/* os_time.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef os_time_H
#define os_time_H

#include "hyve.h"
#include "os__type.h"

#include "os__api.h"

#include "os__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::hyve::os::time::add(::hyve::os::time t) */
db_void os_time_add(os_time _this, os_time t);

/* ::hyve::os::time::get() */
db_void os_time_get(os_time _this);

/* ::hyve::os::time::sub(::hyve::os::time t) */
db_void os_time_sub(os_time _this, os_time t);

/* ::hyve::os::time::toFloat() */
db_float64 os_time_toFloat(os_time _this);

#ifdef __cplusplus
}
#endif
#endif

