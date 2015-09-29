/* test_ObjectMgmt.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "test.h"

/* ::test::ObjectMgmt::setup() */
cx_void _test_ObjectMgmt_setup(test_ObjectMgmt this) {
/* $begin(::test::ObjectMgmt::setup) */
    this->prevAttr = cx_setAttr(CX_ATTR_DEFAULT);
    *test_initCalled_o = 0;
    *test_constructCalled_o = 0;
    *test_destructCalled_o = 0;
/* $end */
}

/* ::test::ObjectMgmt::tc_createChildFoo() */
cx_void _test_ObjectMgmt_tc_createChildFoo(test_ObjectMgmt this) {
/* $begin(::test::ObjectMgmt::tc_createChildFoo) */

    test_Foo o = cx_createChild(NULL, "o", test_Foo_o);
    test_assert(o != NULL);
    test_assert(!strcmp(cx_nameof(o), "o"));
    test_assert(cx_parentof(o) == root_o);    
    test_assert(cx_typeof(o) == (cx_type)test_Foo_o);
    test_assert(cx_checkState(o, CX_VALID));
    test_assert(cx_checkState(o, CX_DECLARED));
    test_assert(cx_checkState(o, CX_DEFINED));
    test_assert(cx_checkAttr(o, CX_ATTR_SCOPED));
    test_assert(cx_checkAttr(o, CX_ATTR_WRITABLE));
    test_assert(cx_checkAttr(o, CX_ATTR_OBSERVABLE));
    test_assert(cx_checkAttr(o, CX_ATTR_PERSISTENT));

    cx_object p = cx_resolve(NULL, "o");
    test_assert(o == p);
    cx_release(p);

    /* Test if constructor is correctly executed */
    test_assert(o->x == 11);
    test_assert(o->y == 22);

    cx_delete(o);

    cx_object q = cx_resolve(NULL, "o");
    test_assert(q == NULL);

    test_assert(*test_initCalled_o == 1);
    test_assert(*test_constructCalled_o == 1);
    test_assert(*test_destructCalled_o == 1);

/* $end */
}

/* ::test::ObjectMgmt::tc_createChildFooAttr0() */
cx_void _test_ObjectMgmt_tc_createChildFooAttr0(test_ObjectMgmt this) {
/* $begin(::test::ObjectMgmt::tc_createChildFooAttr0) */

    cx_setAttr(0);
    test_Foo o = cx_createChild(NULL, "o", test_Foo_o);
    test_assert(o != NULL);
    test_assert(!strcmp(cx_nameof(o), "o"));
    test_assert(cx_parentof(o) == root_o);    
    test_assert(cx_typeof(o) == (cx_type)test_Foo_o);
    test_assert(cx_checkState(o, CX_VALID));
    test_assert(cx_checkState(o, CX_DECLARED));
    test_assert(cx_checkState(o, CX_DEFINED));
    test_assert(cx_checkAttr(o, CX_ATTR_SCOPED));
    test_assert(!cx_checkAttr(o, CX_ATTR_WRITABLE));
    test_assert(!cx_checkAttr(o, CX_ATTR_OBSERVABLE));
    test_assert(!cx_checkAttr(o, CX_ATTR_PERSISTENT));

    cx_object p = cx_resolve(NULL, "o");
    test_assert(o == p);
    cx_release(p);

    /* Test if constructor is correctly executed */
    test_assert(o->x == 11);
    test_assert(o->y == 22);

    cx_delete(o);

    cx_object q = cx_resolve(NULL, "o");
    test_assert(q == NULL);

    test_assert(*test_initCalled_o == 1);
    test_assert(*test_constructCalled_o == 1);
    test_assert(*test_destructCalled_o == 1);

/* $end */
}

/* ::test::ObjectMgmt::tc_createChildInitFail() */
cx_void _test_ObjectMgmt_tc_createChildInitFail(test_ObjectMgmt this) {
/* $begin(::test::ObjectMgmt::tc_createChildInitFail) */

    cx_object o = cx_createChild(NULL, "o", test_Bar_o);
    test_assert(o == NULL);
    test_assert(!strcmp(cx_lasterr(), "::test::Bar::init failed"));

/* $end */
}

/* ::test::ObjectMgmt::tc_createChildInt() */
cx_void _test_ObjectMgmt_tc_createChildInt(test_ObjectMgmt this) {
/* $begin(::test::ObjectMgmt::tc_createChildInt) */

    cx_object o = cx_createChild(NULL, "o", cx_int32_o);
    test_assert(o != NULL);
    test_assert(!strcmp(cx_nameof(o), "o"));
    test_assert(cx_parentof(o) == root_o);    
    test_assert(cx_typeof(o) == (cx_type)cx_int32_o);
    test_assert(cx_checkState(o, CX_VALID));
    test_assert(cx_checkState(o, CX_DECLARED));
    test_assert(cx_checkState(o, CX_DEFINED));
    test_assert(cx_checkAttr(o, CX_ATTR_SCOPED));
    test_assert(cx_checkAttr(o, CX_ATTR_WRITABLE));
    test_assert(cx_checkAttr(o, CX_ATTR_OBSERVABLE));
    test_assert(cx_checkAttr(o, CX_ATTR_PERSISTENT));

    cx_object p = cx_resolve(NULL, "o");
    test_assert(o == p);
    cx_release(p);

    cx_delete(o);

    cx_object q = cx_resolve(NULL, "o");
    test_assert(q == NULL);

/* $end */
}

/* ::test::ObjectMgmt::tc_createChildIntAttr0() */
cx_void _test_ObjectMgmt_tc_createChildIntAttr0(test_ObjectMgmt this) {
/* $begin(::test::ObjectMgmt::tc_createChildIntAttr0) */

    cx_setAttr(0);
    cx_object o = cx_createChild(NULL, "o", cx_int32_o);
    test_assert(o != NULL);
    test_assert(!strcmp(cx_nameof(o), "o"));
    test_assert(cx_parentof(o) == root_o);    
    test_assert(cx_typeof(o) == (cx_type)cx_int32_o);
    test_assert(cx_checkState(o, CX_VALID));
    test_assert(cx_checkState(o, CX_DECLARED));
    test_assert(cx_checkState(o, CX_DEFINED));
    test_assert(cx_checkAttr(o, CX_ATTR_SCOPED));
    test_assert(!cx_checkAttr(o, CX_ATTR_WRITABLE));
    test_assert(!cx_checkAttr(o, CX_ATTR_OBSERVABLE));
    test_assert(!cx_checkAttr(o, CX_ATTR_PERSISTENT));

    cx_object p = cx_resolve(NULL, "o");
    test_assert(o == p);
    cx_release(p);

    cx_delete(o);

    cx_object q = cx_resolve(NULL, "o");
    test_assert(q == NULL);

/* $end */
}

