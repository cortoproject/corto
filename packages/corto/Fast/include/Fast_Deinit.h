/* Fast_Deinit.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_Deinit_H
#define Fast_Deinit_H

#include "corto.h"
#include "Fast_Expression.h"
#include "Fast__type.h"
#include "Fast__api.h"
#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto::Fast::Deinit::construct() */
cx_int16 _Fast_Deinit_construct(Fast_Deinit _this);
#define Fast_Deinit_construct(_this) _Fast_Deinit_construct(Fast_Deinit(_this))

/* virtual ::corto::Fast::Deinit::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node Fast_Deinit_toIc(Fast_Deinit _this, ic_program program, ic_storage storage, cx_bool stored);

/* ::corto::Fast::Deinit::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _Fast_Deinit_toIc_v(Fast_Deinit _this, ic_program program, ic_storage storage, cx_bool stored);
#define Fast_Deinit_toIc_v(_this, program, storage, stored) _Fast_Deinit_toIc_v(Fast_Deinit(_this), ic_program(program), ic_storage(storage), stored)

#ifdef __cplusplus
}
#endif
#endif

