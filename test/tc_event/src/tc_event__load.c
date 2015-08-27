/** 
 * This file is generated. Only insert code in appropriate places
 */

#include "tc_event__meta.h"

/* $header() */
/* Insert user-includes here */
/* $end */

/* This function is the entrypoint for the library and * loads definitions of the 'tc_event' scope */
int cortomain(int argc, char* argv[]) {
    CX_UNUSED(argc);
    CX_UNUSED(argv);
    
    int result = tc_event_load();
    
    /* $begin(cortomain) */
    /* Insert user-code here */
    /* $end */

    return result;
}

