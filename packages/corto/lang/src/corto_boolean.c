/* $CORTO_GENERATED
 *
 * corto_boolean.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "corto.h"

corto_int16 _corto_boolean_init(corto_boolean this) {
/* $begin(::corto::lang::boolean::init) */
    corto_primitive(this)->kind = CORTO_BOOLEAN;
    corto_primitive(this)->width = CORTO_WIDTH_8;
    return corto_primitive_init((corto_primitive)this);
/* $end */
}
