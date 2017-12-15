/* This is a managed file. Do not delete this comment. */

#include <corto/corto.h>

#include <corto/entityadmin.h>
#include "src/store/object.h"
#include "../base/src/idmatch.h"

extern corto_tls CORTO_KEY_SUBSCRIBER_ADMIN;
extern corto_tls CORTO_KEY_FLUENT;

extern corto_rwmutex_s corto_subscriberLock;

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

static
corto_subscriberEvent* corto_subscriber_findEvent(
    corto_ll events,
    corto_subscriberEvent *e)
{
    corto_iter iter = corto_ll_iter(events);
    corto_subscriberEvent *e2;
    while ((corto_iter_hasNext(&iter))) {
        e2 = corto_iter_next(&iter);
        if (!strcmp(e2->data.id, e->data.id) &&
            !strcmp(e2->data.parent, e->data.parent))
        {
            return e2;
        }
    }
    return NULL;
}

static
void corto_subscriber_addToAlignQueue(
    corto_subscriber s,
    corto_subscriberEvent *event)
{
    corto_subscriberEvent *oldEvent =
        corto_subscriber_findEvent(s->alignQueue, event);

    if (oldEvent) {
        corto_ll_replace(s->alignQueue, oldEvent, event);
        corto_assert(corto_release(oldEvent) == 0, "subscriber event leaks");
    } else {
        corto_ll_append(s->alignQueue, event);
    }
    corto_claim(event);
}

static
int16_t corto_subscriber_invoke(
    corto_object instance,
    corto_eventMask mask,
    corto_result *r,
    corto_subscriber s,
    corto_subscriberEvent *eptr)
{
    corto_dispatcher dispatcher = corto_observer(s)->dispatcher;

    if (!dispatcher && !s->isAligning) {
        /* Deliver synchronously if the subscriber does not have a dispatcher
         * and is not aligning data. */
        corto_function f = corto_function(s);

        corto_subscriberEvent e;
        if (!eptr) {
            e = (corto_subscriberEvent){
                .instance = instance,
                .event = mask,
                .source = NULL,
                .subscriber = s,
                .data = *r
            };
            eptr = &e;
        }

        if (f->kind == CORTO_PROCEDURE_CDECL) {
            if (f->fptr) {
                ((void(*)(corto_subscriberEvent*))((corto_function)s)->fptr)(eptr);
            }
        } else {
            void *args[] = {&eptr};
            corto_callb((corto_function)s, NULL, args);
        }
    } else {
        if (!eptr) {
            eptr = corto_declare(corto_subscriberEvent_o);
            corto_ptr_setref(&eptr->subscriber, s);
            corto_ptr_setref(&eptr->instance, instance);
            corto_ptr_setref(&eptr->source, NULL);
            eptr->event = mask;
            corto_ptr_setstr(&eptr->data.id, r->id);
            corto_ptr_setstr(&eptr->data.type, r->type);
            corto_ptr_setstr(&eptr->data.parent, r->parent);
            if (r->value) {
                eptr->data.value =
                  ((corto_contentType)s->contentTypeHandle)->copy(r->value);
            }
            eptr->contentTypeHandle = s->contentTypeHandle;
            if (corto_define(eptr)) {
                goto error;
            }
        }

        if (!s->isAligning) {
            corto_dispatcher_post(dispatcher, corto_event(eptr));
        } else {
            corto_subscriber_addToAlignQueue(s, eptr);
        }
    }

    return 0;
error:
    return -1;
}

static
int16_t corto_subscriber_flushAlignQueue(
    corto_subscriber s)
{
    corto_subscriberEvent *e;
    while ((e = corto_ll_takeFirst(s->alignQueue))) {
        if (corto_subscriber_invoke(NULL, 0, NULL, s, e)) {
            corto_release(e);
            goto error;
        }
        corto_release(e);
    }

    return 0;
error:
    return -1;
}

static
char tochar(
    char *to,
    char *ptr,
    int len)
{
    if (len > 0) {
        if (ptr - to < len) {
            return ptr[0];
        } else {
            return '\0';
        }
    } else {
        return ptr[0];
    }
}

#define tch tochar(to, tptr, tolen)

static bool chicmp(char ch1, char ch2) {
    if (ch1 < 97) ch1 = tolower(ch1);
    if (ch2 < 97) ch2 = tolower(ch2);
    return ch1 == ch2;
}

/* Function returns the 'to' path relative to 'from', and ensures that the
 * output can be used in an "from + / + out + / + id" expression to reconstruct
 * a correct full path to an object. */
