/* function.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_LANG_FUNCTION_H
#define CORTO_LANG_FUNCTION_H

#include "corto/corto__interface.h"
#include "corto/lang/lang__type.h"

#ifdef __cplusplus
extern "C" {
#endif

CORTO_EXPORT corto_int16 _corto_function_bind(corto_function _this);
#define corto_function_bind(_this) _corto_function_bind(corto_function(_this))

CORTO_EXPORT corto_int16 _corto_function_init(corto_function _this);
#define corto_function_init(_this) _corto_function_init(corto_function(_this))

CORTO_EXPORT corto_parameterseq _corto_function_stringToParameterSeq(corto_string name, corto_object scope);
#define corto_function_stringToParameterSeq(name, scope) _corto_function_stringToParameterSeq(name, scope)

CORTO_EXPORT corto_void _corto_function_unbind(corto_function object);
#define corto_function_unbind(object) _corto_function_unbind(corto_function(object))

#ifdef __cplusplus
}
#endif
#endif
