/* $CORTO_GENERATED
 *
 * profile.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "profile.h"

/* $header() */

#include "profile__keyvalue.h"

corto_threadKey profile_key = 0;

static void profile_clearTlsValue(void *data) {
    profile_TlsValue *value = data;
    corto_ll ll = value->ll;
    if (ll) {
        corto_llFree(ll);
    }
}

/*
 * topProfile can be a profile, the per-thread scope, or the root-scope
 */
static corto_object profile_profileRoot(void) {
    return root_o;
}

static profile_TlsValue *profile_value(void) {
    corto_threadKey key = profile_key;
    profile_TlsValue *value = corto_threadTlsGet(key);

    if (!value) {
        corto_thread tid;
        corto_id name;
        corto_ll ll;
        corto_object topProfile;
        
        tid = corto_threadSelf();
        sprintf(name, "t%lu", corto_threadSelf());
        ll = corto_llNew();
        topProfile = corto_declareChild(profile_profileRoot(), name, corto_void_o);
        if (ll && topProfile) {
            value = corto_alloc(sizeof(profile_TlsValue));
            value->ll = ll;
            value->topProfile = topProfile;
            corto_threadTlsSet(key, value);
        } else if (!ll) {
            corto_error("Could not create scope for Profile objects of thread %lu", tid);
            corto_release(topProfile);
        } else {
            corto_error("Could not create corto_ll object for profile start times");
            corto_llFree(ll);
        }
    }
    return value;
}

static void profile_openProfile(profile_TlsValue *value, corto_string name) {
    profile_Profile *next = corto_declareChild(value->topProfile, name, profile_Profile_o);
    value->topProfile = next;
}

static void profile_closeProfile(profile_TlsValue *value, corto_time t) {
    profile_Profile *top = value->topProfile;
    if (corto_checkState(top, CORTO_DEFINED)) {
        top->seconds += t.tv_sec;
        top->nanoseconds += t.tv_nsec;
        top->callCount += 1;
    } else {
        top->seconds = t.tv_sec;
        top->nanoseconds = t.tv_nsec;
        top->callCount = 1;
        corto_define(top);
    }
    value->topProfile = corto_parentof(top);
}

/* $end */

corto_void _profile_start(corto_string name) {
/* $begin(::corto::profile::start) */
    corto_time *startTimePtr = corto_alloc(sizeof(corto_time));
    profile_TlsValue *value = profile_value();
    corto_timeGet(startTimePtr);
    corto_llInsert(value->ll, startTimePtr);
    profile_openProfile(value, name);
/* $end */
}

corto_void _profile_stop(void) {
/* $begin(::corto::profile::stop) */
    corto_time *startTimePtr;
    corto_time stopTime;
    corto_time difference;
    profile_TlsValue *value;
    value = profile_value();
    corto_timeGet(&stopTime);
    startTimePtr = corto_llTakeFirst(value->ll);
    difference = corto_timeSub(stopTime, *startTimePtr);
    corto_dealloc(startTimePtr);
    profile_closeProfile(value, difference);
/* $end */
}

int profileMain(int argc, char* argv[]) {
/* $begin(main) */
    CORTO_UNUSED(argc);
    CORTO_UNUSED(argv);
    if (corto_threadTlsKey(&profile_key, profile_clearTlsValue)) {
        corto_error("Cannot create profile key");
    }
    return 0;
/* $end */
}
