/* Fast_String.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_String_H
#define Fast_String_H

#include "corto.h"
#include "Fast_Literal.h"
#include "Fast__type.h"
#include "Fast__api.h"
#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto::Fast::String::construct() */
cx_int16 _Fast_String_construct(Fast_String _this);
#define Fast_String_construct(_this) _Fast_String_construct(Fast_String(_this))

/* ::corto::Fast::String::getValue() */
cx_word _Fast_String_getValue(Fast_String _this);
#define Fast_String_getValue(_this) _Fast_String_getValue(Fast_String(_this))

/* ::corto::Fast::String::init() */
cx_int16 _Fast_String_init(Fast_String _this);
#define Fast_String_init(_this) _Fast_String_init(Fast_String(_this))

/* ::corto::Fast::String::serialize(type dstType,word dst) */
cx_int16 _Fast_String_serialize(Fast_String _this, cx_type dstType, cx_word dst);
#define Fast_String_serialize(_this, dstType, dst) _Fast_String_serialize(Fast_String(_this), cx_type(dstType), dst)

/* virtual ::corto::Fast::String::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node Fast_String_toIc(Fast_String _this, ic_program program, ic_storage storage, cx_bool stored);

/* ::corto::Fast::String::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _Fast_String_toIc_v(Fast_String _this, ic_program program, ic_storage storage, cx_bool stored);
#define Fast_String_toIc_v(_this, program, storage, stored) _Fast_String_toIc_v(Fast_String(_this), ic_program(program), ic_storage(storage), stored)

#ifdef __cplusplus
}
#endif
#endif

