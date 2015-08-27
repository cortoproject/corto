/* Fast_Call.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_Call_H
#define Fast_Call_H

#include "corto.h"
#include "Fast_Expression.h"
#include "Fast__type.h"
#include "Fast__api.h"
#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto::Fast::Call::construct() */
cx_int16 _Fast_Call_construct(Fast_Call _this);
#define Fast_Call_construct(_this) _Fast_Call_construct(Fast_Call(_this))

/* virtual ::corto::Fast::Call::hasReturnedResource() */
cx_bool Fast_Call_hasReturnedResource(Fast_Call _this);

/* ::corto::Fast::Call::hasReturnedResource() */
cx_bool _Fast_Call_hasReturnedResource_v(Fast_Call _this);
#define Fast_Call_hasReturnedResource_v(_this) _Fast_Call_hasReturnedResource_v(Fast_Call(_this))

/* virtual ::corto::Fast::Call::hasSideEffects() */
cx_bool Fast_Call_hasSideEffects(Fast_Call _this);

/* ::corto::Fast::Call::hasSideEffects() */
cx_bool _Fast_Call_hasSideEffects_v(Fast_Call _this);
#define Fast_Call_hasSideEffects_v(_this) _Fast_Call_hasSideEffects_v(Fast_Call(_this))

/* ::corto::Fast::Call::setParameters(function function) */
cx_void _Fast_Call_setParameters(Fast_Call _this, cx_function function);
#define Fast_Call_setParameters(_this, function) _Fast_Call_setParameters(Fast_Call(_this), cx_function(function))

/* virtual ::corto::Fast::Call::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node Fast_Call_toIc(Fast_Call _this, ic_program program, ic_storage storage, cx_bool stored);

/* ::corto::Fast::Call::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _Fast_Call_toIc_v(Fast_Call _this, ic_program program, ic_storage storage, cx_bool stored);
#define Fast_Call_toIc_v(_this, program, storage, stored) _Fast_Call_toIc_v(Fast_Call(_this), ic_program(program), ic_storage(storage), stored)

#ifdef __cplusplus
}
#endif
#endif

