/* $CORTO_GENERATED
 *
 * MountSubscription.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <test.h>

corto_void _test_MountSubscription_tc_subscribeScope(
    test_MountSubscription this)
{
/* $begin(test/MountSubscription/tc_subscribeScope) */
    corto_object mountRoot = corto_createChild(root_o, "mountRoot", corto_void_o);
    test_assert(mountRoot != NULL);

    test_AutoResumeSinkReplicator m =
      test_AutoResumeSinkReplicatorCreate(mountRoot, NULL, NULL);
    test_assert(m != NULL);

    corto_subscriber s = corto_subscribe(CORTO_ON_UPDATE, "/mountRoot", "*")
      .callback(NULL);
    test_assert(s != NULL);
    test_assertint(corto_llSize(m->subscribes), 1);
    test_assertint(corto_llSize(m->unsubscribes), 0);

    corto_request *r = corto_llGet(m->subscribes, 0);
    test_assert(r != NULL);
    test_assertstr(r->parent, ".");
    test_assertstr(r->expr, "*");

    test_assert(corto_delete(s) == 0);
    test_assertint(corto_llSize(m->subscribes), 1);
    test_assertint(corto_llSize(m->unsubscribes), 1);
    r = corto_llGet(m->unsubscribes, 0);
    test_assert(r != NULL);
    test_assertstr(r->parent, ".");

    test_assert(corto_delete(m) == 0);
    test_assert(corto_delete(mountRoot) == 0);

/* $end */
}

corto_void _test_MountSubscription_tc_subscribeScopeAlign(
    test_MountSubscription this)
{
/* $begin(test/MountSubscription/tc_subscribeScopeAlign) */

    /* << Insert implementation >> */

/* $end */
}

corto_void _test_MountSubscription_tc_subscribeScopeTwice(
    test_MountSubscription this)
{
/* $begin(test/MountSubscription/tc_subscribeScopeTwice) */
    corto_object mountRoot = corto_createChild(root_o, "mountRoot", corto_void_o);
    test_assert(mountRoot != NULL);

    test_AutoResumeSinkReplicator m =
      test_AutoResumeSinkReplicatorCreate(mountRoot, NULL, NULL);
    test_assert(m != NULL);

    corto_subscriber s1 = corto_subscribe(CORTO_ON_UPDATE, "/mountRoot", "*")
      .callback(NULL);
    test_assert(s1 != NULL);
    test_assertint(corto_llSize(m->subscribes), 1);
    test_assertint(corto_llSize(m->unsubscribes), 0);

    corto_subscriber s2 = corto_subscribe(CORTO_ON_UPDATE, "/mountRoot", "*")
      .callback(NULL);
    test_assert(s2 != NULL);
    test_assertint(corto_llSize(m->subscribes), 1);
    test_assertint(corto_llSize(m->unsubscribes), 0);

    corto_request *r = corto_llGet(m->subscribes, 0);
    test_assert(r != NULL);
    test_assertstr(r->parent, ".");
    test_assertstr(r->expr, "*");

    test_assert(corto_delete(s1) == 0);
    test_assertint(corto_llSize(m->subscribes), 1);
    test_assertint(corto_llSize(m->unsubscribes), 0);

    test_assert(corto_delete(s2) == 0);
    test_assertint(corto_llSize(m->subscribes), 1);
    test_assertint(corto_llSize(m->unsubscribes), 1);

    r = corto_llGet(m->unsubscribes, 0);
    test_assert(r != NULL);
    test_assertstr(r->parent, ".");

    test_assert(corto_delete(m) == 0);
    test_assert(corto_delete(mountRoot) == 0);

/* $end */
}

corto_void _test_MountSubscription_tc_subscribeScopeTwiceSameSubscriber(
    test_MountSubscription this)
{
/* $begin(test/MountSubscription/tc_subscribeScopeTwiceSameSubscriber) */

    /* << Insert implementation >> */

/* $end */
}

