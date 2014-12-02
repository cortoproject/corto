/*
 * db_ll.h
 *
 *  Created on: Sep 20, 2011
 *      Author: sander
 */

#ifndef DB_LL_H_
#define DB_LL_H_

#include "db__type.h"
#include "db_collection.h"
#include "db_def.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct db_llNode_s* db_llNode;

typedef struct db_iter {
	db_llNode next;
	db_llNode cur;
	db_ll list;
}db_iter;

db_ll db_llNew(void);
void db_llFree(db_ll);

/* Walk list */
int db_llWalk(db_ll list, db_walkAction callback, void* userdata);
    
/* Walk list, return pointers to elements */
int db_llWalkPtr(db_ll list, db_walkAction callback, void* userdata);

/* Insert at start. */
void db_llInsert(db_ll list, void* data);

/* Insert at end */
void db_llAppend(db_ll list, void* data);

/* Remove object */
void db_llRemove(db_ll list, void* o);

/* Replace object */
void db_llReplace(db_ll list, void* o, void* by);

/* Take first */
void* db_llTakeFirst(db_ll);

/* Random access read */
void* db_llGet(db_ll list, int index);

/* Get element ptr */
void* db_llGetPtr(db_ll list, int index);

/* Find object - performs semantic comparison */
void* db_llFind(db_ll list, db_compareAction callback, void* o);

/* Check if object is in list - simple compare on address */
db_uint32 db_llHasObject(db_ll list, void* o);

/* Last element */
void* db_llLast(db_ll list);

/* Get listsize */
int db_llSize(db_ll list);

/* Obtain iterator */
db_iter db_llIter(db_ll);

/* Append one list to another */
void db_llAppendList(db_ll l1, db_ll l2);

/* Insert one list into another */
void db_llInsertList(db_ll l1, db_ll l2);

/* Reverse list */
void db_llReverse(db_ll list);
    
/* Clear list */
void db_llClear(db_ll list);
    
/* Iterator implementation */
void db_iterMoveFirst(db_iter* iter);
void* db_iterMove(db_iter* iter, unsigned int index);
int db_iterHasNext(db_iter* iter);
void* db_iterNext(db_iter* iter);
void* db_iterNextPtr(db_iter* iter);
void* db_iterRemove(db_iter* iter);
void db_iterInsert(db_iter* iter, void* o);
void db_iterSet(db_iter* iter, void* o);

#ifdef __cplusplus
}
#endif

#endif


