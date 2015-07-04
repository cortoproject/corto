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

/* ::cortex::math::abs(int64 x) */
cx_uint64 mth_abs(cx_int64 x) {
/* $begin(::cortex::math::abs) */

    return llabs(x);

/* $end */
}

/* ::cortex::math::acos(float64 x) */
cx_float64 mth_acos(cx_float64 x) {
/* $begin(::cortex::math::acos) */

    return acos(x);

/* $end */
}

/* ::cortex::math::asin(float64 x) */
cx_float64 mth_asin(cx_float64 x) {
/* $begin(::cortex::math::asin) */

    return asin(x);

/* $end */
}

/* ::cortex::math::atan(float64 x) */
cx_float64 mth_atan(cx_float64 x) {
/* $begin(::cortex::math::atan) */

    return atan(x);

/* $end */
}

/* ::cortex::math::cos(float64 x) */
cx_float64 mth_cos(cx_float64 x) {
/* $begin(::cortex::math::cos) */

    return cos(x);

/* $end */
}

/* ::cortex::math::exp(float64 x) */
cx_float64 mth_exp(cx_float64 x) {
/* $begin(::cortex::math::exp) */

    return exp(x);

/* $end */
}

/* ::cortex::math::log(float64 x) */
cx_float64 mth_log(cx_float64 x) {
/* $begin(::cortex::math::log) */

    return log(x);

/* $end */
}

/* ::cortex::math::log10(float64 x) */
cx_float64 mth_log10(cx_float64 x) {
/* $begin(::cortex::math::log10) */

    return log10(x);

/* $end */
}

/* ::cortex::math::pow(float64 x,float64 p) */
cx_float64 mth_pow(cx_float64 x, cx_float64 p) {
/* $begin(::cortex::math::pow) */

    return pow(x, p);

/* $end */
}

/* ::cortex::math::rand() */
cx_float64 mth_rand(void) {
/* $begin(::cortex::math::rand) */

    return (cx_float64)rand() / (cx_float64)RAND_MAX;

/* $end */
}

/* ::cortex::math::seed(uint32 seed) */
cx_void mth_seed(cx_uint32 seed) {
/* $begin(::cortex::math::seed) */

    srand(seed);

/* $end */
}

/* ::cortex::math::sin(float64 x) */
cx_float64 mth_sin(cx_float64 x) {
/* $begin(::cortex::math::sin) */

    return sin(x);

/* $end */
}

/* ::cortex::math::sqrt(float64 x) */
cx_float64 mth_sqrt(cx_float64 x) {
/* $begin(::cortex::math::sqrt) */

    return sqrt(x);

/* $end */
}

/* ::cortex::math::tan(float64 x) */
cx_float64 mth_tan(cx_float64 x) {
/* $begin(::cortex::math::tan) */

    return tan(x);

/* $end */
}
