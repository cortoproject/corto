/* $CORTO_GENERATED
 *
 * mount.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/corto.h>

/* $header() */
#include "_object.h"
extern corto_threadKey CORTO_KEY_MOUNT_RESULT;
corto_entityAdmin corto_mount_admin;
/* $end */

/* $header(corto/core/mount/construct) */
void* corto_mount_thread(void* arg) {
    corto_mount this = arg;
    corto_float64 frequency = this->policies.sampleRate;
    corto_uint32 sec = 1.0 / frequency;
    frequency -= sec;
    corto_uint32 nanosec = 0;

    if (frequency >= 0) {
        nanosec = (1.0 / frequency) * 1000000000.0;
    }

    while (!this->quit) {
        corto_mount_onPoll(this);
        corto_sleep(sec, nanosec);
    }

    return NULL;
}

void corto_mount_notify(corto_subscriberEvent *e) {
    corto_mount this = (corto_mount)e->subscriber;
    corto_eventMask event = e->event;
    corto_result *r = &e->data;

    if (event != CORTO_ON_DECLARE) {
        if (!r->object || (!this->attr || corto_checkAttr(r->object, this->attr))) {
            corto_mount_onNotify(this, event, r);
        }
    }

    switch(event) {
    case CORTO_ON_DEFINE: this->sent.updates ++; break;
    case CORTO_ON_UPDATE: this->sent.updates ++; break;
    case CORTO_ON_DELETE: this->sent.deletes ++; break;
    default: break;
    }
}

int corto_mount_alignSubscriptionsAction(
  corto_object e,
  corto_object instance,
  void *userData)
{
    corto_mount this = userData;
    corto_iter it;
    corto_subscriber s = e;

    CORTO_UNUSED(instance);

    corto_select(s->parent, s->expr)
      .mount(this)
      .subscribe(&it);

    /* Visit all objects to find all subscriptions */
    while (corto_iter_hasNext(&it)) {
        corto_iter_next(&it);
    }

    return 1;
}

corto_int16 corto_mount_alignSubscriptions(corto_mount this) {

    if (!corto_entityAdmin_walk(&corto_subscriber_admin, corto_mount_alignSubscriptionsAction, NULL, this)) {
        goto error;
    }

    return 0;
error:
    return -1;
}

corto_bool corto_mount_hasMethod(corto_mount this, corto_string id) {
    corto_method m = corto_interface_resolveMethod(corto_typeof(this), id);
    if (m && (corto_parentof(m) != corto_mount_o)) {
        return TRUE;
    } else {
        return FALSE;
    }
}

