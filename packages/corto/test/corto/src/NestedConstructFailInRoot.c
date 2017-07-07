/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

int16_t test_NestedConstructFailInRoot_construct(
    test_NestedConstructFailInRoot this)
{
    corto_object parent = this;
    corto_int32 count = 0;
    while ((parent = corto_parentof(parent))) {
        count ++;
    }

    if (count == 1) return -1;

    return 0;
}

