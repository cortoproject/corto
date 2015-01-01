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

/* callback ::cortex::lang::class::construct(lang::object object) -> ::cortex::os::thread::construct(::cortex::os::thread object) */
db_int16 os_thread_construct(os_thread object);

/* callback ::cortex::lang::class::destruct(lang::object object) -> ::cortex::os::thread::destruct(::cortex::os::thread object) */
db_void os_thread_destruct(os_thread object);

/* ::cortex::os::thread::join() */
db_void os_thread_join(os_thread _this);

/* virtual ::cortex::os::thread::run() */
void os_thread_run(os_thread _this);

/* ::cortex::os::thread::run() */
db_void os_thread_run_v(os_thread _this);

/* ::cortex::os::thread::start() */
db_void os_thread_start(os_thread _this);

/* ::cortex::os::thread::stop() */
db_void os_thread_stop(os_thread _this);

#ifdef __cplusplus
}
#endif
#endif

