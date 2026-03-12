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
 * @param show_tree Display process hierarchy
 * @param kill_signal Send signal to process
 * @param watch Enable live refresh
 * @param limit Limit number of results
 * @return 0 on success
 */
int fossil_squid_process(bool show_all,
                         int pid,
                         ccstring name_pattern,
                         ccstring sort_key,
                         bool show_tree,
                         int kill_signal,
                         bool watch,
                         size_t limit);

/**
 * Real-time monitoring of system resources.
 * @param cpu Monitor CPU usage
 * @param memory Monitor memory usage
 * @param disk Monitor disk usage
 * @param process Monitor specific processes
 * @param top_n Show top N processes by resource usage
 * @param interval Refresh interval in seconds
 * @param watch Enable continuous monitoring
 * @return 0 on success, non-zero on error
 */
int fossil_squid_monitor(bool cpu,
                         bool memory,
                         bool disk,
                         bool process,
                         size_t top_n,
                         size_t interval,
                         bool watch);

/**
 * Perform system health diagnostics.
 * @param quick Perform a quick health check
 * @param full Perform a full health check
 * @param cpu Include CPU diagnostics
 * @param memory Include memory diagnostics
 * @param disk Include disk diagnostics
 * @param report_file Output report to file
 * @param fix Attempt to fix detected issues
 * @param fson_output Output results in FSON format
 * @return 0 on success, non-zero on error
 */
int fossil_squid_health(bool quick,
                        bool full,
                        bool cpu,
                        bool memory,
                        bool disk,
                        ccstring report_file,
                        bool fix,
                        bool fson_output);

/**
 * Deep inspection of system resources and processes.
 * @param process Inspect specific process by PID
 * @param memory Inspect memory layout
 * @param threads Show thread usage
 * @param fds Show file descriptors
 * @param limits Show resource limits
 * @param fson_output Output results in FSON format
 * @return 0 on success, non-zero on error
 */
int fossil_squid_inspect(int process,
                         bool memory,
                         bool threads,
                         bool fds,
                         bool limits,
                         bool fson_output);

/**
 * Low-level system introspection.
 * @param kernel Include kernel information
 * @param modules Include loaded modules
 * @param hardware Include hardware details
 * @param boot Include boot information
 * @param firmware Include firmware details
 * @param fson_output Output results in FSON format
 * @return 0 on success, non-zero on error
 */
int fossil_squid_introspect(bool kernel,
                            bool modules,
                            bool hardware,
                            bool boot,
                            bool firmware,
                            bool fson_output);

/**
 * Display information about the current host system.
 * @param os Include operating system information
 * @param arch Include architecture information
 * @param hostname Include hostname information
 * @param uptime Include system uptime
 * @param load Include system load
 * @param all Include all available information
 * @return 0 on success, non-zero on error
 */
int fossil_squid_this(bool os,
                      bool arch,
                      bool hostname,
                      bool uptime,
                      bool load,
                      bool all);

/**
 * Manage system services.
 * @param action Action to perform (start, stop, restart, reload, status)
 * @param service_name Name of the service
 * @param enable Enable the service at boot
 * @param disable Disable the service at boot
 * @param list List all services
 * @param watch Enable continuous monitoring
 * @return 0 on success, non-zero on error
 */
int fossil_squid_service(ccstring action,
                         ccstring service_name,
                         bool enable,
                         bool disable,
                         bool list,
                         bool watch);

/**
 * System-level control commands.
 * @param reboot Reboot the system
 * @param shutdown Shut down the system
 * @param suspend Suspend the system
 * @param hibernate Hibernate the system
 * @param targets List available power targets
 * @param default_target Set default power target
 * @return 0 on success, non-zero on error
 */
int fossil_squid_system(bool reboot,
                        bool shutdown,
                        bool suspend,
                        bool hibernate,
                        bool targets,
                        ccstring default_target);

/**
 * Inspect and modify permissions.
 * @param user User to inspect or modify permissions for
 * @param group Group to inspect or modify permissions for
 * @param grant_mode Mode to grant permissions
 * @param revoke_mode Mode to revoke permissions
 * @param recursive Apply changes recursively
 * @param audit Enable auditing of permission changes
 * @return 0 on success, non-zero on error
 */
int fossil_squid_permit(ccstring user,
                        ccstring group,
                        ccstring grant_mode,
                        ccstring revoke_mode,
                        bool recursive,
                        bool audit);

/**
 * Query system journal logs.
 * @param boot Include logs from the current boot
 * @param service Filter logs by service name
 * @param since_time Show logs since the specified time
 * @param tail_lines Show the last N lines
 * @param follow Continuously follow new log entries
 * @return 0 on success, non-zero on error
 */
int fossil_squid_notebook(bool boot,
                          ccstring service,
                          ccstring since_time,
                          size_t tail_lines,
                          bool follow);

/**
 * View logs, streams, or files using a pager.
 * @param file Path to the file to view
 * @param follow Continuously follow the file for new content
 * @param search_pattern Search for a specific pattern in the file
 * @param lines Number of lines to display (0 for all)
 * @param color Enable colorized output
 * @return 0 on success, non-zero on error
 */
int fossil_squid_view(ccstring file,
                      bool follow,
                      ccstring search_pattern,
                      size_t lines,
                      bool color);

/**
 * Output formatted text.
 * @param text Text to output
 * @param cipher_type Type of cipher to use for encoding
 * @param speak Enable text-to-speech
 * @param repeat Number of times to repeat the output
 * @param format_mode Format mode for the output
 * @return 0 on success, non-zero on error
 */
int fossil_squid_echo(ccstring text,
                      ccstring cipher_type,
                      bool speak,
                      size_t repeat,
                      ccstring format_mode);

/**
 * Manage environment variables.
 * @param list List all environment variables
 * @param get Get the value of a specific environment variable
 * @param set Set the value of a specific environment variable
 * @param unset Unset a specific environment variable
 * @return 0 on success, non-zero on error
 */
int fossil_squid_env(bool list,
                     ccstring get,
                     ccstring set,
                     ccstring unset);

/**
 * Built-in calculator.
 * @param expression Mathematical expression to evaluate
 * @param base Numerical base for output (e.g., 10 for decimal, 16 for hexadecimal)
 * @param scientific Use scientific notation for output
 * @param precision Number of decimal places for output
 * @return 0 on success, non-zero on error
 */
int fossil_squid_calc(ccstring expression,
                      int base,
                      bool scientific,
                      size_t precision);

#ifdef __cplusplus
}
#endif

#endif /* FOSSIL_APP_COMMANDS_H */
