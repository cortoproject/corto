/* Fast_New.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_New_H
#define Fast_New_H

#include "corto.h"
#include "Fast_Expression.h"
#include "Fast__type.h"
#include "Fast__api.h"
#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto::Fast::New::construct() */
cx_int16 _Fast_New_construct(Fast_New _this);
#define Fast_New_construct(_this) _Fast_New_construct(Fast_New(_this))

/* virtual ::corto::Fast::New::hasSideEffects() */
cx_bool Fast_New_hasSideEffects(Fast_New _this);

/* ::corto::Fast::New::hasSideEffects() */
cx_bool _Fast_New_hasSideEffects_v(Fast_New _this);
#define Fast_New_hasSideEffects_v(_this) _Fast_New_hasSideEffects_v(Fast_New(_this))

/* virtual ::corto::Fast::New::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node Fast_New_toIc(Fast_New _this, ic_program program, ic_storage storage, cx_bool stored);

/* ::corto::Fast::New::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _Fast_New_toIc_v(Fast_New _this, ic_program program, ic_storage storage, cx_bool stored);
#define Fast_New_toIc_v(_this, program, storage, stored) _Fast_New_toIc_v(Fast_New(_this), ic_program(program), ic_storage(storage), stored)

#ifdef __cplusplus
}
#endif
#endif

