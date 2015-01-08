/* Fast_BinaryExpr.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_BinaryExpr_H
#define Fast_BinaryExpr_H

#include "cortex.h"
#include "Fast_Expression.h"
#include "Fast__type.h"

#include "Fast__api.h"

#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* callback ::cortex::lang::class::construct(object object) -> ::cortex::Fast::BinaryExpr::construct(Fast::BinaryExpr object) */
cx_int16 Fast_BinaryExpr_construct(Fast_BinaryExpr object);

/* ::cortex::Fast::BinaryExpr::fold() */
Fast_Expression Fast_BinaryExpr_fold(Fast_BinaryExpr _this);

/* virtual ::cortex::Fast::BinaryExpr::hasSideEffects() */
cx_bool Fast_BinaryExpr_hasSideEffects(Fast_BinaryExpr _this);

/* ::cortex::Fast::BinaryExpr::hasSideEffects() */
cx_bool Fast_BinaryExpr_hasSideEffects_v(Fast_BinaryExpr _this);

/* ::cortex::Fast::BinaryExpr::setOperator(operatorKind kind) */
cx_void Fast_BinaryExpr_setOperator(Fast_BinaryExpr _this, cx_operatorKind kind);

/* virtual ::cortex::Fast::BinaryExpr::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_BinaryExpr_toIc(Fast_BinaryExpr _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

/* ::cortex::Fast::BinaryExpr::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_BinaryExpr_toIc_v(Fast_BinaryExpr _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

#ifdef __cplusplus
}
#endif
#endif

