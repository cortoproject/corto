 /*
 * corto_object.c
 *
 *  Created on: Aug 3, 2012
 *      Author: sander
 */

#include "corto/corto.h"
#include "_object.h"
#include "_matcher.h"
#include "lang/_class.h"

extern corto_mutex_s corto_adminLock;

static corto_object corto_adopt(corto_object parent, corto_object child);
static void corto_olsDestroy(corto__scope *scope);
static corto_bool corto_ownerMatch(corto_object owner, corto_object current);

extern corto_int8 CORTO_OLS_REPLICATOR;
extern corto_int8 CORTO_OLS_AUGMENT;

/* Administration that keeps track of current object attributes */
extern corto_threadKey CORTO_KEY_ATTR;

/* Administration that keeps track of objects declared but not defined in
 * current thread */
extern corto_threadKey CORTO_KEY_DECLARED_ADMIN;

/* Ownership is set per thread */
extern corto_threadKey CORTO_KEY_OWNER;

/* Benchmark tags */
extern int CORTO_BENCHMARK_DECLARE;
extern int CORTO_BENCHMARK_DECLARECHILD;
extern int CORTO_BENCHMARK_INIT;
extern int CORTO_BENCHMARK_DEFINE;
extern int CORTO_BENCHMARK_DELETE;

/* Lists all the anonymous objects in use. Used by the garbage collector. */
corto_ll corto_anonymousObjects = NULL;

void corto_declaredAdminFree(void *admin) {
    if (admin) {
        corto_llFree(admin);
    }
}

corto_bool corto_isBuiltin(corto_object o) {
    corto_assertObject(o);
    if (corto_checkAttr(o, CORTO_ATTR_SCOPED)) {
        if (o == root_o ||
            o == corto_o ||
            o == corto_lang_o ||
            o == corto_core_o ||
            o == corto_native_o)
        {
            return TRUE;
        } else
        {
            corto_object p = corto_parentof(o);
            if (p == corto_lang_o || p == corto_core_o || p == corto_native_o)
            {
                return TRUE;
            } else
            {
                while(p) {
                    p = corto_parentof(p);
                    if (p == corto_lang_o || p == corto_core_o || p == corto_native_o) {
                        return TRUE;
                    }
                }
            }
        }
    }
    return FALSE;
}

corto_bool corto_declaredAdminCheck(corto_object o) {
    corto_assertObject(o);
    corto_ll admin = corto_threadTlsGet(CORTO_KEY_DECLARED_ADMIN);
    if (!admin) {
        return FALSE;
    } else {
        return corto_llHasObject(admin, o) != 0;
    }
}

static void corto_declaredAdminAdd(corto_object o) {
    corto_assertObject(o);
    corto_ll admin = corto_threadTlsGet(CORTO_KEY_DECLARED_ADMIN);
    if (!admin) {
        admin = corto_llNew();
        corto_threadTlsSet(CORTO_KEY_DECLARED_ADMIN, admin);
    }
    corto_llAppend(admin, o);
}

static corto_bool corto_declaredAdminRemove(corto_object o) {
    corto_assertObject(o);
    corto_ll admin = corto_threadTlsGet(CORTO_KEY_DECLARED_ADMIN);
    if (admin) {
        if (corto_llRemove(admin, o)) {
            corto_unlock(o);
            return TRUE;
        }
    }
    return FALSE;
}

corto__observable* corto__objectObservable(corto__object* o) {
    corto__observable* result = (void*)o;

    if (o->align.attrs.observable) {
        result = CORTO_OFFSET(result, -sizeof(corto__observable));
    } else {
        result = NULL;
    }

    return result;
}

static corto__scope* corto__objectScope(corto__object* o) {
    corto__scope* result = (void*)o;

    if (o->align.attrs.observable) {
        result = CORTO_OFFSET(result, -sizeof(corto__observable));
    }
    if (o->align.attrs.scope) {
        result = CORTO_OFFSET(result, -sizeof(corto__scope));
    } else {
        result = NULL;
    }

    return result;
}

static corto__writable* corto__objectWritable(corto__object* o) {
    corto__writable* result = (void*)o;

    if (o->align.attrs.observable) {
        result = CORTO_OFFSET(result, -sizeof(corto__observable));
    }
    if (o->align.attrs.scope) {
        result = CORTO_OFFSET(result, -sizeof(corto__scope));
    }
    if (o->align.attrs.write) {
        result = CORTO_OFFSET(result, -sizeof(corto__writable));
    } else {
        result = NULL;
    }

    return result;
}

static corto__persistent* corto__objectPersistent(corto__object* o) {
    corto__persistent* result = (void*)o;

    if (o->align.attrs.observable) {
        result = CORTO_OFFSET(result, -sizeof(corto__observable));
    }
    if (o->align.attrs.scope) {
        result = CORTO_OFFSET(result, -sizeof(corto__scope));
    }
    if (o->align.attrs.write) {
        result = CORTO_OFFSET(result, -sizeof(corto__writable));
    }
    if (o->align.attrs.persistent) {
        result = CORTO_OFFSET(result, -sizeof(corto__persistent));
    } else {
        result = NULL;
    }

    return result;
}

static void* corto__objectStartAddr(corto__object* o) {
    void* result;
    result = o;
    if (o->align.attrs.scope) {
        result = CORTO_OFFSET(result, -sizeof(corto__scope));
    }
    if (o->align.attrs.write) {
        result = CORTO_OFFSET(result, -sizeof(corto__writable));
    }
    if (o->align.attrs.observable) {
        result = CORTO_OFFSET(result, -sizeof(corto__observable));
    }
    if (o->align.attrs.persistent) {
        result  = CORTO_OFFSET(result, -sizeof(corto__persistent));
    }
    return result;
}

/* Initialze scope-part of object */
static corto_object corto__initScope(
    corto_object o,
    corto_string id,
    corto_object parent,
    corto_bool orphan)
{
    corto__object* _o;
    corto__scope* scope;
    corto_object result = NULL;

    corto_assertObject(o);
    corto_assertObject(parent);

    _o = CORTO_OFFSET(o, -sizeof(corto__object));
    scope = corto__objectScope(_o);
    corto_assert(scope != NULL,
      "corto__initScope: created scoped object, but corto__objectScope returned NULL.");

    if (id) {
        scope->id = corto_strdup(id);
    } else {
        scope->id = NULL;
    }


    /* Set parent, so that initializer can refer to it */
    scope->parent = parent;
    corto_rwmutexNew(&scope->align.scopeLock);


    /* Add object to the scope of the parent-object */
    if (!orphan && corto_checkAttr(parent, CORTO_ATTR_SCOPED)) {
        if (!(result = corto_adopt(parent, o))) {
            /* Reset parent so deinitScope won't release it */
            scope->parent = NULL;
            goto error;
        }
    } else {
        result = o;
        corto_declaredAdminAdd(o);
        corto_lock(o);
    }

    if (result != o) {
        corto_dealloc(scope->id);
        corto_rwmutexFree(&scope->align.scopeLock);
        _o = CORTO_OFFSET(result, -sizeof(corto__object));
        scope = corto__objectScope(_o);
    } else {
        /* Call framework initializer. */
        if (corto_init(o)) {
            corto_string err = corto_lasterr();
            if (!err) {
                corto_seterr(
                  "%s/init failed", corto_fullpath(NULL, corto_typeof(o)));
            }

            /* Remove object from scope */
            corto__orphan(o);

            /* Reset parent so deinitScope won't release it */
            scope->parent = NULL;
            goto error;
        }
    }

    return result;
error:
    return NULL;
}

static void corto__deinitScope(corto_object o) {
    corto__object *_o;
    corto__scope* scope;

    corto_assertObject(o);

    /* Obtain own scope */
    _o = CORTO_OFFSET(o, -sizeof(corto__object));
    scope = corto__objectScope(_o);
    corto_assert(scope != NULL,
        "corto__deinitScope: called on non-scoped object <%p>.", o);

    /* Free parent */
    if (scope->parent && corto_checkState(o, CORTO_DECLARED)) {
        corto_release(scope->parent);
    }
    scope->parent = NULL;

    /* We cannot remove the scope itself, since there might be childs
    * which have multiple cycles, which must be resolved first. */

    /* Deleting the id of the object is also postponed until the object itself
     * is deleted. This makes it easier to debug scenarios with cycles where
     * otherwise lots of objects with NULL ids would show up. It also
     * allows the select function to more efficiently determine what the
     * last iterated object was after a tree has changed. */

    if (scope->ols) {
        corto_olsDestroy(scope);
    }

    /* Finally, free own scopeLock. */
    corto_rwmutexFree(&scope->align.scopeLock);
}

/* Initialize writable-part of object */
static void corto__initWritable(corto_object o) {
    corto__object* _o;
    corto__writable* writable;

    corto_assertObject(o);

    _o = CORTO_OFFSET(o, -sizeof(corto__object));
    writable = corto__objectWritable(_o);
    corto_assert(writable != NULL, "corto__initWritable: created writable object, but corto__objectWritable returned NULL.");

    corto_rwmutexNew(&writable->align.lock);
}

static void corto__deinitWritable(corto_object o) {
    corto__object* _o;
    corto__writable* writable;

    corto_assertObject(o);

    _o = CORTO_OFFSET(o, -sizeof(corto__object));
    writable = corto__objectWritable(_o);
    corto_assert(writable != NULL, "corto__deinitWritable: called on non-writable object <%p>.", o);

    corto_rwmutexFree(&writable->align.lock);
}

/* Initialize observable-part of object */
static void corto__initObservable(corto_object o) {
    corto__object* _o;
    corto__observable *observable;

    corto_assertObject(o);

    _o = CORTO_OFFSET(o, -sizeof(corto__object));
    observable = corto__objectObservable(_o);
    corto_assert(observable != NULL, "corto__initObservable: created observable object, but corto__objectObservable returned NULL.");

    corto_rwmutexNew(&observable->align.selfLock);

    observable->onSelf = NULL;
    observable->onChild = NULL;
    observable->onSelfArray = NULL;
    observable->onChildArray = NULL;
}

static void corto__deinitObservable(corto_object o) {
    corto__object* _o;
    corto__observable* observable;

    corto_assertObject(o);

    _o = CORTO_OFFSET(o, -sizeof(corto__object));
    observable = corto__objectObservable(_o);
    corto_assert(observable != NULL, "corto__deinitObservable: called on non-observable object <%p>.", o);

    /* Delete observer objects in onSelf and onChild */
    if (observable->onSelf) {
        corto__observer* observer;
        while((observer = corto_llTakeFirst(observable->onSelf))) {
            if (!--observer->count) {
                observer->observer->active --;
                corto_dealloc(observer);
            }
        }
        corto_llFree(observable->onSelf);
        observable->onSelf = NULL;
    }

    if (observable->onChild) {
        corto__observer* observer;
        while((observer = corto_llTakeFirst(observable->onChild))) {
            if (!--observer->count) {
                observer->observer->active --;
                corto_dealloc(observer);
            }
        }
        corto_llFree(observable->onChild);
        observable->onChild = NULL;
    }

    corto_rwmutexFree(&observable->align.selfLock);
}

/* Initialize static scoped object */
void corto__newSSO(corto_object sso) {
    corto__object* o;
    corto__scope* scope;

    corto_assertObject(sso);

    o = CORTO_OFFSET(sso, -sizeof(corto__object));
    scope = corto__objectScope(o);
    corto_assert(scope != NULL, "SSO object without a scope? That's bad.");

    /* Don't call initScope because id is already set. */
    corto_rwmutexNew(&scope->align.scopeLock);
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

    corto_assertObject(sso);

    o = CORTO_OFFSET(sso, -sizeof(corto__object));
    scope = corto__objectScope(o);

    corto_assert(scope != NULL, "corto__freeSSO: static scoped object has no scope");

    corto__orphan(sso);

    if (scope->parent) {
        corto_release(scope->parent);
    }

    if (scope->scope) {
        /* Don't print this error - without a proper cycle detector this could
         * be reported without there actually being a problem
        if (corto_rbtreeSize(scope->scope)) {
            corto_error("corto__freeSSO: scope of object '%s' is not empty (%p/%p: %d left)",
                corto_idof(sso),
                sso,
                scope->scope,
                corto_rbtreeSize(scope->scope));
            goto error;
        }*/
        corto_rbtreeFree(scope->scope);
        scope->scope = NULL;
    }

    corto_rwmutexFree(&scope->align.scopeLock);

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

    corto_assertObject(sso);

    o = CORTO_OFFSET(sso, -sizeof(corto__object));
    scope = corto__objectScope(o);

    corto_assert(scope != NULL, "corto__adoptSSO: static scoped object has no scope (very unlikely, corto__adoptSSO called on non-static object?)");

    parent = scope->parent;

    corto_assert(parent != NULL, "corto__adoptSSO: static scoped object has no parent");

    return !corto_adopt(parent, sso);
}

