/* Fast_TernaryExpr.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_TernaryExpr_H
#define Fast_TernaryExpr_H

#include "cortex.h"
#include "Fast_Expression.h"
#include "Fast__type.h"

#include "Fast__api.h"

#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* callback ::cortex::lang::class::construct(object object) -> ::cortex::Fast::TernaryExpr::construct(Fast::TernaryExpr object) */
cx_int16 Fast_TernaryExpr_construct(Fast_TernaryExpr object);

/* virtual ::cortex::Fast::TernaryExpr::hasSideEffects() */
cx_bool Fast_TernaryExpr_hasSideEffects(Fast_TernaryExpr _this);

/* ::cortex::Fast::TernaryExpr::hasSideEffects() */
cx_bool Fast_TernaryExpr_hasSideEffects_v(Fast_TernaryExpr _this);

/* ::cortex::Fast::TernaryExpr::setOperator(operatorKind kind) */
cx_void Fast_TernaryExpr_setOperator(Fast_TernaryExpr _this, cx_operatorKind kind);

/* virtual ::cortex::Fast::TernaryExpr::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_TernaryExpr_toIc(Fast_TernaryExpr _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

/* ::cortex::Fast::TernaryExpr::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_TernaryExpr_toIc_v(Fast_TernaryExpr _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

#ifdef __cplusplus
}
#endif
#endif

