/* os_thread.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef os_thread_H
#define os_thread_H

#include "corto.h"
#include "os__type.h"
#include "os__api.h"
#include "os__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto::os::thread::construct() */
cx_int16 _os_thread_construct(os_thread _this);
#define os_thread_construct(_this) _os_thread_construct(os_thread(_this))

/* ::corto::os::thread::destruct() */
cx_void _os_thread_destruct(os_thread _this);
#define os_thread_destruct(_this) _os_thread_destruct(os_thread(_this))

/* ::corto::os::thread::join() */
cx_void _os_thread_join(os_thread _this);
#define os_thread_join(_this) _os_thread_join(os_thread(_this))

/* virtual ::corto::os::thread::run() */
void os_thread_run(os_thread _this);

/* ::corto::os::thread::run() */
cx_void _os_thread_run_v(os_thread _this);
#define os_thread_run_v(_this) _os_thread_run_v(os_thread(_this))

/* ::corto::os::thread::start() */
cx_void _os_thread_start(os_thread _this);
#define os_thread_start(_this) _os_thread_start(os_thread(_this))

/* ::corto::os::thread::stop() */
cx_void _os_thread_stop(os_thread _this);
#define os_thread_stop(_this) _os_thread_stop(os_thread(_this))

#ifdef __cplusplus
}
#endif
#endif

