<p align="center">
    <img src=".github/logo.png" alt="Squid Tool Logo" width="620"/>
</p>

### A Command-Line Power Utility by **Fossil Logic**

**Squid** is the ultimate **admin and power-user CLI**, designed for system operators, DevOps, and security engineers. Squid allows you to **manage, monitor, secure, and audit your system**, with traceable actions, and comprehensive logging. Its nautilus mascot represents **flexibility, intelligence, and depth** in system operations.

---

## Command Palette

### Core System Operations

| **Command** | **Description** | **Common Flags** |
|-------------|-----------------|-----------------|
| `process` | Manage running processes. | `--pid <pid>` Target process<br>`--kill` Terminate process<br>`--tree` Show process hierarchy |
| `manage` | General system management. | `--user <username>` Specify user<br>`--group <group>` Specify group |
| `network` | Inspect and configure network. | `--interface <iface>` Specify network interface<br>`--status` Show network status<br>`--firewall` Manage rules |
| `secure` | Security operations. | `--audit` Run security audit<br>`--policy <policy>` Apply security policy |
| `notebook` | System journaling (journalctl based). | `--unit <unit>` Filter by systemd unit<br>`--follow` Tail logs in real-time |
| `service` | Manage system services. | `--start/stop/restart` Control service<br>`--enable/disable` Boot-time control |
| `storage` | Manage disks and filesystems. | `--mount <path>` Mount a disk<br>`--usage` Show usage stats |
| `audit` | System and security auditing. | `--report` Generate audit report<br>`--fson` Output FSON |
| `backup` | Backup and restore files or system state. | `--source <path>` Source path<br>`--dest <path>` Destination path<br>`--encrypt` Encrypt backup |
| `monitor` | Live system performance monitoring. | `--cpu` CPU stats<br>`--mem` Memory stats<br>`--interval <s>` Refresh interval |
| `logbook` | Aggregated log analysis. | `--filter <pattern>` Filter logs<br>`--tail` Tail logs<br>`--json` Output JSON |
| `system` | System overview and diagnostics. | `--info` Basic info<br>`--health` Health check |
| `help` | Display help and examples. | `--examples` Usage examples<br>`--man` Full manual |

---

### Global Flags (Available to All Commands)

| **Flag** | **Description** |
|-----------|-----------------|
| `--help` | Show help for command. |
| `--version` | Display Squid version. |
| `-v, --verbose` | Enable detailed output. |
| `-q, --quiet` | Suppress output. |
| `--dry-run` | Simulate without changing system. |
| `--color` | Colorize output. |

---

### Usage Examples

| **Example** | **Description** |
|-------------|-----------------|
| `squid process list` | List all running processes. |
| `squid process kill --pid 1234` | Terminate a specific process. |
| `squid network status` | Show network interface status. |
| `squid secure audit --fson` | Run a system security audit with structured output. |
| `squid notebook view --unit sshd` | View SSH daemon logs. |
| `squid service restart nginx` | Restart the nginx service. |
| `squid storage usage --disk /dev/sda` | Check disk usage of a specific disk. |
| `squid backup create --source /etc --dest /backups/etc.tar.gz --encrypt` | Backup system configuration files. |
| `squid monitor cpu --interval 5` | Monitor CPU usage every 5 seconds. |
| `squid logbook tail --filter ERROR` | Tail logs containing “ERROR”. |
| `squid system info` | Show general system information. |
| `squid help monitor` | Show usage examples for monitoring commands. |

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
    squid
    ```

## **Contributing**

Interested in contributing? Please open pull requests or create issues on the [GitHub repository](https://github.com/fossillogic/app-c).

## **Feedback and Support**

For issues, questions, or feedback, open an issue on the [GitHub repository](https://github.com/fossillogic/squid/issues).

## **License**

This project is licensed under the [Apache 2.0 License](LICENSE).
