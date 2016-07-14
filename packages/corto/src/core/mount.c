/* $CORTO_GENERATED
 *
 * mount.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/core/core.h>

/* $header() */
#include "_object.h"
extern corto_int8 CORTO_OLS_REPLICATOR;
extern corto_threadKey CORTO_KEY_MOUNT_RESULT;

/* Add mount entry to object OLS */
corto_int16 corto_mount_attach(
    corto_mount this,
    corto_object o,
    corto_eventMask mask)
{
    corto_ll mounts = corto_olsLockGet(o, CORTO_OLS_REPLICATOR);
    corto_mount_olsData_t *data;

    if (!mounts) {
        mounts = corto_llNew();
    }

    if (corto_llSize(mounts) >= CORTO_MAX_REPLICATORS) {
        corto_seterr("maximum number of replicatos for scope set");
        corto_olsUnlockSet(o, CORTO_OLS_REPLICATOR, mounts);
        goto error;
    }

    data = corto_alloc(sizeof(corto_mount_olsData_t));
    data->mount = this;
    data->mask = mask;
    corto_llAppend(mounts, data);

    corto_olsUnlockSet(o, CORTO_OLS_REPLICATOR, mounts);

    return 0;
error:
    return -1;
}
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
/* $end */
corto_int16 _corto_mount_construct(
    corto_mount this)
{
/* $begin(corto/core/mount/construct) */

    /* If mount isn't set, and object is scoped, mount data on itself */
    if (!this->mount && corto_checkAttr(this, CORTO_ATTR_SCOPED)) {
        corto_setref(&this->mount, this);
    }

    corto_object observable = this->mount;
    corto_eventMask mask = this->mask;

    if (observable && mask) {
        /* Attach mount to the observable if mask != ON_SELF */
        if (mask != CORTO_ON_SELF) {
            if (corto_mount_attach(this, observable, mask)) {
                goto error;
            }
        }

        if (corto_listen(this, corto_mount_on_declare_o, CORTO_ON_DECLARE | mask, observable, this)) {
            goto error;
        }
        if (corto_listen(this, corto_mount_on_update_o, CORTO_ON_DEFINE | CORTO_ON_UPDATE | mask, observable, this)) {
            goto error;
        }
        if (corto_listen(this, corto_mount_on_delete_o, CORTO_ON_DELETE | mask, observable, this)) {
            goto error;
        }
    }

    /* Parse policies */
    if (this->policy) {
        corto_string value;
        void *policies = &this->policies;
        corto_asprintf(&value, "{%s}", this->policy);
        if (corto_fromStrp(&policies, corto_mountPolicy_o, value)) {
            corto_dealloc(value);
            goto error;
        }
        corto_dealloc(value);
    }

    /* If rate limiting is enabled, start thread */
    if (this->policies.sampleRate) {
        this->thread = (corto_word)corto_threadNew(
            corto_mount_thread,
            this);
    }

    return 0;
error:
    return -1;
/* $end */
}

corto_void _corto_mount_destruct(
    corto_mount this)
{
/* $begin(corto/core/mount/destruct) */
    corto_mountSubscription *s = NULL;

    while ((s = corto_llTakeFirst(this->subscriptions))) {
        corto_mount_onUnsubscribe(
            this,
            s->parent,
            s->expr,
            s->mask,
            s->userData);
        corto_deinitp(s, corto_mountSubscription_o);
        corto_dealloc(s);
    }

/* $end */
}

corto_int16 _corto_mount_init(
    corto_mount this)
{
/* $begin(corto/core/mount/init) */

    this->kind = CORTO_SOURCE;
    this->mask = CORTO_ON_SCOPE;

    return 0;
/* $end */
}

corto_void _corto_mount_invoke(
    corto_mount this,
    corto_object instance,
    corto_function proc,
    corto_word argptrs)
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

corto_void _corto_mount_on_declare(
    corto_mount this,
    corto_object observable)
{
/* $begin(corto/core/mount/on_declare) */

    if ((observable != root_o) && corto_checkAttr(observable, CORTO_ATTR_PERSISTENT)) {
        if (this->type) {
            corto_id srcType; corto_fullpath(srcType, corto_typeof(observable));
            if (!strcmp(this->type, srcType)) {
                this->sent.declares ++;
                corto_mount_onDeclare(this, observable);
            }
        } else {
            this->sent.declares ++;
            corto_mount_onDeclare(this, observable);
        }
    }

/* $end */
}

