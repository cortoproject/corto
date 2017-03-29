/* $CORTO_GENERATED
 *
 * NestedInitFailInRoot.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

corto_int16 _test_NestedInitFailInRoot_init(
    test_NestedInitFailInRoot* this)
{
/* $begin(test/NestedInitFailInRoot/init) */

    if (corto_parentof(this) == root_o) {
        return -1;
    }

    return 0;
/* $end */
}
