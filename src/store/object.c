/* Copyright (c) 2010-2018 the corto developers
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <corto/corto.h>

#include "../base/src/idmatch.h"
#include "src/lang/class.h"
#include "src/store/object.h"
#include "object.h"
#include "compare_ser.h"
#include "copy_ser.h"
#include "init_ser.h"
#include "memory_ser.h"

extern corto_mutex_s corto_adminLock;

static
corto_object corto_adopt(
    corto_object parent,
    corto_object child,
    bool forceType);

static
bool corto_ownerMatch(
    corto_object owner,
    corto_object current);

static
int16_t corto_define_intern(
    corto_object o,
    bool resume);

static
int16_t corto_lock_intern(
    corto_object object);

static
int16_t corto_unlock_intern(
    corto_object object);

extern corto_tls CORTO_KEY_ATTR;
extern corto_tls CORTO_KEY_DECLARED_ADMIN;
extern corto_tls CORTO_KEY_OWNER;
extern corto_tls CORTO_KEY_CONSTRUCTOR_TYPE;

int16_t corto_init(corto_object o);
int16_t corto_deinit(corto_object o);

void corto_declaredByMeFree(void *admin) {
    if (admin) {
        corto_ll_free(admin);
    }
}

static
bool corto_declaredByMeCheck(corto_object o) {
    corto_assertObject(o);
    if (!corto_isbuiltin(o)) {
        corto_ll admin = corto_tls_get(CORTO_KEY_DECLARED_ADMIN);
        if (!admin) {
            return FALSE;
        } else {
            return corto_ll_hasObject(admin, o) != 0;
        }
    } else {
        return true;
    }
}

static
void corto_declaredByMeAdd(corto_object o) {
    corto_assertObject(o);
    if (!corto_isbuiltin(o)) {
        corto_ll admin = corto_tls_get(CORTO_KEY_DECLARED_ADMIN);
        if (!admin) {
            admin = corto_ll_new();
            corto_tls_set(CORTO_KEY_DECLARED_ADMIN, admin);
        }
        corto_ll_append(admin, o);
    }
}

static
bool corto_declaredByMeRemove(corto_object o) {
    corto_assertObject(o);
    if (!corto_isbuiltin(o)) {
        corto_ll admin = corto_tls_get(CORTO_KEY_DECLARED_ADMIN);
        if (admin) {
            if (corto_ll_remove(admin, o)) {
                corto_unlock_intern(o);
                return TRUE;
            }
        }
        return FALSE;
    } else {
        return FALSE;
    }
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

static
corto__scope* corto__objectScope(
    corto__object* o)
{
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

static
corto__writable* corto__objectWritable(
    corto__object* o)
{
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

static
corto__persistent* corto__objectPersistent(
    corto__object* o)
{
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

static
void* corto__objectStartAddr(
    corto__object* o)
{
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

static
corto_equalityKind corto_compareDefault(
    corto_type this,
    const void* o1,
    const void* o2)
{
    int r;
    corto_assertObject(this);
    CORTO_UNUSED(this);
    return ((r = stricmp(o1, o2)) < 0) ? CORTO_LT : (r > 0) ? CORTO_GT : CORTO_EQ;
}

static
corto_equalityKind corto_compareLookupIntern(
    const char *o1,
    const char *o2,
    bool matchArgs)
{
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

static
corto_equalityKind corto_compareLookup(
    corto_type this,
    const void* o1,
    const void* o2)
{
    CORTO_UNUSED(this);
    return corto_compareLookupIntern(o1, o2, TRUE);
}

static
corto_equalityKind corto_compareLookupNoArgMatching(
    corto_type this,
    const void* o1,
    const void* o2)
{
    CORTO_UNUSED(this);
    return corto_compareLookupIntern(o1, o2, FALSE);
}

#ifndef NDEBUG
/* Stack for tracing memory management operations */
static char *memtrace[50];
static int8_t memtraceSp = 0;
static int8_t memtraceCount = 0;

static
void corto_memtracePush(void) {
    memtraceSp ++;
}

static
void corto_memtracePop(void) {
    memtraceSp --;
    if (memtrace[memtraceSp]) {
        corto_dealloc(memtrace[memtraceSp]);
        memtrace[memtraceSp] = NULL;
    }
}

