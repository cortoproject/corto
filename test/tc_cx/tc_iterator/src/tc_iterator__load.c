/** 
 * This file is generated. Only insert code in appropriate places
 */

#include "tc_iterator__meta.h"

/* $header() */
#include "cx_err.h"

#include "tc_iterator.h"

int cortexmain(int argc, char *argv[]);
int main(int argc, char *argv[]) {
    cx_start();
    int result = cortexmain(argc, argv);
    cx_stop();
    return result;
}
/* $end */

/* This function is the entrypoint for the library and * loads definitions of the 'tc_iterator' scope */
int cortexmain(int argc, char* argv[]) {
    CX_UNUSED(argc);
    CX_UNUSED(argv);
    
    int result = tc_iterator_load();
    
    /* $begin(cortexmain) */
    result += !tc_iterator_testArray();
    /* $end */

    if (result == 0) {
        cx_print("tc_iterator: OK\n");
    }

    return result;
}