/* $end */
int16_t _corto_mount_construct(
    corto_mount this)
{
/* $begin(corto/core/mount/construct) */
    corto_object dispatcher = NULL;

    /* If mount isn't set, and object is scoped, mount data on itself */
    if (!this->mount && corto_checkAttr(this, CORTO_ATTR_SCOPED) && !corto_subscriber(this)->parent) {
        corto_setref(&this->mount, this);
    }

    if (this->mount) {
        /*corto_warning(
          "corto: %s: using mount/mount is deprecated, please use 'parent' and 'expr'",
          corto_fullpath(NULL, corto_typeof(this)));*/
        corto_setstr(&corto_subscriber(this)->parent, corto_fullpath(NULL, this->mount));
    }

    corto_eventMask mask = corto_observer(this)->mask;

    /* If parent is set, resolve it and assign mount */
    if (corto_subscriber(this)->parent) {
        corto_object o = corto_lookup(NULL, corto_subscriber(this)->parent);
        if (!o) {
            corto_seterr(
                "'%s' not found (future versions will allow mounts on virtual scopes)",
                corto_subscriber(this)->parent);
            goto error;
        }
        corto_setref(&this->mount, o);
        corto_release(o);

        /* Set the expression according to the mask */
        if (mask & CORTO_ON_TREE) {
            corto_setstr(&corto_subscriber(this)->expr, "//");
        } else if (mask & CORTO_ON_SCOPE) {
            corto_setstr(&corto_subscriber(this)->expr, "/");
        } else {
            corto_setstr(&corto_subscriber(this)->expr, ".");
        }
    }

    /* Parse policies */
    if (this->policy) {
        corto_string value;
        void *policies = &this->policies;
        corto_asprintf(&value, "{%s}", this->policy);
        if (corto_ptr_fromStr(&policies, corto_mountPolicy_o, value)) {
            corto_dealloc(value);
            goto error;
        }
        corto_dealloc(value);
    }

    /* If rate limiting is enabled, start thread */
    if (this->policies.sampleRate) {
        dispatcher = this;
        this->thread = (corto_word)corto_threadNew(
            corto_mount_thread,
            this);
    }

    /* If mount doesn't implement onRequest, it is a passthrough mount meaning
     * it uses the object store. */
    if (!corto_mount_hasMethod(this, "onRequest")) this->passThrough = TRUE;

    /* If mount doesn't implement onResume, the mount will use onRequest to
     * request the object and then use the returned data to automatically
     * instantiate an object in the store. */
    if (corto_mount_hasMethod(this, "onResume")) this->hasResume = TRUE;

    /* Set the callback function */
    corto_function(this)->kind = CORTO_PROCEDURE_CDECL;
    corto_function(this)->fptr = (corto_word)corto_mount_notify;
    corto_setref(&corto_observer(this)->instance, this);
    corto_setref(&corto_observer(this)->dispatcher, dispatcher);

    /* Enable subscriber only when mount implements onNotify */
    if (corto_mount_hasMethod(this, "onNotify")) {
        corto_observer(this)->enabled = TRUE;
    }

    corto_observer(this)->mask |=
      CORTO_ON_DECLARE|CORTO_ON_DEFINE|CORTO_ON_UPDATE|CORTO_ON_DELETE;
    if (!corto_subscriber(this)->expr) {
        corto_setstr(&corto_subscriber(this)->expr, "//");
    }

    corto_entityAdmin_add(&corto_mount_admin, corto_subscriber(this)->parent, this, this);

    /* If mount is interested in subscriptions, align from existing subscribers */
    if (corto_mount_hasMethod(this, "onSubscribe") ||
        corto_mount_hasMethod(this, "onUnsubscribe"))
    {
        if (corto_mount_alignSubscriptions(this)) {
            goto error;
        }
    }

    corto_int16 ret = corto_subscriber_construct(this);
    if (ret) {
        corto_entityAdmin_remove(&corto_mount_admin, corto_subscriber(this)->parent, this, this, FALSE);
    }
    
    return ret;
error:
    return -1;
/* $end */
}

void _corto_mount_destruct(
    corto_mount this)
{
/* $begin(corto/core/mount/destruct) */
    corto_mountSubscription *s = NULL;

    /* Signal thread ASAP to stop */
    this->quit = TRUE;

    /* Unsubscribe from active subscriptions */
    while ((s = corto_ll_takeFirst(this->subscriptions))) {
        corto_mount_onUnsubscribe(
            this,
            s->parent,
            s->expr,
            s->userData);
        corto_ptr_deinit(s, corto_mountSubscription_o);
        corto_dealloc(s);
    }

    if (this->thread) {
        corto_threadJoin((corto_thread)this->thread, NULL);
    }

    corto_subscriber_destruct(this);

    corto_assert(
        corto_entityAdmin_remove(&corto_mount_admin, corto_subscriber(this)->parent, this, this, FALSE) != -1, 
        "trying to remove mount that was never added to mountAdmin");

/* $end */
}

corto_string _corto_mount_id(
    corto_mount this)
{
/* $begin(corto/core/mount/id) */

    return corto_mount_onId(this);
/* $end */
}

int16_t _corto_mount_init(
    corto_mount this)
{
/* $begin(corto/core/mount/init) */

    this->kind = CORTO_SOURCE;
    corto_observer(this)->mask = CORTO_ON_SCOPE;
    this->attr = CORTO_ATTR_PERSISTENT;

    return corto_subscriber_init(this);
/* $end */
}

void _corto_mount_invoke(
    corto_mount this,
    corto_object instance,
    corto_function proc,
    uintptr_t argptrs)
{
/* $begin(corto/core/mount/invoke) */
    corto_object owner = corto_ownerof(instance);

    if (owner == this) {
        corto_mount_onInvoke(this, instance, proc, argptrs);
    } else {
        corto_object prevowner = corto_setOwner(corto_ownerof(instance));
        corto_callb(proc, NULL, (void**)argptrs);
        corto_setOwner(prevowner);
    }

/* $end */
}

