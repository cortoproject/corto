/* test.h
 *
 * This file contains generated code. Do not modify!
 */

#ifndef TEST_H
#define TEST_H

#include <corto/corto.h>
#include <_interface.h>
#include <corto/test/test.h>

#include <_type.h>
#include <_api.h>
#include <_meta.h>

#ifdef __cplusplus
extern "C" {
#endif


TEST_EXPORT corto_void _test_functionToResolve(
    corto_int32 a,
    corto_int32 b);
#define test_functionToResolve(a, b) _test_functionToResolve(a, b)

TEST_EXPORT corto_void _test_ol_any__test_Color(
    test_Color a);
#define test_ol_any__test_Color(a) _test_ol_any__test_Color(a)

TEST_EXPORT corto_void _test_ol_any_bool(
    corto_bool a);
#define test_ol_any_bool(a) _test_ol_any_bool(a)

TEST_EXPORT corto_void _test_ol_any_char(
    corto_char a);
#define test_ol_any_char(a) _test_ol_any_char(a)

TEST_EXPORT corto_void _test_ol_any_float32(
    corto_float32 a);
#define test_ol_any_float32(a) _test_ol_any_float32(a)

TEST_EXPORT corto_void _test_ol_any_int32(
    corto_int32 a);
#define test_ol_any_int32(a) _test_ol_any_int32(a)

TEST_EXPORT corto_void _test_ol_any_object(
    corto_object a);
#define test_ol_any_object(a) _test_ol_any_object(a)

TEST_EXPORT corto_void _test_ol_any_string(
    corto_string a);
#define test_ol_any_string(a) _test_ol_any_string(a)

TEST_EXPORT corto_void _test_ol_bool(
    corto_bool a);
#define test_ol_bool(a) _test_ol_bool(a)

TEST_EXPORT corto_void _test_ol_inherit__test_Animal(
    test_Animal a);
#define test_ol_inherit__test_Animal(a) _test_ol_inherit__test_Animal(test_Animal(a))

TEST_EXPORT corto_void _test_ol_inherit__test_Dog(
    test_Dog a);
#define test_ol_inherit__test_Dog(a) _test_ol_inherit__test_Dog(test_Dog(a))

TEST_EXPORT corto_void _test_ol_int(
    corto_int32 a);
#define test_ol_int(a) _test_ol_int(a)

TEST_EXPORT corto_void _test_ol_null_bool(
    corto_bool a);
#define test_ol_null_bool(a) _test_ol_null_bool(a)

TEST_EXPORT corto_void _test_ol_null_object(
    corto_object a);
#define test_ol_null_object(a) _test_ol_null_object(a)

TEST_EXPORT corto_void _test_ol_null_string(
    corto_string a);
#define test_ol_null_string(a) _test_ol_null_string(a)

TEST_EXPORT corto_void _test_ol_num_float64(
    corto_float64 a);
#define test_ol_num_float64(a) _test_ol_num_float64(a)

TEST_EXPORT corto_void _test_ol_num_int32(
    corto_int32 a);
#define test_ol_num_int32(a) _test_ol_num_int32(a)

TEST_EXPORT corto_void _test_ol_object(
    corto_object a);
#define test_ol_object(a) _test_ol_object(a)

TEST_EXPORT corto_void _test_ol_string(
    corto_string a);
#define test_ol_string(a) _test_ol_string(a)

TEST_EXPORT corto_void _test_ol_uint(
    corto_int32 a);
#define test_ol_uint(a) _test_ol_uint(a)

TEST_EXPORT corto_void _test_ol_wildcard_float32_string(
    corto_float32 a,
    corto_string b);
#define test_ol_wildcard_float32_string(a, b) _test_ol_wildcard_float32_string(a, b)

TEST_EXPORT corto_void _test_ol_wildcard_int32_string(
    corto_int32 a,
    corto_string b);
#define test_ol_wildcard_int32_string(a, b) _test_ol_wildcard_int32_string(a, b)
#include <Animal.h>
#include <AnonymousTest.h>
#include <Args.h>
#include <AttrCheck.h>
#include <AttrConstructorTest.h>
#include <Attributes.h>
#include <Bar.h>
#include <Buffer.h>
#include <Cat.h>
#include <Compare.h>
#include <CompositeWithString.h>
#include <Copy.h>
#include <DeclaredParent.h>
#include <DefinedParent.h>
#include <Dog.h>
#include <EmptySinkReplicator.h>
#include <Env.h>
#include <Event.h>
#include <EventReplicator.h>
#include <EventTest.h>
#include <Foo.h>
#include <FooReplicator.h>
#include <Fullname.h>
#include <GoldenRetriever.h>
#include <JsonReplicator.h>
#include <Line.h>
#include <ListReplicator.h>
#include <MethodForwardTest.h>
#include <MethodResolver.h>
#include <MethodTester.h>
#include <MethodTesterInherit.h>
#include <ObjectMgmt.h>
#include <Overload.h>
#include <Ownership.h>
#include <Point.h>
#include <Point3D.h>
#include <RelativeName.h>
#include <ReplicatorEvent.h>
#include <ReplicatorRequest.h>
#include <Resolver.h>
#include <ResumeSink.h>
#include <Select.h>
#include <SelectContentType.h>
#include <SelectSink.h>
#include <SelectSinkNoOnRequest.h>
#include <SelectSinkWithType.h>
#include <SinkReplicator.h>
#include <StringDeserializer.h>
#include <StringReplicator.h>
#include <StringSerializer.h>
#include <VoidParent.h>

#ifdef __cplusplus
}
#endif
#endif

