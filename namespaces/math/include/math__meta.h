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
extern db_object math_o;

/* ::hyve::math::abs(::hyve::lang::uint64 x) */
extern db_function math_abs_o;

/* ::hyve::math::acos(::hyve::lang::float64 x) */
extern db_function math_acos_o;

/* ::hyve::math::asin(::hyve::lang::float64 x) */
extern db_function math_asin_o;

/* ::hyve::math::atan(::hyve::lang::float64 x) */
extern db_function math_atan_o;

/* ::hyve::math::cos(::hyve::lang::float64 x) */
extern db_function math_cos_o;

/* ::hyve::math::exp(::hyve::lang::float64 x) */
extern db_function math_exp_o;

/* ::hyve::math::log(::hyve::lang::float64 x) */
extern db_function math_log_o;

/* ::hyve::math::log10(::hyve::lang::float64 x) */
extern db_function math_log10_o;

/* ::hyve::math::pow(::hyve::lang::float64 x,::hyve::lang::float64 p) */
extern db_function math_pow_o;

/* ::hyve::math::rand() */
extern db_function math_rand_o;

/* ::hyve::math::seed(::hyve::lang::uint32 seed) */
extern db_function math_seed_o;

/* ::hyve::math::sin(::hyve::lang::float64 x) */
extern db_function math_sin_o;

/* ::hyve::math::sqrt(::hyve::lang::float64 x) */
extern db_function math_sqrt_o;

/* ::hyve::math::tan(::hyve::lang::float64 x) */
extern db_function math_tan_o;

int math_load(void);
#ifdef __cplusplus
}
#endif
#endif

