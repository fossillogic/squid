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

int fossil_squid_help(ccstring command, bool show_examples, bool full_manual)
{
    // Show overview if command is NULL or "all"
    if (!command || fossil_io_cstring_equals(command, "all"))
    {
        fossil_io_printf("{black,bold,underline}Fossil Squid - Command Overview:{normal}\n");
        fossil_io_printf("{black,italic}------------------------------------------------------------{normal}\n");

        fossil_io_printf("{blue,bold,underline}Core System Commands:{normal}\n");

        fossil_io_printf("  {cyan,bold}process{normal}     - Display and manage system processes.\n");
        fossil_io_printf("  {cyan,bold}monitor{normal}     - Observe system resource usage over time.\n");
        fossil_io_printf("  {cyan,bold}network{normal}     - Display network configuration and traffic.\n");
        fossil_io_printf("  {cyan,bold}health{normal}      - Check system health and diagnostics.\n");
        fossil_io_printf("  {cyan,bold}service{normal}     - Manage system services.\n");
        fossil_io_printf("  {cyan,bold}system{normal}      - System-level operations (like systemctl).\n");
        fossil_io_printf("  {cyan,bold}inspect{normal}     - Examine objects, files, or runtime state.\n");
        fossil_io_printf("  {cyan,bold}permit{normal}      - Adjust permissions for users, files, or services.\n");
        fossil_io_printf("  {cyan,bold}env{normal}         - Inspect or set environment variables.\n");
        fossil_io_printf("  {cyan,bold}echo{normal}        - Print text or system information.\n");
        fossil_io_printf("  {cyan,bold}this{normal}        - Display a comprehensive system profile.\n");
        fossil_io_printf("  {cyan,bold}help{normal}        - Display help for commands.\n");

        fossil_io_printf("\n{blue,bold,underline}Global Flags & Special Commands:{normal}\n");
        fossil_io_printf("  {cyan,bold}--help{normal}      - Show command help\n");
        fossil_io_printf("  {cyan,bold}--version{normal}   - Display Squid Tool version\n");
        fossil_io_printf("  {cyan,bold}-v, --verbose{normal} - Enable detailed output\n");
        fossil_io_printf("  {cyan,bold}-q, --quiet{normal}   - Suppress standard output\n");
        fossil_io_printf("  {cyan,bold}--dry-run{normal}   - Simulate actions without changes\n");
        fossil_io_printf("  {cyan,bold}--color{normal}     - Colorize output where applicable\n");
        fossil_io_printf("  {cyan,bold}--time{normal}      - Display timestamps in output\n");
        fossil_io_printf("{black,italic}------------------------------------------------------------{normal}\n");
        return 0;
    }

    // Detailed help for specific command
    if (clikely(cnotnull(command)))
    {
        if (fossil_io_cstring_equals(command, "process"))
        {
            fossil_io_printf("{blue,bold,underline}Usage:{normal} {green}process [options]{normal}\n");
            fossil_io_printf("{blue,bold,underline}Description:{normal} Display and manage system processes.\n");
            fossil_io_printf("{blue,bold,underline}Options:{normal}\n");
            fossil_io_printf("  {cyan,bold}-a, --all{normal}                   Show all processes\n");
            fossil_io_printf("  {cyan,bold}-p, --pid <id>{normal}              Select specific process\n");
            fossil_io_printf("  {cyan,bold}--name <pattern>{normal}            Filter by process name\n");
            fossil_io_printf("  {cyan,bold}--exists <pid>{normal}              Check if process exists\n");
            fossil_io_printf("  {cyan,bold}--info <pid>{normal}                Show detailed info\n");
            fossil_io_printf("  {cyan,bold}--env <pid>{normal}                 Show environment variables\n");
            fossil_io_printf("  {cyan,bold}--exe <pid>{normal}                 Show executable path\n");
            fossil_io_printf("  {cyan,bold}--ppid <pid>{normal}                Show parent process ID\n");
            fossil_io_printf("  {cyan,bold}--priority <pid>{normal}            Show process priority\n");
            fossil_io_printf("  {cyan,bold}--set-priority <pid> <value>{normal} Change process priority\n");
            fossil_io_printf("  {cyan,bold}--suspend <pid>{normal}             Pause process\n");
            fossil_io_printf("  {cyan,bold}--resume <pid>{normal}              Resume process\n");
            fossil_io_printf("  {cyan,bold}--terminate <pid>{normal}           Terminate process gracefully\n");
            fossil_io_printf("  {cyan,bold}--kill <pid>{normal}                Force kill process\n");
            fossil_io_printf("  {cyan,bold}--signal <pid> <sig>{normal}        Send signal\n");
            fossil_io_printf("  {cyan,bold}--wait <pid> [--timeout <ms>]{normal} Wait for process exit\n");
            fossil_io_printf("  {cyan,bold}--spawn <exe> [args...]{normal}     Start new process\n");
        }
        else if (fossil_io_cstring_equals(command, "monitor"))
        {
            fossil_io_printf("{blue,bold,underline}Usage:{normal} {green}monitor [options]{normal}\n");
            fossil_io_printf("{blue,bold,underline}Description:{normal} Observe system resource usage over time.\n");
            fossil_io_printf("{blue,bold,underline}Options:{normal}\n");
            fossil_io_printf("  {cyan,bold}-c, --cpu{normal}           Monitor CPU usage\n");
            fossil_io_printf("  {cyan,bold}-m, --mem{normal}           Monitor memory usage\n");
            fossil_io_printf("  {cyan,bold}-d, --disk{normal}          Monitor disk usage\n");
            fossil_io_printf("  {cyan,bold}-n, --net{normal}           Monitor network usage\n");
            fossil_io_printf("  {cyan,bold}-t, --interval <s>{normal}  Refresh interval (seconds)\n");
            fossil_io_printf("  {cyan,bold}--top <n>{normal}           Show top N usage\n");
            fossil_io_printf("  {cyan,bold}--graph{normal}             ASCII/graphical output\n");
        }
        else if (fossil_io_cstring_equals(command, "network"))
        {
            fossil_io_printf("{blue,bold,underline}Usage:{normal} {green}network [options]{normal}\n");
            fossil_io_printf("{blue,bold,underline}Description:{normal} Display network configuration and traffic.\n");
            fossil_io_printf("{blue,bold,underline}Options:{normal}\n");
            fossil_io_printf("  {cyan,bold}--interfaces{normal}         Show network interfaces\n");
            fossil_io_printf("  {cyan,bold}--connections{normal}        Show active connections\n");
            fossil_io_printf("  {cyan,bold}--routes{normal}             Show routing table\n");
            fossil_io_printf("  {cyan,bold}--stats{normal}              Show network statistics\n");
            fossil_io_printf("  {cyan,bold}--monitor{normal}            Real-time traffic monitoring\n");
        }
        else if (fossil_io_cstring_equals(command, "health"))
        {
            fossil_io_printf("{blue,bold,underline}Usage:{normal} {green}health [options]{normal}\n");
            fossil_io_printf("{blue,bold,underline}Description:{normal} Check system health and diagnostics.\n");
            fossil_io_printf("{blue,bold,underline}Options:{normal}\n");
            fossil_io_printf("  {cyan,bold}--cpu{normal}                CPU load\n");
            fossil_io_printf("  {cyan,bold}--mem{normal}                Memory usage\n");
            fossil_io_printf("  {cyan,bold}--disk{normal}               Disk health\n");
            fossil_io_printf("  {cyan,bold}--network{normal}            Network health\n");
            fossil_io_printf("  {cyan,bold}--report{normal}             Generate summary report\n");
        }
        else if (fossil_io_cstring_equals(command, "service"))
        {
            fossil_io_printf("{blue,bold,underline}Usage:{normal} {green}service [options]{normal}\n");
            fossil_io_printf("{blue,bold,underline}Description:{normal} Manage system services.\n");
            fossil_io_printf("{blue,bold,underline}Options:{normal}\n");
            fossil_io_printf("  {cyan,bold}--list{normal}               Show services\n");
            fossil_io_printf("  {cyan,bold}--status <name>{normal}      Service status\n");
            fossil_io_printf("  {cyan,bold}--start <name>{normal}       Start service\n");
            fossil_io_printf("  {cyan,bold}--stop <name>{normal}        Stop service\n");
            fossil_io_printf("  {cyan,bold}--restart <name>{normal}     Restart service\n");
            fossil_io_printf("  {cyan,bold}--enable <name>{normal}      Enable service\n");
            fossil_io_printf("  {cyan,bold}--disable <name>{normal}     Disable service\n");
        }
        else if (fossil_io_cstring_equals(command, "system"))
        {
            fossil_io_printf("{blue,bold,underline}Usage:{normal} {green}system [options]{normal}\n");
            fossil_io_printf("{blue,bold,underline}Description:{normal} System-level operations (like systemctl).\n");
            fossil_io_printf("{blue,bold,underline}Options:{normal}\n");
            fossil_io_printf("  {cyan,bold}--info{normal}               System info\n");
            fossil_io_printf("  {cyan,bold}--uptime{normal}             System uptime\n");
            fossil_io_printf("  {cyan,bold}--shutdown{normal}           Shutdown system\n");
            fossil_io_printf("  {cyan,bold}--reboot{normal}             Reboot system\n");
            fossil_io_printf("  {cyan,bold}--update{normal}             Update system\n");
            fossil_io_printf("  {cyan,bold}--config <file>{normal}      Use config file\n");
        }
        else if (fossil_io_cstring_equals(command, "inspect"))
        {
            fossil_io_printf("{blue,bold,underline}Usage:{normal} {green}inspect [options]{normal}\n");
            fossil_io_printf("{blue,bold,underline}Description:{normal} Examine objects, files, or runtime state.\n");
            fossil_io_printf("{blue,bold,underline}Options:{normal}\n");
            fossil_io_printf("  {cyan,bold}--file <path>{normal}        Inspect file\n");
            fossil_io_printf("  {cyan,bold}--dir <path>{normal}         Inspect directory\n");
            fossil_io_printf("  {cyan,bold}--process <pid>{normal}      Inspect process\n");
            fossil_io_printf("  {cyan,bold}--service <name>{normal}     Inspect service\n");
            fossil_io_printf("  {cyan,bold}--json{normal}               Structured output\n");
        }
        else if (fossil_io_cstring_equals(command, "permit"))
        {
            fossil_io_printf("{blue,bold,underline}Usage:{normal} {green}permit [options]{normal}\n");
            fossil_io_printf("{blue,bold,underline}Description:{normal} Adjust permissions for users, files, or services.\n");
            fossil_io_printf("{blue,bold,underline}Options:{normal}\n");
            fossil_io_printf("  {cyan,bold}--user <name>{normal}        User permissions\n");
            fossil_io_printf("  {cyan,bold}--file <path>{normal}        File permissions\n");
            fossil_io_printf("  {cyan,bold}--service <name>{normal}     Service permissions\n");
            fossil_io_printf("  {cyan,bold}--grant <perm>{normal}       Grant permission\n");
            fossil_io_printf("  {cyan,bold}--revoke <perm>{normal}      Revoke permission\n");
        }
        else if (fossil_io_cstring_equals(command, "env"))
        {
            fossil_io_printf("{blue,bold,underline}Usage:{normal} {green}env [options]{normal}\n");
            fossil_io_printf("{blue,bold,underline}Description:{normal} Inspect or set environment variables.\n");
            fossil_io_printf("{blue,bold,underline}Options:{normal}\n");
            fossil_io_printf("  {cyan,bold}--list{normal}               List variables\n");
            fossil_io_printf("  {cyan,bold}--get <key>{normal}          Get variable\n");
            fossil_io_printf("  {cyan,bold}--set <key>=<value>{normal}  Set variable\n");
            fossil_io_printf("  {cyan,bold}--unset <key>{normal}        Unset variable\n");
            fossil_io_printf("  {cyan,bold}--export <file>{normal}      Export to file\n");
        }
        else if (fossil_io_cstring_equals(command, "echo"))
        {
            fossil_io_printf("{blue,bold,underline}Usage:{normal} {green}echo [options]{normal}\n");
            fossil_io_printf("{blue,bold,underline}Description:{normal} Print text or system information.\n");
            fossil_io_printf("{blue,bold,underline}Options:{normal}\n");
            fossil_io_printf("  {cyan,bold}--text <msg>{normal}         Print message\n");
            fossil_io_printf("  {cyan,bold}--env <key>{normal}          Print environment variable\n");
            fossil_io_printf("  {cyan,bold}--json{normal}               JSON output\n");
            fossil_io_printf("  {cyan,bold}--color{normal}              Color output\n");
        }
        else if (fossil_io_cstring_equals(command, "this"))
        {
            fossil_io_printf("{blue,bold,underline}Usage:{normal} {green}this [options]{normal}\n");
            fossil_io_printf("{blue,bold,underline}Description:{normal} Display a comprehensive system profile, with lookup features for each major host property.\n");
            fossil_io_printf("{blue,bold,underline}Options:{normal}\n");
            fossil_io_printf("  {cyan,bold}--system{normal}             OS, kernel, hostname, user, domain, platform\n");
            fossil_io_printf("  {cyan,bold}--arch{normal}               Architecture, CPU, cores, threads, frequency\n");
            fossil_io_printf("  {cyan,bold}--memory{normal}             Total, free, used, available, swap\n");
            fossil_io_printf("  {cyan,bold}--endianness{normal}         Little/big endian\n");
            fossil_io_printf("  {cyan,bold}--power{normal}              AC/battery, charging, battery %%/time left\n");
            fossil_io_printf("  {cyan,bold}--cpu{normal}                Model, vendor, cores, threads, frequency, features\n");
            fossil_io_printf("  {cyan,bold}--gpu{normal}                Name, vendor, driver, memory\n");
            fossil_io_printf("  {cyan,bold}--storage{normal}            Device, mount, total/free/used, filesystem\n");
            fossil_io_printf("  {cyan,bold}--env{normal}                Shell, home, lang, path, term, user\n");
            fossil_io_printf("  {cyan,bold}--virtualization{normal}     VM/container detection, hypervisor, container type\n");
            fossil_io_printf("  {cyan,bold}--uptime{normal}             Uptime, boot time\n");
            fossil_io_printf("  {cyan,bold}--network{normal}            Hostname, IP, MAC, interface, status\n");
            fossil_io_printf("  {cyan,bold}--process{normal}            PID, PPID, exe, cwd, name, privileges\n");
            fossil_io_printf("  {cyan,bold}--limits{normal}             Max open files, max processes, page size\n");
            fossil_io_printf("  {cyan,bold}--time{normal}               Timezone, UTC offset, locale\n");
            fossil_io_printf("  {cyan,bold}--hardware{normal}           Manufacturer, product, serial, BIOS\n");
            fossil_io_printf("  {cyan,bold}--display{normal}            Count, resolution, refresh rate\n");
            fossil_io_printf("  {cyan,bold}--all{normal}                Show everything\n");
            fossil_io_printf("  {cyan,bold}--json{normal}               Structured output\n");
        }
        else if (fossil_io_cstring_equals(command, "help"))
        {
            fossil_io_printf("{blue,bold,underline}Usage:{normal} {green}help [command]{normal}\n");
            fossil_io_printf("{blue,bold,underline}Description:{normal} Display help for commands.\n");
            fossil_io_printf("{blue,bold,underline}Options:{normal}\n");
            fossil_io_printf("  {cyan,bold}--examples{normal}           Usage examples\n");
            fossil_io_printf("  {cyan,bold}--man{normal}                Full manual\n");
            fossil_io_printf("  {cyan,bold}--command <cmd>{normal}      Help for specific command\n");
        }
        else
        {
            fossil_io_fprintf(FOSSIL_STDERR, "{red,bold,blink}Unknown command: %s{normal}\n", command);
            return 1;
        }

        if (clikely(show_examples))
        {
            fossil_io_printf("\n{blue,bold,underline}Example usage:{normal}\n");
            if (fossil_io_cstring_equals(command, "process"))
                fossil_io_printf("  {cyan,bold}squid process -a --sort mem --kill 1234{normal}\n");
            else if (fossil_io_cstring_equals(command, "monitor"))
                fossil_io_printf("  {cyan,bold}squid monitor -c -m -t 5 --graph{normal}\n");
            else if (fossil_io_cstring_equals(command, "network"))
                fossil_io_printf("  {cyan,bold}squid network --interfaces --monitor{normal}\n");
            else if (fossil_io_cstring_equals(command, "health"))
                fossil_io_printf("  {cyan,bold}squid health --cpu --mem --report{normal}\n");
            else if (fossil_io_cstring_equals(command, "service"))
                fossil_io_printf("  {cyan,bold}squid service --restart nginx{normal}\n");
            else if (fossil_io_cstring_equals(command, "system"))
                fossil_io_printf("  {cyan,bold}squid system --info --uptime{normal}\n");
            else if (fossil_io_cstring_equals(command, "inspect"))
                fossil_io_printf("  {cyan,bold}squid inspect --file /etc/passwd --json{normal}\n");
            else if (fossil_io_cstring_equals(command, "permit"))
                fossil_io_printf("  {cyan,bold}squid permit --user alice --grant rw{normal}\n");
            else if (fossil_io_cstring_equals(command, "env"))
                fossil_io_printf("  {cyan,bold}squid env --set PATH=/usr/bin --export env.txt{normal}\n");
            else if (fossil_io_cstring_equals(command, "echo"))
                fossil_io_printf("  {cyan,bold}squid echo --env HOME --color{normal}\n");
            else if (fossil_io_cstring_equals(command, "this"))
                fossil_io_printf("  {cyan,bold}squid this --system --cpu --memory --json{normal}\n");
            else if (fossil_io_cstring_equals(command, "help"))
                fossil_io_printf("  {cyan,bold}squid help --command process{normal}\n");
        }

        if (cunlikely(full_manual))
        {
            fossil_io_printf("\n{blue,bold,underline}Manual Page for '{cyan}%s{normal}{blue,bold,underline}':{normal}\n", command);
            fossil_io_printf("{cyan,italic}------------------------------------------------------------{normal}\n");
            fossil_io_printf("{blue,bold}NAME{normal}\n  {cyan}%s{normal} - ", command);
            fossil_io_printf("{cyan}See command overview and options above.{normal}\n");
            fossil_io_printf("{blue,bold}SYNOPSIS{normal}\n  {cyan}squid %s [options] ...{normal}\n", command);
            fossil_io_printf("{blue,bold}DESCRIPTION{normal}\n  {cyan}See command overview and options above.{normal}\n");
            fossil_io_printf("{blue,bold}OPTIONS{normal}\n  {cyan}See command overview and options above.{normal}\n");
            fossil_io_printf("{blue,bold}EXAMPLE{normal}\n  {cyan}See example usage above.{normal}\n");
            fossil_io_printf("\n{blue,bold}SEE ALSO{normal}\n  {cyan}For more information, visit the official documentation or use 'squid help %s --examples'.{normal}\n", command);
            fossil_io_printf("{cyan,italic}------------------------------------------------------------{normal}\n");
        }
    }
    return 0;
}
