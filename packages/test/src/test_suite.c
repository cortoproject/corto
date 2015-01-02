/* test_suite.c
 *
 * This file contains the implementation for the generated interface.
 *
 *    Don't mess with the begin and end tags, since these will ensure that modified
 *    code in interface functions isn't replaced when code is re-generated.
 */

#include "test.h"
#include "test__meta.h"

/* callback ::cortex::lang::class::construct(lang::object object) -> ::cortex::test::suite::construct(::cortex::test::suite object) */
/* $header(::cortex::test::suite::construct) */
int test_suite_walk(cx_object o, void *userData) {
    test_suite _this = userData;

    /* Run procedures in scope of suite */
    if ((cx_typeof(o)->real->kind == CX_COMPOSITE) && (cx_interface(cx_typeof(o)->real)->kind == CX_PROCEDURE)) {
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
    test_result result = NULL;
    if (cx_parentof(object) != root_o) {
        result = test_suite_createResultTree(_this, cx_parentof(object));
        result = test_result__declare(result, cx_nameof(object));
        test_result__define(result, object);
    } else {
        result = cx_declare(NULL, "test", cx_typedef(cx_void_o));
        result = test_result__declare(result, cx_nameof(object));
        test_result__define(result, _this->package);
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
