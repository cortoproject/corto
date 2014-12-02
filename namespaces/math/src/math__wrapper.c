/* math__wrapper.c
 *
 * This file contains wrapper functions for ::hyve::math.
 */

#include "math.h"
#include "math__meta.h"

void __math_abs(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_uint64*)result = math_abs(
        *(db_uint64*)args);
}

void __math_acos(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_float64*)result = math_acos(
        *(db_float64*)args);
}

void __math_asin(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_float64*)result = math_asin(
        *(db_float64*)args);
}

void __math_atan(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_float64*)result = math_atan(
        *(db_float64*)args);
}

void __math_cos(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_float64*)result = math_cos(
        *(db_float64*)args);
}

void __math_exp(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_float64*)result = math_exp(
        *(db_float64*)args);
}

void __math_log(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_float64*)result = math_log(
        *(db_float64*)args);
}

void __math_log10(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_float64*)result = math_log10(
        *(db_float64*)args);
}

void __math_pow(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_float64*)result = math_pow(
        *(db_float64*)args,
        *(db_float64*)((intptr_t)args + sizeof(db_float64)));
}

void __math_rand(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(db_float64*)result = math_rand(
        );
}

void __math_seed(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(result);
    math_seed(
        *(db_uint32*)args);
}

void __math_sin(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_float64*)result = math_sin(
        *(db_float64*)args);
}

void __math_sqrt(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_float64*)result = math_sqrt(
        *(db_float64*)args);
}

void __math_tan(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_float64*)result = math_tan(
        *(db_float64*)args);
}
