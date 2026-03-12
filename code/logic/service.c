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

/**
 * Manage system services.
 */
int fossil_squid_service(ccstring action,
                         ccstring service_name,
                         bool enable,
                         bool disable,
                         bool list,
                         bool watch)
{
    char cmd[512];

    /* list services */
    if (list) {
#ifdef _WIN32
        snprintf(cmd, sizeof(cmd), "Get-Service | Format-Table");
        return fossil_sys_call_execute(cmd);
#else
        snprintf(cmd, sizeof(cmd), "systemctl list-units --type=service --all");
        return fossil_sys_call_execute(cmd);
#endif
    }

    /* enable service */
    if (enable) {
        if (!service_name) {
            fossil_io_printf("{red}Error: service name required for enable{reset}\n");
            return 1;
        }

#ifdef _WIN32
        snprintf(cmd, sizeof(cmd), "sc config %s start= auto", service_name);
#else
        snprintf(cmd, sizeof(cmd), "systemctl enable %s", service_name);
#endif
        return fossil_sys_call_execute(cmd);
    }

    /* disable service */
    if (disable) {
        if (!service_name) {
            fossil_io_printf("{red}Error: service name required for disable{reset}\n");
            return 1;
        }

#ifdef _WIN32
        snprintf(cmd, sizeof(cmd), "sc config %s start= disabled", service_name);
#else
        snprintf(cmd, sizeof(cmd), "systemctl disable %s", service_name);
#endif
        return fossil_sys_call_execute(cmd);
    }

    /* standard actions */
    if (action && service_name) {
        if (strcmp(action, "start") == 0 ||
            strcmp(action, "stop") == 0 ||
            strcmp(action, "restart") == 0 ||
            strcmp(action, "reload") == 0 ||
            strcmp(action, "status") == 0)
        {
#ifdef _WIN32
            if (strcmp(action, "reload") == 0) {
                fossil_io_printf("{red}Error: reload not supported on Windows{reset}\n");
                return 2;
            }
            snprintf(cmd, sizeof(cmd), "sc %s %s", action, service_name);
#else
            snprintf(cmd, sizeof(cmd), "systemctl %s %s", action, service_name);
#endif
            int r = fossil_sys_call_execute(cmd);

            if (watch) {
                while (1) {
                    fossil_sys_call_sleep(2000);
#ifdef _WIN32
                    snprintf(cmd, sizeof(cmd), "sc query %s", service_name);
#else
                    snprintf(cmd, sizeof(cmd), "systemctl status %s --no-pager", service_name);
#endif
                    fossil_sys_call_execute(cmd);
                }
            }

            return r;
        }

        fossil_io_printf("{red}Error: Unknown action '%s'{reset}\n", action);
        return 2;
    }

    return 1;
}
