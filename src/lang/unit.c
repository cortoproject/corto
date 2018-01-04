/* This is a managed file. Do not delete this comment. */

#include <corto/corto.h>

#include <src/store/object.h>

int16_t corto_unit_construct(
    corto_unit this)
{
    ext_corto_expr *exprToQuantity = NULL, *exprFromQuantity = NULL;

    if (this->conversion) {
        corto_id typeId;
        exprToQuantity = ext_corto_expr_alloc();
        exprFromQuantity = ext_corto_expr_alloc();

        corto_fullpath(typeId, this->type);
        char *types[] = {typeId};

        if (ext_corto_expr_compb(exprToQuantity, NULL, this->conversion, types)) {
            corto_dealloc(exprToQuantity);
            goto error;
        }

        ext_corto_expr_opt opt = {.inverse = TRUE};

        if (ext_corto_expr_compb(exprFromQuantity, &opt, this->conversion, types)) {
            corto_dealloc(exprFromQuantity);
            goto error;
        }

        this->toQuantity = (corto_word)exprToQuantity;
        this->fromQuantity = (corto_word)exprFromQuantity;
    } else {
        /* If unit does not specify a conversion, then this is the base unit for
         * the quantity. */
        corto_set_ref(&this->quantity->base_unit, this);
    }

    return 0;
error:
    return -1;
}

int16_t corto_unit_init(
    corto_unit this)
{
    corto_set_ref(&this->type, corto_float64_o);
    return 0;
}
