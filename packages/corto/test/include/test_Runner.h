/* test_Runner.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef test_Runner_H
#define test_Runner_H

#include "corto.h"
#include "test__type.h"
#include "test__api.h"
#include "test__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto::test::Runner::construct() */
cx_int16 _test_Runner_construct(test_Runner _this);
#define test_Runner_construct(_this) _test_Runner_construct(test_Runner(_this))

/* ::corto::test::Runner::destruct() */
cx_void _test_Runner_destruct(test_Runner _this);
#define test_Runner_destruct(_this) _test_Runner_destruct(test_Runner(_this))

/* virtual ::corto::test::Runner::printTestRun(::corto::test::Suite t) */
void test_Runner_printTestRun(test_Runner _this, test_Suite t);

/* ::corto::test::Runner::printTestRun(::corto::test::Suite t) */
cx_void _test_Runner_printTestRun_v(test_Runner _this, test_Suite t);
#define test_Runner_printTestRun_v(_this, t) _test_Runner_printTestRun_v(test_Runner(_this), test_Suite(t))

/* ::corto::test::Runner::runTest() */
cx_void _test_Runner_runTest(test_Runner _this, cx_object *observable, cx_object *source);
#define test_Runner_runTest(_this, observable, source) _test_Runner_runTest(test_Runner(_this), observable, source)

#ifdef __cplusplus
}
#endif
#endif