/* ::test::ObjectMgmt::tc_createChildInvalidType() */
cx_void _test_ObjectMgmt_tc_createChildInvalidType(test_ObjectMgmt this) {
/* $begin(::test::ObjectMgmt::tc_createChildInvalidType) */

    cx_type t = cx_type(cx_intCreateChild(NULL, "invalid", CX_WIDTH_8, 0, 0));
    test_assert(t != NULL);
    test_assert(cx_typeof(t) == cx_type(cx_int_o));
    test_assert(cx_checkState(t, CX_VALID));
    test_assert(cx_checkState(t, CX_DECLARED));
    test_assert(cx_checkState(t, CX_DEFINED));
    test_assert(cx_checkAttr(t, CX_ATTR_SCOPED));
    test_assert(cx_checkAttr(t, CX_ATTR_WRITABLE));
    test_assert(cx_checkAttr(t, CX_ATTR_OBSERVABLE));
    test_assert(cx_checkAttr(t, CX_ATTR_PERSISTENT));

    cx_invalidate(t);
    test_assert(!cx_checkState(t, CX_VALID));

    cx_object o = cx_create(t);
    test_assert(o == NULL);
    test_assert(!strcmp(cx_lasterr(), "type is not valid/defined"));

/* $end */
}

/* ::test::ObjectMgmt::tc_createChildNested() */
cx_void _test_ObjectMgmt_tc_createChildNested(test_ObjectMgmt this) {
/* $begin(::test::ObjectMgmt::tc_createChildNested) */

    test_Foo o = cx_createChild(NULL, "o", test_Foo_o);
    test_assert(o != NULL);
    test_assert(!strcmp(cx_nameof(o), "o"));
    test_assert(cx_parentof(o) == root_o);    
    test_assert(cx_typeof(o) == (cx_type)test_Foo_o);
    test_assert(cx_checkState(o, CX_VALID));
    test_assert(cx_checkState(o, CX_DECLARED));
    test_assert(cx_checkState(o, CX_DEFINED));
    test_assert(cx_checkAttr(o, CX_ATTR_SCOPED));
    test_assert(cx_checkAttr(o, CX_ATTR_WRITABLE));
    test_assert(cx_checkAttr(o, CX_ATTR_OBSERVABLE));
    test_assert(cx_checkAttr(o, CX_ATTR_PERSISTENT));

    test_Foo p = cx_createChild(o, "p", test_Foo_o);
    test_assert(p != NULL);
    test_assert(!strcmp(cx_nameof(p), "p"));
    test_assert(cx_parentof(p) == o);    
    test_assert(cx_typeof(p) == (cx_type)test_Foo_o);
    test_assert(cx_checkState(p, CX_VALID));
    test_assert(cx_checkState(p, CX_DECLARED));
    test_assert(cx_checkState(p, CX_DEFINED));
    test_assert(cx_checkAttr(p, CX_ATTR_SCOPED));
    test_assert(cx_checkAttr(p, CX_ATTR_WRITABLE));
    test_assert(cx_checkAttr(p, CX_ATTR_OBSERVABLE));
    test_assert(cx_checkAttr(p, CX_ATTR_PERSISTENT));

    test_Foo q = cx_createChild(p, "q", test_Foo_o);
    test_assert(p != NULL);
    test_assert(!strcmp(cx_nameof(q), "q"));
    test_assert(cx_parentof(q) == p);    
    test_assert(cx_typeof(q) == (cx_type)test_Foo_o);
    test_assert(cx_checkState(q, CX_VALID));
    test_assert(cx_checkState(q, CX_DECLARED));
    test_assert(cx_checkState(q, CX_DEFINED));
    test_assert(cx_checkAttr(q, CX_ATTR_SCOPED));
    test_assert(cx_checkAttr(q, CX_ATTR_WRITABLE));
    test_assert(cx_checkAttr(q, CX_ATTR_OBSERVABLE));
    test_assert(cx_checkAttr(q, CX_ATTR_PERSISTENT));

    cx_object _p = cx_resolve(NULL, "o::p");
    test_assert(_p == p);
    cx_release(_p);

    cx_object _q = cx_resolve(NULL, "o::p::q");
    test_assert(_q == q);
    cx_release(_q);

    cx_delete(o);

    test_assert(*test_initCalled_o == 3);
    test_assert(*test_constructCalled_o == 3);
    test_assert(*test_destructCalled_o == 3);

/* $end */
}

/* ::test::ObjectMgmt::tc_createChildNullType() */
cx_void _test_ObjectMgmt_tc_createChildNullType(test_ObjectMgmt this) {
/* $begin(::test::ObjectMgmt::tc_createChildNullType) */

    cx_object o = cx_createChild(NULL, "o", NULL);
    test_assert(o == NULL);
    test_assert(!strcmp(cx_lasterr(), "parameter 'type' is null"));

/* $end */
}

/* ::test::ObjectMgmt::tc_createChildParentStateErr() */
cx_void _test_ObjectMgmt_tc_createChildParentStateErr(test_ObjectMgmt this) {
/* $begin(::test::ObjectMgmt::tc_createChildParentStateErr) */

    cx_object o = cx_declareChild(NULL, "o", cx_int32_o);
    test_assert(o != NULL);
    test_assert(cx_checkState(o, CX_DECLARED));
    test_assert(!cx_checkState(o, CX_DEFINED));

    cx_object p = cx_createChild(o, "p", test_DefinedParent_o);
    test_assert(!strcmp(cx_lasterr(), "'::o' is VALID|DECLARED, must be DEFINED"));
    test_assert(p == NULL);

    cx_object q = test_DefinedParentCreateChild(o, "q", 0);
    test_assert(!strcmp(cx_lasterr(), "'::o' is VALID|DECLARED, must be DEFINED"));
    test_assert(q == NULL);

    cx_delete(o);

/* $end */
}

/* ::test::ObjectMgmt::tc_createChildParentTypeErr() */
cx_void _test_ObjectMgmt_tc_createChildParentTypeErr(test_ObjectMgmt this) {
/* $begin(::test::ObjectMgmt::tc_createChildParentTypeErr) */

    cx_object o = cx_declareChild(NULL, "o", cx_int32_o);
    test_assert(o != NULL);
    test_assert(cx_checkState(o, CX_DECLARED));
    test_assert(!cx_checkState(o, CX_DEFINED));

    cx_object p = cx_createChild(o, "p", test_VoidParent_o);
    test_assert(!strcmp(cx_lasterr(), "type of '::o' is not '::corto::lang::void'"));
    test_assert(p == NULL);

    cx_object q = test_VoidParentCreateChild(o, "q", 0);
    test_assert(!strcmp(cx_lasterr(), "type of '::o' is not '::corto::lang::void'"));
    test_assert(q == NULL);

    cx_delete(o);

/* $end */
}

/* ::test::ObjectMgmt::tc_createChildVoid() */
cx_void _test_ObjectMgmt_tc_createChildVoid(test_ObjectMgmt this) {
/* $begin(::test::ObjectMgmt::tc_createChildVoid) */

    cx_object o = cx_declareChild(NULL, "o", cx_void_o);
    test_assert(o != NULL);
    test_assert(!strcmp(cx_nameof(o), "o"));
    test_assert(cx_parentof(o) == root_o);    
    test_assert(cx_typeof(o) == cx_void_o);
    test_assert(cx_checkState(o, CX_VALID));
    test_assert(cx_checkState(o, CX_DECLARED));
    test_assert(cx_checkState(o, CX_DEFINED));
    test_assert(cx_checkAttr(o, CX_ATTR_SCOPED));
    test_assert(!cx_checkAttr(o, CX_ATTR_WRITABLE));
    test_assert(cx_checkAttr(o, CX_ATTR_OBSERVABLE));
    test_assert(cx_checkAttr(o, CX_ATTR_PERSISTENT));

    cx_object p = cx_resolve(NULL, "o");
    test_assert(o == p);
    cx_release(p);

    cx_delete(o);

    cx_object q = cx_resolve(NULL, "o");
    test_assert(q == NULL);

/* $end */
}