corto_string _corto_mount_onId_v(
    corto_mount this)
{
/* $begin(corto/core/mount/onId) */
    CORTO_UNUSED(this);
    return NULL;
/* $end */
}

void _corto_mount_onInvoke_v(
    corto_mount this,
    corto_object instance,
    corto_function proc,
    uintptr_t argptrs)
{
/* $begin(corto/core/mount/onInvoke) */

    CORTO_UNUSED(this);
    CORTO_UNUSED(instance);
    CORTO_UNUSED(proc);
    CORTO_UNUSED(argptrs);

/* $end */
}

void _corto_mount_onNotify_v(
    corto_mount this,
    corto_eventMask event,
    corto_result *object)
{
/* $begin(corto/core/mount/onNotify) */

    CORTO_UNUSED(this);
    CORTO_UNUSED(event);
    CORTO_UNUSED(object);

/* $end */
}

void _corto_mount_onPoll_v(
    corto_mount this)
{
/* $begin(corto/core/mount/onPoll) */
    corto_event *e;
    corto_ll events = corto_ll_new();

    /* Collect events */
    corto_lock(this);
    while ((e = corto_ll_takeFirst(this->events))) {
        corto_ll_append(events, e);
    }
    corto_unlock(this);

    /* Handle events outside of lock */
    while ((e = corto_ll_takeFirst(events))) {
        corto_event_handle(e);
        corto_assert(corto_release(e) == 0);
    }

    corto_ll_free(events);
/* $end */
}

corto_resultIter _corto_mount_onRequest_v(
    corto_mount this,
    corto_request *request)
{
/* $begin(corto/core/mount/onRequest) */
    corto_resultIter result;
    CORTO_UNUSED(this);
    CORTO_UNUSED(request);
    memset(&result, 0, sizeof(corto_iter));

    if (corto_instanceof(corto_routerimpl_o, corto_typeof(this))) {
        corto_id routerRequest;
        corto_any routerResult = {corto_type(corto_resultIter_o), &result};
        corto_any routerParam = {corto_type(corto_request_o), request};
        sprintf(routerRequest, "%s/%s", request->parent, request->expr);
        corto_cleanpath(routerRequest, routerRequest);
        if (corto_router_match(this, routerRequest, routerParam, routerResult, NULL)) {
            corto_warning("%s", corto_lasterr());
        }
    }

    return result;
/* $end */
}

corto_object _corto_mount_onResume_v(
    corto_mount this,
    corto_string parent,
    corto_string name,
    corto_object o)
{
/* $begin(corto/core/mount/onResume) */
    CORTO_UNUSED(this);
    CORTO_UNUSED(parent);
    CORTO_UNUSED(name);
    CORTO_UNUSED(o);

    return NULL;
/* $end */
}

uintptr_t _corto_mount_onSubscribe_v(
    corto_mount this,
    corto_string parent,
    corto_string expr,
    uintptr_t ctx)
{
/* $begin(corto/core/mount/onSubscribe) */
    CORTO_UNUSED(this);
    CORTO_UNUSED(parent);
    CORTO_UNUSED(expr);
    CORTO_UNUSED(ctx);

    return 0;
/* $end */
}

void _corto_mount_onUnsubscribe_v(
    corto_mount this,
    corto_string parent,
    corto_string expr,
    uintptr_t ctx)
{
/* $begin(corto/core/mount/onUnsubscribe) */
    CORTO_UNUSED(this);
    CORTO_UNUSED(parent);
    CORTO_UNUSED(expr);
    CORTO_UNUSED(ctx);

/* $end */
}

/* $header(corto/core/mount/post) */
static corto_subscriberEvent* corto_mount_findEvent(corto_mount this, corto_subscriberEvent *e) {
    corto_iter iter = corto_ll_iter(this->events);
    corto_subscriberEvent *e2;
    while ((corto_iter_hasNext(&iter))) {
        e2 = corto_iter_next(&iter);
        if (!strcmp(e2->data.id, e->data.id) &&
            !strcmp(e2->data.parent, e->data.parent) &&
            (e2->subscriber == e->subscriber))
        {
            return e2;
        }
    }
    return NULL;
}

#define MOUNT_QUEUE_THRESHOLD 2000
#define MOUNT_QUEUE_THRESHOLD_SLEEP 1000000

