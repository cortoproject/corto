/* tc_iterator__api.c
 *
 *    API convenience functions for C-language.
 *    This file contains generated code. Do not modify!
 */

#include "tc_iterator__meta.h"
#include "tc_iterator__api.h"

void tc_iterator_intList__insert(tc_iterator_intList list, cx_int32 element) {
    cx_llInsert(list, (void*)element);
}

void tc_iterator_intList__append(tc_iterator_intList list, cx_int32 element) {
    cx_llAppend(list, (void*)element);
}

cx_int32 tc_iterator_intList__takeFirst(tc_iterator_intList list) {
    return (cx_int32)cx_llTakeFirst(list);
}

cx_int32 tc_iterator_intList__last(tc_iterator_intList list) {
    return (cx_int32)cx_llLast(list);
}

void tc_iterator_intList__clear(tc_iterator_intList list) {
    void *element;

    while((element = cx_llTakeFirst(list))) {
    }
}

cx_int32 tc_iterator_intList__get(tc_iterator_intList list, cx_uint32 index) {
    return (cx_int32)cx_llGet(list, index);
}

cx_uint32 tc_iterator_intList__size(tc_iterator_intList list) {
    return cx_llSize(list);
}

