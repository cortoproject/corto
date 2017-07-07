/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

int16_t test_NestedInitFailInRoot_init(
    test_NestedInitFailInRoot* this)
{

    if (corto_parentof(this) == root_o) {
        return -1;
    }

    return 0;
}

