/* $CORTO_GENERATED
 *
 * Subscribe.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

void _test_Subscribe_noInitialSep(
    corto_subscriberEvent *e)
{
/* $begin(test/Subscribe/noInitialSep) */
    test_Subscribe this = e->instance;
    this->triggered ++;
/* $end */
}

void _test_Subscribe_tc_noInitialSep(
    test_Subscribe this)
{
/* $begin(test/Subscribe/tc_noInitialSep) */
    test_assertint(this->triggered, 0);

    corto_voidCreateChild_auto(root_o, testScope);
    corto_int32CreateChild_auto(testScope, i, 10);
    test_assertint(this->triggered, 0);

    corto_int16 ret = corto_subscriber_subscribe(test_Subscribe_noInitialSep_o, this);
    test_assert(ret == 0);
    test_assertint(this->triggered, 1); /* Alignment */

    ret = corto_int32Update(i, 20);
    test_assert(ret == 0);

    test_assertint(this->triggered, 2);

/* $end */
}

/* $header(test/Subscribe/tc_subscribeAlignSelf) */
void subscribeAlignSelf(corto_subscriberEvent *e)
{
    test_Subscribe this = e->instance;
    test_assertstr(e->data.id, "o");
    test_assert(e->event == CORTO_ON_DEFINE);
    this->triggered = TRUE;
}
/* $end */
void _test_Subscribe_tc_subscribeAlignSelf(
    test_Subscribe this)
{
/* $begin(test/Subscribe/tc_subscribeAlignSelf) */
    corto_createChild(root_o, "o", corto_void_o);

    corto_subscriber s = corto_subscribe("o")
      .instance(this)
      .callback(subscribeAlignSelf);

    test_assert(this->triggered == TRUE);

    test_assert(corto_delete(s) == 0);

/* $end */
}

/* $header(test/Subscribe/tc_subscribeAlignType) */
void subscribeAlignType(corto_subscriberEvent *e)
{
    test_Subscribe this = e->instance;
    test_assertstr(e->data.id, "p");
    test_assert(e->event == CORTO_ON_DEFINE);
    this->triggered = TRUE;
}
/* $end */
void _test_Subscribe_tc_subscribeAlignType(
    test_Subscribe this)
{
/* $begin(test/Subscribe/tc_subscribeAlignType) */
    corto_createChild(root_o, "o", corto_int32_o);
    corto_createChild(root_o, "p", corto_float32_o);
    corto_createChild(root_o, "q", corto_string_o);

    corto_subscriber s = corto_subscribe("*")
      .instance(this)
      .type("float32")
      .callback(subscribeAlignType);

    test_assert(this->triggered == TRUE);

    test_assert(corto_delete(s) == 0);

/* $end */
}

