/* Fast_Boolean.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_Boolean_H
#define Fast_Boolean_H

#include "corto.h"
#include "Fast_Literal.h"
#include "Fast__type.h"
#include "Fast__api.h"
#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto::Fast::Boolean::init() */
cx_int16 _Fast_Boolean_init(Fast_Boolean _this);
#define Fast_Boolean_init(_this) _Fast_Boolean_init(Fast_Boolean(_this))

/* ::corto::Fast::Boolean::serialize(type dstType,word dst) */
cx_int16 _Fast_Boolean_serialize(Fast_Boolean _this, cx_type dstType, cx_word dst);
#define Fast_Boolean_serialize(_this, dstType, dst) _Fast_Boolean_serialize(Fast_Boolean(_this), cx_type(dstType), dst)

/* virtual ::corto::Fast::Boolean::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node Fast_Boolean_toIc(Fast_Boolean _this, ic_program program, ic_storage storage, cx_bool stored);

/* ::corto::Fast::Boolean::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _Fast_Boolean_toIc_v(Fast_Boolean _this, ic_program program, ic_storage storage, cx_bool stored);
#define Fast_Boolean_toIc_v(_this, program, storage, stored) _Fast_Boolean_toIc_v(Fast_Boolean(_this), ic_program(program), ic_storage(storage), stored)

#ifdef __cplusplus
}
#endif
#endif

