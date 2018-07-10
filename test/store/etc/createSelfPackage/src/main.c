/* This is a managed file. Do not delete this comment. */

#include <createSelfPackage/createSelfPackage.h>


/* Enter code outside of main here. */

int cortomain(int argc, char *argv[]) {

    corto_object o = corto_create(root_o, "createSelfPackage", corto_package_o);
    if (!o) {
        goto error;
    }

    return 0;
error:
    return -1;
}

