
#include "corto.h"
#include "corto_project.h"
#include "corto_build.h"
#include "corto_install.h"
#include "corto_pp.h"
#include "corto_run.h"
#include "corto_shell.h"
#include "cx_loader.h"

int main(int argc, char* argv[]) {
    int i;

    /* Start corto */
    cx_start();

    /* Parse arguments */
    if (argc == 1) {
        if (corto_shell(argc, argv)) {
            goto error;
        }
    } else {
        for(i=1; i<argc; i++) {
            if (*argv[i] == '-') {
                if (*(argv[i]+1) == 'd') {
                    CX_DEBUG_ENABLED = TRUE;
                } else if (*(argv[i]+1) == 'v') {
                    printf("%s", CORTO_VERSION);
                } else if (*(argv[i]+1) == '-') {
                    if (!strcmp(argv[i] + 2, "version")) {
                        printf("corto (%s) %s\n\n", CX_PLATFORM_STRING, CORTO_VERSION);
                    }
                }
            } else if (!strcmp(argv[i], "create")) {
                if (corto_project(argc-i, &argv[i])) {
                    goto error;
                }
                break;
            } else if (!strcmp(argv[i], "pp")) {
                if (corto_pp(argc-i, &argv[i])) {
                    goto error;
                }
                break;
            } else if (!strcmp(argv[i], "build")) {
                if (corto_build(argc-i, &argv[i])) {
                    goto error;
                }
                break;
            } else if (!strcmp(argv[i], "install")) {
                if (corto_install(argc-i, &argv[i])) {
                    goto error;
                }
                break;
            } else if (!strcmp(argv[i], "uninstall")) {
                if (corto_uninstall(argc-i, &argv[i])) {
                    goto error;
                }
                break;  
            } else if (!strcmp(argv[i], "locate")) {
                if (corto_locate(argc-i, &argv[i])) {
                    goto error;
                }
                break;                
            } else if (!strcmp(argv[i], "run")) {
                if (corto_run(argc-i, &argv[i])) {
                    goto error;
                }
                break;
            } else if (!strcmp(argv[i], "shell")) {
                if (corto_shell(argc-i, &argv[i])) {
                    goto error;
                }
                break;
            } else if (!strcmp(argv[1], "tar")) {
                if (corto_tar(argc-i, &argv[i])) {
                    goto error;
                }
                break;
            } else if (!strcmp(argv[1], "untar")) {
                if (corto_untar(argc-i, &argv[i])) {
                    goto error;
                }
                break;
            } else {
                if (cx_load(argv[i])) {
                    cx_error("corto: failed to load file '%s'", argv[i]);
                    goto error;
                }
            }
        }
    }

    /* Stop corto */
    cx_stop();

    return 0;
error:
    cx_stop();
    return -1;
}
