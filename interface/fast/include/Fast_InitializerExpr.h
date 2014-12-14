/* Fast_InitializerExpr.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_InitializerExpr_H
#define Fast_InitializerExpr_H

#include "hyve.h"
#include "Fast_Initializer.h"
#include "Fast__type.h"

#include "Fast__api.h"

#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* callback ::hyve::lang::class::construct(lang::object object) -> ::hyve::Fast::InitializerExpr::construct(InitializerExpr object) */
db_int16 Fast_InitializerExpr_construct(Fast_InitializerExpr object);

/* ::hyve::Fast::InitializerExpr::define() */
db_int16 Fast_InitializerExpr_define(Fast_InitializerExpr _this);

/* ::hyve::Fast::InitializerExpr::insert(Expression variable) */
db_int16 Fast_InitializerExpr_insert(Fast_InitializerExpr _this, Fast_Expression variable);

/* ::hyve::Fast::InitializerExpr::member(lang::string name) */
db_int32 Fast_InitializerExpr_member(Fast_InitializerExpr _this, db_string name);

/* ::hyve::Fast::InitializerExpr::pop() */
db_int16 Fast_InitializerExpr_pop(Fast_InitializerExpr _this);

/* ::hyve::Fast::InitializerExpr::push() */
db_int16 Fast_InitializerExpr_push(Fast_InitializerExpr _this);

/* ::hyve::Fast::InitializerExpr::value(Expression v) */
db_int16 Fast_InitializerExpr_value(Fast_InitializerExpr _this, Fast_Expression v);

#ifdef __cplusplus
}
#endif
#endif

