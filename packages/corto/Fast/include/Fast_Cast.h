/* Fast_Cast.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_Cast_H
#define Fast_Cast_H

#include "corto.h"
#include "Fast_Expression.h"
#include "Fast__type.h"
#include "Fast__api.h"
#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto::Fast::Cast::construct() */
cx_int16 _Fast_Cast_construct(Fast_Cast _this);
#define Fast_Cast_construct(_this) _Fast_Cast_construct(Fast_Cast(_this))

/* virtual ::corto::Fast::Cast::hasReturnedResource() */
cx_bool Fast_Cast_hasReturnedResource(Fast_Cast _this);

/* ::corto::Fast::Cast::hasReturnedResource() */
cx_bool _Fast_Cast_hasReturnedResource_v(Fast_Cast _this);
#define Fast_Cast_hasReturnedResource_v(_this) _Fast_Cast_hasReturnedResource_v(Fast_Cast(_this))

/* virtual ::corto::Fast::Cast::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node Fast_Cast_toIc(Fast_Cast _this, ic_program program, ic_storage storage, cx_bool stored);

/* ::corto::Fast::Cast::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _Fast_Cast_toIc_v(Fast_Cast _this, ic_program program, ic_storage storage, cx_bool stored);
#define Fast_Cast_toIc_v(_this, program, storage, stored) _Fast_Cast_toIc_v(Fast_Cast(_this), ic_program(program), ic_storage(storage), stored)

#ifdef __cplusplus
}
#endif
#endif

