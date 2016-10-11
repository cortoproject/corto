/* $CORTO_GENERATED
 *
 * SubscriberEvent.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <test.h>

corto_void _test_SubscriberEvent_setup(
    test_SubscriberEvent this)
{
/* $begin(test/SubscriberEvent/setup) */

    this->prevAttr = corto_setAttr(CORTO_ATTR_DEFAULT);

/* $end */
}

corto_void _test_SubscriberEvent_teardown(
    test_SubscriberEvent this)
{
/* $begin(test/SubscriberEvent/teardown) */

    corto_setAttr(this->prevAttr);

/* $end */
}
