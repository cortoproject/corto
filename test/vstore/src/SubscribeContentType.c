/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

#define LOOKUP_ASSERT(p, i, t)\
    corto(CORTO_FORCE_TYPE|CORTO_ASSERT_SUCCESS, {.parent = p, .id = i, .type = t})

void test_SubscribeContentType_setup(
    test_SubscribeContentType this)
{
    /* Create 'json' scope for JSON mount */
    corto_object json_o = corto_void__create(root_o, "json");

    /* Create 'string' scope for Corto string mount */
    corto_object str_o = corto_void__create(root_o, "str");

    /* Create 'obj' scope with Corto objects */
    corto_object obj_o = corto_void__create(root_o, "obj");

    /* Attach json mount to json scope */
    test_JsonReplicator__create(NULL, NULL, json_o, "/test/Point");

    /* Attach str mount to str scope */
    test_StringReplicator__create(NULL, NULL, str_o);

    /* Create three objects in 'obj' scope */
    test_Point__create(obj_o, "a", 10, 20);
    test_Point__create(obj_o, "b", 30, 40);
    test_Point__create(obj_o, "c", 50, 60);

}


void binary(corto_subscriber_event *e) {
    test_SubscribeContentType this = e->instance;
    test_Point *p;
    this->eventsReceived ++;
    switch(this->eventsReceived) {
    case 1:
        test_assertstr(e->data.id, "a");
        p = (test_Point*)e->data.value;
        test_assertint(p->x, 10);
        test_assertint(p->y, 20);
        break;
    case 2:
        test_assertstr(e->data.id, "b");
        p = (test_Point*)e->data.value;
        test_assertint(p->x, 30);
        test_assertint(p->y, 40);
        break;
    case 3:
        test_assertstr(e->data.id, "c");
        p = (test_Point*)e->data.value;
        test_assertint(p->x, 50);
        test_assertint(p->y, 60);
        break;
    case 4:
        test_assertstr(e->data.id, "c");
        p = (test_Point*)e->data.value;
        test_assertint(p->x, 70);
        test_assertint(p->y, 80);
        break;
    }
}

void test_SubscribeContentType_tc_subscribeBinaryFromJson(
    test_SubscribeContentType this)
{
    corto_subscriber s = corto_subscribe("json/*")
        .instance(this)
        .contentType("binary/corto")
        .callback(binary);

    test_assert(s != 0);
    test_assertint(this->eventsReceived, 3);

    test_assert(corto_publish(CORTO_UPDATE, "json/c", "/test/Point", "text/json", "{\"x\":70,\"y\":80}") == 0);

    test_assertint(this->eventsReceived, 4);

    test_assert(corto_delete(s) == 0);

}

void test_SubscribeContentType_tc_subscribeBinaryFromJsonDispatch(
    test_SubscribeContentType this)
{
    test_FooDispatcher dispatcher = test_FooDispatcher__create(NULL, NULL);

    corto_subscriber s = corto_subscribe("json/*")
        .instance(this)
        .contentType("binary/corto")
        .dispatcher(dispatcher)
        .callback(binary);

    test_assert(s != 0);
    test_assertint(this->eventsReceived, 3);

    test_assert(corto_publish(CORTO_UPDATE, "json/c", "/test/Point", "text/json", "{\"x\":70,\"y\":80}") == 0);

    test_assertint(this->eventsReceived, 4);

    test_assert(corto_delete(s) == 0);

}

void test_SubscribeContentType_tc_subscribeBinaryFromObjects(
    test_SubscribeContentType this)
{
    corto_subscriber s = corto_subscribe("obj/*")
        .instance(this)
        .contentType("binary/corto")
        .callback(binary);

    test_assert(s != 0);
    test_assertint(this->eventsReceived, 3);

    test_Point *p = LOOKUP_ASSERT(NULL, "obj/c", test_Point_o);
    test_assert(test_Point__update(p, 70, 80) == 0);
    test_assertint(this->eventsReceived, 4);

    test_assert(corto_delete(s) == 0);

}

