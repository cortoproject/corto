/* function.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_LANG_FUNCTION_H
#define CORTO_LANG_FUNCTION_H

#include <corto/corto.h>
#include <corto/_project.h>
#include <corto/lang/_type.h>

#ifdef __cplusplus
extern "C" {
#endif


CORTO_EXPORT corto_int16 _corto_function_construct(
    corto_function _this);
#define corto_function_construct(_this) _corto_function_construct(corto_function(_this))

CORTO_EXPORT corto_void _corto_function_destruct(
    corto_function _this);
#define corto_function_destruct(_this) _corto_function_destruct(corto_function(_this))

CORTO_EXPORT corto_int16 _corto_function_init(
    corto_function _this);
#define corto_function_init(_this) _corto_function_init(corto_function(_this))

CORTO_EXPORT corto_int16 _corto_function_parseParamString(
    corto_function _this,
    corto_string params);
#define corto_function_parseParamString(_this, params) _corto_function_parseParamString(corto_function(_this), params)

CORTO_EXPORT corto_parameterseq _corto_function_stringToParameterSeq(
    corto_string name,
    corto_object scope);
#define corto_function_stringToParameterSeq(name, scope) _corto_function_stringToParameterSeq(name, scope)

#ifdef __cplusplus
}
#endif
#endif

