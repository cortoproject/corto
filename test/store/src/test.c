/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

int testMain(int argc, char *argv[]) {
    int result = 0;
    test_Runner runner = test_RunnerCreate("store", argv[0], (argc > 1) ? argv[1] : NULL);
    if (!runner) return -1;
    if (corto_ll_size(runner->failures)) {
        result = -1;
    }

    corto_delete(runner);
    return result;
    return 0;
}

void test_functionToResolve(
    int32_t a,
    int32_t b)
{
    /* Insert implementation */
}

void test_ol_any__test_Color(
    test_Color a)
{
    /* Insert implementation */
}

void test_ol_any_bool(
    bool a)
{
    /* Insert implementation */
}

void test_ol_any_char(
    char a)
{
    /* Insert implementation */
}

void test_ol_any_float32(
    float a)
{
    /* Insert implementation */
}

void test_ol_any_int32(
    int32_t a)
{
    /* Insert implementation */
}

void test_ol_any_object(
    corto_object a)
{
    /* Insert implementation */
}

void test_ol_any_string(
    corto_string a)
{
    /* Insert implementation */
}

void test_ol_bool(
    bool a)
{
    /* Insert implementation */
}

void test_ol_inherit__test_Animal(
    test_Animal a)
{
    /* Insert implementation */
}

void test_ol_inherit__test_Dog(
    test_Dog a)
{
    /* Insert implementation */
}

void test_ol_int(
    int32_t a)
{
    /* Insert implementation */
}

void test_ol_null_bool(
    bool a)
{
    /* Insert implementation */
}

void test_ol_null_object(
    corto_object a)
{
    /* Insert implementation */
}

void test_ol_null_string(
    corto_string a)
{
    /* Insert implementation */
}

void test_ol_num_float64(
    double a)
{
    /* Insert implementation */
}

void test_ol_num_int32(
    int32_t a)
{
    /* Insert implementation */
}

void test_ol_object(
    corto_object a)
{
    /* Insert implementation */
}

void test_ol_string(
    corto_string a)
{
    /* Insert implementation */
}

void test_ol_uint(
    int32_t a)
{
    /* Insert implementation */
}

void test_ol_wildcard_float32_string(
    float a,
    corto_string b)
{
    /* Insert implementation */
}

void test_ol_wildcard_int32_string(
    int32_t a,
    corto_string b)
{
    /* Insert implementation */
}

