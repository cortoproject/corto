/*
 * corto_object.h
 *
 *  Created on: Aug 2, 2012
 *      Author: sander
 */

#ifndef CORTO_OBJECT_H_
#define CORTO_OBJECT_H_

#include "core/_type.h"
#include "lang/_type.h"
#include "secure/_type.h"
#include "corto/value.h"
#include "corto/async.h"
#include "corto/time.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef char corto_id[CORTO_MAX_PATH_LENGTH];
typedef int (*corto_scopeWalkAction)(corto_object o, void* userData);
typedef corto_equalityKind ___ (*corto_equalsAction)(corto_type _this, const void* o1, const void* o2);

/* Object lifecycle */
CORTO_EXPORT corto_object _corto_create(corto_type type);
CORTO_EXPORT corto_object _corto_createChild(corto_object parent, corto_string id, corto_type type);
CORTO_EXPORT corto_object _corto_createOrphan(corto_object parent, corto_string id, corto_type type);
CORTO_EXPORT corto_object _corto_findOrCreate(corto_object parent, corto_string id, corto_type type);
CORTO_EXPORT corto_object _corto_declare(corto_type type);
CORTO_EXPORT corto_object _corto_declareChild(corto_object parent, corto_string id, corto_type type);
CORTO_EXPORT corto_object _corto_declareOrphan(corto_object parent, corto_string id, corto_type type);
CORTO_EXPORT corto_object _corto_findOrDeclare(corto_object parent, corto_string id, corto_type type);
CORTO_EXPORT corto_int16 corto_define(corto_object o);
CORTO_EXPORT corto_int16 corto_delete(corto_object o);

/* Object notifications */
CORTO_EXPORT corto_int16 corto_update(corto_object observable);
CORTO_EXPORT corto_int16 corto_updateBegin(corto_object observable);
CORTO_EXPORT corto_int16 corto_updateTry(corto_object observable);
CORTO_EXPORT corto_int16 corto_updateEnd(corto_object observable);
CORTO_EXPORT corto_int16 corto_updateCancel(corto_object observable);
CORTO_EXPORT corto_int16 corto_invalidate(corto_object o);
/* Publish event without reference to an object */
CORTO_EXPORT corto_int16 corto_publish(
    corto_eventMask event,
    corto_string id,
    corto_string type,
    corto_string contentType,
    void *content);

/* Memory management */
CORTO_EXPORT corto_int32 corto_claim(corto_object o);
CORTO_EXPORT corto_int32 corto_release(corto_object o);
CORTO_EXPORT void corto_setref(void* ptr, corto_object value);
CORTO_EXPORT void corto_setstr(corto_string* ptr, corto_string value);

/* Create heap objects for non-reference types */
CORTO_EXPORT void* _corto_new(corto_type type);
CORTO_EXPORT void _corto_free(corto_type type, void *ptr);

/* Set/get object attributes for current thread */
CORTO_EXPORT corto_attr corto_setAttr(corto_attr attr);
CORTO_EXPORT corto_attr corto_getAttr(void);

/* Security */
CORTO_EXPORT corto_uint16 corto_useradd(corto_string userId, corto_string password, corto_string group, corto_string home);
CORTO_EXPORT corto_uint16 corto_userdel(corto_string userId);
CORTO_EXPORT corto_string corto_login(corto_string username, corto_string password);
CORTO_EXPORT void corto_logout(corto_string token);
CORTO_EXPORT corto_string corto_authenticate(corto_string key);
CORTO_EXPORT corto_bool corto_authorized(corto_object object, corto_secure_actionKind access);
CORTO_EXPORT corto_bool corto_authorizedId(corto_string id, corto_secure_actionKind access);
CORTO_EXPORT corto_bool corto_secured(void);

/* Object metadata */
CORTO_EXPORT corto_type corto_typeof(corto_object o);
CORTO_EXPORT corto_int32 corto_countof(corto_object o);
CORTO_EXPORT corto_state corto_stateof(corto_object o);
CORTO_EXPORT corto_attr corto_attrof(corto_object o);
CORTO_EXPORT corto_bool corto_checkState(corto_object o, corto_int8 state);
CORTO_EXPORT corto_bool corto_checkAttr(corto_object o, corto_int8 attr);
CORTO_EXPORT corto_bool _corto_instanceof(corto_type type, corto_object o);
CORTO_EXPORT corto_bool _corto_instanceofType(corto_type type, corto_type valueType);

