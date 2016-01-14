 /*
 * corto_object.c
 *
 *  Created on: Aug 3, 2012
 *      Author: sander
 */

#include "corto/corto.h"
#include "_object.h"
#include "lang/_class.h"

extern corto_mutex_s corto_adminLock;

static corto_object corto_adopt(corto_object parent, corto_object child);
static corto_int32 corto_notify(corto__observable *_o, corto_object observable, corto_uint32 mask);
static void corto_olsDestroy(corto__scope *scope);

extern corto_threadKey CORTO_KEY_ATTR;

/* Thread local storage key that keeps track of the objects that are prepared to wait for. */
extern corto_threadKey CORTO_KEY_WAIT_ADMIN;

typedef struct corto_waitForObject {
    corto_object objects[CORTO_MAX_WAIT_FOR_OBJECTS];
    corto_uint32 count;
    corto_object triggered;
    corto_sem semaphore;
    corto_observer observer;
    int triggerCount; /* Value is atomically incremented\decremented to make sure wait is only triggered once */
} corto_waitForObject;

/* Thread local storage key for administration that keeps track for which observables notifications take place.
 * This key points to an element in a list keyed by threadId's for which notifications have taken place. Value
 * of this element is the observable being notified at the moment. When a listen\silence call needs to clean
 * memory it can look at this administration to see if it is in use. To prevent deadlocks, listen\silence calls
 * will not look at their own threadId, since this would indicate listen\silence is called from an observer being
 * notified. This key is created in corto_start. */
/* TODO: when a thread exits, the corresponding element must be free'd again - use tls destructor function */
extern corto_threadKey CORTO_KEY_OBSERVER_ADMIN;

/* Lists all the anonymous objects in use. Used by the garbage collector. */
corto_ll corto_anonymousObjects = NULL;

typedef struct corto_observerElement {
    corto__observer ** observers;
    corto_bool free;
}corto_observerElement;

typedef struct corto_observerAdmin {
    corto_thread id;
    corto_observerElement stack[CORTO_MAX_NOTIFY_DEPTH];
    corto_uint32 sp;
    corto_object from;
}corto_observerAdmin;
static corto_observerAdmin observerAdmin[CORTO_MAX_THREADS];

/* Stack for tracing memory management operations */
static corto_string memtrace[50];
static corto_int8 memtraceSp = 0;

static struct corto_observerAdmin* corto_observerAdminGet(void) {
    corto_observerAdmin *admin = corto_threadTlsGet(CORTO_KEY_OBSERVER_ADMIN);
    if (!admin) {
        corto_thread thr = corto_threadSelf();
        corto_uint32 i;
        do {
            i = 0;
            while(observerAdmin[i].id) { /* Find a free slot for thread in administration */
                i++;
                if (i >= CORTO_MAX_THREADS) {
                    corto_critical("maximum number of supported threads reached! (%d)", CORTO_MAX_THREADS);
                }
            }
        }while(!corto_cas(&observerAdmin[i].id,0,thr));
        admin = &observerAdmin[i];
        corto_threadTlsSet(CORTO_KEY_OBSERVER_ADMIN, admin);
    }
    return admin;
}

/* Push observer-array to thread administration. Rather than passing the array pass the
 * address of the array so that setting the administration can be done atomic. */
corto__observer** corto_observersPush(corto__observer**  *observers, corto_object *this) {
    corto__observer** result;
    corto_observerAdmin *admin = corto_observerAdminGet();

    result = admin->stack[admin->sp].observers = *observers;
    admin->stack[admin->sp++].free = FALSE;

    if (this) {
        *this = admin->from;
    }

    return result;
}

corto_bool corto_observersPop(void) {
    corto_observerAdmin *admin = corto_threadTlsGet(CORTO_KEY_OBSERVER_ADMIN); /* Admin must always exist when popping */
    return admin->stack[--admin->sp].free;
}

