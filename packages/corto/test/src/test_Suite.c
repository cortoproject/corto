/* test_Suite.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#define corto_test_LIB
#include "test.h"

/* ::corto::test::Suite::construct() */
cx_int16 _test_Suite_construct(test_Suite this) {
/* $begin(::corto::test::Suite::construct) */
    if (this->test) {
        this->result.success = TRUE;
        extern cx_threadKey test_suiteKey;
        cx_threadTlsSet(test_suiteKey, this);
        cx_call(cx_function(this->test), NULL, this);
        cx_threadTlsSet(test_suiteKey, NULL);
    } else {
        goto error;
    }
    return 0;
error:
    return -1;
/* $end */
}

/* ::corto::test::Suite::setup() */
cx_void _test_Suite_setup_v(test_Suite this) {
/* $begin(::corto::test::Suite::setup) */
    CX_UNUSED(this);
/* $end */
}

/* ::corto::test::Suite::teardown() */
cx_void _test_Suite_teardown_v(test_Suite this) {
/* $begin(::corto::test::Suite::teardown) */
    CX_UNUSED(this);
/* $end */
}
