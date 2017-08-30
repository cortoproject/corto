/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_MountSubscription_tc_subscribeForMountWithTypeFilter(
    test_MountSubscription this)
{
    corto_object mountRoot = corto_createChild(root_o, "mountRoot", corto_void_o);
    test_assert(mountRoot != NULL);

    corto_object obj1 = corto_createChild(mountRoot, "obj1", corto_int32_o);
    test_assert(obj1 != NULL);

    corto_object obj2 = corto_createChild(mountRoot, "obj2", corto_float32_o);
    test_assert(obj2 != NULL);

    /* Create a mount with a filter on int32 */
    test_AutoResumeSinkMount m =
      test_AutoResumeSinkMountCreate(mountRoot, "int32", NULL);
    test_assert(m != NULL);

    /* Subscribe for scope in mountRoot: ok */
    corto_subscriber s1 = corto_subscribe("*").from("/mountRoot")
      .callback(NULL);
    test_assert(s1 != NULL);
    test_assertint(corto_ll_size(m->subscribes), 1);
    test_assertint(corto_ll_size(m->unsubscribes), 0);

    /* Subscribe for scope in obj1: ok */
    corto_subscriber s2 = corto_subscribe("obj1/*").from("/mountRoot")
      .callback(NULL);
    test_assert(s2 != NULL);
    test_assertint(corto_ll_size(m->subscribes), 2);
    test_assertint(corto_ll_size(m->unsubscribes), 0);

    /* Subscribe for scope in obj2: should not trigger new subscription */
    corto_subscriber s3 = corto_subscribe("obj2/*").from("/mountRoot")
      .callback(NULL);
    test_assert(s3 != NULL);
    test_assertint(corto_ll_size(m->subscribes), 2);
    test_assertint(corto_ll_size(m->unsubscribes), 0);

    test_assert(corto_delete(s1) == 0);
    test_assertint(corto_ll_size(m->subscribes), 2);
    test_assertint(corto_ll_size(m->unsubscribes), 1);

    test_assert(corto_delete(s2) == 0);
    test_assertint(corto_ll_size(m->subscribes), 2);
    test_assertint(corto_ll_size(m->unsubscribes), 2);

    test_assert(corto_delete(s3) == 0);
    test_assertint(corto_ll_size(m->subscribes), 2);
    test_assertint(corto_ll_size(m->unsubscribes), 2);

    test_assert(corto_delete(m) == 0);
    test_assert(corto_delete(mountRoot) == 0);

}

void test_MountSubscription_tc_subscribeNestedForMountWithTypeFilter(
    test_MountSubscription this)
{
    corto_object mountRoot = corto_createChild(root_o, "mountRoot", corto_void_o);
    test_assert(mountRoot != NULL);

    corto_object obj1 = corto_createChild(mountRoot, "obj1", corto_int32_o);
    test_assert(obj1 != NULL);

    corto_object obj2 = corto_createChild(obj1, "obj2", corto_float32_o);
    test_assert(obj2 != NULL);

    corto_object obj3 = corto_createChild(obj2, "obj3", corto_int32_o);
    test_assert(obj3 != NULL);

    corto_object obj4 = corto_createChild(obj3, "obj4", corto_int32_o);
    test_assert(obj4 != NULL);

    /* Create a mount with a filter on int32 */
    test_AutoResumeSinkMount m =
      test_AutoResumeSinkMountCreate(mountRoot, "int32", NULL);
    test_assert(m != NULL);

    /* Subscribe for nested scope in mountRoot: ok */
    corto_subscriber s1 = corto_subscribe("*").from("/mountRoot")
      .callback(NULL);
    test_assert(s1 != NULL);
    test_assertint(corto_ll_size(m->subscribes), 1);
    test_assertint(corto_ll_size(m->unsubscribes), 0);

    /* Subscribe for scope in obj1: ok */
    corto_subscriber s2 = corto_subscribe("*").from("/mountRoot/obj1")
      .callback(NULL);
    test_assert(s2 != NULL);
    test_assertint(corto_ll_size(m->subscribes), 2);
    test_assertint(corto_ll_size(m->unsubscribes), 0);

    /* Subscribe for scope in obj2: should not trigger new subscription */
    corto_subscriber s3 = corto_subscribe("*").from("/mountRoot/obj1/obj2")
      .callback(NULL);
    test_assert(s3 != NULL);
    test_assertint(corto_ll_size(m->subscribes), 2);
    test_assertint(corto_ll_size(m->unsubscribes), 0);

    /* Subscribe for scope in obj3: should not trigger new subscription */
    corto_subscriber s4 = corto_subscribe("*").from("/mountRoot/obj1/obj2/obj3")
      .callback(NULL);
    test_assert(s4 != NULL);
    test_assertint(corto_ll_size(m->subscribes), 2);
    test_assertint(corto_ll_size(m->unsubscribes), 0);

    /* Subscribe for scope in obj4: should not trigger new subscription */
    corto_subscriber s5 = corto_subscribe("*").from("/mountRoot/obj1/obj2/obj3/obj4")
      .callback(NULL);
    test_assert(s5 != NULL);
    test_assertint(corto_ll_size(m->subscribes), 2);
    test_assertint(corto_ll_size(m->unsubscribes), 0);

    test_assert(corto_delete(s1) == 0);
    test_assertint(corto_ll_size(m->subscribes), 2);
    test_assertint(corto_ll_size(m->unsubscribes), 1);

    test_assert(corto_delete(s2) == 0);
    test_assertint(corto_ll_size(m->subscribes), 2);
    test_assertint(corto_ll_size(m->unsubscribes), 2);

    test_assert(corto_delete(s3) == 0);
    test_assertint(corto_ll_size(m->subscribes), 2);
    test_assertint(corto_ll_size(m->unsubscribes), 2);

    test_assert(corto_delete(s4) == 0);
    test_assertint(corto_ll_size(m->subscribes), 2);
    test_assertint(corto_ll_size(m->unsubscribes), 2);

    test_assert(corto_delete(s5) == 0);
    test_assertint(corto_ll_size(m->subscribes), 2);
    test_assertint(corto_ll_size(m->unsubscribes), 2);

    test_assert(corto_delete(m) == 0);
    test_assert(corto_delete(mountRoot) == 0);

}

