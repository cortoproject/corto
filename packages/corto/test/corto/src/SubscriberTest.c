/* $CORTO_GENERATED
 *
 * SubscriberTest.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

/* $header() */
void test_SubscriberTest_setMembers(
    test_SubscriberTest this,
    corto_eventMask event,
    corto_result *object,
    corto_subscriber subscriber)
{

    corto_setstr(&this->lastId, object->id);
    corto_setstr(&this->lastParent, object->parent);
    this->lastMask |= event;
    corto_subscriberListAppend(this->triggered, subscriber);
}
/* $end */

corto_void _test_SubscriberTest_clear(
    test_SubscriberTest this)
{
/* $begin(test/SubscriberTest/clear) */

    corto_subscriberListClear(this->triggered);
    this->lastMask = 0;

/* $end */
}

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
    test_SubscriberTest this,
    corto_eventMask event,
    corto_result *object,
    corto_subscriber subscriber)
{
/* $begin(test/SubscriberTest/onDeclare) */
    test_SubscriberTest_setMembers(this, event, object, subscriber);
    this->countDeclare ++;
/* $end */
}

void _test_SubscriberTest_onDeclareScope(
    test_SubscriberTest this,
    corto_eventMask event,
    corto_result *object,
    corto_subscriber subscriber)
{
/* $begin(test/SubscriberTest/onDeclareScope) */
    test_SubscriberTest_setMembers(this, event, object, subscriber);
    this->countDeclareScope ++;
/* $end */
}

void _test_SubscriberTest_onDeclareSelf(
    test_SubscriberTest this,
    corto_eventMask event,
    corto_result *object,
    corto_subscriber subscriber)
{
/* $begin(test/SubscriberTest/onDeclareSelf) */
    test_SubscriberTest_setMembers(this, event, object, subscriber);
    this->countDeclareSelf ++;
/* $end */
}

void _test_SubscriberTest_onDeclareTree(
    test_SubscriberTest this,
    corto_eventMask event,
    corto_result *object,
    corto_subscriber subscriber)
{
/* $begin(test/SubscriberTest/onDeclareTree) */
    test_SubscriberTest_setMembers(this, event, object, subscriber);
    this->countDeclareTree ++;
/* $end */
}

void _test_SubscriberTest_onDefine(
    test_SubscriberTest this,
    corto_eventMask event,
    corto_result *object,
    corto_subscriber subscriber)
{
/* $begin(test/SubscriberTest/onDefine) */
    test_SubscriberTest_setMembers(this, event, object, subscriber);
    this->countDefine ++;
/* $end */
}

void _test_SubscriberTest_onDefineScope(
    test_SubscriberTest this,
    corto_eventMask event,
    corto_result *object,
    corto_subscriber subscriber)
{
/* $begin(test/SubscriberTest/onDefineScope) */
    test_SubscriberTest_setMembers(this, event, object, subscriber);
    this->countDefineScope ++;
/* $end */
}

void _test_SubscriberTest_onDefineSelf(
    test_SubscriberTest this,
    corto_eventMask event,
    corto_result *object,
    corto_subscriber subscriber)
{
/* $begin(test/SubscriberTest/onDefineSelf) */
    test_SubscriberTest_setMembers(this, event, object, subscriber);
    this->countDefineSelf ++;
/* $end */
}

void _test_SubscriberTest_onDefineTree(
    test_SubscriberTest this,
    corto_eventMask event,
    corto_result *object,
    corto_subscriber subscriber)
{
/* $begin(test/SubscriberTest/onDefineTree) */
    test_SubscriberTest_setMembers(this, event, object, subscriber);
    this->countDefineTree ++;
/* $end */
}

void _test_SubscriberTest_onUpdate(
    test_SubscriberTest this,
    corto_eventMask event,
    corto_result *object,
    corto_subscriber subscriber)
{
/* $begin(test/SubscriberTest/onUpdate) */
    test_SubscriberTest_setMembers(this, event, object, subscriber);
    this->countUpdate ++;
/* $end */
}

void _test_SubscriberTest_onUpdateScope(
    test_SubscriberTest this,
    corto_eventMask event,
    corto_result *object,
    corto_subscriber subscriber)
{
/* $begin(test/SubscriberTest/onUpdateScope) */
    test_SubscriberTest_setMembers(this, event, object, subscriber);
    this->countUpdateScope ++;
/* $end */
}

void _test_SubscriberTest_onUpdateSelf(
    test_SubscriberTest this,
    corto_eventMask event,
    corto_result *object,
    corto_subscriber subscriber)
{
/* $begin(test/SubscriberTest/onUpdateSelf) */
    test_SubscriberTest_setMembers(this, event, object, subscriber);
    this->countUpdateSelf ++;
/* $end */
}

void _test_SubscriberTest_onUpdateTree(
    test_SubscriberTest this,
    corto_eventMask event,
    corto_result *object,
    corto_subscriber subscriber)
{
/* $begin(test/SubscriberTest/onUpdateTree) */
    test_SubscriberTest_setMembers(this, event, object, subscriber);
    this->countUpdateTree ++;
/* $end */
}
