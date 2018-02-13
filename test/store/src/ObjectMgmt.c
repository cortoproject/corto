/* This is a managed file. Do not delete this comment. */

#include <include/test.h>
void test_ObjectMgmt_setup(
    test_ObjectMgmt this)
{
    this->prevAttr = corto_set_attr(CORTO_ATTR_DEFAULT);
    *test_initCalled_o = 0;
    *test_constructCalled_o = 0;
    *test_destructCalled_o = 0;
}

void test_ObjectMgmt_tc_createChildFoo(
    test_ObjectMgmt this)
{
    test_Foo o = corto_create(root_o, "o", test_Foo_o);
    test_assert(o != NULL);
    test_assert(!strcmp(corto_idof(o), "o"));
    test_assert(corto_parentof(o) == root_o);
    test_assert(corto_typeof(o) == (corto_type)test_Foo_o);
    test_assert(corto_check_state(o, CORTO_DECLARED));
    test_assert(corto_check_state(o, CORTO_VALID));
    test_assert(corto_check_attr(o, CORTO_ATTR_NAMED));
    test_assert(corto_check_attr(o, CORTO_ATTR_WRITABLE));
    test_assert(corto_check_attr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));

    corto_object p = corto_resolve(NULL, "o");
    test_assert(o == p);
    corto_release(p);

    /* Test if constructor is correctly executed */
    test_assert(o->x == 2);
    test_assert(o->y == 4);

    corto_delete(o);

    corto_object q = corto_resolve(NULL, "o");
    test_assert(q == NULL);

    test_assert(*test_initCalled_o == 1);
    test_assert(*test_constructCalled_o == 1);
    test_assert(*test_destructCalled_o == 1);

}

