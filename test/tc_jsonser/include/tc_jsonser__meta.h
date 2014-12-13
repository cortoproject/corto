/* tc_jsonser__meta.h
 *
 * Loads objects in database.
 * This file contains generated code. Do not modify!
 */

#ifndef tc_jsonser_META_H
#define tc_jsonser_META_H

#include "hyve.h"

#include "tc_jsonser__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::tc_jsonser */
extern db_object tc_jsonser_o;

/* ::tc_jsonser::bf */
extern db_bool (*tc_jsonser_bf_o);

/* ::tc_jsonser::bt */
extern db_bool (*tc_jsonser_bt_o);

/* ::tc_jsonser::Djinn */
extern db_enum tc_jsonser_Djinn_o;

/* ::tc_jsonser::Djinn::Jupiter */
extern db_constant (*tc_jsonser_Djinn_Jupiter_o);

/* ::tc_jsonser::Djinn::Mars */
extern db_constant (*tc_jsonser_Djinn_Mars_o);

/* ::tc_jsonser::Djinn::Mercury */
extern db_constant (*tc_jsonser_Djinn_Mercury_o);

/* ::tc_jsonser::Djinn::Venus */
extern db_constant (*tc_jsonser_Djinn_Venus_o);

/* ::tc_jsonser::f32n */
extern db_float32 (*tc_jsonser_f32n_o);

/* ::tc_jsonser::f32p */
extern db_float32 (*tc_jsonser_f32p_o);

/* ::tc_jsonser::f32z */
extern db_float32 (*tc_jsonser_f32z_o);

/* ::tc_jsonser::f64n */
extern db_float32 (*tc_jsonser_f64n_o);

/* ::tc_jsonser::f64p */
extern db_float32 (*tc_jsonser_f64p_o);

/* ::tc_jsonser::f64z */
extern db_float32 (*tc_jsonser_f64z_o);

/* ::tc_jsonser::Flint */
extern tc_jsonser_Djinn (*tc_jsonser_Flint_o);

/* ::tc_jsonser::Forge */
extern tc_jsonser_Djinn (*tc_jsonser_Forge_o);

/* ::tc_jsonser::Gust */
extern tc_jsonser_Djinn (*tc_jsonser_Gust_o);

/* ::tc_jsonser::i16n */
extern db_int16 (*tc_jsonser_i16n_o);

/* ::tc_jsonser::i16p */
extern db_int16 (*tc_jsonser_i16p_o);

/* ::tc_jsonser::i16z */
extern db_int16 (*tc_jsonser_i16z_o);

/* ::tc_jsonser::i32n */
extern db_int32 (*tc_jsonser_i32n_o);

/* ::tc_jsonser::i32p */
extern db_int32 (*tc_jsonser_i32p_o);

/* ::tc_jsonser::i32z */
extern db_int32 (*tc_jsonser_i32z_o);

/* ::tc_jsonser::i64n */
extern db_int64 (*tc_jsonser_i64n_o);

/* ::tc_jsonser::i64p */
extern db_int64 (*tc_jsonser_i64p_o);

/* ::tc_jsonser::i64z */
extern db_int64 (*tc_jsonser_i64z_o);

/* ::tc_jsonser::i8n */
extern db_int8 (*tc_jsonser_i8n_o);

/* ::tc_jsonser::i8p */
extern db_int8 (*tc_jsonser_i8p_o);

/* ::tc_jsonser::i8z */
extern db_int8 (*tc_jsonser_i8z_o);

/* ::tc_jsonser::namesp */
extern db_void (*tc_jsonser_namesp_o);

/* ::tc_jsonser::namesp::a */
extern db_int16 (*tc_jsonser_namesp_a_o);

/* ::tc_jsonser::namesp::b */
extern db_string (*tc_jsonser_namesp_b_o);

/* ::tc_jsonser::p */
extern tc_jsonser_point2D (*tc_jsonser_p_o);

/* ::tc_jsonser::point2D */
extern db_struct tc_jsonser_point2D_o;

/* ::tc_jsonser::point2D::x */
extern db_member tc_jsonser_point2D_x_o;

/* ::tc_jsonser::point2D::y */
extern db_member tc_jsonser_point2D_y_o;

/* ::tc_jsonser::s1 */
extern db_string (*tc_jsonser_s1_o);

/* ::tc_jsonser::s10 */
extern db_string (*tc_jsonser_s10_o);

/* ::tc_jsonser::s11 */
extern db_string (*tc_jsonser_s11_o);

/* ::tc_jsonser::s12 */
extern db_string (*tc_jsonser_s12_o);

/* ::tc_jsonser::s13 */
extern db_string (*tc_jsonser_s13_o);

/* ::tc_jsonser::s14 */
extern db_string (*tc_jsonser_s14_o);

/* ::tc_jsonser::s2 */
extern db_string (*tc_jsonser_s2_o);

/* ::tc_jsonser::s3 */
extern db_string (*tc_jsonser_s3_o);

/* ::tc_jsonser::s4 */
extern db_string (*tc_jsonser_s4_o);

/* ::tc_jsonser::s5 */
extern db_string (*tc_jsonser_s5_o);

/* ::tc_jsonser::s6 */
extern db_string (*tc_jsonser_s6_o);

/* ::tc_jsonser::s7 */
extern db_string (*tc_jsonser_s7_o);

/* ::tc_jsonser::s8 */
extern db_string (*tc_jsonser_s8_o);

/* ::tc_jsonser::s9 */
extern db_string (*tc_jsonser_s9_o);

/* ::tc_jsonser::Sleet */
extern tc_jsonser_Djinn (*tc_jsonser_Sleet_o);

/* ::tc_jsonser::sn */
extern db_string (*tc_jsonser_sn_o);

/* ::tc_jsonser::u16p */
extern db_uint16 (*tc_jsonser_u16p_o);

/* ::tc_jsonser::u16z */
extern db_uint16 (*tc_jsonser_u16z_o);

/* ::tc_jsonser::u32p */
extern db_uint32 (*tc_jsonser_u32p_o);

/* ::tc_jsonser::u32z */
extern db_uint32 (*tc_jsonser_u32z_o);

/* ::tc_jsonser::u64p */
extern db_uint64 (*tc_jsonser_u64p_o);

/* ::tc_jsonser::u64z */
extern db_uint64 (*tc_jsonser_u64z_o);

/* ::tc_jsonser::u8p */
extern db_uint8 (*tc_jsonser_u8p_o);

/* ::tc_jsonser::u8z */
extern db_uint8 (*tc_jsonser_u8z_o);

int tc_jsonser_load(void);
#ifdef __cplusplus
}
#endif
#endif

