#include "corto_test.h"

cx_int16 corto_test(int argc, char *argv[]) {
    if (argc > 1) {
        cx_chdir(argv[1]);
    }

    if (cx_fileTest("test")) {
    	cx_pid pid = cx_procrun("corto", (char*[]){"corto", "build", "test", NULL});
        if (cx_procwait(pid, NULL)) {
            cx_error("corto: failed to build test");
            goto error;
        }
    	if (cx_fileTest("test/.corto/libtest.so")) {
            cx_chdir("test");
			cx_pid pid = cx_procrun("corto", (char*[]){"corto", "./.corto/libtest.so", NULL});
            if (cx_procwait(pid, NULL)) {
                cx_error("corto: failed to run test");
                goto error;
            }
		}
    }

    /* If a project doesn't have any tests, that counts as a PASS */

	return 0;
error:
    return -1;
}
