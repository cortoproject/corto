/** 
 * This file is generated. Only insert code in appropriate places
 */

#include "tc_jsonser_fixture__meta.h"

/* $header() */
#include "tc_jsonser_collection_value.h"
#include "tc_jsonser_composite_value.h"
#include "tc_jsonser_primitive_value.h"
#include "tc_jsonser_reference_value.h"
#include "tc_jsonser_meta.h"
#include "tc_jsonser_scope.h"
/* $end */

/* This function is the entrypoint for the library and * loads definitions of the 'tc_jsonser_fixture' scope */
int cortexmain(int argc, char* argv[]) {
    CX_UNUSED(argc);
    CX_UNUSED(argv);
    
    int result = tc_jsonser_fixture_load();
    
    /* $begin(cortexmain) */
    result += test_ser_primitive_value();
    result += test_ser_reference_value();
    result += test_ser_collection_value();
    result += test_ser_composite_value();
    result += test_ser_meta();
    result += test_ser_scope();
    if (!result) {
        printf("tc_jsonser: OK\n");
    }
    /* $end */

    return result;
}

