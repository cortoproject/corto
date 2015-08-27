/* os_time.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef os_time_H
#define os_time_H

#include "corto.h"
#include "os__type.h"
#include "os__api.h"
#include "os__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto::os::time::add(::corto::os::time t) */
cx_void _os_time_add(os_time _this, os_time t);
#define os_time_add(_this, t) _os_time_add(os_time(_this), os_time(t))

/* ::corto::os::time::get() */
cx_void _os_time_get(os_time _this);
#define os_time_get(_this) _os_time_get(os_time(_this))

/* ::corto::os::time::sub(::corto::os::time t) */
cx_void _os_time_sub(os_time _this, os_time t);
#define os_time_sub(_this, t) _os_time_sub(os_time(_this), os_time(t))

/* ::corto::os::time::toFloat() */
cx_float64 _os_time_toFloat(os_time _this);
#define os_time_toFloat(_this) _os_time_toFloat(os_time(_this))

#ifdef __cplusplus
}
#endif
#endif

