/* Fast_Unary.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_Unary_H
#define Fast_Unary_H

#include "corto.h"
#include "Fast_Expression.h"
#include "Fast__type.h"
#include "Fast__api.h"
#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto::Fast::Unary::construct() */
cx_int16 _Fast_Unary_construct(Fast_Unary _this);
#define Fast_Unary_construct(_this) _Fast_Unary_construct(Fast_Unary(_this))

/* virtual ::corto::Fast::Unary::hasReturnedResource() */
cx_bool Fast_Unary_hasReturnedResource(Fast_Unary _this);

/* ::corto::Fast::Unary::hasReturnedResource() */
cx_bool _Fast_Unary_hasReturnedResource_v(Fast_Unary _this);
#define Fast_Unary_hasReturnedResource_v(_this) _Fast_Unary_hasReturnedResource_v(Fast_Unary(_this))

/* virtual ::corto::Fast::Unary::hasSideEffects() */
cx_bool Fast_Unary_hasSideEffects(Fast_Unary _this);

/* ::corto::Fast::Unary::hasSideEffects() */
cx_bool _Fast_Unary_hasSideEffects_v(Fast_Unary _this);
#define Fast_Unary_hasSideEffects_v(_this) _Fast_Unary_hasSideEffects_v(Fast_Unary(_this))

/* virtual ::corto::Fast::Unary::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node Fast_Unary_toIc(Fast_Unary _this, ic_program program, ic_storage storage, cx_bool stored);

/* ::corto::Fast::Unary::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _Fast_Unary_toIc_v(Fast_Unary _this, ic_program program, ic_storage storage, cx_bool stored);
#define Fast_Unary_toIc_v(_this, program, storage, stored) _Fast_Unary_toIc_v(Fast_Unary(_this), ic_program(program), ic_storage(storage), stored)

#ifdef __cplusplus
}
#endif
#endif

