/* math__meta.c
 *
 *  Generated on Sep  5 2014
 *    Loads objects in database.
 *    This file contains generated code. Do not modify!
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

    /* Declare ::hyve */
    _o = db_declare(root_o, "hyve", db_typedef(db_object_o));
    if (!_o) {
        db_error("math_load: failed to declare object '::hyve'.");
        goto error;
    }

    /* Define ::hyve */
    if (!db_checkState(_o, DB_DEFINED)) {
        if (db_define(_o)) {
            db_error("math_load: failed to define object '::hyve'.");
            goto error;
        }
    }
    /* Declare ::hyve::math */
    mth_o = db_declare(_o, "math", db_typedef(db_object_o));
    if (!mth_o) {
        db_error("math_load: failed to declare object '::hyve::math'.");
        goto error;
    }

    /* Define ::hyve::math */
    if (!db_checkState(mth_o, DB_DEFINED)) {
        if (db_define(mth_o)) {
            db_error("math_load: failed to define object '::hyve::math'.");
            goto error;
        }
    }
    /* Declare ::hyve::math::abs(::hyve::lang::uint64 x) */
    mth_abs_o = db_declare(mth_o, "abs(::hyve::lang::uint64 x)", db_typedef(db_function_o));
    if (!mth_abs_o) {
        db_error("math_load: failed to declare object '::hyve::math::abs(::hyve::lang::uint64 x)'.");
        goto error;
    }

    /* Define ::hyve::math::abs(::hyve::lang::uint64 x) */
    if (!db_checkState(mth_abs_o, DB_DEFINED)) {
        mth_abs_o->returnType = db_resolve_ext(mth_abs_o, NULL, "::hyve::lang::uint64", FALSE, "element ::hyve::math::abs(::hyve::lang::uint64 x).returnType");
        
        /* Bind mth_abs_o with C-function */
        db_function(mth_abs_o)->kind = DB_PROCEDURE_CDECL;
        db_uint64 mth_abs(db_uint64 x);
        db_function(mth_abs_o)->impl = (db_word)mth_abs;
        if (db_define(mth_abs_o)) {
            db_error("math_load: failed to define object '::hyve::math::abs(::hyve::lang::uint64 x)'.");
            goto error;
        }
    }
    /* Declare ::hyve::math::acos(::hyve::lang::float64 x) */
    mth_acos_o = db_declare(mth_o, "acos(::hyve::lang::float64 x)", db_typedef(db_function_o));
    if (!mth_acos_o) {
        db_error("math_load: failed to declare object '::hyve::math::acos(::hyve::lang::float64 x)'.");
        goto error;
    }

    /* Define ::hyve::math::acos(::hyve::lang::float64 x) */
    if (!db_checkState(mth_acos_o, DB_DEFINED)) {
        mth_acos_o->returnType = db_resolve_ext(mth_acos_o, NULL, "::hyve::lang::float64", FALSE, "element ::hyve::math::acos(::hyve::lang::float64 x).returnType");
        
        /* Bind mth_acos_o with C-function */
        db_function(mth_acos_o)->kind = DB_PROCEDURE_CDECL;
        db_float64 mth_acos(db_float64 x);
        db_function(mth_acos_o)->impl = (db_word)mth_acos;
        if (db_define(mth_acos_o)) {
            db_error("math_load: failed to define object '::hyve::math::acos(::hyve::lang::float64 x)'.");
            goto error;
        }
    }
    /* Declare ::hyve::math::asin(::hyve::lang::float64 x) */
    mth_asin_o = db_declare(mth_o, "asin(::hyve::lang::float64 x)", db_typedef(db_function_o));
    if (!mth_asin_o) {
        db_error("math_load: failed to declare object '::hyve::math::asin(::hyve::lang::float64 x)'.");
        goto error;
    }

    /* Define ::hyve::math::asin(::hyve::lang::float64 x) */
    if (!db_checkState(mth_asin_o, DB_DEFINED)) {
        mth_asin_o->returnType = db_resolve_ext(mth_asin_o, NULL, "::hyve::lang::float64", FALSE, "element ::hyve::math::asin(::hyve::lang::float64 x).returnType");
        
        /* Bind mth_asin_o with C-function */
        db_function(mth_asin_o)->kind = DB_PROCEDURE_CDECL;
        db_float64 mth_asin(db_float64 x);
        db_function(mth_asin_o)->impl = (db_word)mth_asin;
        if (db_define(mth_asin_o)) {
            db_error("math_load: failed to define object '::hyve::math::asin(::hyve::lang::float64 x)'.");
            goto error;
        }
    }
    /* Declare ::hyve::math::atan(::hyve::lang::float64 x) */
    mth_atan_o = db_declare(mth_o, "atan(::hyve::lang::float64 x)", db_typedef(db_function_o));
    if (!mth_atan_o) {
        db_error("math_load: failed to declare object '::hyve::math::atan(::hyve::lang::float64 x)'.");
        goto error;
    }

    /* Define ::hyve::math::atan(::hyve::lang::float64 x) */
    if (!db_checkState(mth_atan_o, DB_DEFINED)) {
        mth_atan_o->returnType = db_resolve_ext(mth_atan_o, NULL, "::hyve::lang::float64", FALSE, "element ::hyve::math::atan(::hyve::lang::float64 x).returnType");
        
        /* Bind mth_atan_o with C-function */
        db_function(mth_atan_o)->kind = DB_PROCEDURE_CDECL;
        db_float64 mth_atan(db_float64 x);
        db_function(mth_atan_o)->impl = (db_word)mth_atan;
        if (db_define(mth_atan_o)) {
            db_error("math_load: failed to define object '::hyve::math::atan(::hyve::lang::float64 x)'.");
            goto error;
        }
    }
    /* Declare ::hyve::math::cos(::hyve::lang::float64 x) */
    mth_cos_o = db_declare(mth_o, "cos(::hyve::lang::float64 x)", db_typedef(db_function_o));
    if (!mth_cos_o) {
        db_error("math_load: failed to declare object '::hyve::math::cos(::hyve::lang::float64 x)'.");
        goto error;
    }

    /* Define ::hyve::math::cos(::hyve::lang::float64 x) */
    if (!db_checkState(mth_cos_o, DB_DEFINED)) {
        mth_cos_o->returnType = db_resolve_ext(mth_cos_o, NULL, "::hyve::lang::float64", FALSE, "element ::hyve::math::cos(::hyve::lang::float64 x).returnType");
        
        /* Bind mth_cos_o with C-function */
        db_function(mth_cos_o)->kind = DB_PROCEDURE_CDECL;
        db_float64 mth_cos(db_float64 x);
        db_function(mth_cos_o)->impl = (db_word)mth_cos;
        if (db_define(mth_cos_o)) {
            db_error("math_load: failed to define object '::hyve::math::cos(::hyve::lang::float64 x)'.");
            goto error;
        }
    }
    /* Declare ::hyve::math::exp(::hyve::lang::float64 x) */
    mth_exp_o = db_declare(mth_o, "exp(::hyve::lang::float64 x)", db_typedef(db_function_o));
    if (!mth_exp_o) {
        db_error("math_load: failed to declare object '::hyve::math::exp(::hyve::lang::float64 x)'.");
        goto error;
    }

    /* Define ::hyve::math::exp(::hyve::lang::float64 x) */
    if (!db_checkState(mth_exp_o, DB_DEFINED)) {
        mth_exp_o->returnType = db_resolve_ext(mth_exp_o, NULL, "::hyve::lang::float64", FALSE, "element ::hyve::math::exp(::hyve::lang::float64 x).returnType");
        
        /* Bind mth_exp_o with C-function */
        db_function(mth_exp_o)->kind = DB_PROCEDURE_CDECL;
        db_float64 mth_exp(db_float64 x);
        db_function(mth_exp_o)->impl = (db_word)mth_exp;
        if (db_define(mth_exp_o)) {
            db_error("math_load: failed to define object '::hyve::math::exp(::hyve::lang::float64 x)'.");
            goto error;
        }
    }
    /* Declare ::hyve::math::log(::hyve::lang::float64 x) */
    mth_log_o = db_declare(mth_o, "log(::hyve::lang::float64 x)", db_typedef(db_function_o));
    if (!mth_log_o) {
        db_error("math_load: failed to declare object '::hyve::math::log(::hyve::lang::float64 x)'.");
        goto error;
    }

    /* Define ::hyve::math::log(::hyve::lang::float64 x) */
    if (!db_checkState(mth_log_o, DB_DEFINED)) {
        mth_log_o->returnType = db_resolve_ext(mth_log_o, NULL, "::hyve::lang::float64", FALSE, "element ::hyve::math::log(::hyve::lang::float64 x).returnType");
        
        /* Bind mth_log_o with C-function */
        db_function(mth_log_o)->kind = DB_PROCEDURE_CDECL;
        db_float64 mth_log(db_float64 x);
        db_function(mth_log_o)->impl = (db_word)mth_log;
        if (db_define(mth_log_o)) {
            db_error("math_load: failed to define object '::hyve::math::log(::hyve::lang::float64 x)'.");
            goto error;
        }
    }
    /* Declare ::hyve::math::log10(::hyve::lang::float64 x) */
    mth_log10_o = db_declare(mth_o, "log10(::hyve::lang::float64 x)", db_typedef(db_function_o));
    if (!mth_log10_o) {
        db_error("math_load: failed to declare object '::hyve::math::log10(::hyve::lang::float64 x)'.");
        goto error;
    }

    /* Define ::hyve::math::log10(::hyve::lang::float64 x) */
    if (!db_checkState(mth_log10_o, DB_DEFINED)) {
        mth_log10_o->returnType = db_resolve_ext(mth_log10_o, NULL, "::hyve::lang::float64", FALSE, "element ::hyve::math::log10(::hyve::lang::float64 x).returnType");
        
        /* Bind mth_log10_o with C-function */
        db_function(mth_log10_o)->kind = DB_PROCEDURE_CDECL;
        db_float64 mth_log10(db_float64 x);
        db_function(mth_log10_o)->impl = (db_word)mth_log10;
        if (db_define(mth_log10_o)) {
            db_error("math_load: failed to define object '::hyve::math::log10(::hyve::lang::float64 x)'.");
            goto error;
        }
    }
    /* Declare ::hyve::math::pow(::hyve::lang::float64 x,::hyve::lang::float64 p) */
    mth_pow_o = db_declare(mth_o, "pow(::hyve::lang::float64 x,::hyve::lang::float64 p)", db_typedef(db_function_o));
    if (!mth_pow_o) {
        db_error("math_load: failed to declare object '::hyve::math::pow(::hyve::lang::float64 x,::hyve::lang::float64 p)'.");
        goto error;
    }

    /* Define ::hyve::math::pow(::hyve::lang::float64 x,::hyve::lang::float64 p) */
    if (!db_checkState(mth_pow_o, DB_DEFINED)) {
        mth_pow_o->returnType = db_resolve_ext(mth_pow_o, NULL, "::hyve::lang::float64", FALSE, "element ::hyve::math::pow(::hyve::lang::float64 x,::hyve::lang::float64 p).returnType");
        
        /* Bind mth_pow_o with C-function */
        db_function(mth_pow_o)->kind = DB_PROCEDURE_CDECL;
        db_float64 mth_pow(db_float64 x, db_float64 p);
        db_function(mth_pow_o)->impl = (db_word)mth_pow;
        if (db_define(mth_pow_o)) {
            db_error("math_load: failed to define object '::hyve::math::pow(::hyve::lang::float64 x,::hyve::lang::float64 p)'.");
            goto error;
        }
    }
    /* Declare ::hyve::math::rand() */
    mth_rand_o = db_declare(mth_o, "rand()", db_typedef(db_function_o));
    if (!mth_rand_o) {
        db_error("math_load: failed to declare object '::hyve::math::rand()'.");
        goto error;
    }

    /* Define ::hyve::math::rand() */
    if (!db_checkState(mth_rand_o, DB_DEFINED)) {
        mth_rand_o->returnType = db_resolve_ext(mth_rand_o, NULL, "::hyve::lang::float64", FALSE, "element ::hyve::math::rand().returnType");
        
        /* Bind mth_rand_o with C-function */
        db_function(mth_rand_o)->kind = DB_PROCEDURE_CDECL;
        db_float64 mth_rand(void);
        db_function(mth_rand_o)->impl = (db_word)mth_rand;
        if (db_define(mth_rand_o)) {
            db_error("math_load: failed to define object '::hyve::math::rand()'.");
            goto error;
        }
    }
    /* Declare ::hyve::math::seed(::hyve::lang::uint32 seed) */
    mth_seed_o = db_declare(mth_o, "seed(::hyve::lang::uint32 seed)", db_typedef(db_function_o));
    if (!mth_seed_o) {
        db_error("math_load: failed to declare object '::hyve::math::seed(::hyve::lang::uint32 seed)'.");
        goto error;
    }

    /* Define ::hyve::math::seed(::hyve::lang::uint32 seed) */
    if (!db_checkState(mth_seed_o, DB_DEFINED)) {
        mth_seed_o->returnType = db_resolve_ext(mth_seed_o, NULL, "::hyve::lang::void", FALSE, "element ::hyve::math::seed(::hyve::lang::uint32 seed).returnType");
        
        /* Bind mth_seed_o with C-function */
        db_function(mth_seed_o)->kind = DB_PROCEDURE_CDECL;
        db_void mth_seed(db_uint32 seed);
        db_function(mth_seed_o)->impl = (db_word)mth_seed;
        if (db_define(mth_seed_o)) {
            db_error("math_load: failed to define object '::hyve::math::seed(::hyve::lang::uint32 seed)'.");
            goto error;
        }
    }
    /* Declare ::hyve::math::sin(::hyve::lang::float64 x) */
    mth_sin_o = db_declare(mth_o, "sin(::hyve::lang::float64 x)", db_typedef(db_function_o));
    if (!mth_sin_o) {
        db_error("math_load: failed to declare object '::hyve::math::sin(::hyve::lang::float64 x)'.");
        goto error;
    }

    /* Define ::hyve::math::sin(::hyve::lang::float64 x) */
    if (!db_checkState(mth_sin_o, DB_DEFINED)) {
        mth_sin_o->returnType = db_resolve_ext(mth_sin_o, NULL, "::hyve::lang::float64", FALSE, "element ::hyve::math::sin(::hyve::lang::float64 x).returnType");
        
        /* Bind mth_sin_o with C-function */
        db_function(mth_sin_o)->kind = DB_PROCEDURE_CDECL;
        db_float64 mth_sin(db_float64 x);
        db_function(mth_sin_o)->impl = (db_word)mth_sin;
        if (db_define(mth_sin_o)) {
            db_error("math_load: failed to define object '::hyve::math::sin(::hyve::lang::float64 x)'.");
            goto error;
        }
    }
    /* Declare ::hyve::math::sqrt(::hyve::lang::float64 x) */
    mth_sqrt_o = db_declare(mth_o, "sqrt(::hyve::lang::float64 x)", db_typedef(db_function_o));
    if (!mth_sqrt_o) {
        db_error("math_load: failed to declare object '::hyve::math::sqrt(::hyve::lang::float64 x)'.");
        goto error;
    }

    /* Define ::hyve::math::sqrt(::hyve::lang::float64 x) */
    if (!db_checkState(mth_sqrt_o, DB_DEFINED)) {
        mth_sqrt_o->returnType = db_resolve_ext(mth_sqrt_o, NULL, "::hyve::lang::float64", FALSE, "element ::hyve::math::sqrt(::hyve::lang::float64 x).returnType");
        
        /* Bind mth_sqrt_o with C-function */
        db_function(mth_sqrt_o)->kind = DB_PROCEDURE_CDECL;
        db_float64 mth_sqrt(db_float64 x);
        db_function(mth_sqrt_o)->impl = (db_word)mth_sqrt;
        if (db_define(mth_sqrt_o)) {
            db_error("math_load: failed to define object '::hyve::math::sqrt(::hyve::lang::float64 x)'.");
            goto error;
        }
    }
    /* Declare ::hyve::math::tan(::hyve::lang::float64 x) */
    mth_tan_o = db_declare(mth_o, "tan(::hyve::lang::float64 x)", db_typedef(db_function_o));
    if (!mth_tan_o) {
        db_error("math_load: failed to declare object '::hyve::math::tan(::hyve::lang::float64 x)'.");
        goto error;
    }

    /* Define ::hyve::math::tan(::hyve::lang::float64 x) */
    if (!db_checkState(mth_tan_o, DB_DEFINED)) {
        mth_tan_o->returnType = db_resolve_ext(mth_tan_o, NULL, "::hyve::lang::float64", FALSE, "element ::hyve::math::tan(::hyve::lang::float64 x).returnType");
        
        /* Bind mth_tan_o with C-function */
        db_function(mth_tan_o)->kind = DB_PROCEDURE_CDECL;
        db_float64 mth_tan(db_float64 x);
        db_function(mth_tan_o)->impl = (db_word)mth_tan;
        if (db_define(mth_tan_o)) {
            db_error("math_load: failed to define object '::hyve::math::tan(::hyve::lang::float64 x)'.");
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
