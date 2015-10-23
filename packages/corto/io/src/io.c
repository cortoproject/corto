/* io.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "io.h"

/* ::corto::io::print(string str) */
corto_void _io_print(corto_string str) {
/* $begin(::corto::io::print) */
    printf("%s", str);
/* $end */
}

/* ::corto::io::println(string str) */
corto_void _io_println(corto_string str) {
/* $begin(::corto::io::println) */
    printf("%s\n", str);
/* $end */
}

/* ::corto::io::readln() */
corto_string _io_readln(void) {
/* $begin(::corto::io::readln) */
    size_t size=256;
    
    corto_string result = corto_alloc(size+1);
    scanf("%255s", result);

    return result;
/* $end */
}

int ioMain(int argc, char* argv[]) {
/* $begin(main) */
    /* Insert code that must be run when component is loaded */
    CORTO_UNUSED(argc);
    CORTO_UNUSED(argv);
    return 0;
/* $end */
}
