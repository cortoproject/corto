/* Fast_CommaExpr.h
 *
 *  Generated on Nov 18 2014
 *    This file contains generated code. Do not modify!
 */

#ifndef Fast_CommaExpr_H
#define Fast_CommaExpr_H

#include "hyve.h"
#include "Fast_Expression.h"
#include "Fast__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::hyve::Fast::CommaExpr::addExpression(Expression expr) */
db_int16 Fast_CommaExpr_addExpression(Fast_CommaExpr _this, Fast_Expression expr);

/* ::hyve::Fast::CommaExpr::addOrCreate(Expression list,Expression expr) */
Fast_Expression Fast_CommaExpr_addOrCreate(Fast_Expression list, Fast_Expression expr);

/* callback ::hyve::lang::class::construct(lang::object object) -> ::hyve::Fast::CommaExpr::construct(CommaExpr object) */
db_int16 Fast_CommaExpr_construct(Fast_CommaExpr object);

/* virtual ::hyve::Fast::CommaExpr::hasSideEffects() */
db_bool Fast_CommaExpr_hasSideEffects(Fast_CommaExpr _this);

/* ::hyve::Fast::CommaExpr::hasSideEffects() */
db_bool Fast_CommaExpr_hasSideEffects_v(Fast_CommaExpr _this);

/* callback ::hyve::lang::type::init(lang::object object) -> ::hyve::Fast::CommaExpr::init(CommaExpr object) */
db_int16 Fast_CommaExpr_init(Fast_CommaExpr object);

/* virtual ::hyve::Fast::CommaExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_CommaExpr_toIc(Fast_CommaExpr _this, db_icProgram program, db_icStorage storage, db_bool stored);

/* ::hyve::Fast::CommaExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_CommaExpr_toIc_v(Fast_CommaExpr _this, db_icProgram program, db_icStorage storage, db_bool stored);

/* ::hyve::Fast::CommaExpr::toList() */
Fast_Node_list Fast_CommaExpr_toList(Fast_CommaExpr _this);

#ifdef __cplusplus
}
#endif
#endif

