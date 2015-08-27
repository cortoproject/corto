/* test__api.h
 *
 * API convenience functions for C-language.
 * This file contains generated code. Do not modify!
 */

#ifndef test__API_H
#define test__API_H

#include "test__type.h"
#include "corto.h"

#ifdef __cplusplus
extern "C" {
#endif
/* ::corto::test::Case */
test_Case test_Case__create(cx_type returnType, cx_bool returnsReference, cx_bool virtual);
test_Case test_Case__createChild(cx_object _parent, cx_string _name, cx_type returnType, cx_bool returnsReference, cx_bool virtual);

test_Case test_Case__declare(void);
test_Case test_Case__declareChild(cx_object _parent, cx_string _name);
cx_int16 test_Case__define(test_Case _this, cx_type returnType, cx_bool returnsReference, cx_bool virtual);
void test_Case__update(test_Case _this, cx_type returnType, cx_bool returnsReference, cx_bool virtual);
void test_Case__set(test_Case _this, cx_type returnType, cx_bool returnsReference, cx_bool virtual);
cx_string test_Case__str(test_Case value);
test_Case test_Case__fromStr(test_Case value, cx_string str);
cx_int16 test_Case__copy(test_Case *dst, test_Case src);
cx_int16 test_Case__compare(test_Case dst, test_Case src);

/* ::corto::test::Result */
test_Result* test_Result__create(cx_string assertmsg, cx_string errmsg);
test_Result* test_Result__createChild(cx_object _parent, cx_string _name, cx_string assertmsg, cx_string errmsg);

test_Result* test_Result__declare(void);
test_Result* test_Result__declareChild(cx_object _parent, cx_string _name);
cx_int16 test_Result__define(test_Result* _this, cx_string assertmsg, cx_string errmsg);
void test_Result__update(test_Result* _this, cx_string assertmsg, cx_string errmsg);
void test_Result__set(test_Result* _this, cx_string assertmsg, cx_string errmsg);
cx_string test_Result__str(test_Result* value);
test_Result* test_Result__fromStr(test_Result* value, cx_string str);
cx_int16 test_Result__copy(test_Result* *dst, test_Result* src);
cx_int16 test_Result__compare(test_Result* dst, test_Result* src);

cx_int16 test_Result__init(test_Result* value);
cx_int16 test_Result__deinit(test_Result* value);

/* ::corto::test::Runner */
test_Runner test_Runner__create(test_Suite_list successes, test_Suite_list failures);
test_Runner test_Runner__createChild(cx_object _parent, cx_string _name, test_Suite_list successes, test_Suite_list failures);

test_Runner test_Runner__declare(void);
test_Runner test_Runner__declareChild(cx_object _parent, cx_string _name);
cx_int16 test_Runner__define(test_Runner _this, test_Suite_list successes, test_Suite_list failures);
void test_Runner__update(test_Runner _this, test_Suite_list successes, test_Suite_list failures);
void test_Runner__set(test_Runner _this, test_Suite_list successes, test_Suite_list failures);
cx_string test_Runner__str(test_Runner value);
test_Runner test_Runner__fromStr(test_Runner value, cx_string str);
cx_int16 test_Runner__copy(test_Runner *dst, test_Runner src);
cx_int16 test_Runner__compare(test_Runner dst, test_Runner src);

/* ::corto::test::Suite */
test_Suite test_Suite__create(test_Case test);
test_Suite test_Suite__createChild(cx_object _parent, cx_string _name, test_Case test);

test_Suite test_Suite__declare(void);
test_Suite test_Suite__declareChild(cx_object _parent, cx_string _name);
cx_int16 test_Suite__define(test_Suite _this, test_Case test);
void test_Suite__update(test_Suite _this, test_Case test);
void test_Suite__set(test_Suite _this, test_Case test);
cx_string test_Suite__str(test_Suite value);
test_Suite test_Suite__fromStr(test_Suite value, cx_string str);
cx_int16 test_Suite__copy(test_Suite *dst, test_Suite src);
cx_int16 test_Suite__compare(test_Suite dst, test_Suite src);


/* <0x7fce69582548> */
#define test_Suite_list__foreach(list, elem) \
    cx_iter elem##_iter = cx_llIter(list);\
    test_Suite elem;\
    while(cx_iterHasNext(&elem##_iter)) {\
        elem = cx_iterNext(&elem##_iter);

void test_Suite_list__insert(test_Suite_list list, test_Suite element);
void test_Suite_list__append(test_Suite_list list, test_Suite element);
test_Suite test_Suite_list__takeFirst(test_Suite_list list);
test_Suite test_Suite_list__last(test_Suite_list list);
void test_Suite_list__clear(test_Suite_list list);
test_Suite test_Suite_list__get(test_Suite_list list, cx_uint32 index);
cx_uint32 test_Suite_list__size(test_Suite_list list);

#ifdef __cplusplus
}
#endif
#endif

