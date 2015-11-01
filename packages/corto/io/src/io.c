/* $CORTO_GENERATED
 *
 * io.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "io.h"

corto_void _io_print(corto_string str) {
/* $begin(::corto::io::print) */
    printf("%s", str);
/* $end */
}

corto_void _io_println(corto_string str) {
/* $begin(::corto::io::println) */
    printf("%s\n", str);
/* $end */
}

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
