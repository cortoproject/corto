/* test_TestCase.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "test.h"

/* $header() */

static cx_void test_TestCase_test(test_TestCase _this, cx_bool b, cx_string assertmsg, cx_string errmsg) {
    if (!b) {
        _this->result.assertmsg = cx_strdup(assertmsg);
        if (errmsg) {
            _this->result.errmsg = cx_strdup(errmsg);
        } else {
            _this->result.errmsg = NULL;
        }
        _this->result.success = FALSE;
    }
}

/* $end */

/* ::cortex::test::TestCase::assert(bool b) */
cx_void test_TestCase_assert_bool(test_TestCase _this, cx_bool b) {
/* $begin(::cortex::test::TestCase::assert(bool b)) */
    test_TestCase_assert_bool_string(_this, b, NULL);
/* $end */
}

/* ::cortex::test::TestCase::assert(bool b,string errmsg) */
cx_void test_TestCase_assert_bool_string(test_TestCase _this, cx_bool b, cx_string errmsg) {
/* $begin(::cortex::test::TestCase::assert(bool b,string errmsg)) */
    test_TestCase_test(_this, b, "Not true", errmsg);
/* $end */
}

/* ::cortex::test::TestCase::assertEqual(any a,any b) */
cx_void test_TestCase_assertEqual_any_any(test_TestCase _this, cx_any a, cx_any b) {
/* $begin(::cortex::test::TestCase::assertEqual(any a,any b)) */
    test_TestCase_assertEqual_any_any_string(_this, a, b, NULL);
/* $end */
}

/* ::cortex::test::TestCase::assertEqual(any a,any b,string errmsg) */
cx_void test_TestCase_assertEqual_any_any_string(test_TestCase _this, cx_any a, cx_any b, cx_string errmsg) {
/* $begin(::cortex::test::TestCase::assertEqual(any a,any b,string errmsg)) */
    cx_equalityKind eq;
    cx_value aV, bV;
    cx_string aS, bS;
    char *assertmsg;
    int length;
    eq = cx_type_compare(a, b);
    cx_valueValueInit(&aV, NULL, a.type, a.value);
    cx_valueValueInit(&bV, NULL, b.type, b.value);
    aS = cx_valueToString(&aV, 0);
    bS = cx_valueToString(&bV, 0);
    length = snprintf(NULL, 0, "%s != %s", aS, bS);
    if (length < 0) {
        cx_critical("error in snprintf");
    }
    assertmsg = cx_malloc(length + 1);
    sprintf(assertmsg, "%s != %s", aS, bS);
    test_TestCase_test(_this, eq == CX_EQ, assertmsg, errmsg);
    cx_dealloc(assertmsg);
/* $end */
}

/* ::cortex::test::TestCase::construct() */
cx_int16 test_TestCase_construct(test_TestCase _this) {
/* $begin(::cortex::test::TestCase::construct) */
    if (_this->test) {
        test_TestCase_setUp(_this);
        _this->result.success = TRUE;
        cx_call(cx_function(_this->test), NULL, _this);
        test_TestCase_tearDown(_this);
    } else {
        _this->result.success = FALSE;
    }
    return !_this->result.success;
/* $end */
}

/* ::cortex::test::TestCase::setUp() */
cx_void test_TestCase_setUp_v(test_TestCase _this) {
/* $begin(::cortex::test::TestCase::setUp) */
    CX_UNUSED(_this);
/* $end */
}

/* ::cortex::test::TestCase::tearDown() */
cx_void test_TestCase_tearDown_v(test_TestCase _this) {
/* $begin(::cortex::test::TestCase::tearDown) */
    CX_UNUSED(_this);
/* $end */
}
