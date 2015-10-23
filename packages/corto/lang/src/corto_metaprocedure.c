/* corto_metaprocedure.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "cx.h"

/* $header() */
corto_int16 corto_type_bindMetaprocedure(corto_type this, corto_metaprocedure procedure);
/* $end */

/* ::corto::lang::metaprocedure::bind() */
corto_int16 _corto_metaprocedure_bind(corto_metaprocedure this) {
/* $begin(::corto::lang::metaprocedure::bind) */
    corto_object parent;

    parent = corto_parentof(this);
    if (corto_instanceof(corto_type(corto_type_o), parent)) {
        if (corto_type_bindMetaprocedure(corto_type(parent), this)) {
            goto error;
        }
    } else {
        corto_id id, id2;
        corto_error("metaoperation '%s' not defined in scope of '%s' which is not a type", corto_fullname(this, id), corto_fullname(parent, id2));
        goto error;
    }

    return corto_function_bind(corto_function(this));
error:
    return -1;
/* $end */
}
