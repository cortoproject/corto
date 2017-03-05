/* $CORTO_GENERATED
 *
 * unit.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/lang/lang.h>

/* $header() */
#include <src/_object.h>
/* $end */

corto_int16 _corto_unit_construct(
    corto_unit this)
{
/* $begin(corto/lang/unit/construct) */
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
    }

    return 0;
error:
    return -1;
/* $end */
}

corto_void _corto_unit_destruct(
    corto_unit this)
{
/* $begin(corto/lang/unit/destruct) */

    CORTO_UNUSED(this);

/* $end */
}

corto_int16 _corto_unit_init(
    corto_unit this)
{
/* $begin(corto/lang/unit/init) */

    corto_setref(&this->type, corto_float64_o);
    return 0;
/* $end */
}
