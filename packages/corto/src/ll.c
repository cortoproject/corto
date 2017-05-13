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

#define get(list, index) corto_ll_get(list, index)
#define walk(list, cb, udata) corto_ll_walk(list, cb, udata)

#define next(iter) corto_ll_iterNext(&iter)
#define remove(iter) corto_ll_iterRemove(&iter)
#define hasNext(iter) corto_ll_iterHasNext(&iter)
#define insert(iter, data) corto_ll_iterInsert(&iter, data)
#define set(iter) corto_ll_iterSet(&iter)

typedef struct corto_ll_node_s {
    void* data;
    corto_ll_node next;
    corto_ll_node prev;
} corto_ll_node_s;

typedef struct corto_ll_s {
    corto_ll_node first;
    corto_ll_node last;
    unsigned int size;
} corto_ll_s;

#define corto_iterData(iter) ((corto_ll_iter_s*)(iter).udata)

/* New list */
corto_ll corto_ll_new() {
    corto_ll result = (corto_ll)malloc(sizeof(corto_ll_s));

    result->first = 0;
    result->last = 0;
    result->last = 0;
    result->size = 0;

    return result;
}

/* Get listsize */
int corto_ll_size(corto_ll list) {
    return list->size;
}

void corto_ll_free(corto_ll list) {
    corto_ll_node node, next;
    node = list->first;
    while (node) {
        next = node->next;
        free(node);
        node = next;
    }

    free(list);
}

int corto_ll_walk(corto_ll list, corto_elementWalk_cb callback, void* userdata) {
    corto_ll_node next;
    corto_ll_node ptr;
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

int corto_ll_walkPtr(corto_ll list, corto_elementWalk_cb callback, void* userdata) {
    corto_ll_node next;
    corto_ll_node ptr;
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
void corto_ll_insert(corto_ll list, void* data) {
    corto_iter iter = corto_ll_iter(list);
    insert(iter, data);
}

/* Insert at end */
void corto_ll_append(corto_ll list, void* data) {
    corto_ll_node node = list->first;
    corto_iter iter = corto_ll_iter(list);

    if (node) {
        node = list->last;
    }

    corto_iterData(iter)->cur = node;
    corto_iterData(iter)->next = 0;

    insert(iter, data);
}

/* Random access read */
void* corto_ll_get(corto_ll list, int index) {
    corto_ll_node node;
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
void* corto_ll_getPtr(corto_ll list, int index) {
    corto_ll_node node;
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

void* corto_ll_find(corto_ll list, corto_compare_cb callback, void* o) {
    corto_ll_node ptr;
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

corto_uint32 corto_ll_hasObject(corto_ll list, void* o) {
    corto_ll_node ptr;
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
void* corto_ll_last(corto_ll list) {
    if (list->last) {
        return list->last->data;
    }
    return 0;
}

/* Take first */
void* corto_ll_takeFirst(corto_ll list) {
    void* data;
    corto_ll_node node;

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
void* corto_ll_remove(corto_ll list, void* o) {
    corto_ll_node node, prev;
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
void corto_ll_replace(corto_ll list, void* src, void* by) {
    corto_ll_node node;

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
void corto_ll_appendList(corto_ll l1, corto_ll l2) {
    corto_ll_node ptr;

    ptr = l2->first;
    while(ptr) {
        corto_ll_insert(l1, ptr->data);
        ptr = ptr->next;
    }
}

/* Insert one list into another */
void corto_ll_insertList(corto_ll l1, corto_ll l2) {
    printf("TODO\n");
    (void)l1;
    (void)l2;
}

/* Reverse list */
void corto_ll_reverse(corto_ll list) {
    corto_uint32 i, size = corto_ll_size(list);
    corto_ll_node start = list->first;
    corto_ll_node end = list->last;
    corto_ll_node ptr;

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
corto_ll corto_ll_copy(corto_ll list) {
    corto_iter iter = corto_ll_iter(list);
    corto_ll result = NULL;
    if (list) {
        result = corto_ll_new();
        while (corto_iter_hasNext(&iter)) {
            corto_ll_append(result, corto_iter_next(&iter));
        }
    }
    return result;
}

/* Clear list */
void corto_ll_clear(corto_ll list) {
    while(list->size) {
        corto_ll_takeFirst(list);
    }
}

/* Return list iterator */
corto_iter _corto_ll_iter(corto_ll list, void *udata) {
    corto_iter result;

    result.udata = udata;
    corto_iterData(result)->cur = 0;
    corto_iterData(result)->next = list->first;
    corto_iterData(result)->list = list;
    result.hasNext = corto_ll_iterHasNext;
    result.next = corto_ll_iterNext;
    result.nextPtr = corto_ll_iterNextPtr;
    result.release = NULL;

    return result;
}

corto_iter corto_ll_iterAlloc(corto_ll list) {
    corto_iter result;
    corto_ll_iter_s *udata =  corto_alloc(sizeof(corto_ll_iter_s));
    result = _corto_ll_iter(list, udata);
    result.release = corto_ll_iterRelease;
    return result;
}

void corto_ll_iterRelease(corto_iter *iter) {
    corto_dealloc(iter->udata);
    iter->udata = NULL;
}

void corto_ll_iterMoveFirst(corto_iter* iter) {
    corto_iterData(*iter)->cur = 0;
    corto_iterData(*iter)->next = (corto_iterData(*iter)->list)->first;
}

void* corto_ll_iterMove(corto_iter* iter, unsigned int index) {
    void* result;

    result = NULL;

    if (corto_iterData(*iter)->list->size <= index) {
        corto_critical("iterMove exceeds list-bound (%d >= %d).", index, (corto_iterData(*iter)->list)->size);
    }
    corto_ll_iterMoveFirst(iter);
    while(index) {
        result = corto_iter_next(iter);
        index--;
    }

    return result;
}

/* Can the iterator provide a 'next' value */
int corto_ll_iterHasNext(corto_iter* iter) {
    return corto_iterData(*iter)->next != 0;
}

/* Take next element of iterator */
void* corto_ll_iterNext(corto_iter* iter) {
    corto_ll_node current;
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
void* corto_ll_iterNextPtr(corto_iter* iter) {
    corto_ll_node current;
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
void* corto_ll_iterRemove(corto_iter* iter) {
    corto_ll_node current;
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
void corto_ll_iterInsert(corto_iter* iter, void* o) {
    corto_ll_node newNode;
    corto_ll_node current;
    corto_ll_node next;

    current = corto_iterData(*iter)->cur;
    next = corto_iterData(*iter)->next;

    newNode = malloc(sizeof(corto_ll_node_s));
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
void corto_ll_iterSet(corto_iter* iter, void* o) {
    if (corto_iterData(*iter)->cur) {
        ((corto_ll_node)corto_iterData(*iter)->cur)->data = o;
    } else {
        corto_critical("Illegal use of 'set' by corto_iter: no element selected. Use 'next' to select an element first.");
    }
}

corto_ll corto_ll_map(corto_ll l, corto_mapAction f, void* data)
{
    corto_ll ll = corto_ll_new();
    {
        corto_iter i = corto_ll_iter(l);
        while (corto_iter_hasNext(&i)) {
            void* e = corto_iter_next(&i);
            void* r = f(e, data);
            corto_ll_append(ll, r);
        }
    }
    return ll;
}
