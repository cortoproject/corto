/* Foo__api.c
 *
 *  Generated on Jan 17 2014
 *    API convenience functions for C-language.
 *    This file contains generated code. Do not modify!
 */

#include "Foo__meta.h"
#include "Foo__api.h"

Foo_Point Foo_Point__new(void) {
    return db_new(db_typedef(Foo_Point_o));
}

Foo_Point Foo_Point__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(Foo_Point_o));
}

int Foo_Point__define(Foo_Point _this, db_uint32 x, db_uint32 y) {
    _this->x = x;
    _this->y = y;
    return db_define(_this);
}

Foo_Point Foo_Point__create(db_uint32 x, db_uint32 y) {
    Foo_Point _this;
    _this = db_new(db_typedef(Foo_Point_o));
    _this->x = x;
    _this->y = y;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

