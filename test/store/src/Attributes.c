/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_Attributes_tc_isDefaultPersistent(
    test_Attributes this)
{

    corto_int32Create_auto(i, 10);
    test_assert(i != NULL);
    test_assert(!corto_check_attr(i, CORTO_ATTR_PERSISTENT));
    corto_delete(i);

}

void test_Attributes_tc_isDefaultScopedPersistent(
    test_Attributes this)
{

    corto_int32CreateChild_auto(root_o, i, 10);
    test_assert(i != NULL);
    test_assert(corto_check_attr(i, CORTO_ATTR_PERSISTENT));
    corto_delete(i);

}

void test_Attributes_tc_testDefaultSet(
    test_Attributes this)
{

    test_assertint(corto_get_attr(), CORTO_ATTR_DEFAULT);

}

void test_Attributes_tc_testTargetAttr(
    test_Attributes this)
{

    corto_object o = corto_create(root_o, "a", test_TargetActual_o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_TargetActual_o));
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));
    test_assert(corto_delete(o) == 0);

}

void test_Attributes_tc_testTargetOrphanAttr(
    test_Attributes this)
{

    test_TargetActualMember* o = corto_create(root_o, "a", test_TargetActualMember_o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_type(test_TargetActualMember_o));
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));
    test_assert(!corto_check_attr(o->m, CORTO_ATTR_PERSISTENT));
    test_assert(corto_delete(o) == 0);

}

void test_Attributes_tc_typeOverridesAttributes(
    test_Attributes this)
{

    corto_object o = corto_create(NULL, NULL, test_TypeAttr_o);
    test_assert(o != NULL);
    test_assertint(corto_attrof(o), CORTO_ATTR_OBSERVABLE);
    test_assert(corto_delete(o) == 0);

}
