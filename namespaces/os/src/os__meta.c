/* os__meta.c
 *
 * Loads objects in database.
 * This file contains generated code. Do not modify!
 */

#include "os__type.h"

/* Variable definitions */
db_object _o;
db_void (*os_o);
db_function os_exit_o;
db_function os_loadavg_o;
db_enum os_loadAvgKind_o;
db_constant (*os_loadAvgKind_MIN_1_o);
db_constant (*os_loadAvgKind_MIN_15_o);
db_constant (*os_loadAvgKind_MIN_5_o);
db_function os_sleep_o;
db_function os_system_o;
db_class os_thread_o;
db_callback os_thread_construct_o;
db_callback os_thread_destruct_o;
db_member os_thread_handle_o;
db_method os_thread_join_o;
db_virtual os_thread_run_o;
db_method os_thread_start_o;
db_method os_thread_stop_o;
db_member os_thread_stopping_o;
db_class os_time_o;
db_method os_time_add_o;
db_method os_time_get_o;
db_member os_time_nanoseconds_o;
db_member os_time_seconds_o;
db_method os_time_sub_o;
db_method os_time_toFloat_o;
db_class os_timer_o;
db_member os_timer_nanosec_o;
db_method os_timer_run_o;
db_member os_timer_sec_o;
db_method os_timer_stop_o;

