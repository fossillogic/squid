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

int fossil_squid_service(bool list,
                         ccstring status,
                         ccstring start,
                         ccstring stop,
                         ccstring restart,
                         ccstring enable,
                         ccstring disable)
{
    int result = 0;

    if (list)
    {
        fossil_io_printf("{cyan,bold}Listing all services...{reset}\n");
        result = fossil_sys_call_execute("systemctl list-units --type=service");
        if (result != 0)
            fossil_io_error("[%s] %s\n", "process.exec", fossil_io_what("process.exec"));
    }
    else if (status && status[0])
    {
        char cmd[256];
        fossil_io_printf("{yellow,bold}Checking status of service: {reset}%s\n", status);
        snprintf(cmd, sizeof(cmd), "systemctl status %s", status);
        result = fossil_sys_call_execute(cmd);
        if (result != 0)
            fossil_io_error("[%s] %s\n", "process.exec", fossil_io_what("process.exec"));
    }
    else if (start && start[0])
    {
        char cmd[256];
        fossil_io_printf("{green,bold}Starting service: {reset}%s\n", start);
        snprintf(cmd, sizeof(cmd), "systemctl start %s", start);
        result = fossil_sys_call_execute(cmd);
        if (result != 0)
            fossil_io_error("[%s] %s\n", "process.exec", fossil_io_what("process.exec"));
    }
    else if (stop && stop[0])
    {
        char cmd[256];
        fossil_io_printf("{red,bold}Stopping service: {reset}%s\n", stop);
        snprintf(cmd, sizeof(cmd), "systemctl stop %s", stop);
        result = fossil_sys_call_execute(cmd);
        if (result != 0)
            fossil_io_error("[%s] %s\n", "process.exec", fossil_io_what("process.exec"));
    }
    else if (restart && restart[0])
    {
        char cmd[256];
        fossil_io_printf("{magenta,bold}Restarting service: {reset}%s\n", restart);
        snprintf(cmd, sizeof(cmd), "systemctl restart %s", restart);
        result = fossil_sys_call_execute(cmd);
        if (result != 0)
            fossil_io_error("[%s] %s\n", "process.exec", fossil_io_what("process.exec"));
    }
    else if (enable && enable[0])
    {
        char cmd[256];
        fossil_io_printf("{blue,bold}Enabling service: {reset}%s\n", enable);
        snprintf(cmd, sizeof(cmd), "systemctl enable %s", enable);
        result = fossil_sys_call_execute(cmd);
        if (result != 0)
            fossil_io_error("[%s] %s\n", "process.exec", fossil_io_what("process.exec"));
    }
    else if (disable && disable[0])
    {
        char cmd[256];
        fossil_io_printf("{bright_red,bold}Disabling service: {reset}%s\n", disable);
        snprintf(cmd, sizeof(cmd), "systemctl disable %s", disable);
        result = fossil_sys_call_execute(cmd);
        if (result != 0)
            fossil_io_error("[%s] %s\n", "process.exec", fossil_io_what("process.exec"));
    }
    else
    {
        fossil_io_error("[%s] %s\n", "user.input", fossil_io_what("user.input"));
        fossil_io_printf("{red,bold}No operation specified. Please provide a valid service command.{reset}\n");
        result = -1;
    }

    return result;
}
