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

#ifndef CORTO_LL_H_
#define CORTO_LL_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef struct corto_ll_node_s* corto_ll_node;

typedef struct corto_ll_iter_s {
    corto_ll list;
    corto_ll_node cur;
    corto_ll_node next;
} corto_ll_iter_s;

CORTO_EXPORT corto_ll corto_ll_new(void);
CORTO_EXPORT void corto_ll_free(corto_ll);

/* Walk list */
CORTO_EXPORT int corto_ll_walk(corto_ll list, corto_elementWalk_cb callback, void* userdata);

/* Walk list, return pointers to elements */
CORTO_EXPORT int corto_ll_walkPtr(corto_ll list, corto_elementWalk_cb callback, void* userdata);

/* Insert at start. */
CORTO_EXPORT void corto_ll_insert(corto_ll list, void* data);

/* Insert at end */
CORTO_EXPORT void corto_ll_append(corto_ll list, void* data);

/* Remove object */
CORTO_EXPORT void* corto_ll_remove(corto_ll list, void* o);

/* Replace object */
CORTO_EXPORT void corto_ll_replace(corto_ll list, void* o, void* by);

/* Take first */
CORTO_EXPORT void* corto_ll_takeFirst(corto_ll);

/* Random access read */
CORTO_EXPORT void* corto_ll_get(corto_ll list, int index);

/* Get element ptr */
CORTO_EXPORT void* corto_ll_getPtr(corto_ll list, int index);

/* Find object - comparison by value */
CORTO_EXPORT void* corto_ll_find(corto_ll list, corto_compare_cb callback, void* o);

/* Find object, return ptr - comparison by value */
CORTO_EXPORT void* corto_ll_findPtr(corto_ll list, corto_compare_cb callback, void* o);

/* Check if object is in list - simple compare on address */
CORTO_EXPORT unsigned int corto_ll_hasObject(corto_ll list, void* o);

/* Last element */
CORTO_EXPORT void* corto_ll_last(corto_ll list);

/* Get listsize */
CORTO_EXPORT int corto_ll_size(corto_ll list);

/* Obtain regular iterator, not valid outside scope of origin. */
#define corto_ll_iter(list) _corto_ll_iter(list, alloca(sizeof(corto_ll_iter_s)));
CORTO_EXPORT corto_iter _corto_ll_iter(corto_ll, void *ctx);

/* Obtain persistent iterator. Requries corto_iter_release to be called */
CORTO_EXPORT corto_iter corto_ll_iterAlloc(corto_ll);

/* Iterator cleanup functions */
CORTO_EXPORT void corto_ll_iterRelease(corto_iter *iter);

/* Append one list to another */
CORTO_EXPORT void corto_ll_appendList(corto_ll l1, corto_ll l2);

/* Insert one list into another */
CORTO_EXPORT void corto_ll_insertList(corto_ll l1, corto_ll l2);

/* Reverse list */
CORTO_EXPORT void corto_ll_reverse(corto_ll list);

/* Clear list */
CORTO_EXPORT void corto_ll_clear(corto_ll list);

/* Copy list */
CORTO_EXPORT corto_ll corto_ll_copy(corto_ll list);

/* Iterator implementation */
CORTO_EXPORT void corto_ll_iterMoveFirst(corto_iter* iter);
CORTO_EXPORT void *corto_ll_iterMove(corto_iter* iter, unsigned int index);
CORTO_EXPORT int corto_ll_iterHasNext(corto_iter* iter);
CORTO_EXPORT void* corto_ll_iterNext(corto_iter* iter);
CORTO_EXPORT void* corto_ll_iterNextPtr(corto_iter* iter);
CORTO_EXPORT void* corto_ll_iterRemove(corto_iter* iter);
CORTO_EXPORT void corto_ll_iterInsert(corto_iter* iter, void* o);
CORTO_EXPORT void corto_ll_iterSet(corto_iter* iter, void* o);

/* Functional-style */
typedef void* (*corto_mapAction)(void* elem, void* data);
CORTO_EXPORT corto_ll corto_ll_map(corto_ll l, corto_mapAction f, void* data);


#ifdef __cplusplus
}
#endif

#endif
