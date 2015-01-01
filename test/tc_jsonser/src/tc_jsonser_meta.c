#include <string.h>
#include <stdio.h>

#include "cortex.h"
#include "json.h"
#include "fixture__api.h"
#include "fixture__meta.h"
#include "fixture__type.h"


#define _test_ser_meta(object, expected) \
{\
    db_json_ser_t userData = {NULL, NULL, 0, 0, 0, TRUE, FALSE, FALSE};\
    db_serialize(&serializer, fixture_##object##_o, &userData);\
    if (strcmp(userData.buffer, "{\"meta\":"expected"}")) {\
        result = -1;\
        fprintf(\
            stderr,\
            "tc_jsonser_meta: FAIL:\nexpected:\n%s\nserialized:\n%s\n",\
            "{\"meta\":"expected"}", userData.buffer);\
    }\
}

db_int16 test_ser_meta(void) {
    db_int16 result = 0;

    struct db_serializer_s serializer = 
        db_json_ser(DB_LOCAL, DB_NOT, DB_SERIALIZER_TRACE_NEVER);

    _test_ser_meta(i8n, "{\"name\":\"i8n\",\"type\":\"::cortex::lang::int8\",\"states\":\"V|DCL|DEF\",\"attributes\":\"S|W|O\",\"parent\":\"::fixture\",\"childCount\":0}");
    _test_ser_meta(u32z, "{\"name\":\"u32z\",\"type\":\"::cortex::lang::uint32\",\"states\":\"V|DCL|DEF\",\"attributes\":\"S|W|O\",\"parent\":\"::fixture\",\"childCount\":0}");
    _test_ser_meta(u64p, "{\"name\":\"u64p\",\"type\":\"::cortex::lang::uint64\",\"states\":\"V|DCL|DEF\",\"attributes\":\"S|W|O\",\"parent\":\"::fixture\",\"childCount\":0}");
    _test_ser_meta(f32z, "{\"name\":\"f32z\",\"type\":\"::cortex::lang::float32\",\"states\":\"V|DCL|DEF\",\"attributes\":\"S|W|O\",\"parent\":\"::fixture\",\"childCount\":0}");
    _test_ser_meta(f64p, "{\"name\":\"f64p\",\"type\":\"::cortex::lang::float64\",\"states\":\"V|DCL|DEF\",\"attributes\":\"S|W|O\",\"parent\":\"::fixture\",\"childCount\":0}");
    _test_ser_meta(bt, "{\"name\":\"bt\",\"type\":\"::cortex::lang::bool\",\"states\":\"V|DCL|DEF\",\"attributes\":\"S|W|O\",\"parent\":\"::fixture\",\"childCount\":0}");
    _test_ser_meta(sn, "{\"name\":\"sn\",\"type\":\"::cortex::lang::string\",\"states\":\"V|DCL|DEF\",\"attributes\":\"S|W|O\",\"parent\":\"::fixture\",\"childCount\":0}");
    _test_ser_meta(p, "{\"name\":\"p\",\"type\":\"::fixture::point2D\",\"states\":\"V|DCL|DEF\",\"attributes\":\"S|W|O\",\"parent\":\"::fixture\",\"childCount\":0}");
    _test_ser_meta(Gust, "{\"name\":\"Gust\",\"type\":\"::fixture::Djinn\",\"states\":\"V|DCL|DEF\",\"attributes\":\"S|W|O\",\"parent\":\"::fixture\",\"childCount\":0}");
    _test_ser_meta(Dog, "{\"name\":\"Dog\",\"type\":\"::cortex::lang::class\",\"states\":\"V|DCL|DEF\",\"attributes\":\"S|W|O\",\"parent\":\"::fixture\",\"childCount\":4}");
    _test_ser_meta(v0, "{\"name\":\"v0\",\"type\":\"::cortex::lang::void\",\"states\":\"V|DCL|DEF\",\"attributes\":\"S|O\",\"parent\":\"::fixture\",\"childCount\":1}");
    _test_ser_meta(v1, "{\"name\":\"v1\",\"type\":\"::cortex::lang::void\",\"states\":\"V|DCL|DEF\",\"attributes\":\"S|O\",\"parent\":\"::fixture\",\"childCount\":3}");
    _test_ser_meta(v1_v1, "{\"name\":\"v1\",\"type\":\"::cortex::lang::void\",\"states\":\"V|DCL|DEF\",\"attributes\":\"S|O\",\"parent\":\"::fixture::v1\",\"childCount\":4}");
    _test_ser_meta(v1_v2, "{\"name\":\"v2\",\"type\":\"::cortex::lang::void\",\"states\":\"V|DCL|DEF\",\"attributes\":\"S|O\",\"parent\":\"::fixture::v1\",\"childCount\":5}");
    _test_ser_meta(v1_v3, "{\"name\":\"v3\",\"type\":\"::cortex::lang::void\",\"states\":\"V|DCL|DEF\",\"attributes\":\"S|O\",\"parent\":\"::fixture::v1\",\"childCount\":6}");
    _test_ser_meta(v1_v1_v1, "{\"name\":\"v1\",\"type\":\"::cortex::lang::void\",\"states\":\"V|DCL|DEF\",\"attributes\":\"S|O\",\"parent\":\"::fixture::v1::v1\",\"childCount\":0}");
    _test_ser_meta(v1_v2_v2, "{\"name\":\"v2\",\"type\":\"::cortex::lang::void\",\"states\":\"V|DCL|DEF\",\"attributes\":\"S|O\",\"parent\":\"::fixture::v1::v2\",\"childCount\":0}");
    _test_ser_meta(v1_v3_v6, "{\"name\":\"v6\",\"type\":\"::cortex::lang::void\",\"states\":\"V|DCL|DEF\",\"attributes\":\"S|O\",\"parent\":\"::fixture::v1::v3\",\"childCount\":0}");

    return result;
}

#undef _test_ser_meta
