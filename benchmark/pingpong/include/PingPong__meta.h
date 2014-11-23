/* PingPong__meta.h
 *
 *  Generated on Feb  5 2014
 *    Loads objects in database.
 *    This file contains generated code. Do not modify!
 */

#ifndef PingPong_META_H
#define PingPong_META_H

#include "hyve.h"

#include "PingPong__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::PingPong */
extern db_void (*pp_o);

/* ::PingPong::Dispatcher */
extern db_class pp_Dispatcher_o;

/* ::PingPong::Dispatcher::construct(::PingPong::Dispatcher object) */
extern db_callback pp_Dispatcher_construct_o;

/* ::PingPong::Dispatcher::destruct(::PingPong::Dispatcher object) */
extern db_callback pp_Dispatcher_destruct_o;

/* ::PingPong::Dispatcher::event */
extern db_member pp_Dispatcher_event_o;

/* ::PingPong::Dispatcher::getEvent(::hyve::lang::observer observer,::hyve::lang::object me,::hyve::lang::object observable,::hyve::lang::object src) */
extern db_method pp_Dispatcher_getEvent_o;

/* ::PingPong::Dispatcher::handled(::hyve::lang::observableEvent event) */
extern db_method pp_Dispatcher_handled_o;

/* ::PingPong::Dispatcher::lastEvent */
extern db_member pp_Dispatcher_lastEvent_o;

/* ::PingPong::Dispatcher::post(::hyve::lang::event event) */
extern db_method pp_Dispatcher_post_o;

/* ::PingPong::Dispatcher::run() */
extern db_method pp_Dispatcher_run_o;

/* ::PingPong::ping */
extern pp_Pinger pp_ping_o;

/* ::PingPong::Pinger */
extern db_class pp_Pinger_o;

/* ::PingPong::Pinger::construct(::PingPong::Pinger object) */
extern db_callback pp_Pinger_construct_o;

/* ::PingPong::Pinger::cummPing */
extern db_member pp_Pinger_cummPing_o;

/* ::PingPong::Pinger::dispatcher */
extern db_member pp_Pinger_dispatcher_o;

/* ::PingPong::Pinger::isPing */
extern db_member pp_Pinger_isPing_o;

/* ::PingPong::Pinger::lastPing */
extern db_member pp_Pinger_lastPing_o;

/* ::PingPong::Pinger::maxPing */
extern db_member pp_Pinger_maxPing_o;

/* ::PingPong::Pinger::minPing */
extern db_member pp_Pinger_minPing_o;

/* ::PingPong::Pinger::onEvent */
extern db_observer pp_Pinger_onEvent_o;

/* ::PingPong::Pinger::samples */
extern db_member pp_Pinger_samples_o;

/* ::PingPong::pong */
extern pp_Pinger pp_pong_o;

/* ::PingPong::pongDispatcher */
extern pp_Dispatcher pp_pongDispatcher_o;

/* ::PingPong::time */
extern db_struct pp_time_o;

/* ::PingPong::time::nanosec */
extern db_member pp_time_nanosec_o;

/* ::PingPong::time::sec */
extern db_member pp_time_sec_o;

int PingPong_load(void);
#ifdef __cplusplus
}
#endif
#endif

