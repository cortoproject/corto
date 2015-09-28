/* profile.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "profile.h"

/* $header() */

#include "profile__keyvalue.h"

cx_threadKey profile_key = 0;

static void profile_clearTlsValue(void *data) {
    profile_TlsValue *value = data;
    cx_ll ll = value->ll;
    if (ll) {
        cx_llFree(ll);
    }
}

/*
 * topProfile can be a profile, the per-thread scope, or the root-scope
 */
static cx_object profile_profileRoot(void) {
    return root_o;
}

static profile_TlsValue *profile_value(void) {
    cx_threadKey key = profile_key;
    profile_TlsValue *value = cx_threadTlsGet(key);

    if (!value) {
        cx_thread tid;
        cx_id name;
        cx_ll ll;
        cx_object topProfile;
        
        tid = cx_threadSelf();
        sprintf(name, "t%lu", cx_threadSelf());
        ll = cx_llNew();
        topProfile = cx_declareChild(profile_profileRoot(), name, cx_void_o);
        if (ll && topProfile) {
            value = cx_alloc(sizeof(profile_TlsValue));
            value->ll = ll;
            value->topProfile = topProfile;
            cx_threadTlsSet(key, value);
        } else if (!ll) {
            cx_error("Could not create scope for Profile objects of thread %lu", tid);
            cx_release(topProfile);
        } else {
            cx_error("Could not create cx_ll object for profile start times");
            cx_llFree(ll);
        }
    }
    return value;
}

static void profile_openProfile(profile_TlsValue *value, cx_string name) {
    profile_Profile *next = cx_declareChild(value->topProfile, name, profile_Profile_o);
    value->topProfile = next;
}

static void profile_closeProfile(profile_TlsValue *value, cx_time t) {
    profile_Profile *top = value->topProfile;
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
    value->topProfile = cx_parentof(top);
}

/* $end */

/* ::corto::profile::start(string name) */
cx_void _profile_start(cx_string name) {
/* $begin(::corto::profile::start) */
    cx_time *startTimePtr = cx_alloc(sizeof(cx_time));
    profile_TlsValue *value = profile_value();
    cx_timeGet(startTimePtr);
    cx_llInsert(value->ll, startTimePtr);
    profile_openProfile(value, name);
/* $end */
}

/* ::corto::profile::stop() */
cx_void _profile_stop(void) {
/* $begin(::corto::profile::stop) */
    cx_time *startTimePtr;
    cx_time stopTime;
    cx_time difference;
    profile_TlsValue *value;
    value = profile_value();
    cx_timeGet(&stopTime);
    startTimePtr = cx_llTakeFirst(value->ll);
    difference = cx_timeSub(stopTime, *startTimePtr);
    cx_dealloc(startTimePtr);
    profile_closeProfile(value, difference);
/* $end */
}

int profileMain(int argc, char* argv[]) {
/* $begin(main) */
    CX_UNUSED(argc);
    CX_UNUSED(argv);
    if (cx_threadTlsKey(&profile_key, profile_clearTlsValue)) {
        cx_error("Cannot create profile key");
    }
    return 0;
/* $end */
}
