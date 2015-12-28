/* $CORTO_GENERATED
 *
 * member.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "corto/lang/lang.h"

/* $header() */
#include "_interface.h"
/* $end */

corto_int16 _corto_member_construct(corto_member this) {
/* $begin(corto/lang/member/construct) */
    if (!this->type) {
        corto_seterr("member '%s' has no type", corto_fullpath(NULL, this));
        goto error;
    }

    return 0;
error:
    return -1;
/* $end */
}

corto_int16 _corto_member_init(corto_member this) {
/* $begin(corto/lang/member/init) */
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
            corto_seterr(
              "invalid declaration of member '%s' in non-composite scope '%s'",
              corto_nameof(this), corto_fullpath(NULL, parent));
            goto error;
        }
    }
    return 0;
error:
    return -1;
/* $end */
}
