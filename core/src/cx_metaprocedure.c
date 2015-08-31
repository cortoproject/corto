/* cx_metaprocedure.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "cx.h"

/* $header() */
cx_int16 cx_type_bindMetaprocedure(cx_type _this, cx_metaprocedure procedure);
/* $end */

/* ::corto::lang::metaprocedure::bind() */
cx_int16 _cx_metaprocedure_bind(cx_metaprocedure _this) {
/* $begin(::corto::lang::metaprocedure::bind) */
    cx_object parent;

    parent = cx_parentof(_this);
    if (cx_instanceof(cx_type(cx_type_o), parent)) {
        if (cx_type_bindMetaprocedure(cx_type(parent), _this)) {
            goto error;
        }
    } else {
        cx_id id, id2;
        cx_error("metaoperation '%s' not defined in scope of '%s' which is not a type", cx_fullname(_this, id), cx_fullname(parent, id2));
        goto error;
    }

    return cx_function_bind(cx_function(_this));
error:
    return -1;
/* $end */
}
