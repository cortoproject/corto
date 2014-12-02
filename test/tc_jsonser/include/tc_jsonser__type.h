/* tc_jsonser__type.h
 *
 *  Generated on Nov 29 2014
 *    Type-definitions for C-language.
 *    This file contains generated code. Do not modify!
 */

#ifndef tc_jsonser__type_H
#define tc_jsonser__type_H

#include "hyve.h"
#ifdef __cplusplus
extern "C" {
#endif

/* Casting macro's for classes */
#define tc_jsonser_Point(o) ((tc_jsonser_Point)o)
#define tc_jsonser_PointPoint(o) ((tc_jsonser_PointPoint)o)

/* Type definitions */


/*  ::tc_jsonser::Point */
DB_CLASS(tc_jsonser_Point);
DB_CLASS_DEF(tc_jsonser_Point) {
    db_uint32 x;
    db_uint32 y;
};

/*  ::tc_jsonser::PointPoint */
DB_CLASS(tc_jsonser_PointPoint);
DB_CLASS_DEF(tc_jsonser_PointPoint) {
    db_uint32 x;
    db_uint32 y;
    tc_jsonser_Point other;
};

#ifdef __cplusplus
}
#endif
#endif

