/* test_MethodTester.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef TEST_METHODTESTER_H
#define TEST_METHODTESTER_H

#include "corto.h"
#include "test__interface.h"

#ifdef __cplusplus
extern "C" {
#endif

TEST_EXPORT corto_void _test_MethodTester_onearg(test_MethodTester _this, corto_int32 a);
#define test_MethodTester_onearg(_this, a) _test_MethodTester_onearg(test_MethodTester(_this), a)

TEST_EXPORT corto_void _test_MethodTester_overload__test_MethodTester(test_MethodTester _this, test_MethodTester m);
#define test_MethodTester_overload__test_MethodTester(_this, m) _test_MethodTester_overload__test_MethodTester(test_MethodTester(_this), test_MethodTester(m))

TEST_EXPORT corto_void _test_MethodTester_overload_int32(test_MethodTester _this, corto_int32 a);
#define test_MethodTester_overload_int32(_this, a) _test_MethodTester_overload_int32(test_MethodTester(_this), a)

TEST_EXPORT corto_void _test_MethodTester_overload_int32_int32(test_MethodTester _this, corto_int32 a, corto_int32 b);
#define test_MethodTester_overload_int32_int32(_this, a, b) _test_MethodTester_overload_int32_int32(test_MethodTester(_this), a, b)

TEST_EXPORT corto_void _test_MethodTester_overload_string(test_MethodTester _this, corto_string a);
#define test_MethodTester_overload_string(_this, a) _test_MethodTester_overload_string(test_MethodTester(_this), a)

TEST_EXPORT corto_void _test_MethodTester_simple(test_MethodTester _this);
#define test_MethodTester_simple(_this) _test_MethodTester_simple(test_MethodTester(_this))

TEST_EXPORT corto_void _test_MethodTester_twoargs(test_MethodTester _this, corto_int32 a, corto_int32 b);
#define test_MethodTester_twoargs(_this, a, b) _test_MethodTester_twoargs(test_MethodTester(_this), a, b)

/* virtual /test/MethodTester/virtualOverload() */
TEST_EXPORT void _test_MethodTester_virtualOverload_(test_MethodTester _this);
#define test_MethodTester_virtualOverload_(_this) _test_MethodTester_virtualOverload_(test_MethodTester(_this))

TEST_EXPORT corto_void _test_MethodTester_virtualOverload__v(test_MethodTester _this);
#define test_MethodTester_virtualOverload__v(_this) _test_MethodTester_virtualOverload__v(test_MethodTester(_this))

TEST_EXPORT corto_void _test_MethodTester_virtualOverload_int32(test_MethodTester _this, corto_int32 a);
#define test_MethodTester_virtualOverload_int32(_this, a) _test_MethodTester_virtualOverload_int32(test_MethodTester(_this), a)

/* virtual /test/MethodTester/virtualSimple() */
TEST_EXPORT void _test_MethodTester_virtualSimple(test_MethodTester _this);
#define test_MethodTester_virtualSimple(_this) _test_MethodTester_virtualSimple(test_MethodTester(_this))

TEST_EXPORT corto_void _test_MethodTester_virtualSimple_v(test_MethodTester _this);
#define test_MethodTester_virtualSimple_v(_this) _test_MethodTester_virtualSimple_v(test_MethodTester(_this))

#ifdef __cplusplus
}
#endif
#endif

