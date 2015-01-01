/*
 * cx__class.h
 *
 *  Created on: July 25, 2015
 *      Author: sander
 *
 *  Private definitions for the collection types
 */

#ifndef DB__COLLECTION_H_
#define DB__COLLECTION_H_

#include "cx__type.h"

#ifdef __cplusplus
extern "C" {
#endif
    
int cx_walk(cx_collection _this, cx_void* collection, cx_walkAction action, cx_void* userData);
void cx_clear(cx_collection _this, cx_void* collection);

#ifdef __cplusplus
}
#endif

#endif /* DB__COLLECTION_H_ */
