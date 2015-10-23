/*
 * corto_rbtree.h
 *
 *  Created on: Apr 6, 2012
 *      Author: sander
 */

#ifndef CORTO_RBTREE_H_
#define CORTO_RBTREE_H_

#include "corto_object.h"
#include "corto_collection.h"
#include "jsw_rbtree.h"

#ifdef __cplusplus
extern "C" {
#endif

corto_rbtree corto_rbtreeNew(corto_type keyType);
corto_rbtree corto_rbtreeNew_w_func(corto_equalsAction compare);
void corto_rbtreeFree(corto_rbtree tree);

void* corto_rbtreeGet(corto_rbtree tree, void* key);
void* corto_rbtreeGetPtr(corto_rbtree tree, void* key);
void corto_rbtreeSet(corto_rbtree tree, const void* key, void* value);
void* corto_rbtreeFindOrSet(corto_rbtree tree, const void* key, void* value);
void corto_rbtreeRemove(corto_rbtree tree, void* key);
corto_bool corto_rbtreeHasKey(corto_rbtree tree, const void* key, void** value);
corto_bool corto_rbtreeHasKey_w_cmp(corto_rbtree tree, const void* key, void** value, corto_equalsAction cmp);
void* corto_rbtreeMin(corto_rbtree tree, void** key_out);
void* corto_rbtreeMax(corto_rbtree tree, void** key_out);
void* corto_rbtreeNext(corto_rbtree tree, void* key, void** key_out);
void* corto_rbtreePrev(corto_rbtree tree, void* key, void** key_out);
corto_uint32 corto_rbtreeSize(corto_rbtree tree);
int corto_rbtreeWalk(corto_rbtree tree, corto_walkAction callback, void* userData);
int corto_rbtreeWalkPtr(corto_rbtree tree, corto_walkAction callback, void* userData);
#define corto_rbtreeIter(tree) _corto_rbtreeIter(tree, alloca(sizeof(struct jsw_rbtrav)));
corto_iter _corto_rbtreeIter(corto_rbtree tree, void *udata);
corto_type corto_rbtreeKeyType(corto_rbtree tree);

#ifdef __cplusplus
}
#endif

#endif /* CORTO_RBTREE_H_ */
