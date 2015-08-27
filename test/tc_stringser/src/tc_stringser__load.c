/** 
 * This file is generated. Only insert code in appropriate places
 */

#include "tc_stringser__meta.h"

/* $header() */
/* Insert user-includes here */
/* $end */

/* This function is the entrypoint for the library and * loads definitions of the 'tc_stringser' scope */
int cortomain(int argc, char* argv[]) {
    CX_UNUSED(argc);
    CX_UNUSED(argv);
    
    int result = tc_stringser_load();
    
    /* $begin(cortomain) */
    /* Insert user-code here */
    /* $end */

    return result;
}

