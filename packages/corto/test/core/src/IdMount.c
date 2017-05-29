/* $CORTO_GENERATED
 *
 * IdMount.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

int16_t _test_IdMount_construct(
    test_IdMount this)
{
/* $begin(test/IdMount/construct) */

    corto_mount(this)->policy.ownership = CORTO_LOCAL_OWNER;
    corto_ptr_setstr(&corto_subscriber(this)->query.select, "//");

    return corto_mount_construct(this);
/* $end */
}

corto_string _test_IdMount_onId(
    test_IdMount this)
{
/* $begin(test/IdMount/onId) */

    return corto_strdup("some_unique_id");

/* $end */
}
