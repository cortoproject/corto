/* cx_array.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef corto_lang_array_H
#define corto_lang_array_H

#include "corto.h"
#include "cx_collection.h"
#ifdef corto_lang_LIB
#include "cx__type.h"
#include "cx__api.h"
#include "cx__meta.h"
#else
#include "corto/lang/cx__type.h"
#include "corto/lang/cx__api.h"
#include "corto/lang/cx__meta.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto::lang::array::construct() */
cx_int16 _cx_array_construct(cx_array _this);
#define cx_array_construct(_this) _cx_array_construct(cx_array(_this))

/* ::corto::lang::array::destruct() */
cx_void _cx_array_destruct(cx_array _this);
#define cx_array_destruct(_this) _cx_array_destruct(cx_array(_this))

/* ::corto::lang::array::init() */
cx_int16 _cx_array_init(cx_array _this);
#define cx_array_init(_this) _cx_array_init(cx_array(_this))

#ifdef __cplusplus
}
#endif
#endif

