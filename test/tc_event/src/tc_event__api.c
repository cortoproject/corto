/* tc_event__api.c
 *
 *  Generated on Feb  5 2014
 *    API convenience functions for C-language.
 *    This file contains generated code. Do not modify!
 */

#include "tc_event__meta.h"
#include "tc_event__api.h"

tc_Point tc_Point__new(void) {
    return cx_declare(tc_Point_o);
}

tc_Point tc_PointDeclare(cx_object _parent, cx_string _name) {
    return cx_declareChild(_parent, _name, tc_Point_o);
}

int tc_PointDefine(tc_Point this, cx_uint32 x, cx_uint32 y) {
    this->x = x;
    this->y = y;
    return cx_define(this);
}

tc_Point tc_PointCreate(cx_uint32 x, cx_uint32 y) {
    tc_Point this;
    this = cx_declare(tc_Point_o);
    this->x = x;
    this->y = y;
    if (cx_define(this)) {
        cx_release(this);
        this = NULL;
    }
    return this;
}

