/*
 * corto_object.h
 *
 *  Created on: Aug 2, 2012
 *      Author: sander
 */

#ifndef CORTO_OBJECT_H_
#define CORTO_OBJECT_H_

#include <corto/base.h>
#include <corto/core/_type.h>
#include <corto/lang/_type.h>
#include <corto/secure/_type.h>

#ifdef __cplusplus
extern "C" {
#endif

/** Create a new anonymous object.
 * Equivalent to calling corto_declare + corto_define.
 * @param type The type of the object to create.
 * @return The new object, NULL if failed.
 * @see corto_declare corto_declareChild corto_declareOrphan corto_findOrDeclare
 * @see corto_createChild corto_createOrphan corto_findOrCreate
 * @see corto_define corto_delete corto_release
 */
CORTO_EXPORT 
corto_object _corto_create(
    corto_type type);

/** Create a new scoped object.
 * Equivalent to calling corto_declareChild + corto_define.
 * @param parent The parent for the new object.
 * @param id The object id. If NULL, a random unique id is generated. A name may contain
 *     multiple elements, separated by the '/' character. If one or more elements
 *     do not yet exist, they are created with the specified type.
 * @param type The type of the object to create.
 * @return The new object, NULL if failed.
 * @see corto_declare corto_declareChild corto_declareOrphan corto_findOrDeclare
 * @see corto_create corto_createOrphan corto_findOrCreate
 * @see corto_define corto_delete corto_release
 */
CORTO_EXPORT 
corto_object _corto_createChild(
    corto_object parent, 
    char *id, 
    corto_type type);

/** Create a new orphan object.
 * Equivalent to corto_declareOrphan + corto_define.
 * @param parent The parent for the new object.
 * @param id The object id. If NULL, a random unique id is generated. A name may contain
 *     multiple elements, separated by the '/' character. If one or more elements
 *     do not yet exist, they are created with the specified type.
 * @param type The type of the object to create.
 * @return The new object, NULL if failed.
 * @see corto_declare corto_declareChild corto_declareOrphan corto_findOrDeclare
 * @see corto_create corto_createChild corto_findOrCreate
 * @see corto_define corto_delete corto_release
 */
CORTO_EXPORT 
corto_object _corto_createOrphan(
    corto_object parent, 
    char *id, 
    corto_type type);

/** Find or create a new object.
 * Equivalent to calling corto_findOrDeclare + corto_define.
 * @param parent The parent for the new object.
 * @param id The object id. If NULL, a random unique id is generated. A name may contain
 *     multiple elements, separated by the '/' character. If one or more elements
 *     do not yet exist, they are created with the specified type.
 * @param type The type of the object to create.
 * @return The new object, NULL if failed.
 * @see corto_declare corto_declareChild corto_declareOrphan corto_findOrDeclare
 * @see corto_create corto_createChild corto_createOrphan
 * @see corto_define corto_delete corto_release
 */
CORTO_EXPORT 
corto_object _corto_findOrCreate(
    corto_object parent, 
    char *id, 
    corto_type type);

/** Declare a new anonymous object.
 * This function returns an object in the DECLARED state, allowing for setting 
 * the object value before invoking the type constructor with corto_define. The
 * function fails if the type initializer fails.
 * @param type The type of the object to create.
 * @return The new object, NULL if failed.
 * @see corto_declareChild corto_declareOrphan corto_findOrDeclare
 * @see corto_create corto_createChild corto_createOrphan corto_findOrCreate
 * @see corto_define corto_delete corto_release
 */
CORTO_EXPORT 
corto_object _corto_declare(
    corto_type type);

/** Declare a new object.
 * This function returns an object in the DECLARED state, which enables setting 
 * the object value before invoking the type constructor with corto_define. When
 * the object already exists with the specified type, the existing object will
 * be returned.
 *
 * The function fails if the type initializer fails or if it violates constraints
 * of the specified type on the state or type of the specified parent. The function
 * also fails when the object already exists with a different type.
 *
 * Scoped objects are added to the scope of their parent and have a unique id
 * which makes them discoverable in the object store. When this function succeeds
 * an ON_DECLARE event is emitted.
 *
 * This function will block if there is another thread that has declared, but not
 * defined the same object. Once the other thread defines the object, the function
 * will unblock, and return an object in the DEFINED state. The calling thread can
 * (and should) use the state of the returned object to determine if it needs to
 * initialize the object. The same thread may declare an object multiple times.
 *
 * @param parent The parent for the new object.
 * @param id The object id. If NULL, a random unique id is generated. A name may contain
 *     multiple elements, separated by the '/' character. If one or more elements
 *     do not yet exist, they are created with the specified type.
 * @param type The type of the object to create.
 * @return The new object, NULL if failed.
 * @see corto_declare corto_declareOrphan corto_findOrDeclare
 * @see corto_create corto_createChild corto_createOrphan corto_findOrCreate
 * @see corto_define corto_delete corto_release
 */
CORTO_EXPORT 
corto_object _corto_declareChild(
    corto_object parent, 
    char *id, 
    corto_type type);

/** Declare a new orphaned object.
 * Equivalent to corto_declareChild, except that the function returns an orphaned
 * object.
 *
 * Orphaned objects, like scoped objects have a name and hold a reference to 
 * their parent, but are not added to the scope of their parent and are thus not 
 * discoverable. Orphaned objects are typically used for observable members.
 *
 * @param parent The parent for the new object.
 * @param id The object id. If NULL, a random unique id is generated. A name may contain
 *     multiple elements, separated by the '/' character. If one or more elements
 *     do not yet exist, they are created with the specified type.
 * @param type The type of the object to create.
 * @return The new object, NULL if failed.
 * @see corto_declare corto_declareOrphan corto_findOrDeclare
 * @see corto_create corto_createChild corto_createOrphan corto_findOrCreate
 * @see corto_define corto_delete corto_release
 */
CORTO_EXPORT 
corto_object _corto_declareOrphan(
    corto_object parent, 
    char *id, 
    corto_type type);

/** Declare a new object.
 * Equivalent to corto_declareChild, except that when the function finds an
 * existing object with a different type, it does not fail.
 *
 * @param parent The parent for the new object.
 * @param id The object id. If NULL, a random unique id is generated. A name may contain
 *     multiple elements, separated by the '/' character. If one or more elements
 *     do not yet exist, they are created with the specified type.
 * @param type The type of the object to create.
 * @return The new object, NULL if failed.
 * @see corto_declare corto_declareOrphan corto_findOrDeclare
 * @see corto_create corto_createChild corto_createOrphan corto_findOrCreate
 * @see corto_define corto_delete corto_release
 */
CORTO_EXPORT 
corto_object _corto_findOrDeclare(
    corto_object parent, 
    char *id, 
    corto_type type);

/** Define an object.
 * This function changes the state of an object to DEFINED. When an object is 
 * defined, the type constructor is invoked. If successful, an ON_DEFINE event is 
 * emitted. The DEFINE event indicates the moment when the value
 * of an object is ready to be interpreted by contexts other than the one where
 * the object was being created.
 *
 * This function may emit an ON_RESUME event instead of ON_DEFINE if a SINK mount
 * indicates that it has a copy of the object available. In this case, the function
 * will overwrite the initial object value with the value that the SINK mount provides.
 *
 * This mechanism enables transparent persistency of objects. The value specified
 * by the application is treated as an initial value which is overridden by the
 * latest value of the SINK, which is typically some form of persistent storage.
 *
 * This function will fail if the type constructor fails.
 *
 * If the function fails, the object is left in an undefined, invalid state. An
 * application can attempt again to define the object by calling corto_define again
 * on the object after resolving the issue that caused it to fail.
 *
 * @param o The object to be defined.
 * @return 0 if success, nonzero if failed.
 * @see corto_declare corto_declareChild corto_declareOrphan corto_findOrDeclare
 * @see corto_create corto_createChild corto_createOrphan corto_findOrCreate
 * @see corto_delete corto_release
 */
CORTO_EXPORT 
int16_t corto_define(
    corto_object o);

/** Delete an object.
 * This function deletes an object. If the object was DEFINED, the type destructor
 * will be invoked. 
 *
 * Deleting an object does not guarantee that its memory is freed, as there still
 * may be references to the object. Once all references have been released, the
 * object will be deallocated.
 *
 * This function fails if the current context does not own the object.
 *
 * @param o The object to be deleted.
 * @return 0 if success, nonzero if failed.
 * @see corto_declare corto_declareChild corto_declareOrphan corto_findOrDeclare
 * @see corto_create corto_createChild corto_createOrphan corto_findOrCreate
 * @see corto_delete corto_release
 */
CORTO_EXPORT 
int16_t corto_delete(
    corto_object o);

/** Update an object.
 * This function emits an UPDATE event for the specified object.
 *
 * This function fails if the current context does not own the object or if the
 * object passed to was not created with ATTR_OBSERVABLE.
 *
 * @param o The object to be updated.
 * @return 0 if success, nonzero if failed.
 * @see corto_updateBegin corto_updateEnd corto_updateTry corto_updateCancel corto_publish
 * @see corto_observe corto_subscribe
 */
CORTO_EXPORT 
int16_t corto_update(
    corto_object o);

/** Start updating an object.
 * This function locks the object for thread-safe updating. No event is emitted 
 * yet. This function must be followed up by corto_updateEnd or corto_updateCancel.
 *
 * This function fails if the current context does not own the object or if the
 * object passed to was not created with ATTR_OBSERVABLE.
 *
 * @param o The object to be updated.
 * @return 0 if success, nonzero if failed.
 * @see corto_updateBegin corto_updateEnd corto_updateTry corto_updateCancel corto_publish
 * @see corto_observe corto_subscribe
 */
CORTO_EXPORT 
int16_t corto_updateBegin(
    corto_object o);

/** Try start updating an object.
 * This function locks the object for thread-safe updating only when no other
 * thread is locking the object. Use this function when updating the object has
 * to be as non-intrusive as possible to the application.
 *
 * This function fails if the current context does not own the object or if the
 * object passed to was not created with ATTR_OBSERVABLE, or when
 * the object is already locked.
 *
 * @param o The object to be updated.
 * @return 0 if success, nonzero if failed.
 * @see corto_updateBegin corto_updateEnd corto_updateTry corto_updateCancel corto_publish
 * @see corto_observe corto_subscribe
 */
CORTO_EXPORT 
int16_t corto_updateTry(
    corto_object o);

/** Update an object.
 * This function emits an ON_UPDATE event and must be called after either 
 * a successful call to corto_updateBegin or corto_updateTry. If the function is
 * called without first calling corto_updateBegin or corto_updateTry the behavior
 * is undefined. The function will unlock the object.
 *
 * This function behaves like corto_define when the object is not yet defined, 
 * in that it defines the object, and may either emit ON_DEFINE or ON_RESUME, 
 * depending on whether a SINK mount has a copy of the object.
 *
 * @param o The object to be updated.
 * @return 0 if success, nonzero if failed.
 * @see corto_updateBegin corto_updateEnd corto_updateTry corto_updateCancel corto_publish
 * @see corto_observe corto_subscribe
 */
CORTO_EXPORT 
int16_t corto_updateEnd(
    corto_object o);

/** Cancel updating an object.
 * This function unlocks the object without any other side-effects. The application
 * is responsible for reversing any changes made to the object.
 *
 * @param o The object for which the update must be cancelled.
 * @return 0 if success, nonzero if failed.
 * @see corto_updateBegin corto_updateEnd corto_updateTry corto_updateCancel corto_publish
 * @see corto_observe corto_subscribe
 */
CORTO_EXPORT 
int16_t corto_updateCancel(
    corto_object o);

/** Invalidate an object.
 * This function emits an ON_INVALIDATE event when a valid object is passed to it.
 * This function is typically used to indicate that an object has gone stale, or
 * that the constructor of the object has failed.
 *
 * This function fails if the current context does not own the object.
 *
 * @param o The object to be invalidated
 * @return 0 if success, nonzero if failed.
 * @see corto_updateBegin corto_updateEnd corto_updateTry corto_updateCancel corto_publish
 * @see corto_observe corto_subscribe
 */
CORTO_EXPORT 
int16_t corto_invalidate(
    corto_object o);

/** Publish event for an object.
 * This function enables emitting events for objects that are not loaded in the
 * RAM store. This allows for efficient routing of events between subscribers
 * without the need to (de)marshall object values.
 *
 * If the object is loaded in the RAM store, a call to corto_publish will demarshall
 * the specified value into the object.
 *
 * The function may only emit "data events", which are ON_DEFINE, 
 * ON_UPDATE, ON_INVALIDATE and ON_DELETE. The other events are reserved for 
 * objects that are loaded in the RAM store.
 *
 * @param event The event to be emitted
 * @param id A string representing the id of the object in the form of 'foo/bar'.
 * @param type A string representing the id of the type as returned by corto_fullpath.
 * @param contentType A string representing the content type (format) of the specified value.
 * @param value A string (or binary value) representing the serialized value of the object.
 * @return 0 if success, nonzero if failed.
 * @see corto_updateBegin corto_updateEnd corto_updateTry corto_updateCancel corto_publish
 * @see corto_observe corto_subscribe
 */
CORTO_EXPORT 
int16_t corto_publish(
    corto_eventMask event,
    char *id,
    char *type,
    char *contentType,
    void *content);

/** Claim an object.
 * This function increases the reference count of an object, which will prevent
 * it from being deallocated.
 *
 * It is usually not needed to call this function manually. When setting a member
 * of a reference type, use the corto_ptr_setref function.
 *
 * @param o The object of which to increase the reference count.
 * @return The reference count of the object after the operation.
 * @see corto_release
 */
CORTO_EXPORT 
int32_t corto_claim(
    corto_object o);

/** Release an object.
 * This function decreases the reference count of an object. When the reference
 * count reaches zero, it will be deallocated.
 *
 * @param o The object of which to increase the reference count.
 * @return The reference count of the object after the operation.
 * @see corto_claim
 */
CORTO_EXPORT 
int32_t corto_release(
    corto_object o);

/* Set/get object attributes for current thread */
CORTO_EXPORT corto_attr corto_setAttr(corto_attr attr);
CORTO_EXPORT corto_attr corto_getAttr(void);

/* Object metadata */
CORTO_EXPORT corto_type corto_typeof(corto_object o);
CORTO_EXPORT int32_t corto_countof(corto_object o);
CORTO_EXPORT corto_state corto_stateof(corto_object o);
CORTO_EXPORT corto_attr corto_attrof(corto_object o);
CORTO_EXPORT bool corto_checkState(corto_object o, corto_state state);
CORTO_EXPORT bool corto_checkAttr(corto_object o, corto_attr attr);
CORTO_EXPORT bool _corto_instanceof(corto_type type, corto_object o);
CORTO_EXPORT bool _corto_instanceofType(corto_type type, corto_type valueType);

/* Object metadata for scoped objects */
CORTO_EXPORT char *corto_idof(corto_object o);
CORTO_EXPORT char *corto_nameof(corto_id str, corto_object o);
CORTO_EXPORT corto_object corto_parentof(corto_object o);
CORTO_EXPORT bool corto_childof(corto_object p, corto_object o);
CORTO_EXPORT uint32_t corto_scopeSize(corto_object o);
CORTO_EXPORT corto_objectseq corto_scopeClaim(corto_object o);
CORTO_EXPORT corto_objectseq corto_scopeClaimWithFilter(corto_object scope, corto_type type, char *id);
CORTO_EXPORT void corto_scopeRelease(corto_objectseq scope);
CORTO_EXPORT int16_t corto_scopeWalk(corto_object o, corto_scopeWalk_cb action, void *userData);

/* Ownership */
CORTO_EXPORT corto_object corto_ownerof(corto_object o);
CORTO_EXPORT bool corto_owned(corto_object o);
/* Set/get owner for thread */
CORTO_EXPORT corto_object corto_setOwner(corto_object owner);
CORTO_EXPORT corto_object corto_getOwner(void);

/* Object path */
CORTO_EXPORT char *corto_fullpath(corto_id str, corto_object o);
CORTO_EXPORT char *corto_fullname(corto_id str, corto_object o);
CORTO_EXPORT char *corto_path(corto_id str, corto_object from, corto_object o, const char* sep);
CORTO_EXPORT char *corto_pathname(corto_id str, corto_object from, corto_object o, const char* sep);
CORTO_EXPORT int32_t corto_pathToArray(char *path, char *elements[], char *sep);
CORTO_EXPORT char *corto_cleanpath(corto_id buffer, char* path);

/* Lookup objects by id */
CORTO_EXPORT corto_object corto_lookup(corto_object scope, char *id);

/* Lookup object by id, assert if not found or if wrong type, does not claim */
CORTO_EXPORT corto_object _corto_lookupAssert(corto_object scope, char *id, corto_type type);

/* Lookup type by id */
CORTO_EXPORT corto_object corto_resolve(corto_object scope, char *id);

/* Lookup objects by id according to custom settings */
typedef enum corto_findKind {
    CORTO_FIND_DEFAULT = 0,
    CORTO_FIND_RESUME = 1
    /* Will be extended with more options */
} corto_findKind;

/* Unstable API */
CORTO_EXPORT corto_object corto_find(corto_object scope, char *id, corto_findKind mode);

/* Iterate over objects matching an expression */
typedef struct corto_selectFluent {
    struct corto_selectFluent (*contentType)(char *contentType);
    struct corto_selectFluent (*limit)(corto_uint64 offset, corto_uint64 limit);
    struct corto_selectFluent (*type)(char *filter);
    struct corto_selectFluent (*instance)(corto_object instance);
    struct corto_selectFluent (*mount)(corto_mount mount);
    struct corto_selectFluent (*fromNow)(void);
    struct corto_selectFluent (*fromTime)(corto_time t);
    struct corto_selectFluent (*fromSample)(corto_uint64 sample);
    struct corto_selectFluent (*toNow)(void);
    struct corto_selectFluent (*toTime)(corto_time t);
    struct corto_selectFluent (*toSample)(corto_uint64 sample);
    struct corto_selectFluent (*forDuration)(corto_time t);
    struct corto_selectFluent (*forDepth)(int64_t depth);
    int16_t ___ (*iter)(corto_resultIter *ret);
    int16_t ___ (*iterObjects)(corto_objectIter *ret); /* Unstable API */
    int64_t ___ (*count)(void);
    int16_t ___ (*subscribe)(corto_resultIter *ret); /* Unstable API */
    int16_t ___ (*unsubscribe)(void); /* Unstable API */
    char *___ (*id)(void); /* Unstable API */
} corto_selectFluent;
CORTO_EXPORT struct corto_selectFluent corto_select(char *scope, char *expr, ...);

/* Observe objects for an observable matching an eventmask */
typedef struct corto_observeFluent {
    struct corto_observeFluent (*disabled)(void);
    struct corto_observeFluent (*dispatcher)(corto_dispatcher dispatcher);
    struct corto_observeFluent (*instance)(corto_object instance);
    struct corto_observeFluent (*type)(char *type);
    corto_observer ___ (*callback)(void (*r)(corto_object, corto_eventMask, corto_object, corto_observer));
} corto_observeFluent;
CORTO_EXPORT struct corto_observeFluent corto_observe(corto_eventMask event, corto_object observable);
CORTO_EXPORT int16_t corto_unobserve(corto_observer observer);

/* Subscribe for notifications matching an expression and eventmask */
typedef struct corto_subscribeFluent {
    struct corto_subscribeFluent (*disabled)(void);
    struct corto_subscribeFluent (*dispatcher)(corto_dispatcher dispatcher);
    struct corto_subscribeFluent (*instance)(corto_object instance);
    struct corto_subscribeFluent (*contentType)(char *contentType);
    struct corto_subscribeFluent (*type)(char *type);
    corto_subscriber ___ (*callback)(void (*r)(corto_object, corto_eventMask, corto_result*, corto_subscriber));
} corto_subscribeFluent;
CORTO_EXPORT struct corto_subscribeFluent corto_subscribe(corto_eventMask mask, char *scope, char *expr, ...);
CORTO_EXPORT int16_t corto_unsubscribe(corto_subscriber subscriber, corto_object instance);

/* Match corto expression */
typedef struct corto_matchProgram_s* corto_matchProgram;
CORTO_EXPORT bool corto_match(char *expr, char *str);
CORTO_EXPORT corto_matchProgram corto_matchProgram_compile(char *expr, bool allowScopes, bool allowSeparators);
CORTO_EXPORT bool corto_matchProgram_run(corto_matchProgram program, char *str);
CORTO_EXPORT void corto_matchProgram_free(corto_matchProgram matcher);
/* Match parent of expression. Returns NULL if no match, or ptr to remainder (for corto_match) */
CORTO_EXPORT char* corto_matchParent(char *parent, char *expr);

/* Serialize object value to contentType */
CORTO_EXPORT char *corto_contentof(corto_id str, char *contentType, corto_object o);
CORTO_EXPORT int16_t corto_fromcontent(corto_object o, char *contentType, char *content, ...);

/* Serialize object to contentType */
CORTO_EXPORT char *corto_object_contentof(corto_id str, char *contentType, corto_object o);
CORTO_EXPORT int16_t corto_object_fromcontent(corto_object *o, char *contentType, char *content, ...);

/* Deprecated */
CORTO_EXPORT corto_object corto_createFromContent(char *contentType, char *content);

/* Object extensions (Object Local Storage) */
CORTO_EXPORT uint8_t corto_olsKey(void(*destructor)(void*));
CORTO_EXPORT void* corto_olsSet(corto_object o, int8_t key, void *data);
CORTO_EXPORT void* corto_olsGet(corto_object o, int8_t key);
/* Thread-safe way to modify OLS data */
CORTO_EXPORT void* corto_olsLockGet(corto_object o, int8_t key);
CORTO_EXPORT void corto_olsUnlockSet(corto_object o, int8_t key, void *value);

/* Read locking */
CORTO_EXPORT int16_t corto_readBegin(corto_object object);
CORTO_EXPORT int16_t corto_readEnd(corto_object object);

/* Write locking */
CORTO_EXPORT int16_t corto_lock(corto_object object);
CORTO_EXPORT int16_t corto_unlock(corto_object object);

CORTO_EXPORT char *corto_str(corto_object object, uint32_t maxLength);
CORTO_EXPORT int16_t corto_fromStr(void *o, char *string);
CORTO_EXPORT int16_t _corto_copy(corto_object *dst, corto_object src);
CORTO_EXPORT corto_equalityKind corto_compare(corto_object o1, corto_object o2);

/* Call base initalizer / constructor / destructor */
CORTO_EXPORT int16_t corto_super_init(corto_object o);
CORTO_EXPORT int16_t corto_super_construct(corto_object o);
CORTO_EXPORT void corto_super_destruct(corto_object o);

/* Security */
CORTO_EXPORT int16_t corto_useradd(char *userId, char *password, char *group, char *home);
CORTO_EXPORT int16_t corto_userdel(char *userId);
CORTO_EXPORT char *corto_login(char *username, char *password);
CORTO_EXPORT void corto_logout(char *token);
CORTO_EXPORT char *corto_authenticate(char *key);
CORTO_EXPORT bool corto_authorized(corto_object object, corto_secure_actionKind access);
CORTO_EXPORT bool corto_authorizedId(char *id, corto_secure_actionKind access);
CORTO_EXPORT bool corto_secured(void);

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
#define corto_copy(dst, src) _corto_copy((corto_object*)dst, src)
#define corto_instanceof(type, o) _corto_instanceof((corto_type)type, o)
#define corto_instanceofType(type, valueType) _corto_instanceofType((corto_type)type, (corto_type)valueType)

#ifdef __cplusplus
}
#endif

#endif /* CORTO_OBJECT_H_ */
