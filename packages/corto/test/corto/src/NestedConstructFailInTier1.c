/* $CORTO_GENERATED
 *
 * NestedConstructFailInTier1.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

int16_t _test_NestedConstructFailInTier1_construct(
    test_NestedConstructFailInTier1 this)
{
/* $begin(test/NestedConstructFailInTier1/construct) */
    corto_object parent = this;
    corto_int32 count = 0;
    while ((parent = corto_parentof(parent))) {
        count ++;
    }

    if (count == 2) return -1;

    return 0;
/* $end */
}
