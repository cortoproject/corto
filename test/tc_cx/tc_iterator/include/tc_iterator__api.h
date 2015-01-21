/* tc_iterator__api.h
 *
 *    API convenience functions for C-language.
 *    This file contains generated code. Do not modify!
 */

#ifndef tc_iterator__API_H
#define tc_iterator__API_H

#include "tc_iterator__type.h"
#include "cortex.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::tc_iterator::intList */
#define tc_iterator_intList__foreach(list, elem) \
    cx_iter elem##_iter = cx_llIter(list);\
    cx_int32 *elem;\
    while(cx_iterHasNext(&elem##_iter)) {\
        elem = cx_iterNext(&elem##_iter);

void tc_iterator_intList__insert(tc_iterator_intList list, cx_int32 element);
void tc_iterator_intList__append(tc_iterator_intList list, cx_int32 element);
cx_int32 tc_iterator_intList__takeFirst(tc_iterator_intList list);
cx_int32 tc_iterator_intList__last(tc_iterator_intList list);
void tc_iterator_intList__clear(tc_iterator_intList list);
cx_int32 tc_iterator_intList__get(tc_iterator_intList list, cx_uint32 index);
cx_uint32 tc_iterator_intList__size(tc_iterator_intList list);

#ifdef __cplusplus
}
#endif
#endif