/* Object metadata for scoped objects */
CORTO_EXPORT corto_string corto_idof(corto_object o);
CORTO_EXPORT corto_string corto_nameof(corto_id str, corto_object o);
CORTO_EXPORT corto_object corto_parentof(corto_object o);
CORTO_EXPORT corto_bool corto_childof(corto_object p, corto_object o);
CORTO_EXPORT corto_uint32 corto_scopeSize(corto_object o);
CORTO_EXPORT corto_objectseq corto_scopeClaim(corto_object o);
CORTO_EXPORT corto_objectseq corto_scopeClaimWithFilter(corto_object scope, corto_type type, corto_string id);
CORTO_EXPORT void corto_scopeRelease(corto_objectseq scope);
CORTO_EXPORT corto_int16 corto_scopeWalk(corto_object o, corto_scopeWalkAction action, void *userData);

/* Ownership */
CORTO_EXPORT corto_object corto_ownerof(corto_object o);
CORTO_EXPORT corto_bool corto_owned(corto_object o);
/* Set/get owner for thread */
CORTO_EXPORT corto_object corto_setOwner(corto_object owner);
CORTO_EXPORT corto_object corto_getOwner(void);

/* Object path */
CORTO_EXPORT corto_string corto_fullpath(corto_id str, corto_object o);
CORTO_EXPORT corto_string corto_fullname(corto_id str, corto_object o);
CORTO_EXPORT corto_string corto_path(corto_id str, corto_object from, corto_object o, const char* sep);
CORTO_EXPORT corto_string corto_pathname(corto_id str, corto_object from, corto_object o, const char* sep);
CORTO_EXPORT corto_int32 corto_pathToArray(corto_string path, char *elements[], char *sep);
CORTO_EXPORT corto_string corto_cleanpath(corto_id buffer, char* path);

/* Lookup objects by id */
CORTO_EXPORT corto_object corto_lookup(corto_object scope, corto_string id);

/* Lookup object by id, assert if not found or if wrong type, does not claim */
CORTO_EXPORT corto_object _corto_lookupAssert(corto_object scope, corto_string id, corto_type type);

/* Lookup type by id */
CORTO_EXPORT corto_object corto_resolve(corto_object scope, corto_string id);

/* Lookup objects by id according to custom settings */
typedef enum corto_findKind {
    CORTO_FIND_DEFAULT = 0,
    CORTO_FIND_RESUME = 1,
    /* Will be extended with more options */
} corto_findKind;

/* Unstable API */
CORTO_EXPORT corto_object corto_find(corto_object scope, corto_string id, corto_findKind mode);

/* Iterate over objects matching an expression */
typedef struct corto_selectFluent {
    struct corto_selectFluent (*contentType)(corto_string contentType);
    struct corto_selectFluent (*limit)(corto_uint64 offset, corto_uint64 limit);
    struct corto_selectFluent (*type)(corto_string filter);
    struct corto_selectFluent (*instance)(corto_object instance);
    struct corto_selectFluent (*mount)(corto_mount mount);
    struct corto_selectFluent (*fromNow)(void);
    struct corto_selectFluent (*fromTime)(corto_time t);
    struct corto_selectFluent (*fromSample)(corto_uint64 sample);
    struct corto_selectFluent (*toNow)(void);
    struct corto_selectFluent (*toTime)(corto_time t);
    struct corto_selectFluent (*toSample)(corto_uint64 sample);
    struct corto_selectFluent (*forDuration)(corto_time t);
    struct corto_selectFluent (*forDepth)(corto_int64 depth);
    corto_int16 ___ (*iter)(corto_resultIter *ret);
    corto_int16 ___ (*iterObjects)(corto_objectIter *ret); /* Unstable API */
    corto_int64 ___ (*count)(void);
    corto_int16 ___ (*subscribe)(corto_resultIter *ret); /* Unstable API */
    corto_int16 ___ (*unsubscribe)(void); /* Unstable API */
    corto_string ___ (*id)(void); /* Unstable API */
} corto_selectFluent;
CORTO_EXPORT struct corto_selectFluent corto_select(corto_string scope, corto_string expr, ...);

