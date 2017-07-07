/* This is a managed file. Do not delete this comment. */

#include <include/test.h>
void test_Subscribe_noInitialSep(
    corto_subscriberEvent *e)
{
    test_Subscribe this = e->instance;
    this->triggered ++;
}

void test_Subscribe_tc_noInitialSep(
    test_Subscribe this)
{
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

}

void subscribeAlignSelf(corto_subscriberEvent *e)
{
    test_Subscribe this = e->instance;
    test_assertstr(e->data.id, "o");
    test_assert(e->event == CORTO_ON_DEFINE);
    this->triggered = TRUE;
}

void test_Subscribe_tc_subscribeAlignSelf(
    test_Subscribe this)
{
    corto_createChild(root_o, "o", corto_void_o);

    corto_subscriber s = corto_subscribe("o")
      .instance(this)
      .callback(subscribeAlignSelf);

    test_assert(this->triggered == TRUE);

    test_assert(corto_delete(s) == 0);

}

void subscribeAlignType(corto_subscriberEvent *e)
{
    test_Subscribe this = e->instance;
    test_assertstr(e->data.id, "p");
    test_assert(e->event == CORTO_ON_DEFINE);
    this->triggered = TRUE;
}

void test_Subscribe_tc_subscribeAlignType(
    test_Subscribe this)
{
    corto_createChild(root_o, "o", corto_int32_o);
    corto_createChild(root_o, "p", corto_float32_o);
    corto_createChild(root_o, "q", corto_string_o);

    corto_subscriber s = corto_subscribe("*")
      .instance(this)
      .type("float32")
      .callback(subscribeAlignType);

    test_assert(this->triggered == TRUE);

    test_assert(corto_delete(s) == 0);

}

void subscribeResultTest(corto_subscriberEvent *e)
{
    test_Subscribe this = e->instance;
    this->triggered = TRUE;
    corto_ptr_copy(&this->result, corto_result_o, &e->data);
}

void test_Subscribe_tc_subscribeFromEmpty(
    test_Subscribe this)
{
    corto_int32 *a = corto_createChild(root_o, "a", corto_int32_o);
    test_assert(a != NULL);

    corto_subscriber s = corto_subscribe("*")
        .from("")
        .instance(this)
        .callback(subscribeResultTest);
    test_assert(s != NULL);

    this->triggered = FALSE;

    corto_update(a);

    test_assertstr(this->result.id, "a");
    test_assertstr(this->result.parent, "");
    test_assertstr(this->result.type, "int32");

    test_assert(corto_delete(s) == 0);
    test_assert(corto_delete(a) == 0);

}

void test_Subscribe_tc_subscribeFromImplicit(
    test_Subscribe this)
{
    corto_int32 *a = corto_createChild(root_o, "a", corto_int32_o);
    test_assert(a != NULL);

    corto_subscriber s = corto_subscribe("*")
        .instance(this)
        .callback(subscribeResultTest);
    test_assert(s != NULL);

    this->triggered = FALSE;

    corto_update(a);

    test_assertstr(this->result.id, "a");
    test_assertstr(this->result.parent, "");
    test_assertstr(this->result.type, "int32");

    test_assert(corto_delete(s) == 0);
    test_assert(corto_delete(a) == 0);

}

void test_Subscribe_tc_subscribeFromNested(
    test_Subscribe this)
{
    corto_object scope = corto_createChild(root_o, "scope", corto_void_o);
    corto_object nested = corto_createChild(scope, "nested", corto_void_o);
    corto_int32 *a = corto_createChild(nested, "a", corto_int32_o);
    test_assert(a != NULL);

    corto_subscriber s = corto_subscribe("*")
        .from("/scope/nested")
        .instance(this)
        .callback(subscribeResultTest);
    test_assert(s != NULL);

    this->triggered = FALSE;

    corto_update(a);

    test_assertstr(this->result.id, "a");
    test_assertstr(this->result.parent, ".");
    test_assertstr(this->result.type, "int32");

    test_assert(corto_delete(s) == 0);
    test_assert(corto_delete(scope) == 0);

}

void test_Subscribe_tc_subscribeFromNestedNoInitialSlash(
    test_Subscribe this)
{
    corto_object scope = corto_createChild(root_o, "scope", corto_void_o);
    corto_object nested = corto_createChild(scope, "nested", corto_void_o);
    corto_int32 *a = corto_createChild(nested, "a", corto_int32_o);
    test_assert(a != NULL);

    corto_subscriber s = corto_subscribe("*")
        .from("scope/nested")
        .instance(this)
        .callback(subscribeResultTest);
    test_assert(s != NULL);

    this->triggered = FALSE;

    corto_update(a);

    test_assertstr(this->result.id, "a");
    test_assertstr(this->result.parent, ".");
    test_assertstr(this->result.type, "int32");

    test_assert(corto_delete(s) == 0);
    test_assert(corto_delete(scope) == 0);

}

