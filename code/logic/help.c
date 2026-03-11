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
        fossil_io_printf("  {cyan,bold}process{normal}     - Display and manage system processes\n");
        fossil_io_printf("  {cyan,bold}monitor{normal}     - Real-time monitoring of system resources\n");
        fossil_io_printf("  {cyan,bold}health{normal}      - System health diagnostics and checks\n");
        fossil_io_printf("  {cyan,bold}doctor{normal}      - Perform system health diagnostics (alias)\n");
        fossil_io_printf("  {cyan,bold}inspect{normal}     - Deep inspection of system resources\n");
        fossil_io_printf("  {cyan,bold}introspect{normal}  - Low-level kernel and hardware introspection\n");
        fossil_io_printf("  {cyan,bold}this{normal}        - Display current host system information\n");
        fossil_io_printf("  {cyan,bold}network{normal}     - Display and analyze network information\n");
        fossil_io_printf("  {cyan,bold}service{normal}     - Manage system services\n");
        fossil_io_printf("  {cyan,bold}system{normal}      - System-level control tasks\n");
        fossil_io_printf("  {cyan,bold}permit{normal}      - Inspect and modify system permissions\n");
        fossil_io_printf("  {cyan,bold}notebook{normal}    - View and query system journal logs\n");
        fossil_io_printf("  {cyan,bold}view{normal}        - Modern pager for logs and files\n");
        fossil_io_printf("  {cyan,bold}echo{normal}        - Output formatted or encoded text\n");
        fossil_io_printf("  {cyan,bold}env{normal}         - Display and manage environment variables\n");
        fossil_io_printf("  {cyan,bold}calc{normal}        - Built-in calculator\n");
        fossil_io_printf("  {cyan,bold}help{normal}        - Display help for commands\n");
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
            fossil_io_printf("{blue,bold,underline}Options:{normal}\n");
            fossil_io_printf("  {cyan,bold}-a, --all{normal}           Show all processes\n");
            fossil_io_printf("  {cyan,bold}-u, --user <name>{normal}   Filter by user\n");
            fossil_io_printf("  {cyan,bold}-p, --pid <id>{normal}      Specific process\n");
            fossil_io_printf("  {cyan,bold}--name <pattern>{normal}    Filter by name\n");
            fossil_io_printf("  {cyan,bold}--sort <key>{normal}        Sort by: cpu/mem/pid/time\n");
            fossil_io_printf("  {cyan,bold}--tree{normal}              Process hierarchy\n");
            fossil_io_printf("  {cyan,bold}--kill <signal>{normal}     Send signal to process\n");
            fossil_io_printf("  {cyan,bold}--watch{normal}             Live refresh\n");
            fossil_io_printf("  {cyan,bold}--limit <n>{normal}         Limit results\n");
        }
        else if (fossil_io_cstring_equals(command, "monitor"))
        {
            fossil_io_printf("{blue,bold,underline}Usage:{normal} {green}monitor [options]{normal}\n");
            fossil_io_printf("{blue,bold,underline}Options:{normal}\n");
            fossil_io_printf("  {cyan,bold}--cpu{normal}                Monitor CPU usage\n");
            fossil_io_printf("  {cyan,bold}--memory{normal}             Monitor memory usage\n");
            fossil_io_printf("  {cyan,bold}--disk{normal}               Monitor disk usage\n");
            fossil_io_printf("  {cyan,bold}--network{normal}            Monitor network activity\n");
            fossil_io_printf("  {cyan,bold}--process{normal}            Monitor processes\n");
            fossil_io_printf("  {cyan,bold}--top <n>{normal}            Show top n consumers\n");
            fossil_io_printf("  {cyan,bold}-t, --interval <n>{normal}   Refresh interval (seconds)\n");
            fossil_io_printf("  {cyan,bold}--watch{normal}              Continuous monitoring\n");
        }
        else if (fossil_io_cstring_equals(command, "health") || fossil_io_cstring_equals(command, "doctor"))
        {
            fossil_io_printf("{blue,bold,underline}Usage:{normal} {green}health|doctor [options]{normal}\n");
            fossil_io_printf("{blue,bold,underline}Options:{normal}\n");
            fossil_io_printf("  {cyan,bold}--quick{normal}              Basic health check\n");
            fossil_io_printf("  {cyan,bold}--full{normal}               Complete diagnostics\n");
            fossil_io_printf("  {cyan,bold}--cpu{normal}                Check CPU health\n");
            fossil_io_printf("  {cyan,bold}--memory{normal}             Check memory health\n");
            fossil_io_printf("  {cyan,bold}--disk{normal}               Check disk health\n");
            fossil_io_printf("  {cyan,bold}--network{normal}            Check network health\n");
            fossil_io_printf("  {cyan,bold}--report <file>{normal}      Export report to file\n");
            fossil_io_printf("  {cyan,bold}--fix{normal}                Attempt automatic repair\n");
            fossil_io_printf("  {cyan,bold}--json{normal}               Structured report output\n");
        }
        else if (fossil_io_cstring_equals(command, "inspect"))
        {
            fossil_io_printf("{blue,bold,underline}Usage:{normal} {green}inspect [options]{normal}\n");
            fossil_io_printf("{blue,bold,underline}Options:{normal}\n");
            fossil_io_printf("  {cyan,bold}--process <pid>{normal}      Inspect specific process\n");
            fossil_io_printf("  {cyan,bold}--memory{normal}             Memory layout information\n");
            fossil_io_printf("  {cyan,bold}--threads{normal}            Thread usage details\n");
            fossil_io_printf("  {cyan,bold}--fds{normal}                File descriptors\n");
            fossil_io_printf("  {cyan,bold}--network{normal}            Network sockets\n");
            fossil_io_printf("  {cyan,bold}--limits{normal}             Resource limits\n");
            fossil_io_printf("  {cyan,bold}--json{normal}               Structured output\n");
        }
        else if (fossil_io_cstring_equals(command, "introspect"))
        {
            fossil_io_printf("{blue,bold,underline}Usage:{normal} {green}introspect [options]{normal}\n");
            fossil_io_printf("{blue,bold,underline}Options:{normal}\n");
            fossil_io_printf("  {cyan,bold}--kernel{normal}             Kernel information\n");
            fossil_io_printf("  {cyan,bold}--modules{normal}            Loaded kernel modules\n");
            fossil_io_printf("  {cyan,bold}--hardware{normal}           Hardware details\n");
            fossil_io_printf("  {cyan,bold}--boot{normal}               Boot metadata\n");
            fossil_io_printf("  {cyan,bold}--firmware{normal}           Firmware information\n");
            fossil_io_printf("  {cyan,bold}--fson{normal}               Structured output\n");
        }
        else if (fossil_io_cstring_equals(command, "this"))
        {
            fossil_io_printf("{blue,bold,underline}Usage:{normal} {green}this [options]{normal}\n");
            fossil_io_printf("{blue,bold,underline}Options:{normal}\n");
            fossil_io_printf("  {cyan,bold}--os{normal}                 Operating system info\n");
            fossil_io_printf("  {cyan,bold}--arch{normal}               System architecture\n");
            fossil_io_printf("  {cyan,bold}--hostname{normal}           System hostname\n");
            fossil_io_printf("  {cyan,bold}--uptime{normal}             System uptime\n");
            fossil_io_printf("  {cyan,bold}--load{normal}               Load averages\n");
            fossil_io_printf("  {cyan,bold}--all{normal}                Complete system profile\n");
        }
        else if (fossil_io_cstring_equals(command, "network"))
        {
            fossil_io_printf("{blue,bold,underline}Usage:{normal} {green}network [options]{normal}\n");
            fossil_io_printf("{blue,bold,underline}Options:{normal}\n");
            fossil_io_printf("  {cyan,bold}--interfaces{normal}         Network interfaces\n");
            fossil_io_printf("  {cyan,bold}--connections{normal}        Active connections\n");
            fossil_io_printf("  {cyan,bold}--ports{normal}              Open ports\n");
            fossil_io_printf("  {cyan,bold}--routes{normal}             Routing table\n");
            fossil_io_printf("  {cyan,bold}--stats{normal}              Traffic statistics\n");
            fossil_io_printf("  {cyan,bold}--ping <host>{normal}        Ping host\n");
            fossil_io_printf("  {cyan,bold}--trace <host>{normal}       Traceroute\n");
            fossil_io_printf("  {cyan,bold}--dns <host>{normal}         DNS lookup\n");
            fossil_io_printf("  {cyan,bold}--watch{normal}              Live network activity\n");
        }
        else if (fossil_io_cstring_equals(command, "service"))
        {
            fossil_io_printf("{blue,bold,underline}Usage:{normal} {green}service [action] <name>{normal}\n");
            fossil_io_printf("{blue,bold,underline}Options:{normal}\n");
            fossil_io_printf("  {cyan,bold}start <name>{normal}         Start service\n");
            fossil_io_printf("  {cyan,bold}stop <name>{normal}          Stop service\n");
            fossil_io_printf("  {cyan,bold}restart <name>{normal}       Restart service\n");
            fossil_io_printf("  {cyan,bold}reload <name>{normal}        Reload configuration\n");
            fossil_io_printf("  {cyan,bold}status <name>{normal}        Service status\n");
            fossil_io_printf("  {cyan,bold}--enable{normal}             Enable at boot\n");
            fossil_io_printf("  {cyan,bold}--disable{normal}            Disable at boot\n");
            fossil_io_printf("  {cyan,bold}--list{normal}               List all services\n");
            fossil_io_printf("  {cyan,bold}--watch{normal}              Monitor service state\n");
        }
        else if (fossil_io_cstring_equals(command, "system"))
        {
            fossil_io_printf("{blue,bold,underline}Usage:{normal} {green}system [options]{normal}\n");
            fossil_io_printf("{blue,bold,underline}Options:{normal}\n");
            fossil_io_printf("  {cyan,bold}--reboot{normal}             Reboot system\n");
            fossil_io_printf("  {cyan,bold}--shutdown{normal}           Shutdown system\n");
            fossil_io_printf("  {cyan,bold}--suspend{normal}            Suspend system\n");
            fossil_io_printf("  {cyan,bold}--hibernate{normal}          Hibernate system\n");
            fossil_io_printf("  {cyan,bold}--targets{normal}            List system targets\n");
            fossil_io_printf("  {cyan,bold}--default-target <name>{normal} Set default target\n");
        }
        else if (fossil_io_cstring_equals(command, "permit"))
        {
            fossil_io_printf("{blue,bold,underline}Usage:{normal} {green}permit [options]{normal}\n");
            fossil_io_printf("{blue,bold,underline}Options:{normal}\n");
            fossil_io_printf("  {cyan,bold}--user <name>{normal}        Inspect user permissions\n");
            fossil_io_printf("  {cyan,bold}--group <name>{normal}       Inspect group permissions\n");
            fossil_io_printf("  {cyan,bold}--grant <mode>{normal}       Grant permissions\n");
            fossil_io_printf("  {cyan,bold}--revoke <mode>{normal}      Revoke permissions\n");
            fossil_io_printf("  {cyan,bold}--recursive{normal}          Apply recursively\n");
            fossil_io_printf("  {cyan,bold}--audit{normal}              Check permission anomalies\n");
        }
        else if (fossil_io_cstring_equals(command, "notebook"))
        {
            fossil_io_printf("{blue,bold,underline}Usage:{normal} {green}notebook [options]{normal}\n");
            fossil_io_printf("{blue,bold,underline}Options:{normal}\n");
            fossil_io_printf("  {cyan,bold}--boot{normal}               Current boot logs\n");
            fossil_io_printf("  {cyan,bold}--service <name>{normal}     Service logs\n");
            fossil_io_printf("  {cyan,bold}--since <time>{normal}       Logs since time\n");
            fossil_io_printf("  {cyan,bold}--tail <n>{normal}           Last n lines\n");
            fossil_io_printf("  {cyan,bold}--follow{normal}             Live logs\n");
        }
        else if (fossil_io_cstring_equals(command, "view"))
        {
            fossil_io_printf("{blue,bold,underline}Usage:{normal} {green}view [options] <file>{normal}\n");
            fossil_io_printf("{blue,bold,underline}Options:{normal}\n");
            fossil_io_printf("  {cyan,bold}--follow{normal}             Live follow\n");
            fossil_io_printf("  {cyan,bold}--search <pattern>{normal}   Search text\n");
            fossil_io_printf("  {cyan,bold}--lines <n>{normal}          Limit lines\n");
            fossil_io_printf("  {cyan,bold}--color{normal}              Syntax highlighting\n");
        }
        else if (fossil_io_cstring_equals(command, "echo"))
        {
            fossil_io_printf("{blue,bold,underline}Usage:{normal} {green}echo [options] <text>{normal}\n");
            fossil_io_printf("{blue,bold,underline}Options:{normal}\n");
            fossil_io_printf("  {cyan,bold}--cipher <type>{normal}      Encode text\n");
            fossil_io_printf("  {cyan,bold}--speak{normal}              Text-to-speech\n");
            fossil_io_printf("  {cyan,bold}--repeat <n>{normal}         Repeat output\n");
            fossil_io_printf("  {cyan,bold}--format <mode>{normal}      Styled output\n");
        }
        else if (fossil_io_cstring_equals(command, "env"))
        {
            fossil_io_printf("{blue,bold,underline}Usage:{normal} {green}env [options]{normal}\n");
            fossil_io_printf("{blue,bold,underline}Options:{normal}\n");
            fossil_io_printf("  {cyan,bold}--list{normal}               List all variables\n");
            fossil_io_printf("  {cyan,bold}--get <name>{normal}         Retrieve variable\n");
            fossil_io_printf("  {cyan,bold}--set <name=value>{normal}   Set variable\n");
            fossil_io_printf("  {cyan,bold}--unset <name>{normal}       Remove variable\n");
        }
        else if (fossil_io_cstring_equals(command, "calc"))
        {
            fossil_io_printf("{blue,bold,underline}Usage:{normal} {green}calc [options]{normal}\n");
            fossil_io_printf("{blue,bold,underline}Options:{normal}\n");
            fossil_io_printf("  {cyan,bold}--expr <expression>{normal}  Evaluate expression\n");
            fossil_io_printf("  {cyan,bold}--base <n>{normal}           Number base\n");
            fossil_io_printf("  {cyan,bold}--scientific{normal}         Scientific mode\n");
            fossil_io_printf("  {cyan,bold}--precision <n>{normal}      Decimal precision\n");
        }
        else if (fossil_io_cstring_equals(command, "help"))
        {
            fossil_io_printf("{blue,bold,underline}Usage:{normal} {green}help [command]{normal}\n");
            fossil_io_printf("{blue,bold,underline}Options:{normal}\n");
            fossil_io_printf("  {cyan,bold}--examples{normal}  Usage examples\n");
            fossil_io_printf("  {cyan,bold}--man{normal}       Full manual\n");
        }
        else if (fossil_io_cstring_equals(command, "--help"))
        {
            fossil_io_printf("{blue,bold,underline}Usage:{normal} {green}--help{normal}\n");
            fossil_io_printf("{blue,bold,underline}Description:{normal} Show command help\n");
        }
        else if (fossil_io_cstring_equals(command, "--version"))
        {
            fossil_io_printf("{blue,bold,underline}Usage:{normal} {green}--version{normal}\n");
            fossil_io_printf("{blue,bold,underline}Description:{normal} Display Squid Tool version\n");
        }
        else if (fossil_io_cstring_equals(command, "-v") || fossil_io_cstring_equals(command, "--verbose"))
        {
            fossil_io_printf("{blue,bold,underline}Usage:{normal} {green}--verbose{normal}\n");
            fossil_io_printf("{blue,bold,underline}Description:{normal} Enable detailed output\n");
        }
        else if (fossil_io_cstring_equals(command, "-q") || fossil_io_cstring_equals(command, "--quiet"))
        {
            fossil_io_printf("{blue,bold,underline}Usage:{normal} {green}--quiet{normal}\n");
            fossil_io_printf("{blue,bold,underline}Description:{normal} Suppress standard output\n");
        }
        else if (fossil_io_cstring_equals(command, "--dry-run"))
        {
            fossil_io_printf("{blue,bold,underline}Usage:{normal} {green}--dry-run{normal}\n");
            fossil_io_printf("{blue,bold,underline}Description:{normal} Simulate actions without making changes\n");
        }
        else if (fossil_io_cstring_equals(command, "--color"))
        {
            fossil_io_printf("{blue,bold,underline}Usage:{normal} {green}--color{normal}\n");
            fossil_io_printf("{blue,bold,underline}Description:{normal} Colorize output where applicable\n");
        }
        else if (fossil_io_cstring_equals(command, "--time"))
        {
            fossil_io_printf("{blue,bold,underline}Usage:{normal} {green}--time{normal}\n");
            fossil_io_printf("{blue,bold,underline}Description:{normal} Display timestamps in output\n");
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
                fossil_io_printf("  {cyan,bold}squid process -a --sort mem --limit 10{normal}\n");
            else if (fossil_io_cstring_equals(command, "monitor"))
                fossil_io_printf("  {cyan,bold}squid monitor --cpu --memory --interval 5{normal}\n");
            else if (fossil_io_cstring_equals(command, "health") || fossil_io_cstring_equals(command, "doctor"))
                fossil_io_printf("  {cyan,bold}squid health --full --report health.txt{normal}\n");
            else if (fossil_io_cstring_equals(command, "inspect"))
                fossil_io_printf("  {cyan,bold}squid inspect --process 1234 --threads{normal}\n");
            else if (fossil_io_cstring_equals(command, "introspect"))
                fossil_io_printf("  {cyan,bold}squid introspect --kernel --modules{normal}\n");
            else if (fossil_io_cstring_equals(command, "this"))
                fossil_io_printf("  {cyan,bold}squid this --all{normal}\n");
            else if (fossil_io_cstring_equals(command, "network"))
                fossil_io_printf("  {cyan,bold}squid network --ping google.com{normal}\n");
            else if (fossil_io_cstring_equals(command, "service"))
                fossil_io_printf("  {cyan,bold}squid service restart nginx{normal}\n");
            else if (fossil_io_cstring_equals(command, "notebook"))
                fossil_io_printf("  {cyan,bold}squid notebook --service nginx --tail 50{normal}\n");
            else if (fossil_io_cstring_equals(command, "view"))
                fossil_io_printf("  {cyan,bold}squid view --follow --color logfile.txt{normal}\n");
            else if (fossil_io_cstring_equals(command, "echo"))
                fossil_io_printf("  {cyan,bold}squid echo --cipher base64 \"hello\"{normal}\n");
            else if (fossil_io_cstring_equals(command, "env"))
                fossil_io_printf("  {cyan,bold}squid env --list{normal}\n");
            else if (fossil_io_cstring_equals(command, "calc"))
                fossil_io_printf("  {cyan,bold}squid calc --expr \"12*(5+3)\"{normal}\n");
            else if (fossil_io_cstring_equals(command, "help"))
                fossil_io_printf("  {cyan,bold}squid help --examples{normal}\n");
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
