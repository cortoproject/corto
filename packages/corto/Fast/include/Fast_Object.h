/* Fast_Object.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_Object_H
#define Fast_Object_H

#include "corto.h"
#include "Fast_Storage.h"
#include "Fast__type.h"
#include "Fast__api.h"
#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto::Fast::Object::construct() */
cx_int16 _Fast_Object_construct(Fast_Object _this);
#define Fast_Object_construct(_this) _Fast_Object_construct(Fast_Object(_this))

/* ::corto::Fast::Object::getValue() */
cx_word _Fast_Object_getValue(Fast_Object _this);
#define Fast_Object_getValue(_this) _Fast_Object_getValue(Fast_Object(_this))

/* ::corto::Fast::Object::serialize(type dstType,word dst) */
cx_int16 _Fast_Object_serialize(Fast_Object _this, cx_type dstType, cx_word dst);
#define Fast_Object_serialize(_this, dstType, dst) _Fast_Object_serialize(Fast_Object(_this), cx_type(dstType), dst)

/* virtual ::corto::Fast::Object::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node Fast_Object_toIc(Fast_Object _this, ic_program program, ic_storage storage, cx_bool stored);

/* ::corto::Fast::Object::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _Fast_Object_toIc_v(Fast_Object _this, ic_program program, ic_storage storage, cx_bool stored);
#define Fast_Object_toIc_v(_this, program, storage, stored) _Fast_Object_toIc_v(Fast_Object(_this), ic_program(program), ic_storage(storage), stored)

#ifdef __cplusplus
}
#endif
#endif

