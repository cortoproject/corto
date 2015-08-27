/* Fast_FloatingPoint.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_FloatingPoint_H
#define Fast_FloatingPoint_H

#include "corto.h"
#include "Fast_Literal.h"
#include "Fast__type.h"
#include "Fast__api.h"
#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto::Fast::FloatingPoint::init() */
cx_int16 _Fast_FloatingPoint_init(Fast_FloatingPoint _this);
#define Fast_FloatingPoint_init(_this) _Fast_FloatingPoint_init(Fast_FloatingPoint(_this))

/* ::corto::Fast::FloatingPoint::serialize(type dstType,word dst) */
cx_int16 _Fast_FloatingPoint_serialize(Fast_FloatingPoint _this, cx_type dstType, cx_word dst);
#define Fast_FloatingPoint_serialize(_this, dstType, dst) _Fast_FloatingPoint_serialize(Fast_FloatingPoint(_this), cx_type(dstType), dst)

/* virtual ::corto::Fast::FloatingPoint::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node Fast_FloatingPoint_toIc(Fast_FloatingPoint _this, ic_program program, ic_storage storage, cx_bool stored);

/* ::corto::Fast::FloatingPoint::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _Fast_FloatingPoint_toIc_v(Fast_FloatingPoint _this, ic_program program, ic_storage storage, cx_bool stored);
#define Fast_FloatingPoint_toIc_v(_this, program, storage, stored) _Fast_FloatingPoint_toIc_v(Fast_FloatingPoint(_this), ic_program(program), ic_storage(storage), stored)

#ifdef __cplusplus
}
#endif
#endif

