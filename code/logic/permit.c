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

int fossil_squid_permit(ccstring user,
                        ccstring file,
                        ccstring service,
                        ccstring grant_mode,
                        ccstring revoke_mode)
{
    // Validate input
    if (!user || !file || !service || !grant_mode || !revoke_mode) {
        fossil_io_error("[%s] %s", "user.input", fossil_io_what("user.input"));
        return fossil_io_code("user.input");
    }

    // Check if file exists
    int32_t exists = fossil_io_filesys_exists(file);
    if (exists <= 0) {
        fossil_io_error("[%s] %s", "fs.not_found", fossil_io_what("fs.not_found"));
        return fossil_io_code("fs.not_found");
    }

    // Get file metadata
    fossil_io_filesys_obj_t obj;
    if (fossil_io_filesys_stat(file, &obj) != 0) {
        fossil_io_error("[%s] %s", "fs.corrupt", fossil_io_what("fs.corrupt"));
        return fossil_io_code("fs.corrupt");
    }

    // Only operate on files, dirs, or links
    if (obj.type != FOSSIL_FILESYS_TYPE_FILE &&
        obj.type != FOSSIL_FILESYS_TYPE_DIR &&
        obj.type != FOSSIL_FILESYS_TYPE_LINK) {
        fossil_io_error("[%s] %s", "type.invalid", fossil_io_what("type.invalid"));
        return fossil_io_code("type.invalid");
    }

    // Parse grant_mode and revoke_mode (simple example: "rwx")
    fossil_io_filesys_perms_t perms = obj.perms;
    for (const char *p = grant_mode; *p; ++p)
    {
        if (*p == 'r')
            perms.read = true;
        if (*p == 'w')
            perms.write = true;
        if (*p == 'x')
            perms.execute = true;
    }
    for (const char *p = revoke_mode; *p; ++p)
    {
        if (*p == 'r')
            perms.read = false;
        if (*p == 'w')
            perms.write = false;
        if (*p == 'x')
            perms.execute = false;
    }

    // Set permissions based on object type
    int32_t rc = 0;
    if (obj.type == FOSSIL_FILESYS_TYPE_FILE)
        rc = fossil_io_filesys_file_set_perms(file, perms);
    else if (obj.type == FOSSIL_FILESYS_TYPE_DIR)
        rc = fossil_io_filesys_dir_set_perms(file, perms);
    else if (obj.type == FOSSIL_FILESYS_TYPE_LINK)
        rc = fossil_io_filesys_link_set_perms(file, perms);

    if (rc != 0) {
        fossil_io_error("[%s] %s", "fs.permission", fossil_io_what("fs.permission"));
        return fossil_io_code("fs.permission");
    }

    return fossil_io_code("system.ok");
}
