/* This is a managed file. Do not delete this comment. */

#include <corto>


static corto_routerimpl corto_route_find_routerImpl(corto_route this) {
    corto_interface base = corto_interface(corto_parentof(this));
    do {
        if (corto_instanceof(corto_routerimpl_o, base)) {
            break;
        }
    } while ((base = base->base));
    return corto_routerimpl(base);
}

int16_t corto_route_construct(
    corto_route this)
{
    corto_id pattern;
    char *ptr = pattern;
    corto_int32 count = 0, elementCount = 0;
    corto_routerimpl router = corto_route_find_routerImpl(this);
    corto_router routerBase = corto_router(corto_typeof(router));
    const char *elements[CORTO_MAX_SCOPE_DEPTH];
    corto_int32 i;
    corto_parameterseq *params = &corto_function(this)->parameters;

    if (this->pattern) {
        strcpy(pattern, this->pattern);
        if (*ptr == '/') {
            ptr ++;
        }

        if (routerBase->element_separator) {
            if ((elementCount = ut_pathToArray(ptr, elements, routerBase->element_separator)) == -1) {
                ut_throw("invalid pattern '%s'", this->pattern);
                goto error;
            }

            this->elements.buffer = corto_alloc(elementCount * sizeof(corto_string));
            this->elements.length = elementCount;
            for (i = 0; i < elementCount; i ++) {
                this->elements.buffer[i] = ut_strdup(elements[i]);
            }
        }
    }

    if (routerBase->param_type) {
        params->buffer = corto_realloc(
          params->buffer, sizeof(corto_parameter) * (count + 1)
        );
        corto_parameter *p = &params->buffer[count];
        memset(p, 0, sizeof(corto_parameter));
        corto_set_ref(&p->type, routerBase->param_type);
        if (routerBase->param_name) {
            corto_set_str(&p->name, routerBase->param_name);
        } else if (corto_check_attr(routerBase->param_type, CORTO_ATTR_NAMED)) {
            corto_set_str(&p->name, corto_idof(routerBase->param_type));
            p->name[0] = tolower(p->name[0]);
        } else {
            corto_set_str(&p->name, "_param");
        }
        count ++;
    }

    if (routerBase->router_data_type) {
        params->buffer = corto_realloc(
          params->buffer, sizeof(corto_parameter) * (count + 1)
        );
        corto_parameter *p = &params->buffer[count];
        memset(p, 0, sizeof(corto_parameter));
        corto_set_ref(&p->type, routerBase->router_data_type);
        if (routerBase->router_data_name) {
            corto_set_str(&p->name, routerBase->router_data_name);
        } else if (corto_check_attr(routerBase->param_type, CORTO_ATTR_NAMED)) {
            corto_set_str(&p->name, corto_idof(routerBase->router_data_type));
            p->name[0] = tolower(p->name[0]);
        } else {
            corto_set_str(&p->name, "_routerData");
        }
        count ++;
    }

    if (!strcmp(corto_idof(this), "_matched")) {
        corto_set_ref(&router->matched, this);
    }

    for (i = 0; i < this->elements.length; i++) {
        corto_string element = this->elements.buffer[i];
        if (element[0] == '$') {
            corto_function(this)->parameters.buffer = corto_realloc(
              corto_function(this)->parameters.buffer,
              (count + 1) * sizeof(corto_parameter)
            );
            corto_parameter *p = &corto_function(this)->parameters.buffer[count];
            memset(p, 0, sizeof(corto_parameter));
            corto_set_ref(&p->type, corto_string_o);
            corto_set_str(&p->name, &element[1]);
            count ++;
        }
    }

    corto_set_ref(&corto_function(this)->return_type, routerBase->return_type);
    corto_function(this)->parameters.length = count;

    return safe_corto_function_construct(this);
error:
    return -1;
}

int16_t corto_route_init(
    corto_route this)
{
    if (!corto_route_find_routerImpl(this)) {
        ut_throw("parent of '%s' is not an instance of 'routerimpl'",
            corto_fullpath(NULL, this));
        goto error;
    }

    return safe_corto_function_init(this);
error:
    return -1;
}
