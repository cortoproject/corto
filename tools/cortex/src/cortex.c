
#include "cortex.h"
#include "cortex_project.h"
#include "cortex_build.h"
#include "cortex_install.h"
#include "cortex_pp.h"
#include "cortex_run.h"
#include "cortex_shell.h"
#include "cx_loader.h"

extern cx_bool CX_DEBUG_ENABLED;

int main(int argc, char* argv[]) {
    int i;

    /* Start cortex */
    cx_start();

    /* Parse arguments */
    if (argc == 1) {
        if (cortex_shell(argc, argv)) {
            goto error;
        }
    } else {
        for(i=1; i<argc; i++) {
            if (*argv[i] == '-') {
                if (*(argv[i]+1) == 'd') {
                    CX_DEBUG_ENABLED = TRUE;
                } else if (*(argv[i]+1) == 'v') {
                    printf("%s", CORTEX_VERSION);
                } else if (*(argv[i]+1) == '-') {
                    if (!strcmp(argv[i] + 2, "version")) {
                        printf("cortex (%s) %s\n\n", CX_PLATFORM_STRING, CORTEX_VERSION);
                    }
                }
            } else if (!strcmp(argv[i], "create")) {
                if (cortex_project(argc-i, &argv[i])) {
                    goto error;
                }
                break;
            } else if (!strcmp(argv[i], "pp")) {
                if (cortex_pp(argc-i, &argv[i])) {
                    goto error;
                }
                break;
            } else if (!strcmp(argv[i], "build")) {
                if (cortex_build(argc-i, &argv[i])) {
                    goto error;
                }
                break;
            } else if (!strcmp(argv[i], "install")) {
                if (cortex_install(argc-i, &argv[i])) {
                    goto error;
                }
                break;
            } else if (!strcmp(argv[i], "uninstall")) {
                if (cortex_uninstall(argc-i, &argv[i])) {
                    goto error;
                }
                break;  
            } else if (!strcmp(argv[i], "locate")) {
                if (cortex_locate(argc-i, &argv[i])) {
                    goto error;
                }
                break;                
            } else if (!strcmp(argv[i], "run")) {
                if (cortex_run(argc-i, &argv[i])) {
                    goto error;
                }
                break;
            } else if (!strcmp(argv[i], "shell")) {
                if (cortex_shell(argc-i, &argv[i])) {
                    goto error;
                }
                break;
            } else if (!strcmp(argv[1], "tar")) {
                if (cortex_tar(argc-i, &argv[i])) {
                    goto error;
                }
                break;
            } else if (!strcmp(argv[1], "untar")) {
                if (cortex_untar(argc-i, &argv[i])) {
                    goto error;
                }
                break;
            } else {
                if (cx_load(argv[i])) {
                    cx_error("cortex: failed to load file '%s'", argv[i]);
                    goto error;
                }
            }
        }
    }

    /* Stop cortex */
    cx_stop();

    return 0;
error:
    cx_stop();
    return -1;
}
