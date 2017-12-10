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

/** @file
 * @section object Object API
 * @brief API for the corto object store.
 *
 * Corto objects are application-level entities that populate the corto object
 * store. Application logic is expressed through creating, updating and deleting
 * corto objects. Objects are always allocated on the heap.
 *
 * Every corto object is annotated with a type, which allows for runtime
 * reflection. Typical usecases for reflection are marshalling/demarshalling
 * objects to other formats, or dynamically inspecting the value of an object
 * without having to know its type upfront.
 *
 * Objects can be either anonymous or named. Named objects are identified by a
 * string identifier and can be discovered dynamically in the corto object store.
 * Anonymous objects have no name, and cannot be automatically discovered, but are
 * otherwise the same as named objects. The `corto_declare` and `corto_create`
 * functions create anonymous objects.
 *
 * In addition to a name, named objects also have a parent. Objects in corto are
 * stored in a hierarchy, and any named object can act as a parent for another
 * object. Once created, an object cannot be moved to another parent. The
 * `corto_declareChild` and `corto_createChild` functions create named objects.
 *
 * Objects are reference counted. When there are no more references to an object
 * it is deleted from RAM. The `corto_claim` function increases refcount, and
 * the `corto_release` function decreases refcount. This does not mean the object
 * does not exist anymore as it can still 'live' in another medium, like a
 * database. Objects that are no longer in the store but are still alive are
 * called "suspended objects".
 *
 * Suspended objects can be resumed by doing a lookup for the object id, which
 * will re-insert the object in RAM if it is still available. The `corto_lookup`
 * and `corto_resolve` functions can resume objects.
 *
 * Whenever an object is created, updated or deleted events are emitted. These
 * events can be catched with observers and subscribers. See corto_observe and
 * corto_subscribe for more details.
 */

#ifndef CORTO_OBJECT_H_
#define CORTO_OBJECT_H_

#include <corto/base.h>
#include <corto/vstore/_type.h>
#include <corto/lang/_type.h>
#include <corto/secure/_type.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct corto_contentType_s *corto_contentType;

/* TODO: REMOVE */
CORTO_EXPORT corto_object corto_createFromContent(char *contentType, char *content);

/** Create a new anonymous object.
 * Equivalent to calling corto_declare + corto_define.
 *
 * @param type The type of the object to create.
 * @return The new object, NULL if failed.
 * @see corto_declare corto_declareChild corto_declareOrphan corto_findOrDeclare
 * @see corto_createChild corto_createOrphan corto_findOrCreate
 * @see corto_define corto_delete corto_release
 */
CORTO_EXPORT
corto_object _corto_create(
    corto_type type);

/** Create a new named object.
 * Equivalent to calling corto_declareChild + corto_define.
 *
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
 *
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

/** Declare a new anonymous object.
 * This function returns an object in the DECLARED state, allowing for setting
 * the object value before invoking the type constructor with corto_define. The
 * function fails if the type initializer fails.
 *
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
 * (and should) check the state of the returned object using corto_checkState to
 * determine if it needs to initialize the object. The same thread may declare
 * an object multiple times before it is defined.
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
 * If a named object is deleted, all it's children will be recursively deleted
 * as well, using a depth-first walk.
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
 * @see corto_update_begin corto_update_end corto_update_try corto_update_cancel corto_publish
 * @see corto_observe corto_subscribe
 */
CORTO_EXPORT
int16_t corto_update(
    corto_object o);

/** Start updating an object.
 * This function locks the object for thread-safe updating. No event is emitted
 * yet. This function must be followed up by corto_update_end or corto_update_cancel.
 *
 * This function fails if the current context does not own the object or if the
 * object passed to was not created with ATTR_OBSERVABLE.
 *
 * @param o The object to be updated.
 * @return 0 if success, nonzero if failed.
 * @see corto_update_begin corto_update_end corto_update_try corto_update_cancel corto_publish
 * @see corto_observe corto_subscribe
 */
