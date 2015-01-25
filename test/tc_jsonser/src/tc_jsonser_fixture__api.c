/* tc_jsonser_fixture__api.c
 *
 *    API convenience functions for C-language.
 *    This file contains generated code. Do not modify!
 */

#include "tc_jsonser_fixture__meta.h"
#include "tc_jsonser_fixture__api.h"

tc_jsonser_fixture_Dog tc_jsonser_fixture_Dog__new(void) {
    return cx_new(cx_type(tc_jsonser_fixture_Dog_o));
}

tc_jsonser_fixture_Dog tc_jsonser_fixture_Dog__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(tc_jsonser_fixture_Dog_o));
}

int tc_jsonser_fixture_Dog__define(tc_jsonser_fixture_Dog _this, tc_jsonser_fixture_DogBreed breed, cx_string name, cx_uint8 age, tc_jsonser_fixture_Dog lover) {
    _this->breed = breed;
    _this->name = (name ? cx_strdup(name) : NULL);
    _this->age = age;
    lover ? cx_keep_ext(_this, lover, "element <0x9fc7108>.lover") : 0; _this->lover = lover;
    return cx_define(_this);
}

tc_jsonser_fixture_Dog tc_jsonser_fixture_Dog__create(tc_jsonser_fixture_DogBreed breed, cx_string name, cx_uint8 age, tc_jsonser_fixture_Dog lover) {
    tc_jsonser_fixture_Dog _this;
    _this = cx_new(cx_type(tc_jsonser_fixture_Dog_o));
    _this->breed = breed;
    _this->name = (name ? cx_strdup(name) : NULL);
    _this->age = age;
    lover ? cx_keep_ext(_this, lover, "element <0x9fd1010>.lover") : 0; _this->lover = lover;
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

void tc_jsonser_fixture_point2D__init(tc_jsonser_fixture_point2D *_this, cx_int32 x, cx_int32 y) {
    cx_value v;
    memset(_this, 0, sizeof(*_this));
    cx_valueValueInit(&v, NULL, cx_type(tc_jsonser_fixture_point2D_o), _this);
    cx_initValue(&v);
    _this->x = x;
    _this->y = y;
}

void tc_jsonser_fixture_point2D__deinit(tc_jsonser_fixture_point2D *_this) {
    cx_value v;
    cx_valueValueInit(&v, NULL, cx_type(tc_jsonser_fixture_point2D_o), _this);
    cx_deinitValue(&v);
}

void tc_jsonser_fixture_stringlist__insert(tc_jsonser_fixture_stringlist list, cx_string element) {
    cx_llInsert(list, (void*)element);
}

void tc_jsonser_fixture_stringlist__append(tc_jsonser_fixture_stringlist list, cx_string element) {
    cx_llAppend(list, (void*)element);
}

cx_string tc_jsonser_fixture_stringlist__takeFirst(tc_jsonser_fixture_stringlist list) {
    return (cx_string)cx_llTakeFirst(list);
}

cx_string tc_jsonser_fixture_stringlist__last(tc_jsonser_fixture_stringlist list) {
    return (cx_string)cx_llLast(list);
}

void tc_jsonser_fixture_stringlist__clear(tc_jsonser_fixture_stringlist list) {
    void *element;

    while((element = cx_llTakeFirst(list))) {
    }
}

cx_string tc_jsonser_fixture_stringlist__get(tc_jsonser_fixture_stringlist list, cx_uint32 index) {
    return (cx_string)cx_llGet(list, index);
}

cx_uint32 tc_jsonser_fixture_stringlist__size(tc_jsonser_fixture_stringlist list) {
    return cx_llSize(list);
}

