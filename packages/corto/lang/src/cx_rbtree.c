/*
 * cx_rbtree.c
 *
 *  Created on: Jul 17, 2012
 *      Author: sander
 *
 *  This implementation is a wrapper around the jsw_rbtree (http://www.eternallyconfuzzled.com) implementation.
 */

#define corto_lang_LIB
#include "cx_mem.h"
#include "cx_util.h"
#include "cx_rbtree.h"
#include "cx_type.h"
#include "cx_err.h"
#include "jsw_rbtree.h"

cx_rbtree cx_rbtreeNew(cx_type keyType) {

    cx_assert(keyType->size <= sizeof(cx_word), "cx_rbtreeNew: keytype sizes cannot be larger than the size of a word.");

    return (cx_rbtree)jsw_rbnew(keyType, NULL);
}

cx_rbtree cx_rbtreeNew_w_func(cx_equalsAction compare) {
    return (cx_rbtree)jsw_rbnew(NULL, compare);
}

void cx_rbtreeFree(cx_rbtree tree) {
    jsw_rbdelete((jsw_rbtree_t*)tree);
}

void* cx_rbtreeGet(cx_rbtree tree, void* key) {
    return jsw_rbfind((jsw_rbtree_t*)tree, key);
}

void* cx_rbtreeGetPtr(cx_rbtree tree, void* key) {
    return jsw_rbfindPtr((jsw_rbtree_t*)tree, key);
}

void cx_rbtreeSet(cx_rbtree tree, const void* key, void* value) {
    jsw_rbinsert((jsw_rbtree_t*)tree, (void*)key, value);
}

void cx_rbtreeRemove(cx_rbtree tree, void* key) {
    jsw_rberase((jsw_rbtree_t*)tree, key);
}

cx_bool cx_rbtreeHasKey(cx_rbtree tree, const void* key, void** value) {
    return jsw_rbhaskey((jsw_rbtree_t*)tree, key, value);
}

cx_uint32 cx_rbtreeSize(cx_rbtree tree) {
    return jsw_rbsize((jsw_rbtree_t*)tree);
}

void* cx_rbtreeMin(cx_rbtree tree, void** key_out){
    return jsw_rbgetmin((jsw_rbtree_t*)tree, key_out);
}

void* cx_rbtreeMax(cx_rbtree tree, void** key_out) {
    return jsw_rbgetmax((jsw_rbtree_t*)tree, key_out);
}

void* cx_rbtreeNext(cx_rbtree tree, void* key, void** key_out) {
    return jsw_rbgetnext((jsw_rbtree_t*)tree, key, key_out);
}

void* cx_rbtreePrev(cx_rbtree tree, void* key, void** key_out)  {
    return jsw_rbgetprev((jsw_rbtree_t*)tree, key, key_out);
}

/* Note that this function cannot handle NULL values in the tree */
int cx_rbtreeWalk(cx_rbtree tree, cx_walkAction callback, void* userData) {
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
int cx_rbtreeWalkPtr(cx_rbtree tree, cx_walkAction callback, void* userData) {
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

cx_type cx_rbtreeKeyType(cx_rbtree tree) {
    return cx_type(jsw_rbtype((jsw_rbtree_t*)tree));
}