/* ::test::ObjectMgmt::tc_createChildVoidAttr0() */
cx_void _test_ObjectMgmt_tc_createChildVoidAttr0(test_ObjectMgmt this) {
/* $begin(::test::ObjectMgmt::tc_createChildVoidAttr0) */

    cx_setAttr(0);
    cx_object o = cx_createChild(NULL, "o", cx_void_o);
    test_assert(o != NULL);
    test_assert(!strcmp(cx_nameof(o), "o"));
    test_assert(cx_parentof(o) == root_o);    
    test_assert(cx_typeof(o) == cx_void_o);
    test_assert(cx_checkState(o, CX_VALID));
    test_assert(cx_checkState(o, CX_DECLARED));
    test_assert(cx_checkState(o, CX_DEFINED));
    test_assert(cx_checkAttr(o, CX_ATTR_SCOPED));
    test_assert(!cx_checkAttr(o, CX_ATTR_WRITABLE));
    test_assert(!cx_checkAttr(o, CX_ATTR_OBSERVABLE));
    test_assert(!cx_checkAttr(o, CX_ATTR_PERSISTENT));

    cx_object p = cx_resolve(NULL, "o");
    test_assert(o == p);
    cx_release(p);

    cx_delete(o);

    cx_object q = cx_resolve(NULL, "o");
    test_assert(q == NULL);

/* $end */
}

/* ::test::ObjectMgmt::tc_createFoo() */
cx_void _test_ObjectMgmt_tc_createFoo(test_ObjectMgmt this) {
/* $begin(::test::ObjectMgmt::tc_createFoo) */

    test_Foo o = cx_create(test_Foo_o);
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == (cx_type)test_Foo_o);
    test_assert(cx_checkState(o, CX_VALID));
    test_assert(cx_checkState(o, CX_DECLARED));
    test_assert(cx_checkState(o, CX_DEFINED));
    test_assert(!cx_checkAttr(o, CX_ATTR_SCOPED));
    test_assert(cx_checkAttr(o, CX_ATTR_WRITABLE));
    test_assert(cx_checkAttr(o, CX_ATTR_OBSERVABLE));
    test_assert(!cx_checkAttr(o, CX_ATTR_PERSISTENT));

    /* Test if constructor is correctly executed */
    test_assert(o->x == 11);
    test_assert(o->y == 22);

    cx_delete(o);

    test_assert(*test_initCalled_o == 1);
    test_assert(*test_constructCalled_o == 1);
    test_assert(*test_destructCalled_o == 1);

/* $end */
}

/* ::test::ObjectMgmt::tc_createFooAttr0() */
cx_void _test_ObjectMgmt_tc_createFooAttr0(test_ObjectMgmt this) {
/* $begin(::test::ObjectMgmt::tc_createFooAttr0) */

    cx_setAttr(0);
    test_Foo o = cx_create(test_Foo_o);
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == (cx_type)test_Foo_o);
    test_assert(cx_checkState(o, CX_VALID));
    test_assert(cx_checkState(o, CX_DECLARED));
    test_assert(cx_checkState(o, CX_DEFINED));
    test_assert(!cx_checkAttr(o, CX_ATTR_SCOPED));
    test_assert(!cx_checkAttr(o, CX_ATTR_WRITABLE));
    test_assert(!cx_checkAttr(o, CX_ATTR_OBSERVABLE));
    test_assert(!cx_checkAttr(o, CX_ATTR_PERSISTENT));

    /* Test if constructor is correctly executed */
    test_assert(o->x == 11);
    test_assert(o->y == 22);

    cx_delete(o);

    test_assert(*test_initCalled_o == 1);
    test_assert(*test_constructCalled_o == 1);
    test_assert(*test_destructCalled_o == 1);

/* $end */
}

/* ::test::ObjectMgmt::tc_createInitFail() */
cx_void _test_ObjectMgmt_tc_createInitFail(test_ObjectMgmt this) {
/* $begin(::test::ObjectMgmt::tc_createInitFail) */

    cx_object o = cx_create(test_Bar_o);
    test_assert(o == NULL);
    test_assert(!strcmp(cx_lasterr(), "::test::Bar::init failed"));

/* $end */
}

/* ::test::ObjectMgmt::tc_createInt() */
cx_void _test_ObjectMgmt_tc_createInt(test_ObjectMgmt this) {
/* $begin(::test::ObjectMgmt::tc_createInt) */

    cx_object o = cx_create(cx_int32_o);
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == (cx_type)cx_int32_o);
    test_assert(cx_checkState(o, CX_VALID));
    test_assert(cx_checkState(o, CX_DECLARED));
    test_assert(cx_checkState(o, CX_DEFINED));
    test_assert(!cx_checkAttr(o, CX_ATTR_SCOPED));
    test_assert(cx_checkAttr(o, CX_ATTR_WRITABLE));
    test_assert(cx_checkAttr(o, CX_ATTR_OBSERVABLE));
    test_assert(!cx_checkAttr(o, CX_ATTR_PERSISTENT));
    cx_delete(o);

/* $end */
}

/* ::test::ObjectMgmt::tc_createIntAttr0() */
cx_void _test_ObjectMgmt_tc_createIntAttr0(test_ObjectMgmt this) {
/* $begin(::test::ObjectMgmt::tc_createIntAttr0) */

    cx_setAttr(0);
    cx_object o = cx_create(cx_int32_o);
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == (cx_type)cx_int32_o);
    test_assert(cx_checkState(o, CX_VALID));
    test_assert(cx_checkState(o, CX_DECLARED));
    test_assert(cx_checkState(o, CX_DEFINED));
    test_assert(!cx_checkAttr(o, CX_ATTR_SCOPED));
    test_assert(!cx_checkAttr(o, CX_ATTR_WRITABLE));
    test_assert(!cx_checkAttr(o, CX_ATTR_OBSERVABLE));
    test_assert(!cx_checkAttr(o, CX_ATTR_PERSISTENT));
    cx_delete(o);

/* $end */
}

/* ::test::ObjectMgmt::tc_createInvalidType() */
cx_void _test_ObjectMgmt_tc_createInvalidType(test_ObjectMgmt this) {
/* $begin(::test::ObjectMgmt::tc_createInvalidType) */

    cx_type t = cx_type(cx_intCreateChild(NULL, "invalid", CX_WIDTH_8, 0, 0));
    test_assert(t != NULL);
    test_assert(cx_typeof(t) == cx_type(cx_int_o));
    test_assert(cx_checkState(t, CX_VALID));
    test_assert(cx_checkState(t, CX_DECLARED));
    test_assert(cx_checkState(t, CX_DEFINED));
    test_assert(cx_checkAttr(t, CX_ATTR_SCOPED));
    test_assert(cx_checkAttr(t, CX_ATTR_WRITABLE));
    test_assert(cx_checkAttr(t, CX_ATTR_OBSERVABLE));
    test_assert(cx_checkAttr(t, CX_ATTR_PERSISTENT));

    cx_invalidate(t);
    test_assert(!cx_checkState(t, CX_VALID));

    cx_object o = cx_create(t);
    test_assert(!strcmp(cx_lasterr(), "type is not valid/defined"));
    test_assert(o == NULL);

/* $end */
}