/* Destruct object */
static void corto__destructor(corto_object o) {
    corto_type t;
    corto__object* _o;

    corto_assertObject(o);

    t = corto_typeof(o);
    if (corto_checkState(o, CORTO_DEFINED)) {
        _o = CORTO_OFFSET(o, -sizeof(corto__object));
        if (corto_class_instanceof(corto_class_o, t)) {
            /* Call destructor */
            corto_function delegate = NULL;

            if (t->kind == CORTO_COMPOSITE) {
                if ((corto_interface(t)->kind == CORTO_CLASS) || (corto_interface(t)->kind == CORTO_PROCEDURE)) {
                    corto_interface i = corto_interface(t);
                    do {
                        delegate = corto_class(i)->destruct._parent.procedure;
                        i = i->base;
                    } while(i && !delegate);
                }
            }

            if (delegate) {
                if (delegate->kind == CORTO_PROCEDURE_CDECL) {
                    ((void(*)(corto_object))delegate->fptr)(o);
                } else {
                    corto_call(delegate, NULL, o);
                }
            }
        }
        _o->align.attrs.state &= ~CORTO_DEFINED;
    } else {
        corto_critical("%s/destruct: object '%s' is not defined",
            corto_fullpath(NULL, t), corto_fullpath(NULL, o));
    }
}

static corto_equalityKind corto_compareDefault(corto_type this, const void* o1, const void* o2) {
    int r;
    corto_assertObject(this);
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
    while((ch1 = *ptr1) && ch2 && (ch2 != '/')) {
        if (ch1 == ch2) {
            ptr1++; ptr2++;
            ch2 = *ptr2;
            continue;
        }
        if (ch1 < 97) ch1 = tolower(ch1);
        if (ch2 < 97) ch2 = tolower(ch2);
        if (ch1 != ch2) {
            r = ch1 - ch2;
            goto compare;
        }
        ptr1++;
        ptr2++;
        ch2 = *ptr2;
    }

    if (!ch1 && (ch2 == '/')) {
        goto match;
    }

    if (matchArgs) {
        if (!ch2 && (ch1 == '(')) {
            r = 0;
            goto compare;
        }
    }

    r = ch1 - ch2;
compare:
    return (r < 0) ? CORTO_LT : (r > 0) ? CORTO_GT : CORTO_EQ;
match:
    return CORTO_EQ;
}

static corto_equalityKind corto_compareLookup(corto_type this, const void* o1, const void* o2) {
    CORTO_UNUSED(this);
    return corto_compareLookupIntern(o1, o2, TRUE);
}

static corto_equalityKind corto_compareLookupNoArgMatching(corto_type this, const void* o1, const void* o2) {
    CORTO_UNUSED(this);
    return corto_compareLookupIntern(o1, o2, FALSE);
}

#ifndef NDEBUG
/* Stack for tracing memory management operations */
static corto_string memtrace[50];
static corto_int8 memtraceSp = 0;
static corto_int8 memtraceCount = 0;

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
    corto_assertObject(o);
    corto_fullpath(path, o);

    if (memtrace[memtraceSp]) {
        corto_dealloc(memtrace[memtraceSp]);
        memtrace[memtraceSp] = NULL;
    }

    corto_asprintf(&memtrace[memtraceSp], "%s (%s) %s", path, oper, context ? context : "");

    if ((CORTO_TRACE_OBJECT == o) || (CORTO_TRACE_ID && !strcmp(path, CORTO_TRACE_ID))) {
        memtraceCount ++;

        printf("%d: %s: %s (count = %d, destructed = %d)\n",
            memtraceCount,
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

        if (CORTO_MEMTRACE_BREAKPOINT == memtraceCount) {
            printf(" << BREAKPOINT >>\n");
            abort();
        }
    }
}
#else
#define corto_memtracePush()
#define corto_memtracePop()
#define corto_memtrace(oper, o, context)
#endif

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

    corto_assertObject(o);

    _o = CORTO_OFFSET(o, -sizeof(corto__object));

    ostate = _o->align.attrs.state;
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

    corto_assertObject(parent);
    corto_assertObject(child);

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

            /* Lock object before locking parent-scope, this ensures that
             * locking order isn't violated when defining the object. */
            corto_lock(child);

            /* Insert child in parent-scope */
            if (corto_rwmutexWrite(&p_scope->align.scopeLock))
                corto_critical("corto_adopt: lock operation on scopeLock of parent failed");

            if (!p_scope->scope) {
                p_scope->scope = corto_rbtreeNew_w_func(corto_compareDefault);
            }

            corto_object existing = corto_rbtreeFindOrSet(p_scope->scope, c_scope->id, child);
            if (existing && (existing != child)) {
                corto_unlock(child);
                if (corto_typeof(existing) != corto_typeof(child)) {
                    corto_seterr("'%s' is already declared with type '%s'",
                      c_scope->id,
                      corto_fullpath(NULL, corto_typeof(existing)));
                    goto err_existing;
                } else {
                    child = existing;
                }
            } else {
                /* Check if parentType matches scopeType of child type */
                if (childType->options.parentType) {
                    parentType = corto_typeof(parent);
                    if ((childType->options.parentType != parentType) &&
                       !corto_instanceof(childType->options.parentType, parent))
                    {
                        corto_seterr("type of '%s' is not '%s'",
                                corto_fullpath(NULL, parent),
                                corto_fullpath(NULL, childType->options.parentType));
                        goto err_invalid_parent;
                    }
                }

                /* Check if parentState matches scopeState of child type */
                if (childType->options.parentState &&
                    !corto__checkStateXOR(parent, childType->options.parentState))
                {
                    corto_uint32 childState = childType->options.parentState;
                    corto_uint32 parentState = _parent->align.attrs.state;
                    char *parentStateStr = corto_strp(&parentState, corto_state_o, 0);
                    char *childStateStr = corto_strp(&childState, corto_state_o, 0);
                    corto_seterr("parent '%s' is %s, must be %s",
                        corto_fullpath(NULL, parent),
                        parentStateStr,
                        childStateStr);
                    corto_dealloc(parentStateStr);
                    corto_dealloc(childStateStr);
                    goto err_invalid_parent;
                }

                /* Add the object to the declared admin, which ensures that this
                 * thread will be able to resolve / redeclare the object, but
                 * other threads will only see the object after it is defined. */
                corto_declaredAdminAdd(child);
            }

            /* Parent must not be deleted before all childs are gone. */
            if (CORTO_TRACE_OBJECT || CORTO_TRACE_ID) corto_memtrace("declare", child, NULL);
            if (CORTO_TRACE_OBJECT || CORTO_TRACE_ID) corto_memtracePush();
            corto_claim(parent);
            if (CORTO_TRACE_OBJECT || CORTO_TRACE_ID) corto_memtracePop();

            if (corto_rwmutexUnlock(&p_scope->align.scopeLock))
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
    corto_rbtreeRemove(p_scope->scope, c_scope->id);
err_existing:
    corto_rwmutexUnlock(&p_scope->align.scopeLock);
error:
    return NULL;
}

/* Orphan object - not a public function as this will only happen during destruction of an object. */
void corto__orphan(corto_object o) {
    corto__object *_parent, *_child;
    corto__scope *p_scope, *c_scope;

    corto_assertObject(o);

    _child = CORTO_OFFSET(o, -sizeof(corto__object));
    c_scope = corto__objectScope(_child);

    if (c_scope->parent) {
        _parent = CORTO_OFFSET(c_scope->parent, -sizeof(corto__object));
        p_scope = corto__objectScope(_parent);

        /* Remove object from parent scope */
        if (corto_rwmutexWrite(&p_scope->align.scopeLock)) goto err_parent_mutex;
        corto_rbtreeRemove(p_scope->scope, (void*)corto_idof(o));

        if (corto_rwmutexUnlock(&p_scope->align.scopeLock)) goto err_parent_mutex;
    }

    return;
err_parent_mutex:
    corto_error("corto__orphan: lock operation of scopeLock of parent failed");
}

