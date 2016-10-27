/* $CORTO_GENERATED
 *
 * Subscribe.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <test.h>

void _test_Subscribe_noInitialSep(
    test_Subscribe this,
    corto_eventMask event,
    corto_result *object,
    corto_subscriber subscriber)
{
/* $begin(test/Subscribe/noInitialSep) */
    this->triggered ++;
/* $end */
}

corto_void _test_Subscribe_tc_noInitialSep(
    test_Subscribe this)
{
/* $begin(test/Subscribe/tc_noInitialSep) */
    test_assertint(this->triggered, 0);

    corto_voidCreateChild_auto(root_o, testScope);
    corto_int32CreateChild_auto(testScope, i, 10);
    test_assertint(this->triggered, 0);

    corto_int16 ret = corto_subscriber_subscribe(test_Subscribe_noInitialSep_o, this);
    test_assert(ret == 0);
    test_assertint(this->triggered, 0);

    ret = corto_int32Update(i, 20);
    test_assert(ret == 0);

    test_assertint(this->triggered, 1);

/* $end */
}
