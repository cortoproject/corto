/*
 * cx_ll.c
 *
 *  Created on: Apr 19, 2012
 *      Author: sander
 */


#include "cx_ll.h"
#include "cx_err.h"
#include "cx_object.h"

#include "stdlib.h"

/* List convenience macros (to be replaced with generic collection interface) */
#define get(list, index) cx_llGet(list, index)
#define walk(list, cb, udata) cx_llWalk(list, cb, udata)

/* Iterator convenience macros (to be replaced with generic collection interface) */
#define next(iter) cx_iterNext(&iter)
#define remove(iter) cx_iterRemove(&iter)
#define hasNext(iter) cx_iterHasNext(&iter)
#define insert(iter, data) cx_iterInsert(&iter, data)
#define set(iter) cx_iterSet(&iter)

typedef struct cx_ll_s {
	cx_llNode first;
	cx_llNode last;
	unsigned int maximum;
	unsigned int size;
	cx_llNode lastFreed;
}cx_ll_s;

typedef struct cx_llNode_s {
	void* data;
	cx_llNode next;
	cx_llNode prev;
}cx_llNode_s;

/* New list */
cx_ll cx_llNew() {
	cx_ll result = (cx_ll)malloc(sizeof(cx_ll_s));

	result->first = 0;
	result->last = 0;
	result->last = 0;
	result->maximum = 0; /* by default unbounded */
	result->size = 0;
	result->lastFreed = NULL;

	return result;
}

/* Get listsize */
int cx_llSize(cx_ll list) {
	return list->size;
}

/* Set maximum */
void cx_llSetMax(cx_ll list, unsigned int maximum) {
	list->maximum = maximum;
}

void cx_llFree(cx_ll list) {
	cx_llNode node, next;
	node = list->first;
	while(node) {
		next = node->next;
		free(node);
		node = next;
	}
	if (list->lastFreed) {
	    free(list->lastFreed);
	}

	free(list);
}