/* Observe objects for an observable matching an eventmask */
typedef struct corto_observeFluent {
    struct corto_observeFluent (*disabled)(void);
    struct corto_observeFluent (*dispatcher)(corto_dispatcher dispatcher);
    struct corto_observeFluent (*instance)(corto_object instance);
    struct corto_observeFluent (*type)(corto_string type);
    corto_observer ___ (*callback)(void (*r)(corto_object, corto_eventMask, corto_object, corto_observer));
} corto_observeFluent;
CORTO_EXPORT struct corto_observeFluent corto_observe(corto_eventMask event, corto_object observable);
CORTO_EXPORT corto_int16 corto_unobserve(corto_observer observer);

/* Subscribe for notifications matching an expression and eventmask */
typedef struct corto_subscribeFluent {
    struct corto_subscribeFluent (*disabled)(void);
    struct corto_subscribeFluent (*dispatcher)(corto_dispatcher dispatcher);
    struct corto_subscribeFluent (*instance)(corto_object instance);
    struct corto_subscribeFluent (*contentType)(corto_string contentType);
    struct corto_subscribeFluent (*type)(corto_string type);
    corto_subscriber ___ (*callback)(void (*r)(corto_object, corto_eventMask, corto_result*, corto_subscriber));
} corto_subscribeFluent;
CORTO_EXPORT struct corto_subscribeFluent corto_subscribe(corto_eventMask mask, corto_string scope, corto_string expr, ...);
CORTO_EXPORT corto_int16 corto_unsubscribe(corto_subscriber subscriber, corto_object instance);

/* Match corto expression */
typedef struct corto_matchProgram_s* corto_matchProgram;
CORTO_EXPORT corto_bool corto_match(corto_string expr, corto_string str);
CORTO_EXPORT corto_matchProgram corto_matchProgram_compile(corto_string expr, corto_bool allowScopes, corto_bool allowSeparators);
CORTO_EXPORT corto_bool corto_matchProgram_run(corto_matchProgram program, corto_string str);
CORTO_EXPORT void corto_matchProgram_free(corto_matchProgram matcher);
/* Match parent of expression. Returns NULL if no match, or ptr to remainder (for corto_match) */
CORTO_EXPORT char* corto_matchParent(char *parent, char *expr);

/* Serialize object value to contentType */
CORTO_EXPORT corto_string corto_contentof(corto_id str, corto_string contentType, corto_object o);
CORTO_EXPORT corto_int16 corto_fromcontent(corto_object o, corto_string contentType, corto_string content, ...);

/* Serialize object to contentType */
CORTO_EXPORT corto_string corto_object_contentof(corto_id str, corto_string contentType, corto_object o);
CORTO_EXPORT corto_int16 corto_object_fromcontent(corto_object *o, corto_string contentType, corto_string content, ...);

/* Deprecated */
CORTO_EXPORT corto_object corto_createFromContent(corto_string contentType, corto_string content);

/* Object extensions (Object Local Storage) */
CORTO_EXPORT corto_uint8 corto_olsKey(void(*destructor)(void*));
CORTO_EXPORT void* corto_olsSet(corto_object o, corto_int8 key, void *data);
CORTO_EXPORT void* corto_olsGet(corto_object o, corto_int8 key);
/* Thread-safe way to modify OLS data */
CORTO_EXPORT void* corto_olsLockGet(corto_object o, corto_int8 key);
CORTO_EXPORT void corto_olsUnlockSet(corto_object o, corto_int8 key, void *value);

/* Read locking */
CORTO_EXPORT corto_int16 corto_readBegin(corto_object object);
CORTO_EXPORT corto_int16 corto_readEnd(corto_object object);

/* Write locking */
CORTO_EXPORT corto_int16 corto_lock(corto_object object);
CORTO_EXPORT corto_int16 corto_unlock(corto_object object);

/* Serialize to string */
CORTO_EXPORT corto_string corto_str(corto_object object, corto_uint32 maxLength);
CORTO_EXPORT corto_string corto_strv(corto_value* v, corto_uint32 maxLength);
CORTO_EXPORT corto_string _corto_strp(void *p, corto_type type, corto_uint32 maxLength);
CORTO_EXPORT corto_string corto_stra(corto_any a, corto_uint32 maxLength);

