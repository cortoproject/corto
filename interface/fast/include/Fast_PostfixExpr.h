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

/* callback ::cortex::lang::class::construct(lang::object object) -> ::cortex::Fast::PostfixExpr::construct(Fast::PostfixExpr object) */
cx_int16 Fast_PostfixExpr_construct(Fast_PostfixExpr object);

/* virtual ::cortex::Fast::PostfixExpr::toIc(lang::alias{"cx_icProgram"} program,lang::alias{"cx_icStorage"} storage,lang::bool stored) */
cx_ic Fast_PostfixExpr_toIc(Fast_PostfixExpr _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

/* ::cortex::Fast::PostfixExpr::toIc(lang::alias{"cx_icProgram"} program,lang::alias{"cx_icStorage"} storage,lang::bool stored) */
cx_ic Fast_PostfixExpr_toIc_v(Fast_PostfixExpr _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

#ifdef __cplusplus
}
#endif
#endif

