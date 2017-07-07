/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

int16_t test_NestedConstructFailInTier1_construct(
    test_NestedConstructFailInTier1 this)
{
    corto_object parent = this;
    corto_int32 count = 0;
    while ((parent = corto_parentof(parent))) {
        count ++;
    }

    if (count == 2) return -1;

    return 0;
}