static
void corto_memtrace(
    char *oper,
    corto_object o,
    const char *context)
{
    corto_id path;
    corto_assertObject(o);

    if (corto_check_attr(o, CORTO_ATTR_NAMED)) {
        corto_fullpath(path, o);
    } else {
        sprintf(path, "[%p]", o);
    }

    if (memtrace[memtraceSp]) {
        corto_dealloc(memtrace[memtraceSp]);
        memtrace[memtraceSp] = NULL;
    }

    memtrace[memtraceSp] = corto_asprintf("%s (%s) %s", path, oper, context ? context : "");

    if ((CORTO_TRACE_OBJECT == o) || (CORTO_TRACE_ID && !strcmp(path, CORTO_TRACE_ID))) {
        memtraceCount ++;

        printf("%d: %s: %s (count = %d, deleted = %d)\n",
            memtraceCount,
            oper,
            path,
            corto_countof(o),
            corto_check_state(o, CORTO_DELETED));

        if (context) {
            printf("    %s\n", context);
        }

        if (memtraceSp) {
            int32_t i = memtraceSp;
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

static
bool corto__checkStateXOR(
    corto_object o,
    uint8_t state)
{
    uint8_t ostate;
    corto__object* _o;

    corto_assertObject(o);

    _o = CORTO_OFFSET(o, -sizeof(corto__object));

    ostate = _o->align.attrs.state;
    if (ostate & CORTO_VALID) {
        ostate = CORTO_VALID;
    } else {
        ostate = CORTO_DECLARED;
    }

    return ostate & state;
}

struct corto_adopt_updateParents_t {
    corto_object old;
    corto_object new;
};

static
int corto_adopt_updateParents(
    corto_object object,
    void *ctx)
{
    struct corto_adopt_updateParents_t *data = ctx;
    corto__object *_o = CORTO_OFFSET(object, -sizeof(corto__object));
    corto__scope *_scope = corto__objectScope(_o);
    _scope->parent = data->new;
    corto_claim(data->new);
    corto_release(data->old);
    return 1;
}

static
int16_t corto_adopt_checkConstraints(
    corto_type parent,
    corto_type child)
{
    corto_type childType = corto_typeof(child);

    /* Check if parentType matches scopeType of child type */
    if (childType->options.parentType) {
        corto_type parentType = corto_typeof(parent);
        if ((childType->options.parentType != parentType) &&
           !corto_instanceof(childType->options.parentType, parent))
        {
            corto_throw("type of '%s' is not '%s'",
                    corto_fullpath(NULL, parent),
                    corto_fullpath(NULL, childType->options.parentType));
            goto error;
        }
    }

    /* If parentType is a tableinstance, check if child type matches
     * table type */
    if (corto_instanceof(corto_tableinstance_o, parent)) {
        if (childType != corto_type(corto_tableinstance_o)) {
            corto_struct tableType = corto_tableinstance(parent)->type;
            if ((corto_type(tableType) != childType)) {
                if (!corto_instanceof(childType, corto_container_o)) {
                    corto_throw("type '%s' does not match tabletype '%s' of '%s'",
                        corto_fullpath(NULL, childType),
                        corto_fullpath(NULL, tableType),
                        corto_fullpath(NULL, parent));
                    goto error;
                }
            }
        }
    }

    /* If parentType is a leaf, no childs are allowed */
    if (corto_instanceof(corto_leaf_o, corto_typeof(parent))) {
        corto_throw("cannot add children to leaf node '%s'",
            corto_fullpath(NULL, parent));
        goto error;
    }

    /* Check if parentState matches scopeState of child type */
    if (childType->options.parentState &&
        !corto__checkStateXOR(parent, childType->options.parentState))
    {
        uint32_t childState = childType->options.parentState;
        uint32_t parentState = corto_stateof(parent);
        char *parentStateStr = corto_ptr_str(&parentState, corto_state_o, 0);
        char *childStateStr = corto_ptr_str(&childState, corto_state_o, 0);
        corto_throw("parent '%s' is %s, must be %s",
            corto_fullpath(NULL, parent),
            parentStateStr,
            childStateStr);
        corto_dealloc(parentStateStr);
        corto_dealloc(childStateStr);
        goto error;
    }

    return 0;
error:
    return -1;
}


/* Replace unknown object with object that has a known type */
static
void corto_adopt_replaceUnknown(
    corto_object existing,
    corto_object child,
    corto__scope *c_scope)
{
    /* Move scope of the existing object to new object */
    corto__object *_existing = CORTO_OFFSET(existing, -sizeof(corto__object));
    corto__scope *e_scope = corto__objectScope(_existing);

    /* Set scope of existing (unknown) object to scope of new object */
    free(c_scope->id);
    c_scope->id = e_scope->id; /* Use existing id as it's the key in the tree */
    c_scope->scope = e_scope->scope;

    /* Manually orphan object. This ensures that corto_destruct won't try to
     * cleanup scope administration */
    e_scope->scope = NULL;
    e_scope->parent = NULL; /* orphan object */
    e_scope->id = NULL;

    /* Update parent pointers & transfer refcounts of childs */
    if (c_scope->scope) {
        struct corto_adopt_updateParents_t data = {.old = existing, .new = child};
        corto_rb_walk(c_scope->scope, corto_adopt_updateParents, &data);
    }

    /* If refcount of existing object is not 0 after releasing it, other objects
     * have references to it. Should not happen. */
    if(corto_release(existing) != 0) {
        corto_throw(
            "%d invalid reference(s) to '%s' [%p] of unknown type",
            corto_countof(existing),
            c_scope->id,
            existing);

        /* Immediately raise, so an application can stop
         * execution here to debug */
        corto_raise();
    }
}

/* Adopt an object */
static
corto_object corto_adopt(
    corto_object parent,
    corto_object child,
    bool forceType)
{
    corto__object *_parent, *_child;
    corto__scope *p_scope, *c_scope;
    corto_type childType;

    corto_assertObject(parent);
    corto_assertObject(child);

    _parent = CORTO_OFFSET(parent, -sizeof(corto__object));
    _child = CORTO_OFFSET(child, -sizeof(corto__object));
    childType = corto_typeof(child);

    /* Obtain pointers to scope of parent and child */
    p_scope = corto__objectScope(_parent);
    if (p_scope) {
        c_scope = corto__objectScope(_child);
        if (c_scope) {
            bool claimParent = true;

            /* Lock object before locking parent-scope, this ensures that
             * locking order isn't violated when defining the object. */
            corto_lock_intern(child);

            /* Insert child in parent-scope */
            if (corto_rwmutex_write(&p_scope->align.scopeLock))
                corto_critical("corto_adopt: lock operation on scopeLock of parent failed");

            if (!p_scope->scope) {
                p_scope->scope = corto_rb_new((corto_equals_cb)corto_compareDefault, NULL);
            }

            void *ptr = corto_rb_findOrSetPtr(p_scope->scope, c_scope->id);
            corto_object existing = *(corto_object*)ptr;

            /* If existing is of unknown type and child is not, move scope from
             * existing to child, and destruct existing object. */
            if (existing) {
                corto_type e_type = corto_typeof(existing);
                if (e_type == corto_unknown_o) {
                    if (childType != corto_unknown_o) {
                        corto_adopt_replaceUnknown(existing, child, c_scope);
                        claimParent = false;
                        existing = child;
                        *(corto_object*)ptr = child;
                    }
                }
            } else {
                existing = child;
                *(corto_object*)ptr = child;
            }

            /* If existing object has been found, return it */
            if (existing && (existing != child)) {
                if (corto_unlock_intern(child)) {
                    goto err_existing;
                }

                /* Check if the type of the existing & new object match */
                if (forceType && (corto_typeof(existing) != corto_typeof(child))) {
                    corto_throw("'%s' is already declared with type '%s'",
                      c_scope->id,
                      corto_fullpath(NULL, corto_typeof(existing)));
                    goto err_existing;
                }

                child = existing;
                claimParent = false; /* No need to reclaim the parent as no new
                                      * object is added to its scope */
            } else {
                /* Check if no constraints are violated by adding the child to
                 * the scope */
                if (corto_adopt_checkConstraints(parent, child)) {
                    goto error_constraints;
                }

                /* Add the object to the declared admin, which ensures that this
                 * thread will be able to resolve / redeclare the object, but
                 * other threads will only see the object after it is defined. */
                corto_declaredByMeAdd(child);
            }

            if (CORTO_TRACE_OBJECT || CORTO_TRACE_ID) corto_memtrace("declare", child, NULL);
            if (CORTO_TRACE_OBJECT || CORTO_TRACE_ID) corto_memtracePush();
            /* Parent must not be deleted before all childs are gone. */
            if (claimParent) corto_claim(parent);
            if (CORTO_TRACE_OBJECT || CORTO_TRACE_ID) corto_memtracePop();

            if (corto_rwmutex_unlock(&p_scope->align.scopeLock)) {
                corto_critical("corto_adopt: unlock operation on scopeLock of parent failed");
            }
        } else {
            corto_critical("corto_adopt: child-object is not scoped");
        }
    } else {
        corto_critical("corto_adopt: parent-object is not scoped");
    }

    return child;
error_constraints:
    c_scope->parent = NULL;
    corto_rb_remove(p_scope->scope, c_scope->id);
err_existing:
    corto_rwmutex_unlock(&p_scope->align.scopeLock);
    return NULL;
}

/* Orphan object - not a public function as this will only happen during destruction of an object. */
static
void corto_orphan(
    corto_object o)
{
    corto__object *_parent, *_child;
    corto__scope *p_scope, *c_scope;

    corto_assertObject(o);

    _child = CORTO_OFFSET(o, -sizeof(corto__object));
    c_scope = corto__objectScope(_child);

    if (c_scope->parent) {
        _parent = CORTO_OFFSET(c_scope->parent, -sizeof(corto__object));
        p_scope = corto__objectScope(_parent);

        /* Remove object from parent scope */
        if (corto_rwmutex_write(&p_scope->align.scopeLock)) goto err_parent_mutex;
        corto_rb_remove(p_scope->scope, (void*)corto_idof(o));

        if (corto_rwmutex_unlock(&p_scope->align.scopeLock)) goto err_parent_mutex;
    }

    return;
err_parent_mutex:
    corto_error("corto_orphan: lock operation of scopeLock of parent failed");
}

static
int16_t corto_setKeyvalues(
    corto_object o,
    const char *id,
    corto_struct type)
{
    if (type->keys.length) {
        corto_id idWithBraces;
        sprintf(idWithBraces, "{%s}", id);

        corto_string_deser_t serData = {
            .out = o,
            .members = type->keycache,
            .isObject = TRUE
        };

        /* Serializer returns pointer to where it stopped parsing, unless failed */
        if (!corto_string_deser(idWithBraces, &serData)) {
            corto_assert(!serData.out, "deserializer failed but out is set");
        }

        if (!serData.out) {
            corto_throw("cannot parse '%s' to keys", id);
            goto error;
        }
    }

    return 0;
error:
    return -1;
}

/* Initialze scope-part of object */
static
corto_object corto_init_scope(
    corto_object parent,
    const char *id,
    corto_type type,
    corto_object o,
    bool orphan,
    bool forceType)
{
    corto__object* _o;
    corto__scope* scope;
    corto_object result = NULL;

    _o = CORTO_OFFSET(o, -sizeof(corto__object));
    scope = corto__objectScope(_o);

    /* Temporarily assign id */
    scope->id = id ? corto_strdup(id) : NULL;

    /* Set parent, so that initializer can refer to it */
    scope->parent = parent;
    corto_rwmutex_new(&scope->align.scopeLock);

    /* Add object to the scope of the parent-object */
    if (!orphan && corto_check_attr(parent, CORTO_ATTR_NAMED)) {
        if (!(result = corto_adopt(parent, o, forceType))) {
            /* Reset parent so deinitScope won't release it */
            scope->parent = NULL;
            goto error;
        }
    } else {
        result = o;
        corto_declaredByMeAdd(o);
        corto_lock_intern(o);
    }

    if (result != o) {
        corto_rwmutex_free(&scope->align.scopeLock);
        _o = CORTO_OFFSET(result, -sizeof(corto__object));
        scope = corto__objectScope(_o);
    } else {
        /* Set keyvalues from id if object has any */
        if (id && corto_instanceof(corto_struct_o, type)) {
            if (corto_setKeyvalues(o, id, (corto_struct)type)) {
                /* Remove object from scope */
                corto_orphan(o);
                goto error;
            }
        }

        /* Call framework initializer. */
        if (corto_init(o)) {
            /* Remove object from scope */
            corto_orphan(o);

            /* Reset parent so deinitScope won't release it */
            scope->parent = NULL;

            corto_throw(NULL);
            goto error;
        }
    }

    return result;
error:
    return NULL;
}

static
void corto_deinit_scope(
    corto_object o)
{
    corto__object *_o;
    corto__scope* scope;

    corto_assertObject(o);

    /* Obtain own scope */
    _o = CORTO_OFFSET(o, -sizeof(corto__object));
    scope = corto__objectScope(_o);
    corto_assert(scope != NULL,
        "corto_deinit_scope: called on non-scoped object <%p>.", o);

    /* Free parent */
    if (scope->parent && !corto_isorphan(o)) {
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

    /* Finally, free own scopeLock. */
    corto_rwmutex_free(&scope->align.scopeLock);
}

/* Initialize writable-part of object */
static
void corto__initWritable(
    corto_object o)
{
    corto__object* _o;
    corto__writable* writable;

    corto_assertObject(o);

    _o = CORTO_OFFSET(o, -sizeof(corto__object));
    writable = corto__objectWritable(_o);
    corto_assert(writable != NULL, "corto__initWritable: created writable object, but corto__objectWritable returned NULL.");

    corto_rwmutex_new(&writable->align.lock);
}

static
void corto__deinitWritable(
    corto_object o)
{
    corto__object* _o;
    corto__writable* writable;

    corto_assertObject(o);

    _o = CORTO_OFFSET(o, -sizeof(corto__object));
    writable = corto__objectWritable(_o);
    corto_assert(writable != NULL, "corto__deinitWritable: called on non-writable object <%p>.", o);

    corto_rwmutex_free(&writable->align.lock);
}

/* Initialize observable-part of object */
static
void corto__initObservable(
    corto_object o)
{
    corto__object* _o;
    corto__observable *observable;

    corto_assertObject(o);

    _o = CORTO_OFFSET(o, -sizeof(corto__object));
    observable = corto__objectObservable(_o);
    corto_assert(observable != NULL, "corto__initObservable: created observable object, but corto__objectObservable returned NULL.");

    corto_rwmutex_new(&observable->align.selfLock);

    observable->onSelf = NULL;
    observable->onChild = NULL;
    observable->onSelfArray = NULL;
    observable->onChildArray = NULL;
}

static
void corto__deinitObservable(
    corto_object o)
{
    corto__object* _o;
    corto__observable* observable;

    corto_assertObject(o);

    _o = CORTO_OFFSET(o, -sizeof(corto__object));
    observable = corto__objectObservable(_o);
    corto_assert(observable != NULL, "corto__deinitObservable: called on non-observable object <%p>.", o);

    /* Delete observer objects in onSelf and onChild */
    if (observable->onSelf) {
        corto__observer* observer;
        while((observer = corto_ll_takeFirst(observable->onSelf))) {
            if (!--observer->count) {
                observer->observer->active --;
                corto_dealloc(observer);
            }
        }
        corto_ll_free(observable->onSelf);
        observable->onSelf = NULL;
    }

    if (observable->onChild) {
        corto__observer* observer;
        while((observer = corto_ll_takeFirst(observable->onChild))) {
            if (!--observer->count) {
                observer->observer->active --;
                corto_dealloc(observer);
            }
        }
        corto_ll_free(observable->onChild);
        observable->onChild = NULL;
    }

    corto_rwmutex_free(&observable->align.selfLock);
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
    corto_rwmutex_new(&scope->align.scopeLock);
    if (scope->parent) {
        corto_adopt(scope->parent, sso, TRUE);
    }

    /* Init observable */
    if (corto_check_attr(sso, CORTO_ATTR_OBSERVABLE)) {
        corto__initObservable(sso);
    }
}

/* Deinitialize static scoped object */
int16_t corto__freeSSO(corto_object sso) {
    corto__object* o;
    corto__scope* scope;

    corto_assertObject(sso);

    o = CORTO_OFFSET(sso, -sizeof(corto__object));
    scope = corto__objectScope(o);

    corto_assert(scope != NULL, "corto__freeSSO: static scoped object has no scope");

    corto_orphan(sso);

    if (scope->scope) {
        /* Don't print this error - without a proper cycle detector this could
         * be reported without there actually being a problem
        if (corto_rb_count(scope->scope)) {
            corto_error("corto__freeSSO: scope of object '%s' is not empty (%p/%p: %d left)",
                corto_idof(sso),
                sso,
                scope->scope,
                corto_rb_count(scope->scope));
            goto error;
        }*/
        corto_rb_free(scope->scope);
        scope->scope = NULL;
    }

    corto_rwmutex_free(&scope->align.scopeLock);

    /* Deinitialize observable */
    if (corto_check_attr(sso, CORTO_ATTR_OBSERVABLE)) {
        corto__deinitObservable(sso);
    }

    return 0;
}

int16_t corto_callInitDelegate(corto_initAction *d, corto_type t, corto_object o, bool isDefine) {
    int16_t result = 0;
    corto_function delegate;

    if ((delegate = d->super.procedure)) {
        corto_interface prev = NULL;
        bool hasBase = (t->kind == CORTO_COMPOSITE) && ((corto_interface)t)->base;
        if (hasBase) {
            prev = corto_tls_get(CORTO_KEY_CONSTRUCTOR_TYPE);
            corto_tls_set(CORTO_KEY_CONSTRUCTOR_TYPE, t);
        }
        if (delegate->kind == CORTO_PROCEDURE_CDECL) {
            result = ((int16_t ___ (*)(corto_object))delegate->fptr)(o);
        } else {
            corto_callb(delegate, &result, (void*[]){&o});
        }
        if (hasBase) corto_tls_set(CORTO_KEY_CONSTRUCTOR_TYPE, prev);
    }

    return result;
}

void corto_callDestructDelegate(corto_destructAction *d, corto_type t, corto_object o) {
    corto_function delegate;
    if ((delegate = d->super.procedure)) {
        corto_interface prev;
        bool hasBase = (t->kind == CORTO_COMPOSITE) && ((corto_interface)t)->base;
        if (hasBase) {
            prev = corto_tls_get(CORTO_KEY_CONSTRUCTOR_TYPE);
            corto_tls_set(CORTO_KEY_CONSTRUCTOR_TYPE, t);
        }
        if (delegate->kind == CORTO_PROCEDURE_CDECL) {
            ((void ___ (*)(corto_object))delegate->fptr)(o);
        } else {
            corto_callb(delegate, NULL, (void*[]){&o});
        }
        if (hasBase) {
            corto_tls_set(CORTO_KEY_CONSTRUCTOR_TYPE, prev);
        }
    }
}

/* Destruct object */
static
void corto__destructor(
    corto_object o)
{
    corto_type t;
    corto__object* _o;

    corto_assertObject(o);

    t = corto_typeof(o);
    if (corto_check_state(o, CORTO_VALID)) {
        _o = CORTO_OFFSET(o, -sizeof(corto__object));

        if (t->flags & CORTO_TYPE_HAS_DESTRUCT) {
            corto_callDestructDelegate(&((corto_class)t)->destruct, t, o);
        }

        _o->align.attrs.state &= ~CORTO_VALID;
    } else {
        corto_critical("%s/destruct: object '%s' is not defined",
            corto_fullpath(NULL, t), corto_fullpath(NULL, o));
    }
}

corto_attr corto_set_attr(corto_attr attrs) {
    corto_attr* attr = corto_tls_get(CORTO_KEY_ATTR);
    corto_attr oldAttr = CORTO_ATTR_DEFAULT;
    if (!attr) {
        attr = corto_alloc(sizeof(corto_attr));
        corto_tls_set(CORTO_KEY_ATTR, attr);
    } else {
        oldAttr = *attr;
    }
    *attr = attrs;
    return oldAttr;
}

corto_attr corto_get_attr(void) {
    corto_attr* attr = corto_tls_get(CORTO_KEY_ATTR);
    if (attr) {
        return *attr;
    } else {
        return CORTO_ATTR_DEFAULT;
    }
}

bool corto_childof(corto_object p, corto_object o) {
    bool result = FALSE;
    if (p != o) {
        if (corto_check_attr(o, CORTO_ATTR_NAMED)) {
            corto_object parent = corto_parentof(o);
            while (parent && (parent != p)) {
                parent = corto_parentof(parent);
            }
            result = parent != NULL;
        }
    }
    return result;
}

static
corto_type corto_containerType(
    corto_container c)
{
    if (c->type) return c->type; else return corto_type(c);
}

/* Recursively declare containers in its definition */
static
int16_t corto_declareContainer(
    corto_object parent)
{
    corto_type type = corto_typeof(parent);

    if (corto_instanceof(corto_container_o, type))
    {
        corto_objectseq seq = corto_scopeClaim(type);
        int32_t i;
        for (i = 0; i < seq.length; i++) {
            corto_object c = seq.buffer[i];
            if ((corto_typeof(c) == corto_type(corto_container_o)) ||
                (corto_typeof(c) == corto_type(corto_leaf_o)))
            {
                if (!corto_declare(parent, corto_idof(c), corto_containerType(c))) {
                    goto error;
                }
            } else if (corto_typeof(c) == corto_type(corto_table_o)) {
                corto_tableinstance ts = corto_declare(parent, corto_idof(c), corto_tableinstance_o);
                if (!ts) {
                    goto error;
                }
                corto_ptr_setref(&ts->type, corto_containerType(c));
            }
        }
        corto_scopeRelease(seq);
    }

    return 0;
error:
    return -1;
}

/* Recursively define containers in its definition */
static
int16_t corto_defineContainer(
    corto_object parent,
    bool resume)
{
    corto_type type = corto_typeof(parent);

    if (corto_instanceof(corto_container_o, type)) {
        corto_objectseq seq = corto_scopeClaim(type);
        int32_t i;
        for (i = 0; i < seq.length; i++) {
            corto_object c = seq.buffer[i];
            if ((corto_typeof(c) == corto_type(corto_container_o)) ||
                (corto_typeof(c) == corto_type(corto_leaf_o)) ||
                (corto_typeof(c) == corto_type(corto_table_o)))
            {
                corto_object o = corto_lookup(parent, corto_idof(c));
                if (!o) {
                    corto_throw("could not find '%s' in container '%s'",
                        corto_idof(c),
                        corto_fullpath(NULL, parent));
                    goto error;
                }
                if (corto_define_intern(o, resume)) {
                    corto_release(o);
                    goto error;
                }
                corto_release(o);
            }
        }
        corto_scopeRelease(seq);
    } else if (type == corto_type(corto_tableinstance_o)) {
        corto_objectseq seq = corto_scopeClaim(parent);
        int32_t i;
        for (i = 0; i < seq.length; i++) {
            corto_object c = seq.buffer[i];
            if (corto_typeof(corto_typeof(c)) == corto_type(corto_table_o)) {
                if (corto_define_intern(c, resume)) {
                    corto_release(c);
                    goto error;
                }
                corto_release(c);
            }
        }
        corto_scopeRelease(seq);
    } else if (corto_parentof(parent) == corto_type(corto_tableinstance_o)) {
        corto_objectseq seq = corto_scopeClaim(parent);
        int32_t i, error = 0;
        for (i = 0; i < seq.length; i++) {
            corto_object c = seq.buffer[i];
            if (corto_define_intern(c, resume)) {
                error = 1;
            }
        }
        corto_scopeRelease(seq);
        if (error) goto error;
    }

    return 0;
error:
    return -1;
}

/* Create new object with attributes */
static
corto_object corto_declare_intern(
    corto_type type,
    bool orphan)
{
    uint32_t size, headerSize;
    corto__object* o = NULL;
    void *mem = NULL;
    corto_attr attrs = corto_get_attr();
    bool initializeScoped = !(attrs & CORTO_ATTR_NAMED);

    corto_assertObject(type);

    if (!type) {
        corto_throw("type not specified");
        goto error;
    }

    if (!corto_instanceof(corto_type_o, type)) {
        corto_throw("object '%s' is not a type",
          corto_fullpath(NULL, type));
        goto error;
    }

    /* Type must be valid and defined */
    if (!corto_check_state(type, CORTO_VALID)) {
        corto_throw("type '%s' is not valid/defined", corto_fullpath(NULL, type));
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
            if (attrs & CORTO_ATTR_NAMED) {
                attrs |= CORTO_ATTR_PERSISTENT;
            }
        }
    }

    if ((corto_typeof(type) == corto_type(corto_target_o)) && (!orphan || (!(attrs & CORTO_ATTR_NAMED)))) {
        attrs |= CORTO_ATTR_PERSISTENT;
    }

    /* Add any additional attributes the type may have specified */
    attrs |= type->attr;

    headerSize = sizeof(corto__object);

    size = type->size;

    /* Calculate size of attributes */
    if (attrs & CORTO_ATTR_OBSERVABLE) {
        headerSize += sizeof(corto__observable);
    }
    if (attrs & CORTO_ATTR_NAMED) {
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
        if (attrs & CORTO_ATTR_NAMED) {
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

        o->align.attrs.orphan = orphan != 0;

        corto_claim(type);

        if (initializeScoped) {
            /* Object is scoped because type->attr says so, which means it is an
             * anonymous object with a scope */
            if (attrs & CORTO_ATTR_NAMED) {
                /* Initialze scope-part of object */
                if (!corto_init_scope(NULL, NULL, type, CORTO_OFFSET(o, sizeof(corto__object)), TRUE, FALSE)) {
                    goto error_init;
                }
            }
        }

        /* Call framework initializer */
        if (!(attrs & CORTO_ATTR_NAMED)) {
            if (corto_init(CORTO_OFFSET(o, sizeof(corto__object)))) {
                goto error_init;
            }

            /* void objects are instantly defined because they have no value. */
            if (type->kind == CORTO_VOID) {
                corto_define(CORTO_OFFSET(o, sizeof(corto__object)));
            }
        }

        if (initializeScoped && type->flags & CORTO_TYPE_IS_CONTAINER) {
            if (corto_declareContainer(CORTO_OFFSET(o, sizeof(corto__object)))) {
                goto error;
            }
        }
    }

    return CORTO_OFFSET(o, sizeof(corto__object));
error_init: {
    corto_throw("%s/init failed", corto_fullpath(NULL, type));
    corto_release(type);
}
error:
    if (mem) corto_dealloc(mem);
    return NULL;
}

static
char* corto_randomId(
    uint16_t n)
{
/* $begin(corto/web/server/random) */
    static char *alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    static char *alphanum = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890";
    uint16_t i;
    char *result = corto_alloc(n + 1);

    result[0] = alpha[rand() % strlen(alpha)];
    for (i = 1; i < n; i++) {
        result[i] = alphanum[rand() % strlen(alphanum)];
    }

    result[i] = '\0';

    return result;
/* $end */
}

/* Declare object */
static
corto_object corto_declareChild_intern(
    corto_object parent,
    const char *id,
    corto_type type,
    bool orphan,
    bool forceType,
    bool defineVoid,
    bool *newobject)
{
    corto_object o = NULL;
    bool retry = FALSE;
    char *mountId = NULL;

    corto_assertObject(parent);
    corto_assertObject(type);

    corto_assert(parent != NULL, "no parent provided to corto_declareChild");

    if (!corto_check_attr(parent, CORTO_ATTR_NAMED) && !orphan) {
        corto_throw("object provided to 'parent' parameter is not scoped");
        goto error;
    }

    /* If no id is provided, lookup id in mount */
    if (!id) {
        corto_id parentId, typeId;
        corto_fullpath(parentId, parent);
        corto_fullpath(typeId, type);
        mountId = corto_select("*").from(parentId).type(typeId).id();
        if (!mountId) {
            id = corto_randomId(16);
        } else {
            id = mountId;
        }
    }

    if (!id[0]) {
        corto_throw("invalid id (cannot be an empty string)");
        goto error;
    }

    /* Save cycles by not building a path when security is not enabled */
    if (corto_secured()) {
        corto_id fullId;
        corto_fullpath(fullId, parent);
        strcat(fullId, "/");
        strcat(fullId, id);
        if (!corto_authorize_id(fullId, CORTO_SECURE_ACTION_CREATE)) {
            goto access_error;
        }
    }

    /* Create new object */
    do {
        corto_attr oldAttr = corto_set_attr(corto_get_attr()|CORTO_ATTR_NAMED);
        o = corto_declare_intern(type, orphan);
        corto_set_attr(oldAttr);

        if (o) {
            corto_object o_ret = NULL;
            corto__object *_o = CORTO_OFFSET(o, -sizeof(corto__object));

            /* Initialize object parameters. */
            if ((o_ret = corto_init_scope(parent, id, type, o, orphan, forceType))) {
                if (o_ret != o) {
                    corto_release(type);
                    corto_dealloc(corto__objectStartAddr(CORTO_OFFSET(o,-sizeof(corto__object))));
                    o = o_ret;

                    if (newobject) {
                        *newobject = false;
                    }

                    /* Redeclaring an object results in a claim so that the object
                     * can't be deallocated until it is explicitly deleted by the
                     * code that redeclared it. */
                    corto_claim(o);

                    /* If the object just has been declared and not by this thread,
                     * block until the object becomes either defined or deleted */
                    if (!corto_check_state(o, CORTO_VALID) && !corto_check_state(o, CORTO_DELETED)) {
                        if (!corto_declaredByMeCheck(o)) {
                            corto_debug(
                              "corto: declareChild: %s declared in other thread, waiting",
                              id);

                            corto_read_begin(o);
                            bool deleted = corto_check_state(o, CORTO_DELETED);
                            if (!deleted) {
                                corto_assert(
                                    corto_check_state(o, CORTO_VALID),
                                        "thread unblocked but object is still not valid"
                                );
                            }
                            corto_read_end(o);

                            corto_debug(
                              "corto: declareChild: %s defined in other thread (deleted = %d)",
                              id, deleted);

                            /* If the object has been deleted after unlocking,
                             * this means that corto_delete was called instead
                             * of corto_define. Since a postcondition of
                             * corto_declareChild is that it should return a
                             * VALID object (at least), it cannot return the
                             * DESTRUCTED object. Therefore, the function will
                             * retry declaring a new object. */
                            if (deleted) {
                                corto_release(o);
                                retry = TRUE;
                            }
                        } else {
                            /* This thread forward declared the object. */
                        }
                    }
                    goto ok;
                } else {
                    if (newobject) {
                        *newobject = true;
                    }
                }
            } else {
                corto_deinit_scope(o);
                if (corto_countof(o) != 1) {
                    corto_throw(
                      "object '%s/%s' is referenced after initializer failed",
                      corto_fullpath(NULL, parent),
                      id);
                } else {
                    corto_dealloc(corto__objectStartAddr(CORTO_OFFSET(o,-sizeof(corto__object))));
                    corto_throw("init for '%s' of '%s' failed",
                        id,
                        corto_fullpath(NULL, type));
                }
                corto_release(type);
                o = NULL;
                goto error;
            }

            /* Notify of new object */
            if (!orphan) {
                corto_notify(o, CORTO_DECLARE);
            } else {
                /* Orphaned objects don't generate DECLARE and DEFINE events. */
                _o->align.attrs.state = 0;
            }

            /* void objects are instantly valid because they have no value */
            if (type != corto_unknown_o && (type->kind == CORTO_VOID && !type->reference)) {
                if (defineVoid) {
                    /* Never resume void objects - there's nothing to resume */
                    int rc = corto_define_intern(o, FALSE);
                    corto_assert(rc == 0, "void objects should not fail to define");
                }
            }
        }
    } while (retry);

    if (o && (type->flags & CORTO_TYPE_IS_CONTAINER)) {
        if (corto_declareContainer(o)) {
            goto error;
        }
    }

ok:
    if (mountId) corto_dealloc(mountId);
    return o;
error:
    if (o) corto_delete(o);
access_error:
    if (mountId) corto_dealloc(mountId);
    return NULL;
}

static
corto_object corto_create_intern(
    corto_object result,
    bool resume)
{
    if (result && !corto_check_state(result, CORTO_VALID))
    {
        if (corto_define_intern(result, resume)) {
            corto_delete(result);
            result = NULL;
        }
    }
    return result;
}

static
corto_object corto_resume_fromMount(
    corto_mount m,
    char *parentId,
    char* expr,
    corto_object o)
{
    corto_object result = NULL;
    corto_type mountType = corto_observer(m)->type;

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
            corto_ptr_setref(&_p->owner, m);

            /* If object was resumed without creating an object in the store first, it
             * means that a lookup or resolve triggered the resume. In that case, set
             * the 'resume' attribute to true, to indicate that the object should not be
             * released by a drop operation, but explicitly by an application. */
            if (!o) {
                _p->resumed = TRUE;
            }
        }
    }

    return result;
}

typedef struct corto_resumeWalk_t {
    corto_object o;
    corto_object p;
    corto_object parent;
    corto_mount result;
    corto_mount lastMount;
    corto_id parentId;
    bool parentIdSet;
    char *exprPtr;
} corto_resumeWalk_t;

static
int corto_resumeWalk(
    corto_object entity,
    corto_object instance,
    void *userData)
{
    corto_mount mount = entity;
    corto_resumeWalk_t *data = userData;

    CORTO_UNUSED(instance);

    /* Either the mount registered for the direct parent of the
     * provided object, or the mount must have ON_TREE set */
    if ((data->p == data->parent) ||
      (((corto_observer)mount)->mask & CORTO_ON_TREE))
    {
        corto_type mountType = corto_observer(mount)->type;

        if (!mountType || (data->parent == data->p) || (corto_typeof(data->parent) == mountType)) {
            if (!data->parentIdSet) {
                /* Parent must be relative to mount point of mount */
                corto_path(
                    data->parentId,
                    data->p,
                    data->parent,
                    "/");
                data->parentIdSet = TRUE;
            }

            data->result = corto_resume_fromMount(mount, data->parentId, data->exprPtr, data->o);
            if (data->result) {
                data->lastMount = mount;
                return 0;
            }
        }
    }

    return 1;
}

/* Precondition: 'expr' contains the expression starting from the object that
 * could not be found in the object store. */
corto_object corto_resume(
    corto_object parent,
    const char *expr,
    corto_object o)
{
    if (o == root_o) {
        return o;
    }

    if (!parent) {
        parent = root_o;
    }

    if (!expr) {
        return NULL;
    }

    corto_debug("try resume '%s' from '%s' (%s)",
        expr,
        corto_fullpath(NULL, parent),
        corto_fullpath(NULL, corto_typeof(parent)));

    corto_id exprBuff;

    corto_resumeWalk_t walkData = {
        .o = NULL,
        .p = parent,
        .parent = parent,
        .result = NULL,
        .lastMount = NULL,
        .parentId = {0},
        .parentIdSet = FALSE,
        .exprPtr = exprBuff
    };

    /* If expression contains / cut expression up without modifying original
     * parameter value */
    strcpy(exprBuff, expr);

    char *nextSep = NULL;
    do {
        corto_object prev = walkData.result;

        nextSep = strchr(walkData.exprPtr, '/');
        if (nextSep) {
            *nextSep = '\0';
        } else {
            /* If object is last one to be resumed in expression, pass it to
             * mount resume function. */
            walkData.o = o;
        }

        walkData.result = NULL;

        /* If expression consists of multiple elements, and one element has been
         * found in a mount, it is likely that the next elements are going to be
         * found in the same mount, so start searching there. */
        if (walkData.lastMount && corto_observer(walkData.lastMount)->mask & CORTO_ON_TREE) {
            corto_path(
                walkData.parentId,
                walkData.p,
                walkData.parent,
                "/");

            walkData.result = corto_resume_fromMount(
                walkData.lastMount,
                walkData.parentId,
                walkData.exprPtr,
                walkData.o);
        }

        while (!walkData.result && walkData.p) {
            corto_id pId;
            corto_fullpath(pId, walkData.p);
            corto_entityAdmin_walk(&corto_mount_admin, corto_resumeWalk, pId, false, &walkData);
            if (!walkData.result) {
                walkData.p = corto_parentof(walkData.p);
            }
        }

        if (prev) {
            corto_release(prev);
        }

        walkData.parent = walkData.result;
        walkData.exprPtr = nextSep + 1;
    } while (walkData.parent && nextSep);

    return walkData.result;
}

/* Resume a declared object */
static
bool corto_resumeDeclared(
    corto_object o,
    bool resume)
{
    corto__object *_o = CORTO_OFFSET(o, -sizeof(corto__object));
    corto__persistent *_p = NULL;
    bool resumed = FALSE;

    if ((_p = corto__objectPersistent(_o))) {
        _p->owner = corto_get_source();

        if (_p->owner) {
            corto_claim(_p->owner);
        }

        /* If object is persistent and locally owned, check if a
         * persistent copy is already available */
        if (!_p->owner && corto_check_attr(o, CORTO_ATTR_NAMED)) {
            if (resume) {
                if (corto_resume(corto_parentof(o), corto_idof(o), o)) {
                    resumed = TRUE;
                }
            }

        /* If owner of an object is a SINK, object is resumed */
        } else if (_p->owner
          && corto_instanceof(corto_mount_o, _p->owner)
          && (corto_mount(_p->owner)->policy.ownership == CORTO_LOCAL_OWNER))
        {
            resumed = TRUE;
        }
    }

    return resumed;
}

/* Construct a declared object */
static
int16_t corto_defineDeclared(
    corto_object o)
{
    int16_t result = 0;
    corto_type t = corto_typeof(o);

    if (t == corto_unknown_o) {
        corto_throw("cannot define object '%s' of unknown type",
            corto_fullpath(NULL, o));
        goto error;
    }

    /* Don't invoke constructor if object is not locally owned */
    if (t->flags & CORTO_TYPE_HAS_CONSTRUCT) {
        if (corto_ownerMatch(corto_sourceof(o), NULL)) {
            /* Call constructor with default attributes */
            corto_attr prev = corto_set_attr(CORTO_ATTR_DEFAULT);
            result = corto_callInitDelegate(&((corto_class)t)->construct, t, o, true);
            corto_set_attr(prev);
        }
    }

    return result;
error:
    return -1;
}

/* Send DEFINE or RESUME notification for new object */
static
int16_t corto_notifyDefined(
    corto_object o,
    bool resume,
    corto_eventMask mask)
{
    corto__object *_o = CORTO_OFFSET(o, -sizeof(corto__object));
    corto_type t = _o->type;
    bool named = _o->align.attrs.scope;
    bool observable = _o->align.attrs.observable;
    bool hasDefine = t->flags & CORTO_TYPE_HAS_DEFINE;
    bool shouldLock = !named && (hasDefine || observable);

    _o->align.attrs.state |= CORTO_VALID;

    /* Do postponed listen calls for instance */
    if (observable) {
        corto_observerDelayedAdminDefine(o);
    }

    if (shouldLock) {
        corto_lock(o);
    }

    /* Notify observers of defined object, don't generate DEFINED event for
     * orphaned objects. */
    if (!_o->align.attrs.orphan && (observable || named)) {
        corto_notify(o, mask);
    }

    if (hasDefine) {
        corto_callDestructDelegate(&((corto_class)t)->define, t, o);
    }

    /* Define contained objects */
    if (t->flags & CORTO_TYPE_IS_CONTAINER) {
        if (corto_defineContainer(o, resume)) {
            goto error;
        }
    }

    /* Remove object from declared admin and unlock object */
    if (named) {
        corto_declaredByMeRemove(o);
    } else if (shouldLock) {
        corto_unlock(o);
    }

    return 0;
error:
    return -1;
}

static
corto_object corto_declareChildRecursive_intern(
    corto_object parent,
    const char *id,
    corto_type type,
    bool orphan,
    bool forceType,
    bool define,
    bool defineSelf,
    bool resume)
{
    char *next;
    corto_object result = NULL;

    if (id && id[0] == '/') {
        parent = root_o;
        id ++;
    }

    if (id && (next = (char*)strelem(id)) && (*next != '(')) {
        corto_id buf;
        char *cur = buf;
        strcpy(buf, id);
        corto_object firstNonExist = NULL;
        bool newobject;

        next = &cur[next - id];
        *next = '\0';
        next ++;

        do {
            newobject = false;
            result = corto_declareChild_intern(
                parent,
                cur,
                next ? corto_unknown_o : type,
                orphan,
                next ? FALSE : forceType,
                FALSE /* prevent sending VALID event for void objects */,
                &newobject);

            /* Keep track of first non-existing object. If something
             * goes wrong objects starting from here must be deleted. */
            if (!firstNonExist && newobject) {
                firstNonExist = result;
            }
            if (!newobject && result) {
                corto_release(result);
            }

            parent = result;

            cur = next;
            if (cur && (next = (char*)strelem(cur))) {
                *next = '\0';
                next ++;
            }
        } while (result && cur);

        if (result) {
            if (!newobject) {
                corto_claim(result);
            }

            if (defineSelf) {
                /* Call constructor */
                if (!corto_check_state(result, CORTO_VALID)) {
                    if (corto_define_intern(result, resume)) {
                        result = NULL; /* Signal failure */
                    }
                }
            }
        }

        /* If one of the operations failed, delete all objects */
        if (!result) {
            /* Recursively delete objects */
            if (firstNonExist) {
                corto_delete(firstNonExist);
            }
        }
    } else {
        result = corto_declareChild_intern(parent, id, type, orphan, forceType, TRUE, NULL);
        if (defineSelf) {
            result = corto_create_intern(result, resume);
        }
    }

    return result;
}

corto_object _corto_declare(
    corto_object parent,
    const char *id,
    corto_type type)
{
    if (parent) {
        return corto_declareChildRecursive_intern(parent, id, type, FALSE, TRUE, FALSE, FALSE, TRUE);
    } else {
        return corto_declare_intern(type, FALSE);
    }
}

corto_object _corto_create(
    corto_object parent,
    const char  *id,
    corto_type type)
{
    if (parent) {
        return corto_declareChildRecursive_intern(parent, id, type, FALSE, TRUE, TRUE, TRUE, TRUE);
    } else {
        return corto_create_intern(type, TRUE);
    }
}

/* Define object */
static
int16_t corto_define_intern(
    corto_object o,
    bool resume)
{
    int16_t result = 0;

    corto_assertObject(o);

    if (!o) {
        corto_throw("corto: NULL passed to corto_define");
        goto error;
    }

    /* Only define undefined objects */
    if (!corto_check_state(o, CORTO_VALID)) {
        if (corto_childof(root_o, o) && !corto_isbuiltin(o)) {
            if (!corto_declaredByMeCheck(o) && !corto_isorphan(o)) {
                corto_throw("corto: cannot define object '%s' because it was not declared in same thread",
                  corto_fullpath(NULL, o));
                goto error;
            }
        }

        bool resumed = corto_resumeDeclared(o, resume);
        result = corto_defineDeclared(o);
        if (!result) {
            result = corto_notifyDefined(o, resume, resumed ? CORTO_RESUME : CORTO_DEFINE);
        }
        if (CORTO_TRACE_OBJECT || CORTO_TRACE_ID) corto_memtrace("define", o, NULL);
    } else {
        corto_type t = corto_typeof(o);
        if (t->flags & CORTO_TYPE_IS_CONTAINER) {
            if (corto_defineContainer(o, resume)) {
                goto error;
            }
        }
    }

    return result;
error:
    return -1;
}

int16_t corto_define(
    corto_object o)
{
    return corto_define_intern(o, TRUE);
}

bool corto_destruct(
    corto_object o,
    bool delete)
{
    corto__object* _o;
    bool result = TRUE;
    corto_object owner = corto_sourceof(o);
    bool named = corto_check_attr(o, CORTO_ATTR_NAMED);
    bool isBuiltin = corto_isbuiltin(o);

    corto_assertObject(o);

    _o = CORTO_OFFSET(o, -sizeof(corto__object));
    if (!isBuiltin) corto_ainc(&_o->refcount);

    if (!corto_check_state(o, CORTO_DELETED)) {
        if (CORTO_TRACE_OBJECT || CORTO_TRACE_ID) corto_memtrace("destruct", o, NULL);
        if (CORTO_TRACE_OBJECT || CORTO_TRACE_ID) corto_memtracePush();

        bool defined = corto_check_state(o, CORTO_VALID);

        /* Call destructor before marking object state as deleted */
        if (defined && corto_owned(o)) {
            corto__destructor(o);
        }

        /* From here, object is marked as deleted. */
        _o->align.attrs.state |= CORTO_DELETED;

        if (!isBuiltin && named) {
            corto_drop(o, delete);
        }

        /* Only do the following steps if the object is defined */
        if (!isBuiltin) {
            if (defined) {
                corto_type t = corto_typeof(o);

                /* Only send delete notification when object is being deleted, not
                 * when object is being suspended. */
                if (!corto_isorphan(o)) {
                    if (delete) {
                        corto_notify(o, CORTO_DELETE);
                        if (t->flags & CORTO_TYPE_HAS_DELETE) {
                            corto_callDestructDelegate(&((corto_class)t)->_delete, t, o);
                        }
                    } else {
                        corto_notify(o, CORTO_SUSPEND);
                        if (t->flags & CORTO_TYPE_HAS_DELETE) {
                            corto_callDestructDelegate(&((corto_class)t)->_delete, t, o);
                        }
                    }
                }

                if (owner && corto_check_attr(o, CORTO_ATTR_PERSISTENT)) {
                    corto_release(owner);
                }
            } else {
                /* If object wasn't defined, remove it from the declared admin */
                if (named && !corto_declaredByMeRemove(o)) {
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
        }

        /* Deinit observable */
        if (corto_check_attr(o, CORTO_ATTR_OBSERVABLE)) {
            corto__deinitObservable(o);
        }

        /* Deinit scope */
        if (named && !corto_isorphan(o)) {
            corto_orphan(o);
        }

        /* Indicate that object has been deleted */
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

    if (!isBuiltin && !corto_adec(&_o->refcount)) {

        /* Deinit writable */
        if (corto_check_attr(o, CORTO_ATTR_WRITABLE)) {
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
        if (named) {
            /* Deinit scope not before refcount goes to zero. The data in the scope
             * administration is required to determine whether this object is
             * a builtin object. */
            corto_deinit_scope(o);

            _o = CORTO_OFFSET(o, -sizeof(corto__object));
             corto__scope *scope = corto__objectScope(_o);
            if (scope->scope) {
                corto_rb_free(scope->scope);
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

    return result;
}

typedef struct corto_dropWalk_t {
    corto_ll objects;
}corto_dropWalk_t;

/* Collect objects in scope, so they can be removed outside of scopeLock. */
static
int corto_dropWalk(
    void* o,
    void* userData)
{
    corto_dropWalk_t* data;

    data = userData;

    /* Prevent object from being deleted when scopeLock is released, which
     * would result in invalid reference in list. */
    corto_claim(o);

    /* Insert object in list */
    if (!data->objects) {
        data->objects = corto_ll_new();
    }
    corto_ll_insert(data->objects, o);

    return 1;
}

void corto_drop(
    corto_object o,
    bool delete)
{
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

        corto_rwmutex_read(&scope->align.scopeLock);
        walkData.objects = NULL;
        if (scope->scope) {
            corto_rb_walk(scope->scope, corto_dropWalk, &walkData);
        }
        corto_rwmutex_unlock(&scope->align.scopeLock);

        /* Free objects outside scopeLock */
        if (walkData.objects) {
            if (CORTO_TRACE_OBJECT || CORTO_TRACE_ID) {
                corto_memtrace(delete ? "drop:delete" : "drop:suspend", o, NULL);
            }

            iter = corto_ll_iter(walkData.objects);
            while(corto_iter_hasNext(&iter)) {
                collected = corto_iter_next(&iter);

                /* Check if object is resumed before releasing it */
                corto__object *_o = CORTO_OFFSET(collected, -sizeof(corto__object));
                corto__persistent *_p = corto__objectPersistent(_o);
                bool resumed = _p && _p->resumed;

                if (CORTO_TRACE_OBJECT || CORTO_TRACE_ID) corto_memtracePush();

                if (delete) {
                    if (corto_destruct(
                        collected,
                        corto_owned(collected) && delete))
                    {
                        /* Release the object if it was not a pure resumed object */
                        if (!resumed) {
                            corto_release(collected);
                        }
                    }
                } else {
                    corto_drop(collected, delete);
                    if (!resumed) {
                        corto_release(collected);
                    }
                }

                if (CORTO_TRACE_OBJECT || CORTO_TRACE_ID) corto_memtracePop();

                /* Release the claim introduced by corto_drop */
                corto_release(collected);
            }
            corto_ll_free(walkData.objects);
        }
    } else {
        corto_critical("drop: object <%p> is not scoped.", o);
    }
}

/* Delete object */
int16_t corto_suspend(
    corto_object o)
{
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
int16_t corto_delete(
    corto_object o)
{
    corto_assertObject(o);
    if (!o) {
        corto_critical("NULL passed to corto_delete");
    }

    if (!corto_authorize(o, CORTO_SECURE_ACTION_DELETE)) {
        goto error;
    }

    if (!corto_owned(o)) {
        corto_throw("object not owned by thread");
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
int16_t corto_invalidate(
    corto_object o)
{
    corto_assertObject(o);
    corto__object* _o;
    _o = CORTO_OFFSET(o, -sizeof(corto__object));
    _o->align.attrs.state &= ~CORTO_VALID;
    /* Notify observers */
    return corto_notify(o, CORTO_INVALIDATE);
}

/* Get type */
corto_type corto_typeof(
    corto_object o)
{
    corto_assertObject(o);
    corto__object* _o = CORTO_OFFSET(o, -sizeof(corto__object));
    return _o->type;
}

/* Get refcount */
int32_t corto_countof(
    corto_object o)
{
    corto_assertObject(o);
    corto__object* _o;
    _o = CORTO_OFFSET(o, -sizeof(corto__object));
    return _o->refcount;
}

/* Get state */
corto_state corto_stateof(
    corto_object o)
{
    corto_assertObject(o);
    corto__object* _o;
    _o = CORTO_OFFSET(o, -sizeof(corto__object));
    int8_t state = _o->align.attrs.state;
    if (!_o->align.attrs.orphan) {
        state |= CORTO_DECLARED;
    }
    return state;
}

corto_attr corto_attrof(
    corto_object o)
{
    corto_assertObject(o);
    corto__object* _o;
    _o = CORTO_OFFSET(o, -sizeof(corto__object));

    int8_t attr =
      _o->align.attrs.scope |
      (_o->align.attrs.write << 1) |
      (_o->align.attrs.observable << 2) |
      (_o->align.attrs.persistent << 3);

    return attr;
}

/* Get contentstring */
char* corto_serialize_value(
    corto_object o,
    const char *contentType)
{
    corto_fmt type;

    corto_assertObject(o);

    if (!(type = corto_fmt_lookup(contentType))) {
        goto error;
    }

    corto_value v = corto_value_object(o, NULL);

    return (char*)type->fromValue(&v);;
error:
    return NULL;
}

int16_t corto_deserialize_value(
    corto_object o,
    const char *contentType,
    const char *data)
{
    corto_fmt type;

    corto_assertObject(o);

    if (!(type = corto_fmt_lookup(contentType))) {
        goto error;
    }

    corto_value v = corto_value_object(o, NULL);
    return type->toValue(&v, (corto_word)data);;
error:
    return -1;
}

char* corto_serialize(
    corto_object o,
    const char *contentType)
{
    corto_fmt type;

    corto_assertObject(o);

    if (!(type = corto_fmt_lookup(contentType))) {
        goto error;
    }

    return (corto_string)type->fromObject(o);;
error:
    return NULL;
}

int16_t corto_deserialize(
    corto_object *o,
    const char *contentType,
    const char *data)
{
    corto_fmt type;

    corto_assertObject(o);

    if (!(type = corto_fmt_lookup(contentType))) {
        goto error;
    }

    return type->toObject(o, (uintptr_t)data);;
error:
    return -1;
}

bool corto_check_state(
    corto_object o,
    corto_state state)
{
    corto__object* _o;
    corto_assertObject(o);
    _o = CORTO_OFFSET(o, -sizeof(corto__object));
    corto_state ostate = _o->align.attrs.state;
    if (!_o->align.attrs.orphan) {
        ostate |= CORTO_DECLARED;
    }
    return (ostate & state) == state;
}

bool corto_check_attr(
    corto_object o,
    corto_attr attr)
{
    bool result;
    corto__object* _o;

    corto_assertObject(o);

    _o = CORTO_OFFSET(o, -sizeof(corto__object));
    result = TRUE;

    if (attr & CORTO_ATTR_NAMED) {
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

bool corto_isorphan(
    corto_object o)
{
    corto__object* _o;
    corto_assertObject(o);
    _o = CORTO_OFFSET(o, -sizeof(corto__object));
    return _o->align.attrs.orphan;
}

bool corto_isbuiltin(
    corto_object o)
{
    corto__object* _o;
    corto_assertObject(o);
    _o = CORTO_OFFSET(o, -sizeof(corto__object));
    return _o->align.attrs.builtin;
}

corto_object _corto_assertType(
    corto_type type,
    corto_object o)
{
    corto_assertObject(type);
    corto_assertObject(o);

    if (o && (corto_typeof(o) != type)) {
        if (!_corto_instanceof(type, o)) {
            corto_error("object '%s' is not an instance of '%s'\n   type = %s",
                corto_fullpath(NULL, o),
                corto_fullpath(NULL, type),
                corto_fullpath(NULL, corto_typeof(o)));
            corto_backtrace(stdout);
            abort();
        }
    }
    return o;
}

bool _corto_type_instanceof(
    corto_type dst,
    corto_type src)
{
    bool result = TRUE;

    corto_assertObject(dst);
    corto_assertObject(src);

    if (dst != src) {
        result = FALSE;

        if (src->kind == dst->kind) {
            switch(dst->kind) {
            case CORTO_PRIMITIVE: {
                corto_primitive pSrc = corto_primitive(src);
                corto_primitive pDst = corto_primitive(dst);

                switch(pDst->kind) {
                case CORTO_BITMASK:
                case CORTO_UINTEGER:
                case CORTO_BINARY:
                case CORTO_CHARACTER:
                    switch(pSrc->kind) {
                    case CORTO_BITMASK:
                    case CORTO_UINTEGER:
                    case CORTO_BINARY:
                    case CORTO_CHARACTER:
                        result = pSrc->width == pDst->width;
                        break;
                    default:
                        break;
                    }
                    break;
                case CORTO_ENUM:
                case CORTO_INTEGER:
                    switch(pSrc->kind) {
                    case CORTO_ENUM:
                    case CORTO_INTEGER:
                        result = pSrc->width == pDst->width;
                        break;
                    default:
                        break;
                    }
                    break;
                default:
                    result = pSrc->kind == pDst->kind && pSrc->width == pDst->width;
                    break;
                }
                break;
            }
            case CORTO_COMPOSITE: {
                if (((corto_interface)dst)->kind == CORTO_DELEGATE) {
                    /*result = corto_delegate_instanceof(corto_delegate(dst), o);*/
                } else if (((corto_interface)dst)->kind == CORTO_INTERFACE) {
                    if (((corto_interface)src)->kind == CORTO_CLASS) {
                        corto_interface base = (corto_interface)src;
                        while (!result && base) {
                            int32_t i;
                            for (i = 0; i < ((corto_class)base)->implements.length; i++) {
                                if (_corto_interface_baseof(
                                    (corto_interface)((corto_class)base)->implements.buffer[i], (corto_interface)dst)) {
                                    result = TRUE;
                                    break;
                                }
                            }
                            base = base->base;
                        }
                    }
                } else {
                    result = _corto_interface_baseof((corto_interface)src, (corto_interface)dst);
                }
                break;
            }
            default:
                break;
            }
        } else {
            if ((dst->kind == CORTO_VOID) && (dst->reference)) {
                if (src->reference) {
                    result = TRUE;
                }
            }
        }
    }
    if (!result && (corto_typeof(src) == (corto_type)corto_target_o)) {
        result = dst == ((corto_target)src)->type;
    }

    return result;
}

bool _corto_instanceof(
    corto_type type,
    corto_object o)
{
    corto_assertObject(o);

    /* If types are equal, quickly jump out of function */
    corto_type t = corto_typeof(o);
    if (type == t) {
        return TRUE;
    }

    corto_assertObject(type);

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

    return _corto_type_instanceof(type, t);
}

/* Get & lock scope */
corto__scope *corto__scopeClaim(corto_object o) {
    corto_assertObject(o);

    corto__object  *_o = CORTO_OFFSET(o, -sizeof(corto__object));
    corto__scope *scope = corto__objectScope(_o);
    if (scope) {
        if (corto_rwmutex_read(&scope->align.scopeLock)) {
            corto_throw("aquiring scopelock failed");
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
        corto_rwmutex_unlock(&scope->align.scopeLock);
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
char* corto_nameof(corto_id buffer, corto_object o) {
    corto_assertObject(o);

    corto_type t = corto_typeof(o);
    char *str = NULL;
    bool threadStr = FALSE;
    corto_function delegate = NULL;

    if (t->kind == CORTO_COMPOSITE) {
        corto_interface i = corto_interface(t);
        do {
            delegate = corto_type(i)->nameof.super.procedure;
            i = i->base;
        } while(i && !delegate);
    } else {
        delegate = t->nameof.super.procedure;
    }

    if (delegate) {
        if (delegate->kind == CORTO_PROCEDURE_CDECL) {
            str = ((char*___ (*)(corto_object))(delegate->fptr))(o);
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
        char *tmp = buffer;
        buffer = corto_setThreadString(buffer);
        corto_dealloc(tmp);
    }

    return buffer;
}

/* Get id (requires scoped object) */
char* corto_idof(corto_object o) {
    corto_assertObject(o);

    corto__object* _o;
    corto__scope* scope;
    char *result;

    result = NULL;
    _o = CORTO_OFFSET(o, -sizeof(corto__object));
    scope = corto__objectScope(_o);
    if (scope) {
        result = scope->id;
    }

    return result;
}

/* Get scope tree */
corto_rb corto_scopeof(corto_object o) {
    corto_assertObject(o);

    corto__object* _o;
    corto__scope* scope;
    corto_rb result;

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

uint32_t corto_scopeSize(corto_object o) {
    corto_assertObject(o);

    corto__object* _o;
    corto__scope* scope;
    corto_rb tree;
    uint32_t result = 0;

    _o = CORTO_OFFSET(o, -sizeof(corto__object));
    scope = corto__objectScope(_o);
    if (scope) {
        tree = scope->scope;
        if (tree) {
            result = corto_rb_count(tree);
        }
    } else {
        goto err_not_scoped;
    }

    return result;
err_not_scoped:
    corto_error("corto_scopeSize: object <%p> is not scoped", o);
    return 0;
}

/* Secure object walk */
typedef struct corto_scopeWalkSecured_t {
    corto_scopeWalk_cb action;
    void *userData;
} corto_scopeWalkSecured_t;
int corto_scopeWalkSecured(corto_object o, void *userData) {
    corto_scopeWalkSecured_t *data = userData;
    int result = 1;
    if (corto_authorize(o, CORTO_SECURE_ACTION_READ)) {
        result = data->action(o, data->userData);
    }
    return result;
}

/* Walk objects in scope */
int16_t corto_scopeWalk(corto_object o, corto_scopeWalk_cb action, void* userData) {
    corto_assertObject(o);

    int16_t result;
    corto__scope* scope;

    if (!o) {
        o = root_o;
    }

    result = 1;
    scope = corto__objectScope(CORTO_OFFSET(o, -sizeof(corto__object)));
    if (scope) {
        if (scope->scope) {
            corto_rwmutex_read(&scope->align.scopeLock);
            if (!corto_secured()) {
                result = corto_rb_walk(scope->scope, (corto_elementWalk_cb)action, userData);
            } else {
                corto_scopeWalkSecured_t walkData = {action, userData};
                result = corto_rb_walk(
                    scope->scope,
                    (corto_elementWalk_cb)corto_scopeWalkSecured,
                    &walkData);
            }
            corto_rwmutex_unlock(&scope->align.scopeLock);
        }
    }

    return result;
}

/* Obtain scoped identifier (serves as global unique identifier) */
char* corto_fullpath_intern(corto_id buffer, corto_object o, bool useName) {
    corto_assertObject(o);

    corto_object stack[CORTO_MAX_SCOPE_DEPTH];
    uint32_t depth;
    char* ptr;
    uint32_t len;
    bool threadStr = FALSE;

    depth = 0;

    if (!buffer) {
        buffer = corto_alloc(sizeof(corto_id));
        threadStr = TRUE;
    }

    if (!o) {
        buffer[0] = '\0';
    } else if (!corto_check_attr(o, CORTO_ATTR_NAMED)) {
        corto_walk_opt stringSer;
        corto_string_ser_t data;

        /* Serialize object string */
        stringSer = corto_string_ser(CORTO_LOCAL|CORTO_READONLY|CORTO_PRIVATE, CORTO_NOT, CORTO_WALK_TRACE_ON_FAIL);

        *buffer = '\0';
        data.compactNotation = TRUE;
        data.buffer = CORTO_BUFFER_INIT;
        data.buffer.buf = buffer;
        data.buffer.max = sizeof(corto_id) - 1;
        data.prefixType = TRUE;
        data.enableColors = FALSE;
        if (corto_walk(&stringSer, o, &data)) {
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
        char *tmp = buffer;
        buffer = corto_setThreadString(buffer);
        corto_dealloc(tmp);
    }

    return buffer;
error:
    return NULL;
}

char* corto_fullpath(corto_id buffer, corto_object o) {
    corto_assertObject(o);
    return corto_fullpath_intern(buffer, o, FALSE);
}

static
corto_object* corto_scopeStack(
    corto_object o,
    corto_object scopeStack[],
    uint32_t *length)
{
    corto_assertObject(o);

    corto_object ptr = o;
    uint32_t i = 0;

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

char* corto_path_intern(
    corto_id buffer,
    corto_object from,
    corto_object o,
    const char *sep,
    bool useName)
{
    corto_assertObject(from);
    corto_assertObject(o);

    corto_object from_s[CORTO_MAX_SCOPE_DEPTH];
    corto_object o_s[CORTO_MAX_SCOPE_DEPTH];
    uint32_t from_i, o_i;
    char* ptr;
    uint32_t length;
    bool reverse = FALSE;
    uint32_t count = 0;
    bool threadStr = FALSE;

    corto_assert(o != NULL, "corto_path called with NULL for parameter 'to'.");

    if (o == NULL) {
        corto_throw("NULL passed to corto_path");
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
        char* tmp = buffer;
        buffer = corto_setThreadString(buffer);
        corto_dealloc(tmp);
    }

    return buffer;
error:
    return NULL;
}

char* corto_path(
    corto_id buffer,
    corto_object from,
    corto_object o,
    const char *sep)
{
    corto_assertObject(from);
    corto_assertObject(o);
    return corto_path_intern(buffer, from, o, sep, FALSE);
}


corto_object corto_sourceof(
    corto_object o)
{
    corto_assertObject(o);

    corto__object* _o;
    corto__persistent* persistent;
    corto_object result = NULL;

    if (corto_isorphan(o)) {
        o = corto_parentof(o);
        while (o && corto_isorphan(o)) {
            o = corto_parentof(o);
        }
    }

    if (o && corto_check_attr(o, CORTO_ATTR_PERSISTENT)) {
        _o = CORTO_OFFSET(o, -sizeof(corto__object));
        persistent = corto__objectPersistent(_o);
        result = persistent->owner;
    }

    return result;
}

static
bool corto_ownerMatch(
    corto_object owner,
    corto_object current)
{
    bool result;

    if (owner == current) {
        result = TRUE;
    } else if (owner && corto_instanceof(corto_mount_o, owner)) {
        if (!current) {
            if (corto_mount(owner)->policy.ownership != CORTO_LOCAL_OWNER) {
                result = FALSE;
            } else {
                result = TRUE;
            }
        } else {
            result = FALSE;
        }
    } else if (current && corto_instanceof(corto_mount_o, current)) {
        if (!owner) {
            if (corto_mount(current)->policy.ownership != CORTO_LOCAL_OWNER) {
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

bool corto_owned(corto_object o) {
    corto_assertObject(o);

    /* If object is not persistent, and it is not an orphan
     * the application is free to do with the object what it wants. */
    if (!corto_check_attr(o, CORTO_ATTR_PERSISTENT) && !corto_isorphan(o)) {
        return TRUE;
    }

    corto_object owner = corto_sourceof(o);
    corto_object current = corto_get_source();
    bool result = FALSE;

    if (!corto_check_state(o, CORTO_VALID)) {
        /* If object is not DEFINED it is not owned yet, and it's fair game */
        result = TRUE;
    } else {
        result = corto_ownerMatch(owner, current);
    }

    return result;
}

int32_t corto_claim(corto_object o) {
    corto_assertObject(o);

    if (corto_isbuiltin(o)) {
        return 2;
    }

    corto__object* _o;
    uint32_t i;

    _o = CORTO_OFFSET(o, -sizeof(corto__object));
    i = corto_ainc(&_o->refcount);

    if (CORTO_TRACE_OBJECT || CORTO_TRACE_ID) corto_memtrace("claim", o, NULL);

    return i;
}

int32_t corto_release(corto_object o) {
    corto_assertObject(o);

    if (corto_isbuiltin(o)) {
        return 1;
    }

    int32_t i;
    corto__object* _o;

    _o = CORTO_OFFSET(o, -sizeof(corto__object));
    i = corto_adec(&_o->refcount);

    if (CORTO_TRACE_OBJECT || CORTO_TRACE_ID) corto_memtrace("release", o, NULL);
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

static
corto_object corto_lookup_intern(
    corto_object parent,
    const char *id,
    bool resume)
{
    corto_assertObject(parent);

    if (!parent) {
        parent = root_o;
    }

    corto_object o = parent;
    corto__object *_o, *_result;
    corto__scope* scope;
    corto_rb tree;
    corto_object prev = NULL, known_prev = NULL;;
    char ch;
    const char *next, *ptr = id, *last_known_ptr = id;

    if (!id || !id[0]) {
        corto_throw("invalid identifier");
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

        bool containsArgs = FALSE;
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
                    int32_t diff, d;
                    o = corto_lookupFunction(o, ptr, &d, &diff);
                    if (d < 0) {
                        corto_release(o);
                        o = NULL;
                    } else if (!diff) { /* Ambiguous reference */
                        if (o) corto_release(o);
                        corto_throw("lookup: ambiguous reference '%s'", ptr);
                        goto error;
                    }

                    if (o) corto_release(o);
                } else {
                    if (corto_rwmutex_read(&scope->align.scopeLock)) {
                        corto_throw(NULL);
                        goto error;
                    }
                    if (!corto_rb_hasKey_w_cmp(
                          tree,
                          ptr,
                          (void**)&o,
                          (corto_equals_cb)corto_compareLookup))
                    {
                        o = NULL;
                    } else if (strchr(corto_idof(o), '(')) {
                        corto_object checkNoArgs = NULL;

                        /* If requesting an id without '()' and an id with '()'
                         * is returned, look again without allowing for '()' to
                         * give preference to an object without '()' */
                        if (corto_rb_hasKey_w_cmp(
                              tree,
                              ptr,
                              (void**)&checkNoArgs,
                              (corto_equals_cb)corto_compareLookupNoArgMatching))
                        {
                            o = checkNoArgs;
                        } else if (corto_instanceof(corto_function_o, o)) {
                            if (corto_function(o)->overloaded == TRUE) {
                                corto_throw("lookup: ambiguous reference '%s'", id);
                                corto_rwmutex_unlock(&scope->align.scopeLock);
                                goto error;
                            }
                        }
                    }
                    if (corto_rwmutex_unlock(&scope->align.scopeLock)) {
                        corto_throw(NULL);
                        goto error;
                    }
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

        if (corto_typeof(o) != corto_unknown_o) {
            known_prev = o;
            last_known_ptr = ptr;
        }
    } while (ch);

    if (resume && parent != corto_lang_o) {
        if (!known_prev) {
            known_prev = parent;
        }
        if (!last_known_ptr) {
            last_known_ptr = id;
        }
        if (last_known_ptr[0] == '/') {
            last_known_ptr ++;
        }
        if (!o) {
            o = corto_resume(known_prev, last_known_ptr, NULL);
        }
    }

    if (o && corto_secured() && !corto_authorize(o, CORTO_SECURE_ACTION_READ)) {
        goto access_error;
    }

    return o;
access_error:
    corto_release(o);
error:
    return NULL;
}

corto_object corto_lookup(
    corto_object scope,
    const char *id)
{
    return corto_lookup_intern(scope, id, TRUE);
}

bool corto_declaredByMeCheck(corto_object o);

/* Resolve anonymous object */
static
const char* corto_resolveAnonymous(
    corto_object scope,
    corto_object o,
    const char *str,
    corto_object* out)
{
    const char *ptr = str;
    corto_object result = corto_declare(NULL, NULL, o);
    corto_string_deser_t data = {
        .out = result,
        .scope = scope,
        .type = o,
        .isObject = TRUE
    };

    if (corto_type(o)->kind == CORTO_PRIMITIVE) {
        ptr += 1;
    }

    ptr = corto_string_deser(ptr, &data);
    *out = result;

    corto_define(result);

    return ptr;
}

/* Use private function to do a lookup with a string that is guaranteed lowercase */
#include "ctype.h"

/* Resolve fully scoped name */
corto_object corto_resolve_intern(
    corto_object _scope,
    const char *str,
    bool shouldResume)
{
    corto_object scope, _scope_start, o, lookup;
    const char* ptr;
    char *bptr;
    corto_id buffer;
    char ch;
    bool fullyQualified = FALSE;
    bool cortoSearched = FALSE, cortoCoreSearched = FALSE;
    int step = 3;

    if (!str) {
        return NULL;
    }

    ch = str[0];

    if (!ch) {
        return NULL;
    }

    if (ch == '.') {
        _scope_start = _scope;
    } else {
        _scope_start = corto_lang_o;
    }
    scope = _scope_start;

    if (!_scope) {
        _scope = root_o;
    }

    /* Optimization: do not resume objects from builtin scopes, except if they
     * are in / or /corto. */
    if (shouldResume) {
        shouldResume =
            !corto_isbuiltin(_scope) || _scope == corto_o || _scope == root_o;
    }

    if (ch == '/') {
        str += 1;
        scope = root_o;
        fullyQualified = TRUE;
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
        while (ch) {
            if (scope == corto_o) {
                cortoSearched = TRUE;
            } else if (scope == corto_vstore_o) {
                cortoCoreSearched = TRUE;
            }

            bptr = buffer;
            while ((ch = *ptr) && (ch != ':') && (ch != '{') && (ch != '/')) {
                *bptr = ch;
                bptr++;
                ptr++;
                if (ch == '(') {
                    while ((ch = *ptr) && (ch != ')')) {
                        *bptr = ch;
                        bptr++;
                        ptr++;
                    }
                }
            }
            *bptr = '\0';

            /* If buffer is empty, just return current object */
            if (!*buffer) {
                if (step == 3) {
                    return NULL; /* If nothing has been resolved yet, this is
                                  * not a resolvable expression. */
                } else {
                    break;
                }
            }

            if (buffer[0] == '.') {
                if (buffer[1] == '.') {
                    o = corto_parentof(o);
                    if (!o) {
                        corto_throw("cannot resolve parent of root");
                        goto error;
                    }
                    corto_ptr_setref(&lookup, o);
                }
            } else {
                corto_object prevLookup = lookup;

                o = corto_lookup_intern(o, buffer, shouldResume);

                /* Release lookup after(!) potentially resuming an object. In
                 * case of a nested resume, a parent will have been
                 * resumed first. Releasing the parent before resuming the
                 * child will remove the parent from the store. Becuase the
                 * child claims the parent, this won't happen after the
                 * resume. */
                if (prevLookup) {
                    corto_release(prevLookup); /* Free reference */
                }

                lookup = o;

                if (!o) {
                    if (corto_raised()) {
                        corto_throw(NULL);
                        goto error;
                    }
                    break;
                }
            }

            /* Expect scope or serializable string */
            if (ch) {
                if (ch == '{') {
                    do {
                        corto_object prev = o;
                        ptr = corto_resolveAnonymous(_scope, o, (char*)ptr, &o);
                        if (!ptr) {
                            o = NULL;
                        }
                        corto_release(prev);
                    } while (ptr && (ch = *ptr) && (ch == '{'));


                    break;
                } else if (ch == '/') {
                    ptr += 1;
                } else {
                    corto_throw("invalid ':' in expression '%s'", str);
                    o = NULL;
                    break;
                }
            }
        }
        if (o) break;
    } while((step == 2) && (scope = corto_parentof(scope)));

    /* Do lookup in actual scope first, then in corto/vstore, then corto */
    if (!o && step && !fullyQualified) {
        switch(--step) {
        case 2:
            if ((_scope == corto_o) || (_scope == corto_lang_o)) {
                _scope_start = scope = root_o;
            } else {
                _scope_start = scope = _scope;
            }
            goto repeat;
        case 1:
            if (!cortoCoreSearched) {
                _scope_start = scope = corto_vstore_o;
                goto repeat;
            }
            break;
        case 0:
            if (!cortoSearched) {
                _scope_start = scope = corto_o;
                goto repeat;
            }
            break;
        }

         /* Do goto instead of a recursive call. Besides saving (a little bit of) performance,
            this also preserves the original searchscope, which is needed in anonymous type lookups, which
            uses the stringserializer. In a serialized string references to other objects may be relatively
            scoped. For example: the string sequence{F} results in an anonymous sequence object with
            elementType 'F', which is looked up in scope '_scope_start'. */
    }

    /* If the current object is not obtained by a lookup, it is not yet keeped. */
    if (!lookup && o) {
        corto_claim(o);
    }

    if (corto_secured()) {
        if (o && !corto_authorize(o, CORTO_SECURE_ACTION_READ)) {
            goto access_error;
        }
    }

    return o;
access_error:
    corto_release(o);
error:
    return NULL;
}

corto_object corto_resolve(
    corto_object parent,
    const char *id)
{
    return corto_resolve_intern(parent, id, TRUE);
}

corto_object corto_set_source(corto_object owner) {
    corto_assertObject(owner);
    corto_object result = corto_tls_get(CORTO_KEY_OWNER);
    corto_tls_set(CORTO_KEY_OWNER, owner);
    return result;
}

corto_object corto_get_source() {
    return corto_tls_get(CORTO_KEY_OWNER);
}

/* Publish new value for object */
int16_t corto_publish(
    corto_eventMask event,
    const char *id,
    const char *type,
    const char *contentType,
    void *content)
{
    corto_assert(id != NULL, "NULL passed to 'id' parameter of corto_publish");

    corto_object o = FIND(NULL, id);

    int16_t result = 0;

    CORTO_UNUSED(type);

    if (o) {
        switch(event) {
        case CORTO_DEFINE:
        case CORTO_UPDATE:
            if (corto_typeof(o)->kind != CORTO_VOID) {
                if (!(result = corto_update_begin(o))) {
                    if ((result = corto_deserialize_value(o, contentType, content))) {
                        corto_update_cancel(o);
                    } else {
                        corto_update_end(o);
                    }
                }
            } else {
                corto_update(o);
            }
            break;
        case CORTO_DELETE:
            result = corto_delete(o);
            break;
        }
        corto_release(o);
    } else {
        if (corto_notifySubscribersId(
          event, id, type, contentType, (corto_word)content))
        {
            result = -1;
        }
    }

    return result;
}

/* Update object */
int16_t corto_update(corto_object o) {
    corto_assertObject(o);

    int16_t result = 0;
    corto_eventMask mask = CORTO_UPDATE;

    if (!corto_owned(o) && (corto_typeof(corto_typeof(o)) != (corto_type)corto_target_o)) {
        corto_throw("object not owned by thread");
        goto error;
    }

    if (corto_secured()) {
        if (!corto_authorize(o, CORTO_SECURE_ACTION_UPDATE)) {
            goto error;
        }
        if (!corto_check_state(o, CORTO_VALID)) {
            mask |= corto_resumeDeclared(o, true) ? CORTO_RESUME : CORTO_DEFINE;
            result = corto_defineDeclared(o);
            if (!result) {
                result = corto_notifyDefined(o, true, mask);
            }
        } else {
            if (corto_notifySecured(o, CORTO_UPDATE)) {
                goto error;
            }
        }
    } else {
        if (!corto_check_state(o, CORTO_VALID)) {
            mask |= corto_resumeDeclared(o, true) ? CORTO_RESUME : CORTO_DEFINE;
            result = corto_defineDeclared(o);
            if (!result) {
                result = corto_notifyDefined(o, true, mask);
            }
        } else {
            if (corto_notify(o, CORTO_UPDATE)) {
                goto error;
            }
        }
    }

    return result;
error:
    return -1;
}

static
int16_t corto_update_begin_intern(
    corto_object o,
    bool resume)
{
    corto_assertObject(o);
    corto_type type = corto_typeof(o);

    /* Update fails if process isn't authorized to update observable */
    if (corto_secured() && !corto_authorize(o, CORTO_SECURE_ACTION_UPDATE)) {
        goto error;
    }

    if (!corto_check_state(o, CORTO_VALID)) {
        corto_resumeDeclared(o, resume);
    }

    if (!(type->flags & CORTO_TYPE_HAS_TARGET) && (corto_typeof(type) != (corto_type)corto_target_o) && !corto_owned(o)) {
        corto_throw("updateBegin: cannot update '%s', process does not own object",
            corto_fullpath(NULL, o));
        goto error;
    }

    if (!corto_check_state(o, CORTO_VALID) && !corto_declaredByMeCheck(o)) {
        corto_throw("updateBegin: cannot update '%s', object is being defined by other thread",
            corto_fullpath(NULL, o));
        goto error;
    }

    if (corto_check_state(o, CORTO_VALID)) {
        corto__writable* _wr = corto__objectWritable(CORTO_OFFSET(o, -sizeof(corto__object)));
        if (_wr) {
            if (corto_rwmutex_write(&_wr->align.lock)) {
                corto_throw(NULL);
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

int16_t corto_update_begin(
    corto_object o)
{
    return corto_update_begin_intern(o, TRUE);
}

int16_t corto_update_end(
    corto_object observable)
{
    corto_assertObject(observable);

    corto__writable* _wr;
    int16_t result = 0;
    bool defined = TRUE;

    if (!corto_check_state(observable, CORTO_VALID)) {
        corto_object owner = corto_sourceof(observable);
        defined = FALSE;
        corto_eventMask mask = 0;
        if (owner && corto_instanceof(corto_mount_o, owner) &&
            (corto_mount(owner)->policy.ownership == CORTO_LOCAL_OWNER))
        {
            /* If not defined, and owner is a SINK, object is resumed */
            mask |= CORTO_RESUME;
        } else
        {
            mask |= CORTO_DEFINE;
        }

        result = corto_defineDeclared(observable);
        if (!result) {
            result = corto_notifyDefined(observable, true, mask);
        }
    } else {
        if (corto_secured()) {
            if (corto_notifySecured(observable, CORTO_UPDATE)) {
                goto error;
            }
        } else {
            if (corto_notify(observable, CORTO_UPDATE)) {
                goto error;
            }
        }
    }

    if (defined) {
        _wr = corto__objectWritable(CORTO_OFFSET(observable, -sizeof(corto__object)));
        if (_wr) {
            if (corto_rwmutex_unlock(&_wr->align.lock)) {
                corto_throw("updateEnd: unlock on '%s' failed",
                  corto_fullpath(NULL, observable));
            }
        }
    }

    return result;
error:
    return -1;
}

int16_t corto_update_cancel(corto_object observable) {
    corto_assertObject(observable);

    if (corto_check_attr(observable, CORTO_ATTR_OBSERVABLE)) {
        corto__writable* _wr;

        _wr = corto__objectWritable(CORTO_OFFSET(observable, -sizeof(corto__object)));

        if (corto_rwmutex_unlock(&_wr->align.lock)) {
            corto_throw("updateCancel: unlock on '%s' failed",
              corto_fullpath(NULL, observable));
        }
    } else {
        corto_throw("updateCancel: object '%s' is not an observable",
            corto_fullpath(NULL, observable));
        goto error;
    }

    return 0;
error:
    return -1;
}

/* Thread-safe reading */
int16_t corto_read_begin(corto_object object) {
    corto_assertObject(object);

    if (corto_check_attr(object, CORTO_ATTR_WRITABLE)) {
        corto__writable* _o;

        _o = corto__objectWritable(CORTO_OFFSET(object, -sizeof(corto__object)));
        if (corto_rwmutex_read(&_o->align.lock)) {
            corto_throw("readBegin '%s' failed",
              corto_fullpath(NULL, object));
            goto error;
        }
    }

    return 0;
error:
    return -1;
}

int16_t corto_read_end(corto_object object) {
    corto_assertObject(object);
    return corto_unlock(object);
}

static
int16_t corto_lock_intern(
    corto_object object)
{
    if (corto_check_attr(object, CORTO_ATTR_WRITABLE)) {
        corto__writable* _o;

        _o = corto__objectWritable(CORTO_OFFSET(object, -sizeof(corto__object)));
        if (corto_rwmutex_write(&_o->align.lock)) {
            goto error;
        }
    }

    return 0;
error:
    return -1;
}

/* Thread-safe writing */
int16_t corto_lock(
    corto_object object)
{
    corto_assertObject(object);
    if (!corto_check_state(object, CORTO_VALID)) {
        if (corto_declaredByMeCheck(object)) {
            /* Don't lock if object is being defined */
            return 0;
        }
    }
    return corto_lock_intern(object);
}

static
int16_t corto_unlock_intern(
    corto_object object)
{
    if (corto_check_attr(object, CORTO_ATTR_WRITABLE)) {
        corto__writable* _o;

        _o = corto__objectWritable(CORTO_OFFSET(object, -sizeof(corto__object)));
        if (corto_rwmutex_unlock(&_o->align.lock)) {
            goto error;
        }
    }
    return 0;
error:
    return -1;
}

int16_t corto_unlock(
    corto_object object)
{
    corto_assertObject(object);

    if (!corto_check_state(object, CORTO_VALID)) {
        if (corto_declaredByMeCheck(object)) {
            /* Don't lock if object is being defined */
            return 0;
        }
    }

    return corto_unlock_intern(object);
}

/* Obtain function name from signature */
int32_t corto_signatureName(
    const char *signature,
    corto_id buffer)
{
    char ch, *bptr;
    const char *srcptr;

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
int32_t corto_signatureParamCount(
    const char *signature)
{
    const char *ptr;
    char ch;
    uint32_t count;

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
                uint32_t nesting = 1;
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
int32_t corto_signatureParamType(
    const char *signature,
    uint32_t id,
    corto_id buffer,
    int* flags)
{
    char ch, *bptr;
    const char *srcptr;
    uint32_t i;
    bool parsed, parsing;

    if (flags) {
        *flags = 0;
    }

    srcptr = strchr(signature, '(');
    if (!srcptr) {
        corto_throw("missing argmentlist in signature '%s'", signature);
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
                        corto_throw("invalid parameter modifier '%s'", buffer);
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
                uint32_t count=1;
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
int32_t corto_signatureParamName(
    const char *signature,
    uint32_t id,
    corto_id buffer)
{
    char ch, *bptr;
    const char *srcptr;
    uint32_t i;
    bool parsed;

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
                uint32_t count=1;
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
uint32_t corto_overloadParamCount(corto_object o) {
    corto_assertObject(o);

    uint32_t result;
    if (corto_interface(corto_typeof(o))->kind == CORTO_PROCEDURE) {
        result = corto_function(o)->parameters.length;
    } else {
        result = corto_delegate(corto_typeof(o))->parameters.length;
    }
    return result;
}

/* Helper function that obtains type from signature */
corto_type corto_overloadParamType(corto_object object, int32_t i, bool *reference) {
    corto_assertObject(object);

    corto_id buffer;
    int32_t flags = 0;
    corto_id signatureBuffer;
    char *signature;
    corto_type result;

    if (!(signature = corto_signature(object, signatureBuffer))) {
        corto_throw("invalid signature %s", signature);
        goto error;
    }

    if (corto_signatureParamType(signature, i, buffer, &flags)) {
        corto_throw("cannot get parameter %d from signature %s", i, signature);
        goto error;
    }

    if (flags & CORTO_PARAMETER_REFERENCE) {
        if (reference) *reference = TRUE;
    } else {
        if (reference) *reference = FALSE;
    }

    result = RESOLVE(corto_parentof(object), buffer);
    if (!result) {
        corto_throw(
          "unresolved type '%s' in signature '%s'", buffer, signature);
        goto error;
    }

    if(!corto_instanceof(corto_type_o, result)) {
        corto_throw(
          "object '%s' in signature '%s' is not a type", buffer, signature);
        goto error;
    }

    return result;
error:
    return NULL;
}


/* Compare parameter */
static
uint32_t corto_overloadParamCompare(
    corto_type o_type,
    corto_type r_type,
    bool o_reference,
    bool r_reference,
    bool r_forceReference,
    bool r_wildcard,
    bool r_null) {
    int32_t d = 0;

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
            goto nomatch;
        } else {
            goto match;
        }
    }

    /* Match type compatibility */
    if (o_type == r_type) {
        goto match;
    }

    if (corto_check_state(o_type, CORTO_VALID) && (corto_check_state(r_type, CORTO_VALID))) {

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
static
void corto_signatureFromDelegate(
    corto_object o,
    corto_id buffer)
{
    corto_assertObject(o);

    corto_delegate type = corto_delegate(corto_typeof(o));
    uint32_t i;

    /* Construct signature */
    char *signature = corto_signatureOpen(corto_idof(o));
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
    corto_throw(
      "can't get signature from '%s' of non-procedure type '%s'",
      corto_fullpath(NULL, object),
      corto_fullpath(NULL, t));
    return NULL;
}

static
bool corto_signatureCompareName(
    const char *offered,
    const char *requested)
{
    /* Validate if names of request and offered match */
    const char *o_ptr = offered, *r_ptr = requested;
    char o_ch, r_ch = *r_ptr;
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
int16_t corto_overload(
    corto_object object,
    const char *requested,
    int32_t* distance)
{
    corto_assertObject(object);

    int32_t r_parameterCount, o_parameterCount;
    int32_t i = 0, d = 0;
    corto_id offeredBuffer;
    char *offered;

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
        goto nomatch_overload;
    }

    /* If request contains parameters, compare parameters of both */
    if (r_parameterCount == o_parameterCount) {
        for (i = 0; i < o_parameterCount; i++) {
            bool o_reference = FALSE, r_reference = FALSE;
            bool r_forceReference = FALSE, r_wildcard = FALSE, r_null = FALSE;
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
                    r_type = RESOLVE(NULL, r_typeName);
                    if (r_type) {
                        r_type = corto_type(r_type);
                    } else {
                        corto_throw("unresolved type '%s' in signature '%s'", r_typeName, requested);
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
                    goto nomatch_overload;
                } else {
                    d += paramDistance;
                }
            }
        }
    }

    *distance = d;

    return 0;
nomatch:
    *distance = CORTO_OVERLOAD_NOMATCH;
    return 0;
nomatch_overload:
    *distance = CORTO_OVERLOAD_NOMATCH_OVERLOAD;
    return 0;
error:
    *distance = CORTO_OVERLOAD_ERROR;
    corto_throw_fallback("invalid procedure request '%s'", requested);
    return -1;
}

typedef struct corto_scopeWalk_t {
    corto_objectseq *seq;
    corto_type type;
    char *id;
} corto_scopeWalk_t;

static
int corto_scopeCollectWalk(
    corto_object o,
    void* userData)
{
    corto_assertObject(o);
    corto_scopeWalk_t *data = userData;
    corto_objectseq *seq = data->seq;

    if (!data->type || (corto_typeof(o) == data->type)) {
        if (!data->id || (corto_signatureCompareName(data->id, corto_idof(o)))) {
            if (!seq->buffer) {
                /* Get scopesize within scope lock */
                uint32_t scopeSize = corto_scopeSize(corto_parentof(o));
                seq->buffer = corto_alloc(sizeof(corto_object) * scopeSize);
                /* Increment length with each object */
            }
            corto_claim(o);
            seq->buffer[seq->length++] = o;
        }
    }

    return 1;
}

corto_objectseq corto_scopeClaimWithFilter(
    corto_object scope,
    corto_type type,
    char *id)
{
    corto_assertObject(scope);
    corto_objectseq result = {0, NULL};
    corto_scopeWalk_t walkData;
    walkData.seq = &result;
    walkData.type = type;
    walkData.id = id;
    corto_scopeWalk(scope, corto_scopeCollectWalk, &walkData);
    return result;
}

corto_objectseq corto_scopeClaim(
    corto_object scope)
{
    return corto_scopeClaimWithFilter(scope, NULL, NULL);
}

void corto_scopeRelease(corto_objectseq seq) {
    uint32_t i = 0;
    for (i = 0; i < seq.length; i++) {
        corto_release(seq.buffer[i]);
    }
    corto_dealloc(seq.buffer);
}

typedef struct corto_lookupFunction_t {
    const char *request;
    corto_object *result;
    bool error;
    int32_t d;
    int32_t old_d;
}corto_lookupFunction_t;

/* Lookup function in scope */
int corto_lookupFunctionWalk(corto_object *ptr, void* userData) {
    int32_t d = -1;
    corto_lookupFunction_t* data;
    corto_object o = *ptr;
    corto_type t = corto_typeof(o);

    data = userData;

    /* If current object is a function, match it */
    if ((t->kind == CORTO_COMPOSITE) &&
        ((((corto_interface)t)->kind == CORTO_PROCEDURE) ||
        (((corto_interface)t)->kind == CORTO_DELEGATE)))
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
                    corto_throw("ambiguous reference '%s'", data->request);
                    goto found;
                }
            }
        }

        if (d >= 0) {
            int32_t compare = data->d == CORTO_OVERLOAD_NOMATCH_OVERLOAD ? INT_MAX : data->d;
            if (d <= compare) {
                data->old_d = data->d;
            }
            if (d < compare) {
                data->result = (corto_object*)ptr;
                data->d = d;
            }
        } else if (d == CORTO_OVERLOAD_NOMATCH_OVERLOAD && !data->result) {
            data->result = (corto_object*)ptr;
            data->d = d;
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
    const char *requested,
    int32_t* d,
    int32_t* diff)
{
    corto_lookupFunction_t walkData;
    uint32_t i;

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
        *d = walkData.d;
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
    const char *requested,
    int32_t *d,
    int32_t *diff)
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
char* corto_signatureOpen(const char *name) {
    char *result;

    result = corto_alloc(strlen(name) + 1 + 1);
    sprintf(result, "%s(", name);

    return result;
}

char* corto_signatureAdd(char *sig, corto_type type, int flags) {
    uint32_t len;
    char *result;
    corto_id id;
    bool reference = flags & CORTO_PARAMETER_REFERENCE;
    bool forceReference = flags & CORTO_PARAMETER_FORCEREFERENCE;
    bool wildcard = flags & CORTO_PARAMETER_WILDCARD;

    if (type) {
        if (!corto_check_attr(type, CORTO_ATTR_NAMED) ||
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

char* corto_signatureAddWildcard(char *sig, bool isReference) {
    uint32_t len;
    char *result;

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

char* corto_signatureClose(char *sig) {
    uint32_t length = strlen(sig) + 1;
    sig = corto_realloc(sig, length + 1);
    sig[length-1] = ')';
    sig[length] = '\0';
    return sig;
}

char* corto_str(
    corto_object object,
    uint32_t maxLength)
{
    corto_assertObject(object);

    corto_string_ser_t serData;
    corto_walk_opt s;

    serData.buffer = CORTO_BUFFER_INIT;
    serData.buffer.max = maxLength;
    serData.compactNotation = TRUE;
    serData.prefixType = FALSE;
    serData.enableColors = FALSE;

    s = corto_string_ser(CORTO_LOCAL, CORTO_NOT, CORTO_WALK_TRACE_NEVER);
    corto_walk(&s, object, &serData);
    char *result = corto_buffer_str(&serData.buffer);
    corto_walk_deinit(&s, &serData);
    return result;
}

int16_t corto_fromStr(void *o, char *string) {
    corto_string_deser_t serData = {
        .out = *(void**)o,
        .type = *(void**)o ? corto_typeof(*(void**)o) : NULL,
        .isObject = TRUE
    };

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

int corto_compare(
    corto_object o1,
    corto_object o2)
{
    corto_assertObject(o1);
    corto_assertObject(o2);

    corto_compare_ser_t data;
    corto_walk_opt s;

    data.value = corto_value_value(o2, corto_typeof(o2));

    s = corto_compare_ser(CORTO_PRIVATE, CORTO_NOT, CORTO_WALK_TRACE_NEVER);

    corto_walk(&s, o1, &data);

    return data.result;
}

int16_t corto_init(corto_object o) {
    corto_assertObject(o);
    int16_t result = 0;
    corto_type type = corto_typeof(o);

    if (type->flags & CORTO_TYPE_NEEDS_INIT) {
        corto_walk_opt s =
            corto_ser_init(0, CORTO_NOT, CORTO_WALK_TRACE_ON_FAIL);
        if (corto_walk(&s, o, NULL)) {
            goto error;
        }
    }

    if (type->flags & CORTO_TYPE_HAS_INIT) {
        result = corto_callInitDelegate(&type->init, type, o, false);
    }
    return result;
error:
    return -1;
}

int16_t corto_deinit(corto_object o) {
    corto_assertObject(o);
    corto_type type = corto_typeof(o);

    if (type->flags & CORTO_TYPE_HAS_DEINIT) {
        corto_callDestructDelegate(&type->deinit, type, o);
    }

    if (type->flags & CORTO_TYPE_HAS_RESOURCES) {
        freeops_ptr_free(type, o);
    }

    return 0;
}

int16_t _corto_copy(corto_object *dst, corto_object src) {
    corto_assertObject(src);

    corto_walk_opt s = corto_copy_ser(CORTO_PRIVATE, CORTO_NOT, CORTO_WALK_TRACE_ON_FAIL);
    corto_copy_ser_t data;
    int16_t result;
    bool newObject = FALSE;

    if (!*dst) {
        *dst = corto_declare(NULL, NULL, corto_typeof(src));
        newObject = TRUE;
    }

    data.value = corto_value_object(*dst, NULL);
    result = corto_walk(&s, src, &data);

    if (newObject) {
        corto_define(*dst);
    }

    return result;
}

int16_t corto_super_init(corto_object o) {
    corto_interface cur = corto_interface(corto_tls_get(CORTO_KEY_CONSTRUCTOR_TYPE));
    if (!cur) {
        corto_throw("can only call corto_super_init from an initializer");
        goto error;
    }
    corto_type base = (corto_type)cur->base;
    if (base && base->flags & CORTO_TYPE_HAS_INIT) {
        return corto_callInitDelegate(&base->init, (corto_type)base, o, false);
    } else {
        corto_throw("interface '%s' does not have a baseclass", corto_fullpath(NULL, cur));
    }
error:
    return -1;
}

int16_t corto_super_deinit(corto_object o) {
    corto_interface cur = corto_interface(corto_tls_get(CORTO_KEY_CONSTRUCTOR_TYPE));
    if (!cur) {
        corto_throw("can only call corto_super_deinit from an deinitializer");
        goto error;
    }
    corto_type base = (corto_type)cur->base;
    if (base && base->flags & CORTO_TYPE_HAS_DEINIT) {
        corto_callDestructDelegate(&base->deinit, base, o);
    } else {
        corto_throw("interface '%s' does not have a baseclass", corto_fullpath(NULL, cur));
    }

    return 0;
error:
    return -1;
}

int16_t corto_super_construct(corto_object o) {
    corto_interface cur = corto_interface(corto_tls_get(CORTO_KEY_CONSTRUCTOR_TYPE));
    if (!cur) {
        corto_throw("can only call corto_super_construct from a constructor");
        goto error;
    }
    corto_class base = (corto_class)cur->base;
    if (base && ((corto_type)base)->flags & CORTO_TYPE_HAS_CONSTRUCT) {
        return corto_callInitDelegate(&base->construct, (corto_type)base, o, true);
    } else {
        corto_throw("interface '%s' does not have a baseclass", corto_fullpath(NULL, cur));
    }
error:
    return -1;
}

void corto_super_destruct(corto_object o) {
    corto_interface cur = corto_interface(corto_tls_get(CORTO_KEY_CONSTRUCTOR_TYPE));
    if (!cur) {
        corto_throw("can only call corto_super_destruct from a destructor");
        goto error;
    }
    corto_class base = (corto_class)cur->base;
    if (base && ((corto_type)base)->flags & CORTO_TYPE_HAS_DESTRUCT) {
        corto_callDestructDelegate(&base->destruct, (corto_type)base, o);
    } else {
        corto_throw("interface '%s' does not have a baseclass", corto_fullpath(NULL, cur));
    }
error:;
}


char* corto_pathFromFullname(corto_id buffer) {
    char *ptr = buffer, *bptr, ch;
    bptr = ptr;

    for (; (ch = *ptr); ptr++, bptr++) {
        if (ch == ':') {
            *bptr = '/';
            ptr++;
        } else {
            *bptr = ch;
        }
    }

    *bptr = '\0';

    return buffer;
}

/* Check whether object is a builtin package */
bool corto_isBuiltinPackage(corto_object o) {
    return (o == root_o) ||
           (o == corto_o) ||
           (o == corto_lang_o) ||
           (o == corto_vstore_o) ||
           (o == corto_native_o) ||
           (o == corto_secure_o);
}

void* corto_getMemberPtr(corto_object o, void *ptr, corto_member m) {
    void *result;

    if (!ptr) {
        return NULL;
    }

    result = CORTO_OFFSET(ptr, m->offset);

    /* If member is of target type, it represents either a target or actual
     * value. Actual members can only be set if the object is owned by thread
     * that deserializes the value. Target members can only be set if the thread
     * does not own the object. */
    if (corto_typeof(corto_parentof(m)) == (corto_type)corto_target_o) {
        bool owned = corto_owned(ptr);
        bool isActual = strcmp("target", corto_idof(m));
        if ((owned && !isActual) || (!owned && isActual)) {
            result = NULL;
        }
    } else if (o && !corto_owned(o)) {
        /* If type is composite, continue serializing as structure may contain
         * members of target types */
        if (m->type->kind != CORTO_COMPOSITE) {
            result = NULL;
        }
    }

    if (result && (m->modifiers & CORTO_OBSERVABLE)) {
        result = *(void**)result;
    }

    return result;
}

corto_eventMask corto_match_getScope(corto_idmatch_program program) {
    corto_eventMask result = CORTO_ON_SCOPE;
    int32_t op;
    bool quit = false;

    for (op = 0; (op < program->size) && !quit; op ++) {
        switch (program->ops[op].token) {
        case CORTO_MATCHER_TOKEN_IDENTIFIER:
        case CORTO_MATCHER_TOKEN_THIS:
        case CORTO_MATCHER_TOKEN_PARENT:
            result = CORTO_ON_SELF;
            break;
        case CORTO_MATCHER_TOKEN_SCOPE:
            result = CORTO_ON_SCOPE;
            break;
        case CORTO_MATCHER_TOKEN_TREE:
            result = CORTO_ON_TREE;
        default:
            quit = true;
            break;
        }
    }

    return result;
}

corto_object _corto(
    corto_object parent,
    const char *id,
    corto_type type,
    corto_object result,
    corto_fmt contentType,
    void *value,
    corto_attr attrs,
    corto_kind kind)
{
    bool childDeclared = false;
    bool exists = result != NULL;
    bool gotref = false;

    if (!result) {
        corto_attr prevAttr = -1;
        if (attrs != -1) prevAttr = corto_set_attr(attrs);
        if (kind & CORTO_DO_DECLARE) {
            if (parent) {
                if ((kind & CORTO_DO_RECURSIVE_DECLARE) == CORTO_DO_RECURSIVE_DECLARE) {
                    result = corto_declareChildRecursive_intern(
                        parent,
                        (char*)id,
                        type,
                        kind & CORTO_DO_ORPHAN,
                        kind & CORTO_DO_FORCE_TYPE,
                        kind & CORTO_DO_DEFINE,
                        FALSE,
                        kind & CORTO_DO_RESUME);
                } else {
                    result = corto_declareChild_intern(
                        parent,
                        (char*)id,
                        type,
                        kind & CORTO_DO_ORPHAN,
                        kind & CORTO_DO_FORCE_TYPE,
                        kind & CORTO_DO_DEFINE,
                        NULL);
                }
                childDeclared = true;
            } else {
                corto_assert(
                    kind & CORTO_DO_ORPHAN ||
                    id == NULL, "id provided but no parent provided");
                result = corto_declare(NULL, NULL, type);
            }
        } else if (kind & CORTO_DO_LOOKUP_TYPE) {
            result = corto_resolve_intern(parent, (char*)id, kind & CORTO_DO_RESUME);
            gotref = true;
        } else {
            result = corto_lookup_intern(parent, (char*)id, kind & CORTO_DO_RESUME);
            gotref = true;
        }
        if (prevAttr != -1) corto_set_attr(prevAttr);
    } else if (kind & CORTO_DO_FORCE_TYPE) {
        if (!corto_instanceof(type, result)) {
            corto_throw("type mismatch");
            goto error;
        }
    }

    if (result) {
        bool isDefine = kind & CORTO_DO_DEFINE;
        bool isUpdate = kind & CORTO_DO_UPDATE;
        bool isUpdating = false;
        bool isValid = corto_check_state(result, CORTO_VALID);

        /* If application specifies both DEFINE and UPDATE, the function will
         * only do an update if the object is already VALID and was declared. */
        if (isUpdate &&
           (!childDeclared || (isDefine && isValid) || (!isDefine && !isValid)))
        {
            if (corto_update_begin_intern(result, kind & CORTO_DO_RESUME)) {
                goto error;
            }
            isUpdating = true;
        }

        if (isDefine || isUpdate) {
            if (contentType) {
                corto_assert(value != NULL, "contentType specified but no value provided");

                corto_value v = corto_value_object(result, type);
                if (contentType->toValue(&v, (uintptr_t)value)) {
                    goto error;
                }
            }

            if (isUpdating) {
                if (corto_update_end(result)) {
                    goto error;
                }
            } else {
                if (corto_define_intern(result, kind & CORTO_DO_RESUME)) {
                    goto error;
                }
            }
        }
    }

    if (kind & CORTO_DO_ASSERT_SUCCESS) {
        if (!result) {
            corto_throw("object '%s' does not exist", id);
            goto assert_success;
        } else if (!exists) {
            /* If function obtained a new reference to the object, release the
             * claim. A claim is not needed to keep the object alive
             * when the application can assert that the object exists. */
            if (childDeclared) {
                if (corto_check_state(result, CORTO_VALID)) {
                    gotref = true;
                }
            }
            if (gotref) {
                corto_release(result);
            }
        }
    }

    return result;
error:
    if (kind & CORTO_DECLARE) {
        corto_delete(result);
    } else if (!exists) {
        corto_release(result);
    }
assert_success:
    if (kind & CORTO_DO_ASSERT_SUCCESS) {
        corto_raise();
        abort();
    }
    return NULL;
}

corto_object corto_createFromContent(
    char *contentType,
    char *content)
{
    corto_object result = NULL;
    corto_fmt type = corto_fmt_lookup(contentType);
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
