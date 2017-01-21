/* $CORTO_GENERATED
 *
 * EmptySinkMount.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <test.h>

corto_int16 _test_EmptySinkMount_construct(
    test_EmptySinkMount this)
{
/* $begin(test/EmptySinkMount/construct) */

    corto_mount(this)->kind = CORTO_SINK;
    return 0;

/* $end */
}
