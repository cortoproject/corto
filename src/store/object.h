/* Copyright (c) 2010-2017 the corto developers
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

#include <corto/corto.h>
#include <corto/store/store.h>
#include <corto/entityadmin.h>

#ifdef __cplusplus
extern "C" {
#endif

void corto_operatorInit(void);
void corto_ptr_castInit(void);

void corto_drop(corto_object o, corto_bool delete);
corto_object corto_resumePersistent(corto_object o);

struct corto_contentType {
    corto_string name;
    bool isBinary;

    /* Translate values to and from a contentType value */
    corto_word ___ (*fromValue)(corto_value *v);
    corto_int16 ___ (*toValue)(corto_value *v, corto_word content);

    /* Translate results to and from self-contained contentType values */
    corto_word ___ (*fromResult)(corto_result *o);
    corto_int16 ___ (*toResult)(corto_result* o, corto_word content);

    /* Translate objects to and from self-contained contentType values */
    corto_word ___ (*fromObject)(corto_object o);
    corto_int16 ___ (*toObject)(corto_object* o, corto_word content);

    /* Duplicate a contentType value */
    corto_word ___ (*copy)(corto_word content);

    /* Free a contentType value */
    void (*release)(corto_word content);
};

typedef struct corto__attr {
    /* attributes */
    unsigned scope:1;
    unsigned write:1;
    unsigned observable:1;
    unsigned persistent:1;

    /* built-in attributes */
    unsigned builtin:1;
    unsigned orphan:1;

    /* state */
    unsigned state: 2;
}corto__attr;

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
    #endif
    int32_t refcount;
    corto_type type;
} corto__object;

typedef struct corto__ols {
    int8_t key;
    void *value;
} corto__ols;

typedef struct corto__scope {
    corto_object parent;
    char *id;
    corto_rb scope;

    /* See corto__object */
    union {
        struct corto_rwmutex_s scopeLock;
        int64_t dummy;
    } align;
    corto__ols *ols;
} corto__scope;

typedef struct corto__writable {
    /* See corto__object */
    union {
        struct corto_rwmutex_s lock;
        int64_t dummy;
    } align;
} corto__writable;

typedef struct corto__observer corto__observer;
typedef void (*corto__notifyCallback)(corto__observer* data, corto_object _this, corto_object observable, corto_uint32 mask);

struct corto__observer {
    corto_object _this;
    corto_observer observer;
    char notifyKind;
    int32_t count;
};

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

typedef struct corto__persistent corto__persistent;
struct corto__persistent {
    /* This struct is 32 bit on 32 bit architectures, and could result in extra
     * padding bytes in headers. However, as this attribute isn't used in
     * builtin objects, it isn't necessary to take into account struct
     * alignment. */
    corto_object owner;

    /* Objects that are explicitly resumed should also be explicitly suspended
     * by an application. If this is set to true, corto won't automatically
     * attempt to decrease refcount when dropping a scope.
     *
     * Only objects that are resumed through a lookup operation set this flag to
     * true. If an object has been created with declareChild explicitly, it
     * will be set to false. */
    bool resumed;
};

typedef struct corto_mount_olsData_t {
    corto_mount mount;
    corto_eventMask mask;
} corto_mount_olsData_t;

typedef struct corto_augment_olsData_t {
    corto_mount mount;
    corto_string id;
} corto_augment_olsData_t;

/* Initialize static scoped object */
void corto__newSSO(corto_object sso);
corto_int16 corto__freeSSO(corto_object sso);

/* Adopt static scoped object */
int corto__adoptSSO(corto_object sso);

/* Orphan object */
void corto__orphan(corto_object o);

/* Set state on object */
void corto__setState(corto_object o, corto_uint8 state);

/* Provide extra debug information to release */
corto_int32 corto_release_ext(corto_object src, corto_object o, corto_string context);

corto_bool corto_destruct(corto_object o, corto_bool delete);

/* Get & lock scope */
corto__scope *corto__scopeClaim(corto_object o);
void corto__scopeRelease(corto_object o);
void* corto_olsFind(corto__scope *scope, corto_int8 key);

/* Get scope tree */
corto_rb corto_scopeof(corto_object o);

corto_int16 corto_notifySubscribers(corto_eventMask mask, corto_object o);
corto_int16 corto_notifySubscribersId(
    corto_eventMask mask,
    corto_string path,
    corto_string type,
    corto_string contentType,
    corto_word value);

corto__observable* corto__objectObservable(corto__object* o);
corto_int16 corto_notify(corto_object observable, corto_uint32 mask);
corto_int16 corto_notifySecured(corto_object observable, corto_uint32 mask);
void corto_notifyObservers(corto__observable* _o, corto_object observable, corto_object source, corto_uint32 mask, int depth);
void corto_notifyParentObservers(corto__observable* _o, corto_object observable, corto_object source, corto_uint32 mask, int depth);
void corto_observerDelayedAdminDefine(corto_object instance);

corto_object corto_resume(corto_object parent, corto_string expr, corto_object o);
corto_int16 corto_suspend(corto_object o);
int corto_loadIntern(corto_string str, int argc, char* argv[], corto_bool _try, corto_bool ignoreRecursive);

corto_objectseq corto_scopeClaimWithFilter(corto_object scope, corto_type type, char *id);

/* proxy for corto/expr functions */
typedef struct ext_corto_expr {
    corto_function function;
} ext_corto_expr;

typedef struct ext_corto_expr_opt {
    corto_object scope;
    corto_type returnType;
    corto_bool returnsReference;
    corto_bool inverse;
} ext_corto_expr_opt;

ext_corto_expr* ext_corto_expr_alloc(void);
corto_int16 ext_corto_expr_compb(ext_corto_expr *out, ext_corto_expr_opt *opt, char *expr, char **types);
corto_int16 ext_corto_expr_runb(ext_corto_expr *expr, corto_value *out, void **args);
corto_int16 ext_corto_expr_free(ext_corto_expr *expr);

corto_procedure corto_function_getProcedureType(corto_function this);

corto_int16 corto_callInitDelegate(corto_initAction *d, corto_type t, corto_object o, bool isDefine);
void corto_callDestructDelegate(corto_destructAction *d, corto_type t, corto_object o);

extern corto_entityAdmin corto_subscriber_admin;
extern corto_entityAdmin corto_mount_admin;

typedef struct freeops freeops;

void freeops_ptr_free(corto_type t, void *ptr);
void freeops_create(freeops *r, corto_type type);
void freeops_delete(corto_struct t);

/* In place replacelemt of '::' with '/' */
CORTO_EXPORT char* corto_pathFromFullname(corto_id buffer);

/* Check if object is a builtin package */
CORTO_EXPORT bool corto_isBuiltinPackage(corto_object o);

/* Check if object is a builtin object */
CORTO_EXPORT bool corto_isBuiltin(corto_object o);

/* Obtain documentation objects */
CORTO_EXPORT char* corto_manId(corto_object o, corto_id buffer);
CORTO_EXPORT corto_object corto_man(corto_object o);

/* Obtain pointer and type for deserializing member */
CORTO_EXPORT void* corto_getMemberPtr(corto_object o, void *ptr, corto_member m);

#ifdef __cplusplus
}
#endif

#endif /* CORTO__OBJECT_H_ */
