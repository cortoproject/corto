/* math__wrapper.c
 *
 * This file contains wrapper functions for ::hyve::math.
 */

#include "mth.h"
#include "math__meta.h"

void __mth_abs(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_uint64*)result = mth_abs(
        *(db_uint64*)args);
}

void __mth_acos(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_float64*)result = mth_acos(
        *(db_float64*)args);
}

void __mth_asin(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_float64*)result = mth_asin(
        *(db_float64*)args);
}

void __mth_atan(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_float64*)result = mth_atan(
        *(db_float64*)args);
}

void __mth_cos(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_float64*)result = mth_cos(
        *(db_float64*)args);
}

void __mth_exp(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_float64*)result = mth_exp(
        *(db_float64*)args);
}

void __mth_log(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_float64*)result = mth_log(
        *(db_float64*)args);
}

void __mth_log10(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_float64*)result = mth_log10(
        *(db_float64*)args);
}

void __mth_pow(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_float64*)result = mth_pow(
        *(db_float64*)args,
        *(db_float64*)((intptr_t)args + sizeof(db_float64)));
}

void __mth_rand(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(args);
    *(db_float64*)result = mth_rand(
        );
}

void __mth_seed(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    DB_UNUSED(result);
    mth_seed(
        *(db_uint32*)args);
}

void __mth_sin(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_float64*)result = mth_sin(
        *(db_float64*)args);
}

void __mth_sqrt(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_float64*)result = mth_sqrt(
        *(db_float64*)args);
}

void __mth_tan(db_function f, void *result, void *args) {
    DB_UNUSED(f);
    *(db_float64*)result = mth_tan(
        *(db_float64*)args);
}
