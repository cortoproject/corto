/* Sigar__meta.h
 *
 *  Generated on Feb  5 2014
 *    Loads objects in database.
 *    This file contains generated code. Do not modify!
 */

#ifndef Sigar_META_H
#define Sigar_META_H

#include "hyve.h"

#include "Sigar__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::Sigar */
extern db_object Sigar_o;

/* ::Sigar::CpuData */
extern db_struct Sigar_CpuData_o;

/* ::Sigar::CpuData::_wait */
extern db_member Sigar_CpuData__wait_o;

/* ::Sigar::CpuData::idle */
extern db_member Sigar_CpuData_idle_o;

/* ::Sigar::CpuData::irq */
extern db_member Sigar_CpuData_irq_o;

/* ::Sigar::CpuData::nice */
extern db_member Sigar_CpuData_nice_o;

/* ::Sigar::CpuData::soft_irq */
extern db_member Sigar_CpuData_soft_irq_o;

/* ::Sigar::CpuData::stolen */
extern db_member Sigar_CpuData_stolen_o;

/* ::Sigar::CpuData::sys */
extern db_member Sigar_CpuData_sys_o;

/* ::Sigar::CpuData::total */
extern db_member Sigar_CpuData_total_o;

/* ::Sigar::CpuData::user */
extern db_member Sigar_CpuData_user_o;

/* ::Sigar::CpuInfo */
extern db_struct Sigar_CpuInfo_o;

/* ::Sigar::CpuInfo::cache_size */
extern db_member Sigar_CpuInfo_cache_size_o;

/* ::Sigar::CpuInfo::cores_per_socket */
extern db_member Sigar_CpuInfo_cores_per_socket_o;

/* ::Sigar::CpuInfo::mhz */
extern db_member Sigar_CpuInfo_mhz_o;

/* ::Sigar::CpuInfo::model */
extern db_member Sigar_CpuInfo_model_o;

/* ::Sigar::CpuInfo::total_cores */
extern db_member Sigar_CpuInfo_total_cores_o;

/* ::Sigar::CpuInfo::total_sockets */
extern db_member Sigar_CpuInfo_total_sockets_o;

/* ::Sigar::CpuInfo::vendor */
extern db_member Sigar_CpuInfo_vendor_o;

/* ::Sigar::FileSystem */
extern db_struct Sigar_FileSystem_o;

/* ::Sigar::FileSystem::dev_name */
extern db_member Sigar_FileSystem_dev_name_o;

/* ::Sigar::FileSystem::dir_name */
extern db_member Sigar_FileSystem_dir_name_o;

/* ::Sigar::FileSystem::flags */
extern db_member Sigar_FileSystem_flags_o;

/* ::Sigar::FileSystem::options */
extern db_member Sigar_FileSystem_options_o;

/* ::Sigar::FileSystem::sys_type_name */
extern db_member Sigar_FileSystem_sys_type_name_o;

/* ::Sigar::FileSystem::type */
extern db_member Sigar_FileSystem_type_o;

/* ::Sigar::FileSystem::type_name */
extern db_member Sigar_FileSystem_type_name_o;

/* ::Sigar::FileSystemType */
extern db_enum Sigar_FileSystemType_o;

/* ::Sigar::FileSystemType::CDROM */
extern db_constant (*Sigar_FileSystemType_CDROM_o);

/* ::Sigar::FileSystemType::LOCAL_DISK */
extern db_constant (*Sigar_FileSystemType_LOCAL_DISK_o);

/* ::Sigar::FileSystemType::MAX */
extern db_constant (*Sigar_FileSystemType_MAX_o);

/* ::Sigar::FileSystemType::NETWORK */
extern db_constant (*Sigar_FileSystemType_NETWORK_o);

/* ::Sigar::FileSystemType::NONE */
extern db_constant (*Sigar_FileSystemType_NONE_o);

/* ::Sigar::FileSystemType::RAM_DISK */
extern db_constant (*Sigar_FileSystemType_RAM_DISK_o);

/* ::Sigar::FileSystemType::SWAP */
extern db_constant (*Sigar_FileSystemType_SWAP_o);

/* ::Sigar::FileSystemType::UNKNOWN */
extern db_constant (*Sigar_FileSystemType_UNKNOWN_o);

/* ::Sigar::Host */
extern db_class Sigar_Host_o;

/* ::Sigar::Host::construct(::Sigar::Host object) */
extern db_callback Sigar_Host_construct_o;

/* ::Sigar::Host::cpu */
extern db_member Sigar_Host_cpu_o;