/* $header(test/Subscribe/tc_subscribeInvertCase) */
void subscribeInvertCaseOnUpdate(corto_subscriberEvent *e)
{
    test_Subscribe this = e->instance;
    this->triggered = TRUE;
}
/* $end */
void _test_Subscribe_tc_subscribeInvertCase(
    test_Subscribe this)
{
/* $begin(test/Subscribe/tc_subscribeInvertCase) */
    corto_object a = corto_createChild(root_o, "a", corto_void_o);
    test_assert(a != NULL);

    corto_object xyz = corto_createChild(a, "xyz", corto_void_o);
    test_assert(xyz != NULL);

    corto_subscriber s = corto_subscribe("XYZ").from("/a")
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
void subscribeInvertCaseFilterOnUpdate(corto_subscriberEvent *e)
{
    test_Subscribe this = e->instance;
    this->triggered = TRUE;
}
/* $end */
void _test_Subscribe_tc_subscribeInvertCaseFilter(
    test_Subscribe this)
{
/* $begin(test/Subscribe/tc_subscribeInvertCaseFilter) */
    corto_object a = corto_createChild(root_o, "a", corto_void_o);
    test_assert(a != NULL);

    corto_object xyz = corto_createChild(a, "xyz", corto_void_o);
    test_assert(xyz != NULL);

    corto_subscriber s = corto_subscribe("XY?").from("/a")
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
void subscribeInvertCaseFilterFromPublishOnUpdate(corto_subscriberEvent *e)
{
    test_Subscribe this = e->instance;
    this->triggered = TRUE;
}
/* $end */
void _test_Subscribe_tc_subscribeInvertCaseFilterFromPublish(
    test_Subscribe this)
{
/* $begin(test/Subscribe/tc_subscribeInvertCaseFilterFromPublish) */
    corto_subscriber s = corto_subscribe("XY?").from("/a")
      .instance(this)
      .callback(subscribeInvertCaseFilterFromPublishOnUpdate);

    test_assert(s != NULL);

    test_assert(corto_publish(CORTO_ON_UPDATE, "/a/xyz", "void", NULL, 0) == 0);

    test_assert(this->triggered == TRUE);

    test_assert(corto_delete(s) == 0);

/* $end */
}

/* $header(test/Subscribe/tc_subscribeInvertCaseFromPublish) */
void subscribeInvertCaseFromPublishOnUpdate(corto_subscriberEvent *e)
{
    test_Subscribe this = e->instance;
    this->triggered = TRUE;
}
/* $end */
void _test_Subscribe_tc_subscribeInvertCaseFromPublish(
    test_Subscribe this)
{
/* $begin(test/Subscribe/tc_subscribeInvertCaseFromPublish) */
    corto_subscriber s = corto_subscribe("XYZ").from("/a")
      .instance(this)
      .callback(subscribeInvertCaseFromPublishOnUpdate);

    test_assert(s != NULL);

    test_assert(corto_publish(CORTO_ON_UPDATE, "/a/xyz", "void", NULL, 0) == 0);

    test_assert(this->triggered == TRUE);

    test_assert(corto_delete(s) == 0);

/* $end */
}

/* $header(test/Subscribe/tc_subscribeInvertCaseParent) */
void subscribeInvertCaseParentOnUpdate(corto_subscriberEvent *e)
{
    test_Subscribe this = e->instance;
    this->triggered = TRUE;
}
/* $end */
void _test_Subscribe_tc_subscribeInvertCaseParent(
    test_Subscribe this)
{
/* $begin(test/Subscribe/tc_subscribeInvertCaseParent) */
    corto_object a = corto_createChild(root_o, "a", corto_void_o);
    test_assert(a != NULL);

    corto_object xyz = corto_createChild(a, "xyz", corto_void_o);
    test_assert(xyz != NULL);

    corto_subscriber s = corto_subscribe("xyz").from("/A")
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
void subscribeInvertCaseParentFromPublishOnUpdate(corto_subscriberEvent *e)
{
    test_Subscribe this = e->instance;
    this->triggered = TRUE;
}
/* $end */
void _test_Subscribe_tc_subscribeInvertCaseParentFromPublish(
    test_Subscribe this)
{
/* $begin(test/Subscribe/tc_subscribeInvertCaseParentFromPublish) */
    corto_subscriber s = corto_subscribe("xyz").from("/A")
      .instance(this)
      .callback(subscribeInvertCaseParentFromPublishOnUpdate);

    test_assert(s != NULL);

    test_assert(corto_publish(CORTO_ON_UPDATE, "/a/xyz", "void", NULL, 0) == 0);

    test_assert(this->triggered == TRUE);

    test_assert(corto_delete(s) == 0);

/* $end */
}

/* $header(test/Subscribe/tc_subscribeMultiDifferentParent) */
void MultiDifferentParent1(corto_subscriberEvent *e) {
    test_Subscribe instance = e->instance;
    instance->triggered ++;

    test_assertstr(e->data.id, "foo");
    test_assertstr(e->data.parent, "/data");
    test_assertstr(e->data.type, "void");
}
void MultiDifferentParent2(corto_subscriberEvent *e) {
    test_Subscribe instance = e->instance;
    instance->triggered ++;

    test_assertstr(e->data.id, "foo");
    test_assertstr(e->data.parent, "data");
    test_assertstr(e->data.type, "void");
}
void MultiDifferentParent3(corto_subscriberEvent *e) {
    test_Subscribe instance = e->instance;
    instance->triggered ++;
    
    test_assertstr(e->data.id, "foo");
    test_assertstr(e->data.parent, ".");
    test_assertstr(e->data.type, "void");   
}
/* $end */
void _test_Subscribe_tc_subscribeMultiDifferentParent(
    test_Subscribe this)
{
/* $begin(test/Subscribe/tc_subscribeMultiDifferentParent) */
    corto_subscriber s0 = corto_subscribe("/data/*")
        .instance(this)
        .callback(MultiDifferentParent1);

    corto_subscriber s1 = corto_subscribe("data/*").from("/")
        .instance(this)
        .callback(MultiDifferentParent2);

    corto_subscriber s2 = corto_subscribe("*").from("data")
        .instance(this)
        .callback(MultiDifferentParent3);

    corto_subscriber s3 = corto_subscribe("*").from("/data")
        .instance(this)
        .callback(MultiDifferentParent3);

    /* Create data scope */
    corto_object data = corto_createChild(root_o, "data", corto_void_o);

    /* Create foo object in data (triggers subscribers) */
    corto_createChild(data, "foo", corto_void_o);
    test_assertint(this->triggered, 4);

    test_assert(corto_delete(s0) == 0);
    test_assert(corto_delete(s1) == 0);
    test_assert(corto_delete(s2) == 0);
    test_assert(corto_delete(s3) == 0);
    test_assert(corto_delete(data) == 0);

/* $end */
}

/* $header(test/Subscribe/tc_subscribeMultiDifferentParent) */
void MultiDifferentParentVirtual1(corto_subscriberEvent *e) {
    test_Subscribe instance = e->instance;
    instance->triggered ++;

    test_assertstr(e->data.id, "foo");
    test_assertstr(e->data.parent, "/data");
    test_assertstr(e->data.type, "void");
}
void MultiDifferentParentVirtual2(corto_subscriberEvent *e) {
    test_Subscribe instance = e->instance;
    instance->triggered ++;

    test_assertstr(e->data.id, "foo");
    test_assertstr(e->data.parent, "data");
    test_assertstr(e->data.type, "void");
}
void MultiDifferentParentVirtual3(corto_subscriberEvent *e) {
    test_Subscribe instance = e->instance;
    instance->triggered ++;
    
    test_assertstr(e->data.id, "foo");
    test_assertstr(e->data.parent, ".");
    test_assertstr(e->data.type, "void");   
}
/* $end */
void _test_Subscribe_tc_subscribeMultiDifferentParentVirtual(
    test_Subscribe this)
{
/* $begin(test/Subscribe/tc_subscribeMultiDifferentParentVirtual) */
    corto_subscriber s0 = corto_subscribe("/data/*")
        .instance(this)
        .callback(MultiDifferentParentVirtual1);

    corto_subscriber s1 = corto_subscribe("data/*").from("/")
        .instance(this)
        .callback(MultiDifferentParentVirtual2);

    corto_subscriber s2 = corto_subscribe("*").from("data")
        .instance(this)
        .callback(MultiDifferentParentVirtual3);

    corto_subscriber s3 = corto_subscribe("*").from("/data")
        .instance(this)
        .callback(MultiDifferentParentVirtual3);

    /* Publish foo object in data (triggers subscribers) */
    corto_publish(CORTO_ON_DEFINE, "data/foo", "void", NULL, 0);
    test_assertint(this->triggered, 4);

    corto_publish(CORTO_ON_DEFINE, "/data/foo", "void", NULL, 0);
    test_assertint(this->triggered, 8);

    test_assert(corto_delete(s0) == 0);
    test_assert(corto_delete(s1) == 0);
    test_assert(corto_delete(s2) == 0);
    test_assert(corto_delete(s3) == 0);

/* $end */
}

/* $header(test/Subscribe/tc_subscribeNestedIdFromRoot) */
void tc_subscribeNestedIdFromRootOnUpdate(corto_subscriberEvent *e)
{
    test_Subscribe this = e->instance;
    this->triggered = TRUE;
}
/* $end */
void _test_Subscribe_tc_subscribeNestedIdFromRoot(
    test_Subscribe this)
{
/* $begin(test/Subscribe/tc_subscribeNestedIdFromRoot) */
    corto_subscriber s = corto_subscribe("A/XYZ").from("/")
      .instance(this)
      .callback(tc_subscribeNestedIdFromRootOnUpdate);

    test_assert(corto_publish(CORTO_ON_UPDATE, "/A/XYZ", "void", NULL, 0) == 0);

    test_assert(this->triggered == TRUE);

    test_assert(corto_delete(s) == 0);

/* $end */
}

/* $header(test/Subscribe/tc_subscribeNestedScopeFromRoot) */
void tc_subscribeNestedScopeFromRootOnUpdate(corto_subscriberEvent *e)
{
    test_Subscribe this = e->instance;
    this->triggered = TRUE;
}
/* $end */
void _test_Subscribe_tc_subscribeNestedScopeFromRoot(
    test_Subscribe this)
{
/* $begin(test/Subscribe/tc_subscribeNestedScopeFromRoot) */
    corto_subscriber s = corto_subscribe("A/*").from("/")
      .instance(this)
      .callback(tc_subscribeNestedScopeFromRootOnUpdate);

    test_assert(corto_publish(CORTO_ON_UPDATE, "/A/XYZ", "void", NULL, 0) == 0);

    test_assert(this->triggered == TRUE);

    test_assert(corto_delete(s) == 0);

/* $end */
}

/* $header(test/Subscribe/tc_subscribeOwnerSet) */
void tc_subscribeOwnerSet(corto_subscriberEvent *e)
{
    test_Subscribe this = e->instance;
    corto_ptr_setref(&this->owner, e->data.owner);
}
/* $end */
void _test_Subscribe_tc_subscribeOwnerSet(
    test_Subscribe this)
{
/* $begin(test/Subscribe/tc_subscribeOwnerSet) */
    corto_object owner = corto_voidCreate();
    corto_object prevOwner = corto_setOwner(owner);
    corto_object a = corto_createChild(NULL, "a", corto_int32_o);
    corto_setOwner(prevOwner);
    corto_object b = corto_createChild(NULL, "b", corto_int32_o);

    corto_subscriber s = corto_subscribe("a,b").from("/")
      .instance(this)
      .callback(tc_subscribeOwnerSet);
 
    corto_ptr_setref(&this->owner, NULL);

    test_assert(corto_update(a) == 0);
    test_assert(this->owner == owner);

    test_assert(corto_update(b) == 0);
    test_assert(this->owner == NULL);

    test_assert(corto_delete(b) == 0);

    corto_setOwner(owner);
    test_assert(corto_delete(a) == 0);
    corto_setOwner(prevOwner);

    test_assert(corto_delete(s) == 0);

/* $end */
}

void _test_Subscribe_tc_subscribePartialMatchingParent(
    test_Subscribe this)
{
/* $begin(test/Subscribe/tc_subscribePartialMatchingParent) */
    corto_subscriber s = corto_subscribe("/").from("/foo")
      .instance(this)
      .callback(tc_subscribeNestedScopeFromRootOnUpdate);

    test_assert(corto_publish(CORTO_ON_UPDATE, "/foobar", "void", NULL, 0) == 0);

    test_assert(this->triggered == FALSE);

    test_assert(corto_delete(s) == 0);

/* $end */
}

void _test_Subscribe_tc_subscribePartialMatchingParentObject(
    test_Subscribe this)
{
/* $begin(test/Subscribe/tc_subscribePartialMatchingParentObject) */
    corto_object foobar = corto_createChild(root_o, "foobar", corto_void_o);
    test_assert(foobar != NULL);

    corto_subscriber s = corto_subscribe("/").from("/foo")
      .instance(this)
      .callback(tc_subscribeNestedScopeFromRootOnUpdate);

    test_assert(corto_update(foobar) == 0);

    test_assert(this->triggered == FALSE);

    test_assert(corto_delete(s) == 0);
/* $end */
}
