/* Fast_MethodExpr.h
 *
 *  Generated on Aug 12 2013
 *    This file contains generated code. Do not modify!
 */

#ifndef Fast_MethodExpr_H
#define Fast_MethodExpr_H

#include "cortex.h"
#include "Fast_Expression.h"
#include "Fast__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* callback ::cortex::lang::class::construct(lang::object object) -> ::cortex::Fast::MethodExpr::construct(Fast::MethodExpr object) */
cx_int16 Fast_MethodExpr_construct(Fast_MethodExpr object);

/* virtual ::cortex::Fast::MethodExpr::getType() */
Fast_Storage Fast_MethodExpr_getType(Fast_MethodExpr _this);

/* ::cortex::Fast::MethodExpr::getType() */
Fast_Storage Fast_MethodExpr_getType_v(Fast_MethodExpr _this);

#ifdef __cplusplus
}
#endif
#endif

