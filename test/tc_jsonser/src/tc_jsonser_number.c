/*
 * tc_jsonser.c
 *
 *  Created on: Nov 19, 2013
 *      Author: johnny
 */

#include <string.h>
#include "hyve.h"
#include "json.h"
#include "tc_jsonser_number__api.h"
#include "tc_jsonser_number__meta.h"
#include "tc_jsonser_number__type.h"

#define test_object(object, expected) \
 {\
     db_json_ser_t userData = {NULL, NULL, 0, 0, 0, FALSE, TRUE, FALSE};\
     db_serialize(&serializer, tc_jsonser_number_##object##_o, &userData);\
     if (strcmp(userData.buffer, "{\"value\":"expected"}")) {\
        result = FALSE;\
        fprintf(\
            stderr,\
            "tc_jsonser_number: FAIL: expected %s, serialized %s\n",\
            "{\"value\":"expected"}", userData.buffer);\
     }\
 }

int main(int argc, char* argv[]) {
    DB_UNUSED(argc);
    DB_UNUSED(argv);
    db_bool result = TRUE;
    struct db_serializer_s serializer = 
        db_json_ser(DB_LOCAL, DB_NOT, DB_SERIALIZER_TRACE_NEVER);

    /* Start database */
    db_start();

    /* Load definitions */
    tc_jsonser_number_load();

    test_object(f32z, "0");
    test_object(f32n, "-2.45");
    test_object(f32p, "45.2");
    test_object(f64z, "0");
    test_object(f64n, "-2.45");
    test_object(f64p, "45.2");
    test_object(i16n, "-2");
    test_object(i16p, "45");
    test_object(i16z, "0");
    test_object(i32n, "-2");
    test_object(i32p, "45");
    test_object(i32z, "0");
    test_object(i64n, "-2");
    test_object(i64p, "45");
    test_object(i64z, "0");
    test_object(u16p, "45");
    test_object(u16z, "0");
    test_object(u32p, "45");
    test_object(u32z, "0");
    test_object(u64p, "45");
    test_object(u64z, "0");
 
    /* Stop database */
    db_stop();

    if (result) {
        printf("tc_jsonser_number: OK\n");
    }

    return result;
}
