/* PingPong_Pinger.h
 *
 *  Generated on Jan  9 2014
 *    This file contains generated code. Do not modify!
 */

#ifndef PingPong_Pinger_H
#define PingPong_Pinger_H

#include "hyve.h"
#include "PingPong__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* callback ::hyve::lang::class::construct(lang::object object) -> ::PingPong::Pinger::construct(::PingPong::Pinger object) */
db_int16 PingPong_Pinger_construct(PingPong_Pinger object);

/* ::PingPong::Pinger::onEvent */
db_void PingPong_Pinger_onEvent(PingPong_Pinger _this, db_object observable, db_object source);

#ifdef __cplusplus
}
#endif
#endif