/* Deserialize from string */
CORTO_EXPORT corto_int16 corto_fromStr(void *o, corto_string string);
CORTO_EXPORT corto_int16 corto_fromStrv(corto_value *v, corto_string string);
CORTO_EXPORT corto_int16 _corto_fromStrp(void *p, corto_type type, corto_string string);
CORTO_EXPORT corto_int16 corto_fromStra(corto_any *a, corto_string string);

/* Copy */
CORTO_EXPORT corto_int16 _corto_copy(corto_object *dst, corto_object src);
CORTO_EXPORT corto_int16 corto_copyv(corto_value *dst, corto_value *src);
CORTO_EXPORT corto_int16 _corto_copyp(void *dst, corto_type type, void *src);
CORTO_EXPORT corto_int16 corto_copya(corto_any *dst, corto_any src);

/* Compare */
CORTO_EXPORT corto_equalityKind corto_compare(corto_object o1, corto_object o2);
CORTO_EXPORT corto_equalityKind corto_comparev(corto_value *v1, corto_value *value2);
CORTO_EXPORT corto_equalityKind _corto_comparep(void *p1, corto_type type, void *p2);
CORTO_EXPORT corto_equalityKind corto_comparea(corto_any a1, corto_any a2);

/* Init */
CORTO_EXPORT corto_int16 corto_init(corto_object o);
CORTO_EXPORT corto_int16 corto_initv(corto_value *v);
CORTO_EXPORT corto_int16 _corto_initp(void *v, corto_type type);
CORTO_EXPORT corto_int16 corto_inita(corto_any a);

/* Deinit */
CORTO_EXPORT corto_int16 corto_deinit(corto_object o);
CORTO_EXPORT corto_int16 corto_deinitv(corto_value *v);
CORTO_EXPORT corto_int16 _corto_deinitp(void *v, corto_type type);
CORTO_EXPORT corto_int16 corto_deinita(corto_any a);

/* Call base initalizer / constructor / destructor */
CORTO_EXPORT corto_int16 corto_super_init(corto_object o);
CORTO_EXPORT corto_int16 corto_super_construct(corto_object o);
CORTO_EXPORT void corto_super_destruct(corto_object o);

/* Macro's that automate casting of parameters */
#define corto_create(type) _corto_create(corto_type(type))
#define corto_createChild(parent, name, type) _corto_createChild(parent, name, corto_type(type))
#define corto_createOrphan(parent, name, type) _corto_createOrphan(parent, name, corto_type(type))
#define corto_findOrCreate(parent, name, type) _corto_findOrCreate(parent, name, corto_type(type))
#define corto_declare(type) _corto_declare(corto_type(type))
#define corto_declareChild(parent, name, type) _corto_declareChild(parent, name, corto_type(type))
#define corto_declareOrphan(parent, name, type) _corto_declareOrphan(parent, name, corto_type(type))
#define corto_findOrDeclare(parent, name, type) _corto_findOrDeclare(parent, name, corto_type(type))
#define corto_lookupAssert(parent, id, type) _corto_lookupAssert(parent, id, corto_type(type))
#define corto_strp(p, type, maxLength) _corto_strp(p, corto_type(type), maxLength)
#define corto_fromStrp(out, type, string) _corto_fromStrp(out, corto_type(type), string)
#define corto_copy(dst, src) _corto_copy((corto_object*)dst, src)
#define corto_copyp(p, type, src) _corto_copyp(p, corto_type(type), src)
#define corto_comparep(p1, type, p2) _corto_comparep(p1, corto_type(type), p2)
#define corto_initp(p, type) _corto_initp(p, corto_type(type))
#define corto_deinitp(p, type) _corto_deinitp(p, corto_type(type))
#define corto_instanceof(type, o) _corto_instanceof((corto_type)type, o)
#define corto_instanceofType(type, valueType) _corto_instanceofType((corto_type)type, (corto_type)valueType)
#define corto_new(type) _corto_new(corto_type(type))
#define corto_free(type, ptr) _corto_free(corto_type(type), ptr)

#ifdef __cplusplus
}
#endif

#endif /* CORTO_OBJECT_H_ */
