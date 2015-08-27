/* Fast_Binary.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_Binary_H
#define Fast_Binary_H

#include "corto.h"
#include "Fast_Expression.h"
#include "Fast__type.h"
#include "Fast__api.h"
#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto::Fast::Binary::construct() */
cx_int16 _Fast_Binary_construct(Fast_Binary _this);
#define Fast_Binary_construct(_this) _Fast_Binary_construct(Fast_Binary(_this))

/* ::corto::Fast::Binary::fold() */
Fast_Expression _Fast_Binary_fold(Fast_Binary _this);
#define Fast_Binary_fold(_this) _Fast_Binary_fold(Fast_Binary(_this))

/* virtual ::corto::Fast::Binary::hasReturnedResource() */
cx_bool Fast_Binary_hasReturnedResource(Fast_Binary _this);

/* ::corto::Fast::Binary::hasReturnedResource() */
cx_bool _Fast_Binary_hasReturnedResource_v(Fast_Binary _this);
#define Fast_Binary_hasReturnedResource_v(_this) _Fast_Binary_hasReturnedResource_v(Fast_Binary(_this))

/* virtual ::corto::Fast::Binary::hasSideEffects() */
cx_bool Fast_Binary_hasSideEffects(Fast_Binary _this);

/* ::corto::Fast::Binary::hasSideEffects() */
cx_bool _Fast_Binary_hasSideEffects_v(Fast_Binary _this);
#define Fast_Binary_hasSideEffects_v(_this) _Fast_Binary_hasSideEffects_v(Fast_Binary(_this))

/* ::corto::Fast::Binary::setOperator(operatorKind kind) */
cx_void _Fast_Binary_setOperator(Fast_Binary _this, cx_operatorKind kind);
#define Fast_Binary_setOperator(_this, kind) _Fast_Binary_setOperator(Fast_Binary(_this), kind)

/* virtual ::corto::Fast::Binary::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node Fast_Binary_toIc(Fast_Binary _this, ic_program program, ic_storage storage, cx_bool stored);

/* ::corto::Fast::Binary::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _Fast_Binary_toIc_v(Fast_Binary _this, ic_program program, ic_storage storage, cx_bool stored);
#define Fast_Binary_toIc_v(_this, program, storage, stored) _Fast_Binary_toIc_v(Fast_Binary(_this), ic_program(program), ic_storage(storage), stored)

#ifdef __cplusplus
}
#endif
#endif

