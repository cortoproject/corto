/* $CORTO_GENERATED
 *
 * iterator.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/lang/lang.h>

bool _corto_iterator_castable_v(
    corto_iterator this,
    corto_type type)
{
/* $begin(corto/lang/iterator/castable) */
    return corto_iterator_compatible_v(this, type);
/* $end */
}

bool _corto_iterator_compatible_v(
    corto_iterator this,
    corto_type type)
{
/* $begin(corto/lang/iterator/compatible) */
    corto_bool result = FALSE;
    if (type->kind == CORTO_COLLECTION) {
        if (corto_collection(type)->elementType == this->elementType) {
            result = TRUE;
        }
    }
    return result;
/* $end */
}

int16_t _corto_iterator_init(
    corto_iterator this)
{
/* $begin(corto/lang/iterator/init) */
    corto_type(this)->kind = CORTO_ITERATOR;
    corto_type(this)->size = sizeof(corto_iter);
    corto_type(this)->alignment = CORTO_ALIGNMENT(corto_iter);
    return corto_type_init(corto_type(this));
/* $end */
}
