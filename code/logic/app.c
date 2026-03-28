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

    fossil_io_printf("{blue}Core Commands:{reset}\n");

    fossil_io_printf("{cyan}  process          {reset}Display and manage system processes\n");
    fossil_io_printf("{bright_black}    -a, --all           Show all processes\n");
    fossil_io_printf("{bright_black}    -p, --pid <id>      Specific process\n");
    fossil_io_printf("{bright_black}    --name <pattern>    Filter by name\n");
    fossil_io_printf("{bright_black}    --sort <key>        cpu/mem/pid/time\n");
    fossil_io_printf("{bright_black}    --kill <pid>        Terminate process\n");
    fossil_io_printf("{bright_black}    --signal <sig>      Send signal\n");

    fossil_io_printf("{cyan}  monitor          {reset}Observe system resource usage over time\n");
    fossil_io_printf("{bright_black}    -c, --cpu           CPU metrics\n");
    fossil_io_printf("{bright_black}    -m, --mem           Memory usage\n");
    fossil_io_printf("{bright_black}    -d, --disk          Disk usage\n");
    fossil_io_printf("{bright_black}    -n, --net           Network usage\n");
    fossil_io_printf("{bright_black}    -t, --interval <s>  Refresh interval\n");
    fossil_io_printf("{bright_black}    --top <n>           Show top N usage\n");
    fossil_io_printf("{bright_black}    --graph             ASCII/graphical output\n");

    fossil_io_printf("{cyan}  network          {reset}Display network configuration and traffic\n");
    fossil_io_printf("{bright_black}    --interfaces        Show interfaces\n");
    fossil_io_printf("{bright_black}    --connections       Show connections\n");
    fossil_io_printf("{bright_black}    --routes            Show routes\n");
    fossil_io_printf("{bright_black}    --stats             Show statistics\n");
    fossil_io_printf("{bright_black}    --monitor           Real-time traffic\n");

    fossil_io_printf("{cyan}  health           {reset}Check system health and diagnostics\n");
    fossil_io_printf("{bright_black}    --cpu               CPU load\n");
    fossil_io_printf("{bright_black}    --mem               Memory usage\n");
    fossil_io_printf("{bright_black}    --disk              Disk health\n");
    fossil_io_printf("{bright_black}    --network           Network health\n");
    fossil_io_printf("{bright_black}    --report            Generate summary report\n");

    fossil_io_printf("{cyan}  service          {reset}Manage system services\n");
    fossil_io_printf("{bright_black}    --list              Show services\n");
    fossil_io_printf("{bright_black}    --status <name>     Service status\n");
    fossil_io_printf("{bright_black}    --start <name>      Start service\n");
    fossil_io_printf("{bright_black}    --stop <name>       Stop service\n");
    fossil_io_printf("{bright_black}    --restart <name>    Restart service\n");
    fossil_io_printf("{bright_black}    --enable <name>     Enable at boot\n");
    fossil_io_printf("{bright_black}    --disable <name>    Disable at boot\n");

    fossil_io_printf("{cyan}  system           {reset}System-level operations\n");
    fossil_io_printf("{bright_black}    --info              System info\n");
    fossil_io_printf("{bright_black}    --uptime            System uptime\n");
    fossil_io_printf("{bright_black}    --shutdown          Shutdown system\n");
    fossil_io_printf("{bright_black}    --reboot            Reboot system\n");
    fossil_io_printf("{bright_black}    --update            Update system\n");
    fossil_io_printf("{bright_black}    --config <file>     Use config file\n");

    fossil_io_printf("{cyan}  inspect          {reset}Examine objects, files, or runtime state\n");
    fossil_io_printf("{bright_black}    --file <path>       Inspect file\n");
    fossil_io_printf("{bright_black}    --dir <path>        Inspect directory\n");
    fossil_io_printf("{bright_black}    --process <pid>     Inspect process\n");
    fossil_io_printf("{bright_black}    --service <name>    Inspect service\n");
    fossil_io_printf("{bright_black}    --json              Structured output\n");

    fossil_io_printf("{cyan}  permit           {reset}Adjust permissions for users, files, or services\n");
    fossil_io_printf("{bright_black}    --user <name>       User permissions\n");
    fossil_io_printf("{bright_black}    --file <path>       File permissions\n");
    fossil_io_printf("{bright_black}    --service <name>    Service permissions\n");
    fossil_io_printf("{bright_black}    --grant <perm>      Grant permissions\n");
    fossil_io_printf("{bright_black}    --revoke <perm>     Revoke permissions\n");

    fossil_io_printf("{cyan}  env              {reset}Inspect or set environment variables\n");
    fossil_io_printf("{bright_black}    --list              List variables\n");
    fossil_io_printf("{bright_black}    --get <key>         Get variable\n");
    fossil_io_printf("{bright_black}    --set <key>=<val>   Set variable\n");
    fossil_io_printf("{bright_black}    --unset <key>       Remove variable\n");
    fossil_io_printf("{bright_black}    --export <file>     Export variables\n");

    fossil_io_printf("{cyan}  echo             {reset}Print text or system information\n");
    fossil_io_printf("{bright_black}    --text <msg>        Print message\n");
    fossil_io_printf("{bright_black}    --env <key>         Print environment variable\n");
    fossil_io_printf("{bright_black}    --json              JSON output\n");
    fossil_io_printf("{bright_black}    --color             Color output\n");

    fossil_io_printf("{cyan}  this             {reset}Display a comprehensive system profile\n");
    fossil_io_printf("{bright_black}    --system            OS, kernel, hostname, user, domain, platform\n");
    fossil_io_printf("{bright_black}    --arch              Architecture, CPU, cores, threads, frequency\n");
    fossil_io_printf("{bright_black}    --memory            Total, free, used, available, swap\n");
    fossil_io_printf("{bright_black}    --endianness        Little/big endian\n");
    fossil_io_printf("{bright_black}    --power             AC/battery, charging, battery %%/time left\n");
    fossil_io_printf("{bright_black}    --cpu               Model, vendor, cores, threads, frequency, features\n");
    fossil_io_printf("{bright_black}    --gpu               Name, vendor, driver, memory\n");
    fossil_io_printf("{bright_black}    --storage           Device, mount, total/free/used, filesystem\n");
    fossil_io_printf("{bright_black}    --env               Shell, home, lang, path, term, user\n");
    fossil_io_printf("{bright_black}    --virtualization    VM/container detection, hypervisor, container type\n");
    fossil_io_printf("{bright_black}    --uptime            Uptime, boot time\n");
    fossil_io_printf("{bright_black}    --network           Hostname, IP, MAC, interface, status\n");
    fossil_io_printf("{bright_black}    --process           PID, PPID, exe, cwd, name, privileges\n");
    fossil_io_printf("{bright_black}    --limits            Max open files, max processes, page size\n");
    fossil_io_printf("{bright_black}    --time              Timezone, UTC offset, locale\n");
    fossil_io_printf("{bright_black}    --hardware          Manufacturer, product, serial, BIOS\n");
    fossil_io_printf("{bright_black}    --display           Count, resolution, refresh rate\n");
    fossil_io_printf("{bright_black}    --all               Show everything\n");
    fossil_io_printf("{bright_black}    --json              Structured output\n");

    fossil_io_printf("{cyan}  help             {reset}Display help for commands\n");
    fossil_io_printf("{bright_black}    --examples          Usage examples\n");
    fossil_io_printf("{bright_black}    --man               Full manual\n");
    fossil_io_printf("{bright_black}    --command <cmd>     Command-specific help\n");

    fossil_io_printf("\n{blue}Global Flags:{reset}\n");
    fossil_io_printf("{bright_black}  --help                Show command help\n");
    fossil_io_printf("{bright_black}  --version             Display version\n");
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
            int pid = -1, kill_pid = -1, signal = -1;
            ccstring name_pattern = cnull, sort_key = cnull;
            for (int j = i + 1; j < argc && argv[j][0] == '-'; j++)
            {
                if (fossil_io_cstring_compare(argv[j], "-a") == 0 || fossil_io_cstring_compare(argv[j], "--all") == 0)
                    show_all = true;
                else if ((fossil_io_cstring_compare(argv[j], "-p") == 0 || fossil_io_cstring_compare(argv[j], "--pid") == 0) && j + 1 < argc)
                    pid = atoi(argv[++j]);
                else if (fossil_io_cstring_compare(argv[j], "--name") == 0 && j + 1 < argc)
                    name_pattern = argv[++j];
                else if (fossil_io_cstring_compare(argv[j], "--sort") == 0 && j + 1 < argc)
                    sort_key = argv[++j];
                else if (fossil_io_cstring_compare(argv[j], "--kill") == 0 && j + 1 < argc)
                    kill_pid = atoi(argv[++j]);
                else if (fossil_io_cstring_compare(argv[j], "--signal") == 0 && j + 1 < argc)
                    signal = atoi(argv[++j]);
                i = j;
            }
            fossil_squid_process(show_all, pid, name_pattern, sort_key, kill_pid, signal);
        }
        else if (fossil_io_cstring_compare(argv[i], "monitor") == 0)
        {
            bool cpu = false, memory = false, disk = false, net = false, graph = false;
            size_t interval = 1, top_n = 0;
            for (int j = i + 1; j < argc && argv[j][0] == '-'; j++)
            {
                if (fossil_io_cstring_compare(argv[j], "-c") == 0 || fossil_io_cstring_compare(argv[j], "--cpu") == 0)
                    cpu = true;
                else if (fossil_io_cstring_compare(argv[j], "-m") == 0 || fossil_io_cstring_compare(argv[j], "--mem") == 0)
                    memory = true;
                else if (fossil_io_cstring_compare(argv[j], "-d") == 0 || fossil_io_cstring_compare(argv[j], "--disk") == 0)
                    disk = true;
                else if (fossil_io_cstring_compare(argv[j], "-n") == 0 || fossil_io_cstring_compare(argv[j], "--net") == 0)
                    net = true;
                else if ((fossil_io_cstring_compare(argv[j], "-t") == 0 || fossil_io_cstring_compare(argv[j], "--interval") == 0) && j + 1 < argc)
                    interval = (size_t)atoi(argv[++j]);
                else if (fossil_io_cstring_compare(argv[j], "--top") == 0 && j + 1 < argc)
                    top_n = (size_t)atoi(argv[++j]);
                else if (fossil_io_cstring_compare(argv[j], "--graph") == 0)
                    graph = true;
                i = j;
            }
            fossil_squid_monitor(cpu, memory, disk, net, interval, top_n, graph);
        }
        else if (fossil_io_cstring_compare(argv[i], "network") == 0)
        {
            bool interfaces = false, connections = false, routes = false, stats = false, monitor = false;
            for (int j = i + 1; j < argc && argv[j][0] == '-'; j++)
            {
                if (fossil_io_cstring_compare(argv[j], "--interfaces") == 0)
                    interfaces = true;
                else if (fossil_io_cstring_compare(argv[j], "--connections") == 0)
                    connections = true;
                else if (fossil_io_cstring_compare(argv[j], "--routes") == 0)
                    routes = true;
                else if (fossil_io_cstring_compare(argv[j], "--stats") == 0)
                    stats = true;
                else if (fossil_io_cstring_compare(argv[j], "--monitor") == 0)
                    monitor = true;
                i = j;
            }
            fossil_squid_network(interfaces, connections, routes, stats, monitor);
        }
        else if (fossil_io_cstring_compare(argv[i], "health") == 0)
        {
            bool cpu = false, memory = false, disk = false, network = false, report = false;
            for (int j = i + 1; j < argc && argv[j][0] == '-'; j++)
            {
                if (fossil_io_cstring_compare(argv[j], "--cpu") == 0)
                    cpu = true;
                else if (fossil_io_cstring_compare(argv[j], "--mem") == 0)
                    memory = true;
                else if (fossil_io_cstring_compare(argv[j], "--disk") == 0)
                    disk = true;
                else if (fossil_io_cstring_compare(argv[j], "--network") == 0)
                    network = true;
                else if (fossil_io_cstring_compare(argv[j], "--report") == 0)
                    report = true;
                i = j;
            }
            fossil_squid_health(cpu, memory, disk, network, report);
        }
        else if (fossil_io_cstring_compare(argv[i], "inspect") == 0)
        {
            ccstring file = cnull, dir = cnull, service = cnull;
            int process = -1;
            bool json = false;
            for (int j = i + 1; j < argc && argv[j][0] == '-'; j++)
            {
                if (fossil_io_cstring_compare(argv[j], "--file") == 0 && j + 1 < argc)
                    file = argv[++j];
                else if (fossil_io_cstring_compare(argv[j], "--dir") == 0 && j + 1 < argc)
                    dir = argv[++j];
                else if (fossil_io_cstring_compare(argv[j], "--process") == 0 && j + 1 < argc)
                    process = atoi(argv[++j]);
                else if (fossil_io_cstring_compare(argv[j], "--service") == 0 && j + 1 < argc)
                    service = argv[++j];
                else if (fossil_io_cstring_compare(argv[j], "--json") == 0)
                    json = true;
                i = j;
            }
            fossil_squid_inspect(file, dir, process, service, json);
        }
        else if (fossil_io_cstring_compare(argv[i], "system") == 0)
        {
            bool info = false, uptime = false, shutdown = false, reboot = false, update = false;
            ccstring config_file = cnull;
            for (int j = i + 1; j < argc && argv[j][0] == '-'; j++)
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
            for (int j = i + 1; j < argc && argv[j][0] == '-'; j++)
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
            for (int j = i + 1; j < argc && argv[j][0] == '-'; j++)
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
                else if (fossil_io_cstring_compare(argv[j], "--export") == 0 && j + 1 < argc)
                    export_file = argv[++j];
                i = j;
            }
            fossil_squid_env(list, get, set, unset, export_file);
        }
        else if (fossil_io_cstring_compare(argv[i], "echo") == 0)
        {
            ccstring text = cnull, env_key = cnull;
            bool json = false, color = false;
            for (int j = i + 1; j < argc && argv[j][0] == '-'; j++)
            {
                if (fossil_io_cstring_compare(argv[j], "--text") == 0 && j + 1 < argc)
                    text = argv[++j];
                else if (fossil_io_cstring_compare(argv[j], "--env") == 0 && j + 1 < argc)
                    env_key = argv[++j];
                else if (fossil_io_cstring_compare(argv[j], "--json") == 0)
                    json = true;
                else if (fossil_io_cstring_compare(argv[j], "--color") == 0)
                    color = true;
                i = j;
            }
            fossil_squid_echo(text, env_key, json, color);
        }
        else if (fossil_io_cstring_compare(argv[i], "this") == 0)
        {
            bool system = false, arch = false, memory = false, endianness = false, power = false;
            bool cpu = false, gpu = false, storage = false, env = false, virtualization = false;
            bool uptime = false, network = false, process = false, limits = false, time = false;
            bool hardware = false, display = false, all = false, json = false;
            for (int j = i + 1; j < argc && argv[j][0] == '-'; j++)
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
            fossil_squid_profile(system, arch, memory, endianness, power, cpu, gpu, storage, env,
                                 virtualization, uptime, network, process, limits, time, hardware,
                                 display, all, json);
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
