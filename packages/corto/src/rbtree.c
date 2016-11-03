/*
 * corto_rbtree.c
 *
 *  Created on: Jul 17, 2012
 *      Author: sander
 *
 *  This implementation is a wrapper around the jsw_rbtree (http://www.eternallyconfuzzled.com) implementation.
 */

#include "corto/corto.h"

corto_rbtree corto_rbtreeNew(corto_type keyType) {

    corto_assert(keyType->size <= sizeof(corto_word), "corto_rbtreeNew: keytype sizes cannot be larger than the size of a word.");

    return (corto_rbtree)jsw_rbnew(keyType, NULL);
}

corto_rbtree corto_rbtreeNew_w_func(corto_equalsAction compare) {
    return (corto_rbtree)jsw_rbnew(NULL, compare);
}

void corto_rbtreeFree(corto_rbtree tree) {
    jsw_rbdelete((jsw_rbtree_t*)tree);
}

void* corto_rbtreeGet(corto_rbtree tree, void* key) {
    return jsw_rbfind((jsw_rbtree_t*)tree, key);
}

void* corto_rbtreeGetPtr(corto_rbtree tree, void* key) {
    return jsw_rbfindPtr((jsw_rbtree_t*)tree, key);
}

void corto_rbtreeSet(corto_rbtree tree, const void* key, void* value) {
    jsw_rbinsert((jsw_rbtree_t*)tree, (void*)key, value, NULL, TRUE);
}

void* corto_rbtreeFindOrSet(corto_rbtree tree, const void* key, void* value) {
    void *old = NULL;
    jsw_rbinsert((jsw_rbtree_t*)tree, (void*)key, value, &old, FALSE);
    return old;
}

void corto_rbtreeRemove(corto_rbtree tree, void* key) {
    jsw_rberase((jsw_rbtree_t*)tree, key);
}

corto_bool corto_rbtreeHasKey(corto_rbtree tree, const void* key, void** value) {
    return jsw_rbhaskey((jsw_rbtree_t*)tree, key, value);
}

corto_bool corto_rbtreeHasKey_w_cmp(corto_rbtree tree, const void* key, void** value, corto_equalsAction cmp) {
    return jsw_rbhaskey_w_cmp((jsw_rbtree_t*)tree, key, value, cmp);
}

corto_uint32 corto_rbtreeSize(corto_rbtree tree) {
    return jsw_rbsize((jsw_rbtree_t*)tree);
}

void* corto_rbtreeMin(corto_rbtree tree, void** key_out){
    return jsw_rbgetmin((jsw_rbtree_t*)tree, key_out);
}

void* corto_rbtreeMax(corto_rbtree tree, void** key_out) {
    return jsw_rbgetmax((jsw_rbtree_t*)tree, key_out);
}

void* corto_rbtreeNext(corto_rbtree tree, void* key, void** key_out) {
    return jsw_rbgetnext((jsw_rbtree_t*)tree, key, key_out);
}

void* corto_rbtreePrev(corto_rbtree tree, void* key, void** key_out)  {
    return jsw_rbgetprev((jsw_rbtree_t*)tree, key, key_out);
}

/* Note that this function cannot handle NULL values in the tree */
int corto_rbtreeWalk(corto_rbtree tree, corto_walkAction callback, void* userData) {
    jsw_rbtrav_t tdata;
    void* data;

    /* Move to first */
    data = jsw_rbtfirst(&tdata, (jsw_rbtree_t*)tree);
    if (data) {
        if (!callback(data, userData)) {
            return 0;
        }

        /* Walk values */
        while((data = jsw_rbtnext(&tdata))) {
            if (!callback(data, userData)) {
                return 0;
            }
        }
    }

    return 1;
}

/* Note that this function cannot handle NULL values in the tree */
int corto_rbtreeWalkPtr(corto_rbtree tree, corto_walkAction callback, void* userData) {
    jsw_rbtrav_t tdata;
    void* data;

    /* Move to first */
    data = jsw_rbtfirstptr(&tdata, (jsw_rbtree_t*)tree);
    if (data) {
        if (!callback(data, userData)) {
            return 0;
        }

        /* Walk values */
        while((data = jsw_rbtnextptr(&tdata))) {
            if (!callback(data, userData)) {
                return 0;
            }
        }
    }

    return 1;
}

corto_type corto_rbtreeKeyType(corto_rbtree tree) {
    return corto_type(jsw_rbtype((jsw_rbtree_t*)tree));
}

#define corto_iterData(iter) ((jsw_rbtrav_t*)iter->udata)

static int corto_rbtreeIterHasNext(corto_iter *iter) {
    return corto_iterData(iter)->it != NULL;
}

static void* corto_rbtreeIterNext(corto_iter *iter) {
    void* data = corto_iterData(iter)->it ?
        jsw_rbnodedata(corto_iterData(iter)->it) : NULL;
    jsw_rbtnext(corto_iterData(iter));
    return data;
}

corto_bool corto_rbtreeIterChanged(corto_iter *iter) {
    if (corto_iterData(iter)) {
        return jsw_rbtchanged(corto_iterData(iter));
    } else {
        return FALSE;
    }
}

corto_iter _corto_rbtreeIter(corto_rbtree tree, void *udata) {
    corto_iter result;

    result.udata = udata;
    jsw_rbtfirst(result.udata, (jsw_rbtree_t*)tree);
    result.hasNext = corto_rbtreeIterHasNext;
    result.next = corto_rbtreeIterNext;
    result.release = NULL;

    return result;
}
