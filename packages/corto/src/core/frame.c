/* $CORTO_GENERATED
 *
 * frame.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <corto/corto.h>

corto_time _corto_frame_getTime(
    corto_frame* this)
{
/* $begin(corto/core/frame/getTime) */
    union {
        corto_time t;
        corto_uint64 i;
    } toInt;
    toInt.i = this->value;
    return toInt.t;
/* $end */
}
