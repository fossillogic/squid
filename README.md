<p align="center">
    <img src=".github/logo.png" alt="Squid Tool Logo" width="620"/>
</p>

### A System Monitoring Power Utility by **Fossil Logic**

Squid Tool is a powerful **all-in-one system administration and monitoring utility** for admins, developers, and engineers. It unifies essential process management, system diagnostics, and system profiling into a single, consistent command-line interface—eliminating the need for multiple fragmented tools.

---

## Features

- **Process Management** — Use the `process` command to display, filter, and manage system processes. Supports actions like showing all processes, filtering by PID or name, checking existence, viewing details, managing priorities, sending signals, suspending/resuming, terminating, killing, waiting for exit, and spawning new processes.
- **Service Management** — The `service` command allows you to list, check status, start, stop, restart, enable, and disable system services.
- **System Operations** — Use the `system` command for system-level actions such as displaying system info, uptime, shutdown, reboot, updating, and loading configuration files.
- **Resource Inspection** — The `inspect` command examines files, directories, processes, and services, with support for structured JSON output.
- **Permission Management** — The `permit` command inspects and modifies permissions for users, files, and services, including granting and revoking permissions.
- **Environment Variable Management** — The `env` command lists, gets, sets, unsets, and exports environment variables.
- **Flexible Output** — The `echo` command prints text or system information, with options for environment variables, JSON, and colored output.
- **Comprehensive System Profiling** — The `this` command provides a detailed system profile, including OS, hardware, CPU, memory, storage, network, virtualization, uptime, limits, and more, with structured output options.
- **Built-in Help** — The `help` command displays usage information, examples, and manual pages for all commands.

---

Squid Tool delivers unified, professional-grade system administration features with a modern, extensible interface.

---

## **Prerequisites**

Ensure you have the following installed before starting:

