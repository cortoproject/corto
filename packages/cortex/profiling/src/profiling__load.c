/* profiling__load.c
 *
 * This file is generated. Only insert code in appropriate places.
 */

#include "profiling.h"

/* $header() */

#include "profiling__keyvalue.h"

cx_threadKey profiling_key = 0;

static void profiling_clearTlsValue(void *data) {
    profiling_TlsValue *value = data;
    cx_ll ll = value->ll;
    if (ll) {
        cx_llFree(ll);
    }
}
/* $end */

/* This function is the entrypoint for the library and * loads definitions of the 'profiling' scope */
int cortexmain(int argc, char* argv[]) {
    CX_UNUSED(argc);
    CX_UNUSED(argv);
    
    int result = profiling_load();
    
    /* $begin(cortexmain) */
    
    if (cx_threadTlsKey(&profiling_key, profiling_clearTlsValue)) {
        cx_error("Cannot create profiling key");
    }
    /* $end */

    return result;
}

