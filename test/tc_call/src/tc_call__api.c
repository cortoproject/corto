/* tc_call__api.c
 *
 *  Generated on Feb  5 2014
 *    API convenience functions for C-language.
 *    This file contains generated code. Do not modify!
 */

#include "tc_call__meta.h"
#include "tc_call__api.h"

tc_Animal tc_Animal__new(void) {
    return db_new(db_typedef(tc_Animal_o));
}

tc_Animal tc_Animal__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(tc_Animal_o));
}

int tc_Animal__define(tc_Animal _this, tc_AnimalKind kind) {
    _this->kind = kind;
    return db_define(_this);
}

tc_Animal tc_Animal__create(tc_AnimalKind kind) {
    tc_Animal _this;
    _this = db_new(db_typedef(tc_Animal_o));
    _this->kind = kind;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

tc_Mammal tc_Mammal__new(void) {
    return db_new(db_typedef(tc_Mammal_o));
}

tc_Mammal tc_Mammal__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(tc_Mammal_o));
}

int tc_Mammal__define(tc_Mammal _this, tc_MammalKind kind) {
    _this->kind = kind;
    return db_define(_this);
}

tc_Mammal tc_Mammal__create(tc_MammalKind kind) {
    tc_Mammal _this;
    _this = db_new(db_typedef(tc_Mammal_o));
    _this->kind = kind;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

