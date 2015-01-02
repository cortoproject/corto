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

/* callback ::cortex::lang::class::construct(lang::object object) -> ::cortex::test::suite::construct(::cortex::test::suite object) */
cx_int16 test_suite_construct(test_suite object);

/* ::cortex::test::suite::fail(::cortex::lang::string msg) */
cx_void test_suite_fail(test_suite _this, cx_string msg);

#ifdef __cplusplus
}
#endif
#endif

