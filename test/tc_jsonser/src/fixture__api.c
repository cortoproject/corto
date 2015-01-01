/* fixture__api.c
 *
 *    API convenience functions for C-language.
 *    This file contains generated code. Do not modify!
 */

#include "fixture__meta.h"
#include "fixture__api.h"

fixture_Dog fixture_Dog__new(void) {
    return cx_new(cx_typedef(fixture_Dog_o));
}

fixture_Dog fixture_Dog__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_typedef(fixture_Dog_o));
}

int fixture_Dog__define(fixture_Dog _this, fixture_DogBreed breed, cx_string name, cx_uint8 age, fixture_Dog lover) {
    _this->breed = breed;
    _this->name = (name ? cx_strdup(name) : NULL);
    _this->age = age;
    lover ? cx_keep_ext(_this, lover, "element <0x8ce6998>.lover") : 0; _this->lover = lover;
    return cx_define(_this);
}

fixture_Dog fixture_Dog__create(fixture_DogBreed breed, cx_string name, cx_uint8 age, fixture_Dog lover) {
    fixture_Dog _this;
    _this = cx_new(cx_typedef(fixture_Dog_o));
    _this->breed = breed;
    _this->name = (name ? cx_strdup(name) : NULL);
    _this->age = age;
    lover ? cx_keep_ext(_this, lover, "element <0x8ce6998>.lover") : 0; _this->lover = lover;
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

