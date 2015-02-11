/* test__wrapper.c
 *
 * This file contains wrapper functions for ::cortex::test.
 */

#include "test.h"
#include "test__meta.h"

void __test_suite_assert_any_any_string(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(result);
    test_suite_assert_any_any_string(
        *(void**)args,
        *(cx_any*)((intptr_t)args + sizeof(void*)),
        *(cx_any*)((intptr_t)args + sizeof(void*) + sizeof(cx_any)),
        *(cx_string*)((intptr_t)args + sizeof(void*) + sizeof(cx_any) + sizeof(cx_any)));
}

void __test_suite_assert_bool_string(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(result);
    test_suite_assert_bool_string(
        *(void**)args,
        *(cx_bool*)((intptr_t)args + sizeof(void*)),
        *(cx_string*)((intptr_t)args + sizeof(void*) + sizeof(cx_bool)));
}

void __test_suite_construct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = test_suite_construct(
        *(void**)args);
}

void __test_suite_fail(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(result);
    test_suite_fail(
        *(void**)args,
        *(cx_string*)((intptr_t)args + sizeof(void*)));
}

void __test_unit_construct(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_int16*)result = test_unit_construct(
        *(void**)args);
}

void __test_unit_fail(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(result);
    test_unit_fail(
        *(void**)args,
        *(cx_string*)((intptr_t)args + sizeof(void*)));
}
