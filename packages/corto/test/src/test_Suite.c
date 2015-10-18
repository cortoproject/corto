/* test_Suite.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "test.h"

/* ::corto::test::Suite::construct() */
cx_int16 _test_Suite_construct(test_Suite this) {
/* $begin(::corto::test::Suite::construct) */
    cx_interface(this)->base = cx_interface(test_SuiteData_o);
    return cx_class_construct(this);
/* $end */
}
