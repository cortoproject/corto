/* Fast_Null.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_Null_H
#define Fast_Null_H

#include "corto.h"
#include "Fast_Literal.h"
#include "Fast__type.h"
#include "Fast__api.h"
#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto::Fast::Null::init() */
cx_int16 _Fast_Null_init(Fast_Null _this);
#define Fast_Null_init(_this) _Fast_Null_init(Fast_Null(_this))

/* ::corto::Fast::Null::serialize(type dstType,word dst) */
cx_int16 _Fast_Null_serialize(Fast_Null _this, cx_type dstType, cx_word dst);
#define Fast_Null_serialize(_this, dstType, dst) _Fast_Null_serialize(Fast_Null(_this), cx_type(dstType), dst)

/* virtual ::corto::Fast::Null::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node Fast_Null_toIc(Fast_Null _this, ic_program program, ic_storage storage, cx_bool stored);

/* ::corto::Fast::Null::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _Fast_Null_toIc_v(Fast_Null _this, ic_program program, ic_storage storage, cx_bool stored);
#define Fast_Null_toIc_v(_this, program, storage, stored) _Fast_Null_toIc_v(Fast_Null(_this), ic_program(program), ic_storage(storage), stored)

#ifdef __cplusplus
}
#endif
#endif

