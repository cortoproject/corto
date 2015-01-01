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
os_thread os_thread__declare(db_object _parent, db_string _name);
int os_thread__define(os_thread _this);
os_thread os_thread__create(void);

/* ::cortex::os::time */
os_time os_time__new(void);
os_time os_time__declare(db_object _parent, db_string _name);
int os_time__define(os_time _this, db_int32 seconds, db_uint32 nanoseconds);
os_time os_time__create(db_int32 seconds, db_uint32 nanoseconds);

/* ::cortex::os::timer */
os_timer os_timer__new(void);
os_timer os_timer__declare(db_object _parent, db_string _name);
int os_timer__define(os_timer _this, db_int32 sec, db_uint32 nanosec);
os_timer os_timer__create(db_int32 sec, db_uint32 nanosec);


#ifdef __cplusplus
}
#endif
#endif

