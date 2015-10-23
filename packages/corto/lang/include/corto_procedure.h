/* corto_procedure.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_LANG_PROCEDURE_H
#define CORTO_LANG_PROCEDURE_H

#include "corto.h"
#include "corto_struct.h"
#include "corto__interface.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto::lang::procedure::init() */
CORTO_LANG_EXPORT corto_int16 _corto_procedure_init(corto_procedure _this);
#define corto_procedure_init(_this) _corto_procedure_init(corto_procedure(_this))

/* ::corto::lang::procedure::unbind(function object) */
CORTO_LANG_EXPORT corto_void _corto_procedure_unbind(corto_procedure _this, corto_function object);
#define corto_procedure_unbind(_this, object) _corto_procedure_unbind(corto_procedure(_this), corto_function(object))

#ifdef __cplusplus
}
#endif
#endif

