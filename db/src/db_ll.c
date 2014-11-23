/*
 * db_ll.c
 *
 *  Created on: Apr 19, 2012
 *      Author: sander
 */


#include "db_ll.h"
#include "db_err.h"
#include "db_object.h"

#include "stdlib.h"

/* List convenience macros (to be replaced with generic collection interface) */
#define get(list, index) db_llGet(list, index)
#define walk(list, cb, udata) db_llWalk(list, cb, udata)

/* Iterator convenience macros (to be replaced with generic collection interface) */
#define next(iter) db_iterNext(&iter)
#define remove(iter) db_iterRemove(&iter)
#define hasNext(iter) db_iterHasNext(&iter)
#define insert(iter, data) db_iterInsert(&iter, data)
#define set(iter) db_iterSet(&iter)

typedef struct db_ll_s {
	db_llNode first;
	db_llNode last;
	unsigned int maximum;
	unsigned int size;
	db_llNode lastFreed;
}db_ll_s;

typedef struct db_llNode_s {
	void* data;
	db_llNode next;
	db_llNode prev;
}db_llNode_s;

/* New list */
db_ll db_llNew() {
	db_ll result = (db_ll)malloc(sizeof(db_ll_s));

	result->first = 0;
	result->last = 0;
	result->last = 0;
	result->maximum = 0; /* by default unbounded */
	result->size = 0;
	result->lastFreed = NULL;

	return result;
}

/* Get listsize */
int db_llSize(db_ll list) {
	return list->size;
}

/* Set maximum */
void db_llSetMax(db_ll list, unsigned int maximum) {
	list->maximum = maximum;
}

void db_llFree(db_ll list) {
	db_llNode node, next;
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

int db_llWalk(db_ll list, db_walkAction callback, void* userdata) {
	db_llNode next;
	db_llNode ptr;
	int result;
	db_uint32 i=0;

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

int db_llWalkPtr(db_ll list, db_walkAction callback, void* userdata) {
	db_llNode next;
	db_llNode ptr;
	int result;
	db_uint32 i=0;
    
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
void db_llInsert(db_ll list, void* data) {
	db_iter iter = db_llIter(list);
	insert(iter, data);
}

/* Insert at end */
void db_llAppend(db_ll list, void* data) {
	db_llNode node = list->first;
	db_iter iter;

	if (node) {
		node = list->last;
	}

	iter.cur = node;
	iter.next = 0;
	iter.list = list;

	insert(iter, data);
}

/* Random access read */
void* db_llGet(db_ll list, int index) {
	db_llNode node;
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
void* db_llGetPtr(db_ll list, int index) {
	db_llNode node;
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

void* db_llFind(db_ll list, db_compareAction callback, void* o) {
	db_llNode ptr;
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

db_uint32 db_llHasObject(db_ll list, void* o) {
    db_llNode ptr;
    db_uint32 index = 0;

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
void* db_llLast(db_ll list) {
	if (list->last) {
		return list->last->data;
	}
	return 0;
}

/* Take first */
void* db_llTakeFirst(db_ll list) {
	void* data;
	db_llNode node;

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
void db_llRemove(db_ll list, void* o) {
	db_llNode node, prev;
	db_bool found = FALSE;

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
	    db_error("ll::remove: list does not contain %p", o);
	}
}

/* Replace object */
void db_llReplace(db_ll list, void* src, void* by) {
	db_llNode node;

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
void db_llAppendList(db_ll l1, db_ll l2) {
    db_llNode ptr;

    ptr = l2->first;
    while(ptr) {
        db_llInsert(l1, ptr->data);
        ptr = ptr->next;
    }
}

/* Insert one list into another */
void db_llInsertList(db_ll l1, db_ll l2) {
	printf("TODO\n");
	(void)l1;
	(void)l2;
}

/* Reverse list */
void db_llReverse(db_ll list) {
    db_uint32 i, size = db_llSize(list);
    db_llNode start = list->first;
    db_llNode end = list->last;
    db_llNode ptr;
    
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
            db_assert(ptr != NULL, "linked list corrupt");
            end = ptr;
        }
    }
}

/* Clear list */
void db_llClear(db_ll list) {
    while(db_llTakeFirst(list));
}

/* Return list iterator */
db_iter db_llIter(db_ll list) {
	db_iter result;

	result.cur = 0;
	result.next = list->first;
	result.list = list;

	return result;
}

void db_iterMoveFirst(db_iter* iter) {
	iter->cur = 0;
	iter->next = iter->list->first;
}

void* db_iterMove(db_iter* iter, unsigned int index) {
    void* result;

    result = NULL;

    if (iter->list->size <= index) {
        db_critical("iterMove exceeds list-bound (%d >= %d).", index, iter->list->size);
    }
    db_iterMoveFirst(iter);
    while(index) {
        result = db_iterNext(iter);
        index--;
    }
    return result;
}

/* Can the iterator provide a 'next' value */
int db_iterHasNext(db_iter* iter) {
	return iter->next != 0;
}

/* Take next element of iterator */
void* db_iterNext(db_iter* iter) {
	db_llNode current;
	void* result;

	current = iter->next;
	result = 0;

	if (current) {
		iter->next = current->next;
		result = current->data;
		iter->cur = current;
	} else {
		db_critical("Illegal use of 'next' by db_iter. Use 'hasNext' to check if data is still available.");
	}

	return result;
}

/* Take next element of iterator */
void* db_iterNextPtr(db_iter* iter) {
	db_llNode current;
	void* result;
    
	current = iter->next;
	result = 0;
    
	if (current) {
		iter->next = current->next;
		result = &current->data;
		iter->cur = current;
	} else {
		db_critical("Illegal use of 'next' by db_iter. Use 'hasNext' to check if data is still available.");
	}
    
	return result;
}

/* Remove the last-read element from the iterator. */
void* db_iterRemove(db_iter* iter) {
	db_llNode current;
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
		db_critical("Illegal use of 'remove' by db_iter: no element selected. Use 'next' to select an element first.");
	}

	return result;
}

/* Insert element after current (update next of iterator) */
void db_iterInsert(db_iter* iter, void* o) {
	db_llNode newNode;
	db_llNode current;
	db_llNode next;

	current = iter->cur;
	next = iter->next;

	if (iter->list->lastFreed) {
		newNode = iter->list->lastFreed;
		iter->list->lastFreed = NULL;
	} else {
		newNode = malloc(sizeof(db_llNode_s));
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
void db_iterSet(db_iter* iter, void* o) {
	if (iter->cur) {
		iter->cur->data = o;
	} else {
		db_critical("Illegal use of 'set' by db_iter: no element selected. Use 'next' to select an element first.");
	}
}

