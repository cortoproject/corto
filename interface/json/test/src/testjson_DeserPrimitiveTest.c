/* testjson_DeserPrimitiveTest.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "testjson.h"

/* $header() */

#include "json.h"

/* $end */

/* ::testjson::DeserPrimitiveTest::testSimpleString() */
cx_void testjson_DeserPrimitiveTest_testSimpleString(testjson_DeserPrimitiveTest _this) {
/* $begin(::testjson::DeserPrimitiveTest::testSimpleString) */
    cx_object o = cx_json_deser(
        "{\"meta\": {\"name\": \"b\", \"parent\": \"::\", \"type\": \"string\"},"
        "\"value\": \"Hello, World!\"}");
    testjson_BaseDeserTest __this = testjson_BaseDeserTest(_this);
    if (testjson_BaseDeserTest_testNameParentType(__this, o, "b", root_o, cx_type(cx_string_o))) {
        goto error;
    }
    cx_string expected = "Hello, World!";
    cx_any _actual = {cx_type(cx_string_o), o, FALSE};
    cx_any _expected = {cx_type(cx_string_o), &expected, FALSE};
    if (test_Suite_assertEqual_any_any(test_Suite(_this), _actual, _expected)) {
        goto error;
    }
error:;
/* $end */
}

/* ::testjson::DeserPrimitiveTest::testUint8() */
cx_void testjson_DeserPrimitiveTest_testUint8(testjson_DeserPrimitiveTest _this) {
/* $begin(::testjson::DeserPrimitiveTest::testUint8) */
    cx_object o = cx_json_deser(
        "{\"meta\": {\"name\": \"a\", \"parent\": \"::\", \"type\": \"int8\"},"
        " \"value\": 78}");
    testjson_BaseDeserTest __this = testjson_BaseDeserTest(_this);
    if (testjson_BaseDeserTest_testNameParentType(__this, o, "a", root_o, cx_type(cx_int8_o))) {
        goto error;
    }
    cx_int8 expected = 78;
    cx_any _actual = {cx_type(cx_int8_o), o, FALSE};
    cx_any _expected = {cx_type(cx_int8_o), &expected, FALSE};
    if (test_Suite_assertEqual_any_any(test_Suite(_this), _actual, _expected)) {
        goto error;
    }
error:;
/* $end */
}
