#include "cortotool_test.h"
#include "cortotool_build.h"
#include "corto/argparse/argparse.h"

#define GREEN   "\033[1;32m"
#define NORMAL  "\033[0;49m"

corto_int16 cortotool_test(int argc, char *argv[]) {
    corto_string projectArg = NULL;
    corto_int8 ret, sig, err = 0;
    corto_ll verbose, project, build, rebuild, clean, tool;

    CORTO_UNUSED(argc);

    if (cortotool_rakefile(argc, argv)) {
        goto error;
    }

    corto_argdata *data = corto_argparse(
      argv,
      (corto_argdata[]){
        {"$0", NULL, NULL}, /* Ignore 'test' */
        {"--verbose", &verbose, NULL},
        {"--build", &build, NULL},
        {"--rebuild", &rebuild, NULL},
        {"--clean", &clean, NULL},
        {"--tool", NULL, &tool},
        {"*", &project, NULL},
        {NULL}
      }
    );

    if (project) {
        projectArg = corto_llGet(project, 0);
    }

    if (tool) {
        char *toolstr = corto_llGet(tool, 0);
        setenv("CORTO_TEST_TOOL", toolstr, TRUE);
        setenv("CI", "TRUE", TRUE);
    }

    corto_int32 i = 0;
    do {
        if (projectArg) {
            if (corto_chdir(projectArg)) {
                corto_error("corto: can't change to directory '%s'", projectArg);
                goto error;
            }
        }

        corto_pid pid = corto_procrun("rake", (char*[]){
          "rake",
          "test",
          verbose ? "verbose=true" : "verbose=false",
          build ? "build=true" : "build=false",
          rebuild ? "rebuild=true" : "rebuild=false",
          clean ? "clean=true" : "clean=false",
          "silent=true",
          NULL});
        if ((sig = corto_procwait(pid, &ret) || ret)) {
            if ((sig > 0) && !(build || rebuild || clean)) {
                corto_error("Aww, tests failed.");
            }
            err = 1;
        }

        if (err) {
            goto error;
        } else if (!(build || rebuild || clean)) {
            printf("%sYay, all green :-)%s\n", GREEN, NORMAL);
        }

        i ++;
    } while (project && (projectArg = corto_llGet(project, i)));

    corto_argclean(data);

    return 0;
error:
    return -1;
}

void cortotool_testHelp(void) {
    printf("Usage: corto test\n");
    printf("       corto test <project>\n");
    printf("\n");
    printf("Options:\n");
    printf("   --build        Just build tests, do not run test.\n");
    printf("   --rebuild      Just rebuild tests, do not run tests. Same as combining --build and --clean\n");
    printf("   --clean        Just clean tests, do not run tests.\n");
    printf("   --verbose      Verbose output. Sets CORTO_VERBOSITY to 'TRACE'\n");
    printf("\n");
    printf("Test your Corto project. Returns -1 if tests fails.\n");
    printf("\n");
}
