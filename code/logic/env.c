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


int fossil_squid_env(bool list,
                     ccstring get,
                     ccstring set,
                     ccstring unset,
                     ccstring export_file)
{
    
    // List all environment variables if 'list' is true
    if (list) {
        const char *keys[] = {
            "fossil.sys.name",
            "fossil.sys.arch",
            "fossil.sys.page_size",
            "fossil.sys.cpu_count",
            "fossil.sys.path",
            "fossil.sys.home",
            "fossil.sys.tmp",
            "fossil.runtime.mode",
            "fossil.runtime.debug",
            "fossil.runtime.log.level",
            "fossil.runtime.log.output",
            "fossil.runtime.seed",
            "fossil.runtime.threads",
            "fossil.app.name",
            "fossil.app.version",
            "fossil.app.instance",
            "fossil.user.name",
            "fossil.user.id",
            "fossil.temp.dir",
            "fossil.temp.cache"
        };
        int n = sizeof(keys) / sizeof(keys[0]);
        for (int i = 0; i < n; ++i) {
            const char *val = fossil_sys_env_get(keys[i]);
            if (val)
                fossil_io_printf("{green}%s{reset}={yellow}%s{reset}\n", keys[i], val);
            else
                fossil_io_printf("{green}%s{reset}={red}<unset>{reset}\n", keys[i]);
        }
        return 0;
    }

    // Get a variable
    if (get) {
        const char *val = fossil_sys_env_get(get);
        if (val)
            fossil_io_printf("{green}%s{reset}={yellow}%s{reset}\n", get, val);
        else
            fossil_io_error("[%s] %s: %s", "config.env", fossil_io_what("config.env"), get);
        return 0;
    }

    // Set a variable (expects set in form "key=value")
    if (set) {
        const char *eq = strchr(set, '=');
        if (!eq || eq == set || !*(eq + 1)) {
            fossil_io_error("[%s] %s: %s", "parse.syntax", fossil_io_what("parse.syntax"), set ? set : "<null>");
            return 1;
        }
        char key[256];
        size_t klen = eq - set;
        if (klen >= sizeof(key)) klen = sizeof(key) - 1;
        strncpy(key, set, klen);
        key[klen] = '\0';
        const char *value = eq + 1;
        if (fossil_sys_env_set(key, value) == 0) {
            fossil_io_printf("{green}Set %s={yellow}%s{reset}\n", key, value);
            return 0;
        } else {
            fossil_io_error("[%s] %s: %s", "config.env", fossil_io_what("config.env"), key);
            return 1;
        }
    }

    // Unset a variable
    if (unset) {
        if (fossil_sys_env_set(unset, NULL) == 0) {
            fossil_io_printf("{yellow}Unset %s{reset}\n", unset);
            return 0;
        } else {
            fossil_io_error("[%s] %s: %s", "config.env", fossil_io_what("config.env"), unset);
            return 1;
        }
    }

    // Export all environment variables to a file using Fossil IO abstraction
    if (export_file) {
        fossil_io_filesys_file_t file;
        int32_t rc = fossil_io_filesys_file_open(&file, export_file, "w");
        if (rc < 0 || !file.is_open) {
            fossil_io_error("[%s] %s: %s", "fs.permission", fossil_io_what("fs.permission"), export_file);
            return 1;
        }
        const char *keys[] = {
            "fossil.sys.name",
            "fossil.sys.arch",
            "fossil.sys.page_size",
            "fossil.sys.cpu_count",
            "fossil.sys.path",
            "fossil.sys.home",
            "fossil.sys.tmp",
            "fossil.runtime.mode",
            "fossil.runtime.debug",
            "fossil.runtime.log.level",
            "fossil.runtime.log.output",
            "fossil.runtime.seed",
            "fossil.runtime.threads",
            "fossil.app.name",
            "fossil.app.version",
            "fossil.app.instance",
            "fossil.user.name",
            "fossil.user.id",
            "fossil.temp.dir",
            "fossil.temp.cache"
        };
        int n = sizeof(keys) / sizeof(keys[0]);
        for (int i = 0; i < n; ++i) {
            const char *val = fossil_sys_env_get(keys[i]);
            if (val) {
                char line[512];
                int len = fossil_io_snprintf(line, sizeof(line), "%s=%s\n", keys[i], val);
                if (len > 0) {
                    if (fossil_io_fputs(&file, line) < 0) {
                        fossil_io_error("[%s] %s: %s", "io.write", fossil_io_what("io.write"), export_file);
                        fossil_io_filesys_file_close(&file);
                        return 1;
                    }
                }
            }
        }
        fossil_io_filesys_file_close(&file);
        fossil_io_printf("{green}Exported environment to {yellow}%s{reset}\n", export_file);
        return 0;
    }
    fossil_io_error("[%s] %s", "user.input", fossil_io_what("user.input"));
    return 1;
}
