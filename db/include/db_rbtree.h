/*
 * db_rbtree.h
 *
 *  Created on: Apr 6, 2012
 *      Author: sander
 */

#ifndef DB_RBTREE_H_
#define DB_RBTREE_H_

#include "db__type.h"
#include "db_collection.h"

#ifdef __cplusplus
extern "C" {
#endif

db_rbtree db_rbtreeNew(db_type keyType);
db_rbtree db_rbtreeNew_w_func(db_equalsAction compare);
void db_rbtreeFree(db_rbtree tree);

void* db_rbtreeGet(db_rbtree tree, void* key);
void* db_rbtreeGetPtr(db_rbtree tree, void* key);
void db_rbtreeSet(db_rbtree tree, const void* key, void* value);
void db_rbtreeRemove(db_rbtree tree, void* key);
db_bool db_rbtreeHasKey(db_rbtree tree, const void* key, void** value);
void* db_rbtreeMin(db_rbtree tree, void** key_out);
void* db_rbtreeMax(db_rbtree tree, void** key_out);
void* db_rbtreeNext(db_rbtree tree, void* key, void** key_out);
void* db_rbtreePrev(db_rbtree tree, void* key, void** key_out);
db_uint32 db_rbtreeSize(db_rbtree tree);
int db_rbtreeWalk(db_rbtree tree, db_walkAction callback, void* userData);
int db_rbtreeWalkPtr(db_rbtree tree, db_walkAction callback, void* userData);
db_typedef db_rbtreeKeyType(db_rbtree tree);

#ifdef __cplusplus
}
#endif

#endif /* DB_RBTREE_H_ */
