#include "cortotool_test.h"

corto_int16 cortotool_test(int argc, char *argv[]) {
    corto_string testCase = NULL;

    if (argc > 1) {
        if (corto_chdir(argv[1])) {
            corto_error("corto: can't change to directory '%s'", argv[1]);
            goto error;
        }
        if (argc > 2) {
            testCase = argv[2];
        }
    }

    if (corto_fileTest("test")) {
        corto_int8 ret = 0, sig = 0, err = 0;
    	corto_pid pid = corto_procrun("corto", (char*[]){"corto", "build", "test", NULL});
        if ((sig = corto_procwait(pid, &ret) || ret)) {
            if (sig > 0) {
                corto_error("corto: the tests failed to build (build crashed with signal %d)", sig);
            } else {
                corto_error("corto: the tests failed to build (build returned %d)", ret);                
            }
            err = 1;
        }

    	if (corto_fileTest("test/.corto/libtest.so")) {
            if (err) {
                corto_error("corto: trying to run previous testbuild, results may be outdated");
            }

            corto_chdir("test");
            corto_loadPackages();
            if (!testCase) {
                ret = corto_load("./.corto/libtest.so", 1, (char*[]){"./.corto/libtest.so", NULL});
            } else {
                ret = corto_load("./.corto/libtest.so", 2, (char*[]){"./.corto/libtest.so", testCase, NULL});
            }
		}
    }

    /* If a project doesn't have any tests, that counts as a PASS */

	return 0;
error:
    return -1;
}

void cortotool_testHelp(void) {
    printf("Usage: corto test\n");
    printf("       corto test <project>\n");
    printf("       corto test <project> <testcase>\n");
    printf("\n");
    printf("Test your Corto project. Returns -1 if tests fails.\n");
    printf("\n");
}
