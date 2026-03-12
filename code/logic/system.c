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
 * System-level control commands.
 */
int fossil_squid_system(bool reboot,
                        bool shutdown,
                        bool suspend,
                        bool hibernate,
                        bool targets,
                        ccstring default_target)
{
    /* reboot system */
    if (reboot) {
        fossil_io_printf("{cyan}Rebooting system...{reset}\n");
        #ifdef _WIN32
            return fossil_sys_call_execute("shutdown /r /t 0");
        #else
            return fossil_sys_call_execute("systemctl reboot");
        #endif
    }

    /* shutdown system */
    if (shutdown) {
        fossil_io_printf("{cyan}Shutting down system...{reset}\n");
        #ifdef _WIN32
            return fossil_sys_call_execute("shutdown /s /t 0");
        #else
            return fossil_sys_call_execute("systemctl poweroff");
        #endif
    }

    /* suspend system */
    if (suspend) {
        fossil_io_printf("{cyan}Suspending system...{reset}\n");
        #ifdef _WIN32
            return fossil_sys_call_execute("rundll32.exe powrprof.dll,SetSuspendState 0,1,0");
        #else
            return fossil_sys_call_execute("systemctl suspend");
        #endif
    }

    /* hibernate system */
    if (hibernate) {
        fossil_io_printf("{cyan}Hibernating system...{reset}\n");
        #ifdef _WIN32
            return fossil_sys_call_execute("rundll32.exe powrprof.dll,SetSuspendState 1,1,0");
        #else
            return fossil_sys_call_execute("systemctl hibernate");
        #endif
    }

    /* list available targets */
    if (targets) {
        #ifdef _WIN32
            fossil_io_printf("{cyan}Target listing not supported on Windows{reset}\n");
            return 0;
        #else
            return fossil_sys_call_execute("systemctl list-unit-files --type=target");
        #endif
    }

    /* set default target */
    if (default_target && strlen(default_target) > 0) {
        #ifdef _WIN32
            fossil_io_printf("{cyan}Default target setting not supported on Windows{reset}\n");
            return 0;
        #else
            char cmd[256];
            snprintf(cmd, sizeof(cmd),
                     "systemctl set-default %s",
                     default_target);

            fossil_io_printf("{cyan}Setting default target to '%s'{reset}\n", default_target);
            return fossil_sys_call_execute(cmd);
        #endif
    }

    return 1;
}
