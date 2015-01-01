/* mth.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef mth_H
#define mth_H

#include "cortex.h"
#include "math__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::cortex::math::abs(::cortex::lang::uint64 x) */
db_uint64 mth_abs(db_uint64 x);

/* ::cortex::math::acos(::cortex::lang::float64 x) */
db_float64 mth_acos(db_float64 x);

/* ::cortex::math::asin(::cortex::lang::float64 x) */
db_float64 mth_asin(db_float64 x);

/* ::cortex::math::atan(::cortex::lang::float64 x) */
db_float64 mth_atan(db_float64 x);

/* ::cortex::math::cos(::cortex::lang::float64 x) */
db_float64 mth_cos(db_float64 x);

/* ::cortex::math::exp(::cortex::lang::float64 x) */
db_float64 mth_exp(db_float64 x);

/* ::cortex::math::log(::cortex::lang::float64 x) */
db_float64 mth_log(db_float64 x);

/* ::cortex::math::log10(::cortex::lang::float64 x) */
db_float64 mth_log10(db_float64 x);

/* ::cortex::math::pow(::cortex::lang::float64 x,::cortex::lang::float64 p) */
db_float64 mth_pow(db_float64 x, db_float64 p);

/* ::cortex::math::rand() */
db_float64 mth_rand(void);

/* ::cortex::math::seed(::cortex::lang::uint32 seed) */
db_void mth_seed(db_uint32 seed);

/* ::cortex::math::sin(::cortex::lang::float64 x) */
db_float64 mth_sin(db_float64 x);

/* ::cortex::math::sqrt(::cortex::lang::float64 x) */
db_float64 mth_sqrt(db_float64 x);

/* ::cortex::math::tan(::cortex::lang::float64 x) */
db_float64 mth_tan(db_float64 x);

#ifdef __cplusplus
}
#endif
#endif

