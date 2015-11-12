/*
 * corto_ll.c
 *
 *  Created on: Apr 19, 2012
 *      Author: sander
 */


#include "corto_ll.h"
#include "corto_err.h"
#include "corto_object.h"

#include "stdlib.h"

/* List convenience macros (to be replaced with generic collection interface) */
#define get(list, index) corto_llGet(list, index)
#define walk(list, cb, udata) corto_llWalk(list, cb, udata)

/* Iterator convenience macros (to be replaced with generic collection interface) */
#define next(iter) corto_iterNext(&iter)
#define remove(iter) corto_iterRemove(&iter)
#define hasNext(iter) corto_iterHasNext(&iter)
#define insert(iter, data) corto_iterInsert(&iter, data)
#define set(iter) corto_iterSet(&iter)

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

int corto_llWalk(corto_ll list, corto_walkAction callback, void* userdata) {
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

int corto_llWalkPtr(corto_ll list, corto_walkAction callback, void* userdata) {
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

    result = 0;
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

void* corto_llFind(corto_ll list, corto_compareAction callback, void* o) {
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
void corto_llRemove(corto_ll list, void* o) {
    corto_llNode node, prev;
    corto_bool found = FALSE;

    prev = 0;
    node = list->first;

    while(node) {
        if (node->data == o) {
            found = TRUE;
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
            break;
        }
        prev = node;
        node = node->next;
    }
    list->size--;

    if (!found) {
        corto_error("ll::remove: list does not contain %p", o);
    }
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
    result.moveFirst = corto_llIterMoveFirst;
    result.move = corto_llIterMove;
    result.hasNext = corto_llIterHasNext;
    result.next = corto_llIterNext;
    result.nextPtr = corto_llIterNextPtr;
    result.remove = corto_llIterRemove;
    result.insert = corto_llIterInsert;
    result.set = corto_llIterSet;

    return result;
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
    corto_iterMoveFirst(iter);
    while(index) {
        result = corto_iterNext(iter);
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
