/* test_Runner.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "test.h"

/* $header() */
void test_updateProgress(test_Runner this) {
    int i;
    char *str;
    cx_asprintf(&str, "%s: OK:%d, FAIL:%d", 
        this->name, 
        test_CaseListSize(this->successes),
        test_CaseListSize(this->failures));

    for (i = 0; i < strlen(str) + 2 * 2; i++) {
        printf("\b");
    }

    printf("%s", str);
    fflush(stdout);
}
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
            test_SuiteData suite = test_SuiteData(cx_declare(testClass));
            cx_setref(&suite->test, testcase);

            if (cx_define(suite)) {
                cx_error("test: failed to define test suite");
                test_CaseListAppend(this->failures, testcase);
            } else {
                cx_object prev = cx_setOwner(this);
                cx_define(suite);
                cx_setOwner(prev);            
            }

            cx_delete(suite);
        } else {
            cx_error("test: testcase '%s' not found", this->testcase);
            goto error;
        }
    } else {
        cx_listen(this, test_Runner_runTest_o, CX_ON_DEFINE | CX_ON_TREE | CX_ON_SELF, root_o, NULL);
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
        test_updateProgress(this);
        printf("\n");
    }
/* $end */
}

/* ::corto::test::Runner::runTest() */
cx_void _test_Runner_runTest(test_Runner this, cx_object observable) {
/* $begin(::corto::test::Runner::runTest) */

    if (cx_instanceof(cx_type(test_Case_o), observable)) {
        cx_id testcaseId;
        cx_int8 err, ret;

        cx_pid pid = cx_procrun("corto", (char*[]){"corto", "--mute", this->lib, cx_fullname(observable, testcaseId), NULL});
        if ((err = cx_procwait(pid, &ret)) || ret) {
            if (err > 0) {
                int i;
                for (i = 0; i < 255; i++) {
                    fprintf(stderr, "\b");
                }
                cx_error("FAIL: %s: test crashed with signal %d", testcaseId, err);
            } else {
                /* Process exited with a returncode != 0, and must've printed an error msg itself */
            }
            test_CaseListAppend(this->failures, observable);
        } else {
            test_CaseListAppend(this->successes, observable);
        }
        this->testsRun++;
        if (!(this->testsRun % 8)) {
            test_updateProgress(this);
        }
    }
/* $end */
}
