/* test__meta.h
 *
 * Loads objects in database.
 * This file contains generated code. Do not modify!
 */

#ifndef test_META_H
#define test_META_H

#include "cortex.h"

#include "test__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::cortex */
extern cx_object _o;

/* ::cortex::test */
extern cx_package test_o;

/* ::cortex::test::suite */
extern cx_class test_suite_o;

/* ::cortex::test::suite::assert(any v1,any v2,string msg) */
extern cx_method test_suite_assert_any_any_string_o;

/* ::cortex::test::suite::assert(bool cond,string msg) */
extern cx_method test_suite_assert_bool_string_o;

/* ::cortex::test::suite::construct() */
extern cx_method test_suite_construct_o;

/* ::cortex::test::suite::fail(string msg) */
extern cx_method test_suite_fail_o;

/* ::cortex::test::suite::package */
extern cx_member test_suite_package_o;

/* ::cortex::test::suite::result */
extern cx_member test_suite_result_o;

/* ::cortex::test::suite::silent */
extern cx_member test_suite_silent_o;

/* ::cortex::test::suite::success */
extern cx_member test_suite_success_o;

/* ::cortex::test::suite::unit */
extern cx_member test_suite_unit_o;

/* ::cortex::test::test */
extern cx_procedure test_test_o;

/* ::cortex::test::unit */
extern cx_class test_unit_o;

/* ::cortex::test::unit::construct() */
extern cx_method test_unit_construct_o;

/* ::cortex::test::unit::fail(string msg) */
extern cx_method test_unit_fail_o;

/* ::cortex::test::unit::failmsg */
extern cx_member test_unit_failmsg_o;

/* ::cortex::test::unit::success */
extern cx_member test_unit_success_o;

int test_load(void);
#ifdef __cplusplus
}
#endif
#endif

