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
#ifndef FOSSIL_APP_COMMANDS_H
#define FOSSIL_APP_COMMANDS_H

#include "common.h"

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * Display help information and usage examples
 * @param command Command name to show help for
 * @param show_examples Include usage examples in help output
 * @param full_manual Show complete manual instead of brief help
 * @return 0 on success, non-zero on error
 */
int fossil_squid_help(ccstring command, bool show_examples, bool full_manual);

/**
 * Display and manage system processes.
 * @param show_all Show all processes
 * @param pid Specific process ID
 * @param name_pattern Filter by process name pattern
 * @param sort_key Sort key (cpu, mem, pid, time)
 * @param kill_pid PID of process to terminate
 * @param signal Signal number to send
 * @return 0 on success
 */
int fossil_squid_process(bool show_all,
                         int pid,
                         ccstring name_pattern,
                         ccstring sort_key,
                         int kill_pid,
                         int signal);

/**
 * Real-time monitoring of system resources.
 * @param cpu Monitor CPU usage
 * @param memory Monitor memory usage
 * @param disk Monitor disk usage
 * @param net Monitor network usage
 * @param interval Refresh interval in seconds
 * @param top_n Show top N processes by resource usage
 * @param graph Enable graphical/ASCII output
 * @return 0 on success, non-zero on error
 */
int fossil_squid_monitor(bool cpu,
                         bool memory,
                         bool disk,
                         bool net,
                         size_t interval,
                         size_t top_n,
                         bool graph);

/**
 * Display network configuration and traffic.
 * @param interfaces Show network interfaces
 * @param connections Show active connections
 * @param routes Show routing table
 * @param stats Show network statistics
 * @param monitor Enable real-time traffic monitoring
 * @return 0 on success, non-zero on error
 */
int fossil_squid_network(bool interfaces,
                         bool connections,
                         bool routes,
                         bool stats,
                         bool monitor);

/**
 * Perform system health diagnostics.
 * @param cpu Include CPU diagnostics
 * @param memory Include memory diagnostics
 * @param disk Include disk diagnostics
 * @param network Include network diagnostics
 * @param report Generate summary report
 * @return 0 on success, non-zero on error
 */
int fossil_squid_health(bool cpu,
                        bool memory,
                        bool disk,
                        bool network,
                        bool report);

/**
 * Deep inspection of system resources and processes.
 * @param file Inspect specific file
 * @param dir Inspect specific directory
 * @param process Inspect process by PID
 * @param service Inspect service by name
 * @param json Output results in JSON format
 * @return 0 on success, non-zero on error
 */
int fossil_squid_inspect(ccstring file,
                         ccstring dir,
                         int process,
                         ccstring service,
                         bool json);

/**
 * Display information about the current host system.
 * @param info Show system info
 * @param uptime Show system uptime
 * @param shutdown Shut down the system
 * @param reboot Reboot the system
 * @param update Perform system update
 * @param config_file Path to config file
 * @return 0 on success, non-zero on error
 */
int fossil_squid_system(bool info,
                        bool uptime,
                        bool shutdown,
                        bool reboot,
                        bool update,
                        ccstring config_file);

/**
 * Manage system services.
 * @param list List all services
 * @param status Service name to show status
 * @param start Service name to start
 * @param stop Service name to stop
 * @param restart Service name to restart
 * @param enable Service name to enable at boot
 * @param disable Service name to disable at boot
 * @return 0 on success, non-zero on error
 */
int fossil_squid_service(bool list,
                         ccstring status,
                         ccstring start,
                         ccstring stop,
                         ccstring restart,
                         ccstring enable,
                         ccstring disable);

/**
 * Inspect and modify permissions.
 * @param user User to inspect or modify permissions for
 * @param file File path to inspect or modify
 * @param service Service name to inspect or modify
 * @param grant_mode Mode to grant permissions
 * @param revoke_mode Mode to revoke permissions
 * @return 0 on success, non-zero on error
 */
int fossil_squid_permit(ccstring user,
                        ccstring file,
                        ccstring service,
                        ccstring grant_mode,
                        ccstring revoke_mode);

/**
 * Manage environment variables.
 * @param list List all environment variables
 * @param get Get the value of a specific environment variable
 * @param set Set the value of a specific environment variable
 * @param unset Unset a specific environment variable
 * @param export_file Export environment to file
 * @return 0 on success, non-zero on error
 */
int fossil_squid_env(bool list,
                     ccstring get,
                     ccstring set,
                     ccstring unset,
                     ccstring export_file);

/**
 * Output formatted text or system information.
 * @param text Text to output
 * @param env_key Environment variable key to print
 * @param json Output in JSON format
 * @param color Enable colorized output
 * @return 0 on success, non-zero on error
 */
int fossil_squid_echo(ccstring text,
                      ccstring env_key,
                      bool json,
                      bool color);

#ifdef __cplusplus
}
#endif

#endif /* FOSSIL_APP_COMMANDS_H */
