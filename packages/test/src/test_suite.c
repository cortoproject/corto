/* test_suite.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "test.h"
#include "test__meta.h"

/* ::cortex::test::suite::assert(::cortex::lang::any v1,::cortex::lang::any v2,::cortex::lang::string msg) */
cx_void test_suite_assert__cortex_lang_any__cortex_lang_any__cortex_lang_string(test_suite _this, cx_any v1, cx_any v2, cx_string msg) {
/* $begin(::cortex::test::suite::assert(::cortex::lang::any v1,::cortex::lang::any v2,::cortex::lang::string msg)) */

    if (cx_type_compare(v1, v2) != CX_EQ) {
        test_suite_fail(_this, msg);
    }

/* $end */
}

/* ::cortex::test::suite::assert(::cortex::lang::bool cond,::cortex::lang::string msg) */
cx_void test_suite_assert__cortex_lang_bool__cortex_lang_string(test_suite _this, cx_bool cond, cx_string msg) {
/* $begin(::cortex::test::suite::assert(::cortex::lang::bool cond,::cortex::lang::string msg)) */
    if (!cond) {
        test_suite_fail(_this, msg);
    }
/* $end */
}

/* callback ::cortex::lang::class::construct(lang::object object) -> ::cortex::test::suite::construct(::cortex::test::suite object) */
/* $header(::cortex::test::suite::construct) */
int test_suite_walk(cx_object o, void *userData) {
    test_suite _this = userData;

    /* Run procedures in scope of suite */
    if (cx_instanceof(cx_typedef(test_test_o), o)) {
        cx_id id;

        /* Create unit for procedure */
        cx_signatureName(cx_nameof(o), id);
        test_unit unit = test_unit__declare(_this->result, id);
        test_unit__define(unit);
        cx_set(&_this->unit, unit); /* Set current unit under test to this unit */

        /* Run procedure */
        cx_call(cx_function(o), NULL);
    }

    return 1;
}

cx_object test_suite_createResultTree(test_suite _this, cx_object object) {
    cx_object result = NULL;
    if (cx_parentof(object) != root_o) {
        result = test_suite_createResultTree(_this, cx_parentof(object));
        result = cx_declare(result, cx_nameof(object), cx_typeof(cx_void_o));
    } else {
        result = cx_declare(NULL, "test", cx_typedef(cx_void_o));
        result = cx_declare(result, cx_nameof(object), cx_typedef(cx_void_o));
    }
    return result;
}

/* $end */
cx_int16 test_suite_construct(test_suite object) {
/* $begin(::cortex::test::suite::construct) */

    if (!object->package) {
        cx_error("no package provided for testsuite");
        goto error;
    }

    object->success = TRUE;

    /* Recursively recreate scope of package in results root */
    cx_set(&object->result, test_suite_createResultTree(object, object->package));

    /* Walk scope of suite */
    cx_scopeWalk(object, test_suite_walk, object);

    return 0;
error:
    return -1;
/* $end */
}

/* ::cortex::test::suite::fail(::cortex::lang::string msg) */
cx_void test_suite_fail(test_suite _this, cx_string msg) {
/* $begin(::cortex::test::suite::fail) */

    if (_this->unit) {
        if (!_this->silent) {
            cx_id id;
            printf("%s: FAIL: %s\n", cx_fullname(_this->unit, id), msg);
        }
        test_unit_fail(_this->unit, msg);
        _this->success = FALSE;
    }

/* $end */
}
