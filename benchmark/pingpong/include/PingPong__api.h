/* PingPong__api.h
 *
 *  Generated on Feb  5 2014
 *    API convenience functions for C-language.
 *    This file contains generated code. Do not modify!
 */

#ifndef PingPong__API_H
#define PingPong__API_H

#include "PingPong__type.h"
#include "hyve.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::PingPong::Dispatcher */
pp_Dispatcher pp_Dispatcher__new(void);
pp_Dispatcher pp_Dispatcher__declare(db_object _parent, db_string _name);
int pp_Dispatcher__define(pp_Dispatcher _this, db_observableEvent event);
pp_Dispatcher pp_Dispatcher__create(db_observableEvent event);

/* ::PingPong::Pinger */
pp_Pinger pp_Pinger__new(void);
pp_Pinger pp_Pinger__declare(db_object _parent, db_string _name);
int pp_Pinger__define(pp_Pinger _this, db_dispatcher dispatcher, db_bool isPing, pp_time lastPing, pp_time minPing, pp_time maxPing, pp_time cummPing, db_uint32 samples);
pp_Pinger pp_Pinger__create(db_dispatcher dispatcher, db_bool isPing, pp_time lastPing, pp_time minPing, pp_time maxPing, pp_time cummPing, db_uint32 samples);


#ifdef __cplusplus
}
#endif
#endif

