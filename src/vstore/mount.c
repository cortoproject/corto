/* This is a managed file. Do not delete this comment. */

#include <corto/corto.h>
#include "src/store/object.h"
extern corto_tls CORTO_KEY_MOUNT_RESULT;
corto_entityAdmin corto_mount_admin = {
    .key = 0,
    .count = 0,
    .lock = CORTO_RWMUTEX_INITIALIZER,
    .changed = 0
};

void corto_mount_subscribeOrMount(
    corto_mount this,
    corto_query *query,
    bool subscribe,
    bool mount);

void corto_mount_unsubscribeOrUnmount(
    corto_mount this,
    corto_query *query,
    bool subscribe,
    bool mount);

static corto_time corto_mount_doubleToTime(double frequency) {
    corto_time result;
    result.sec = frequency;
    frequency -= result.sec;
    if (frequency >= 0) {
        result.nanosec = frequency * 1000000000.0;
    }

    return result;
}

void* corto_mount_thread(void* arg) {
    corto_mount this = arg;
    corto_float64 frequency = this->policy.sampleRate;
    corto_time interval = corto_mount_doubleToTime(1.0 / frequency);
    corto_time next, current, sleep = {0, 0}, lastSleep = {0, 0};
    corto_time_get(&next);
    next = corto_time_add(next, interval);
    while (!this->quit) {
        corto_mount_onPoll(this);
        corto_time_get(&current);
        lastSleep = sleep;
        sleep = corto_time_sub(next, current);
        if (lastSleep.sec || lastSleep.nanosec) {
            /* Attempt to limit the amount of oscillation in a fully loaded system */
            if (corto_time_compare(lastSleep, sleep) == CORTO_LT) {
                double tmp = (corto_time_toDouble(sleep) + corto_time_toDouble(lastSleep)) / 2;
                sleep = corto_mount_doubleToTime(tmp);
            }

        }

        if (sleep.sec >= 0) {
            corto_sleep(sleep.sec, sleep.nanosec);
        } else {
            sleep = corto_time_sub(current, next);
            corto_warning(
                "processing events took [%d.%.9d] longer than sampleRate interval",
                sleep.sec, sleep.nanosec);
            corto_time_get(&next);
        }

        next = corto_time_add(next, interval);
    }

    return NULL;
}

