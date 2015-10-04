/*
 * cx__object.h
 *
 *  Created on: Aug 3, 2012
 *      Author: sander
 */

#ifndef CX__OBJECT_H_
#define CX__OBJECT_H_

#include "cx__type.h"
#include "cx_rbtree.h"
#include "cx_ll.h"
#include "cx_async.h"
#include "cx_object.h"
#include "cx_mm.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct cx__attr {
    unsigned scope:1;
    unsigned write:1;
    unsigned observable:1;
    unsigned persistent:1;
    unsigned state:4;
}cx__attr;

struct cx__object;
typedef struct cx__object {
    cx__attr attrs;
    cx_int32 refcount;
    cx_type type;

    /* Used by garbage collector to mark and unmark objects. */
    struct cx_mmNode mm;
}cx__object;

typedef struct cx__scope {
    cx_object parent;
    cx_string name;
    cx_rbtree scope;
    struct cx_rwmutex_s scopeLock;
    cx_ll attached;
    cx_int32 declared;
}cx__scope;

typedef struct cx__writable {
    struct cx_rwmutex_s lock;
}cx__writable;

typedef enum cx__observerKind {
    CX__OBSERVER,
    CX__OBSERVER_THIS,
    CX__OBSERVER_CDECL,
    CX__OBSERVER_CDECL_THIS,
}cx__observerKind;

typedef struct cx__observer cx__observer;
typedef void (*cx__notifyCallback)(cx__observer* data, cx_object _this, cx_object observable, cx_uint32 mask);

struct cx__observer {
    cx_object _this;
    cx_observer observer;
    cx_eventMask mask;
    cx_object dispatcher;
    cx_int32 count;
    cx__notifyCallback notify;
};

typedef struct cx__observable cx__observable;
struct cx__observable {
    /* Protected by lock */
    cx_ll onSelf;
    cx_ll onChild;
    struct cx_rwmutex_s selfLock;
    struct cx_rwmutex_s childLock;

    /* Lockless access to observers (zero-terminated)
     *  Element -1 contains a counter which indicates by how many
     *  notify-functions it is being used. When this counter reaches zero, the array
     *  can be deleted. */
    cx__observer **onSelfArray;
    cx__observer **onChildArray;

    /* If this value is set it means that notifications are in progress. In this state it is unsafe to
     * delete existing onSelf\ChildArrays thus a listen\silence method will have to wait until used
     * is set to false again. */
    cx_bool used;

    /* If this value is set to TRUE, updating the observable requires locking the object if it's a writable. This
     * value will only be set to TRUE when there are observers that subscribe on the object's value. */
    cx_bool lockRequired;

    /* Optimization: childs only need to look at this value to know if they need to lock instead of walking the
     * hierarchy checking for ON_CHILDS observables. */
    cx_bool childLockRequired;
};

typedef struct cx__persistent cx__persistent;
struct cx__persistent {
    cx_time timestamp;
    cx_object owner;
};

/* Initialize static scoped object */
void cx__newSSO(cx_object sso);
void cx__freeSSO(cx_object sso);

/* Adopt static scoped object */
int cx__adoptSSO(cx_object sso);

/* Orphan object */
void cx__orphan(cx_object o);

/* Call destructor of object (if class) */
int cx__destructor(cx_object o);

/* Destruct object */
cx_uint16 cx__destruct(cx_object o);

/* Set state on object */
void cx__setState(cx_object o, cx_uint8 state);

#ifdef __cplusplus
}
#endif

#endif /* CX__OBJECT_H_ */
