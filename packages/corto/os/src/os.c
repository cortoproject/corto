/* $CORTO_GENERATED
 *
 * os.c
 *
 * Only ode written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "os.h"

corto_void _os_exit(corto_bool success) {
/* $begin(::corto::os::exit) */

    exit(success ? EXIT_SUCCESS : EXIT_FAILURE);

/* $end */
}

corto_void _os_sleep(corto_uint32 sec, corto_uint32 nsec) {
/* $begin(::corto::os::sleep) */

    corto_sleep(sec, nsec);

/* $end */
}

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
