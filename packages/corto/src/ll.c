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

#include "corto/corto.h"

#define get(list, index) corto_llGet(list, index)
#define walk(list, cb, udata) corto_llWalk(list, cb, udata)

#define next(iter) corto_llIterNext(&iter)
#define remove(iter) corto_llIterRemove(&iter)
#define hasNext(iter) corto_llIterHasNext(&iter)
#define insert(iter, data) corto_llIterInsert(&iter, data)
#define set(iter) corto_llIterSet(&iter)

typedef struct corto_llNode_s {
    void* data;
    corto_llNode next;
    corto_llNode prev;
} corto_llNode_s;

typedef struct corto_ll_s {
    corto_llNode first;
    corto_llNode last;
    unsigned int size;
} corto_ll_s;

#define corto_iterData(iter) ((corto_llIter_s*)(iter).udata)

/* New list */
corto_ll corto_llNew() {
    corto_ll result = (corto_ll)malloc(sizeof(corto_ll_s));

    result->first = 0;
    result->last = 0;
    result->last = 0;
    result->size = 0;

    return result;
}

/* Get listsize */
int corto_llSize(corto_ll list) {
    return list->size;
}

void corto_llFree(corto_ll list) {
    corto_llNode node, next;
    node = list->first;
    while (node) {
        next = node->next;
        free(node);
        node = next;
    }

    free(list);
}

int corto_llWalk(corto_ll list, corto_elementWalk_cb callback, void* userdata) {
    corto_llNode next;
    corto_llNode ptr;
    int result;
    corto_uint32 i=0;

    ptr = list->first;
    result = 1;

    while (ptr) {
        i++;
        next = ptr->next;
        result = callback(ptr->data, userdata);
        if (!result) {
            break;
        }
        ptr = next;
    }

    return result;
}

int corto_llWalkPtr(corto_ll list, corto_elementWalk_cb callback, void* userdata) {
    corto_llNode next;
    corto_llNode ptr;
    int result;
    corto_uint32 i=0;

    ptr = list->first;
    result = 1;

    while (ptr) {
        i++;
        next = ptr->next;
        result = callback(&ptr->data, userdata);
        if (!result) {
            break;
        }
        ptr = next;
    }

    return result;
}

/* Insert at start */
void corto_llInsert(corto_ll list, void* data) {
    corto_iter iter = corto_llIter(list);
    insert(iter, data);
}

/* Insert at end */
void corto_llAppend(corto_ll list, void* data) {
    corto_llNode node = list->first;
    corto_iter iter = corto_llIter(list);

    if (node) {
        node = list->last;
    }

    corto_iterData(iter)->cur = node;
    corto_iterData(iter)->next = 0;

    insert(iter, data);
}

/* Random access read */
void* corto_llGet(corto_ll list, int index) {
    corto_llNode node;
    void* result;
    int i;

    result = NULL;
    i = 0;
    node = list->first;

    while(node && (i < index)) {
        node = node->next;
        i++;
    }
    if (node) {
        result = node->data;
    }
    return result;
}

/* Get element ptr */
void* corto_llGetPtr(corto_ll list, int index) {
    corto_llNode node;
    void* result;
    int i;

    result = 0;
    i = 0;
    node = list->first;

    while(node && (i < index)) {
        node = node->next;
        i++;
    }
    if (node) {
        result = &node->data;
    }

    return result;
}

void* corto_llFind(corto_ll list, corto_compare_cb callback, void* o) {
    corto_llNode ptr;
    void* result;

    ptr = list->first;
    result = 0;

    while (ptr) {
        if (!callback(o, ptr->data)) {
            result = ptr->data;
            break;
        }
        ptr = ptr->next;
    }

    return result;
}

corto_uint32 corto_llHasObject(corto_ll list, void* o) {
    corto_llNode ptr;
    corto_uint32 index = 0;

    ptr = list->first;

    while (ptr) {
        if (o == ptr->data) {
            break;
        }
        ptr = ptr->next;
        index++;
    }

    return ptr ? index+1 : 0;
}

