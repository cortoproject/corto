/* $CORTO_GENERATED
 *
 * target.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/lang/lang.h>

corto_int16 _corto_target_construct(
    corto_target this)
{
/* $begin(corto/lang/target/construct) */

    corto_member actual = corto_declareChild(this, "actual", corto_member_o);
    if (!actual) {
        goto error;
    }
    if (!corto_checkState(actual, CORTO_DEFINED)) {
        corto_setref(&actual->type, this->type);
        if (corto_define(actual)) {
            goto error;
        }
    }

    corto_member target = corto_declareChild(this, "target", corto_member_o);
    if (!target) {
        goto error;
    }
    if (!corto_checkState(target, CORTO_DEFINED)) {
        corto_setref(&target->type, this->type);
        if (corto_define(target)) {
            goto error;
        }
    }

    corto_member objective = corto_declareChild(this, "objective", corto_member_o);
    if (!target) {
        goto error;
    }
    if (!corto_checkState(objective, CORTO_DEFINED)) {
        corto_setref(&objective->type, this->type);
        if (corto_define(objective)) {
            goto error;
        }
    }

    corto_type(this)->reference = TRUE;
    corto_type(this)->flags |= CORTO_TYPE_HAS_TARGET;
    corto_type(this)->attr = CORTO_ATTR_OBSERVABLE | CORTO_ATTR_SCOPED | CORTO_ATTR_WRITABLE;

    return corto_struct_construct(this);
error:
    return -1;
/* $end */
}
