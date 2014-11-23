/* pp_Dispatcher.c
 *
 *  Generated on Feb  5 2014
 *    This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "pp_Dispatcher.h"
#include "PingPong__meta.h"


/* $begin($header) */
#include "db_dispatcher.h"
/* $end */

/* callback ::hyve::lang::class::construct(lang::object object) -> ::PingPong::Dispatcher::construct(::PingPong::Dispatcher object) */
db_int16 pp_Dispatcher_construct(pp_Dispatcher object) {
/* $begin(::PingPong::Dispatcher::construct) */
    DB_UNUSED(object);
    return 0;
/* $end */
}

/* callback ::hyve::lang::class::destruct(lang::object object) -> ::PingPong::Dispatcher::destruct(::PingPong::Dispatcher object) */
db_void pp_Dispatcher_destruct(pp_Dispatcher object) {
/* $begin(::PingPong::Dispatcher::destruct) */
    object->event = NULL;
/* $end */
}

/* ::PingPong::Dispatcher::getEvent(::hyve::lang::observer observer,::hyve::lang::object me,::hyve::lang::object observable,::hyve::lang::object src) */
db_observableEvent pp_Dispatcher_getEvent(pp_Dispatcher _this, db_observer observer, db_object me, db_object observable, db_object src) {
/* $begin(::PingPong::Dispatcher::getEvent) */
    db_observableEvent result;

    if (_this->lastEvent) {
        result = (db_observableEvent)_this->lastEvent;
        _this->lastEvent = NULL;
    } else {
        result = db_new_ext(NULL, db_typedef(db_observableEvent_o), 0, NULL);
        db_event(result)->kind = DB_EVENT_OBSERVABLE;
    }

    result->observable = observable;
    result->me = me;
    result->observer = observer;
    result->source = src;

    return result;
/* $end */
}

/* ::PingPong::Dispatcher::handled(::hyve::lang::observableEvent event) */
db_void pp_Dispatcher_handled(pp_Dispatcher _this, db_observableEvent event) {
/* $begin(::PingPong::Dispatcher::handled) */
    db_event_processed((db_event)event);
    if (!_this->lastEvent) {
        _this->lastEvent = event;
    } else {
        event->observable = NULL;
        event->observer = NULL;
        event->source = NULL;
        db_free(event);
    }
/* $end */
}

/* ::PingPong::Dispatcher::post(::hyve::lang::event event) */
db_void pp_Dispatcher_post(pp_Dispatcher _this, db_event event) {
/* $begin(::PingPong::Dispatcher::post) */
	_this->event = (db_observableEvent)event;
/* $end */
}

/* ::PingPong::Dispatcher::run() */
db_void pp_Dispatcher_run(pp_Dispatcher _this) {
/* $begin(::PingPong::Dispatcher::run) */
    db_observableEvent e;
    db_function f;
	while(1) {
	    while(!(e = _this->event))
        ; _this->event = NULL;
        f = db_function(e->observer);

        /* Since this is a specialized dispatcher and it is known that observers will only be
         * instantiated templates with a cdecl implementation, don't bother with handling other
         * cases.
         */
        ((void(*)(db_object,db_object,db_object))f->impl)(e->me, e->observable, e->source);

        /* Cache last event */
        if (!_this->lastEvent) {
            /*db_set(db_observableEvent(e)->observable,NULL);
            db_set(db_observableEvent(e)->observer,NULL);
            db_set(db_observableEvent(e)->source,NULL);*/
            _this->lastEvent = e;
        } else {
            db_free(e);
        }
	}
/* $end */
}
