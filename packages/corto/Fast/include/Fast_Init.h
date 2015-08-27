/* Fast_Init.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_Init_H
#define Fast_Init_H

#include "corto.h"
#include "Fast_Expression.h"
#include "Fast__type.h"
#include "Fast__api.h"
#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto::Fast::Init::construct() */
cx_int16 _Fast_Init_construct(Fast_Init _this);
#define Fast_Init_construct(_this) _Fast_Init_construct(Fast_Init(_this))

/* virtual ::corto::Fast::Init::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node Fast_Init_toIc(Fast_Init _this, ic_program program, ic_storage storage, cx_bool stored);

/* ::corto::Fast::Init::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _Fast_Init_toIc_v(Fast_Init _this, ic_program program, ic_storage storage, cx_bool stored);
#define Fast_Init_toIc_v(_this, program, storage, stored) _Fast_Init_toIc_v(Fast_Init(_this), ic_program(program), ic_storage(storage), stored)

#ifdef __cplusplus
}
#endif
#endif

