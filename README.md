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

### Core System Commands

| **Command** | **Description** | **Flags** |
|-------------|-----------------|-----------|
| `process` | Display and manage system processes. | `-a`, `--all` (show all processes)<br>`-u`, `--user <name>` (filter by user)<br>`-p`, `--pid <id>` (specific process)<br>`--name <pattern>` (filter by name)<br>`--sort <key>` (cpu/mem/pid/time)<br>`--tree` (process hierarchy)<br>`--kill <signal>` (send signal to process)<br>`--watch` (live refresh)<br>`--limit <n>` (limit results) |
| `system` | Display system configuration and environment information. | `--cpu` (CPU info)<br>`--memory` (memory info)<br>`--kernel` (kernel version)<br>`--os` (operating system)<br>`--hardware` (hardware details)<br>`--uptime` (system uptime)<br>`--load` (load averages)<br>`--env` (environment variables)<br>`--json` (structured output) |
| `monitor` | Real-time monitoring of system resources. | `--cpu`<br>`--memory`<br>`--disk`<br>`--network`<br>`--process`<br>`--top <n>` (top resource consumers)<br>`-t`, `--interval <n>` (refresh interval)<br>`--watch` (continuous monitoring) |
| `health` | Perform system health diagnostics. | `--quick` (basic health check)<br>`--full` (complete diagnostics)<br>`--cpu` (CPU health)<br>`--memory` (memory health)<br>`--disk` (disk health)<br>`--network` (network health)<br>`--report <file>` (export report)<br>`--json` (structured report output) |
| `audit` | Audit system activity and security events. | `--logins` (login history)<br>`--services` (service activity)<br>`--process` (process activity)<br>`--files` (file access events)<br>`--since <time>` (time filter)<br>`--user <name>` (filter by user)<br>`--export <file>` (write audit report) |
| `inspect` | Deep inspection of system resources. | `--process <pid>` (inspect process)<br>`--memory` (memory layout)<br>`--threads` (thread usage)<br>`--fds` (file descriptors)<br>`--network` (network sockets)<br>`--limits` (resource limits)<br>`--json` (structured output) |
| `perm` | Inspect and modify system permissions. | `--user <name>` (inspect user permissions)<br>`--group <name>` (inspect group permissions)<br>`--set <mode>` (set permission mode)<br>`--recursive` (apply recursively)<br>`--audit` (show permission anomalies) |
| `service` | Manage system services. | `start <name>` (start service)<br>`stop <name>` (stop service)<br>`restart <name>` (restart service)<br>`reload <name>` (reload service config)<br>`status <name>` (service status)<br>`--enable` (enable at boot)<br>`--disable` (disable at boot)<br>`--watch` (monitor service state) |
| `network` | Display and analyze network information. | `--interfaces` (network interfaces)<br>`--connections` (active connections)<br>`--ports` (open ports)<br>`--routes` (routing table)<br>`--stats` (traffic statistics)<br>`--tcp` (TCP connections)<br>`--udp` (UDP connections)<br>`--watch` (live network activity) |
| `help` | Display help for commands. | `--examples` (usage examples)<br>`--man` (full manual) |

---

### Global Flags (Available to All Commands)

| **Flag** | **Description** |
|-----------|-----------------|
| `--help` | Show command help. |
| `--version` | Display Shark Tool version. |
| `-v, --verbose` | Enable detailed output. |
| `-q, --quiet` | Suppress standard output. |
| `--dry-run` | Simulate actions without changes. |
| `--color` | Colorize output where applicable. |
| `--time` | Display timestamps in output. |

---

### Usage Examples

| **Example** | **Description** |
|---|---|
| `squid process -a --sort mem --limit 10` | List top 10 processes by memory usage. |
| `squid process --tree --user admin` | Display process hierarchy for admin user. |
| `squid system --cpu --memory --json` | Show CPU and memory info in JSON format. |
| `squid monitor --cpu --memory --interval 5` | Real-time monitoring with 5-second refresh. |
| `squid health --full --report health.txt` | Run complete diagnostics and export report. |
| `squid audit --logins --since "2024-01-01"` | View login history from specific date. |
| `squid inspect --process 1234 --threads` | Inspect process 1234 with thread details. |
| `squid perm --user john --audit` | Check john's permissions and anomalies. |
| `squid service status nginx` | Display nginx service status. |
| `squid service restart apache2 --watch` | Restart Apache and monitor state changes. |
| `squid network --connections --watch` | Monitor active network connections live. |
| `squid network --ports --stats` | Show open ports with traffic statistics. |
| `squid help --examples` | Display command help with usage examples. |

---

### Command Comparison (Squid vs Traditional Tools)

Squid Tool consolidates many common command-line utilities into a **single consistent interface**.  
Below is a comparison between **Squid commands** and their traditional equivalents.

| **Squid Command** | **Traditional Commands** | **Purpose** |
|---|---|---|
| `squid process` | `ps`, `top`, `pgrep`, `kill` | Display, filter, sort, and manage processes with live monitoring. |
| `squid system` | `uname`, `lsb_release`, `lscpu`, `free` | Comprehensive system information in unified format. |
| `squid monitor` | `top`, `htop`, `iotop`, `nethogs` | Real-time monitoring of CPU, memory, disk, and network. |
| `squid health` | `systemctl`, diagnostics scripts | System health checks and diagnostic reports. |
| `squid audit` | `journalctl`, `ausearch`, `last`, `ac` | Security and activity auditing with event tracking. |
| `squid inspect` | `proc`, `lsof`, `nm`, `objdump` | Deep inspection of processes and system resources. |
| `squid perm` | `chmod`, `chown`, `getfacl`, `setfacl` | Permission inspection and modification. |
| `squid service` | `systemctl`, `service`, `chkconfig` | Service lifecycle management. |
| `squid network` | `ifconfig`, `netstat`, `ss`, `route`, `ping` | Network configuration and connection analysis. |

---

## **Contributing**

Interested in contributing? Please open pull requests or create issues on the [GitHub repository](https://github.com/fossillogic/squid).

## **Feedback and Support**

For issues, questions, or feedback, open an issue on the [GitHub repository](https://github.com/fossillogic/squid/issues).

## **License**

This project is licensed under the [Apache Public License](LICENSE).
