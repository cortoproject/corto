/* cx_procedure.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef corto_lang_procedure_H
#define corto_lang_procedure_H

#include "corto.h"
#include "cx_struct.h"
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

/* ::corto::lang::procedure::init() */
cx_int16 _cx_procedure_init(cx_procedure _this);
#define cx_procedure_init(_this) _cx_procedure_init(cx_procedure(_this))

/* ::corto::lang::procedure::unbind(function object) */
cx_void _cx_procedure_unbind(cx_procedure _this, cx_function object);
#define cx_procedure_unbind(_this, object) _cx_procedure_unbind(cx_procedure(_this), cx_function(object))

#ifdef __cplusplus
}
#endif
#endif

