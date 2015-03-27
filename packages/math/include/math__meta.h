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
extern cx_package mth_o;

/* ::cortex::math::abs(uint64 x) */
extern cx_function mth_abs_o;

/* ::cortex::math::acos(float64 x) */
extern cx_function mth_acos_o;

/* ::cortex::math::asin(float64 x) */
extern cx_function mth_asin_o;

/* ::cortex::math::atan(float64 x) */
extern cx_function mth_atan_o;

/* ::cortex::math::cos(float64 x) */
extern cx_function mth_cos_o;

/* ::cortex::math::exp(float64 x) */
extern cx_function mth_exp_o;

/* ::cortex::math::log(float64 x) */
extern cx_function mth_log_o;

/* ::cortex::math::log10(float64 x) */
extern cx_function mth_log10_o;

/* ::cortex::math::pow(float64 x,float64 p) */
extern cx_function mth_pow_o;

/* ::cortex::math::rand() */
extern cx_function mth_rand_o;

/* ::cortex::math::seed(uint32 seed) */
extern cx_function mth_seed_o;

/* ::cortex::math::sin(float64 x) */
extern cx_function mth_sin_o;

/* ::cortex::math::sqrt(float64 x) */
extern cx_function mth_sqrt_o;

/* ::cortex::math::tan(float64 x) */
extern cx_function mth_tan_o;

int math_load(void);
#ifdef __cplusplus
}
#endif
#endif

