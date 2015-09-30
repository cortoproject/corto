/* cx_class.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef CORTO_LANG_CLASS_H
#define CORTO_LANG_CLASS_H

#include "corto.h"
#include "cx_struct.h"
#include "cx__interface.h"

#ifdef __cplusplus
extern "C" {
#endif

/* virtual ::corto::lang::class::allocSize() */
CORTO_LANG_EXPORT cx_uint32 _cx_class_allocSize(cx_class _this);
#define cx_class_allocSize(_this) _cx_class_allocSize(cx_class(_this))

/* ::corto::lang::class::allocSize() */
CORTO_LANG_EXPORT cx_uint32 _cx_class_allocSize_v(cx_class _this);
#define cx_class_allocSize_v(_this) _cx_class_allocSize_v(cx_class(_this))

/* ::corto::lang::class::bindObserver(observer observer) */
CORTO_LANG_EXPORT cx_void _cx_class_bindObserver(cx_class _this, cx_observer observer);
#define cx_class_bindObserver(_this, observer) _cx_class_bindObserver(cx_class(_this), cx_observer(observer))

/* ::corto::lang::class::construct() */
CORTO_LANG_EXPORT cx_int16 _cx_class_construct(cx_class _this);
#define cx_class_construct(_this) _cx_class_construct(cx_class(_this))

/* ::corto::lang::class::destruct() */
CORTO_LANG_EXPORT cx_void _cx_class_destruct(cx_class _this);
#define cx_class_destruct(_this) _cx_class_destruct(cx_class(_this))

/* ::corto::lang::class::eventMaskOf(observer observer) */
CORTO_LANG_EXPORT cx_eventMask _cx_class_eventMaskOf(cx_any _this, cx_observer observer);
#define cx_class_eventMaskOf(_this, observer) _cx_class_eventMaskOf(_this, cx_observer(observer))

/* ::corto::lang::class::findObserver(object observable) */
CORTO_LANG_EXPORT cx_observer _cx_class_findObserver(cx_class _this, cx_object observable);
#define cx_class_findObserver(_this, observable) _cx_class_findObserver(cx_class(_this), observable)

/* ::corto::lang::class::init() */
CORTO_LANG_EXPORT cx_int16 _cx_class_init(cx_class _this);
#define cx_class_init(_this) _cx_class_init(cx_class(_this))

/* ::corto::lang::class::instanceof(object object) */
CORTO_LANG_EXPORT cx_bool _cx_class_instanceof(cx_class _this, cx_object object);
#define cx_class_instanceof(_this, object) _cx_class_instanceof(cx_class(_this), object)

/* ::corto::lang::class::listen(observer observer,eventMask mask,object observable,dispatcher dispatcher) */
CORTO_LANG_EXPORT cx_void _cx_class_listen(cx_any _this, cx_observer observer, cx_eventMask mask, cx_object observable, cx_dispatcher dispatcher);
#define cx_class_listen(_this, observer, mask, observable, dispatcher) _cx_class_listen(_this, cx_observer(observer), mask, observable, cx_dispatcher(dispatcher))

/* ::corto::lang::class::observableOf(observer observer) */
CORTO_LANG_EXPORT cx_object _cx_class_observableOf(cx_any _this, cx_observer observer);
#define cx_class_observableOf(_this, observer) _cx_class_observableOf(_this, cx_observer(observer))

/* ::corto::lang::class::privateObserver(object object,observer observer) */
CORTO_LANG_EXPORT cx_observer _cx_class_privateObserver(cx_class _this, cx_object object, cx_observer observer);
#define cx_class_privateObserver(_this, object, observer) _cx_class_privateObserver(cx_class(_this), object, cx_observer(observer))

/* ::corto::lang::class::resolveInterfaceMethod(interface interface,uint32 method) */
CORTO_LANG_EXPORT cx_method _cx_class_resolveInterfaceMethod(cx_class _this, cx_interface interface, cx_uint32 method);
#define cx_class_resolveInterfaceMethod(_this, interface, method) _cx_class_resolveInterfaceMethod(cx_class(_this), cx_interface(interface), method)

/* ::corto::lang::class::setDispatcher(observer observer,dispatcher dispatcher */
CORTO_LANG_EXPORT cx_void _cx_class_setDispatcher(cx_any _this, cx_observer observer, cx_dispatcher dispatcher);
#define cx_class_setDispatcher(_this, observer, dispatcher) _cx_class_setDispatcher(_this, cx_observer(observer), cx_dispatcher(dispatcher))

/* ::corto::lang::class::setMask(observer observer,eventMask mask) */
CORTO_LANG_EXPORT cx_void _cx_class_setMask(cx_any _this, cx_observer observer, cx_eventMask mask);
#define cx_class_setMask(_this, observer, mask) _cx_class_setMask(_this, cx_observer(observer), mask)

/* ::corto::lang::class::setObservable(observer observer,object observable) */
CORTO_LANG_EXPORT cx_void _cx_class_setObservable(cx_any _this, cx_observer observer, cx_object observable);
#define cx_class_setObservable(_this, observer, observable) _cx_class_setObservable(_this, cx_observer(observer), observable)

#ifdef __cplusplus
}
#endif
#endif

