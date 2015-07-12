/* testjson_BaseDeserTest.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "testjson.h"

/* ::testjson::BaseDeserTest::testName(object o,string name) */
cx_bool testjson_BaseDeserTest_testName(testjson_BaseDeserTest _this, cx_object o, cx_string name) {
/* $begin(::testjson::BaseDeserTest::testName) */
    cx_string actual = cx_nameof(o);
    cx_any _actual = {cx_type(cx_string_o), &actual, FALSE};
    cx_any _expected = {cx_type(cx_string_o), &name, FALSE};
    if (test_Suite_assertEqual_any_any(test_Suite(_this), _expected, _actual)) {
        goto error;
    }
    return FALSE;
error:
    return TRUE;
/* $end */
}

/* ::testjson::BaseDeserTest::testNameParentType(object o,string name,object parent,type type) */
cx_bool testjson_BaseDeserTest_testNameParentType(testjson_BaseDeserTest _this, cx_object o, cx_string name, cx_object parent, cx_type type) {
/* $begin(::testjson::BaseDeserTest::testNameParentType) */
    if (test_Suite_assert_bool_string(test_Suite(_this), o != NULL, "object not initialized")) {
        goto error;
    }
    if (name && testjson_BaseDeserTest_testName(_this, o, name)) {
        goto error;
    }
    if (parent && testjson_BaseDeserTest_testParent(_this, o, parent)) {
        goto error;
    }
    if (type && testjson_BaseDeserTest_testType(_this, o, type)) {
        goto error;
    }
    return FALSE;
error:
    return TRUE;
/* $end */
}

/* ::testjson::BaseDeserTest::testParent(object o,object parent) */
cx_bool testjson_BaseDeserTest_testParent(testjson_BaseDeserTest _this, cx_object o, cx_object parent) {
/* $begin(::testjson::BaseDeserTest::testParent) */
    cx_object actual = cx_parentof(o);
    cx_any _actual = {cx_typeof(actual), &actual, FALSE};
    cx_any _expected = {cx_typeof(parent), &parent, FALSE};
    if (test_Suite_assertEqual_any_any(test_Suite(_this), _expected, _actual)) {
        goto error;
    }
    return FALSE;
error:
    return TRUE;
/* $end */
}

/* ::testjson::BaseDeserTest::testType(object o,type type) */
cx_bool testjson_BaseDeserTest_testType(testjson_BaseDeserTest _this, cx_object o, cx_type type) {
/* $begin(::testjson::BaseDeserTest::testType) */
    cx_type actual = cx_typeof(o);
    cx_any _actual = {cx_type(cx_type_o), &actual, FALSE};
    cx_any _expected = {cx_type(cx_type_o), &type, FALSE};
    if (test_Suite_assertEqual_any_any(test_Suite(_this), _expected, _actual)) {
        goto error;
    }
    return FALSE;
error:
    return TRUE;
/* $end */
}
