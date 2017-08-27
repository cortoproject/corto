/* This is a managed file. Do not delete this comment. */

#include <corto/corto.h>


#include <src/_object.h>

corto_int16 corto_unitinstance_construct(corto_object this) {
    corto_interface base = corto_interface(corto_typeof(this));
    corto_unit u = corto_unit(corto_typeof(base));

    /* Copy unit type into me */
    if (corto_copy(&this, u->type)) {
        goto error;
    }

    return corto_super_construct(this);
error:
    return -1;
}


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
    }

    /* The resulting type shall be like an alias for 'this->type'  */
    corto_ptr_setref(&corto_interface(this)->base, corto_interface(corto_typeof(this->type)));
    corto_struct(this)->baseAccess = CORTO_PRIVATE;

    /* Setup the constructor */
    corto_function constructor = corto_declareChild(this, "construct()", corto_method_o);
        if (!constructor) goto error;
        if (constructor && corto_checkState(constructor, CORTO_VALID)) {
            corto_seterr("unit '%s' has illegal custom-defined constructor", corto_fullpath(NULL, this));
            goto error;
        }
        constructor->kind = CORTO_PROCEDURE_CDECL;
        constructor->fptr = (corto_word)corto_unitinstance_construct;
        if (corto_define(constructor)) goto error;

    /* Setup members for quantity, symbol, conversion */
    /*corto_member quantity = corto_declareChild(this, "quantity", corto_member_o);
        if (!quantity) goto error;
        corto_ptr_setref(&quantity->type, corto_quantity_o);
        if (corto_define(quantity)) goto error;

    corto_member symbol = corto_declareChild(this, "symbol", corto_string_o);
        if (!quantity) goto error;
        corto_ptr_setref(&quantity->type, corto_quantity_o);
        if (corto_define(quantity)) goto error;

    corto_member conversion = corto_declareChild(this, "conversion", corto_string_o);
        if (!quantity) goto error;
        corto_ptr_setref(&quantity->type, corto_quantity_o);
        if (corto_define(quantity)) goto error;*/

    return safe_corto_class_construct(this);
error:
    return -1;
}

void corto_unit_destruct(
    corto_unit this)
{

    CORTO_UNUSED(this);

}

int16_t corto_unit_init(
    corto_unit this)
{

    corto_ptr_setref(&this->type, corto_float64_o);
    return 0;
}

