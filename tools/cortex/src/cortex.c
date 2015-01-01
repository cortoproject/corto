/*
 * cortex.c
 *
 *  Created on: Sep 17, 2012
 *      Author: sander
 */

#include "cortex.h"
#include "cx_loader.h"

extern cx_bool CX_DEBUG_ENABLED;

int main(int argc, char* argv[]) {
    int i;
    cx_id filename;

    /* Start database */
    cx_start();

    /* Pre-load cortex-ast parser */
    if (cx_load("fast")) {
        cx_error("failed to load parser package");
        goto error;
    }

    /* Parse arguments */
    for(i=1; i<argc; i++) {
        if (*argv[i] == '-') {
            if (*(argv[i]+1) == 'd') {
                CX_DEBUG_ENABLED = TRUE;
            }
        } else
        if (!strstr(argv[i], ".cx")) {
            sprintf(filename, "%s.cx", argv[i]);
            if (cx_load(filename)) {
                cx_error("failed to load file '%s'", argv[i]);
                goto error;
            }
        } else {
            if (cx_load(argv[i])) {
                cx_error("failed to load file '%s'", argv[i]);
                goto error;
            }
        }
    }

    /* Stop database */
    cx_stop();

    return 0;
error:
    return -1;
}
