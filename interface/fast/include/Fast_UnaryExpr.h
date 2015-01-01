/* Fast_UnaryExpr.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_UnaryExpr_H
#define Fast_UnaryExpr_H

#include "cortex.h"
#include "Fast_Expression.h"
#include "Fast__type.h"

#include "Fast__api.h"

#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* callback ::cortex::lang::class::construct(lang::object object) -> ::cortex::Fast::UnaryExpr::construct(Fast::UnaryExpr object) */
cx_int16 Fast_UnaryExpr_construct(Fast_UnaryExpr object);

/* virtual ::cortex::Fast::UnaryExpr::hasSideEffects() */
cx_bool Fast_UnaryExpr_hasSideEffects(Fast_UnaryExpr _this);

/* ::cortex::Fast::UnaryExpr::hasSideEffects() */
cx_bool Fast_UnaryExpr_hasSideEffects_v(Fast_UnaryExpr _this);

/* virtual ::cortex::Fast::UnaryExpr::toIc(lang::alias{"cx_icProgram"} program,lang::alias{"cx_icStorage"} storage,lang::bool stored) */
cx_ic Fast_UnaryExpr_toIc(Fast_UnaryExpr _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

/* ::cortex::Fast::UnaryExpr::toIc(lang::alias{"cx_icProgram"} program,lang::alias{"cx_icStorage"} storage,lang::bool stored) */
cx_ic Fast_UnaryExpr_toIc_v(Fast_UnaryExpr _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

#ifdef __cplusplus
}
#endif
#endif

