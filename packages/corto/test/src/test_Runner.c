/* $CORTO_GENERATED
 *
 * test_Runner.c
 *
 * Only code written between the begin and end tags will be preserved
 * when the file is regenerated.
 */

#include "test.h"

/* $header() */
void test_updateProgress(test_Runner this) {
    int i;
    char *str;
    corto_asprintf(&str, "%s: OK:%d, FAIL:%d", 
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

corto_int16 _test_Runner_construct(test_Runner this) {
/* $begin(::corto::test::Runner::construct) */
    /* If a testcase is provided, run it. Otherwise, discover testcases and
     * forward to separate process. */
    if (this->testcase) {
        corto_object testcase = corto_resolve(NULL, this->testcase);
        if (testcase) {
            corto_type testClass = corto_parentof(testcase);
            test_SuiteData suite = test_SuiteData(corto_declare(testClass));
            corto_setref(&suite->test, testcase);

            if (corto_define(suite)) {
                corto_error("test: failed to define test suite");
                test_CaseListAppend(this->failures, testcase);
            } else {
                corto_object prev = corto_setOwner(this);
                corto_define(suite);
                corto_setOwner(prev);            
            }

            corto_delete(suite);
        } else {
            corto_error("test: testcase '%s' not found", this->testcase);
            goto error;
        }
    } else {
        corto_listen(this, test_Runner_runTest_o, CORTO_ON_DEFINE | CORTO_ON_TREE | CORTO_ON_SELF, root_o, NULL);
    }
    return 0;
error:
    return -1;
/* $end */
}

corto_void _test_Runner_destruct(test_Runner this) {
/* $begin(::corto::test::Runner::destruct) */
    if (!this->testcase) {
        test_updateProgress(this);
        printf("\n");
    }
/* $end */
}

corto_void _test_Runner_runTest(test_Runner this, corto_object observable) {
/* $begin(::corto::test::Runner::runTest) */

    if (corto_instanceof(corto_type(test_Case_o), observable)) {
        corto_id testcaseId;
        corto_int8 err, ret;

        corto_pid pid = corto_procrun("corto", (char*[]){"corto", "--mute", this->lib, corto_fullname(observable, testcaseId), NULL});
        if ((err = corto_procwait(pid, &ret)) || ret) {
            if (err > 0) {
                int i;
                for (i = 0; i < 255; i++) {
                    fprintf(stderr, "\b");
                }
                corto_error("FAIL: %s: test crashed with signal %d", testcaseId, err);
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
