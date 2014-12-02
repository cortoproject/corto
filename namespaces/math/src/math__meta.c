/* math__meta.c
 *
 * Loads objects in database.
 * This file contains generated code. Do not modify!
 */

#include "math__type.h"

/* Variable definitions */
db_object _o;
db_object math_o;
db_function math_abs_o;
db_function math_acos_o;
db_function math_asin_o;
db_function math_atan_o;
db_function math_cos_o;
db_function math_exp_o;
db_function math_log_o;
db_function math_log10_o;
db_function math_pow_o;
db_function math_rand_o;
db_function math_seed_o;
db_function math_sin_o;
db_function math_sqrt_o;
db_function math_tan_o;

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
    math_o = db_declare(_o, "math", db_typedef(db_object_o));
    if (!math_o) {
        db_error("math_load: failed to declare object '::hyve::math'.");
        goto error;
    }

    /* Define ::hyve::math */
    if (!db_checkState(math_o, DB_DEFINED)) {
        if (db_define(math_o)) {
            db_error("math_load: failed to define object '::hyve::math'.");
            goto error;
        }
    }
    /* Declare ::hyve::math::abs(::hyve::lang::uint64 x) */
    math_abs_o = db_declare(math_o, "abs(::hyve::lang::uint64 x)", db_typedef(db_function_o));
    if (!math_abs_o) {
        db_error("math_load: failed to declare object '::hyve::math::abs(::hyve::lang::uint64 x)'.");
        goto error;
    }

    /* Define ::hyve::math::abs(::hyve::lang::uint64 x) */
    if (!db_checkState(math_abs_o, DB_DEFINED)) {
        math_abs_o->returnType = db_resolve_ext(math_abs_o, NULL, "::hyve::lang::uint64", FALSE, "element ::hyve::math::abs(::hyve::lang::uint64 x).returnType");
        math_abs_o->returnsReference = FALSE;
        
        /* Bind math_abs_o with C-function */
        db_function(math_abs_o)->kind = DB_PROCEDURE_CDECL;
        void __math_abs(void *args, void *result);
        db_function(math_abs_o)->impl = (db_word)__math_abs;
        if (db_define(math_abs_o)) {
            db_error("math_load: failed to define object '::hyve::math::abs(::hyve::lang::uint64 x)'.");
            goto error;
        }
    }
    /* Declare ::hyve::math::acos(::hyve::lang::float64 x) */
    math_acos_o = db_declare(math_o, "acos(::hyve::lang::float64 x)", db_typedef(db_function_o));
    if (!math_acos_o) {
        db_error("math_load: failed to declare object '::hyve::math::acos(::hyve::lang::float64 x)'.");
        goto error;
    }

    /* Define ::hyve::math::acos(::hyve::lang::float64 x) */
    if (!db_checkState(math_acos_o, DB_DEFINED)) {
        math_acos_o->returnType = db_resolve_ext(math_acos_o, NULL, "::hyve::lang::float64", FALSE, "element ::hyve::math::acos(::hyve::lang::float64 x).returnType");
        math_acos_o->returnsReference = FALSE;
        
        /* Bind math_acos_o with C-function */
        db_function(math_acos_o)->kind = DB_PROCEDURE_CDECL;
        void __math_acos(void *args, void *result);
        db_function(math_acos_o)->impl = (db_word)__math_acos;
        if (db_define(math_acos_o)) {
            db_error("math_load: failed to define object '::hyve::math::acos(::hyve::lang::float64 x)'.");
            goto error;
        }
    }
    /* Declare ::hyve::math::asin(::hyve::lang::float64 x) */
    math_asin_o = db_declare(math_o, "asin(::hyve::lang::float64 x)", db_typedef(db_function_o));
    if (!math_asin_o) {
        db_error("math_load: failed to declare object '::hyve::math::asin(::hyve::lang::float64 x)'.");
        goto error;
    }

    /* Define ::hyve::math::asin(::hyve::lang::float64 x) */
    if (!db_checkState(math_asin_o, DB_DEFINED)) {
        math_asin_o->returnType = db_resolve_ext(math_asin_o, NULL, "::hyve::lang::float64", FALSE, "element ::hyve::math::asin(::hyve::lang::float64 x).returnType");
        math_asin_o->returnsReference = FALSE;
        
        /* Bind math_asin_o with C-function */
        db_function(math_asin_o)->kind = DB_PROCEDURE_CDECL;
        void __math_asin(void *args, void *result);
        db_function(math_asin_o)->impl = (db_word)__math_asin;
        if (db_define(math_asin_o)) {
            db_error("math_load: failed to define object '::hyve::math::asin(::hyve::lang::float64 x)'.");
            goto error;
        }
    }
    /* Declare ::hyve::math::atan(::hyve::lang::float64 x) */
    math_atan_o = db_declare(math_o, "atan(::hyve::lang::float64 x)", db_typedef(db_function_o));
    if (!math_atan_o) {
        db_error("math_load: failed to declare object '::hyve::math::atan(::hyve::lang::float64 x)'.");
        goto error;
    }

    /* Define ::hyve::math::atan(::hyve::lang::float64 x) */
    if (!db_checkState(math_atan_o, DB_DEFINED)) {
        math_atan_o->returnType = db_resolve_ext(math_atan_o, NULL, "::hyve::lang::float64", FALSE, "element ::hyve::math::atan(::hyve::lang::float64 x).returnType");
        math_atan_o->returnsReference = FALSE;
        
        /* Bind math_atan_o with C-function */
        db_function(math_atan_o)->kind = DB_PROCEDURE_CDECL;
        void __math_atan(void *args, void *result);
        db_function(math_atan_o)->impl = (db_word)__math_atan;
        if (db_define(math_atan_o)) {
            db_error("math_load: failed to define object '::hyve::math::atan(::hyve::lang::float64 x)'.");
            goto error;
        }
    }
    /* Declare ::hyve::math::cos(::hyve::lang::float64 x) */
    math_cos_o = db_declare(math_o, "cos(::hyve::lang::float64 x)", db_typedef(db_function_o));
    if (!math_cos_o) {
        db_error("math_load: failed to declare object '::hyve::math::cos(::hyve::lang::float64 x)'.");
        goto error;
    }

    /* Define ::hyve::math::cos(::hyve::lang::float64 x) */
    if (!db_checkState(math_cos_o, DB_DEFINED)) {
        math_cos_o->returnType = db_resolve_ext(math_cos_o, NULL, "::hyve::lang::float64", FALSE, "element ::hyve::math::cos(::hyve::lang::float64 x).returnType");
        math_cos_o->returnsReference = FALSE;
        
        /* Bind math_cos_o with C-function */
        db_function(math_cos_o)->kind = DB_PROCEDURE_CDECL;
        void __math_cos(void *args, void *result);
        db_function(math_cos_o)->impl = (db_word)__math_cos;
        if (db_define(math_cos_o)) {
            db_error("math_load: failed to define object '::hyve::math::cos(::hyve::lang::float64 x)'.");
            goto error;
        }
    }
    /* Declare ::hyve::math::exp(::hyve::lang::float64 x) */
    math_exp_o = db_declare(math_o, "exp(::hyve::lang::float64 x)", db_typedef(db_function_o));
    if (!math_exp_o) {
        db_error("math_load: failed to declare object '::hyve::math::exp(::hyve::lang::float64 x)'.");
        goto error;
    }

    /* Define ::hyve::math::exp(::hyve::lang::float64 x) */
    if (!db_checkState(math_exp_o, DB_DEFINED)) {
        math_exp_o->returnType = db_resolve_ext(math_exp_o, NULL, "::hyve::lang::float64", FALSE, "element ::hyve::math::exp(::hyve::lang::float64 x).returnType");
        math_exp_o->returnsReference = FALSE;
        
        /* Bind math_exp_o with C-function */
        db_function(math_exp_o)->kind = DB_PROCEDURE_CDECL;
        void __math_exp(void *args, void *result);
        db_function(math_exp_o)->impl = (db_word)__math_exp;
        if (db_define(math_exp_o)) {
            db_error("math_load: failed to define object '::hyve::math::exp(::hyve::lang::float64 x)'.");
            goto error;
        }
    }
    /* Declare ::hyve::math::log(::hyve::lang::float64 x) */
    math_log_o = db_declare(math_o, "log(::hyve::lang::float64 x)", db_typedef(db_function_o));
    if (!math_log_o) {
        db_error("math_load: failed to declare object '::hyve::math::log(::hyve::lang::float64 x)'.");
        goto error;
    }

    /* Define ::hyve::math::log(::hyve::lang::float64 x) */
    if (!db_checkState(math_log_o, DB_DEFINED)) {
        math_log_o->returnType = db_resolve_ext(math_log_o, NULL, "::hyve::lang::float64", FALSE, "element ::hyve::math::log(::hyve::lang::float64 x).returnType");
        math_log_o->returnsReference = FALSE;
        
        /* Bind math_log_o with C-function */
        db_function(math_log_o)->kind = DB_PROCEDURE_CDECL;
        void __math_log(void *args, void *result);
        db_function(math_log_o)->impl = (db_word)__math_log;
        if (db_define(math_log_o)) {
            db_error("math_load: failed to define object '::hyve::math::log(::hyve::lang::float64 x)'.");
            goto error;
        }
    }
    /* Declare ::hyve::math::log10(::hyve::lang::float64 x) */
    math_log10_o = db_declare(math_o, "log10(::hyve::lang::float64 x)", db_typedef(db_function_o));
    if (!math_log10_o) {
        db_error("math_load: failed to declare object '::hyve::math::log10(::hyve::lang::float64 x)'.");
        goto error;
    }

    /* Define ::hyve::math::log10(::hyve::lang::float64 x) */
    if (!db_checkState(math_log10_o, DB_DEFINED)) {
        math_log10_o->returnType = db_resolve_ext(math_log10_o, NULL, "::hyve::lang::float64", FALSE, "element ::hyve::math::log10(::hyve::lang::float64 x).returnType");
        math_log10_o->returnsReference = FALSE;
        
        /* Bind math_log10_o with C-function */
        db_function(math_log10_o)->kind = DB_PROCEDURE_CDECL;
        void __math_log10(void *args, void *result);
        db_function(math_log10_o)->impl = (db_word)__math_log10;
        if (db_define(math_log10_o)) {
            db_error("math_load: failed to define object '::hyve::math::log10(::hyve::lang::float64 x)'.");
            goto error;
        }
    }
    /* Declare ::hyve::math::pow(::hyve::lang::float64 x,::hyve::lang::float64 p) */
    math_pow_o = db_declare(math_o, "pow(::hyve::lang::float64 x,::hyve::lang::float64 p)", db_typedef(db_function_o));
    if (!math_pow_o) {
        db_error("math_load: failed to declare object '::hyve::math::pow(::hyve::lang::float64 x,::hyve::lang::float64 p)'.");
        goto error;
    }

    /* Define ::hyve::math::pow(::hyve::lang::float64 x,::hyve::lang::float64 p) */
    if (!db_checkState(math_pow_o, DB_DEFINED)) {
        math_pow_o->returnType = db_resolve_ext(math_pow_o, NULL, "::hyve::lang::float64", FALSE, "element ::hyve::math::pow(::hyve::lang::float64 x,::hyve::lang::float64 p).returnType");
        math_pow_o->returnsReference = FALSE;
        
        /* Bind math_pow_o with C-function */
        db_function(math_pow_o)->kind = DB_PROCEDURE_CDECL;
        void __math_pow(void *args, void *result);
        db_function(math_pow_o)->impl = (db_word)__math_pow;
        if (db_define(math_pow_o)) {
            db_error("math_load: failed to define object '::hyve::math::pow(::hyve::lang::float64 x,::hyve::lang::float64 p)'.");
            goto error;
        }
    }
    /* Declare ::hyve::math::rand() */
    math_rand_o = db_declare(math_o, "rand()", db_typedef(db_function_o));
    if (!math_rand_o) {
        db_error("math_load: failed to declare object '::hyve::math::rand()'.");
        goto error;
    }

    /* Define ::hyve::math::rand() */
    if (!db_checkState(math_rand_o, DB_DEFINED)) {
        math_rand_o->returnType = db_resolve_ext(math_rand_o, NULL, "::hyve::lang::float64", FALSE, "element ::hyve::math::rand().returnType");
        math_rand_o->returnsReference = FALSE;
        
        /* Bind math_rand_o with C-function */
        db_function(math_rand_o)->kind = DB_PROCEDURE_CDECL;
        void __math_rand(void *args, void *result);
        db_function(math_rand_o)->impl = (db_word)__math_rand;
        if (db_define(math_rand_o)) {
            db_error("math_load: failed to define object '::hyve::math::rand()'.");
            goto error;
        }
    }
    /* Declare ::hyve::math::seed(::hyve::lang::uint32 seed) */
    math_seed_o = db_declare(math_o, "seed(::hyve::lang::uint32 seed)", db_typedef(db_function_o));
    if (!math_seed_o) {
        db_error("math_load: failed to declare object '::hyve::math::seed(::hyve::lang::uint32 seed)'.");
        goto error;
    }

    /* Define ::hyve::math::seed(::hyve::lang::uint32 seed) */
    if (!db_checkState(math_seed_o, DB_DEFINED)) {
        math_seed_o->returnType = db_resolve_ext(math_seed_o, NULL, "::hyve::lang::void", FALSE, "element ::hyve::math::seed(::hyve::lang::uint32 seed).returnType");
        math_seed_o->returnsReference = FALSE;
        
        /* Bind math_seed_o with C-function */
        db_function(math_seed_o)->kind = DB_PROCEDURE_CDECL;
        void __math_seed(void *args, void *result);
        db_function(math_seed_o)->impl = (db_word)__math_seed;
        if (db_define(math_seed_o)) {
            db_error("math_load: failed to define object '::hyve::math::seed(::hyve::lang::uint32 seed)'.");
            goto error;
        }
    }
    /* Declare ::hyve::math::sin(::hyve::lang::float64 x) */
    math_sin_o = db_declare(math_o, "sin(::hyve::lang::float64 x)", db_typedef(db_function_o));
    if (!math_sin_o) {
        db_error("math_load: failed to declare object '::hyve::math::sin(::hyve::lang::float64 x)'.");
        goto error;
    }

    /* Define ::hyve::math::sin(::hyve::lang::float64 x) */
    if (!db_checkState(math_sin_o, DB_DEFINED)) {
        math_sin_o->returnType = db_resolve_ext(math_sin_o, NULL, "::hyve::lang::float64", FALSE, "element ::hyve::math::sin(::hyve::lang::float64 x).returnType");
        math_sin_o->returnsReference = FALSE;
        
        /* Bind math_sin_o with C-function */
        db_function(math_sin_o)->kind = DB_PROCEDURE_CDECL;
        void __math_sin(void *args, void *result);
        db_function(math_sin_o)->impl = (db_word)__math_sin;
        if (db_define(math_sin_o)) {
            db_error("math_load: failed to define object '::hyve::math::sin(::hyve::lang::float64 x)'.");
            goto error;
        }
    }
    /* Declare ::hyve::math::sqrt(::hyve::lang::float64 x) */
    math_sqrt_o = db_declare(math_o, "sqrt(::hyve::lang::float64 x)", db_typedef(db_function_o));
    if (!math_sqrt_o) {
        db_error("math_load: failed to declare object '::hyve::math::sqrt(::hyve::lang::float64 x)'.");
        goto error;
    }

    /* Define ::hyve::math::sqrt(::hyve::lang::float64 x) */
    if (!db_checkState(math_sqrt_o, DB_DEFINED)) {
        math_sqrt_o->returnType = db_resolve_ext(math_sqrt_o, NULL, "::hyve::lang::float64", FALSE, "element ::hyve::math::sqrt(::hyve::lang::float64 x).returnType");
        math_sqrt_o->returnsReference = FALSE;
        
        /* Bind math_sqrt_o with C-function */
        db_function(math_sqrt_o)->kind = DB_PROCEDURE_CDECL;
        void __math_sqrt(void *args, void *result);
        db_function(math_sqrt_o)->impl = (db_word)__math_sqrt;
        if (db_define(math_sqrt_o)) {
            db_error("math_load: failed to define object '::hyve::math::sqrt(::hyve::lang::float64 x)'.");
            goto error;
        }
    }
    /* Declare ::hyve::math::tan(::hyve::lang::float64 x) */
    math_tan_o = db_declare(math_o, "tan(::hyve::lang::float64 x)", db_typedef(db_function_o));
    if (!math_tan_o) {
        db_error("math_load: failed to declare object '::hyve::math::tan(::hyve::lang::float64 x)'.");
        goto error;
    }

    /* Define ::hyve::math::tan(::hyve::lang::float64 x) */
    if (!db_checkState(math_tan_o, DB_DEFINED)) {
        math_tan_o->returnType = db_resolve_ext(math_tan_o, NULL, "::hyve::lang::float64", FALSE, "element ::hyve::math::tan(::hyve::lang::float64 x).returnType");
        math_tan_o->returnsReference = FALSE;
        
        /* Bind math_tan_o with C-function */
        db_function(math_tan_o)->kind = DB_PROCEDURE_CDECL;
        void __math_tan(void *args, void *result);
        db_function(math_tan_o)->impl = (db_word)__math_tan;
        if (db_define(math_tan_o)) {
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
