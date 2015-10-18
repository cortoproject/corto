/* test_SuiteData.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "test.h"

/* ::corto::test::SuiteData::construct() */
cx_int16 _test_SuiteData_construct(test_SuiteData this) {
/* $begin(::corto::test::SuiteData::construct) */

    if (this->test) {
        this->result.success = TRUE;
        extern cx_threadKey test_suiteKey;
        cx_threadTlsSet(test_suiteKey, this);
        test_SuiteData_setup(this);
        this->assertCount = 0;
        cx_call(cx_function(this->test), NULL, this);
        if (!this->assertCount) {
            test_fail(" not implemented");
        }
        test_SuiteData_teardown(this);
        cx_threadTlsSet(test_suiteKey, NULL);
    } else {
        cx_seterr("no test provided for suite '%s'", cx_nameof(this));
        goto error;
    }
    return 0;
error:
    return -1;

/* $end */
}

/* ::corto::test::SuiteData::setup() */
cx_void _test_SuiteData_setup_v(test_SuiteData this) {
/* $begin(::corto::test::SuiteData::setup) */

	CX_UNUSED(this);

/* $end */
}

/* ::corto::test::SuiteData::teardown() */
cx_void _test_SuiteData_teardown_v(test_SuiteData this) {
/* $begin(::corto::test::SuiteData::teardown) */

	CX_UNUSED(this);
	
/* $end */
}
