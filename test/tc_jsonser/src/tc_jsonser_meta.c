#include <string.h>
#include <stdio.h>

#include "cortex.h"
#include "json.h"
#include "tc_jsonser_fixture__api.h"
#include "tc_jsonser_fixture__meta.h"
#include "tc_jsonser_fixture__type.h"


#define _test_ser_meta(object, expected) \
{\
    cx_json_ser_t userData = {NULL, NULL, 0, 0, 0, TRUE, FALSE, FALSE};\
    cx_serialize(&serializer, tc_jsonser_fixture_##object##_o, &userData);\
    if (strcmp(userData.buffer, expected)) {\
        result = -1;\
        fprintf(\
            stderr,\
            "tc_jsonser_meta: FAIL:\nexpected:\n%s\nserialized:\n%s\n",\
            expected, userData.buffer);\
    }\
}

cx_int16 test_ser_meta(void) {
    cx_int16 result = 0;

    struct cx_serializer_s serializer = 
        cx_json_ser(CX_LOCAL, CX_NOT, CX_SERIALIZER_TRACE_NEVER);

    _test_ser_meta(i8n, "{\"name\":\"i8n\",\"type\":\"int8\",\"states\":\"V|DCL|DEF\",\"attributes\":\"S|W|O\",\"parent\":\"::tc_jsonser_fixture\",\"childCount\":0}");
    _test_ser_meta(u32z, "{\"name\":\"u32z\",\"type\":\"uint32\",\"states\":\"V|DCL|DEF\",\"attributes\":\"S|W|O\",\"parent\":\"::tc_jsonser_fixture\",\"childCount\":0}");
    _test_ser_meta(u64p, "{\"name\":\"u64p\",\"type\":\"uint64\",\"states\":\"V|DCL|DEF\",\"attributes\":\"S|W|O\",\"parent\":\"::tc_jsonser_fixture\",\"childCount\":0}");
    _test_ser_meta(f32z, "{\"name\":\"f32z\",\"type\":\"float32\",\"states\":\"V|DCL|DEF\",\"attributes\":\"S|W|O\",\"parent\":\"::tc_jsonser_fixture\",\"childCount\":0}");
    _test_ser_meta(f64p, "{\"name\":\"f64p\",\"type\":\"float64\",\"states\":\"V|DCL|DEF\",\"attributes\":\"S|W|O\",\"parent\":\"::tc_jsonser_fixture\",\"childCount\":0}");
    _test_ser_meta(bt, "{\"name\":\"bt\",\"type\":\"bool\",\"states\":\"V|DCL|DEF\",\"attributes\":\"S|W|O\",\"parent\":\"::tc_jsonser_fixture\",\"childCount\":0}");
    _test_ser_meta(sn, "{\"name\":\"sn\",\"type\":\"string\",\"states\":\"V|DCL|DEF\",\"attributes\":\"S|W|O\",\"parent\":\"::tc_jsonser_fixture\",\"childCount\":0}");
    _test_ser_meta(p, "{\"name\":\"p\",\"type\":\"::tc_jsonser_fixture::point2D\",\"states\":\"V|DCL|DEF\",\"attributes\":\"S|W|O\",\"parent\":\"::tc_jsonser_fixture\",\"childCount\":0}");
    _test_ser_meta(Gust, "{\"name\":\"Gust\",\"type\":\"::tc_jsonser_fixture::Djinn\",\"states\":\"V|DCL|DEF\",\"attributes\":\"S|W|O\",\"parent\":\"::tc_jsonser_fixture\",\"childCount\":0}");
    _test_ser_meta(Dog, "{\"name\":\"Dog\",\"type\":\"class\",\"states\":\"V|DCL|DEF\",\"attributes\":\"S|W|O\",\"parent\":\"::tc_jsonser_fixture\",\"childCount\":4}");
    _test_ser_meta(v0, "{\"name\":\"v0\",\"type\":\"void\",\"states\":\"V|DCL|DEF\",\"attributes\":\"S|O\",\"parent\":\"::tc_jsonser_fixture\",\"childCount\":1}");
    _test_ser_meta(v1, "{\"name\":\"v1\",\"type\":\"void\",\"states\":\"V|DCL|DEF\",\"attributes\":\"S|O\",\"parent\":\"::tc_jsonser_fixture\",\"childCount\":3}");
    _test_ser_meta(v1_v1, "{\"name\":\"v1\",\"type\":\"void\",\"states\":\"V|DCL|DEF\",\"attributes\":\"S|O\",\"parent\":\"::tc_jsonser_fixture::v1\",\"childCount\":4}");
    _test_ser_meta(v1_v2, "{\"name\":\"v2\",\"type\":\"void\",\"states\":\"V|DCL|DEF\",\"attributes\":\"S|O\",\"parent\":\"::tc_jsonser_fixture::v1\",\"childCount\":5}");
    _test_ser_meta(v1_v3, "{\"name\":\"v3\",\"type\":\"void\",\"states\":\"V|DCL|DEF\",\"attributes\":\"S|O\",\"parent\":\"::tc_jsonser_fixture::v1\",\"childCount\":6}");
    _test_ser_meta(v1_v1_v1, "{\"name\":\"v1\",\"type\":\"void\",\"states\":\"V|DCL|DEF\",\"attributes\":\"S|O\",\"parent\":\"::tc_jsonser_fixture::v1::v1\",\"childCount\":0}");
    _test_ser_meta(v1_v2_v2, "{\"name\":\"v2\",\"type\":\"void\",\"states\":\"V|DCL|DEF\",\"attributes\":\"S|O\",\"parent\":\"::tc_jsonser_fixture::v1::v2\",\"childCount\":0}");
    _test_ser_meta(v1_v3_v6, "{\"name\":\"v6\",\"type\":\"void\",\"states\":\"V|DCL|DEF\",\"attributes\":\"S|O\",\"parent\":\"::tc_jsonser_fixture::v1::v3\",\"childCount\":0}");

    return result;
}

#undef _test_ser_meta