corto_void _test_MountSubscription_tc_subscribeSingle(
    test_MountSubscription this)
{
/* $begin(test/MountSubscription/tc_subscribeSingle) */
    corto_object mountRoot = corto_createChild(root_o, "mountRoot", corto_void_o);
    test_assert(mountRoot != NULL);

    test_AutoResumeSinkReplicator m =
      test_AutoResumeSinkReplicatorCreate(mountRoot, NULL, NULL);
    test_assert(m != NULL);

    corto_subscriber s = corto_subscribe(CORTO_ON_UPDATE, "/mountRoot", "foo")
      .callback(NULL);
    test_assert(s != NULL);
    test_assertint(corto_llSize(m->subscribes), 1);
    test_assertint(corto_llSize(m->unsubscribes), 0);

    corto_request *r = corto_llGet(m->subscribes, 0);
    test_assert(r != NULL);
    test_assertstr(r->parent, ".");
    test_assertstr(r->expr, "foo");

    test_assert(corto_delete(s) == 0);
    test_assertint(corto_llSize(m->subscribes), 1);
    test_assertint(corto_llSize(m->unsubscribes), 1);
    r = corto_llGet(m->unsubscribes, 0);
    test_assert(r != NULL);
    test_assertstr(r->parent, ".");

    test_assert(corto_delete(m) == 0);
    test_assert(corto_delete(mountRoot) == 0);

/* $end */
}

corto_void _test_MountSubscription_tc_subscribeSingleAlign(
    test_MountSubscription this)
{
/* $begin(test/MountSubscription/tc_subscribeSingleAlign) */

    /* << Insert implementation >> */

/* $end */
}

corto_void _test_MountSubscription_tc_subscribeSingleTwice(
    test_MountSubscription this)
{
/* $begin(test/MountSubscription/tc_subscribeSingleTwice) */
    corto_object mountRoot = corto_createChild(root_o, "mountRoot", corto_void_o);
    test_assert(mountRoot != NULL);

    test_AutoResumeSinkReplicator m =
      test_AutoResumeSinkReplicatorCreate(mountRoot, NULL, NULL);
    test_assert(m != NULL);

    corto_subscriber s1 = corto_subscribe(CORTO_ON_UPDATE, "/mountRoot", "foo")
      .callback(NULL);
    test_assert(s1 != NULL);
    test_assertint(corto_llSize(m->subscribes), 1);
    test_assertint(corto_llSize(m->unsubscribes), 0);

    corto_subscriber s2 = corto_subscribe(CORTO_ON_UPDATE, "/mountRoot", "foo")
      .callback(NULL);
    test_assert(s2 != NULL);
    test_assertint(corto_llSize(m->subscribes), 1);
    test_assertint(corto_llSize(m->unsubscribes), 0);

    corto_request *r = corto_llGet(m->subscribes, 0);
    test_assert(r != NULL);
    test_assertstr(r->parent, ".");
    test_assertstr(r->expr, "foo");

    test_assert(corto_delete(s1) == 0);
    test_assertint(corto_llSize(m->subscribes), 1);
    test_assertint(corto_llSize(m->unsubscribes), 0);

    test_assert(corto_delete(s2) == 0);
    test_assertint(corto_llSize(m->subscribes), 1);
    test_assertint(corto_llSize(m->unsubscribes), 1);

    r = corto_llGet(m->unsubscribes, 0);
    test_assert(r != NULL);
    test_assertstr(r->parent, ".");

    test_assert(corto_delete(m) == 0);
    test_assert(corto_delete(mountRoot) == 0);

/* $end */
}

corto_void _test_MountSubscription_tc_subscribeSingleTwiceSameSubscriber(
    test_MountSubscription this)
{
/* $begin(test/MountSubscription/tc_subscribeSingleTwiceSameSubscriber) */

    /* << Insert implementation >> */

/* $end */
}

