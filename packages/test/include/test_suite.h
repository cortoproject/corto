/* test_suite.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef test_suite_H
#define test_suite_H

#include "cortex.h"
#include "test__type.h"

#include "test__api.h"

#include "test__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::cortex::test::suite::assert(any v1,any v2,string msg) */
cx_void test_suite_assert_any_any_string(test_suite _this, cx_any v1, cx_any v2, cx_string msg);

/* ::cortex::test::suite::assert(bool cond,string msg) */
cx_void test_suite_assert_bool_string(test_suite _this, cx_bool cond, cx_string msg);

/* ::cortex::test::suite::construct() */
cx_int16 test_suite_construct(test_suite _this);

/* ::cortex::test::suite::fail(string msg) */
cx_void test_suite_fail(test_suite _this, cx_string msg);

#ifdef __cplusplus
}
#endif
#endif

