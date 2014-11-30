/* tc_jsonser__api.h
 *
 *  Generated on Nov 29 2014
 *    API convenience functions for C-language.
 *    This file contains generated code. Do not modify!
 */

#ifndef tc_jsonser__API_H
#define tc_jsonser__API_H

#include "tc_jsonser__type.h"
#include "hyve.h"

#ifdef __cplusplus
extern "C" {
#endif
/* ::tc_jsonser::Point */
tc_jsonser_Point tc_jsonser_Point__new(void);
tc_jsonser_Point tc_jsonser_Point__declare(db_object _parent, db_string _name);
int tc_jsonser_Point__define(tc_jsonser_Point _this, db_uint32 x, db_uint32 y);
tc_jsonser_Point tc_jsonser_Point__create(db_uint32 x, db_uint32 y);

/* ::tc_jsonser::PointPoint */
tc_jsonser_PointPoint tc_jsonser_PointPoint__new(void);
tc_jsonser_PointPoint tc_jsonser_PointPoint__declare(db_object _parent, db_string _name);
int tc_jsonser_PointPoint__define(tc_jsonser_PointPoint _this, db_uint32 x, db_uint32 y, tc_jsonser_Point other);
tc_jsonser_PointPoint tc_jsonser_PointPoint__create(db_uint32 x, db_uint32 y, tc_jsonser_Point other);


#ifdef __cplusplus
}
#endif
#endif

