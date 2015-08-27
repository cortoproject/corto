/* test__meta.h
 *
 * Loads objects in object store.
 * This file contains generated code. Do not modify!
 */

#ifndef test_META_H
#define test_META_H

#include "corto.h"

#include "test__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto */
extern cx_package _o;

/* ::corto::test */
extern cx_package test_o;

/* ::corto::test::Case */
extern cx_procedure test_Case_o;

/* ::corto::test::Result */
extern cx_struct test_Result_o;

/* ::corto::test::Result::assertmsg */
extern cx_member test_Result_assertmsg_o;

/* ::corto::test::Result::errmsg */
extern cx_member test_Result_errmsg_o;

/* ::corto::test::Result::success */
extern cx_member test_Result_success_o;

/* ::corto::test::Runner */
extern cx_class test_Runner_o;

/* ::corto::test::Runner::construct() */
extern cx_method test_Runner_construct_o;

/* ::corto::test::Runner::destruct() */
extern cx_method test_Runner_destruct_o;

/* ::corto::test::Runner::failures */
extern cx_member test_Runner_failures_o;

/* ::corto::test::Runner::printTestRun(::corto::test::Suite t) */
extern cx_virtual test_Runner_printTestRun_o;

/* ::corto::test::Runner::runTest() */
extern cx_observer test_Runner_runTest_o;

/* ::corto::test::Runner::successes */
extern cx_member test_Runner_successes_o;

/* ::corto::test::Suite */
extern cx_class test_Suite_o;

/* ::corto::test::Suite::assert(bool b) */
extern cx_method test_Suite_assert_bool_o;

/* ::corto::test::Suite::assert(bool b,string errmsg) */
extern cx_method test_Suite_assert_bool_string_o;

/* ::corto::test::Suite::assertEqual(any a,any b) */
extern cx_method test_Suite_assertEqual_any_any_o;

/* ::corto::test::Suite::assertEqual(any a,any b,string errmsg) */
extern cx_method test_Suite_assertEqual_any_any_string_o;

/* ::corto::test::Suite::construct() */
extern cx_method test_Suite_construct_o;

/* ::corto::test::Suite::result */
extern cx_member test_Suite_result_o;

/* ::corto::test::Suite::rSetUp(object type) */
extern cx_method test_Suite_rSetUp_o;

/* ::corto::test::Suite::rTearDown(object type) */
extern cx_method test_Suite_rTearDown_o;

/* ::corto::test::Suite::setUp() */
extern cx_virtual test_Suite_setUp_o;

/* ::corto::test::Suite::tearDown() */
extern cx_virtual test_Suite_tearDown_o;

/* ::corto::test::Suite::test */
extern cx_member test_Suite_test_o;

int test_load(void);
#ifdef __cplusplus
}
#endif
#endif