/* ::test::ObjectMgmt::tc_createNullType() */
cx_void _test_ObjectMgmt_tc_createNullType(test_ObjectMgmt this) {
/* $begin(::test::ObjectMgmt::tc_createNullType) */

    cx_object o = cx_create(NULL);
    test_assert(o == NULL);
    test_assert(!strcmp(cx_lasterr(), "parameter 'type' is null"));

/* $end */
}

/* ::test::ObjectMgmt::tc_createVoid() */
cx_void _test_ObjectMgmt_tc_createVoid(test_ObjectMgmt this) {
/* $begin(::test::ObjectMgmt::tc_createVoid) */

    cx_object o = cx_create(cx_void_o);
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == cx_void_o);
    test_assert(cx_checkState(o, CX_VALID));
    test_assert(cx_checkState(o, CX_DECLARED));
    test_assert(cx_checkState(o, CX_DEFINED));
    test_assert(!cx_checkAttr(o, CX_ATTR_SCOPED));
    test_assert(!cx_checkAttr(o, CX_ATTR_WRITABLE));
    test_assert(cx_checkAttr(o, CX_ATTR_OBSERVABLE));
    test_assert(!cx_checkAttr(o, CX_ATTR_PERSISTENT));
    cx_delete(o);

/* $end */
}

/* ::test::ObjectMgmt::tc_createVoidAttr0() */
cx_void _test_ObjectMgmt_tc_createVoidAttr0(test_ObjectMgmt this) {
/* $begin(::test::ObjectMgmt::tc_createVoidAttr0) */

    cx_setAttr(0);
    cx_object o = cx_create(cx_void_o);
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == (cx_type)cx_void_o);
    test_assert(cx_checkState(o, CX_VALID));
    test_assert(cx_checkState(o, CX_DECLARED));
    test_assert(cx_checkState(o, CX_DEFINED));
    test_assert(!cx_checkAttr(o, CX_ATTR_SCOPED));
    test_assert(!cx_checkAttr(o, CX_ATTR_WRITABLE));
    test_assert(!cx_checkAttr(o, CX_ATTR_OBSERVABLE));
    test_assert(!cx_checkAttr(o, CX_ATTR_PERSISTENT));
    cx_delete(o);

/* $end */
}

/* ::test::ObjectMgmt::tc_declareChildFoo() */
cx_void _test_ObjectMgmt_tc_declareChildFoo(test_ObjectMgmt this) {
/* $begin(::test::ObjectMgmt::tc_declareChildFoo) */

    test_Foo o = cx_declareChild(NULL, "o", test_Foo_o);
    test_assert(o != NULL);
    test_assert(!strcmp(cx_nameof(o), "o"));
    test_assert(cx_parentof(o) == root_o);    
    test_assert(cx_typeof(o) == (cx_type)test_Foo_o);
    test_assert(cx_checkState(o, CX_VALID));
    test_assert(cx_checkState(o, CX_DECLARED));
    test_assert(!cx_checkState(o, CX_DEFINED));
    test_assert(cx_checkAttr(o, CX_ATTR_SCOPED));
    test_assert(cx_checkAttr(o, CX_ATTR_WRITABLE));
    test_assert(cx_checkAttr(o, CX_ATTR_OBSERVABLE));
    test_assert(cx_checkAttr(o, CX_ATTR_PERSISTENT));

    /* Test if initializer is correctly executed */
    test_assert(o->x == 1);
    test_assert(o->y == 2);

    cx_object p = cx_resolve(NULL, "o");
    test_assert(o == p);
    cx_release(p);

    cx_delete(o);

    cx_object q = cx_resolve(NULL, "o");
    test_assert(q == NULL);

    test_assert(*test_initCalled_o == 1);
    test_assert(*test_constructCalled_o == 0);
    test_assert(*test_destructCalled_o == 0);

/* $end */
}

/* ::test::ObjectMgmt::tc_declareChildFooAttr0() */
cx_void _test_ObjectMgmt_tc_declareChildFooAttr0(test_ObjectMgmt this) {
/* $begin(::test::ObjectMgmt::tc_declareChildFooAttr0) */

    cx_setAttr(0);
    test_Foo o = cx_declareChild(NULL, "o", test_Foo_o);
    test_assert(o != NULL);
    test_assert(!strcmp(cx_nameof(o), "o"));
    test_assert(cx_parentof(o) == root_o);    
    test_assert(cx_typeof(o) == (cx_type)test_Foo_o);
    test_assert(cx_checkState(o, CX_VALID));
    test_assert(cx_checkState(o, CX_DECLARED));
    test_assert(!cx_checkState(o, CX_DEFINED));
    test_assert(cx_checkAttr(o, CX_ATTR_SCOPED));
    test_assert(!cx_checkAttr(o, CX_ATTR_WRITABLE));
    test_assert(!cx_checkAttr(o, CX_ATTR_OBSERVABLE));
    test_assert(!cx_checkAttr(o, CX_ATTR_PERSISTENT));

    /* Test if initializer is correctly executed */
    test_assert(o->x == 1);
    test_assert(o->y == 2);

    cx_object p = cx_resolve(NULL, "o");
    test_assert(o == p);
    cx_release(p);

    cx_delete(o);

    cx_object q = cx_resolve(NULL, "o");
    test_assert(q == NULL);

    test_assert(*test_initCalled_o == 1);
    test_assert(*test_constructCalled_o == 0);
    test_assert(*test_destructCalled_o == 0);

/* $end */
}

/* ::test::ObjectMgmt::tc_declareChildInitFail() */
cx_void _test_ObjectMgmt_tc_declareChildInitFail(test_ObjectMgmt this) {
/* $begin(::test::ObjectMgmt::tc_declareChildInitFail) */

    cx_object o = cx_declareChild(NULL, "o", test_Bar_o);
    test_assert(o == NULL);
    test_assert(!strcmp(cx_lasterr(), "::test::Bar::init failed"));

/* $end */
}

/* ::test::ObjectMgmt::tc_declareChildInt() */
cx_void _test_ObjectMgmt_tc_declareChildInt(test_ObjectMgmt this) {
/* $begin(::test::ObjectMgmt::tc_declareChildInt) */

    cx_object o = cx_declareChild(NULL, "o", cx_int32_o);
    test_assert(o != NULL);
    test_assert(!strcmp(cx_nameof(o), "o"));
    test_assert(cx_parentof(o) == root_o);    
    test_assert(cx_typeof(o) == (cx_type)cx_int32_o);
    test_assert(cx_checkState(o, CX_VALID));
    test_assert(cx_checkState(o, CX_DECLARED));
    test_assert(!cx_checkState(o, CX_DEFINED));
    test_assert(cx_checkAttr(o, CX_ATTR_SCOPED));
    test_assert(cx_checkAttr(o, CX_ATTR_WRITABLE));
    test_assert(cx_checkAttr(o, CX_ATTR_OBSERVABLE));
    test_assert(cx_checkAttr(o, CX_ATTR_PERSISTENT));

    cx_object p = cx_resolve(NULL, "o");
    test_assert(o == p);
    cx_release(p);

    p = cx_declareChild(NULL, "o", cx_int32_o);
    test_assert(o == p);
    cx_delete(p);

    cx_delete(o);

    cx_object q = cx_resolve(NULL, "o");
    test_assert(q == NULL);

/* $end */
}

