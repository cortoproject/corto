/* $CORTO_GENERATED
 *
 * type.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/lang/lang.h>

/* $header() */
#include "_interface.h"

corto_int16 corto_type_bindMetaprocedure(corto_type this, corto_metaprocedure procedure) {
    corto_function* f;
    corto_int32 d = 0;

    /* Check if function is overloaded */
    if ((f = corto_vtableLookup(&this->metaprocedures, corto_idof(procedure), &d))) {
        if (d) {
            corto_function(*f)->overloaded = TRUE; /* Flag found and passed function as overloaded. */
            corto_function(procedure)->overloaded = TRUE;
        } else {
            if (*f != corto_function(procedure)) {
                /* Overriding metaprocedures is not allowed. */
                corto_seterr(
                  "definition of metaprocedure '%s' conflicts with existing '%s'",
                  corto_fullpath(NULL, *f),
                  corto_fullpath(NULL, procedure));
                goto error;
            }
        }
    }

    if (corto_vtableInsert(&this->metaprocedures, corto_function(procedure))) {
        corto_claim(procedure);
    }
    return 0;
error:
    return -1;
}
/* $end */

corto_uint16 _corto_type_alignmentof(
    corto_type this)
{
/* $begin(corto/lang/type/alignmentof) */
    corto_uint16 alignment;

    if (this->reference) {
        alignment = CORTO_ALIGNMENT(corto_object);
    } else {
        alignment = this->alignment;
    }
    return alignment;
/* $end */
}

corto_bool _corto_type_castable_v(
    corto_type this,
    corto_type type)
{
/* $begin(corto/lang/type/castable) */
    corto_bool result = FALSE;

    if (this->kind == CORTO_VOID) { /* A void reference can be casted to any reference type */
        if (this->reference && type->reference) {
            return TRUE;
        }
    }

    if (!result) {
        result = corto_type_compatible_v(this, type);
    }

    return result;
/* $end */
}

corto_bool _corto_type_compatible_v(
    corto_type this,
    corto_type type)
{
/* $begin(corto/lang/type/compatible) */
    corto_bool result;

    result = FALSE;

    if (this != type) {
        if (this->kind == CORTO_ANY) {
            result = TRUE;
        } else if (this->reference == type->reference) {
            if (type->reference) {
                if (this->kind == CORTO_VOID) {
                    result = TRUE;
                }
            }
        }
    } else {
        result = TRUE;
    }

    return result;
/* $end */
}

corto_int16 _corto_type_construct(
    corto_type this)
{
/* $begin(corto/lang/type/construct) */
    switch(this->kind) {
    case CORTO_ANY:
        this->size = sizeof(corto_any);
        this->alignment = CORTO_ALIGNMENT(corto_any);
        break;
    case CORTO_VOID:
        this->size = this->reference ? sizeof(void*) : 0;
        this->alignment = CORTO_ALIGNMENT(void*);
    default:
        break;
    }
    if (this->kind == CORTO_ANY) {
        this->flags |= CORTO_TYPE_NEEDS_INIT;
    }
    return 0;
/* $end */
}

corto_void _corto_type_destruct(
    corto_type this)
{
/* $begin(corto/lang/type/destruct) */
    corto_uint32 i;

    /* Free methods */
    for(i=0; i<this->metaprocedures.length; i++) {
        corto_release(this->metaprocedures.buffer[i]);
    }

    if (this->metaprocedures.buffer) {
        corto_dealloc(this->metaprocedures.buffer);
        this->metaprocedures.buffer = NULL;
    }
/* $end */
}

corto_int16 _corto_type_init(
    corto_type this)
{
/* $begin(corto/lang/type/init) */
    if (!this->options.parentState) {
        this->options.parentState = CORTO_DECLARED | CORTO_DEFINED;
    }
    if (!this->attr) {
        this->attr = CORTO_ATTR_DEFAULT;
    }
    return 0;
/* $end */
}

corto_function _corto_type_resolveProcedure(
    corto_type this,
    corto_string name)
{
/* $begin(corto/lang/type/resolveProcedure) */
    corto_function result = NULL;

    /* If type is an interface, try first to resolve a method on the interface */
    if (corto_instanceof((corto_type)corto_interface_o, this)) {
        result = (corto_function)corto_interface_resolveMethod(corto_interface(this), name);
    }

    /* If no method is found or type is not an interface, resolve metaprocedure */
    if (!result) {
        corto_function *f;
        corto_int32 d = 0, prevD = 9999;
        corto_class metaclass = corto_class(corto_typeof(this));

        /* Walk inheritance of metaclass to find metaprocedure */
        do {
            if ((f = corto_vtableLookup(&corto_type(metaclass)->metaprocedures, name, &d))) {
                if (d < prevD) {
                    result = *f;
                    prevD = d;
                }
            }
            metaclass = corto_class(corto_interface(metaclass)->base);
        }while(metaclass && !result);
    }

    return result;
/* $end */
}

corto_uint32 _corto_type_sizeof(
    corto_type this)
{
/* $begin(corto/lang/type/sizeof) */
    corto_uint32 size;
    if (this->reference) {
        size = sizeof(corto_object);
    } else {
        size = this->size;
    }
    return size;
/* $end */
}
