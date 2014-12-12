/* tc_jsonser__meta.c
 *
 * Loads objects in database.
 * This file contains generated code. Do not modify!
 */

#include "tc_jsonser__type.h"

/* Variable definitions */
db_object tc_jsonser_o;
db_bool (*tc_jsonser_bf_o);
db_bool (*tc_jsonser_bt_o);
db_float32 (*tc_jsonser_f32n_o);
db_float32 (*tc_jsonser_f32p_o);
db_float32 (*tc_jsonser_f32z_o);
db_float32 (*tc_jsonser_f64n_o);
db_float32 (*tc_jsonser_f64p_o);
db_float32 (*tc_jsonser_f64z_o);
db_int16 (*tc_jsonser_i16n_o);
db_int16 (*tc_jsonser_i16p_o);
db_int16 (*tc_jsonser_i16z_o);
db_int32 (*tc_jsonser_i32n_o);
db_int32 (*tc_jsonser_i32p_o);
db_int32 (*tc_jsonser_i32z_o);
db_int64 (*tc_jsonser_i64n_o);
db_int64 (*tc_jsonser_i64p_o);
db_int64 (*tc_jsonser_i64z_o);
db_string (*tc_jsonser_namesp_o);
db_int16 (*tc_jsonser_namesp_a_o);
db_string (*tc_jsonser_namesp_b_o);
tc_jsonser_point2D (*tc_jsonser_p_o);
db_struct tc_jsonser_point2D_o;
db_member tc_jsonser_point2D_x_o;
db_member tc_jsonser_point2D_y_o;
db_string (*tc_jsonser_s1_o);
db_string (*tc_jsonser_s2_o);
db_string (*tc_jsonser_sn_o);
db_uint16 (*tc_jsonser_u16p_o);
db_uint16 (*tc_jsonser_u16z_o);
db_uint32 (*tc_jsonser_u32p_o);
db_uint32 (*tc_jsonser_u32z_o);
db_uint64 (*tc_jsonser_u64p_o);
db_uint64 (*tc_jsonser_u64z_o);