void test_Subscribe_tc_subscribeFromNull(
    test_Subscribe this)
{
    corto_int32 *a = corto_createChild(root_o, "a", corto_int32_o);
    test_assert(a != NULL);

    corto_subscriber s = corto_subscribe("*")
        .from(NULL)
        .instance(this)
        .callback(subscribeResultTest);
    test_assert(s != NULL);

    this->triggered = FALSE;

    corto_update(a);

    test_assertstr(this->result.id, "a");
    test_assertstr(this->result.parent, "");
    test_assertstr(this->result.type, "int32");

    test_assert(corto_delete(s) == 0);
    test_assert(corto_delete(a) == 0);

}

void test_Subscribe_tc_subscribeFromRoot(
    test_Subscribe this)
{
    corto_int32 *a = corto_createChild(root_o, "a", corto_int32_o);
    test_assert(a != NULL);

    corto_subscriber s = corto_subscribe("*")
        .from("/")
        .instance(this)
        .callback(subscribeResultTest);
    test_assert(s != NULL);

    this->triggered = FALSE;

    corto_update(a);

    test_assertstr(this->result.id, "a");
    test_assertstr(this->result.parent, ".");
    test_assertstr(this->result.type, "int32");

    test_assert(corto_delete(s) == 0);
    test_assert(corto_delete(a) == 0);

}

void test_Subscribe_tc_subscribeFromScope(
    test_Subscribe this)
{
    corto_object scope = corto_createChild(root_o, "scope", corto_void_o);
    corto_int32 *a = corto_createChild(scope, "a", corto_int32_o);
    test_assert(a != NULL);

    corto_subscriber s = corto_subscribe("*")
        .from("/scope")
        .instance(this)
        .callback(subscribeResultTest);
    test_assert(s != NULL);

    this->triggered = FALSE;

    corto_update(a);

    test_assertstr(this->result.id, "a");
    test_assertstr(this->result.parent, ".");
    test_assertstr(this->result.type, "int32");

    test_assert(corto_delete(s) == 0);
    test_assert(corto_delete(scope) == 0);

}

void test_Subscribe_tc_subscribeFromScopeNoInitialSlash(
    test_Subscribe this)
{
    corto_object scope = corto_createChild(root_o, "scope", corto_void_o);
    corto_int32 *a = corto_createChild(scope, "a", corto_int32_o);
    test_assert(a != NULL);

    corto_subscriber s = corto_subscribe("*")
        .from("scope")
        .instance(this)
        .callback(subscribeResultTest);
    test_assert(s != NULL);

    this->triggered = FALSE;

    corto_update(a);

    test_assertstr(this->result.id, "a");
    test_assertstr(this->result.parent, ".");
    test_assertstr(this->result.type, "int32");

    test_assert(corto_delete(s) == 0);
    test_assert(corto_delete(scope) == 0);

}

void subscribeInvertCaseOnUpdate(corto_subscriberEvent *e)
{
    test_Subscribe this = e->instance;
    this->triggered = TRUE;
}

void test_Subscribe_tc_subscribeInvertCase(
    test_Subscribe this)
{
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

}

void subscribeInvertCaseFilterOnUpdate(corto_subscriberEvent *e)
{
    test_Subscribe this = e->instance;
    this->triggered = TRUE;
}

void test_Subscribe_tc_subscribeInvertCaseFilter(
    test_Subscribe this)
{
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

}

void subscribeInvertCaseFilterFromPublishOnUpdate(corto_subscriberEvent *e)
{
    test_Subscribe this = e->instance;
    this->triggered = TRUE;
}

void test_Subscribe_tc_subscribeInvertCaseFilterFromPublish(
    test_Subscribe this)
{
    corto_subscriber s = corto_subscribe("XY?").from("/a")
      .instance(this)
      .callback(subscribeInvertCaseFilterFromPublishOnUpdate);

    test_assert(s != NULL);

    test_assert(corto_publish(CORTO_ON_UPDATE, "/a/xyz", "void", NULL, 0) == 0);

    test_assert(this->triggered == TRUE);

    test_assert(corto_delete(s) == 0);

}

void subscribeInvertCaseFromPublishOnUpdate(corto_subscriberEvent *e)
{
    test_Subscribe this = e->instance;
    this->triggered = TRUE;
}

