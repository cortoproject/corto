/* mth.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "mth.h"

/* $header() */
#include "math.h"
/* $end */

/* ::corto::math::abs(int64 x) */
corto_uint64 _mth_abs(corto_int64 x) {
/* $begin(::corto::math::abs) */

    return llabs(x);

/* $end */
}

/* ::corto::math::acos(float64 x) */
corto_float64 _mth_acos(corto_float64 x) {
/* $begin(::corto::math::acos) */

    return acos(x);

/* $end */
}

/* ::corto::math::asin(float64 x) */
corto_float64 _mth_asin(corto_float64 x) {
/* $begin(::corto::math::asin) */

    return asin(x);

/* $end */
}

/* ::corto::math::atan(float64 x) */
corto_float64 _mth_atan(corto_float64 x) {
/* $begin(::corto::math::atan) */

    return atan(x);

/* $end */
}

/* ::corto::math::cos(float64 x) */
corto_float64 _mth_cos(corto_float64 x) {
/* $begin(::corto::math::cos) */

    return cos(x);

/* $end */
}

/* ::corto::math::exp(float64 x) */
corto_float64 _mth_exp(corto_float64 x) {
/* $begin(::corto::math::exp) */

    return exp(x);

/* $end */
}

/* ::corto::math::log(float64 x) */
corto_float64 _mth_log(corto_float64 x) {
/* $begin(::corto::math::log) */

    return log(x);

/* $end */
}

/* ::corto::math::log10(float64 x) */
corto_float64 _mth_log10(corto_float64 x) {
/* $begin(::corto::math::log10) */

    return log10(x);

/* $end */
}

/* ::corto::math::pow(float64 x,float64 p) */
corto_float64 _mth_pow(corto_float64 x, corto_float64 p) {
/* $begin(::corto::math::pow) */

    return pow(x, p);

/* $end */
}

/* ::corto::math::rand() */
corto_float64 _mth_rand(void) {
/* $begin(::corto::math::rand) */

    return (corto_float64)rand() / (corto_float64)RAND_MAX;

/* $end */
}

/* ::corto::math::seed(uint32 seed) */
corto_void _mth_seed(corto_uint32 seed) {
/* $begin(::corto::math::seed) */

    srand(seed);

/* $end */
}

/* ::corto::math::sin(float64 x) */
corto_float64 _mth_sin(corto_float64 x) {
/* $begin(::corto::math::sin) */

    return sin(x);

/* $end */
}

/* ::corto::math::sqrt(float64 x) */
corto_float64 _mth_sqrt(corto_float64 x) {
/* $begin(::corto::math::sqrt) */

    return sqrt(x);

/* $end */
}

/* ::corto::math::tan(float64 x) */
corto_float64 _mth_tan(corto_float64 x) {
/* $begin(::corto::math::tan) */

    return tan(x);

/* $end */
}

int mathMain(int argc, char* argv[]) {
/* $begin(main) */
    /* Insert code that must be run when component is loaded */
    CORTO_UNUSED(argc);
    CORTO_UNUSED(argv);
    return 0;
/* $end */
}