/* Load objects in database */
int tc_jsonser_load(void) {
    db_object _a_; /* Used for resolving anonymous objects */
    _a_ = NULL;

    /* Declare ::tc_jsonser */
    tc_jsonser_o = db_declare(root_o, "tc_jsonser", db_typedef(db_object_o));
    if (!tc_jsonser_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser'.");
        goto error;
    }

    /* Define ::tc_jsonser */
    if (!db_checkState(tc_jsonser_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::bf */
    tc_jsonser_bf_o = db_declare(tc_jsonser_o, "bf", db_typedef(db_bool_o));
    if (!tc_jsonser_bf_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::bf'.");
        goto error;
    } else {
        (*tc_jsonser_bf_o) = FALSE;
    }

    /* Define ::tc_jsonser::bf */
    if (!db_checkState(tc_jsonser_bf_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_bf_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::bf'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::bt */
    tc_jsonser_bt_o = db_declare(tc_jsonser_o, "bt", db_typedef(db_bool_o));
    if (!tc_jsonser_bt_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::bt'.");
        goto error;
    } else {
        (*tc_jsonser_bt_o) = TRUE;
    }

    /* Define ::tc_jsonser::bt */
    if (!db_checkState(tc_jsonser_bt_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_bt_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::bt'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::f32n */
    tc_jsonser_f32n_o = db_declare(tc_jsonser_o, "f32n", db_typedef(db_float32_o));
    if (!tc_jsonser_f32n_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::f32n'.");
        goto error;
    } else {
        (*tc_jsonser_f32n_o) = -2.450000;
    }

    /* Define ::tc_jsonser::f32n */
    if (!db_checkState(tc_jsonser_f32n_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_f32n_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::f32n'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::f32p */
    tc_jsonser_f32p_o = db_declare(tc_jsonser_o, "f32p", db_typedef(db_float32_o));
    if (!tc_jsonser_f32p_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::f32p'.");
        goto error;
    } else {
        (*tc_jsonser_f32p_o) = 45.200001;
    }

    /* Define ::tc_jsonser::f32p */
    if (!db_checkState(tc_jsonser_f32p_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_f32p_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::f32p'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::f32z */
    tc_jsonser_f32z_o = db_declare(tc_jsonser_o, "f32z", db_typedef(db_float32_o));
    if (!tc_jsonser_f32z_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::f32z'.");
        goto error;
    } else {
        (*tc_jsonser_f32z_o) = 0.000000;
    }

    /* Define ::tc_jsonser::f32z */
    if (!db_checkState(tc_jsonser_f32z_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_f32z_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::f32z'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::f64n */
    tc_jsonser_f64n_o = db_declare(tc_jsonser_o, "f64n", db_typedef(db_float32_o));
    if (!tc_jsonser_f64n_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::f64n'.");
        goto error;
    } else {
        (*tc_jsonser_f64n_o) = -2.450000;
    }

    /* Define ::tc_jsonser::f64n */
    if (!db_checkState(tc_jsonser_f64n_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_f64n_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::f64n'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::f64p */
    tc_jsonser_f64p_o = db_declare(tc_jsonser_o, "f64p", db_typedef(db_float32_o));
    if (!tc_jsonser_f64p_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::f64p'.");
        goto error;
    } else {
        (*tc_jsonser_f64p_o) = 45.200001;
    }

    /* Define ::tc_jsonser::f64p */
    if (!db_checkState(tc_jsonser_f64p_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_f64p_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::f64p'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::f64z */
    tc_jsonser_f64z_o = db_declare(tc_jsonser_o, "f64z", db_typedef(db_float32_o));
    if (!tc_jsonser_f64z_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::f64z'.");
        goto error;
    } else {
        (*tc_jsonser_f64z_o) = 0.000000;
    }

    /* Define ::tc_jsonser::f64z */
    if (!db_checkState(tc_jsonser_f64z_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_f64z_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::f64z'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::i16n */
    tc_jsonser_i16n_o = db_declare(tc_jsonser_o, "i16n", db_typedef(db_int16_o));
    if (!tc_jsonser_i16n_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::i16n'.");
        goto error;
    } else {
        (*tc_jsonser_i16n_o) = -2;
    }

    /* Define ::tc_jsonser::i16n */
    if (!db_checkState(tc_jsonser_i16n_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_i16n_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::i16n'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::i16p */
    tc_jsonser_i16p_o = db_declare(tc_jsonser_o, "i16p", db_typedef(db_int16_o));
    if (!tc_jsonser_i16p_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::i16p'.");
        goto error;
    } else {
        (*tc_jsonser_i16p_o) = 45;
    }

    /* Define ::tc_jsonser::i16p */
    if (!db_checkState(tc_jsonser_i16p_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_i16p_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::i16p'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::i16z */
    tc_jsonser_i16z_o = db_declare(tc_jsonser_o, "i16z", db_typedef(db_int16_o));
    if (!tc_jsonser_i16z_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::i16z'.");
        goto error;
    } else {
        (*tc_jsonser_i16z_o) = 0;
    }

    /* Define ::tc_jsonser::i16z */
    if (!db_checkState(tc_jsonser_i16z_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_i16z_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::i16z'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::i32n */
    tc_jsonser_i32n_o = db_declare(tc_jsonser_o, "i32n", db_typedef(db_int32_o));
    if (!tc_jsonser_i32n_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::i32n'.");
        goto error;
    } else {
        (*tc_jsonser_i32n_o) = -2;
    }

    /* Define ::tc_jsonser::i32n */
    if (!db_checkState(tc_jsonser_i32n_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_i32n_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::i32n'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::i32p */
    tc_jsonser_i32p_o = db_declare(tc_jsonser_o, "i32p", db_typedef(db_int32_o));
    if (!tc_jsonser_i32p_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::i32p'.");
        goto error;
    } else {
        (*tc_jsonser_i32p_o) = 45;
    }

    /* Define ::tc_jsonser::i32p */
    if (!db_checkState(tc_jsonser_i32p_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_i32p_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::i32p'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::i32z */
    tc_jsonser_i32z_o = db_declare(tc_jsonser_o, "i32z", db_typedef(db_int32_o));
    if (!tc_jsonser_i32z_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::i32z'.");
        goto error;
    } else {
        (*tc_jsonser_i32z_o) = 0;
    }

    /* Define ::tc_jsonser::i32z */
    if (!db_checkState(tc_jsonser_i32z_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_i32z_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::i32z'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::i64n */
    tc_jsonser_i64n_o = db_declare(tc_jsonser_o, "i64n", db_typedef(db_int64_o));
    if (!tc_jsonser_i64n_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::i64n'.");
        goto error;
    } else {
        (*tc_jsonser_i64n_o) = -2;
    }

    /* Define ::tc_jsonser::i64n */
    if (!db_checkState(tc_jsonser_i64n_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_i64n_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::i64n'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::i64p */
    tc_jsonser_i64p_o = db_declare(tc_jsonser_o, "i64p", db_typedef(db_int64_o));
    if (!tc_jsonser_i64p_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::i64p'.");
        goto error;
    } else {
        (*tc_jsonser_i64p_o) = 45;
    }

    /* Define ::tc_jsonser::i64p */
    if (!db_checkState(tc_jsonser_i64p_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_i64p_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::i64p'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::i64z */
    tc_jsonser_i64z_o = db_declare(tc_jsonser_o, "i64z", db_typedef(db_int64_o));
    if (!tc_jsonser_i64z_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::i64z'.");
        goto error;
    } else {
        (*tc_jsonser_i64z_o) = 0;
    }

    /* Define ::tc_jsonser::i64z */
    if (!db_checkState(tc_jsonser_i64z_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_i64z_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::i64z'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::namesp */
    tc_jsonser_namesp_o = db_declare(tc_jsonser_o, "namesp", db_typedef(db_string_o));
    if (!tc_jsonser_namesp_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::namesp'.");
        goto error;
    } else {
        (*tc_jsonser_namesp_o) = db_strdup("hey");
    }

    /* Define ::tc_jsonser::namesp */
    if (!db_checkState(tc_jsonser_namesp_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_namesp_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::namesp'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::namesp::a */
    tc_jsonser_namesp_a_o = db_declare(tc_jsonser_namesp_o, "a", db_typedef(db_int16_o));
    if (!tc_jsonser_namesp_a_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::namesp::a'.");
        goto error;
    } else {
        (*tc_jsonser_namesp_a_o) = 1;
    }

    /* Define ::tc_jsonser::namesp::a */
    if (!db_checkState(tc_jsonser_namesp_a_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_namesp_a_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::namesp::a'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::namesp::b */
    tc_jsonser_namesp_b_o = db_declare(tc_jsonser_namesp_o, "b", db_typedef(db_string_o));
    if (!tc_jsonser_namesp_b_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::namesp::b'.");
        goto error;
    } else {
        (*tc_jsonser_namesp_b_o) = db_strdup("2");
    }

    /* Define ::tc_jsonser::namesp::b */
    if (!db_checkState(tc_jsonser_namesp_b_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_namesp_b_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::namesp::b'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::point2D */
    tc_jsonser_point2D_o = db_declare(tc_jsonser_o, "point2D", db_typedef(db_struct_o));
    if (!tc_jsonser_point2D_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::point2D'.");
        goto error;
    }

    /* Declare ::tc_jsonser::point2D::x */
    tc_jsonser_point2D_x_o = db_declare(tc_jsonser_point2D_o, "x", db_typedef(db_member_o));
    if (!tc_jsonser_point2D_x_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::point2D::x'.");
        goto error;
    }

    /* Define ::tc_jsonser::point2D::x */
    if (!db_checkState(tc_jsonser_point2D_x_o, DB_DEFINED)) {
        tc_jsonser_point2D_x_o->type = db_resolve_ext(tc_jsonser_point2D_x_o, NULL, "::hyve::lang::int32", FALSE, "element ::tc_jsonser::point2D::x.type");
        tc_jsonser_point2D_x_o->modifiers = 0x0;
        tc_jsonser_point2D_x_o->state = 0x6;
        tc_jsonser_point2D_x_o->weak = FALSE;
        tc_jsonser_point2D_x_o->id = 0;
        if (db_define(tc_jsonser_point2D_x_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::point2D::x'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::point2D::y */
    tc_jsonser_point2D_y_o = db_declare(tc_jsonser_point2D_o, "y", db_typedef(db_member_o));
    if (!tc_jsonser_point2D_y_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::point2D::y'.");
        goto error;
    }

    /* Define ::tc_jsonser::point2D::y */
    if (!db_checkState(tc_jsonser_point2D_y_o, DB_DEFINED)) {
        tc_jsonser_point2D_y_o->type = db_resolve_ext(tc_jsonser_point2D_y_o, NULL, "::hyve::lang::int32", FALSE, "element ::tc_jsonser::point2D::y.type");
        tc_jsonser_point2D_y_o->modifiers = 0x0;
        tc_jsonser_point2D_y_o->state = 0x6;
        tc_jsonser_point2D_y_o->weak = FALSE;
        tc_jsonser_point2D_y_o->id = 1;
        if (db_define(tc_jsonser_point2D_y_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::point2D::y'.");
            goto error;
        }
    }
    /* Define ::tc_jsonser::point2D */
    if (!db_checkState(tc_jsonser_point2D_o, DB_DEFINED)) {
        db_type(tc_jsonser_point2D_o)->defaultType = db_resolve_ext(tc_jsonser_point2D_o, NULL, "::hyve::lang::member", FALSE, "element ::tc_jsonser::point2D.defaultType");
        db_type(tc_jsonser_point2D_o)->parentType = NULL;
        db_type(tc_jsonser_point2D_o)->parentState = 0x0;
        db_interface(tc_jsonser_point2D_o)->base = NULL;
        tc_jsonser_point2D_o->baseAccess = 0x0;
        if (db_define(tc_jsonser_point2D_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::point2D'.");
            goto error;
        }
    }
    if (db_type(tc_jsonser_point2D_o)->size != sizeof(tc_jsonser_point2D)) {
        db_error("tc_jsonser_load: calculated size '%d' of type '::tc_jsonser::point2D' doesn't match C-type size '%d'", db_type(tc_jsonser_point2D_o)->size, sizeof(tc_jsonser_point2D));
    }
    /* Declare ::tc_jsonser::p */
    tc_jsonser_p_o = db_declare(tc_jsonser_o, "p", db_typedef(tc_jsonser_point2D_o));
    if (!tc_jsonser_p_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::p'.");
        goto error;
    }

    /* Define ::tc_jsonser::p */
    if (!db_checkState(tc_jsonser_p_o, DB_DEFINED)) {
        tc_jsonser_p_o->x = 3;
        tc_jsonser_p_o->y = 4;
        if (db_define(tc_jsonser_p_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::p'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::s1 */
    tc_jsonser_s1_o = db_declare(tc_jsonser_o, "s1", db_typedef(db_string_o));
    if (!tc_jsonser_s1_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::s1'.");
        goto error;
    } else {
        (*tc_jsonser_s1_o) = db_strdup("hello word");
    }

    /* Define ::tc_jsonser::s1 */
    if (!db_checkState(tc_jsonser_s1_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_s1_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::s1'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::s2 */
    tc_jsonser_s2_o = db_declare(tc_jsonser_o, "s2", db_typedef(db_string_o));
    if (!tc_jsonser_s2_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::s2'.");
        goto error;
    } else {
        (*tc_jsonser_s2_o) = db_strdup("hello, world!");
    }

    /* Define ::tc_jsonser::s2 */
    if (!db_checkState(tc_jsonser_s2_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_s2_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::s2'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::sn */
    tc_jsonser_sn_o = db_declare(tc_jsonser_o, "sn", db_typedef(db_string_o));
    if (!tc_jsonser_sn_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::sn'.");
        goto error;
    } else {
        (*tc_jsonser_sn_o) = NULL;
    }

    /* Define ::tc_jsonser::sn */
    if (!db_checkState(tc_jsonser_sn_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_sn_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::sn'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::u16p */
    tc_jsonser_u16p_o = db_declare(tc_jsonser_o, "u16p", db_typedef(db_uint16_o));
    if (!tc_jsonser_u16p_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::u16p'.");
        goto error;
    } else {
        (*tc_jsonser_u16p_o) = 45;
    }

    /* Define ::tc_jsonser::u16p */
    if (!db_checkState(tc_jsonser_u16p_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_u16p_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::u16p'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::u16z */
    tc_jsonser_u16z_o = db_declare(tc_jsonser_o, "u16z", db_typedef(db_uint16_o));
    if (!tc_jsonser_u16z_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::u16z'.");
        goto error;
    } else {
        (*tc_jsonser_u16z_o) = 0;
    }

    /* Define ::tc_jsonser::u16z */
    if (!db_checkState(tc_jsonser_u16z_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_u16z_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::u16z'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::u32p */
    tc_jsonser_u32p_o = db_declare(tc_jsonser_o, "u32p", db_typedef(db_uint32_o));
    if (!tc_jsonser_u32p_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::u32p'.");
        goto error;
    } else {
        (*tc_jsonser_u32p_o) = 45;
    }

    /* Define ::tc_jsonser::u32p */
    if (!db_checkState(tc_jsonser_u32p_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_u32p_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::u32p'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::u32z */
    tc_jsonser_u32z_o = db_declare(tc_jsonser_o, "u32z", db_typedef(db_uint32_o));
    if (!tc_jsonser_u32z_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::u32z'.");
        goto error;
    } else {
        (*tc_jsonser_u32z_o) = 0;
    }

    /* Define ::tc_jsonser::u32z */
    if (!db_checkState(tc_jsonser_u32z_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_u32z_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::u32z'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::u64p */
    tc_jsonser_u64p_o = db_declare(tc_jsonser_o, "u64p", db_typedef(db_uint64_o));
    if (!tc_jsonser_u64p_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::u64p'.");
        goto error;
    } else {
        (*tc_jsonser_u64p_o) = 45;
    }

    /* Define ::tc_jsonser::u64p */
    if (!db_checkState(tc_jsonser_u64p_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_u64p_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::u64p'.");
            goto error;
        }
    }
    /* Declare ::tc_jsonser::u64z */
    tc_jsonser_u64z_o = db_declare(tc_jsonser_o, "u64z", db_typedef(db_uint64_o));
    if (!tc_jsonser_u64z_o) {
        db_error("tc_jsonser_load: failed to declare object '::tc_jsonser::u64z'.");
        goto error;
    } else {
        (*tc_jsonser_u64z_o) = 0;
    }

    /* Define ::tc_jsonser::u64z */
    if (!db_checkState(tc_jsonser_u64z_o, DB_DEFINED)) {
        if (db_define(tc_jsonser_u64z_o)) {
            db_error("tc_jsonser_load: failed to define object '::tc_jsonser::u64z'.");
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
