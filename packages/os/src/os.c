/* os.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "os.h"
#include "os__meta.h"

/* ::cortex::os::exit(bool success) */
cx_void os_exit(cx_bool success) {
/* $begin(::cortex::os::exit) */

    exit(success ? EXIT_SUCCESS : EXIT_FAILURE);

/* $end */
}

/* ::cortex::os::loadavg(loadAvgKind kind) */
cx_float64 os_loadavg(os_loadAvgKind kind) {
/* $begin(::cortex::os::loadavg) */
    double result[3];
    unsigned int c;

    if (getloadavg(result, 3) == -1) {
        cx_error("os::loadavg failed!");
    }

    switch(kind) {
    case OS_MIN_1:
        c = 0;
        break;
    case OS_MIN_5:
        c = 1;
        break;
    case OS_MIN_15:
        c = 2;
        break;
    default:
        cx_error("os::loadavg: invalid kind!");
        c = 0;
        break;
    }

    return result[c];
/* $end */
}

/* ::cortex::os::sleep(uint32 sec,uint32 nsec) */
cx_void os_sleep(cx_uint32 sec, cx_uint32 nsec) {
/* $begin(::cortex::os::sleep) */

    cx_sleep(sec, nsec);

/* $end */
}

/* ::cortex::os::system(string cmd) */
cx_void os_system(cx_string cmd) {
/* $begin(::cortex::os::system) */

    system(cmd);

/* $end */
}
