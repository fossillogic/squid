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
    bool piglatin,
    bool leet,
    bool upper_snake,
    bool silly,
    ccstring cipher_type
)
{
    if (!text || !*text) {
        fossil_io_error("[%s] %s", "user.input", fossil_io_what("user.input"));
        return fossil_io_code("user.input"); // Nothing to echo
    }

    cstring transformed = fossil_io_cstring_create(text);
    if (!transformed) {
        fossil_io_error("[%s] %s", "memory.alloc", fossil_io_what("memory.alloc"));
        return fossil_io_code("memory.alloc");
    }

    if (mocking) {
        cstring tmp = fossil_io_cstring_mocking(transformed);
        if (!tmp) {
            fossil_io_error("[%s] %s", "memory.alloc", fossil_io_what("memory.alloc"));
            fossil_io_cstring_free(transformed);
            return fossil_io_code("memory.alloc");
        }
        fossil_io_cstring_free(transformed);
        transformed = tmp;
    }
    if (rot13) {
        cstring tmp = fossil_io_cstring_rot13(transformed);
        if (!tmp) {
            fossil_io_error("[%s] %s", "memory.alloc", fossil_io_what("memory.alloc"));
            fossil_io_cstring_free(transformed);
            return fossil_io_code("memory.alloc");
        }
        fossil_io_cstring_free(transformed);
        transformed = tmp;
    }
    if (shuffle) {
        cstring tmp = fossil_io_cstring_shuffle(transformed);
        if (!tmp) {
            fossil_io_error("[%s] %s", "memory.alloc", fossil_io_what("memory.alloc"));
            fossil_io_cstring_free(transformed);
            return fossil_io_code("memory.alloc");
        }
        fossil_io_cstring_free(transformed);
        transformed = tmp;
    }
    if (piglatin) {
        cstring tmp = fossil_io_cstring_create(NULL);
        if (!tmp) {
            fossil_io_error("[%s] %s", "memory.alloc", fossil_io_what("memory.alloc"));
            fossil_io_cstring_free(transformed);
            return fossil_io_code("memory.alloc");
        }
        if (!fossil_io_cstring_piglatin(transformed, tmp, 4096)) {
            fossil_io_error("[%s] %s", "data.invalid", fossil_io_what("data.invalid"));
            fossil_io_cstring_free(transformed);
            fossil_io_cstring_free(tmp);
            return fossil_io_code("data.invalid");
        }
        fossil_io_cstring_free(transformed);
        transformed = tmp;
    }
    if (leet) {
        cstring tmp = fossil_io_cstring_create(NULL);
        if (!tmp) {
            fossil_io_error("[%s] %s", "memory.alloc", fossil_io_what("memory.alloc"));
            fossil_io_cstring_free(transformed);
            return fossil_io_code("memory.alloc");
        }
        if (!fossil_io_cstring_leetspeak(transformed, tmp, 4096)) {
            fossil_io_error("[%s] %s", "data.invalid", fossil_io_what("data.invalid"));
            fossil_io_cstring_free(transformed);
            fossil_io_cstring_free(tmp);
            return fossil_io_code("data.invalid");
        }
        fossil_io_cstring_free(transformed);
        transformed = tmp;
    }
    if (upper_snake) {
        cstring tmp = fossil_io_cstring_upper_snake(transformed);
        if (!tmp) {
            fossil_io_error("[%s] %s", "memory.alloc", fossil_io_what("memory.alloc"));
            fossil_io_cstring_free(transformed);
            return fossil_io_code("memory.alloc");
        }
        fossil_io_cstring_free(transformed);
        transformed = tmp;
    }
    if (silly) {
        cstring tmp = fossil_io_cstring_create(NULL);
        if (!tmp) {
            fossil_io_error("[%s] %s", "memory.alloc", fossil_io_what("memory.alloc"));
            fossil_io_cstring_free(transformed);
            return fossil_io_code("memory.alloc");
        }
        if (!fossil_io_cstring_silly(transformed, tmp, 4096)) {
            fossil_io_error("[%s] %s", "data.invalid", fossil_io_what("data.invalid"));
            fossil_io_cstring_free(transformed);
            fossil_io_cstring_free(tmp);
            return fossil_io_code("data.invalid");
        }
        fossil_io_cstring_free(transformed);
        transformed = tmp;
    }

    if (cipher_type && *cipher_type) {
        char *ciphered = fossil_io_cipher_encode(transformed, cipher_type);
        if (!ciphered) {
            fossil_io_error("[%s] %s", "security.encryption", fossil_io_what("security.encryption"));
            fossil_io_cstring_free(transformed);
            return fossil_io_code("security.encryption");
        }
        fossil_io_cstring_free(transformed);
        transformed = fossil_io_cstring_create(ciphered);
        free(ciphered);
        if (!transformed) {
            fossil_io_error("[%s] %s", "memory.alloc", fossil_io_what("memory.alloc"));
            return fossil_io_code("memory.alloc");
        }
    }

    if (env_key && *env_key) {
        const char *env_val = fossil_sys_env_get(env_key);
        if (!env_val) {
            fossil_io_error("[%s] %s", "config.env", fossil_io_what("config.env"));
        }
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
    return fossil_io_code("system.ok");
}
