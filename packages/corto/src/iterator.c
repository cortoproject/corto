/* $CORTO_GENERATED
 *
 * corto_iterator.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "corto.h"

corto_bool _corto_iterator_castable_v(corto_iterator this, corto_type type) {
/* $begin(corto/lang/iterator/castable) */
    return corto_iterator_compatible_v(this, type);
/* $end */
}

corto_bool _corto_iterator_compatible_v(corto_iterator this, corto_type type) {
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

corto_int16 _corto_iterator_init(corto_iterator this) {
/* $begin(corto/lang/iterator/init) */
    corto_type(this)->kind = CORTO_ITERATOR;
    corto_type(this)->size = sizeof(corto_iter);
    return corto_type_init(corto_type(this));
/* $end */
}
