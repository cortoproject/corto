/* $CORTO_GENERATED
 *
 * SubscriberTest.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

/* $header() */
void test_SubscriberTest_setMembers(corto_subscriberEvent *e)
{
    test_SubscriberTest this = e->instance;
    corto_ptr_setstr(&this->lastId, e->data.id);
    corto_ptr_setstr(&this->lastParent,  e->data.parent);
    this->lastMask |= e->event;
    corto_subscriberListAppend(this->triggered, corto_subscriber(e->subscriber));
}
/* $end */

void _test_SubscriberTest_clear(
    test_SubscriberTest this)
{
/* $begin(test/SubscriberTest/clear) */

    corto_subscriberListClear(this->triggered);
    this->lastMask = 0;

/* $end */
}

int16_t _test_SubscriberTest_construct(
    test_SubscriberTest this)
{
/* $begin(test/SubscriberTest/construct) */
    corto_int16 ret = 0;

    ret = corto_subscriber_subscribe(test_SubscriberTest_onAll_o, this);
    test_assert(ret == 0);

    ret = corto_subscriber_subscribe(test_SubscriberTest_onSelf_o, this);
    test_assert(ret == 0);

    ret = corto_subscriber_subscribe(test_SubscriberTest_onScope_o, this);
    test_assert(ret == 0);

    ret = corto_subscriber_subscribe(test_SubscriberTest_onTree_o, this);
    test_assert(ret == 0);

    return 0;
/* $end */
}

void _test_SubscriberTest_destruct(
    test_SubscriberTest this)
{
/* $begin(test/SubscriberTest/destruct) */
    corto_int16 ret = 0;

    ret = corto_subscriber_unsubscribe(test_SubscriberTest_onAll_o, this);
    test_assert(ret == 0);

    ret = corto_subscriber_unsubscribe(test_SubscriberTest_onSelf_o, this);
    test_assert(ret == 0);

    ret = corto_subscriber_unsubscribe(test_SubscriberTest_onScope_o, this);
    test_assert(ret == 0);

    ret = corto_subscriber_unsubscribe(test_SubscriberTest_onTree_o, this);
    test_assert(ret == 0);

/* $end */
}

void _test_SubscriberTest_onAll(
    corto_subscriberEvent *e)
{
/* $begin(test/SubscriberTest/onAll) */

    test_SubscriberTest this = e->instance;
    test_SubscriberTest_setMembers(e);
    if (e->event & CORTO_ON_DECLARE) {
        this->countDeclare ++;
    }
    if (e->event & CORTO_ON_DEFINE) {
        this->countDefine ++;
    }
    if (e->event & CORTO_ON_UPDATE) {
        this->countUpdate ++;
    }

/* $end */
}

void _test_SubscriberTest_onScope(
    corto_subscriberEvent *e)
{
/* $begin(test/SubscriberTest/onScope) */

    test_SubscriberTest this = e->instance;
    test_SubscriberTest_setMembers(e);
    if (e->event & CORTO_ON_DECLARE) {
        this->countDeclareScope ++;
    }
    if (e->event & CORTO_ON_DEFINE) {
        this->countDefineScope ++;
    }
    if (e->event & CORTO_ON_UPDATE) {
        this->countUpdateScope ++;
    }

/* $end */
}

void _test_SubscriberTest_onSelf(
    corto_subscriberEvent *e)
{
/* $begin(test/SubscriberTest/onSelf) */

    test_SubscriberTest this = e->instance;
    test_SubscriberTest_setMembers(e);
    if (e->event & CORTO_ON_DECLARE) {
        this->countDeclareSelf ++;
    }
    if (e->event & CORTO_ON_DEFINE) {
        this->countDefineSelf ++;
    }
    if (e->event & CORTO_ON_UPDATE) {
        this->countUpdateSelf ++;
    }

/* $end */
}

void _test_SubscriberTest_onTree(
    corto_subscriberEvent *e)
{
/* $begin(test/SubscriberTest/onTree) */

    test_SubscriberTest this = e->instance;
    test_SubscriberTest_setMembers(e);
    if (e->event & CORTO_ON_DECLARE) {
        this->countDeclareTree ++;
    }
    if (e->event & CORTO_ON_DEFINE) {
        this->countDefineTree ++;
    }
    if (e->event & CORTO_ON_UPDATE) {
        this->countUpdateTree ++;
    }

/* $end */
}
