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
        cx_int8 ret = 0;
    	cx_pid pid = cx_procrun("corto", (char*[]){"corto", "build", "test", NULL});
        if (cx_procwait(pid, &ret) || ret) {
            cx_error("corto: the tests failed to build!");
            goto error;
        }

    	if (cx_fileTest("test/.corto/libtest.so")) {
            cx_int8 err = 0, ret = 0;
            cx_chdir("test");
            cx_pid pid;
            if (!testCase) {
    			pid = cx_procrun("corto", (char*[]){"corto", "--mute", "./.corto/libtest.so", NULL});
            } else {
                pid = cx_procrun("corto", (char*[]){"corto", "--mute", "./.corto/libtest.so", testCase, NULL});
            }
            if ((err = cx_procwait(pid, &ret))) {
                cx_error("corto: failed to run test (%s %d)", 
                    (err == -1) ? "returned" : "signal", 
                    (err == -1) ? ret : err);
                goto error;
            }
		}
    }

    /* If a project doesn't have any tests, that counts as a PASS */

	return 0;
error:
    return -1;
}
