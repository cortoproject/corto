/* Fast_Initializer.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_Initializer_H
#define Fast_Initializer_H

#include "corto.h"
#include "Fast_Expression.h"
#include "Fast__type.h"
#include "Fast__api.h"
#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto::Fast::Initializer::construct() */
cx_int16 _Fast_Initializer_construct(Fast_Initializer _this);
#define Fast_Initializer_construct(_this) _Fast_Initializer_construct(Fast_Initializer(_this))

/* ::corto::Fast::Initializer::currentType() */
cx_type _Fast_Initializer_currentType(Fast_Initializer _this);
#define Fast_Initializer_currentType(_this) _Fast_Initializer_currentType(Fast_Initializer(_this))

/* virtual ::corto::Fast::Initializer::define() */
cx_int16 Fast_Initializer_define(Fast_Initializer _this);

/* ::corto::Fast::Initializer::define() */
cx_int16 _Fast_Initializer_define_v(Fast_Initializer _this);
#define Fast_Initializer_define_v(_this) _Fast_Initializer_define_v(Fast_Initializer(_this))

/* ::corto::Fast::Initializer::initFrame() */
cx_uint16 _Fast_Initializer_initFrame(Fast_Initializer _this);
#define Fast_Initializer_initFrame(_this) _Fast_Initializer_initFrame(Fast_Initializer(_this))

/* virtual ::corto::Fast::Initializer::member(string name) */
cx_int32 Fast_Initializer_member(Fast_Initializer _this, cx_string name);

/* ::corto::Fast::Initializer::member(string name) */
cx_int32 _Fast_Initializer_member_v(Fast_Initializer _this, cx_string name);
#define Fast_Initializer_member_v(_this, name) _Fast_Initializer_member_v(Fast_Initializer(_this), name)

/* virtual ::corto::Fast::Initializer::next() */
cx_int16 Fast_Initializer_next(Fast_Initializer _this);

/* ::corto::Fast::Initializer::next() */
cx_int16 _Fast_Initializer_next_v(Fast_Initializer _this);
#define Fast_Initializer_next_v(_this) _Fast_Initializer_next_v(Fast_Initializer(_this))

/* virtual ::corto::Fast::Initializer::pop() */
cx_int8 Fast_Initializer_pop(Fast_Initializer _this);

/* ::corto::Fast::Initializer::pop() */
cx_int8 _Fast_Initializer_pop_v(Fast_Initializer _this);
#define Fast_Initializer_pop_v(_this) _Fast_Initializer_pop_v(Fast_Initializer(_this))

/* virtual ::corto::Fast::Initializer::popKey() */
cx_int16 Fast_Initializer_popKey(Fast_Initializer _this);

/* ::corto::Fast::Initializer::popKey() */
cx_int16 _Fast_Initializer_popKey_v(Fast_Initializer _this);
#define Fast_Initializer_popKey_v(_this) _Fast_Initializer_popKey_v(Fast_Initializer(_this))

/* virtual ::corto::Fast::Initializer::push() */
cx_int16 Fast_Initializer_push(Fast_Initializer _this);

/* ::corto::Fast::Initializer::push() */
cx_int16 _Fast_Initializer_push_v(Fast_Initializer _this);
#define Fast_Initializer_push_v(_this) _Fast_Initializer_push_v(Fast_Initializer(_this))

/* virtual ::corto::Fast::Initializer::pushKey() */
cx_int16 Fast_Initializer_pushKey(Fast_Initializer _this);

/* ::corto::Fast::Initializer::pushKey() */
cx_int16 _Fast_Initializer_pushKey_v(Fast_Initializer _this);
#define Fast_Initializer_pushKey_v(_this) _Fast_Initializer_pushKey_v(Fast_Initializer(_this))

/* ::corto::Fast::Initializer::type() */
cx_type _Fast_Initializer_type(Fast_Initializer _this);
#define Fast_Initializer_type(_this) _Fast_Initializer_type(Fast_Initializer(_this))

/* virtual ::corto::Fast::Initializer::value(Expression v) */
cx_int16 Fast_Initializer_value(Fast_Initializer _this, Fast_Expression v);

/* ::corto::Fast::Initializer::value(Expression v) */
cx_int16 _Fast_Initializer_value_v(Fast_Initializer _this, Fast_Expression v);
#define Fast_Initializer_value_v(_this, v) _Fast_Initializer_value_v(Fast_Initializer(_this), Fast_Expression(v))

/* virtual ::corto::Fast::Initializer::valueKey(Expression key) */
cx_int16 Fast_Initializer_valueKey(Fast_Initializer _this, Fast_Expression key);

/* ::corto::Fast::Initializer::valueKey(Expression key) */
cx_int16 _Fast_Initializer_valueKey_v(Fast_Initializer _this, Fast_Expression key);
#define Fast_Initializer_valueKey_v(_this, key) _Fast_Initializer_valueKey_v(Fast_Initializer(_this), Fast_Expression(key))

#ifdef __cplusplus
}
#endif
#endif

