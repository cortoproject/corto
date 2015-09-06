/* test.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#define corto_test_LIB
#include "test.h"

/* $header() */
cx_threadKey test_suiteKey;
/* $end */

/* ::corto::test::assert(bool condition,string $condition) */
cx_void _test_assert(cx_bool condition, cx_string str_condition) {
/* $begin(::corto::test::assert) */
	if (!condition) {
        char *assertMsg = NULL;
        cx_asprintf(&assertMsg, "assert(%s)", str_condition);
		test_fail(assertMsg);
        cx_dealloc(assertMsg);
	}
/* $end */
}

/* ::corto::test::assertEqual(any a,any b,string $a,string $b) */
cx_void _test_assertEqual(cx_any a, cx_any b, cx_string str_a, cx_string str_b) {
/* $begin(::corto::test::assertEqual) */
    cx_equalityKind eq;
    char *assertMsg = NULL;

    eq = cx_type_compare(a, b);
    if (eq != CX_EQ) {
        cx_asprintf(&assertMsg, "assert(%s == %s)", str_a, str_b);
        test_fail(assertMsg);
        cx_dealloc(assertMsg);
    }
/* $end */
}

/* ::corto::test::fail(string err) */
cx_void _test_fail(cx_string err) {
/* $begin(::corto::test::fail) */
	test_Suite _this = cx_threadTlsGet(test_suiteKey);
	if (!_this) {
		cx_error("test: test::fail called but no testsuite is running!");
		abort();
	}
    if (_this->result.success) {
        _this->result.errmsg = cx_strdup(err);
        _this->result.success = FALSE;
    }
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
