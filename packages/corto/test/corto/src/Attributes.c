/* $CORTO_GENERATED
 *
 * Attributes.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

void _test_Attributes_tc_isDefaultPersistent(
    test_Attributes this)
{
/* $begin(test/Attributes/tc_isDefaultPersistent) */

    corto_int32Create_auto(i, 10);
    test_assert(i != NULL);
    test_assert(!corto_checkAttr(i, CORTO_ATTR_PERSISTENT));
    corto_delete(i);

/* $end */
}

void _test_Attributes_tc_isDefaultScopedPersistent(
    test_Attributes this)
{
/* $begin(test/Attributes/tc_isDefaultScopedPersistent) */

    corto_int32CreateChild_auto(root_o, i, 10);
    test_assert(i != NULL);
    test_assert(corto_checkAttr(i, CORTO_ATTR_PERSISTENT));
    corto_delete(i);
    
/* $end */
}

void _test_Attributes_tc_testDefaultSet(
    test_Attributes this)
{
/* $begin(test/Attributes/tc_testDefaultSet) */

    test_assertint(corto_getAttr(), CORTO_ATTR_DEFAULT);

/* $end */
}

void _test_Attributes_tc_testTargetAttr(
    test_Attributes this)
{
/* $begin(test/Attributes/tc_testTargetAttr) */

    corto_object o = corto_createChild(NULL, "a", test_TargetActual_o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_TargetActual_o));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_delete(o) == 0);

/* $end */
}

void _test_Attributes_tc_testTargetOrphanAttr(
    test_Attributes this)
{
/* $begin(test/Attributes/tc_testTargetOrphanAttr) */

    test_TargetActualMember* o = corto_createChild(NULL, "a", test_TargetActualMember_o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_TargetActualMember_o));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    test_assert(!corto_checkAttr(o->m, CORTO_ATTR_PERSISTENT));
    test_assert(corto_delete(o) == 0);

/* $end */
}

void _test_Attributes_tc_typeOverridesAttributes(
    test_Attributes this)
{
/* $begin(test/Attributes/tc_typeOverridesAttributes) */

    corto_object o = corto_create(test_TypeAttr_o);
    test_assert(o != NULL);
    test_assertint(corto_attrof(o), CORTO_ATTR_OBSERVABLE);
    test_assert(corto_delete(o) == 0);

/* $end */
}
