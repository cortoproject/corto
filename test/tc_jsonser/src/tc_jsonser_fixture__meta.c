/* tc_jsonser_fixture__meta.c
 *
 * Loads objects in database.
 * This file contains generated code. Do not modify!
 */

#include "tc_jsonser_fixture__type.h"

/* Variable definitions */
cx_object tc_jsonser_fixture_o;
cx_bool (*tc_jsonser_fixture_bf_o);
tc_jsonser_fixture_color (*tc_jsonser_fixture_black_o);
cx_bool (*tc_jsonser_fixture_bt_o);
cx_char (*tc_jsonser_fixture_c1_o);
cx_char (*tc_jsonser_fixture_c2_o);
cx_char (*tc_jsonser_fixture_c3_o);
cx_char (*tc_jsonser_fixture_c4_o);
cx_char (*tc_jsonser_fixture_c5_o);
cx_bitmask tc_jsonser_fixture_color_o;
cx_constant (*tc_jsonser_fixture_color_blue_o);
cx_constant (*tc_jsonser_fixture_color_green_o);
cx_constant (*tc_jsonser_fixture_color_red_o);
cx_enum tc_jsonser_fixture_Djinn_o;
cx_constant (*tc_jsonser_fixture_Djinn_Jupiter_o);
cx_constant (*tc_jsonser_fixture_Djinn_Mars_o);
cx_constant (*tc_jsonser_fixture_Djinn_Mercury_o);
cx_constant (*tc_jsonser_fixture_Djinn_Venus_o);
cx_class tc_jsonser_fixture_Dog_o;
cx_member tc_jsonser_fixture_Dog_age_o;
cx_member tc_jsonser_fixture_Dog_breed_o;
cx_member tc_jsonser_fixture_Dog_lover_o;
cx_member tc_jsonser_fixture_Dog_name_o;
tc_jsonser_fixture_Dog tc_jsonser_fixture_dog1_o;
tc_jsonser_fixture_Dog tc_jsonser_fixture_dog2_o;
tc_jsonser_fixture_Dog tc_jsonser_fixture_dog3_o;
cx_enum tc_jsonser_fixture_DogBreed_o;
cx_constant (*tc_jsonser_fixture_DogBreed_Chihuahua_o);
cx_constant (*tc_jsonser_fixture_DogBreed_GoldenRetriever_o);
cx_constant (*tc_jsonser_fixture_DogBreed_Pug_o);
cx_float32 (*tc_jsonser_fixture_f32n_o);
cx_float32 (*tc_jsonser_fixture_f32p_o);
cx_float32 (*tc_jsonser_fixture_f32z_o);
cx_float64 (*tc_jsonser_fixture_f64n_o);
cx_float64 (*tc_jsonser_fixture_f64p_o);
cx_float64 (*tc_jsonser_fixture_f64z_o);
tc_jsonser_fixture_Djinn (*tc_jsonser_fixture_Flint_o);
tc_jsonser_fixture_Djinn (*tc_jsonser_fixture_Forge_o);
tc_jsonser_fixture_Djinn (*tc_jsonser_fixture_Gust_o);
cx_int16 (*tc_jsonser_fixture_i16n_o);
cx_int16 (*tc_jsonser_fixture_i16p_o);
cx_int16 (*tc_jsonser_fixture_i16z_o);
cx_int32 (*tc_jsonser_fixture_i32n_o);
cx_int32 (*tc_jsonser_fixture_i32p_o);
cx_int32 (*tc_jsonser_fixture_i32z_o);
cx_int64 (*tc_jsonser_fixture_i64n_o);
cx_int64 (*tc_jsonser_fixture_i64p_o);
cx_int64 (*tc_jsonser_fixture_i64z_o);
cx_int8 (*tc_jsonser_fixture_i8n_o);
cx_int8 (*tc_jsonser_fixture_i8p_o);
cx_int8 (*tc_jsonser_fixture_i8z_o);
cx_array tc_jsonser_fixture_intarray_o;
tc_jsonser_fixture_intarray (*tc_jsonser_fixture_intarray1_o);
cx_void (*tc_jsonser_fixture_namesp_o);
cx_int16 (*tc_jsonser_fixture_namesp_a_o);
cx_string (*tc_jsonser_fixture_namesp_b_o);
tc_jsonser_fixture_point2D (*tc_jsonser_fixture_p_o);
cx_struct tc_jsonser_fixture_point2D_o;
cx_member tc_jsonser_fixture_point2D_x_o;
cx_member tc_jsonser_fixture_point2D_y_o;
cx_string (*tc_jsonser_fixture_s1_o);
cx_string (*tc_jsonser_fixture_s10_o);
cx_string (*tc_jsonser_fixture_s11_o);
cx_string (*tc_jsonser_fixture_s12_o);
cx_string (*tc_jsonser_fixture_s13_o);
cx_string (*tc_jsonser_fixture_s14_o);
cx_string (*tc_jsonser_fixture_s2_o);
cx_string (*tc_jsonser_fixture_s3_o);
cx_string (*tc_jsonser_fixture_s4_o);
cx_string (*tc_jsonser_fixture_s5_o);
cx_string (*tc_jsonser_fixture_s6_o);
cx_string (*tc_jsonser_fixture_s7_o);
cx_string (*tc_jsonser_fixture_s8_o);
cx_string (*tc_jsonser_fixture_s9_o);
tc_jsonser_fixture_Djinn (*tc_jsonser_fixture_Sleet_o);
cx_string (*tc_jsonser_fixture_sn_o);
cx_list tc_jsonser_fixture_stringlist_o;
tc_jsonser_fixture_stringlist (*tc_jsonser_fixture_stringlist1_o);
cx_uint16 (*tc_jsonser_fixture_u16p_o);
cx_uint16 (*tc_jsonser_fixture_u16z_o);
cx_uint32 (*tc_jsonser_fixture_u32p_o);
cx_uint32 (*tc_jsonser_fixture_u32z_o);
cx_uint64 (*tc_jsonser_fixture_u64p_o);
cx_uint64 (*tc_jsonser_fixture_u64z_o);
cx_uint8 (*tc_jsonser_fixture_u8p_o);
cx_uint8 (*tc_jsonser_fixture_u8z_o);
cx_void (*tc_jsonser_fixture_v0_o);
tc_jsonser_fixture_Dog tc_jsonser_fixture_v0_dog1_o;
cx_void (*tc_jsonser_fixture_v1_o);
cx_void (*tc_jsonser_fixture_v1_v1_o);
cx_void (*tc_jsonser_fixture_v1_v1_v1_o);
cx_void (*tc_jsonser_fixture_v1_v1_v2_o);
cx_void (*tc_jsonser_fixture_v1_v1_v3_o);
cx_void (*tc_jsonser_fixture_v1_v1_v4_o);
cx_void (*tc_jsonser_fixture_v1_v2_o);
cx_void (*tc_jsonser_fixture_v1_v2_v1_o);
cx_void (*tc_jsonser_fixture_v1_v2_v2_o);
cx_void (*tc_jsonser_fixture_v1_v2_v3_o);
cx_void (*tc_jsonser_fixture_v1_v2_v4_o);
cx_void (*tc_jsonser_fixture_v1_v2_v5_o);
cx_void (*tc_jsonser_fixture_v1_v3_o);
cx_void (*tc_jsonser_fixture_v1_v3_v1_o);
cx_void (*tc_jsonser_fixture_v1_v3_v2_o);
cx_void (*tc_jsonser_fixture_v1_v3_v3_o);
cx_void (*tc_jsonser_fixture_v1_v3_v4_o);
cx_void (*tc_jsonser_fixture_v1_v3_v5_o);
cx_void (*tc_jsonser_fixture_v1_v3_v6_o);
tc_jsonser_fixture_color (*tc_jsonser_fixture_white_o);
tc_jsonser_fixture_color (*tc_jsonser_fixture_yellow_o);

