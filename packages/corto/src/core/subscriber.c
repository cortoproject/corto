/* This is a managed file. Do not delete this comment. */

#include <corto/corto.h>


#include "entityadmin.h"
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
    corto_string scope;
    corto_string expr;
    corto_string type;
    corto_string contentType;
    corto_dispatcher dispatcher;
    corto_bool enabled;
    void (*callback)(corto_subscriberEvent*);
} corto_subscribeRequest;

corto_entityAdmin corto_subscriber_admin = {
    .key = 0,
    .count = 0,
    .lock = CORTO_RWMUTEX_INITIALIZER,
    .changed = 0
};

/* Function to determine relative path from two path strings  */
char* corto_pathstr(
    corto_string buffer,
    corto_string from,
    corto_string to,
    char *sep);

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
                corto_subscriberEvent e = {
                    .instance = instance,
                    .event = mask,
                    .source = NULL,
                    .subscriber = s,
                    .data = *r
                };
                ((void(*)(corto_subscriberEvent*))((corto_function)s)->fptr)(&e);
            }
        } else {
            corto_subscriberEvent e = {
                .instance = instance,
                .event = mask,
                .source = NULL,
                .subscriber = s,
                .data = *r
            },
            *ePtr = &e;
            void *args[] = {&ePtr};
            corto_callb((corto_function)s, NULL, args);
        }
    } else {
        corto_attr oldAttr = corto_setAttr(0);
        corto_subscriberEvent *event = corto_declare(corto_subscriberEvent_o);
        corto_setAttr(oldAttr);
        corto_ptr_setref(&event->subscriber, s);
        corto_ptr_setref(&event->instance, instance);
        corto_ptr_setref(&event->source, NULL);
        event->event = mask;
        corto_ptr_copy(&event->data, corto_result_o, r);
        if (r->value) {
            event->data.value =
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
    if (!corto_subscriber_admin.count) {
        return 0;
    }

    /* Subscribers only receive data events */
    if (!(mask & (CORTO_ON_DEFINE|CORTO_ON_UPDATE|CORTO_ON_DELETE))) {
        return 0;
    }

    /* Don't notify when shutting down */
    if (CORTO_OPERATIONAL != 0) {
        return 0;
    }

    corto_benchmark_start(S_B_NOTIFY);

    corto_benchmark_start(S_B_INIT);
    corto_object intermediate = NULL;
    corto_value intermediateValue = corto_value_empty();
    corto_contentType contentTypeHandle = NULL;
    corto_object owner = corto_getOwner();
    corto_object objectOwner = owner;
    bool valueIsObject = false;

    struct {
        corto_contentType ct;
        corto_word value;
    } contentTypes[CORTO_MAX_CONTENTTYPE];
    corto_int32 contentTypesCount = 0;

    if (!contentType && value) {
        intermediate = (corto_object)value;
        intermediateValue = corto_value_object(intermediate, NULL);
        objectOwner = corto_ownerof(intermediate);
        valueIsObject = true;
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

    corto_int16 depth = corto_entityAdmin_getDepthFromId(path);
    corto_benchmark_stop(S_B_INIT);

    corto_entityAdmin *admin = corto_entityAdmin_get(&corto_subscriber_admin);
    if (!admin) {
        goto error;
    }

    do {
        corto_uint32 sp, s;
        corto_id relativeParent;

        for (sp = 0; sp < admin->entities[depth].length; sp ++) {
            corto_entityPerParent *subPerParent = &admin->entities[depth].buffer[sp];
            corto_bool relativeParentSet = FALSE;

            corto_benchmark_start(S_B_MATCHPARENT);
            char *expr = corto_matchParent(subPerParent->parent, path);
            if (!expr) {
                continue;
            }
            corto_benchmark_stop(S_B_MATCHPARENT);

            for (s = 0; s < subPerParent->entities.length; s ++) {
                corto_entity *sub = &subPerParent->entities.buffer[s];
                corto_subscriber s = sub->e;
                corto_word content = 0;
                corto_object instance = sub->instance;

                if (!s->query.select) {
                    continue;
                }

                if (instance && (instance == owner)) {
                    continue;
                }

                if (s->query.type && strcmp(s->query.type, type)) {
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
                char *parentPtr = relativeParent;
                if (!relativeParentSet) {
                    corto_benchmark_start(S_B_PATHID);
                    if (sep) *sep = '\0';
                    corto_id fromElem, toElem;
                    char *fromElemPtr = fromElem;

                    if (subPerParent->parent && subPerParent->parent[1]) {
                        strcpy(fromElem, subPerParent->parent);
                    } else {
                        fromElemPtr = NULL;
                    }

                    if (fromElemPtr && fromElemPtr[0]) {
                        if (parent[1] && parent[0] == '/') {
                            strcpy(toElem, &parent[1]);
                        } else {
                            strcpy(toElem, parent);
                        }
                    } else {
                        if (parent[1] || parent[0] != '/') {
                            toElem[0] = '/';
                            strcpy(&toElem[1], parent);
                        } else {
                            strcpy(toElem, parent);
                        }
                    }

                    /* pathstr modifies from & to buffers */
                    corto_pathstr(relativeParent, fromElemPtr, toElem, "/");
                    corto_benchmark_stop(S_B_PATHID);
                    relativeParentSet = TRUE;
                }

                /* Subscribers with query.from set to '/' and null share the
                 * same computed relative parent, however for subscribers with
                 * '/' we need to strip the initial '/' */
                if (s->query.from && !s->query.from[1] && (s->query.from[0] == '/')) {
                    if (parentPtr[0] == '/' && parentPtr[1]) {
                        parentPtr ++;
                    } else {
                        parentPtr = ".";
                    }
                }

                corto_result r = {
                  .id = id,
                  .name = NULL,
                  .parent = parentPtr,
                  .type = type,
                  .value = content,
                  .flags = 0,
                  .object = valueIsObject ? intermediate : NULL,
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

    if (corto_subscriber_admin.count && corto_checkAttr(o, CORTO_ATTR_NAMED)) {
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
    corto_ptr_setstr(&s->query.from, r->scope);

    if (r->scope && *r->scope) {
        if (*r->scope != '/') {
            corto_asprintf(&s->query.from, "/%s", r->scope);
        } else {
            s->query.from = corto_strdup(r->scope);
        } 
    } else {
        s->query.from = NULL;
    }

    corto_ptr_setstr(&s->query.select, r->expr);
    corto_ptr_setstr(&s->contentType, r->contentType);
    corto_ptr_setref(&((corto_observer)s)->instance, r->instance);
    corto_ptr_setref(&((corto_observer)s)->dispatcher, r->dispatcher);
    corto_ptr_setstr(&s->query.type, r->type);
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

static corto_subscribe__fluent corto_subscribe__fluentGet(void);

static corto_subscribe__fluent corto_subscribeContentType(
    corto_string contentType)
{
    corto_subscribeRequest *request = corto_threadTlsGet(CORTO_KEY_FLUENT);
    if (request) {
        request->contentType = contentType;
    }
    return corto_subscribe__fluentGet();
}

static corto_subscribe__fluent corto_subscribeType(
    corto_string type)
{
    corto_subscribeRequest *request = corto_threadTlsGet(CORTO_KEY_FLUENT);
    if (request) {
        request->type = type;
    }
    return corto_subscribe__fluentGet();
}

static corto_subscribe__fluent corto_subscribeInstance(
    corto_object instance)
{
    corto_subscribeRequest *request = corto_threadTlsGet(CORTO_KEY_FLUENT);
    if (request) {
        request->instance = instance;
    }
    return corto_subscribe__fluentGet();
}

static corto_subscribe__fluent corto_subscribeDisabled(void)
{
    corto_subscribeRequest *request = corto_threadTlsGet(CORTO_KEY_FLUENT);
    if (request) {
        request->enabled = FALSE;
    }
    return corto_subscribe__fluentGet();
}

static corto_subscribe__fluent corto_subscribeDispatcher(corto_dispatcher dispatcher)
{
    corto_subscribeRequest *request = corto_threadTlsGet(CORTO_KEY_FLUENT);
    if (request) {
        request->dispatcher = dispatcher;
    }
    return corto_subscribe__fluentGet();
}


static corto_subscribe__fluent corto_subscribeFrom(
    char *scope)
{
    corto_subscribeRequest *request = corto_threadTlsGet(CORTO_KEY_FLUENT);
    if (request) {
        request->scope = scope;
    }

    return corto_subscribe__fluentGet();
}

static corto_subscriber corto_subscribeCallback(
    void (*callback)(corto_subscriberEvent*))
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

static corto_subscribe__fluent corto_subscribe__fluentGet(void)
{
    corto_subscribe__fluent result;
    result.from = corto_subscribeFrom;
    result.contentType = corto_subscribeContentType;
    result.callback = corto_subscribeCallback;
    result.instance = corto_subscribeInstance;
    result.disabled = corto_subscribeDisabled;
    result.type = corto_subscribeType;
    result.dispatcher = corto_subscribeDispatcher;
    return result;
}

corto_subscribe__fluent corto_subscribe(
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

    request->enabled = TRUE;
    return corto_subscribe__fluentGet();
}

corto_int16 corto_unsubscribe(corto_subscriber subscriber, corto_object instance) {
    return corto_subscriber_unsubscribe(subscriber, instance);
}

static uint16_t corto_subscriber_unsubscribeIntern(
    corto_subscriber this, 
    corto_object instance, 
    bool removeAll) 
{
    int i, count = 
        corto_entityAdmin_remove(
            &corto_subscriber_admin, this->query.from, this, instance, removeAll);

    if (count < 0) {
        goto error;
    }

    /* Unsubscribe outside of lock for every instance that is unsubscribed */
    for (i = 0; i < count; i ++) {
        corto_select(this->query.select).from(this->query.from).instance(this).unsubscribe();
    }

    if (!removeAll) {
        /* Ensure that observer isn't deleted before instance unsubscribes */
        corto_release(this);
    }

    return 0;
error:
    return -1;
}


int16_t corto_subscriber_construct(
    corto_subscriber this)
{
    if (!this->query.select || !this->query.select[0]) {
        corto_seterr("'null' is not a valid subscriber expression");
        goto error;
    }

    if (this->contentType && !this->contentTypeHandle) {
        this->contentTypeHandle = (corto_word)corto_loadContentType(this->contentType);
        if (!this->contentTypeHandle) {
            goto error;
        }
    }

    this->matchProgram = (corto_word)corto_matchProgram_compile(this->query.select, TRUE, TRUE);
    if (!this->matchProgram) {
        goto error;
    }

    if (corto_observer(this)->enabled) {
        if (corto_subscriber_subscribe(this, corto_observer(this)->instance)) {
            goto error;
        }
    }

    if (this->query.type) {
        corto_type type = corto_resolve(NULL, this->query.type);
        if (type) {
            if (!corto_instanceof(corto_type_o, type)) {
                corto_seterr("'%s' is not a type", this->query.type);
                goto error;
            }
            corto_ptr_setref(&corto_observer(this)->type, type);
            corto_release(type);
        }

    } else if (corto_observer(this)->type) {
        corto_id id;
        corto_fullpath(id, corto_observer(this)->type);
        corto_ptr_setstr(&this->query.type, id);
    }

    return safe_corto_observer_construct(this);
error:
    return -1;
}

void corto_subscriber_deinit(
    corto_subscriber this)
{

    /* Delete matchProgram resources only when subscriber itself is deallocated 
     * as notifications might still take place when subscriber is deleted. */
    corto_matchProgram_free((corto_matchProgram)this->matchProgram);

}

void corto_subscriber_destruct(
    corto_subscriber this)
{

    /* Unsubscribe all entities of this subscriber */
    corto_subscriber_unsubscribeIntern(this, NULL, TRUE);

}

int16_t corto_subscriber_init(
    corto_subscriber this)
{
    corto_parameter *p;
    corto_function(this)->parameters.buffer = corto_calloc(sizeof(corto_parameter) * 1);
    corto_function(this)->parameters.length = 1;

    /* Parameter event */
    p = &corto_function(this)->parameters.buffer[0];
    p->name = corto_strdup("e");
    p->passByReference = FALSE;
    corto_ptr_setref(&p->type, corto_subscriberEvent_o);

    return safe_corto_function_init(this);
}

int16_t corto_subscriber_subscribe(
    corto_subscriber this,
    corto_object instance)
{
    corto_iter it;

    corto_debug("subscriber: '%s' subscribing for '%s', '%s'",
      corto_fullpath(NULL, this),
      this->query.from,
      this->query.select);

    /* If subscriber was not yet enabled, subscribe to mounts */
    corto_int16 ret;
    if (!this->contentType) {
        ret = corto_select(this->query.select)
          .from(this->query.from)
          .type(this->query.type)
          .instance(this) /* this prevents mounts from subscribing to themselves */
          .subscribe(&it);
    } else {
        ret = corto_select(this->query.select)
          .from(this->query.from)
          .type(this->query.type)
          .contentType(this->contentType)
          .instance(this) /* this prevents mounts from subscribing to themselves */
          .subscribe(&it);
    }
    if (ret) {
        goto error;
    }

    /* Add subscriber to global subscriber admin */
    corto_entityAdmin_add(
        &corto_subscriber_admin,
        this->query.from ? this->query.from : "/",
        this,
        instance);

    corto_observer(this)->enabled = TRUE;

    /* Ensure that subscriber isn't deleted before instance unsubscribes */
    corto_claim(this);

    /* Align subscriber */
    while (corto_iter_hasNext(&it)) {
        corto_result *r = corto_iter_next(&it);
        corto_subscriber_invoke(instance, CORTO_ON_DEFINE, r, this);
    }

    return 0;
error:
    return -1;
}

int16_t corto_subscriber_unsubscribe(
    corto_subscriber this,
    corto_object instance)
{
    corto_debug("subscriber '%s': unsubscribe for %s, %s",
      corto_fullpath(NULL, this),
      this->query.from,
      this->query.select);

    return corto_subscriber_unsubscribeIntern(this, instance, FALSE);
}

