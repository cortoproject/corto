/* Fast_Character.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_Character_H
#define Fast_Character_H

#include "corto.h"
#include "Fast_Literal.h"
#include "Fast__type.h"
#include "Fast__api.h"
#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto::Fast::Character::init() */
cx_int16 _Fast_Character_init(Fast_Character _this);
#define Fast_Character_init(_this) _Fast_Character_init(Fast_Character(_this))

/* ::corto::Fast::Character::serialize(type dstType,word dst) */
cx_int16 _Fast_Character_serialize(Fast_Character _this, cx_type dstType, cx_word dst);
#define Fast_Character_serialize(_this, dstType, dst) _Fast_Character_serialize(Fast_Character(_this), cx_type(dstType), dst)

/* virtual ::corto::Fast::Character::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node Fast_Character_toIc(Fast_Character _this, ic_program program, ic_storage storage, cx_bool stored);

/* ::corto::Fast::Character::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _Fast_Character_toIc_v(Fast_Character _this, ic_program program, ic_storage storage, cx_bool stored);
#define Fast_Character_toIc_v(_this, program, storage, stored) _Fast_Character_toIc_v(Fast_Character(_this), ic_program(program), ic_storage(storage), stored)

#ifdef __cplusplus
}
#endif
#endif

