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
#include "fossil/code/commands.h"

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
                         bool json)
{
    int rc = 0;

    if (all || system) {
        fossil_sys_hostinfo_system_t sysinfo;
        if (fossil_sys_hostinfo_get_system(&sysinfo) == 0) {
            if (json) {
                fossil_io_printf("{\"system\":{\"os_name\":\"%s\",\"os_version\":\"%s\",\"kernel_version\":\"%s\",\"hostname\":\"%s\",\"username\":\"%s\",\"domain_name\":\"%s\",\"machine_type\":\"%s\",\"platform\":\"%s\"}}\n",
                    sysinfo.os_name, sysinfo.os_version, sysinfo.kernel_version, sysinfo.hostname,
                    sysinfo.username, sysinfo.domain_name, sysinfo.machine_type, sysinfo.platform);
            } else {
                fossil_io_printf("{bold,cyan}System:{reset}\n  OS: {green}%s %s{reset}\n  Kernel: {yellow}%s{reset}\n  Hostname: {magenta}%s{reset}\n  User: {blue}%s{reset}\n  Domain: {cyan}%s{reset}\n  Machine: {yellow}%s{reset}\n  Platform: {green}%s{reset}\n",
                    sysinfo.os_name, sysinfo.os_version, sysinfo.kernel_version, sysinfo.hostname,
                    sysinfo.username, sysinfo.domain_name, sysinfo.machine_type, sysinfo.platform);
            }
        } else {
            rc = 1;
            fossil_io_error("[%s] %s", "system.internal", fossil_io_what("system.internal"));
        }
    }

    if (all || arch) {
        fossil_sys_hostinfo_architecture_t archinfo;
        if (fossil_sys_hostinfo_get_architecture(&archinfo) == 0) {
            if (json) {
                fossil_io_printf("{\"architecture\":{\"architecture\":\"%s\",\"cpu\":\"%s\",\"cpu_cores\":\"%s\",\"cpu_threads\":\"%s\",\"cpu_frequency\":\"%s\",\"cpu_architecture\":\"%s\"}}\n",
                    archinfo.architecture, archinfo.cpu, archinfo.cpu_cores, archinfo.cpu_threads,
                    archinfo.cpu_frequency, archinfo.cpu_architecture);
            } else {
                fossil_io_printf("{bold,cyan}Architecture:{reset}\n  Arch: {green}%s{reset}\n  CPU: {yellow}%s{reset}\n  Cores: {magenta}%s{reset}\n  Threads: {blue}%s{reset}\n  Frequency: {cyan}%s{reset}\n  CPU Arch: {green}%s{reset}\n",
                    archinfo.architecture, archinfo.cpu, archinfo.cpu_cores, archinfo.cpu_threads,
                    archinfo.cpu_frequency, archinfo.cpu_architecture);
            }
        } else {
            rc = 1;
            fossil_io_error("[%s] %s", "system.internal", fossil_io_what("system.internal"));
        }
    }

    if (all || memory) {
        fossil_sys_hostinfo_memory_t meminfo;
        if (fossil_sys_hostinfo_get_memory(&meminfo) == 0) {
            if (json) {
                fossil_io_printf("{\"memory\":{\"total\":%llu,\"free\":%llu,\"used\":%llu,\"available\":%llu,\"swap_total\":%llu,\"swap_free\":%llu,\"swap_used\":%llu}}\n",
                    (unsigned long long)meminfo.total_memory, (unsigned long long)meminfo.free_memory,
                    (unsigned long long)meminfo.used_memory, (unsigned long long)meminfo.available_memory,
                    (unsigned long long)meminfo.total_swap, (unsigned long long)meminfo.free_swap,
                    (unsigned long long)meminfo.used_swap);
            } else {
                fossil_io_printf("{bold,cyan}Memory:{reset}\n  Total: {green}%llu{reset}\n  Free: {yellow}%llu{reset}\n  Used: {red}%llu{reset}\n  Available: {blue}%llu{reset}\n  Swap Total: {magenta}%llu{reset}\n  Swap Free: {cyan}%llu{reset}\n  Swap Used: {red}%llu{reset}\n",
                    (unsigned long long)meminfo.total_memory, (unsigned long long)meminfo.free_memory,
                    (unsigned long long)meminfo.used_memory, (unsigned long long)meminfo.available_memory,
                    (unsigned long long)meminfo.total_swap, (unsigned long long)meminfo.free_swap,
                    (unsigned long long)meminfo.used_swap);
            }
        } else {
            rc = 1;
            fossil_io_error("[%s] %s", "memory.alloc", fossil_io_what("memory.alloc"));
        }
    }

    if (all || endianness) {
        fossil_sys_hostinfo_endianness_t endianinfo;
        if (fossil_sys_hostinfo_get_endianness(&endianinfo) == 0) {
            if (json) {
                fossil_io_printf("{\"endianness\":\"%s\"}\n", endianinfo.is_little_endian ? "little" : "big");
            } else {
                fossil_io_printf("{bold,cyan}Endianness:{reset} {yellow}%s-endian{reset}\n", endianinfo.is_little_endian ? "Little" : "Big");
            }
        } else {
            rc = 1;
            fossil_io_error("[%s] %s", "encoding.endianness", fossil_io_what("encoding.endianness"));
        }
    }

    if (all || power) {
        fossil_sys_hostinfo_power_t powerinfo;
        if (fossil_sys_hostinfo_get_power(&powerinfo) == 0) {
            if (json) {
                fossil_io_printf("{\"power\":{\"on_ac\":%d,\"battery_present\":%d,\"charging\":%d,\"percent\":%d,\"seconds_left\":%d}}\n",
                    powerinfo.on_ac_power, powerinfo.battery_present, powerinfo.battery_charging,
                    powerinfo.battery_percentage, powerinfo.battery_seconds_left);
            } else {
                fossil_io_printf("{bold,cyan}Power:{reset}\n  AC Power: {green}%s{reset}\n  Battery Present: {yellow}%s{reset}\n  Charging: {blue}%s{reset}\n  Battery %%: {magenta}%d{reset}\n  Time Left: {cyan}%d sec{reset}\n",
                    powerinfo.on_ac_power ? "Yes" : "No",
                    powerinfo.battery_present ? "Yes" : "No",
                    powerinfo.battery_charging ? "Yes" : "No",
                    powerinfo.battery_percentage,
                    powerinfo.battery_seconds_left);
            }
        } else {
            rc = 1;
            fossil_io_error("[%s] %s", "resource.exhausted", fossil_io_what("resource.exhausted"));
        }
    }

    if (all || cpu) {
        fossil_sys_hostinfo_cpu_t cpuinfo;
        if (fossil_sys_hostinfo_get_cpu(&cpuinfo) == 0) {
            if (json) {
                fossil_io_printf("{\"cpu\":{\"model\":\"%s\",\"vendor\":\"%s\",\"cores\":%d,\"threads\":%d,\"frequency_ghz\":%.2f,\"features\":\"%s\"}}\n",
                    cpuinfo.model, cpuinfo.vendor, cpuinfo.cores, cpuinfo.threads, cpuinfo.frequency_ghz, cpuinfo.features);
            } else {
                fossil_io_printf("{bold,cyan}CPU:{reset}\n  Model: {green}%s{reset}\n  Vendor: {yellow}%s{reset}\n  Cores: {magenta}%d{reset}\n  Threads: {blue}%d{reset}\n  Frequency: {cyan}%.2f GHz{reset}\n  Features: {red}%s{reset}\n",
                    cpuinfo.model, cpuinfo.vendor, cpuinfo.cores, cpuinfo.threads, cpuinfo.frequency_ghz, cpuinfo.features);
            }
        } else {
            rc = 1;
            fossil_io_error("[%s] %s", "cpu.overflow", fossil_io_what("cpu.overflow"));
        }
    }

    if (all || gpu) {
        fossil_sys_hostinfo_gpu_t gpuinfo;
        if (fossil_sys_hostinfo_get_gpu(&gpuinfo) == 0) {
            if (json) {
                fossil_io_printf("{\"gpu\":{\"name\":\"%s\",\"vendor\":\"%s\",\"driver_version\":\"%s\",\"memory_total\":%llu,\"memory_free\":%llu}}\n",
                    gpuinfo.name, gpuinfo.vendor, gpuinfo.driver_version,
                    (unsigned long long)gpuinfo.memory_total, (unsigned long long)gpuinfo.memory_free);
            } else {
                fossil_io_printf("{bold,cyan}GPU:{reset}\n  Name: {green}%s{reset}\n  Vendor: {yellow}%s{reset}\n  Driver: {blue}%s{reset}\n  Memory Total: {magenta}%llu{reset}\n  Memory Free: {cyan}%llu{reset}\n",
                    gpuinfo.name, gpuinfo.vendor, gpuinfo.driver_version,
                    (unsigned long long)gpuinfo.memory_total, (unsigned long long)gpuinfo.memory_free);
            }
        } else {
            rc = 1;
            fossil_io_error("[%s] %s", "resource.exhausted", fossil_io_what("resource.exhausted"));
        }
    }

    if (all || storage) {
        fossil_sys_hostinfo_storage_t storageinfo;
        if (fossil_sys_hostinfo_get_storage(&storageinfo) == 0) {
            if (json) {
                fossil_io_printf("{\"storage\":{\"device\":\"%s\",\"mount\":\"%s\",\"total\":%llu,\"free\":%llu,\"used\":%llu,\"fs_type\":\"%s\"}}\n",
                    storageinfo.device_name, storageinfo.mount_point,
                    (unsigned long long)storageinfo.total_space, (unsigned long long)storageinfo.free_space,
                    (unsigned long long)storageinfo.used_space, storageinfo.filesystem_type);
            } else {
                fossil_io_printf("{bold,cyan}Storage:{reset}\n  Device: {green}%s{reset}\n  Mount: {yellow}%s{reset}\n  Total: {magenta}%llu{reset}\n  Free: {blue}%llu{reset}\n  Used: {red}%llu{reset}\n  FS: {cyan}%s{reset}\n",
                    storageinfo.device_name, storageinfo.mount_point,
                    (unsigned long long)storageinfo.total_space, (unsigned long long)storageinfo.free_space,
                    (unsigned long long)storageinfo.used_space, storageinfo.filesystem_type);
            }
        } else {
            rc = 1;
            fossil_io_error("[%s] %s", "fs.not_found", fossil_io_what("fs.not_found"));
        }
    }

    if (all || env) {
        fossil_sys_hostinfo_environment_t envinfo;
        if (fossil_sys_hostinfo_get_environment(&envinfo) == 0) {
            if (json) {
                fossil_io_printf("{\"environment\":{\"shell\":\"%s\",\"home\":\"%s\",\"lang\":\"%s\",\"path\":\"%s\",\"term\":\"%s\",\"user\":\"%s\"}}\n",
                    envinfo.shell, envinfo.home_dir, envinfo.lang, envinfo.path, envinfo._term, envinfo.user);
            } else {
                fossil_io_printf("{bold,cyan}Environment:{reset}\n  Shell: {green}%s{reset}\n  Home: {yellow}%s{reset}\n  Lang: {magenta}%s{reset}\n  Path: {blue}%s{reset}\n  Term: {cyan}%s{reset}\n  User: {red}%s{reset}\n",
                    envinfo.shell, envinfo.home_dir, envinfo.lang, envinfo.path, envinfo._term, envinfo.user);
            }
        } else {
            rc = 1;
            fossil_io_error("[%s] %s", "config.env", fossil_io_what("config.env"));
        }
    }

    if (all || virtualization) {
        fossil_sys_hostinfo_virtualization_t virtinfo;
        if (fossil_sys_hostinfo_get_virtualization(&virtinfo) == 0) {
            if (json) {
                fossil_io_printf("{\"virtualization\":{\"is_vm\":%d,\"is_container\":%d,\"hypervisor\":\"%s\",\"container_type\":\"%s\"}}\n",
                    virtinfo.is_virtual_machine, virtinfo.is_container, virtinfo.hypervisor, virtinfo.container_type);
            } else {
                fossil_io_printf("{bold,cyan}Virtualization:{reset}\n  VM: {green}%s{reset}\n  Container: {yellow}%s{reset}\n  Hypervisor: {magenta}%s{reset}\n  Container Type: {blue}%s{reset}\n",
                    virtinfo.is_virtual_machine ? "Yes" : "No",
                    virtinfo.is_container ? "Yes" : "No",
                    virtinfo.hypervisor, virtinfo.container_type);
            }
        } else {
            rc = 1;
            fossil_io_error("[%s] %s", "system.unsupported", fossil_io_what("system.unsupported"));
        }
    }

    if (all || uptime) {
        fossil_sys_hostinfo_uptime_t uptimeinfo;
        if (fossil_sys_hostinfo_get_uptime(&uptimeinfo) == 0) {
            if (json) {
                fossil_io_printf("{\"uptime\":{\"seconds\":%llu,\"boot_time\":%llu}}\n",
                    (unsigned long long)uptimeinfo.uptime_seconds, (unsigned long long)uptimeinfo.boot_time_epoch);
            } else {
                fossil_io_printf("{bold,cyan}Uptime:{reset}\n  Seconds: {green}%llu{reset}\n  Boot Time (epoch): {yellow}%llu{reset}\n",
                    (unsigned long long)uptimeinfo.uptime_seconds, (unsigned long long)uptimeinfo.boot_time_epoch);
            }
        } else {
            rc = 1;
            fossil_io_error("[%s] %s", "time.clock", fossil_io_what("time.clock"));
        }
    }

    if (all || network) {
        fossil_sys_hostinfo_network_t netinfo;
        if (fossil_sys_hostinfo_get_network(&netinfo) == 0) {
            if (json) {
                fossil_io_printf("{\"network\":{\"hostname\":\"%s\",\"ip\":\"%s\",\"mac\":\"%s\",\"interface\":\"%s\",\"up\":%d}}\n",
                    netinfo.hostname, netinfo.primary_ip, netinfo.mac_address, netinfo.interface_name, netinfo.is_up);
            } else {
                fossil_io_printf("{bold,cyan}Network:{reset}\n  Hostname: {green}%s{reset}\n  IP: {yellow}%s{reset}\n  MAC: {magenta}%s{reset}\n  Interface: {blue}%s{reset}\n  Up: {cyan}%s{reset}\n",
                    netinfo.hostname, netinfo.primary_ip, netinfo.mac_address, netinfo.interface_name,
                    netinfo.is_up ? "Yes" : "No");
            }
        } else {
            rc = 1;
            fossil_io_error("[%s] %s", "network.unreachable", fossil_io_what("network.unreachable"));
        }
    }

    if (all || process) {
        fossil_sys_hostinfo_process_t procinfo;
        if (fossil_sys_hostinfo_get_process(&procinfo) == 0) {
            if (json) {
                fossil_io_printf("{\"process\":{\"pid\":%d,\"ppid\":%d,\"exe\":\"%s\",\"cwd\":\"%s\",\"name\":\"%s\",\"elevated\":%d}}\n",
                    procinfo.pid, procinfo.ppid, procinfo.executable_path, procinfo.current_working_dir,
                    procinfo.process_name, procinfo.is_elevated);
            } else {
                fossil_io_printf("{bold,cyan}Process:{reset}\n  PID: {green}%d{reset}\n  PPID: {yellow}%d{reset}\n  Executable: {magenta}%s{reset}\n  CWD: {blue}%s{reset}\n  Name: {cyan}%s{reset}\n  Elevated: {red}%s{reset}\n",
                    procinfo.pid, procinfo.ppid, procinfo.executable_path, procinfo.current_working_dir,
                    procinfo.process_name, procinfo.is_elevated ? "Yes" : "No");
            }
        } else {
            rc = 1;
            fossil_io_error("[%s] %s", "process.spawn", fossil_io_what("process.spawn"));
        }
    }

    if (all || limits) {
        fossil_sys_hostinfo_limits_t liminfo;
        if (fossil_sys_hostinfo_get_limits(&liminfo) == 0) {
            if (json) {
                fossil_io_printf("{\"limits\":{\"max_open_files\":%llu,\"max_processes\":%llu,\"page_size\":%llu}}\n",
                    (unsigned long long)liminfo.max_open_files, (unsigned long long)liminfo.max_processes, (unsigned long long)liminfo.page_size);
            } else {
                fossil_io_printf("{bold,cyan}Limits:{reset}\n  Max Open Files: {green}%llu{reset}\n  Max Processes: {yellow}%llu{reset}\n  Page Size: {magenta}%llu{reset}\n",
                    (unsigned long long)liminfo.max_open_files, (unsigned long long)liminfo.max_processes, (unsigned long long)liminfo.page_size);
            }
        } else {
            rc = 1;
            fossil_io_error("[%s] %s", "resource.limit", fossil_io_what("resource.limit"));
        }
    }

    if (all || time) {
        fossil_sys_hostinfo_time_t timeinfo;
        if (fossil_sys_hostinfo_get_time(&timeinfo) == 0) {
            if (json) {
                fossil_io_printf("{\"time\":{\"timezone\":\"%s\",\"utc_offset\":%d,\"locale\":\"%s\"}}\n",
                    timeinfo.timezone, timeinfo.utc_offset_seconds, timeinfo.locale);
            } else {
                fossil_io_printf("{bold,cyan}Time:{reset}\n  Timezone: {green}%s{reset}\n  UTC Offset: {yellow}%d{reset}\n  Locale: {magenta}%s{reset}\n",
                    timeinfo.timezone, timeinfo.utc_offset_seconds, timeinfo.locale);
            }
        } else {
            rc = 1;
            fossil_io_error("[%s] %s", "time.clock", fossil_io_what("time.clock"));
        }
    }

    if (all || hardware) {
        fossil_sys_hostinfo_hardware_t hwinfo;
        if (fossil_sys_hostinfo_get_hardware(&hwinfo) == 0) {
            if (json) {
                fossil_io_printf("{\"hardware\":{\"manufacturer\":\"%s\",\"product\":\"%s\",\"serial\":\"%s\",\"bios\":\"%s\"}}\n",
                    hwinfo.manufacturer, hwinfo.product_name, hwinfo.serial_number, hwinfo.bios_version);
            } else {
                fossil_io_printf("{bold,cyan}Hardware:{reset}\n  Manufacturer: {green}%s{reset}\n  Product: {yellow}%s{reset}\n  Serial: {magenta}%s{reset}\n  BIOS: {blue}%s{reset}\n",
                    hwinfo.manufacturer, hwinfo.product_name, hwinfo.serial_number, hwinfo.bios_version);
            }
        } else {
            rc = 1;
            fossil_io_error("[%s] %s", "hardware.unsupported", fossil_io_what("hardware.unsupported"));
        }
    }

    if (all || display) {
        fossil_sys_hostinfo_display_t dispinfo;
        if (fossil_sys_hostinfo_get_display(&dispinfo) == 0) {
            if (json) {
                fossil_io_printf("{\"display\":{\"count\":%d,\"width\":%d,\"height\":%d,\"refresh\":%d}}\n",
                    dispinfo.display_count, dispinfo.primary_width, dispinfo.primary_height, dispinfo.primary_refresh_rate);
            } else {
                fossil_io_printf("{bold,cyan}Display:{reset}\n  Count: {green}%d{reset}\n  Primary: {yellow}%dx%d{reset} @ {magenta}%dHz{reset}\n",
                    dispinfo.display_count, dispinfo.primary_width, dispinfo.primary_height, dispinfo.primary_refresh_rate);
            }
        } else {
            rc = 1;
            fossil_io_error("[%s] %s", "ui.render", fossil_io_what("ui.render"));
        }
    }

    return rc;
}
