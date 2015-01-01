/* tc_Mammal.h
 *
 *  Generated on Feb  5 2014
 *    This file contains generated code. Do not modify!
 */

#ifndef tc_Mammal_H
#define tc_Mammal_H

#include "cortex.h"
#include "tc_Animal.h"
#include "tc_call__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::tc_call::Mammal::getKind() */
tc_MammalKind tc_Mammal_getKind(tc_Mammal _this);

/* ::tc_call::Mammal::getProps(::cortex::lang::uint32 someValue) */
tc_MammalProps tc_Mammal_getProps(tc_Mammal _this, db_uint32 someValue);

/* ::tc_call::Mammal::getSpeed() */
db_float64 tc_Mammal_getSpeed(tc_Mammal _this);

/* callback ::cortex::lang::type::init(lang::object object) -> ::tc_call::Mammal::init(::tc_call::Mammal object) */
db_int16 tc_Mammal_init(tc_Mammal object);

/* virtual ::tc_call::Mammal::matesWith(::tc_call::Animal m) */
db_bool tc_Mammal_matesWith(tc_Mammal _this, tc_Animal m);

/* ::tc_call::Mammal::matesWith(::tc_call::Animal m) */
db_bool tc_Mammal_matesWith_v(tc_Mammal _this, tc_Animal m);

/* ::tc_call::Mammal::setProps(::tc_call::MammalProps props) */
db_void tc_Mammal_setProps(tc_Mammal _this, tc_MammalProps *props);

/* ::tc_call::Mammal::setSpeed(::cortex::lang::float64 speed) */
db_void tc_Mammal_setSpeed(tc_Mammal _this, db_float64 speed);

#ifdef __cplusplus
}
#endif
#endif

