/* Fast_Ternary.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_Ternary_H
#define Fast_Ternary_H

#include "corto.h"
#include "Fast_Expression.h"
#include "Fast__type.h"
#include "Fast__api.h"
#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto::Fast::Ternary::construct() */
cx_int16 _Fast_Ternary_construct(Fast_Ternary _this);
#define Fast_Ternary_construct(_this) _Fast_Ternary_construct(Fast_Ternary(_this))

/* virtual ::corto::Fast::Ternary::hasReturnedResource() */
cx_bool Fast_Ternary_hasReturnedResource(Fast_Ternary _this);

/* ::corto::Fast::Ternary::hasReturnedResource() */
cx_bool _Fast_Ternary_hasReturnedResource_v(Fast_Ternary _this);
#define Fast_Ternary_hasReturnedResource_v(_this) _Fast_Ternary_hasReturnedResource_v(Fast_Ternary(_this))

/* virtual ::corto::Fast::Ternary::hasSideEffects() */
cx_bool Fast_Ternary_hasSideEffects(Fast_Ternary _this);

/* ::corto::Fast::Ternary::hasSideEffects() */
cx_bool _Fast_Ternary_hasSideEffects_v(Fast_Ternary _this);
#define Fast_Ternary_hasSideEffects_v(_this) _Fast_Ternary_hasSideEffects_v(Fast_Ternary(_this))

/* ::corto::Fast::Ternary::setOperator(operatorKind kind) */
cx_void _Fast_Ternary_setOperator(Fast_Ternary _this, cx_operatorKind kind);
#define Fast_Ternary_setOperator(_this, kind) _Fast_Ternary_setOperator(Fast_Ternary(_this), kind)

/* virtual ::corto::Fast::Ternary::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node Fast_Ternary_toIc(Fast_Ternary _this, ic_program program, ic_storage storage, cx_bool stored);

/* ::corto::Fast::Ternary::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _Fast_Ternary_toIc_v(Fast_Ternary _this, ic_program program, ic_storage storage, cx_bool stored);
#define Fast_Ternary_toIc_v(_this, program, storage, stored) _Fast_Ternary_toIc_v(Fast_Ternary(_this), ic_program(program), ic_storage(storage), stored)

#ifdef __cplusplus
}
#endif
#endif

