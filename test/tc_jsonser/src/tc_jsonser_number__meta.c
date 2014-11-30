/* tc_jsonser_number__meta.c
 *
 *  Generated on Nov 30 2014
 *    Loads objects in database.
 *    This file contains generated code. Do not modify!
 */

#include "tc_jsonser_number__type.h"

/* Variable definitions */
db_object tc_jsonser_number_o;
db_float32 (*tc_jsonser_number_f32n_o);
db_float32 (*tc_jsonser_number_f32p_o);
db_float32 (*tc_jsonser_number_f32z_o);
db_float32 (*tc_jsonser_number_f64n_o);
db_float32 (*tc_jsonser_number_f64p_o);
db_float32 (*tc_jsonser_number_f64z_o);
db_int16 (*tc_jsonser_number_i16n_o);
db_int16 (*tc_jsonser_number_i16p_o);
db_int16 (*tc_jsonser_number_i16z_o);
db_int32 (*tc_jsonser_number_i32n_o);
db_int32 (*tc_jsonser_number_i32p_o);
db_int32 (*tc_jsonser_number_i32z_o);
db_int64 (*tc_jsonser_number_i64n_o);
db_int64 (*tc_jsonser_number_i64p_o);
db_int64 (*tc_jsonser_number_i64z_o);
db_uint16 (*tc_jsonser_number_u16p_o);
db_uint16 (*tc_jsonser_number_u16z_o);
db_uint32 (*tc_jsonser_number_u32p_o);
db_uint32 (*tc_jsonser_number_u32z_o);
db_uint64 (*tc_jsonser_number_u64p_o);
db_uint64 (*tc_jsonser_number_u64z_o);

