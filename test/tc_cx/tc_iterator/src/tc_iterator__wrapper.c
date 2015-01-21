/* tc_iterator__wrapper.c
 *
 * This file contains wrapper functions for ::tc_iterator.
 */

#include "tc_iterator.h"
#include "tc_iterator__meta.h"

void __tc_iterator_testArray(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_bool*)result = tc_iterator_testArray(
        );
}

void __tc_iterator_testList(cx_function f, void *result, void *args) {
    CX_UNUSED(f);
    CX_UNUSED(args);
    *(cx_bool*)result = tc_iterator_testList(
        );
}
