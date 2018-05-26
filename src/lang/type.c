/* This is a managed file. Do not delete this comment. */

#include <corto/corto.h>
#include "interface.h"
#include "src/store/object.h"

corto_int16 corto_type_bindMetaprocedure(
    corto_type this,
    corto_metaprocedure procedure)
{
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
                corto_throw(
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

uint16_t corto_type_alignmentof(
    corto_type this)
{
    corto_uint16 alignment;

    if (this->reference) {
        alignment = CORTO_ALIGNMENT(corto_object);
    } else {
        alignment = this->alignment;
    }

    return alignment;
}

bool corto_type_castable_v(
    corto_type this,
    corto_type type)
{
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
}

bool corto_type_compatible_v(
    corto_type this,
    corto_type type)
{
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
}

int16_t corto_type_construct(
    corto_type this)
{
    switch(this->kind) {
    case CORTO_ANY:
        this->size = sizeof(corto_any);
        this->alignment = CORTO_ALIGNMENT(corto_any);
        break;
    case CORTO_VOID:
        this->size = this->reference ? sizeof(void*) : 0;
        this->alignment = CORTO_ALIGNMENT(void*);
        break;
    default:
        break;
    }

    if (this->kind == CORTO_ANY) {
        this->flags |= CORTO_TYPE_NEEDS_INIT;
    }

    if (this->init.super.procedure) {
        this->flags |= CORTO_TYPE_HAS_INIT;
    }

    if (this->deinit.super.procedure) {
        this->flags |= CORTO_TYPE_HAS_DEINIT;
    }

    this->typecache = (uintptr_t)corto_typecache_create(this);

    return 0;
}

void corto_type_destruct(
    corto_type this)
{
    corto_uint32 i;

    /* Free methods */
    for(i=0; i<this->metaprocedures.length; i++) {
        corto_release(this->metaprocedures.buffer[i]);
    }

    if (this->metaprocedures.buffer) {
        corto_dealloc(this->metaprocedures.buffer);
        this->metaprocedures.buffer = NULL;
    }

    // free((void*)this->typecache);
}

int16_t corto_type_init(
    corto_type this)
{
    if (!this->options.parentState) {
        this->options.parentState = CORTO_DECLARED | CORTO_VALID;
    }

    if (!this->attr) {
        this->attr = CORTO_ATTR_DEFAULT;
    }

    if (this->reference && this->kind == CORTO_VOID) {
        this->flags |= CORTO_TYPE_HAS_RESOURCES;
    }

    return 0;
}

void corto_type_deinit(
    corto_type this)
{
    free ((corto_typecache*)this->typecache);
}

corto_function corto_type_resolveProcedure(
    corto_type this,
    const char *name)
{
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
            if ((f = corto_vtableLookup(
                &corto_type(metaclass)->metaprocedures, name, &d)))
            {
                if (d < prevD) {
                    result = *f;
                    prevD = d;
                }
            }

            metaclass = corto_class(corto_interface(metaclass)->base);
        } while(metaclass && !result);
    }

    return result;
}

uint32_t corto_type_sizeof(
    corto_type this)
{
    corto_uint32 size;
    if (this->reference) {
        size = sizeof(corto_object);
    } else {
        size = this->size;
    }

    return size;
}
