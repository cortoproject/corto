/* math__meta.c
 *
 * Loads objects in database.
 * This file contains generated code. Do not modify!
 */

#include "math__type.h"

/* Variable definitions */
cx_object _o;
cx_object mth_o;
cx_function mth_abs_o;
cx_function mth_acos_o;
cx_function mth_asin_o;
cx_function mth_atan_o;
cx_function mth_cos_o;
cx_function mth_exp_o;
cx_function mth_log_o;
cx_function mth_log10_o;
cx_function mth_pow_o;
cx_function mth_rand_o;
cx_function mth_seed_o;
cx_function mth_sin_o;
cx_function mth_sqrt_o;
cx_function mth_tan_o;

/* Load objects in database */
int math_load(void) {
    cx_object _a_; /* Used for resolving anonymous objects */
    _a_ = NULL;

    /* Declare ::cortex */
    _o = cx_declare(root_o, "cortex", cx_typedef(cx_object_o));
    if (!_o) {
        cx_error("math_load: failed to declare object '::cortex'.");
        goto error;
    }

    /* Define ::cortex */
    if (!cx_checkState(_o, CX_DEFINED)) {
        if (cx_define(_o)) {
            cx_error("math_load: failed to define object '::cortex'.");
            goto error;
        }
    }

    /* Declare ::cortex::math */
    mth_o = cx_declare(_o, "math", cx_typedef(cx_object_o));
    if (!mth_o) {
        cx_error("math_load: failed to declare object '::cortex::math'.");
        goto error;
    }

    /* Define ::cortex::math */
    if (!cx_checkState(mth_o, CX_DEFINED)) {
        if (cx_define(mth_o)) {
            cx_error("math_load: failed to define object '::cortex::math'.");
            goto error;
        }
    }

    /* Declare ::cortex::math::abs(::cortex::lang::uint64 x) */
    mth_abs_o = cx_declare(mth_o, "abs(::cortex::lang::uint64 x)", cx_typedef(cx_function_o));
    if (!mth_abs_o) {
        cx_error("math_load: failed to declare object '::cortex::math::abs(::cortex::lang::uint64 x)'.");
        goto error;
    }

    /* Define ::cortex::math::abs(::cortex::lang::uint64 x) */
    if (!cx_checkState(mth_abs_o, CX_DEFINED)) {
        mth_abs_o->returnType = cx_resolve_ext(mth_abs_o, NULL, "::cortex::lang::uint64", FALSE, "element ::cortex::math::abs(::cortex::lang::uint64 x).returnType");
        mth_abs_o->returnsReference = FALSE;
        
        /* Bind ::cortex::math::abs(::cortex::lang::uint64 x) with C-function */
        cx_function(mth_abs_o)->kind = CX_PROCEDURE_CDECL;
        void __mth_abs(void *args, void *result);
        cx_function(mth_abs_o)->impl = (cx_word)__mth_abs;
        if (cx_define(mth_abs_o)) {
            cx_error("math_load: failed to define object '::cortex::math::abs(::cortex::lang::uint64 x)'.");
            goto error;
        }
    }

    /* Declare ::cortex::math::acos(::cortex::lang::float64 x) */
    mth_acos_o = cx_declare(mth_o, "acos(::cortex::lang::float64 x)", cx_typedef(cx_function_o));
    if (!mth_acos_o) {
        cx_error("math_load: failed to declare object '::cortex::math::acos(::cortex::lang::float64 x)'.");
        goto error;
    }

    /* Define ::cortex::math::acos(::cortex::lang::float64 x) */
    if (!cx_checkState(mth_acos_o, CX_DEFINED)) {
        mth_acos_o->returnType = cx_resolve_ext(mth_acos_o, NULL, "::cortex::lang::float64", FALSE, "element ::cortex::math::acos(::cortex::lang::float64 x).returnType");
        mth_acos_o->returnsReference = FALSE;
        
        /* Bind ::cortex::math::acos(::cortex::lang::float64 x) with C-function */
        cx_function(mth_acos_o)->kind = CX_PROCEDURE_CDECL;
        void __mth_acos(void *args, void *result);
        cx_function(mth_acos_o)->impl = (cx_word)__mth_acos;
        if (cx_define(mth_acos_o)) {
            cx_error("math_load: failed to define object '::cortex::math::acos(::cortex::lang::float64 x)'.");
            goto error;
        }
    }

    /* Declare ::cortex::math::asin(::cortex::lang::float64 x) */
    mth_asin_o = cx_declare(mth_o, "asin(::cortex::lang::float64 x)", cx_typedef(cx_function_o));
    if (!mth_asin_o) {
        cx_error("math_load: failed to declare object '::cortex::math::asin(::cortex::lang::float64 x)'.");
        goto error;
    }

    /* Define ::cortex::math::asin(::cortex::lang::float64 x) */
    if (!cx_checkState(mth_asin_o, CX_DEFINED)) {
        mth_asin_o->returnType = cx_resolve_ext(mth_asin_o, NULL, "::cortex::lang::float64", FALSE, "element ::cortex::math::asin(::cortex::lang::float64 x).returnType");
        mth_asin_o->returnsReference = FALSE;
        
        /* Bind ::cortex::math::asin(::cortex::lang::float64 x) with C-function */
        cx_function(mth_asin_o)->kind = CX_PROCEDURE_CDECL;
        void __mth_asin(void *args, void *result);
        cx_function(mth_asin_o)->impl = (cx_word)__mth_asin;
        if (cx_define(mth_asin_o)) {
            cx_error("math_load: failed to define object '::cortex::math::asin(::cortex::lang::float64 x)'.");
            goto error;
        }
    }

    /* Declare ::cortex::math::atan(::cortex::lang::float64 x) */
    mth_atan_o = cx_declare(mth_o, "atan(::cortex::lang::float64 x)", cx_typedef(cx_function_o));
    if (!mth_atan_o) {
        cx_error("math_load: failed to declare object '::cortex::math::atan(::cortex::lang::float64 x)'.");
        goto error;
    }

    /* Define ::cortex::math::atan(::cortex::lang::float64 x) */
    if (!cx_checkState(mth_atan_o, CX_DEFINED)) {
        mth_atan_o->returnType = cx_resolve_ext(mth_atan_o, NULL, "::cortex::lang::float64", FALSE, "element ::cortex::math::atan(::cortex::lang::float64 x).returnType");
        mth_atan_o->returnsReference = FALSE;
        
        /* Bind ::cortex::math::atan(::cortex::lang::float64 x) with C-function */
        cx_function(mth_atan_o)->kind = CX_PROCEDURE_CDECL;
        void __mth_atan(void *args, void *result);
        cx_function(mth_atan_o)->impl = (cx_word)__mth_atan;
        if (cx_define(mth_atan_o)) {
            cx_error("math_load: failed to define object '::cortex::math::atan(::cortex::lang::float64 x)'.");
            goto error;
        }
    }

    /* Declare ::cortex::math::cos(::cortex::lang::float64 x) */
    mth_cos_o = cx_declare(mth_o, "cos(::cortex::lang::float64 x)", cx_typedef(cx_function_o));
    if (!mth_cos_o) {
        cx_error("math_load: failed to declare object '::cortex::math::cos(::cortex::lang::float64 x)'.");
        goto error;
    }

    /* Define ::cortex::math::cos(::cortex::lang::float64 x) */
    if (!cx_checkState(mth_cos_o, CX_DEFINED)) {
        mth_cos_o->returnType = cx_resolve_ext(mth_cos_o, NULL, "::cortex::lang::float64", FALSE, "element ::cortex::math::cos(::cortex::lang::float64 x).returnType");
        mth_cos_o->returnsReference = FALSE;
        
        /* Bind ::cortex::math::cos(::cortex::lang::float64 x) with C-function */
        cx_function(mth_cos_o)->kind = CX_PROCEDURE_CDECL;
        void __mth_cos(void *args, void *result);
        cx_function(mth_cos_o)->impl = (cx_word)__mth_cos;
        if (cx_define(mth_cos_o)) {
            cx_error("math_load: failed to define object '::cortex::math::cos(::cortex::lang::float64 x)'.");
            goto error;
        }
    }

    /* Declare ::cortex::math::exp(::cortex::lang::float64 x) */
    mth_exp_o = cx_declare(mth_o, "exp(::cortex::lang::float64 x)", cx_typedef(cx_function_o));
    if (!mth_exp_o) {
        cx_error("math_load: failed to declare object '::cortex::math::exp(::cortex::lang::float64 x)'.");
        goto error;
    }

    /* Define ::cortex::math::exp(::cortex::lang::float64 x) */
    if (!cx_checkState(mth_exp_o, CX_DEFINED)) {
        mth_exp_o->returnType = cx_resolve_ext(mth_exp_o, NULL, "::cortex::lang::float64", FALSE, "element ::cortex::math::exp(::cortex::lang::float64 x).returnType");
        mth_exp_o->returnsReference = FALSE;
        
        /* Bind ::cortex::math::exp(::cortex::lang::float64 x) with C-function */
        cx_function(mth_exp_o)->kind = CX_PROCEDURE_CDECL;
        void __mth_exp(void *args, void *result);
        cx_function(mth_exp_o)->impl = (cx_word)__mth_exp;
        if (cx_define(mth_exp_o)) {
            cx_error("math_load: failed to define object '::cortex::math::exp(::cortex::lang::float64 x)'.");
            goto error;
        }
    }

    /* Declare ::cortex::math::log(::cortex::lang::float64 x) */
    mth_log_o = cx_declare(mth_o, "log(::cortex::lang::float64 x)", cx_typedef(cx_function_o));
    if (!mth_log_o) {
        cx_error("math_load: failed to declare object '::cortex::math::log(::cortex::lang::float64 x)'.");
        goto error;
    }

    /* Define ::cortex::math::log(::cortex::lang::float64 x) */
    if (!cx_checkState(mth_log_o, CX_DEFINED)) {
        mth_log_o->returnType = cx_resolve_ext(mth_log_o, NULL, "::cortex::lang::float64", FALSE, "element ::cortex::math::log(::cortex::lang::float64 x).returnType");
        mth_log_o->returnsReference = FALSE;
        
        /* Bind ::cortex::math::log(::cortex::lang::float64 x) with C-function */
        cx_function(mth_log_o)->kind = CX_PROCEDURE_CDECL;
        void __mth_log(void *args, void *result);
        cx_function(mth_log_o)->impl = (cx_word)__mth_log;
        if (cx_define(mth_log_o)) {
            cx_error("math_load: failed to define object '::cortex::math::log(::cortex::lang::float64 x)'.");
            goto error;
        }
    }

    /* Declare ::cortex::math::log10(::cortex::lang::float64 x) */
    mth_log10_o = cx_declare(mth_o, "log10(::cortex::lang::float64 x)", cx_typedef(cx_function_o));
    if (!mth_log10_o) {
        cx_error("math_load: failed to declare object '::cortex::math::log10(::cortex::lang::float64 x)'.");
        goto error;
    }

    /* Define ::cortex::math::log10(::cortex::lang::float64 x) */
    if (!cx_checkState(mth_log10_o, CX_DEFINED)) {
        mth_log10_o->returnType = cx_resolve_ext(mth_log10_o, NULL, "::cortex::lang::float64", FALSE, "element ::cortex::math::log10(::cortex::lang::float64 x).returnType");
        mth_log10_o->returnsReference = FALSE;
        
        /* Bind ::cortex::math::log10(::cortex::lang::float64 x) with C-function */
        cx_function(mth_log10_o)->kind = CX_PROCEDURE_CDECL;
        void __mth_log10(void *args, void *result);
        cx_function(mth_log10_o)->impl = (cx_word)__mth_log10;
        if (cx_define(mth_log10_o)) {
            cx_error("math_load: failed to define object '::cortex::math::log10(::cortex::lang::float64 x)'.");
            goto error;
        }
    }

    /* Declare ::cortex::math::pow(::cortex::lang::float64 x,::cortex::lang::float64 p) */
    mth_pow_o = cx_declare(mth_o, "pow(::cortex::lang::float64 x,::cortex::lang::float64 p)", cx_typedef(cx_function_o));
    if (!mth_pow_o) {
        cx_error("math_load: failed to declare object '::cortex::math::pow(::cortex::lang::float64 x,::cortex::lang::float64 p)'.");
        goto error;
    }

    /* Define ::cortex::math::pow(::cortex::lang::float64 x,::cortex::lang::float64 p) */
    if (!cx_checkState(mth_pow_o, CX_DEFINED)) {
        mth_pow_o->returnType = cx_resolve_ext(mth_pow_o, NULL, "::cortex::lang::float64", FALSE, "element ::cortex::math::pow(::cortex::lang::float64 x,::cortex::lang::float64 p).returnType");
        mth_pow_o->returnsReference = FALSE;
        
        /* Bind ::cortex::math::pow(::cortex::lang::float64 x,::cortex::lang::float64 p) with C-function */
        cx_function(mth_pow_o)->kind = CX_PROCEDURE_CDECL;
        void __mth_pow(void *args, void *result);
        cx_function(mth_pow_o)->impl = (cx_word)__mth_pow;
        if (cx_define(mth_pow_o)) {
            cx_error("math_load: failed to define object '::cortex::math::pow(::cortex::lang::float64 x,::cortex::lang::float64 p)'.");
            goto error;
        }
    }

    /* Declare ::cortex::math::rand() */
    mth_rand_o = cx_declare(mth_o, "rand()", cx_typedef(cx_function_o));
    if (!mth_rand_o) {
        cx_error("math_load: failed to declare object '::cortex::math::rand()'.");
        goto error;
    }

    /* Define ::cortex::math::rand() */
    if (!cx_checkState(mth_rand_o, CX_DEFINED)) {
        mth_rand_o->returnType = cx_resolve_ext(mth_rand_o, NULL, "::cortex::lang::float64", FALSE, "element ::cortex::math::rand().returnType");
        mth_rand_o->returnsReference = FALSE;
        
        /* Bind ::cortex::math::rand() with C-function */
        cx_function(mth_rand_o)->kind = CX_PROCEDURE_CDECL;
        void __mth_rand(void *args, void *result);
        cx_function(mth_rand_o)->impl = (cx_word)__mth_rand;
        if (cx_define(mth_rand_o)) {
            cx_error("math_load: failed to define object '::cortex::math::rand()'.");
            goto error;
        }
    }

    /* Declare ::cortex::math::seed(::cortex::lang::uint32 seed) */
    mth_seed_o = cx_declare(mth_o, "seed(::cortex::lang::uint32 seed)", cx_typedef(cx_function_o));
    if (!mth_seed_o) {
        cx_error("math_load: failed to declare object '::cortex::math::seed(::cortex::lang::uint32 seed)'.");
        goto error;
    }

    /* Define ::cortex::math::seed(::cortex::lang::uint32 seed) */
    if (!cx_checkState(mth_seed_o, CX_DEFINED)) {
        mth_seed_o->returnType = cx_resolve_ext(mth_seed_o, NULL, "::cortex::lang::void", FALSE, "element ::cortex::math::seed(::cortex::lang::uint32 seed).returnType");
        mth_seed_o->returnsReference = FALSE;
        
        /* Bind ::cortex::math::seed(::cortex::lang::uint32 seed) with C-function */
        cx_function(mth_seed_o)->kind = CX_PROCEDURE_CDECL;
        void __mth_seed(void *args, void *result);
        cx_function(mth_seed_o)->impl = (cx_word)__mth_seed;
        if (cx_define(mth_seed_o)) {
            cx_error("math_load: failed to define object '::cortex::math::seed(::cortex::lang::uint32 seed)'.");
            goto error;
        }
    }

    /* Declare ::cortex::math::sin(::cortex::lang::float64 x) */
    mth_sin_o = cx_declare(mth_o, "sin(::cortex::lang::float64 x)", cx_typedef(cx_function_o));
    if (!mth_sin_o) {
        cx_error("math_load: failed to declare object '::cortex::math::sin(::cortex::lang::float64 x)'.");
        goto error;
    }

    /* Define ::cortex::math::sin(::cortex::lang::float64 x) */
    if (!cx_checkState(mth_sin_o, CX_DEFINED)) {
        mth_sin_o->returnType = cx_resolve_ext(mth_sin_o, NULL, "::cortex::lang::float64", FALSE, "element ::cortex::math::sin(::cortex::lang::float64 x).returnType");
        mth_sin_o->returnsReference = FALSE;
        
        /* Bind ::cortex::math::sin(::cortex::lang::float64 x) with C-function */
        cx_function(mth_sin_o)->kind = CX_PROCEDURE_CDECL;
        void __mth_sin(void *args, void *result);
        cx_function(mth_sin_o)->impl = (cx_word)__mth_sin;
        if (cx_define(mth_sin_o)) {
            cx_error("math_load: failed to define object '::cortex::math::sin(::cortex::lang::float64 x)'.");
            goto error;
        }
    }

    /* Declare ::cortex::math::sqrt(::cortex::lang::float64 x) */
    mth_sqrt_o = cx_declare(mth_o, "sqrt(::cortex::lang::float64 x)", cx_typedef(cx_function_o));
    if (!mth_sqrt_o) {
        cx_error("math_load: failed to declare object '::cortex::math::sqrt(::cortex::lang::float64 x)'.");
        goto error;
    }

    /* Define ::cortex::math::sqrt(::cortex::lang::float64 x) */
    if (!cx_checkState(mth_sqrt_o, CX_DEFINED)) {
        mth_sqrt_o->returnType = cx_resolve_ext(mth_sqrt_o, NULL, "::cortex::lang::float64", FALSE, "element ::cortex::math::sqrt(::cortex::lang::float64 x).returnType");
        mth_sqrt_o->returnsReference = FALSE;
        
        /* Bind ::cortex::math::sqrt(::cortex::lang::float64 x) with C-function */
        cx_function(mth_sqrt_o)->kind = CX_PROCEDURE_CDECL;
        void __mth_sqrt(void *args, void *result);
        cx_function(mth_sqrt_o)->impl = (cx_word)__mth_sqrt;
        if (cx_define(mth_sqrt_o)) {
            cx_error("math_load: failed to define object '::cortex::math::sqrt(::cortex::lang::float64 x)'.");
            goto error;
        }
    }

    /* Declare ::cortex::math::tan(::cortex::lang::float64 x) */
    mth_tan_o = cx_declare(mth_o, "tan(::cortex::lang::float64 x)", cx_typedef(cx_function_o));
    if (!mth_tan_o) {
        cx_error("math_load: failed to declare object '::cortex::math::tan(::cortex::lang::float64 x)'.");
        goto error;
    }

    /* Define ::cortex::math::tan(::cortex::lang::float64 x) */
    if (!cx_checkState(mth_tan_o, CX_DEFINED)) {
        mth_tan_o->returnType = cx_resolve_ext(mth_tan_o, NULL, "::cortex::lang::float64", FALSE, "element ::cortex::math::tan(::cortex::lang::float64 x).returnType");
        mth_tan_o->returnsReference = FALSE;
        
        /* Bind ::cortex::math::tan(::cortex::lang::float64 x) with C-function */
        cx_function(mth_tan_o)->kind = CX_PROCEDURE_CDECL;
        void __mth_tan(void *args, void *result);
        cx_function(mth_tan_o)->impl = (cx_word)__mth_tan;
        if (cx_define(mth_tan_o)) {
            cx_error("math_load: failed to define object '::cortex::math::tan(::cortex::lang::float64 x)'.");
            goto error;
        }
    }

    if (_a_) {
        cx_free(_a_);
    }

    return 0;
error:
    return -1;
}
