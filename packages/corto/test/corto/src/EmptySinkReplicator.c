/* $CORTO_GENERATED
 *
 * EmptySinkReplicator.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <test.h>

corto_int16 _test_EmptySinkReplicator_construct(
    test_EmptySinkReplicator this)
{
/* $begin(test/EmptySinkReplicator/construct) */

    corto_mount(this)->kind = CORTO_SINK;
    return 0;

/* $end */
}
