/* $CORTO_GENERATED
 *
 * createSelfPackage.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <createSelfPackage/createSelfPackage.h>

/* $header() */
/* Enter code outside of main here. */
/* $end */

int createSelfPackageMain(int argc, char *argv[]) {
/* $begin(main) */

    corto_object o = corto_createChild(root_o, "createSelfPackage", corto_package_o);
    if (!o) {
        goto error;
    }

    return 0;
error:
    return -1;
/* $end */
}