/* Last element */
void* corto_llLast(corto_ll list) {
    if (list->last) {
        return list->last->data;
    }
    return 0;
}

/* Take first */
void* corto_llTakeFirst(corto_ll list) {
    void* data;
    corto_llNode node;

    node = list->first;
    data = 0;

    if (node) {
        data = node->data;
        list->first = node->next;
        free(node);
        if (!list->first) {
            list->last = 0;
        }
        list->size--;
    }

    return data;
}

/* Remove object */
void* corto_llRemove(corto_ll list, void* o) {
    corto_llNode node, prev;
    void *result = NULL;

    prev = 0;
    node = list->first;

    while(node && !result) {
        if (node->data == o) {
            result = o;
            if (prev) {
                prev->next = node->next;
                if (!prev->next) {
                    list->last = prev;
                }
            } else {
                list->first = node->next;
                if (!node->next) {
                    list->last = list->first;
                }
            }
            free(node);
            list->size --;
            break;
        }
        prev = node;
        node = node->next;
    }

    return result;
}

/* Replace object */
void corto_llReplace(corto_ll list, void* src, void* by) {
    corto_llNode node;

    node = list->first;
    while(node) {
        if (node->data == src) {
            node->data = by;
            break;
        }
        node = node->next;
    }
}

/* Append one list to another */
void corto_llAppendList(corto_ll l1, corto_ll l2) {
    corto_llNode ptr;

    ptr = l2->first;
    while(ptr) {
        corto_llInsert(l1, ptr->data);
        ptr = ptr->next;
    }
}

/* Insert one list into another */
void corto_llInsertList(corto_ll l1, corto_ll l2) {
    printf("TODO\n");
    (void)l1;
    (void)l2;
}

/* Reverse list */
void corto_llReverse(corto_ll list) {
    corto_uint32 i, size = corto_llSize(list);
    corto_llNode start = list->first;
    corto_llNode end = list->last;
    corto_llNode ptr;

    for(i=0; i<size / 2; i++) {
        void *tmp = start->data;
        start->data = end->data;
        end->data = tmp;
        start = start->next;

        /* Do in-place reverse, find node that precedes 'end' */
        if (start != end) {
            ptr = start;
            while(ptr && (ptr->next != end)) {
                ptr = ptr->next;
            }
            corto_assert(ptr != NULL, "linked list corrupt");
            end = ptr;
        }
    }
}

/* Copy list */
corto_ll corto_llCopy(corto_ll list) {
    corto_iter iter = corto_llIter(list);
    corto_ll result = NULL;
    if (list) {
        result = corto_llNew();
        while (corto_iter_hasNext(&iter)) {
            corto_llAppend(result, corto_iter_next(&iter));
        }
    }
    return result;
}

/* Clear list */
void corto_llClear(corto_ll list) {
    while(list->size) {
        corto_llTakeFirst(list);
    }
}

/* Return list iterator */
corto_iter _corto_llIter(corto_ll list, void *udata) {
    corto_iter result;

    result.udata = udata;
    corto_iterData(result)->cur = 0;
    corto_iterData(result)->next = list->first;
    corto_iterData(result)->list = list;
    result.hasNext = corto_llIterHasNext;
    result.next = corto_llIterNext;
    result.nextPtr = corto_llIterNextPtr;
    result.release = NULL;

    return result;
}

corto_iter corto_llIterAlloc(corto_ll list) {
    corto_iter result;
    corto_llIter_s *udata =  corto_alloc(sizeof(corto_llIter_s));
    result = _corto_llIter(list, udata);
    result.release = corto_llIterRelease;
    return result;
}

void corto_llIterRelease(corto_iter *iter) {
    corto_dealloc(iter->udata);
    iter->udata = NULL;
}

void corto_llIterMoveFirst(corto_iter* iter) {
    corto_iterData(*iter)->cur = 0;
    corto_iterData(*iter)->next = (corto_iterData(*iter)->list)->first;
}

