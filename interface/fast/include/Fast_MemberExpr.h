/* Fast_MemberExpr.h
 *
 *  Generated on Nov 18 2014
 *    This file contains generated code. Do not modify!
 */

#ifndef Fast_MemberExpr_H
#define Fast_MemberExpr_H

#include "hyve.h"
#include "Fast_Expression.h"
#include "Fast__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* callback ::hyve::lang::class::construct(lang::object object) -> ::hyve::Fast::MemberExpr::construct(Fast::MemberExpr object) */
db_int16 Fast_MemberExpr_construct(Fast_MemberExpr object);

/* virtual ::hyve::Fast::MemberExpr::hasSideEffects() */
db_bool Fast_MemberExpr_hasSideEffects(Fast_MemberExpr _this);

/* ::hyve::Fast::MemberExpr::hasSideEffects() */
db_bool Fast_MemberExpr_hasSideEffects_v(Fast_MemberExpr _this);

/* virtual ::hyve::Fast::MemberExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_MemberExpr_toIc(Fast_MemberExpr _this, db_icProgram program, db_icStorage storage, db_bool stored);

/* ::hyve::Fast::MemberExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_MemberExpr_toIc_v(Fast_MemberExpr _this, db_icProgram program, db_icStorage storage, db_bool stored);

#ifdef __cplusplus
}
#endif
#endif

