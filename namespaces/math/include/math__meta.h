/* math__meta.h
 *
 * Loads objects in database.
 * This file contains generated code. Do not modify!
 */

#ifndef math_META_H
#define math_META_H

#include "cortex.h"

#include "math__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::cortex */
extern cx_object _o;

/* ::cortex::math */
extern cx_object mth_o;

/* ::cortex::math::abs(::cortex::lang::uint64 x) */
extern cx_function mth_abs_o;

/* ::cortex::math::acos(::cortex::lang::float64 x) */
extern cx_function mth_acos_o;

/* ::cortex::math::asin(::cortex::lang::float64 x) */
extern cx_function mth_asin_o;

/* ::cortex::math::atan(::cortex::lang::float64 x) */
extern cx_function mth_atan_o;

/* ::cortex::math::cos(::cortex::lang::float64 x) */
extern cx_function mth_cos_o;

/* ::cortex::math::exp(::cortex::lang::float64 x) */
extern cx_function mth_exp_o;

/* ::cortex::math::log(::cortex::lang::float64 x) */
extern cx_function mth_log_o;

/* ::cortex::math::log10(::cortex::lang::float64 x) */
extern cx_function mth_log10_o;

/* ::cortex::math::pow(::cortex::lang::float64 x,::cortex::lang::float64 p) */
extern cx_function mth_pow_o;

/* ::cortex::math::rand() */
extern cx_function mth_rand_o;

/* ::cortex::math::seed(::cortex::lang::uint32 seed) */
extern cx_function mth_seed_o;

/* ::cortex::math::sin(::cortex::lang::float64 x) */
extern cx_function mth_sin_o;

/* ::cortex::math::sqrt(::cortex::lang::float64 x) */
extern cx_function mth_sqrt_o;

/* ::cortex::math::tan(::cortex::lang::float64 x) */
extern cx_function mth_tan_o;

int math_load(void);
#ifdef __cplusplus
}
#endif
#endif

