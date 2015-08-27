/* Fast_Wait.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_Wait_H
#define Fast_Wait_H

#include "corto.h"
#include "Fast_Expression.h"
#include "Fast__type.h"
#include "Fast__api.h"
#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto::Fast::Wait::construct() */
cx_int16 _Fast_Wait_construct(Fast_Wait _this);
#define Fast_Wait_construct(_this) _Fast_Wait_construct(Fast_Wait(_this))

/* virtual ::corto::Fast::Wait::hasReturnedResource() */
cx_bool Fast_Wait_hasReturnedResource(Fast_Wait _this);

/* ::corto::Fast::Wait::hasReturnedResource() */
cx_bool _Fast_Wait_hasReturnedResource_v(Fast_Wait _this);
#define Fast_Wait_hasReturnedResource_v(_this) _Fast_Wait_hasReturnedResource_v(Fast_Wait(_this))

/* virtual ::corto::Fast::Wait::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node Fast_Wait_toIc(Fast_Wait _this, ic_program program, ic_storage storage, cx_bool stored);

/* ::corto::Fast::Wait::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _Fast_Wait_toIc_v(Fast_Wait _this, ic_program program, ic_storage storage, cx_bool stored);
#define Fast_Wait_toIc_v(_this, program, storage, stored) _Fast_Wait_toIc_v(Fast_Wait(_this), ic_program(program), ic_storage(storage), stored)

#ifdef __cplusplus
}
#endif
#endif

