/* cx_typedef.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "cx.h"
#include "cx__meta.h"

/* callback ::cortex::lang::class::construct(lang::object object) -> ::cortex::lang::typedef::construct(lang::typedef object) */
cx_int16 cx_typedef_construct(cx_typedef object) {
/* $begin(::cortex::lang::typedef::construct) */
    cx_typedef real;

    real = cx_typedef(object)->type;
    if (!real) {
        cx_id id;
        cx_error("typedef::construct: typedef '%s' points to nothing", cx_fullname(object, id));
        goto error;
    }

    while(real != real->type) {
        if (!cx_checkState(real, CX_VALID)) {
            cx_id id, id2;
            cx_error("typedef::construct: typedef '%s' points to object '%s' which is not valid", cx_fullname(object, id), cx_fullname(real, id2));
            goto error;
        }
        if (!cx_checkState(real, CX_DEFINED)) {
            cx_id id, id2;
            cx_error("typedef::construct: typedef '%s' points to object '%s' which is not defined", cx_fullname(object, id), cx_fullname(real, id2));
            goto error;
        }
        if (!real->type) {

        }
        real = real->type;
    }

    cx_assert(real != NULL, "typedef '%s' points to nothing", cx_nameof(object));

    cx_set_ext(object, &cx_typedef(object)->real, real, "Set real-member");

	return 0;
error:
    return -1;
/* $end */
}

/* callback ::cortex::lang::class::destruct(lang::object object) -> ::cortex::lang::typedef::destruct(lang::typedef object) */
cx_void cx_typedef_destruct(cx_typedef object) {
/* $begin(::cortex::lang::typedef::destruct) */
	cx_free_ext(object, object->real, "Free real member");
	object->real = NULL;
/* $end */
}

/* callback ::cortex::lang::type::init(lang::object object) -> ::cortex::lang::typedef::init(lang::typedef object) */
cx_int16 cx_typedef_init(cx_typedef object) {
/* $begin(::cortex::lang::typedef::init) */
    CX_UNUSED(object);

    if (object->type) {
        cx_typedef_construct(object);
        if (cx_checkAttr(object, CX_ATTR_SCOPED) && (cx_parentof(object) == cortex_lang_o)) {
            cx_keep_ext(object, object->real, "Keep self for real member");
        }

    }

    return 0;
/* $end */
}

/* ::cortex::lang::typedef::realType() */
cx_type cx_typedef_realType(cx_typedef _this) {
/* $begin(::cortex::lang::typedef::realType) */
	return _this->real;
/* $end */
}
