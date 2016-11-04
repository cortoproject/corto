/* $CORTO_GENERATED
 *
 * ObjectMgmt.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <test.h>

corto_void _test_ObjectMgmt_setup(
    test_ObjectMgmt this)
{
/* $begin(test/ObjectMgmt/setup) */
    this->prevAttr = corto_setAttr(CORTO_ATTR_DEFAULT);
    *test_initCalled_o = 0;
    *test_constructCalled_o = 0;
    *test_destructCalled_o = 0;
/* $end */
}

corto_void _test_ObjectMgmt_tc_createChildFoo(
    test_ObjectMgmt this)
{
/* $begin(test/ObjectMgmt/tc_createChildFoo) */

    test_Foo o = corto_createChild(NULL, "o", test_Foo_o);
    test_assert(o != NULL);
    test_assert(!strcmp(corto_idof(o), "o"));
    test_assert(corto_parentof(o) == root_o);
    test_assert(corto_typeof(o) == (corto_type)test_Foo_o);
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));

    corto_object p = corto_resolve(NULL, "o");
    test_assert(o == p);
    corto_release(p);

    /* Test if constructor is correctly executed */
    test_assert(o->x == 11);
    test_assert(o->y == 22);

    corto_delete(o);

    corto_object q = corto_resolve(NULL, "o");
    test_assert(q == NULL);

    test_assert(*test_initCalled_o == 1);
    test_assert(*test_constructCalled_o == 1);
    test_assert(*test_destructCalled_o == 1);

/* $end */
}

corto_void _test_ObjectMgmt_tc_createChildFooAttr0(
    test_ObjectMgmt this)
{
/* $begin(test/ObjectMgmt/tc_createChildFooAttr0) */

    corto_setAttr(0);
    test_Foo o = corto_createChild(NULL, "o", test_Foo_o);
    test_assert(o != NULL);
    test_assert(!strcmp(corto_idof(o), "o"));
    test_assert(corto_parentof(o) == root_o);
    test_assert(corto_typeof(o) == (corto_type)test_Foo_o);
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_WRITABLE));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_PERSISTENT));

    corto_object p = corto_resolve(NULL, "o");
    test_assert(o == p);
    corto_release(p);

    /* Test if constructor is correctly executed */
    test_assert(o->x == 11);
    test_assert(o->y == 22);

    corto_delete(o);

    corto_object q = corto_resolve(NULL, "o");
    test_assert(q == NULL);

    test_assert(*test_initCalled_o == 1);
    test_assert(*test_constructCalled_o == 1);
    test_assert(*test_destructCalled_o == 1);

/* $end */
}

corto_void _test_ObjectMgmt_tc_createChildInitFail(
    test_ObjectMgmt this)
{
/* $begin(test/ObjectMgmt/tc_createChildInitFail) */

    corto_object o = corto_createChild(NULL, "o", test_Bar_o);
    test_assert(o == NULL);
    test_assert(!strcmp(corto_lasterr(), "init for 'o' of '/test/Bar' failed: /test/Bar/init failed"));

/* $end */
}

corto_void _test_ObjectMgmt_tc_createChildInt(
    test_ObjectMgmt this)
{
/* $begin(test/ObjectMgmt/tc_createChildInt) */

    corto_object o = corto_createChild(NULL, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(!strcmp(corto_idof(o), "o"));
    test_assert(corto_parentof(o) == root_o);
    test_assert(corto_typeof(o) == (corto_type)corto_int32_o);
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));

    corto_object p = corto_resolve(NULL, "o");
    test_assert(o == p);
    corto_release(p);

    corto_delete(o);

    corto_object q = corto_resolve(NULL, "o");
    test_assert(q == NULL);

/* $end */
}

corto_void _test_ObjectMgmt_tc_createChildIntAttr0(
    test_ObjectMgmt this)
{
/* $begin(test/ObjectMgmt/tc_createChildIntAttr0) */

    corto_setAttr(0);
    corto_object o = corto_createChild(NULL, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(!strcmp(corto_idof(o), "o"));
    test_assert(corto_parentof(o) == root_o);
    test_assert(corto_typeof(o) == (corto_type)corto_int32_o);
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_WRITABLE));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_PERSISTENT));

    corto_object p = corto_resolve(NULL, "o");
    test_assert(o == p);
    corto_release(p);

    corto_delete(o);

    corto_object q = corto_resolve(NULL, "o");
    test_assert(q == NULL);

/* $end */
}

corto_void _test_ObjectMgmt_tc_createChildInvalidType(
    test_ObjectMgmt this)
{
/* $begin(test/ObjectMgmt/tc_createChildInvalidType) */

    corto_type t = corto_type(corto_intCreateChild(NULL, "invalid", CORTO_WIDTH_8, 0, 0));
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_int_o));
    test_assert(corto_checkState(t, CORTO_VALID));
    test_assert(corto_checkState(t, CORTO_DECLARED));
    test_assert(corto_checkState(t, CORTO_DEFINED));
    test_assert(corto_checkAttr(t, CORTO_ATTR_SCOPED));
    test_assert(corto_checkAttr(t, CORTO_ATTR_WRITABLE));
    test_assert(corto_checkAttr(t, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(t, CORTO_ATTR_PERSISTENT));

    corto_invalidate(t);
    test_assert(!corto_checkState(t, CORTO_VALID));

    corto_object o = corto_create(t);
    test_assert(o == NULL);
    test_assert(!strcmp(corto_lasterr(), "type '/invalid' is not valid/defined"));

/* $end */
}

