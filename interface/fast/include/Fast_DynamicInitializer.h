/* Fast_DynamicInitializer.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_DynamicInitializer_H
#define Fast_DynamicInitializer_H

#include "cortex.h"
#include "Fast_Initializer.h"
#include "Fast__type.h"

#include "Fast__api.h"

#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* callback ::cortex::lang::class::construct(object object) -> ::cortex::Fast::DynamicInitializer::construct(DynamicInitializer object) */
cx_int16 Fast_DynamicInitializer_construct(Fast_DynamicInitializer object);

/* ::cortex::Fast::DynamicInitializer::define() */
cx_int16 Fast_DynamicInitializer_define(Fast_DynamicInitializer _this);

/* ::cortex::Fast::DynamicInitializer::pop() */
cx_int16 Fast_DynamicInitializer_pop(Fast_DynamicInitializer _this);

/* ::cortex::Fast::DynamicInitializer::push() */
cx_int16 Fast_DynamicInitializer_push(Fast_DynamicInitializer _this);

/* ::cortex::Fast::DynamicInitializer::value(Expression v) */
cx_int16 Fast_DynamicInitializer_value(Fast_DynamicInitializer _this, Fast_Expression v);

#ifdef __cplusplus
}
#endif
#endif

