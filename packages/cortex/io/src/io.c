/* io.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
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
    int read;
    cx_string result = cx_malloc(size+1);

    if ((read = getline(&result, &size, stdin)) == -1) {
        cx_error("io::readln: read error\n");
        goto error;
    }
    
    /* Remove newline character */
    result[strlen(result)-1]='\0';
    
    return result;
error:
    cx_dealloc(result);
    return NULL;
/* $end */
}
