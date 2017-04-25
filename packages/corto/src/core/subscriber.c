/* $CORTO_GENERATED
 *
 * subscriber.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/core/core.h>

/* $header() */
#include "_object.h"

extern corto_threadKey CORTO_KEY_SUBSCRIBER_ADMIN;
extern corto_threadKey CORTO_KEY_FLUENT;

extern corto_rwmutex_s corto_subscriberLock;

extern int S_B_NOTIFY;
extern int S_B_INIT;
extern int S_B_FINI;
extern int S_B_MATCH;
extern int S_B_PATHID;
extern int S_B_INVOKE;
extern int S_B_MATCHPARENT;
extern int S_B_CONTENTTYPE;


/* Fluent request */
typedef struct corto_subscribeRequest {
    corto_int16 err;
    corto_object instance;
    corto_eventMask mask;
    corto_string scope;
    corto_string expr;
    corto_string type;
    corto_string contentType;
    corto_dispatcher dispatcher;
    corto_bool enabled;
    void (*callback)(corto_object, corto_eventMask mask, corto_result*, corto_subscriber);
} corto_subscribeRequest;

typedef struct corto_subscription {
    corto_subscriber s;
    corto_object instance;
} corto_subscription;

CORTO_SEQUENCE(corto_subscriptionSeq, corto_subscription,);

typedef struct corto_subscriptionPerParent {
    corto_subscriptionSeq subscriptions;
    corto_string parent;
} corto_subscriptionPerParent;

CORTO_SEQUENCE(corto_subscriptionPerParentSeq, corto_subscriptionPerParent,);

/* Threads keep their own copy of active subscribers so there is no need for
 * a lock when notifying */
typedef struct corto_subscriberAdmin {
    /* counter keeps track of when subscribers are added / removed so that
     * threads know when to sync. */
    corto_uint32 changed;
    corto_subscriptionPerParentSeq subscribers[CORTO_MAX_SCOPE_DEPTH];
} corto_subscriberAdmin;

static corto_subscriberAdmin corto_subscribers_global = {0};


/* Optimization- if number is zero don't bother taking a lock and walking
 * subscribers */
corto_uint32 corto_subscribers_count;

/* Free all subscriptoins, but do not free corto_subscriberAdmin itself so
 * it can be reused when a thread needs to copy global subscriptions */
void corto_subscriberAdminFreeSubscriptions(corto_subscriberAdmin *data) {
    corto_int32 depth, sp;

    for (depth = 0; depth < CORTO_MAX_SCOPE_DEPTH; depth ++) {
        for (sp = 0; sp < data->subscribers[depth].length; sp++) {
            corto_subscriptionPerParent *subPerParent = &data->subscribers[depth].buffer[sp];
            corto_dealloc(subPerParent->subscriptions.buffer);
        }
        corto_dealloc(data->subscribers[depth].buffer);
        data->subscribers[depth].buffer = NULL;
        data->subscribers[depth].length = 0;
    }
}

/* Free all data when thread shuts down */
void corto_subscriberAdminFree(void *admin) {
    corto_subscriberAdmin *data = admin;
    if (data) {
        corto_subscriberAdminFreeSubscriptions(data);
        corto_dealloc(data);
    }
}

/* Copy data from global admin to (local) thread admin */
static corto_int16 corto_subscriberAdminCopyIn(corto_subscriberAdmin *dst) {
    corto_subscriberAdmin *src = &corto_subscribers_global;
    corto_int32 depth, sp;

    if (corto_subscribers_count) {
        if (corto_rwmutexRead(&corto_subscriberLock)) {
            goto error;
        }

        for (depth = 0; depth < CORTO_MAX_SCOPE_DEPTH; depth ++) {
            dst->subscribers[depth].length = src->subscribers[depth].length;
            dst->subscribers[depth].buffer = 
                corto_alloc(dst->subscribers[depth].length * sizeof(corto_subscriptionPerParent));

            for (sp = 0; sp < src->subscribers[depth].length; sp++) {
                corto_subscriptionPerParent *srcSubParent = &src->subscribers[depth].buffer[sp];
                corto_subscriptionPerParent *dstSubParent = &dst->subscribers[depth].buffer[sp];

                dstSubParent->parent = srcSubParent->parent;
                dstSubParent->subscriptions.length = srcSubParent->subscriptions.length;
                dstSubParent->subscriptions.buffer = 
                    corto_alloc(dstSubParent->subscriptions.length * sizeof(corto_subscription));

                memcpy (
                    dstSubParent->subscriptions.buffer, 
                    srcSubParent->subscriptions.buffer, 
                    srcSubParent->subscriptions.length * sizeof(corto_subscription));
            }
        }

        if (corto_rwmutexUnlock(&corto_subscriberLock)) {
            goto error;
        }
    }

    return 0;
error:
    return -1;
}

