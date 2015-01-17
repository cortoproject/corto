/*
 * cx__class.h
 *
 *  Created on: Aug 5, 2012
 *      Author: sander
 *
 *  Private definitions for the class type
 */

#ifndef CX__CLASS_H_
#define CX__CLASS_H_

#include "cx__type.h"
#include "cx_class.h"

#ifdef __cplusplus
extern "C" {
#endif

cx_object cx_class_getObservable(cx_class _this, cx_observer observer, cx_object me);
void cx_class_setObservable(cx_class _this, cx_observer observer, cx_object observable, cx_object me);

void cx_class_attachObservers(cx_class _this, cx_object object);
void cx_class_listenObservers(cx_class _this, cx_object object);
void cx_class_detachObservers(cx_class _this, cx_object object);

cx_vtable* cx_class_getObserverVtable(cx_object o);

#ifdef __cplusplus
}
#endif

#endif /* CX__CLASS_H_ */
