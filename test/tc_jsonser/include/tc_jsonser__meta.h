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

/* ::tc_jsonser::namesp */
extern db_string (*tc_jsonser_namesp_o);

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

/* ::tc_jsonser::s2 */
extern db_string (*tc_jsonser_s2_o);

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

int tc_jsonser_load(void);
#ifdef __cplusplus
}
#endif
#endif

