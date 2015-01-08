/* cx_class.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef cx_class_H
#define cx_class_H

#include "cortex.h"
#include "cx_struct.h"
#include "cx__type.h"

#include "cx__api.h"

#include "cx__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* callback ::cortex::lang::class::construct(object object) -> ::cortex::lang::class::_construct(class object) */
cx_int16 cx_class__construct(cx_class object);

/* callback ::cortex::lang::class::destruct(object object) -> ::cortex::lang::class::_destruct(class object) */
cx_void cx_class__destruct(cx_class object);

/* virtual ::cortex::lang::class::allocSize() */
cx_uint32 cx_class_allocSize(cx_class _this);

/* ::cortex::lang::class::allocSize() */
cx_uint32 cx_class_allocSize_v(cx_class _this);

/* ::cortex::lang::class::bindCallback(delegate delegate,object object,callback method) */
cx_int16 cx_class_bindCallback(cx_class _this, cx_delegate delegate, cx_object object, cx_callback method);

/* ::cortex::lang::class::bindDelegate(delegate delegate) */
cx_int16 cx_class_bindDelegate(cx_class _this, cx_delegate delegate);

/* ::cortex::lang::class::bindMethod(method method) */
cx_int16 cx_class_bindMethod(cx_class _this, cx_method method);

/* ::cortex::lang::class::bindObserver(observer observer) */
cx_void cx_class_bindObserver(cx_class _this, cx_observer observer);

/* delegate ::cortex::lang::class::construct(object object), obtain callback */
cx_bool cx_class_construct_hasCallback(cx_class _this);

/* ::cortex::lang::class::construct(object object) */
cx_int16 cx_class_construct(cx_class _this, cx_object object);

/* delegate ::cortex::lang::class::destruct(object object), obtain callback */
cx_bool cx_class_destruct_hasCallback(cx_class _this);

/* ::cortex::lang::class::destruct(object object) */
cx_void cx_class_destruct(cx_class _this, cx_object object);

/* ::cortex::lang::class::findObserver(object observable,string expr) */
cx_observer cx_class_findObserver(cx_class _this, cx_object observable, cx_string expr);

/* callback ::cortex::lang::type::init(object object) -> ::cortex::lang::class::init(class object) */
cx_int16 cx_class_init(cx_class object);

/* ::cortex::lang::class::instanceof(object object) */
cx_bool cx_class_instanceof(cx_class _this, cx_object object);

/* ::cortex::lang::class::privateObserver(object object,observer observer) */
cx_observer cx_class_privateObserver(cx_class _this, cx_object object, cx_observer observer);

/* ::cortex::lang::class::resolveCallback(delegate delegate,object target) */
cx_callback cx_class_resolveCallback(cx_class _this, cx_delegate delegate, cx_object target);

/* ::cortex::lang::class::resolveDelegate(string name) */
cx_delegate cx_class_resolveDelegate(cx_class _this, cx_string name);

/* ::cortex::lang::class::resolveInterfaceMethod(interface interface,uint32 method) */
cx_method cx_class_resolveInterfaceMethod(cx_class _this, cx_interface interface, cx_uint32 method);

#ifdef __cplusplus
}
#endif
#endif

