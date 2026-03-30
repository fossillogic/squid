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
 * @param show_all Show all processes (-a, --all)
 * @param pid Select specific process (-p, --pid <id>)
 * @param name_pattern Filter by process name (--name <pattern>)
 * @param exists_pid Check if process exists (--exists <pid>)
 * @param info_pid Show detailed info (--info <pid>)
 * @param env_pid Show environment variables (--env <pid>)
 * @param exe_pid Show executable path (--exe <pid>)
 * @param ppid_pid Show parent process ID (--ppid <pid>)
 * @param priority_pid Show process priority (--priority <pid>)
 * @param set_priority_pid Change process priority (--set-priority <pid> <value>)
 * @param set_priority_value Priority value for set-priority
 * @param suspend_pid Pause process (--suspend <pid>)
 * @param resume_pid Resume process (--resume <pid>)
 * @param terminate_pid Terminate process gracefully (--terminate <pid>)
 * @param kill_pid Force kill process (--kill <pid>)
 * @param signal_pid Send signal to process (--signal <pid> <sig>)
 * @param signal_value Signal number for --signal
 * @param wait_pid Wait for process exit (--wait <pid>)
 * @param wait_timeout_ms Timeout in milliseconds for wait (optional, --timeout <ms>)
 * @param spawn_exe Start new process (--spawn <exe>)
 * @param spawn_args Arguments for spawned process (NULL-terminated array)
 * @return 0 on success, non-zero on error
 */
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
    ccstring const *spawn_args
);

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
 * @param text Text to output (--text <msg>)
 * @param env_key Environment variable key to print (--env <key>)
 * @param json Output in JSON format (--json)
 * @param color Enable colorized output (--color)
 * @param mocking Apply mocking SpongeBob case (--mocking)
 * @param rot13 Apply ROT13 transform (--rot13)
 * @param shuffle Randomize characters (--shuffle)
 * @param piglatin Apply Pig Latin transform (--piglatin)
 * @param leet Apply Leet speak transform (--leet)
 * @param upper_snake Apply UPPER_SNAKE_CASE transform (--upper-snake)
 * @param silly Apply random case/symbols (--silly)
 * @param cipher_type Encode text using specified cipher (--cipher <type>)
 * @return 0 on success, non-zero on error
 */
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
);

/**
 * Display a comprehensive system profile with lookup features for each major host property.
 * @param system Show OS, kernel, hostname, user, domain, platform
 * @param arch Show architecture, CPU, cores, threads, frequency
 * @param memory Show memory details (total, free, used, available, swap)
 * @param endianness Show endianness (little/big)
 * @param power Show power status (AC/battery, charging, battery %, time left)
 * @param cpu Show CPU details (model, vendor, cores, threads, frequency, features)
 * @param gpu Show GPU details (name, vendor, driver, memory)
 * @param storage Show storage details (device, mount, total/free/used, filesystem)
 * @param env Show environment variables (shell, home, lang, path, term, user)
 * @param virtualization Show virtualization/container info
 * @param uptime Show uptime and boot time
 * @param network Show network info (hostname, IP, MAC, interface, status)
 * @param process Show process info (PID, PPID, exe, cwd, name, privileges)
 * @param limits Show system limits (max open files, max processes, page size)
 * @param time Show time info (timezone, UTC offset, locale)
 * @param hardware Show hardware info (manufacturer, product, serial, BIOS)
 * @param display Show display info (count, resolution, refresh rate)
 * @param all Show all information
 * @param json Output in JSON format
 * @return 0 on success, non-zero on error
 */
int fossil_squid_this(bool system,
                         bool arch,
                         bool memory,
                         bool endianness,
                         bool power,
                         bool cpu,
                         bool gpu,
                         bool storage,
                         bool env,
                         bool virtualization,
                         bool uptime,
                         bool network,
                         bool process,
                         bool limits,
                         bool time,
                         bool hardware,
                         bool display,
                         bool all,
                         bool json);

/**
 * Manage network sockets, addresses, and connections.
 * @param init Initialize networking subsystem (--init)
 * @param shutdown Shutdown networking subsystem (--shutdown)
 * @param create_type Socket type for creation (TCP/UDP/RAW) (--create <type> <family>)
 * @param create_family Address family for creation (IPv4/IPv6) (--create <type> <family>)
 * @param close_id Socket ID to close (--close <id>)
 * @param set_blocking_id Socket ID to set blocking mode (--set-blocking <id> <on/off>)
 * @param set_blocking_on Set blocking mode on (true) or off (false)
 * @param bind_id Socket ID to bind (--bind <id> <ip> <port>)
 * @param bind_ip IP address to bind (--bind <id> <ip> <port>)
 * @param bind_port Port to bind (--bind <id> <ip> <port>)
 * @param listen_id Socket ID to listen (--listen <id> <backlog>)
 * @param listen_backlog Backlog for listen (--listen <id> <backlog>)
 * @param accept_server_id Server socket ID to accept on (--accept <server-id> <client-id>)
 * @param accept_client_id Client socket ID to assign to accepted connection (--accept <server-id> <client-id>)
 * @param connect_id Socket ID to connect (--connect <id> <ip> <port>)
 * @param connect_ip IP address to connect (--connect <id> <ip> <port>)
 * @param connect_port Port to connect (--connect <id> <ip> <port>)
 * @param send_id Socket ID to send data (--send <id> <data>)
 * @param send_data Data to send (--send <id> <data>)
 * @param receive_id Socket ID to receive data (--receive <id> <size>)
 * @param receive_size Number of bytes to receive (--receive <id> <size>)
 * @param address_parse_ip IP address to parse (--address-parse <ip> <port>)
 * @param address_parse_port Port to parse (--address-parse <ip> <port>)
 * @param address_to_string_id Address ID to format as string (--address-to-string <id>)
 * @param resolve_hostname Hostname to resolve (--resolve <hostname>)
 * @param hostname Get local hostname (--hostname)
 * @param mac_get Get primary MAC address (--mac-get)
 * @param mac_to_string_id MAC address ID to format as string (--mac-to-string <id>)
 * @param poll_id_list List of socket IDs to poll (NULL-terminated array) (--poll <id-list> <timeout-ms>)
 * @param poll_timeout_ms Timeout in milliseconds for poll (--poll <id-list> <timeout-ms>)
 * @param error_last Get last socket error code (--error-last)
 * @param error_string_code Error code to describe (--error-string <code>)
 * @param sleep_ms Sleep for milliseconds (--sleep <ms>)
 * @return 0 on success, non-zero on error
 */
int fossil_squid_network(
    bool init,
    bool shutdown,
    ccstring create_type,
    ccstring create_family,
    int close_id,
    int set_blocking_id,
    bool set_blocking_on,
    int bind_id,
    ccstring bind_ip,
    int bind_port,
    int listen_id,
    int listen_backlog,
    int accept_server_id,
    int accept_client_id,
    int connect_id,
    ccstring connect_ip,
    int connect_port,
    int send_id,
    ccstring send_data,
    int receive_id,
    int receive_size,
    ccstring address_parse_ip,
    int address_parse_port,
    int address_to_string_id,
    ccstring resolve_hostname,
    bool hostname,
    bool mac_get,
    int mac_to_string_id,
    int const *poll_id_list,
    int poll_timeout_ms,
    bool error_last,
    int error_string_code,
    int sleep_ms
);

#ifdef __cplusplus
}
#endif

#endif /* FOSSIL_APP_COMMANDS_H */
