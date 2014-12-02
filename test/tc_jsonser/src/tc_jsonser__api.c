/* tc_jsonser__api.c
 *
 *  Generated on Nov 29 2014
 *    API convenience functions for C-language.
 *    This file contains generated code. Do not modify!
 */

#include "tc_jsonser__meta.h"
#include "tc_jsonser__api.h"

tc_jsonser_Point tc_jsonser_Point__new(void) {
    return db_new(db_typedef(tc_jsonser_Point_o));
}

tc_jsonser_Point tc_jsonser_Point__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(tc_jsonser_Point_o));
}

int tc_jsonser_Point__define(tc_jsonser_Point _this, db_uint32 x, db_uint32 y) {
    _this->x = x;
    _this->y = y;
    return db_define(_this);
}

tc_jsonser_Point tc_jsonser_Point__create(db_uint32 x, db_uint32 y) {
    tc_jsonser_Point _this;
    _this = db_new(db_typedef(tc_jsonser_Point_o));
    _this->x = x;
    _this->y = y;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

tc_jsonser_PointPoint tc_jsonser_PointPoint__new(void) {
    return db_new(db_typedef(tc_jsonser_PointPoint_o));
}

tc_jsonser_PointPoint tc_jsonser_PointPoint__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(tc_jsonser_PointPoint_o));
}

int tc_jsonser_PointPoint__define(tc_jsonser_PointPoint _this, db_uint32 x, db_uint32 y, tc_jsonser_Point other) {
    _this->x = x;
    _this->y = y;
    other ? db_keep_ext(_this, other, "element <0x89073d8>.other") : 0; _this->other = other;
    return db_define(_this);
}

tc_jsonser_PointPoint tc_jsonser_PointPoint__create(db_uint32 x, db_uint32 y, tc_jsonser_Point other) {
    tc_jsonser_PointPoint _this;
    _this = db_new(db_typedef(tc_jsonser_PointPoint_o));
    _this->x = x;
    _this->y = y;
    other ? db_keep_ext(_this, other, "element <0x89073d8>.other") : 0; _this->other = other;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

