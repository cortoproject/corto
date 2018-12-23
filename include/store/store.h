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
  * @section store In-memory Store
  * @brief Access and populate the in-memory store.
  *
  * The in-memory store is a thread-safe, high-performance hierarchical object store that is
  * designed to store the current state of an application. The store implements
  * familiar OOP concepts like inheritance and polymorphism, alongside with
  * support for collections, composite and primitive types to provide a
  * convenient environment for expressing application logic.
  *
  * Once objects are in the store, they can be discovered and introspected. This
  * enables connecting generic components to the store, like for example a REST
  * API, that automatically provides access to the contents of the store.
  *
  * The object store provides a simple but powerful security framework for
  * restricting access to objects. The security framework is deeply embedded
  * into the core, thus decreasing the performance penalty to a minimum.
  *
  * All objects are strongly typed, meaning their types can't change after they
  * are created, although dynamic programming is supported by the `any` type.
  * Type information is stored in the in-memory store alongside regular objects.
  * This enables using the regular store APIs to create and query the store for
  * metadata.
  *
  * The in-memory store provides refcounting-based memory management. To
  * maintain its realtime characteristics, the store will not attempt to detect
  * reference-cycles in realtime. It is up to the application to ensure that
  * non-persistent objects do not contain cycles.
  *
  * Objects can be updated and observed. Every lifecycle event triggers a
  * notification that can be catched by an observer (or subscriber, see vstore).
  * Creating, updating and deleting objects all trigger notifications.
  * Applications can subscribe for a single object, an object scope (branch)
  * or a (sub)tree of objects.
  *
  * The in-memory store interacts with the virtual store when lifecycle events
  * take place. When the value of an object updates, it will be synchronized
  * with the virtual store. When an object is created or deleted, it will also
  * be created or deleted in the virtual store.
  *
  * Corto makes an important distinction between deleting an object and no
  * longer having references to an object. When the last reference to an object
  * is removed, an object may be removed from the in-memory store to conserve
  * RAM, but it will still be in the virtual store. A consecutive lookup of the
  * object will reinsert it into the in-memory store.
  *
  * Objects in the store are first declared, then defined. Between declaring and
  * defining an application has the opportunity to set the initial object value.
  * This ensures that when observers receive a DEFINE notification, the object
  * will be set to a valid value. This also allows an application to forward-
  * declare objects, which enables declaratively creating object cycles.
  *
  * When defining an object, the virtual store is queried for the last value of
  * the object. This is also referred to as "resuming" an object. The initial
  * value assigned by the application inbetween declaring and defining the
  * object may be overwritten when the vstore has a previous state of the
  * object. This enables transparent persisting & retrieving of objects.
  *
  * Applications may use the `corto_create` function to create an object with
  * default values. The `corto_create` function is essentially a convenience
  * wrapper around `corto_declare` and `corto_define`. When an object is defined
  * it acquires the `VALID` object state, indicating that the value of the object
  * may be interpreted for application logic.
  *
  * Multiple threads may attempt to set the initial value of an object. When
  * the same object is declared by multiple threads, `corto_declare` ensures
  * that only one thread will see the object in a not-`VALID` state. While the
  * object is undefined, `corto_declare` will block for the other threads, until
  * the thread that received the non-`VALID` object defines the object.
  *
  * When changing the value of an object, an application must use
  * `corto_update_begin` and `corto_update_end`, which write-locks an object.
  * When calling `corto_update_end` an `UPDATE` notification is sent to all
  * observers of the object.
  *
  * The store provides lifecycle hooks for objects, which are callbacks defined
  * on the type of an object that provide more control to an object over its
  * lifecycle. An example of a hook is the `construct` callback, which is invoked
  * when an object is defined. Another hook is the `validate` hook, which allows
  * the object to verify if a new object value is valid.
  *
  * Applications can define functions and methods in the store, which can be
  * implemented in multiple languages. The store provides an APO (invoke.h) for
  * registering language bindings, which allows to insert custom logic when a
  * function object is invoked. This enables components written in multiple
  * languages to interact with each other in a single process, which can for
  * example be utilized to import Lua or Python scripts, whilst abstracting from
  * the language they are written in. By default store functions are implemented
  * in C. The store uses libffi for dynamically invoking C functions.
  */

