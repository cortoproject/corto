/* Fast_UnaryExpr.h
 *
 *  Generated on Nov 18 2014
 *    This file contains generated code. Do not modify!
 */

#ifndef Fast_UnaryExpr_H
#define Fast_UnaryExpr_H

#include "hyve.h"
#include "Fast_Expression.h"
#include "Fast__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* callback ::hyve::lang::class::construct(lang::object object) -> ::hyve::Fast::UnaryExpr::construct(Fast::UnaryExpr object) */
db_int16 Fast_UnaryExpr_construct(Fast_UnaryExpr object);

/* virtual ::hyve::Fast::UnaryExpr::hasSideEffects() */
db_bool Fast_UnaryExpr_hasSideEffects(Fast_UnaryExpr _this);

/* ::hyve::Fast::UnaryExpr::hasSideEffects() */
db_bool Fast_UnaryExpr_hasSideEffects_v(Fast_UnaryExpr _this);

/* virtual ::hyve::Fast::UnaryExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_UnaryExpr_toIc(Fast_UnaryExpr _this, db_icProgram program, db_icStorage storage, db_bool stored);

/* ::hyve::Fast::UnaryExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_UnaryExpr_toIc_v(Fast_UnaryExpr _this, db_icProgram program, db_icStorage storage, db_bool stored);

#ifdef __cplusplus
}
#endif
#endif

