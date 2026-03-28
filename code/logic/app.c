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

    fossil_io_printf("{cyan}  show             {reset}Display files and directories\n");
    fossil_io_printf("{bright_black}    -a, --all           Show hidden files\n");
    fossil_io_printf("{bright_black}    -l, --long          Detailed info\n");
    fossil_io_printf("{bright_black}    -h, --human         Human-readable sizes\n");
    fossil_io_printf("{bright_black}    -r, --recursive     Include subdirs\n");
    fossil_io_printf("{bright_black}    -d, --depth <n>     Limit recursion\n");
    fossil_io_printf("{bright_black}    --as <mode>         Format: list/tree/graph\n");
    fossil_io_printf("{bright_black}    --time              Show timestamps\n");
    fossil_io_printf("{bright_black}    --sort <key>        Sort by: desc/asc\n");
    fossil_io_printf("{bright_black}    --match <pattern>   Filter by name pattern\n");
    fossil_io_printf("{bright_black}    --size <n>          Filter by size (e.g. >1MB)\n");
    fossil_io_printf("{bright_black}    --type <type>       Filter by type: file/dir/link\n");

    fossil_io_printf("{cyan}  merge             {reset}Combine multiple files or directories\n");
    fossil_io_printf("{bright_black}    -f, --force         Overwrite if needed\n");
    fossil_io_printf("{bright_black}    -i, --interactive   Confirm before merge\n");
    fossil_io_printf("{bright_black}    -b, --backup        Backup before merge\n");
    fossil_io_printf("{bright_black}    --strategy <mode>   Merge strategy: overwrite/keep-both/skip\n");
    fossil_io_printf("{bright_black}    --progress          Show progress\n");
    fossil_io_printf("{bright_black}    --dry-run           Preview merge\n");
    fossil_io_printf("{bright_black}    --exclude <pat>     Exclude files\n");
    fossil_io_printf("{bright_black}    --include <pat>     Include files\n");

    fossil_io_printf("{cyan}  swap             {reset}Exchange locations of two files/directories\n");
    fossil_io_printf("{bright_black}    -f, --force         Overwrite if needed\n");
    fossil_io_printf("{bright_black}    -i, --interactive   Confirm swap\n");
    fossil_io_printf("{bright_black}    -b, --backup        Create backups before swap\n");
    fossil_io_printf("{bright_black}    --atomic            Guarantee atomic swap\n");
    fossil_io_printf("{bright_black}    --progress          Show progress\n");
    fossil_io_printf("{bright_black}    --dry-run           Preview swap\n");
    fossil_io_printf("{bright_black}    --temp <path>       Temporary staging location\n");
    fossil_io_printf("{bright_black}    --no-cross-device   Fail if paths on different filesystems\n");

    fossil_io_printf("{cyan}  move             {reset}Move or rename files/directories\n");
    fossil_io_printf("{bright_black}    -f, --force         Overwrite\n");
    fossil_io_printf("{bright_black}    -i, --interactive   Confirm overwrite\n");
    fossil_io_printf("{bright_black}    -b, --backup        Backup before move\n");
    fossil_io_printf("{bright_black}    --atomic            Atomic move\n");
    fossil_io_printf("{bright_black}    --progress          Show progress\n");
    fossil_io_printf("{bright_black}    --dry-run           Simulate\n");
    fossil_io_printf("{bright_black}    --exclude <pat>     Exclude files\n");
    fossil_io_printf("{bright_black}    --include <pat>     Include files\n");

    fossil_io_printf("{cyan}  copy             {reset}Copy files or directories\n");
    fossil_io_printf("{bright_black}    -r, --recursive     Copy subdirs\n");
    fossil_io_printf("{bright_black}    -u, --update        Only newer\n");
    fossil_io_printf("{bright_black}    -p, --preserve      Keep permissions/timestamps\n");
    fossil_io_printf("{bright_black}    --checksum          Verify after copy\n");
    fossil_io_printf("{bright_black}    --sparse            Preserve sparse files\n");
    fossil_io_printf("{bright_black}    --link              Hardlink instead\n");
    fossil_io_printf("{bright_black}    --reflink           Copy-on-write\n");
    fossil_io_printf("{bright_black}    --progress          Show progress\n");
    fossil_io_printf("{bright_black}    --dry-run           Simulate\n");
    fossil_io_printf("{bright_black}    --exclude <pat>     Exclude files\n");
    fossil_io_printf("{bright_black}    --include <pat>     Include files\n");

    fossil_io_printf("{cyan}  remove, delete   {reset}Delete files or directories\n");
    fossil_io_printf("{bright_black}    -r, --recursive     Delete contents\n");
    fossil_io_printf("{bright_black}    -f, --force         No confirmation\n");
    fossil_io_printf("{bright_black}    -i, --interactive   Confirm per file\n");
    fossil_io_printf("{bright_black}    --trash             Move to trash\n");
    fossil_io_printf("{bright_black}    --wipe              Securely overwrite\n");
    fossil_io_printf("{bright_black}    --shred <n>         Multi-pass secure delete\n");
    fossil_io_printf("{bright_black}    --older-than <t>    Delete files older than time\n");
    fossil_io_printf("{bright_black}    --larger-than <s>   Delete files larger than size\n");
    fossil_io_printf("{bright_black}    --empty-only        Delete empty dirs only\n");
    fossil_io_printf("{bright_black}    --log-file <path>   Write deletion log\n");

    fossil_io_printf("{cyan}  rename           {reset}Rename files or directories\n");
    fossil_io_printf("{bright_black}    -f, --force         Overwrite target\n");
    fossil_io_printf("{bright_black}    -i, --interactive   Confirm overwrite\n");

    fossil_io_printf("{cyan}  create           {reset}Create new directories or files\n");
    fossil_io_printf("{bright_black}    -p, --parents       Create parent dirs\n");
    fossil_io_printf("{bright_black}    -t, --type <type>   File or dir\n");

    fossil_io_printf("{cyan}  search           {reset}Find files by name or content\n");
    fossil_io_printf("{bright_black}    -r, --recursive     Include subdirs\n");
    fossil_io_printf("{bright_black}    -n, --name <pat>    Filename match\n");
    fossil_io_printf("{bright_black}    -c, --content <pat> Search contents\n");
    fossil_io_printf("{bright_black}    -i, --ignore-case   Case-insensitive\n");
    fossil_io_printf("{bright_black}    -p, --path <path>   Search within specific path\n");

    fossil_io_printf("{cyan}  archive          {reset}Create, extract, or list archives\n");
    fossil_io_printf("{bright_black}    -c, --create        Create new archive\n");
    fossil_io_printf("{bright_black}    -x, --extract       Extract archive\n");
    fossil_io_printf("{bright_black}    -l, --list          List archive contents\n");
    fossil_io_printf("{bright_black}    -f <format>         Format: zip/tar/gz\n");
    fossil_io_printf("{bright_black}    -p, --password <pw> Encrypt with password\n");
    fossil_io_printf("{bright_black}    --stdout            Output to stdout\n");
    fossil_io_printf("{bright_black}    --compress <n>      Compression level (0-9)\n");
    fossil_io_printf("{bright_black}    --exclude <pat>     Exclude files\n");

    fossil_io_printf("{cyan}  compare          {reset}Compare two files/directories\n");
    fossil_io_printf("{bright_black}    -t, --text          Line diff\n");
    fossil_io_printf("{bright_black}    -b, --binary        Binary diff\n");
    fossil_io_printf("{bright_black}    --context <n>       Context lines\n");
    fossil_io_printf("{bright_black}    --ignore-case       Ignore case\n");

    fossil_io_printf("{cyan}  help             {reset}Display help for commands\n");
    fossil_io_printf("{bright_black}    --examples          Usage examples\n");
    fossil_io_printf("{bright_black}    --man               Full manual\n");

    fossil_io_printf("{cyan}  sync             {reset}Synchronize files/directories\n");
    fossil_io_printf("{bright_black}    -r, --recursive     Include subdirs\n");
    fossil_io_printf("{bright_black}    -u, --update        Only newer\n");
    fossil_io_printf("{bright_black}    --delete            Remove extraneous files\n");

    fossil_io_printf("{cyan}  watch            {reset}Monitor files or directories\n");
    fossil_io_printf("{bright_black}    -r, --recursive     Include subdirs\n");
    fossil_io_printf("{bright_black}    -e, --events <list> Event filter\n");
    fossil_io_printf("{bright_black}    -t, --interval <n>  Poll interval\n");

    fossil_io_printf("{cyan}  rewrite          {reset}Modify file contents or metadata\n");
    fossil_io_printf("{bright_black}    -a, --append        Append\n");
    fossil_io_printf("{bright_black}    --in-place          Edit in place\n");
    fossil_io_printf("{bright_black}    --access-time       Update atime\n");
    fossil_io_printf("{bright_black}    --mod-time          Update mtime\n");
    fossil_io_printf("{bright_black}    --size <n>          Set file size\n");

    fossil_io_printf("{cyan}  introspect       {reset}Examine file contents/type/meta\n");
    fossil_io_printf("{bright_black}    --head <n>          First n lines\n");
    fossil_io_printf("{bright_black}    --tail <n>          Last n lines\n");
    fossil_io_printf("{bright_black}    --count             Count lines/words/bytes\n");
    fossil_io_printf("{bright_black}    --line              Total lines only\n");
    fossil_io_printf("{bright_black}    --size              File size in bytes and human-readable\n");
    fossil_io_printf("{bright_black}    --time              Timestamps: modified, created, accessed\n");
    fossil_io_printf("{bright_black}    --type              Detect and display file type\n");
    fossil_io_printf("{bright_black}    --find <pattern>    Search for string or pattern\n");
    fossil_io_printf("{bright_black}    --fson              FSON structured format output\n");
    fossil_io_printf("{bright_black}    --json              JSON structured format output\n");

    fossil_io_printf("{cyan}  grammar          {reset}Analyze/correct grammar/style\n");
    fossil_io_printf("{bright_black}    --check             Analyze\n");
    fossil_io_printf("{bright_black}    --fix, --correct    Correct\n");
    fossil_io_printf("{bright_black}    --sanitize          Sanitize text\n");
    fossil_io_printf("{bright_black}    --suggest           Suggest improvements\n");
    fossil_io_printf("{bright_black}    --tone              Detect tone\n");
    fossil_io_printf("{bright_black}    --summarize         Summarize\n");
    fossil_io_printf("{bright_black}    --score             Show scores\n");
    fossil_io_printf("{bright_black}    --detect <type>     Detect traits\n");
    fossil_io_printf("{bright_black}    --reflow-width <n>  Reflow text\n");
    fossil_io_printf("{bright_black}    --capitalize <mode> Capitalize\n");
    fossil_io_printf("{bright_black}    --format            Pretty-print\n");
    fossil_io_printf("{bright_black}    --declutter         Repair whitespace\n");
    fossil_io_printf("{bright_black}    --punctuate         Normalize punctuation\n");

    fossil_io_printf("{cyan}  cryptic          {reset}Encode or decode text using various ciphers\n");
    fossil_io_printf("{bright_black}    -e, --encode        Encode text\n");
    fossil_io_printf("{bright_black}    -d, --decode        Decode text\n");
    fossil_io_printf("{bright_black}    -c, --cipher <type> Cipher type: caesar, vigenere, base64, base32,\n");
    fossil_io_printf("{bright_black}                        binary, morse, baconian, railfence, haxor,\n");
    fossil_io_printf("{bright_black}                        leet, rot13, atbash\n");

    fossil_io_printf("{cyan}  split             {reset}Split files into smaller segments\n");
    fossil_io_printf("{bright_black}    -l, --lines <n>     Split by line count\n");
    fossil_io_printf("{bright_black}    -b, --bytes <n>     Split by byte size\n");
    fossil_io_printf("{bright_black}    -n, --number <n>    Number of segments\n");
    fossil_io_printf("{bright_black}    -p, --prefix <name> Output prefix\n");
    fossil_io_printf("{bright_black}    -s, --suffix <n>    Suffix digits\n");
    fossil_io_printf("{bright_black}    --numeric-suffix    Use numeric suffix\n");
    fossil_io_printf("{bright_black}    -d, --delimiter <c> Custom delimiter\n");
    fossil_io_printf("{bright_black}    --dry-run           Preview split\n");

    fossil_io_printf("\n{blue}Global Flags:{reset}\n");
    fossil_io_printf("{bright_black}  --help                Show command help\n");
    fossil_io_printf("{bright_black}  --version             Display Shark Tool version\n");
    fossil_io_printf("{bright_black}  --name                Display application name\n");
    fossil_io_printf("{bright_black}  --verbose             Enable detailed output\n");
    fossil_io_printf("{bright_black}  --color [enable|disable|auto]  Colorize output\n");
    fossil_io_printf("{bright_black}  --clear               Clear the terminal screen\n");

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
            ccstring text = cnull, env_key = cnull;
            bool json = false, color = false;
            for (int j = i + 1; j < argc; j++)
            {
                if (fossil_io_cstring_compare(argv[j], "--json") == 0)
                    json = true;
                else if (fossil_io_cstring_compare(argv[j], "--color") == 0)
                    color = true;
                else if (fossil_io_cstring_compare(argv[j], "--env") == 0 && j + 1 < argc)
                    env_key = argv[++j];
                else if (!cnotnull(text))
                    text = argv[j];
                i = j;
            }
            fossil_squid_echo(text, env_key, json, color);
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
