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
#include "fossil/code/app.h"
#include <unistd.h>
#include <limits.h>
#include <dirent.h>
#include <sys/stat.h>

#ifdef _WIN32
#include <io.h>
#define isatty _isatty
#ifndef STDOUT_FILENO
#define STDOUT_FILENO _fileno(stdout)
#endif
#else
#include <unistd.h>
#endif

int FOSSIL_IO_VERBOSE = false; // Verbose output flag

void show_commands(char *app_name)
{
    fossil_io_printf("{white}Usage: {cyan}%s{white} <command> [options]{reset}\n\n", app_name);

    fossil_io_printf("{blue}Commands:{reset}\n");

    fossil_io_printf("{cyan}  process          {reset}Display and manage system processes\n");
    fossil_io_printf("{bright_black}    -a, --all             Show all processes\n");
    fossil_io_printf("{bright_black}    -p, --pid <id>        Select specific process\n");
    fossil_io_printf("{bright_black}    --name <pattern>      Filter by process name\n");
    fossil_io_printf("{bright_black}    --exists <pid>        Check if process exists\n");
    fossil_io_printf("{bright_black}    --info <pid>          Show detailed info\n");
    fossil_io_printf("{bright_black}    --env <pid>           Show environment variables\n");
    fossil_io_printf("{bright_black}    --exe <pid>           Show executable path\n");
    fossil_io_printf("{bright_black}    --ppid <pid>          Show parent process ID\n");
    fossil_io_printf("{bright_black}    --priority <pid>      Show process priority\n");
    fossil_io_printf("{bright_black}    --set-priority <pid> <value>  Change process priority\n");
    fossil_io_printf("{bright_black}    --suspend <pid>       Pause process\n");
    fossil_io_printf("{bright_black}    --resume <pid>        Resume process\n");
    fossil_io_printf("{bright_black}    --terminate <pid>     Terminate process gracefully\n");
    fossil_io_printf("{bright_black}    --kill <pid>          Force kill process\n");
    fossil_io_printf("{bright_black}    --signal <pid> <sig>  Send signal\n");
    fossil_io_printf("{bright_black}    --wait <pid> [--timeout <ms>]  Wait for process exit\n");
    fossil_io_printf("{bright_black}    --spawn <exe> [args...]  Start new process\n");

    fossil_io_printf("{cyan}  service          {reset}Manage system services\n");
    fossil_io_printf("{bright_black}    --list                Show services\n");
    fossil_io_printf("{bright_black}    --status <name>       Show service status\n");
    fossil_io_printf("{bright_black}    --start <name>        Start service\n");
    fossil_io_printf("{bright_black}    --stop <name>         Stop service\n");
    fossil_io_printf("{bright_black}    --restart <name>      Restart service\n");
    fossil_io_printf("{bright_black}    --enable <name>       Enable service\n");
    fossil_io_printf("{bright_black}    --disable <name>      Disable service\n");

    fossil_io_printf("{cyan}  system           {reset}System-level operations\n");
    fossil_io_printf("{bright_black}    --info                System info\n");
    fossil_io_printf("{bright_black}    --uptime              Show uptime\n");
    fossil_io_printf("{bright_black}    --shutdown            Shutdown system\n");
    fossil_io_printf("{bright_black}    --reboot              Reboot system\n");
    fossil_io_printf("{bright_black}    --update              Update system\n");
    fossil_io_printf("{bright_black}    --config <file>       Specify config file\n");

    fossil_io_printf("{cyan}  permit           {reset}Adjust permissions for users, files, or services\n");
    fossil_io_printf("{bright_black}    --user <name>         Specify user\n");
    fossil_io_printf("{bright_black}    --file <path>         Specify file\n");
    fossil_io_printf("{bright_black}    --service <name>      Specify service\n");
    fossil_io_printf("{bright_black}    --grant <perm>        Grant permission\n");
    fossil_io_printf("{bright_black}    --revoke <perm>       Revoke permission\n");

    fossil_io_printf("{cyan}  env              {reset}Inspect or set environment variables\n");
    fossil_io_printf("{bright_black}    --list                List environment variables\n");
    fossil_io_printf("{bright_black}    --get <key>           Get value\n");
    fossil_io_printf("{bright_black}    --set <key>=<value>   Set value\n");
    fossil_io_printf("{bright_black}    --unset <key>         Unset variable\n");
    fossil_io_printf("{bright_black}    --export <file>       Export to file\n");

    fossil_io_printf("{cyan}  inspect          {reset}Inspect files, directories, processes, and services\n");
    fossil_io_printf("{bright_black}    --file <path>         Inspect file\n");
    fossil_io_printf("{bright_black}    --dir <path>          Inspect directory\n");
    fossil_io_printf("{bright_black}    --process <pid>       Inspect process\n");
    fossil_io_printf("{bright_black}    --service <name>      Inspect service\n");
    fossil_io_printf("{bright_black}    --json                Output as JSON\n");
    fossil_io_printf("{bright_black}    --money-to-string <amount>  Format number as money\n");
    fossil_io_printf("{bright_black}    --string-to-money <str>     Parse money string\n");
    fossil_io_printf("{bright_black}    --money-currency <symbol>   Specify currency symbol\n");
    fossil_io_printf("{bright_black}    --number-from-words <str>   Parse English number words\n");
    fossil_io_printf("{bright_black}    --number-to-words <num>     Convert number to English words\n");

    fossil_io_printf("{cyan}  echo             {reset}Print text or system information\n");
    fossil_io_printf("{bright_black}    --text <msg>          Print message\n");
    fossil_io_printf("{bright_black}    --env <key>           Print environment variable\n");
    fossil_io_printf("{bright_black}    --json                Output as JSON\n");
    fossil_io_printf("{bright_black}    --color               Colorize output\n");
    fossil_io_printf("{bright_black}    --mocking             Mocking SpongeBob case\n");
    fossil_io_printf("{bright_black}    --rot13               ROT13 transform\n");
    fossil_io_printf("{bright_black}    --shuffle             Randomize characters\n");
    fossil_io_printf("{bright_black}    --piglatin            Pig Latin transform\n");
    fossil_io_printf("{bright_black}    --leet                Leet speak transform\n");
    fossil_io_printf("{bright_black}    --upper-snake         UPPER_SNAKE_CASE\n");
    fossil_io_printf("{bright_black}    --silly               Random case/symbols\n");
    fossil_io_printf("{bright_black}    --cipher <type>       Encode text using cipher\n");

    fossil_io_printf("{cyan}  this             {reset}Display a comprehensive system profile\n");
    fossil_io_printf("{bright_black}    --system              OS, kernel, hostname, user, domain, platform\n");
    fossil_io_printf("{bright_black}    --arch                Architecture, CPU, cores, threads, frequency\n");
    fossil_io_printf("{bright_black}    --memory              Memory info\n");
    fossil_io_printf("{bright_black}    --endianness          Endianness\n");
    fossil_io_printf("{bright_black}    --power               Power/battery info\n");
    fossil_io_printf("{bright_black}    --cpu                 CPU details\n");
    fossil_io_printf("{bright_black}    --gpu                 GPU details\n");
    fossil_io_printf("{bright_black}    --storage             Storage info\n");
    fossil_io_printf("{bright_black}    --env                 Environment info\n");
    fossil_io_printf("{bright_black}    --virtualization      Virtualization info\n");
    fossil_io_printf("{bright_black}    --uptime              Uptime/boot time\n");
    fossil_io_printf("{bright_black}    --network             Network info\n");
    fossil_io_printf("{bright_black}    --process             Process info\n");
    fossil_io_printf("{bright_black}    --limits              System limits\n");
    fossil_io_printf("{bright_black}    --time                Timezone/locale\n");
    fossil_io_printf("{bright_black}    --hardware            Hardware info\n");
    fossil_io_printf("{bright_black}    --display             Display info\n");
    fossil_io_printf("{bright_black}    --all                 Show everything\n");
    fossil_io_printf("{bright_black}    --json                Structured output\n");

    fossil_io_printf("{cyan}  help             {reset}Display help for commands\n");
    fossil_io_printf("{bright_black}    --examples            Usage examples\n");
    fossil_io_printf("{bright_black}    --man                 Full manual\n");
    fossil_io_printf("{bright_black}    --command <cmd>       Help for specific command\n");

    exit(FOSSIL_IO_SUCCESS);
}

