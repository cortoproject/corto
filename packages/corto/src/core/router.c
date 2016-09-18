/* $CORTO_GENERATED
 *
 * router.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/core/core.h>

/* $header(corto/core/router/construct) */
int corto_router_countArgs(corto_object o, void *userData) {
    if (corto_instanceof(corto_route_o, o)) {
        if (corto_router(userData)->maxArgs < corto_function(o)->parameters.length) {
            corto_router(userData)->maxArgs = corto_function(o)->parameters.length;
        }
    }
    return 1;
}
/* $end */
corto_int16 _corto_router_construct(
    corto_router this)
{
/* $begin(corto/core/router/construct) */
    corto_scopeWalk(this, corto_router_countArgs, this);
    return corto_class_construct(this);
/* $end */
}

corto_void _corto_router_destruct(
    corto_router this)
{
/* $begin(corto/core/router/destruct) */
    CORTO_UNUSED(this);
/* $end */
}

/* $header(corto/core/router/match) */
corto_int32 corto_router_matchRoute(
    corto_route r,
    char* elements[],
    corto_int32 elementCount)
{
    corto_int32 result = -1;

    if (r->elements.length == elementCount) {
        result = 0;
        corto_int32 i;
        for (i = 0; i < elementCount; i++) {
            char *pattern = r->elements.buffer[i];
            if (pattern[0] != '$') {
                if (strcmp(pattern, elements[i])) {
                    goto nomatch;
                } else {
                    result ++;
                }
            }
        }
    }

    return result;
nomatch:
    return -1;
}
/* $end */
corto_int16 _corto_router_match(
    corto_object instance,
    corto_string request,
    corto_any result)
{
/* $begin(corto/core/router/match) */
    corto_router router = corto_router(corto_typeof(instance));
    corto_route match = NULL;
    corto_int32 maxMatched = -1;
    corto_id requestBuffer;
    char *requestElements[CORTO_MAX_SCOPE_DEPTH];
    corto_int32 elementCount;

    /* Parse request once */
    strcpy(requestBuffer, request);
    if ((elementCount = corto_pathToArray(requestBuffer, requestElements, "/")) == -1) {
        corto_seterr("%s: invalid request: %s", request, corto_lasterr());
        goto error;
    }

    /* Walk routes */
    corto_vtableForeach(corto_interface(router)->methods, o) {
        if (corto_instanceof(corto_route_o, o)) {
            corto_int32 matched = corto_router_matchRoute(
                corto_route(o), requestElements, elementCount);
            if (matched > maxMatched) {
                match = corto_route(o);
            }
        }
    }

    if (!match) {
        corto_seterr("%s: resource unknown", request);
        goto error;
    }

    /* Parse router arguments */
    corto_int32 i, arg = 1;
    void **args = alloca((1 + router->maxArgs) * sizeof(void*));
    args[0] = instance;
    for (i = 0; i < elementCount; i++) {
        char *pattern = match->elements.buffer[i];
        if (pattern[0] == '$') {
            args[arg] = &requestElements[i];
            arg++;
        }
    }

    /* Call route */
    corto_callb(corto_function(match), result.value, args);

    return 0;
error:
    return -1;
/* $end */
}