/* $end */
void _corto_mount_post(
    corto_mount this,
    corto_event *e)
{
/* $begin(corto/core/mount/post) */

    /* If sampleRate != 0, post event to list. Another thread will process it
     * at the specified rate. */
    if (this->policies.sampleRate) {
        corto_uint32 size = 0;
        corto_subscriberEvent *e2;

        /* Append new event to queue */
        corto_lock(this);

        /* Check if there is already another event in the queue for the same object.
         * if so, replace event with latest update. */
        if ((e2 = corto_mount_findEvent(this, corto_subscriberEvent(e)))) {
            corto_ll_replace(this->events, e2, e);
            if (e2->event & CORTO_ON_DECLARE) this->sentDiscarded.declares++;
            if (e2->event & (CORTO_ON_DEFINE | CORTO_ON_UPDATE)) this->sentDiscarded.updates++;
            if (e2->event & CORTO_ON_DELETE) this->sentDiscarded.deletes++;
            corto_assert(corto_release(e2) == 0);
        } else {
            corto_ll_append(this->events, e);
        }

        size = corto_ll_size(this->events);
        corto_unlock(this);

        /* If queue is getting big, slow down publisher */
        if (size > MOUNT_QUEUE_THRESHOLD) {
            corto_sleep(0, MOUNT_QUEUE_THRESHOLD_SLEEP);
        }
    } else {
        corto_event_handle(e);
        corto_assert(corto_release(e) == 0);
    }

/* $end */
}

/* $header(corto/core/mount/request) */
void corto_mount_requestRelease(corto_iter *iter) {
    corto_ll_iter_s *data = iter->udata;
    corto_ptr_deinit(&data->list, corto_resultList_o);
    corto_ll_iterRelease(iter);
}
/* $end */
corto_resultIter _corto_mount_request(
    corto_mount this,
    corto_request *request)
{
/* $begin(corto/core/mount/request) */
    corto_iter result;
    corto_ll r, prevResult = corto_threadTlsGet(CORTO_KEY_MOUNT_RESULT);
    corto_threadTlsSet(CORTO_KEY_MOUNT_RESULT, NULL);

    result = corto_mount_onRequest(this, request);

    /* If mount isn't returning anything with the iterator, check if there's
     * anything in the result list. */
    if (!result.hasNext && (r = corto_threadTlsGet(CORTO_KEY_MOUNT_RESULT))) {
        result = corto_ll_iterAlloc(r);
        result.release = corto_mount_requestRelease;
    }

    corto_threadTlsSet(CORTO_KEY_MOUNT_RESULT, prevResult);

    return result;
/* $end */
}