static corto_subscriberAdmin* corto_subscriberAdminGet() {
    corto_subscriberAdmin *result = corto_threadTlsGet(CORTO_KEY_SUBSCRIBER_ADMIN);
    if (!result) {
        result = corto_calloc(sizeof(corto_subscriberAdmin));
        corto_threadTlsSet(CORTO_KEY_SUBSCRIBER_ADMIN, result);
    }

    if (result->changed != corto_subscribers_global.changed) {
        corto_subscriberAdminFreeSubscriptions(result);
        if (corto_subscriberAdminCopyIn(result)) {
            goto error;
        }
        result->changed = corto_subscribers_global.changed;
    }

    return result;
error:
    return NULL;
}

/* Function to determine relative path from two path strings  */
char* corto_pathstr(
    corto_string buffer,
    corto_string from,
    corto_string to,
    char *sep);

int corto_subscriptionWalk(corto_subscriptionWalkAction action, void *userData) {
    int result = 1;

    if (corto_subscribers_count) {
        corto_subscriberAdmin *admin = corto_subscriberAdminGet();

        int depth, sp, s;
        for (depth = 0; depth < CORTO_MAX_SCOPE_DEPTH; depth++) {
            for (sp = 0; sp < admin->subscribers[depth].length; sp++) {
                corto_subscriptionPerParent *subPerParent = &admin->subscribers[depth].buffer[sp];
                for (s = 0; s < subPerParent[sp].subscriptions.length; s ++) {
                    corto_subscription *sub = &subPerParent[sp].subscriptions.buffer[s];
                    if (!(result = action(sub->s, sub->instance, userData))) {
                        break;
                    }
                }
            }
            if (!result) {
                break;
            }
        }
    }

    return result;
}

static corto_int16 corto_subscriber_getObjectDepth(corto_id id) {
    corto_int16 result = 0;
    if (id) {
        char *ptr = id;
        while ((ptr = strchr(ptr + 1, '/'))) {
            result ++;
        }
    }
    return result;
}

static corto_int16 corto_subscriber_invoke(
    corto_object instance,
    corto_eventMask mask,
    corto_result *r,
    corto_subscriber s)
{
    corto_dispatcher dispatcher = corto_observer(s)->dispatcher;
    if (!dispatcher) {
        corto_function f = corto_function(s);
        if (f->kind == CORTO_PROCEDURE_CDECL) {
            if (f->fptr) {
                ((void(*)(corto_object, corto_eventMask, corto_result*, corto_subscriber))
                  corto_function(s)->fptr)(instance, mask, r, s);
            }
        } else {
            void *args[4];
            args[0] = &instance;
            args[1] = &mask;
            args[2] = &r;
            args[3] = &s;
            corto_callb(corto_function(s), NULL, args);
        }
    } else {
        corto_attr oldAttr = corto_setAttr(0);
        corto_subscriberEvent event = corto_declare(corto_subscriberEvent_o);
        corto_setAttr(oldAttr);
        corto_observableEvent oEvent = corto_observableEvent(event);
        corto_setref(&oEvent->observer, s);
        corto_setref(&oEvent->me, instance);
        corto_setref(&oEvent->observable, NULL);
        corto_setref(&oEvent->source, NULL);
        oEvent->mask = mask;
        corto_copyp(&event->result, corto_result_o, r);
        if (r->value) {
            event->result.value =
              ((corto_contentType)s->contentTypeHandle)->copy(r->value);
        }
        event->contentTypeHandle = s->contentTypeHandle;
        if (corto_define(event)) {
            goto error;
        }
        corto_dispatcher_post(dispatcher, corto_event(event));
    }

    return 0;
error:
    return -1;
}

