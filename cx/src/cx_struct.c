/* cx_struct.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "cx.h"

/* $header() */
#include "cx__interface.h"
#include "cx__class.h"
/* $end */

/* ::cortex::lang::struct::castable(type type) */
cx_bool cx_struct_castable_v(cx_struct _this, cx_type type) {
/* $begin(::cortex::lang::struct::castable) */
    return cx_struct_compatible(_this, type);
/* $end */
}

/* ::cortex::lang::struct::compatible(type type) */
cx_bool cx_struct_compatible_v(cx_struct _this, cx_type type) {
/* $begin(::cortex::lang::struct::compatible) */
    cx_bool result;

    cx_assert(cx_class_instanceof(cx_struct_o, _this), "struct::compatible called on non-struct object.");
    result = FALSE;

    /* Call overloaded type::compatible function first to check for generic compatibility. */
    if (!cx_type_compatible_v(cx_type(_this), type)) {
        /* Type must be at least struct for it to be compatible. */
        if (cx_class_instanceof(cx_struct_o, type)) {
            cx_interface e;

            /* Check if '_this' is superclass of 'type' */
            e = cx_interface(type);
            do {
                e = cx_interface(e)->base;
            }while(e && (e != cx_interface(_this)));
            result = (e == (cx_interface)_this);
        }
    } else {
        result = TRUE;
    }

    return result;
/* $end */
}

/* ::cortex::lang::struct::construct() */
cx_int16 cx_struct_construct(cx_struct _this) {
/* $begin(::cortex::lang::struct::construct) */
    cx_struct base;
    cx_uint16 alignment;
    cx_uint32 size;

    size = 0;
    alignment = 0;

    /* Insert members */
    if (cx__interface_insertMembers(cx_interface(_this))) {
        goto error;
    }

    /* Calculate alignment of self */
    if (cx_interface(_this)->members.length) {
        alignment = cx__interface_calculateAlignment(cx_interface(_this));
        if (!alignment) {
            cx_id id;
            cx_error("error in definition of '%s'", cx_fullname(_this, id));
            goto error;            
        }
    }

    /* Check if struct inherits from another struct */
    base = (cx_struct)cx_interface(_this)->base;

    /* Get maximum alignment from self and base-class and copy template parameters */
    if (base) {
        if (!cx_instanceof(cx_type(cx_struct_o), base)) {
            cx_id id, id2;
            cx_error("struct '%s' inherits from non-struct type '%s'", cx_fullname(_this, id), cx_fullname(base, id2));
            goto error;
        }

        if (cx_type(base)->alignment) {
            if (alignment < cx_type(base)->alignment) {
                alignment = cx_type(base)->alignment;
            }
        }
    }

    /* Set alignment of self */
    cx_type(_this)->alignment = alignment;

    /* Get size of base-class */
    if (base) {
        size = cx_type(base)->size;

        if (cx_type(base)->hasResources) {
            cx_type(_this)->hasResources = TRUE;
        }
    }

    /* Calculate size of self */
    if (cx_interface(_this)->members.length) {
        size = cx__interface_calculateSize(cx_interface(_this), size);
        if (!size) {
            cx_id id;
            cx_error("error in definition of '%s'", cx_fullname(_this, id));
            goto error;
        }
    }

    /* Set size of self */
    cx_type(_this)->size = size;

    return cx_interface_construct(cx_interface(_this));
error:
    return -1;
/* $end */
}

/* ::cortex::lang::struct::init() */
cx_int16 cx_struct_init(cx_struct _this) {
/* $begin(::cortex::lang::struct::init) */
    /* If not bootstrapping, set baseAccess to GLOBAL | PUBLIC */
    if (cx_checkState(cx_type_o, CX_DEFINED)) {
        _this->baseAccess = CX_GLOBAL;
    }

    if (cx_interface_init(cx_interface(_this))) {
        goto error;
    }

    cx_interface(_this)->kind = CX_STRUCT;
    cx_type(_this)->reference = FALSE;

    return 0;
error:
    return -1;
/* $end */
}

/* ::cortex::lang::struct::resolveMember(string name) */
cx_member cx_struct_resolveMember_v(cx_struct _this, cx_string name) {
/* $begin(::cortex::lang::struct::resolveMember) */
    cx_interface base;
    cx_member m;

    m = NULL;
    base = cx_interface(_this);
    do {
        m = cx_interface_resolveMember_v(cx_interface(base), name);
    }while(!m && (base=cx_interface(base)->base));

    return m;
/* $end */
}
