/* Sigar__meta.c
 *
 *  Generated on Feb  5 2014
 *    Loads objects in database.
 *    This file contains generated code. Do not modify!
 */

#include "Sigar__type.h"

/* Variable definitions */
db_object Sigar_o;
db_struct Sigar_CpuData_o;
db_member Sigar_CpuData__wait_o;
db_member Sigar_CpuData_idle_o;
db_member Sigar_CpuData_irq_o;
db_member Sigar_CpuData_nice_o;
db_member Sigar_CpuData_soft_irq_o;
db_member Sigar_CpuData_stolen_o;
db_member Sigar_CpuData_sys_o;
db_member Sigar_CpuData_total_o;
db_member Sigar_CpuData_user_o;
db_struct Sigar_CpuInfo_o;
db_member Sigar_CpuInfo_cache_size_o;
db_member Sigar_CpuInfo_cores_per_socket_o;
db_member Sigar_CpuInfo_mhz_o;
db_member Sigar_CpuInfo_model_o;
db_member Sigar_CpuInfo_total_cores_o;
db_member Sigar_CpuInfo_total_sockets_o;
db_member Sigar_CpuInfo_vendor_o;
db_struct Sigar_FileSystem_o;
db_member Sigar_FileSystem_dev_name_o;
db_member Sigar_FileSystem_dir_name_o;
db_member Sigar_FileSystem_flags_o;
db_member Sigar_FileSystem_options_o;
db_member Sigar_FileSystem_sys_type_name_o;
db_member Sigar_FileSystem_type_o;
db_member Sigar_FileSystem_type_name_o;
db_enum Sigar_FileSystemType_o;
db_constant (*Sigar_FileSystemType_CDROM_o);
db_constant (*Sigar_FileSystemType_LOCAL_DISK_o);
db_constant (*Sigar_FileSystemType_MAX_o);
db_constant (*Sigar_FileSystemType_NETWORK_o);
db_constant (*Sigar_FileSystemType_NONE_o);
db_constant (*Sigar_FileSystemType_RAM_DISK_o);
db_constant (*Sigar_FileSystemType_SWAP_o);
db_constant (*Sigar_FileSystemType_UNKNOWN_o);
db_class Sigar_Host_o;
db_callback Sigar_Host_construct_o;
db_member Sigar_Host_cpu_o;
db_member Sigar_Host_cpu_info_o;
db_member Sigar_Host_cpu_list_o;
db_callback Sigar_Host_destruct_o;
db_member Sigar_Host_file_system_list_o;
db_member Sigar_Host_handle_o;
db_member Sigar_Host_loadavg_o;
db_member Sigar_Host_memory_o;
db_member Sigar_Host_name_o;
db_member Sigar_Host_proc_list_o;
db_member Sigar_Host_proc_stat_o;
db_method Sigar_Host_refresh_o;
db_member Sigar_Host_stats_o;
db_member Sigar_Host_swap_o;
db_member Sigar_Host_uptime_o;
db_struct Sigar_LoadAvg_o;
db_member Sigar_LoadAvg_loadavg_o;
db_struct Sigar_MemoryData_o;
db_member Sigar_MemoryData_actual_free_o;
db_member Sigar_MemoryData_actual_used_o;
db_member Sigar_MemoryData_free_o;
db_member Sigar_MemoryData_free_percent_o;
db_member Sigar_MemoryData_ram_o;
db_member Sigar_MemoryData_total_o;
db_member Sigar_MemoryData_used_o;
db_member Sigar_MemoryData_used_percent_o;
db_typedef Sigar_Pid_o;
db_struct Sigar_ProcCpu_o;
db_member Sigar_ProcCpu_last_time_o;
db_member Sigar_ProcCpu_percent_o;
db_member Sigar_ProcCpu_start_time_o;
db_member Sigar_ProcCpu_sys_o;
db_member Sigar_ProcCpu_total_o;
db_member Sigar_ProcCpu_user_o;
db_class Sigar_Process_o;
db_member Sigar_Process_cpu_o;
db_member Sigar_Process_exe_o;
db_member Sigar_Process_mem_o;
db_member Sigar_Process_pid_o;
db_member Sigar_Process_time_o;
db_struct Sigar_ProcExe_o;
db_member Sigar_ProcExe_cwd_o;
db_member Sigar_ProcExe_name_o;
db_member Sigar_ProcExe_root_o;
db_struct Sigar_ProcMem_o;
db_member Sigar_ProcMem_major_faults_o;
db_member Sigar_ProcMem_minor_faults_o;
db_member Sigar_ProcMem_page_faults_o;
db_member Sigar_ProcMem_resident_o;
db_member Sigar_ProcMem_share_o;
db_member Sigar_ProcMem_size_o;
db_struct Sigar_ProcStat_o;
db_member Sigar_ProcStat_idle_o;
db_member Sigar_ProcStat_running_o;
db_member Sigar_ProcStat_sleeping_o;
db_member Sigar_ProcStat_stopped_o;
db_member Sigar_ProcStat_threads_o;
db_member Sigar_ProcStat_total_o;
db_member Sigar_ProcStat_zombie_o;
db_struct Sigar_ProcTime_o;
db_member Sigar_ProcTime_start_time_o;
db_member Sigar_ProcTime_sys_o;
db_member Sigar_ProcTime_total_o;
db_member Sigar_ProcTime_user_o;
db_bitmask Sigar_Stats_o;
db_constant (*Sigar_Stats_CPU_o);
db_constant (*Sigar_Stats_CPU_INFO_o);
db_constant (*Sigar_Stats_CPU_LIST_o);
db_constant (*Sigar_Stats_FILE_SYSTEM_LIST_o);
db_constant (*Sigar_Stats_LOADAVG_o);
db_constant (*Sigar_Stats_MEM_o);
db_constant (*Sigar_Stats_PROC_CPU_o);
db_constant (*Sigar_Stats_PROC_EXE_o);
db_constant (*Sigar_Stats_PROC_LIST_o);
db_constant (*Sigar_Stats_PROC_MEM_o);
db_constant (*Sigar_Stats_PROC_STAT_o);
db_constant (*Sigar_Stats_PROC_TIME_o);
db_constant (*Sigar_Stats_SWAP_o);
db_constant (*Sigar_Stats_UPTIME_o);
db_struct Sigar_SwapData_o;
db_member Sigar_SwapData_free_o;
db_member Sigar_SwapData_page_in_o;
db_member Sigar_SwapData_page_out_o;
db_member Sigar_SwapData_total_o;
db_member Sigar_SwapData_used_o;
db_struct Sigar_Uptime_o;
db_member Sigar_Uptime_uptime_o;

