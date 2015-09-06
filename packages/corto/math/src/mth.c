/* mth.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#define corto_math_LIB
#include "mth.h"

/* $header() */
#include "math.h"
/* $end */

/* ::corto::math::abs(int64 x) */
cx_uint64 _mth_abs(cx_int64 x) {
/* $begin(::corto::math::abs) */

    return llabs(x);

/* $end */
}

/* ::corto::math::acos(float64 x) */
cx_float64 _mth_acos(cx_float64 x) {
/* $begin(::corto::math::acos) */

    return acos(x);

/* $end */
}

/* ::corto::math::asin(float64 x) */
cx_float64 _mth_asin(cx_float64 x) {
/* $begin(::corto::math::asin) */

    return asin(x);

/* $end */
}

/* ::corto::math::atan(float64 x) */
cx_float64 _mth_atan(cx_float64 x) {
/* $begin(::corto::math::atan) */

    return atan(x);

/* $end */
}

/* ::corto::math::cos(float64 x) */
cx_float64 _mth_cos(cx_float64 x) {
/* $begin(::corto::math::cos) */

    return cos(x);

/* $end */
}

/* ::corto::math::exp(float64 x) */
cx_float64 _mth_exp(cx_float64 x) {
/* $begin(::corto::math::exp) */

    return exp(x);

/* $end */
}

/* ::corto::math::log(float64 x) */
cx_float64 _mth_log(cx_float64 x) {
/* $begin(::corto::math::log) */

    return log(x);

/* $end */
}

/* ::corto::math::log10(float64 x) */
cx_float64 _mth_log10(cx_float64 x) {
/* $begin(::corto::math::log10) */

    return log10(x);

/* $end */
}

/* ::corto::math::pow(float64 x,float64 p) */
cx_float64 _mth_pow(cx_float64 x, cx_float64 p) {
/* $begin(::corto::math::pow) */

    return pow(x, p);

/* $end */
}

/* ::corto::math::rand() */
cx_float64 _mth_rand(void) {
/* $begin(::corto::math::rand) */

    return (cx_float64)rand() / (cx_float64)RAND_MAX;

/* $end */
}

/* ::corto::math::seed(uint32 seed) */
cx_void _mth_seed(cx_uint32 seed) {
/* $begin(::corto::math::seed) */

    srand(seed);

/* $end */
}

/* ::corto::math::sin(float64 x) */
cx_float64 _mth_sin(cx_float64 x) {
/* $begin(::corto::math::sin) */

    return sin(x);

/* $end */
}

/* ::corto::math::sqrt(float64 x) */
cx_float64 _mth_sqrt(cx_float64 x) {
/* $begin(::corto::math::sqrt) */

    return sqrt(x);

/* $end */
}

/* ::corto::math::tan(float64 x) */
cx_float64 _mth_tan(cx_float64 x) {
/* $begin(::corto::math::tan) */

    return tan(x);

/* $end */
}

int mathMain(int argc, char* argv[]) {
/* $begin(main) */
    /* Insert code that must be run when component is loaded */
    CX_UNUSED(argc);
    CX_UNUSED(argv);
    return 0;
/* $end */
}
