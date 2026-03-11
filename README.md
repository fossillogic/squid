<p align="center">
    <img src=".github/logo.png" alt="Squid Tool Logo" width="620"/>
</p>

### A System Monitoring Power Utility by **Fossil Logic**

Squid Tool is the ultimate **all-in-one system administration and monitoring utility** for admins, developers, and system engineers. It consolidates essential process management, system diagnostics, and real-time monitoring into a single command-line interface—eliminating tool fragmentation. Unique commands like `health` for system diagnostics, `audit` for security event tracking, and `inspect` for deep resource analysis provide capabilities rarely found in traditional utilities, delivering the precision and control professionals demand.

---

## Features

- **Process management and monitoring** — `process`, `inspect`, `watch` with filtering, sorting, and signaling
- **System information and diagnostics** — CPU, memory, disk, network, kernel, and hardware details
- **Real-time resource monitoring** — Live CPU, memory, disk, and network monitoring with customizable intervals
- **System health diagnostics** — Quick and comprehensive health checks with detailed reporting
- **Security and audit logging** — Track logins, services, processes, and file access events
- **Cross-platform support** — Seamless operation on Linux, macOS, and Windows
- **Deep resource inspection** — Process details, memory layout, threads, file descriptors, and limits
- **Permission management** — Inspect and modify user/group permissions with anomaly detection
- **Service management** — Start, stop, restart, reload, and monitor system services
- **Network analysis** — Interfaces, connections, ports, routes, and traffic statistics

## **Why Choose Squid Tool?**

Unlike traditional CLI utilities that require juggling multiple tools, Squid consolidates essential system administration and monitoring into a single, intuitive command-line interface. Here's what sets it apart:

- **All-in-One Solution**: Eliminate tool switching. Process management, system monitoring, diagnostics, and auditing all in one place.
- **Unique Advanced Features**: Commands like `health` for comprehensive diagnostics, `audit` for security tracking, and `inspect` for deep analysis go beyond standard utilities.
- **Admin-Friendly**: Built specifically for system administrators and engineers who need power and visibility without complexity.
- **Cross-Platform**: Works seamlessly across Linux, macOS, and Windows.
- **Real-Time Insights**: Live monitoring with customizable refresh intervals and structured output formats.
- **Modern Architecture**: Built with Meson and designed for performance and extensibility.

Squid Tool is the unified solution for professionals who demand more from their system administration utilities.

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
| `process` | Display and manage system processes. | `-a`, `--all` (show all processes)<br>`-u`, `--user <name>` (filter by user)<br>`-p`, `--pid <id>` (specific process)<br>`--name <pattern>` (filter by name)<br>`--sort <key>` (cpu/mem/pid/time)<br>`--tree` (process hierarchy)<br>`--kill <signal>` (send signal)<br>`--watch` (live refresh)<br>`--limit <n>` (limit results) |
| `monitor` | Real-time monitoring of system resources. | `--cpu`<br>`--memory`<br>`--disk`<br>`--network`<br>`--process`<br>`--top <n>` (top consumers)<br>`-t`, `--interval <n>` (refresh interval)<br>`--watch` (continuous monitoring) |
| `health` / `doctor` | Perform system health diagnostics and performance checks. | `--quick` (basic health check)<br>`--full` (complete diagnostics)<br>`--cpu` (CPU health)<br>`--memory` (memory health)<br>`--disk` (disk health)<br>`--network` (network health)<br>`--report <file>` (export report)<br>`--fix` (attempt automatic repair)<br>`--json` (structured report output) |
| `inspect` | Deep inspection of system resources and processes. | `--process <pid>` (inspect process)<br>`--memory` (memory layout)<br>`--threads` (thread usage)<br>`--fds` (file descriptors)<br>`--network` (network sockets)<br>`--limits` (resource limits)<br>`--json` (structured output) |
| `introspect` | Low-level introspection of kernel, hardware, and runtime environment. | `--kernel` (kernel info)<br>`--modules` (loaded modules)<br>`--hardware` (hardware details)<br>`--boot` (boot metadata)<br>`--firmware` (firmware info)<br>`--fson` (structured output) |
| `this` | Display detailed information about the current host system. | `--os` (operating system)<br>`--arch` (architecture)<br>`--hostname` (system hostname)<br>`--uptime` (system uptime)<br>`--load` (load averages)<br>`--all` (complete system profile) |
| `network` | Display and analyze network information and perform diagnostics. | `--interfaces` (network interfaces)<br>`--connections` (active connections)<br>`--ports` (open ports)<br>`--routes` (routing table)<br>`--stats` (traffic statistics)<br>`--ping <host>` (ping host)<br>`--trace <host>` (traceroute)<br>`--dns <host>` (DNS lookup)<br>`--watch` (live network activity) |
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
| `squid network --ping google.com` | Ping a host from Squid. |
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
| `squid monitor` | `top`, `htop`, `iotop`, `nethogs` | Real-time system monitoring. |
| `squid health` | diagnostics scripts | System health diagnostics and performance analysis. |
| `squid inspect` | `lsof`, `/proc`, `pmap` | Deep inspection of processes and resources. |
| `squid introspect` | `uname`, `lsmod`, `lshw`, `dmidecode` | Kernel and hardware introspection. |
| `squid this` | `hostnamectl`, `uptime`, `uname` | Quick overview of the current system. |
| `squid service` | `systemctl`, `service` | Service lifecycle management. |
| `squid system` | `systemctl`, `shutdown`, `reboot` | System-level control operations. |
| `squid notebook` | `journalctl` | System log querying and filtering. |
| `squid network` | `ifconfig`, `ss`, `netstat`, `ping`, `traceroute` | Network diagnostics and analysis. |
| `squid permit` | `chmod`, `chown`, `setfacl` | Permission and policy management. |
| `squid view` | `less`, `tail -f` | Modern pager for logs and streams. |
| `squid env` | `env`, `printenv`, `export` | Environment variable management. |
| `squid calc` | `bc`, `expr` | Command-line calculator. |
| `squid echo` | `echo`, `say`, encoding tools | Advanced text output, encoding, and speech. |

---

## **Contributing**

Interested in contributing? Please open pull requests or create issues on the [GitHub repository](https://github.com/fossillogic/squid).

## **Feedback and Support**

For issues, questions, or feedback, open an issue on the [GitHub repository](https://github.com/fossillogic/squid/issues).

## **License**

This project is licensed under the [Apache Public License](LICENSE).
