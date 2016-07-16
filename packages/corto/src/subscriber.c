#include <corto/corto.h>

extern corto_threadKey CORTO_KEY_FLOW;

static corto_subscriber corto_subscribeSubscribe(corto_subscribeRequest *r)
{
    return 0;
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
    void (*callback)(corto_subscriber, corto_eventMask mask, corto_result*))
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
