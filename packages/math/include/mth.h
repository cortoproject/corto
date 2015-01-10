/* mth.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef mth_H
#define mth_H

#include "cortex.h"
#include "math__type.h"

#include "math__api.h"

#include "math__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::cortex::math::abs(uint64 x) */
cx_uint64 mth_abs(cx_uint64 x);

/* ::cortex::math::acos(float64 x) */
cx_float64 mth_acos(cx_float64 x);

/* ::cortex::math::asin(float64 x) */
cx_float64 mth_asin(cx_float64 x);

/* ::cortex::math::atan(float64 x) */
cx_float64 mth_atan(cx_float64 x);

/* ::cortex::math::cos(float64 x) */
cx_float64 mth_cos(cx_float64 x);

/* ::cortex::math::exp(float64 x) */
cx_float64 mth_exp(cx_float64 x);

/* ::cortex::math::log(float64 x) */
cx_float64 mth_log(cx_float64 x);

/* ::cortex::math::log10(float64 x) */
cx_float64 mth_log10(cx_float64 x);

/* ::cortex::math::pow(float64 x,float64 p) */
cx_float64 mth_pow(cx_float64 x, cx_float64 p);

/* ::cortex::math::rand() */
cx_float64 mth_rand(void);

/* ::cortex::math::seed(uint32 seed) */
cx_void mth_seed(cx_uint32 seed);

/* ::cortex::math::sin(float64 x) */
cx_float64 mth_sin(cx_float64 x);

/* ::cortex::math::sqrt(float64 x) */
cx_float64 mth_sqrt(cx_float64 x);

/* ::cortex::math::tan(float64 x) */
cx_float64 mth_tan(cx_float64 x);

#ifdef __cplusplus
}
#endif
#endif

