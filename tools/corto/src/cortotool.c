
#include "cortotool_build.h"
#include "cortotool_create.h"
#include "cortotool_help.h"
#include "cortotool_install.h"
#include "cortotool_package.h"
#include "cortotool_pp.h"
#include "cortotool_publish.h"
#include "cortotool_run.h"
#include "cortotool_shell.h"
#include "cortotool_test.h"

static void cortotool_printUsage(corto_bool expert) {
    printf("Usage: corto [-d] [--keep-alive] <command> [args]\n");
    printf("       corto [-d] [--keep-alive] [files] [loader]\n");
    printf("       corto [--version] [-v] [--help] [-h] [--expert]\n");
    printf("\n");
    printf("Without arguments, 'corto' starts the corto shell.\n");
    printf("\n");
    printf("Commands:\n");
    printf("   create               Create a new project.\n");
    printf("   add                  Add a package to a project\n");
    printf("   remove               Remove a package from a project\n");
    printf("   list                 List loader of a project\n");
    printf("   install              Install a package.\n");
    printf("   uninstall            Uninstall a package.\n");
    printf("   update               Update a package\n");
    printf("   run                  Run and build a project.\n");
    printf("   clean                Clean a project.\n");
    printf("   build                Build a project.\n");
    printf("   rebuild              Clean, then build a project.\n");
    printf("   test                 Run tests for a project\n");
    printf("   coverage             Print coverage report for project\n");
    printf("   shell                Start the corto shell.\n");
    printf("   locate               Show where a package is located.\n");
    printf("\n");
    if (expert) {
        printf("Expert commands:\n");
        printf("   pp                   Invoke the corto preprocessor.\n");
        printf("   tar                  Package a project in a redistributable tar file.\n");
        printf("   untar                Unpackage a project to the global environment.\n");
        printf("\n");
    }
    printf("See 'corto help <command>' for details on a command.\n\n");
}

int main(int argc, char* argv[]) {
    int i;
    corto_bool mute = FALSE;
    corto_bool startShell = FALSE;
    corto_bool keepAlive = FALSE;

    /* Parse debugging options before starting the core */
    for(i = 1; i < argc; i++) {
        if (*argv[i] == '-') {
            if (*(argv[i]+1) == 'h') {
                cortotool_printUsage(FALSE);
                break;
            } else if (*(argv[i]+1) == 'd') {
                fprintf(stderr, "corto: debugging enabled\n");
                CORTO_DEBUG_ENABLED = TRUE;
            } else if (*(argv[i]+1) == 'v') {
                printf("%s\n", CORTO_VERSION);
            } else if (*(argv[i]+1) == '-') {
                if (!strcmp(argv[i], "--debug")) {
                    fprintf(stderr, "corto: debugging enabled\n");
                    CORTO_DEBUG_ENABLED = TRUE;
                } else if (!strcmp(argv[i], "--trace-memory")) {
                    CORTO_TRACE_OBJECT = argv[i + 1];
                    i ++;
                } else if (!strcmp(argv[i], "--trace-events")) {
                    CORTO_TRACE_NOTIFICATIONS = 1;
                    i ++;
                } else if (!strcmp(argv[i], "--trace-stack")) {
                    CORTO_BACKTRACE_ENABLED = TRUE;
                }
            }
        }
    }

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
                if (*(argv[i]+1) == 'h') {
                    /* Already handled */
                    break;
                } else if (*(argv[i]+1) == 'v') {
                    /* Already handled */
                } else if (*(argv[i]+1) == 'd') {
                      /* Already handled */
                } else if (*(argv[i]+1) == 'p') {
                    if (corto_load(argv[i + 1], 0, NULL)) {
                        corto_error("%s: %s", argv[i + 1], corto_lasterr());
                        goto error;
                    }
                    i++;
                } else if (*(argv[i]+1) == '-') {
                    if (!strcmp(argv[i] + 2, "version")) {
                        printf("corto version %s (%s)\n  library: %s (%s)\n",
                            CORTO_VERSION,
                            CORTO_PLATFORM_STRING,
                            corto_getLibrary(),
                            corto_getBuild());
                    } else if (!strcmp(argv[i] + 2, "minor")) {
                        printf("%s.%s\n", CORTO_VERSION_MAJOR, CORTO_VERSION_MINOR);
                    } else if (!strcmp(argv[i] + 2, "help")) {
                        cortotool_printUsage(FALSE);
                    } else if (!strcmp(argv[i] + 2, "expert")) {
                        cortotool_printUsage(TRUE);
                    } else if (!strcmp(argv[i] + 2, "mute")) {
                        mute = TRUE;
                    } else if (!strcmp(argv[i], "--keep-alive")) {
                        keepAlive = TRUE;
                    } else if (!strcmp(argv[i], "--autoload")) {
                        corto_create(corto_loader_o);
                    } else if (!strcmp(argv[i] + 2, "trace-events")) {
                        /* Already handled */
                    } else if (!strcmp(argv[i] + 2, "trace-memory")) {
                        /* Already handled */
                        i++;
                    } else if (!strcmp(argv[i] + 2, "trace-stack")) {
                        /* Already handled */
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
            } else if (!strcmp(argv[i], "publish")) {
                if (cortotool_publish(argc-i, &argv[i])) {
                    goto error;
                }
                break;
            } else if (!strcmp(argv[i], "rakefile")) {
                if (cortotool_rakefile(argc-1, &argv[i])) {
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
            } else if (!strcmp(argv[i], "coverage")) {
                if (cortotool_coverage(argc-i, &argv[i])) {
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
            } else if (!strcmp(argv[i], "update")) {
                if (cortotool_update(argc-i, &argv[i])) {
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
                            corto_error("corto: %s: unknown command", argv[i]);
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

    if (keepAlive) {
        printf("corto: keeping process alive\n");
        while (TRUE) {
            corto_sleep(1, 0);
        }
    }

    /* Stop corto */
    corto_stop();
    return 0;
error:
    return -1;
}
