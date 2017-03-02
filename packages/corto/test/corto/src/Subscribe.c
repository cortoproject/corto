/* $CORTO_GENERATED
 *
 * Subscribe.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

corto_void _test_Subscribe_noInitialSep(
    test_Subscribe this,
    corto_eventMask event,
    corto_result *object,
    corto_subscriber subscriber)
{
/* $begin(test/Subscribe/noInitialSep) */
    this->triggered ++;
/* $end */
}

corto_void _test_Subscribe_tc_noInitialSep(
    test_Subscribe this)
{
/* $begin(test/Subscribe/tc_noInitialSep) */
    test_assertint(this->triggered, 0);

    corto_voidCreateChild_auto(root_o, testScope);
    corto_int32CreateChild_auto(testScope, i, 10);
    test_assertint(this->triggered, 0);

    corto_int16 ret = corto_subscriber_subscribe(test_Subscribe_noInitialSep_o, this);
    test_assert(ret == 0);
    test_assertint(this->triggered, 0);

    ret = corto_int32Update(i, 20);
    test_assert(ret == 0);

    test_assertint(this->triggered, 1);

/* $end */
}

/* $header(test/Subscribe/tc_subscribeInvertCase) */
void subscribeInvertCaseOnUpdate(
    corto_object instance,
    corto_eventMask event,
    corto_result *result,
    corto_subscriber subscriber)
{
    test_Subscribe this = instance;
    this->triggered = TRUE;
}
/* $end */
corto_void _test_Subscribe_tc_subscribeInvertCase(
    test_Subscribe this)
{
/* $begin(test/Subscribe/tc_subscribeInvertCase) */
    corto_object a = corto_createChild(root_o, "a", corto_void_o);
    test_assert(a != NULL);

    corto_object xyz = corto_createChild(a, "xyz", corto_void_o);
    test_assert(xyz != NULL);

    corto_subscriber s = corto_subscribe(CORTO_ON_UPDATE, "/a", "XYZ")
      .instance(this)
      .callback(subscribeInvertCaseOnUpdate);

    test_assert(s != NULL);
    test_assert(corto_update(xyz) == 0);
    test_assert(this->triggered == TRUE);

    test_assert(corto_delete(s) == 0);
    test_assert(corto_delete(a) == 0);

/* $end */
}

/* $header(test/Subscribe/tc_subscribeInvertCaseFilter) */
void subscribeInvertCaseFilterOnUpdate(
    corto_object instance,
    corto_eventMask event,
    corto_result *result,
    corto_subscriber subscriber)
{
    test_Subscribe this = instance;
    this->triggered = TRUE;
}
/* $end */
corto_void _test_Subscribe_tc_subscribeInvertCaseFilter(
    test_Subscribe this)
{
/* $begin(test/Subscribe/tc_subscribeInvertCaseFilter) */
    corto_object a = corto_createChild(root_o, "a", corto_void_o);
    test_assert(a != NULL);

    corto_object xyz = corto_createChild(a, "xyz", corto_void_o);
    test_assert(xyz != NULL);

    corto_subscriber s = corto_subscribe(CORTO_ON_UPDATE, "/a", "XY?")
      .instance(this)
      .callback(subscribeInvertCaseFilterOnUpdate);

    test_assert(s != NULL);
    test_assert(corto_update(xyz) == 0);
    test_assert(this->triggered == TRUE);

    test_assert(corto_delete(s) == 0);
    test_assert(corto_delete(a) == 0);

/* $end */
}

/* $header(test/Subscribe/tc_subscribeInvertCaseFilterFromPublish) */
void subscribeInvertCaseFilterFromPublishOnUpdate(
    corto_object instance,
    corto_eventMask event,
    corto_result *result,
    corto_subscriber subscriber)
{
    test_Subscribe this = instance;
    this->triggered = TRUE;
}
/* $end */
corto_void _test_Subscribe_tc_subscribeInvertCaseFilterFromPublish(
    test_Subscribe this)
{
/* $begin(test/Subscribe/tc_subscribeInvertCaseFilterFromPublish) */
    corto_subscriber s = corto_subscribe(CORTO_ON_UPDATE, "/a", "XY?")
      .instance(this)
      .callback(subscribeInvertCaseFilterFromPublishOnUpdate);

    test_assert(s != NULL);

    test_assert(corto_publish(CORTO_ON_UPDATE, "/a/xyz", "void", NULL, 0) == 0);

    test_assert(this->triggered == TRUE);

    test_assert(corto_delete(s) == 0);

/* $end */
}

/* $header(test/Subscribe/tc_subscribeInvertCaseFromPublish) */
void subscribeInvertCaseFromPublishOnUpdate(
    corto_object instance,
    corto_eventMask event,
    corto_result *result,
    corto_subscriber subscriber)
{
    test_Subscribe this = instance;
    this->triggered = TRUE;
}
/* $end */
corto_void _test_Subscribe_tc_subscribeInvertCaseFromPublish(
    test_Subscribe this)
{
/* $begin(test/Subscribe/tc_subscribeInvertCaseFromPublish) */
    corto_subscriber s = corto_subscribe(CORTO_ON_UPDATE, "/a", "XYZ")
      .instance(this)
      .callback(subscribeInvertCaseFromPublishOnUpdate);

    test_assert(s != NULL);

    test_assert(corto_publish(CORTO_ON_UPDATE, "/a/xyz", "void", NULL, 0) == 0);

    test_assert(this->triggered == TRUE);

    test_assert(corto_delete(s) == 0);

/* $end */
}

