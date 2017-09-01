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

/** @file 
 * @section query Query API
 * @brief API for querying the store.
 *
 * Query functions allow an application to make selections of objects and apply
 * filters to those selections. The Query API is optimized to handle large
 * datasets and thus does not rely on the RAM object store. Instead, the API
 * interacts directly with mounts to obtain data.
 *
 * The API contains functions to do single-shot queries (`corto_select`), 
 * realtime queries (`corto_subscribe`) and to push data to subscribers without
 * using RAM objects (`corto_publish`).
 */

#ifndef CORTO_QUERY_H_
#define CORTO_QUERY_H_

#include <corto/base.h>
#include <corto/vstore/_type.h>
#include <corto/lang/_type.h>
#include <corto/secure/_type.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct corto_select__fluent {
    /** Specify a relative scope for the query.
     * @param scope A scope identifier. 
     */
    struct corto_select__fluent (*from)(
        char *scope);

    /** Request results in a specific contentType.
     * @param contentType A MIME identifier identifying a contentType.
     */
    struct corto_select__fluent (*contentType)(
        char *contentType);

    /** Enable pagination by specifying an offset and limit.
     * @param offset Specifies from which nth object results should be returned.
     * @param limit Specifies the total number of results that should be returned.
     */
    struct corto_select__fluent (*limit)(
        corto_uint64 offset, 
        corto_uint64 limit);

    /** Filter results by type.
     * @param filter An id expression matching one or more types.
     */
    struct corto_select__fluent (*type)(
        char *filter);

    /** Filter out results from a specific instance (mount).
     * This is typically useful when using corto_select from a mount, and the
     * mount does not want to invoke itself.
     *
     * @param instance The instance object.
     */
    struct corto_select__fluent (*instance)(
        corto_object instance);

    /** Only return results for a specific mount.
     * This is typically useful when using corto_select from a mount, and the
     * mount does not want to invoke itself.
     *
     * @param instance The instance object.
     */    
    struct corto_select__fluent (*mount)(
        corto_mount mount);

    /** Request historical data starting from the current time. */
    struct corto_select__fluent (*fromNow)(void);

    /** Request historical data starting from fixed timestamp 
     * @param t The timestamp from which to return historical data.
     */
    struct corto_select__fluent (*fromTime)(
        corto_time t);

    /** Request historical data from a fixed sample id.
     * @param sample Sample id, starting from the beginning of the sequence.
     */
    struct corto_select__fluent (*fromSample)(
        corto_uint64 sample);

    /** Request historical data until now. */
    struct corto_select__fluent (*toNow)(void);

    /** Request historical data until a fixed timestamp.
     * @param t The timestamp until which to return historical data.
     */
    struct corto_select__fluent (*toTime)(
        corto_time t);

    /** Request historical data until a fixed sample id.
     * @param sample Sample id, starting from the beginning of the sequence.
     */    
    struct corto_select__fluent (*toSample)(
        corto_uint64 sample);

    /** Request historical data for a specific time window.
     * @param t The duration of the time window.
     */
    struct corto_select__fluent (*forDuration)(
        corto_time t);

    /** Request historical data for a specific number of samples.
     * @param depth The number of samples in the window.
     */
    struct corto_select__fluent (*forDepth)(
        int64_t depth);

    /** Return an iterator to the requested results.
     * Results are returned as corto_result instances. A corto_result contains
     * metadata and when a content type is specified, a serialized value of an 
     * object. When using this function, no objects are created.
     *
     * @param iter_out A pointer to an iterator object.
     * @return 0 if success, -1 if failed.
     */
    int16_t (*iter)(
        corto_resultIter *iter_out);

    /** Return an iterator to the requested objects.
     * This function will return results as anonymous objects. No objects will be
     * created in the object store.
     *
     * @param iter_out A pointer to an iterator object.
     * @return 0 if success, -1 if failed.
     */
    int16_t (*iterObjects)(
        corto_objectIter *iter_out); /* Unstable API */

    /** Return the number of objects for a query.
     * This function requires a walk over all the returned results to determine
     * the total number of objects. 
     *
     * @return -1 if failed, otherwise the total number of objects.
     */
    int64_t (*count)(void);

    /* Internal APIs */
    int16_t (*subscribe)(corto_resultIter *ret); /* Unstable API */
    int16_t (*unsubscribe)(void); /* Unstable API */
    char* (*id)(void); /* Unstable API */
} corto_select__fluent;

/** Single-shot query.
 * With corto_select an application can select a subset of objects using a corto
 * identifier expression (parent, expr). The functionality of the corto_select
 * function is extended with fluent methods (see 
 * [corto_select fluent methods](corto_select_fluent_methods)) that enable an
 * application to further narrow down results and perform various operations on
 * the objects.
 *
 * The most common operation is to request an iterator to the matching objects
 * which allows the application to iterate over the set one by one.
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
 * @param expr An expression matching one or more objects [printf-style format specifier].
 */ 
