/* test_unit.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef test_unit_H
#define test_unit_H

#include "cortex.h"
#include "test__type.h"

#include "test__api.h"

#include "test__meta.h"

#ifdef __cplusplus
extern "C" {
#endif

/* callback ::cortex::lang::class::construct(lang::object object) -> ::cortex::test::unit::construct(::cortex::test::unit object) */
cx_int16 test_unit_construct(test_unit object);

/* ::cortex::test::unit::fail(::cortex::lang::string msg) */
cx_void test_unit_fail(test_unit _this, cx_string msg);

#ifdef __cplusplus
}
#endif
#endif