/* ::test::ObjectMgmt::tc_declareChildIntAttr0() */
cx_void _test_ObjectMgmt_tc_declareChildIntAttr0(test_ObjectMgmt this) {
/* $begin(::test::ObjectMgmt::tc_declareChildIntAttr0) */

    cx_setAttr(0);
    cx_object o = cx_declareChild(NULL, "o", cx_int32_o);
    test_assert(o != NULL);
    test_assert(!strcmp(cx_nameof(o), "o"));
    test_assert(cx_parentof(o) == root_o);    
    test_assert(cx_typeof(o) == (cx_type)cx_int32_o);
    test_assert(cx_checkState(o, CX_VALID));
    test_assert(cx_checkState(o, CX_DECLARED));
    test_assert(!cx_checkState(o, CX_DEFINED));
    test_assert(cx_checkAttr(o, CX_ATTR_SCOPED));
    test_assert(!cx_checkAttr(o, CX_ATTR_WRITABLE));
    test_assert(!cx_checkAttr(o, CX_ATTR_OBSERVABLE));
    test_assert(!cx_checkAttr(o, CX_ATTR_PERSISTENT));

    cx_object p = cx_resolve(NULL, "o");
    test_assert(o == p);
    cx_release(p);

    cx_delete(o);

    cx_object q = cx_resolve(NULL, "o");
    test_assert(q == NULL);

/* $end */
}

/* ::test::ObjectMgmt::tc_declareChildInvalidType() */
cx_void _test_ObjectMgmt_tc_declareChildInvalidType(test_ObjectMgmt this) {
/* $begin(::test::ObjectMgmt::tc_declareChildInvalidType) */

    cx_type t = cx_type(cx_intCreateChild(NULL, "invalid", CX_WIDTH_8, 0, 0));
    test_assert(t != NULL);
    test_assert(cx_typeof(t) == cx_type(cx_int_o));
    test_assert(cx_checkState(t, CX_VALID));
    test_assert(cx_checkState(t, CX_DECLARED));
    test_assert(cx_checkState(t, CX_DEFINED));
    test_assert(cx_checkAttr(t, CX_ATTR_SCOPED));
    test_assert(cx_checkAttr(t, CX_ATTR_WRITABLE));
    test_assert(cx_checkAttr(t, CX_ATTR_OBSERVABLE));
    test_assert(cx_checkAttr(t, CX_ATTR_PERSISTENT));

    cx_invalidate(t);
    test_assert(!cx_checkState(t, CX_VALID));

    cx_object o = cx_declareChild(NULL, "foo", t);
    test_assert(o == NULL);

/* $end */
}

/* ::test::ObjectMgmt::tc_declareChildNullType() */
cx_void _test_ObjectMgmt_tc_declareChildNullType(test_ObjectMgmt this) {
/* $begin(::test::ObjectMgmt::tc_declareChildNullType) */

    cx_object o = cx_declareChild(NULL, "o", NULL);
    test_assert(o == NULL);
    test_assert(!strcmp(cx_lasterr(), "parameter 'type' is null"));

/* $end */
}

/* ::test::ObjectMgmt::tc_declareChildParentStateErr() */
cx_void _test_ObjectMgmt_tc_declareChildParentStateErr(test_ObjectMgmt this) {
/* $begin(::test::ObjectMgmt::tc_declareChildParentStateErr) */

    cx_object o = cx_declareChild(NULL, "o", cx_int32_o);
    test_assert(o != NULL);
    test_assert(cx_checkState(o, CX_DECLARED));
    test_assert(!cx_checkState(o, CX_DEFINED));

    cx_object p = cx_declareChild(o, "p", test_DefinedParent_o);
    test_assert(p == NULL);

    cx_object q = test_DefinedParentDeclareChild(o, "q");
    test_assert(q == NULL);

    cx_delete(o);

/* $end */
}

/* ::test::ObjectMgmt::tc_declareChildParentTypeErr() */
cx_void _test_ObjectMgmt_tc_declareChildParentTypeErr(test_ObjectMgmt this) {
/* $begin(::test::ObjectMgmt::tc_declareChildParentTypeErr) */

    cx_object o = cx_declareChild(NULL, "o", cx_int32_o);
    test_assert(o != NULL);
    test_assert(cx_checkState(o, CX_DECLARED));
    test_assert(!cx_checkState(o, CX_DEFINED));

    cx_object p = cx_declareChild(o, "p", test_VoidParent_o);
    test_assert(!strcmp(cx_lasterr(), "type of '::o' is not '::corto::lang::void'"));
    test_assert(p == NULL);

    cx_object q = test_VoidParentDeclareChild(o, "q");
    test_assert(!strcmp(cx_lasterr(), "type of '::o' is not '::corto::lang::void'"));
    test_assert(q == NULL);

    cx_delete(o);

/* $end */
}

/* ::test::ObjectMgmt::tc_declareChildVoid() */
cx_void _test_ObjectMgmt_tc_declareChildVoid(test_ObjectMgmt this) {
/* $begin(::test::ObjectMgmt::tc_declareChildVoid) */

    cx_object o = cx_declareChild(NULL, "o", cx_void_o);
    test_assert(o != NULL);
    test_assert(!strcmp(cx_nameof(o), "o"));
    test_assert(cx_parentof(o) == root_o);    
    test_assert(cx_typeof(o) == cx_void_o);
    test_assert(cx_checkState(o, CX_VALID));
    test_assert(cx_checkState(o, CX_DECLARED));
    test_assert(cx_checkState(o, CX_DEFINED));
    test_assert(cx_checkAttr(o, CX_ATTR_SCOPED));
    test_assert(!cx_checkAttr(o, CX_ATTR_WRITABLE));
    test_assert(cx_checkAttr(o, CX_ATTR_OBSERVABLE));
    test_assert(cx_checkAttr(o, CX_ATTR_PERSISTENT));

    cx_object p = cx_resolve(NULL, "o");
    test_assert(o == p);
    cx_release(p);

    cx_delete(o);

    cx_object q = cx_resolve(NULL, "o");
    test_assert(q == NULL);

/* $end */
}

/* ::test::ObjectMgmt::tc_declareChildVoidAttr0() */
cx_void _test_ObjectMgmt_tc_declareChildVoidAttr0(test_ObjectMgmt this) {
/* $begin(::test::ObjectMgmt::tc_declareChildVoidAttr0) */

    cx_setAttr(0);
    cx_object o = cx_declareChild(NULL, "o", cx_void_o);
    test_assert(o != NULL);
    test_assert(!strcmp(cx_nameof(o), "o"));
    test_assert(cx_parentof(o) == root_o);    
    test_assert(cx_typeof(o) == cx_void_o);
    test_assert(cx_checkState(o, CX_VALID));
    test_assert(cx_checkState(o, CX_DECLARED));
    test_assert(cx_checkState(o, CX_DEFINED));
    test_assert(cx_checkAttr(o, CX_ATTR_SCOPED));
    test_assert(!cx_checkAttr(o, CX_ATTR_WRITABLE));
    test_assert(!cx_checkAttr(o, CX_ATTR_OBSERVABLE));
    test_assert(!cx_checkAttr(o, CX_ATTR_PERSISTENT));

    cx_object p = cx_resolve(NULL, "o");
    test_assert(o == p);
    cx_release(p);

    cx_delete(o);

    cx_object q = cx_resolve(NULL, "o");
    test_assert(q == NULL);

/* $end */
}

