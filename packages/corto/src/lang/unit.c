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
    ext_corto_expr *expr = NULL;

    if (this->conversion) {
        corto_id typeId;
        expr = ext_corto_expr_alloc();

        corto_fullpath(typeId, this->type);
        char *types[] = {typeId};

        if (ext_corto_expr_compb(expr, NULL, this->conversion, types)) {
            corto_dealloc(expr);
            goto error;
        }

        this->toQuantity = (corto_word)expr;
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
