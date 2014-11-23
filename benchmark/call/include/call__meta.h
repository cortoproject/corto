/* call__meta.h
 *
 *  Generated on Feb  5 2014
 *    Loads objects in database.
 *    This file contains generated code. Do not modify!
 */

#ifndef call_META_H
#define call_META_H

#include "hyve.h"

#include "call__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::call */
extern db_void (*call_o);

/* ::call::complexCall(::hyve::lang::word w1,::hyve::lang::word w2,::hyve::lang::word w3,::hyve::lang::word w4) */
extern db_function call_complexCall_o;

/* ::call::floatCall(::hyve::lang::word w1,::hyve::lang::word w2,::hyve::lang::word w3,::hyve::lang::word w4) */
extern db_function call_floatCall_o;

/* ::call::noargCall() */
extern db_function call_noargCall_o;

/* ::call::Point */
extern db_struct call_Point_o;

/* ::call::Point::x */
extern db_member call_Point_x_o;

/* ::call::Point::y */
extern db_member call_Point_y_o;

/* ::call::wordCall(::hyve::lang::word w1,::hyve::lang::word w2,::hyve::lang::word w3,::hyve::lang::word w4) */
extern db_function call_wordCall_o;

int call_load(void);
#ifdef __cplusplus
}
#endif
#endif

