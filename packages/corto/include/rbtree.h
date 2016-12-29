/*
 * corto_rbtree.h
 *
 *  Created on: Apr 6, 2012
 *      Author: sander
 */

#ifndef CORTO_RBTREE_H_
#define CORTO_RBTREE_H_

#include "corto/object.h"
#include "corto/lang/collection.h"
#include "jsw_rbtree.h"

#ifdef __cplusplus
extern "C" {
#endif

CORTO_EXPORT corto_rbtree corto_rbtreeNew(corto_type keyType);
CORTO_EXPORT corto_rbtree corto_rbtreeNew_w_func(corto_equalsAction compare);
CORTO_EXPORT void corto_rbtreeFree(corto_rbtree tree);

CORTO_EXPORT void* corto_rbtreeGet(corto_rbtree tree, void* key);
CORTO_EXPORT void* corto_rbtreeGetPtr(corto_rbtree tree, void* key);
CORTO_EXPORT void corto_rbtreeSet(corto_rbtree tree, const void* key, void* value);
CORTO_EXPORT void* corto_rbtreeFindOrSet(corto_rbtree tree, const void* key, void* value);
CORTO_EXPORT void corto_rbtreeRemove(corto_rbtree tree, void* key);
CORTO_EXPORT corto_bool corto_rbtreeHasKey(corto_rbtree tree, const void* key, void** value);
CORTO_EXPORT corto_bool corto_rbtreeHasKey_w_cmp(corto_rbtree tree, const void* key, void** value, corto_equalsAction cmp);
CORTO_EXPORT void* corto_rbtreeMin(corto_rbtree tree, void** key_out);
CORTO_EXPORT void* corto_rbtreeMax(corto_rbtree tree, void** key_out);
CORTO_EXPORT void* corto_rbtreeNext(corto_rbtree tree, void* key, void** key_out);
CORTO_EXPORT void* corto_rbtreePrev(corto_rbtree tree, void* key, void** key_out);
CORTO_EXPORT corto_uint32 corto_rbtreeSize(corto_rbtree tree);
CORTO_EXPORT int corto_rbtreeWalk(corto_rbtree tree, corto_walkAction callback, void* userData);
CORTO_EXPORT int corto_rbtreeWalkPtr(corto_rbtree tree, corto_walkAction callback, void* userData);

#define corto_rbtreeIter(tree) _corto_rbtreeIter(tree, alloca(sizeof(struct jsw_rbtrav)));
CORTO_EXPORT corto_iter _corto_rbtreeIter(corto_rbtree tree, void *udata);
CORTO_EXPORT corto_type corto_rbtreeKeyType(corto_rbtree tree);
CORTO_EXPORT corto_bool corto_rbtreeIterChanged(corto_iter *iter);

#ifdef __cplusplus
}
#endif

#endif /* CORTO_RBTREE_H_ */
