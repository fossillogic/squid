/**
 * -----------------------------------------------------------------------------
 * Project: Fossil Logic
 *
 * This file is part of the Fossil Logic project, which aims to develop
 * high-performance, cross-platform applications and libraries. The code
 * contained herein is licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License. You may obtain
 * a copy of the License at:
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 * Author: Michael Gene Brockus (Dreamer)
 * Date: 04/05/2014
 *
 * Copyright (C) 2014-2025 Fossil Logic. All rights reserved.
 * -----------------------------------------------------------------------------
 */
#include "fossil/code/commands.h"

/* simple port range parser: "start-end" */
static void squid_parse_ports(const char *range, int *start, int *end)
{
    if (!range || sscanf(range, "%d-%d", start, end) != 2)
    {
        *start = 1;
        *end = 1024;
    }

    if (*start < 1) *start = 1;
    if (*end > 65535) *end = 65535;
}

/* basic service guess */
static const char *squid_service_name(int port)
{
    switch (port)
    {
        case 80: return "http";
        case 443: return "https";
        case 22: return "ssh";
        case 21: return "ftp";
        case 25: return "smtp";
        case 53: return "dns";
        case 110: return "pop3";
        case 143: return "imap";
        default: return "unknown";
    }
}

int fossil_squid_scan(
    ccstring host,
    ccstring ports,
    int top_n,
    int timeout_ms,
    bool tcp,
    bool udp,
    bool service,
    bool banner,
    bool open_only,
    bool json)
{
    if (!host)
        return -1;

    if (!tcp && !udp)
        tcp = true; /* default */

    if (timeout_ms <= 0)
        timeout_ms = 1000;

    fossil_net_address_t base_addr;
    memset(&base_addr, 0, sizeof(base_addr));

    if (fossil_net_socket_resolve(host, &base_addr) != 0)
    {
        fprintf(stderr, "scan: failed to resolve host %s\n", host);
        return -1;
    }

    int start = 1, end = 1024;

    if (top_n > 0)
    {
        start = 1;
        end = top_n;
    }
    else
    {
        squid_parse_ports(ports, &start, &end);
    }

    if (!json)
        printf("SCAN %s (%s)\n", host, base_addr.ip);

    int open_count = 0;

    for (int port = start; port <= end; ++port)
    {
        fossil_net_socket_t sock;
        memset(&sock, 0, sizeof(sock));

        fossil_net_address_t addr = base_addr;
        addr.port = (uint16_t)port;

        int rc = -1;

        if (tcp)
        {
            if (fossil_net_socket_create(&sock, "tcp", base_addr.family) != 0)
                continue;

            fossil_net_socket_set_blocking(&sock, true);

            rc = fossil_net_socket_connect(&sock, &addr);
        }
        else if (udp)
        {
            if (fossil_net_socket_create(&sock, "udp", base_addr.family) != 0)
                continue;

            /* UDP "scan": attempt send */
            uint32_t sent = 0;
            char dummy = 0;

            rc = fossil_net_socket_send(&sock, &dummy, 1, &sent);
        }

        if (rc == 0)
        {
            open_count++;

            if (!open_only && !json)
                printf("open %d\n", port);

            if (service && !json)
                printf("  service: %s\n", squid_service_name(port));

            if (banner && tcp)
            {
                char buf[256];
                uint32_t recvd = 0;

                if (fossil_net_socket_receive(&sock, buf, sizeof(buf) - 1, &recvd) == 0 && recvd > 0)
                {
                    buf[recvd] = '\0';
                    if (!json)
                        printf("  banner: %s\n", buf);
                }
            }
        }
        else
        {
            if (!open_only && !json)
                printf("closed %d\n", port);
        }

        fossil_net_socket_close(&sock);
    }

    if (json)
    {
        printf("{\"host\":\"%s\",\"open_ports\":%d}\n",
               host, open_count);
    }
    else
    {
        printf("\nscan complete: %d open ports\n", open_count);
    }

    return 0;
}
