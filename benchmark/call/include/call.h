/* call.h
 *
 *  Generated on Feb  5 2014
 *    This file contains generated code. Do not modify!
 */

#ifndef call_H
#define call_H

#include "hyve.h"
#include "call__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::call::complexCall(::hyve::lang::word w1,::hyve::lang::word w2,::hyve::lang::word w3,::hyve::lang::word w4) */
call_Point call_complexCall(db_word w1, db_word w2, db_word w3, db_word w4);

/* ::call::floatCall(::hyve::lang::word w1,::hyve::lang::word w2,::hyve::lang::word w3,::hyve::lang::word w4) */
db_float64 call_floatCall(db_word w1, db_word w2, db_word w3, db_word w4);

/* ::call::noargCall() */
db_void call_noargCall(void);

/* ::call::wordCall(::hyve::lang::word w1,::hyve::lang::word w2,::hyve::lang::word w3,::hyve::lang::word w4) */
db_word call_wordCall(db_word w1, db_word w2, db_word w3, db_word w4);

#ifdef __cplusplus
}
#endif
#endif

