/* This is a managed file. Do not delete this comment. */

#include <corto/corto.h>

bool corto_iterator_castable_v(
    corto_iterator this,
    corto_type type)
{
    return corto_iterator_compatible_v(this, type);
}

bool corto_iterator_compatible_v(
    corto_iterator this,
    corto_type type)
{
    corto_bool result = FALSE;
    if (type->kind == CORTO_COLLECTION) {
        if (corto_collection(type)->elementType == this->elementType) {
            result = TRUE;
        }
    } else if (type->kind == CORTO_ITERATOR) {
        if (this->elementType == corto_iterator(type)->elementType) {
            result = TRUE;
        }
    }


    return result;
}

int16_t corto_iterator_init(
    corto_iterator this)
{
    corto_type(this)->kind = CORTO_ITERATOR;
    corto_type(this)->size = sizeof(corto_iter);
    corto_type(this)->alignment = CORTO_ALIGNMENT(corto_iter);
    return corto_type_init(corto_type(this));
}

