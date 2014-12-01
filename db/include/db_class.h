/* db_class.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef db_class_H
#define db_class_H

#include "hyve.h"
#include "db_struct.h"
#include "db__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* callback ::hyve::lang::class::construct(lang::object object) -> ::hyve::lang::class::_construct(lang::class object) */
db_int16 db_class__construct(db_class object);

/* callback ::hyve::lang::class::destruct(lang::object object) -> ::hyve::lang::class::_destruct(lang::class object) */
db_void db_class__destruct(db_class object);

/* virtual ::hyve::lang::class::allocSize() */
db_uint32 db_class_allocSize(db_class _this);

/* ::hyve::lang::class::allocSize() */
db_uint32 db_class_allocSize_v(db_class _this);

/* ::hyve::lang::class::bindCallback(lang::delegate delegate,lang::object object,lang::callback method) */
db_int16 db_class_bindCallback(db_class _this, db_delegate delegate, db_object object, db_callback method);

/* ::hyve::lang::class::bindDelegate(lang::delegate delegate) */
db_int16 db_class_bindDelegate(db_class _this, db_delegate delegate);

/* ::hyve::lang::class::bindMethod(lang::method method) */
db_int16 db_class_bindMethod(db_class _this, db_method method);

/* delegate ::hyve::lang::class::construct(lang::object object), obtain callback */
db_callback db_class_construct_callback(db_class _this);

/* delegate ::hyve::lang::class::construct(lang::object object), supply callback */
db_int16 db_class_construct_w_callback(db_callback __callback, db_class _this, db_object object);

/* ::hyve::lang::class::construct(lang::object object) */
db_int16 db_class_construct(db_class _this, db_object object);

/* delegate ::hyve::lang::class::destruct(lang::object object), obtain callback */
db_callback db_class_destruct_callback(db_class _this);

/* delegate ::hyve::lang::class::destruct(lang::object object), supply callback */
void db_class_destruct_w_callback(db_callback __callback, db_class _this, db_object object);

/* ::hyve::lang::class::destruct(lang::object object) */
db_void db_class_destruct(db_class _this, db_object object);

/* callback ::hyve::lang::type::init(lang::object object) -> ::hyve::lang::class::init(lang::class object) */
db_int16 db_class_init(db_class object);

/* ::hyve::lang::class::instanceof(lang::object object) */
db_bool db_class_instanceof(db_class _this, db_object object);

/* ::hyve::lang::class::privateObserver(lang::object object,lang::observer observer) */
db_observer db_class_privateObserver(db_class _this, db_object object, db_observer observer);

/* ::hyve::lang::class::resolveCallback(lang::delegate delegate,lang::object target) */
db_callback db_class_resolveCallback(db_class _this, db_delegate delegate, db_object target);

/* ::hyve::lang::class::resolveDelegate(lang::string name) */
db_delegate db_class_resolveDelegate(db_class _this, db_string name);

/* ::hyve::lang::class::resolveInterfaceMethod(lang::interface interface,lang::uint32 method) */
db_method db_class_resolveInterfaceMethod(db_class _this, db_interface interface, db_uint32 method);

#ifdef __cplusplus
}
#endif
#endif

