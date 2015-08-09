/* io.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "io.h"

/* ::cortex::io::print(string str) */
cx_void io_print(cx_string str) {
/* $begin(::cortex::io::print) */
    printf("%s", str);
/* $end */
}

/* ::cortex::io::println(string str) */
cx_void io_println(cx_string str) {
/* $begin(::cortex::io::println) */
    printf("%s\n", str);
/* $end */
}

/* ::cortex::io::readln() */
cx_string io_readln(void) {
/* $begin(::cortex::io::readln) */
    size_t size=256;
    
    cx_string result = cx_alloc(size+1);
    scanf("%255s", result);

    return result;
/* $end */
}

int iomain(int argc, char* argv[]) {
/* $begin(main) */
    /* Insert code that must be run when component is loaded */
    CX_UNUSED(argc);
    CX_UNUSED(argv);
    return 0;
/* $end */
}
