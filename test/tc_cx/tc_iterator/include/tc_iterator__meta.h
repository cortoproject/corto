/* tc_iterator__meta.h
 *
 * Loads objects in database.
 * This file contains generated code. Do not modify!
 */

#ifndef tc_iterator_META_H
#define tc_iterator_META_H

#include "cortex.h"

#include "tc_iterator__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::tc_iterator */
extern cx_object tc_iterator_o;

/* ::tc_iterator::array1 */
extern tc_iterator_intArray (*tc_iterator_array1_o);

/* ::tc_iterator::intArray */
extern cx_array tc_iterator_intArray_o;

/* ::tc_iterator::intIterator */
extern cx_iterator tc_iterator_intIterator_o;

/* ::tc_iterator::intList */
extern cx_list tc_iterator_intList_o;

/* ::tc_iterator::list1 */
extern tc_iterator_intList (*tc_iterator_list1_o);

/* ::tc_iterator::testArray() */
extern cx_function tc_iterator_testArray_o;

/* ::tc_iterator::testList() */
extern cx_function tc_iterator_testList_o;

int tc_iterator_load(void);
#ifdef __cplusplus
}
#endif
#endif