corto_void _test_MountSubscription_tc_subscribeTree(
    test_MountSubscription this)
{
/* $begin(test/MountSubscription/tc_subscribeTree) */
    corto_object mountRoot = corto_createChild(root_o, "mountRoot", corto_void_o);
    test_assert(mountRoot != NULL);

    test_AutoResumeSinkReplicator m =
      test_AutoResumeSinkReplicatorCreate(mountRoot, NULL, NULL);
    test_assert(m != NULL);

    corto_subscriber s = corto_subscribe(CORTO_ON_UPDATE, "/mountRoot", "//")
      .callback(NULL);
    test_assert(s != NULL);
    test_assertint(corto_llSize(m->subscribes), 13);
    test_assertint(corto_llSize(m->unsubscribes), 0);

    corto_request *r = corto_llGet(m->subscribes, 0);
    test_assert(r != NULL);
    test_assertstr(r->parent, ".");
    test_assertstr(r->expr, "*");

    r = corto_llGet(m->subscribes, 1);
    test_assert(r != NULL);
    test_assertstr(r->parent, "x");
    test_assertstr(r->expr, "*");

    r = corto_llGet(m->subscribes, 2);
    test_assert(r != NULL);
    test_assertstr(r->parent, "x/a");
    test_assertstr(r->expr, "*");

    r = corto_llGet(m->subscribes, 3);
    test_assert(r != NULL);
    test_assertstr(r->parent, "x/a/k");
    test_assertstr(r->expr, "*");

    r = corto_llGet(m->subscribes, 4);
    test_assert(r != NULL);
    test_assertstr(r->parent, "x/a/k/n");
    test_assertstr(r->expr, "*");

    r = corto_llGet(m->subscribes, 5);
    test_assert(r != NULL);
    test_assertstr(r->parent, "x/a/k/o");
    test_assertstr(r->expr, "*");

    r = corto_llGet(m->subscribes, 6);
    test_assert(r != NULL);
    test_assertstr(r->parent, "x/a/k/p");
    test_assertstr(r->expr, "*");

    r = corto_llGet(m->subscribes, 7);
    test_assert(r != NULL);
    test_assertstr(r->parent, "x/a/l");
    test_assertstr(r->expr, "*");

    r = corto_llGet(m->subscribes, 8);
    test_assert(r != NULL);
    test_assertstr(r->parent, "x/a/m");
    test_assertstr(r->expr, "*");

    r = corto_llGet(m->subscribes, 9);
    test_assert(r != NULL);
    test_assertstr(r->parent, "x/b");
    test_assertstr(r->expr, "*");

    r = corto_llGet(m->subscribes, 10);
    test_assert(r != NULL);
    test_assertstr(r->parent, "x/c");
    test_assertstr(r->expr, "*");

    r = corto_llGet(m->subscribes, 11);
    test_assert(r != NULL);
    test_assertstr(r->parent, "y");
    test_assertstr(r->expr, "*");

    r = corto_llGet(m->subscribes, 12);
    test_assert(r != NULL);
    test_assertstr(r->parent, "z");
    test_assertstr(r->expr, "*");

    test_assert(corto_delete(s) == 0);
    test_assertint(corto_llSize(m->subscribes), 13);
    test_assertint(corto_llSize(m->unsubscribes), 13);

    r = corto_llGet(m->unsubscribes, 0);
    test_assert(r != NULL);
    test_assertstr(r->parent, ".");

    r = corto_llGet(m->unsubscribes, 1);
    test_assert(r != NULL);
    test_assertstr(r->parent, "x");

    r = corto_llGet(m->unsubscribes, 2);
    test_assert(r != NULL);
    test_assertstr(r->parent, "x/a");

    r = corto_llGet(m->unsubscribes, 3);
    test_assert(r != NULL);
    test_assertstr(r->parent, "x/a/k");

    r = corto_llGet(m->unsubscribes, 4);
    test_assert(r != NULL);
    test_assertstr(r->parent, "x/a/k/n");

    r = corto_llGet(m->unsubscribes, 5);
    test_assert(r != NULL);
    test_assertstr(r->parent, "x/a/k/o");

    r = corto_llGet(m->unsubscribes, 6);
    test_assert(r != NULL);
    test_assertstr(r->parent, "x/a/k/p");

    r = corto_llGet(m->unsubscribes, 7);
    test_assert(r != NULL);
    test_assertstr(r->parent, "x/a/l");

    r = corto_llGet(m->unsubscribes, 8);
    test_assert(r != NULL);
    test_assertstr(r->parent, "x/a/m");

    r = corto_llGet(m->unsubscribes, 9);
    test_assert(r != NULL);
    test_assertstr(r->parent, "x/b");

    r = corto_llGet(m->unsubscribes, 10);
    test_assert(r != NULL);
    test_assertstr(r->parent, "x/c");

    r = corto_llGet(m->unsubscribes, 11);
    test_assert(r != NULL);
    test_assertstr(r->parent, "y");

    r = corto_llGet(m->unsubscribes, 12);
    test_assert(r != NULL);
    test_assertstr(r->parent, "z");

    test_assert(corto_delete(m) == 0);
    test_assert(corto_delete(mountRoot) == 0);

/* $end */
}

