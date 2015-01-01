/* db_class.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef db_class_H
#define db_class_H

#include "cortex.h"
#include "db_struct.h"
#include "db__type.h"

#include "db__api.h"

#include "db__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* callback ::cortex::lang::class::construct(lang::object object) -> ::cortex::lang::class::_construct(lang::class object) */
db_int16 db_class__construct(db_class object);

/* callback ::cortex::lang::class::destruct(lang::object object) -> ::cortex::lang::class::_destruct(lang::class object) */
db_void db_class__destruct(db_class object);

/* virtual ::cortex::lang::class::allocSize() */
db_uint32 db_class_allocSize(db_class _this);

/* ::cortex::lang::class::allocSize() */
db_uint32 db_class_allocSize_v(db_class _this);

/* ::cortex::lang::class::bindCallback(lang::delegate delegate,lang::object object,lang::callback method) */
db_int16 db_class_bindCallback(db_class _this, db_delegate delegate, db_object object, db_callback method);

/* ::cortex::lang::class::bindDelegate(lang::delegate delegate) */
db_int16 db_class_bindDelegate(db_class _this, db_delegate delegate);

/* ::cortex::lang::class::bindMethod(lang::method method) */
db_int16 db_class_bindMethod(db_class _this, db_method method);

/* ::cortex::lang::class::bindObserver(lang::observer observer) */
db_void db_class_bindObserver(db_class _this, db_observer observer);

/* delegate ::cortex::lang::class::construct(lang::object object), obtain callback */
db_bool db_class_construct_hasCallback(db_class _this);

/* ::cortex::lang::class::construct(lang::object object) */
db_int16 db_class_construct(db_class _this, db_object object);

/* delegate ::cortex::lang::class::destruct(lang::object object), obtain callback */
db_bool db_class_destruct_hasCallback(db_class _this);

/* ::cortex::lang::class::destruct(lang::object object) */
db_void db_class_destruct(db_class _this, db_object object);

/* ::cortex::lang::class::findObserver(lang::object observable,string expr) */
db_observer db_class_findObserver(db_class _this, db_object observable, db_string expr);

/* callback ::cortex::lang::type::init(lang::object object) -> ::cortex::lang::class::init(lang::class object) */
db_int16 db_class_init(db_class object);

/* ::cortex::lang::class::instanceof(lang::object object) */
db_bool db_class_instanceof(db_class _this, db_object object);

/* ::cortex::lang::class::privateObserver(lang::object object,lang::observer observer) */
db_observer db_class_privateObserver(db_class _this, db_object object, db_observer observer);

/* ::cortex::lang::class::resolveCallback(lang::delegate delegate,lang::object target) */
db_callback db_class_resolveCallback(db_class _this, db_delegate delegate, db_object target);

/* ::cortex::lang::class::resolveDelegate(lang::string name) */
db_delegate db_class_resolveDelegate(db_class _this, db_string name);

/* ::cortex::lang::class::resolveInterfaceMethod(lang::interface interface,lang::uint32 method) */
db_method db_class_resolveInterfaceMethod(db_class _this, db_interface interface, db_uint32 method);

#ifdef __cplusplus
}
#endif
#endif

