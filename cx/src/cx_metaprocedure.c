/* cx_metaprocedure.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "cx.h"
#include "cx__meta.h"

/* $header() */
cx_int16 cx_type_bindMetaprocedure(cx_type _this, cx_metaprocedure procedure);
/* $end */

/* callback ::cortex::lang::procedure::bind(lang::object object) -> ::cortex::lang::metaprocedure::bind(lang::metaprocedure object) */
cx_int16 cx_metaprocedure_bind(cx_metaprocedure object) {
/* $begin(::cortex::lang::metaprocedure::bind) */
    cx_object parent;

    parent = cx_parentof(object);
    if (cx_instanceof(cx_typedef(cx_type_o), parent)) {
        if (cx_type_bindMetaprocedure(cx_type(parent), object)) {
            goto error;
        }
    } else {
        cx_id id, id2;
        cx_error("metaoperation '%s' not defined in scope of '%s' which is not a type", cx_fullname(object, id), cx_fullname(parent, id2));
        goto error;
    }

    return cx_function_bind(cx_function(object));
error:
    return -1;
/* $end */
}