void test_MountSubscription_tc_subscribeOnMountWithFromNull(
    test_MountSubscription this)
{

    /* Create default mount with 'from' set to NULL */
    corto_object m = corto_create(corto_mount_o);
    test_assert(m != NULL);

    /* Create subscriber on root */
    corto_subscriber s = corto_subscribe("*").callback(NULL);
    test_assert(s != NULL);

    /* test didn't crash, yay */

    test_assert(corto_delete(s) == 0);
    test_assert(corto_delete(m) == 0);

}

void test_MountSubscription_tc_subscribeSameIdDifferentCase(
    test_MountSubscription this)
{
    corto_object mountRoot = corto_createChild(root_o, "mountRoot", corto_void_o);
    test_assert(mountRoot != NULL);

    test_AutoResumeSinkMount m =
      test_AutoResumeSinkMountCreate(mountRoot, NULL, NULL);
    test_assert(m != NULL);

    corto_subscriber s1 = corto_subscribe("foo").from("/mountRoot")
      .callback(NULL);
    test_assert(s1 != NULL);
    test_assertint(corto_ll_size(m->subscribes), 1);
    test_assertint(corto_ll_size(m->unsubscribes), 0);

    corto_subscriber s2 = corto_subscribe("Foo").from("/mountRoot")
      .callback(NULL);
    test_assert(s2 != NULL);
    test_assertint(corto_ll_size(m->subscribes), 1);
    test_assertint(corto_ll_size(m->unsubscribes), 0);

    corto_query *r = corto_ll_get(m->subscribes, 0);
    test_assert(r != NULL);
    test_assertstr(r->from, ".");
    test_assertstr(r->select, "foo");

    test_assert(corto_delete(s1) == 0);
    test_assertint(corto_ll_size(m->subscribes), 1);
    test_assertint(corto_ll_size(m->unsubscribes), 0);

    test_assert(corto_delete(s2) == 0);
    test_assertint(corto_ll_size(m->subscribes), 1);
    test_assertint(corto_ll_size(m->unsubscribes), 1);

    r = corto_ll_get(m->unsubscribes, 0);
    test_assert(r != NULL);
    test_assertstr(r->from, ".");
    test_assertstr(r->select, "foo");

    test_assert(corto_delete(m) == 0);
    test_assert(corto_delete(mountRoot) == 0);

}

void test_MountSubscription_tc_subscribeScope(
    test_MountSubscription this)
{
    corto_object mountRoot = corto_createChild(root_o, "mountRoot", corto_void_o);
    test_assert(mountRoot != NULL);

    test_AutoResumeSinkMount m =
      test_AutoResumeSinkMountCreate(mountRoot, NULL, NULL);
    test_assert(m != NULL);

    corto_subscriber s = corto_subscribe("*").from("/mountRoot")
      .callback(NULL);
    test_assert(s != NULL);
    test_assertint(corto_ll_size(m->subscribes), 1);
    test_assertint(corto_ll_size(m->unsubscribes), 0);

    corto_query *r = corto_ll_get(m->subscribes, 0);
    test_assert(r != NULL);
    test_assertstr(r->from, ".");
    test_assertstr(r->select, "*");

    test_assert(corto_delete(s) == 0);
    test_assertint(corto_ll_size(m->subscribes), 1);
    test_assertint(corto_ll_size(m->unsubscribes), 1);
    r = corto_ll_get(m->unsubscribes, 0);
    test_assert(r != NULL);
    test_assertstr(r->from, ".");

    test_assert(corto_delete(m) == 0);
    test_assert(corto_delete(mountRoot) == 0);

}

