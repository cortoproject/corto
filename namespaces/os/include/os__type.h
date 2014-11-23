/* os__type.h
 *
 *  Generated on Feb  5 2014
 *    Type-definitions for C-language.
 *    This file contains generated code. Do not modify!
 */

#ifndef os__type_H
#define os__type_H

#include "hyve.h"
#ifdef __cplusplus
extern "C" {
#endif

/* Casting macro's for classes */
#define os_thread(o) ((os_thread)o)
#define os_time(o) ((os_time)o)
#define os_timer(o) ((os_timer)o)

/* Type definitions */

/* ::hyve::os::loadAvgKind */
typedef enum os_loadAvgKind {
    OS_MIN_1 = 0,
    OS_MIN_5 = 1,
    OS_MIN_15 = 2
} os_loadAvgKind;

/*  ::hyve::os::thread */
DB_CLASS(os_thread);
DB_CLASS_DEF(os_thread) {
    db_word handle;
    db_bool stopping;
};

/*  ::hyve::os::time */
DB_CLASS(os_time);
DB_CLASS_DEF(os_time) {
    db_int32 seconds;
    db_uint32 nanoseconds;
};

/*  ::hyve::os::timer */
DB_CLASS(os_timer);
DB_CLASS_DEF(os_timer) {
    DB_EXTEND(os_thread);
    db_int32 sec;
    db_uint32 nanosec;
};

#ifdef __cplusplus
}
#endif
#endif

