/* Copyright (c) 2010-2017 the corto developers
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <corto/corto.h>
#include "jsw_rbtree.h"

corto_rbtree corto_rb_new(corto_type keyType) {

    corto_assert(keyType->size <= sizeof(corto_word), "corto_rb_new: keytype sizes cannot be larger than the size of a word.");

    return (corto_rbtree)jsw_rbnew(keyType, NULL);
}

corto_rbtree corto_rb_new_w_func(corto_equals_cb compare) {
    return (corto_rbtree)jsw_rbnew(NULL, compare);
}

void corto_rb_free(corto_rbtree tree) {
    jsw_rbdelete((jsw_rbtree_t*)tree);
}

void* corto_rb_get(corto_rbtree tree, void* key) {
    return jsw_rbfind((jsw_rbtree_t*)tree, key);
}

void* corto_rb_getPtr(corto_rbtree tree, void* key) {
    return jsw_rbfindPtr((jsw_rbtree_t*)tree, key);
}

void corto_rb_set(corto_rbtree tree, const void* key, void* value) {
    jsw_rbinsert((jsw_rbtree_t*)tree, (void*)key, value, NULL, TRUE);
}

void* corto_rb_findOrSet(corto_rbtree tree, const void* key, void* value) {
    void *old = NULL;
    jsw_rbinsert((jsw_rbtree_t*)tree, (void*)key, value, &old, FALSE);
    return old;
}

void corto_rb_remove(corto_rbtree tree, void* key) {
    jsw_rberase((jsw_rbtree_t*)tree, key);
}

corto_bool corto_rb_hasKey(corto_rbtree tree, const void* key, void** value) {
    return jsw_rbhaskey((jsw_rbtree_t*)tree, key, value);
}

corto_bool corto_rb_hasKey_w_cmp(corto_rbtree tree, const void* key, void** value, corto_equals_cb cmp) {
    return jsw_rbhaskey_w_cmp((jsw_rbtree_t*)tree, key, value, cmp);
}

corto_uint32 corto_rb_size(corto_rbtree tree) {
    return jsw_rbsize((jsw_rbtree_t*)tree);
}

void* corto_rb_min(corto_rbtree tree, void** key_out){
    return jsw_rbgetmin((jsw_rbtree_t*)tree, key_out);
}

void* corto_rb_max(corto_rbtree tree, void** key_out) {
    return jsw_rbgetmax((jsw_rbtree_t*)tree, key_out);
}

void* corto_rb_next(corto_rbtree tree, void* key, void** key_out) {
    return jsw_rbgetnext((jsw_rbtree_t*)tree, key, key_out);
}

void* corto_rb_prev(corto_rbtree tree, void* key, void** key_out)  {
    return jsw_rbgetprev((jsw_rbtree_t*)tree, key, key_out);
}

/* Note that this function cannot handle NULL values in the tree */
int corto_rb_walk(corto_rbtree tree, corto_elementWalk_cb callback, void* userData) {
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
int corto_rb_walkPtr(corto_rbtree tree, corto_elementWalk_cb callback, void* userData) {
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

corto_type corto_rb_keyType(corto_rbtree tree) {
    return corto_type(jsw_rbtype((jsw_rbtree_t*)tree));
}

#define corto_iterData(iter) ((jsw_rbtrav_t*)iter->ctx)

static int corto_rb_iterHasNext(corto_iter *iter) {
    return corto_iterData(iter)->it != NULL;
}

static void* corto_rb_iterNext(corto_iter *iter) {
    void* data = corto_iterData(iter)->it ?
        jsw_rbnodedata(corto_iterData(iter)->it) : NULL;
    jsw_rbtnext(corto_iterData(iter));
    return data;
}

corto_bool corto_rb_iterChanged(corto_iter *iter) {
    if (corto_iterData(iter)) {
        return jsw_rbtchanged(corto_iterData(iter));
    } else {
        return FALSE;
    }
}

corto_iter _corto_rb_iter(corto_rbtree tree, void *ctx) {
    corto_iter result;

    result.ctx = ctx;
    jsw_rbtfirst(result.ctx, (jsw_rbtree_t*)tree);
    result.hasNext = corto_rb_iterHasNext;
    result.next = corto_rb_iterNext;
    result.release = NULL;

    return result;
}
