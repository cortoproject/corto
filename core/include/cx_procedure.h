/* cx_procedure.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef cx_procedure_H
#define cx_procedure_H

#include "corto.h"
#include "cx_struct.h"
#include "cx__type.h"
#include "cx__api.h"
#include "cx__meta.h"

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

