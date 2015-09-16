/* cx_struct.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#define corto_lang_LIB
#include "cx.h"

/* $header() */
#include "cx__interface.h"
#include "cx__class.h"
/* $end */

/* ::corto::lang::struct::castable(type type) */
cx_bool _cx_struct_castable_v(cx_struct this, cx_type type) {
/* $begin(::corto::lang::struct::castable) */
    return cx_struct_compatible(this, type);
/* $end */
}

/* ::corto::lang::struct::compatible(type type) */
cx_bool _cx_struct_compatible_v(cx_struct this, cx_type type) {
/* $begin(::corto::lang::struct::compatible) */
    cx_bool result;

    cx_assert(cx_class_instanceof(cx_struct_o, this), "struct::compatible called on non-struct object.");
    result = FALSE;

    /* Call overloaded type::compatible function first to check for generic compatibility. */
    if (!cx_type_compatible_v(cx_type(this), type)) {
        /* Type must be at least struct for it to be compatible. */
        if (cx_class_instanceof(cx_struct_o, type)) {
            cx_interface e;

            /* Check if 'this' is superclass of 'type' */
            e = cx_interface(type);
            do {
                e = cx_interface(e)->base;
            }while(e && (e != cx_interface(this)));
            result = (e == (cx_interface)this);
        }
    } else {
        result = TRUE;
    }

    return result;
/* $end */
}

/* ::corto::lang::struct::construct() */
cx_int16 _cx_struct_construct(cx_struct this) {
/* $begin(::corto::lang::struct::construct) */
    cx_struct base;
    cx_uint16 alignment;
    cx_uint32 size;

    size = 0;
    alignment = 0;

    /* Don't allow empty structs */
    if (!cx_interface(this)->nextMemberId && !cx_interface(this)->base) {
        cx_member m = cx_declareChild(this, "__dummy", cx_member_o);
        cx_setref(&m->type, cx_int8_o);
        m->modifiers = CX_PRIVATE|CX_LOCAL;
        cx_define(m);
    }

    /* Insert members */
    if (cx__interface_insertMembers(cx_interface(this))) {
        goto error;
    }

    /* Calculate alignment of self */
    if (cx_interface(this)->members.length) {
        alignment = cx__interface_calculateAlignment(cx_interface(this));
        if (!alignment) {
            cx_id id;
            cx_error("error in definition of '%s'", cx_fullname(this, id));
            goto error;            
        }
    }

    /* Check if struct inherits from another struct */
    base = (cx_struct)cx_interface(this)->base;

    /* Get maximum alignment from self and base-class and copy template parameters */
    if (base) {
        if (!cx_instanceof(cx_type(cx_struct_o), base)) {
            cx_id id, id2;
            cx_error("struct '%s' inherits from non-struct type '%s'", cx_fullname(this, id), cx_fullname(base, id2));
            goto error;
        }

        if (cx_type(base)->alignment) {
            if (alignment < cx_type(base)->alignment) {
                alignment = cx_type(base)->alignment;
            }
        }
    }

    /* Set alignment of self */
    cx_type(this)->alignment = alignment;

    /* Get size of base-class */
    if (base) {
        size = cx_type(base)->size;

        if (cx_type(base)->hasResources) {
            cx_type(this)->hasResources = TRUE;
        }
    }

    /* Calculate size of self */
    if (cx_interface(this)->members.length) {
        size = cx__interface_calculateSize(cx_interface(this), size);
        if (!size) {
            cx_id id;
            cx_error("error in definition of '%s'", cx_fullname(this, id));
            goto error;
        }
    }

    /* Set size of self */
    cx_type(this)->size = size;

    return cx_interface_construct(this);
error:
    return -1;
/* $end */
}

/* ::corto::lang::struct::init() */
cx_int16 _cx_struct_init(cx_struct this) {
/* $begin(::corto::lang::struct::init) */
    /* If not bootstrapping, set baseAccess to GLOBAL | PUBLIC */
    if (cx_checkState(cx_type_o, CX_DEFINED)) {
        this->baseAccess = CX_GLOBAL;
    }

    if (cx_interface_init(this)) {
        goto error;
    }

    cx_interface(this)->kind = CX_STRUCT;
    cx_type(this)->reference = FALSE;

    return 0;
error:
    return -1;
/* $end */
}

/* ::corto::lang::struct::resolveMember(string name) */
cx_member _cx_struct_resolveMember_v(cx_struct this, cx_string name) {
/* $begin(::corto::lang::struct::resolveMember) */
    cx_interface base;
    cx_member m;

    m = NULL;
    base = cx_interface(this);
    do {
        m = cx_interface_resolveMember_v(cx_interface(base), name);
    }while(!m && (base=cx_interface(base)->base));

    return m;
/* $end */
}
