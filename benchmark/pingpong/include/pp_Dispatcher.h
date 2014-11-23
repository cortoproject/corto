/* pp_Dispatcher.h
 *
 *  Generated on Feb  5 2014
 *    This file contains generated code. Do not modify!
 */

#ifndef pp_Dispatcher_H
#define pp_Dispatcher_H

#include "hyve.h"
#include "os_thread.h"
#include "PingPong__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* callback ::hyve::lang::class::construct(lang::object object) -> ::PingPong::Dispatcher::construct(::PingPong::Dispatcher object) */
db_int16 pp_Dispatcher_construct(pp_Dispatcher object);

/* callback ::hyve::lang::class::destruct(lang::object object) -> ::PingPong::Dispatcher::destruct(::PingPong::Dispatcher object) */
db_void pp_Dispatcher_destruct(pp_Dispatcher object);

/* ::PingPong::Dispatcher::getEvent(::hyve::lang::observer observer,::hyve::lang::object me,::hyve::lang::object observable,::hyve::lang::object src) */
db_observableEvent pp_Dispatcher_getEvent(pp_Dispatcher _this, db_observer observer, db_object me, db_object observable, db_object src);

/* ::PingPong::Dispatcher::handled(::hyve::lang::observableEvent event) */
db_void pp_Dispatcher_handled(pp_Dispatcher _this, db_observableEvent event);

/* ::PingPong::Dispatcher::post(::hyve::lang::event event) */
db_void pp_Dispatcher_post(pp_Dispatcher _this, db_event event);

/* ::PingPong::Dispatcher::run() */
db_void pp_Dispatcher_run(pp_Dispatcher _this);

#ifdef __cplusplus
}
#endif
#endif

