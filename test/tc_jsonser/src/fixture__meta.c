/* fixture__meta.c
 *
 * Loads objects in database.
 * This file contains generated code. Do not modify!
 */

#include "fixture__type.h"

/* Variable definitions */
cx_object fixture_o;
cx_bool (*fixture_bf_o);
fixture_color (*fixture_black_o);
cx_bool (*fixture_bt_o);
cx_char (*fixture_c1_o);
cx_char (*fixture_c2_o);
cx_char (*fixture_c3_o);
cx_char (*fixture_c4_o);
cx_char (*fixture_c5_o);
cx_bitmask fixture_color_o;
cx_constant (*fixture_color_blue_o);
cx_constant (*fixture_color_green_o);
cx_constant (*fixture_color_red_o);
cx_enum fixture_Djinn_o;
cx_constant (*fixture_Djinn_Jupiter_o);
cx_constant (*fixture_Djinn_Mars_o);
cx_constant (*fixture_Djinn_Mercury_o);
cx_constant (*fixture_Djinn_Venus_o);
cx_class fixture_Dog_o;
cx_member fixture_Dog_age_o;
cx_member fixture_Dog_breed_o;
cx_member fixture_Dog_lover_o;
cx_member fixture_Dog_name_o;
fixture_Dog fixture_dog1_o;
fixture_Dog fixture_dog2_o;
fixture_Dog fixture_dog3_o;
cx_enum fixture_DogBreed_o;
cx_constant (*fixture_DogBreed_Chihuahua_o);
cx_constant (*fixture_DogBreed_GoldenRetriever_o);
cx_constant (*fixture_DogBreed_Pug_o);
cx_float32 (*fixture_f32n_o);
cx_float32 (*fixture_f32p_o);
cx_float32 (*fixture_f32z_o);
cx_float64 (*fixture_f64n_o);
cx_float64 (*fixture_f64p_o);
cx_float64 (*fixture_f64z_o);
fixture_Djinn (*fixture_Flint_o);
fixture_Djinn (*fixture_Forge_o);
fixture_Djinn (*fixture_Gust_o);
cx_int16 (*fixture_i16n_o);
cx_int16 (*fixture_i16p_o);
cx_int16 (*fixture_i16z_o);
cx_int32 (*fixture_i32n_o);
cx_int32 (*fixture_i32p_o);
cx_int32 (*fixture_i32z_o);
cx_int64 (*fixture_i64n_o);
cx_int64 (*fixture_i64p_o);
cx_int64 (*fixture_i64z_o);
cx_int8 (*fixture_i8n_o);
cx_int8 (*fixture_i8p_o);
cx_int8 (*fixture_i8z_o);
cx_array fixture_ints_o;
fixture_ints (*fixture_myarray_o);
cx_void (*fixture_namesp_o);
cx_int16 (*fixture_namesp_a_o);
cx_string (*fixture_namesp_b_o);
fixture_point2D (*fixture_p_o);
cx_struct fixture_point2D_o;
cx_member fixture_point2D_x_o;
cx_member fixture_point2D_y_o;
cx_string (*fixture_s1_o);
cx_string (*fixture_s10_o);
cx_string (*fixture_s11_o);
cx_string (*fixture_s12_o);
cx_string (*fixture_s13_o);
cx_string (*fixture_s14_o);
cx_string (*fixture_s2_o);
cx_string (*fixture_s3_o);
cx_string (*fixture_s4_o);
cx_string (*fixture_s5_o);
cx_string (*fixture_s6_o);
cx_string (*fixture_s7_o);
cx_string (*fixture_s8_o);
cx_string (*fixture_s9_o);
fixture_Djinn (*fixture_Sleet_o);
cx_string (*fixture_sn_o);
cx_uint16 (*fixture_u16p_o);
cx_uint16 (*fixture_u16z_o);
cx_uint32 (*fixture_u32p_o);
cx_uint32 (*fixture_u32z_o);
cx_uint64 (*fixture_u64p_o);
cx_uint64 (*fixture_u64z_o);
cx_uint8 (*fixture_u8p_o);
cx_uint8 (*fixture_u8z_o);
cx_void (*fixture_v0_o);
fixture_Dog fixture_v0_dog1_o;
cx_void (*fixture_v1_o);
cx_void (*fixture_v1_v1_o);
cx_void (*fixture_v1_v1_v1_o);
cx_void (*fixture_v1_v1_v2_o);
cx_void (*fixture_v1_v1_v3_o);
cx_void (*fixture_v1_v1_v4_o);
cx_void (*fixture_v1_v2_o);
cx_void (*fixture_v1_v2_v1_o);
cx_void (*fixture_v1_v2_v2_o);
cx_void (*fixture_v1_v2_v3_o);
cx_void (*fixture_v1_v2_v4_o);
cx_void (*fixture_v1_v2_v5_o);
cx_void (*fixture_v1_v3_o);
cx_void (*fixture_v1_v3_v1_o);
cx_void (*fixture_v1_v3_v2_o);
cx_void (*fixture_v1_v3_v3_o);
cx_void (*fixture_v1_v3_v4_o);
cx_void (*fixture_v1_v3_v5_o);
cx_void (*fixture_v1_v3_v6_o);
fixture_color (*fixture_white_o);
fixture_color (*fixture_yellow_o);

