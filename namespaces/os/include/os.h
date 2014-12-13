/* os.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef os_H
#define os_H

#include "hyve.h"
#include "os__type.h"

#include "os__api.h"

#include "os__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::hyve::os::exit(::hyve::lang::bool success) */
db_void os_exit(db_bool success);

/* ::hyve::os::loadavg(::hyve::os::loadAvgKind kind) */
db_float64 os_loadavg(os_loadAvgKind kind);

/* ::hyve::os::sleep(::hyve::lang::uint32 sec,::hyve::lang::uint32 nsec) */
db_void os_sleep(db_uint32 sec, db_uint32 nsec);

/* ::hyve::os::system(::hyve::lang::string cmd) */
db_void os_system(db_string cmd);

#ifdef __cplusplus
}
#endif
#endif

#include "os_thread.h"
#include "os_time.h"
#include "os_timer.h"