corto_bool corto_observersWaitForUnused(corto__observer** observers) {
    corto_thread self = corto_threadSelf();
    corto_uint32 i, j;
    corto_bool inUse, freeArray = TRUE; /* Initialization merely to satisfy the compiler */

    if (!observers) {
        return FALSE;
    }

    /* Spinning loop which waits as long as an observer array is being used
     * in a notification by any of the running threads. */
    do {
        inUse = FALSE;
        for(i = 0; i < CORTO_MAX_THREADS; i++) {
            if (observerAdmin[i].id) {
                /* Check whether the observer array is in use by threads other than myself */
                if ((observerAdmin[i].id != self)) {
                    for(j=0; j<observerAdmin[i].sp; j++) {
                        if (observerAdmin[i].stack[j].observers == observers) {
                            inUse = TRUE; /* Array is found, so keep waiting */
                        }
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

static corto__scope* corto__objectScope(corto__object* o) {
    corto__scope* result = NULL;

    if (o->attrs.scope) {
        result = CORTO_OFFSET(o, -sizeof(corto__scope));
    }

    return result;
}

static corto__writable* corto__objectWritable(corto__object* o) {
    corto__writable* result = (void*)o;

    if (o->attrs.scope) {
        result = CORTO_OFFSET(result, -sizeof(corto__scope));
    }
    if (o->attrs.write) {
        result = CORTO_OFFSET(result, -sizeof(corto__writable));
    } else {
        result = NULL;
    }

    return result;
}

static corto__observable* corto__objectObservable(corto__object* o) {
    corto__observable* result = (void*)o;

    if (o->attrs.scope) {
        result = CORTO_OFFSET(result, -sizeof(corto__scope));
    }
    if (o->attrs.write) {
        result = CORTO_OFFSET(result, -sizeof(corto__writable));
    }
    if (result && o->attrs.observable) {
        result = CORTO_OFFSET(result, -sizeof(corto__observable));
    } else {
        result = NULL;
    }

    return result;
}

static corto__persistent* corto__objectPersistent(corto__object* o) {
    corto__persistent* result = (void*)o;

    if (o->attrs.scope) {
        result = CORTO_OFFSET(result, -sizeof(corto__scope));
    }
    if (o->attrs.write) {
        result = CORTO_OFFSET(result, -sizeof(corto__writable));
    }
    if (result && o->attrs.observable) {
        result = CORTO_OFFSET(result, -sizeof(corto__observable));
    }
    if (o->attrs.persistent) {
        result = CORTO_OFFSET(result, -sizeof(corto__persistent));
    } else {
        result = NULL;
    }

    return result;
}

static void* corto__objectStartAddr(corto__object* o) {
    void* result;
    result = o;
    if (o->attrs.scope) {
        result = CORTO_OFFSET(result, -sizeof(corto__scope));
    }
    if (o->attrs.write) {
        result = CORTO_OFFSET(result, -sizeof(corto__writable));
    }
    if (o->attrs.observable) {
        result = CORTO_OFFSET(result, -sizeof(corto__observable));
    }
    if (o->attrs.persistent) {
        result  = CORTO_OFFSET(result, -sizeof(corto__persistent));
    }
    return result;
}

/* Initialze scope-part of object */
static corto_object corto__initScope(corto_object o, corto_string name, corto_object parent) {
    corto__object* _o;
    corto__scope* scope;
    corto_object result = NULL;

    _o = CORTO_OFFSET(o, -sizeof(corto__object));
    scope = corto__objectScope(_o);
    corto_assert(scope != NULL,
      "corto__initScope: created scoped object, but corto__objectScope returned NULL.");

    scope->name = corto_strdup(name);

    /* Set parent, so that initializer can refer to it */
    scope->parent = parent;
    corto_rwmutexNew(&scope->scopeLock);

    /* Call framework initializer. Do this before adopting the
     * object, so that when the initializer failed, it hasn't
     * yet been added to the scope. */
    if (corto_init(o)) {
        corto_string err = corto_lasterr();
        if (err) {
            corto_seterr(
              "%s/init failed: %s", corto_fullpath(NULL, corto_typeof(o)), err);
        } else {
            corto_seterr(
              "%s/init failed", corto_fullpath(NULL, corto_typeof(o)));
        }
        goto error;
    }

    /* Add object to the scope of the parent-object */
    if (!(result = corto_adopt(parent, o))) {
        /* Reset parent */
        scope->parent = NULL;
        goto error;
    }

    if (result != o) {
        corto_dealloc(scope->name);
        corto_rwmutexFree(&scope->scopeLock);
        _o = CORTO_OFFSET(result, -sizeof(corto__object));
        scope = corto__objectScope(_o);
    }

    return result;
error:
    return NULL;
}

static void corto__deinitScope(corto_object o) {
    corto__object *_o;
    corto__scope* scope;

    /* Obtain own scope */
    _o = CORTO_OFFSET(o, -sizeof(corto__object));
    scope = corto__objectScope(_o);
    corto_assert(scope != NULL,
        "corto__deinitScope: called on non-scoped object <%p>.", o);

    /* Free parent */
    if (scope->parent) {
        corto_release(scope->parent);
        scope->parent = NULL;
    }

    /* We cannot remove the scope itself, since there might be childs
    * which have multiple cycles, which must be resolved first. */

    /* Deleting the name of the object is also postponed until the object itself
     * is deleted. This makes it easier to debug scenarios with cycles where
     * otherwise lots of objects with NULL names would show up. It also
     * allows the select function to more efficiently determine what the
     * last iterated object was after a tree has changed. */

    if (scope->ols) {
        corto_olsDestroy(scope);
    }

    /* Finally, free own scopeLock. */
    corto_rwmutexFree(&scope->scopeLock);
}

/* Initialize writable-part of object */
static void corto__initWritable(corto_object o) {
    corto__object* _o;
    corto__writable* writable;

    _o = CORTO_OFFSET(o, -sizeof(corto__object));
    writable = corto__objectWritable(_o);
    corto_assert(writable != NULL, "corto__initWritable: created writable object, but corto__objectWritable returned NULL.");

    corto_rwmutexNew(&writable->lock);
}

static void corto__deinitWritable(corto_object o) {
    corto__object* _o;
    corto__writable* writable;

    _o = CORTO_OFFSET(o, -sizeof(corto__object));
    writable = corto__objectWritable(_o);
    corto_assert(writable != NULL, "corto__deinitWritable: called on non-writable object <%p>.", o);

    corto_rwmutexFree(&writable->lock);
}

/* Initialize observable-part of object */
static void corto__initObservable(corto_object o) {
    corto__object* _o;
    corto__observable *observable;

    _o = CORTO_OFFSET(o, -sizeof(corto__object));
    observable = corto__objectObservable(_o);
    corto_assert(observable != NULL, "corto__initObservable: created observable object, but corto__objectObservable returned NULL.");

    corto_rwmutexNew(&observable->selfLock);

    if (corto_checkAttr(o, CORTO_ATTR_SCOPED)) {
        corto_rwmutexNew(&observable->childLock);
    }

    observable->onSelf = NULL;
    observable->onChild = NULL;
    observable->onSelfArray = NULL;
    observable->onChildArray = NULL;
}

static void corto__deinitObservable(corto_object o) {
    corto__object* _o;
    corto__observable* observable;

    _o = CORTO_OFFSET(o, -sizeof(corto__object));
    observable = corto__objectObservable(_o);
    corto_assert(observable != NULL, "corto__deinitObservable: called on non-observable object <%p>.", o);

    /* Delete observer objects in onSelf and onChild */
    if (observable->onSelf) {
        corto__observer* observer;
        while((observer = corto_llTakeFirst(observable->onSelf))) {
            if (!--observer->count) {
                corto_dealloc(observer);
            }
        }
        corto_llFree(observable->onSelf);
        observable->onSelf = NULL;
    }

    if (observable->onChild) {
        corto__observer* observer;
        while((observer = corto_llTakeFirst(observable->onChild))) {
            observer->count--;
             if (!observer->count) {
                corto_dealloc(observer);
            }
        }
        corto_llFree(observable->onChild);
        observable->onChild = NULL;
    }

    corto_rwmutexFree(&observable->selfLock);
    if (corto_checkAttr(o, CORTO_ATTR_SCOPED)) {
        corto_rwmutexFree(&observable->childLock);
    }
}

/* Initialize static scoped object */
void corto__newSSO(corto_object sso) {
    corto__object* o;
    corto__scope* scope;

    o = CORTO_OFFSET(sso, -sizeof(corto__object));
    scope = corto__objectScope(o);
    corto_assert(scope != NULL, "SSO object without a scope? That's bad.");

    /* Don't call initScope because name is already set. */
    corto_rwmutexNew(&scope->scopeLock);
    if (scope->parent) {
        corto__adoptSSO(sso);
    }

    /* Init observable */
    if (corto_checkAttr(sso, CORTO_ATTR_OBSERVABLE)) {
        corto__initObservable(sso);
    }

    /* Keep type */
    corto_claim(corto_typeof(sso));
}

/* Deinitialize static scoped object */
corto_int16 corto__freeSSO(corto_object sso) {
    corto__object* o;
    corto__scope* scope;

    o = CORTO_OFFSET(sso, -sizeof(corto__object));
    scope = corto__objectScope(o);

    corto_assert(scope != NULL, "corto__freeSSO: static scoped object has no scope")

    corto__orphan(sso);

    if (scope->parent) {
        corto_release(scope->parent);
    }

    if (scope->scope) {
        /* Don't print this error - without a proper cycle detector this could
         * be reported without there actually being a problem
        if (corto_rbtreeSize(scope->scope)) {
            corto_error("corto__freeSSO: scope of object '%s' is not empty (%p/%p: %d left)",
                corto_nameof(sso),
                sso,
                scope->scope,
                corto_rbtreeSize(scope->scope));
            goto error;
        }*/
        corto_rbtreeFree(scope->scope);
        scope->scope = NULL;
    }

    corto_rwmutexFree(&scope->scopeLock);

    /* Deinitialize observable */
    if (corto_checkAttr(sso, CORTO_ATTR_OBSERVABLE)) {
        corto__deinitObservable(sso);
    }

    /* Free type */
    corto_release(corto_typeof(sso));

    return 0;
}

/* Adopt static scoped object */
int corto__adoptSSO(corto_object sso) {
    corto__object* o;
    corto__scope* scope;
    corto_object parent;

    o = CORTO_OFFSET(sso, -sizeof(corto__object));
    scope = corto__objectScope(o);

    corto_assert(scope != NULL, "corto__adoptSSO: static scoped object has no scope (very unlikely, corto__adoptSSO called on non-static object?)");

    parent = scope->parent;

    corto_assert(parent != NULL, "corto__adoptSSO: static scoped object has no parent");

    return !corto_adopt(parent, sso);
}

/* Find the right constructor to call */
void corto_delegateDestruct(corto_type t, corto_object o) {
    corto_function delegate = NULL;

    if (t->kind == CORTO_COMPOSITE) {
        if (corto_interface(t)->kind == CORTO_CLASS) {
            corto_interface i = corto_interface(t);
            do {
                delegate = corto_class(i)->destruct._parent.procedure;
                i = i->base;
            } while(i && !delegate);
        }
    }

    if (delegate) {
        if(delegate->kind == CORTO_PROCEDURE_CDECL) {
            ((void(*)(corto_function f, void *result, void *args))delegate->impl)(delegate, NULL, &o);
        } else {
            corto_call(delegate, NULL, o);
        }
    }
}

/* Destruct object */
void corto__destructor(corto_object o) {
    corto_type t;
    corto__object* _o;

    t = corto_typeof(o);
    if (corto_checkState(o, CORTO_DEFINED)) {
        _o = CORTO_OFFSET(o, -sizeof(corto__object));
        if (corto_class_instanceof(corto_class_o, t)) {

            /* Call destructor */
            corto_delegateDestruct(corto_typeof(o), o);
        } else if (corto_class_instanceof(corto_procedure_o, t)) {
            /* Call unbind */
            corto_procedure_unbind(corto_procedure(corto_typeof(o)), o);
        }

        _o->attrs.state &= ~CORTO_DEFINED;
    } else {
        corto_critical("%s/destruct: object '%s' is not defined",
            corto_fullpath(NULL, t), corto_fullpath(NULL, o));
    }
}

void corto__setState(corto_object o, corto_uint8 state) {
    corto__object* _o;

    _o = CORTO_OFFSET(o, -sizeof(corto__object));
    _o->attrs.state |= state;
}

static corto_equalityKind corto_compareDefault(corto_type this, const void* o1, const void* o2) {
    int r;
    CORTO_UNUSED(this);
    return ((r = stricmp(o1, o2)) < 0) ? CORTO_LT : (r > 0) ? CORTO_GT : CORTO_EQ;
}

static corto_equalityKind corto_compareLookupIntern(const char *o1, const char *o2, corto_bool matchArgs) {
    int r;
    const char *ptr1, *ptr2;
    ptr1 = o1;
    ptr2 = o2;
    char ch1, ch2;

    ch2 = *ptr2;
    while((ch1 = *ptr1) && ch2) {
        if (ch1 == ch2) {
            ptr1++; ptr2++;
            ch2 = *ptr2;
            continue;
        }
        if (ch1 < 97) ch1 = tolower(ch1);

        /* Query is always made lower case, for efficiency reasons */
        /* if (ch2 < 97) ch2 = tolower(ch2); */
        if (ch1 != ch2) {
            r = ch1 - ch2;
            goto compare;
        }
        ptr1++;
        ptr2++;
        ch2 = *ptr2;
    }

  if (matchArgs) {
      if ((ch1 == '(') && !ch2) {
          r = 0;
          goto compare;
      }
  }

  r = ch1 - ch2;
compare:
  return (r < 0) ? CORTO_LT : (r > 0) ? CORTO_GT : CORTO_EQ;
}

static corto_equalityKind corto_compareLookup(corto_type this, const void* o1, const void* o2) {
    CORTO_UNUSED(this);
    return corto_compareLookupIntern(o1, o2, TRUE);
}

static corto_equalityKind corto_compareLookupNoArgMatching(corto_type this, const void* o1, const void* o2) {
    CORTO_UNUSED(this);
    return corto_compareLookupIntern(o1, o2, FALSE);
}

static void corto_memtracePush(void) {
    memtraceSp ++;
}

static void corto_memtracePop(void) {
    memtraceSp --;
    if (memtrace[memtraceSp]) {
        corto_dealloc(memtrace[memtraceSp]);
        memtrace[memtraceSp] = NULL;
    }
}

static void corto_memtrace(corto_string oper, corto_object o, corto_string context) {
    corto_id path;
    corto_fullpath(path, o);

    if (memtrace[memtraceSp]) {
        corto_dealloc(memtrace[memtraceSp]);
        memtrace[memtraceSp] = NULL;
    }

    corto_asprintf(&memtrace[memtraceSp], "%s (%s) %s", path, oper, context ? context : "");

    if (!strcmp(path, CORTO_TRACE_OBJECT)) {
        printf("%s: %s (count = %d, destructed = %d)\n",
            oper,
            path,
            corto_countof(o),
            corto_checkState(o, CORTO_DESTRUCTED));

        if (context) {
            printf("    %s\n", context);
        }

        if (memtraceSp) {
            corto_int32 i = memtraceSp;
            do {
                i --;
                printf("   from: %s\n", memtrace[i]);
            } while (i);
        }
        if (CORTO_BACKTRACE_ENABLED) {
            corto_backtrace(stdout);
        }
        printf("\n");
    }
}

/* Match a state exclusively:
 *                CORTO_DECLARED - CORTO_DECLARED | CORTO_DEFINED
 *  CORTO_DECLARED        X
 *  CORTO_DEFINED                       X
 *  CORTO_DECLARED |      X             X
 *     CORTO_DEFINED
 */
static corto_bool corto__checkStateXOR(corto_object o, corto_uint8 state) {
    corto_uint8 ostate;
    corto__object* _o;

    _o = CORTO_OFFSET(o, -sizeof(corto__object));

    ostate = _o->attrs.state;
    if (ostate & CORTO_DEFINED) {
        ostate = CORTO_DEFINED;
    }

    return ostate & state;
}

/* Adopt an object */
static corto_object corto_adopt(corto_object parent, corto_object child) {
    corto__object *_parent, *_child;
    corto__scope *p_scope, *c_scope;
    corto_type parentType;
    corto_type childType;

    _parent = CORTO_OFFSET(parent, -sizeof(corto__object));
    _child = CORTO_OFFSET(child, -sizeof(corto__object));
    childType = corto_typeof(child);

    /* Parent must be a valid object */
    if (!corto_checkState(parent, CORTO_VALID)) {
        corto_seterr("parent is invalid");
        goto error;
    }

    /* Obtain pointers to scope of parent and child */
    p_scope = corto__objectScope(_parent);
    if (p_scope) {
        c_scope = corto__objectScope(_child);
        if (c_scope) {

            /* Insert child in parent-scope */
            if (corto_rwmutexWrite(&p_scope->scopeLock))
                corto_critical("corto_adopt: lock operation on scopeLock of parent failed");

            if (!p_scope->scope) {
                p_scope->scope = corto_rbtreeNew_w_func(corto_compareDefault);
            }

            corto_object existing = corto_rbtreeFindOrSet(p_scope->scope, c_scope->name, child);
            if (existing) {
                if (corto_typeof(existing) != corto_typeof(child)) {
                    corto_seterr("'%s' is already declared with a different type", c_scope->name);
                    goto err_existing;
                } else {
                    child = existing;
                }
            } else {
                /* Check if parentType matches scopeType of child type */
                if (childType->parentType) {
                    parentType = corto_typeof(parent);
                    if ((childType->parentType != parentType) && !corto_instanceof(childType->parentType, parent)) {
                        corto_seterr("type of '%s' is not '%s'",
                                corto_fullpath(NULL, parent),
                                corto_fullpath(NULL, childType->parentType));
                        goto err_invalid_parent;
                    }
                }

                /* Check if parentState matches scopeState of child type */
                if (childType->parentState && !corto__checkStateXOR(parent, childType->parentState)) {
                    corto_uint32 childState = childType->parentState;
                    corto_seterr("'%s' is %s, must be %s",
                        corto_fullpath(NULL, parent),
                        corto_stateStr(_parent->attrs.state),
                        corto_stateStr(childState));
                    goto err_invalid_parent;
                }
            }

            /* Parent must not be deleted before all childs are gone. */
            if (CORTO_TRACE_OBJECT) corto_memtrace("declare", child, NULL);
            if (CORTO_TRACE_OBJECT) corto_memtracePush();
            corto_claim(parent);
            if (CORTO_TRACE_OBJECT) corto_memtracePop();

            if (corto_rwmutexUnlock(&p_scope->scopeLock))
                corto_critical("corto_adopt: unlock operation on scopeLock of parent failed");
        } else {
            corto_critical("corto_adopt: child-object is not scoped");
        }
    } else {
        corto_critical("corto_adopt: parent-object is not scoped");
    }

    return child;

err_invalid_parent:
    c_scope->parent = NULL;
    corto_rbtreeRemove(p_scope->scope, c_scope->name);
err_existing:
    corto_rwmutexUnlock(&p_scope->scopeLock);
error:
    return NULL;
}

/* Orphan object - not a public function as this will only happen during destruction of an object. */
void corto__orphan(corto_object o) {
    corto__object *_parent, *_child;
    corto__scope *p_scope, *c_scope;

    _child = CORTO_OFFSET(o, -sizeof(corto__object));
    c_scope = corto__objectScope(_child);

    if (c_scope->parent) {
        _parent = CORTO_OFFSET(c_scope->parent, -sizeof(corto__object));
        p_scope = corto__objectScope(_parent);

        /* Remove object from parent scope */
        if (corto_rwmutexWrite(&p_scope->scopeLock)) goto err_parent_mutex;
        corto_rbtreeRemove(p_scope->scope, (void*)corto_nameof(o));

        if (corto_rwmutexUnlock(&p_scope->scopeLock)) goto err_parent_mutex;
    }

    return;
err_parent_mutex:
    corto_error("corto__orphan: lock operation of scopeLock of parent failed");
}

/* Find the right initializer to call */
corto_int16 corto_delegateInit(corto_type t, void *o) {
    corto_function delegate = NULL;
    corto_int16 result = 0;

    delegate = t->init._parent.procedure;

    if (t->kind == CORTO_COMPOSITE) {
        if ((corto_interface(t)->kind == CORTO_CLASS) || ((corto_interface(t)->kind == CORTO_PROCEDURE))) {
            corto_interface i = corto_interface(t)->base;
            while(i && !delegate) {
                delegate = corto_type(i)->init._parent.procedure;
                i = i->base;
            }
        }
    }

    if (delegate) {
        if(delegate->kind == CORTO_PROCEDURE_CDECL) {
            ((void(*)(corto_function f, void *result, void *args))delegate->impl)(delegate, &result, &o);
        } else {
            corto_call(delegate, &result, o);
        }
    }

    return result;
}

corto_attr corto_setAttr(corto_attr attrs) {
    corto_attr* attr = corto_threadTlsGet(CORTO_KEY_ATTR);
    corto_attr oldAttr = CORTO_ATTR_DEFAULT;
    if (!attr) {
        attr = corto_alloc(sizeof(corto_attr));
        corto_threadTlsSet(CORTO_KEY_ATTR, attr);
    } else {
        oldAttr = *attr;
    }
    *attr = attrs;
    return oldAttr;
}

corto_attr corto_getAttr(void) {
    corto_attr* attr = corto_threadTlsGet(CORTO_KEY_ATTR);
    if (attr) {
        return *attr;
    } else {
        return CORTO_ATTR_DEFAULT;
    }
}

/* Create new object with attributes */
corto_object _corto_declare(corto_type type) {
    corto_uint32 size, headerSize;
    corto__object* o = NULL;
    corto_attr attrs = corto_getAttr();

    if (!type) {
        corto_seterr("parameter 'type' is null");
        goto error;
    }

    /* Type must be valid and defined */
    if (!corto_checkState(type, CORTO_VALID | CORTO_DEFINED)) {
        corto_seterr("type is not valid/defined");
        goto error;
    }

    if (attrs & CORTO_ATTR_DEFAULT) {
        attrs |= CORTO_ATTR_OBSERVABLE;

        if (type->kind != CORTO_VOID) {
            attrs |= CORTO_ATTR_WRITABLE;
        }
        if (attrs & CORTO_ATTR_SCOPED) {
            attrs |= CORTO_ATTR_PERSISTENT;
        }
    }

    headerSize = sizeof(corto__object);

    size = type->size;

    /* Calculate size of attributes */
    if (attrs & CORTO_ATTR_SCOPED) {
        headerSize += sizeof(corto__scope);
    }
    if (attrs & CORTO_ATTR_WRITABLE) {
        headerSize += sizeof(corto__writable);
    }
    if (attrs & CORTO_ATTR_OBSERVABLE) {
        headerSize += sizeof(corto__observable);
    }
    if (attrs & CORTO_ATTR_PERSISTENT) {
        headerSize += sizeof(corto__persistent);
    }

    size += headerSize;

    /* Allocate object */
    o = corto_calloc(size);
    if (o) {

        /* Offset o so it points to object */
        o = CORTO_OFFSET(o, headerSize - sizeof(corto__object));

        /* Give object initial refcount */
        o->refcount = 1;

        /* Set type */
        o->type = type;

        /* Set attributes */
        if (attrs & CORTO_ATTR_SCOPED) {
            o->attrs.scope = TRUE;
        }
        if (attrs & CORTO_ATTR_WRITABLE) {
            if (type->kind == CORTO_VOID) {
                corto_warning("writable void object created");
            }
            o->attrs.write = TRUE;
            corto__initWritable(CORTO_OFFSET(o, sizeof(corto__object)));
        }
        if (attrs & CORTO_ATTR_OBSERVABLE) {
            o->attrs.observable = TRUE;
        }
        if (attrs & CORTO_ATTR_PERSISTENT) {
            o->attrs.persistent = TRUE;
        }

        /* Initially, an object is valid and declared */
        o->attrs.state = CORTO_DECLARED;

        corto_claim(type);

        if (!(attrs & CORTO_ATTR_SCOPED)) {
            if (attrs & CORTO_ATTR_OBSERVABLE) {
                corto__initObservable(CORTO_OFFSET(o, sizeof(corto__object)));
            }

            /* Call framework initializer */
            if (!corto_init(CORTO_OFFSET(o, sizeof(corto__object)))) {
                o->attrs.state |= CORTO_VALID;
            } else {
                corto_string err = corto_lasterr();
                if (err) {
                    corto_seterr("%s/init failed: %s",
                        corto_fullpath(NULL, type), err);
                } else {
                    corto_seterr("%s/init failed",
                        corto_fullpath(NULL, type));
                }
                goto error_init;
            }

            /* Add object to anonymous cache */
            corto_mutexLock(&corto_adminLock);
            if (!corto_anonymousObjects) {
                corto_anonymousObjects = corto_llNew();
            }
            corto_llInsert(corto_anonymousObjects, CORTO_OFFSET(o, sizeof(corto__object)));
            corto_mutexUnlock(&corto_adminLock);

            /* void objects are instantly defined because they have no value. */
            if (type->kind == CORTO_VOID) {
                corto_define(CORTO_OFFSET(o, sizeof(corto__object)));
            }
        }
    }

    return CORTO_OFFSET(o, sizeof(corto__object));
error_init:
    corto_release(type);
error:
    if (o) corto_dealloc(corto__objectObservable(o));
    return NULL;
}

/* Declare object */
corto_object _corto_declareChild(corto_object parent, corto_string name, corto_type type) {
    corto_object o = NULL;

    if (!parent) {
        parent = root_o;
    }

    if (!name || !strlen(name)) {
        corto_seterr("invalid name");
        goto error;
    }

    /* Create new object */
    corto_attr oldAttr = corto_setAttr(corto_getAttr()|CORTO_ATTR_SCOPED);
    o = corto_declare(type);
    corto_setAttr(oldAttr);

    if (o) {
        corto_object o_ret = NULL;
        corto__object *_o = CORTO_OFFSET(o, -sizeof(corto__object));

        /* Initialize object parameters. */
        if ((o_ret = corto__initScope(o, name, parent))) {

            if (o_ret == o) {
                /* Observable administration needs to be initialized after the
                 * scope administration because it needs to setup the correct
                 * chain of parents to notify on an event. */
                if (corto_checkAttr(o, CORTO_ATTR_OBSERVABLE)) {
                    corto__initObservable(o);
                }

                /* Initially, an object is valid and declared */
                _o->attrs.state |= CORTO_VALID;
            } else {
                corto_release(type);
                corto_dealloc(corto__objectStartAddr(CORTO_OFFSET(o,-sizeof(corto__object))));
                o = o_ret;

                /* Redeclaring an object results in a claim so that the object
                 * can't be deallocated until it is explicitly deleted by the
                 * code that redeclared it. */
                corto_claim(o);

                /* The object already exists. Check if the existing object is
                 * owned by the same owner as the one registered */
                corto_object owner = corto_ownerof(o);
                if (owner && corto_instanceof(corto_replicator_o, owner)) {
                    if (owner != corto_getOwner()) {
                        corto_release(o);
                        corto_seterr(
                          "owner '%s' of existing object '%s' does not match",
                          corto_fullpath(NULL, owner),
                          corto_fullpath(NULL, o));
                        goto owner_error;
                    }
                }

                goto ok;
            }
        } else {
            corto__deinitScope(o);
            corto_release(type);
            corto_dealloc(corto__objectStartAddr(CORTO_OFFSET(o,-sizeof(corto__object))));
            o = NULL;
            goto error;
        }

        /* Notify parent of new object */
        if (corto__objectObservable(_o)) {
            corto_notify(corto__objectObservable(_o), o, CORTO_ON_DECLARE);
        }

        /* void objects are instantly defined because they have no value. */
        if (type->kind == CORTO_VOID) {
            corto_define(o);
        }
    }

ok:
    return o;
error:
    if (o) {
        corto_delete(o);
    }
owner_error:
    return NULL;
}

corto_object _corto_create(corto_type type) {
    corto_object result = corto_declare(type);
    if (result && corto_checkState(result, CORTO_VALID)) {
        corto_define(result);
    }
    return result;
}

corto_object _corto_createChild(corto_object parent, corto_string name, corto_type type) {
    corto_object result = corto_declareChild(parent, name, type);
    if (result && corto_checkState(result, CORTO_VALID)) {
        corto_define(result);
    }
    return result;
}

/* Find the right constructor to call */
corto_int16 corto_delegateConstruct(corto_type t, corto_object o) {
    corto_function delegate = NULL;
    corto_int16 result = 0;

    if (t->kind == CORTO_COMPOSITE) {
        if (corto_interface(t)->kind == CORTO_CLASS) {
            corto_interface i = corto_interface(t);
            do {
                delegate = corto_class(i)->construct._parent.procedure;
                i = i->base;
            } while(i && !delegate);
        } else if (corto_interface(t)->kind == CORTO_PROCEDURE) {
            corto_interface i = corto_interface(t);
            do {
                delegate = corto_procedure(i)->bind._parent.procedure;
                i = i->base;
            } while(i && !delegate);
        }
    }

    if (delegate) {
        if (delegate->kind == CORTO_PROCEDURE_CDECL) {
            ((corto_int16 ___ (*)(corto_function f, void *result, void *args))delegate->impl)(delegate, &result, &o);
        } else {
            corto_call(delegate, &result, o);
        }
    }

    return result;
}

/* Define object */
corto_int16 corto_define(corto_object o) {
    corto_int16 result = 0;

    /* Only define valid, undefined objects */
    if (corto_checkState(o, CORTO_DECLARED)) {
        corto__object *_o = CORTO_OFFSET(o, -sizeof(corto__object));
        corto__persistent *_p = NULL;
        if (!corto_checkState(o, CORTO_DEFINED)) {
            corto_type t = corto_typeof(o);

            if ((_p = corto__objectPersistent(_o))) {
                _p->owner = corto_getOwner();
            }

            /* Don't invoke constructor if object is not locally owned */
            if (!_p || !_p->owner || !corto_instanceof(corto_replicator_o, _p->owner)) {
                /* If object is instance of a class, call the constructor */
                if (corto_class_instanceof(corto_class_o, t)) {
                    /* Call constructor - will potentially override observer params */
                    result = corto_delegateConstruct(t, o);
                } else if (corto_class_instanceof(corto_procedure_o, t)) {
                    result = corto_delegateConstruct(t, o);
                }
            }

            if (!result) {
                _o->attrs.state |= CORTO_DEFINED;
                if (!corto_checkState(o, CORTO_VALID)) {
                    _o->attrs.state |= CORTO_VALID;
                }

                /* Notify observers of defined object */
                corto_notify(corto__objectObservable(_o), o, CORTO_ON_DEFINE|CORTO_ON_UPDATE);
            } else {
                /* Remove valid state */
                corto_invalidate(o);
            }

            if (CORTO_TRACE_OBJECT) corto_memtrace("define", o, NULL);
        } else {
            corto_notify(corto__objectObservable(_o), o, CORTO_ON_UPDATE);
        }
    }

    return result;
}

static corto_bool corto_isBuiltin(corto_object o) {
    if (corto_checkAttr(o, CORTO_ATTR_SCOPED)) {
        if (o == root_o ||
            o == corto_o ||
            o == corto_lang_o ||
            o == corto_core_o)
        {
            return TRUE;
        } else
        {
            corto_object p = corto_parentof(o);
            if (p == corto_lang_o || p == corto_core_o)
            {
                return TRUE;
            } else
            {
                do {
                    p = corto_parentof(p);
                    if (p == corto_lang_o || p == corto_core_o) {
                        return TRUE;
                    }
                } while (p);
            }
        }
    }

    return FALSE;
}

corto_bool corto_destruct(corto_object o, corto_bool delete) {
    corto__object* _o;
    corto_bool result = TRUE;
    corto_object owner = corto_ownerof(o);

    _o = CORTO_OFFSET(o, -sizeof(corto__object));
    corto_ainc(&_o->refcount);

    /* Treat builtin objects separately. They cannot be destructed regularly
     * because they aren't allocated on heap */
    if (corto_isBuiltin(o)) {
        if (!corto_checkState(o, CORTO_DESTRUCTED)) {
            _o->attrs.state |= CORTO_DESTRUCTED;
        }
        return TRUE;
    }

    if (!corto_checkState(o, CORTO_DESTRUCTED)) {
        if (CORTO_TRACE_OBJECT) corto_memtrace("destruct", o, NULL);
        if (CORTO_TRACE_OBJECT) corto_memtracePush();

        /* From here, object is marked as destructed. */
        _o->attrs.state |= CORTO_DESTRUCTED;

        /* Only do the following steps if the object is defined */
        if (corto_checkState(o, CORTO_DEFINED)) {

            /* Only send delete notification when object is being deleted, not
             * when object is being suspended. */
            if (delete) {
                if (corto_checkAttr(o, CORTO_ATTR_SCOPED)) {
                    corto_drop(o, delete);
                }
                corto_notify(corto__objectObservable(_o), o, CORTO_ON_DELETE);
            }

            /* Call object destructor */
            if (!owner || !corto_instanceof(corto_replicator_o, owner)) {
                corto__destructor(o);
            }
        }

        /* Deinit observable */
        if (corto_checkAttr(o, CORTO_ATTR_OBSERVABLE)) {
            corto__deinitObservable(o);
        }

        /* Deinit scope */
        if (corto_checkAttr(o, CORTO_ATTR_SCOPED)) {
            corto__orphan(o);
        } else {
            /* Remove from anonymous cache */
            corto_mutexLock(&corto_adminLock);
            corto_llRemove(corto_anonymousObjects, o);
            corto_mutexUnlock(&corto_adminLock);
        }

        /* Indicate that object has been destructed */
        result = TRUE;
        if (CORTO_TRACE_OBJECT) corto_memtracePop();
    }

    /* Although after the destruct-operation it is ensured that this object no
     * longer participates in any cycles, it cannot be assumed that all objects
     * using this are free'd. For example, another object that has multiple
     * reference cycles might still be referencing this object, but can itself
     * not yet be freed because of the other cycles, which cannot be solved by
     * the destruction of this object. Therefore when the reference count of
     * this object is non-zero, it cannot yet be freed.
     */

    if (!corto_adec(&_o->refcount)) {

        /* Deinit writable */
        if (corto_checkAttr(o, CORTO_ATTR_WRITABLE)) {
            corto__deinitWritable(o);
        }

        if (CORTO_TRACE_OBJECT) corto_memtrace("deinit", o, NULL);

        /* Call deinitializer */
        if (CORTO_TRACE_OBJECT) corto_memtracePush();
        corto_deinit(o);
        if (CORTO_TRACE_OBJECT) corto_memtracePop();

        /* Do not free type before deinitializing the object, which needs the
         * type to walk over the content of the object. */
        corto_release(corto_typeof(o));

        /* If the object was scoped, check if there is a tree object that needs
         * to be removed. Tree objects can't be cleaned up for as long as the
         * object is referenced, since that may indicate that there can be
         * iterators active on the tree. Iterators need the tree object to
         * figure out whether mutations have happened. */
        if (corto_checkAttr(o, CORTO_ATTR_SCOPED)) {
            /* Deinit scope not before refcount goes to zero. The data in the scope
             * administration is required to determine whether this object is
             * a builtin object. */
            corto__deinitScope(o);

            _o = CORTO_OFFSET(o, -sizeof(corto__object));
             corto__scope *scope = corto__objectScope(_o);
            if (scope->scope) {
                corto_rbtreeFree(scope->scope);
            }

            if (scope->name) {
                corto_dealloc(scope->name);
                scope->name = NULL;
            }
        }

        if (CORTO_TRACE_OBJECT) corto_memtrace("deallocate", o, NULL);

        corto_dealloc(corto__objectStartAddr(_o));

        result = FALSE;
    }

    return result;
}

typedef struct corto_dropWalk_t {
    corto_ll objects;
}corto_dropWalk_t;

/* Collect objects in scope, so they can be removed outside of scopeLock. */
static int corto_dropWalk(void* o, void* userData) {
    corto_dropWalk_t* data;

    data = userData;

    /* Prevent object from being deleted when scopeLock is released, which
     * would result in invalid reference in list. */
    corto_claim(o);

    /* Insert object in list */
    if (!data->objects) {
        data->objects = corto_llNew();
    }
    corto_llInsert(data->objects, o);

    return 1;
}

void corto_drop(corto_object o, corto_bool delete) {
    corto__object* _o;
    corto__scope* scope;
    corto_dropWalk_t walkData;

    _o = CORTO_OFFSET(o, -sizeof(corto__object));
    scope = corto__objectScope(_o);
    if (scope) {
        corto_iter iter;
        corto_object collected;

        /* Because object refcounts can reach zero after a free, a
         * walk in which objects are collected is needed first. During
         * destruction of an object, this scopeLock is also required,
         * which would result in deadlocks. */

        corto_rwmutexRead(&scope->scopeLock);
        walkData.objects = NULL;
        if (scope->scope) {
            corto_rbtreeWalk(scope->scope, corto_dropWalk, &walkData);
        }
        corto_rwmutexUnlock(&scope->scopeLock);

        /* Free objects outside scopeLock */
        if (walkData.objects) {
            if (CORTO_TRACE_OBJECT) {
                corto_memtrace(delete ? "drop:delete" : "drop:suspend", o, NULL);
            }

            iter = corto_llIter(walkData.objects);
            while(corto_iterHasNext(&iter)) {
                collected = corto_iterNext(&iter);

                if (CORTO_TRACE_OBJECT) corto_memtracePush();

                if (delete) {
                    if (corto_destruct(
                        collected,
                        corto_owned(collected) && delete))
                    {
                        corto_release(collected);
                    }
                } else {
                    corto_release(collected);
                    corto_drop(collected, delete);
                }

                if (CORTO_TRACE_OBJECT) corto_memtracePop();

                /* Double free - because corto_drop itself introduced a keep. */
                corto_release(collected);
            }
            corto_llFree(walkData.objects);
        }
    } else {
        corto_critical("corto_drop: object <%p> is not scoped.", o);
    }
}

/* Delete object */
corto_int16 corto_suspend(corto_object o) {
    if (!o) {
        corto_critical("NULL passed to corto_delete");
    }

    if (corto_destruct(o, FALSE)) {
        corto_release(o);
    }

    return 0;
}

/* Delete object */
corto_int16 corto_delete(corto_object o) {
    if (!o) {
        corto_critical("NULL passed to corto_delete");
    }

    if (!corto_owned(o)) {
        corto_seterr(
          "can't delete %s: not owned by thread (use corto_suspend)",
          corto_fullpath(NULL, o));
        goto error;
    }

    if (CORTO_TRACE_OBJECT) corto_memtrace("delete", o, NULL);
    if (CORTO_TRACE_OBJECT) corto_memtracePush();

    if (corto_destruct(o, TRUE)) {
        corto_release(o);
    }

    if (CORTO_TRACE_OBJECT) corto_memtracePop();

    return 0;
error:
    return -1;
}

/* Invalidate object by removing valid flag */
void corto_invalidate(corto_object o) {
    corto__object* _o;
    _o = CORTO_OFFSET(o, -sizeof(corto__object));
    _o->attrs.state &= ~CORTO_VALID;
    /* Notify observers */
    corto_notify(corto__objectObservable(CORTO_OFFSET(o,-sizeof(corto__object))), o, CORTO_ON_INVALIDATE);
}

/* Get type */
corto_type corto_typeof(corto_object o) {
    corto__object* _o = CORTO_OFFSET(o, -sizeof(corto__object));
    return _o->type;
}

/* Get refcount */
corto_int32 corto_countof(corto_object o) {
    corto__object* _o;
    _o = CORTO_OFFSET(o, -sizeof(corto__object));
    return _o->refcount;
}

/* Get state */
corto_int8 corto_stateof(corto_object o) {
    corto__object* _o;
    _o = CORTO_OFFSET(o, -sizeof(corto__object));
    corto_int8 state = _o->attrs.state;
    return state;
}

/* Check for a state */
corto_bool corto_checkState(corto_object o, corto_int8 state) {
    corto__object* _o;
    _o = CORTO_OFFSET(o, -sizeof(corto__object));
    return (_o->attrs.state & state) == state;
}

/* Check for an attribute */
corto_bool corto_checkAttr(corto_object o, corto_int8 attr) {
    corto_bool result;
    corto__object* _o;

    _o = CORTO_OFFSET(o, -sizeof(corto__object));
    result = TRUE;

    if (attr & CORTO_ATTR_SCOPED) {
        if (!_o->attrs.scope) result = FALSE;
    }
    if (attr & CORTO_ATTR_WRITABLE) {
        if (!_o->attrs.write) result = FALSE;
    }
    if (attr & CORTO_ATTR_OBSERVABLE) {
        if (!_o->attrs.observable) result = FALSE;
    }
    if (attr & CORTO_ATTR_PERSISTENT) {
        if (!_o->attrs.persistent) result = FALSE;
    }
    return result;
}

corto_object _corto_assertType(corto_type type, corto_object o) {
    if (o && (o != type)) {
        if (!corto_instanceof(type, o)) {
            corto_error("object '%s' is not of type '%s'\n   type = %s",
                corto_fullpath(NULL, o),
                corto_fullpath(NULL, type),
                corto_fullpath(NULL, corto_typeof(o)));
            corto_backtrace(stdout);
            abort();
        }
    }
    return o;
}

corto_bool _corto_instanceof(corto_type type, corto_object o) {
    corto_type objectType = corto_typeof(o);
    corto_bool result = TRUE;

    if (type != objectType) {
        corto_type t;

        result = FALSE;
        t = corto_typeof(o);

        if (t->kind == type->kind) {
            switch(type->kind) {
            case CORTO_COMPOSITE: {
                if (((corto_interface)type)->kind == CORTO_DELEGATE) {
                    /*result = corto_delegate_instanceof(corto_delegate(type), o);*/
                } else if (((corto_interface)type)->kind == CORTO_INTERFACE) {
                    if (corto_interface(t)->kind == CORTO_CLASS) {
                        corto_interface base = (corto_interface)t;
                        while (!result && base) {
                            corto_int32 i;
                            for (i = 0; i < ((corto_class)base)->implements.length; i++) {
                                if (_corto_interface_baseof(
                                    (corto_interface)((corto_class)base)->implements.buffer[i], (corto_interface)type)) {
                                    result = TRUE;
                                    break;
                                }
                            }
                            base = base->base;
                        }
                    }
                } else {
                    result = _corto_interface_baseof((corto_interface)t, (corto_interface)type);
                }
                break;
            }
            case CORTO_PRIMITIVE:
                switch(corto_primitive(type)->kind) {
                case CORTO_ENUM:
                case CORTO_BITMASK:
                    if (corto_parentof(o) == type) {
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

static void(*destructors[CORTO_MAX_OLS_KEY])(void*);

static void corto_olsDestroy(corto__scope *scope) {
    if (scope->ols) {
        corto__ols *ols = scope->ols;
        do {
            if (destructors[ols->key]) {
                destructors[ols->key](ols->value);
            }
        } while ((ols++)->key);
        corto_dealloc(scope->ols);
        scope->ols = NULL;
    }
}

/* Generate a new OLS key */
corto_uint8 corto_olsKey(void(*destructor)(void*)) {
    static int olsKeys;
    corto_uint32 result;

    result = corto_ainc(&olsKeys);
    if (result > 255) {
        corto_seterr("maximum number of extensions exceeded");
        result = 0;
    } else {
        destructors[result] = destructor;
    }

    return result;
}

/* Find OLS value (assumes scope is locked) */
void* corto_olsFind(corto__scope *scope, corto_int8 key) {
    corto__ols *ols = scope->ols;
    if (ols) {
        do {
            if (ols->key == key) break;
        } while ((ols++)->key);
        return ols->key ? ols : NULL;
    } else {
        return NULL;
    }
}

static corto_uint8 corto_olsSize(corto__scope *scope) {
    corto_uint8 result = 0;
    corto__ols *ols = scope->ols;
    if (ols) {
        do {
        } while ((ols++)->key);
        result = ols - scope->ols - 1;
    }
    return result;
}

/* Set an OLS value */
void* corto_olsSet(corto_object o, corto_int8 key, void *value) {
    corto__object* _o;
    corto__scope* scope;
    void *old = NULL;

    _o = CORTO_OFFSET(o, -sizeof(corto__object));
    scope = corto__objectScope(_o);
    if (scope) {
        corto__ols *ols = NULL;

        if (corto_rwmutexWrite(&scope->scopeLock)) {
            corto_seterr("aquiring scopelock failed");
            goto error;
        }

        ols = corto_olsFind(scope, key);
        if (ols) {
            old = ols->value;
        } else {
            corto_uint8 size = corto_olsSize(scope);
            scope->ols = corto_realloc(scope->ols,
                (size + 1) * sizeof(corto__ols));
            ols = &scope->ols[size];
            ols->key = key;
        }
        ols->value = value;

        corto_rwmutexUnlock(&scope->scopeLock);
    } else {
        corto_seterr("object is not scoped");
        goto error;
    }

    return old;
error:
    return NULL;
}

/* Get an OLS value */
void* corto_olsGet(corto_object o, corto_int8 key) {
    corto__object* _o;
    corto__scope* scope;
    void *result = NULL;

    _o = CORTO_OFFSET(o, -sizeof(corto__object));
    scope = corto__objectScope(_o);
    if (scope) {
        corto__ols *ols = NULL;
        if (corto_rwmutexWrite(&scope->scopeLock)) {
            corto_seterr("aquiring scopelock failed");
            goto error;
        }

        ols = corto_olsFind(scope, key);
        if (ols) {
            result = ols->value;
        }

        corto_rwmutexUnlock(&scope->scopeLock);
    } else {
        corto_seterr("object is not scoped");
        goto error;
    }

    return result;
error:
    return NULL;
}

void* corto_olsLockGet(corto_object o, corto_int8 key) {
    corto__object* _o;
    corto__scope* scope;
    void **result = NULL;

    _o = CORTO_OFFSET(o, -sizeof(corto__object));
    scope = corto__objectScope(_o);
    if (scope) {
        corto__ols *ols = NULL;
        if (corto_rwmutexWrite(&scope->scopeLock)) {
            corto_seterr("aquiring scopelock failed");
            goto error;
        }

        ols = corto_olsFind(scope, key);
        if (!ols) {
            corto_uint8 size = corto_olsSize(scope);
            scope->ols = corto_realloc(scope->ols,
                (size + 2) * sizeof(corto__ols));
            scope->ols[size + 1].key = 0; /* Marks end of list */
            ols = &scope->ols[size];
            ols->key = key;
            ols->value = NULL;
        }

        result = ols->value;
    } else {
        corto_seterr("object is not scoped");
        goto error;
    }

    return result;
error:
    return NULL;
}

void corto_olsUnlockSet(corto_object o, corto_int8 key, void *value) {
    corto__object* _o;
    corto__scope* scope;

    _o = CORTO_OFFSET(o, -sizeof(corto__object));
    scope = corto__objectScope(_o);
    if (scope) {
        corto__ols *ols = corto_olsFind(scope, key);
        if (ols) {
            ols->value = value;
        }
        corto_rwmutexUnlock(&scope->scopeLock);
    } else {
        corto_seterr("object is not scoped");
    }
}

/* Get & lock scope */
corto__scope *corto__scopeClaim(corto_object o) {
    corto__object  *_o = CORTO_OFFSET(o, -sizeof(corto__object));
    corto__scope *scope = corto__objectScope(_o);
    if (scope) {
        if (corto_rwmutexRead(&scope->scopeLock)) {
            corto_seterr("aquiring scopelock failed");
            goto error;
        }
    }
    return scope;
error:
    return NULL;
}

/* Release scope */
void corto__scopeRelease(corto_object o) {
    corto__object  *_o = CORTO_OFFSET(o, -sizeof(corto__object));
    corto__scope *scope = corto__objectScope(_o);
    if (scope) {
        corto_rwmutexUnlock(&scope->scopeLock);
    }
}

/* Get parent (requires scoped object) */
corto_object corto_parentof(corto_object o) {
    corto__object* _o;
    corto__scope* scope;
    corto_object result;

    result = NULL;
    _o = CORTO_OFFSET(o, -sizeof(corto__object));
    scope = corto__objectScope(_o);
    if (scope) {
        result = scope->parent;
    } else {
        goto err_not_scoped;
    }

    return result;
err_not_scoped:
    corto_critical("corto_parentof: object %p is not scoped.", o);
    return NULL;
}

/* Get name (requires scoped object) */
corto_string corto_nameof(corto_object o) {
    corto__object* _o;
    corto__scope* scope;
    corto_string result;

    result = NULL;
    _o = CORTO_OFFSET(o, -sizeof(corto__object));
    scope = corto__objectScope(_o);
    if (scope) {
        result = scope->name;
    } else {
        goto err_not_scoped;
    }

    return result;
err_not_scoped:
    corto_critical("corto_nameof: object %p is not scoped.", o);
    return NULL;
}

/* Get scope tree */
corto_rbtree corto_scopeof(corto_object o) {
    corto__object* _o;
    corto__scope* scope;
    corto_rbtree result;

    result = NULL;
    _o = CORTO_OFFSET(o, -sizeof(corto__object));
    scope = corto__objectScope(_o);
    if (scope) {
        result = scope->scope;
    } else {
        goto err_not_scoped;
    }

    return result;
err_not_scoped:
    corto_critical("corto_nameof: object %p is not scoped.", o);
    return NULL;
}

corto_uint32 corto_scopeSize(corto_object o) {
    corto__object* _o;
    corto__scope* scope;
    corto_rbtree tree;
    corto_uint32 result;

    result = 0;

    _o = CORTO_OFFSET(o, -sizeof(corto__object));
    scope = corto__objectScope(_o);
    if (scope) {
        tree = scope->scope;
        if (tree) {
            result = corto_rbtreeSize(tree);
        }
    } else {
        goto err_not_scoped;
    }

    return result;
err_not_scoped:
    corto_error("corto_scopeof: object <%p> is not scoped", o);
    return 0;
}

/* Walk objects in scope */
corto_int16 corto_scopeWalk(corto_object o, corto_scopeWalkAction action, void* userData) {
    corto_int16 result;
    corto__scope* scope;

    if (!o) {
        o = root_o;
    }

    result = 1;
    scope = corto__objectScope(CORTO_OFFSET(o, -sizeof(corto__object)));
    if (scope) {
        if (scope->scope) {
            corto_rwmutexRead(&scope->scopeLock);
            result = corto_rbtreeWalk(scope->scope, (corto_walkAction)action, userData);
            corto_rwmutexUnlock(&scope->scopeLock);
        }
    }

    return result;
}

/* Obtain scoped identifier (serves as global unique identifier) */
corto_string corto_fullpath(corto_id buffer, corto_object o) {
    corto_object stack[CORTO_MAX_SCOPE_DEPTH];
    corto_uint32 depth;
    corto_string name;
    corto_char* ptr;
    corto_uint32 len;
    corto_bool threadStr = FALSE;

    depth = 0;

    if (!o) {
        o = root_o;
    }

    if (!buffer) {
        buffer = corto_alloc(sizeof(corto_id));
        threadStr = TRUE;
    }

    if (!corto_checkAttr(o, CORTO_ATTR_SCOPED)) {
        sprintf(buffer, "<%p>", o);
    } else {
        do {
            stack[depth++] = o;
        }while((o = corto_parentof(o)));

        ptr = buffer;
        if (depth == 1) {
            *ptr = '/';
            ptr += 1;
        } else {
            while(depth) {
                depth--;
                o = stack[depth];

                if ((name = corto_nameof(o))) {
                    /* Copy scope operator */
                    *ptr = '/';
                    ptr += 1;

                    /* Copy name */
                    len = strlen(name);
                    memcpy(ptr, name, len + 1);
                    ptr += len;
                }
            }
        }
        *ptr = '\0';
    }

    if (threadStr) {
        corto_string tmp = buffer;
        buffer = corto_setThreadString(buffer);
        corto_dealloc(tmp);
    }

    return buffer;
}

static corto_object* corto_scopeStack(
    corto_object o,
    corto_object scopeStack[],
    corto_uint32 *length)
{
    corto_object ptr;
    corto_uint32 i;

    ptr = o;
    i = 0;
    while(ptr) {
        scopeStack[i] = ptr;
        ptr = corto_parentof(ptr);
        i++;
    }
    scopeStack[i] = NULL;
    if (length) {
        *length = i;
    }

    return scopeStack;
}

corto_string corto_path(
    corto_id buffer,
    corto_object from,
    corto_object o,
    const char *sep)
{
    corto_object from_s[CORTO_MAX_SCOPE_DEPTH];
    corto_object o_s[CORTO_MAX_SCOPE_DEPTH];
    corto_uint32 from_i, o_i;
    corto_char* ptr;
    corto_uint32 length;
    corto_bool reverse = FALSE;
    corto_uint32 count = 0;
    corto_bool threadStr = FALSE;

    corto_assert(o != NULL, "corto_path called with NULL for parameter 'to'.");

    if (o == NULL) {
        corto_seterr("NULL passed to corto_path");
        goto error;
    }

    if (!buffer) {
        buffer = corto_alloc(sizeof(corto_id));
        threadStr = TRUE;
    }

    buffer[0] = '\0';

    if (!from) {
        strcpy(buffer, sep);
        from = root_o;
    }

    if (from == o) {
        strcpy(buffer, ".");
    } else {
        corto_scopeStack(from, from_s, &from_i);
        corto_scopeStack(o, o_s, &o_i);

        if (from_i > o_i) {
            reverse = TRUE; /* from is in scope of o */
        }

        do {
            from_i--;
            o_i--;
            if (!o_i || !from_i) {
                break;
            }
        } while(from_s[from_i] == o_s[o_i]);

        if (!reverse) {
            count = o_i;
        } else {
            count = from_i;
        }

        if (from_s[from_i] == o_s[o_i]) {
            if (count) {
                count--;
            }
        }

        ptr = &buffer[strlen(buffer)];
        while(count) {
            if (!reverse) {
                length = strlen(corto_nameof(o_s[count]));
                memcpy(ptr, corto_nameof(o_s[count]), length);
            } else {
                length = 2;
                memcpy(ptr, "..", 2);
            }
            ptr += length;
            strcpy(ptr, sep);
            ptr += strlen(sep);
            count--;
        }
        if (!reverse) {
            length = strlen(corto_nameof(o_s[count]));
            memcpy(ptr, corto_nameof(o_s[count]), length);
        } else {
            length = 2;
            memcpy(ptr, "..", 2);
        }
        ptr += length;
        *ptr = '\0';
    }

    if (threadStr) {
        corto_string tmp = buffer;
        buffer = corto_setThreadString(buffer);
        corto_dealloc(tmp);
    }

    return buffer;
error:
    return NULL;
}

static char *strsep(char **str, char delim) {
    char *result = *str;
    if (result) {
        char *ptr = strchr(result, delim);
        if (ptr) {
            *ptr = 0;
            (*str) = ptr + 1;
        } else {
            *str = NULL;
        }
    }
    return result;
}

corto_string corto_cleanpath(corto_id path) {
    corto_id work;
    char *cp, *thisp, *nextp = work;
    corto_id buf;

    cp = strchr(path, '/');

    /* no '/' characters - return as-is */
    if (cp == NULL) {
        return path;
    }

    /* copy leading slash if present */
    if (cp == path) {
        strcpy(buf, "/");
    } else {
        buf[0] = '\0';
    }

    /* tokenization */
    strcpy(work, path);
    while ((thisp = strsep(&nextp, '/')) != NULL) {
        if (*thisp == '\0') continue;

        if (strcmp(thisp, ".") == 0) continue;

        if (strcmp(thisp, "..") == 0) {
            cp = strrchr(buf, '/');

             /* "/" or "/foo" */
            if (cp == buf) {
                buf[1] = '\0';
                continue;
            }

            /* "..", "foo", or "" */
            else if (cp == NULL) {
                if (buf[0] != '\0' && strcmp(buf, "..") != 0) {
                    buf[0] = '\0';
                    continue;
                }
            }
            /* ".../foo" */
            else {
                *cp = '\0';
                continue;
            }
        }

        if (buf[0] != '\0' && buf[strlen(buf) - 1] != '/') {
            strcat(buf, "/");
        }

        strcat(buf, thisp);
    }

    if (buf[0] == '\0') strcpy(buf, ".");

    strcpy(path, buf);

    return path;
}

corto_object corto_ownerof(corto_object o) {
    corto__object* _o;
    corto__persistent* persistent;
    corto_object result = NULL;

    if (corto_checkAttr(o, CORTO_ATTR_PERSISTENT)) {
        _o = CORTO_OFFSET(o, -sizeof(corto__object));
        persistent = corto__objectPersistent(_o);
        result = persistent->owner;
    }

    return result;
}

corto_bool corto_owned(corto_object o) {
    corto_object owner = corto_ownerof(o);
    corto_object current = corto_getOwner();

    if (owner == current) {
        return TRUE;
    } else {
        if (!current && owner) {
            return !corto_instanceof(corto_replicator_o, owner);
        } else {
            return FALSE;
        }
    }
}

corto_int32 corto_claim_ext(corto_object src, corto_object o, corto_string context) {
    corto__object* _o;
    corto_uint32 i;
    CORTO_UNUSED(src);
    CORTO_UNUSED(context);

    _o = CORTO_OFFSET(o, -sizeof(corto__object));
    i = corto_ainc(&_o->refcount);

    if (CORTO_TRACE_OBJECT) corto_memtrace("claim", o, context);

    return i;
}

corto_int32 corto_release_ext(corto_object src, corto_object o, corto_string context) {
    corto_int32 i;
    corto__object* _o;
    CORTO_UNUSED(src);
    CORTO_UNUSED(context);

    _o = CORTO_OFFSET(o, -sizeof(corto__object));
    i = corto_adec(&_o->refcount);

    if (CORTO_TRACE_OBJECT) corto_memtrace("release", o, context);
    if (CORTO_TRACE_OBJECT) corto_memtracePush();

    if (!i) {
        corto_destruct(o, FALSE);
    } else if (i < 0) {
        corto_critical("negative reference count of object (%p) '%s' of type '%s'",
            o, corto_fullpath(NULL, o), corto_fullpath(NULL, corto_typeof(o)));
        corto_backtrace(stdout);
    }
    if (CORTO_TRACE_OBJECT) corto_memtracePop();

    return i;
}

corto_int32 corto_claim(corto_object o) {
    return corto_claim_ext(NULL, o, NULL);
}

corto_int32 corto_release(corto_object o) {
    return corto_release_ext(NULL, o, NULL);
}

corto_object corto_lookupLowercase(corto_object o, corto_string name) {
    corto_object result;
    corto__object *_o, *_result;
    corto__scope* scope;
    corto_rbtree tree;

    if (!o) {
        o = root_o;
    }

    _o = CORTO_OFFSET(o, -sizeof(corto__object));
    scope = corto__objectScope(_o);

    if (scope) {
        corto_rwmutexRead(&scope->scopeLock);
        if ((tree = scope->scope)) {
            if ((!corto_rbtreeHasKey_w_cmp(tree, name, (void**)&result, corto_compareLookup))) {
                result = NULL;
            } else {
                /* If an object was returned with a ( in its name but
                 * the request didn't have one, check scope again for an object
                 * that matches the request exactly */
                if (strchr(corto_nameof(result), '(') && !strchr(name, '(')) {
                    corto_object checkNoArgs = NULL;
                    if (corto_rbtreeHasKey_w_cmp(tree, name, (void**)&checkNoArgs, corto_compareLookupNoArgMatching)) {
                        result = checkNoArgs;
                    }
                }

                /* Keep object. If the refcount was zero, this object will be deleted soon, so prevent the object from being referenced again. */
                if (corto_claim(result) == 1) {
                     /* Set the refcount to zero again. There can be no more objects that are looking up this object right now because
                      * we have the scopeLock of the parent. Additionally, the object will not yet have been free'd because the destruct
                      * function also needs the parent's scopelock to remove the object from the scope.
                      *
                      * The refcount needs to be re-set to zero, because after the scopeLock is released, other threads - other than the destruct
                      * thread might try to acquire this object. Setting the refcount back to zero will enable these lookups to also detect
                      * that the object is being deleted.
                      */
                    _result = CORTO_OFFSET(result, -sizeof(corto__object));
                    _result->refcount = 0;
                    result = NULL;
                }
            }
        } else {
            result = NULL;
        }
        corto_rwmutexUnlock(&scope->scopeLock);
    } else {
        corto_seterr("corto_lookup: object '%s' has no scope",
            corto_fullpath(NULL, o));
        goto error;
    }

    return result;
error:
    return NULL;
}

corto_object corto_lookup(corto_object o, corto_string name) {
    corto_id lower; *lower = '\0';
    char *ptr = name, ch;
    char *bptr = lower;
    if (name) {
        for(; (ch = *ptr); ptr++) *(bptr++) = tolower(ch);
        *bptr = '\0';
    }
    return corto_lookupLowercase(o, lower);
}

/* Event handling. */
static corto__observer* corto_observerFind(corto_ll on, corto_observer observer, corto_object this) {
    corto__observer* result;
    corto_iter iter;

    result = NULL;

    if (on) {
        iter = corto_llIter(on);
        while(corto_iterHasNext(&iter)) {
            result = corto_iterNext(&iter);
            if ((result->observer == observer) && (result->_this == this)) {
                break;
            } else {
                result = NULL;
            }
        }
    }

    return result;
}

/* Copyout observers */
static void corto_observersCopyOut(corto_ll list, corto__observer** observers) {
    corto_iter iter;
    corto_uint32 i;

    iter = corto_llIter(list);
    i = 0;
    while(corto_iterHasNext(&iter)) {
        observers[i] = corto_iterNext(&iter);
        observers[i]->count++;
        i++;
    }
    observers[i] = NULL;
}

/* Free observer-array */
static void corto_observersFree(corto__observer** observers) {
    corto__observer* observer;
    while((observer = *observers)) {
        if (!corto_adec(&observer->count)) {
            corto_dealloc(observer);
        }
        ++observers;
    }
}

/* Create observer-array */
static corto__observer** corto_observersArrayNew(corto_ll list) {
    corto__observer** array;

    array = corto_alloc((corto_llSize(list) + 1) * sizeof(corto__observer*));
    corto_observersCopyOut(list, array);

    /* Observers start from the second element */
    return array;
}

/* There is a small chance that a thread simultaneously with corto_listen obtains a pointer
 * to an old observers-array, then gets scheduled out and this function in another thread
 * deletes that array. Although unlikely this scenario must be addressed. */
static void corto_observersArrayFree(corto__observer** array) {
    if (array) {
        corto_observersFree(array);
        corto_dealloc(array);
    }
}

#ifndef NDEBUG
static corto_uint32 indent = 0;
#endif

/* Notify one observer */
static void corto_notifyObserver(corto__observer *data, corto_object observable, corto_object source, corto_uint32 mask, int depth) {
    corto_observer observer = data->observer;
    corto_eventMask observerMask = data->mask;

    if ((mask & observerMask) && (!depth || (observerMask & CORTO_ON_TREE))) {
        corto_dispatcher dispatcher = data->dispatcher;

#ifndef NDEBUG
        if (CORTO_TRACE_NOTIFICATIONS) {
            printf("%*s [notify] observable '%s' observer '%s' me '%s'\n",
                indent * 3, "",
                corto_fullpath(NULL, observable),
                corto_fullpath(NULL, observer),
                corto_fullpath(NULL, data->_this));
            indent++;
        }
#endif

        if (!dispatcher) {
            corto_object this = data->_this;
            if (!this || (this != corto_getOwner())) {
                corto_function f = corto_function(observer);
                corto_call(f, NULL, this, observable);
            }
        } else {
            if (!data->_this || (data->_this != source)) {
                corto_attr oldAttr = corto_setAttr(0);
                corto_observableEvent event = corto_declare(corto_type(corto_observableEvent_o));
                corto_setAttr(oldAttr);

                corto_setref(&event->observer, observer);
                corto_setref(&event->me, data->_this);
                corto_setref(&event->observable, observable);
                corto_setref(&event->source, source);
                event->mask = mask;

                /* Set thread handle so the dispatcher can figure out whether a
                 * readlock is needed */
                event->thread = corto_threadSelf();

                corto_dispatcher_post(dispatcher, corto_event(event));
            }
        }
#ifndef NDEBUG
        indent--;
#endif
    }
}

/* If an observer is subscribed to NEW events align it with existing objects so that
 * an observer doesn't need to do an object-walk over the observable manually to discover
 * all objects.
 */
typedef struct corto_observerAlignData {
    corto__observer *observer;
    corto_object observable;
    int mask;
    int depth;
} corto_observerAlignData;

int corto_observerAlignScope(corto_object o, void *userData) {
    corto_observerAlignData *data = userData;

    if ((data->mask & CORTO_ON_DECLARE) && (data->mask & (CORTO_ON_SCOPE|CORTO_ON_TREE)))
    {
        corto_notifyObserver(data->observer, o, o, CORTO_ON_DECLARE, data->depth);
    }

    if ((data->mask & CORTO_ON_DEFINE) && (data->mask & (CORTO_ON_SCOPE|CORTO_ON_TREE)) &&
        corto_checkState(o, CORTO_DEFINED))
    {
        corto_notifyObserver(data->observer, o, o, CORTO_ON_DEFINE, data->depth);
    }

    if (data->mask & CORTO_ON_TREE) {
        int result = 1;
        corto_objectseq scope;
        corto_uint32 i;
        data->depth++;
        scope = corto_scopeClaim(o);
        for(i = 0; i < scope.length; i++) {
            result = corto_observerAlignScope(scope.buffer[i], userData);
        }
        corto_scopeRelease(scope);
        data->depth--;
        return result;
    } else {
        return 1;
    }
}

void corto_observerAlign(corto_object observable, corto__observer *observer, int mask) {
    corto_observerAlignData walkData;
    corto_objectseq scope;

    /* Do recursive walk over scope */
    walkData.observable = observable;
    walkData.observer = observer;
    walkData.mask = mask;
    walkData.depth = 0;

    if (((mask & CORTO_ON_DECLARE) && (mask & CORTO_ON_SELF) && corto_checkState(observable, CORTO_DECLARED)) ||
        ((mask & CORTO_ON_DEFINE) && (mask & CORTO_ON_SELF) && corto_checkState(observable, CORTO_DEFINED))) {
        corto_notifyObserver(observer, observable, observable, mask, 0);
    }

    scope = corto_scopeClaim(observable);
    corto_objectseqForeach(scope, o) {
        corto_observerAlignScope(o, &walkData);
    }
    corto_scopeRelease(scope);
}

/* Add observer to observable */
corto_int16 corto_listen(corto_object this, corto_observer observer, corto_eventMask mask, corto_object observable, corto_dispatcher dispatcher) {
    corto__observer* _observerData = NULL;
    corto__observable* _o;
    corto_bool added;
    corto__observer **oldSelfArray = NULL, **oldChildArray = NULL;

    if (!observable) {
        observable = root_o;
    }

    if (!mask) {
        mask = observer->mask;
    }

    /* Check if mask specifies either SELF or CHILDS, if not enable SELF */
    if (!(mask & (CORTO_ON_SELF|CORTO_ON_SCOPE|CORTO_ON_TREE))) {
        mask |= CORTO_ON_SELF;
    }

    /* Check if mask specifies either VALUE or METAVALUE, if not enable VALUE */
    if (!((mask & CORTO_ON_VALUE) || (mask & CORTO_ON_METAVALUE))) {
        mask |= CORTO_ON_VALUE;
    }

    /* Test for error conditions before making changes */
    if (mask & (CORTO_ON_SCOPE|CORTO_ON_TREE)) {
        if (!corto_checkAttr(observable, CORTO_ATTR_SCOPED)) {
            corto_seterr(
                "cannot listen to scope of non-scoped observable '%s' (observer %s)",
                corto_fullpath(NULL, observable),
                corto_fullpath(NULL, observer));
            goto error;
        }
    }

    if (!corto_checkAttr(observable, CORTO_ATTR_OBSERVABLE)) {
        corto_seterr(
            0,
            "object '%s' is not an observable",
            corto_fullpath(NULL, observable));
        goto error;
    }

    _o = corto__objectObservable(
        CORTO_OFFSET(observable, -sizeof(corto__object)));

#ifndef NDEBUG
        if (CORTO_TRACE_NOTIFICATIONS) {
            printf("%*s [listen] observable '%s' observer '%s' me '%s'%s%s%s%s%s%s%s\n",
                indent * 3, "",
                corto_fullpath(NULL, observable),
                corto_fullpath(NULL, observer),
                corto_fullpath(NULL, this),
                mask & CORTO_ON_SELF ? " self" : "",
                mask & CORTO_ON_SCOPE ? " scope" : "",
                mask & CORTO_ON_TREE ? " tree" : "",
                mask & CORTO_ON_DECLARE ? " declare" : "",
                mask & CORTO_ON_DEFINE ? " define" : "",
                mask & CORTO_ON_UPDATE ? " update" : "",
                mask & CORTO_ON_DELETE ? " delete" : "");
        }
#endif

    /* Create observerData */
    _observerData = corto_alloc(sizeof(corto__observer));
    _observerData->observer = observer;
    _observerData->_this = this;
    _observerData->count = 0;
    _observerData->mask = mask;
    _observerData->dispatcher = dispatcher;

    added = FALSE;

    /* If observer must trigger on updates of me, add it to onSelf list */
    if (mask & CORTO_ON_SELF) {
        corto_rwmutexWrite(&_o->selfLock);
        if (!corto_observerFind(_o->onSelf, observer, this)) {
            if (!_o->onSelf) {
                _o->onSelf = corto_llNew();
            }
            corto_llAppend(_o->onSelf, _observerData);
            _observerData->count++;
            added = TRUE;

            /* Build new observer array. This array can be accessed without
             * locking and is faster than walking the linked list. */
            oldSelfArray = _o->onSelfArray;
            _o->onSelfArray = corto_observersArrayNew(_o->onSelf);
        }
        corto_rwmutexUnlock(&_o->selfLock);
    }

    /* If observer must trigger on updates of childs, add it to onChilds list */
    if (mask & (CORTO_ON_SCOPE|CORTO_ON_TREE)) {
        corto_rwmutexWrite(&_o->childLock);
        if (!corto_observerFind(_o->onChild, observer, this)) {
            if (!_o->onChild) {
                _o->onChild = corto_llNew();
            }

            corto_llAppend(_o->onChild, _observerData);
            _observerData->count++;
            added = TRUE;

            /* Build new observer array. This array can be accessed without
             * locking and is faster than walking a linked list. */
            oldChildArray = _o->onChildArray;
            _o->onChildArray = corto_observersArrayNew(_o->onChild);
        }
        corto_rwmutexUnlock(&_o->childLock);
    }

    if (!added) {
        corto_dealloc(_observerData);
    } else {
        /* If observer is subscribed to declare/define events, align observer
         * with existing */
        if ((mask & CORTO_ON_DECLARE) || (mask & CORTO_ON_DEFINE)) {
            corto_observerAlign(observable, _observerData, mask);
        }
    }

    /* From this point onwards the old observer arrays are no longer accessible.
     * However, since notifications can still be in progress these arrays can't
     * be deleted yet. Therefore wait until the arrays are no longer being
     * used.
     *
     * The administration where this information is stored is not protected by
     * locking so that notifying objects can remain lock-free. There is however
     * a slight chance that a notification pushed the old array to the
     * administration but that this change is not yet visible due to a number of
     * issues w.r.t. concurrency. In this case the functions below will assume
     * the array is unused, which is incorrect.
     *
     * To be absolutely sure that the observed administration is up to date a
     * memory barrier is required here. A simple mutex will not do since this
     * would encumber the notifications too much.
     */
     /*__atomic_thread_fence (__ATOMIC_SEQ_CST);*/

    if (corto_observersWaitForUnused(oldSelfArray)) {
        corto_observersArrayFree(oldSelfArray);
    }
    if (corto_observersWaitForUnused(oldChildArray)) {
        corto_observersArrayFree(oldChildArray);
    }

    return 0;
error:
    return -1;
}

/* Remove observer from observable - TODO update parentObservers. */
corto_int16 corto_silence(corto_object this, corto_observer observer, corto_eventMask mask, corto_object observable) {
    corto__observer* observerData;
    corto__observable* _o;
    corto__observer **oldSelfArray = NULL, **oldChildArray = NULL;

    if (!observable) {
        observable = root_o;
    }

    if (!mask) {
        mask = observer->mask;
    }

    if (corto_checkAttr(observable, CORTO_ATTR_OBSERVABLE)) {
        _o = corto__objectObservable(CORTO_OFFSET(observable, -sizeof(corto__object)));
        observerData = NULL;

        /* If observer triggered on updates of me, remove from onSelf list */
        if (mask & CORTO_ON_SELF) {
            corto_rwmutexWrite(&_o->selfLock);
            observerData = corto_observerFind(_o->onSelf, observer, this);
            if (observerData) {
                corto_llRemove(_o->onSelf, observerData);
                observerData->count--;

                /* Build new observer array */
                oldSelfArray = _o->onSelfArray;
                _o->onSelfArray = corto_observersArrayNew(_o->onSelf);

#ifndef NDEBUG
                if (CORTO_TRACE_NOTIFICATIONS) {
                    printf("%*s [silence] observable '%s' observer '%s' me '%s'\n",
                        indent * 3, "",
                        corto_fullpath(NULL, observable),
                        corto_fullpath(NULL, observer),
                        corto_fullpath(NULL, this));
                }
#endif

            } else {
                if (this) {
                    corto_seterr("observer '%s' ('%s') is not observing '%s'",
                            corto_fullpath(NULL, observer),
                            corto_fullpath(NULL, this),
                            corto_fullpath(NULL, observable));
                    goto error;
                } else {
                    corto_seterr("observer '%s' is not observing '%s'",
                        corto_fullpath(NULL, observer),
                        corto_fullpath(NULL, observable));
                    goto error;
                }
            }
            corto_rwmutexUnlock(&_o->selfLock);
        }

        /* If observer triggered on updates of childs, remove from onChilds list */
        if (mask & (CORTO_ON_SCOPE|CORTO_ON_TREE)) {
            if (corto_checkAttr(observable, CORTO_ATTR_SCOPED)) {
                corto_rwmutexWrite(&_o->childLock);
                observerData = corto_observerFind(_o->onChild, observer, this);
                if (observerData) {
                    corto_llRemove(_o->onChild, observerData);
                    observerData->count--;

                    /* Build new observer array */
                    oldChildArray = _o->onChildArray;
                    _o->onChildArray = corto_observersArrayNew(_o->onChild);
                } else {
                    if (this) {
                        corto_seterr("observer '%s' ('%s') is not observing '%s'",
                            corto_fullpath(NULL, observer),
                            corto_fullpath(NULL, this),
                            corto_fullpath(NULL, observable));
                        goto error;
                    } else {
                        corto_seterr("observer '%s' is not observing '%s'",
                            corto_fullpath(NULL, observer),
                            corto_fullpath(NULL, observable));
                        goto error;
                    }
                }
                corto_rwmutexUnlock(&_o->childLock);
            } else {
                corto_seterr(
                    "corto::listen: observer subscribed on childs of non-scoped object");
                goto error;
            }
        }
    } else {
        corto_seterr("object '%s' is not an observable",
            corto_fullpath(NULL, observable));
        goto error;
    }

    /* See comments in corto_listen */
    /*__atomic_thread_fence (__ATOMIC_SEQ_CST);*/

    if (corto_observersWaitForUnused(oldSelfArray)) {
        corto_observersArrayFree(oldSelfArray);
    }
    if (corto_observersWaitForUnused(oldChildArray)) {
        corto_observersArrayFree(oldChildArray);
    }
    /*if (observerData) {
        TODO: corto_dealloc(observerData);
    }*/

    return 0;
error:
    return -1;
}

corto_bool corto_listening(corto_object observable, corto_observer observer, corto_object this) {
    corto__observer* observerData;
    corto__observable* _o;
    corto_bool result = FALSE;

    _o = corto__objectObservable(CORTO_OFFSET(observable, -sizeof(corto__object)));
    observerData = NULL;

    /* If observer triggered on updates of me, remove from onSelf list */
    if (_o) {
        if (observer->mask & CORTO_ON_SELF) {
            corto_rwmutexWrite(&_o->selfLock);
            observerData = corto_observerFind(_o->onSelf, observer, this);
            if (observerData) {
                result = TRUE;
            }
            corto_rwmutexUnlock(&_o->selfLock);
        }

        if (!result) {
            if (corto_checkAttr(observable, CORTO_ATTR_OBSERVABLE)) {
                if (observer->mask & CORTO_ON_SCOPE) {
                    if (corto_checkAttr(observable, CORTO_ATTR_SCOPED)) {
                        corto_rwmutexWrite(&_o->childLock);
                        observerData = corto_observerFind(_o->onChild, observer, this);
                        if (observerData) {
                            result = TRUE;
                        }
                        corto_rwmutexUnlock(&_o->childLock);
                    }
                }
            } else {
                corto_seterr("object '%s' is not an observable",
                    corto_fullpath(NULL, observable));
                goto error;
            }
        }
    }

    return result;
error:
    return FALSE;
}

static void corto_notifyObservers(corto__observer** observers, corto_object observable, corto_object source, corto_uint32 mask, int depth) {
    corto__observer* data;
    corto_uint32 i = 0;

    if (!observers) {
        return;
    }

    while((data = *observers)) {
        i++;
        corto_notifyObserver(data, observable, source, mask, depth);
        observers++;
    }
}

corto_object corto_setOwner(corto_object source) {
    corto_object result = NULL;
    corto_observerAdmin *admin = corto_observerAdminGet();
    result = admin->from;
    admin->from = source;
    return result;
}

corto_object corto_getOwner() {
    corto_object result = NULL;
    corto_observerAdmin *admin = corto_observerAdminGet();
    result = admin->from;
    return result;
}

static corto_int32 corto_notify(corto__observable* _o, corto_object observable, corto_uint32 mask) {
    corto_object *parent;
    corto_object this = NULL;
    corto__observer **observers;
    int depth = 0;

    /* Notify direct observers */
    if (_o) {

        /* Notify observers of observable */
        observers = corto_observersPush(&_o->onSelfArray, &this);
        corto_notifyObservers(observers, observable, this, mask, 0);
        if (corto_observersPop()) {
            corto_observersArrayFree(observers);
        }
    }

    /* Bubble event up in hierarchy */
    if (corto_checkAttr(observable, CORTO_ATTR_SCOPED)) {
        parent = observable;
        while((parent = corto_parentof(parent))) {
            corto__observable *_parent = corto__objectObservable(
                CORTO_OFFSET(parent, -sizeof(corto__object)));

            /* Notify observers of parent */
            if (_parent) {
                observers = corto_observersPush(&_parent->onChildArray, NULL);
                corto_notifyObservers(observers, observable, this, mask, depth);
                if (corto_observersPop()) {
                    corto_observersArrayFree(observers);
                }
            }
            depth++;
        }
    }

    return 0;
}

/* Update object */
corto_int16 corto_update(corto_object o) {
    corto__observable *_o;

    if (corto_typeof(o)->kind != CORTO_VOID) {
        corto_seterr("use updateBegin/updateEnd for non-void objects");
        goto error;
    }

    if (!corto_owned(o)) {
        corto_seterr("cannot update '%s', process does not own object",
            corto_nameof(o));
        goto error;
    }

    _o = corto__objectObservable(CORTO_OFFSET(o, -sizeof(corto__object)));
    if (corto_notify(_o, o, CORTO_ON_UPDATE)) {
        goto error;
    }

    return 0;
error:
    return -1;
}

corto_int16 corto_updateBegin(corto_object o) {
    corto__observable *_o;
    corto__writable* _wr;

    if (!corto_checkState(o, CORTO_DEFINED)) {
        corto_seterr("cannot update undefined object");
        goto error;
    }

    if (!corto_owned(o)) {
        corto_seterr("cannot update '%s', process does not own object",
            corto_nameof(o));
        goto error;
    }

    _o = corto__objectObservable(CORTO_OFFSET(o, -sizeof(corto__object)));

    if (_o) {
        _wr = corto__objectWritable(CORTO_OFFSET(o, -sizeof(corto__object)));
        if (_wr) {
            if (corto_rwmutexWrite(&_wr->lock)) {
                corto_seterr("updateBegin: writelock on '%s' failed (%s)",
                    corto_fullpath(NULL, o), corto_lasterr());
                goto error;
            }
        } else {
            corto_warning(
                "calling updateBegin for non-writable '%s' is useless",
                corto_fullpath(NULL, o));
        }
    }

    return 0;
error:
    return -1;
}

corto_int16 corto_updateTry(corto_object observable) {
    corto__writable* _wr;

    _wr = corto__objectWritable(CORTO_OFFSET(observable, -sizeof(corto__object)));
    if (_wr) {
        if (corto_rwmutexTryWrite(&_wr->lock) == CORTO_LOCK_BUSY) {
            goto busy;
        }
    } else {
        corto_warning("calling updateTry for non-writable object '%s' is useless.",
            corto_fullpath(NULL, observable));
    }

    return 0;
busy:
    return CORTO_LOCK_BUSY;
}

void corto_updateEnd(corto_object observable) {
    corto__writable* _wr;
    corto__observable *_o;

    _o = corto__objectObservable(CORTO_OFFSET(observable, -sizeof(corto__object)));

    if (corto_notify(_o, observable, CORTO_ON_UPDATE)) {
        corto_assert(0, "notify failed");
    }

    if (_o) {
        _wr = corto__objectWritable(CORTO_OFFSET(observable, -sizeof(corto__object)));
        if (_wr) {
            if (corto_rwmutexUnlock(&_wr->lock)) {
                corto_seterr("updateEnd: unlock on '%s' failed (%s)",
                  corto_fullpath(NULL, observable), corto_lasterr());
            }
        }
    }
}

corto_int16 corto_updateCancel(corto_object observable) {

    if (corto_checkAttr(observable, CORTO_ATTR_OBSERVABLE)) {
        corto__writable* _wr;

        _wr = corto__objectWritable(CORTO_OFFSET(observable, -sizeof(corto__object)));

        if (corto_rwmutexUnlock(&_wr->lock)) {
            corto_seterr("updateCancel: unlock on '%s' failed (%s)",
              corto_fullpath(NULL, observable), corto_lasterr());
        }
    } else {
        corto_seterr("updateCancel: object '%s' is not an observable",
            corto_fullpath(NULL, observable));
        goto error;
    }

    return 0;
error:
    return -1;
}

static void corto_waitObserver(corto_object me, corto_object observable, corto_object source) {
    corto_waitForObject *waitAdmin;
    CORTO_UNUSED(source);

    waitAdmin = (corto_waitForObject*)me;

    if (corto_ainc(&waitAdmin->triggerCount) == 1) {
        corto_uint32 i;

        waitAdmin->triggered = observable;
        corto_semPost(waitAdmin->semaphore);

        /* Silence this observer */
        for(i=0; i<waitAdmin->count; i++) {
            corto_silence(me, waitAdmin->observer, CORTO_ON_UPDATE, waitAdmin->objects[i]);
        }
    }
    corto_adec(&waitAdmin->triggerCount);
}

static void __corto_waitObserver(corto_function f, void* result, void* args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    corto_waitObserver(
        *(corto_object*)args,
        *(corto_object*)((intptr_t)args + sizeof(corto_object)),
        *(corto_object*)((intptr_t)args + sizeof(corto_object) * 2));
}

corto_int16 corto_waitfor(corto_object observable) {
    corto_waitForObject *waitAdmin;

    /* Obtain waitadministration */
    waitAdmin = corto_threadTlsGet(CORTO_KEY_WAIT_ADMIN);
    if (!waitAdmin) {
        corto_observer observer;

        /* Create thread-specific waitadministration */
        waitAdmin = corto_alloc(sizeof(corto_waitForObject));
        memset(waitAdmin, 0, sizeof(corto_waitForObject));
        waitAdmin->semaphore = corto_semNew(0);

        /* Create observer */
        observer = corto_declare(corto_type(corto_observer_o));
        corto_function(observer)->impl = (corto_word)__corto_waitObserver;
        corto_function(observer)->implData = (corto_word)corto_waitObserver;
        corto_function(observer)->kind = CORTO_PROCEDURE_CDECL;
        observer->mask = CORTO_ON_UPDATE;

        corto_define(observer);
        waitAdmin->observer = observer;
        corto_threadTlsSet(CORTO_KEY_WAIT_ADMIN, waitAdmin);
    }

    /* Add object to waitadministration */
    waitAdmin->objects[waitAdmin->count] = observable;
    waitAdmin->count++;

    return 0;
}

corto_object corto_wait(corto_int32 timeout_sec, corto_int32 timeout_nanosec) {
    corto_waitForObject *waitAdmin;
    corto_object result = NULL;
    CORTO_UNUSED(timeout_sec);
    CORTO_UNUSED(timeout_nanosec);

    /* Obtain waitadministration */
    waitAdmin = corto_threadTlsGet(CORTO_KEY_WAIT_ADMIN);
    if (waitAdmin) {
        corto_uint32 i;

        /* Setup observer for observables */
        for(i=0; i<waitAdmin->count; i++) {
            corto_listen((corto_object)waitAdmin, waitAdmin->observer, CORTO_ON_UPDATE, waitAdmin->objects[i], NULL);
        }

        /* Do the wait */
        corto_semWait(waitAdmin->semaphore);

        result = waitAdmin->triggered;
    } else {
        corto_error("wait called without objects that are being waited for");
    }

    return result;
}

/* REPL functionality */
corto_int16 corto_expr(corto_object scope, corto_string expr, corto_value *value) {
    corto_int16 result = -1;
    static corto_function parseLine = NULL;
    static corto_bool searchedForParser = FALSE;

    /* Clear any errors set by previous code  */
    corto_seterr(NULL);

    corto_object o = corto_resolve(scope, expr);
    if (o) {
        corto_valueObjectInit(value, o, NULL);
        result = 0;
    } else {
        if (!corto_lasterr()) {
            if (!parseLine && !searchedForParser) {
                parseLine = corto_resolve(NULL, "::corto::ast::Parser::parseLine");
                searchedForParser = TRUE;
            }

            if (parseLine) {
                corto_call(parseLine, &result, expr, scope, value);
            } else {
                corto_seterr(NULL);
            }
        }
    }

    return result;
}

static char* corto_manIdEscape(corto_object from, corto_object o, corto_id buffer) {

    corto_path(buffer, from, o, "_");

    return &buffer[strlen(buffer)];
}

char* corto_manId(corto_object o, corto_id buffer) {
    corto_object parents[CORTO_MAX_SCOPE_DEPTH];
    corto_uint32 count = 0;
    corto_object p = o;
    corto_object from = NULL;
    char *ptr = buffer + 5;

    strcpy(buffer, "/doc/");

    do {
        parents[count] = p;
        count++;
    } while(!corto_instanceof(corto_package_o, p) && (p = corto_parentof(p)));

    do{
        count--;
        p = parents[count];
        if (corto_instanceof(corto_package_o, p)) {
            ptr = corto_manIdEscape(NULL, p, ptr);
            from = p;
        } else if (corto_instanceof(corto_type_o, p)) {
            if (from && !corto_instanceof(corto_package_o, from)) {
                *(ptr++) = '_';
            } else {
                *(ptr++) = '/';
            }
            ptr = corto_manIdEscape(from, p, ptr);
            from = p;
        } else {
            *(ptr++) = '/';
            ptr = corto_manIdEscape(parents[count + 1], p, ptr);
        }
    } while (count);

    return buffer;
}

/* Documentation */
corto_object corto_man(corto_object o) {
    corto_id id;
    corto_manId(o, id);
    return corto_resolve(NULL, id);
}

/* Thread-safe reading */
corto_int16 corto_readBegin(corto_object object) {
    if (corto_checkAttr(object, CORTO_ATTR_WRITABLE)) {
        corto__writable* _o;

        _o = corto__objectWritable(CORTO_OFFSET(object, -sizeof(corto__object)));
        if (corto_rwmutexRead(&_o->lock)) {
            corto_seterr("readBegin of '%s' failed: %s",
              corto_fullpath(NULL, object), corto_lasterr());
            goto error;
        }
    }

    return 0;
error:
    return -1;
}

corto_int16 corto_readEnd(corto_object object) {
    return corto_unlock(object);
}

/* Thread-safe writing */
corto_int16 corto_lock(corto_object object) {
    if (corto_checkAttr(object, CORTO_ATTR_WRITABLE)) {
        corto__writable* _o;

        _o = corto__objectWritable(CORTO_OFFSET(object, -sizeof(corto__object)));
        if (corto_rwmutexWrite(&_o->lock)) {
            goto error;
        }
    }

    return 0;
error:
    return -1;
}

corto_int16 corto_unlock(corto_object object) {
    if (corto_checkAttr(object, CORTO_ATTR_WRITABLE)) {
        corto__writable* _o;

        _o = corto__objectWritable(CORTO_OFFSET(object, -sizeof(corto__object)));
        if (corto_rwmutexUnlock(&_o->lock)) {
            goto error;
        }
    }

    return 0;
error:
    return -1;
}


/* Obtain function name from signature */
corto_int32 corto_signatureName(corto_string signature, corto_id buffer) {
    corto_char ch, *srcptr, *bptr;

    /* Obtain name from function (without argumentlist) */
    srcptr = signature; bptr = buffer;
    while ((ch = *srcptr) && (ch != '(')) {
        *bptr = ch;
        bptr++;
        srcptr++;
    }
    *bptr = '\0';

    return 0;
}

/* Count number of parameters */
corto_int32 corto_signatureParamCount(corto_string signature) {
    corto_char *ptr, ch;
    corto_uint32 count;

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
                corto_uint32 nesting = 1;
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
corto_int32 corto_signatureParamType(corto_string signature, corto_uint32 id, corto_id buffer, int* flags) {
    corto_char ch, *srcptr, *bptr;
    corto_uint32 i;
    corto_bool parsed, parsing;

    if (flags) {
        *flags = 0;
    }

    srcptr = strchr(signature, '(');
    if (!srcptr) {
        corto_seterr("missing argmentlist in signature '%s'", signature);
        goto error;
    }
    srcptr++;

    /* Find parameter-entry, copy to buffer */
    bptr = buffer;
    i = 0;
    parsed = FALSE;
    parsing = FALSE;
    while((ch = *srcptr) && !parsed) {

        /* Start parsing when argument is reached. */
        if (i == id) {
            if ((ch == ',') || (ch == ' ') || (ch == ')') || (ch == '&')) {
                if (parsing) {
                    parsed = TRUE;
                }
            } else {
                parsing = TRUE;
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
                corto_uint32 count=1;
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

    if (flags && (ch == '&')) {
        *flags |= CORTO_PARAMETER_REFERENCE;
        if(*(srcptr+1) == '&') {
            *flags |= CORTO_PARAMETER_FORCEREFERENCE;
        }
    }
    if (flags && !strcmp(buffer, "?")) {
        *flags |= CORTO_PARAMETER_WILDCARD;
    }
    if (flags && !strcmp(buffer, "null")) {
        *flags |= CORTO_PARAMETER_NULL;
    }

    return 0;
error:
    return -1;
}

/* Obtain function parameter names from signature */
corto_int32 corto_signatureParamName(corto_string signature, corto_uint32 id, corto_id buffer) {
    corto_char ch, *srcptr, *bptr;
    corto_uint32 i;
    corto_bool parsed;

    srcptr = strchr(signature, '(');
    if (!srcptr) {
        corto_error("missing argmentlist in signature '%s'", signature);
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
                if(*srcptr == '&') { /* Forcereference */
                    srcptr++;
                }

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
                corto_error("missing name of parameter %d in signature '%s'", id, buffer);
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
                corto_uint32 count=1;
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

/* Helper functions for overloading */
corto_uint32 corto_overloadParamCount(corto_object o) {
    corto_uint32 result;
    if (corto_interface(corto_typeof(o))->kind == CORTO_PROCEDURE) {
        if (corto_procedure(corto_typeof(o))->kind != CORTO_OBSERVER) {
            result = corto_function(o)->parameters.length;
        } else {
            result = 0;
        }
    } else {
        result = corto_delegate(corto_typeof(o))->parameters.length;
    }
    return result;
}

/* Helper function that obtains type from signature */
corto_type corto_overloadParamType(corto_object object, corto_int32 i, corto_bool *reference) {
    corto_id buffer;
    corto_int32 flags = 0;
    corto_id signature;
    corto_type result;

    if (corto_signature(object, signature)) {
        corto_seterr("invalid signature %s", signature);
        goto error;
    }

    if (corto_signatureParamType(signature, i, buffer, &flags)) {
        corto_seterr("cannot get parameter %d from signature %s", i, signature);
        goto error;
    }

    if (flags & CORTO_PARAMETER_REFERENCE) {
        if (reference) *reference = TRUE;
    } else {
        if (reference) *reference = FALSE;
    }

    result = corto_resolve(object, buffer);
    if (!result) {
        corto_seterr(
          "unresolved type '%s' in signature '%s'", buffer, signature);
        goto error;
    }

    if(!corto_instanceof(corto_type_o, result)) {
        corto_seterr(
          "object '%s' in signature '%s' is not a type", buffer, signature);
        goto error;
    }

    return result;
error:
    return NULL;
}


/* Compare parameter */
static corto_uint32 corto_overloadParamCompare(
    corto_type o_type,
    corto_type r_type,
    corto_bool o_reference,
    corto_bool r_reference,
    corto_bool r_forceReference,
    corto_bool r_wildcard,
    corto_bool r_null) {
    corto_int32 d = 0;

    /* Match wildcards */
    if (r_wildcard) {
        goto match;
    }

    /* Match reference modifiers */
    if (o_reference) {
        if (!r_reference && !r_null) {
            goto nomatch; /* Parameter accepts only references */
        } else {
            if (!r_forceReference) {
                if (!r_null) {
                    d++; /* Favor pass by value in case of implicit reference passing */
                }
            }
        }
    } else if (r_reference) {
        d++;
    }

    /* Match any */
    if ((o_type->kind == CORTO_ANY) || (r_type && (r_type->kind == CORTO_ANY))) {
        goto match;
    }

    /* Match null */
    if (r_null) {
        if ((o_type->kind == CORTO_PRIMITIVE) && (corto_primitive(o_type)->kind == CORTO_BOOLEAN)) {
            d++;
            goto match;
        } else if (!o_reference &&
            ((o_type->kind != CORTO_PRIMITIVE) || (corto_primitive(o_type)->kind != CORTO_TEXT))) {
            goto nomatch;
        } else {
            goto match;
        }
    }

    /* Match type compatibility */
    if (corto_checkState(o_type, CORTO_DEFINED) && (corto_checkState(r_type, CORTO_DEFINED))) {
        if (o_type == r_type) {
            goto match;
        }

        /* If an interface, increase distance for each level in inheritance tree  */
        if ((o_type->kind == CORTO_COMPOSITE) && (r_type->kind == CORTO_COMPOSITE)) {
            corto_interface base = corto_interface(r_type);
            while(base && (base != corto_interface(o_type))) {
                d++;
                base = base->base;
            }
            if (!base) {
                goto nomatch; /* o_type doesn't occur in the inheritance tree of r_type */
            }

        /* If a generic reference, increase distance with the max levels in r's inheritance tree. This
         * way, a more specific signature will always be favored */
        } else if (o_reference && o_type->kind == CORTO_VOID) {
            if (r_type->kind == CORTO_COMPOSITE) {
                corto_interface base = corto_interface(r_type);
                do { /* Always increase at least by one */
                    d++;
                } while((base = base->base));
            } else {
                d++;
            }
        /* If the requested type is a (forced) reference check if treating it as a generic
         * reference would result in a match - this is for example useful when casting from
         * references to a boolean or string type */
        } else if (r_forceReference && !corto_type_compatible(o_type, corto_object_o)) {
            d++;
        /* If types are not compatible, they won't match */
        } else if (!corto_type_compatible(o_type, r_type)) {
            goto nomatch;
        /* Types are compatible. Increase d by one if types are of a different primitive
         * kind. */
        } else if ((o_type->kind == CORTO_PRIMITIVE) && (r_type->kind == CORTO_PRIMITIVE)) {
            if (corto_primitive(o_type)->kind != corto_primitive(r_type)->kind) {
                if (!corto_primitive_isInteger(corto_primitive(o_type)) ||
                    !corto_primitive_isInteger(corto_primitive(r_type))) {
                    d++;
                }
            }
        }
    } else if (o_type != r_type) {
        goto nomatch;
    }

match:
    return d;
nomatch:
    return -1;
}

/* Create signature from delegate */
static void corto_signatureFromDelegate(corto_object o, corto_id buffer) {
    corto_delegate type = corto_delegate(corto_typeof(o));
    corto_uint32 i;

    /* Construct signature */
    corto_string signature = corto_signatureOpen(corto_nameof(o));
    for (i = 0; i < type->parameters.length; i++) {
        corto_parameter *p = &type->parameters.buffer[i];
        signature = corto_signatureAdd(signature, p->type, p->passByReference ? CORTO_PARAMETER_FORCEREFERENCE : 0);
    }
    signature = corto_signatureClose(signature);

    /* Copy signature to buffer */
    strcpy(buffer, signature);
    corto_dealloc(signature);
}

/* Obtain signature from object */
corto_int16 corto_signature(corto_object object, corto_id buffer) {
    corto_type t = corto_typeof(object);

    if (t->kind != CORTO_COMPOSITE) {
        goto error;
    }

    switch(corto_interface(t)->kind) {
    case CORTO_DELEGATE:
        corto_signatureFromDelegate(object, buffer);
        break;
    case CORTO_PROCEDURE:
        strcpy(buffer, corto_nameof(object));
        break;
    default:
        goto error;
    }

    return 0;
error:
    corto_seterr(
      "can't get signature from '%s' of non-procedure type '%s'",
      corto_fullpath(NULL, object),
      corto_fullpath(NULL, t));    abort();
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
corto_int16 corto_overload(corto_object object, corto_string requested, corto_int32* distance) {
    corto_id r_name, o_name;
    corto_int32 r_parameterCount, o_parameterCount;
    corto_int32 i = 0, d = 0;
    corto_id offered;

    /* Validate if function object is valid */
    if (!corto_checkState(object, CORTO_VALID)) {
        corto_seterr(
            "can't perform request '%s' on invalid object %s",
            requested,
            corto_fullpath(NULL, object));
        goto error;
    }

    /* Obtain offered singature */
    if (corto_signature(object, offered)) {
        printf("invalid signature\n");
        goto error;
    }

    /* Obtain name of offered object */
    if (corto_signatureName(offered, o_name)) {
        printf("invalid signature name #1\n");
        goto error;
    }

    /* Obtain name of requested object */
    if (corto_signatureName(requested, r_name)) {
        printf("invalid signature name\n");
        goto error;
    }

    /* Validate if names of request and offered match */
    if (stricmp(o_name, r_name)) {
        goto nomatch;
    }

    /* Validate whether number of parameters is equal. A request is allowed to
     * omit parameters */
    r_parameterCount = corto_signatureParamCount(requested);
    o_parameterCount = corto_overloadParamCount(object);

    if ((r_parameterCount != -1) && (r_parameterCount != o_parameterCount)) {
        goto nomatch;
    }

    /* If request contains parameters, compare parameters of both */
    if (r_parameterCount == o_parameterCount) {
        for (i = 0; i < o_parameterCount; i++) {
            corto_bool o_reference = FALSE, r_reference = FALSE;
            corto_bool r_forceReference = FALSE, r_wildcard = FALSE, r_null = FALSE;
            corto_type o_type, r_type = NULL;
            corto_id r_typeName;
            int flags, paramDistance = 0;

            /* Obtain offered and requested type */
            if (!(o_type = corto_overloadParamType(object, i, &o_reference))) {
                goto error;
            }
            if (corto_signatureParamType(requested, i, r_typeName, &flags)) {
                goto error;
            } else if (!(flags & (CORTO_PARAMETER_WILDCARD | CORTO_PARAMETER_NULL))) {
                r_type = corto_resolve(object, r_typeName);
                if (r_type) {
                    r_type = corto_type(r_type);
                } else {
                    corto_seterr("unresolved type '%s' in signature '%s'", r_typeName, requested);
                    goto error;
                }
            }

            /* Obtain flags */
            o_reference |= o_type->reference;
            r_reference |= (flags & CORTO_PARAMETER_REFERENCE) | (r_type ? r_type->reference : 0);
            r_forceReference |= (flags & CORTO_PARAMETER_FORCEREFERENCE) | (r_type ? r_type->reference : 0);
            r_wildcard = flags & CORTO_PARAMETER_WILDCARD;
            r_null = flags & CORTO_PARAMETER_NULL;

            /* Evaluate whether parameter types are compatible */
            paramDistance += corto_overloadParamCompare(
                o_type,
                r_type,
                o_reference,
                r_reference,
                r_forceReference,
                r_wildcard,
                r_null);

            if (paramDistance == -1) {
                goto nomatch;
            } else {
                d += paramDistance;
            }
        }
    }

    *distance = d;

    return 0;
nomatch:
    *distance = -1;
    return 0;
error:
    if (!corto_lasterr()) {
        corto_seterr("invalid procedure request '%s'", requested);
    }
    return -1;
}

static int corto_scopeCollectWalk(corto_object o, void* userData) {
    corto_objectseq *seq = userData;
    if (!seq->buffer) {
        /* Get scopesize within scope lock */
        corto_uint32 scopeSize = corto_scopeSize(corto_parentof(o));
        seq->buffer = corto_alloc(sizeof(corto_object) * scopeSize);
        /* Increment length with each object */
    }
    corto_claim(o);
    seq->buffer[seq->length++] = o;
    return 1;
}

corto_objectseq corto_scopeClaim(corto_object scope) {
    corto_objectseq result = {0, NULL};
    corto_scopeWalk(scope, corto_scopeCollectWalk, &result);
    return result;
}

void corto_scopeRelease(corto_objectseq seq) {
    corto_uint32 i = 0;
    for (i = 0; i < seq.length; i++) {
        corto_release(seq.buffer[i]);
    }
    corto_dealloc(seq.buffer);
}

typedef struct corto_lookupFunction_t {
    corto_string request;
    corto_object *result;
    corto_bool error;
    corto_int32 d;
    corto_int32 old_d;
}corto_lookupFunction_t;

/* Lookup function in scope */
int corto_lookupFunctionWalk(corto_object *ptr, void* userData) {
    corto_int32 d = -1;
    corto_lookupFunction_t* data;
    corto_object o = *ptr;

    data = userData;

    /* If current object is a function, match it */
    if ((corto_typeof(o)->kind == CORTO_COMPOSITE) &&
        ((corto_interface(corto_typeof(o))->kind == CORTO_PROCEDURE) ||
        (corto_interface(corto_typeof(o))->kind == CORTO_DELEGATE))) {
        if (strchr(data->request, '(')) {
            if (corto_overload(o, data->request, &d)) {
                data->error = TRUE;
                goto found;
            }
        } else {
            corto_id sigName; corto_signatureName(corto_nameof(o), sigName);
            if (!strcmp(sigName, data->request)) {
                if (!corto_function(o)->overloaded) {
                    data->d = 0;
                    data->result = (corto_object*)ptr;
                    goto found;
                } else {
                    data->error = TRUE;
                    corto_seterr("ambiguous reference '%s'", data->request);
                    goto found;
                }
            }
        }

        if (d != -1) {
            if (d <= data->d) {
                data->old_d = data->d;
            }
            if (d < data->d) {
                data->result = (corto_object*)ptr;
                data->d = d;
            }
        }
    } else {
        if (!stricmp(corto_nameof(o), data->request)) {
            data->d = 0;
            data->result = (corto_object*)ptr;
            goto found;
        }
    }

    return 1;
found:
    return 0;
}

/* Lookup function with support for overloading */
corto_object* corto_lookupFunctionFromSequence(corto_objectseq scopeContents, corto_string requested, corto_int32* d) {
    corto_lookupFunction_t walkData;
    corto_uint32 i;

    /* Call the actual lookup function */
    walkData.request = requested;
    walkData.result = NULL;
    walkData.error = FALSE;
    walkData.d = INT_MAX;
    walkData.old_d = INT_MAX;

    for (i = 0; i < scopeContents.length; i++) {
        if (!corto_lookupFunctionWalk(&scopeContents.buffer[i], &walkData)) {
            break;
        }
    }

    if (walkData.d != INT_MAX && (walkData.d == walkData.old_d)) {
        corto_seterr("ambiguous reference '%s'", walkData.request);
        walkData.error = TRUE;
    }

    if (d) {
        if (walkData.error) {
            *d = -1;
        } else if (!walkData.result) {
            *d = 0;
        } else {
            *d = walkData.d;
        }
    }

    if (walkData.error) walkData.result = NULL;

    return walkData.result;
}

corto_object corto_lookupFunction(corto_object scope, corto_string requested, corto_int32* d) {
    corto_objectseq scopeContents = corto_scopeClaim(scope);
    corto_object result = NULL;
    corto_object *ptr = corto_lookupFunctionFromSequence(scopeContents, requested, d);
    if (ptr) {
        corto_claim(*ptr);
        result = *ptr;
    }
    corto_scopeRelease(scopeContents);
    return result;
}

/* Create request signature */
corto_string corto_signatureOpen(corto_string name) {
    corto_string result;

    result = corto_alloc(strlen(name) + 1 + 1);
    sprintf(result, "%s(", name);

    return result;
}

corto_string corto_signatureAdd(corto_string sig, corto_type type, int flags) {
    corto_uint32 len;
    corto_string result;
    corto_id id;
    corto_bool reference = flags & CORTO_PARAMETER_REFERENCE;
    corto_bool forceReference = flags & CORTO_PARAMETER_FORCEREFERENCE;
    corto_bool wildcard = flags & CORTO_PARAMETER_WILDCARD;

    if (type) {
        if (!corto_checkAttr(type, CORTO_ATTR_SCOPED) ||
            corto_isBuiltinPackage(type))
        {
            corto_fullpath(id, type);
        } else
        {
            strcpy(id, corto_nameof(type));
        }
    } else if (wildcard) {
        strcpy(id, "?");
    } else {
        strcpy(id, "null");
    }

    len = strlen(sig);
    if (sig[len-1] == '(') {
        result = corto_realloc(sig, len + strlen(id) + 1 + ((reference|forceReference) ? 2 : 0));
        strcat(result, id);
        if (flags & (reference|forceReference)) strcat(result, "&");
        if (flags & (forceReference)) strcat(result, "&");
    } else {
        result = corto_realloc(sig, len + strlen(id) + 1 + 1 + ((reference|forceReference) ? 2 : 0));
        strcat(result, ",");
        strcat(result, id);
        if (flags & (reference|forceReference)) strcat(result, "&");
        if (flags & (forceReference)) strcat(result, "&");
    }

    return result;
}

corto_string corto_signatureAddWildcard(corto_string sig, corto_bool isReference) {
    corto_uint32 len;
    corto_string result;

    len = strlen(sig);
    if (sig[len-1] == '(') {
        result = corto_realloc(sig, len + 1 + 1 + (isReference ? 1 : 0));
        strcat(result, "?");
        if (isReference) strcat(result, "&");
    } else {
        result = corto_realloc(sig, len + 1 + 1 + 1 + (isReference ? 1 : 0));
        strcat(result, ",");
        strcat(result, "?");
        if (isReference) strcat(result, "&");
    }

    return result;
}

corto_string corto_signatureClose(corto_string sig) {
    corto_uint32 length = strlen(sig) + 1;
    sig = corto_realloc(sig, length + 1);
    sig[length-1] = ')';
    sig[length] = '\0';
    return sig;
}

/* Set reference field */
void corto_setref(void* ptr, corto_object value) {
    corto_object old;
    old = *(corto_object*)ptr;
    if (value) {
        corto_claim(value);
    }
    *(corto_object*)ptr = value;
    if (old) {
        corto_release(old);
    }
}

/* Set string field */
void corto_setstr(corto_string* ptr, corto_string value) {
    if (*ptr) {
        corto_dealloc(*ptr);
    }
    *ptr = value ? corto_strdup(value) : NULL;
}

corto_string corto_str(corto_object object, corto_uint32 maxLength) {
    corto_string_ser_t serData;
    struct corto_serializer_s s;
    serData.buffer = NULL;
    serData.length = 0;
    serData.maxlength = maxLength;
    serData.compactNotation = TRUE;
    serData.prefixType = FALSE;
    serData.enableColors = FALSE;

    s = corto_string_ser(CORTO_LOCAL, CORTO_NOT, CORTO_SERIALIZER_TRACE_NEVER);
    corto_serialize(&s, object, &serData);

    return serData.buffer;
}

corto_string corto_strv(corto_value* v, corto_uint32 maxLength) {
    corto_string_ser_t serData;
    struct corto_serializer_s s;
    serData.buffer = NULL;
    serData.length = 0;
    serData.maxlength = maxLength;
    serData.compactNotation = TRUE;
    serData.prefixType = FALSE;
    serData.enableColors = FALSE;

    s = corto_string_ser(CORTO_LOCAL, CORTO_NOT, CORTO_SERIALIZER_TRACE_NEVER);
    corto_serializeValue(&s, v, &serData);

    return serData.buffer;
}

corto_string _corto_strp(void *p, corto_type type, corto_uint32 maxLength) {
    corto_value v;
    corto_valueValueInit(&v, NULL, type, p);
    return corto_strv(&v, maxLength);
}

corto_string corto_stra(corto_any a, corto_uint32 maxLength) {
    corto_value v;
    corto_valueValueInit(&v, NULL, a.type, a.value);
    return corto_strv(&v, maxLength);
}

corto_int16 corto_fromStr(void *o, corto_string string) {
    corto_string_deser_t serData;

    serData.out = *(void**)o;
    serData.scope = NULL;
    serData.type = *(void**)o ? corto_typeof(*(void**)o) : NULL;
    if (!corto_string_deser(string, &serData)) {
        corto_assert(!serData.out, "deserializer failed but out is set");
    }

    if (serData.out) {
        *(void**)o = serData.out;
    } else {
        goto error;
    }

    return 0;
error:
    return -1;
}

corto_int16 corto_fromStrv(corto_value *v, corto_string string) {
    corto_string_deser_t serData;

    serData.out = corto_valueValue(v);
    serData.scope = NULL;
    serData.type = corto_valueType(v);
    if (!corto_string_deser(string, &serData)) {
        corto_assert(!serData.out, "deserializer failed but out is set");
    }

    if (serData.out) {
        corto_valueSetValue(v, serData.out);
    } else {
        goto error;
    }

    return 0;
error:
    return -1;
}

corto_int16 _corto_fromStrp(void* out, corto_type type, corto_string string) {
    corto_string_deser_t serData;

    serData.out = *(void**)out;
    serData.scope = NULL;
    serData.type = type;
    if (!corto_string_deser(string, &serData)) {
        corto_assert(!serData.out, "deserializer failed but out is set");
    }

    if (serData.out) {
        *(void**)out = serData.out;
    } else {
        goto error;
    }

    return 0;
error:
    return -1;
}

corto_int16 corto_fromStra(corto_any *a, corto_string string) {
    corto_string_deser_t serData;

    serData.out = a->value;
    serData.scope = NULL;
    serData.type = a->type;
    if (!corto_string_deser(string, &serData)) {
        corto_assert(!serData.out, "deserializer failed but out is set");
    }

    if (serData.out) {
        a->value = serData.out;
    } else {
        goto error;
    }

    return 0;
error:
    return -1;
}

corto_equalityKind corto_compare(corto_object o1, corto_object o2) {
    corto_any a1, a2;
    a1.value = o1;
    a1.type = corto_typeof(o1);
    a1.owner = FALSE;
    a2.value = o2;
    a2.type = corto_typeof(o2);
    a2.owner = FALSE;
    return corto_type_compare(a1, a2);
}

corto_equalityKind corto_comparev(corto_value *value1, corto_value *value2) {
    corto_void *v1, *v2;
    corto_any a1, a2;
    corto_type t1, t2;

    v1 = corto_valueValue(value1);
    v2 = corto_valueValue(value2);
    t1 = corto_valueType(value1);
    t2 = corto_valueType(value2);

    a1.value = v1;
    a1.type = t1;
    a1.owner = FALSE;
    a2.value = v2;
    a2.type = t2;
    a2.owner = FALSE;
    return corto_type_compare(a1, a2);
}

corto_equalityKind _corto_comparep(void *p1, corto_type type, void *p2) {
    corto_value vdst;
    corto_value vsrc;
    corto_valueValueInit(&vdst, NULL, type, p1);
    corto_valueValueInit(&vsrc, NULL, type, p2);
    return corto_comparev(&vdst, &vsrc);
}

corto_equalityKind corto_comparea(corto_any a1, corto_any a2) {
    corto_value vdst;
    corto_value vsrc;
    corto_valueValueInit(&vdst, NULL, a1.type, a1.value);
    corto_valueValueInit(&vsrc, NULL, a2.type, a2.value);
    return corto_comparev(&vdst, &vsrc);
}

corto_int16 corto_init(corto_object o) {
    corto_typeKind kind = corto_typeof(o)->kind;

    switch(kind) {
        case CORTO_COMPOSITE:
        case CORTO_COLLECTION: {
            struct corto_serializer_s s = corto_ser_init(0, CORTO_NOT, CORTO_SERIALIZER_TRACE_ON_FAIL);
            corto_serialize(&s, o, NULL);
            break;
        }
        default:
            break;
    }
    return corto_delegateInit(corto_typeof(o), o);;
}

corto_int16 corto_initv(corto_value *v) {
    struct corto_serializer_s s = corto_ser_init(0, CORTO_NOT, CORTO_SERIALIZER_TRACE_ON_FAIL);
    if (corto_serializeValue(&s, v, NULL)) {
        return -1;
    }
    return corto_delegateInit(corto_valueType(v), corto_valueValue(v));
}

corto_int16 _corto_initp(void *p, corto_type type) {
    corto_value v;
    corto_valueValueInit(&v, NULL, type, p);
    return corto_initv(&v);
}

corto_int16 corto_inita(corto_any a) {
    corto_value v;
    corto_valueValueInit(&v, NULL, a.type, a.value);
    return corto_initv(&v);
}

corto_int16 corto_deinit(corto_object o) {
    corto_typeKind kind = corto_typeof(o)->kind;
    switch(kind) {
        case CORTO_COMPOSITE:
        case CORTO_COLLECTION: {
            struct corto_serializer_s s = corto_ser_freeResources(0, CORTO_NOT, CORTO_SERIALIZER_TRACE_ON_FAIL);
            corto_serialize(&s, o, NULL);
            break;
        }
        default:
            break;
    }
    return 0;
}

corto_int16 corto_deinitv(corto_value *v) {
    struct corto_serializer_s s = corto_ser_freeResources(0, CORTO_NOT, CORTO_SERIALIZER_TRACE_ON_FAIL);
    return corto_serializeValue(&s, v, NULL);
}

corto_int16 _corto_deinitp(void *p, corto_type type) {
    corto_value v;
    corto_valueValueInit(&v, NULL, type, p);
    return corto_deinitv(&v);
}

corto_int16 corto_deinita(corto_any a) {
    corto_value v;
    corto_valueValueInit(&v, NULL, a.type, a.value);
    return corto_deinitv(&v);
}

corto_int16 corto_copy(corto_object *dst, corto_object src) {
    struct corto_serializer_s s = corto_copy_ser(CORTO_PRIVATE, CORTO_NOT, CORTO_SERIALIZER_TRACE_ON_FAIL);
    corto_copy_ser_t data;
    corto_int16 result;
    corto_bool newObject = FALSE;

    if (!*dst) {
        *dst = corto_declare(corto_typeof(src));
        newObject = TRUE;
    }

    corto_valueObjectInit(&data.value, *dst, NULL);
    result = corto_serialize(&s, src, &data);

    if (newObject) {
        corto_define(*dst);
    }

    return result;
}

corto_int16 corto_copyv(corto_value *dst, corto_value *src) {
    struct corto_serializer_s s = corto_copy_ser(CORTO_PRIVATE, CORTO_NOT, CORTO_SERIALIZER_TRACE_ON_FAIL);
    corto_copy_ser_t data;
    corto_int16 result;
    corto_bool newObject = FALSE;

    if (!corto_valueValue(dst)) {
        corto_valueValueInit(dst, NULL, corto_valueType(src), corto_declare(corto_valueType(src)));
        newObject = TRUE;
    }

    data.value = *dst;
    result = corto_serializeValue(&s, src, &data);

    if (newObject) {
        corto_define(corto_valueValue(dst));
    }

    return result;
}

corto_int16 _corto_copyp(void *dst, corto_type type, void *src) {
    corto_value vdst;
    corto_value vsrc;
    corto_int16 result;
    corto_valueValueInit(&vdst, NULL, type, dst);
    corto_valueValueInit(&vsrc, NULL, type, src);
    result = corto_copyv(&vdst, &vsrc);
    return result;
}

corto_int16 corto_copya(corto_any *dst, corto_any src) {
    corto_value vdst;
    corto_value vsrc;
    corto_int16 result;
    corto_valueValueInit(&vdst, NULL, src.type, dst->value);
    corto_valueValueInit(&vsrc, NULL, src.type, src.value);
    result = corto_copyv(&vdst, &vsrc);
    dst->value = corto_valueValue(&vdst);
    dst->type = src.type;
    return result;
}
