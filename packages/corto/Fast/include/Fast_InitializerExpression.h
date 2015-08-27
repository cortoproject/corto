/* Fast_InitializerExpression.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_InitializerExpression_H
#define Fast_InitializerExpression_H

#include "corto.h"
#include "Fast_Initializer.h"
#include "Fast__type.h"
#include "Fast__api.h"
#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto::Fast::InitializerExpression::construct() */
cx_int16 _Fast_InitializerExpression_construct(Fast_InitializerExpression _this);
#define Fast_InitializerExpression_construct(_this) _Fast_InitializerExpression_construct(Fast_InitializerExpression(_this))

/* ::corto::Fast::InitializerExpression::define() */
cx_int16 _Fast_InitializerExpression_define(Fast_InitializerExpression _this);
#define Fast_InitializerExpression_define(_this) _Fast_InitializerExpression_define(Fast_InitializerExpression(_this))

/* virtual ::corto::Fast::InitializerExpression::hasReturnedResource() */
cx_bool Fast_InitializerExpression_hasReturnedResource(Fast_InitializerExpression _this);

/* ::corto::Fast::InitializerExpression::hasReturnedResource() */
cx_bool _Fast_InitializerExpression_hasReturnedResource_v(Fast_InitializerExpression _this);
#define Fast_InitializerExpression_hasReturnedResource_v(_this) _Fast_InitializerExpression_hasReturnedResource_v(Fast_InitializerExpression(_this))

/* ::corto::Fast::InitializerExpression::insert(Expression variable) */
cx_int16 _Fast_InitializerExpression_insert(Fast_InitializerExpression _this, Fast_Expression variable);
#define Fast_InitializerExpression_insert(_this, variable) _Fast_InitializerExpression_insert(Fast_InitializerExpression(_this), Fast_Expression(variable))

/* ::corto::Fast::InitializerExpression::member(string name) */
cx_int32 _Fast_InitializerExpression_member(Fast_InitializerExpression _this, cx_string name);
#define Fast_InitializerExpression_member(_this, name) _Fast_InitializerExpression_member(Fast_InitializerExpression(_this), name)

/* ::corto::Fast::InitializerExpression::pop() */
cx_int16 _Fast_InitializerExpression_pop(Fast_InitializerExpression _this);
#define Fast_InitializerExpression_pop(_this) _Fast_InitializerExpression_pop(Fast_InitializerExpression(_this))

/* ::corto::Fast::InitializerExpression::push() */
cx_int16 _Fast_InitializerExpression_push(Fast_InitializerExpression _this);
#define Fast_InitializerExpression_push(_this) _Fast_InitializerExpression_push(Fast_InitializerExpression(_this))

/* ::corto::Fast::InitializerExpression::value(Expression v) */
cx_int16 _Fast_InitializerExpression_value(Fast_InitializerExpression _this, Fast_Expression v);
#define Fast_InitializerExpression_value(_this, v) _Fast_InitializerExpression_value(Fast_InitializerExpression(_this), Fast_Expression(v))

#ifdef __cplusplus
}
#endif
#endif