/* Load objects in database */
int fixture_load(void) {
    cx_object _a_; /* Used for resolving anonymous objects */
    _a_ = NULL;

    /* Declare ::fixture */
    fixture_o = cx_declare(root_o, "fixture", cx_typedef(cx_object_o));
    if (!fixture_o) {
        cx_error("fixture_load: failed to declare object '::fixture'.");
        goto error;
    }

    /* Define ::fixture */
    if (!cx_checkState(fixture_o, CX_DEFINED)) {
        if (cx_define(fixture_o)) {
            cx_error("fixture_load: failed to define object '::fixture'.");
            goto error;
        }
    }

    /* Declare ::fixture::bf */
    fixture_bf_o = cx_declare(fixture_o, "bf", cx_typedef(cx_bool_o));
    if (!fixture_bf_o) {
        cx_error("fixture_load: failed to declare object '::fixture::bf'.");
        goto error;
    } else {
        (*fixture_bf_o) = FALSE;
    }

    /* Declare ::fixture::bt */
    fixture_bt_o = cx_declare(fixture_o, "bt", cx_typedef(cx_bool_o));
    if (!fixture_bt_o) {
        cx_error("fixture_load: failed to declare object '::fixture::bt'.");
        goto error;
    } else {
        (*fixture_bt_o) = TRUE;
    }

    /* Declare ::fixture::c1 */
    fixture_c1_o = cx_declare(fixture_o, "c1", cx_typedef(cx_char_o));
    if (!fixture_c1_o) {
        cx_error("fixture_load: failed to declare object '::fixture::c1'.");
        goto error;
    } else {
        (*fixture_c1_o) = 'a';
    }

    /* Declare ::fixture::c2 */
    fixture_c2_o = cx_declare(fixture_o, "c2", cx_typedef(cx_char_o));
    if (!fixture_c2_o) {
        cx_error("fixture_load: failed to declare object '::fixture::c2'.");
        goto error;
    } else {
        (*fixture_c2_o) = 'A';
    }

    /* Declare ::fixture::c3 */
    fixture_c3_o = cx_declare(fixture_o, "c3", cx_typedef(cx_char_o));
    if (!fixture_c3_o) {
        cx_error("fixture_load: failed to declare object '::fixture::c3'.");
        goto error;
    } else {
        (*fixture_c3_o) = '0';
    }

    /* Declare ::fixture::c4 */
    fixture_c4_o = cx_declare(fixture_o, "c4", cx_typedef(cx_char_o));
    if (!fixture_c4_o) {
        cx_error("fixture_load: failed to declare object '::fixture::c4'.");
        goto error;
    } else {
        (*fixture_c4_o) = '\n';
    }

    /* Declare ::fixture::c5 */
    fixture_c5_o = cx_declare(fixture_o, "c5", cx_typedef(cx_char_o));
    if (!fixture_c5_o) {
        cx_error("fixture_load: failed to declare object '::fixture::c5'.");
        goto error;
    } else {
        (*fixture_c5_o) = '\0';
    }

    /* Declare ::fixture::color */
    fixture_color_o = cx_declare(fixture_o, "color", cx_typedef(cx_bitmask_o));
    if (!fixture_color_o) {
        cx_error("fixture_load: failed to declare object '::fixture::color'.");
        goto error;
    }

    /* Declare ::fixture::color::blue */
    fixture_color_blue_o = cx_declare(fixture_color_o, "blue", cx_typedef(cx_constant_o));
    if (!fixture_color_blue_o) {
        cx_error("fixture_load: failed to declare object '::fixture::color::blue'.");
        goto error;
    } else {
        (*fixture_color_blue_o) = 4;
    }

    /* Declare ::fixture::color::green */
    fixture_color_green_o = cx_declare(fixture_color_o, "green", cx_typedef(cx_constant_o));
    if (!fixture_color_green_o) {
        cx_error("fixture_load: failed to declare object '::fixture::color::green'.");
        goto error;
    } else {
        (*fixture_color_green_o) = 2;
    }

    /* Declare ::fixture::color::red */
    fixture_color_red_o = cx_declare(fixture_color_o, "red", cx_typedef(cx_constant_o));
    if (!fixture_color_red_o) {
        cx_error("fixture_load: failed to declare object '::fixture::color::red'.");
        goto error;
    } else {
        (*fixture_color_red_o) = 1;
    }

    /* Define ::fixture::color */
    if (!cx_checkState(fixture_color_o, CX_DEFINED)) {
        if (cx_define(fixture_color_o)) {
            cx_error("fixture_load: failed to define object '::fixture::color'.");
            goto error;
        }
    }

    if (cx_type(fixture_color_o)->size != sizeof(fixture_color)) {
        cx_error("fixture_load: calculated size '%d' of type '::fixture::color' doesn't match C-type size '%d'", cx_type(fixture_color_o)->size, sizeof(fixture_color));
    }

    /* Declare ::fixture::black */
    fixture_black_o = cx_declare(fixture_o, "black", cx_typedef(fixture_color_o));
    if (!fixture_black_o) {
        cx_error("fixture_load: failed to declare object '::fixture::black'.");
        goto error;
    } else {
        (*fixture_black_o) = 0x0;
    }

    /* Declare ::fixture::white */
    fixture_white_o = cx_declare(fixture_o, "white", cx_typedef(fixture_color_o));
    if (!fixture_white_o) {
        cx_error("fixture_load: failed to declare object '::fixture::white'.");
        goto error;
    } else {
        (*fixture_white_o) = 0x7;
    }

    /* Declare ::fixture::yellow */
    fixture_yellow_o = cx_declare(fixture_o, "yellow", cx_typedef(fixture_color_o));
    if (!fixture_yellow_o) {
        cx_error("fixture_load: failed to declare object '::fixture::yellow'.");
        goto error;
    } else {
        (*fixture_yellow_o) = 0x3;
    }

    /* Declare ::fixture::Djinn */
    fixture_Djinn_o = cx_declare(fixture_o, "Djinn", cx_typedef(cx_enum_o));
    if (!fixture_Djinn_o) {
        cx_error("fixture_load: failed to declare object '::fixture::Djinn'.");
        goto error;
    }

    /* Declare ::fixture::Djinn::Jupiter */
    fixture_Djinn_Jupiter_o = cx_declare(fixture_Djinn_o, "Jupiter", cx_typedef(cx_constant_o));
    if (!fixture_Djinn_Jupiter_o) {
        cx_error("fixture_load: failed to declare object '::fixture::Djinn::Jupiter'.");
        goto error;
    } else {
        (*fixture_Djinn_Jupiter_o) = 3;
    }

    /* Declare ::fixture::Djinn::Mars */
    fixture_Djinn_Mars_o = cx_declare(fixture_Djinn_o, "Mars", cx_typedef(cx_constant_o));
    if (!fixture_Djinn_Mars_o) {
        cx_error("fixture_load: failed to declare object '::fixture::Djinn::Mars'.");
        goto error;
    } else {
        (*fixture_Djinn_Mars_o) = 2;
    }

    /* Declare ::fixture::Djinn::Mercury */
    fixture_Djinn_Mercury_o = cx_declare(fixture_Djinn_o, "Mercury", cx_typedef(cx_constant_o));
    if (!fixture_Djinn_Mercury_o) {
        cx_error("fixture_load: failed to declare object '::fixture::Djinn::Mercury'.");
        goto error;
    } else {
        (*fixture_Djinn_Mercury_o) = 0;
    }

    /* Declare ::fixture::Djinn::Venus */
    fixture_Djinn_Venus_o = cx_declare(fixture_Djinn_o, "Venus", cx_typedef(cx_constant_o));
    if (!fixture_Djinn_Venus_o) {
        cx_error("fixture_load: failed to declare object '::fixture::Djinn::Venus'.");
        goto error;
    } else {
        (*fixture_Djinn_Venus_o) = 1;
    }

    /* Define ::fixture::Djinn */
    if (!cx_checkState(fixture_Djinn_o, CX_DEFINED)) {
        if (cx_define(fixture_Djinn_o)) {
            cx_error("fixture_load: failed to define object '::fixture::Djinn'.");
            goto error;
        }
    }

    if (cx_type(fixture_Djinn_o)->size != sizeof(fixture_Djinn)) {
        cx_error("fixture_load: calculated size '%d' of type '::fixture::Djinn' doesn't match C-type size '%d'", cx_type(fixture_Djinn_o)->size, sizeof(fixture_Djinn));
    }

    /* Declare ::fixture::Flint */
    fixture_Flint_o = cx_declare(fixture_o, "Flint", cx_typedef(fixture_Djinn_o));
    if (!fixture_Flint_o) {
        cx_error("fixture_load: failed to declare object '::fixture::Flint'.");
        goto error;
    } else {
        (*fixture_Flint_o) = FIXTURE_Venus;
    }

    /* Declare ::fixture::Forge */
    fixture_Forge_o = cx_declare(fixture_o, "Forge", cx_typedef(fixture_Djinn_o));
    if (!fixture_Forge_o) {
        cx_error("fixture_load: failed to declare object '::fixture::Forge'.");
        goto error;
    } else {
        (*fixture_Forge_o) = FIXTURE_Mars;
    }

    /* Declare ::fixture::Gust */
    fixture_Gust_o = cx_declare(fixture_o, "Gust", cx_typedef(fixture_Djinn_o));
    if (!fixture_Gust_o) {
        cx_error("fixture_load: failed to declare object '::fixture::Gust'.");
        goto error;
    } else {
        (*fixture_Gust_o) = FIXTURE_Jupiter;
    }

    /* Declare ::fixture::Sleet */
    fixture_Sleet_o = cx_declare(fixture_o, "Sleet", cx_typedef(fixture_Djinn_o));
    if (!fixture_Sleet_o) {
        cx_error("fixture_load: failed to declare object '::fixture::Sleet'.");
        goto error;
    } else {
        (*fixture_Sleet_o) = FIXTURE_Mercury;
    }

    /* Declare ::fixture::Dog */
    fixture_Dog_o = cx_declare(fixture_o, "Dog", cx_typedef(cx_class_o));
    if (!fixture_Dog_o) {
        cx_error("fixture_load: failed to declare object '::fixture::Dog'.");
        goto error;
    }

    /* Declare ::fixture::Dog::age */
    fixture_Dog_age_o = cx_declare(fixture_Dog_o, "age", cx_typedef(cx_member_o));
    if (!fixture_Dog_age_o) {
        cx_error("fixture_load: failed to declare object '::fixture::Dog::age'.");
        goto error;
    }

    /* Define ::fixture::Dog::age */
    if (!cx_checkState(fixture_Dog_age_o, CX_DEFINED)) {
        fixture_Dog_age_o->type = cx_resolve_ext(fixture_Dog_age_o, NULL, "::cortex::lang::uint8", FALSE, "element ::fixture::Dog::age.type");
        fixture_Dog_age_o->modifiers = 0x0;
        fixture_Dog_age_o->state = 0x6;
        fixture_Dog_age_o->weak = FALSE;
        fixture_Dog_age_o->id = 2;
        if (cx_define(fixture_Dog_age_o)) {
            cx_error("fixture_load: failed to define object '::fixture::Dog::age'.");
            goto error;
        }
    }

    /* Declare ::fixture::Dog::breed */
    fixture_Dog_breed_o = cx_declare(fixture_Dog_o, "breed", cx_typedef(cx_member_o));
    if (!fixture_Dog_breed_o) {
        cx_error("fixture_load: failed to declare object '::fixture::Dog::breed'.");
        goto error;
    }

    /* Declare ::fixture::Dog::lover */
    fixture_Dog_lover_o = cx_declare(fixture_Dog_o, "lover", cx_typedef(cx_member_o));
    if (!fixture_Dog_lover_o) {
        cx_error("fixture_load: failed to declare object '::fixture::Dog::lover'.");
        goto error;
    }

    /* Declare ::fixture::Dog::name */
    fixture_Dog_name_o = cx_declare(fixture_Dog_o, "name", cx_typedef(cx_member_o));
    if (!fixture_Dog_name_o) {
        cx_error("fixture_load: failed to declare object '::fixture::Dog::name'.");
        goto error;
    }

    /* Define ::fixture::Dog::name */
    if (!cx_checkState(fixture_Dog_name_o, CX_DEFINED)) {
        fixture_Dog_name_o->type = cx_resolve_ext(fixture_Dog_name_o, NULL, "::cortex::lang::string", FALSE, "element ::fixture::Dog::name.type");
        fixture_Dog_name_o->modifiers = 0x0;
        fixture_Dog_name_o->state = 0x6;
        fixture_Dog_name_o->weak = FALSE;
        fixture_Dog_name_o->id = 1;
        if (cx_define(fixture_Dog_name_o)) {
            cx_error("fixture_load: failed to define object '::fixture::Dog::name'.");
            goto error;
        }
    }

    /* Declare ::fixture::DogBreed */
    fixture_DogBreed_o = cx_declare(fixture_o, "DogBreed", cx_typedef(cx_enum_o));
    if (!fixture_DogBreed_o) {
        cx_error("fixture_load: failed to declare object '::fixture::DogBreed'.");
        goto error;
    }

    /* Declare ::fixture::DogBreed::Chihuahua */
    fixture_DogBreed_Chihuahua_o = cx_declare(fixture_DogBreed_o, "Chihuahua", cx_typedef(cx_constant_o));
    if (!fixture_DogBreed_Chihuahua_o) {
        cx_error("fixture_load: failed to declare object '::fixture::DogBreed::Chihuahua'.");
        goto error;
    } else {
        (*fixture_DogBreed_Chihuahua_o) = 2;
    }

    /* Declare ::fixture::DogBreed::GoldenRetriever */
    fixture_DogBreed_GoldenRetriever_o = cx_declare(fixture_DogBreed_o, "GoldenRetriever", cx_typedef(cx_constant_o));
    if (!fixture_DogBreed_GoldenRetriever_o) {
        cx_error("fixture_load: failed to declare object '::fixture::DogBreed::GoldenRetriever'.");
        goto error;
    } else {
        (*fixture_DogBreed_GoldenRetriever_o) = 0;
    }

    /* Declare ::fixture::DogBreed::Pug */
    fixture_DogBreed_Pug_o = cx_declare(fixture_DogBreed_o, "Pug", cx_typedef(cx_constant_o));
    if (!fixture_DogBreed_Pug_o) {
        cx_error("fixture_load: failed to declare object '::fixture::DogBreed::Pug'.");
        goto error;
    } else {
        (*fixture_DogBreed_Pug_o) = 1;
    }

    /* Define ::fixture::DogBreed */
    if (!cx_checkState(fixture_DogBreed_o, CX_DEFINED)) {
        if (cx_define(fixture_DogBreed_o)) {
            cx_error("fixture_load: failed to define object '::fixture::DogBreed'.");
            goto error;
        }
    }

    if (cx_type(fixture_DogBreed_o)->size != sizeof(fixture_DogBreed)) {
        cx_error("fixture_load: calculated size '%d' of type '::fixture::DogBreed' doesn't match C-type size '%d'", cx_type(fixture_DogBreed_o)->size, sizeof(fixture_DogBreed));
    }

    /* Define ::fixture::Dog::breed */
    if (!cx_checkState(fixture_Dog_breed_o, CX_DEFINED)) {
        fixture_Dog_breed_o->type = cx_resolve_ext(fixture_Dog_breed_o, NULL, "::fixture::DogBreed", FALSE, "element ::fixture::Dog::breed.type");
        fixture_Dog_breed_o->modifiers = 0x0;
        fixture_Dog_breed_o->state = 0x6;
        fixture_Dog_breed_o->weak = FALSE;
        fixture_Dog_breed_o->id = 0;
        if (cx_define(fixture_Dog_breed_o)) {
            cx_error("fixture_load: failed to define object '::fixture::Dog::breed'.");
            goto error;
        }
    }

    /* Declare ::fixture::f32n */
    fixture_f32n_o = cx_declare(fixture_o, "f32n", cx_typedef(cx_float32_o));
    if (!fixture_f32n_o) {
        cx_error("fixture_load: failed to declare object '::fixture::f32n'.");
        goto error;
    } else {
        (*fixture_f32n_o) = -2.450000;
    }

    /* Declare ::fixture::f32p */
    fixture_f32p_o = cx_declare(fixture_o, "f32p", cx_typedef(cx_float32_o));
    if (!fixture_f32p_o) {
        cx_error("fixture_load: failed to declare object '::fixture::f32p'.");
        goto error;
    } else {
        (*fixture_f32p_o) = 45.200001;
    }

    /* Declare ::fixture::f32z */
    fixture_f32z_o = cx_declare(fixture_o, "f32z", cx_typedef(cx_float32_o));
    if (!fixture_f32z_o) {
        cx_error("fixture_load: failed to declare object '::fixture::f32z'.");
        goto error;
    } else {
        (*fixture_f32z_o) = 0.000000;
    }

    /* Declare ::fixture::f64n */
    fixture_f64n_o = cx_declare(fixture_o, "f64n", cx_typedef(cx_float64_o));
    if (!fixture_f64n_o) {
        cx_error("fixture_load: failed to declare object '::fixture::f64n'.");
        goto error;
    } else {
        (*fixture_f64n_o) = -2.450000;
    }

    /* Declare ::fixture::f64p */
    fixture_f64p_o = cx_declare(fixture_o, "f64p", cx_typedef(cx_float64_o));
    if (!fixture_f64p_o) {
        cx_error("fixture_load: failed to declare object '::fixture::f64p'.");
        goto error;
    } else {
        (*fixture_f64p_o) = 45.200000;
    }

    /* Declare ::fixture::f64z */
    fixture_f64z_o = cx_declare(fixture_o, "f64z", cx_typedef(cx_float64_o));
    if (!fixture_f64z_o) {
        cx_error("fixture_load: failed to declare object '::fixture::f64z'.");
        goto error;
    } else {
        (*fixture_f64z_o) = 0.000000;
    }

    /* Declare ::fixture::i16n */
    fixture_i16n_o = cx_declare(fixture_o, "i16n", cx_typedef(cx_int16_o));
    if (!fixture_i16n_o) {
        cx_error("fixture_load: failed to declare object '::fixture::i16n'.");
        goto error;
    } else {
        (*fixture_i16n_o) = -2;
    }

    /* Declare ::fixture::i16p */
    fixture_i16p_o = cx_declare(fixture_o, "i16p", cx_typedef(cx_int16_o));
    if (!fixture_i16p_o) {
        cx_error("fixture_load: failed to declare object '::fixture::i16p'.");
        goto error;
    } else {
        (*fixture_i16p_o) = 45;
    }

    /* Declare ::fixture::i16z */
    fixture_i16z_o = cx_declare(fixture_o, "i16z", cx_typedef(cx_int16_o));
    if (!fixture_i16z_o) {
        cx_error("fixture_load: failed to declare object '::fixture::i16z'.");
        goto error;
    } else {
        (*fixture_i16z_o) = 0;
    }

    /* Declare ::fixture::i32n */
    fixture_i32n_o = cx_declare(fixture_o, "i32n", cx_typedef(cx_int32_o));
    if (!fixture_i32n_o) {
        cx_error("fixture_load: failed to declare object '::fixture::i32n'.");
        goto error;
    } else {
        (*fixture_i32n_o) = -2;
    }

    /* Declare ::fixture::i32p */
    fixture_i32p_o = cx_declare(fixture_o, "i32p", cx_typedef(cx_int32_o));
    if (!fixture_i32p_o) {
        cx_error("fixture_load: failed to declare object '::fixture::i32p'.");
        goto error;
    } else {
        (*fixture_i32p_o) = 45;
    }

    /* Declare ::fixture::i32z */
    fixture_i32z_o = cx_declare(fixture_o, "i32z", cx_typedef(cx_int32_o));
    if (!fixture_i32z_o) {
        cx_error("fixture_load: failed to declare object '::fixture::i32z'.");
        goto error;
    } else {
        (*fixture_i32z_o) = 0;
    }

    /* Declare ::fixture::i64n */
    fixture_i64n_o = cx_declare(fixture_o, "i64n", cx_typedef(cx_int64_o));
    if (!fixture_i64n_o) {
        cx_error("fixture_load: failed to declare object '::fixture::i64n'.");
        goto error;
    } else {
        (*fixture_i64n_o) = -2;
    }

    /* Declare ::fixture::i64p */
    fixture_i64p_o = cx_declare(fixture_o, "i64p", cx_typedef(cx_int64_o));
    if (!fixture_i64p_o) {
        cx_error("fixture_load: failed to declare object '::fixture::i64p'.");
        goto error;
    } else {
        (*fixture_i64p_o) = 45;
    }

    /* Declare ::fixture::i64z */
    fixture_i64z_o = cx_declare(fixture_o, "i64z", cx_typedef(cx_int64_o));
    if (!fixture_i64z_o) {
        cx_error("fixture_load: failed to declare object '::fixture::i64z'.");
        goto error;
    } else {
        (*fixture_i64z_o) = 0;
    }

    /* Declare ::fixture::i8n */
    fixture_i8n_o = cx_declare(fixture_o, "i8n", cx_typedef(cx_int8_o));
    if (!fixture_i8n_o) {
        cx_error("fixture_load: failed to declare object '::fixture::i8n'.");
        goto error;
    } else {
        (*fixture_i8n_o) = -2;
    }

    /* Declare ::fixture::i8p */
    fixture_i8p_o = cx_declare(fixture_o, "i8p", cx_typedef(cx_int8_o));
    if (!fixture_i8p_o) {
        cx_error("fixture_load: failed to declare object '::fixture::i8p'.");
        goto error;
    } else {
        (*fixture_i8p_o) = 45;
    }

    /* Declare ::fixture::i8z */
    fixture_i8z_o = cx_declare(fixture_o, "i8z", cx_typedef(cx_int8_o));
    if (!fixture_i8z_o) {
        cx_error("fixture_load: failed to declare object '::fixture::i8z'.");
        goto error;
    } else {
        (*fixture_i8z_o) = 0;
    }

    /* Declare ::fixture::ints */
    fixture_ints_o = cx_declare(fixture_o, "ints", cx_typedef(cx_array_o));
    if (!fixture_ints_o) {
        cx_error("fixture_load: failed to declare object '::fixture::ints'.");
        goto error;
    }

    /* Define ::fixture::ints */
    if (!cx_checkState(fixture_ints_o, CX_DEFINED)) {
        cx_collection(fixture_ints_o)->elementType = cx_resolve_ext(fixture_ints_o, NULL, "::cortex::lang::uint32", FALSE, "element ::fixture::ints.elementType");
        cx_collection(fixture_ints_o)->max = 4;
        fixture_ints_o->elementType = cx_resolve_ext(fixture_ints_o, NULL, "::cortex::lang::uint32", FALSE, "element ::fixture::ints.elementType");
        if (cx_define(fixture_ints_o)) {
            cx_error("fixture_load: failed to define object '::fixture::ints'.");
            goto error;
        }
    }

    if (cx_type(fixture_ints_o)->size != sizeof(fixture_ints)) {
        cx_error("fixture_load: calculated size '%d' of type '::fixture::ints' doesn't match C-type size '%d'", cx_type(fixture_ints_o)->size, sizeof(fixture_ints));
    }

    /* Declare ::fixture::myarray */
    fixture_myarray_o = cx_declare(fixture_o, "myarray", cx_typedef(fixture_ints_o));
    if (!fixture_myarray_o) {
        cx_error("fixture_load: failed to declare object '::fixture::myarray'.");
        goto error;
    }

    /* Define ::fixture::myarray */
    if (!cx_checkState(fixture_myarray_o, CX_DEFINED)) {
        (*fixture_myarray_o)[0] = 26;
        (*fixture_myarray_o)[1] = 47;
        (*fixture_myarray_o)[2] = 6;
        (*fixture_myarray_o)[3] = 39;
        if (cx_define(fixture_myarray_o)) {
            cx_error("fixture_load: failed to define object '::fixture::myarray'.");
            goto error;
        }
    }

    /* Declare ::fixture::namesp */
    fixture_namesp_o = cx_declare(fixture_o, "namesp", cx_typedef(cx_void_o));
    if (!fixture_namesp_o) {
        cx_error("fixture_load: failed to declare object '::fixture::namesp'.");
        goto error;
    }

    /* Declare ::fixture::namesp::a */
    fixture_namesp_a_o = cx_declare(fixture_namesp_o, "a", cx_typedef(cx_int16_o));
    if (!fixture_namesp_a_o) {
        cx_error("fixture_load: failed to declare object '::fixture::namesp::a'.");
        goto error;
    } else {
        (*fixture_namesp_a_o) = 9;
    }

    /* Declare ::fixture::namesp::b */
    fixture_namesp_b_o = cx_declare(fixture_namesp_o, "b", cx_typedef(cx_string_o));
    if (!fixture_namesp_b_o) {
        cx_error("fixture_load: failed to declare object '::fixture::namesp::b'.");
        goto error;
    } else {
        (*fixture_namesp_b_o) = cx_strdup("b");
    }

    /* Declare ::fixture::point2D */
    fixture_point2D_o = cx_declare(fixture_o, "point2D", cx_typedef(cx_struct_o));
    if (!fixture_point2D_o) {
        cx_error("fixture_load: failed to declare object '::fixture::point2D'.");
        goto error;
    }

    /* Declare ::fixture::point2D::x */
    fixture_point2D_x_o = cx_declare(fixture_point2D_o, "x", cx_typedef(cx_member_o));
    if (!fixture_point2D_x_o) {
        cx_error("fixture_load: failed to declare object '::fixture::point2D::x'.");
        goto error;
    }

    /* Define ::fixture::point2D::x */
    if (!cx_checkState(fixture_point2D_x_o, CX_DEFINED)) {
        fixture_point2D_x_o->type = cx_resolve_ext(fixture_point2D_x_o, NULL, "::cortex::lang::int32", FALSE, "element ::fixture::point2D::x.type");
        fixture_point2D_x_o->modifiers = 0x0;
        fixture_point2D_x_o->state = 0x6;
        fixture_point2D_x_o->weak = FALSE;
        fixture_point2D_x_o->id = 0;
        if (cx_define(fixture_point2D_x_o)) {
            cx_error("fixture_load: failed to define object '::fixture::point2D::x'.");
            goto error;
        }
    }

    /* Declare ::fixture::point2D::y */
    fixture_point2D_y_o = cx_declare(fixture_point2D_o, "y", cx_typedef(cx_member_o));
    if (!fixture_point2D_y_o) {
        cx_error("fixture_load: failed to declare object '::fixture::point2D::y'.");
        goto error;
    }

    /* Define ::fixture::point2D::y */
    if (!cx_checkState(fixture_point2D_y_o, CX_DEFINED)) {
        fixture_point2D_y_o->type = cx_resolve_ext(fixture_point2D_y_o, NULL, "::cortex::lang::int32", FALSE, "element ::fixture::point2D::y.type");
        fixture_point2D_y_o->modifiers = 0x0;
        fixture_point2D_y_o->state = 0x6;
        fixture_point2D_y_o->weak = FALSE;
        fixture_point2D_y_o->id = 1;
        if (cx_define(fixture_point2D_y_o)) {
            cx_error("fixture_load: failed to define object '::fixture::point2D::y'.");
            goto error;
        }
    }

    /* Define ::fixture::point2D */
    if (!cx_checkState(fixture_point2D_o, CX_DEFINED)) {
        cx_type(fixture_point2D_o)->defaultType = cx_resolve_ext(fixture_point2D_o, NULL, "::cortex::lang::member", FALSE, "element ::fixture::point2D.defaultType");
        cx_type(fixture_point2D_o)->parentType = NULL;
        cx_type(fixture_point2D_o)->parentState = 0x0;
        cx_interface(fixture_point2D_o)->base = NULL;
        fixture_point2D_o->baseAccess = 0x0;
        if (cx_define(fixture_point2D_o)) {
            cx_error("fixture_load: failed to define object '::fixture::point2D'.");
            goto error;
        }
    }

    if (cx_type(fixture_point2D_o)->size != sizeof(fixture_point2D)) {
        cx_error("fixture_load: calculated size '%d' of type '::fixture::point2D' doesn't match C-type size '%d'", cx_type(fixture_point2D_o)->size, sizeof(fixture_point2D));
    }

    /* Declare ::fixture::p */
    fixture_p_o = cx_declare(fixture_o, "p", cx_typedef(fixture_point2D_o));
    if (!fixture_p_o) {
        cx_error("fixture_load: failed to declare object '::fixture::p'.");
        goto error;
    }

    /* Define ::fixture::p */
    if (!cx_checkState(fixture_p_o, CX_DEFINED)) {
        fixture_p_o->x = 3;
        fixture_p_o->y = 4;
        if (cx_define(fixture_p_o)) {
            cx_error("fixture_load: failed to define object '::fixture::p'.");
            goto error;
        }
    }

    /* Declare ::fixture::s1 */
    fixture_s1_o = cx_declare(fixture_o, "s1", cx_typedef(cx_string_o));
    if (!fixture_s1_o) {
        cx_error("fixture_load: failed to declare object '::fixture::s1'.");
        goto error;
    } else {
        (*fixture_s1_o) = cx_strdup("hello world");
    }

    /* Declare ::fixture::s10 */
    fixture_s10_o = cx_declare(fixture_o, "s10", cx_typedef(cx_string_o));
    if (!fixture_s10_o) {
        cx_error("fixture_load: failed to declare object '::fixture::s10'.");
        goto error;
    } else {
        (*fixture_s10_o) = cx_strdup("@@hey you");
    }

    /* Declare ::fixture::s11 */
    fixture_s11_o = cx_declare(fixture_o, "s11", cx_typedef(cx_string_o));
    if (!fixture_s11_o) {
        cx_error("fixture_load: failed to declare object '::fixture::s11'.");
        goto error;
    } else {
        (*fixture_s11_o) = cx_strdup("@@@@@");
    }

    /* Declare ::fixture::s12 */
    fixture_s12_o = cx_declare(fixture_o, "s12", cx_typedef(cx_string_o));
    if (!fixture_s12_o) {
        cx_error("fixture_load: failed to declare object '::fixture::s12'.");
        goto error;
    } else {
        (*fixture_s12_o) = cx_strdup("@@@@@ hey");
    }

    /* Declare ::fixture::s13 */
    fixture_s13_o = cx_declare(fixture_o, "s13", cx_typedef(cx_string_o));
    if (!fixture_s13_o) {
        cx_error("fixture_load: failed to declare object '::fixture::s13'.");
        goto error;
    } else {
        (*fixture_s13_o) = cx_strdup("@@@@@hey");
    }

    /* Declare ::fixture::s14 */
    fixture_s14_o = cx_declare(fixture_o, "s14", cx_typedef(cx_string_o));
    if (!fixture_s14_o) {
        cx_error("fixture_load: failed to declare object '::fixture::s14'.");
        goto error;
    } else {
        (*fixture_s14_o) = cx_strdup("@@@@@hey you");
    }

    /* Declare ::fixture::s2 */
    fixture_s2_o = cx_declare(fixture_o, "s2", cx_typedef(cx_string_o));
    if (!fixture_s2_o) {
        cx_error("fixture_load: failed to declare object '::fixture::s2'.");
        goto error;
    } else {
        (*fixture_s2_o) = cx_strdup("hello, world!");
    }

    /* Declare ::fixture::s3 */
    fixture_s3_o = cx_declare(fixture_o, "s3", cx_typedef(cx_string_o));
    if (!fixture_s3_o) {
        cx_error("fixture_load: failed to declare object '::fixture::s3'.");
        goto error;
    } else {
        (*fixture_s3_o) = cx_strdup("@");
    }

    /* Declare ::fixture::s4 */
    fixture_s4_o = cx_declare(fixture_o, "s4", cx_typedef(cx_string_o));
    if (!fixture_s4_o) {
        cx_error("fixture_load: failed to declare object '::fixture::s4'.");
        goto error;
    } else {
        (*fixture_s4_o) = cx_strdup("@ hey");
    }

    /* Declare ::fixture::s5 */
    fixture_s5_o = cx_declare(fixture_o, "s5", cx_typedef(cx_string_o));
    if (!fixture_s5_o) {
        cx_error("fixture_load: failed to declare object '::fixture::s5'.");
        goto error;
    } else {
        (*fixture_s5_o) = cx_strdup("@hey");
    }

    /* Declare ::fixture::s6 */
    fixture_s6_o = cx_declare(fixture_o, "s6", cx_typedef(cx_string_o));
    if (!fixture_s6_o) {
        cx_error("fixture_load: failed to declare object '::fixture::s6'.");
        goto error;
    } else {
        (*fixture_s6_o) = cx_strdup("@hey you");
    }

    /* Declare ::fixture::s7 */
    fixture_s7_o = cx_declare(fixture_o, "s7", cx_typedef(cx_string_o));
    if (!fixture_s7_o) {
        cx_error("fixture_load: failed to declare object '::fixture::s7'.");
        goto error;
    } else {
        (*fixture_s7_o) = cx_strdup("@@");
    }

    /* Declare ::fixture::s8 */
    fixture_s8_o = cx_declare(fixture_o, "s8", cx_typedef(cx_string_o));
    if (!fixture_s8_o) {
        cx_error("fixture_load: failed to declare object '::fixture::s8'.");
        goto error;
    } else {
        (*fixture_s8_o) = cx_strdup("@@ hey");
    }

    /* Declare ::fixture::s9 */
    fixture_s9_o = cx_declare(fixture_o, "s9", cx_typedef(cx_string_o));
    if (!fixture_s9_o) {
        cx_error("fixture_load: failed to declare object '::fixture::s9'.");
        goto error;
    } else {
        (*fixture_s9_o) = cx_strdup("@@hey");
    }

    /* Declare ::fixture::sn */
    fixture_sn_o = cx_declare(fixture_o, "sn", cx_typedef(cx_string_o));
    if (!fixture_sn_o) {
        cx_error("fixture_load: failed to declare object '::fixture::sn'.");
        goto error;
    } else {
        (*fixture_sn_o) = NULL;
    }

    /* Declare ::fixture::u16p */
    fixture_u16p_o = cx_declare(fixture_o, "u16p", cx_typedef(cx_uint16_o));
    if (!fixture_u16p_o) {
        cx_error("fixture_load: failed to declare object '::fixture::u16p'.");
        goto error;
    } else {
        (*fixture_u16p_o) = 45;
    }

    /* Declare ::fixture::u16z */
    fixture_u16z_o = cx_declare(fixture_o, "u16z", cx_typedef(cx_uint16_o));
    if (!fixture_u16z_o) {
        cx_error("fixture_load: failed to declare object '::fixture::u16z'.");
        goto error;
    } else {
        (*fixture_u16z_o) = 0;
    }

    /* Declare ::fixture::u32p */
    fixture_u32p_o = cx_declare(fixture_o, "u32p", cx_typedef(cx_uint32_o));
    if (!fixture_u32p_o) {
        cx_error("fixture_load: failed to declare object '::fixture::u32p'.");
        goto error;
    } else {
        (*fixture_u32p_o) = 45;
    }

    /* Declare ::fixture::u32z */
    fixture_u32z_o = cx_declare(fixture_o, "u32z", cx_typedef(cx_uint32_o));
    if (!fixture_u32z_o) {
        cx_error("fixture_load: failed to declare object '::fixture::u32z'.");
        goto error;
    } else {
        (*fixture_u32z_o) = 0;
    }

    /* Declare ::fixture::u64p */
    fixture_u64p_o = cx_declare(fixture_o, "u64p", cx_typedef(cx_uint64_o));
    if (!fixture_u64p_o) {
        cx_error("fixture_load: failed to declare object '::fixture::u64p'.");
        goto error;
    } else {
        (*fixture_u64p_o) = 45;
    }

    /* Declare ::fixture::u64z */
    fixture_u64z_o = cx_declare(fixture_o, "u64z", cx_typedef(cx_uint64_o));
    if (!fixture_u64z_o) {
        cx_error("fixture_load: failed to declare object '::fixture::u64z'.");
        goto error;
    } else {
        (*fixture_u64z_o) = 0;
    }

    /* Declare ::fixture::u8p */
    fixture_u8p_o = cx_declare(fixture_o, "u8p", cx_typedef(cx_uint8_o));
    if (!fixture_u8p_o) {
        cx_error("fixture_load: failed to declare object '::fixture::u8p'.");
        goto error;
    } else {
        (*fixture_u8p_o) = 45;
    }

    /* Declare ::fixture::u8z */
    fixture_u8z_o = cx_declare(fixture_o, "u8z", cx_typedef(cx_uint8_o));
    if (!fixture_u8z_o) {
        cx_error("fixture_load: failed to declare object '::fixture::u8z'.");
        goto error;
    } else {
        (*fixture_u8z_o) = 0;
    }

    /* Declare ::fixture::v0 */
    fixture_v0_o = cx_declare(fixture_o, "v0", cx_typedef(cx_void_o));
    if (!fixture_v0_o) {
        cx_error("fixture_load: failed to declare object '::fixture::v0'.");
        goto error;
    }

    /* Declare ::fixture::v1 */
    fixture_v1_o = cx_declare(fixture_o, "v1", cx_typedef(cx_void_o));
    if (!fixture_v1_o) {
        cx_error("fixture_load: failed to declare object '::fixture::v1'.");
        goto error;
    }

    /* Declare ::fixture::v1::v1 */
    fixture_v1_v1_o = cx_declare(fixture_v1_o, "v1", cx_typedef(cx_void_o));
    if (!fixture_v1_v1_o) {
        cx_error("fixture_load: failed to declare object '::fixture::v1::v1'.");
        goto error;
    }

    /* Declare ::fixture::v1::v1::v1 */
    fixture_v1_v1_v1_o = cx_declare(fixture_v1_v1_o, "v1", cx_typedef(cx_void_o));
    if (!fixture_v1_v1_v1_o) {
        cx_error("fixture_load: failed to declare object '::fixture::v1::v1::v1'.");
        goto error;
    }

    /* Declare ::fixture::v1::v1::v2 */
    fixture_v1_v1_v2_o = cx_declare(fixture_v1_v1_o, "v2", cx_typedef(cx_void_o));
    if (!fixture_v1_v1_v2_o) {
        cx_error("fixture_load: failed to declare object '::fixture::v1::v1::v2'.");
        goto error;
    }

    /* Declare ::fixture::v1::v1::v3 */
    fixture_v1_v1_v3_o = cx_declare(fixture_v1_v1_o, "v3", cx_typedef(cx_void_o));
    if (!fixture_v1_v1_v3_o) {
        cx_error("fixture_load: failed to declare object '::fixture::v1::v1::v3'.");
        goto error;
    }

    /* Declare ::fixture::v1::v1::v4 */
    fixture_v1_v1_v4_o = cx_declare(fixture_v1_v1_o, "v4", cx_typedef(cx_void_o));
    if (!fixture_v1_v1_v4_o) {
        cx_error("fixture_load: failed to declare object '::fixture::v1::v1::v4'.");
        goto error;
    }

    /* Declare ::fixture::v1::v2 */
    fixture_v1_v2_o = cx_declare(fixture_v1_o, "v2", cx_typedef(cx_void_o));
    if (!fixture_v1_v2_o) {
        cx_error("fixture_load: failed to declare object '::fixture::v1::v2'.");
        goto error;
    }

    /* Declare ::fixture::v1::v2::v1 */
    fixture_v1_v2_v1_o = cx_declare(fixture_v1_v2_o, "v1", cx_typedef(cx_void_o));
    if (!fixture_v1_v2_v1_o) {
        cx_error("fixture_load: failed to declare object '::fixture::v1::v2::v1'.");
        goto error;
    }

    /* Declare ::fixture::v1::v2::v2 */
    fixture_v1_v2_v2_o = cx_declare(fixture_v1_v2_o, "v2", cx_typedef(cx_void_o));
    if (!fixture_v1_v2_v2_o) {
        cx_error("fixture_load: failed to declare object '::fixture::v1::v2::v2'.");
        goto error;
    }

    /* Declare ::fixture::v1::v2::v3 */
    fixture_v1_v2_v3_o = cx_declare(fixture_v1_v2_o, "v3", cx_typedef(cx_void_o));
    if (!fixture_v1_v2_v3_o) {
        cx_error("fixture_load: failed to declare object '::fixture::v1::v2::v3'.");
        goto error;
    }

    /* Declare ::fixture::v1::v2::v4 */
    fixture_v1_v2_v4_o = cx_declare(fixture_v1_v2_o, "v4", cx_typedef(cx_void_o));
    if (!fixture_v1_v2_v4_o) {
        cx_error("fixture_load: failed to declare object '::fixture::v1::v2::v4'.");
        goto error;
    }

    /* Declare ::fixture::v1::v2::v5 */
    fixture_v1_v2_v5_o = cx_declare(fixture_v1_v2_o, "v5", cx_typedef(cx_void_o));
    if (!fixture_v1_v2_v5_o) {
        cx_error("fixture_load: failed to declare object '::fixture::v1::v2::v5'.");
        goto error;
    }

    /* Declare ::fixture::v1::v3 */
    fixture_v1_v3_o = cx_declare(fixture_v1_o, "v3", cx_typedef(cx_void_o));
    if (!fixture_v1_v3_o) {
        cx_error("fixture_load: failed to declare object '::fixture::v1::v3'.");
        goto error;
    }

    /* Declare ::fixture::v1::v3::v1 */
    fixture_v1_v3_v1_o = cx_declare(fixture_v1_v3_o, "v1", cx_typedef(cx_void_o));
    if (!fixture_v1_v3_v1_o) {
        cx_error("fixture_load: failed to declare object '::fixture::v1::v3::v1'.");
        goto error;
    }

    /* Declare ::fixture::v1::v3::v2 */
    fixture_v1_v3_v2_o = cx_declare(fixture_v1_v3_o, "v2", cx_typedef(cx_void_o));
    if (!fixture_v1_v3_v2_o) {
        cx_error("fixture_load: failed to declare object '::fixture::v1::v3::v2'.");
        goto error;
    }

    /* Declare ::fixture::v1::v3::v3 */
    fixture_v1_v3_v3_o = cx_declare(fixture_v1_v3_o, "v3", cx_typedef(cx_void_o));
    if (!fixture_v1_v3_v3_o) {
        cx_error("fixture_load: failed to declare object '::fixture::v1::v3::v3'.");
        goto error;
    }

    /* Declare ::fixture::v1::v3::v4 */
    fixture_v1_v3_v4_o = cx_declare(fixture_v1_v3_o, "v4", cx_typedef(cx_void_o));
    if (!fixture_v1_v3_v4_o) {
        cx_error("fixture_load: failed to declare object '::fixture::v1::v3::v4'.");
        goto error;
    }

    /* Declare ::fixture::v1::v3::v5 */
    fixture_v1_v3_v5_o = cx_declare(fixture_v1_v3_o, "v5", cx_typedef(cx_void_o));
    if (!fixture_v1_v3_v5_o) {
        cx_error("fixture_load: failed to declare object '::fixture::v1::v3::v5'.");
        goto error;
    }

    /* Declare ::fixture::v1::v3::v6 */
    fixture_v1_v3_v6_o = cx_declare(fixture_v1_v3_o, "v6", cx_typedef(cx_void_o));
    if (!fixture_v1_v3_v6_o) {
        cx_error("fixture_load: failed to declare object '::fixture::v1::v3::v6'.");
        goto error;
    }

    /* Define ::fixture::Dog::lover */
    if (!cx_checkState(fixture_Dog_lover_o, CX_DEFINED)) {
        fixture_Dog_lover_o->type = cx_resolve_ext(fixture_Dog_lover_o, NULL, "::fixture::Dog", FALSE, "element ::fixture::Dog::lover.type");
        fixture_Dog_lover_o->modifiers = 0x0;
        fixture_Dog_lover_o->state = 0x6;
        fixture_Dog_lover_o->weak = FALSE;
        fixture_Dog_lover_o->id = 3;
        if (cx_define(fixture_Dog_lover_o)) {
            cx_error("fixture_load: failed to define object '::fixture::Dog::lover'.");
            goto error;
        }
    }

    /* Define ::fixture::Dog */
    if (!cx_checkState(fixture_Dog_o, CX_DEFINED)) {
        cx_type(fixture_Dog_o)->defaultType = cx_resolve_ext(fixture_Dog_o, NULL, "::cortex::lang::member", FALSE, "element ::fixture::Dog.defaultType");
        cx_type(fixture_Dog_o)->parentType = NULL;
        cx_type(fixture_Dog_o)->parentState = 0x0;
        cx_interface(fixture_Dog_o)->base = NULL;
        cx_struct(fixture_Dog_o)->baseAccess = 0x0;
        fixture_Dog_o->implements.length = 0;
        fixture_Dog_o->implements.buffer = NULL;
        if (cx_define(fixture_Dog_o)) {
            cx_error("fixture_load: failed to define object '::fixture::Dog'.");
            goto error;
        }
    }

    if (cx_type(fixture_Dog_o)->size != sizeof(struct fixture_Dog_s)) {
        cx_error("fixture_load: calculated size '%d' of type '::fixture::Dog' doesn't match C-type size '%d'", cx_type(fixture_Dog_o)->size, sizeof(struct fixture_Dog_s));
    }

    /* Declare ::fixture::dog1 */
    fixture_dog1_o = cx_declare(fixture_o, "dog1", cx_typedef(fixture_Dog_o));
    if (!fixture_dog1_o) {
        cx_error("fixture_load: failed to declare object '::fixture::dog1'.");
        goto error;
    }

    /* Define ::fixture::dog1 */
    if (!cx_checkState(fixture_dog1_o, CX_DEFINED)) {
        fixture_dog1_o->breed = FIXTURE_GoldenRetriever;
        fixture_dog1_o->name = cx_strdup("Gijs");
        fixture_dog1_o->age = 10;
        fixture_dog1_o->lover = NULL;
        if (cx_define(fixture_dog1_o)) {
            cx_error("fixture_load: failed to define object '::fixture::dog1'.");
            goto error;
        }
    }

    /* Declare ::fixture::dog2 */
    fixture_dog2_o = cx_declare(fixture_o, "dog2", cx_typedef(fixture_Dog_o));
    if (!fixture_dog2_o) {
        cx_error("fixture_load: failed to declare object '::fixture::dog2'.");
        goto error;
    }

    /* Define ::fixture::dog2 */
    if (!cx_checkState(fixture_dog2_o, CX_DEFINED)) {
        fixture_dog2_o->breed = FIXTURE_Pug;
        fixture_dog2_o->name = cx_strdup("Lolly");
        fixture_dog2_o->age = 4;
        fixture_dog2_o->lover = NULL;
        if (cx_define(fixture_dog2_o)) {
            cx_error("fixture_load: failed to define object '::fixture::dog2'.");
            goto error;
        }
    }

    /* Declare ::fixture::dog3 */
    fixture_dog3_o = cx_declare(fixture_o, "dog3", cx_typedef(fixture_Dog_o));
    if (!fixture_dog3_o) {
        cx_error("fixture_load: failed to declare object '::fixture::dog3'.");
        goto error;
    }

    /* Define ::fixture::dog3 */
    if (!cx_checkState(fixture_dog3_o, CX_DEFINED)) {
        fixture_dog3_o->breed = FIXTURE_Chihuahua;
        fixture_dog3_o->name = cx_strdup("I'm annoying");
        fixture_dog3_o->age = 3;
        fixture_dog3_o->lover = cx_resolve_ext(fixture_dog3_o, NULL, "::fixture::dog2", FALSE, "element ::fixture::dog3.lover");
        if (cx_define(fixture_dog3_o)) {
            cx_error("fixture_load: failed to define object '::fixture::dog3'.");
            goto error;
        }
    }

    /* Declare ::fixture::v0::dog1 */
    fixture_v0_dog1_o = cx_declare(fixture_v0_o, "dog1", cx_typedef(fixture_Dog_o));
    if (!fixture_v0_dog1_o) {
        cx_error("fixture_load: failed to declare object '::fixture::v0::dog1'.");
        goto error;
    }

    /* Define ::fixture::v0::dog1 */
    if (!cx_checkState(fixture_v0_dog1_o, CX_DEFINED)) {
        fixture_v0_dog1_o->breed = FIXTURE_Pug;
        fixture_v0_dog1_o->name = cx_strdup("MyPug");
        fixture_v0_dog1_o->age = 55;
        fixture_v0_dog1_o->lover = NULL;
        if (cx_define(fixture_v0_dog1_o)) {
            cx_error("fixture_load: failed to define object '::fixture::v0::dog1'.");
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
