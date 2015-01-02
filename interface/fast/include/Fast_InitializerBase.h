/* Fast_InitializerBase.h
 *
 *  Generated on Apr  1 2014
 *    This file contains generated code. Do not modify!
 */

#ifndef Fast_InitializerBase_H
#define Fast_InitializerBase_H

#include "cortex.h"
#include "Fast__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* callback ::cortex::lang::class::construct(lang::object object) -> ::cortex::Fast::InitializerBase::construct(InitializerBase object) */
cx_int16 Fast_InitializerBase_construct(Fast_InitializerBase object);

/* ::cortex::Fast::InitializerBase::getType() */
cx_type Fast_InitializerBase_getType(Fast_InitializerBase _this);

/* virtual ::cortex::Fast::InitializerBase::member(lang::string name) */
cx_int32 Fast_InitializerBase_member(Fast_InitializerBase _this, cx_string name);

/* ::cortex::Fast::InitializerBase::member(lang::string name) */
cx_int32 Fast_InitializerBase_member_v(Fast_InitializerBase _this, cx_string name);

/* ::cortex::Fast::InitializerBase::next() */
cx_int16 Fast_InitializerBase_next(Fast_InitializerBase _this);

/* virtual ::cortex::Fast::InitializerBase::pop() */
cx_int8 Fast_InitializerBase_pop(Fast_InitializerBase _this);

/* ::cortex::Fast::InitializerBase::pop() */
cx_int8 Fast_InitializerBase_pop_v(Fast_InitializerBase _this);

/* virtual ::cortex::Fast::InitializerBase::push() */
cx_int16 Fast_InitializerBase_push(Fast_InitializerBase _this);

/* ::cortex::Fast::InitializerBase::push() */
cx_int16 Fast_InitializerBase_push_v(Fast_InitializerBase _this);

/* virtual ::cortex::Fast::InitializerBase::value(Expression v) */
cx_int16 Fast_InitializerBase_value(Fast_InitializerBase _this, Fast_Expression v);

/* ::cortex::Fast::InitializerBase::value(Expression v) */
cx_int16 Fast_InitializerBase_value_v(Fast_InitializerBase _this, Fast_Expression v);

#ifdef __cplusplus
}
#endif
#endif