void corto_pathstr(
    char *out,
    char *from,
    char *to,
    int tolen)
{
    char *outptr = out, *firstid = out;

    /* If 'from' is empty, and 'to' contains a path to an object other than
     * root, construct a 'from' that includes the root, so that a user can do
     * out + '/' + id to create the full path. If 'to' is pointing to root, do
     * not append root, as out + '/' + id would then result in a double '/' */
    if (!from || !from[0]) {
        bool to_isRoot = to && (to[0] == '/') && !to[1];
        if (!to_isRoot) {
            (outptr ++)[0] = '/';
            firstid++;
        } else {
            /* If to is root, and from is empty return an empty string */
            (outptr++)[0] = '\0';
            return;
        }
    }

    char *fptr = from ? from[0] == '/' ? &from[1] : from : "";
    char *tptr = to ? to[0] == '/' ? &to[1] : to : "";

    /* First, move ptrs until paths diverge */
    while (fptr[0] && chicmp(fptr[0], tch)) {
        fptr ++;
        tptr ++;
    }

    /* Check if paths are equal */
    if (!fptr[0] && !tch) {
        (outptr++)[0] = '.';
    } else if (fptr[0]) {
        /* If fptr was split on a '..', don't insert a '..' for that */
        if (fptr[0] == '/') fptr ++;

        /* Next, for every identifier in 'from', add '..' */
        while (fptr[0]) {
            if (fptr[0] == '/') {
                if (outptr != firstid) (outptr++)[0] = '/';
                (outptr++)[0] = '.';
                (outptr++)[0] = '.';
            }
            fptr ++;
        }
        /* Add '..' for last identifier */
        if (outptr != firstid) (outptr++)[0] = '/';
        (outptr++)[0] = '.';
        (outptr++)[0] = '.';
    }

    /* Finally, append remaining elements from to */
    if (tch) {
        if (tch == '/') tptr ++;
        if (outptr != firstid) (outptr++)[0] = '/';
        do {
            (outptr++)[0] = tch;
            tptr ++;
        } while (tch);
    }
    outptr[0] = '\0';
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
    if (!(mask & (CORTO_DEFINE|CORTO_UPDATE|CORTO_DELETE))) {
        return 0;
    }

    /* Don't notify when shutting down */
    if (CORTO_APP_STATUS != 0) {
        return 0;
    }

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

    int sepLength = sep
        ? sep - path
        : 0
        ;

    corto_int16 depth = corto_entityAdmin_getDepthFromId(path);

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

            char *expr = corto_matchParent(subPerParent->parent, path);
            if (!expr) {
                continue;
            }

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

                /* Id match program kind 3 is '*'. Because we already gathered
                 * some information about the identifier, it is faster to
                 * evaluate this simple expression here. */
                corto_idmatch_program match = (corto_idmatch_program)s->idmatch;
                if (match->kind != 3) {
                    if (!corto_idmatch_run(match, expr)) {
                        continue;
                    }
                } else if ((sep > expr) || expr[0] == '.') {
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

                        /* Has source contentType been loaded? */
                        if (contentType && !contentTypeHandle) {
                            /* Load contentType */
                            contentTypeHandle = corto_load_contentType(contentType);
                            if (!contentTypeHandle) {
                                goto error;
                            }

                            /* Resolve type of object */
                            corto_type t = corto_resolve(NULL, type);
                            if (!t) {
                                corto_throw("failed to resolve type '%s'", type);
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
                }

                /* Relative parent will be the same for each subscriber at same depth */
                char *parentPtr = relativeParent;
                if (!relativeParentSet) {
                    char *fromptr = subPerParent->parent;
                    /* If 'from' is '/', move up one character, This ensures that
                     * the same relativeParent buffer can be used for subscribers
                     * that start their from with and without '/'. */
                    if (!fromptr[1]) {
                        fromptr ++;
                    }
                    corto_pathstr(relativeParent, fromptr, parent, sepLength);
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

                if (s->isAligning) {
                    if (corto_mutex_lock((corto_mutex)s->alignMutex)) {
                        goto error;
                    }

                    corto_subscriber_invoke(instance, mask, &r, s, NULL);

                    if (corto_mutex_unlock((corto_mutex)s->alignMutex)) {
                        goto error;
                    }
                } else {
                    corto_subscriber_invoke(instance, mask, &r, s, NULL);
                }
            }
        }
    } while (--depth >= 0);

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

    if (corto_subscriber_admin.count && corto_checkAttr(o, CORTO_ATTR_NAMED)) {
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
    corto_ptr_setstr(&s->query.from, r->scope);

    if (r->scope && *r->scope) {
        if (*r->scope != '/') {
            s->query.from = corto_asprintf("/%s", r->scope);
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
    corto_subscribeRequest *request = corto_tls_get(CORTO_KEY_FLUENT);
    if (request) {
        request->contentType = contentType;
    }
    return corto_subscribe__fluentGet();
}

static corto_subscribe__fluent corto_subscribeType(
    corto_string type)
{
    corto_subscribeRequest *request = corto_tls_get(CORTO_KEY_FLUENT);
    if (request) {
        request->type = type;
    }
    return corto_subscribe__fluentGet();
}

static corto_subscribe__fluent corto_subscribeInstance(
    corto_object instance)
{
    corto_subscribeRequest *request = corto_tls_get(CORTO_KEY_FLUENT);
    if (request) {
        request->instance = instance;
    }
    return corto_subscribe__fluentGet();
}

static corto_subscribe__fluent corto_subscribeDisabled(void)
{
    corto_subscribeRequest *request = corto_tls_get(CORTO_KEY_FLUENT);
    if (request) {
        request->enabled = FALSE;
    }
    return corto_subscribe__fluentGet();
}

static corto_subscribe__fluent corto_subscribeDispatcher(corto_dispatcher dispatcher)
{
    corto_subscribeRequest *request = corto_tls_get(CORTO_KEY_FLUENT);
    if (request) {
        request->dispatcher = dispatcher;
    }
    return corto_subscribe__fluentGet();
}


static corto_subscribe__fluent corto_subscribeFrom(
    char *scope)
{
    corto_subscribeRequest *request = corto_tls_get(CORTO_KEY_FLUENT);
    if (request) {
        request->scope = scope;
    }

    return corto_subscribe__fluentGet();
}

static corto_subscriber corto_subscribeCallback(
    void (*callback)(corto_subscriberEvent*))
{
    corto_subscriber result = NULL;

    corto_subscribeRequest *request = corto_tls_get(CORTO_KEY_FLUENT);
    if (request) {
        request->callback = callback;
        corto_tls_set(CORTO_KEY_FLUENT, NULL);
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

    corto_subscribeRequest *request = corto_tls_get(CORTO_KEY_FLUENT);
    if (!request) {
        request = corto_calloc(sizeof(corto_subscribeRequest));
        corto_tls_set(CORTO_KEY_FLUENT, request);
    } else {
        memset(request, 0, sizeof(corto_subscribeRequest));
    }

    va_start(arglist, expr);
    request->expr = corto_vasprintf(expr, arglist);
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

void corto_subscriber_define(
    corto_subscriber this)
{
    if (corto_unlock(this)) {
        corto_throw(NULL);
        corto_raise();
    }

    if (corto_observer(this)->enabled) {
        if (corto_subscriber_subscribe(this, corto_observer(this)->instance)) {
            corto_raise();
        }
    }

    if (corto_lock(this)) {
        corto_throw(NULL);
        corto_raise();
    }
}

int16_t corto_subscriber_construct(
    corto_subscriber this)
{
    corto_log_push("subscribe");

    if (!this->query.select || !this->query.select[0]) {
        corto_throw("'null' is not a valid subscriber expression");
        goto error;
    }

    if (this->contentType && !this->contentTypeHandle) {
        this->contentTypeHandle = (corto_word)corto_load_contentType(this->contentType);
        if (!this->contentTypeHandle) {
            goto error;
        }
    }

    this->idmatch = (corto_word)corto_idmatch_compile(this->query.select, TRUE, TRUE);
    if (!this->idmatch) {
        goto error;
    }

    if (this->query.type) {
        corto_type type = corto_resolve(NULL, this->query.type);
        if (type) {
            if (!corto_instanceof(corto_type_o, type)) {
                corto_throw("'%s' is not a type", this->query.type);
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

    int16_t result = safe_corto_observer_construct(this);
    corto_log_pop();
    return result;
error:
    corto_log_pop();
    return -1;
}

void corto_subscriber_deinit(
    corto_subscriber this)
{

    /* Delete idmatch resources only when subscriber itself is deallocated
     * as notifications might still take place when subscriber is deleted. */
    corto_idmatch_free((corto_idmatch_program)this->idmatch);

}

void corto_subscriber_destruct(
    corto_subscriber this)
{

    /* Unsubscribe all entities of this subscriber */
    corto_subscriber_unsubscribeIntern(this, NULL, TRUE);

    corto_mutex_free((corto_mutex)this->alignMutex);
    free((corto_mutex)this->alignMutex);
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

    this->alignMutex = (uintptr_t)corto_alloc(sizeof(corto_mutex_s));
    if (corto_mutex_new((corto_mutex)this->alignMutex)) {
        goto error;
    }

    return safe_corto_function_init(this);
error:
    return -1;
}

int16_t corto_subscriber_subscribe(
    corto_subscriber this,
    corto_object instance)
{
    corto_iter it;

    if (corto_checkAttr(this, CORTO_ATTR_NAMED)) {
        corto_debug("ID '%s'", corto_fullpath(NULL, this));
    }

    corto_debug("SELECT '%s'", this->query.select);
    if (this->query.from) {
        corto_debug("FROM '%s'", this->query.from);
    }
    if (this->query.type) {
        corto_debug("TYPE '%s'", this->query.type);
    }

    this->isAligning = true;

    /* Add subscriber to global subscriber admin */
    corto_entityAdmin_add(
        &corto_subscriber_admin,
        this->query.from ? this->query.from : "/",
        this,
        instance);

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

    corto_observer(this)->enabled = TRUE;

    /* Ensure that subscriber isn't deleted before instance unsubscribes */
    corto_claim(this);

    /* Align subscriber */
    while (corto_iter_hasNext(&it)) {
        corto_result *r = corto_iter_next(&it);
        corto_subscriber_invoke(instance, CORTO_DEFINE, r, this, NULL);
    }

    corto_mutex_lock((corto_mutex)this->alignMutex);
    this->isAligning = false;
    if (corto_subscriber_flushAlignQueue(this)) {
        corto_mutex_unlock((corto_mutex)this->alignMutex);
        goto error;
    }
    corto_mutex_unlock((corto_mutex)this->alignMutex);

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
