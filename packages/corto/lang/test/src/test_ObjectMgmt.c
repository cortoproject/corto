/* $CORTO_GENERATED
 *
 * test_ObjectMgmt.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "test.h"

corto_void _test_ObjectMgmt_setup(test_ObjectMgmt this) {
/* $begin(test/ObjectMgmt/setup) */
    this->prevAttr = corto_setAttr(CORTO_ATTR_DEFAULT);
    *test_initCalled_o = 0;
    *test_constructCalled_o = 0;
    *test_destructCalled_o = 0;
/* $end */
}

corto_void _test_ObjectMgmt_tc_createChildFoo(test_ObjectMgmt this) {
/* $begin(test/ObjectMgmt/tc_createChildFoo) */

    test_Foo o = corto_createChild(NULL, "o", test_Foo_o);
    test_assert(o != NULL);
    test_assert(!strcmp(corto_nameof(o), "o"));
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

corto_void _test_ObjectMgmt_tc_createChildFooAttr0(test_ObjectMgmt this) {
/* $begin(test/ObjectMgmt/tc_createChildFooAttr0) */

    corto_setAttr(0);
    test_Foo o = corto_createChild(NULL, "o", test_Foo_o);
    test_assert(o != NULL);
    test_assert(!strcmp(corto_nameof(o), "o"));
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

corto_void _test_ObjectMgmt_tc_createChildInitFail(test_ObjectMgmt this) {
/* $begin(test/ObjectMgmt/tc_createChildInitFail) */

    corto_object o = corto_createChild(NULL, "o", test_Bar_o);
    test_assert(o == NULL);
    test_assert(!strcmp(corto_lasterr(), "/test/Bar/init failed"));

/* $end */
}

corto_void _test_ObjectMgmt_tc_createChildInt(test_ObjectMgmt this) {
/* $begin(test/ObjectMgmt/tc_createChildInt) */

    corto_object o = corto_createChild(NULL, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(!strcmp(corto_nameof(o), "o"));
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

corto_void _test_ObjectMgmt_tc_createChildIntAttr0(test_ObjectMgmt this) {
/* $begin(test/ObjectMgmt/tc_createChildIntAttr0) */

    corto_setAttr(0);
    corto_object o = corto_createChild(NULL, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(!strcmp(corto_nameof(o), "o"));
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

corto_void _test_ObjectMgmt_tc_createChildInvalidType(test_ObjectMgmt this) {
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
    test_assert(!strcmp(corto_lasterr(), "type is not valid/defined"));

/* $end */
}

corto_void _test_ObjectMgmt_tc_createChildNested(test_ObjectMgmt this) {
/* $begin(test/ObjectMgmt/tc_createChildNested) */

    test_Foo o = corto_createChild(NULL, "o", test_Foo_o);
    test_assert(o != NULL);
    test_assert(!strcmp(corto_nameof(o), "o"));
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
    test_assert(!strcmp(corto_nameof(p), "p"));
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
    test_assert(!strcmp(corto_nameof(q), "q"));
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

corto_void _test_ObjectMgmt_tc_createChildNullType(test_ObjectMgmt this) {
/* $begin(test/ObjectMgmt/tc_createChildNullType) */

    corto_object o = corto_createChild(NULL, "o", NULL);
    test_assert(o == NULL);
    test_assert(!strcmp(corto_lasterr(), "parameter 'type' is null"));

/* $end */
}

corto_void _test_ObjectMgmt_tc_createChildParentStateErr(test_ObjectMgmt this) {
/* $begin(test/ObjectMgmt/tc_createChildParentStateErr) */

    corto_object o = corto_declareChild(NULL, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(!corto_checkState(o, CORTO_DEFINED));

    corto_object p = corto_createChild(o, "p", test_DefinedParent_o);
    test_assert(!strcmp(corto_lasterr(), "'/o' is VALID|DECLARED, must be DEFINED"));
    test_assert(p == NULL);

    corto_object q = test_DefinedParentCreateChild(o, "q", 0);
    test_assert(!strcmp(corto_lasterr(), "'/o' is VALID|DECLARED, must be DEFINED"));
    test_assert(q == NULL);

    corto_delete(o);

/* $end */
}

corto_void _test_ObjectMgmt_tc_createChildParentTypeErr(test_ObjectMgmt this) {
/* $begin(test/ObjectMgmt/tc_createChildParentTypeErr) */

    corto_object o = corto_declareChild(NULL, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(!corto_checkState(o, CORTO_DEFINED));

    corto_object p = corto_createChild(o, "p", test_VoidParent_o);
    test_assert(!strcmp(corto_lasterr(), "type of '/o' is not '/corto/lang/void'"));
    test_assert(p == NULL);

    corto_object q = test_VoidParentCreateChild(o, "q", 0);
    test_assert(!strcmp(corto_lasterr(), "type of '/o' is not '/corto/lang/void'"));
    test_assert(q == NULL);

    corto_delete(o);

/* $end */
}

corto_void _test_ObjectMgmt_tc_createChildVoid(test_ObjectMgmt this) {
/* $begin(test/ObjectMgmt/tc_createChildVoid) */

    corto_object o = corto_declareChild(NULL, "o", corto_void_o);
    test_assert(o != NULL);
    test_assert(!strcmp(corto_nameof(o), "o"));
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

corto_void _test_ObjectMgmt_tc_createChildVoidAttr0(test_ObjectMgmt this) {
/* $begin(test/ObjectMgmt/tc_createChildVoidAttr0) */

    corto_setAttr(0);
    corto_object o = corto_createChild(NULL, "o", corto_void_o);
    test_assert(o != NULL);
    test_assert(!strcmp(corto_nameof(o), "o"));
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

corto_void _test_ObjectMgmt_tc_createFoo(test_ObjectMgmt this) {
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

corto_void _test_ObjectMgmt_tc_createFooAttr0(test_ObjectMgmt this) {
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

corto_void _test_ObjectMgmt_tc_createInitFail(test_ObjectMgmt this) {
/* $begin(test/ObjectMgmt/tc_createInitFail) */

    corto_object o = corto_create(test_Bar_o);
    test_assert(o == NULL);
    test_assert(!strcmp(corto_lasterr(), "/test/Bar/init failed"));

/* $end */
}

corto_void _test_ObjectMgmt_tc_createInt(test_ObjectMgmt this) {
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

corto_void _test_ObjectMgmt_tc_createIntAttr0(test_ObjectMgmt this) {
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

corto_void _test_ObjectMgmt_tc_createInvalidType(test_ObjectMgmt this) {
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
    test_assert(!strcmp(corto_lasterr(), "type is not valid/defined"));
    test_assert(o == NULL);

/* $end */
}

corto_void _test_ObjectMgmt_tc_createNullType(test_ObjectMgmt this) {
/* $begin(test/ObjectMgmt/tc_createNullType) */

    corto_object o = corto_create(NULL);
    test_assert(o == NULL);
    test_assert(!strcmp(corto_lasterr(), "parameter 'type' is null"));

/* $end */
}

corto_void _test_ObjectMgmt_tc_createVoid(test_ObjectMgmt this) {
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

corto_void _test_ObjectMgmt_tc_createVoidAttr0(test_ObjectMgmt this) {
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

corto_void _test_ObjectMgmt_tc_declareChildFoo(test_ObjectMgmt this) {
/* $begin(test/ObjectMgmt/tc_declareChildFoo) */

    test_Foo o = corto_declareChild(NULL, "o", test_Foo_o);
    test_assert(o != NULL);
    test_assert(!strcmp(corto_nameof(o), "o"));
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

corto_void _test_ObjectMgmt_tc_declareChildFooAttr0(test_ObjectMgmt this) {
/* $begin(test/ObjectMgmt/tc_declareChildFooAttr0) */

    corto_setAttr(0);
    test_Foo o = corto_declareChild(NULL, "o", test_Foo_o);
    test_assert(o != NULL);
    test_assert(!strcmp(corto_nameof(o), "o"));
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

corto_void _test_ObjectMgmt_tc_declareChildInitFail(test_ObjectMgmt this) {
/* $begin(test/ObjectMgmt/tc_declareChildInitFail) */

    corto_object o = corto_declareChild(NULL, "o", test_Bar_o);
    test_assert(o == NULL);
    test_assert(!strcmp(corto_lasterr(), "/test/Bar/init failed"));

/* $end */
}

corto_void _test_ObjectMgmt_tc_declareChildInt(test_ObjectMgmt this) {
/* $begin(test/ObjectMgmt/tc_declareChildInt) */

    corto_object o = corto_declareChild(NULL, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(!strcmp(corto_nameof(o), "o"));
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

corto_void _test_ObjectMgmt_tc_declareChildIntAttr0(test_ObjectMgmt this) {
/* $begin(test/ObjectMgmt/tc_declareChildIntAttr0) */

    corto_setAttr(0);
    corto_object o = corto_declareChild(NULL, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(!strcmp(corto_nameof(o), "o"));
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

corto_void _test_ObjectMgmt_tc_declareChildInvalidType(test_ObjectMgmt this) {
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

corto_void _test_ObjectMgmt_tc_declareChildNullType(test_ObjectMgmt this) {
/* $begin(test/ObjectMgmt/tc_declareChildNullType) */

    corto_object o = corto_declareChild(NULL, "o", NULL);
    test_assert(o == NULL);
    test_assert(!strcmp(corto_lasterr(), "parameter 'type' is null"));

/* $end */
}

corto_void _test_ObjectMgmt_tc_declareChildParentStateErr(test_ObjectMgmt this) {
/* $begin(test/ObjectMgmt/tc_declareChildParentStateErr) */

    corto_object o = corto_declareChild(NULL, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(!corto_checkState(o, CORTO_DEFINED));

    corto_object p = corto_declareChild(o, "p", test_DefinedParent_o);
    test_assert(p == NULL);

    corto_object q = test_DefinedParentDeclareChild(o, "q");
    test_assert(q == NULL);

    corto_delete(o);

/* $end */
}

corto_void _test_ObjectMgmt_tc_declareChildParentTypeErr(test_ObjectMgmt this) {
/* $begin(test/ObjectMgmt/tc_declareChildParentTypeErr) */

    corto_object o = corto_declareChild(NULL, "o", corto_int32_o);
    test_assert(o != NULL);
    test_assert(corto_checkState(o, CORTO_DECLARED));
    test_assert(!corto_checkState(o, CORTO_DEFINED));

    corto_object p = corto_declareChild(o, "p", test_VoidParent_o);
    test_assert(!strcmp(corto_lasterr(), "type of '/o' is not '/corto/lang/void'"));
    test_assert(p == NULL);

    corto_object q = test_VoidParentDeclareChild(o, "q");
    test_assert(!strcmp(corto_lasterr(), "type of '/o' is not '/corto/lang/void'"));
    test_assert(q == NULL);

    corto_delete(o);

/* $end */
}

corto_void _test_ObjectMgmt_tc_declareChildVoid(test_ObjectMgmt this) {
/* $begin(test/ObjectMgmt/tc_declareChildVoid) */

    corto_object o = corto_declareChild(NULL, "o", corto_void_o);
    test_assert(o != NULL);
    test_assert(!strcmp(corto_nameof(o), "o"));
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

corto_void _test_ObjectMgmt_tc_declareChildVoidAttr0(test_ObjectMgmt this) {
/* $begin(test/ObjectMgmt/tc_declareChildVoidAttr0) */

    corto_setAttr(0);
    corto_object o = corto_declareChild(NULL, "o", corto_void_o);
    test_assert(o != NULL);
    test_assert(!strcmp(corto_nameof(o), "o"));
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

corto_void _test_ObjectMgmt_tc_declareExistingWithParentState(test_ObjectMgmt this) {
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

corto_void _test_ObjectMgmt_tc_declareFoo(test_ObjectMgmt this) {
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

corto_void _test_ObjectMgmt_tc_declareFooAttr0(test_ObjectMgmt this) {
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

corto_void _test_ObjectMgmt_tc_declareInitFail(test_ObjectMgmt this) {
/* $begin(test/ObjectMgmt/tc_declareInitFail) */

    corto_object o = corto_declare(test_Bar_o);
    test_assert(o == NULL);
    test_assert(!strcmp(corto_lasterr(), "/test/Bar/init failed"));

/* $end */
}

corto_void _test_ObjectMgmt_tc_declareInt(test_ObjectMgmt this) {
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

corto_void _test_ObjectMgmt_tc_declareIntAttr0(test_ObjectMgmt this) {
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

corto_void _test_ObjectMgmt_tc_declareInvalidType(test_ObjectMgmt this) {
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

corto_void _test_ObjectMgmt_tc_declareNullType(test_ObjectMgmt this) {
/* $begin(test/ObjectMgmt/tc_declareNullType) */

    corto_object o = corto_declare(NULL);
    test_assert(o == NULL);
    test_assert(!strcmp(corto_lasterr(), "parameter 'type' is null"));

/* $end */
}

corto_void _test_ObjectMgmt_tc_declareVoid(test_ObjectMgmt this) {
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

corto_void _test_ObjectMgmt_tc_declareVoidAttr0(test_ObjectMgmt this) {
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

corto_void _test_ObjectMgmt_tc_defineFoo(test_ObjectMgmt this) {
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

corto_void _test_ObjectMgmt_tc_defineFooAttr0(test_ObjectMgmt this) {
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

corto_void _test_ObjectMgmt_tc_defineFooFail(test_ObjectMgmt this) {
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

corto_void _test_ObjectMgmt_tc_defineInt(test_ObjectMgmt this) {
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

corto_void _test_ObjectMgmt_tc_defineIntAttr0(test_ObjectMgmt this) {
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

corto_void _test_ObjectMgmt_tc_defineVoid(test_ObjectMgmt this) {
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

corto_void _test_ObjectMgmt_tc_defineVoidAttr0(test_ObjectMgmt this) {
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

corto_void _test_ObjectMgmt_tc_drop(test_ObjectMgmt this) {
/* $begin(test/ObjectMgmt/tc_drop) */

    test_Foo o = corto_createChild(NULL, "o", test_Foo_o);
    test_assert(o != NULL);
    test_assert(!strcmp(corto_nameof(o), "o"));
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
    test_assert(!strcmp(corto_nameof(p), "p"));
    test_assert(corto_parentof(p) == o);
    test_assert(corto_typeof(p) == (corto_type)test_Foo_o);
    test_assert(corto_checkState(p, CORTO_VALID));
    test_assert(corto_checkState(p, CORTO_DECLARED));
    test_assert(corto_checkState(p, CORTO_DEFINED));
    test_assert(corto_checkAttr(p, CORTO_ATTR_SCOPED));
    test_assert(corto_checkAttr(p, CORTO_ATTR_WRITABLE));
    test_assert(corto_checkAttr(p, CORTO_ATTR_OBSERVABLE));
    test_assert(corto_checkAttr(p, CORTO_ATTR_PERSISTENT));

    test_Foo q = corto_createChild(o, "q", test_Foo_o);
    test_assert(p != NULL);
    test_assert(!strcmp(corto_nameof(q), "q"));
    test_assert(corto_parentof(q) == o);
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

    corto_object _q = corto_resolve(NULL, "o/q");
    test_assert(_q == q);
    corto_release(_q);

    corto_drop(o);

    _p = corto_resolve(NULL, "o/p");
    test_assert(_p == NULL);

    _q = corto_resolve(NULL, "o/q");
    test_assert(_q == NULL);

    /* Arbitrary number of drops */
    corto_drop(o);
    corto_drop(o);
    corto_drop(o);

    test_assert(*test_initCalled_o == 3);
    test_assert(*test_constructCalled_o == 3);
    test_assert(*test_destructCalled_o == 2);

    corto_delete(o);

    test_assert(*test_destructCalled_o == 3);

/* $end */
}

corto_void _test_ObjectMgmt_tc_invalidate(test_ObjectMgmt this) {
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

corto_void _test_ObjectMgmt_tc_redeclareWithDifferentType(test_ObjectMgmt this) {
/* $begin(test/ObjectMgmt/tc_redeclareWithDifferentType) */

    corto_float32DeclareChild(NULL, "a");
    corto_float32DeclareChild(NULL, "b");
    corto_float32DeclareChild(NULL, "c");

    corto_object a = corto_float64DeclareChild(NULL, "a");
    test_assert(a == NULL);
    test_assert(corto_lasterr() != NULL);
    test_assert(!strcmp(corto_lasterr(), "'a' is already declared with a different type"));

    corto_object b = corto_float64DeclareChild(NULL, "b");
    test_assert(b == NULL);
    test_assert(corto_lasterr() != NULL);
    test_assert(!strcmp(corto_lasterr(), "'b' is already declared with a different type"));

    corto_object c = corto_float64DeclareChild(NULL, "c");
    test_assert(c == NULL);
    test_assert(corto_lasterr() != NULL);
    test_assert(!strcmp(corto_lasterr(), "'c' is already declared with a different type"));

/* $end */
}

corto_void _test_ObjectMgmt_teardown(test_ObjectMgmt this) {
/* $begin(test/ObjectMgmt/teardown) */
    corto_setAttr(this->prevAttr);
/* $end */
}