void show_version(void)
{
    fossil_io_printf("{blue}%s version %s{reset}\n", FOSSIL_APP_NAME, FOSSIL_APP_VERSION);
    exit(FOSSIL_IO_SUCCESS);
}

void show_name(void)
{
    fossil_io_printf("{blue}App Name: {cyan}%s{reset}\n", FOSSIL_APP_NAME);
    exit(FOSSIL_IO_SUCCESS);
}

bool app_entry(int argc, char **argv)
{
    static ccstring supported_commands[] = {
        "help", "process", "system", "service", "permit", "env", "echo", "this",
        "--help", "--version", "--name", "--verbose", "--color", "--clear"
    };
    const int num_supported = sizeof(supported_commands) / sizeof(supported_commands[0]);

    for (i32 i = 1; i < argc; ++i)
    {
        if (argv[i] == cnullptr)
            continue;

        // Unknown command suggestion
        bool handled = false;
        fossil_ti_reason_t ti_reason = {0};
        for (int k = 0; k < num_supported; ++k)
        {
            if (fossil_io_cstring_compare(argv[i], supported_commands[k]) == 0)
            {
                handled = true;
                break;
            }
        }
        if (!handled && argv[i][0] != '-')
        {
            ccstring suggested = fossil_it_magic_suggest_command(argv[i], supported_commands, num_supported, &ti_reason);
            if (cnotnull(suggested))
            {
                int jaccard = fossil_it_magic_jaccard_index(argv[i], suggested);
                int edit_dist = fossil_it_magic_levenshtein_distance(argv[i], suggested);
                float similarity = fossil_it_magic_similarity(argv[i], suggested);
                fossil_io_printf(
                    "{yellow}Did you mean: {cyan}%s{yellow}?{reset}\n"
                    "  {bright_cyan}TI Reason:{reset} {magenta}%s{reset} "
                    "({blue}edit:{reset} {yellow}%d{reset}, "
                    "{blue}sim:{reset} {yellow}%.2f{reset}, "
                    "{blue}jaccard:{reset} {yellow}%d{reset}, "
                    "{blue}prefix:{reset} {yellow}%d{reset}, "
                    "{blue}suffix:{reset} {yellow}%d{reset}, "
                    "{blue}ci:{reset} {yellow}%d{reset})\n",
                    suggested,
                    ti_reason.reason,
                    edit_dist,
                    similarity,
                    jaccard,
                    ti_reason.prefix_match,
                    ti_reason.suffix_match,
                    ti_reason.case_insensitive);
            }
            else
            {
                fossil_io_printf("{red}Unknown command: %s{reset}\n", argv[i]);
            }
            return false;
        }

        if (fossil_io_cstring_compare(argv[i], "--help") == 0)
        {
            fossil_squid_help(cnull, false, false);
            exit(FOSSIL_IO_SUCCESS);
        }
        else if (fossil_io_cstring_compare(argv[i], "--version") == 0)
        {
            show_version();
        }
        else if (fossil_io_cstring_compare(argv[i], "--name") == 0)
        {
            show_name();
        }
        else if (fossil_io_cstring_compare(argv[i], "--verbose") == 0)
        {
            FOSSIL_IO_VERBOSE = true;
            fossil_io_printf("{blue}Verbose mode enabled{reset}\n");
        }
        else if (fossil_io_cstring_compare(argv[i], "--color") == 0)
        {
            if (i + 1 < argc && argv[i + 1] != cnullptr)
            {
                if (fossil_io_cstring_compare(argv[i + 1], "enable") == 0)
                {
                    FOSSIL_IO_COLOR_ENABLE = true;
                }
                else if (fossil_io_cstring_compare(argv[i + 1], "disable") == 0)
                {
                    FOSSIL_IO_COLOR_ENABLE = false;
                }
                else if (fossil_io_cstring_compare(argv[i + 1], "auto") == 0)
                {
                    FOSSIL_IO_COLOR_ENABLE = isatty(STDOUT_FILENO);
                }
                ++i;
            }
        }
        else if (fossil_io_cstring_compare(argv[i], "--clear") == 0)
        {
            fossil_io_clear_screen();
        }
        else if (fossil_io_cstring_compare(argv[i], "help") == 0)
        {
            ccstring command = cnull;
            bool show_examples = false, full_manual = false;
            for (int j = i + 1; j < argc; j++)
            {
                if (fossil_io_cstring_compare(argv[j], "--examples") == 0)
                    show_examples = true;
                else if (fossil_io_cstring_compare(argv[j], "--man") == 0)
                    full_manual = true;
                else if (!cnotnull(command) && argv[j][0] != '-')
                    command = argv[j];
                i = j;
            }
            fossil_squid_help(command, show_examples, full_manual);
        }
        else if (fossil_io_cstring_compare(argv[i], "process") == 0)
        {
            bool show_all = false;
            int pid = -1, exists_pid = -1, info_pid = -1, env_pid = -1, exe_pid = -1, ppid_pid = -1, priority_pid = -1;
            int set_priority_pid = -1, set_priority_value = 0, suspend_pid = -1, resume_pid = -1, terminate_pid = -1, kill_pid = -1;
            int signal_pid = -1, signal_value = 0, wait_pid = -1, wait_timeout_ms = 0;
            ccstring name_pattern = cnull, spawn_exe = cnull;
            ccstring spawn_args_buf[32] = {0};
            int spawn_args_count = 0;

            for (int j = i + 1; j < argc; j++)
            {
                if (fossil_io_cstring_compare(argv[j], "-a") == 0 || fossil_io_cstring_compare(argv[j], "--all") == 0)
                    show_all = true;
                else if (fossil_io_cstring_compare(argv[j], "-p") == 0 && j + 1 < argc)
                    pid = atoi(argv[++j]);
                else if (fossil_io_cstring_compare(argv[j], "--name") == 0 && j + 1 < argc)
                    name_pattern = argv[++j];
                else if (fossil_io_cstring_compare(argv[j], "--exists") == 0 && j + 1 < argc)
                    exists_pid = atoi(argv[++j]);
                else if (fossil_io_cstring_compare(argv[j], "--info") == 0 && j + 1 < argc)
                    info_pid = atoi(argv[++j]);
                else if (fossil_io_cstring_compare(argv[j], "--env") == 0 && j + 1 < argc)
                    env_pid = atoi(argv[++j]);
                else if (fossil_io_cstring_compare(argv[j], "--exe") == 0 && j + 1 < argc)
                    exe_pid = atoi(argv[++j]);
                else if (fossil_io_cstring_compare(argv[j], "--ppid") == 0 && j + 1 < argc)
                    ppid_pid = atoi(argv[++j]);
                else if (fossil_io_cstring_compare(argv[j], "--priority") == 0 && j + 1 < argc)
                    priority_pid = atoi(argv[++j]);
                else if (fossil_io_cstring_compare(argv[j], "--set-priority") == 0 && j + 2 < argc)
                {
                    set_priority_pid = atoi(argv[++j]);
                    set_priority_value = atoi(argv[++j]);
                }
                else if (fossil_io_cstring_compare(argv[j], "--suspend") == 0 && j + 1 < argc)
                    suspend_pid = atoi(argv[++j]);
                else if (fossil_io_cstring_compare(argv[j], "--resume") == 0 && j + 1 < argc)
                    resume_pid = atoi(argv[++j]);
                else if (fossil_io_cstring_compare(argv[j], "--terminate") == 0 && j + 1 < argc)
                    terminate_pid = atoi(argv[++j]);
                else if (fossil_io_cstring_compare(argv[j], "--kill") == 0 && j + 1 < argc)
                    kill_pid = atoi(argv[++j]);
                else if (fossil_io_cstring_compare(argv[j], "--signal") == 0 && j + 2 < argc)
                {
                    signal_pid = atoi(argv[++j]);
                    signal_value = atoi(argv[++j]);
                }
                else if (fossil_io_cstring_compare(argv[j], "--wait") == 0 && j + 1 < argc)
                    wait_pid = atoi(argv[++j]);
                else if (fossil_io_cstring_compare(argv[j], "--timeout") == 0 && j + 1 < argc)
                    wait_timeout_ms = atoi(argv[++j]);
                else if (fossil_io_cstring_compare(argv[j], "--spawn") == 0 && j + 1 < argc)
                {
                    spawn_exe = argv[++j];
                    // Collect all remaining args as spawn_args
                    for (int k = j + 1; k < argc && argv[k][0] != '-'; ++k)
                    {
                        if (spawn_args_count < 31)
                            spawn_args_buf[spawn_args_count++] = argv[k];
                        j = k;
                    }
                    spawn_args_buf[spawn_args_count] = cnull;
                }
                i = j;
            }
            fossil_squid_process(
                show_all, pid, name_pattern, exists_pid, info_pid, env_pid, exe_pid, ppid_pid, priority_pid,
                set_priority_pid, set_priority_value, suspend_pid, resume_pid, terminate_pid, kill_pid,
                signal_pid, signal_value, wait_pid, wait_timeout_ms, spawn_exe,
                spawn_args_count > 0 ? (ccstring const *)spawn_args_buf : cnull
            );
        }
        else if (fossil_io_cstring_compare(argv[i], "system") == 0)
        {
            bool info = false, uptime = false, shutdown = false, reboot = false, update = false;
            ccstring config_file = cnull;
            for (int j = i + 1; j < argc; j++)
            {
                if (fossil_io_cstring_compare(argv[j], "--info") == 0)
                    info = true;
                else if (fossil_io_cstring_compare(argv[j], "--uptime") == 0)
                    uptime = true;
                else if (fossil_io_cstring_compare(argv[j], "--shutdown") == 0)
                    shutdown = true;
                else if (fossil_io_cstring_compare(argv[j], "--reboot") == 0)
                    reboot = true;
                else if (fossil_io_cstring_compare(argv[j], "--update") == 0)
                    update = true;
                else if (fossil_io_cstring_compare(argv[j], "--config") == 0 && j + 1 < argc)
                    config_file = argv[++j];
                i = j;
            }
            fossil_squid_system(info, uptime, shutdown, reboot, update, config_file);
        }
        else if (fossil_io_cstring_compare(argv[i], "service") == 0)
        {
            bool list = false;
            ccstring status = cnull, start = cnull, stop = cnull, restart = cnull, enable = cnull, disable = cnull;
            for (int j = i + 1; j < argc; j++)
            {
                if (fossil_io_cstring_compare(argv[j], "--list") == 0)
                    list = true;
                else if (fossil_io_cstring_compare(argv[j], "--status") == 0 && j + 1 < argc)
                    status = argv[++j];
                else if (fossil_io_cstring_compare(argv[j], "--start") == 0 && j + 1 < argc)
                    start = argv[++j];
                else if (fossil_io_cstring_compare(argv[j], "--stop") == 0 && j + 1 < argc)
                    stop = argv[++j];
                else if (fossil_io_cstring_compare(argv[j], "--restart") == 0 && j + 1 < argc)
                    restart = argv[++j];
                else if (fossil_io_cstring_compare(argv[j], "--enable") == 0 && j + 1 < argc)
                    enable = argv[++j];
                else if (fossil_io_cstring_compare(argv[j], "--disable") == 0 && j + 1 < argc)
                    disable = argv[++j];
                i = j;
            }
            fossil_squid_service(list, status, start, stop, restart, enable, disable);
        }
        else if (fossil_io_cstring_compare(argv[i], "permit") == 0)
        {
            ccstring user = cnull, file = cnull, service = cnull, grant_mode = cnull, revoke_mode = cnull;
            for (int j = i + 1; j < argc; j++)
            {
                if (fossil_io_cstring_compare(argv[j], "--user") == 0 && j + 1 < argc)
                    user = argv[++j];
                else if (fossil_io_cstring_compare(argv[j], "--file") == 0 && j + 1 < argc)
                    file = argv[++j];
                else if (fossil_io_cstring_compare(argv[j], "--service") == 0 && j + 1 < argc)
                    service = argv[++j];
                else if (fossil_io_cstring_compare(argv[j], "--grant") == 0 && j + 1 < argc)
                    grant_mode = argv[++j];
                else if (fossil_io_cstring_compare(argv[j], "--revoke") == 0 && j + 1 < argc)
                    revoke_mode = argv[++j];
                i = j;
            }
            fossil_squid_permit(user, file, service, grant_mode, revoke_mode);
        }
        else if (fossil_io_cstring_compare(argv[i], "env") == 0)
        {
            bool list = false;
            ccstring get = cnull, set = cnull, unset = cnull, export_file = cnull;
            for (int j = i + 1; j < argc; j++)
            {
                if (fossil_io_cstring_compare(argv[j], "--list") == 0)
                    list = true;
                else if (fossil_io_cstring_compare(argv[j], "--get") == 0 && j + 1 < argc)
                    get = argv[++j];
                else if (fossil_io_cstring_compare(argv[j], "--set") == 0 && j + 1 < argc)
                    set = argv[++j];
                else if (fossil_io_cstring_compare(argv[j], "--unset") == 0 && j + 1 < argc)
                    unset = argv[++j];
                else if (fossil_io_cstring_compare(argv[j], "--export") == 0 && j + 1 < argc)
                    export_file = argv[++j];
                i = j;
            }
            fossil_squid_env(list, get, set, unset, export_file);
        }
        else if (fossil_io_cstring_compare(argv[i], "echo") == 0)
        {
            ccstring text = cnull, env_key = cnull, cipher_type = cnull;
            bool json = false, color = false, mocking = false, rot13 = false, shuffle = false;
            bool piglatin = false, leet = false, upper_snake = false, silly = false;
            for (int j = i + 1; j < argc; j++)
            {
                if (fossil_io_cstring_compare(argv[j], "--json") == 0)
                    json = true;
                else if (fossil_io_cstring_compare(argv[j], "--color") == 0)
                    color = true;
                else if (fossil_io_cstring_compare(argv[j], "--mocking") == 0)
                    mocking = true;
                else if (fossil_io_cstring_compare(argv[j], "--rot13") == 0)
                    rot13 = true;
                else if (fossil_io_cstring_compare(argv[j], "--shuffle") == 0)
                    shuffle = true;
                else if (fossil_io_cstring_compare(argv[j], "--piglatin") == 0)
                    piglatin = true;
                else if (fossil_io_cstring_compare(argv[j], "--leet") == 0)
                    leet = true;
                else if (fossil_io_cstring_compare(argv[j], "--upper-snake") == 0)
                    upper_snake = true;
                else if (fossil_io_cstring_compare(argv[j], "--silly") == 0)
                    silly = true;
                else if (fossil_io_cstring_compare(argv[j], "--env") == 0 && j + 1 < argc)
                    env_key = argv[++j];
                else if (fossil_io_cstring_compare(argv[j], "--cipher") == 0 && j + 1 < argc)
                    cipher_type = argv[++j];
                else if (!cnotnull(text))
                    text = argv[j];
                i = j;
            }
            fossil_squid_echo(
                text, env_key, json, color, mocking, rot13, shuffle,
                piglatin, leet, upper_snake, silly, cipher_type
            );
        }
        else if (fossil_io_cstring_compare(argv[i], "this") == 0)
        {
            bool system = false, arch = false, memory = false, endianness = false, power = false, cpu = false, gpu = false;
            bool storage = false, env = false, virtualization = false, uptime = false, network = false, process = false;
            bool limits = false, time = false, hardware = false, display = false, all = false, json = false;
            for (int j = i + 1; j < argc; j++)
            {
                if (fossil_io_cstring_compare(argv[j], "--system") == 0)
                    system = true;
                else if (fossil_io_cstring_compare(argv[j], "--arch") == 0)
                    arch = true;
                else if (fossil_io_cstring_compare(argv[j], "--memory") == 0)
                    memory = true;
                else if (fossil_io_cstring_compare(argv[j], "--endianness") == 0)
                    endianness = true;
                else if (fossil_io_cstring_compare(argv[j], "--power") == 0)
                    power = true;
                else if (fossil_io_cstring_compare(argv[j], "--cpu") == 0)
                    cpu = true;
                else if (fossil_io_cstring_compare(argv[j], "--gpu") == 0)
                    gpu = true;
                else if (fossil_io_cstring_compare(argv[j], "--storage") == 0)
                    storage = true;
                else if (fossil_io_cstring_compare(argv[j], "--env") == 0)
                    env = true;
                else if (fossil_io_cstring_compare(argv[j], "--virtualization") == 0)
                    virtualization = true;
                else if (fossil_io_cstring_compare(argv[j], "--uptime") == 0)
                    uptime = true;
                else if (fossil_io_cstring_compare(argv[j], "--network") == 0)
                    network = true;
                else if (fossil_io_cstring_compare(argv[j], "--process") == 0)
                    process = true;
                else if (fossil_io_cstring_compare(argv[j], "--limits") == 0)
                    limits = true;
                else if (fossil_io_cstring_compare(argv[j], "--time") == 0)
                    time = true;
                else if (fossil_io_cstring_compare(argv[j], "--hardware") == 0)
                    hardware = true;
                else if (fossil_io_cstring_compare(argv[j], "--display") == 0)
                    display = true;
                else if (fossil_io_cstring_compare(argv[j], "--all") == 0)
                    all = true;
                else if (fossil_io_cstring_compare(argv[j], "--json") == 0)
                    json = true;
                i = j;
            }
            fossil_squid_this(system, arch, memory, endianness, power, cpu, gpu, storage, env, virtualization, uptime, network, process, limits, time, hardware, display, all, json);
        }
        else
        {
            fossil_io_printf("{red}Unknown command: %s{reset}\n", argv[i]);
            fossil_squid_help(cnull, false, false);
            return 1;
        }
    }
    return 0;
}