- **Meson Build System**: This project relies on Meson. For installation instructions, visit the official [Meson website](https://mesonbuild.com/Getting-meson.html).

## **Setting Up Meson Build**

1. **Install Meson**:
    - Follow the installation guide on the [Meson website](https://mesonbuild.com/Getting-meson.html) for your operating system.

## **Setting Up, Compiling, Installing, and Running the Project**

1. **Clone the Repository**:

    ```sh
    git clone https://github.com/fossillogic/squid.git
    cd squid
    ```

2. **Configure the Build**:

    ```sh
    meson setup builddir
    ```

3. **Compile the Project**:

    ```sh
    meson compile -C builddir
    ```

4. **Install the Project**:

    ```sh
    meson install -C builddir
    ```

5. **Run the Project**:

    ```sh
    squid --help
    ```

## Command Palette

---

## Core System Commands

| Command | Description | Flags / Options |
|---------|-------------|----------------|
| `process` | Display and manage system processes. | <br> `-a`, `--all` (show all processes)<br> `-p`, `--pid <id>` (select specific process)<br> `--name <pattern>` (filter by process name)<br> `--exists <pid>` (check if process exists)<br> `--info <pid>` (show detailed info)<br> `--env <pid>` (show environment variables)<br> `--exe <pid>` (show executable path)<br> `--ppid <pid>` (show parent process ID)<br> `--priority <pid>` (show process priority)<br> `--set-priority <pid> <value>` (change process priority)<br> `--suspend <pid>` (pause process)<br> `--resume <pid>` (resume process)<br> `--terminate <pid>` (terminate process gracefully)<br> `--kill <pid>` (force kill process)<br> `--signal <pid> <sig>` (send signal)<br> `--wait <pid> [--timeout <ms>]` (wait for process exit)<br> `--spawn <exe> [args...]` (start new process)<br> |
| `service` | Manage system services. | `--list` (show services)<br>`--status <name>`<br>`--start <name>`<br>`--stop <name>`<br>`--restart <name>`<br>`--enable <name>`<br>`--disable <name>` |
| `system` | System-level operations (like `systemctl`). | `--info` (system info)<br>`--uptime`<br>`--shutdown`<br>`--reboot`<br>`--update`<br>`--config <file>` |
| `permit` | Adjust permissions for users, files, or services. | `--user <name>`<br>`--file <path>`<br>`--service <name>`<br>`--grant <perm>`<br>`--revoke <perm>` |
| `env` | Inspect or set environment variables. | `--list`<br>`--get <key>`<br>`--set <key>=<value>`<br>`--unset <key>`<br>`--export <file>` |
| `inspect` | Inspect files, directories, processes, and services. | `--file <path>`<br>`--dir <path>`<br>`--process <pid>`<br>`--service <name>`<br>`--json`<br>`--money-to-string <amount>` (format number as money)<br>`--string-to-money <str>` (parse money string)<br>`--money-currency <symbol>` (specify currency symbol)<br>`--number-from-words <str>` (parse English number words)<br>`--number-to-words <num>` (convert number to English words) |
| `echo` | Print text or system information. | `--text <msg>`<br>`--env <key>`<br>`--json`<br>`--color`<br>`--mocking` (mocking SpongeBob case)<br>`--rot13` (ROT13 transform)<br>`--shuffle` (randomize characters)<br>`--piglatin` (Pig Latin transform)<br>`--leet` (Leet speak transform)<br>`--upper-snake` (UPPER_SNAKE_CASE)<br>`--silly` (random case/symbols)<br>`--cipher <type>` (encode text using a named cipher: `caesar`, `vigenere`, `base64`, `base32`, `binary`, `morse`, `baconian`, `railfence`, `haxor`, `leet`, `rot13`, `atbash`) |
| `network` | Manage network sockets, addresses, and connections. | `--init` (initialize networking subsystem)<br>`--shutdown` (shutdown networking subsystem)<br>`--create <type> <family>` (create socket: TCP/UDP/RAW, IPv4/IPv6)<br>`--close <id>` (close socket by ID)<br>`--set-blocking <id> <on/off>` (set blocking mode)<br>`--bind <id> <ip> <port>` (bind socket to address/port)<br>`--listen <id> <backlog>` (listen for incoming connections)<br>`--accept <server-id> <client-id>` (accept connection)<br>`--connect <id> <ip> <port>` (connect to remote address)<br>`--send <id> <data>` (send data)<br>`--receive <id> <size>` (receive data)<br>`--address-parse <ip> <port>` (parse address)<br>`--address-to-string <id>` (format address as string)<br>`--resolve <hostname>` (resolve hostname to IP)<br>`--hostname` (get local hostname)<br>`--mac-get` (get primary MAC address)<br>`--mac-to-string <id>` (format MAC as string)<br>`--poll <id-list> <timeout-ms>` (poll sockets for readiness)<br>`--error-last` (get last socket error code)<br>`--error-string <code>` (describe error code)<br>`--sleep <ms>` (sleep for milliseconds) |
| `this` | Display a comprehensive system profile, with lookup features for each major host property. | `--system` (OS, kernel, hostname, user, domain, platform)<br>`--arch` (architecture, CPU, cores, threads, frequency)<br>`--memory` (total, free, used, available, swap)<br>`--endianness` (little/big endian)<br>`--power` (AC/battery, charging, battery %/time left)<br>`--cpu` (model, vendor, cores, threads, frequency, features)<br>`--gpu` (name, vendor, driver, memory)<br>`--storage` (device, mount, total/free/used, filesystem)<br>`--env` (shell, home, lang, path, term, user)<br>`--virtualization` (VM/container detection, hypervisor, container type)<br>`--uptime` (uptime, boot time)<br>`--network` (hostname, IP, MAC, interface, status)<br>`--process` (PID, PPID, exe, cwd, name, privileges)<br>`--limits` (max open files, max processes, page size)<br>`--time` (timezone, UTC offset, locale)<br>`--hardware` (manufacturer, product, serial, BIOS)<br>`--display` (count, resolution, refresh rate)<br>`--all` (show everything)<br>`--json` (structured output) |
| `help` | Display help for commands. | `--examples`<br>`--man`<br>`--command <cmd>` |

---

## Global Flags (Available to All Commands)

| **Flag** | **Description** |
|-----------|-----------------|
| `--help` | Show command help. |
| `--version` | Display Squid Tool version. |
| `-v, --verbose` | Enable detailed output. |
| `-q, --quiet` | Suppress standard output. |
| `--dry-run` | Simulate actions without changes. |
| `--color` | Colorize output where applicable. |
| `--time` | Display timestamps in output. |

---

## Usage Examples

| **Example** | **Description** |
|---|---|
| `squid process -a` | List all system processes. Uses `-a`/`--all`. |
| `squid service --list` | List all system services. Uses `--list`. |
| `squid system --info` | Show system information. Uses `--info`. |
| `squid permit --user alice --grant sudo` | Grant `sudo` permission to user `alice`. Uses `--user` and `--grant`. |
| `squid env --get PATH` | Display the value of the `PATH` environment variable. Uses `--get PATH`. |
| `squid inspect --file /etc/passwd` | Inspect the `/etc/passwd` file. Uses `--file`. |
| `squid echo --text "Hello, Squid!" --upper-snake` | Print "Hello, Squid!" in UPPER_SNAKE_CASE. Uses `--text` and `--upper-snake`. |
| `squid this --all --json` | Show a full system profile in JSON format. Uses `--all` and `--json`. |
| `squid help --command process` | Show help for the `process` command. Uses `--command process`. |
| `squid network --send 2 "GET / HTTP/1.1\r\n\r\n"` | Send data through socket ID 2. Uses `--send`. |

---

## Command Comparison (Squid vs Traditional Tools)

Squid Tool consolidates many common **system administration utilities** into a **single consistent interface**.

| **Squid Command**      | **Traditional Commands**                                   | **Purpose**                                              |
|------------------------|------------------------------------------------------------|----------------------------------------------------------|
| `squid process`        | `ps`, `top`, `pgrep`, `kill`, `renice`, `nice`            | Display, filter, and manage system processes, including signals and priorities. |
| `squid service`        | `systemctl`, `service`, `chkconfig`                        | Manage system services: list, start, stop, enable, disable, restart. |
| `squid system`         | `uname`, `uptime`, `shutdown`, `reboot`, `cat /etc/os-release` | System-level operations: info, uptime, shutdown, reboot, update. |
| `squid permit`         | `chmod`, `chown`, `usermod`, `setfacl`                     | Inspect and modify permissions for users, files, and services. |
| `squid env`            | `env`, `printenv`, `export`, `unset`                       | List, get, set, unset, and export environment variables. |
| `squid inspect`        | `lsof`, `ls`, `stat`, `file`, `/proc`, `pmap`              | Inspect files, directories, processes, and services with structured output. |
| `squid echo`           | `echo`, `printf`, `env`, `jq`, `tr`, `awk`                 | Print text or system info, transform output, and format data. |
| `squid this`           | `hostnamectl`, `lscpu`, `lsblk`, `free`, `ifconfig`, `dmidecode` | Display a comprehensive system profile (OS, hardware, CPU, memory, storage, network, etc.). |
| `squid help`           | `man`, `--help`, `info`                                    | Show help, usage, and examples for all commands.         |
| `squid network`        | `ifconfig`, `ip`, `ss`, `netstat`, `nc`, `socat`, `hostname`, `arp`, `ping`, `dig` | Manage network sockets, addresses, connections, and perform network diagnostics and configuration. |

This table highlights how Squid Tool unifies and extends the capabilities of many traditional Linux/Unix utilities.

---

## **Contributing**

Interested in contributing? Please open pull requests or create issues on the [GitHub repository](https://github.com/fossillogic/squid).

## **Feedback and Support**

For issues, questions, or feedback, open an issue on the [GitHub repository](https://github.com/fossillogic/squid/issues).

## **License**

This project is licensed under the [Apache Public License](LICENSE).