corto_void _corto_mount_on_delete(
    corto_mount this,
    corto_object observable)
{
/* $begin(corto/core/mount/on_delete) */

    if (corto_checkAttr(observable, CORTO_ATTR_PERSISTENT)) {
        if (this->type) {
            corto_id srcType; corto_fullpath(srcType, corto_typeof(observable));
            if (!strcmp(this->type, srcType)) {
                this->sent.deletes ++;
                corto_mount_onDelete(this, observable);
            }
        } else {
            this->sent.deletes ++;
            corto_mount_onDelete(this, observable);
        }
    }

/* $end */
}

corto_void _corto_mount_on_update(
    corto_mount this,
    corto_object observable)
{
/* $begin(corto/core/mount/on_update) */

    if (corto_checkAttr(observable, CORTO_ATTR_PERSISTENT)) {
        if (this->type) {
            corto_id srcType; corto_fullpath(srcType, corto_typeof(observable));
            if (!strcmp(this->type, srcType)) {
                this->sent.updates ++;
                corto_mount_onUpdate(this, observable);
            }
        } else {
            this->sent.updates ++;
            corto_mount_onUpdate(this, observable);
        }
    }

/* $end */
}

corto_void _corto_mount_onDeclare_v(
    corto_mount this,
    corto_object observable)
{
/* $begin(corto/core/mount/onDeclare) */
    CORTO_UNUSED(observable);

    /* If mount doesn't implement onDeclare, nothing has been sent */
    this->sent.declares --;

/* $end */
}

corto_void _corto_mount_onDelete_v(
    corto_mount this,
    corto_object observable)
{
/* $begin(corto/core/mount/onDelete) */
    CORTO_UNUSED(observable);

    /* If mount doesn't implement onDelete, nothing has been sent */
    this->sent.deletes --;

/* $end */
}

corto_void _corto_mount_onInvoke_v(
    corto_mount this,
    corto_object instance,
    corto_function proc,
    corto_word argptrs)
{
/* $begin(corto/core/mount/onInvoke) */

    CORTO_UNUSED(this);
    CORTO_UNUSED(instance);
    CORTO_UNUSED(proc);
    CORTO_UNUSED(argptrs);

/* $end */
}

