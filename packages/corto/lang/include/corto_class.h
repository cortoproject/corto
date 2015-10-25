/* corto_class.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_LANG_CLASS_H
#define CORTO_LANG_CLASS_H

#include "corto.h"
#include "corto_struct.h"
#include "corto__interface.h"

#ifdef __cplusplus
extern "C" {
#endif

/* virtual ::corto::lang::class::allocSize() */
CORTO_LANG_EXPORT corto_uint32 _corto_class_allocSize(corto_class _this);
#define corto_class_allocSize(_this) _corto_class_allocSize(corto_class(_this))

CORTO_LANG_EXPORT corto_uint32 _corto_class_allocSize_v(corto_class _this);
#define corto_class_allocSize_v(_this) _corto_class_allocSize_v(corto_class(_this))

CORTO_LANG_EXPORT corto_void _corto_class_bindObserver(corto_class _this, corto_observer observer);
#define corto_class_bindObserver(_this, observer) _corto_class_bindObserver(corto_class(_this), corto_observer(observer))

CORTO_LANG_EXPORT corto_int16 _corto_class_construct(corto_class _this);
#define corto_class_construct(_this) _corto_class_construct(corto_class(_this))

CORTO_LANG_EXPORT corto_void _corto_class_destruct(corto_class _this);
#define corto_class_destruct(_this) _corto_class_destruct(corto_class(_this))

CORTO_LANG_EXPORT corto_eventMask _corto_class_eventMaskOf(corto_any _this, corto_observer observer);
#define corto_class_eventMaskOf(_this, observer) _corto_class_eventMaskOf(_this, corto_observer(observer))

CORTO_LANG_EXPORT corto_observer _corto_class_findObserver(corto_class _this, corto_object observable);
#define corto_class_findObserver(_this, observable) _corto_class_findObserver(corto_class(_this), observable)

CORTO_LANG_EXPORT corto_int16 _corto_class_init(corto_class _this);
#define corto_class_init(_this) _corto_class_init(corto_class(_this))

CORTO_LANG_EXPORT corto_bool _corto_class_instanceof(corto_class _this, corto_object object);
#define corto_class_instanceof(_this, object) _corto_class_instanceof(corto_class(_this), object)

CORTO_LANG_EXPORT corto_void _corto_class_listen(corto_any _this, corto_observer observer, corto_eventMask mask, corto_object observable, corto_dispatcher dispatcher);
#define corto_class_listen(_this, observer, mask, observable, dispatcher) _corto_class_listen(_this, corto_observer(observer), mask, observable, corto_dispatcher(dispatcher))

CORTO_LANG_EXPORT corto_object _corto_class_observableOf(corto_any _this, corto_observer observer);
#define corto_class_observableOf(_this, observer) _corto_class_observableOf(_this, corto_observer(observer))

CORTO_LANG_EXPORT corto_observer _corto_class_privateObserver(corto_class _this, corto_object object, corto_observer observer);
#define corto_class_privateObserver(_this, object, observer) _corto_class_privateObserver(corto_class(_this), object, corto_observer(observer))

CORTO_LANG_EXPORT corto_method _corto_class_resolveInterfaceMethod(corto_class _this, corto_interface interface, corto_uint32 method);
#define corto_class_resolveInterfaceMethod(_this, interface, method) _corto_class_resolveInterfaceMethod(corto_class(_this), corto_interface(interface), method)

CORTO_LANG_EXPORT corto_void _corto_class_setDispatcher(corto_any _this, corto_observer observer, corto_dispatcher dispatcher);
#define corto_class_setDispatcher(_this, observer, dispatcher) _corto_class_setDispatcher(_this, corto_observer(observer), corto_dispatcher(dispatcher))

CORTO_LANG_EXPORT corto_void _corto_class_setMask(corto_any _this, corto_observer observer, corto_eventMask mask);
#define corto_class_setMask(_this, observer, mask) _corto_class_setMask(_this, corto_observer(observer), mask)

CORTO_LANG_EXPORT corto_void _corto_class_setObservable(corto_any _this, corto_observer observer, corto_object observable);
#define corto_class_setObservable(_this, observer, observable) _corto_class_setObservable(_this, corto_observer(observer), observable)

#ifdef __cplusplus
}
#endif
#endif

