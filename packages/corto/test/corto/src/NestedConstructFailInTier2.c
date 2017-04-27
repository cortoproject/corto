/* $CORTO_GENERATED
 *
 * NestedConstructFailInTier2.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

int16_t _test_NestedConstructFailInTier2_construct(
    test_NestedConstructFailInTier2 this)
{
/* $begin(test/NestedConstructFailInTier2/construct) */
    corto_object parent = this;
    corto_int32 count = 0;
    while ((parent = corto_parentof(parent))) {
        count ++;
    }

    if (count == 3) return -1;

    return 0;
/* $end */
}
