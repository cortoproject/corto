/* $CORTO_GENERATED
 *
 * SubscriberTest.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <test.h>

corto_int16 _test_SubscriberTest_construct(
    test_SubscriberTest this)
{
/* $begin(test/SubscriberTest/construct) */
    corto_int16 ret = 0;

    ret = corto_subscriber_subscribe(test_SubscriberTest_onDeclare_o, this);
    test_assert(ret == 0);

    ret = corto_subscriber_subscribe(test_SubscriberTest_onDeclareSelf_o, this);
    test_assert(ret == 0);

    ret = corto_subscriber_subscribe(test_SubscriberTest_onDeclareScope_o, this);
    test_assert(ret == 0);

    ret = corto_subscriber_subscribe(test_SubscriberTest_onDeclareTree_o, this);
    test_assert(ret == 0);

    return 0;
/* $end */
}

corto_void _test_SubscriberTest_destruct(
    test_SubscriberTest this)
{
/* $begin(test/SubscriberTest/destruct) */
    corto_int16 ret = 0;

    ret = corto_subscriber_unsubscribe(test_SubscriberTest_onDeclare_o, this);
    test_assert(ret == 0);

    ret = corto_subscriber_unsubscribe(test_SubscriberTest_onDeclareSelf_o, this);
    test_assert(ret == 0);

    ret = corto_subscriber_unsubscribe(test_SubscriberTest_onDeclareScope_o, this);
    test_assert(ret == 0);

    ret = corto_subscriber_unsubscribe(test_SubscriberTest_onDeclareTree_o, this);
    test_assert(ret == 0);

/* $end */
}

void _test_SubscriberTest_onDeclare(
    test_SubscriberTest instance,
    corto_eventMask *event,
    corto_result *object,
    corto_subscriber subscriber)
{
/* $begin(test/SubscriberTest/onDeclare) */

    /* << Insert implementation >> */

/* $end */
}

void _test_SubscriberTest_onDeclareScope(
    test_SubscriberTest instance,
    corto_eventMask *event,
    corto_result *object,
    corto_subscriber subscriber)
{
/* $begin(test/SubscriberTest/onDeclareScope) */

    /* << Insert implementation >> */

/* $end */
}

void _test_SubscriberTest_onDeclareSelf(
    test_SubscriberTest instance,
    corto_eventMask *event,
    corto_result *object,
    corto_subscriber subscriber)
{
/* $begin(test/SubscriberTest/onDeclareSelf) */

    /* << Insert implementation >> */

/* $end */
}

void _test_SubscriberTest_onDeclareTree(
    test_SubscriberTest instance,
    corto_eventMask *event,
    corto_result *object,
    corto_subscriber subscriber)
{
/* $begin(test/SubscriberTest/onDeclareTree) */

    /* << Insert implementation >> */

/* $end */
}
