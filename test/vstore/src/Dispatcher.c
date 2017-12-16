/* This is a managed file. Do not delete this comment. */

#include <include/test.h>
void observerCallback(corto_observerEvent *event) {
    test_Dispatcher instance = event->instance;
    instance->observerPosted ++;
}

void test_Dispatcher_tc_observerDispatcher(
    test_Dispatcher this)
{
    corto_object obj = corto_createChild(root_o, "data/obj", corto_void_o);
    corto_dispatcher d = test_FooDispatcherCreate();
    corto_observer o = corto_observe(CORTO_UPDATE, obj)
        .instance(this)
        .dispatcher(d)
        .callback(observerCallback);
    test_assert(o != NULL);

    test_assert(corto_update(obj) == 0);
    test_assertint(this->observerPosted, 1);

    test_assert(corto_delete(o) == 0);
    test_assert(corto_delete(d) == 0);
    test_assert(corto_delete(obj) == 0);
}

void test_Dispatcher_tc_observerDispatcherMulti(
    test_Dispatcher this)
{
    corto_object obj = corto_createChild(root_o, "data/obj", corto_void_o);
    corto_dispatcher d = test_FooDispatcherCreate();
    corto_observer o1 = corto_observe(CORTO_UPDATE, obj)
        .instance(this)
        .dispatcher(d)
        .callback(observerCallback);
    test_assert(o1 != NULL);
    corto_observer o2 = corto_observe(CORTO_UPDATE, obj)
        .instance(this)
        .dispatcher(d)
        .callback(observerCallback);
    test_assert(o2 != NULL);

    test_assert(corto_update(obj) == 0);
    test_assertint(this->observerPosted, 2);

    test_assert(corto_delete(o1) == 0);
    test_assert(corto_delete(o2) == 0);
    test_assert(corto_delete(d) == 0);
    test_assert(corto_delete(obj) == 0);
}

void subscriberCallback(corto_subscriberEvent *event) {
    test_Dispatcher instance = event->instance;
    if (event->event == CORTO_UPDATE) {
        instance->subscriberPosted ++;
    }
}

void test_Dispatcher_tc_subscriberDispatcher(
    test_Dispatcher this)
{
    corto_object obj = corto_createChild(root_o, "data/obj", corto_void_o);
    corto_dispatcher d = test_FooDispatcherCreate();
    corto_subscriber s = corto_subscribe("data/obj")
        .instance(this)
        .dispatcher(d)
        .callback(subscriberCallback);
    test_assert(s != NULL);

    test_assert(corto_update(obj) == 0);
    test_assertint(this->subscriberPosted, 1);

    test_assert(corto_delete(s) == 0);
    test_assert(corto_delete(d) == 0);
    test_assert(corto_delete(obj) == 0);
}

void test_Dispatcher_tc_subscriberDispatcherMulti(
    test_Dispatcher this)
{
    corto_object obj = corto_createChild(root_o, "data/obj", corto_void_o);
    corto_dispatcher d = test_FooDispatcherCreate();
    corto_subscriber s1 = corto_subscribe("data/obj")
        .instance(this)
        .dispatcher(d)
        .callback(subscriberCallback);
    test_assert(s1 != NULL);
    corto_subscriber s2 = corto_subscribe("data/obj")
        .instance(this)
        .dispatcher(d)
        .callback(subscriberCallback);
    test_assert(s2 != NULL);

    test_assert(corto_update(obj) == 0);
    test_assertint(this->subscriberPosted, 2);

    test_assert(corto_delete(s1) == 0);
    test_assert(corto_delete(s2) == 0);
    test_assert(corto_delete(d) == 0);
    test_assert(corto_delete(obj) == 0);
}

void test_Dispatcher_tc_observerSubscriberDispatcher(
    test_Dispatcher this)
{
    corto_object obj = corto_createChild(root_o, "data/obj", corto_void_o);
    corto_dispatcher d = test_FooDispatcherCreate();
    corto_subscriber s = corto_subscribe("data/obj")
        .instance(this)
        .dispatcher(d)
        .callback(subscriberCallback);
    test_assert(s != NULL);
    corto_observer o = corto_observe(CORTO_UPDATE, obj)
        .instance(this)
        .dispatcher(d)
        .callback(observerCallback);
    test_assert(o != NULL);

    test_assert(corto_update(obj) == 0);

    test_assertint(this->observerPosted, 1);
    test_assertint(this->subscriberPosted, 1);

    test_assert(corto_delete(s) == 0);
    test_assert(corto_delete(o) == 0);
    test_assert(corto_delete(d) == 0);
    test_assert(corto_delete(obj) == 0);
}