corto_void _test_ObjectMgmt_tc_createChildNested(
    test_ObjectMgmt this)
{
/* $begin(test/ObjectMgmt/tc_createChildNested) */

    test_Foo o = corto_createChild(NULL, "o", test_Foo_o);
    test_assert(o != NULL);
    test_assert(!strcmp(corto_idof(o), "o"));
    test_assert(corto_parentof(o) == root_o);
    test_assert(corto_typeof(o) == (corto_type)test_Foo_o);
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));

    test_Foo p = corto_createChild(o, "p", test_Foo_o);
    test_assert(p != NULL);
    test_assert(!strcmp(corto_idof(p), "p"));
    test_assert(corto_parentof(p) == o);
    test_assert(corto_typeof(p) == (corto_type)test_Foo_o);
    test_assert(corto_checkState(p, CORTO_VALID));
    test_assert(corto_checkState(p, CORTO_DECLARED));
    test_assert(corto_checkState(p, CORTO_DEFINED));
    test_assert(corto_checkAttr(p, CORTO_ATTR_SCOPED));
    test_assert(corto_checkAttr(p, CORTO_ATTR_WRITABLE));
    test_assert(corto_checkAttr(p, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(p, CORTO_ATTR_PERSISTENT));

    test_Foo q = corto_createChild(p, "q", test_Foo_o);
    test_assert(p != NULL);
    test_assert(!strcmp(corto_idof(q), "q"));
    test_assert(corto_parentof(q) == p);
    test_assert(corto_typeof(q) == (corto_type)test_Foo_o);
    test_assert(corto_checkState(q, CORTO_VALID));
    test_assert(corto_checkState(q, CORTO_DECLARED));
    test_assert(corto_checkState(q, CORTO_DEFINED));
    test_assert(corto_checkAttr(q, CORTO_ATTR_SCOPED));
    test_assert(corto_checkAttr(q, CORTO_ATTR_WRITABLE));
    test_assert(corto_checkAttr(q, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(q, CORTO_ATTR_PERSISTENT));

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

/* $end */
}

corto_void _test_ObjectMgmt_tc_createChildNullType(
    test_ObjectMgmt this)
{
/* $begin(test/ObjectMgmt/tc_createChildNullType) */

    corto_object o = corto_createChild(NULL, "o", NULL);
    test_assert(o == NULL);
    test_assert(!strcmp(corto_lasterr(), "parameter 'type' is null"));

/* $end */
}

corto_void _test_ObjectMgmt_tc_createChildParentStateErr(
    test_ObjectMgmt this)
{
/* $begin(test/ObjectMgmt/tc_createChildParentStateErr) */

    corto_object o = corto_declareChild(NULL, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(!corto_checkState(o, CORTO_DEFINED));

    corto_object p = corto_createChild(o, "p", test_DefinedParent_o);
    test_assert(!strcmp(corto_lasterr(), "init for 'p' of '/test/DefinedParent' failed: parent '/o' is VALID|DECLARED, must be DEFINED"));
    test_assert(p == NULL);

    corto_object q = test_DefinedParentCreateChild(o, "q", 0);
    test_assert(!strcmp(corto_lasterr(), "init for 'q' of '/test/DefinedParent' failed: parent '/o' is VALID|DECLARED, must be DEFINED"));
    test_assert(q == NULL);

    corto_delete(o);

/* $end */
}

corto_void _test_ObjectMgmt_tc_createChildParentTypeErr(
    test_ObjectMgmt this)
{
/* $begin(test/ObjectMgmt/tc_createChildParentTypeErr) */

    corto_object o = corto_declareChild(NULL, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(!corto_checkState(o, CORTO_DEFINED));

    corto_object p = corto_createChild(o, "p", test_VoidParent_o);
    test_assert(!strcmp(corto_lasterr(), "init for 'p' of '/test/VoidParent' failed: type of '/o' is not 'void'"));
    test_assert(p == NULL);

    corto_object q = test_VoidParentCreateChild(o, "q", 0);
    test_assert(!strcmp(corto_lasterr(), "init for 'q' of '/test/VoidParent' failed: type of '/o' is not 'void'"));
    test_assert(q == NULL);

    corto_delete(o);

/* $end */
}

corto_void _test_ObjectMgmt_tc_createChildVoid(
    test_ObjectMgmt this)
{
/* $begin(test/ObjectMgmt/tc_createChildVoid) */

    corto_object o = corto_declareChild(NULL, "o", corto_void_o);
    test_assert(o != NULL);
    test_assert(!strcmp(corto_idof(o), "o"));
    test_assert(corto_parentof(o) == root_o);
    test_assert(corto_typeof(o) == corto_void_o);
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_WRITABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));

    corto_object p = corto_resolve(NULL, "o");
    test_assert(o == p);
    corto_release(p);

    corto_delete(o);

    corto_object q = corto_resolve(NULL, "o");
    test_assert(q == NULL);

/* $end */
}

corto_void _test_ObjectMgmt_tc_createChildVoidAttr0(
    test_ObjectMgmt this)
{
/* $begin(test/ObjectMgmt/tc_createChildVoidAttr0) */

    corto_setAttr(0);
    corto_object o = corto_createChild(NULL, "o", corto_void_o);
    test_assert(o != NULL);
    test_assert(!strcmp(corto_idof(o), "o"));
    test_assert(corto_parentof(o) == root_o);
    test_assert(corto_typeof(o) == corto_void_o);
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_WRITABLE));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_PERSISTENT));

    corto_object p = corto_resolve(NULL, "o");
    test_assert(o == p);
    corto_release(p);

    corto_delete(o);

    corto_object q = corto_resolve(NULL, "o");
    test_assert(q == NULL);

