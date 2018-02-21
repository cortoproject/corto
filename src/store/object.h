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

#ifndef CORTO__OBJECT_H_
#define CORTO__OBJECT_H_

/* -- INTERNAL STORE APIs & DATATYPES -- */

#include <corto/corto.h>
#include <corto/store/store.h>
#include <corto/entityadmin.h>
#include "string_deser.h"
#include "init_ser.h"
#include "compare_ser.h"
#include "copy_ser.h"
#include "memory_ser.h"
#include "freeops.h"
#include "fmt.h"
#include "expr.h"
#include "cdeclhandler.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Get address to header of an object */
#define corto_hdr(o)  CORTO_OFFSET(o, -sizeof(corto__object))

/* lookup & resolve that do not attempt to resume objects from the vstore */
#define FIND(p, i) corto(CORTO_LOOKUP, {.parent=p, .id=i})
#define RESOLVE(p, i) corto(CORTO_LOOKUP_TYPE, {.parent=p, .id=i})


/* -- GLOBAL ADMIN -- */

extern corto_entityAdmin corto_subscriber_admin;
extern corto_entityAdmin corto_mount_admin;
extern corto_mutex_s corto_adminLock;


/* -- THREAD LOCAL STORAGE KEYS -- */

extern corto_tls CORTO_KEY_ATTR;
extern corto_tls CORTO_KEY_DECLARED_ADMIN;
extern corto_tls CORTO_KEY_OWNER;
extern corto_tls CORTO_KEY_CONSTRUCTOR_TYPE;


/* -- OBJECT HEADER TYPES -- */

/* object attributes and state */
typedef struct corto__attr {
    /* attributes */
    unsigned scope:1;       /* can an object contain other objects */
    unsigned write:1;       /* can the object be locked for writing */
    unsigned observable:1;  /* can the object be observed */
    unsigned persistent:1;  /* can the object be synchronized across stores */

    /* built-in attributes */
    unsigned builtin:1;     /* is this a builtin (ROM) object */
    unsigned orphan:1;      /* is this an orphaned object */

    /* state */
    unsigned state: 2;       /* object state (VALID | DESTRUCTED) */
}corto__attr;

/* base object header - every object has these fields */
struct corto__object;
typedef struct corto__object {
    /* Force max alignment to be used for struct. This ensures that the
     * member after this struct won't insert any padding bytes, regardless of
     * its alignment. */
    union {
        corto__attr attrs;
        uint64_t dummy;
    } align; /* Anonymous union would've been nice, but not supported in C99 */
    #ifndef NDEBUG
        /* Magic number to check in debugging whether value is an object. This value
         * should not be used in application logic. */
        uint32_t magic;

        /* Used for garbage collector- only enabled in debug builds */
        uint32_t cycles;
    #endif
    int32_t refcount;
    corto_type type;
} corto__object;

/* scope object header - only scoped objects have these fields */
typedef struct corto__scope {
    corto_object parent;
    char *id;
    corto_rb scope;

    /* See corto__object for why this union exists*/
    union {
        struct corto_rwmutex_s scopeLock;
        int64_t dummy;
    } align;
} corto__scope;

/* writable object header - only writable objects have these fields */
typedef struct corto__writable {
    /* See corto__object for why this union exists */
    union {
        struct corto_rwmutex_s lock;
        int64_t dummy;
    } align;
} corto__writable;

/* observable object header - only observable objects have these fields */
typedef struct corto__observer {
    corto_object _this;
    corto_observer observer;
    char notifyKind;
    int32_t count;
} corto__observer;

typedef struct corto__observable corto__observable;
struct corto__observable {
    /* Protected by lock */
    corto_ll onSelf;
    corto_ll onChild;

    /* See corto__object */
    union {
        struct corto_rwmutex_s selfLock;
        int64_t dummy;
    } align;

    /* Lockless access to observers (zero-terminated)
     *  Element -1 contains a counter which indicates by how many
     *  notify-functions it is being used. When this counter reaches zero, the array
     *  can be deleted. */
    corto__observer **onSelfArray;
    corto__observer **onChildArray;
};

/* persistent object header - only persistent objects have these fields */
typedef struct corto__persistent corto__persistent;
struct corto__persistent {
    /* This struct is 32 bit on 32 bit architectures, and could result in extra
     * padding bytes in headers. However, as this attribute isn't used in
     * builtin objects, it isn't necessary to take into account struct
     * alignment. */
    corto_object source;

    /* Objects that are explicitly resumed should also be explicitly suspended
     * by an application. If this is set to true, corto won't automatically
     * attempt to decrease refcount when dropping a scope.
     *
     * Only objects that are resumed through a lookup operation set this flag to
     * true. If an object has been created with declareChild explicitly, it
     * will be set to false. */
    bool resumed;
};


CORTO_EXPORT
bool corto_isbuiltin_package(corto_object o);

CORTO_EXPORT
void* corto_getMemberPtr(corto_object o, void *ptr, corto_member m);


/* -- OBJECT LIFECYCLE -- */

void corto_init_builtin(
    corto_object sso);

int16_t corto_deinit_builtin(
    corto_object sso);

int16_t corto_invoke_preDelegate(
    corto_pre_action *d,
    corto_type t,
    corto_object o);

void corto_invoke_postDelegate(
    corto_post_action *d,
    corto_type t,
    corto_object o);

void corto_drop(
    corto_object o,
    bool delete);

bool corto_destruct(
    corto_object o,
    bool delete);

corto_object corto_resume(
    corto_object parent,
    const char *expr,
    corto_object o);

int16_t corto_suspend(
    corto_object o);


/* -- SCOPE ACTIONS -- */

corto_rb corto_scopeof(
    corto_object o);

corto__scope *corto_scope_lock(
    corto_object o);

void corto_scope_unlock(
    corto_object o);

corto_objectseq corto_scope_claimWithFilter(
    corto_object scope,
    corto_type type,
    char *id);


/* -- NOTIFICATIONS -- */

int16_t corto_notify(
    corto_object observable,
    corto_uint32 mask);

int16_t corto_notify_secured(
    corto_object observable,
    corto_uint32 mask);

void corto_observer_delayedAdminDefine(
    corto_object instance);

int16_t corto_notify_subscribers(
    corto_eventMask mask,
    corto_object o);

int16_t corto_notify_subscribersById(
    corto_eventMask mask,
    const char *path,
    const char *type,
    const char *fmtId,
    corto_word value);


/* -- CORE INITIALIZATION -- */

void corto_ptr_operatorInit(void);

void corto_ptr_castInit(void);


/* -- MISC -- */

corto__observable* corto_hdr_observable(
    corto__object* o);

corto_procedure corto_function_getProcedureType(
    corto_function this);

corto_object *corto_lookup_functionFromSequence(
    corto_objectseq scopeContents,
    const char* requested,
    int32_t* d,
    int32_t *diff);

int corto_load_intern(
    corto_string str,
    int argc,
    char* argv[],
    bool ignoreRecursive,
    bool alwaysRun);

int16_t corto_collect(
    corto_object root);

void corto_fmt_deinit(void);

#ifdef __cplusplus
}
#endif

#endif /* CORTO__OBJECT_H_ */