void test_MountSubscription_tc_subscribeScopeAlign(
    test_MountSubscription this)
{
    corto_object mountRoot = corto_createChild(root_o, "mountRoot", corto_void_o);
    test_assert(mountRoot != NULL);

    corto_subscriber s = corto_subscribe("*").from("/mountRoot")
      .callback(NULL);
    test_assert(s != NULL);

    test_AutoResumeSinkMount m =
      test_AutoResumeSinkMountCreate(mountRoot, NULL, NULL);
    test_assert(m != NULL);

    test_assertint(corto_ll_size(m->subscribes), 1);
    test_assertint(corto_ll_size(m->unsubscribes), 0);

    corto_query *r = corto_ll_get(m->subscribes, 0);
    test_assert(r != NULL);
    test_assertstr(r->from, ".");
    test_assertstr(r->select, "*");

    test_assert(corto_delete(s) == 0);
    test_assertint(corto_ll_size(m->subscribes), 1);
    test_assertint(corto_ll_size(m->unsubscribes), 1);
    r = corto_ll_get(m->unsubscribes, 0);
    test_assert(r != NULL);
    test_assertstr(r->from, ".");

    test_assert(corto_delete(m) == 0);
    test_assert(corto_delete(mountRoot) == 0);

}

void test_MountSubscription_tc_subscribeScopeTwice(
    test_MountSubscription this)
{
    corto_object mountRoot = corto_createChild(root_o, "mountRoot", corto_void_o);
    test_assert(mountRoot != NULL);

    test_AutoResumeSinkMount m =
      test_AutoResumeSinkMountCreate(mountRoot, NULL, NULL);
    test_assert(m != NULL);

    corto_subscriber s1 = corto_subscribe("*").from("/mountRoot")
      .callback(NULL);
    test_assert(s1 != NULL);
    test_assertint(corto_ll_size(m->subscribes), 1);
    test_assertint(corto_ll_size(m->unsubscribes), 0);

    corto_subscriber s2 = corto_subscribe("*").from("/mountRoot")
      .callback(NULL);
    test_assert(s2 != NULL);
    test_assertint(corto_ll_size(m->subscribes), 1);
    test_assertint(corto_ll_size(m->unsubscribes), 0);

    corto_query *r = corto_ll_get(m->subscribes, 0);
    test_assert(r != NULL);
    test_assertstr(r->from, ".");
    test_assertstr(r->select, "*");

    test_assert(corto_delete(s1) == 0);
    test_assertint(corto_ll_size(m->subscribes), 1);
    test_assertint(corto_ll_size(m->unsubscribes), 0);

    test_assert(corto_delete(s2) == 0);
    test_assertint(corto_ll_size(m->subscribes), 1);
    test_assertint(corto_ll_size(m->unsubscribes), 1);

    r = corto_ll_get(m->unsubscribes, 0);
    test_assert(r != NULL);
    test_assertstr(r->from, ".");

    test_assert(corto_delete(m) == 0);
    test_assert(corto_delete(mountRoot) == 0);

}

void test_MountSubscription_tc_subscribeScopeTwiceSameSubscriber(
    test_MountSubscription this)
{
    corto_object mountRoot = corto_createChild(root_o, "mountRoot", corto_void_o);
    test_assert(mountRoot != NULL);

    test_AutoResumeSinkMount m =
      test_AutoResumeSinkMountCreate(mountRoot, NULL, NULL);
    test_assert(m != NULL);

    corto_subscriber s = corto_subscribe("*").from("/mountRoot")
      .disabled()
      .callback(NULL);
    test_assert(s != NULL);
    test_assertint(corto_ll_size(m->subscribes), 0);
    test_assertint(corto_ll_size(m->unsubscribes), 0);

    corto_object instance1 = corto_create(corto_void_o);
    corto_subscriber_subscribe(s, instance1);
    test_assertint(corto_ll_size(m->subscribes), 1);
    test_assertint(corto_ll_size(m->unsubscribes), 0);

    corto_object instance2 = corto_create(corto_void_o);
    corto_subscriber_subscribe(s, instance2);
    test_assertint(corto_ll_size(m->subscribes), 1);
    test_assertint(corto_ll_size(m->unsubscribes), 0);

    corto_query *r = corto_ll_get(m->subscribes, 0);
    test_assert(r != NULL);
    test_assertstr(r->from, ".");
    test_assertstr(r->select, "*");

    test_assert(corto_delete(s) == 0);
    test_assertint(corto_ll_size(m->subscribes), 1);
    test_assertint(corto_ll_size(m->unsubscribes), 1);

    r = corto_ll_get(m->unsubscribes, 0);
    test_assert(r != NULL);
    test_assertstr(r->from, ".");

    test_assert(corto_delete(m) == 0);
    test_assert(corto_delete(mountRoot) == 0);

}

void test_MountSubscription_tc_subscribeSingle(
    test_MountSubscription this)
{
    corto_object mountRoot = corto_createChild(root_o, "mountRoot", corto_void_o);
    test_assert(mountRoot != NULL);

    test_AutoResumeSinkMount m =
      test_AutoResumeSinkMountCreate(mountRoot, NULL, NULL);
    test_assert(m != NULL);

    corto_subscriber s = corto_subscribe("foo").from("/mountRoot")
      .callback(NULL);
    test_assert(s != NULL);
    test_assertint(corto_ll_size(m->subscribes), 1);
    test_assertint(corto_ll_size(m->unsubscribes), 0);

    corto_query *r = corto_ll_get(m->subscribes, 0);
    test_assert(r != NULL);
    test_assertstr(r->from, ".");
    test_assertstr(r->select, "foo");

    test_assert(corto_delete(s) == 0);
    test_assertint(corto_ll_size(m->subscribes), 1);
    test_assertint(corto_ll_size(m->unsubscribes), 1);
    r = corto_ll_get(m->unsubscribes, 0);
    test_assert(r != NULL);
    test_assertstr(r->from, ".");

    test_assert(corto_delete(m) == 0);
    test_assert(corto_delete(mountRoot) == 0);

}