/* Load objects in database */
int os_load(void) {
    db_object _a_; /* Used for resolving anonymous objects */
    _a_ = NULL;

    /* Declare ::hyve */
    _o = db_declare(root_o, "hyve", db_typedef(db_object_o));
    if (!_o) {
        db_error("os_load: failed to declare object '::hyve'.");
        goto error;
    }

    /* Define ::hyve */
    if (!db_checkState(_o, DB_DEFINED)) {
        if (db_define(_o)) {
            db_error("os_load: failed to define object '::hyve'.");
            goto error;
        }
    }
    /* Declare ::hyve::os */
    os_o = db_declare(_o, "os", db_typedef(db_void_o));
    if (!os_o) {
        db_error("os_load: failed to declare object '::hyve::os'.");
        goto error;
    }

    /* Declare ::hyve::os::exit(::hyve::lang::bool success) */
    os_exit_o = db_declare(os_o, "exit(::hyve::lang::bool success)", db_typedef(db_function_o));
    if (!os_exit_o) {
        db_error("os_load: failed to declare object '::hyve::os::exit(::hyve::lang::bool success)'.");
        goto error;
    }

    /* Define ::hyve::os::exit(::hyve::lang::bool success) */
    if (!db_checkState(os_exit_o, DB_DEFINED)) {
        os_exit_o->returnType = db_resolve_ext(os_exit_o, NULL, "::hyve::lang::void", FALSE, "element ::hyve::os::exit(::hyve::lang::bool success).returnType");
        os_exit_o->returnsReference = FALSE;
        
        /* Bind ::hyve::os::exit(::hyve::lang::bool success) with C-function */
        db_function(os_exit_o)->kind = DB_PROCEDURE_CDECL;
        void __os_exit(void *args, void *result);
        db_function(os_exit_o)->impl = (db_word)__os_exit;
        if (db_define(os_exit_o)) {
            db_error("os_load: failed to define object '::hyve::os::exit(::hyve::lang::bool success)'.");
            goto error;
        }
    }
    /* Declare ::hyve::os::loadAvgKind */
    os_loadAvgKind_o = db_declare(os_o, "loadAvgKind", db_typedef(db_enum_o));
    if (!os_loadAvgKind_o) {
        db_error("os_load: failed to declare object '::hyve::os::loadAvgKind'.");
        goto error;
    }

    /* Declare ::hyve::os::loadAvgKind::MIN_1 */
    os_loadAvgKind_MIN_1_o = db_declare(os_loadAvgKind_o, "MIN_1", db_typedef(db_constant_o));
    if (!os_loadAvgKind_MIN_1_o) {
        db_error("os_load: failed to declare object '::hyve::os::loadAvgKind::MIN_1'.");
        goto error;
    } else {
        (*os_loadAvgKind_MIN_1_o) = 0;
    }

    /* Define ::hyve::os::loadAvgKind::MIN_1 */
    if (!db_checkState(os_loadAvgKind_MIN_1_o, DB_DEFINED)) {
        if (db_define(os_loadAvgKind_MIN_1_o)) {
            db_error("os_load: failed to define object '::hyve::os::loadAvgKind::MIN_1'.");
            goto error;
        }
    }
    /* Declare ::hyve::os::loadAvgKind::MIN_15 */
    os_loadAvgKind_MIN_15_o = db_declare(os_loadAvgKind_o, "MIN_15", db_typedef(db_constant_o));
    if (!os_loadAvgKind_MIN_15_o) {
        db_error("os_load: failed to declare object '::hyve::os::loadAvgKind::MIN_15'.");
        goto error;
    } else {
        (*os_loadAvgKind_MIN_15_o) = 2;
    }

    /* Define ::hyve::os::loadAvgKind::MIN_15 */
    if (!db_checkState(os_loadAvgKind_MIN_15_o, DB_DEFINED)) {
        if (db_define(os_loadAvgKind_MIN_15_o)) {
            db_error("os_load: failed to define object '::hyve::os::loadAvgKind::MIN_15'.");
            goto error;
        }
    }
    /* Declare ::hyve::os::loadAvgKind::MIN_5 */
    os_loadAvgKind_MIN_5_o = db_declare(os_loadAvgKind_o, "MIN_5", db_typedef(db_constant_o));
    if (!os_loadAvgKind_MIN_5_o) {
        db_error("os_load: failed to declare object '::hyve::os::loadAvgKind::MIN_5'.");
        goto error;
    } else {
        (*os_loadAvgKind_MIN_5_o) = 1;
    }

    /* Define ::hyve::os::loadAvgKind::MIN_5 */
    if (!db_checkState(os_loadAvgKind_MIN_5_o, DB_DEFINED)) {
        if (db_define(os_loadAvgKind_MIN_5_o)) {
            db_error("os_load: failed to define object '::hyve::os::loadAvgKind::MIN_5'.");
            goto error;
        }
    }
    /* Define ::hyve::os::loadAvgKind */
    if (!db_checkState(os_loadAvgKind_o, DB_DEFINED)) {
        if (db_define(os_loadAvgKind_o)) {
            db_error("os_load: failed to define object '::hyve::os::loadAvgKind'.");
            goto error;
        }
    }
    if (db_type(os_loadAvgKind_o)->size != sizeof(os_loadAvgKind)) {
        db_error("os_load: calculated size '%d' of type '::hyve::os::loadAvgKind' doesn't match C-type size '%d'", db_type(os_loadAvgKind_o)->size, sizeof(os_loadAvgKind));
    }
    /* Declare ::hyve::os::loadavg(::hyve::os::loadAvgKind kind) */
    os_loadavg_o = db_declare(os_o, "loadavg(::hyve::os::loadAvgKind kind)", db_typedef(db_function_o));
    if (!os_loadavg_o) {
        db_error("os_load: failed to declare object '::hyve::os::loadavg(::hyve::os::loadAvgKind kind)'.");
        goto error;
    }

    /* Define ::hyve::os::loadavg(::hyve::os::loadAvgKind kind) */
    if (!db_checkState(os_loadavg_o, DB_DEFINED)) {
        os_loadavg_o->returnType = db_resolve_ext(os_loadavg_o, NULL, "::hyve::lang::float64", FALSE, "element ::hyve::os::loadavg(::hyve::os::loadAvgKind kind).returnType");
        os_loadavg_o->returnsReference = FALSE;
        
        /* Bind ::hyve::os::loadavg(::hyve::os::loadAvgKind kind) with C-function */
        db_function(os_loadavg_o)->kind = DB_PROCEDURE_CDECL;
        void __os_loadavg(void *args, void *result);
        db_function(os_loadavg_o)->impl = (db_word)__os_loadavg;
        if (db_define(os_loadavg_o)) {
            db_error("os_load: failed to define object '::hyve::os::loadavg(::hyve::os::loadAvgKind kind)'.");
            goto error;
        }
    }
    /* Declare ::hyve::os::sleep(::hyve::lang::uint32 sec,::hyve::lang::uint32 nsec) */
    os_sleep_o = db_declare(os_o, "sleep(::hyve::lang::uint32 sec,::hyve::lang::uint32 nsec)", db_typedef(db_function_o));
    if (!os_sleep_o) {
        db_error("os_load: failed to declare object '::hyve::os::sleep(::hyve::lang::uint32 sec,::hyve::lang::uint32 nsec)'.");
        goto error;
    }

    /* Define ::hyve::os::sleep(::hyve::lang::uint32 sec,::hyve::lang::uint32 nsec) */
    if (!db_checkState(os_sleep_o, DB_DEFINED)) {
        os_sleep_o->returnType = db_resolve_ext(os_sleep_o, NULL, "::hyve::lang::void", FALSE, "element ::hyve::os::sleep(::hyve::lang::uint32 sec,::hyve::lang::uint32 nsec).returnType");
        os_sleep_o->returnsReference = FALSE;
        
        /* Bind ::hyve::os::sleep(::hyve::lang::uint32 sec,::hyve::lang::uint32 nsec) with C-function */
        db_function(os_sleep_o)->kind = DB_PROCEDURE_CDECL;
        void __os_sleep(void *args, void *result);
        db_function(os_sleep_o)->impl = (db_word)__os_sleep;
        if (db_define(os_sleep_o)) {
            db_error("os_load: failed to define object '::hyve::os::sleep(::hyve::lang::uint32 sec,::hyve::lang::uint32 nsec)'.");
            goto error;
        }
    }
    /* Declare ::hyve::os::system(::hyve::lang::string cmd) */
    os_system_o = db_declare(os_o, "system(::hyve::lang::string cmd)", db_typedef(db_function_o));
    if (!os_system_o) {
        db_error("os_load: failed to declare object '::hyve::os::system(::hyve::lang::string cmd)'.");
        goto error;
    }

    /* Define ::hyve::os::system(::hyve::lang::string cmd) */
    if (!db_checkState(os_system_o, DB_DEFINED)) {
        os_system_o->returnType = db_resolve_ext(os_system_o, NULL, "::hyve::lang::void", FALSE, "element ::hyve::os::system(::hyve::lang::string cmd).returnType");
        os_system_o->returnsReference = FALSE;
        
        /* Bind ::hyve::os::system(::hyve::lang::string cmd) with C-function */
        db_function(os_system_o)->kind = DB_PROCEDURE_CDECL;
        void __os_system(void *args, void *result);
        db_function(os_system_o)->impl = (db_word)__os_system;
        if (db_define(os_system_o)) {
            db_error("os_load: failed to define object '::hyve::os::system(::hyve::lang::string cmd)'.");
            goto error;
        }
    }
    /* Declare ::hyve::os::thread */
    os_thread_o = db_declare(os_o, "thread", db_typedef(db_class_o));
    if (!os_thread_o) {
        db_error("os_load: failed to declare object '::hyve::os::thread'.");
        goto error;
    }

    /* Declare ::hyve::os::thread::handle */
    os_thread_handle_o = db_declare(os_thread_o, "handle", db_typedef(db_member_o));
    if (!os_thread_handle_o) {
        db_error("os_load: failed to declare object '::hyve::os::thread::handle'.");
        goto error;
    }

    /* Define ::hyve::os::thread::handle */
    if (!db_checkState(os_thread_handle_o, DB_DEFINED)) {
        os_thread_handle_o->type = db_resolve_ext(os_thread_handle_o, NULL, "::hyve::lang::word", FALSE, "element ::hyve::os::thread::handle.type");
        os_thread_handle_o->modifiers = 0x1;
        os_thread_handle_o->state = 0x6;
        os_thread_handle_o->weak = FALSE;
        os_thread_handle_o->id = 0;
        if (db_define(os_thread_handle_o)) {
            db_error("os_load: failed to define object '::hyve::os::thread::handle'.");
            goto error;
        }
    }
    /* Declare ::hyve::os::thread::join() */
    os_thread_join_o = db_declare(os_thread_o, "join()", db_typedef(db_method_o));
    if (!os_thread_join_o) {
        db_error("os_load: failed to declare object '::hyve::os::thread::join()'.");
        goto error;
    }

    /* Define ::hyve::os::thread::join() */
    if (!db_checkState(os_thread_join_o, DB_DEFINED)) {
        db_function(os_thread_join_o)->returnType = db_resolve_ext(os_thread_join_o, NULL, "::hyve::lang::void", FALSE, "element ::hyve::os::thread::join().returnType");
        db_function(os_thread_join_o)->returnsReference = FALSE;
        os_thread_join_o->virtual = FALSE;
        
        /* Bind ::hyve::os::thread::join() with C-function */
        db_function(os_thread_join_o)->kind = DB_PROCEDURE_CDECL;
        void __os_thread_join(void *args, void *result);
        db_function(os_thread_join_o)->impl = (db_word)__os_thread_join;
        if (db_define(os_thread_join_o)) {
            db_error("os_load: failed to define object '::hyve::os::thread::join()'.");
            goto error;
        }
    }
    /* Declare ::hyve::os::thread::run() */
    os_thread_run_o = db_declare(os_thread_o, "run()", db_typedef(db_virtual_o));
    if (!os_thread_run_o) {
        db_error("os_load: failed to declare object '::hyve::os::thread::run()'.");
        goto error;
    }

    /* Define ::hyve::os::thread::run() */
    if (!db_checkState(os_thread_run_o, DB_DEFINED)) {
        db_function(os_thread_run_o)->returnType = db_resolve_ext(os_thread_run_o, NULL, "::hyve::lang::void", FALSE, "element ::hyve::os::thread::run().returnType");
        db_function(os_thread_run_o)->returnsReference = FALSE;
        db_method(os_thread_run_o)->virtual = TRUE;
        
        if (db_define(os_thread_run_o)) {
            db_error("os_load: failed to define object '::hyve::os::thread::run()'.");
            goto error;
        }
    }
    /* Declare ::hyve::os::thread::start() */
    os_thread_start_o = db_declare(os_thread_o, "start()", db_typedef(db_method_o));
    if (!os_thread_start_o) {
        db_error("os_load: failed to declare object '::hyve::os::thread::start()'.");
        goto error;
    }

    /* Define ::hyve::os::thread::start() */
    if (!db_checkState(os_thread_start_o, DB_DEFINED)) {
        db_function(os_thread_start_o)->returnType = db_resolve_ext(os_thread_start_o, NULL, "::hyve::lang::void", FALSE, "element ::hyve::os::thread::start().returnType");
        db_function(os_thread_start_o)->returnsReference = FALSE;
        os_thread_start_o->virtual = FALSE;
        
        /* Bind ::hyve::os::thread::start() with C-function */
        db_function(os_thread_start_o)->kind = DB_PROCEDURE_CDECL;
        void __os_thread_start(void *args, void *result);
        db_function(os_thread_start_o)->impl = (db_word)__os_thread_start;
        if (db_define(os_thread_start_o)) {
            db_error("os_load: failed to define object '::hyve::os::thread::start()'.");
            goto error;
        }
    }
    /* Declare ::hyve::os::thread::stop() */
    os_thread_stop_o = db_declare(os_thread_o, "stop()", db_typedef(db_method_o));
    if (!os_thread_stop_o) {
        db_error("os_load: failed to declare object '::hyve::os::thread::stop()'.");
        goto error;
    }

    /* Define ::hyve::os::thread::stop() */
    if (!db_checkState(os_thread_stop_o, DB_DEFINED)) {
        db_function(os_thread_stop_o)->returnType = db_resolve_ext(os_thread_stop_o, NULL, "::hyve::lang::void", FALSE, "element ::hyve::os::thread::stop().returnType");
        db_function(os_thread_stop_o)->returnsReference = FALSE;
        os_thread_stop_o->virtual = FALSE;
        
        /* Bind ::hyve::os::thread::stop() with C-function */
        db_function(os_thread_stop_o)->kind = DB_PROCEDURE_CDECL;
        void __os_thread_stop(void *args, void *result);
        db_function(os_thread_stop_o)->impl = (db_word)__os_thread_stop;
        if (db_define(os_thread_stop_o)) {
            db_error("os_load: failed to define object '::hyve::os::thread::stop()'.");
            goto error;
        }
    }
    /* Declare ::hyve::os::thread::stopping */
    os_thread_stopping_o = db_declare(os_thread_o, "stopping", db_typedef(db_member_o));
    if (!os_thread_stopping_o) {
        db_error("os_load: failed to declare object '::hyve::os::thread::stopping'.");
        goto error;
    }

    /* Define ::hyve::os::thread::stopping */
    if (!db_checkState(os_thread_stopping_o, DB_DEFINED)) {
        os_thread_stopping_o->type = db_resolve_ext(os_thread_stopping_o, NULL, "::hyve::lang::bool", FALSE, "element ::hyve::os::thread::stopping.type");
        os_thread_stopping_o->modifiers = 0x2;
        os_thread_stopping_o->state = 0x6;
        os_thread_stopping_o->weak = FALSE;
        os_thread_stopping_o->id = 1;
        if (db_define(os_thread_stopping_o)) {
            db_error("os_load: failed to define object '::hyve::os::thread::stopping'.");
            goto error;
        }
    }
    /* Declare ::hyve::os::time */
    os_time_o = db_declare(os_o, "time", db_typedef(db_class_o));
    if (!os_time_o) {
        db_error("os_load: failed to declare object '::hyve::os::time'.");
        goto error;
    }

    /* Declare ::hyve::os::time::get() */
    os_time_get_o = db_declare(os_time_o, "get()", db_typedef(db_method_o));
    if (!os_time_get_o) {
        db_error("os_load: failed to declare object '::hyve::os::time::get()'.");
        goto error;
    }

    /* Define ::hyve::os::time::get() */
    if (!db_checkState(os_time_get_o, DB_DEFINED)) {
        db_function(os_time_get_o)->returnType = db_resolve_ext(os_time_get_o, NULL, "::hyve::lang::void", FALSE, "element ::hyve::os::time::get().returnType");
        db_function(os_time_get_o)->returnsReference = FALSE;
        os_time_get_o->virtual = FALSE;
        
        /* Bind ::hyve::os::time::get() with C-function */
        db_function(os_time_get_o)->kind = DB_PROCEDURE_CDECL;
        void __os_time_get(void *args, void *result);
        db_function(os_time_get_o)->impl = (db_word)__os_time_get;
        if (db_define(os_time_get_o)) {
            db_error("os_load: failed to define object '::hyve::os::time::get()'.");
            goto error;
        }
    }
    /* Declare ::hyve::os::time::nanoseconds */
    os_time_nanoseconds_o = db_declare(os_time_o, "nanoseconds", db_typedef(db_member_o));
    if (!os_time_nanoseconds_o) {
        db_error("os_load: failed to declare object '::hyve::os::time::nanoseconds'.");
        goto error;
    }

    /* Define ::hyve::os::time::nanoseconds */
    if (!db_checkState(os_time_nanoseconds_o, DB_DEFINED)) {
        os_time_nanoseconds_o->type = db_resolve_ext(os_time_nanoseconds_o, NULL, "::hyve::lang::uint32", FALSE, "element ::hyve::os::time::nanoseconds.type");
        os_time_nanoseconds_o->modifiers = 0x0;
        os_time_nanoseconds_o->state = 0x6;
        os_time_nanoseconds_o->weak = FALSE;
        os_time_nanoseconds_o->id = 1;
        if (db_define(os_time_nanoseconds_o)) {
            db_error("os_load: failed to define object '::hyve::os::time::nanoseconds'.");
            goto error;
        }
    }
    /* Declare ::hyve::os::time::seconds */
    os_time_seconds_o = db_declare(os_time_o, "seconds", db_typedef(db_member_o));
    if (!os_time_seconds_o) {
        db_error("os_load: failed to declare object '::hyve::os::time::seconds'.");
        goto error;
    }

    /* Define ::hyve::os::time::seconds */
    if (!db_checkState(os_time_seconds_o, DB_DEFINED)) {
        os_time_seconds_o->type = db_resolve_ext(os_time_seconds_o, NULL, "::hyve::lang::int32", FALSE, "element ::hyve::os::time::seconds.type");
        os_time_seconds_o->modifiers = 0x0;
        os_time_seconds_o->state = 0x6;
        os_time_seconds_o->weak = FALSE;
        os_time_seconds_o->id = 0;
        if (db_define(os_time_seconds_o)) {
            db_error("os_load: failed to define object '::hyve::os::time::seconds'.");
            goto error;
        }
    }
    /* Declare ::hyve::os::time::toFloat() */
    os_time_toFloat_o = db_declare(os_time_o, "toFloat()", db_typedef(db_method_o));
    if (!os_time_toFloat_o) {
        db_error("os_load: failed to declare object '::hyve::os::time::toFloat()'.");
        goto error;
    }

    /* Define ::hyve::os::time::toFloat() */
    if (!db_checkState(os_time_toFloat_o, DB_DEFINED)) {
        db_function(os_time_toFloat_o)->returnType = db_resolve_ext(os_time_toFloat_o, NULL, "::hyve::lang::float64", FALSE, "element ::hyve::os::time::toFloat().returnType");
        db_function(os_time_toFloat_o)->returnsReference = FALSE;
        os_time_toFloat_o->virtual = FALSE;
        
        /* Bind ::hyve::os::time::toFloat() with C-function */
        db_function(os_time_toFloat_o)->kind = DB_PROCEDURE_CDECL;
        void __os_time_toFloat(void *args, void *result);
        db_function(os_time_toFloat_o)->impl = (db_word)__os_time_toFloat;
        if (db_define(os_time_toFloat_o)) {
            db_error("os_load: failed to define object '::hyve::os::time::toFloat()'.");
            goto error;
        }
    }
    /* Declare ::hyve::os::timer */
    os_timer_o = db_declare(os_o, "timer", db_typedef(db_class_o));
    if (!os_timer_o) {
        db_error("os_load: failed to declare object '::hyve::os::timer'.");
        goto error;
    }

    /* Declare ::hyve::os::timer::nanosec */
    os_timer_nanosec_o = db_declare(os_timer_o, "nanosec", db_typedef(db_member_o));
    if (!os_timer_nanosec_o) {
        db_error("os_load: failed to declare object '::hyve::os::timer::nanosec'.");
        goto error;
    }

    /* Define ::hyve::os::timer::nanosec */
    if (!db_checkState(os_timer_nanosec_o, DB_DEFINED)) {
        os_timer_nanosec_o->type = db_resolve_ext(os_timer_nanosec_o, NULL, "::hyve::lang::uint32", FALSE, "element ::hyve::os::timer::nanosec.type");
        os_timer_nanosec_o->modifiers = 0x0;
        os_timer_nanosec_o->state = 0x6;
        os_timer_nanosec_o->weak = FALSE;
        os_timer_nanosec_o->id = 1;
        if (db_define(os_timer_nanosec_o)) {
            db_error("os_load: failed to define object '::hyve::os::timer::nanosec'.");
            goto error;
        }
    }
    /* Declare ::hyve::os::timer::sec */
    os_timer_sec_o = db_declare(os_timer_o, "sec", db_typedef(db_member_o));
    if (!os_timer_sec_o) {
        db_error("os_load: failed to declare object '::hyve::os::timer::sec'.");
        goto error;
    }

    /* Define ::hyve::os::timer::sec */
    if (!db_checkState(os_timer_sec_o, DB_DEFINED)) {
        os_timer_sec_o->type = db_resolve_ext(os_timer_sec_o, NULL, "::hyve::lang::int32", FALSE, "element ::hyve::os::timer::sec.type");
        os_timer_sec_o->modifiers = 0x0;
        os_timer_sec_o->state = 0x6;
        os_timer_sec_o->weak = FALSE;
        os_timer_sec_o->id = 0;
        if (db_define(os_timer_sec_o)) {
            db_error("os_load: failed to define object '::hyve::os::timer::sec'.");
            goto error;
        }
    }
    /* Declare ::hyve::os::time::add(::hyve::os::time t) */
    os_time_add_o = db_declare(os_time_o, "add(::hyve::os::time t)", db_typedef(db_method_o));
    if (!os_time_add_o) {
        db_error("os_load: failed to declare object '::hyve::os::time::add(::hyve::os::time t)'.");
        goto error;
    }

    /* Define ::hyve::os::time::add(::hyve::os::time t) */
    if (!db_checkState(os_time_add_o, DB_DEFINED)) {
        db_function(os_time_add_o)->returnType = db_resolve_ext(os_time_add_o, NULL, "::hyve::lang::void", FALSE, "element ::hyve::os::time::add(::hyve::os::time t).returnType");
        db_function(os_time_add_o)->returnsReference = FALSE;
        os_time_add_o->virtual = FALSE;
        
        /* Bind ::hyve::os::time::add(::hyve::os::time t) with C-function */
        db_function(os_time_add_o)->kind = DB_PROCEDURE_CDECL;
        void __os_time_add(void *args, void *result);
        db_function(os_time_add_o)->impl = (db_word)__os_time_add;
        if (db_define(os_time_add_o)) {
            db_error("os_load: failed to define object '::hyve::os::time::add(::hyve::os::time t)'.");
            goto error;
        }
    }
    /* Declare ::hyve::os::time::sub(::hyve::os::time t) */
    os_time_sub_o = db_declare(os_time_o, "sub(::hyve::os::time t)", db_typedef(db_method_o));
    if (!os_time_sub_o) {
        db_error("os_load: failed to declare object '::hyve::os::time::sub(::hyve::os::time t)'.");
        goto error;
    }

    /* Define ::hyve::os::time::sub(::hyve::os::time t) */
    if (!db_checkState(os_time_sub_o, DB_DEFINED)) {
        db_function(os_time_sub_o)->returnType = db_resolve_ext(os_time_sub_o, NULL, "::hyve::lang::void", FALSE, "element ::hyve::os::time::sub(::hyve::os::time t).returnType");
        db_function(os_time_sub_o)->returnsReference = FALSE;
        os_time_sub_o->virtual = FALSE;
        
        /* Bind ::hyve::os::time::sub(::hyve::os::time t) with C-function */
        db_function(os_time_sub_o)->kind = DB_PROCEDURE_CDECL;
        void __os_time_sub(void *args, void *result);
        db_function(os_time_sub_o)->impl = (db_word)__os_time_sub;
        if (db_define(os_time_sub_o)) {
            db_error("os_load: failed to define object '::hyve::os::time::sub(::hyve::os::time t)'.");
            goto error;
        }
    }
    /* Define ::hyve::os::time */
    if (!db_checkState(os_time_o, DB_DEFINED)) {
        db_type(os_time_o)->defaultType = db_resolve_ext(os_time_o, NULL, "::hyve::lang::member", FALSE, "element ::hyve::os::time.defaultType");
        db_type(os_time_o)->parentType = NULL;
        db_type(os_time_o)->parentState = 0x0;
        db_interface(os_time_o)->base = NULL;
        db_struct(os_time_o)->baseAccess = 0x0;
        os_time_o->implements.length = 0;
        os_time_o->implements.buffer = NULL;
        if (db_define(os_time_o)) {
            db_error("os_load: failed to define object '::hyve::os::time'.");
            goto error;
        }
    }
    if (db_type(os_time_o)->size != sizeof(struct os_time_s)) {
        db_error("os_load: calculated size '%d' of type '::hyve::os::time' doesn't match C-type size '%d'", db_type(os_time_o)->size, sizeof(struct os_time_s));
    }
    /* Declare ::hyve::os::thread::construct(::hyve::os::thread object) */
    os_thread_construct_o = db_declare(os_thread_o, "construct(::hyve::os::thread object)", db_typedef(db_callback_o));
    if (!os_thread_construct_o) {
        db_error("os_load: failed to declare object '::hyve::os::thread::construct(::hyve::os::thread object)'.");
        goto error;
    }

    /* Define ::hyve::os::thread::construct(::hyve::os::thread object) */
    if (!db_checkState(os_thread_construct_o, DB_DEFINED)) {
        db_function(os_thread_construct_o)->returnType = db_resolve_ext(os_thread_construct_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::os::thread::construct(::hyve::os::thread object).returnType");
        db_function(os_thread_construct_o)->returnsReference = FALSE;
        os_thread_construct_o->delegate = db_resolve_ext(os_thread_construct_o, NULL, "::hyve::lang::class::construct(lang::object object)", FALSE, "element ::hyve::os::thread::construct(::hyve::os::thread object).delegate");
        
        /* Bind ::hyve::os::thread::construct(::hyve::os::thread object) with C-function */
        db_function(os_thread_construct_o)->kind = DB_PROCEDURE_CDECL;
        void __os_thread_construct(void *args, void *result);
        db_function(os_thread_construct_o)->impl = (db_word)__os_thread_construct;
        if (db_define(os_thread_construct_o)) {
            db_error("os_load: failed to define object '::hyve::os::thread::construct(::hyve::os::thread object)'.");
            goto error;
        }
    }
    /* Declare ::hyve::os::thread::destruct(::hyve::os::thread object) */
    os_thread_destruct_o = db_declare(os_thread_o, "destruct(::hyve::os::thread object)", db_typedef(db_callback_o));
    if (!os_thread_destruct_o) {
        db_error("os_load: failed to declare object '::hyve::os::thread::destruct(::hyve::os::thread object)'.");
        goto error;
    }

    /* Define ::hyve::os::thread::destruct(::hyve::os::thread object) */
    if (!db_checkState(os_thread_destruct_o, DB_DEFINED)) {
        db_function(os_thread_destruct_o)->returnType = db_resolve_ext(os_thread_destruct_o, NULL, "::hyve::lang::void", FALSE, "element ::hyve::os::thread::destruct(::hyve::os::thread object).returnType");
        db_function(os_thread_destruct_o)->returnsReference = FALSE;
        os_thread_destruct_o->delegate = db_resolve_ext(os_thread_destruct_o, NULL, "::hyve::lang::class::destruct(lang::object object)", FALSE, "element ::hyve::os::thread::destruct(::hyve::os::thread object).delegate");
        
        /* Bind ::hyve::os::thread::destruct(::hyve::os::thread object) with C-function */
        db_function(os_thread_destruct_o)->kind = DB_PROCEDURE_CDECL;
        void __os_thread_destruct(void *args, void *result);
        db_function(os_thread_destruct_o)->impl = (db_word)__os_thread_destruct;
        if (db_define(os_thread_destruct_o)) {
            db_error("os_load: failed to define object '::hyve::os::thread::destruct(::hyve::os::thread object)'.");
            goto error;
        }
    }
    /* Define ::hyve::os::thread */
    if (!db_checkState(os_thread_o, DB_DEFINED)) {
        db_type(os_thread_o)->defaultType = db_resolve_ext(os_thread_o, NULL, "::hyve::lang::member", FALSE, "element ::hyve::os::thread.defaultType");
        db_type(os_thread_o)->parentType = NULL;
        db_type(os_thread_o)->parentState = 0x0;
        db_interface(os_thread_o)->base = NULL;
        db_struct(os_thread_o)->baseAccess = 0x0;
        os_thread_o->implements.length = 0;
        os_thread_o->implements.buffer = NULL;
        if (db_define(os_thread_o)) {
            db_error("os_load: failed to define object '::hyve::os::thread'.");
            goto error;
        }
    }
    if (db_type(os_thread_o)->size != sizeof(struct os_thread_s)) {
        db_error("os_load: calculated size '%d' of type '::hyve::os::thread' doesn't match C-type size '%d'", db_type(os_thread_o)->size, sizeof(struct os_thread_s));
    }
    /* Declare ::hyve::os::timer::run() */
    os_timer_run_o = db_declare(os_timer_o, "run()", db_typedef(db_method_o));
    if (!os_timer_run_o) {
        db_error("os_load: failed to declare object '::hyve::os::timer::run()'.");
        goto error;
    }

    /* Define ::hyve::os::timer::run() */
    if (!db_checkState(os_timer_run_o, DB_DEFINED)) {
        db_function(os_timer_run_o)->returnType = db_resolve_ext(os_timer_run_o, NULL, "::hyve::lang::void", FALSE, "element ::hyve::os::timer::run().returnType");
        db_function(os_timer_run_o)->returnsReference = FALSE;
        os_timer_run_o->virtual = FALSE;
        
        /* Bind ::hyve::os::timer::run() with C-function */
        db_function(os_timer_run_o)->kind = DB_PROCEDURE_CDECL;
        void __os_timer_run(void *args, void *result);
        db_function(os_timer_run_o)->impl = (db_word)__os_timer_run;
        if (db_define(os_timer_run_o)) {
            db_error("os_load: failed to define object '::hyve::os::timer::run()'.");
            goto error;
        }
    }
    /* Declare ::hyve::os::timer::stop() */
    os_timer_stop_o = db_declare(os_timer_o, "stop()", db_typedef(db_method_o));
    if (!os_timer_stop_o) {
        db_error("os_load: failed to declare object '::hyve::os::timer::stop()'.");
        goto error;
    }

    /* Define ::hyve::os::timer::stop() */
    if (!db_checkState(os_timer_stop_o, DB_DEFINED)) {
        db_function(os_timer_stop_o)->returnType = db_resolve_ext(os_timer_stop_o, NULL, "::hyve::lang::void", FALSE, "element ::hyve::os::timer::stop().returnType");
        db_function(os_timer_stop_o)->returnsReference = FALSE;
        os_timer_stop_o->virtual = FALSE;
        
        /* Bind ::hyve::os::timer::stop() with C-function */
        db_function(os_timer_stop_o)->kind = DB_PROCEDURE_CDECL;
        void __os_timer_stop(void *args, void *result);
        db_function(os_timer_stop_o)->impl = (db_word)__os_timer_stop;
        if (db_define(os_timer_stop_o)) {
            db_error("os_load: failed to define object '::hyve::os::timer::stop()'.");
            goto error;
        }
    }
    /* Define ::hyve::os::timer */
    if (!db_checkState(os_timer_o, DB_DEFINED)) {
        db_type(os_timer_o)->defaultType = db_resolve_ext(os_timer_o, NULL, "::hyve::lang::member", FALSE, "element ::hyve::os::timer.defaultType");
        db_type(os_timer_o)->parentType = NULL;
        db_type(os_timer_o)->parentState = 0x0;
        db_interface(os_timer_o)->base = db_resolve_ext(os_timer_o, NULL, "::hyve::os::thread", FALSE, "element ::hyve::os::timer.base");
        db_struct(os_timer_o)->baseAccess = 0x0;
        os_timer_o->implements.length = 0;
        os_timer_o->implements.buffer = NULL;
        if (db_define(os_timer_o)) {
            db_error("os_load: failed to define object '::hyve::os::timer'.");
            goto error;
        }
    }
    if (db_type(os_timer_o)->size != sizeof(struct os_timer_s)) {
        db_error("os_load: calculated size '%d' of type '::hyve::os::timer' doesn't match C-type size '%d'", db_type(os_timer_o)->size, sizeof(struct os_timer_s));
    }
    if (_a_) {
        db_free(_a_);
    }

    return 0;
error:
    return -1;
}
