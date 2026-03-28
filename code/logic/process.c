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


int fossil_squid_process(bool show_all,
                         int pid,
                         ccstring name_pattern,
                         ccstring sort_key,
                         int kill_pid,
                         int signal)
{
    fossil_sys_process_list_t plist;
    int rc = fossil_sys_process_list(&plist);
    if (rc != 0) {
        return rc;
    }

    // If kill_pid is set, try to terminate or signal the process
    if (kill_pid > 0) {
        if (signal > 0) {
            return fossil_sys_process_send_signal((uint32_t)kill_pid, signal);
        } else {
            return fossil_sys_process_terminate((uint32_t)kill_pid, 1);
        }
    }

    // If pid is set, show info for that process only
    if (pid > 0) {
        fossil_sys_process_info_t info;
        if (fossil_sys_process_get_info((uint32_t)pid, &info) == 0) {
            // Print process info (example, replace with your output logic)
            printf("PID: %u, Name: %s, Memory: %llu KB, CPU: %.2f%%, Threads: %u\n",
                   info.pid, info.name, (unsigned long long)(info.memory_bytes / 1024),
                   info.cpu_percent, info.thread_count);
            return 0;
        } else {
            printf("Process with PID %d not found.\n", pid);
            return -1;
        }
    }

    // Otherwise, list all or filtered processes
    for (size_t i = 0; i < plist.count; ++i) {
        fossil_sys_process_info_t *p = &plist.list[i];
        if (!show_all && p->ppid == 1) // skip system/root processes unless show_all
            continue;
        if (name_pattern && name_pattern[0] != '\0' && strstr(p->name, name_pattern) == NULL)
            continue;
        // Print process info (example, replace with your output logic)
        printf("PID: %u, Name: %s, Memory: %llu KB, CPU: %.2f%%, Threads: %u\n",
               p->pid, p->name, (unsigned long long)(p->memory_bytes / 1024),
               p->cpu_percent, p->thread_count);
    }
    return 0;
}
