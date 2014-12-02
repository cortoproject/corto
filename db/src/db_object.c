/*
 * db_object.c
 *
 *  Created on: Aug 3, 2012
 *      Author: sander
 */
#include "db__meta.h"
#include "db__object.h"
#include "db_memory_ser.h"
#include "db_mm.h"
#include "db_err.h"
#include "db_util.h"
#include "db_mem.h"
#include "db_string.h"
#include "db_serializer.h"
#include "db_type.h"
#include "db__class.h"
#include "db_string_deser.h"
#include "db_init_ser.h"
#include "db_copy_ser.h"
#include "db_procedure.h"
#include "db_call.h"
#include "db_string_ser.h"
#include "db_convert.h"
#include "db_interface.h"
#include "db_dispatcher.h"
#include "db_time.h"

static int db_adopt(db_object parent, db_object child);
static db_int32 db_notify(db__observable *_o, db_object observable, db_object _this, db_uint32 mask);

static void db_notifyObserverDefault(db__observer* data, db_object _this, db_object observable, db_object source, db_uint32 mask);
static void db_notifyObserverCdecl(db__observer* data, db_object _this, db_object observable, db_object source, db_uint32 mask);
static void db_notifyObserverThis(db__observer* data, db_object _this, db_object observable, db_object source, db_uint32 mask);
static void db_notifyObserverThisCdecl(db__observer* data, db_object _this, db_object observable, db_object source, db_uint32 mask);

/* Thread local storage key that keeps track of the objects that are prepared to wait for. */
extern db_threadKey DB_KEY_WAIT_ADMIN;

typedef struct db_waitForObject {
    db_object objects[DB_MAX_WAIT_FOR_OBJECTS];
    db_uint32 count;
    db_object triggered;
    db_sem semaphore;
    db_observer observer;
    int triggerCount; /* Value is atomically incremented\decremented to make sure wait is only triggered once */
}db_waitForObject;

/* Thread local storage key for administration that keeps track for which observables notifications take place.
 * 	This key points to an element in a list keyed by threadId's for which notifications have taken place. Value
 * 	of this element is the observable being notified at the moment. When a listen\silence call needs to clean
 * 	memory it can look at this administration to see if it is in use. To prevent deadlocks, listen\silence calls
 * 	will not look at their own threadId, since this would indicate listen\silence is called from an observer being
 * 	notified. This key is created in db_start. */
/* TODO: when a thread exits, the corresponding element must be free'd again - use tls destructor function */
extern db_threadKey DB_KEY_OBSERVER_ADMIN;

/* Lists all the anonymous objects in use. Used by the garbage collector. */
db_ll db_anonymousObjects = NULL;

typedef struct db_observerElement {
	db__observer ** observers;
	db_bool free;
}db_observerElement;

typedef struct db_observerAdmin {
	db_thread id;
	db_observerElement stack[DB_MAX_NOTIFY_DEPTH];
	db_uint32 sp;
}db_observerAdmin;
static db_observerAdmin observerAdmin[DB_MAX_THREADS];

/* Push observer-array to thread administration. Rather than passing the array pass the
 * address of the array so that setting the administration can be done atomic. */
db__observer** db_observersPush(db__observer**  *observers) {
	db__observer** result;
	db_observerAdmin *admin = db_threadTlsGet(DB_KEY_OBSERVER_ADMIN);
	if (!admin) {
		db_thread thr = db_threadSelf();
		db_uint32 i;
		do {
			i = 0;
			while(observerAdmin[i].id) { /* Find a free slot for thread in administration */
				i++;
				if (i >= DB_MAX_THREADS) {
					db_critical("maximum number of supported threads reached! (%d)", DB_MAX_THREADS);
				}
			}
		}while(!db_cas(&observerAdmin[i].id,0,thr));
		admin = &observerAdmin[i];
		db_threadTlsSet(DB_KEY_OBSERVER_ADMIN, admin);
	}
	result = admin->stack[admin->sp].observers = *observers;
	admin->stack[admin->sp++].free = FALSE;
	return result;
}

db_bool db_observersPop(void) {
	db_observerAdmin *admin = db_threadTlsGet(DB_KEY_OBSERVER_ADMIN); /* Admin must always exist when popping */
	return admin->stack[--admin->sp].free;
}

db_bool db_observersWaitForUnused(db__observer** observers) {
	db_thread self = db_threadSelf();
	db_uint32 i, j;
	db_bool inUse, freeArray = TRUE; /* Initialization merely to satisfy the compiler */

	if (!observers) {
		return FALSE;
	}

	/* Spinning loop which waits as long as an observer array is being used
	 * in a notification by any of the running threads. */
	do {
		inUse = FALSE;
		for(i=0; i<DB_MAX_THREADS; i++) {
			if (observerAdmin[i].id) {
				/* Check whether the observer array is in use by threads other than myself */
				if ((observerAdmin[i].id != self)) {
					for(j=0; j<observerAdmin[i].sp; j++) {
						if (observerAdmin[i].stack[j].observers == observers) {
							inUse = TRUE; /* Array is found, so keep waiting */
						}
						break;
					}
					
				/* Check whether the observer array is in use by my own thread */
				} else {
					freeArray = TRUE;
					for(j=0; j<observerAdmin[i].sp; j++) {
						/* The array is in use by my own thread so I can't keep spinning. Notify the observing function to 
						 * free the array */
						if (observerAdmin[i].stack[j].observers == observers) {
							observerAdmin[i].stack[j].free = TRUE; /* Signal the notification routine to free the array */
							freeArray = FALSE; /* Since the array is still in use by myself don't free array yet */
							break;
						}
					}
				}
			}
		}
	}while(inUse);

	return freeArray;
}

static db__scope* db__objectScope(db__object* o) {
    db__scope* result = NULL;

    if (o->attrs.scope) {
        result = DB_OFFSET(o, -sizeof(db__scope));
    }
    return result;
}

static db__writable* db__objectWritable(db__object* o) {
    db__writable* result = (void*)o;

    if (o->attrs.scope) {
        result = DB_OFFSET(result, -sizeof(db__scope));
    }
    if (o->attrs.write) {
        result = DB_OFFSET(result, -sizeof(db__writable));
    } else {
        result = NULL;
    }

    return result;
}

static db__observable* db__objectObservable(db__object* o) {
    db__observable* result = (void*)o;

    if (o->attrs.scope) {
    	result = DB_OFFSET(result, -sizeof(db__scope));
    }
	if (o->attrs.write) {
		result = DB_OFFSET(result, -sizeof(db__writable));
	}
	if (result && o->attrs.observable) {
		result = DB_OFFSET(result, -sizeof(db__observable));
	} else {
		result = NULL;
	}

    return result;
}

static void* db__objectStartAddr(db__object* o) {
    void* result;
    result = o;
    if (o->attrs.scope) {
        result = DB_OFFSET(result, -sizeof(db__scope));
    }
    if (o->attrs.write) {
        result = DB_OFFSET(result, -sizeof(db__writable));
    }

    if (o->attrs.observable) {
        result = DB_OFFSET(result, -sizeof(db__observable));
    }
    return result;
}

/* Initialze scope-part of object */
static db_int16 db__initScope(db_object o, db_string name, db_object parent) {
    db__object* _o;
    db__scope* scope;

    _o = DB_OFFSET(o, -sizeof(db__object));
    scope = db__objectScope(_o);
    db_assert(scope != NULL, "db__initScope: created scoped object, but db__objectScope returned NULL.");

    scope->name = db_strdup(name);
    scope->scopeLock = db_rwmutexNew();

    /* Add object to the scope of the parent-object */
    if (db_adopt(parent, o)) {
        goto error;
    }

    return 0;
error:
    return -1;
}

static void db__deinitScope(db_object o) {
    db__object *_o;
    db__scope* scope;

    /* Obtain own scope */
    _o = DB_OFFSET(o, -sizeof(db__object));
    scope = db__objectScope(_o);
    db_assert(scope != NULL, "db__deinitScope: called on non-scoped object <%p>.", o);
    db_assert(scope->attached == NULL, "db__deinitScope: object has still objects attached");

    /* Free parent */
    db_free_ext(o, scope->parent, "Free parent of object");
    scope->parent = NULL;

    /* We cannot actually remove the scope itself, since there might be childs which
     * have multiple cycles, which must be resolved first. The childs will take care
     * of removing the parent's scope. */

    if (scope->name) {
        db_dealloc(scope->name);
        scope->name = NULL;
    }

    /* Finally, free own scopeLock. */
    db_rwmutexFree(&scope->scopeLock);
}

/* Initialize writable-part of object */
static void db__initWritable(db_object o) {
    db__object* _o;
    db__writable* writable;

    _o = DB_OFFSET(o, -sizeof(db__object));
    writable = db__objectWritable(_o);
    db_assert(writable != NULL, "db__initWritable: created writable object, but db__objectWritable returned NULL.");

    writable->lock = db_rwmutexNew();
}

static void db__deinitWritable(db_object o) {
    db__object* _o;
    db__writable* writable;

    _o = DB_OFFSET(o, -sizeof(db__object));
    writable = db__objectWritable(_o);
    db_assert(writable != NULL, "db__deinitWritable: called on non-writable object <%p>.", o);

    db_rwmutexFree(&writable->lock);
}

/* Initialize observable-part of object */
static void db__initObservable(db_object o) {
    db__object* _o;
    db__observable *observable, *parentObservable;
    db_object parent;

    _o = DB_OFFSET(o, -sizeof(db__object));
    observable = db__objectObservable(_o);
    db_assert(observable != NULL, "db__initObservable: created observable object, but db__objectObservable returned NULL.");

    observable->selfLock = db_rwmutexNew();

    if (db_checkAttr(o, DB_ATTR_SCOPED)) {
        observable->childLock = db_rwmutexNew();
    }

    observable->onSelf = NULL;
    observable->onChild = NULL;
    observable->onSelfArray = NULL;
    observable->onChildArray = NULL;
    observable->used = FALSE;
    observable->parent = NULL;
    observable->lockRequired = FALSE;
    observable->childLockRequired = FALSE;

    parent = o;
    while((parent = db_parentof(parent))) {
        if ((parentObservable = db__objectObservable(DB_OFFSET(parent, -sizeof(db__object))))) {
            db_rwmutexRead(&parentObservable->childLock);

            /* Inherit childLockRequired from first observable parent */
            if (parentObservable->childLockRequired) {
                observable->lockRequired = TRUE;
            }

            if (!observable->parent) {
                if (parentObservable->onChild) {
                    observable->parent = parentObservable;
                } else {
                    observable->parent = parentObservable->parent;
                }
            }
            db_rwmutexUnlock(&parentObservable->childLock);

            if (observable->childLockRequired) {
                break;
            }
        }
    }

    /* Override lockRequired if object is not writable */
    if (!db_checkAttr(o, DB_ATTR_WRITABLE)) {
        observable->lockRequired = FALSE;
    }
}

static void db__deinitObservable(db_object o) {
    db__object* _o;
    db__observable* observable;

    _o = DB_OFFSET(o, -sizeof(db__object));
    observable = db__objectObservable(_o);
    db_assert(observable != NULL, "db__deinitObservable: called on non-observable object <%p>.", o);

    /* Delete observer objects in onSelf and onChild */
    if (observable->onSelf) {
        db__observer* observer;
        while((observer = db_llTakeFirst(observable->onSelf))) {
        	/* Clear template observer data */
        	if (observer->observer->template) {
        		db_object observerObj = observer->_this;
        		db_class_setObservable(db_class(db_typeof(observerObj)), observer->observer, observer->_this, NULL);
        	}
            if (!--observer->count) {
                db_dealloc(observer);
            }
        }
        db_llFree(observable->onSelf);
        observable->onSelf = NULL;
    }

    if (observable->onChild) {
        db__observer* observer;
        while((observer = db_llTakeFirst(observable->onChild))) {
        	/* Clear template observer data */
        	if (observer->observer->template) {
        		db_object observerObj = observer->_this;
        		db_class_setObservable(db_class(db_typeof(observerObj)), observer->observer, observer->_this, NULL);
        	}
            observer->count--;
             if (!observer->count) {
                db_dealloc(observer);
            }
        }
        db_llFree(observable->onChild);
        observable->onChild = NULL;
    }

    db_rwmutexFree(&observable->selfLock);
    db_rwmutexFree(&observable->childLock);
}

/* Initialize static scoped object */
void db__newSSO(db_object sso) {
    db__object* o;
    db__scope* scope;

    o = DB_OFFSET(sso, -sizeof(db__object));
    scope = db__objectScope(o);

    /* Don't call initScope because name is already set. */
    scope->scopeLock = db_rwmutexNew();
    if (scope->parent) {
    	db__adoptSSO(sso);
    }

    /* Init observable */
    if (db_checkAttr(sso, DB_ATTR_OBSERVABLE)) {
        db__initObservable(sso);
    }

    /* Keep type */
    db_keep_ext(sso, db_typeof(sso), "Keep type of object.");
}

/* Deinitialize static scoped object */
void db__freeSSO(db_object sso) {
    db__object* o;
    db__scope* scope;

    o = DB_OFFSET(sso, -sizeof(db__object));
    scope = db__objectScope(o);

    db_assert(scope != NULL, "db__freeSSO: static scoped object has no scope (very unlikely, db__freeSSO called on non-static object?)")

    if (scope->parent) {
        db_free(scope->parent);
    }

    if (scope->scope) {
        if (db_rbtreeSize(scope->scope)) {
            db_error("db__freeSSO: scope of object '%s' is not empty", db_nameof(sso));
        }
        db_rbtreeFree(scope->scope);
        scope->scope = NULL;
    }

    db_rwmutexFree(&scope->scopeLock);

    /* Deinitialize observable */
    if (db_checkAttr(sso, DB_ATTR_OBSERVABLE)) {
        db__deinitObservable(sso);
    }

    /* Free type */
    db_free_ext(sso, db_typeof(sso), "free type of builtin-object");
}