/* ::test::ObjectMgmt::tc_declareExistingWithParentState() */
cx_void _test_ObjectMgmt_tc_declareExistingWithParentState(test_ObjectMgmt this) {
/* $begin(::test::ObjectMgmt::tc_declareExistingWithParentState) */

    cx_struct s = cx_structDeclareChild(NULL, "s");
    test_assert(s != NULL);

    cx_member m = cx_memberCreateChild(s, "m", cx_type(cx_uint32_o), CX_GLOBAL, 0, FALSE);
    test_assert(m != NULL);

    cx_int16 ret = cx_define(s);
    test_assert(ret == 0);

    /* Validate I can redeclare member after struct has been defined */
    cx_member n = cx_memberDeclareChild(s, "m");
    test_assert(n != NULL);
    test_assert(cx_checkState(n, CX_DEFINED));

    ret = cx_define(n);
    test_assert(ret == 0);

    cx_delete(n);
    cx_delete(m);
    cx_delete(s);

/* $end */
}

/* ::test::ObjectMgmt::tc_declareFoo() */
cx_void _test_ObjectMgmt_tc_declareFoo(test_ObjectMgmt this) {
/* $begin(::test::ObjectMgmt::tc_declareFoo) */

    test_Foo o = cx_declare(test_Foo_o);
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == (cx_type)test_Foo_o);
    test_assert(cx_checkState(o, CX_VALID));
    test_assert(cx_checkState(o, CX_DECLARED));
    test_assert(!cx_checkState(o, CX_DEFINED));
    test_assert(!cx_checkAttr(o, CX_ATTR_SCOPED));
    test_assert(cx_checkAttr(o, CX_ATTR_WRITABLE));
    test_assert(cx_checkAttr(o, CX_ATTR_OBSERVABLE));
    test_assert(!cx_checkAttr(o, CX_ATTR_PERSISTENT));

    /* Test if initializer is correctly executed */
    test_assert(o->x == 1);
    test_assert(o->y == 2);

    cx_delete(o);

    test_assert(*test_initCalled_o == 1);
    test_assert(*test_constructCalled_o == 0);
    test_assert(*test_destructCalled_o == 0);

/* $end */
}

/* ::test::ObjectMgmt::tc_declareFooAttr0() */
cx_void _test_ObjectMgmt_tc_declareFooAttr0(test_ObjectMgmt this) {
/* $begin(::test::ObjectMgmt::tc_declareFooAttr0) */

    cx_setAttr(0);
    test_Foo o = cx_declare(test_Foo_o);
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == (cx_type)test_Foo_o);
    test_assert(cx_checkState(o, CX_VALID));
    test_assert(cx_checkState(o, CX_DECLARED));
    test_assert(!cx_checkState(o, CX_DEFINED));
    test_assert(!cx_checkAttr(o, CX_ATTR_SCOPED));
    test_assert(!cx_checkAttr(o, CX_ATTR_WRITABLE));
    test_assert(!cx_checkAttr(o, CX_ATTR_OBSERVABLE));
    test_assert(!cx_checkAttr(o, CX_ATTR_PERSISTENT));

    /* Test if initializer is correctly executed */
    test_assert(o->x == 1);
    test_assert(o->y == 2);

    cx_delete(o);

    test_assert(*test_initCalled_o == 1);
    test_assert(*test_constructCalled_o == 0);
    test_assert(*test_destructCalled_o == 0);


/* $end */
}

/* ::test::ObjectMgmt::tc_declareInitFail() */
cx_void _test_ObjectMgmt_tc_declareInitFail(test_ObjectMgmt this) {
/* $begin(::test::ObjectMgmt::tc_declareInitFail) */

    cx_object o = cx_declare(test_Bar_o);
    test_assert(o == NULL);
    test_assert(!strcmp(cx_lasterr(), "::test::Bar::init failed"));

/* $end */
}

/* ::test::ObjectMgmt::tc_declareInt() */
cx_void _test_ObjectMgmt_tc_declareInt(test_ObjectMgmt this) {
/* $begin(::test::ObjectMgmt::tc_declareInt) */

    cx_object o = cx_declare(cx_int32_o);
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == (cx_type)cx_int32_o);
    test_assert(cx_checkState(o, CX_VALID));
    test_assert(cx_checkState(o, CX_DECLARED));
    test_assert(!cx_checkState(o, CX_DEFINED));
    test_assert(!cx_checkAttr(o, CX_ATTR_SCOPED));
    test_assert(cx_checkAttr(o, CX_ATTR_WRITABLE));
    test_assert(cx_checkAttr(o, CX_ATTR_OBSERVABLE));
    test_assert(!cx_checkAttr(o, CX_ATTR_PERSISTENT));
    cx_delete(o);
    
/* $end */
}

/* ::test::ObjectMgmt::tc_declareIntAttr0() */
cx_void _test_ObjectMgmt_tc_declareIntAttr0(test_ObjectMgmt this) {
/* $begin(::test::ObjectMgmt::tc_declareIntAttr0) */

    cx_setAttr(0);
    cx_object o = cx_declare(cx_int32_o);
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == (cx_type)cx_int32_o);
    test_assert(cx_checkState(o, CX_VALID));
    test_assert(cx_checkState(o, CX_DECLARED));
    test_assert(!cx_checkState(o, CX_DEFINED));
    test_assert(!cx_checkAttr(o, CX_ATTR_SCOPED));
    test_assert(!cx_checkAttr(o, CX_ATTR_WRITABLE));
    test_assert(!cx_checkAttr(o, CX_ATTR_OBSERVABLE));
    test_assert(!cx_checkAttr(o, CX_ATTR_PERSISTENT));
    cx_delete(o);

/* $end */
}

/* ::test::ObjectMgmt::tc_declareInvalidType() */
cx_void _test_ObjectMgmt_tc_declareInvalidType(test_ObjectMgmt this) {
/* $begin(::test::ObjectMgmt::tc_declareInvalidType) */

    cx_type t = cx_type(cx_intCreateChild(NULL, "invalid", CX_WIDTH_8, 0, 0));
    test_assert(t != NULL);
    test_assert(cx_typeof(t) == cx_type(cx_int_o));
    test_assert(cx_checkState(t, CX_VALID));
    test_assert(cx_checkState(t, CX_DECLARED));
    test_assert(cx_checkState(t, CX_DEFINED));
    test_assert(cx_checkAttr(t, CX_ATTR_SCOPED));
    test_assert(cx_checkAttr(t, CX_ATTR_WRITABLE));
    test_assert(cx_checkAttr(t, CX_ATTR_OBSERVABLE));
    test_assert(cx_checkAttr(t, CX_ATTR_PERSISTENT));

    cx_invalidate(t);
    test_assert(!cx_checkState(t, CX_VALID));

    cx_object o = cx_declare(t);
    test_assert(o == NULL);

/* $end */
}

/* ::test::ObjectMgmt::tc_declareNullType() */
cx_void _test_ObjectMgmt_tc_declareNullType(test_ObjectMgmt this) {
/* $begin(::test::ObjectMgmt::tc_declareNullType) */

    cx_object o = cx_declare(NULL);
    test_assert(o == NULL);
    test_assert(!strcmp(cx_lasterr(), "parameter 'type' is null"));

/* $end */
}