/* $end */
}

corto_void _test_ObjectMgmt_tc_createFoo(
    test_ObjectMgmt this)
{
/* $begin(test/ObjectMgmt/tc_createFoo) */

    test_Foo o = corto_create(test_Foo_o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == (corto_type)test_Foo_o);
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_SCOPED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_PERSISTENT));

    /* Test if constructor is correctly executed */
    test_assert(o->x == 11);
    test_assert(o->y == 22);

    corto_delete(o);

    test_assert(*test_initCalled_o == 1);
    test_assert(*test_constructCalled_o == 1);
    test_assert(*test_destructCalled_o == 1);

/* $end */
}

corto_void _test_ObjectMgmt_tc_createFooAttr0(
    test_ObjectMgmt this)
{
/* $begin(test/ObjectMgmt/tc_createFooAttr0) */

    corto_setAttr(0);
    test_Foo o = corto_create(test_Foo_o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == (corto_type)test_Foo_o);
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_SCOPED));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_WRITABLE));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_PERSISTENT));

    /* Test if constructor is correctly executed */
    test_assert(o->x == 11);
    test_assert(o->y == 22);

    corto_delete(o);

    test_assert(*test_initCalled_o == 1);
    test_assert(*test_constructCalled_o == 1);
    test_assert(*test_destructCalled_o == 1);

/* $end */
}

corto_void _test_ObjectMgmt_tc_createInitFail(
    test_ObjectMgmt this)
{
/* $begin(test/ObjectMgmt/tc_createInitFail) */

    corto_object o = corto_create(test_Bar_o);
    test_assert(o == NULL);
    test_assert(!strcmp(corto_lasterr(), "/test/Bar/init failed"));

/* $end */
}

corto_void _test_ObjectMgmt_tc_createInt(
    test_ObjectMgmt this)
{
/* $begin(test/ObjectMgmt/tc_createInt) */

    corto_object o = corto_create(corto_int32_o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == (corto_type)corto_int32_o);
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_SCOPED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    corto_delete(o);

/* $end */
}

corto_void _test_ObjectMgmt_tc_createIntAttr0(
    test_ObjectMgmt this)
{
/* $begin(test/ObjectMgmt/tc_createIntAttr0) */

    corto_setAttr(0);
    corto_object o = corto_create(corto_int32_o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == (corto_type)corto_int32_o);
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_SCOPED));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_WRITABLE));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    corto_delete(o);

/* $end */
}

corto_void _test_ObjectMgmt_tc_createInvalidType(
    test_ObjectMgmt this)
{
/* $begin(test/ObjectMgmt/tc_createInvalidType) */

    corto_type t = corto_type(corto_intCreateChild(NULL, "invalid", CORTO_WIDTH_8, 0, 0));
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_int_o));
    test_assert(corto_checkState(t, CORTO_VALID));
    test_assert(corto_checkState(t, CORTO_DECLARED));
    test_assert(corto_checkState(t, CORTO_DEFINED));
    test_assert(corto_checkAttr(t, CORTO_ATTR_SCOPED));
    test_assert(corto_checkAttr(t, CORTO_ATTR_WRITABLE));
    test_assert(corto_checkAttr(t, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(t, CORTO_ATTR_PERSISTENT));

    corto_invalidate(t);
    test_assert(!corto_checkState(t, CORTO_VALID));

    corto_object o = corto_create(t);
    test_assert(!strcmp(corto_lasterr(), "type '/invalid' is not valid/defined"));
    test_assert(o == NULL);

/* $end */
}

corto_void _test_ObjectMgmt_tc_createNullType(
    test_ObjectMgmt this)
{
/* $begin(test/ObjectMgmt/tc_createNullType) */

    corto_object o = corto_create(NULL);
    test_assert(o == NULL);
    test_assert(!strcmp(corto_lasterr(), "parameter 'type' is null"));

/* $end */
}

corto_void _test_ObjectMgmt_tc_createVoid(
    test_ObjectMgmt this)
{
/* $begin(test/ObjectMgmt/tc_createVoid) */

    corto_object o = corto_create(corto_void_o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_void_o);
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_SCOPED));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_WRITABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    corto_delete(o);

/* $end */
}

corto_void _test_ObjectMgmt_tc_createVoidAttr0(
    test_ObjectMgmt this)
{
/* $begin(test/ObjectMgmt/tc_createVoidAttr0) */

    corto_setAttr(0);
    corto_object o = corto_create(corto_void_o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == (corto_type)corto_void_o);
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_SCOPED));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_WRITABLE));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    corto_delete(o);

/* $end */
}

corto_void _test_ObjectMgmt_tc_declareChildFoo(
    test_ObjectMgmt this)
{
/* $begin(test/ObjectMgmt/tc_declareChildFoo) */

    test_Foo o = corto_declareChild(NULL, "o", test_Foo_o);
    test_assert(o != NULL);
    test_assert(!strcmp(corto_idof(o), "o"));
    test_assert(corto_parentof(o) == root_o);
    test_assert(corto_typeof(o) == (corto_type)test_Foo_o);
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(!corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));

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

/* $end */
}

corto_void _test_ObjectMgmt_tc_declareChildFooAttr0(
    test_ObjectMgmt this)
{
/* $begin(test/ObjectMgmt/tc_declareChildFooAttr0) */

    corto_setAttr(0);
    test_Foo o = corto_declareChild(NULL, "o", test_Foo_o);
    test_assert(o != NULL);
    test_assert(!strcmp(corto_idof(o), "o"));
    test_assert(corto_parentof(o) == root_o);
    test_assert(corto_typeof(o) == (corto_type)test_Foo_o);
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(!corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_WRITABLE));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_PERSISTENT));

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

