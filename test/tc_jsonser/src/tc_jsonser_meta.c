#include <string.h>
#include <stdio.h>

#include "hyve.h"
#include "json.h"
#include "fixture__api.h"
#include "fixture__meta.h"
#include "fixture__type.h"


#define _test_ser_metadata(object, expected) \
{\
    db_json_ser_t userData = {NULL, NULL, 0, 0, 0, TRUE, FALSE, FALSE};\
    db_serialize(&serializer, fixture_##object##_o, &userData);\
    if (strcmp(userData.buffer, "{\"meta\":"expected"}")) {\
        result = -1;\
        fprintf(\
            stderr,\
            "tc_jsonser_metadata: FAIL:\nexpected:\n%s\nserialized:\n%s\n",\
            "{\"meta\":"expected"}", userData.buffer);\
    }\
}

db_int16 test_ser_metadata(void) {
    db_int16 result = 0;

    struct db_serializer_s serializer = 
        db_json_ser(DB_LOCAL, DB_NOT, DB_SERIALIZER_TRACE_NEVER);

    _test_ser_metadata(i8n, "-2");
    _test_ser_metadata(i8z, "0");
    _test_ser_metadata(i16n, "-2");
    _test_ser_metadata(i16z, "0");
    _test_ser_metadata(i32n, "-2");
    _test_ser_metadata(i32z, "0");
    _test_ser_metadata(i64z, "0");
    
    _test_ser_metadata(u8p, "45");
    _test_ser_metadata(u8z, "0");
    _test_ser_metadata(u16z, "0");
    _test_ser_metadata(u32z, "0");
    _test_ser_metadata(u64z, "0");
    
    _test_ser_metadata(f32z, "0.000000");
    _test_ser_metadata(f32n, "-2.450000");
    _test_ser_metadata(f64p, "45.200001");

    _test_ser_metadata(bt, "true");
    _test_ser_metadata(bf, "false");

    _test_ser_metadata(sn, "null");
    _test_ser_metadata(s1, "\"hello world\"");

    _test_ser_metadata(s3, "\"@@\"");
    _test_ser_metadata(s4, "\"@@ hey\"");
    _test_ser_metadata(s6, "\"@@hey you\"");
    _test_ser_metadata(s7, "\"@@@\"");
    _test_ser_metadata(s8, "\"@@@ hey\"");
    _test_ser_metadata(s10, "\"@@@hey you\"");
    _test_ser_metadata(s11, "\"@@@@@@\"");
    _test_ser_metadata(s14, "\"@@@@@@hey you\"");

    _test_ser_metadata(p, "{\"x\":3,\"y\":4}");

    _test_ser_metadata(Flint, "\"@E Venus\"");
    _test_ser_metadata(Gust, "\"@E Jupiter\"");

    return result;
}

#undef _test_ser_metadata