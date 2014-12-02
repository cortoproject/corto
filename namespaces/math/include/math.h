/* math.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef math_H
#define math_H

#include "hyve.h"
#include "math__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::hyve::math::abs(::hyve::lang::uint64 x) */
db_uint64 math_abs(db_uint64 x);

/* ::hyve::math::acos(::hyve::lang::float64 x) */
db_float64 math_acos(db_float64 x);

/* ::hyve::math::asin(::hyve::lang::float64 x) */
db_float64 math_asin(db_float64 x);

/* ::hyve::math::atan(::hyve::lang::float64 x) */
db_float64 math_atan(db_float64 x);

/* ::hyve::math::cos(::hyve::lang::float64 x) */
db_float64 math_cos(db_float64 x);

/* ::hyve::math::exp(::hyve::lang::float64 x) */
db_float64 math_exp(db_float64 x);

/* ::hyve::math::log(::hyve::lang::float64 x) */
db_float64 math_log(db_float64 x);

/* ::hyve::math::log10(::hyve::lang::float64 x) */
db_float64 math_log10(db_float64 x);

/* ::hyve::math::pow(::hyve::lang::float64 x,::hyve::lang::float64 p) */
db_float64 math_pow(db_float64 x, db_float64 p);

/* ::hyve::math::rand() */
db_float64 math_rand(void);

/* ::hyve::math::seed(::hyve::lang::uint32 seed) */
db_void math_seed(db_uint32 seed);

/* ::hyve::math::sin(::hyve::lang::float64 x) */
db_float64 math_sin(db_float64 x);

/* ::hyve::math::sqrt(::hyve::lang::float64 x) */
db_float64 math_sqrt(db_float64 x);

/* ::hyve::math::tan(::hyve::lang::float64 x) */
db_float64 math_tan(db_float64 x);

#ifdef __cplusplus
}
#endif
#endif

