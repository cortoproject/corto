/* os__meta.c
 *
 * Loads objects in database.
 * This file contains generated code. Do not modify!
 */

#include "os__type.h"

/* Variable definitions */
cx_object _o;
cx_package os_o;
cx_function os_exit_o;
cx_function os_sleep_o;
cx_function os_system_o;
cx_class os_thread_o;
cx_method os_thread_construct_o;
cx_method os_thread_destruct_o;
cx_member os_thread_handle_o;
cx_method os_thread_join_o;
cx_virtual os_thread_run_o;
cx_method os_thread_start_o;
cx_method os_thread_stop_o;
cx_member os_thread_stopping_o;
cx_class os_time_o;
cx_method os_time_add_o;
cx_method os_time_get_o;
cx_member os_time_nanoseconds_o;
cx_member os_time_seconds_o;
cx_method os_time_sub_o;
cx_method os_time_toFloat_o;
cx_class os_timer_o;
cx_member os_timer_nanosec_o;
cx_method os_timer_run_o;
cx_member os_timer_sec_o;
cx_method os_timer_stop_o;

/* Load objects in database */
int os_load(void) {
    cx_object _a_; /* Used for resolving anonymous objects */
    _a_ = NULL;

    /* Declare ::cortex */
    _o = cx_declare(root_o, "cortex", cx_type(cx_object_o));
    if (!_o) {
        cx_error("os_load: failed to declare object '::cortex'.");
        goto error;
    }

    /* Define ::cortex */
    if (!cx_checkState(_o, CX_DEFINED)) {
        if (cx_define(_o)) {
            cx_error("os_load: failed to define object '::cortex'.");
            goto error;
        }
    }

    /* Declare ::cortex::os */
    os_o = cx_declare(_o, "os", cx_type(cx_package_o));
    if (!os_o) {
        cx_error("os_load: failed to declare object '::cortex::os'.");
        goto error;
    }

    /* Define ::cortex::os */
    if (!cx_checkState(os_o, CX_DEFINED)) {
        os_o->url = NULL;
        if (cx_define(os_o)) {
            cx_error("os_load: failed to define object '::cortex::os'.");
            goto error;
        }
    }

    /* Declare ::cortex::os::exit(bool success) */
    os_exit_o = cx_declare(os_o, "exit(bool success)", cx_type(cx_function_o));
    if (!os_exit_o) {
        cx_error("os_load: failed to declare object '::cortex::os::exit(bool success)'.");
        goto error;
    }

    /* Define ::cortex::os::exit(bool success) */
    if (!cx_checkState(os_exit_o, CX_DEFINED)) {
        os_exit_o->returnType = cx_resolve_ext(os_exit_o, NULL, "::cortex::lang::void", FALSE, "element ::cortex::os::exit(bool success).returnType");
        os_exit_o->returnsReference = FALSE;
        
        /* Bind ::cortex::os::exit(bool success) with C-function */
        cx_function(os_exit_o)->kind = CX_PROCEDURE_CDECL;
        void __os_exit(void *args, void *result);
        cx_function(os_exit_o)->impl = (cx_word)__os_exit;
        if (cx_define(os_exit_o)) {
            cx_error("os_load: failed to define object '::cortex::os::exit(bool success)'.");
            goto error;
        }
    }

    /* Declare ::cortex::os::sleep(uint32 sec,uint32 nsec) */
    os_sleep_o = cx_declare(os_o, "sleep(uint32 sec,uint32 nsec)", cx_type(cx_function_o));
    if (!os_sleep_o) {
        cx_error("os_load: failed to declare object '::cortex::os::sleep(uint32 sec,uint32 nsec)'.");
        goto error;
    }

    /* Define ::cortex::os::sleep(uint32 sec,uint32 nsec) */
    if (!cx_checkState(os_sleep_o, CX_DEFINED)) {
        os_sleep_o->returnType = cx_resolve_ext(os_sleep_o, NULL, "::cortex::lang::void", FALSE, "element ::cortex::os::sleep(uint32 sec,uint32 nsec).returnType");
        os_sleep_o->returnsReference = FALSE;
        
        /* Bind ::cortex::os::sleep(uint32 sec,uint32 nsec) with C-function */
        cx_function(os_sleep_o)->kind = CX_PROCEDURE_CDECL;
        void __os_sleep(void *args, void *result);
        cx_function(os_sleep_o)->impl = (cx_word)__os_sleep;
        if (cx_define(os_sleep_o)) {
            cx_error("os_load: failed to define object '::cortex::os::sleep(uint32 sec,uint32 nsec)'.");
            goto error;
        }
    }

    /* Declare ::cortex::os::system(string cmd) */
    os_system_o = cx_declare(os_o, "system(string cmd)", cx_type(cx_function_o));
    if (!os_system_o) {
        cx_error("os_load: failed to declare object '::cortex::os::system(string cmd)'.");
        goto error;
    }

    /* Define ::cortex::os::system(string cmd) */
    if (!cx_checkState(os_system_o, CX_DEFINED)) {
        os_system_o->returnType = cx_resolve_ext(os_system_o, NULL, "::cortex::lang::void", FALSE, "element ::cortex::os::system(string cmd).returnType");
        os_system_o->returnsReference = FALSE;
        
        /* Bind ::cortex::os::system(string cmd) with C-function */
        cx_function(os_system_o)->kind = CX_PROCEDURE_CDECL;
        void __os_system(void *args, void *result);
        cx_function(os_system_o)->impl = (cx_word)__os_system;
        if (cx_define(os_system_o)) {
            cx_error("os_load: failed to define object '::cortex::os::system(string cmd)'.");
            goto error;
        }
    }

    /* Declare ::cortex::os::thread */
    os_thread_o = cx_declare(os_o, "thread", cx_type(cx_class_o));
    if (!os_thread_o) {
        cx_error("os_load: failed to declare object '::cortex::os::thread'.");
        goto error;
    }

    /* Declare ::cortex::os::thread::construct() */
    os_thread_construct_o = cx_declare(os_thread_o, "construct()", cx_type(cx_method_o));
    if (!os_thread_construct_o) {
        cx_error("os_load: failed to declare object '::cortex::os::thread::construct()'.");
        goto error;
    }

    /* Define ::cortex::os::thread::construct() */
    if (!cx_checkState(os_thread_construct_o, CX_DEFINED)) {
        cx_function(os_thread_construct_o)->returnType = cx_resolve_ext(os_thread_construct_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::os::thread::construct().returnType");
        cx_function(os_thread_construct_o)->returnsReference = FALSE;
        os_thread_construct_o->virtual = FALSE;
        
        /* Bind ::cortex::os::thread::construct() with C-function */
        cx_function(os_thread_construct_o)->kind = CX_PROCEDURE_CDECL;
        void __os_thread_construct(void *args, void *result);
        cx_function(os_thread_construct_o)->impl = (cx_word)__os_thread_construct;
        if (cx_define(os_thread_construct_o)) {
            cx_error("os_load: failed to define object '::cortex::os::thread::construct()'.");
            goto error;
        }
    }

    /* Declare ::cortex::os::thread::destruct() */
    os_thread_destruct_o = cx_declare(os_thread_o, "destruct()", cx_type(cx_method_o));
    if (!os_thread_destruct_o) {
        cx_error("os_load: failed to declare object '::cortex::os::thread::destruct()'.");
        goto error;
    }

    /* Define ::cortex::os::thread::destruct() */
    if (!cx_checkState(os_thread_destruct_o, CX_DEFINED)) {
        cx_function(os_thread_destruct_o)->returnType = cx_resolve_ext(os_thread_destruct_o, NULL, "::cortex::lang::void", FALSE, "element ::cortex::os::thread::destruct().returnType");
        cx_function(os_thread_destruct_o)->returnsReference = FALSE;
        os_thread_destruct_o->virtual = FALSE;
        
        /* Bind ::cortex::os::thread::destruct() with C-function */
        cx_function(os_thread_destruct_o)->kind = CX_PROCEDURE_CDECL;
        void __os_thread_destruct(void *args, void *result);
        cx_function(os_thread_destruct_o)->impl = (cx_word)__os_thread_destruct;
        if (cx_define(os_thread_destruct_o)) {
            cx_error("os_load: failed to define object '::cortex::os::thread::destruct()'.");
            goto error;
        }
    }

    /* Declare ::cortex::os::thread::handle */
    os_thread_handle_o = cx_declare(os_thread_o, "handle", cx_type(cx_member_o));
    if (!os_thread_handle_o) {
        cx_error("os_load: failed to declare object '::cortex::os::thread::handle'.");
        goto error;
    }

    /* Define ::cortex::os::thread::handle */
    if (!cx_checkState(os_thread_handle_o, CX_DEFINED)) {
        os_thread_handle_o->type = cx_resolve_ext(os_thread_handle_o, NULL, "::cortex::lang::word", FALSE, "element ::cortex::os::thread::handle.type");
        os_thread_handle_o->modifiers = 0x1;
        os_thread_handle_o->state = 0x6;
        os_thread_handle_o->weak = FALSE;
        os_thread_handle_o->id = 0;
        if (cx_define(os_thread_handle_o)) {
            cx_error("os_load: failed to define object '::cortex::os::thread::handle'.");
            goto error;
        }
    }

    /* Declare ::cortex::os::thread::join() */
    os_thread_join_o = cx_declare(os_thread_o, "join()", cx_type(cx_method_o));
    if (!os_thread_join_o) {
        cx_error("os_load: failed to declare object '::cortex::os::thread::join()'.");
        goto error;
    }

    /* Define ::cortex::os::thread::join() */
    if (!cx_checkState(os_thread_join_o, CX_DEFINED)) {
        cx_function(os_thread_join_o)->returnType = cx_resolve_ext(os_thread_join_o, NULL, "::cortex::lang::void", FALSE, "element ::cortex::os::thread::join().returnType");
        cx_function(os_thread_join_o)->returnsReference = FALSE;
        os_thread_join_o->virtual = FALSE;
        
        /* Bind ::cortex::os::thread::join() with C-function */
        cx_function(os_thread_join_o)->kind = CX_PROCEDURE_CDECL;
        void __os_thread_join(void *args, void *result);
        cx_function(os_thread_join_o)->impl = (cx_word)__os_thread_join;
        if (cx_define(os_thread_join_o)) {
            cx_error("os_load: failed to define object '::cortex::os::thread::join()'.");
            goto error;
        }
    }

    /* Declare ::cortex::os::thread::run() */
    os_thread_run_o = cx_declare(os_thread_o, "run()", cx_type(cx_virtual_o));
    if (!os_thread_run_o) {
        cx_error("os_load: failed to declare object '::cortex::os::thread::run()'.");
        goto error;
    }

    /* Define ::cortex::os::thread::run() */
    if (!cx_checkState(os_thread_run_o, CX_DEFINED)) {
        cx_function(os_thread_run_o)->returnType = cx_resolve_ext(os_thread_run_o, NULL, "::cortex::lang::void", FALSE, "element ::cortex::os::thread::run().returnType");
        cx_function(os_thread_run_o)->returnsReference = FALSE;
        cx_method(os_thread_run_o)->virtual = TRUE;
        
        if (cx_define(os_thread_run_o)) {
            cx_error("os_load: failed to define object '::cortex::os::thread::run()'.");
            goto error;
        }
    }

    /* Declare ::cortex::os::thread::start() */
    os_thread_start_o = cx_declare(os_thread_o, "start()", cx_type(cx_method_o));
    if (!os_thread_start_o) {
        cx_error("os_load: failed to declare object '::cortex::os::thread::start()'.");
        goto error;
    }

    /* Define ::cortex::os::thread::start() */
    if (!cx_checkState(os_thread_start_o, CX_DEFINED)) {
        cx_function(os_thread_start_o)->returnType = cx_resolve_ext(os_thread_start_o, NULL, "::cortex::lang::void", FALSE, "element ::cortex::os::thread::start().returnType");
        cx_function(os_thread_start_o)->returnsReference = FALSE;
        os_thread_start_o->virtual = FALSE;
        
        /* Bind ::cortex::os::thread::start() with C-function */
        cx_function(os_thread_start_o)->kind = CX_PROCEDURE_CDECL;
        void __os_thread_start(void *args, void *result);
        cx_function(os_thread_start_o)->impl = (cx_word)__os_thread_start;
        if (cx_define(os_thread_start_o)) {
            cx_error("os_load: failed to define object '::cortex::os::thread::start()'.");
            goto error;
        }
    }

    /* Declare ::cortex::os::thread::stop() */
    os_thread_stop_o = cx_declare(os_thread_o, "stop()", cx_type(cx_method_o));
    if (!os_thread_stop_o) {
        cx_error("os_load: failed to declare object '::cortex::os::thread::stop()'.");
        goto error;
    }

    /* Define ::cortex::os::thread::stop() */
    if (!cx_checkState(os_thread_stop_o, CX_DEFINED)) {
        cx_function(os_thread_stop_o)->returnType = cx_resolve_ext(os_thread_stop_o, NULL, "::cortex::lang::void", FALSE, "element ::cortex::os::thread::stop().returnType");
        cx_function(os_thread_stop_o)->returnsReference = FALSE;
        os_thread_stop_o->virtual = FALSE;
        
        /* Bind ::cortex::os::thread::stop() with C-function */
        cx_function(os_thread_stop_o)->kind = CX_PROCEDURE_CDECL;
        void __os_thread_stop(void *args, void *result);
        cx_function(os_thread_stop_o)->impl = (cx_word)__os_thread_stop;
        if (cx_define(os_thread_stop_o)) {
            cx_error("os_load: failed to define object '::cortex::os::thread::stop()'.");
            goto error;
        }
    }

    /* Declare ::cortex::os::thread::stopping */
    os_thread_stopping_o = cx_declare(os_thread_o, "stopping", cx_type(cx_member_o));
    if (!os_thread_stopping_o) {
        cx_error("os_load: failed to declare object '::cortex::os::thread::stopping'.");
        goto error;
    }

    /* Define ::cortex::os::thread::stopping */
    if (!cx_checkState(os_thread_stopping_o, CX_DEFINED)) {
        os_thread_stopping_o->type = cx_resolve_ext(os_thread_stopping_o, NULL, "::cortex::lang::bool", FALSE, "element ::cortex::os::thread::stopping.type");
        os_thread_stopping_o->modifiers = 0x2;
        os_thread_stopping_o->state = 0x6;
        os_thread_stopping_o->weak = FALSE;
        os_thread_stopping_o->id = 1;
        if (cx_define(os_thread_stopping_o)) {
            cx_error("os_load: failed to define object '::cortex::os::thread::stopping'.");
            goto error;
        }
    }

    /* Define ::cortex::os::thread */
    if (!cx_checkState(os_thread_o, CX_DEFINED)) {
        cx_type(os_thread_o)->defaultType = cx_resolve_ext(os_thread_o, NULL, "::cortex::lang::member", FALSE, "element ::cortex::os::thread.defaultType");
        cx_type(os_thread_o)->parentType = NULL;
        cx_type(os_thread_o)->parentState = 0x0;
        cx_interface(os_thread_o)->base = NULL;
        cx_struct(os_thread_o)->baseAccess = 0x0;
        os_thread_o->implements.length = 0;
        os_thread_o->implements.buffer = NULL;
        if (cx_define(os_thread_o)) {
            cx_error("os_load: failed to define object '::cortex::os::thread'.");
            goto error;
        }
    }

    if (cx_type(os_thread_o)->size != sizeof(struct os_thread_s)) {
        cx_error("os_load: calculated size '%d' of type '::cortex::os::thread' doesn't match C-type size '%d'", cx_type(os_thread_o)->size, sizeof(struct os_thread_s));
    }

    /* Declare ::cortex::os::time */
    os_time_o = cx_declare(os_o, "time", cx_type(cx_class_o));
    if (!os_time_o) {
        cx_error("os_load: failed to declare object '::cortex::os::time'.");
        goto error;
    }

    /* Declare ::cortex::os::time::get() */
    os_time_get_o = cx_declare(os_time_o, "get()", cx_type(cx_method_o));
    if (!os_time_get_o) {
        cx_error("os_load: failed to declare object '::cortex::os::time::get()'.");
        goto error;
    }

    /* Define ::cortex::os::time::get() */
    if (!cx_checkState(os_time_get_o, CX_DEFINED)) {
        cx_function(os_time_get_o)->returnType = cx_resolve_ext(os_time_get_o, NULL, "::cortex::lang::void", FALSE, "element ::cortex::os::time::get().returnType");
        cx_function(os_time_get_o)->returnsReference = FALSE;
        os_time_get_o->virtual = FALSE;
        
        /* Bind ::cortex::os::time::get() with C-function */
        cx_function(os_time_get_o)->kind = CX_PROCEDURE_CDECL;
        void __os_time_get(void *args, void *result);
        cx_function(os_time_get_o)->impl = (cx_word)__os_time_get;
        if (cx_define(os_time_get_o)) {
            cx_error("os_load: failed to define object '::cortex::os::time::get()'.");
            goto error;
        }
    }

    /* Declare ::cortex::os::time::nanoseconds */
    os_time_nanoseconds_o = cx_declare(os_time_o, "nanoseconds", cx_type(cx_member_o));
    if (!os_time_nanoseconds_o) {
        cx_error("os_load: failed to declare object '::cortex::os::time::nanoseconds'.");
        goto error;
    }

    /* Define ::cortex::os::time::nanoseconds */
    if (!cx_checkState(os_time_nanoseconds_o, CX_DEFINED)) {
        os_time_nanoseconds_o->type = cx_resolve_ext(os_time_nanoseconds_o, NULL, "::cortex::lang::uint32", FALSE, "element ::cortex::os::time::nanoseconds.type");
        os_time_nanoseconds_o->modifiers = 0x0;
        os_time_nanoseconds_o->state = 0x6;
        os_time_nanoseconds_o->weak = FALSE;
        os_time_nanoseconds_o->id = 1;
        if (cx_define(os_time_nanoseconds_o)) {
            cx_error("os_load: failed to define object '::cortex::os::time::nanoseconds'.");
            goto error;
        }
    }

    /* Declare ::cortex::os::time::seconds */
    os_time_seconds_o = cx_declare(os_time_o, "seconds", cx_type(cx_member_o));
    if (!os_time_seconds_o) {
        cx_error("os_load: failed to declare object '::cortex::os::time::seconds'.");
        goto error;
    }

    /* Define ::cortex::os::time::seconds */
    if (!cx_checkState(os_time_seconds_o, CX_DEFINED)) {
        os_time_seconds_o->type = cx_resolve_ext(os_time_seconds_o, NULL, "::cortex::lang::int32", FALSE, "element ::cortex::os::time::seconds.type");
        os_time_seconds_o->modifiers = 0x0;
        os_time_seconds_o->state = 0x6;
        os_time_seconds_o->weak = FALSE;
        os_time_seconds_o->id = 0;
        if (cx_define(os_time_seconds_o)) {
            cx_error("os_load: failed to define object '::cortex::os::time::seconds'.");
            goto error;
        }
    }

    /* Declare ::cortex::os::time::toFloat() */
    os_time_toFloat_o = cx_declare(os_time_o, "toFloat()", cx_type(cx_method_o));
    if (!os_time_toFloat_o) {
        cx_error("os_load: failed to declare object '::cortex::os::time::toFloat()'.");
        goto error;
    }

    /* Define ::cortex::os::time::toFloat() */
    if (!cx_checkState(os_time_toFloat_o, CX_DEFINED)) {
        cx_function(os_time_toFloat_o)->returnType = cx_resolve_ext(os_time_toFloat_o, NULL, "::cortex::lang::float64", FALSE, "element ::cortex::os::time::toFloat().returnType");
        cx_function(os_time_toFloat_o)->returnsReference = FALSE;
        os_time_toFloat_o->virtual = FALSE;
        
        /* Bind ::cortex::os::time::toFloat() with C-function */
        cx_function(os_time_toFloat_o)->kind = CX_PROCEDURE_CDECL;
        void __os_time_toFloat(void *args, void *result);
        cx_function(os_time_toFloat_o)->impl = (cx_word)__os_time_toFloat;
        if (cx_define(os_time_toFloat_o)) {
            cx_error("os_load: failed to define object '::cortex::os::time::toFloat()'.");
            goto error;
        }
    }

    /* Declare ::cortex::os::timer */
    os_timer_o = cx_declare(os_o, "timer", cx_type(cx_class_o));
    if (!os_timer_o) {
        cx_error("os_load: failed to declare object '::cortex::os::timer'.");
        goto error;
    }

    /* Declare ::cortex::os::timer::nanosec */
    os_timer_nanosec_o = cx_declare(os_timer_o, "nanosec", cx_type(cx_member_o));
    if (!os_timer_nanosec_o) {
        cx_error("os_load: failed to declare object '::cortex::os::timer::nanosec'.");
        goto error;
    }

    /* Define ::cortex::os::timer::nanosec */
    if (!cx_checkState(os_timer_nanosec_o, CX_DEFINED)) {
        os_timer_nanosec_o->type = cx_resolve_ext(os_timer_nanosec_o, NULL, "::cortex::lang::uint32", FALSE, "element ::cortex::os::timer::nanosec.type");
        os_timer_nanosec_o->modifiers = 0x0;
        os_timer_nanosec_o->state = 0x6;
        os_timer_nanosec_o->weak = FALSE;
        os_timer_nanosec_o->id = 1;
        if (cx_define(os_timer_nanosec_o)) {
            cx_error("os_load: failed to define object '::cortex::os::timer::nanosec'.");
            goto error;
        }
    }

    /* Declare ::cortex::os::timer::run() */
    os_timer_run_o = cx_declare(os_timer_o, "run()", cx_type(cx_method_o));
    if (!os_timer_run_o) {
        cx_error("os_load: failed to declare object '::cortex::os::timer::run()'.");
        goto error;
    }

    /* Define ::cortex::os::timer::run() */
    if (!cx_checkState(os_timer_run_o, CX_DEFINED)) {
        cx_function(os_timer_run_o)->returnType = cx_resolve_ext(os_timer_run_o, NULL, "::cortex::lang::void", FALSE, "element ::cortex::os::timer::run().returnType");
        cx_function(os_timer_run_o)->returnsReference = FALSE;
        os_timer_run_o->virtual = FALSE;
        
        /* Bind ::cortex::os::timer::run() with C-function */
        cx_function(os_timer_run_o)->kind = CX_PROCEDURE_CDECL;
        void __os_timer_run(void *args, void *result);
        cx_function(os_timer_run_o)->impl = (cx_word)__os_timer_run;
        if (cx_define(os_timer_run_o)) {
            cx_error("os_load: failed to define object '::cortex::os::timer::run()'.");
            goto error;
        }
    }

    /* Declare ::cortex::os::timer::sec */
    os_timer_sec_o = cx_declare(os_timer_o, "sec", cx_type(cx_member_o));
    if (!os_timer_sec_o) {
        cx_error("os_load: failed to declare object '::cortex::os::timer::sec'.");
        goto error;
    }

    /* Define ::cortex::os::timer::sec */
    if (!cx_checkState(os_timer_sec_o, CX_DEFINED)) {
        os_timer_sec_o->type = cx_resolve_ext(os_timer_sec_o, NULL, "::cortex::lang::int32", FALSE, "element ::cortex::os::timer::sec.type");
        os_timer_sec_o->modifiers = 0x0;
        os_timer_sec_o->state = 0x6;
        os_timer_sec_o->weak = FALSE;
        os_timer_sec_o->id = 0;
        if (cx_define(os_timer_sec_o)) {
            cx_error("os_load: failed to define object '::cortex::os::timer::sec'.");
            goto error;
        }
    }

    /* Declare ::cortex::os::timer::stop() */
    os_timer_stop_o = cx_declare(os_timer_o, "stop()", cx_type(cx_method_o));
    if (!os_timer_stop_o) {
        cx_error("os_load: failed to declare object '::cortex::os::timer::stop()'.");
        goto error;
    }

    /* Define ::cortex::os::timer::stop() */
    if (!cx_checkState(os_timer_stop_o, CX_DEFINED)) {
        cx_function(os_timer_stop_o)->returnType = cx_resolve_ext(os_timer_stop_o, NULL, "::cortex::lang::void", FALSE, "element ::cortex::os::timer::stop().returnType");
        cx_function(os_timer_stop_o)->returnsReference = FALSE;
        os_timer_stop_o->virtual = FALSE;
        
        /* Bind ::cortex::os::timer::stop() with C-function */
        cx_function(os_timer_stop_o)->kind = CX_PROCEDURE_CDECL;
        void __os_timer_stop(void *args, void *result);
        cx_function(os_timer_stop_o)->impl = (cx_word)__os_timer_stop;
        if (cx_define(os_timer_stop_o)) {
            cx_error("os_load: failed to define object '::cortex::os::timer::stop()'.");
            goto error;
        }
    }

    /* Define ::cortex::os::timer */
    if (!cx_checkState(os_timer_o, CX_DEFINED)) {
        cx_type(os_timer_o)->defaultType = cx_resolve_ext(os_timer_o, NULL, "::cortex::lang::member", FALSE, "element ::cortex::os::timer.defaultType");
        cx_type(os_timer_o)->parentType = NULL;
        cx_type(os_timer_o)->parentState = 0x0;
        cx_interface(os_timer_o)->base = cx_resolve_ext(os_timer_o, NULL, "::cortex::os::thread", FALSE, "element ::cortex::os::timer.base");
        cx_struct(os_timer_o)->baseAccess = 0x0;
        os_timer_o->implements.length = 0;
        os_timer_o->implements.buffer = NULL;
        if (cx_define(os_timer_o)) {
            cx_error("os_load: failed to define object '::cortex::os::timer'.");
            goto error;
        }
    }

    if (cx_type(os_timer_o)->size != sizeof(struct os_timer_s)) {
        cx_error("os_load: calculated size '%d' of type '::cortex::os::timer' doesn't match C-type size '%d'", cx_type(os_timer_o)->size, sizeof(struct os_timer_s));
    }

    /* Declare ::cortex::os::time::add(time t) */
    os_time_add_o = cx_declare(os_time_o, "add(time t)", cx_type(cx_method_o));
    if (!os_time_add_o) {
        cx_error("os_load: failed to declare object '::cortex::os::time::add(time t)'.");
        goto error;
    }

    /* Define ::cortex::os::time::add(time t) */
    if (!cx_checkState(os_time_add_o, CX_DEFINED)) {
        cx_function(os_time_add_o)->returnType = cx_resolve_ext(os_time_add_o, NULL, "::cortex::lang::void", FALSE, "element ::cortex::os::time::add(time t).returnType");
        cx_function(os_time_add_o)->returnsReference = FALSE;
        os_time_add_o->virtual = FALSE;
        
        /* Bind ::cortex::os::time::add(time t) with C-function */
        cx_function(os_time_add_o)->kind = CX_PROCEDURE_CDECL;
        void __os_time_add(void *args, void *result);
        cx_function(os_time_add_o)->impl = (cx_word)__os_time_add;
        if (cx_define(os_time_add_o)) {
            cx_error("os_load: failed to define object '::cortex::os::time::add(time t)'.");
            goto error;
        }
    }

    /* Declare ::cortex::os::time::sub(time t) */
    os_time_sub_o = cx_declare(os_time_o, "sub(time t)", cx_type(cx_method_o));
    if (!os_time_sub_o) {
        cx_error("os_load: failed to declare object '::cortex::os::time::sub(time t)'.");
        goto error;
    }

    /* Define ::cortex::os::time::sub(time t) */
    if (!cx_checkState(os_time_sub_o, CX_DEFINED)) {
        cx_function(os_time_sub_o)->returnType = cx_resolve_ext(os_time_sub_o, NULL, "::cortex::lang::void", FALSE, "element ::cortex::os::time::sub(time t).returnType");
        cx_function(os_time_sub_o)->returnsReference = FALSE;
        os_time_sub_o->virtual = FALSE;
        
        /* Bind ::cortex::os::time::sub(time t) with C-function */
        cx_function(os_time_sub_o)->kind = CX_PROCEDURE_CDECL;
        void __os_time_sub(void *args, void *result);
        cx_function(os_time_sub_o)->impl = (cx_word)__os_time_sub;
        if (cx_define(os_time_sub_o)) {
            cx_error("os_load: failed to define object '::cortex::os::time::sub(time t)'.");
            goto error;
        }
    }

    /* Define ::cortex::os::time */
    if (!cx_checkState(os_time_o, CX_DEFINED)) {
        cx_type(os_time_o)->defaultType = cx_resolve_ext(os_time_o, NULL, "::cortex::lang::member", FALSE, "element ::cortex::os::time.defaultType");
        cx_type(os_time_o)->parentType = NULL;
        cx_type(os_time_o)->parentState = 0x0;
        cx_interface(os_time_o)->base = NULL;
        cx_struct(os_time_o)->baseAccess = 0x0;
        os_time_o->implements.length = 0;
        os_time_o->implements.buffer = NULL;
        if (cx_define(os_time_o)) {
            cx_error("os_load: failed to define object '::cortex::os::time'.");
            goto error;
        }
    }

    if (cx_type(os_time_o)->size != sizeof(struct os_time_s)) {
        cx_error("os_load: calculated size '%d' of type '::cortex::os::time' doesn't match C-type size '%d'", cx_type(os_time_o)->size, sizeof(struct os_time_s));
    }

    if (_a_) {
        cx_free(_a_);
    }

    return 0;
error:
    return -1;
}
