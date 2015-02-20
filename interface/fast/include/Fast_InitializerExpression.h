/* Fast_InitializerExpression.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_InitializerExpression_H
#define Fast_InitializerExpression_H

#include "cortex.h"
#include "Fast_Initializer.h"
#include "Fast__type.h"

#include "Fast__api.h"

#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::cortex::Fast::InitializerExpression::construct() */
cx_int16 Fast_InitializerExpression_construct(Fast_InitializerExpression _this);

/* ::cortex::Fast::InitializerExpression::define() */
cx_int16 Fast_InitializerExpression_define(Fast_InitializerExpression _this);

/* ::cortex::Fast::InitializerExpression::insert(Expression variable) */
cx_int16 Fast_InitializerExpression_insert(Fast_InitializerExpression _this, Fast_Expression variable);

/* ::cortex::Fast::InitializerExpression::member(string name) */
cx_int32 Fast_InitializerExpression_member(Fast_InitializerExpression _this, cx_string name);

/* ::cortex::Fast::InitializerExpression::pop() */
cx_int16 Fast_InitializerExpression_pop(Fast_InitializerExpression _this);

/* ::cortex::Fast::InitializerExpression::push() */
cx_int16 Fast_InitializerExpression_push(Fast_InitializerExpression _this);

/* ::cortex::Fast::InitializerExpression::value(Expression v) */
cx_int16 Fast_InitializerExpression_value(Fast_InitializerExpression _this, Fast_Expression v);

#ifdef __cplusplus
}
#endif
#endif

