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

/*=============================================================================
SQUID PING COMMAND (TCP-BASED FALLBACK)
=============================================================================*/

#include <stdio.h>
#include <string.h>
#include <time.h>

/* simple timestamp helper (ms) */
static uint64_t squid_time_ms(void)
{
    struct timespec ts;
#if defined(_WIN32)
    timespec_get(&ts, TIME_UTC);
#else
    clock_gettime(CLOCK_REALTIME, &ts);
#endif
    return (uint64_t)ts.tv_sec * 1000ULL + (ts.tv_nsec / 1000000ULL);
}

int fossil_squid_ping(
    ccstring host,
    int count,
    int interval_ms,
    int timeout_ms,
    bool ipv4,
    bool ipv6,
    int tcp_port,
    bool stats_only,
    bool flood,
    bool json)
{
    if (!host)
        return -1;

    if (count <= 0)
        count = 4;

    if (interval_ms <= 0)
        interval_ms = 1000;

    if (timeout_ms <= 0)
        timeout_ms = 3000;

    if (tcp_port <= 0)
        tcp_port = 80;

    fossil_net_address_t addr;
    memset(&addr, 0, sizeof(addr));

    /* resolve host */
    if (fossil_net_socket_resolve(host, &addr) != 0)
    {
        fprintf(stderr, "ping: failed to resolve host %s\n", host);
        return -1;
    }

    addr.port = (uint16_t)tcp_port;

    int sent = 0;
    int received = 0;
    uint64_t total_time = 0;

    if (!stats_only)
        printf("PING %s (%s:%d)\n", host, addr.ip, addr.port);

    for (int i = 0; i < count; ++i)
    {
        fossil_net_socket_t sock;
        memset(&sock, 0, sizeof(sock));

        const char *family = ipv6 ? "ipv6" : "ipv4";

        if (fossil_net_socket_create(&sock, "tcp", family) != 0)
        {
            fprintf(stderr, "ping: socket create failed\n");
            continue;
        }

        fossil_net_socket_set_blocking(&sock, true);

        uint64_t start = squid_time_ms();

        int rc = fossil_net_socket_connect(&sock, &addr);

        uint64_t end = squid_time_ms();
        uint64_t elapsed = end - start;

        sent++;

        if (rc == 0)
        {
            received++;
            total_time += elapsed;

            if (!stats_only)
            {
                printf("reply from %s: time=%llums\n",
                       addr.ip,
                       (unsigned long long)elapsed);
            }
        }
        else
        {
            if (!stats_only)
            {
                int err = fossil_net_socket_error_last();
                printf("timeout/error from %s (%s)\n",
                       addr.ip,
                       fossil_net_socket_error_string(err));
            }
        }

        fossil_net_socket_close(&sock);

        if (!flood)
            fossil_net_socket_sleep(interval_ms);
    }

    /* summary */
    int loss = sent > 0 ? ((sent - received) * 100 / sent) : 0;
    uint64_t avg = received > 0 ? total_time / received : 0;

    if (json)
    {
        printf("{\"host\":\"%s\",\"sent\":%d,\"received\":%d,\"loss\":%d,\"avg_ms\":%llu}\n",
               host,
               sent,
               received,
               loss,
               (unsigned long long)avg);
    }
    else
    {
        printf("\n--- %s ping statistics ---\n", host);
        printf("%d packets transmitted, %d received, %d%% packet loss\n",
               sent, received, loss);
        if (received > 0)
        {
            printf("avg time = %llums\n",
                   (unsigned long long)avg);
        }
    }

    return (received > 0) ? 0 : -1;
}
