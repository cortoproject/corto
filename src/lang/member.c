/* This is a managed file. Do not delete this comment. */

#include <corto/corto.h>

#include "interface.h"

int16_t corto_member_construct(
    corto_member this)
{
    if (!this->type) {
        corto_throw("member '%s' has no type", corto_fullpath(NULL, this));
        goto error;
    }

    if (corto_instanceof(corto_native_type_o, this->type) &&
        !(this->modifiers & CORTO_LOCAL))
    {
        corto_throw("member '%s' of native type '%s' is not local",
            corto_fullpath(NULL, this),
            corto_fullpath(NULL, this->type));
        goto error;
    }

    if (this->type->flags & CORTO_TYPE_HAS_TARGET) {
        ((corto_type)corto_parentof(this))->flags |= CORTO_TYPE_HAS_TARGET;
    }

    if ((this->type->kind == CORTO_COMPOSITE) && ((corto_interface)this->type)->kind == CORTO_DELEGATE) {
        ((corto_type)corto_parentof(this))->flags |= CORTO_TYPE_HAS_DELEGATE;
    }

    if (corto_typeof(this->type) == (corto_type)corto_target_o) {
        this->modifiers |= CORTO_OBSERVABLE;
    }

    return 0;
error:
    return -1;
}

int16_t corto_member_init(
    corto_member this)
{
    corto_object parent;
    corto_type parentType;

    if (corto_checkAttr(this, CORTO_ATTR_NAMED)) {
        parent = corto_parentof(this);
        parentType = corto_typeof(parent);

        if (parentType->kind == CORTO_COMPOSITE) {
            /* Bind member with composite object */
            if (corto__interface_bindMember(parent, this)) {
                goto error;
            }

            /* Set default member-modifiers - not during bootstrap */
            if (corto_checkState(corto_type_o, CORTO_VALID)) {
                this->modifiers = CORTO_GLOBAL;
                this->state = CORTO_DECLARED | CORTO_VALID;
            }
        } else {
            corto_throw(
              "invalid declaration of member '%s' in non-composite scope '%s'",
              corto_idof(this), corto_fullpath(NULL, parent));
            goto error;
        }
    }

    return 0;
error:
    return -1;
}