/* Adopt static scoped object */
int db__adoptSSO(db_object sso) {
    db__object* o;
    db__scope* scope;
    db_object parent;

    o = DB_OFFSET(sso, -sizeof(db__object));
    scope = db__objectScope(o);

    db_assert(scope != NULL, "db__adoptSSO: static scoped object has no scope (very unlikely, db__adoptSSO called on non-static object?)");

    parent = scope->parent;

    db_assert(parent != NULL, "db__adoptSSO: static scoped object has no parent");

    /* Reset the parent to NULL, since db_adopt will otherwise conclude that this object is adopted twice */
    scope->parent = NULL;

    return db_adopt(parent, sso);
}

/* Destruct object */
int db__destructor(db_object o) {
    db_type t;
    db__object* _o;

    t = db_typeof(o)->real;
    if (db_checkState(o, DB_DEFINED)) {
        _o = DB_OFFSET(o, -sizeof(db__object));
        if (db_class_instanceof(db_class_o, t)) {
            /* Detach observers from object */
            db_class_detachObservers(db_class(t), o);

            /* Call destructor */
            if(db_class_destruct_hasCallback(db_class(db_typeof(o)))) {
                db_class_destruct(db_class(db_typeof(o)), o);
            }
        } else if (db_class_instanceof(db_procedure_o, t)) {
            /* Call unbind */
            db_procedure_unbind(db_procedure(db_typeof(o)), o);
        }

        _o->attrs.state &= !DB_DEFINED;
    } else {
        db_id id, id2;
        db_error("%s::destruct: object '%s' is not defined", db_fullname(t, id2), db_fullname(o, id));
        goto error;
    }

    return 0;
error:
    return -1;
}

/* Set state on object */
void db__setState(db_object o, db_uint8 state) {
    db__object* _o;

    _o = DB_OFFSET(o, -sizeof(db__object));
    _o->attrs.state |= state;
}

static db_equalityKind db_objectCompare(db_type _this, const void* o1, const void* o2) {
    db_char *argList1, *argList2;
    int r;
    DB_UNUSED(_this);

    /* Added support for overloaded functions. When resolving overloaded functions and not specifying
     * an argumentlist in the lookup-expression, don't take it into account but just resolve the
     * name before the argumentlist. This can result in ambiguous lookups however, so
     * anyone doing the resolve must check afterwards if that is the only object that is matching.
     */
    if ((argList1 = strchr(o1, '('))) { /* Object has an argumentlist */
        if ((argList2 = strchr(o2, '('))) {
            /* This results in an exact compare of the names - default behavior */
        } else {
            db_id id;
            /* This results in comparing with the source(o1) from which the argumentlist
             * is stripped.
             */
            strncpy(id, o1, argList1 - (db_char*)o1);
            id[argList1 - (db_char*)o1] = '\0';

            return ((r = stricmp(id, o2)) < 0) ? DB_LT : (r > 0) ? DB_GT : DB_EQ;
        }
    }

    return ((r = stricmp(o1, o2)) < 0) ? DB_LT : (r > 0) ? DB_GT : DB_EQ;
}

/* Match a state exclusively:
 *                DB_DECLARED - DB_DECLARED | DB_DEFINED
 *  DB_DECLARED        X
 *  DB_DEFINED                       X
 *  DB_DECLARED |      X             X
 *     DB_DEFINED
 */
static db_bool db__checkStateXOR(db_object o, db_uint8 state) {
    db_uint8 ostate;
    db__object* _o;

    _o = DB_OFFSET(o, -sizeof(db__object));

    ostate = _o->attrs.state;
    if (ostate & DB_DEFINED) {
        ostate = DB_DEFINED;
    }

    return ostate & state;
}

/* Adopt an object */
static int db_adopt(db_object parent, db_object child) {
    db__object *_parent, *_child;
    db__scope *p_scope, *c_scope;
    db_typedef parentType;
    db_type childType;

    _parent = DB_OFFSET(parent, -sizeof(db__object));
    _child = DB_OFFSET(child, -sizeof(db__object));
    childType = db_typeof(child)->real;

    /* Parent must be a valid object */
    if (!db_checkState(parent, DB_VALID)) {
        db_error("cannot adopt, parentobject <%p> is invalid", parent);
        goto err_invalid_parent;
    }

    /* Check if parentType matches scopeType of child type */
    if (childType->parentType) {
        parentType = db_typeof(parent);
        if ((childType->parentType != parentType) && !db_class_instanceof((db_class)childType->parentType, parent)) {
            db_id parentId, parentTypeId, childTypeId, childParentTypeId;
            db_error("parent '%s' of type '%s' cannot adopt object '%s' of type '%s' (must be defined in '%s')",
                    db_fullname(parent, parentId), db_fullname(parentType, parentTypeId), db_nameof(child), db_fullname(childType, childTypeId), db_fullname(childType->parentType, childParentTypeId));
            goto err_invalid_parent;
        }
    }

    /* Check if parentState matches scopeState of child type */
    if (childType->parentState && !db__checkStateXOR(parent, childType->parentState)) {
        db_id parentId, childTypeId;
        db_string s_parentState, s_childState;
        db_uint32 parentState, childState;
        parentState = _parent->attrs.state;
        childState = childType->parentState;
        db_convert(db_primitive(db_state_o), &parentState, db_primitive(db_string_o), &s_parentState);
        db_convert(db_primitive(db_state_o), &childState, db_primitive(db_string_o), &s_childState);
        db_error("state %s of parent '%s' does not match %s, cannot adopt '%s' of type '%s'",
        		s_parentState, db_fullname(parent, parentId), s_childState, db_nameof(child), db_fullname(childType, childTypeId));

        if (s_parentState) {
        	db_dealloc(s_parentState);
        }
        if (s_childState) {
        	db_dealloc(s_childState);
        }

        goto err_invalid_parent;
    }

    /* Obtain pointers to scope of parent and child */
    p_scope = db__objectScope(_parent);
    if (p_scope) {
        c_scope = db__objectScope(_child);
        if (c_scope) {
            /* Set parent of child */
            if (db_rwmutexWrite(&c_scope->scopeLock)) goto err_child_mutex;
            if (c_scope->parent) {
                /* Cannot adopt an already adopted child */
                goto err_already_adopted;
            }
            c_scope->parent = parent;
            if (db_rwmutexUnlock(&c_scope->scopeLock)) goto err_child_mutex;

            /* Insert child in parent-scope */
            if (db_rwmutexWrite(&p_scope->scopeLock)) goto err_parent_mutex;
            if (!p_scope->scope) {
                p_scope->scope = db_rbtreeNew_w_func(db_objectCompare);
            }
            db_rbtreeSet(p_scope->scope, c_scope->name, child);

            /* Parent must not be deleted before all childs are gone. */
            db_keep_ext(child, parent, "keep parent of object.");
            if (db_rwmutexUnlock(&p_scope->scopeLock)) goto err_parent_mutex;
        } else {
            goto err_no_child_scope;
        }
    } else {
        goto err_no_parent_scope;
    }

    return 0;

err_child_mutex:
    db_error("db_adopt: lock operation on scopeLock of child failed");
    return -1;

err_parent_mutex:
    db_error("db_adopt: lock operation on scopeLock of parent failed");
    return -1;

err_already_adopted:
    db_rwmutexUnlock(&c_scope->scopeLock);
    db_error("db_adopt: child-object is already adopted");
    return -1;

err_no_parent_scope:
    db_critical("db_adopt: parent-object is not scoped");
    return -1;

err_no_child_scope:
    db_critical("db_adopt: child-object is not scoped");
    return -1;

err_invalid_parent:
    return -1;
}

void db_attach(db_object parent, db_object child) {
    db__object *_parent;
    db__scope *_scope;

    if (!db_checkAttr(parent, DB_ATTR_SCOPED)) {
    	db_critical("attach: cannot attach to non-scoped object");
    }
    if (db_checkAttr(child, DB_ATTR_SCOPED)) {
    	db_critical("attach: cannot attach scoped object");
    }

    _parent = DB_OFFSET(parent, -sizeof(db__object));
    _scope = db__objectScope(_parent);

    db_rwmutexWrite(&_scope->scopeLock);
    if (!_scope->attached) {
    	_scope->attached = db_llNew();
    }
    db_llAppend(_scope->attached, child);
    db_rwmutexUnlock(&_scope->scopeLock);
}

void db_detach(db_object parent, db_object child) {
    db__object *_parent;
    db__scope *_scope;

    if (!db_checkAttr(parent, DB_ATTR_SCOPED)) {
    	db_critical("attach: cannot attach to non-scoped object");
    }
    if (db_checkAttr(child, DB_ATTR_SCOPED)) {
    	db_critical("attach: cannot attach scoped object");
    }

    _parent = DB_OFFSET(parent, -sizeof(db__object));
    _scope = db__objectScope(_parent);

    db_rwmutexWrite(&_scope->scopeLock);
    db_llRemove(_scope->attached, child);
    db_rwmutexUnlock(&_scope->scopeLock);
}

/* Orphan object - not a public function as this will only happen during destruction of an object. */
void db__orphan(db_object o) {
    db__object *_parent, *_child;
    db__scope *p_scope, *c_scope;

    _child = DB_OFFSET(o, -sizeof(db__object));
    c_scope = db__objectScope(_child);

    if (c_scope->parent) {
        _parent = DB_OFFSET(c_scope->parent, -sizeof(db__object));
        p_scope = db__objectScope(_parent);

        /* Remove object from parent scope */
        if (db_rwmutexWrite(&p_scope->scopeLock)) goto err_parent_mutex;
        db_rbtreeRemove(p_scope->scope, (void*)db_nameof(o));

        /* If scope is empty delete it. */
        if (!db_rbtreeSize(p_scope->scope)) {
        	db_rbtreeFree(p_scope->scope);
        	p_scope->scope = NULL;
        }

        if (db_rwmutexUnlock(&p_scope->scopeLock)) goto err_parent_mutex;
    }

    return;
err_parent_mutex:
    db_error("db__orphan: lock operation of scopeLock of parent failed");
}

/* Create new object with attributes */
db_object db_new_ext(db_object src, db_typedef type, db_uint8 attrs, db_string context) {
    db_uint32 size, headerSize;
    db__object* o;
    
    DB_UNUSED(src);
    DB_UNUSED(context);

    headerSize = sizeof(db__object);

    /* Get size of type */
    size = db_type_allocSize(type->real);

    /* Calculate size of attributes */
    if (attrs & DB_ATTR_SCOPED) {
        headerSize += sizeof(db__scope);
    }
    if (attrs & DB_ATTR_WRITABLE) {
    	headerSize += sizeof(db__writable);
    }
    if (attrs & DB_ATTR_OBSERVABLE) {
    	headerSize += sizeof(db__observable);
    }

    size += headerSize;

    /* Allocate object */
    o = db_calloc(size);
    if (o) {

		/* Offset o so it points to object */
		o = DB_OFFSET(o, headerSize - sizeof(db__object));

        /* Give object initial refcount */
        o->refcount = 1;

		/* Set type */
		o->type = type;

		/* Set attributes */
		if (attrs & DB_ATTR_SCOPED) {
			o->attrs.scope = TRUE;
		}
		if (attrs & DB_ATTR_WRITABLE) {
			if (type->real->kind == DB_VOID) {
			    if (!type->real->reference) {
			        db_warning("db_new_ext: writable void object created.");
			    }
			}
			o->attrs.write = TRUE;
			db__initWritable(DB_OFFSET(o, sizeof(db__object)));
		}
		if (attrs & DB_ATTR_OBSERVABLE) {
			o->attrs.observable = TRUE;
		}

		/* Initially, an object is valid and declared */
		o->attrs.state = DB_VALID | DB_DECLARED;

		/* void objects, primitives and references are instantly defined because they have no value. */
		if ((type->real->kind == DB_VOID) || (type->real->kind == DB_PRIMITIVE)) {
			o->attrs.state |= DB_DEFINED;
		}

        /* If object is of a classType, set the number of delegates in callback-vtable */
        if (db_class_instanceof(db_class_o, type)) {
            if (db__class_delegateCount(db_class(type->real))) {
                *(db_uint32*)DB_OFFSET(o, sizeof(db__object) + type->real->size) = db__class_delegateCount(db_class(type->real));
            }
        }

        db_keep_ext(DB_OFFSET(o, sizeof(db__object)), type, "Keep type of object");

        if (!(attrs & DB_ATTR_SCOPED)) {
            /* Call framework initializer */
            db_init(DB_OFFSET(o, sizeof(db__object)));
            
            /* Call initializer */
            if (db_type_init_hasCallback(type->real) &&  
                db_type_init(type->real, DB_OFFSET(o, sizeof(db__object)))) {
                goto error;
            }
            /* Add object to anonymous cache */
            if (!db_anonymousObjects) {
            	db_anonymousObjects = db_llNew();
            }
            db_llInsert(db_anonymousObjects, DB_OFFSET(o, sizeof(db__object)));
        }
    }

    return DB_OFFSET(o, sizeof(db__object));
error:
    return NULL;
}

