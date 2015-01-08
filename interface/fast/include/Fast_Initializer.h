/* Fast_Initializer.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_Initializer_H
#define Fast_Initializer_H

#include "cortex.h"
#include "Fast_Expression.h"
#include "Fast__type.h"

#include "Fast__api.h"

#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* callback ::cortex::lang::class::construct(object object) -> ::cortex::Fast::Initializer::construct(Initializer object) */
cx_int16 Fast_Initializer_construct(Fast_Initializer object);

/* ::cortex::Fast::Initializer::currentType() */
cx_type Fast_Initializer_currentType(Fast_Initializer _this);

/* virtual ::cortex::Fast::Initializer::define() */
cx_int16 Fast_Initializer_define(Fast_Initializer _this);

/* ::cortex::Fast::Initializer::define() */
cx_int16 Fast_Initializer_define_v(Fast_Initializer _this);

/* ::cortex::Fast::Initializer::initFrame() */
cx_uint16 Fast_Initializer_initFrame(Fast_Initializer _this);

/* virtual ::cortex::Fast::Initializer::member(string name) */
cx_int32 Fast_Initializer_member(Fast_Initializer _this, cx_string name);

/* ::cortex::Fast::Initializer::member(string name) */
cx_int32 Fast_Initializer_member_v(Fast_Initializer _this, cx_string name);

/* virtual ::cortex::Fast::Initializer::next() */
cx_int16 Fast_Initializer_next(Fast_Initializer _this);

/* ::cortex::Fast::Initializer::next() */
cx_int16 Fast_Initializer_next_v(Fast_Initializer _this);

/* virtual ::cortex::Fast::Initializer::pop() */
cx_int8 Fast_Initializer_pop(Fast_Initializer _this);

/* ::cortex::Fast::Initializer::pop() */
cx_int8 Fast_Initializer_pop_v(Fast_Initializer _this);

/* virtual ::cortex::Fast::Initializer::popKey() */
cx_int16 Fast_Initializer_popKey(Fast_Initializer _this);

/* ::cortex::Fast::Initializer::popKey() */
cx_int16 Fast_Initializer_popKey_v(Fast_Initializer _this);

/* virtual ::cortex::Fast::Initializer::push() */
cx_int16 Fast_Initializer_push(Fast_Initializer _this);

/* ::cortex::Fast::Initializer::push() */
cx_int16 Fast_Initializer_push_v(Fast_Initializer _this);

/* virtual ::cortex::Fast::Initializer::pushKey() */
cx_int16 Fast_Initializer_pushKey(Fast_Initializer _this);

/* ::cortex::Fast::Initializer::pushKey() */
cx_int16 Fast_Initializer_pushKey_v(Fast_Initializer _this);

/* ::cortex::Fast::Initializer::type() */
cx_type Fast_Initializer_type(Fast_Initializer _this);

/* virtual ::cortex::Fast::Initializer::value(Expression v) */
cx_int16 Fast_Initializer_value(Fast_Initializer _this, Fast_Expression v);

/* ::cortex::Fast::Initializer::value(Expression v) */
cx_int16 Fast_Initializer_value_v(Fast_Initializer _this, Fast_Expression v);

/* virtual ::cortex::Fast::Initializer::valueKey(Expression key) */
cx_int16 Fast_Initializer_valueKey(Fast_Initializer _this, Fast_Expression key);

/* ::cortex::Fast::Initializer::valueKey(Expression key) */
cx_int16 Fast_Initializer_valueKey_v(Fast_Initializer _this, Fast_Expression key);

#ifdef __cplusplus
}
#endif
#endif

