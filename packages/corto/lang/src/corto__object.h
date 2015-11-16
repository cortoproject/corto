/*
 * corto__object.h
 *
 *  Created on: Aug 3, 2012
 *      Author: sander
 */

#ifndef CORTO__OBJECT_H_
#define CORTO__OBJECT_H_

#include "corto__type.h"
#include "corto_rbtree.h"
#include "corto_ll.h"
#include "corto_async.h"
#include "corto_object.h"
#include "corto_mm.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct corto__attr {
    unsigned scope:1;
    unsigned write:1;
    unsigned observable:1;
    unsigned persistent:1;
    unsigned state:4;
}corto__attr;

struct corto__object;
typedef struct corto__object {
    corto__attr attrs;
    corto_int32 refcount;
    corto_type type;
}corto__object;

typedef struct corto__ols {
    corto_int8 key;
    void *value;
}corto__ols;

typedef struct corto__scope {
    corto_object parent;
    corto_string name;
    corto_rbtree scope;
    struct corto_rwmutex_s scopeLock;
    corto_int32 declared;
    corto__ols *ols;
}corto__scope;

typedef struct corto__writable {
    struct corto_rwmutex_s lock;
}corto__writable;

typedef struct corto__observer corto__observer;
typedef void (*corto__notifyCallback)(corto__observer* data, corto_object _this, corto_object observable, corto_uint32 mask);

struct corto__observer {
    corto_object _this;
    corto_observer observer;
    corto_eventMask mask;
    corto_object dispatcher;
    corto_int32 count;
};

typedef struct corto__observable corto__observable;
struct corto__observable {
    /* Protected by lock */
    corto_ll onSelf;
    corto_ll onChild;
    struct corto_rwmutex_s selfLock;
    struct corto_rwmutex_s childLock;

    /* Lockless access to observers (zero-terminated)
     *  Element -1 contains a counter which indicates by how many
     *  notify-functions it is being used. When this counter reaches zero, the array
     *  can be deleted. */
    corto__observer **onSelfArray;
    corto__observer **onChildArray;

    /* If this value is set to TRUE, updating the observable requires locking the object if it's a writable. This
     * value will only be set to TRUE when there are observers that subscribe on the object's value. */
    corto_bool lockRequired;

    /* Optimization: childs only need to look at this value to know if they need to lock instead of walking the
     * hierarchy checking for ON_CHILDS observables. */
    corto_bool childLockRequired;
};

typedef struct corto__persistent corto__persistent;
struct corto__persistent {
    corto_object owner;
};

/* Initialize static scoped object */
void corto__newSSO(corto_object sso);
void corto__freeSSO(corto_object sso);

/* Adopt static scoped object */
int corto__adoptSSO(corto_object sso);

/* Orphan object */
void corto__orphan(corto_object o);

/* Call destructor of object (if class) */
int corto__destructor(corto_object o);

/* Destruct object */
corto_uint16 corto__destruct(corto_object o);

/* Set state on object */
void corto__setState(corto_object o, corto_uint8 state);

/* Get & lock scope */
corto__scope *corto__scopeClaim(corto_object o);
void corto__scopeRelease(corto_object o);

/* Get scope tree */
corto_rbtree corto_scopeof(corto_object o);

#ifdef __cplusplus
}
#endif

#endif /* CORTO__OBJECT_H_ */