corto_int16 corto_notifySubscribersId(
    corto_eventMask mask,
    corto_string path,
    corto_string type,
    corto_string contentType,
    corto_word value)
{
    if (!corto_subscribers_count) {
        return 0;
    }

    /* Don't notify when shutting down */
    if (CORTO_OPERATIONAL != 0) {
        return 0;
    }

    corto_benchmark_start(S_B_NOTIFY);

    corto_benchmark_start(S_B_INIT);
    corto_object intermediate = NULL;
    corto_value intermediateValue = corto_value_init();
    corto_contentType contentTypeHandle = NULL;
    corto_object owner = corto_getOwner();
    corto_object objectOwner = owner;

    struct {
        corto_contentType ct;
        corto_word value;
    } contentTypes[CORTO_MAX_CONTENTTYPE];
    corto_int32 contentTypesCount = 0;

    if (!contentType && value) {
        intermediate = (corto_object)value;
        intermediateValue = corto_value_object(intermediate, NULL);
        objectOwner = corto_ownerof(intermediate);
    }

    char *sep = NULL, *id = strrchr(path, '/');
    char *parent = NULL;
    if (id) {
        if (id != path) {
            sep = id;
            parent = path;
        } else {
            parent = "/";
        }
        id ++;
    } else {
        id = path;
        parent = "/corto/lang";
    }

    corto_int16 depth = corto_subscriber_getObjectDepth(path);
    corto_benchmark_stop(S_B_INIT);

    corto_subscriberAdmin *admin = corto_subscriberAdminGet();
    if (!admin) {
        goto error;
    }

    do {
        corto_uint32 sp, s;
        corto_bool relativeParentSet = FALSE;
        corto_id relativeParent;

        for (sp = 0; sp < admin->subscribers[depth].length; sp ++) {
            corto_subscriptionPerParent *subPerParent = &admin->subscribers[depth].buffer[sp];

            corto_benchmark_start(S_B_MATCHPARENT);
            char *expr = corto_matchParent(subPerParent->parent, path);
            if (!expr) {
                continue;
            }
            corto_benchmark_stop(S_B_MATCHPARENT);

            for (s = 0; s < subPerParent->subscriptions.length; s ++) {
                corto_subscription *sub = &subPerParent->subscriptions.buffer[s];
                corto_subscriber s = sub->s;
                corto_word content = 0;
                corto_object instance = sub->instance;

                if (!s->expr) {
                    continue;
                }

                if (instance && (instance == owner)) {
                    continue;
                }

                if ((corto_observer(s)->mask & mask) != mask) {
                    continue;
                }

                if (corto_observer(s)->type && strcmp(corto_observer(s)->type, type)) {
                    continue;
                }

                corto_benchmark_start(S_B_MATCH);
                if (!corto_matchProgram_run((corto_matchProgram)s->matchProgram, expr)) {
                    continue;
                }
                corto_benchmark_stop(S_B_MATCH);

                /* If subscriber requests content, convert to subscriber contentType */
                if (s->contentType && contentType && !strcmp(s->contentType, contentType)) {
                    content = value;
                } else if (s->contentTypeHandle && value && type) {
                    corto_benchmark_start(S_B_CONTENTTYPE);

                    /* Check if contentType has already been loaded */
                    corto_int32 i;
                    for (i = 0; i < contentTypesCount; i++) {
                        if ((corto_word)contentTypes[i].ct == s->contentTypeHandle) {
                            content = contentTypes[i].value;
                            break;
                        }
                    }

                    /* contentType hasn't been loaded */
                    if (i == contentTypesCount) {

                        /* Has source contentType been loaded? */
                        if (contentType && !contentTypeHandle) {
                            /* Load contentType */
                            contentTypeHandle = corto_loadContentType(contentType);
                            if (!contentTypeHandle) {
                                goto error;
                            }

                            /* Resolve type of object */
                            corto_type t = corto_resolve(NULL, type);
                            if (!t) {
                                corto_seterr("failed to resolve type '%s'", type);
                                goto error;
                            }

                            /* Create intermediate object */
                            if (!(intermediate = corto_create(t))) {
                                goto error;
                            }
                            corto_release(t);
                            intermediateValue = corto_value_object(intermediate, NULL);
                            if (contentTypeHandle->toValue(&intermediateValue, value)) {
                                goto error;
                            }
                        }

                        contentTypes[i].ct = (corto_contentType)s->contentTypeHandle;
                        contentTypes[i].value = contentTypes[i].ct->fromValue(&intermediateValue);
                        content = contentTypes[i].value;
                        contentTypesCount ++;
                    }
                    corto_benchmark_stop(S_B_CONTENTTYPE);
                }

                /* Relative parent will be the same for each subscriber at same depth */
                if (!relativeParentSet) {
                    corto_benchmark_start(S_B_PATHID);
                    if (sep) *sep = '\0';
                    corto_id fromElem, toElem;
                    char *fromElemPtr = fromElem;
                    if (s->parent) {
                        strcpy(fromElem, s->parent);
                    } else {
                        fromElemPtr = NULL;
                    }
                    strcpy(toElem, parent);

                    corto_pathstr(relativeParent, fromElemPtr, toElem, "/");
                    corto_benchmark_stop(S_B_PATHID);
                    relativeParentSet = TRUE;
                }

                corto_result r = {
                  .id = id,
                  .name = NULL,
                  .parent = relativeParent,
                  .type = type,
                  .value = content,
                  .leaf = FALSE,
                  .object = intermediate,
                  .owner = objectOwner
                };

                corto_benchmark_start(S_B_INVOKE);
                corto_subscriber_invoke(instance, mask, &r, s);
                corto_benchmark_stop(S_B_INVOKE);

                if (sep) *sep = '/';
            }
        }
    } while (--depth >= 0);

    corto_benchmark_start(S_B_FINI);

    /* Free up resources */
    corto_int32 i;
    for (i = 0; i < contentTypesCount; i++) {
        contentTypes[i].ct->release(contentTypes[i].value);
    }

    /* Free intermediate format */
    if (intermediate && contentType) {
        corto_release(intermediate);
    }

    corto_benchmark_stop(S_B_FINI);

    corto_benchmark_stop(S_B_NOTIFY);

    return 0;
error:
    if (intermediate && contentType) {
        corto_release(intermediate);
    }

    return -1;
}

