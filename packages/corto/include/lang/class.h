/* class.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_LANG_CLASS_H
#define CORTO_LANG_CLASS_H

#include <corto/corto.h>
#include <corto/_interface.h>
#include <corto/lang/_type.h>
#include <corto/lang/_api.h>
#include <corto/lang/_meta.h>

#ifdef __cplusplus
extern "C" {
#endif


CORTO_EXPORT corto_int16 _corto_class_construct(
    corto_class this);
#define corto_class_construct(_this) _corto_class_construct(corto_class(_this))

CORTO_EXPORT corto_void _corto_class_destruct(
    corto_class this);
#define corto_class_destruct(_this) _corto_class_destruct(corto_class(_this))

CORTO_EXPORT corto_int16 _corto_class_init(
    corto_class this);
#define corto_class_init(_this) _corto_class_init(corto_class(_this))

CORTO_EXPORT corto_bool _corto_class_instanceof(
    corto_class this,
    corto_object object);
#define corto_class_instanceof(_this, object) _corto_class_instanceof(corto_class(_this), object)

CORTO_EXPORT corto_method _corto_class_resolveInterfaceMethod(
    corto_class this,
    corto_interface interface,
    corto_uint32 method);
#define corto_class_resolveInterfaceMethod(_this, interface, method) _corto_class_resolveInterfaceMethod(corto_class(_this), corto_interface(interface), method)

#ifdef __cplusplus
}
#endif
#endif