void test_MountSubscription_tc_subscribeSingleAlign(
    test_MountSubscription this)
{
    corto_object mountRoot = corto_createChild(root_o, "mountRoot", corto_void_o);
    test_assert(mountRoot != NULL);

    corto_subscriber s = corto_subscribe("foo").from("/mountRoot")
      .callback(NULL);
    test_assert(s != NULL);

    test_AutoResumeSinkMount m =
      test_AutoResumeSinkMountCreate(mountRoot, NULL, NULL);
    test_assert(m != NULL);

    test_assertint(corto_ll_size(m->subscribes), 1);
    test_assertint(corto_ll_size(m->unsubscribes), 0);

    corto_query *r = corto_ll_get(m->subscribes, 0);
    test_assert(r != NULL);
    test_assertstr(r->from, ".");
    test_assertstr(r->select, "foo");

    test_assert(corto_delete(s) == 0);
    test_assertint(corto_ll_size(m->subscribes), 1);
    test_assertint(corto_ll_size(m->unsubscribes), 1);
    r = corto_ll_get(m->unsubscribes, 0);
    test_assert(r != NULL);
    test_assertstr(r->from, ".");

    test_assert(corto_delete(m) == 0);
    test_assert(corto_delete(mountRoot) == 0);
}

void test_MountSubscription_tc_subscribeSingleTwice(
    test_MountSubscription this)
{
    corto_object mountRoot = corto_createChild(root_o, "mountRoot", corto_void_o);
    test_assert(mountRoot != NULL);

    test_AutoResumeSinkMount m =
      test_AutoResumeSinkMountCreate(mountRoot, NULL, NULL);
    test_assert(m != NULL);

    corto_subscriber s1 = corto_subscribe("foo").from("/mountRoot")
      .callback(NULL);
    test_assert(s1 != NULL);
    test_assertint(corto_ll_size(m->subscribes), 1);
    test_assertint(corto_ll_size(m->unsubscribes), 0);

    corto_subscriber s2 = corto_subscribe("foo").from("/mountRoot")
      .callback(NULL);
    test_assert(s2 != NULL);
    test_assertint(corto_ll_size(m->subscribes), 1);
    test_assertint(corto_ll_size(m->unsubscribes), 0);

    corto_query *r = corto_ll_get(m->subscribes, 0);
    test_assert(r != NULL);
    test_assertstr(r->from, ".");
    test_assertstr(r->select, "foo");

    test_assert(corto_delete(s1) == 0);
    test_assertint(corto_ll_size(m->subscribes), 1);
    test_assertint(corto_ll_size(m->unsubscribes), 0);

    test_assert(corto_delete(s2) == 0);
    test_assertint(corto_ll_size(m->subscribes), 1);
    test_assertint(corto_ll_size(m->unsubscribes), 1);

    r = corto_ll_get(m->unsubscribes, 0);
    test_assert(r != NULL);
    test_assertstr(r->from, ".");

    test_assert(corto_delete(m) == 0);
    test_assert(corto_delete(mountRoot) == 0);
}

void test_MountSubscription_tc_subscribeSingleTwiceSameSubscriber(
    test_MountSubscription this)
{
    corto_object mountRoot = corto_createChild(root_o, "mountRoot", corto_void_o);
    test_assert(mountRoot != NULL);

    test_AutoResumeSinkMount m =
      test_AutoResumeSinkMountCreate(mountRoot, NULL, NULL);
    test_assert(m != NULL);

    corto_subscriber s = corto_subscribe("foo").from("/mountRoot")
      .disabled()
      .callback(NULL);
    test_assert(s != NULL);
    test_assertint(corto_ll_size(m->subscribes), 0);
    test_assertint(corto_ll_size(m->unsubscribes), 0);

    corto_object instance1 = corto_create(corto_void_o);
    corto_object instance2 = corto_create(corto_void_o);
    corto_subscriber_subscribe(s, instance1);
    test_assertint(corto_ll_size(m->subscribes), 1);
    test_assertint(corto_ll_size(m->unsubscribes), 0);

    corto_subscriber_subscribe(s, instance2);
    test_assertint(corto_ll_size(m->subscribes), 1);
    test_assertint(corto_ll_size(m->unsubscribes), 0);

    corto_query *r = corto_ll_get(m->subscribes, 0);
    test_assert(r != NULL);
    test_assertstr(r->from, ".");
    test_assertstr(r->select, "foo");

    test_assert(corto_delete(s) == 0);
    test_assertint(corto_ll_size(m->subscribes), 1);
    test_assertint(corto_ll_size(m->unsubscribes), 1);

    r = corto_ll_get(m->unsubscribes, 0);
    test_assert(r != NULL);
    test_assertstr(r->from, ".");

    test_assert(corto_delete(m) == 0);
    test_assert(corto_delete(mountRoot) == 0);

}

