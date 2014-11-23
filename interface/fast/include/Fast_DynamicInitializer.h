/* Fast_DynamicInitializer.h
 *
 *  Generated on Nov 18 2014
 *    This file contains generated code. Do not modify!
 */

#ifndef Fast_DynamicInitializer_H
#define Fast_DynamicInitializer_H

#include "hyve.h"
#include "Fast_Initializer.h"
#include "Fast__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* callback ::hyve::lang::class::construct(lang::object object) -> ::hyve::Fast::DynamicInitializer::construct(DynamicInitializer object) */
db_int16 Fast_DynamicInitializer_construct(Fast_DynamicInitializer object);

/* ::hyve::Fast::DynamicInitializer::define() */
db_int16 Fast_DynamicInitializer_define(Fast_DynamicInitializer _this);

/* ::hyve::Fast::DynamicInitializer::pop() */
db_int16 Fast_DynamicInitializer_pop(Fast_DynamicInitializer _this);

/* ::hyve::Fast::DynamicInitializer::push() */
db_int16 Fast_DynamicInitializer_push(Fast_DynamicInitializer _this);

/* ::hyve::Fast::DynamicInitializer::value(Expression v) */
db_int16 Fast_DynamicInitializer_value(Fast_DynamicInitializer _this, Fast_Expression v);

#ifdef __cplusplus
}
#endif
#endif

