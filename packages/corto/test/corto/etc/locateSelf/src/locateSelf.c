/* $CORTO_GENERATED
 *
 * locateSelf.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <locateSelf/locateSelf.h>

/* $header() */
/* Enter code outside of main here. */
/* $end */

int locateSelfMain(int argc, char *argv[]) {
/* $begin(main) */

    corto_string str = corto_locate("locateSelf", NULL, CORTO_LOCATION_LIB);
    if (!str) {
        goto error;
    }

    return 0;
error:
    return -1;
/* $end */
}
