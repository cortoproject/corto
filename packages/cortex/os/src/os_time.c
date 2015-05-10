/* os_time.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "os.h"

/* $header() */
#include "cx_time.h"
/* $end */

/* ::cortex::os::time::add(time t) */
cx_void os_time_add(os_time _this, os_time t) {
/* $begin(::cortex::os::time::add) */
    cx_time t1, t2;

    /* Avoid type-punning warnings */
    t1.tv_sec = _this->seconds;
    t1.tv_nsec = _this->nanoseconds;
    t2.tv_sec = t->seconds;
    t2.tv_nsec = t->nanoseconds;

    /* Add times */
    t1 = cx_timeAdd(t1, t2);

    /* Copy values back to this */
    _this->seconds = t1.tv_sec;
    _this->nanoseconds = t1.tv_nsec;
/* $end */
}

/* ::cortex::os::time::get() */
cx_void os_time_get(os_time _this) {
/* $begin(::cortex::os::time::get) */

    cx_timeGet((cx_time*)_this); /* os_Time is equally formed as cx_time */

/* $end */
}

/* ::cortex::os::time::sub(time t) */
cx_void os_time_sub(os_time _this, os_time t) {
/* $begin(::cortex::os::time::sub) */
    cx_time t1, t2;

    /* Avoid type-punning warnings */
    t1.tv_sec = _this->seconds;
    t1.tv_nsec = _this->nanoseconds;
    t2.tv_sec = t->seconds;
    t2.tv_nsec = t->nanoseconds;

    /* Add times */
    t1 = cx_timeSub(t1, t2);

    /* Copy values back to this */
    _this->seconds = t1.tv_sec;
    _this->nanoseconds = t1.tv_nsec;
/* $end */
}

/* ::cortex::os::time::toFloat() */
cx_float64 os_time_toFloat(os_time _this) {
/* $begin(::cortex::os::time::toFloat) */
    cx_time t;

    t.tv_sec = _this->seconds;
    t.tv_nsec = _this->nanoseconds;

    return cx_timeToDouble(t);

/* $end */
}
