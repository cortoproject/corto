/* cx_member.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "cx.h"

/* $header() */
#include "cx__interface.h"
/* $end */

/* ::corto::lang::member::construct() */
cx_int16 _cx_member_construct(cx_member _this) {
/* $begin(::corto::lang::member::construct) */
    if (!_this->type) {
        cx_id id;
        cx_error("member '%s' has no type.", cx_fullname(_this, id));
        goto error;
    }

    return 0;
error:
    return -1;
/* $end */
}

/* ::corto::lang::member::init() */
cx_int16 _cx_member_init(cx_member _this) {
/* $begin(::corto::lang::member::init) */
    cx_object parent;
    cx_type parentType;

    if (cx_checkAttr(_this, CX_ATTR_SCOPED)) {
        parent = cx_parentof(_this);
        parentType = cx_typeof(parent);

        if (parentType->kind == CX_COMPOSITE) {
            /* Bind member with composite object */
            if (cx__interface_bindMember(parent, _this)) {
                goto error;
            }

            /* Set default member-modifiers - not during bootstrap */
            if (cx_checkState(cx_type_o, CX_DEFINED)) {
                _this->modifiers = CX_GLOBAL;
                _this->state = CX_DECLARED | CX_DEFINED;
            }
        } else {
            cx_id id;
            cx_error("invalid declaration of member '%s' in scope '%s', members can only be declared in scopes of composite _thiss.",
                    cx_nameof(_this), cx_fullname(parent, id));
            goto error;
        }
    }
    return 0;
error:
    return -1;
/* $end */
}
