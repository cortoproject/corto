/** 
 * This file is generated. Only insert code in appropriate places
 */

#include "os__meta.h"

/* $header() *//* Insert user-includes here *//* $end */

/* This function is the entrypoint for the library and * loads definitions of the 'os' scope */
int cortexmain(int argc, char* argv[]) {
    CX_UNUSED(argc);
    CX_UNUSED(argv);
    
    int result = os_load();
    
    /* $begin(cortexmain) */
    /* Insert user-code here */
    /* $end */

    return result;
}