corto_int16 corto_notifySubscribers(corto_eventMask mask, corto_object o) {
    corto_int16 result = 0;

    if (corto_subscribers_count && corto_checkAttr(o, CORTO_ATTR_SCOPED)) {
        corto_id path, type;
        corto_fullpath(path, o);

        result = corto_notifySubscribersId(
          mask,
          corto_fullpath(path, o),
          corto_fullpath(type, corto_typeof(o)),
          NULL,
          (corto_word)o);
    }

    return result;
}

static corto_subscriber corto_subscribeSubscribe(corto_subscribeRequest *r)
{
    corto_subscriber s = corto_declare(corto_subscriber_o);
    ((corto_observer)s)->mask = r->mask;
    corto_setstr(&s->parent, r->scope);

    if (r->scope && *r->scope) {
        if (*r->scope != '/') {
            corto_asprintf(&s->parent, "/%s", r->scope);
        } else {
            s->parent = corto_strdup(r->scope);
        } } else {
        s->parent = NULL;
    }

    corto_setstr(&s->expr, r->expr);
    corto_setstr(&s->contentType, r->contentType);
    corto_setref(&((corto_observer)s)->instance, r->instance);
    corto_setref(&((corto_observer)s)->dispatcher, r->dispatcher);
    corto_setstr(&((corto_observer)s)->type, r->type);
    ((corto_observer)s)->enabled = r->enabled;
    ((corto_function)s)->fptr = (corto_word)r->callback;
    ((corto_function)s)->kind = CORTO_PROCEDURE_CDECL;

    if (corto_define(s)) {
        corto_delete(s);
        s = NULL;
    }

    corto_dealloc(r->expr);

    return s;
}

