#include "corto_test.h"

cx_int16 corto_test(int argc, char *argv[]) {
    if (argc > 1) {
        cx_chdir(argv[1]);
    }

    if (cx_fileTest("test")) {
    	system("corto build test");
    	if (cx_fileTest("test/.corto/libtest.so")) {
			system ("corto test/.corto/libtest.so");
		}
    }

    /* If a project doesn't have any tests, that counts as a PASS */

	return 0;
error:
	return -1;
}
