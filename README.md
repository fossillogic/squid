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
| `monitor` | Observe live system activity and resource usage. | `--cpu` (CPU usage)<br>`--mem` (memory usage)<br>`--disk` (disk usage)<br>`--net` (network activity)<br>`--interval <ms>` (refresh rate)<br>`--top` (top processes)<br>`--json` |
| `echo` | Print and transform text or system information. | `--text <msg>`<br>`--env <key>`<br>`--json`<br>`--color <style>` |
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
| `squid process -a --sort mem --top 10` | List all processes and show the top 10 by memory usage. Uses `-a`/`--all`, `--sort mem`, and `--top 10`. |
| `squid process --name nginx --sort cpu --top 5` | Show top 5 `nginx` processes by CPU usage. Uses `--name nginx`, `--sort cpu`, and `--top 5`. |
| `squid inspect --process 1234 --json` | Inspect process 1234 and output structured JSON. Uses `--process 1234` and `--json`. |
| `squid service --restart nginx` | Restart the `nginx` service. Uses `--restart nginx`. |
| `squid env --list` | List all environment variables. Uses `--list`. |
| `squid env --set DEBUG=1` | Set the environment variable `DEBUG` to `1`. Uses `--set DEBUG=1`. |
| `squid echo --text "hello world" --color` | Print "hello world" with colored output. Uses `--text` and `--color`. |
| `squid this --cpu --memory --network` | Show CPU, memory, and network details for the current system. Uses `--cpu`, `--memory`, and `--network`. |
| `squid help --examples` | Show help with usage examples. Uses `--examples`. |

---

## Command Comparison (Squid vs Traditional Tools)

Squid Tool consolidates many common **system administration utilities** into a **single consistent interface**.

| **Squid Command**      | **Traditional Commands**                   | **Purpose**                                              |
|------------------------|--------------------------------------------|----------------------------------------------------------|
| `squid process`        | `ps`, `top`, `pgrep`, `kill`               | Display and manage processes with filtering and signals.  |
| `squid inspect`        | `lsof`, `/proc`, `pmap`                    | Deep inspection of processes and resources.               |
| `squid this`           | `hostnamectl`, `uptime`, `uname`           | Quick overview of the current system.                     |
| `squid service`        | `systemctl`, `service`                     | Service lifecycle management.                             |
| `squid system`         | `systemctl`, `shutdown`, `reboot`          | System log querying and filtering.                        |
| `squid permit`         | `chmod`, `chown`, `setfacl`                | Permission and policy management.                         |
| `squid view`           | `less`, `tail -f`                          | Modern pager for logs and streams.                        |
| `squid env`            | `env`, `printenv`, `export`                | Environment variable management.                          |
| `squid calc`           | `bc`, `expr`                               | Command-line calculator.                                  |
| `squid echo`           | `echo`, encoding tools                     | Advanced text output and encoding.                        |
| `squid this`           | `hostnamectl`, `lscpu`, `free`, `lsblk`, `lshw`, `dmidecode`, `uptime`, `ifconfig`, `whoami`, `timedatectl` | Display a comprehensive system profile and lookup host properties. |

---

## **Contributing**

Interested in contributing? Please open pull requests or create issues on the [GitHub repository](https://github.com/fossillogic/squid).

## **Feedback and Support**

For issues, questions, or feedback, open an issue on the [GitHub repository](https://github.com/fossillogic/squid/issues).

## **License**

This project is licensed under the [Apache Public License](LICENSE).
