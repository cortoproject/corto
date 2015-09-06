/* testjson_BaseTestJson.c
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

/* ::testjson::BaseTestJson::setUp() */
cx_void _testjson_BaseTestJson_setUp_v(testjson_BaseTestJson this) {
/* $begin(::testjson::BaseTestJson::setUp) */
    testjson_BaseTestJson(this)->serializer = (cx_word)cx_alloc(sizeof(struct cx_serializer_s));
    struct cx_serializer_s *serializer = (void *)testjson_BaseTestJson(this)->serializer;
    *serializer = cx_json_ser(CX_PRIVATE, CX_NOT, CX_SERIALIZER_TRACE_NEVER);
/* $end */
}

/* ::testjson::BaseTestJson::tearDown() */
cx_void _testjson_BaseTestJson_tearDown_v(testjson_BaseTestJson this) {
/* $begin(::testjson::BaseTestJson::tearDown) */
    void *serializer = (void *)testjson_BaseTestJson(this)->serializer;
    void *jsonData = (void *)testjson_BaseTestJson(this)->jsonData;
    if (serializer) {
        cx_dealloc(serializer);
    }
    if (jsonData) {
        cx_dealloc(jsonData);
    }
/* $end */
}

/* ::testjson::BaseTestJson::testJson(string fullname,string expected) */
cx_void _testjson_BaseTestJson_testJson(testjson_BaseTestJson this, cx_string fullname, cx_string expected) {
/* $begin(::testjson::BaseTestJson::testJson) */
    struct cx_serializer_s *serializer = (void *)this->serializer;
    cx_json_ser_t *jsonData = (void *)this->jsonData;
    cx_object o = cx_resolve(NULL, fullname);
    cx_string errmsg;
    int length;
    length = snprintf(NULL, 0, "Cannot find %s", fullname);
    if (length < 0) {
        cx_critical("Failed snprintf");
    }
    errmsg = cx_alloc(length + 1);
    sprintf(errmsg, "Cannot find %s", fullname);
    if (test_Suite_assert_bool_string(test_Suite(this), o != NULL, errmsg)) {
        goto finished;
    }
    cx_serialize(serializer, o, jsonData);
    cx_string actual = jsonData->buffer;
    cx_any _expected = {cx_type(cx_string_o), &expected, FALSE};
    cx_any _actual = {cx_type(cx_string_o), &actual, FALSE};
    if (test_Suite_assertEqual_any_any(test_Suite(this), _expected, _actual)) {
        goto finished;
    }
finished:
    return;
/* $end */
}
