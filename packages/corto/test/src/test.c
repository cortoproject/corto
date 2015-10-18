/* test.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#include "test.h"

/* $header() */
cx_threadKey test_suiteKey;
/* $end */

/* ::corto::test::assert(bool condition,string $condition,uint32 $__line) */
cx_bool _test_assert(cx_bool condition, cx_string str_condition, cx_uint32 __line) {
/* $begin(::corto::test::assert) */
    test_SuiteData this = cx_threadTlsGet(test_suiteKey);
    if (!this) {
        cx_error("test: test::fail called but no testsuite is running!");
        abort();
    }
    this->assertCount++;

	if (!condition) {
        char *assertMsg = NULL;
        cx_asprintf(&assertMsg, "%d: assert(%s)", __line, str_condition);
		test_fail(assertMsg);
        cx_dealloc(assertMsg);
	}

    return !condition;
/* $end */
}

/* ::corto::test::assertEqual(any a,any b,string $a,string $b,uint32 $__line) */
cx_bool _test_assertEqual(cx_any a, cx_any b, cx_string str_a, cx_string str_b, cx_uint32 __line) {
/* $begin(::corto::test::assertEqual) */
    cx_equalityKind eq;
    char *assertMsg = NULL;
    test_SuiteData this = cx_threadTlsGet(test_suiteKey);
    if (!this) {
        cx_error("test: test::fail called but no testsuite is running!");
        abort();
    }
    this->assertCount++;

    eq = cx_type_compare(a, b);
    if (eq != CX_EQ) {
        cx_asprintf(&assertMsg, "%d: assert(%s == %s)", __line, str_a, str_b);
        test_fail(assertMsg);
        cx_dealloc(assertMsg);
    }

    return (eq != CX_EQ);
/* $end */
}

/* ::corto::test::fail(string err) */
cx_void _test_fail(cx_string err) {
/* $begin(::corto::test::fail) */
    cx_id id;
    int i;
	test_SuiteData this = cx_threadTlsGet(test_suiteKey);
	if (!this) {
		cx_error("test: test::fail called but no testsuite is running!");
		abort();
	}
    if (this->result.success) {
        this->result.errmsg = cx_strdup(err);
        this->result.success = FALSE;
    }
    
    for (i = 0; i < 255; i++) {
        fprintf(stderr, "\b");
    }

    cx_error("FAIL: %s:%s", 
        cx_fullname(this->test, id),
        this->result.errmsg ? this->result.errmsg : "");

    cx_string lasterr = cx_lasterr();
    if (lasterr) {
        cx_error("   details: %s", lasterr);
    }

    exit(-1);
/* $end */
}

int testMain(int argc, char* argv[]) {
/* $begin(main) */
	CX_UNUSED(argc);
	CX_UNUSED(argv);
    if (cx_threadTlsKey(&test_suiteKey, NULL)) {
        return -1;
    }
    return 0;
/* $end */
}
