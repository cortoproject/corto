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
cx_void testjson_TestJsonValue_setUp_v(testjson_TestJsonValue _this) {
/* $begin(::testjson::TestJsonValue::setUp) */
    testjson_BaseTestJson __this = testjson_BaseTestJson(_this);
    __this->jsonData = (cx_word)cx_malloc(sizeof(struct cx_json_ser_t));
    cx_json_ser_t jsonData = {NULL, NULL, 0, 0, 0, FALSE, TRUE, FALSE, TRUE};
    *((cx_json_ser_t *)__this->jsonData) = jsonData;
/* $end */
}

/* ::testjson::TestJsonValue::tearDown() */
cx_void testjson_TestJsonValue_tearDown_v(testjson_TestJsonValue _this) {
/* $begin(::testjson::TestJsonValue::tearDown) */
    CX_UNUSED(_this);
/* $end */
}
