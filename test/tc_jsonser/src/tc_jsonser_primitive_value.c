#include <string.h>
#include <stdio.h>

#include "hyve.h"
#include "json.h"
#include "tc_jsonser__api.h"
#include "tc_jsonser__meta.h"
#include "tc_jsonser__type.h"

#define _test_primitive_value(object, expected) \
 {\
     db_json_ser_t userData = {NULL, NULL, 0, 0, 0, FALSE, TRUE, FALSE};\
     db_serialize(&serializer, tc_jsonser_number_##object##_o, &userData);\
     if (strcmp(userData.buffer, "{\"value\":"expected"}")) {\
        result = FALSE;\
        fprintf(\
            stderr,\
            "tc_jsonser_number: FAIL: expected %s, serialized %s\n",\
            "{\"value\":"expected"}", userData.buffer);\
        result = -1;
     }\
 }

int16 test_primitive_value(void) {
    int16 result = 0;

    _test_primitive_value(f32z, "0");
    _test_primitive_value(f32n, "-2.45");
    _test_primitive_value(f32p, "45.2");
    _test_primitive_value(f64z, "0");
    _test_primitive_value(f64n, "-2.45");
    _test_primitive_value(f64p, "45.2");
    _test_primitive_value(i16n, "-2");
    _test_primitive_value(i16p, "45");
    _test_primitive_value(i16z, "0");
    _test_primitive_value(i32n, "-2");
    _test_primitive_value(i32p, "45");
    _test_primitive_value(i32z, "0");
    _test_primitive_value(i64n, "-2");
    _test_primitive_value(i64p, "45");
    _test_primitive_value(i64z, "0");
    _test_primitive_value(u16p, "45");
    _test_primitive_value(u16z, "0");
    _test_primitive_value(u32p, "45");
    _test_primitive_value(u32z, "0");
    _test_primitive_value(u64p, "45");
    _test_primitive_value(u64z, "0");

    _test_primitive_value(bt, "true");
    _test_primitive_value(bf, "false");

    _test_primitive_value(sn, "null");
    _test_primitive_value(s1, "\"hello world\"");
    _test_primitive_value(s1, "\"hello, world!\"");

    _test_primitive_value(p, "{\"x\":3,\"y\":4}");

    return result;
}

#undef _test_primitive_value