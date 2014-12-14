/* Fast_StaticInitializer.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_StaticInitializer_H
#define Fast_StaticInitializer_H

#include "hyve.h"
#include "Fast_Initializer.h"
#include "Fast__type.h"

#include "Fast__api.h"

#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* callback ::hyve::lang::class::construct(lang::object object) -> ::hyve::Fast::StaticInitializer::construct(StaticInitializer object) */
db_int16 Fast_StaticInitializer_construct(Fast_StaticInitializer object);

/* ::hyve::Fast::StaticInitializer::define() */
db_int16 Fast_StaticInitializer_define(Fast_StaticInitializer _this);

/* ::hyve::Fast::StaticInitializer::push() */
db_int16 Fast_StaticInitializer_push(Fast_StaticInitializer _this);

/* ::hyve::Fast::StaticInitializer::value(Expression v) */
db_int16 Fast_StaticInitializer_value(Fast_StaticInitializer _this, Fast_Expression v);

#ifdef __cplusplus
}
#endif
#endif