void corto_mount_notify(corto_subscriberEvent *e) {
    corto_mount this = (corto_mount)e->subscriber;
    corto_eventMask event = e->event;
    corto_result *r = &e->data;

    if (!r->object || (!this->attr || corto_check_attr(r->object, this->attr))) {
        if (this->policy.mask & CORTO_MOUNT_NOTIFY) {
            corto_mount_on_notify(this, e);
        }

        switch(event) {
        case CORTO_DEFINE:
            if (this->policy.mask & CORTO_MOUNT_MOUNT) {
                corto_query q = {
                    .select = e->data.id,
                    .from = e->data.parent
                };
                if (r->object) {
                    corto_mount_subscribeOrMount(this, &q, false, true);
                }

            }

            break;
        case CORTO_UPDATE:
            break;
        case CORTO_DELETE:
            if (this->policy.mask & CORTO_MOUNT_MOUNT) {
                corto_query q = {
                    .select = e->data.id,
                    .from = e->data.parent
                };
                if (r->object) {
                    corto_mount_unsubscribeOrUnmount(this, &q, false, true);
                }

            }

            break;
        default:
            break;
        }

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
    if (!this->mount && corto_check_attr(this, CORTO_ATTR_NAMED) && !s->query.from) {
        corto_set_ref(&this->mount, this);
    }

    if (this->mount) {
        corto_set_str(&s->query.from, corto_fullpath(NULL, this->mount));
    } else if (s->query.from) {
        this->mount = corto(CORTO_LOOKUP, {.id = s->query.from});
    }

    corto_eventMask mask = corto_observer(this)->mask;
    /* If parent is set, resolve it and assign mount */
    if (!s->query.select) {
        /* Set the expression according to the mask */
        if (mask & CORTO_ON_TREE) {
            corto_set_str(&s->query.select, "//");
        } else if (mask & CORTO_ON_SCOPE) {
            corto_set_str(&s->query.select, "/");
        } else if (mask & CORTO_ON_SELF) {
            corto_set_str(&s->query.select, ".");
        } else {
            corto_set_str(&s->query.select, "/");
        }

    }

    /* Parse policies */
    if (this->policy.sampleRate) {
        dispatcher = this;
        this->thread = (corto_word)corto_thread_new(
            corto_mount_thread,
            this);
    }

    /* If mount doesn't implement on_query, it is a passthrough mount meaning
     * it uses the object store. */
    if (!corto_mount_hasMethod(this, "on_query")) {
        this->passThrough = TRUE;
    }

    /* If mount has explicit on_resume function, don't call on_query when resuming
     * objects */
    if (corto_mount_hasMethod(this, "on_resume")) {
        this->explicitResume = true;
    }

    /* Disable flags if mount does not implement method. This allows the rest of
     * the code to check for just the flags, instead of looking up the method. */
    if (!corto_mount_hasMethod(this, "on_history_query")) {
        this->policy.mask &= ~CORTO_MOUNT_HISTORY_QUERY;
    }

    if (!corto_mount_hasMethod(this, "on_notify")) {
        this->policy.mask &= ~CORTO_MOUNT_NOTIFY;
    }

    if (!corto_mount_hasMethod(this, "on_batch_notify")) {
        this->policy.mask &= ~CORTO_MOUNT_BATCH_NOTIFY;
    }

    if (!corto_mount_hasMethod(this, "on_history_batch_notify")) {
        this->policy.mask &= ~CORTO_MOUNT_HISTORY_BATCH_NOTIFY;
    }

    if (!corto_mount_hasMethod(this, "on_invoke")) {
        this->policy.mask &= ~CORTO_MOUNT_INVOKE;
    }

    if (!corto_mount_hasMethod(this, "on_subscribe")) {
        this->policy.mask &= ~CORTO_MOUNT_SUBSCRIBE;
    }

    if (!corto_mount_hasMethod(this, "on_mount")) {
        this->policy.mask &= ~CORTO_MOUNT_MOUNT;
    }

    if (!corto_mount_hasMethod(this, "on_id")) {
        this->policy.mask &= ~CORTO_MOUNT_ID;
    }

    /* Set the callback function */
    corto_function(this)->kind = CORTO_PROCEDURE_CDECL;
    corto_function(this)->fptr = (corto_word)corto_mount_notify;
    corto_set_ref(&corto_observer(this)->instance, this);
    corto_set_ref(&corto_observer(this)->dispatcher, dispatcher);
    /* Enable subscriber only when mount implements on_notify */
    if (this->policy.mask & CORTO_MOUNT_NOTIFY ||
        this->policy.mask & CORTO_MOUNT_BATCH_NOTIFY ||
        this->policy.mask & CORTO_MOUNT_HISTORY_BATCH_NOTIFY ||
        this->policy.mask & CORTO_MOUNT_MOUNT) {
        corto_observer(this)->enabled = TRUE;
    }

    corto_observer(this)->mask |=
      CORTO_DECLARE|CORTO_DEFINE|CORTO_UPDATE|CORTO_DELETE;
    if (!s->query.select) {
        corto_set_str(&s->query.select, "//");
    }

    if (s->contentType)
    {
        if (!s->contentTypeHandle) {
            corto_mount_setContentTypeIn(this, s->contentType);
        }

        if (!this->contentTypeOutHandle) {
            corto_mount_setContentTypeOut(this, s->contentType);
        }

    }

    /* Add mount to mount admin so it can be found by corto_select */
    corto_entityAdmin_add(&corto_mount_admin, s->query.from, this, this);
    /* If mount is interested in subscriptions, align from existing subscribers */
    if (this->policy.mask & (CORTO_MOUNT_SUBSCRIBE|CORTO_MOUNT_MOUNT))
    {
        if (corto_mount_alignSubscriptions(this)) {
            goto error;
        }

    }

    corto_int16 ret = safe_corto_subscriber_construct(this);
    if (ret) {
        corto_entityAdmin_remove(&corto_mount_admin, s->query.from, this, this, FALSE);
    } else {
        /* Make it easy to see whether this mount observes a tree, scope or self */
        int scope = corto_idmatch_get_scope(
            (corto_idmatch_program)corto_subscriber(this)->idmatch);

        corto_observer(this)->mask = scope == 2 ? CORTO_ON_TREE
                                   : scope == 1 ? CORTO_ON_SCOPE
                                                : CORTO_ON_SELF;
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
        corto_mount_on_unsubscribe(
            this,
            &s->query,
            s->subscriberCtx);
        corto_ptr_deinit(s, corto_mountSubscription_o);
        corto_dealloc(s);
    }

    if (this->thread) {
        corto_thread_join((corto_thread)this->thread, NULL);
    }

    if (corto_ll_count(this->events)) {
        corto_trace("there were %d events left in the mount event queue",
            corto_ll_count(this->events));
    }

    if (corto_ll_count(this->historicalEvents)) {
        corto_trace("there were %d historical events left in the mount event queue",
            corto_ll_count(this->historicalEvents));
    }

    safe_corto_subscriber_destruct(this);
    corto_assert(
        corto_entityAdmin_remove(&corto_mount_admin, this->super.query.from, this, this, FALSE) != -1,
        "trying to remove mount that was never added to mountAdmin");
}

corto_string corto_mount_id(
    corto_mount this)
{
    return corto_mount_on_id(this);
}

int16_t corto_mount_init(
    corto_mount this)
{
    this->policy.ownership = CORTO_REMOTE_SOURCE;

    /* Mount doesn't need to implement a resume callback to resume objects */
    this->policy.mask |= CORTO_MOUNT_RESUME;

    /* Enable default flags based on which methods are implemented */
    if (corto_mount_hasMethod(this, "on_query")) {
        this->policy.mask |= CORTO_MOUNT_QUERY;
    }

    if (corto_mount_hasMethod(this, "on_id")) {
        this->policy.mask |= CORTO_MOUNT_ID;
    }

    if (corto_mount_hasMethod(this, "on_history_query")) {
        this->policy.mask |= CORTO_MOUNT_HISTORY_QUERY;
    }

    if (corto_mount_hasMethod(this, "on_notify")) {
        this->policy.mask |= CORTO_MOUNT_NOTIFY;
    }

    if (corto_mount_hasMethod(this, "on_batch_notify")) {
        this->policy.mask |= CORTO_MOUNT_BATCH_NOTIFY;
    }

    if (corto_mount_hasMethod(this, "on_history_batch_notify")) {
        this->policy.mask |= CORTO_MOUNT_HISTORY_BATCH_NOTIFY;
    }

    if (corto_mount_hasMethod(this, "on_invoke")) {
        this->policy.mask |= CORTO_MOUNT_INVOKE;
    }

    if (corto_mount_hasMethod(this, "on_subscribe")) {
        this->policy.mask |= CORTO_MOUNT_SUBSCRIBE;
    }

    if (corto_mount_hasMethod(this, "on_mount")) {
        this->policy.mask |= CORTO_MOUNT_MOUNT;
    }

    this->policy.sampleRate = 0;
    this->policy.expiryTime = -1;
    this->policy.filterResults = true;
    this->attr = CORTO_ATTR_PERSISTENT;
    return safe_corto_subscriber_init(this);
}

void corto_mount_invoke(
    corto_mount this,
    corto_object instance,
    corto_function proc,
    uintptr_t argptrs)
{
    corto_object owner = corto_sourceof(instance);

    if (owner == this) {
        corto_mount_on_invoke(this, instance, proc, argptrs);
    } else {
        corto_object prevowner = corto_set_source(corto_sourceof(instance));
        corto_invokeb(proc, NULL, (void**)argptrs);
        corto_set_source(prevowner);
    }

}

corto_string corto_mount_on_id_v(
    corto_mount this)
{
    CORTO_UNUSED(this);
    return NULL;
}

void corto_mount_on_invoke_v(
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

void corto_mount_on_notify_v(
    corto_mount this,
    corto_subscriberEvent *event)
{
    CORTO_UNUSED(this);
    CORTO_UNUSED(event);
}

void corto_mount_onPoll(
    corto_mount this)
{
    corto_event *e;
    corto_ll events = NULL, historicalEvents = NULL;

    /* Collect events */
    if (corto_lock(this)) {
        corto_throw(NULL);
        corto_raise();
    }

    corto_time_get(&this->lastPoll);
    this->lastQueueSize = 0;
    if (corto_ll_count(this->events)) {
        events = corto_ll_new();
        while ((e = corto_ll_takeFirst(this->events))) {
            corto_ll_append(events, e);
        }

    }

    if (corto_ll_count(this->historicalEvents)) {
        historicalEvents = corto_ll_new();
        while ((e = corto_ll_takeFirst(this->historicalEvents))) {
            corto_ll_append(historicalEvents, e);
        }

    }

    if (corto_unlock(this)) {
        corto_throw(NULL);
        corto_raise();
    }

    /* If batching is enabled, call on_batch_notify */
    if (events && this->policy.mask & CORTO_MOUNT_BATCH_NOTIFY) {
        corto_iter it = corto_ll_iter(events);
        corto_mount_on_batch_notify(this, it);
    }

    /* If batching of historical data is enabled, call on_history_batch_notify */
    if (historicalEvents && this->policy.mask & CORTO_MOUNT_HISTORY_BATCH_NOTIFY) {
        corto_iter it = corto_ll_iter(historicalEvents);
        corto_mount_on_history_batch_notify(this, it);
        it = corto_ll_iter(historicalEvents);
        while (corto_iter_hasNext(&it)) {
            corto_event *e = corto_iter_next(&it);
            corto_release(e);
        }

        corto_ll_free(historicalEvents);
    }

    /* Default event handler */
    if (events) {
        while ((e = corto_ll_takeFirst(events))) {
            corto_mount_notify((corto_subscriberEvent*)e);
            corto_assert(corto_release(e) == 0, "event is leaking");
        }

        corto_ll_free(events);
    }

}

static
int corto_mount_findEvent(
    void *o1,
    void *o2)
{
    corto_subscriberEvent *e1 = o1, *e2 = o2;
    if (!strcmp(e2->data.id, e1->data.id) &&
        !strcmp(e2->data.parent, e1->data.parent) &&
        (e2->subscriber == e1->subscriber))
    {
        return false;
    }

    return true;
}

void corto_mount_post(
    corto_mount this,
    corto_event *e)
{
    int size = 0;
    corto_time lastPoll = {0, 0};
    int lastQueueSize = 0;
    /* If sampleRate != 0, post event to list. Another thread will process it
     * at the specified rate. */
    if (this->policy.mask & (CORTO_MOUNT_NOTIFY | CORTO_MOUNT_BATCH_NOTIFY | CORTO_MOUNT_HISTORY_BATCH_NOTIFY))
    {
        if (this->policy.sampleRate)
        {
            /* Keep track of how often an event is added to a queue. If added to
             * only one queue, refcount does not need to be increased. If added
             * to two queues, refcount must be increased. */
            int appended = 0;
            /* Append new event to queue */
            if (corto_lock(this)) {
                corto_throw(NULL);
                corto_raise();
            }

            /* Retrieve last poll time within lock */
            lastPoll = this->lastPoll;
            lastQueueSize = this->lastQueueSize;
            if (this->policy.mask & CORTO_MOUNT_HISTORY_BATCH_NOTIFY) {
                corto_ll_append(this->historicalEvents, e);
                appended ++;
                size = corto_ll_count(this->historicalEvents);
            }

            if (this->policy.mask & (CORTO_MOUNT_NOTIFY | CORTO_MOUNT_BATCH_NOTIFY)) {
                /* Check if there is already another event in the queue for the same object.
                 * if so, replace event with latest update. */
                void *ptr = corto_ll_findPtr(this->events, corto_mount_findEvent, e);
                if (ptr) {
                    corto_release(*(void**)ptr);
                    *(void**)ptr = e;
                } else {
                    corto_ll_append(this->events, e);
                    appended ++;
                }

                if (!size) {
                    size = corto_ll_count(this->events);
                }

            }

            if (appended == 2) {
                corto_claim(e);
            }

            if (corto_unlock(this)) {
                corto_throw(NULL);
                corto_raise();
            }

        } else {
            corto_event_handle(e);
            corto_assert(corto_release(e) == 0, "event is leaking");
        }

    }

    /* If queue.max is not specified, don't throttle */
    if (!this->policy.queue.max) {
        return;
    }

    /* collectCount determines how often the algorithm will evaluate the delay
     * required for throttling. Because calculating delay requires getting the
     * current time, this would be too expensive to do for every event. Instead
     * it is determined adaptively. A risk is that this thread is very busy, and
     * is keeping the poll thread from being scheduled in. To ensure that this
     * is kept to a minimum, checking is done more often towards the end of a
     * cycle. If this thread notices time has moved past last poll time + 1 / Sr
     * it should stop until the poll thread has been scheduled in again. */
    int collectCount = (this->policy.queue.max / 10);
    if (collectCount < 2) collectCount = 2;
    if (collectCount > 10) collectCount = 10;
    /** Throttling algorithm that spreads delays evenly between events.
     * A simple throttling algorithm would block a publisher once the queue.max
     * has been reached. That is undesirable, because that way there would be
     * (queue.max - 1) updates that are very fast, and 1 update that is very
     * slow. If data collection happens at the same time an update is done, this
     * would result in a very uneven dataset.
     *
     * The purpose of this algorithm is to spread delays evenly between updates
     * so that for the application, every update takes approximately the "same"
     * time (within one order of magnitude).
     *
     * The algorithm looks if the frequency at which the application publishes
     * events is going to exceed queue.max for the current poll cycle. If it
     * does not exceed the max, there will be no delay.
     *
     * If the number of events is going to exceed queue.max, the algorithm looks
     * at how much time is left in the current period, and how many samples
     * still can be written before the max is reached. Based on this, an average
     * delay is computed per sample to be written.
     *
     * The algorithm works best in stable systems, where an application is
     * publishing at a fixed rate. To handle situations where an application is
     * not stable (worst case: starts publishing faster at the end of a cycle)
     * the throttling algorithm will block for as long as the current queue size
     * equals queue.max.
     *
     * The algorithm parameters are reset at the beginning of each poll cycle,
     * so that it can adapt fast to changing behavior of the application.
     */
    if (size > collectCount && size < this->policy.queue.max) {
        /* Retrieve time every collectCount samples */
        if (!lastQueueSize || !(size % collectCount)) {
            corto_time_get(&this->lastPost);
            /* Calculate total available time per period */
            corto_time totalTime = corto_mount_doubleToTime(1.0 / this->policy.sampleRate);
            corto_time spent = lastPoll.sec
                ? corto_time_sub(this->lastPost, lastPoll)
                : (corto_time){0, 0}

                ;
            if (corto_time_compare(spent, totalTime) == CORTO_LT) {
                /* Calculate last recorded write frequency */
                double writeFrequency = size / corto_time_toDouble(spent);
                /* Calculate if number of samples exceeds max if continuing to write at
                 * this frequency */
                if (lastQueueSize || (writeFrequency * corto_time_toDouble(totalTime) > this->policy.queue.max)) {
                    /* Need to throttle. Calculate how much publisher needs to slow down */
                    corto_time budget = corto_time_sub(totalTime, spent);
                    /* Calculate time available per remaining sample, which is the time
                     * we should sleep to slow down the publisher. Add one
                     * sample for error margin so that in a stable system
                     * each poll cycle receives exactly the max queue size. */
                    double timePerSample =
                        corto_time_toDouble(budget) / ((double)this->policy.queue.max - (double)size + collectCount);
                    /*printf("sleep: %d.%.9d budget=[%d.%.9d] spent=[%d.%.9d] size=%d timePerSample=%f\n",
                        this->lastSleep.sec, this->lastSleep.nanosec,
                        budget.sec, budget.nanosec,
                        spent.sec, spent.nanosec,
                        size,
                        timePerSample);*/
                    this->lastSleep = corto_mount_doubleToTime(timePerSample);
                    this->dueSleep = (corto_time){0, 0};
                } else {
                    this->lastSleep.sec = 0;
                    this->lastSleep.nanosec = 0;
                }

            } else {
                /* If time spent in current period exceeds total period time,
                 * the OS scheduler is lagging. In that case block, as it might
                 * be this thread that is holding up the poll thread. */
                do {
                    corto_sleep(0, 1000000);
                } while ((lastPoll.nanosec == this->lastPoll.nanosec) ||
                         (lastPoll.nanosec == this->lastPoll.nanosec));
                this->lastSleep.sec = 0;
                this->lastSleep.nanosec = 0;
                this->dueSleep.sec = 0;
                this->dueSleep.nanosec = 0;
            }

            this->lastQueueSize = size;
        }

        /* If sleep time is less than a millisecond, accuracy of a sleep is not
         * good enough due to OS scheduler variation. Instead, accumulate sleep
         * until it is larger than a millisecond, then sleep. */
        this->dueSleep = corto_time_add(this->dueSleep, this->lastSleep);
        if (this->dueSleep.sec || this->dueSleep.nanosec > 10000000) {
            corto_sleep(this->dueSleep.sec, this->dueSleep.nanosec);
            this->dueSleep = (corto_time){0, 0};
        }

    }

    /* If size is equal to max, block until queue is emptied */
    if (size == this->policy.queue.max) {
        do {
            corto_sleep(0, 1000000); /* fast loop to minimize blocking time */
            corto_lock(this);
            if (this->policy.mask & CORTO_MOUNT_HISTORY_BATCH_NOTIFY) {
                size = corto_ll_count(this->historicalEvents);
            } else {
                size = corto_ll_count(this->events);
            }

            corto_unlock(this);
        } while (size == this->policy.queue.max);
    }

}

corto_resultIter corto_mount_on_query_v(
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
        if (!strcmp(query->from, ".")) {
            sprintf(routerRequest, "/");
        } else {
            sprintf(routerRequest, "/%s", query->from);
        }

        corto_path_clean(routerRequest, routerRequest);
        if (corto_router_match(this, routerRequest, routerParam, routerResult, NULL)) {
            corto_raise();
        }

    }

    return result;
}

corto_object corto_mount_on_resume_v(
    corto_mount this,
    const char *parent,
    const char *id,
    corto_object object)
{
    CORTO_UNUSED(this);
    CORTO_UNUSED(parent);
    CORTO_UNUSED(id);
    CORTO_UNUSED(object);

    return NULL;
}

uintptr_t corto_mount_on_subscribe_v(
    corto_mount this,
    corto_query *query,
    uintptr_t ctx)
{
    CORTO_UNUSED(this);
    CORTO_UNUSED(query);
    CORTO_UNUSED(ctx);

    return 0;
}

uintptr_t corto_mount_on_transaction_begin_v(
    corto_mount this)
{

    CORTO_UNUSED(this);
    return 0;
}

void corto_mount_on_transaction_end_v(
    corto_mount this,
    corto_subscriberEventIter events,
    uintptr_t ctx)
{

    CORTO_UNUSED(this);
    CORTO_UNUSED(events);
    CORTO_UNUSED(ctx);

}

void corto_mount_on_unsubscribe_v(
    corto_mount this,
    corto_query *query,
    uintptr_t ctx)
{
    CORTO_UNUSED(this);
    CORTO_UNUSED(query);
    CORTO_UNUSED(ctx);

}

void corto_mount_publish(
    corto_mount this,
    corto_eventMask event,
    const char *from,
    const char *id,
    const char *type,
    uintptr_t value)
{
    corto_id identifier;
    sprintf(identifier, "%s/%s/%s", corto_subscriber(this)->query.from, from, id);
    corto_path_clean(identifier, identifier);

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
    corto_ll r, prevResult = corto_tls_get(CORTO_KEY_MOUNT_RESULT);
    corto_tls_set(CORTO_KEY_MOUNT_RESULT, NULL);

    result = corto_mount_on_query(this, query);

    /* If mount isn't returning anything with the iterator, check if there's
     * anything in the result list. */
    if (!result.hasNext && (r = corto_tls_get(CORTO_KEY_MOUNT_RESULT))) {
        result = corto_ll_iterAlloc(r);
        result.release = corto_mount_queryRelease;
    }

    corto_tls_set(CORTO_KEY_MOUNT_RESULT, prevResult);
    return result;
}

corto_resultIter corto_mount_historyQuery(
    corto_mount this,
    corto_query *query)
{
    corto_iter result;
    corto_ll r, prevResult = corto_tls_get(CORTO_KEY_MOUNT_RESULT);
    corto_tls_set(CORTO_KEY_MOUNT_RESULT, NULL);

    result = corto_mount_on_history_query(this, query);

    /* If mount isn't returning anything with the iterator, check if there's
     * anything in the result list. */
    if (!result.hasNext && (r = corto_tls_get(CORTO_KEY_MOUNT_RESULT))) {
        result = corto_ll_iterAlloc(r);
        result.release = corto_mount_queryRelease;
    }

    corto_tls_set(CORTO_KEY_MOUNT_RESULT, prevResult);
    return result;
}

corto_object corto_mount_resume(
    corto_mount this,
    const char *parent,
    const char *name,
    corto_object o)
{
    /* If objects from mount are not owned locally they cannot be resumed */
    if (this->policy.ownership != CORTO_LOCAL_SOURCE) {
        return NULL;
    }

    corto_log_push(strarg("resume:%s/%s", parent, name));

    /* Ensure that if object is created, owner & attributes are set correctly */
    corto_attr prevAttr = corto_set_attr(CORTO_ATTR_PERSISTENT | corto_get_attr());
    corto_object prevOwner = corto_set_source(this);
    corto_object result = NULL;

    /* Resume object */
    if (this->explicitResume) {
        corto_debug("mount: on_resume parent=%s, expr=%s (mount = %s, o = %p)", parent, name, corto_fullpath(NULL, this), o);
        result = corto_mount_on_resume(this, parent, name, o);
    } else {
        corto_id type;
        corto_query q;
        corto_bool newObject = FALSE;
        // Prepare request
        memset(&q, 0, sizeof(q));
        q.select = (char*)name;
        q.from = (char*)parent;
        if (o) {
            corto_fullpath(type, corto_typeof(o));
        } else {
            type[0] = '\0';
        }

        q.type = type;
        q.content = TRUE;
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

                corto_id fullpath;
                sprintf(fullpath, "%s/%s/%s", corto_subscriber(this)->query.from, iterResult->parent, iterResult->id);
                corto_path_clean(fullpath, fullpath);
                corto_object type_o = corto_resolve(NULL, iterResult->type);
                if (type_o) {
                    o = corto_declare(root_o, fullpath, type_o);
                    if (!o) {
                        corto_throw("failed to create object %s/%s",
                          parent, name);
                    }

                    newObject = TRUE;
                    corto_release(type_o);
                } else {
                    corto_throw("unresolved type '%s' of object '%s' returned by '%s'",
                        iterResult->type,
                        iterResult->id,
                        corto_fullpath(NULL, this));
                    goto error;
                }

            }

            if (o) {
                corto_value v = corto_value_object(o, NULL);
                if (this->contentTypeOutHandle && iterResult->value) {
                    ((corto_fmt)this->contentTypeOutHandle)->toValue(
                        &v, iterResult->value);
                }

                if (newObject) {
                    /* Use define that won't resume */
                    corto(CORTO_DEFINE, {.object = o});
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
    corto_set_attr(prevAttr);
    corto_set_source(prevOwner);
    if (result) {
        corto_debug("resumed '%s/%s' from '%s'", parent, name, corto_fullpath(NULL, this));
    }

    corto_log_pop();
    return result;
error:
    corto_log_pop();
    return NULL;
}

void corto_mount_return(
    corto_mount this,
    corto_result *r)
{
    corto_ll result = corto_tls_get(CORTO_KEY_MOUNT_RESULT);

    if (!result) {
        result = corto_ll_new();
        corto_tls_set(CORTO_KEY_MOUNT_RESULT, result);
    }

    if (!r->id) {
        corto_error("mount: returned result that doesn't set the id");
        return;
    }

    if (!r->parent) {
        corto_error("mount: returned result that doesn't set the parent");
        return;
    }

    if (!r->type) {
        corto_error("mount: returned result that doesn't set the type");
        return;
    }

    if (!r->value && this->contentTypeOutHandle) {
        corto_error("mount: returned result that doesn't set value but mount has contentType");
        return;
    }

    corto_result *elem = corto_calloc(sizeof(corto_result));
    elem->id = corto_strdup(r->id);
    elem->name = r->name ? corto_strdup(r->name) : NULL;
    elem->parent = corto_strdup(r->parent);
    elem->type = corto_strdup(r->type);
    elem->value = (corto_word)r->value;
    elem->flags = r->flags;
    corto_ll_append(result, elem);
}

int16_t corto_mount_setContentType(
    corto_mount this,
    const char *type)
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
    const char *type)
{

    corto_set_str(&corto_subscriber(this)->contentType, type);
    corto_subscriber(this)->contentTypeHandle = (corto_word)corto_fmt_lookup(type);
    if (!corto_subscriber(this)->contentTypeHandle) {
        goto error;
    }

    return 0;
error:
    return -1;
}

int16_t corto_mount_setContentTypeOut(
    corto_mount this,
    const char *type)
{

    corto_set_str(&this->contentTypeOut, type);
    this->contentTypeOutHandle = (corto_word)corto_fmt_lookup(type);
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

/* Depending on whether a query is for a subscription or whether it comes from
 * a notification it needs to forward the object, or the parent of the object. */
corto_query* corto_mount_getQueryForMount(
    corto_query *q_in,
    corto_query *q_out,
    char *parentBuffer,
    bool subscribe)
{
    /* A subscription for one or more objects in a scope should
     * result in spawning a mount that provides these objects, so
     * shift hierarchical query by one level.
     * If the subscription is for the root, the current mount is
     * providing the data already. */
    if (subscribe) {
        if (strcmp(q_in->from, ".")) {
            strcpy(parentBuffer, q_in->from);
            char *lastParent = strrchr(parentBuffer, '/');
            memset(q_out, 0, sizeof(corto_query));
            if (lastParent) {
                *lastParent = '\0';
                q_out->select = lastParent + 1;
                q_out->from = parentBuffer;
            } else {
                q_out->select = q_in->from;
                q_out->from = ".";
            }

            return q_out;
        } else {
            return NULL;
        }

    } else {
        return q_in;
    }

}

/* Reuse same code for keeping track of subscriptions and mounts */
void corto_mount_subscribeOrMount(
    corto_mount this,
    corto_query *query,
    bool subscribe,
    bool mount)
{
    corto_word subCtx = 0, mntCtx = 0;
    corto_mountSubscription *subscription = NULL, *placeHolder = NULL;
    bool found = FALSE;

    if (subscribe && !(this->policy.mask & CORTO_MOUNT_SUBSCRIBE)) {
        subscribe = false;
    }

    if (mount && !(this->policy.mask & CORTO_MOUNT_MOUNT)) {
        mount = false;
    }

    if (!subscribe && !mount) {
        return;
    }

    if (corto_check_state(this, CORTO_VALID)) corto_lock(this);
    subscription = corto_mount_findSubscription(this, query, &found);
    if (subscription) {
        /* Ensure subscription isn't deleted outside of lock */
        if (subscribe) {
            subscription->subscriberCount ++;
        }

        if (mount) {
            subscription->mountCount ++;
        }

    } else {
        /* Add placeholder to list, so on_subscribe won't be called recursively */
        placeHolder = corto_calloc(sizeof(corto_mountSubscription));
        corto_ptr_copy(&placeHolder->query, corto_query_o, query);
        if (subscribe) {
            placeHolder->subscriberCount = 1;
        }

        if (mount) {
            placeHolder->mountCount = 1;
        }

        corto_ll_append(this->subscriptions, placeHolder);
    }

    if (corto_check_state(this, CORTO_VALID)) corto_unlock(this);
    /* Process callback outside of lock */
    if (!found && (!subscription ||
        (subscribe && subscription->subscriberCtx) ||
        (mount && subscription->mountCtx)))
    {
        /* If no subscription is found that both matches parent and expr, notify
         * the mount */
        if (subscribe) {
            subCtx = corto_mount_on_subscribe(
                this,
                query,
                subscription ? subscription->subscriberCtx : 0);
        }

        if (mount) {
            corto_query q_out, *q;
            corto_id parentId;
            if ((q = corto_mount_getQueryForMount(query, &q_out, parentId, subscribe))) {
                mntCtx = corto_mount_on_mount(
                    this,
                    q,
                    subscription ? subscription->mountCtx : 0);
            }

        }

    }

    /* Only add subscription if connection data is not null, no existing
     * subscription exists, and if context data differs from existing
     * subscription */
    if ((subCtx && (!subscription || (subscription->subscriberCtx != subCtx))) ||
        (mntCtx && (!subscription || (subscription->mountCtx != mntCtx)))) {
        if (corto_check_state(this, CORTO_VALID)) corto_lock(this);
        /* If a new subscription is required, undo increase of refcount of the
         * subscription that was found */
        if (subscription) {
            if (subCtx) subscription->subscriberCount --;
            if (mntCtx) subscription->mountCount --;
        }

        /* Do lookup again, as list may have changed while mount was unlocked */
        subscription = corto_mount_findSubscription(this, query, &found);
        if (!found) {
            subscription = corto_calloc(sizeof(corto_mountSubscription));
            corto_ptr_copy(&subscription->query, corto_query_o, query);
            if (subscribe) subscription->subscriberCount = 1;
            if (mount) subscription->mountCount = 1;
            corto_ll_append(this->subscriptions, subscription);
        } else if (subscription->subscriberCtx) {
            /* Increase refcount of new or existing subscription (can be new if
             * during the unlock a new subscription was added). */
            if (subCtx) subscription->subscriberCount ++;
            if (mntCtx) subscription->mountCount ++;
        } else {
            /* If ctx is 0, this was a temporary entry in the subscriptions
             * list to prevent recursion. Since it will already have a count of
             * 1, don't increase refcount again as this would leak */
        }

        if (subscribe) subscription->subscriberCtx = subCtx;
        if (mount) subscription->mountCtx = mntCtx;
        if (corto_check_state(this, CORTO_VALID))  corto_unlock(this);
    } else if ((subCtx || mntCtx) && !found && subscription) {
        /* If there is no need to create a new subscription but no exact match
         * was found, it means that on_subscribe returned the same ctx as the
         * existing connection. In that case, the 'select' parameter of the
         * subscription is meaningless, so to avoid confusion set it to '*'
         */
        if (corto_check_state(this, CORTO_VALID))  corto_lock(this);
        corto_set_str(&subscription->query.select, "*");
        /* Doesn't count as new subscription, so undo increase in refcount */
        if (subCtx) subscription->subscriberCount --;
        if (mntCtx) subscription->mountCount --;
        if (corto_check_state(this, CORTO_VALID)) corto_unlock(this);
    /* If placeholder was added & no (new) subscription is created, remove the
     * placeholder from the list */
    } else if (placeHolder) {
        if (corto_check_state(this, CORTO_VALID))  corto_lock(this);
        corto_ll_remove(this->subscriptions, placeHolder);
        corto_ptr_free(placeHolder, corto_mountSubscription_o);
        if (corto_check_state(this, CORTO_VALID)) corto_unlock(this);
    }

}

void corto_mount_subscribe(
    corto_mount this,
    corto_query *query)
{
    corto_mount_subscribeOrMount(this, query, true, true);
}

void corto_mount_unsubscribeOrUnmount(
    corto_mount this,
    corto_query *query,
    bool subscribe,
    bool mount)
{
    corto_mountSubscription *subscription = NULL;
    corto_bool found = FALSE;

    if (subscribe && !(this->policy.mask & CORTO_MOUNT_SUBSCRIBE)) {
        subscribe = false;
    }

    if (mount && !(this->policy.mask & CORTO_MOUNT_MOUNT)) {
        mount = false;
    }

    if (!subscribe && !mount) {
        return;
    }

    corto_lock(this);
    subscription = corto_mount_findSubscription(this, query, &found);
    if (subscription) {
        if (subscribe) --subscription->subscriberCount;
        if (mount) --subscription->mountCount;
        if (!subscription->subscriberCount && !subscription->mountCount) {
            corto_ll_remove(this->subscriptions, subscription);
        }

    }

    corto_unlock(this);
    if (subscription) {
        if (subscribe && !subscription->subscriberCount) {
            corto_mount_on_unsubscribe(
                this,
                &subscription->query,
                subscription->subscriberCtx);
        }

        if (mount && !subscription->mountCount) {
            corto_query q_out, *q;
            corto_id parentId;
            if ((q = corto_mount_getQueryForMount(query, &q_out, parentId, subscribe))) {
                corto_mount_on_unmount(
                    this,
                    q,
                    subscription->mountCtx);
            }

        }

        if (!subscription->subscriberCount && !subscription->mountCount) {
            corto_ptr_deinit(subscription, corto_mountSubscription_o);
            corto_dealloc(subscription);
        }

    }

}

void corto_mount_unsubscribe(
    corto_mount this,
    corto_query *query)
{
    corto_mount_unsubscribeOrUnmount(this, query, true, true);
}

uintptr_t corto_mount_on_mount_v(
    corto_mount this,
    corto_query *query,
    uintptr_t ctx)
{
    CORTO_UNUSED(this);
    CORTO_UNUSED(query);
    CORTO_UNUSED(ctx);
    return 0;
}

void corto_mount_on_unmount_v(
    corto_mount this,
    corto_query *query,
    uintptr_t ctx)
{
    CORTO_UNUSED(this);
    CORTO_UNUSED(query);
    CORTO_UNUSED(ctx);
}

void corto_mount_on_batch_notify_v(
    corto_mount this,
    corto_subscriberEventIter events)
{
    CORTO_UNUSED(this);
    CORTO_UNUSED(events);
}

corto_resultIter corto_mount_on_history_query_v(
    corto_mount this,
    corto_query *query)
{
    CORTO_UNUSED(this);
    CORTO_UNUSED(query);
    return CORTO_ITER_EMPTY;
}

void corto_mount_on_history_batch_notify_v(
    corto_mount this,
    corto_subscriberEventIter events)
{
    CORTO_UNUSED(this);
    CORTO_UNUSED(events);
}
