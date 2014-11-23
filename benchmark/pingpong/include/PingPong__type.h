/* PingPong__type.h
 *
 *  Generated on Feb  5 2014
 *    Type-definitions for C-language.
 *    This file contains generated code. Do not modify!
 */

#ifndef PingPong__type_H
#define PingPong__type_H

#include "hyve.h"
#include "hyve/os/os__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Casting macro's for classes */
#define pp_Dispatcher(o) ((pp_Dispatcher)o)
#define pp_Pinger(o) ((pp_Pinger)o)

/* Type definitions */


/*  ::PingPong::Dispatcher */
DB_CLASS(pp_Dispatcher);
DB_CLASS_DEF(pp_Dispatcher) {
    DB_EXTEND(os_thread);
    db_observableEvent event;
    db_observableEvent lastEvent;
};

/*  ::PingPong::time */
typedef struct pp_time pp_time;
struct pp_time {
    db_int32 sec;
    db_uint32 nanosec;
};

/*  ::PingPong::Pinger */
DB_CLASS(pp_Pinger);
DB_CLASS_DEF(pp_Pinger) {
    db_dispatcher dispatcher;
    db_bool isPing;
    pp_time lastPing;
    pp_time minPing;
    pp_time maxPing;
    pp_time cummPing;
    db_uint32 samples;
};

#ifdef __cplusplus
}
#endif
#endif

