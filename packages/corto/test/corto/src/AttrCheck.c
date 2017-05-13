/* $CORTO_GENERATED
 *
 * AttrCheck.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

void _test_AttrCheck_tc_constructorAttr(
    test_AttrCheck this)
{
/* $begin(test/AttrCheck/tc_constructorAttr) */
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

/* $end */
}

void _test_AttrCheck_tc_packageMainAttr(
    test_AttrCheck this)
{
/* $begin(test/AttrCheck/tc_packageMainAttr) */
    corto_int8 ret;
    corto_int8 sig;

    test_assert(corto_chdir(TEST_ETC) == 0);

    sig = corto_proccmd("corto rebuild attrtest --silent", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

    test_assert(corto_load("attrtest", 0, NULL) == 0);

    sig = corto_proccmd("corto clean attrtest", &ret);
    test_assert(ret == 0);
    test_assert(sig == 0);

/* $end */
}

void _test_AttrCheck_tc_packageObjectAttr(
    test_AttrCheck this)
{
/* $begin(test/AttrCheck/tc_packageObjectAttr) */

    test_assertint(corto_attrof(test_o), CORTO_ATTR_SCOPED|CORTO_ATTR_PERSISTENT|CORTO_ATTR_OBSERVABLE);

/* $end */
}
