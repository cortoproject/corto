/* test__type.h
 *
 * Type definitions for C-language.
 * This file contains generated code. Do not modify!
 */

#ifndef test__type_H
#define test__type_H

#include "corto.h"
#include "corto/test/test__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Casting macro's for classes */
#define test_Animal(o) ((test_Animal)corto_assertType((corto_type)test_Animal_o, o))
#define test_AnonymousTest(o) ((test_AnonymousTest)corto_assertType((corto_type)test_AnonymousTest_o, o))
#define test_Args(o) ((test_Args)corto_assertType((corto_type)test_Args_o, o))
#define test_Bar(o) ((test_Bar)corto_assertType((corto_type)test_Bar_o, o))
#define test_Cat(o) ((test_Cat)corto_assertType((corto_type)test_Cat_o, o))
#define test_Color(o) ((test_Color *)corto_assertType((corto_type)test_Color_o, o))
#define test_CompositeCollection(o) ((test_CompositeCollection *)corto_assertType((corto_type)test_CompositeCollection_o, o))
#define test_DeclaredParent(o) ((test_DeclaredParent *)corto_assertType((corto_type)test_DeclaredParent_o, o))
#define test_DefinedParent(o) ((test_DefinedParent *)corto_assertType((corto_type)test_DefinedParent_o, o))
#define test_Dog(o) ((test_Dog)corto_assertType((corto_type)test_Dog_o, o))
#define test_Env(o) ((test_Env)corto_assertType((corto_type)test_Env_o, o))
#define test_Event(o) ((test_Event)corto_assertType((corto_type)test_Event_o, o))
#define test_EventTest(o) ((test_EventTest)corto_assertType((corto_type)test_EventTest_o, o))
#define test_Foo(o) ((test_Foo)corto_assertType((corto_type)test_Foo_o, o))
#define test_Fullname(o) ((test_Fullname)corto_assertType((corto_type)test_Fullname_o, o))
#define test_GoldenRetriever(o) ((test_GoldenRetriever)corto_assertType((corto_type)test_GoldenRetriever_o, o))
#define test_Line(o) ((test_Line *)corto_assertType((corto_type)test_Line_o, o))
#define test_MethodResolver(o) ((test_MethodResolver)corto_assertType((corto_type)test_MethodResolver_o, o))
#define test_MethodTester(o) ((test_MethodTester)corto_assertType((corto_type)test_MethodTester_o, o))
#define test_MethodTesterInherit(o) ((test_MethodTesterInherit)corto_assertType((corto_type)test_MethodTesterInherit_o, o))
#define test_ObjectMgmt(o) ((test_ObjectMgmt)corto_assertType((corto_type)test_ObjectMgmt_o, o))
#define test_Overload(o) ((test_Overload)corto_assertType((corto_type)test_Overload_o, o))
#define test_Point(o) ((test_Point *)corto_assertType((corto_type)test_Point_o, o))
#define test_Point3D(o) ((test_Point3D *)corto_assertType((corto_type)test_Point3D_o, o))
#define test_PrimitiveCollection(o) ((test_PrimitiveCollection *)corto_assertType((corto_type)test_PrimitiveCollection_o, o))
#define test_Project(o) ((test_Project)corto_assertType((corto_type)test_Project_o, o))
#define test_RelativeName(o) ((test_RelativeName)corto_assertType((corto_type)test_RelativeName_o, o))
#define test_Resolver(o) ((test_Resolver)corto_assertType((corto_type)test_Resolver_o, o))
#define test_Select(o) ((test_Select)corto_assertType((corto_type)test_Select_o, o))
#define test_selectItem(o) ((test_selectItem *)corto_assertType((corto_type)test_selectItem_o, o))
#define test_StringDeserializer(o) ((test_StringDeserializer)corto_assertType((corto_type)test_StringDeserializer_o, o))
#define test_VoidParent(o) ((test_VoidParent *)corto_assertType((corto_type)test_VoidParent_o, o))

/* Type definitions */
/*  /test/Animal */
CORTO_CLASS(test_Animal);

CORTO_CLASS_DEF(test_Animal) {
    corto_bool a;
};

CORTO_LIST(corto_objectList);

/*  /test/AnonymousTest */
CORTO_CLASS(test_AnonymousTest);

CORTO_CLASS_DEF(test_AnonymousTest) {
    corto_objectList objects;
};

/*  /test/Args */
CORTO_CLASS(test_Args);

CORTO_CLASS_DEF(test_Args) {
    CORTO_EXTEND(test_SuiteData);
};

/*  /test/Bar */
CORTO_CLASS(test_Bar);

CORTO_CLASS_DEF(test_Bar) {
    corto_int8 __dummy;
};

/*  /test/Cat */
CORTO_CLASS(test_Cat);

CORTO_CLASS_DEF(test_Cat) {
    CORTO_EXTEND(test_Animal);
    corto_bool b;
};

/* /test/Color */
typedef enum test_Color {
    Test_Red = 0,
    Test_Orange = 1,
    Test_Yellow = 2,
    Test_Green = 3,
    Test_Blue = 4
} test_Color;

/*  /test/Point */
typedef struct test_Point test_Point;

struct test_Point {
    corto_int32 x;
    corto_int32 y;
};

CORTO_LIST(test_PointList);

/*  /test/CompositeCollection */
typedef struct test_CompositeCollection test_CompositeCollection;

struct test_CompositeCollection {
    test_PointList points;
};

