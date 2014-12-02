/* Fast_Character.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_Character_H
#define Fast_Character_H

#include "hyve.h"
#include "Fast_Literal.h"
#include "Fast__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* callback ::hyve::lang::type::init(lang::object object) -> ::hyve::Fast::Character::init(Character object) */
db_int16 Fast_Character_init(Fast_Character object);

/* ::hyve::Fast::Character::serialize(lang::type dstType,lang::word dst) */
db_int16 Fast_Character_serialize(Fast_Character _this, db_type dstType, db_word dst);

/* virtual ::hyve::Fast::Character::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_Character_toIc(Fast_Character _this, db_icProgram program, db_icStorage storage, db_bool stored);

/* ::hyve::Fast::Character::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
db_ic Fast_Character_toIc_v(Fast_Character _this, db_icProgram program, db_icStorage storage, db_bool stored);

#ifdef __cplusplus
}
#endif
#endif