void test_SubscribeContentType_tc_subscribeBinaryFromObjectsDispatch(
    test_SubscribeContentType this)
{
    test_FooDispatcher dispatcher = test_FooDispatcher__create(NULL, NULL);

    corto_subscriber s = corto_subscribe("obj/*")
        .instance(this)
        .contentType("binary/corto")
        .dispatcher(dispatcher)
        .callback(binary);

    test_assert(s != 0);
    test_assertint(this->eventsReceived, 3);

    test_Point *p = LOOKUP_ASSERT(NULL, "obj/c", test_Point_o);
    test_assert(test_Point__update(p, 70, 80) == 0);
    test_assertint(this->eventsReceived, 4);

    test_assert(corto_delete(s) == 0);

}

void test_SubscribeContentType_tc_subscribeBinaryFromString(
    test_SubscribeContentType this)
{
    corto_subscriber s = corto_subscribe("str/*")
        .instance(this)
        .contentType("binary/corto")
        .callback(binary);

    test_assert(s != 0);
    test_assertint(this->eventsReceived, 3);

    test_assert(corto_publish(CORTO_UPDATE, "str/c", "/test/Point", "text/corto", "{70,80}") == 0);
    test_assertint(this->eventsReceived, 4);

    test_assert(corto_delete(s) == 0);

}

void test_SubscribeContentType_tc_subscribeBinaryFromStringDispatch(
    test_SubscribeContentType this)
{
    test_FooDispatcher dispatcher = test_FooDispatcher__create(NULL, NULL);

    corto_subscriber s = corto_subscribe("str/*")
        .instance(this)
        .contentType("binary/corto")
        .dispatcher(dispatcher)
        .callback(binary);

    test_assert(s != 0);
    test_assertint(this->eventsReceived, 3);

    test_assert(corto_publish(CORTO_UPDATE, "str/c", "/test/Point", "text/corto", "{70,80}") == 0);
    test_assertint(this->eventsReceived, 4);

    test_assert(corto_delete(s) == 0);

}


void json(corto_subscriber_event *e) {
    test_SubscribeContentType this = e->instance;
    char *json;
    this->eventsReceived ++;
    switch(this->eventsReceived) {
    case 1:
        test_assertstr(e->data.id, "a");
        json = corto_result_getText(&e->data);
        test_assertstr(json, "{\"x\":10,\"y\":20}");
        break;
    case 2:
        test_assertstr(e->data.id, "b");
        json = corto_result_getText(&e->data);
        test_assertstr(json, "{\"x\":30,\"y\":40}");
        break;
    case 3:
        test_assertstr(e->data.id, "c");
        json = corto_result_getText(&e->data);
        test_assertstr(json, "{\"x\":50,\"y\":60}");
        break;
    case 4:
        test_assertstr(e->data.id, "c");
        json = corto_result_getText(&e->data);
        test_assertstr(json, "{\"x\":70,\"y\":80}");
        break;
    }
}

void test_SubscribeContentType_tc_subscribeJsonFromJson(
    test_SubscribeContentType this)
{
    corto_subscriber s = corto_subscribe("json/*")
        .instance(this)
        .contentType("text/json")
        .callback(json);

    test_assert(s != 0);
    test_assertint(this->eventsReceived, 3);

    test_assert(corto_publish(CORTO_UPDATE, "json/c", "/test/Point", "text/json", "{\"x\":70,\"y\":80}") == 0);
    test_assertint(this->eventsReceived, 4);

    test_assert(corto_delete(s) == 0);

}

