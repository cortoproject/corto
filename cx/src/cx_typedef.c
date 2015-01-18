/* cx_typedef.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "cx.h"
#include "cx__meta.h"

/* ::cortex::lang::typedef::construct() */
cx_int16 cx_typedef_construct(cx_typedef _this) {
/* $begin(::cortex::lang::typedef::construct) */
    cx_typedef real;

    real = cx_typedef(_this)->type;
    if (!real) {
        cx_id id;
        cx_error("typedef::construct: typedef '%s' points to nothing", cx_fullname(_this, id));
        goto error;
    }

    while(real && (real != real->type)) {
        if (!cx_checkState(real, CX_VALID)) {
            cx_id id, id2;
            cx_error("typedef::construct: typedef '%s' points to object '%s' which is not valid", cx_fullname(_this, id), cx_fullname(real, id2));
            goto error;
        }
        if (!cx_checkState(real, CX_DEFINED)) {
            cx_id id, id2;
            cx_error("typedef::construct: typedef '%s' points to object '%s' which is not defined", cx_fullname(_this, id), cx_fullname(real, id2));
            goto error;
        }
        real = real->type;
    }

    cx_assert(real != NULL, "typedef '%s' points to nothing", cx_nameof(_this));

    cx_set_ext(_this, &cx_typedef(_this)->real, real, "Set real-member");

    return 0;
error:
    return -1;
/* $end */
}

/* ::cortex::lang::typedef::destruct() */
cx_void cx_typedef_destruct(cx_typedef _this) {
/* $begin(::cortex::lang::typedef::destruct) */
    cx_free_ext(_this, _this->real, "Free real member");
    _this->real = NULL;
/* $end */
}

/* ::cortex::lang::typedef::init() */
cx_int16 cx_typedef_init(cx_typedef _this) {
/* $begin(::cortex::lang::typedef::init) */
    CX_UNUSED(_this);

    if (_this->type) {
        cx_typedef_construct(_this);
        if (cx_checkAttr(_this, CX_ATTR_SCOPED) && (cx_parentof(_this) == cortex_lang_o)) {
            cx_keep_ext(_this, _this->real, "Keep self for real member");
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
