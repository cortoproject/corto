/* math__wrapper.c
 *
 * This file contains wrapper functions for ::cortex::math.
 */

#include "mth.h"
#include "math__meta.h"

void __mth_abs(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_uint64*)result = mth_abs(
        *(cx_uint64*)args);
}

void __mth_acos(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_float64*)result = mth_acos(
        *(cx_float64*)args);
}

void __mth_asin(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_float64*)result = mth_asin(
        *(cx_float64*)args);
}

void __mth_atan(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_float64*)result = mth_atan(
        *(cx_float64*)args);
}

void __mth_cos(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_float64*)result = mth_cos(
        *(cx_float64*)args);
}

void __mth_exp(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_float64*)result = mth_exp(
        *(cx_float64*)args);
}

void __mth_log(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_float64*)result = mth_log(
        *(cx_float64*)args);
}

void __mth_log10(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_float64*)result = mth_log10(
        *(cx_float64*)args);
}

void __mth_pow(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_float64*)result = mth_pow(
        *(cx_float64*)args,
        *(cx_float64*)((intptr_t)args + sizeof(cx_float64)));
}

void __mth_rand(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_float64*)result = mth_rand(
        );
}

void __mth_seed(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(result);
    mth_seed(
        *(cx_uint32*)args);
}

void __mth_sin(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_float64*)result = mth_sin(
        *(cx_float64*)args);
}

void __mth_sqrt(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_float64*)result = mth_sqrt(
        *(cx_float64*)args);
}

void __mth_tan(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    *(cx_float64*)result = mth_tan(
        *(cx_float64*)args);
}