/* $end */
}

corto_void _test_ObjectMgmt_tc_declareChildInitFail(
    test_ObjectMgmt this)
{
/* $begin(test/ObjectMgmt/tc_declareChildInitFail) */

    corto_object o = corto_declareChild(NULL, "o", test_Bar_o);
    test_assert(o == NULL);
    test_assert(!strcmp(corto_lasterr(), "init for 'o' of '/test/Bar' failed: /test/Bar/init failed"));

/* $end */
}

corto_void _test_ObjectMgmt_tc_declareChildInt(
    test_ObjectMgmt this)
{
/* $begin(test/ObjectMgmt/tc_declareChildInt) */

    corto_object o = corto_declareChild(NULL, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(!strcmp(corto_idof(o), "o"));
    test_assert(corto_parentof(o) == root_o);
    test_assert(corto_typeof(o) == (corto_type)corto_int32_o);
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(!corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));

    corto_object p = corto_resolve(NULL, "o");
    test_assert(o == p);
    corto_release(p);

    p = corto_declareChild(NULL, "o", corto_int32_o);
    test_assert(o == p);
    corto_delete(p);

    corto_delete(o);

    corto_object q = corto_resolve(NULL, "o");
    test_assert(q == NULL);

/* $end */
}

corto_void _test_ObjectMgmt_tc_declareChildIntAttr0(
    test_ObjectMgmt this)
{
/* $begin(test/ObjectMgmt/tc_declareChildIntAttr0) */

    corto_setAttr(0);
    corto_object o = corto_declareChild(NULL, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(!strcmp(corto_idof(o), "o"));
    test_assert(corto_parentof(o) == root_o);
    test_assert(corto_typeof(o) == (corto_type)corto_int32_o);
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(!corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_WRITABLE));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_PERSISTENT));

    corto_object p = corto_resolve(NULL, "o");
    test_assert(o == p);
    corto_release(p);

    corto_delete(o);

    corto_object q = corto_resolve(NULL, "o");
    test_assert(q == NULL);

/* $end */
}

corto_void _test_ObjectMgmt_tc_declareChildInvalidType(
    test_ObjectMgmt this)
{
/* $begin(test/ObjectMgmt/tc_declareChildInvalidType) */

    corto_type t = corto_type(corto_intCreateChild(NULL, "invalid", CORTO_WIDTH_8, 0, 0));
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_int_o));
    test_assert(corto_checkState(t, CORTO_VALID));
    test_assert(corto_checkState(t, CORTO_DECLARED));
    test_assert(corto_checkState(t, CORTO_DEFINED));
    test_assert(corto_checkAttr(t, CORTO_ATTR_SCOPED));
    test_assert(corto_checkAttr(t, CORTO_ATTR_WRITABLE));
    test_assert(corto_checkAttr(t, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(t, CORTO_ATTR_PERSISTENT));

    corto_invalidate(t);
    test_assert(!corto_checkState(t, CORTO_VALID));

    corto_object o = corto_declareChild(NULL, "foo", t);
    test_assert(o == NULL);

/* $end */
}

corto_void _test_ObjectMgmt_tc_declareChildNullType(
    test_ObjectMgmt this)
{
/* $begin(test/ObjectMgmt/tc_declareChildNullType) */

    corto_object o = corto_declareChild(NULL, "o", NULL);
    test_assert(o == NULL);
    test_assert(!strcmp(corto_lasterr(), "parameter 'type' is null"));

/* $end */
}

corto_void _test_ObjectMgmt_tc_declareChildParentStateErr(
    test_ObjectMgmt this)
{
/* $begin(test/ObjectMgmt/tc_declareChildParentStateErr) */

    corto_object o = corto_declareChild(NULL, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(!corto_checkState(o, CORTO_DEFINED));

    corto_object p = corto_declareChild(o, "p", test_DefinedParent_o);
    test_assert(p == NULL);
    test_assertstr(corto_lasterr(), "init for 'p' of '/test/DefinedParent' failed: parent '/o' is VALID|DECLARED, must be DEFINED");

    corto_object q = test_DefinedParentDeclareChild(o, "q");
    test_assert(q == NULL);
    test_assertstr(corto_lasterr(), "init for 'q' of '/test/DefinedParent' failed: parent '/o' is VALID|DECLARED, must be DEFINED");

    corto_delete(o);

/* $end */
}

corto_void _test_ObjectMgmt_tc_declareChildParentTypeErr(
    test_ObjectMgmt this)
{
/* $begin(test/ObjectMgmt/tc_declareChildParentTypeErr) */

    corto_object o = corto_declareChild(NULL, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(!corto_checkState(o, CORTO_DEFINED));

    corto_object p = corto_declareChild(o, "p", test_VoidParent_o);
    test_assert(!strcmp(corto_lasterr(), "init for 'p' of '/test/VoidParent' failed: type of '/o' is not 'void'"));
    test_assert(p == NULL);

    corto_object q = test_VoidParentDeclareChild(o, "q");
    test_assert(!strcmp(corto_lasterr(), "init for 'q' of '/test/VoidParent' failed: type of '/o' is not 'void'"));
    test_assert(q == NULL);

    corto_delete(o);

/* $end */
}

corto_void _test_ObjectMgmt_tc_declareChildVoid(
    test_ObjectMgmt this)
{
/* $begin(test/ObjectMgmt/tc_declareChildVoid) */

    corto_object o = corto_declareChild(NULL, "o", corto_void_o);
    test_assert(o != NULL);
    test_assert(!strcmp(corto_idof(o), "o"));
    test_assert(corto_parentof(o) == root_o);
    test_assert(corto_typeof(o) == corto_void_o);
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_WRITABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_PERSISTENT));

    corto_object p = corto_resolve(NULL, "o");
    test_assert(o == p);
    corto_release(p);

    corto_delete(o);

    corto_object q = corto_resolve(NULL, "o");
    test_assert(q == NULL);

/* $end */
}

