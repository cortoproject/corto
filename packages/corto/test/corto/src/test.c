/* $CORTO_GENERATED
 *
 * test.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include <include/test.h>

corto_void _test_functionToResolve(
    int32_t a,
    int32_t b)
{
/* $begin(test/functionToResolve) */

    /* << Insert implementation >> */

/* $end */
}

corto_void _test_ol_any__test_Color(
    test_Color a)
{
/* $begin(test/ol_any(/test/Color a)) */

    /* << Insert implementation >> */

/* $end */
}

corto_void _test_ol_any_bool(
    bool a)
{
/* $begin(test/ol_any(bool a)) */

    /* << Insert implementation >> */

/* $end */
}

corto_void _test_ol_any_char(
    char a)
{
/* $begin(test/ol_any(char a)) */

    /* << Insert implementation >> */

/* $end */
}

corto_void _test_ol_any_float32(
    float a)
{
/* $begin(test/ol_any(float32 a)) */

    /* << Insert implementation >> */

/* $end */
}

corto_void _test_ol_any_int32(
    int32_t a)
{
/* $begin(test/ol_any(int32 a)) */

    /* << Insert implementation >> */

/* $end */
}

corto_void _test_ol_any_object(
    corto_object a)
{
/* $begin(test/ol_any(object a)) */

    /* << Insert implementation >> */

/* $end */
}

corto_void _test_ol_any_string(
    corto_string a)
{
/* $begin(test/ol_any(string a)) */

    /* << Insert implementation >> */

/* $end */
}

corto_void _test_ol_bool(
    bool a)
{
/* $begin(test/ol_bool) */

    /* << Insert implementation >> */

/* $end */
}

corto_void _test_ol_inherit__test_Animal(
    test_Animal a)
{
/* $begin(test/ol_inherit(/test/Animal a)) */

    /* << Insert implementation >> */

/* $end */
}

corto_void _test_ol_inherit__test_Dog(
    test_Dog a)
{
/* $begin(test/ol_inherit(/test/Dog a)) */

    /* << Insert implementation >> */

/* $end */
}

corto_void _test_ol_int(
    int32_t a)
{
/* $begin(test/ol_int) */

    /* << Insert implementation >> */

/* $end */
}

corto_void _test_ol_null_bool(
    bool a)
{
/* $begin(test/ol_null(bool a)) */

    /* << Insert implementation >> */

/* $end */
}

corto_void _test_ol_null_object(
    corto_object a)
{
/* $begin(test/ol_null(object a)) */

    /* << Insert implementation >> */

/* $end */
}

corto_void _test_ol_null_string(
    corto_string a)
{
/* $begin(test/ol_null(string a)) */

    /* << Insert implementation >> */

/* $end */
}

corto_void _test_ol_num_float64(
    double a)
{
/* $begin(test/ol_num(float64 a)) */

    /* << Insert implementation >> */

/* $end */
}

corto_void _test_ol_num_int32(
    int32_t a)
{
/* $begin(test/ol_num(int32 a)) */

    /* << Insert implementation >> */

/* $end */
}

corto_void _test_ol_object(
    corto_object a)
{
/* $begin(test/ol_object) */

    /* << Insert implementation >> */

/* $end */
}

corto_void _test_ol_string(
    corto_string a)
{
/* $begin(test/ol_string) */

    /* << Insert implementation >> */

/* $end */
}

corto_void _test_ol_uint(
    int32_t a)
{
/* $begin(test/ol_uint) */

    /* << Insert implementation >> */

/* $end */
}

corto_void _test_ol_wildcard_float32_string(
    float a,
    corto_string b)
{
/* $begin(test/ol_wildcard(float32 a,string b)) */

    /* << Insert implementation >> */

/* $end */
}

corto_void _test_ol_wildcard_int32_string(
    int32_t a,
    corto_string b)
{
/* $begin(test/ol_wildcard(int32 a,string b)) */

    /* << Insert implementation >> */

/* $end */
}

int testMain(int argc, char *argv[]) {
/* $begin(main) */
    int result = 0;
    test_Runner runner = test_RunnerCreate("corto", argv[0], (argc > 1) ? argv[1] : NULL);
    if (!runner) return -1;
    if (corto_llSize(runner->failures)) {
        result = -1;
    }
    corto_delete(runner);
    return result;
    return 0;
/* $end */
}
