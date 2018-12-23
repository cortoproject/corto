/* This is a managed file. Do not delete this comment. */

#include <corto>


corto_int16 corto_type_bindMetaprocedure(
    corto_type this,
    corto_metaprocedure procedure);

int16_t corto_metaprocedure_construct(
    corto_metaprocedure this)
{
    corto_object parent;

    parent = corto_parentof(this);
    if (corto_instanceof(corto_type(corto_type_o), parent)) {
        if (corto_type_bindMetaprocedure(corto_type(parent), this)) {
            goto error;
        }
    } else {
        ut_throw("invalid declaration of '%s' in non-type scope '%s'",
            corto_fullpath(NULL, this), corto_fullpath(NULL, parent));
        goto error;
    }

    return corto_function_construct(corto_function(this));
error:
    return -1;
}

