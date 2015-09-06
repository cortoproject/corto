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
    cx_print("%s: %d OK, %d FAIL", _this->name, successCount, failureCount);
/* $end */
}

/* ::corto::test::Runner::printTestRun(::corto::test::Suite t) */
cx_void _test_Runner_printTestRun_v(test_Runner _this, test_Suite t) {
/* $begin(::corto::test::Runner::printTestRun) */
    CX_UNUSED(_this);
    cx_string suiteName = cx_nameof(cx_typeof(t));
    cx_string testName = cx_nameof(t->test);
    if (!t->result.success) {
        cx_id signame; cx_signatureName(testName, signame);
        cx_error("FAIL: %s.%s: %s", suiteName, signame, t->result.errmsg);
    }
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
        cx_object prev = cx_setSource(_this);
        if (!cx_define(suite) && suite->result.success) {
            test_SuiteListAppend(_this->successes, suite);
        } else {
            test_SuiteListAppend(_this->failures, suite);
        }
        cx_setSource(prev);
        test_Runner_printTestRun(_this, suite);
        cx_release(suite);
    }
/* $end */
}