void test_SubscribeContentType_tc_subscribeJsonFromJsonDispatch(
    test_SubscribeContentType this)
{
    test_FooDispatcher dispatcher = test_FooDispatcher__create(NULL, NULL);

    corto_subscriber s = corto_subscribe("json/*")
        .instance(this)
        .contentType("text/json")
        .dispatcher(dispatcher)
        .callback(json);

    test_assert(s != 0);
    test_assertint(this->eventsReceived, 3);

    test_assert(corto_publish(CORTO_UPDATE, "json/c", "/test/Point", "text/json", "{\"x\":70,\"y\":80}") == 0);
    test_assertint(this->eventsReceived, 4);

    test_assert(corto_delete(s) == 0);

}

void test_SubscribeContentType_tc_subscribeJsonFromObjects(
    test_SubscribeContentType this)
{
    corto_subscriber s = corto_subscribe("obj/*")
        .instance(this)
        .contentType("text/json")
        .callback(json);

    test_assert(s != 0);
    test_assertint(this->eventsReceived, 3);

    test_Point *p = LOOKUP_ASSERT(NULL, "obj/c", test_Point_o);
    test_assert(test_Point__update(p, 70, 80) == 0);
    test_assertint(this->eventsReceived, 4);

    test_assert(corto_delete(s) == 0);

}

void test_SubscribeContentType_tc_subscribeJsonFromObjectsDispatch(
    test_SubscribeContentType this)
{
    test_FooDispatcher dispatcher = test_FooDispatcher__create(NULL, NULL);

    corto_subscriber s = corto_subscribe("obj/*")
        .instance(this)
        .contentType("text/json")
        .dispatcher(dispatcher)
        .callback(json);

    test_assert(s != 0);
    test_assertint(this->eventsReceived, 3);

    test_Point *p = LOOKUP_ASSERT(NULL, "obj/c", test_Point_o);
    test_assert(test_Point__update(p, 70, 80) == 0);
    test_assertint(this->eventsReceived, 4);

    test_assert(corto_delete(s) == 0);

}

void test_SubscribeContentType_tc_subscribeJsonFromString(
    test_SubscribeContentType this)
{
    corto_subscriber s = corto_subscribe("str/*")
        .instance(this)
        .contentType("text/json")
        .callback(json);

    test_assert(s != 0);
    test_assertint(this->eventsReceived, 3);

    test_assert(corto_publish(CORTO_UPDATE, "str/c", "/test/Point", "text/corto", "{70,80}") == 0);
    test_assertint(this->eventsReceived, 4);

    test_assert(corto_delete(s) == 0);

}

void test_SubscribeContentType_tc_subscribeJsonFromStringDispatch(
    test_SubscribeContentType this)
{
    test_FooDispatcher dispatcher = test_FooDispatcher__create(NULL, NULL);

    corto_subscriber s = corto_subscribe("str/*")
        .instance(this)
        .contentType("text/json")
        .dispatcher(dispatcher)
        .callback(json);

    test_assert(s != 0);
    test_assertint(this->eventsReceived, 3);

    test_assert(corto_publish(CORTO_UPDATE, "str/c", "/test/Point", "text/corto", "{70,80}") == 0);
    test_assertint(this->eventsReceived, 4);

    test_assert(corto_delete(s) == 0);

}


void string(corto_subscriber_event *e) {
    test_SubscribeContentType this = e->instance;
    char *json;
    this->eventsReceived ++;
    switch(this->eventsReceived) {
    case 1:
        test_assertstr(e->data.id, "a");
        json = corto_result_getText(&e->data);
        test_assertstr(json, "{10,20}");
        break;
    case 2:
        test_assertstr(e->data.id, "b");
        json = corto_result_getText(&e->data);
        test_assertstr(json, "{30,40}");
        break;
    case 3:
        test_assertstr(e->data.id, "c");
        json = corto_result_getText(&e->data);
        test_assertstr(json, "{50,60}");
        break;
    case 4:
        test_assertstr(e->data.id, "c");
        json = corto_result_getText(&e->data);
        test_assertstr(json, "{70,80}");
        break;
    }
}