/* Create new object */
db_object db_new(db_typedef type) {
    int attr;

    if (type->real->kind == DB_VOID) {
    	attr = DB_ATTR_OBSERVABLE;
    } else {
    	attr = DB_ATTR_WRITABLE | DB_ATTR_OBSERVABLE;
    }

    return db_new_ext(NULL, type, attr, NULL);
}

/* Declare object */
db_object db_declare(db_object parent, db_string name, db_typedef type) {
    db_object o;
    db_uint8 state;

    if (!parent) {
    	parent = root_o;
    }

    /* Type must be valid and defined */
    if (!db_checkState(type, DB_VALID | DB_DEFINED)) {
        db_id pid, tid;
        db_error("db_declare: failed to declare object '%s' in scope '%s', type '%s' is not valid and/or defined", name, db_fullname(parent, pid), db_fullname(type, tid));
        goto error;
    }

    /* Pointer must be of type-class */
    if (!db_class_instanceof(db_typedef_o, type)) {
        db_id pid, tid;
        db_error("db_declare: failed to declare object '%s' in scope '%s': object '%s' is not- or does not refer a type", name, db_fullname(parent, pid), db_fullname(type, tid));
        goto error;
    }

    /* When the object is of a void-type, it should not be writable. */
    if (type->real->kind != DB_VOID) {
    	state = DB_ATTR_SCOPED | DB_ATTR_WRITABLE | DB_ATTR_OBSERVABLE;
    } else {
    	state = DB_ATTR_SCOPED | DB_ATTR_OBSERVABLE;
    }

    /* Check if object already exists */
    if ((o = db_lookup(parent, name))) {
        db_free(o);
        if (db_typeof(o) != type) {
            db_id tid, tid2, pid;
            if (parent != root_o) {
            	db_error("cannot declare '%s %s::%s', it is already declared as an object of a different type '%s'", db_fullname(type, tid), db_fullname(parent, pid), name, db_fullname(db_typeof(o), tid2));
            } else {
               	db_error("cannot declare '%s ::%s', it is already declared as an object of a different type '%s'", db_fullname(type, tid), name, db_fullname(db_typeof(o), tid2));
            }
            goto error;
        }
    } else {
        /* Create new object */
        o = db_new_ext(parent, type, state, "Declare object in scope");
        if (o) {
            /* Initialize object parameters. */
            if (!db__initScope(o, name, parent)) {
                if (state & DB_ATTR_WRITABLE) {
                    db__initWritable(o);
                }
                db__initObservable(o);
                
                /* Call framework initializer */
                db_init(o);

                /* Init object value */
                if (db_type_init_hasCallback(db_typeof(o)->real) && db_type_init(db_typeof(o)->real, o)) {
                    db_invalidate(o);
                    goto error;
                }
            } else {
                db_invalidate(o);
                goto error;
            }

            /* Notify parent of new object */
            db_notify(db__objectObservable(DB_OFFSET(parent,-sizeof(db__object))), parent, o, DB_ON_DECLARE);
        }
    }

    return o;
error:
    return NULL;
}

/* Define object */
db_int16 db_define(db_object o) {
    db_type t;
    db_int16 result;
    db__object *_o;

    result = 0;
    _o = DB_OFFSET(o, -sizeof(db__object));
    t = db_typeof(o)->real;

    /* Only define valid, undefined objects */
    if (db_checkState(o, DB_VALID | DB_DECLARED) && !db_checkState(o, DB_DEFINED)) {

        /* If object is instance of a class, call the constructor */
        if (db_class_instanceof(db_class_o, t)) {
        	/* Attach observers to object */
        	db_class_attachObservers(db_class(t), o);
            /* Call constructor */
            if(db_class_construct_hasCallback(db_class(t))) {
                result = db_class_construct(db_class(t), o);
            }
            /* Start listening with attached observers */
            db_class_listenObservers(db_class(t), o);
        } else if (db_class_instanceof(db_procedure_o, t)) {
            result = db_procedure_bind(db_procedure(t), o);
        }

        if (!result) {
            _o->attrs.state |= DB_DEFINED;

            /* Notify observers of defined object */
            db_notify(db__objectObservable(DB_OFFSET(o,-sizeof(db__object))), o, o, DB_ON_DEFINE);

        } else {
            /* Remove valid state */
            db_invalidate(o);
        }
    }

    return result;
}

/* Destruct object */
void db_destruct(db_object o) {
    db__object* _o;
    db__scope* scope;

    _o = DB_OFFSET(o, -sizeof(db__object));
    scope = db__objectScope(_o);

    if (db_ainc(&scope->orphaned) == 1) {
    	/* Orphan object */
    	db__orphan(o);
        db_free_ext(db_parentof(o), o, "destroy scope reference");
    }
}

/* Invalidate object by removing valid flag */
void db_invalidate(db_object o) {
    db__object* _o;
    _o = DB_OFFSET(o, -sizeof(db__object));
    _o->attrs.state &= !DB_VALID;
    /* Notify observers */
    db_notify(db__objectObservable(DB_OFFSET(o,-sizeof(db__object))), o, o, DB_ON_INVALIDATE);
}

/* Get type */
db_typedef db_typeof(db_object o) {
    db__object* _o = DB_OFFSET(o, -sizeof(db__object));
    return _o->type;
}

/* Get refcount */
db_int32 db_countof(db_object o) {
    db__object* _o;
    _o = DB_OFFSET(o, -sizeof(db__object));
    return _o->refcount;
}

/* Check for a state */
db_bool db_checkState(db_object o, db_int8 state) {
    db__object* _o;
    _o = DB_OFFSET(o, -sizeof(db__object));
    return (_o->attrs.state & state) == state;
}

/* Check for an attribute */
db_bool db_checkAttr(db_object o, db_int8 attr) {
    db_bool result;
    db__object* _o;

    _o = DB_OFFSET(o, -sizeof(db__object));
    result = TRUE;

    if (attr & DB_ATTR_SCOPED) {
        if (!_o->attrs.scope) result = FALSE;
    }
    if (attr & DB_ATTR_WRITABLE) {
        if (!_o->attrs.write) result = FALSE;
    }
    if (attr & DB_ATTR_OBSERVABLE) {
        if (!_o->attrs.observable) result = FALSE;
    }
    return result;
}

db_bool db_instanceof(db_typedef type, db_object o) {
	db_typedef objectType = db_typeof(o);
	db_bool result = TRUE;

	if (type->real != objectType->real) {
	    db_type t;

	    result = FALSE;
	    t = db_typeof(o)->real;

	    if (t->kind == type->real->kind) {
            switch(type->real->kind) {
            case DB_COMPOSITE: {
                db_interface p;
                p = (db_interface)t;

                while(p && !result) {
                    result = (p == (db_interface)type->real);
                    p = p->base;
                }
                break;
            }
            case DB_PRIMITIVE:
                switch(db_primitive(type->real)->kind) {
                case DB_ENUM:
                case DB_BITMASK:
                    if (db_parentof(o) == type) {
                        result = TRUE;
                    }
                    break;
                default:
                    break;
                }
                break;
            default:
                break;
            }
        }
	}

	return result;
}

/* Get parent (requires scoped object) */
db_object db_parentof(db_object o) {
    db__object* _o;
    db__scope* scope;
    db_object result;

    result = NULL;
    _o = DB_OFFSET(o, -sizeof(db__object));
    scope = db__objectScope(_o);
    if (scope) {
        result = scope->parent;
    } else {
        goto err_not_scoped;
    }

    return result;
err_not_scoped:
    db_critical("db_parentof: object %p is not scoped.", o);
    return NULL;
}

/* Get name (requires scoped object) */
db_string db_nameof(db_object o) {
    db__object* _o;
    db__scope* scope;
    db_string result;

    result = NULL;
    _o = DB_OFFSET(o, -sizeof(db__object));
    scope = db__objectScope(_o);
    if (scope) {
        result = scope->name;
    } else {
        goto err_not_scoped;
    }

    return result;
err_not_scoped:
    db_critical("db_nameof: object %p is not scoped.", o);
    return NULL;
}

/* Get scope (requires scoped object) */
db_rbtree db_scopeof(db_object o) {
	db__object* _o;
	db__scope* scope;
	db_rbtree result;

	result = NULL;

    _o = DB_OFFSET(o, -sizeof(db__object));
    scope = db__objectScope(_o);
    if (scope) {
        result = scope->scope;
    } else {
        goto err_not_scoped;
    }

    return result;
err_not_scoped:
	db_error("db_scopeof: object <%p> is not scoped", o);
	return NULL;
}

db_uint32 db_scopeSize(db_object o) {
    db__object* _o;
    db__scope* scope;
    db_rbtree tree;
    db_uint32 result;

    result = 0;

    _o = DB_OFFSET(o, -sizeof(db__object));
    scope = db__objectScope(_o);
    if (scope) {
        tree = scope->scope;
        if (tree) {
            result = db_rbtreeSize(tree);
        }
    } else {
        goto err_not_scoped;
    }

    return result;
err_not_scoped:
    db_error("db_scopeof: object <%p> is not scoped", o);
    return 0;
}

/* Walk objects in scope */
db_int32 db_scopeWalk(db_object o, db_scopeWalkAction action, void* userData) {
	db_int32 result;
    db__scope* scope;

    if (!o) {
    	o = root_o;
    }

    result = 1;
    scope = db__objectScope(DB_OFFSET(o, -sizeof(db__object)));
    if (scope) {
        if (scope->scope) {
            db_rwmutexRead(&scope->scopeLock);
            result = db_rbtreeWalk(scope->scope, (db_walkAction)action, userData);
            db_rwmutexUnlock(&scope->scopeLock);
        }
    }

    return result;
}

/* Obtain scoped identifier (serves as global unique identifier) */
db_string db_fullname(db_object o, db_id buffer) {
	db_object stack[DB_MAX_SCOPE_DEPTH];
	db_uint32 depth;
	db_string name;
	db_char* ptr;
	db_uint32 len;

	depth = 0;

	if (!o) {
	    *buffer = '\0';
	    return buffer;
	}

	if (!db_checkAttr(o, DB_ATTR_SCOPED)) {
		sprintf(buffer, "<%p>", o);
	} else {
		do {
			stack[depth++] = o;
		}while((o = db_parentof(o)));

		ptr = buffer;
		if (depth == 1) {
			*(db_uint16*)ptr = DB_SCOPE_HEX;
			ptr += 2;
		} else {
			while(depth) {
	            depth--;
				o = stack[depth];

				if ((name = db_nameof(o))) {
					/* Copy scope operator */
					*(db_uint16*)ptr = DB_SCOPE_HEX;
					ptr += 2;

					/* Copy name */
					len = strlen(name);
					memcpy(ptr, name, len + 1);
					ptr += len;
				}
			}
		}
		*ptr = '\0';
	}

	return buffer;
}

static db_object* db_scopeStack(db_object o, db_object scopeStack[], db_uint32 *length) {
	db_object ptr;
	db_uint32 i;

	ptr = o;
	i = 0;
	while(ptr) {
		scopeStack[i] = ptr;
		ptr = db_parentof(ptr);
		i++;
	}
	scopeStack[i] = NULL;
	if (length) {
		*length = i;
	}

	return scopeStack;
}

db_string db_relname(db_object from, db_object o, db_id buffer) {
	db_object from_s[DB_MAX_SCOPE_DEPTH];
	db_object o_s[DB_MAX_SCOPE_DEPTH];
	db_uint32 from_i, o_i;
	db_char* ptr;
	db_uint32 length;

	db_assert(from != NULL, "relname called with NULL for parameter 'from'.");
	db_assert(o != NULL, "relname called with NULL for parameter 'to'.");

	if (from == root_o) {
		db_fullname(o, buffer);
	} else {
		db_scopeStack(from, from_s, &from_i);
		db_scopeStack(o, o_s, &o_i);

		from_i--;
		o_i--;
		while(from_s[from_i] == o_s[o_i]) {
			from_i--;
			o_i--;
			if (!o_i || !from_i) {
				break;
			}
		}

		if (from_s[from_i] == o_s[o_i] && o_i) {
			o_i--;
		}

		ptr = buffer;
		while(o_i) {
			length = strlen(db_nameof(o_s[o_i]));
			memcpy(ptr, db_nameof(o_s[o_i]), length);
			ptr += length;
			*(db_uint16*)ptr = DB_SCOPE_HEX;
			ptr += 2;
			o_i--;
		}
		length = strlen(db_nameof(o_s[o_i]));
		memcpy(ptr, db_nameof(o_s[o_i]), length);
		ptr += length;
		*ptr = '\0';
	}
    return buffer;
}

