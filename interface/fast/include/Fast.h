/* Fast.h
 *
 *  Generated on Nov 18 2014
 *    This file contains generated code. Do not modify!
 */

#ifndef Fast_H
#define Fast_H

#include "hyve.h"
#include "Fast__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* $header() */
Fast_Call Fast_createMethodCall(Fast_Expression obj, db_string function, db_uint32 numArgs, ...);
/* $end */

/* ::hyve::Fast::valueKindFromType(lang::type type) */
Fast_valueKind Fast_valueKindFromType(db_type type);

#ifdef __cplusplus
}
#endif
#endif

