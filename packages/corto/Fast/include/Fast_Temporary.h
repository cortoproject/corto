/* Fast_Temporary.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_Temporary_H
#define Fast_Temporary_H

#include "corto.h"
#include "Fast_Storage.h"
#include "Fast__type.h"
#include "Fast__api.h"
#include "Fast__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto::Fast::Temporary::construct() */
cx_int16 _Fast_Temporary_construct(Fast_Temporary _this);
#define Fast_Temporary_construct(_this) _Fast_Temporary_construct(Fast_Temporary(_this))

/* ::corto::Fast::Temporary::setProxy(Temporary proxy) */
cx_void _Fast_Temporary_setProxy(Fast_Temporary _this, Fast_Temporary proxy);
#define Fast_Temporary_setProxy(_this, proxy) _Fast_Temporary_setProxy(Fast_Temporary(_this), Fast_Temporary(proxy))

/* virtual ::corto::Fast::Temporary::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node Fast_Temporary_toIc(Fast_Temporary _this, ic_program program, ic_storage storage, cx_bool stored);

/* ::corto::Fast::Temporary::toIc(ic::program program,ic::storage storage,bool stored) */
ic_node _Fast_Temporary_toIc_v(Fast_Temporary _this, ic_program program, ic_storage storage, cx_bool stored);
#define Fast_Temporary_toIc_v(_this, program, storage, stored) _Fast_Temporary_toIc_v(Fast_Temporary(_this), ic_program(program), ic_storage(storage), stored)

#ifdef __cplusplus
}
#endif
#endif