/* Destruct object. */
db_uint16 db__destruct(db_object o) {
	db__object* _o;

	_o = DB_OFFSET(o, -sizeof(db__object));
	db_ainc(&_o->refcount);

	/* Only the following steps if the object is valid. */
	if (!db_checkState(o, DB_DESTRUCTED)) {
		db_vtable *ct, *ot;

		ct = db_class_getCallbackVtable(o);
		ot = db_class_getObserverVtable(o);

        /* Prevents from calling destructor nested */
        _o->mm.cycles = -1;

	    /* Only do the following steps if the object is defined */
	    if (db_checkState(o, DB_DEFINED)) {
	        /* From here, object is marked as destructed. */
	        _o->attrs.state |= DB_DESTRUCTED;

	        /* Integrity check */
            if (db_checkAttr(o, DB_ATTR_SCOPED)) {
                if (db_parentof(o) == hyve_lang_o) {
                    db_id id;
                    db_critical("illegal attempt to destruct builtin-object '%s'.", db_fullname(o, id));
                }
            }

            /* Notify destruct */
            db_notify(db__objectObservable(DB_OFFSET(o,-sizeof(db__object))), o, o, DB_ON_DESTRUCT);

            /* Call object-destructor */
            if (db__destructor(o)) {
                return -1;
            }
	    } else {
            /* Notify destruct */
            db_notify(db__objectObservable(DB_OFFSET(o,-sizeof(db__object))), o, o, DB_ON_DESTRUCT);
	    }

        db_deinit(o);

        /* If object is of a classType, free callbacks */
        if (ct && ct->buffer) {
        	db_uint32 i;
        	for(i=0; i<ct->length; i++) {
        		if (ct->buffer[i]) {
        			db_free_ext(o, ct->buffer[i], "Free callback.");
        		}
        	}
        	ct->buffer = NULL;
        	ct->length = 0;
        }

        /* Deinit observable */
        if (db_checkAttr(o, DB_ATTR_OBSERVABLE)) {
            db__deinitObservable(o);
        }

        /* Free type of object */
        db_free_ext(o, db_typeof(o), "Free type of object");

        /* Deinit writable */
        if (db_checkAttr(o, DB_ATTR_WRITABLE)) {
            db__deinitWritable(o);
        }

        /* Deinit scope */
        if (db_checkAttr(o, DB_ATTR_SCOPED)) {
            db__deinitScope(o);
        } else {
            /* Remove from anonymous cache */
            db_llRemove(db_anonymousObjects, o);
        }

        /* Reset template observable table */
        if (ot && ot->buffer) {
        	ot->buffer = NULL; /* Buffer is allocated as part of object - so no leakage */
        	ot->length = 0;
        }
	}

	/* Although after the destruct-operation it is ensured that this object no longer participates in any cycles, it cannot be assumed
	 * that all objects using this are free'd. For example, another object that has multiple reference cycles might still be
	 * referencing this object, but can itself not yet be free'd because of the other cycles, which cannot be solved by the destruction
	 * of this object. Therefore when the reference count of this object is non-zero, it cannot yet be free'd.
	 */

	db_adec(&_o->refcount);

	if (!db_countof(o)) {
	    db_dealloc(db__objectStartAddr(_o));
	    return 0;
	} else {
	    return db_countof(o);
	}
}

/* Name-based tracing */
/*#define DB_TRACE_DEBUG
#define DB_TRACE "48"*/
#ifdef DB_TRACE
#define DB_TRACE_KEEP(o)\
	{\
		db__object* _o;\
		_o = DB_OFFSET(o, -sizeof(db__object));\
		if (db__objectScope(_o)) {\
			if ((db_nameof(o) == DB_TRACE) || (DB_TRACE && (db_nameof(o) && !strcmp(db_nameof(o), DB_TRACE)))) {\
			    DB_TRACE_ADDR = o;\
				db_trace("keep (%p)'%s' -> %d (context = \"%s\")", o, db_nameof(o), _o->refcount, context);\
				if (src) {\
					db_id id;\
				    db_trace("    source: %s", db_fullname(src, id));\
                }\
                db_backtrace(stdout);\
			}\
		}\
	}
#define DB_TRACE_FREE(object)\
	{\
		db__object* _o;\
		_o = DB_OFFSET(o, -sizeof(db__object));\
		if (db__objectScope(_o)) {\
			if ((db_nameof(o) == DB_TRACE) || (DB_TRACE && (db_nameof(o) && !strcmp(db_nameof(o), DB_TRACE)))) {\
			    DB_TRACE_ADDR = o;\
				db_trace("free (%p)'%s' -> %d (context = \"%s\", cycles=%d)", o, db_nameof(o), _o->refcount, context, _o->mm.cycles);\
                if (src) {\
                	db_id id;\
                    db_trace("    source: %s", db_fullname(src, id));\
                }\
                db_backtrace(stdout);\
			}\
		}\
	}
#endif

/* Type-based tracing */
/* #define DB_TRACE_DEBUG
#define DB_TRACE_TYPE "Local"*/
#ifdef DB_TRACE_TYPE
#define DB_TRACE_KEEP(o)\
	{\
		db__object* _o;\
		_o = DB_OFFSET(o, -sizeof(db__object));\
        if ((db_nameof(db_typeof(o)) == DB_TRACE_TYPE) || (DB_TRACE_TYPE && (db_nameof(db_typeof(o)) && !strcmp(db_nameof(db_typeof(o)), DB_TRACE_TYPE)))) {\
            db_id id;\
            db_trace("keep (%p)'%s' -> %d (context = \"%s\")", o, db_fullname(o, id), db_countof(o), context);\
            if (src) {\
                db_id id;\
                db_trace("    source: %s", db_fullname(src, id));\
            }\
            db_backtrace(stdout);\
        }\
	}
#define DB_TRACE_FREE(object)\
	{\
		db__object* _o;\
		_o = DB_OFFSET(o, -sizeof(db__object));\
        if ((db_nameof(db_typeof(o)) == DB_TRACE_TYPE) || (DB_TRACE_TYPE && (db_nameof(db_typeof(o)) && !strcmp(db_nameof(db_typeof(o)), DB_TRACE_TYPE)))) {\
            db_id id;\
            db_trace("free (%p)'%s' -> %d (context = \"%s\", cycles=%d)", o, db_fullname(o, id), db_countof(o), context, _o->mm.cycles);\
            if (src) {\
                db_id id;\
                db_trace("    source: %s", db_fullname(src, id));\
            }\
            db_backtrace(stdout);\
        }\
	}
#endif

/* Parent based tracing */
/*#define DB_TRACE_DEBUG
#define DB_TRACE_TYPEPARENT "Fast"*/
#ifdef DB_TRACE_TYPEPARENT
#define DB_TRACE_KEEP(o)\
	{\
		db__object* _o;\
		_o = DB_OFFSET(db_typeof(o), -sizeof(db__object));\
		if (db__objectScope(_o)) {\
			if ((db_nameof(db_parentof(db_typeof(o))) == DB_TRACE_TYPEPARENT) || (DB_TRACE_TYPEPARENT && (db_nameof(db_parentof(db_typeof(o))) && !strcmp(db_nameof(db_parentof(db_typeof(o))), DB_TRACE_TYPEPARENT)))) {\
				db_id id;\
				db_trace("keep (%p)'%s' -> %d (context = \"%s\")", o, db_fullname(o, id), db_countof(o), context);\
				if (src) {\
					db_id id;\
				    db_trace("    source: %s", db_fullname(src, id));\
                }\
                /*db_backtrace(stdout);*/\
			}\
		}\
	}
#define DB_TRACE_FREE(object)\
	{\
		db__object* _o;\
		_o = DB_OFFSET(db_typeof(o), -sizeof(db__object));\
		if (db__objectScope(_o)) {\
			if ((db_nameof(db_parentof(db_typeof(o))) == DB_TRACE_TYPEPARENT) || (DB_TRACE_TYPEPARENT && (db_nameof(db_parentof(db_typeof(o))) && !strcmp(db_nameof(db_parentof(db_typeof(o))), DB_TRACE_TYPEPARENT)))) {\
				db_id id;\
				db_trace("free (%p)'%s' -> %d (context = \"%s\", cycles=%d)", o, db_fullname(o, id), db_countof(o), context, _o->mm.cycles);\
                if (src) {\
                	db_id id;\
                    db_trace("    source: %s", db_fullname(src, id));\
                }\
                /*db_backtrace(stdout);\*/\
			}\
		}\
	}
#endif


#ifndef DB_TRACE
#ifndef DB_TRACE_TYPE
#ifndef DB_TRACE_TYPEPARENT
#define DB_TRACE_KEEP(o)
#define DB_TRACE_FREE(o)
#endif
#endif
#endif

#ifdef DB_TRACE_DEBUG
db_object DB_TRACE_ADDR = NULL;
#endif
db_int32 db_keep_ext(db_object src, db_object o, db_string context) {
    db__object* _o;
    db_uint32 i;
	DB_UNUSED(src);
	DB_UNUSED(context);

	_o = DB_OFFSET(o, -sizeof(db__object));
	i = db_ainc(&_o->refcount);

#ifdef DB_TRACE_DEBUG
	if (DB_TRACE_ADDR == o) {
	    db_id id, id2;
	    db_trace("keep %s of type %s -> %d (cycles=%d, source=%p, context='%s')", db_fullname(o, id), db_fullname(db_typeof(o), id2), i, _o->mm.cycles, src, context);
	    /*db_backtrace(stdout);*/
	}

    DB_TRACE_KEEP(o);

	if (i == 0) {
		db_id id1, id2;
		db_critical("keep resulted in refcount of 0 for object '%s' of type '%s'",
				db_fullname(o, id1), db_fullname(db_typeof(o), id2));
	}
#endif

	return i;
}

db_int32 db_free_ext(db_object src, db_object o, db_string context) {
	db_int32 i;
	db__object* _o;
	DB_UNUSED(src);
	DB_UNUSED(context);

	_o = DB_OFFSET(o, -sizeof(db__object));
	i = db_adec(&_o->refcount);

#ifdef DB_TRACE_DEBUG
    if ((DB_TRACE_ADDR == o)) {
        db_id id, id2;
        db_trace("free (%p)%s of type %s -> %d (cycles=%d, valid=%d, destructed = %d, source=%p, context='%s')",
        		o, db_fullname(o, id), db_fullname(db_typeof(o), id2), i, _o->mm.cycles, db_checkState(o, DB_VALID), db_checkState(o, DB_DESTRUCTED), src, context);
        /*db_backtrace(stdout);*/
    }

	DB_TRACE_FREE(o);
#endif

	if (i == _o->mm.cycles) {
		db__destruct(o);

	/* If an invalid scoped object doesn't have a name, it must still be free'd - can occur when objects are
	 * dangling because of double cycles. */
	} else if (!i && db_checkState(o, DB_DESTRUCTED) && (_o->mm.cycles == 65535)) {
        db__destruct(o);
	}
	if (i < 0) {
		db_id id, typeId;
		db_critical("negative reference count of object (%p) '%s' of type '%s'", o, db_fullname(o, id), db_fullname(db_typeof(o), typeId));
		db_backtrace(stdout);
	}

	return i;
}

db_int32 db_keep(db_object o) {
	return db_keep_ext(NULL, o, NULL);
}

db_int32 db_free(db_object o) {
	return db_free_ext(NULL, o, NULL);
}

typedef struct db_dropWalk_t {
	db_ll objects;
}db_dropWalk_t;

/* Collect objects in scope, so they can be removed outside of scopeLock. */
static int db_dropWalk(void* o, void* userData) {
    db__object* _o;
    db__scope* scope;
	db_dropWalk_t* data;

	data = userData;

	/* Drops are recursive */
	_o = DB_OFFSET(o, -sizeof(db__object));
	scope = db__objectScope(_o);
	if (scope) {
		db_rwmutexRead(&scope->scopeLock);
		if (scope->scope) {
			db_rbtreeWalk(scope->scope, db_dropWalk, data);
		}
		if (scope->attached) {
			db_llWalk(scope->attached, db_dropWalk, data);
			db_llFree(scope->attached);
			scope->attached = NULL;
		}
		db_rwmutexUnlock(&scope->scopeLock);
	}

	/* Prevent object from being deleted when scopeLock is released, which
	 * would result in invalid reference in list. */
	db_keep_ext(NULL, o, "keep object in temporary drop-list");

	/* Insert object in list */
	if (!data->objects) {
	    data->objects = db_llNew();
	}
	db_llInsert(data->objects, o);

	return 1;
}

void db_drop(db_object o) {
	db__object* _o;
	db__scope* scope;
	db_dropWalk_t walkData;

	_o = DB_OFFSET(o, -sizeof(db__object));
	scope = db__objectScope(_o);
	if (scope) {
	    db_iter iter;
	    db_object collected;

		/* Because object refcounts can reach zero after a free, a
		 * walk in which objects are collected is needed first. During
		 * destruction of an object, this scopeLock is also required,
		 * which would result in deadlocks. */

		db_rwmutexRead(&scope->scopeLock);
		walkData.objects = NULL;
		if (scope->scope) {
			db_rbtreeWalk(scope->scope, db_dropWalk, &walkData);
		}
		if (scope->attached) {
			db_llWalk(scope->attached, db_dropWalk, &walkData);
			db_llFree(scope->attached);
			scope->attached = NULL;
		}
		db_rwmutexUnlock(&scope->scopeLock);

		/* Free objects outside scopeLock */
		if (walkData.objects) {
			iter = db_llIter(walkData.objects);
			while(db_iterHasNext(&iter)) {
				collected = db_iterNext(&iter);
				db_free_ext(NULL, collected, "free from temporary drop-list");
				/* Double free - because db_drop itself introduced a keep. */
				if (db_checkAttr(collected, DB_ATTR_SCOPED)) {
					db_destruct(collected);
				} else {
					db_free_ext(NULL, collected, "free attached object");
				}
			}
			db_llFree(walkData.objects);
		}
	} else {
		db_critical("db_drop: object <%p> is not scoped.", o);
	}
}

