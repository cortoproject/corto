/* test__type.h
 *
 *    Type-definitions for C-language.
 *    This file contains generated code. Do not modify!
 */

#ifndef test__type_H
#define test__type_H

#include "cortex.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Casting macro's for classes */
#define test_suite(o) ((test_suite)cx_assertType((cx_type)test_suite_o, o))
#define test_test(o) ((test_test)cx_assertType((cx_type)test_test_o, o))
#define test_unit(o) ((test_unit)cx_assertType((cx_type)test_unit_o, o))

/* Type definitions */
/*  ::cortex::test::unit */
CX_CLASS(test_unit);

CX_CLASS_DEF(test_unit) {
    cx_bool success;
    cx_string failmsg;
};

/*  ::cortex::test::suite */
CX_CLASS(test_suite);

CX_CLASS_DEF(test_suite) {
    cx_object package;
    cx_bool silent;
    cx_bool success;
    test_unit unit;
    cx_object result;
};

/*  ::cortex::test::test */
CX_CLASS(test_test);

CX_CLASS_DEF(test_test) {
    CX_EXTEND(cx_function);
};

#ifdef __cplusplus
}
#endif
#endif