static corto_subscribeFluent corto_subscribeFluentGet(void);

static corto_subscribeFluent corto_subscribeContentType(
    corto_string contentType)
{
    corto_subscribeRequest *request = corto_threadTlsGet(CORTO_KEY_FLUENT);
    if (request) {
        request->contentType = contentType;
    }
    return corto_subscribeFluentGet();
}

static corto_subscribeFluent corto_subscribeType(
    corto_string type)
{
    corto_subscribeRequest *request = corto_threadTlsGet(CORTO_KEY_FLUENT);
    if (request) {
        request->type = type;
    }
    return corto_subscribeFluentGet();
}

static corto_subscribeFluent corto_subscribeInstance(
    corto_object instance)
{
    corto_subscribeRequest *request = corto_threadTlsGet(CORTO_KEY_FLUENT);
    if (request) {
        request->instance = instance;
    }
    return corto_subscribeFluentGet();
}

static corto_subscribeFluent corto_subscribeDisabled(void)
{
    corto_subscribeRequest *request = corto_threadTlsGet(CORTO_KEY_FLUENT);
    if (request) {
        request->enabled = FALSE;
    }
    return corto_subscribeFluentGet();
}

static corto_subscribeFluent corto_subscribeDispatcher(corto_dispatcher dispatcher)
{
    corto_subscribeRequest *request = corto_threadTlsGet(CORTO_KEY_FLUENT);
    if (request) {
        request->dispatcher = dispatcher;
    }
    return corto_subscribeFluentGet();
}

static corto_subscriber corto_subscribeCallback(
    void (*callback)(corto_object, corto_eventMask, corto_result*, corto_subscriber))
{
    corto_subscriber result = NULL;

    corto_subscribeRequest *request = corto_threadTlsGet(CORTO_KEY_FLUENT);
    if (request) {
        request->callback = callback;
        corto_threadTlsSet(CORTO_KEY_FLUENT, NULL);
        result = corto_subscribeSubscribe(request);
        corto_dealloc(request);
    }

    return result;
}

static corto_subscribeFluent corto_subscribeFluentGet(void)
{
    corto_subscribeFluent result;
    result.contentType = corto_subscribeContentType;
    result.callback = corto_subscribeCallback;
    result.instance = corto_subscribeInstance;
    result.disabled = corto_subscribeDisabled;
    result.type = corto_subscribeType;
    result.dispatcher = corto_subscribeDispatcher;
    return result;
}

corto_subscribeFluent corto_subscribe(
    corto_eventMask mask,
    corto_string scope,
    corto_string expr,
    ...)
{
    va_list arglist;

    corto_subscribeRequest *request = corto_threadTlsGet(CORTO_KEY_FLUENT);
    if (!request) {
        request = corto_calloc(sizeof(corto_subscribeRequest));
        corto_threadTlsSet(CORTO_KEY_FLUENT, request);
    } else {
        memset(request, 0, sizeof(corto_subscribeRequest));
    }

    va_start(arglist, expr);
    corto_vasprintf(&request->expr, expr, arglist);
    va_end (arglist);

    request->mask = mask;
    request->scope = scope;
    request->enabled = TRUE;
    return corto_subscribeFluentGet();
}

corto_int16 corto_unsubscribe(corto_subscriber subscriber, corto_object instance) {
    return corto_subscriber_unsubscribe(subscriber, instance);
}

