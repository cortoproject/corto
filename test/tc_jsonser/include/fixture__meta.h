/* fixture__meta.h
 *
 * Loads objects in database.
 * This file contains generated code. Do not modify!
 */

#ifndef fixture_META_H
#define fixture_META_H

#include "cortex.h"

#include "fixture__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::fixture */
extern cx_object fixture_o;

/* ::fixture::bf */
extern cx_bool (*fixture_bf_o);

/* ::fixture::black */
extern fixture_color (*fixture_black_o);

/* ::fixture::bt */
extern cx_bool (*fixture_bt_o);

/* ::fixture::c1 */
extern cx_char (*fixture_c1_o);

/* ::fixture::c2 */
extern cx_char (*fixture_c2_o);

/* ::fixture::c3 */
extern cx_char (*fixture_c3_o);

/* ::fixture::c4 */
extern cx_char (*fixture_c4_o);

/* ::fixture::c5 */
extern cx_char (*fixture_c5_o);

/* ::fixture::color */
extern cx_bitmask fixture_color_o;

/* ::fixture::color::blue */
extern cx_constant (*fixture_color_blue_o);

/* ::fixture::color::green */
extern cx_constant (*fixture_color_green_o);

/* ::fixture::color::red */
extern cx_constant (*fixture_color_red_o);

/* ::fixture::Djinn */
extern cx_enum fixture_Djinn_o;

/* ::fixture::Djinn::Jupiter */
extern cx_constant (*fixture_Djinn_Jupiter_o);

/* ::fixture::Djinn::Mars */
extern cx_constant (*fixture_Djinn_Mars_o);

/* ::fixture::Djinn::Mercury */
extern cx_constant (*fixture_Djinn_Mercury_o);

/* ::fixture::Djinn::Venus */
extern cx_constant (*fixture_Djinn_Venus_o);

/* ::fixture::Dog */
extern cx_class fixture_Dog_o;

/* ::fixture::Dog::age */
extern cx_member fixture_Dog_age_o;

/* ::fixture::Dog::breed */
extern cx_member fixture_Dog_breed_o;

/* ::fixture::Dog::lover */
extern cx_member fixture_Dog_lover_o;

/* ::fixture::Dog::name */
extern cx_member fixture_Dog_name_o;

/* ::fixture::dog1 */
extern fixture_Dog fixture_dog1_o;

/* ::fixture::dog2 */
extern fixture_Dog fixture_dog2_o;

/* ::fixture::dog3 */
extern fixture_Dog fixture_dog3_o;

/* ::fixture::DogBreed */
extern cx_enum fixture_DogBreed_o;

/* ::fixture::DogBreed::Chihuahua */
extern cx_constant (*fixture_DogBreed_Chihuahua_o);

/* ::fixture::DogBreed::GoldenRetriever */
extern cx_constant (*fixture_DogBreed_GoldenRetriever_o);

/* ::fixture::DogBreed::Pug */
extern cx_constant (*fixture_DogBreed_Pug_o);

/* ::fixture::f32n */
extern cx_float32 (*fixture_f32n_o);

/* ::fixture::f32p */
extern cx_float32 (*fixture_f32p_o);

/* ::fixture::f32z */
extern cx_float32 (*fixture_f32z_o);

/* ::fixture::f64n */
extern cx_float64 (*fixture_f64n_o);

/* ::fixture::f64p */
extern cx_float64 (*fixture_f64p_o);

/* ::fixture::f64z */
extern cx_float64 (*fixture_f64z_o);

/* ::fixture::Flint */
extern fixture_Djinn (*fixture_Flint_o);

/* ::fixture::Forge */
extern fixture_Djinn (*fixture_Forge_o);

/* ::fixture::Gust */
extern fixture_Djinn (*fixture_Gust_o);

/* ::fixture::i16n */
extern cx_int16 (*fixture_i16n_o);

/* ::fixture::i16p */
extern cx_int16 (*fixture_i16p_o);

/* ::fixture::i16z */
extern cx_int16 (*fixture_i16z_o);

/* ::fixture::i32n */
extern cx_int32 (*fixture_i32n_o);

/* ::fixture::i32p */
extern cx_int32 (*fixture_i32p_o);

/* ::fixture::i32z */
extern cx_int32 (*fixture_i32z_o);

/* ::fixture::i64n */
extern cx_int64 (*fixture_i64n_o);

/* ::fixture::i64p */
extern cx_int64 (*fixture_i64p_o);

/* ::fixture::i64z */
extern cx_int64 (*fixture_i64z_o);

/* ::fixture::i8n */
extern cx_int8 (*fixture_i8n_o);

/* ::fixture::i8p */
extern cx_int8 (*fixture_i8p_o);

/* ::fixture::i8z */
extern cx_int8 (*fixture_i8z_o);

/* ::fixture::ints */
extern cx_array fixture_ints_o;

/* ::fixture::myarray */
extern fixture_ints (*fixture_myarray_o);

