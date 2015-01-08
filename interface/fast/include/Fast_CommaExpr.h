/* Fast_CommaExpr.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_CommaExpr_H
#define Fast_CommaExpr_H

#include "cortex.h"
#include "Fast_Expression.h"
#include "Fast__type.h"

#include "Fast__api.h"

#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::cortex::Fast::CommaExpr::addExpression(Expression expr) */
cx_int16 Fast_CommaExpr_addExpression(Fast_CommaExpr _this, Fast_Expression expr);

/* ::cortex::Fast::CommaExpr::addOrCreate(Expression list,Expression expr) */
Fast_Expression Fast_CommaExpr_addOrCreate(Fast_Expression list, Fast_Expression expr);

/* callback ::cortex::lang::class::construct(object object) -> ::cortex::Fast::CommaExpr::construct(CommaExpr object) */
cx_int16 Fast_CommaExpr_construct(Fast_CommaExpr object);

/* virtual ::cortex::Fast::CommaExpr::hasSideEffects() */
cx_bool Fast_CommaExpr_hasSideEffects(Fast_CommaExpr _this);

/* ::cortex::Fast::CommaExpr::hasSideEffects() */
cx_bool Fast_CommaExpr_hasSideEffects_v(Fast_CommaExpr _this);

/* callback ::cortex::lang::type::init(object object) -> ::cortex::Fast::CommaExpr::init(CommaExpr object) */
cx_int16 Fast_CommaExpr_init(Fast_CommaExpr object);

/* virtual ::cortex::Fast::CommaExpr::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_CommaExpr_toIc(Fast_CommaExpr _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

/* ::cortex::Fast::CommaExpr::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_CommaExpr_toIc_v(Fast_CommaExpr _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

/* ::cortex::Fast::CommaExpr::toList() */
Fast_Node_list Fast_CommaExpr_toList(Fast_CommaExpr _this);

#ifdef __cplusplus
}
#endif
#endif