db_object db_lookup_ext(db_object src, db_object o, db_string name, db_string context) {
    db_object result;
    db__object *_o, *_result;
    db__scope* scope;
    db_rbtree tree;

    _o = DB_OFFSET(o, -sizeof(db__object));
    scope = db__objectScope(_o);

    if (scope) {
        db_rwmutexRead(&scope->scopeLock);
        if ((tree = scope->scope)) {
            if ((!db_rbtreeHasKey(tree, name, (void**)&result))) {
                result = NULL;
            } else {
                /* Keep object. If the refcount was zero, this object will be deleted soon, so prevent the object from being referenced again. */
                if (db_keep_ext(src, result, context) == 1) {
                     /* Set the refcount to zero again. There can be no more objects that are looking up this object right now because
                      * we have the scopeLock of the parent. Additionally, the object will not yet have been free'd because the destruct
                      * function also needs the parent's scopelock to remove the object from the scope.
                      *
                      * The refcount needs to be re-set to zero, because after the scopeLock is released, other threads - other than the destruct
                      * thread might try to acquire this object. Setting the refcount back to zero will enable these lookups to also detect
                      * that the object is being deleted.
                      */
                    _result = DB_OFFSET(result, -sizeof(db__object));
                    _result->refcount = 0;
                    result = NULL;
                }
            }
        } else {
            result = NULL;
        }
        db_rwmutexUnlock(&scope->scopeLock);
    } else {
        db_id id;
        db_error("db_lookup: object '%s' has no scope", db_fullname(o, id));
        goto error;
    }

    return result;
error:
    return NULL;
}

db_object db_lookup(db_object o, db_string name) {
    return db_lookup_ext(NULL, o, name, NULL);
}

/* Resolve anonymous object */
static db_char* db_resolveAnonymous(db_object src, db_object scope, db_object o, db_string str, db_object* out) {
    DB_UNUSED(src);
    db_object result;
    db_string_deser_t data;

    result = db_new_ext(NULL, db_typedef(o), (db_typedef(o)->real->kind == DB_VOID) ? DB_ATTR_WRITABLE : 0, "Create anonymous object");
    data.out = result;
    data.scope = scope;
    data.type = NULL;
    str = db_string_deser(str, &data);
    *out = result;

    db_define(result);

    return str;
}

/* Resolve address-identifier */
static db_object db_resolveAddress(db_string str) {
	db_word addr;

	addr = strtoul(str+1, NULL, 16);

	db_keep_ext(NULL, (db_object)addr, "Resolve by address");

	return (db_object)addr;
}

/* Resolve fully scoped name */
db_object db_resolve_ext(db_object src, db_object _scope, db_string str, db_bool allowCastableOverloading, db_string context) {
    db_object scope, _scope_start, o, lookup;
    const char* ptr;
    char* bptr;
    db_id buffer;
    db_char ch;
    db_bool overload;

    if (!*str) {
        return NULL;
    }

    if (*str == '<') {
    	return db_resolveAddress(str);
    }

    _scope_start = _scope;
    scope = _scope_start;

    /* If no scope is provided, start from root */
    if (!scope) {
        scope = root_o;
    }

    /* If expression starts with scope operator, start from root */
    if (*(db_uint16*)str == DB_SCOPE_HEX) {
        str += 2;
        scope = root_o;
    }

repeat:
    lookup = NULL;
    do {
        o = scope;

        ptr = str;
        ch = *ptr;
        if (!ch) {
            break;
        }
        while(ch) {
        	overload = FALSE;
            /* Parse name */
            bptr = buffer;
            while((ch = *ptr) && (ch != ':') && (ch != '{')) {
                *bptr = ch;
                bptr++;
                ptr++;
                if (ch == '(') { /* Scope operators & initializers in argumentlists are ignored. */
                	overload = TRUE;
                    while((ch = *ptr) && (ch != ')')) {
                        *bptr = ch;
                        bptr++;
                        ptr++;
                    }
                }
            }
            *bptr = '\0';

            /* Lookup object */
            if (db_scopeof(o)) {
            	if (!overload) {
					o = db_lookup_ext(src, o, buffer, context);
					if (lookup) {
						db_free_ext(src, lookup, "Free intermediate reference for resolve"); /* Free reference */
					}
					lookup = o;
					if (!o) {
						break;
					}
            	} else {
            		/* If argumentlist is provided, look for closest match */
            		o = db_lookupFunction_ext(src, o, buffer, allowCastableOverloading, NULL, context);
            		if (lookup) {
            			db_free_ext(src, lookup, "Free intermediate procedure-reference for resolve");
            		}
            		lookup = o;
            		if (!o) {
            			break;
            		}
            	}
            } else {
                o = NULL;
                if (lookup) {
                    db_free_ext(src, lookup, "Free intermediate reference (object not found) for resolve");
                    lookup = NULL;
                }
                break;
            }

            /* Expect scope or serializable string */
            if (ch) {
                if (ch == '{') {
                    db_object prev = o;
                    ptr = lookup = db_resolveAnonymous(src, _scope, o, (char*)ptr, &o);
                    if (!ptr) {
                        o = NULL;
                    }
                    db_free_ext(src, prev, "Free type of anonymous identifier");
                    break;
                } else
                if (*(db_uint16*)ptr == DB_SCOPE_HEX) {
                    ptr += 2;
                } else {
                    db_error("db_resolve: invalid ':' in expression '%s'", str);
                    o = NULL;
                    break;
                }
            }
        }
        if (o) break;
    }while((scope = db_parentof(scope)));

    /* Do implicit lookup in ::hyve::lang */
    if (!o && (_scope_start != hyve_lang_o)) {
        scope = hyve_lang_o;
        _scope_start = hyve_lang_o;
        goto repeat; /* Do this instead of a recursive call. Besides saving (a little bit of) performance,
        				this also preserves the original searchscope, which is needed in anonymous type lookups, which
        				uses the stringserializer. In a serialized string references to other objects may be relatively
        				scoped. For example: the string sequence{F} results in an anonymous sequence object with
        				elementType 'F', which is looked up in scope '_scope_start'. */
    }

    /* If the current object is not obtained by a lookup, it is not yet keeped. */
    if (!lookup && o) {
        db_keep_ext(src, o, context);
    }

    return o;
}

db_object db_resolve(db_object _scope, db_string str) {
    return db_resolve_ext(NULL, _scope, str, FALSE, NULL);
}

/* Event handling. */

static db__observer* db_observerFind(db_ll on, db_observer observer, db_object _this) {
	db__observer* result;
	db_iter iter;

	result = NULL;

	if (on) {
		iter = db_llIter(on);
		while(db_iterHasNext(&iter)) {
			result = db_iterNext(&iter);
			if ((result->observer == observer) && (result->_this == _this)) {
				break;
			} else {
				result = NULL;
			}
		}
	}

	return result;
}

/* Copyout observers */
static void db_observersCopyOut(db_ll list, db__observer** observers) {
    db_iter iter;
    db_uint32 i;

    iter = db_llIter(list);
    i = 0;
    while(db_iterHasNext(&iter)) {
        observers[i] = db_iterNext(&iter);
        observers[i]->count++;
        i++;
    }
    observers[i] = NULL;
}

/* Free observer-array */
static void db_observersFree(db__observer** observers) {
    db__observer* observer;
    while((observer = *observers)) {
        if (!db_adec(&observer->count)) {
            db_dealloc(observer);
        }
        ++observers;
    }
}

/* Create observer-array */
static db__observer** db_observersArrayNew(db_ll list) {
    db__observer** array;

    array = db_malloc((db_llSize(list) + 1 + 1) * sizeof(db__observer*));
    array[0] = (db__observer*)1;
    db_observersCopyOut(list, &array[1]);

    /* Observers start from the second element */
    return &array[1];
}

/* There is a small chance that a thread simultaneously with db_listen obtains a pointer
 * to an old observers-array, then gets scheduled out and this function in another thread
 * deletes that array. Although unlikely this scenario must be addressed. */
static void db_observersArrayFree(db__observer** array) {
    if (array) {
        db_observersFree(array);
        db_dealloc(&array[-1]);
    }
}

/* Walk childs recursively, set db__observable.parent field to this observable only
 * when the current value is equal to the observableData's parent. If observable.parent does
 * not point to the observableData's parent there is an observable with childObservers between
 * the child and the observableData's observer.
 * PRE: childlock of observableData must be locked. */
void db_setChildParentObservers(db_object observable, db__observable *observableData) {
    if (db_checkAttr(observable, DB_ATTR_SCOPED)) {
        db_iter childIter;
        db_object child;
        db__observable *childObservable;
        db_ll scope = db_scopeClaim(observable);

        childIter = db_llIter(scope);
        while(db_iterHasNext(&childIter)) {
            db_bool parentSet = FALSE;
            child = db_iterNext(&childIter);
            if ((childObservable = db__objectObservable(DB_OFFSET(child, -sizeof(db__object))))) {
                db_rwmutexWrite(&childObservable->childLock);
                if (childObservable->parent == observableData->parent) {
                    childObservable->parent = observableData;
                    parentSet = TRUE;
                }
                db_rwmutexUnlock(&childObservable->childLock);

                /* Process childs of child outside childLock to enhance concurrency of listen\sleep's. */
                if (parentSet) {
                    db_setChildParentObservers(child, observableData);
                }
            }
        }
        db_scopeRelease(scope);
    }
}

/* Walk childs recursively, set whether a lock is required when updating a
 * child object because a parent has an observer interested in childs that
 * requires locking. */
void db_setChildLockRequired(db_object observable) {
    if (db_checkAttr(observable, DB_ATTR_SCOPED)) {
        db_iter childIter;
        db_object child;
        db__observable *childObservable;
        db_ll scope = db_scopeClaim(observable);

        childIter = db_llIter(scope);
        while(db_iterHasNext(&childIter)) {
            child = db_iterNext(&childIter);
            if ((childObservable = db__objectObservable(DB_OFFSET(child, -sizeof(db__object))))) {
                db_rwmutexWrite(&childObservable->childLock);
                if (db_checkAttr(child,DB_ATTR_WRITABLE)) {
                    childObservable->lockRequired = TRUE;
                }
                db_setChildLockRequired(child);
                db_rwmutexUnlock(&childObservable->childLock);
            }
        }

        db_scopeRelease(scope);
    }
}

/*#define DB_TRACE_NOTIFICATIONS*/

#ifdef DB_TRACE_NOTIFICATIONS
static db_uint32 indent = 0;
#endif

/* Notify one observer */
static void db_notifyObserver(db__observer *data, db_object observable, db_object source, db_uint32 mask) {
    db_observer observer = data->observer;

    if (mask & observer->mask) {
#ifdef DB_TRACE_NOTIFICATIONS
{
    db_id id1, id2, id3;
    printf("%*s [notify] observable '%s' observer '%s' me '%s'\n",
            indent * 3, "",
            db_fullname(observable, id1),
            db_fullname(observer, id2),
            db_fullname(data->_this, id3));
}
indent++;
#endif
        if (!observer->dispatcher) {
            data->notify(data, data->_this, observable, source, mask);
        } else {
            if (!data->_this || (data->_this != source)) {
                db_observableEvent event;
                db_dispatcher dispatcher = observer->dispatcher;
                event = (db_observableEvent)db_dispatcher_getEvent(dispatcher, observer, data->_this, observable, source);

                /* Destruct events must always be send synchronous because otherwise the object's value might no longer
                 * be valid when it is received by the observer (object destruction will continue after notification). */
                if (mask & DB_ON_DESTRUCT) {
                    db_keep_ext(NULL, event, "Temporarily keep destruct event");
                    db_dispatcher_post(dispatcher, db_event(event));
                    while(!event->_parent.handled) {
                        db_sleep(0,10000000);
                    }
                    db_free_ext(NULL, event, "Free destruct event");
                } else {
                    db_dispatcher_post(dispatcher, db_event(event));
                }
            }
        }
#ifdef DB_TRACE_NOTIFICATIONS
        indent--;
#endif
    }
}

/* If an observer is subscribed to NEW events align it with existing objects so that
 * an observer doesn't need to do an object-walk over the observable manually to discover
 * all objects.
 */
typedef struct db_observerAlignData {
    db__observer *observer;
    db_object observable;
}db_observerAlignData;

int db_observerAlignScope(db_object o, void *userData) {
    db_observerAlignData *data;

    data = userData;
    db_notifyObserver(data->observer, data->observable, o, DB_ON_DECLARE);

    if (data->observer->observer->mask & DB_ON_SCOPE) {
    	return db_scopeWalk(o, db_observerAlignScope, userData);
    } else {
    	return 1;
    }
}

void db_observerAlign(db_object observable, db__observer *observer) {
    db_observerAlignData walkData;

    /* Do recursive walk over scope */
    walkData.observable = observable;
    walkData.observer = observer;

    db_scopeWalk(observable, db_observerAlignScope, &walkData);
}

#ifdef DB_TRACE_NOTIFICATIONS
static int indent=0;
#endif

