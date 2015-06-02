/* test_TestRunner.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "test.h"

/* $header() */

static int test_TestRunner_walkTestCaseScopeAction(cx_object o, void *data) {
    test_TestRunner _this = data;
    if (cx_instanceof(cx_type(test_test_o), o)) {
        test_test testMethod = o;

        /* Create with dynamic type */
        test_TestCase run;
        cx_type testClass = cx_parentof(testMethod);
        run = test_TestCase(cx_new(cx_type(testClass)));
        cx_keep_ext(run, testMethod, "element <0x7fd64355b778>.test"); /* TODO What is context? */
        run->test = test_test(testMethod);
        if (cx_define(run)) { /* base type constructor not called */
            test_TestCase_list__insert(_this->failures, run);
        } else {
            if (run->result.success) {
                test_TestCase_list__insert(_this->successes, run);
            } else {
                test_TestCase_list__insert(_this->failures, run);
            }
        }
        test_TestRunner_printTestRun(_this, run);
        cx_free(run);
        run = NULL;
    }
    return 1;
}

/* $end */

/* ::cortex::test::TestRunner::construct() */
cx_int16 test_TestRunner_construct(test_TestRunner _this) {
/* $begin(::cortex::test::TestRunner::construct) */
    test_TestRunner_runTest_o->mask = CX_ON_DECLARE | CX_ON_DEFINE | CX_ON_SCOPE | CX_ON_SELF;
    cx_listen(root_o, test_TestRunner_runTest_o, _this);
    return 0;
/* $end */
}

/* ::cortex::test::TestRunner::destruct() */
cx_void test_TestRunner_destruct(test_TestRunner _this) {
/* $begin(::cortex::test::TestRunner::destruct) */
    static char *successes[] = {"successes", "success"};
    static char *failures[] = {"failures", "failure"};
    cx_uint32 successCount = test_TestCase_list__size(_this->successes);
    cx_uint32 failureCount = test_TestCase_list__size(_this->failures);
    char *success = successes[successCount == 1 ? 1 : 0];
    char *failure = failures[failureCount == 1 ? 1 : 0];
    cx_print("%d %s, %d %s", successCount, success, failureCount, failure);
/* $end */
}

/* ::cortex::test::TestRunner::printTestRun(TestCase t) */
cx_void test_TestRunner_printTestRun_v(test_TestRunner _this, test_TestCase t) {
/* $begin(::cortex::test::TestRunner::printTestRun) */
    CX_UNUSED(_this);

    cx_string testName = cx_nameof(t->test);
    if (t->result.success) {
        cx_print("%s: success", testName);
    } else {
        cx_assert(t->result.assertmsg != NULL, "null assert message");
        cx_print("%s: failure: %s", testName, t->result.assertmsg);
        if (t->result.errmsg && *(t->result.errmsg) != '\0') {
            cx_print("    message: %s", t->result.errmsg);
        }
    }
/* $end */
}

/* ::cortex::test::TestRunner::runTest() */
cx_void test_TestRunner_runTest(test_TestRunner _this, cx_object *observable, cx_object *source) {
/* $begin(::cortex::test::TestRunner::runTest) */
    CX_UNUSED(_this);
    CX_UNUSED(source);
    if (cx_typeof(observable) == cx_type(cx_class_o)
            && cx_interface_baseof(cx_interface(observable), cx_interface(test_TestCase_o))) {
        if (cx_checkState(observable, CX_DEFINED)) {
            cx_scopeWalk(observable, test_TestRunner_walkTestCaseScopeAction, _this);
        }
    }
/* $end */
}
