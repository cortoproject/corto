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
cx_void _testjson_DeserPrimitiveTest_testSimpleString(testjson_DeserPrimitiveTest _this) {
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

/* ::testjson::DeserPrimitiveTest::testStruct_1L() */
cx_void _testjson_DeserPrimitiveTest_testStruct_1L(testjson_DeserPrimitiveTest _this) {
/* $begin(::testjson::DeserPrimitiveTest::testStruct_1L) */
    cx_object o = cx_json_deser(
        "{\"meta\": {\"name\": \"c\", \"parent\": \"::\", \"type\": \"::testjson::Point\"},"
        "\"value\": {\"x\": 45, \"y\": 3}}");
    testjson_BaseDeserTest __this = testjson_BaseDeserTest(_this);
    if (testjson_BaseDeserTest_testNameParentType(__this, o, "c", root_o, cx_type(testjson_Point_o))) {
        goto error;
    }
    testjson_Point expected = {45, 3};
    cx_any _actual = {cx_type(testjson_Point_o), o, FALSE};
    cx_any _expected = {cx_type(testjson_Point_o), &expected, FALSE};
    if (test_Suite_assertEqual_any_any(test_Suite(_this), _actual, _expected)) {
        goto error;
    }
    error:;
/* $end */
}

/* ::testjson::DeserPrimitiveTest::testStruct_2L() */
cx_void _testjson_DeserPrimitiveTest_testStruct_2L(testjson_DeserPrimitiveTest _this) {
/* $begin(::testjson::DeserPrimitiveTest::testStruct_2L) */
    cx_object o = cx_json_deser(
        "{\"meta\": {\"name\": \"d\", \"parent\": \"::\", \"type\": \"::testjson::Line\"},"
        "\"value\": {\"sense\": true, \"a\": {\"x\": 1, \"y\": 2}, \"b\": {\"x\": 3, \"y\": 4}}}");
    testjson_BaseDeserTest __this = testjson_BaseDeserTest(_this);
    if (testjson_BaseDeserTest_testNameParentType(__this, o, "d", root_o, cx_type(testjson_Line_o))) {
        goto error;
    }
    testjson_Line expected = {TRUE, {1, 2}, {3, 4}};
    cx_any _actual = {cx_type(testjson_Line_o), o, FALSE};
    cx_any _expected = {cx_type(testjson_Line_o), &expected, FALSE};
    if (test_Suite_assertEqual_any_any(test_Suite(_this), _actual, _expected)) {
        goto error;
    }
    error:;
/* $end */
}

/* ::testjson::DeserPrimitiveTest::testStruct_3L() */
cx_void _testjson_DeserPrimitiveTest_testStruct_3L(testjson_DeserPrimitiveTest _this) {
/* $begin(::testjson::DeserPrimitiveTest::testStruct_3L) */
    cx_object o = cx_json_deser(
        "{\"meta\": {\"name\": \"e\", \"parent\": \"::\", \"type\": \"::testjson::Triangle\"},"
            "\"value\": {"
            "\"a\": {\"sense\": true, \"a\": {\"x\": 1, \"y\": 2}, \"b\": {\"x\": 3, \"y\": 4}},"
            "\"b\": {\"sense\": false, \"a\": {\"x\": 3, \"y\": 8}, \"b\": {\"x\": 5, \"y\": 7}},"
            "\"c\": {\"sense\": true, \"a\": {\"x\": 56, \"y\": 12}, \"b\": {\"x\": 3, \"y\": 89}}"
            "}}");
    testjson_BaseDeserTest __this = testjson_BaseDeserTest(_this);
    if (testjson_BaseDeserTest_testNameParentType(__this, o, "e", root_o, cx_type(testjson_Triangle_o))) {
        goto error;
    }
    testjson_Triangle expected = {{TRUE, {1, 2}, {3, 4}}, {FALSE, {3, 8}, {5, 7}}, {TRUE, {56, 12}, {3, 89}}};
    cx_any _actual = {cx_type(testjson_Triangle_o), o, FALSE};
    cx_any _expected = {cx_type(testjson_Triangle_o), &expected, FALSE};
    if (test_Suite_assertEqual_any_any(test_Suite(_this), _actual, _expected)) {
        goto error;
    }
    error:;
/* $end */
}

/* ::testjson::DeserPrimitiveTest::testStructRef() */
cx_void _testjson_DeserPrimitiveTest_testStructRef(testjson_DeserPrimitiveTest _this) {
/* $begin(::testjson::DeserPrimitiveTest::testStructRef) */
    cx_object o = cx_json_deser(
        "{\"meta\": {\"name\": \"f\", \"parent\": \"::\", \"type\": \"::testjson::Team\"},"
            "\"value\": {\"dev\": \"::testjson::bulbasaur\","
            "\"test\": \"::testjson::charmander\", \"pm\": \"::testjson::squirtle\"}}"
        );
    testjson_BaseDeserTest __this = testjson_BaseDeserTest(_this);
    if (testjson_BaseDeserTest_testNameParentType(__this, o, "f", root_o, cx_type(testjson_Team_o))) {
        goto error;
    }
    testjson_Team expected = {testjson_bulbasaur_o, testjson_charmander_o, testjson_squirtle_o};
    cx_any _actual = {cx_type(testjson_Team_o), o, FALSE};
    cx_any _expected = {cx_type(testjson_Team_o), &expected, FALSE};
    if (test_Suite_assertEqual_any_any(test_Suite(_this), _actual, _expected)) {
        goto error;
    }
    error:;
/* $end */
}

/* ::testjson::DeserPrimitiveTest::testUint8() */
cx_void _testjson_DeserPrimitiveTest_testUint8(testjson_DeserPrimitiveTest _this) {
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
