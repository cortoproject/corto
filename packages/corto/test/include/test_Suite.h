/* test_Suite.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef test_Suite_H
#define test_Suite_H

#include "corto.h"
#include "test__type.h"
#include "test__api.h"
#include "test__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto::test::Suite::assert(bool b) */
cx_bool _test_Suite_assert_bool(test_Suite _this, cx_bool b);
#define test_Suite_assert_bool(_this, b) _test_Suite_assert_bool(test_Suite(_this), b)

/* ::corto::test::Suite::assert(bool b,string errmsg) */
cx_bool _test_Suite_assert_bool_string(test_Suite _this, cx_bool b, cx_string errmsg);
#define test_Suite_assert_bool_string(_this, b, errmsg) _test_Suite_assert_bool_string(test_Suite(_this), b, errmsg)

/* ::corto::test::Suite::assertEqual(any a,any b) */
cx_bool _test_Suite_assertEqual_any_any(test_Suite _this, cx_any a, cx_any b);
#define test_Suite_assertEqual_any_any(_this, a, b) _test_Suite_assertEqual_any_any(test_Suite(_this), a, b)

/* ::corto::test::Suite::assertEqual(any a,any b,string errmsg) */
cx_bool _test_Suite_assertEqual_any_any_string(test_Suite _this, cx_any a, cx_any b, cx_string errmsg);
#define test_Suite_assertEqual_any_any_string(_this, a, b, errmsg) _test_Suite_assertEqual_any_any_string(test_Suite(_this), a, b, errmsg)

/* ::corto::test::Suite::construct() */
cx_int16 _test_Suite_construct(test_Suite _this);
#define test_Suite_construct(_this) _test_Suite_construct(test_Suite(_this))

/* ::corto::test::Suite::rSetUp(object type) */
cx_void _test_Suite_rSetUp(test_Suite _this, cx_object type);
#define test_Suite_rSetUp(_this, type) _test_Suite_rSetUp(test_Suite(_this), type)

/* ::corto::test::Suite::rTearDown(object type) */
cx_void _test_Suite_rTearDown(test_Suite _this, cx_object type);
#define test_Suite_rTearDown(_this, type) _test_Suite_rTearDown(test_Suite(_this), type)

/* virtual ::corto::test::Suite::setUp() */
void test_Suite_setUp(test_Suite _this);

/* ::corto::test::Suite::setUp() */
cx_void _test_Suite_setUp_v(test_Suite _this);
#define test_Suite_setUp_v(_this) _test_Suite_setUp_v(test_Suite(_this))

/* virtual ::corto::test::Suite::tearDown() */
void test_Suite_tearDown(test_Suite _this);

/* ::corto::test::Suite::tearDown() */
cx_void _test_Suite_tearDown_v(test_Suite _this);
#define test_Suite_tearDown_v(_this) _test_Suite_tearDown_v(test_Suite(_this))

#ifdef __cplusplus
}
#endif
#endif

