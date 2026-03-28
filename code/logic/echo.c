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

int fossil_squid_echo(ccstring text,
                      ccstring env_key,
                      bool json,
                      bool color)
{
    if (!text || !*text) {
        return 1; // Nothing to echo
    }

    // If env_key is provided, print it as a prefix
    if (env_key && *env_key) {
        // Try to resolve env_key as a canonical Fossil Sys environment key
        const char *env_val = fossil_sys_env_get(env_key);
        if (env_val) {
            if (color) {
            fossil_io_printf("{cyan,bold}%s:{reset} %s ", env_key, env_val);
            } else {
            fossil_io_printf("%s: %s ", env_key, env_val);
            }
        } else {
            // Fallback: just print the key as before
            if (color) {
            fossil_io_printf("{cyan,bold}%s:{reset} ", env_key);
            } else {
            fossil_io_printf("%s: ", env_key);
            }
        }
    }

    if (json) {
        // Output as JSON string
        if (color) {
            fossil_io_printf("{green}{bold}\"%s\"{reset}\n", text);
        } else {
            fossil_io_printf("\"%s\"\n", text);
        }
    } else {
        if (color) {
            fossil_io_printf("{yellow}%s{reset}\n", text);
        } else {
            fossil_io_puts(text);
        }
    }

    return 0;
}
