/* fixture__meta.c
 *
 * Loads objects in database.
 * This file contains generated code. Do not modify!
 */

#include "fixture__type.h"

/* Variable definitions */
db_object fixture_o;
db_bool (*fixture_bf_o);
fixture_color (*fixture_black_o);
db_bool (*fixture_bt_o);
db_char (*fixture_c1_o);
db_char (*fixture_c2_o);
db_char (*fixture_c3_o);
db_char (*fixture_c4_o);
db_char (*fixture_c5_o);
db_bitmask fixture_color_o;
db_constant (*fixture_color_blue_o);
db_constant (*fixture_color_green_o);
db_constant (*fixture_color_red_o);
db_enum fixture_Djinn_o;
db_constant (*fixture_Djinn_Jupiter_o);
db_constant (*fixture_Djinn_Mars_o);
db_constant (*fixture_Djinn_Mercury_o);
db_constant (*fixture_Djinn_Venus_o);
db_class fixture_Dog_o;
db_member fixture_Dog_age_o;
db_member fixture_Dog_breed_o;
db_member fixture_Dog_lover_o;
db_member fixture_Dog_name_o;
fixture_Dog fixture_dog1_o;
fixture_Dog fixture_dog2_o;
fixture_Dog fixture_dog3_o;
db_enum fixture_DogBreed_o;
db_constant (*fixture_DogBreed_Chihuahua_o);
db_constant (*fixture_DogBreed_GoldenRetriever_o);
db_constant (*fixture_DogBreed_Pug_o);
db_float32 (*fixture_f32n_o);
db_float32 (*fixture_f32p_o);
db_float32 (*fixture_f32z_o);
db_float64 (*fixture_f64n_o);
db_float64 (*fixture_f64p_o);
db_float64 (*fixture_f64z_o);
fixture_Djinn (*fixture_Flint_o);
fixture_Djinn (*fixture_Forge_o);
fixture_Djinn (*fixture_Gust_o);
db_int16 (*fixture_i16n_o);
db_int16 (*fixture_i16p_o);
db_int16 (*fixture_i16z_o);
db_int32 (*fixture_i32n_o);
db_int32 (*fixture_i32p_o);
db_int32 (*fixture_i32z_o);
db_int64 (*fixture_i64n_o);
db_int64 (*fixture_i64p_o);
db_int64 (*fixture_i64z_o);
db_int8 (*fixture_i8n_o);
db_int8 (*fixture_i8p_o);
db_int8 (*fixture_i8z_o);
db_array fixture_ints_o;
fixture_ints (*fixture_myarray_o);
db_void (*fixture_namesp_o);
db_int16 (*fixture_namesp_a_o);
db_string (*fixture_namesp_b_o);
fixture_point2D (*fixture_p_o);
db_struct fixture_point2D_o;
db_member fixture_point2D_x_o;
db_member fixture_point2D_y_o;
db_string (*fixture_s1_o);
db_string (*fixture_s10_o);
db_string (*fixture_s11_o);
db_string (*fixture_s12_o);
db_string (*fixture_s13_o);
db_string (*fixture_s14_o);
db_string (*fixture_s2_o);
db_string (*fixture_s3_o);
db_string (*fixture_s4_o);
db_string (*fixture_s5_o);
db_string (*fixture_s6_o);
db_string (*fixture_s7_o);
db_string (*fixture_s8_o);
db_string (*fixture_s9_o);
fixture_Djinn (*fixture_Sleet_o);
db_string (*fixture_sn_o);
db_uint16 (*fixture_u16p_o);
db_uint16 (*fixture_u16z_o);
db_uint32 (*fixture_u32p_o);
db_uint32 (*fixture_u32z_o);
db_uint64 (*fixture_u64p_o);
db_uint64 (*fixture_u64z_o);
db_uint8 (*fixture_u8p_o);
db_uint8 (*fixture_u8z_o);
db_void (*fixture_v0_o);
fixture_Dog fixture_v0_dog1_o;
db_void (*fixture_v1_o);
db_void (*fixture_v1_v1_o);
db_void (*fixture_v1_v1_v1_o);
db_void (*fixture_v1_v1_v2_o);
db_void (*fixture_v1_v1_v3_o);
db_void (*fixture_v1_v1_v4_o);
db_void (*fixture_v1_v2_o);
db_void (*fixture_v1_v2_v1_o);
db_void (*fixture_v1_v2_v2_o);
db_void (*fixture_v1_v2_v3_o);
db_void (*fixture_v1_v2_v4_o);
db_void (*fixture_v1_v2_v5_o);
db_void (*fixture_v1_v3_o);
db_void (*fixture_v1_v3_v1_o);
db_void (*fixture_v1_v3_v2_o);
db_void (*fixture_v1_v3_v3_o);
db_void (*fixture_v1_v3_v4_o);
db_void (*fixture_v1_v3_v5_o);
db_void (*fixture_v1_v3_v6_o);
fixture_color (*fixture_white_o);
fixture_color (*fixture_yellow_o);

