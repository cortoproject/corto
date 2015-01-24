#include <string.h>
#include <stdio.h>

#include "cortex.h"
#include "json.h"
#include "tc_jsonser_fixture__api.h"
#include "tc_jsonser_fixture__meta.h"
#include "tc_jsonser_fixture__type.h"


#define _test_ser_reference_value(object, expected) \
{\
    cx_json_ser_t userData = {NULL, NULL, 0, 0, 0, FALSE, TRUE, FALSE};\
    cx_serialize(&serializer, tc_jsonser_fixture_##object##_o, &userData);\
    if (strcmp(userData.buffer, expected)) {\
        result = -1;\
        fprintf(\
            stderr,\
            "tc_jsonser_reference_value: FAIL:\nexpected:\n%s\nserialized:\n%s\n",\
            expected, userData.buffer);\
    }\
}

cx_int16 test_ser_reference_value(void) {
    cx_int16 result = 0;

    struct cx_serializer_s serializer = 
        cx_json_ser(CX_LOCAL, CX_NOT, CX_SERIALIZER_TRACE_NEVER);

    _test_ser_reference_value(Dog, "{\"@base\":{\"@base\":{\"@base\":{\"defaultType\":\"@R ::cortex::lang::member\",\"parentType\":null,\"parentState\":\"@M 0\"},\"base\":null},\"baseAccess\":\"@M GLOBAL\"},\"implements\":[]}");
    _test_ser_reference_value(dog1, "{\"breed\":\"@E GoldenRetriever\",\"name\":\"Gijs\",\"age\":10,\"lover\":null}");
    _test_ser_reference_value(dog2, "{\"breed\":\"@E Pug\",\"name\":\"Lolly\",\"age\":4,\"lover\":null}");
    _test_ser_reference_value(dog3, "{\"breed\":\"@E Chihuahua\",\"name\":\"I'm annoying\",\"age\":3,\"lover\":\"@R ::tc_jsonser_fixture::dog2\"}");
    

    return result;
}

#undef _test_ser_reference_value
