/* fixture__api.c
 *
 *    API convenience functions for C-language.
 *    This file contains generated code. Do not modify!
 */

#include "fixture__meta.h"
#include "fixture__api.h"

fixture_Dog fixture_Dog__new(void) {
    return db_new(db_typedef(fixture_Dog_o));
}

fixture_Dog fixture_Dog__declare(db_object _parent, db_string _name) {
    return db_declare(_parent, _name, db_typedef(fixture_Dog_o));
}

int fixture_Dog__define(fixture_Dog _this, fixture_DogBreed breed, db_string name, db_uint8 age, fixture_Dog lover) {
    _this->breed = breed;
    _this->name = (name ? db_strdup(name) : NULL);
    _this->age = age;
    lover ? db_keep_ext(_this, lover, "element <0x8658618>.lover") : 0; _this->lover = lover;
    return db_define(_this);
}

fixture_Dog fixture_Dog__create(fixture_DogBreed breed, db_string name, db_uint8 age, fixture_Dog lover) {
    fixture_Dog _this;
    _this = db_new(db_typedef(fixture_Dog_o));
    _this->breed = breed;
    _this->name = (name ? db_strdup(name) : NULL);
    _this->age = age;
    lover ? db_keep_ext(_this, lover, "element <0x8658618>.lover") : 0; _this->lover = lover;
    if (db_define(_this)) {
        db_free(_this);
        _this = NULL;
    }
    return _this;
}

