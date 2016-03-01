/* $CORTO_GENERATED
 *
 * uint.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "corto/lang/lang.h"

corto_int16 _corto_uint_init(
    corto_uint this)
{
/* $begin(corto/lang/uint/init) */
    corto_primitive(this)->kind = CORTO_UINTEGER;
    return corto_primitive_init((corto_primitive)this);
/* $end */
}
