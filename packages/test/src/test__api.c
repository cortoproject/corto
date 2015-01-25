/* test__api.c
 *
 *    API convenience functions for C-language.
 *    This file contains generated code. Do not modify!
 */

#include "test__meta.h"
#include "test__api.h"

test_suite test_suite__new(void) {
    return cx_new(cx_type(test_suite_o));
}

test_suite test_suite__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(test_suite_o));
}

int test_suite__define(test_suite _this, cx_object package, cx_bool silent) {
    package ? cx_keep_ext(_this, package, "element <0x87f51a0>.package") : 0; _this->package = package;
    _this->silent = silent;
    return cx_define(_this);
}

test_suite test_suite__create(cx_object package, cx_bool silent) {
    test_suite _this;
    _this = cx_new(cx_type(test_suite_o));
    package ? cx_keep_ext(_this, package, "element <0x87f51a0>.package") : 0; _this->package = package;
    _this->silent = silent;
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

test_test test_test__new(void) {
    return cx_new(cx_type(test_test_o));
}

test_test test_test__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(test_test_o));
}

int test_test__define(test_test _this, cx_type returnType, cx_bool returnsReference) {
    returnType ? cx_keep_ext(_this, returnType, "element <0x87b4b58>.returnType") : 0; cx_function(_this)->returnType = returnType;
    cx_function(_this)->returnsReference = returnsReference;
    return cx_define(_this);
}

test_test test_test__create(cx_type returnType, cx_bool returnsReference) {
    test_test _this;
    _this = cx_new(cx_type(test_test_o));
    returnType ? cx_keep_ext(_this, returnType, "element <0x87b4b58>.returnType") : 0; cx_function(_this)->returnType = returnType;
    cx_function(_this)->returnsReference = returnsReference;
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

test_unit test_unit__new(void) {
    return cx_new(cx_type(test_unit_o));
}

test_unit test_unit__declare(cx_object _parent, cx_string _name) {
    return cx_declare(_parent, _name, cx_type(test_unit_o));
}

int test_unit__define(test_unit _this) {
    return cx_define(_this);
}

test_unit test_unit__create(void) {
    test_unit _this;
    _this = cx_new(cx_type(test_unit_o));
    if (cx_define(_this)) {
        cx_free(_this);
        _this = NULL;
    }
    return _this;
}

