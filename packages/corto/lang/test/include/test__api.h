/* test__api.h
 *
 * API convenience functions for C-language.
 * This file contains generated code. Do not modify!
 */

#ifndef test__API_H
#define test__API_H

#include "corto.h"
#include "test__interface.h"
#ifdef __cplusplus
extern "C" {
#endif
/* /test/Animal */
TEST_EXPORT test_Animal _test_AnimalCreate(corto_bool a);
#define test_AnimalCreate(a) _test_AnimalCreate(a)
TEST_EXPORT test_Animal _test_AnimalCreateChild(corto_object _parent, corto_string _name, corto_bool a);
#define test_AnimalCreateChild(_parent, _name, a) _test_AnimalCreateChild(_parent, _name, a)
TEST_EXPORT corto_int16 _test_AnimalUpdate(test_Animal _this, corto_bool a);
#define test_AnimalUpdate(_this, a) _test_AnimalUpdate(test_Animal(_this), a)

TEST_EXPORT test_Animal _test_AnimalDeclare(void);
#define test_AnimalDeclare() _test_AnimalDeclare()
TEST_EXPORT test_Animal _test_AnimalDeclareChild(corto_object _parent, corto_string _name);
#define test_AnimalDeclareChild(_parent, _name) _test_AnimalDeclareChild(_parent, _name)
TEST_EXPORT corto_int16 _test_AnimalDefine(test_Animal _this, corto_bool a);
#define test_AnimalDefine(_this, a) _test_AnimalDefine(test_Animal(_this), a)
TEST_EXPORT void _test_AnimalSet(test_Animal _this, corto_bool a);
#define test_AnimalSet(_this, a) _test_AnimalSet(test_Animal(_this), a)
TEST_EXPORT corto_string _test_AnimalStr(test_Animal value);
#define test_AnimalStr(value) _test_AnimalStr(test_Animal(value))
TEST_EXPORT test_Animal test_AnimalFromStr(test_Animal value, corto_string str);
TEST_EXPORT corto_int16 _test_AnimalCopy(test_Animal *dst, test_Animal src);
#define test_AnimalCopy(dst, src) _test_AnimalCopy(dst, test_Animal(src))
TEST_EXPORT corto_int16 _test_AnimalCompare(test_Animal dst, test_Animal src);
#define test_AnimalCompare(dst, src) _test_AnimalCompare(test_Animal(dst), test_Animal(src))

/* /test/AnonymousTest */
TEST_EXPORT test_AnonymousTest _test_AnonymousTestCreate(corto_objectList objects);
#define test_AnonymousTestCreate(objects) _test_AnonymousTestCreate(objects)
TEST_EXPORT test_AnonymousTest _test_AnonymousTestCreateChild(corto_object _parent, corto_string _name, corto_objectList objects);
#define test_AnonymousTestCreateChild(_parent, _name, objects) _test_AnonymousTestCreateChild(_parent, _name, objects)
TEST_EXPORT corto_int16 _test_AnonymousTestUpdate(test_AnonymousTest _this, corto_objectList objects);
#define test_AnonymousTestUpdate(_this, objects) _test_AnonymousTestUpdate(test_AnonymousTest(_this), objects)

TEST_EXPORT test_AnonymousTest _test_AnonymousTestDeclare(void);
#define test_AnonymousTestDeclare() _test_AnonymousTestDeclare()
TEST_EXPORT test_AnonymousTest _test_AnonymousTestDeclareChild(corto_object _parent, corto_string _name);
#define test_AnonymousTestDeclareChild(_parent, _name) _test_AnonymousTestDeclareChild(_parent, _name)
TEST_EXPORT corto_int16 _test_AnonymousTestDefine(test_AnonymousTest _this, corto_objectList objects);
#define test_AnonymousTestDefine(_this, objects) _test_AnonymousTestDefine(test_AnonymousTest(_this), objects)
TEST_EXPORT void _test_AnonymousTestSet(test_AnonymousTest _this, corto_objectList objects);
#define test_AnonymousTestSet(_this, objects) _test_AnonymousTestSet(test_AnonymousTest(_this), objects)
TEST_EXPORT corto_string _test_AnonymousTestStr(test_AnonymousTest value);
#define test_AnonymousTestStr(value) _test_AnonymousTestStr(test_AnonymousTest(value))
TEST_EXPORT test_AnonymousTest test_AnonymousTestFromStr(test_AnonymousTest value, corto_string str);
TEST_EXPORT corto_int16 _test_AnonymousTestCopy(test_AnonymousTest *dst, test_AnonymousTest src);
#define test_AnonymousTestCopy(dst, src) _test_AnonymousTestCopy(dst, test_AnonymousTest(src))
TEST_EXPORT corto_int16 _test_AnonymousTestCompare(test_AnonymousTest dst, test_AnonymousTest src);
#define test_AnonymousTestCompare(dst, src) _test_AnonymousTestCompare(test_AnonymousTest(dst), test_AnonymousTest(src))

/* /test/Args */
TEST_EXPORT test_Args _test_ArgsCreate(test_Case test, corto_uint32 assertCount);
#define test_ArgsCreate(test, assertCount) _test_ArgsCreate(test_Case(test), assertCount)
TEST_EXPORT test_Args _test_ArgsCreateChild(corto_object _parent, corto_string _name, test_Case test, corto_uint32 assertCount);
#define test_ArgsCreateChild(_parent, _name, test, assertCount) _test_ArgsCreateChild(_parent, _name, test_Case(test), assertCount)
TEST_EXPORT corto_int16 _test_ArgsUpdate(test_Args _this, test_Case test, corto_uint32 assertCount);
#define test_ArgsUpdate(_this, test, assertCount) _test_ArgsUpdate(test_Args(_this), test_Case(test), assertCount)

TEST_EXPORT test_Args _test_ArgsDeclare(void);
#define test_ArgsDeclare() _test_ArgsDeclare()
TEST_EXPORT test_Args _test_ArgsDeclareChild(corto_object _parent, corto_string _name);
#define test_ArgsDeclareChild(_parent, _name) _test_ArgsDeclareChild(_parent, _name)
TEST_EXPORT corto_int16 _test_ArgsDefine(test_Args _this, test_Case test, corto_uint32 assertCount);
#define test_ArgsDefine(_this, test, assertCount) _test_ArgsDefine(test_Args(_this), test_Case(test), assertCount)
TEST_EXPORT void _test_ArgsSet(test_Args _this, test_Case test, corto_uint32 assertCount);
#define test_ArgsSet(_this, test, assertCount) _test_ArgsSet(test_Args(_this), test_Case(test), assertCount)
TEST_EXPORT corto_string _test_ArgsStr(test_Args value);
#define test_ArgsStr(value) _test_ArgsStr(test_Args(value))
TEST_EXPORT test_Args test_ArgsFromStr(test_Args value, corto_string str);
TEST_EXPORT corto_int16 _test_ArgsCopy(test_Args *dst, test_Args src);
#define test_ArgsCopy(dst, src) _test_ArgsCopy(dst, test_Args(src))
TEST_EXPORT corto_int16 _test_ArgsCompare(test_Args dst, test_Args src);
#define test_ArgsCompare(dst, src) _test_ArgsCompare(test_Args(dst), test_Args(src))

/* /test/Bar */
TEST_EXPORT test_Bar _test_BarCreate(void);
#define test_BarCreate() _test_BarCreate()
TEST_EXPORT test_Bar _test_BarCreateChild(corto_object _parent, corto_string _name);
#define test_BarCreateChild(_parent, _name) _test_BarCreateChild(_parent, _name)
TEST_EXPORT corto_int16 _test_BarUpdate(test_Bar _this);
#define test_BarUpdate(_this) _test_BarUpdate(test_Bar(_this))

TEST_EXPORT test_Bar _test_BarDeclare(void);
#define test_BarDeclare() _test_BarDeclare()
TEST_EXPORT test_Bar _test_BarDeclareChild(corto_object _parent, corto_string _name);
#define test_BarDeclareChild(_parent, _name) _test_BarDeclareChild(_parent, _name)
TEST_EXPORT corto_int16 _test_BarDefine(test_Bar _this);
#define test_BarDefine(_this) _test_BarDefine(test_Bar(_this))
TEST_EXPORT void _test_BarSet(test_Bar _this);
#define test_BarSet(_this) _test_BarSet(test_Bar(_this))
TEST_EXPORT corto_string _test_BarStr(test_Bar value);
#define test_BarStr(value) _test_BarStr(test_Bar(value))
TEST_EXPORT test_Bar test_BarFromStr(test_Bar value, corto_string str);
TEST_EXPORT corto_int16 _test_BarCopy(test_Bar *dst, test_Bar src);
#define test_BarCopy(dst, src) _test_BarCopy(dst, test_Bar(src))
TEST_EXPORT corto_int16 _test_BarCompare(test_Bar dst, test_Bar src);
#define test_BarCompare(dst, src) _test_BarCompare(test_Bar(dst), test_Bar(src))

/* /test/Cat */
TEST_EXPORT test_Cat _test_CatCreate(corto_bool a, corto_bool b);
#define test_CatCreate(a, b) _test_CatCreate(a, b)
TEST_EXPORT test_Cat _test_CatCreateChild(corto_object _parent, corto_string _name, corto_bool a, corto_bool b);
#define test_CatCreateChild(_parent, _name, a, b) _test_CatCreateChild(_parent, _name, a, b)
TEST_EXPORT corto_int16 _test_CatUpdate(test_Cat _this, corto_bool a, corto_bool b);
#define test_CatUpdate(_this, a, b) _test_CatUpdate(test_Cat(_this), a, b)

TEST_EXPORT test_Cat _test_CatDeclare(void);
#define test_CatDeclare() _test_CatDeclare()
TEST_EXPORT test_Cat _test_CatDeclareChild(corto_object _parent, corto_string _name);
#define test_CatDeclareChild(_parent, _name) _test_CatDeclareChild(_parent, _name)
TEST_EXPORT corto_int16 _test_CatDefine(test_Cat _this, corto_bool a, corto_bool b);
#define test_CatDefine(_this, a, b) _test_CatDefine(test_Cat(_this), a, b)
TEST_EXPORT void _test_CatSet(test_Cat _this, corto_bool a, corto_bool b);
#define test_CatSet(_this, a, b) _test_CatSet(test_Cat(_this), a, b)
TEST_EXPORT corto_string _test_CatStr(test_Cat value);
#define test_CatStr(value) _test_CatStr(test_Cat(value))
TEST_EXPORT test_Cat test_CatFromStr(test_Cat value, corto_string str);
TEST_EXPORT corto_int16 _test_CatCopy(test_Cat *dst, test_Cat src);
#define test_CatCopy(dst, src) _test_CatCopy(dst, test_Cat(src))
TEST_EXPORT corto_int16 _test_CatCompare(test_Cat dst, test_Cat src);
#define test_CatCompare(dst, src) _test_CatCompare(test_Cat(dst), test_Cat(src))

/* /test/Color */
TEST_EXPORT test_Color* _test_ColorCreate(test_Color value);
#define test_ColorCreate(value) _test_ColorCreate(value)
TEST_EXPORT test_Color* _test_ColorCreateChild(corto_object _parent, corto_string _name, test_Color value);
#define test_ColorCreateChild(_parent, _name, value) _test_ColorCreateChild(_parent, _name, value)
TEST_EXPORT corto_int16 _test_ColorUpdate(test_Color* _this, test_Color value);
#define test_ColorUpdate(_this, value) _test_ColorUpdate(_this, value)

TEST_EXPORT test_Color* _test_ColorDeclare(void);
#define test_ColorDeclare() _test_ColorDeclare()
TEST_EXPORT test_Color* _test_ColorDeclareChild(corto_object _parent, corto_string _name);
#define test_ColorDeclareChild(_parent, _name) _test_ColorDeclareChild(_parent, _name)
TEST_EXPORT corto_int16 _test_ColorDefine(test_Color* _this, test_Color value);
#define test_ColorDefine(_this, value) _test_ColorDefine(_this, value)
TEST_EXPORT void _test_ColorSet(test_Color* _this, test_Color value);
#define test_ColorSet(_this, value) _test_ColorSet(_this, value)
TEST_EXPORT corto_string _test_ColorStr(test_Color value);
#define test_ColorStr(value) _test_ColorStr(value)
TEST_EXPORT test_Color* test_ColorFromStr(test_Color* value, corto_string str);
TEST_EXPORT corto_int16 _test_ColorCopy(test_Color* *dst, test_Color* src);
#define test_ColorCopy(dst, src) _test_ColorCopy(dst, src)
TEST_EXPORT corto_int16 _test_ColorCompare(test_Color* dst, test_Color* src);
#define test_ColorCompare(dst, src) _test_ColorCompare(dst, src)

TEST_EXPORT corto_int16 _test_ColorInit(test_Color* value);
#define test_ColorInit(value) _test_ColorInit(value)
TEST_EXPORT corto_int16 _test_ColorDeinit(test_Color* value);
#define test_ColorDeinit(value) _test_ColorDeinit(value)

/* /test/CompositeCollection */
TEST_EXPORT test_CompositeCollection* _test_CompositeCollectionCreate(test_PointList points);
#define test_CompositeCollectionCreate(points) _test_CompositeCollectionCreate(points)
TEST_EXPORT test_CompositeCollection* _test_CompositeCollectionCreateChild(corto_object _parent, corto_string _name, test_PointList points);
#define test_CompositeCollectionCreateChild(_parent, _name, points) _test_CompositeCollectionCreateChild(_parent, _name, points)
TEST_EXPORT corto_int16 _test_CompositeCollectionUpdate(test_CompositeCollection* _this, test_PointList points);
#define test_CompositeCollectionUpdate(_this, points) _test_CompositeCollectionUpdate(_this, points)

TEST_EXPORT test_CompositeCollection* _test_CompositeCollectionDeclare(void);
#define test_CompositeCollectionDeclare() _test_CompositeCollectionDeclare()
TEST_EXPORT test_CompositeCollection* _test_CompositeCollectionDeclareChild(corto_object _parent, corto_string _name);
#define test_CompositeCollectionDeclareChild(_parent, _name) _test_CompositeCollectionDeclareChild(_parent, _name)
TEST_EXPORT corto_int16 _test_CompositeCollectionDefine(test_CompositeCollection* _this, test_PointList points);
#define test_CompositeCollectionDefine(_this, points) _test_CompositeCollectionDefine(_this, points)
TEST_EXPORT void _test_CompositeCollectionSet(test_CompositeCollection* _this, test_PointList points);
#define test_CompositeCollectionSet(_this, points) _test_CompositeCollectionSet(_this, points)
TEST_EXPORT corto_string _test_CompositeCollectionStr(test_CompositeCollection* value);
#define test_CompositeCollectionStr(value) _test_CompositeCollectionStr(value)
TEST_EXPORT test_CompositeCollection* test_CompositeCollectionFromStr(test_CompositeCollection* value, corto_string str);
TEST_EXPORT corto_int16 _test_CompositeCollectionCopy(test_CompositeCollection* *dst, test_CompositeCollection* src);
#define test_CompositeCollectionCopy(dst, src) _test_CompositeCollectionCopy(dst, src)
TEST_EXPORT corto_int16 _test_CompositeCollectionCompare(test_CompositeCollection* dst, test_CompositeCollection* src);
#define test_CompositeCollectionCompare(dst, src) _test_CompositeCollectionCompare(dst, src)

TEST_EXPORT corto_int16 _test_CompositeCollectionInit(test_CompositeCollection* value);
#define test_CompositeCollectionInit(value) _test_CompositeCollectionInit(value)
TEST_EXPORT corto_int16 _test_CompositeCollectionDeinit(test_CompositeCollection* value);
#define test_CompositeCollectionDeinit(value) _test_CompositeCollectionDeinit(value)

/* /test/DeclaredParent */
TEST_EXPORT test_DeclaredParent* _test_DeclaredParentCreate(corto_int32 Foo);
#define test_DeclaredParentCreate(Foo) _test_DeclaredParentCreate(Foo)
TEST_EXPORT test_DeclaredParent* _test_DeclaredParentCreateChild(corto_object _parent, corto_string _name, corto_int32 Foo);
#define test_DeclaredParentCreateChild(_parent, _name, Foo) _test_DeclaredParentCreateChild(_parent, _name, Foo)
TEST_EXPORT corto_int16 _test_DeclaredParentUpdate(test_DeclaredParent* _this, corto_int32 Foo);
#define test_DeclaredParentUpdate(_this, Foo) _test_DeclaredParentUpdate(_this, Foo)

TEST_EXPORT test_DeclaredParent* _test_DeclaredParentDeclare(void);
#define test_DeclaredParentDeclare() _test_DeclaredParentDeclare()
TEST_EXPORT test_DeclaredParent* _test_DeclaredParentDeclareChild(corto_object _parent, corto_string _name);
#define test_DeclaredParentDeclareChild(_parent, _name) _test_DeclaredParentDeclareChild(_parent, _name)
TEST_EXPORT corto_int16 _test_DeclaredParentDefine(test_DeclaredParent* _this, corto_int32 Foo);
#define test_DeclaredParentDefine(_this, Foo) _test_DeclaredParentDefine(_this, Foo)
TEST_EXPORT void _test_DeclaredParentSet(test_DeclaredParent* _this, corto_int32 Foo);
#define test_DeclaredParentSet(_this, Foo) _test_DeclaredParentSet(_this, Foo)
TEST_EXPORT corto_string _test_DeclaredParentStr(test_DeclaredParent* value);
#define test_DeclaredParentStr(value) _test_DeclaredParentStr(value)
TEST_EXPORT test_DeclaredParent* test_DeclaredParentFromStr(test_DeclaredParent* value, corto_string str);
TEST_EXPORT corto_int16 _test_DeclaredParentCopy(test_DeclaredParent* *dst, test_DeclaredParent* src);
#define test_DeclaredParentCopy(dst, src) _test_DeclaredParentCopy(dst, src)
TEST_EXPORT corto_int16 _test_DeclaredParentCompare(test_DeclaredParent* dst, test_DeclaredParent* src);
#define test_DeclaredParentCompare(dst, src) _test_DeclaredParentCompare(dst, src)

TEST_EXPORT corto_int16 _test_DeclaredParentInit(test_DeclaredParent* value);
#define test_DeclaredParentInit(value) _test_DeclaredParentInit(value)
TEST_EXPORT corto_int16 _test_DeclaredParentDeinit(test_DeclaredParent* value);
#define test_DeclaredParentDeinit(value) _test_DeclaredParentDeinit(value)

/* /test/DefinedParent */
TEST_EXPORT test_DefinedParent* _test_DefinedParentCreate(corto_int32 Foo);
#define test_DefinedParentCreate(Foo) _test_DefinedParentCreate(Foo)
TEST_EXPORT test_DefinedParent* _test_DefinedParentCreateChild(corto_object _parent, corto_string _name, corto_int32 Foo);
#define test_DefinedParentCreateChild(_parent, _name, Foo) _test_DefinedParentCreateChild(_parent, _name, Foo)
TEST_EXPORT corto_int16 _test_DefinedParentUpdate(test_DefinedParent* _this, corto_int32 Foo);
#define test_DefinedParentUpdate(_this, Foo) _test_DefinedParentUpdate(_this, Foo)

TEST_EXPORT test_DefinedParent* _test_DefinedParentDeclare(void);
#define test_DefinedParentDeclare() _test_DefinedParentDeclare()
TEST_EXPORT test_DefinedParent* _test_DefinedParentDeclareChild(corto_object _parent, corto_string _name);
#define test_DefinedParentDeclareChild(_parent, _name) _test_DefinedParentDeclareChild(_parent, _name)
TEST_EXPORT corto_int16 _test_DefinedParentDefine(test_DefinedParent* _this, corto_int32 Foo);
#define test_DefinedParentDefine(_this, Foo) _test_DefinedParentDefine(_this, Foo)
TEST_EXPORT void _test_DefinedParentSet(test_DefinedParent* _this, corto_int32 Foo);
#define test_DefinedParentSet(_this, Foo) _test_DefinedParentSet(_this, Foo)
TEST_EXPORT corto_string _test_DefinedParentStr(test_DefinedParent* value);
#define test_DefinedParentStr(value) _test_DefinedParentStr(value)
TEST_EXPORT test_DefinedParent* test_DefinedParentFromStr(test_DefinedParent* value, corto_string str);
TEST_EXPORT corto_int16 _test_DefinedParentCopy(test_DefinedParent* *dst, test_DefinedParent* src);
#define test_DefinedParentCopy(dst, src) _test_DefinedParentCopy(dst, src)
TEST_EXPORT corto_int16 _test_DefinedParentCompare(test_DefinedParent* dst, test_DefinedParent* src);
#define test_DefinedParentCompare(dst, src) _test_DefinedParentCompare(dst, src)

TEST_EXPORT corto_int16 _test_DefinedParentInit(test_DefinedParent* value);
#define test_DefinedParentInit(value) _test_DefinedParentInit(value)
TEST_EXPORT corto_int16 _test_DefinedParentDeinit(test_DefinedParent* value);
#define test_DefinedParentDeinit(value) _test_DefinedParentDeinit(value)

/* /test/Dog */
TEST_EXPORT test_Dog _test_DogCreate(corto_bool a, corto_bool b);
#define test_DogCreate(a, b) _test_DogCreate(a, b)
TEST_EXPORT test_Dog _test_DogCreateChild(corto_object _parent, corto_string _name, corto_bool a, corto_bool b);
#define test_DogCreateChild(_parent, _name, a, b) _test_DogCreateChild(_parent, _name, a, b)
TEST_EXPORT corto_int16 _test_DogUpdate(test_Dog _this, corto_bool a, corto_bool b);
#define test_DogUpdate(_this, a, b) _test_DogUpdate(test_Dog(_this), a, b)

TEST_EXPORT test_Dog _test_DogDeclare(void);
#define test_DogDeclare() _test_DogDeclare()
TEST_EXPORT test_Dog _test_DogDeclareChild(corto_object _parent, corto_string _name);
#define test_DogDeclareChild(_parent, _name) _test_DogDeclareChild(_parent, _name)
TEST_EXPORT corto_int16 _test_DogDefine(test_Dog _this, corto_bool a, corto_bool b);
#define test_DogDefine(_this, a, b) _test_DogDefine(test_Dog(_this), a, b)
TEST_EXPORT void _test_DogSet(test_Dog _this, corto_bool a, corto_bool b);
#define test_DogSet(_this, a, b) _test_DogSet(test_Dog(_this), a, b)
TEST_EXPORT corto_string _test_DogStr(test_Dog value);
#define test_DogStr(value) _test_DogStr(test_Dog(value))
TEST_EXPORT test_Dog test_DogFromStr(test_Dog value, corto_string str);
TEST_EXPORT corto_int16 _test_DogCopy(test_Dog *dst, test_Dog src);
#define test_DogCopy(dst, src) _test_DogCopy(dst, test_Dog(src))
TEST_EXPORT corto_int16 _test_DogCompare(test_Dog dst, test_Dog src);
#define test_DogCompare(dst, src) _test_DogCompare(test_Dog(dst), test_Dog(src))

/* /test/Env */
TEST_EXPORT test_Env _test_EnvCreate(test_Case test, corto_uint32 assertCount);
#define test_EnvCreate(test, assertCount) _test_EnvCreate(test_Case(test), assertCount)
TEST_EXPORT test_Env _test_EnvCreateChild(corto_object _parent, corto_string _name, test_Case test, corto_uint32 assertCount);
#define test_EnvCreateChild(_parent, _name, test, assertCount) _test_EnvCreateChild(_parent, _name, test_Case(test), assertCount)
TEST_EXPORT corto_int16 _test_EnvUpdate(test_Env _this, test_Case test, corto_uint32 assertCount);
#define test_EnvUpdate(_this, test, assertCount) _test_EnvUpdate(test_Env(_this), test_Case(test), assertCount)

TEST_EXPORT test_Env _test_EnvDeclare(void);
#define test_EnvDeclare() _test_EnvDeclare()
TEST_EXPORT test_Env _test_EnvDeclareChild(corto_object _parent, corto_string _name);
#define test_EnvDeclareChild(_parent, _name) _test_EnvDeclareChild(_parent, _name)
TEST_EXPORT corto_int16 _test_EnvDefine(test_Env _this, test_Case test, corto_uint32 assertCount);
#define test_EnvDefine(_this, test, assertCount) _test_EnvDefine(test_Env(_this), test_Case(test), assertCount)
TEST_EXPORT void _test_EnvSet(test_Env _this, test_Case test, corto_uint32 assertCount);
#define test_EnvSet(_this, test, assertCount) _test_EnvSet(test_Env(_this), test_Case(test), assertCount)
TEST_EXPORT corto_string _test_EnvStr(test_Env value);
#define test_EnvStr(value) _test_EnvStr(test_Env(value))
TEST_EXPORT test_Env test_EnvFromStr(test_Env value, corto_string str);
TEST_EXPORT corto_int16 _test_EnvCopy(test_Env *dst, test_Env src);
#define test_EnvCopy(dst, src) _test_EnvCopy(dst, test_Env(src))
TEST_EXPORT corto_int16 _test_EnvCompare(test_Env dst, test_Env src);
#define test_EnvCompare(dst, src) _test_EnvCompare(test_Env(dst), test_Env(src))

/* /test/Event */
TEST_EXPORT test_Event _test_EventCreate(test_Case test, corto_uint32 assertCount, test_EventTest et, corto_attr prevAttr);
#define test_EventCreate(test, assertCount, et, prevAttr) _test_EventCreate(test_Case(test), assertCount, test_EventTest(et), prevAttr)
TEST_EXPORT test_Event _test_EventCreateChild(corto_object _parent, corto_string _name, test_Case test, corto_uint32 assertCount, test_EventTest et, corto_attr prevAttr);
#define test_EventCreateChild(_parent, _name, test, assertCount, et, prevAttr) _test_EventCreateChild(_parent, _name, test_Case(test), assertCount, test_EventTest(et), prevAttr)
TEST_EXPORT corto_int16 _test_EventUpdate(test_Event _this, test_Case test, corto_uint32 assertCount, test_EventTest et, corto_attr prevAttr);
#define test_EventUpdate(_this, test, assertCount, et, prevAttr) _test_EventUpdate(test_Event(_this), test_Case(test), assertCount, test_EventTest(et), prevAttr)

TEST_EXPORT test_Event _test_EventDeclare(void);
#define test_EventDeclare() _test_EventDeclare()
TEST_EXPORT test_Event _test_EventDeclareChild(corto_object _parent, corto_string _name);
#define test_EventDeclareChild(_parent, _name) _test_EventDeclareChild(_parent, _name)
TEST_EXPORT corto_int16 _test_EventDefine(test_Event _this, test_Case test, corto_uint32 assertCount, test_EventTest et, corto_attr prevAttr);
#define test_EventDefine(_this, test, assertCount, et, prevAttr) _test_EventDefine(test_Event(_this), test_Case(test), assertCount, test_EventTest(et), prevAttr)
TEST_EXPORT void _test_EventSet(test_Event _this, test_Case test, corto_uint32 assertCount, test_EventTest et, corto_attr prevAttr);
#define test_EventSet(_this, test, assertCount, et, prevAttr) _test_EventSet(test_Event(_this), test_Case(test), assertCount, test_EventTest(et), prevAttr)
TEST_EXPORT corto_string _test_EventStr(test_Event value);
#define test_EventStr(value) _test_EventStr(test_Event(value))
TEST_EXPORT test_Event test_EventFromStr(test_Event value, corto_string str);
TEST_EXPORT corto_int16 _test_EventCopy(test_Event *dst, test_Event src);
#define test_EventCopy(dst, src) _test_EventCopy(dst, test_Event(src))
TEST_EXPORT corto_int16 _test_EventCompare(test_Event dst, test_Event src);
#define test_EventCompare(dst, src) _test_EventCompare(test_Event(dst), test_Event(src))

/* /test/EventTest */
TEST_EXPORT test_EventTest _test_EventTestCreate(corto_object scope);
#define test_EventTestCreate(scope) _test_EventTestCreate(scope)
TEST_EXPORT test_EventTest _test_EventTestCreateChild(corto_object _parent, corto_string _name, corto_object scope);
#define test_EventTestCreateChild(_parent, _name, scope) _test_EventTestCreateChild(_parent, _name, scope)
TEST_EXPORT corto_int16 _test_EventTestUpdate(test_EventTest _this, corto_object scope);
#define test_EventTestUpdate(_this, scope) _test_EventTestUpdate(test_EventTest(_this), scope)

TEST_EXPORT test_EventTest _test_EventTestDeclare(void);
#define test_EventTestDeclare() _test_EventTestDeclare()
TEST_EXPORT test_EventTest _test_EventTestDeclareChild(corto_object _parent, corto_string _name);
#define test_EventTestDeclareChild(_parent, _name) _test_EventTestDeclareChild(_parent, _name)
TEST_EXPORT corto_int16 _test_EventTestDefine(test_EventTest _this, corto_object scope);
#define test_EventTestDefine(_this, scope) _test_EventTestDefine(test_EventTest(_this), scope)
TEST_EXPORT void _test_EventTestSet(test_EventTest _this, corto_object scope);
#define test_EventTestSet(_this, scope) _test_EventTestSet(test_EventTest(_this), scope)
TEST_EXPORT corto_string _test_EventTestStr(test_EventTest value);
#define test_EventTestStr(value) _test_EventTestStr(test_EventTest(value))
TEST_EXPORT test_EventTest test_EventTestFromStr(test_EventTest value, corto_string str);
TEST_EXPORT corto_int16 _test_EventTestCopy(test_EventTest *dst, test_EventTest src);
#define test_EventTestCopy(dst, src) _test_EventTestCopy(dst, test_EventTest(src))
TEST_EXPORT corto_int16 _test_EventTestCompare(test_EventTest dst, test_EventTest src);
#define test_EventTestCompare(dst, src) _test_EventTestCompare(test_EventTest(dst), test_EventTest(src))

/* /test/Foo */
TEST_EXPORT test_Foo _test_FooCreate(corto_int32 x, corto_int32 y);
#define test_FooCreate(x, y) _test_FooCreate(x, y)
TEST_EXPORT test_Foo _test_FooCreateChild(corto_object _parent, corto_string _name, corto_int32 x, corto_int32 y);
#define test_FooCreateChild(_parent, _name, x, y) _test_FooCreateChild(_parent, _name, x, y)
TEST_EXPORT corto_int16 _test_FooUpdate(test_Foo _this, corto_int32 x, corto_int32 y);
#define test_FooUpdate(_this, x, y) _test_FooUpdate(test_Foo(_this), x, y)

TEST_EXPORT test_Foo _test_FooDeclare(void);
#define test_FooDeclare() _test_FooDeclare()
TEST_EXPORT test_Foo _test_FooDeclareChild(corto_object _parent, corto_string _name);
#define test_FooDeclareChild(_parent, _name) _test_FooDeclareChild(_parent, _name)
TEST_EXPORT corto_int16 _test_FooDefine(test_Foo _this, corto_int32 x, corto_int32 y);
#define test_FooDefine(_this, x, y) _test_FooDefine(test_Foo(_this), x, y)
TEST_EXPORT void _test_FooSet(test_Foo _this, corto_int32 x, corto_int32 y);
#define test_FooSet(_this, x, y) _test_FooSet(test_Foo(_this), x, y)
TEST_EXPORT corto_string _test_FooStr(test_Foo value);
#define test_FooStr(value) _test_FooStr(test_Foo(value))
TEST_EXPORT test_Foo test_FooFromStr(test_Foo value, corto_string str);
TEST_EXPORT corto_int16 _test_FooCopy(test_Foo *dst, test_Foo src);
#define test_FooCopy(dst, src) _test_FooCopy(dst, test_Foo(src))
TEST_EXPORT corto_int16 _test_FooCompare(test_Foo dst, test_Foo src);
#define test_FooCompare(dst, src) _test_FooCompare(test_Foo(dst), test_Foo(src))

/* /test/Fullname */
TEST_EXPORT test_Fullname _test_FullnameCreate(test_Case test, corto_uint32 assertCount);
#define test_FullnameCreate(test, assertCount) _test_FullnameCreate(test_Case(test), assertCount)
TEST_EXPORT test_Fullname _test_FullnameCreateChild(corto_object _parent, corto_string _name, test_Case test, corto_uint32 assertCount);
#define test_FullnameCreateChild(_parent, _name, test, assertCount) _test_FullnameCreateChild(_parent, _name, test_Case(test), assertCount)
TEST_EXPORT corto_int16 _test_FullnameUpdate(test_Fullname _this, test_Case test, corto_uint32 assertCount);
#define test_FullnameUpdate(_this, test, assertCount) _test_FullnameUpdate(test_Fullname(_this), test_Case(test), assertCount)

TEST_EXPORT test_Fullname _test_FullnameDeclare(void);
#define test_FullnameDeclare() _test_FullnameDeclare()
TEST_EXPORT test_Fullname _test_FullnameDeclareChild(corto_object _parent, corto_string _name);
#define test_FullnameDeclareChild(_parent, _name) _test_FullnameDeclareChild(_parent, _name)
TEST_EXPORT corto_int16 _test_FullnameDefine(test_Fullname _this, test_Case test, corto_uint32 assertCount);
#define test_FullnameDefine(_this, test, assertCount) _test_FullnameDefine(test_Fullname(_this), test_Case(test), assertCount)
TEST_EXPORT void _test_FullnameSet(test_Fullname _this, test_Case test, corto_uint32 assertCount);
#define test_FullnameSet(_this, test, assertCount) _test_FullnameSet(test_Fullname(_this), test_Case(test), assertCount)
TEST_EXPORT corto_string _test_FullnameStr(test_Fullname value);
#define test_FullnameStr(value) _test_FullnameStr(test_Fullname(value))
TEST_EXPORT test_Fullname test_FullnameFromStr(test_Fullname value, corto_string str);
TEST_EXPORT corto_int16 _test_FullnameCopy(test_Fullname *dst, test_Fullname src);
#define test_FullnameCopy(dst, src) _test_FullnameCopy(dst, test_Fullname(src))
TEST_EXPORT corto_int16 _test_FullnameCompare(test_Fullname dst, test_Fullname src);
#define test_FullnameCompare(dst, src) _test_FullnameCompare(test_Fullname(dst), test_Fullname(src))

/* /test/GoldenRetriever */
TEST_EXPORT test_GoldenRetriever _test_GoldenRetrieverCreate(corto_bool a, corto_bool b, corto_bool c);
#define test_GoldenRetrieverCreate(a, b, c) _test_GoldenRetrieverCreate(a, b, c)
TEST_EXPORT test_GoldenRetriever _test_GoldenRetrieverCreateChild(corto_object _parent, corto_string _name, corto_bool a, corto_bool b, corto_bool c);
#define test_GoldenRetrieverCreateChild(_parent, _name, a, b, c) _test_GoldenRetrieverCreateChild(_parent, _name, a, b, c)
TEST_EXPORT corto_int16 _test_GoldenRetrieverUpdate(test_GoldenRetriever _this, corto_bool a, corto_bool b, corto_bool c);
#define test_GoldenRetrieverUpdate(_this, a, b, c) _test_GoldenRetrieverUpdate(test_GoldenRetriever(_this), a, b, c)

TEST_EXPORT test_GoldenRetriever _test_GoldenRetrieverDeclare(void);
#define test_GoldenRetrieverDeclare() _test_GoldenRetrieverDeclare()
TEST_EXPORT test_GoldenRetriever _test_GoldenRetrieverDeclareChild(corto_object _parent, corto_string _name);
#define test_GoldenRetrieverDeclareChild(_parent, _name) _test_GoldenRetrieverDeclareChild(_parent, _name)
TEST_EXPORT corto_int16 _test_GoldenRetrieverDefine(test_GoldenRetriever _this, corto_bool a, corto_bool b, corto_bool c);
#define test_GoldenRetrieverDefine(_this, a, b, c) _test_GoldenRetrieverDefine(test_GoldenRetriever(_this), a, b, c)
TEST_EXPORT void _test_GoldenRetrieverSet(test_GoldenRetriever _this, corto_bool a, corto_bool b, corto_bool c);
#define test_GoldenRetrieverSet(_this, a, b, c) _test_GoldenRetrieverSet(test_GoldenRetriever(_this), a, b, c)
TEST_EXPORT corto_string _test_GoldenRetrieverStr(test_GoldenRetriever value);
#define test_GoldenRetrieverStr(value) _test_GoldenRetrieverStr(test_GoldenRetriever(value))
TEST_EXPORT test_GoldenRetriever test_GoldenRetrieverFromStr(test_GoldenRetriever value, corto_string str);
TEST_EXPORT corto_int16 _test_GoldenRetrieverCopy(test_GoldenRetriever *dst, test_GoldenRetriever src);
#define test_GoldenRetrieverCopy(dst, src) _test_GoldenRetrieverCopy(dst, test_GoldenRetriever(src))
TEST_EXPORT corto_int16 _test_GoldenRetrieverCompare(test_GoldenRetriever dst, test_GoldenRetriever src);
#define test_GoldenRetrieverCompare(dst, src) _test_GoldenRetrieverCompare(test_GoldenRetriever(dst), test_GoldenRetriever(src))

/* /test/Line */
TEST_EXPORT test_Line* _test_LineCreate(test_Point start, test_Point stop);
#define test_LineCreate(start, stop) _test_LineCreate(start, stop)
TEST_EXPORT test_Line* _test_LineCreateChild(corto_object _parent, corto_string _name, test_Point start, test_Point stop);
#define test_LineCreateChild(_parent, _name, start, stop) _test_LineCreateChild(_parent, _name, start, stop)
TEST_EXPORT corto_int16 _test_LineUpdate(test_Line* _this, test_Point start, test_Point stop);
#define test_LineUpdate(_this, start, stop) _test_LineUpdate(_this, start, stop)

TEST_EXPORT test_Line* _test_LineDeclare(void);
#define test_LineDeclare() _test_LineDeclare()
TEST_EXPORT test_Line* _test_LineDeclareChild(corto_object _parent, corto_string _name);
#define test_LineDeclareChild(_parent, _name) _test_LineDeclareChild(_parent, _name)
TEST_EXPORT corto_int16 _test_LineDefine(test_Line* _this, test_Point start, test_Point stop);
#define test_LineDefine(_this, start, stop) _test_LineDefine(_this, start, stop)
TEST_EXPORT void _test_LineSet(test_Line* _this, test_Point start, test_Point stop);
#define test_LineSet(_this, start, stop) _test_LineSet(_this, start, stop)
TEST_EXPORT corto_string _test_LineStr(test_Line* value);
#define test_LineStr(value) _test_LineStr(value)
TEST_EXPORT test_Line* test_LineFromStr(test_Line* value, corto_string str);
TEST_EXPORT corto_int16 _test_LineCopy(test_Line* *dst, test_Line* src);
#define test_LineCopy(dst, src) _test_LineCopy(dst, src)
TEST_EXPORT corto_int16 _test_LineCompare(test_Line* dst, test_Line* src);
#define test_LineCompare(dst, src) _test_LineCompare(dst, src)

TEST_EXPORT corto_int16 _test_LineInit(test_Line* value);
#define test_LineInit(value) _test_LineInit(value)
TEST_EXPORT corto_int16 _test_LineDeinit(test_Line* value);
#define test_LineDeinit(value) _test_LineDeinit(value)

/* /test/MethodResolver */
TEST_EXPORT test_MethodResolver _test_MethodResolverCreate(test_Case test, corto_uint32 assertCount);
#define test_MethodResolverCreate(test, assertCount) _test_MethodResolverCreate(test_Case(test), assertCount)
TEST_EXPORT test_MethodResolver _test_MethodResolverCreateChild(corto_object _parent, corto_string _name, test_Case test, corto_uint32 assertCount);
#define test_MethodResolverCreateChild(_parent, _name, test, assertCount) _test_MethodResolverCreateChild(_parent, _name, test_Case(test), assertCount)
TEST_EXPORT corto_int16 _test_MethodResolverUpdate(test_MethodResolver _this, test_Case test, corto_uint32 assertCount);
#define test_MethodResolverUpdate(_this, test, assertCount) _test_MethodResolverUpdate(test_MethodResolver(_this), test_Case(test), assertCount)

TEST_EXPORT test_MethodResolver _test_MethodResolverDeclare(void);
#define test_MethodResolverDeclare() _test_MethodResolverDeclare()
TEST_EXPORT test_MethodResolver _test_MethodResolverDeclareChild(corto_object _parent, corto_string _name);
#define test_MethodResolverDeclareChild(_parent, _name) _test_MethodResolverDeclareChild(_parent, _name)
TEST_EXPORT corto_int16 _test_MethodResolverDefine(test_MethodResolver _this, test_Case test, corto_uint32 assertCount);
#define test_MethodResolverDefine(_this, test, assertCount) _test_MethodResolverDefine(test_MethodResolver(_this), test_Case(test), assertCount)
TEST_EXPORT void _test_MethodResolverSet(test_MethodResolver _this, test_Case test, corto_uint32 assertCount);
#define test_MethodResolverSet(_this, test, assertCount) _test_MethodResolverSet(test_MethodResolver(_this), test_Case(test), assertCount)
TEST_EXPORT corto_string _test_MethodResolverStr(test_MethodResolver value);
#define test_MethodResolverStr(value) _test_MethodResolverStr(test_MethodResolver(value))
TEST_EXPORT test_MethodResolver test_MethodResolverFromStr(test_MethodResolver value, corto_string str);
TEST_EXPORT corto_int16 _test_MethodResolverCopy(test_MethodResolver *dst, test_MethodResolver src);
#define test_MethodResolverCopy(dst, src) _test_MethodResolverCopy(dst, test_MethodResolver(src))
TEST_EXPORT corto_int16 _test_MethodResolverCompare(test_MethodResolver dst, test_MethodResolver src);
#define test_MethodResolverCompare(dst, src) _test_MethodResolverCompare(test_MethodResolver(dst), test_MethodResolver(src))

/* /test/MethodTester */
TEST_EXPORT test_MethodTester _test_MethodTesterCreate(void);
#define test_MethodTesterCreate() _test_MethodTesterCreate()
TEST_EXPORT test_MethodTester _test_MethodTesterCreateChild(corto_object _parent, corto_string _name);
#define test_MethodTesterCreateChild(_parent, _name) _test_MethodTesterCreateChild(_parent, _name)
TEST_EXPORT corto_int16 _test_MethodTesterUpdate(test_MethodTester _this);
#define test_MethodTesterUpdate(_this) _test_MethodTesterUpdate(test_MethodTester(_this))

TEST_EXPORT test_MethodTester _test_MethodTesterDeclare(void);
#define test_MethodTesterDeclare() _test_MethodTesterDeclare()
TEST_EXPORT test_MethodTester _test_MethodTesterDeclareChild(corto_object _parent, corto_string _name);
#define test_MethodTesterDeclareChild(_parent, _name) _test_MethodTesterDeclareChild(_parent, _name)
TEST_EXPORT corto_int16 _test_MethodTesterDefine(test_MethodTester _this);
#define test_MethodTesterDefine(_this) _test_MethodTesterDefine(test_MethodTester(_this))
TEST_EXPORT void _test_MethodTesterSet(test_MethodTester _this);
#define test_MethodTesterSet(_this) _test_MethodTesterSet(test_MethodTester(_this))
TEST_EXPORT corto_string _test_MethodTesterStr(test_MethodTester value);
#define test_MethodTesterStr(value) _test_MethodTesterStr(test_MethodTester(value))
TEST_EXPORT test_MethodTester test_MethodTesterFromStr(test_MethodTester value, corto_string str);
TEST_EXPORT corto_int16 _test_MethodTesterCopy(test_MethodTester *dst, test_MethodTester src);
#define test_MethodTesterCopy(dst, src) _test_MethodTesterCopy(dst, test_MethodTester(src))
TEST_EXPORT corto_int16 _test_MethodTesterCompare(test_MethodTester dst, test_MethodTester src);
#define test_MethodTesterCompare(dst, src) _test_MethodTesterCompare(test_MethodTester(dst), test_MethodTester(src))

/* /test/MethodTesterInherit */
TEST_EXPORT test_MethodTesterInherit _test_MethodTesterInheritCreate(void);
#define test_MethodTesterInheritCreate() _test_MethodTesterInheritCreate()
TEST_EXPORT test_MethodTesterInherit _test_MethodTesterInheritCreateChild(corto_object _parent, corto_string _name);
#define test_MethodTesterInheritCreateChild(_parent, _name) _test_MethodTesterInheritCreateChild(_parent, _name)
TEST_EXPORT corto_int16 _test_MethodTesterInheritUpdate(test_MethodTesterInherit _this);
#define test_MethodTesterInheritUpdate(_this) _test_MethodTesterInheritUpdate(test_MethodTesterInherit(_this))

TEST_EXPORT test_MethodTesterInherit _test_MethodTesterInheritDeclare(void);
#define test_MethodTesterInheritDeclare() _test_MethodTesterInheritDeclare()
TEST_EXPORT test_MethodTesterInherit _test_MethodTesterInheritDeclareChild(corto_object _parent, corto_string _name);
#define test_MethodTesterInheritDeclareChild(_parent, _name) _test_MethodTesterInheritDeclareChild(_parent, _name)
TEST_EXPORT corto_int16 _test_MethodTesterInheritDefine(test_MethodTesterInherit _this);
#define test_MethodTesterInheritDefine(_this) _test_MethodTesterInheritDefine(test_MethodTesterInherit(_this))
TEST_EXPORT void _test_MethodTesterInheritSet(test_MethodTesterInherit _this);
#define test_MethodTesterInheritSet(_this) _test_MethodTesterInheritSet(test_MethodTesterInherit(_this))
TEST_EXPORT corto_string _test_MethodTesterInheritStr(test_MethodTesterInherit value);
#define test_MethodTesterInheritStr(value) _test_MethodTesterInheritStr(test_MethodTesterInherit(value))
TEST_EXPORT test_MethodTesterInherit test_MethodTesterInheritFromStr(test_MethodTesterInherit value, corto_string str);
TEST_EXPORT corto_int16 _test_MethodTesterInheritCopy(test_MethodTesterInherit *dst, test_MethodTesterInherit src);
#define test_MethodTesterInheritCopy(dst, src) _test_MethodTesterInheritCopy(dst, test_MethodTesterInherit(src))
TEST_EXPORT corto_int16 _test_MethodTesterInheritCompare(test_MethodTesterInherit dst, test_MethodTesterInherit src);
#define test_MethodTesterInheritCompare(dst, src) _test_MethodTesterInheritCompare(test_MethodTesterInherit(dst), test_MethodTesterInherit(src))

/* /test/ObjectMgmt */
TEST_EXPORT test_ObjectMgmt _test_ObjectMgmtCreate(test_Case test, corto_uint32 assertCount);
#define test_ObjectMgmtCreate(test, assertCount) _test_ObjectMgmtCreate(test_Case(test), assertCount)
TEST_EXPORT test_ObjectMgmt _test_ObjectMgmtCreateChild(corto_object _parent, corto_string _name, test_Case test, corto_uint32 assertCount);
#define test_ObjectMgmtCreateChild(_parent, _name, test, assertCount) _test_ObjectMgmtCreateChild(_parent, _name, test_Case(test), assertCount)
TEST_EXPORT corto_int16 _test_ObjectMgmtUpdate(test_ObjectMgmt _this, test_Case test, corto_uint32 assertCount);
#define test_ObjectMgmtUpdate(_this, test, assertCount) _test_ObjectMgmtUpdate(test_ObjectMgmt(_this), test_Case(test), assertCount)

TEST_EXPORT test_ObjectMgmt _test_ObjectMgmtDeclare(void);
#define test_ObjectMgmtDeclare() _test_ObjectMgmtDeclare()
TEST_EXPORT test_ObjectMgmt _test_ObjectMgmtDeclareChild(corto_object _parent, corto_string _name);
#define test_ObjectMgmtDeclareChild(_parent, _name) _test_ObjectMgmtDeclareChild(_parent, _name)
TEST_EXPORT corto_int16 _test_ObjectMgmtDefine(test_ObjectMgmt _this, test_Case test, corto_uint32 assertCount);
#define test_ObjectMgmtDefine(_this, test, assertCount) _test_ObjectMgmtDefine(test_ObjectMgmt(_this), test_Case(test), assertCount)
TEST_EXPORT void _test_ObjectMgmtSet(test_ObjectMgmt _this, test_Case test, corto_uint32 assertCount);
#define test_ObjectMgmtSet(_this, test, assertCount) _test_ObjectMgmtSet(test_ObjectMgmt(_this), test_Case(test), assertCount)
TEST_EXPORT corto_string _test_ObjectMgmtStr(test_ObjectMgmt value);
#define test_ObjectMgmtStr(value) _test_ObjectMgmtStr(test_ObjectMgmt(value))
TEST_EXPORT test_ObjectMgmt test_ObjectMgmtFromStr(test_ObjectMgmt value, corto_string str);
TEST_EXPORT corto_int16 _test_ObjectMgmtCopy(test_ObjectMgmt *dst, test_ObjectMgmt src);
#define test_ObjectMgmtCopy(dst, src) _test_ObjectMgmtCopy(dst, test_ObjectMgmt(src))
TEST_EXPORT corto_int16 _test_ObjectMgmtCompare(test_ObjectMgmt dst, test_ObjectMgmt src);
#define test_ObjectMgmtCompare(dst, src) _test_ObjectMgmtCompare(test_ObjectMgmt(dst), test_ObjectMgmt(src))

/* /test/Overload */
TEST_EXPORT test_Overload _test_OverloadCreate(test_Case test, corto_uint32 assertCount);
#define test_OverloadCreate(test, assertCount) _test_OverloadCreate(test_Case(test), assertCount)
TEST_EXPORT test_Overload _test_OverloadCreateChild(corto_object _parent, corto_string _name, test_Case test, corto_uint32 assertCount);
#define test_OverloadCreateChild(_parent, _name, test, assertCount) _test_OverloadCreateChild(_parent, _name, test_Case(test), assertCount)
TEST_EXPORT corto_int16 _test_OverloadUpdate(test_Overload _this, test_Case test, corto_uint32 assertCount);
#define test_OverloadUpdate(_this, test, assertCount) _test_OverloadUpdate(test_Overload(_this), test_Case(test), assertCount)

TEST_EXPORT test_Overload _test_OverloadDeclare(void);
#define test_OverloadDeclare() _test_OverloadDeclare()
TEST_EXPORT test_Overload _test_OverloadDeclareChild(corto_object _parent, corto_string _name);
#define test_OverloadDeclareChild(_parent, _name) _test_OverloadDeclareChild(_parent, _name)
TEST_EXPORT corto_int16 _test_OverloadDefine(test_Overload _this, test_Case test, corto_uint32 assertCount);
#define test_OverloadDefine(_this, test, assertCount) _test_OverloadDefine(test_Overload(_this), test_Case(test), assertCount)
TEST_EXPORT void _test_OverloadSet(test_Overload _this, test_Case test, corto_uint32 assertCount);
#define test_OverloadSet(_this, test, assertCount) _test_OverloadSet(test_Overload(_this), test_Case(test), assertCount)
TEST_EXPORT corto_string _test_OverloadStr(test_Overload value);
#define test_OverloadStr(value) _test_OverloadStr(test_Overload(value))
TEST_EXPORT test_Overload test_OverloadFromStr(test_Overload value, corto_string str);
TEST_EXPORT corto_int16 _test_OverloadCopy(test_Overload *dst, test_Overload src);
#define test_OverloadCopy(dst, src) _test_OverloadCopy(dst, test_Overload(src))
TEST_EXPORT corto_int16 _test_OverloadCompare(test_Overload dst, test_Overload src);
#define test_OverloadCompare(dst, src) _test_OverloadCompare(test_Overload(dst), test_Overload(src))

/* /test/Point */
TEST_EXPORT test_Point* _test_PointCreate(corto_int32 x, corto_int32 y);
#define test_PointCreate(x, y) _test_PointCreate(x, y)
TEST_EXPORT test_Point* _test_PointCreateChild(corto_object _parent, corto_string _name, corto_int32 x, corto_int32 y);
#define test_PointCreateChild(_parent, _name, x, y) _test_PointCreateChild(_parent, _name, x, y)
TEST_EXPORT corto_int16 _test_PointUpdate(test_Point* _this, corto_int32 x, corto_int32 y);
#define test_PointUpdate(_this, x, y) _test_PointUpdate(_this, x, y)

TEST_EXPORT test_Point* _test_PointDeclare(void);
#define test_PointDeclare() _test_PointDeclare()
TEST_EXPORT test_Point* _test_PointDeclareChild(corto_object _parent, corto_string _name);
#define test_PointDeclareChild(_parent, _name) _test_PointDeclareChild(_parent, _name)
TEST_EXPORT corto_int16 _test_PointDefine(test_Point* _this, corto_int32 x, corto_int32 y);
#define test_PointDefine(_this, x, y) _test_PointDefine(_this, x, y)
TEST_EXPORT void _test_PointSet(test_Point* _this, corto_int32 x, corto_int32 y);
#define test_PointSet(_this, x, y) _test_PointSet(_this, x, y)
TEST_EXPORT corto_string _test_PointStr(test_Point* value);
#define test_PointStr(value) _test_PointStr(value)
TEST_EXPORT test_Point* test_PointFromStr(test_Point* value, corto_string str);
TEST_EXPORT corto_int16 _test_PointCopy(test_Point* *dst, test_Point* src);
#define test_PointCopy(dst, src) _test_PointCopy(dst, src)
TEST_EXPORT corto_int16 _test_PointCompare(test_Point* dst, test_Point* src);
#define test_PointCompare(dst, src) _test_PointCompare(dst, src)

TEST_EXPORT corto_int16 _test_PointInit(test_Point* value);
#define test_PointInit(value) _test_PointInit(value)
TEST_EXPORT corto_int16 _test_PointDeinit(test_Point* value);
#define test_PointDeinit(value) _test_PointDeinit(value)

/* /test/Point3D */
TEST_EXPORT test_Point3D* _test_Point3DCreate(corto_int32 x, corto_int32 y, corto_int32 z);
#define test_Point3DCreate(x, y, z) _test_Point3DCreate(x, y, z)
TEST_EXPORT test_Point3D* _test_Point3DCreateChild(corto_object _parent, corto_string _name, corto_int32 x, corto_int32 y, corto_int32 z);
#define test_Point3DCreateChild(_parent, _name, x, y, z) _test_Point3DCreateChild(_parent, _name, x, y, z)
TEST_EXPORT corto_int16 _test_Point3DUpdate(test_Point3D* _this, corto_int32 x, corto_int32 y, corto_int32 z);
#define test_Point3DUpdate(_this, x, y, z) _test_Point3DUpdate(_this, x, y, z)

TEST_EXPORT test_Point3D* _test_Point3DDeclare(void);
#define test_Point3DDeclare() _test_Point3DDeclare()
TEST_EXPORT test_Point3D* _test_Point3DDeclareChild(corto_object _parent, corto_string _name);
#define test_Point3DDeclareChild(_parent, _name) _test_Point3DDeclareChild(_parent, _name)
TEST_EXPORT corto_int16 _test_Point3DDefine(test_Point3D* _this, corto_int32 x, corto_int32 y, corto_int32 z);
#define test_Point3DDefine(_this, x, y, z) _test_Point3DDefine(_this, x, y, z)
TEST_EXPORT void _test_Point3DSet(test_Point3D* _this, corto_int32 x, corto_int32 y, corto_int32 z);
#define test_Point3DSet(_this, x, y, z) _test_Point3DSet(_this, x, y, z)
TEST_EXPORT corto_string _test_Point3DStr(test_Point3D* value);
#define test_Point3DStr(value) _test_Point3DStr(value)
TEST_EXPORT test_Point3D* test_Point3DFromStr(test_Point3D* value, corto_string str);
TEST_EXPORT corto_int16 _test_Point3DCopy(test_Point3D* *dst, test_Point3D* src);
#define test_Point3DCopy(dst, src) _test_Point3DCopy(dst, src)
TEST_EXPORT corto_int16 _test_Point3DCompare(test_Point3D* dst, test_Point3D* src);
#define test_Point3DCompare(dst, src) _test_Point3DCompare(dst, src)

TEST_EXPORT corto_int16 _test_Point3DInit(test_Point3D* value);
#define test_Point3DInit(value) _test_Point3DInit(value)
TEST_EXPORT corto_int16 _test_Point3DDeinit(test_Point3D* value);
#define test_Point3DDeinit(value) _test_Point3DDeinit(value)

/* /test/PrimitiveCollection */
TEST_EXPORT test_PrimitiveCollection* _test_PrimitiveCollectionCreate(corto_int32List ints);
#define test_PrimitiveCollectionCreate(ints) _test_PrimitiveCollectionCreate(ints)
TEST_EXPORT test_PrimitiveCollection* _test_PrimitiveCollectionCreateChild(corto_object _parent, corto_string _name, corto_int32List ints);
#define test_PrimitiveCollectionCreateChild(_parent, _name, ints) _test_PrimitiveCollectionCreateChild(_parent, _name, ints)
TEST_EXPORT corto_int16 _test_PrimitiveCollectionUpdate(test_PrimitiveCollection* _this, corto_int32List ints);
#define test_PrimitiveCollectionUpdate(_this, ints) _test_PrimitiveCollectionUpdate(_this, ints)

TEST_EXPORT test_PrimitiveCollection* _test_PrimitiveCollectionDeclare(void);
#define test_PrimitiveCollectionDeclare() _test_PrimitiveCollectionDeclare()
TEST_EXPORT test_PrimitiveCollection* _test_PrimitiveCollectionDeclareChild(corto_object _parent, corto_string _name);
#define test_PrimitiveCollectionDeclareChild(_parent, _name) _test_PrimitiveCollectionDeclareChild(_parent, _name)
TEST_EXPORT corto_int16 _test_PrimitiveCollectionDefine(test_PrimitiveCollection* _this, corto_int32List ints);
#define test_PrimitiveCollectionDefine(_this, ints) _test_PrimitiveCollectionDefine(_this, ints)
TEST_EXPORT void _test_PrimitiveCollectionSet(test_PrimitiveCollection* _this, corto_int32List ints);
#define test_PrimitiveCollectionSet(_this, ints) _test_PrimitiveCollectionSet(_this, ints)
TEST_EXPORT corto_string _test_PrimitiveCollectionStr(test_PrimitiveCollection* value);
#define test_PrimitiveCollectionStr(value) _test_PrimitiveCollectionStr(value)
TEST_EXPORT test_PrimitiveCollection* test_PrimitiveCollectionFromStr(test_PrimitiveCollection* value, corto_string str);
TEST_EXPORT corto_int16 _test_PrimitiveCollectionCopy(test_PrimitiveCollection* *dst, test_PrimitiveCollection* src);
#define test_PrimitiveCollectionCopy(dst, src) _test_PrimitiveCollectionCopy(dst, src)
TEST_EXPORT corto_int16 _test_PrimitiveCollectionCompare(test_PrimitiveCollection* dst, test_PrimitiveCollection* src);
#define test_PrimitiveCollectionCompare(dst, src) _test_PrimitiveCollectionCompare(dst, src)

TEST_EXPORT corto_int16 _test_PrimitiveCollectionInit(test_PrimitiveCollection* value);
#define test_PrimitiveCollectionInit(value) _test_PrimitiveCollectionInit(value)
TEST_EXPORT corto_int16 _test_PrimitiveCollectionDeinit(test_PrimitiveCollection* value);
#define test_PrimitiveCollectionDeinit(value) _test_PrimitiveCollectionDeinit(value)

/* /test/Project */
TEST_EXPORT test_Project _test_ProjectCreate(test_Case test, corto_uint32 assertCount);
#define test_ProjectCreate(test, assertCount) _test_ProjectCreate(test_Case(test), assertCount)
TEST_EXPORT test_Project _test_ProjectCreateChild(corto_object _parent, corto_string _name, test_Case test, corto_uint32 assertCount);
#define test_ProjectCreateChild(_parent, _name, test, assertCount) _test_ProjectCreateChild(_parent, _name, test_Case(test), assertCount)
TEST_EXPORT corto_int16 _test_ProjectUpdate(test_Project _this, test_Case test, corto_uint32 assertCount);
#define test_ProjectUpdate(_this, test, assertCount) _test_ProjectUpdate(test_Project(_this), test_Case(test), assertCount)

TEST_EXPORT test_Project _test_ProjectDeclare(void);
#define test_ProjectDeclare() _test_ProjectDeclare()
TEST_EXPORT test_Project _test_ProjectDeclareChild(corto_object _parent, corto_string _name);
#define test_ProjectDeclareChild(_parent, _name) _test_ProjectDeclareChild(_parent, _name)
TEST_EXPORT corto_int16 _test_ProjectDefine(test_Project _this, test_Case test, corto_uint32 assertCount);
#define test_ProjectDefine(_this, test, assertCount) _test_ProjectDefine(test_Project(_this), test_Case(test), assertCount)
TEST_EXPORT void _test_ProjectSet(test_Project _this, test_Case test, corto_uint32 assertCount);
#define test_ProjectSet(_this, test, assertCount) _test_ProjectSet(test_Project(_this), test_Case(test), assertCount)
TEST_EXPORT corto_string _test_ProjectStr(test_Project value);
#define test_ProjectStr(value) _test_ProjectStr(test_Project(value))
TEST_EXPORT test_Project test_ProjectFromStr(test_Project value, corto_string str);
TEST_EXPORT corto_int16 _test_ProjectCopy(test_Project *dst, test_Project src);
#define test_ProjectCopy(dst, src) _test_ProjectCopy(dst, test_Project(src))
TEST_EXPORT corto_int16 _test_ProjectCompare(test_Project dst, test_Project src);
#define test_ProjectCompare(dst, src) _test_ProjectCompare(test_Project(dst), test_Project(src))

/* /test/RelativeName */
TEST_EXPORT test_RelativeName _test_RelativeNameCreate(test_Case test, corto_uint32 assertCount, corto_object tier1, corto_object tier2, corto_object tier3, corto_object obj, corto_object disjunct, corto_object child);
#define test_RelativeNameCreate(test, assertCount, tier1, tier2, tier3, obj, disjunct, child) _test_RelativeNameCreate(test_Case(test), assertCount, tier1, tier2, tier3, obj, disjunct, child)
TEST_EXPORT test_RelativeName _test_RelativeNameCreateChild(corto_object _parent, corto_string _name, test_Case test, corto_uint32 assertCount, corto_object tier1, corto_object tier2, corto_object tier3, corto_object obj, corto_object disjunct, corto_object child);
#define test_RelativeNameCreateChild(_parent, _name, test, assertCount, tier1, tier2, tier3, obj, disjunct, child) _test_RelativeNameCreateChild(_parent, _name, test_Case(test), assertCount, tier1, tier2, tier3, obj, disjunct, child)
TEST_EXPORT corto_int16 _test_RelativeNameUpdate(test_RelativeName _this, test_Case test, corto_uint32 assertCount, corto_object tier1, corto_object tier2, corto_object tier3, corto_object obj, corto_object disjunct, corto_object child);
#define test_RelativeNameUpdate(_this, test, assertCount, tier1, tier2, tier3, obj, disjunct, child) _test_RelativeNameUpdate(test_RelativeName(_this), test_Case(test), assertCount, tier1, tier2, tier3, obj, disjunct, child)

TEST_EXPORT test_RelativeName _test_RelativeNameDeclare(void);
#define test_RelativeNameDeclare() _test_RelativeNameDeclare()
TEST_EXPORT test_RelativeName _test_RelativeNameDeclareChild(corto_object _parent, corto_string _name);
#define test_RelativeNameDeclareChild(_parent, _name) _test_RelativeNameDeclareChild(_parent, _name)
TEST_EXPORT corto_int16 _test_RelativeNameDefine(test_RelativeName _this, test_Case test, corto_uint32 assertCount, corto_object tier1, corto_object tier2, corto_object tier3, corto_object obj, corto_object disjunct, corto_object child);
#define test_RelativeNameDefine(_this, test, assertCount, tier1, tier2, tier3, obj, disjunct, child) _test_RelativeNameDefine(test_RelativeName(_this), test_Case(test), assertCount, tier1, tier2, tier3, obj, disjunct, child)
TEST_EXPORT void _test_RelativeNameSet(test_RelativeName _this, test_Case test, corto_uint32 assertCount, corto_object tier1, corto_object tier2, corto_object tier3, corto_object obj, corto_object disjunct, corto_object child);
#define test_RelativeNameSet(_this, test, assertCount, tier1, tier2, tier3, obj, disjunct, child) _test_RelativeNameSet(test_RelativeName(_this), test_Case(test), assertCount, tier1, tier2, tier3, obj, disjunct, child)
TEST_EXPORT corto_string _test_RelativeNameStr(test_RelativeName value);
#define test_RelativeNameStr(value) _test_RelativeNameStr(test_RelativeName(value))
TEST_EXPORT test_RelativeName test_RelativeNameFromStr(test_RelativeName value, corto_string str);
TEST_EXPORT corto_int16 _test_RelativeNameCopy(test_RelativeName *dst, test_RelativeName src);
#define test_RelativeNameCopy(dst, src) _test_RelativeNameCopy(dst, test_RelativeName(src))
TEST_EXPORT corto_int16 _test_RelativeNameCompare(test_RelativeName dst, test_RelativeName src);
#define test_RelativeNameCompare(dst, src) _test_RelativeNameCompare(test_RelativeName(dst), test_RelativeName(src))

/* /test/Resolver */
TEST_EXPORT test_Resolver _test_ResolverCreate(test_Case test, corto_uint32 assertCount);
#define test_ResolverCreate(test, assertCount) _test_ResolverCreate(test_Case(test), assertCount)
TEST_EXPORT test_Resolver _test_ResolverCreateChild(corto_object _parent, corto_string _name, test_Case test, corto_uint32 assertCount);
#define test_ResolverCreateChild(_parent, _name, test, assertCount) _test_ResolverCreateChild(_parent, _name, test_Case(test), assertCount)
TEST_EXPORT corto_int16 _test_ResolverUpdate(test_Resolver _this, test_Case test, corto_uint32 assertCount);
#define test_ResolverUpdate(_this, test, assertCount) _test_ResolverUpdate(test_Resolver(_this), test_Case(test), assertCount)

TEST_EXPORT test_Resolver _test_ResolverDeclare(void);
#define test_ResolverDeclare() _test_ResolverDeclare()
TEST_EXPORT test_Resolver _test_ResolverDeclareChild(corto_object _parent, corto_string _name);
#define test_ResolverDeclareChild(_parent, _name) _test_ResolverDeclareChild(_parent, _name)
TEST_EXPORT corto_int16 _test_ResolverDefine(test_Resolver _this, test_Case test, corto_uint32 assertCount);
#define test_ResolverDefine(_this, test, assertCount) _test_ResolverDefine(test_Resolver(_this), test_Case(test), assertCount)
TEST_EXPORT void _test_ResolverSet(test_Resolver _this, test_Case test, corto_uint32 assertCount);
#define test_ResolverSet(_this, test, assertCount) _test_ResolverSet(test_Resolver(_this), test_Case(test), assertCount)
TEST_EXPORT corto_string _test_ResolverStr(test_Resolver value);
#define test_ResolverStr(value) _test_ResolverStr(test_Resolver(value))
TEST_EXPORT test_Resolver test_ResolverFromStr(test_Resolver value, corto_string str);
TEST_EXPORT corto_int16 _test_ResolverCopy(test_Resolver *dst, test_Resolver src);
#define test_ResolverCopy(dst, src) _test_ResolverCopy(dst, test_Resolver(src))
TEST_EXPORT corto_int16 _test_ResolverCompare(test_Resolver dst, test_Resolver src);
#define test_ResolverCompare(dst, src) _test_ResolverCompare(test_Resolver(dst), test_Resolver(src))

/* /test/Select */
TEST_EXPORT test_Select _test_SelectCreate(test_Case test, corto_uint32 assertCount);
#define test_SelectCreate(test, assertCount) _test_SelectCreate(test_Case(test), assertCount)
TEST_EXPORT test_Select _test_SelectCreateChild(corto_object _parent, corto_string _name, test_Case test, corto_uint32 assertCount);
#define test_SelectCreateChild(_parent, _name, test, assertCount) _test_SelectCreateChild(_parent, _name, test_Case(test), assertCount)
TEST_EXPORT corto_int16 _test_SelectUpdate(test_Select _this, test_Case test, corto_uint32 assertCount);
#define test_SelectUpdate(_this, test, assertCount) _test_SelectUpdate(test_Select(_this), test_Case(test), assertCount)

TEST_EXPORT test_Select _test_SelectDeclare(void);
#define test_SelectDeclare() _test_SelectDeclare()
TEST_EXPORT test_Select _test_SelectDeclareChild(corto_object _parent, corto_string _name);
#define test_SelectDeclareChild(_parent, _name) _test_SelectDeclareChild(_parent, _name)
TEST_EXPORT corto_int16 _test_SelectDefine(test_Select _this, test_Case test, corto_uint32 assertCount);
#define test_SelectDefine(_this, test, assertCount) _test_SelectDefine(test_Select(_this), test_Case(test), assertCount)
TEST_EXPORT void _test_SelectSet(test_Select _this, test_Case test, corto_uint32 assertCount);
#define test_SelectSet(_this, test, assertCount) _test_SelectSet(test_Select(_this), test_Case(test), assertCount)
TEST_EXPORT corto_string _test_SelectStr(test_Select value);
#define test_SelectStr(value) _test_SelectStr(test_Select(value))
TEST_EXPORT test_Select test_SelectFromStr(test_Select value, corto_string str);
TEST_EXPORT corto_int16 _test_SelectCopy(test_Select *dst, test_Select src);
#define test_SelectCopy(dst, src) _test_SelectCopy(dst, test_Select(src))
TEST_EXPORT corto_int16 _test_SelectCompare(test_Select dst, test_Select src);
#define test_SelectCompare(dst, src) _test_SelectCompare(test_Select(dst), test_Select(src))

/* /test/selectItem */
TEST_EXPORT test_selectItem* _test_selectItemCreate(corto_string parent, corto_string name, corto_string type);
#define test_selectItemCreate(parent, name, type) _test_selectItemCreate(parent, name, type)
TEST_EXPORT test_selectItem* _test_selectItemCreateChild(corto_object _parent, corto_string _name, corto_string parent, corto_string name, corto_string type);
#define test_selectItemCreateChild(_parent, _name, parent, name, type) _test_selectItemCreateChild(_parent, _name, parent, name, type)
TEST_EXPORT corto_int16 _test_selectItemUpdate(test_selectItem* _this, corto_string parent, corto_string name, corto_string type);
#define test_selectItemUpdate(_this, parent, name, type) _test_selectItemUpdate(_this, parent, name, type)

TEST_EXPORT test_selectItem* _test_selectItemDeclare(void);
#define test_selectItemDeclare() _test_selectItemDeclare()
TEST_EXPORT test_selectItem* _test_selectItemDeclareChild(corto_object _parent, corto_string _name);
#define test_selectItemDeclareChild(_parent, _name) _test_selectItemDeclareChild(_parent, _name)
TEST_EXPORT corto_int16 _test_selectItemDefine(test_selectItem* _this, corto_string parent, corto_string name, corto_string type);
#define test_selectItemDefine(_this, parent, name, type) _test_selectItemDefine(_this, parent, name, type)
TEST_EXPORT void _test_selectItemSet(test_selectItem* _this, corto_string parent, corto_string name, corto_string type);
#define test_selectItemSet(_this, parent, name, type) _test_selectItemSet(_this, parent, name, type)
TEST_EXPORT corto_string _test_selectItemStr(test_selectItem* value);
#define test_selectItemStr(value) _test_selectItemStr(value)
TEST_EXPORT test_selectItem* test_selectItemFromStr(test_selectItem* value, corto_string str);
TEST_EXPORT corto_int16 _test_selectItemCopy(test_selectItem* *dst, test_selectItem* src);
#define test_selectItemCopy(dst, src) _test_selectItemCopy(dst, src)
TEST_EXPORT corto_int16 _test_selectItemCompare(test_selectItem* dst, test_selectItem* src);
#define test_selectItemCompare(dst, src) _test_selectItemCompare(dst, src)

TEST_EXPORT corto_int16 _test_selectItemInit(test_selectItem* value);
#define test_selectItemInit(value) _test_selectItemInit(value)
TEST_EXPORT corto_int16 _test_selectItemDeinit(test_selectItem* value);
#define test_selectItemDeinit(value) _test_selectItemDeinit(value)

/* /test/StringDeserializer */
TEST_EXPORT test_StringDeserializer _test_StringDeserializerCreate(test_Case test, corto_uint32 assertCount);
#define test_StringDeserializerCreate(test, assertCount) _test_StringDeserializerCreate(test_Case(test), assertCount)
TEST_EXPORT test_StringDeserializer _test_StringDeserializerCreateChild(corto_object _parent, corto_string _name, test_Case test, corto_uint32 assertCount);
#define test_StringDeserializerCreateChild(_parent, _name, test, assertCount) _test_StringDeserializerCreateChild(_parent, _name, test_Case(test), assertCount)
TEST_EXPORT corto_int16 _test_StringDeserializerUpdate(test_StringDeserializer _this, test_Case test, corto_uint32 assertCount);
#define test_StringDeserializerUpdate(_this, test, assertCount) _test_StringDeserializerUpdate(test_StringDeserializer(_this), test_Case(test), assertCount)

TEST_EXPORT test_StringDeserializer _test_StringDeserializerDeclare(void);
#define test_StringDeserializerDeclare() _test_StringDeserializerDeclare()
TEST_EXPORT test_StringDeserializer _test_StringDeserializerDeclareChild(corto_object _parent, corto_string _name);
#define test_StringDeserializerDeclareChild(_parent, _name) _test_StringDeserializerDeclareChild(_parent, _name)
TEST_EXPORT corto_int16 _test_StringDeserializerDefine(test_StringDeserializer _this, test_Case test, corto_uint32 assertCount);
#define test_StringDeserializerDefine(_this, test, assertCount) _test_StringDeserializerDefine(test_StringDeserializer(_this), test_Case(test), assertCount)
TEST_EXPORT void _test_StringDeserializerSet(test_StringDeserializer _this, test_Case test, corto_uint32 assertCount);
#define test_StringDeserializerSet(_this, test, assertCount) _test_StringDeserializerSet(test_StringDeserializer(_this), test_Case(test), assertCount)
TEST_EXPORT corto_string _test_StringDeserializerStr(test_StringDeserializer value);
#define test_StringDeserializerStr(value) _test_StringDeserializerStr(test_StringDeserializer(value))
TEST_EXPORT test_StringDeserializer test_StringDeserializerFromStr(test_StringDeserializer value, corto_string str);
TEST_EXPORT corto_int16 _test_StringDeserializerCopy(test_StringDeserializer *dst, test_StringDeserializer src);
#define test_StringDeserializerCopy(dst, src) _test_StringDeserializerCopy(dst, test_StringDeserializer(src))
TEST_EXPORT corto_int16 _test_StringDeserializerCompare(test_StringDeserializer dst, test_StringDeserializer src);
#define test_StringDeserializerCompare(dst, src) _test_StringDeserializerCompare(test_StringDeserializer(dst), test_StringDeserializer(src))

/* /test/VoidParent */
TEST_EXPORT test_VoidParent* _test_VoidParentCreate(corto_int32 Foo);
#define test_VoidParentCreate(Foo) _test_VoidParentCreate(Foo)
TEST_EXPORT test_VoidParent* _test_VoidParentCreateChild(corto_object _parent, corto_string _name, corto_int32 Foo);
#define test_VoidParentCreateChild(_parent, _name, Foo) _test_VoidParentCreateChild(_parent, _name, Foo)
TEST_EXPORT corto_int16 _test_VoidParentUpdate(test_VoidParent* _this, corto_int32 Foo);
#define test_VoidParentUpdate(_this, Foo) _test_VoidParentUpdate(_this, Foo)

TEST_EXPORT test_VoidParent* _test_VoidParentDeclare(void);
#define test_VoidParentDeclare() _test_VoidParentDeclare()
TEST_EXPORT test_VoidParent* _test_VoidParentDeclareChild(corto_object _parent, corto_string _name);
#define test_VoidParentDeclareChild(_parent, _name) _test_VoidParentDeclareChild(_parent, _name)
TEST_EXPORT corto_int16 _test_VoidParentDefine(test_VoidParent* _this, corto_int32 Foo);
#define test_VoidParentDefine(_this, Foo) _test_VoidParentDefine(_this, Foo)
TEST_EXPORT void _test_VoidParentSet(test_VoidParent* _this, corto_int32 Foo);
#define test_VoidParentSet(_this, Foo) _test_VoidParentSet(_this, Foo)
TEST_EXPORT corto_string _test_VoidParentStr(test_VoidParent* value);
#define test_VoidParentStr(value) _test_VoidParentStr(value)
TEST_EXPORT test_VoidParent* test_VoidParentFromStr(test_VoidParent* value, corto_string str);
TEST_EXPORT corto_int16 _test_VoidParentCopy(test_VoidParent* *dst, test_VoidParent* src);
#define test_VoidParentCopy(dst, src) _test_VoidParentCopy(dst, src)
TEST_EXPORT corto_int16 _test_VoidParentCompare(test_VoidParent* dst, test_VoidParent* src);
#define test_VoidParentCompare(dst, src) _test_VoidParentCompare(dst, src)

TEST_EXPORT corto_int16 _test_VoidParentInit(test_VoidParent* value);
#define test_VoidParentInit(value) _test_VoidParentInit(value)
TEST_EXPORT corto_int16 _test_VoidParentDeinit(test_VoidParent* value);
#define test_VoidParentDeinit(value) _test_VoidParentDeinit(value)


/* <0x7fb208e17710> */
#define test_PointListForeach(list, elem) \
    corto_iter elem##_iter = corto_llIter(list);\
    test_Point *elem;\
    while(corto_iterHasNext(&elem##_iter) ? elem = corto_iterNext(&elem##_iter), TRUE : FALSE)

TEST_EXPORT test_Point* test_PointListInsertAlloc(test_PointList list);
TEST_EXPORT test_Point* test_PointListInsert(test_PointList list, test_Point* element);
TEST_EXPORT test_Point* test_PointListAppendAlloc(test_PointList list);
TEST_EXPORT test_Point* test_PointListAppend(test_PointList list, test_Point* element);
TEST_EXPORT test_Point* test_PointListTakeFirst(test_PointList list);
TEST_EXPORT test_Point* test_PointListLast(test_PointList list);
TEST_EXPORT void test_PointListClear(test_PointList list);
TEST_EXPORT test_Point* test_PointListGet(test_PointList list, corto_uint32 index);
TEST_EXPORT corto_uint32 test_PointListSize(test_PointList list);

/* <0x7fb208e6b810> */
#define test_selectItemListForeach(list, elem) \
    corto_iter elem##_iter = corto_llIter(list);\
    test_selectItem *elem;\
    while(corto_iterHasNext(&elem##_iter) ? elem = corto_iterNext(&elem##_iter), TRUE : FALSE)

TEST_EXPORT test_selectItem* test_selectItemListInsertAlloc(test_selectItemList list);
TEST_EXPORT test_selectItem* test_selectItemListInsert(test_selectItemList list, test_selectItem* element);
TEST_EXPORT test_selectItem* test_selectItemListAppendAlloc(test_selectItemList list);
TEST_EXPORT test_selectItem* test_selectItemListAppend(test_selectItemList list, test_selectItem* element);
TEST_EXPORT test_selectItem* test_selectItemListTakeFirst(test_selectItemList list);
TEST_EXPORT test_selectItem* test_selectItemListLast(test_selectItemList list);
TEST_EXPORT void test_selectItemListClear(test_selectItemList list);
TEST_EXPORT test_selectItem* test_selectItemListGet(test_selectItemList list, corto_uint32 index);
TEST_EXPORT corto_uint32 test_selectItemListSize(test_selectItemList list);

/* <0x7fb208f2c050> */
#define corto_objectListForeach(list, elem) \
    corto_iter elem##_iter = corto_llIter(list);\
    corto_object elem;\
    while(corto_iterHasNext(&elem##_iter) ? elem = corto_iterNext(&elem##_iter), TRUE : FALSE)

TEST_EXPORT void corto_objectListInsert(corto_objectList list, corto_object element);
TEST_EXPORT void corto_objectListAppend(corto_objectList list, corto_object element);
TEST_EXPORT corto_object corto_objectListTakeFirst(corto_objectList list);
TEST_EXPORT corto_object corto_objectListLast(corto_objectList list);
TEST_EXPORT void corto_objectListClear(corto_objectList list);
TEST_EXPORT corto_object corto_objectListGet(corto_objectList list, corto_uint32 index);
TEST_EXPORT corto_uint32 corto_objectListSize(corto_objectList list);

/* <0x7fb208e154c0> */
#define corto_int32ListForeach(list, elem) \
    corto_iter elem##_iter = corto_llIter(list);\
    corto_int32 elem;\
    while(corto_iterHasNext(&elem##_iter) ? elem = (corto_int32)(corto_word)corto_iterNext(&elem##_iter), TRUE : FALSE)

TEST_EXPORT void corto_int32ListInsert(corto_int32List list, corto_int32 element);
TEST_EXPORT void corto_int32ListAppend(corto_int32List list, corto_int32 element);
TEST_EXPORT corto_int32 corto_int32ListTakeFirst(corto_int32List list);
TEST_EXPORT corto_int32 corto_int32ListLast(corto_int32List list);
TEST_EXPORT void corto_int32ListClear(corto_int32List list);
TEST_EXPORT corto_int32 corto_int32ListGet(corto_int32List list, corto_uint32 index);
TEST_EXPORT corto_uint32 corto_int32ListSize(corto_int32List list);

#ifdef __cplusplus
}
#endif
#endif

