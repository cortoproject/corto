/* test_unit.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "test.h"
#include "test__meta.h"

/* ::cortex::test::unit::construct() */
cx_int16 test_unit_construct(test_unit _this) {
/* $begin(::cortex::test::unit::construct) */

    _this->success = TRUE;

    return 0;
/* $end */
}

/* ::cortex::test::unit::fail(string msg) */
cx_void test_unit_fail(test_unit _this, cx_string msg) {
/* $begin(::cortex::test::unit::fail) */

    if (_this->failmsg) {
        cx_dealloc(_this->failmsg);
    }
    _this->failmsg = cx_strdup(msg);
    _this->success = FALSE;

/* $end */
}