void* corto_llIterMove(corto_iter* iter, unsigned int index) {
    void* result;

    result = NULL;

    if (corto_iterData(*iter)->list->size <= index) {
        corto_critical("iterMove exceeds list-bound (%d >= %d).", index, (corto_iterData(*iter)->list)->size);
    }
    corto_llIterMoveFirst(iter);
    while(index) {
        result = corto_iter_next(iter);
        index--;
    }

    return result;
}

/* Can the iterator provide a 'next' value */
int corto_llIterHasNext(corto_iter* iter) {
    return corto_iterData(*iter)->next != 0;
}

/* Take next element of iterator */
void* corto_llIterNext(corto_iter* iter) {
    corto_llNode current;
    void* result;

    current = corto_iterData(*iter)->next;
    result = 0;

    if (current) {
        corto_iterData(*iter)->next = current->next;
        result = current->data;
        corto_iterData(*iter)->cur = current;
    } else {
        corto_critical("Illegal use of 'next' by corto_iter. Use 'hasNext' to check if data is still available.");
    }

    return result;
}

/* Take next element of iterator */
void* corto_llIterNextPtr(corto_iter* iter) {
    corto_llNode current;
    void* result;

    current = corto_iterData(*iter)->next;
    result = 0;

    if (current) {
        corto_iterData(*iter)->next = current->next;
        result = &current->data;
        corto_iterData(*iter)->cur = current;
    } else {
        corto_critical("Illegal use of 'next' by corto_iter. Use 'hasNext' to check if data is still available.");
    }

    return result;
}

/* Remove the last-read element from the iterator. */
void* corto_llIterRemove(corto_iter* iter) {
    corto_llNode current;
    void* result;

    result = 0;

    if ((current = corto_iterData(*iter)->cur)) {
        if ((corto_iterData(*iter)->list)->first == current) {
            (corto_iterData(*iter)->list)->first = current->next;
        }
        if ((corto_iterData(*iter)->list)->last == current) {
            (corto_iterData(*iter)->list)->last = current->next;
        }
        if (current->prev) {
            current->prev->next = current->next;
        }
        if (current->next) {
            current->next->prev = current->prev;
        }
        result = current->data;
        free(current);
        (corto_iterData(*iter)->list)->size--;
    } else {
        corto_critical("Illegal use of 'remove' by corto_iter: no element selected. Use 'next' to select an element first.");
    }

    return result;
}

/* Insert element after current (update next of iterator) */
void corto_llIterInsert(corto_iter* iter, void* o) {
    corto_llNode newNode;
    corto_llNode current;
    corto_llNode next;

    current = corto_iterData(*iter)->cur;
    next = corto_iterData(*iter)->next;

    newNode = malloc(sizeof(corto_llNode_s));
    newNode->data = o;
    newNode->prev = current;
    newNode->next = next;
    if (!next) {
        (corto_iterData(*iter)->list)->last = newNode;
    }
    if (current) {
        current->next = newNode;
    } else {
        (corto_iterData(*iter)->list)->first = newNode;
    }
    if (next) {
        next->prev = newNode;
    }

    (corto_iterData(*iter)->list)->size++;
    corto_iterData(*iter)->next = newNode;
}

/* Set data of current element. */
void corto_llIterSet(corto_iter* iter, void* o) {
    if (corto_iterData(*iter)->cur) {
        ((corto_llNode)corto_iterData(*iter)->cur)->data = o;
    } else {
        corto_critical("Illegal use of 'set' by corto_iter: no element selected. Use 'next' to select an element first.");
    }
}

corto_ll corto_llMap(corto_ll l, corto_mapAction f, void* data)
{
    corto_ll ll = corto_llNew();
    {
        corto_iter i = corto_llIter(l);
        while (corto_iter_hasNext(&i)) {
            void* e = corto_iter_next(&i);
            void* r = f(e, data);
            corto_llAppend(ll, r);
        }
    }
    return ll;
}
