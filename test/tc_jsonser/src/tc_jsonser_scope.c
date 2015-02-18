#include <string.h>
#include <stdio.h>

#include "cortex.h"
#include "json.h"
#include "tc_jsonser_fixture__api.h"
#include "tc_jsonser_fixture__meta.h"
#include "tc_jsonser_fixture__type.h"


#define _test_ser_scope(object, expected) \
{\
    cx_json_ser_t userData = {NULL, NULL, 0, 0, 0, FALSE, FALSE, TRUE, FALSE};\
    cx_serialize(&serializer, tc_jsonser_fixture_##object##_o, &userData);\
    if (strcmp(userData.buffer, expected)) {\
        result = -1;\
        fprintf(\
            stderr,\
            "tc_jsonser_scope: FAIL:\nexpected:\n%s\nserialized:\n%s\n",\
            expected, userData.buffer);\
    }\
}

cx_int16 test_ser_scope(void) {
    cx_int16 result = 0;

    struct cx_serializer_s serializer = 
        cx_json_ser(CX_LOCAL, CX_NOT, CX_SERIALIZER_TRACE_NEVER);

    _test_ser_scope(namesp, 
        "[{\"name\":\"a\","
            "\"type\":\"int16\",\""
            "states\":\"V|DCL|DEF\",\""
            "attributes\":\"S|W|O\",\""
            "childCount\":0},"
        "{\"name\":\"b\",\""
            "type\":\"string\","
            "\"states\":\"V|DCL|DEF\",\""
            "attributes\":\"S|W|O\","
            "\"childCount\":0}]"
    );

    _test_ser_scope(Dog,
        "["
        "{\"name\":\"age\",\"type\":\"member\",\"states\":\"V|DCL|DEF\",\"attributes\":\"S|W|O\",\"childCount\":0},"
        "{\"name\":\"breed\",\"type\":\"member\",\"states\":\"V|DCL|DEF\",\"attributes\":\"S|W|O\",\"childCount\":0},"
        "{\"name\":\"lover\",\"type\":\"member\",\"states\":\"V|DCL|DEF\",\"attributes\":\"S|W|O\",\"childCount\":0},"
        "{\"name\":\"name\",\"type\":\"member\",\"states\":\"V|DCL|DEF\",\"attributes\":\"S|W|O\",\"childCount\":0}"
        "]"
    );

    return result;
}

#undef _test_ser_scope
