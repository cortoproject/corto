/*
 * corto__class.h
 *
 *  Created on: July 25, 2015
 *      Author: sander
 *
 *  Private definitions for the collection types
 */

#ifndef CORTO__COLLECTION_H_
#define CORTO__COLLECTION_H_

#include "corto/corto.h"

#ifdef __cplusplus
extern "C" {
#endif

int corto_walk(corto_collection _this, corto_void* collection, corto_walkAction action, corto_void* userData);
void corto_clear(corto_collection _this, corto_void* collection);

#ifdef __cplusplus
}
#endif

#endif /* CORTO__COLLECTION_H_ */
