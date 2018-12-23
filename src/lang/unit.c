/* This is a managed file. Do not delete this comment. */

#include <corto>

#include <src/store/object.h>

int16_t corto_unit_construct(
    corto_unit this)
{
    return 0;
}

int16_t corto_unit_init(
    corto_unit this)
{
    corto_set_ref(&this->type, corto_float64_o);
    return 0;
}
