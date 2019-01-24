/* This is a managed file. Do not delete this comment. */

#include <corto>

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
        if (corto_collection(type)->element_type == this->element_type) {
            result = TRUE;
        }
    } else if (type->kind == CORTO_ITERATOR) {
        if (this->element_type == corto_iterator(type)->element_type) {
            result = TRUE;
        }
    }


    return result;
}

int16_t corto_iterator_init(
    corto_iterator this)
{
    corto_type(this)->kind = CORTO_ITERATOR;
    corto_type(this)->size = sizeof(ut_iter);
    corto_type(this)->alignment = CORTO_ALIGNMENT(ut_iter);
    return corto_type_init(corto_type(this));
}

