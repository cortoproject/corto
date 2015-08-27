/* test__type.h
 *
 * Type definitions for C-language.
 * This file contains generated code. Do not modify!
 */

#ifndef test__type_H
#define test__type_H

#include "corto.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Casting macro's for classes */
#define test_Case(o) ((test_Case)cx_assertType((cx_type)test_Case_o, o))
#define test_Result(o) ((test_Result *)cx_assertType((cx_type)test_Result_o, o))
#define test_Runner(o) ((test_Runner)cx_assertType((cx_type)test_Runner_o, o))
#define test_Suite(o) ((test_Suite)cx_assertType((cx_type)test_Suite_o, o))

/* Type definitions */
/*  ::corto::test::Case */
CX_CLASS(test_Case);

CX_CLASS_DEF(test_Case) {
    CX_EXTEND(cx_method);
};

/*  ::corto::test::Result */
typedef struct test_Result test_Result;

struct test_Result {
    cx_bool success;
    cx_string assertmsg;
    cx_string errmsg;
};

/*  ::corto::test::Suite */
CX_CLASS(test_Suite);

CX_CLASS_DEF(test_Suite) {
    test_Case test;
    test_Result result;
};

CX_LIST(test_Suite_list);

/*  ::corto::test::Runner */
CX_CLASS(test_Runner);

CX_CLASS_DEF(test_Runner) {
    test_Suite_list successes;
    test_Suite_list failures;
};

#ifdef __cplusplus
}
#endif
#endif

