/* os.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "os.h"

/* ::corto::os::exit(bool success) */
cx_void _os_exit(cx_bool success) {
/* $begin(::corto::os::exit) */

    exit(success ? EXIT_SUCCESS : EXIT_FAILURE);

/* $end */
}

/* ::corto::os::sleep(uint32 sec,uint32 nsec) */
cx_void _os_sleep(cx_uint32 sec, cx_uint32 nsec) {
/* $begin(::corto::os::sleep) */

    cx_sleep(sec, nsec);

/* $end */
}

/* ::corto::os::system(string cmd) */
cx_void _os_system(cx_string cmd) {
/* $begin(::corto::os::system) */

    system(cmd);

/* $end */
}

int osmain(int argc, char* argv[]) {
/* $begin(main) */
    /* Insert code that must be run when component is loaded */
    CX_UNUSED(argc);
    CX_UNUSED(argv);
    return 0;
/* $end */
}
