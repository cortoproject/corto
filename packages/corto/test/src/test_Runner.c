/* test_Runner.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#define corto_test_LIB
#include "test.h"

/* $header() */
/* $end */

/* ::corto::test::Runner::construct() */
cx_int16 _test_Runner_construct(test_Runner _this) {
/* $begin(::corto::test::Runner::construct) */
    test_Runner_runTest_o->mask = CX_ON_DEFINE | CX_ON_TREE | CX_ON_SELF;
    cx_listen(root_o, test_Runner_runTest_o, _this);
    return 0;
/* $end */
}

/* ::corto::test::Runner::destruct() */
cx_void _test_Runner_destruct(test_Runner _this) {
/* $begin(::corto::test::Runner::destruct) */
    cx_uint32 successCount = test_SuiteListSize(_this->successes);
    cx_uint32 failureCount = test_SuiteListSize(_this->failures);
    cx_print("%s: OK:%d, FAIL:%d", _this->name, successCount, failureCount);
/* $end */
}

/* ::corto::test::Runner::runTest() */
cx_void _test_Runner_runTest(test_Runner _this, cx_object *observable, cx_object *source) {
/* $begin(::corto::test::Runner::runTest) */
    CX_UNUSED(source);

    if (cx_instanceof(cx_type(test_Case_o), observable)) {
        cx_type testClass = cx_parentof(observable);
        test_Suite suite = test_Suite(cx_declare(testClass));
        cx_setref(&suite->test, observable);

        if (cx_define(suite)) {
            cx_error("test: failed to define test suite");
            test_SuiteListAppend(_this->failures, suite);
        } else {
            cx_object prev = cx_setSource(_this);
            if (!cx_define(suite) && suite->result.success) {
                test_SuiteListAppend(_this->successes, suite);
            } else {
                test_SuiteListAppend(_this->failures, suite);
            }
            cx_setSource(prev);            
        }

        cx_string suiteName = cx_nameof(testClass);
        cx_string testName = cx_nameof(observable);

        if (!suite->result.success) {
            cx_id signame; cx_signatureName(testName, signame);
            cx_error("FAIL: %s.%s: %s", suiteName, signame, suite->result.errmsg ? suite->result.errmsg : "");
        }
        cx_delete(suite);
    }
/* $end */
}
