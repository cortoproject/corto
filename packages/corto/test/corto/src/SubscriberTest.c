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
    corto_setstr(&this->lastId, e->data.id);
    corto_setstr(&this->lastParent,  e->data.parent);
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

    ret = corto_subscriber_subscribe(test_SubscriberTest_onDeclare_o, this);
    test_assert(ret == 0);

    ret = corto_subscriber_subscribe(test_SubscriberTest_onDeclareSelf_o, this);
    test_assert(ret == 0);

    ret = corto_subscriber_subscribe(test_SubscriberTest_onDeclareScope_o, this);
    test_assert(ret == 0);

    ret = corto_subscriber_subscribe(test_SubscriberTest_onDeclareTree_o, this);
    test_assert(ret == 0);

    ret = corto_subscriber_subscribe(test_SubscriberTest_onDefine_o, this);
    test_assert(ret == 0);

    ret = corto_subscriber_subscribe(test_SubscriberTest_onDefineSelf_o, this);
    test_assert(ret == 0);

    ret = corto_subscriber_subscribe(test_SubscriberTest_onDefineScope_o, this);
    test_assert(ret == 0);

    ret = corto_subscriber_subscribe(test_SubscriberTest_onDefineTree_o, this);
    test_assert(ret == 0);

    ret = corto_subscriber_subscribe(test_SubscriberTest_onUpdate_o, this);
    test_assert(ret == 0);

    ret = corto_subscriber_subscribe(test_SubscriberTest_onUpdateSelf_o, this);
    test_assert(ret == 0);

    ret = corto_subscriber_subscribe(test_SubscriberTest_onUpdateScope_o, this);
    test_assert(ret == 0);

    ret = corto_subscriber_subscribe(test_SubscriberTest_onUpdateTree_o, this);
    test_assert(ret == 0);


    return 0;
/* $end */
}

void _test_SubscriberTest_destruct(
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

    ret = corto_subscriber_unsubscribe(test_SubscriberTest_onDefine_o, this);
    test_assert(ret == 0);

    ret = corto_subscriber_unsubscribe(test_SubscriberTest_onDefineSelf_o, this);
    test_assert(ret == 0);

    ret = corto_subscriber_unsubscribe(test_SubscriberTest_onDefineScope_o, this);
    test_assert(ret == 0);

    ret = corto_subscriber_unsubscribe(test_SubscriberTest_onDefineTree_o, this);
    test_assert(ret == 0);

    ret = corto_subscriber_unsubscribe(test_SubscriberTest_onUpdate_o, this);
    test_assert(ret == 0);

    ret = corto_subscriber_unsubscribe(test_SubscriberTest_onUpdateSelf_o, this);
    test_assert(ret == 0);

    ret = corto_subscriber_unsubscribe(test_SubscriberTest_onUpdateScope_o, this);
    test_assert(ret == 0);

    ret = corto_subscriber_unsubscribe(test_SubscriberTest_onUpdateTree_o, this);
    test_assert(ret == 0);

/* $end */
}

void _test_SubscriberTest_onDeclare(
    corto_subscriberEvent *e)
{
/* $begin(test/SubscriberTest/onDeclare) */
    test_SubscriberTest this = e->instance;
    test_SubscriberTest_setMembers(e);
    this->countDeclare ++;
/* $end */
}

void _test_SubscriberTest_onDeclareScope(
    corto_subscriberEvent *e)
{
/* $begin(test/SubscriberTest/onDeclareScope) */
    test_SubscriberTest this = e->instance;
    test_SubscriberTest_setMembers(e);
    this->countDeclareScope ++;
/* $end */
}

void _test_SubscriberTest_onDeclareSelf(
    corto_subscriberEvent *e)
{
/* $begin(test/SubscriberTest/onDeclareSelf) */
    test_SubscriberTest this = e->instance;
    test_SubscriberTest_setMembers(e);
    this->countDeclareSelf ++;
/* $end */
}

void _test_SubscriberTest_onDeclareTree(
    corto_subscriberEvent *e)
{
/* $begin(test/SubscriberTest/onDeclareTree) */
    test_SubscriberTest this = e->instance;
    test_SubscriberTest_setMembers(e);
    this->countDeclareTree ++;
/* $end */
}

void _test_SubscriberTest_onDefine(
    corto_subscriberEvent *e)
{
/* $begin(test/SubscriberTest/onDefine) */
    test_SubscriberTest this = e->instance;
    test_SubscriberTest_setMembers(e);
    this->countDefine ++;
/* $end */
}

void _test_SubscriberTest_onDefineScope(
    corto_subscriberEvent *e)
{
/* $begin(test/SubscriberTest/onDefineScope) */
    test_SubscriberTest this = e->instance;
    test_SubscriberTest_setMembers(e);
    this->countDefineScope ++;
/* $end */
}

void _test_SubscriberTest_onDefineSelf(
    corto_subscriberEvent *e)
{
/* $begin(test/SubscriberTest/onDefineSelf) */
    test_SubscriberTest this = e->instance;
    test_SubscriberTest_setMembers(e);
    this->countDefineSelf ++;
/* $end */
}

void _test_SubscriberTest_onDefineTree(
    corto_subscriberEvent *e)
{
/* $begin(test/SubscriberTest/onDefineTree) */
    test_SubscriberTest this = e->instance;
    test_SubscriberTest_setMembers(e);
    this->countDefineTree ++;
/* $end */
}

void _test_SubscriberTest_onUpdate(
    corto_subscriberEvent *e)
{
/* $begin(test/SubscriberTest/onUpdate) */
    test_SubscriberTest this = e->instance;
    test_SubscriberTest_setMembers(e);
    this->countUpdate ++;
/* $end */
}

void _test_SubscriberTest_onUpdateScope(
    corto_subscriberEvent *e)
{
/* $begin(test/SubscriberTest/onUpdateScope) */
    test_SubscriberTest this = e->instance;
    test_SubscriberTest_setMembers(e);
    this->countUpdateScope ++;
/* $end */
}

void _test_SubscriberTest_onUpdateSelf(
    corto_subscriberEvent *e)
{
/* $begin(test/SubscriberTest/onUpdateSelf) */
    test_SubscriberTest this = e->instance;
    test_SubscriberTest_setMembers(e);
    this->countUpdateSelf ++;
/* $end */
}

void _test_SubscriberTest_onUpdateTree(
    corto_subscriberEvent *e)
{
/* $begin(test/SubscriberTest/onUpdateTree) */
    test_SubscriberTest this = e->instance;
    test_SubscriberTest_setMembers(e);
    this->countUpdateTree ++;
/* $end */
}
