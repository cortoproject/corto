/* math__meta.c
 *
 * Loads objects in database.
 * This file contains generated code. Do not modify!
 */

#include "math__type.h"

/* Variable definitions */
db_object _o;
db_object mth_o;
db_function mth_abs_o;
db_function mth_acos_o;
db_function mth_asin_o;
db_function mth_atan_o;
db_function mth_cos_o;
db_function mth_exp_o;
db_function mth_log_o;
db_function mth_log10_o;
db_function mth_pow_o;
db_function mth_rand_o;
db_function mth_seed_o;
db_function mth_sin_o;
db_function mth_sqrt_o;
db_function mth_tan_o;

/* Load objects in database */
int math_load(void) {
    db_object _a_; /* Used for resolving anonymous objects */
    _a_ = NULL;

    /* Declare ::cortex */
    _o = db_declare(root_o, "cortex", db_typedef(db_object_o));
    if (!_o) {
        db_error("math_load: failed to declare object '::cortex'.");
        goto error;
    }

    /* Define ::cortex */
    if (!db_checkState(_o, DB_DEFINED)) {
        if (db_define(_o)) {
            db_error("math_load: failed to define object '::cortex'.");
            goto error;
        }
    }
    /* Declare ::cortex::math */
    mth_o = db_declare(_o, "math", db_typedef(db_object_o));
    if (!mth_o) {
        db_error("math_load: failed to declare object '::cortex::math'.");
        goto error;
    }

    /* Define ::cortex::math */
    if (!db_checkState(mth_o, DB_DEFINED)) {
        if (db_define(mth_o)) {
            db_error("math_load: failed to define object '::cortex::math'.");
            goto error;
        }
    }
    /* Declare ::cortex::math::abs(::cortex::lang::uint64 x) */
    mth_abs_o = db_declare(mth_o, "abs(::cortex::lang::uint64 x)", db_typedef(db_function_o));
    if (!mth_abs_o) {
        db_error("math_load: failed to declare object '::cortex::math::abs(::cortex::lang::uint64 x)'.");
        goto error;
    }

    /* Define ::cortex::math::abs(::cortex::lang::uint64 x) */
    if (!db_checkState(mth_abs_o, DB_DEFINED)) {
        mth_abs_o->returnType = db_resolve_ext(mth_abs_o, NULL, "::cortex::lang::uint64", FALSE, "element ::cortex::math::abs(::cortex::lang::uint64 x).returnType");
        mth_abs_o->returnsReference = FALSE;
        
        /* Bind mth_abs_o with C-function */
        db_function(mth_abs_o)->kind = DB_PROCEDURE_CDECL;
        void __mth_abs(void *args, void *result);
        db_function(mth_abs_o)->impl = (db_word)__mth_abs;
        if (db_define(mth_abs_o)) {
            db_error("math_load: failed to define object '::cortex::math::abs(::cortex::lang::uint64 x)'.");
            goto error;
        }
    }
    /* Declare ::cortex::math::acos(::cortex::lang::float64 x) */
    mth_acos_o = db_declare(mth_o, "acos(::cortex::lang::float64 x)", db_typedef(db_function_o));
    if (!mth_acos_o) {
        db_error("math_load: failed to declare object '::cortex::math::acos(::cortex::lang::float64 x)'.");
        goto error;
    }

    /* Define ::cortex::math::acos(::cortex::lang::float64 x) */
    if (!db_checkState(mth_acos_o, DB_DEFINED)) {
        mth_acos_o->returnType = db_resolve_ext(mth_acos_o, NULL, "::cortex::lang::float64", FALSE, "element ::cortex::math::acos(::cortex::lang::float64 x).returnType");
        mth_acos_o->returnsReference = FALSE;
        
        /* Bind mth_acos_o with C-function */
        db_function(mth_acos_o)->kind = DB_PROCEDURE_CDECL;
        void __mth_acos(void *args, void *result);
        db_function(mth_acos_o)->impl = (db_word)__mth_acos;
        if (db_define(mth_acos_o)) {
            db_error("math_load: failed to define object '::cortex::math::acos(::cortex::lang::float64 x)'.");
            goto error;
        }
    }
    /* Declare ::cortex::math::asin(::cortex::lang::float64 x) */
    mth_asin_o = db_declare(mth_o, "asin(::cortex::lang::float64 x)", db_typedef(db_function_o));
    if (!mth_asin_o) {
        db_error("math_load: failed to declare object '::cortex::math::asin(::cortex::lang::float64 x)'.");
        goto error;
    }

    /* Define ::cortex::math::asin(::cortex::lang::float64 x) */
    if (!db_checkState(mth_asin_o, DB_DEFINED)) {
        mth_asin_o->returnType = db_resolve_ext(mth_asin_o, NULL, "::cortex::lang::float64", FALSE, "element ::cortex::math::asin(::cortex::lang::float64 x).returnType");
        mth_asin_o->returnsReference = FALSE;
        
        /* Bind mth_asin_o with C-function */
        db_function(mth_asin_o)->kind = DB_PROCEDURE_CDECL;
        void __mth_asin(void *args, void *result);
        db_function(mth_asin_o)->impl = (db_word)__mth_asin;
        if (db_define(mth_asin_o)) {
            db_error("math_load: failed to define object '::cortex::math::asin(::cortex::lang::float64 x)'.");
            goto error;
        }
    }
    /* Declare ::cortex::math::atan(::cortex::lang::float64 x) */
    mth_atan_o = db_declare(mth_o, "atan(::cortex::lang::float64 x)", db_typedef(db_function_o));
    if (!mth_atan_o) {
        db_error("math_load: failed to declare object '::cortex::math::atan(::cortex::lang::float64 x)'.");
        goto error;
    }

    /* Define ::cortex::math::atan(::cortex::lang::float64 x) */
    if (!db_checkState(mth_atan_o, DB_DEFINED)) {
        mth_atan_o->returnType = db_resolve_ext(mth_atan_o, NULL, "::cortex::lang::float64", FALSE, "element ::cortex::math::atan(::cortex::lang::float64 x).returnType");
        mth_atan_o->returnsReference = FALSE;
        
        /* Bind mth_atan_o with C-function */
        db_function(mth_atan_o)->kind = DB_PROCEDURE_CDECL;
        void __mth_atan(void *args, void *result);
        db_function(mth_atan_o)->impl = (db_word)__mth_atan;
        if (db_define(mth_atan_o)) {
            db_error("math_load: failed to define object '::cortex::math::atan(::cortex::lang::float64 x)'.");
            goto error;
        }
    }
    /* Declare ::cortex::math::cos(::cortex::lang::float64 x) */
    mth_cos_o = db_declare(mth_o, "cos(::cortex::lang::float64 x)", db_typedef(db_function_o));
    if (!mth_cos_o) {
        db_error("math_load: failed to declare object '::cortex::math::cos(::cortex::lang::float64 x)'.");
        goto error;
    }

    /* Define ::cortex::math::cos(::cortex::lang::float64 x) */
    if (!db_checkState(mth_cos_o, DB_DEFINED)) {
        mth_cos_o->returnType = db_resolve_ext(mth_cos_o, NULL, "::cortex::lang::float64", FALSE, "element ::cortex::math::cos(::cortex::lang::float64 x).returnType");
        mth_cos_o->returnsReference = FALSE;
        
        /* Bind mth_cos_o with C-function */
        db_function(mth_cos_o)->kind = DB_PROCEDURE_CDECL;
        void __mth_cos(void *args, void *result);
        db_function(mth_cos_o)->impl = (db_word)__mth_cos;
        if (db_define(mth_cos_o)) {
            db_error("math_load: failed to define object '::cortex::math::cos(::cortex::lang::float64 x)'.");
            goto error;
        }
    }
    /* Declare ::cortex::math::exp(::cortex::lang::float64 x) */
    mth_exp_o = db_declare(mth_o, "exp(::cortex::lang::float64 x)", db_typedef(db_function_o));
    if (!mth_exp_o) {
        db_error("math_load: failed to declare object '::cortex::math::exp(::cortex::lang::float64 x)'.");
        goto error;
    }

    /* Define ::cortex::math::exp(::cortex::lang::float64 x) */
    if (!db_checkState(mth_exp_o, DB_DEFINED)) {
        mth_exp_o->returnType = db_resolve_ext(mth_exp_o, NULL, "::cortex::lang::float64", FALSE, "element ::cortex::math::exp(::cortex::lang::float64 x).returnType");
        mth_exp_o->returnsReference = FALSE;
        
        /* Bind mth_exp_o with C-function */
        db_function(mth_exp_o)->kind = DB_PROCEDURE_CDECL;
        void __mth_exp(void *args, void *result);
        db_function(mth_exp_o)->impl = (db_word)__mth_exp;
        if (db_define(mth_exp_o)) {
            db_error("math_load: failed to define object '::cortex::math::exp(::cortex::lang::float64 x)'.");
            goto error;
        }
    }
    /* Declare ::cortex::math::log(::cortex::lang::float64 x) */
    mth_log_o = db_declare(mth_o, "log(::cortex::lang::float64 x)", db_typedef(db_function_o));
    if (!mth_log_o) {
        db_error("math_load: failed to declare object '::cortex::math::log(::cortex::lang::float64 x)'.");
        goto error;
    }

    /* Define ::cortex::math::log(::cortex::lang::float64 x) */
    if (!db_checkState(mth_log_o, DB_DEFINED)) {
        mth_log_o->returnType = db_resolve_ext(mth_log_o, NULL, "::cortex::lang::float64", FALSE, "element ::cortex::math::log(::cortex::lang::float64 x).returnType");
        mth_log_o->returnsReference = FALSE;
        
        /* Bind mth_log_o with C-function */
        db_function(mth_log_o)->kind = DB_PROCEDURE_CDECL;
        void __mth_log(void *args, void *result);
        db_function(mth_log_o)->impl = (db_word)__mth_log;
        if (db_define(mth_log_o)) {
            db_error("math_load: failed to define object '::cortex::math::log(::cortex::lang::float64 x)'.");
            goto error;
        }
    }
    /* Declare ::cortex::math::log10(::cortex::lang::float64 x) */
    mth_log10_o = db_declare(mth_o, "log10(::cortex::lang::float64 x)", db_typedef(db_function_o));
    if (!mth_log10_o) {
        db_error("math_load: failed to declare object '::cortex::math::log10(::cortex::lang::float64 x)'.");
        goto error;
    }

    /* Define ::cortex::math::log10(::cortex::lang::float64 x) */
    if (!db_checkState(mth_log10_o, DB_DEFINED)) {
        mth_log10_o->returnType = db_resolve_ext(mth_log10_o, NULL, "::cortex::lang::float64", FALSE, "element ::cortex::math::log10(::cortex::lang::float64 x).returnType");
        mth_log10_o->returnsReference = FALSE;
        
        /* Bind mth_log10_o with C-function */
        db_function(mth_log10_o)->kind = DB_PROCEDURE_CDECL;
        void __mth_log10(void *args, void *result);
        db_function(mth_log10_o)->impl = (db_word)__mth_log10;
        if (db_define(mth_log10_o)) {
            db_error("math_load: failed to define object '::cortex::math::log10(::cortex::lang::float64 x)'.");
            goto error;
        }
    }
    /* Declare ::cortex::math::pow(::cortex::lang::float64 x,::cortex::lang::float64 p) */
    mth_pow_o = db_declare(mth_o, "pow(::cortex::lang::float64 x,::cortex::lang::float64 p)", db_typedef(db_function_o));
    if (!mth_pow_o) {
        db_error("math_load: failed to declare object '::cortex::math::pow(::cortex::lang::float64 x,::cortex::lang::float64 p)'.");
        goto error;
    }

    /* Define ::cortex::math::pow(::cortex::lang::float64 x,::cortex::lang::float64 p) */
    if (!db_checkState(mth_pow_o, DB_DEFINED)) {
        mth_pow_o->returnType = db_resolve_ext(mth_pow_o, NULL, "::cortex::lang::float64", FALSE, "element ::cortex::math::pow(::cortex::lang::float64 x,::cortex::lang::float64 p).returnType");
        mth_pow_o->returnsReference = FALSE;
        
        /* Bind mth_pow_o with C-function */
        db_function(mth_pow_o)->kind = DB_PROCEDURE_CDECL;
        void __mth_pow(void *args, void *result);
        db_function(mth_pow_o)->impl = (db_word)__mth_pow;
        if (db_define(mth_pow_o)) {
            db_error("math_load: failed to define object '::cortex::math::pow(::cortex::lang::float64 x,::cortex::lang::float64 p)'.");
            goto error;
        }
    }
    /* Declare ::cortex::math::rand() */
    mth_rand_o = db_declare(mth_o, "rand()", db_typedef(db_function_o));
    if (!mth_rand_o) {
        db_error("math_load: failed to declare object '::cortex::math::rand()'.");
        goto error;
    }

    /* Define ::cortex::math::rand() */
    if (!db_checkState(mth_rand_o, DB_DEFINED)) {
        mth_rand_o->returnType = db_resolve_ext(mth_rand_o, NULL, "::cortex::lang::float64", FALSE, "element ::cortex::math::rand().returnType");
        mth_rand_o->returnsReference = FALSE;
        
        /* Bind mth_rand_o with C-function */
        db_function(mth_rand_o)->kind = DB_PROCEDURE_CDECL;
        void __mth_rand(void *args, void *result);
        db_function(mth_rand_o)->impl = (db_word)__mth_rand;
        if (db_define(mth_rand_o)) {
            db_error("math_load: failed to define object '::cortex::math::rand()'.");
            goto error;
        }
    }
    /* Declare ::cortex::math::seed(::cortex::lang::uint32 seed) */
    mth_seed_o = db_declare(mth_o, "seed(::cortex::lang::uint32 seed)", db_typedef(db_function_o));
    if (!mth_seed_o) {
        db_error("math_load: failed to declare object '::cortex::math::seed(::cortex::lang::uint32 seed)'.");
        goto error;
    }

    /* Define ::cortex::math::seed(::cortex::lang::uint32 seed) */
    if (!db_checkState(mth_seed_o, DB_DEFINED)) {
        mth_seed_o->returnType = db_resolve_ext(mth_seed_o, NULL, "::cortex::lang::void", FALSE, "element ::cortex::math::seed(::cortex::lang::uint32 seed).returnType");
        mth_seed_o->returnsReference = FALSE;
        
        /* Bind mth_seed_o with C-function */
        db_function(mth_seed_o)->kind = DB_PROCEDURE_CDECL;
        void __mth_seed(void *args, void *result);
        db_function(mth_seed_o)->impl = (db_word)__mth_seed;
        if (db_define(mth_seed_o)) {
            db_error("math_load: failed to define object '::cortex::math::seed(::cortex::lang::uint32 seed)'.");
            goto error;
        }
    }
    /* Declare ::cortex::math::sin(::cortex::lang::float64 x) */
    mth_sin_o = db_declare(mth_o, "sin(::cortex::lang::float64 x)", db_typedef(db_function_o));
    if (!mth_sin_o) {
        db_error("math_load: failed to declare object '::cortex::math::sin(::cortex::lang::float64 x)'.");
        goto error;
    }

    /* Define ::cortex::math::sin(::cortex::lang::float64 x) */
    if (!db_checkState(mth_sin_o, DB_DEFINED)) {
        mth_sin_o->returnType = db_resolve_ext(mth_sin_o, NULL, "::cortex::lang::float64", FALSE, "element ::cortex::math::sin(::cortex::lang::float64 x).returnType");
        mth_sin_o->returnsReference = FALSE;
        
        /* Bind mth_sin_o with C-function */
        db_function(mth_sin_o)->kind = DB_PROCEDURE_CDECL;
        void __mth_sin(void *args, void *result);
        db_function(mth_sin_o)->impl = (db_word)__mth_sin;
        if (db_define(mth_sin_o)) {
            db_error("math_load: failed to define object '::cortex::math::sin(::cortex::lang::float64 x)'.");
            goto error;
        }
    }
    /* Declare ::cortex::math::sqrt(::cortex::lang::float64 x) */
    mth_sqrt_o = db_declare(mth_o, "sqrt(::cortex::lang::float64 x)", db_typedef(db_function_o));
    if (!mth_sqrt_o) {
        db_error("math_load: failed to declare object '::cortex::math::sqrt(::cortex::lang::float64 x)'.");
        goto error;
    }

    /* Define ::cortex::math::sqrt(::cortex::lang::float64 x) */
    if (!db_checkState(mth_sqrt_o, DB_DEFINED)) {
        mth_sqrt_o->returnType = db_resolve_ext(mth_sqrt_o, NULL, "::cortex::lang::float64", FALSE, "element ::cortex::math::sqrt(::cortex::lang::float64 x).returnType");
        mth_sqrt_o->returnsReference = FALSE;
        
        /* Bind mth_sqrt_o with C-function */
        db_function(mth_sqrt_o)->kind = DB_PROCEDURE_CDECL;
        void __mth_sqrt(void *args, void *result);
        db_function(mth_sqrt_o)->impl = (db_word)__mth_sqrt;
        if (db_define(mth_sqrt_o)) {
            db_error("math_load: failed to define object '::cortex::math::sqrt(::cortex::lang::float64 x)'.");
            goto error;
        }
    }
    /* Declare ::cortex::math::tan(::cortex::lang::float64 x) */
    mth_tan_o = db_declare(mth_o, "tan(::cortex::lang::float64 x)", db_typedef(db_function_o));
    if (!mth_tan_o) {
        db_error("math_load: failed to declare object '::cortex::math::tan(::cortex::lang::float64 x)'.");
        goto error;
    }

    /* Define ::cortex::math::tan(::cortex::lang::float64 x) */
    if (!db_checkState(mth_tan_o, DB_DEFINED)) {
        mth_tan_o->returnType = db_resolve_ext(mth_tan_o, NULL, "::cortex::lang::float64", FALSE, "element ::cortex::math::tan(::cortex::lang::float64 x).returnType");
        mth_tan_o->returnsReference = FALSE;
        
        /* Bind mth_tan_o with C-function */
        db_function(mth_tan_o)->kind = DB_PROCEDURE_CDECL;
        void __mth_tan(void *args, void *result);
        db_function(mth_tan_o)->impl = (db_word)__mth_tan;
        if (db_define(mth_tan_o)) {
            db_error("math_load: failed to define object '::cortex::math::tan(::cortex::lang::float64 x)'.");
            goto error;
        }
    }
    if (_a_) {
        db_free(_a_);
    }

    return 0;
error:
    return -1;
}
