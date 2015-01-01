/* tc_Animal.h
 *
 *  Generated on Feb  5 2014
 *    This file contains generated code. Do not modify!
 */

#ifndef tc_Animal_H
#define tc_Animal_H

#include "cortex.h"
#include "tc_call__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::tc_call::Animal::getKind() */
tc_AnimalKind tc_Animal_getKind(tc_Animal _this);

/* virtual ::tc_call::Animal::matesWith(::tc_call::Animal m) */
cx_bool tc_Animal_matesWith(tc_Animal _this, tc_Animal m);

/* ::tc_call::Animal::matesWith(::tc_call::Animal m) */
cx_bool tc_Animal_matesWith_v(tc_Animal _this, tc_Animal m);

#ifdef __cplusplus
}
#endif
#endif

