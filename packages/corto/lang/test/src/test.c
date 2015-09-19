/* test.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#define test_LIB
#include "test.h"

/* ::test::functionToResolve(int32 a,int32 b) */
cx_void _test_functionToResolve(cx_int32 a, cx_int32 b) {
/* $begin(::test::functionToResolve) */

    /* Dummy function */

/* $end */
}

int testMain(int argc, char* argv[]) {
/* $begin(main) */
    int result = 0;
    test_Runner runner = test_RunnerCreate("core", argv[0], (argc > 1) ? argv[1] : NULL);
    if (!runner) return -1;
    if (cx_llSize(runner->failures)) {
        result = -1;
    }
    cx_delete(runner);
    return result;
/* $end */
}
