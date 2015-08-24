/* testjson_TestJsonText.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "testjson.h"

/* ::testjson::TestJsonText::testAlpha() */
cx_void _testjson_TestJsonText_testAlpha(testjson_TestJsonText _this) {
/* $begin(::testjson::TestJsonText::testAlpha) */
    testjson_BaseTestJson_testJson(testjson_BaseTestJson(_this),
        "::testjson::primitives::texts::alpha",
        "{\"value\":\"Hello\"}");
/* $end */
}

/* ::testjson::TestJsonText::testEmpty() */
cx_void _testjson_TestJsonText_testEmpty(testjson_TestJsonText _this) {
/* $begin(::testjson::TestJsonText::testEmpty) */
    testjson_BaseTestJson_testJson(testjson_BaseTestJson(_this),
        "::testjson::primitives::texts::empty",
        "{\"value\":\"\"}");
/* $end */
}

/* ::testjson::TestJsonText::testEscaped() */
cx_void _testjson_TestJsonText_testEscaped(testjson_TestJsonText _this) {
/* $begin(::testjson::TestJsonText::testEscaped) */
    testjson_BaseTestJson_testJson(testjson_BaseTestJson(_this),
        "::testjson::primitives::texts::escaped",
        "{\"value\":\"Hello \\\\ \\\"world\\\"\"}");
/* $end */
}

/* ::testjson::TestJsonText::testNum() */
cx_void _testjson_TestJsonText_testNum(testjson_TestJsonText _this) {
/* $begin(::testjson::TestJsonText::testNum) */
    testjson_BaseTestJson_testJson(testjson_BaseTestJson(_this),
        "::testjson::primitives::texts::num",
        "{\"value\":\"455\"}");
/* $end */
}

/* ::testjson::TestJsonText::testPunctuation() */
cx_void _testjson_TestJsonText_testPunctuation(testjson_TestJsonText _this) {
/* $begin(::testjson::TestJsonText::testPunctuation) */
    testjson_BaseTestJson_testJson(testjson_BaseTestJson(_this),
        "::testjson::primitives::texts::punctuation",
        "{\"value\":\"Hello world!\"}");
/* $end */
}
