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

/* callback ::cortex::lang::class::construct(lang::object object) -> ::cortex::Fast::TernaryExpr::construct(Fast::TernaryExpr object) */
db_int16 Fast_TernaryExpr_construct(Fast_TernaryExpr object);

/* virtual ::cortex::Fast::TernaryExpr::hasSideEffects() */
db_bool Fast_TernaryExpr_hasSideEffects(Fast_TernaryExpr _this);

/* ::cortex::Fast::TernaryExpr::hasSideEffects() */
db_bool Fast_TernaryExpr_hasSideEffects_v(Fast_TernaryExpr _this);

/* ::cortex::Fast::TernaryExpr::setOperator(lang::operatorKind kind) */
db_void Fast_TernaryExpr_setOperator(Fast_TernaryExpr _this, db_operatorKind kind);

/* virtual ::cortex::Fast::TernaryExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_TernaryExpr_toIc(Fast_TernaryExpr _this, db_icProgram program, db_icStorage storage, db_bool stored);

/* ::cortex::Fast::TernaryExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_TernaryExpr_toIc_v(Fast_TernaryExpr _this, db_icProgram program, db_icStorage storage, db_bool stored);

#ifdef __cplusplus
}
#endif
#endif

