/* Fast_Initializer.h
 *
 *  Generated on Nov 18 2014
 *    This file contains generated code. Do not modify!
 */

#ifndef Fast_Initializer_H
#define Fast_Initializer_H

#include "hyve.h"
#include "Fast_Expression.h"
#include "Fast__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* callback ::hyve::lang::class::construct(lang::object object) -> ::hyve::Fast::Initializer::construct(Initializer object) */
db_int16 Fast_Initializer_construct(Fast_Initializer object);

/* ::hyve::Fast::Initializer::currentType() */
db_type Fast_Initializer_currentType(Fast_Initializer _this);

/* virtual ::hyve::Fast::Initializer::define() */
db_int16 Fast_Initializer_define(Fast_Initializer _this);

/* ::hyve::Fast::Initializer::define() */
db_int16 Fast_Initializer_define_v(Fast_Initializer _this);

/* ::hyve::Fast::Initializer::initFrame() */
db_uint16 Fast_Initializer_initFrame(Fast_Initializer _this);

/* virtual ::hyve::Fast::Initializer::member(lang::string name) */
db_int32 Fast_Initializer_member(Fast_Initializer _this, db_string name);

/* ::hyve::Fast::Initializer::member(lang::string name) */
db_int32 Fast_Initializer_member_v(Fast_Initializer _this, db_string name);

/* virtual ::hyve::Fast::Initializer::next() */
db_int16 Fast_Initializer_next(Fast_Initializer _this);

/* ::hyve::Fast::Initializer::next() */
db_int16 Fast_Initializer_next_v(Fast_Initializer _this);

/* virtual ::hyve::Fast::Initializer::pop() */
db_int8 Fast_Initializer_pop(Fast_Initializer _this);

/* ::hyve::Fast::Initializer::pop() */
db_int8 Fast_Initializer_pop_v(Fast_Initializer _this);

/* virtual ::hyve::Fast::Initializer::popKey() */
db_int16 Fast_Initializer_popKey(Fast_Initializer _this);

/* ::hyve::Fast::Initializer::popKey() */
db_int16 Fast_Initializer_popKey_v(Fast_Initializer _this);

/* virtual ::hyve::Fast::Initializer::push() */
db_int16 Fast_Initializer_push(Fast_Initializer _this);

/* ::hyve::Fast::Initializer::push() */
db_int16 Fast_Initializer_push_v(Fast_Initializer _this);

/* virtual ::hyve::Fast::Initializer::pushKey() */
db_int16 Fast_Initializer_pushKey(Fast_Initializer _this);

/* ::hyve::Fast::Initializer::pushKey() */
db_int16 Fast_Initializer_pushKey_v(Fast_Initializer _this);

/* ::hyve::Fast::Initializer::type() */
db_type Fast_Initializer_type(Fast_Initializer _this);

/* virtual ::hyve::Fast::Initializer::value(Expression v) */
db_int16 Fast_Initializer_value(Fast_Initializer _this, Fast_Expression v);

/* ::hyve::Fast::Initializer::value(Expression v) */
db_int16 Fast_Initializer_value_v(Fast_Initializer _this, Fast_Expression v);

/* virtual ::hyve::Fast::Initializer::valueKey(Expression key) */
db_int16 Fast_Initializer_valueKey(Fast_Initializer _this, Fast_Expression key);

/* ::hyve::Fast::Initializer::valueKey(Expression key) */
db_int16 Fast_Initializer_valueKey_v(Fast_Initializer _this, Fast_Expression key);

#ifdef __cplusplus
}
#endif
#endif

