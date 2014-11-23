/*
 * ll.cpp
 *
 *  Created on: Jan 27, 2013
 *      Author: sander
 */

#include "hyve/ll.hpp"
#include "stdio.h"

extern "C" {
typedef void* db_ll;
typedef void* db_llNode;
typedef struct db_iter {
	db_llNode next;
	db_llNode cur;
	db_llNode last;
	db_ll list;
}db_iter;

db_ll db_llNew(void);
void db_llFree(db_ll);
int db_llWalk(db_ll list, hyve::walkAction callback, void* userdata);
void db_llInsert(db_ll list, void* data);
void db_llAppend(db_ll list, void* data);
void db_llRemove(db_ll list, void* o);
void db_llReplace(db_ll list, void* o, void* by);
void* db_llTakeFirst(db_ll);
void* db_llGet(db_ll list, int index);
void* db_llFind(db_ll list, hyve::compareAction callback, void* o);
hyve::lang::_bool db_llHasObject(db_ll list, void* o);
void* db_llLast(db_ll list);
int db_llSize(db_ll list);
db_iter db_llIter(db_ll);
void db_llMerge(db_ll l1, db_ll l2);
void db_iterMoveFirst(db_iter* iter);
void* db_iterMove(db_iter* iter, unsigned int index);
int db_iterHasNext(db_iter* iter);
void* db_iterNext(db_iter* iter);
void* db_iterRemove(db_iter* iter);
void db_iterInsert(db_iter* iter, void* o);
void db_iterSet(db_iter* iter, void* o);
void db_iterLast(db_iter* iter);
}

namespace hyve {

ll::ll() {
	this->handle = NULL;
	this->owned = true;
}

ll::ll(ll_h handle) {
	this->handle = handle;
	this->owned = false;
}

ll::~ll() {
	if (this->owned) {
		if (this->handle) {
			db_llFree((db_ll)this->handle);
		}
	}
}

ll_h ll::_new() {
	return db_llNew();
}

/* Walk elements */
int ll::walk(hyve::walkAction action, void* userData) {
	return db_llWalk((db_ll)this->handle, action, userData);
}

/* Insert element at beginning of list */
void ll::insert(void* data) {
	db_llInsert((db_ll)this->handle, data);
}

/* Insert element at end of list */
void ll::append(void* data) {
	db_llAppend((db_ll)this->handle, data);
}

/* Remove element */
void ll::remove(void* data) {
	db_llRemove((db_ll)this->handle, data);
}

/* Replace element */
void ll::replace(void* object, void* by) {
	db_llReplace((db_ll)this->handle, object, by);
}

/* Take first element */
void* ll::takeFirst() {
	return db_llTakeFirst((db_ll)this->handle);
}

/* Random access read */
void* ll::get(int index) {
	return db_llGet((db_ll)this->handle, index);
}

/* Find element */
void* ll::find(hyve::compareAction compare, void* object) {
	return db_llFind((db_ll)this->handle, compare, object);
}

/* Check if object is in list */
hyve::lang::_bool ll::hasObject(void* object) {
	return db_llHasObject((db_ll)this->handle, object);
}

/* Last element */
void* ll::last() {
	return db_llLast((db_ll)this->handle);
}

/* Size of list */
int ll::size() {
    if (this->handle) {
        return db_llSize((db_ll)this->handle);
    } else {
        return 0;
    }
}

/* Merge with other list */
void ll::merge(hyve::ll* list) {
	return db_llMerge((db_ll)this->handle, (db_ll)(list->getHandle()));
}

/* Get handle */
void* ll::getHandle() {
	return this->handle;
}

}