corto_void _test_ObjectMgmt_tc_declareChildVoidAttr0(
    test_ObjectMgmt this)
{
/* $begin(test/ObjectMgmt/tc_declareChildVoidAttr0) */

    corto_setAttr(0);
    corto_object o = corto_declareChild(NULL, "o", corto_void_o);
    test_assert(o != NULL);
    test_assert(!strcmp(corto_idof(o), "o"));
    test_assert(corto_parentof(o) == root_o);
    test_assert(corto_typeof(o) == corto_void_o);
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_SCOPED));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_WRITABLE));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_PERSISTENT));

    corto_object p = corto_resolve(NULL, "o");
    test_assert(o == p);
    corto_release(p);

    corto_delete(o);

    corto_object q = corto_resolve(NULL, "o");
    test_assert(q == NULL);

/* $end */
}

corto_void _test_ObjectMgmt_tc_declareExistingWithParentState(
    test_ObjectMgmt this)
{
/* $begin(test/ObjectMgmt/tc_declareExistingWithParentState) */

    corto_struct s = corto_structDeclareChild(NULL, "s");
    test_assert(s != NULL);

    corto_member m = corto_memberCreateChild(s, "m", corto_type(corto_uint32_o), CORTO_GLOBAL);
    test_assert(m != NULL);

    corto_int16 ret = corto_define(s);
    test_assert(ret == 0);

    /* Validate I can redeclare member after struct has been defined */
    corto_member n = corto_memberDeclareChild(s, "m");
    test_assert(n != NULL);
    test_assert(corto_checkState(n, CORTO_DEFINED));

    ret = corto_define(n);
    test_assert(ret == 0);

    corto_delete(n);
    corto_delete(m);
    corto_delete(s);

/* $end */
}

corto_void _test_ObjectMgmt_tc_declareFoo(
    test_ObjectMgmt this)
{
/* $begin(test/ObjectMgmt/tc_declareFoo) */

    test_Foo o = corto_declare(test_Foo_o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == (corto_type)test_Foo_o);
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(!corto_checkState(o, CORTO_DEFINED));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_SCOPED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_PERSISTENT));

    /* Test if initializer is correctly executed */
    test_assert(o->x == 1);
    test_assert(o->y == 2);

    corto_delete(o);

    test_assert(*test_initCalled_o == 1);
    test_assert(*test_constructCalled_o == 0);
    test_assert(*test_destructCalled_o == 0);

/* $end */
}

corto_void _test_ObjectMgmt_tc_declareFooAttr0(
    test_ObjectMgmt this)
{
/* $begin(test/ObjectMgmt/tc_declareFooAttr0) */

    corto_setAttr(0);
    test_Foo o = corto_declare(test_Foo_o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == (corto_type)test_Foo_o);
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(!corto_checkState(o, CORTO_DEFINED));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_SCOPED));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_WRITABLE));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_PERSISTENT));

    /* Test if initializer is correctly executed */
    test_assert(o->x == 1);
    test_assert(o->y == 2);

    corto_delete(o);

    test_assert(*test_initCalled_o == 1);
    test_assert(*test_constructCalled_o == 0);
    test_assert(*test_destructCalled_o == 0);


/* $end */
}

corto_void _test_ObjectMgmt_tc_declareInitFail(
    test_ObjectMgmt this)
{
/* $begin(test/ObjectMgmt/tc_declareInitFail) */

    corto_object o = corto_declare(test_Bar_o);
    test_assert(o == NULL);
    test_assert(!strcmp(corto_lasterr(), "/test/Bar/init failed"));

/* $end */
}

corto_void _test_ObjectMgmt_tc_declareInt(
    test_ObjectMgmt this)
{
/* $begin(test/ObjectMgmt/tc_declareInt) */

    corto_object o = corto_declare(corto_int32_o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == (corto_type)corto_int32_o);
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(!corto_checkState(o, CORTO_DEFINED));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_SCOPED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    corto_delete(o);

/* $end */
}

corto_void _test_ObjectMgmt_tc_declareIntAttr0(
    test_ObjectMgmt this)
{
/* $begin(test/ObjectMgmt/tc_declareIntAttr0) */

    corto_setAttr(0);
    corto_object o = corto_declare(corto_int32_o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == (corto_type)corto_int32_o);
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(!corto_checkState(o, CORTO_DEFINED));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_SCOPED));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_WRITABLE));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    corto_delete(o);

/* $end */
}

