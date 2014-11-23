/* Sigar_Host.c
 *
 *  Generated on Feb  5 2014
 *    This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "Sigar_Host.h"
#include "Sigar__meta.h"


/* $begin($header) */
#include "Sigar__meta.h"
#include "Sigar__api.h"
#include "sigar.h"
#include "db_err.h"

static Sigar_Process Sigar_findProc(db_ll list, Sigar_Pid pid) {
    Sigar_Process p;
    db_iter iter;

    p = NULL;

    if (list) {
        iter = db_llIter(list);
        while(db_iterHasNext(&iter)) {
            p = db_iterNext(&iter);
            if (p->pid == pid) {
                break;
            } else {
                p = NULL;
            }
        }
    }

    return p;
}

/* $end */

/* callback ::hyve::lang::class::construct(lang::object object) -> ::Sigar::Host::construct(::Sigar::Host object) */
db_int16 Sigar_Host_construct(Sigar_Host object) {
/* $begin(::Sigar::Host::construct) */
    if (sigar_open((sigar_t**)&object->handle)) {
        db_error("Sigar::Host::construct: failed to open sigar handle.");
        goto error;
    }

    /* Update cpu-info, this information is static, and does not need to be refreshed each time. */
    if (object->stats & SIGAR_CPU_INFO) {
        sigar_cpu_info_list_t cpu_info;
        db_uint32 i;
        sigar_cpu_info_list_get((sigar_t*)object->handle, &cpu_info);
        object->cpu_info = db_llNew();

        for(i=0; i<cpu_info.number; i++) {
            Sigar_CpuInfo* info;
            info = db_malloc(db_type_sizeof(db_type(Sigar_CpuInfo_o)));
            info->vendor = db_strdup(cpu_info.data[i].vendor);
            info->model = db_strdup(cpu_info.data[i].model);
            info->mhz = cpu_info.data[i].mhz;
            info->cache_size = cpu_info.data[i].cache_size;
            info->total_sockets = cpu_info.data[i].total_sockets;
            info->total_cores = cpu_info.data[i].total_cores;
            info->cores_per_socket = cpu_info.data[i].cores_per_socket;
            db_llAppend(object->cpu_info, info);
        }

        /* Cleanup info-list */
        sigar_cpu_info_list_destroy((sigar_t*)object->handle, &cpu_info);
    }
    if (object->stats & SIGAR_FILE_SYSTEM_LIST) {
    	sigar_file_system_list_t file_sys;
    	db_uint32 i;
    	sigar_file_system_list_get((sigar_t*)object->handle, &file_sys);
    	object->file_system_list = db_llNew();

    	for(i=0; i<file_sys.number; i++) {
    		Sigar_FileSystem* fs;
    		fs = db_malloc(db_type_sizeof(db_type(Sigar_FileSystem_o)));
    		fs->dir_name = db_strdup(file_sys.data[i].dir_name);
    		fs->dev_name = db_strdup(file_sys.data[i].dev_name);
    		fs->type_name = db_strdup(file_sys.data[i].type_name);
    		fs->sys_type_name = db_strdup(file_sys.data[i].sys_type_name);
    		fs->options = db_strdup(file_sys.data[i].options);
    		fs->type = file_sys.data[i].type;
    		fs->flags = file_sys.data[i].flags;
    		db_llAppend(object->file_system_list, fs);
    	}
    }

    return 0;
error:
    return -1;
/* $end */
}

/* callback ::hyve::lang::class::destruct(lang::object object) -> ::Sigar::Host::destruct(::Sigar::Host object) */
db_void Sigar_Host_destruct(Sigar_Host object) {
/* $begin(::Sigar::Host::destruct) */
    if (sigar_close((sigar_t*)object->handle)) {
        db_error("Sigar::Host::destruct: failed to close sigar handle.");
    }
/* $end */
}

