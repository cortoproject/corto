/* tc_iterator.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "tc_iterator.h"
#include "tc_iterator__meta.h"

/* $header() */
#include "cx_iterator.h"
#include <stdio.h>
/* $end */

/* ::tc_iterator::testArray() */
cx_bool tc_iterator_testArray(void) {
/* $begin(::tc_iterator::testArray) */

    cx_bool result = TRUE;
    tc_iterator_intIterator iterator = {
        cx_collection(tc_iterator_intArray_o),
        tc_iterator_array1_o,
        tc_iterator_array1_o
    };
    cx_any anyIterator = {cx_type(tc_iterator_intIterator_o), &iterator, FALSE};

    if (!cx_iterator_hasNext(anyIterator)) {
        cx_error("hasNext did not return TRUE for unfinished array");
        result = FALSE;
    }

    cx_iterator_next(anyIterator);
    if (!cx_iterator_hasNext(anyIterator)) {
        cx_error("hasNext did not return TRUE for unfinished array");
        result = FALSE;
    }

    cx_iterator_next(anyIterator);
    if (!cx_iterator_hasNext(anyIterator)) {
        cx_error("hasNext did not return TRUE for unfinished array");
        result = FALSE;
    }

    cx_iterator_next(anyIterator);
    if (cx_iterator_hasNext(anyIterator)) {
        cx_error("hasNext did not return FALSE for last element");
        result = FALSE;
    }

    return result;

/* $end */
}
