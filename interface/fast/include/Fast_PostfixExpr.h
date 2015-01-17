/* Fast_PostfixExpr.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_PostfixExpr_H
#define Fast_PostfixExpr_H

#include "cortex.h"
#include "Fast_Expression.h"
#include "Fast__type.h"

#include "Fast__api.h"

#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::cortex::Fast::PostfixExpr::construct() */
cx_int16 Fast_PostfixExpr_construct(Fast_PostfixExpr _this);

/* virtual ::cortex::Fast::PostfixExpr::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_PostfixExpr_toIc(Fast_PostfixExpr _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

/* ::cortex::Fast::PostfixExpr::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_PostfixExpr_toIc_v(Fast_PostfixExpr _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

#ifdef __cplusplus
}
#endif
#endif

