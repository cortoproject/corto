/* This is a managed file. Do not delete this comment. */

#include <corto>


int corto_routerimpl_countArgs(corto_object o, void *userData) {
    if (corto_instanceof(corto_route_o, o)) {
        if (corto_routerimpl(userData)->maxArgs < corto_function(o)->parameters.length) {
            corto_routerimpl(userData)->maxArgs = corto_function(o)->parameters.length;
        }
    }
    return 1;
}

int16_t corto_routerimpl_construct(
    corto_routerimpl this)
{
    corto_scope_walk(this, corto_routerimpl_countArgs, this);
    return safe_corto_class_construct(this);
}

void corto_routerimpl_destruct(
    corto_routerimpl this)
{

    CORTO_UNUSED(this);

}

corto_route corto_routerimpl_find_route_v(
    corto_routerimpl this,
    corto_object instance,
    corto_stringseq pattern,
    corto_any param,
    corto_any *routerData)
{
    corto_route result = NULL;
    corto_router routerBase = corto_router(corto_typeof(this));
    corto_interface interfaceType = corto_interface(corto_typeof(instance));
    corto_int32 maxMatched = -1;

    CORTO_UNUSED(instance);

    /* Walk routes */
    corto_int32 i;
    for (i = 0; i < interfaceType->methods.length; i++) {
        corto_object o = interfaceType->methods.buffer[i];
        if (corto_instanceof(corto_route_o, o)) {
            corto_int32 matched = corto_routerimpl_match_route(
                this, corto_route(o), pattern, param, routerData);
            if (matched > maxMatched) {
                result = corto_route(o);

                /* If request is not split up in multiple elements, there will
                 * be only one matching route. */
                if (!routerBase->element_separator) {
                    break;
                }
            }
        }
    }

    return result;

}

int32_t corto_routerimpl_match_route_v(
    corto_routerimpl this,
    corto_route route,
    corto_stringseq pattern,
    corto_any param,
    corto_any *routerData)
{
    corto_int32 result = -1;

    CORTO_UNUSED(this);
    CORTO_UNUSED(param);
    CORTO_UNUSED(routerData);

    if (route->elements.length == pattern.length) {
        result = 0;
        corto_int32 i;
        for (i = 0; i < pattern.length; i++) {
            char *expr = route->elements.buffer[i];
            if (expr[0] != '$') {
                if (strcmp(expr, pattern.buffer[i])) {
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

