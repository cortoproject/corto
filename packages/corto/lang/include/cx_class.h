/* cx_class.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef corto_lang_class_H
#define corto_lang_class_H

#include "corto.h"
#include "cx_struct.h"
#ifdef corto_lang_LIB
#include "cx__type.h"
#include "cx__api.h"
#include "cx__meta.h"
#else
#include "corto/lang/cx__type.h"
#include "corto/lang/cx__api.h"
#include "corto/lang/cx__meta.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* virtual ::corto::lang::class::allocSize() */
cx_uint32 cx_class_allocSize(cx_class _this);

/* ::corto::lang::class::allocSize() */
cx_uint32 _cx_class_allocSize_v(cx_class _this);
#define cx_class_allocSize_v(_this) _cx_class_allocSize_v(cx_class(_this))

/* ::corto::lang::class::bindObserver(observer observer) */
cx_void _cx_class_bindObserver(cx_class _this, cx_observer observer);
#define cx_class_bindObserver(_this, observer) _cx_class_bindObserver(cx_class(_this), cx_observer(observer))

/* ::corto::lang::class::construct() */
cx_int16 _cx_class_construct(cx_class _this);
#define cx_class_construct(_this) _cx_class_construct(cx_class(_this))

/* ::corto::lang::class::destruct() */
cx_void _cx_class_destruct(cx_class _this);
#define cx_class_destruct(_this) _cx_class_destruct(cx_class(_this))

/* ::corto::lang::class::findObserver(object observable) */
cx_observer _cx_class_findObserver(cx_class _this, cx_object observable);
#define cx_class_findObserver(_this, observable) _cx_class_findObserver(cx_class(_this), observable)

/* ::corto::lang::class::init() */
cx_int16 _cx_class_init(cx_class _this);
#define cx_class_init(_this) _cx_class_init(cx_class(_this))

/* ::corto::lang::class::instanceof(object object) */
cx_bool _cx_class_instanceof(cx_class _this, cx_object object);
#define cx_class_instanceof(_this, object) _cx_class_instanceof(cx_class(_this), object)

/* ::corto::lang::class::privateObserver(object object,observer observer) */
cx_observer _cx_class_privateObserver(cx_class _this, cx_object object, cx_observer observer);
#define cx_class_privateObserver(_this, object, observer) _cx_class_privateObserver(cx_class(_this), object, cx_observer(observer))

/* ::corto::lang::class::resolveInterfaceMethod(interface interface,uint32 method) */
cx_method _cx_class_resolveInterfaceMethod(cx_class _this, cx_interface interface, cx_uint32 method);
#define cx_class_resolveInterfaceMethod(_this, interface, method) _cx_class_resolveInterfaceMethod(cx_class(_this), cx_interface(interface), method)

#ifdef __cplusplus
}
#endif
#endif

