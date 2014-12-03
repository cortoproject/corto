/* mth.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "mth.h"
#include "math__meta.h"

/* $header() */
#include "math.h"

int hyvemain(int argc, char* argv[]) {
    DB_UNUSED(argc);
    DB_UNUSED(argv);

    math_load();

    return 0;
}
/* $end */

/* ::hyve::math::abs(::hyve::lang::uint64 x) */
db_uint64 mth_abs(db_uint64 x) {
/* $begin(::hyve::math::abs) */

    return llabs(x);

/* $end */
}

/* ::hyve::math::acos(::hyve::lang::float64 x) */
db_float64 mth_acos(db_float64 x) {
/* $begin(::hyve::math::acos) */

    return acos(x);

/* $end */
}

/* ::hyve::math::asin(::hyve::lang::float64 x) */
db_float64 mth_asin(db_float64 x) {
/* $begin(::hyve::math::asin) */

    return asin(x);

/* $end */
}

/* ::hyve::math::atan(::hyve::lang::float64 x) */
db_float64 mth_atan(db_float64 x) {
/* $begin(::hyve::math::atan) */

    return atan(x);

/* $end */
}

/* ::hyve::math::cos(::hyve::lang::float64 x) */
db_float64 mth_cos(db_float64 x) {
/* $begin(::hyve::math::cos) */

    return cos(x);

/* $end */
}

/* ::hyve::math::exp(::hyve::lang::float64 x) */
db_float64 mth_exp(db_float64 x) {
/* $begin(::hyve::math::exp) */

    return exp(x);

/* $end */
}

/* ::hyve::math::log(::hyve::lang::float64 x) */
db_float64 mth_log(db_float64 x) {
/* $begin(::hyve::math::log) */

    return log(x);

/* $end */
}

/* ::hyve::math::log10(::hyve::lang::float64 x) */
db_float64 mth_log10(db_float64 x) {
/* $begin(::hyve::math::log10) */

    return log10(x);

/* $end */
}

/* ::hyve::math::pow(::hyve::lang::float64 x,::hyve::lang::float64 p) */
db_float64 mth_pow(db_float64 x, db_float64 p) {
/* $begin(::hyve::math::pow) */

    return pow(x, p);

/* $end */
}

/* ::hyve::math::rand() */
db_float64 mth_rand(void) {
/* $begin(::hyve::math::rand) */

    return (db_float64)rand() / (db_float64)RAND_MAX;

/* $end */
}

/* ::hyve::math::seed(::hyve::lang::uint32 seed) */
db_void mth_seed(db_uint32 seed) {
/* $begin(::hyve::math::seed) */

    srand(seed);

/* $end */
}

/* ::hyve::math::sin(::hyve::lang::float64 x) */
db_float64 mth_sin(db_float64 x) {
/* $begin(::hyve::math::sin) */

    return sin(x);

/* $end */
}

/* ::hyve::math::sqrt(::hyve::lang::float64 x) */
db_float64 mth_sqrt(db_float64 x) {
/* $begin(::hyve::math::sqrt) */

    return sqrt(x);

/* $end */
}

/* ::hyve::math::tan(::hyve::lang::float64 x) */
db_float64 mth_tan(db_float64 x) {
/* $begin(::hyve::math::tan) */

    return tan(x);

/* $end */
}