void test_MountSubscription_tc_subscribeTree(
    test_MountSubscription this)
{
    corto_object mountRoot = corto_createChild(root_o, "mountRoot", corto_void_o);
    test_assert(mountRoot != NULL);

    test_AutoResumeSinkMount m =
      test_AutoResumeSinkMountCreate(mountRoot, NULL, NULL);
    test_assert(m != NULL);

    corto_subscriber s = corto_subscribe("//").from("/mountRoot")
      .callback(NULL);
    test_assert(s != NULL);
    test_assertint(corto_ll_size(m->subscribes), 13);
    test_assertint(corto_ll_size(m->unsubscribes), 0);

    corto_query *r = corto_ll_get(m->subscribes, 0);
    test_assert(r != NULL);
    test_assertstr(r->from, ".");
    test_assertstr(r->select, "*");

    r = corto_ll_get(m->subscribes, 1);
    test_assert(r != NULL);
    test_assertstr(r->from, "x");
    test_assertstr(r->select, "*");

    r = corto_ll_get(m->subscribes, 2);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/a");
    test_assertstr(r->select, "*");

    r = corto_ll_get(m->subscribes, 3);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/a/k");
    test_assertstr(r->select, "*");

    r = corto_ll_get(m->subscribes, 4);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/a/k/n");
    test_assertstr(r->select, "*");

    r = corto_ll_get(m->subscribes, 5);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/a/k/o");
    test_assertstr(r->select, "*");

    r = corto_ll_get(m->subscribes, 6);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/a/k/p");
    test_assertstr(r->select, "*");

    r = corto_ll_get(m->subscribes, 7);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/a/l");
    test_assertstr(r->select, "*");

    r = corto_ll_get(m->subscribes, 8);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/a/m");
    test_assertstr(r->select, "*");

    r = corto_ll_get(m->subscribes, 9);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/b");
    test_assertstr(r->select, "*");

    r = corto_ll_get(m->subscribes, 10);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/c");
    test_assertstr(r->select, "*");

    r = corto_ll_get(m->subscribes, 11);
    test_assert(r != NULL);
    test_assertstr(r->from, "y");
    test_assertstr(r->select, "*");

    r = corto_ll_get(m->subscribes, 12);
    test_assert(r != NULL);
    test_assertstr(r->from, "z");
    test_assertstr(r->select, "*");

    test_assert(corto_delete(s) == 0);
    test_assertint(corto_ll_size(m->subscribes), 13);
    test_assertint(corto_ll_size(m->unsubscribes), 13);

    r = corto_ll_get(m->unsubscribes, 0);
    test_assert(r != NULL);
    test_assertstr(r->from, ".");

    r = corto_ll_get(m->unsubscribes, 1);
    test_assert(r != NULL);
    test_assertstr(r->from, "x");

    r = corto_ll_get(m->unsubscribes, 2);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/a");

    r = corto_ll_get(m->unsubscribes, 3);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/a/k");

    r = corto_ll_get(m->unsubscribes, 4);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/a/k/n");

    r = corto_ll_get(m->unsubscribes, 5);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/a/k/o");

    r = corto_ll_get(m->unsubscribes, 6);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/a/k/p");

    r = corto_ll_get(m->unsubscribes, 7);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/a/l");

    r = corto_ll_get(m->unsubscribes, 8);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/a/m");

    r = corto_ll_get(m->unsubscribes, 9);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/b");

    r = corto_ll_get(m->unsubscribes, 10);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/c");

    r = corto_ll_get(m->unsubscribes, 11);
    test_assert(r != NULL);
    test_assertstr(r->from, "y");

    r = corto_ll_get(m->unsubscribes, 12);
    test_assert(r != NULL);
    test_assertstr(r->from, "z");

    test_assert(corto_delete(m) == 0);
    test_assert(corto_delete(mountRoot) == 0);

}

