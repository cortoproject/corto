/* $CORTO_GENERATED
 *
 * NestedInitFailInTier1.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

corto_int16 _test_NestedInitFailInTier1_init(
    test_NestedInitFailInTier1* this)
{
/* $begin(test/NestedInitFailInTier1/init) */
    corto_object parent = this;
    corto_int32 count = 0;
    while ((parent = corto_parentof(parent))) {
        count ++;
    }

    if (count == 2) return -1;

    return 0;
/* $end */
}
