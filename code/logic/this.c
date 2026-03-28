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
int fossil_squid_profile(bool system,
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
                printf("{\"system\":{\"os_name\":\"%s\",\"os_version\":\"%s\",\"kernel_version\":\"%s\",\"hostname\":\"%s\",\"username\":\"%s\",\"domain_name\":\"%s\",\"machine_type\":\"%s\",\"platform\":\"%s\"}}\n",
                    sysinfo.os_name, sysinfo.os_version, sysinfo.kernel_version, sysinfo.hostname,
                    sysinfo.username, sysinfo.domain_name, sysinfo.machine_type, sysinfo.platform);
            } else {
                printf("System:\n  OS: %s %s\n  Kernel: %s\n  Hostname: %s\n  User: %s\n  Domain: %s\n  Machine: %s\n  Platform: %s\n",
                    sysinfo.os_name, sysinfo.os_version, sysinfo.kernel_version, sysinfo.hostname,
                    sysinfo.username, sysinfo.domain_name, sysinfo.machine_type, sysinfo.platform);
            }
        } else {
            rc = 1;
        }
    }

    if (all || arch) {
        fossil_sys_hostinfo_architecture_t archinfo;
        if (fossil_sys_hostinfo_get_architecture(&archinfo) == 0) {
            if (json) {
                printf("{\"architecture\":{\"architecture\":\"%s\",\"cpu\":\"%s\",\"cpu_cores\":\"%s\",\"cpu_threads\":\"%s\",\"cpu_frequency\":\"%s\",\"cpu_architecture\":\"%s\"}}\n",
                    archinfo.architecture, archinfo.cpu, archinfo.cpu_cores, archinfo.cpu_threads,
                    archinfo.cpu_frequency, archinfo.cpu_architecture);
            } else {
                printf("Architecture:\n  Arch: %s\n  CPU: %s\n  Cores: %s\n  Threads: %s\n  Frequency: %s\n  CPU Arch: %s\n",
                    archinfo.architecture, archinfo.cpu, archinfo.cpu_cores, archinfo.cpu_threads,
                    archinfo.cpu_frequency, archinfo.cpu_architecture);
            }
        } else {
            rc = 1;
        }
    }

    if (all || memory) {
        fossil_sys_hostinfo_memory_t meminfo;
        if (fossil_sys_hostinfo_get_memory(&meminfo) == 0) {
            if (json) {
                printf("{\"memory\":{\"total\":%llu,\"free\":%llu,\"used\":%llu,\"available\":%llu,\"swap_total\":%llu,\"swap_free\":%llu,\"swap_used\":%llu}}\n",
                    (unsigned long long)meminfo.total_memory, (unsigned long long)meminfo.free_memory,
                    (unsigned long long)meminfo.used_memory, (unsigned long long)meminfo.available_memory,
                    (unsigned long long)meminfo.total_swap, (unsigned long long)meminfo.free_swap,
                    (unsigned long long)meminfo.used_swap);
            } else {
                printf("Memory:\n  Total: %llu\n  Free: %llu\n  Used: %llu\n  Available: %llu\n  Swap Total: %llu\n  Swap Free: %llu\n  Swap Used: %llu\n",
                    (unsigned long long)meminfo.total_memory, (unsigned long long)meminfo.free_memory,
                    (unsigned long long)meminfo.used_memory, (unsigned long long)meminfo.available_memory,
                    (unsigned long long)meminfo.total_swap, (unsigned long long)meminfo.free_swap,
                    (unsigned long long)meminfo.used_swap);
            }
        } else {
            rc = 1;
        }
    }

    if (all || endianness) {
        fossil_sys_hostinfo_endianness_t endianinfo;
        if (fossil_sys_hostinfo_get_endianness(&endianinfo) == 0) {
            if (json) {
                printf("{\"endianness\":\"%s\"}\n", endianinfo.is_little_endian ? "little" : "big");
            } else {
                printf("Endianness: %s-endian\n", endianinfo.is_little_endian ? "Little" : "Big");
            }
        } else {
            rc = 1;
        }
    }

    if (all || power) {
        fossil_sys_hostinfo_power_t powerinfo;
        if (fossil_sys_hostinfo_get_power(&powerinfo) == 0) {
            if (json) {
                printf("{\"power\":{\"on_ac\":%d,\"battery_present\":%d,\"charging\":%d,\"percent\":%d,\"seconds_left\":%d}}\n",
                    powerinfo.on_ac_power, powerinfo.battery_present, powerinfo.battery_charging,
                    powerinfo.battery_percentage, powerinfo.battery_seconds_left);
            } else {
                printf("Power:\n  AC Power: %s\n  Battery Present: %s\n  Charging: %s\n  Battery %%: %d\n  Time Left: %d sec\n",
                    powerinfo.on_ac_power ? "Yes" : "No",
                    powerinfo.battery_present ? "Yes" : "No",
                    powerinfo.battery_charging ? "Yes" : "No",
                    powerinfo.battery_percentage,
                    powerinfo.battery_seconds_left);
            }
        } else {
            rc = 1;
        }
    }

    if (all || cpu) {
        fossil_sys_hostinfo_cpu_t cpuinfo;
        if (fossil_sys_hostinfo_get_cpu(&cpuinfo) == 0) {
            if (json) {
                printf("{\"cpu\":{\"model\":\"%s\",\"vendor\":\"%s\",\"cores\":%d,\"threads\":%d,\"frequency_ghz\":%.2f,\"features\":\"%s\"}}\n",
                    cpuinfo.model, cpuinfo.vendor, cpuinfo.cores, cpuinfo.threads, cpuinfo.frequency_ghz, cpuinfo.features);
            } else {
                printf("CPU:\n  Model: %s\n  Vendor: %s\n  Cores: %d\n  Threads: %d\n  Frequency: %.2f GHz\n  Features: %s\n",
                    cpuinfo.model, cpuinfo.vendor, cpuinfo.cores, cpuinfo.threads, cpuinfo.frequency_ghz, cpuinfo.features);
            }
        } else {
            rc = 1;
        }
    }

    if (all || gpu) {
        fossil_sys_hostinfo_gpu_t gpuinfo;
        if (fossil_sys_hostinfo_get_gpu(&gpuinfo) == 0) {
            if (json) {
                printf("{\"gpu\":{\"name\":\"%s\",\"vendor\":\"%s\",\"driver_version\":\"%s\",\"memory_total\":%llu,\"memory_free\":%llu}}\n",
                    gpuinfo.name, gpuinfo.vendor, gpuinfo.driver_version,
                    (unsigned long long)gpuinfo.memory_total, (unsigned long long)gpuinfo.memory_free);
            } else {
                printf("GPU:\n  Name: %s\n  Vendor: %s\n  Driver: %s\n  Memory Total: %llu\n  Memory Free: %llu\n",
                    gpuinfo.name, gpuinfo.vendor, gpuinfo.driver_version,
                    (unsigned long long)gpuinfo.memory_total, (unsigned long long)gpuinfo.memory_free);
            }
        } else {
            rc = 1;
        }
    }

    if (all || storage) {
        fossil_sys_hostinfo_storage_t storageinfo;
        if (fossil_sys_hostinfo_get_storage(&storageinfo) == 0) {
            if (json) {
                printf("{\"storage\":{\"device\":\"%s\",\"mount\":\"%s\",\"total\":%llu,\"free\":%llu,\"used\":%llu,\"fs_type\":\"%s\"}}\n",
                    storageinfo.device_name, storageinfo.mount_point,
                    (unsigned long long)storageinfo.total_space, (unsigned long long)storageinfo.free_space,
                    (unsigned long long)storageinfo.used_space, storageinfo.filesystem_type);
            } else {
                printf("Storage:\n  Device: %s\n  Mount: %s\n  Total: %llu\n  Free: %llu\n  Used: %llu\n  FS: %s\n",
                    storageinfo.device_name, storageinfo.mount_point,
                    (unsigned long long)storageinfo.total_space, (unsigned long long)storageinfo.free_space,
                    (unsigned long long)storageinfo.used_space, storageinfo.filesystem_type);
            }
        } else {
            rc = 1;
        }
    }

    if (all || env) {
        fossil_sys_hostinfo_environment_t envinfo;
        if (fossil_sys_hostinfo_get_environment(&envinfo) == 0) {
            if (json) {
                printf("{\"environment\":{\"shell\":\"%s\",\"home\":\"%s\",\"lang\":\"%s\",\"path\":\"%s\",\"term\":\"%s\",\"user\":\"%s\"}}\n",
                    envinfo.shell, envinfo.home_dir, envinfo.lang, envinfo.path, envinfo._term, envinfo.user);
            } else {
                printf("Environment:\n  Shell: %s\n  Home: %s\n  Lang: %s\n  Path: %s\n  Term: %s\n  User: %s\n",
                    envinfo.shell, envinfo.home_dir, envinfo.lang, envinfo.path, envinfo._term, envinfo.user);
            }
        } else {
            rc = 1;
        }
    }

    if (all || virtualization) {
        fossil_sys_hostinfo_virtualization_t virtinfo;
        if (fossil_sys_hostinfo_get_virtualization(&virtinfo) == 0) {
            if (json) {
                printf("{\"virtualization\":{\"is_vm\":%d,\"is_container\":%d,\"hypervisor\":\"%s\",\"container_type\":\"%s\"}}\n",
                    virtinfo.is_virtual_machine, virtinfo.is_container, virtinfo.hypervisor, virtinfo.container_type);
            } else {
                printf("Virtualization:\n  VM: %s\n  Container: %s\n  Hypervisor: %s\n  Container Type: %s\n",
                    virtinfo.is_virtual_machine ? "Yes" : "No",
                    virtinfo.is_container ? "Yes" : "No",
                    virtinfo.hypervisor, virtinfo.container_type);
            }
        } else {
            rc = 1;
        }
    }

    if (all || uptime) {
        fossil_sys_hostinfo_uptime_t uptimeinfo;
        if (fossil_sys_hostinfo_get_uptime(&uptimeinfo) == 0) {
            if (json) {
                printf("{\"uptime\":{\"seconds\":%llu,\"boot_time\":%llu}}\n",
                    (unsigned long long)uptimeinfo.uptime_seconds, (unsigned long long)uptimeinfo.boot_time_epoch);
            } else {
                printf("Uptime:\n  Seconds: %llu\n  Boot Time (epoch): %llu\n",
                    (unsigned long long)uptimeinfo.uptime_seconds, (unsigned long long)uptimeinfo.boot_time_epoch);
            }
        } else {
            rc = 1;
        }
    }

    if (all || network) {
        fossil_sys_hostinfo_network_t netinfo;
        if (fossil_sys_hostinfo_get_network(&netinfo) == 0) {
            if (json) {
                printf("{\"network\":{\"hostname\":\"%s\",\"ip\":\"%s\",\"mac\":\"%s\",\"interface\":\"%s\",\"up\":%d}}\n",
                    netinfo.hostname, netinfo.primary_ip, netinfo.mac_address, netinfo.interface_name, netinfo.is_up);
            } else {
                printf("Network:\n  Hostname: %s\n  IP: %s\n  MAC: %s\n  Interface: %s\n  Up: %s\n",
                    netinfo.hostname, netinfo.primary_ip, netinfo.mac_address, netinfo.interface_name,
                    netinfo.is_up ? "Yes" : "No");
            }
        } else {
            rc = 1;
        }
    }

    if (all || process) {
        fossil_sys_hostinfo_process_t procinfo;
        if (fossil_sys_hostinfo_get_process(&procinfo) == 0) {
            if (json) {
                printf("{\"process\":{\"pid\":%d,\"ppid\":%d,\"exe\":\"%s\",\"cwd\":\"%s\",\"name\":\"%s\",\"elevated\":%d}}\n",
                    procinfo.pid, procinfo.ppid, procinfo.executable_path, procinfo.current_working_dir,
                    procinfo.process_name, procinfo.is_elevated);
            } else {
                printf("Process:\n  PID: %d\n  PPID: %d\n  Executable: %s\n  CWD: %s\n  Name: %s\n  Elevated: %s\n",
                    procinfo.pid, procinfo.ppid, procinfo.executable_path, procinfo.current_working_dir,
                    procinfo.process_name, procinfo.is_elevated ? "Yes" : "No");
            }
        } else {
            rc = 1;
        }
    }

    if (all || limits) {
        fossil_sys_hostinfo_limits_t liminfo;
        if (fossil_sys_hostinfo_get_limits(&liminfo) == 0) {
            if (json) {
                printf("{\"limits\":{\"max_open_files\":%llu,\"max_processes\":%llu,\"page_size\":%llu}}\n",
                    (unsigned long long)liminfo.max_open_files, (unsigned long long)liminfo.max_processes, (unsigned long long)liminfo.page_size);
            } else {
                printf("Limits:\n  Max Open Files: %llu\n  Max Processes: %llu\n  Page Size: %llu\n",
                    (unsigned long long)liminfo.max_open_files, (unsigned long long)liminfo.max_processes, (unsigned long long)liminfo.page_size);
            }
        } else {
            rc = 1;
        }
    }

    if (all || time) {
        fossil_sys_hostinfo_time_t timeinfo;
        if (fossil_sys_hostinfo_get_time(&timeinfo) == 0) {
            if (json) {
                printf("{\"time\":{\"timezone\":\"%s\",\"utc_offset\":%d,\"locale\":\"%s\"}}\n",
                    timeinfo.timezone, timeinfo.utc_offset_seconds, timeinfo.locale);
            } else {
                printf("Time:\n  Timezone: %s\n  UTC Offset: %d\n  Locale: %s\n",
                    timeinfo.timezone, timeinfo.utc_offset_seconds, timeinfo.locale);
            }
        } else {
            rc = 1;
        }
    }

    if (all || hardware) {
        fossil_sys_hostinfo_hardware_t hwinfo;
        if (fossil_sys_hostinfo_get_hardware(&hwinfo) == 0) {
            if (json) {
                printf("{\"hardware\":{\"manufacturer\":\"%s\",\"product\":\"%s\",\"serial\":\"%s\",\"bios\":\"%s\"}}\n",
                    hwinfo.manufacturer, hwinfo.product_name, hwinfo.serial_number, hwinfo.bios_version);
            } else {
                printf("Hardware:\n  Manufacturer: %s\n  Product: %s\n  Serial: %s\n  BIOS: %s\n",
                    hwinfo.manufacturer, hwinfo.product_name, hwinfo.serial_number, hwinfo.bios_version);
            }
        } else {
            rc = 1;
        }
    }

    if (all || display) {
        fossil_sys_hostinfo_display_t dispinfo;
        if (fossil_sys_hostinfo_get_display(&dispinfo) == 0) {
            if (json) {
                printf("{\"display\":{\"count\":%d,\"width\":%d,\"height\":%d,\"refresh\":%d}}\n",
                    dispinfo.display_count, dispinfo.primary_width, dispinfo.primary_height, dispinfo.primary_refresh_rate);
            } else {
                printf("Display:\n  Count: %d\n  Primary: %dx%d @ %dHz\n",
                    dispinfo.display_count, dispinfo.primary_width, dispinfo.primary_height, dispinfo.primary_refresh_rate);
            }
        } else {
            rc = 1;
        }
    }

    return rc;
    return 0;
}
