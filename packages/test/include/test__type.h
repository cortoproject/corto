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
#define test_result(o) ((test_result)o)
#define test_suite(o) ((test_suite)o)
#define test_unit(o) ((test_unit)o)

/* Type definitions */
/*  ::cortex::test::result */
CX_CLASS(test_result);

CX_CLASS_DEF(test_result) {
    cx_object package;
};

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
    test_result result;
};

#ifdef __cplusplus
}
#endif
#endif