void test_MountSubscription_tc_subscribeTreeAlign(
    test_MountSubscription this)
{
    corto_object mountRoot = corto_createChild(root_o, "mountRoot", corto_void_o);
    test_assert(mountRoot != NULL);

    /* Create subscriber before mount */
    corto_subscriber s = corto_subscribe("//").from("/mountRoot")
      .callback(NULL);
    test_assert(s != NULL);

    test_AutoResumeSinkMount m =
      test_AutoResumeSinkMountCreate(mountRoot, NULL, NULL);
    test_assert(m != NULL);

    test_assertint(corto_ll_size(m->subscribes), 13);
    test_assertint(corto_ll_size(m->unsubscribes), 0);

    corto_query *r = corto_ll_get(m->subscribes, 0);
    test_assert(r != NULL);
    test_assertstr(r->from, ".");
    test_assertstr(r->select, "*");

    r = corto_ll_get(m->subscribes, 1);
    test_assert(r != NULL);
    test_assertstr(r->from, "x");
    test_assertstr(r->select, "*");

    r = corto_ll_get(m->subscribes, 2);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/a");
    test_assertstr(r->select, "*");

    r = corto_ll_get(m->subscribes, 3);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/a/k");
    test_assertstr(r->select, "*");

    r = corto_ll_get(m->subscribes, 4);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/a/k/n");
    test_assertstr(r->select, "*");

    r = corto_ll_get(m->subscribes, 5);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/a/k/o");
    test_assertstr(r->select, "*");

    r = corto_ll_get(m->subscribes, 6);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/a/k/p");
    test_assertstr(r->select, "*");

    r = corto_ll_get(m->subscribes, 7);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/a/l");
    test_assertstr(r->select, "*");

    r = corto_ll_get(m->subscribes, 8);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/a/m");
    test_assertstr(r->select, "*");

    r = corto_ll_get(m->subscribes, 9);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/b");
    test_assertstr(r->select, "*");

    r = corto_ll_get(m->subscribes, 10);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/c");
    test_assertstr(r->select, "*");

    r = corto_ll_get(m->subscribes, 11);
    test_assert(r != NULL);
    test_assertstr(r->from, "y");
    test_assertstr(r->select, "*");

    r = corto_ll_get(m->subscribes, 12);
    test_assert(r != NULL);
    test_assertstr(r->from, "z");
    test_assertstr(r->select, "*");

    test_assert(corto_delete(s) == 0);
    test_assertint(corto_ll_size(m->subscribes), 13);
    test_assertint(corto_ll_size(m->unsubscribes), 13);

    r = corto_ll_get(m->unsubscribes, 0);
    test_assert(r != NULL);
    test_assertstr(r->from, ".");

    r = corto_ll_get(m->unsubscribes, 1);
    test_assert(r != NULL);
    test_assertstr(r->from, "x");

    r = corto_ll_get(m->unsubscribes, 2);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/a");

    r = corto_ll_get(m->unsubscribes, 3);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/a/k");

    r = corto_ll_get(m->unsubscribes, 4);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/a/k/n");

    r = corto_ll_get(m->unsubscribes, 5);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/a/k/o");

    r = corto_ll_get(m->unsubscribes, 6);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/a/k/p");

    r = corto_ll_get(m->unsubscribes, 7);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/a/l");

    r = corto_ll_get(m->unsubscribes, 8);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/a/m");

    r = corto_ll_get(m->unsubscribes, 9);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/b");

    r = corto_ll_get(m->unsubscribes, 10);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/c");

    r = corto_ll_get(m->unsubscribes, 11);
    test_assert(r != NULL);
    test_assertstr(r->from, "y");

    r = corto_ll_get(m->unsubscribes, 12);
    test_assert(r != NULL);
    test_assertstr(r->from, "z");

    test_assert(corto_delete(m) == 0);
    test_assert(corto_delete(mountRoot) == 0);

}

void test_MountSubscription_tc_subscribeTreeDefine(
    test_MountSubscription this)
{

    /* << Insert implementation >> */

}

void test_MountSubscription_tc_subscribeTreeDefineNested(
    test_MountSubscription this)
{

    /* << Insert implementation >> */

}

void test_MountSubscription_tc_subscribeTreeDelete(
    test_MountSubscription this)
{

    /* << Insert implementation >> */

}

void test_MountSubscription_tc_subscribeTreeDeleteNested(
    test_MountSubscription this)
{

    /* << Insert implementation >> */

}

void test_MountSubscription_tc_subscribeTreeTwice(
    test_MountSubscription this)
{
    corto_object mountRoot = corto_createChild(root_o, "mountRoot", corto_void_o);
    test_assert(mountRoot != NULL);

    test_AutoResumeSinkMount m =
      test_AutoResumeSinkMountCreate(mountRoot, NULL, NULL);
    test_assert(m != NULL);

    corto_subscriber s1 = corto_subscribe("//").from("/mountRoot")
      .callback(NULL);
    test_assert(s1 != NULL);
    test_assertint(corto_ll_size(m->subscribes), 13);
    test_assertint(corto_ll_size(m->unsubscribes), 0);

    corto_subscriber s2 = corto_subscribe("//").from("/mountRoot")
      .callback(NULL);
    test_assert(s2 != NULL);
    test_assertint(corto_ll_size(m->subscribes), 13);
    test_assertint(corto_ll_size(m->unsubscribes), 0);

    corto_query *r = corto_ll_get(m->subscribes, 0);
    test_assert(r != NULL);
    test_assertstr(r->from, ".");
    test_assertstr(r->select, "*");

    r = corto_ll_get(m->subscribes, 1);
    test_assert(r != NULL);
    test_assertstr(r->from, "x");
    test_assertstr(r->select, "*");

    r = corto_ll_get(m->subscribes, 2);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/a");
    test_assertstr(r->select, "*");

    r = corto_ll_get(m->subscribes, 3);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/a/k");
    test_assertstr(r->select, "*");

    r = corto_ll_get(m->subscribes, 4);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/a/k/n");
    test_assertstr(r->select, "*");

    r = corto_ll_get(m->subscribes, 5);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/a/k/o");
    test_assertstr(r->select, "*");

    r = corto_ll_get(m->subscribes, 6);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/a/k/p");
    test_assertstr(r->select, "*");

    r = corto_ll_get(m->subscribes, 7);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/a/l");
    test_assertstr(r->select, "*");

    r = corto_ll_get(m->subscribes, 8);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/a/m");
    test_assertstr(r->select, "*");

    r = corto_ll_get(m->subscribes, 9);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/b");
    test_assertstr(r->select, "*");

    r = corto_ll_get(m->subscribes, 10);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/c");
    test_assertstr(r->select, "*");

    r = corto_ll_get(m->subscribes, 11);
    test_assert(r != NULL);
    test_assertstr(r->from, "y");
    test_assertstr(r->select, "*");

    r = corto_ll_get(m->subscribes, 12);
    test_assert(r != NULL);
    test_assertstr(r->from, "z");
    test_assertstr(r->select, "*");

    test_assert(corto_delete(s1) == 0);
    test_assertint(corto_ll_size(m->subscribes), 13);
    test_assertint(corto_ll_size(m->unsubscribes), 0);

    test_assert(corto_delete(s2) == 0);
    test_assertint(corto_ll_size(m->subscribes), 13);
    test_assertint(corto_ll_size(m->unsubscribes), 13);

    r = corto_ll_get(m->unsubscribes, 0);
    test_assert(r != NULL);
    test_assertstr(r->from, ".");

    r = corto_ll_get(m->unsubscribes, 1);
    test_assert(r != NULL);
    test_assertstr(r->from, "x");

    r = corto_ll_get(m->unsubscribes, 2);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/a");

    r = corto_ll_get(m->unsubscribes, 3);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/a/k");

    r = corto_ll_get(m->unsubscribes, 4);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/a/k/n");

    r = corto_ll_get(m->unsubscribes, 5);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/a/k/o");

    r = corto_ll_get(m->unsubscribes, 6);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/a/k/p");

    r = corto_ll_get(m->unsubscribes, 7);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/a/l");

    r = corto_ll_get(m->unsubscribes, 8);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/a/m");

    r = corto_ll_get(m->unsubscribes, 9);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/b");

    r = corto_ll_get(m->unsubscribes, 10);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/c");

    r = corto_ll_get(m->unsubscribes, 11);
    test_assert(r != NULL);
    test_assertstr(r->from, "y");

    r = corto_ll_get(m->unsubscribes, 12);
    test_assert(r != NULL);
    test_assertstr(r->from, "z");

    test_assert(corto_delete(m) == 0);
    test_assert(corto_delete(mountRoot) == 0);

}

