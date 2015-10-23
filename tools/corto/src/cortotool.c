
#include "corto.h"
#include "cortotool_build.h"
#include "cortotool_help.h"
#include "cortotool_install.h"
#include "cortotool_package.h"
#include "cortotool_pp.h"
#include "cortotool_create.h"
#include "cortotool_run.h"
#include "cortotool_shell.h"
#include "cortotool_test.h"
#include "corto_loader.h"

void cortotool_locateHelp(void) {
    printf("Usage: corto locate <package>\n");
    printf("\n");
    printf("Find out where a package is located. This can be useful if you're\n");
    printf("unsure whether you're using a package from the local or global\n");
    printf("environment.\n");
    printf("\n");
}

static void cortotool_printUsage(corto_bool expert) {
    printf("Usage: corto [-d] <command> [args]\n");
    printf("       corto [-d] [files] [packages]\n");
    printf("       corto [--version] [-v] [--help] [-h] [--expert]\n");
    printf("\n");
    printf("Without arguments, 'corto' starts the corto shell.\n");
    printf("\n");
    printf("Commands:\n");
    printf("   create               Create a new project.\n");
    printf("   add                  Add a package to a project\n");
    printf("   remove               Remove a package from a project\n");
    printf("   list                 List packages of a project\n");
    printf("   run                  Run a project.\n");
    printf("   build                Build a project (not needed for apps!).\n");
    printf("   test                 Run tests for a project\n");
    printf("   shell                Start the corto shell.\n");
    printf("\n");
    if (expert) {
        printf("Expert commands:\n");
        printf("   pp                   Invoke the corto preprocessor.\n");
        printf("   locate               Show where a package or component is located.\n");
        printf("   install              Install a project to the global environment.\n");
        printf("   uninstall            Remove a project from the global environment.\n");
        printf("   tar                  Package a project in a redistributable tar file.\n");
        printf("   untar                Unpackage a project to the global environment.\n");
        printf("   rebuild              Clean, then build a project.\n");
        printf("   clean                Clean a project.\n");
        printf("\n");
    }
    printf("See 'corto help <command>' for details on a commnad.\n\n");
}

int main(int argc, char* argv[]) {
    int i;
    corto_bool mute = FALSE;
    corto_bool startShell = FALSE;

    /* Start corto */
    corto_start();

    /* Parse arguments */
    if (argc == 1) {
        if (cortotool_shell(argc, argv)) {
            goto error;
        }
    } else {
        for(i=1; i<argc; i++) {
            if (*argv[i] == '-') {
                if (*(argv[i]+1) == 'd') {
                    CORTO_DEBUG_ENABLED = TRUE;
                }else if (*(argv[i]+1) == 'h') {
                    cortotool_printUsage(FALSE);
                    break;
                } else if (*(argv[i]+1) == 'v') {
                    printf("%s", CORTO_VERSION);
                } else if (*(argv[i]+1) == 'c') {
                    if (corto_loadComponent(argv[i + 1], 0, NULL)) {
                        corto_error("%s: %s", argv[i + 1], corto_lasterr());
                        goto error;
                    }
                    i++;
                } else if (*(argv[i]+1) == 'p') {
                    if (corto_load(argv[i + 1], 0, NULL)) {
                        corto_error("%s: %s", argv[i + 1], corto_lasterr());
                        goto error;
                    }
                    i++;
                } else if (*(argv[i]+1) == '-') {
                    if (!strcmp(argv[i] + 2, "version")) {
                        corto_error("corto (%s) %s\n\n", CORTO_PLATFORM_STRING, CORTO_VERSION);
                    } else if (!strcmp(argv[i] + 2, "help")) {
                        cortotool_printUsage(FALSE);
                    } else if (!strcmp(argv[i] + 2, "expert")) {
                        cortotool_printUsage(TRUE);
                    } else if (!strcmp(argv[i] + 2, "mute")) {
                        mute = TRUE;
                    } else {
                        corto_error("corto: unknown option '%s'", argv[i] + 2);
                        cortotool_printUsage(FALSE);
                        goto error;
                    }
                } else {
                    corto_error("corto: unknown option '%s'", argv[i] + 1);
                    cortotool_printUsage(FALSE);
                    goto error;
                }
            } else if (!strcmp(argv[i], "create")) {
                if (cortotool_create(argc-i, &argv[i])) {
                    goto error;
                }
                break;
            } else if (!strcmp(argv[i], "add")) {
                if (cortotool_add(argc-i, &argv[i])) {
                    goto error;
                }
                break;
            } else if (!strcmp(argv[i], "remove")) {
                if (cortotool_remove(argc-i, &argv[i])) {
                    goto error;
                }
                break;
            } else if (!strcmp(argv[i], "list")) {
                if (cortotool_list(argc-i, &argv[i])) {
                    goto error;
                }
                break;
            } else if (!strcmp(argv[i], "pp")) {
                if (cortotool_pp(argc-i, &argv[i])) {
                    goto error;
                }
                break;
            } else if (!strcmp(argv[i], "build")) {
                if (cortotool_build(argc-i, &argv[i])) {
                    goto error;
                }
                break;
            } else if (!strcmp(argv[i], "rebuild")) {
                if (cortotool_rebuild(argc-i, &argv[i])) {
                    goto error;
                }
                break;
            } else if (!strcmp(argv[i], "test")) {
                if (cortotool_test(argc-i, &argv[i])) {
                    goto error;
                }
                break;
            } else if (!strcmp(argv[i], "clean")) {
                if (cortotool_clean(argc-i, &argv[i])) {
                    goto error;
                }
                break;
            } else if (!strcmp(argv[i], "install")) {
                if (cortotool_install(argc-i, &argv[i])) {
                    goto error;
                }
                break;
            } else if (!strcmp(argv[i], "uninstall")) {
                if (cortotool_uninstall(argc-i, &argv[i])) {
                    goto error;
                }
                break;  
            } else if (!strcmp(argv[i], "locate")) {
                if (cortotool_locate(argc-i, &argv[i])) {
                    goto error;
                }
                break;                
            } else if (!strcmp(argv[i], "run")) {
                if (cortotool_run(argc-i, &argv[i])) {
                    goto error;
                }
                break;
            } else if (!strcmp(argv[i], "debug")) {
                if (cortotool_debug(argc-i, &argv[i])) {
                    goto error;
                }
                break;
            } else if (!strcmp(argv[i], "shell")) {
                startShell = TRUE;
            } else if (!strcmp(argv[1], "tar")) {
                if (cortotool_tar(argc-i, &argv[i])) {
                    goto error;
                }
                break;
            } else if (!strcmp(argv[1], "untar")) {
                if (cortotool_untar(argc-i, &argv[i])) {
                    goto error;
                }
                break;
            } else if (!strcmp(argv[1], "help")) {
                if (cortotool_help(argc-i, &argv[i])) {
                    goto error;
                }
                break;
            } else {
                if (corto_load(argv[i], argc-i, &argv[i])) {
                    if (!mute) {
                        if (corto_lasterr()) {
                            corto_error("corto: %s: %s", argv[i], corto_lasterr());
                        } else {
                            corto_error("corto: %s: input error", argv[i]);
                        }
                    }
                    goto error;
                }
                break;
            }
        }
    }

    if (startShell) {
        if (cortotool_shell(argc-i, &argv[i])) {
            goto error;
        }
    }

    /* Stop corto */
    corto_stop();
    return 0;
error:
    return -1;
}
