/* $CORTO_GENERATED
 *
 * type.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "corto/native/native.h"

corto_int16 _corto_native_type_init(
    corto_native_type this)
{
/* $begin(corto/native/type/init) */
    corto_primitive(this)->width = CORTO_WIDTH_WORD;
    return corto_binary_init(this);
/* $end */
}
