
#include "cortex.h"
#include "cx_loader.h"

extern cx_bool CX_DEBUG_ENABLED;

int main(int argc, char* argv[]) {
    int i;

    /* Start database */
    cx_start();

    /* Parse arguments */
    for(i=1; i<argc; i++) {
        if (*argv[i] == '-') {
            if (*(argv[i]+1) == 'd') {
                CX_DEBUG_ENABLED = TRUE;
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
