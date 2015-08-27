/* Fast_SignedInteger.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_SignedInteger_H
#define Fast_SignedInteger_H

#include "corto.h"
#include "Fast_Literal.h"
#include "Fast__type.h"
#include "Fast__api.h"
#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto::Fast::SignedInteger::init() */
cx_int16 _Fast_SignedInteger_init(Fast_SignedInteger _this);
#define Fast_SignedInteger_init(_this) _Fast_SignedInteger_init(Fast_SignedInteger(_this))

/* ::corto::Fast::SignedInteger::serialize(type dstType,word dst) */
cx_int16 _Fast_SignedInteger_serialize(Fast_SignedInteger _this, cx_type dstType, cx_word dst);
#define Fast_SignedInteger_serialize(_this, dstType, dst) _Fast_SignedInteger_serialize(Fast_SignedInteger(_this), cx_type(dstType), dst)

/* virtual ::corto::Fast::SignedInteger::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node Fast_SignedInteger_toIc(Fast_SignedInteger _this, ic_program program, ic_storage storage, cx_bool stored);

/* ::corto::Fast::SignedInteger::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _Fast_SignedInteger_toIc_v(Fast_SignedInteger _this, ic_program program, ic_storage storage, cx_bool stored);
#define Fast_SignedInteger_toIc_v(_this, program, storage, stored) _Fast_SignedInteger_toIc_v(Fast_SignedInteger(_this), ic_program(program), ic_storage(storage), stored)

#ifdef __cplusplus
}
#endif
#endif

