/* tc_jsonser_fixture__api.h
 *
 *    API convenience functions for C-language.
 *    This file contains generated code. Do not modify!
 */

#ifndef tc_jsonser_fixture__API_H
#define tc_jsonser_fixture__API_H

#include "tc_jsonser_fixture__type.h"
#include "cortex.h"

#ifdef __cplusplus
extern "C" {
#endif
/* ::tc_jsonser_fixture::Dog */
tc_jsonser_fixture_Dog tc_jsonser_fixture_Dog__new(void);
tc_jsonser_fixture_Dog tc_jsonser_fixture_Dog__declare(cx_object _parent, cx_string _name);
int tc_jsonser_fixture_Dog__define(tc_jsonser_fixture_Dog _this, tc_jsonser_fixture_DogBreed breed, cx_string name, cx_uint8 age, tc_jsonser_fixture_Dog lover);
tc_jsonser_fixture_Dog tc_jsonser_fixture_Dog__create(tc_jsonser_fixture_DogBreed breed, cx_string name, cx_uint8 age, tc_jsonser_fixture_Dog lover);

/* ::tc_jsonser_fixture::point2D */
void tc_jsonser_fixture_point2D__init(tc_jsonser_fixture_point2D *_this, cx_int32 x, cx_int32 y);
void tc_jsonser_fixture_point2D__deinit(tc_jsonser_fixture_point2D *_this);


/* ::tc_jsonser_fixture::stringlist */
#define tc_jsonser_fixture_stringlist__foreach(list, elem) \
    cx_iter elem##_iter = cx_llIter(list);\
    cx_string *elem;\
    while(cx_iterHasNext(&elem##_iter)) {\
        elem = cx_iterNext(&elem##_iter);

void tc_jsonser_fixture_stringlist__insert(tc_jsonser_fixture_stringlist list, cx_string element);
void tc_jsonser_fixture_stringlist__append(tc_jsonser_fixture_stringlist list, cx_string element);
cx_string tc_jsonser_fixture_stringlist__takeFirst(tc_jsonser_fixture_stringlist list);
cx_string tc_jsonser_fixture_stringlist__last(tc_jsonser_fixture_stringlist list);
void tc_jsonser_fixture_stringlist__clear(tc_jsonser_fixture_stringlist list);
cx_string tc_jsonser_fixture_stringlist__get(tc_jsonser_fixture_stringlist list, cx_uint32 index);
cx_uint32 tc_jsonser_fixture_stringlist__size(tc_jsonser_fixture_stringlist list);

#ifdef __cplusplus
}
#endif
#endif