/* Add observer to observable */
db_int32 db_listen(db_object observable, db_observer observer, db_object _this) {
	db__observer* _observerData;
	db__observable* _o;
	db_bool added;
	db__observer **oldSelfArray = NULL, **oldChildArray = NULL;

	if (db_checkAttr(observable, DB_ATTR_OBSERVABLE)) {
		_o = db__objectObservable(DB_OFFSET(observable, -sizeof(db__object)));

#ifdef DB_TRACE_NOTIFICATIONS
    	{
    		db_id id1, id2, id3;
    		printf("%*s [listen] observable '%s' observer '%s' me '%s'\n",
    				indent * 3, "",
    				db_fullname(observable, id1),
    				db_fullname(observer, id2),
    				db_fullname(_this, id3));
    	}
#endif

		/* Create observerData */
		_observerData = db_malloc(sizeof(db__observer));
		_observerData->observer = observer;
		_observerData->_this = _this;
		_observerData->count = 0;
		_observerData->enabled = TRUE;

		/* Resolve the kind of the observer. This reduces the number of
		 * conditions that need to be evaluated in the notifyObserver function. */
        if (db_function(observer)->kind == DB_PROCEDURE_CDECL) {
            if (_this) {
                _observerData->notify = db_notifyObserverThisCdecl;
            } else {
                _observerData->notify = db_notifyObserverCdecl;
            }
        } else {
            if (_this) {
                _observerData->notify = db_notifyObserverThis;
            } else {
                _observerData->notify = db_notifyObserverDefault;
            }
        }

		added = FALSE;

		/* If observer must trigger on updates of me, add it to onSelf list */
		if (observer->mask & DB_ON_SELF) {
			db_rwmutexWrite(&_o->selfLock);
			if (!db_observerFind(_o->onSelf, observer, _this)) {
				if (!_o->onSelf) {
					_o->onSelf = db_llNew();
				}
				db_llAppend(_o->onSelf, _observerData);
				_observerData->count++;
				added = TRUE;

				/* Build new observer array. This array can be accessed without locking and is
				 * faster than walking the linked list. */
				oldSelfArray = _o->onSelfArray;
				_o->onSelfArray = db_observersArrayNew(_o->onSelf);
			}
			if (observer->mask & DB_ON_VALUE) {
			    if (db_checkAttr(observable, DB_ATTR_WRITABLE)) {
			        _o->lockRequired = TRUE;
			    }
			}
			db_rwmutexUnlock(&_o->selfLock);
		}

		/* If observer must trigger on updates of childs, add it to onChilds list */
		if (observer->mask & DB_ON_SCOPE) {
			if (db_checkAttr(observable, DB_ATTR_SCOPED)) {
			    db_bool firstChildObserver = FALSE;
				db_rwmutexWrite(&_o->childLock);
				if (!db_observerFind(_o->onChild, observer, _this)) {
					if (!_o->onChild) {
						_o->onChild = db_llNew();
						firstChildObserver = TRUE;
					}
					db_llAppend(_o->onChild, _observerData);
					_observerData->count++;
					added = TRUE;

					/* Build new observer array. This array can be accessed without locking and is
					 * faster than walking a linked list. */
					oldChildArray = _o->onChildArray;
					_o->onChildArray = db_observersArrayNew(_o->onChild);
				}

                /* If this is the first observer that subscribes on child-events let childs
                 * of this observable recursively know that it has interest. This is an optimization
                 * so that child objects do not need to walk the entire hierarchy upwards when there
                 * is no interest (or not on every parent). */
                if (firstChildObserver) {
                    db_setChildParentObservers(observable, _o);
                }

                if (observer->mask & DB_ON_VALUE) {
                    if (!_o->childLockRequired) {
                        _o->childLockRequired = TRUE;
                        db_setChildLockRequired(observable);
                    }
                }
				db_rwmutexUnlock(&_o->childLock);

			} else {
				db_id id, id2;
				db_error("hyve::listen: cannot listen to childs of non-scoped observable '%s' (observer %s)",
						db_fullname(observable, id),
						db_fullname(observer, id2));
				goto error;
			}
		}

		if (!added) {
			db_dealloc(_observerData);
		} else {
		    /* If observer is subscribed to new events, align observer with existing */
		    if (observer->mask & DB_ON_DECLARE) {
		        db_observerAlign(observable, _observerData);
		    }
		}
	} else {
		db_id id;
		db_assert(0, "hyve::listen: object '%s' is not an observable", db_fullname(observable, id));
		goto error;
	}

	/* From this point onwards the old observer arrays are no longer accessible. However, since notifications can
	 * still be in progress these arrays can't be deleted yet. Therefore wait until the arrays are no longer being
	 * used. 
	 *
	 * The administration where this information is stored is not protected by locking so that notifying objects can
	 * remain lock-free. There is however a slight chance that a notification pushed the old array to the administration
	 * but that this change is not yet visible due to a number of issues w.r.t. concurrency. In this case the functions
	 * below will assume the array is unused, which is incorrect.
	 *
	 * To be absolutely sure that the observed administration is up to date a memory barrier is required here. A simple
	 * mutex will not do since this would encumber the notifications too much.
	 */
	 /*__atomic_thread_fence (__ATOMIC_SEQ_CST);*/

	if (db_observersWaitForUnused(oldSelfArray)) {
	    db_observersArrayFree(oldSelfArray);
	}
	if (db_observersWaitForUnused(oldChildArray)) {
	    db_observersArrayFree(oldChildArray);
	}

	return 0;
error:
	return -1;
}

/* Remove observer from observable - TODO update lockRequired and parentObserves. */
db_int32 db_silence(db_object observable, db_observer observer, db_object _this) {
	db__observer* observerData;
	db__observable* _o;
    db__observer **oldSelfArray = NULL, **oldChildArray = NULL;

    if (db_checkAttr(observable, DB_ATTR_OBSERVABLE)) {
        _o = db__objectObservable(DB_OFFSET(observable, -sizeof(db__object)));
        observerData = NULL;

        /* If observer triggered on updates of me, remove from onSelf list */
        if (observer->mask & DB_ON_SELF) {
            db_rwmutexWrite(&_o->selfLock);
            observerData = db_observerFind(_o->onSelf, observer, _this);
            if (observerData) {
                observerData->enabled = FALSE;
                db_llRemove(_o->onSelf, observerData);
                observerData->count--;

                /* Build new observer array */
                oldSelfArray = _o->onSelfArray;
                _o->onSelfArray = db_observersArrayNew(_o->onSelf);
#ifdef DB_TRACE_NOTIFICATIONS
            {
                db_id id1, id2, id3;
                printf("%*s [silence] observable '%s' observer '%s' me '%s'\n",
                        indent * 3, "",
                        db_fullname(observable, id1),
                        db_fullname(observer, id2),
                        db_fullname(_this, id3));
            }
#endif
            }
            db_rwmutexUnlock(&_o->selfLock);
        }

		/* If observer triggered on updates of childs, remove from onChilds list */
		if (observer->mask & DB_ON_SCOPE) {
			if (db_checkAttr(observable, DB_ATTR_SCOPED)) {
				db_rwmutexWrite(&_o->childLock);
				observerData = db_observerFind(_o->onChild, observer, _this);
				if (observerData) {
					db_llRemove(_o->onChild, observerData);
					observerData->count--;

	                /* Build new observer array */
	                oldChildArray = _o->onChildArray;
	                _o->onChildArray = db_observersArrayNew(_o->onChild);
				}
				db_rwmutexUnlock(&_o->childLock);
			} else {
				db_error(0, "hyve::listen: observer subscribed on childs of non-scoped object");
				goto error;
			}
		}
	} else {
		db_id id;
		db_error("object '%s' is not an observable", db_fullname(observable, id));
		goto error;
	}

    /* See comments in db_listen */
	/*__atomic_thread_fence (__ATOMIC_SEQ_CST);*/

    if (db_observersWaitForUnused(oldSelfArray)) {
        db_observersArrayFree(oldSelfArray);
    }
    if (db_observersWaitForUnused(oldChildArray)) {
        db_observersArrayFree(oldChildArray);
    }
    /*if (observerData) {
    	TODO: db_dealloc(observerData);
    }*/

	return 0;
error:
	return -1;
}

db_bool db_listening(db_object observable, db_observer observer, db_object _this) {
    db__observer* observerData;
    db__observable* _o;
    db_bool result = FALSE;

    _o = db__objectObservable(DB_OFFSET(observable, -sizeof(db__object)));
    observerData = NULL;

    /* If observer triggered on updates of me, remove from onSelf list */
    if (_o) {
		if (observer->mask & DB_ON_SELF) {
			db_rwmutexWrite(&_o->selfLock);
			observerData = db_observerFind(_o->onSelf, observer, _this);
			if (observerData) {
				result = TRUE;
			}
			db_rwmutexUnlock(&_o->selfLock);
		}

		if (!result) {
			if (db_checkAttr(observable, DB_ATTR_OBSERVABLE)) {
				if (observer->mask & DB_ON_SCOPE) {
					if (db_checkAttr(observable, DB_ATTR_SCOPED)) {
						db_rwmutexWrite(&_o->childLock);
						observerData = db_observerFind(_o->onChild, observer, _this);
						if (observerData) {
							result = TRUE;
						}
						db_rwmutexUnlock(&_o->childLock);
					}
				}
			} else {
				db_id id;
				db_error("object '%s' is not an observable", db_fullname(observable, id));
				goto error;
			}
		}
    }

    return result;
error:
    return FALSE;
}

static void db_notifyObserverDefault(db__observer* data, db_object _this, db_object observable, db_object source, db_uint32 mask) {
    db_function f = db_function(data->observer);
    DB_UNUSED(_this);
    DB_UNUSED(mask);
    db_call(f, NULL, observable, source);
}

static void db_notifyObserverCdecl(db__observer* data, db_object _this, db_object observable, db_object source, db_uint32 mask) {
    db_function f = db_function(data->observer);
    DB_UNUSED(_this);
    DB_UNUSED(mask);
    ((void(*)(db_object,db_object))f->implData)(observable, source);
}

static void db_notifyObserverThis(db__observer* data, db_object _this, db_object observable, db_object source, db_uint32 mask) {
    DB_UNUSED(mask);

    if (!_this || (_this != source)) {
        db_function f = db_function(data->observer);
        db_call(f, NULL, _this, observable, source);
    }
}
static void db_notifyObserverThisCdecl(db__observer* data, db_object _this, db_object observable, db_object source, db_uint32 mask) {
    DB_UNUSED(mask);
    if (!_this || (_this != source)) {
        db_function f = db_function(data->observer);
        ((void(*)(db_object,db_object,db_object))f->implData)(_this, observable, source);
    }
}

static void db_notifyObservers(db__observer** observers, db_object observable, db_object source, db_uint32 mask) {
    db__observer* data;
    db_uint32 i = 0;
    if (!observers) {
        return;
    }

    while((data = *observers)) {
    	i++;
    	if (data->enabled) {
    	    db_notifyObserver(data, observable, source, mask);
    	}
        observers++;
    }
}

static db_int32 db_notify(db__observable* _o, db_object observable, db_object _this, db_uint32 mask) {
	db__observable *_parent;
	db__observer **observers;

	/* Notify direct observers */
	if (_o) {
        /* Notify observers of observable */
		observers = db_observersPush(&_o->onSelfArray);
        db_notifyObservers(observers, observable, _this, mask);
        if (db_observersPop()) {
        	db_observersArrayFree(observers);
        }

        /* Bubble event up in hierarchy */
        _parent = _o;
        while((_parent = _parent->parent)) {
            /* Notify observers of parent */
        	observers = db_observersPush(&_parent->onChildArray);
            db_notifyObservers(observers, observable, _this, mask);
            if (db_observersPop()) {
            	db_observersArrayFree(observers);
            }
        }
	}

	return 0;
}

/* Update object */
db_int32 db_update(db_object observable) {
    db__observable *_o;
    db__writable* _wr;

    _o = db__objectObservable(DB_OFFSET(observable, -sizeof(db__object)));
    if (_o->lockRequired) {
        _wr = db__objectWritable(DB_OFFSET(observable, -sizeof(db__object)));
        db_rwmutexRead(&_wr->lock);
        if (db_notify(_o, observable, observable, DB_ON_UPDATE)) {
            goto error;
        }
        db_rwmutexUnlock(&_wr->lock);
    } else {
        if (db_notify(_o, observable, observable, DB_ON_UPDATE)) {
            goto error;
        }
    }

	return 0;
error:
	return -1;
}

/* Update object from source other than self */
db_int32 db_updateFrom(db_object observable, db_object _this) {
    db__observable *_o;
    db__writable* _wr;

    _o = db__objectObservable(DB_OFFSET(observable, -sizeof(db__object)));
    if (_o->lockRequired) {
        _wr = db__objectWritable(DB_OFFSET(observable, -sizeof(db__object)));
        db_rwmutexRead(&_wr->lock);
        if (db_notify(_o, observable, _this, DB_ON_UPDATE)) {
            goto error;
        }
        db_rwmutexUnlock(&_wr->lock);
    } else {
        if (db_notify(_o, observable, _this, DB_ON_UPDATE)) {
            goto error;
        }
    }

	return 0;
error:
	return -1;
}

db_int32 db_updateBegin(db_object observable) {
    db__observable *_o;
	db__writable* _wr;

	_o = db__objectObservable(DB_OFFSET(observable, -sizeof(db__object)));

	if (_o->lockRequired) {
        _wr = db__objectWritable(DB_OFFSET(observable, -sizeof(db__object)));
        if (_wr) {
            if (db_rwmutexWrite(&_wr->lock)) {
                db_id id;
                db_error("db_updateBegin: writelock on object '%s' failed", db_fullname(observable, id));
                goto error;
            }
        } else {
            db_id id;
            db_warning("calling updateBegin for non-writable object '%s' is useless.", db_fullname(observable, id));
        }
	}

	return 0;
error:
	return -1;
}

db_int32 db_updateTry(db_object observable) {
	db__writable* _wr;

    _wr = db__objectWritable(DB_OFFSET(observable, -sizeof(db__object)));
    if (_wr) {
        if (db_rwmutexTryWrite(&_wr->lock) == DB_LOCK_BUSY) {
            goto busy;
        }
    } else {
        db_id id;
        db_warning("calling updateTry for non-writable object '%s' is useless.", db_fullname(observable, id));
    }

	return 0;
busy:
	return DB_LOCK_BUSY;
}

