/* $CORTO_GENERATED
 *
 * AttrCheck.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <test.h>

corto_void _test_AttrCheck_tc_constructorAttr(
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

corto_void _test_AttrCheck_tc_packageMainAttr(
    test_AttrCheck this)
{
/* $begin(test/AttrCheck/tc_packageMainAttr) */

    corto_int16 ret = corto_load("attrtest", 0, NULL);
    test_assert(ret == 0);

/* $end */
}

corto_void _test_AttrCheck_tc_packageObjectAttr(
    test_AttrCheck this)
{
/* $begin(test/AttrCheck/tc_packageObjectAttr) */

    test_assertint(corto_attrof(test_o), CORTO_ATTR_SCOPED|CORTO_ATTR_PERSISTENT);

/* $end */
}
