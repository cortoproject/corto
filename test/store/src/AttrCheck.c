/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_AttrCheck_tc_constructorAttr(
    test_AttrCheck this)
{
    corto_int16 ret;

    corto_object o = test_AttrConstructorTestCreate();
    test_assert(o != NULL);

    ret = corto_delete(o);
    test_assert(ret == 0);

    corto_attr prev = corto_setAttr(CORTO_ATTR_PERSISTENT);
    o = test_AttrConstructorTestCreate();
    test_assert(o != NULL);
    corto_setAttr(prev);

    ret = corto_delete(o);
    test_assert(ret == 0);

}

void test_AttrCheck_tc_packageMainAttr(
    test_AttrCheck this)
{
    corto_int8 ret;
    corto_int8 sig;

    test_assert(corto_chdir(TEST_ETC) == 0);

    sig = corto_proc_cmd("bake rebuild attrtest --error", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    test_assert(corto_use("attrtest", 0, NULL) == 0);

    sig = corto_proc_cmd("bake clean attrtest --error", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

}

void test_AttrCheck_tc_packageObjectAttr(
    test_AttrCheck this)
{

    test_assertint(corto_attrof(test_o), CORTO_ATTR_NAMED|CORTO_ATTR_PERSISTENT|CORTO_ATTR_OBSERVABLE);

}