static corto_int16 corto_subscriber_unsubscribeIntern(corto_subscriber this, corto_object instance, corto_bool removeAll) {
    corto_int32 count = 0;
    corto_int16 depth = corto_subscriber_getObjectDepth(this->parent);

    if (corto_rwmutexWrite(&corto_subscriberLock)) {
        goto error;
    }

    /* Find subscriber */
    corto_uint32 s, sp;
    for (sp = 0; sp < corto_subscribers_global.subscribers[depth].length; sp++) {
        corto_subscriptionPerParent *subPerParent = &corto_subscribers_global.subscribers[depth].buffer[sp];
        corto_subscriptionSeq *seq = &subPerParent->subscriptions;
        for (s = 0; s < seq->length; s ++) {
            corto_subscription *sub = &seq->buffer[s];
            if ((sub->s == this) && (removeAll || (sub->instance == instance))) {
                if (s == (seq->length - 1)) {
                    seq->buffer[s].s = NULL;
                    seq->buffer[s].instance = NULL;
                } else {
                    seq->buffer[s].s = seq->buffer[seq->length - 1].s;
                    seq->buffer[s].instance = seq->buffer[seq->length - 1].instance;

                    /* If removing all, make sure not to skip elements */
                    if (removeAll && (s == (seq->length - 2))) {
                        s --;
                    }
                }

                corto_select(this->parent, this->expr).instance(this).unsubscribe();

                seq->length --;
                corto_subscribers_count --;
                count ++;
                if (!removeAll) {
                    break;
                }
            }
        }
    }
    if (!count && !removeAll) {
        corto_seterr(
          "unsubscribe failed, could not find subscriber for instance '%s' <%p>",
          corto_fullpath(NULL, instance), instance);
        goto error;
    }

    if (count) {
        corto_subscribers_global.changed ++;
    }

    if (corto_rwmutexUnlock(&corto_subscriberLock)) {
        goto error;
    }

    if (!removeAll) {
        /* Ensure that observer isn't deleted before instance unsubscribes */
        corto_release(this);
    }

    return 0;
error:
    if (corto_rwmutexUnlock(&corto_subscriberLock)) {
        goto error;
    }
    return -1;
}

/* $end */

corto_int16 _corto_subscriber_construct(
    corto_subscriber this)
{
/* $begin(corto/core/subscriber/construct) */
    if (!this->expr || !this->expr[0]) {
        corto_seterr("'null' is not a valid subscriber expression");
        goto error;
    }

    if (this->contentType) {
        this->contentTypeHandle = (corto_word)corto_loadContentType(this->contentType);
        if (!this->contentTypeHandle) {
            goto error;
        }
    }

    this->matchProgram = (corto_word)corto_matchProgram_compile(this->expr, TRUE, TRUE);
    if (!this->matchProgram) {
        goto error;
    }

    if (corto_observer(this)->enabled) {
        if (corto_subscriber_subscribe(this, corto_observer(this)->instance)) {
            goto error;
        }
    }

    return corto_observer_construct(this);
error:
    return -1;
/* $end */
}

void _corto_subscriber_deinit(
    corto_subscriber this)
{
/* $begin(corto/core/subscriber/deinit) */

    /* Delete matchProgram resources only when subscriber itself is deallocated 
     * as notifications might still take place when subscriber is deleted. */
    corto_matchProgram_free((corto_matchProgram)this->matchProgram);

/* $end */
}

corto_void _corto_subscriber_destruct(
    corto_subscriber this)
{
/* $begin(corto/core/subscriber/destruct) */

    /* Unsubscribe all subscriptions of this subscriber */
    corto_subscriber_unsubscribeIntern(this, NULL, TRUE);

/* $end */
}

corto_int16 _corto_subscriber_init(
    corto_subscriber this)
{
/* $begin(corto/core/subscriber/init) */
    corto_parameter *p;
    corto_function(this)->parameters.buffer = corto_calloc(sizeof(corto_parameter) * 4);
    corto_function(this)->parameters.length = 3;

    /* Parameter event */
    p = &corto_function(this)->parameters.buffer[0];
    p->name = corto_strdup("event");
    p->passByReference = FALSE;
    corto_setref(&p->type, corto_eventMask_o);

    /* Parameter object */
    p = &corto_function(this)->parameters.buffer[1];
    p->name = corto_strdup("object");
    p->passByReference = TRUE;
    corto_setref(&p->type, corto_result_o);

    /* Parameter subscriber */
    p = &corto_function(this)->parameters.buffer[2];
    p->name = corto_strdup("subscriber");
    p->passByReference = TRUE;
    corto_setref(&p->type, corto_subscriber_o);

    corto_observer(this)->mask = CORTO_ON_ANY;

    return corto_function_init(this);
/* $end */
}

