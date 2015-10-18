#include "corto_test.h"

cx_int16 corto_test(int argc, char *argv[]) {
    cx_string testCase = NULL;

    if (argc > 1) {
        if (cx_chdir(argv[1])) {
            cx_error("corto: can't change to directory '%s'", argv[1]);
            goto error;
        }
        if (argc > 2) {
            testCase = argv[2];
        }
    }

    if (cx_fileTest("test")) {
        cx_int8 ret = 0, sig = 0, err = 0;
    	cx_pid pid = cx_procrun("corto", (char*[]){"corto", "build", "test", NULL});
        if ((sig = cx_procwait(pid, &ret) || ret)) {
            if (sig > 0) {
                cx_error("corto: the tests failed to build (build crashed with signal %d)", sig);
            } else {
                cx_error("corto: the tests failed to build (build returned %d)", ret);                
            }
            err = 1;
        }

    	if (cx_fileTest("test/.corto/libtest.so")) {
            if (err) {
                cx_error("corto: trying to run previous testbuild, results may be outdated");
            }

            cx_chdir("test");
            cx_loadPackages();
            if (!testCase) {
                ret = cx_load("./.corto/libtest.so", 1, (char*[]){"./.corto/libtest.so", NULL});
            } else {
                ret = cx_load("./.corto/libtest.so", 2, (char*[]){"./.corto/libtest.so", testCase, NULL});
            }
		}
    }

    /* If a project doesn't have any tests, that counts as a PASS */

	return 0;
error:
    return -1;
}

void corto_testHelp(void) {
    printf("Usage: corto test\n");
    printf("       corto test <project>\n");
    printf("       corto test <project> <testcase>\n");
    printf("\n");
    printf("Test your Corto project. Returns -1 if tests fails.\n");
    printf("\n");
}