corto_void _corto_mount_onPoll_v(
    corto_mount this)
{
/* $begin(corto/core/mount/onPoll) */
    corto_event e;
    corto_ll events = corto_llNew();

    /* Collect events */
    corto_lock(this);
    while ((e = corto_llTakeFirst(this->events))) {
        corto_llAppend(events, e);
    }
    corto_unlock(this);

    /* Handle events outside of lock */
    while ((e = corto_llTakeFirst(events))) {
        corto_event_handle(e);
        corto_release(e);
    }

    corto_llFree(events);
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

corto_word _corto_mount_onSubscribe_v(
    corto_mount this,
    corto_string parent,
    corto_string name,
    corto_eventMask mask)
{
/* $begin(corto/core/mount/onSubscribe) */
    CORTO_UNUSED(this);
    CORTO_UNUSED(parent);
    CORTO_UNUSED(name);
    CORTO_UNUSED(mask);

    return 0;
/* $end */
}

corto_void _corto_mount_onUnsubscribe_v(
    corto_mount this,
    corto_string parent,
    corto_string name,
    corto_eventMask mask,
    corto_word userData)
{
/* $begin(corto/core/mount/onUnsubscribe) */
    CORTO_UNUSED(this);
    CORTO_UNUSED(parent);
    CORTO_UNUSED(name);
    CORTO_UNUSED(mask);
    CORTO_UNUSED(userData);

/* $end */
}

corto_void _corto_mount_onUpdate_v(
    corto_mount this,
    corto_object observable)
{
/* $begin(corto/core/mount/onUpdate) */
    CORTO_UNUSED(observable);

    /* If mount doesn't implement onUpdate, nothing has been sent */
    this->sent.updates --;

/* $end */
}

/* $header(corto/core/mount/post) */
static corto_observableEvent corto_mount_findEvent(corto_mount this, corto_observableEvent e) {
    corto_iter iter = corto_llIter(this->events);
    corto_observableEvent e2;
    while ((corto_iterHasNext(&iter))) {
        e2 = corto_iterNext(&iter);
        if ((e2->me == e->me) &&
          (e2->observable == e->observable) &&
          (e2->source == e->source) &&
          (e2->observer == e->observer)) {
            return e2;
        }
    }
    return NULL;
}

#define MOUNT_QUEUE_THRESHOLD 100
#define MOUNT_QUEUE_THRESHOLD_SLEEP 10000000

/* $end */
corto_void _corto_mount_post(
    corto_mount this,
    corto_event e)
{
/* $begin(corto/core/mount/post) */

    /* If sampleRate != 0, post event to list. Another thread will process it
     * at the specified rate. */
    if (this->policies.sampleRate) {
        corto_uint32 size = 0;
        corto_observableEvent e2;

        /* Append new event to queue */
        corto_lock(this);

        /* Check if there is already another event in the queue for the same object.
         * if so, replace event with latest update. */
        if ((e2 = corto_mount_findEvent(this, corto_observableEvent(e)))) {
            corto_llReplace(this->events, e2, e);
            if (e2->mask & CORTO_ON_DECLARE) this->sentDiscarded.declares++;
            if (e2->mask & (CORTO_ON_DEFINE | CORTO_ON_UPDATE)) this->sentDiscarded.updates++;
            if (e2->mask & CORTO_ON_DELETE) this->sentDiscarded.deletes++;
            corto_release(e2);
        } else {
            corto_llAppend(this->events, e);
        }

        size = corto_llSize(this->events);
        corto_unlock(this);

        /* If queue is getting big, slow down publisher */
        if (size > MOUNT_QUEUE_THRESHOLD) {
            corto_sleep(0, MOUNT_QUEUE_THRESHOLD_SLEEP);
        }
    } else {
        corto_event_handle(e);
        corto_release(e);
    }

/* $end */
}

/* $header(corto/core/mount/request) */
void corto_mount_requestRelease(corto_iter *iter) {
    corto_llIter_s *data = iter->udata;
    corto_resultListClear(data->list);
    corto_llFree(data->list);
    corto_llIterRelease(iter);
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
        result = corto_llIterAlloc(r);
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
    /* Ensure that if object is created, owner & attributes are set correctly */
    corto_attr prevAttr = corto_setAttr(CORTO_ATTR_PERSISTENT | corto_getAttr());
    corto_object prevOwner = corto_setOwner(this);

    /* Resume object */
    corto_object result = corto_mount_onResume(this, parent, name, o);

    /* Restore owner & attributes */
    corto_setAttr(prevAttr);
    corto_setOwner(prevOwner);

    return result;
/* $end */
}

corto_void _corto_mount_return(
    corto_mount this,
    corto_result *r)
{
/* $begin(corto/core/mount/return) */
    corto_ll result = corto_threadTlsGet(CORTO_KEY_MOUNT_RESULT);

    CORTO_UNUSED(this);

    if (!result) {
        result = corto_llNew();
        corto_threadTlsSet(CORTO_KEY_MOUNT_RESULT, result);
    }

    /* Create and initialize new result element */
    corto_resultAssign(
        corto_resultListAppendAlloc(result),
        r->id,
        r->name,
        r->parent,
        r->type,
        r->value
    );

/* $end */
}

corto_int16 _corto_mount_setContentType(
    corto_mount this,
    corto_string type)
{
/* $begin(corto/core/mount/setContentType) */
    corto_setstr(&this->contentType, type);
    return 0;
/* $end */
}

corto_void _corto_mount_subscribe(
    corto_mount this,
    corto_string parent,
    corto_string name,
    corto_eventMask mask)
{
/* $begin(corto/core/mount/subscribe) */
    corto_bool found = FALSE;
    corto_mountSubscription *newSubscription = NULL;

    corto_lock(this);
    corto_mountSubscriptionListForeach(this->subscriptions, s) {
        if (!strcmp(s->parent, parent) &&
            !strcmp(s->expr, name) &&
            s->mask == mask)
        {
            s->count ++;
            found = TRUE;
            break;
        }
    }
    if (!found) {
        newSubscription = corto_mountSubscriptionListAppendAlloc(
            this->subscriptions);

        corto_mountSubscriptionAssign(
            newSubscription,
            parent,
            name,
            mask,
            1,
            0);
    }
    corto_unlock(this);

    if (newSubscription) {
        newSubscription->userData = corto_mount_onSubscribe(
            this, parent, name, mask);
    }

/* $end */
}

corto_void _corto_mount_unsubscribe(
    corto_mount this,
    corto_string parent,
    corto_string name,
    corto_eventMask mask)
{
/* $begin(corto/core/mount/unsubscribe) */
    corto_mountSubscription *found = NULL;

    corto_lock(this);
    corto_mountSubscriptionListForeach(this->subscriptions, s) {
        if (!strcmp(s->parent, parent) &&
            !strcmp(s->expr, name) &&
            s->mask == mask)
        {
            found = s;
            break;
        }
    }
    if (found) {
        if (! --found->count) {
            corto_llRemove(this->subscriptions, found);
        } else {
            found = NULL;
        }
    }
    corto_unlock(this);

    if (found) {
        corto_mount_onUnsubscribe(this, parent, name, mask, found->userData);
        corto_deinitp(found, corto_mountSubscription_o);
        corto_dealloc(found);
    }

/* $end */
}
