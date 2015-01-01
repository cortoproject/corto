/* os_time.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "os.h"
#include "os__meta.h"

/* $header() */
#include "db_time.h"
/* $end */

/* ::cortex::os::time::add(::cortex::os::time t) */
db_void os_time_add(os_time _this, os_time t) {
/* $begin(::cortex::os::time::add) */
    db_time t1, t2;

    /* Avoid type-punning warnings */
    t1.tv_sec = _this->seconds;
    t1.tv_nsec = _this->nanoseconds;
    t2.tv_sec = t->seconds;
    t2.tv_nsec = t->nanoseconds;

    /* Add times */
    t1 = db_timeAdd(t1, t2);

    /* Copy values back to this */
    _this->seconds = t1.tv_sec;
    _this->nanoseconds = t1.tv_nsec;
/* $end */
}

/* ::cortex::os::time::get() */
db_void os_time_get(os_time _this) {
/* $begin(::cortex::os::time::get) */

    db_timeGet((db_time*)_this); /* os_Time is equally formed as db_time */

/* $end */
}

/* ::cortex::os::time::sub(::cortex::os::time t) */
db_void os_time_sub(os_time _this, os_time t) {
/* $begin(::cortex::os::time::sub) */
    db_time t1, t2;

    /* Avoid type-punning warnings */
    t1.tv_sec = _this->seconds;
    t1.tv_nsec = _this->nanoseconds;
    t2.tv_sec = t->seconds;
    t2.tv_nsec = t->nanoseconds;

    /* Add times */
    t1 = db_timeSub(t1, t2);

    /* Copy values back to this */
    _this->seconds = t1.tv_sec;
    _this->nanoseconds = t1.tv_nsec;
/* $end */
}

/* ::cortex::os::time::toFloat() */
db_float64 os_time_toFloat(os_time _this) {
/* $begin(::cortex::os::time::toFloat) */
    db_time t;

    t.tv_sec = _this->seconds;
    t.tv_nsec = _this->nanoseconds;

    return db_timeToDouble(t);

/* $end */
}
