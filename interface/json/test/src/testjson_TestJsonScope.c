/* testjson_TestJsonScope.c
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

/* ::testjson::TestJsonScope::setUp() */
cx_void testjson_TestJsonScope_setUp_v(testjson_TestJsonScope _this) {
/* $begin(::testjson::TestJsonScope::setUp) */
    testjson_BaseTestJson __this = testjson_BaseTestJson(_this);
    __this->jsonData = (cx_word)cx_alloc(sizeof(struct cx_json_ser_t));
    cx_json_ser_t jsonData = {NULL, NULL, 0, 0, 0, FALSE, TRUE, TRUE, TRUE};
    *((cx_json_ser_t *)__this->jsonData) = jsonData;
/* $end */
}

/* ::testjson::TestJsonScope::tearDown() */
cx_void testjson_TestJsonScope_tearDown_v(testjson_TestJsonScope _this) {
/* $begin(::testjson::TestJsonScope::tearDown) */
    CX_UNUSED(_this);
/* $end */
}
