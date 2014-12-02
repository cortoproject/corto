/*
 * tc_jsonser.c
 *
 *  Created on: Nov 19, 2013
 *      Author: johnny
 */

#include "tc_jsonser__type.h"
#include "tc_jsonser__meta.h"
#include "tc_jsonser__api.h"
#include "json.h"
#include "hyve.h"

int main(int argc, char* argv[]) {
    DB_UNUSED(argc);
    DB_UNUSED(argv);
    db_bool result = TRUE;
    struct db_serializer_s serializer = 
        db_json_ser(DB_LOCAL, DB_NOT, DB_SERIALIZER_TRACE_NEVER);

    /* Start database */
    db_start();

    /* Load definitions */
    tc_jsonser_load();

    db_json_ser_t userData = {NULL, NULL, 0, 0, 0, TRUE, TRUE, TRUE};

    db_serialize(&serializer, tc_jsonser_pp_o, &userData);

    printf("%s\n", userData.buffer);
 
    /* Stop database */
    db_stop();

    if (result) {
        printf("tc_jsonser: OK\n");
    }

    return result;
}
