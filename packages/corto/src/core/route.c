/* $CORTO_GENERATED
 *
 * route.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/core/core.h>

corto_int16 _corto_route_construct(
    corto_route this)
{
/* $begin(corto/core/route/construct) */
    corto_id pattern;
    strcpy(pattern, this->pattern);
    char *ptr = pattern;
    corto_int32 count = 0, elementCount = 0;
    corto_router router = corto_parentof(this);
    char *elements[CORTO_MAX_SCOPE_DEPTH];

    if (*ptr == '/') {
        ptr ++;
    }

    if ((elementCount = corto_pathToArray(ptr, elements, "/")) == -1) {
        corto_seterr("invalid pattern '%s': %s", this->pattern, corto_lasterr());
        goto error;
    }

    corto_stringseqAssign(&this->elements, elementCount, elements);

    if (router->paramType) {
        corto_function(this)->parameters.buffer = corto_realloc(
          corto_function(this)->parameters.buffer, sizeof(corto_parameter)
        );
        corto_parameter *p = &corto_function(this)->parameters.buffer[0];
        memset(p, 0, sizeof(corto_parameter));
        corto_setref(&p->type, router->paramType);
        corto_setstr(&p->name, "param");
        count = 1;
    }

    corto_stringseqForeach(this->elements, element) {
        if (element[0] == '$') {
            corto_function(this)->parameters.buffer = corto_realloc(
              corto_function(this)->parameters.buffer,
              (count + 1) * sizeof(corto_parameter)
            );
            corto_parameter *p = &corto_function(this)->parameters.buffer[count];
            memset(p, 0, sizeof(corto_parameter));
            corto_setref(&p->type, corto_string_o);
            corto_setstr(&p->name, &element[1]);
            count ++;
        }
    }

    corto_function(this)->parameters.length = count;

    return corto_method_construct(this);
error:
    return -1;
/* $end */
}

corto_int16 _corto_route_init(
    corto_route this)
{
/* $begin(corto/core/route/init) */
    if (!corto_instanceof(corto_router_o, corto_parentof(this))) {
        corto_seterr("parent of route should inherit from router");
        goto error;
    }
    corto_router r = corto_parentof(this);
    corto_setref(&corto_function(this)->returnType, r->returnType);

    return corto_method_init(this);
error:
    return -1;
/* $end */
}
