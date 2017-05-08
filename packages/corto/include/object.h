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

/** Create a new scoped object.
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

/** Find or create a new object.
 * Equivalent to calling corto_findOrDeclare + corto_define.
 *
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
 * The object passed to this function must be created with CORTO_ATTR_SCOPED. Any
 * object that is created with declareChild or createChild has this attribute. If
 * an object without CORTO_ATTR_SCOPED is passed to this function the behavior is
 * undefined. 
 *
 * @param o A scoped object for which to obtain the id.
 * @return The object id. The returned string is not owned by the application.
 * @see corto_nameof
 */
CORTO_EXPORT 
char *corto_idof(
    corto_object o);

/** Get the object name.
 * The object passed to this function must be created with CORTO_ATTR_SCOPED. Any
 * object that is created with declareChild or createChild has this attribute. If
 * an object without CORTO_ATTR_SCOPED is passed to this function the behavior is
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
 * @param o A scoped object for which to obtain the name.
 * @return The object name. If str is NULL, the returned string is not owned by the application. Otherwise, str is returned.
 * @see corto_idof
 */
CORTO_EXPORT 
char *corto_nameof(
    corto_id str, 
    corto_object o);

/** Get the parent of an object.
 * The object passed to this function must be created with CORTO_ATTR_SCOPED. Any
 * object that is created with declareChild or createChild has this attribute. If
 * an object without CORTO_ATTR_SCOPED is passed to this function the behavior is
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
 * The objects passed to this function must be created with CORTO_ATTR_SCOPED. Any
 * object that is created with declareChild or createChild has this attribute. If
 * an object without CORTO_ATTR_SCOPED is passed to this function the behavior is
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
 * The objects passed to this function must be created with CORTO_ATTR_SCOPED. Any
 * object that is created with declareChild or createChild has this attribute. If
 * an object without CORTO_ATTR_SCOPED is passed to this function the behavior is
 * undefined.
 *
 * This function must be used with care as it only returns number of objects that
 * are currently loaded in the object store. If there are mounted objects in this
 * scope that are not loaded in the store they will not be counted. To obtain an
 * accurate count, use corto_select().count().
 *
 * @param o A scoped object.
 * @return The number of objects in the scope of the object.
 */
CORTO_EXPORT 
uint32_t corto_scopeSize(
    corto_object o);

/** Returns a sequence with the objects in the current scope.
 * The object passed to this function must be created with CORTO_ATTR_SCOPED. Any
 * object that is created with declareChild or createChild has this attribute. If
 * an object without CORTO_ATTR_SCOPED is passed to this function the behavior is
 * undefined.
 *
 * This function must be used with care as it only returns objects that are 
 * currently loaded in the object store. If there are mounted objects in this
 * scope that are not loaded in the store they will not be returned. To obtain a
 * full list of objects count, use corto_select().iterObjects().
 *
 * @param o A scoped object.
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
 * The object passed to this function must be created with CORTO_ATTR_SCOPED. Any
 * object that is created with declareChild or createChild has this attribute. If
 * an object without CORTO_ATTR_SCOPED is passed to this function the behavior is
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
 * @param o A scoped object.
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
 * 2. If the object owner is not NULL and not an instance of corto/core/mount, the
 * rule 1 applies. This mode can be used to emit notifications from a non-mount
 * instance without an observer for that instance receiving the notification.
 * 3. If the object owner is an instance of corto/core/mount, the mount owns the
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

/** Lookup an object, assert if not found.
 * This function looks up an object and asserts if the object is not found. Use
 * this function only when the specified object is guaranteed to be resolvable.
 * Because the returned object is guaranteed to be alive, the application does
 * not need to invoke corto_release.
 *
 * If an object is found that is not of the specified type, this function will
 * also assert.
 *
 * @param scope The scope in which to lookup the object.
 * @param id An id expression (foo/bar) identifying the object to lookup.
 * @param type The type of the object to lookup.
 * @return The object if found, NULL if not found.
 * @see corto_lookup corto_resolve corto_release
 */
CORTO_EXPORT 
corto_object _corto_lookupAssert(
    corto_object scope, 
    char *id, 
    corto_type type);

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

/* UNSTABLE API */
typedef enum corto_findKind {
    CORTO_FIND_DEFAULT = 0,
    CORTO_FIND_RESUME = 1
    /* Will be extended with more options */
} corto_findKind;
CORTO_EXPORT corto_object corto_find(corto_object scope, char *id, corto_findKind mode);

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

/** Obtain an array with the individual elements of a path.
 * This function splits up a path using the specified separator. An element with
 * at least CORTO_MAX_SCOPE_DEPTH elements must be provided. 
 * 
 * WARNING: This function modifies the input path.
 *
 * @param path The path to be split up.
 * @param elements The result array with the path elements.
 * @param sep The separator used to split up the path.
 * @return The number of elements in the array.
 * @see corto_idof corto_fullname corto_path corto_pathname
 */
CORTO_EXPORT 
int32_t corto_pathToArray(
    char *path, 
    char *elements[], 
    char *sep);

/** Create a canonical version of a path.
 * This function reduces a path to its canonical form by resolving . and .. operators.
 * @param str An id buffer in which to store the id. If NULL, a corto-managed
 * string is returned which may change with subsequent calls to corto_fullpath and 
 * other functions that use the corto stringcache.
 *
 * @param path The input path. Can be the same as buffer.
 * @return The path. If buffer is NULL, the returned string is not owned by the application. Otherwise, buffer is returned.
 * @see corto_idof corto_fullname corto_path corto_pathname
 */
CORTO_EXPORT 
char *corto_cleanpath(
    corto_id buffer, 
    char* path);

