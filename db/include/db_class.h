/*
 * db_class.h
 *
 *  Created on: Aug 5, 2012
 *      Author: sander
 */

#ifndef DB_CLASS_H_
#define DB_CLASS_H_

#include "db__type.h"
#include "db_interface.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Callbacks */
db_int16 db_class_init(db_class object);
db_int16 db_class__construct(db_class object);
void db_class__destruct(db_class object);

/* Delegates */
db_int16 db_class_construct(db_class _this, db_object object);
void db_class_destruct(db_class _this, db_object object);

/* Virtual methods */
db_uint16 db_class_allocSize(db_class _this);
db_int16 db_class_bindMethod(db_class _this, db_method method);
db_int16 db_class_bindDelegate(db_class _this, db_delegate method);

/* Methods */
db_bool db_class_instanceof(db_class _this, db_object o);
db_delegate db_class_resolveDelegate(db_class _this, db_string delegate);
db_callback db_class_resolveCallback(db_class _this, db_delegate delegate, db_object target);
db_method db_class_resolveInterfaceMethod(db_class _this, db_interface abstract, db_uint32 methodId);
db_int16 db_class_bindCallback(db_class _this, db_delegate delegate, db_object o, db_callback method);
db_observer db_class_privateObserver(db_class _this, db_object object, db_observer template);

/* Private methods */
db_vtable* db_class_getCallbackVtable(db_object o);
db_vtable* db_class_getObserverVtable(db_object o);
void db_class_bindObserver(db_class _this, db_observer observer);
db_observer db_class_findObserver(db_class _this, db_object observable, db_string expr);
void db_class_attachObservers(db_class _this, db_object object);
void db_class_listenObservers(db_class _this, db_object object);
void db_class_detachObservers(db_class _this, db_object object);

#ifdef __cplusplus
}
#endif

#endif /* DB_CLASS_H_ */