corto_void _test_MountSubscription_tc_subscribeTreeAlign(
    test_MountSubscription this)
{
/* $begin(test/MountSubscription/tc_subscribeTreeAlign) */

    /* << Insert implementation >> */

/* $end */
}

corto_void _test_MountSubscription_tc_subscribeTreeDefine(
    test_MountSubscription this)
{
/* $begin(test/MountSubscription/tc_subscribeTreeDefine) */

    /* << Insert implementation >> */

/* $end */
}

corto_void _test_MountSubscription_tc_subscribeTreeDefineNested(
    test_MountSubscription this)
{
/* $begin(test/MountSubscription/tc_subscribeTreeDefineNested) */

    /* << Insert implementation >> */

/* $end */
}

corto_void _test_MountSubscription_tc_subscribeTreeDelete(
    test_MountSubscription this)
{
/* $begin(test/MountSubscription/tc_subscribeTreeDelete) */

    /* << Insert implementation >> */

/* $end */
}

corto_void _test_MountSubscription_tc_subscribeTreeDeleteNested(
    test_MountSubscription this)
{
/* $begin(test/MountSubscription/tc_subscribeTreeDeleteNested) */

    /* << Insert implementation >> */

/* $end */
}

corto_void _test_MountSubscription_tc_subscribeTreeTwice(
    test_MountSubscription this)
{
/* $begin(test/MountSubscription/tc_subscribeTreeTwice) */
    corto_object mountRoot = corto_createChild(root_o, "mountRoot", corto_void_o);
    test_assert(mountRoot != NULL);

    test_AutoResumeSinkReplicator m =
      test_AutoResumeSinkReplicatorCreate(mountRoot, NULL, NULL);
    test_assert(m != NULL);

    corto_subscriber s1 = corto_subscribe(CORTO_ON_UPDATE, "/mountRoot", "//")
      .callback(NULL);
    test_assert(s1 != NULL);
    test_assertint(corto_llSize(m->subscribes), 13);
    test_assertint(corto_llSize(m->unsubscribes), 0);

    corto_subscriber s2 = corto_subscribe(CORTO_ON_UPDATE, "/mountRoot", "//")
      .callback(NULL);
    test_assert(s2 != NULL);
    test_assertint(corto_llSize(m->subscribes), 13);
    test_assertint(corto_llSize(m->unsubscribes), 0);

    corto_request *r = corto_llGet(m->subscribes, 0);
    test_assert(r != NULL);
    test_assertstr(r->parent, ".");
    test_assertstr(r->expr, "*");

    r = corto_llGet(m->subscribes, 1);
    test_assert(r != NULL);
    test_assertstr(r->parent, "x");
    test_assertstr(r->expr, "*");

    r = corto_llGet(m->subscribes, 2);
    test_assert(r != NULL);
    test_assertstr(r->parent, "x/a");
    test_assertstr(r->expr, "*");

    r = corto_llGet(m->subscribes, 3);
    test_assert(r != NULL);
    test_assertstr(r->parent, "x/a/k");
    test_assertstr(r->expr, "*");

    r = corto_llGet(m->subscribes, 4);
    test_assert(r != NULL);
    test_assertstr(r->parent, "x/a/k/n");
    test_assertstr(r->expr, "*");

    r = corto_llGet(m->subscribes, 5);
    test_assert(r != NULL);
    test_assertstr(r->parent, "x/a/k/o");
    test_assertstr(r->expr, "*");

    r = corto_llGet(m->subscribes, 6);
    test_assert(r != NULL);
    test_assertstr(r->parent, "x/a/k/p");
    test_assertstr(r->expr, "*");

    r = corto_llGet(m->subscribes, 7);
    test_assert(r != NULL);
    test_assertstr(r->parent, "x/a/l");
    test_assertstr(r->expr, "*");

    r = corto_llGet(m->subscribes, 8);
    test_assert(r != NULL);
    test_assertstr(r->parent, "x/a/m");
    test_assertstr(r->expr, "*");

    r = corto_llGet(m->subscribes, 9);
    test_assert(r != NULL);
    test_assertstr(r->parent, "x/b");
    test_assertstr(r->expr, "*");

    r = corto_llGet(m->subscribes, 10);
    test_assert(r != NULL);
    test_assertstr(r->parent, "x/c");
    test_assertstr(r->expr, "*");

    r = corto_llGet(m->subscribes, 11);
    test_assert(r != NULL);
    test_assertstr(r->parent, "y");
    test_assertstr(r->expr, "*");

    r = corto_llGet(m->subscribes, 12);
    test_assert(r != NULL);
    test_assertstr(r->parent, "z");
    test_assertstr(r->expr, "*");

    test_assert(corto_delete(s1) == 0);
    test_assertint(corto_llSize(m->subscribes), 13);
    test_assertint(corto_llSize(m->unsubscribes), 0);

    test_assert(corto_delete(s2) == 0);
    test_assertint(corto_llSize(m->subscribes), 13);
    test_assertint(corto_llSize(m->unsubscribes), 13);

    r = corto_llGet(m->unsubscribes, 0);
    test_assert(r != NULL);
    test_assertstr(r->parent, ".");

    r = corto_llGet(m->unsubscribes, 1);
    test_assert(r != NULL);
    test_assertstr(r->parent, "x");

    r = corto_llGet(m->unsubscribes, 2);
    test_assert(r != NULL);
    test_assertstr(r->parent, "x/a");

    r = corto_llGet(m->unsubscribes, 3);
    test_assert(r != NULL);
    test_assertstr(r->parent, "x/a/k");

    r = corto_llGet(m->unsubscribes, 4);
    test_assert(r != NULL);
    test_assertstr(r->parent, "x/a/k/n");

    r = corto_llGet(m->unsubscribes, 5);
    test_assert(r != NULL);
    test_assertstr(r->parent, "x/a/k/o");

    r = corto_llGet(m->unsubscribes, 6);
    test_assert(r != NULL);
    test_assertstr(r->parent, "x/a/k/p");

    r = corto_llGet(m->unsubscribes, 7);
    test_assert(r != NULL);
    test_assertstr(r->parent, "x/a/l");

    r = corto_llGet(m->unsubscribes, 8);
    test_assert(r != NULL);
    test_assertstr(r->parent, "x/a/m");

    r = corto_llGet(m->unsubscribes, 9);
    test_assert(r != NULL);
    test_assertstr(r->parent, "x/b");

    r = corto_llGet(m->unsubscribes, 10);
    test_assert(r != NULL);
    test_assertstr(r->parent, "x/c");

    r = corto_llGet(m->unsubscribes, 11);
    test_assert(r != NULL);
    test_assertstr(r->parent, "y");

    r = corto_llGet(m->unsubscribes, 12);
    test_assert(r != NULL);
    test_assertstr(r->parent, "z");

    test_assert(corto_delete(m) == 0);
    test_assert(corto_delete(mountRoot) == 0);

/* $end */
}

corto_void _test_MountSubscription_tc_subscribeTreeTwiceSameSubscriber(
    test_MountSubscription this)
{
/* $begin(test/MountSubscription/tc_subscribeTreeTwiceSameSubscriber) */

    /* << Insert implementation >> */

/* $end */
}
