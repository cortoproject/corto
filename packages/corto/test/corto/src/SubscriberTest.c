/* This is a managed file. Do not delete this comment. */

#include <include/test.h>


void test_SubscriberTest_setMembers(corto_subscriberEvent *e)
{
    test_SubscriberTest this = e->instance;
    corto_ptr_setstr(&this->lastId, e->data.id);
    corto_ptr_setstr(&this->lastParent,  e->data.parent);
    this->lastMask |= e->event;
    corto_subscriberListAppend(this->triggered, corto_subscriber(e->subscriber));
}

void test_SubscriberTest_clear(
    test_SubscriberTest this)
{

    corto_subscriberListClear(this->triggered);
    this->lastMask = 0;

}

int16_t test_SubscriberTest_construct(
    test_SubscriberTest this)
{
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
}

void test_SubscriberTest_destruct(
    test_SubscriberTest this)
{
    corto_int16 ret = 0;

    ret = corto_subscriber_unsubscribe(test_SubscriberTest_onAll_o, this);
    test_assert(ret == 0);

    ret = corto_subscriber_unsubscribe(test_SubscriberTest_onSelf_o, this);
    test_assert(ret == 0);

    ret = corto_subscriber_unsubscribe(test_SubscriberTest_onScope_o, this);
    test_assert(ret == 0);

    ret = corto_subscriber_unsubscribe(test_SubscriberTest_onTree_o, this);
    test_assert(ret == 0);

}

void test_SubscriberTest_onAll(
    corto_subscriberEvent *e)
{

    test_SubscriberTest this = e->instance;
    test_SubscriberTest_setMembers(e);
    if (e->event & CORTO_DECLARE) {
        this->countDeclare ++;
    }
    if (e->event & CORTO_DEFINE) {
        this->countDefine ++;
    }
    if (e->event & CORTO_UPDATE) {
        this->countUpdate ++;
    }

}

void test_SubscriberTest_onScope(
    corto_subscriberEvent *e)
{

    test_SubscriberTest this = e->instance;
    test_SubscriberTest_setMembers(e);
    if (e->event & CORTO_DECLARE) {
        this->countDeclareScope ++;
    }
    if (e->event & CORTO_DEFINE) {
        this->countDefineScope ++;
    }
    if (e->event & CORTO_UPDATE) {
        this->countUpdateScope ++;
    }

}

void test_SubscriberTest_onSelf(
    corto_subscriberEvent *e)
{

    test_SubscriberTest this = e->instance;
    test_SubscriberTest_setMembers(e);
    if (e->event & CORTO_DECLARE) {
        this->countDeclareSelf ++;
    }
    if (e->event & CORTO_DEFINE) {
        this->countDefineSelf ++;
    }
    if (e->event & CORTO_UPDATE) {
        this->countUpdateSelf ++;
    }

}

void test_SubscriberTest_onTree(
    corto_subscriberEvent *e)
{

    test_SubscriberTest this = e->instance;
    test_SubscriberTest_setMembers(e);
    if (e->event & CORTO_DECLARE) {
        this->countDeclareTree ++;
    }
    if (e->event & CORTO_DEFINE) {
        this->countDefineTree ++;
    }
    if (e->event & CORTO_UPDATE) {
        this->countUpdateTree ++;
    }

}

