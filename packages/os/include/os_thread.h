/* os_thread.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef os_thread_H
#define os_thread_H

#include "cortex.h"
#include "os__type.h"

#include "os__api.h"

#include "os__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::cortex::os::thread::construct() */
cx_int16 os_thread_construct(os_thread _this);

/* ::cortex::os::thread::destruct() */
cx_void os_thread_destruct(os_thread _this);

/* ::cortex::os::thread::join() */
cx_void os_thread_join(os_thread _this);

/* virtual ::cortex::os::thread::run() */
void os_thread_run(os_thread _this);

/* ::cortex::os::thread::run() */
cx_void os_thread_run_v(os_thread _this);

/* ::cortex::os::thread::start() */
cx_void os_thread_start(os_thread _this);

/* ::cortex::os::thread::stop() */
cx_void os_thread_stop(os_thread _this);

#ifdef __cplusplus
}
#endif
#endif

