/* PingPong_Dispatcher.h
 *
 *  Generated on Jan  9 2014
 *    This file contains generated code. Do not modify!
 */

#ifndef PingPong_Dispatcher_H
#define PingPong_Dispatcher_H

#include "hyve.h"
#include "os_thread.h"
#include "PingPong__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* callback ::hyve::lang::class::construct(lang::object object) -> ::PingPong::Dispatcher::construct(::PingPong::Dispatcher object) */
db_int16 PingPong_Dispatcher_construct(PingPong_Dispatcher object);

/* callback ::hyve::lang::class::destruct(lang::object object) -> ::PingPong::Dispatcher::destruct(::PingPong::Dispatcher object) */
db_void PingPong_Dispatcher_destruct(PingPong_Dispatcher object);

/* ::PingPong::Dispatcher::getEvent(::hyve::lang::observer observer,::hyve::lang::object me,::hyve::lang::object observable,::hyve::lang::object src) */
db_observableEvent PingPong_Dispatcher_getEvent(PingPong_Dispatcher _this, db_observer observer, db_object me, db_object observable, db_object src);

/* ::PingPong::Dispatcher::handled(::hyve::lang::observableEvent event) */
db_void PingPong_Dispatcher_handled(PingPong_Dispatcher _this, db_observableEvent event);

/* ::PingPong::Dispatcher::post(::hyve::lang::event event) */
db_void PingPong_Dispatcher_post(PingPong_Dispatcher _this, db_event event);

/* ::PingPong::Dispatcher::run() */
db_void PingPong_Dispatcher_run(PingPong_Dispatcher _this);

#ifdef __cplusplus
}
#endif
#endif

