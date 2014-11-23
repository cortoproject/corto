/* Sigar__type.h
 *
 *  Generated on Feb  5 2014
 *    Type-definitions for C-language.
 *    This file contains generated code. Do not modify!
 */

#ifndef Sigar__type_H
#define Sigar__type_H

#include "hyve.h"
#ifdef __cplusplus
extern "C" {
#endif

/* Casting macro's for classes */
#define Sigar_Host(o) ((Sigar_Host)o)
#define Sigar_Process(o) ((Sigar_Process)o)

/* Type definitions */


/*  ::Sigar::CpuData */
typedef struct Sigar_CpuData Sigar_CpuData;
struct Sigar_CpuData {
    db_uint64 user;
    db_uint64 sys;
    db_uint64 nice;
    db_uint64 idle;
    db_uint64 _wait;
    db_uint64 irq;
    db_uint64 soft_irq;
    db_uint64 stolen;
    db_uint64 total;
};

/*  ::Sigar::CpuInfo */
typedef struct Sigar_CpuInfo Sigar_CpuInfo;
struct Sigar_CpuInfo {
    db_string vendor;
    db_string model;
    db_uint32 mhz;
    db_uint64 cache_size;
    db_uint32 total_sockets;
    db_uint32 total_cores;
    db_uint32 cores_per_socket;
};
/* ::Sigar::FileSystemType */
typedef enum Sigar_FileSystemType {
    SIGAR_UNKNOWN = 0,
    SIGAR_NONE = 1,
    SIGAR_LOCAL_DISK = 2,
    SIGAR_NETWORK = 3,
    SIGAR_RAM_DISK = 4,
    SIGAR_CDROM = 5,
    SIGAR_SWAP = 6,
    SIGAR_MAX = 7
} Sigar_FileSystemType;

/*  ::Sigar::FileSystem */
typedef struct Sigar_FileSystem Sigar_FileSystem;
struct Sigar_FileSystem {
    db_string dir_name;
    db_string dev_name;
    db_string type_name;
    db_string sys_type_name;
    db_string options;
    Sigar_FileSystemType type;
    db_int32 flags;
};
/* ::Sigar::Stats */
DB_BITMASK(Sigar_Stats);
#define SIGAR_CPU (0x1)
#define SIGAR_CPU_LIST (0x2)
#define SIGAR_CPU_INFO (0x4)
#define SIGAR_MEM (0x8)
#define SIGAR_SWAP (0x10)
#define SIGAR_UPTIME (0x20)
#define SIGAR_LOADAVG (0x40)
#define SIGAR_PROC_LIST (0x80)
#define SIGAR_PROC_STAT (0x100)
#define SIGAR_PROC_MEM (0x200)
#define SIGAR_PROC_TIME (0x400)
#define SIGAR_PROC_CPU (0x800)
#define SIGAR_PROC_EXE (0x1000)
#define SIGAR_FILE_SYSTEM_LIST (0x2000)
DB_LIST(Sigar_CpuData_list);
DB_LIST(Sigar_CpuInfo_list);

/*  ::Sigar::MemoryData */
typedef struct Sigar_MemoryData Sigar_MemoryData;
struct Sigar_MemoryData {
    db_uint64 ram;
    db_uint64 total;
    db_uint64 used;
    db_uint64 free;
    db_uint64 actual_used;
    db_uint64 actual_free;
    db_float64 used_percent;
    db_float64 free_percent;
};

/*  ::Sigar::SwapData */
typedef struct Sigar_SwapData Sigar_SwapData;
struct Sigar_SwapData {
    db_uint64 total;
    db_uint64 used;
    db_uint64 free;
    db_uint64 page_in;
    db_uint64 page_out;
};

/*  ::Sigar::Uptime */
typedef struct Sigar_Uptime Sigar_Uptime;
struct Sigar_Uptime {
    db_float64 uptime;
};
typedef db_float64 db_float64_array3[3];

/*  ::Sigar::LoadAvg */
typedef struct Sigar_LoadAvg Sigar_LoadAvg;
struct Sigar_LoadAvg {
    db_float64_array3 loadavg;
};
typedef db_uint64 Sigar_Pid;

/*  ::Sigar::ProcMem */
typedef struct Sigar_ProcMem Sigar_ProcMem;
struct Sigar_ProcMem {
    db_uint64 size;
    db_uint64 resident;
    db_uint64 share;
    db_uint64 minor_faults;
    db_uint64 major_faults;
    db_uint64 page_faults;
};

/*  ::Sigar::ProcTime */
typedef struct Sigar_ProcTime Sigar_ProcTime;
struct Sigar_ProcTime {
    db_uint64 start_time;
    db_uint64 user;
    db_uint64 sys;
    db_uint64 total;
};

/*  ::Sigar::ProcCpu */
typedef struct Sigar_ProcCpu Sigar_ProcCpu;
struct Sigar_ProcCpu {
    db_uint64 start_time;
    db_uint64 user;
    db_uint64 sys;
    db_uint64 total;
    db_uint64 last_time;
    db_float64 percent;
};

/*  ::Sigar::ProcExe */
typedef struct Sigar_ProcExe Sigar_ProcExe;
struct Sigar_ProcExe {
    db_string name;
    db_string cwd;
    db_string root;
};

/*  ::Sigar::Process */
DB_CLASS(Sigar_Process);
DB_CLASS_DEF(Sigar_Process) {
    Sigar_Pid pid;
    Sigar_ProcMem mem;
    Sigar_ProcTime time;
    Sigar_ProcCpu cpu;
    Sigar_ProcExe exe;
};
DB_LIST(Sigar_Process_list);

/*  ::Sigar::ProcStat */
typedef struct Sigar_ProcStat Sigar_ProcStat;
struct Sigar_ProcStat {
    db_uint64 total;
    db_uint64 sleeping;
    db_uint64 running;
    db_uint64 zombie;
    db_uint64 stopped;
    db_uint64 idle;
    db_uint64 threads;
};
DB_LIST(Sigar_FileSystem_list);

/*  ::Sigar::Host */
DB_CLASS(Sigar_Host);
DB_CLASS_DEF(Sigar_Host) {
    db_string name;
    Sigar_Stats stats;
    Sigar_CpuData cpu;
    Sigar_CpuData_list cpu_list;
    Sigar_CpuInfo_list cpu_info;
    Sigar_MemoryData memory;
    Sigar_SwapData swap;
    Sigar_Uptime uptime;
    Sigar_LoadAvg loadavg;
    Sigar_Process_list proc_list;
    Sigar_ProcStat proc_stat;
    Sigar_FileSystem_list file_system_list;
    db_word handle;
};

#ifdef __cplusplus
}
#endif
#endif

