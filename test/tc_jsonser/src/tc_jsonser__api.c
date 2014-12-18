/* tc_jsonser__api.c
 *
 *    API convenience functions for C-language.
 *    This file contains generated code. Do not modify!
 */

#include "tc_jsonser__meta.h"
#include "tc_jsonser__api.h"

tc_jsonser_Dog tc_jsonser_Dog__new(void) {
    return db_new(db_typedef(tc_jsonser_Dog_o));
}

tc_jsonser_Dog tc_jsonser_Dog__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(tc_jsonser_Dog_o));
}

int tc_jsonser_Dog__define(tc_jsonser_Dog _this, tc_jsonser_DogBreed breed, db_string name, db_uint8 age, tc_jsonser_Dog lover) {
    _this->breed = breed;
    _this->name = (name ? db_strdup(name) : NULL);
    _this->age = age;
    lover ? db_keep_ext(_this, lover, "element <0x8ef7cd0>.lover") : 0; _this->lover = lover;
    return db_define(_this);
}

tc_jsonser_Dog tc_jsonser_Dog__create(tc_jsonser_DogBreed breed, db_string name, db_uint8 age, tc_jsonser_Dog lover) {
    tc_jsonser_Dog _this;
    _this = db_new(db_typedef(tc_jsonser_Dog_o));
    _this->breed = breed;
    _this->name = (name ? db_strdup(name) : NULL);
    _this->age = age;
    lover ? db_keep_ext(_this, lover, "element <0x8ef7cd0>.lover") : 0; _this->lover = lover;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

