
#include "corto.h"
#include "corto_build.h"
#include "corto_help.h"
#include "corto_install.h"
#include "corto_package.h"
#include "corto_pp.h"
#include "corto_project.h"
#include "corto_run.h"
#include "corto_shell.h"
#include "cx_loader.h"

void corto_locateHelp(void) {
    printf("Usage: corto locate <package>\n");
    printf("\n");
    printf("Find out where a package is located. This can be useful if you're\n");
    printf("unsure whether you're using a package from the local or global\n");
    printf("environment.\n");
    printf("\n");
}

static void corto_printUsage(void) {
    printf("Usage: corto [-d] <command> [args]\n");
    printf("       corto [-d] [files] [packages]\n");
    printf("       corto [--version] [-v] [--help] [-h]\n");
    printf("\n");
    printf("Without arguments, 'corto' starts the corto shell.\n");
    printf("\n");
    printf("Commands:\n");
    printf("   create               Create a new project.\n");
    printf("   run                  Run a project.\n");
    printf("   add                  Add a package to the project\n");
    printf("   remove               Remove a package from the project\n");
    printf("   list                 List the packages of the project\n");
    printf("   install              Install a project to the global environment.\n");
    printf("   uninstall            Remove a project from the global environment.\n");
    printf("   locate               Show whether a package is located in the local or global environment\n");
    printf("   shell                Start the corto shell.\n");
    printf("   tar                  Package a project in a redistributable tar file.\n");
    printf("   untar                Unpackage a project to the global environment.\n");
    printf("   build                Build a project.\n");
    printf("\n");
    printf("See 'corto help <command>' for details on a commnad.\n\n");
}

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
                }else if (*(argv[i]+1) == 'h') {
                    corto_printUsage();
                    break;
                } else if (*(argv[i]+1) == 'v') {
                    printf("%s", CORTO_VERSION);
                } else if (*(argv[i]+1) == '-') {
                    if (!strcmp(argv[i] + 2, "version")) {
                        cx_error("corto (%s) %s\n\n", CX_PLATFORM_STRING, CORTO_VERSION);
                    } else if (!strcmp(argv[i] + 2, "help")) {
                        corto_printUsage();
                    } else {
                        cx_error("corto: unknown option '%s'", argv[i] + 2);
                        corto_printUsage();
                        goto error;
                    }
                } else {
                    printf("corto: unknown option '%s'", argv[i] + 1);
                    corto_printUsage();
                    goto error;
                }
            } else if (!strcmp(argv[i], "create")) {
                if (corto_project(argc-i, &argv[i])) {
                    goto error;
                }
                break;
            } else if (!strcmp(argv[i], "add")) {
                if (corto_add(argc-i, &argv[i])) {
                    goto error;
                }
                break;
            } else if (!strcmp(argv[i], "remove")) {
                if (corto_remove(argc-i, &argv[i])) {
                    goto error;
                }
                break;
            } else if (!strcmp(argv[i], "list")) {
                if (corto_list(argc-i, &argv[i])) {
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
            } else if (!strcmp(argv[i], "rebuild")) {
                if (corto_rebuild(argc-i, &argv[i])) {
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
            } else if (!strcmp(argv[1], "help")) {
                if (corto_help(argc-i, &argv[i])) {
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
    return -1;
}