corto_void _test_ObjectMgmt_tc_declareInvalidType(
    test_ObjectMgmt this)
{
/* $begin(test/ObjectMgmt/tc_declareInvalidType) */

    corto_type t = corto_type(corto_intCreateChild(NULL, "invalid", CORTO_WIDTH_8, 0, 0));
    test_assert(t != NULL);
    test_assert(corto_typeof(t) == corto_type(corto_int_o));
    test_assert(corto_checkState(t, CORTO_VALID));
    test_assert(corto_checkState(t, CORTO_DECLARED));
    test_assert(corto_checkState(t, CORTO_DEFINED));
    test_assert(corto_checkAttr(t, CORTO_ATTR_SCOPED));
    test_assert(corto_checkAttr(t, CORTO_ATTR_WRITABLE));
    test_assert(corto_checkAttr(t, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(t, CORTO_ATTR_PERSISTENT));

    corto_invalidate(t);
    test_assert(!corto_checkState(t, CORTO_VALID));

    corto_object o = corto_declare(t);
    test_assert(o == NULL);

/* $end */
}

corto_void _test_ObjectMgmt_tc_declareNullType(
    test_ObjectMgmt this)
{
/* $begin(test/ObjectMgmt/tc_declareNullType) */

    corto_object o = corto_declare(NULL);
    test_assert(o == NULL);
    test_assert(!strcmp(corto_lasterr(), "parameter 'type' is null"));

/* $end */
}

corto_void _test_ObjectMgmt_tc_declareOrphan(
    test_ObjectMgmt this)
{
/* $begin(test/ObjectMgmt/tc_declareOrphan) */
    corto_int16 ret;

    /* Create orphaned object */
    corto_object i = corto_declareOrphan(root_o, "i", corto_int32_o);
    test_assert(i != NULL);
    test_assert(corto_checkAttr(i, CORTO_ATTR_SCOPED));
    test_assertstr(corto_idof(i), "i");
    test_assert(corto_parentof(i) == root_o);
    test_assert(corto_childof(root_o, i));
    test_assert(!corto_isBuiltin(i));
    ret = corto_define(i);
    test_assert(ret == 0);

    /* Object should not be resolvable */
    test_assert(!corto_lookup(root_o, "i"));

    ret = corto_delete(i);
    test_assert(ret == 0);

/* $end */
}

corto_void _test_ObjectMgmt_tc_declareScoped(
    test_ObjectMgmt this)
{
/* $begin(test/ObjectMgmt/tc_declareScoped) */
    corto_int16 ret;

    /* Create scoped anonymous object (structs are always scoped) */
    corto_struct s = corto_declare(corto_struct_o);
    test_assert(s != NULL);
    test_assert(corto_checkAttr(s, CORTO_ATTR_SCOPED));
    test_assert(corto_idof(s) == NULL);
    test_assert(corto_parentof(s) == NULL);

    /* Create members in scope of anonymous object */
    corto_member x = corto_declareChild(s, "x", corto_member_o);
    test_assert(x != NULL);
    corto_setref(&x->type, corto_int32_o);
    ret = corto_define(x);
    test_assert(ret == 0);

    corto_member y = corto_declareChild(s, "y", corto_member_o);
    test_assert(y != NULL);
    corto_setref(&y->type, corto_int32_o);
    ret = corto_define(y);
    test_assert(ret == 0);

    /* Define struct */
    ret = corto_define(s);
    test_assert(ret == 0);

    /* Test type */
    corto_object p = corto_create(s);
    test_assert(p != NULL);
    *(corto_int32*)CORTO_OFFSET(p, x->offset) = 10;
    *(corto_int32*)CORTO_OFFSET(p, y->offset) = 20;
    test_assertstr("{10,20}", corto_contentof(NULL, "text/corto", p));

    ret = corto_delete(s);
    test_assert(ret == 0);

    ret = corto_delete(s);
    test_assert(ret == 0);

/* $end */
}

corto_void _test_ObjectMgmt_tc_declareVoid(
    test_ObjectMgmt this)
{
/* $begin(test/ObjectMgmt/tc_declareVoid) */

    corto_object o = corto_declare(corto_void_o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_void_o);
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_SCOPED));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_WRITABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    corto_delete(o);

/* $end */
}

corto_void _test_ObjectMgmt_tc_declareVoidAttr0(
    test_ObjectMgmt this)
{
/* $begin(test/ObjectMgmt/tc_declareVoidAttr0) */

    corto_setAttr(0);
    corto_object o = corto_declare(corto_void_o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == (corto_type)corto_void_o);
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_SCOPED));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_WRITABLE));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    corto_delete(o);

/* $end */
}

corto_void _test_ObjectMgmt_tc_defineFoo(
    test_ObjectMgmt this)
{
/* $begin(test/ObjectMgmt/tc_defineFoo) */

    test_Foo o = corto_declare(test_Foo_o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == (corto_type)test_Foo_o);
    test_assert(o->x == 1);
    test_assert(o->y == 2);
    test_assert(!corto_define(o));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_SCOPED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_PERSISTENT));

    /* Test if initializer is correctly executed */
    test_assert(o->x == 11);
    test_assert(o->y == 22);

    /* Test if constructor is executed only once */
    test_assert(!corto_define(o));

    test_assert(o->x == 11);
    test_assert(o->y == 22);

    corto_delete(o);

    test_assert(*test_initCalled_o == 1);
    test_assert(*test_constructCalled_o == 1);
    test_assert(*test_destructCalled_o == 1);

/* $end */
}

corto_void _test_ObjectMgmt_tc_defineFooAttr0(
    test_ObjectMgmt this)
{
/* $begin(test/ObjectMgmt/tc_defineFooAttr0) */

    corto_setAttr(0);
    test_Foo o = corto_declare(test_Foo_o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == (corto_type)test_Foo_o);
    test_assert(o->x == 1);
    test_assert(o->y == 2);
    test_assert(!corto_define(o));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_SCOPED));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_WRITABLE));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_PERSISTENT));

    /* Test if constructor is correctly executed */
    test_assert(o->x == 11);
    test_assert(o->y == 22);

    /* Test if constructor is executed only once */
    test_assert(!corto_define(o));

    test_assert(o->x == 11);
    test_assert(o->y == 22);

    corto_delete(o);

    test_assert(*test_initCalled_o == 1);
    test_assert(*test_constructCalled_o == 1);
    test_assert(*test_destructCalled_o == 1);

