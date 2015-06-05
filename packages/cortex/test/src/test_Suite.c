/* test_Suite.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "test.h"

/* $header() */

/*
 * Returns 0 if the condition was successful
 */
static cx_bool test_Suite_test(test_Suite _this, cx_bool b, cx_string assertmsg, cx_string errmsg) {
    if (_this->result.success && !b) {
        _this->result.assertmsg = cx_strdup(assertmsg);
        if (errmsg) {
            _this->result.errmsg = cx_strdup(errmsg);
        } else {
            _this->result.errmsg = NULL;
        }
        _this->result.success = FALSE;
    }
    return !b;
}

typedef struct {
    test_Suite o;
    cx_procedure p; /* test_SetUp_o or test_TearDown_o */
} test_Suite_fixtureDiscoveryScopeWalkData;

/*
 * Receives a test_Suite_fixtureDiscoveryScopeWalkData
 */
static int test_Suite_fixtureDiscoveryScopeWalk(cx_object o, void *data) {
    test_Suite_fixtureDiscoveryScopeWalkData *_data = data;
    cx_object _this = _data->o;
    cx_procedure p = _data->p;
    if (cx_instanceof(cx_type(p), o)) {
        cx_call(o, NULL, _this);
    }
    return TRUE;
}

/*
 * Code common to rSetUp and rTearDown
 */
static cx_void test_Suite_rFixture(test_Suite _this, cx_object type, const test_Suite_fixtureDiscoveryScopeWalkData *data) {
    cx_interface i = cx_interface(type);
    if (i->base) {
        test_Suite_rFixture(_this, i->base, data);
    }
    cx_scopeWalk(type, test_Suite_fixtureDiscoveryScopeWalk, (void *)data);
}

/* $end */

/* ::cortex::test::Suite::assert(bool b) */
cx_bool test_Suite_assert_bool(test_Suite _this, cx_bool b) {
/* $begin(::cortex::test::Suite::assert(bool b)) */
    return test_Suite_assert_bool_string(_this, b, NULL);
/* $end */
}

/* ::cortex::test::Suite::assert(bool b,string errmsg) */
cx_bool test_Suite_assert_bool_string(test_Suite _this, cx_bool b, cx_string errmsg) {
/* $begin(::cortex::test::Suite::assert(bool b,string errmsg)) */
    return test_Suite_test(_this, b, "Not true", errmsg);
/* $end */
}

/* ::cortex::test::Suite::assertEqual(any a,any b) */
cx_bool test_Suite_assertEqual_any_any(test_Suite _this, cx_any a, cx_any b) {
/* $begin(::cortex::test::Suite::assertEqual(any a,any b)) */
    return test_Suite_assertEqual_any_any_string(_this, a, b, NULL);
/* $end */
}

/* ::cortex::test::Suite::assertEqual(any a,any b,string errmsg) */
cx_bool test_Suite_assertEqual_any_any_string(test_Suite _this, cx_any a, cx_any b, cx_string errmsg) {
/* $begin(::cortex::test::Suite::assertEqual(any a,any b,string errmsg)) */
    cx_bool result;
    cx_equalityKind eq;
    cx_value aV, bV;
    cx_string aS, bS;
    char *assertmsg;
    int length;
    eq = cx_type_compare(a, b);
    cx_valueValueInit(&aV, NULL, a.type, a.value);
    cx_valueValueInit(&bV, NULL, b.type, b.value);
    aS = cx_valueToString(&aV, 0);
    bS = cx_valueToString(&bV, 0);
    length = snprintf(NULL, 0, "%s != %s", aS, bS);
    if (length < 0) {
        cx_critical("error in snprintf");
    }
    assertmsg = cx_malloc(length + 1);
    sprintf(assertmsg, "%s != %s", aS, bS);
    result = test_Suite_test(_this, eq == CX_EQ, assertmsg, errmsg);
    cx_dealloc(assertmsg);
    return result;
/* $end */
}

/* ::cortex::test::Suite::construct() */
cx_int16 test_Suite_construct(test_Suite _this) {
/* $begin(::cortex::test::Suite::construct) */
    if (_this->test) {
        cx_type type = cx_typeof(_this);
        test_Suite_rSetUp(_this, type);
        _this->result.success = TRUE;
        cx_call(cx_function(_this->test), NULL, _this);
        test_Suite_rTearDown(_this, type);
    } else {
        _this->result.success = FALSE;
    }
    return 0;
/* $end */
}

/* ::cortex::test::Suite::rSetUp(object type) */
cx_void test_Suite_rSetUp(test_Suite _this, cx_object type) {
/* $begin(::cortex::test::Suite::rSetUp) */
    test_Suite_fixtureDiscoveryScopeWalkData data = {_this, test_SetUp_o};
    test_Suite_rFixture(_this, type, &data);
/* $end */
}

/* ::cortex::test::Suite::rTearDown(object type) */
cx_void test_Suite_rTearDown(test_Suite _this, cx_object type) {
/* $begin(::cortex::test::Suite::rTearDown) */
    test_Suite_fixtureDiscoveryScopeWalkData data = {_this, test_TearDown_o};
    test_Suite_rFixture(_this, type, &data);
/* $end */
}