/* ::fixture::namesp */
extern cx_void (*fixture_namesp_o);

/* ::fixture::namesp::a */
extern cx_int16 (*fixture_namesp_a_o);

/* ::fixture::namesp::b */
extern cx_string (*fixture_namesp_b_o);

/* ::fixture::p */
extern fixture_point2D (*fixture_p_o);

/* ::fixture::point2D */
extern cx_struct fixture_point2D_o;

/* ::fixture::point2D::x */
extern cx_member fixture_point2D_x_o;

/* ::fixture::point2D::y */
extern cx_member fixture_point2D_y_o;

/* ::fixture::s1 */
extern cx_string (*fixture_s1_o);

/* ::fixture::s10 */
extern cx_string (*fixture_s10_o);

/* ::fixture::s11 */
extern cx_string (*fixture_s11_o);

/* ::fixture::s12 */
extern cx_string (*fixture_s12_o);

/* ::fixture::s13 */
extern cx_string (*fixture_s13_o);

/* ::fixture::s14 */
extern cx_string (*fixture_s14_o);

/* ::fixture::s2 */
extern cx_string (*fixture_s2_o);

/* ::fixture::s3 */
extern cx_string (*fixture_s3_o);

/* ::fixture::s4 */
extern cx_string (*fixture_s4_o);

/* ::fixture::s5 */
extern cx_string (*fixture_s5_o);

/* ::fixture::s6 */
extern cx_string (*fixture_s6_o);

/* ::fixture::s7 */
extern cx_string (*fixture_s7_o);

/* ::fixture::s8 */
extern cx_string (*fixture_s8_o);

/* ::fixture::s9 */
extern cx_string (*fixture_s9_o);

/* ::fixture::Sleet */
extern fixture_Djinn (*fixture_Sleet_o);

/* ::fixture::sn */
extern cx_string (*fixture_sn_o);

/* ::fixture::u16p */
extern cx_uint16 (*fixture_u16p_o);

/* ::fixture::u16z */
extern cx_uint16 (*fixture_u16z_o);

/* ::fixture::u32p */
extern cx_uint32 (*fixture_u32p_o);

/* ::fixture::u32z */
extern cx_uint32 (*fixture_u32z_o);

/* ::fixture::u64p */
extern cx_uint64 (*fixture_u64p_o);

/* ::fixture::u64z */
extern cx_uint64 (*fixture_u64z_o);

/* ::fixture::u8p */
extern cx_uint8 (*fixture_u8p_o);

/* ::fixture::u8z */
extern cx_uint8 (*fixture_u8z_o);

/* ::fixture::v0 */
extern cx_void (*fixture_v0_o);

/* ::fixture::v0::dog1 */
extern fixture_Dog fixture_v0_dog1_o;

/* ::fixture::v1 */
extern cx_void (*fixture_v1_o);

/* ::fixture::v1::v1 */
extern cx_void (*fixture_v1_v1_o);

/* ::fixture::v1::v1::v1 */
extern cx_void (*fixture_v1_v1_v1_o);

/* ::fixture::v1::v1::v2 */
extern cx_void (*fixture_v1_v1_v2_o);

/* ::fixture::v1::v1::v3 */
extern cx_void (*fixture_v1_v1_v3_o);

/* ::fixture::v1::v1::v4 */
extern cx_void (*fixture_v1_v1_v4_o);

/* ::fixture::v1::v2 */
extern cx_void (*fixture_v1_v2_o);

/* ::fixture::v1::v2::v1 */
extern cx_void (*fixture_v1_v2_v1_o);

/* ::fixture::v1::v2::v2 */
extern cx_void (*fixture_v1_v2_v2_o);

/* ::fixture::v1::v2::v3 */
extern cx_void (*fixture_v1_v2_v3_o);

/* ::fixture::v1::v2::v4 */
extern cx_void (*fixture_v1_v2_v4_o);

/* ::fixture::v1::v2::v5 */
extern cx_void (*fixture_v1_v2_v5_o);

/* ::fixture::v1::v3 */
extern cx_void (*fixture_v1_v3_o);

/* ::fixture::v1::v3::v1 */
extern cx_void (*fixture_v1_v3_v1_o);

/* ::fixture::v1::v3::v2 */
extern cx_void (*fixture_v1_v3_v2_o);

/* ::fixture::v1::v3::v3 */
extern cx_void (*fixture_v1_v3_v3_o);

/* ::fixture::v1::v3::v4 */
extern cx_void (*fixture_v1_v3_v4_o);

/* ::fixture::v1::v3::v5 */
extern cx_void (*fixture_v1_v3_v5_o);

/* ::fixture::v1::v3::v6 */
extern cx_void (*fixture_v1_v3_v6_o);

/* ::fixture::white */
extern fixture_color (*fixture_white_o);

/* ::fixture::yellow */
extern fixture_color (*fixture_yellow_o);

int fixture_load(void);
#ifdef __cplusplus
}
#endif
#endif