/* ::Sigar::Host::cpu_info */
extern db_member Sigar_Host_cpu_info_o;

/* ::Sigar::Host::cpu_list */
extern db_member Sigar_Host_cpu_list_o;

/* ::Sigar::Host::destruct(::Sigar::Host object) */
extern db_callback Sigar_Host_destruct_o;

/* ::Sigar::Host::file_system_list */
extern db_member Sigar_Host_file_system_list_o;

/* ::Sigar::Host::handle */
extern db_member Sigar_Host_handle_o;

/* ::Sigar::Host::loadavg */
extern db_member Sigar_Host_loadavg_o;

/* ::Sigar::Host::memory */
extern db_member Sigar_Host_memory_o;

/* ::Sigar::Host::name */
extern db_member Sigar_Host_name_o;

/* ::Sigar::Host::proc_list */
extern db_member Sigar_Host_proc_list_o;

/* ::Sigar::Host::proc_stat */
extern db_member Sigar_Host_proc_stat_o;

/* ::Sigar::Host::refresh() */
extern db_method Sigar_Host_refresh_o;

/* ::Sigar::Host::stats */
extern db_member Sigar_Host_stats_o;

/* ::Sigar::Host::swap */
extern db_member Sigar_Host_swap_o;

/* ::Sigar::Host::uptime */
extern db_member Sigar_Host_uptime_o;

/* ::Sigar::LoadAvg */
extern db_struct Sigar_LoadAvg_o;

/* ::Sigar::LoadAvg::loadavg */
extern db_member Sigar_LoadAvg_loadavg_o;

/* ::Sigar::MemoryData */
extern db_struct Sigar_MemoryData_o;

/* ::Sigar::MemoryData::actual_free */
extern db_member Sigar_MemoryData_actual_free_o;

/* ::Sigar::MemoryData::actual_used */
extern db_member Sigar_MemoryData_actual_used_o;

/* ::Sigar::MemoryData::free */
extern db_member Sigar_MemoryData_free_o;

/* ::Sigar::MemoryData::free_percent */
extern db_member Sigar_MemoryData_free_percent_o;

/* ::Sigar::MemoryData::ram */
extern db_member Sigar_MemoryData_ram_o;

/* ::Sigar::MemoryData::total */
extern db_member Sigar_MemoryData_total_o;

/* ::Sigar::MemoryData::used */
extern db_member Sigar_MemoryData_used_o;

/* ::Sigar::MemoryData::used_percent */
extern db_member Sigar_MemoryData_used_percent_o;

/* ::Sigar::Pid */
extern db_typedef Sigar_Pid_o;

/* ::Sigar::ProcCpu */
extern db_struct Sigar_ProcCpu_o;

/* ::Sigar::ProcCpu::last_time */
extern db_member Sigar_ProcCpu_last_time_o;

/* ::Sigar::ProcCpu::percent */
extern db_member Sigar_ProcCpu_percent_o;

/* ::Sigar::ProcCpu::start_time */
extern db_member Sigar_ProcCpu_start_time_o;

/* ::Sigar::ProcCpu::sys */
extern db_member Sigar_ProcCpu_sys_o;

/* ::Sigar::ProcCpu::total */
extern db_member Sigar_ProcCpu_total_o;

/* ::Sigar::ProcCpu::user */
extern db_member Sigar_ProcCpu_user_o;

/* ::Sigar::Process */
extern db_class Sigar_Process_o;

/* ::Sigar::Process::cpu */
extern db_member Sigar_Process_cpu_o;

/* ::Sigar::Process::exe */
extern db_member Sigar_Process_exe_o;

/* ::Sigar::Process::mem */
extern db_member Sigar_Process_mem_o;

/* ::Sigar::Process::pid */
extern db_member Sigar_Process_pid_o;

/* ::Sigar::Process::time */
extern db_member Sigar_Process_time_o;

/* ::Sigar::ProcExe */
extern db_struct Sigar_ProcExe_o;

/* ::Sigar::ProcExe::cwd */
extern db_member Sigar_ProcExe_cwd_o;

/* ::Sigar::ProcExe::name */
extern db_member Sigar_ProcExe_name_o;

/* ::Sigar::ProcExe::root */
extern db_member Sigar_ProcExe_root_o;

/* ::Sigar::ProcMem */
extern db_struct Sigar_ProcMem_o;

/* ::Sigar::ProcMem::major_faults */
extern db_member Sigar_ProcMem_major_faults_o;

