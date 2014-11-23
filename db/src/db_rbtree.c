/*
 * db_rbtree.c
 *
 *  Created on: Jul 17, 2012
 *      Author: sander
 *
 *  This implementation is a wrapper around the jsw_rbtree (http://www.eternallyconfuzzled.com) implementation.
 */

#include "db_mem.h"
#include "db_util.h"
#include "db_rbtree.h"
#include "db_type.h"
#include "jsw_rbtree.h"
#include "db_err.h"

db_rbtree db_rbtreeNew(db_type keyType) {

    db_assert(keyType->size <= sizeof(db_word), "db_rbtreeNew: keytype sizes cannot be larger than the size of a word.");

    return (db_rbtree)jsw_rbnew(keyType, NULL);
}

db_rbtree db_rbtreeNew_w_func(db_equalsAction compare) {
    return (db_rbtree)jsw_rbnew(NULL, compare);
}

void db_rbtreeFree(db_rbtree tree) {
    jsw_rbdelete((jsw_rbtree_t*)tree);
}

void* db_rbtreeGet(db_rbtree tree, void* key) {
    return jsw_rbfind((jsw_rbtree_t*)tree, key);
}

void* db_rbtreeGetPtr(db_rbtree tree, void* key) {
    return jsw_rbfindPtr((jsw_rbtree_t*)tree, key);
}

void db_rbtreeSet(db_rbtree tree, const void* key, void* value) {
    jsw_rbinsert((jsw_rbtree_t*)tree, (void*)key, value);
}

void db_rbtreeRemove(db_rbtree tree, void* key) {
    jsw_rberase((jsw_rbtree_t*)tree, key);
}

db_bool db_rbtreeHasKey(db_rbtree tree, const void* key, void** value) {
    return jsw_rbhaskey((jsw_rbtree_t*)tree, key, value);
}

db_uint32 db_rbtreeSize(db_rbtree tree) {
    return jsw_rbsize((jsw_rbtree_t*)tree);
}

void* db_rbtreeMin(db_rbtree tree, void** key_out){
    return jsw_rbgetmin((jsw_rbtree_t*)tree, key_out);
}

void* db_rbtreeMax(db_rbtree tree, void** key_out) {
    return jsw_rbgetmax((jsw_rbtree_t*)tree, key_out);
}

void* db_rbtreeNext(db_rbtree tree, void* key, void** key_out) {
    return jsw_rbgetnext((jsw_rbtree_t*)tree, key, key_out);
}

void* db_rbtreePrev(db_rbtree tree, void* key, void** key_out)  {
    return jsw_rbgetprev((jsw_rbtree_t*)tree, key, key_out);
}

/* Note that this function cannot handle NULL values in the tree */
int db_rbtreeWalk(db_rbtree tree, db_walkAction callback, void* userData) {
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
int db_rbtreeWalkPtr(db_rbtree tree, db_walkAction callback, void* userData) {
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

db_typedef db_rbtreeKeyType(db_rbtree tree) {
	return db_typedef(jsw_rbtype((jsw_rbtree_t*)tree));
}
