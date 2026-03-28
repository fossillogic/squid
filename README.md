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

| Command | Description | Flags / Options |
|---------|-------------|----------------|
| `process` | Display and manage system processes. | `-a`, `--all` (show all processes)<br>`-p`, `--pid <id>` (specific process)<br>`--name <pattern>` (filter by name)<br>`--sort <key>` (cpu/mem/pid/time)<br>`--kill <pid>` (terminate process)<br>`--signal <sig>` (send signal) |
| `monitor` | Observe system resource usage over time. | `-c`, `--cpu`<br>`-m`, `--mem`<br>`-d`, `--disk`<br>`-n`, `--net`<br>`-t`, `--interval <s>`<br>`--top <n>` (show top N usage)<br>`--graph` (ASCII/graphical output) |
| `network` | Display network configuration and traffic. | `--interfaces`<br>`--connections`<br>`--routes`<br>`--stats`<br>`--monitor` (real-time traffic) |
| `health` | Check system health and diagnostics. | `--cpu` (CPU load)<br>`--mem` (memory usage)<br>`--disk` (disk health)<br>`--network`<br>`--report` (generate summary report) |
| `service` | Manage system services. | `--list` (show services)<br>`--status <name>`<br>`--start <name>`<br>`--stop <name>`<br>`--restart <name>`<br>`--enable <name>`<br>`--disable <name>` |
| `system` | System-level operations (like `systemctl`). | `--info` (system info)<br>`--uptime`<br>`--shutdown`<br>`--reboot`<br>`--update`<br>`--config <file>` |
| `inspect` | Examine objects, files, or runtime state. | `--file <path>`<br>`--dir <path>`<br>`--process <pid>`<br>`--service <name>`<br>`--json` (structured output) |
| `permit` | Adjust permissions for users, files, or services. | `--user <name>`<br>`--file <path>`<br>`--service <name>`<br>`--grant <perm>`<br>`--revoke <perm>` |
| `env` | Inspect or set environment variables. | `--list`<br>`--get <key>`<br>`--set <key>=<value>`<br>`--unset <key>`<br>`--export <file>` |
| `echo` | Print text or system information. | `--text <msg>`<br>`--env <key>`<br>`--json`<br>`--color` |
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
| `squid process -a --sort mem --top 10` | List top 10 processes by memory usage. |
| `squid process --tree --user admin` | Show process hierarchy for the admin user. |
| `squid monitor --cpu --mem --interval 5` | Monitor CPU and memory in real time, refreshing every 5 seconds. |
| `squid health --full --report health.txt` | Run full diagnostics and save the report to `health.txt`. |
| `squid inspect --process 1234 --threads` | Inspect process 1234, including thread details. |
| `squid introspect --kernel --modules` | Display kernel and loaded modules information. |
| `squid this --all` | Show a complete system profile of the current host. |
| `squid notebook --service nginx --tail 50` | View the last 50 log entries for the nginx service. |
| `squid service --restart nginx` | Restart the nginx service. |
| `squid env --list` | List all environment variables. |
| `squid calc --expr "12*(5+3)"` | Evaluate the mathematical expression. |
| `squid echo --cipher base64 "hello"` | Encode the text "hello" using Base64. |
| `squid help --examples` | Show help with usage examples. |

---

## Command Comparison (Squid vs Traditional Tools)

Squid Tool consolidates many common **system administration utilities** into a **single consistent interface**.

| **Squid Command**      | **Traditional Commands**                   | **Purpose**                                              |
|------------------------|--------------------------------------------|----------------------------------------------------------|
| `squid process`        | `ps`, `top`, `pgrep`, `kill`               | Display and manage processes with filtering and signals.  |
| `squid monitor`        | `top`, `htop`, `iotop`                     | Real-time system monitoring.                             |
| `squid health`         | Custom diagnostic scripts                   | System health diagnostics and performance analysis.       |
| `squid inspect`        | `lsof`, `/proc`, `pmap`                    | Deep inspection of processes and resources.               |
| `squid introspect`     | `uname`, `lsmod`, `lshw`, `dmidecode`      | Kernel and hardware introspection.                        |
| `squid this`           | `hostnamectl`, `uptime`, `uname`           | Quick overview of the current system.                     |
| `squid service`        | `systemctl`, `service`                     | Service lifecycle management.                             |
| `squid system`         | `systemctl`, `shutdown`, `reboot`          | System-level control operations.                          |
| `squid notebook`       | `journalctl`                               | System log querying and filtering.                        |
| `squid permit`         | `chmod`, `chown`, `setfacl`                | Permission and policy management.                         |
| `squid view`           | `less`, `tail -f`                          | Modern pager for logs and streams.                        |
| `squid env`            | `env`, `printenv`, `export`                | Environment variable management.                          |
| `squid calc`           | `bc`, `expr`                               | Command-line calculator.                                  |
| `squid echo`           | `echo`, encoding tools                     | Advanced text output and encoding.                        |

---

## **Contributing**

Interested in contributing? Please open pull requests or create issues on the [GitHub repository](https://github.com/fossillogic/squid).

## **Feedback and Support**

For issues, questions, or feedback, open an issue on the [GitHub repository](https://github.com/fossillogic/squid/issues).

## **License**

This project is licensed under the [Apache Public License](LICENSE).
