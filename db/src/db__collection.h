/*
 * db__class.h
 *
 *  Created on: July 25, 2015
 *      Author: sander
 *
 *  Private definitions for the collection types
 */

#ifndef DB__COLLECTION_H_
#define DB__COLLECTION_H_

#include "db__type.h"

#ifdef __cplusplus
extern "C" {
#endif
    
int db_walk(db_collection _this, db_void* collection, db_walkAction action, db_void* userData);
void db_clear(db_collection _this, db_void* collection);

#ifdef __cplusplus
}
#endif

#endif /* DB__COLLECTION_H_ */
