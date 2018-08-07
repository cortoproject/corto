/* This is a managed file. Do not delete this comment. */

#include <corto/corto.h>
static corto_routerimpl corto_router_find_routerImpl(corto_route this) {
    corto_interface base = corto_interface(this);
    do {
        if (corto_instanceof(corto_routerimpl_o, base)) {
            break;
        }

    } while ((base = base->base));
    return corto_routerimpl(base);
}

int16_t corto_router_construct(
    corto_router this)
{
    if (!corto_interface(this)->base) {
        corto_set_ref(&corto_interface(this)->base, corto_interface(corto_routerimpl_o));
    } else {
        if (!corto_type_instanceof(corto_routerimpl_o, corto_interface(this)->base)) {
            corto_throw("router must inherit from 'routerimpl'");
            goto error;
        }

    }

    corto_set_ref(&corto_type(this)->scope_procedure_type, corto_method_o);
    return safe_corto_class_construct(this);
error:
    return -1;
}

int16_t corto_router_init(
    corto_router this)
{
    corto_set_str(&this->element_separator, "/");
    return safe_corto_class_init(this);
}

int16_t corto_router_match(
    corto_object instance,
    const char *request,
    corto_any param,
    corto_any result,
    corto_route *matched)
{
    corto_object instanceType = corto_typeof(instance);
    corto_routerimpl router = corto_router_find_routerImpl(instanceType);
    corto_router routerBase = corto_router(corto_typeof(router));
    corto_route match = NULL;
    corto_id requestBuffer;
    const char *requestElements[CORTO_MAX_SCOPE_DEPTH];
    corto_int32 elementCount;
    corto_any routerData = {.owner = TRUE};
    corto_int32 i;
    if (matched) {
        *matched = NULL;
    }

    /* Parse request once */
    if (routerBase->element_separator) {
        strcpy(requestBuffer, request[0] == '/' ? request + 1 : request);
        if ((elementCount = corto_pathToArray(requestBuffer, requestElements, "/")) == -1) {
            corto_throw("invalid request '%s'", request);
            goto error;
        }

    } else {
        requestElements[0] = request;
        elementCount = 1;
    }

    corto_stringseq pattern = {elementCount, (char**)requestElements};
    if (!(match = corto_routerimpl_find_route(router, instance, pattern, param, &routerData))) {
        corto_throw("router: resource '%s' unknown", request);
        goto error;
    }

    corto_type return_type = corto_function(match)->return_type;
    if (return_type &&
        ((return_type->kind != CORTO_VOID) ||
         return_type->reference) &&
        !result.value)
    {
        corto_throw("no result provided for route '%s' (expected value of type '%s')",
            corto_fullpath(NULL, match),
            return_type ? corto_fullpath(NULL, return_type) : "void");
        goto error;
    }

    /* Parse router arguments */
    corto_int32 arg = 1;
    void **args = alloca((1 + router->maxArgs) * sizeof(void*));
    args[0] = &instance;
    /* Add data passed from application */
    if (routerBase->param_type) {
        args[arg] = &param.value;
        arg ++;
    }

    /* Add data passed from router */
    if (routerBase->router_data_type) {
        args[arg] = &routerData.value;
        arg ++;
    }

    /* Add data from elements */
    if (routerBase->element_separator) {
        for (i = 0; i < elementCount; i++) {
            char *pattern = match->elements.buffer[i];
            if (pattern[0] == '$') {
                args[arg] = &requestElements[i];
                arg++;
            }

        }

    }

    /* Call route */
    corto_invokeb(corto_function(match), result.value, args);
    if (router->matched) {
        corto_invokeb(corto_function(router->matched), result.value, args);
    }

    if (matched) {
        *matched = match;
    }

    if (routerBase->router_data_type) {
        corto_ptr_deinit(&routerData, corto_any_o);
    }

    return 0;
error:
    return -1;
}