/*  /test/DeclaredParent */
typedef struct test_DeclaredParent test_DeclaredParent;

struct test_DeclaredParent {
    corto_int32 Foo;
};

/*  /test/DefinedParent */
typedef struct test_DefinedParent test_DefinedParent;

struct test_DefinedParent {
    corto_int32 Foo;
};

/*  /test/Dog */
CORTO_CLASS(test_Dog);

CORTO_CLASS_DEF(test_Dog) {
    CORTO_EXTEND(test_Animal);
    corto_bool b;
};

/*  /test/Env */
CORTO_CLASS(test_Env);

CORTO_CLASS_DEF(test_Env) {
    CORTO_EXTEND(test_SuiteData);
};

/*  /test/EventTest */
CORTO_CLASS(test_EventTest);

CORTO_CLASS_DEF(test_EventTest) {
    corto_object scope;
    corto_object lastThis;
    corto_object lastObservable;
    corto_uint32 countDeclare;
    corto_uint32 countDeclareSelf;
    corto_uint32 countDeclareScope;
    corto_uint32 countDeclareTree;
    corto_uint32 countDefine;
    corto_uint32 countDefineSelf;
    corto_uint32 countDefineScope;
    corto_uint32 countDefineTree;
    corto_uint32 countUpdate;
    corto_uint32 countUpdateSelf;
    corto_uint32 countUpdateScope;
    corto_uint32 countUpdateTree;
    corto_uint32 countDelete;
    corto_uint32 countDeleteSelf;
    corto_uint32 countDeleteScope;
    corto_uint32 countDeleteTree;
};

/*  /test/Event */
CORTO_CLASS(test_Event);

CORTO_CLASS_DEF(test_Event) {
    CORTO_EXTEND(test_SuiteData);
    test_EventTest et;
    corto_attr prevAttr;
};

/*  /test/Foo */
CORTO_CLASS(test_Foo);

CORTO_CLASS_DEF(test_Foo) {
    corto_bool fail;
    corto_int32 x;
    corto_int32 y;
};

/*  /test/Fullname */
CORTO_CLASS(test_Fullname);

CORTO_CLASS_DEF(test_Fullname) {
    CORTO_EXTEND(test_SuiteData);
};

/*  /test/GoldenRetriever */
CORTO_CLASS(test_GoldenRetriever);

CORTO_CLASS_DEF(test_GoldenRetriever) {
    CORTO_EXTEND(test_Dog);
    corto_bool c;
};

/*  /test/Line */
typedef struct test_Line test_Line;

struct test_Line {
    test_Point start;
    test_Point stop;
};

/*  /test/MethodResolver */
CORTO_CLASS(test_MethodResolver);

CORTO_CLASS_DEF(test_MethodResolver) {
    CORTO_EXTEND(test_SuiteData);
};

/*  /test/MethodTester */
CORTO_CLASS(test_MethodTester);

CORTO_CLASS_DEF(test_MethodTester) {
    corto_int8 __dummy;
};

/*  /test/MethodTesterInherit */
CORTO_CLASS(test_MethodTesterInherit);

CORTO_CLASS_DEF(test_MethodTesterInherit) {
    CORTO_EXTEND(test_MethodTester);
};

/*  /test/ObjectMgmt */
CORTO_CLASS(test_ObjectMgmt);

CORTO_CLASS_DEF(test_ObjectMgmt) {
    CORTO_EXTEND(test_SuiteData);
    corto_attr prevAttr;
};

/*  /test/Overload */
CORTO_CLASS(test_Overload);

CORTO_CLASS_DEF(test_Overload) {
    CORTO_EXTEND(test_SuiteData);
};

/*  /test/Point3D */
typedef struct test_Point3D test_Point3D;

struct test_Point3D {
    test_Point _parent;
    corto_int32 z;
};

CORTO_LIST(corto_int32List);

/*  /test/PrimitiveCollection */
typedef struct test_PrimitiveCollection test_PrimitiveCollection;

struct test_PrimitiveCollection {
    corto_int32List ints;
};

/*  /test/Project */
CORTO_CLASS(test_Project);

CORTO_CLASS_DEF(test_Project) {
    CORTO_EXTEND(test_SuiteData);
};

/*  /test/RelativeName */
CORTO_CLASS(test_RelativeName);

CORTO_CLASS_DEF(test_RelativeName) {
    CORTO_EXTEND(test_SuiteData);
    corto_object tier1;
    corto_object tier2;
    corto_object tier3;
    corto_object obj;
    corto_object disjunct;
    corto_object child;
};

/*  /test/Resolver */
CORTO_CLASS(test_Resolver);

CORTO_CLASS_DEF(test_Resolver) {
    CORTO_EXTEND(test_SuiteData);
};

/*  /test/Select */
CORTO_CLASS(test_Select);

CORTO_CLASS_DEF(test_Select) {
    CORTO_EXTEND(test_SuiteData);
};

/*  /test/selectItem */
typedef struct test_selectItem test_selectItem;

struct test_selectItem {
    corto_string parent;
    corto_string name;
    corto_string type;
};

CORTO_LIST(test_selectItemList);

/*  /test/StringDeserializer */
CORTO_CLASS(test_StringDeserializer);

CORTO_CLASS_DEF(test_StringDeserializer) {
    CORTO_EXTEND(test_SuiteData);
};

/*  /test/VoidParent */
typedef struct test_VoidParent test_VoidParent;

struct test_VoidParent {
    corto_int32 Foo;
};

#ifdef __cplusplus
}
#endif
#endif

