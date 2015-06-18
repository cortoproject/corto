/* profiling.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "profiling.h"

/* $header() */

static cx_threadKey profiling_key(void) {
    static cx_threadKey key = 0;
    if (!key) {
        if (cx_threadTlsKey(&key, (void(*)(void *))cx_llFree)) {
            cx_error("Cannot create profiling key");
        }
    }
    return key;
}

static cx_ll profiling_stack(void) {
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

static cx_object profiling_profileRoot(void) {
    return profiling_o;
}

static cx_object profiling__topProfile = NULL;

/* TODO per thread */
/*
 * Returns the top of the profile stack, or if no profile has been yet declared,
 * the profiling package object.
 */
static cx_object profiling_topProfile(void) {
    if (!profiling__topProfile) {
        profiling__topProfile = profiling_profileRoot();
    }
    return profiling__topProfile;
}

/*
 * Declares the next profile and moves profiling__topProfile to match it.
 * Doesn't fail on profiles previously declared.
 */
static void profiling_openProfile(cx_string name) {
    profiling_Profile *next = cx_declare(profiling_topProfile(), name, cx_type(profiling_Profile_o));
    profiling__topProfile = next;
}

/*
 * Defines a profile (sets its members) and moves profiling__topProfile 
 * the previous profile. If the profile previously existed, it will add
 * the values.
 */
static void profiling_closeProfile(cx_time t) {
    profiling_Profile *top = profiling_topProfile();
    if (cx_checkState(top, CX_DEFINED)) {
        top->seconds += t.tv_sec;
        top->nanoseconds += t.tv_nsec;
        top->callCount += 1;
    } else {
        top->seconds = t.tv_sec;
        top->nanoseconds = t.tv_nsec;
        top->callCount = 1;
        cx_define(top);
    }
    profiling__topProfile = cx_parentof(top);
}

// cx_uint64 profiling_timeToNanoS(const cx_time* t) {
//     cx_uint64 nanos = t->tv_sec * 1000000000 + t->tv_nsec;
//     return nanos;
// }

/* $end */

/* ::cortex::profiling::start(string name) */
cx_void profiling_start(cx_string name) {
/* $begin(::cortex::profiling::start) */
    cx_time *startTimePtr = cx_malloc(sizeof(cx_time));
    cx_timeGet(startTimePtr);
    cx_ll ll = profiling_stack();
    cx_llInsert(ll, startTimePtr);
    CX_UNUSED(name);
/* $end */
}

/* ::cortex::profiling::stop() */
cx_void profiling_stop(void) {
/* $begin(::cortex::profiling::stop) */
    cx_time *startTimePtr;
    cx_time stopTime;
    cx_time difference;
    cx_ll ll;
    cx_timeGet(&stopTime);
    ll = profiling_stack();
    startTimePtr = cx_llTakeFirst(ll);
    difference = cx_timeSub(stopTime, *startTimePtr);
    printf("seconds: %d, nanos: %d\n", difference.tv_sec, difference.tv_nsec);
    cx_dealloc(startTimePtr);
/* $end */
}