/* ::test::ObjectMgmt::tc_declareVoid() */
cx_void _test_ObjectMgmt_tc_declareVoid(test_ObjectMgmt this) {
/* $begin(::test::ObjectMgmt::tc_declareVoid) */

    cx_object o = cx_declare(cx_void_o);
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == cx_void_o);
    test_assert(cx_checkState(o, CX_VALID));
    test_assert(cx_checkState(o, CX_DECLARED));
    test_assert(cx_checkState(o, CX_DEFINED));
    test_assert(!cx_checkAttr(o, CX_ATTR_SCOPED));
    test_assert(!cx_checkAttr(o, CX_ATTR_WRITABLE));
    test_assert(cx_checkAttr(o, CX_ATTR_OBSERVABLE));
    test_assert(!cx_checkAttr(o, CX_ATTR_PERSISTENT));
    cx_delete(o);
    
/* $end */
}

/* ::test::ObjectMgmt::tc_declareVoidAttr0() */
cx_void _test_ObjectMgmt_tc_declareVoidAttr0(test_ObjectMgmt this) {
/* $begin(::test::ObjectMgmt::tc_declareVoidAttr0) */

    cx_setAttr(0);
    cx_object o = cx_declare(cx_void_o);
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == (cx_type)cx_void_o);
    test_assert(cx_checkState(o, CX_VALID));
    test_assert(cx_checkState(o, CX_DECLARED));
    test_assert(cx_checkState(o, CX_DEFINED));
    test_assert(!cx_checkAttr(o, CX_ATTR_SCOPED));
    test_assert(!cx_checkAttr(o, CX_ATTR_WRITABLE));
    test_assert(!cx_checkAttr(o, CX_ATTR_OBSERVABLE));
    test_assert(!cx_checkAttr(o, CX_ATTR_PERSISTENT));
    cx_delete(o);

/* $end */
}

/* ::test::ObjectMgmt::tc_defineFoo() */
cx_void _test_ObjectMgmt_tc_defineFoo(test_ObjectMgmt this) {
/* $begin(::test::ObjectMgmt::tc_defineFoo) */

    test_Foo o = cx_declare(test_Foo_o);
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == (cx_type)test_Foo_o);
    test_assert(o->x == 1);
    test_assert(o->y == 2);
    test_assert(!cx_define(o));
    test_assert(cx_checkState(o, CX_VALID));
    test_assert(cx_checkState(o, CX_DECLARED));
    test_assert(cx_checkState(o, CX_DEFINED));
    test_assert(!cx_checkAttr(o, CX_ATTR_SCOPED));
    test_assert(cx_checkAttr(o, CX_ATTR_WRITABLE));
    test_assert(cx_checkAttr(o, CX_ATTR_OBSERVABLE));
    test_assert(!cx_checkAttr(o, CX_ATTR_PERSISTENT));

    /* Test if initializer is correctly executed */
    test_assert(o->x == 11);
    test_assert(o->y == 22);

    /* Test if constructor is executed only once */
    test_assert(!cx_define(o));

    test_assert(o->x == 11);
    test_assert(o->y == 22);

    cx_delete(o);

    test_assert(*test_initCalled_o == 1);
    test_assert(*test_constructCalled_o == 1);
    test_assert(*test_destructCalled_o == 1);

/* $end */
}

/* ::test::ObjectMgmt::tc_defineFooAttr0() */
cx_void _test_ObjectMgmt_tc_defineFooAttr0(test_ObjectMgmt this) {
/* $begin(::test::ObjectMgmt::tc_defineFooAttr0) */

    cx_setAttr(0);
    test_Foo o = cx_declare(test_Foo_o);
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == (cx_type)test_Foo_o);
    test_assert(o->x == 1);
    test_assert(o->y == 2);
    test_assert(!cx_define(o));
    test_assert(cx_checkState(o, CX_VALID));
    test_assert(cx_checkState(o, CX_DECLARED));
    test_assert(cx_checkState(o, CX_DEFINED));
    test_assert(!cx_checkAttr(o, CX_ATTR_SCOPED));
    test_assert(!cx_checkAttr(o, CX_ATTR_WRITABLE));
    test_assert(!cx_checkAttr(o, CX_ATTR_OBSERVABLE));
    test_assert(!cx_checkAttr(o, CX_ATTR_PERSISTENT));

    /* Test if constructor is correctly executed */
    test_assert(o->x == 11);
    test_assert(o->y == 22);

    /* Test if constructor is executed only once */
    test_assert(!cx_define(o));

    test_assert(o->x == 11);
    test_assert(o->y == 22);

    cx_delete(o);

    test_assert(*test_initCalled_o == 1);
    test_assert(*test_constructCalled_o == 1);
    test_assert(*test_destructCalled_o == 1);

/* $end */
}

/* ::test::ObjectMgmt::tc_defineFooFail() */
cx_void _test_ObjectMgmt_tc_defineFooFail(test_ObjectMgmt this) {
/* $begin(::test::ObjectMgmt::tc_defineFooFail) */

    test_Foo o = cx_declare(test_Foo_o);
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == (cx_type)test_Foo_o);
    test_assert(o->x == 1);
    test_assert(o->y == 2);

    o->fail = TRUE;
    test_assert(cx_define(o));

    test_assert(!cx_checkState(o, CX_VALID));
    test_assert(cx_checkState(o, CX_DECLARED));
    test_assert(!cx_checkState(o, CX_DEFINED));
    test_assert(!cx_checkAttr(o, CX_ATTR_SCOPED));
    test_assert(cx_checkAttr(o, CX_ATTR_WRITABLE));
    test_assert(cx_checkAttr(o, CX_ATTR_OBSERVABLE));
    test_assert(!cx_checkAttr(o, CX_ATTR_PERSISTENT));

    /* Test if constructor is not executed */
    test_assert(o->x == 1);
    test_assert(o->y == 2);

    /* Test if constructor fails 2nd time */
    test_assert(cx_define(o));
    test_assert(!cx_checkState(o, CX_VALID));
    test_assert(cx_checkState(o, CX_DECLARED));
    test_assert(!cx_checkState(o, CX_DEFINED));

    /* Test if constructor is still not executed */
    test_assert(o->x == 1);
    test_assert(o->y == 2);

    /* Test if constructor succeeds after fixing error */
    o->fail = FALSE;
    test_assert(!cx_define(o));
    test_assert(cx_checkState(o, CX_VALID));
    test_assert(cx_checkState(o, CX_DECLARED));
    test_assert(cx_checkState(o, CX_DEFINED));

    /* Test if constructor is executed */
    test_assert(o->x == 11);
    test_assert(o->y == 22);

    cx_delete(o);

/* $end */
}

/* ::test::ObjectMgmt::tc_defineInt() */
cx_void _test_ObjectMgmt_tc_defineInt(test_ObjectMgmt this) {
/* $begin(::test::ObjectMgmt::tc_defineInt) */

    cx_object o = cx_declare(cx_int32_o);
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == (cx_type)cx_int32_o);
    test_assert(!cx_define(o));
    test_assert(cx_checkState(o, CX_VALID));
    test_assert(cx_checkState(o, CX_DECLARED));
    test_assert(cx_checkState(o, CX_DEFINED));
    test_assert(!cx_checkAttr(o, CX_ATTR_SCOPED));
    test_assert(cx_checkAttr(o, CX_ATTR_WRITABLE));
    test_assert(cx_checkAttr(o, CX_ATTR_OBSERVABLE));
    test_assert(!cx_checkAttr(o, CX_ATTR_PERSISTENT));
    cx_delete(o);

/* $end */
}

