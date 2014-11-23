/*
 * db__class.h
 *
 *  Created on: Aug 5, 2012
 *      Author: sander
 *
 *  Private definitions for the class type
 */

#ifndef DB__CLASS_H_
#define DB__CLASS_H_

#include "db__type.h"
#include "db_class.h"

#ifdef __cplusplus
extern "C" {
#endif

db_uint32 db__class_delegateCount(db_class _this);
db_object db_class_getObservable(db_class _this, db_observer observer, db_object me);
void db_class_setObservable(db_class _this, db_observer observer, db_object observable, db_object me);

#ifdef __cplusplus
}
#endif

#endif /* DB__CLASS_H_ */
