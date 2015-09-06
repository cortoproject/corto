/* testjson_TestJsonValue.c
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

/* ::testjson::TestJsonValue::setUp() */
cx_void _testjson_TestJsonValue_setUp_v(testjson_TestJsonValue this) {
/* $begin(::testjson::TestJsonValue::setUp) */
    testjson_BaseTestJson _this = testjson_BaseTestJson(this);
    _this->jsonData = (cx_word)cx_alloc(sizeof(struct cx_json_ser_t));
    cx_json_ser_t jsonData = {NULL, NULL, 0, 0, 0, FALSE, TRUE, FALSE, TRUE};
    *((cx_json_ser_t *)_this->jsonData) = jsonData;
/* $end */
}

/* ::testjson::TestJsonValue::tearDown() */
cx_void _testjson_TestJsonValue_tearDown_v(testjson_TestJsonValue this) {
/* $begin(::testjson::TestJsonValue::tearDown) */
    CX_UNUSED(this);
/* $end */
}
