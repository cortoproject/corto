/* Fast_Local.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_Local_H
#define Fast_Local_H

#include "corto.h"
#include "Fast_Storage.h"
#include "Fast__type.h"
#include "Fast__api.h"
#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto::Fast::Local::construct() */
cx_int16 _Fast_Local_construct(Fast_Local _this);
#define Fast_Local_construct(_this) _Fast_Local_construct(Fast_Local(_this))

/* virtual ::corto::Fast::Local::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node Fast_Local_toIc(Fast_Local _this, ic_program program, ic_storage storage, cx_bool stored);

/* ::corto::Fast::Local::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _Fast_Local_toIc_v(Fast_Local _this, ic_program program, ic_storage storage, cx_bool stored);
#define Fast_Local_toIc_v(_this, program, storage, stored) _Fast_Local_toIc_v(Fast_Local(_this), ic_program(program), ic_storage(storage), stored)

#ifdef __cplusplus
}
#endif
#endif

