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

int fossil_squid_echo(
    ccstring text,
    ccstring env_key,
    bool json,
    bool color,
    bool mocking,
    bool rot13,
    bool shuffle,
    bool zalgo,
    bool piglatin,
    bool leet,
    bool upper_snake,
    bool silly,
    ccstring cipher_type
)
{
    if (!text || !*text) {
        return 1; // Nothing to echo
    }

    // Apply string transformations as requested
    cstring transformed = fossil_io_cstring_create(text);

    if (mocking) {
        cstring tmp = fossil_io_cstring_mocking(transformed);
        fossil_io_cstring_free(transformed);
        transformed = tmp;
    }
    if (rot13) {
        cstring tmp = fossil_io_cstring_rot13(transformed);
        fossil_io_cstring_free(transformed);
        transformed = tmp;
    }
    if (shuffle) {
        cstring tmp = fossil_io_cstring_shuffle(transformed);
        fossil_io_cstring_free(transformed);
        transformed = tmp;
    }
    if (zalgo) {
        cstring tmp = fossil_io_cstring_zalgo(transformed);
        fossil_io_cstring_free(transformed);
        transformed = tmp;
    }
    if (piglatin) {
        cstring tmp = fossil_io_cstring_create(NULL);
        fossil_io_cstring_piglatin(transformed, tmp, 4096);
        fossil_io_cstring_free(transformed);
        transformed = tmp;
    }
    if (leet) {
        cstring tmp = fossil_io_cstring_create(NULL);
        fossil_io_cstring_leetspeak(transformed, tmp, 4096);
        fossil_io_cstring_free(transformed);
        transformed = tmp;
    }
    if (upper_snake) {
        cstring tmp = fossil_io_cstring_upper_snake(transformed);
        fossil_io_cstring_free(transformed);
        transformed = tmp;
    }
    if (silly) {
        cstring tmp = fossil_io_cstring_create(NULL);
        fossil_io_cstring_silly(transformed, tmp, 4096);
        fossil_io_cstring_free(transformed);
        transformed = tmp;
    }

    // Handle cipher flag if provided
    if (cipher_type && *cipher_type) {
        char *ciphered = fossil_io_cipher_encode(transformed, cipher_type);
        if (ciphered) {
            fossil_io_cstring_free(transformed);
            transformed = fossil_io_cstring_create(ciphered);
            free(ciphered);
        }
    }

    // If env_key is provided, print it as a prefix
    if (env_key && *env_key) {
        const char *env_val = fossil_sys_env_get(env_key);
        if (env_val) {
            if (color) {
                fossil_io_printf("{cyan,bold}%s:{reset} %s ", env_key, env_val);
            } else {
                fossil_io_printf("%s: %s ", env_key, env_val);
            }
        } else {
            if (color) {
                fossil_io_printf("{cyan,bold}%s:{reset} ", env_key);
            } else {
                fossil_io_printf("%s: ", env_key);
            }
        }
    }

    if (json) {
        if (color) {
            fossil_io_printf("{green}{bold}\"%s\"{reset}\n", transformed);
        } else {
            fossil_io_printf("\"%s\"\n", transformed);
        }
    } else {
        if (color) {
            fossil_io_printf("{yellow}%s{reset}\n", transformed);
        } else {
            fossil_io_puts(transformed);
        }
    }

    fossil_io_cstring_free(transformed);
    return 0;
}