db_int32 db_updateEnd(db_object observable) {
    db__writable* _wr;
    db__observable *_o;

    _o = db__objectObservable(DB_OFFSET(observable, -sizeof(db__object)));

    if (db_notify(_o, observable, observable, DB_ON_UPDATE)) {
        goto error;
    }

    if (_o->lockRequired) {
        _wr = db__objectWritable(DB_OFFSET(observable, -sizeof(db__object)));
        if (_wr) {
            db_rwmutexUnlock(&_wr->lock);
        }
    }

	return 0;
error:
	return -1;
}

db_int32 db_updateEndFrom(db_object observable, db_object _this) {
	if (db_checkAttr(observable, DB_ATTR_OBSERVABLE)) {
		db__writable* _wr;
	    db__observable *_o;

	    _o = db__objectObservable(DB_OFFSET(observable, -sizeof(db__object)));

		if (db_notify(_o, observable, _this, DB_ON_UPDATE)) {
			goto error;
		}

		if (_o->lockRequired) {
			_wr = db__objectWritable(DB_OFFSET(observable, -sizeof(db__object)));
			if (_wr) {
				db_rwmutexUnlock(&_wr->lock);
			}
		}
	} else {
		db_id id;
		db_error("object '%s' is not an observable", db_fullname(observable, id));
		goto error;
	}

	return 0;
error:
	return -1;
}

db_int32 db_updateCancel(db_object observable) {

	if (db_checkAttr(observable, DB_ATTR_OBSERVABLE)) {
		db__writable* _wr;

		_wr = db__objectWritable(DB_OFFSET(observable, -sizeof(db__object)));

		db_rwmutexUnlock(&_wr->lock);
	} else {
		db_id id;
		db_error("object '%s' is not an observable", db_fullname(observable, id));
		goto error;
	}

	return 0;
error:
	return -1;
}

static void db_waitObserver(db_object me, db_object observable, db_object source) {
    db_waitForObject *waitAdmin;
    DB_UNUSED(source);

    waitAdmin = (db_waitForObject*)me;

    if (db_ainc(&waitAdmin->triggerCount) == 1) {
        db_uint32 i;

        waitAdmin->triggered = observable;
        db_semPost(waitAdmin->semaphore);

        /* Silence this observer */
        for(i=0; i<waitAdmin->count; i++) {
            db_silence(waitAdmin->objects[i], waitAdmin->observer, me);
        }
    }
    db_adec(&waitAdmin->triggerCount);
}

static void __db_waitObserver(db_function f, void* result, void* args) {
    DB_UNUSED(f);
    DB_UNUSED(result);
    db_waitObserver(
        *(db_object*)args,
        *(db_object*)((intptr_t)args + sizeof(db_object)),
        *(db_object*)((intptr_t)args + sizeof(db_object) * 2));
}

db_int32 db_waitfor(db_object observable) {
    db_waitForObject *waitAdmin;

    /* Obtain waitadministration */
    waitAdmin = db_threadTlsGet(DB_KEY_WAIT_ADMIN);
    if (!waitAdmin) {
        db_observer observer;

        /* Create thread-specific waitadministration */
        waitAdmin = db_malloc(sizeof(db_waitForObject));
        memset(waitAdmin, 0, sizeof(db_waitForObject));
        waitAdmin->semaphore = db_semNew(0);

        /* Create observer */
        observer = db_new(db_typedef(db_observer_o));
        db_function(observer)->impl = (db_word)__db_waitObserver;
        db_function(observer)->implData = (db_word)db_waitObserver;
        db_function(observer)->kind = DB_PROCEDURE_CDECL;
        observer->mask = DB_ON_UPDATE;

        db_define(observer);
        waitAdmin->observer = observer;
        db_threadTlsSet(DB_KEY_WAIT_ADMIN, waitAdmin);
    }

    /* Add object to waitadministration */
    waitAdmin->objects[waitAdmin->count] = observable;
    waitAdmin->count++;

    return 0;
}

db_object db_wait(db_int32 timeout_sec, db_int32 timeout_nanosec) {
    db_waitForObject *waitAdmin;
    db_object result = NULL;
    DB_UNUSED(timeout_sec);
    DB_UNUSED(timeout_nanosec);

    /* Obtain waitadministration */
    waitAdmin = db_threadTlsGet(DB_KEY_WAIT_ADMIN);
    if (waitAdmin) {
        db_uint32 i;

        /* Setup observer for observables */
        for(i=0; i<waitAdmin->count; i++) {
            db_listen(waitAdmin->objects[i], waitAdmin->observer, (db_object)waitAdmin);
        }

        /* Do the wait */
        db_semWait(waitAdmin->semaphore);

        result = waitAdmin->triggered;
    } else {
        db_error("wait called without objects that are being waited for");
    }

    return result;
}

/* Thread-safe reading */
db_int32 db_readBegin(db_object object) {
	if (db_checkAttr(object, DB_ATTR_WRITABLE)) {
		db__writable* _o;

		_o = db__objectWritable(DB_OFFSET(object, -sizeof(db__object)));
		if (db_rwmutexRead(&_o->lock)) {
			goto error;
		}
	}

	return 0;
error:
	return -1;
}

db_int32 db_readEnd(db_object object) {
	if (db_checkAttr(object, DB_ATTR_WRITABLE)) {
		db__writable* _o;

		_o = db__objectWritable(DB_OFFSET(object, -sizeof(db__object)));
		if (db_rwmutexUnlock(&_o->lock)) {
			goto error;
		}
	}

	return 0;
error:
	return -1;
}

/* Obtain function name from signature */
db_int32 db_signatureName(db_string signature, db_id buffer) {
    db_char ch, *srcptr, *bptr;

    /* Obtain name from function (without argumentlist) */
    srcptr = signature; bptr = buffer;
    while((ch = *srcptr) && (ch != '(')) {
        *bptr = ch;
        bptr++;
        srcptr++;
    }
    *bptr = '\0';

    return 0;
}

/* Count number of parameters */
db_int32 db_signatureParamCount(db_string signature) {
    db_char *ptr, ch;
    db_uint32 count;

    count = 0;

    /* Look for start of argumentlist */
    ptr = strchr(signature, '(');
    if (!ptr) {
        goto error;
    }

    /* Check if there are zero arguments */
    ptr++;
    if (*ptr != ')') {
        count = 1;
        /* Count arguments */
        while((ch = *ptr)) {
            if (ch == ',') {
                count++;
            }
            ptr++;

            if (ch == '{') {
                db_uint32 nesting = 1;
                while((ch = *ptr) && nesting) {
                   ptr++;
                   switch(ch) {
                   case '{':
                       nesting++;
                       break;
                   case '}':
                       nesting--;
                       break;
                   }
               }
            }
        }
    }

    return count;
error:
    return -1;
}

/* Obtain function parameter types from signature */
db_int32 db_signatureParamType(db_string signature, db_uint32 id, db_id buffer, db_bool* reference) {
    db_char ch, *srcptr, *bptr;
    db_uint32 i;
    db_bool parsed;

    if (reference) {
        *reference = FALSE;
    }

    srcptr = strchr(signature, '(');
    if (!srcptr) {
        db_error("missing argmentlist in signature '%s'", signature);
        goto error;
    }
    srcptr++;

    /* Find parameter-entry, copy to buffer */
    bptr = buffer;
    i = 0;
    parsed = FALSE;
    while((ch = *srcptr) && !parsed) {

        /* Start parsing when argument is reached. */
        if (i == id) {
            if ((ch == ',') || (ch == ' ') || (ch == ')') || (ch == '&')) {
                parsed = TRUE;
            } else {
                *bptr = ch;
                bptr++;
            }
        }

        if (!parsed) {
            if (ch == ',') {
                i++;
            }

            srcptr++;
            if (ch == '{') {
                db_uint32 count=1;
                while((ch = *srcptr) && count) {
                    if (i == id) {
                        *bptr = ch;
                        bptr++;
                    }
                    srcptr++;
                    switch(ch) {
                    case '{':
                        count++;
                        break;
                    case '}':
                        count--;
                        break;
                    }
                }
            }
        }
    }
    *bptr = '\0';

    if ((ch == '&') && reference) {
        *reference = TRUE;
    }

    return 0;
error:
    return -1;
}

/* Obtain function parameter names from signature */
db_int32 db_signatureParamName(db_string signature, db_uint32 id, db_id buffer) {
    db_char ch, *srcptr, *bptr;
    db_uint32 i;
    db_bool parsed;

    srcptr = strchr(signature, '(');
    if (!srcptr) {
        db_error("missing argmentlist in signature '%s'", signature);
        goto error;
    }
    srcptr++;

    /* Find parameter-entry, copy name to buffer */
    bptr = buffer;
    i = 0;
    parsed = FALSE;
    while((ch = *srcptr) && !parsed) {
        if (i == id) {
            switch(ch) {
            case '&':
                srcptr++;
                /* no break */
            case ' ':
                srcptr++;
                /* Location of parameter-name found, copy to buffer */
                while((ch = *srcptr) && (ch != ',') && (ch != ')')) {
                    *bptr = ch;
                    bptr++;
                    srcptr++;
                }
                parsed = TRUE;
                break;
            case ')':
            case ',':
                db_error("missing name of parameter %d in signature '%s'", id, buffer);
                break;
            default:
                break;
            }
        }

        if (!parsed) {
            if (ch == ',') {
                i++;
            }

            srcptr++;
            if (ch == '{') {
                db_uint32 count=1;
                while((ch = *srcptr) && count) {
                    srcptr++;
                    switch(ch) {
                    case '{':
                        count++;
                        break;
                    case '}':
                        count--;
                        break;
                    }
                }
            }
        }
    }
    *bptr = '\0';

    return 0;
error:
    return -1;
}

/* Check if argumentlist-expr matches function.
 *   The offered string (the name of the object) looks like:
 *      name(type1 arg1,type2 arg2,...)
 *   The requested string looks like:
 *      name(type1,type2,...)
 *
 *   No extra whitespaces are allowed in both. Type-names are relative
 *   to the scope of the function-object.
 */
db_int16 db_overload(db_function object, db_string name, db_int32* distance, db_bool allowCastable) {
    db_id offName, reqName;
    db_int32 offCount, reqCount;
    int d;

    d = 0;

    /* Obtain name from function (strip argumentlist) */
    if (db_signatureName(db_nameof(object), offName)) {
        goto nomatch;
    }

    /* Obtain name from requested signature */
    if (db_signatureName(name, reqName)) {
        goto nomatch;
    }

    /* Two function-names must be equal, otherwise requested name doesn't match */
    if (strcmp(offName, reqName)) {
        goto nomatch;
    }

    /* Compare number of arguments */
    offCount = db_signatureParamCount(db_nameof(object));
    if (offCount == -1) {
        db_error("functionname '%s' is missing argumentlist", db_nameof(object));
        goto nomatch; /* Error */
    }

    reqCount = db_signatureParamCount(name); /* reqCount is allowed to be -1, because the requested string may be omitting arguments */
    if (reqCount != -1) {
        if (offCount != reqCount) {
            goto nomatch;
        }
    } else {
        /* Ambiguous references are allowed but potentially dangerous. */
    }

    /* Compare argumentlists */
    if (offCount == reqCount) {
        db_int32 i;
        db_bool defined = TRUE;

        i = 0;

        /* Variables offptr and reqptr now points to the first type of the argumentlist. Now loop through
         * the arguments, and verify one-by-one that they match. */
        for(i=0; i<reqCount; i++){
            db_id offTypeBuff, reqTypeBuff;
            db_bool referenceRequested, referenceOffered;

            /* Get name of offered type */
            if (db_signatureParamType(db_nameof(object), i, offTypeBuff, &referenceOffered)) {
                goto nomatch; /* Error in argumentlist */
            }

            /* Get name of requested type */
            if (db_signatureParamType(name, i, reqTypeBuff, &referenceRequested)) {
                goto nomatch; /* Error in argumentlist */
            }

            /* If requested and offered are equal, there is a direct match - do not increase distance. */
            if (!strcmp(reqTypeBuff, offTypeBuff)) {
                continue;
            } else {
                db_object offered=NULL, requested=NULL; /* Pointers to requested vs. offered types */
                db_bool requestedIsNull=FALSE;

                 /* If types are not equal, resolve types and check if they are compatible(!) - so not castable! */
                offered = db_resolve_ext(NULL, db_parentof(object), offTypeBuff, FALSE, "Resolve offered type for overload-check");
                if (!offered) {
                    db_error("type '%s' of parameter %d in parameterlist of function '%s' not found", offTypeBuff, i, db_nameof(object));
                    if (requested) {
                        db_free_ext(NULL, requested, "Free requested type (error occurred).");
                    }
                    goto error;
                }
                
                /* Validate offered is a type */
                if (!db_class_instanceof(db_typedef_o, offered)) {
                    db_id id;
                    db_error("offered object '%s' is not a type", db_fullname(offered, id));
                    goto error;
                }
                
                /* Determine whether offered is defined */
                if (!db_checkState(offered, DB_DEFINED)) {
                    defined = FALSE;
                }

                /* If requested is 'null', type can either match a string or a reference */
                if (!strcmp(reqTypeBuff, "null")) {
                    requestedIsNull = TRUE;
                } else if (!strcmp(reqTypeBuff, "?")) {
                    db_free_ext(NULL, offered, "wildcard encountered in request");
                    continue; /* If the request type is a wildcard don't perform additional checks */
                } else {
                    requested = db_resolve_ext(NULL, db_parentof(object), reqTypeBuff, FALSE, "Resolve requested type for overload-check");
                    if (!requested) {
                        db_error("type '%s' of parameter %d in request '%s' not found", reqTypeBuff, i, name);
                        if (offered) {
                            db_free_ext(NULL, offered, "Free offered type (error occurred).");
                        }
                        goto error;
                    }
                    
                    /* Check whether requested is a type */
                    if (!db_class_instanceof(db_typedef_o, requested)) {
                        db_id id;
                        db_error("requested object '%s' is not a type", db_fullname(requested, id));
                        goto error;
                    }
                    
                    /* Determine whether requested is defined */
                    if (!db_checkState(requested,DB_DEFINED)) {
                        defined = FALSE;
                    }
                }

                /* If one or both types are not defined they must match exactly */
                if (!defined && (offered != requested)) {
                	goto nomatch;
                }

                /* If requested is 'null', check whether offered is either an any, reference or a string */
                if (requestedIsNull) {
                    if (!(db_typedef(offered)->real->reference || referenceOffered)) {
                        if ((db_typedef(offered)->real->kind != DB_PRIMITIVE) || (db_primitive(db_typedef(offered)->real)->kind != DB_TEXT)) {
                            if (db_typedef(offered)->real->kind != DB_ANY) {
                                goto nomatch;
                            }
                        }
                    }
                } else if (db_type_compatible(db_typedef(offered)->real, db_typedef(requested)->real)) {
                    /* If types are extendable, determine distance */
                    if (db_class_instanceof(db_interface_o, offered)) {
                    	db_interface base;
                    	base = db_interface(requested);
                    	while(base && (base != offered)) {
                    		d++; /* Increase distance */
                    		base = base->base;
                    	}
                    } else {
                    	/* If not extendable, do not increase distance when types are equal, else increase distance by one */
                    	if (db_typedef(offered)->real != db_typedef(requested)->real) {
                    		/* If types are of the same primitive kind, don't increase distance */
                    		if (db_typedef(offered)->real->kind != DB_PRIMITIVE) {
                    			d++;
                    		} else {
                    			if (db_primitive(offered)->kind != db_primitive(requested)->kind) {
                    				d++;
                    			}
                    		}
                    	}
                    }
                } else {
                    if (allowCastable && db_type_castable(db_typedef(offered)->real, db_typedef(requested)->real)) {
                        /* Increase distance by one. This algorithm could have been made more complex to automatically select
                         * the closest matching function w.r.t. downcasting but for the sake of understandability this
                         * algorithm is kept simple. When ambiguity occurs because of this, an explicit cast is required. */
                        d++;
                    } else {
                    	/* If offered type accepts any kind of reference and requested is a reference value (regardless
                    	 * of whether it's a reference type) increase distance by one. */
                    	if (((db_typedef(offered)->real->kind == DB_VOID) &&
                    		 db_typedef(offered)->real->reference) &&
                    		 referenceRequested) {
                    		d++;
                    	} else {
							/* If types are not compatible and casting is not allowed, offered does not meet requested. */
							db_free_ext(NULL, offered, "Free offered-type.");
							db_free_ext(NULL, requested, "Free requested type.");
							goto nomatch;
                    	}
                    }
                }

                db_free_ext(NULL, offered, "Free offered type.");
                if (requested) {
                    db_free_ext(NULL, requested, "Free requested type.");
                }
            }
        }
    }

    /* Assign distance (allows a user to pick the closest match). */
    if (distance) {
        *distance = d;
    }

/*match:*/
    return 0;
nomatch:
    *distance = -1;
    return 0;
error:
	return -1;
}

