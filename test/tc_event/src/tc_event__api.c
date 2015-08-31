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

int tc_PointDefine(tc_Point _this, cx_uint32 x, cx_uint32 y) {
    _this->x = x;
    _this->y = y;
    return cx_define(_this);
}

tc_Point tc_PointCreate(cx_uint32 x, cx_uint32 y) {
    tc_Point _this;
    _this = cx_declare(tc_Point_o);
    _this->x = x;
    _this->y = y;
    if (cx_define(_this)) {
        cx_release(_this);
        _this = NULL;
    }
    return _this;
}

