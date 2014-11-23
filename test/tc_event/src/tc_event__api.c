/* tc_event__api.c
 *
 *  Generated on Feb  5 2014
 *    API convenience functions for C-language.
 *    This file contains generated code. Do not modify!
 */

#include "tc_event__meta.h"
#include "tc_event__api.h"

tc_Point tc_Point__new(void) {
    return db_new(db_typedef(tc_Point_o));
}

tc_Point tc_Point__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(tc_Point_o));
}

int tc_Point__define(tc_Point _this, db_uint32 x, db_uint32 y) {
    _this->x = x;
    _this->y = y;
    return db_define(_this);
}

tc_Point tc_Point__create(db_uint32 x, db_uint32 y) {
    tc_Point _this;
    _this = db_new(db_typedef(tc_Point_o));
    _this->x = x;
    _this->y = y;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

