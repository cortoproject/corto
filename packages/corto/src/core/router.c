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
    corto_setref(&corto_type(this)->options.defaultProcedureType, corto_method_o);
    return corto_class_construct(this);
/* $end */
}

corto_int16 _corto_router_init(
    corto_router this)
{
/* $begin(corto/core/router/init) */
    corto_setstr(&this->elementSeparator, "/");
    return corto_class_init(this);
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
    if (routerBase->elementSeparator) {
        strcpy(requestBuffer, request[0] == '/' ? request + 1 : request);
        if ((elementCount = corto_pathToArray(requestBuffer, requestElements, "/")) == -1) {
            corto_seterr("%s: invalid request: %s", request, corto_lasterr());
            goto error;
        }
    } else {
        requestElements[0] = request;
        elementCount = 1;
    }

    /* Walk routes */
    corto_int32 i;
    for (i = 0; i < corto_interface(instanceType)->methods.length; i++) {
        corto_object o = corto_interface(instanceType)->methods.buffer[i];
        if (corto_instanceof(corto_route_o, o)) {
            corto_stringseq pattern = {.length = elementCount, .buffer = requestElements};
            corto_int32 matched = corto_routerimpl_matchRoute(
                router, corto_route(o), pattern, param);
            if (matched > maxMatched) {
                match = corto_route(o);

                /* If request is not split up in multiple elements, there will
                 * be only one matching route. */
                if (!routerBase->elementSeparator) {
                    break;
                }
            }
        }
    }

    if (!match) {
        corto_seterr("%s: resource unknown", request);
        goto error;
    }


    corto_type returnType = corto_function(match)->returnType;
    if (returnType && 
        ((returnType->kind != CORTO_VOID) ||
         returnType->reference) &&
        !result.value)
    {
        corto_seterr("no result provided for route '%s' (expected value of type '%s')",
            corto_fullpath(NULL, match),
            returnType ? corto_fullpath(NULL, returnType) : "void");
        goto error;
    }

    /* Parse router arguments */
    corto_int32 arg = 1;
    void **args = alloca((1 + router->maxArgs) * sizeof(void*));
    args[0] = &instance;
    if (routerBase->paramType) {
        args[1] = &param.value;
        arg = 2;
    }

    if (routerBase->elementSeparator) {
        for (i = 0; i < elementCount; i++) {
            char *pattern = match->elements.buffer[i];
            if (pattern[0] == '$') {
                args[arg] = &requestElements[i];
                arg++;
            }
        }
    }

    /* Call route */
    corto_callb(corto_function(match), result.value, args);

    return 0;
error:
    return -1;
/* $end */
}
