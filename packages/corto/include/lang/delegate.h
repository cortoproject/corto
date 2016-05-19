/* delegate.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_LANG_DELEGATE_H
#define CORTO_LANG_DELEGATE_H

#include <corto/corto.h>
#include <corto/_interface.h>
#include <corto/lang/_type.h>
#include <corto/lang/_api.h>
#include <corto/lang/_meta.h>

#ifdef __cplusplus
extern "C" {
#endif


CORTO_EXPORT corto_int16 _corto_delegate_bind(
    corto_function object);
#define corto_delegate_bind(object) _corto_delegate_bind(corto_function(object))
CORTO_EXPORT corto_bool _corto_delegate_castable(
    corto_delegate this,
    corto_type type);
#define corto_delegate_castable(_this, type) _corto_delegate_castable(corto_delegate(_this), corto_type(type))

CORTO_EXPORT corto_bool _corto_delegate_castable_v(
    corto_delegate this,
    corto_type type);
#define corto_delegate_castable_v(_this, type) _corto_delegate_castable_v(corto_delegate(_this), corto_type(type))
CORTO_EXPORT corto_bool _corto_delegate_compatible(
    corto_delegate this,
    corto_type type);
#define corto_delegate_compatible(_this, type) _corto_delegate_compatible(corto_delegate(_this), corto_type(type))

CORTO_EXPORT corto_bool _corto_delegate_compatible_v(
    corto_delegate this,
    corto_type type);
#define corto_delegate_compatible_v(_this, type) _corto_delegate_compatible_v(corto_delegate(_this), corto_type(type))

CORTO_EXPORT corto_int16 _corto_delegate_init(
    corto_delegate this);
#define corto_delegate_init(_this) _corto_delegate_init(corto_delegate(_this))

CORTO_EXPORT corto_bool _corto_delegate_instanceof(
    corto_delegate this,
    corto_object object);
#define corto_delegate_instanceof(_this, object) _corto_delegate_instanceof(corto_delegate(_this), object)

#ifdef __cplusplus
}
#endif
#endif

