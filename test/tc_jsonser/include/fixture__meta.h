/* fixture__meta.h
 *
 * Loads objects in database.
 * This file contains generated code. Do not modify!
 */

#ifndef fixture_META_H
#define fixture_META_H

#include "hyve.h"

#include "fixture__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::fixture */
extern db_object fixture_o;

/* ::fixture::bf */
extern db_bool (*fixture_bf_o);

/* ::fixture::bt */
extern db_bool (*fixture_bt_o);

/* ::fixture::Djinn */
extern db_enum fixture_Djinn_o;

/* ::fixture::Djinn::Jupiter */
extern db_constant (*fixture_Djinn_Jupiter_o);

/* ::fixture::Djinn::Mars */
extern db_constant (*fixture_Djinn_Mars_o);

/* ::fixture::Djinn::Mercury */
extern db_constant (*fixture_Djinn_Mercury_o);

/* ::fixture::Djinn::Venus */
extern db_constant (*fixture_Djinn_Venus_o);

/* ::fixture::Dog */
extern db_class fixture_Dog_o;

/* ::fixture::Dog::age */
extern db_member fixture_Dog_age_o;

/* ::fixture::Dog::breed */
extern db_member fixture_Dog_breed_o;

/* ::fixture::Dog::lover */
extern db_member fixture_Dog_lover_o;

/* ::fixture::Dog::name */
extern db_member fixture_Dog_name_o;

/* ::fixture::dog1 */
extern fixture_Dog fixture_dog1_o;

/* ::fixture::dog2 */
extern fixture_Dog fixture_dog2_o;

/* ::fixture::dog3 */
extern fixture_Dog fixture_dog3_o;

/* ::fixture::DogBreed */
extern db_enum fixture_DogBreed_o;

/* ::fixture::DogBreed::Chihuahua */
extern db_constant (*fixture_DogBreed_Chihuahua_o);

/* ::fixture::DogBreed::GoldenRetriever */
extern db_constant (*fixture_DogBreed_GoldenRetriever_o);

/* ::fixture::DogBreed::Pug */
extern db_constant (*fixture_DogBreed_Pug_o);

/* ::fixture::f32n */
extern db_float32 (*fixture_f32n_o);

/* ::fixture::f32p */
extern db_float32 (*fixture_f32p_o);

/* ::fixture::f32z */
extern db_float32 (*fixture_f32z_o);

/* ::fixture::f64n */
extern db_float32 (*fixture_f64n_o);

/* ::fixture::f64p */
extern db_float32 (*fixture_f64p_o);

/* ::fixture::f64z */
extern db_float32 (*fixture_f64z_o);

/* ::fixture::Flint */
extern fixture_Djinn (*fixture_Flint_o);

/* ::fixture::Forge */
extern fixture_Djinn (*fixture_Forge_o);

/* ::fixture::Gust */
extern fixture_Djinn (*fixture_Gust_o);

/* ::fixture::i16n */
extern db_int16 (*fixture_i16n_o);

/* ::fixture::i16p */
extern db_int16 (*fixture_i16p_o);

/* ::fixture::i16z */
extern db_int16 (*fixture_i16z_o);

/* ::fixture::i32n */
extern db_int32 (*fixture_i32n_o);

/* ::fixture::i32p */
extern db_int32 (*fixture_i32p_o);

/* ::fixture::i32z */
extern db_int32 (*fixture_i32z_o);

/* ::fixture::i64n */
extern db_int64 (*fixture_i64n_o);

/* ::fixture::i64p */
extern db_int64 (*fixture_i64p_o);

/* ::fixture::i64z */
extern db_int64 (*fixture_i64z_o);

/* ::fixture::i8n */
extern db_int8 (*fixture_i8n_o);

/* ::fixture::i8p */
extern db_int8 (*fixture_i8p_o);

/* ::fixture::i8z */
extern db_int8 (*fixture_i8z_o);

/* ::fixture::ints */
extern db_array fixture_ints_o;

/* ::fixture::myarray */
extern fixture_ints (*fixture_myarray_o);

/* ::fixture::namesp */
extern db_void (*fixture_namesp_o);

/* ::fixture::namesp::a */
extern db_int16 (*fixture_namesp_a_o);

/* ::fixture::namesp::b */
extern db_string (*fixture_namesp_b_o);

/* ::fixture::p */
extern fixture_point2D (*fixture_p_o);

/* ::fixture::point2D */
extern db_struct fixture_point2D_o;

/* ::fixture::point2D::x */
extern db_member fixture_point2D_x_o;

/* ::fixture::point2D::y */
extern db_member fixture_point2D_y_o;

/* ::fixture::s1 */
extern db_string (*fixture_s1_o);

/* ::fixture::s10 */
extern db_string (*fixture_s10_o);

/* ::fixture::s11 */
extern db_string (*fixture_s11_o);

/* ::fixture::s12 */
extern db_string (*fixture_s12_o);

/* ::fixture::s13 */
extern db_string (*fixture_s13_o);

/* ::fixture::s14 */
extern db_string (*fixture_s14_o);

/* ::fixture::s2 */
extern db_string (*fixture_s2_o);

/* ::fixture::s3 */
extern db_string (*fixture_s3_o);

/* ::fixture::s4 */
extern db_string (*fixture_s4_o);

/* ::fixture::s5 */
extern db_string (*fixture_s5_o);

/* ::fixture::s6 */
extern db_string (*fixture_s6_o);

/* ::fixture::s7 */
extern db_string (*fixture_s7_o);

/* ::fixture::s8 */
extern db_string (*fixture_s8_o);

/* ::fixture::s9 */
extern db_string (*fixture_s9_o);

/* ::fixture::Sleet */
extern fixture_Djinn (*fixture_Sleet_o);

/* ::fixture::sn */
extern db_string (*fixture_sn_o);

/* ::fixture::u16p */
extern db_uint16 (*fixture_u16p_o);

/* ::fixture::u16z */
extern db_uint16 (*fixture_u16z_o);

/* ::fixture::u32p */
extern db_uint32 (*fixture_u32p_o);

/* ::fixture::u32z */
extern db_uint32 (*fixture_u32z_o);

/* ::fixture::u64p */
extern db_uint64 (*fixture_u64p_o);

/* ::fixture::u64z */
extern db_uint64 (*fixture_u64z_o);

/* ::fixture::u8p */
extern db_uint8 (*fixture_u8p_o);

/* ::fixture::u8z */
extern db_uint8 (*fixture_u8z_o);

int fixture_load(void);
#ifdef __cplusplus
}
#endif
#endif

