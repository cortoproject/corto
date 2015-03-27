/* os__api.h
 *
 *    API convenience functions for C-language.
 *    This file contains generated code. Do not modify!
 */

#ifndef os__API_H
#define os__API_H

#include "os__type.h"
#include "cortex.h"

#ifdef __cplusplus
extern "C" {
#endif
/* ::cortex::os::thread */
os_thread os_thread__new(void);
os_thread os_thread__declare(cx_object _parent, cx_string _name);
int os_thread__define(os_thread _this);
os_thread os_thread__create(void);

/* ::cortex::os::time */
os_time os_time__new(void);
os_time os_time__declare(cx_object _parent, cx_string _name);
int os_time__define(os_time _this, cx_int32 seconds, cx_uint32 nanoseconds);
os_time os_time__create(cx_int32 seconds, cx_uint32 nanoseconds);

/* ::cortex::os::timer */
os_timer os_timer__new(void);
os_timer os_timer__declare(cx_object _parent, cx_string _name);
int os_timer__define(os_timer _this, cx_int32 sec, cx_uint32 nanosec);
os_timer os_timer__create(cx_int32 sec, cx_uint32 nanosec);


#ifdef __cplusplus
}
#endif
#endif

