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

/* ::test::ol_int(int32 a) */
cx_void _test_ol_int(cx_int32 a) {
/* $begin(::test::ol_int) */

    /* << Insert implementation >> */

/* $end */
}

/* ::test::ol_null(bool a) */
cx_void _test_ol_null_bool(cx_bool a) {
/* $begin(::test::ol_null(bool a)) */

    /* << Insert implementation >> */

/* $end */
}

/* ::test::ol_null(object a) */
cx_void _test_ol_null_object(cx_object a) {
/* $begin(::test::ol_null(object a)) */

    /* << Insert implementation >> */

/* $end */
}

/* ::test::ol_null(string a) */
cx_void _test_ol_null_string(cx_string a) {
/* $begin(::test::ol_null(string a)) */

    /* << Insert implementation >> */

/* $end */
}

/* ::test::ol_num(float64 a) */
cx_void _test_ol_num_float64(cx_float64 a) {
/* $begin(::test::ol_num(float64 a)) */

    /* << Insert implementation >> */

/* $end */
}

/* ::test::ol_num(int32 a) */
cx_void _test_ol_num_int32(cx_int32 a) {
/* $begin(::test::ol_num(int32 a)) */

    /* << Insert implementation >> */

/* $end */
}

/* ::test::ol_uint(int32 a) */
cx_void _test_ol_uint(cx_int32 a) {
/* $begin(::test::ol_uint) */

    /* << Insert implementation >> */

/* $end */
}

/* ::test::ol_wildcard(float32 a,string b) */
cx_void _test_ol_wildcard_float32_string(cx_float32 a, cx_string b) {
/* $begin(::test::ol_wildcard(float32 a,string b)) */

    /* << Insert implementation >> */

/* $end */
}

/* ::test::ol_wildcard(int32 a,string b) */
cx_void _test_ol_wildcard_int32_string(cx_int32 a, cx_string b) {
/* $begin(::test::ol_wildcard(int32 a,string b)) */

    /* << Insert implementation >> */

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