typedef struct db_lookupFunction_t {
	db_string request;
	db_function result;
	db_bool error;
	db_bool castableOverloading;
	db_int32 d;
}db_lookupFunction_t;

/* Lookup function in scope */
int db_lookupFunctionWalk(db_object o, void* userData) {
	db_int32 d;
	db_lookupFunction_t* data;

	data = userData;

	/* If current object is a function, match it */
	if (db_class_instanceof(db_procedure_o, db_typeof(o))) {
		if (db_overload(o, data->request, &d, data->castableOverloading)) {
			data->error = TRUE;
			goto found;
		}

		if (d != -1) {
			if (d < data->d) {
				data->result = o;
				data->d = d;
			}

			/* If distance is zero, the function is an exact match. */
			if (!d) {
				goto found;
			}
		}
	}

	return 1;
found:
	return 0;
}

static int db_scopeCollectWalk(db_object o, void* userData) {
	db_ll list = userData;
	db_keep_ext(NULL, o, "Collect objects in scope");
	db_llAppend(list, o);
	return 1;
}

static int db_scopeFreeWalk(db_object o, void* userData) {
	DB_UNUSED(userData);
	db_free_ext(NULL, o, "Free collected objects in scope");
	return 1;
}

db_ll db_scopeClaim(db_object scope) {
	db_ll result;
	result = db_llNew();
	db_scopeWalk(scope, db_scopeCollectWalk, result);
	return result;
}

void db_scopeRelease(db_ll scope) {
	db_llWalk(scope, db_scopeFreeWalk, NULL);
	db_llFree(scope);
}

/* Lookup function with support for overloading */
db_function db_lookupFunction_ext(db_object src, db_object scope, db_string requested, db_bool allowCastableOverloading, db_int32* d, db_string context) {
	db_lookupFunction_t walkData;
	db_ll scopeContents;

	/* Collect objects in scope first, to prevent reversed locking order (locking should
	 * always be outer scope first, then inner scope) and deadlocking i.c.m. db_resolve.
	 */
	scopeContents = db_scopeClaim(scope);

	/* Call the actual lookup function */
	walkData.request = requested;
	walkData.result = NULL;
	walkData.error = FALSE;
	walkData.castableOverloading = allowCastableOverloading;
	walkData.d = 0x7FFFFFFF;
	db_llWalk(scopeContents, db_lookupFunctionWalk, &walkData);

	if (walkData.error) {
		return NULL;
	}

	if (d) {
		*d = walkData.d;
	}

	if (walkData.result) {
		db_keep_ext(src, walkData.result, context);
	}

	/* Free contents of scope */
	db_scopeRelease(scopeContents);

	return walkData.result;
}

db_function db_lookupFunction(db_object scope, db_string requested, db_bool allowCastableOverloading, db_int32* d) {
    return db_lookupFunction_ext(NULL, scope, requested, allowCastableOverloading, d, NULL);
}

/* Create request signature */
db_string db_signatureOpen(db_string name) {
	db_string result;

	result = db_malloc(strlen(name) + 1 + 1);
	sprintf(result, "%s(", name);

	return result;
}

db_string db_signatureAdd(db_string sig, db_typedef type, db_bool isReference) {
	db_uint32 len;
	db_string result;
	db_id id;
    
    if (type) {
        db_fullname(type, id);
    } else {
        strcpy(id, "null");
    }
    
	len = strlen(sig);
	if (sig[len-1] == '(') {
		result = db_realloc(sig, len + strlen(id) + 1 + (isReference ? 1 : 0));
		strcat(result, id);
		if (isReference) strcat(result, "&");
	} else {
		result = db_realloc(sig, len + strlen(id) + 1 + 1 + (isReference ? 1 : 0));
		strcat(result, ",");
		strcat(result, id);
		if (isReference) strcat(result, "&");
	}

	return result;
}

db_string db_signatureAddWildcard(db_string sig, db_bool isReference) {
    db_uint32 len;
    db_string result;
    
    len = strlen(sig);
    if (sig[len-1] == '(') {
        result = db_realloc(sig, len + 1 + 1 + (isReference ? 1 : 0));
        strcat(result, "?");
        if (isReference) strcat(result, "&");
    } else {
        result = db_realloc(sig, len + 1 + 1 + 1 + (isReference ? 1 : 0));
        strcat(result, ",");
        strcat(result, "?");
        if (isReference) strcat(result, "&");
    }

    return result;
}

db_string db_signatureClose(db_string sig) {
    db_uint32 length = strlen(sig) + 1;
	sig = db_realloc(sig, length + 1);
	sig[length-1] = ')';
	sig[length] = '\0';
	return sig;
}

/* Set reference field */
void db_set_ext(db_object source, void* ptr, db_object value, db_string context) {
    db_object old;
    old = *(db_object*)ptr;
    if (value) {
    	db_keep_ext(source, value, context);
    }
    *(db_object*)ptr = value;
    if (old) {
        db_free_ext(source, old, context);
    }
}

/* Set reference field */
void db_set(void* ptr, db_object value) {
	db_set_ext(NULL, ptr, value, NULL);
}

/* Convert object to string */
db_string db_toString(db_object object, db_uint32 maxLength) {
	db_string_ser_t serData;
	struct db_serializer_s s;
	serData.buffer = NULL;
	serData.length = 0;
	serData.maxlength = maxLength;
	serData.compactNotation = TRUE;
	serData.prefixType = FALSE;

	s = db_string_ser(DB_LOCAL, DB_NOT, DB_SERIALIZER_TRACE_NEVER);
	db_serialize(&s, object, &serData);

	return serData.buffer;
}

/* Convert value to string */
db_string db_valueToString(db_value* v, db_uint32 maxLength) {
	db_string_ser_t serData;
	struct db_serializer_s s;
	serData.buffer = NULL;
	serData.length = 0;
	serData.maxlength = maxLength;
	serData.compactNotation = TRUE;
	serData.prefixType = FALSE;

	s = db_string_ser(DB_LOCAL, DB_NOT, DB_SERIALIZER_TRACE_NEVER);
	db_serializeValue(&s, v, &serData);

	return serData.buffer;
}

/* Deserialize object from string */
db_object db_fromString(db_string string) {
    db_string_deser_t serData;

    serData.out = NULL;
    serData.scope = NULL;
    serData.type = NULL;
    if (!db_string_deser(string, &serData)) {
        db_assert(!serData.out, "deserializer failed but out is set");
    }

    return serData.out;
}

/* Deserialize object from string */
void *db_valueFromString(db_string string, void* out, db_typedef type) {
    db_string_deser_t serData;

    serData.out = out;
    serData.scope = NULL;
    serData.type = type->real;
    if (!db_string_deser(string, &serData)) {
        db_assert(!serData.out, "deserializer failed but out is set");
    }

    return serData.out;
}

/* Compare objects */
db_equalityKind db_compare(db_object o1, db_object o2) {
    db_any a1, a2;
    a1.value = o1;
    a1.type = db_typeof(o1)->real;
    a1.owner = FALSE;
    a2.value = o2;
    a2.type = db_typeof(o2)->real;
    a2.owner = FALSE;
    return db_type_compare(a1, a2);
}

/* Compare value */
db_equalityKind db_valueCompare(db_value *value1, db_value *value2) {
    db_void *v1, *v2;
    db_any a1, a2;
    db_type t1, t2;

    v1 = db_valueValue(value1);
    v2 = db_valueValue(value2);
    t1 = db_valueType(value1)->real;
    t2 = db_valueType(value2)->real;

    a1.value = v1;
    a1.type = t1;
    a1.owner = FALSE;
    a2.value = v2;
    a2.type = t2;
    a2.owner = FALSE;
    return db_type_compare(a1, a2);
}

/* Init object */
db_int16 db_init(db_object o) {
    db_typeKind kind = db_typeof(o)->real->kind;
    switch(kind) {
        case DB_COMPOSITE:
        case DB_COLLECTION: {
            struct db_serializer_s s = db_ser_init(0, DB_NOT, DB_SERIALIZER_TRACE_ON_FAIL);
            db_serialize(&s, o, NULL);
            break;
        }
        default:
            break;
    }
    return 0;
}

/* Init value */
db_int16 db_initValue(db_value *v) {
    struct db_serializer_s s = db_ser_init(0, DB_NOT, DB_SERIALIZER_TRACE_ON_FAIL);
	return db_serializeValue(&s, v, NULL);
}

/* Deinit object */
db_int16 db_deinit(db_object o) {
    db_typeKind kind = db_typeof(o)->real->kind;
    switch(kind) {
        case DB_COMPOSITE:
        case DB_COLLECTION: {
            struct db_serializer_s s = db_ser_freeResources(0, DB_NOT, DB_SERIALIZER_TRACE_ON_FAIL);
            db_serialize(&s, o, NULL);
            break;
        }
        default:
            break;
    }
    return 0;
}

/* Deinit value */
db_int16 db_deinitValue(db_value *v) {
    struct db_serializer_s s = db_ser_freeResources(0, DB_NOT, DB_SERIALIZER_TRACE_ON_FAIL);
	return db_serializeValue(&s, v, NULL);
}

/* Copy object */
db_int16 db_copy(db_object dst, db_object src) {
    struct db_serializer_s s = db_copy_ser(DB_PRIVATE, DB_NOT, DB_SERIALIZER_TRACE_ON_FAIL);
    db_copy_ser_t data;
    db_int16 result;
    db_valueObjectInit(&data.value, dst);
    result = db_serialize(&s, src, &data);
    return result;
}

/* Copy value */
db_int16 db_valueCopy(db_value *dst, db_value *src) {
    struct db_serializer_s s = db_copy_ser(DB_PRIVATE, DB_NOT, DB_SERIALIZER_TRACE_ON_FAIL);
    db_copy_ser_t data;
    db_int16 result;
    data.value = *dst;
    result = db_serializeValue(&s, src, &data);
    return result;
}

db_object db_hyve_new(db_typedef type) {
    return db_new(type);
}

db_object db_hyve__new(db_typedef type, db_attr attributes) {
    return db_new_ext(NULL, type, attributes, NULL);
}

void __db_hyve_new(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_object*)result = db_hyve_new(*(db_typedef*)args);
}

void __db_hyve__new(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_object*)result = db_hyve__new(
        *(db_typedef*)args,
        *(db_attr*)((intptr_t)args + sizeof(db_typedef)));
}

