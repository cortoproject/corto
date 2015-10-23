/* test_Suite.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "test.h"

/* ::corto::test::Suite::construct() */
corto_int16 _test_Suite_construct(test_Suite this) {
/* $begin(::corto::test::Suite::construct) */
    corto_interface(this)->base = corto_interface(test_SuiteData_o);
    return corto_class_construct(this);
/* $end */
}
