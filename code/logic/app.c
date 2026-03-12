/*
 * -----------------------------------------------------------------------------
 * Project: Fossil Logic
 *
 * This file is part of the Fossil Logic project, which aims to develop high-
 * performance, cross-platform applications and libraries. The code contained
 * herein is subject to the terms and conditions defined in the project license.
 *
 * Author: Michael Gene Brockus (Dreamer)
 *
 * Copyright (C) 2024 Fossil Logic. All rights reserved.
 * -----------------------------------------------------------------------------
 */
#include "fossil/code/app.h"
#include "fossil/code/magic.h"
#include <unistd.h>

int FOSSIL_IO_VERBOSE = false; // Verbose output flag

void show_commands(char *app_name)
{
    fossil_io_printf("{white}Usage: {cyan}%s{white} <command> [options]{reset}\n\n", app_name);

    fossil_io_printf("{blue}Core System Commands:{reset}\n");

    fossil_io_printf("{cyan}  process          {reset}Display and manage system processes\n");
    fossil_io_printf("{bright_black}    -a, --all           Show all processes\n");
    fossil_io_printf("{bright_black}    -p, --pid <id>      Specific process\n");
    fossil_io_printf("{bright_black}    --name <pattern>    Filter by name\n");
    fossil_io_printf("{bright_black}    --sort <key>        cpu/mem/pid/time\n");
    fossil_io_printf("{bright_black}    --tree              Process hierarchy\n");
    fossil_io_printf("{bright_black}    --kill <signal>     Send signal\n");
    fossil_io_printf("{bright_black}    --watch             Live refresh\n");
    fossil_io_printf("{bright_black}    --limit <n>         Limit results\n");

    fossil_io_printf("{cyan}  monitor          {reset}Real-time monitoring of system resources\n");
    fossil_io_printf("{bright_black}    --cpu               CPU metrics\n");
    fossil_io_printf("{bright_black}    --memory            Memory usage\n");
    fossil_io_printf("{bright_black}    --disk              Disk usage\n");
    fossil_io_printf("{bright_black}    --process           Process metrics\n");
    fossil_io_printf("{bright_black}    --top <n>           Top consumers\n");
    fossil_io_printf("{bright_black}    -t, --interval <n>  Refresh interval\n");
    fossil_io_printf("{bright_black}    --watch             Continuous monitoring\n");

    fossil_io_printf("{cyan}  health, doctor   {reset}Perform system health diagnostics and performance checks\n");
    fossil_io_printf("{bright_black}    --quick             Basic health check\n");
    fossil_io_printf("{bright_black}    --full              Complete diagnostics\n");
    fossil_io_printf("{bright_black}    --cpu               CPU health\n");
    fossil_io_printf("{bright_black}    --memory            Memory health\n");
    fossil_io_printf("{bright_black}    --disk              Disk health\n");
    fossil_io_printf("{bright_black}    --report <file>     Export report\n");
    fossil_io_printf("{bright_black}    --fix               Automatic repair\n");
    fossil_io_printf("{bright_black}    --json              Structured output\n");

    fossil_io_printf("{cyan}  inspect          {reset}Deep inspection of system resources and processes\n");
    fossil_io_printf("{bright_black}    --process <pid>     Inspect process\n");
    fossil_io_printf("{bright_black}    --memory            Memory layout\n");
    fossil_io_printf("{bright_black}    --threads           Thread usage\n");
    fossil_io_printf("{bright_black}    --fds               File descriptors\n");
    fossil_io_printf("{bright_black}    --limits            Resource limits\n");
    fossil_io_printf("{bright_black}    --json              Structured output\n");

    fossil_io_printf("{cyan}  introspect       {reset}Low-level introspection of kernel, hardware, and runtime\n");
    fossil_io_printf("{bright_black}    --kernel            Kernel info\n");
    fossil_io_printf("{bright_black}    --modules           Loaded modules\n");
    fossil_io_printf("{bright_black}    --hardware          Hardware details\n");
    fossil_io_printf("{bright_black}    --boot              Boot metadata\n");
    fossil_io_printf("{bright_black}    --firmware          Firmware info\n");
    fossil_io_printf("{bright_black}    --fson              Structured output\n");

    fossil_io_printf("{cyan}  this             {reset}Display detailed information about the current host system\n");
    fossil_io_printf("{bright_black}    --os                Operating system\n");
    fossil_io_printf("{bright_black}    --arch              Architecture\n");
    fossil_io_printf("{bright_black}    --hostname          System hostname\n");
    fossil_io_printf("{bright_black}    --uptime            System uptime\n");
    fossil_io_printf("{bright_black}    --load              Load averages\n");
    fossil_io_printf("{bright_black}    --all               Complete system profile\n");

    fossil_io_printf("{cyan}  service          {reset}Manage system services\n");
    fossil_io_printf("{bright_black}    start <name>        Start service\n");
    fossil_io_printf("{bright_black}    stop <name>         Stop service\n");
    fossil_io_printf("{bright_black}    restart <name>      Restart service\n");
    fossil_io_printf("{bright_black}    reload <name>       Reload config\n");
    fossil_io_printf("{bright_black}    status <name>       Service status\n");
    fossil_io_printf("{bright_black}    --enable            Enable at boot\n");
    fossil_io_printf("{bright_black}    --disable           Disable at boot\n");
    fossil_io_printf("{bright_black}    --list              List services\n");
    fossil_io_printf("{bright_black}    --watch             Monitor state\n");

    fossil_io_printf("{cyan}  system           {reset}Execute system-level control tasks\n");
    fossil_io_printf("{bright_black}    --reboot            Reboot system\n");
    fossil_io_printf("{bright_black}    --shutdown          Shutdown system\n");
    fossil_io_printf("{bright_black}    --suspend           Suspend system\n");
    fossil_io_printf("{bright_black}    --hibernate         Hibernate system\n");
    fossil_io_printf("{bright_black}    --targets           List system targets\n");
    fossil_io_printf("{bright_black}    --default-target    Set default target\n");

    fossil_io_printf("{cyan}  permit           {reset}Inspect and modify system permissions and policies\n");
    fossil_io_printf("{bright_black}    --user <name>       Inspect user permissions\n");
    fossil_io_printf("{bright_black}    --group <name>      Inspect group permissions\n");
    fossil_io_printf("{bright_black}    --grant <mode>      Grant permissions\n");
    fossil_io_printf("{bright_black}    --revoke <mode>     Revoke permissions\n");
    fossil_io_printf("{bright_black}    --recursive         Apply recursively\n");
    fossil_io_printf("{bright_black}    --audit             Permission anomalies\n");

    fossil_io_printf("{cyan}  notebook         {reset}View and query system journal logs\n");
    fossil_io_printf("{bright_black}    --boot              Current boot logs\n");
    fossil_io_printf("{bright_black}    --service <name>    Service logs\n");
    fossil_io_printf("{bright_black}    --since <time>      Logs since time\n");
    fossil_io_printf("{bright_black}    --tail <n>          Last lines\n");
    fossil_io_printf("{bright_black}    --follow            Live logs\n");

    fossil_io_printf("{cyan}  view             {reset}Modern pager for viewing logs, streams, or files\n");
    fossil_io_printf("{bright_black}    --follow            Live follow\n");
    fossil_io_printf("{bright_black}    --search <pattern>  Search text\n");
    fossil_io_printf("{bright_black}    --lines <n>         Limit lines\n");
    fossil_io_printf("{bright_black}    --color             Syntax highlight\n");

    fossil_io_printf("{cyan}  echo             {reset}Output formatted text, encoded text, or spoken responses\n");
    fossil_io_printf("{bright_black}    --cipher <type>     Encode text\n");
    fossil_io_printf("{bright_black}    --speak             Text-to-speech\n");
    fossil_io_printf("{bright_black}    --repeat <n>        Repeat output\n");
    fossil_io_printf("{bright_black}    --format <mode>     Styled output\n");

    fossil_io_printf("{cyan}  env              {reset}Display and manage environment variables\n");
    fossil_io_printf("{bright_black}    --list              List variables\n");
    fossil_io_printf("{bright_black}    --get <name>        Retrieve variable\n");
    fossil_io_printf("{bright_black}    --set <name=value>  Set variable\n");
    fossil_io_printf("{bright_black}    --unset <name>      Remove variable\n");

    fossil_io_printf("{cyan}  calc             {reset}Built-in calculator supporting arithmetic expressions\n");
    fossil_io_printf("{bright_black}    --expr <expr>       Evaluate expression\n");
    fossil_io_printf("{bright_black}    --base <n>          Number base\n");
    fossil_io_printf("{bright_black}    --scientific        Scientific mode\n");
    fossil_io_printf("{bright_black}    --precision <n>     Decimal precision\n");

    fossil_io_printf("{cyan}  help             {reset}Display help for commands\n");
    fossil_io_printf("{bright_black}    --examples          Usage examples\n");
    fossil_io_printf("{bright_black}    --man               Full manual\n");

    fossil_io_printf("\n{blue}Global Flags:{reset}\n");
    fossil_io_printf("{bright_black}  --help                Show command help\n");
    fossil_io_printf("{bright_black}  --version             Display Squid version\n");
    fossil_io_printf("{bright_black}  --name                Display application name\n");
    fossil_io_printf("{bright_black}  -v, --verbose         Enable detailed output\n");
    fossil_io_printf("{bright_black}  --color               Colorize output\n");

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
    if (argc < 2)
    {
        show_commands(argv[0]);
        return 1;
    }

    for (i32 i = 1; i < argc; ++i)
    {
        if (argv[i] == cnullptr)
            continue;

        if (fossil_io_cstring_compare(argv[i], "--help") == 0)
        {
            show_commands(argv[0]);
        }
        else if (fossil_io_cstring_compare(argv[i], "--version") == 0)
        {
            show_version();
        }
        else if (fossil_io_cstring_compare(argv[i], "--name") == 0)
        {
            show_name();
        }
        else if (fossil_io_cstring_compare(argv[i], "--verbose") == 0 ||
                 fossil_io_cstring_compare(argv[i], "-v") == 0)
        {
            FOSSIL_IO_VERBOSE = true;
        }
        else if (fossil_io_cstring_compare(argv[i], "--color") == 0)
        {
            if (i + 1 < argc && argv[i + 1][0] != '-')
            {
                if (fossil_io_cstring_compare(argv[i + 1], "enable") == 0)
                    FOSSIL_IO_COLOR_ENABLE = true;
                else if (fossil_io_cstring_compare(argv[i + 1], "disable") == 0)
                    FOSSIL_IO_COLOR_ENABLE = false;
                else if (fossil_io_cstring_compare(argv[i + 1], "auto") == 0)
                    FOSSIL_IO_COLOR_ENABLE = isatty(STDOUT_FILENO);
                ++i;
            }
        }
        else if (fossil_io_cstring_compare(argv[i], "process") == 0)
        {
            bool show_all = false;
            ccstring name_pattern = cnull, sort_key = cnull;
            int pid = -1, kill_signal = -1;
            bool show_tree = false, watch = false;
            size_t limit = 0;

            for (int j = i + 1; j < argc && argv[j][0] == '-'; j++)
            {
                if (fossil_io_cstring_compare(argv[j], "-a") == 0 || 
                    fossil_io_cstring_compare(argv[j], "--all") == 0)
                    show_all = true;
                else if (fossil_io_cstring_compare(argv[j], "-p") == 0 || 
                         fossil_io_cstring_compare(argv[j], "--pid") == 0 && j + 1 < argc)
                    pid = atoi(argv[++j]);
                else if (fossil_io_cstring_compare(argv[j], "--name") == 0 && j + 1 < argc)
                    name_pattern = argv[++j];
                else if (fossil_io_cstring_compare(argv[j], "--sort") == 0 && j + 1 < argc)
                    sort_key = argv[++j];
                else if (fossil_io_cstring_compare(argv[j], "--tree") == 0)
                    show_tree = true;
                else if (fossil_io_cstring_compare(argv[j], "--kill") == 0 && j + 1 < argc)
                    kill_signal = atoi(argv[++j]);
                else if (fossil_io_cstring_compare(argv[j], "--watch") == 0)
                    watch = true;
                else if (fossil_io_cstring_compare(argv[j], "--limit") == 0 && j + 1 < argc)
                    limit = (size_t)atoi(argv[++j]);
                i = j;
            }
            fossil_squid_process(show_all, pid, name_pattern, sort_key, show_tree, kill_signal, watch, limit);
        }
        else if (fossil_io_cstring_compare(argv[i], "monitor") == 0)
        {
            bool cpu = false, memory = false, disk = false;
            bool process_mon = false, watch = false;
            size_t top_n = 0, interval = 1;

            for (int j = i + 1; j < argc && argv[j][0] == '-'; j++)
            {
                if (fossil_io_cstring_compare(argv[j], "--cpu") == 0)
                    cpu = true;
                else if (fossil_io_cstring_compare(argv[j], "--memory") == 0)
                    memory = true;
                else if (fossil_io_cstring_compare(argv[j], "--disk") == 0)
                    disk = true;
                else if (fossil_io_cstring_compare(argv[j], "--process") == 0)
                    process_mon = true;
                else if (fossil_io_cstring_compare(argv[j], "--top") == 0 && j + 1 < argc)
                    top_n = (size_t)atoi(argv[++j]);
                else if (fossil_io_cstring_compare(argv[j], "-t") == 0 || 
                         fossil_io_cstring_compare(argv[j], "--interval") == 0 && j + 1 < argc)
                    interval = (size_t)atoi(argv[++j]);
                else if (fossil_io_cstring_compare(argv[j], "--watch") == 0)
                    watch = true;
                i = j;
            }
            fossil_squid_monitor(cpu, memory, disk, process_mon, top_n, interval, watch);
        }
        else if (fossil_io_cstring_compare(argv[i], "health") == 0 ||
                 fossil_io_cstring_compare(argv[i], "doctor") == 0)
        {
            bool quick = false, full = false, cpu = false, memory = false;
            bool disk = false, fix = false, json_output = false;
            ccstring report_file = cnull;

            for (int j = i + 1; j < argc && argv[j][0] == '-'; j++)
            {
                if (fossil_io_cstring_compare(argv[j], "--quick") == 0)
                    quick = true;
                else if (fossil_io_cstring_compare(argv[j], "--full") == 0)
                    full = true;
                else if (fossil_io_cstring_compare(argv[j], "--cpu") == 0)
                    cpu = true;
                else if (fossil_io_cstring_compare(argv[j], "--memory") == 0)
                    memory = true;
                else if (fossil_io_cstring_compare(argv[j], "--disk") == 0)
                    disk = true;
                else if (fossil_io_cstring_compare(argv[j], "--report") == 0 && j + 1 < argc)
                    report_file = argv[++j];
                else if (fossil_io_cstring_compare(argv[j], "--fix") == 0)
                    fix = true;
                else if (fossil_io_cstring_compare(argv[j], "--json") == 0)
                    json_output = true;
                i = j;
            }
            fossil_squid_health(quick, full, cpu, memory, disk, report_file, fix, json_output);
        }
        else if (fossil_io_cstring_compare(argv[i], "inspect") == 0)
        {
            int process_pid = -1;
            bool memory = false, threads = false, fds = false;
            bool limits = false, json_output = false;

            for (int j = i + 1; j < argc && argv[j][0] == '-'; j++)
            {
                if (fossil_io_cstring_compare(argv[j], "--process") == 0 && j + 1 < argc)
                    process_pid = atoi(argv[++j]);
                else if (fossil_io_cstring_compare(argv[j], "--memory") == 0)
                    memory = true;
                else if (fossil_io_cstring_compare(argv[j], "--threads") == 0)
                    threads = true;
                else if (fossil_io_cstring_compare(argv[j], "--fds") == 0)
                    fds = true;
                else if (fossil_io_cstring_compare(argv[j], "--limits") == 0)
                    limits = true;
                else if (fossil_io_cstring_compare(argv[j], "--json") == 0)
                    json_output = true;
                i = j;
            }
            fossil_squid_inspect(process_pid, memory, threads, fds, limits, json_output);
        }
        else if (fossil_io_cstring_compare(argv[i], "introspect") == 0)
        {
            bool kernel = false, modules = false, hardware = false;
            bool boot = false, firmware = false, fson_output = false;

            for (int j = i + 1; j < argc && argv[j][0] == '-'; j++)
            {
                if (fossil_io_cstring_compare(argv[j], "--kernel") == 0)
                    kernel = true;
                else if (fossil_io_cstring_compare(argv[j], "--modules") == 0)
                    modules = true;
                else if (fossil_io_cstring_compare(argv[j], "--hardware") == 0)
                    hardware = true;
                else if (fossil_io_cstring_compare(argv[j], "--boot") == 0)
                    boot = true;
                else if (fossil_io_cstring_compare(argv[j], "--firmware") == 0)
                    firmware = true;
                else if (fossil_io_cstring_compare(argv[j], "--fson") == 0)
                    fson_output = true;
                i = j;
            }
            fossil_squid_introspect(kernel, modules, hardware, boot, firmware, fson_output);
        }
        else if (fossil_io_cstring_compare(argv[i], "this") == 0)
        {
            bool os = false, arch = false, hostname = false, uptime = false;
            bool load = false, all = false;

            for (int j = i + 1; j < argc && argv[j][0] == '-'; j++)
            {
                if (fossil_io_cstring_compare(argv[j], "--os") == 0)
                    os = true;
                else if (fossil_io_cstring_compare(argv[j], "--arch") == 0)
                    arch = true;
                else if (fossil_io_cstring_compare(argv[j], "--hostname") == 0)
                    hostname = true;
                else if (fossil_io_cstring_compare(argv[j], "--uptime") == 0)
                    uptime = true;
                else if (fossil_io_cstring_compare(argv[j], "--load") == 0)
                    load = true;
                else if (fossil_io_cstring_compare(argv[j], "--all") == 0)
                    all = true;
                i = j;
            }
            fossil_squid_this(os, arch, hostname, uptime, load, all);
        }
        else if (fossil_io_cstring_compare(argv[i], "service") == 0)
        {
            ccstring action = cnull, service_name = cnull;
            bool enable = false, disable = false, list = false, watch = false;

            for (int j = i + 1; j < argc; j++)
            {
                if (fossil_io_cstring_compare(argv[j], "--enable") == 0)
                    enable = true;
                else if (fossil_io_cstring_compare(argv[j], "--disable") == 0)
                    disable = true;
                else if (fossil_io_cstring_compare(argv[j], "--list") == 0)
                    list = true;
                else if (fossil_io_cstring_compare(argv[j], "--watch") == 0)
                    watch = true;
                else if (argv[j][0] != '-' && !cnotnull(action))
                    action = argv[j];
                else if (argv[j][0] != '-' && !cnotnull(service_name))
                    service_name = argv[j];
                i = j;
            }
            fossil_squid_service(action, service_name, enable, disable, list, watch);
        }
        else if (fossil_io_cstring_compare(argv[i], "system") == 0)
        {
            bool reboot = false, shutdown = false, suspend = false, hibernate = false;
            bool targets = false;
            ccstring default_target = cnull;

            for (int j = i + 1; j < argc && argv[j][0] == '-'; j++)
            {
                if (fossil_io_cstring_compare(argv[j], "--reboot") == 0)
                    reboot = true;
                else if (fossil_io_cstring_compare(argv[j], "--shutdown") == 0)
                    shutdown = true;
                else if (fossil_io_cstring_compare(argv[j], "--suspend") == 0)
                    suspend = true;
                else if (fossil_io_cstring_compare(argv[j], "--hibernate") == 0)
                    hibernate = true;
                else if (fossil_io_cstring_compare(argv[j], "--targets") == 0)
                    targets = true;
                else if (fossil_io_cstring_compare(argv[j], "--default-target") == 0 && j + 1 < argc)
                    default_target = argv[++j];
                i = j;
            }
            fossil_squid_system(reboot, shutdown, suspend, hibernate, targets, default_target);
        }
        else if (fossil_io_cstring_compare(argv[i], "permit") == 0)
        {
            ccstring user = cnull, group = cnull, grant_mode = cnull, revoke_mode = cnull;
            bool recursive = false, audit = false;

            for (int j = i + 1; j < argc && argv[j][0] == '-'; j++)
            {
                if (fossil_io_cstring_compare(argv[j], "--user") == 0 && j + 1 < argc)
                    user = argv[++j];
                else if (fossil_io_cstring_compare(argv[j], "--group") == 0 && j + 1 < argc)
                    group = argv[++j];
                else if (fossil_io_cstring_compare(argv[j], "--grant") == 0 && j + 1 < argc)
                    grant_mode = argv[++j];
                else if (fossil_io_cstring_compare(argv[j], "--revoke") == 0 && j + 1 < argc)
                    revoke_mode = argv[++j];
                else if (fossil_io_cstring_compare(argv[j], "--recursive") == 0)
                    recursive = true;
                else if (fossil_io_cstring_compare(argv[j], "--audit") == 0)
                    audit = true;
                i = j;
            }
            fossil_squid_permit(user, group, grant_mode, revoke_mode, recursive, audit);
        }
        else if (fossil_io_cstring_compare(argv[i], "notebook") == 0)
        {
            bool boot = false, follow = false;
            ccstring service = cnull, since_time = cnull;
            size_t tail_lines = 0;

            for (int j = i + 1; j < argc && argv[j][0] == '-'; j++)
            {
                if (fossil_io_cstring_compare(argv[j], "--boot") == 0)
                    boot = true;
                else if (fossil_io_cstring_compare(argv[j], "--service") == 0 && j + 1 < argc)
                    service = argv[++j];
                else if (fossil_io_cstring_compare(argv[j], "--since") == 0 && j + 1 < argc)
                    since_time = argv[++j];
                else if (fossil_io_cstring_compare(argv[j], "--tail") == 0 && j + 1 < argc)
                    tail_lines = (size_t)atoi(argv[++j]);
                else if (fossil_io_cstring_compare(argv[j], "--follow") == 0)
                    follow = true;
                i = j;
            }
            fossil_squid_notebook(boot, service, since_time, tail_lines, follow);
        }
        else if (fossil_io_cstring_compare(argv[i], "view") == 0)
        {
            ccstring file = cnull, search_pattern = cnull;
            bool follow = false, color = false;
            size_t lines = 0;

            for (int j = i + 1; j < argc && argv[j][0] == '-'; j++)
            {
                if (fossil_io_cstring_compare(argv[j], "--follow") == 0)
                    follow = true;
                else if (fossil_io_cstring_compare(argv[j], "--search") == 0 && j + 1 < argc)
                    search_pattern = argv[++j];
                else if (fossil_io_cstring_compare(argv[j], "--lines") == 0 && j + 1 < argc)
                    lines = (size_t)atoi(argv[++j]);
                else if (fossil_io_cstring_compare(argv[j], "--color") == 0)
                    color = true;
                i = j;
            }
            if (i + 1 < argc && argv[i + 1][0] != '-')
                file = argv[++i];
            fossil_squid_view(file, follow, search_pattern, lines, color);
        }
        else if (fossil_io_cstring_compare(argv[i], "echo") == 0)
        {
            ccstring text = cnull, cipher_type = cnull, format_mode = cnull;
            bool speak = false;
            size_t repeat = 1;

            for (int j = i + 1; j < argc && argv[j][0] == '-'; j++)
            {
                if (fossil_io_cstring_compare(argv[j], "--cipher") == 0 && j + 1 < argc)
                    cipher_type = argv[++j];
                else if (fossil_io_cstring_compare(argv[j], "--speak") == 0)
                    speak = true;
                else if (fossil_io_cstring_compare(argv[j], "--repeat") == 0 && j + 1 < argc)
                    repeat = (size_t)atoi(argv[++j]);
                else if (fossil_io_cstring_compare(argv[j], "--format") == 0 && j + 1 < argc)
                    format_mode = argv[++j];
                i = j;
            }
            if (i + 1 < argc && argv[i + 1][0] != '-')
                text = argv[++i];
            fossil_squid_echo(text, cipher_type, speak, repeat, format_mode);
        }
        else if (fossil_io_cstring_compare(argv[i], "env") == 0)
        {
            bool list = false;
            ccstring get = cnull, set = cnull, unset = cnull;

            for (int j = i + 1; j < argc && argv[j][0] == '-'; j++)
            {
                if (fossil_io_cstring_compare(argv[j], "--list") == 0)
                    list = true;
                else if (fossil_io_cstring_compare(argv[j], "--get") == 0 && j + 1 < argc)
                    get = argv[++j];
                else if (fossil_io_cstring_compare(argv[j], "--set") == 0 && j + 1 < argc)
                    set = argv[++j];
                else if (fossil_io_cstring_compare(argv[j], "--unset") == 0 && j + 1 < argc)
                    unset = argv[++j];
                i = j;
            }
            fossil_squid_env(list, get, set, unset);
        }
        else if (fossil_io_cstring_compare(argv[i], "calc") == 0)
        {
            ccstring expression = cnull;
            int base = 10;
            bool scientific = false;
            size_t precision = 6;

            for (int j = i + 1; j < argc && argv[j][0] == '-'; j++)
            {
                if (fossil_io_cstring_compare(argv[j], "--expr") == 0 && j + 1 < argc)
                    expression = argv[++j];
                else if (fossil_io_cstring_compare(argv[j], "--base") == 0 && j + 1 < argc)
                    base = atoi(argv[++j]);
                else if (fossil_io_cstring_compare(argv[j], "--scientific") == 0)
                    scientific = true;
                else if (fossil_io_cstring_compare(argv[j], "--precision") == 0 && j + 1 < argc)
                    precision = (size_t)atoi(argv[++j]);
                i = j;
            }
            fossil_squid_calc(expression, base, scientific, precision);
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
        else
        {
            fossil_io_printf("{red}Unknown command: %s{reset}\n", argv[i]);
            show_commands(argv[0]);
            return 1;
        }
    }
    return 0;
}
