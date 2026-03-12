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
                         bool show_tree,
                         int kill_signal,
                         bool watch,
                         size_t limit) {
    fossil_sys_process_list_t plist = {0};
    
    // Get process list
    if (fossil_sys_process_list(&plist) != 0) {
        return -1;
    }
    
    size_t displayed = 0;
    
    // Process each entry
    for (size_t i = 0; i < plist.count && displayed < limit; i++) {
        fossil_sys_process_info_t *proc = &plist.list[i];
        
        // Filter by PID if specified
        if (pid > 0 && (int)proc->pid != pid) {
            continue;
        }
        
        // Filter by name pattern if specified
        if (name_pattern && strstr(proc->name, name_pattern) == NULL) {
            continue;
        }
        
        // Handle kill signal if requested
        if (kill_signal > 0 && pid > 0 && (int)proc->pid == pid) {
            fossil_sys_process_terminate(proc->pid, kill_signal == 9 ? 1 : 0);
            return 0;
        }
        
        // Display process information
        printf("PID: %u, PPID: %u, Name: %s, Mem: %lu KB, CPU: %.2f%%, Threads: %u\n",
               proc->pid, proc->ppid, proc->name, 
               proc->memory_bytes / 1024, proc->cpu_percent, proc->thread_count);
        
        displayed++;
    }
    
    // Cleanup process list
    if (plist.list != NULL) {
        free(plist.list);
    }
    
    // Handle live refresh if watch mode enabled
    if (watch) {
        sleep(1);
        return fossil_squid_process(show_all, pid, name_pattern, 
                                    sort_key, show_tree, kill_signal, false, limit);
    }
    
    return 0;
}
