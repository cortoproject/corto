/* testjson_BaseDeserializeJsonTest.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "testjson.h"

/* ::testjson::BaseDeserializeJsonTest::testName(string name) */
cx_bool testjson_BaseDeserializeJsonTest_testName(testjson_BaseDeserializeJsonTest _this, cx_string name) {
/* $begin(::testjson::BaseDeserializeJsonTest::testName) */
    cx_string actual = cx_nameof(_this->o);
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

/* ::testjson::BaseDeserializeJsonTest::testNameParentType(string name,object parent,type type) */
cx_bool testjson_BaseDeserializeJsonTest_testNameParentType(testjson_BaseDeserializeJsonTest _this, cx_string name, cx_object parent, cx_type type) {
/* $begin(::testjson::BaseDeserializeJsonTest::testNameParentType) */
    if (testjson_BaseDeserializeJsonTest_testName(_this, name)) {
        goto error;
    }
    if (testjson_BaseDeserializeJsonTest_testParent(_this, parent)) {
        goto error;
    }
    if (testjson_BaseDeserializeJsonTest_testType(_this, type)) {
        goto error;
    }
    return FALSE;
error:
    return TRUE;
/* $end */
}

/* ::testjson::BaseDeserializeJsonTest::testParent(object parent) */
cx_bool testjson_BaseDeserializeJsonTest_testParent(testjson_BaseDeserializeJsonTest _this, cx_object parent) {
/* $begin(::testjson::BaseDeserializeJsonTest::testParent) */
    cx_object actual = cx_parentof(_this->o);
    cx_any _actual = {cx_typeof(actual), actual, FALSE};
    cx_any _expected = {cx_typeof(parent), parent, FALSE};
    if (test_Suite_assertEqual_any_any(test_Suite(_this), _expected, _actual)) {
        goto error;
    }
    return FALSE;
error:
    return TRUE;
/* $end */
}

/* ::testjson::BaseDeserializeJsonTest::testType(type type) */
cx_bool testjson_BaseDeserializeJsonTest_testType(testjson_BaseDeserializeJsonTest _this, cx_type type) {
/* $begin(::testjson::BaseDeserializeJsonTest::testType) */
    cx_type actual = cx_typeof(_this->o);
    cx_any _actual = {cx_type(cx_type_o), actual, FALSE};
    cx_any _expected = {cx_type(cx_type_o), type, FALSE};
    if (test_Suite_assertEqual_any_any(test_Suite(_this), _expected, _actual)) {
        goto error;
    }
    return FALSE;
error:
    return TRUE;
/* $end */
}
