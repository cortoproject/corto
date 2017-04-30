/* $CORTO_GENERATED
 *
 * procedure.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/corto.h>

int16_t _corto_procedure_construct(
    corto_procedure this)
{
/* $begin(corto/lang/procedure/construct) */

    if (!this->hasThis) {
        if (corto_interface(this)->base && 
            corto_instanceof(corto_procedure_o, corto_interface(this)->base)) 
        {
            this->hasThis = corto_procedure(corto_interface(this)->base)->hasThis;
        }
    }

    return corto_class_construct(this);
/* $end */
}

int16_t _corto_procedure_init(
    corto_procedure this)
{
/* $begin(corto/lang/procedure/init) */

    if (corto_interface_init(corto_interface(this))) {
        goto error;
    }

    corto_interface(this)->kind = CORTO_PROCEDURE;
    corto_type(this)->reference = TRUE;

    return 0;
error:
    return -1;
/* $end */
}
