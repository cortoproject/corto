/* Fast_BinaryExpr.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_BinaryExpr_H
#define Fast_BinaryExpr_H

#include "hyve.h"
#include "Fast_Expression.h"
#include "Fast__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* callback ::hyve::lang::class::construct(lang::object object) -> ::hyve::Fast::BinaryExpr::construct(Fast::BinaryExpr object) */
db_int16 Fast_BinaryExpr_construct(Fast_BinaryExpr object);

/* ::hyve::Fast::BinaryExpr::fold() */
Fast_Expression Fast_BinaryExpr_fold(Fast_BinaryExpr _this);

/* virtual ::hyve::Fast::BinaryExpr::hasSideEffects() */
db_bool Fast_BinaryExpr_hasSideEffects(Fast_BinaryExpr _this);

/* ::hyve::Fast::BinaryExpr::hasSideEffects() */
db_bool Fast_BinaryExpr_hasSideEffects_v(Fast_BinaryExpr _this);

/* ::hyve::Fast::BinaryExpr::setOperator(lang::operatorKind kind) */
db_void Fast_BinaryExpr_setOperator(Fast_BinaryExpr _this, db_operatorKind kind);

/* virtual ::hyve::Fast::BinaryExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_BinaryExpr_toIc(Fast_BinaryExpr _this, db_icProgram program, db_icStorage storage, db_bool stored);

/* ::hyve::Fast::BinaryExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_BinaryExpr_toIc_v(Fast_BinaryExpr _this, db_icProgram program, db_icStorage storage, db_bool stored);

#ifdef __cplusplus
}
#endif
#endif