/* ::test::ObjectMgmt::tc_defineIntAttr0() */
cx_void _test_ObjectMgmt_tc_defineIntAttr0(test_ObjectMgmt this) {
/* $begin(::test::ObjectMgmt::tc_defineIntAttr0) */

    cx_setAttr(0);
    cx_object o = cx_declare(cx_int32_o);
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == (cx_type)cx_int32_o);
    test_assert(!cx_define(o));
    test_assert(cx_checkState(o, CX_VALID));
    test_assert(cx_checkState(o, CX_DECLARED));
    test_assert(cx_checkState(o, CX_DEFINED));
    test_assert(!cx_checkAttr(o, CX_ATTR_SCOPED));
    test_assert(!cx_checkAttr(o, CX_ATTR_WRITABLE));
    test_assert(!cx_checkAttr(o, CX_ATTR_OBSERVABLE));
    test_assert(!cx_checkAttr(o, CX_ATTR_PERSISTENT));
    cx_delete(o);

/* $end */
}

/* ::test::ObjectMgmt::tc_defineVoid() */
cx_void _test_ObjectMgmt_tc_defineVoid(test_ObjectMgmt this) {
/* $begin(::test::ObjectMgmt::tc_defineVoid) */

    cx_object o = cx_declare(cx_void_o);
    cx_define(o);

    test_assert(o != NULL);
    test_assert(cx_typeof(o) == cx_void_o);
    test_assert(cx_checkState(o, CX_VALID));
    test_assert(cx_checkState(o, CX_DECLARED));
    test_assert(cx_checkState(o, CX_DEFINED));
    test_assert(!cx_checkAttr(o, CX_ATTR_SCOPED));
    test_assert(!cx_checkAttr(o, CX_ATTR_WRITABLE));
    test_assert(cx_checkAttr(o, CX_ATTR_OBSERVABLE));
    test_assert(!cx_checkAttr(o, CX_ATTR_PERSISTENT));
    cx_delete(o);

/* $end */
}

/* ::test::ObjectMgmt::tc_defineVoidAttr0() */
cx_void _test_ObjectMgmt_tc_defineVoidAttr0(test_ObjectMgmt this) {
/* $begin(::test::ObjectMgmt::tc_defineVoidAttr0) */

    cx_setAttr(0);
    cx_object o = cx_declare(cx_void_o);
    cx_define(o);
    
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == (cx_type)cx_void_o);
    test_assert(cx_checkState(o, CX_VALID));
    test_assert(cx_checkState(o, CX_DECLARED));
    test_assert(cx_checkState(o, CX_DEFINED));
    test_assert(!cx_checkAttr(o, CX_ATTR_SCOPED));
    test_assert(!cx_checkAttr(o, CX_ATTR_WRITABLE));
    test_assert(!cx_checkAttr(o, CX_ATTR_OBSERVABLE));
    test_assert(!cx_checkAttr(o, CX_ATTR_PERSISTENT));
    cx_delete(o);

/* $end */
}

/* ::test::ObjectMgmt::tc_drop() */
cx_void _test_ObjectMgmt_tc_drop(test_ObjectMgmt this) {
/* $begin(::test::ObjectMgmt::tc_drop) */

    test_Foo o = cx_createChild(NULL, "o", test_Foo_o);
    test_assert(o != NULL);
    test_assert(!strcmp(cx_nameof(o), "o"));
    test_assert(cx_parentof(o) == root_o);    
    test_assert(cx_typeof(o) == (cx_type)test_Foo_o);
    test_assert(cx_checkState(o, CX_VALID));
    test_assert(cx_checkState(o, CX_DECLARED));
    test_assert(cx_checkState(o, CX_DEFINED));
    test_assert(cx_checkAttr(o, CX_ATTR_SCOPED));
    test_assert(cx_checkAttr(o, CX_ATTR_WRITABLE));
    test_assert(cx_checkAttr(o, CX_ATTR_OBSERVABLE));
    test_assert(cx_checkAttr(o, CX_ATTR_PERSISTENT));

    test_Foo p = cx_createChild(o, "p", test_Foo_o);
    test_assert(p != NULL);
    test_assert(!strcmp(cx_nameof(p), "p"));
    test_assert(cx_parentof(p) == o);    
    test_assert(cx_typeof(p) == (cx_type)test_Foo_o);
    test_assert(cx_checkState(p, CX_VALID));
    test_assert(cx_checkState(p, CX_DECLARED));
    test_assert(cx_checkState(p, CX_DEFINED));
    test_assert(cx_checkAttr(p, CX_ATTR_SCOPED));
    test_assert(cx_checkAttr(p, CX_ATTR_WRITABLE));
    test_assert(cx_checkAttr(p, CX_ATTR_OBSERVABLE));
    test_assert(cx_checkAttr(p, CX_ATTR_PERSISTENT));

    test_Foo q = cx_createChild(o, "q", test_Foo_o);
    test_assert(p != NULL);
    test_assert(!strcmp(cx_nameof(q), "q"));
    test_assert(cx_parentof(q) == o);    
    test_assert(cx_typeof(q) == (cx_type)test_Foo_o);
    test_assert(cx_checkState(q, CX_VALID));
    test_assert(cx_checkState(q, CX_DECLARED));
    test_assert(cx_checkState(q, CX_DEFINED));
    test_assert(cx_checkAttr(q, CX_ATTR_SCOPED));
    test_assert(cx_checkAttr(q, CX_ATTR_WRITABLE));
    test_assert(cx_checkAttr(q, CX_ATTR_OBSERVABLE));
    test_assert(cx_checkAttr(q, CX_ATTR_PERSISTENT));

    cx_object _p = cx_resolve(NULL, "o::p");
    test_assert(_p == p);
    cx_release(_p);

    cx_object _q = cx_resolve(NULL, "o::q");
    test_assert(_q == q);
    cx_release(_q);

    cx_drop(o);

    _p = cx_resolve(NULL, "o::p");
    test_assert(_p == NULL);

    _q = cx_resolve(NULL, "o::q");
    test_assert(_q == NULL);

    /* Arbitrary number of drops */
    cx_drop(o);
    cx_drop(o);
    cx_drop(o);

    test_assert(*test_initCalled_o == 3);
    test_assert(*test_constructCalled_o == 3);
    test_assert(*test_destructCalled_o == 2);

    cx_delete(o);

    test_assert(*test_destructCalled_o == 3);

/* $end */
}

/* ::test::ObjectMgmt::tc_invalidate() */
cx_void _test_ObjectMgmt_tc_invalidate(test_ObjectMgmt this) {
/* $begin(::test::ObjectMgmt::tc_invalidate) */

    cx_object o = cx_voidCreate();
    test_assert(o != NULL);
    test_assert(cx_typeof(o) == cx_void_o);
    test_assert(cx_checkState(o, CX_VALID));
    test_assert(cx_checkState(o, CX_DECLARED));
    test_assert(cx_checkState(o, CX_DEFINED));
    test_assert(cx_checkAttr(o, CX_ATTR_OBSERVABLE));

    cx_invalidate(o);
    test_assert(!cx_checkState(o, CX_VALID));
    cx_delete(o);

/* $end */
}

/* ::test::ObjectMgmt::teardown() */
cx_void _test_ObjectMgmt_teardown(test_ObjectMgmt this) {
/* $begin(::test::ObjectMgmt::teardown) */
    cx_setAttr(this->prevAttr);
/* $end */
}
