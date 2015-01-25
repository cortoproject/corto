/* test__meta.c
 *
 * Loads objects in database.
 * This file contains generated code. Do not modify!
 */

#include "test__type.h"

/* Variable definitions */
cx_object _o;
cx_void (*test_o);
cx_class test_suite_o;
cx_method test_suite_assert_any_any_string_o;
cx_method test_suite_assert_bool_string_o;
cx_method test_suite_construct_o;
cx_method test_suite_fail_o;
cx_member test_suite_package_o;
cx_member test_suite_result_o;
cx_member test_suite_silent_o;
cx_member test_suite_success_o;
cx_member test_suite_unit_o;
cx_procedure test_test_o;
cx_class test_unit_o;
cx_method test_unit_construct_o;
cx_method test_unit_fail_o;
cx_member test_unit_failmsg_o;
cx_member test_unit_success_o;

/* Load objects in database */
int test_load(void) {
    cx_object _a_; /* Used for resolving anonymous objects */
    _a_ = NULL;

    /* Declare ::cortex */
    _o = cx_declare(root_o, "cortex", cx_type(cx_object_o));
    if (!_o) {
        cx_error("test_load: failed to declare object '::cortex'.");
        goto error;
    }

    /* Define ::cortex */
    if (!cx_checkState(_o, CX_DEFINED)) {
        if (cx_define(_o)) {
            cx_error("test_load: failed to define object '::cortex'.");
            goto error;
        }
    }

    /* Declare ::cortex::test */
    test_o = cx_declare(_o, "test", cx_type(cx_void_o));
    if (!test_o) {
        cx_error("test_load: failed to declare object '::cortex::test'.");
        goto error;
    }

    /* Declare ::cortex::test::suite */
    test_suite_o = cx_declare(test_o, "suite", cx_type(cx_class_o));
    if (!test_suite_o) {
        cx_error("test_load: failed to declare object '::cortex::test::suite'.");
        goto error;
    }

    /* Declare ::cortex::test::suite::assert(any v1,any v2,string msg) */
    test_suite_assert_any_any_string_o = cx_declare(test_suite_o, "assert(any v1,any v2,string msg)", cx_type(cx_method_o));
    if (!test_suite_assert_any_any_string_o) {
        cx_error("test_load: failed to declare object '::cortex::test::suite::assert(any v1,any v2,string msg)'.");
        goto error;
    }

    /* Define ::cortex::test::suite::assert(any v1,any v2,string msg) */
    if (!cx_checkState(test_suite_assert_any_any_string_o, CX_DEFINED)) {
        cx_function(test_suite_assert_any_any_string_o)->returnType = cx_resolve_ext(test_suite_assert_any_any_string_o, NULL, "::cortex::lang::void", FALSE, "element ::cortex::test::suite::assert(any v1,any v2,string msg).returnType");
        cx_function(test_suite_assert_any_any_string_o)->returnsReference = FALSE;
        test_suite_assert_any_any_string_o->virtual = FALSE;
        
        /* Bind ::cortex::test::suite::assert(any v1,any v2,string msg) with C-function */
        cx_function(test_suite_assert_any_any_string_o)->kind = CX_PROCEDURE_CDECL;
        void __test_suite_assert_any_any_string(void *args, void *result);
        cx_function(test_suite_assert_any_any_string_o)->impl = (cx_word)__test_suite_assert_any_any_string;
        if (cx_define(test_suite_assert_any_any_string_o)) {
            cx_error("test_load: failed to define object '::cortex::test::suite::assert(any v1,any v2,string msg)'.");
            goto error;
        }
    }

    /* Declare ::cortex::test::suite::assert(bool cond,string msg) */
    test_suite_assert_bool_string_o = cx_declare(test_suite_o, "assert(bool cond,string msg)", cx_type(cx_method_o));
    if (!test_suite_assert_bool_string_o) {
        cx_error("test_load: failed to declare object '::cortex::test::suite::assert(bool cond,string msg)'.");
        goto error;
    }

    /* Define ::cortex::test::suite::assert(bool cond,string msg) */
    if (!cx_checkState(test_suite_assert_bool_string_o, CX_DEFINED)) {
        cx_function(test_suite_assert_bool_string_o)->returnType = cx_resolve_ext(test_suite_assert_bool_string_o, NULL, "::cortex::lang::void", FALSE, "element ::cortex::test::suite::assert(bool cond,string msg).returnType");
        cx_function(test_suite_assert_bool_string_o)->returnsReference = FALSE;
        test_suite_assert_bool_string_o->virtual = FALSE;
        
        /* Bind ::cortex::test::suite::assert(bool cond,string msg) with C-function */
        cx_function(test_suite_assert_bool_string_o)->kind = CX_PROCEDURE_CDECL;
        void __test_suite_assert_bool_string(void *args, void *result);
        cx_function(test_suite_assert_bool_string_o)->impl = (cx_word)__test_suite_assert_bool_string;
        if (cx_define(test_suite_assert_bool_string_o)) {
            cx_error("test_load: failed to define object '::cortex::test::suite::assert(bool cond,string msg)'.");
            goto error;
        }
    }

    /* Declare ::cortex::test::suite::construct() */
    test_suite_construct_o = cx_declare(test_suite_o, "construct()", cx_type(cx_method_o));
    if (!test_suite_construct_o) {
        cx_error("test_load: failed to declare object '::cortex::test::suite::construct()'.");
        goto error;
    }

    /* Define ::cortex::test::suite::construct() */
    if (!cx_checkState(test_suite_construct_o, CX_DEFINED)) {
        cx_function(test_suite_construct_o)->returnType = cx_resolve_ext(test_suite_construct_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::test::suite::construct().returnType");
        cx_function(test_suite_construct_o)->returnsReference = FALSE;
        test_suite_construct_o->virtual = FALSE;
        
        /* Bind ::cortex::test::suite::construct() with C-function */
        cx_function(test_suite_construct_o)->kind = CX_PROCEDURE_CDECL;
        void __test_suite_construct(void *args, void *result);
        cx_function(test_suite_construct_o)->impl = (cx_word)__test_suite_construct;
        if (cx_define(test_suite_construct_o)) {
            cx_error("test_load: failed to define object '::cortex::test::suite::construct()'.");
            goto error;
        }
    }

    /* Declare ::cortex::test::suite::fail(string msg) */
    test_suite_fail_o = cx_declare(test_suite_o, "fail(string msg)", cx_type(cx_method_o));
    if (!test_suite_fail_o) {
        cx_error("test_load: failed to declare object '::cortex::test::suite::fail(string msg)'.");
        goto error;
    }

    /* Define ::cortex::test::suite::fail(string msg) */
    if (!cx_checkState(test_suite_fail_o, CX_DEFINED)) {
        cx_function(test_suite_fail_o)->returnType = cx_resolve_ext(test_suite_fail_o, NULL, "::cortex::lang::void", FALSE, "element ::cortex::test::suite::fail(string msg).returnType");
        cx_function(test_suite_fail_o)->returnsReference = FALSE;
        test_suite_fail_o->virtual = FALSE;
        
        /* Bind ::cortex::test::suite::fail(string msg) with C-function */
        cx_function(test_suite_fail_o)->kind = CX_PROCEDURE_CDECL;
        void __test_suite_fail(void *args, void *result);
        cx_function(test_suite_fail_o)->impl = (cx_word)__test_suite_fail;
        if (cx_define(test_suite_fail_o)) {
            cx_error("test_load: failed to define object '::cortex::test::suite::fail(string msg)'.");
            goto error;
        }
    }

    /* Declare ::cortex::test::suite::package */
    test_suite_package_o = cx_declare(test_suite_o, "package", cx_type(cx_member_o));
    if (!test_suite_package_o) {
        cx_error("test_load: failed to declare object '::cortex::test::suite::package'.");
        goto error;
    }

    /* Define ::cortex::test::suite::package */
    if (!cx_checkState(test_suite_package_o, CX_DEFINED)) {
        test_suite_package_o->type = cx_resolve_ext(test_suite_package_o, NULL, "::cortex::lang::object", FALSE, "element ::cortex::test::suite::package.type");
        test_suite_package_o->modifiers = 0x0;
        test_suite_package_o->state = 0x6;
        test_suite_package_o->weak = FALSE;
        test_suite_package_o->id = 0;
        if (cx_define(test_suite_package_o)) {
            cx_error("test_load: failed to define object '::cortex::test::suite::package'.");
            goto error;
        }
    }

    /* Declare ::cortex::test::suite::result */
    test_suite_result_o = cx_declare(test_suite_o, "result", cx_type(cx_member_o));
    if (!test_suite_result_o) {
        cx_error("test_load: failed to declare object '::cortex::test::suite::result'.");
        goto error;
    }

    /* Define ::cortex::test::suite::result */
    if (!cx_checkState(test_suite_result_o, CX_DEFINED)) {
        test_suite_result_o->type = cx_resolve_ext(test_suite_result_o, NULL, "::cortex::lang::object", FALSE, "element ::cortex::test::suite::result.type");
        test_suite_result_o->modifiers = 0x3;
        test_suite_result_o->state = 0x6;
        test_suite_result_o->weak = FALSE;
        test_suite_result_o->id = 4;
        if (cx_define(test_suite_result_o)) {
            cx_error("test_load: failed to define object '::cortex::test::suite::result'.");
            goto error;
        }
    }

    /* Declare ::cortex::test::suite::silent */
    test_suite_silent_o = cx_declare(test_suite_o, "silent", cx_type(cx_member_o));
    if (!test_suite_silent_o) {
        cx_error("test_load: failed to declare object '::cortex::test::suite::silent'.");
        goto error;
    }

    /* Define ::cortex::test::suite::silent */
    if (!cx_checkState(test_suite_silent_o, CX_DEFINED)) {
        test_suite_silent_o->type = cx_resolve_ext(test_suite_silent_o, NULL, "::cortex::lang::bool", FALSE, "element ::cortex::test::suite::silent.type");
        test_suite_silent_o->modifiers = 0x0;
        test_suite_silent_o->state = 0x6;
        test_suite_silent_o->weak = FALSE;
        test_suite_silent_o->id = 1;
        if (cx_define(test_suite_silent_o)) {
            cx_error("test_load: failed to define object '::cortex::test::suite::silent'.");
            goto error;
        }
    }

    /* Declare ::cortex::test::suite::success */
    test_suite_success_o = cx_declare(test_suite_o, "success", cx_type(cx_member_o));
    if (!test_suite_success_o) {
        cx_error("test_load: failed to declare object '::cortex::test::suite::success'.");
        goto error;
    }

    /* Define ::cortex::test::suite::success */
    if (!cx_checkState(test_suite_success_o, CX_DEFINED)) {
        test_suite_success_o->type = cx_resolve_ext(test_suite_success_o, NULL, "::cortex::lang::bool", FALSE, "element ::cortex::test::suite::success.type");
        test_suite_success_o->modifiers = 0x4;
        test_suite_success_o->state = 0x6;
        test_suite_success_o->weak = FALSE;
        test_suite_success_o->id = 2;
        if (cx_define(test_suite_success_o)) {
            cx_error("test_load: failed to define object '::cortex::test::suite::success'.");
            goto error;
        }
    }

    /* Declare ::cortex::test::suite::unit */
    test_suite_unit_o = cx_declare(test_suite_o, "unit", cx_type(cx_member_o));
    if (!test_suite_unit_o) {
        cx_error("test_load: failed to declare object '::cortex::test::suite::unit'.");
        goto error;
    }

    /* Declare ::cortex::test::test */
    test_test_o = cx_declare(test_o, "test", cx_type(cx_procedure_o));
    if (!test_test_o) {
        cx_error("test_load: failed to declare object '::cortex::test::test'.");
        goto error;
    }

    /* Define ::cortex::test::test */
    if (!cx_checkState(test_test_o, CX_DEFINED)) {
        cx_type(test_test_o)->defaultType = cx_resolve_ext(test_test_o, NULL, "::cortex::lang::member", FALSE, "element ::cortex::test::test.defaultType");
        cx_type(test_test_o)->parentType = NULL;
        cx_type(test_test_o)->parentState = 0x0;
        cx_interface(test_test_o)->base = cx_resolve_ext(test_test_o, NULL, "::cortex::lang::function", FALSE, "element ::cortex::test::test.base");
        cx_struct(test_test_o)->baseAccess = 0x0;
        test_test_o->kind = CX_FUNCTION;
        if (cx_define(test_test_o)) {
            cx_error("test_load: failed to define object '::cortex::test::test'.");
            goto error;
        }
    }

    if (cx_type(test_test_o)->size != sizeof(struct test_test_s)) {
        cx_error("test_load: calculated size '%d' of type '::cortex::test::test' doesn't match C-type size '%d'", cx_type(test_test_o)->size, sizeof(struct test_test_s));
    }

    /* Declare ::cortex::test::unit */
    test_unit_o = cx_declare(test_o, "unit", cx_type(cx_class_o));
    if (!test_unit_o) {
        cx_error("test_load: failed to declare object '::cortex::test::unit'.");
        goto error;
    }

    /* Declare ::cortex::test::unit::construct() */
    test_unit_construct_o = cx_declare(test_unit_o, "construct()", cx_type(cx_method_o));
    if (!test_unit_construct_o) {
        cx_error("test_load: failed to declare object '::cortex::test::unit::construct()'.");
        goto error;
    }

    /* Define ::cortex::test::unit::construct() */
    if (!cx_checkState(test_unit_construct_o, CX_DEFINED)) {
        cx_function(test_unit_construct_o)->returnType = cx_resolve_ext(test_unit_construct_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::test::unit::construct().returnType");
        cx_function(test_unit_construct_o)->returnsReference = FALSE;
        test_unit_construct_o->virtual = FALSE;
        
        /* Bind ::cortex::test::unit::construct() with C-function */
        cx_function(test_unit_construct_o)->kind = CX_PROCEDURE_CDECL;
        void __test_unit_construct(void *args, void *result);
        cx_function(test_unit_construct_o)->impl = (cx_word)__test_unit_construct;
        if (cx_define(test_unit_construct_o)) {
            cx_error("test_load: failed to define object '::cortex::test::unit::construct()'.");
            goto error;
        }
    }

    /* Declare ::cortex::test::unit::fail(string msg) */
    test_unit_fail_o = cx_declare(test_unit_o, "fail(string msg)", cx_type(cx_method_o));
    if (!test_unit_fail_o) {
        cx_error("test_load: failed to declare object '::cortex::test::unit::fail(string msg)'.");
        goto error;
    }

    /* Define ::cortex::test::unit::fail(string msg) */
    if (!cx_checkState(test_unit_fail_o, CX_DEFINED)) {
        cx_function(test_unit_fail_o)->returnType = cx_resolve_ext(test_unit_fail_o, NULL, "::cortex::lang::void", FALSE, "element ::cortex::test::unit::fail(string msg).returnType");
        cx_function(test_unit_fail_o)->returnsReference = FALSE;
        test_unit_fail_o->virtual = FALSE;
        
        /* Bind ::cortex::test::unit::fail(string msg) with C-function */
        cx_function(test_unit_fail_o)->kind = CX_PROCEDURE_CDECL;
        void __test_unit_fail(void *args, void *result);
        cx_function(test_unit_fail_o)->impl = (cx_word)__test_unit_fail;
        if (cx_define(test_unit_fail_o)) {
            cx_error("test_load: failed to define object '::cortex::test::unit::fail(string msg)'.");
            goto error;
        }
    }

    /* Declare ::cortex::test::unit::failmsg */
    test_unit_failmsg_o = cx_declare(test_unit_o, "failmsg", cx_type(cx_member_o));
    if (!test_unit_failmsg_o) {
        cx_error("test_load: failed to declare object '::cortex::test::unit::failmsg'.");
        goto error;
    }

    /* Define ::cortex::test::unit::failmsg */
    if (!cx_checkState(test_unit_failmsg_o, CX_DEFINED)) {
        test_unit_failmsg_o->type = cx_resolve_ext(test_unit_failmsg_o, NULL, "::cortex::lang::string", FALSE, "element ::cortex::test::unit::failmsg.type");
        test_unit_failmsg_o->modifiers = 0x4;
        test_unit_failmsg_o->state = 0x6;
        test_unit_failmsg_o->weak = FALSE;
        test_unit_failmsg_o->id = 1;
        if (cx_define(test_unit_failmsg_o)) {
            cx_error("test_load: failed to define object '::cortex::test::unit::failmsg'.");
            goto error;
        }
    }

    /* Declare ::cortex::test::unit::success */
    test_unit_success_o = cx_declare(test_unit_o, "success", cx_type(cx_member_o));
    if (!test_unit_success_o) {
        cx_error("test_load: failed to declare object '::cortex::test::unit::success'.");
        goto error;
    }

    /* Define ::cortex::test::unit::success */
    if (!cx_checkState(test_unit_success_o, CX_DEFINED)) {
        test_unit_success_o->type = cx_resolve_ext(test_unit_success_o, NULL, "::cortex::lang::bool", FALSE, "element ::cortex::test::unit::success.type");
        test_unit_success_o->modifiers = 0x4;
        test_unit_success_o->state = 0x6;
        test_unit_success_o->weak = FALSE;
        test_unit_success_o->id = 0;
        if (cx_define(test_unit_success_o)) {
            cx_error("test_load: failed to define object '::cortex::test::unit::success'.");
            goto error;
        }
    }

    /* Define ::cortex::test::unit */
    if (!cx_checkState(test_unit_o, CX_DEFINED)) {
        cx_type(test_unit_o)->defaultType = cx_resolve_ext(test_unit_o, NULL, "::cortex::lang::member", FALSE, "element ::cortex::test::unit.defaultType");
        cx_type(test_unit_o)->parentType = NULL;
        cx_type(test_unit_o)->parentState = 0x0;
        cx_interface(test_unit_o)->base = NULL;
        cx_struct(test_unit_o)->baseAccess = 0x0;
        test_unit_o->implements.length = 0;
        test_unit_o->implements.buffer = NULL;
        if (cx_define(test_unit_o)) {
            cx_error("test_load: failed to define object '::cortex::test::unit'.");
            goto error;
        }
    }

    if (cx_type(test_unit_o)->size != sizeof(struct test_unit_s)) {
        cx_error("test_load: calculated size '%d' of type '::cortex::test::unit' doesn't match C-type size '%d'", cx_type(test_unit_o)->size, sizeof(struct test_unit_s));
    }

    /* Define ::cortex::test::suite::unit */
    if (!cx_checkState(test_suite_unit_o, CX_DEFINED)) {
        test_suite_unit_o->type = cx_resolve_ext(test_suite_unit_o, NULL, "::cortex::test::unit", FALSE, "element ::cortex::test::suite::unit.type");
        test_suite_unit_o->modifiers = 0x3;
        test_suite_unit_o->state = 0x6;
        test_suite_unit_o->weak = FALSE;
        test_suite_unit_o->id = 3;
        if (cx_define(test_suite_unit_o)) {
            cx_error("test_load: failed to define object '::cortex::test::suite::unit'.");
            goto error;
        }
    }

    /* Define ::cortex::test::suite */
    if (!cx_checkState(test_suite_o, CX_DEFINED)) {
        cx_type(test_suite_o)->defaultType = cx_resolve_ext(test_suite_o, NULL, "::cortex::lang::member", FALSE, "element ::cortex::test::suite.defaultType");
        cx_type(test_suite_o)->parentType = NULL;
        cx_type(test_suite_o)->parentState = 0x0;
        cx_interface(test_suite_o)->base = NULL;
        cx_struct(test_suite_o)->baseAccess = 0x0;
        test_suite_o->implements.length = 0;
        test_suite_o->implements.buffer = NULL;
        if (cx_define(test_suite_o)) {
            cx_error("test_load: failed to define object '::cortex::test::suite'.");
            goto error;
        }
    }

    if (cx_type(test_suite_o)->size != sizeof(struct test_suite_s)) {
        cx_error("test_load: calculated size '%d' of type '::cortex::test::suite' doesn't match C-type size '%d'", cx_type(test_suite_o)->size, sizeof(struct test_suite_s));
    }

    if (_a_) {
        cx_free(_a_);
    }

    return 0;
error:
    return -1;
}