void test_MountSubscription_tc_subscribeTreeTwiceSameSubscriber(
    test_MountSubscription this)
{
    corto_object mountRoot = corto_createChild(root_o, "mountRoot", corto_void_o);
    test_assert(mountRoot != NULL);

    test_AutoResumeSinkMount m =
      test_AutoResumeSinkMountCreate(mountRoot, NULL, NULL);
    test_assert(m != NULL);

    corto_subscriber s = corto_subscribe("//").from("/mountRoot")
      .disabled()
      .callback(NULL);
    test_assert(s != NULL);
    test_assertint(corto_ll_size(m->subscribes), 0);
    test_assertint(corto_ll_size(m->unsubscribes), 0);

    corto_object instance1 = corto_create(corto_void_o);
    corto_object instance2 = corto_create(corto_void_o);
    test_assert(corto_subscriber_subscribe(s, instance1) == 0);
    test_assertint(corto_ll_size(m->subscribes), 13);
    test_assertint(corto_ll_size(m->unsubscribes), 0);

    test_assert(corto_subscriber_subscribe(s, instance2) == 0);
    test_assertint(corto_ll_size(m->subscribes), 13);
    test_assertint(corto_ll_size(m->unsubscribes), 0);

    corto_query *r = corto_ll_get(m->subscribes, 0);
    test_assert(r != NULL);
    test_assertstr(r->from, ".");
    test_assertstr(r->select, "*");

    r = corto_ll_get(m->subscribes, 1);
    test_assert(r != NULL);
    test_assertstr(r->from, "x");
    test_assertstr(r->select, "*");

    r = corto_ll_get(m->subscribes, 2);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/a");
    test_assertstr(r->select, "*");

    r = corto_ll_get(m->subscribes, 3);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/a/k");
    test_assertstr(r->select, "*");

    r = corto_ll_get(m->subscribes, 4);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/a/k/n");
    test_assertstr(r->select, "*");

    r = corto_ll_get(m->subscribes, 5);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/a/k/o");
    test_assertstr(r->select, "*");

    r = corto_ll_get(m->subscribes, 6);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/a/k/p");
    test_assertstr(r->select, "*");

    r = corto_ll_get(m->subscribes, 7);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/a/l");
    test_assertstr(r->select, "*");

    r = corto_ll_get(m->subscribes, 8);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/a/m");
    test_assertstr(r->select, "*");

    r = corto_ll_get(m->subscribes, 9);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/b");
    test_assertstr(r->select, "*");

    r = corto_ll_get(m->subscribes, 10);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/c");
    test_assertstr(r->select, "*");

    r = corto_ll_get(m->subscribes, 11);
    test_assert(r != NULL);
    test_assertstr(r->from, "y");
    test_assertstr(r->select, "*");

    r = corto_ll_get(m->subscribes, 12);
    test_assert(r != NULL);
    test_assertstr(r->from, "z");
    test_assertstr(r->select, "*");

    test_assert(corto_delete(s) == 0);
    test_assertint(corto_ll_size(m->subscribes), 13);
    test_assertint(corto_ll_size(m->unsubscribes), 13);

    r = corto_ll_get(m->unsubscribes, 0);
    test_assert(r != NULL);
    test_assertstr(r->from, ".");

    r = corto_ll_get(m->unsubscribes, 1);
    test_assert(r != NULL);
    test_assertstr(r->from, "x");

    r = corto_ll_get(m->unsubscribes, 2);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/a");

    r = corto_ll_get(m->unsubscribes, 3);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/a/k");

    r = corto_ll_get(m->unsubscribes, 4);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/a/k/n");

    r = corto_ll_get(m->unsubscribes, 5);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/a/k/o");

    r = corto_ll_get(m->unsubscribes, 6);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/a/k/p");

    r = corto_ll_get(m->unsubscribes, 7);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/a/l");

    r = corto_ll_get(m->unsubscribes, 8);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/a/m");

    r = corto_ll_get(m->unsubscribes, 9);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/b");

    r = corto_ll_get(m->unsubscribes, 10);
    test_assert(r != NULL);
    test_assertstr(r->from, "x/c");

    r = corto_ll_get(m->unsubscribes, 11);
    test_assert(r != NULL);
    test_assertstr(r->from, "y");

    r = corto_ll_get(m->unsubscribes, 12);
    test_assert(r != NULL);
    test_assertstr(r->from, "z");

    test_assert(corto_delete(m) == 0);
    test_assert(corto_delete(mountRoot) == 0);

}

