/* os_time.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef os_time_H
#define os_time_H

#include "cortex.h"
#include "os__type.h"

#include "os__api.h"

#include "os__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::cortex::os::time::add(time t) */
cx_void os_time_add(os_time _this, os_time t);

/* ::cortex::os::time::get() */
cx_void os_time_get(os_time _this);

/* ::cortex::os::time::sub(time t) */
cx_void os_time_sub(os_time _this, os_time t);

/* ::cortex::os::time::toFloat() */
cx_float64 os_time_toFloat(os_time _this);

#ifdef __cplusplus
}
#endif
#endif