void test_Subscribe_tc_subscribeInvertCaseFromPublish(
    test_Subscribe this)
{
    corto_subscriber s = corto_subscribe("XYZ").from("/a")
      .instance(this)
      .callback(subscribeInvertCaseFromPublishOnUpdate);

    test_assert(s != NULL);

    test_assert(corto_publish(CORTO_ON_UPDATE, "/a/xyz", "void", NULL, 0) == 0);

    test_assert(this->triggered == TRUE);

    test_assert(corto_delete(s) == 0);

}

void subscribeInvertCaseParentOnUpdate(corto_subscriberEvent *e)
{
    test_Subscribe this = e->instance;
    this->triggered = TRUE;
}

void test_Subscribe_tc_subscribeInvertCaseParent(
    test_Subscribe this)
{
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

}

void subscribeInvertCaseParentFromPublishOnUpdate(corto_subscriberEvent *e)
{
    test_Subscribe this = e->instance;
    this->triggered = TRUE;
}

void test_Subscribe_tc_subscribeInvertCaseParentFromPublish(
    test_Subscribe this)
{
    corto_subscriber s = corto_subscribe("xyz").from("/A")
      .instance(this)
      .callback(subscribeInvertCaseParentFromPublishOnUpdate);

    test_assert(s != NULL);

    test_assert(corto_publish(CORTO_ON_UPDATE, "/a/xyz", "void", NULL, 0) == 0);

    test_assert(this->triggered == TRUE);

    test_assert(corto_delete(s) == 0);

}

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

void test_Subscribe_tc_subscribeMultiDifferentParent(
    test_Subscribe this)
{
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

}

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

void test_Subscribe_tc_subscribeMultiDifferentParentVirtual(
    test_Subscribe this)
{
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

}

void tc_subscribeNestedIdFromRootOnUpdate(corto_subscriberEvent *e)
{
    test_Subscribe this = e->instance;
    this->triggered = TRUE;
}

void test_Subscribe_tc_subscribeNestedIdFromRoot(
    test_Subscribe this)
{
    corto_subscriber s = corto_subscribe("A/XYZ").from("/")
      .instance(this)
      .callback(tc_subscribeNestedIdFromRootOnUpdate);

    test_assert(corto_publish(CORTO_ON_UPDATE, "/A/XYZ", "void", NULL, 0) == 0);

    test_assert(this->triggered == TRUE);

    test_assert(corto_delete(s) == 0);

}

void tc_subscribeNestedScopeFromRootOnUpdate(corto_subscriberEvent *e)
{
    test_Subscribe this = e->instance;
    this->triggered = TRUE;
}

void test_Subscribe_tc_subscribeNestedScopeFromRoot(
    test_Subscribe this)
{
    corto_subscriber s = corto_subscribe("A/*").from("/")
      .instance(this)
      .callback(tc_subscribeNestedScopeFromRootOnUpdate);
    test_assert(corto_publish(CORTO_ON_UPDATE, "/A/XYZ", "void", NULL, 0) == 0);
    test_assert(this->triggered == TRUE);
    test_assert(corto_delete(s) == 0);
}

void tc_subscribeOwnerSet(corto_subscriberEvent *e)
{
    test_Subscribe this = e->instance;
    corto_ptr_setref(&this->owner, e->data.owner);
}

void test_Subscribe_tc_subscribeOwnerSet(
    test_Subscribe this)
{
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

}

void test_Subscribe_tc_subscribePartialMatchingParent(
    test_Subscribe this)
{
    corto_subscriber s = corto_subscribe("/").from("/foo")
      .instance(this)
      .callback(tc_subscribeNestedScopeFromRootOnUpdate);

    test_assert(this->triggered == FALSE);

    test_assert(corto_publish(CORTO_ON_UPDATE, "/foobar", "void", NULL, 0) == 0);

    test_assert(this->triggered == FALSE);

    test_assert(corto_delete(s) == 0);

}

void test_Subscribe_tc_subscribePartialMatchingParentObject(
    test_Subscribe this)
{
    corto_object foobar = corto_createChild(root_o, "foobar", corto_void_o);
    test_assert(foobar != NULL);

    corto_subscriber s = corto_subscribe("/").from("/foo")
      .instance(this)
      .callback(tc_subscribeNestedScopeFromRootOnUpdate);

    test_assert(this->triggered == FALSE);

    test_assert(corto_update(foobar) == 0);

    test_assert(this->triggered == FALSE);

    test_assert(corto_delete(s) == 0);
}

