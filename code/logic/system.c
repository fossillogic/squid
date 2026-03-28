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
int fossil_squid_system(bool info,
                        bool uptime,
                        bool shutdown,
                        bool reboot,
                        bool update,
                        ccstring config_file)
{
    if (info)
    {
        char buffer[256] = {0};
        if (fossil_sys_call_execute_capture("uname -a", buffer, sizeof(buffer)) == 0)
        {
            fossil_io_printf("{cyan,bold}System Info:{reset} %s\n", buffer);
        }
        else
        {
            fossil_io_printf("{red,bold}Failed to get system info.{reset}\n");
        }
    }

    if (uptime)
    {
        char buffer[256] = {0};
        if (fossil_sys_call_execute_capture("uptime", buffer, sizeof(buffer)) == 0)
        {
            fossil_io_printf("{green,bold}Uptime:{reset} %s\n", buffer);
        }
        else
        {
            fossil_io_printf("{red,bold}Failed to get uptime.{reset}\n");
        }
    }

    if (shutdown)
    {
        fossil_io_printf("{yellow,bold}System will shutdown now.{reset}\n");
        fossil_sys_call_execute("shutdown -h now");
        return 0;
    }

    if (reboot)
    {
        fossil_io_printf("{yellow,bold}System will reboot now.{reset}\n");
        fossil_sys_call_execute("reboot");
        return 0;
    }

    if (update)
    {
        fossil_io_printf("{blue,bold}System update requested.{reset}\n");
        fossil_sys_call_execute("sudo apt update && sudo apt upgrade -y");
    }

    if (config_file && fossil_sys_call_file_exists(config_file))
    {
        fossil_io_printf("{magenta}Config file '{bold}%s{reset}{magenta}' exists.{reset}\n", config_file);
    }
    else if (config_file)
    {
        fossil_io_printf("{red}Config file '{bold}%s{reset}{red}' does not exist.{reset}\n", config_file);
    }

    return 0;
}
