/* os_time.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "os.h"

/* $header() */
#include "corto_time.h"
/* $end */

/* ::corto::os::time::add(::corto::os::time t) */
corto_void _os_time_add(os_time this, os_time t) {
/* $begin(::corto::os::time::add) */
    corto_time t1, t2;

    /* Avoid type-punning warnings */
    t1.tv_sec = this->seconds;
    t1.tv_nsec = this->nanoseconds;
    t2.tv_sec = t->seconds;
    t2.tv_nsec = t->nanoseconds;

    /* Add times */
    t1 = corto_timeAdd(t1, t2);

    /* Copy values back to this */
    this->seconds = t1.tv_sec;
    this->nanoseconds = t1.tv_nsec;
/* $end */
}

/* ::corto::os::time::get() */
corto_void _os_time_get(os_time this) {
/* $begin(::corto::os::time::get) */

    corto_timeGet((corto_time*)this); /* os_Time is equally formed as corto_time */

/* $end */
}

/* ::corto::os::time::sub(::corto::os::time t) */
corto_void _os_time_sub(os_time this, os_time t) {
/* $begin(::corto::os::time::sub) */
    corto_time t1, t2;

    /* Avoid type-punning warnings */
    t1.tv_sec = this->seconds;
    t1.tv_nsec = this->nanoseconds;
    t2.tv_sec = t->seconds;
    t2.tv_nsec = t->nanoseconds;

    /* Add times */
    t1 = corto_timeSub(t1, t2);

    /* Copy values back to this */
    this->seconds = t1.tv_sec;
    this->nanoseconds = t1.tv_nsec;
/* $end */
}

/* ::corto::os::time::toFloat() */
corto_float64 _os_time_toFloat(os_time this) {
/* $begin(::corto::os::time::toFloat) */
    corto_time t;

    t.tv_sec = this->seconds;
    t.tv_nsec = this->nanoseconds;

    return corto_timeToDouble(t);

/* $end */
}
