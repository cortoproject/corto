/*
 * cx_ll.h
 *
 *  Created on: Sep 20, 2011
 *      Author: sander
 */

#ifndef CX_LL_H_
#define CX_LL_H_

#include "cx_def.h"
#include "cx_iter.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct cx_llNode_s* cx_llNode;

typedef struct cx_llIter_s {
    cx_ll list;
    cx_llNode cur;
    cx_llNode next;
} cx_llIter_s;

cx_ll cx_llNew(void);
void cx_llFree(cx_ll);

/* Walk list */
int cx_llWalk(cx_ll list, cx_walkAction callback, void* userdata);
    
/* Walk list, return pointers to elements */
int cx_llWalkPtr(cx_ll list, cx_walkAction callback, void* userdata);

/* Insert at start. */
void cx_llInsert(cx_ll list, void* data);

/* Insert at end */
void cx_llAppend(cx_ll list, void* data);

/* Remove object */
void cx_llRemove(cx_ll list, void* o);

/* Replace object */
void cx_llReplace(cx_ll list, void* o, void* by);

/* Take first */
void* cx_llTakeFirst(cx_ll);

/* Random access read */
void* cx_llGet(cx_ll list, int index);

/* Get element ptr */
void* cx_llGetPtr(cx_ll list, int index);

/* Find object - performs semantic comparison */
void* cx_llFind(cx_ll list, cx_compareAction callback, void* o);

/* Check if object is in list - simple compare on address */
unsigned int cx_llHasObject(cx_ll list, void* o);

/* Last element */
void* cx_llLast(cx_ll list);

/* Get listsize */
int cx_llSize(cx_ll list);

/* Obtain iterator */
#define cx_llIter(list) _cx_llIter(list, alloca(sizeof(cx_llIter_s)));
cx_iter _cx_llIter(cx_ll, void *udata);

/* Append one list to another */
void cx_llAppendList(cx_ll l1, cx_ll l2);

/* Insert one list into another */
void cx_llInsertList(cx_ll l1, cx_ll l2);

/* Reverse list */
void cx_llReverse(cx_ll list);
    
/* Clear list */
void cx_llClear(cx_ll list);
    
/* Iterator implementation */
void cx_llIterMoveFirst(cx_iter* iter);
void *cx_llIterMove(cx_iter* iter, unsigned int index);
int cx_llIterHasNext(cx_iter* iter);
void* cx_llIterNext(cx_iter* iter);
void* cx_llIterNextPtr(cx_iter* iter);
void* cx_llIterRemove(cx_iter* iter);
void cx_llIterInsert(cx_iter* iter, void* o);
void cx_llIterSet(cx_iter* iter, void* o);

#ifdef __cplusplus
}
#endif

#endif