typedef struct corto_select_request {
    /** Request results in a specific contentType.
     * @param contentType A MIME identifier identifying a contentType.
     */
    struct corto_select_request (*contentType)(
        char *contentType);

    /** Enable pagination by specifying an offset and limit.
     * @param offset Specifies from which nth object results should be returned.
     * @param limit Specifies the total number of results that should be returned.
     */
    struct corto_select_request (*limit)(
        corto_uint64 offset, 
        corto_uint64 limit);

    /** Filter results by type.
     * @param filter An id expression matching one or more types.
     */
    struct corto_select_request (*type)(
        char *filter);

    /** Filter out results from a specific instance (mount).
     * This is typically useful when using corto_select from a mount, and the
     * mount does not want to invoke itself.
     *
     * @param instance The instance object.
     */
    struct corto_select_request (*instance)(
        corto_object instance);

    /** Only return results for a specific mount.
     * This is typically useful when using corto_select from a mount, and the
     * mount does not want to invoke itself.
     *
     * @param instance The instance object.
     */    
    struct corto_select_request (*mount)(
        corto_mount mount);

    /** Request historical data starting from the current time. */
    struct corto_select_request (*fromNow)(void);

    /** Request historical data starting from fixed timestamp 
     * @param t The timestamp from which to return historical data.
     */
    struct corto_select_request (*fromTime)(
        corto_time t);

    /** Request historical data from a fixed sample id.
     * @param sample Sample id, starting from the beginning of the sequence.
     */
    struct corto_select_request (*fromSample)(
        corto_uint64 sample);

    /** Request historical data until now. */
    struct corto_select_request (*toNow)(void);

    /** Request historical data until a fixed timestamp.
     * @param t The timestamp until which to return historical data.
     */
    struct corto_select_request (*toTime)(corto_time t);

    /** Request historical data until a fixed sample id.
     * @param sample Sample id, starting from the beginning of the sequence.
     */    
    struct corto_select_request (*toSample)(corto_uint64 sample);

    /** Request historical data for a specific time window.
     * @param t The duration of the time window.
     */
    struct corto_select_request (*forDuration)(corto_time t);

    /** Request historical data for a specific number of samples.
     * @param depth The number of samples in the window.
     */
    struct corto_select_request (*forDepth)(int64_t depth);

    /** Return an iterator to the requested results.
     * Results are returned as corto_result instances. A corto_result contains
     * metadata and when a content type is specified, a serialized value of an 
     * object. When using this function, no objects are created.
     *
     * @param iter_out A pointer to an iterator object.
     * @return 0 if success, -1 if failed.
     */
    int16_t ___ (*iter)(corto_resultIter *iter_out);

    /** Return an iterator to the requested objects.
     * This function will return results as anonymous objects. No objects will be
     * created in the object store.
     *
     * @param iter_out A pointer to an iterator object.
     * @return 0 if success, -1 if failed.
     */
    int16_t ___ (*iterObjects)(corto_objectIter *iter_out); /* Unstable API */

    /** Return the number of objects for a query.
     * This function requires a walk over all the returned results to determine
     * the total number of objects. 
     *
     * @return -1 if failed, otherwise the total number of objects.
     */
    int64_t ___ (*count)(void);

    /** Internal API. */
    int16_t ___ (*subscribe)(corto_resultIter *ret); /* Unstable API */
    /** Internal API. */
    int16_t ___ (*unsubscribe)(void); /* Unstable API */
    /** Internal API. */
    char *___ (*id)(void); /* Unstable API */
} corto_select_request;

/** Query for objects.
 * This function performs an operation on objects matching a corto identifier 
 * expression (parent, expr). Selector methods control what kind of information
 * is to be retrieved.
 *
 * The corto_select function is designed to be an API that enables accessing large 
 * datasets with constrained resources. The iterative design of the API allows the
 * corto mount implementations to feed data to the application one object at a time,
 * so that even with large result sets, the memory of an application will not be
 * exhausted. Furthermore the API has native support for pagination, which allows
 * applications to further narrow down results.
 *
 * The results returned by corto_select are in abitrary order, which is a result
 * of the requirement of being able to deal with large datasets. Ordering results
 * would require obtaining a full resultset before anything can be returned to
 * the application, which is not scalable.
 *
 * The performance of corto_select highly depends on the implementation of a mount.
 * The backend provides as much information as possible upfront to the mount about
 * which information is required, which allows a mount to prefetch/cache results. 
 * A mount may choose to implement such optimizations, but this is not enforced.
 *
 * The function employs minimal locking on the object store while an application
 * is iterating over a resultset. Outside of the corto_iter_next and corto_iter_hasNext
 * calls no locks will be held, which enables applications to run corto_select
 * queries concurrently and without disturbing other tasks in an application.
 *
 * @param scope The scope of the request. Query results are relative to the scope.
 * @param expr An expression matching one or more objects [printf-style format specifier].
 */ 
CORTO_EXPORT struct corto_select_request corto_select(char *scope, char *expr, ...);

/* Observe objects for an observable matching an eventmask */
typedef struct corto_observeFluent {
    struct corto_observeFluent (*disabled)(void);
    struct corto_observeFluent (*dispatcher)(corto_dispatcher dispatcher);
    struct corto_observeFluent (*instance)(corto_object instance);
    struct corto_observeFluent (*type)(char *type);
    corto_observer ___ (*callback)(void (*r)(corto_observerEvent*));
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
    corto_subscriber ___ (*callback)(void (*r)(corto_subscriberEvent*));
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
CORTO_EXPORT char *corto_contentof(corto_object o, char *contentType);
CORTO_EXPORT int16_t corto_fromcontent(corto_object o, char *contentType, char *content, ...);

/* Serialize object to contentType */
CORTO_EXPORT char *corto_object_contentof(corto_object o, char *contentType);
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
