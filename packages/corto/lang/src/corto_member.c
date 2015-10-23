/* corto_member.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "cx.h"

/* $header() */
#include "corto__interface.h"
/* $end */

/* ::corto::lang::member::construct() */
corto_int16 _corto_member_construct(corto_member this) {
/* $begin(::corto::lang::member::construct) */
    if (!this->type) {
        corto_id id;
        corto_seterr("member '%s' has no type", corto_fullname(this, id));
        goto error;
    }

    return 0;
error:
    return -1;
/* $end */
}

/* ::corto::lang::member::init() */
corto_int16 _corto_member_init(corto_member this) {
/* $begin(::corto::lang::member::init) */
    corto_object parent;
    corto_type parentType;

    if (corto_checkAttr(this, CORTO_ATTR_SCOPED)) {
        parent = corto_parentof(this);
        parentType = corto_typeof(parent);

        if (parentType->kind == CORTO_COMPOSITE) {
            /* Bind member with composite object */
            if (corto__interface_bindMember(parent, this)) {
                goto error;
            }

            /* Set default member-modifiers - not during bootstrap */
            if (corto_checkState(corto_type_o, CORTO_DEFINED)) {
                this->modifiers = CORTO_GLOBAL;
                this->state = CORTO_DECLARED | CORTO_DEFINED;
            }
        } else {
            corto_id id;
            corto_seterr("invalid declaration of member '%s' in scope '%s', members can only be declared in scopes of composite types.",
                    corto_nameof(this), corto_fullname(parent, id));
            goto error;
        }
    }
    return 0;
error:
    return -1;
/* $end */
}
