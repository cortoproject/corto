/* This is a managed file. Do not delete this comment. */

#include <corto>

bool corto_collection_castable_v(
    corto_collection this,
    corto_type type)
{
    corto_bool result = FALSE;
    if (type->kind == CORTO_COLLECTION) {
        corto_collection t = corto_collection(type);

        /* Arrays are only castable when they match exactly in size */
        if (!(this->kind == CORTO_ARRAY) || ((t->kind == CORTO_ARRAY) && (this->max == t->max))) {
            if (this->element_type != t->element_type) {
                if (this->element_type->kind == CORTO_COLLECTION) {
                    result = corto_collection_castable(corto_collection(this->element_type), t->element_type);
                }
            } else {
                result = TRUE;
            }
        }
    }

    return result;
}

bool corto_collection_compatible_v(
    corto_collection this,
    corto_type type)
{
    corto_bool result = FALSE;

    if (type->kind == CORTO_COLLECTION) {
        if (corto_collection(this)->kind == corto_collection(type)->kind) {
            if(corto_collection(this)->element_type == corto_collection(type)->element_type) {
                result = TRUE;
            }
            if(corto_collection(this)->kind == CORTO_MAP) {
                if(corto_map(this)->key_type != corto_map(type)->key_type) {
                    result = FALSE;
                }
            }
        }
    }

    return result;
}

int16_t corto_collection_init(
    corto_collection this)
{
    corto_type(this)->kind = CORTO_COLLECTION;
    return corto_type_init(corto_type(this));
}

bool corto_collection_requires_alloc(
    corto_type element_type)
{
    corto_bool result = TRUE;

    if (element_type->reference) {
        result = FALSE;
    } else {
        switch(element_type->kind) {
        case CORTO_VOID:
            ut_assert(0, "non reference void type cannot be an elementtype");
            break;
        case CORTO_ANY:
            /* Any values don't fit in an address */
            break;
        case CORTO_PRIMITIVE:
            switch(corto_primitive(element_type)->width) {
            case CORTO_WIDTH_8:
            case CORTO_WIDTH_16:
            case CORTO_WIDTH_32:
            case CORTO_WIDTH_WORD:
                /* At least a 32-bit architecture is required for corto. */
                result = FALSE;
                break;
            case CORTO_WIDTH_64:
                /* Even on 64-bit architectures, don't store value directly in list. This would change usage of a collection
                 * based on architecture which would make code-portability difficult. */
                break;
            }
            break;
        case CORTO_COLLECTION:
            switch(corto_collection(element_type)->kind) {
            case CORTO_ARRAY:
            case CORTO_SEQUENCE:
                /* Arrays and sequences (typically) don't fit in a collection */
                break;
            case CORTO_LIST:
            case CORTO_MAP:
                result = FALSE; /* Lists and maps fit in an address */
                break;
            }
            break;
        case CORTO_ITERATOR:
            /* Iterators are wider than an address */
            break;
        case CORTO_COMPOSITE:
            /* If type is composite and not a reference an alloc is required. */
            break;
        }
    }

    return result;
}