/* Load objects in database */
int tc_jsonser_fixture_load(void) {
    cx_object _a_; /* Used for resolving anonymous objects */
    _a_ = NULL;

    /* Declare ::tc_jsonser_fixture */
    tc_jsonser_fixture_o = cx_declare(root_o, "tc_jsonser_fixture", cx_type(cx_object_o));
    if (!tc_jsonser_fixture_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture */
    if (!cx_checkState(tc_jsonser_fixture_o, CX_DEFINED)) {
        if (cx_define(tc_jsonser_fixture_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::bf */
    tc_jsonser_fixture_bf_o = cx_declare(tc_jsonser_fixture_o, "bf", cx_type(cx_bool_o));
    if (!tc_jsonser_fixture_bf_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::bf'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::bf */
    if (!cx_checkState(tc_jsonser_fixture_bf_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_bf_o) = FALSE;
        if (cx_define(tc_jsonser_fixture_bf_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::bf'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::bt */
    tc_jsonser_fixture_bt_o = cx_declare(tc_jsonser_fixture_o, "bt", cx_type(cx_bool_o));
    if (!tc_jsonser_fixture_bt_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::bt'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::bt */
    if (!cx_checkState(tc_jsonser_fixture_bt_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_bt_o) = TRUE;
        if (cx_define(tc_jsonser_fixture_bt_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::bt'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::c1 */
    tc_jsonser_fixture_c1_o = cx_declare(tc_jsonser_fixture_o, "c1", cx_type(cx_char_o));
    if (!tc_jsonser_fixture_c1_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::c1'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::c1 */
    if (!cx_checkState(tc_jsonser_fixture_c1_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_c1_o) = 'a';
        if (cx_define(tc_jsonser_fixture_c1_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::c1'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::c2 */
    tc_jsonser_fixture_c2_o = cx_declare(tc_jsonser_fixture_o, "c2", cx_type(cx_char_o));
    if (!tc_jsonser_fixture_c2_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::c2'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::c2 */
    if (!cx_checkState(tc_jsonser_fixture_c2_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_c2_o) = 'A';
        if (cx_define(tc_jsonser_fixture_c2_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::c2'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::c3 */
    tc_jsonser_fixture_c3_o = cx_declare(tc_jsonser_fixture_o, "c3", cx_type(cx_char_o));
    if (!tc_jsonser_fixture_c3_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::c3'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::c3 */
    if (!cx_checkState(tc_jsonser_fixture_c3_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_c3_o) = '0';
        if (cx_define(tc_jsonser_fixture_c3_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::c3'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::c4 */
    tc_jsonser_fixture_c4_o = cx_declare(tc_jsonser_fixture_o, "c4", cx_type(cx_char_o));
    if (!tc_jsonser_fixture_c4_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::c4'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::c4 */
    if (!cx_checkState(tc_jsonser_fixture_c4_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_c4_o) = '\n';
        if (cx_define(tc_jsonser_fixture_c4_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::c4'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::c5 */
    tc_jsonser_fixture_c5_o = cx_declare(tc_jsonser_fixture_o, "c5", cx_type(cx_char_o));
    if (!tc_jsonser_fixture_c5_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::c5'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::c5 */
    if (!cx_checkState(tc_jsonser_fixture_c5_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_c5_o) = '\0';
        if (cx_define(tc_jsonser_fixture_c5_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::c5'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::color */
    tc_jsonser_fixture_color_o = cx_declare(tc_jsonser_fixture_o, "color", cx_type(cx_bitmask_o));
    if (!tc_jsonser_fixture_color_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::color'.");
        goto error;
    }

    /* Declare ::tc_jsonser_fixture::color::blue */
    tc_jsonser_fixture_color_blue_o = cx_declare(tc_jsonser_fixture_color_o, "blue", cx_type(cx_constant_o));
    if (!tc_jsonser_fixture_color_blue_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::color::blue'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::color::blue */
    if (!cx_checkState(tc_jsonser_fixture_color_blue_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_color_blue_o) = 4;
        if (cx_define(tc_jsonser_fixture_color_blue_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::color::blue'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::color::green */
    tc_jsonser_fixture_color_green_o = cx_declare(tc_jsonser_fixture_color_o, "green", cx_type(cx_constant_o));
    if (!tc_jsonser_fixture_color_green_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::color::green'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::color::green */
    if (!cx_checkState(tc_jsonser_fixture_color_green_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_color_green_o) = 2;
        if (cx_define(tc_jsonser_fixture_color_green_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::color::green'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::color::red */
    tc_jsonser_fixture_color_red_o = cx_declare(tc_jsonser_fixture_color_o, "red", cx_type(cx_constant_o));
    if (!tc_jsonser_fixture_color_red_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::color::red'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::color::red */
    if (!cx_checkState(tc_jsonser_fixture_color_red_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_color_red_o) = 1;
        if (cx_define(tc_jsonser_fixture_color_red_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::color::red'.");
            goto error;
        }
    }

    /* Define ::tc_jsonser_fixture::color */
    if (!cx_checkState(tc_jsonser_fixture_color_o, CX_DEFINED)) {
        if (cx_define(tc_jsonser_fixture_color_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::color'.");
            goto error;
        }
    }

    if (cx_type(tc_jsonser_fixture_color_o)->size != sizeof(tc_jsonser_fixture_color)) {
        cx_error("tc_jsonser_fixture_load: calculated size '%d' of type '::tc_jsonser_fixture::color' doesn't match C-type size '%d'", cx_type(tc_jsonser_fixture_color_o)->size, sizeof(tc_jsonser_fixture_color));
    }

    /* Declare ::tc_jsonser_fixture::black */
    tc_jsonser_fixture_black_o = cx_declare(tc_jsonser_fixture_o, "black", cx_type(tc_jsonser_fixture_color_o));
    if (!tc_jsonser_fixture_black_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::black'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::black */
    if (!cx_checkState(tc_jsonser_fixture_black_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_black_o) = 0x0;
        if (cx_define(tc_jsonser_fixture_black_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::black'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::white */
    tc_jsonser_fixture_white_o = cx_declare(tc_jsonser_fixture_o, "white", cx_type(tc_jsonser_fixture_color_o));
    if (!tc_jsonser_fixture_white_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::white'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::white */
    if (!cx_checkState(tc_jsonser_fixture_white_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_white_o) = 0x7;
        if (cx_define(tc_jsonser_fixture_white_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::white'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::yellow */
    tc_jsonser_fixture_yellow_o = cx_declare(tc_jsonser_fixture_o, "yellow", cx_type(tc_jsonser_fixture_color_o));
    if (!tc_jsonser_fixture_yellow_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::yellow'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::yellow */
    if (!cx_checkState(tc_jsonser_fixture_yellow_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_yellow_o) = 0x3;
        if (cx_define(tc_jsonser_fixture_yellow_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::yellow'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::Djinn */
    tc_jsonser_fixture_Djinn_o = cx_declare(tc_jsonser_fixture_o, "Djinn", cx_type(cx_enum_o));
    if (!tc_jsonser_fixture_Djinn_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::Djinn'.");
        goto error;
    }

    /* Declare ::tc_jsonser_fixture::Djinn::Jupiter */
    tc_jsonser_fixture_Djinn_Jupiter_o = cx_declare(tc_jsonser_fixture_Djinn_o, "Jupiter", cx_type(cx_constant_o));
    if (!tc_jsonser_fixture_Djinn_Jupiter_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::Djinn::Jupiter'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::Djinn::Jupiter */
    if (!cx_checkState(tc_jsonser_fixture_Djinn_Jupiter_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_Djinn_Jupiter_o) = 3;
        if (cx_define(tc_jsonser_fixture_Djinn_Jupiter_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::Djinn::Jupiter'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::Djinn::Mars */
    tc_jsonser_fixture_Djinn_Mars_o = cx_declare(tc_jsonser_fixture_Djinn_o, "Mars", cx_type(cx_constant_o));
    if (!tc_jsonser_fixture_Djinn_Mars_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::Djinn::Mars'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::Djinn::Mars */
    if (!cx_checkState(tc_jsonser_fixture_Djinn_Mars_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_Djinn_Mars_o) = 2;
        if (cx_define(tc_jsonser_fixture_Djinn_Mars_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::Djinn::Mars'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::Djinn::Mercury */
    tc_jsonser_fixture_Djinn_Mercury_o = cx_declare(tc_jsonser_fixture_Djinn_o, "Mercury", cx_type(cx_constant_o));
    if (!tc_jsonser_fixture_Djinn_Mercury_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::Djinn::Mercury'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::Djinn::Mercury */
    if (!cx_checkState(tc_jsonser_fixture_Djinn_Mercury_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_Djinn_Mercury_o) = 0;
        if (cx_define(tc_jsonser_fixture_Djinn_Mercury_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::Djinn::Mercury'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::Djinn::Venus */
    tc_jsonser_fixture_Djinn_Venus_o = cx_declare(tc_jsonser_fixture_Djinn_o, "Venus", cx_type(cx_constant_o));
    if (!tc_jsonser_fixture_Djinn_Venus_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::Djinn::Venus'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::Djinn::Venus */
    if (!cx_checkState(tc_jsonser_fixture_Djinn_Venus_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_Djinn_Venus_o) = 1;
        if (cx_define(tc_jsonser_fixture_Djinn_Venus_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::Djinn::Venus'.");
            goto error;
        }
    }

    /* Define ::tc_jsonser_fixture::Djinn */
    if (!cx_checkState(tc_jsonser_fixture_Djinn_o, CX_DEFINED)) {
        if (cx_define(tc_jsonser_fixture_Djinn_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::Djinn'.");
            goto error;
        }
    }

    if (cx_type(tc_jsonser_fixture_Djinn_o)->size != sizeof(tc_jsonser_fixture_Djinn)) {
        cx_error("tc_jsonser_fixture_load: calculated size '%d' of type '::tc_jsonser_fixture::Djinn' doesn't match C-type size '%d'", cx_type(tc_jsonser_fixture_Djinn_o)->size, sizeof(tc_jsonser_fixture_Djinn));
    }

    /* Declare ::tc_jsonser_fixture::Flint */
    tc_jsonser_fixture_Flint_o = cx_declare(tc_jsonser_fixture_o, "Flint", cx_type(tc_jsonser_fixture_Djinn_o));
    if (!tc_jsonser_fixture_Flint_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::Flint'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::Flint */
    if (!cx_checkState(tc_jsonser_fixture_Flint_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_Flint_o) = Tc_jsonser_fixture_Venus;
        if (cx_define(tc_jsonser_fixture_Flint_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::Flint'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::Forge */
    tc_jsonser_fixture_Forge_o = cx_declare(tc_jsonser_fixture_o, "Forge", cx_type(tc_jsonser_fixture_Djinn_o));
    if (!tc_jsonser_fixture_Forge_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::Forge'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::Forge */
    if (!cx_checkState(tc_jsonser_fixture_Forge_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_Forge_o) = Tc_jsonser_fixture_Mars;
        if (cx_define(tc_jsonser_fixture_Forge_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::Forge'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::Gust */
    tc_jsonser_fixture_Gust_o = cx_declare(tc_jsonser_fixture_o, "Gust", cx_type(tc_jsonser_fixture_Djinn_o));
    if (!tc_jsonser_fixture_Gust_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::Gust'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::Gust */
    if (!cx_checkState(tc_jsonser_fixture_Gust_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_Gust_o) = Tc_jsonser_fixture_Jupiter;
        if (cx_define(tc_jsonser_fixture_Gust_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::Gust'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::Sleet */
    tc_jsonser_fixture_Sleet_o = cx_declare(tc_jsonser_fixture_o, "Sleet", cx_type(tc_jsonser_fixture_Djinn_o));
    if (!tc_jsonser_fixture_Sleet_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::Sleet'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::Sleet */
    if (!cx_checkState(tc_jsonser_fixture_Sleet_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_Sleet_o) = Tc_jsonser_fixture_Mercury;
        if (cx_define(tc_jsonser_fixture_Sleet_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::Sleet'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::Dog */
    tc_jsonser_fixture_Dog_o = cx_declare(tc_jsonser_fixture_o, "Dog", cx_type(cx_class_o));
    if (!tc_jsonser_fixture_Dog_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::Dog'.");
        goto error;
    }

    /* Declare ::tc_jsonser_fixture::Dog::age */
    tc_jsonser_fixture_Dog_age_o = cx_declare(tc_jsonser_fixture_Dog_o, "age", cx_type(cx_member_o));
    if (!tc_jsonser_fixture_Dog_age_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::Dog::age'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::Dog::age */
    if (!cx_checkState(tc_jsonser_fixture_Dog_age_o, CX_DEFINED)) {
        tc_jsonser_fixture_Dog_age_o->type = cx_resolve_ext(tc_jsonser_fixture_Dog_age_o, NULL, "::cortex::lang::uint8", FALSE, "element ::tc_jsonser_fixture::Dog::age.type");
        tc_jsonser_fixture_Dog_age_o->modifiers = 0x0;
        tc_jsonser_fixture_Dog_age_o->state = 0x6;
        tc_jsonser_fixture_Dog_age_o->weak = FALSE;
        tc_jsonser_fixture_Dog_age_o->id = 2;
        if (cx_define(tc_jsonser_fixture_Dog_age_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::Dog::age'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::Dog::breed */
    tc_jsonser_fixture_Dog_breed_o = cx_declare(tc_jsonser_fixture_Dog_o, "breed", cx_type(cx_member_o));
    if (!tc_jsonser_fixture_Dog_breed_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::Dog::breed'.");
        goto error;
    }

    /* Declare ::tc_jsonser_fixture::Dog::lover */
    tc_jsonser_fixture_Dog_lover_o = cx_declare(tc_jsonser_fixture_Dog_o, "lover", cx_type(cx_member_o));
    if (!tc_jsonser_fixture_Dog_lover_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::Dog::lover'.");
        goto error;
    }

    /* Declare ::tc_jsonser_fixture::Dog::name */
    tc_jsonser_fixture_Dog_name_o = cx_declare(tc_jsonser_fixture_Dog_o, "name", cx_type(cx_member_o));
    if (!tc_jsonser_fixture_Dog_name_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::Dog::name'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::Dog::name */
    if (!cx_checkState(tc_jsonser_fixture_Dog_name_o, CX_DEFINED)) {
        tc_jsonser_fixture_Dog_name_o->type = cx_resolve_ext(tc_jsonser_fixture_Dog_name_o, NULL, "::cortex::lang::string", FALSE, "element ::tc_jsonser_fixture::Dog::name.type");
        tc_jsonser_fixture_Dog_name_o->modifiers = 0x0;
        tc_jsonser_fixture_Dog_name_o->state = 0x6;
        tc_jsonser_fixture_Dog_name_o->weak = FALSE;
        tc_jsonser_fixture_Dog_name_o->id = 1;
        if (cx_define(tc_jsonser_fixture_Dog_name_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::Dog::name'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::DogBreed */
    tc_jsonser_fixture_DogBreed_o = cx_declare(tc_jsonser_fixture_o, "DogBreed", cx_type(cx_enum_o));
    if (!tc_jsonser_fixture_DogBreed_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::DogBreed'.");
        goto error;
    }

    /* Declare ::tc_jsonser_fixture::DogBreed::Chihuahua */
    tc_jsonser_fixture_DogBreed_Chihuahua_o = cx_declare(tc_jsonser_fixture_DogBreed_o, "Chihuahua", cx_type(cx_constant_o));
    if (!tc_jsonser_fixture_DogBreed_Chihuahua_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::DogBreed::Chihuahua'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::DogBreed::Chihuahua */
    if (!cx_checkState(tc_jsonser_fixture_DogBreed_Chihuahua_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_DogBreed_Chihuahua_o) = 2;
        if (cx_define(tc_jsonser_fixture_DogBreed_Chihuahua_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::DogBreed::Chihuahua'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::DogBreed::GoldenRetriever */
    tc_jsonser_fixture_DogBreed_GoldenRetriever_o = cx_declare(tc_jsonser_fixture_DogBreed_o, "GoldenRetriever", cx_type(cx_constant_o));
    if (!tc_jsonser_fixture_DogBreed_GoldenRetriever_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::DogBreed::GoldenRetriever'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::DogBreed::GoldenRetriever */
    if (!cx_checkState(tc_jsonser_fixture_DogBreed_GoldenRetriever_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_DogBreed_GoldenRetriever_o) = 0;
        if (cx_define(tc_jsonser_fixture_DogBreed_GoldenRetriever_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::DogBreed::GoldenRetriever'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::DogBreed::Pug */
    tc_jsonser_fixture_DogBreed_Pug_o = cx_declare(tc_jsonser_fixture_DogBreed_o, "Pug", cx_type(cx_constant_o));
    if (!tc_jsonser_fixture_DogBreed_Pug_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::DogBreed::Pug'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::DogBreed::Pug */
    if (!cx_checkState(tc_jsonser_fixture_DogBreed_Pug_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_DogBreed_Pug_o) = 1;
        if (cx_define(tc_jsonser_fixture_DogBreed_Pug_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::DogBreed::Pug'.");
            goto error;
        }
    }

    /* Define ::tc_jsonser_fixture::DogBreed */
    if (!cx_checkState(tc_jsonser_fixture_DogBreed_o, CX_DEFINED)) {
        if (cx_define(tc_jsonser_fixture_DogBreed_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::DogBreed'.");
            goto error;
        }
    }

    if (cx_type(tc_jsonser_fixture_DogBreed_o)->size != sizeof(tc_jsonser_fixture_DogBreed)) {
        cx_error("tc_jsonser_fixture_load: calculated size '%d' of type '::tc_jsonser_fixture::DogBreed' doesn't match C-type size '%d'", cx_type(tc_jsonser_fixture_DogBreed_o)->size, sizeof(tc_jsonser_fixture_DogBreed));
    }

    /* Define ::tc_jsonser_fixture::Dog::breed */
    if (!cx_checkState(tc_jsonser_fixture_Dog_breed_o, CX_DEFINED)) {
        tc_jsonser_fixture_Dog_breed_o->type = cx_resolve_ext(tc_jsonser_fixture_Dog_breed_o, NULL, "::tc_jsonser_fixture::DogBreed", FALSE, "element ::tc_jsonser_fixture::Dog::breed.type");
        tc_jsonser_fixture_Dog_breed_o->modifiers = 0x0;
        tc_jsonser_fixture_Dog_breed_o->state = 0x6;
        tc_jsonser_fixture_Dog_breed_o->weak = FALSE;
        tc_jsonser_fixture_Dog_breed_o->id = 0;
        if (cx_define(tc_jsonser_fixture_Dog_breed_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::Dog::breed'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::f32n */
    tc_jsonser_fixture_f32n_o = cx_declare(tc_jsonser_fixture_o, "f32n", cx_type(cx_float32_o));
    if (!tc_jsonser_fixture_f32n_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::f32n'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::f32n */
    if (!cx_checkState(tc_jsonser_fixture_f32n_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_f32n_o) = -2.450000;
        if (cx_define(tc_jsonser_fixture_f32n_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::f32n'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::f32p */
    tc_jsonser_fixture_f32p_o = cx_declare(tc_jsonser_fixture_o, "f32p", cx_type(cx_float32_o));
    if (!tc_jsonser_fixture_f32p_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::f32p'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::f32p */
    if (!cx_checkState(tc_jsonser_fixture_f32p_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_f32p_o) = 45.200001;
        if (cx_define(tc_jsonser_fixture_f32p_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::f32p'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::f32z */
    tc_jsonser_fixture_f32z_o = cx_declare(tc_jsonser_fixture_o, "f32z", cx_type(cx_float32_o));
    if (!tc_jsonser_fixture_f32z_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::f32z'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::f32z */
    if (!cx_checkState(tc_jsonser_fixture_f32z_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_f32z_o) = 0.000000;
        if (cx_define(tc_jsonser_fixture_f32z_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::f32z'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::f64n */
    tc_jsonser_fixture_f64n_o = cx_declare(tc_jsonser_fixture_o, "f64n", cx_type(cx_float64_o));
    if (!tc_jsonser_fixture_f64n_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::f64n'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::f64n */
    if (!cx_checkState(tc_jsonser_fixture_f64n_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_f64n_o) = -2.450000;
        if (cx_define(tc_jsonser_fixture_f64n_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::f64n'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::f64p */
    tc_jsonser_fixture_f64p_o = cx_declare(tc_jsonser_fixture_o, "f64p", cx_type(cx_float64_o));
    if (!tc_jsonser_fixture_f64p_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::f64p'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::f64p */
    if (!cx_checkState(tc_jsonser_fixture_f64p_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_f64p_o) = 45.200000;
        if (cx_define(tc_jsonser_fixture_f64p_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::f64p'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::f64z */
    tc_jsonser_fixture_f64z_o = cx_declare(tc_jsonser_fixture_o, "f64z", cx_type(cx_float64_o));
    if (!tc_jsonser_fixture_f64z_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::f64z'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::f64z */
    if (!cx_checkState(tc_jsonser_fixture_f64z_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_f64z_o) = 0.000000;
        if (cx_define(tc_jsonser_fixture_f64z_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::f64z'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::i16n */
    tc_jsonser_fixture_i16n_o = cx_declare(tc_jsonser_fixture_o, "i16n", cx_type(cx_int16_o));
    if (!tc_jsonser_fixture_i16n_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::i16n'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::i16n */
    if (!cx_checkState(tc_jsonser_fixture_i16n_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_i16n_o) = -2;
        if (cx_define(tc_jsonser_fixture_i16n_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::i16n'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::i16p */
    tc_jsonser_fixture_i16p_o = cx_declare(tc_jsonser_fixture_o, "i16p", cx_type(cx_int16_o));
    if (!tc_jsonser_fixture_i16p_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::i16p'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::i16p */
    if (!cx_checkState(tc_jsonser_fixture_i16p_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_i16p_o) = 45;
        if (cx_define(tc_jsonser_fixture_i16p_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::i16p'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::i16z */
    tc_jsonser_fixture_i16z_o = cx_declare(tc_jsonser_fixture_o, "i16z", cx_type(cx_int16_o));
    if (!tc_jsonser_fixture_i16z_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::i16z'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::i16z */
    if (!cx_checkState(tc_jsonser_fixture_i16z_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_i16z_o) = 0;
        if (cx_define(tc_jsonser_fixture_i16z_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::i16z'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::i32n */
    tc_jsonser_fixture_i32n_o = cx_declare(tc_jsonser_fixture_o, "i32n", cx_type(cx_int32_o));
    if (!tc_jsonser_fixture_i32n_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::i32n'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::i32n */
    if (!cx_checkState(tc_jsonser_fixture_i32n_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_i32n_o) = -2;
        if (cx_define(tc_jsonser_fixture_i32n_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::i32n'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::i32p */
    tc_jsonser_fixture_i32p_o = cx_declare(tc_jsonser_fixture_o, "i32p", cx_type(cx_int32_o));
    if (!tc_jsonser_fixture_i32p_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::i32p'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::i32p */
    if (!cx_checkState(tc_jsonser_fixture_i32p_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_i32p_o) = 45;
        if (cx_define(tc_jsonser_fixture_i32p_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::i32p'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::i32z */
    tc_jsonser_fixture_i32z_o = cx_declare(tc_jsonser_fixture_o, "i32z", cx_type(cx_int32_o));
    if (!tc_jsonser_fixture_i32z_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::i32z'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::i32z */
    if (!cx_checkState(tc_jsonser_fixture_i32z_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_i32z_o) = 0;
        if (cx_define(tc_jsonser_fixture_i32z_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::i32z'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::i64n */
    tc_jsonser_fixture_i64n_o = cx_declare(tc_jsonser_fixture_o, "i64n", cx_type(cx_int64_o));
    if (!tc_jsonser_fixture_i64n_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::i64n'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::i64n */
    if (!cx_checkState(tc_jsonser_fixture_i64n_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_i64n_o) = -2;
        if (cx_define(tc_jsonser_fixture_i64n_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::i64n'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::i64p */
    tc_jsonser_fixture_i64p_o = cx_declare(tc_jsonser_fixture_o, "i64p", cx_type(cx_int64_o));
    if (!tc_jsonser_fixture_i64p_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::i64p'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::i64p */
    if (!cx_checkState(tc_jsonser_fixture_i64p_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_i64p_o) = 45;
        if (cx_define(tc_jsonser_fixture_i64p_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::i64p'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::i64z */
    tc_jsonser_fixture_i64z_o = cx_declare(tc_jsonser_fixture_o, "i64z", cx_type(cx_int64_o));
    if (!tc_jsonser_fixture_i64z_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::i64z'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::i64z */
    if (!cx_checkState(tc_jsonser_fixture_i64z_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_i64z_o) = 0;
        if (cx_define(tc_jsonser_fixture_i64z_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::i64z'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::i8n */
    tc_jsonser_fixture_i8n_o = cx_declare(tc_jsonser_fixture_o, "i8n", cx_type(cx_int8_o));
    if (!tc_jsonser_fixture_i8n_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::i8n'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::i8n */
    if (!cx_checkState(tc_jsonser_fixture_i8n_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_i8n_o) = -2;
        if (cx_define(tc_jsonser_fixture_i8n_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::i8n'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::i8p */
    tc_jsonser_fixture_i8p_o = cx_declare(tc_jsonser_fixture_o, "i8p", cx_type(cx_int8_o));
    if (!tc_jsonser_fixture_i8p_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::i8p'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::i8p */
    if (!cx_checkState(tc_jsonser_fixture_i8p_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_i8p_o) = 45;
        if (cx_define(tc_jsonser_fixture_i8p_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::i8p'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::i8z */
    tc_jsonser_fixture_i8z_o = cx_declare(tc_jsonser_fixture_o, "i8z", cx_type(cx_int8_o));
    if (!tc_jsonser_fixture_i8z_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::i8z'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::i8z */
    if (!cx_checkState(tc_jsonser_fixture_i8z_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_i8z_o) = 0;
        if (cx_define(tc_jsonser_fixture_i8z_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::i8z'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::intarray */
    tc_jsonser_fixture_intarray_o = cx_declare(tc_jsonser_fixture_o, "intarray", cx_type(cx_array_o));
    if (!tc_jsonser_fixture_intarray_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::intarray'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::intarray */
    if (!cx_checkState(tc_jsonser_fixture_intarray_o, CX_DEFINED)) {
        cx_collection(tc_jsonser_fixture_intarray_o)->elementType = cx_resolve_ext(tc_jsonser_fixture_intarray_o, NULL, "::cortex::lang::int32", FALSE, "element ::tc_jsonser_fixture::intarray.elementType");
        cx_collection(tc_jsonser_fixture_intarray_o)->max = 4;
        tc_jsonser_fixture_intarray_o->elementType = cx_resolve_ext(tc_jsonser_fixture_intarray_o, NULL, "::cortex::lang::int32", FALSE, "element ::tc_jsonser_fixture::intarray.elementType");
        if (cx_define(tc_jsonser_fixture_intarray_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::intarray'.");
            goto error;
        }
    }

    if (cx_type(tc_jsonser_fixture_intarray_o)->size != sizeof(tc_jsonser_fixture_intarray)) {
        cx_error("tc_jsonser_fixture_load: calculated size '%d' of type '::tc_jsonser_fixture::intarray' doesn't match C-type size '%d'", cx_type(tc_jsonser_fixture_intarray_o)->size, sizeof(tc_jsonser_fixture_intarray));
    }

    /* Declare ::tc_jsonser_fixture::intarray1 */
    tc_jsonser_fixture_intarray1_o = cx_declare(tc_jsonser_fixture_o, "intarray1", cx_type(tc_jsonser_fixture_intarray_o));
    if (!tc_jsonser_fixture_intarray1_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::intarray1'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::intarray1 */
    if (!cx_checkState(tc_jsonser_fixture_intarray1_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_intarray1_o)[0] = 26;
        (*tc_jsonser_fixture_intarray1_o)[1] = 47;
        (*tc_jsonser_fixture_intarray1_o)[2] = 6;
        (*tc_jsonser_fixture_intarray1_o)[3] = 39;
        if (cx_define(tc_jsonser_fixture_intarray1_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::intarray1'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::namesp */
    tc_jsonser_fixture_namesp_o = cx_declare(tc_jsonser_fixture_o, "namesp", cx_type(cx_void_o));
    if (!tc_jsonser_fixture_namesp_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::namesp'.");
        goto error;
    }

    /* Declare ::tc_jsonser_fixture::namesp::a */
    tc_jsonser_fixture_namesp_a_o = cx_declare(tc_jsonser_fixture_namesp_o, "a", cx_type(cx_int16_o));
    if (!tc_jsonser_fixture_namesp_a_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::namesp::a'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::namesp::a */
    if (!cx_checkState(tc_jsonser_fixture_namesp_a_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_namesp_a_o) = 9;
        if (cx_define(tc_jsonser_fixture_namesp_a_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::namesp::a'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::namesp::b */
    tc_jsonser_fixture_namesp_b_o = cx_declare(tc_jsonser_fixture_namesp_o, "b", cx_type(cx_string_o));
    if (!tc_jsonser_fixture_namesp_b_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::namesp::b'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::namesp::b */
    if (!cx_checkState(tc_jsonser_fixture_namesp_b_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_namesp_b_o) = cx_strdup("b");
        if (cx_define(tc_jsonser_fixture_namesp_b_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::namesp::b'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::point2D */
    tc_jsonser_fixture_point2D_o = cx_declare(tc_jsonser_fixture_o, "point2D", cx_type(cx_struct_o));
    if (!tc_jsonser_fixture_point2D_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::point2D'.");
        goto error;
    }

    /* Declare ::tc_jsonser_fixture::point2D::x */
    tc_jsonser_fixture_point2D_x_o = cx_declare(tc_jsonser_fixture_point2D_o, "x", cx_type(cx_member_o));
    if (!tc_jsonser_fixture_point2D_x_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::point2D::x'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::point2D::x */
    if (!cx_checkState(tc_jsonser_fixture_point2D_x_o, CX_DEFINED)) {
        tc_jsonser_fixture_point2D_x_o->type = cx_resolve_ext(tc_jsonser_fixture_point2D_x_o, NULL, "::cortex::lang::int32", FALSE, "element ::tc_jsonser_fixture::point2D::x.type");
        tc_jsonser_fixture_point2D_x_o->modifiers = 0x0;
        tc_jsonser_fixture_point2D_x_o->state = 0x6;
        tc_jsonser_fixture_point2D_x_o->weak = FALSE;
        tc_jsonser_fixture_point2D_x_o->id = 0;
        if (cx_define(tc_jsonser_fixture_point2D_x_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::point2D::x'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::point2D::y */
    tc_jsonser_fixture_point2D_y_o = cx_declare(tc_jsonser_fixture_point2D_o, "y", cx_type(cx_member_o));
    if (!tc_jsonser_fixture_point2D_y_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::point2D::y'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::point2D::y */
    if (!cx_checkState(tc_jsonser_fixture_point2D_y_o, CX_DEFINED)) {
        tc_jsonser_fixture_point2D_y_o->type = cx_resolve_ext(tc_jsonser_fixture_point2D_y_o, NULL, "::cortex::lang::int32", FALSE, "element ::tc_jsonser_fixture::point2D::y.type");
        tc_jsonser_fixture_point2D_y_o->modifiers = 0x0;
        tc_jsonser_fixture_point2D_y_o->state = 0x6;
        tc_jsonser_fixture_point2D_y_o->weak = FALSE;
        tc_jsonser_fixture_point2D_y_o->id = 1;
        if (cx_define(tc_jsonser_fixture_point2D_y_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::point2D::y'.");
            goto error;
        }
    }

    /* Define ::tc_jsonser_fixture::point2D */
    if (!cx_checkState(tc_jsonser_fixture_point2D_o, CX_DEFINED)) {
        cx_type(tc_jsonser_fixture_point2D_o)->defaultType = cx_resolve_ext(tc_jsonser_fixture_point2D_o, NULL, "::cortex::lang::member", FALSE, "element ::tc_jsonser_fixture::point2D.defaultType");
        cx_type(tc_jsonser_fixture_point2D_o)->parentType = NULL;
        cx_type(tc_jsonser_fixture_point2D_o)->parentState = 0x6;
        cx_interface(tc_jsonser_fixture_point2D_o)->base = NULL;
        tc_jsonser_fixture_point2D_o->baseAccess = 0x0;
        if (cx_define(tc_jsonser_fixture_point2D_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::point2D'.");
            goto error;
        }
    }

    if (cx_type(tc_jsonser_fixture_point2D_o)->size != sizeof(tc_jsonser_fixture_point2D)) {
        cx_error("tc_jsonser_fixture_load: calculated size '%d' of type '::tc_jsonser_fixture::point2D' doesn't match C-type size '%d'", cx_type(tc_jsonser_fixture_point2D_o)->size, sizeof(tc_jsonser_fixture_point2D));
    }

    /* Declare ::tc_jsonser_fixture::p */
    tc_jsonser_fixture_p_o = cx_declare(tc_jsonser_fixture_o, "p", cx_type(tc_jsonser_fixture_point2D_o));
    if (!tc_jsonser_fixture_p_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::p'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::p */
    if (!cx_checkState(tc_jsonser_fixture_p_o, CX_DEFINED)) {
        tc_jsonser_fixture_p_o->x = 3;
        tc_jsonser_fixture_p_o->y = 4;
        if (cx_define(tc_jsonser_fixture_p_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::p'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::s1 */
    tc_jsonser_fixture_s1_o = cx_declare(tc_jsonser_fixture_o, "s1", cx_type(cx_string_o));
    if (!tc_jsonser_fixture_s1_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::s1'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::s1 */
    if (!cx_checkState(tc_jsonser_fixture_s1_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_s1_o) = cx_strdup("hello world");
        if (cx_define(tc_jsonser_fixture_s1_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::s1'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::s10 */
    tc_jsonser_fixture_s10_o = cx_declare(tc_jsonser_fixture_o, "s10", cx_type(cx_string_o));
    if (!tc_jsonser_fixture_s10_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::s10'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::s10 */
    if (!cx_checkState(tc_jsonser_fixture_s10_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_s10_o) = cx_strdup("@@hey you");
        if (cx_define(tc_jsonser_fixture_s10_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::s10'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::s11 */
    tc_jsonser_fixture_s11_o = cx_declare(tc_jsonser_fixture_o, "s11", cx_type(cx_string_o));
    if (!tc_jsonser_fixture_s11_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::s11'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::s11 */
    if (!cx_checkState(tc_jsonser_fixture_s11_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_s11_o) = cx_strdup("@@@@@");
        if (cx_define(tc_jsonser_fixture_s11_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::s11'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::s12 */
    tc_jsonser_fixture_s12_o = cx_declare(tc_jsonser_fixture_o, "s12", cx_type(cx_string_o));
    if (!tc_jsonser_fixture_s12_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::s12'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::s12 */
    if (!cx_checkState(tc_jsonser_fixture_s12_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_s12_o) = cx_strdup("@@@@@ hey");
        if (cx_define(tc_jsonser_fixture_s12_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::s12'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::s13 */
    tc_jsonser_fixture_s13_o = cx_declare(tc_jsonser_fixture_o, "s13", cx_type(cx_string_o));
    if (!tc_jsonser_fixture_s13_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::s13'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::s13 */
    if (!cx_checkState(tc_jsonser_fixture_s13_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_s13_o) = cx_strdup("@@@@@hey");
        if (cx_define(tc_jsonser_fixture_s13_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::s13'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::s14 */
    tc_jsonser_fixture_s14_o = cx_declare(tc_jsonser_fixture_o, "s14", cx_type(cx_string_o));
    if (!tc_jsonser_fixture_s14_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::s14'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::s14 */
    if (!cx_checkState(tc_jsonser_fixture_s14_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_s14_o) = cx_strdup("@@@@@hey you");
        if (cx_define(tc_jsonser_fixture_s14_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::s14'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::s2 */
    tc_jsonser_fixture_s2_o = cx_declare(tc_jsonser_fixture_o, "s2", cx_type(cx_string_o));
    if (!tc_jsonser_fixture_s2_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::s2'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::s2 */
    if (!cx_checkState(tc_jsonser_fixture_s2_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_s2_o) = cx_strdup("hello, world!");
        if (cx_define(tc_jsonser_fixture_s2_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::s2'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::s3 */
    tc_jsonser_fixture_s3_o = cx_declare(tc_jsonser_fixture_o, "s3", cx_type(cx_string_o));
    if (!tc_jsonser_fixture_s3_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::s3'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::s3 */
    if (!cx_checkState(tc_jsonser_fixture_s3_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_s3_o) = cx_strdup("@");
        if (cx_define(tc_jsonser_fixture_s3_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::s3'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::s4 */
    tc_jsonser_fixture_s4_o = cx_declare(tc_jsonser_fixture_o, "s4", cx_type(cx_string_o));
    if (!tc_jsonser_fixture_s4_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::s4'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::s4 */
    if (!cx_checkState(tc_jsonser_fixture_s4_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_s4_o) = cx_strdup("@ hey");
        if (cx_define(tc_jsonser_fixture_s4_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::s4'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::s5 */
    tc_jsonser_fixture_s5_o = cx_declare(tc_jsonser_fixture_o, "s5", cx_type(cx_string_o));
    if (!tc_jsonser_fixture_s5_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::s5'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::s5 */
    if (!cx_checkState(tc_jsonser_fixture_s5_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_s5_o) = cx_strdup("@hey");
        if (cx_define(tc_jsonser_fixture_s5_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::s5'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::s6 */
    tc_jsonser_fixture_s6_o = cx_declare(tc_jsonser_fixture_o, "s6", cx_type(cx_string_o));
    if (!tc_jsonser_fixture_s6_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::s6'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::s6 */
    if (!cx_checkState(tc_jsonser_fixture_s6_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_s6_o) = cx_strdup("@hey you");
        if (cx_define(tc_jsonser_fixture_s6_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::s6'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::s7 */
    tc_jsonser_fixture_s7_o = cx_declare(tc_jsonser_fixture_o, "s7", cx_type(cx_string_o));
    if (!tc_jsonser_fixture_s7_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::s7'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::s7 */
    if (!cx_checkState(tc_jsonser_fixture_s7_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_s7_o) = cx_strdup("@@");
        if (cx_define(tc_jsonser_fixture_s7_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::s7'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::s8 */
    tc_jsonser_fixture_s8_o = cx_declare(tc_jsonser_fixture_o, "s8", cx_type(cx_string_o));
    if (!tc_jsonser_fixture_s8_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::s8'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::s8 */
    if (!cx_checkState(tc_jsonser_fixture_s8_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_s8_o) = cx_strdup("@@ hey");
        if (cx_define(tc_jsonser_fixture_s8_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::s8'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::s9 */
    tc_jsonser_fixture_s9_o = cx_declare(tc_jsonser_fixture_o, "s9", cx_type(cx_string_o));
    if (!tc_jsonser_fixture_s9_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::s9'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::s9 */
    if (!cx_checkState(tc_jsonser_fixture_s9_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_s9_o) = cx_strdup("@@hey");
        if (cx_define(tc_jsonser_fixture_s9_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::s9'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::sn */
    tc_jsonser_fixture_sn_o = cx_declare(tc_jsonser_fixture_o, "sn", cx_type(cx_string_o));
    if (!tc_jsonser_fixture_sn_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::sn'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::sn */
    if (!cx_checkState(tc_jsonser_fixture_sn_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_sn_o) = NULL;
        if (cx_define(tc_jsonser_fixture_sn_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::sn'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::stringlist */
    tc_jsonser_fixture_stringlist_o = cx_declare(tc_jsonser_fixture_o, "stringlist", cx_type(cx_list_o));
    if (!tc_jsonser_fixture_stringlist_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::stringlist'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::stringlist */
    if (!cx_checkState(tc_jsonser_fixture_stringlist_o, CX_DEFINED)) {
        cx_collection(tc_jsonser_fixture_stringlist_o)->elementType = cx_resolve_ext(tc_jsonser_fixture_stringlist_o, NULL, "::cortex::lang::string", FALSE, "element ::tc_jsonser_fixture::stringlist.elementType");
        cx_collection(tc_jsonser_fixture_stringlist_o)->max = 0;
        if (cx_define(tc_jsonser_fixture_stringlist_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::stringlist'.");
            goto error;
        }
    }

    if (cx_type(tc_jsonser_fixture_stringlist_o)->size != sizeof(tc_jsonser_fixture_stringlist)) {
        cx_error("tc_jsonser_fixture_load: calculated size '%d' of type '::tc_jsonser_fixture::stringlist' doesn't match C-type size '%d'", cx_type(tc_jsonser_fixture_stringlist_o)->size, sizeof(tc_jsonser_fixture_stringlist));
    }

    /* Declare ::tc_jsonser_fixture::stringlist1 */
    tc_jsonser_fixture_stringlist1_o = cx_declare(tc_jsonser_fixture_o, "stringlist1", cx_type(tc_jsonser_fixture_stringlist_o));
    if (!tc_jsonser_fixture_stringlist1_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::stringlist1'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::stringlist1 */
    if (!cx_checkState(tc_jsonser_fixture_stringlist1_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_stringlist1_o) = cx_llNew();
        {
            cx_string _e1_;
            
            _e1_ = cx_strdup("Alpha");
            cx_llAppend((*tc_jsonser_fixture_stringlist1_o), (void*)_e1_);
            
            _e1_ = cx_strdup("Beta");
            cx_llAppend((*tc_jsonser_fixture_stringlist1_o), (void*)_e1_);
            
            _e1_ = cx_strdup("Gamma");
            cx_llAppend((*tc_jsonser_fixture_stringlist1_o), (void*)_e1_);
        }
        if (cx_define(tc_jsonser_fixture_stringlist1_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::stringlist1'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::u16p */
    tc_jsonser_fixture_u16p_o = cx_declare(tc_jsonser_fixture_o, "u16p", cx_type(cx_uint16_o));
    if (!tc_jsonser_fixture_u16p_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::u16p'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::u16p */
    if (!cx_checkState(tc_jsonser_fixture_u16p_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_u16p_o) = 45;
        if (cx_define(tc_jsonser_fixture_u16p_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::u16p'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::u16z */
    tc_jsonser_fixture_u16z_o = cx_declare(tc_jsonser_fixture_o, "u16z", cx_type(cx_uint16_o));
    if (!tc_jsonser_fixture_u16z_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::u16z'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::u16z */
    if (!cx_checkState(tc_jsonser_fixture_u16z_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_u16z_o) = 0;
        if (cx_define(tc_jsonser_fixture_u16z_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::u16z'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::u32p */
    tc_jsonser_fixture_u32p_o = cx_declare(tc_jsonser_fixture_o, "u32p", cx_type(cx_uint32_o));
    if (!tc_jsonser_fixture_u32p_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::u32p'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::u32p */
    if (!cx_checkState(tc_jsonser_fixture_u32p_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_u32p_o) = 45;
        if (cx_define(tc_jsonser_fixture_u32p_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::u32p'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::u32z */
    tc_jsonser_fixture_u32z_o = cx_declare(tc_jsonser_fixture_o, "u32z", cx_type(cx_uint32_o));
    if (!tc_jsonser_fixture_u32z_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::u32z'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::u32z */
    if (!cx_checkState(tc_jsonser_fixture_u32z_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_u32z_o) = 0;
        if (cx_define(tc_jsonser_fixture_u32z_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::u32z'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::u64p */
    tc_jsonser_fixture_u64p_o = cx_declare(tc_jsonser_fixture_o, "u64p", cx_type(cx_uint64_o));
    if (!tc_jsonser_fixture_u64p_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::u64p'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::u64p */
    if (!cx_checkState(tc_jsonser_fixture_u64p_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_u64p_o) = 45;
        if (cx_define(tc_jsonser_fixture_u64p_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::u64p'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::u64z */
    tc_jsonser_fixture_u64z_o = cx_declare(tc_jsonser_fixture_o, "u64z", cx_type(cx_uint64_o));
    if (!tc_jsonser_fixture_u64z_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::u64z'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::u64z */
    if (!cx_checkState(tc_jsonser_fixture_u64z_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_u64z_o) = 0;
        if (cx_define(tc_jsonser_fixture_u64z_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::u64z'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::u8p */
    tc_jsonser_fixture_u8p_o = cx_declare(tc_jsonser_fixture_o, "u8p", cx_type(cx_uint8_o));
    if (!tc_jsonser_fixture_u8p_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::u8p'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::u8p */
    if (!cx_checkState(tc_jsonser_fixture_u8p_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_u8p_o) = 45;
        if (cx_define(tc_jsonser_fixture_u8p_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::u8p'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::u8z */
    tc_jsonser_fixture_u8z_o = cx_declare(tc_jsonser_fixture_o, "u8z", cx_type(cx_uint8_o));
    if (!tc_jsonser_fixture_u8z_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::u8z'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::u8z */
    if (!cx_checkState(tc_jsonser_fixture_u8z_o, CX_DEFINED)) {
        (*tc_jsonser_fixture_u8z_o) = 0;
        if (cx_define(tc_jsonser_fixture_u8z_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::u8z'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::v0 */
    tc_jsonser_fixture_v0_o = cx_declare(tc_jsonser_fixture_o, "v0", cx_type(cx_void_o));
    if (!tc_jsonser_fixture_v0_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::v0'.");
        goto error;
    }

    /* Declare ::tc_jsonser_fixture::v1 */
    tc_jsonser_fixture_v1_o = cx_declare(tc_jsonser_fixture_o, "v1", cx_type(cx_void_o));
    if (!tc_jsonser_fixture_v1_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::v1'.");
        goto error;
    }

    /* Declare ::tc_jsonser_fixture::v1::v1 */
    tc_jsonser_fixture_v1_v1_o = cx_declare(tc_jsonser_fixture_v1_o, "v1", cx_type(cx_void_o));
    if (!tc_jsonser_fixture_v1_v1_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::v1::v1'.");
        goto error;
    }

    /* Declare ::tc_jsonser_fixture::v1::v1::v1 */
    tc_jsonser_fixture_v1_v1_v1_o = cx_declare(tc_jsonser_fixture_v1_v1_o, "v1", cx_type(cx_void_o));
    if (!tc_jsonser_fixture_v1_v1_v1_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::v1::v1::v1'.");
        goto error;
    }

    /* Declare ::tc_jsonser_fixture::v1::v1::v2 */
    tc_jsonser_fixture_v1_v1_v2_o = cx_declare(tc_jsonser_fixture_v1_v1_o, "v2", cx_type(cx_void_o));
    if (!tc_jsonser_fixture_v1_v1_v2_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::v1::v1::v2'.");
        goto error;
    }

    /* Declare ::tc_jsonser_fixture::v1::v1::v3 */
    tc_jsonser_fixture_v1_v1_v3_o = cx_declare(tc_jsonser_fixture_v1_v1_o, "v3", cx_type(cx_void_o));
    if (!tc_jsonser_fixture_v1_v1_v3_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::v1::v1::v3'.");
        goto error;
    }

    /* Declare ::tc_jsonser_fixture::v1::v1::v4 */
    tc_jsonser_fixture_v1_v1_v4_o = cx_declare(tc_jsonser_fixture_v1_v1_o, "v4", cx_type(cx_void_o));
    if (!tc_jsonser_fixture_v1_v1_v4_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::v1::v1::v4'.");
        goto error;
    }

    /* Declare ::tc_jsonser_fixture::v1::v2 */
    tc_jsonser_fixture_v1_v2_o = cx_declare(tc_jsonser_fixture_v1_o, "v2", cx_type(cx_void_o));
    if (!tc_jsonser_fixture_v1_v2_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::v1::v2'.");
        goto error;
    }

    /* Declare ::tc_jsonser_fixture::v1::v2::v1 */
    tc_jsonser_fixture_v1_v2_v1_o = cx_declare(tc_jsonser_fixture_v1_v2_o, "v1", cx_type(cx_void_o));
    if (!tc_jsonser_fixture_v1_v2_v1_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::v1::v2::v1'.");
        goto error;
    }

    /* Declare ::tc_jsonser_fixture::v1::v2::v2 */
    tc_jsonser_fixture_v1_v2_v2_o = cx_declare(tc_jsonser_fixture_v1_v2_o, "v2", cx_type(cx_void_o));
    if (!tc_jsonser_fixture_v1_v2_v2_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::v1::v2::v2'.");
        goto error;
    }

    /* Declare ::tc_jsonser_fixture::v1::v2::v3 */
    tc_jsonser_fixture_v1_v2_v3_o = cx_declare(tc_jsonser_fixture_v1_v2_o, "v3", cx_type(cx_void_o));
    if (!tc_jsonser_fixture_v1_v2_v3_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::v1::v2::v3'.");
        goto error;
    }

    /* Declare ::tc_jsonser_fixture::v1::v2::v4 */
    tc_jsonser_fixture_v1_v2_v4_o = cx_declare(tc_jsonser_fixture_v1_v2_o, "v4", cx_type(cx_void_o));
    if (!tc_jsonser_fixture_v1_v2_v4_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::v1::v2::v4'.");
        goto error;
    }

    /* Declare ::tc_jsonser_fixture::v1::v2::v5 */
    tc_jsonser_fixture_v1_v2_v5_o = cx_declare(tc_jsonser_fixture_v1_v2_o, "v5", cx_type(cx_void_o));
    if (!tc_jsonser_fixture_v1_v2_v5_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::v1::v2::v5'.");
        goto error;
    }

    /* Declare ::tc_jsonser_fixture::v1::v3 */
    tc_jsonser_fixture_v1_v3_o = cx_declare(tc_jsonser_fixture_v1_o, "v3", cx_type(cx_void_o));
    if (!tc_jsonser_fixture_v1_v3_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::v1::v3'.");
        goto error;
    }

    /* Declare ::tc_jsonser_fixture::v1::v3::v1 */
    tc_jsonser_fixture_v1_v3_v1_o = cx_declare(tc_jsonser_fixture_v1_v3_o, "v1", cx_type(cx_void_o));
    if (!tc_jsonser_fixture_v1_v3_v1_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::v1::v3::v1'.");
        goto error;
    }

    /* Declare ::tc_jsonser_fixture::v1::v3::v2 */
    tc_jsonser_fixture_v1_v3_v2_o = cx_declare(tc_jsonser_fixture_v1_v3_o, "v2", cx_type(cx_void_o));
    if (!tc_jsonser_fixture_v1_v3_v2_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::v1::v3::v2'.");
        goto error;
    }

    /* Declare ::tc_jsonser_fixture::v1::v3::v3 */
    tc_jsonser_fixture_v1_v3_v3_o = cx_declare(tc_jsonser_fixture_v1_v3_o, "v3", cx_type(cx_void_o));
    if (!tc_jsonser_fixture_v1_v3_v3_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::v1::v3::v3'.");
        goto error;
    }

    /* Declare ::tc_jsonser_fixture::v1::v3::v4 */
    tc_jsonser_fixture_v1_v3_v4_o = cx_declare(tc_jsonser_fixture_v1_v3_o, "v4", cx_type(cx_void_o));
    if (!tc_jsonser_fixture_v1_v3_v4_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::v1::v3::v4'.");
        goto error;
    }

    /* Declare ::tc_jsonser_fixture::v1::v3::v5 */
    tc_jsonser_fixture_v1_v3_v5_o = cx_declare(tc_jsonser_fixture_v1_v3_o, "v5", cx_type(cx_void_o));
    if (!tc_jsonser_fixture_v1_v3_v5_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::v1::v3::v5'.");
        goto error;
    }

    /* Declare ::tc_jsonser_fixture::v1::v3::v6 */
    tc_jsonser_fixture_v1_v3_v6_o = cx_declare(tc_jsonser_fixture_v1_v3_o, "v6", cx_type(cx_void_o));
    if (!tc_jsonser_fixture_v1_v3_v6_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::v1::v3::v6'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::Dog::lover */
    if (!cx_checkState(tc_jsonser_fixture_Dog_lover_o, CX_DEFINED)) {
        tc_jsonser_fixture_Dog_lover_o->type = cx_resolve_ext(tc_jsonser_fixture_Dog_lover_o, NULL, "::tc_jsonser_fixture::Dog", FALSE, "element ::tc_jsonser_fixture::Dog::lover.type");
        tc_jsonser_fixture_Dog_lover_o->modifiers = 0x0;
        tc_jsonser_fixture_Dog_lover_o->state = 0x6;
        tc_jsonser_fixture_Dog_lover_o->weak = FALSE;
        tc_jsonser_fixture_Dog_lover_o->id = 3;
        if (cx_define(tc_jsonser_fixture_Dog_lover_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::Dog::lover'.");
            goto error;
        }
    }

    /* Define ::tc_jsonser_fixture::Dog */
    if (!cx_checkState(tc_jsonser_fixture_Dog_o, CX_DEFINED)) {
        cx_type(tc_jsonser_fixture_Dog_o)->defaultType = cx_resolve_ext(tc_jsonser_fixture_Dog_o, NULL, "::cortex::lang::member", FALSE, "element ::tc_jsonser_fixture::Dog.defaultType");
        cx_type(tc_jsonser_fixture_Dog_o)->parentType = NULL;
        cx_type(tc_jsonser_fixture_Dog_o)->parentState = 0x6;
        cx_interface(tc_jsonser_fixture_Dog_o)->base = NULL;
        cx_struct(tc_jsonser_fixture_Dog_o)->baseAccess = 0x0;
        tc_jsonser_fixture_Dog_o->implements.length = 0;
        tc_jsonser_fixture_Dog_o->implements.buffer = NULL;
        if (cx_define(tc_jsonser_fixture_Dog_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::Dog'.");
            goto error;
        }
    }

    if (cx_type(tc_jsonser_fixture_Dog_o)->size != sizeof(struct tc_jsonser_fixture_Dog_s)) {
        cx_error("tc_jsonser_fixture_load: calculated size '%d' of type '::tc_jsonser_fixture::Dog' doesn't match C-type size '%d'", cx_type(tc_jsonser_fixture_Dog_o)->size, sizeof(struct tc_jsonser_fixture_Dog_s));
    }

    /* Declare ::tc_jsonser_fixture::dog1 */
    tc_jsonser_fixture_dog1_o = cx_declare(tc_jsonser_fixture_o, "dog1", cx_type(tc_jsonser_fixture_Dog_o));
    if (!tc_jsonser_fixture_dog1_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::dog1'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::dog1 */
    if (!cx_checkState(tc_jsonser_fixture_dog1_o, CX_DEFINED)) {
        tc_jsonser_fixture_dog1_o->breed = Tc_jsonser_fixture_GoldenRetriever;
        tc_jsonser_fixture_dog1_o->name = cx_strdup("Gijs");
        tc_jsonser_fixture_dog1_o->age = 10;
        tc_jsonser_fixture_dog1_o->lover = NULL;
        if (cx_define(tc_jsonser_fixture_dog1_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::dog1'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::dog2 */
    tc_jsonser_fixture_dog2_o = cx_declare(tc_jsonser_fixture_o, "dog2", cx_type(tc_jsonser_fixture_Dog_o));
    if (!tc_jsonser_fixture_dog2_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::dog2'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::dog2 */
    if (!cx_checkState(tc_jsonser_fixture_dog2_o, CX_DEFINED)) {
        tc_jsonser_fixture_dog2_o->breed = Tc_jsonser_fixture_Pug;
        tc_jsonser_fixture_dog2_o->name = cx_strdup("Lolly");
        tc_jsonser_fixture_dog2_o->age = 4;
        tc_jsonser_fixture_dog2_o->lover = NULL;
        if (cx_define(tc_jsonser_fixture_dog2_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::dog2'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::dog3 */
    tc_jsonser_fixture_dog3_o = cx_declare(tc_jsonser_fixture_o, "dog3", cx_type(tc_jsonser_fixture_Dog_o));
    if (!tc_jsonser_fixture_dog3_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::dog3'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::dog3 */
    if (!cx_checkState(tc_jsonser_fixture_dog3_o, CX_DEFINED)) {
        tc_jsonser_fixture_dog3_o->breed = Tc_jsonser_fixture_Chihuahua;
        tc_jsonser_fixture_dog3_o->name = cx_strdup("I'm annoying");
        tc_jsonser_fixture_dog3_o->age = 3;
        tc_jsonser_fixture_dog3_o->lover = cx_resolve_ext(tc_jsonser_fixture_dog3_o, NULL, "::tc_jsonser_fixture::dog2", FALSE, "element ::tc_jsonser_fixture::dog3.lover");
        if (cx_define(tc_jsonser_fixture_dog3_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::dog3'.");
            goto error;
        }
    }

    /* Declare ::tc_jsonser_fixture::v0::dog1 */
    tc_jsonser_fixture_v0_dog1_o = cx_declare(tc_jsonser_fixture_v0_o, "dog1", cx_type(tc_jsonser_fixture_Dog_o));
    if (!tc_jsonser_fixture_v0_dog1_o) {
        cx_error("tc_jsonser_fixture_load: failed to declare object '::tc_jsonser_fixture::v0::dog1'.");
        goto error;
    }

    /* Define ::tc_jsonser_fixture::v0::dog1 */
    if (!cx_checkState(tc_jsonser_fixture_v0_dog1_o, CX_DEFINED)) {
        tc_jsonser_fixture_v0_dog1_o->breed = Tc_jsonser_fixture_Pug;
        tc_jsonser_fixture_v0_dog1_o->name = cx_strdup("MyPug");
        tc_jsonser_fixture_v0_dog1_o->age = 55;
        tc_jsonser_fixture_v0_dog1_o->lover = NULL;
        if (cx_define(tc_jsonser_fixture_v0_dog1_o)) {
            cx_error("tc_jsonser_fixture_load: failed to define object '::tc_jsonser_fixture::v0::dog1'.");
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