/* $end */
}

corto_void _test_ObjectMgmt_tc_defineFooFail(
    test_ObjectMgmt this)
{
/* $begin(test/ObjectMgmt/tc_defineFooFail) */

    test_Foo o = corto_declare(test_Foo_o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == (corto_type)test_Foo_o);
    test_assert(o->x == 1);
    test_assert(o->y == 2);

    o->fail = TRUE;
    test_assert(corto_define(o));

    test_assert(!corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(!corto_checkState(o, CORTO_DEFINED));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_SCOPED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_PERSISTENT));

    /* Test if constructor is not executed */
    test_assert(o->x == 1);
    test_assert(o->y == 2);

    /* Test if constructor fails 2nd time */
    test_assert(corto_define(o));
    test_assert(!corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(!corto_checkState(o, CORTO_DEFINED));

    /* Test if constructor is still not executed */
    test_assert(o->x == 1);
    test_assert(o->y == 2);

    /* Test if constructor succeeds after fixing error */
    o->fail = FALSE;
    test_assert(!corto_define(o));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));

    /* Test if constructor is executed */
    test_assert(o->x == 11);
    test_assert(o->y == 22);

    corto_delete(o);

/* $end */
}

corto_void _test_ObjectMgmt_tc_defineInt(
    test_ObjectMgmt this)
{
/* $begin(test/ObjectMgmt/tc_defineInt) */

    corto_object o = corto_declare(corto_int32_o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == (corto_type)corto_int32_o);
    test_assert(!corto_define(o));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_SCOPED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_WRITABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    corto_delete(o);

/* $end */
}

corto_void _test_ObjectMgmt_tc_defineIntAttr0(
    test_ObjectMgmt this)
{
/* $begin(test/ObjectMgmt/tc_defineIntAttr0) */

    corto_setAttr(0);
    corto_object o = corto_declare(corto_int32_o);
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == (corto_type)corto_int32_o);
    test_assert(!corto_define(o));
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_SCOPED));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_WRITABLE));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    corto_delete(o);

/* $end */
}

corto_void _test_ObjectMgmt_tc_defineVoid(
    test_ObjectMgmt this)
{
/* $begin(test/ObjectMgmt/tc_defineVoid) */

    corto_object o = corto_declare(corto_void_o);
    corto_define(o);

    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_void_o);
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_SCOPED));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_WRITABLE));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    corto_delete(o);

/* $end */
}

corto_void _test_ObjectMgmt_tc_defineVoidAttr0(
    test_ObjectMgmt this)
{
/* $begin(test/ObjectMgmt/tc_defineVoidAttr0) */

    corto_setAttr(0);
    corto_object o = corto_declare(corto_void_o);
    corto_define(o);

    test_assert(o != NULL);
    test_assert(corto_typeof(o) == (corto_type)corto_void_o);
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_SCOPED));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_WRITABLE));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));
    test_assert(!corto_checkAttr(o, CORTO_ATTR_PERSISTENT));
    corto_delete(o);

/* $end */
}

corto_void _test_ObjectMgmt_tc_deleteRedeclaration(
    test_ObjectMgmt this)
{
/* $begin(test/ObjectMgmt/tc_deleteRedeclaration) */
    corto_int16 result;
    test_Foo o = corto_createChild(NULL, "o", test_Foo_o);
    test_assert(o != NULL);
    test_assert(corto_countof(o) == 1);

    test_assert(*test_initCalled_o == 1);
    test_assert(*test_constructCalled_o == 1);
    test_assert(*test_destructCalled_o == 0);

    /* Redeclare object */
    test_Foo o2 = corto_createChild(NULL, "o", test_Foo_o);
    test_assert(o2 != NULL);
    test_assert(o == o2);
    test_assert(corto_countof(o) == 2);

    test_assert(*test_initCalled_o == 1);
    test_assert(*test_constructCalled_o == 1);
    test_assert(*test_destructCalled_o == 0);

    test_EventTest e = test_EventTestCreate(o);
    test_assert(corto_countof(o) == 4);

    corto_object p = corto_resolve(NULL, "o");
    test_assert(p == o);
    test_assert(corto_countof(o) == 5);
    corto_release(p);
    test_assert(corto_countof(o) == 4);

    test_assert(e->countDeclareSelf == 1);
    test_assert(e->countDefineSelf == 1);
    test_assert(e->countDeleteSelf == 0);
    test_assert(e->countDeleteScope == 0);
    test_assert(e->countDeleteTree == 0);

    result = corto_delete(o);
    test_assert(result == 0);
    test_assert(corto_countof(o) == 3);

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
    test_assert(corto_countof(o) == 2);

    test_assert(e->countDeleteSelf == 1);
    test_assert(e->countDeleteScope == 0);
    test_assert(e->countDeleteTree == 0);

    test_assert(*test_initCalled_o == 1);
    test_assert(*test_constructCalled_o == 1);
    test_assert(*test_destructCalled_o == 1);

    corto_delete(e);

/* $end */
}

corto_void _test_ObjectMgmt_tc_deleteSingle(
    test_ObjectMgmt this)
{
/* $begin(test/ObjectMgmt/tc_deleteSingle) */
    corto_int16 result;
    test_Foo o = corto_createChild(NULL, "o", test_Foo_o);
    test_assert(o != NULL);

    test_EventTest e = test_EventTestCreate(o);

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

/* $end */
}

