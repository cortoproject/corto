/* pp_Pinger.h
 *
 *  Generated on Feb  5 2014
 *    This file contains generated code. Do not modify!
 */

#ifndef pp_Pinger_H
#define pp_Pinger_H

#include "hyve.h"
#include "PingPong__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* callback ::hyve::lang::class::construct(lang::object object) -> ::PingPong::Pinger::construct(::PingPong::Pinger object) */
db_int16 pp_Pinger_construct(pp_Pinger object);

/* ::PingPong::Pinger::onEvent */
db_void pp_Pinger_onEvent(pp_Pinger _this, db_object *observable, db_object *source);

#ifdef __cplusplus
}
#endif
#endif

