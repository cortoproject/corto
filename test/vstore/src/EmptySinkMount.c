/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

int16_t test_EmptySinkMount_construct(
    test_EmptySinkMount this)
{

    corto_mount(this)->policy.ownership = CORTO_LOCAL_SOURCE;
    return corto_mount_construct(this);

}

