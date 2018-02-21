/* This is a managed file. Do not delete this comment. */

#include <corto/corto.h>

#include <corto/entityadmin.h>
#include "src/store/object.h"
#include "../platform/src/idmatch.h"

extern corto_tls CORTO_KEY_SUBSCRIBER_ADMIN;
extern corto_tls CORTO_KEY_FLUENT;

extern corto_rwmutex_s corto_subscriberLock;

/* Fluent request */
typedef struct corto_subscribeRequest {
    int16_t err;
    corto_object instance;
    const char *scope;
    char *expr;
    const char *type;
    const char *contentType;
    corto_dispatcher dispatcher;
    bool enabled;
    void (*callback)(corto_subscriber_event*);
} corto_subscribeRequest;

corto_entityAdmin corto_subscriber_admin = {0, 0, CORTO_RWMUTEX_INIT, 0, 0, CORTO_MUTEX_INIT, CORTO_COND_INIT};

static
const char tochar(
    const char *to,
    const char *ptr,
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

static
bool chicmp(
    char ch1,
    char ch2)
{
    if (ch1 < 97) ch1 = tolower(ch1);
    if (ch2 < 97) ch2 = tolower(ch2);
    return ch1 == ch2;
}

/* Function returns the 'to' path relative to 'from', and ensures that the
 * output can be used in an "from + / + out + / + id" expression to reconstruct
 * a correct full path to an object. */
void corto_pathstr(
    char *out,
    const char *from,
    const char *to,
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

    const char *fptr = from ? from[0] == '/' ? &from[1] : from : "";
    const char *tptr = to ? to[0] == '/' ? &to[1] : to : "";

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

static
int corto_subscriber_findEvent(
    void *o1,
    void *o2)
{
    corto_subscriber_event *e1 = o1, *e2 = o2;
    if (!strcmp(e2->data.id, e1->data.id) &&
        !strcmp(e2->data.parent, e1->data.parent))
    {
        return false;
    }
    return true;
}

static
void corto_subscriber_addToAlignQueue(
    corto_subscriber this,
    corto_subscriber_event *e)
{
    void *ptr = corto_ll_findPtr(this->alignQueue, corto_subscriber_findEvent, e);
    if (ptr) {
        *(void**)ptr = e;
    } else {
        corto_ll_append(this->alignQueue, e);
    }
}

typedef struct corto_fmtcache {
    corto_fmt src_handle;
    uintptr_t src_ptr;
    void* o;
    corto_value v;
    const char *type;
    corto_fmt_data cache[CORTO_MAX_CONTENTTYPE];
    int32_t count;
} corto_fmtcache;

static
corto_fmtcache corto_fmtcache_init(
    corto_fmt src_handle,
    uintptr_t src_ptr,
    void* o,
    const char *type)
{
    corto_fmtcache result = {
        .src_handle = src_handle,
        .src_ptr = src_ptr,
        .o = o,
        .type = type,
        .count = 1
    };

    /* Reserve first spot for format of publisher */
    result.cache[0].handle = (uintptr_t)src_handle;
    result.cache[0].ptr = src_ptr;
    result.cache[0].shared_count = 0;

    if (o) {
        result.v = corto_value_object(o, NULL);
    }

    return result;
}

static
corto_fmt_data* corto_fmtcache_serialize(
    corto_fmtcache *this,
    corto_fmt dst_handle,
    bool copy)
{
    int32_t index = -1;

    if (dst_handle && this->src_handle && dst_handle == this->src_handle) {
        /* Requested same format as provided by publisher */
        index = 0;

    } else if (dst_handle && this->src_ptr) {
        /* Subcsriber requests different format */

        /* Check if format has been serialized */
        for (index = 0; index < this->count; index++) {
            if (this->cache[index].handle == (uintptr_t)dst_handle) {
                /* Index points to correct format */
                break;
            }
        }

        if (index == this->count) {
            /* Format has not yet been serialized */

            if (!this->o) {
                /* Create intermediate object for serializing between formats */

                /* Resolve type of object */
                corto_type type = corto_resolve(NULL, this->type);
                corto_try(!type, "failed to resolve type '%s'", this->type);

                /* Create intermediate object */
                this->o = corto_mem_new(type);

                corto_try(!this->o, NULL);
                corto_release(type);

                /* Serialize from source format to intermediate object */
                this->v = corto_value_mem(this->o, type);
                corto_try (
                    this->src_handle->toValue(&this->v, this->src_ptr), NULL);
            }

            /* Serialize to destination format */
            this->cache[index].ptr = dst_handle->fromValue(&this->v);
            this->cache[index].handle = (uintptr_t)dst_handle;
            this->count ++;
        }
    }

    if (copy) {
        if (!this->cache[index].shared_count) {
            this->cache[index].shared_count = (uintptr_t)malloc(sizeof(int32_t));

            /* Give it an initial count of two, so it is guaranteed that the
             * serialized value won't be deleted until we finish notifying. The
             * additional count is for the asynchronous subscriber that is
             * currently requesting the serialization. */
            *(int32_t*)this->cache[index].shared_count = 2;
        } else {
            /* Do an atomic incrememt, as asynchronous subscribers may already
             * have been notified */
            corto_ainc((int32_t*)this->cache[index].shared_count);
        }
    }

    return &this->cache[index];
error:
    return NULL;
}

static
void corto_fmtcache_deinit(
    corto_fmtcache *this)
{
    /* Only cleanup first element when it has a shared count */
    if (this->cache[0].shared_count) {
        corto_fmt_data_deinit(&this->cache[0]);
    }
    int i;
    for (i = 1; i < this->count; i ++) {
        corto_fmt_data_deinit(&this->cache[i]);
    }

    /* If src_handle is provided, the object is an intermediate object */
    if (this->o && this->src_handle) {
        if (this->v.kind == CORTO_MEM) {
            corto_mem_free(this->o);
        } else if (this->v.kind == CORTO_OBJECT) {
            corto_release(this->o);
        }
    }
}

static
int16_t corto_subscriber_invoke(
    corto_object instance,
    corto_eventMask mask,
    corto_result *r,
    corto_subscriber s,
    corto_subscriber_event *existing_event,
    corto_fmtcache *cache)
{
    corto_dispatcher dispatcher = ((corto_observer)s)->dispatcher;
    corto_subscriber_event *event = existing_event;
    corto_fmt_data *fmt = NULL;
    bool synchronous = !dispatcher && !s->isAligning;

    if (cache && s->fmt_handle) {
        /* Use serialization cache if available & if subscriber requests a
         * destination format. */
        fmt = corto_fmtcache_serialize(
            cache, (corto_fmt)s->fmt_handle, !synchronous);
    }

    if (synchronous) {
        /* Deliver synchronously if the subscriber does not have a dispatcher
         * and is not aligning data. */

        corto_function f = corto_function(s);
        corto_subscriber_event e;

        if (!event) {
            e = (corto_subscriber_event){
                .instance = instance,
                .event = mask,
                .source = NULL,
                .subscriber = s,
                .data = *r,
            };
            if (fmt) {
                e.fmt = *fmt;
                e.data.value = fmt->ptr;
            }
            event = &e;
        }

        if (f->kind == CORTO_PROCEDURE_CDECL) {
            if (f->fptr) {
                ((void(*)(corto_subscriber_event*))((corto_function)s)->fptr)(event);
            }
        } else {
            void *args[] = {&event};
            corto_invokeb((corto_function)s, NULL, args);
        }
        if (event != &e) {
            /* When an existing_event was provided but needs to be synchronously
             * delivered, this is an event from the alignment queue, and can be
             * deleted after it has used. */
            corto_try (corto_delete(event), NULL);
        }
    } else {
        /* Asynchronously deliver event to subscriber. If no event was provided,
         * create a new one */
        if (!event) {
            event = corto(CORTO_DECLARE, {.type = corto_subscriber_event_o, .attrs = -1});
            corto_set_ref(&event->subscriber, s);
            corto_set_ref(&event->instance, instance);
            corto_set_ref(&event->source, NULL);
            corto_set_str(&event->data.id, r->id);
            corto_set_str(&event->data.type, r->type);
            corto_set_str(&event->data.parent, r->parent);
            corto_set_ref(&event->data.object, r->object);
            event->event = mask;
            if (fmt) {
                event->data.value = fmt->ptr;
                event->fmt = *fmt;
            } else {
                event->data.value = r->value;
            }
            corto_try (corto_define(event), NULL);
        }

        if (s->isAligning) {
            /* If this happens during alignment, add event to alignment queue.
             * Ownership of event is transferred to align queue. */
            corto_subscriber_addToAlignQueue(s, event);
        } else {
            /* Deliver event to dispatcher */
            corto_dispatcher_post(dispatcher, (corto_event*)event);
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
    corto_subscriber_event *e;
    while ((e = corto_ll_takeFirst(s->alignQueue))) {
        if (corto_subscriber_invoke(NULL, 0, NULL, s, e, NULL)) {
            corto_release(e);
            goto error;
        }

        /* No need to release event. Ownership is transferred to invoke */
    }

    return 0;
error:
    return -1;
}

int16_t corto_notify_subscribersById(
    corto_eventMask mask,
    const char *path,
    const char *type,
    const char *fmt,
    corto_word value)
{
    /* If there are no subscribers, quickly return */
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

    /* Intermediate object used for serializing between formats */
    corto_object o = NULL;
    corto_object owner = corto_get_source();
    corto_object object_source = owner;
    bool value_is_object = false;

    /* Lookup publisher format */
    corto_fmt fmt_handle = fmt ? corto_fmt_lookup(fmt) : NULL;
    if (fmt && !fmt_handle) {
        corto_throw("failed to load format '%s'", fmt);
        goto error;
    }

    /* If value is set but no format is provided, the value is an object */
    if (!fmt_handle && value) {
        /* Use provided object as intermediate, no extra serialization needed */
        o = (corto_object)value;
        object_source = corto_sourceof(o);
        value_is_object = true;
    }

    /* Temporary storage for serialized values */
    corto_fmtcache cache = corto_fmtcache_init(fmt_handle, value, o, type);

    /* Normalize id and path */
    const char *sep = NULL, *id = strrchr(path, '/');
    const char *parent = NULL;
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

    /* Determine depth at which subscribers should start being invoked */
    int16_t depth = corto_entityAdmin_claimDepthFromId(path);

    /* Obtain global administration with subscribers */
    corto_entityAdmin *admin = corto_entityAdmin_claim(&corto_subscriber_admin);
    corto_try(!admin, NULL);

    do {
        uint32_t sp, s;
        corto_id relativeParent;

        /* Walk parents at specified depth */
        for (sp = 0; sp < admin->entities[depth].length; sp ++) {
            corto_entityPerParent *subPerParent = &admin->entities[depth].buffer[sp];
            bool relativeParentSet = FALSE;

            /* Verify if path matches with subscribers in current branch */
            const char *expr = corto_matchParent(subPerParent->parent, path);
            if (!expr) {
                continue;
            }

            /* Walk subscribers for parent */
            for (s = 0; s < subPerParent->entities.length; s ++) {
                corto_entity *sub = &subPerParent->entities.buffer[s];
                corto_subscriber s = sub->e;
                corto_object instance = sub->instance;

                if (!s->query.select) {
                    continue;
                }

                /* If notification comes from subscriber instance, ignore */
                if (instance && (instance == owner)) {
                    continue;
                }

                /* Verify that subscription type matches */
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
                  .id = (char*)id,
                  .name = NULL,
                  .parent = parentPtr,
                  .type = (char*)type,
                  .flags = 0,
                  .object = value_is_object ? o : NULL,
                  .owner = object_source
                };

                bool isAligning = s->isAligning;
                if (isAligning) { corto_try(
                    corto_mutex_lock((corto_mutex)s->alignMutex), NULL
                );}
                corto_subscriber_invoke(instance, mask, &r, s, NULL, &cache);
                if (isAligning) { corto_try(
                    corto_mutex_unlock((corto_mutex)s->alignMutex), NULL
                );}
            }
        }
    } while (--depth >= 0);

    corto_entityAdmin_release(&corto_subscriber_admin);
    corto_fmtcache_deinit(&cache);
    return 0;
error:
    corto_entityAdmin_release(&corto_subscriber_admin);
    corto_fmtcache_deinit(&cache);
    return -1;
}

int16_t corto_notify_subscribers(corto_eventMask mask, corto_object o) {
    int16_t result = 0;

    if (corto_subscriber_admin.count && corto_check_attr(o, CORTO_ATTR_NAMED)) {
        corto_id path, type;

        result = corto_notify_subscribersById(
          mask,
          corto_fullpath(path, o),
          corto_fullpath(type, corto_typeof(o)),
          NULL,
          (corto_word)o);
    }

    return result;
}

static
corto_subscriber corto_subscribeSubscribe(
    corto_subscribeRequest *r)
{
    corto_subscriber s = corto_declare(NULL, NULL, corto_subscriber_o);
    corto_set_str(&s->query.from, r->scope);

    if (r->scope && *r->scope) {
        if (*r->scope != '/') {
            s->query.from = corto_asprintf("/%s", r->scope);
        } else {
            s->query.from = corto_strdup(r->scope);
        }
    } else {
        s->query.from = NULL;
    }

    corto_set_str(&s->query.select, r->expr);
    corto_set_str(&s->contentType, r->contentType);
    corto_set_ref(&((corto_observer)s)->instance, r->instance);
    corto_set_ref(&((corto_observer)s)->dispatcher, r->dispatcher);
    corto_set_str(&s->query.type, r->type);
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

static
corto_subscribe__fluent corto_subscribe__fluentGet(void);

static
corto_subscribe__fluent corto_subscribeContentType(
    const char *contentType)
{
    corto_subscribeRequest *request = corto_tls_get(CORTO_KEY_FLUENT);
    if (request) {
        request->contentType = contentType;
    }
    return corto_subscribe__fluentGet();
}

static
corto_subscribe__fluent corto_subscribeType(
    const char *type)
{
    corto_subscribeRequest *request = corto_tls_get(CORTO_KEY_FLUENT);
    if (request) {
        request->type = type;
    }
    return corto_subscribe__fluentGet();
}

static
corto_subscribe__fluent corto_subscribeInstance(
    corto_object instance)
{
    corto_subscribeRequest *request = corto_tls_get(CORTO_KEY_FLUENT);
    if (request) {
        request->instance = instance;
    }
    return corto_subscribe__fluentGet();
}

static
corto_subscribe__fluent corto_subscribeDisabled(void)
{
    corto_subscribeRequest *request = corto_tls_get(CORTO_KEY_FLUENT);
    if (request) {
        request->enabled = FALSE;
    }
    return corto_subscribe__fluentGet();
}

static
corto_subscribe__fluent corto_subscribeDispatcher(
    corto_dispatcher dispatcher)
{
    corto_subscribeRequest *request = corto_tls_get(CORTO_KEY_FLUENT);
    if (request) {
        request->dispatcher = dispatcher;
    }
    return corto_subscribe__fluentGet();
}


static
corto_subscribe__fluent corto_subscribeFrom(
    const char *scope)
{
    corto_subscribeRequest *request = corto_tls_get(CORTO_KEY_FLUENT);
    if (request) {
        request->scope = scope;
    }

    return corto_subscribe__fluentGet();
}

static
corto_subscriber corto_subscribeCallback(
    void (*callback)(corto_subscriber_event*))
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

static
corto_mount corto_subscribeMount(
    corto_class type,
    corto_mountPolicy *policy,
    const char *value)
{
    corto_subscribeRequest *r = corto_tls_get(CORTO_KEY_FLUENT);
    corto_fmt fmt = NULL;
    if (value) {
        fmt = corto_fmt_lookup("text/corto");
    }

    /* declareChild */
    corto_mount m = corto(CORTO_DECLARE|CORTO_FORCE_TYPE, {.type = type});

    corto_subscriber s = corto_subscriber(m);
    corto_query *q = &s->query;
    corto_set_str(&q->from, r->scope);
    corto_set_str(&q->select, r->expr);
    corto_set_str(&q->type, r->type);
    corto_set_str(&s->contentType, r->contentType);

    ((corto_observer)s)->enabled = true;
    if (policy) {
        m->policy = *policy;
    }

    corto_tls_set(CORTO_KEY_FLUENT, NULL);
    free(r);

    /* define & set value if provided */
    return corto(CORTO_DEFINE, {.object = m, .fmt = fmt, .value = value});
}

static
corto_subscribe__fluent corto_subscribe__fluentGet(void)
{
    corto_subscribe__fluent result;
    result.from = corto_subscribeFrom;
    result.contentType = corto_subscribeContentType;
    result.callback = corto_subscribeCallback;
    result.instance = corto_subscribeInstance;
    result.disabled = corto_subscribeDisabled;
    result.type = corto_subscribeType;
    result.dispatcher = corto_subscribeDispatcher;
    result.mount = corto_subscribeMount;
    return result;
}

corto_subscribe__fluent corto_subscribe(
    const char *expr,
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

int16_t corto_unsubscribe(corto_subscriber subscriber, corto_object instance) {
    return corto_subscriber_unsubscribe(subscriber, instance);
}

static
uint16_t corto_subscriber_unsubscribeIntern(
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
        corto_select(this->query.select)
        .from(this->query.from)
        .instance(this)
        .unsubscribe();
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

    if (this->contentType && !this->fmt_handle) {
        this->fmt_handle = (corto_word)corto_fmt_lookup(this->contentType);
        if (!this->fmt_handle) {
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
            corto_set_ref(&corto_observer(this)->type, type);
            corto_release(type);
        }

    } else if (corto_observer(this)->type) {
        corto_id id;
        corto_fullpath(id, corto_observer(this)->type);
        corto_set_str(&this->query.type, id);
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
    corto_set_ref(&p->type, corto_subscriber_event_o);

    this->alignMutex = (uintptr_t)corto_alloc(sizeof(corto_mutex_s));
    if (corto_mutex_new((corto_mutex)this->alignMutex)) {
        goto error;
    }

    this->alignQueue = corto_ll_new();

    return safe_corto_function_init(this);
error:
    return -1;
}

int16_t corto_subscriber_subscribe(
    corto_subscriber this,
    corto_object instance)
{
    corto_iter it;

    if (corto_check_attr(this, CORTO_ATTR_NAMED)) {
        corto_debug("ID '%s'", corto_fullpath(NULL, this));
    }

    corto_debug("SELECT '%s'", this->query.select);
    if (this->query.from) {
        corto_debug("FROM '%s'", this->query.from);
    }
    if (this->query.type) {
        corto_debug("TYPE '%s'", this->query.type);
    }

    /* Add subscriber to global subscriber admin */
    corto_entityAdmin_add(
        &corto_subscriber_admin,
        this->query.from ? this->query.from : "/",
        this,
        instance);

    /* If subscriber was not yet enabled, subscribe to mounts */
    int16_t ret;
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

    /* Ensure that subscriber isn't deleted before instance unsubscribes */
    corto_claim(this);

    /* Align subscriber */
    corto_mutex_lock((corto_mutex)this->alignMutex);
    this->isAligning = true;

    /* Enable observer within aligner lock, so no messages are delivered before
     * alignment has started */
    corto_observer(this)->enabled = TRUE;

    if (corto_ll_count(this->alignQueue)) {
        corto_warning("messages in align queue before aligned messages");
    }

    /* Populate alignment queue. Any message delivered to the subscriber will
     * end up in the queue */
    while (corto_iter_hasNext(&it)) {
        corto_result *r = corto_iter_next(&it);
        corto_subscriber_invoke(instance, CORTO_DEFINE, r, this, NULL, NULL);

        /* Nifty trick to take ownership of the serialized value- that way there
         * is no need to make a copy. The corto_select function will now not
         * attempt to free the serialized value. */
        r->value = 0;
    }

    this->isAligning = false;

    /* Flush messages in alignQueue to subscriber */
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
