/* os_thread.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef os_thread_H
#define os_thread_H

#include "hyve.h"
#include "os__type.h"

#include "os__api.h"

#include "os__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* callback ::hyve::lang::class::construct(lang::object object) -> ::hyve::os::thread::construct(::hyve::os::thread object) */
db_int16 os_thread_construct(os_thread object);

/* callback ::hyve::lang::class::destruct(lang::object object) -> ::hyve::os::thread::destruct(::hyve::os::thread object) */
db_void os_thread_destruct(os_thread object);

/* ::hyve::os::thread::join() */
db_void os_thread_join(os_thread _this);

/* virtual ::hyve::os::thread::run() */
void os_thread_run(os_thread _this);

/* ::hyve::os::thread::run() */
db_void os_thread_run_v(os_thread _this);

/* ::hyve::os::thread::start() */
db_void os_thread_start(os_thread _this);

/* ::hyve::os::thread::stop() */
db_void os_thread_stop(os_thread _this);

#ifdef __cplusplus
}
#endif
#endif

