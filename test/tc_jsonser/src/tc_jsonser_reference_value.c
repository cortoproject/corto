#include <string.h>
#include <stdio.h>

#include "hyve.h"
#include "json.h"
#include "tc_jsonser__api.h"
#include "tc_jsonser__meta.h"
#include "tc_jsonser__type.h"


#define _test_ser_reference_value(object, expected) \
{\
    db_json_ser_t userData = {NULL, NULL, 0, 0, 0, FALSE, TRUE, FALSE};\
    db_serialize(&serializer, tc_jsonser_##object##_o, &userData);\
    if (strcmp(userData.buffer, "{\"value\":"expected"}")) {\
        result = -1;\
        fprintf(\
            stderr,\
            "tc_jsonser_number: FAIL:\nexpected:\n%s\nserialized:\n%s\n",\
            "{\"value\":"expected"}", userData.buffer);\
    }\
}

db_int16 test_ser_reference_value(void) {
    db_int16 result = 0;

    struct db_serializer_s serializer = 
        db_json_ser(DB_LOCAL, DB_NOT, DB_SERIALIZER_TRACE_NEVER);

    _test_ser_reference_value(Dog, "");
    _test_ser_reference_value(dog1, "{\"breed\":\"@E GoldenRetriever\",\"name\":\"Gijs\",\"age\":10,\"lover\":null}");
    _test_ser_reference_value(dog2, "{\"breed\":\"@E Pug\",\"name\":\"Lolly\",\"age\":4,\"lover\":null}");
    _test_ser_reference_value(dog3, "{\"breed\":\"@E Chihuahua\",\"name\":\"I'm annoying\",\"age\":3,\"lover\":\"@R ::tc_jsonser::dog2\"}");
    

    return result;
}

#undef _test_ser_primitive_value