/* Load objects in database */
int Sigar_load(void) {
    db_object _a_; /* Used for resolving anonymous objects */
    _a_ = NULL;

    /* Declare ::Sigar */
    Sigar_o = db_declare(root_o, "Sigar", db_typedef(db_object_o));
    if (!Sigar_o) {
        db_error("Sigar_load: failed to declare object '::Sigar'.");
        goto error;
    }

    /* Define ::Sigar */
    if (!db_checkState(Sigar_o, DB_DEFINED)) {
        if (db_define(Sigar_o)) {
            db_error("Sigar_load: failed to define object '::Sigar'.");
            goto error;
        }
    }
    /* Declare ::Sigar::CpuData */
    Sigar_CpuData_o = db_declare(Sigar_o, "CpuData", db_typedef(db_struct_o));
    if (!Sigar_CpuData_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::CpuData'.");
        goto error;
    }

    /* Declare ::Sigar::CpuData::_wait */
    Sigar_CpuData__wait_o = db_declare(Sigar_CpuData_o, "_wait", db_typedef(db_member_o));
    if (!Sigar_CpuData__wait_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::CpuData::_wait'.");
        goto error;
    }

    /* Define ::Sigar::CpuData::_wait */
    if (!db_checkState(Sigar_CpuData__wait_o, DB_DEFINED)) {
        Sigar_CpuData__wait_o->type = db_resolve_ext(Sigar_CpuData__wait_o, NULL, "::hyve::lang::uint64", FALSE, "element ::Sigar::CpuData::_wait.type");
        Sigar_CpuData__wait_o->modifiers = 0x0;
        Sigar_CpuData__wait_o->state = 0x6;
        Sigar_CpuData__wait_o->weak = FALSE;
        Sigar_CpuData__wait_o->id = 4;
        if (db_define(Sigar_CpuData__wait_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::CpuData::_wait'.");
            goto error;
        }
    }
    /* Declare ::Sigar::CpuData::idle */
    Sigar_CpuData_idle_o = db_declare(Sigar_CpuData_o, "idle", db_typedef(db_member_o));
    if (!Sigar_CpuData_idle_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::CpuData::idle'.");
        goto error;
    }

    /* Define ::Sigar::CpuData::idle */
    if (!db_checkState(Sigar_CpuData_idle_o, DB_DEFINED)) {
        Sigar_CpuData_idle_o->type = db_resolve_ext(Sigar_CpuData_idle_o, NULL, "::hyve::lang::uint64", FALSE, "element ::Sigar::CpuData::idle.type");
        Sigar_CpuData_idle_o->modifiers = 0x0;
        Sigar_CpuData_idle_o->state = 0x6;
        Sigar_CpuData_idle_o->weak = FALSE;
        Sigar_CpuData_idle_o->id = 3;
        if (db_define(Sigar_CpuData_idle_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::CpuData::idle'.");
            goto error;
        }
    }
    /* Declare ::Sigar::CpuData::irq */
    Sigar_CpuData_irq_o = db_declare(Sigar_CpuData_o, "irq", db_typedef(db_member_o));
    if (!Sigar_CpuData_irq_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::CpuData::irq'.");
        goto error;
    }

    /* Define ::Sigar::CpuData::irq */
    if (!db_checkState(Sigar_CpuData_irq_o, DB_DEFINED)) {
        Sigar_CpuData_irq_o->type = db_resolve_ext(Sigar_CpuData_irq_o, NULL, "::hyve::lang::uint64", FALSE, "element ::Sigar::CpuData::irq.type");
        Sigar_CpuData_irq_o->modifiers = 0x0;
        Sigar_CpuData_irq_o->state = 0x6;
        Sigar_CpuData_irq_o->weak = FALSE;
        Sigar_CpuData_irq_o->id = 5;
        if (db_define(Sigar_CpuData_irq_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::CpuData::irq'.");
            goto error;
        }
    }
    /* Declare ::Sigar::CpuData::nice */
    Sigar_CpuData_nice_o = db_declare(Sigar_CpuData_o, "nice", db_typedef(db_member_o));
    if (!Sigar_CpuData_nice_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::CpuData::nice'.");
        goto error;
    }

    /* Define ::Sigar::CpuData::nice */
    if (!db_checkState(Sigar_CpuData_nice_o, DB_DEFINED)) {
        Sigar_CpuData_nice_o->type = db_resolve_ext(Sigar_CpuData_nice_o, NULL, "::hyve::lang::uint64", FALSE, "element ::Sigar::CpuData::nice.type");
        Sigar_CpuData_nice_o->modifiers = 0x0;
        Sigar_CpuData_nice_o->state = 0x6;
        Sigar_CpuData_nice_o->weak = FALSE;
        Sigar_CpuData_nice_o->id = 2;
        if (db_define(Sigar_CpuData_nice_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::CpuData::nice'.");
            goto error;
        }
    }
    /* Declare ::Sigar::CpuData::soft_irq */
    Sigar_CpuData_soft_irq_o = db_declare(Sigar_CpuData_o, "soft_irq", db_typedef(db_member_o));
    if (!Sigar_CpuData_soft_irq_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::CpuData::soft_irq'.");
        goto error;
    }

    /* Define ::Sigar::CpuData::soft_irq */
    if (!db_checkState(Sigar_CpuData_soft_irq_o, DB_DEFINED)) {
        Sigar_CpuData_soft_irq_o->type = db_resolve_ext(Sigar_CpuData_soft_irq_o, NULL, "::hyve::lang::uint64", FALSE, "element ::Sigar::CpuData::soft_irq.type");
        Sigar_CpuData_soft_irq_o->modifiers = 0x0;
        Sigar_CpuData_soft_irq_o->state = 0x6;
        Sigar_CpuData_soft_irq_o->weak = FALSE;
        Sigar_CpuData_soft_irq_o->id = 6;
        if (db_define(Sigar_CpuData_soft_irq_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::CpuData::soft_irq'.");
            goto error;
        }
    }
    /* Declare ::Sigar::CpuData::stolen */
    Sigar_CpuData_stolen_o = db_declare(Sigar_CpuData_o, "stolen", db_typedef(db_member_o));
    if (!Sigar_CpuData_stolen_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::CpuData::stolen'.");
        goto error;
    }

    /* Define ::Sigar::CpuData::stolen */
    if (!db_checkState(Sigar_CpuData_stolen_o, DB_DEFINED)) {
        Sigar_CpuData_stolen_o->type = db_resolve_ext(Sigar_CpuData_stolen_o, NULL, "::hyve::lang::uint64", FALSE, "element ::Sigar::CpuData::stolen.type");
        Sigar_CpuData_stolen_o->modifiers = 0x0;
        Sigar_CpuData_stolen_o->state = 0x6;
        Sigar_CpuData_stolen_o->weak = FALSE;
        Sigar_CpuData_stolen_o->id = 7;
        if (db_define(Sigar_CpuData_stolen_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::CpuData::stolen'.");
            goto error;
        }
    }
    /* Declare ::Sigar::CpuData::sys */
    Sigar_CpuData_sys_o = db_declare(Sigar_CpuData_o, "sys", db_typedef(db_member_o));
    if (!Sigar_CpuData_sys_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::CpuData::sys'.");
        goto error;
    }

    /* Define ::Sigar::CpuData::sys */
    if (!db_checkState(Sigar_CpuData_sys_o, DB_DEFINED)) {
        Sigar_CpuData_sys_o->type = db_resolve_ext(Sigar_CpuData_sys_o, NULL, "::hyve::lang::uint64", FALSE, "element ::Sigar::CpuData::sys.type");
        Sigar_CpuData_sys_o->modifiers = 0x0;
        Sigar_CpuData_sys_o->state = 0x6;
        Sigar_CpuData_sys_o->weak = FALSE;
        Sigar_CpuData_sys_o->id = 1;
        if (db_define(Sigar_CpuData_sys_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::CpuData::sys'.");
            goto error;
        }
    }
    /* Declare ::Sigar::CpuData::total */
    Sigar_CpuData_total_o = db_declare(Sigar_CpuData_o, "total", db_typedef(db_member_o));
    if (!Sigar_CpuData_total_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::CpuData::total'.");
        goto error;
    }

    /* Define ::Sigar::CpuData::total */
    if (!db_checkState(Sigar_CpuData_total_o, DB_DEFINED)) {
        Sigar_CpuData_total_o->type = db_resolve_ext(Sigar_CpuData_total_o, NULL, "::hyve::lang::uint64", FALSE, "element ::Sigar::CpuData::total.type");
        Sigar_CpuData_total_o->modifiers = 0x0;
        Sigar_CpuData_total_o->state = 0x6;
        Sigar_CpuData_total_o->weak = FALSE;
        Sigar_CpuData_total_o->id = 8;
        if (db_define(Sigar_CpuData_total_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::CpuData::total'.");
            goto error;
        }
    }
    /* Declare ::Sigar::CpuData::user */
    Sigar_CpuData_user_o = db_declare(Sigar_CpuData_o, "user", db_typedef(db_member_o));
    if (!Sigar_CpuData_user_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::CpuData::user'.");
        goto error;
    }

    /* Define ::Sigar::CpuData::user */
    if (!db_checkState(Sigar_CpuData_user_o, DB_DEFINED)) {
        Sigar_CpuData_user_o->type = db_resolve_ext(Sigar_CpuData_user_o, NULL, "::hyve::lang::uint64", FALSE, "element ::Sigar::CpuData::user.type");
        Sigar_CpuData_user_o->modifiers = 0x0;
        Sigar_CpuData_user_o->state = 0x6;
        Sigar_CpuData_user_o->weak = FALSE;
        Sigar_CpuData_user_o->id = 0;
        if (db_define(Sigar_CpuData_user_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::CpuData::user'.");
            goto error;
        }
    }
    /* Define ::Sigar::CpuData */
    if (!db_checkState(Sigar_CpuData_o, DB_DEFINED)) {
        db_type(Sigar_CpuData_o)->parentType = NULL;
        db_type(Sigar_CpuData_o)->parentState = 0x0;
        db_interface(Sigar_CpuData_o)->base = NULL;
        Sigar_CpuData_o->baseAccess = 0x0;
        if (db_define(Sigar_CpuData_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::CpuData'.");
            goto error;
        }
    }
    /* Declare ::Sigar::CpuInfo */
    Sigar_CpuInfo_o = db_declare(Sigar_o, "CpuInfo", db_typedef(db_struct_o));
    if (!Sigar_CpuInfo_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::CpuInfo'.");
        goto error;
    }

    /* Declare ::Sigar::CpuInfo::cache_size */
    Sigar_CpuInfo_cache_size_o = db_declare(Sigar_CpuInfo_o, "cache_size", db_typedef(db_member_o));
    if (!Sigar_CpuInfo_cache_size_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::CpuInfo::cache_size'.");
        goto error;
    }

    /* Define ::Sigar::CpuInfo::cache_size */
    if (!db_checkState(Sigar_CpuInfo_cache_size_o, DB_DEFINED)) {
        Sigar_CpuInfo_cache_size_o->type = db_resolve_ext(Sigar_CpuInfo_cache_size_o, NULL, "::hyve::lang::uint64", FALSE, "element ::Sigar::CpuInfo::cache_size.type");
        Sigar_CpuInfo_cache_size_o->modifiers = 0x0;
        Sigar_CpuInfo_cache_size_o->state = 0x6;
        Sigar_CpuInfo_cache_size_o->weak = FALSE;
        Sigar_CpuInfo_cache_size_o->id = 3;
        if (db_define(Sigar_CpuInfo_cache_size_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::CpuInfo::cache_size'.");
            goto error;
        }
    }
    /* Declare ::Sigar::CpuInfo::cores_per_socket */
    Sigar_CpuInfo_cores_per_socket_o = db_declare(Sigar_CpuInfo_o, "cores_per_socket", db_typedef(db_member_o));
    if (!Sigar_CpuInfo_cores_per_socket_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::CpuInfo::cores_per_socket'.");
        goto error;
    }

    /* Define ::Sigar::CpuInfo::cores_per_socket */
    if (!db_checkState(Sigar_CpuInfo_cores_per_socket_o, DB_DEFINED)) {
        Sigar_CpuInfo_cores_per_socket_o->type = db_resolve_ext(Sigar_CpuInfo_cores_per_socket_o, NULL, "::hyve::lang::uint32", FALSE, "element ::Sigar::CpuInfo::cores_per_socket.type");
        Sigar_CpuInfo_cores_per_socket_o->modifiers = 0x0;
        Sigar_CpuInfo_cores_per_socket_o->state = 0x6;
        Sigar_CpuInfo_cores_per_socket_o->weak = FALSE;
        Sigar_CpuInfo_cores_per_socket_o->id = 6;
        if (db_define(Sigar_CpuInfo_cores_per_socket_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::CpuInfo::cores_per_socket'.");
            goto error;
        }
    }
    /* Declare ::Sigar::CpuInfo::mhz */
    Sigar_CpuInfo_mhz_o = db_declare(Sigar_CpuInfo_o, "mhz", db_typedef(db_member_o));
    if (!Sigar_CpuInfo_mhz_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::CpuInfo::mhz'.");
        goto error;
    }

    /* Define ::Sigar::CpuInfo::mhz */
    if (!db_checkState(Sigar_CpuInfo_mhz_o, DB_DEFINED)) {
        Sigar_CpuInfo_mhz_o->type = db_resolve_ext(Sigar_CpuInfo_mhz_o, NULL, "::hyve::lang::uint32", FALSE, "element ::Sigar::CpuInfo::mhz.type");
        Sigar_CpuInfo_mhz_o->modifiers = 0x0;
        Sigar_CpuInfo_mhz_o->state = 0x6;
        Sigar_CpuInfo_mhz_o->weak = FALSE;
        Sigar_CpuInfo_mhz_o->id = 2;
        if (db_define(Sigar_CpuInfo_mhz_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::CpuInfo::mhz'.");
            goto error;
        }
    }
    /* Declare ::Sigar::CpuInfo::model */
    Sigar_CpuInfo_model_o = db_declare(Sigar_CpuInfo_o, "model", db_typedef(db_member_o));
    if (!Sigar_CpuInfo_model_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::CpuInfo::model'.");
        goto error;
    }

    /* Define ::Sigar::CpuInfo::model */
    if (!db_checkState(Sigar_CpuInfo_model_o, DB_DEFINED)) {
        Sigar_CpuInfo_model_o->type = db_resolve_ext(Sigar_CpuInfo_model_o, NULL, "::hyve::lang::string", FALSE, "element ::Sigar::CpuInfo::model.type");
        Sigar_CpuInfo_model_o->modifiers = 0x0;
        Sigar_CpuInfo_model_o->state = 0x6;
        Sigar_CpuInfo_model_o->weak = FALSE;
        Sigar_CpuInfo_model_o->id = 1;
        if (db_define(Sigar_CpuInfo_model_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::CpuInfo::model'.");
            goto error;
        }
    }
    /* Declare ::Sigar::CpuInfo::total_cores */
    Sigar_CpuInfo_total_cores_o = db_declare(Sigar_CpuInfo_o, "total_cores", db_typedef(db_member_o));
    if (!Sigar_CpuInfo_total_cores_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::CpuInfo::total_cores'.");
        goto error;
    }

    /* Define ::Sigar::CpuInfo::total_cores */
    if (!db_checkState(Sigar_CpuInfo_total_cores_o, DB_DEFINED)) {
        Sigar_CpuInfo_total_cores_o->type = db_resolve_ext(Sigar_CpuInfo_total_cores_o, NULL, "::hyve::lang::uint32", FALSE, "element ::Sigar::CpuInfo::total_cores.type");
        Sigar_CpuInfo_total_cores_o->modifiers = 0x0;
        Sigar_CpuInfo_total_cores_o->state = 0x6;
        Sigar_CpuInfo_total_cores_o->weak = FALSE;
        Sigar_CpuInfo_total_cores_o->id = 5;
        if (db_define(Sigar_CpuInfo_total_cores_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::CpuInfo::total_cores'.");
            goto error;
        }
    }
    /* Declare ::Sigar::CpuInfo::total_sockets */
    Sigar_CpuInfo_total_sockets_o = db_declare(Sigar_CpuInfo_o, "total_sockets", db_typedef(db_member_o));
    if (!Sigar_CpuInfo_total_sockets_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::CpuInfo::total_sockets'.");
        goto error;
    }

    /* Define ::Sigar::CpuInfo::total_sockets */
    if (!db_checkState(Sigar_CpuInfo_total_sockets_o, DB_DEFINED)) {
        Sigar_CpuInfo_total_sockets_o->type = db_resolve_ext(Sigar_CpuInfo_total_sockets_o, NULL, "::hyve::lang::uint32", FALSE, "element ::Sigar::CpuInfo::total_sockets.type");
        Sigar_CpuInfo_total_sockets_o->modifiers = 0x0;
        Sigar_CpuInfo_total_sockets_o->state = 0x6;
        Sigar_CpuInfo_total_sockets_o->weak = FALSE;
        Sigar_CpuInfo_total_sockets_o->id = 4;
        if (db_define(Sigar_CpuInfo_total_sockets_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::CpuInfo::total_sockets'.");
            goto error;
        }
    }
    /* Declare ::Sigar::CpuInfo::vendor */
    Sigar_CpuInfo_vendor_o = db_declare(Sigar_CpuInfo_o, "vendor", db_typedef(db_member_o));
    if (!Sigar_CpuInfo_vendor_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::CpuInfo::vendor'.");
        goto error;
    }

    /* Define ::Sigar::CpuInfo::vendor */
    if (!db_checkState(Sigar_CpuInfo_vendor_o, DB_DEFINED)) {
        Sigar_CpuInfo_vendor_o->type = db_resolve_ext(Sigar_CpuInfo_vendor_o, NULL, "::hyve::lang::string", FALSE, "element ::Sigar::CpuInfo::vendor.type");
        Sigar_CpuInfo_vendor_o->modifiers = 0x0;
        Sigar_CpuInfo_vendor_o->state = 0x6;
        Sigar_CpuInfo_vendor_o->weak = FALSE;
        Sigar_CpuInfo_vendor_o->id = 0;
        if (db_define(Sigar_CpuInfo_vendor_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::CpuInfo::vendor'.");
            goto error;
        }
    }
    /* Define ::Sigar::CpuInfo */
    if (!db_checkState(Sigar_CpuInfo_o, DB_DEFINED)) {
        db_type(Sigar_CpuInfo_o)->parentType = NULL;
        db_type(Sigar_CpuInfo_o)->parentState = 0x0;
        db_interface(Sigar_CpuInfo_o)->base = NULL;
        Sigar_CpuInfo_o->baseAccess = 0x0;
        if (db_define(Sigar_CpuInfo_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::CpuInfo'.");
            goto error;
        }
    }
    /* Declare ::Sigar::FileSystem */
    Sigar_FileSystem_o = db_declare(Sigar_o, "FileSystem", db_typedef(db_struct_o));
    if (!Sigar_FileSystem_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::FileSystem'.");
        goto error;
    }

    /* Declare ::Sigar::FileSystem::dev_name */
    Sigar_FileSystem_dev_name_o = db_declare(Sigar_FileSystem_o, "dev_name", db_typedef(db_member_o));
    if (!Sigar_FileSystem_dev_name_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::FileSystem::dev_name'.");
        goto error;
    }

    /* Define ::Sigar::FileSystem::dev_name */
    if (!db_checkState(Sigar_FileSystem_dev_name_o, DB_DEFINED)) {
        Sigar_FileSystem_dev_name_o->type = db_resolve_ext(Sigar_FileSystem_dev_name_o, NULL, "::hyve::lang::string", FALSE, "element ::Sigar::FileSystem::dev_name.type");
        Sigar_FileSystem_dev_name_o->modifiers = 0x0;
        Sigar_FileSystem_dev_name_o->state = 0x6;
        Sigar_FileSystem_dev_name_o->weak = FALSE;
        Sigar_FileSystem_dev_name_o->id = 1;
        if (db_define(Sigar_FileSystem_dev_name_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::FileSystem::dev_name'.");
            goto error;
        }
    }
    /* Declare ::Sigar::FileSystem::dir_name */
    Sigar_FileSystem_dir_name_o = db_declare(Sigar_FileSystem_o, "dir_name", db_typedef(db_member_o));
    if (!Sigar_FileSystem_dir_name_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::FileSystem::dir_name'.");
        goto error;
    }

    /* Define ::Sigar::FileSystem::dir_name */
    if (!db_checkState(Sigar_FileSystem_dir_name_o, DB_DEFINED)) {
        Sigar_FileSystem_dir_name_o->type = db_resolve_ext(Sigar_FileSystem_dir_name_o, NULL, "::hyve::lang::string", FALSE, "element ::Sigar::FileSystem::dir_name.type");
        Sigar_FileSystem_dir_name_o->modifiers = 0x0;
        Sigar_FileSystem_dir_name_o->state = 0x6;
        Sigar_FileSystem_dir_name_o->weak = FALSE;
        Sigar_FileSystem_dir_name_o->id = 0;
        if (db_define(Sigar_FileSystem_dir_name_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::FileSystem::dir_name'.");
            goto error;
        }
    }
    /* Declare ::Sigar::FileSystem::flags */
    Sigar_FileSystem_flags_o = db_declare(Sigar_FileSystem_o, "flags", db_typedef(db_member_o));
    if (!Sigar_FileSystem_flags_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::FileSystem::flags'.");
        goto error;
    }

    /* Define ::Sigar::FileSystem::flags */
    if (!db_checkState(Sigar_FileSystem_flags_o, DB_DEFINED)) {
        Sigar_FileSystem_flags_o->type = db_resolve_ext(Sigar_FileSystem_flags_o, NULL, "::hyve::lang::int32", FALSE, "element ::Sigar::FileSystem::flags.type");
        Sigar_FileSystem_flags_o->modifiers = 0x0;
        Sigar_FileSystem_flags_o->state = 0x6;
        Sigar_FileSystem_flags_o->weak = FALSE;
        Sigar_FileSystem_flags_o->id = 6;
        if (db_define(Sigar_FileSystem_flags_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::FileSystem::flags'.");
            goto error;
        }
    }
    /* Declare ::Sigar::FileSystem::options */
    Sigar_FileSystem_options_o = db_declare(Sigar_FileSystem_o, "options", db_typedef(db_member_o));
    if (!Sigar_FileSystem_options_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::FileSystem::options'.");
        goto error;
    }

    /* Define ::Sigar::FileSystem::options */
    if (!db_checkState(Sigar_FileSystem_options_o, DB_DEFINED)) {
        Sigar_FileSystem_options_o->type = db_resolve_ext(Sigar_FileSystem_options_o, NULL, "::hyve::lang::string", FALSE, "element ::Sigar::FileSystem::options.type");
        Sigar_FileSystem_options_o->modifiers = 0x0;
        Sigar_FileSystem_options_o->state = 0x6;
        Sigar_FileSystem_options_o->weak = FALSE;
        Sigar_FileSystem_options_o->id = 4;
        if (db_define(Sigar_FileSystem_options_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::FileSystem::options'.");
            goto error;
        }
    }
    /* Declare ::Sigar::FileSystem::sys_type_name */
    Sigar_FileSystem_sys_type_name_o = db_declare(Sigar_FileSystem_o, "sys_type_name", db_typedef(db_member_o));
    if (!Sigar_FileSystem_sys_type_name_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::FileSystem::sys_type_name'.");
        goto error;
    }

    /* Define ::Sigar::FileSystem::sys_type_name */
    if (!db_checkState(Sigar_FileSystem_sys_type_name_o, DB_DEFINED)) {
        Sigar_FileSystem_sys_type_name_o->type = db_resolve_ext(Sigar_FileSystem_sys_type_name_o, NULL, "::hyve::lang::string", FALSE, "element ::Sigar::FileSystem::sys_type_name.type");
        Sigar_FileSystem_sys_type_name_o->modifiers = 0x0;
        Sigar_FileSystem_sys_type_name_o->state = 0x6;
        Sigar_FileSystem_sys_type_name_o->weak = FALSE;
        Sigar_FileSystem_sys_type_name_o->id = 3;
        if (db_define(Sigar_FileSystem_sys_type_name_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::FileSystem::sys_type_name'.");
            goto error;
        }
    }
    /* Declare ::Sigar::FileSystem::type */
    Sigar_FileSystem_type_o = db_declare(Sigar_FileSystem_o, "type", db_typedef(db_member_o));
    if (!Sigar_FileSystem_type_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::FileSystem::type'.");
        goto error;
    }

    /* Declare ::Sigar::FileSystem::type_name */
    Sigar_FileSystem_type_name_o = db_declare(Sigar_FileSystem_o, "type_name", db_typedef(db_member_o));
    if (!Sigar_FileSystem_type_name_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::FileSystem::type_name'.");
        goto error;
    }

    /* Define ::Sigar::FileSystem::type_name */
    if (!db_checkState(Sigar_FileSystem_type_name_o, DB_DEFINED)) {
        Sigar_FileSystem_type_name_o->type = db_resolve_ext(Sigar_FileSystem_type_name_o, NULL, "::hyve::lang::string", FALSE, "element ::Sigar::FileSystem::type_name.type");
        Sigar_FileSystem_type_name_o->modifiers = 0x0;
        Sigar_FileSystem_type_name_o->state = 0x6;
        Sigar_FileSystem_type_name_o->weak = FALSE;
        Sigar_FileSystem_type_name_o->id = 2;
        if (db_define(Sigar_FileSystem_type_name_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::FileSystem::type_name'.");
            goto error;
        }
    }
    /* Declare ::Sigar::FileSystemType */
    Sigar_FileSystemType_o = db_declare(Sigar_o, "FileSystemType", db_typedef(db_enum_o));
    if (!Sigar_FileSystemType_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::FileSystemType'.");
        goto error;
    }

    /* Declare ::Sigar::FileSystemType::CDROM */
    Sigar_FileSystemType_CDROM_o = db_declare(Sigar_FileSystemType_o, "CDROM", db_typedef(db_constant_o));
    if (!Sigar_FileSystemType_CDROM_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::FileSystemType::CDROM'.");
        goto error;
    }

    /* Define ::Sigar::FileSystemType::CDROM */
    if (!db_checkState(Sigar_FileSystemType_CDROM_o, DB_DEFINED)) {
        (*Sigar_FileSystemType_CDROM_o) = 5;
        if (db_define(Sigar_FileSystemType_CDROM_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::FileSystemType::CDROM'.");
            goto error;
        }
    }
    /* Declare ::Sigar::FileSystemType::LOCAL_DISK */
    Sigar_FileSystemType_LOCAL_DISK_o = db_declare(Sigar_FileSystemType_o, "LOCAL_DISK", db_typedef(db_constant_o));
    if (!Sigar_FileSystemType_LOCAL_DISK_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::FileSystemType::LOCAL_DISK'.");
        goto error;
    }

    /* Define ::Sigar::FileSystemType::LOCAL_DISK */
    if (!db_checkState(Sigar_FileSystemType_LOCAL_DISK_o, DB_DEFINED)) {
        (*Sigar_FileSystemType_LOCAL_DISK_o) = 2;
        if (db_define(Sigar_FileSystemType_LOCAL_DISK_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::FileSystemType::LOCAL_DISK'.");
            goto error;
        }
    }
    /* Declare ::Sigar::FileSystemType::MAX */
    Sigar_FileSystemType_MAX_o = db_declare(Sigar_FileSystemType_o, "MAX", db_typedef(db_constant_o));
    if (!Sigar_FileSystemType_MAX_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::FileSystemType::MAX'.");
        goto error;
    }

    /* Define ::Sigar::FileSystemType::MAX */
    if (!db_checkState(Sigar_FileSystemType_MAX_o, DB_DEFINED)) {
        (*Sigar_FileSystemType_MAX_o) = 7;
        if (db_define(Sigar_FileSystemType_MAX_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::FileSystemType::MAX'.");
            goto error;
        }
    }
    /* Declare ::Sigar::FileSystemType::NETWORK */
    Sigar_FileSystemType_NETWORK_o = db_declare(Sigar_FileSystemType_o, "NETWORK", db_typedef(db_constant_o));
    if (!Sigar_FileSystemType_NETWORK_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::FileSystemType::NETWORK'.");
        goto error;
    }

    /* Define ::Sigar::FileSystemType::NETWORK */
    if (!db_checkState(Sigar_FileSystemType_NETWORK_o, DB_DEFINED)) {
        (*Sigar_FileSystemType_NETWORK_o) = 3;
        if (db_define(Sigar_FileSystemType_NETWORK_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::FileSystemType::NETWORK'.");
            goto error;
        }
    }
    /* Declare ::Sigar::FileSystemType::NONE */
    Sigar_FileSystemType_NONE_o = db_declare(Sigar_FileSystemType_o, "NONE", db_typedef(db_constant_o));
    if (!Sigar_FileSystemType_NONE_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::FileSystemType::NONE'.");
        goto error;
    }

    /* Define ::Sigar::FileSystemType::NONE */
    if (!db_checkState(Sigar_FileSystemType_NONE_o, DB_DEFINED)) {
        (*Sigar_FileSystemType_NONE_o) = 1;
        if (db_define(Sigar_FileSystemType_NONE_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::FileSystemType::NONE'.");
            goto error;
        }
    }
    /* Declare ::Sigar::FileSystemType::RAM_DISK */
    Sigar_FileSystemType_RAM_DISK_o = db_declare(Sigar_FileSystemType_o, "RAM_DISK", db_typedef(db_constant_o));
    if (!Sigar_FileSystemType_RAM_DISK_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::FileSystemType::RAM_DISK'.");
        goto error;
    }

    /* Define ::Sigar::FileSystemType::RAM_DISK */
    if (!db_checkState(Sigar_FileSystemType_RAM_DISK_o, DB_DEFINED)) {
        (*Sigar_FileSystemType_RAM_DISK_o) = 4;
        if (db_define(Sigar_FileSystemType_RAM_DISK_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::FileSystemType::RAM_DISK'.");
            goto error;
        }
    }
    /* Declare ::Sigar::FileSystemType::SWAP */
    Sigar_FileSystemType_SWAP_o = db_declare(Sigar_FileSystemType_o, "SWAP", db_typedef(db_constant_o));
    if (!Sigar_FileSystemType_SWAP_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::FileSystemType::SWAP'.");
        goto error;
    }

    /* Define ::Sigar::FileSystemType::SWAP */
    if (!db_checkState(Sigar_FileSystemType_SWAP_o, DB_DEFINED)) {
        (*Sigar_FileSystemType_SWAP_o) = 6;
        if (db_define(Sigar_FileSystemType_SWAP_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::FileSystemType::SWAP'.");
            goto error;
        }
    }
    /* Declare ::Sigar::FileSystemType::UNKNOWN */
    Sigar_FileSystemType_UNKNOWN_o = db_declare(Sigar_FileSystemType_o, "UNKNOWN", db_typedef(db_constant_o));
    if (!Sigar_FileSystemType_UNKNOWN_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::FileSystemType::UNKNOWN'.");
        goto error;
    }

    /* Define ::Sigar::FileSystemType::UNKNOWN */
    if (!db_checkState(Sigar_FileSystemType_UNKNOWN_o, DB_DEFINED)) {
        (*Sigar_FileSystemType_UNKNOWN_o) = 0;
        if (db_define(Sigar_FileSystemType_UNKNOWN_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::FileSystemType::UNKNOWN'.");
            goto error;
        }
    }
    /* Define ::Sigar::FileSystemType */
    if (!db_checkState(Sigar_FileSystemType_o, DB_DEFINED)) {
        if (db_define(Sigar_FileSystemType_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::FileSystemType'.");
            goto error;
        }
    }
    /* Define ::Sigar::FileSystem::type */
    if (!db_checkState(Sigar_FileSystem_type_o, DB_DEFINED)) {
        Sigar_FileSystem_type_o->type = db_resolve_ext(Sigar_FileSystem_type_o, NULL, "::Sigar::FileSystemType", FALSE, "element ::Sigar::FileSystem::type.type");
        Sigar_FileSystem_type_o->modifiers = 0x0;
        Sigar_FileSystem_type_o->state = 0x6;
        Sigar_FileSystem_type_o->weak = FALSE;
        Sigar_FileSystem_type_o->id = 5;
        if (db_define(Sigar_FileSystem_type_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::FileSystem::type'.");
            goto error;
        }
    }
    /* Define ::Sigar::FileSystem */
    if (!db_checkState(Sigar_FileSystem_o, DB_DEFINED)) {
        db_type(Sigar_FileSystem_o)->parentType = NULL;
        db_type(Sigar_FileSystem_o)->parentState = 0x0;
        db_interface(Sigar_FileSystem_o)->base = NULL;
        Sigar_FileSystem_o->baseAccess = 0x0;
        if (db_define(Sigar_FileSystem_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::FileSystem'.");
            goto error;
        }
    }
    /* Declare ::Sigar::Host */
    Sigar_Host_o = db_declare(Sigar_o, "Host", db_typedef(db_class_o));
    if (!Sigar_Host_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::Host'.");
        goto error;
    }

    /* Declare ::Sigar::Host::cpu */
    Sigar_Host_cpu_o = db_declare(Sigar_Host_o, "cpu", db_typedef(db_member_o));
    if (!Sigar_Host_cpu_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::Host::cpu'.");
        goto error;
    }

    /* Define ::Sigar::Host::cpu */
    if (!db_checkState(Sigar_Host_cpu_o, DB_DEFINED)) {
        Sigar_Host_cpu_o->type = db_resolve_ext(Sigar_Host_cpu_o, NULL, "::Sigar::CpuData", FALSE, "element ::Sigar::Host::cpu.type");
        Sigar_Host_cpu_o->modifiers = 0x5;
        Sigar_Host_cpu_o->state = 0x6;
        Sigar_Host_cpu_o->weak = FALSE;
        Sigar_Host_cpu_o->id = 2;
        if (db_define(Sigar_Host_cpu_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::Host::cpu'.");
            goto error;
        }
    }
    /* Declare ::Sigar::Host::cpu_info */
    Sigar_Host_cpu_info_o = db_declare(Sigar_Host_o, "cpu_info", db_typedef(db_member_o));
    if (!Sigar_Host_cpu_info_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::Host::cpu_info'.");
        goto error;
    }

    /* Define ::Sigar::Host::cpu_info */
    if (!db_checkState(Sigar_Host_cpu_info_o, DB_DEFINED)) {
        Sigar_Host_cpu_info_o->type = db_resolve_ext(Sigar_Host_cpu_info_o, NULL, "::hyve::lang::list{::Sigar::CpuInfo,0}", FALSE, "element ::Sigar::Host::cpu_info.type");
        Sigar_Host_cpu_info_o->modifiers = 0x5;
        Sigar_Host_cpu_info_o->state = 0x6;
        Sigar_Host_cpu_info_o->weak = FALSE;
        Sigar_Host_cpu_info_o->id = 4;
        if (db_define(Sigar_Host_cpu_info_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::Host::cpu_info'.");
            goto error;
        }
    }
    /* Declare ::Sigar::Host::cpu_list */
    Sigar_Host_cpu_list_o = db_declare(Sigar_Host_o, "cpu_list", db_typedef(db_member_o));
    if (!Sigar_Host_cpu_list_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::Host::cpu_list'.");
        goto error;
    }

    /* Define ::Sigar::Host::cpu_list */
    if (!db_checkState(Sigar_Host_cpu_list_o, DB_DEFINED)) {
        Sigar_Host_cpu_list_o->type = db_resolve_ext(Sigar_Host_cpu_list_o, NULL, "::hyve::lang::list{::Sigar::CpuData,0}", FALSE, "element ::Sigar::Host::cpu_list.type");
        Sigar_Host_cpu_list_o->modifiers = 0x5;
        Sigar_Host_cpu_list_o->state = 0x6;
        Sigar_Host_cpu_list_o->weak = FALSE;
        Sigar_Host_cpu_list_o->id = 3;
        if (db_define(Sigar_Host_cpu_list_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::Host::cpu_list'.");
            goto error;
        }
    }
    /* Declare ::Sigar::Host::file_system_list */
    Sigar_Host_file_system_list_o = db_declare(Sigar_Host_o, "file_system_list", db_typedef(db_member_o));
    if (!Sigar_Host_file_system_list_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::Host::file_system_list'.");
        goto error;
    }

    /* Define ::Sigar::Host::file_system_list */
    if (!db_checkState(Sigar_Host_file_system_list_o, DB_DEFINED)) {
        Sigar_Host_file_system_list_o->type = db_resolve_ext(Sigar_Host_file_system_list_o, NULL, "::hyve::lang::list{::Sigar::FileSystem,0}", FALSE, "element ::Sigar::Host::file_system_list.type");
        Sigar_Host_file_system_list_o->modifiers = 0x5;
        Sigar_Host_file_system_list_o->state = 0x6;
        Sigar_Host_file_system_list_o->weak = FALSE;
        Sigar_Host_file_system_list_o->id = 11;
        if (db_define(Sigar_Host_file_system_list_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::Host::file_system_list'.");
            goto error;
        }
    }
    /* Declare ::Sigar::Host::handle */
    Sigar_Host_handle_o = db_declare(Sigar_Host_o, "handle", db_typedef(db_member_o));
    if (!Sigar_Host_handle_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::Host::handle'.");
        goto error;
    }

    /* Define ::Sigar::Host::handle */
    if (!db_checkState(Sigar_Host_handle_o, DB_DEFINED)) {
        Sigar_Host_handle_o->type = db_resolve_ext(Sigar_Host_handle_o, NULL, "::hyve::lang::word", FALSE, "element ::Sigar::Host::handle.type");
        Sigar_Host_handle_o->modifiers = 0x3;
        Sigar_Host_handle_o->state = 0x6;
        Sigar_Host_handle_o->weak = FALSE;
        Sigar_Host_handle_o->id = 12;
        if (db_define(Sigar_Host_handle_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::Host::handle'.");
            goto error;
        }
    }
    /* Declare ::Sigar::Host::loadavg */
    Sigar_Host_loadavg_o = db_declare(Sigar_Host_o, "loadavg", db_typedef(db_member_o));
    if (!Sigar_Host_loadavg_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::Host::loadavg'.");
        goto error;
    }

    /* Declare ::Sigar::Host::memory */
    Sigar_Host_memory_o = db_declare(Sigar_Host_o, "memory", db_typedef(db_member_o));
    if (!Sigar_Host_memory_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::Host::memory'.");
        goto error;
    }

    /* Declare ::Sigar::Host::name */
    Sigar_Host_name_o = db_declare(Sigar_Host_o, "name", db_typedef(db_member_o));
    if (!Sigar_Host_name_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::Host::name'.");
        goto error;
    }

    /* Define ::Sigar::Host::name */
    if (!db_checkState(Sigar_Host_name_o, DB_DEFINED)) {
        Sigar_Host_name_o->type = db_resolve_ext(Sigar_Host_name_o, NULL, "::hyve::lang::string", FALSE, "element ::Sigar::Host::name.type");
        Sigar_Host_name_o->modifiers = 0x0;
        Sigar_Host_name_o->state = 0x6;
        Sigar_Host_name_o->weak = FALSE;
        Sigar_Host_name_o->id = 0;
        if (db_define(Sigar_Host_name_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::Host::name'.");
            goto error;
        }
    }
    /* Declare ::Sigar::Host::proc_list */
    Sigar_Host_proc_list_o = db_declare(Sigar_Host_o, "proc_list", db_typedef(db_member_o));
    if (!Sigar_Host_proc_list_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::Host::proc_list'.");
        goto error;
    }

    /* Declare ::Sigar::Host::proc_stat */
    Sigar_Host_proc_stat_o = db_declare(Sigar_Host_o, "proc_stat", db_typedef(db_member_o));
    if (!Sigar_Host_proc_stat_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::Host::proc_stat'.");
        goto error;
    }

    /* Declare ::Sigar::Host::refresh() */
    Sigar_Host_refresh_o = db_declare(Sigar_Host_o, "refresh()", db_typedef(db_method_o));
    if (!Sigar_Host_refresh_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::Host::refresh()'.");
        goto error;
    }

    /* Define ::Sigar::Host::refresh() */
    if (!db_checkState(Sigar_Host_refresh_o, DB_DEFINED)) {
        db_function(Sigar_Host_refresh_o)->returnType = db_resolve_ext(Sigar_Host_refresh_o, NULL, "::hyve::lang::void", FALSE, "element ::Sigar::Host::refresh().returnType");
        Sigar_Host_refresh_o->virtual = FALSE;
        
        /* Bind Sigar_Host_refresh_o with C-function */
        db_function(Sigar_Host_refresh_o)->kind = DB_PROCEDURE_CDECL;
        db_void Sigar_Host_refresh(Sigar_Host _this);
        db_function(Sigar_Host_refresh_o)->impl = (db_word)Sigar_Host_refresh;
        if (db_define(Sigar_Host_refresh_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::Host::refresh()'.");
            goto error;
        }
    }
    /* Declare ::Sigar::Host::stats */
    Sigar_Host_stats_o = db_declare(Sigar_Host_o, "stats", db_typedef(db_member_o));
    if (!Sigar_Host_stats_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::Host::stats'.");
        goto error;
    }

    /* Declare ::Sigar::Host::swap */
    Sigar_Host_swap_o = db_declare(Sigar_Host_o, "swap", db_typedef(db_member_o));
    if (!Sigar_Host_swap_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::Host::swap'.");
        goto error;
    }

    /* Declare ::Sigar::Host::uptime */
    Sigar_Host_uptime_o = db_declare(Sigar_Host_o, "uptime", db_typedef(db_member_o));
    if (!Sigar_Host_uptime_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::Host::uptime'.");
        goto error;
    }

    /* Declare ::Sigar::LoadAvg */
    Sigar_LoadAvg_o = db_declare(Sigar_o, "LoadAvg", db_typedef(db_struct_o));
    if (!Sigar_LoadAvg_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::LoadAvg'.");
        goto error;
    }

    /* Declare ::Sigar::LoadAvg::loadavg */
    Sigar_LoadAvg_loadavg_o = db_declare(Sigar_LoadAvg_o, "loadavg", db_typedef(db_member_o));
    if (!Sigar_LoadAvg_loadavg_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::LoadAvg::loadavg'.");
        goto error;
    }

    /* Declare ::Sigar::MemoryData */
    Sigar_MemoryData_o = db_declare(Sigar_o, "MemoryData", db_typedef(db_struct_o));
    if (!Sigar_MemoryData_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::MemoryData'.");
        goto error;
    }

    /* Declare ::Sigar::MemoryData::actual_free */
    Sigar_MemoryData_actual_free_o = db_declare(Sigar_MemoryData_o, "actual_free", db_typedef(db_member_o));
    if (!Sigar_MemoryData_actual_free_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::MemoryData::actual_free'.");
        goto error;
    }

    /* Define ::Sigar::MemoryData::actual_free */
    if (!db_checkState(Sigar_MemoryData_actual_free_o, DB_DEFINED)) {
        Sigar_MemoryData_actual_free_o->type = db_resolve_ext(Sigar_MemoryData_actual_free_o, NULL, "::hyve::lang::uint64", FALSE, "element ::Sigar::MemoryData::actual_free.type");
        Sigar_MemoryData_actual_free_o->modifiers = 0x0;
        Sigar_MemoryData_actual_free_o->state = 0x6;
        Sigar_MemoryData_actual_free_o->weak = FALSE;
        Sigar_MemoryData_actual_free_o->id = 5;
        if (db_define(Sigar_MemoryData_actual_free_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::MemoryData::actual_free'.");
            goto error;
        }
    }
    /* Declare ::Sigar::MemoryData::actual_used */
    Sigar_MemoryData_actual_used_o = db_declare(Sigar_MemoryData_o, "actual_used", db_typedef(db_member_o));
    if (!Sigar_MemoryData_actual_used_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::MemoryData::actual_used'.");
        goto error;
    }

    /* Define ::Sigar::MemoryData::actual_used */
    if (!db_checkState(Sigar_MemoryData_actual_used_o, DB_DEFINED)) {
        Sigar_MemoryData_actual_used_o->type = db_resolve_ext(Sigar_MemoryData_actual_used_o, NULL, "::hyve::lang::uint64", FALSE, "element ::Sigar::MemoryData::actual_used.type");
        Sigar_MemoryData_actual_used_o->modifiers = 0x0;
        Sigar_MemoryData_actual_used_o->state = 0x6;
        Sigar_MemoryData_actual_used_o->weak = FALSE;
        Sigar_MemoryData_actual_used_o->id = 4;
        if (db_define(Sigar_MemoryData_actual_used_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::MemoryData::actual_used'.");
            goto error;
        }
    }
    /* Declare ::Sigar::MemoryData::free */
    Sigar_MemoryData_free_o = db_declare(Sigar_MemoryData_o, "free", db_typedef(db_member_o));
    if (!Sigar_MemoryData_free_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::MemoryData::free'.");
        goto error;
    }

    /* Define ::Sigar::MemoryData::free */
    if (!db_checkState(Sigar_MemoryData_free_o, DB_DEFINED)) {
        Sigar_MemoryData_free_o->type = db_resolve_ext(Sigar_MemoryData_free_o, NULL, "::hyve::lang::uint64", FALSE, "element ::Sigar::MemoryData::free.type");
        Sigar_MemoryData_free_o->modifiers = 0x0;
        Sigar_MemoryData_free_o->state = 0x6;
        Sigar_MemoryData_free_o->weak = FALSE;
        Sigar_MemoryData_free_o->id = 3;
        if (db_define(Sigar_MemoryData_free_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::MemoryData::free'.");
            goto error;
        }
    }
    /* Declare ::Sigar::MemoryData::free_percent */
    Sigar_MemoryData_free_percent_o = db_declare(Sigar_MemoryData_o, "free_percent", db_typedef(db_member_o));
    if (!Sigar_MemoryData_free_percent_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::MemoryData::free_percent'.");
        goto error;
    }

    /* Define ::Sigar::MemoryData::free_percent */
    if (!db_checkState(Sigar_MemoryData_free_percent_o, DB_DEFINED)) {
        Sigar_MemoryData_free_percent_o->type = db_resolve_ext(Sigar_MemoryData_free_percent_o, NULL, "::hyve::lang::float64", FALSE, "element ::Sigar::MemoryData::free_percent.type");
        Sigar_MemoryData_free_percent_o->modifiers = 0x0;
        Sigar_MemoryData_free_percent_o->state = 0x6;
        Sigar_MemoryData_free_percent_o->weak = FALSE;
        Sigar_MemoryData_free_percent_o->id = 7;
        if (db_define(Sigar_MemoryData_free_percent_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::MemoryData::free_percent'.");
            goto error;
        }
    }
    /* Declare ::Sigar::MemoryData::ram */
    Sigar_MemoryData_ram_o = db_declare(Sigar_MemoryData_o, "ram", db_typedef(db_member_o));
    if (!Sigar_MemoryData_ram_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::MemoryData::ram'.");
        goto error;
    }

    /* Define ::Sigar::MemoryData::ram */
    if (!db_checkState(Sigar_MemoryData_ram_o, DB_DEFINED)) {
        Sigar_MemoryData_ram_o->type = db_resolve_ext(Sigar_MemoryData_ram_o, NULL, "::hyve::lang::uint64", FALSE, "element ::Sigar::MemoryData::ram.type");
        Sigar_MemoryData_ram_o->modifiers = 0x0;
        Sigar_MemoryData_ram_o->state = 0x6;
        Sigar_MemoryData_ram_o->weak = FALSE;
        Sigar_MemoryData_ram_o->id = 0;
        if (db_define(Sigar_MemoryData_ram_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::MemoryData::ram'.");
            goto error;
        }
    }
    /* Declare ::Sigar::MemoryData::total */
    Sigar_MemoryData_total_o = db_declare(Sigar_MemoryData_o, "total", db_typedef(db_member_o));
    if (!Sigar_MemoryData_total_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::MemoryData::total'.");
        goto error;
    }

    /* Define ::Sigar::MemoryData::total */
    if (!db_checkState(Sigar_MemoryData_total_o, DB_DEFINED)) {
        Sigar_MemoryData_total_o->type = db_resolve_ext(Sigar_MemoryData_total_o, NULL, "::hyve::lang::uint64", FALSE, "element ::Sigar::MemoryData::total.type");
        Sigar_MemoryData_total_o->modifiers = 0x0;
        Sigar_MemoryData_total_o->state = 0x6;
        Sigar_MemoryData_total_o->weak = FALSE;
        Sigar_MemoryData_total_o->id = 1;
        if (db_define(Sigar_MemoryData_total_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::MemoryData::total'.");
            goto error;
        }
    }
    /* Declare ::Sigar::MemoryData::used */
    Sigar_MemoryData_used_o = db_declare(Sigar_MemoryData_o, "used", db_typedef(db_member_o));
    if (!Sigar_MemoryData_used_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::MemoryData::used'.");
        goto error;
    }

    /* Define ::Sigar::MemoryData::used */
    if (!db_checkState(Sigar_MemoryData_used_o, DB_DEFINED)) {
        Sigar_MemoryData_used_o->type = db_resolve_ext(Sigar_MemoryData_used_o, NULL, "::hyve::lang::uint64", FALSE, "element ::Sigar::MemoryData::used.type");
        Sigar_MemoryData_used_o->modifiers = 0x0;
        Sigar_MemoryData_used_o->state = 0x6;
        Sigar_MemoryData_used_o->weak = FALSE;
        Sigar_MemoryData_used_o->id = 2;
        if (db_define(Sigar_MemoryData_used_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::MemoryData::used'.");
            goto error;
        }
    }
    /* Declare ::Sigar::MemoryData::used_percent */
    Sigar_MemoryData_used_percent_o = db_declare(Sigar_MemoryData_o, "used_percent", db_typedef(db_member_o));
    if (!Sigar_MemoryData_used_percent_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::MemoryData::used_percent'.");
        goto error;
    }

    /* Define ::Sigar::MemoryData::used_percent */
    if (!db_checkState(Sigar_MemoryData_used_percent_o, DB_DEFINED)) {
        Sigar_MemoryData_used_percent_o->type = db_resolve_ext(Sigar_MemoryData_used_percent_o, NULL, "::hyve::lang::float64", FALSE, "element ::Sigar::MemoryData::used_percent.type");
        Sigar_MemoryData_used_percent_o->modifiers = 0x0;
        Sigar_MemoryData_used_percent_o->state = 0x6;
        Sigar_MemoryData_used_percent_o->weak = FALSE;
        Sigar_MemoryData_used_percent_o->id = 6;
        if (db_define(Sigar_MemoryData_used_percent_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::MemoryData::used_percent'.");
            goto error;
        }
    }
    /* Define ::Sigar::MemoryData */
    if (!db_checkState(Sigar_MemoryData_o, DB_DEFINED)) {
        db_type(Sigar_MemoryData_o)->parentType = NULL;
        db_type(Sigar_MemoryData_o)->parentState = 0x0;
        db_interface(Sigar_MemoryData_o)->base = NULL;
        Sigar_MemoryData_o->baseAccess = 0x0;
        if (db_define(Sigar_MemoryData_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::MemoryData'.");
            goto error;
        }
    }
    /* Define ::Sigar::Host::memory */
    if (!db_checkState(Sigar_Host_memory_o, DB_DEFINED)) {
        Sigar_Host_memory_o->type = db_resolve_ext(Sigar_Host_memory_o, NULL, "::Sigar::MemoryData", FALSE, "element ::Sigar::Host::memory.type");
        Sigar_Host_memory_o->modifiers = 0x5;
        Sigar_Host_memory_o->state = 0x6;
        Sigar_Host_memory_o->weak = FALSE;
        Sigar_Host_memory_o->id = 5;
        if (db_define(Sigar_Host_memory_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::Host::memory'.");
            goto error;
        }
    }
    /* Declare ::Sigar::Pid */
    Sigar_Pid_o = db_declare(Sigar_o, "Pid", db_typedef(db_typedef_o));
    if (!Sigar_Pid_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::Pid'.");
        goto error;
    }

    /* Define ::Sigar::Pid */
    if (!db_checkState(Sigar_Pid_o, DB_DEFINED)) {
        Sigar_Pid_o->type = db_resolve_ext(Sigar_Pid_o, NULL, "::hyve::lang::uint64", FALSE, "element ::Sigar::Pid.type");
        if (db_define(Sigar_Pid_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::Pid'.");
            goto error;
        }
    }
    /* Declare ::Sigar::ProcCpu */
    Sigar_ProcCpu_o = db_declare(Sigar_o, "ProcCpu", db_typedef(db_struct_o));
    if (!Sigar_ProcCpu_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::ProcCpu'.");
        goto error;
    }

    /* Declare ::Sigar::ProcCpu::last_time */
    Sigar_ProcCpu_last_time_o = db_declare(Sigar_ProcCpu_o, "last_time", db_typedef(db_member_o));
    if (!Sigar_ProcCpu_last_time_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::ProcCpu::last_time'.");
        goto error;
    }

    /* Define ::Sigar::ProcCpu::last_time */
    if (!db_checkState(Sigar_ProcCpu_last_time_o, DB_DEFINED)) {
        Sigar_ProcCpu_last_time_o->type = db_resolve_ext(Sigar_ProcCpu_last_time_o, NULL, "::hyve::lang::uint64", FALSE, "element ::Sigar::ProcCpu::last_time.type");
        Sigar_ProcCpu_last_time_o->modifiers = 0x0;
        Sigar_ProcCpu_last_time_o->state = 0x6;
        Sigar_ProcCpu_last_time_o->weak = FALSE;
        Sigar_ProcCpu_last_time_o->id = 4;
        if (db_define(Sigar_ProcCpu_last_time_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::ProcCpu::last_time'.");
            goto error;
        }
    }
    /* Declare ::Sigar::ProcCpu::percent */
    Sigar_ProcCpu_percent_o = db_declare(Sigar_ProcCpu_o, "percent", db_typedef(db_member_o));
    if (!Sigar_ProcCpu_percent_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::ProcCpu::percent'.");
        goto error;
    }

    /* Define ::Sigar::ProcCpu::percent */
    if (!db_checkState(Sigar_ProcCpu_percent_o, DB_DEFINED)) {
        Sigar_ProcCpu_percent_o->type = db_resolve_ext(Sigar_ProcCpu_percent_o, NULL, "::hyve::lang::float64", FALSE, "element ::Sigar::ProcCpu::percent.type");
        Sigar_ProcCpu_percent_o->modifiers = 0x0;
        Sigar_ProcCpu_percent_o->state = 0x6;
        Sigar_ProcCpu_percent_o->weak = FALSE;
        Sigar_ProcCpu_percent_o->id = 5;
        if (db_define(Sigar_ProcCpu_percent_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::ProcCpu::percent'.");
            goto error;
        }
    }
    /* Declare ::Sigar::ProcCpu::start_time */
    Sigar_ProcCpu_start_time_o = db_declare(Sigar_ProcCpu_o, "start_time", db_typedef(db_member_o));
    if (!Sigar_ProcCpu_start_time_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::ProcCpu::start_time'.");
        goto error;
    }

    /* Define ::Sigar::ProcCpu::start_time */
    if (!db_checkState(Sigar_ProcCpu_start_time_o, DB_DEFINED)) {
        Sigar_ProcCpu_start_time_o->type = db_resolve_ext(Sigar_ProcCpu_start_time_o, NULL, "::hyve::lang::uint64", FALSE, "element ::Sigar::ProcCpu::start_time.type");
        Sigar_ProcCpu_start_time_o->modifiers = 0x0;
        Sigar_ProcCpu_start_time_o->state = 0x6;
        Sigar_ProcCpu_start_time_o->weak = FALSE;
        Sigar_ProcCpu_start_time_o->id = 0;
        if (db_define(Sigar_ProcCpu_start_time_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::ProcCpu::start_time'.");
            goto error;
        }
    }
    /* Declare ::Sigar::ProcCpu::sys */
    Sigar_ProcCpu_sys_o = db_declare(Sigar_ProcCpu_o, "sys", db_typedef(db_member_o));
    if (!Sigar_ProcCpu_sys_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::ProcCpu::sys'.");
        goto error;
    }

    /* Define ::Sigar::ProcCpu::sys */
    if (!db_checkState(Sigar_ProcCpu_sys_o, DB_DEFINED)) {
        Sigar_ProcCpu_sys_o->type = db_resolve_ext(Sigar_ProcCpu_sys_o, NULL, "::hyve::lang::uint64", FALSE, "element ::Sigar::ProcCpu::sys.type");
        Sigar_ProcCpu_sys_o->modifiers = 0x0;
        Sigar_ProcCpu_sys_o->state = 0x6;
        Sigar_ProcCpu_sys_o->weak = FALSE;
        Sigar_ProcCpu_sys_o->id = 2;
        if (db_define(Sigar_ProcCpu_sys_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::ProcCpu::sys'.");
            goto error;
        }
    }
    /* Declare ::Sigar::ProcCpu::total */
    Sigar_ProcCpu_total_o = db_declare(Sigar_ProcCpu_o, "total", db_typedef(db_member_o));
    if (!Sigar_ProcCpu_total_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::ProcCpu::total'.");
        goto error;
    }

    /* Define ::Sigar::ProcCpu::total */
    if (!db_checkState(Sigar_ProcCpu_total_o, DB_DEFINED)) {
        Sigar_ProcCpu_total_o->type = db_resolve_ext(Sigar_ProcCpu_total_o, NULL, "::hyve::lang::uint64", FALSE, "element ::Sigar::ProcCpu::total.type");
        Sigar_ProcCpu_total_o->modifiers = 0x0;
        Sigar_ProcCpu_total_o->state = 0x6;
        Sigar_ProcCpu_total_o->weak = FALSE;
        Sigar_ProcCpu_total_o->id = 3;
        if (db_define(Sigar_ProcCpu_total_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::ProcCpu::total'.");
            goto error;
        }
    }
    /* Declare ::Sigar::ProcCpu::user */
    Sigar_ProcCpu_user_o = db_declare(Sigar_ProcCpu_o, "user", db_typedef(db_member_o));
    if (!Sigar_ProcCpu_user_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::ProcCpu::user'.");
        goto error;
    }

    /* Define ::Sigar::ProcCpu::user */
    if (!db_checkState(Sigar_ProcCpu_user_o, DB_DEFINED)) {
        Sigar_ProcCpu_user_o->type = db_resolve_ext(Sigar_ProcCpu_user_o, NULL, "::hyve::lang::uint64", FALSE, "element ::Sigar::ProcCpu::user.type");
        Sigar_ProcCpu_user_o->modifiers = 0x0;
        Sigar_ProcCpu_user_o->state = 0x6;
        Sigar_ProcCpu_user_o->weak = FALSE;
        Sigar_ProcCpu_user_o->id = 1;
        if (db_define(Sigar_ProcCpu_user_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::ProcCpu::user'.");
            goto error;
        }
    }
    /* Define ::Sigar::ProcCpu */
    if (!db_checkState(Sigar_ProcCpu_o, DB_DEFINED)) {
        db_type(Sigar_ProcCpu_o)->parentType = NULL;
        db_type(Sigar_ProcCpu_o)->parentState = 0x0;
        db_interface(Sigar_ProcCpu_o)->base = NULL;
        Sigar_ProcCpu_o->baseAccess = 0x0;
        if (db_define(Sigar_ProcCpu_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::ProcCpu'.");
            goto error;
        }
    }
    /* Declare ::Sigar::Process */
    Sigar_Process_o = db_declare(Sigar_o, "Process", db_typedef(db_class_o));
    if (!Sigar_Process_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::Process'.");
        goto error;
    }

    /* Declare ::Sigar::Process::cpu */
    Sigar_Process_cpu_o = db_declare(Sigar_Process_o, "cpu", db_typedef(db_member_o));
    if (!Sigar_Process_cpu_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::Process::cpu'.");
        goto error;
    }

    /* Define ::Sigar::Process::cpu */
    if (!db_checkState(Sigar_Process_cpu_o, DB_DEFINED)) {
        Sigar_Process_cpu_o->type = db_resolve_ext(Sigar_Process_cpu_o, NULL, "::Sigar::ProcCpu", FALSE, "element ::Sigar::Process::cpu.type");
        Sigar_Process_cpu_o->modifiers = 0x1;
        Sigar_Process_cpu_o->state = 0x6;
        Sigar_Process_cpu_o->weak = FALSE;
        Sigar_Process_cpu_o->id = 3;
        if (db_define(Sigar_Process_cpu_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::Process::cpu'.");
            goto error;
        }
    }
    /* Declare ::Sigar::Process::exe */
    Sigar_Process_exe_o = db_declare(Sigar_Process_o, "exe", db_typedef(db_member_o));
    if (!Sigar_Process_exe_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::Process::exe'.");
        goto error;
    }

    /* Declare ::Sigar::Process::mem */
    Sigar_Process_mem_o = db_declare(Sigar_Process_o, "mem", db_typedef(db_member_o));
    if (!Sigar_Process_mem_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::Process::mem'.");
        goto error;
    }

    /* Declare ::Sigar::Process::pid */
    Sigar_Process_pid_o = db_declare(Sigar_Process_o, "pid", db_typedef(db_member_o));
    if (!Sigar_Process_pid_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::Process::pid'.");
        goto error;
    }

    /* Define ::Sigar::Process::pid */
    if (!db_checkState(Sigar_Process_pid_o, DB_DEFINED)) {
        Sigar_Process_pid_o->type = db_resolve_ext(Sigar_Process_pid_o, NULL, "::Sigar::Pid", FALSE, "element ::Sigar::Process::pid.type");
        Sigar_Process_pid_o->modifiers = 0x0;
        Sigar_Process_pid_o->state = 0x6;
        Sigar_Process_pid_o->weak = FALSE;
        Sigar_Process_pid_o->id = 0;
        if (db_define(Sigar_Process_pid_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::Process::pid'.");
            goto error;
        }
    }
    /* Declare ::Sigar::Process::time */
    Sigar_Process_time_o = db_declare(Sigar_Process_o, "time", db_typedef(db_member_o));
    if (!Sigar_Process_time_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::Process::time'.");
        goto error;
    }

    /* Define ::Sigar::Host::proc_list */
    if (!db_checkState(Sigar_Host_proc_list_o, DB_DEFINED)) {
        Sigar_Host_proc_list_o->type = db_resolve_ext(Sigar_Host_proc_list_o, NULL, "::hyve::lang::list{::Sigar::Process,0}", FALSE, "element ::Sigar::Host::proc_list.type");
        Sigar_Host_proc_list_o->modifiers = 0x5;
        Sigar_Host_proc_list_o->state = 0x6;
        Sigar_Host_proc_list_o->weak = FALSE;
        Sigar_Host_proc_list_o->id = 9;
        if (db_define(Sigar_Host_proc_list_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::Host::proc_list'.");
            goto error;
        }
    }
    /* Declare ::Sigar::ProcExe */
    Sigar_ProcExe_o = db_declare(Sigar_o, "ProcExe", db_typedef(db_struct_o));
    if (!Sigar_ProcExe_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::ProcExe'.");
        goto error;
    }

    /* Declare ::Sigar::ProcExe::cwd */
    Sigar_ProcExe_cwd_o = db_declare(Sigar_ProcExe_o, "cwd", db_typedef(db_member_o));
    if (!Sigar_ProcExe_cwd_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::ProcExe::cwd'.");
        goto error;
    }

    /* Define ::Sigar::ProcExe::cwd */
    if (!db_checkState(Sigar_ProcExe_cwd_o, DB_DEFINED)) {
        Sigar_ProcExe_cwd_o->type = db_resolve_ext(Sigar_ProcExe_cwd_o, NULL, "::hyve::lang::string", FALSE, "element ::Sigar::ProcExe::cwd.type");
        Sigar_ProcExe_cwd_o->modifiers = 0x0;
        Sigar_ProcExe_cwd_o->state = 0x6;
        Sigar_ProcExe_cwd_o->weak = FALSE;
        Sigar_ProcExe_cwd_o->id = 1;
        if (db_define(Sigar_ProcExe_cwd_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::ProcExe::cwd'.");
            goto error;
        }
    }
    /* Declare ::Sigar::ProcExe::name */
    Sigar_ProcExe_name_o = db_declare(Sigar_ProcExe_o, "name", db_typedef(db_member_o));
    if (!Sigar_ProcExe_name_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::ProcExe::name'.");
        goto error;
    }

    /* Define ::Sigar::ProcExe::name */
    if (!db_checkState(Sigar_ProcExe_name_o, DB_DEFINED)) {
        Sigar_ProcExe_name_o->type = db_resolve_ext(Sigar_ProcExe_name_o, NULL, "::hyve::lang::string", FALSE, "element ::Sigar::ProcExe::name.type");
        Sigar_ProcExe_name_o->modifiers = 0x0;
        Sigar_ProcExe_name_o->state = 0x6;
        Sigar_ProcExe_name_o->weak = FALSE;
        Sigar_ProcExe_name_o->id = 0;
        if (db_define(Sigar_ProcExe_name_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::ProcExe::name'.");
            goto error;
        }
    }
    /* Declare ::Sigar::ProcExe::root */
    Sigar_ProcExe_root_o = db_declare(Sigar_ProcExe_o, "root", db_typedef(db_member_o));
    if (!Sigar_ProcExe_root_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::ProcExe::root'.");
        goto error;
    }

    /* Define ::Sigar::ProcExe::root */
    if (!db_checkState(Sigar_ProcExe_root_o, DB_DEFINED)) {
        Sigar_ProcExe_root_o->type = db_resolve_ext(Sigar_ProcExe_root_o, NULL, "::hyve::lang::string", FALSE, "element ::Sigar::ProcExe::root.type");
        Sigar_ProcExe_root_o->modifiers = 0x0;
        Sigar_ProcExe_root_o->state = 0x6;
        Sigar_ProcExe_root_o->weak = FALSE;
        Sigar_ProcExe_root_o->id = 2;
        if (db_define(Sigar_ProcExe_root_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::ProcExe::root'.");
            goto error;
        }
    }
    /* Define ::Sigar::ProcExe */
    if (!db_checkState(Sigar_ProcExe_o, DB_DEFINED)) {
        db_type(Sigar_ProcExe_o)->parentType = NULL;
        db_type(Sigar_ProcExe_o)->parentState = 0x0;
        db_interface(Sigar_ProcExe_o)->base = NULL;
        Sigar_ProcExe_o->baseAccess = 0x0;
        if (db_define(Sigar_ProcExe_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::ProcExe'.");
            goto error;
        }
    }
    /* Define ::Sigar::Process::exe */
    if (!db_checkState(Sigar_Process_exe_o, DB_DEFINED)) {
        Sigar_Process_exe_o->type = db_resolve_ext(Sigar_Process_exe_o, NULL, "::Sigar::ProcExe", FALSE, "element ::Sigar::Process::exe.type");
        Sigar_Process_exe_o->modifiers = 0x1;
        Sigar_Process_exe_o->state = 0x6;
        Sigar_Process_exe_o->weak = FALSE;
        Sigar_Process_exe_o->id = 4;
        if (db_define(Sigar_Process_exe_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::Process::exe'.");
            goto error;
        }
    }
    /* Declare ::Sigar::ProcMem */
    Sigar_ProcMem_o = db_declare(Sigar_o, "ProcMem", db_typedef(db_struct_o));
    if (!Sigar_ProcMem_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::ProcMem'.");
        goto error;
    }

    /* Declare ::Sigar::ProcMem::major_faults */
    Sigar_ProcMem_major_faults_o = db_declare(Sigar_ProcMem_o, "major_faults", db_typedef(db_member_o));
    if (!Sigar_ProcMem_major_faults_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::ProcMem::major_faults'.");
        goto error;
    }

    /* Define ::Sigar::ProcMem::major_faults */
    if (!db_checkState(Sigar_ProcMem_major_faults_o, DB_DEFINED)) {
        Sigar_ProcMem_major_faults_o->type = db_resolve_ext(Sigar_ProcMem_major_faults_o, NULL, "::hyve::lang::uint64", FALSE, "element ::Sigar::ProcMem::major_faults.type");
        Sigar_ProcMem_major_faults_o->modifiers = 0x0;
        Sigar_ProcMem_major_faults_o->state = 0x6;
        Sigar_ProcMem_major_faults_o->weak = FALSE;
        Sigar_ProcMem_major_faults_o->id = 4;
        if (db_define(Sigar_ProcMem_major_faults_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::ProcMem::major_faults'.");
            goto error;
        }
    }
    /* Declare ::Sigar::ProcMem::minor_faults */
    Sigar_ProcMem_minor_faults_o = db_declare(Sigar_ProcMem_o, "minor_faults", db_typedef(db_member_o));
    if (!Sigar_ProcMem_minor_faults_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::ProcMem::minor_faults'.");
        goto error;
    }

    /* Define ::Sigar::ProcMem::minor_faults */
    if (!db_checkState(Sigar_ProcMem_minor_faults_o, DB_DEFINED)) {
        Sigar_ProcMem_minor_faults_o->type = db_resolve_ext(Sigar_ProcMem_minor_faults_o, NULL, "::hyve::lang::uint64", FALSE, "element ::Sigar::ProcMem::minor_faults.type");
        Sigar_ProcMem_minor_faults_o->modifiers = 0x0;
        Sigar_ProcMem_minor_faults_o->state = 0x6;
        Sigar_ProcMem_minor_faults_o->weak = FALSE;
        Sigar_ProcMem_minor_faults_o->id = 3;
        if (db_define(Sigar_ProcMem_minor_faults_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::ProcMem::minor_faults'.");
            goto error;
        }
    }
    /* Declare ::Sigar::ProcMem::page_faults */
    Sigar_ProcMem_page_faults_o = db_declare(Sigar_ProcMem_o, "page_faults", db_typedef(db_member_o));
    if (!Sigar_ProcMem_page_faults_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::ProcMem::page_faults'.");
        goto error;
    }

    /* Define ::Sigar::ProcMem::page_faults */
    if (!db_checkState(Sigar_ProcMem_page_faults_o, DB_DEFINED)) {
        Sigar_ProcMem_page_faults_o->type = db_resolve_ext(Sigar_ProcMem_page_faults_o, NULL, "::hyve::lang::uint64", FALSE, "element ::Sigar::ProcMem::page_faults.type");
        Sigar_ProcMem_page_faults_o->modifiers = 0x0;
        Sigar_ProcMem_page_faults_o->state = 0x6;
        Sigar_ProcMem_page_faults_o->weak = FALSE;
        Sigar_ProcMem_page_faults_o->id = 5;
        if (db_define(Sigar_ProcMem_page_faults_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::ProcMem::page_faults'.");
            goto error;
        }
    }
    /* Declare ::Sigar::ProcMem::resident */
    Sigar_ProcMem_resident_o = db_declare(Sigar_ProcMem_o, "resident", db_typedef(db_member_o));
    if (!Sigar_ProcMem_resident_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::ProcMem::resident'.");
        goto error;
    }

    /* Define ::Sigar::ProcMem::resident */
    if (!db_checkState(Sigar_ProcMem_resident_o, DB_DEFINED)) {
        Sigar_ProcMem_resident_o->type = db_resolve_ext(Sigar_ProcMem_resident_o, NULL, "::hyve::lang::uint64", FALSE, "element ::Sigar::ProcMem::resident.type");
        Sigar_ProcMem_resident_o->modifiers = 0x0;
        Sigar_ProcMem_resident_o->state = 0x6;
        Sigar_ProcMem_resident_o->weak = FALSE;
        Sigar_ProcMem_resident_o->id = 1;
        if (db_define(Sigar_ProcMem_resident_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::ProcMem::resident'.");
            goto error;
        }
    }
    /* Declare ::Sigar::ProcMem::share */
    Sigar_ProcMem_share_o = db_declare(Sigar_ProcMem_o, "share", db_typedef(db_member_o));
    if (!Sigar_ProcMem_share_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::ProcMem::share'.");
        goto error;
    }

    /* Define ::Sigar::ProcMem::share */
    if (!db_checkState(Sigar_ProcMem_share_o, DB_DEFINED)) {
        Sigar_ProcMem_share_o->type = db_resolve_ext(Sigar_ProcMem_share_o, NULL, "::hyve::lang::uint64", FALSE, "element ::Sigar::ProcMem::share.type");
        Sigar_ProcMem_share_o->modifiers = 0x0;
        Sigar_ProcMem_share_o->state = 0x6;
        Sigar_ProcMem_share_o->weak = FALSE;
        Sigar_ProcMem_share_o->id = 2;
        if (db_define(Sigar_ProcMem_share_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::ProcMem::share'.");
            goto error;
        }
    }
    /* Declare ::Sigar::ProcMem::size */
    Sigar_ProcMem_size_o = db_declare(Sigar_ProcMem_o, "size", db_typedef(db_member_o));
    if (!Sigar_ProcMem_size_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::ProcMem::size'.");
        goto error;
    }

    /* Define ::Sigar::ProcMem::size */
    if (!db_checkState(Sigar_ProcMem_size_o, DB_DEFINED)) {
        Sigar_ProcMem_size_o->type = db_resolve_ext(Sigar_ProcMem_size_o, NULL, "::hyve::lang::uint64", FALSE, "element ::Sigar::ProcMem::size.type");
        Sigar_ProcMem_size_o->modifiers = 0x0;
        Sigar_ProcMem_size_o->state = 0x6;
        Sigar_ProcMem_size_o->weak = FALSE;
        Sigar_ProcMem_size_o->id = 0;
        if (db_define(Sigar_ProcMem_size_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::ProcMem::size'.");
            goto error;
        }
    }
    /* Define ::Sigar::ProcMem */
    if (!db_checkState(Sigar_ProcMem_o, DB_DEFINED)) {
        db_type(Sigar_ProcMem_o)->parentType = NULL;
        db_type(Sigar_ProcMem_o)->parentState = 0x0;
        db_interface(Sigar_ProcMem_o)->base = NULL;
        Sigar_ProcMem_o->baseAccess = 0x0;
        if (db_define(Sigar_ProcMem_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::ProcMem'.");
            goto error;
        }
    }
    /* Define ::Sigar::Process::mem */
    if (!db_checkState(Sigar_Process_mem_o, DB_DEFINED)) {
        Sigar_Process_mem_o->type = db_resolve_ext(Sigar_Process_mem_o, NULL, "::Sigar::ProcMem", FALSE, "element ::Sigar::Process::mem.type");
        Sigar_Process_mem_o->modifiers = 0x1;
        Sigar_Process_mem_o->state = 0x6;
        Sigar_Process_mem_o->weak = FALSE;
        Sigar_Process_mem_o->id = 1;
        if (db_define(Sigar_Process_mem_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::Process::mem'.");
            goto error;
        }
    }
    /* Declare ::Sigar::ProcStat */
    Sigar_ProcStat_o = db_declare(Sigar_o, "ProcStat", db_typedef(db_struct_o));
    if (!Sigar_ProcStat_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::ProcStat'.");
        goto error;
    }

    /* Declare ::Sigar::ProcStat::idle */
    Sigar_ProcStat_idle_o = db_declare(Sigar_ProcStat_o, "idle", db_typedef(db_member_o));
    if (!Sigar_ProcStat_idle_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::ProcStat::idle'.");
        goto error;
    }

    /* Define ::Sigar::ProcStat::idle */
    if (!db_checkState(Sigar_ProcStat_idle_o, DB_DEFINED)) {
        Sigar_ProcStat_idle_o->type = db_resolve_ext(Sigar_ProcStat_idle_o, NULL, "::hyve::lang::uint64", FALSE, "element ::Sigar::ProcStat::idle.type");
        Sigar_ProcStat_idle_o->modifiers = 0x0;
        Sigar_ProcStat_idle_o->state = 0x6;
        Sigar_ProcStat_idle_o->weak = FALSE;
        Sigar_ProcStat_idle_o->id = 5;
        if (db_define(Sigar_ProcStat_idle_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::ProcStat::idle'.");
            goto error;
        }
    }
    /* Declare ::Sigar::ProcStat::running */
    Sigar_ProcStat_running_o = db_declare(Sigar_ProcStat_o, "running", db_typedef(db_member_o));
    if (!Sigar_ProcStat_running_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::ProcStat::running'.");
        goto error;
    }

    /* Define ::Sigar::ProcStat::running */
    if (!db_checkState(Sigar_ProcStat_running_o, DB_DEFINED)) {
        Sigar_ProcStat_running_o->type = db_resolve_ext(Sigar_ProcStat_running_o, NULL, "::hyve::lang::uint64", FALSE, "element ::Sigar::ProcStat::running.type");
        Sigar_ProcStat_running_o->modifiers = 0x0;
        Sigar_ProcStat_running_o->state = 0x6;
        Sigar_ProcStat_running_o->weak = FALSE;
        Sigar_ProcStat_running_o->id = 2;
        if (db_define(Sigar_ProcStat_running_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::ProcStat::running'.");
            goto error;
        }
    }
    /* Declare ::Sigar::ProcStat::sleeping */
    Sigar_ProcStat_sleeping_o = db_declare(Sigar_ProcStat_o, "sleeping", db_typedef(db_member_o));
    if (!Sigar_ProcStat_sleeping_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::ProcStat::sleeping'.");
        goto error;
    }

    /* Define ::Sigar::ProcStat::sleeping */
    if (!db_checkState(Sigar_ProcStat_sleeping_o, DB_DEFINED)) {
        Sigar_ProcStat_sleeping_o->type = db_resolve_ext(Sigar_ProcStat_sleeping_o, NULL, "::hyve::lang::uint64", FALSE, "element ::Sigar::ProcStat::sleeping.type");
        Sigar_ProcStat_sleeping_o->modifiers = 0x0;
        Sigar_ProcStat_sleeping_o->state = 0x6;
        Sigar_ProcStat_sleeping_o->weak = FALSE;
        Sigar_ProcStat_sleeping_o->id = 1;
        if (db_define(Sigar_ProcStat_sleeping_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::ProcStat::sleeping'.");
            goto error;
        }
    }
    /* Declare ::Sigar::ProcStat::stopped */
    Sigar_ProcStat_stopped_o = db_declare(Sigar_ProcStat_o, "stopped", db_typedef(db_member_o));
    if (!Sigar_ProcStat_stopped_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::ProcStat::stopped'.");
        goto error;
    }

    /* Define ::Sigar::ProcStat::stopped */
    if (!db_checkState(Sigar_ProcStat_stopped_o, DB_DEFINED)) {
        Sigar_ProcStat_stopped_o->type = db_resolve_ext(Sigar_ProcStat_stopped_o, NULL, "::hyve::lang::uint64", FALSE, "element ::Sigar::ProcStat::stopped.type");
        Sigar_ProcStat_stopped_o->modifiers = 0x0;
        Sigar_ProcStat_stopped_o->state = 0x6;
        Sigar_ProcStat_stopped_o->weak = FALSE;
        Sigar_ProcStat_stopped_o->id = 4;
        if (db_define(Sigar_ProcStat_stopped_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::ProcStat::stopped'.");
            goto error;
        }
    }
    /* Declare ::Sigar::ProcStat::threads */
    Sigar_ProcStat_threads_o = db_declare(Sigar_ProcStat_o, "threads", db_typedef(db_member_o));
    if (!Sigar_ProcStat_threads_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::ProcStat::threads'.");
        goto error;
    }

    /* Define ::Sigar::ProcStat::threads */
    if (!db_checkState(Sigar_ProcStat_threads_o, DB_DEFINED)) {
        Sigar_ProcStat_threads_o->type = db_resolve_ext(Sigar_ProcStat_threads_o, NULL, "::hyve::lang::uint64", FALSE, "element ::Sigar::ProcStat::threads.type");
        Sigar_ProcStat_threads_o->modifiers = 0x0;
        Sigar_ProcStat_threads_o->state = 0x6;
        Sigar_ProcStat_threads_o->weak = FALSE;
        Sigar_ProcStat_threads_o->id = 6;
        if (db_define(Sigar_ProcStat_threads_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::ProcStat::threads'.");
            goto error;
        }
    }
    /* Declare ::Sigar::ProcStat::total */
    Sigar_ProcStat_total_o = db_declare(Sigar_ProcStat_o, "total", db_typedef(db_member_o));
    if (!Sigar_ProcStat_total_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::ProcStat::total'.");
        goto error;
    }

    /* Define ::Sigar::ProcStat::total */
    if (!db_checkState(Sigar_ProcStat_total_o, DB_DEFINED)) {
        Sigar_ProcStat_total_o->type = db_resolve_ext(Sigar_ProcStat_total_o, NULL, "::hyve::lang::uint64", FALSE, "element ::Sigar::ProcStat::total.type");
        Sigar_ProcStat_total_o->modifiers = 0x0;
        Sigar_ProcStat_total_o->state = 0x6;
        Sigar_ProcStat_total_o->weak = FALSE;
        Sigar_ProcStat_total_o->id = 0;
        if (db_define(Sigar_ProcStat_total_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::ProcStat::total'.");
            goto error;
        }
    }
    /* Declare ::Sigar::ProcStat::zombie */
    Sigar_ProcStat_zombie_o = db_declare(Sigar_ProcStat_o, "zombie", db_typedef(db_member_o));
    if (!Sigar_ProcStat_zombie_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::ProcStat::zombie'.");
        goto error;
    }

    /* Define ::Sigar::ProcStat::zombie */
    if (!db_checkState(Sigar_ProcStat_zombie_o, DB_DEFINED)) {
        Sigar_ProcStat_zombie_o->type = db_resolve_ext(Sigar_ProcStat_zombie_o, NULL, "::hyve::lang::uint64", FALSE, "element ::Sigar::ProcStat::zombie.type");
        Sigar_ProcStat_zombie_o->modifiers = 0x0;
        Sigar_ProcStat_zombie_o->state = 0x6;
        Sigar_ProcStat_zombie_o->weak = FALSE;
        Sigar_ProcStat_zombie_o->id = 3;
        if (db_define(Sigar_ProcStat_zombie_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::ProcStat::zombie'.");
            goto error;
        }
    }
    /* Define ::Sigar::ProcStat */
    if (!db_checkState(Sigar_ProcStat_o, DB_DEFINED)) {
        db_type(Sigar_ProcStat_o)->parentType = NULL;
        db_type(Sigar_ProcStat_o)->parentState = 0x0;
        db_interface(Sigar_ProcStat_o)->base = NULL;
        Sigar_ProcStat_o->baseAccess = 0x0;
        if (db_define(Sigar_ProcStat_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::ProcStat'.");
            goto error;
        }
    }
    /* Define ::Sigar::Host::proc_stat */
    if (!db_checkState(Sigar_Host_proc_stat_o, DB_DEFINED)) {
        Sigar_Host_proc_stat_o->type = db_resolve_ext(Sigar_Host_proc_stat_o, NULL, "::Sigar::ProcStat", FALSE, "element ::Sigar::Host::proc_stat.type");
        Sigar_Host_proc_stat_o->modifiers = 0x5;
        Sigar_Host_proc_stat_o->state = 0x6;
        Sigar_Host_proc_stat_o->weak = FALSE;
        Sigar_Host_proc_stat_o->id = 10;
        if (db_define(Sigar_Host_proc_stat_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::Host::proc_stat'.");
            goto error;
        }
    }
    /* Declare ::Sigar::ProcTime */
    Sigar_ProcTime_o = db_declare(Sigar_o, "ProcTime", db_typedef(db_struct_o));
    if (!Sigar_ProcTime_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::ProcTime'.");
        goto error;
    }

    /* Declare ::Sigar::ProcTime::start_time */
    Sigar_ProcTime_start_time_o = db_declare(Sigar_ProcTime_o, "start_time", db_typedef(db_member_o));
    if (!Sigar_ProcTime_start_time_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::ProcTime::start_time'.");
        goto error;
    }

    /* Define ::Sigar::ProcTime::start_time */
    if (!db_checkState(Sigar_ProcTime_start_time_o, DB_DEFINED)) {
        Sigar_ProcTime_start_time_o->type = db_resolve_ext(Sigar_ProcTime_start_time_o, NULL, "::hyve::lang::uint64", FALSE, "element ::Sigar::ProcTime::start_time.type");
        Sigar_ProcTime_start_time_o->modifiers = 0x0;
        Sigar_ProcTime_start_time_o->state = 0x6;
        Sigar_ProcTime_start_time_o->weak = FALSE;
        Sigar_ProcTime_start_time_o->id = 0;
        if (db_define(Sigar_ProcTime_start_time_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::ProcTime::start_time'.");
            goto error;
        }
    }
    /* Declare ::Sigar::ProcTime::sys */
    Sigar_ProcTime_sys_o = db_declare(Sigar_ProcTime_o, "sys", db_typedef(db_member_o));
    if (!Sigar_ProcTime_sys_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::ProcTime::sys'.");
        goto error;
    }

    /* Define ::Sigar::ProcTime::sys */
    if (!db_checkState(Sigar_ProcTime_sys_o, DB_DEFINED)) {
        Sigar_ProcTime_sys_o->type = db_resolve_ext(Sigar_ProcTime_sys_o, NULL, "::hyve::lang::uint64", FALSE, "element ::Sigar::ProcTime::sys.type");
        Sigar_ProcTime_sys_o->modifiers = 0x0;
        Sigar_ProcTime_sys_o->state = 0x6;
        Sigar_ProcTime_sys_o->weak = FALSE;
        Sigar_ProcTime_sys_o->id = 2;
        if (db_define(Sigar_ProcTime_sys_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::ProcTime::sys'.");
            goto error;
        }
    }
    /* Declare ::Sigar::ProcTime::total */
    Sigar_ProcTime_total_o = db_declare(Sigar_ProcTime_o, "total", db_typedef(db_member_o));
    if (!Sigar_ProcTime_total_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::ProcTime::total'.");
        goto error;
    }

    /* Define ::Sigar::ProcTime::total */
    if (!db_checkState(Sigar_ProcTime_total_o, DB_DEFINED)) {
        Sigar_ProcTime_total_o->type = db_resolve_ext(Sigar_ProcTime_total_o, NULL, "::hyve::lang::uint64", FALSE, "element ::Sigar::ProcTime::total.type");
        Sigar_ProcTime_total_o->modifiers = 0x0;
        Sigar_ProcTime_total_o->state = 0x6;
        Sigar_ProcTime_total_o->weak = FALSE;
        Sigar_ProcTime_total_o->id = 3;
        if (db_define(Sigar_ProcTime_total_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::ProcTime::total'.");
            goto error;
        }
    }
    /* Declare ::Sigar::ProcTime::user */
    Sigar_ProcTime_user_o = db_declare(Sigar_ProcTime_o, "user", db_typedef(db_member_o));
    if (!Sigar_ProcTime_user_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::ProcTime::user'.");
        goto error;
    }

    /* Define ::Sigar::ProcTime::user */
    if (!db_checkState(Sigar_ProcTime_user_o, DB_DEFINED)) {
        Sigar_ProcTime_user_o->type = db_resolve_ext(Sigar_ProcTime_user_o, NULL, "::hyve::lang::uint64", FALSE, "element ::Sigar::ProcTime::user.type");
        Sigar_ProcTime_user_o->modifiers = 0x0;
        Sigar_ProcTime_user_o->state = 0x6;
        Sigar_ProcTime_user_o->weak = FALSE;
        Sigar_ProcTime_user_o->id = 1;
        if (db_define(Sigar_ProcTime_user_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::ProcTime::user'.");
            goto error;
        }
    }
    /* Define ::Sigar::ProcTime */
    if (!db_checkState(Sigar_ProcTime_o, DB_DEFINED)) {
        db_type(Sigar_ProcTime_o)->parentType = NULL;
        db_type(Sigar_ProcTime_o)->parentState = 0x0;
        db_interface(Sigar_ProcTime_o)->base = NULL;
        Sigar_ProcTime_o->baseAccess = 0x0;
        if (db_define(Sigar_ProcTime_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::ProcTime'.");
            goto error;
        }
    }
    /* Define ::Sigar::Process::time */
    if (!db_checkState(Sigar_Process_time_o, DB_DEFINED)) {
        Sigar_Process_time_o->type = db_resolve_ext(Sigar_Process_time_o, NULL, "::Sigar::ProcTime", FALSE, "element ::Sigar::Process::time.type");
        Sigar_Process_time_o->modifiers = 0x1;
        Sigar_Process_time_o->state = 0x6;
        Sigar_Process_time_o->weak = FALSE;
        Sigar_Process_time_o->id = 2;
        if (db_define(Sigar_Process_time_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::Process::time'.");
            goto error;
        }
    }
    /* Define ::Sigar::Process */
    if (!db_checkState(Sigar_Process_o, DB_DEFINED)) {
        db_type(Sigar_Process_o)->parentType = NULL;
        db_type(Sigar_Process_o)->parentState = 0x0;
        db_interface(Sigar_Process_o)->base = NULL;
        db_struct(Sigar_Process_o)->baseAccess = 0x0;
        Sigar_Process_o->implements.length = 0;
        Sigar_Process_o->implements.buffer = NULL;
        if (db_define(Sigar_Process_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::Process'.");
            goto error;
        }
    }
    /* Declare ::Sigar::Stats */
    Sigar_Stats_o = db_declare(Sigar_o, "Stats", db_typedef(db_bitmask_o));
    if (!Sigar_Stats_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::Stats'.");
        goto error;
    }

    /* Declare ::Sigar::Stats::CPU */
    Sigar_Stats_CPU_o = db_declare(Sigar_Stats_o, "CPU", db_typedef(db_constant_o));
    if (!Sigar_Stats_CPU_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::Stats::CPU'.");
        goto error;
    }

    /* Define ::Sigar::Stats::CPU */
    if (!db_checkState(Sigar_Stats_CPU_o, DB_DEFINED)) {
        (*Sigar_Stats_CPU_o) = 1;
        if (db_define(Sigar_Stats_CPU_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::Stats::CPU'.");
            goto error;
        }
    }
    /* Declare ::Sigar::Stats::CPU_INFO */
    Sigar_Stats_CPU_INFO_o = db_declare(Sigar_Stats_o, "CPU_INFO", db_typedef(db_constant_o));
    if (!Sigar_Stats_CPU_INFO_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::Stats::CPU_INFO'.");
        goto error;
    }

    /* Define ::Sigar::Stats::CPU_INFO */
    if (!db_checkState(Sigar_Stats_CPU_INFO_o, DB_DEFINED)) {
        (*Sigar_Stats_CPU_INFO_o) = 4;
        if (db_define(Sigar_Stats_CPU_INFO_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::Stats::CPU_INFO'.");
            goto error;
        }
    }
    /* Declare ::Sigar::Stats::CPU_LIST */
    Sigar_Stats_CPU_LIST_o = db_declare(Sigar_Stats_o, "CPU_LIST", db_typedef(db_constant_o));
    if (!Sigar_Stats_CPU_LIST_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::Stats::CPU_LIST'.");
        goto error;
    }

    /* Define ::Sigar::Stats::CPU_LIST */
    if (!db_checkState(Sigar_Stats_CPU_LIST_o, DB_DEFINED)) {
        (*Sigar_Stats_CPU_LIST_o) = 2;
        if (db_define(Sigar_Stats_CPU_LIST_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::Stats::CPU_LIST'.");
            goto error;
        }
    }
    /* Declare ::Sigar::Stats::FILE_SYSTEM_LIST */
    Sigar_Stats_FILE_SYSTEM_LIST_o = db_declare(Sigar_Stats_o, "FILE_SYSTEM_LIST", db_typedef(db_constant_o));
    if (!Sigar_Stats_FILE_SYSTEM_LIST_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::Stats::FILE_SYSTEM_LIST'.");
        goto error;
    }

    /* Define ::Sigar::Stats::FILE_SYSTEM_LIST */
    if (!db_checkState(Sigar_Stats_FILE_SYSTEM_LIST_o, DB_DEFINED)) {
        (*Sigar_Stats_FILE_SYSTEM_LIST_o) = 8192;
        if (db_define(Sigar_Stats_FILE_SYSTEM_LIST_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::Stats::FILE_SYSTEM_LIST'.");
            goto error;
        }
    }
    /* Declare ::Sigar::Stats::LOADAVG */
    Sigar_Stats_LOADAVG_o = db_declare(Sigar_Stats_o, "LOADAVG", db_typedef(db_constant_o));
    if (!Sigar_Stats_LOADAVG_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::Stats::LOADAVG'.");
        goto error;
    }

    /* Define ::Sigar::Stats::LOADAVG */
    if (!db_checkState(Sigar_Stats_LOADAVG_o, DB_DEFINED)) {
        (*Sigar_Stats_LOADAVG_o) = 64;
        if (db_define(Sigar_Stats_LOADAVG_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::Stats::LOADAVG'.");
            goto error;
        }
    }
    /* Declare ::Sigar::Stats::MEM */
    Sigar_Stats_MEM_o = db_declare(Sigar_Stats_o, "MEM", db_typedef(db_constant_o));
    if (!Sigar_Stats_MEM_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::Stats::MEM'.");
        goto error;
    }

    /* Define ::Sigar::Stats::MEM */
    if (!db_checkState(Sigar_Stats_MEM_o, DB_DEFINED)) {
        (*Sigar_Stats_MEM_o) = 8;
        if (db_define(Sigar_Stats_MEM_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::Stats::MEM'.");
            goto error;
        }
    }
    /* Declare ::Sigar::Stats::PROC_CPU */
    Sigar_Stats_PROC_CPU_o = db_declare(Sigar_Stats_o, "PROC_CPU", db_typedef(db_constant_o));
    if (!Sigar_Stats_PROC_CPU_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::Stats::PROC_CPU'.");
        goto error;
    }

    /* Define ::Sigar::Stats::PROC_CPU */
    if (!db_checkState(Sigar_Stats_PROC_CPU_o, DB_DEFINED)) {
        (*Sigar_Stats_PROC_CPU_o) = 2048;
        if (db_define(Sigar_Stats_PROC_CPU_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::Stats::PROC_CPU'.");
            goto error;
        }
    }
    /* Declare ::Sigar::Stats::PROC_EXE */
    Sigar_Stats_PROC_EXE_o = db_declare(Sigar_Stats_o, "PROC_EXE", db_typedef(db_constant_o));
    if (!Sigar_Stats_PROC_EXE_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::Stats::PROC_EXE'.");
        goto error;
    }

    /* Define ::Sigar::Stats::PROC_EXE */
    if (!db_checkState(Sigar_Stats_PROC_EXE_o, DB_DEFINED)) {
        (*Sigar_Stats_PROC_EXE_o) = 4096;
        if (db_define(Sigar_Stats_PROC_EXE_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::Stats::PROC_EXE'.");
            goto error;
        }
    }
    /* Declare ::Sigar::Stats::PROC_LIST */
    Sigar_Stats_PROC_LIST_o = db_declare(Sigar_Stats_o, "PROC_LIST", db_typedef(db_constant_o));
    if (!Sigar_Stats_PROC_LIST_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::Stats::PROC_LIST'.");
        goto error;
    }

    /* Define ::Sigar::Stats::PROC_LIST */
    if (!db_checkState(Sigar_Stats_PROC_LIST_o, DB_DEFINED)) {
        (*Sigar_Stats_PROC_LIST_o) = 128;
        if (db_define(Sigar_Stats_PROC_LIST_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::Stats::PROC_LIST'.");
            goto error;
        }
    }
    /* Declare ::Sigar::Stats::PROC_MEM */
    Sigar_Stats_PROC_MEM_o = db_declare(Sigar_Stats_o, "PROC_MEM", db_typedef(db_constant_o));
    if (!Sigar_Stats_PROC_MEM_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::Stats::PROC_MEM'.");
        goto error;
    }

    /* Define ::Sigar::Stats::PROC_MEM */
    if (!db_checkState(Sigar_Stats_PROC_MEM_o, DB_DEFINED)) {
        (*Sigar_Stats_PROC_MEM_o) = 512;
        if (db_define(Sigar_Stats_PROC_MEM_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::Stats::PROC_MEM'.");
            goto error;
        }
    }
    /* Declare ::Sigar::Stats::PROC_STAT */
    Sigar_Stats_PROC_STAT_o = db_declare(Sigar_Stats_o, "PROC_STAT", db_typedef(db_constant_o));
    if (!Sigar_Stats_PROC_STAT_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::Stats::PROC_STAT'.");
        goto error;
    }

    /* Define ::Sigar::Stats::PROC_STAT */
    if (!db_checkState(Sigar_Stats_PROC_STAT_o, DB_DEFINED)) {
        (*Sigar_Stats_PROC_STAT_o) = 256;
        if (db_define(Sigar_Stats_PROC_STAT_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::Stats::PROC_STAT'.");
            goto error;
        }
    }
    /* Declare ::Sigar::Stats::PROC_TIME */
    Sigar_Stats_PROC_TIME_o = db_declare(Sigar_Stats_o, "PROC_TIME", db_typedef(db_constant_o));
    if (!Sigar_Stats_PROC_TIME_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::Stats::PROC_TIME'.");
        goto error;
    }

    /* Define ::Sigar::Stats::PROC_TIME */
    if (!db_checkState(Sigar_Stats_PROC_TIME_o, DB_DEFINED)) {
        (*Sigar_Stats_PROC_TIME_o) = 1024;
        if (db_define(Sigar_Stats_PROC_TIME_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::Stats::PROC_TIME'.");
            goto error;
        }
    }
    /* Declare ::Sigar::Stats::SWAP */
    Sigar_Stats_SWAP_o = db_declare(Sigar_Stats_o, "SWAP", db_typedef(db_constant_o));
    if (!Sigar_Stats_SWAP_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::Stats::SWAP'.");
        goto error;
    }

    /* Define ::Sigar::Stats::SWAP */
    if (!db_checkState(Sigar_Stats_SWAP_o, DB_DEFINED)) {
        (*Sigar_Stats_SWAP_o) = 16;
        if (db_define(Sigar_Stats_SWAP_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::Stats::SWAP'.");
            goto error;
        }
    }
    /* Declare ::Sigar::Stats::UPTIME */
    Sigar_Stats_UPTIME_o = db_declare(Sigar_Stats_o, "UPTIME", db_typedef(db_constant_o));
    if (!Sigar_Stats_UPTIME_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::Stats::UPTIME'.");
        goto error;
    }

    /* Define ::Sigar::Stats::UPTIME */
    if (!db_checkState(Sigar_Stats_UPTIME_o, DB_DEFINED)) {
        (*Sigar_Stats_UPTIME_o) = 32;
        if (db_define(Sigar_Stats_UPTIME_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::Stats::UPTIME'.");
            goto error;
        }
    }
    /* Define ::Sigar::Stats */
    if (!db_checkState(Sigar_Stats_o, DB_DEFINED)) {
        if (db_define(Sigar_Stats_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::Stats'.");
            goto error;
        }
    }
    /* Define ::Sigar::Host::stats */
    if (!db_checkState(Sigar_Host_stats_o, DB_DEFINED)) {
        Sigar_Host_stats_o->type = db_resolve_ext(Sigar_Host_stats_o, NULL, "::Sigar::Stats", FALSE, "element ::Sigar::Host::stats.type");
        Sigar_Host_stats_o->modifiers = 0x0;
        Sigar_Host_stats_o->state = 0x6;
        Sigar_Host_stats_o->weak = FALSE;
        Sigar_Host_stats_o->id = 1;
        if (db_define(Sigar_Host_stats_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::Host::stats'.");
            goto error;
        }
    }
    /* Declare ::Sigar::SwapData */
    Sigar_SwapData_o = db_declare(Sigar_o, "SwapData", db_typedef(db_struct_o));
    if (!Sigar_SwapData_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::SwapData'.");
        goto error;
    }

    /* Declare ::Sigar::SwapData::free */
    Sigar_SwapData_free_o = db_declare(Sigar_SwapData_o, "free", db_typedef(db_member_o));
    if (!Sigar_SwapData_free_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::SwapData::free'.");
        goto error;
    }

    /* Define ::Sigar::SwapData::free */
    if (!db_checkState(Sigar_SwapData_free_o, DB_DEFINED)) {
        Sigar_SwapData_free_o->type = db_resolve_ext(Sigar_SwapData_free_o, NULL, "::hyve::lang::uint64", FALSE, "element ::Sigar::SwapData::free.type");
        Sigar_SwapData_free_o->modifiers = 0x0;
        Sigar_SwapData_free_o->state = 0x6;
        Sigar_SwapData_free_o->weak = FALSE;
        Sigar_SwapData_free_o->id = 2;
        if (db_define(Sigar_SwapData_free_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::SwapData::free'.");
            goto error;
        }
    }
    /* Declare ::Sigar::SwapData::page_in */
    Sigar_SwapData_page_in_o = db_declare(Sigar_SwapData_o, "page_in", db_typedef(db_member_o));
    if (!Sigar_SwapData_page_in_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::SwapData::page_in'.");
        goto error;
    }

    /* Define ::Sigar::SwapData::page_in */
    if (!db_checkState(Sigar_SwapData_page_in_o, DB_DEFINED)) {
        Sigar_SwapData_page_in_o->type = db_resolve_ext(Sigar_SwapData_page_in_o, NULL, "::hyve::lang::uint64", FALSE, "element ::Sigar::SwapData::page_in.type");
        Sigar_SwapData_page_in_o->modifiers = 0x0;
        Sigar_SwapData_page_in_o->state = 0x6;
        Sigar_SwapData_page_in_o->weak = FALSE;
        Sigar_SwapData_page_in_o->id = 3;
        if (db_define(Sigar_SwapData_page_in_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::SwapData::page_in'.");
            goto error;
        }
    }
    /* Declare ::Sigar::SwapData::page_out */
    Sigar_SwapData_page_out_o = db_declare(Sigar_SwapData_o, "page_out", db_typedef(db_member_o));
    if (!Sigar_SwapData_page_out_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::SwapData::page_out'.");
        goto error;
    }

    /* Define ::Sigar::SwapData::page_out */
    if (!db_checkState(Sigar_SwapData_page_out_o, DB_DEFINED)) {
        Sigar_SwapData_page_out_o->type = db_resolve_ext(Sigar_SwapData_page_out_o, NULL, "::hyve::lang::uint64", FALSE, "element ::Sigar::SwapData::page_out.type");
        Sigar_SwapData_page_out_o->modifiers = 0x0;
        Sigar_SwapData_page_out_o->state = 0x6;
        Sigar_SwapData_page_out_o->weak = FALSE;
        Sigar_SwapData_page_out_o->id = 4;
        if (db_define(Sigar_SwapData_page_out_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::SwapData::page_out'.");
            goto error;
        }
    }
    /* Declare ::Sigar::SwapData::total */
    Sigar_SwapData_total_o = db_declare(Sigar_SwapData_o, "total", db_typedef(db_member_o));
    if (!Sigar_SwapData_total_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::SwapData::total'.");
        goto error;
    }

    /* Define ::Sigar::SwapData::total */
    if (!db_checkState(Sigar_SwapData_total_o, DB_DEFINED)) {
        Sigar_SwapData_total_o->type = db_resolve_ext(Sigar_SwapData_total_o, NULL, "::hyve::lang::uint64", FALSE, "element ::Sigar::SwapData::total.type");
        Sigar_SwapData_total_o->modifiers = 0x0;
        Sigar_SwapData_total_o->state = 0x6;
        Sigar_SwapData_total_o->weak = FALSE;
        Sigar_SwapData_total_o->id = 0;
        if (db_define(Sigar_SwapData_total_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::SwapData::total'.");
            goto error;
        }
    }
    /* Declare ::Sigar::SwapData::used */
    Sigar_SwapData_used_o = db_declare(Sigar_SwapData_o, "used", db_typedef(db_member_o));
    if (!Sigar_SwapData_used_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::SwapData::used'.");
        goto error;
    }

    /* Define ::Sigar::SwapData::used */
    if (!db_checkState(Sigar_SwapData_used_o, DB_DEFINED)) {
        Sigar_SwapData_used_o->type = db_resolve_ext(Sigar_SwapData_used_o, NULL, "::hyve::lang::uint64", FALSE, "element ::Sigar::SwapData::used.type");
        Sigar_SwapData_used_o->modifiers = 0x0;
        Sigar_SwapData_used_o->state = 0x6;
        Sigar_SwapData_used_o->weak = FALSE;
        Sigar_SwapData_used_o->id = 1;
        if (db_define(Sigar_SwapData_used_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::SwapData::used'.");
            goto error;
        }
    }
    /* Define ::Sigar::SwapData */
    if (!db_checkState(Sigar_SwapData_o, DB_DEFINED)) {
        db_type(Sigar_SwapData_o)->parentType = NULL;
        db_type(Sigar_SwapData_o)->parentState = 0x0;
        db_interface(Sigar_SwapData_o)->base = NULL;
        Sigar_SwapData_o->baseAccess = 0x0;
        if (db_define(Sigar_SwapData_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::SwapData'.");
            goto error;
        }
    }
    /* Define ::Sigar::Host::swap */
    if (!db_checkState(Sigar_Host_swap_o, DB_DEFINED)) {
        Sigar_Host_swap_o->type = db_resolve_ext(Sigar_Host_swap_o, NULL, "::Sigar::SwapData", FALSE, "element ::Sigar::Host::swap.type");
        Sigar_Host_swap_o->modifiers = 0x5;
        Sigar_Host_swap_o->state = 0x6;
        Sigar_Host_swap_o->weak = FALSE;
        Sigar_Host_swap_o->id = 6;
        if (db_define(Sigar_Host_swap_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::Host::swap'.");
            goto error;
        }
    }
    /* Declare ::Sigar::Uptime */
    Sigar_Uptime_o = db_declare(Sigar_o, "Uptime", db_typedef(db_struct_o));
    if (!Sigar_Uptime_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::Uptime'.");
        goto error;
    }

    /* Declare ::Sigar::Uptime::uptime */
    Sigar_Uptime_uptime_o = db_declare(Sigar_Uptime_o, "uptime", db_typedef(db_member_o));
    if (!Sigar_Uptime_uptime_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::Uptime::uptime'.");
        goto error;
    }

    /* Define ::Sigar::Uptime::uptime */
    if (!db_checkState(Sigar_Uptime_uptime_o, DB_DEFINED)) {
        Sigar_Uptime_uptime_o->type = db_resolve_ext(Sigar_Uptime_uptime_o, NULL, "::hyve::lang::float64", FALSE, "element ::Sigar::Uptime::uptime.type");
        Sigar_Uptime_uptime_o->modifiers = 0x0;
        Sigar_Uptime_uptime_o->state = 0x6;
        Sigar_Uptime_uptime_o->weak = FALSE;
        Sigar_Uptime_uptime_o->id = 0;
        if (db_define(Sigar_Uptime_uptime_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::Uptime::uptime'.");
            goto error;
        }
    }
    /* Define ::Sigar::Uptime */
    if (!db_checkState(Sigar_Uptime_o, DB_DEFINED)) {
        db_type(Sigar_Uptime_o)->parentType = NULL;
        db_type(Sigar_Uptime_o)->parentState = 0x0;
        db_interface(Sigar_Uptime_o)->base = NULL;
        Sigar_Uptime_o->baseAccess = 0x0;
        if (db_define(Sigar_Uptime_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::Uptime'.");
            goto error;
        }
    }
    /* Define ::Sigar::Host::uptime */
    if (!db_checkState(Sigar_Host_uptime_o, DB_DEFINED)) {
        Sigar_Host_uptime_o->type = db_resolve_ext(Sigar_Host_uptime_o, NULL, "::Sigar::Uptime", FALSE, "element ::Sigar::Host::uptime.type");
        Sigar_Host_uptime_o->modifiers = 0x5;
        Sigar_Host_uptime_o->state = 0x6;
        Sigar_Host_uptime_o->weak = FALSE;
        Sigar_Host_uptime_o->id = 7;
        if (db_define(Sigar_Host_uptime_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::Host::uptime'.");
            goto error;
        }
    }
    /* Define ::Sigar::LoadAvg::loadavg */
    if (!db_checkState(Sigar_LoadAvg_loadavg_o, DB_DEFINED)) {
        Sigar_LoadAvg_loadavg_o->type = db_resolve_ext(Sigar_LoadAvg_loadavg_o, NULL, "::hyve::lang::array{::hyve::lang::float64,3,::hyve::lang::float64}", FALSE, "element ::Sigar::LoadAvg::loadavg.type");
        Sigar_LoadAvg_loadavg_o->modifiers = 0x0;
        Sigar_LoadAvg_loadavg_o->state = 0x6;
        Sigar_LoadAvg_loadavg_o->weak = FALSE;
        Sigar_LoadAvg_loadavg_o->id = 0;
        if (db_define(Sigar_LoadAvg_loadavg_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::LoadAvg::loadavg'.");
            goto error;
        }
    }
    /* Define ::Sigar::LoadAvg */
    if (!db_checkState(Sigar_LoadAvg_o, DB_DEFINED)) {
        db_type(Sigar_LoadAvg_o)->parentType = NULL;
        db_type(Sigar_LoadAvg_o)->parentState = 0x0;
        db_interface(Sigar_LoadAvg_o)->base = NULL;
        Sigar_LoadAvg_o->baseAccess = 0x0;
        if (db_define(Sigar_LoadAvg_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::LoadAvg'.");
            goto error;
        }
    }
    /* Define ::Sigar::Host::loadavg */
    if (!db_checkState(Sigar_Host_loadavg_o, DB_DEFINED)) {
        Sigar_Host_loadavg_o->type = db_resolve_ext(Sigar_Host_loadavg_o, NULL, "::Sigar::LoadAvg", FALSE, "element ::Sigar::Host::loadavg.type");
        Sigar_Host_loadavg_o->modifiers = 0x5;
        Sigar_Host_loadavg_o->state = 0x6;
        Sigar_Host_loadavg_o->weak = FALSE;
        Sigar_Host_loadavg_o->id = 8;
        if (db_define(Sigar_Host_loadavg_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::Host::loadavg'.");
            goto error;
        }
    }
    /* Declare ::Sigar::Host::construct(::Sigar::Host object) */
    Sigar_Host_construct_o = db_declare(Sigar_Host_o, "construct(::Sigar::Host object)", db_typedef(db_callback_o));
    if (!Sigar_Host_construct_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::Host::construct(::Sigar::Host object)'.");
        goto error;
    }

    /* Define ::Sigar::Host::construct(::Sigar::Host object) */
    if (!db_checkState(Sigar_Host_construct_o, DB_DEFINED)) {
        db_function(Sigar_Host_construct_o)->returnType = db_resolve_ext(Sigar_Host_construct_o, NULL, "::hyve::lang::int16", FALSE, "element ::Sigar::Host::construct(::Sigar::Host object).returnType");
        Sigar_Host_construct_o->delegate = db_resolve_ext(Sigar_Host_construct_o, NULL, "::hyve::lang::class::construct(lang::object object)", FALSE, "element ::Sigar::Host::construct(::Sigar::Host object).delegate");
        
        /* Bind Sigar_Host_construct_o with C-function */
        db_function(Sigar_Host_construct_o)->kind = DB_PROCEDURE_CDECL;
        db_int16 Sigar_Host_construct(Sigar_Host object);
        db_function(Sigar_Host_construct_o)->impl = (db_word)Sigar_Host_construct;
        if (db_define(Sigar_Host_construct_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::Host::construct(::Sigar::Host object)'.");
            goto error;
        }
    }
    /* Declare ::Sigar::Host::destruct(::Sigar::Host object) */
    Sigar_Host_destruct_o = db_declare(Sigar_Host_o, "destruct(::Sigar::Host object)", db_typedef(db_callback_o));
    if (!Sigar_Host_destruct_o) {
        db_error("Sigar_load: failed to declare object '::Sigar::Host::destruct(::Sigar::Host object)'.");
        goto error;
    }

    /* Define ::Sigar::Host::destruct(::Sigar::Host object) */
    if (!db_checkState(Sigar_Host_destruct_o, DB_DEFINED)) {
        db_function(Sigar_Host_destruct_o)->returnType = db_resolve_ext(Sigar_Host_destruct_o, NULL, "::hyve::lang::void", FALSE, "element ::Sigar::Host::destruct(::Sigar::Host object).returnType");
        Sigar_Host_destruct_o->delegate = db_resolve_ext(Sigar_Host_destruct_o, NULL, "::hyve::lang::class::destruct(lang::object object)", FALSE, "element ::Sigar::Host::destruct(::Sigar::Host object).delegate");
        
        /* Bind Sigar_Host_destruct_o with C-function */
        db_function(Sigar_Host_destruct_o)->kind = DB_PROCEDURE_CDECL;
        db_void Sigar_Host_destruct(Sigar_Host object);
        db_function(Sigar_Host_destruct_o)->impl = (db_word)Sigar_Host_destruct;
        if (db_define(Sigar_Host_destruct_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::Host::destruct(::Sigar::Host object)'.");
            goto error;
        }
    }
    /* Define ::Sigar::Host */
    if (!db_checkState(Sigar_Host_o, DB_DEFINED)) {
        db_type(Sigar_Host_o)->parentType = NULL;
        db_type(Sigar_Host_o)->parentState = 0x0;
        db_interface(Sigar_Host_o)->base = NULL;
        db_struct(Sigar_Host_o)->baseAccess = 0x0;
        Sigar_Host_o->implements.length = 0;
        Sigar_Host_o->implements.buffer = NULL;
        if (db_define(Sigar_Host_o)) {
            db_error("Sigar_load: failed to define object '::Sigar::Host'.");
            goto error;
        }
    }
    if (_a_) {
        db_free(_a_);
    }

    return 0;
error:
    return -1;
}
