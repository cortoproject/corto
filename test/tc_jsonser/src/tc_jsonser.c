#include <string.h>

#include "cortex.h"
#include "json.h"

#include "tc_jsonser_fixture__meta.h"
#include "tc_jsonser_fixture__api.h"
#include "tc_jsonser_fixture__type.h"

#include "tc_jsonser_meta.h"
#include "tc_jsonser_collection_value.h"
#include "tc_jsonser_composite_value.h"
#include "tc_jsonser_primitive_value.h"
#include "tc_jsonser_reference_value.h"
#include "tc_jsonser_scope.h"

int main(int argc, char* argv[]) {
    CX_UNUSED(argc);
    CX_UNUSED(argv);
    
    cx_int16 result = 0;

    cx_start();
    tc_jsonser_fixture_load();

    result += test_ser_primitive_value();
    result += test_ser_reference_value();
    result += test_ser_collection_value();
    result += test_ser_composite_value();
    result += test_ser_meta();
    result += test_ser_scope();
 
    cx_stop();

    if (!result) {
        printf("tc_jsonser: OK\n");
    }

    return result;
}
