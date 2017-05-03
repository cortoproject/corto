/* $CORTO_GENERATED
 *
 * EmptySinkMount.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

int16_t _test_EmptySinkMount_construct(
    test_EmptySinkMount this)
{
/* $begin(test/EmptySinkMount/construct) */

    corto_mount(this)->kind = CORTO_SINK;
    return corto_mount_construct(this);

/* $end */
}
