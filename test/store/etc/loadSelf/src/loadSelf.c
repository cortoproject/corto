/* This is a managed file. Do not delete this comment. */

#include <loadSelf/loadSelf.h>


/* Enter code outside of main here. */

int cortomain(int argc, char *argv[]) {

    /* Should abort */
    corto_load("loadSelf", 0, NULL);

    return -1;
}

