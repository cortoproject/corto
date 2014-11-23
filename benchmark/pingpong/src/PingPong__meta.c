/* PingPong__meta.c
 *
 *  Generated on Feb  5 2014
 *    Loads objects in database.
 *    This file contains generated code. Do not modify!
 */

#include "PingPong__type.h"

/* Variable definitions */
db_void (*pp_o);
db_class pp_Dispatcher_o;
db_callback pp_Dispatcher_construct_o;
db_callback pp_Dispatcher_destruct_o;
db_member pp_Dispatcher_event_o;
db_method pp_Dispatcher_getEvent_o;
db_method pp_Dispatcher_handled_o;
db_member pp_Dispatcher_lastEvent_o;
db_method pp_Dispatcher_post_o;
db_method pp_Dispatcher_run_o;
pp_Pinger pp_ping_o;
db_class pp_Pinger_o;
db_callback pp_Pinger_construct_o;
db_member pp_Pinger_cummPing_o;
db_member pp_Pinger_dispatcher_o;
db_member pp_Pinger_isPing_o;
db_member pp_Pinger_lastPing_o;
db_member pp_Pinger_maxPing_o;
db_member pp_Pinger_minPing_o;
db_observer pp_Pinger_onEvent_o;
db_member pp_Pinger_samples_o;
pp_Pinger pp_pong_o;
pp_Dispatcher pp_pongDispatcher_o;
db_struct pp_time_o;
db_member pp_time_nanosec_o;
db_member pp_time_sec_o;

