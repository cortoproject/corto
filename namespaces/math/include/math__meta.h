/* math__meta.h
 *
 * Loads objects in database.
 * This file contains generated code. Do not modify!
 */

#ifndef math_META_H
#define math_META_H

#include "hyve.h"

#include "math__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::hyve */
extern db_object _o;

/* ::hyve::math */
extern db_object mth_o;

/* ::hyve::math::abs(::hyve::lang::uint64 x) */
extern db_function mth_abs_o;

/* ::hyve::math::acos(::hyve::lang::float64 x) */
extern db_function mth_acos_o;

/* ::hyve::math::asin(::hyve::lang::float64 x) */
extern db_function mth_asin_o;

/* ::hyve::math::atan(::hyve::lang::float64 x) */
extern db_function mth_atan_o;

/* ::hyve::math::cos(::hyve::lang::float64 x) */
extern db_function mth_cos_o;

/* ::hyve::math::exp(::hyve::lang::float64 x) */
extern db_function mth_exp_o;

/* ::hyve::math::log(::hyve::lang::float64 x) */
extern db_function mth_log_o;

/* ::hyve::math::log10(::hyve::lang::float64 x) */
extern db_function mth_log10_o;

/* ::hyve::math::pow(::hyve::lang::float64 x,::hyve::lang::float64 p) */
extern db_function mth_pow_o;

/* ::hyve::math::rand() */
extern db_function mth_rand_o;

/* ::hyve::math::seed(::hyve::lang::uint32 seed) */
extern db_function mth_seed_o;

/* ::hyve::math::sin(::hyve::lang::float64 x) */
extern db_function mth_sin_o;

/* ::hyve::math::sqrt(::hyve::lang::float64 x) */
extern db_function mth_sqrt_o;

/* ::hyve::math::tan(::hyve::lang::float64 x) */
extern db_function mth_tan_o;

int math_load(void);
#ifdef __cplusplus
}
#endif
#endif

