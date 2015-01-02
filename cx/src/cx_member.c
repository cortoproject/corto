/* cx_member.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "cx.h"
#include "cx__meta.h"

/* $header() */
#include "cx__interface.h"
/* $end */

/* callback ::cortex::lang::class::construct(lang::object object) -> ::cortex::lang::member::construct(lang::member object) */
cx_int16 cx_member_construct(cx_member object) {
/* $begin(::cortex::lang::member::construct) */
    if (!object->type) {
        cx_id id;
        cx_error("member '%s' has no type.", cx_fullname(object, id));
        goto error;
    }

    return 0;
error:
    return -1;
/* $end */
}

/* callback ::cortex::lang::type::init(lang::object object) -> ::cortex::lang::member::init(lang::member object) */
cx_int16 cx_member_init(cx_member object) {
/* $begin(::cortex::lang::member::init) */
    cx_object parent;
    cx_type parentType;

    if (cx_checkAttr(object, CX_ATTR_SCOPED)) {
        parent = cx_parentof(object);
        parentType = cx_typeof(parent)->real;

        if (parentType->kind == CX_COMPOSITE) {
            /* Bind member with composite object */
            if (cx__interface_bindMember(parent, object)) {
                goto error;
            }
            /* Set default member-modifiers - not during bootstrap */
            if (cx_checkState(cx_type_o, CX_DEFINED)) {
                object->modifiers = CX_GLOBAL;
                object->state = CX_DECLARED | CX_DEFINED;
            }
        } else {
            cx_id id;
            cx_error("invalid declaration of member '%s' in scope '%s', members can only be declared in scopes of composite objects.",
                    cx_nameof(object), cx_fullname(parent, id));
            goto error;
        }
    }
    return 0;
error:
    return -1;
/* $end */
}
