/* This is a managed file. Do not delete this comment. */

#include <corto/corto.h>

int16_t corto_procedure_construct(
    corto_procedure this)
{

    if (!this->hasThis) {
        if (corto_interface(this)->base && 
            corto_instanceof(corto_procedure_o, corto_interface(this)->base)) 
        {
            this->hasThis = corto_procedure(corto_interface(this)->base)->hasThis;
        }
    }

    return safe_corto_class_construct(this);
}

int16_t corto_procedure_init(
    corto_procedure this)
{

    if (corto_interface_init(corto_interface(this))) {
        goto error;
    }

    corto_interface(this)->kind = CORTO_PROCEDURE;
    corto_type(this)->reference = TRUE;

    return 0;
error:
    return -1;
}