void test_MountSubscription_tc_subscribeTwoSingleOtherCtx(
    test_MountSubscription this)
{
    corto_object mountRoot = corto_createChild(root_o, "mountRoot", corto_void_o);
    test_assert(mountRoot != NULL);

    test_AutoResumeSinkMount m =
      test_AutoResumeSinkMountCreate(mountRoot, NULL, NULL);
    test_assert(m != NULL);

    corto_subscriber s1 = corto_subscribe("A").from("/mountRoot")
      .callback(NULL);
    test_assert(s1 != NULL);
    test_assertint(corto_ll_size(m->subscribes), 1);
    test_assertint(corto_ll_size(m->unsubscribes), 0);

    corto_query *r = corto_ll_get(m->subscribes, 0);
    test_assert(r != NULL);
    test_assertstr(r->from, ".");
    test_assertstr(r->select, "A");

    corto_subscriber s2 = corto_subscribe("B").from("/mountRoot")
      .callback(NULL);
    test_assert(s2 != NULL);
    test_assertint(corto_ll_size(m->subscribes), 2);
    test_assertint(corto_ll_size(m->unsubscribes), 0);

    r = corto_ll_get(m->subscribes, 1);
    test_assert(r != NULL);
    test_assertstr(r->from, ".");
    test_assertstr(r->select, "B");

    test_assert(corto_delete(s1) == 0);
    test_assertint(corto_ll_size(m->subscribes), 2);
    test_assertint(corto_ll_size(m->unsubscribes), 1);
    r = corto_ll_get(m->unsubscribes, 0);
    test_assert(r != NULL);
    test_assertstr(r->from, ".");
    test_assertstr(r->select, "A");

    test_assert(corto_delete(s2) == 0);
    test_assertint(corto_ll_size(m->subscribes), 2);
    test_assertint(corto_ll_size(m->unsubscribes), 2);
    r = corto_ll_get(m->unsubscribes, 1);
    test_assert(r != NULL);
    test_assertstr(r->from, ".");
    test_assertstr(r->select, "B");

    test_assert(corto_delete(m) == 0);
    test_assert(corto_delete(mountRoot) == 0);
}

void test_MountSubscription_tc_subscribeTwoSingleSameCtx(
    test_MountSubscription this)
{
    corto_object mountRoot = corto_createChild(root_o, "mountRoot", corto_void_o);
    test_assert(mountRoot != NULL);

    test_AutoResumeSinkMount m =
      test_AutoResumeSinkMountCreate(mountRoot, NULL, NULL);
    test_assert(m != NULL);

    corto_subscriber s1 = corto_subscribe("*A").from("/mountRoot")
      .callback(NULL);
    test_assert(s1 != NULL);
    test_assertint(corto_ll_size(m->subscribes), 1);
    test_assertint(corto_ll_size(m->unsubscribes), 0);

    corto_query *r = corto_ll_get(m->subscribes, 0);
    test_assert(r != NULL);
    test_assertstr(r->from, ".");
    test_assertstr(r->select, "*A");

    corto_subscriber s2 = corto_subscribe("*B").from("/mountRoot")
      .callback(NULL);
    test_assert(s2 != NULL);
    test_assertint(corto_ll_size(m->subscribes), 2);
    test_assertint(corto_ll_size(m->unsubscribes), 0);

    r = corto_ll_get(m->subscribes, 1);
    test_assert(r != NULL);
    test_assertstr(r->from, ".");
    test_assertstr(r->select, "*B");

    test_assert(corto_delete(s1) == 0);
    test_assertint(corto_ll_size(m->subscribes), 2);
    test_assertint(corto_ll_size(m->unsubscribes), 1);
    r = corto_ll_get(m->unsubscribes, 0);
    test_assert(r != NULL);
    test_assertstr(r->from, ".");
    test_assertstr(r->select, "*");

    test_assert(corto_delete(s2) == 0);
    test_assertint(corto_ll_size(m->subscribes), 2);
    test_assertint(corto_ll_size(m->unsubscribes), 1);

    test_assert(corto_delete(m) == 0);
    test_assert(corto_delete(mountRoot) == 0);

}

