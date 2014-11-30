/* tc_jsonser__meta.h
 *
 *  Generated on Nov 29 2014
 *    Loads objects in database.
 *    This file contains generated code. Do not modify!
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

/* ::tc_jsonser::p */
extern tc_jsonser_Point tc_jsonser_p_o;

/* ::tc_jsonser::p::a */
extern tc_jsonser_Point tc_jsonser_p_a_o;

/* ::tc_jsonser::p::b */
extern tc_jsonser_Point tc_jsonser_p_b_o;

/* ::tc_jsonser::p::c */
extern tc_jsonser_Point tc_jsonser_p_c_o;

/* ::tc_jsonser::p::d */
extern tc_jsonser_Point tc_jsonser_p_d_o;

/* ::tc_jsonser::Point */
extern db_class tc_jsonser_Point_o;

/* ::tc_jsonser::Point::x */
extern db_member tc_jsonser_Point_x_o;

/* ::tc_jsonser::Point::y */
extern db_member tc_jsonser_Point_y_o;

/* ::tc_jsonser::PointPoint */
extern db_class tc_jsonser_PointPoint_o;

/* ::tc_jsonser::PointPoint::other */
extern db_member tc_jsonser_PointPoint_other_o;

/* ::tc_jsonser::PointPoint::x */
extern db_member tc_jsonser_PointPoint_x_o;

/* ::tc_jsonser::PointPoint::y */
extern db_member tc_jsonser_PointPoint_y_o;

/* ::tc_jsonser::pp */
extern tc_jsonser_PointPoint tc_jsonser_pp_o;

int tc_jsonser_load(void);
#ifdef __cplusplus
}
#endif
#endif

