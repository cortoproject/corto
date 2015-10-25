/* $CORTO_GENERATED
 *
 * test_SuiteData.c
 *
 * Code written between the begin and end tags will be preserved when the
 * file is regenerated.
 */

#include "test.h"

corto_int16 _test_SuiteData_construct(test_SuiteData this) {
/* $begin(::corto::test::SuiteData::construct) */

    if (this->test) {
        this->result.success = TRUE;
        extern corto_threadKey test_suiteKey;
        corto_threadTlsSet(test_suiteKey, this);
        test_SuiteData_setup(this);
        this->assertCount = 0;
        corto_call(corto_function(this->test), NULL, this);
        if (!this->assertCount) {
            test_fail(" not implemented");
        }
        test_SuiteData_teardown(this);
        corto_threadTlsSet(test_suiteKey, NULL);
    } else {
        corto_seterr("no test provided for suite '%s'", corto_nameof(this));
        goto error;
    }
    return 0;
error:
    return -1;

/* $end */
}

corto_void _test_SuiteData_setup_v(test_SuiteData this) {
/* $begin(::corto::test::SuiteData::setup) */

	CORTO_UNUSED(this);

/* $end */
}

corto_void _test_SuiteData_teardown_v(test_SuiteData this) {
/* $begin(::corto::test::SuiteData::teardown) */

	CORTO_UNUSED(this);
	
/* $end */
}
