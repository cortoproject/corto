/* $CORTO_GENERATED
 *
 * float.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/corto.h>

int16_t _corto_float_init(
    corto_float this)
{
/* $begin(corto/lang/float/init) */
    corto_primitive(this)->kind = CORTO_FLOAT;
    return corto_primitive_init((corto_primitive)this);
/* $end */
}
