/* $CORTO_GENERATED
 *
 * Attributes.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <test.h>

corto_void _test_Attributes_tc_isDefaultPersistent(
    test_Attributes this)
{
/* $begin(test/Attributes/tc_isDefaultPersistent) */

    corto_int32Create_auto(i, 10);
    test_assert(i != NULL);
    test_assert(!corto_checkAttr(i, CORTO_ATTR_PERSISTENT));
    corto_delete(i);

/* $end */
}

corto_void _test_Attributes_tc_isDefaultScopedPersistent(
    test_Attributes this)
{
/* $begin(test/Attributes/tc_isDefaultScopedPersistent) */

    corto_int32CreateChild_auto(root_o, i, 10);
    test_assert(i != NULL);
    test_assert(corto_checkAttr(i, CORTO_ATTR_PERSISTENT));
    corto_delete(i);
    
/* $end */
}

corto_void _test_Attributes_tc_testDefaultSet(
    test_Attributes this)
{
/* $begin(test/Attributes/tc_testDefaultSet) */

    test_assertint(corto_getAttr(), CORTO_ATTR_DEFAULT);

/* $end */
}
