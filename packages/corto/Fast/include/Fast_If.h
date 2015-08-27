/* Fast_If.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_If_H
#define Fast_If_H

#include "corto.h"
#include "Fast_Node.h"
#include "Fast__type.h"
#include "Fast__api.h"
#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto::Fast::If::construct() */
cx_int16 _Fast_If_construct(Fast_If _this);
#define Fast_If_construct(_this) _Fast_If_construct(Fast_If(_this))

/* ::corto::Fast::If::noWarnUnreachable() */
cx_void _Fast_If_noWarnUnreachable(Fast_If _this);
#define Fast_If_noWarnUnreachable(_this) _Fast_If_noWarnUnreachable(Fast_If(_this))

/* virtual ::corto::Fast::If::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node Fast_If_toIc(Fast_If _this, ic_program program, ic_storage storage, cx_bool stored);

/* ::corto::Fast::If::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _Fast_If_toIc_v(Fast_If _this, ic_program program, ic_storage storage, cx_bool stored);
#define Fast_If_toIc_v(_this, program, storage, stored) _Fast_If_toIc_v(Fast_If(_this), ic_program(program), ic_storage(storage), stored)

#ifdef __cplusplus
}
#endif
#endif

