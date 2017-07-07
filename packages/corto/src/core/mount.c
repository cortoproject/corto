/* This is a managed file. Do not delete this comment. */

#include <corto/corto.h>


#include "_object.h"
extern corto_threadKey CORTO_KEY_MOUNT_RESULT;
corto_entityAdmin corto_mount_admin = {
    .key = 0,
    .count = 0,
    .lock = CORTO_RWMUTEX_INITIALIZER,
    .changed = 0
};


void* corto_mount_thread(void* arg) {
    corto_mount this = arg;
    corto_float64 frequency = this->policy.sampleRate;
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

    if (!r->object || (!this->attr || corto_checkAttr(r->object, this->attr))) {
        corto_mount_onNotify(this, e);
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

    corto_select(s->query.select)
      .from(s->query.from)
      .type(s->query.type)
      .mount(this)
      .subscribe(&it);

    /* Visit all objects to find all subscriptions */
    while (corto_iter_hasNext(&it)) {
        corto_iter_next(&it);
    }

    return 1;
}

corto_int16 corto_mount_alignSubscriptions(corto_mount this) {

    if (!corto_entityAdmin_walk(&corto_subscriber_admin, corto_mount_alignSubscriptionsAction, NULL, false, this)) {
        goto error;
    }

    return 0;
error:
    return -1;
}

corto_bool corto_mount_hasMethod(corto_mount this, corto_string id) {
    corto_method m = safe_corto_interface_resolveMethod(corto_typeof(this), id);
    if (m && (corto_parentof(m) != corto_mount_o)) {
        return TRUE;
    } else {
        return FALSE;
    }
}


int16_t corto_mount_construct(
    corto_mount this)
{
    corto_object dispatcher = NULL;
    corto_subscriber s = corto_subscriber(this);

    /* If mount isn't set, and object is scoped, mount data on itself */
    if (!this->mount && corto_checkAttr(this, CORTO_ATTR_NAMED) && !s->query.from) {
        corto_ptr_setref(&this->mount, this);
    }

    if (this->mount) {
        corto_ptr_setstr(&s->query.from, corto_fullpath(NULL, this->mount));
    } else if (s->query.from) {
        this->mount = corto_find(NULL, s->query.from, CORTO_FIND_DEFAULT);
    }

    corto_eventMask mask = corto_observer(this)->mask;

    /* If parent is set, resolve it and assign mount */
    if (!s->query.select) {

        /* Set the expression according to the mask */
        if (mask & CORTO_ON_TREE) {
            corto_ptr_setstr(&s->query.select, "//");
        } else if (mask & CORTO_ON_SCOPE) {
            corto_ptr_setstr(&s->query.select, "/");
        } else if (mask & CORTO_ON_SELF) {
            corto_ptr_setstr(&s->query.select, ".");
        } else {
            corto_ptr_setstr(&s->query.select, "/");
        }
    }

    /* Parse policies */
    if (this->policy.sampleRate) {
        dispatcher = this;
        this->thread = (corto_word)corto_threadNew(
            corto_mount_thread,
            this);
    }

    /* If mount doesn't implement onQuery, it is a passthrough mount meaning
     * it uses the object store. */
    if (!corto_mount_hasMethod(this, "onQuery")) this->passThrough = TRUE;

    /* If mount doesn't implement onResume, the mount will use onQuery to
     * request the object and then use the returned data to automatically
     * instantiate an object in the store. */
    if (corto_mount_hasMethod(this, "onResume")) this->hasResume = TRUE;

    /* Set the callback function */
    corto_function(this)->kind = CORTO_PROCEDURE_CDECL;
    corto_function(this)->fptr = (corto_word)corto_mount_notify;
    corto_ptr_setref(&corto_observer(this)->instance, this);
    corto_ptr_setref(&corto_observer(this)->dispatcher, dispatcher);

    /* Enable subscriber only when mount implements onNotify */
    if (corto_mount_hasMethod(this, "onNotify")) {
        corto_observer(this)->enabled = TRUE;
    }

    corto_observer(this)->mask |=
      CORTO_ON_DECLARE|CORTO_ON_DEFINE|CORTO_ON_UPDATE|CORTO_ON_DELETE;
    if (!s->query.select) {
        corto_ptr_setstr(&s->query.select, "//");
    }

    if (s->contentType &&
        (!s->contentTypeHandle ||
        !this->contentTypeOutHandle))
    {
        corto_mount_setContentType(this, s->contentType);
    }

    corto_entityAdmin_add(&corto_mount_admin, s->query.from, this, this);

    /* If mount is interested in subscriptions, align from existing subscribers */
    if (corto_mount_hasMethod(this, "onSubscribe") ||
        corto_mount_hasMethod(this, "onUnsubscribe"))
    {
        this->hasSubscribe = TRUE;
        if (corto_mount_alignSubscriptions(this)) {
            goto error;
        }
    }

    corto_int16 ret = safe_corto_subscriber_construct(this);
    if (ret) {
        corto_entityAdmin_remove(&corto_mount_admin, s->query.from, this, this, FALSE);
    } else {
        /* Make it easy to see whether this mount observes a tree, scope or self */
        corto_observer(this)->mask = 
            corto_match_getScope((corto_matchProgram)corto_subscriber(this)->matchProgram);
    }

    return ret;
error:
    return -1;
}

void corto_mount_destruct(
    corto_mount this)
{
    corto_mountSubscription *s = NULL;

    /* Signal thread ASAP to stop */
    this->quit = TRUE;

    /* Unsubscribe from active subscriptions */
    while ((s = corto_ll_takeFirst(this->subscriptions))) {
        corto_mount_onUnsubscribe(
            this,
            &s->query,
            s->ctx);
        corto_ptr_deinit(s, corto_mountSubscription_o);
        corto_dealloc(s);
    }

    if (this->thread) {
        corto_threadJoin((corto_thread)this->thread, NULL);
    }

    safe_corto_subscriber_destruct(this);

    corto_assert(
        corto_entityAdmin_remove(&corto_mount_admin, this->super.query.from, this, this, FALSE) != -1, 
        "trying to remove mount that was never added to mountAdmin");

}

corto_string corto_mount_id(
    corto_mount this)
{

    return corto_mount_onId(this);
}

int16_t corto_mount_init(
    corto_mount this)
{

    this->policy.ownership = CORTO_REMOTE_OWNER;
    this->policy.readWrite = CORTO_READ|CORTO_WRITE;
    this->policy.sampleRate = 0;
    this->policy.expiryTime = -1;
    this->attr = CORTO_ATTR_PERSISTENT;

    return safe_corto_subscriber_init(this);
}

void corto_mount_invoke(
    corto_mount this,
    corto_object instance,
    corto_function proc,
    uintptr_t argptrs)
{
    corto_object owner = corto_ownerof(instance);

    if (owner == this) {
        corto_mount_onInvoke(this, instance, proc, argptrs);
    } else {
        corto_object prevowner = corto_setOwner(corto_ownerof(instance));
        corto_callb(proc, NULL, (void**)argptrs);
        corto_setOwner(prevowner);
    }

}

corto_string corto_mount_onId_v(
    corto_mount this)
{
    CORTO_UNUSED(this);
    return NULL;
}

void corto_mount_onInvoke_v(
    corto_mount this,
    corto_object instance,
    corto_function proc,
    uintptr_t argptrs)
{

    CORTO_UNUSED(this);
    CORTO_UNUSED(instance);
    CORTO_UNUSED(proc);
    CORTO_UNUSED(argptrs);

}

void corto_mount_onNotify_v(
    corto_mount this,
    corto_subscriberEvent *event)
{

    CORTO_UNUSED(this);
    CORTO_UNUSED(event);

}

void corto_mount_onNotifyBatch_v(
    corto_mount this,
    corto_subscriberEventIter data)
{
    
    CORTO_UNUSED(this);
    CORTO_UNUSED(data);

}

void corto_mount_onPoll_v(
    corto_mount this)
{
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
    
}

corto_resultIter corto_mount_onQuery_v(
    corto_mount this,
    corto_query *query)
{
    corto_resultIter result;
    CORTO_UNUSED(this);
    memset(&result, 0, sizeof(corto_iter));

    if (corto_instanceof(corto_routerimpl_o, corto_typeof(this))) {
        corto_id routerRequest;
        corto_any routerResult = {corto_type(corto_resultIter_o), &result};
        corto_any routerParam = {corto_type(corto_query_o), query};
        sprintf(routerRequest, "%s/%s", query->from, query->select);
        corto_cleanpath(routerRequest, routerRequest);
        if (corto_router_match(this, routerRequest, routerParam, routerResult, NULL)) {
            corto_warning("%s", corto_lasterr());
        }
    }

    return result;
}

corto_resultIter corto_mount_onQueryHistorical_v(
    corto_mount this,
    corto_query *query)
{

    CORTO_UNUSED(this);
    CORTO_UNUSED(query);

    return CORTO_ITER_EMPTY;
}

corto_object corto_mount_onResume_v(
    corto_mount this,
    corto_string parent,
    corto_string name,
    corto_object object)
{
    CORTO_UNUSED(this);
    CORTO_UNUSED(parent);
    CORTO_UNUSED(name);
    CORTO_UNUSED(object);

    return NULL;
}

uintptr_t corto_mount_onSubscribe_v(
    corto_mount this,
    corto_query *query,
    uintptr_t ctx)
{
    CORTO_UNUSED(this);
    CORTO_UNUSED(query);
    CORTO_UNUSED(ctx);

    return 0;
}

uintptr_t corto_mount_onTransactionBegin_v(
    corto_mount this)
{

    CORTO_UNUSED(this);
    return 0;
}

void corto_mount_onTransactionEnd_v(
    corto_mount this,
    corto_subscriberEventIter events,
    uintptr_t ctx)
{

    CORTO_UNUSED(this);
    CORTO_UNUSED(events);
    CORTO_UNUSED(ctx);

}

void corto_mount_onUnsubscribe_v(
    corto_mount this,
    corto_query *query,
    uintptr_t ctx)
{
    CORTO_UNUSED(this);
    CORTO_UNUSED(query);
    CORTO_UNUSED(ctx);

}


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


void corto_mount_post(
    corto_mount this,
    corto_event *e)
{

    /* If sampleRate != 0, post event to list. Another thread will process it
     * at the specified rate. */
    if (this->policy.sampleRate) {
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

}

void corto_mount_publish(
    corto_mount this,
    corto_eventMask event,
    corto_string from,
    corto_string id,
    corto_string type,
    uintptr_t value)
{
    corto_id identifier;
    sprintf(identifier, "%s/%s/%s", corto_subscriber(this)->query.from, from, id);
    corto_cleanpath(identifier, identifier);

    corto_publish(
        event,
        identifier,
        type,
        this->contentTypeOut,
        (void*)value
    );

}


void corto_mount_queryRelease(corto_iter *iter) {
    corto_ll_iter_s *data = iter->ctx;
    corto_ptr_deinit(&data->list, corto_resultList_o);
    corto_ll_iterRelease(iter);
}

corto_resultIter corto_mount_query(
    corto_mount this,
    corto_query *query)
{
    corto_iter result;
    corto_ll r, prevResult = corto_threadTlsGet(CORTO_KEY_MOUNT_RESULT);
    corto_threadTlsSet(CORTO_KEY_MOUNT_RESULT, NULL);

    result = corto_mount_onQuery(this, query);

    /* If mount isn't returning anything with the iterator, check if there's
     * anything in the result list. */
    if (!result.hasNext && (r = corto_threadTlsGet(CORTO_KEY_MOUNT_RESULT))) {
        result = corto_ll_iterAlloc(r);
        result.release = corto_mount_queryRelease;
    }

    corto_threadTlsSet(CORTO_KEY_MOUNT_RESULT, prevResult);

    return result;
}

corto_object corto_mount_resume(
    corto_mount this,
    corto_string parent,
    corto_string name,
    corto_object o)
{
    /* If objects from mount are not owned locally they cannot be resumed */
    if (this->policy.ownership != CORTO_LOCAL_OWNER) {
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
        corto_query q;
        corto_bool newObject = FALSE;

        // Prepare request
        memset(&q, 0, sizeof(q));
        q.select = name;
        q.from = parent;
        if (o) {
            corto_fullpath(type, corto_typeof(o));
        } else {
            type[0] = '\0';
        }
        q.type = type;
        q.content = TRUE;

        // Request object from mount
        corto_debug("mount: try resume for '%s/%s' (mount = '%s')", parent, name, corto_fullpath(NULL, this));
        corto_resultIter it = corto_mount_query(this, &q);

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

                corto_id fullparent;
                sprintf(fullparent, "%s/%s", corto_subscriber(this)->query.from, iterResult->parent);
                corto_cleanpath(fullparent, fullparent);
                corto_object parent_o = corto_lookup(NULL, fullparent);
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
                    } else {
                        corto_seterr("unresolved type '%s' of object '%s' returned by '%s'",
                            iterResult->type,
                            iterResult->id,
                            corto_fullpath(NULL, this));
                        goto error;
                    }
                    corto_release(parent_o);
                } else {
                    corto_seterr("parent '%s' is not provided by any mount, cannot resume '%s/%s'",
                        fullparent,
                        parent,
                        name);
                    goto error;
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
        corto_debug("mount: resumed '%s/%s' from '%s'", parent, name, corto_fullpath(NULL, this));
    }

    return result;
error:
    return NULL;
}

void corto_mount_return(
    corto_mount this,
    corto_result *r)
{
    corto_ll result = corto_threadTlsGet(CORTO_KEY_MOUNT_RESULT);

    CORTO_UNUSED(this);

    if (!result) {
        result = corto_ll_new();
        corto_threadTlsSet(CORTO_KEY_MOUNT_RESULT, result);
    }

    corto_result *elem = corto_calloc(sizeof(corto_result));
    elem->id = corto_strdup(r->id);
    elem->name = corto_strdup(r->name);
    elem->parent = corto_strdup(r->parent);
    elem->type = corto_strdup(r->type);
    elem->value = (corto_word)r->value;
    elem->leaf = r->leaf;
    corto_ll_append(result, elem);

}

int16_t corto_mount_setContentType(
    corto_mount this,
    corto_string type)
{

    if (corto_mount_setContentTypeIn(this, type)) {
        goto error;
    }

    if (corto_mount_setContentTypeOut(this, type)) {
        goto error;
    }

    return 0;
error:
    return -1;
}

int16_t corto_mount_setContentTypeIn(
    corto_mount this,
    corto_string type)
{

    corto_ptr_setstr(&corto_subscriber(this)->contentType, type);
    corto_subscriber(this)->contentTypeHandle = (corto_word)corto_loadContentType(type);
    if (!corto_subscriber(this)->contentTypeHandle) {
        goto error;
    }

    return 0;
error:
    return -1;
}

int16_t corto_mount_setContentTypeOut(
    corto_mount this,
    corto_string type)
{

    corto_ptr_setstr(&this->contentTypeOut, type);
    this->contentTypeOutHandle = (corto_word)corto_loadContentType(type);
    if (!this->contentTypeOutHandle) {
        goto error;
    }

    return 0;
error:
    return -1;
}


static corto_mountSubscription* corto_mount_findSubscription(
    corto_mount this,
    corto_query *q,
    bool *found)
{
    *found = FALSE;
    corto_mountSubscription *result = NULL;

    corto_iter it = corto_ll_iter(this->subscriptions);
    while (corto_iter_hasNext(&it)) {
        corto_mountSubscription *s = corto_iter_next(&it);
        if (!stricmp(s->query.from, q->from)) {
             result = s;
             if (!stricmp(s->query.select, q->select)) {
                *found = TRUE;
                break;
            }
        }
    }

    return result;
}

void corto_mount_subscribe(
    corto_mount this,
    corto_query *query)
{
    corto_word ctx = 0;
    corto_mountSubscription *subscription = NULL, *placeHolder = NULL;
    bool found = FALSE;

    if (!this->hasSubscribe) {
        return;
    }

    if (corto_checkState(this, CORTO_DEFINED)) corto_lock(this);

    subscription = corto_mount_findSubscription(this, query, &found);
    if (subscription) {
        /* Ensure subscription isn't deleted outside of lock */
        subscription->count ++;
    } else {
        /* Add placeholder to list, so onSubscribe won't be called recursively */
        placeHolder = corto_calloc(sizeof(corto_mountSubscription));
        corto_ptr_copy(&placeHolder->query, corto_query_o, query);
        placeHolder->count = 1;
        corto_ll_append(this->subscriptions, placeHolder);
    }
    if (corto_checkState(this, CORTO_DEFINED)) corto_unlock(this);

    /* Process callback outside of lock */
    if (!found && (!subscription || subscription->ctx)) {
        /* If no subscription is found that both matches parent and expr, notify
         * the mount */
        ctx = corto_mount_onSubscribe(
          this,
          query,
          subscription ? subscription->ctx : 0);
    }

    /* Only add subscription if connection data is not null, no existing
     * subscription exists, and if context data differs from existing
     * subscription */
    if (ctx && (!subscription || (subscription->ctx != ctx))) {
        if (corto_checkState(this, CORTO_DEFINED)) corto_lock(this);

        /* If a new subscription is required, undo increase of refcount of the
         * subscription that was found */
        if (subscription) {
            subscription->count --;
        }

        /* Do lookup again, as list may have changed while mount was unlocked */
        subscription = corto_mount_findSubscription(this, query, &found);
        if (!found) {
            subscription = corto_calloc(sizeof(corto_mountSubscription));
            corto_ptr_copy(&subscription->query, corto_query_o, query);
            subscription->count = 1;
            corto_ll_append(this->subscriptions, subscription);
        } else if (subscription->ctx) {
            /* Increase refcount of new or existing subscription (can be new if
             * during the unlock a new subscription was added). */
            subscription->count ++;
        } else {
            /* If ctx is 0, this was a temporary entry in the subscriptions
             * list to prevent recursion. Since it will already have a count of
             * 1, don't increase refcount again as this would leak */
        }

        subscription->ctx = ctx;

        if (corto_checkState(this, CORTO_DEFINED))  corto_unlock(this);
    } else if (ctx && !found && subscription) {
        /* If there is no need to create a new subscription but no exact match
         * was found, it means that onSubscribe returned the same ctx as the
         * existing connection. In that case, the 'select' parameter of the
         * subscription is meaningless, so to avoid confusion set it to '*' 
         */
        if (corto_checkState(this, CORTO_DEFINED))  corto_lock(this);
        corto_ptr_setstr(&subscription->query.select, "*");

        /* Doesn't count as new subscription, so undo increase in refcount */
        subscription->count --;
        if (corto_checkState(this, CORTO_DEFINED)) corto_unlock(this);

    /* If placeholder was added & no (new) subscription is created, remove the
     * placeholder from the list */
    } else if (placeHolder) {
        if (corto_checkState(this, CORTO_DEFINED))  corto_lock(this);
        corto_ll_remove(this->subscriptions, placeHolder);
        corto_ptr_free(placeHolder, corto_mountSubscription_o);
        if (corto_checkState(this, CORTO_DEFINED)) corto_unlock(this);
    }

}

void corto_mount_unsubscribe(
    corto_mount this,
    corto_query *query)
{
    corto_mountSubscription *subscription = NULL;
    corto_bool found = FALSE;

    if (!this->hasSubscribe) {
        return;
    }

    corto_lock(this);
    subscription = corto_mount_findSubscription(this, query, &found);

    if (subscription) {
        if (! --subscription->count) {
            corto_ll_remove(this->subscriptions, subscription);
        } else {
            subscription = NULL;
        }
    }
    corto_unlock(this);


    if (subscription) {
        corto_mount_onUnsubscribe(
            this, 
            &subscription->query, 
            subscription->ctx);
        corto_ptr_deinit(subscription, corto_mountSubscription_o);
        corto_dealloc(subscription);
    }

}

