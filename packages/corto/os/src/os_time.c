/* os_time.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#define corto_os_LIB
#include "os.h"

/* $header() */
#include "cx_time.h"
/* $end */

/* ::corto::os::time::add(::corto::os::time t) */
cx_void _os_time_add(os_time this, os_time t) {
/* $begin(::corto::os::time::add) */
    cx_time t1, t2;

    /* Avoid type-punning warnings */
    t1.tv_sec = this->seconds;
    t1.tv_nsec = this->nanoseconds;
    t2.tv_sec = t->seconds;
    t2.tv_nsec = t->nanoseconds;

    /* Add times */
    t1 = cx_timeAdd(t1, t2);

    /* Copy values back to this */
    this->seconds = t1.tv_sec;
    this->nanoseconds = t1.tv_nsec;
/* $end */
}

/* ::corto::os::time::get() */
cx_void _os_time_get(os_time this) {
/* $begin(::corto::os::time::get) */

    cx_timeGet((cx_time*)this); /* os_Time is equally formed as cx_time */

/* $end */
}

/* ::corto::os::time::sub(::corto::os::time t) */
cx_void _os_time_sub(os_time this, os_time t) {
/* $begin(::corto::os::time::sub) */
    cx_time t1, t2;

    /* Avoid type-punning warnings */
    t1.tv_sec = this->seconds;
    t1.tv_nsec = this->nanoseconds;
    t2.tv_sec = t->seconds;
    t2.tv_nsec = t->nanoseconds;

    /* Add times */
    t1 = cx_timeSub(t1, t2);

    /* Copy values back to this */
    this->seconds = t1.tv_sec;
    this->nanoseconds = t1.tv_nsec;
/* $end */
}

/* ::corto::os::time::toFloat() */
cx_float64 _os_time_toFloat(os_time this) {
/* $begin(::corto::os::time::toFloat) */
    cx_time t;

    t.tv_sec = this->seconds;
    t.tv_nsec = this->nanoseconds;

    return cx_timeToDouble(t);

/* $end */
}
