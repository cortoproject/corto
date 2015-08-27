/* Fast_Update.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_Update_H
#define Fast_Update_H

#include "corto.h"
#include "Fast_Node.h"
#include "Fast__type.h"
#include "Fast__api.h"
#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto::Fast::Update::construct() */
cx_int16 _Fast_Update_construct(Fast_Update _this);
#define Fast_Update_construct(_this) _Fast_Update_construct(Fast_Update(_this))

/* virtual ::corto::Fast::Update::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node Fast_Update_toIc(Fast_Update _this, ic_program program, ic_storage storage, cx_bool stored);

/* ::corto::Fast::Update::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _Fast_Update_toIc_v(Fast_Update _this, ic_program program, ic_storage storage, cx_bool stored);
#define Fast_Update_toIc_v(_this, program, storage, stored) _Fast_Update_toIc_v(Fast_Update(_this), ic_program(program), ic_storage(storage), stored)

#ifdef __cplusplus
}
#endif
#endif

