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
    if (this->test) {
        this->result.success = TRUE;
        extern cx_threadKey test_suiteKey;
        cx_threadTlsSet(test_suiteKey, this);
        test_Suite_setup(this);
        this->assertCount = 0;
        cx_call(cx_function(this->test), NULL, this);
        if (!this->assertCount) {
            test_fail(" not implemented");
        }
        test_Suite_teardown(this);
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
