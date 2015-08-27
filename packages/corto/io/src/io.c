/* io.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "io.h"

/* ::corto::io::print(string str) */
cx_void _io_print(cx_string str) {
/* $begin(::corto::io::print) */
    printf("%s", str);
/* $end */
}

/* ::corto::io::println(string str) */
cx_void _io_println(cx_string str) {
/* $begin(::corto::io::println) */
    printf("%s\n", str);
/* $end */
}

/* ::corto::io::readln() */
cx_string _io_readln(void) {
/* $begin(::corto::io::readln) */
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
