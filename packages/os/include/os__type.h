/* os__type.h
 *
 *    Type-definitions for C-language.
 *    This file contains generated code. Do not modify!
 */

#ifndef os__type_H
#define os__type_H

#include "cortex.h"
#ifdef __cplusplus
extern "C" {
#endif

/* Casting macro's for classes */
#define os_thread(o) ((os_thread)o)
#define os_time(o) ((os_time)o)
#define os_timer(o) ((os_timer)o)

/* Type definitions */

/* ::cortex::os::loadAvgKind */
typedef enum os_loadAvgKind {
    OS_MIN_1 = 0,
    OS_MIN_5 = 1,
    OS_MIN_15 = 2
} os_loadAvgKind;

/*  ::cortex::os::thread */
CX_CLASS(os_thread);
CX_CLASS_DEF(os_thread) {
    cx_word handle;
    cx_bool stopping;
};

/*  ::cortex::os::time */
CX_CLASS(os_time);
CX_CLASS_DEF(os_time) {
    cx_int32 seconds;
    cx_uint32 nanoseconds;
};

/*  ::cortex::os::timer */
CX_CLASS(os_timer);
CX_CLASS_DEF(os_timer) {
    CX_EXTEND(os_thread);
    cx_int32 sec;
    cx_uint32 nanosec;
};

#ifdef __cplusplus
}
#endif
#endif

