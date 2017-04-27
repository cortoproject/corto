/* $CORTO_GENERATED
 *
 * NestedConstructFailInRoot.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

int16_t _test_NestedConstructFailInRoot_construct(
    test_NestedConstructFailInRoot this)
{
/* $begin(test/NestedConstructFailInRoot/construct) */
    corto_object parent = this;
    corto_int32 count = 0;
    while ((parent = corto_parentof(parent))) {
        count ++;
    }

    if (count == 1) return -1;

    return 0;
/* $end */
}