corto_object _corto_mount_resume(
    corto_mount this,
    corto_string parent,
    corto_string name,
    corto_object o)
{
/* $begin(corto/core/mount/resume) */
    if (this->kind != CORTO_SINK) {
        return NULL;
    }
    
    /* Ensure that if object is created, owner & attributes are set correctly */
    corto_attr prevAttr = corto_setAttr(CORTO_ATTR_PERSISTENT | corto_getAttr());
    corto_object prevOwner = corto_setOwner(this);

    corto_object result = NULL;

    /* Resume object */
    if (this->hasResume) {
        corto_debug("mount: onResume parent=%s, expr=%s (mount = %s, o = %p)", parent, name, corto_fullpath(NULL, this), o);
        result = corto_mount_onResume(this, parent, name, o);
    } else {
        corto_id type;
        corto_request r;
        corto_bool newObject = FALSE;

        // Prepare request
        memset(&r, 0, sizeof(r));
        r.expr = name;
        r.parent = parent;
        if (o) {
            corto_fullpath(type, corto_typeof(o));
        } else {
            type[0] = '\0';
        }
        r.type = type;
        r.content = TRUE;

        // Request object from mount
        corto_debug("mount: try resume for '%s/%s' (mount = '%s')", parent, name, corto_fullpath(NULL, this));
        corto_resultIter it = corto_mount_request(this, &r);

        if (corto_iter_hasNext(&it)) {
            corto_result *iterResult = corto_iter_next(&it);

            if (!o) {
                if (iterResult->parent[0] == '/') {
                    corto_error(
                      "mount %s:%s returned fully qualified parent '%s', expected a path relative to mount",
                      corto_fullpath(NULL, this),
                      corto_fullpath(NULL, corto_typeof(this)),
                      iterResult->parent
                    );
                    goto error;
                }
                corto_object parent_o =
                  corto_lookup(corto_mount(this)->mount, parent);
                if (parent_o) {
                    corto_object type_o = corto_resolve(NULL, iterResult->type);
                    if (type_o) {
                        o = corto_declareChild(parent_o, iterResult->id, type_o);
                        if (!o) {
                            corto_seterr("failed to create object %s/%s: %s",
                              parent, name, corto_lasterr());
                        }
                        newObject = TRUE;
                        corto_release(type_o);
                    }
                    corto_release(parent_o);
                }
            }

            if (o) {
                corto_value v = corto_value_object(o, NULL);
                if (corto_subscriber(this)->contentTypeHandle && iterResult->value) {
                    ((corto_contentType)corto_subscriber(this)->contentTypeHandle)->toValue(
                        &v, iterResult->value);
                }
                if (newObject) {
                    corto_define(o);
                }
                result = o;
            }
        }

        if (corto_iter_hasNext(&it)) {
            corto_error(
              "corto: mount should not return more than one object (scope = '%s', id = '%s')",
              parent,
              name);

            do {
                corto_result *r = corto_iter_next(&it);
                fprintf(stderr, "  excess result: %s/%s\n", r->parent, r->id);
            } while (corto_iter_hasNext(&it));
            goto error;
        }
    }

    /* Restore owner & attributes */
    corto_setAttr(prevAttr);
    corto_setOwner(prevOwner);

    if (result) {
        corto_trace("mount: resumed '%s/%s' from '%s'", parent, name, corto_fullpath(NULL, this));
    }

    return result;
error:
    return NULL;
/* $end */
}

void _corto_mount_return(
    corto_mount this,
    corto_result *r)
{
/* $begin(corto/core/mount/return) */
    corto_ll result = corto_threadTlsGet(CORTO_KEY_MOUNT_RESULT);

    CORTO_UNUSED(this);

    if (!result) {
        result = corto_ll_new();
        corto_threadTlsSet(CORTO_KEY_MOUNT_RESULT, result);
    }

    corto_result *elem = corto_calloc(sizeof(corto_result));
    elem->id = corto_strdup(r->id);
    elem->id = corto_strdup(r->name);
    elem->parent = corto_strdup(r->parent);
    elem->type = corto_strdup(r->type);
    elem->value = (corto_word)r->value;
    elem->leaf = r->leaf;
    corto_ll_append(result, elem);

/* $end */
}

int16_t _corto_mount_setContentType(
    corto_mount this,
    corto_string type)
{
/* $begin(corto/core/mount/setContentType) */

    if (corto_mount_setContentTypeIn(this, type)) {
        goto error;
    }

    if (corto_mount_setContentTypeOut(this, type)) {
        goto error;
    }

    return 0;
error:
    return -1;
/* $end */
}

int16_t _corto_mount_setContentTypeIn(
    corto_mount this,
    corto_string type)
{
/* $begin(corto/core/mount/setContentTypeIn) */

    corto_setstr(&corto_subscriber(this)->contentType, type);
    corto_subscriber(this)->contentTypeHandle = (corto_word)corto_loadContentType(type);
    if (!corto_subscriber(this)->contentTypeHandle) {
        goto error;
    }

    return 0;
error:
    return -1;
/* $end */
}

int16_t _corto_mount_setContentTypeOut(
    corto_mount this,
    corto_string type)
{
/* $begin(corto/core/mount/setContentTypeOut) */

    corto_setstr(&this->contentTypeOut, type);
    this->contentTypeOutHandle = (corto_word)corto_loadContentType(type);
    if (!this->contentTypeOutHandle) {
        goto error;
    }

    return 0;
error:
    return -1;
/* $end */
}

