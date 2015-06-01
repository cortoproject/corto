/* ic__load.c
 *
 * This file is generated. Only insert code in appropriate places.
 */

#include "ic.h"

/* $header() */
cx_threadKey IC_PROGRAM_KEY;
/* $end */

/* This function is the entrypoint for the library and * loads definitions of the 'ic' scope */
int cortexmain(int argc, char* argv[]) {
    CX_UNUSED(argc);
    CX_UNUSED(argv);
    
    int result = ic_load();
    
    /* $begin(cortexmain) */
    if (cx_threadTlsKey(&IC_PROGRAM_KEY, NULL)) {
        return -1;
    }
    /* $end */

    return result;
}

