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
 * Display information about the current host system.
 * @param os Include operating system information
 * @param arch Include architecture information
 * @param hostname Include hostname information
 * @param uptime Include system uptime
 * @param load Include system load
 * @param all Include all available information
 * @return 0 on success, non-zero on error
 */
int fossil_squid_this(bool os,
                      bool arch,
                      bool hostname,
                      bool uptime,
                      bool load,
                      bool all)
{
    //
    fossil_sys_hostinfo_system_t sys_info = {0};
    fossil_sys_hostinfo_architecture_t arch_info = {0};
    fossil_sys_hostinfo_uptime_t uptime_info = {0};
    fossil_sys_hostinfo_memory_t mem_info = {0};

    int result = 0;

    if (all)
    {
        os = arch = hostname = uptime = load = true;
    }

    if (os)
    {
        if ((result = fossil_sys_hostinfo_get_system(&sys_info)) == 0)
        {
            fossil_io_printf("OS: {bold}%s %s{reset}\n", sys_info.os_name, sys_info.os_version);
            fossil_io_printf("Kernel: {bold}%s{reset}\n", sys_info.kernel_version);
            fossil_io_printf("Hostname: {bold}%s{reset}\n", sys_info.hostname);
        }
    }

    if (arch)
    {
        if ((result = fossil_sys_hostinfo_get_architecture(&arch_info)) == 0)
        {
            fossil_io_printf("Architecture: {bold}%s{reset}\n", arch_info.architecture);
            fossil_io_printf("CPU: {bold}%s{reset} (%s cores, %s threads)\n",
                   arch_info.cpu, arch_info.cpu_cores, arch_info.cpu_threads);
        }
    }

    if (hostname && !os)
    {
        if ((result = fossil_sys_hostinfo_get_system(&sys_info)) == 0)
        {
            fossil_io_printf("Hostname: {bold}%s{reset}\n", sys_info.hostname);
        }
    }

    if (uptime)
    {
        if ((result = fossil_sys_hostinfo_get_uptime(&uptime_info)) == 0)
        {
            fossil_io_printf("Uptime: {bold}%llu seconds{reset}\n", (unsigned long long)uptime_info.uptime_seconds);
        }
    }

    if (load)
    {
        if ((result = fossil_sys_hostinfo_get_memory(&mem_info)) == 0)
        {
            fossil_io_printf("Memory: {bold}%llu{reset} / {bold}%llu{reset} bytes\n",
                   (unsigned long long)mem_info.used_memory,
                   (unsigned long long)mem_info.total_memory);
        }
    }

    return result;
}
