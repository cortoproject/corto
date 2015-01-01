/* Fast_InitializerExpr.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_InitializerExpr_H
#define Fast_InitializerExpr_H

#include "cortex.h"
#include "Fast_Initializer.h"
#include "Fast__type.h"

#include "Fast__api.h"

#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* callback ::cortex::lang::class::construct(lang::object object) -> ::cortex::Fast::InitializerExpr::construct(InitializerExpr object) */
db_int16 Fast_InitializerExpr_construct(Fast_InitializerExpr object);

/* ::cortex::Fast::InitializerExpr::define() */
db_int16 Fast_InitializerExpr_define(Fast_InitializerExpr _this);

/* ::cortex::Fast::InitializerExpr::insert(Expression variable) */
db_int16 Fast_InitializerExpr_insert(Fast_InitializerExpr _this, Fast_Expression variable);

/* ::cortex::Fast::InitializerExpr::member(lang::string name) */
db_int32 Fast_InitializerExpr_member(Fast_InitializerExpr _this, db_string name);

/* ::cortex::Fast::InitializerExpr::pop() */
db_int16 Fast_InitializerExpr_pop(Fast_InitializerExpr _this);

/* ::cortex::Fast::InitializerExpr::push() */
db_int16 Fast_InitializerExpr_push(Fast_InitializerExpr _this);

/* ::cortex::Fast::InitializerExpr::value(Expression v) */
db_int16 Fast_InitializerExpr_value(Fast_InitializerExpr _this, Fast_Expression v);

#ifdef __cplusplus
}
#endif
#endif

