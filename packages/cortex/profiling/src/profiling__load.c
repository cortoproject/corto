/* profiling__load.c
 *
 * This file is generated. Only insert code in appropriate places.
 */

#include "profiling.h"

/* $header() */
/* Insert user-includes here */
/* $end */

/* This function is the entrypoint for the library and * loads definitions of the 'profiling' scope */
int cortexmain(int argc, char* argv[]) {
    CX_UNUSED(argc);
    CX_UNUSED(argv);
    
    int result = profiling_load();
    
    /* $begin(cortexmain) */
    /* $end */

    return result;
}