/* $header(corto/core/mount/subscribe(/corto/core/request request)) */
static corto_mountSubscription* corto_mount_findSubscription(
    corto_mount this,
    corto_request *request,
    bool *found)
{
    *found = FALSE;
    corto_mountSubscription *result = NULL;

    corto_iter it = corto_ll_iter(this->subscriptions);
    while (corto_iter_hasNext(&it)) {
        corto_mountSubscription *s = corto_iter_next(&it);
        if (!stricmp(s->parent, request->parent)) {
             result = s;
             if (!stricmp(s->expr, request->expr)) {
                *found = TRUE;
                break;
            }
        }
    }

    return result;
}
/* $end */
void _corto_mount_subscribe(
    corto_mount this,
    corto_request *request)
{
/* $begin(corto/core/mount/subscribe(/corto/core/request request)) */
    corto_word ctx = 0;
    corto_mountSubscription *subscription = NULL;
    bool found = FALSE;

    if (corto_checkState(this, CORTO_DEFINED)) corto_lock(this);

    subscription = corto_mount_findSubscription(this, request, &found);
    if (subscription) {
        /* Ensure subscription isn't deleted outside of lock */
        subscription->count ++;
    } else {
        /* Add placeholder to list, so onSubscribe won't be called recursively */
        corto_mountSubscription *placeHolder = corto_calloc(sizeof(corto_mountSubscription));
        placeHolder->parent = corto_strdup(request->parent);
        placeHolder->expr = corto_strdup(request->expr);
        placeHolder->count = 1;
        corto_ll_append(this->subscriptions, placeHolder);
    }
    if (corto_checkState(this, CORTO_DEFINED)) corto_unlock(this);

    /* Process callback outside of lock */
    if (!found && (!subscription || subscription->userData)) {
        /* If no subscription is found that both matches parent and expr, notify
         * the mount */
        ctx = corto_mount_onSubscribe(
          this,
          request->parent,
          request->expr,
          subscription ? subscription->userData : 0);
    }

    /* Only add subscription if connection data is not null, no existing
     * subscription exists, and if context data differs from existing
     * subscription */
    if (ctx && (!subscription || (subscription->userData != ctx))) {
        if (corto_checkState(this, CORTO_DEFINED)) corto_lock(this);

        /* If a new subscription is required, undo increase of refcount of the
         * subscription that was found */
        if (subscription) {
            subscription->count --;
        }

        /* Do lookup again, as list may have changed while mount was unlocked */
        subscription = corto_mount_findSubscription(this, request, &found);
        if (!found) {
            subscription = corto_calloc(sizeof(corto_mountSubscription));
            subscription->parent = corto_strdup(request->parent);
            subscription->expr = corto_strdup(request->expr);
            subscription->count = 1;
            corto_ll_append(this->subscriptions, subscription);
        } else if (subscription->userData) {
            /* Increase refcount of new or existing subscription (can be new if
             * during the unlock a new subscription was added). */
            subscription->count ++;
        } else {
            /* If userData is 0, this was a temporary entry in the subscriptions
             * list to prevent recursion. Since it will already have a count of
             * 1, don't increase refcount again as this would leak */
        }

        subscription->userData = ctx;

        if (corto_checkState(this, CORTO_DEFINED))  corto_unlock(this);
    } else if (ctx && !found && subscription) {
        /* If there is no need to create a new subscription but no exact match
         * was found, it means that onSubscribe returned the same ctx as the
         * existing connection. In that case, the 'expr' parameter of the
         * subscription is meaningless, so to avoid confusion set it to '*' */
       if (corto_checkState(this, CORTO_DEFINED))  corto_lock(this);
       corto_setstr(&subscription->expr, "*");

       /* Doesn't count as new subscription, so undo increase in refcount */
       subscription->count --;
       if (corto_checkState(this, CORTO_DEFINED)) corto_unlock(this);
    }

/* $end */
}

void _corto_mount_unsubscribe(
    corto_mount this,
    corto_request *request)
{
/* $begin(corto/core/mount/unsubscribe(/corto/core/request request)) */
    corto_mountSubscription *subscription = NULL;
    corto_bool found = FALSE;

    corto_lock(this);
    subscription = corto_mount_findSubscription(this, request, &found);

    if (subscription) {
        if (! --subscription->count) {
            corto_ll_remove(this->subscriptions, subscription);
        } else {
            subscription = NULL;
        }
    }
    corto_unlock(this);


    if (subscription) {
        corto_mount_onUnsubscribe(this, subscription->parent, subscription->expr, subscription->userData);
        corto_ptr_deinit(subscription, corto_mountSubscription_o);
        corto_dealloc(subscription);
    }

/* $end */
}