/* ::Sigar::ProcMem::minor_faults */
extern db_member Sigar_ProcMem_minor_faults_o;

/* ::Sigar::ProcMem::page_faults */
extern db_member Sigar_ProcMem_page_faults_o;

/* ::Sigar::ProcMem::resident */
extern db_member Sigar_ProcMem_resident_o;

/* ::Sigar::ProcMem::share */
extern db_member Sigar_ProcMem_share_o;

/* ::Sigar::ProcMem::size */
extern db_member Sigar_ProcMem_size_o;

/* ::Sigar::ProcStat */
extern db_struct Sigar_ProcStat_o;

/* ::Sigar::ProcStat::idle */
extern db_member Sigar_ProcStat_idle_o;

/* ::Sigar::ProcStat::running */
extern db_member Sigar_ProcStat_running_o;

/* ::Sigar::ProcStat::sleeping */
extern db_member Sigar_ProcStat_sleeping_o;

/* ::Sigar::ProcStat::stopped */
extern db_member Sigar_ProcStat_stopped_o;

/* ::Sigar::ProcStat::threads */
extern db_member Sigar_ProcStat_threads_o;

/* ::Sigar::ProcStat::total */
extern db_member Sigar_ProcStat_total_o;

/* ::Sigar::ProcStat::zombie */
extern db_member Sigar_ProcStat_zombie_o;

/* ::Sigar::ProcTime */
extern db_struct Sigar_ProcTime_o;

/* ::Sigar::ProcTime::start_time */
extern db_member Sigar_ProcTime_start_time_o;

/* ::Sigar::ProcTime::sys */
extern db_member Sigar_ProcTime_sys_o;

/* ::Sigar::ProcTime::total */
extern db_member Sigar_ProcTime_total_o;

/* ::Sigar::ProcTime::user */
extern db_member Sigar_ProcTime_user_o;

/* ::Sigar::Stats */
extern db_bitmask Sigar_Stats_o;

/* ::Sigar::Stats::CPU */
extern db_constant (*Sigar_Stats_CPU_o);

/* ::Sigar::Stats::CPU_INFO */
extern db_constant (*Sigar_Stats_CPU_INFO_o);

/* ::Sigar::Stats::CPU_LIST */
extern db_constant (*Sigar_Stats_CPU_LIST_o);

/* ::Sigar::Stats::FILE_SYSTEM_LIST */
extern db_constant (*Sigar_Stats_FILE_SYSTEM_LIST_o);

/* ::Sigar::Stats::LOADAVG */
extern db_constant (*Sigar_Stats_LOADAVG_o);

/* ::Sigar::Stats::MEM */
extern db_constant (*Sigar_Stats_MEM_o);

/* ::Sigar::Stats::PROC_CPU */
extern db_constant (*Sigar_Stats_PROC_CPU_o);

/* ::Sigar::Stats::PROC_EXE */
extern db_constant (*Sigar_Stats_PROC_EXE_o);

/* ::Sigar::Stats::PROC_LIST */
extern db_constant (*Sigar_Stats_PROC_LIST_o);

/* ::Sigar::Stats::PROC_MEM */
extern db_constant (*Sigar_Stats_PROC_MEM_o);

/* ::Sigar::Stats::PROC_STAT */
extern db_constant (*Sigar_Stats_PROC_STAT_o);

/* ::Sigar::Stats::PROC_TIME */
extern db_constant (*Sigar_Stats_PROC_TIME_o);

/* ::Sigar::Stats::SWAP */
extern db_constant (*Sigar_Stats_SWAP_o);

/* ::Sigar::Stats::UPTIME */
extern db_constant (*Sigar_Stats_UPTIME_o);

/* ::Sigar::SwapData */
extern db_struct Sigar_SwapData_o;

/* ::Sigar::SwapData::free */
extern db_member Sigar_SwapData_free_o;

/* ::Sigar::SwapData::page_in */
extern db_member Sigar_SwapData_page_in_o;

/* ::Sigar::SwapData::page_out */
extern db_member Sigar_SwapData_page_out_o;

/* ::Sigar::SwapData::total */
extern db_member Sigar_SwapData_total_o;

/* ::Sigar::SwapData::used */
extern db_member Sigar_SwapData_used_o;

/* ::Sigar::Uptime */
extern db_struct Sigar_Uptime_o;

/* ::Sigar::Uptime::uptime */
extern db_member Sigar_Uptime_uptime_o;

int Sigar_load(void);
#ifdef __cplusplus
}
#endif
#endif

