/* mth.h
 *
 *  Generated on Sep  5 2014
 *    This file contains generated code. Do not modify!
 */

#ifndef mth_H
#define mth_H

#include "hyve.h"
#include "math__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::hyve::math::abs(::hyve::lang::uint64 x) */
db_uint64 mth_abs(db_uint64 x);

/* ::hyve::math::acos(::hyve::lang::float64 x) */
db_float64 mth_acos(db_float64 x);

/* ::hyve::math::asin(::hyve::lang::float64 x) */
db_float64 mth_asin(db_float64 x);

/* ::hyve::math::atan(::hyve::lang::float64 x) */
db_float64 mth_atan(db_float64 x);

/* ::hyve::math::cos(::hyve::lang::float64 x) */
db_float64 mth_cos(db_float64 x);

/* ::hyve::math::exp(::hyve::lang::float64 x) */
db_float64 mth_exp(db_float64 x);

/* ::hyve::math::log(::hyve::lang::float64 x) */
db_float64 mth_log(db_float64 x);

/* ::hyve::math::log10(::hyve::lang::float64 x) */
db_float64 mth_log10(db_float64 x);

/* ::hyve::math::pow(::hyve::lang::float64 x,::hyve::lang::float64 p) */
db_float64 mth_pow(db_float64 x, db_float64 p);

/* ::hyve::math::rand() */
db_float64 mth_rand(void);

/* ::hyve::math::seed(::hyve::lang::uint32 seed) */
db_void mth_seed(db_uint32 seed);

/* ::hyve::math::sin(::hyve::lang::float64 x) */
db_float64 mth_sin(db_float64 x);

/* ::hyve::math::sqrt(::hyve::lang::float64 x) */
db_float64 mth_sqrt(db_float64 x);

/* ::hyve::math::tan(::hyve::lang::float64 x) */
db_float64 mth_tan(db_float64 x);

#ifdef __cplusplus
}
#endif
#endif