/* $header(test/Subscribe/tc_subscribeInvertCaseParent) */
void subscribeInvertCaseParentOnUpdate(
    corto_object instance,
    corto_eventMask event,
    corto_result *result,
    corto_subscriber subscriber)
{
    test_Subscribe this = instance;
    this->triggered = TRUE;
}
/* $end */
corto_void _test_Subscribe_tc_subscribeInvertCaseParent(
    test_Subscribe this)
{
/* $begin(test/Subscribe/tc_subscribeInvertCaseParent) */
    corto_object a = corto_createChild(root_o, "a", corto_void_o);
    test_assert(a != NULL);

    corto_object xyz = corto_createChild(a, "xyz", corto_void_o);
    test_assert(xyz != NULL);

    corto_subscriber s = corto_subscribe(CORTO_ON_UPDATE, "/A", "xyz")
      .instance(this)
      .callback(subscribeInvertCaseParentOnUpdate);

    test_assert(s != NULL);
    test_assert(corto_update(xyz) == 0);
    test_assert(this->triggered == TRUE);

    test_assert(corto_delete(s) == 0);
    test_assert(corto_delete(a) == 0);

/* $end */
}

/* $header(test/Subscribe/tc_subscribeInvertCaseParentFromPublish) */
void subscribeInvertCaseParentFromPublishOnUpdate(
    corto_object instance,
    corto_eventMask event,
    corto_result *result,
    corto_subscriber subscriber)
{
    test_Subscribe this = instance;
    this->triggered = TRUE;
}
/* $end */
corto_void _test_Subscribe_tc_subscribeInvertCaseParentFromPublish(
    test_Subscribe this)
{
/* $begin(test/Subscribe/tc_subscribeInvertCaseParentFromPublish) */
    corto_subscriber s = corto_subscribe(CORTO_ON_UPDATE, "/A", "xyz")
      .instance(this)
      .callback(subscribeInvertCaseParentFromPublishOnUpdate);

    test_assert(s != NULL);

    test_assert(corto_publish(CORTO_ON_UPDATE, "/a/xyz", "void", NULL, 0) == 0);

    test_assert(this->triggered == TRUE);

    test_assert(corto_delete(s) == 0);

/* $end */
}

/* $header(test/Subscribe/tc_subscribeNestedIdFromRoot) */
void tc_subscribeNestedIdFromRootOnUpdate(
    corto_object instance,
    corto_eventMask event,
    corto_result *result,
    corto_subscriber subscriber)
{
    test_Subscribe this = instance;
    this->triggered = TRUE;
}
/* $end */
corto_void _test_Subscribe_tc_subscribeNestedIdFromRoot(
    test_Subscribe this)
{
/* $begin(test/Subscribe/tc_subscribeNestedIdFromRoot) */
    corto_subscriber s = corto_subscribe(CORTO_ON_UPDATE, "/", "A/XYZ")
      .instance(this)
      .callback(tc_subscribeNestedIdFromRootOnUpdate);

    test_assert(corto_publish(CORTO_ON_UPDATE, "/A/XYZ", "void", NULL, 0) == 0);

    test_assert(this->triggered == TRUE);

    test_assert(corto_delete(s) == 0);

/* $end */
}

/* $header(test/Subscribe/tc_subscribeNestedScopeFromRoot) */
void tc_subscribeNestedScopeFromRootOnUpdate(
    corto_object instance,
    corto_eventMask event,
    corto_result *result,
    corto_subscriber subscriber)
{
    test_Subscribe this = instance;
    this->triggered = TRUE;
}
/* $end */
corto_void _test_Subscribe_tc_subscribeNestedScopeFromRoot(
    test_Subscribe this)
{
/* $begin(test/Subscribe/tc_subscribeNestedScopeFromRoot) */
    corto_subscriber s = corto_subscribe(CORTO_ON_UPDATE, "/", "A/*")
      .instance(this)
      .callback(tc_subscribeNestedScopeFromRootOnUpdate);

    test_assert(corto_publish(CORTO_ON_UPDATE, "/A/XYZ", "void", NULL, 0) == 0);

    test_assert(this->triggered == TRUE);

    test_assert(corto_delete(s) == 0);

/* $end */
}

corto_void _test_Subscribe_tc_subscribePartialMatchingParent(
    test_Subscribe this)
{
/* $begin(test/Subscribe/tc_subscribePartialMatchingParent) */
    corto_subscriber s = corto_subscribe(CORTO_ON_UPDATE, "/foo", "/")
      .instance(this)
      .callback(tc_subscribeNestedScopeFromRootOnUpdate);

    test_assert(corto_publish(CORTO_ON_UPDATE, "/foobar", "void", NULL, 0) == 0);

    test_assert(this->triggered == FALSE);

    test_assert(corto_delete(s) == 0);

/* $end */
}

corto_void _test_Subscribe_tc_subscribePartialMatchingParentObject(
    test_Subscribe this)
{
/* $begin(test/Subscribe/tc_subscribePartialMatchingParentObject) */
    corto_object foobar = corto_createChild(root_o, "foobar", corto_void_o);
    test_assert(foobar != NULL);

    corto_subscriber s = corto_subscribe(CORTO_ON_UPDATE, "/foo", "/")
      .instance(this)
      .callback(tc_subscribeNestedScopeFromRootOnUpdate);

    test_assert(corto_update(foobar) == 0);

    test_assert(this->triggered == FALSE);

    test_assert(corto_delete(s) == 0);
/* $end */
}
