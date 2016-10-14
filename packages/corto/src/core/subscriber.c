/* $CORTO_GENERATED
 *
 * subscriber.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/core/core.h>

/* $header() */
extern corto_threadKey CORTO_KEY_FLOW;

static corto_ll corto_subscribers[CORTO_MAX_SCOPE_DEPTH];
static corto_uint32 corto_subscribers_count = 0;

static corto_int16 corto_subscriber_getObjectDepth(corto_id id) {
    corto_int16 result = 0;
    char *ptr = id;
    while ((ptr = strchr(ptr + 1, '/'))) {
        result ++;
    }
    return result;
}

static char* corto_subscriber_match(char *lockId, char *id) {
    char *lPtr = lockId, *idPtr = id;
    char lCh, idCh;

    while ((lCh = *lPtr) && (idCh = *idPtr) && (lCh == idCh)) {
        lPtr++;
        idPtr++;
    }

    if (*lPtr == '\0') {
        if (*idPtr == '/') {
            idPtr ++;
        }
        return idPtr;
    } else {
        return NULL;
    }
}

corto_int16 corto_notifySubscribersId(
    corto_eventMask mask,
    corto_string path,
    corto_string type,
    corto_string contentType,
    corto_word value)
{
    char *id = strrchr(path, '/');
    char *parent = NULL;
    if (id) {
        *id = '\0';
        id ++;
        parent = path;
    } else {
        id = path;
        parent = "/corto/lang";
    }
    corto_int16 depth = corto_subscriber_getObjectDepth(path);

    while (depth) {
        corto_ll subscribers = corto_subscribers[depth];
        if (subscribers) {
            corto_iter it = corto_llIter(subscribers);
            while (corto_iterHasNext(&it)) {
                corto_subscriber s = corto_iterNext(&it);
                if (!(s->mask & mask) == mask) {
                    continue;
                }
                if (!corto_subscriber_match(s->parent, parent)) {
                    continue;
                }
                if (!corto_match(s->expr, id)) {
                    continue;
                }

                corto_result r = {
                  id,
                  NULL,
                  parent,
                  type,
                  value,
                  FALSE
                };

                if (corto_function(s)->kind == CORTO_PROCEDURE_CDECL) {
                    ((void(*)(corto_object, corto_eventMask, corto_result*, corto_subscriber))
                      corto_function(s)->fptr)(s->instance, mask, &r, s);
                } else {
                    corto_result *rArg = &r;
                    void *args[4];
                    args[0] = &s->instance;
                    args[1] = &mask;
                    args[2] = &rArg;
                    args[3] = &s;
                    corto_callb(corto_function(s), NULL, args);
                }
            }
        }
        depth --;
    }

    return 0;
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
    return corto_subscriberCreate(
      r->mask,
      r->scope,
      r->expr,
      r->callback,
      r->instance
    );
}

static corto_subscribeSelector corto_subscribeSelectorGet(void);

static corto_subscribeSelector corto_subscribeContentType(
    corto_string contentType)
{
    corto_subscribeRequest *request = corto_threadTlsGet(CORTO_KEY_FLOW);
    if (request) {
        request->contentType = contentType;
    }
    return corto_subscribeSelectorGet();
}

static corto_subscribeSelector corto_subscribeMask(corto_eventMask mask)
{
    corto_subscribeRequest *request = corto_threadTlsGet(CORTO_KEY_FLOW);
    if (request) {
        request->mask = mask;
    }
    return corto_subscribeSelectorGet();;
}

static corto_subscriber corto_subscribeCallback(
    void (*callback)(corto_object, corto_eventMask, corto_result*, corto_subscriber))
{
    corto_subscriber result = NULL;

    corto_subscribeRequest *request = corto_threadTlsGet(CORTO_KEY_FLOW);
    if (request) {
        request->callback = callback;
        result = corto_subscribeSubscribe(request);
    }

    return result;
}

static corto_subscribeSelector corto_subscribeSelectorGet(void)
{
    corto_subscribeSelector result;
    result.contentType = corto_subscribeContentType;
    result.mask = corto_subscribeMask;
    result.callback = corto_subscribeCallback;
    return result;
}

corto_subscribeSelector corto_subscribe(
    corto_string scope,
    corto_string expr)
{
    corto_subscribeRequest *request = corto_threadTlsGet(CORTO_KEY_FLOW);
    if (!request) {
        request = corto_calloc(sizeof(corto_subscribeRequest));
        corto_threadTlsSet(CORTO_KEY_FLOW, request);
    } else {
        memset(request, 0, sizeof(corto_subscribeRequest));
    }
    request->scope = scope;
    request->expr = expr;
    return corto_subscribeSelectorGet();
}

/* $end */

corto_int16 _corto_subscriber_construct(
    corto_subscriber this)
{
/* $begin(corto/core/subscriber/construct) */
    corto_int16 depth = corto_subscriber_getObjectDepth(this->parent);

    if (!corto_subscribers[depth]) {
        corto_subscribers[depth] = corto_llNew();
    }

    corto_llAppend(corto_subscribers[depth], this);
    corto_subscribers_count ++;

    return 0;
/* $end */
}

corto_void _corto_subscriber_destruct(
    corto_subscriber this)
{
/* $begin(corto/core/subscriber/destruct) */
    corto_int16 depth = corto_subscriber_getObjectDepth(this->parent);
    corto_assert(corto_subscribers[depth] != NULL, "deleting subscriber but no subscriber list");

    corto_llRemove(corto_subscribers[depth], this);
    if (!corto_subscribers[depth]) {
        corto_llFree(corto_subscribers[depth]);
        corto_subscribers[depth] = NULL;
    }

    corto_subscribers_count --;

/* $end */
}

corto_int16 _corto_subscriber_init(
    corto_subscriber this)
{
/* $begin(corto/core/subscriber/init) */
    corto_parameter *p;
    corto_function(this)->parameters.buffer = corto_calloc(sizeof(corto_parameter) * 4);
    corto_function(this)->parameters.length = 4;

    /* Parameter observable */
    p = &corto_function(this)->parameters.buffer[0];
    p->name = corto_strdup("instance");
    p->passByReference = TRUE;
    corto_setref(&p->type, corto_type(corto_object_o));

    /* Parameter observable */
    p = &corto_function(this)->parameters.buffer[1];
    p->name = corto_strdup("event");
    p->passByReference = TRUE;
    corto_setref(&p->type, corto_type(corto_eventMask_o));

    /* Parameter observable */
    p = &corto_function(this)->parameters.buffer[2];
    p->name = corto_strdup("object");
    p->passByReference = TRUE;
    corto_setref(&p->type, corto_type(corto_result_o));

    /* Parameter observable */
    p = &corto_function(this)->parameters.buffer[3];
    p->name = corto_strdup("subscriber");
    p->passByReference = TRUE;
    corto_setref(&p->type, corto_type(corto_subscriber_o));

    return corto_function_init(this);
/* $end */
}
