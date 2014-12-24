#include <string.h>

#include "hyve.h"
#include "json.h"

#include "fixture__meta.h"
#include "fixture__api.h"
#include "fixture__type.h"

#include "tc_jsonser_meta.h"
#include "tc_jsonser_collection_value.h"
#include "tc_jsonser_composite_value.h"
#include "tc_jsonser_primitive_value.h"
#include "tc_jsonser_reference_value.h"
#include "tc_jsonser_scope.h"

int main(int argc, char* argv[]) {
    DB_UNUSED(argc);
    DB_UNUSED(argv);
    
    db_int16 result = 0;

    db_start();
    fixture_load();

    result += test_ser_primitive_value();
    result += test_ser_reference_value();
    result += test_ser_collection_value();
    result += test_ser_composite_value();
    result += test_ser_meta();
    result += test_ser_scope();
 
    db_stop();

    if (!result) {
        printf("tc_jsonser: OK\n");
    }

    return result;
}
