/* Fast_While.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_While_H
#define Fast_While_H

#include "corto.h"
#include "Fast_Node.h"
#include "Fast__type.h"
#include "Fast__api.h"
#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto::Fast::While::construct() */
cx_int16 _Fast_While_construct(Fast_While _this);
#define Fast_While_construct(_this) _Fast_While_construct(Fast_While(_this))

/* virtual ::corto::Fast::While::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node Fast_While_toIc(Fast_While _this, ic_program program, ic_storage storage, cx_bool stored);

/* ::corto::Fast::While::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _Fast_While_toIc_v(Fast_While _this, ic_program program, ic_storage storage, cx_bool stored);
#define Fast_While_toIc_v(_this, program, storage, stored) _Fast_While_toIc_v(Fast_While(_this), ic_program(program), ic_storage(storage), stored)

#ifdef __cplusplus
}
#endif
#endif

