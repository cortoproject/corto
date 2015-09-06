/* test_Suite.c
 *
 * This file contains the implementation for the generated interface.
 *
 * Don't mess with the begin and end tags, since these will ensure that modified
 * code in interface functions isn't replaced when code is re-generated.
 */

#define corto_test_LIB
#include "test.h"

/* $header() */

/*
 * Returns 0 if the condition was successful
 */
static cx_bool test_Suite_test(test_Suite _this, cx_bool b, cx_string assertmsg, cx_string errmsg) {
    if (_this->result.success && !b) {
        _this->result.assertmsg = cx_strdup(assertmsg);
        if (errmsg) {
            _this->result.errmsg = cx_strdup(errmsg);
        } else {
            _this->result.errmsg = NULL;
        }
        _this->result.success = FALSE;
    }
    return !b;
}

/* $end */

/* ::corto::test::Suite::assert(bool b) */
cx_bool _test_Suite_assert_bool(test_Suite _this, cx_bool b) {
/* $begin(::corto::test::Suite::assert(bool b)) */
    return test_Suite_assert_bool_string(_this, b, NULL);
/* $end */
}

/* ::corto::test::Suite::assert(bool b,string errmsg) */
cx_bool _test_Suite_assert_bool_string(test_Suite _this, cx_bool b, cx_string errmsg) {
/* $begin(::corto::test::Suite::assert(bool b,string errmsg)) */
    return test_Suite_test(_this, b, "Not true", errmsg);
/* $end */
}

/* ::corto::test::Suite::assertEqual(any a,any b) */
cx_bool _test_Suite_assertEqual_any_any(test_Suite _this, cx_any a, cx_any b) {
/* $begin(::corto::test::Suite::assertEqual(any a,any b)) */
    return test_Suite_assertEqual_any_any_string(_this, a, b, NULL);
/* $end */
}

/* ::corto::test::Suite::assertEqual(any a,any b,string errmsg) */
cx_bool _test_Suite_assertEqual_any_any_string(test_Suite _this, cx_any a, cx_any b, cx_string errmsg) {
/* $begin(::corto::test::Suite::assertEqual(any a,any b,string errmsg)) */
    cx_bool result;
    cx_equalityKind eq;
    cx_value aV, bV;
    cx_string aS, bS;
    char *assertmsg;
    int length;
    eq = cx_type_compare(a, b);
    cx_valueValueInit(&aV, NULL, a.type, a.value);
    cx_valueValueInit(&bV, NULL, b.type, b.value);
    aS = cx_strv(&aV, 0);
    bS = cx_strv(&bV, 0);
    length = snprintf(NULL, 0, "%s != %s", aS, bS);
    if (length < 0) {
        cx_critical("error in snprintf");
    }
    assertmsg = cx_alloc(length + 1);
    sprintf(assertmsg, "%s != %s", aS, bS);
    result = test_Suite_test(_this, eq == CX_EQ, assertmsg, errmsg);
    cx_dealloc(assertmsg);
    return result;
/* $end */
}

/* ::corto::test::Suite::construct() */
cx_int16 _test_Suite_construct(test_Suite _this) {
/* $begin(::corto::test::Suite::construct) */
    if (_this->test) {
        _this->result.success = TRUE;
        cx_call(cx_function(_this->test), NULL, _this);
    } else {
        goto error;
    }
    return 0;
error:
    return -1;
/* $end */
}

/* ::corto::test::Suite::setup() */
cx_void _test_Suite_setup_v(test_Suite _this) {
/* $begin(::corto::test::Suite::setup) */
    CX_UNUSED(_this);
/* $end */
}

/* ::corto::test::Suite::teardown() */
cx_void _test_Suite_teardown_v(test_Suite _this) {
/* $begin(::corto::test::Suite::teardown) */
    CX_UNUSED(_this);
/* $end */
}