int cx_llWalk(cx_ll list, cx_walkAction callback, void* userdata) {
	cx_llNode next;
	cx_llNode ptr;
	int result;
	cx_uint32 i=0;

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

int cx_llWalkPtr(cx_ll list, cx_walkAction callback, void* userdata) {
	cx_llNode next;
	cx_llNode ptr;
	int result;
	cx_uint32 i=0;
    
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
void cx_llInsert(cx_ll list, void* data) {
	cx_iter iter = cx_llIter(list);
	insert(iter, data);
}

/* Insert at end */
void cx_llAppend(cx_ll list, void* data) {
	cx_llNode node = list->first;
	cx_iter iter;

	if (node) {
		node = list->last;
	}

	iter.cur = node;
	iter.next = 0;
	iter.list = list;

	insert(iter, data);
}

/* Random access read */
void* cx_llGet(cx_ll list, int index) {
	cx_llNode node;
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
void* cx_llGetPtr(cx_ll list, int index) {
	cx_llNode node;
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

void* cx_llFind(cx_ll list, cx_compareAction callback, void* o) {
	cx_llNode ptr;
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

cx_uint32 cx_llHasObject(cx_ll list, void* o) {
    cx_llNode ptr;
    cx_uint32 index = 0;

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
void* cx_llLast(cx_ll list) {
	if (list->last) {
		return list->last->data;
	}
	return 0;
}

/* Take first */
void* cx_llTakeFirst(cx_ll list) {
	void* data;
	cx_llNode node;

	node = list->first;
	data = 0;

	if (node) {
		data = node->data;
		list->first = node->next;
		if (!list->lastFreed) {
			list->lastFreed = node;
		} else {
			free(node);
		}
		if (!list->first) {
			list->last = 0;
		}
		list->size--;
	}

	return data;
}

/* Remove object */
void cx_llRemove(cx_ll list, void* o) {
	cx_llNode node, prev;
	cx_bool found = FALSE;

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
	    cx_error("ll::remove: list does not contain %p", o);
	}
}

/* Replace object */
void cx_llReplace(cx_ll list, void* src, void* by) {
	cx_llNode node;

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
void cx_llAppendList(cx_ll l1, cx_ll l2) {
    cx_llNode ptr;

    ptr = l2->first;
    while(ptr) {
        cx_llInsert(l1, ptr->data);
        ptr = ptr->next;
    }
}

/* Insert one list into another */
void cx_llInsertList(cx_ll l1, cx_ll l2) {
	printf("TODO\n");
	(void)l1;
	(void)l2;
}

/* Reverse list */
void cx_llReverse(cx_ll list) {
    cx_uint32 i, size = cx_llSize(list);
    cx_llNode start = list->first;
    cx_llNode end = list->last;
    cx_llNode ptr;
    
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
            cx_assert(ptr != NULL, "linked list corrupt");
            end = ptr;
        }
    }
}

/* Clear list */
void cx_llClear(cx_ll list) {
    while(cx_llTakeFirst(list));
}

/* Return list iterator */
cx_iter cx_llIter(cx_ll list) {
	cx_iter result;

	result.cur = 0;
	result.next = list->first;
	result.list = list;

	return result;
}

void cx_iterMoveFirst(cx_iter* iter) {
	iter->cur = 0;
	iter->next = iter->list->first;
}

void* cx_iterMove(cx_iter* iter, unsigned int index) {
    void* result;

    result = NULL;

    if (iter->list->size <= index) {
        cx_critical("iterMove exceeds list-bound (%d >= %d).", index, iter->list->size);
    }
    cx_iterMoveFirst(iter);
    while(index) {
        result = cx_iterNext(iter);
        index--;
    }
    return result;
}

/* Can the iterator provide a 'next' value */
int cx_iterHasNext(cx_iter* iter) {
	return iter->next != 0;
}

/* Take next element of iterator */
void* cx_iterNext(cx_iter* iter) {
	cx_llNode current;
	void* result;

	current = iter->next;
	result = 0;

	if (current) {
		iter->next = current->next;
		result = current->data;
		iter->cur = current;
	} else {
		cx_critical("Illegal use of 'next' by cx_iter. Use 'hasNext' to check if data is still available.");
	}

	return result;
}

/* Take next element of iterator */
void* cx_iterNextPtr(cx_iter* iter) {
	cx_llNode current;
	void* result;
    
	current = iter->next;
	result = 0;
    
	if (current) {
		iter->next = current->next;
		result = &current->data;
		iter->cur = current;
	} else {
		cx_critical("Illegal use of 'next' by cx_iter. Use 'hasNext' to check if data is still available.");
	}
    
	return result;
}

/* Remove the last-read element from the iterator. */
void* cx_iterRemove(cx_iter* iter) {
	cx_llNode current;
	void* result;

	result = 0;

	if ((current = iter->cur)) {
		if (iter->list->first == current) {
			iter->list->first = current->next;
		}
		if (iter->list->last == current) {
			iter->list->last = current->next;
		}
		if (current->prev) {
			current->prev->next = current->next;
		}
		if (current->next) {
			current->next->prev = current->prev;
		}
		result = current->data;
		free(current);
		iter->list->size--;
	} else {
		cx_critical("Illegal use of 'remove' by cx_iter: no element selected. Use 'next' to select an element first.");
	}

	return result;
}

/* Insert element after current (update next of iterator) */
void cx_iterInsert(cx_iter* iter, void* o) {
	cx_llNode newNode;
	cx_llNode current;
	cx_llNode next;

	current = iter->cur;
	next = iter->next;

	if (iter->list->lastFreed) {
		newNode = iter->list->lastFreed;
		iter->list->lastFreed = NULL;
	} else {
		newNode = malloc(sizeof(cx_llNode_s));
	}
	newNode->data = o;
	newNode->prev = current;
	newNode->next = next;
	if (!next) {
		iter->list->last = newNode;
	}
	if (current) {
		current->next = newNode;
	} else {
		iter->list->first = newNode;
	}
	if (next) {
		next->prev = newNode;
	}

	iter->list->size++;
	iter->next = newNode;
}

/* Set data of current element. */
void cx_iterSet(cx_iter* iter, void* o) {
	if (iter->cur) {
		iter->cur->data = o;
	} else {
		cx_critical("Illegal use of 'set' by cx_iter: no element selected. Use 'next' to select an element first.");
	}
}