void test_SubscribeContentType_tc_subscribeStringFromJson(
    test_SubscribeContentType this)
{
    corto_subscriber s = corto_subscribe("json/*")
        .instance(this)
        .contentType("text/corto")
        .callback(string);

    test_assert(s != 0);
    test_assertint(this->eventsReceived, 3);

    test_assert(corto_publish(CORTO_UPDATE, "json/c", "/test/Point", "text/json", "{\"x\":70,\"y\":80}") == 0);
    test_assertint(this->eventsReceived, 4);

    test_assert(corto_delete(s) == 0);

}

void test_SubscribeContentType_tc_subscribeStringFromJsonDispatch(
    test_SubscribeContentType this)
{
    test_FooDispatcher dispatcher = test_FooDispatcher__create(NULL, NULL);

    corto_subscriber s = corto_subscribe("json/*")
        .instance(this)
        .contentType("text/corto")
        .dispatcher(dispatcher)
        .callback(string);

    test_assert(s != 0);
    test_assertint(this->eventsReceived, 3);

    test_assert(corto_publish(CORTO_UPDATE, "json/c", "/test/Point", "text/json", "{\"x\":70,\"y\":80}") == 0);
    test_assertint(this->eventsReceived, 4);

    test_assert(corto_delete(s) == 0);

}

void test_SubscribeContentType_tc_subscribeStringFromObjects(
    test_SubscribeContentType this)
{
    corto_subscriber s = corto_subscribe("obj/*")
        .instance(this)
        .contentType("text/corto")
        .callback(string);

    test_assert(s != 0);
    test_assertint(this->eventsReceived, 3);

    test_Point *p = LOOKUP_ASSERT(NULL, "obj/c", test_Point_o);
    test_assert(test_Point__update(p, 70, 80) == 0);
    test_assertint(this->eventsReceived, 4);

    test_assert(corto_delete(s) == 0);

}

void test_SubscribeContentType_tc_subscribeStringFromObjectsDispatch(
    test_SubscribeContentType this)
{
    test_FooDispatcher dispatcher = test_FooDispatcher__create(NULL, NULL);

    corto_subscriber s = corto_subscribe("obj/*")
        .instance(this)
        .contentType("text/corto")
        .dispatcher(dispatcher)
        .callback(string);

    test_assert(s != 0);
    test_assertint(this->eventsReceived, 3);

    test_Point *p = LOOKUP_ASSERT(NULL, "obj/c", test_Point_o);
    test_assert(test_Point__update(p, 70, 80) == 0);
    test_assertint(this->eventsReceived, 4);

    test_assert(corto_delete(s) == 0);

}

void test_SubscribeContentType_tc_subscribeStringFromString(
    test_SubscribeContentType this)
{
    corto_subscriber s = corto_subscribe("str/*")
        .instance(this)
        .contentType("text/corto")
        .callback(string);

    test_assert(s != 0);
    test_assertint(this->eventsReceived, 3);

    test_assert(corto_publish(CORTO_UPDATE, "str/c", "/test/Point", "text/corto", "{70,80}") == 0);
    test_assertint(this->eventsReceived, 4);

    test_assert(corto_delete(s) == 0);

}

void test_SubscribeContentType_tc_subscribeStringFromStringDispatch(
    test_SubscribeContentType this)
{
    test_FooDispatcher dispatcher = test_FooDispatcher__create(NULL, NULL);

    corto_subscriber s = corto_subscribe("str/*")
        .instance(this)
        .contentType("text/corto")
        .dispatcher(dispatcher)
        .callback(string);

    test_assert(s != 0);
    test_assertint(this->eventsReceived, 3);

    test_assert(corto_publish(CORTO_UPDATE, "str/c", "/test/Point", "text/corto", "{70,80}") == 0);
    test_assertint(this->eventsReceived, 4);

    test_assert(corto_delete(s) == 0);

}