/* Load objects in database */
int PingPong_load(void) {
    db_object _a_; /* Used for resolving anonymous objects */
    _a_ = NULL;

    /* Declare ::PingPong */
    pp_o = db_declare(root_o, "PingPong", db_typedef(db_void_o));
    if (!pp_o) {
        db_error("PingPong_load: failed to declare object '::PingPong'.");
        goto error;
    }

    /* Declare ::PingPong::Dispatcher */
    pp_Dispatcher_o = db_declare(pp_o, "Dispatcher", db_typedef(db_class_o));
    if (!pp_Dispatcher_o) {
        db_error("PingPong_load: failed to declare object '::PingPong::Dispatcher'.");
        goto error;
    }

    /* Declare ::PingPong::Dispatcher::event */
    pp_Dispatcher_event_o = db_declare(pp_Dispatcher_o, "event", db_typedef(db_member_o));
    if (!pp_Dispatcher_event_o) {
        db_error("PingPong_load: failed to declare object '::PingPong::Dispatcher::event'.");
        goto error;
    }

    /* Define ::PingPong::Dispatcher::event */
    if (!db_checkState(pp_Dispatcher_event_o, DB_DEFINED)) {
        pp_Dispatcher_event_o->type = db_resolve_ext(pp_Dispatcher_event_o, NULL, "::hyve::lang::observableEvent", FALSE, "element ::PingPong::Dispatcher::event.type");
        pp_Dispatcher_event_o->modifiers = 0x0;
        pp_Dispatcher_event_o->state = 0x6;
        pp_Dispatcher_event_o->weak = FALSE;
        pp_Dispatcher_event_o->id = 0;
        if (db_define(pp_Dispatcher_event_o)) {
            db_error("PingPong_load: failed to define object '::PingPong::Dispatcher::event'.");
            goto error;
        }
    }
    /* Declare ::PingPong::Dispatcher::getEvent(::hyve::lang::observer observer,::hyve::lang::object me,::hyve::lang::object observable,::hyve::lang::object src) */
    pp_Dispatcher_getEvent_o = db_declare(pp_Dispatcher_o, "getEvent(::hyve::lang::observer observer,::hyve::lang::object me,::hyve::lang::object observable,::hyve::lang::object src)", db_typedef(db_method_o));
    if (!pp_Dispatcher_getEvent_o) {
        db_error("PingPong_load: failed to declare object '::PingPong::Dispatcher::getEvent(::hyve::lang::observer observer,::hyve::lang::object me,::hyve::lang::object observable,::hyve::lang::object src)'.");
        goto error;
    }

    /* Define ::PingPong::Dispatcher::getEvent(::hyve::lang::observer observer,::hyve::lang::object me,::hyve::lang::object observable,::hyve::lang::object src) */
    if (!db_checkState(pp_Dispatcher_getEvent_o, DB_DEFINED)) {
        db_function(pp_Dispatcher_getEvent_o)->returnType = db_resolve_ext(pp_Dispatcher_getEvent_o, NULL, "::hyve::lang::observableEvent", FALSE, "element ::PingPong::Dispatcher::getEvent(::hyve::lang::observer observer,::hyve::lang::object me,::hyve::lang::object observable,::hyve::lang::object src).returnType");
        pp_Dispatcher_getEvent_o->virtual = FALSE;
        
        /* Bind pp_Dispatcher_getEvent_o with C-function */
        db_function(pp_Dispatcher_getEvent_o)->kind = DB_PROCEDURE_CDECL;
        db_observableEvent pp_Dispatcher_getEvent(pp_Dispatcher _this, db_observer observer, db_object me, db_object observable, db_object src);
        db_function(pp_Dispatcher_getEvent_o)->impl = (db_word)pp_Dispatcher_getEvent;
        if (db_define(pp_Dispatcher_getEvent_o)) {
            db_error("PingPong_load: failed to define object '::PingPong::Dispatcher::getEvent(::hyve::lang::observer observer,::hyve::lang::object me,::hyve::lang::object observable,::hyve::lang::object src)'.");
            goto error;
        }
    }
    /* Declare ::PingPong::Dispatcher::handled(::hyve::lang::observableEvent event) */
    pp_Dispatcher_handled_o = db_declare(pp_Dispatcher_o, "handled(::hyve::lang::observableEvent event)", db_typedef(db_method_o));
    if (!pp_Dispatcher_handled_o) {
        db_error("PingPong_load: failed to declare object '::PingPong::Dispatcher::handled(::hyve::lang::observableEvent event)'.");
        goto error;
    }

    /* Define ::PingPong::Dispatcher::handled(::hyve::lang::observableEvent event) */
    if (!db_checkState(pp_Dispatcher_handled_o, DB_DEFINED)) {
        db_function(pp_Dispatcher_handled_o)->returnType = db_resolve_ext(pp_Dispatcher_handled_o, NULL, "::hyve::lang::void", FALSE, "element ::PingPong::Dispatcher::handled(::hyve::lang::observableEvent event).returnType");
        pp_Dispatcher_handled_o->virtual = FALSE;
        
        /* Bind pp_Dispatcher_handled_o with C-function */
        db_function(pp_Dispatcher_handled_o)->kind = DB_PROCEDURE_CDECL;
        db_void pp_Dispatcher_handled(pp_Dispatcher _this, db_observableEvent event);
        db_function(pp_Dispatcher_handled_o)->impl = (db_word)pp_Dispatcher_handled;
        if (db_define(pp_Dispatcher_handled_o)) {
            db_error("PingPong_load: failed to define object '::PingPong::Dispatcher::handled(::hyve::lang::observableEvent event)'.");
            goto error;
        }
    }
    /* Declare ::PingPong::Dispatcher::lastEvent */
    pp_Dispatcher_lastEvent_o = db_declare(pp_Dispatcher_o, "lastEvent", db_typedef(db_member_o));
    if (!pp_Dispatcher_lastEvent_o) {
        db_error("PingPong_load: failed to declare object '::PingPong::Dispatcher::lastEvent'.");
        goto error;
    }

    /* Define ::PingPong::Dispatcher::lastEvent */
    if (!db_checkState(pp_Dispatcher_lastEvent_o, DB_DEFINED)) {
        pp_Dispatcher_lastEvent_o->type = db_resolve_ext(pp_Dispatcher_lastEvent_o, NULL, "::hyve::lang::observableEvent", FALSE, "element ::PingPong::Dispatcher::lastEvent.type");
        pp_Dispatcher_lastEvent_o->modifiers = 0x3;
        pp_Dispatcher_lastEvent_o->state = 0x6;
        pp_Dispatcher_lastEvent_o->weak = FALSE;
        pp_Dispatcher_lastEvent_o->id = 1;
        if (db_define(pp_Dispatcher_lastEvent_o)) {
            db_error("PingPong_load: failed to define object '::PingPong::Dispatcher::lastEvent'.");
            goto error;
        }
    }
    /* Declare ::PingPong::Dispatcher::post(::hyve::lang::event event) */
    pp_Dispatcher_post_o = db_declare(pp_Dispatcher_o, "post(::hyve::lang::event event)", db_typedef(db_method_o));
    if (!pp_Dispatcher_post_o) {
        db_error("PingPong_load: failed to declare object '::PingPong::Dispatcher::post(::hyve::lang::event event)'.");
        goto error;
    }

    /* Define ::PingPong::Dispatcher::post(::hyve::lang::event event) */
    if (!db_checkState(pp_Dispatcher_post_o, DB_DEFINED)) {
        db_function(pp_Dispatcher_post_o)->returnType = db_resolve_ext(pp_Dispatcher_post_o, NULL, "::hyve::lang::void", FALSE, "element ::PingPong::Dispatcher::post(::hyve::lang::event event).returnType");
        pp_Dispatcher_post_o->virtual = FALSE;
        
        /* Bind pp_Dispatcher_post_o with C-function */
        db_function(pp_Dispatcher_post_o)->kind = DB_PROCEDURE_CDECL;
        db_void pp_Dispatcher_post(pp_Dispatcher _this, db_event event);
        db_function(pp_Dispatcher_post_o)->impl = (db_word)pp_Dispatcher_post;
        if (db_define(pp_Dispatcher_post_o)) {
            db_error("PingPong_load: failed to define object '::PingPong::Dispatcher::post(::hyve::lang::event event)'.");
            goto error;
        }
    }
    /* Declare ::PingPong::Dispatcher::run() */
    pp_Dispatcher_run_o = db_declare(pp_Dispatcher_o, "run()", db_typedef(db_method_o));
    if (!pp_Dispatcher_run_o) {
        db_error("PingPong_load: failed to declare object '::PingPong::Dispatcher::run()'.");
        goto error;
    }

    /* Define ::PingPong::Dispatcher::run() */
    if (!db_checkState(pp_Dispatcher_run_o, DB_DEFINED)) {
        db_function(pp_Dispatcher_run_o)->returnType = db_resolve_ext(pp_Dispatcher_run_o, NULL, "::hyve::lang::void", FALSE, "element ::PingPong::Dispatcher::run().returnType");
        pp_Dispatcher_run_o->virtual = FALSE;
        
        /* Bind pp_Dispatcher_run_o with C-function */
        db_function(pp_Dispatcher_run_o)->kind = DB_PROCEDURE_CDECL;
        db_void pp_Dispatcher_run(pp_Dispatcher _this);
        db_function(pp_Dispatcher_run_o)->impl = (db_word)pp_Dispatcher_run;
        if (db_define(pp_Dispatcher_run_o)) {
            db_error("PingPong_load: failed to define object '::PingPong::Dispatcher::run()'.");
            goto error;
        }
    }
    /* Declare ::PingPong::Pinger */
    pp_Pinger_o = db_declare(pp_o, "Pinger", db_typedef(db_class_o));
    if (!pp_Pinger_o) {
        db_error("PingPong_load: failed to declare object '::PingPong::Pinger'.");
        goto error;
    }

    /* Declare ::PingPong::Pinger::cummPing */
    pp_Pinger_cummPing_o = db_declare(pp_Pinger_o, "cummPing", db_typedef(db_member_o));
    if (!pp_Pinger_cummPing_o) {
        db_error("PingPong_load: failed to declare object '::PingPong::Pinger::cummPing'.");
        goto error;
    }

    /* Declare ::PingPong::Pinger::dispatcher */
    pp_Pinger_dispatcher_o = db_declare(pp_Pinger_o, "dispatcher", db_typedef(db_member_o));
    if (!pp_Pinger_dispatcher_o) {
        db_error("PingPong_load: failed to declare object '::PingPong::Pinger::dispatcher'.");
        goto error;
    }

    /* Define ::PingPong::Pinger::dispatcher */
    if (!db_checkState(pp_Pinger_dispatcher_o, DB_DEFINED)) {
        pp_Pinger_dispatcher_o->type = db_resolve_ext(pp_Pinger_dispatcher_o, NULL, "::hyve::lang::dispatcher", FALSE, "element ::PingPong::Pinger::dispatcher.type");
        pp_Pinger_dispatcher_o->modifiers = 0x0;
        pp_Pinger_dispatcher_o->state = 0x6;
        pp_Pinger_dispatcher_o->weak = FALSE;
        pp_Pinger_dispatcher_o->id = 0;
        if (db_define(pp_Pinger_dispatcher_o)) {
            db_error("PingPong_load: failed to define object '::PingPong::Pinger::dispatcher'.");
            goto error;
        }
    }
    /* Declare ::PingPong::Pinger::isPing */
    pp_Pinger_isPing_o = db_declare(pp_Pinger_o, "isPing", db_typedef(db_member_o));
    if (!pp_Pinger_isPing_o) {
        db_error("PingPong_load: failed to declare object '::PingPong::Pinger::isPing'.");
        goto error;
    }

    /* Define ::PingPong::Pinger::isPing */
    if (!db_checkState(pp_Pinger_isPing_o, DB_DEFINED)) {
        pp_Pinger_isPing_o->type = db_resolve_ext(pp_Pinger_isPing_o, NULL, "::hyve::lang::bool", FALSE, "element ::PingPong::Pinger::isPing.type");
        pp_Pinger_isPing_o->modifiers = 0x0;
        pp_Pinger_isPing_o->state = 0x6;
        pp_Pinger_isPing_o->weak = FALSE;
        pp_Pinger_isPing_o->id = 1;
        if (db_define(pp_Pinger_isPing_o)) {
            db_error("PingPong_load: failed to define object '::PingPong::Pinger::isPing'.");
            goto error;
        }
    }
    /* Declare ::PingPong::Pinger::lastPing */
    pp_Pinger_lastPing_o = db_declare(pp_Pinger_o, "lastPing", db_typedef(db_member_o));
    if (!pp_Pinger_lastPing_o) {
        db_error("PingPong_load: failed to declare object '::PingPong::Pinger::lastPing'.");
        goto error;
    }

    /* Declare ::PingPong::Pinger::maxPing */
    pp_Pinger_maxPing_o = db_declare(pp_Pinger_o, "maxPing", db_typedef(db_member_o));
    if (!pp_Pinger_maxPing_o) {
        db_error("PingPong_load: failed to declare object '::PingPong::Pinger::maxPing'.");
        goto error;
    }

    /* Declare ::PingPong::Pinger::minPing */
    pp_Pinger_minPing_o = db_declare(pp_Pinger_o, "minPing", db_typedef(db_member_o));
    if (!pp_Pinger_minPing_o) {
        db_error("PingPong_load: failed to declare object '::PingPong::Pinger::minPing'.");
        goto error;
    }

    /* Declare ::PingPong::Pinger::onEvent */
    pp_Pinger_onEvent_o = db_declare(pp_Pinger_o, "onEvent", db_typedef(db_observer_o));
    if (!pp_Pinger_onEvent_o) {
        db_error("PingPong_load: failed to declare object '::PingPong::Pinger::onEvent'.");
        goto error;
    }

    /* Define ::PingPong::Pinger::onEvent */
    if (!db_checkState(pp_Pinger_onEvent_o, DB_DEFINED)) {
        pp_Pinger_onEvent_o->observable = NULL;
        pp_Pinger_onEvent_o->mask = 0x130;
        pp_Pinger_onEvent_o->expression = NULL;
        pp_Pinger_onEvent_o->template = 1;
        pp_Pinger_onEvent_o->dispatcher = NULL;
        pp_Pinger_onEvent_o->me = NULL;
        
        /* Bind pp_Pinger_onEvent_o with C-function */
        db_function(pp_Pinger_onEvent_o)->kind = DB_PROCEDURE_CDECL;
        db_void pp_Pinger_onEvent(pp_Pinger _this, db_object *observable, db_object *source);
        db_function(pp_Pinger_onEvent_o)->impl = (db_word)pp_Pinger_onEvent;
        if (db_define(pp_Pinger_onEvent_o)) {
            db_error("PingPong_load: failed to define object '::PingPong::Pinger::onEvent'.");
            goto error;
        }
    }
    /* Declare ::PingPong::Pinger::samples */
    pp_Pinger_samples_o = db_declare(pp_Pinger_o, "samples", db_typedef(db_member_o));
    if (!pp_Pinger_samples_o) {
        db_error("PingPong_load: failed to declare object '::PingPong::Pinger::samples'.");
        goto error;
    }

    /* Define ::PingPong::Pinger::samples */
    if (!db_checkState(pp_Pinger_samples_o, DB_DEFINED)) {
        pp_Pinger_samples_o->type = db_resolve_ext(pp_Pinger_samples_o, NULL, "::hyve::lang::uint32", FALSE, "element ::PingPong::Pinger::samples.type");
        pp_Pinger_samples_o->modifiers = 0x0;
        pp_Pinger_samples_o->state = 0x6;
        pp_Pinger_samples_o->weak = FALSE;
        pp_Pinger_samples_o->id = 6;
        if (db_define(pp_Pinger_samples_o)) {
            db_error("PingPong_load: failed to define object '::PingPong::Pinger::samples'.");
            goto error;
        }
    }
    /* Declare ::PingPong::time */
    pp_time_o = db_declare(pp_o, "time", db_typedef(db_struct_o));
    if (!pp_time_o) {
        db_error("PingPong_load: failed to declare object '::PingPong::time'.");
        goto error;
    }

    /* Declare ::PingPong::time::nanosec */
    pp_time_nanosec_o = db_declare(pp_time_o, "nanosec", db_typedef(db_member_o));
    if (!pp_time_nanosec_o) {
        db_error("PingPong_load: failed to declare object '::PingPong::time::nanosec'.");
        goto error;
    }

    /* Define ::PingPong::time::nanosec */
    if (!db_checkState(pp_time_nanosec_o, DB_DEFINED)) {
        pp_time_nanosec_o->type = db_resolve_ext(pp_time_nanosec_o, NULL, "::hyve::lang::uint32", FALSE, "element ::PingPong::time::nanosec.type");
        pp_time_nanosec_o->modifiers = 0x0;
        pp_time_nanosec_o->state = 0x6;
        pp_time_nanosec_o->weak = FALSE;
        pp_time_nanosec_o->id = 1;
        if (db_define(pp_time_nanosec_o)) {
            db_error("PingPong_load: failed to define object '::PingPong::time::nanosec'.");
            goto error;
        }
    }
    /* Declare ::PingPong::time::sec */
    pp_time_sec_o = db_declare(pp_time_o, "sec", db_typedef(db_member_o));
    if (!pp_time_sec_o) {
        db_error("PingPong_load: failed to declare object '::PingPong::time::sec'.");
        goto error;
    }

    /* Define ::PingPong::time::sec */
    if (!db_checkState(pp_time_sec_o, DB_DEFINED)) {
        pp_time_sec_o->type = db_resolve_ext(pp_time_sec_o, NULL, "::hyve::lang::int32", FALSE, "element ::PingPong::time::sec.type");
        pp_time_sec_o->modifiers = 0x0;
        pp_time_sec_o->state = 0x6;
        pp_time_sec_o->weak = FALSE;
        pp_time_sec_o->id = 0;
        if (db_define(pp_time_sec_o)) {
            db_error("PingPong_load: failed to define object '::PingPong::time::sec'.");
            goto error;
        }
    }
    /* Define ::PingPong::time */
    if (!db_checkState(pp_time_o, DB_DEFINED)) {
        db_type(pp_time_o)->parentType = NULL;
        db_type(pp_time_o)->parentState = 0x0;
        db_interface(pp_time_o)->base = NULL;
        pp_time_o->baseAccess = 0x0;
        if (db_define(pp_time_o)) {
            db_error("PingPong_load: failed to define object '::PingPong::time'.");
            goto error;
        }
    }
    /* Define ::PingPong::Pinger::cummPing */
    if (!db_checkState(pp_Pinger_cummPing_o, DB_DEFINED)) {
        pp_Pinger_cummPing_o->type = db_resolve_ext(pp_Pinger_cummPing_o, NULL, "::PingPong::time", FALSE, "element ::PingPong::Pinger::cummPing.type");
        pp_Pinger_cummPing_o->modifiers = 0x0;
        pp_Pinger_cummPing_o->state = 0x6;
        pp_Pinger_cummPing_o->weak = FALSE;
        pp_Pinger_cummPing_o->id = 5;
        if (db_define(pp_Pinger_cummPing_o)) {
            db_error("PingPong_load: failed to define object '::PingPong::Pinger::cummPing'.");
            goto error;
        }
    }
    /* Define ::PingPong::Pinger::lastPing */
    if (!db_checkState(pp_Pinger_lastPing_o, DB_DEFINED)) {
        pp_Pinger_lastPing_o->type = db_resolve_ext(pp_Pinger_lastPing_o, NULL, "::PingPong::time", FALSE, "element ::PingPong::Pinger::lastPing.type");
        pp_Pinger_lastPing_o->modifiers = 0x0;
        pp_Pinger_lastPing_o->state = 0x6;
        pp_Pinger_lastPing_o->weak = FALSE;
        pp_Pinger_lastPing_o->id = 2;
        if (db_define(pp_Pinger_lastPing_o)) {
            db_error("PingPong_load: failed to define object '::PingPong::Pinger::lastPing'.");
            goto error;
        }
    }
    /* Define ::PingPong::Pinger::maxPing */
    if (!db_checkState(pp_Pinger_maxPing_o, DB_DEFINED)) {
        pp_Pinger_maxPing_o->type = db_resolve_ext(pp_Pinger_maxPing_o, NULL, "::PingPong::time", FALSE, "element ::PingPong::Pinger::maxPing.type");
        pp_Pinger_maxPing_o->modifiers = 0x0;
        pp_Pinger_maxPing_o->state = 0x6;
        pp_Pinger_maxPing_o->weak = FALSE;
        pp_Pinger_maxPing_o->id = 4;
        if (db_define(pp_Pinger_maxPing_o)) {
            db_error("PingPong_load: failed to define object '::PingPong::Pinger::maxPing'.");
            goto error;
        }
    }
    /* Define ::PingPong::Pinger::minPing */
    if (!db_checkState(pp_Pinger_minPing_o, DB_DEFINED)) {
        pp_Pinger_minPing_o->type = db_resolve_ext(pp_Pinger_minPing_o, NULL, "::PingPong::time", FALSE, "element ::PingPong::Pinger::minPing.type");
        pp_Pinger_minPing_o->modifiers = 0x0;
        pp_Pinger_minPing_o->state = 0x6;
        pp_Pinger_minPing_o->weak = FALSE;
        pp_Pinger_minPing_o->id = 3;
        if (db_define(pp_Pinger_minPing_o)) {
            db_error("PingPong_load: failed to define object '::PingPong::Pinger::minPing'.");
            goto error;
        }
    }
    /* Declare ::PingPong::Pinger::construct(::PingPong::Pinger object) */
    pp_Pinger_construct_o = db_declare(pp_Pinger_o, "construct(::PingPong::Pinger object)", db_typedef(db_callback_o));
    if (!pp_Pinger_construct_o) {
        db_error("PingPong_load: failed to declare object '::PingPong::Pinger::construct(::PingPong::Pinger object)'.");
        goto error;
    }

    /* Define ::PingPong::Pinger::construct(::PingPong::Pinger object) */
    if (!db_checkState(pp_Pinger_construct_o, DB_DEFINED)) {
        db_function(pp_Pinger_construct_o)->returnType = db_resolve_ext(pp_Pinger_construct_o, NULL, "::hyve::lang::int16", FALSE, "element ::PingPong::Pinger::construct(::PingPong::Pinger object).returnType");
        pp_Pinger_construct_o->delegate = db_resolve_ext(pp_Pinger_construct_o, NULL, "::hyve::lang::class::construct(lang::object object)", FALSE, "element ::PingPong::Pinger::construct(::PingPong::Pinger object).delegate");
        
        /* Bind pp_Pinger_construct_o with C-function */
        db_function(pp_Pinger_construct_o)->kind = DB_PROCEDURE_CDECL;
        db_int16 pp_Pinger_construct(pp_Pinger object);
        db_function(pp_Pinger_construct_o)->impl = (db_word)pp_Pinger_construct;
        if (db_define(pp_Pinger_construct_o)) {
            db_error("PingPong_load: failed to define object '::PingPong::Pinger::construct(::PingPong::Pinger object)'.");
            goto error;
        }
    }
    /* Define ::PingPong::Pinger */
    if (!db_checkState(pp_Pinger_o, DB_DEFINED)) {
        db_type(pp_Pinger_o)->parentType = NULL;
        db_type(pp_Pinger_o)->parentState = 0x0;
        db_interface(pp_Pinger_o)->base = NULL;
        db_struct(pp_Pinger_o)->baseAccess = 0x0;
        pp_Pinger_o->implements.length = 0;
        pp_Pinger_o->implements.buffer = NULL;
        if (db_define(pp_Pinger_o)) {
            db_error("PingPong_load: failed to define object '::PingPong::Pinger'.");
            goto error;
        }
    }
    /* Declare ::PingPong::ping */
    pp_ping_o = db_declare(pp_o, "ping", db_typedef(pp_Pinger_o));
    if (!pp_ping_o) {
        db_error("PingPong_load: failed to declare object '::PingPong::ping'.");
        goto error;
    }

    /* Define ::PingPong::ping */
    if (!db_checkState(pp_ping_o, DB_DEFINED)) {
        pp_ping_o->dispatcher = NULL;
        pp_ping_o->isPing = TRUE;
        pp_ping_o->lastPing.sec = 0;
        pp_ping_o->lastPing.nanosec = 0;
        pp_ping_o->minPing.sec = 0;
        pp_ping_o->minPing.nanosec = 0;
        pp_ping_o->maxPing.sec = 0;
        pp_ping_o->maxPing.nanosec = 0;
        pp_ping_o->cummPing.sec = 0;
        pp_ping_o->cummPing.nanosec = 0;
        pp_ping_o->samples = 0;
        if (db_define(pp_ping_o)) {
            db_error("PingPong_load: failed to define object '::PingPong::ping'.");
            goto error;
        }
    }
    /* Declare ::PingPong::pong */
    pp_pong_o = db_declare(pp_o, "pong", db_typedef(pp_Pinger_o));
    if (!pp_pong_o) {
        db_error("PingPong_load: failed to declare object '::PingPong::pong'.");
        goto error;
    }

    /* Declare ::PingPong::Dispatcher::construct(::PingPong::Dispatcher object) */
    pp_Dispatcher_construct_o = db_declare(pp_Dispatcher_o, "construct(::PingPong::Dispatcher object)", db_typedef(db_callback_o));
    if (!pp_Dispatcher_construct_o) {
        db_error("PingPong_load: failed to declare object '::PingPong::Dispatcher::construct(::PingPong::Dispatcher object)'.");
        goto error;
    }

    /* Define ::PingPong::Dispatcher::construct(::PingPong::Dispatcher object) */
    if (!db_checkState(pp_Dispatcher_construct_o, DB_DEFINED)) {
        db_function(pp_Dispatcher_construct_o)->returnType = db_resolve_ext(pp_Dispatcher_construct_o, NULL, "::hyve::lang::int16", FALSE, "element ::PingPong::Dispatcher::construct(::PingPong::Dispatcher object).returnType");
        pp_Dispatcher_construct_o->delegate = db_resolve_ext(pp_Dispatcher_construct_o, NULL, "::hyve::lang::class::construct(lang::object object)", FALSE, "element ::PingPong::Dispatcher::construct(::PingPong::Dispatcher object).delegate");
        
        /* Bind pp_Dispatcher_construct_o with C-function */
        db_function(pp_Dispatcher_construct_o)->kind = DB_PROCEDURE_CDECL;
        db_int16 pp_Dispatcher_construct(pp_Dispatcher object);
        db_function(pp_Dispatcher_construct_o)->impl = (db_word)pp_Dispatcher_construct;
        if (db_define(pp_Dispatcher_construct_o)) {
            db_error("PingPong_load: failed to define object '::PingPong::Dispatcher::construct(::PingPong::Dispatcher object)'.");
            goto error;
        }
    }
    /* Declare ::PingPong::Dispatcher::destruct(::PingPong::Dispatcher object) */
    pp_Dispatcher_destruct_o = db_declare(pp_Dispatcher_o, "destruct(::PingPong::Dispatcher object)", db_typedef(db_callback_o));
    if (!pp_Dispatcher_destruct_o) {
        db_error("PingPong_load: failed to declare object '::PingPong::Dispatcher::destruct(::PingPong::Dispatcher object)'.");
        goto error;
    }

    /* Define ::PingPong::Dispatcher::destruct(::PingPong::Dispatcher object) */
    if (!db_checkState(pp_Dispatcher_destruct_o, DB_DEFINED)) {
        db_function(pp_Dispatcher_destruct_o)->returnType = db_resolve_ext(pp_Dispatcher_destruct_o, NULL, "::hyve::lang::void", FALSE, "element ::PingPong::Dispatcher::destruct(::PingPong::Dispatcher object).returnType");
        pp_Dispatcher_destruct_o->delegate = db_resolve_ext(pp_Dispatcher_destruct_o, NULL, "::hyve::lang::class::destruct(lang::object object)", FALSE, "element ::PingPong::Dispatcher::destruct(::PingPong::Dispatcher object).delegate");
        
        /* Bind pp_Dispatcher_destruct_o with C-function */
        db_function(pp_Dispatcher_destruct_o)->kind = DB_PROCEDURE_CDECL;
        db_void pp_Dispatcher_destruct(pp_Dispatcher object);
        db_function(pp_Dispatcher_destruct_o)->impl = (db_word)pp_Dispatcher_destruct;
        if (db_define(pp_Dispatcher_destruct_o)) {
            db_error("PingPong_load: failed to define object '::PingPong::Dispatcher::destruct(::PingPong::Dispatcher object)'.");
            goto error;
        }
    }
    /* Define ::PingPong::Dispatcher */
    if (!db_checkState(pp_Dispatcher_o, DB_DEFINED)) {
        db_type(pp_Dispatcher_o)->parentType = NULL;
        db_type(pp_Dispatcher_o)->parentState = 0x0;
        db_interface(pp_Dispatcher_o)->base = db_resolve_ext(pp_Dispatcher_o, NULL, "::hyve::os::thread", FALSE, "element ::PingPong::Dispatcher.base");
        db_struct(pp_Dispatcher_o)->baseAccess = 0x0;
        pp_Dispatcher_o->implements.length = 1;
        pp_Dispatcher_o->implements.buffer = db_malloc(sizeof(db_interface));
        pp_Dispatcher_o->implements.buffer[0] = db_resolve_ext(pp_Dispatcher_o, NULL, "::hyve::lang::dispatcher", FALSE, "(null) ::PingPong::Dispatcher.implements[0]");
        if (db_define(pp_Dispatcher_o)) {
            db_error("PingPong_load: failed to define object '::PingPong::Dispatcher'.");
            goto error;
        }
    }
    /* Declare ::PingPong::pongDispatcher */
    pp_pongDispatcher_o = db_declare(pp_o, "pongDispatcher", db_typedef(pp_Dispatcher_o));
    if (!pp_pongDispatcher_o) {
        db_error("PingPong_load: failed to declare object '::PingPong::pongDispatcher'.");
        goto error;
    }

    /* Define ::PingPong::pongDispatcher */
    if (!db_checkState(pp_pongDispatcher_o, DB_DEFINED)) {
        os_thread(pp_pongDispatcher_o)->stopping = FALSE;
        pp_pongDispatcher_o->event = NULL;
        if (db_define(pp_pongDispatcher_o)) {
            db_error("PingPong_load: failed to define object '::PingPong::pongDispatcher'.");
            goto error;
        }
    }
    /* Define ::PingPong::pong */
    if (!db_checkState(pp_pong_o, DB_DEFINED)) {
        pp_pong_o->dispatcher = db_resolve_ext(pp_pong_o, NULL, "::PingPong::pongDispatcher", FALSE, "element ::PingPong::pong.dispatcher");
        pp_pong_o->isPing = FALSE;
        pp_pong_o->lastPing.sec = 0;
        pp_pong_o->lastPing.nanosec = 0;
        pp_pong_o->minPing.sec = 0;
        pp_pong_o->minPing.nanosec = 0;
        pp_pong_o->maxPing.sec = 0;
        pp_pong_o->maxPing.nanosec = 0;
        pp_pong_o->cummPing.sec = 0;
        pp_pong_o->cummPing.nanosec = 0;
        pp_pong_o->samples = 0;
        if (db_define(pp_pong_o)) {
            db_error("PingPong_load: failed to define object '::PingPong::pong'.");
            goto error;
        }
    }
    if (_a_) {
        db_free(_a_);
    }

    return 0;
error:
    return -1;
}
