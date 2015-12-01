/* test_Foo.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef TEST_FOO_H
#define TEST_FOO_H

#include "corto.h"
#include "test__interface.h"

#ifdef __cplusplus
extern "C" {
#endif

TEST_EXPORT corto_int16 _test_Foo_construct(test_Foo _this);
#define test_Foo_construct(_this) _test_Foo_construct(test_Foo(_this))

TEST_EXPORT corto_void _test_Foo_destruct(test_Foo _this);
#define test_Foo_destruct(_this) _test_Foo_destruct(test_Foo(_this))

TEST_EXPORT corto_int16 _test_Foo_init(test_Foo _this);
#define test_Foo_init(_this) _test_Foo_init(test_Foo(_this))

#ifdef __cplusplus
}
#endif
#endif

