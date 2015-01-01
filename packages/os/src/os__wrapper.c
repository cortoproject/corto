/* os__wrapper.c
 *
 * This file contains wrapper functions for ::cortex::os.
 */

#include "os.h"
#include "os__meta.h"

void __os_exit(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(result);
    os_exit(
        *(cx_bool*)args);
}

void __os_loadavg(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_float64*)result = os_loadavg(
        *(os_loadAvgKind*)args);
}

void __os_sleep(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(result);
    os_sleep(
        *(cx_uint32*)args,
        *(cx_uint32*)((intptr_t)args + sizeof(cx_uint32)));
}

void __os_system(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(result);
    os_system(
        *(cx_string*)args);
}

void __os_thread_construct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_int16*)result = os_thread_construct(
        *(os_thread*)args);
}

void __os_thread_destruct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(result);
    os_thread_destruct(
        *(os_thread*)args);
}

void __os_thread_join(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    CX_UNUSED(result);
    os_thread_join(
        *(os_thread*)args);
}

/* virtual ::cortex::os::thread::run() */
void os_thread_run(os_thread _this) {
    static cx_uint32 _methodId;
    cx_method _method;
    cx_interface _abstract;

    _abstract = cx_interface(cx_typeof(_this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = cx_interface_resolveMethodId(_abstract, "run()");
    }
    cx_assert(_methodId, "virtual method 'run()' not found in abstract '%s'", cx_nameof(_abstract));

    /* Lookup method-object. */
    _method = cx_interface_resolveMethodById(_abstract, _methodId);
    cx_assert(_method != NULL, "unresolved method '%s::run()@%d'", cx_nameof(_this), _methodId);

    cx_call(cx_function(_method), NULL, _this);
}

void __os_thread_start(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    CX_UNUSED(result);
    os_thread_start(
        *(os_thread*)args);
}

void __os_thread_stop(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    CX_UNUSED(result);
    os_thread_stop(
        *(os_thread*)args);
}

void __os_time_add(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(result);
    os_time_add(
        *(os_time*)args,
        *(os_time*)((intptr_t)args + sizeof(os_time)));
}

void __os_time_get(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    CX_UNUSED(result);
    os_time_get(
        *(os_time*)args);
}

void __os_time_sub(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(result);
    os_time_sub(
        *(os_time*)args,
        *(os_time*)((intptr_t)args + sizeof(os_time)));
}

void __os_time_toFloat(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_float64*)result = os_time_toFloat(
        *(os_time*)args);
}

void __os_timer_run(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    CX_UNUSED(result);
    os_timer_run(
        *(os_timer*)args);
}

void __os_timer_stop(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    CX_UNUSED(result);
    os_timer_stop(
        *(os_timer*)args);
}
