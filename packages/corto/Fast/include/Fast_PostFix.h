/* Fast_PostFix.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_PostFix_H
#define Fast_PostFix_H

#include "corto.h"
#include "Fast_Expression.h"
#include "Fast__type.h"
#include "Fast__api.h"
#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto::Fast::PostFix::construct() */
cx_int16 _Fast_PostFix_construct(Fast_PostFix _this);
#define Fast_PostFix_construct(_this) _Fast_PostFix_construct(Fast_PostFix(_this))

/* virtual ::corto::Fast::PostFix::hasReturnedResource() */
cx_bool Fast_PostFix_hasReturnedResource(Fast_PostFix _this);

/* ::corto::Fast::PostFix::hasReturnedResource() */
cx_bool _Fast_PostFix_hasReturnedResource_v(Fast_PostFix _this);
#define Fast_PostFix_hasReturnedResource_v(_this) _Fast_PostFix_hasReturnedResource_v(Fast_PostFix(_this))

/* virtual ::corto::Fast::PostFix::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node Fast_PostFix_toIc(Fast_PostFix _this, ic_program program, ic_storage storage, cx_bool stored);

/* ::corto::Fast::PostFix::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _Fast_PostFix_toIc_v(Fast_PostFix _this, ic_program program, ic_storage storage, cx_bool stored);
#define Fast_PostFix_toIc_v(_this, program, storage, stored) _Fast_PostFix_toIc_v(Fast_PostFix(_this), ic_program(program), ic_storage(storage), stored)

#ifdef __cplusplus
}
#endif
#endif

