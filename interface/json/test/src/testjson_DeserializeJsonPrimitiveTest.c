/* testjson_DeserializeJsonPrimitiveTest.c
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

/* ::testjson::DeserializeJsonPrimitiveTest::setUp() */
cx_void testjson_DeserializeJsonPrimitiveTest_setUp(testjson_DeserializeJsonPrimitiveTest _this) {
/* $begin(::testjson::DeserializeJsonPrimitiveTest::setUp) */
    cx_object o = cx_json_deser("{ \"meta\": { \"name\": \"a\", \"parent\": \"::\", \"type\": \"int32\" }, \"value\": 78 }");
    cx_set(&testjson_BaseDeserializeJsonTest(_this)->o, o);
/* $end */
}

/* ::testjson::DeserializeJsonPrimitiveTest::testUint8() */
cx_void testjson_DeserializeJsonPrimitiveTest_testUint8(testjson_DeserializeJsonPrimitiveTest _this) {
/* $begin(::testjson::DeserializeJsonPrimitiveTest::testUint8) */
    testjson_BaseDeserializeJsonTest __this = testjson_BaseDeserializeJsonTest(_this);
    if (testjson_BaseDeserializeJsonTest_testNameParentType(__this, "a", root_o, cx_type(cx_int8_o))) {
        goto error;
    }
error:;
/* $end */
}
