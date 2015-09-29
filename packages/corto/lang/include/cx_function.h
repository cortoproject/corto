/* cx_function.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_LANG_FUNCTION_H
#define CORTO_LANG_FUNCTION_H

#include "corto.h"
#include "cx__interface.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto::lang::function::bind() */
CORTO_LANG_EXPORT cx_int16 _cx_function_bind(cx_function _this);
#define cx_function_bind(_this) _cx_function_bind(cx_function(_this))

/* ::corto::lang::function::init() */
CORTO_LANG_EXPORT cx_int16 _cx_function_init(cx_function _this);
#define cx_function_init(_this) _cx_function_init(cx_function(_this))

/* ::corto::lang::function::stringToParameterSeq(string name,object scope) */
CORTO_LANG_EXPORT cx_parameterseq _cx_function_stringToParameterSeq(cx_string name, cx_object scope);
#define cx_function_stringToParameterSeq(name, scope) _cx_function_stringToParameterSeq(name, scope)

/* ::corto::lang::function::unbind(function object) */
CORTO_LANG_EXPORT cx_void _cx_function_unbind(cx_function object);
#define cx_function_unbind(object) _cx_function_unbind(cx_function(object))

#ifdef __cplusplus
}
#endif
#endif

