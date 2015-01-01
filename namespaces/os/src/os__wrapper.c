/* os__wrapper.c
 *
 * This file contains wrapper functions for ::cortex::os.
 */

#include "os.h"
#include "os__meta.h"

void __os_exit(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(result);
    os_exit(
        *(db_bool*)args);
}

void __os_loadavg(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_float64*)result = os_loadavg(
        *(os_loadAvgKind*)args);
}

void __os_sleep(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(result);
    os_sleep(
        *(db_uint32*)args,
        *(db_uint32*)((intptr_t)args + sizeof(db_uint32)));
}

void __os_system(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(result);
    os_system(
        *(db_string*)args);
}

void __os_thread_construct(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_int16*)result = os_thread_construct(
        *(os_thread*)args);
}

void __os_thread_destruct(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(result);
    os_thread_destruct(
        *(os_thread*)args);
}

void __os_thread_join(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    DB_UNUSED(result);
    os_thread_join(
        *(os_thread*)args);
}

/* virtual ::cortex::os::thread::run() */
void os_thread_run(os_thread _this) {
    static db_uint32 _methodId;
    db_method _method;
    db_interface _abstract;

    _abstract = db_interface(db_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = db_interface_resolveMethodId(_abstract, "run()");
    }
    db_assert(_methodId, "virtual method 'run()' not found in abstract '%s'", db_nameof(_abstract));

    /* Lookup method-object. */
    _method = db_interface_resolveMethodById(_abstract, _methodId);
    db_assert(_method != NULL, "unresolved method '%s::run()@%d'", db_nameof(_this), _methodId);

    db_call(db_function(_method), NULL, _this);
}

void __os_thread_start(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    DB_UNUSED(result);
    os_thread_start(
        *(os_thread*)args);
}

void __os_thread_stop(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    DB_UNUSED(result);
    os_thread_stop(
        *(os_thread*)args);
}

void __os_time_add(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(result);
    os_time_add(
        *(os_time*)args,
        *(os_time*)((intptr_t)args + sizeof(os_time)));
}

void __os_time_get(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    DB_UNUSED(result);
    os_time_get(
        *(os_time*)args);
}

void __os_time_sub(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(result);
    os_time_sub(
        *(os_time*)args,
        *(os_time*)((intptr_t)args + sizeof(os_time)));
}

void __os_time_toFloat(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(db_float64*)result = os_time_toFloat(
        *(os_time*)args);
}

void __os_timer_run(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    DB_UNUSED(result);
    os_timer_run(
        *(os_timer*)args);
}

void __os_timer_stop(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    DB_UNUSED(result);
    os_timer_stop(
        *(os_timer*)args);
}
