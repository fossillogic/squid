<p align="center">
    <img src=".github/logo.png" alt="Squid Tool Logo" width="620"/>
</p>

### A System Monitoring Power Utility by **Fossil Logic**

Squid Tool is the ultimate **all-in-one system administration and monitoring utility** for admins, developers, and system engineers. It consolidates essential process management, system diagnostics, and real-time monitoring into a single command-line interface—eliminating tool fragmentation. Unique commands like `health` for comprehensive diagnostics, `audit` for security tracking, `inspect` for deep analysis, and `introspect` for kernel-level insights provide capabilities rarely found in traditional utilities, delivering the precision and control professionals demand.

---

## Features

- **Process Management** — `process` command with filtering, sorting, hierarchy view, and signal control
- **Real-Time Monitoring** — `monitor` for live CPU, memory, disk, and network metrics with customizable intervals
- **System Health & Diagnostics** — `health`/`doctor` commands for quick and comprehensive system analysis with auto-repair
- **Deep Resource Inspection** — `inspect` for process details, memory layout, threads, file descriptors, and limits
- **Kernel & Hardware Introspection** — `introspect` for kernel info, modules, hardware details, and firmware data
- **System Overview** — `this` command for quick host system profile and statistics
- **Network Analysis** — `network` for interfaces, connections, ports, routes, ping, traceroute, and DNS lookup
- **Service Management** — `service` for lifecycle control and monitoring of system services
- **System Control** — `system` for reboot, shutdown, suspend, and target management
- **Permission Management** — `permit` to inspect and modify user/group permissions with anomaly detection
- **Log Viewing** — `notebook` for journalctl-like log querying and `view` for modern paging
- **Environment & Utilities** — `env` for variable management, `calc` for expressions, `echo` for formatted output and encoding
- **Cross-Platform Support** — Seamless operation on Linux, macOS, and Windows


## **Why Choose Squid Tool?**
- **Unified Command Suite**: One tool replaces `ps`, `top`, `systemctl`, `journalctl`, `ifconfig`, `netstat`, `lsof`, and more—eliminating context switching.
- **Unique Advanced Commands**: `health`/`doctor` for comprehensive diagnostics with auto-repair, `audit` for security tracking, `inspect` for deep process analysis, and `introspect` for kernel-level insights.
- **Real-Time Monitoring**: Live CPU, memory, disk, and network metrics with customizable intervals via the `monitor` command.
- **Deep System Visibility**: From process hierarchies and file descriptors to kernel modules and hardware details—complete transparency in one utility.
- **Built for Professionals**: Designed specifically for system administrators, engineers, and developers who demand precision and control.
- **Cross-Platform**: Seamless operation on Linux, macOS, and Windows with consistent command syntax.
- **Modern & Extensible**: Built with Meson for performance, with structured JSON output and advanced formatting options.

Squid Tool is the comprehensive solution for professionals who need power, visibility, and efficiency in system administration.

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