CORTO_EXPORT
int16_t corto_update_begin(
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
 * @see corto_update_begin corto_update_end corto_update_try corto_update_cancel corto_publish
 * @see corto_observe corto_subscribe
 */
CORTO_EXPORT
int16_t corto_update_try(
    corto_object o);

/** Update an object.
 * This function emits an ON_UPDATE event and must be called after either
 * a successful call to corto_update_begin or corto_update_try. If the function is
 * called without first calling corto_update_begin or corto_update_try the behavior
 * is undefined. The function will unlock the object.
 *
 * This function behaves like corto_define when the object is not yet defined,
 * in that it defines the object, and may either emit ON_DEFINE or ON_RESUME,
 * depending on whether a SINK mount has a copy of the object.
 *
 * @param o The object to be updated.
 * @return 0 if success, nonzero if failed.
 * @see corto_update_begin corto_update_end corto_update_try corto_update_cancel corto_publish
 * @see corto_observe corto_subscribe
 */
CORTO_EXPORT
int16_t corto_update_end(
    corto_object o);

/** Cancel updating an object.
 * This function unlocks the object without any other side-effects. The application
 * is responsible for reversing any changes made to the object.
 *
 * @param o The object for which the update must be cancelled.
 * @return 0 if success, nonzero if failed.
 * @see corto_update_begin corto_update_end corto_update_try corto_update_cancel corto_publish
 * @see corto_observe corto_subscribe
 */
CORTO_EXPORT
int16_t corto_update_cancel(
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
 * @see corto_update_begin corto_update_end corto_update_try corto_update_cancel corto_publish
 * @see corto_observe corto_subscribe
 */
CORTO_EXPORT
int16_t corto_invalidate(
    corto_object o);

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

/** Set object attributes for the current thread.
 * This function sets the attributes of objects that will be created in the
 * current thread. For valid attribute values see the corto/lang/attr type.
 *
 * Attributes were introduced to reduce footprint of corto objects by disabling
 * features that are not used. For example, if an object does not need to be
 * observed, it can be created without the CORTO_ATTR_OBSERVABLE attribute.
 *
 * @param attr A mask containing the attributes for the current thread.
 * @return The previous attribute mask for this thread.
 * @see corto_getAttr corto_attrof corto_checkAttr
 */
CORTO_EXPORT
corto_attr corto_setAttr(
    corto_attr attr);

/** Get the object attributes for the current thread.
 * This function returns the current object attributes that are set for this
 * thread.
 *
 * @return The object attributes for the current thread.
 * @see corto_setAttr corto_attrof corto_checkAttr
 */
CORTO_EXPORT
corto_attr corto_getAttr(void);

/** Get the type of an object.
 * @param o The object for which to obtain the type.
 * @return The object type.
 * @see corto_instanceof corto_instanceofType
 */
CORTO_EXPORT
corto_type corto_typeof(
    corto_object o);

/** Check if object is an instance of a specified type.
 * This function returns true when types exactly match, when o is of a type that
 * is a subtype of type, when o is of a type that implements type, and when o is of
 * target{type}.
 *
 * @param type The type against which to check.
 * @param o The object to check.
 * @return true if o is an instance of type, otherwise false.
 * @see corto_typeof corto_instanceofType
 */
CORTO_EXPORT
bool _corto_instanceof(
    corto_type type,
    corto_object o);

/** Check if objects of a type are an instance of another type.
 * @param type The type against which to check.
 * @param valueType The type to check.
 * @return true if objects of valueType are an instance of type, otherwise false.
 * @see corto_typeof corto_instanceof
 */
CORTO_EXPORT
bool _corto_instanceofType(
    corto_type type,
    corto_type valueType);

/** Obtain the current state mask of the object.
 * Object state changes as an object is declared, defined and ultimately deleted.
 *
 * @param o The object of which to obtain the state.
 * @return The state mask of the current object.
 * @see corto_checkState
 */
CORTO_EXPORT
corto_state corto_stateof(
    corto_object o);

/** Obtain the attribute mask of the object.
 * Object attributes are static after an object is declared.
 *
 * @param o The object of which to obtain the attributes.
 * @return The attribute mask of the current object.
 * @see corto_checkAttr corto_getAttr corto_setAttr
 */
CORTO_EXPORT
corto_attr corto_attrof(
    corto_object o);

/** Check if an object is of a specified state.
 * Object state changes as an object is declared, defined and ultimately deleted.
 *
 * @param o The object for which to check the state.
 * @param state The state to look for.
 * @return true if the object is in the specified state, otherwise false.
 * @see corto_checkState
 */
CORTO_EXPORT
bool corto_checkState(
    corto_object o,
    corto_state state);

/** Check if an object is of a specified attribute.
 * Object attributes are static after an object is declared.
 *
 * @param o The object for which to check the attribute.
 * @param state The attribute to look for.
 * @return true if the object has the specified attribute, otherwise false.
 * @see corto_attrof corto_getAttr corto_setAttr
 */
CORTO_EXPORT
bool corto_checkAttr(
    corto_object o,
    corto_attr attr);

/** Check if an object is an orphan.
 * Orphans are objects that not registered with their parents.
 *
 * @param o The object to check
 * @return true if the object is an orphan.
 * @see isbuiltin corto_checkState corto_checkAttr
 */
CORTO_EXPORT
bool corto_isorphan(
    corto_object o);

/** Check if an object is a builtin object.
 * Builtin objects are part of the corto runtime and are not located on the heap.
 *
 * @param o The object to check
 * @return true if the object is builtin.
 * @see isorphan corto_checkState corto_checkAttr
 */
CORTO_EXPORT
bool corto_isbuiltin(
    corto_object o);

/** The current reference count of the object.
 * This function should be used with caution, as it introduces dependencies on
 * the underlying garbage collection mechanism. A valid use for this function
 * would be in testcases, where it can be used to validate if an specific
 * operation did not introduce any leaks.
 *
 * @param o The object for which to obtain the reference count.
 * @return The reference count of the object.
 */
CORTO_EXPORT
int32_t corto_countof(
    corto_object o);

/** Get the object id.
 * The object passed to this function must be created with CORTO_ATTR_NAMED. Any
 * object that is created with declareChild or createChild has this attribute. If
 * an object without CORTO_ATTR_NAMED is passed to this function the behavior is
 * undefined.
 *
 * @param o A named object for which to obtain the id.
 * @return The object id. The returned string is not owned by the application.
 * @see corto_nameof
 */
CORTO_EXPORT
char *corto_idof(
    corto_object o);

/** Get the object name.
 * The object passed to this function must be created with CORTO_ATTR_NAMED. Any
 * object that is created with declareChild or createChild has this attribute. If
 * an object without CORTO_ATTR_NAMED is passed to this function the behavior is
 * undefined.
 *
 * The object name is the same as the object id, unless the 'nameof' function of
 * a type is overridden, in which case the result of that function is used.
 *
 * Object names are meant to provide a user friendly, though not necessarily
 * unique way to refer to an object.
 *
 * @param str An id buffer in which to store the name. If NULL, a corto-managed
 * string is returned which may change with subsequent calls to corto_nameof and
 * other functions that use the corto stringcache.
 * @param o A named object for which to obtain the name.
 * @return The object name. If str is NULL, the returned string is not owned by the application. Otherwise, str is returned.
 * @see corto_idof
 */
CORTO_EXPORT
char *corto_nameof(
    corto_id str,
    corto_object o);

/** Get the parent of an object.
 * The object passed to this function must be created with CORTO_ATTR_NAMED. Any
 * object that is created with declareChild or createChild has this attribute. If
 * an object without CORTO_ATTR_NAMED is passed to this function the behavior is
 * undefined.
 *
 * This function may return NULL if the corto root object is passed as argument. If
 * @param o The object for which to obtain the id.
 * @return The object id. The returned string is not owned by the application.
 * @see corto_childof
 */
CORTO_EXPORT
corto_object corto_parentof(
    corto_object o);

/** Check if object is a child of the specified parent.
 * The objects passed to this function must be created with CORTO_ATTR_NAMED. Any
 * object that is created with declareChild or createChild has this attribute. If
 * an object without CORTO_ATTR_NAMED is passed to this function the behavior is
 * undefined.
 *
 * @param p The parent object.
 * @param o The child object.
 * @return true if o is a child of p, otherwise false.
 * @see corto_parentof
 */
CORTO_EXPORT
bool corto_childof(
    corto_object p,
    corto_object o);

/** Returns the number of child objects in a scope.
 * The objects passed to this function must be created with CORTO_ATTR_NAMED. Any
 * object that is created with declareChild or createChild has this attribute. If
 * an object without CORTO_ATTR_NAMED is passed to this function the behavior is
 * undefined.
 *
 * This function must be used with care as it only returns number of objects that
 * are currently loaded in the object store. If there are mounted objects in this
 * scope that are not loaded in the store they will not be counted. To obtain an
 * accurate count, use corto_select().count().
 *
 * @param o A named object.
 * @return The number of objects in the scope of the object.
 */
CORTO_EXPORT
uint32_t corto_scopeSize(
    corto_object o);

/** Returns a sequence with the objects in the current scope.
 * The object passed to this function must be created with CORTO_ATTR_NAMED. Any
 * object that is created with declareChild or createChild has this attribute. If
 * an object without CORTO_ATTR_NAMED is passed to this function the behavior is
 * undefined.
 *
 * This function must be used with care as it only returns objects that are
 * currently loaded in the object store. If there are mounted objects in this
 * scope that are not loaded in the store they will not be returned. To obtain a
 * full list of objects count, use corto_select().iterObjects().
 *
 * @param o A named object.
 * @return A sequence with the objects in the scope of the object.
 * @see corto_scopeRelease
 */
CORTO_EXPORT
corto_objectseq corto_scopeClaim(
    corto_object o);

/** Release a sequence obtained by corto_scopeClaim.
 * @param scope A sequence obtained by corto_scopeClaim.
 * @see corto_scopeClaim
 */
CORTO_EXPORT
void corto_scopeRelease(
    corto_objectseq scope);

/** Invoke a callback for each object in a scope.
 * The object passed to this function must be created with CORTO_ATTR_NAMED. Any
 * object that is created with declareChild or createChild has this attribute. If
 * an object without CORTO_ATTR_NAMED is passed to this function the behavior is
 * undefined.
 *
 * Usage of this function is generally NOT recommended as it locks the scope
 * which is a very intrusive operation. The lock is still being held when the
 * action is called, so care must be taken not to introduce any deadlocks while
 * in the action.
 *
 * Use this function only for fast, low-level operations. For all other operations
 * that need to walk a scope, use the safer corto_scopeClaim and corto_scopeRelease.
 *
 * @param o A named object.
 * @return A sequence with the objects in the scope of the object.
 * @see corto_scopeClaim corto_scopeRelease
 */
CORTO_EXPORT
int16_t corto_scopeWalk(
    corto_object o,
    corto_scopeWalk_cb action,
    void *userData);

/** Returns the owner for an object.
 * Only objects created with CORTO_ATTR_PERSISTENT can explicitly set an owner. If
 * the object is not PERSISTENT and is an orphan (created with either corto_declareOrphan
 * or corto_createOrphan) the function will obtain the owner of the parent. In
 * all other scenarios the function will return NULL.
 *
 * @param o A valid object.
 * @return The owner of the object.
 * @see corto_owned corto_setOwner corto_getOwner
 */
CORTO_EXPORT
corto_object corto_ownerof(
    corto_object o);

/** Check if object is owned by current thread.
 * Corto uses this function to check if a thread is allowed to change an object
 * through corto_update or corto_delete functions. The rules for ownership are
 * as follows:
 *
 * 1. If the object owner is NULL, the object is owned by the application. A SOURCE
 * mount will not be able to modify the object.
 * 2. If the object owner is not NULL and not an instance of corto/vstore/mount, the
 * rule 1 applies. This mode can be used to emit notifications from a non-mount
 * instance without an observer for that instance receiving the notification.
 * 3. If the object owner is an instance of corto/vstore/mount, the mount owns the
 * object. If the mount is a SINK, it shares ownership with the application. If
 * the mount is a SOURCE, only that mount will be able to change the object.
 *
 * The owner is determined as specified by corto_ownerof.
 *
 * @param o A valid object.
 * @return The owner of the object.
 * @see corto_owned corto_setOwner corto_getOwner
 */
CORTO_EXPORT
bool corto_owned(
    corto_object o);

/** Set the owner for the current thread.
 * @param owner A valid object.
 * @return The previous owner of the thread.
 * @see corto_ownerof corto_owned corto_getOwner
 */
CORTO_EXPORT
corto_object corto_setOwner(
    corto_object owner);

/** Get the owner for the current thread.
 * @return The owner of the current thread.
 * @see corto_ownerof corto_owned corto_setOwner
 */
CORTO_EXPORT
corto_object corto_getOwner(void);

/** Lookup an object.
 * This function looks up an object and obtains a reference to it. If the object
 * is not loaded in the store but is provided by a mount, it will be resumed from
 * the mount into the store. After the object is no longer needed, an application
 * should call corto_release.
 *
 * corto_lookup can be used to find overloaded functions by specifying an
 * parameter list between parentheses that contains the required types. For example,
 * to find a function called add with two int32 parameters, 'add(int32,int32)'
 * can be specified in id.
 *
 * The following operators can be used in the parameter list:
 * <type>& - The requested argument is a reference.
 * <type>&& - The offered argument must be a reference.
 * null - The requested argument is either a reference or a string (null value).
 * ? - The type is unknown.
 *
 * @param scope The scope in which to lookup the object.
 * @param id An id expression (foo/bar) identifying the object to lookup.
 * @return The object if found, NULL if not found.
 * @see corto_lookupAssert corto_resolve corto_release
 */
CORTO_EXPORT
corto_object corto_lookup(
    corto_object scope,
    char *id);

/** Resolve an object.
 * This function is similar to corto_lookup, but follows a set of rules that is
 * used to lookup types. Note however that corto_resolve can be used to lookup any
 * object, not just types.
 *
 * The reason that types use a different set of lookup rules is to enable short
 * identifiers for builtin types (int32, struct, class, etc) and to types / packages
 * in the corto package. Because these are frequently used, using an optimized
 * set of rules will reduce footprint of type identifiers, which can significantly
 * impact memory usage and bandwidth usage that rely on exchange of type information.
 *
 * The rules of corto_resolve are:
 * 1. If the identifier starts with an '/', lookup in root and return result.
 * 2. If not, look for the identifier in corto/lang.
 * 3. If not found, look for the identifier in the specified scope.
 * 4. If not found, look for the identifier in the parent of the current scope [repeat]
 * 5. If not found, look for the identifier in /corto.
 *
 * corto_resolve will never look twice in a path, so if scope is corto/lang, the
 * function will only look in corto/lang once.
 *
 * If the id expression contains {}, corto_resolve will create an anonymous object
 * by deserializing the contents within {} according to the rules of the corto
 * string format.
 *
 * @param scope The scope in which to lookup the object.
 * @param id An id expression (foo/bar) identifying the object to lookup.
 * @return The object if found, NULL if not found.
 * @see corto_lookup corto_lookupAssert corto_release
 */
CORTO_EXPORT
corto_object corto_resolve(
    corto_object scope,
    char *id);

/** Obtain a full path identifier to an object.
 * This function returns the shortest path that will lead to resolving the object
 * using a corto_resolve where the root is specified as scope.
 *
 * In practice this means that for objects in corto/lang it will only return the
 * object id (int32) while for all other objects the function will a forward slash ('/')
 * separated list of ids as obtained by corto_idof (/grandparent/parent/object).
 * @param str An id buffer in which to store the id. If NULL, a corto-managed
 * string is returned which may change with subsequent calls to corto_fullpath and
 * other functions that use the corto stringcache.
 *
 * @param o The object for which to obtain the id.
 * @return The full path. If str is NULL, the returned string is not owned by the application. Otherwise, str is returned.
 * @see corto_idof corto_fullname corto_path corto_pathname
 */
CORTO_EXPORT
char *corto_fullpath(
    corto_id str,
    corto_object o);

/** Obtain a full path identifier to an object using corto_nameof.
 * This function is equivalent to corto_fullpath, but uses corto_nameof instead
 * of corto_idof.
 *
 * @param o The object for which to obtain the id.
 * @return The full path. If str is NULL, the returned string is not owned by the application. Otherwise, str is returned.
 * @see corto_idof corto_fullpath corto_path corto_pathname
 */
CORTO_EXPORT
char *corto_fullname(
    corto_id str,
    corto_object o);

/** Obtain a relative path identifier to an object.
 * This function returns the shortest path from the specified from object to the
 * to object, separated by sep. If to is a parent of from, this function will insert
 * the appropriate number of '..' operators. This function uses corto_idof to determine
 * the object ids.
 *
 * The result of this function can be used with corto_lookup to lookup the to object,
 * where from is specifed as scope and result as id.
 *
 * If NULL is specified for from, an initial forward slash will be added to the
 * resulting path. If root_o is specified for from, no initial slash will be added
 * to the resulting path.
 * @param str An id buffer in which to store the id. If NULL, a corto-managed
 * string is returned which may change with subsequent calls to corto_fullpath and
 * other functions that use the corto stringcache.
 *
 * @param from The object from the path should be offset.
 * @param o The object to which to generate the path.
 * @param sep The path separator.
 * @return The path. If str is NULL, the returned string is not owned by the application. Otherwise, str is returned.
 * @see corto_idof corto_fullname corto_path corto_pathname
 */
CORTO_EXPORT
char *corto_path(
    corto_id str,
    corto_object from,
    corto_object to,
    const char* sep);

/** Obtain a relative path identifier to an object.
 * This function is equivalent to corto_path, but uses corto_nameof instead of
 * corto_idof.
 * @param str An id buffer in which to store the id. If NULL, a corto-managed
 * string is returned which may change with subsequent calls to corto_fullpath and
 * other functions that use the corto stringcache.
 *
 * @param from The object from the path should be offset.
 * @param o The object to which to generate the path.
 * @param sep The path separator.
 * @return The path. If str is NULL, the returned string is not owned by the application. Otherwise, str is returned.
 * @see corto_idof corto_fullname corto_path corto_pathname
 */
CORTO_EXPORT
char *corto_pathname(
    corto_id str,
    corto_object from,
    corto_object o,
    const char* sep);

/* Observe objects for an observable matching an eventmask */
typedef struct corto_observe__fluent {
    /** Create disabled observer.
     * Disabled observers allow an application to make modifications to the
     * observer mask or observable, and to observe multiple objects using
     * `corto_observer_observe`.
     */
    struct corto_observe__fluent (*disabled)(void);

    /** Provide dispatcher for observer.
     * Dispatchers intercept events before they are delivered to an observer
     * callback, which enables applications to implement custom event handlers.
     * A common usecase for this is to forward events to a worker thread.
     *
     * @param dispatcher A dispatcher object.
     */
    struct corto_observe__fluent (*dispatcher)(
        corto_dispatcher dispatcher);

    /** Specify an instance.
     * Instances are passed to observer callbacks. They are typically used to pass
     * the `this` variable when an observer is associated with a class.
     *
     * @param instance A corto object.
     */
    struct corto_observe__fluent (*instance)(
        corto_object instance);

    /** Filter objects by type.
     * The observer will only trigger on objects of the specified type.
     *
     * @param type A valid corto type identifier.
     */
    struct corto_observe__fluent (*type)(
        char *type);

    /** Specify callback, create observer.
     * Provide a callback function that is invoked when a matching event occurs.
     * This function returns a new observer based on the specified parameters.
     *
     * @param callback An observer callback function.
     */
    corto_observer ___ (*callback)(
        void (*r)(corto_observerEvent*));
} corto_observe__fluent;

/** Create an observer.
 * Observers enable an application to listen for events from the object store, such
 * as objects that are being created, updated or deleted. Observers can observe
 * a single object, an object scope or a subtree of objects. `corto_observe`
 * accepts a parameter `event` of the `corto_eventMask` type, which has the
 * following values:
 *
@verbatim
Flag | Value | Kind | Description
-----|-------|------|------------
CORTO_DECLARE    | 0x1    | infra | Observe objects being forward declared.
CORTO_DEFINE     | 0x2    | data  | Observe objects being defined.
CORTO_DELETE     | 0x4    | data  | Observe objects being deleted.
CORTO_INVALIDATE | 0x8    | data  | Observe objects being invalidated.
CORTO_UPDATE     | 0x10   | data  | Observe objects being updated.
CORTO_RESUME     | 0x20   | infra | Observe objects being resumed.
CORTO_SUSPEND    | 0x40   | infra | Observe objects being suspended.
CORTO_ON_SELF       | 0x80   | scope | Observe a single object.
CORTO_ON_SCOPE      | 0x100  | scope | Observe children of an object.
CORTO_ON_TREE       | 0x200  | scope | Observe children of an object recursively.
CORTO_ON_VALUE      | 0x400  | async | Observe value of an object (requires lock).
CORTO_ON_METAVALUE  | 0x800  | async | Observe metavalue of an object.
CORTO_ON_ANY        | 0xffff | any   | Observe all notifications.
@endverbatim
 *
 * The flag kinds have the following meaning:
 *
@verbatim
Kind  | Description
------|------------
infra | Inform application about (meta) data in the RAM object store.
data  | Inform application about data (CrUD) events.
scope | Set the scope of a mask.
async | Set whether the mask requires an object to be locked.
any   | Enable all flags.
@endverbatim
 *
 * The functionality of corto_observe is further extended by fluent methods. See
 * [corto_observe fluent methods](corto_observe_fluent_methods)). A call to
 * corto_observe must always finish with the `callback` fluent method, which
 * creates the observer and accepts a callback that will be invoked when a matching
 * notification triggers.
 *
 * Observers provide a very fast mechanism for delivering events. The
 * tradeoff is that for an observer to work, objects must be stored in RAM,
 * which is fine if you don't observe millions of objects at the same time.
 *
 * If you want to observe big datasets, check out corto_subscribe which offers
 * equivalent functionality, but does not require objects to be stored in RAM.
 *
 * @param event A mask that specifies the events to observe.
 * @param observable The object to observe.
 */
CORTO_EXPORT
struct corto_observe__fluent corto_observe(
    corto_eventMask event,
    corto_object observable);

/** Delete an observer.
 * No more events will be delivered to the callback after this function is
 * called. Note that the observer object will not be deallocated if there are
 * references to the object.
 *
 * When there are still events in flight when this function is called (something
 * that can happen when a dispatcher is pushing events to another thread) the
 * application can prevent delivery of the event by checking the state of the
 * observer object, which is part of the `corto_observerEvent` instance, by doing:
 *
@verbatim
```c
void myDispatcher_post(corto_observerEvent *e) {
    if (!corto_checkState(e->observer, CORTO_DELETED)) {
        corto_event_handle(e);
    } else {
        // Do nothing
    }
}
```
@endverbatim
 *
 * @param observer An observer object.
 * @return 0 if success, -1 if failed.
 */
CORTO_EXPORT
int16_t corto_unobserve(
    corto_observer observer);

/** Obtain handle to a content type.
 *
 * This function provides a high(er) performance alternative to looking up
 * content types by string, by returning a handle to a contentType that can be
 * reused.
 *
 * UNSTABLE API
 */
CORTO_EXPORT
corto_contentType corto_load_contentType(
    corto_string contentType);

typedef uint32_t corto_kind;
    #define CORTO_DO_DECLARE (0x1)
    #define CORTO_DO_RECURSIVE_DECLARE (0x3)
    #define CORTO_DO_DEFINE (0x4)
    #define CORTO_DO_UPDATE (0x8)
    #define CORTO_DO_ORPHAN (0x10)
    #define CORTO_DO_RESUME (0x20)
    #define CORTO_DO_FORCE_TYPE (0x40)
    #define CORTO_DO_LOOKUP_TYPE (0x80)
    #define CORTO_DO_ASSERT_SUCCESS (0x100)

/** Function that provides low-level access to the corto store.
 *
 * UNSTABLE API
 *
 * When applications require more flexibility than what is provided by the
 * regular API, they can use the corto() function.
 */
CORTO_EXPORT
corto_object _corto(
    corto_object parent,
    const char *id,
    corto_type type,
    corto_object ref,
    corto_contentType contentType,
    void *value,
    corto_attr attrs,
    corto_kind kind);

/* Serialize object value to contentType */
CORTO_EXPORT
char *corto_contentof(
    corto_object o,
    char *contentType);

CORTO_EXPORT
int16_t corto_fromcontent(
    corto_object o,
    char *contentType,
    char *content, ...);

/* Serialize object to contentType */
CORTO_EXPORT
char *corto_object_contentof(
    corto_object o,
    char *contentType);

CORTO_EXPORT
int16_t corto_object_fromcontent(
    corto_object *o,
    char *contentType,
    char *content, ...);

/* Read locking */
CORTO_EXPORT int16_t corto_read_begin(corto_object object);
CORTO_EXPORT int16_t corto_read_end(corto_object object);

/* Write locking */
CORTO_EXPORT int16_t corto_lock(corto_object object);
CORTO_EXPORT int16_t corto_unlock(corto_object object);

CORTO_EXPORT char *corto_str(corto_object object, uint32_t maxLength);
CORTO_EXPORT int16_t corto_fromStr(void *o, char *string);
CORTO_EXPORT int16_t _corto_copy(corto_object *dst, corto_object src);
CORTO_EXPORT corto_equalityKind corto_compare(corto_object o1, corto_object o2);

/* Call base initalizer / constructor / destructor */
CORTO_EXPORT int16_t corto_super_init(corto_object o);
CORTO_EXPORT int16_t corto_super_deinit(corto_object o);
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
#define corto_declare(type) _corto_declare(corto_type(type))
#define corto_declareChild(parent, name, type) _corto_declareChild(parent, name, corto_type(type))
#define corto_copy(dst, src) _corto_copy((corto_object*)dst, src)
#define corto_instanceof(type, o) _corto_instanceof((corto_type)type, o)
#define corto_instanceofType(type, valueType) _corto_instanceofType((corto_type)type, (corto_type)valueType)
#define corto(parent, id, type, ref, contentType, value, attrs, kind)\
    _corto(parent, id, corto_type(type), ref, contentType, value, attrs, kind)

/* Backwards compatibility macro's */
#define corto_updateBegin corto_update_begin
#define corto_updateTry corto_update_try
#define corto_updateCancel corto_update_cancel
#define corto_updateEnd corto_update_end

/* Overload functions */

/* Parameter kinds */
#define CORTO_PARAMETER_REFERENCE          (1)
#define CORTO_PARAMETER_FORCEREFERENCE     (2)
#define CORTO_PARAMETER_WILDCARD           (4)
#define CORTO_PARAMETER_NULL               (8)
#define CORTO_PARAMETER_IN                 (16)
#define CORTO_PARAMETER_OUT                (32)

/* Special distance values for corto_overload */
#define CORTO_OVERLOAD_ERROR               (-1)
#define CORTO_OVERLOAD_NOMATCH             (-2)
#define CORTO_OVERLOAD_NOMATCH_OVERLOAD    (-3)

/* Calculate the distance between a function and a request signature */
CORTO_EXPORT int16_t corto_overload(corto_object object, char* name, int32_t* distance);

/* Obtain information from signature.
 *   Signatures can be of the following form:
 *     name(type name,type name)
 *     name(type,type)
 *     name --> Only allowed for non-overloaded functions
 *
 *   No extra whitespaces are allowed.
 */
CORTO_EXPORT int32_t corto_signatureName(char* signature, corto_id buffer);
CORTO_EXPORT int32_t corto_signatureParamCount(char* signature);
CORTO_EXPORT int32_t corto_signatureParamName(char* signature, uint32_t id, corto_id buffer);
CORTO_EXPORT int32_t corto_signatureParamType(char* signature, uint32_t id, corto_id buffer, int* reference);

/* Create request signature */
CORTO_EXPORT char* corto_signatureOpen(char* name);
CORTO_EXPORT char* corto_signatureAdd(char* sig, corto_type type, int flags);
CORTO_EXPORT char* corto_signatureAddWildcard(char* sig, bool isReference);
CORTO_EXPORT char* corto_signatureClose(char* sig);

/* Obtain signature from object */
CORTO_EXPORT char* corto_signature(corto_object o, corto_id buffer);

/* Find a function that matches a signature */
CORTO_EXPORT corto_object corto_lookupFunction(corto_object scope, char* requested, int32_t *d, int32_t *diff);
CORTO_EXPORT corto_object *corto_lookupFunctionFromSequence(corto_objectseq scopeContents, char* requested, int32_t* d, int32_t *diff);

#ifdef __cplusplus
}
#endif

#endif /* CORTO_OBJECT_H_ */