#ifndef CORTO_STORE_H
#define CORTO_STORE_H

#include "invoke.h"
#include "ptr.h"
#include "time.h"
#include "field.h"
#include "value.h"
#include "rw.h"
#include "expr.h"
#include "entityadmin.h"
#include "walk.h"
#include "reflection.h"
#include "security.h"

#include "string_ser.h"
#include "fmt.h"

#ifdef __cplusplus
extern "C" {
#endif

CORTO_EXPORT extern corto_object data_o;
CORTO_EXPORT extern corto_object config_o;
CORTO_EXPORT extern corto_object home_o;

typedef int (*corto_scope_walk_cb)(corto_object o, void* userData);

/* -- LIFECYCLE API -- */


/** Create a new named object.
 * Equivalent to calling corto_declare + corto_define.
 *
 * @param parent The parent for the new object.
 * @param id The object id. If NULL, a random unique id is generated. A name may contain
 *     multiple elements, separated by the '/' character. If one or more elements
 *     do not yet exist, they are created with the specified type.
 * @param type The type of the object to create.
 * @return The new object, NULL if failed.
 * @see corto_declare corto_define corto_delete
 */
CORTO_EXPORT
corto_object _corto_create(
    corto_object parent,
    const char *id,
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
 * an DECLARE event is emitted.
 *
 * This function will block if there is another thread that has declared, but not
 * defined the same object. Once the other thread defines the object, the function
 * will unblock, and return an object in the DEFINED state. The calling thread can
 * (and should) check the state of the returned object using corto_check_state to
 * determine if it needs to initialize the object. The same thread may declare
 * an object multiple times before it is defined.
 *
 * @param parent The parent for the new object.
 * @param id The object id. If NULL, a random unique id is generated. A name may contain
 *     multiple elements, separated by the '/' character. If one or more elements
 *     do not yet exist, they are created with the specified type.
 * @param type The type of the object to create.
 * @return The new object, NULL if failed.
 * @see corto_create corto_define corto_delete
 */
CORTO_EXPORT
corto_object _corto_declare(
    corto_object parent,
    const char *id,
    corto_type type);

/** Define an object.
 * This function changes the state of an object to DEFINED. When an object is
 * defined, the type constructor is invoked. If successful, an DEFINE event is
 * emitted. The DEFINE event indicates the moment when the value
 * of an object is ready to be interpreted by contexts other than the one where
 * the object was being created.
 *
 * This function may emit an RESUME event instead of DEFINE if a SINK mount
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
 * @see corto_declare corto_create corto_delete
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
 * @see corto_declare corto_create corto_define
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
 * @see corto_update_begin corto_update_end corto_update_cancel corto_observe
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
 * @see corto_update corto_update_end corto_update_cancel corto_observe
 */
CORTO_EXPORT
int16_t corto_update_begin(
    corto_object o);

/** Update an object.
 * This function emits an UPDATE event and must be called after either
 * a successful call to corto_update_begin or corto_update_try. If the function is
 * called without first calling corto_update_begin or corto_update_try the behavior
 * is undefined. The function will unlock the object.
 *
 * This function behaves like corto_define when the object is not yet defined,
 * in that it defines the object, and may either emit DEFINE or RESUME,
 * depending on whether a SINK mount has a copy of the object.
 *
 * @param o The object to be updated.
 * @return 0 if success, nonzero if failed.
 * @see corto_update_begin
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
 * @see corto_update_begin
 */
CORTO_EXPORT
int16_t corto_update_cancel(
    corto_object o);

/** Invalidate an object.
 * This function emits an INVALIDATE event when a valid object is passed to it.
 * This function is typically used to indicate that an object has gone stale, or
 * that the constructor of the object has failed.
 *
 * This function fails if the current context does not own the object.
 *
 * @param o The object to be invalidated
 * @return 0 if success, nonzero if failed.
 * @see corto_define corto_update
 */
CORTO_EXPORT
int16_t corto_invalidate(
    corto_object o);

#define CORTO_LOOKUP (0) /* Lookup is the default action */
/* Conveniently reuse constants from corto_eventMask
#define CORTO_DECLARE (0x1)
#define CORTO_DEFINE (0x2)
#define CORTO_DELETE (0x4) -> not supported in corto(...)
#define CORTO_INVALIDATE (0x8) -> not supported in corto(...)
#define CORTO_UPDATE (0x10)
#define CORTO_RESUME (0x20)
#define CORTO_SUSPEND (0x40) -> not supported in corto(...) */
#define CORTO_RECURSIVE_DECLARE (0x81)
#define CORTO_ORPHAN (0x100)
#define CORTO_FORCE_TYPE (0x200)
#define CORTO_LOOKUP_TYPE (0x400)
#define CORTO_ASSERT_SUCCESS (0x800)
#define CORTO_UNSECURED (0x10000)

struct corto_action {
    corto_object parent;
    const char *id;
    corto_object type; /* Use corto_object to prevent cast- checked @ runtime */
    corto_object object;
    corto_fmt fmt;
    void const *value;
    corto_attr attrs;
    corto_object source;
};

#define corto(action, ...) _corto(action, (struct corto_action)__VA_ARGS__)

CORTO_EXPORT
corto_object _corto(
    int action,
    struct corto_action params);


/* -- MEMORY MANAGEMENT -- */


/** Claim an object.
 * This function increases the reference count of an object, which will prevent
 * it from being deallocated.
 *
 * It is usually not needed to call this function manually. When setting a member
 * of a reference type, use the corto_set_ref function.
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


/* -- REFLECTION -- */




/* STORE LOOKUP */


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
 * @see corto_resolve
 */
CORTO_EXPORT
corto_object corto_lookup(
    corto_object scope,
    const char *id);

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
 * @see corto_lookup
 */
CORTO_EXPORT
corto_object corto_resolve(
    corto_object scope,
    const char *id);


/* -- NOTIFICATIONS -- */


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
        void (*r)(corto_observer_event*));
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
 * @see corto_unobserve corto_update corto_update_begin
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
 * observer object, which is part of the `corto_observer_event` instance, by doing:
 *
@verbatim
```c
void myDispatcher_post(corto_observer_event *e) {
    if (!corto_check_state(e->observer, CORTO_DELETED)) {
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
 * @see corto_observe
 */
CORTO_EXPORT
int16_t corto_unobserve(
    corto_observer observer);


/* -- SERIALIZATION -- */


/* -- LOCKING -- */


/** Read-lock object.
 *
 * This guarantees that the object will not be modified while the application
 * holds the readlock. Multiple threads may obtain a readlock at the same time.
 *
 * @param o The object to readlock.
 * @return 0 if success, non-zero if failed.
 * @see corto_read_end corto_lock
 */
CORTO_EXPORT
int16_t corto_read_begin(
    corto_object o);

/** Release readlock.
 *
 * Release lock on an object previously locked by corto_read_begin.
 *
 * @param o The object to unlock.
 * @return 0 if success, non-zero if failed.
 * @see corto_read_begin
 */
CORTO_EXPORT
int16_t corto_read_end(
    corto_object o);

/** Write-lock object.
 *
 * This guarantees that the object will not be read while the application
 * holds the writelock, and that no other threads are modifying the object. Only
 * one thread may hold a writelock at the same time.
 *
 * @param o The object to readlock.
 * @return 0 if success, non-zero if failed.
 * @see corto_unlock corto_read_begin
 */
CORTO_EXPORT
int16_t corto_lock(
    corto_object o);

/** Release writelock.
 *
 * Release lock on an object previously locked by corto_write_begin.
 *
 * @param o The object to unlock.
 * @return 0 if success, non-zero if failed.
 * @see corto_lock
 */
CORTO_EXPORT
int16_t corto_unlock(
    corto_object o);


/* -- THREAD-SPECIFIC CONFIGURATION -- */


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
 * @see corto_get_attr corto_attrof corto_check_attr
 */
CORTO_EXPORT
corto_attr corto_set_attr(
    corto_attr attr);

/** Get the object attributes for the current thread.
 * This function returns the current object attributes that are set for this
 * thread.
 *
 * @return The object attributes for the current thread.
 * @see corto_set_attr corto_attrof corto_check_attr
 */
CORTO_EXPORT
corto_attr corto_get_attr(void);

/** Set the source for the current thread.
 * @param source A valid object.
 * @return The previous source of the thread.
 * @see corto_sourceof corto_owned corto_get_source
 */
CORTO_EXPORT
corto_object corto_set_source(
    corto_object source);

/** Get the source for the current thread.
 * @return The source of the current thread.
 * @see corto_sourceof corto_owned corto_set_source
 */
CORTO_EXPORT
corto_object corto_get_source(void);


/* -- UTILITY FUNCTIONS -- */

/** Deep-copy value of source object to destination object.
 * The function accepts a pointer to an object reference. If the pointer points
 * to a NULL value, the function will create a new object.
 *
 * If the pointer contains a reference to an object, the function will verify if
 * the type of the destination object is compatible with the source object. If
 * it is not compatible, the function will fail.
 *
 * @param dst A pointer to the destination object.
 * @param src The source object.
 * @return 0 if success, non-zero if failed.
 */
CORTO_EXPORT
int16_t _corto_copy(
    corto_object *dst,
    corto_object src);

/** Compare value of two objects.
 * This function can be used to perform ordering on objects, as it will return
 * whether objects are lesser, equal or larger than the other object.
 *
 * @param o1 The object to compare.
 * @param o2 The object to compare with.
 * @return 0 if equal, 1 if o1 is larger than o2, -1 if o1 is smaller than o2.
 */
CORTO_EXPORT
int corto_compare(
    corto_object o1,
    corto_object o2);

/** Returns the number of child objects in a scope.
 * The objects passed to this function must be created with CORTO_ATTR_NAMED. If
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
uint32_t corto_scope_size(
    corto_object o);

/** Returns a sequence with the objects in the current scope.
 * The object passed to this function must be created with CORTO_ATTR_NAMED. If
 * an object without CORTO_ATTR_NAMED is passed to this function the behavior is
 * undefined.
 *
 * This function must be used with care as it only returns objects that are
 * currently loaded in the object store. If there are mounted objects in this
 * scope that are not loaded in the store they will not be returned. To obtain a
 * full list of objects count, use corto_select().iter_objects().
 *
 * @param o A named object.
 * @return A sequence with the objects in the scope of the object.
 * @see corto_scope_release
 */
CORTO_EXPORT
corto_objectseq corto_scope_claim(
    corto_object o);

/** Release a sequence obtained by corto_scope_claim.
 * @param scope A sequence obtained by corto_scope_claim.
 * @see corto_scope_claim
 */
CORTO_EXPORT
void corto_scope_release(
    corto_objectseq scope);

/** Invoke a callback for each object in a scope.
 * The object passed to this function must be created with CORTO_ATTR_NAMED. If
 * an object without CORTO_ATTR_NAMED is passed to this function the behavior is
 * undefined.
 *
 * Usage of this function is generally NOT recommended as it locks the scope
 * which is a very intrusive operation. The lock is still being held when the
 * action is called, so care must be taken not to introduce any deadlocks while
 * in the action.
 *
 * Use this function only for fast, low-level operations. For all other operations
 * that need to walk a scope, use the safer corto_scope_claim and corto_scope_release.
 *
 * @param o A named object.
 * @return A sequence with the objects in the scope of the object.
 * @see corto_scope_claim corto_scope_release
 */
CORTO_EXPORT
int16_t corto_scope_walk(
    corto_object o,
    corto_scope_walk_cb action,
    void *userData);

/* Set a reference value.
 * This function will increase the refcount of the specified object, assign the
 * object to the value, and decrease the refcount of the old object, in that order.
 * Both value (not ptr!) and object can be null.
 *
 * @param ptr A pointer to the value.
 * @param object The object reference to assign to the value.
 */
CORTO_EXPORT
void corto_set_ref(
    void* ptr,
    corto_object object);

/* Set a string value.
 * This function will duplicate the the specified string, assign the
 * string to the value, and deallocate the old string, in that order.
 * Both value (not ptr!) and object can be null.
 *
 * @param ptr A pointer to the value.
 * @param str The string to assign to the value.
 */
CORTO_EXPORT
void corto_set_str(
    char **ptr,
    const char *str);

/* Call base initalizer / constructor / destructor */

CORTO_EXPORT
int16_t corto_super_init(
    corto_object o);

CORTO_EXPORT
int16_t corto_super_deinit(
    corto_object o);

CORTO_EXPORT
int16_t corto_super_construct(
    corto_object o);

CORTO_EXPORT
void corto_super_destruct(
    corto_object o);


/* Macro's that automate casting of parameters */
#define corto_create(parent, name, type) _corto_create(parent, name, corto_type(type))
#define corto_declare(parent, name, type) _corto_declare(parent, name, corto_type(type))
#define corto_copy(dst, src) _corto_copy((corto_object*)dst, src)
#define corto_instanceof(type, o) _corto_instanceof((corto_type)type, o)
#define corto_type_instanceof(type, valueType) _corto_type_instanceof((corto_type)type, (corto_type)valueType)

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

/* Find a function that matches a signature (embedded in corto_lookup) */
CORTO_EXPORT
corto_object corto_lookup_function(
    corto_object scope,
    const char* requested,
    int32_t *d,
    int32_t *diff);

/* Calculate the distance between a function and a request signature */
CORTO_EXPORT
int16_t corto_overload(
    corto_object object,
    const char* name,
    int32_t* distance);

/* Obtain information from signature.
 *   Signatures can be of the following form:
 *     name(type name,type name)
 *     name(type,type)
 *     name --> Only allowed for non-overloaded functions
 *
 *   No extra whitespaces are allowed.
 */

CORTO_EXPORT
int32_t corto_sig_name(
    const char* signature,
    corto_id buffer);

CORTO_EXPORT
int32_t corto_sig_paramCount(
    const char* signature);

CORTO_EXPORT
int32_t corto_sig_param_name(
    const char* signature,
    uint32_t id,
    corto_id buffer);

CORTO_EXPORT
int32_t corto_sig_param_type(
    const char* signature,
    uint32_t id,
    corto_id buffer,
    int* reference);

/* Create request signature */

CORTO_EXPORT
char* corto_sig_open(
    const char* name);

CORTO_EXPORT
char* corto_sig_add(
    char* sig,
    corto_type type,
    int flags);

CORTO_EXPORT
char* corto_sig_addWildcard(
    char* sig,
    bool isReference);

CORTO_EXPORT
char* corto_sig_close(
    char* sig);

/* Obtain signature from function or delegate */
CORTO_EXPORT
char* corto_sig(
    corto_object o,
    corto_id buffer);

#ifdef __cplusplus
}
#endif

/* -- C++ SUPPORT TEMPLATES -- */
#ifdef __cplusplus
namespace corto {

/* Type-safe corto::declare */
template <class T>
typename T::_ref declare(corto_object object, const char *id) {
    return static_cast<typename T::_ref>(_corto_declare(object, id, (corto_type)T::_o));
}

/* Type-safe corto::create */
template <class T>
typename T::_ref create(corto_object object, const char *id) {
    return static_cast<typename T::_ref>(_corto_create(object, id, (corto_type)T::_o));
}

/* Overloaded type-safe corto::declare */
template <class T>
typename T::_ref declare() {
    return static_cast<typename T::_ref>(_corto_declare(NULL, NULL, (corto_type)T::_o));
}

/* Overloaded type-safe corto::create */
template <class T>
typename T::_ref create() {
    return static_cast<typename T::_ref>(_corto_create(NULL, NULL, (corto_type)T::_o));
}

}
#endif

#endif