/* Load objects in database */
int fixture_load(void) {
    db_object _a_; /* Used for resolving anonymous objects */
    _a_ = NULL;

    /* Declare ::fixture */
    fixture_o = db_declare(root_o, "fixture", db_typedef(db_object_o));
    if (!fixture_o) {
        db_error("fixture_load: failed to declare object '::fixture'.");
        goto error;
    }

    /* Define ::fixture */
    if (!db_checkState(fixture_o, DB_DEFINED)) {
        if (db_define(fixture_o)) {
            db_error("fixture_load: failed to define object '::fixture'.");
            goto error;
        }
    }

    /* Declare ::fixture::bf */
    fixture_bf_o = db_declare(fixture_o, "bf", db_typedef(db_bool_o));
    if (!fixture_bf_o) {
        db_error("fixture_load: failed to declare object '::fixture::bf'.");
        goto error;
    } else {
        (*fixture_bf_o) = FALSE;
    }

    /* Declare ::fixture::bt */
    fixture_bt_o = db_declare(fixture_o, "bt", db_typedef(db_bool_o));
    if (!fixture_bt_o) {
        db_error("fixture_load: failed to declare object '::fixture::bt'.");
        goto error;
    } else {
        (*fixture_bt_o) = TRUE;
    }

    /* Declare ::fixture::c1 */
    fixture_c1_o = db_declare(fixture_o, "c1", db_typedef(db_char_o));
    if (!fixture_c1_o) {
        db_error("fixture_load: failed to declare object '::fixture::c1'.");
        goto error;
    } else {
        (*fixture_c1_o) = 'a';
    }

    /* Declare ::fixture::c2 */
    fixture_c2_o = db_declare(fixture_o, "c2", db_typedef(db_char_o));
    if (!fixture_c2_o) {
        db_error("fixture_load: failed to declare object '::fixture::c2'.");
        goto error;
    } else {
        (*fixture_c2_o) = 'A';
    }

    /* Declare ::fixture::c3 */
    fixture_c3_o = db_declare(fixture_o, "c3", db_typedef(db_char_o));
    if (!fixture_c3_o) {
        db_error("fixture_load: failed to declare object '::fixture::c3'.");
        goto error;
    } else {
        (*fixture_c3_o) = '0';
    }

    /* Declare ::fixture::c4 */
    fixture_c4_o = db_declare(fixture_o, "c4", db_typedef(db_char_o));
    if (!fixture_c4_o) {
        db_error("fixture_load: failed to declare object '::fixture::c4'.");
        goto error;
    } else {
        (*fixture_c4_o) = '\n';
    }

    /* Declare ::fixture::c5 */
    fixture_c5_o = db_declare(fixture_o, "c5", db_typedef(db_char_o));
    if (!fixture_c5_o) {
        db_error("fixture_load: failed to declare object '::fixture::c5'.");
        goto error;
    } else {
        (*fixture_c5_o) = '\0';
    }

    /* Declare ::fixture::color */
    fixture_color_o = db_declare(fixture_o, "color", db_typedef(db_bitmask_o));
    if (!fixture_color_o) {
        db_error("fixture_load: failed to declare object '::fixture::color'.");
        goto error;
    }

    /* Declare ::fixture::color::blue */
    fixture_color_blue_o = db_declare(fixture_color_o, "blue", db_typedef(db_constant_o));
    if (!fixture_color_blue_o) {
        db_error("fixture_load: failed to declare object '::fixture::color::blue'.");
        goto error;
    } else {
        (*fixture_color_blue_o) = 4;
    }

    /* Declare ::fixture::color::green */
    fixture_color_green_o = db_declare(fixture_color_o, "green", db_typedef(db_constant_o));
    if (!fixture_color_green_o) {
        db_error("fixture_load: failed to declare object '::fixture::color::green'.");
        goto error;
    } else {
        (*fixture_color_green_o) = 2;
    }

    /* Declare ::fixture::color::red */
    fixture_color_red_o = db_declare(fixture_color_o, "red", db_typedef(db_constant_o));
    if (!fixture_color_red_o) {
        db_error("fixture_load: failed to declare object '::fixture::color::red'.");
        goto error;
    } else {
        (*fixture_color_red_o) = 1;
    }

    /* Define ::fixture::color */
    if (!db_checkState(fixture_color_o, DB_DEFINED)) {
        if (db_define(fixture_color_o)) {
            db_error("fixture_load: failed to define object '::fixture::color'.");
            goto error;
        }
    }

    if (db_type(fixture_color_o)->size != sizeof(fixture_color)) {
        db_error("fixture_load: calculated size '%d' of type '::fixture::color' doesn't match C-type size '%d'", db_type(fixture_color_o)->size, sizeof(fixture_color));
    }

    /* Declare ::fixture::black */
    fixture_black_o = db_declare(fixture_o, "black", db_typedef(fixture_color_o));
    if (!fixture_black_o) {
        db_error("fixture_load: failed to declare object '::fixture::black'.");
        goto error;
    } else {
        (*fixture_black_o) = 0x0;
    }

    /* Declare ::fixture::white */
    fixture_white_o = db_declare(fixture_o, "white", db_typedef(fixture_color_o));
    if (!fixture_white_o) {
        db_error("fixture_load: failed to declare object '::fixture::white'.");
        goto error;
    } else {
        (*fixture_white_o) = 0x7;
    }

    /* Declare ::fixture::yellow */
    fixture_yellow_o = db_declare(fixture_o, "yellow", db_typedef(fixture_color_o));
    if (!fixture_yellow_o) {
        db_error("fixture_load: failed to declare object '::fixture::yellow'.");
        goto error;
    } else {
        (*fixture_yellow_o) = 0x3;
    }

    /* Declare ::fixture::Djinn */
    fixture_Djinn_o = db_declare(fixture_o, "Djinn", db_typedef(db_enum_o));
    if (!fixture_Djinn_o) {
        db_error("fixture_load: failed to declare object '::fixture::Djinn'.");
        goto error;
    }

    /* Declare ::fixture::Djinn::Jupiter */
    fixture_Djinn_Jupiter_o = db_declare(fixture_Djinn_o, "Jupiter", db_typedef(db_constant_o));
    if (!fixture_Djinn_Jupiter_o) {
        db_error("fixture_load: failed to declare object '::fixture::Djinn::Jupiter'.");
        goto error;
    } else {
        (*fixture_Djinn_Jupiter_o) = 3;
    }

    /* Declare ::fixture::Djinn::Mars */
    fixture_Djinn_Mars_o = db_declare(fixture_Djinn_o, "Mars", db_typedef(db_constant_o));
    if (!fixture_Djinn_Mars_o) {
        db_error("fixture_load: failed to declare object '::fixture::Djinn::Mars'.");
        goto error;
    } else {
        (*fixture_Djinn_Mars_o) = 2;
    }

    /* Declare ::fixture::Djinn::Mercury */
    fixture_Djinn_Mercury_o = db_declare(fixture_Djinn_o, "Mercury", db_typedef(db_constant_o));
    if (!fixture_Djinn_Mercury_o) {
        db_error("fixture_load: failed to declare object '::fixture::Djinn::Mercury'.");
        goto error;
    } else {
        (*fixture_Djinn_Mercury_o) = 0;
    }

    /* Declare ::fixture::Djinn::Venus */
    fixture_Djinn_Venus_o = db_declare(fixture_Djinn_o, "Venus", db_typedef(db_constant_o));
    if (!fixture_Djinn_Venus_o) {
        db_error("fixture_load: failed to declare object '::fixture::Djinn::Venus'.");
        goto error;
    } else {
        (*fixture_Djinn_Venus_o) = 1;
    }

    /* Define ::fixture::Djinn */
    if (!db_checkState(fixture_Djinn_o, DB_DEFINED)) {
        if (db_define(fixture_Djinn_o)) {
            db_error("fixture_load: failed to define object '::fixture::Djinn'.");
            goto error;
        }
    }

    if (db_type(fixture_Djinn_o)->size != sizeof(fixture_Djinn)) {
        db_error("fixture_load: calculated size '%d' of type '::fixture::Djinn' doesn't match C-type size '%d'", db_type(fixture_Djinn_o)->size, sizeof(fixture_Djinn));
    }

    /* Declare ::fixture::Flint */
    fixture_Flint_o = db_declare(fixture_o, "Flint", db_typedef(fixture_Djinn_o));
    if (!fixture_Flint_o) {
        db_error("fixture_load: failed to declare object '::fixture::Flint'.");
        goto error;
    } else {
        (*fixture_Flint_o) = FIXTURE_Venus;
    }

    /* Declare ::fixture::Forge */
    fixture_Forge_o = db_declare(fixture_o, "Forge", db_typedef(fixture_Djinn_o));
    if (!fixture_Forge_o) {
        db_error("fixture_load: failed to declare object '::fixture::Forge'.");
        goto error;
    } else {
        (*fixture_Forge_o) = FIXTURE_Mars;
    }

    /* Declare ::fixture::Gust */
    fixture_Gust_o = db_declare(fixture_o, "Gust", db_typedef(fixture_Djinn_o));
    if (!fixture_Gust_o) {
        db_error("fixture_load: failed to declare object '::fixture::Gust'.");
        goto error;
    } else {
        (*fixture_Gust_o) = FIXTURE_Jupiter;
    }

    /* Declare ::fixture::Sleet */
    fixture_Sleet_o = db_declare(fixture_o, "Sleet", db_typedef(fixture_Djinn_o));
    if (!fixture_Sleet_o) {
        db_error("fixture_load: failed to declare object '::fixture::Sleet'.");
        goto error;
    } else {
        (*fixture_Sleet_o) = FIXTURE_Mercury;
    }

    /* Declare ::fixture::Dog */
    fixture_Dog_o = db_declare(fixture_o, "Dog", db_typedef(db_class_o));
    if (!fixture_Dog_o) {
        db_error("fixture_load: failed to declare object '::fixture::Dog'.");
        goto error;
    }

    /* Declare ::fixture::Dog::age */
    fixture_Dog_age_o = db_declare(fixture_Dog_o, "age", db_typedef(db_member_o));
    if (!fixture_Dog_age_o) {
        db_error("fixture_load: failed to declare object '::fixture::Dog::age'.");
        goto error;
    }

    /* Define ::fixture::Dog::age */
    if (!db_checkState(fixture_Dog_age_o, DB_DEFINED)) {
        fixture_Dog_age_o->type = db_resolve_ext(fixture_Dog_age_o, NULL, "::hyve::lang::uint8", FALSE, "element ::fixture::Dog::age.type");
        fixture_Dog_age_o->modifiers = 0x0;
        fixture_Dog_age_o->state = 0x6;
        fixture_Dog_age_o->weak = FALSE;
        fixture_Dog_age_o->id = 2;
        if (db_define(fixture_Dog_age_o)) {
            db_error("fixture_load: failed to define object '::fixture::Dog::age'.");
            goto error;
        }
    }

    /* Declare ::fixture::Dog::breed */
    fixture_Dog_breed_o = db_declare(fixture_Dog_o, "breed", db_typedef(db_member_o));
    if (!fixture_Dog_breed_o) {
        db_error("fixture_load: failed to declare object '::fixture::Dog::breed'.");
        goto error;
    }

    /* Declare ::fixture::Dog::lover */
    fixture_Dog_lover_o = db_declare(fixture_Dog_o, "lover", db_typedef(db_member_o));
    if (!fixture_Dog_lover_o) {
        db_error("fixture_load: failed to declare object '::fixture::Dog::lover'.");
        goto error;
    }

    /* Declare ::fixture::Dog::name */
    fixture_Dog_name_o = db_declare(fixture_Dog_o, "name", db_typedef(db_member_o));
    if (!fixture_Dog_name_o) {
        db_error("fixture_load: failed to declare object '::fixture::Dog::name'.");
        goto error;
    }

    /* Define ::fixture::Dog::name */
    if (!db_checkState(fixture_Dog_name_o, DB_DEFINED)) {
        fixture_Dog_name_o->type = db_resolve_ext(fixture_Dog_name_o, NULL, "::hyve::lang::string", FALSE, "element ::fixture::Dog::name.type");
        fixture_Dog_name_o->modifiers = 0x0;
        fixture_Dog_name_o->state = 0x6;
        fixture_Dog_name_o->weak = FALSE;
        fixture_Dog_name_o->id = 1;
        if (db_define(fixture_Dog_name_o)) {
            db_error("fixture_load: failed to define object '::fixture::Dog::name'.");
            goto error;
        }
    }

    /* Declare ::fixture::DogBreed */
    fixture_DogBreed_o = db_declare(fixture_o, "DogBreed", db_typedef(db_enum_o));
    if (!fixture_DogBreed_o) {
        db_error("fixture_load: failed to declare object '::fixture::DogBreed'.");
        goto error;
    }

    /* Declare ::fixture::DogBreed::Chihuahua */
    fixture_DogBreed_Chihuahua_o = db_declare(fixture_DogBreed_o, "Chihuahua", db_typedef(db_constant_o));
    if (!fixture_DogBreed_Chihuahua_o) {
        db_error("fixture_load: failed to declare object '::fixture::DogBreed::Chihuahua'.");
        goto error;
    } else {
        (*fixture_DogBreed_Chihuahua_o) = 2;
    }

    /* Declare ::fixture::DogBreed::GoldenRetriever */
    fixture_DogBreed_GoldenRetriever_o = db_declare(fixture_DogBreed_o, "GoldenRetriever", db_typedef(db_constant_o));
    if (!fixture_DogBreed_GoldenRetriever_o) {
        db_error("fixture_load: failed to declare object '::fixture::DogBreed::GoldenRetriever'.");
        goto error;
    } else {
        (*fixture_DogBreed_GoldenRetriever_o) = 0;
    }

    /* Declare ::fixture::DogBreed::Pug */
    fixture_DogBreed_Pug_o = db_declare(fixture_DogBreed_o, "Pug", db_typedef(db_constant_o));
    if (!fixture_DogBreed_Pug_o) {
        db_error("fixture_load: failed to declare object '::fixture::DogBreed::Pug'.");
        goto error;
    } else {
        (*fixture_DogBreed_Pug_o) = 1;
    }

    /* Define ::fixture::DogBreed */
    if (!db_checkState(fixture_DogBreed_o, DB_DEFINED)) {
        if (db_define(fixture_DogBreed_o)) {
            db_error("fixture_load: failed to define object '::fixture::DogBreed'.");
            goto error;
        }
    }

    if (db_type(fixture_DogBreed_o)->size != sizeof(fixture_DogBreed)) {
        db_error("fixture_load: calculated size '%d' of type '::fixture::DogBreed' doesn't match C-type size '%d'", db_type(fixture_DogBreed_o)->size, sizeof(fixture_DogBreed));
    }

    /* Define ::fixture::Dog::breed */
    if (!db_checkState(fixture_Dog_breed_o, DB_DEFINED)) {
        fixture_Dog_breed_o->type = db_resolve_ext(fixture_Dog_breed_o, NULL, "::fixture::DogBreed", FALSE, "element ::fixture::Dog::breed.type");
        fixture_Dog_breed_o->modifiers = 0x0;
        fixture_Dog_breed_o->state = 0x6;
        fixture_Dog_breed_o->weak = FALSE;
        fixture_Dog_breed_o->id = 0;
        if (db_define(fixture_Dog_breed_o)) {
            db_error("fixture_load: failed to define object '::fixture::Dog::breed'.");
            goto error;
        }
    }

    /* Declare ::fixture::f32n */
    fixture_f32n_o = db_declare(fixture_o, "f32n", db_typedef(db_float32_o));
    if (!fixture_f32n_o) {
        db_error("fixture_load: failed to declare object '::fixture::f32n'.");
        goto error;
    } else {
        (*fixture_f32n_o) = -2.450000;
    }

    /* Declare ::fixture::f32p */
    fixture_f32p_o = db_declare(fixture_o, "f32p", db_typedef(db_float32_o));
    if (!fixture_f32p_o) {
        db_error("fixture_load: failed to declare object '::fixture::f32p'.");
        goto error;
    } else {
        (*fixture_f32p_o) = 45.200001;
    }

    /* Declare ::fixture::f32z */
    fixture_f32z_o = db_declare(fixture_o, "f32z", db_typedef(db_float32_o));
    if (!fixture_f32z_o) {
        db_error("fixture_load: failed to declare object '::fixture::f32z'.");
        goto error;
    } else {
        (*fixture_f32z_o) = 0.000000;
    }

    /* Declare ::fixture::f64n */
    fixture_f64n_o = db_declare(fixture_o, "f64n", db_typedef(db_float64_o));
    if (!fixture_f64n_o) {
        db_error("fixture_load: failed to declare object '::fixture::f64n'.");
        goto error;
    } else {
        (*fixture_f64n_o) = -2.450000;
    }

    /* Declare ::fixture::f64p */
    fixture_f64p_o = db_declare(fixture_o, "f64p", db_typedef(db_float64_o));
    if (!fixture_f64p_o) {
        db_error("fixture_load: failed to declare object '::fixture::f64p'.");
        goto error;
    } else {
        (*fixture_f64p_o) = 45.200000;
    }

    /* Declare ::fixture::f64z */
    fixture_f64z_o = db_declare(fixture_o, "f64z", db_typedef(db_float64_o));
    if (!fixture_f64z_o) {
        db_error("fixture_load: failed to declare object '::fixture::f64z'.");
        goto error;
    } else {
        (*fixture_f64z_o) = 0.000000;
    }

    /* Declare ::fixture::i16n */
    fixture_i16n_o = db_declare(fixture_o, "i16n", db_typedef(db_int16_o));
    if (!fixture_i16n_o) {
        db_error("fixture_load: failed to declare object '::fixture::i16n'.");
        goto error;
    } else {
        (*fixture_i16n_o) = -2;
    }

    /* Declare ::fixture::i16p */
    fixture_i16p_o = db_declare(fixture_o, "i16p", db_typedef(db_int16_o));
    if (!fixture_i16p_o) {
        db_error("fixture_load: failed to declare object '::fixture::i16p'.");
        goto error;
    } else {
        (*fixture_i16p_o) = 45;
    }

    /* Declare ::fixture::i16z */
    fixture_i16z_o = db_declare(fixture_o, "i16z", db_typedef(db_int16_o));
    if (!fixture_i16z_o) {
        db_error("fixture_load: failed to declare object '::fixture::i16z'.");
        goto error;
    } else {
        (*fixture_i16z_o) = 0;
    }

    /* Declare ::fixture::i32n */
    fixture_i32n_o = db_declare(fixture_o, "i32n", db_typedef(db_int32_o));
    if (!fixture_i32n_o) {
        db_error("fixture_load: failed to declare object '::fixture::i32n'.");
        goto error;
    } else {
        (*fixture_i32n_o) = -2;
    }

    /* Declare ::fixture::i32p */
    fixture_i32p_o = db_declare(fixture_o, "i32p", db_typedef(db_int32_o));
    if (!fixture_i32p_o) {
        db_error("fixture_load: failed to declare object '::fixture::i32p'.");
        goto error;
    } else {
        (*fixture_i32p_o) = 45;
    }

    /* Declare ::fixture::i32z */
    fixture_i32z_o = db_declare(fixture_o, "i32z", db_typedef(db_int32_o));
    if (!fixture_i32z_o) {
        db_error("fixture_load: failed to declare object '::fixture::i32z'.");
        goto error;
    } else {
        (*fixture_i32z_o) = 0;
    }

    /* Declare ::fixture::i64n */
    fixture_i64n_o = db_declare(fixture_o, "i64n", db_typedef(db_int64_o));
    if (!fixture_i64n_o) {
        db_error("fixture_load: failed to declare object '::fixture::i64n'.");
        goto error;
    } else {
        (*fixture_i64n_o) = -2;
    }

    /* Declare ::fixture::i64p */
    fixture_i64p_o = db_declare(fixture_o, "i64p", db_typedef(db_int64_o));
    if (!fixture_i64p_o) {
        db_error("fixture_load: failed to declare object '::fixture::i64p'.");
        goto error;
    } else {
        (*fixture_i64p_o) = 45;
    }

    /* Declare ::fixture::i64z */
    fixture_i64z_o = db_declare(fixture_o, "i64z", db_typedef(db_int64_o));
    if (!fixture_i64z_o) {
        db_error("fixture_load: failed to declare object '::fixture::i64z'.");
        goto error;
    } else {
        (*fixture_i64z_o) = 0;
    }

    /* Declare ::fixture::i8n */
    fixture_i8n_o = db_declare(fixture_o, "i8n", db_typedef(db_int8_o));
    if (!fixture_i8n_o) {
        db_error("fixture_load: failed to declare object '::fixture::i8n'.");
        goto error;
    } else {
        (*fixture_i8n_o) = -2;
    }

    /* Declare ::fixture::i8p */
    fixture_i8p_o = db_declare(fixture_o, "i8p", db_typedef(db_int8_o));
    if (!fixture_i8p_o) {
        db_error("fixture_load: failed to declare object '::fixture::i8p'.");
        goto error;
    } else {
        (*fixture_i8p_o) = 45;
    }

    /* Declare ::fixture::i8z */
    fixture_i8z_o = db_declare(fixture_o, "i8z", db_typedef(db_int8_o));
    if (!fixture_i8z_o) {
        db_error("fixture_load: failed to declare object '::fixture::i8z'.");
        goto error;
    } else {
        (*fixture_i8z_o) = 0;
    }

    /* Declare ::fixture::ints */
    fixture_ints_o = db_declare(fixture_o, "ints", db_typedef(db_array_o));
    if (!fixture_ints_o) {
        db_error("fixture_load: failed to declare object '::fixture::ints'.");
        goto error;
    }

    /* Define ::fixture::ints */
    if (!db_checkState(fixture_ints_o, DB_DEFINED)) {
        db_collection(fixture_ints_o)->elementType = db_resolve_ext(fixture_ints_o, NULL, "::hyve::lang::uint32", FALSE, "element ::fixture::ints.elementType");
        db_collection(fixture_ints_o)->max = 4;
        fixture_ints_o->elementType = db_resolve_ext(fixture_ints_o, NULL, "::hyve::lang::uint32", FALSE, "element ::fixture::ints.elementType");
        if (db_define(fixture_ints_o)) {
            db_error("fixture_load: failed to define object '::fixture::ints'.");
            goto error;
        }
    }

    if (db_type(fixture_ints_o)->size != sizeof(fixture_ints)) {
        db_error("fixture_load: calculated size '%d' of type '::fixture::ints' doesn't match C-type size '%d'", db_type(fixture_ints_o)->size, sizeof(fixture_ints));
    }

    /* Declare ::fixture::myarray */
    fixture_myarray_o = db_declare(fixture_o, "myarray", db_typedef(fixture_ints_o));
    if (!fixture_myarray_o) {
        db_error("fixture_load: failed to declare object '::fixture::myarray'.");
        goto error;
    }

    /* Define ::fixture::myarray */
    if (!db_checkState(fixture_myarray_o, DB_DEFINED)) {
        (*fixture_myarray_o)[0] = 26;
        (*fixture_myarray_o)[1] = 47;
        (*fixture_myarray_o)[2] = 6;
        (*fixture_myarray_o)[3] = 39;
        if (db_define(fixture_myarray_o)) {
            db_error("fixture_load: failed to define object '::fixture::myarray'.");
            goto error;
        }
    }

    /* Declare ::fixture::namesp */
    fixture_namesp_o = db_declare(fixture_o, "namesp", db_typedef(db_void_o));
    if (!fixture_namesp_o) {
        db_error("fixture_load: failed to declare object '::fixture::namesp'.");
        goto error;
    }

    /* Declare ::fixture::namesp::a */
    fixture_namesp_a_o = db_declare(fixture_namesp_o, "a", db_typedef(db_int16_o));
    if (!fixture_namesp_a_o) {
        db_error("fixture_load: failed to declare object '::fixture::namesp::a'.");
        goto error;
    } else {
        (*fixture_namesp_a_o) = 9;
    }

    /* Declare ::fixture::namesp::b */
    fixture_namesp_b_o = db_declare(fixture_namesp_o, "b", db_typedef(db_string_o));
    if (!fixture_namesp_b_o) {
        db_error("fixture_load: failed to declare object '::fixture::namesp::b'.");
        goto error;
    } else {
        (*fixture_namesp_b_o) = db_strdup("b");
    }

    /* Declare ::fixture::point2D */
    fixture_point2D_o = db_declare(fixture_o, "point2D", db_typedef(db_struct_o));
    if (!fixture_point2D_o) {
        db_error("fixture_load: failed to declare object '::fixture::point2D'.");
        goto error;
    }

    /* Declare ::fixture::point2D::x */
    fixture_point2D_x_o = db_declare(fixture_point2D_o, "x", db_typedef(db_member_o));
    if (!fixture_point2D_x_o) {
        db_error("fixture_load: failed to declare object '::fixture::point2D::x'.");
        goto error;
    }

    /* Define ::fixture::point2D::x */
    if (!db_checkState(fixture_point2D_x_o, DB_DEFINED)) {
        fixture_point2D_x_o->type = db_resolve_ext(fixture_point2D_x_o, NULL, "::hyve::lang::int32", FALSE, "element ::fixture::point2D::x.type");
        fixture_point2D_x_o->modifiers = 0x0;
        fixture_point2D_x_o->state = 0x6;
        fixture_point2D_x_o->weak = FALSE;
        fixture_point2D_x_o->id = 0;
        if (db_define(fixture_point2D_x_o)) {
            db_error("fixture_load: failed to define object '::fixture::point2D::x'.");
            goto error;
        }
    }

    /* Declare ::fixture::point2D::y */
    fixture_point2D_y_o = db_declare(fixture_point2D_o, "y", db_typedef(db_member_o));
    if (!fixture_point2D_y_o) {
        db_error("fixture_load: failed to declare object '::fixture::point2D::y'.");
        goto error;
    }

    /* Define ::fixture::point2D::y */
    if (!db_checkState(fixture_point2D_y_o, DB_DEFINED)) {
        fixture_point2D_y_o->type = db_resolve_ext(fixture_point2D_y_o, NULL, "::hyve::lang::int32", FALSE, "element ::fixture::point2D::y.type");
        fixture_point2D_y_o->modifiers = 0x0;
        fixture_point2D_y_o->state = 0x6;
        fixture_point2D_y_o->weak = FALSE;
        fixture_point2D_y_o->id = 1;
        if (db_define(fixture_point2D_y_o)) {
            db_error("fixture_load: failed to define object '::fixture::point2D::y'.");
            goto error;
        }
    }

    /* Define ::fixture::point2D */
    if (!db_checkState(fixture_point2D_o, DB_DEFINED)) {
        db_type(fixture_point2D_o)->defaultType = db_resolve_ext(fixture_point2D_o, NULL, "::hyve::lang::member", FALSE, "element ::fixture::point2D.defaultType");
        db_type(fixture_point2D_o)->parentType = NULL;
        db_type(fixture_point2D_o)->parentState = 0x0;
        db_interface(fixture_point2D_o)->base = NULL;
        fixture_point2D_o->baseAccess = 0x0;
        if (db_define(fixture_point2D_o)) {
            db_error("fixture_load: failed to define object '::fixture::point2D'.");
            goto error;
        }
    }

    if (db_type(fixture_point2D_o)->size != sizeof(fixture_point2D)) {
        db_error("fixture_load: calculated size '%d' of type '::fixture::point2D' doesn't match C-type size '%d'", db_type(fixture_point2D_o)->size, sizeof(fixture_point2D));
    }

    /* Declare ::fixture::p */
    fixture_p_o = db_declare(fixture_o, "p", db_typedef(fixture_point2D_o));
    if (!fixture_p_o) {
        db_error("fixture_load: failed to declare object '::fixture::p'.");
        goto error;
    }

    /* Define ::fixture::p */
    if (!db_checkState(fixture_p_o, DB_DEFINED)) {
        fixture_p_o->x = 3;
        fixture_p_o->y = 4;
        if (db_define(fixture_p_o)) {
            db_error("fixture_load: failed to define object '::fixture::p'.");
            goto error;
        }
    }

    /* Declare ::fixture::s1 */
    fixture_s1_o = db_declare(fixture_o, "s1", db_typedef(db_string_o));
    if (!fixture_s1_o) {
        db_error("fixture_load: failed to declare object '::fixture::s1'.");
        goto error;
    } else {
        (*fixture_s1_o) = db_strdup("hello world");
    }

    /* Declare ::fixture::s10 */
    fixture_s10_o = db_declare(fixture_o, "s10", db_typedef(db_string_o));
    if (!fixture_s10_o) {
        db_error("fixture_load: failed to declare object '::fixture::s10'.");
        goto error;
    } else {
        (*fixture_s10_o) = db_strdup("@@hey you");
    }

    /* Declare ::fixture::s11 */
    fixture_s11_o = db_declare(fixture_o, "s11", db_typedef(db_string_o));
    if (!fixture_s11_o) {
        db_error("fixture_load: failed to declare object '::fixture::s11'.");
        goto error;
    } else {
        (*fixture_s11_o) = db_strdup("@@@@@");
    }

    /* Declare ::fixture::s12 */
    fixture_s12_o = db_declare(fixture_o, "s12", db_typedef(db_string_o));
    if (!fixture_s12_o) {
        db_error("fixture_load: failed to declare object '::fixture::s12'.");
        goto error;
    } else {
        (*fixture_s12_o) = db_strdup("@@@@@ hey");
    }

    /* Declare ::fixture::s13 */
    fixture_s13_o = db_declare(fixture_o, "s13", db_typedef(db_string_o));
    if (!fixture_s13_o) {
        db_error("fixture_load: failed to declare object '::fixture::s13'.");
        goto error;
    } else {
        (*fixture_s13_o) = db_strdup("@@@@@hey");
    }

    /* Declare ::fixture::s14 */
    fixture_s14_o = db_declare(fixture_o, "s14", db_typedef(db_string_o));
    if (!fixture_s14_o) {
        db_error("fixture_load: failed to declare object '::fixture::s14'.");
        goto error;
    } else {
        (*fixture_s14_o) = db_strdup("@@@@@hey you");
    }

    /* Declare ::fixture::s2 */
    fixture_s2_o = db_declare(fixture_o, "s2", db_typedef(db_string_o));
    if (!fixture_s2_o) {
        db_error("fixture_load: failed to declare object '::fixture::s2'.");
        goto error;
    } else {
        (*fixture_s2_o) = db_strdup("hello, world!");
    }

    /* Declare ::fixture::s3 */
    fixture_s3_o = db_declare(fixture_o, "s3", db_typedef(db_string_o));
    if (!fixture_s3_o) {
        db_error("fixture_load: failed to declare object '::fixture::s3'.");
        goto error;
    } else {
        (*fixture_s3_o) = db_strdup("@");
    }

    /* Declare ::fixture::s4 */
    fixture_s4_o = db_declare(fixture_o, "s4", db_typedef(db_string_o));
    if (!fixture_s4_o) {
        db_error("fixture_load: failed to declare object '::fixture::s4'.");
        goto error;
    } else {
        (*fixture_s4_o) = db_strdup("@ hey");
    }

    /* Declare ::fixture::s5 */
    fixture_s5_o = db_declare(fixture_o, "s5", db_typedef(db_string_o));
    if (!fixture_s5_o) {
        db_error("fixture_load: failed to declare object '::fixture::s5'.");
        goto error;
    } else {
        (*fixture_s5_o) = db_strdup("@hey");
    }

    /* Declare ::fixture::s6 */
    fixture_s6_o = db_declare(fixture_o, "s6", db_typedef(db_string_o));
    if (!fixture_s6_o) {
        db_error("fixture_load: failed to declare object '::fixture::s6'.");
        goto error;
    } else {
        (*fixture_s6_o) = db_strdup("@hey you");
    }

    /* Declare ::fixture::s7 */
    fixture_s7_o = db_declare(fixture_o, "s7", db_typedef(db_string_o));
    if (!fixture_s7_o) {
        db_error("fixture_load: failed to declare object '::fixture::s7'.");
        goto error;
    } else {
        (*fixture_s7_o) = db_strdup("@@");
    }

    /* Declare ::fixture::s8 */
    fixture_s8_o = db_declare(fixture_o, "s8", db_typedef(db_string_o));
    if (!fixture_s8_o) {
        db_error("fixture_load: failed to declare object '::fixture::s8'.");
        goto error;
    } else {
        (*fixture_s8_o) = db_strdup("@@ hey");
    }

    /* Declare ::fixture::s9 */
    fixture_s9_o = db_declare(fixture_o, "s9", db_typedef(db_string_o));
    if (!fixture_s9_o) {
        db_error("fixture_load: failed to declare object '::fixture::s9'.");
        goto error;
    } else {
        (*fixture_s9_o) = db_strdup("@@hey");
    }

    /* Declare ::fixture::sn */
    fixture_sn_o = db_declare(fixture_o, "sn", db_typedef(db_string_o));
    if (!fixture_sn_o) {
        db_error("fixture_load: failed to declare object '::fixture::sn'.");
        goto error;
    } else {
        (*fixture_sn_o) = NULL;
    }

    /* Declare ::fixture::u16p */
    fixture_u16p_o = db_declare(fixture_o, "u16p", db_typedef(db_uint16_o));
    if (!fixture_u16p_o) {
        db_error("fixture_load: failed to declare object '::fixture::u16p'.");
        goto error;
    } else {
        (*fixture_u16p_o) = 45;
    }

    /* Declare ::fixture::u16z */
    fixture_u16z_o = db_declare(fixture_o, "u16z", db_typedef(db_uint16_o));
    if (!fixture_u16z_o) {
        db_error("fixture_load: failed to declare object '::fixture::u16z'.");
        goto error;
    } else {
        (*fixture_u16z_o) = 0;
    }

    /* Declare ::fixture::u32p */
    fixture_u32p_o = db_declare(fixture_o, "u32p", db_typedef(db_uint32_o));
    if (!fixture_u32p_o) {
        db_error("fixture_load: failed to declare object '::fixture::u32p'.");
        goto error;
    } else {
        (*fixture_u32p_o) = 45;
    }

    /* Declare ::fixture::u32z */
    fixture_u32z_o = db_declare(fixture_o, "u32z", db_typedef(db_uint32_o));
    if (!fixture_u32z_o) {
        db_error("fixture_load: failed to declare object '::fixture::u32z'.");
        goto error;
    } else {
        (*fixture_u32z_o) = 0;
    }

    /* Declare ::fixture::u64p */
    fixture_u64p_o = db_declare(fixture_o, "u64p", db_typedef(db_uint64_o));
    if (!fixture_u64p_o) {
        db_error("fixture_load: failed to declare object '::fixture::u64p'.");
        goto error;
    } else {
        (*fixture_u64p_o) = 45;
    }

    /* Declare ::fixture::u64z */
    fixture_u64z_o = db_declare(fixture_o, "u64z", db_typedef(db_uint64_o));
    if (!fixture_u64z_o) {
        db_error("fixture_load: failed to declare object '::fixture::u64z'.");
        goto error;
    } else {
        (*fixture_u64z_o) = 0;
    }

    /* Declare ::fixture::u8p */
    fixture_u8p_o = db_declare(fixture_o, "u8p", db_typedef(db_uint8_o));
    if (!fixture_u8p_o) {
        db_error("fixture_load: failed to declare object '::fixture::u8p'.");
        goto error;
    } else {
        (*fixture_u8p_o) = 45;
    }

    /* Declare ::fixture::u8z */
    fixture_u8z_o = db_declare(fixture_o, "u8z", db_typedef(db_uint8_o));
    if (!fixture_u8z_o) {
        db_error("fixture_load: failed to declare object '::fixture::u8z'.");
        goto error;
    } else {
        (*fixture_u8z_o) = 0;
    }

    /* Declare ::fixture::v0 */
    fixture_v0_o = db_declare(fixture_o, "v0", db_typedef(db_void_o));
    if (!fixture_v0_o) {
        db_error("fixture_load: failed to declare object '::fixture::v0'.");
        goto error;
    }

    /* Declare ::fixture::v1 */
    fixture_v1_o = db_declare(fixture_o, "v1", db_typedef(db_void_o));
    if (!fixture_v1_o) {
        db_error("fixture_load: failed to declare object '::fixture::v1'.");
        goto error;
    }

    /* Declare ::fixture::v1::v1 */
    fixture_v1_v1_o = db_declare(fixture_v1_o, "v1", db_typedef(db_void_o));
    if (!fixture_v1_v1_o) {
        db_error("fixture_load: failed to declare object '::fixture::v1::v1'.");
        goto error;
    }

    /* Declare ::fixture::v1::v1::v1 */
    fixture_v1_v1_v1_o = db_declare(fixture_v1_v1_o, "v1", db_typedef(db_void_o));
    if (!fixture_v1_v1_v1_o) {
        db_error("fixture_load: failed to declare object '::fixture::v1::v1::v1'.");
        goto error;
    }

    /* Declare ::fixture::v1::v1::v2 */
    fixture_v1_v1_v2_o = db_declare(fixture_v1_v1_o, "v2", db_typedef(db_void_o));
    if (!fixture_v1_v1_v2_o) {
        db_error("fixture_load: failed to declare object '::fixture::v1::v1::v2'.");
        goto error;
    }

    /* Declare ::fixture::v1::v1::v3 */
    fixture_v1_v1_v3_o = db_declare(fixture_v1_v1_o, "v3", db_typedef(db_void_o));
    if (!fixture_v1_v1_v3_o) {
        db_error("fixture_load: failed to declare object '::fixture::v1::v1::v3'.");
        goto error;
    }

    /* Declare ::fixture::v1::v1::v4 */
    fixture_v1_v1_v4_o = db_declare(fixture_v1_v1_o, "v4", db_typedef(db_void_o));
    if (!fixture_v1_v1_v4_o) {
        db_error("fixture_load: failed to declare object '::fixture::v1::v1::v4'.");
        goto error;
    }

    /* Declare ::fixture::v1::v2 */
    fixture_v1_v2_o = db_declare(fixture_v1_o, "v2", db_typedef(db_void_o));
    if (!fixture_v1_v2_o) {
        db_error("fixture_load: failed to declare object '::fixture::v1::v2'.");
        goto error;
    }

    /* Declare ::fixture::v1::v2::v1 */
    fixture_v1_v2_v1_o = db_declare(fixture_v1_v2_o, "v1", db_typedef(db_void_o));
    if (!fixture_v1_v2_v1_o) {
        db_error("fixture_load: failed to declare object '::fixture::v1::v2::v1'.");
        goto error;
    }

    /* Declare ::fixture::v1::v2::v2 */
    fixture_v1_v2_v2_o = db_declare(fixture_v1_v2_o, "v2", db_typedef(db_void_o));
    if (!fixture_v1_v2_v2_o) {
        db_error("fixture_load: failed to declare object '::fixture::v1::v2::v2'.");
        goto error;
    }

    /* Declare ::fixture::v1::v2::v3 */
    fixture_v1_v2_v3_o = db_declare(fixture_v1_v2_o, "v3", db_typedef(db_void_o));
    if (!fixture_v1_v2_v3_o) {
        db_error("fixture_load: failed to declare object '::fixture::v1::v2::v3'.");
        goto error;
    }

    /* Declare ::fixture::v1::v2::v4 */
    fixture_v1_v2_v4_o = db_declare(fixture_v1_v2_o, "v4", db_typedef(db_void_o));
    if (!fixture_v1_v2_v4_o) {
        db_error("fixture_load: failed to declare object '::fixture::v1::v2::v4'.");
        goto error;
    }

    /* Declare ::fixture::v1::v2::v5 */
    fixture_v1_v2_v5_o = db_declare(fixture_v1_v2_o, "v5", db_typedef(db_void_o));
    if (!fixture_v1_v2_v5_o) {
        db_error("fixture_load: failed to declare object '::fixture::v1::v2::v5'.");
        goto error;
    }

    /* Declare ::fixture::v1::v3 */
    fixture_v1_v3_o = db_declare(fixture_v1_o, "v3", db_typedef(db_void_o));
    if (!fixture_v1_v3_o) {
        db_error("fixture_load: failed to declare object '::fixture::v1::v3'.");
        goto error;
    }

    /* Declare ::fixture::v1::v3::v1 */
    fixture_v1_v3_v1_o = db_declare(fixture_v1_v3_o, "v1", db_typedef(db_void_o));
    if (!fixture_v1_v3_v1_o) {
        db_error("fixture_load: failed to declare object '::fixture::v1::v3::v1'.");
        goto error;
    }

    /* Declare ::fixture::v1::v3::v2 */
    fixture_v1_v3_v2_o = db_declare(fixture_v1_v3_o, "v2", db_typedef(db_void_o));
    if (!fixture_v1_v3_v2_o) {
        db_error("fixture_load: failed to declare object '::fixture::v1::v3::v2'.");
        goto error;
    }

    /* Declare ::fixture::v1::v3::v3 */
    fixture_v1_v3_v3_o = db_declare(fixture_v1_v3_o, "v3", db_typedef(db_void_o));
    if (!fixture_v1_v3_v3_o) {
        db_error("fixture_load: failed to declare object '::fixture::v1::v3::v3'.");
        goto error;
    }

    /* Declare ::fixture::v1::v3::v4 */
    fixture_v1_v3_v4_o = db_declare(fixture_v1_v3_o, "v4", db_typedef(db_void_o));
    if (!fixture_v1_v3_v4_o) {
        db_error("fixture_load: failed to declare object '::fixture::v1::v3::v4'.");
        goto error;
    }

    /* Declare ::fixture::v1::v3::v5 */
    fixture_v1_v3_v5_o = db_declare(fixture_v1_v3_o, "v5", db_typedef(db_void_o));
    if (!fixture_v1_v3_v5_o) {
        db_error("fixture_load: failed to declare object '::fixture::v1::v3::v5'.");
        goto error;
    }

    /* Declare ::fixture::v1::v3::v6 */
    fixture_v1_v3_v6_o = db_declare(fixture_v1_v3_o, "v6", db_typedef(db_void_o));
    if (!fixture_v1_v3_v6_o) {
        db_error("fixture_load: failed to declare object '::fixture::v1::v3::v6'.");
        goto error;
    }

    /* Define ::fixture::Dog::lover */
    if (!db_checkState(fixture_Dog_lover_o, DB_DEFINED)) {
        fixture_Dog_lover_o->type = db_resolve_ext(fixture_Dog_lover_o, NULL, "::fixture::Dog", FALSE, "element ::fixture::Dog::lover.type");
        fixture_Dog_lover_o->modifiers = 0x0;
        fixture_Dog_lover_o->state = 0x6;
        fixture_Dog_lover_o->weak = FALSE;
        fixture_Dog_lover_o->id = 3;
        if (db_define(fixture_Dog_lover_o)) {
            db_error("fixture_load: failed to define object '::fixture::Dog::lover'.");
            goto error;
        }
    }

    /* Define ::fixture::Dog */
    if (!db_checkState(fixture_Dog_o, DB_DEFINED)) {
        db_type(fixture_Dog_o)->defaultType = db_resolve_ext(fixture_Dog_o, NULL, "::hyve::lang::member", FALSE, "element ::fixture::Dog.defaultType");
        db_type(fixture_Dog_o)->parentType = NULL;
        db_type(fixture_Dog_o)->parentState = 0x0;
        db_interface(fixture_Dog_o)->base = NULL;
        db_struct(fixture_Dog_o)->baseAccess = 0x0;
        fixture_Dog_o->implements.length = 0;
        fixture_Dog_o->implements.buffer = NULL;
        if (db_define(fixture_Dog_o)) {
            db_error("fixture_load: failed to define object '::fixture::Dog'.");
            goto error;
        }
    }

    if (db_type(fixture_Dog_o)->size != sizeof(struct fixture_Dog_s)) {
        db_error("fixture_load: calculated size '%d' of type '::fixture::Dog' doesn't match C-type size '%d'", db_type(fixture_Dog_o)->size, sizeof(struct fixture_Dog_s));
    }

    /* Declare ::fixture::dog1 */
    fixture_dog1_o = db_declare(fixture_o, "dog1", db_typedef(fixture_Dog_o));
    if (!fixture_dog1_o) {
        db_error("fixture_load: failed to declare object '::fixture::dog1'.");
        goto error;
    }

    /* Define ::fixture::dog1 */
    if (!db_checkState(fixture_dog1_o, DB_DEFINED)) {
        fixture_dog1_o->breed = FIXTURE_GoldenRetriever;
        fixture_dog1_o->name = db_strdup("Gijs");
        fixture_dog1_o->age = 10;
        fixture_dog1_o->lover = NULL;
        if (db_define(fixture_dog1_o)) {
            db_error("fixture_load: failed to define object '::fixture::dog1'.");
            goto error;
        }
    }

    /* Declare ::fixture::dog2 */
    fixture_dog2_o = db_declare(fixture_o, "dog2", db_typedef(fixture_Dog_o));
    if (!fixture_dog2_o) {
        db_error("fixture_load: failed to declare object '::fixture::dog2'.");
        goto error;
    }

    /* Define ::fixture::dog2 */
    if (!db_checkState(fixture_dog2_o, DB_DEFINED)) {
        fixture_dog2_o->breed = FIXTURE_Pug;
        fixture_dog2_o->name = db_strdup("Lolly");
        fixture_dog2_o->age = 4;
        fixture_dog2_o->lover = NULL;
        if (db_define(fixture_dog2_o)) {
            db_error("fixture_load: failed to define object '::fixture::dog2'.");
            goto error;
        }
    }

    /* Declare ::fixture::dog3 */
    fixture_dog3_o = db_declare(fixture_o, "dog3", db_typedef(fixture_Dog_o));
    if (!fixture_dog3_o) {
        db_error("fixture_load: failed to declare object '::fixture::dog3'.");
        goto error;
    }

    /* Define ::fixture::dog3 */
    if (!db_checkState(fixture_dog3_o, DB_DEFINED)) {
        fixture_dog3_o->breed = FIXTURE_Chihuahua;
        fixture_dog3_o->name = db_strdup("I'm annoying");
        fixture_dog3_o->age = 3;
        fixture_dog3_o->lover = db_resolve_ext(fixture_dog3_o, NULL, "::fixture::dog2", FALSE, "element ::fixture::dog3.lover");
        if (db_define(fixture_dog3_o)) {
            db_error("fixture_load: failed to define object '::fixture::dog3'.");
            goto error;
        }
    }

    /* Declare ::fixture::v0::dog1 */
    fixture_v0_dog1_o = db_declare(fixture_v0_o, "dog1", db_typedef(fixture_Dog_o));
    if (!fixture_v0_dog1_o) {
        db_error("fixture_load: failed to declare object '::fixture::v0::dog1'.");
        goto error;
    }

    /* Define ::fixture::v0::dog1 */
    if (!db_checkState(fixture_v0_dog1_o, DB_DEFINED)) {
        fixture_v0_dog1_o->breed = FIXTURE_Pug;
        fixture_v0_dog1_o->name = db_strdup("MyPug");
        fixture_v0_dog1_o->age = 55;
        fixture_v0_dog1_o->lover = NULL;
        if (db_define(fixture_v0_dog1_o)) {
            db_error("fixture_load: failed to define object '::fixture::v0::dog1'.");
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