corto_void _test_ObjectMgmt_tc_deleteTreeExplicit(
    test_ObjectMgmt this)
{
/* $begin(test/ObjectMgmt/tc_deleteTreeExplicit) */
    corto_int16 result;
    test_Foo o = corto_createChild(NULL, "o", test_Foo_o);
    test_assert(o != NULL);

    test_Foo o_o = corto_createChild(o, "o", test_Foo_o);
    test_assert(o_o != NULL);
    test_assert(o_o != o);

    test_Foo o_o_o = corto_createChild(o_o, "o", test_Foo_o);
    test_assert(o_o_o != NULL);
    test_assert(o_o_o != o_o);
    test_assert(o_o_o != o);

    test_EventTest e = test_EventTestCreate(o);

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

/* $end */
}

corto_void _test_ObjectMgmt_tc_deleteTreeImplicit(
    test_ObjectMgmt this)
{
/* $begin(test/ObjectMgmt/tc_deleteTreeImplicit) */
    corto_int16 result;
    test_Foo o = corto_createChild(NULL, "o", test_Foo_o);
    test_assert(o != NULL);

    test_Foo o_o = corto_createChild(o, "o", test_Foo_o);
    test_assert(o_o != NULL);
    test_assert(o_o != o);

    test_Foo o_o_o = corto_createChild(o_o, "o", test_Foo_o);
    test_assert(o_o_o != NULL);
    test_assert(o_o_o != o_o);
    test_assert(o_o_o != o);

    test_EventTest e = test_EventTestCreate(o);

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

/* $end */
}

corto_void _test_ObjectMgmt_tc_deleteWithReference(
    test_ObjectMgmt this)
{
/* $begin(test/ObjectMgmt/tc_deleteWithReference) */
    corto_int16 result;
    test_Foo o = corto_createChild(NULL, "o", test_Foo_o);
    test_assert(o != NULL);
    test_assert(corto_countof(o) == 1);

    test_EventTest e = test_EventTestCreate(o);
    test_assert(corto_countof(o) == 3); /* e holds 2 references */

    corto_object p = corto_resolve(NULL, "o");
    test_assert(p == o);
    test_assert(corto_countof(o) == 4);

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
    test_assert(corto_countof(o) == 3);

    test_assert(e->countDeleteSelf == 1);
    test_assert(e->countDeleteScope == 0);
    test_assert(e->countDeleteTree == 0);

    test_assert(*test_initCalled_o == 1);
    test_assert(*test_constructCalled_o == 1);
    test_assert(*test_destructCalled_o == 1);

    corto_object q = corto_resolve(NULL, "o");
    test_assert(q == NULL);
    test_assert(corto_countof(o) == 3);

    result = corto_release(o);
    test_assert(result == 2); /* Refcount should be 2 */

    /* This will get rid of the remaining 2 references */
    corto_delete(e);

/* $end */
}

corto_void _test_ObjectMgmt_tc_invalidate(
    test_ObjectMgmt this)
{
/* $begin(test/ObjectMgmt/tc_invalidate) */

    corto_object o = corto_voidCreate();
    test_assert(o != NULL);
    test_assert(corto_typeof(o) == corto_void_o);
    test_assert(corto_checkState(o, CORTO_VALID));
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(corto_checkState(o, CORTO_DEFINED));
    test_assert(corto_checkAttr(o, CORTO_ATTR_OBSERVABLE));

    corto_invalidate(o);
    test_assert(!corto_checkState(o, CORTO_VALID));
    corto_delete(o);

/* $end */
}

corto_void _test_ObjectMgmt_tc_nameof(
    test_ObjectMgmt this)
{
/* $begin(test/ObjectMgmt/tc_nameof) */

    corto_int32CreateChild_auto(root_o, a, 10);
    test_assertstr(corto_nameof(NULL, a), "a");

/* $end */
}

corto_void _test_ObjectMgmt_tc_nameofOverride(
    test_ObjectMgmt this)
{
/* $begin(test/ObjectMgmt/tc_nameofOverride) */

    test_PointCreateChild_auto(root_o, p, 10, 20);
    test_assertstr(corto_nameof(NULL, p), "10,20");

/* $end */
}

corto_void _test_ObjectMgmt_tc_redeclareWithDifferentType(
    test_ObjectMgmt this)
{
/* $begin(test/ObjectMgmt/tc_redeclareWithDifferentType) */

    corto_float32DeclareChild(NULL, "a");
    corto_float32DeclareChild(NULL, "b");
    corto_float32DeclareChild(NULL, "c");

    corto_object a = corto_float64DeclareChild(NULL, "a");
    test_assert(a == NULL);
    test_assert(corto_lasterr() != NULL);
    test_assert(!strcmp(corto_lasterr(), "init for 'a' of 'float64' failed: 'a' is already declared with type 'float32'"));

    corto_object b = corto_float64DeclareChild(NULL, "b");
    test_assert(b == NULL);
    test_assert(corto_lasterr() != NULL);
    test_assert(!strcmp(corto_lasterr(), "init for 'b' of 'float64' failed: 'b' is already declared with type 'float32'"));

    corto_object c = corto_float64DeclareChild(NULL, "c");
    test_assert(c == NULL);
    test_assert(corto_lasterr() != NULL);
    test_assert(!strcmp(corto_lasterr(), "init for 'c' of 'float64' failed: 'c' is already declared with type 'float32'"));

/* $end */
}

corto_void _test_ObjectMgmt_teardown(
    test_ObjectMgmt this)
{
/* $begin(test/ObjectMgmt/teardown) */
    corto_setAttr(this->prevAttr);
/* $end */
}
