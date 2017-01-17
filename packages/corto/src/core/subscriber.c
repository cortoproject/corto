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
extern corto_threadKey CORTO_KEY_FLUENT;
extern corto_rwmutex_s corto_subscriberLock;

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

static corto_subscriptionSeq corto_subscribers[CORTO_MAX_SCOPE_DEPTH];

/* Optimization- if number is zero don't bother taking a lock and walking
 * the subscribers */
static corto_uint32 corto_subscribers_count;

/* Function to determine relative path from two path strings  */
char* corto_pathstr(
    corto_string buffer,
    corto_string from,
    corto_string to,
    char *sep);

int corto_subscriptionWalk(corto_subscriptionWalkAction action, void *userData) {
    int result = 1;

    if (corto_subscribers_count) {
        if (corto_rwmutexRead(&corto_subscriberLock)) {
            goto error;
        }

        int i, s;
        for (i = 0; i < CORTO_MAX_SCOPE_DEPTH; i++) {
            for (s = 0; s < corto_subscribers[i].length; s++) {
                corto_subscription *sub = &corto_subscribers[i].buffer[s];
                if (!(result = action(sub->s, sub->instance, userData))) {
                    break;
                }
            }
            if (!result) {
                break;
            }
        }

        if (corto_rwmutexUnlock(&corto_subscriberLock)) {
            goto error;
        }
    }

    return result;
error:
    return -1;
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

corto_int16 corto_notifySubscribersId(
    corto_eventMask mask,
    corto_string path,
    corto_string type,
    corto_string contentType,
    corto_word value)
{
    corto_object intermediate = NULL;
    corto_value intermediateValue = corto_value_init();
    corto_contentType contentTypeHandle = NULL;
    corto_object owner = corto_getOwner();

    struct {
        corto_contentType ct;
        corto_word value;
    } contentTypes[CORTO_MAX_CONTENTTYPE];
    corto_int32 contentTypesCount = 0;

    if (!contentType) {
        intermediate = (corto_object)value;
        intermediateValue = corto_value_object(intermediate, NULL);
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

    corto_rwmutexRead(&corto_subscriberLock);
    do {
        corto_subscriptionSeq *subscribers = &corto_subscribers[depth];
        if (subscribers) {
            corto_uint32 it;
            for (it = 0; it < subscribers->length; it ++) {
                corto_subscriber s = subscribers->buffer[it].s;
                corto_word content = 0;
                corto_id relativeParent;
                corto_object instance = subscribers->buffer[it].instance;

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

                char *expr = corto_matchParent(s->parent, path);
                if (!expr) {
                    continue;
                }
                if (!corto_matchProgram_run((corto_matchProgram)s->matchProgram, expr)) {
                    corto_debug("subscriber: expression '%s' does not match '%s' (parent = '%s', path = '%s')",
                      s->expr, expr, s->parent, path);
                    continue;
                }

                /* If subscriber requests content, convert to subscriber contentType */
                if (s->contentType && contentType && !strcmp(s->contentType, contentType)) {
                    content = value;
                } else if (s->contentTypeHandle && value && type) {
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
                        contentTypes[i].ct = (corto_contentType)s->contentTypeHandle;

                        /* Has target contentType been loaded? */
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
                        contentTypes[i].value = contentTypes[i].ct->fromValue(&intermediateValue);
                        content = contentTypes[i].value;
                    }
                    contentTypesCount ++;
                }

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

                corto_result r = {
                  id,
                  NULL,
                  relativeParent,
                  type,
                  content,
                  FALSE,
                  intermediate
                };

                corto_dispatcher dispatcher = corto_observer(s)->dispatcher;
                if (!dispatcher) {
                    corto_rwmutexUnlock(&corto_subscriberLock);
                    if (corto_function(s)->kind == CORTO_PROCEDURE_CDECL) {
                        ((void(*)(corto_object, corto_eventMask, corto_result*, corto_subscriber))
                          corto_function(s)->fptr)(instance, mask, &r, s);
                    } else {
                        corto_result *rArg = &r;
                        void *args[4];
                        args[0] = &instance;
                        args[1] = &mask;
                        args[2] = &rArg;
                        args[3] = &s;
                        corto_callb(corto_function(s), NULL, args);
                    }
                    corto_rwmutexRead(&corto_subscriberLock);
                } else {
                    corto_attr oldAttr = corto_setAttr(0);
                    corto_subscriberEvent event = corto_declare(corto_type(corto_subscriberEvent_o));
                    corto_setAttr(oldAttr);
                    corto_observableEvent oEvent = corto_observableEvent(event);
                    corto_setref(&oEvent->observer, s);
                    corto_setref(&oEvent->me, instance);
                    corto_setref(&oEvent->observable, NULL);
                    corto_setref(&oEvent->source, NULL);
                    oEvent->mask = mask;
                    corto_copyp(&event->result, corto_result_o, &r);
                    if (r.value) {
                        event->result.value =
                          ((corto_contentType)s->contentTypeHandle)->copy(r.value);
                    }
                    event->contentTypeHandle = s->contentTypeHandle;
                    corto_dispatcher_post(dispatcher, corto_event(event));
                }
                if (sep) *sep = '/';
            }
        }
    } while (depth-- >= 0);
    corto_rwmutexUnlock(&corto_subscriberLock);

    /* Free up resources */
    corto_int32 i;
    for (i = 0; i < contentTypesCount; i++) {
        contentTypes[i].ct->release(contentTypes[i].value);
    }

    /* Free intermediate format */
    if (intermediate && contentType) {
        corto_release(intermediate);
    }

    return 0;
error:
    if (intermediate && contentType) {
        corto_release(intermediate);
    }

    return -1;
}

corto_int16 corto_notifySubscribers(corto_eventMask mask, corto_object o) {
    corto_int16 result = 0;

    if (corto_subscribers_count) {
        corto_id path, type;
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
    corto_string expr)
{
    corto_subscribeRequest *request = corto_threadTlsGet(CORTO_KEY_FLUENT);
    if (!request) {
        request = corto_calloc(sizeof(corto_subscribeRequest));
        corto_threadTlsSet(CORTO_KEY_FLUENT, request);
    } else {
        memset(request, 0, sizeof(corto_subscribeRequest));
    }

    request->mask = mask;
    request->scope = scope;
    request->expr = expr;
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

    /* Notify mounts of unsubscription once */
    corto_subscriptionSeq *seq = &corto_subscribers[depth];

    /* Find subscriber */
    corto_uint32 i;
    for (i = 0; i < seq->length; i++) {
        if ((seq->buffer[i].s == this) && (removeAll || (seq->buffer[i].instance == instance))) {
            if (i == (seq->length - 1)) {
                seq->buffer[i].s = NULL;
                seq->buffer[i].instance = NULL;
            } else {
                seq->buffer[i].s = seq->buffer[seq->length - 1].s;
                seq->buffer[i].instance = seq->buffer[seq->length - 1].instance;

                /* If removing all, make sure not to skip elements */
                if (removeAll && (i == (seq->length - 2))) {
                    i --;
                }
            }

            corto_select(this->parent, this->expr).instance(this).unsubscribe();

            seq->length --;
            count ++;
            if (!removeAll) {
                break;
            }
        }
    }
    if (!count && !removeAll) {
        corto_seterr(
          "unsubscribe failed, could not find subscriber for instance '%s' <%p>",
          corto_fullpath(NULL, instance), instance);
        goto error;
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

    return 0;
error:
    return -1;
/* $end */
}

corto_void _corto_subscriber_destruct(
    corto_subscriber this)
{
/* $begin(corto/core/subscriber/destruct) */
    corto_matchProgram_free((corto_matchProgram)this->matchProgram);

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

    return corto_function_init(this);
/* $end */
}

corto_int16 _corto_subscriber_subscribe(
    corto_subscriber this,
    corto_object instance)
{
/* $begin(corto/core/subscriber/subscribe) */
    corto_int16 depth = corto_subscriber_getObjectDepth(this->parent);
    corto_iter it;
    corto_bool align = FALSE;
    corto_eventMask mask = corto_observer(this)->mask;

    corto_debug("corto: subscriber '%s': subscribe for %s, %s",
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
    if ((mask == CORTO_ON_DECLARE) || (mask == CORTO_ON_DEFINE)) {
        align = TRUE;
    }

    /* Add subscriber to subscriber admin */
    if (corto_rwmutexWrite(&corto_subscriberLock)) {
        goto error;
    }

    corto_uint32 length = corto_subscribers[depth].length + 1;
    corto_subscribers[depth].buffer =
      corto_realloc(corto_subscribers[depth].buffer, length * sizeof(corto_subscription));

    corto_subscribers[depth].buffer[length - 1].s = this;
    corto_subscribers[depth].buffer[length - 1].instance = instance;
    corto_subscribers[depth].length ++;
    corto_subscribers_count ++;

    if (corto_rwmutexUnlock(&corto_subscriberLock)) {
        goto error;
    }

    /* Align subscriber */
    while (corto_iterHasNext(&it)) {
        corto_result *r = corto_iterNext(&it);
        /* Only forward results to subscriber if subscriber wants to be
         * aligned. If not, still walk the results so mounts will receive
         * onSubscribe callbacks */
        if (align) {
            if (corto_function(this)->kind == CORTO_PROCEDURE_CDECL) {
                ((void(*)(corto_object, corto_eventMask, corto_result*, corto_subscriber))
                  corto_function(this)->fptr)(instance, mask, r, this);
            } else {
                void *args[4];
                args[0] = &instance;
                args[1] = &mask;
                args[2] = &r;
                args[3] = &this;
                corto_callb(this, NULL, args);
            }
        }
    }

    corto_observer(this)->enabled = TRUE;

    /* Ensure that subscriber isn't deleted before instance unsubscribes */
    corto_claim(this);

    return 0;
error:
    return -1;
/* $end */
}

corto_int16 _corto_subscriber_unsubscribe(
    corto_subscriber this,
    corto_object instance)
{
/* $begin(corto/core/subscriber/unsubscribe) */
    corto_debug("corto: subscriber '%s': unsubscribe for %s, %s",
      corto_fullpath(NULL, this),
      this->parent,
      this->expr);

    return corto_subscriber_unsubscribeIntern(this, instance, FALSE);
/* $end */
}
