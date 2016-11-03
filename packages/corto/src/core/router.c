/* $CORTO_GENERATED
 *
 * router.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/core/core.h>

/* $header() */
static corto_routerimpl corto_router_findRouterImpl(corto_route this) {
    corto_interface base = corto_interface(this);
    do {
        if (corto_instanceof(corto_routerimpl_o, base)) {
            break;
        }
    } while ((base = base->base));
    return corto_routerimpl(base);
}
/* $end */

corto_int16 _corto_router_construct(
    corto_router this)
{
/* $begin(corto/core/router/construct) */
    corto_setref(&corto_interface(this)->base, corto_interface(corto_routerimpl_o));
    corto_setref(&corto_type(this)->defaultProcedureType, corto_method_o);
    return corto_class_construct(this);
/* $end */
}

corto_int16 _corto_router_match(
    corto_object instance,
    corto_string request,
    corto_any param,
    corto_any result)
{
/* $begin(corto/core/router/match) */
    corto_object instanceType = corto_typeof(instance);
    corto_routerimpl router = corto_router_findRouterImpl(instanceType);
    corto_router routerBase = corto_router(corto_typeof(router));
    corto_route match = NULL;
    corto_int32 maxMatched = -1;
    corto_id requestBuffer;
    char *requestElements[CORTO_MAX_SCOPE_DEPTH];
    corto_int32 elementCount;

    /* Parse request once */
    strcpy(requestBuffer, request[0] == '/' ? request + 1 : request);
    if ((elementCount = corto_pathToArray(requestBuffer, requestElements, "/")) == -1) {
        corto_seterr("%s: invalid request: %s", request, corto_lasterr());
        goto error;
    }

    /* Walk routes */
    corto_vtableForeach(corto_interface(instanceType)->methods, o) {
        if (corto_instanceof(corto_route_o, o)) {
            corto_stringseq pattern = {.length = elementCount, .buffer = requestElements};
            corto_int32 matched = corto_routerimpl_matchRoute(
                router, corto_route(o), pattern, param);
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
    args[0] = &instance;
    if (routerBase->paramType) {
        args[1] = &param.value;
        arg = 2;
    }
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