/* Load objects in database */
int tc_jsonser_number_load(void) {
    db_object _a_; /* Used for resolving anonymous objects */
    _a_ = NULL;

    /* Declare ::tc_jsonser_number */
    tc_jsonser_number_o = db_declare(root_o, "tc_jsonser_number", db_typedef(db_object_o));
    if (!tc_jsonser_number_o) {
        db_error("tc_jsonser_number_load: failed to declare object '::tc_jsonser_number'.");
        goto error;
    }

    /* Define ::tc_jsonser_number */
    if (!db_checkState(tc_jsonser_number_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_number_o)) {
            db_error("tc_jsonser_number_load: failed to define object '::tc_jsonser_number'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser_number::f32n */
    tc_jsonser_number_f32n_o = db_declare(tc_jsonser_number_o, "f32n", db_typedef(db_float32_o));
    if (!tc_jsonser_number_f32n_o) {
        db_error("tc_jsonser_number_load: failed to declare object '::tc_jsonser_number::f32n'.");
        goto error;
    }

    /* Define ::tc_jsonser_number::f32n */
    if (!db_checkState(tc_jsonser_number_f32n_o, DB_DEFINED)) {
        (*tc_jsonser_number_f32n_o) = -2.450000;
        if (db_define(tc_jsonser_number_f32n_o)) {
            db_error("tc_jsonser_number_load: failed to define object '::tc_jsonser_number::f32n'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser_number::f32p */
    tc_jsonser_number_f32p_o = db_declare(tc_jsonser_number_o, "f32p", db_typedef(db_float32_o));
    if (!tc_jsonser_number_f32p_o) {
        db_error("tc_jsonser_number_load: failed to declare object '::tc_jsonser_number::f32p'.");
        goto error;
    }

    /* Define ::tc_jsonser_number::f32p */
    if (!db_checkState(tc_jsonser_number_f32p_o, DB_DEFINED)) {
        (*tc_jsonser_number_f32p_o) = 45.200001;
        if (db_define(tc_jsonser_number_f32p_o)) {
            db_error("tc_jsonser_number_load: failed to define object '::tc_jsonser_number::f32p'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser_number::f32z */
    tc_jsonser_number_f32z_o = db_declare(tc_jsonser_number_o, "f32z", db_typedef(db_float32_o));
    if (!tc_jsonser_number_f32z_o) {
        db_error("tc_jsonser_number_load: failed to declare object '::tc_jsonser_number::f32z'.");
        goto error;
    }

    /* Define ::tc_jsonser_number::f32z */
    if (!db_checkState(tc_jsonser_number_f32z_o, DB_DEFINED)) {
        (*tc_jsonser_number_f32z_o) = 0.000000;
        if (db_define(tc_jsonser_number_f32z_o)) {
            db_error("tc_jsonser_number_load: failed to define object '::tc_jsonser_number::f32z'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser_number::f64n */
    tc_jsonser_number_f64n_o = db_declare(tc_jsonser_number_o, "f64n", db_typedef(db_float32_o));
    if (!tc_jsonser_number_f64n_o) {
        db_error("tc_jsonser_number_load: failed to declare object '::tc_jsonser_number::f64n'.");
        goto error;
    }

    /* Define ::tc_jsonser_number::f64n */
    if (!db_checkState(tc_jsonser_number_f64n_o, DB_DEFINED)) {
        (*tc_jsonser_number_f64n_o) = -2.450000;
        if (db_define(tc_jsonser_number_f64n_o)) {
            db_error("tc_jsonser_number_load: failed to define object '::tc_jsonser_number::f64n'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser_number::f64p */
    tc_jsonser_number_f64p_o = db_declare(tc_jsonser_number_o, "f64p", db_typedef(db_float32_o));
    if (!tc_jsonser_number_f64p_o) {
        db_error("tc_jsonser_number_load: failed to declare object '::tc_jsonser_number::f64p'.");
        goto error;
    }

    /* Define ::tc_jsonser_number::f64p */
    if (!db_checkState(tc_jsonser_number_f64p_o, DB_DEFINED)) {
        (*tc_jsonser_number_f64p_o) = 45.200001;
        if (db_define(tc_jsonser_number_f64p_o)) {
            db_error("tc_jsonser_number_load: failed to define object '::tc_jsonser_number::f64p'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser_number::f64z */
    tc_jsonser_number_f64z_o = db_declare(tc_jsonser_number_o, "f64z", db_typedef(db_float32_o));
    if (!tc_jsonser_number_f64z_o) {
        db_error("tc_jsonser_number_load: failed to declare object '::tc_jsonser_number::f64z'.");
        goto error;
    }

    /* Define ::tc_jsonser_number::f64z */
    if (!db_checkState(tc_jsonser_number_f64z_o, DB_DEFINED)) {
        (*tc_jsonser_number_f64z_o) = 0.000000;
        if (db_define(tc_jsonser_number_f64z_o)) {
            db_error("tc_jsonser_number_load: failed to define object '::tc_jsonser_number::f64z'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser_number::i16n */
    tc_jsonser_number_i16n_o = db_declare(tc_jsonser_number_o, "i16n", db_typedef(db_int16_o));
    if (!tc_jsonser_number_i16n_o) {
        db_error("tc_jsonser_number_load: failed to declare object '::tc_jsonser_number::i16n'.");
        goto error;
    }

    /* Define ::tc_jsonser_number::i16n */
    if (!db_checkState(tc_jsonser_number_i16n_o, DB_DEFINED)) {
        (*tc_jsonser_number_i16n_o) = -2;
        if (db_define(tc_jsonser_number_i16n_o)) {
            db_error("tc_jsonser_number_load: failed to define object '::tc_jsonser_number::i16n'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser_number::i16p */
    tc_jsonser_number_i16p_o = db_declare(tc_jsonser_number_o, "i16p", db_typedef(db_int16_o));
    if (!tc_jsonser_number_i16p_o) {
        db_error("tc_jsonser_number_load: failed to declare object '::tc_jsonser_number::i16p'.");
        goto error;
    }

    /* Define ::tc_jsonser_number::i16p */
    if (!db_checkState(tc_jsonser_number_i16p_o, DB_DEFINED)) {
        (*tc_jsonser_number_i16p_o) = 45;
        if (db_define(tc_jsonser_number_i16p_o)) {
            db_error("tc_jsonser_number_load: failed to define object '::tc_jsonser_number::i16p'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser_number::i16z */
    tc_jsonser_number_i16z_o = db_declare(tc_jsonser_number_o, "i16z", db_typedef(db_int16_o));
    if (!tc_jsonser_number_i16z_o) {
        db_error("tc_jsonser_number_load: failed to declare object '::tc_jsonser_number::i16z'.");
        goto error;
    }

    /* Define ::tc_jsonser_number::i16z */
    if (!db_checkState(tc_jsonser_number_i16z_o, DB_DEFINED)) {
        (*tc_jsonser_number_i16z_o) = 0;
        if (db_define(tc_jsonser_number_i16z_o)) {
            db_error("tc_jsonser_number_load: failed to define object '::tc_jsonser_number::i16z'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser_number::i32n */
    tc_jsonser_number_i32n_o = db_declare(tc_jsonser_number_o, "i32n", db_typedef(db_int32_o));
    if (!tc_jsonser_number_i32n_o) {
        db_error("tc_jsonser_number_load: failed to declare object '::tc_jsonser_number::i32n'.");
        goto error;
    }

    /* Define ::tc_jsonser_number::i32n */
    if (!db_checkState(tc_jsonser_number_i32n_o, DB_DEFINED)) {
        (*tc_jsonser_number_i32n_o) = -2;
        if (db_define(tc_jsonser_number_i32n_o)) {
            db_error("tc_jsonser_number_load: failed to define object '::tc_jsonser_number::i32n'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser_number::i32p */
    tc_jsonser_number_i32p_o = db_declare(tc_jsonser_number_o, "i32p", db_typedef(db_int32_o));
    if (!tc_jsonser_number_i32p_o) {
        db_error("tc_jsonser_number_load: failed to declare object '::tc_jsonser_number::i32p'.");
        goto error;
    }

    /* Define ::tc_jsonser_number::i32p */
    if (!db_checkState(tc_jsonser_number_i32p_o, DB_DEFINED)) {
        (*tc_jsonser_number_i32p_o) = 45;
        if (db_define(tc_jsonser_number_i32p_o)) {
            db_error("tc_jsonser_number_load: failed to define object '::tc_jsonser_number::i32p'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser_number::i32z */
    tc_jsonser_number_i32z_o = db_declare(tc_jsonser_number_o, "i32z", db_typedef(db_int32_o));
    if (!tc_jsonser_number_i32z_o) {
        db_error("tc_jsonser_number_load: failed to declare object '::tc_jsonser_number::i32z'.");
        goto error;
    }

    /* Define ::tc_jsonser_number::i32z */
    if (!db_checkState(tc_jsonser_number_i32z_o, DB_DEFINED)) {
        (*tc_jsonser_number_i32z_o) = 0;
        if (db_define(tc_jsonser_number_i32z_o)) {
            db_error("tc_jsonser_number_load: failed to define object '::tc_jsonser_number::i32z'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser_number::i64n */
    tc_jsonser_number_i64n_o = db_declare(tc_jsonser_number_o, "i64n", db_typedef(db_int64_o));
    if (!tc_jsonser_number_i64n_o) {
        db_error("tc_jsonser_number_load: failed to declare object '::tc_jsonser_number::i64n'.");
        goto error;
    }

    /* Define ::tc_jsonser_number::i64n */
    if (!db_checkState(tc_jsonser_number_i64n_o, DB_DEFINED)) {
        (*tc_jsonser_number_i64n_o) = -2;
        if (db_define(tc_jsonser_number_i64n_o)) {
            db_error("tc_jsonser_number_load: failed to define object '::tc_jsonser_number::i64n'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser_number::i64p */
    tc_jsonser_number_i64p_o = db_declare(tc_jsonser_number_o, "i64p", db_typedef(db_int64_o));
    if (!tc_jsonser_number_i64p_o) {
        db_error("tc_jsonser_number_load: failed to declare object '::tc_jsonser_number::i64p'.");
        goto error;
    }

    /* Define ::tc_jsonser_number::i64p */
    if (!db_checkState(tc_jsonser_number_i64p_o, DB_DEFINED)) {
        (*tc_jsonser_number_i64p_o) = 45;
        if (db_define(tc_jsonser_number_i64p_o)) {
            db_error("tc_jsonser_number_load: failed to define object '::tc_jsonser_number::i64p'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser_number::i64z */
    tc_jsonser_number_i64z_o = db_declare(tc_jsonser_number_o, "i64z", db_typedef(db_int64_o));
    if (!tc_jsonser_number_i64z_o) {
        db_error("tc_jsonser_number_load: failed to declare object '::tc_jsonser_number::i64z'.");
        goto error;
    }

    /* Define ::tc_jsonser_number::i64z */
    if (!db_checkState(tc_jsonser_number_i64z_o, DB_DEFINED)) {
        (*tc_jsonser_number_i64z_o) = 0;
        if (db_define(tc_jsonser_number_i64z_o)) {
            db_error("tc_jsonser_number_load: failed to define object '::tc_jsonser_number::i64z'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser_number::u16p */
    tc_jsonser_number_u16p_o = db_declare(tc_jsonser_number_o, "u16p", db_typedef(db_uint16_o));
    if (!tc_jsonser_number_u16p_o) {
        db_error("tc_jsonser_number_load: failed to declare object '::tc_jsonser_number::u16p'.");
        goto error;
    }

    /* Define ::tc_jsonser_number::u16p */
    if (!db_checkState(tc_jsonser_number_u16p_o, DB_DEFINED)) {
        (*tc_jsonser_number_u16p_o) = 45;
        if (db_define(tc_jsonser_number_u16p_o)) {
            db_error("tc_jsonser_number_load: failed to define object '::tc_jsonser_number::u16p'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser_number::u16z */
    tc_jsonser_number_u16z_o = db_declare(tc_jsonser_number_o, "u16z", db_typedef(db_uint16_o));
    if (!tc_jsonser_number_u16z_o) {
        db_error("tc_jsonser_number_load: failed to declare object '::tc_jsonser_number::u16z'.");
        goto error;
    }

    /* Define ::tc_jsonser_number::u16z */
    if (!db_checkState(tc_jsonser_number_u16z_o, DB_DEFINED)) {
        (*tc_jsonser_number_u16z_o) = 0;
        if (db_define(tc_jsonser_number_u16z_o)) {
            db_error("tc_jsonser_number_load: failed to define object '::tc_jsonser_number::u16z'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser_number::u32p */
    tc_jsonser_number_u32p_o = db_declare(tc_jsonser_number_o, "u32p", db_typedef(db_uint32_o));
    if (!tc_jsonser_number_u32p_o) {
        db_error("tc_jsonser_number_load: failed to declare object '::tc_jsonser_number::u32p'.");
        goto error;
    }

    /* Define ::tc_jsonser_number::u32p */
    if (!db_checkState(tc_jsonser_number_u32p_o, DB_DEFINED)) {
        (*tc_jsonser_number_u32p_o) = 45;
        if (db_define(tc_jsonser_number_u32p_o)) {
            db_error("tc_jsonser_number_load: failed to define object '::tc_jsonser_number::u32p'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser_number::u32z */
    tc_jsonser_number_u32z_o = db_declare(tc_jsonser_number_o, "u32z", db_typedef(db_uint32_o));
    if (!tc_jsonser_number_u32z_o) {
        db_error("tc_jsonser_number_load: failed to declare object '::tc_jsonser_number::u32z'.");
        goto error;
    }

    /* Define ::tc_jsonser_number::u32z */
    if (!db_checkState(tc_jsonser_number_u32z_o, DB_DEFINED)) {
        (*tc_jsonser_number_u32z_o) = 0;
        if (db_define(tc_jsonser_number_u32z_o)) {
            db_error("tc_jsonser_number_load: failed to define object '::tc_jsonser_number::u32z'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser_number::u64p */
    tc_jsonser_number_u64p_o = db_declare(tc_jsonser_number_o, "u64p", db_typedef(db_uint64_o));
    if (!tc_jsonser_number_u64p_o) {
        db_error("tc_jsonser_number_load: failed to declare object '::tc_jsonser_number::u64p'.");
        goto error;
    }

    /* Define ::tc_jsonser_number::u64p */
    if (!db_checkState(tc_jsonser_number_u64p_o, DB_DEFINED)) {
        (*tc_jsonser_number_u64p_o) = 45;
        if (db_define(tc_jsonser_number_u64p_o)) {
            db_error("tc_jsonser_number_load: failed to define object '::tc_jsonser_number::u64p'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser_number::u64z */
    tc_jsonser_number_u64z_o = db_declare(tc_jsonser_number_o, "u64z", db_typedef(db_uint64_o));
    if (!tc_jsonser_number_u64z_o) {
        db_error("tc_jsonser_number_load: failed to declare object '::tc_jsonser_number::u64z'.");
        goto error;
    }

    /* Define ::tc_jsonser_number::u64z */
    if (!db_checkState(tc_jsonser_number_u64z_o, DB_DEFINED)) {
        (*tc_jsonser_number_u64z_o) = 0;
        if (db_define(tc_jsonser_number_u64z_o)) {
            db_error("tc_jsonser_number_load: failed to define object '::tc_jsonser_number::u64z'.");
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