/* Find the right initializer to call */
corto_int16 corto_delegateInit(corto_type t, void *o) {
    corto_function delegate = NULL;
    corto_int16 result = 0;

    corto_assertObject(t);

    delegate = t->init._parent.procedure;

    if (t->kind == CORTO_COMPOSITE) {
        if ((corto_interface(t)->kind == CORTO_CLASS) ||
            (corto_interface(t)->kind == CORTO_STRUCT) ||
            (corto_interface(t)->kind == CORTO_PROCEDURE))
        {
            corto_interface i = corto_interface(t)->base;
            while(i && !delegate) {
                delegate = corto_type(i)->init._parent.procedure;
                i = i->base;
            }
        }
    }

    if (delegate) {
        if (delegate->kind == CORTO_PROCEDURE_CDECL) {
            result = ((corto_int16 ___ (*)(corto_object))delegate->fptr)(o);
        } else {
            corto_callb(delegate, &result, (void*[]){&o});
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
    corto_benchmark_start(CORTO_BENCHMARK_DECLARE);

    corto_uint32 size, headerSize;
    corto__object* o = NULL;
    void *mem = NULL;
    corto_attr attrs = corto_getAttr();
    corto_bool initializeScoped = !(attrs & CORTO_ATTR_SCOPED);

    corto_assertObject(type);

    if (!type) {
        corto_seterr("parameter 'type' is null");
        goto error;
    }

    if (!corto_instanceof(corto_type_o, type)) {
        corto_seterr("object '%s' is not a type",
          corto_fullpath(NULL, type));
        goto error;
    }

    /* Type must be valid and defined */
    if (!corto_checkState(type, CORTO_VALID | CORTO_DEFINED)) {
        corto_seterr("type '%s' is not valid/defined", corto_fullpath(NULL, type));
        goto error;
    }

    /* If type specifies ATTR_DEFAULT it means that instances of the type will
     * use the attributes configured for the current thread. */
    if (type->attr & CORTO_ATTR_DEFAULT) {
        if (attrs & CORTO_ATTR_DEFAULT) {
            attrs |= CORTO_ATTR_OBSERVABLE;

            if (type->kind != CORTO_VOID) {
                attrs |= CORTO_ATTR_WRITABLE;
            }
            if (attrs & CORTO_ATTR_SCOPED) {
                attrs |= CORTO_ATTR_PERSISTENT;
            }
        }
    }

    /* Add any additional attributes the type may have specified */
    attrs |= type->attr;

    headerSize = sizeof(corto__object);

    size = type->size;

    /* Calculate size of attributes */
    if (attrs & CORTO_ATTR_OBSERVABLE) {
        headerSize += sizeof(corto__observable);
    }
    if (attrs & CORTO_ATTR_SCOPED) {
        headerSize += sizeof(corto__scope);
    }
    if (attrs & CORTO_ATTR_WRITABLE) {
        headerSize += sizeof(corto__writable);
    }
    if (attrs & CORTO_ATTR_PERSISTENT) {
        headerSize += sizeof(corto__persistent);
    }

    size += headerSize;

    /* Allocate object */
    mem = corto_calloc(size);
    if (mem) {

        /* Offset o so it points to object */
        o = CORTO_OFFSET(mem, headerSize - sizeof(corto__object));

        /* Set magic */
#ifndef NDEBUG
        o->magic = CORTO_MAGIC;
#endif

        /* Give object initial refcount */
        o->refcount = 1;

        /* Set type */
        o->type = type;

        /* Set attributes */
        if (attrs & CORTO_ATTR_SCOPED) {
          o->align.attrs.scope = TRUE;
        }
        if (attrs & CORTO_ATTR_OBSERVABLE) {
            o->align.attrs.observable = TRUE;
            corto__initObservable(CORTO_OFFSET(o, sizeof(corto__object)));
        }
        if (attrs & CORTO_ATTR_WRITABLE) {
            if (type->kind == CORTO_VOID) {
                corto_warning("writable void object created");
            }
            o->align.attrs.write = TRUE;
            corto__initWritable(CORTO_OFFSET(o, sizeof(corto__object)));
        }
        if (attrs & CORTO_ATTR_PERSISTENT) {
            o->align.attrs.persistent = TRUE;
        }

        /* Initially, an object is valid and declared */
        o->align.attrs.state = CORTO_DECLARED;

        corto_claim(type);

        if (initializeScoped) {
            /* Object is scoped because type->attr says so, which means it is an
             * anonymous object with a scope */
            if (attrs & CORTO_ATTR_SCOPED) {
                /* Initialze scope-part of object */
                if (!corto__initScope(CORTO_OFFSET(o, sizeof(corto__object)), NULL, NULL, TRUE)) {
                    goto error_init;
                } else {
                    o->align.attrs.state |= CORTO_VALID;
                }
            }
        }

        /* Call framework initializer */
        if (!(attrs & CORTO_ATTR_SCOPED)) {
            if (!corto_init(CORTO_OFFSET(o, sizeof(corto__object)))) {
                o->align.attrs.state |= CORTO_VALID;
            } else {
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

    corto_benchmark_stop(CORTO_BENCHMARK_DECLARE);
    return CORTO_OFFSET(o, sizeof(corto__object));
error_init: {
    corto_string err = corto_lasterr();
    if (err) {
        corto_seterr("%s/init failed: %s",
            corto_fullpath(NULL, type), err);
    } else {
        corto_seterr("%s/init failed",
            corto_fullpath(NULL, type));
    }
    corto_release(type);
}
error:
    if (mem) corto_dealloc(mem);

    corto_benchmark_stop(CORTO_BENCHMARK_DECLARE);
    return NULL;
}

/* Declare object */
static corto_object corto_declareChildIntern(
    corto_object parent,
    corto_string id,
    corto_type type,
    corto_bool orphan)
{
    corto_benchmark_start(CORTO_BENCHMARK_DECLARECHILD);
    corto_object o = NULL;
    corto_bool retry = FALSE;

    corto_assertObject(parent);
    corto_assertObject(type);

    if (!parent) {
        parent = root_o;
    }

    if (!corto_checkAttr(parent, CORTO_ATTR_SCOPED) && !orphan) {
        corto_seterr("object provided to 'parent' parameter is not scoped");
        goto error;
    }

    if (!id || !strlen(id)) {
        corto_seterr("invalid id (cannot be null or an empty string)");
        goto error;
    }

    /* Save cycles by not building a path when security is not enabled */
    if (corto_secured()) {
        corto_id fullId;
        corto_fullpath(fullId, parent);
        strcat(fullId, "/");
        strcat(fullId, id);
        if (!corto_authorizedId(fullId, CORTO_SECURE_ACTION_CREATE)) {
            goto access_error;
        }
    }

    /* Create new object */
    do {
        corto_attr oldAttr = corto_setAttr(corto_getAttr()|CORTO_ATTR_SCOPED);
        o = corto_declare(type);
        corto_setAttr(oldAttr);

        if (o) {
            corto_object o_ret = NULL;
            corto__object *_o = CORTO_OFFSET(o, -sizeof(corto__object));

            /* Initialize object parameters. */
            if ((o_ret = corto__initScope(o, id, parent, orphan))) {

                if (o_ret == o) {
                    /* Initially, an object is valid and declared */
                    _o->align.attrs.state |= CORTO_VALID;

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
                    if (owner && corto_instanceof(corto_mount_o, owner)) {
                        if (owner != corto_getOwner()) {
                            if (corto_getOwner() || corto_mount(owner)->kind != CORTO_SINK) {
                                corto_release(o);
                                corto_seterr(
                                  "owner '%s' of existing object '%s' does not match owner '%s'",
                                  corto_fullpath(NULL, owner),
                                  corto_fullpath(NULL, o),
                                  corto_fullpath(NULL, corto_getOwner()));
                                goto owner_error;
                            }
                        }
                    }

                    /* If the object just has been declared and not by this thread,
                     * block until the object becomes either defined or destructed */
                    if (!corto_checkState(o, CORTO_DEFINED) && !corto_checkState(o, CORTO_DESTRUCTED)) {
                        if (!corto_declaredAdminCheck(o)) {
                            corto_debug(
                              "corto: declareChild: %s declared in other thread, waiting",
                              id);

                            corto_readBegin(o);
                            corto_bool destructed = corto_checkState(o, CORTO_DESTRUCTED);
                            corto_readEnd(o);

                            corto_debug(
                              "corto: declareChild: %s defined in other thread (destructed = %d)",
                              id, destructed);

                            /* If the object has been deleted after unlocking,
                             * this means that corto_delete was called instead
                             * of corto_define. Since a postcondition of
                             * corto_declareChild is that it should return a
                             * VALID object (at least), it cannot return the
                             * DESTRUCTED object. Therefore, the function will
                             * retry declaring a new object. */
                            if (destructed) {
                                corto_release(o);
                                retry = TRUE;
                            }
                        } else {
                            /* This thread forward declared the object. */
                        }
                    }
                    goto ok;
                }
            } else {
                corto__deinitScope(o);
                if (corto_countof(o) != 1) {
                    corto_seterr(
                      "object '%s/%s' is referenced after initializer failed. details:\n    %s",
                      corto_fullpath(NULL, parent),
                      id,
                      corto_lasterr());
                } else {
                    corto_dealloc(corto__objectStartAddr(CORTO_OFFSET(o,-sizeof(corto__object))));
                    corto_seterr("init for '%s' of '%s' failed: %s",
                        id,
                        corto_fullpath(NULL, type),
                        corto_lasterr());
                }
                corto_release(type);
                o = NULL;
                goto error;
            }

            /* Notify parent of new object */
            if (!orphan) {
                corto_notify(o, CORTO_ON_DECLARE);
            } else {
                /* Orphaned objects don't generate DECLARE and DEFINE events. To
                 * indicate that an object is orphaned, the DECLARE flag is removed. */
                _o->align.attrs.state = CORTO_VALID;
            }

            /* void objects are instantly defined because they have no value. */
            if (type->kind == CORTO_VOID) {
                corto_define(o);
            }
        }
    } while (retry);

ok:
    corto_benchmark_stop(CORTO_BENCHMARK_DECLARECHILD);

    return o;
error:
    if (o) {
        corto_delete(o);
    }
access_error:
owner_error:
    corto_benchmark_stop(CORTO_BENCHMARK_DECLARECHILD);
    return NULL;
}

corto_object _corto_declareChild(corto_object parent, corto_string id, corto_type type) {
    return corto_declareChildIntern(parent, id, type, FALSE);
}

corto_object _corto_declareOrphan(corto_object parent, corto_string id, corto_type type) {
    return corto_declareChildIntern(parent, id, type, TRUE);
}

corto_object _corto_create(corto_type type) {
    corto_assertObject(type);
    corto_object result = corto_declare(type);
    if (result && corto_checkState(result, CORTO_VALID)) {
        if (corto_define(result)) {
            corto_delete(result);
            result = NULL;
        }
    }
    return result;
}

corto_object _corto_createChild(corto_object parent, corto_string id, corto_type type) {
    corto_assertObject(parent);
    corto_assertObject(type);
    corto_object result = corto_declareChildIntern(parent, id, type, FALSE);
    if (result &&
        corto_checkState(result, CORTO_VALID) &&
        !corto_checkState(result, CORTO_DEFINED))
    {
        if (corto_define(result)) {
            corto_delete(result);
            result = NULL;
        }
    }

    return result;
}

corto_object _corto_createOrphan(corto_object parent, corto_string id, corto_type type) {
    corto_assertObject(parent);
    corto_assertObject(type);
    corto_object result = corto_declareChildIntern(parent, id, type, TRUE);
    if (result &&
        corto_checkState(result, CORTO_VALID) &&
        !corto_checkState(result, CORTO_DEFINED))
    {
        if (corto_define(result)) {
            corto_delete(result);
            result = NULL;
        }
    }

    return result;
}

/* Find the right constructor to call */
corto_int16 corto_delegateConstruct(corto_type t, corto_object o) {
    corto_function delegate = NULL;
    corto_int16 result = 0;

    corto_assertObject(t);

    if (t->kind == CORTO_COMPOSITE) {
        if ((corto_interface(t)->kind == CORTO_CLASS) || (corto_interface(t)->kind == CORTO_PROCEDURE)) {
            corto_interface i = corto_interface(t);
            do {
                delegate = corto_class(i)->construct._parent.procedure;
                i = i->base;
            } while(i && !delegate);
        }
    }

    if (delegate) {
        if (delegate->kind == CORTO_PROCEDURE_CDECL) {
            result = ((corto_int16 ___ (*)(corto_object))delegate->fptr)(o);
        } else {
            corto_callb(delegate, &result, (void*[]){&o});
        }
    }

    return result;
}

corto_object corto_resume_fromMount(
    corto_mount m,
    char *parentId,
    char* expr,
    corto_object o)
{
    corto_object result = NULL;
    corto_type mountType = corto_observer(m)->typeReference;

    /* If mount implements resume, this will load the
     * persistent copy in memory */
    if (!o || !mountType || (mountType == corto_typeof(o))) {
        if ((result = corto_mount_resume(
            m,
            parentId,
            expr,
            o)))
        {
            /* Assign owner */
            corto__object *_o = CORTO_OFFSET(result, -sizeof(corto__object));
            corto__persistent *_p = corto__objectPersistent(_o);
            corto_assert(_p != NULL, "cannot resume object that is not persistent");
            corto_setref(&_p->owner, m);
        }
    }

    return result;
}

/* Precondition: 'expr' contains the expression starting from the object that
 * could not be found in the object store. */
corto_object corto_resume(
    corto_object parent,
    corto_string expr,
    corto_object o)
{
    if (o == root_o) {
        return o;
    }

    if (!expr) {
        return NULL;
    }

    corto_object result = NULL;
    corto_object p = parent;
    corto_id exprBuff;
    char *exprPtr = exprBuff;
    corto_mount lastMount = NULL;

    /* If expression contains / cut expression up without modifying original
     * parameter value */
    strcpy(exprBuff, expr);

    char *nextSep = NULL;
    do {
        corto_id parentId;
        corto_object prev = result;

        nextSep = strchr(exprPtr, '/');
        if (nextSep) {
            *nextSep = '\0';
        }

        result = NULL;

        /* If expression consists of multiple elements, and one element has been
         * found in a mount, it is likely that the next elements are going to be
         * found in the same mount, so start searching there. */
        if (lastMount) {
            corto_path(
                parentId,
                p,
                parent,
                "/");
            result = corto_resume_fromMount(lastMount, parentId, exprPtr, o);
        }

        while (!result && p) {
            corto_ll mountList = corto_olsGet(p, CORTO_OLS_REPLICATOR);
            if (mountList) {
                corto_iter iter = corto_llIter(mountList);

                /* Parent must be relative to mount point of mount */
                corto_path(
                    parentId,
                    p,
                    parent,
                    "/");

                while (corto_iterHasNext(&iter)) {
                    corto_mount_olsData_t *rData = corto_iterNext(&iter);

                    /* Either the mount registered for the direct parent of the
                     * provided object, or the mount must have ON_TREE set */
                    if ((p == parent) ||
                      (((corto_observer)rData->mount)->mask & CORTO_ON_TREE)) {

                        result = corto_resume_fromMount(rData->mount, parentId, exprPtr, o);
                        if (result) {
                            lastMount = rData->mount;
                            break;
                        }
                    }
                }
            }
            if (!result) {
                p = corto_parentof(p);
            }
        }

        if (prev) {
            corto_release(prev);
        }

        parent = result;
        exprPtr = nextSep + 1;
    } while (parent && nextSep);

    return result;
}

/* Resume a declared object */
corto_bool corto_resumeDeclared(corto_object o) {
    corto__object *_o = CORTO_OFFSET(o, -sizeof(corto__object));
    corto__persistent *_p = NULL;
    corto_bool resumed = FALSE;

    corto_assertObject(o);

    if ((_p = corto__objectPersistent(_o))) {
        _p->owner = corto_getOwner();

        if (_p->owner) {
            corto_claim(_p->owner);
        }

        /* If object is persistent and locally owned, check if a
         * persistent copy is already available */
        if (!_p->owner && corto_checkAttr(o, CORTO_ATTR_SCOPED)) {
            if (corto_resume(corto_parentof(o), corto_idof(o), o)) {
                resumed = TRUE;
            }

        /* If owner of an object is a SINK, object is resumed */
        } else if (_p->owner
          && corto_instanceof(corto_mount_o, _p->owner)
          && (corto_mount(_p->owner)->kind == CORTO_SINK))
        {
            resumed = TRUE;
        }
    }

    return resumed;
}

/* Resume a declared object */
corto_int16 corto_defineDeclared(corto_object o, corto_eventMask mask) {
    corto_int16 result = 0;
    corto_type t = corto_typeof(o);
    corto__object *_o = CORTO_OFFSET(o, -sizeof(corto__object));

    corto_assertObject(o);

    /* Don't invoke constructor if object is not locally owned */
    if (corto_ownerMatch(corto_ownerof(o), NULL)) {
        /* If object is instance of a class, call the constructor */
        if (corto_class_instanceof(corto_class_o, t)) {
            /* Call constructor - will potentially override observer params */
            corto_attr prev = corto_setAttr(CORTO_ATTR_DEFAULT);
            result = corto_delegateConstruct(t, o);
            corto_setAttr(prev);
        } else if (corto_class_instanceof(corto_procedure_o, t)) {
            result = corto_delegateConstruct(t, o);
        }
    }

    if (!result) {
        _o->align.attrs.state |= CORTO_DEFINED;
        if (!corto_checkState(o, CORTO_VALID)) {
            _o->align.attrs.state |= CORTO_VALID;
        }

        if (corto_checkAttr(o, CORTO_ATTR_SCOPED)) {
            corto_declaredAdminRemove(o);
        }

        /* Do postponed listen calls for instance */
        corto_observerDelayedAdminDefine(o);

        /* Notify observers of defined object, don't generate DEFINED event for
         * orphaned objects (that don't have CORTO_DECLARED). */
        if (_o->align.attrs.state & CORTO_DECLARED) {
            corto_notify(o, mask);
        }
    } else {
        /* Remove valid state */
        corto_invalidate(o);
    }

    return result;
}

corto_bool corto_childof(corto_object p, corto_object o) {
    corto_bool result = FALSE;
    if (p != o) {
        if (corto_checkAttr(o, CORTO_ATTR_SCOPED)) {
            corto_object parent = corto_parentof(o);
            while (parent && (parent != p)) {
                parent = corto_parentof(parent);
            }
            result = parent != NULL;
        }
    }
    return result;
}

/* Define object */
corto_int16 corto_define(corto_object o) {
    corto_benchmark_start(CORTO_BENCHMARK_DEFINE);

    corto_int16 result = 0;

    corto_assertObject(o);

    if (!o) {
        corto_seterr("corto: NULL passed to corto_define");
        goto error;
    }

    /* Only define undefined objects */
    if (!corto_checkState(o, CORTO_DEFINED) || !corto_checkState(o, CORTO_VALID)) {
        if (corto_childof(root_o, o) && !corto_isBuiltin(o)) {
            if (!corto_declaredAdminCheck(o) && corto_checkState(o, CORTO_VALID)) {
                corto_seterr("corto: cannot define object '%s' because it was not declared in same thread",
                  corto_fullpath(NULL, o));
                goto error;
            }
        }

        corto_bool resumed = corto_resumeDeclared(o);
        result = corto_defineDeclared(o, resumed ? CORTO_ON_RESUME : CORTO_ON_DEFINE);
        if (CORTO_TRACE_OBJECT || CORTO_TRACE_ID) corto_memtrace("define", o, NULL);
    }

    corto_benchmark_stop(CORTO_BENCHMARK_DEFINE);
    return result;
error:
    corto_benchmark_stop(CORTO_BENCHMARK_DEFINE);
    return -1;
}

corto_bool corto_destruct(corto_object o, corto_bool delete) {
    corto_benchmark_start(CORTO_BENCHMARK_DELETE);

    corto__object* _o;
    corto_bool result = TRUE;
    corto_object owner = corto_ownerof(o);

    corto_assertObject(o);

    _o = CORTO_OFFSET(o, -sizeof(corto__object));
    corto_ainc(&_o->refcount);

    /* Treat builtin objects separately. They cannot be destructed regularly
     * because they aren't allocated on heap */
    if (corto_isBuiltin(o)) {
        if (!corto_checkState(o, CORTO_DESTRUCTED)) {
            _o->align.attrs.state |= CORTO_DESTRUCTED;
        }
        return TRUE;
    }

    if (!corto_checkState(o, CORTO_DESTRUCTED)) {
        if (CORTO_TRACE_OBJECT || CORTO_TRACE_ID) corto_memtrace("destruct", o, NULL);
        if (CORTO_TRACE_OBJECT || CORTO_TRACE_ID) corto_memtracePush();

        /* From here, object is marked as destructed. */
        _o->align.attrs.state |= CORTO_DESTRUCTED;

        /* Only do the following steps if the object is defined */
        if (corto_checkState(o, CORTO_DEFINED)) {

            /* Only send delete notification when object is being deleted, not
             * when object is being suspended. */
            if (delete) {
                if (corto_checkAttr(o, CORTO_ATTR_SCOPED)) {
                    corto_drop(o, delete);
                }
                if (corto_checkState(o, CORTO_DECLARED)) {
                    corto_notify(o, CORTO_ON_DELETE);
                }
            } else if (corto_checkState(o, CORTO_DECLARED)) {
                corto_notify(o, CORTO_ON_SUSPEND);
            }

            /* Call object destructor */
            if (corto_owned(o)) {
                corto__destructor(o);
            }
            if (owner && corto_checkAttr(o, CORTO_ATTR_PERSISTENT)) {
                corto_release(owner);
            }
        } else {
            /* If object wasn't defined, remove it from the declared admin */
            if (corto_checkAttr(o, CORTO_ATTR_SCOPED) && !corto_declaredAdminRemove(o)) {
                /* Throw a warning only if deleting the object. If this is not a
                 * delete, then the object was released, which may be done by
                 * anyone. */
                if (delete) {
                    corto_warning(
                      "corto: undefined object '%s' is deleted by different thread",
                      corto_fullpath(NULL, o));
                }
            }
        }

        /* Deinit observable */
        if (corto_checkAttr(o, CORTO_ATTR_OBSERVABLE)) {
            corto__deinitObservable(o);
        }

        /* Deinit scope */
        if (corto_checkAttr(o, CORTO_ATTR_SCOPED) && corto_checkState(o, CORTO_DECLARED)) {
            corto__orphan(o);
        } else {
            /* Remove from anonymous cache */
            corto_mutexLock(&corto_adminLock);
            corto_llRemove(corto_anonymousObjects, o);
            corto_mutexUnlock(&corto_adminLock);
        }

        /* Indicate that object has been destructed */
        result = TRUE;
        if (CORTO_TRACE_OBJECT || CORTO_TRACE_ID) corto_memtracePop();
    }

    /* Although after the destruct-operation it is ensured that this object no
     * longer participates in any cycles, it cannot be assumed that all objects
     * using this are freed. For example, another object that has multiple
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

        if (CORTO_TRACE_OBJECT || CORTO_TRACE_ID) corto_memtrace("deinit", o, NULL);

        /* Call deinitializer */
        if (CORTO_TRACE_OBJECT || CORTO_TRACE_ID) corto_memtracePush();
        corto_deinit(o);
        if (CORTO_TRACE_OBJECT || CORTO_TRACE_ID) corto_memtracePop();

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

            if (scope->id) {
                corto_dealloc(scope->id);
                scope->id = NULL;
            }
        }

        if (CORTO_TRACE_OBJECT || CORTO_TRACE_ID) corto_memtrace("deallocate", o, NULL);

#ifndef NDEBUG
        _o->magic = CORTO_MAGIC_DESTRUCT;
#endif
        corto_dealloc(corto__objectStartAddr(_o));

        result = FALSE;
    }

    corto_benchmark_stop(CORTO_BENCHMARK_DELETE);
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

    corto_assertObject(o);

    _o = CORTO_OFFSET(o, -sizeof(corto__object));
    scope = corto__objectScope(_o);
    if (scope) {
        corto_iter iter;
        corto_object collected;

        /* Because object refcounts can reach zero after a free, a
         * walk in which objects are collected is needed first. During
         * destruction of an object, this scopeLock is also required,
         * which would result in deadlocks. */

        corto_rwmutexRead(&scope->align.scopeLock);
        walkData.objects = NULL;
        if (scope->scope) {
            corto_rbtreeWalk(scope->scope, corto_dropWalk, &walkData);
        }
        corto_rwmutexUnlock(&scope->align.scopeLock);

        /* Free objects outside scopeLock */
        if (walkData.objects) {
            if (CORTO_TRACE_OBJECT || CORTO_TRACE_ID) {
                corto_memtrace(delete ? "drop:delete" : "drop:suspend", o, NULL);
            }

            iter = corto_llIter(walkData.objects);
            while(corto_iterHasNext(&iter)) {
                collected = corto_iterNext(&iter);

                if (CORTO_TRACE_OBJECT || CORTO_TRACE_ID) corto_memtracePush();

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

                if (CORTO_TRACE_OBJECT || CORTO_TRACE_ID) corto_memtracePop();

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
    corto_assertObject(o);
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
    corto_assertObject(o);
    if (!o) {
        corto_critical("NULL passed to corto_delete");
    }

    if (!corto_authorized(o, CORTO_SECURE_ACTION_DELETE)) {
        goto error;
    }

    if (!corto_owned(o)) {
        corto_seterr("object not owned by thread");
        goto error;
    }

    if (CORTO_TRACE_OBJECT || CORTO_TRACE_ID) corto_memtrace("delete", o, NULL);
    if (CORTO_TRACE_OBJECT || CORTO_TRACE_ID) corto_memtracePush();

    if (corto_destruct(o, TRUE)) {
        corto_release(o);
    }

    if (CORTO_TRACE_OBJECT || CORTO_TRACE_ID) corto_memtracePop();

    return 0;
error:
    return -1;
}

/* Invalidate object by removing valid flag */
corto_int16 corto_invalidate(corto_object o) {
    corto_assertObject(o);
    corto__object* _o;
    _o = CORTO_OFFSET(o, -sizeof(corto__object));
    _o->align.attrs.state &= ~CORTO_VALID;
    /* Notify observers */
    return corto_notify(o, CORTO_ON_INVALIDATE);
}

/* Get type */
corto_type corto_typeof(corto_object o) {
    corto_assertObject(o);
    corto__object* _o = CORTO_OFFSET(o, -sizeof(corto__object));
    return _o->type;
}

/* Get refcount */
corto_int32 corto_countof(corto_object o) {
    corto_assertObject(o);
    corto__object* _o;
    _o = CORTO_OFFSET(o, -sizeof(corto__object));
    return _o->refcount;
}

/* Get state */
corto_state corto_stateof(corto_object o) {
    corto_assertObject(o);
    corto__object* _o;
    _o = CORTO_OFFSET(o, -sizeof(corto__object));
    corto_int8 state = _o->align.attrs.state;
    return state;
}

corto_attr corto_attrof(corto_object o) {
    corto_assertObject(o);
    corto__object* _o;
    _o = CORTO_OFFSET(o, -sizeof(corto__object));

    corto_int8 attr =
      _o->align.attrs.scope |
      (_o->align.attrs.write << 1) |
      (_o->align.attrs.observable << 2) |
      (_o->align.attrs.persistent << 3);

    return attr;
}

static corto_ll contentTypes = NULL;

static corto_string corto_contentTypeToStr(corto_value *v) {
    return corto_strv(v, 0);
}

static corto_int16 corto_contentTypeFromStr(corto_value *v, corto_string str) {
    return corto_fromStrv(v, str);
}

static corto_string corto_contentTypeToStrColor(corto_value *v) {
    corto_string_ser_t sdata;
    struct corto_serializer_s s = corto_string_ser(CORTO_PRIVATE, CORTO_NOT, CORTO_SERIALIZER_TRACE_ON_FAIL);
    memset(&sdata, 0, sizeof(corto_string_ser_t));
    sdata.enableColors = TRUE;
    s.access = CORTO_PRIVATE;
    s.accessKind = CORTO_NOT;
    s.aliasAction = CORTO_SERIALIZER_ALIAS_IGNORE;
    s.optionalAction = CORTO_SERIALIZER_OPTIONAL_IF_SET;
    corto_serializeValue(&s, v, &sdata);
    return corto_buffer_str(&sdata.buffer);
}

static corto_contentType corto_findContentType(
    corto_string contentType)
{
    corto_contentType result = NULL;
    if (contentTypes) {
        corto_iter it = corto_llIter(contentTypes);
        while (corto_iterHasNext(&it)) {
            corto_contentType ct = corto_iterNext(&it);
            if (!strcmp(ct->name, contentType)) {
                result = ct;
                break;
            }
        }
    } else {
        contentTypes = corto_llNew();
    }

    if (!result && !strcmp(contentType, "corto")) {
        result = corto_alloc(sizeof(struct corto_contentType));
        result->name = corto_strdup("corto");

        result->toValue =
            (corto_int16 ___ (*)(corto_value*, corto_word))corto_contentTypeFromStr;

        result->fromValue =
            (corto_word ___ (*)(corto_value*))corto_contentTypeToStr;

        result->release = (void ___ (*)(corto_word))corto_dealloc;

        result->copy = (corto_word ___ (*)(corto_word)) corto_strdup;
        corto_llAppend(contentTypes, result);

    } else if (!result && !strcmp(contentType, "corto-color")) {
        result = corto_alloc(sizeof(struct corto_contentType));
        result->name = corto_strdup("corto");

        result->toValue = NULL;
        result->fromValue =
            (corto_word ___ (*)(corto_value*))corto_contentTypeToStrColor;

        result->release = (void ___ (*)(corto_word))corto_dealloc;

        result->copy = (corto_word ___ (*)(corto_word)) corto_strdup;
        corto_llAppend(contentTypes, result);
    }

    return result;
}

corto_contentType corto_loadContentType(
    corto_string contentType)
{
    corto_contentType result = NULL;

    /* Built-in Corto string serializer */
    char *packagePtr = strchr(contentType, '/');
    if (!packagePtr) {
        corto_seterr("invalid content type %s (expected '/')", contentType);
        goto error;
    }

    packagePtr ++;

    /* Find content type in admin */
    corto_mutexLock(&corto_adminLock);
    result = corto_findContentType(packagePtr);
    corto_mutexUnlock(&corto_adminLock);

    /* Load contentType outside of lock */
    if (!result) {
        corto_id packageId;
        sprintf(packageId, "corto/fmt/%s", packagePtr);

        result = corto_alloc(sizeof(struct corto_contentType));
        result->name = corto_strdup(packagePtr);

        /* Load package associated with content type */
        corto_seterr(NULL);
        if (corto_load(packageId, 0, NULL)) {
            if (corto_lasterr()) {
                corto_seterr("unresolved package '%s' for contentType '%s': %s",
                    packageId, contentType, corto_lasterr());
            } else {
                corto_seterr("unresolved package '%s' for contentType '%s'",
                    packageId, contentType);
            }
            goto error;
        }

        /* Load serialization routines */
        corto_id id;
        sprintf(id, "%s_fromValue", packagePtr);
        result->fromValue =
            (corto_word ___ (*)(corto_value*))
              corto_loaderResolveProc(id);
        if (!result->fromValue) {
            corto_seterr("symbol '%s' missing for contentType '%s'", id, contentType);
            goto error;
        }

        sprintf(id, "%s_toValue", packagePtr);
        result->toValue =
            (corto_int16 ___ (*)(corto_value*, corto_word))
              corto_loaderResolveProc(id);
        if (!result->toValue) {
            corto_seterr("symbol '%s' missing for contentType '%s'", id, contentType);
            goto error;
        }


        sprintf(id, "%s_fromResult", packagePtr);
        result->fromResult =
          (corto_word ___ (*)(corto_result*))
            corto_loaderResolveProc(id);
        if (!result->fromResult) {
            corto_seterr("symbol '%s' missing for contentType '%s'", id, contentType);
            goto error;
        }

        sprintf(id, "%s_toResult", packagePtr);
        result->toResult =
          (corto_int16 ___ (*)(corto_result*, corto_word))
            corto_loaderResolveProc(id);
        if (!result->toResult) {
            corto_seterr("symbol '%s' missing for contentType '%s'", id, contentType);
            goto error;
        }


        sprintf(id, "%s_fromObject", packagePtr);
        result->toObject =
          (corto_int16 ___ (*)(corto_object*, corto_word))
            corto_loaderResolveProc(id);
        if (!result->toObject) {
            corto_seterr("symbol '%s' missing for contentType '%s'", id, contentType);
            goto error;
        }

        sprintf(id, "%s_toObject", packagePtr);
        result->toObject =
          (corto_int16 ___ (*)(corto_object*, corto_word))
            corto_loaderResolveProc(id);
        if (!result->toObject) {
            corto_seterr("symbol '%s' missing for contentType '%s'", id, contentType);
            goto error;
        }

        sprintf(id, "%s_copy", packagePtr);
        result->copy =
            (corto_word ___ (*)(corto_word))
              corto_loaderResolveProc(id);
        if (!result->copy) {
            corto_seterr("symbol '%s' missing for contentType '%s'", id, contentType);
            goto error;
        }

        sprintf(id, "%s_release", packagePtr);
        result->release =
            (void ___ (*)(corto_word))
              corto_loaderResolveProc(id);
        if (!result->release) {
            corto_seterr("symbol '%s' missing for contentType '%s'", id, contentType);
            goto error;
        }

        /* Add to admin, verify that it hasn't been already added by another
         * thread */
         corto_mutexLock(&corto_adminLock);
         corto_contentType alreadyAdded = corto_findContentType(packagePtr);
         if (!alreadyAdded) {
            corto_llAppend(contentTypes, result);
         } else {
            corto_dealloc(result->name);
            corto_dealloc(result);
            result = alreadyAdded;
         }
         corto_mutexUnlock(&corto_adminLock);
    }

    return result;
error:
    return NULL;
}

/* Get contentstring */
corto_string corto_contentof(corto_id str, corto_string contentType, corto_object o) {
    corto_contentType type;
    corto_string result = NULL;

    corto_assertObject(o);

    if (!(type = corto_loadContentType(contentType))) {
        goto error;
    }

    corto_value v = corto_value_object(o, NULL);
    corto_string c = (corto_string)type->fromValue(&v);
    if (!c) {
        goto error;
    }

    if (str) {
        strncpy(str, c, sizeof(corto_id));
        str[sizeof(corto_id) - 1] = '\0';
        result = str;
    } else {
        result = corto_setThreadString(c);
        corto_dealloc(c);
    }

    return result;
error:
    return NULL;
}

corto_int16 corto_fromcontent(corto_object o, corto_string contentType, corto_string fmt, ...) {
    corto_contentType type;
    va_list args;
    corto_string content;
    corto_int16 result;

    corto_assertObject(o);

    va_start(args, fmt);
    corto_vasprintf(&content, fmt, args);
    va_end(args);

    if (!(type = corto_loadContentType(contentType))) {
        goto error;
    }

    corto_value v = corto_value_object(o, NULL);
    result = type->toValue(&v, (corto_word)content);
    corto_dealloc(content);

    return result;
error:
    return -1;
}

corto_object corto_createFromContent(corto_string contentType, corto_string content)
{
    corto_object result = NULL;
    corto_contentType type = corto_loadContentType(contentType);
    if (!type) {
        goto error;
    }
    if (type->toObject(&result, (corto_word)content)) {
        goto error;
    }

    return result;
error:
    return NULL;
}


/* Check for a state */
corto_bool corto_checkState(corto_object o, corto_int8 state) {
    corto__object* _o;
    corto_assertObject(o);
    _o = CORTO_OFFSET(o, -sizeof(corto__object));
    return (_o->align.attrs.state & state) == state;
}

/* Check for an attribute */
corto_bool corto_checkAttr(corto_object o, corto_int8 attr) {
    corto_bool result;
    corto__object* _o;

    corto_assertObject(o);

    _o = CORTO_OFFSET(o, -sizeof(corto__object));
    result = TRUE;

    if (attr & CORTO_ATTR_SCOPED) {
        if (!_o->align.attrs.scope) result = FALSE;
    }
    if (attr & CORTO_ATTR_WRITABLE) {
        if (!_o->align.attrs.write) result = FALSE;
    }
    if (attr & CORTO_ATTR_OBSERVABLE) {
        if (!_o->align.attrs.observable) result = FALSE;
    }
    if (attr & CORTO_ATTR_PERSISTENT) {
        if (!_o->align.attrs.persistent) result = FALSE;
    }
    return result;
}

corto_object _corto_assertType(corto_type type, corto_object o) {
    corto_assertObject(type);
    corto_assertObject(o);

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

corto_bool _corto_instanceofType(corto_type type, corto_type t) {
    corto_bool result = TRUE;

    corto_assertObject(type);
    corto_assertObject(t);

    if (type != t) {
        result = FALSE;

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
            default:
                break;
            }
        } else {
            if ((type->kind == CORTO_VOID) && (type->reference)) {
                if (t->reference) {
                    result = TRUE;
                }
            }
        }
    }
    if (!result && (corto_typeof(t) == (corto_type)corto_target_o)) {
        result = type == ((corto_target)t)->type;
    }

    return result;
}

corto_bool _corto_instanceof(corto_type type, corto_object o) {
    corto_assertObject(type);
    corto_assertObject(o);

    corto_type t = corto_typeof(o);

    /* If types are equal, quickly jump out of function */
    if (type == t) {
        return TRUE;
    }

    /* Any object is an instance of VOID references */
    if ((type->kind == CORTO_VOID) && (type->reference)) {
        return TRUE;
    }

    /* A bit of gibberish to ensure that a constant of an enumeration or bitmask
     * will evaluate TRUE when used with the enum/bitmask type.  */
    if (t == (corto_type)corto_constant_o) {
        if (type == (corto_type)corto_constant_o) {
            return TRUE;
        }
        t = corto_parentof(o);
    }

    return corto_instanceofType(type, t);
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
        } while ((++ols)->key);
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
        } while ((++ols)->key);
        result = ols - scope->ols;
    }
    return result;
}

/* Set an OLS value */
void* corto_olsSet(corto_object o, corto_int8 key, void *value) {
    corto__object* _o;
    corto__scope* scope;
    void *old = NULL;

    corto_assertObject(o);

    _o = CORTO_OFFSET(o, -sizeof(corto__object));
    scope = corto__objectScope(_o);
    if (scope) {
        corto__ols *ols = NULL;

        if (corto_rwmutexWrite(&scope->align.scopeLock)) {
            corto_seterr("aquiring scopelock failed");
            goto error;
        }

        ols = corto_olsFind(scope, key);
        if (ols) {
            corto_assert(ols->key == key, "returned wrong OLS data");
            old = ols->value;
        } else {
            corto_uint8 size = corto_olsSize(scope);
            scope->ols = corto_realloc(scope->ols,
                (size + 2) * sizeof(corto__ols));
            ols = &scope->ols[size];
            ols->key = key;
            (ols + 1)->key = 0;
        }
        ols->value = value;

        corto_rwmutexUnlock(&scope->align.scopeLock);
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

    corto_assertObject(o);

    _o = CORTO_OFFSET(o, -sizeof(corto__object));
    scope = corto__objectScope(_o);
    if (scope) {
        corto__ols *ols = NULL;
        if (corto_rwmutexWrite(&scope->align.scopeLock)) {
            corto_seterr("aquiring scopelock failed: %s", corto_lasterr());
            goto error;
        }

        ols = corto_olsFind(scope, key);
        if (ols) {
            corto_assert(ols->key == key, "returned wrong OLS data");
            result = ols->value;
        }

        corto_rwmutexUnlock(&scope->align.scopeLock);
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

    corto_assertObject(o);

    _o = CORTO_OFFSET(o, -sizeof(corto__object));
    scope = corto__objectScope(_o);
    if (scope) {
        corto__ols *ols = NULL;
        if (corto_rwmutexWrite(&scope->align.scopeLock)) {
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
        } else {
            corto_assert(ols->key == key, "returned wrong OLS data");
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
    corto_assertObject(o);

    corto__object* _o;
    corto__scope* scope;

    _o = CORTO_OFFSET(o, -sizeof(corto__object));
    scope = corto__objectScope(_o);
    if (scope) {
        corto__ols *ols = corto_olsFind(scope, key);
        if (ols) {
            corto_assert(ols->key == key, "returned wrong OLS data");
            ols->value = value;
        }
        corto_rwmutexUnlock(&scope->align.scopeLock);
    } else {
        corto_seterr("object is not scoped");
    }
}

/* Get & lock scope */
corto__scope *corto__scopeClaim(corto_object o) {
    corto_assertObject(o);

    corto__object  *_o = CORTO_OFFSET(o, -sizeof(corto__object));
    corto__scope *scope = corto__objectScope(_o);
    if (scope) {
        if (corto_rwmutexRead(&scope->align.scopeLock)) {
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
    corto_assertObject(o);

    corto__object  *_o = CORTO_OFFSET(o, -sizeof(corto__object));
    corto__scope *scope = corto__objectScope(_o);
    if (scope) {
        corto_rwmutexUnlock(&scope->align.scopeLock);
    }
}

/* Get parent (requires scoped object) */
corto_object corto_parentof(corto_object o) {
    corto_assertObject(o);

    corto__object* _o;
    corto__scope* scope;
    corto_object result;

    result = NULL;
    _o = CORTO_OFFSET(o, -sizeof(corto__object));
    scope = corto__objectScope(_o);
    if (scope) {
        result = scope->parent;
    }

    return result;
}

/* Get name (requires scoped object) */
corto_string corto_nameof(corto_id buffer, corto_object o) {
    corto_assertObject(o);

    corto_type t = corto_typeof(o);
    corto_string str = NULL;
    corto_bool threadStr = FALSE;
    corto_function delegate = NULL;

    if (t->kind == CORTO_COMPOSITE) {
        corto_interface i = corto_interface(t);
        do {
            delegate = corto_type(i)->nameof._parent.procedure;
            i = i->base;
        } while(i && !delegate);
    } else {
        delegate = t->nameof._parent.procedure;
    }

    if (delegate) {
        if (delegate->kind == CORTO_PROCEDURE_CDECL) {
            str = ((corto_string ___ (*)(corto_object))(delegate->fptr))(o);
        } else {
            corto_call(delegate, &str, o);
        }

        if (!buffer) {
            buffer = str;
            threadStr = TRUE;
        } else {
            strcpy(buffer, str);
            corto_dealloc(str);
        }
    } else {
        if (!buffer) {
            buffer = corto_alloc(sizeof(corto_id));
            threadStr = TRUE;
        }
        if (corto_idof(o)) {
            strcpy(buffer, corto_idof(o));
        } else {
            buffer[0] = '\0';
        }
    }

    if (threadStr) {
        corto_string tmp = buffer;
        buffer = corto_setThreadString(buffer);
        corto_dealloc(tmp);
    }

    return buffer;
}

/* Get id (requires scoped object) */
corto_string corto_idof(corto_object o) {
    corto_assertObject(o);

    corto__object* _o;
    corto__scope* scope;
    corto_string result;

    result = NULL;
    _o = CORTO_OFFSET(o, -sizeof(corto__object));
    scope = corto__objectScope(_o);
    if (scope) {
        result = scope->id;
    }

    return result;
}

/* Get scope tree */
corto_rbtree corto_scopeof(corto_object o) {
    corto_assertObject(o);

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
    corto_critical("corto_idof: object %p is not scoped.", o);
    return NULL;
}

corto_uint32 corto_scopeSize(corto_object o) {
    corto_assertObject(o);

    corto__object* _o;
    corto__scope* scope;
    corto_rbtree tree;
    corto_uint32 result = 0;

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

/* Secure object walk */
typedef struct corto_scopeWalkSecured_t {
    corto_scopeWalkAction action;
    void *userData;
} corto_scopeWalkSecured_t;
int corto_scopeWalkSecured(corto_object o, void *userData) {
    corto_scopeWalkSecured_t *data = userData;
    int result = 1;
    if (corto_authorized(o, CORTO_SECURE_ACTION_READ)) {
        result = data->action(o, data->userData);
    }
    return result;
}

/* Walk objects in scope */
corto_int16 corto_scopeWalk(corto_object o, corto_scopeWalkAction action, void* userData) {
    corto_assertObject(o);

    corto_int16 result;
    corto__scope* scope;

    if (!o) {
        o = root_o;
    }

    result = 1;
    scope = corto__objectScope(CORTO_OFFSET(o, -sizeof(corto__object)));
    if (scope) {
        if (scope->scope) {
            corto_rwmutexRead(&scope->align.scopeLock);
            if (!corto_secured()) {
                result = corto_rbtreeWalk(scope->scope, (corto_walkAction)action, userData);
            } else {
                corto_scopeWalkSecured_t walkData = {action, userData};
                result = corto_rbtreeWalk(
                    scope->scope,
                    (corto_walkAction)corto_scopeWalkSecured,
                    &walkData);
            }
            corto_rwmutexUnlock(&scope->align.scopeLock);
        }
    }

    return result;
}

/* Obtain scoped identifier (serves as global unique identifier) */
corto_string corto_fullpath_intern(corto_id buffer, corto_object o, corto_bool useName) {
    corto_assertObject(o);

    corto_object stack[CORTO_MAX_SCOPE_DEPTH];
    corto_uint32 depth;
    corto_char* ptr;
    corto_uint32 len;
    corto_bool threadStr = FALSE;

    depth = 0;

    if (!buffer) {
        buffer = corto_alloc(sizeof(corto_id));
        threadStr = TRUE;
    }

    if (!o) {
        buffer[0] = '\0';
    } else if (!corto_checkAttr(o, CORTO_ATTR_SCOPED)) {
        struct corto_serializer_s stringSer;
        corto_string_ser_t data;

        /* Serialize object string */
        stringSer = corto_string_ser(CORTO_LOCAL|CORTO_READONLY|CORTO_PRIVATE, CORTO_NOT, CORTO_SERIALIZER_TRACE_ON_FAIL);

        *buffer = '\0';
        data.compactNotation = TRUE;
        data.buffer = CORTO_BUFFER_INIT;
        data.buffer.buf = buffer;
        data.buffer.max = sizeof(corto_id) - 1;
        data.prefixType = TRUE;
        data.enableColors = FALSE;
        if (corto_serialize(&stringSer, o, &data)) {
            goto error;
        }

    } else if (corto_parentof(o) == corto_lang_o) {
        if (useName) {
            corto_nameof(buffer, o);
        } else {
            strcpy(buffer, corto_idof(o));
        }
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
                char* id;
                corto_id buff;
                if (useName) {
                    id = corto_nameof(buff, o);
                    if (!*id) {
                        id = NULL;
                    }
                } else {
                    id = corto_idof(o);
                }

                if (id) {
                    /* Copy scope operator */
                    *ptr = '/';
                    ptr += 1;

                    /* Copy id */
                    len = strlen(id);
                    memcpy(ptr, id, len + 1);
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
error:
    return NULL;
}

corto_string corto_fullpath(corto_id buffer, corto_object o) {
    corto_assertObject(o);
    return corto_fullpath_intern(buffer, o, FALSE);
}

corto_string corto_fullname(corto_id buffer, corto_object o) {
    corto_assertObject(o);
    return corto_fullpath_intern(buffer, o, TRUE);
}

corto_int32 corto_pathToArray(corto_string path, char *elements[], char *sep) {
    corto_int32 count = 0;
    char *ptr = path;

    if (*ptr == *sep) {
        elements[count ++] = ptr;
        *ptr = '\0';
        ptr ++;
    }
    if (*ptr) {
        do {
            /* Never parse more elements than maximum scope depth */
            if (count == CORTO_MAX_SCOPE_DEPTH) {
                corto_seterr(
                    "number of elements in path exceeds MAX_SCOPE_DEPTH (%d)",
                    CORTO_MAX_SCOPE_DEPTH);
                goto error;
            }
            if (*ptr == *sep) {
                *ptr = '\0';
                ptr++;
            }
            elements[count ++] = ptr;
        } while ((ptr = strchr(ptr, *sep)));
    }

    return count;
error:
    return -1;
}

static corto_object* corto_scopeStack(
    corto_object o,
    corto_object scopeStack[],
    corto_uint32 *length)
{
    corto_assertObject(o);

    corto_object ptr = o;
    corto_uint32 i = 0;

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

corto_string corto_path_intern(
    corto_id buffer,
    corto_object from,
    corto_object o,
    const char *sep,
    corto_bool useName)
{
    corto_assertObject(from);
    corto_assertObject(o);

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
        if (o != root_o) {
            from = root_o;
        }
    }

    if (from) {
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
                    char* id;
                    corto_id buff;
                    if (useName) {
                        id = corto_nameof(buff, o_s[count]);
                    } else {
                        id = corto_idof(o_s[count]);
                    }
                    length = strlen(id);
                    memcpy(ptr, id, length);
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
                char* id;
                corto_id buff;
                if (useName) {
                    id = corto_nameof(buff, o_s[count]);
                } else {
                    id = corto_idof(o_s[count]);
                }
                length = strlen(id);
                memcpy(ptr, id, length);
            } else {
                length = 2;
                memcpy(ptr, "..", 2);
            }
            ptr += length;
            *ptr = '\0';
        }
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

corto_string corto_path(
    corto_id buffer,
    corto_object from,
    corto_object o,
    const char *sep)
{
    corto_assertObject(from);
    corto_assertObject(o);
    return corto_path_intern(buffer, from, o, sep, FALSE);
}

corto_string corto_pathname(
    corto_id buffer,
    corto_object from,
    corto_object o,
    const char *sep)
{
    corto_assertObject(from);
    corto_assertObject(o);
    return corto_path_intern(buffer, from, o, sep, TRUE);
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

corto_string corto_cleanpath(corto_id buf, char *path) {
    corto_id work, tempbuf;
    char *cp, *thisp, *nextp = work;
    corto_bool threadStr = FALSE;
    corto_bool equalBuf = TRUE;

    if (!buf) {
        buf = corto_alloc(sizeof(corto_id));
        threadStr = TRUE;
    } else if (buf == path) {
        equalBuf = TRUE;
        buf = tempbuf;
    }

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

    if (threadStr) {
        corto_string tmp = buf;
        path = corto_setThreadString(buf);
        corto_dealloc(tmp);
    } else if (equalBuf) {
        strcpy(path, buf);
    } else {
        path = buf;
    }

    return path;
}

corto_object corto_ownerof(corto_object o) {
    corto_assertObject(o);

    corto__object* _o;
    corto__persistent* persistent;
    corto_object result = NULL;

    if (!corto_checkState(o, CORTO_DECLARED) && corto_checkAttr(o, CORTO_ATTR_SCOPED)) {
        o = corto_parentof(o);
        while (o && !corto_checkState(o, CORTO_DECLARED)) {
            o = corto_parentof(o);
        }
    }

    if (o && corto_checkAttr(o, CORTO_ATTR_PERSISTENT)) {
        _o = CORTO_OFFSET(o, -sizeof(corto__object));
        persistent = corto__objectPersistent(_o);
        result = persistent->owner;
    }

    return result;
}

static corto_bool corto_ownerMatch(corto_object owner, corto_object current) {
    corto_bool result;

    if (owner == current) {
        result = TRUE;
    } else if (owner && corto_instanceof(corto_mount_o, owner)) {
        if (!current) {
            if (corto_mount(owner)->kind != CORTO_SINK) {
                result = FALSE;
            } else {
                result = TRUE;
            }
        } else {
            result = FALSE;
        }
    } else if (current && corto_instanceof(corto_mount_o, current)) {
        if (!owner) {
            if (corto_mount(current)->kind != CORTO_SINK) {
                result = FALSE;
            } else {
                result = TRUE;
            }
        } else {
            result = FALSE;
        }
    } else {
        /* Owner is set, but not a mount. Object is owned by local process */
        result = TRUE;
    }

    return result;
}

corto_bool corto_owned(corto_object o) {
    corto_assertObject(o);

    corto_object owner = corto_ownerof(o);
    corto_object current = corto_getOwner();
    corto_bool result = FALSE;

    if (!corto_checkState(o, CORTO_DEFINED)) {
        /* If object is not DEFINED it is not owned yet, and it's fair game */
        result = TRUE;
    } else {
        result = corto_ownerMatch(owner, current);
    }

    return result;
}

corto_int32 corto_claim_ext(corto_object src, corto_object o, corto_string context) {
    corto_assertObject(src);
    corto_assertObject(o);

    corto__object* _o;
    corto_uint32 i;
    CORTO_UNUSED(src);
    CORTO_UNUSED(context);

    _o = CORTO_OFFSET(o, -sizeof(corto__object));
    i = corto_ainc(&_o->refcount);

    if (CORTO_TRACE_OBJECT || CORTO_TRACE_ID) corto_memtrace("claim", o, context);

    return i;
}

corto_int32 corto_release_ext(corto_object src, corto_object o, corto_string context) {
    corto_assertObject(src);
    corto_assertObject(o);

    corto_int32 i;
    corto__object* _o;
    CORTO_UNUSED(src);
    CORTO_UNUSED(context);

    _o = CORTO_OFFSET(o, -sizeof(corto__object));
    i = corto_adec(&_o->refcount);

    if (CORTO_TRACE_OBJECT || CORTO_TRACE_ID) corto_memtrace("release", o, context);
    if (CORTO_TRACE_OBJECT || CORTO_TRACE_ID) corto_memtracePush();

    if (!i) {
        corto_destruct(o, FALSE);
    } else if (i < 0) {
        corto_critical("negative reference count of object (%p) '%s' of type '%s'",
            o, corto_fullpath(NULL, o), corto_fullpath(NULL, corto_typeof(o)));
        corto_backtrace(stdout);
    }
    if (CORTO_TRACE_OBJECT || CORTO_TRACE_ID) corto_memtracePop();

    return i;
}

corto_int32 corto_claim(corto_object o) {
    corto_assertObject(o);
    return corto_claim_ext(NULL, o, NULL);
}

corto_int32 corto_release(corto_object o) {
    corto_assertObject(o);
    return corto_release_ext(NULL, o, NULL);
}

static corto_object corto_lookup_intern(
    corto_object parent,
    corto_string id,
    corto_bool resume)
{
    corto_assertObject(parent);

    if (!parent) {
        parent = root_o;
    }

    corto_object o = parent;
    corto__object *_o, *_result;
    corto__scope* scope;
    corto_rbtree tree;
    corto_object prev = NULL;
    char ch, *next, *ptr = id;

    if (!id || !id[0]) {
        corto_seterr("invalid identifier");
        goto error;
    }

    if (id[0] == '/') {
        o = root_o;
    }

    int i = 0;
    do {
        _o = CORTO_OFFSET(o, -sizeof(corto__object));
        scope = corto__objectScope(_o);
        if (i) {
            prev = o;
        }
        i++;

        if (ptr[0] == '/') {
            ptr ++;
        }
        if (!ptr[0]) {
            break;
        }

        corto_bool containsArgs = FALSE;
        for (next = ptr; (ch = *next) && (ch != '/'); next ++) {
            if (ch == '(') {
                containsArgs = TRUE;
                for (next ++; (ch = *next) && (ch != ')'); next ++);
            }
        }

        if ((ptr[0] == '.') && (&ptr[1] == next)) {
            /* do nothing */
        } else if ((ptr[0] == '.') && (ptr[1] == '.') && (&ptr[2] == next)) {
            o = corto_parentof(o);
        } else if (scope) {
            if ((tree = scope->scope)) {
                if (containsArgs) {
                    corto_int32 diff;
                    o = corto_lookupFunction(o, ptr, NULL, &diff);
                    if (!diff) { /* Ambiguous reference */
                        if (o) corto_release(o);
                        corto_setinfo("ambiguous reference '%s'", ptr);
                        goto error;
                    }

                    if (o) corto_release(o);
                } else {
                    corto_rwmutexRead(&scope->align.scopeLock);
                    if (!corto_rbtreeHasKey_w_cmp(
                          tree,
                          ptr,
                          (void**)&o,
                          corto_compareLookup))
                    {
                        o = NULL;
                    } else if (strchr(corto_idof(o), '(')) {
                        corto_object checkNoArgs = NULL;

                        /* If requesting an id without '()' and an id with '()'
                         * is returned, look again without allowing for '()' to
                         * give preference to an object without '()' */
                        if (corto_rbtreeHasKey_w_cmp(
                              tree,
                              ptr,
                              (void**)&checkNoArgs,
                              corto_compareLookupNoArgMatching))
                        {
                            o = checkNoArgs;
                        } else if (corto_instanceof(corto_function_o, o)) {
                            if (corto_function(o)->overloaded == TRUE) {
                                corto_setinfo("ambiguous reference '%s'", id);
                                corto_rwmutexUnlock(&scope->align.scopeLock);
                                goto error;
                            }
                        }
                    }
                    corto_rwmutexUnlock(&scope->align.scopeLock);
                }
            } else {
                o = NULL;
            }

        } else {
            /* Walking a non-scoped object should not be possible */
            corto_critical("corto_lookup: object '%s' has no scope",
                corto_fullpath(NULL, o));
            goto error;
        }

        /* Keep object. If the refcount was zero, this object will be deleted soon, so prevent the object from being referenced again. */
        if (o && (corto_claim(o) == 1)) {
             /* Set the refcount to zero again. There can be no more objects that are looking up this object right now because
              * we have the scopeLock of the parent. Additionally, the object will not yet have been free'd because the destruct
              * function also needs the parent's scopelock to remove the object from the scope.
              *
              * The refcount needs to be re-set to zero, because after the scopeLock is released, other threads - other than the destruct
              * thread might try to acquire this object. Setting the refcount back to zero will enable these lookups to also detect
              * that the object is being deleted.
              */
            _result = CORTO_OFFSET(o, -sizeof(corto__object));
            _result->refcount = 0;
            o = NULL;
        }

        if (prev) {
            corto_release(prev);
        }

        if (!o) {
            break;
        }

        ptr = next;
    } while (ch);

    if (resume) {
        if (!prev) {
            prev = parent;
        }
        if (!o) {
            o = corto_resume(prev, ptr, NULL);
        }
    }

    if (o && corto_secured() && !corto_authorized(o, CORTO_SECURE_ACTION_READ)) {
        goto access_error;
    }

    return o;
access_error:
    corto_release(o);
error:
    return NULL;
}

corto_object corto_lookup(corto_object scope, corto_string id)
{
    return corto_lookup_intern(scope, id, TRUE);
}

corto_object corto_find(corto_object scope, corto_string id, corto_findKind mode)
{
    return corto_lookup_intern(scope, id, mode & CORTO_FIND_RESUME);
}

corto_bool corto_match(corto_string expr, corto_string str) {
    struct corto_matchProgram_s matcher;
    if (corto_matchProgramParseIntern(&matcher, expr, TRUE, TRUE)) {
        goto error;
    }
    corto_bool result = corto_matchProgram_run(&matcher, str);
    corto_dealloc(matcher.tokens);
    return result;
error:
    return FALSE;
}

corto_object corto_setOwner(corto_object owner) {
    corto_assertObject(owner);
    corto_object result = corto_threadTlsGet(CORTO_KEY_OWNER);
    corto_threadTlsSet(CORTO_KEY_OWNER, owner);
    return result;
}

corto_object corto_getOwner() {
    return corto_threadTlsGet(CORTO_KEY_OWNER);
}

/* Publish new value for object */
corto_int16 corto_publish(
    corto_eventMask event,
    corto_string id,
    corto_string type,
    corto_string contentType,
    void *content)
{
    corto_object o = corto_find(NULL, id, CORTO_FIND_DEFAULT);
    corto_int16 result = 0;

    CORTO_UNUSED(type);

    if (o) {
        switch(event) {
        case CORTO_ON_DEFINE:
        case CORTO_ON_UPDATE:
            if (corto_typeof(o)->kind != CORTO_VOID) {
                if (!(result = corto_updateBegin(o))) {
                    if ((result = corto_fromcontent(o, contentType, content))) {
                        corto_updateCancel(o);
                    } else {
                        corto_updateEnd(o);
                    }
                }
            } else {
                corto_update(o);
            }
            break;
        case CORTO_ON_DELETE:
            result = corto_delete(o);
            break;
        }
        corto_release(o);
    } else {
        corto_id buffer;
        strcpy(buffer, id);
        if (corto_notifySubscribersId(
          event, buffer, type, contentType, (corto_word)content))
        {
            result = -1;
        }
    }

    return result;
}

/* Update object */
corto_int16 corto_update(corto_object o) {
    corto_assertObject(o);

    corto_int16 result = 0;
    corto_eventMask mask = CORTO_ON_UPDATE;

    if (!corto_owned(o) && (corto_typeof(corto_typeof(o)) != (corto_type)corto_target_o)) {
        corto_seterr("object not owned by thread");
        goto error;
    }

    if (corto_secured()) {
        if (!corto_authorized(o, CORTO_SECURE_ACTION_UPDATE)) {
            goto error;
        }
        if (!corto_checkState(o, CORTO_DEFINED)) {
            mask |= corto_resumeDeclared(o) ? CORTO_ON_RESUME : CORTO_ON_DEFINE;
            result = corto_defineDeclared(o, mask);
        } else {
            if (corto_notifySecured(o, CORTO_ON_UPDATE)) {
                goto error;
            }
        }
    } else {
        if (!corto_checkState(o, CORTO_DEFINED)) {
            mask |= corto_resumeDeclared(o) ? CORTO_ON_RESUME : CORTO_ON_DEFINE;
            result = corto_defineDeclared(o, mask);
        } else {
            if (corto_notify(o, CORTO_ON_UPDATE)) {
                goto error;
            }
        }
    }

    return result;
error:
    return -1;
}

corto_int16 corto_updateBegin(corto_object o) {
    corto_assertObject(o);
    corto_type type = corto_typeof(o);

    /* Update fails if process isn't authorized to update observable */
    if (corto_secured() && !corto_authorized(o, CORTO_SECURE_ACTION_UPDATE)) {
        goto error;
    }

    if (!corto_checkState(o, CORTO_DEFINED)) {
        corto_resumeDeclared(o);
    }

    if (!type->hasTarget && (corto_typeof(corto_typeof(o)) != (corto_type)corto_target_o) && !corto_owned(o)) {
        corto_seterr("updateBegin: cannot update '%s', process does not own object",
            corto_fullpath(NULL, o));
        goto error;
    }

    if (!corto_checkState(o, CORTO_DEFINED) && !corto_declaredAdminCheck(o)) {
        corto_seterr("updateBegin: cannot update '%s', object is being defined by other thread",
            corto_fullpath(NULL, o));
        goto error;
    }

    if (corto_checkState(o, CORTO_DEFINED)) {
        corto__writable* _wr = corto__objectWritable(CORTO_OFFSET(o, -sizeof(corto__object)));
        if (_wr) {
            if (corto_rwmutexWrite(&_wr->align.lock)) {
                corto_seterr("updateBegin: %s",
                    corto_fullpath(NULL, o), corto_lasterr());
                goto error;
            }
        } else {
            corto_warning(
                "updateBegin: calling updateBegin for non-writable '%s' is useless",
                corto_fullpath(NULL, o));
        }
    }

    return 0;
error:
    return -1;
}

corto_int16 corto_updateTry(corto_object observable) {
    corto_assertObject(observable);

    corto__writable* _wr;

    /* Notify fails if process isn't authorized to update observable */
    if (!corto_authorized(observable, CORTO_SECURE_ACTION_UPDATE)) {
        goto error;
    }

    _wr = corto__objectWritable(CORTO_OFFSET(observable, -sizeof(corto__object)));
    if (_wr) {
        if (corto_rwmutexTryWrite(&_wr->align.lock) == CORTO_LOCK_BUSY) {
            goto busy;
        }
    } else {
        corto_warning("calling updateTry for non-writable object '%s' is useless.",
            corto_fullpath(NULL, observable));
    }

    return 0;
error:
    return -1;
busy:
    return CORTO_LOCK_BUSY;
}

corto_int16 corto_updateEnd(corto_object observable) {
    corto_assertObject(observable);

    corto__writable* _wr;
    corto_int16 result = 0;
    corto_bool defined = TRUE;

    if (!corto_checkState(observable, CORTO_DEFINED)) {
        corto_object owner = corto_ownerof(observable);
        defined = FALSE;
        corto_eventMask mask = 0;
        if (owner && corto_instanceof(corto_mount_o, owner) &&
            (corto_mount(owner)->kind == CORTO_SINK))
        {
            /* If not defined, and owner is a SINK, object is resumed */
            mask |= CORTO_ON_RESUME;
        } else
        {
            mask |= CORTO_ON_DEFINE;
        }

        result = corto_defineDeclared(observable, mask);
    } else {
        if (!corto_secured()) {
            if (corto_notifySecured(observable, CORTO_ON_UPDATE)) {
                goto error;
            }
        } else {
            if (corto_notify(observable, CORTO_ON_UPDATE)) {
                goto error;
            }
        }
    }

    if (defined) {
        _wr = corto__objectWritable(CORTO_OFFSET(observable, -sizeof(corto__object)));
        if (_wr) {
            if (corto_rwmutexUnlock(&_wr->align.lock)) {
                corto_seterr("updateEnd: unlock on '%s' failed (%s)",
                  corto_fullpath(NULL, observable), corto_lasterr());
            }
        }
    }

    return result;
error:
    return -1;
}

corto_int16 corto_updateCancel(corto_object observable) {
    corto_assertObject(observable);

    if (corto_checkAttr(observable, CORTO_ATTR_OBSERVABLE)) {
        corto__writable* _wr;

        _wr = corto__objectWritable(CORTO_OFFSET(observable, -sizeof(corto__object)));

        if (corto_rwmutexUnlock(&_wr->align.lock)) {
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

/* REPL functionality */
corto_int16 corto_expr(corto_object scope, corto_string expr, corto_value *value) {
    corto_assertObject(scope);

    corto_object o = corto_resolve(scope, expr);
    if (o) {
        *value = corto_value_object(o, NULL);
    }

    /* eventually this function will use the parser to evaluate expressions */

    return o == NULL;
}

static char* corto_manIdEscape(corto_object from, corto_object o, corto_id buffer) {
    corto_assertObject(from);
    corto_assertObject(o);

    corto_path(buffer, from, o, "_");

    return &buffer[strlen(buffer)];
}

char* corto_manId(corto_object o, corto_id buffer) {
    corto_assertObject(o);

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
    corto_assertObject(o);

    corto_id id;
    corto_manId(o, id);
    return corto_resolve(NULL, id);
}

/* Thread-safe reading */
corto_int16 corto_readBegin(corto_object object) {
    corto_assertObject(object);

    if (corto_checkAttr(object, CORTO_ATTR_WRITABLE)) {
        corto__writable* _o;

        _o = corto__objectWritable(CORTO_OFFSET(object, -sizeof(corto__object)));
        if (corto_rwmutexRead(&_o->align.lock)) {
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
    corto_assertObject(object);
    return corto_unlock(object);
}

/* Thread-safe writing */
corto_int16 corto_lock(corto_object object) {
    corto_assertObject(object);

    if (corto_checkAttr(object, CORTO_ATTR_WRITABLE)) {
        corto__writable* _o;

        _o = corto__objectWritable(CORTO_OFFSET(object, -sizeof(corto__object)));
        if (corto_rwmutexWrite(&_o->align.lock)) {
            goto error;
        }
    }

    return 0;
error:
    return -1;
}

corto_int16 corto_unlock(corto_object object) {
    corto_assertObject(object);

    if (corto_checkAttr(object, CORTO_ATTR_WRITABLE)) {
        corto__writable* _o;

        _o = corto__objectWritable(CORTO_OFFSET(object, -sizeof(corto__object)));
        if (corto_rwmutexUnlock(&_o->align.lock)) {
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
            } else if (ch == ':') {
                if (srcptr[1] != ':') {
                    *bptr = '\0';
                    if (!strcmp(buffer, "in")) {
                        *flags |= CORTO_PARAMETER_IN;
                    } else if (!strcmp(buffer, "out")) {
                        *flags |= CORTO_PARAMETER_OUT;
                    } else if (!strcmp(buffer, "inout")) {
                        *flags |= CORTO_PARAMETER_IN|CORTO_PARAMETER_OUT;
                    } else {
                        corto_seterr("invalid parameter modifier '%s'", buffer);
                        goto error;
                    }
                    bptr = buffer;
                } else {
                    parsing = TRUE;
                    *bptr = ch;
                    bptr++;     
                    *bptr = ch;
                    bptr++;
                    srcptr++;               
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
    corto_assertObject(o);

    corto_uint32 result;
    if (corto_interface(corto_typeof(o))->kind == CORTO_PROCEDURE) {
        result = corto_function(o)->parameters.length;
    } else {
        result = corto_delegate(corto_typeof(o))->parameters.length;
    }
    return result;
}

/* Helper function that obtains type from signature */
corto_type corto_overloadParamType(corto_object object, corto_int32 i, corto_bool *reference) {
    corto_assertObject(object);

    corto_id buffer;
    corto_int32 flags = 0;
    corto_id signatureBuffer;
    char *signature;
    corto_type result;

    if (!(signature = corto_signature(object, signatureBuffer))) {
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

    result = corto_resolve(corto_parentof(object), buffer);
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

    corto_assertObject(o_type);
    corto_assertObject(r_type);

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
            fprintf(stderr, "null but not reference or text!\n");
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
    corto_assertObject(o);

    corto_delegate type = corto_delegate(corto_typeof(o));
    corto_uint32 i;

    /* Construct signature */
    corto_string signature = corto_signatureOpen(corto_idof(o));
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
char* corto_signature(corto_object object, corto_id buffer) {
    corto_type t = corto_typeof(object);

    switch(((corto_interface)t)->kind) {
    case CORTO_DELEGATE:
        corto_signatureFromDelegate(object, buffer);
        break;
    case CORTO_PROCEDURE:
        return corto_idof(object);
    default:
        goto error;
    }

    return buffer;
error:
    corto_seterr(
      "can't get signature from '%s' of non-procedure type '%s'",
      corto_fullpath(NULL, object),
      corto_fullpath(NULL, t));    abort();
    return NULL;
}

static corto_bool corto_signatureCompareName(char *offered, char *requested) {
    /* Validate if names of request and offered match */
    char *o_ptr = offered, o_ch, *r_ptr = requested, r_ch = *r_ptr;
    while ((o_ch = *o_ptr) && (r_ch = *r_ptr) &&
           (o_ch != '(') && (r_ch != '('))
    {
        o_ch = tolower(o_ch);
        r_ch = tolower(r_ch);
        if (o_ch != r_ch) break;
        o_ptr ++;
        r_ptr ++;
    }
    if (o_ch != r_ch) {
        return FALSE;
    }
    return TRUE;
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
    corto_assertObject(object);

    corto_int32 r_parameterCount, o_parameterCount;
    corto_int32 i = 0, d = 0;
    corto_id offeredBuffer;
    char *offered;

    /* Validate if function object is valid */
    if (!corto_checkState(object, CORTO_VALID)) {
        goto error;
    }

    /* Obtain offered singature */
    if (!(offered = corto_signature(object, offeredBuffer))) {
        goto error;
    }

    if (!corto_signatureCompareName(offered, requested)) {
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
            corto_id r_typeName, o_typeName;
            int flags, o_flags, paramDistance = 0;

            /* Obtain offered and requested type */
            if (!(o_type = corto_overloadParamType(object, i, &o_reference))) {
                goto error;
            }

            if (corto_signatureParamType(requested, i, r_typeName, &flags)) {
                goto error;
            }
            if (corto_signatureParamType(corto_idof(object), i, o_typeName, &o_flags)) {
                goto error;
            }

            if (strcmp(r_typeName, o_typeName) || (flags != o_flags)) {
                if (!(flags & (CORTO_PARAMETER_WILDCARD | CORTO_PARAMETER_NULL))) {
                    r_type = corto_resolve(NULL, r_typeName);
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

typedef struct corto_scopeWalk_t {
    corto_objectseq *seq;
    corto_type type;
    corto_string id;
} corto_scopeWalk_t;

static int corto_scopeCollectWalk(corto_object o, void* userData) {
    corto_assertObject(o);
    corto_scopeWalk_t *data = userData;
    corto_objectseq *seq = data->seq;

    if (!data->type || (corto_typeof(o) == data->type)) {
        if (!data->id || (corto_signatureCompareName(data->id, corto_idof(o)))) {
            if (!seq->buffer) {
                /* Get scopesize within scope lock */
                corto_uint32 scopeSize = corto_scopeSize(corto_parentof(o));
                seq->buffer = corto_alloc(sizeof(corto_object) * scopeSize);
                /* Increment length with each object */
            }
            corto_claim(o);
            seq->buffer[seq->length++] = o;
        }
    }

    return 1;
}

corto_objectseq corto_scopeClaimWithFilter(corto_object scope, corto_type type, corto_string id) {
    corto_assertObject(scope);
    corto_objectseq result = {0, NULL};
    corto_scopeWalk_t walkData;
    walkData.seq = &result;
    walkData.type = type;
    walkData.id = id;
    corto_scopeWalk(scope, corto_scopeCollectWalk, &walkData);
    return result;
}

corto_objectseq corto_scopeClaim(corto_object scope) {
    return corto_scopeClaimWithFilter(scope, NULL, NULL);
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
        (corto_interface(corto_typeof(o))->kind == CORTO_DELEGATE)))
    {
        if (strchr(data->request, '(')) {
            if (corto_overload(o, data->request, &d)) {
                data->error = TRUE;
                goto found;
            }
        } else {
            corto_id sigName;
            corto_signatureName(corto_idof(o), sigName);

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
        if (!stricmp(corto_idof(o), data->request)) {
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
corto_object* corto_lookupFunctionFromSequence(
    corto_objectseq scopeContents,
    corto_string requested,
    corto_int32* d,
    corto_int32* diff)
{
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

    if (diff) {
        /* If difference is zero, reference is ambiguous */
        if (walkData.d != INT_MAX) {
            *diff = walkData.old_d - walkData.d;
        } else {
            *diff = INT_MAX;
        }
    }

    if (walkData.error) walkData.result = NULL;

    return walkData.result;
}

corto_object corto_lookupFunction(
    corto_object scope,
    corto_string requested,
    corto_int32 *d,
    corto_int32 *diff)
{
    corto_assertObject(scope);

    corto_objectseq scopeContents = corto_scopeClaim(scope);
    corto_object result = NULL;

    if (diff) {
        *diff = INT_MAX;
    }

    corto_object *ptr = corto_lookupFunctionFromSequence(scopeContents, requested, d, diff);
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
            strcpy(id, corto_idof(type));
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
    corto_assertObject(value);

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
    corto_assertObject(object);

    corto_string_ser_t serData;
    struct corto_serializer_s s;

    serData.buffer = CORTO_BUFFER_INIT;
    serData.buffer.max = maxLength;
    serData.compactNotation = TRUE;
    serData.prefixType = FALSE;
    serData.enableColors = FALSE;

    s = corto_string_ser(CORTO_LOCAL, CORTO_NOT, CORTO_SERIALIZER_TRACE_NEVER);
    corto_serialize(&s, object, &serData);
    corto_string result = corto_buffer_str(&serData.buffer);
    corto_serializeDestruct(&s, &serData);
    return result;
}

corto_string corto_strv(corto_value* v, corto_uint32 maxLength) {
    corto_string_ser_t serData;
    struct corto_serializer_s s;

    serData.buffer = CORTO_BUFFER_INIT;
    serData.buffer.max = maxLength;
    serData.compactNotation = TRUE;
    serData.prefixType = FALSE;
    serData.enableColors = FALSE;

    s = corto_string_ser(CORTO_LOCAL, CORTO_NOT, CORTO_SERIALIZER_TRACE_NEVER);
    corto_serializeValue(&s, v, &serData);
    corto_string result = corto_buffer_str(&serData.buffer);
    corto_serializeDestruct(&s, &serData);
    return result;
}

corto_string _corto_strp(void *p, corto_type type, corto_uint32 maxLength) {
    corto_assertObject(type);

    corto_value v;
    v = corto_value_value(type, p);
    return corto_strv(&v, maxLength);
}

corto_string corto_stra(corto_any a, corto_uint32 maxLength) {
    corto_value v;
    v = corto_value_value(a.type, a.value);
    return corto_strv(&v, maxLength);
}

corto_int16 corto_fromStr(void *o, corto_string string) {
    corto_string_deser_t serData;

    serData.out = *(void**)o;
    serData.scope = NULL;
    serData.type = *(void**)o ? corto_typeof(*(void**)o) : NULL;
    serData.isObject = TRUE;
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

    serData.out = corto_value_getPtr(v);
    serData.scope = NULL;
    serData.type = corto_value_getType(v);
    serData.isObject = v->kind == CORTO_OBJECT;
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
    corto_assertObject(type);

    corto_string_deser_t serData;

    serData.out = *(void**)out;
    serData.scope = NULL;
    serData.type = type;
    serData.isObject = FALSE;
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
    serData.isObject = FALSE;
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
    corto_assertObject(o1);
    corto_assertObject(o2);

    corto_compare_ser_t data;
    struct corto_serializer_s s;

    data.value = corto_value_value(corto_typeof(o2), o2);

    s = corto_compare_ser(CORTO_PRIVATE, CORTO_NOT, CORTO_SERIALIZER_TRACE_NEVER);

    corto_serialize(&s, o1, &data);

    return data.result;
}

corto_equalityKind corto_comparev(corto_value *value1, corto_value *value2) {
    corto_compare_ser_t data;
    struct corto_serializer_s s;

    data.value = *value2;
    s = corto_compare_ser(CORTO_PRIVATE, CORTO_NOT, CORTO_SERIALIZER_TRACE_NEVER);

    corto_serializeValue(&s, value1, &data);

    return data.result;
}

corto_equalityKind _corto_comparep(void *p1, corto_type type, void *p2) {
    corto_assertObject(type);

    corto_value vdst;
    corto_value vsrc;
    vdst = corto_value_value(type, p1);
    vsrc = corto_value_value(type, p2);
    return corto_comparev(&vdst, &vsrc);
}

corto_equalityKind corto_comparea(corto_any a1, corto_any a2) {
    corto_value vdst;
    corto_value vsrc;
    vdst = corto_value_value(a1.type, a1.value);
    vsrc = corto_value_value(a2.type, a2.value);
    return corto_comparev(&vdst, &vsrc);
}

corto_int16 corto_init(corto_object o) {
    corto_benchmark_start(CORTO_BENCHMARK_INIT);
    corto_int16 result;
    corto_assertObject(o);
    corto_typeKind kind = corto_typeof(o)->kind;

    switch(kind) {
        case CORTO_COMPOSITE:
        case CORTO_COLLECTION: {
            struct corto_serializer_s s = corto_ser_init(0, CORTO_NOT, CORTO_SERIALIZER_TRACE_ON_FAIL);
            if (corto_serialize(&s, o, NULL)) {
                goto error;
            }
            break;
        }
        default:
            break;
    }
    result = corto_delegateInit(corto_typeof(o), o);
    corto_benchmark_stop(CORTO_BENCHMARK_INIT);
    return result;
error:
    corto_benchmark_stop(CORTO_BENCHMARK_INIT);
    return -1;
}

corto_int16 corto_initv(corto_value *v) {
    struct corto_serializer_s s = corto_ser_init(0, CORTO_NOT, CORTO_SERIALIZER_TRACE_ON_FAIL);
    if (corto_serializeValue(&s, v, NULL)) {
        return -1;
    }
    return corto_delegateInit(corto_value_getType(v), corto_value_getPtr(v));
}

corto_int16 _corto_initp(void *p, corto_type type) {
    corto_assertObject(type);
    corto_value v;
    v = corto_value_value(type, p);
    return corto_initv(&v);
}

corto_int16 corto_inita(corto_any a) {
    corto_value v;
    v = corto_value_value(a.type, a.value);
    return corto_initv(&v);
}

corto_int16 corto_deinit(corto_object o) {
    corto_assertObject(o);
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
    corto_assertObject(type);
    corto_value v;
    v = corto_value_value(type, p);
    return corto_deinitv(&v);
}

corto_int16 corto_deinita(corto_any a) {
    corto_value v;
    v = corto_value_value(a.type, a.value);
    return corto_deinitv(&v);
}

corto_int16 _corto_copy(corto_object *dst, corto_object src) {
    corto_assertObject(src);

    struct corto_serializer_s s = corto_copy_ser(CORTO_PRIVATE, CORTO_NOT, CORTO_SERIALIZER_TRACE_ON_FAIL);
    corto_copy_ser_t data;
    corto_int16 result;
    corto_bool newObject = FALSE;

    if (!*dst) {
        *dst = corto_declare(corto_typeof(src));
        newObject = TRUE;
    }

    data.value = corto_value_object(*dst, NULL);
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

    if (!corto_value_getPtr(dst)) {
        *dst = corto_value_value(corto_value_getType(src), corto_declare(corto_value_getType(src)));
        newObject = TRUE;
    }

    data.value = *dst;
    result = corto_serializeValue(&s, src, &data);

    if (newObject) {
        corto_define(corto_value_getPtr(dst));
    }

    return result;
}

corto_int16 _corto_copyp(void *dst, corto_type type, void *src) {
    corto_assertObject(type);

    corto_value vdst;
    corto_value vsrc;
    corto_int16 result;
    vdst = corto_value_value(type, dst);
    vsrc = corto_value_value(type, src);
    result = corto_copyv(&vdst, &vsrc);
    return result;
}

corto_int16 corto_copya(corto_any *dst, corto_any src) {
    corto_value vdst;
    corto_value vsrc;
    corto_int16 result;
    vdst = corto_value_value(corto_type(corto_any_o), dst);
    vsrc = corto_value_value(corto_type(corto_any_o), &src);
    result = corto_copyv(&vdst, &vsrc);
    return result;
}

corto_int16 _corto_augment(corto_type o, corto_string id, corto_mount r) {
    corto_assertObject(o);
    corto_assertObject(r);

    corto_ll augments = corto_olsLockGet(o, CORTO_OLS_AUGMENT);
    corto_augment_olsData_t *data = NULL;

    if (!augments) {
        augments = corto_llNew();
    }

    if (corto_llSize(augments) >= CORTO_MAX_AUGMENTS) {
        corto_seterr("maximum number of augments for scope set");
        corto_olsUnlockSet(o, CORTO_OLS_AUGMENT, augments);
        goto error;
    }

    data = corto_alloc(sizeof(corto_augment_olsData_t));
    data->mount = r;
    data->id = corto_strdup(id);
    corto_llAppend(augments, data);

    corto_olsUnlockSet(o, CORTO_OLS_AUGMENT, augments);

    return 0;
error:
    return -1;
}