/* ::Sigar::Host::refresh() */
db_void Sigar_Host_refresh(Sigar_Host _this) {
/* $begin(::Sigar::Host::refresh) */
    int status;

    /* Lock object */
    /* Notify observers */
    if (db_checkAttr(_this, DB_ATTR_OBSERVABLE)) {
        db_updateBegin(_this);
    }

    /* Update cpu */
    if (_this->stats & SIGAR_CPU) {
        sigar_cpu_t cpu;
        sigar_cpu_get((sigar_t*)_this->handle, &cpu);
        _this->cpu.user = cpu.user;
        _this->cpu.sys = cpu.sys;
        _this->cpu.nice = cpu.nice;
        _this->cpu.idle = cpu.idle;
        _this->cpu._wait = cpu.wait;
        _this->cpu.irq = cpu.irq;
        _this->cpu.soft_irq = cpu.soft_irq;
        _this->cpu.stolen = cpu.stolen;
        _this->cpu.total = cpu.total;
    }

    /* Update cpu info */
    if (_this->stats & SIGAR_CPU_INFO) {
        db_iter iter;
        sigar_cpu_list_t cpu_list;
        db_uint32 i;
        sigar_cpu_list_get((sigar_t*)_this->handle, &cpu_list);

        /* If list did not exist, create it along with memory */
        if (!_this->cpu_list) {
            db_uint32 i;
            Sigar_CpuData* data;
            _this->cpu_list = db_llNew();
            for(i=0; i<cpu_list.number; i++) {
                data = db_malloc(db_type_sizeof(db_type(Sigar_CpuData_o)));
                db_llInsert(_this->cpu_list, data);
            }
        }

        iter = db_llIter(_this->cpu_list);
        for(i=0; i<cpu_list.number; i++) {
            Sigar_CpuData* data;
            if (db_iterHasNext(&iter)) {
                data = db_iterNext(&iter);
            } else {
                db_error("Sigar::Host::refresh: inconsistent number of cpu's (%d vs %d)", i, cpu_list.number);
                break;
            }
            data->user = cpu_list.data[i].user;
            data->sys = cpu_list.data[i].sys;
            data->nice = cpu_list.data[i].nice;
            data->idle = cpu_list.data[i].idle;
            data->_wait = cpu_list.data[i].wait;
            data->irq = cpu_list.data[i].irq;
            data->soft_irq = cpu_list.data[i].soft_irq;
            data->stolen = cpu_list.data[i].stolen;
            data->total = cpu_list.data[i].total;
        }
    }

    /* Update mem */
    if (_this->stats & SIGAR_MEM) {
        sigar_mem_t mem;
        sigar_mem_get((sigar_t*)_this->handle, &mem);
        _this->memory.ram = mem.ram;
        _this->memory.total = mem.total;
        _this->memory.used = mem.used;
        _this->memory.free = mem.free;
        _this->memory.actual_used = mem.actual_used;
        _this->memory.actual_free = mem.actual_free;
        _this->memory.used_percent = mem.used_percent;
        _this->memory.free_percent = mem.free_percent;
    }

    /* Update swap */
    if (_this->stats & SIGAR_SWAP) {
        sigar_swap_t swap;
        sigar_swap_get((sigar_t*)_this->handle, &swap);
        _this->swap.total = swap.total;
        _this->swap.used = swap.used;
        _this->swap.free = swap.free;
        _this->swap.page_in = swap.page_in;
        _this->swap.page_out = swap.page_out;
    }

    /* Update uptime */
    if (_this->stats & SIGAR_UPTIME) {
        sigar_uptime_t uptime;
        sigar_uptime_get((sigar_t*)_this->handle, &uptime);
        _this->uptime.uptime = uptime.uptime;
    }

    /* Update loadavg */
    if (_this->stats & SIGAR_LOADAVG) {
        sigar_loadavg_t loadavg;
        sigar_loadavg_get((sigar_t*)_this->handle, &loadavg);
        _this->loadavg.loadavg[0] = loadavg.loadavg[0];
        _this->loadavg.loadavg[1] = loadavg.loadavg[1];
        _this->loadavg.loadavg[2] = loadavg.loadavg[2];
    }

    /* Update proc statistics */
    if (_this->stats & SIGAR_PROC_STAT) {
        sigar_proc_stat_t proc_stat;
        sigar_proc_stat_get((sigar_t*)_this->handle, &proc_stat);
        _this->proc_stat.total = proc_stat.total;
        _this->proc_stat.sleeping = proc_stat.sleeping;
        _this->proc_stat.running = proc_stat.running;
        _this->proc_stat.zombie = proc_stat.zombie;
        _this->proc_stat.stopped = proc_stat.stopped;
        _this->proc_stat.idle = proc_stat.idle;
        _this->proc_stat.threads = proc_stat.threads;
    }

    /* Update process list */
    if (_this->stats & SIGAR_PROC_LIST) {
        sigar_proc_list_t proc_list;
        db_ll oldList;
        db_uint32 i;
        Sigar_Process p;
        db_iter iter;

        /* Obtain process-list */
        sigar_proc_list_get((sigar_t*)_this->handle, &proc_list);
        oldList = _this->proc_list;
        _this->proc_list = db_llNew();

        /* Add processes to list */
        for(i=0; i<proc_list.number; i++) {
            /* Find process in list */
            p = Sigar_findProc(oldList, proc_list.data[i]);
            if (!p) {
                p = Sigar_Process__create(proc_list.data[i]);
            } else {
                /* Remove process from oldlist, so it won't get removed in cleaning up lost processes */
                if (oldList) {
                    db_llRemove(oldList, p);
                }
            }
            /* Insert process in list */
            db_llInsert(_this->proc_list, p);
        }

        /* Remove old processes */
        if (oldList) {
            iter = db_llIter(oldList);
            while(db_iterHasNext(&iter)) {
                p = db_iterNext(&iter);
                db_free(p);
            }
            db_llFree(oldList);
        }

        /* Cleanup list */
        sigar_proc_list_destroy((sigar_t*)_this->handle, &proc_list);
    }


    /* Loop processes */
    if (_this->proc_list) {
        db_iter iter;
        Sigar_Process p;

        iter = db_llIter(_this->proc_list);
        while(db_iterHasNext(&iter)) {
            p = db_iterNext(&iter);

            if (_this->stats & SIGAR_PROC_MEM) {
                sigar_proc_mem_t proc_mem;
                if (sigar_proc_mem_get((sigar_t*)_this->handle, p->pid, &proc_mem)) {
                    db_error("Sigar::Host::refresh: failed to obtain process-memory statistics for pid %d", p->pid);
                }
                p->mem.size = proc_mem.size;
                p->mem.resident = proc_mem.resident;
                p->mem.share = proc_mem.share;
                p->mem.minor_faults = proc_mem.minor_faults;
                p->mem.major_faults = proc_mem.major_faults;
                p->mem.page_faults = proc_mem.page_faults;
            }

            if (_this->stats & SIGAR_PROC_TIME) {
                sigar_proc_time_t proc_time;
                if (sigar_proc_time_get((sigar_t*)_this->handle, p->pid, &proc_time)) {
                    db_error("Sigar::Host::refresh: failed to obtain process-time statistics for pid %d", p->pid);
                }
                p->time.start_time = proc_time.start_time;
                p->time.user = proc_time.user;
                p->time.sys = proc_time.sys;
                p->time.total = proc_time.total;
            }

            if (_this->stats & SIGAR_PROC_CPU) {
                sigar_proc_cpu_t proc_cpu;
                if (sigar_proc_cpu_get((sigar_t*)_this->handle, p->pid, &proc_cpu)) {
                    db_error("Sigar::Host::refresh: failed to obtain process-cpu statistics for pid %d", p->pid);
                }
                p->cpu.start_time = proc_cpu.start_time;
                p->cpu.user = proc_cpu.user;
                p->cpu.sys = proc_cpu.sys;
                p->cpu.total = proc_cpu.total;
                p->cpu.last_time = proc_cpu.last_time;
                p->cpu.percent = proc_cpu.percent;
            }
            if (_this->stats & SIGAR_PROC_EXE) {
                sigar_proc_exe_t proc_exe;
                if ((status = sigar_proc_exe_get((sigar_t*)_this->handle, p->pid, &proc_exe))) {
                    /* Silently ignore error - most likely a permission error. */
                } else {
                    p->exe.name = db_strdup(proc_exe.name);
                    p->exe.cwd = db_strdup(proc_exe.cwd);
                    p->exe.root = db_strdup(proc_exe.root);
                }
            }
        }
    } else {
        if (_this->stats & (SIGAR_PROC_MEM | SIGAR_PROC_TIME | SIGAR_PROC_CPU | SIGAR_PROC_EXE)) {
            db_error("Sigar::Host::refresh: PROC_MEM, PROC_TIME, PROC_CPU and/or PROC_EXE enabled without PROC_LIST.");
        }
    }

    /* Notify observers */
    if (db_checkAttr(_this, DB_ATTR_OBSERVABLE)) {
        db_updateEnd(_this);
    }

/* $end */
}
