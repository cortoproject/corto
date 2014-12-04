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

#define test_value(object, expected) \
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

 #define test_scope(object, expected) \
 {\
    db_json_ser_t userData = {NULL, NULL, 0, 0, 0, FALSE, FALSE, TRUE};\
    db_serialize(&serializer, tc_jsonser_number_##object##_o, &userData);\
    if (strcmp(userData.buffer, "{\"scope\":"expected"}")) {\
        result = FALSE;\
        fprintf(\
            stderr,\
            "tc_jsonser_number: FAIL: expected %s, serialized %s\n",\
            "{\"scope\":"expected"}", userData.buffer);\
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

    /* Test numbers */
    test_value(f32z, "0");
    test_value(f32n, "-2.45");
    test_value(f32p, "45.2");
    test_value(f64z, "0");
    test_value(f64n, "-2.45");
    test_value(f64p, "45.2");
    test_value(i16n, "-2");
    test_value(i16p, "45");
    test_value(i16z, "0");
    test_value(i32n, "-2");
    test_value(i32p, "45");
    test_value(i32z, "0");
    test_value(i64n, "-2");
    test_value(i64p, "45");
    test_value(i64z, "0");
    test_value(u16p, "45");
    test_value(u16z, "0");
    test_value(u32p, "45");
    test_value(u32z, "0");
    test_value(u64p, "45");
    test_value(u64z, "0");

    /* Test boolean */
    test_value(bt, "true");
    test_value(bf, "false");

    /* Test other primitives */
    test_value(sn, "null");
    test_value(s1, "\"hello world\"");
    test_value(s1, "\"hello, world!\"");

    /* Test a struct */
    test_value(p, "{\"x\":3,\"y\":4}");

    /* Test scope */
    test_scope(namesp, "[{\"name\":\"a\",\"type\":\"::hyve::lang::int16\",\"states\":\"V|DCL|DEF\",\"attributes\":\"S|W|O\",\"childCount\":0},{\"name\":\"b\",\"type\":\"::hyve::lang::string\",\"states\":\"V|DCL|DEF\",\"attributes\":\"S|W|O\",\"childCount\":0}]");
 
    /* Stop database */
    db_stop();

    if (result) {
        printf("tc_jsonser_number: OK\n");
    }

    return result;
}
