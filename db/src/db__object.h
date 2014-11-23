/*
 * db__object.h
 *
 *  Created on: Aug 3, 2012
 *      Author: sander
 */

#ifndef DB__OBJECT_H_
#define DB__OBJECT_H_

#include "db__type.h"
#include "db_rbtree.h"
#include "db_ll.h"
#include "db_async.h"
#include "db_object.h"
#include "db_mm.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct db__attr {
    unsigned scope:1;
    unsigned write:1;
    unsigned observable:1;
    unsigned state:4;
}db__attr;

struct db__object;
typedef struct db__object {
    db__attr attrs;
    db_int32 refcount;
    db_typedef type;

    /* Used by garbage collector to mark and unmark objects. */
    struct db_mmNode mm;
}db__object;

typedef struct db__scope {
    db_object parent;
    db_string name;
    db_rbtree scope;
    struct db_rwmutex_s scopeLock;
    db_ll attached;
    db_int32 orphaned;
}db__scope;

typedef struct db__writable {
    struct db_rwmutex_s lock;
}db__writable;

typedef enum db__observerKind {
    DB__OBSERVER,
    DB__OBSERVER_THIS,
    DB__OBSERVER_CDECL,
    DB__OBSERVER_CDECL_THIS,
}db__observerKind;

typedef struct db__observer db__observer;
typedef void (*db__notifyCallback)(db__observer* data, db_object _this, db_object observable, db_object source, db_uint32 mask);

struct db__observer {
	db_object _this;
	db_observer observer;
	db_int32 count;
	db__notifyCallback notify;
	db_bool enabled;
};

typedef struct db__observable db__observable;
struct db__observable {
    /* Protected by lock */
    db_ll onSelf;
    db_ll onChild;
    struct db_rwmutex_s selfLock;
    struct db_rwmutex_s childLock;

    /* Lockless access to observers (zero-terminated)
     *  Element -1 contains a counter which indicates by how many
     *  notify-functions it is being used. When this counter reaches zero, the array
     *  can be deleted. */
    db__observer **onSelfArray;
    db__observer **onChildArray;

    /* If this value is set it means that notifications are in progress. In this state it is unsafe to
     * delete existing onSelf\ChildArrays thus a listen\silence method will have to wait until used
     * is set to false again. */
    db_bool used;

    /* If this value is set to TRUE, updating the observable requires locking the object if it's a writable. This
     * value will only be set to TRUE when there are observers that subscribe on the object's value. */
    db_bool lockRequired;

    /* Optimization: childs only need to look at this value to know if they need to lock instead of walking the hierarchy checking for ON_CHILDS observables. */
    db_bool childLockRequired;

    /* Pointer to first parent that has observers. If there are no observers
     * on any parent-object, this member is NULL. */
    db__observable *parent;
};

/* Initialize static scoped object */
void db__newSSO(db_object sso);
void db__freeSSO(db_object sso);

/* Adopt static scoped object */
int db__adoptSSO(db_object sso);

/* Orphan object */
void db__orphan(db_object o);

/* Call destructor of object (if class) */
int db__destructor(db_object o);

/* Destruct object */
db_uint16 db__destruct(db_object o);

/* Set state on object */
void db__setState(db_object o, db_uint8 state);

#ifdef __cplusplus
}
#endif

#endif /* DB__OBJECT_H_ */
