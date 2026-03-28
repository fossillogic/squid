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
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

int fossil_squid_process(
    bool show_all,
    int pid,
    ccstring name_pattern,
    int exists_pid,
    int info_pid,
    int env_pid,
    int exe_pid,
    int ppid_pid,
    int priority_pid,
    int set_priority_pid,
    int set_priority_value,
    int suspend_pid,
    int resume_pid,
    int terminate_pid,
    int kill_pid,
    int signal_pid,
    int signal_value,
    int wait_pid,
    int wait_timeout_ms,
    ccstring spawn_exe,
    ccstring const *spawn_args)
{
    // Show all processes
    if (show_all)
    {
        fossil_sys_process_list_t plist;
        int rc = fossil_sys_process_list(&plist);
        if (rc == 0)
        {
            for (size_t i = 0; i < plist.count; ++i)
            {
                fossil_sys_process_info_t *p = &plist.list[i];
                fossil_io_printf(
                    "{blue}PID: {cyan}%u {reset}{blue}PPID: {cyan}%u {reset}{green}Name: {bold}%s{reset} "
                    "{magenta}Mem: {yellow}%llu KB {reset}{magenta}VMem: {yellow}%llu KB {reset}"
                    "{blue}CPU: {yellow}%.2f%% {reset}{red}Threads: {yellow}%u{reset}\n",
                    p->pid, p->ppid, p->name,
                    (unsigned long long)(p->memory_bytes / 1024),
                    (unsigned long long)(p->virtual_memory_bytes / 1024),
                    p->cpu_percent, p->thread_count
                );
            }
        }
        return rc;
    }

    // Check if process exists
    if (exists_pid > 0)
    {
        return fossil_sys_process_exists((uint32_t)exists_pid);
    }

    // Show process info
    if (info_pid > 0)
    {
        fossil_sys_process_info_t info;
        int rc = fossil_sys_process_get_info((uint32_t)info_pid, &info);
        if (rc == 0)
        {
            fossil_io_printf(
                "{blue}PID: {cyan}%u{reset}\n"
                "{blue}PPID: {cyan}%u{reset}\n"
                "{blue}Name: {cyan}%s{reset}\n"
                "{blue}Memory: {cyan}%llu KB{reset}\n"
                "{blue}Virtual Memory: {cyan}%llu KB{reset}\n"
                "{blue}CPU: {cyan}%.2f%%{reset}\n"
                "{blue}Threads: {cyan}%u{reset}\n",
                info.pid, info.ppid, info.name,
                (unsigned long long)(info.memory_bytes / 1024),
                (unsigned long long)(info.virtual_memory_bytes / 1024),
                info.cpu_percent, info.thread_count
            );
        }
        return rc;
    }

    // Show environment variables
    if (env_pid > 0)
    {
        char buffer[4096];
        int rc = fossil_sys_process_get_environment((uint32_t)env_pid, buffer, sizeof(buffer));
        if (rc >= 0)
        {
            fossil_io_printf("{blue}%.*s{reset}\n", rc, buffer);
        }
        return rc;
    }

    // Show executable path
    if (exe_pid > 0)
    {
        char buffer[1024];
        int rc = fossil_sys_process_get_exe_path((uint32_t)exe_pid, buffer, sizeof(buffer));
        if (rc == 0)
        {
            fossil_io_printf("{blue}%s{reset}\n", buffer);
        }
        return rc;
    }

    // Show parent process ID
    if (ppid_pid > 0)
    {
        int ppid = fossil_sys_process_get_ppid((uint32_t)ppid_pid);
        if (ppid >= 0)
            fossil_io_printf("{blue}%d{reset}\n", ppid);
        return (ppid >= 0) ? 0 : -1;
    }

    // Show process priority
    if (priority_pid > 0)
    {
        int priority = 0;
        int rc = fossil_sys_process_get_priority((uint32_t)priority_pid, &priority);
        if (rc == 0)
        {
            fossil_io_printf("{blue}%d{reset}\n", priority);
        }
        return rc;
    }

    // Set process priority
    if (set_priority_pid > 0)
    {
        return fossil_sys_process_set_priority((uint32_t)set_priority_pid, set_priority_value);
    }

    // Suspend process
    if (suspend_pid > 0)
    {
        return fossil_sys_process_suspend((uint32_t)suspend_pid);
    }

    // Resume process
    if (resume_pid > 0)
    {
        return fossil_sys_process_resume((uint32_t)resume_pid);
    }

    // Terminate process gracefully
    if (terminate_pid > 0)
    {
        return fossil_sys_process_terminate((uint32_t)terminate_pid, 0);
    }

    // Force kill process
    if (kill_pid > 0)
    {
        return fossil_sys_process_terminate((uint32_t)kill_pid, 1);
    }

    // Send signal to process
    if (signal_pid > 0 && signal_value > 0)
    {
        return fossil_sys_process_send_signal((uint32_t)signal_pid, signal_value);
    }

    // Wait for process exit
    if (wait_pid > 0)
    {
        return fossil_sys_process_wait((uint32_t)wait_pid, NULL, wait_timeout_ms);
    }

    // Spawn new process
    if (spawn_exe != NULL && spawn_exe[0] != '\0')
    {
        uint32_t new_pid = 0;
        char *const *args = (char *const *)spawn_args;
        return fossil_sys_process_spawn(spawn_exe, args, NULL, &new_pid);
    }

    // Get process name by PID
    if (pid > 0 && (name_pattern == NULL || name_pattern[0] == '\0'))
    {
        char name[FOSSIL_SYS_PROCESS_NAME_MAX];
        int rc = fossil_sys_process_get_name((uint32_t)pid, name, sizeof(name));
        if (rc == 0)
        {
            fossil_io_printf("{blue}%s{reset}\n", name);
        }
        return rc;
    }

    // Filter by process name
    if (name_pattern != NULL && name_pattern[0] != '\0')
    {
        fossil_sys_process_list_t plist;
        int rc = fossil_sys_process_list(&plist);
        if (rc == 0)
        {
            for (size_t i = 0; i < plist.count; ++i)
            {
                fossil_sys_process_info_t *p = &plist.list[i];
                if (strstr(p->name, name_pattern) != NULL)
                {
                    fossil_io_printf(
                        "{blue}PID: {cyan}%u {reset}{blue}PPID: {cyan}%u {reset}{blue}Name: {cyan}%s{reset} "
                        "{blue}Mem: {cyan}%llu KB {reset}{blue}VMem: {cyan}%llu KB {reset}"
                        "{blue}CPU: {cyan}%.2f%% {reset}{blue}Threads: {cyan}%u{reset}\n",
                        p->pid, p->ppid, p->name,
                        (unsigned long long)(p->memory_bytes / 1024),
                        (unsigned long long)(p->virtual_memory_bytes / 1024),
                        p->cpu_percent, p->thread_count
                    );
                }
            }
        }
        return rc;
    }

    return 0;
}