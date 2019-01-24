/* This is a managed file. Do not delete this comment. */

#include <corto>

corto_time corto_frame_getTime(
    corto_frame* this)
{
    union {
        corto_time t;
        corto_uint64 i;
    } toInt;
    toInt.i = this->value;
    return toInt.t;
}

