/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

int16_t test_IdMount_construct(
    test_IdMount this)
{

    corto_mount(this)->policy.ownership = CORTO_LOCAL_SOURCE;
    corto_set_str(&corto_subscriber(this)->query.select, "//");

    return corto_mount_construct(this);
}

corto_string test_IdMount_onId(
    test_IdMount this)
{

    return corto_strdup("some_unique_id");

}

