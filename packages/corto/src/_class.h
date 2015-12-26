/*
 * corto__class.h
 *
 *  Created on: Aug 5, 2012
 *      Author: sander
 *
 *  Private definitions for the class type
 */

#ifndef CORTO__CLASS_H_
#define CORTO__CLASS_H_

#include "corto/corto.h"

#ifdef __cplusplus
extern "C" {
#endif

void corto_class_attachObservers(corto_class _this, corto_object object);
void corto_class_listenObservers(corto_class _this, corto_object object);
void corto_class_detachObservers(corto_class _this, corto_object object);

corto_vtable* corto_class_getObserverVtable(corto_object o);

#ifdef __cplusplus
}
#endif

#endif /* CORTO__CLASS_H_ */
