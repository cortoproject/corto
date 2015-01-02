#include <string.h>
#include <stdio.h>

#include "cortex.h"
#include "json.h"
#include "tc_jsonser_fixture__api.h"
#include "tc_jsonser_fixture__meta.h"
#include "tc_jsonser_fixture__type.h"


#define _test_ser_primitive_value(object, expected) \
{\
    cx_json_ser_t userData = {NULL, NULL, 0, 0, 0, FALSE, TRUE, FALSE};\
    cx_serialize(&serializer, tc_jsonser_fixture_##object##_o, &userData);\
    if (strcmp(userData.buffer, "{\"value\":"expected"}")) {\
        result = -1;\
        fprintf(\
            stderr,\
            "tc_jsonser_primitive_value: FAIL:\nexpected:\n%s\nserialized:\n%s\n",\
            "{\"value\":"expected"}", userData.buffer);\
    }\
}

cx_int16 test_ser_primitive_value(void) {
    cx_int16 result = 0;

    struct cx_serializer_s serializer = 
        cx_json_ser(CX_LOCAL, CX_NOT, CX_SERIALIZER_TRACE_NEVER);

    _test_ser_primitive_value(i8n, "-2");
    _test_ser_primitive_value(i8p, "45");
    _test_ser_primitive_value(i8z, "0");
    _test_ser_primitive_value(i16n, "-2");
    _test_ser_primitive_value(i16p, "45");
    _test_ser_primitive_value(i16z, "0");
    _test_ser_primitive_value(i32n, "-2");
    _test_ser_primitive_value(i32p, "45");
    _test_ser_primitive_value(i32z, "0");
    _test_ser_primitive_value(i64n, "-2");
    _test_ser_primitive_value(i64p, "45");
    _test_ser_primitive_value(i64z, "0");
    
    _test_ser_primitive_value(u8p, "45");
    _test_ser_primitive_value(u8z, "0");
    _test_ser_primitive_value(u16p, "45");
    _test_ser_primitive_value(u16z, "0");
    _test_ser_primitive_value(u32p, "45");
    _test_ser_primitive_value(u32z, "0");
    _test_ser_primitive_value(u64p, "45");
    _test_ser_primitive_value(u64z, "0");
    
    _test_ser_primitive_value(f32z, "0.000000");
    _test_ser_primitive_value(f32n, "-2.450000");
    _test_ser_primitive_value(f32p, "45.200001");
    _test_ser_primitive_value(f64z, "0.000000");
    _test_ser_primitive_value(f64n, "-2.450000");
    _test_ser_primitive_value(f64p, "45.200000");

    _test_ser_primitive_value(bt, "true");
    _test_ser_primitive_value(bf, "false");

    _test_ser_primitive_value(c1, "\"a\"");
    _test_ser_primitive_value(c2, "\"A\"");
    _test_ser_primitive_value(c3, "\"0\"");
    _test_ser_primitive_value(c4, "\"\\n\"");
    _test_ser_primitive_value(c5, "null");

    _test_ser_primitive_value(sn, "null");
    _test_ser_primitive_value(s1, "\"hello world\"");
    _test_ser_primitive_value(s2, "\"hello, world!\"");
    _test_ser_primitive_value(s3, "\"@@\"");
    _test_ser_primitive_value(s4, "\"@@ hey\"");
    _test_ser_primitive_value(s5, "\"@@hey\"");
    _test_ser_primitive_value(s6, "\"@@hey you\"");
    _test_ser_primitive_value(s7, "\"@@@\"");
    _test_ser_primitive_value(s8, "\"@@@ hey\"");
    _test_ser_primitive_value(s9, "\"@@@hey\"");
    _test_ser_primitive_value(s10, "\"@@@hey you\"");
    _test_ser_primitive_value(s11, "\"@@@@@@\"");
    _test_ser_primitive_value(s12, "\"@@@@@@ hey\"");
    _test_ser_primitive_value(s13, "\"@@@@@@hey\"");
    _test_ser_primitive_value(s14, "\"@@@@@@hey you\"");
    // _test_ser_primitive_value(s15, "a tab \\t");
    // _test_ser_primitive_value(s16, "r\\rr");
    // _test_ser_primitive_value(s17, "\\v");

    _test_ser_primitive_value(yellow, "\"@M green|red\"");
    _test_ser_primitive_value(white, "\"@M blue|green|red\"");
    _test_ser_primitive_value(black, "\"@M 0\"");

    // _test_ser_primitive_value(o1, "@B 2d");
    // _test_ser_primitive_value(o2, "@B FF");

    _test_ser_primitive_value(Flint, "\"@E Venus\"");
    _test_ser_primitive_value(Forge, "\"@E Mars\"");
    _test_ser_primitive_value(Gust, "\"@E Jupiter\"");
    _test_ser_primitive_value(Sleet, "\"@E Mercury\"");



    return result;
}

#undef _test_ser_primitive_value
