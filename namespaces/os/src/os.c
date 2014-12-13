/* os.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "os.h"
#include "os__meta.h"

/* ::hyve::os::exit(::hyve::lang::bool success) */
db_void os_exit(db_bool success) {
/* $begin(::hyve::os::exit) */

    exit(success ? EXIT_SUCCESS : EXIT_FAILURE);

/* $end */
}

/* ::hyve::os::loadavg(::hyve::os::loadAvgKind kind) */
db_float64 os_loadavg(os_loadAvgKind kind) {
/* $begin(::hyve::os::loadavg) */
    double result[3];
    unsigned int c;

    if (getloadavg(result, 3) == -1) {
        db_error("os::loadavg failed!");
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
        db_error("os::loadavg: invalid kind!");
        c = 0;
        break;
    }

    return result[c];
/* $end */
}

/* ::hyve::os::sleep(::hyve::lang::uint32 sec,::hyve::lang::uint32 nsec) */
db_void os_sleep(db_uint32 sec, db_uint32 nsec) {
/* $begin(::hyve::os::sleep) */

    db_sleep(sec, nsec);

/* $end */
}

/* ::hyve::os::system(::hyve::lang::string cmd) */
db_void os_system(db_string cmd) {
/* $begin(::hyve::os::system) */

    system(cmd);

/* $end */
}
