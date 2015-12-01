/* test.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef TEST_H
#define TEST_H

#include "corto.h"
#include "test__interface.h"

#ifdef __cplusplus
extern "C" {
#endif

TEST_EXPORT corto_void _test_functionToResolve(corto_int32 a, corto_int32 b);
#define test_functionToResolve(a, b) _test_functionToResolve(a, b)

TEST_EXPORT corto_void _test_ol_any__test_Color(test_Color a);
#define test_ol_any__test_Color(a) _test_ol_any__test_Color(a)

TEST_EXPORT corto_void _test_ol_any_bool(corto_bool a);
#define test_ol_any_bool(a) _test_ol_any_bool(a)

TEST_EXPORT corto_void _test_ol_any_char(corto_char a);
#define test_ol_any_char(a) _test_ol_any_char(a)

TEST_EXPORT corto_void _test_ol_any_float32(corto_float32 a);
#define test_ol_any_float32(a) _test_ol_any_float32(a)

TEST_EXPORT corto_void _test_ol_any_int32(corto_int32 a);
#define test_ol_any_int32(a) _test_ol_any_int32(a)

TEST_EXPORT corto_void _test_ol_any_object(corto_object a);
#define test_ol_any_object(a) _test_ol_any_object(a)

TEST_EXPORT corto_void _test_ol_any_string(corto_string a);
#define test_ol_any_string(a) _test_ol_any_string(a)

TEST_EXPORT corto_void _test_ol_bool(corto_bool a);
#define test_ol_bool(a) _test_ol_bool(a)

TEST_EXPORT corto_void _test_ol_inherit__test_Animal(test_Animal a);
#define test_ol_inherit__test_Animal(a) _test_ol_inherit__test_Animal(test_Animal(a))

TEST_EXPORT corto_void _test_ol_inherit__test_Dog(test_Dog a);
#define test_ol_inherit__test_Dog(a) _test_ol_inherit__test_Dog(test_Dog(a))

TEST_EXPORT corto_void _test_ol_int(corto_int32 a);
#define test_ol_int(a) _test_ol_int(a)

TEST_EXPORT corto_void _test_ol_null_bool(corto_bool a);
#define test_ol_null_bool(a) _test_ol_null_bool(a)

TEST_EXPORT corto_void _test_ol_null_object(corto_object a);
#define test_ol_null_object(a) _test_ol_null_object(a)

TEST_EXPORT corto_void _test_ol_null_string(corto_string a);
#define test_ol_null_string(a) _test_ol_null_string(a)

TEST_EXPORT corto_void _test_ol_num_float64(corto_float64 a);
#define test_ol_num_float64(a) _test_ol_num_float64(a)

TEST_EXPORT corto_void _test_ol_num_int32(corto_int32 a);
#define test_ol_num_int32(a) _test_ol_num_int32(a)

TEST_EXPORT corto_void _test_ol_object(corto_object a);
#define test_ol_object(a) _test_ol_object(a)

TEST_EXPORT corto_void _test_ol_string(corto_string a);
#define test_ol_string(a) _test_ol_string(a)

TEST_EXPORT corto_void _test_ol_uint(corto_int32 a);
#define test_ol_uint(a) _test_ol_uint(a)

TEST_EXPORT corto_void _test_ol_wildcard_float32_string(corto_float32 a, corto_string b);
#define test_ol_wildcard_float32_string(a, b) _test_ol_wildcard_float32_string(a, b)

TEST_EXPORT corto_void _test_ol_wildcard_int32_string(corto_int32 a, corto_string b);
#define test_ol_wildcard_int32_string(a, b) _test_ol_wildcard_int32_string(a, b)

#ifdef __cplusplus
}
#endif
#endif

#include "test_Animal.h"
#include "test_AnonymousTest.h"
#include "test_Args.h"
#include "test_Bar.h"
#include "test_Cat.h"
#include "test_CompositeCollection.h"
#include "test_DeclaredParent.h"
#include "test_DefinedParent.h"
#include "test_Dog.h"
#include "test_Env.h"
#include "test_Event.h"
#include "test_EventTest.h"
#include "test_Foo.h"
#include "test_Fullname.h"
#include "test_GoldenRetriever.h"
#include "test_Line.h"
#include "test_MethodResolver.h"
#include "test_MethodTester.h"
#include "test_MethodTesterInherit.h"
#include "test_ObjectMgmt.h"
#include "test_Overload.h"
#include "test_Point.h"
#include "test_Point3D.h"
#include "test_PrimitiveCollection.h"
#include "test_Project.h"
#include "test_RelativeName.h"
#include "test_Resolver.h"
#include "test_Select.h"
#include "test_selectItem.h"
#include "test_StringDeserializer.h"
#include "test_VoidParent.h"
#include "corto/test/test.h"
#include "corto/test/test.h"
