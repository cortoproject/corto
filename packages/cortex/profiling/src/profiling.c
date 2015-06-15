/* profiling.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "profiling.h"

/* $header() */

/* This key should always be read using profiling_key() */
static cx_threadKey profiling__key = 0;

cx_threadKey profiling_key() {
    if (!profiling__key) {
        if (cx_threadTlsKey(&profiling__key, (void(*)(void *))cx_llFree)) {
            cx_error("Cannot create profiling key");
        }
    }
    return profiling__key;
}

cx_ll profiling_stack() {
    cx_threadKey key = profiling_key();
    cx_ll ll = NULL;
    if (key) {
        ll = cx_threadTlsGet(key);
        if (!ll) {
            ll = cx_llNew();
            if (cx_threadTlsSet(key, ll)) {
                cx_llFree(ll);
                ll = NULL;
            }
        }
    }
    return ll;
}

// cx_uint64 profiling_timeToNanoS(const cx_time* t) {
//     cx_uint64 nanos = t->tv_sec * 1000000000 + t->tv_nsec;
//     return nanos;
// }




/* $end */

/* ::profiling::start() */
cx_void profiling_start(void) {
/* $begin(::profiling::start) */
    cx_time *startTimePtr = cx_malloc(sizeof(cx_time));
    cx_timeGet(startTimePtr);
    cx_ll ll = profiling_stack();
    cx_llInsert(ll, startTimePtr);
/* $end */
}

/* ::profiling::stop() */
cx_void profiling_stop(void) {
/* $begin(::profiling::stop) */
    cx_time *startTimePtr;
    cx_time stopTime;
    cx_time difference;
    cx_ll ll;
    cx_timeGet(&stopTime);
    ll = profiling_stack();
    startTimePtr = cx_llTakeFirst(ll);
    difference = cx_timeSub(stopTime, *startTimePtr);
    cx_dealloc(startTimePtr);
/* $end */
}
