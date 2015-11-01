/* $CORTO_GENERATED
 *
 * os_time.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "os.h"

/* $header() */
#include "corto_time.h"
/* $end */

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

corto_void _os_time_get(os_time this) {
/* $begin(::corto::os::time::get) */

    corto_timeGet((corto_time*)this); /* os_Time is equally formed as corto_time */

/* $end */
}

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

corto_float64 _os_time_toFloat(os_time this) {
/* $begin(::corto::os::time::toFloat) */
    corto_time t;

    t.tv_sec = this->seconds;
    t.tv_nsec = this->nanoseconds;

    return corto_timeToDouble(t);

/* $end */
}
