/* test__api.h
 *
 *    API convenience functions for C-language.
 *    This file contains generated code. Do not modify!
 */

#ifndef test__API_H
#define test__API_H

#include "test__type.h"
#include "cortex.h"

#ifdef __cplusplus
extern "C" {
#endif
/* ::cortex::test::suite */
test_suite test_suite__new(void);
test_suite test_suite__declare(cx_object _parent, cx_string _name);
int test_suite__define(test_suite _this, cx_object package, cx_bool silent);
test_suite test_suite__create(cx_object package, cx_bool silent);

/* ::cortex::test::test */
test_test test_test__new(void);
test_test test_test__declare(cx_object _parent, cx_string _name);
int test_test__define(test_test _this, cx_type returnType, cx_bool returnsReference);
test_test test_test__create(cx_type returnType, cx_bool returnsReference);

/* ::cortex::test::unit */
test_unit test_unit__new(void);
test_unit test_unit__declare(cx_object _parent, cx_string _name);
int test_unit__define(test_unit _this);
test_unit test_unit__create(void);


#ifdef __cplusplus
}
#endif
#endif

