/* Fast_Character.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_Character_H
#define Fast_Character_H

#include "cortex.h"
#include "Fast_Literal.h"
#include "Fast__type.h"

#include "Fast__api.h"

#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::cortex::Fast::Character::init() */
cx_int16 Fast_Character_init(Fast_Character _this);

/* ::cortex::Fast::Character::serialize(type dstType,word dst) */
cx_int16 Fast_Character_serialize(Fast_Character _this, cx_type dstType, cx_word dst);

/* virtual ::cortex::Fast::Character::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_Character_toIc(Fast_Character _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

/* ::cortex::Fast::Character::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
cx_ic Fast_Character_toIc_v(Fast_Character _this, cx_icProgram program, cx_icStorage storage, cx_bool stored);

#ifdef __cplusplus
}
#endif
#endif

