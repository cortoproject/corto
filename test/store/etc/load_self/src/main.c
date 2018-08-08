/* This is a managed file. Do not delete this comment. */

#include <load_self/load_self.h>


/* Enter code outside of main here. */

int cortomain(int argc, char *argv[]) {

    int ret = corto_use("load_self", 0, NULL);;
    return ret;
}