| **Command** | **Description** | **Flags** |
|-------------|-----------------|-----------|
| `process` | Display and manage system processes. | `-a`, `--all` (show all processes)<br>`-p`, `--pid <id>` (specific process)<br>`--name <pattern>` (filter by name)<br>`--sort <key>` (cpu/mem/pid/time)<br>`--tree` (process hierarchy)<br>`--kill <signal>` (send signal)<br>`--watch` (live refresh)<br>`--limit <n>` (limit results) |
| `monitor` | Real-time monitoring of system resources. | `--cpu`<br>`--memory`<br>`--disk`<br>`--process`<br>`--top <n>` (top consumers)<br>`-t`, `--interval <n>` (refresh interval)<br>`--watch` (continuous monitoring) |
| `health` / `doctor` | Perform system health diagnostics and performance checks. | `--quick` (basic health check)<br>`--full` (complete diagnostics)<br>`--cpu` (CPU health)<br>`--memory` (memory health)<br>`--disk` (disk health)<br>`--report <file>` (export report)<br>`--fix` (attempt automatic repair)<br>`--fson` (structured report output) |
| `inspect` | Deep inspection of system resources and processes. | `--process <pid>` (inspect process)<br>`--memory` (memory layout)<br>`--threads` (thread usage)<br>`--fds` (file descriptors)<br>`--limits` (resource limits)<br>`--fson` (structured output) |
| `introspect` | Low-level introspection of kernel, hardware, and runtime environment. | `--kernel` (kernel info)<br>`--modules` (loaded modules)<br>`--hardware` (hardware details)<br>`--boot` (boot metadata)<br>`--firmware` (firmware info)<br>`--fson` (structured output) |
| `this` | Display detailed information about the current host system. | `--os` (operating system)<br>`--arch` (architecture)<br>`--hostname` (system hostname)<br>`--uptime` (system uptime)<br>`--load` (load averages)<br>`--all` (complete system profile) |
| `service` | Manage system services. | `start <name>` (start service)<br>`stop <name>` (stop service)<br>`restart <name>` (restart service)<br>`reload <name>` (reload config)<br>`status <name>` (service status)<br>`--enable` (enable at boot)<br>`--disable` (disable at boot)<br>`--list` (list services)<br>`--watch` (monitor state) |
| `system` | Execute system-level control tasks similar to `systemctl`. | `--reboot` (reboot system)<br>`--shutdown` (shutdown system)<br>`--suspend` (suspend system)<br>`--hibernate` (hibernate system)<br>`--targets` (list system targets)<br>`--default-target <name>` (set default target) |
| `permit` | Inspect and modify system permissions and policies. | `--user <name>` (inspect user permissions)<br>`--group <name>` (inspect group permissions)<br>`--grant <mode>` (grant permissions)<br>`--revoke <mode>` (revoke permissions)<br>`--recursive` (apply recursively)<br>`--audit` (permission anomalies) |
| `notebook` | View and query system journal logs (similar to `journalctl`). | `--boot` (current boot logs)<br>`--service <name>` (service logs)<br>`--since <time>` (logs since time)<br>`--tail <n>` (last lines)<br>`--follow` (live logs) |
| `view` | Modern pager for viewing logs, streams, or files. | `--follow` (live follow)<br>`--search <pattern>` (search text)<br>`--lines <n>` (limit lines)<br>`--color` (syntax highlight) |
| `echo` | Output formatted text, encoded text, or spoken responses. | `--cipher <type>` (encode text)<br>`--speak` (text-to-speech)<br>`--repeat <n>` (repeat output)<br>`--format <mode>` (styled output) |
| `env` | Display and manage environment variables. | `--list` (list variables)<br>`--get <name>` (retrieve variable)<br>`--set <name=value>` (set variable)<br>`--unset <name>` (remove variable) |
| `calc` | Built-in calculator supporting arithmetic expressions. | `--expr <expression>` (evaluate expression)<br>`--base <n>` (number base)<br>`--scientific` (scientific mode)<br>`--precision <n>` (decimal precision) |
| `help` | Display help for commands. | `--examples` (usage examples)<br>`--man` (full manual) |

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
| `squid process -a --sort mem --limit 10` | List top 10 processes by memory usage. |
| `squid process --tree --user admin` | Display process hierarchy for admin user. |
| `squid monitor --cpu --memory --interval 5` | Real-time monitoring with 5-second refresh. |
| `squid health --full --report health.txt` | Run complete diagnostics and export report. |
| `squid inspect --process 1234 --threads` | Inspect process 1234 with thread details. |
| `squid introspect --kernel --modules` | Display kernel and loaded module information. |
| `squid this --all` | Display full system profile of the current host. |
| `squid notebook --service nginx --tail 50` | View last 50 nginx logs. |
| `squid service restart nginx` | Restart nginx service. |
| `squid env --list` | List environment variables. |
| `squid calc --expr "12*(5+3)"` | Evaluate mathematical expression. |
| `squid echo --cipher base64 "hello"` | Encode text using Base64. |
| `squid help --examples` | Display help with usage examples. |

---

## Command Comparison (Squid vs Traditional Tools)

Squid Tool consolidates many common **system administration utilities** into a **single consistent interface**.

| **Squid Command** | **Traditional Commands** | **Purpose** |
|---|---|---|
| `squid process` | `ps`, `top`, `pgrep`, `kill` | Display and manage processes with filtering and signals. |
| `squid monitor` | `top`, `htop`, `iotop` | Real-time system monitoring. |
| `squid health` | diagnostics scripts | System health diagnostics and performance analysis. |
| `squid inspect` | `lsof`, `/proc`, `pmap` | Deep inspection of processes and resources. |
| `squid introspect` | `uname`, `lsmod`, `lshw`, `dmidecode` | Kernel and hardware introspection. |
| `squid this` | `hostnamectl`, `uptime`, `uname` | Quick overview of the current system. |
| `squid service` | `systemctl`, `service` | Service lifecycle management. |
| `squid system` | `systemctl`, `shutdown`, `reboot` | System-level control operations. |
| `squid notebook` | `journalctl` | System log querying and filtering. |
| `squid permit` | `chmod`, `chown`, `setfacl` | Permission and policy management. |
| `squid view` | `less`, `tail -f` | Modern pager for logs and streams. |
| `squid env` | `env`, `printenv`, `export` | Environment variable management. |
| `squid calc` | `bc`, `expr` | Command-line calculator. |
| `squid echo` | `echo`, `say`, encoding tools | Advanced text output, encoding, and speech with FSON support. |

---

## **Contributing**

Interested in contributing? Please open pull requests or create issues on the [GitHub repository](https://github.com/fossillogic/squid).

## **Feedback and Support**

For issues, questions, or feedback, open an issue on the [GitHub repository](https://github.com/fossillogic/squid/issues).

## **License**

This project is licensed under the [Apache Public License](LICENSE).
