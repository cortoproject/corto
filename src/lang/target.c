/* This is a managed file. Do not delete this comment. */

#include <corto/corto.h>

int16_t corto_target_construct(
    corto_target this)
{

    corto_member actual = corto(this, "actual", corto_member_o, NULL, NULL, NULL, -1, CORTO_DO_DECLARE | CORTO_DO_FORCE_TYPE);
    if (!actual) {
        goto error;
    }
    if (!corto_checkState(actual, CORTO_VALID)) {
        corto_ptr_setref(&actual->type, this->type);
        if (!corto(NULL, NULL, NULL, actual, NULL, NULL, -1, CORTO_DO_DEFINE)) {
            goto error;
        }
    }

    corto_member target = corto(this, "target", corto_member_o, NULL, NULL, NULL, -1, CORTO_DO_DECLARE | CORTO_DO_FORCE_TYPE);
    if (!target) {
        goto error;
    }
    if (!corto_checkState(target, CORTO_VALID)) {
        corto_ptr_setref(&target->type, this->type);
        if (!corto(NULL, NULL, NULL, target, NULL, NULL, -1, CORTO_DO_DEFINE)) {
            goto error;
        }
    }

    corto_member objective = corto(this, "objective", corto_member_o, NULL, NULL, NULL, -1, CORTO_DO_DECLARE | CORTO_DO_FORCE_TYPE);
    if (!target) {
        goto error;
    }
    if (!corto_checkState(objective, CORTO_VALID)) {
        corto_ptr_setref(&objective->type, this->type);
        if (!corto(NULL, NULL, NULL, objective, NULL, NULL, -1, CORTO_DO_DEFINE)) {
            goto error;
        }
    }

    corto_type(this)->reference = TRUE;
    corto_type(this)->flags |= CORTO_TYPE_HAS_TARGET;
    corto_type(this)->attr = CORTO_ATTR_OBSERVABLE | CORTO_ATTR_NAMED | CORTO_ATTR_WRITABLE;

    return safe_corto_struct_construct(this);
error:
    return -1;
}
