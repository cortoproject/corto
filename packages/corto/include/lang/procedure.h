/* procedure.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_LANG_PROCEDURE_H
#define CORTO_LANG_PROCEDURE_H

#include "corto/corto.h"
#include "corto/lang/_type.h"
#include "corto/lang/_api.h"
#include "corto/lang/_meta.h"
#include "corto/_interface.h"

#ifdef __cplusplus
extern "C" {
#endif


CORTO_EXPORT corto_int16 _corto_procedure_init(corto_procedure _this);
#define corto_procedure_init(_this) _corto_procedure_init(corto_procedure(_this))

CORTO_EXPORT corto_void _corto_procedure_unbind(corto_procedure _this, corto_function object);
#define corto_procedure_unbind(_this, object) _corto_procedure_unbind(corto_procedure(_this), corto_function(object))

#ifdef __cplusplus
}
#endif
#endif

