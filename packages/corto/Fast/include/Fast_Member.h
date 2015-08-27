/* Fast_Member.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_Member_H
#define Fast_Member_H

#include "corto.h"
#include "Fast_Storage.h"
#include "Fast__type.h"
#include "Fast__api.h"
#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto::Fast::Member::construct() */
cx_int16 _Fast_Member_construct(Fast_Member _this);
#define Fast_Member_construct(_this) _Fast_Member_construct(Fast_Member(_this))

/* virtual ::corto::Fast::Member::hasSideEffects() */
cx_bool Fast_Member_hasSideEffects(Fast_Member _this);

/* ::corto::Fast::Member::hasSideEffects() */
cx_bool _Fast_Member_hasSideEffects_v(Fast_Member _this);
#define Fast_Member_hasSideEffects_v(_this) _Fast_Member_hasSideEffects_v(Fast_Member(_this))

/* virtual ::corto::Fast::Member::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node Fast_Member_toIc(Fast_Member _this, ic_program program, ic_storage storage, cx_bool stored);

/* ::corto::Fast::Member::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _Fast_Member_toIc_v(Fast_Member _this, ic_program program, ic_storage storage, cx_bool stored);
#define Fast_Member_toIc_v(_this, program, storage, stored) _Fast_Member_toIc_v(Fast_Member(_this), ic_program(program), ic_storage(storage), stored)

#ifdef __cplusplus
}
#endif
#endif

