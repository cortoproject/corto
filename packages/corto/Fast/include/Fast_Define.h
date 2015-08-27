/* Fast_Define.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_Define_H
#define Fast_Define_H

#include "corto.h"
#include "Fast_Node.h"
#include "Fast__type.h"
#include "Fast__api.h"
#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto::Fast::Define::construct() */
cx_int16 _Fast_Define_construct(Fast_Define _this);
#define Fast_Define_construct(_this) _Fast_Define_construct(Fast_Define(_this))

/* virtual ::corto::Fast::Define::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node Fast_Define_toIc(Fast_Define _this, ic_program program, ic_storage storage, cx_bool stored);

/* ::corto::Fast::Define::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _Fast_Define_toIc_v(Fast_Define _this, ic_program program, ic_storage storage, cx_bool stored);
#define Fast_Define_toIc_v(_this, program, storage, stored) _Fast_Define_toIc_v(Fast_Define(_this), ic_program(program), ic_storage(storage), stored)

#ifdef __cplusplus
}
#endif
#endif

