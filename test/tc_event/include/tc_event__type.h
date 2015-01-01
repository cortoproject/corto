/* tc_event__type.h
 *
 *  Generated on Feb  5 2014
 *    Type-definitions for C-language.
 *    This file contains generated code. Do not modify!
 */

#ifndef tc_event__type_H
#define tc_event__type_H

#include "cortex.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Casting macro's for classes */
#define tc_Point(o) ((tc_Point)o)

/* Type definitions */


/*  ::tc_event::Point */
DB_CLASS(tc_Point);
DB_CLASS_DEF(tc_Point) {
    cx_uint32 x;
    cx_uint32 y;
};
typedef cx_uint32 tc_value;

#ifdef __cplusplus
}
#endif
#endif