CORTO_EXPORT 
struct corto_select__fluent corto_select(
    char *expr, 
    ...);

/** Publish event.
 * This function enables emitting events for objects that are not loaded in the
 * RAM store. This allows for efficient routing of events between subscribers
 * without the need to (de)marshall object values.
 *
 * If the object is loaded in the RAM store, a call to corto_publish will
 * demarshall the specified value into the object.
 *
 * The function may only emit events of the data kind, which are ON_DEFINE, 
 * ON_UPDATE, ON_INVALIDATE and ON_DELETE. The other events are reserved for 
 * objects that are loaded in the RAM store.
 *
 * @param event The event to be emitted
 * @param id A string representing the id of the object in the form of 'foo/bar'.
 * @param type A string representing the id of the type as returned by corto_fullpath.
 * @param contentType A string representing the content type (format) of the specified value.
 * @param value A string (or binary value) representing the serialized value of the object.
 * @return 0 if success, nonzero if failed.
 * @see corto_update_begin corto_update_end corto_update_try corto_update_cancel corto_publish
 * @see corto_observe corto_subscribe
 */
CORTO_EXPORT 
int16_t corto_publish(
    corto_eventMask event,
    char *id,
    char *type,
    char *contentType,
    void *content);

typedef struct corto_subscribe__fluent {
    /** Specify a relative scope for the subscriber. 
     * @param scope A scope identifier. 
     */
    struct corto_subscribe__fluent (*from)(
        char *scope);

    /** Create disabled subscriber.
     * Disabled observers allow an application to make modifications to the
     * event mask or expression, and to observe multiple expressions using 
     * `corto_subscriber_subscribe`.
     */
    struct corto_subscribe__fluent (*disabled)(void);

    /** Provide dispatcher for subscriber.
     * Dispatchers intercept events before they are delivered to an subscriber
     * callback, which enables applications to implement custom event handlers.
     * A common usecase for this is to forward events to a worker thread.
     *
     * @param dispatcher A dispatcher object.
     */
    struct corto_subscribe__fluent (*dispatcher)(
        corto_dispatcher dispatcher);

    /** Specify an instance.
     * Instances are passed to subscriber callbacks. They are typically used to pass
     * the `this` variable when an subscriber is associated with a class.
     *
     * @param instance A corto object.
     */
    struct corto_subscribe__fluent (*instance)(
        corto_object instance);

    /** Request results in a specific contentType.
     * @param contentType A MIME identifier identifying a contentType.
     */
    struct corto_subscribe__fluent (*contentType)(
        char *contentType);

    /** Filter objects by type.
     * The subscriber will only trigger on objects of the specified type.
     *
     * @param type A valid corto type identifier.
     */
    struct corto_subscribe__fluent (*type)(
        char *type);

    /** Specify callback, create subscriber.
     * Provide a callback function that is invoked when a matching event occurs.
     * This function returns a new subscriber based on the specified parameters.
     *
     * @param callback An subscriber callback function.
     */
    corto_subscriber ___ (*callback)(
        void (*r)(corto_subscriberEvent*));
} corto_subscribe__fluent;

/** Create a realtime query.
 * Subscribers enable an application to listen for for events from the object 
 * store and events that come directly from mounts. Subscribers receive only
 * data events (`ON_DEFINE`, `ON_UPDATE`, `ON_DELETE`).
 *
 * The difference between subscribers and observers is that while observers 
 * provide a reference to an object, a subscriber returns a `corto_result`, which
 * contains metadata about the object, and when requested, a serialized value.
 *
 * This means that a subscriber does not require objects to be stored in the 
 * in-memory object store, which makes it a better API for working with large 
 * datasets.
 *
 * @param expr An expression matching one or more objects [printf-style format specifier].
 */
CORTO_EXPORT 
struct corto_subscribe__fluent corto_subscribe(
    char *expr, 
    ...);

/** Delete a subscriber.
 * No more events will be delivered to the callback after this function is
 * called. Note that the subscriber object will not be deallocated if there are
 * references to the object.
 *
 * When there are still events in flight when this function is called (something
 * that can happen when a dispatcher is pushing events to another thread) the
 * application can prevent delivery of the event by checking the state of the
 * subscriber object, which is part of the `corto_subscriberEvent` instance, by
 * doing:
 *
@verbatim
```c
void myDispatcher_post(corto_subscriberEvent *e) {
    if (!corto_checkState(e->subscriber, CORTO_DELETED)) {
        corto_event_handle(e);
    } else {
        // Do nothing
    }
}
```
@endverbatim
 *
 * @param subscriber A subscriber object.
 * @return 0 if success, -1 if failed.
 */ 
CORTO_EXPORT 
int16_t corto_unsubscribe(
    corto_subscriber subscriber, 
    corto_object instance);

#ifdef __cplusplus
}
#endif

#endif
