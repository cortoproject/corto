/* corto_function.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_LANG_FUNCTION_H
#define CORTO_LANG_FUNCTION_H

#include "corto.h"
#include "corto__interface.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto::lang::function::bind() */
CORTO_LANG_EXPORT corto_int16 _corto_function_bind(corto_function _this);
#define corto_function_bind(_this) _corto_function_bind(corto_function(_this))

/* ::corto::lang::function::init() */
CORTO_LANG_EXPORT corto_int16 _corto_function_init(corto_function _this);
#define corto_function_init(_this) _corto_function_init(corto_function(_this))

/* ::corto::lang::function::stringToParameterSeq(string name,object scope) */
CORTO_LANG_EXPORT corto_parameterseq _corto_function_stringToParameterSeq(corto_string name, corto_object scope);
#define corto_function_stringToParameterSeq(name, scope) _corto_function_stringToParameterSeq(name, scope)

/* ::corto::lang::function::unbind(function object) */
CORTO_LANG_EXPORT corto_void _corto_function_unbind(corto_function object);
#define corto_function_unbind(object) _corto_function_unbind(corto_function(object))

#ifdef __cplusplus
}
#endif
#endif