void test_ObjectMgmt_tc_createChildFooAttr0(
    test_ObjectMgmt this)
{

    corto_set_attr(0);
    test_Foo o = corto_create(root_o, "o", test_Foo_o);
    test_assert(o != NULL);
    test_assert(!strcmp(corto_idof(o), "o"));
    test_assert(corto_parentof(o) == root_o);
    test_assert(corto_typeof(o) == (corto_type)test_Foo_o);
    test_assert(corto_check_state(o, CORTO_DECLARED));
    test_assert(corto_check_state(o, CORTO_VALID));
    test_assert(corto_check_attr(o, CORTO_ATTR_NAMED));
    test_assert(!corto_check_attr(o, CORTO_ATTR_WRITABLE));
    test_assert(!corto_check_attr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(!corto_check_attr(o, CORTO_ATTR_PERSISTENT));

    corto_object p = corto_resolve(NULL, "o");
    test_assert(o == p);
    corto_release(p);

    /* Test if constructor is correctly executed */
    test_assert(o->x == 2);
    test_assert(o->y == 4);

    corto_delete(o);

    corto_object q = corto_resolve(NULL, "o");
    test_assert(q == NULL);

    test_assert(*test_initCalled_o == 1);
    test_assert(*test_constructCalled_o == 1);
    test_assert(*test_destructCalled_o == 1);

}

void test_ObjectMgmt_tc_createChildInitFail(
    test_ObjectMgmt this)
{

    corto_object o = corto_create(root_o, "o", test_Bar_o);
    test_assert(o == NULL);
    test_assert(corto_catch());
}

void test_ObjectMgmt_tc_createChildInt(
    test_ObjectMgmt this)
{

    corto_object o = corto_create(root_o, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(!strcmp(corto_idof(o), "o"));
    test_assert(corto_parentof(o) == root_o);
    test_assert(corto_typeof(o) == (corto_type)corto_int32_o);
    test_assert(corto_check_state(o, CORTO_DECLARED));
    test_assert(corto_check_state(o, CORTO_VALID));
    test_assert(corto_check_attr(o, CORTO_ATTR_NAMED));
    test_assert(corto_check_attr(o, CORTO_ATTR_WRITABLE));
    test_assert(corto_check_attr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));

    corto_object p = corto_resolve(NULL, "o");
    test_assert(o == p);
    corto_release(p);

    corto_delete(o);

    corto_object q = corto_resolve(NULL, "o");
    test_assert(q == NULL);

}

void test_ObjectMgmt_tc_createChildIntAttr0(
    test_ObjectMgmt this)
{

    corto_set_attr(0);
    corto_object o = corto_create(root_o, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(!strcmp(corto_idof(o), "o"));
    test_assert(corto_parentof(o) == root_o);
    test_assert(corto_typeof(o) == (corto_type)corto_int32_o);
    test_assert(corto_check_state(o, CORTO_DECLARED));
    test_assert(corto_check_state(o, CORTO_VALID));
    test_assert(corto_check_attr(o, CORTO_ATTR_NAMED));
    test_assert(!corto_check_attr(o, CORTO_ATTR_WRITABLE));
    test_assert(!corto_check_attr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(!corto_check_attr(o, CORTO_ATTR_PERSISTENT));

    corto_object p = corto_resolve(NULL, "o");
    test_assert(o == p);
    corto_release(p);

    corto_delete(o);

    corto_object q = corto_resolve(NULL, "o");
    test_assert(q == NULL);

}

void test_ObjectMgmt_tc_createChildInvalidType(
    test_ObjectMgmt this)
{

    corto_type t = corto_type(corto_int__create(root_o, "invalid", CORTO_WIDTH_8, 0, 0));
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_int_o));
    test_assert(corto_check_state(t, CORTO_DECLARED));
    test_assert(corto_check_state(t, CORTO_VALID));
    test_assert(corto_check_attr(t, CORTO_ATTR_NAMED));
    test_assert(corto_check_attr(t, CORTO_ATTR_WRITABLE));
    test_assert(corto_check_attr(t, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_check_attr(t, CORTO_ATTR_PERSISTENT));

    corto_invalidate(t);
    test_assert(!corto_check_state(t, CORTO_VALID));

    corto_object o = corto_create(NULL, NULL, t);
    test_assert(o == NULL);
    test_assert(corto_catch());
}

void test_ObjectMgmt_tc_createChildNested(
    test_ObjectMgmt this)
{

    test_Foo o = corto_create(root_o, "o", test_Foo_o);
    test_assert(o != NULL);
    test_assert(!strcmp(corto_idof(o), "o"));
    test_assert(corto_parentof(o) == root_o);
    test_assert(corto_typeof(o) == (corto_type)test_Foo_o);
    test_assert(corto_check_state(o, CORTO_DECLARED));
    test_assert(corto_check_state(o, CORTO_VALID));
    test_assert(corto_check_attr(o, CORTO_ATTR_NAMED));
    test_assert(corto_check_attr(o, CORTO_ATTR_WRITABLE));
    test_assert(corto_check_attr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));

    test_Foo p = corto_create(o, "p", test_Foo_o);
    test_assert(p != NULL);
    test_assert(!strcmp(corto_idof(p), "p"));
    test_assert(corto_parentof(p) == o);
    test_assert(corto_typeof(p) == (corto_type)test_Foo_o);
    test_assert(corto_check_state(p, CORTO_DECLARED));
    test_assert(corto_check_state(p, CORTO_VALID));
    test_assert(corto_check_attr(p, CORTO_ATTR_NAMED));
    test_assert(corto_check_attr(p, CORTO_ATTR_WRITABLE));
    test_assert(corto_check_attr(p, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_check_attr(p, CORTO_ATTR_PERSISTENT));

    test_Foo q = corto_create(p, "q", test_Foo_o);
    test_assert(p != NULL);
    test_assert(!strcmp(corto_idof(q), "q"));
    test_assert(corto_parentof(q) == p);
    test_assert(corto_typeof(q) == (corto_type)test_Foo_o);
    test_assert(corto_check_state(q, CORTO_DECLARED));
    test_assert(corto_check_state(q, CORTO_VALID));
    test_assert(corto_check_attr(q, CORTO_ATTR_NAMED));
    test_assert(corto_check_attr(q, CORTO_ATTR_WRITABLE));
    test_assert(corto_check_attr(q, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_check_attr(q, CORTO_ATTR_PERSISTENT));

    corto_object _p = corto_resolve(NULL, "o/p");
    test_assert(_p == p);
    corto_release(_p);

    corto_object _q = corto_resolve(NULL, "o/p/q");
    test_assert(_q == q);
    corto_release(_q);

    corto_delete(o);

    test_assert(*test_initCalled_o == 3);
    test_assert(*test_constructCalled_o == 3);
    test_assert(*test_destructCalled_o == 3);

}

void test_ObjectMgmt_tc_createChildNullType(
    test_ObjectMgmt this)
{

    corto_object o = corto_create(root_o, "o", NULL);
    test_assert(o == NULL);
    test_assert(corto_catch());
}

void test_ObjectMgmt_tc_createChildParentStateErr(
    test_ObjectMgmt this)
{

    corto_object o = corto_declare(root_o, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(corto_check_state(o, CORTO_DECLARED));
    test_assert(!corto_check_state(o, CORTO_VALID));

    corto_object p = corto_create(o, "p", test_DefinedParent_o);
    test_assert(p == NULL);
    test_assert(corto_catch());

    corto_object q = test_DefinedParent__create(o, "q", 0);
    test_assert(q == NULL);
    test_assert(corto_catch());

    corto_delete(o);

}

void test_ObjectMgmt_tc_createChildParentTypeErr(
    test_ObjectMgmt this)
{

    corto_object o = corto_declare(root_o, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(corto_check_state(o, CORTO_DECLARED));
    test_assert(!corto_check_state(o, CORTO_VALID));

    corto_object p = corto_create(o, "p", test_VoidParent_o);
    test_assert(p == NULL);
    test_assert(corto_catch());

    corto_object q = test_VoidParent__create(o, "q", 0);
    test_assert(q == NULL);
    test_assert(corto_catch());

    test_assert(corto_delete(o) == 0);
}

void test_ObjectMgmt_tc_createChildVoid(
    test_ObjectMgmt this)
{

    corto_object o = corto_declare(root_o, "o", corto_void_o);
    test_assert(o != NULL);
    test_assert(!strcmp(corto_idof(o), "o"));
    test_assert(corto_parentof(o) == root_o);
    test_assert(corto_typeof(o) == corto_void_o);
    test_assert(corto_check_state(o, CORTO_DECLARED));
    test_assert(corto_check_state(o, CORTO_VALID));
    test_assert(corto_check_attr(o, CORTO_ATTR_NAMED));
    test_assert(!corto_check_attr(o, CORTO_ATTR_WRITABLE));
    test_assert(corto_check_attr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));

    corto_object p = corto_resolve(NULL, "o");
    test_assert(o == p);
    corto_release(p);

    corto_delete(o);

    corto_object q = corto_resolve(NULL, "o");
    test_assert(q == NULL);

}

void test_ObjectMgmt_tc_createChildVoidAttr0(
    test_ObjectMgmt this)
{

    corto_set_attr(0);
    corto_object o = corto_create(root_o, "o", corto_void_o);
    test_assert(o != NULL);
    test_assert(!strcmp(corto_idof(o), "o"));
    test_assert(corto_parentof(o) == root_o);
    test_assert(corto_typeof(o) == corto_void_o);
    test_assert(corto_check_state(o, CORTO_DECLARED));
    test_assert(corto_check_state(o, CORTO_VALID));
    test_assert(corto_check_attr(o, CORTO_ATTR_NAMED));
    test_assert(!corto_check_attr(o, CORTO_ATTR_WRITABLE));
    test_assert(!corto_check_attr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(!corto_check_attr(o, CORTO_ATTR_PERSISTENT));

    corto_object p = corto_resolve(NULL, "o");
    test_assert(o == p);
    corto_release(p);

    corto_delete(o);

    corto_object q = corto_resolve(NULL, "o");
    test_assert(q == NULL);

}

void test_ObjectMgmt_tc_createFoo(
    test_ObjectMgmt this)
{

    test_Foo o = corto_create(NULL, NULL, test_Foo_o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == (corto_type)test_Foo_o);
    test_assert(corto_check_state(o, CORTO_DECLARED));
    test_assert(corto_check_state(o, CORTO_VALID));
    test_assert(!corto_check_attr(o, CORTO_ATTR_NAMED));
    test_assert(corto_check_attr(o, CORTO_ATTR_WRITABLE));
    test_assert(corto_check_attr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(!corto_check_attr(o, CORTO_ATTR_PERSISTENT));

    /* Test if constructor is correctly executed */
    test_assert(o->x == 2);
    test_assert(o->y == 4);

    corto_delete(o);

    test_assert(*test_initCalled_o == 1);
    test_assert(*test_constructCalled_o == 1);
    test_assert(*test_destructCalled_o == 1);

}

void test_ObjectMgmt_tc_createFooAttr0(
    test_ObjectMgmt this)
{

    corto_set_attr(0);
    test_Foo o = corto_create(NULL, NULL, test_Foo_o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == (corto_type)test_Foo_o);
    test_assert(corto_check_state(o, CORTO_DECLARED));
    test_assert(corto_check_state(o, CORTO_VALID));
    test_assert(!corto_check_attr(o, CORTO_ATTR_NAMED));
    test_assert(!corto_check_attr(o, CORTO_ATTR_WRITABLE));
    test_assert(!corto_check_attr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(!corto_check_attr(o, CORTO_ATTR_PERSISTENT));

    /* Test if constructor is correctly executed */
    test_assert(o->x == 2);
    test_assert(o->y == 4);

    corto_delete(o);

    test_assert(*test_initCalled_o == 1);
    test_assert(*test_constructCalled_o == 1);
    test_assert(*test_destructCalled_o == 1);

}

void test_ObjectMgmt_tc_createInitFail(
    test_ObjectMgmt this)
{

    corto_object o = corto_create(NULL, NULL, test_Bar_o);
    test_assert(o == NULL);
    test_assert(corto_catch());
}

void test_ObjectMgmt_tc_createInt(
    test_ObjectMgmt this)
{

    corto_object o = corto_create(NULL, NULL, corto_int32_o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == (corto_type)corto_int32_o);
    test_assert(corto_check_state(o, CORTO_DECLARED));
    test_assert(corto_check_state(o, CORTO_VALID));
    test_assert(!corto_check_attr(o, CORTO_ATTR_NAMED));
    test_assert(corto_check_attr(o, CORTO_ATTR_WRITABLE));
    test_assert(corto_check_attr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(!corto_check_attr(o, CORTO_ATTR_PERSISTENT));
    corto_delete(o);

}

void test_ObjectMgmt_tc_createIntAttr0(
    test_ObjectMgmt this)
{

    corto_set_attr(0);
    corto_object o = corto_create(NULL, NULL, corto_int32_o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == (corto_type)corto_int32_o);
    test_assert(corto_check_state(o, CORTO_DECLARED));
    test_assert(corto_check_state(o, CORTO_VALID));
    test_assert(!corto_check_attr(o, CORTO_ATTR_NAMED));
    test_assert(!corto_check_attr(o, CORTO_ATTR_WRITABLE));
    test_assert(!corto_check_attr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(!corto_check_attr(o, CORTO_ATTR_PERSISTENT));
    corto_delete(o);

}

void test_ObjectMgmt_tc_createInvalidType(
    test_ObjectMgmt this)
{

    corto_type t = corto_type(corto_int__create(root_o, "invalid", CORTO_WIDTH_8, 0, 0));
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_int_o));
    test_assert(corto_check_state(t, CORTO_DECLARED));
    test_assert(corto_check_state(t, CORTO_VALID));
    test_assert(corto_check_attr(t, CORTO_ATTR_NAMED));
    test_assert(corto_check_attr(t, CORTO_ATTR_WRITABLE));
    test_assert(corto_check_attr(t, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_check_attr(t, CORTO_ATTR_PERSISTENT));

    corto_invalidate(t);
    test_assert(!corto_check_state(t, CORTO_VALID));

    corto_object o = corto_create(NULL, NULL, t);
    test_assert(o == NULL);
    test_assert(corto_catch());

}

corto_void onCreateNested(corto_observer_event *e)
{
    test_EventCount *counter = e->instance;

    if (e->event & CORTO_DECLARE) counter->declareCount++;
    if (e->event & CORTO_DEFINE) counter->defineCount++;
    if (e->event & CORTO_UPDATE) counter->updateCount++;
    if (e->event & CORTO_DELETE) counter->deleteCount++;
    if (e->event & CORTO_RESUME) counter->resumeCount++;
    if (e->event & CORTO_SUSPEND) counter->suspendCount++;
}

void test_ObjectMgmt_tc_createNested(
    test_ObjectMgmt this)
{
    test_EventCount *counter = test_EventCount__create(NULL, NULL, 0, 0, 0, 0, 0, 0);
    corto_observer o = corto_observe(CORTO_ON_ANY | CORTO_ON_TREE, root_o)
        .instance(counter)
        .callback(onCreateNested);
    test_assert(o != NULL);

    /* Reset counter so aligned objects don't pollute result */
    counter->declareCount = 0;
    counter->defineCount = 0;
    counter->updateCount = 0;
    counter->deleteCount = 0;

    corto_object c = corto_create(root_o, "a/b/c", corto_int32_o);
    test_assert(c != NULL);
    test_assert(corto_typeof(c) == corto_type(corto_int32_o));
    test_assertstr(corto_idof(c), "c");
    test_assert(corto_check_state(c, CORTO_DECLARED));
    test_assert(corto_check_state(c, CORTO_VALID));

    corto_object b = corto_lookup(root_o, "a/b");
    test_assert(b != NULL);
    test_assert(corto_parentof(c) == b);
    test_assert(corto_typeof(b) == corto_type(corto_unknown_o));
    test_assertstr(corto_idof(b), "b");
    test_assert(corto_check_state(b, CORTO_DECLARED));
    test_assert(!corto_check_state(b, CORTO_VALID));

    corto_object a = corto_lookup(root_o, "a");
    test_assert(a != NULL);
    test_assert(corto_parentof(b) == a);
    test_assert(corto_typeof(a) == corto_type(corto_unknown_o));
    test_assertstr(corto_idof(a), "a");
    test_assert(corto_check_state(a, CORTO_DECLARED));
    test_assert(!corto_check_state(a, CORTO_VALID));

    test_assert(corto_delete(a) == 0);
    test_assert(corto_delete(o) == 0);

    test_assertint(counter->declareCount, 3);
    test_assertint(counter->defineCount, 1);
    test_assertint(counter->updateCount, 0);
    test_assertint(counter->deleteCount, 1);

}

void test_ObjectMgmt_tc_createNestedLastFail(
    test_ObjectMgmt this)
{
    test_EventCount *counter = test_EventCount__create(NULL, NULL, 0, 0, 0, 0, 0, 0);
    corto_observer o = corto_observe(CORTO_ON_ANY | CORTO_ON_TREE, root_o)
        .instance(counter)
        .callback(onCreateNested);
    test_assert(o != NULL);

    /* Reset counter so aligned objects don't pollute result */
    counter->declareCount = 0;
    counter->defineCount = 0;
    counter->updateCount = 0;
    counter->deleteCount = 0;

    corto_object c = corto_create(root_o, "a/b/c", test_NestedConstructFail_o);
    test_assert(c == NULL);
    test_assert(corto_lookup(root_o, "a/b") == NULL);
    test_assert(corto_lookup(root_o, "a") == NULL);

    test_assert(corto_delete(o) == 0);

    test_assertint(counter->declareCount, 3);
    test_assertint(counter->defineCount, 0);
    test_assertint(counter->updateCount, 0);
    test_assertint(counter->deleteCount, 0);

}

void test_ObjectMgmt_tc_createNullType(
    test_ObjectMgmt this)
{

    corto_object o = corto_create(NULL, NULL, NULL);
    test_assert(o == NULL);
    test_assert(corto_catch());
}

void test_ObjectMgmt_tc_createVoid(
    test_ObjectMgmt this)
{

    corto_object o = corto_create(NULL, NULL, corto_void_o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_void_o);
    test_assert(corto_check_state(o, CORTO_DECLARED));
    test_assert(corto_check_state(o, CORTO_VALID));
    test_assert(!corto_check_attr(o, CORTO_ATTR_NAMED));
    test_assert(!corto_check_attr(o, CORTO_ATTR_WRITABLE));
    test_assert(corto_check_attr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(!corto_check_attr(o, CORTO_ATTR_PERSISTENT));
    corto_delete(o);

}

void test_ObjectMgmt_tc_createVoidAttr0(
    test_ObjectMgmt this)
{

    corto_set_attr(0);
    corto_object o = corto_create(NULL, NULL, corto_void_o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == (corto_type)corto_void_o);
    test_assert(corto_check_state(o, CORTO_DECLARED));
    test_assert(corto_check_state(o, CORTO_VALID));
    test_assert(!corto_check_attr(o, CORTO_ATTR_NAMED));
    test_assert(!corto_check_attr(o, CORTO_ATTR_WRITABLE));
    test_assert(!corto_check_attr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(!corto_check_attr(o, CORTO_ATTR_PERSISTENT));
    corto_delete(o);

}

void test_ObjectMgmt_tc_declareChildFoo(
    test_ObjectMgmt this)
{

    test_Foo o = corto_declare(root_o, "o", test_Foo_o);
    test_assert(o != NULL);
    test_assert(!strcmp(corto_idof(o), "o"));
    test_assert(corto_parentof(o) == root_o);
    test_assert(corto_typeof(o) == (corto_type)test_Foo_o);
    test_assert(corto_check_state(o, CORTO_DECLARED));
    test_assert(!corto_check_state(o, CORTO_VALID));
    test_assert(corto_check_attr(o, CORTO_ATTR_NAMED));
    test_assert(corto_check_attr(o, CORTO_ATTR_WRITABLE));
    test_assert(corto_check_attr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));

    /* Test if initializer is correctly executed */
    test_assert(o->x == 1);
    test_assert(o->y == 2);

    corto_object p = corto_resolve(NULL, "o");
    test_assert(o == p);
    corto_release(p);

    corto_delete(o);

    corto_object q = corto_resolve(NULL, "o");
    test_assert(q == NULL);

    test_assert(*test_initCalled_o == 1);
    test_assert(*test_constructCalled_o == 0);
    test_assert(*test_destructCalled_o == 0);

}

void test_ObjectMgmt_tc_declareChildFooAttr0(
    test_ObjectMgmt this)
{

    corto_set_attr(0);
    test_Foo o = corto_declare(root_o, "o", test_Foo_o);
    test_assert(o != NULL);
    test_assert(!strcmp(corto_idof(o), "o"));
    test_assert(corto_parentof(o) == root_o);
    test_assert(corto_typeof(o) == (corto_type)test_Foo_o);
    test_assert(corto_check_state(o, CORTO_DECLARED));
    test_assert(!corto_check_state(o, CORTO_VALID));
    test_assert(corto_check_attr(o, CORTO_ATTR_NAMED));
    test_assert(!corto_check_attr(o, CORTO_ATTR_WRITABLE));
    test_assert(!corto_check_attr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(!corto_check_attr(o, CORTO_ATTR_PERSISTENT));

    /* Test if initializer is correctly executed */
    test_assert(o->x == 1);
    test_assert(o->y == 2);

    corto_object p = corto_resolve(NULL, "o");
    test_assert(o == p);
    corto_release(p);

    corto_delete(o);

    corto_object q = corto_resolve(NULL, "o");
    test_assert(q == NULL);

    test_assert(*test_initCalled_o == 1);
    test_assert(*test_constructCalled_o == 0);
    test_assert(*test_destructCalled_o == 0);

}

void test_ObjectMgmt_tc_declareChildInitFail(
    test_ObjectMgmt this)
{

    corto_object o = corto_declare(root_o, "o", test_Bar_o);
    test_assert(o == NULL);
    test_assert(corto_catch());
}

void test_ObjectMgmt_tc_declareChildInt(
    test_ObjectMgmt this)
{

    corto_object o = corto_declare(root_o, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(!strcmp(corto_idof(o), "o"));
    test_assert(corto_parentof(o) == root_o);
    test_assert(corto_typeof(o) == (corto_type)corto_int32_o);
    test_assert(corto_check_state(o, CORTO_DECLARED));
    test_assert(!corto_check_state(o, CORTO_VALID));
    test_assert(corto_check_attr(o, CORTO_ATTR_NAMED));
    test_assert(corto_check_attr(o, CORTO_ATTR_WRITABLE));
    test_assert(corto_check_attr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));

    corto_object p = corto_resolve(NULL, "o");
    test_assert(o == p);
    corto_release(p);

    p = corto_declare(root_o, "o", corto_int32_o);
    test_assert(o == p);
    corto_delete(p);

    corto_delete(o);

    corto_object q = corto_resolve(NULL, "o");
    test_assert(q == NULL);

}

void test_ObjectMgmt_tc_declareChildIntAttr0(
    test_ObjectMgmt this)
{

    corto_set_attr(0);
    corto_object o = corto_declare(root_o, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(!strcmp(corto_idof(o), "o"));
    test_assert(corto_parentof(o) == root_o);
    test_assert(corto_typeof(o) == (corto_type)corto_int32_o);
    test_assert(corto_check_state(o, CORTO_DECLARED));
    test_assert(!corto_check_state(o, CORTO_VALID));
    test_assert(corto_check_attr(o, CORTO_ATTR_NAMED));
    test_assert(!corto_check_attr(o, CORTO_ATTR_WRITABLE));
    test_assert(!corto_check_attr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(!corto_check_attr(o, CORTO_ATTR_PERSISTENT));

    corto_object p = corto_resolve(NULL, "o");
    test_assert(o == p);
    corto_release(p);

    corto_delete(o);

    corto_object q = corto_resolve(NULL, "o");
    test_assert(q == NULL);

}

void test_ObjectMgmt_tc_declareChildInvalidType(
    test_ObjectMgmt this)
{

    corto_type t = corto_type(corto_int__create(root_o, "invalid", CORTO_WIDTH_8, 0, 0));
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_int_o));
    test_assert(corto_check_state(t, CORTO_DECLARED));
    test_assert(corto_check_state(t, CORTO_VALID));
    test_assert(corto_check_attr(t, CORTO_ATTR_NAMED));
    test_assert(corto_check_attr(t, CORTO_ATTR_WRITABLE));
    test_assert(corto_check_attr(t, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_check_attr(t, CORTO_ATTR_PERSISTENT));

    corto_invalidate(t);
    test_assert(!corto_check_state(t, CORTO_VALID));

    corto_object o = corto_declare(root_o, "foo", t);
    test_assert(o == NULL);
    test_assert(corto_catch());
}

void test_ObjectMgmt_tc_declareChildNullType(
    test_ObjectMgmt this)
{

    corto_object o = corto_declare(root_o, "o", NULL);
    test_assert(o == NULL);
    test_assert(corto_catch());
}

void test_ObjectMgmt_tc_declareChildParentStateErr(
    test_ObjectMgmt this)
{

    corto_object o = corto_declare(root_o, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(corto_check_state(o, CORTO_DECLARED));
    test_assert(!corto_check_state(o, CORTO_VALID));

    corto_object p = corto_declare(o, "p", test_DefinedParent_o);
    test_assert(p == NULL);
    test_assert(corto_catch());

    corto_object q = corto_declare(o, "q", test_DefinedParent_o);
    test_assert(q == NULL);
    test_assert(corto_catch());

    corto_delete(o);
}

void test_ObjectMgmt_tc_declareChildParentTypeErr(
    test_ObjectMgmt this)
{

    corto_object o = corto_declare(root_o, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(corto_check_state(o, CORTO_DECLARED));
    test_assert(!corto_check_state(o, CORTO_VALID));

    corto_object p = corto_declare(o, "p", test_VoidParent_o);
    test_assert(p == NULL);
    test_assert(corto_catch());

    corto_object q = corto_declare(o, "q", test_VoidParent_o);
    test_assert(q == NULL);
    test_assert(corto_catch());

    corto_delete(o);

}

void test_ObjectMgmt_tc_declareChildVoid(
    test_ObjectMgmt this)
{

    corto_object o = corto_declare(root_o, "o", corto_void_o);
    test_assert(o != NULL);
    test_assert(!strcmp(corto_idof(o), "o"));
    test_assert(corto_parentof(o) == root_o);
    test_assert(corto_typeof(o) == corto_void_o);
    test_assert(corto_check_state(o, CORTO_DECLARED));
    test_assert(corto_check_state(o, CORTO_VALID));
    test_assert(corto_check_attr(o, CORTO_ATTR_NAMED));
    test_assert(!corto_check_attr(o, CORTO_ATTR_WRITABLE));
    test_assert(corto_check_attr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_check_attr(o, CORTO_ATTR_PERSISTENT));

    corto_object p = corto_resolve(NULL, "o");
    test_assert(o == p);
    corto_release(p);

    corto_delete(o);

    corto_object q = corto_resolve(NULL, "o");
    test_assert(q == NULL);

}

void test_ObjectMgmt_tc_declareChildVoidAttr0(
    test_ObjectMgmt this)
{

    corto_set_attr(0);
    corto_object o = corto_declare(root_o, "o", corto_void_o);
    test_assert(o != NULL);
    test_assert(!strcmp(corto_idof(o), "o"));
    test_assert(corto_parentof(o) == root_o);
    test_assert(corto_typeof(o) == corto_void_o);
    test_assert(corto_check_state(o, CORTO_DECLARED));
    test_assert(corto_check_state(o, CORTO_VALID));
    test_assert(corto_check_attr(o, CORTO_ATTR_NAMED));
    test_assert(!corto_check_attr(o, CORTO_ATTR_WRITABLE));
    test_assert(!corto_check_attr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(!corto_check_attr(o, CORTO_ATTR_PERSISTENT));

    corto_object p = corto_resolve(NULL, "o");
    test_assert(o == p);
    corto_release(p);

    corto_delete(o);

    corto_object q = corto_resolve(NULL, "o");
    test_assert(q == NULL);

}

void test_ObjectMgmt_tc_declareExistingWithParentState(
    test_ObjectMgmt this)
{
    corto_struct s = corto_declare(root_o, "s", corto_struct_o);
    test_assert(s != NULL);

    corto_member m = corto_member__create(s, "m", corto_type(corto_uint32_o), CORTO_GLOBAL);
    test_assert(m != NULL);

    corto_int16 ret = corto_define(s);
    test_assert(ret == 0);

    /* Validate I can redeclare member after struct has been defined */
    corto_member n = corto_declare(s, "m", corto_member_o);
    test_assert(n != NULL);
    test_assert(corto_check_state(n, CORTO_VALID));

    ret = corto_define(n);
    test_assert(ret == 0);

    corto_delete(n);
    corto_delete(m);
    corto_delete(s);

}

void test_ObjectMgmt_tc_declareFoo(
    test_ObjectMgmt this)
{

    test_Foo o = corto_declare(NULL, NULL, test_Foo_o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == (corto_type)test_Foo_o);
    test_assert(corto_check_state(o, CORTO_DECLARED));
    test_assert(!corto_check_state(o, CORTO_VALID));
    test_assert(!corto_check_attr(o, CORTO_ATTR_NAMED));
    test_assert(corto_check_attr(o, CORTO_ATTR_WRITABLE));
    test_assert(corto_check_attr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(!corto_check_attr(o, CORTO_ATTR_PERSISTENT));

    /* Test if initializer is correctly executed */
    test_assert(o->x == 1);
    test_assert(o->y == 2);

    corto_delete(o);

    test_assert(*test_initCalled_o == 1);
    test_assert(*test_constructCalled_o == 0);
    test_assert(*test_destructCalled_o == 0);

}

void test_ObjectMgmt_tc_declareFooAttr0(
    test_ObjectMgmt this)
{

    corto_set_attr(0);
    test_Foo o = corto_declare(NULL, NULL, test_Foo_o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == (corto_type)test_Foo_o);
    test_assert(corto_check_state(o, CORTO_DECLARED));
    test_assert(!corto_check_state(o, CORTO_VALID));
    test_assert(!corto_check_attr(o, CORTO_ATTR_NAMED));
    test_assert(!corto_check_attr(o, CORTO_ATTR_WRITABLE));
    test_assert(!corto_check_attr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(!corto_check_attr(o, CORTO_ATTR_PERSISTENT));

    /* Test if initializer is correctly executed */
    test_assert(o->x == 1);
    test_assert(o->y == 2);

    corto_delete(o);

    test_assert(*test_initCalled_o == 1);
    test_assert(*test_constructCalled_o == 0);
    test_assert(*test_destructCalled_o == 0);
}

void test_ObjectMgmt_tc_declareInitFail(
    test_ObjectMgmt this)
{

    corto_object o = corto_declare(NULL, NULL, test_Bar_o);
    test_assert(o == NULL);
    test_assert(corto_catch());
}

void test_ObjectMgmt_tc_declareInt(
    test_ObjectMgmt this)
{

    corto_object o = corto_declare(NULL, NULL, corto_int32_o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == (corto_type)corto_int32_o);
    test_assert(corto_check_state(o, CORTO_DECLARED));
    test_assert(!corto_check_state(o, CORTO_VALID));
    test_assert(!corto_check_attr(o, CORTO_ATTR_NAMED));
    test_assert(corto_check_attr(o, CORTO_ATTR_WRITABLE));
    test_assert(corto_check_attr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(!corto_check_attr(o, CORTO_ATTR_PERSISTENT));
    corto_delete(o);

}

void test_ObjectMgmt_tc_declareIntAttr0(
    test_ObjectMgmt this)
{
    corto_set_attr(0);
    corto_object o = corto_declare(NULL, NULL, corto_int32_o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == (corto_type)corto_int32_o);
    test_assert(corto_check_state(o, CORTO_DECLARED));
    test_assert(!corto_check_state(o, CORTO_VALID));
    test_assert(!corto_check_attr(o, CORTO_ATTR_NAMED));
    test_assert(!corto_check_attr(o, CORTO_ATTR_WRITABLE));
    test_assert(!corto_check_attr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(!corto_check_attr(o, CORTO_ATTR_PERSISTENT));
    corto_delete(o);

}

void test_ObjectMgmt_tc_declareInvalidType(
    test_ObjectMgmt this)
{
    corto_type t = corto_type(corto_int__create(root_o, "invalid", CORTO_WIDTH_8, 0, 0));
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_int_o));
    test_assert(corto_check_state(t, CORTO_DECLARED));
    test_assert(corto_check_state(t, CORTO_VALID));
    test_assert(corto_check_attr(t, CORTO_ATTR_NAMED));
    test_assert(corto_check_attr(t, CORTO_ATTR_WRITABLE));
    test_assert(corto_check_attr(t, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_check_attr(t, CORTO_ATTR_PERSISTENT));

    corto_invalidate(t);
    test_assert(!corto_check_state(t, CORTO_VALID));

    corto_object o = corto_declare(NULL, NULL, t);
    test_assert(o == NULL);
    test_assert(corto_catch());
}

corto_void onDeclareNested(corto_observer_event *e)
{
    test_EventCount *counter = e->instance;

    if (e->event & CORTO_DECLARE) counter->declareCount++;
    if (e->event & CORTO_DEFINE) counter->defineCount++;
    if (e->event & CORTO_UPDATE) counter->updateCount++;
    if (e->event & CORTO_DELETE) counter->deleteCount++;
    if (e->event & CORTO_RESUME) counter->resumeCount++;
    if (e->event & CORTO_SUSPEND) counter->suspendCount++;
}

void test_ObjectMgmt_tc_declareNested(
    test_ObjectMgmt this)
{
    test_EventCount *counter = test_EventCount__create(NULL, NULL, 0, 0, 0, 0, 0, 0);
    corto_observer o = corto_observe(CORTO_ON_ANY | CORTO_ON_TREE, root_o)
        .instance(counter)
        .callback(onDeclareNested);
    test_assert(o != NULL);

    /* Reset counter so aligned objects don't pollute result */
    counter->declareCount = 0;
    counter->defineCount = 0;
    counter->updateCount = 0;
    counter->deleteCount = 0;

    corto_object c = corto_declare(root_o, "a/b/c", corto_int32_o);
    test_assert(c != NULL);
    test_assert(corto_typeof(c) == corto_type(corto_int32_o));
    test_assertstr(corto_idof(c), "c");
    test_assert(corto_check_state(c, CORTO_DECLARED));
    test_assert(!corto_check_state(c, CORTO_VALID));

    corto_object b = corto_lookup(root_o, "a/b");
    test_assert(b != NULL);
    test_assert(corto_parentof(c) == b);
    test_assert(corto_typeof(b) == corto_type(corto_unknown_o));
    test_assertstr(corto_idof(b), "b");
    test_assert(corto_check_state(b, CORTO_DECLARED));
    test_assert(!corto_check_state(b, CORTO_VALID));

    corto_object a = corto_lookup(root_o, "a");
    test_assert(a != NULL);
    test_assert(corto_parentof(b) == a);
    test_assert(corto_typeof(a) == corto_type(corto_unknown_o));
    test_assertstr(corto_idof(a), "a");
    test_assert(corto_check_state(a, CORTO_DECLARED));
    test_assert(!corto_check_state(a, CORTO_VALID));

    test_assert(corto_delete(a) == 0);
    test_assert(corto_delete(o) == 0);

    test_assertint(counter->declareCount, 3);
    test_assertint(counter->defineCount, 0);
    test_assertint(counter->updateCount, 0);
    test_assertint(counter->deleteCount, 0);
}

void test_ObjectMgmt_tc_declareNestedFirstFail(
    test_ObjectMgmt this)
{
    test_EventCount *counter = test_EventCount__create(NULL, NULL, 0, 0, 0, 0, 0, 0);
    corto_observer o = corto_observe(CORTO_ON_ANY | CORTO_ON_TREE, root_o)
        .instance(counter)
        .callback(onDeclareNested);
    test_assert(o != NULL);

    /* Trick: Create a tableinstance that only allows int32 objects in its scope,
     * so that the first created object will fail, as it will be a void. */
    corto_tableinstance myRoot = corto_declare(root_o, "myRoot", corto_tableinstance_o);
    test_assert(myRoot != NULL);
    corto_set_ref(&myRoot->type, corto_int32_o);
    test_assert(corto_define(myRoot) == 0);

    /* Reset counter so aligned objects don't pollute result */
    counter->declareCount = 0;
    counter->defineCount = 0;
    counter->updateCount = 0;
    counter->deleteCount = 0;

    corto_object c = corto_declare(root_o, "myRoot/a/b/c", corto_int32_o);
    test_assert(c == NULL);
    test_assert(corto_catch());

    test_assert(corto_lookup(root_o, "myRoot/a/b") == NULL);
    test_assert(corto_lookup(root_o, "myRoot/a") == NULL);
    test_assert(corto_delete(o) == 0);

    test_assertint(counter->declareCount, 0);
    test_assertint(counter->defineCount, 0);
    test_assertint(counter->updateCount, 0);
    test_assertint(counter->deleteCount, 0);
}

void test_ObjectMgmt_tc_declareNestedLastFail(
    test_ObjectMgmt this)
{
    test_EventCount *counter = test_EventCount__create(NULL, NULL, 0, 0, 0, 0, 0, 0);
    corto_observer o = corto_observe(CORTO_ON_ANY | CORTO_ON_TREE, root_o)
        .instance(counter)
        .callback(onDeclareNested);
    test_assert(o != NULL);

    /* Reset counter so aligned objects don't pollute result */
    counter->declareCount = 0;
    counter->defineCount = 0;
    counter->updateCount = 0;
    counter->deleteCount = 0;

    corto_object c = corto_declare(root_o, "a/b/c", test_NestedInitFail_o);
    test_assert(c == NULL);
    test_assert(corto_catch());

    test_assert(corto_lookup(root_o, "a/b") == NULL);
    test_assert(corto_lookup(root_o, "a") == NULL);

    test_assert(corto_delete(o) == 0);

    test_assertint(counter->declareCount, 2);
    test_assertint(counter->defineCount, 0);
    test_assertint(counter->updateCount, 0);
    test_assertint(counter->deleteCount, 0);
}

void test_ObjectMgmt_tc_declareNestedSecondFail(
    test_ObjectMgmt this)
{
    test_EventCount *counter = test_EventCount__create(NULL, NULL, 0, 0, 0, 0, 0, 0);
    corto_observer o = corto_observe(CORTO_ON_ANY | CORTO_ON_TREE, root_o)
        .instance(counter)
        .callback(onDeclareNested);
    test_assert(o != NULL);

    /* Trick: Create a tableinstance that only allows int32 objects in its scope,
     * so that the first created object will fail, as it will be a void. */
    corto_tableinstance myRoot = corto_declare(root_o, "a", corto_tableinstance_o);
    test_assert(myRoot != NULL);
    corto_set_ref(&myRoot->type, corto_int32_o);
    test_assert(corto_define(myRoot) == 0);

    /* Reset counter so aligned objects don't pollute result */
    counter->declareCount = 0;
    counter->defineCount = 0;
    counter->updateCount = 0;
    counter->deleteCount = 0;

    corto_object c = corto_declare(root_o, "a/b/c", corto_int32_o);
    test_assert(c == NULL);
    test_assert(corto_catch());

    test_assert(corto_lookup(root_o, "a/b") == NULL);

    /* A should exist, because it was declared before the statement failed. */
    test_assert(corto_lookup(root_o, "a") != NULL);

    test_assert(corto_delete(o) == 0);

    test_assertint(counter->declareCount, 0);
    test_assertint(counter->defineCount, 0);
    test_assertint(counter->updateCount, 0);
    test_assertint(counter->deleteCount, 0);
}

void test_ObjectMgmt_tc_declareNullType(
    test_ObjectMgmt this)
{

    corto_object o = corto_declare(NULL, NULL, NULL);
    test_assert(o == NULL);
    test_assert(corto_catch());
}

void test_ObjectMgmt_tc_declareOrphan(
    test_ObjectMgmt this)
{
    corto_int16 ret;

    /* Create orphaned object */
    corto_object i = corto(CORTO_DECLARE|CORTO_ORPHAN|CORTO_FORCE_TYPE, {
        .parent = root_o,
        .id = "i",
        .type = corto_int32_o
    });
    test_assert(i != NULL);
    test_assert(corto_check_attr(i, CORTO_ATTR_NAMED));
    test_assertstr(corto_idof(i), "i");
    test_assert(corto_parentof(i) == root_o);
    test_assert(corto_childof(root_o, i));
    test_assert(!corto_isbuiltin(i));
    ret = corto_define(i);
    test_assert(ret == 0);
    /* Object should not be resolvable */
    test_assert(!corto_lookup(root_o, "i"));
    ret = corto_delete(i);
    test_assert(ret == 0);
}

void test_ObjectMgmt_tc_declareScoped(
    test_ObjectMgmt this)
{
    corto_int16 ret;

    /* Create scoped anonymous object (structs are always scoped) */
    corto_struct s = corto_declare(NULL, NULL, corto_struct_o);
    test_assert(s != NULL);
    test_assert(corto_check_attr(s, CORTO_ATTR_NAMED));
    test_assert(corto_idof(s) == NULL);
    test_assert(corto_parentof(s) == NULL);

    /* Create members in scope of anonymous object */
    corto_member x = corto_declare(s, "x", corto_member_o);
    test_assert(x != NULL);
    corto_set_ref(&x->type, corto_int32_o);
    ret = corto_define(x);
    test_assert(ret == 0);

    corto_member y = corto_declare(s, "y", corto_member_o);
    test_assert(y != NULL);
    corto_set_ref(&y->type, corto_int32_o);
    ret = corto_define(y);
    test_assert(ret == 0);

    /* Define struct */
    ret = corto_define(s);
    test_assert(ret == 0);

    /* Test type */
    corto_object p = corto_create(NULL, NULL, s);
    test_assert(p != NULL);
    *(corto_int32*)CORTO_OFFSET(p, x->offset) = 10;
    *(corto_int32*)CORTO_OFFSET(p, y->offset) = 20;
    test_assertstr("{10,20}", corto_serialize_value(p, "text/corto"));

    ret = corto_delete(p);
    test_assert(ret == 0);

    ret = corto_delete(s);
    test_assert(ret == 0);
}

void test_ObjectMgmt_tc_declareVoid(
    test_ObjectMgmt this)
{

    corto_object o = corto_declare(NULL, NULL, corto_void_o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_void_o);
    test_assert(corto_check_state(o, CORTO_DECLARED));
    test_assert(corto_check_state(o, CORTO_VALID));
    test_assert(!corto_check_attr(o, CORTO_ATTR_NAMED));
    test_assert(!corto_check_attr(o, CORTO_ATTR_WRITABLE));
    test_assert(corto_check_attr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(!corto_check_attr(o, CORTO_ATTR_PERSISTENT));
    corto_delete(o);

}

void test_ObjectMgmt_tc_declareVoidAttr0(
    test_ObjectMgmt this)
{

    corto_set_attr(0);
    corto_object o = corto_declare(NULL, NULL, corto_void_o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == (corto_type)corto_void_o);
    test_assert(corto_check_state(o, CORTO_DECLARED));
    test_assert(corto_check_state(o, CORTO_VALID));
    test_assert(!corto_check_attr(o, CORTO_ATTR_NAMED));
    test_assert(!corto_check_attr(o, CORTO_ATTR_WRITABLE));
    test_assert(!corto_check_attr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(!corto_check_attr(o, CORTO_ATTR_PERSISTENT));
    corto_delete(o);

}

void test_ObjectMgmt_tc_defineFoo(
    test_ObjectMgmt this)
{

    test_Foo o = corto_declare(NULL, NULL, test_Foo_o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == (corto_type)test_Foo_o);
    test_assert(o->x == 1);
    test_assert(o->y == 2);
    test_assert(!corto_define(o));
    test_assert(corto_check_state(o, CORTO_DECLARED));
    test_assert(corto_check_state(o, CORTO_VALID));
    test_assert(!corto_check_attr(o, CORTO_ATTR_NAMED));
    test_assert(corto_check_attr(o, CORTO_ATTR_WRITABLE));
    test_assert(corto_check_attr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(!corto_check_attr(o, CORTO_ATTR_PERSISTENT));

    /* Test if initializer is correctly executed */
    test_assert(o->x == 2);
    test_assert(o->y == 4);

    /* Test if constructor is executed only once */
    test_assert(!corto_define(o));

    test_assert(o->x == 2);
    test_assert(o->y == 4);

    corto_delete(o);

    test_assert(*test_initCalled_o == 1);
    test_assert(*test_constructCalled_o == 1);
    test_assert(*test_destructCalled_o == 1);

}

void test_ObjectMgmt_tc_defineFooAttr0(
    test_ObjectMgmt this)
{

    corto_set_attr(0);
    test_Foo o = corto_declare(NULL, NULL, test_Foo_o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == (corto_type)test_Foo_o);
    test_assert(o->x == 1);
    test_assert(o->y == 2);
    test_assert(!corto_define(o));
    test_assert(corto_check_state(o, CORTO_DECLARED));
    test_assert(corto_check_state(o, CORTO_VALID));
    test_assert(!corto_check_attr(o, CORTO_ATTR_NAMED));
    test_assert(!corto_check_attr(o, CORTO_ATTR_WRITABLE));
    test_assert(!corto_check_attr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(!corto_check_attr(o, CORTO_ATTR_PERSISTENT));

    /* Test if constructor is correctly executed */
    test_assert(o->x == 2);
    test_assert(o->y == 4);

    /* Test if constructor is executed only once */
    test_assert(!corto_define(o));

    test_assert(o->x == 2);
    test_assert(o->y == 4);

    corto_delete(o);

    test_assert(*test_initCalled_o == 1);
    test_assert(*test_constructCalled_o == 1);
    test_assert(*test_destructCalled_o == 1);

}

void test_ObjectMgmt_tc_defineFooFail(
    test_ObjectMgmt this)
{

    test_Foo o = corto_declare(NULL, NULL, test_Foo_o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == (corto_type)test_Foo_o);
    test_assert(o->x == 1);
    test_assert(o->y == 2);

    o->fail = TRUE;
    test_assert(corto_define(o));

    test_assert(corto_check_state(o, CORTO_DECLARED));
    test_assert(!corto_check_state(o, CORTO_VALID));
    test_assert(!corto_check_attr(o, CORTO_ATTR_NAMED));
    test_assert(corto_check_attr(o, CORTO_ATTR_WRITABLE));
    test_assert(corto_check_attr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(!corto_check_attr(o, CORTO_ATTR_PERSISTENT));

    /* Test if constructor is not executed */
    test_assert(o->x == 1);
    test_assert(o->y == 2);

    /* Test if constructor fails 2nd time */
    test_assert(corto_define(o));
    test_assert(corto_check_state(o, CORTO_DECLARED));
    test_assert(!corto_check_state(o, CORTO_VALID));

    /* Test if constructor is still not executed */
    test_assert(o->x == 1);
    test_assert(o->y == 2);

    /* Test if constructor succeeds after fixing error */
    o->fail = FALSE;
    test_assert(!corto_define(o));
    test_assert(corto_check_state(o, CORTO_DECLARED));
    test_assert(corto_check_state(o, CORTO_VALID));

    /* Test if constructor is executed */
    test_assert(o->x == 2);
    test_assert(o->y == 4);

    corto_delete(o);

}

void test_ObjectMgmt_tc_defineInt(
    test_ObjectMgmt this)
{

    corto_object o = corto_declare(NULL, NULL, corto_int32_o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == (corto_type)corto_int32_o);
    test_assert(!corto_define(o));
    test_assert(corto_check_state(o, CORTO_DECLARED));
    test_assert(corto_check_state(o, CORTO_VALID));
    test_assert(!corto_check_attr(o, CORTO_ATTR_NAMED));
    test_assert(corto_check_attr(o, CORTO_ATTR_WRITABLE));
    test_assert(corto_check_attr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(!corto_check_attr(o, CORTO_ATTR_PERSISTENT));
    corto_delete(o);

}

void test_ObjectMgmt_tc_defineIntAttr0(
    test_ObjectMgmt this)
{

    corto_set_attr(0);
    corto_object o = corto_declare(NULL, NULL, corto_int32_o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == (corto_type)corto_int32_o);
    test_assert(!corto_define(o));
    test_assert(corto_check_state(o, CORTO_DECLARED));
    test_assert(corto_check_state(o, CORTO_VALID));
    test_assert(!corto_check_attr(o, CORTO_ATTR_NAMED));
    test_assert(!corto_check_attr(o, CORTO_ATTR_WRITABLE));
    test_assert(!corto_check_attr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(!corto_check_attr(o, CORTO_ATTR_PERSISTENT));
    corto_delete(o);

}

void test_ObjectMgmt_tc_defineVoid(
    test_ObjectMgmt this)
{

    corto_object o = corto_declare(NULL, NULL, corto_void_o);
    corto_define(o);

    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_void_o);
    test_assert(corto_check_state(o, CORTO_DECLARED));
    test_assert(corto_check_state(o, CORTO_VALID));
    test_assert(!corto_check_attr(o, CORTO_ATTR_NAMED));
    test_assert(!corto_check_attr(o, CORTO_ATTR_WRITABLE));
    test_assert(corto_check_attr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(!corto_check_attr(o, CORTO_ATTR_PERSISTENT));
    corto_delete(o);

}

void test_ObjectMgmt_tc_defineVoidAttr0(
    test_ObjectMgmt this)
{

    corto_set_attr(0);
    corto_object o = corto_declare(NULL, NULL, corto_void_o);
    corto_define(o);

    test_assert(o != NULL);
    test_assert(corto_typeof(o) == (corto_type)corto_void_o);
    test_assert(corto_check_state(o, CORTO_DECLARED));
    test_assert(corto_check_state(o, CORTO_VALID));
    test_assert(!corto_check_attr(o, CORTO_ATTR_NAMED));
    test_assert(!corto_check_attr(o, CORTO_ATTR_WRITABLE));
    test_assert(!corto_check_attr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(!corto_check_attr(o, CORTO_ATTR_PERSISTENT));
    corto_delete(o);

}

void test_ObjectMgmt_tc_deleteRedeclaration(
    test_ObjectMgmt this)
{
    corto_int16 result;
    test_Foo o = corto_create(root_o, "o", test_Foo_o);
    test_assert(o != NULL);
    test_assertint(corto_countof(o), 1);

    test_assert(*test_initCalled_o == 1);
    test_assert(*test_constructCalled_o == 1);
    test_assert(*test_destructCalled_o == 0);

    /* Redeclare object */
    test_Foo o2 = corto_create(root_o, "o", test_Foo_o);
    test_assert(o2 != NULL);
    test_assert(o == o2);
    test_assertint(corto_countof(o), 2);

    test_assert(*test_initCalled_o == 1);
    test_assert(*test_constructCalled_o == 1);
    test_assert(*test_destructCalled_o == 0);

    test_EventTest e = test_EventTest__create(NULL, NULL, o);
    test_assertint(corto_countof(o), 4);

    corto_object p = corto_resolve(NULL, "o");
    test_assert(p == o);
    test_assertint(corto_countof(o), 5);
    corto_release(p);
    test_assertint(corto_countof(o), 4);

    test_assert(e->countDeclareSelf == 1);
    test_assert(e->countDefineSelf == 1);
    test_assert(e->countDeleteSelf == 0);
    test_assert(e->countDeleteScope == 0);
    test_assert(e->countDeleteTree == 0);

    result = corto_delete(o);
    test_assert(result == 0);
    test_assertint(corto_countof(o), 3);

    corto_object q = corto_resolve(NULL, "o");
    test_assert(q == NULL);

    test_assert(e->countDeleteSelf == 1);
    test_assert(e->countDeleteScope == 0);
    test_assert(e->countDeleteTree == 0);

    test_assert(*test_initCalled_o == 1);
    test_assert(*test_constructCalled_o == 1);
    test_assert(*test_destructCalled_o == 1);

    result = corto_delete(o2);
    test_assert(result == 0);
    test_assertint(corto_countof(o), 2);

    test_assert(e->countDeleteSelf == 1);
    test_assert(e->countDeleteScope == 0);
    test_assert(e->countDeleteTree == 0);

    test_assert(*test_initCalled_o == 1);
    test_assert(*test_constructCalled_o == 1);
    test_assert(*test_destructCalled_o == 1);

    corto_delete(e);

}

void test_ObjectMgmt_tc_deleteSingle(
    test_ObjectMgmt this)
{
    corto_int16 result;
    test_Foo o = corto_create(root_o, "o", test_Foo_o);
    test_assert(o != NULL);

    test_EventTest e = test_EventTest__create(NULL, NULL, o);

    corto_object p = corto_resolve(NULL, "o");
    test_assert(p == o);
    corto_release(p);

    test_assert(*test_initCalled_o == 1);
    test_assert(*test_constructCalled_o == 1);
    test_assert(*test_destructCalled_o == 0);

    test_assert(e->countDeclareSelf == 1);
    test_assert(e->countDefineSelf == 1);
    test_assert(e->countDeleteSelf == 0);
    test_assert(e->countDeleteScope == 0);
    test_assert(e->countDeleteTree == 0);

    result = corto_delete(o);
    test_assert(result == 0);

    test_assert(e->countDeleteSelf == 1);
    test_assert(e->countDeleteScope == 0);
    test_assert(e->countDeleteTree == 0);

    test_assert(*test_initCalled_o == 1);
    test_assert(*test_constructCalled_o == 1);
    test_assert(*test_destructCalled_o == 1);

    corto_object q = corto_resolve(NULL, "o");
    test_assert(q == NULL);

    corto_delete(e);

}

void test_ObjectMgmt_tc_deleteTreeExplicit(
    test_ObjectMgmt this)
{
    corto_int16 result;
    test_Foo o = corto_create(root_o, "o", test_Foo_o);
    test_assert(o != NULL);

    test_Foo o_o = corto_create(o, "o", test_Foo_o);
    test_assert(o_o != NULL);
    test_assert(o_o != o);

    test_Foo o_o_o = corto_create(o_o, "o", test_Foo_o);
    test_assert(o_o_o != NULL);
    test_assert(o_o_o != o_o);
    test_assert(o_o_o != o);

    test_EventTest e = test_EventTest__create(NULL, NULL, o);

    corto_object p = corto_resolve(NULL, "o");
    test_assert(p == o);
    corto_release(p);

    p = corto_resolve(NULL, "o/o");
    test_assert(p == o_o);
    corto_release(p);

    p = corto_resolve(NULL, "o/o/o");
    test_assert(p == o_o_o);
    corto_release(p);

    test_assert(*test_initCalled_o == 3);
    test_assert(*test_constructCalled_o == 3);
    test_assert(*test_destructCalled_o == 0);

    test_assert(e->countDeclareSelf == 1);
    test_assert(e->countDefineSelf == 1);
    test_assert(e->countDeleteSelf == 0);
    test_assert(e->countDeclareScope == 1);
    test_assert(e->countDefineScope == 1);
    test_assert(e->countDeleteScope == 0);
    test_assert(e->countDeclareTree == 2);
    test_assert(e->countDefineTree == 2);
    test_assert(e->countDeleteTree == 0);

    result = corto_delete(o_o_o);
    test_assert(result == 0);

    test_assert(e->countDeleteSelf == 0);
    test_assert(e->countDeleteScope == 0);
    test_assert(e->countDeleteTree == 1);

    p = corto_resolve(NULL, "o/o/o");
    test_assert(p == NULL);

    result = corto_delete(o_o);
    test_assert(result == 0);

    test_assert(e->countDeleteSelf == 0);
    test_assert(e->countDeleteScope == 1);
    test_assert(e->countDeleteTree == 2);

    p = corto_resolve(NULL, "o/o");
    test_assert(p == NULL);

    result = corto_delete(o);
    test_assert(result == 0);

    test_assert(e->countDeleteSelf == 1);
    test_assert(e->countDeleteScope == 1);
    test_assert(e->countDeleteTree == 2);

    p = corto_resolve(NULL, "o");
    test_assert(p == NULL);

    test_assert(*test_initCalled_o == 3);
    test_assert(*test_constructCalled_o == 3);
    test_assert(*test_destructCalled_o == 3);

    corto_delete(e);

}

void test_ObjectMgmt_tc_deleteTreeImplicit(
    test_ObjectMgmt this)
{
    corto_int16 result;
    test_Foo o = corto_create(root_o, "o", test_Foo_o);
    test_assert(o != NULL);

    test_Foo o_o = corto_create(o, "o", test_Foo_o);
    test_assert(o_o != NULL);
    test_assert(o_o != o);

    test_Foo o_o_o = corto_create(o_o, "o", test_Foo_o);
    test_assert(o_o_o != NULL);
    test_assert(o_o_o != o_o);
    test_assert(o_o_o != o);

    test_EventTest e = test_EventTest__create(NULL, NULL, o);

    corto_object p = corto_resolve(NULL, "o");
    test_assert(p == o);
    corto_release(p);

    p = corto_resolve(NULL, "o/o");
    test_assert(p == o_o);
    corto_release(p);

    p = corto_resolve(NULL, "o/o/o");
    test_assert(p == o_o_o);
    corto_release(p);

    test_assert(*test_initCalled_o == 3);
    test_assert(*test_constructCalled_o == 3);
    test_assert(*test_destructCalled_o == 0);

    test_assert(e->countDeclareSelf == 1);
    test_assert(e->countDefineSelf == 1);
    test_assert(e->countDeleteSelf == 0);
    test_assert(e->countDeclareScope == 1);
    test_assert(e->countDefineScope == 1);
    test_assert(e->countDeleteScope == 0);
    test_assert(e->countDeclareTree == 2);
    test_assert(e->countDefineTree == 2);
    test_assert(e->countDeleteTree == 0);

    result = corto_delete(o);
    test_assert(result == 0);

    test_assert(e->countDeleteSelf == 1);
    test_assert(e->countDeleteScope == 1);
    test_assert(e->countDeleteTree == 2);

    p = corto_resolve(NULL, "o");
    test_assert(p == NULL);

    test_assert(*test_initCalled_o == 3);
    test_assert(*test_constructCalled_o == 3);
    test_assert(*test_destructCalled_o == 3);

    corto_delete(e);

}

void test_ObjectMgmt_tc_deleteWithReference(
    test_ObjectMgmt this)
{
    corto_int16 result;
    test_Foo o = corto_create(root_o, "o", test_Foo_o);
    test_assert(o != NULL);
    test_assertint(corto_countof(o), 1);

    test_EventTest e = test_EventTest__create(NULL, NULL, o);
    test_assertint(corto_countof(o), 3); /* e holds 2 references */

    corto_object p = corto_resolve(NULL, "o");
    test_assert(p == o);
    test_assertint(corto_countof(o), 4);

    /* Postpone release until after the delete */

    test_assert(*test_initCalled_o == 1);
    test_assert(*test_constructCalled_o == 1);
    test_assert(*test_destructCalled_o == 0);

    test_assert(e->countDeclareSelf == 1);
    test_assert(e->countDefineSelf == 1);
    test_assert(e->countDeleteSelf == 0);
    test_assert(e->countDeleteScope == 0);
    test_assert(e->countDeleteTree == 0);

    result = corto_delete(o);
    test_assert(result == 0);
    test_assertint(corto_countof(o), 3);

    test_assert(e->countDeleteSelf == 1);
    test_assert(e->countDeleteScope == 0);
    test_assert(e->countDeleteTree == 0);

    test_assert(*test_initCalled_o == 1);
    test_assert(*test_constructCalled_o == 1);
    test_assert(*test_destructCalled_o == 1);

    corto_object q = corto_resolve(NULL, "o");
    test_assert(q == NULL);
    test_assertint(corto_countof(o), 3);

    result = corto_release(o);
    test_assert(result == 2); /* Refcount should be 2 */

    /* This will get rid of the remaining 2 references */
    corto_delete(e);

}

void test_ObjectMgmt_tc_findOrCreate(
    test_ObjectMgmt this)
{
    corto_object o = corto(CORTO_DECLARE|CORTO_DEFINE, {
        .parent = root_o,
        .id = "foo",
        .type = corto_int32_o
    });
    test_assert(o != NULL);
    test_assert(corto_check_state(o, CORTO_VALID));
    test_assert(corto_typeof(o) == corto_type(corto_int32_o));
    test_assertstr(corto_idof(o), "foo");
    test_assert(corto_parentof(o) == root_o);
    test_assertint(corto_countof(o), 1);
    corto_object f = corto_lookup(root_o, "foo");
    test_assert(f != NULL);
    test_assert(f == o);
    test_assert(corto_release(f) == 1);
    test_assert(corto_delete(o) == 0);
}

void test_ObjectMgmt_tc_findOrCreateExisting(
    test_ObjectMgmt this)
{
    corto_object e = corto_create(root_o, "foo", corto_int32_o);
    test_assert(e != NULL);

    corto_object o = corto(CORTO_DECLARE|CORTO_DEFINE, {
        .parent = root_o,
        .id = "foo",
        .type = corto_int32_o
    });
    test_assert(o != NULL);
    test_assert(o == e);
    test_assert(corto_check_state(o, CORTO_VALID));
    test_assert(corto_typeof(o) == corto_type(corto_int32_o));
    test_assertstr(corto_idof(o), "foo");
    test_assert(corto_parentof(o) == root_o);
    test_assertint(corto_countof(o), 2);
    test_assert(corto_delete(o) == 0);
    test_assert(corto_release(e) == 0);
}

void test_ObjectMgmt_tc_findOrCreateExistingOtherType(
    test_ObjectMgmt this)
{
    corto_object e = corto_create(root_o, "foo", corto_float32_o);

    corto_object o = corto(CORTO_DECLARE|CORTO_DEFINE, {
        .parent = root_o,
        .id = "foo",
        .type = corto_int32_o
    });
    test_assert(o != NULL);
    test_assert(o == e);
    test_assert(corto_check_state(o, CORTO_VALID));
    test_assert(corto_typeof(o) == corto_type(corto_float32_o));
    test_assertstr(corto_idof(o), "foo");
    test_assert(corto_parentof(o) == root_o);
    test_assertint(corto_countof(o), 2);
    test_assert(corto_delete(o) == 0);
    test_assert(corto_release(e) == 0);
}

void test_ObjectMgmt_tc_findOrDeclare(
    test_ObjectMgmt this)
{
    corto_object o = corto(CORTO_DECLARE, {
        .parent = root_o,
        .id = "foo",
        .type = corto_int32_o
    });
    test_assert(o != NULL);
    test_assert(!corto_check_state(o, CORTO_VALID));
    test_assert(corto_typeof(o) == corto_type(corto_int32_o));
    test_assertstr(corto_idof(o), "foo");
    test_assert(corto_parentof(o) == root_o);
    test_assertint(corto_countof(o), 1);
    corto_object f = corto_lookup(root_o, "foo");
    test_assert(f != NULL);
    test_assert(f == o);
    test_assert(corto_release(f) == 1);
    test_assert(corto_delete(o) == 0);
}

void test_ObjectMgmt_tc_findOrDeclareExisting(
    test_ObjectMgmt this)
{
    corto_object e = corto_declare(root_o, "foo", corto_int32_o);
    test_assert(e != NULL);

    corto_object o = corto(CORTO_DECLARE, {
        .parent = root_o,
        .id = "foo",
        .type = corto_int32_o
    });
    test_assert(o != NULL);
    test_assert(o == e);
    test_assert(!corto_check_state(o, CORTO_VALID));
    test_assert(corto_typeof(o) == corto_type(corto_int32_o));
    test_assertstr(corto_idof(o), "foo");
    test_assert(corto_parentof(o) == root_o);
    test_assertint(corto_countof(o), 2);
    test_assert(corto_delete(o) == 0);
    test_assert(corto_release(e) == 0);
}

void test_ObjectMgmt_tc_findOrDeclareExistingOtherType(
    test_ObjectMgmt this)
{
    corto_object e = corto_declare(root_o, "foo", corto_float32_o);

    corto_object o = corto(CORTO_DECLARE, {
        .parent = root_o,
        .id = "foo",
        .type = corto_int32_o
    });
    test_assert(o != NULL);
    test_assert(o == e);
    test_assert(!corto_check_state(o, CORTO_VALID));
    test_assert(corto_typeof(o) == corto_type(corto_float32_o));
    test_assertstr(corto_idof(o), "foo");
    test_assert(corto_parentof(o) == root_o);
    test_assertint(corto_countof(o), 2);
    test_assert(corto_delete(o) == 0);
    test_assert(corto_release(e) == 0);
}

void test_ObjectMgmt_tc_invalidate(
    test_ObjectMgmt this)
{

    corto_object o = corto_void__create(NULL, NULL);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_void_o);
    test_assert(corto_check_state(o, CORTO_DECLARED));
    test_assert(corto_check_state(o, CORTO_VALID));
    test_assert(corto_check_attr(o, CORTO_ATTR_OBSERVABLE));

    corto_invalidate(o);
    test_assert(!corto_check_state(o, CORTO_VALID));
    corto_delete(o);

}

void test_ObjectMgmt_tc_nameof(
    test_ObjectMgmt this)
{

    corto_int32__create_auto(root_o, a, 10);
    test_assertstr(corto_nameof(NULL, a), "a");

}

void test_ObjectMgmt_tc_nameofOverride(
    test_ObjectMgmt this)
{

    test_Point__create_auto(root_o, p, 10, 20);
    test_assertstr(corto_nameof(NULL, p), "10,20");

}

void test_ObjectMgmt_tc_redeclareWithDifferentType(
    test_ObjectMgmt this)
{
    corto_declare(root_o, "a", corto_float32_o);
    corto_declare(root_o, "b", corto_float32_o);
    corto_declare(root_o, "c", corto_float32_o);

    corto_object a = corto_declare(root_o, "a", corto_float64_o);
    test_assert(a == NULL);
    test_assert(corto_catch());

    corto_object b = corto_declare(root_o, "b", corto_float64_o);
    test_assert(b == NULL);
    test_assert(corto_catch());

    corto_object c = corto_declare(root_o, "c", corto_float64_o);
    test_assert(c == NULL);
    test_assert(corto_catch());
}

void test_ObjectMgmt_teardown(
    test_ObjectMgmt this)
{
    corto_set_attr(this->prevAttr);
}

void test_ObjectMgmt_tc_declareNestedFirstExists(
    test_ObjectMgmt this)
{
    test_EventCount *counter = test_EventCount__create(NULL, NULL, 0, 0, 0, 0, 0, 0);
    corto_observer o = corto_observe(CORTO_ON_ANY | CORTO_ON_TREE, root_o)
        .instance(counter)
        .callback(onDeclareNested);
    test_assert(o != NULL);

    /* Reset counter so aligned objects don't pollute result */
    counter->declareCount = 0;
    counter->defineCount = 0;
    counter->updateCount = 0;
    counter->deleteCount = 0;

    /* Pre-declare the first object */
    corto_object pre_a = corto_declare(root_o, "a", corto_float32_o);
    test_assert(pre_a != NULL);

    corto_object c = corto_declare(root_o, "a/b/c", corto_int32_o);
    test_assert(c != NULL);
    test_assert(corto_typeof(c) == corto_type(corto_int32_o));
    test_assertstr(corto_idof(c), "c");
    test_assert(corto_check_state(c, CORTO_DECLARED));
    test_assert(!corto_check_state(c, CORTO_VALID));

    corto_object b = corto_lookup(root_o, "a/b");
    test_assert(b != NULL);
    test_assert(corto_parentof(c) == b);
    test_assert(corto_typeof(b) == corto_type(corto_unknown_o));
    test_assertstr(corto_idof(b), "b");
    test_assert(corto_check_state(b, CORTO_DECLARED));
    test_assert(!corto_check_state(b, CORTO_VALID));

    corto_object a = corto_lookup(root_o, "a");
    test_assert(a != NULL);
    test_assert(corto_parentof(b) == a);
    test_assert(corto_typeof(a) == corto_type(corto_float32_o));
    test_assertstr(corto_idof(a), "a");
    test_assert(corto_check_state(a, CORTO_DECLARED));
    test_assert(!corto_check_state(a, CORTO_VALID));

    test_assert(corto_delete(a) == 0);
    test_assert(corto_delete(o) == 0);

    test_assertint(counter->declareCount, 3);
    test_assertint(counter->defineCount, 0);
    test_assertint(counter->updateCount, 0);
    test_assertint(counter->deleteCount, 0); /* one for void object */
}

void test_ObjectMgmt_tc_declareNestedLastExists(
    test_ObjectMgmt this)
{
    test_EventCount *counter = test_EventCount__create(NULL, NULL, 0, 0, 0, 0, 0, 0);
    corto_observer o = corto_observe(CORTO_ON_ANY | CORTO_ON_TREE, root_o)
        .instance(counter)
        .callback(onDeclareNested);
    test_assert(o != NULL);

    /* Reset counter so aligned objects don't pollute result */
    counter->declareCount = 0;
    counter->defineCount = 0;
    counter->updateCount = 0;
    counter->deleteCount = 0;

    /* Pre-declare the first object */
    corto_object pre_a = corto_declare(root_o, "a", corto_float32_o);
    test_assert(pre_a != NULL);

    /* Pre-declare the second object */
    corto_object pre_b = corto_declare(root_o, "a/b", corto_float32_o);
    test_assert(pre_b != NULL);

    /* Pre-declare the third object */
    corto_object pre_c = corto_declare(root_o, "a/b/c", corto_float32_o);
    test_assert(pre_c != NULL);

    corto_object c = corto_declare(root_o, "a/b/c", corto_float32_o);
    test_assert(c != NULL);
    test_assert(corto_typeof(c) == corto_type(corto_float32_o));
    test_assertstr(corto_idof(c), "c");
    test_assert(corto_check_state(c, CORTO_DECLARED));
    test_assert(!corto_check_state(c, CORTO_VALID));

    corto_object b = corto_lookup(root_o, "a/b");
    test_assert(b != NULL);
    test_assert(corto_parentof(c) == b);
    test_assert(corto_typeof(b) == corto_type(corto_float32_o));
    test_assertstr(corto_idof(b), "b");
    test_assert(corto_check_state(b, CORTO_DECLARED));
    test_assert(!corto_check_state(b, CORTO_VALID));

    corto_object a = corto_lookup(root_o, "a");
    test_assert(a != NULL);
    test_assert(corto_parentof(b) == a);
    test_assert(corto_typeof(a) == corto_type(corto_float32_o));
    test_assertstr(corto_idof(a), "a");
    test_assert(corto_check_state(a, CORTO_DECLARED));
    test_assert(!corto_check_state(a, CORTO_VALID));

    test_assert(corto_delete(a) == 0);
    test_assert(corto_delete(o) == 0);

    test_assertint(counter->declareCount, 3);
    test_assertint(counter->defineCount, 0);
    test_assertint(counter->updateCount, 0);
    test_assertint(counter->deleteCount, 0);
}

void test_ObjectMgmt_tc_declareNestedSecondExists(
    test_ObjectMgmt this)
{
    test_EventCount *counter = test_EventCount__create(NULL, NULL, 0, 0, 0, 0, 0, 0);
    corto_observer o = corto_observe(CORTO_ON_ANY | CORTO_ON_TREE, root_o)
        .instance(counter)
        .callback(onDeclareNested);
    test_assert(o != NULL);

    /* Reset counter so aligned objects don't pollute result */
    counter->declareCount = 0;
    counter->defineCount = 0;
    counter->updateCount = 0;
    counter->deleteCount = 0;

    /* Pre-declare the first object */
    corto_object pre_a = corto_declare(root_o, "a", corto_float32_o);
    test_assert(pre_a != NULL);

    /* Pre-declare the second object */
    corto_object pre_b = corto_declare(root_o, "a/b", corto_float32_o);
    test_assert(pre_b != NULL);

    corto_object c = corto_declare(root_o, "a/b/c", corto_int32_o);
    test_assert(c != NULL);
    test_assert(corto_typeof(c) == corto_type(corto_int32_o));
    test_assertstr(corto_idof(c), "c");
    test_assert(corto_check_state(c, CORTO_DECLARED));
    test_assert(!corto_check_state(c, CORTO_VALID));

    corto_object b = corto_lookup(root_o, "a/b");
    test_assert(b != NULL);
    test_assert(corto_parentof(c) == b);
    test_assert(corto_typeof(b) == corto_type(corto_float32_o));
    test_assertstr(corto_idof(b), "b");
    test_assert(corto_check_state(b, CORTO_DECLARED));
    test_assert(!corto_check_state(b, CORTO_VALID));

    corto_object a = corto_lookup(root_o, "a");
    test_assert(a != NULL);
    test_assert(corto_parentof(b) == a);
    test_assert(corto_typeof(a) == corto_type(corto_float32_o));
    test_assertstr(corto_idof(a), "a");
    test_assert(corto_check_state(a, CORTO_DECLARED));
    test_assert(!corto_check_state(a, CORTO_VALID));

    test_assert(corto_delete(a) == 0);
    test_assert(corto_delete(o) == 0);

    test_assertint(counter->declareCount, 3);
    test_assertint(counter->defineCount, 0);
    test_assertint(counter->updateCount, 0);
    test_assertint(counter->deleteCount, 0);
}

void test_ObjectMgmt_tc_lifecycle(
    test_ObjectMgmt this)
{
    test_LifecycleTest o = corto_declare(root_o, "data/lt", test_LifecycleTest_o);
    test_assert(o != NULL);
    test_assert(o->admin != NULL);

    // Separate object keeps track of called callbacks so it is possible to track
    // calling deinit
    test_LifecycleAdmin a = o->admin;
    corto_claim(a);

    test_assertint(a->hooksCalled, TEST_INIT_CALLED);
    test_assertint(corto_stateof(o), CORTO_DECLARED);

    /* Claim object, so difference between delete and release can be tested */
    corto_claim(o);

    test_assert(corto_define(o) == 0);
    test_assertint(a->hooksCalled,
        TEST_INIT_CALLED|TEST_CONSTRUCT_CALLED|TEST_DEFINE_CALLED);
    test_assertint(corto_stateof(o), CORTO_DECLARED|CORTO_VALID);

    test_assert(corto_update(o) == 0);
    test_assertint(a->hooksCalled,
        TEST_INIT_CALLED|TEST_CONSTRUCT_CALLED|TEST_DEFINE_CALLED|TEST_VALIDATE_CALLED|TEST_UPDATE_CALLED);
    test_assertint(corto_stateof(o), CORTO_DECLARED|CORTO_VALID);

    test_assert(corto_delete(o) == 0);
    test_assertint(a->hooksCalled,
        TEST_INIT_CALLED|TEST_CONSTRUCT_CALLED|TEST_DEFINE_CALLED|TEST_VALIDATE_CALLED|TEST_UPDATE_CALLED|
        TEST_DESTRUCT_CALLED|TEST_DELETE_CALLED);
    test_assertint(corto_stateof(o), CORTO_DECLARED|CORTO_DELETED);

    corto_release(o);
    test_assertint(a->hooksCalled,
        TEST_INIT_CALLED|TEST_CONSTRUCT_CALLED|TEST_DEFINE_CALLED|TEST_VALIDATE_CALLED|TEST_UPDATE_CALLED|
        TEST_DESTRUCT_CALLED|TEST_DELETE_CALLED|TEST_DEINIT_CALLED);

    test_assert(corto_delete(a) == 0);
}

void test_ObjectMgmt_tc_lifecycleConstructFail(
    test_ObjectMgmt this)
{
    test_LifecycleTest o = corto_declare(root_o, "data/lt", test_LifecycleTest_o);
    test_assert(o != NULL);
    test_assert(o->admin != NULL);

    o->constructFail = true;

    // Separate object keeps track of called callbacks so it is possible to track
    // calling deinit
    test_LifecycleAdmin a = o->admin;
    corto_claim(a);

    test_assertint(a->hooksCalled, TEST_INIT_CALLED);
    test_assertint(corto_stateof(o), CORTO_DECLARED);

    /* Claim object, so difference between delete and release can be tested */
    corto_claim(o);

    test_assert(corto_define(o) != 0);
    test_assertint(a->hooksCalled,
        TEST_INIT_CALLED|TEST_CONSTRUCT_CALLED);
    test_assertint(corto_stateof(o), CORTO_DECLARED);

    o->constructFail = false;

    /* Reset hooksCalled for next test */
    a->hooksCalled = TEST_INIT_CALLED;

    test_assert(corto_define(o) == 0);
    test_assertint(a->hooksCalled,
        TEST_INIT_CALLED|TEST_CONSTRUCT_CALLED|TEST_DEFINE_CALLED);
    test_assertint(corto_stateof(o), CORTO_DECLARED|CORTO_VALID);

    test_assert(corto_update(o) == 0);
    test_assertint(a->hooksCalled,
        TEST_INIT_CALLED|TEST_CONSTRUCT_CALLED|TEST_DEFINE_CALLED|TEST_VALIDATE_CALLED|TEST_UPDATE_CALLED);
    test_assertint(corto_stateof(o), CORTO_DECLARED|CORTO_VALID);

    test_assert(corto_delete(o) == 0);
    test_assertint(a->hooksCalled,
        TEST_INIT_CALLED|TEST_CONSTRUCT_CALLED|TEST_DEFINE_CALLED|TEST_VALIDATE_CALLED|TEST_UPDATE_CALLED|
        TEST_DESTRUCT_CALLED|TEST_DELETE_CALLED);
    test_assertint(corto_stateof(o), CORTO_DECLARED|CORTO_DELETED);

    corto_release(o);
    test_assertint(a->hooksCalled,
        TEST_INIT_CALLED|TEST_CONSTRUCT_CALLED|TEST_DEFINE_CALLED|TEST_VALIDATE_CALLED|TEST_UPDATE_CALLED|
        TEST_DESTRUCT_CALLED|TEST_DELETE_CALLED|TEST_DEINIT_CALLED);

    test_assert(corto_delete(a) == 0);
}

void test_ObjectMgmt_tc_lifecycleInitFail(
    test_ObjectMgmt this)
{
    test_LifecycleTest o = corto_declare(root_o, "data/fail", test_LifecycleTest_o);
    test_assert(o == NULL);
    test_assert(corto_catch());
}

void test_ObjectMgmt_tc_lifecycleValidateFail(
    test_ObjectMgmt this)
{
    test_LifecycleTest o = corto_declare(root_o, "data/lt", test_LifecycleTest_o);
    test_assert(o != NULL);
    test_assert(o->admin != NULL);

    // Separate object keeps track of called callbacks so it is possible to track
    // calling deinit
    test_LifecycleAdmin a = o->admin;
    corto_claim(a);

    test_assertint(a->hooksCalled, TEST_INIT_CALLED);
    test_assertint(corto_stateof(o), CORTO_DECLARED);

    /* Claim object, so difference between delete and release can be tested */
    corto_claim(o);

    o->validateFail = true;

    test_assert(corto_define(o) == 0);
    test_assertint(a->hooksCalled,
        TEST_INIT_CALLED|TEST_CONSTRUCT_CALLED|TEST_DEFINE_CALLED);
    test_assertint(corto_stateof(o), CORTO_DECLARED|CORTO_VALID);

    test_assert(corto_update(o) != 0);
    test_assertint(a->hooksCalled,
        TEST_INIT_CALLED|TEST_CONSTRUCT_CALLED|TEST_DEFINE_CALLED|TEST_VALIDATE_CALLED);
    test_assertint(corto_stateof(o), CORTO_DECLARED|CORTO_VALID);

    a->hooksCalled = TEST_INIT_CALLED|TEST_CONSTRUCT_CALLED|TEST_DEFINE_CALLED;
    o->validateFail = false;

    test_assert(corto_update(o) == 0);
    test_assertint(a->hooksCalled,
        TEST_INIT_CALLED|TEST_CONSTRUCT_CALLED|TEST_DEFINE_CALLED|TEST_VALIDATE_CALLED|TEST_UPDATE_CALLED);
    test_assertint(corto_stateof(o), CORTO_DECLARED|CORTO_VALID);

    test_assert(corto_delete(o) == 0);
    test_assertint(a->hooksCalled,
        TEST_INIT_CALLED|TEST_CONSTRUCT_CALLED|TEST_DEFINE_CALLED|TEST_VALIDATE_CALLED|TEST_UPDATE_CALLED|
        TEST_DESTRUCT_CALLED|TEST_DELETE_CALLED);
    test_assertint(corto_stateof(o), CORTO_DECLARED|CORTO_DELETED);

    corto_release(o);
    test_assertint(a->hooksCalled,
        TEST_INIT_CALLED|TEST_CONSTRUCT_CALLED|TEST_DEFINE_CALLED|TEST_VALIDATE_CALLED|TEST_UPDATE_CALLED|
        TEST_DESTRUCT_CALLED|TEST_DELETE_CALLED|TEST_DEINIT_CALLED);

    test_assert(corto_delete(a) == 0);
}

void test_ObjectMgmt_tc_lifecycleValidateFail_w_updateBegin(
    test_ObjectMgmt this)
{
    test_LifecycleTest o = corto_declare(root_o, "data/lt", test_LifecycleTest_o);
    test_assert(o != NULL);
    test_assert(o->admin != NULL);

    // Separate object keeps track of called callbacks so it is possible to track
    // calling deinit
    test_LifecycleAdmin a = o->admin;
    corto_claim(a);

    test_assertint(a->hooksCalled, TEST_INIT_CALLED);
    test_assertint(corto_stateof(o), CORTO_DECLARED);

    /* Claim object, so difference between delete and release can be tested */
    corto_claim(o);

    o->validateFail = true;

    test_assert(corto_define(o) == 0);
    test_assertint(a->hooksCalled,
        TEST_INIT_CALLED|TEST_CONSTRUCT_CALLED|TEST_DEFINE_CALLED);
    test_assertint(corto_stateof(o), CORTO_DECLARED|CORTO_VALID);

    test_assert(corto_update_begin(o) == 0);
    test_assert(corto_update_end(o) != 0);
    test_assertint(a->hooksCalled,
        TEST_INIT_CALLED|TEST_CONSTRUCT_CALLED|TEST_DEFINE_CALLED|TEST_VALIDATE_CALLED);
    test_assertint(corto_stateof(o), CORTO_DECLARED|CORTO_VALID);

    a->hooksCalled = TEST_INIT_CALLED|TEST_CONSTRUCT_CALLED|TEST_DEFINE_CALLED;
    o->validateFail = false;

    test_assert(corto_update_begin(o) == 0);
    test_assert(corto_update_end(o) == 0);
    test_assertint(a->hooksCalled,
        TEST_INIT_CALLED|TEST_CONSTRUCT_CALLED|TEST_DEFINE_CALLED|TEST_VALIDATE_CALLED|TEST_UPDATE_CALLED);
    test_assertint(corto_stateof(o), CORTO_DECLARED|CORTO_VALID);

    test_assert(corto_delete(o) == 0);
    test_assertint(a->hooksCalled,
        TEST_INIT_CALLED|TEST_CONSTRUCT_CALLED|TEST_DEFINE_CALLED|TEST_VALIDATE_CALLED|TEST_UPDATE_CALLED|
        TEST_DESTRUCT_CALLED|TEST_DELETE_CALLED);
    test_assertint(corto_stateof(o), CORTO_DECLARED|CORTO_DELETED);

    corto_release(o);
    test_assertint(a->hooksCalled,
        TEST_INIT_CALLED|TEST_CONSTRUCT_CALLED|TEST_DEFINE_CALLED|TEST_VALIDATE_CALLED|TEST_UPDATE_CALLED|
        TEST_DESTRUCT_CALLED|TEST_DELETE_CALLED|TEST_DEINIT_CALLED);

    test_assert(corto_delete(a) == 0);
}

void test_ObjectMgmt_tc_redeclareNestedUnknown(
    test_ObjectMgmt this)
{
    corto_object o = corto_declare(root_o, "foo/bar", corto_string_o);
    test_assert(o != NULL);
    test_assert(!corto_check_state(o, CORTO_VALID));
    test_assert(corto_typeof(o) == (corto_type)corto_string_o);

    corto_object p = corto_parentof(o);
    test_assert(p != NULL);
    test_assert(!corto_check_state(p, CORTO_VALID));
    test_assert(corto_typeof(p) == corto_unknown_o);

    corto_object q = corto_declare(root_o, "foo", corto_uint32_o);
    test_assert(q != NULL);
    test_assert(q != p);
    test_assert(!corto_check_state(q, CORTO_VALID));
    test_assert(corto_typeof(q) == (corto_type)corto_uint32_o);
    test_assertstr(corto_fullpath(NULL, q), "/foo");
    test_assert(corto_parentof(o) == q);

    test_assert(!corto_delete(q));
}

void test_ObjectMgmt_tc_redeclareUnknown(
    test_ObjectMgmt this)
{
    corto_object o = corto_declare(root_o, "foo", corto_unknown_o);
    test_assert(o != NULL);
    test_assert(!corto_check_state(o, CORTO_VALID));
    test_assert(corto_typeof(o) == corto_unknown_o);
    test_assertstr(corto_fullpath(NULL, o), "/foo");

    corto_object p = corto_declare(root_o, "foo", corto_uint32_o);
    test_assert(p != NULL);
    test_assert(p != o);
    test_assert(!corto_check_state(p, CORTO_VALID));
    test_assert(corto_typeof(p) == (corto_type)corto_uint32_o);
    test_assertstr(corto_fullpath(NULL, p), "/foo");

    test_assert(!corto_delete(p));
}

void test_ObjectMgmt_tc_redeclareOutOfOrder(
    test_ObjectMgmt this)
{
    corto_object world = corto_declare(root_o, "foo/bar/hello/world", corto_string_o);
    test_assert(world != NULL);
    test_assert(!corto_check_state(world, CORTO_VALID));
    test_assert(corto_typeof(world) == (corto_type)corto_string_o);
    test_assertint(corto_countof(world), 1);

    corto_object bar = corto_declare(root_o, "foo/bar", corto_bool_o);
    test_assert(bar != NULL);
    test_assert(!corto_check_state(bar, CORTO_VALID));
    test_assert(corto_typeof(bar) == (corto_type)corto_bool_o);
    test_assertint(corto_countof(bar), 2);
    test_assertint(corto_countof(world), 1);

    corto_object hello = corto_declare(root_o, "foo/bar/hello", corto_uint64_o);
    test_assert(hello != NULL);
    test_assert(!corto_check_state(hello, CORTO_VALID));
    test_assert(corto_typeof(hello) == (corto_type)corto_uint64_o);
    test_assertint(corto_countof(hello), 2);
    test_assertint(corto_countof(bar), 2);
    test_assertint(corto_countof(world), 1);

    corto_object foo = corto_declare(root_o, "foo", corto_char_o);
    test_assert(foo != NULL);
    test_assert(!corto_check_state(foo, CORTO_VALID));
    test_assert(corto_typeof(foo) == (corto_type)corto_char_o);
    test_assertint(corto_countof(foo), 2);
    test_assertint(corto_countof(bar), 2);
    test_assertint(corto_countof(hello), 2);
    test_assertint(corto_countof(world), 1);

    test_assert(corto_parentof(world) == hello);
    test_assert(corto_parentof(hello) == bar);
    test_assert(corto_parentof(bar) == foo);
    test_assert(corto_parentof(foo) == root_o);

    test_assert(corto_delete(foo) == 0);
}

void test_ObjectMgmt_tc_redeclareRecursiveUnknownDontForceType(
    test_ObjectMgmt this)
{
    corto_object o = corto_declare(root_o, "foo/bar", corto_unknown_o);
    test_assert(o != NULL);
    test_assert(!corto_check_state(o, CORTO_VALID));
    test_assert(corto_typeof(o) == corto_unknown_o);
    test_assertstr(corto_fullpath(NULL, o), "/foo/bar");

    corto_object p = corto(CORTO_RECURSIVE_DECLARE, {
        .parent = root_o,
        .id = "foo/bar",
        .type = corto_uint32_o
    });
    test_assert(p != NULL);
    test_assert(p != o);
    test_assert(!corto_check_state(p, CORTO_VALID));
    test_assert(corto_typeof(p) == (corto_type)corto_uint32_o);
    test_assertstr(corto_fullpath(NULL, p), "/foo/bar");
    test_assert(!corto_delete(p));
}

void test_ObjectMgmt_tc_redeclareUnknownDontForceType(
    test_ObjectMgmt this)
{
    corto_object o = corto_declare(root_o, "foo", corto_unknown_o);
    test_assert(o != NULL);
    test_assert(!corto_check_state(o, CORTO_VALID));
    test_assert(corto_typeof(o) == corto_unknown_o);
    test_assertstr(corto_fullpath(NULL, o), "/foo");

    corto_object p = corto(CORTO_DECLARE, {
        .parent = root_o,
        .id = "foo",
        .type = corto_uint32_o
    });
    test_assert(p != NULL);
    test_assert(p != o);
    test_assert(!corto_check_state(p, CORTO_VALID));
    test_assert(corto_typeof(p) == (corto_type)corto_uint32_o);
    test_assertstr(corto_fullpath(NULL, p), "/foo");
    test_assert(!corto_delete(p));
}

void test_ObjectMgmt_tc_defineUnknown(
    test_ObjectMgmt this)
{
    corto_object o = corto_declare(root_o, "foo", corto_unknown_o);
    test_assert(o != NULL);
    test_assert(!corto_check_state(o, CORTO_VALID));
    test_assert(corto_typeof(o) == corto_unknown_o);
    test_assertstr(corto_fullpath(NULL, o), "/foo");

    test_assert(corto_define(o) != 0);
    test_assert(corto_catch());
    test_assert(!corto_check_state(o, CORTO_VALID));
}

void test_ObjectMgmt_tc_recreatedOutOfOrder(
    test_ObjectMgmt this)
{
    corto_object world = corto_create(root_o, "foo/bar/hello/world", corto_string_o);
    test_assert(world != NULL);
    test_assert(corto_check_state(world, CORTO_VALID));
    test_assert(corto_typeof(world) == (corto_type)corto_string_o);
    test_assertint(corto_countof(world), 1);

    corto_object bar = corto_create(root_o, "foo/bar", corto_bool_o);
    test_assert(bar != NULL);
    test_assert(corto_check_state(bar, CORTO_VALID));
    test_assert(corto_typeof(bar) == (corto_type)corto_bool_o);
    test_assertint(corto_countof(bar), 2);
    test_assertint(corto_countof(world), 1);

    corto_object hello = corto_create(root_o, "foo/bar/hello", corto_uint64_o);
    test_assert(hello != NULL);
    test_assert(corto_check_state(hello, CORTO_VALID));
    test_assert(corto_typeof(hello) == (corto_type)corto_uint64_o);
    test_assertint(corto_countof(hello), 2);
    test_assertint(corto_countof(bar), 2);
    test_assertint(corto_countof(world), 1);

    corto_object foo = corto_create(root_o, "foo", corto_char_o);
    test_assert(foo != NULL);
    test_assert(corto_check_state(foo, CORTO_VALID));
    test_assert(corto_typeof(foo) == (corto_type)corto_char_o);
    test_assertint(corto_countof(foo), 2);
    test_assertint(corto_countof(bar), 2);
    test_assertint(corto_countof(hello), 2);
    test_assertint(corto_countof(world), 1);

    test_assert(corto_parentof(world) == hello);
    test_assert(corto_parentof(hello) == bar);
    test_assert(corto_parentof(bar) == foo);
    test_assert(corto_parentof(foo) == root_o);

    test_assert(corto_delete(foo) == 0);
}

void test_ObjectMgmt_tc_recreateNestedUnknown(
    test_ObjectMgmt this)
{
    corto_object o = corto_declare(root_o, "foo/bar", corto_string_o);
    test_assert(o != NULL);
    test_assert(!corto_check_state(o, CORTO_VALID));
    test_assert(corto_typeof(o) == (corto_type)corto_string_o);

    corto_object p = corto_parentof(o);
    test_assert(p != NULL);
    test_assert(!corto_check_state(p, CORTO_VALID));
    test_assert(corto_typeof(p) == corto_unknown_o);

    corto_object q = corto_create(root_o, "foo", corto_uint32_o);
    test_assert(q != NULL);
    test_assert(q != p);
    test_assert(corto_check_state(q, CORTO_VALID));
    test_assert(corto_typeof(q) == (corto_type)corto_uint32_o);
    test_assertstr(corto_fullpath(NULL, q), "/foo");
    test_assert(corto_parentof(o) == q);

    test_assert(!corto_delete(q));
}

void test_ObjectMgmt_tc_recreateUnknown(
    test_ObjectMgmt this)
{
    corto_object o = corto_declare(root_o, "foo", corto_unknown_o);
    test_assert(o != NULL);
    test_assert(!corto_check_state(o, CORTO_VALID));
    test_assert(corto_typeof(o) == corto_unknown_o);
    test_assertstr(corto_fullpath(NULL, o), "/foo");

    corto_object p = corto_create(root_o, "foo", corto_uint32_o);
    test_assert(p != NULL);
    test_assert(p != o);
    test_assert(corto_check_state(p, CORTO_VALID));
    test_assert(corto_typeof(p) == (corto_type)corto_uint32_o);
    test_assertstr(corto_fullpath(NULL, p), "/foo");

    test_assert(!corto_delete(p));
}

void test_ObjectMgmt_tc_defineRedeclaredUnknown(
    test_ObjectMgmt this)
{
    corto_object o = corto_declare(root_o, "foo", corto_unknown_o);
    test_assert(o != NULL);
    test_assert(!corto_check_state(o, CORTO_VALID));
    test_assert(corto_typeof(o) == corto_unknown_o);
    test_assertstr(corto_fullpath(NULL, o), "/foo");

    o = corto_declare(root_o, "foo", corto_uint32_o);
    test_assert(o != NULL);
    test_assert(!corto_check_state(o, CORTO_VALID));
    test_assert(corto_typeof(o) == (corto_type)corto_uint32_o);

    test_assert(corto_define(o) == 0);
    test_assert(corto_check_state(o, CORTO_VALID));

    test_assert(corto_delete(o) == 0);
}

void test_ObjectMgmt_tc_defaultValues(
    test_ObjectMgmt this)
{
    test_DefaultValues v = corto_create(NULL, NULL, test_DefaultValues_o);
    test_assert(v != NULL);
    test_assert(corto_check_state(v, CORTO_VALID));

    test_assertint(v->a, 10);
    test_assertint(v->b.x, 20);
    test_assertint(v->b.y, 30);
    test_assertstr(v->c, "Hello World");
}

