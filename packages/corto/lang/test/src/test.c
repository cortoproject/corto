/* $CORTO_GENERATED
 *
 * test.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "test.h"

corto/void _test/functionToResolve(corto/int32 a, corto/int32 b) {
/* $begin(/test/functionToResolve) */

    /* Dummy function */

/* $end */
}

corto/void _test/ol_any_/test/Color(test/Color a) {
/* $begin(/test/ol_any(/test/Color a)) */

    /* << Insert implementation >> */

/* $end */
}

corto/void _test/ol_any_bool(corto/bool a) {
/* $begin(/test/ol_any(bool a)) */

    /* << Insert implementation >> */

/* $end */
}

corto/void _test/ol_any_char(corto/char a) {
/* $begin(/test/ol_any(char a)) */

    /* << Insert implementation >> */

/* $end */
}

corto/void _test/ol_any_float32(corto/float32 a) {
/* $begin(/test/ol_any(float32 a)) */

    /* << Insert implementation >> */

/* $end */
}

corto/void _test/ol_any_int32(corto/int32 a) {
/* $begin(/test/ol_any(int32 a)) */

    /* << Insert implementation >> */

/* $end */
}

corto/void _test/ol_any_object(corto/object a) {
/* $begin(/test/ol_any(object a)) */

    /* << Insert implementation >> */

/* $end */
}

corto/void _test/ol_any_string(corto/string a) {
/* $begin(/test/ol_any(string a)) */

    /* << Insert implementation >> */

/* $end */
}

corto/void _test/ol_bool(corto/bool a) {
/* $begin(/test/ol_bool) */

    /* << Insert implementation >> */

/* $end */
}

corto/void _test/ol_inherit_/test/Animal(test/Animal a) {
/* $begin(/test/ol_inherit(/test/Animal a)) */

    /* << Insert implementation >> */

/* $end */
}

corto/void _test/ol_inherit_/test/Dog(test/Dog a) {
/* $begin(/test/ol_inherit(/test/Dog a)) */

    /* << Insert implementation >> */

/* $end */
}

corto/void _test/ol_int(corto/int32 a) {
/* $begin(/test/ol_int) */

    /* << Insert implementation >> */

/* $end */
}

corto/void _test/ol_null_bool(corto/bool a) {
/* $begin(/test/ol_null(bool a)) */

    /* << Insert implementation >> */

/* $end */
}

corto/void _test/ol_null_object(corto/object a) {
/* $begin(/test/ol_null(object a)) */

    /* << Insert implementation >> */

/* $end */
}

corto/void _test/ol_null_string(corto/string a) {
/* $begin(/test/ol_null(string a)) */

    /* << Insert implementation >> */

/* $end */
}

corto/void _test/ol_num_float64(corto/float64 a) {
/* $begin(/test/ol_num(float64 a)) */

    /* << Insert implementation >> */

/* $end */
}

corto/void _test/ol_num_int32(corto/int32 a) {
/* $begin(/test/ol_num(int32 a)) */

    /* << Insert implementation >> */

/* $end */
}

corto/void _test/ol_object(corto/object a) {
/* $begin(/test/ol_object) */

    /* << Insert implementation >> */

/* $end */
}

corto/void _test/ol_string(corto/string a) {
/* $begin(/test/ol_string) */

    /* << Insert implementation >> */

/* $end */
}

corto/void _test/ol_uint(corto/int32 a) {
/* $begin(/test/ol_uint) */

    /* << Insert implementation >> */

/* $end */
}

corto/void _test/ol_wildcard_float32_string(corto/float32 a, corto/string b) {
/* $begin(/test/ol_wildcard(float32 a,string b)) */

    /* << Insert implementation >> */

/* $end */
}

corto/void _test/ol_wildcard_int32_string(corto/int32 a, corto/string b) {
/* $begin(/test/ol_wildcard(int32 a,string b)) */

    /* << Insert implementation >> */

/* $end */
}

int testMain(int argc, char* argv[]) {
/* $begin(main) */
    int result = 0;
    test_Runner runner = test_RunnerCreate("core", argv[0], (argc > 1) ? argv[1] : NULL);
    if (!runner) return -1;
    if (corto_llSize(runner->failures)) {
        result = -1;
    }
    corto_delete(runner);
    return result;
/* $end */
}
