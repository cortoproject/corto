/* os.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "os.h"

/* ::corto::os::exit(bool success) */
corto_void _os_exit(corto_bool success) {
/* $begin(::corto::os::exit) */

    exit(success ? EXIT_SUCCESS : EXIT_FAILURE);

/* $end */
}

/* ::corto::os::sleep(uint32 sec,uint32 nsec) */
corto_void _os_sleep(corto_uint32 sec, corto_uint32 nsec) {
/* $begin(::corto::os::sleep) */

    corto_sleep(sec, nsec);

/* $end */
}

/* ::corto::os::system(string cmd) */
corto_void _os_system(corto_string cmd) {
/* $begin(::corto::os::system) */

    system(cmd);

/* $end */
}

int osMain(int argc, char* argv[]) {
/* $begin(main) */
    /* Insert code that must be run when component is loaded */
    CORTO_UNUSED(argc);
    CORTO_UNUSED(argv);
    return 0;
/* $end */
}
