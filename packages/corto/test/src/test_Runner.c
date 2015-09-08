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
cx_int16 _test_Runner_construct(test_Runner this) {
/* $begin(::corto::test::Runner::construct) */
    /* If a testcase is provided, run it. Otherwise, discover testcases and
     * forward to separate process. */
    if (this->testcase) {
        cx_object testcase = cx_resolve(NULL, this->testcase);
        if (testcase) {
            cx_type testClass = cx_parentof(testcase);
            test_Suite suite = test_Suite(cx_declare(testClass));
            cx_setref(&suite->test, testcase);

            if (cx_define(suite)) {
                cx_error("test: failed to define test suite");
                test_CaseListAppend(this->failures, testcase);
            } else {
                cx_object prev = cx_setSource(this);
                if (!cx_define(suite) && suite->result.success) {
                    test_CaseListAppend(this->successes, testcase);
                } else {
                    test_CaseListAppend(this->failures, testcase);
                }
                cx_setSource(prev);            
            }

            cx_string suiteName = cx_nameof(testClass);
            cx_string testName = cx_nameof(testcase);

            if (!suite->result.success) {
                cx_id signame; cx_signatureName(testName, signame);
                cx_error("FAIL: %s::%s:%s", suiteName, signame, suite->result.errmsg ? suite->result.errmsg : "");
                cx_delete(suite);
                goto error;
            }
            cx_delete(suite);
        } else {
            cx_error("test: testcase '%s' not found", this->testcase);
            goto error;
        }
    } else {
        test_Runner_runTest_o->mask = CX_ON_DEFINE | CX_ON_TREE | CX_ON_SELF;
        cx_listen(root_o, test_Runner_runTest_o, this);
    }
    return 0;
error:
    return -1;
/* $end */
}

/* ::corto::test::Runner::destruct() */
cx_void _test_Runner_destruct(test_Runner this) {
/* $begin(::corto::test::Runner::destruct) */
    if (!this->testcase) {
        cx_uint32 successCount = test_CaseListSize(this->successes);
        cx_uint32 failureCount = test_CaseListSize(this->failures);
        cx_print("%s: OK:%d, FAIL:%d", this->name, successCount, failureCount);
    }
/* $end */
}

/* ::corto::test::Runner::runTest() */
cx_void _test_Runner_runTest(test_Runner this, cx_object observable, cx_object source) {
/* $begin(::corto::test::Runner::runTest) */
    CX_UNUSED(source);

    if (cx_instanceof(cx_type(test_Case_o), observable)) {
        cx_id testcaseId;
        cx_int8 err, ret;

        cx_pid pid = cx_procrun("corto", (char*[]){"corto", "--mute", this->lib, cx_fullname(observable, testcaseId), NULL});
        if ((err = cx_procwait(pid, &ret)) || ret) {
            if (err > 0) {
                cx_error("FAIL: %s: test crashed with signal %d", testcaseId, err);
            } else {
                /* Process exited with a returncode != 0, and must've printed an error msg itself */
            }
            test_CaseListAppend(this->failures, observable);
        } else {
            test_CaseListAppend(this->successes, observable);
        }
    }
/* $end */
}