corto_int16 _corto_subscriber_subscribe(
    corto_subscriber this,
    corto_object instance)
{
/* $begin(corto/core/subscriber/subscribe(object instance)) */
    corto_int16 depth = corto_subscriber_getObjectDepth(this->parent);
    corto_iter it;
    corto_bool align = FALSE;
    corto_eventMask mask = corto_observer(this)->mask;

    corto_debug("subscriber '%s': subscribe for %s, %s",
      corto_fullpath(NULL, this),
      this->parent,
      this->expr);

    /* If subscriber was not yet enabled, subscribe to mounts */
    corto_int16 ret = corto_select(this->parent, this->expr)
      .instance(this) /* this prevents mounts from subscribing to themselves */
      .subscribe(&it);
    if (ret) {
        goto error;
    }

    /* If subscriber subscribes for DECLARE or DEFINE events, align data */
    if ((mask & CORTO_ON_DECLARE) || (mask & CORTO_ON_DEFINE)) {
        align = TRUE;
    }

    /* Add subscriber to subscriber admin */
    if (corto_rwmutexWrite(&corto_subscriberLock)) {
        goto error;
    }

    /* First, find an existing subscription sequence for parent of subscriber */
    corto_uint32 sp;
    corto_subscriptionPerParent *subPerParent = NULL;
    for (sp = 0; sp < corto_subscribers_global.subscribers[depth].length; sp++) {
        subPerParent = &corto_subscribers_global.subscribers[depth].buffer[sp];
        if ((!this->parent && !subPerParent->parent) || 
            (this->parent && subPerParent->parent && !stricmp(this->parent, subPerParent->parent))) 
        {
            break;
        } else {
            subPerParent = NULL;
        }
    }

    /* If no subscription sequence is found for parent, create one */
    if (!subPerParent) {
        corto_uint32 length = corto_subscribers_global.subscribers[depth].length + 1;
        corto_subscribers_global.subscribers[depth].buffer =
          corto_realloc(corto_subscribers_global.subscribers[depth].buffer, length * sizeof(corto_subscriptionPerParent));
        corto_subscribers_global.subscribers[depth].buffer[length - 1].parent = this->parent ? corto_strdup(this->parent) : NULL;
        corto_subscribers_global.subscribers[depth].buffer[length - 1].subscriptions.length = 0;
        corto_subscribers_global.subscribers[depth].buffer[length - 1].subscriptions.buffer = NULL;
        corto_subscribers_global.subscribers[depth].length ++;
        subPerParent = &corto_subscribers_global.subscribers[depth].buffer[length - 1];
    }

    corto_subscriptionSeq *seq = &subPerParent->subscriptions;

    /* Add subscriber to subscription sequence */
    corto_uint32 length = seq->length + 1;
    seq->buffer = corto_realloc(seq->buffer, length * sizeof(corto_subscription));
    seq->buffer[length - 1].s = this;
    seq->buffer[length - 1].instance = instance;
    seq->length ++;
    corto_subscribers_count ++;
    corto_subscribers_global.changed ++;

    corto_observer(this)->enabled = TRUE;

    if (corto_rwmutexUnlock(&corto_subscriberLock)) {
        goto error;
    }

    /* Ensure that subscriber isn't deleted before instance unsubscribes */
    corto_claim(this);

    /* Align subscriber */
    while (corto_iterHasNext(&it)) {
        corto_result *r = corto_iterNext(&it);
        /* Only forward results to subscriber if subscriber wants to be
         * aligned. If not, still walk the results so mounts will receive
         * onSubscribe callbacks */
        if (align) {
            corto_subscriber_invoke(instance, mask, r, this);
        }
    }

    return 0;
error:
    return -1;
/* $end */
}

corto_int16 _corto_subscriber_unsubscribe(
    corto_subscriber this,
    corto_object instance)
{
/* $begin(corto/core/subscriber/unsubscribe(object instance)) */
    corto_debug("subscriber '%s': unsubscribe for %s, %s",
      corto_fullpath(NULL, this),
      this->parent,
      this->expr);

    return corto_subscriber_unsubscribeIntern(this, instance, FALSE);
/* $end */
}
