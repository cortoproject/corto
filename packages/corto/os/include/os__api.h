/* os__api.h
 *
 * API convenience functions for C-language.
 * This file contains generated code. Do not modify!
 */

#ifndef os__API_H
#define os__API_H

#include "os__type.h"
#include "corto.h"

#ifdef __cplusplus
extern "C" {
#endif
/* ::corto::os::thread */
os_thread os_thread__create(void);
os_thread os_thread__createChild(cx_object _parent, cx_string _name);

os_thread os_thread__declare(void);
os_thread os_thread__declareChild(cx_object _parent, cx_string _name);
cx_int16 os_thread__define(os_thread _this);
void os_thread__update(os_thread _this);
void os_thread__set(os_thread _this);
cx_string os_thread__str(os_thread value);
os_thread os_thread__fromStr(os_thread value, cx_string str);
cx_int16 os_thread__copy(os_thread *dst, os_thread src);
cx_int16 os_thread__compare(os_thread dst, os_thread src);

/* ::corto::os::time */
os_time os_time__create(cx_int32 seconds, cx_uint32 nanoseconds);
os_time os_time__createChild(cx_object _parent, cx_string _name, cx_int32 seconds, cx_uint32 nanoseconds);

os_time os_time__declare(void);
os_time os_time__declareChild(cx_object _parent, cx_string _name);
cx_int16 os_time__define(os_time _this, cx_int32 seconds, cx_uint32 nanoseconds);
void os_time__update(os_time _this, cx_int32 seconds, cx_uint32 nanoseconds);
void os_time__set(os_time _this, cx_int32 seconds, cx_uint32 nanoseconds);
cx_string os_time__str(os_time value);
os_time os_time__fromStr(os_time value, cx_string str);
cx_int16 os_time__copy(os_time *dst, os_time src);
cx_int16 os_time__compare(os_time dst, os_time src);

/* ::corto::os::timer */
os_timer os_timer__create(cx_int32 sec, cx_uint32 nanosec);
os_timer os_timer__createChild(cx_object _parent, cx_string _name, cx_int32 sec, cx_uint32 nanosec);

os_timer os_timer__declare(void);
os_timer os_timer__declareChild(cx_object _parent, cx_string _name);
cx_int16 os_timer__define(os_timer _this, cx_int32 sec, cx_uint32 nanosec);
void os_timer__update(os_timer _this, cx_int32 sec, cx_uint32 nanosec);
void os_timer__set(os_timer _this, cx_int32 sec, cx_uint32 nanosec);
cx_string os_timer__str(os_timer value);
os_timer os_timer__fromStr(os_timer value, cx_string str);
cx_int16 os_timer__copy(os_timer *dst, os_timer src);
cx_int16 os_timer__compare(os_timer dst, os_timer src);


#ifdef __cplusplus
}
#endif
#endif

