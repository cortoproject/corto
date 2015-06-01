/* testjson_TestJsonValueOnly.c
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

/* ::testjson::TestJsonValueOnly::setUp() */
cx_void testjson_TestJsonValueOnly_setUp(testjson_TestJsonValueOnly _this) {
/* $begin(::testjson::TestJsonValueOnly::setUp) */
    testjson_BaseTestJson __this = testjson_BaseTestJson(_this);
    __this->jsonData = (cx_word)cx_malloc(sizeof(struct cx_json_ser_t));
    cx_json_ser_t jsonData = {NULL, NULL, 0, 0, 0, FALSE, TRUE, TRUE, TRUE};
    *((cx_json_ser_t *)__this->jsonData) = jsonData;
/* $end */
}

/* ::testjson::TestJsonValueOnly::tearDown() */
cx_void testjson_TestJsonValueOnly_tearDown(testjson_TestJsonValueOnly _this) {
/* $begin(::testjson::TestJsonValueOnly::tearDown) */

    CX_UNUSED(_this);

/* $end */
}

/* ::testjson::TestJsonValueOnly::testNegativeInt8() */
cx_void testjson_TestJsonValueOnly_testNegativeInt8(testjson_TestJsonValueOnly _this) {
/* $begin(::testjson::TestJsonValueOnly::testNegativeInt8) */
    testjson_BaseTestJson_testJson(testjson_BaseTestJson(_this),
        "::testjson::primitives::ints::b",
        "{}");
/* $end */
}

/* ::testjson::TestJsonValueOnly::testPositiveInt8() */
cx_void testjson_TestJsonValueOnly_testPositiveInt8(testjson_TestJsonValueOnly _this) {
/* $begin(::testjson::TestJsonValueOnly::testPositiveInt8) */
    testjson_BaseTestJson_testJson(testjson_BaseTestJson(_this),
        "::testjson::primitives::ints::a",
        "{\"value\":127,\"scope\":[]}");
/* $end */
}

/* ::testjson::TestJsonValueOnly::testZeroInt8() */
cx_void testjson_TestJsonValueOnly_testZeroInt8(testjson_TestJsonValueOnly _this) {
/* $begin(::testjson::TestJsonValueOnly::testZeroInt8) */
    testjson_BaseTestJson_testJson(testjson_BaseTestJson(_this),
        "::testjson::primitives::ints::b",
        "{}");
/* $end */
}
