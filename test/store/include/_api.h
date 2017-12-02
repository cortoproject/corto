/* _api.h
 *
 * API convenience functions for C-language.
 * This file contains generated code. Do not modify!
 */

#ifndef TEST__API_H
#define TEST__API_H

#include <corto/corto.h>
#include <include/_project.h>
#include <include/_type.h>
#ifdef __cplusplus
extern "C" {
#endif
/* /test/AccessRule */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AccessRuleCreate test_AccessRuleCreate
#endif
TEST_EXPORT test_AccessRule* _test_AccessRuleCreate(corto_string user, corto_secure_actionKind action, corto_secure_accessKind access);
#define test_AccessRuleCreate(user, action, access) _test_AccessRuleCreate(user, action, access)
#define test_AccessRuleCreate_auto(_id, user, action, access) test_AccessRule* _id = test_AccessRuleCreate(user, action, access); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AccessRuleCreateChild test_AccessRuleCreateChild
#endif
TEST_EXPORT test_AccessRule* _test_AccessRuleCreateChild(corto_object _parent, corto_string _id, corto_string user, corto_secure_actionKind action, corto_secure_accessKind access);
#define test_AccessRuleCreateChild(_parent, _id, user, action, access) _test_AccessRuleCreateChild(_parent, _id, user, action, access)
#define test_AccessRuleCreateChild_auto(_parent, _id, user, action, access) test_AccessRule* _id = test_AccessRuleCreateChild(_parent, #_id, user, action, access); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AccessRuleUpdate test_AccessRuleUpdate
#endif
TEST_EXPORT corto_int16 _test_AccessRuleUpdate(test_AccessRule* _this, corto_string user, corto_secure_actionKind action, corto_secure_accessKind access);
#define test_AccessRuleUpdate(_this, user, action, access) _test_AccessRuleUpdate(test_AccessRule(_this), user, action, access)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AccessRuleDeclare test_AccessRuleDeclare
#endif
TEST_EXPORT test_AccessRule* _test_AccessRuleDeclare(void);
#define test_AccessRuleDeclare() _test_AccessRuleDeclare()
#define test_AccessRuleDeclare_auto(_id) test_AccessRule* _id = test_AccessRuleDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AccessRuleDeclareChild test_AccessRuleDeclareChild
#endif
TEST_EXPORT test_AccessRule* _test_AccessRuleDeclareChild(corto_object _parent, corto_string _id);
#define test_AccessRuleDeclareChild(_parent, _id) _test_AccessRuleDeclareChild(_parent, _id)
#define test_AccessRuleDeclareChild_auto(_parent, _id) test_AccessRule* _id = test_AccessRuleDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AccessRuleDefine test_AccessRuleDefine
#endif
TEST_EXPORT corto_int16 _test_AccessRuleDefine(test_AccessRule* _this, corto_string user, corto_secure_actionKind action, corto_secure_accessKind access);
#define test_AccessRuleDefine(_this, user, action, access) _test_AccessRuleDefine(test_AccessRule(_this), user, action, access)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AccessRuleAssign test_AccessRuleAssign
#endif
TEST_EXPORT test_AccessRule* _test_AccessRuleAssign(test_AccessRule* _this, corto_string user, corto_secure_actionKind action, corto_secure_accessKind access);
#define test_AccessRule__optional_NotSet NULL
#define test_AccessRule__optional_Set(user, action, access) test_AccessRuleAssign((test_AccessRule*)corto_ptr_new(test_AccessRule_o)), user, action, access)
#define test_AccessRule__optional_SetCond(cond, user, action, access) cond ? test_AccessRuleAssign((test_AccessRule*)corto_ptr_new(test_AccessRule_o), user, action, access) : NULL
#define test_AccessRuleUnset(_this) _this ? corto_ptr_free(_this, test_AccessRule_o), 0 : 0; _this = NULL;
#define test_AccessRuleAssign(_this, user, action, access) _test_AccessRuleAssign(_this, user, action, access)
#define test_AccessRuleSet(_this, user, action, access) _this = _this ? _this : (test_AccessRule*)corto_ptr_new(test_AccessRule_o); _test_AccessRuleAssign(_this, user, action, access)

/* /test/AllocArray */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AllocArrayCreate test_AllocArrayCreate
#endif
TEST_EXPORT corto_int64* _test_AllocArrayCreate(corto_uint32 length, int64_t* elements);
#define test_AllocArrayCreate(length, elements) _test_AllocArrayCreate(length, elements)
#define test_AllocArrayCreate_auto(_id, length, elements) corto_int64* _id = test_AllocArrayCreate(length, elements); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AllocArrayCreateChild test_AllocArrayCreateChild
#endif
TEST_EXPORT corto_int64* _test_AllocArrayCreateChild(corto_object _parent, corto_string _id, corto_uint32 length, int64_t* elements);
#define test_AllocArrayCreateChild(_parent, _id, length, elements) _test_AllocArrayCreateChild(_parent, _id, length, elements)
#define test_AllocArrayCreateChild_auto(_parent, _id, length, elements) corto_int64* _id = test_AllocArrayCreateChild(_parent, #_id, length, elements); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AllocArrayUpdate test_AllocArrayUpdate
#endif
TEST_EXPORT corto_int16 _test_AllocArrayUpdate(test_AllocArray _this, corto_uint32 length, int64_t* elements);
#define test_AllocArrayUpdate(_this, length, elements) _test_AllocArrayUpdate(test_AllocArray(_this), length, elements)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AllocArrayDeclare test_AllocArrayDeclare
#endif
TEST_EXPORT corto_int64* _test_AllocArrayDeclare(void);
#define test_AllocArrayDeclare() _test_AllocArrayDeclare()
#define test_AllocArrayDeclare_auto(_id) corto_int64* _id = test_AllocArrayDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AllocArrayDeclareChild test_AllocArrayDeclareChild
#endif
TEST_EXPORT corto_int64* _test_AllocArrayDeclareChild(corto_object _parent, corto_string _id);
#define test_AllocArrayDeclareChild(_parent, _id) _test_AllocArrayDeclareChild(_parent, _id)
#define test_AllocArrayDeclareChild_auto(_parent, _id) corto_int64* _id = test_AllocArrayDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AllocArrayDefine test_AllocArrayDefine
#endif
TEST_EXPORT corto_int16 _test_AllocArrayDefine(test_AllocArray _this, corto_uint32 length, int64_t* elements);
#define test_AllocArrayDefine(_this, length, elements) _test_AllocArrayDefine(test_AllocArray(_this), length, elements)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AllocArrayAssign test_AllocArrayAssign
#endif
TEST_EXPORT corto_int64* _test_AllocArrayAssign(test_AllocArray _this, corto_uint32 length, int64_t* elements);
#define test_AllocArray__optional_NotSet NULL
#define test_AllocArray__optional_Set(length, elements) test_AllocArrayAssign((test_AllocArray*)corto_ptr_new(test_AllocArray_o)), length, elements)
#define test_AllocArray__optional_SetCond(cond, length, elements) cond ? test_AllocArrayAssign((test_AllocArray*)corto_ptr_new(test_AllocArray_o), length, elements) : NULL
#define test_AllocArrayUnset(_this) _this ? corto_ptr_free(_this, test_AllocArray_o), 0 : 0; _this = NULL;
#define test_AllocArrayAssign(_this, length, elements) _test_AllocArrayAssign((corto_int64*)_this, length, elements)
#define test_AllocArraySet(_this, length, elements) _this = _this ? _this : (test_AllocArray*)corto_ptr_new(test_AllocArray_o); _test_AllocArrayAssign((corto_int64*)_this, length, elements)

/* /test/AllocList */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AllocListCreate test_AllocListCreate
#endif
TEST_EXPORT test_AllocList* _test_AllocListCreate(corto_uint32 length, int64_t* elements);
#define test_AllocListCreate(length, elements) _test_AllocListCreate(length, elements)
#define test_AllocListCreate_auto(_id, length, elements) test_AllocList* _id = test_AllocListCreate(length, elements); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AllocListCreateChild test_AllocListCreateChild
#endif
TEST_EXPORT test_AllocList* _test_AllocListCreateChild(corto_object _parent, corto_string _id, corto_uint32 length, int64_t* elements);
#define test_AllocListCreateChild(_parent, _id, length, elements) _test_AllocListCreateChild(_parent, _id, length, elements)
#define test_AllocListCreateChild_auto(_parent, _id, length, elements) test_AllocList* _id = test_AllocListCreateChild(_parent, #_id, length, elements); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AllocListUpdate test_AllocListUpdate
#endif
TEST_EXPORT corto_int16 _test_AllocListUpdate(test_AllocList* _this, corto_uint32 length, int64_t* elements);
#define test_AllocListUpdate(_this, length, elements) _test_AllocListUpdate(test_AllocList(_this), length, elements)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AllocListDeclare test_AllocListDeclare
#endif
TEST_EXPORT test_AllocList* _test_AllocListDeclare(void);
#define test_AllocListDeclare() _test_AllocListDeclare()
#define test_AllocListDeclare_auto(_id) test_AllocList* _id = test_AllocListDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AllocListDeclareChild test_AllocListDeclareChild
#endif
TEST_EXPORT test_AllocList* _test_AllocListDeclareChild(corto_object _parent, corto_string _id);
#define test_AllocListDeclareChild(_parent, _id) _test_AllocListDeclareChild(_parent, _id)
#define test_AllocListDeclareChild_auto(_parent, _id) test_AllocList* _id = test_AllocListDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AllocListDefine test_AllocListDefine
#endif
TEST_EXPORT corto_int16 _test_AllocListDefine(test_AllocList* _this, corto_uint32 length, int64_t* elements);
#define test_AllocListDefine(_this, length, elements) _test_AllocListDefine(test_AllocList(_this), length, elements)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AllocListAssign test_AllocListAssign
#endif
TEST_EXPORT test_AllocList* _test_AllocListAssign(test_AllocList* _this, corto_uint32 length, int64_t* elements);
#define test_AllocList__optional_NotSet NULL
#define test_AllocList__optional_Set(length, elements) test_AllocListAssign((test_AllocList*)corto_ptr_new(test_AllocList_o)), length, elements)
#define test_AllocList__optional_SetCond(cond, length, elements) cond ? test_AllocListAssign((test_AllocList*)corto_ptr_new(test_AllocList_o), length, elements) : NULL
#define test_AllocListUnset(_this) _this ? corto_ptr_free(_this, test_AllocList_o), 0 : 0; _this = NULL;
#define test_AllocListAssign(_this, length, elements) _test_AllocListAssign(_this, length, elements)
#define test_AllocListSet(_this, length, elements) _this = _this ? _this : (test_AllocList*)corto_ptr_new(test_AllocList_o); _test_AllocListAssign(_this, length, elements)

/* /test/AllocSequence */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AllocSequenceCreate test_AllocSequenceCreate
#endif
TEST_EXPORT test_AllocSequence* _test_AllocSequenceCreate(corto_uint32 length, int64_t* elements);
#define test_AllocSequenceCreate(length, elements) _test_AllocSequenceCreate(length, elements)
#define test_AllocSequenceCreate_auto(_id, length, elements) test_AllocSequence* _id = test_AllocSequenceCreate(length, elements); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AllocSequenceCreateChild test_AllocSequenceCreateChild
#endif
TEST_EXPORT test_AllocSequence* _test_AllocSequenceCreateChild(corto_object _parent, corto_string _id, corto_uint32 length, int64_t* elements);
#define test_AllocSequenceCreateChild(_parent, _id, length, elements) _test_AllocSequenceCreateChild(_parent, _id, length, elements)
#define test_AllocSequenceCreateChild_auto(_parent, _id, length, elements) test_AllocSequence* _id = test_AllocSequenceCreateChild(_parent, #_id, length, elements); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AllocSequenceUpdate test_AllocSequenceUpdate
#endif
TEST_EXPORT corto_int16 _test_AllocSequenceUpdate(test_AllocSequence* _this, corto_uint32 length, int64_t* elements);
#define test_AllocSequenceUpdate(_this, length, elements) _test_AllocSequenceUpdate(test_AllocSequence(_this), length, elements)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AllocSequenceDeclare test_AllocSequenceDeclare
#endif
TEST_EXPORT test_AllocSequence* _test_AllocSequenceDeclare(void);
#define test_AllocSequenceDeclare() _test_AllocSequenceDeclare()
#define test_AllocSequenceDeclare_auto(_id) test_AllocSequence* _id = test_AllocSequenceDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AllocSequenceDeclareChild test_AllocSequenceDeclareChild
#endif
TEST_EXPORT test_AllocSequence* _test_AllocSequenceDeclareChild(corto_object _parent, corto_string _id);
#define test_AllocSequenceDeclareChild(_parent, _id) _test_AllocSequenceDeclareChild(_parent, _id)
#define test_AllocSequenceDeclareChild_auto(_parent, _id) test_AllocSequence* _id = test_AllocSequenceDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AllocSequenceDefine test_AllocSequenceDefine
#endif
TEST_EXPORT corto_int16 _test_AllocSequenceDefine(test_AllocSequence* _this, corto_uint32 length, int64_t* elements);
#define test_AllocSequenceDefine(_this, length, elements) _test_AllocSequenceDefine(test_AllocSequence(_this), length, elements)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AllocSequenceAssign test_AllocSequenceAssign
#endif
TEST_EXPORT test_AllocSequence* _test_AllocSequenceAssign(test_AllocSequence* _this, corto_uint32 length, int64_t* elements);
#define test_AllocSequence__optional_NotSet NULL
#define test_AllocSequence__optional_Set(length, elements) test_AllocSequenceAssign((test_AllocSequence*)corto_ptr_new(test_AllocSequence_o)), length, elements)
#define test_AllocSequence__optional_SetCond(cond, length, elements) cond ? test_AllocSequenceAssign((test_AllocSequence*)corto_ptr_new(test_AllocSequence_o), length, elements) : NULL
#define test_AllocSequenceUnset(_this) _this ? corto_ptr_free(_this, test_AllocSequence_o), 0 : 0; _this = NULL;
#define test_AllocSequenceAssign(_this, length, elements) _test_AllocSequenceAssign(_this, length, elements)
#define test_AllocSequenceSet(_this, length, elements) _this = _this ? _this : (test_AllocSequence*)corto_ptr_new(test_AllocSequence_o); _test_AllocSequenceAssign(_this, length, elements)

/* /test/Animal */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AnimalCreate test_AnimalCreate
#endif
TEST_EXPORT test_Animal _test_AnimalCreate(bool a);
#define test_AnimalCreate(a) _test_AnimalCreate(a)
#define test_AnimalCreate_auto(_id, a) test_Animal _id = test_AnimalCreate(a); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AnimalCreateChild test_AnimalCreateChild
#endif
TEST_EXPORT test_Animal _test_AnimalCreateChild(corto_object _parent, corto_string _id, bool a);
#define test_AnimalCreateChild(_parent, _id, a) _test_AnimalCreateChild(_parent, _id, a)
#define test_AnimalCreateChild_auto(_parent, _id, a) test_Animal _id = test_AnimalCreateChild(_parent, #_id, a); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AnimalUpdate test_AnimalUpdate
#endif
TEST_EXPORT corto_int16 _test_AnimalUpdate(test_Animal _this, bool a);
#define test_AnimalUpdate(_this, a) _test_AnimalUpdate(test_Animal(_this), a)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AnimalDeclare test_AnimalDeclare
#endif
TEST_EXPORT test_Animal _test_AnimalDeclare(void);
#define test_AnimalDeclare() _test_AnimalDeclare()
#define test_AnimalDeclare_auto(_id) test_Animal _id = test_AnimalDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AnimalDeclareChild test_AnimalDeclareChild
#endif
TEST_EXPORT test_Animal _test_AnimalDeclareChild(corto_object _parent, corto_string _id);
#define test_AnimalDeclareChild(_parent, _id) _test_AnimalDeclareChild(_parent, _id)
#define test_AnimalDeclareChild_auto(_parent, _id) test_Animal _id = test_AnimalDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AnimalDefine test_AnimalDefine
#endif
TEST_EXPORT corto_int16 _test_AnimalDefine(test_Animal _this, bool a);
#define test_AnimalDefine(_this, a) _test_AnimalDefine(test_Animal(_this), a)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AnimalAssign test_AnimalAssign
#endif
TEST_EXPORT test_Animal _test_AnimalAssign(test_Animal _this, bool a);
#define test_Animal__optional_NotSet NULL
#define test_Animal__optional_Set(a) test_AnimalAssign((test_Animal*)corto_ptr_new(test_Animal_o)), a)
#define test_Animal__optional_SetCond(cond, a) cond ? test_AnimalAssign((test_Animal*)corto_ptr_new(test_Animal_o), a) : NULL
#define test_AnimalUnset(_this) _this ? corto_ptr_free(_this, test_Animal_o), 0 : 0; _this = NULL;
#define test_AnimalAssign(_this, a) _test_AnimalAssign(_this, a)
#define test_AnimalSet(_this, a) _this = _this ? _this : (test_Animal*)corto_ptr_new(test_Animal_o); _test_AnimalAssign(_this, a)

/* /test/AnonymousTest */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AnonymousTestCreate test_AnonymousTestCreate
#endif
TEST_EXPORT test_AnonymousTest _test_AnonymousTestCreate(corto_objectList objects);
#define test_AnonymousTestCreate(objects) _test_AnonymousTestCreate(objects)
#define test_AnonymousTestCreate_auto(_id, objects) test_AnonymousTest _id = test_AnonymousTestCreate(objects); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AnonymousTestCreateChild test_AnonymousTestCreateChild
#endif
TEST_EXPORT test_AnonymousTest _test_AnonymousTestCreateChild(corto_object _parent, corto_string _id, corto_objectList objects);
#define test_AnonymousTestCreateChild(_parent, _id, objects) _test_AnonymousTestCreateChild(_parent, _id, objects)
#define test_AnonymousTestCreateChild_auto(_parent, _id, objects) test_AnonymousTest _id = test_AnonymousTestCreateChild(_parent, #_id, objects); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AnonymousTestUpdate test_AnonymousTestUpdate
#endif
TEST_EXPORT corto_int16 _test_AnonymousTestUpdate(test_AnonymousTest _this, corto_objectList objects);
#define test_AnonymousTestUpdate(_this, objects) _test_AnonymousTestUpdate(test_AnonymousTest(_this), objects)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AnonymousTestDeclare test_AnonymousTestDeclare
#endif
TEST_EXPORT test_AnonymousTest _test_AnonymousTestDeclare(void);
#define test_AnonymousTestDeclare() _test_AnonymousTestDeclare()
#define test_AnonymousTestDeclare_auto(_id) test_AnonymousTest _id = test_AnonymousTestDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AnonymousTestDeclareChild test_AnonymousTestDeclareChild
#endif
TEST_EXPORT test_AnonymousTest _test_AnonymousTestDeclareChild(corto_object _parent, corto_string _id);
#define test_AnonymousTestDeclareChild(_parent, _id) _test_AnonymousTestDeclareChild(_parent, _id)
#define test_AnonymousTestDeclareChild_auto(_parent, _id) test_AnonymousTest _id = test_AnonymousTestDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AnonymousTestDefine test_AnonymousTestDefine
#endif
TEST_EXPORT corto_int16 _test_AnonymousTestDefine(test_AnonymousTest _this, corto_objectList objects);
#define test_AnonymousTestDefine(_this, objects) _test_AnonymousTestDefine(test_AnonymousTest(_this), objects)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AnonymousTestAssign test_AnonymousTestAssign
#endif
TEST_EXPORT test_AnonymousTest _test_AnonymousTestAssign(test_AnonymousTest _this, corto_objectList objects);
#define test_AnonymousTest__optional_NotSet NULL
#define test_AnonymousTest__optional_Set(objects) test_AnonymousTestAssign((test_AnonymousTest*)corto_ptr_new(test_AnonymousTest_o)), objects)
#define test_AnonymousTest__optional_SetCond(cond, objects) cond ? test_AnonymousTestAssign((test_AnonymousTest*)corto_ptr_new(test_AnonymousTest_o), objects) : NULL
#define test_AnonymousTestUnset(_this) _this ? corto_ptr_free(_this, test_AnonymousTest_o), 0 : 0; _this = NULL;
#define test_AnonymousTestAssign(_this, objects) _test_AnonymousTestAssign(_this, objects)
#define test_AnonymousTestSet(_this, objects) _this = _this ? _this : (test_AnonymousTest*)corto_ptr_new(test_AnonymousTest_o); _test_AnonymousTestAssign(_this, objects)

/* /test/AttrCheck */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AttrCheckCreate test_AttrCheckCreate
#endif
TEST_EXPORT test_AttrCheck _test_AttrCheckCreate(uint32_t assertCount);
#define test_AttrCheckCreate(assertCount) _test_AttrCheckCreate(assertCount)
#define test_AttrCheckCreate_auto(_id, assertCount) test_AttrCheck _id = test_AttrCheckCreate(assertCount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AttrCheckCreateChild test_AttrCheckCreateChild
#endif
TEST_EXPORT test_AttrCheck _test_AttrCheckCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount);
#define test_AttrCheckCreateChild(_parent, _id, assertCount) _test_AttrCheckCreateChild(_parent, _id, assertCount)
#define test_AttrCheckCreateChild_auto(_parent, _id, assertCount) test_AttrCheck _id = test_AttrCheckCreateChild(_parent, #_id, assertCount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AttrCheckUpdate test_AttrCheckUpdate
#endif
TEST_EXPORT corto_int16 _test_AttrCheckUpdate(test_AttrCheck _this, uint32_t assertCount);
#define test_AttrCheckUpdate(_this, assertCount) _test_AttrCheckUpdate(test_AttrCheck(_this), assertCount)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AttrCheckDeclare test_AttrCheckDeclare
#endif
TEST_EXPORT test_AttrCheck _test_AttrCheckDeclare(void);
#define test_AttrCheckDeclare() _test_AttrCheckDeclare()
#define test_AttrCheckDeclare_auto(_id) test_AttrCheck _id = test_AttrCheckDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AttrCheckDeclareChild test_AttrCheckDeclareChild
#endif
TEST_EXPORT test_AttrCheck _test_AttrCheckDeclareChild(corto_object _parent, corto_string _id);
#define test_AttrCheckDeclareChild(_parent, _id) _test_AttrCheckDeclareChild(_parent, _id)
#define test_AttrCheckDeclareChild_auto(_parent, _id) test_AttrCheck _id = test_AttrCheckDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AttrCheckDefine test_AttrCheckDefine
#endif
TEST_EXPORT corto_int16 _test_AttrCheckDefine(test_AttrCheck _this, uint32_t assertCount);
#define test_AttrCheckDefine(_this, assertCount) _test_AttrCheckDefine(test_AttrCheck(_this), assertCount)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AttrCheckAssign test_AttrCheckAssign
#endif
TEST_EXPORT test_AttrCheck _test_AttrCheckAssign(test_AttrCheck _this, uint32_t assertCount);
#define test_AttrCheck__optional_NotSet NULL
#define test_AttrCheck__optional_Set(assertCount) test_AttrCheckAssign((test_AttrCheck*)corto_ptr_new(test_AttrCheck_o)), assertCount)
#define test_AttrCheck__optional_SetCond(cond, assertCount) cond ? test_AttrCheckAssign((test_AttrCheck*)corto_ptr_new(test_AttrCheck_o), assertCount) : NULL
#define test_AttrCheckUnset(_this) _this ? corto_ptr_free(_this, test_AttrCheck_o), 0 : 0; _this = NULL;
#define test_AttrCheckAssign(_this, assertCount) _test_AttrCheckAssign(_this, assertCount)
#define test_AttrCheckSet(_this, assertCount) _this = _this ? _this : (test_AttrCheck*)corto_ptr_new(test_AttrCheck_o); _test_AttrCheckAssign(_this, assertCount)

/* /test/AttrConstructorTest */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AttrConstructorTestCreate test_AttrConstructorTestCreate
#endif
TEST_EXPORT test_AttrConstructorTest _test_AttrConstructorTestCreate(void);
#define test_AttrConstructorTestCreate() _test_AttrConstructorTestCreate()
#define test_AttrConstructorTestCreate_auto(_id) test_AttrConstructorTest _id = test_AttrConstructorTestCreate(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AttrConstructorTestCreateChild test_AttrConstructorTestCreateChild
#endif
TEST_EXPORT test_AttrConstructorTest _test_AttrConstructorTestCreateChild(corto_object _parent, corto_string _id);
#define test_AttrConstructorTestCreateChild(_parent, _id) _test_AttrConstructorTestCreateChild(_parent, _id)
#define test_AttrConstructorTestCreateChild_auto(_parent, _id) test_AttrConstructorTest _id = test_AttrConstructorTestCreateChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AttrConstructorTestUpdate test_AttrConstructorTestUpdate
#endif
TEST_EXPORT corto_int16 _test_AttrConstructorTestUpdate(test_AttrConstructorTest _this);
#define test_AttrConstructorTestUpdate(_this) _test_AttrConstructorTestUpdate(test_AttrConstructorTest(_this))


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AttrConstructorTestDeclare test_AttrConstructorTestDeclare
#endif
TEST_EXPORT test_AttrConstructorTest _test_AttrConstructorTestDeclare(void);
#define test_AttrConstructorTestDeclare() _test_AttrConstructorTestDeclare()
#define test_AttrConstructorTestDeclare_auto(_id) test_AttrConstructorTest _id = test_AttrConstructorTestDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AttrConstructorTestDeclareChild test_AttrConstructorTestDeclareChild
#endif
TEST_EXPORT test_AttrConstructorTest _test_AttrConstructorTestDeclareChild(corto_object _parent, corto_string _id);
#define test_AttrConstructorTestDeclareChild(_parent, _id) _test_AttrConstructorTestDeclareChild(_parent, _id)
#define test_AttrConstructorTestDeclareChild_auto(_parent, _id) test_AttrConstructorTest _id = test_AttrConstructorTestDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AttrConstructorTestDefine test_AttrConstructorTestDefine
#endif
TEST_EXPORT corto_int16 _test_AttrConstructorTestDefine(test_AttrConstructorTest _this);
#define test_AttrConstructorTestDefine(_this) _test_AttrConstructorTestDefine(test_AttrConstructorTest(_this))

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AttrConstructorTestAssign test_AttrConstructorTestAssign
#endif
TEST_EXPORT test_AttrConstructorTest _test_AttrConstructorTestAssign(test_AttrConstructorTest _this);
#define test_AttrConstructorTest__optional_NotSet NULL
#define test_AttrConstructorTest__optional_Set() test_AttrConstructorTestAssign((test_AttrConstructorTest*)corto_ptr_new(test_AttrConstructorTest_o)))
#define test_AttrConstructorTest__optional_SetCond(cond) cond ? test_AttrConstructorTestAssign((test_AttrConstructorTest*)corto_ptr_new(test_AttrConstructorTest_o)) : NULL
#define test_AttrConstructorTestUnset(_this) _this ? corto_ptr_free(_this, test_AttrConstructorTest_o), 0 : 0; _this = NULL;
#define test_AttrConstructorTestAssign(_this) _test_AttrConstructorTestAssign(_this)
#define test_AttrConstructorTestSet(_this) _this = _this ? _this : (test_AttrConstructorTest*)corto_ptr_new(test_AttrConstructorTest_o); _test_AttrConstructorTestAssign(_this)

/* /test/Attributes */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AttributesCreate test_AttributesCreate
#endif
TEST_EXPORT test_Attributes _test_AttributesCreate(uint32_t assertCount);
#define test_AttributesCreate(assertCount) _test_AttributesCreate(assertCount)
#define test_AttributesCreate_auto(_id, assertCount) test_Attributes _id = test_AttributesCreate(assertCount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AttributesCreateChild test_AttributesCreateChild
#endif
TEST_EXPORT test_Attributes _test_AttributesCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount);
#define test_AttributesCreateChild(_parent, _id, assertCount) _test_AttributesCreateChild(_parent, _id, assertCount)
#define test_AttributesCreateChild_auto(_parent, _id, assertCount) test_Attributes _id = test_AttributesCreateChild(_parent, #_id, assertCount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AttributesUpdate test_AttributesUpdate
#endif
TEST_EXPORT corto_int16 _test_AttributesUpdate(test_Attributes _this, uint32_t assertCount);
#define test_AttributesUpdate(_this, assertCount) _test_AttributesUpdate(test_Attributes(_this), assertCount)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AttributesDeclare test_AttributesDeclare
#endif
TEST_EXPORT test_Attributes _test_AttributesDeclare(void);
#define test_AttributesDeclare() _test_AttributesDeclare()
#define test_AttributesDeclare_auto(_id) test_Attributes _id = test_AttributesDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AttributesDeclareChild test_AttributesDeclareChild
#endif
TEST_EXPORT test_Attributes _test_AttributesDeclareChild(corto_object _parent, corto_string _id);
#define test_AttributesDeclareChild(_parent, _id) _test_AttributesDeclareChild(_parent, _id)
#define test_AttributesDeclareChild_auto(_parent, _id) test_Attributes _id = test_AttributesDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AttributesDefine test_AttributesDefine
#endif
TEST_EXPORT corto_int16 _test_AttributesDefine(test_Attributes _this, uint32_t assertCount);
#define test_AttributesDefine(_this, assertCount) _test_AttributesDefine(test_Attributes(_this), assertCount)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AttributesAssign test_AttributesAssign
#endif
TEST_EXPORT test_Attributes _test_AttributesAssign(test_Attributes _this, uint32_t assertCount);
#define test_Attributes__optional_NotSet NULL
#define test_Attributes__optional_Set(assertCount) test_AttributesAssign((test_Attributes*)corto_ptr_new(test_Attributes_o)), assertCount)
#define test_Attributes__optional_SetCond(cond, assertCount) cond ? test_AttributesAssign((test_Attributes*)corto_ptr_new(test_Attributes_o), assertCount) : NULL
#define test_AttributesUnset(_this) _this ? corto_ptr_free(_this, test_Attributes_o), 0 : 0; _this = NULL;
#define test_AttributesAssign(_this, assertCount) _test_AttributesAssign(_this, assertCount)
#define test_AttributesSet(_this, assertCount) _this = _this ? _this : (test_Attributes*)corto_ptr_new(test_Attributes_o); _test_AttributesAssign(_this, assertCount)

/* /test/Bar */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define BarCreate test_BarCreate
#endif
TEST_EXPORT test_Bar _test_BarCreate(void);
#define test_BarCreate() _test_BarCreate()
#define test_BarCreate_auto(_id) test_Bar _id = test_BarCreate(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define BarCreateChild test_BarCreateChild
#endif
TEST_EXPORT test_Bar _test_BarCreateChild(corto_object _parent, corto_string _id);
#define test_BarCreateChild(_parent, _id) _test_BarCreateChild(_parent, _id)
#define test_BarCreateChild_auto(_parent, _id) test_Bar _id = test_BarCreateChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define BarUpdate test_BarUpdate
#endif
TEST_EXPORT corto_int16 _test_BarUpdate(test_Bar _this);
#define test_BarUpdate(_this) _test_BarUpdate(test_Bar(_this))


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define BarDeclare test_BarDeclare
#endif
TEST_EXPORT test_Bar _test_BarDeclare(void);
#define test_BarDeclare() _test_BarDeclare()
#define test_BarDeclare_auto(_id) test_Bar _id = test_BarDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define BarDeclareChild test_BarDeclareChild
#endif
TEST_EXPORT test_Bar _test_BarDeclareChild(corto_object _parent, corto_string _id);
#define test_BarDeclareChild(_parent, _id) _test_BarDeclareChild(_parent, _id)
#define test_BarDeclareChild_auto(_parent, _id) test_Bar _id = test_BarDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define BarDefine test_BarDefine
#endif
TEST_EXPORT corto_int16 _test_BarDefine(test_Bar _this);
#define test_BarDefine(_this) _test_BarDefine(test_Bar(_this))

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define BarAssign test_BarAssign
#endif
TEST_EXPORT test_Bar _test_BarAssign(test_Bar _this);
#define test_Bar__optional_NotSet NULL
#define test_Bar__optional_Set() test_BarAssign((test_Bar*)corto_ptr_new(test_Bar_o)))
#define test_Bar__optional_SetCond(cond) cond ? test_BarAssign((test_Bar*)corto_ptr_new(test_Bar_o)) : NULL
#define test_BarUnset(_this) _this ? corto_ptr_free(_this, test_Bar_o), 0 : 0; _this = NULL;
#define test_BarAssign(_this) _test_BarAssign(_this)
#define test_BarSet(_this) _this = _this ? _this : (test_Bar*)corto_ptr_new(test_Bar_o); _test_BarAssign(_this)

/* /test/BinaryOperators */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define BinaryOperatorsCreate test_BinaryOperatorsCreate
#endif
TEST_EXPORT test_BinaryOperators _test_BinaryOperatorsCreate(uint32_t assertCount);
#define test_BinaryOperatorsCreate(assertCount) _test_BinaryOperatorsCreate(assertCount)
#define test_BinaryOperatorsCreate_auto(_id, assertCount) test_BinaryOperators _id = test_BinaryOperatorsCreate(assertCount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define BinaryOperatorsCreateChild test_BinaryOperatorsCreateChild
#endif
TEST_EXPORT test_BinaryOperators _test_BinaryOperatorsCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount);
#define test_BinaryOperatorsCreateChild(_parent, _id, assertCount) _test_BinaryOperatorsCreateChild(_parent, _id, assertCount)
#define test_BinaryOperatorsCreateChild_auto(_parent, _id, assertCount) test_BinaryOperators _id = test_BinaryOperatorsCreateChild(_parent, #_id, assertCount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define BinaryOperatorsUpdate test_BinaryOperatorsUpdate
#endif
TEST_EXPORT corto_int16 _test_BinaryOperatorsUpdate(test_BinaryOperators _this, uint32_t assertCount);
#define test_BinaryOperatorsUpdate(_this, assertCount) _test_BinaryOperatorsUpdate(test_BinaryOperators(_this), assertCount)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define BinaryOperatorsDeclare test_BinaryOperatorsDeclare
#endif
TEST_EXPORT test_BinaryOperators _test_BinaryOperatorsDeclare(void);
#define test_BinaryOperatorsDeclare() _test_BinaryOperatorsDeclare()
#define test_BinaryOperatorsDeclare_auto(_id) test_BinaryOperators _id = test_BinaryOperatorsDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define BinaryOperatorsDeclareChild test_BinaryOperatorsDeclareChild
#endif
TEST_EXPORT test_BinaryOperators _test_BinaryOperatorsDeclareChild(corto_object _parent, corto_string _id);
#define test_BinaryOperatorsDeclareChild(_parent, _id) _test_BinaryOperatorsDeclareChild(_parent, _id)
#define test_BinaryOperatorsDeclareChild_auto(_parent, _id) test_BinaryOperators _id = test_BinaryOperatorsDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define BinaryOperatorsDefine test_BinaryOperatorsDefine
#endif
TEST_EXPORT corto_int16 _test_BinaryOperatorsDefine(test_BinaryOperators _this, uint32_t assertCount);
#define test_BinaryOperatorsDefine(_this, assertCount) _test_BinaryOperatorsDefine(test_BinaryOperators(_this), assertCount)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define BinaryOperatorsAssign test_BinaryOperatorsAssign
#endif
TEST_EXPORT test_BinaryOperators _test_BinaryOperatorsAssign(test_BinaryOperators _this, uint32_t assertCount);
#define test_BinaryOperators__optional_NotSet NULL
#define test_BinaryOperators__optional_Set(assertCount) test_BinaryOperatorsAssign((test_BinaryOperators*)corto_ptr_new(test_BinaryOperators_o)), assertCount)
#define test_BinaryOperators__optional_SetCond(cond, assertCount) cond ? test_BinaryOperatorsAssign((test_BinaryOperators*)corto_ptr_new(test_BinaryOperators_o), assertCount) : NULL
#define test_BinaryOperatorsUnset(_this) _this ? corto_ptr_free(_this, test_BinaryOperators_o), 0 : 0; _this = NULL;
#define test_BinaryOperatorsAssign(_this, assertCount) _test_BinaryOperatorsAssign(_this, assertCount)
#define test_BinaryOperatorsSet(_this, assertCount) _this = _this ? _this : (test_BinaryOperators*)corto_ptr_new(test_BinaryOperators_o); _test_BinaryOperatorsAssign(_this, assertCount)

/* /test/Boat */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define BoatCreate test_BoatCreate
#endif
TEST_EXPORT test_Boat _test_BoatCreate(double cur_x, double cur_y);
#define test_BoatCreate(cur_x, cur_y) _test_BoatCreate(cur_x, cur_y)
#define test_BoatCreate_auto(_id, cur_x, cur_y) test_Boat _id = test_BoatCreate(cur_x, cur_y); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define BoatCreateChild test_BoatCreateChild
#endif
TEST_EXPORT test_Boat _test_BoatCreateChild(corto_object _parent, corto_string _id, double cur_x, double cur_y);
#define test_BoatCreateChild(_parent, _id, cur_x, cur_y) _test_BoatCreateChild(_parent, _id, cur_x, cur_y)
#define test_BoatCreateChild_auto(_parent, _id, cur_x, cur_y) test_Boat _id = test_BoatCreateChild(_parent, #_id, cur_x, cur_y); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define BoatUpdate test_BoatUpdate
#endif
TEST_EXPORT corto_int16 _test_BoatUpdate(test_Boat _this, double cur_x, double cur_y);
#define test_BoatUpdate(_this, cur_x, cur_y) _test_BoatUpdate(test_Boat(_this), cur_x, cur_y)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define BoatDeclare test_BoatDeclare
#endif
TEST_EXPORT test_Boat _test_BoatDeclare(void);
#define test_BoatDeclare() _test_BoatDeclare()
#define test_BoatDeclare_auto(_id) test_Boat _id = test_BoatDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define BoatDeclareChild test_BoatDeclareChild
#endif
TEST_EXPORT test_Boat _test_BoatDeclareChild(corto_object _parent, corto_string _id);
#define test_BoatDeclareChild(_parent, _id) _test_BoatDeclareChild(_parent, _id)
#define test_BoatDeclareChild_auto(_parent, _id) test_Boat _id = test_BoatDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define BoatDefine test_BoatDefine
#endif
TEST_EXPORT corto_int16 _test_BoatDefine(test_Boat _this, double cur_x, double cur_y);
#define test_BoatDefine(_this, cur_x, cur_y) _test_BoatDefine(test_Boat(_this), cur_x, cur_y)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define BoatAssign test_BoatAssign
#endif
TEST_EXPORT test_Boat _test_BoatAssign(test_Boat _this, double cur_x, double cur_y);
#define test_Boat__optional_NotSet NULL
#define test_Boat__optional_Set(cur_x, cur_y) test_BoatAssign((test_Boat*)corto_ptr_new(test_Boat_o)), cur_x, cur_y)
#define test_Boat__optional_SetCond(cond, cur_x, cur_y) cond ? test_BoatAssign((test_Boat*)corto_ptr_new(test_Boat_o), cur_x, cur_y) : NULL
#define test_BoatUnset(_this) _this ? corto_ptr_free(_this, test_Boat_o), 0 : 0; _this = NULL;
#define test_BoatAssign(_this, cur_x, cur_y) _test_BoatAssign(_this, cur_x, cur_y)
#define test_BoatSet(_this, cur_x, cur_y) _this = _this ? _this : (test_Boat*)corto_ptr_new(test_Boat_o); _test_BoatAssign(_this, cur_x, cur_y)

/* /test/Buffer */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define BufferCreate test_BufferCreate
#endif
TEST_EXPORT test_Buffer _test_BufferCreate(uint32_t assertCount);
#define test_BufferCreate(assertCount) _test_BufferCreate(assertCount)
#define test_BufferCreate_auto(_id, assertCount) test_Buffer _id = test_BufferCreate(assertCount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define BufferCreateChild test_BufferCreateChild
#endif
TEST_EXPORT test_Buffer _test_BufferCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount);
#define test_BufferCreateChild(_parent, _id, assertCount) _test_BufferCreateChild(_parent, _id, assertCount)
#define test_BufferCreateChild_auto(_parent, _id, assertCount) test_Buffer _id = test_BufferCreateChild(_parent, #_id, assertCount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define BufferUpdate test_BufferUpdate
#endif
TEST_EXPORT corto_int16 _test_BufferUpdate(test_Buffer _this, uint32_t assertCount);
#define test_BufferUpdate(_this, assertCount) _test_BufferUpdate(test_Buffer(_this), assertCount)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define BufferDeclare test_BufferDeclare
#endif
TEST_EXPORT test_Buffer _test_BufferDeclare(void);
#define test_BufferDeclare() _test_BufferDeclare()
#define test_BufferDeclare_auto(_id) test_Buffer _id = test_BufferDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define BufferDeclareChild test_BufferDeclareChild
#endif
TEST_EXPORT test_Buffer _test_BufferDeclareChild(corto_object _parent, corto_string _id);
#define test_BufferDeclareChild(_parent, _id) _test_BufferDeclareChild(_parent, _id)
#define test_BufferDeclareChild_auto(_parent, _id) test_Buffer _id = test_BufferDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define BufferDefine test_BufferDefine
#endif
TEST_EXPORT corto_int16 _test_BufferDefine(test_Buffer _this, uint32_t assertCount);
#define test_BufferDefine(_this, assertCount) _test_BufferDefine(test_Buffer(_this), assertCount)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define BufferAssign test_BufferAssign
#endif
TEST_EXPORT test_Buffer _test_BufferAssign(test_Buffer _this, uint32_t assertCount);
#define test_Buffer__optional_NotSet NULL
#define test_Buffer__optional_Set(assertCount) test_BufferAssign((test_Buffer*)corto_ptr_new(test_Buffer_o)), assertCount)
#define test_Buffer__optional_SetCond(cond, assertCount) cond ? test_BufferAssign((test_Buffer*)corto_ptr_new(test_Buffer_o), assertCount) : NULL
#define test_BufferUnset(_this) _this ? corto_ptr_free(_this, test_Buffer_o), 0 : 0; _this = NULL;
#define test_BufferAssign(_this, assertCount) _test_BufferAssign(_this, assertCount)
#define test_BufferSet(_this, assertCount) _this = _this ? _this : (test_Buffer*)corto_ptr_new(test_Buffer_o); _test_BufferAssign(_this, assertCount)

/* /test/Car */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define CarCreate test_CarCreate
#endif
TEST_EXPORT test_Car _test_CarCreate(corto_string license_plate, uint16_t speed);
#define test_CarCreate(license_plate, speed) _test_CarCreate(license_plate, speed)
#define test_CarCreate_auto(_id, license_plate, speed) test_Car _id = test_CarCreate(license_plate, speed); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define CarCreateChild test_CarCreateChild
#endif
TEST_EXPORT test_Car _test_CarCreateChild(corto_object _parent, corto_string _id, corto_string license_plate, uint16_t speed);
#define test_CarCreateChild(_parent, _id, license_plate, speed) _test_CarCreateChild(_parent, _id, license_plate, speed)
#define test_CarCreateChild_auto(_parent, _id, license_plate, speed) test_Car _id = test_CarCreateChild(_parent, #_id, license_plate, speed); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define CarUpdate test_CarUpdate
#endif
TEST_EXPORT corto_int16 _test_CarUpdate(test_Car _this, corto_string license_plate, uint16_t speed);
#define test_CarUpdate(_this, license_plate, speed) _test_CarUpdate(test_Car(_this), license_plate, speed)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define CarDeclare test_CarDeclare
#endif
TEST_EXPORT test_Car _test_CarDeclare(void);
#define test_CarDeclare() _test_CarDeclare()
#define test_CarDeclare_auto(_id) test_Car _id = test_CarDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define CarDeclareChild test_CarDeclareChild
#endif
TEST_EXPORT test_Car _test_CarDeclareChild(corto_object _parent, corto_string _id);
#define test_CarDeclareChild(_parent, _id) _test_CarDeclareChild(_parent, _id)
#define test_CarDeclareChild_auto(_parent, _id) test_Car _id = test_CarDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define CarDefine test_CarDefine
#endif
TEST_EXPORT corto_int16 _test_CarDefine(test_Car _this, corto_string license_plate, uint16_t speed);
#define test_CarDefine(_this, license_plate, speed) _test_CarDefine(test_Car(_this), license_plate, speed)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define CarAssign test_CarAssign
#endif
TEST_EXPORT test_Car _test_CarAssign(test_Car _this, corto_string license_plate, uint16_t speed);
#define test_Car__optional_NotSet NULL
#define test_Car__optional_Set(license_plate, speed) test_CarAssign((test_Car*)corto_ptr_new(test_Car_o)), license_plate, speed)
#define test_Car__optional_SetCond(cond, license_plate, speed) cond ? test_CarAssign((test_Car*)corto_ptr_new(test_Car_o), license_plate, speed) : NULL
#define test_CarUnset(_this) _this ? corto_ptr_free(_this, test_Car_o), 0 : 0; _this = NULL;
#define test_CarAssign(_this, license_plate, speed) _test_CarAssign(_this, license_plate, speed)
#define test_CarSet(_this, license_plate, speed) _this = _this ? _this : (test_Car*)corto_ptr_new(test_Car_o); _test_CarAssign(_this, license_plate, speed)

/* /test/Car/Engine */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define Car_EngineCreate test_Car_EngineCreate
#endif
TEST_EXPORT test_Car_Engine _test_Car_EngineCreate(uint16_t rpm, uint16_t temperature);
#define test_Car_EngineCreate(rpm, temperature) _test_Car_EngineCreate(rpm, temperature)
#define test_Car_EngineCreate_auto(_id, rpm, temperature) test_Car_Engine _id = test_Car_EngineCreate(rpm, temperature); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define Car_EngineCreateChild test_Car_EngineCreateChild
#endif
TEST_EXPORT test_Car_Engine _test_Car_EngineCreateChild(corto_object _parent, corto_string _id, uint16_t rpm, uint16_t temperature);
#define test_Car_EngineCreateChild(_parent, _id, rpm, temperature) _test_Car_EngineCreateChild(_parent, _id, rpm, temperature)
#define test_Car_EngineCreateChild_auto(_parent, _id, rpm, temperature) test_Car_Engine _id = test_Car_EngineCreateChild(_parent, #_id, rpm, temperature); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define Car_EngineUpdate test_Car_EngineUpdate
#endif
TEST_EXPORT corto_int16 _test_Car_EngineUpdate(test_Car_Engine _this, uint16_t rpm, uint16_t temperature);
#define test_Car_EngineUpdate(_this, rpm, temperature) _test_Car_EngineUpdate(test_Car_Engine(_this), rpm, temperature)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define Car_EngineDeclare test_Car_EngineDeclare
#endif
TEST_EXPORT test_Car_Engine _test_Car_EngineDeclare(void);
#define test_Car_EngineDeclare() _test_Car_EngineDeclare()
#define test_Car_EngineDeclare_auto(_id) test_Car_Engine _id = test_Car_EngineDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define Car_EngineDeclareChild test_Car_EngineDeclareChild
#endif
TEST_EXPORT test_Car_Engine _test_Car_EngineDeclareChild(corto_object _parent, corto_string _id);
#define test_Car_EngineDeclareChild(_parent, _id) _test_Car_EngineDeclareChild(_parent, _id)
#define test_Car_EngineDeclareChild_auto(_parent, _id) test_Car_Engine _id = test_Car_EngineDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define Car_EngineDefine test_Car_EngineDefine
#endif
TEST_EXPORT corto_int16 _test_Car_EngineDefine(test_Car_Engine _this, uint16_t rpm, uint16_t temperature);
#define test_Car_EngineDefine(_this, rpm, temperature) _test_Car_EngineDefine(test_Car_Engine(_this), rpm, temperature)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define Car_EngineAssign test_Car_EngineAssign
#endif
TEST_EXPORT test_Car_Engine _test_Car_EngineAssign(test_Car_Engine _this, uint16_t rpm, uint16_t temperature);
#define test_Car_Engine__optional_NotSet NULL
#define test_Car_Engine__optional_Set(rpm, temperature) test_Car_EngineAssign((test_Car_Engine*)corto_ptr_new(test_Car_Engine_o)), rpm, temperature)
#define test_Car_Engine__optional_SetCond(cond, rpm, temperature) cond ? test_Car_EngineAssign((test_Car_Engine*)corto_ptr_new(test_Car_Engine_o), rpm, temperature) : NULL
#define test_Car_EngineUnset(_this) _this ? corto_ptr_free(_this, test_Car_Engine_o), 0 : 0; _this = NULL;
#define test_Car_EngineAssign(_this, rpm, temperature) _test_Car_EngineAssign(_this, rpm, temperature)
#define test_Car_EngineSet(_this, rpm, temperature) _this = _this ? _this : (test_Car_Engine*)corto_ptr_new(test_Car_Engine_o); _test_Car_EngineAssign(_this, rpm, temperature)

/* /test/Car/Wheel */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define Car_WheelCreate test_Car_WheelCreate
#endif
TEST_EXPORT test_Car_Wheel _test_Car_WheelCreate(uint16_t position);
#define test_Car_WheelCreate(position) _test_Car_WheelCreate(position)
#define test_Car_WheelCreate_auto(_id, position) test_Car_Wheel _id = test_Car_WheelCreate(position); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define Car_WheelCreateChild test_Car_WheelCreateChild
#endif
TEST_EXPORT test_Car_Wheel _test_Car_WheelCreateChild(corto_object _parent, corto_string _id, uint16_t position);
#define test_Car_WheelCreateChild(_parent, _id, position) _test_Car_WheelCreateChild(_parent, _id, position)
#define test_Car_WheelCreateChild_auto(_parent, _id, position) test_Car_Wheel _id = test_Car_WheelCreateChild(_parent, #_id, position); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define Car_WheelUpdate test_Car_WheelUpdate
#endif
TEST_EXPORT corto_int16 _test_Car_WheelUpdate(test_Car_Wheel _this, uint16_t position);
#define test_Car_WheelUpdate(_this, position) _test_Car_WheelUpdate(test_Car_Wheel(_this), position)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define Car_WheelDeclare test_Car_WheelDeclare
#endif
TEST_EXPORT test_Car_Wheel _test_Car_WheelDeclare(void);
#define test_Car_WheelDeclare() _test_Car_WheelDeclare()
#define test_Car_WheelDeclare_auto(_id) test_Car_Wheel _id = test_Car_WheelDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define Car_WheelDeclareChild test_Car_WheelDeclareChild
#endif
TEST_EXPORT test_Car_Wheel _test_Car_WheelDeclareChild(corto_object _parent, corto_string _id);
#define test_Car_WheelDeclareChild(_parent, _id) _test_Car_WheelDeclareChild(_parent, _id)
#define test_Car_WheelDeclareChild_auto(_parent, _id) test_Car_Wheel _id = test_Car_WheelDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define Car_WheelDefine test_Car_WheelDefine
#endif
TEST_EXPORT corto_int16 _test_Car_WheelDefine(test_Car_Wheel _this, uint16_t position);
#define test_Car_WheelDefine(_this, position) _test_Car_WheelDefine(test_Car_Wheel(_this), position)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define Car_WheelAssign test_Car_WheelAssign
#endif
TEST_EXPORT test_Car_Wheel _test_Car_WheelAssign(test_Car_Wheel _this, uint16_t position);
#define test_Car_Wheel__optional_NotSet NULL
#define test_Car_Wheel__optional_Set(position) test_Car_WheelAssign((test_Car_Wheel*)corto_ptr_new(test_Car_Wheel_o)), position)
#define test_Car_Wheel__optional_SetCond(cond, position) cond ? test_Car_WheelAssign((test_Car_Wheel*)corto_ptr_new(test_Car_Wheel_o), position) : NULL
#define test_Car_WheelUnset(_this) _this ? corto_ptr_free(_this, test_Car_Wheel_o), 0 : 0; _this = NULL;
#define test_Car_WheelAssign(_this, position) _test_Car_WheelAssign(_this, position)
#define test_Car_WheelSet(_this, position) _this = _this ? _this : (test_Car_Wheel*)corto_ptr_new(test_Car_Wheel_o); _test_Car_WheelAssign(_this, position)

/* /test/Car/Wheel/Tire */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define Car_Wheel_TireCreate test_Car_Wheel_TireCreate
#endif
TEST_EXPORT test_Car_Wheel_Tire _test_Car_Wheel_TireCreate(corto_string brand);
#define test_Car_Wheel_TireCreate(brand) _test_Car_Wheel_TireCreate(brand)
#define test_Car_Wheel_TireCreate_auto(_id, brand) test_Car_Wheel_Tire _id = test_Car_Wheel_TireCreate(brand); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define Car_Wheel_TireCreateChild test_Car_Wheel_TireCreateChild
#endif
TEST_EXPORT test_Car_Wheel_Tire _test_Car_Wheel_TireCreateChild(corto_object _parent, corto_string _id, corto_string brand);
#define test_Car_Wheel_TireCreateChild(_parent, _id, brand) _test_Car_Wheel_TireCreateChild(_parent, _id, brand)
#define test_Car_Wheel_TireCreateChild_auto(_parent, _id, brand) test_Car_Wheel_Tire _id = test_Car_Wheel_TireCreateChild(_parent, #_id, brand); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define Car_Wheel_TireUpdate test_Car_Wheel_TireUpdate
#endif
TEST_EXPORT corto_int16 _test_Car_Wheel_TireUpdate(test_Car_Wheel_Tire _this, corto_string brand);
#define test_Car_Wheel_TireUpdate(_this, brand) _test_Car_Wheel_TireUpdate(test_Car_Wheel_Tire(_this), brand)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define Car_Wheel_TireDeclare test_Car_Wheel_TireDeclare
#endif
TEST_EXPORT test_Car_Wheel_Tire _test_Car_Wheel_TireDeclare(void);
#define test_Car_Wheel_TireDeclare() _test_Car_Wheel_TireDeclare()
#define test_Car_Wheel_TireDeclare_auto(_id) test_Car_Wheel_Tire _id = test_Car_Wheel_TireDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define Car_Wheel_TireDeclareChild test_Car_Wheel_TireDeclareChild
#endif
TEST_EXPORT test_Car_Wheel_Tire _test_Car_Wheel_TireDeclareChild(corto_object _parent, corto_string _id);
#define test_Car_Wheel_TireDeclareChild(_parent, _id) _test_Car_Wheel_TireDeclareChild(_parent, _id)
#define test_Car_Wheel_TireDeclareChild_auto(_parent, _id) test_Car_Wheel_Tire _id = test_Car_Wheel_TireDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define Car_Wheel_TireDefine test_Car_Wheel_TireDefine
#endif
TEST_EXPORT corto_int16 _test_Car_Wheel_TireDefine(test_Car_Wheel_Tire _this, corto_string brand);
#define test_Car_Wheel_TireDefine(_this, brand) _test_Car_Wheel_TireDefine(test_Car_Wheel_Tire(_this), brand)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define Car_Wheel_TireAssign test_Car_Wheel_TireAssign
#endif
TEST_EXPORT test_Car_Wheel_Tire _test_Car_Wheel_TireAssign(test_Car_Wheel_Tire _this, corto_string brand);
#define test_Car_Wheel_Tire__optional_NotSet NULL
#define test_Car_Wheel_Tire__optional_Set(brand) test_Car_Wheel_TireAssign((test_Car_Wheel_Tire*)corto_ptr_new(test_Car_Wheel_Tire_o)), brand)
#define test_Car_Wheel_Tire__optional_SetCond(cond, brand) cond ? test_Car_Wheel_TireAssign((test_Car_Wheel_Tire*)corto_ptr_new(test_Car_Wheel_Tire_o), brand) : NULL
#define test_Car_Wheel_TireUnset(_this) _this ? corto_ptr_free(_this, test_Car_Wheel_Tire_o), 0 : 0; _this = NULL;
#define test_Car_Wheel_TireAssign(_this, brand) _test_Car_Wheel_TireAssign(_this, brand)
#define test_Car_Wheel_TireSet(_this, brand) _this = _this ? _this : (test_Car_Wheel_Tire*)corto_ptr_new(test_Car_Wheel_Tire_o); _test_Car_Wheel_TireAssign(_this, brand)

/* /test/Car/WheelLocation */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define Car_WheelLocationCreate test_Car_WheelLocationCreate
#endif
TEST_EXPORT test_Car_WheelLocation* _test_Car_WheelLocationCreate(test_Car_WheelLocation value);
#define test_Car_WheelLocationCreate(value) _test_Car_WheelLocationCreate(value)
#define test_Car_WheelLocationCreate_auto(_id, value) test_Car_WheelLocation* _id = test_Car_WheelLocationCreate(value); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define Car_WheelLocationCreateChild test_Car_WheelLocationCreateChild
#endif
TEST_EXPORT test_Car_WheelLocation* _test_Car_WheelLocationCreateChild(corto_object _parent, corto_string _id, test_Car_WheelLocation value);
#define test_Car_WheelLocationCreateChild(_parent, _id, value) _test_Car_WheelLocationCreateChild(_parent, _id, value)
#define test_Car_WheelLocationCreateChild_auto(_parent, _id, value) test_Car_WheelLocation* _id = test_Car_WheelLocationCreateChild(_parent, #_id, value); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define Car_WheelLocationUpdate test_Car_WheelLocationUpdate
#endif
TEST_EXPORT corto_int16 _test_Car_WheelLocationUpdate(test_Car_WheelLocation* _this, test_Car_WheelLocation value);
#define test_Car_WheelLocationUpdate(_this, value) _test_Car_WheelLocationUpdate(test_Car_WheelLocation(_this), value)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define Car_WheelLocationDeclare test_Car_WheelLocationDeclare
#endif
TEST_EXPORT test_Car_WheelLocation* _test_Car_WheelLocationDeclare(void);
#define test_Car_WheelLocationDeclare() _test_Car_WheelLocationDeclare()
#define test_Car_WheelLocationDeclare_auto(_id) test_Car_WheelLocation* _id = test_Car_WheelLocationDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define Car_WheelLocationDeclareChild test_Car_WheelLocationDeclareChild
#endif
TEST_EXPORT test_Car_WheelLocation* _test_Car_WheelLocationDeclareChild(corto_object _parent, corto_string _id);
#define test_Car_WheelLocationDeclareChild(_parent, _id) _test_Car_WheelLocationDeclareChild(_parent, _id)
#define test_Car_WheelLocationDeclareChild_auto(_parent, _id) test_Car_WheelLocation* _id = test_Car_WheelLocationDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define Car_WheelLocationDefine test_Car_WheelLocationDefine
#endif
TEST_EXPORT corto_int16 _test_Car_WheelLocationDefine(test_Car_WheelLocation* _this, test_Car_WheelLocation value);
#define test_Car_WheelLocationDefine(_this, value) _test_Car_WheelLocationDefine(test_Car_WheelLocation(_this), value)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define Car_WheelLocationAssign test_Car_WheelLocationAssign
#endif
TEST_EXPORT test_Car_WheelLocation* _test_Car_WheelLocationAssign(test_Car_WheelLocation* _this, test_Car_WheelLocation value);
#define test_Car_WheelLocation__optional_NotSet NULL
#define test_Car_WheelLocation__optional_Set(value) test_Car_WheelLocationAssign((test_Car_WheelLocation*)corto_ptr_new(test_Car_WheelLocation_o)), value)
#define test_Car_WheelLocation__optional_SetCond(cond, value) cond ? test_Car_WheelLocationAssign((test_Car_WheelLocation*)corto_ptr_new(test_Car_WheelLocation_o), value) : NULL
#define test_Car_WheelLocationUnset(_this) _this ? corto_ptr_free(_this, test_Car_WheelLocation_o), 0 : 0; _this = NULL;
#define test_Car_WheelLocationAssign(_this, value) _test_Car_WheelLocationAssign(_this, value)
#define test_Car_WheelLocationSet(_this, value) _this = _this ? _this : (test_Car_WheelLocation*)corto_ptr_new(test_Car_WheelLocation_o); _test_Car_WheelLocationAssign(_this, value)

/* /test/Cat */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define CatCreate test_CatCreate
#endif
TEST_EXPORT test_Cat _test_CatCreate(bool a, bool b);
#define test_CatCreate(a, b) _test_CatCreate(a, b)
#define test_CatCreate_auto(_id, a, b) test_Cat _id = test_CatCreate(a, b); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define CatCreateChild test_CatCreateChild
#endif
TEST_EXPORT test_Cat _test_CatCreateChild(corto_object _parent, corto_string _id, bool a, bool b);
#define test_CatCreateChild(_parent, _id, a, b) _test_CatCreateChild(_parent, _id, a, b)
#define test_CatCreateChild_auto(_parent, _id, a, b) test_Cat _id = test_CatCreateChild(_parent, #_id, a, b); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define CatUpdate test_CatUpdate
#endif
TEST_EXPORT corto_int16 _test_CatUpdate(test_Cat _this, bool a, bool b);
#define test_CatUpdate(_this, a, b) _test_CatUpdate(test_Cat(_this), a, b)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define CatDeclare test_CatDeclare
#endif
TEST_EXPORT test_Cat _test_CatDeclare(void);
#define test_CatDeclare() _test_CatDeclare()
#define test_CatDeclare_auto(_id) test_Cat _id = test_CatDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define CatDeclareChild test_CatDeclareChild
#endif
TEST_EXPORT test_Cat _test_CatDeclareChild(corto_object _parent, corto_string _id);
#define test_CatDeclareChild(_parent, _id) _test_CatDeclareChild(_parent, _id)
#define test_CatDeclareChild_auto(_parent, _id) test_Cat _id = test_CatDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define CatDefine test_CatDefine
#endif
TEST_EXPORT corto_int16 _test_CatDefine(test_Cat _this, bool a, bool b);
#define test_CatDefine(_this, a, b) _test_CatDefine(test_Cat(_this), a, b)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define CatAssign test_CatAssign
#endif
TEST_EXPORT test_Cat _test_CatAssign(test_Cat _this, bool a, bool b);
#define test_Cat__optional_NotSet NULL
#define test_Cat__optional_Set(a, b) test_CatAssign((test_Cat*)corto_ptr_new(test_Cat_o)), a, b)
#define test_Cat__optional_SetCond(cond, a, b) cond ? test_CatAssign((test_Cat*)corto_ptr_new(test_Cat_o), a, b) : NULL
#define test_CatUnset(_this) _this ? corto_ptr_free(_this, test_Cat_o), 0 : 0; _this = NULL;
#define test_CatAssign(_this, a, b) _test_CatAssign(_this, a, b)
#define test_CatSet(_this, a, b) _this = _this ? _this : (test_Cat*)corto_ptr_new(test_Cat_o); _test_CatAssign(_this, a, b)

/* /test/CollectionList */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define CollectionListCreate test_CollectionListCreate
#endif
TEST_EXPORT test_CollectionList* _test_CollectionListCreate(corto_uint32 length, corto_int32List* elements);
#define test_CollectionListCreate(length, elements) _test_CollectionListCreate(length, elements)
#define test_CollectionListCreate_auto(_id, length, elements) test_CollectionList* _id = test_CollectionListCreate(length, elements); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define CollectionListCreateChild test_CollectionListCreateChild
#endif
TEST_EXPORT test_CollectionList* _test_CollectionListCreateChild(corto_object _parent, corto_string _id, corto_uint32 length, corto_int32List* elements);
#define test_CollectionListCreateChild(_parent, _id, length, elements) _test_CollectionListCreateChild(_parent, _id, length, elements)
#define test_CollectionListCreateChild_auto(_parent, _id, length, elements) test_CollectionList* _id = test_CollectionListCreateChild(_parent, #_id, length, elements); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define CollectionListUpdate test_CollectionListUpdate
#endif
TEST_EXPORT corto_int16 _test_CollectionListUpdate(test_CollectionList* _this, corto_uint32 length, corto_int32List* elements);
#define test_CollectionListUpdate(_this, length, elements) _test_CollectionListUpdate(test_CollectionList(_this), length, elements)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define CollectionListDeclare test_CollectionListDeclare
#endif
TEST_EXPORT test_CollectionList* _test_CollectionListDeclare(void);
#define test_CollectionListDeclare() _test_CollectionListDeclare()
#define test_CollectionListDeclare_auto(_id) test_CollectionList* _id = test_CollectionListDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define CollectionListDeclareChild test_CollectionListDeclareChild
#endif
TEST_EXPORT test_CollectionList* _test_CollectionListDeclareChild(corto_object _parent, corto_string _id);
#define test_CollectionListDeclareChild(_parent, _id) _test_CollectionListDeclareChild(_parent, _id)
#define test_CollectionListDeclareChild_auto(_parent, _id) test_CollectionList* _id = test_CollectionListDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define CollectionListDefine test_CollectionListDefine
#endif
TEST_EXPORT corto_int16 _test_CollectionListDefine(test_CollectionList* _this, corto_uint32 length, corto_int32List* elements);
#define test_CollectionListDefine(_this, length, elements) _test_CollectionListDefine(test_CollectionList(_this), length, elements)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define CollectionListAssign test_CollectionListAssign
#endif
TEST_EXPORT test_CollectionList* _test_CollectionListAssign(test_CollectionList* _this, corto_uint32 length, corto_int32List* elements);
#define test_CollectionList__optional_NotSet NULL
#define test_CollectionList__optional_Set(length, elements) test_CollectionListAssign((test_CollectionList*)corto_ptr_new(test_CollectionList_o)), length, elements)
#define test_CollectionList__optional_SetCond(cond, length, elements) cond ? test_CollectionListAssign((test_CollectionList*)corto_ptr_new(test_CollectionList_o), length, elements) : NULL
#define test_CollectionListUnset(_this) _this ? corto_ptr_free(_this, test_CollectionList_o), 0 : 0; _this = NULL;
#define test_CollectionListAssign(_this, length, elements) _test_CollectionListAssign(_this, length, elements)
#define test_CollectionListSet(_this, length, elements) _this = _this ? _this : (test_CollectionList*)corto_ptr_new(test_CollectionList_o); _test_CollectionListAssign(_this, length, elements)

/* /test/Color */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ColorCreate test_ColorCreate
#endif
TEST_EXPORT test_Color* _test_ColorCreate(test_Color value);
#define test_ColorCreate(value) _test_ColorCreate(value)
#define test_ColorCreate_auto(_id, value) test_Color* _id = test_ColorCreate(value); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ColorCreateChild test_ColorCreateChild
#endif
TEST_EXPORT test_Color* _test_ColorCreateChild(corto_object _parent, corto_string _id, test_Color value);
#define test_ColorCreateChild(_parent, _id, value) _test_ColorCreateChild(_parent, _id, value)
#define test_ColorCreateChild_auto(_parent, _id, value) test_Color* _id = test_ColorCreateChild(_parent, #_id, value); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ColorUpdate test_ColorUpdate
#endif
TEST_EXPORT corto_int16 _test_ColorUpdate(test_Color* _this, test_Color value);
#define test_ColorUpdate(_this, value) _test_ColorUpdate(test_Color(_this), value)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ColorDeclare test_ColorDeclare
#endif
TEST_EXPORT test_Color* _test_ColorDeclare(void);
#define test_ColorDeclare() _test_ColorDeclare()
#define test_ColorDeclare_auto(_id) test_Color* _id = test_ColorDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ColorDeclareChild test_ColorDeclareChild
#endif
TEST_EXPORT test_Color* _test_ColorDeclareChild(corto_object _parent, corto_string _id);
#define test_ColorDeclareChild(_parent, _id) _test_ColorDeclareChild(_parent, _id)
#define test_ColorDeclareChild_auto(_parent, _id) test_Color* _id = test_ColorDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ColorDefine test_ColorDefine
#endif
TEST_EXPORT corto_int16 _test_ColorDefine(test_Color* _this, test_Color value);
#define test_ColorDefine(_this, value) _test_ColorDefine(test_Color(_this), value)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ColorAssign test_ColorAssign
#endif
TEST_EXPORT test_Color* _test_ColorAssign(test_Color* _this, test_Color value);
#define test_Color__optional_NotSet NULL
#define test_Color__optional_Set(value) test_ColorAssign((test_Color*)corto_ptr_new(test_Color_o)), value)
#define test_Color__optional_SetCond(cond, value) cond ? test_ColorAssign((test_Color*)corto_ptr_new(test_Color_o), value) : NULL
#define test_ColorUnset(_this) _this ? corto_ptr_free(_this, test_Color_o), 0 : 0; _this = NULL;
#define test_ColorAssign(_this, value) _test_ColorAssign(_this, value)
#define test_ColorSet(_this, value) _this = _this ? _this : (test_Color*)corto_ptr_new(test_Color_o); _test_ColorAssign(_this, value)

/* /test/Compare */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define CompareCreate test_CompareCreate
#endif
TEST_EXPORT test_Compare _test_CompareCreate(uint32_t assertCount);
#define test_CompareCreate(assertCount) _test_CompareCreate(assertCount)
#define test_CompareCreate_auto(_id, assertCount) test_Compare _id = test_CompareCreate(assertCount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define CompareCreateChild test_CompareCreateChild
#endif
TEST_EXPORT test_Compare _test_CompareCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount);
#define test_CompareCreateChild(_parent, _id, assertCount) _test_CompareCreateChild(_parent, _id, assertCount)
#define test_CompareCreateChild_auto(_parent, _id, assertCount) test_Compare _id = test_CompareCreateChild(_parent, #_id, assertCount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define CompareUpdate test_CompareUpdate
#endif
TEST_EXPORT corto_int16 _test_CompareUpdate(test_Compare _this, uint32_t assertCount);
#define test_CompareUpdate(_this, assertCount) _test_CompareUpdate(test_Compare(_this), assertCount)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define CompareDeclare test_CompareDeclare
#endif
TEST_EXPORT test_Compare _test_CompareDeclare(void);
#define test_CompareDeclare() _test_CompareDeclare()
#define test_CompareDeclare_auto(_id) test_Compare _id = test_CompareDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define CompareDeclareChild test_CompareDeclareChild
#endif
TEST_EXPORT test_Compare _test_CompareDeclareChild(corto_object _parent, corto_string _id);
#define test_CompareDeclareChild(_parent, _id) _test_CompareDeclareChild(_parent, _id)
#define test_CompareDeclareChild_auto(_parent, _id) test_Compare _id = test_CompareDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define CompareDefine test_CompareDefine
#endif
TEST_EXPORT corto_int16 _test_CompareDefine(test_Compare _this, uint32_t assertCount);
#define test_CompareDefine(_this, assertCount) _test_CompareDefine(test_Compare(_this), assertCount)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define CompareAssign test_CompareAssign
#endif
TEST_EXPORT test_Compare _test_CompareAssign(test_Compare _this, uint32_t assertCount);
#define test_Compare__optional_NotSet NULL
#define test_Compare__optional_Set(assertCount) test_CompareAssign((test_Compare*)corto_ptr_new(test_Compare_o)), assertCount)
#define test_Compare__optional_SetCond(cond, assertCount) cond ? test_CompareAssign((test_Compare*)corto_ptr_new(test_Compare_o), assertCount) : NULL
#define test_CompareUnset(_this) _this ? corto_ptr_free(_this, test_Compare_o), 0 : 0; _this = NULL;
#define test_CompareAssign(_this, assertCount) _test_CompareAssign(_this, assertCount)
#define test_CompareSet(_this, assertCount) _this = _this ? _this : (test_Compare*)corto_ptr_new(test_Compare_o); _test_CompareAssign(_this, assertCount)

/* /test/CompositeArray */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define CompositeArrayCreate test_CompositeArrayCreate
#endif
TEST_EXPORT test_Point* _test_CompositeArrayCreate(corto_uint32 length, test_Point* elements);
#define test_CompositeArrayCreate(length, elements) _test_CompositeArrayCreate(length, elements)
#define test_CompositeArrayCreate_auto(_id, length, elements) test_Point* _id = test_CompositeArrayCreate(length, elements); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define CompositeArrayCreateChild test_CompositeArrayCreateChild
#endif
TEST_EXPORT test_Point* _test_CompositeArrayCreateChild(corto_object _parent, corto_string _id, corto_uint32 length, test_Point* elements);
#define test_CompositeArrayCreateChild(_parent, _id, length, elements) _test_CompositeArrayCreateChild(_parent, _id, length, elements)
#define test_CompositeArrayCreateChild_auto(_parent, _id, length, elements) test_Point* _id = test_CompositeArrayCreateChild(_parent, #_id, length, elements); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define CompositeArrayUpdate test_CompositeArrayUpdate
#endif
TEST_EXPORT corto_int16 _test_CompositeArrayUpdate(test_CompositeArray _this, corto_uint32 length, test_Point* elements);
#define test_CompositeArrayUpdate(_this, length, elements) _test_CompositeArrayUpdate(test_CompositeArray(_this), length, elements)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define CompositeArrayDeclare test_CompositeArrayDeclare
#endif
TEST_EXPORT test_Point* _test_CompositeArrayDeclare(void);
#define test_CompositeArrayDeclare() _test_CompositeArrayDeclare()
#define test_CompositeArrayDeclare_auto(_id) test_Point* _id = test_CompositeArrayDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define CompositeArrayDeclareChild test_CompositeArrayDeclareChild
#endif
TEST_EXPORT test_Point* _test_CompositeArrayDeclareChild(corto_object _parent, corto_string _id);
#define test_CompositeArrayDeclareChild(_parent, _id) _test_CompositeArrayDeclareChild(_parent, _id)
#define test_CompositeArrayDeclareChild_auto(_parent, _id) test_Point* _id = test_CompositeArrayDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define CompositeArrayDefine test_CompositeArrayDefine
#endif
TEST_EXPORT corto_int16 _test_CompositeArrayDefine(test_CompositeArray _this, corto_uint32 length, test_Point* elements);
#define test_CompositeArrayDefine(_this, length, elements) _test_CompositeArrayDefine(test_CompositeArray(_this), length, elements)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define CompositeArrayAssign test_CompositeArrayAssign
#endif
TEST_EXPORT test_Point* _test_CompositeArrayAssign(test_CompositeArray _this, corto_uint32 length, test_Point* elements);
#define test_CompositeArray__optional_NotSet NULL
#define test_CompositeArray__optional_Set(length, elements) test_CompositeArrayAssign((test_CompositeArray*)corto_ptr_new(test_CompositeArray_o)), length, elements)
#define test_CompositeArray__optional_SetCond(cond, length, elements) cond ? test_CompositeArrayAssign((test_CompositeArray*)corto_ptr_new(test_CompositeArray_o), length, elements) : NULL
#define test_CompositeArrayUnset(_this) _this ? corto_ptr_free(_this, test_CompositeArray_o), 0 : 0; _this = NULL;
#define test_CompositeArrayAssign(_this, length, elements) _test_CompositeArrayAssign((test_Point*)_this, length, elements)
#define test_CompositeArraySet(_this, length, elements) _this = _this ? _this : (test_CompositeArray*)corto_ptr_new(test_CompositeArray_o); _test_CompositeArrayAssign((test_Point*)_this, length, elements)

/* /test/CompositeList */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define CompositeListCreate test_CompositeListCreate
#endif
TEST_EXPORT test_CompositeList* _test_CompositeListCreate(corto_uint32 length, test_Point* elements);
#define test_CompositeListCreate(length, elements) _test_CompositeListCreate(length, elements)
#define test_CompositeListCreate_auto(_id, length, elements) test_CompositeList* _id = test_CompositeListCreate(length, elements); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define CompositeListCreateChild test_CompositeListCreateChild
#endif
TEST_EXPORT test_CompositeList* _test_CompositeListCreateChild(corto_object _parent, corto_string _id, corto_uint32 length, test_Point* elements);
#define test_CompositeListCreateChild(_parent, _id, length, elements) _test_CompositeListCreateChild(_parent, _id, length, elements)
#define test_CompositeListCreateChild_auto(_parent, _id, length, elements) test_CompositeList* _id = test_CompositeListCreateChild(_parent, #_id, length, elements); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define CompositeListUpdate test_CompositeListUpdate
#endif
TEST_EXPORT corto_int16 _test_CompositeListUpdate(test_CompositeList* _this, corto_uint32 length, test_Point* elements);
#define test_CompositeListUpdate(_this, length, elements) _test_CompositeListUpdate(test_CompositeList(_this), length, elements)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define CompositeListDeclare test_CompositeListDeclare
#endif
TEST_EXPORT test_CompositeList* _test_CompositeListDeclare(void);
#define test_CompositeListDeclare() _test_CompositeListDeclare()
#define test_CompositeListDeclare_auto(_id) test_CompositeList* _id = test_CompositeListDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define CompositeListDeclareChild test_CompositeListDeclareChild
#endif
TEST_EXPORT test_CompositeList* _test_CompositeListDeclareChild(corto_object _parent, corto_string _id);
#define test_CompositeListDeclareChild(_parent, _id) _test_CompositeListDeclareChild(_parent, _id)
#define test_CompositeListDeclareChild_auto(_parent, _id) test_CompositeList* _id = test_CompositeListDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define CompositeListDefine test_CompositeListDefine
#endif
TEST_EXPORT corto_int16 _test_CompositeListDefine(test_CompositeList* _this, corto_uint32 length, test_Point* elements);
#define test_CompositeListDefine(_this, length, elements) _test_CompositeListDefine(test_CompositeList(_this), length, elements)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define CompositeListAssign test_CompositeListAssign
#endif
TEST_EXPORT test_CompositeList* _test_CompositeListAssign(test_CompositeList* _this, corto_uint32 length, test_Point* elements);
#define test_CompositeList__optional_NotSet NULL
#define test_CompositeList__optional_Set(length, elements) test_CompositeListAssign((test_CompositeList*)corto_ptr_new(test_CompositeList_o)), length, elements)
#define test_CompositeList__optional_SetCond(cond, length, elements) cond ? test_CompositeListAssign((test_CompositeList*)corto_ptr_new(test_CompositeList_o), length, elements) : NULL
#define test_CompositeListUnset(_this) _this ? corto_ptr_free(_this, test_CompositeList_o), 0 : 0; _this = NULL;
#define test_CompositeListAssign(_this, length, elements) _test_CompositeListAssign(_this, length, elements)
#define test_CompositeListSet(_this, length, elements) _this = _this ? _this : (test_CompositeList*)corto_ptr_new(test_CompositeList_o); _test_CompositeListAssign(_this, length, elements)

/* /test/CompositeSequence */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define CompositeSequenceCreate test_CompositeSequenceCreate
#endif
TEST_EXPORT test_CompositeSequence* _test_CompositeSequenceCreate(corto_uint32 length, test_Point* elements);
#define test_CompositeSequenceCreate(length, elements) _test_CompositeSequenceCreate(length, elements)
#define test_CompositeSequenceCreate_auto(_id, length, elements) test_CompositeSequence* _id = test_CompositeSequenceCreate(length, elements); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define CompositeSequenceCreateChild test_CompositeSequenceCreateChild
#endif
TEST_EXPORT test_CompositeSequence* _test_CompositeSequenceCreateChild(corto_object _parent, corto_string _id, corto_uint32 length, test_Point* elements);
#define test_CompositeSequenceCreateChild(_parent, _id, length, elements) _test_CompositeSequenceCreateChild(_parent, _id, length, elements)
#define test_CompositeSequenceCreateChild_auto(_parent, _id, length, elements) test_CompositeSequence* _id = test_CompositeSequenceCreateChild(_parent, #_id, length, elements); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define CompositeSequenceUpdate test_CompositeSequenceUpdate
#endif
TEST_EXPORT corto_int16 _test_CompositeSequenceUpdate(test_CompositeSequence* _this, corto_uint32 length, test_Point* elements);
#define test_CompositeSequenceUpdate(_this, length, elements) _test_CompositeSequenceUpdate(test_CompositeSequence(_this), length, elements)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define CompositeSequenceDeclare test_CompositeSequenceDeclare
#endif
TEST_EXPORT test_CompositeSequence* _test_CompositeSequenceDeclare(void);
#define test_CompositeSequenceDeclare() _test_CompositeSequenceDeclare()
#define test_CompositeSequenceDeclare_auto(_id) test_CompositeSequence* _id = test_CompositeSequenceDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define CompositeSequenceDeclareChild test_CompositeSequenceDeclareChild
#endif
TEST_EXPORT test_CompositeSequence* _test_CompositeSequenceDeclareChild(corto_object _parent, corto_string _id);
#define test_CompositeSequenceDeclareChild(_parent, _id) _test_CompositeSequenceDeclareChild(_parent, _id)
#define test_CompositeSequenceDeclareChild_auto(_parent, _id) test_CompositeSequence* _id = test_CompositeSequenceDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define CompositeSequenceDefine test_CompositeSequenceDefine
#endif
TEST_EXPORT corto_int16 _test_CompositeSequenceDefine(test_CompositeSequence* _this, corto_uint32 length, test_Point* elements);
#define test_CompositeSequenceDefine(_this, length, elements) _test_CompositeSequenceDefine(test_CompositeSequence(_this), length, elements)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define CompositeSequenceAssign test_CompositeSequenceAssign
#endif
TEST_EXPORT test_CompositeSequence* _test_CompositeSequenceAssign(test_CompositeSequence* _this, corto_uint32 length, test_Point* elements);
#define test_CompositeSequence__optional_NotSet NULL
#define test_CompositeSequence__optional_Set(length, elements) test_CompositeSequenceAssign((test_CompositeSequence*)corto_ptr_new(test_CompositeSequence_o)), length, elements)
#define test_CompositeSequence__optional_SetCond(cond, length, elements) cond ? test_CompositeSequenceAssign((test_CompositeSequence*)corto_ptr_new(test_CompositeSequence_o), length, elements) : NULL
#define test_CompositeSequenceUnset(_this) _this ? corto_ptr_free(_this, test_CompositeSequence_o), 0 : 0; _this = NULL;
#define test_CompositeSequenceAssign(_this, length, elements) _test_CompositeSequenceAssign(_this, length, elements)
#define test_CompositeSequenceSet(_this, length, elements) _this = _this ? _this : (test_CompositeSequence*)corto_ptr_new(test_CompositeSequence_o); _test_CompositeSequenceAssign(_this, length, elements)

/* /test/CompositeWithString */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define CompositeWithStringCreate test_CompositeWithStringCreate
#endif
TEST_EXPORT test_CompositeWithString* _test_CompositeWithStringCreate(int32_t a, corto_string b, corto_string c, int32_t d);
#define test_CompositeWithStringCreate(a, b, c, d) _test_CompositeWithStringCreate(a, b, c, d)
#define test_CompositeWithStringCreate_auto(_id, a, b, c, d) test_CompositeWithString* _id = test_CompositeWithStringCreate(a, b, c, d); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define CompositeWithStringCreateChild test_CompositeWithStringCreateChild
#endif
TEST_EXPORT test_CompositeWithString* _test_CompositeWithStringCreateChild(corto_object _parent, corto_string _id, int32_t a, corto_string b, corto_string c, int32_t d);
#define test_CompositeWithStringCreateChild(_parent, _id, a, b, c, d) _test_CompositeWithStringCreateChild(_parent, _id, a, b, c, d)
#define test_CompositeWithStringCreateChild_auto(_parent, _id, a, b, c, d) test_CompositeWithString* _id = test_CompositeWithStringCreateChild(_parent, #_id, a, b, c, d); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define CompositeWithStringUpdate test_CompositeWithStringUpdate
#endif
TEST_EXPORT corto_int16 _test_CompositeWithStringUpdate(test_CompositeWithString* _this, int32_t a, corto_string b, corto_string c, int32_t d);
#define test_CompositeWithStringUpdate(_this, a, b, c, d) _test_CompositeWithStringUpdate(test_CompositeWithString(_this), a, b, c, d)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define CompositeWithStringDeclare test_CompositeWithStringDeclare
#endif
TEST_EXPORT test_CompositeWithString* _test_CompositeWithStringDeclare(void);
#define test_CompositeWithStringDeclare() _test_CompositeWithStringDeclare()
#define test_CompositeWithStringDeclare_auto(_id) test_CompositeWithString* _id = test_CompositeWithStringDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define CompositeWithStringDeclareChild test_CompositeWithStringDeclareChild
#endif
TEST_EXPORT test_CompositeWithString* _test_CompositeWithStringDeclareChild(corto_object _parent, corto_string _id);
#define test_CompositeWithStringDeclareChild(_parent, _id) _test_CompositeWithStringDeclareChild(_parent, _id)
#define test_CompositeWithStringDeclareChild_auto(_parent, _id) test_CompositeWithString* _id = test_CompositeWithStringDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define CompositeWithStringDefine test_CompositeWithStringDefine
#endif
TEST_EXPORT corto_int16 _test_CompositeWithStringDefine(test_CompositeWithString* _this, int32_t a, corto_string b, corto_string c, int32_t d);
#define test_CompositeWithStringDefine(_this, a, b, c, d) _test_CompositeWithStringDefine(test_CompositeWithString(_this), a, b, c, d)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define CompositeWithStringAssign test_CompositeWithStringAssign
#endif
TEST_EXPORT test_CompositeWithString* _test_CompositeWithStringAssign(test_CompositeWithString* _this, int32_t a, corto_string b, corto_string c, int32_t d);
#define test_CompositeWithString__optional_NotSet NULL
#define test_CompositeWithString__optional_Set(a, b, c, d) test_CompositeWithStringAssign((test_CompositeWithString*)corto_ptr_new(test_CompositeWithString_o)), a, b, c, d)
#define test_CompositeWithString__optional_SetCond(cond, a, b, c, d) cond ? test_CompositeWithStringAssign((test_CompositeWithString*)corto_ptr_new(test_CompositeWithString_o), a, b, c, d) : NULL
#define test_CompositeWithStringUnset(_this) _this ? corto_ptr_free(_this, test_CompositeWithString_o), 0 : 0; _this = NULL;
#define test_CompositeWithStringAssign(_this, a, b, c, d) _test_CompositeWithStringAssign(_this, a, b, c, d)
#define test_CompositeWithStringSet(_this, a, b, c, d) _this = _this ? _this : (test_CompositeWithString*)corto_ptr_new(test_CompositeWithString_o); _test_CompositeWithStringAssign(_this, a, b, c, d)

/* /test/Container */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ContainerCreate test_ContainerCreate
#endif
TEST_EXPORT test_Container _test_ContainerCreate(uint32_t assertCount);
#define test_ContainerCreate(assertCount) _test_ContainerCreate(assertCount)
#define test_ContainerCreate_auto(_id, assertCount) test_Container _id = test_ContainerCreate(assertCount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ContainerCreateChild test_ContainerCreateChild
#endif
TEST_EXPORT test_Container _test_ContainerCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount);
#define test_ContainerCreateChild(_parent, _id, assertCount) _test_ContainerCreateChild(_parent, _id, assertCount)
#define test_ContainerCreateChild_auto(_parent, _id, assertCount) test_Container _id = test_ContainerCreateChild(_parent, #_id, assertCount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ContainerUpdate test_ContainerUpdate
#endif
TEST_EXPORT corto_int16 _test_ContainerUpdate(test_Container _this, uint32_t assertCount);
#define test_ContainerUpdate(_this, assertCount) _test_ContainerUpdate(test_Container(_this), assertCount)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ContainerDeclare test_ContainerDeclare
#endif
TEST_EXPORT test_Container _test_ContainerDeclare(void);
#define test_ContainerDeclare() _test_ContainerDeclare()
#define test_ContainerDeclare_auto(_id) test_Container _id = test_ContainerDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ContainerDeclareChild test_ContainerDeclareChild
#endif
TEST_EXPORT test_Container _test_ContainerDeclareChild(corto_object _parent, corto_string _id);
#define test_ContainerDeclareChild(_parent, _id) _test_ContainerDeclareChild(_parent, _id)
#define test_ContainerDeclareChild_auto(_parent, _id) test_Container _id = test_ContainerDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ContainerDefine test_ContainerDefine
#endif
TEST_EXPORT corto_int16 _test_ContainerDefine(test_Container _this, uint32_t assertCount);
#define test_ContainerDefine(_this, assertCount) _test_ContainerDefine(test_Container(_this), assertCount)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ContainerAssign test_ContainerAssign
#endif
TEST_EXPORT test_Container _test_ContainerAssign(test_Container _this, uint32_t assertCount);
#define test_Container__optional_NotSet NULL
#define test_Container__optional_Set(assertCount) test_ContainerAssign((test_Container*)corto_ptr_new(test_Container_o)), assertCount)
#define test_Container__optional_SetCond(cond, assertCount) cond ? test_ContainerAssign((test_Container*)corto_ptr_new(test_Container_o), assertCount) : NULL
#define test_ContainerUnset(_this) _this ? corto_ptr_free(_this, test_Container_o), 0 : 0; _this = NULL;
#define test_ContainerAssign(_this, assertCount) _test_ContainerAssign(_this, assertCount)
#define test_ContainerSet(_this, assertCount) _this = _this ? _this : (test_Container*)corto_ptr_new(test_Container_o); _test_ContainerAssign(_this, assertCount)

/* /test/ContainerEmpty */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ContainerEmptyCreate test_ContainerEmptyCreate
#endif
TEST_EXPORT test_ContainerEmpty _test_ContainerEmptyCreate(int32_t id, corto_string value);
#define test_ContainerEmptyCreate(id, value) _test_ContainerEmptyCreate(id, value)
#define test_ContainerEmptyCreate_auto(_id, id, value) test_ContainerEmpty _id = test_ContainerEmptyCreate(id, value); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ContainerEmptyCreateChild test_ContainerEmptyCreateChild
#endif
TEST_EXPORT test_ContainerEmpty _test_ContainerEmptyCreateChild(corto_object _parent, corto_string _id, int32_t id, corto_string value);
#define test_ContainerEmptyCreateChild(_parent, _id, id, value) _test_ContainerEmptyCreateChild(_parent, _id, id, value)
#define test_ContainerEmptyCreateChild_auto(_parent, _id, id, value) test_ContainerEmpty _id = test_ContainerEmptyCreateChild(_parent, #_id, id, value); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ContainerEmptyUpdate test_ContainerEmptyUpdate
#endif
TEST_EXPORT corto_int16 _test_ContainerEmptyUpdate(test_ContainerEmpty _this, int32_t id, corto_string value);
#define test_ContainerEmptyUpdate(_this, id, value) _test_ContainerEmptyUpdate(test_ContainerEmpty(_this), id, value)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ContainerEmptyDeclare test_ContainerEmptyDeclare
#endif
TEST_EXPORT test_ContainerEmpty _test_ContainerEmptyDeclare(void);
#define test_ContainerEmptyDeclare() _test_ContainerEmptyDeclare()
#define test_ContainerEmptyDeclare_auto(_id) test_ContainerEmpty _id = test_ContainerEmptyDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ContainerEmptyDeclareChild test_ContainerEmptyDeclareChild
#endif
TEST_EXPORT test_ContainerEmpty _test_ContainerEmptyDeclareChild(corto_object _parent, corto_string _id);
#define test_ContainerEmptyDeclareChild(_parent, _id) _test_ContainerEmptyDeclareChild(_parent, _id)
#define test_ContainerEmptyDeclareChild_auto(_parent, _id) test_ContainerEmpty _id = test_ContainerEmptyDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ContainerEmptyDefine test_ContainerEmptyDefine
#endif
TEST_EXPORT corto_int16 _test_ContainerEmptyDefine(test_ContainerEmpty _this, int32_t id, corto_string value);
#define test_ContainerEmptyDefine(_this, id, value) _test_ContainerEmptyDefine(test_ContainerEmpty(_this), id, value)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ContainerEmptyAssign test_ContainerEmptyAssign
#endif
TEST_EXPORT test_ContainerEmpty _test_ContainerEmptyAssign(test_ContainerEmpty _this, int32_t id, corto_string value);
#define test_ContainerEmpty__optional_NotSet NULL
#define test_ContainerEmpty__optional_Set(id, value) test_ContainerEmptyAssign((test_ContainerEmpty*)corto_ptr_new(test_ContainerEmpty_o)), id, value)
#define test_ContainerEmpty__optional_SetCond(cond, id, value) cond ? test_ContainerEmptyAssign((test_ContainerEmpty*)corto_ptr_new(test_ContainerEmpty_o), id, value) : NULL
#define test_ContainerEmptyUnset(_this) _this ? corto_ptr_free(_this, test_ContainerEmpty_o), 0 : 0; _this = NULL;
#define test_ContainerEmptyAssign(_this, id, value) _test_ContainerEmptyAssign(_this, id, value)
#define test_ContainerEmptySet(_this, id, value) _this = _this ? _this : (test_ContainerEmpty*)corto_ptr_new(test_ContainerEmpty_o); _test_ContainerEmptyAssign(_this, id, value)

/* /test/ContainerNestedContainer */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ContainerNestedContainerCreate test_ContainerNestedContainerCreate
#endif
TEST_EXPORT test_ContainerNestedContainer _test_ContainerNestedContainerCreate(int32_t id, corto_string value);
#define test_ContainerNestedContainerCreate(id, value) _test_ContainerNestedContainerCreate(id, value)
#define test_ContainerNestedContainerCreate_auto(_id, id, value) test_ContainerNestedContainer _id = test_ContainerNestedContainerCreate(id, value); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ContainerNestedContainerCreateChild test_ContainerNestedContainerCreateChild
#endif
TEST_EXPORT test_ContainerNestedContainer _test_ContainerNestedContainerCreateChild(corto_object _parent, corto_string _id, int32_t id, corto_string value);
#define test_ContainerNestedContainerCreateChild(_parent, _id, id, value) _test_ContainerNestedContainerCreateChild(_parent, _id, id, value)
#define test_ContainerNestedContainerCreateChild_auto(_parent, _id, id, value) test_ContainerNestedContainer _id = test_ContainerNestedContainerCreateChild(_parent, #_id, id, value); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ContainerNestedContainerUpdate test_ContainerNestedContainerUpdate
#endif
TEST_EXPORT corto_int16 _test_ContainerNestedContainerUpdate(test_ContainerNestedContainer _this, int32_t id, corto_string value);
#define test_ContainerNestedContainerUpdate(_this, id, value) _test_ContainerNestedContainerUpdate(test_ContainerNestedContainer(_this), id, value)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ContainerNestedContainerDeclare test_ContainerNestedContainerDeclare
#endif
TEST_EXPORT test_ContainerNestedContainer _test_ContainerNestedContainerDeclare(void);
#define test_ContainerNestedContainerDeclare() _test_ContainerNestedContainerDeclare()
#define test_ContainerNestedContainerDeclare_auto(_id) test_ContainerNestedContainer _id = test_ContainerNestedContainerDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ContainerNestedContainerDeclareChild test_ContainerNestedContainerDeclareChild
#endif
TEST_EXPORT test_ContainerNestedContainer _test_ContainerNestedContainerDeclareChild(corto_object _parent, corto_string _id);
#define test_ContainerNestedContainerDeclareChild(_parent, _id) _test_ContainerNestedContainerDeclareChild(_parent, _id)
#define test_ContainerNestedContainerDeclareChild_auto(_parent, _id) test_ContainerNestedContainer _id = test_ContainerNestedContainerDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ContainerNestedContainerDefine test_ContainerNestedContainerDefine
#endif
TEST_EXPORT corto_int16 _test_ContainerNestedContainerDefine(test_ContainerNestedContainer _this, int32_t id, corto_string value);
#define test_ContainerNestedContainerDefine(_this, id, value) _test_ContainerNestedContainerDefine(test_ContainerNestedContainer(_this), id, value)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ContainerNestedContainerAssign test_ContainerNestedContainerAssign
#endif
TEST_EXPORT test_ContainerNestedContainer _test_ContainerNestedContainerAssign(test_ContainerNestedContainer _this, int32_t id, corto_string value);
#define test_ContainerNestedContainer__optional_NotSet NULL
#define test_ContainerNestedContainer__optional_Set(id, value) test_ContainerNestedContainerAssign((test_ContainerNestedContainer*)corto_ptr_new(test_ContainerNestedContainer_o)), id, value)
#define test_ContainerNestedContainer__optional_SetCond(cond, id, value) cond ? test_ContainerNestedContainerAssign((test_ContainerNestedContainer*)corto_ptr_new(test_ContainerNestedContainer_o), id, value) : NULL
#define test_ContainerNestedContainerUnset(_this) _this ? corto_ptr_free(_this, test_ContainerNestedContainer_o), 0 : 0; _this = NULL;
#define test_ContainerNestedContainerAssign(_this, id, value) _test_ContainerNestedContainerAssign(_this, id, value)
#define test_ContainerNestedContainerSet(_this, id, value) _this = _this ? _this : (test_ContainerNestedContainer*)corto_ptr_new(test_ContainerNestedContainer_o); _test_ContainerNestedContainerAssign(_this, id, value)

/* /test/ContainerNestedContainer/ChildContainer */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ContainerNestedContainer_ChildContainerCreate test_ContainerNestedContainer_ChildContainerCreate
#endif
TEST_EXPORT test_ContainerNestedContainer_ChildContainer _test_ContainerNestedContainer_ChildContainerCreate(int32_t id, corto_string value);
#define test_ContainerNestedContainer_ChildContainerCreate(id, value) _test_ContainerNestedContainer_ChildContainerCreate(id, value)
#define test_ContainerNestedContainer_ChildContainerCreate_auto(_id, id, value) test_ContainerNestedContainer_ChildContainer _id = test_ContainerNestedContainer_ChildContainerCreate(id, value); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ContainerNestedContainer_ChildContainerCreateChild test_ContainerNestedContainer_ChildContainerCreateChild
#endif
TEST_EXPORT test_ContainerNestedContainer_ChildContainer _test_ContainerNestedContainer_ChildContainerCreateChild(corto_object _parent, corto_string _id, int32_t id, corto_string value);
#define test_ContainerNestedContainer_ChildContainerCreateChild(_parent, _id, id, value) _test_ContainerNestedContainer_ChildContainerCreateChild(_parent, _id, id, value)
#define test_ContainerNestedContainer_ChildContainerCreateChild_auto(_parent, _id, id, value) test_ContainerNestedContainer_ChildContainer _id = test_ContainerNestedContainer_ChildContainerCreateChild(_parent, #_id, id, value); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ContainerNestedContainer_ChildContainerUpdate test_ContainerNestedContainer_ChildContainerUpdate
#endif
TEST_EXPORT corto_int16 _test_ContainerNestedContainer_ChildContainerUpdate(test_ContainerNestedContainer_ChildContainer _this, int32_t id, corto_string value);
#define test_ContainerNestedContainer_ChildContainerUpdate(_this, id, value) _test_ContainerNestedContainer_ChildContainerUpdate(test_ContainerNestedContainer_ChildContainer(_this), id, value)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ContainerNestedContainer_ChildContainerDeclare test_ContainerNestedContainer_ChildContainerDeclare
#endif
TEST_EXPORT test_ContainerNestedContainer_ChildContainer _test_ContainerNestedContainer_ChildContainerDeclare(void);
#define test_ContainerNestedContainer_ChildContainerDeclare() _test_ContainerNestedContainer_ChildContainerDeclare()
#define test_ContainerNestedContainer_ChildContainerDeclare_auto(_id) test_ContainerNestedContainer_ChildContainer _id = test_ContainerNestedContainer_ChildContainerDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ContainerNestedContainer_ChildContainerDeclareChild test_ContainerNestedContainer_ChildContainerDeclareChild
#endif
TEST_EXPORT test_ContainerNestedContainer_ChildContainer _test_ContainerNestedContainer_ChildContainerDeclareChild(corto_object _parent, corto_string _id);
#define test_ContainerNestedContainer_ChildContainerDeclareChild(_parent, _id) _test_ContainerNestedContainer_ChildContainerDeclareChild(_parent, _id)
#define test_ContainerNestedContainer_ChildContainerDeclareChild_auto(_parent, _id) test_ContainerNestedContainer_ChildContainer _id = test_ContainerNestedContainer_ChildContainerDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ContainerNestedContainer_ChildContainerDefine test_ContainerNestedContainer_ChildContainerDefine
#endif
TEST_EXPORT corto_int16 _test_ContainerNestedContainer_ChildContainerDefine(test_ContainerNestedContainer_ChildContainer _this, int32_t id, corto_string value);
#define test_ContainerNestedContainer_ChildContainerDefine(_this, id, value) _test_ContainerNestedContainer_ChildContainerDefine(test_ContainerNestedContainer_ChildContainer(_this), id, value)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ContainerNestedContainer_ChildContainerAssign test_ContainerNestedContainer_ChildContainerAssign
#endif
TEST_EXPORT test_ContainerNestedContainer_ChildContainer _test_ContainerNestedContainer_ChildContainerAssign(test_ContainerNestedContainer_ChildContainer _this, int32_t id, corto_string value);
#define test_ContainerNestedContainer_ChildContainer__optional_NotSet NULL
#define test_ContainerNestedContainer_ChildContainer__optional_Set(id, value) test_ContainerNestedContainer_ChildContainerAssign((test_ContainerNestedContainer_ChildContainer*)corto_ptr_new(test_ContainerNestedContainer_ChildContainer_o)), id, value)
#define test_ContainerNestedContainer_ChildContainer__optional_SetCond(cond, id, value) cond ? test_ContainerNestedContainer_ChildContainerAssign((test_ContainerNestedContainer_ChildContainer*)corto_ptr_new(test_ContainerNestedContainer_ChildContainer_o), id, value) : NULL
#define test_ContainerNestedContainer_ChildContainerUnset(_this) _this ? corto_ptr_free(_this, test_ContainerNestedContainer_ChildContainer_o), 0 : 0; _this = NULL;
#define test_ContainerNestedContainer_ChildContainerAssign(_this, id, value) _test_ContainerNestedContainer_ChildContainerAssign(_this, id, value)
#define test_ContainerNestedContainer_ChildContainerSet(_this, id, value) _this = _this ? _this : (test_ContainerNestedContainer_ChildContainer*)corto_ptr_new(test_ContainerNestedContainer_ChildContainer_o); _test_ContainerNestedContainer_ChildContainerAssign(_this, id, value)

/* /test/ContainerNestedContainer/ChildContainer/ChildLeaf */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ContainerNestedContainer_ChildContainer_ChildLeafCreate test_ContainerNestedContainer_ChildContainer_ChildLeafCreate
#endif
TEST_EXPORT test_ContainerNestedContainer_ChildContainer_ChildLeaf _test_ContainerNestedContainer_ChildContainer_ChildLeafCreate(int32_t id, corto_string value);
#define test_ContainerNestedContainer_ChildContainer_ChildLeafCreate(id, value) _test_ContainerNestedContainer_ChildContainer_ChildLeafCreate(id, value)
#define test_ContainerNestedContainer_ChildContainer_ChildLeafCreate_auto(_id, id, value) test_ContainerNestedContainer_ChildContainer_ChildLeaf _id = test_ContainerNestedContainer_ChildContainer_ChildLeafCreate(id, value); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ContainerNestedContainer_ChildContainer_ChildLeafCreateChild test_ContainerNestedContainer_ChildContainer_ChildLeafCreateChild
#endif
TEST_EXPORT test_ContainerNestedContainer_ChildContainer_ChildLeaf _test_ContainerNestedContainer_ChildContainer_ChildLeafCreateChild(corto_object _parent, corto_string _id, int32_t id, corto_string value);
#define test_ContainerNestedContainer_ChildContainer_ChildLeafCreateChild(_parent, _id, id, value) _test_ContainerNestedContainer_ChildContainer_ChildLeafCreateChild(_parent, _id, id, value)
#define test_ContainerNestedContainer_ChildContainer_ChildLeafCreateChild_auto(_parent, _id, id, value) test_ContainerNestedContainer_ChildContainer_ChildLeaf _id = test_ContainerNestedContainer_ChildContainer_ChildLeafCreateChild(_parent, #_id, id, value); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ContainerNestedContainer_ChildContainer_ChildLeafUpdate test_ContainerNestedContainer_ChildContainer_ChildLeafUpdate
#endif
TEST_EXPORT corto_int16 _test_ContainerNestedContainer_ChildContainer_ChildLeafUpdate(test_ContainerNestedContainer_ChildContainer_ChildLeaf _this, int32_t id, corto_string value);
#define test_ContainerNestedContainer_ChildContainer_ChildLeafUpdate(_this, id, value) _test_ContainerNestedContainer_ChildContainer_ChildLeafUpdate(test_ContainerNestedContainer_ChildContainer_ChildLeaf(_this), id, value)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ContainerNestedContainer_ChildContainer_ChildLeafDeclare test_ContainerNestedContainer_ChildContainer_ChildLeafDeclare
#endif
TEST_EXPORT test_ContainerNestedContainer_ChildContainer_ChildLeaf _test_ContainerNestedContainer_ChildContainer_ChildLeafDeclare(void);
#define test_ContainerNestedContainer_ChildContainer_ChildLeafDeclare() _test_ContainerNestedContainer_ChildContainer_ChildLeafDeclare()
#define test_ContainerNestedContainer_ChildContainer_ChildLeafDeclare_auto(_id) test_ContainerNestedContainer_ChildContainer_ChildLeaf _id = test_ContainerNestedContainer_ChildContainer_ChildLeafDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ContainerNestedContainer_ChildContainer_ChildLeafDeclareChild test_ContainerNestedContainer_ChildContainer_ChildLeafDeclareChild
#endif
TEST_EXPORT test_ContainerNestedContainer_ChildContainer_ChildLeaf _test_ContainerNestedContainer_ChildContainer_ChildLeafDeclareChild(corto_object _parent, corto_string _id);
#define test_ContainerNestedContainer_ChildContainer_ChildLeafDeclareChild(_parent, _id) _test_ContainerNestedContainer_ChildContainer_ChildLeafDeclareChild(_parent, _id)
#define test_ContainerNestedContainer_ChildContainer_ChildLeafDeclareChild_auto(_parent, _id) test_ContainerNestedContainer_ChildContainer_ChildLeaf _id = test_ContainerNestedContainer_ChildContainer_ChildLeafDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ContainerNestedContainer_ChildContainer_ChildLeafDefine test_ContainerNestedContainer_ChildContainer_ChildLeafDefine
#endif
TEST_EXPORT corto_int16 _test_ContainerNestedContainer_ChildContainer_ChildLeafDefine(test_ContainerNestedContainer_ChildContainer_ChildLeaf _this, int32_t id, corto_string value);
#define test_ContainerNestedContainer_ChildContainer_ChildLeafDefine(_this, id, value) _test_ContainerNestedContainer_ChildContainer_ChildLeafDefine(test_ContainerNestedContainer_ChildContainer_ChildLeaf(_this), id, value)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ContainerNestedContainer_ChildContainer_ChildLeafAssign test_ContainerNestedContainer_ChildContainer_ChildLeafAssign
#endif
TEST_EXPORT test_ContainerNestedContainer_ChildContainer_ChildLeaf _test_ContainerNestedContainer_ChildContainer_ChildLeafAssign(test_ContainerNestedContainer_ChildContainer_ChildLeaf _this, int32_t id, corto_string value);
#define test_ContainerNestedContainer_ChildContainer_ChildLeaf__optional_NotSet NULL
#define test_ContainerNestedContainer_ChildContainer_ChildLeaf__optional_Set(id, value) test_ContainerNestedContainer_ChildContainer_ChildLeafAssign((test_ContainerNestedContainer_ChildContainer_ChildLeaf*)corto_ptr_new(test_ContainerNestedContainer_ChildContainer_ChildLeaf_o)), id, value)
#define test_ContainerNestedContainer_ChildContainer_ChildLeaf__optional_SetCond(cond, id, value) cond ? test_ContainerNestedContainer_ChildContainer_ChildLeafAssign((test_ContainerNestedContainer_ChildContainer_ChildLeaf*)corto_ptr_new(test_ContainerNestedContainer_ChildContainer_ChildLeaf_o), id, value) : NULL
#define test_ContainerNestedContainer_ChildContainer_ChildLeafUnset(_this) _this ? corto_ptr_free(_this, test_ContainerNestedContainer_ChildContainer_ChildLeaf_o), 0 : 0; _this = NULL;
#define test_ContainerNestedContainer_ChildContainer_ChildLeafAssign(_this, id, value) _test_ContainerNestedContainer_ChildContainer_ChildLeafAssign(_this, id, value)
#define test_ContainerNestedContainer_ChildContainer_ChildLeafSet(_this, id, value) _this = _this ? _this : (test_ContainerNestedContainer_ChildContainer_ChildLeaf*)corto_ptr_new(test_ContainerNestedContainer_ChildContainer_ChildLeaf_o); _test_ContainerNestedContainer_ChildContainer_ChildLeafAssign(_this, id, value)

/* /test/ContainerNestedLeaf */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ContainerNestedLeafCreate test_ContainerNestedLeafCreate
#endif
TEST_EXPORT test_ContainerNestedLeaf _test_ContainerNestedLeafCreate(int32_t id, corto_string value);
#define test_ContainerNestedLeafCreate(id, value) _test_ContainerNestedLeafCreate(id, value)
#define test_ContainerNestedLeafCreate_auto(_id, id, value) test_ContainerNestedLeaf _id = test_ContainerNestedLeafCreate(id, value); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ContainerNestedLeafCreateChild test_ContainerNestedLeafCreateChild
#endif
TEST_EXPORT test_ContainerNestedLeaf _test_ContainerNestedLeafCreateChild(corto_object _parent, corto_string _id, int32_t id, corto_string value);
#define test_ContainerNestedLeafCreateChild(_parent, _id, id, value) _test_ContainerNestedLeafCreateChild(_parent, _id, id, value)
#define test_ContainerNestedLeafCreateChild_auto(_parent, _id, id, value) test_ContainerNestedLeaf _id = test_ContainerNestedLeafCreateChild(_parent, #_id, id, value); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ContainerNestedLeafUpdate test_ContainerNestedLeafUpdate
#endif
TEST_EXPORT corto_int16 _test_ContainerNestedLeafUpdate(test_ContainerNestedLeaf _this, int32_t id, corto_string value);
#define test_ContainerNestedLeafUpdate(_this, id, value) _test_ContainerNestedLeafUpdate(test_ContainerNestedLeaf(_this), id, value)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ContainerNestedLeafDeclare test_ContainerNestedLeafDeclare
#endif
TEST_EXPORT test_ContainerNestedLeaf _test_ContainerNestedLeafDeclare(void);
#define test_ContainerNestedLeafDeclare() _test_ContainerNestedLeafDeclare()
#define test_ContainerNestedLeafDeclare_auto(_id) test_ContainerNestedLeaf _id = test_ContainerNestedLeafDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ContainerNestedLeafDeclareChild test_ContainerNestedLeafDeclareChild
#endif
TEST_EXPORT test_ContainerNestedLeaf _test_ContainerNestedLeafDeclareChild(corto_object _parent, corto_string _id);
#define test_ContainerNestedLeafDeclareChild(_parent, _id) _test_ContainerNestedLeafDeclareChild(_parent, _id)
#define test_ContainerNestedLeafDeclareChild_auto(_parent, _id) test_ContainerNestedLeaf _id = test_ContainerNestedLeafDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ContainerNestedLeafDefine test_ContainerNestedLeafDefine
#endif
TEST_EXPORT corto_int16 _test_ContainerNestedLeafDefine(test_ContainerNestedLeaf _this, int32_t id, corto_string value);
#define test_ContainerNestedLeafDefine(_this, id, value) _test_ContainerNestedLeafDefine(test_ContainerNestedLeaf(_this), id, value)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ContainerNestedLeafAssign test_ContainerNestedLeafAssign
#endif
TEST_EXPORT test_ContainerNestedLeaf _test_ContainerNestedLeafAssign(test_ContainerNestedLeaf _this, int32_t id, corto_string value);
#define test_ContainerNestedLeaf__optional_NotSet NULL
#define test_ContainerNestedLeaf__optional_Set(id, value) test_ContainerNestedLeafAssign((test_ContainerNestedLeaf*)corto_ptr_new(test_ContainerNestedLeaf_o)), id, value)
#define test_ContainerNestedLeaf__optional_SetCond(cond, id, value) cond ? test_ContainerNestedLeafAssign((test_ContainerNestedLeaf*)corto_ptr_new(test_ContainerNestedLeaf_o), id, value) : NULL
#define test_ContainerNestedLeafUnset(_this) _this ? corto_ptr_free(_this, test_ContainerNestedLeaf_o), 0 : 0; _this = NULL;
#define test_ContainerNestedLeafAssign(_this, id, value) _test_ContainerNestedLeafAssign(_this, id, value)
#define test_ContainerNestedLeafSet(_this, id, value) _this = _this ? _this : (test_ContainerNestedLeaf*)corto_ptr_new(test_ContainerNestedLeaf_o); _test_ContainerNestedLeafAssign(_this, id, value)

/* /test/ContainerNestedLeaf/ChildLeaf */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ContainerNestedLeaf_ChildLeafCreate test_ContainerNestedLeaf_ChildLeafCreate
#endif
TEST_EXPORT test_ContainerNestedLeaf_ChildLeaf _test_ContainerNestedLeaf_ChildLeafCreate(int32_t id, corto_string value);
#define test_ContainerNestedLeaf_ChildLeafCreate(id, value) _test_ContainerNestedLeaf_ChildLeafCreate(id, value)
#define test_ContainerNestedLeaf_ChildLeafCreate_auto(_id, id, value) test_ContainerNestedLeaf_ChildLeaf _id = test_ContainerNestedLeaf_ChildLeafCreate(id, value); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ContainerNestedLeaf_ChildLeafCreateChild test_ContainerNestedLeaf_ChildLeafCreateChild
#endif
TEST_EXPORT test_ContainerNestedLeaf_ChildLeaf _test_ContainerNestedLeaf_ChildLeafCreateChild(corto_object _parent, corto_string _id, int32_t id, corto_string value);
#define test_ContainerNestedLeaf_ChildLeafCreateChild(_parent, _id, id, value) _test_ContainerNestedLeaf_ChildLeafCreateChild(_parent, _id, id, value)
#define test_ContainerNestedLeaf_ChildLeafCreateChild_auto(_parent, _id, id, value) test_ContainerNestedLeaf_ChildLeaf _id = test_ContainerNestedLeaf_ChildLeafCreateChild(_parent, #_id, id, value); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ContainerNestedLeaf_ChildLeafUpdate test_ContainerNestedLeaf_ChildLeafUpdate
#endif
TEST_EXPORT corto_int16 _test_ContainerNestedLeaf_ChildLeafUpdate(test_ContainerNestedLeaf_ChildLeaf _this, int32_t id, corto_string value);
#define test_ContainerNestedLeaf_ChildLeafUpdate(_this, id, value) _test_ContainerNestedLeaf_ChildLeafUpdate(test_ContainerNestedLeaf_ChildLeaf(_this), id, value)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ContainerNestedLeaf_ChildLeafDeclare test_ContainerNestedLeaf_ChildLeafDeclare
#endif
TEST_EXPORT test_ContainerNestedLeaf_ChildLeaf _test_ContainerNestedLeaf_ChildLeafDeclare(void);
#define test_ContainerNestedLeaf_ChildLeafDeclare() _test_ContainerNestedLeaf_ChildLeafDeclare()
#define test_ContainerNestedLeaf_ChildLeafDeclare_auto(_id) test_ContainerNestedLeaf_ChildLeaf _id = test_ContainerNestedLeaf_ChildLeafDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ContainerNestedLeaf_ChildLeafDeclareChild test_ContainerNestedLeaf_ChildLeafDeclareChild
#endif
TEST_EXPORT test_ContainerNestedLeaf_ChildLeaf _test_ContainerNestedLeaf_ChildLeafDeclareChild(corto_object _parent, corto_string _id);
#define test_ContainerNestedLeaf_ChildLeafDeclareChild(_parent, _id) _test_ContainerNestedLeaf_ChildLeafDeclareChild(_parent, _id)
#define test_ContainerNestedLeaf_ChildLeafDeclareChild_auto(_parent, _id) test_ContainerNestedLeaf_ChildLeaf _id = test_ContainerNestedLeaf_ChildLeafDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ContainerNestedLeaf_ChildLeafDefine test_ContainerNestedLeaf_ChildLeafDefine
#endif
TEST_EXPORT corto_int16 _test_ContainerNestedLeaf_ChildLeafDefine(test_ContainerNestedLeaf_ChildLeaf _this, int32_t id, corto_string value);
#define test_ContainerNestedLeaf_ChildLeafDefine(_this, id, value) _test_ContainerNestedLeaf_ChildLeafDefine(test_ContainerNestedLeaf_ChildLeaf(_this), id, value)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ContainerNestedLeaf_ChildLeafAssign test_ContainerNestedLeaf_ChildLeafAssign
#endif
TEST_EXPORT test_ContainerNestedLeaf_ChildLeaf _test_ContainerNestedLeaf_ChildLeafAssign(test_ContainerNestedLeaf_ChildLeaf _this, int32_t id, corto_string value);
#define test_ContainerNestedLeaf_ChildLeaf__optional_NotSet NULL
#define test_ContainerNestedLeaf_ChildLeaf__optional_Set(id, value) test_ContainerNestedLeaf_ChildLeafAssign((test_ContainerNestedLeaf_ChildLeaf*)corto_ptr_new(test_ContainerNestedLeaf_ChildLeaf_o)), id, value)
#define test_ContainerNestedLeaf_ChildLeaf__optional_SetCond(cond, id, value) cond ? test_ContainerNestedLeaf_ChildLeafAssign((test_ContainerNestedLeaf_ChildLeaf*)corto_ptr_new(test_ContainerNestedLeaf_ChildLeaf_o), id, value) : NULL
#define test_ContainerNestedLeaf_ChildLeafUnset(_this) _this ? corto_ptr_free(_this, test_ContainerNestedLeaf_ChildLeaf_o), 0 : 0; _this = NULL;
#define test_ContainerNestedLeaf_ChildLeafAssign(_this, id, value) _test_ContainerNestedLeaf_ChildLeafAssign(_this, id, value)
#define test_ContainerNestedLeaf_ChildLeafSet(_this, id, value) _this = _this ? _this : (test_ContainerNestedLeaf_ChildLeaf*)corto_ptr_new(test_ContainerNestedLeaf_ChildLeaf_o); _test_ContainerNestedLeaf_ChildLeafAssign(_this, id, value)

/* /test/ContainerNestedTable */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ContainerNestedTableCreate test_ContainerNestedTableCreate
#endif
TEST_EXPORT test_ContainerNestedTable _test_ContainerNestedTableCreate(int32_t id, corto_string value);
#define test_ContainerNestedTableCreate(id, value) _test_ContainerNestedTableCreate(id, value)
#define test_ContainerNestedTableCreate_auto(_id, id, value) test_ContainerNestedTable _id = test_ContainerNestedTableCreate(id, value); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ContainerNestedTableCreateChild test_ContainerNestedTableCreateChild
#endif
TEST_EXPORT test_ContainerNestedTable _test_ContainerNestedTableCreateChild(corto_object _parent, corto_string _id, int32_t id, corto_string value);
#define test_ContainerNestedTableCreateChild(_parent, _id, id, value) _test_ContainerNestedTableCreateChild(_parent, _id, id, value)
#define test_ContainerNestedTableCreateChild_auto(_parent, _id, id, value) test_ContainerNestedTable _id = test_ContainerNestedTableCreateChild(_parent, #_id, id, value); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ContainerNestedTableUpdate test_ContainerNestedTableUpdate
#endif
TEST_EXPORT corto_int16 _test_ContainerNestedTableUpdate(test_ContainerNestedTable _this, int32_t id, corto_string value);
#define test_ContainerNestedTableUpdate(_this, id, value) _test_ContainerNestedTableUpdate(test_ContainerNestedTable(_this), id, value)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ContainerNestedTableDeclare test_ContainerNestedTableDeclare
#endif
TEST_EXPORT test_ContainerNestedTable _test_ContainerNestedTableDeclare(void);
#define test_ContainerNestedTableDeclare() _test_ContainerNestedTableDeclare()
#define test_ContainerNestedTableDeclare_auto(_id) test_ContainerNestedTable _id = test_ContainerNestedTableDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ContainerNestedTableDeclareChild test_ContainerNestedTableDeclareChild
#endif
TEST_EXPORT test_ContainerNestedTable _test_ContainerNestedTableDeclareChild(corto_object _parent, corto_string _id);
#define test_ContainerNestedTableDeclareChild(_parent, _id) _test_ContainerNestedTableDeclareChild(_parent, _id)
#define test_ContainerNestedTableDeclareChild_auto(_parent, _id) test_ContainerNestedTable _id = test_ContainerNestedTableDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ContainerNestedTableDefine test_ContainerNestedTableDefine
#endif
TEST_EXPORT corto_int16 _test_ContainerNestedTableDefine(test_ContainerNestedTable _this, int32_t id, corto_string value);
#define test_ContainerNestedTableDefine(_this, id, value) _test_ContainerNestedTableDefine(test_ContainerNestedTable(_this), id, value)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ContainerNestedTableAssign test_ContainerNestedTableAssign
#endif
TEST_EXPORT test_ContainerNestedTable _test_ContainerNestedTableAssign(test_ContainerNestedTable _this, int32_t id, corto_string value);
#define test_ContainerNestedTable__optional_NotSet NULL
#define test_ContainerNestedTable__optional_Set(id, value) test_ContainerNestedTableAssign((test_ContainerNestedTable*)corto_ptr_new(test_ContainerNestedTable_o)), id, value)
#define test_ContainerNestedTable__optional_SetCond(cond, id, value) cond ? test_ContainerNestedTableAssign((test_ContainerNestedTable*)corto_ptr_new(test_ContainerNestedTable_o), id, value) : NULL
#define test_ContainerNestedTableUnset(_this) _this ? corto_ptr_free(_this, test_ContainerNestedTable_o), 0 : 0; _this = NULL;
#define test_ContainerNestedTableAssign(_this, id, value) _test_ContainerNestedTableAssign(_this, id, value)
#define test_ContainerNestedTableSet(_this, id, value) _this = _this ? _this : (test_ContainerNestedTable*)corto_ptr_new(test_ContainerNestedTable_o); _test_ContainerNestedTableAssign(_this, id, value)

/* /test/ContainerNestedTable/ChildTable */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ContainerNestedTable_ChildTableCreate test_ContainerNestedTable_ChildTableCreate
#endif
TEST_EXPORT test_ContainerNestedTable_ChildTable _test_ContainerNestedTable_ChildTableCreate(corto_string value);
#define test_ContainerNestedTable_ChildTableCreate(value) _test_ContainerNestedTable_ChildTableCreate(value)
#define test_ContainerNestedTable_ChildTableCreate_auto(_id, value) test_ContainerNestedTable_ChildTable _id = test_ContainerNestedTable_ChildTableCreate(value); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ContainerNestedTable_ChildTableCreateChild test_ContainerNestedTable_ChildTableCreateChild
#endif
TEST_EXPORT test_ContainerNestedTable_ChildTable _test_ContainerNestedTable_ChildTableCreateChild(corto_object _parent, corto_string _id, corto_string value);
#define test_ContainerNestedTable_ChildTableCreateChild(_parent, _id, value) _test_ContainerNestedTable_ChildTableCreateChild(_parent, _id, value)
#define test_ContainerNestedTable_ChildTableCreateChild_auto(_parent, _id, value) test_ContainerNestedTable_ChildTable _id = test_ContainerNestedTable_ChildTableCreateChild(_parent, #_id, value); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ContainerNestedTable_ChildTableUpdate test_ContainerNestedTable_ChildTableUpdate
#endif
TEST_EXPORT corto_int16 _test_ContainerNestedTable_ChildTableUpdate(test_ContainerNestedTable_ChildTable _this, corto_string value);
#define test_ContainerNestedTable_ChildTableUpdate(_this, value) _test_ContainerNestedTable_ChildTableUpdate(test_ContainerNestedTable_ChildTable(_this), value)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ContainerNestedTable_ChildTableDeclare test_ContainerNestedTable_ChildTableDeclare
#endif
TEST_EXPORT test_ContainerNestedTable_ChildTable _test_ContainerNestedTable_ChildTableDeclare(void);
#define test_ContainerNestedTable_ChildTableDeclare() _test_ContainerNestedTable_ChildTableDeclare()
#define test_ContainerNestedTable_ChildTableDeclare_auto(_id) test_ContainerNestedTable_ChildTable _id = test_ContainerNestedTable_ChildTableDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ContainerNestedTable_ChildTableDeclareChild test_ContainerNestedTable_ChildTableDeclareChild
#endif
TEST_EXPORT test_ContainerNestedTable_ChildTable _test_ContainerNestedTable_ChildTableDeclareChild(corto_object _parent, corto_string _id);
#define test_ContainerNestedTable_ChildTableDeclareChild(_parent, _id) _test_ContainerNestedTable_ChildTableDeclareChild(_parent, _id)
#define test_ContainerNestedTable_ChildTableDeclareChild_auto(_parent, _id) test_ContainerNestedTable_ChildTable _id = test_ContainerNestedTable_ChildTableDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ContainerNestedTable_ChildTableDefine test_ContainerNestedTable_ChildTableDefine
#endif
TEST_EXPORT corto_int16 _test_ContainerNestedTable_ChildTableDefine(test_ContainerNestedTable_ChildTable _this, corto_string value);
#define test_ContainerNestedTable_ChildTableDefine(_this, value) _test_ContainerNestedTable_ChildTableDefine(test_ContainerNestedTable_ChildTable(_this), value)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ContainerNestedTable_ChildTableAssign test_ContainerNestedTable_ChildTableAssign
#endif
TEST_EXPORT test_ContainerNestedTable_ChildTable _test_ContainerNestedTable_ChildTableAssign(test_ContainerNestedTable_ChildTable _this, corto_string value);
#define test_ContainerNestedTable_ChildTable__optional_NotSet NULL
#define test_ContainerNestedTable_ChildTable__optional_Set(value) test_ContainerNestedTable_ChildTableAssign((test_ContainerNestedTable_ChildTable*)corto_ptr_new(test_ContainerNestedTable_ChildTable_o)), value)
#define test_ContainerNestedTable_ChildTable__optional_SetCond(cond, value) cond ? test_ContainerNestedTable_ChildTableAssign((test_ContainerNestedTable_ChildTable*)corto_ptr_new(test_ContainerNestedTable_ChildTable_o), value) : NULL
#define test_ContainerNestedTable_ChildTableUnset(_this) _this ? corto_ptr_free(_this, test_ContainerNestedTable_ChildTable_o), 0 : 0; _this = NULL;
#define test_ContainerNestedTable_ChildTableAssign(_this, value) _test_ContainerNestedTable_ChildTableAssign(_this, value)
#define test_ContainerNestedTable_ChildTableSet(_this, value) _this = _this ? _this : (test_ContainerNestedTable_ChildTable*)corto_ptr_new(test_ContainerNestedTable_ChildTable_o); _test_ContainerNestedTable_ChildTableAssign(_this, value)

/* /test/Copy */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define CopyCreate test_CopyCreate
#endif
TEST_EXPORT test_Copy _test_CopyCreate(uint32_t assertCount);
#define test_CopyCreate(assertCount) _test_CopyCreate(assertCount)
#define test_CopyCreate_auto(_id, assertCount) test_Copy _id = test_CopyCreate(assertCount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define CopyCreateChild test_CopyCreateChild
#endif
TEST_EXPORT test_Copy _test_CopyCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount);
#define test_CopyCreateChild(_parent, _id, assertCount) _test_CopyCreateChild(_parent, _id, assertCount)
#define test_CopyCreateChild_auto(_parent, _id, assertCount) test_Copy _id = test_CopyCreateChild(_parent, #_id, assertCount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define CopyUpdate test_CopyUpdate
#endif
TEST_EXPORT corto_int16 _test_CopyUpdate(test_Copy _this, uint32_t assertCount);
#define test_CopyUpdate(_this, assertCount) _test_CopyUpdate(test_Copy(_this), assertCount)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define CopyDeclare test_CopyDeclare
#endif
TEST_EXPORT test_Copy _test_CopyDeclare(void);
#define test_CopyDeclare() _test_CopyDeclare()
#define test_CopyDeclare_auto(_id) test_Copy _id = test_CopyDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define CopyDeclareChild test_CopyDeclareChild
#endif
TEST_EXPORT test_Copy _test_CopyDeclareChild(corto_object _parent, corto_string _id);
#define test_CopyDeclareChild(_parent, _id) _test_CopyDeclareChild(_parent, _id)
#define test_CopyDeclareChild_auto(_parent, _id) test_Copy _id = test_CopyDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define CopyDefine test_CopyDefine
#endif
TEST_EXPORT corto_int16 _test_CopyDefine(test_Copy _this, uint32_t assertCount);
#define test_CopyDefine(_this, assertCount) _test_CopyDefine(test_Copy(_this), assertCount)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define CopyAssign test_CopyAssign
#endif
TEST_EXPORT test_Copy _test_CopyAssign(test_Copy _this, uint32_t assertCount);
#define test_Copy__optional_NotSet NULL
#define test_Copy__optional_Set(assertCount) test_CopyAssign((test_Copy*)corto_ptr_new(test_Copy_o)), assertCount)
#define test_Copy__optional_SetCond(cond, assertCount) cond ? test_CopyAssign((test_Copy*)corto_ptr_new(test_Copy_o), assertCount) : NULL
#define test_CopyUnset(_this) _this ? corto_ptr_free(_this, test_Copy_o), 0 : 0; _this = NULL;
#define test_CopyAssign(_this, assertCount) _test_CopyAssign(_this, assertCount)
#define test_CopySet(_this, assertCount) _this = _this ? _this : (test_Copy*)corto_ptr_new(test_Copy_o); _test_CopyAssign(_this, assertCount)

/* /test/DeclaredParent */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define DeclaredParentCreate test_DeclaredParentCreate
#endif
TEST_EXPORT test_DeclaredParent* _test_DeclaredParentCreate(int32_t foo);
#define test_DeclaredParentCreate(foo) _test_DeclaredParentCreate(foo)
#define test_DeclaredParentCreate_auto(_id, foo) test_DeclaredParent* _id = test_DeclaredParentCreate(foo); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define DeclaredParentCreateChild test_DeclaredParentCreateChild
#endif
TEST_EXPORT test_DeclaredParent* _test_DeclaredParentCreateChild(corto_object _parent, corto_string _id, int32_t foo);
#define test_DeclaredParentCreateChild(_parent, _id, foo) _test_DeclaredParentCreateChild(_parent, _id, foo)
#define test_DeclaredParentCreateChild_auto(_parent, _id, foo) test_DeclaredParent* _id = test_DeclaredParentCreateChild(_parent, #_id, foo); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define DeclaredParentUpdate test_DeclaredParentUpdate
#endif
TEST_EXPORT corto_int16 _test_DeclaredParentUpdate(test_DeclaredParent* _this, int32_t foo);
#define test_DeclaredParentUpdate(_this, foo) _test_DeclaredParentUpdate(test_DeclaredParent(_this), foo)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define DeclaredParentDeclare test_DeclaredParentDeclare
#endif
TEST_EXPORT test_DeclaredParent* _test_DeclaredParentDeclare(void);
#define test_DeclaredParentDeclare() _test_DeclaredParentDeclare()
#define test_DeclaredParentDeclare_auto(_id) test_DeclaredParent* _id = test_DeclaredParentDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define DeclaredParentDeclareChild test_DeclaredParentDeclareChild
#endif
TEST_EXPORT test_DeclaredParent* _test_DeclaredParentDeclareChild(corto_object _parent, corto_string _id);
#define test_DeclaredParentDeclareChild(_parent, _id) _test_DeclaredParentDeclareChild(_parent, _id)
#define test_DeclaredParentDeclareChild_auto(_parent, _id) test_DeclaredParent* _id = test_DeclaredParentDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define DeclaredParentDefine test_DeclaredParentDefine
#endif
TEST_EXPORT corto_int16 _test_DeclaredParentDefine(test_DeclaredParent* _this, int32_t foo);
#define test_DeclaredParentDefine(_this, foo) _test_DeclaredParentDefine(test_DeclaredParent(_this), foo)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define DeclaredParentAssign test_DeclaredParentAssign
#endif
TEST_EXPORT test_DeclaredParent* _test_DeclaredParentAssign(test_DeclaredParent* _this, int32_t foo);
#define test_DeclaredParent__optional_NotSet NULL
#define test_DeclaredParent__optional_Set(foo) test_DeclaredParentAssign((test_DeclaredParent*)corto_ptr_new(test_DeclaredParent_o)), foo)
#define test_DeclaredParent__optional_SetCond(cond, foo) cond ? test_DeclaredParentAssign((test_DeclaredParent*)corto_ptr_new(test_DeclaredParent_o), foo) : NULL
#define test_DeclaredParentUnset(_this) _this ? corto_ptr_free(_this, test_DeclaredParent_o), 0 : 0; _this = NULL;
#define test_DeclaredParentAssign(_this, foo) _test_DeclaredParentAssign(_this, foo)
#define test_DeclaredParentSet(_this, foo) _this = _this ? _this : (test_DeclaredParent*)corto_ptr_new(test_DeclaredParent_o); _test_DeclaredParentAssign(_this, foo)

/* /test/DefinedParent */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define DefinedParentCreate test_DefinedParentCreate
#endif
TEST_EXPORT test_DefinedParent* _test_DefinedParentCreate(int32_t foo);
#define test_DefinedParentCreate(foo) _test_DefinedParentCreate(foo)
#define test_DefinedParentCreate_auto(_id, foo) test_DefinedParent* _id = test_DefinedParentCreate(foo); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define DefinedParentCreateChild test_DefinedParentCreateChild
#endif
TEST_EXPORT test_DefinedParent* _test_DefinedParentCreateChild(corto_object _parent, corto_string _id, int32_t foo);
#define test_DefinedParentCreateChild(_parent, _id, foo) _test_DefinedParentCreateChild(_parent, _id, foo)
#define test_DefinedParentCreateChild_auto(_parent, _id, foo) test_DefinedParent* _id = test_DefinedParentCreateChild(_parent, #_id, foo); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define DefinedParentUpdate test_DefinedParentUpdate
#endif
TEST_EXPORT corto_int16 _test_DefinedParentUpdate(test_DefinedParent* _this, int32_t foo);
#define test_DefinedParentUpdate(_this, foo) _test_DefinedParentUpdate(test_DefinedParent(_this), foo)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define DefinedParentDeclare test_DefinedParentDeclare
#endif
TEST_EXPORT test_DefinedParent* _test_DefinedParentDeclare(void);
#define test_DefinedParentDeclare() _test_DefinedParentDeclare()
#define test_DefinedParentDeclare_auto(_id) test_DefinedParent* _id = test_DefinedParentDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define DefinedParentDeclareChild test_DefinedParentDeclareChild
#endif
TEST_EXPORT test_DefinedParent* _test_DefinedParentDeclareChild(corto_object _parent, corto_string _id);
#define test_DefinedParentDeclareChild(_parent, _id) _test_DefinedParentDeclareChild(_parent, _id)
#define test_DefinedParentDeclareChild_auto(_parent, _id) test_DefinedParent* _id = test_DefinedParentDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define DefinedParentDefine test_DefinedParentDefine
#endif
TEST_EXPORT corto_int16 _test_DefinedParentDefine(test_DefinedParent* _this, int32_t foo);
#define test_DefinedParentDefine(_this, foo) _test_DefinedParentDefine(test_DefinedParent(_this), foo)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define DefinedParentAssign test_DefinedParentAssign
#endif
TEST_EXPORT test_DefinedParent* _test_DefinedParentAssign(test_DefinedParent* _this, int32_t foo);
#define test_DefinedParent__optional_NotSet NULL
#define test_DefinedParent__optional_Set(foo) test_DefinedParentAssign((test_DefinedParent*)corto_ptr_new(test_DefinedParent_o)), foo)
#define test_DefinedParent__optional_SetCond(cond, foo) cond ? test_DefinedParentAssign((test_DefinedParent*)corto_ptr_new(test_DefinedParent_o), foo) : NULL
#define test_DefinedParentUnset(_this) _this ? corto_ptr_free(_this, test_DefinedParent_o), 0 : 0; _this = NULL;
#define test_DefinedParentAssign(_this, foo) _test_DefinedParentAssign(_this, foo)
#define test_DefinedParentSet(_this, foo) _this = _this ? _this : (test_DefinedParent*)corto_ptr_new(test_DefinedParent_o); _test_DefinedParentAssign(_this, foo)

/* /test/Dog */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define DogCreate test_DogCreate
#endif
TEST_EXPORT test_Dog _test_DogCreate(bool a, bool b);
#define test_DogCreate(a, b) _test_DogCreate(a, b)
#define test_DogCreate_auto(_id, a, b) test_Dog _id = test_DogCreate(a, b); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define DogCreateChild test_DogCreateChild
#endif
TEST_EXPORT test_Dog _test_DogCreateChild(corto_object _parent, corto_string _id, bool a, bool b);
#define test_DogCreateChild(_parent, _id, a, b) _test_DogCreateChild(_parent, _id, a, b)
#define test_DogCreateChild_auto(_parent, _id, a, b) test_Dog _id = test_DogCreateChild(_parent, #_id, a, b); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define DogUpdate test_DogUpdate
#endif
TEST_EXPORT corto_int16 _test_DogUpdate(test_Dog _this, bool a, bool b);
#define test_DogUpdate(_this, a, b) _test_DogUpdate(test_Dog(_this), a, b)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define DogDeclare test_DogDeclare
#endif
TEST_EXPORT test_Dog _test_DogDeclare(void);
#define test_DogDeclare() _test_DogDeclare()
#define test_DogDeclare_auto(_id) test_Dog _id = test_DogDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define DogDeclareChild test_DogDeclareChild
#endif
TEST_EXPORT test_Dog _test_DogDeclareChild(corto_object _parent, corto_string _id);
#define test_DogDeclareChild(_parent, _id) _test_DogDeclareChild(_parent, _id)
#define test_DogDeclareChild_auto(_parent, _id) test_Dog _id = test_DogDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define DogDefine test_DogDefine
#endif
TEST_EXPORT corto_int16 _test_DogDefine(test_Dog _this, bool a, bool b);
#define test_DogDefine(_this, a, b) _test_DogDefine(test_Dog(_this), a, b)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define DogAssign test_DogAssign
#endif
TEST_EXPORT test_Dog _test_DogAssign(test_Dog _this, bool a, bool b);
#define test_Dog__optional_NotSet NULL
#define test_Dog__optional_Set(a, b) test_DogAssign((test_Dog*)corto_ptr_new(test_Dog_o)), a, b)
#define test_Dog__optional_SetCond(cond, a, b) cond ? test_DogAssign((test_Dog*)corto_ptr_new(test_Dog_o), a, b) : NULL
#define test_DogUnset(_this) _this ? corto_ptr_free(_this, test_Dog_o), 0 : 0; _this = NULL;
#define test_DogAssign(_this, a, b) _test_DogAssign(_this, a, b)
#define test_DogSet(_this, a, b) _this = _this ? _this : (test_Dog*)corto_ptr_new(test_Dog_o); _test_DogAssign(_this, a, b)

/* /test/Env */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define EnvCreate test_EnvCreate
#endif
TEST_EXPORT test_Env _test_EnvCreate(uint32_t assertCount);
#define test_EnvCreate(assertCount) _test_EnvCreate(assertCount)
#define test_EnvCreate_auto(_id, assertCount) test_Env _id = test_EnvCreate(assertCount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define EnvCreateChild test_EnvCreateChild
#endif
TEST_EXPORT test_Env _test_EnvCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount);
#define test_EnvCreateChild(_parent, _id, assertCount) _test_EnvCreateChild(_parent, _id, assertCount)
#define test_EnvCreateChild_auto(_parent, _id, assertCount) test_Env _id = test_EnvCreateChild(_parent, #_id, assertCount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define EnvUpdate test_EnvUpdate
#endif
TEST_EXPORT corto_int16 _test_EnvUpdate(test_Env _this, uint32_t assertCount);
#define test_EnvUpdate(_this, assertCount) _test_EnvUpdate(test_Env(_this), assertCount)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define EnvDeclare test_EnvDeclare
#endif
TEST_EXPORT test_Env _test_EnvDeclare(void);
#define test_EnvDeclare() _test_EnvDeclare()
#define test_EnvDeclare_auto(_id) test_Env _id = test_EnvDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define EnvDeclareChild test_EnvDeclareChild
#endif
TEST_EXPORT test_Env _test_EnvDeclareChild(corto_object _parent, corto_string _id);
#define test_EnvDeclareChild(_parent, _id) _test_EnvDeclareChild(_parent, _id)
#define test_EnvDeclareChild_auto(_parent, _id) test_Env _id = test_EnvDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define EnvDefine test_EnvDefine
#endif
TEST_EXPORT corto_int16 _test_EnvDefine(test_Env _this, uint32_t assertCount);
#define test_EnvDefine(_this, assertCount) _test_EnvDefine(test_Env(_this), assertCount)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define EnvAssign test_EnvAssign
#endif
TEST_EXPORT test_Env _test_EnvAssign(test_Env _this, uint32_t assertCount);
#define test_Env__optional_NotSet NULL
#define test_Env__optional_Set(assertCount) test_EnvAssign((test_Env*)corto_ptr_new(test_Env_o)), assertCount)
#define test_Env__optional_SetCond(cond, assertCount) cond ? test_EnvAssign((test_Env*)corto_ptr_new(test_Env_o), assertCount) : NULL
#define test_EnvUnset(_this) _this ? corto_ptr_free(_this, test_Env_o), 0 : 0; _this = NULL;
#define test_EnvAssign(_this, assertCount) _test_EnvAssign(_this, assertCount)
#define test_EnvSet(_this, assertCount) _this = _this ? _this : (test_Env*)corto_ptr_new(test_Env_o); _test_EnvAssign(_this, assertCount)

/* /test/Err */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ErrCreate test_ErrCreate
#endif
TEST_EXPORT test_Err _test_ErrCreate(uint32_t assertCount, int32_t level, corto_string msg, corto_string category);
#define test_ErrCreate(assertCount, level, msg, category) _test_ErrCreate(assertCount, level, msg, category)
#define test_ErrCreate_auto(_id, assertCount, level, msg, category) test_Err _id = test_ErrCreate(assertCount, level, msg, category); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ErrCreateChild test_ErrCreateChild
#endif
TEST_EXPORT test_Err _test_ErrCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount, int32_t level, corto_string msg, corto_string category);
#define test_ErrCreateChild(_parent, _id, assertCount, level, msg, category) _test_ErrCreateChild(_parent, _id, assertCount, level, msg, category)
#define test_ErrCreateChild_auto(_parent, _id, assertCount, level, msg, category) test_Err _id = test_ErrCreateChild(_parent, #_id, assertCount, level, msg, category); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ErrUpdate test_ErrUpdate
#endif
TEST_EXPORT corto_int16 _test_ErrUpdate(test_Err _this, uint32_t assertCount, int32_t level, corto_string msg, corto_string category);
#define test_ErrUpdate(_this, assertCount, level, msg, category) _test_ErrUpdate(test_Err(_this), assertCount, level, msg, category)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ErrDeclare test_ErrDeclare
#endif
TEST_EXPORT test_Err _test_ErrDeclare(void);
#define test_ErrDeclare() _test_ErrDeclare()
#define test_ErrDeclare_auto(_id) test_Err _id = test_ErrDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ErrDeclareChild test_ErrDeclareChild
#endif
TEST_EXPORT test_Err _test_ErrDeclareChild(corto_object _parent, corto_string _id);
#define test_ErrDeclareChild(_parent, _id) _test_ErrDeclareChild(_parent, _id)
#define test_ErrDeclareChild_auto(_parent, _id) test_Err _id = test_ErrDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ErrDefine test_ErrDefine
#endif
TEST_EXPORT corto_int16 _test_ErrDefine(test_Err _this, uint32_t assertCount, int32_t level, corto_string msg, corto_string category);
#define test_ErrDefine(_this, assertCount, level, msg, category) _test_ErrDefine(test_Err(_this), assertCount, level, msg, category)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ErrAssign test_ErrAssign
#endif
TEST_EXPORT test_Err _test_ErrAssign(test_Err _this, uint32_t assertCount, int32_t level, corto_string msg, corto_string category);
#define test_Err__optional_NotSet NULL
#define test_Err__optional_Set(assertCount, level, msg, category) test_ErrAssign((test_Err*)corto_ptr_new(test_Err_o)), assertCount, level, msg, category)
#define test_Err__optional_SetCond(cond, assertCount, level, msg, category) cond ? test_ErrAssign((test_Err*)corto_ptr_new(test_Err_o), assertCount, level, msg, category) : NULL
#define test_ErrUnset(_this) _this ? corto_ptr_free(_this, test_Err_o), 0 : 0; _this = NULL;
#define test_ErrAssign(_this, assertCount, level, msg, category) _test_ErrAssign(_this, assertCount, level, msg, category)
#define test_ErrSet(_this, assertCount, level, msg, category) _this = _this ? _this : (test_Err*)corto_ptr_new(test_Err_o); _test_ErrAssign(_this, assertCount, level, msg, category)

/* /test/Event */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define EventCreate test_EventCreate
#endif
TEST_EXPORT test_Event _test_EventCreate(uint32_t assertCount, test_EventTest et, corto_attr prevAttr);
#define test_EventCreate(assertCount, et, prevAttr) _test_EventCreate(assertCount, test_EventTest(et), prevAttr)
#define test_EventCreate_auto(_id, assertCount, et, prevAttr) test_Event _id = test_EventCreate(assertCount, et, prevAttr); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define EventCreateChild test_EventCreateChild
#endif
TEST_EXPORT test_Event _test_EventCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount, test_EventTest et, corto_attr prevAttr);
#define test_EventCreateChild(_parent, _id, assertCount, et, prevAttr) _test_EventCreateChild(_parent, _id, assertCount, test_EventTest(et), prevAttr)
#define test_EventCreateChild_auto(_parent, _id, assertCount, et, prevAttr) test_Event _id = test_EventCreateChild(_parent, #_id, assertCount, et, prevAttr); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define EventUpdate test_EventUpdate
#endif
TEST_EXPORT corto_int16 _test_EventUpdate(test_Event _this, uint32_t assertCount, test_EventTest et, corto_attr prevAttr);
#define test_EventUpdate(_this, assertCount, et, prevAttr) _test_EventUpdate(test_Event(_this), assertCount, test_EventTest(et), prevAttr)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define EventDeclare test_EventDeclare
#endif
TEST_EXPORT test_Event _test_EventDeclare(void);
#define test_EventDeclare() _test_EventDeclare()
#define test_EventDeclare_auto(_id) test_Event _id = test_EventDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define EventDeclareChild test_EventDeclareChild
#endif
TEST_EXPORT test_Event _test_EventDeclareChild(corto_object _parent, corto_string _id);
#define test_EventDeclareChild(_parent, _id) _test_EventDeclareChild(_parent, _id)
#define test_EventDeclareChild_auto(_parent, _id) test_Event _id = test_EventDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define EventDefine test_EventDefine
#endif
TEST_EXPORT corto_int16 _test_EventDefine(test_Event _this, uint32_t assertCount, test_EventTest et, corto_attr prevAttr);
#define test_EventDefine(_this, assertCount, et, prevAttr) _test_EventDefine(test_Event(_this), assertCount, test_EventTest(et), prevAttr)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define EventAssign test_EventAssign
#endif
TEST_EXPORT test_Event _test_EventAssign(test_Event _this, uint32_t assertCount, test_EventTest et, corto_attr prevAttr);
#define test_Event__optional_NotSet NULL
#define test_Event__optional_Set(assertCount, et, prevAttr) test_EventAssign((test_Event*)corto_ptr_new(test_Event_o)), assertCount, et, prevAttr)
#define test_Event__optional_SetCond(cond, assertCount, et, prevAttr) cond ? test_EventAssign((test_Event*)corto_ptr_new(test_Event_o), assertCount, et, prevAttr) : NULL
#define test_EventUnset(_this) _this ? corto_ptr_free(_this, test_Event_o), 0 : 0; _this = NULL;
#define test_EventAssign(_this, assertCount, et, prevAttr) _test_EventAssign(_this, assertCount, test_EventTest(et), prevAttr)
#define test_EventSet(_this, assertCount, et, prevAttr) _this = _this ? _this : (test_Event*)corto_ptr_new(test_Event_o); _test_EventAssign(_this, assertCount, test_EventTest(et), prevAttr)

/* /test/EventCount */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define EventCountCreate test_EventCountCreate
#endif
TEST_EXPORT test_EventCount* _test_EventCountCreate(int32_t declareCount, int32_t defineCount, int32_t updateCount, int32_t deleteCount, int32_t resumeCount, int32_t suspendCount);
#define test_EventCountCreate(declareCount, defineCount, updateCount, deleteCount, resumeCount, suspendCount) _test_EventCountCreate(declareCount, defineCount, updateCount, deleteCount, resumeCount, suspendCount)
#define test_EventCountCreate_auto(_id, declareCount, defineCount, updateCount, deleteCount, resumeCount, suspendCount) test_EventCount* _id = test_EventCountCreate(declareCount, defineCount, updateCount, deleteCount, resumeCount, suspendCount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define EventCountCreateChild test_EventCountCreateChild
#endif
TEST_EXPORT test_EventCount* _test_EventCountCreateChild(corto_object _parent, corto_string _id, int32_t declareCount, int32_t defineCount, int32_t updateCount, int32_t deleteCount, int32_t resumeCount, int32_t suspendCount);
#define test_EventCountCreateChild(_parent, _id, declareCount, defineCount, updateCount, deleteCount, resumeCount, suspendCount) _test_EventCountCreateChild(_parent, _id, declareCount, defineCount, updateCount, deleteCount, resumeCount, suspendCount)
#define test_EventCountCreateChild_auto(_parent, _id, declareCount, defineCount, updateCount, deleteCount, resumeCount, suspendCount) test_EventCount* _id = test_EventCountCreateChild(_parent, #_id, declareCount, defineCount, updateCount, deleteCount, resumeCount, suspendCount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define EventCountUpdate test_EventCountUpdate
#endif
TEST_EXPORT corto_int16 _test_EventCountUpdate(test_EventCount* _this, int32_t declareCount, int32_t defineCount, int32_t updateCount, int32_t deleteCount, int32_t resumeCount, int32_t suspendCount);
#define test_EventCountUpdate(_this, declareCount, defineCount, updateCount, deleteCount, resumeCount, suspendCount) _test_EventCountUpdate(test_EventCount(_this), declareCount, defineCount, updateCount, deleteCount, resumeCount, suspendCount)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define EventCountDeclare test_EventCountDeclare
#endif
TEST_EXPORT test_EventCount* _test_EventCountDeclare(void);
#define test_EventCountDeclare() _test_EventCountDeclare()
#define test_EventCountDeclare_auto(_id) test_EventCount* _id = test_EventCountDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define EventCountDeclareChild test_EventCountDeclareChild
#endif
TEST_EXPORT test_EventCount* _test_EventCountDeclareChild(corto_object _parent, corto_string _id);
#define test_EventCountDeclareChild(_parent, _id) _test_EventCountDeclareChild(_parent, _id)
#define test_EventCountDeclareChild_auto(_parent, _id) test_EventCount* _id = test_EventCountDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define EventCountDefine test_EventCountDefine
#endif
TEST_EXPORT corto_int16 _test_EventCountDefine(test_EventCount* _this, int32_t declareCount, int32_t defineCount, int32_t updateCount, int32_t deleteCount, int32_t resumeCount, int32_t suspendCount);
#define test_EventCountDefine(_this, declareCount, defineCount, updateCount, deleteCount, resumeCount, suspendCount) _test_EventCountDefine(test_EventCount(_this), declareCount, defineCount, updateCount, deleteCount, resumeCount, suspendCount)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define EventCountAssign test_EventCountAssign
#endif
TEST_EXPORT test_EventCount* _test_EventCountAssign(test_EventCount* _this, int32_t declareCount, int32_t defineCount, int32_t updateCount, int32_t deleteCount, int32_t resumeCount, int32_t suspendCount);
#define test_EventCount__optional_NotSet NULL
#define test_EventCount__optional_Set(declareCount, defineCount, updateCount, deleteCount, resumeCount, suspendCount) test_EventCountAssign((test_EventCount*)corto_ptr_new(test_EventCount_o)), declareCount, defineCount, updateCount, deleteCount, resumeCount, suspendCount)
#define test_EventCount__optional_SetCond(cond, declareCount, defineCount, updateCount, deleteCount, resumeCount, suspendCount) cond ? test_EventCountAssign((test_EventCount*)corto_ptr_new(test_EventCount_o), declareCount, defineCount, updateCount, deleteCount, resumeCount, suspendCount) : NULL
#define test_EventCountUnset(_this) _this ? corto_ptr_free(_this, test_EventCount_o), 0 : 0; _this = NULL;
#define test_EventCountAssign(_this, declareCount, defineCount, updateCount, deleteCount, resumeCount, suspendCount) _test_EventCountAssign(_this, declareCount, defineCount, updateCount, deleteCount, resumeCount, suspendCount)
#define test_EventCountSet(_this, declareCount, defineCount, updateCount, deleteCount, resumeCount, suspendCount) _this = _this ? _this : (test_EventCount*)corto_ptr_new(test_EventCount_o); _test_EventCountAssign(_this, declareCount, defineCount, updateCount, deleteCount, resumeCount, suspendCount)

/* /test/EventTest */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define EventTestCreate test_EventTestCreate
#endif
TEST_EXPORT test_EventTest _test_EventTestCreate(corto_object scope);
#define test_EventTestCreate(scope) _test_EventTestCreate(scope)
#define test_EventTestCreate_auto(_id, scope) test_EventTest _id = test_EventTestCreate(scope); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define EventTestCreateChild test_EventTestCreateChild
#endif
TEST_EXPORT test_EventTest _test_EventTestCreateChild(corto_object _parent, corto_string _id, corto_object scope);
#define test_EventTestCreateChild(_parent, _id, scope) _test_EventTestCreateChild(_parent, _id, scope)
#define test_EventTestCreateChild_auto(_parent, _id, scope) test_EventTest _id = test_EventTestCreateChild(_parent, #_id, scope); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define EventTestUpdate test_EventTestUpdate
#endif
TEST_EXPORT corto_int16 _test_EventTestUpdate(test_EventTest _this, corto_object scope);
#define test_EventTestUpdate(_this, scope) _test_EventTestUpdate(test_EventTest(_this), scope)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define EventTestDeclare test_EventTestDeclare
#endif
TEST_EXPORT test_EventTest _test_EventTestDeclare(void);
#define test_EventTestDeclare() _test_EventTestDeclare()
#define test_EventTestDeclare_auto(_id) test_EventTest _id = test_EventTestDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define EventTestDeclareChild test_EventTestDeclareChild
#endif
TEST_EXPORT test_EventTest _test_EventTestDeclareChild(corto_object _parent, corto_string _id);
#define test_EventTestDeclareChild(_parent, _id) _test_EventTestDeclareChild(_parent, _id)
#define test_EventTestDeclareChild_auto(_parent, _id) test_EventTest _id = test_EventTestDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define EventTestDefine test_EventTestDefine
#endif
TEST_EXPORT corto_int16 _test_EventTestDefine(test_EventTest _this, corto_object scope);
#define test_EventTestDefine(_this, scope) _test_EventTestDefine(test_EventTest(_this), scope)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define EventTestAssign test_EventTestAssign
#endif
TEST_EXPORT test_EventTest _test_EventTestAssign(test_EventTest _this, corto_object scope);
#define test_EventTest__optional_NotSet NULL
#define test_EventTest__optional_Set(scope) test_EventTestAssign((test_EventTest*)corto_ptr_new(test_EventTest_o)), scope)
#define test_EventTest__optional_SetCond(cond, scope) cond ? test_EventTestAssign((test_EventTest*)corto_ptr_new(test_EventTest_o), scope) : NULL
#define test_EventTestUnset(_this) _this ? corto_ptr_free(_this, test_EventTest_o), 0 : 0; _this = NULL;
#define test_EventTestAssign(_this, scope) _test_EventTestAssign(_this, scope)
#define test_EventTestSet(_this, scope) _this = _this ? _this : (test_EventTest*)corto_ptr_new(test_EventTest_o); _test_EventTestAssign(_this, scope)

/* /test/Foo */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define FooCreate test_FooCreate
#endif
TEST_EXPORT test_Foo _test_FooCreate(int32_t x, int32_t y);
#define test_FooCreate(x, y) _test_FooCreate(x, y)
#define test_FooCreate_auto(_id, x, y) test_Foo _id = test_FooCreate(x, y); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define FooCreateChild test_FooCreateChild
#endif
TEST_EXPORT test_Foo _test_FooCreateChild(corto_object _parent, corto_string _id, int32_t x, int32_t y);
#define test_FooCreateChild(_parent, _id, x, y) _test_FooCreateChild(_parent, _id, x, y)
#define test_FooCreateChild_auto(_parent, _id, x, y) test_Foo _id = test_FooCreateChild(_parent, #_id, x, y); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define FooUpdate test_FooUpdate
#endif
TEST_EXPORT corto_int16 _test_FooUpdate(test_Foo _this, int32_t x, int32_t y);
#define test_FooUpdate(_this, x, y) _test_FooUpdate(test_Foo(_this), x, y)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define FooDeclare test_FooDeclare
#endif
TEST_EXPORT test_Foo _test_FooDeclare(void);
#define test_FooDeclare() _test_FooDeclare()
#define test_FooDeclare_auto(_id) test_Foo _id = test_FooDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define FooDeclareChild test_FooDeclareChild
#endif
TEST_EXPORT test_Foo _test_FooDeclareChild(corto_object _parent, corto_string _id);
#define test_FooDeclareChild(_parent, _id) _test_FooDeclareChild(_parent, _id)
#define test_FooDeclareChild_auto(_parent, _id) test_Foo _id = test_FooDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define FooDefine test_FooDefine
#endif
TEST_EXPORT corto_int16 _test_FooDefine(test_Foo _this, int32_t x, int32_t y);
#define test_FooDefine(_this, x, y) _test_FooDefine(test_Foo(_this), x, y)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define FooAssign test_FooAssign
#endif
TEST_EXPORT test_Foo _test_FooAssign(test_Foo _this, int32_t x, int32_t y);
#define test_Foo__optional_NotSet NULL
#define test_Foo__optional_Set(x, y) test_FooAssign((test_Foo*)corto_ptr_new(test_Foo_o)), x, y)
#define test_Foo__optional_SetCond(cond, x, y) cond ? test_FooAssign((test_Foo*)corto_ptr_new(test_Foo_o), x, y) : NULL
#define test_FooUnset(_this) _this ? corto_ptr_free(_this, test_Foo_o), 0 : 0; _this = NULL;
#define test_FooAssign(_this, x, y) _test_FooAssign(_this, x, y)
#define test_FooSet(_this, x, y) _this = _this ? _this : (test_Foo*)corto_ptr_new(test_Foo_o); _test_FooAssign(_this, x, y)

/* /test/FooReplicator */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define FooReplicatorCreate test_FooReplicatorCreate
#endif
TEST_EXPORT test_FooReplicator _test_FooReplicatorCreate(corto_object mount);
#define test_FooReplicatorCreate(mount) _test_FooReplicatorCreate(mount)
#define test_FooReplicatorCreate_auto(_id, mount) test_FooReplicator _id = test_FooReplicatorCreate(mount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define FooReplicatorCreateChild test_FooReplicatorCreateChild
#endif
TEST_EXPORT test_FooReplicator _test_FooReplicatorCreateChild(corto_object _parent, corto_string _id, corto_object mount);
#define test_FooReplicatorCreateChild(_parent, _id, mount) _test_FooReplicatorCreateChild(_parent, _id, mount)
#define test_FooReplicatorCreateChild_auto(_parent, _id, mount) test_FooReplicator _id = test_FooReplicatorCreateChild(_parent, #_id, mount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define FooReplicatorUpdate test_FooReplicatorUpdate
#endif
TEST_EXPORT corto_int16 _test_FooReplicatorUpdate(test_FooReplicator _this, corto_object mount);
#define test_FooReplicatorUpdate(_this, mount) _test_FooReplicatorUpdate(test_FooReplicator(_this), mount)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define FooReplicatorDeclare test_FooReplicatorDeclare
#endif
TEST_EXPORT test_FooReplicator _test_FooReplicatorDeclare(void);
#define test_FooReplicatorDeclare() _test_FooReplicatorDeclare()
#define test_FooReplicatorDeclare_auto(_id) test_FooReplicator _id = test_FooReplicatorDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define FooReplicatorDeclareChild test_FooReplicatorDeclareChild
#endif
TEST_EXPORT test_FooReplicator _test_FooReplicatorDeclareChild(corto_object _parent, corto_string _id);
#define test_FooReplicatorDeclareChild(_parent, _id) _test_FooReplicatorDeclareChild(_parent, _id)
#define test_FooReplicatorDeclareChild_auto(_parent, _id) test_FooReplicator _id = test_FooReplicatorDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define FooReplicatorDefine test_FooReplicatorDefine
#endif
TEST_EXPORT corto_int16 _test_FooReplicatorDefine(test_FooReplicator _this, corto_object mount);
#define test_FooReplicatorDefine(_this, mount) _test_FooReplicatorDefine(test_FooReplicator(_this), mount)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define FooReplicatorAssign test_FooReplicatorAssign
#endif
TEST_EXPORT test_FooReplicator _test_FooReplicatorAssign(test_FooReplicator _this, corto_object mount);
#define test_FooReplicator__optional_NotSet NULL
#define test_FooReplicator__optional_Set(mount) test_FooReplicatorAssign((test_FooReplicator*)corto_ptr_new(test_FooReplicator_o)), mount)
#define test_FooReplicator__optional_SetCond(cond, mount) cond ? test_FooReplicatorAssign((test_FooReplicator*)corto_ptr_new(test_FooReplicator_o), mount) : NULL
#define test_FooReplicatorUnset(_this) _this ? corto_ptr_free(_this, test_FooReplicator_o), 0 : 0; _this = NULL;
#define test_FooReplicatorAssign(_this, mount) _test_FooReplicatorAssign(_this, mount)
#define test_FooReplicatorSet(_this, mount) _this = _this ? _this : (test_FooReplicator*)corto_ptr_new(test_FooReplicator_o); _test_FooReplicatorAssign(_this, mount)

/* /test/Fullname */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define FullnameCreate test_FullnameCreate
#endif
TEST_EXPORT test_Fullname _test_FullnameCreate(uint32_t assertCount);
#define test_FullnameCreate(assertCount) _test_FullnameCreate(assertCount)
#define test_FullnameCreate_auto(_id, assertCount) test_Fullname _id = test_FullnameCreate(assertCount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define FullnameCreateChild test_FullnameCreateChild
#endif
TEST_EXPORT test_Fullname _test_FullnameCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount);
#define test_FullnameCreateChild(_parent, _id, assertCount) _test_FullnameCreateChild(_parent, _id, assertCount)
#define test_FullnameCreateChild_auto(_parent, _id, assertCount) test_Fullname _id = test_FullnameCreateChild(_parent, #_id, assertCount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define FullnameUpdate test_FullnameUpdate
#endif
TEST_EXPORT corto_int16 _test_FullnameUpdate(test_Fullname _this, uint32_t assertCount);
#define test_FullnameUpdate(_this, assertCount) _test_FullnameUpdate(test_Fullname(_this), assertCount)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define FullnameDeclare test_FullnameDeclare
#endif
TEST_EXPORT test_Fullname _test_FullnameDeclare(void);
#define test_FullnameDeclare() _test_FullnameDeclare()
#define test_FullnameDeclare_auto(_id) test_Fullname _id = test_FullnameDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define FullnameDeclareChild test_FullnameDeclareChild
#endif
TEST_EXPORT test_Fullname _test_FullnameDeclareChild(corto_object _parent, corto_string _id);
#define test_FullnameDeclareChild(_parent, _id) _test_FullnameDeclareChild(_parent, _id)
#define test_FullnameDeclareChild_auto(_parent, _id) test_Fullname _id = test_FullnameDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define FullnameDefine test_FullnameDefine
#endif
TEST_EXPORT corto_int16 _test_FullnameDefine(test_Fullname _this, uint32_t assertCount);
#define test_FullnameDefine(_this, assertCount) _test_FullnameDefine(test_Fullname(_this), assertCount)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define FullnameAssign test_FullnameAssign
#endif
TEST_EXPORT test_Fullname _test_FullnameAssign(test_Fullname _this, uint32_t assertCount);
#define test_Fullname__optional_NotSet NULL
#define test_Fullname__optional_Set(assertCount) test_FullnameAssign((test_Fullname*)corto_ptr_new(test_Fullname_o)), assertCount)
#define test_Fullname__optional_SetCond(cond, assertCount) cond ? test_FullnameAssign((test_Fullname*)corto_ptr_new(test_Fullname_o), assertCount) : NULL
#define test_FullnameUnset(_this) _this ? corto_ptr_free(_this, test_Fullname_o), 0 : 0; _this = NULL;
#define test_FullnameAssign(_this, assertCount) _test_FullnameAssign(_this, assertCount)
#define test_FullnameSet(_this, assertCount) _this = _this ? _this : (test_Fullname*)corto_ptr_new(test_Fullname_o); _test_FullnameAssign(_this, assertCount)

/* /test/GoldenRetriever */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define GoldenRetrieverCreate test_GoldenRetrieverCreate
#endif
TEST_EXPORT test_GoldenRetriever _test_GoldenRetrieverCreate(bool a, bool b, bool c);
#define test_GoldenRetrieverCreate(a, b, c) _test_GoldenRetrieverCreate(a, b, c)
#define test_GoldenRetrieverCreate_auto(_id, a, b, c) test_GoldenRetriever _id = test_GoldenRetrieverCreate(a, b, c); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define GoldenRetrieverCreateChild test_GoldenRetrieverCreateChild
#endif
TEST_EXPORT test_GoldenRetriever _test_GoldenRetrieverCreateChild(corto_object _parent, corto_string _id, bool a, bool b, bool c);
#define test_GoldenRetrieverCreateChild(_parent, _id, a, b, c) _test_GoldenRetrieverCreateChild(_parent, _id, a, b, c)
#define test_GoldenRetrieverCreateChild_auto(_parent, _id, a, b, c) test_GoldenRetriever _id = test_GoldenRetrieverCreateChild(_parent, #_id, a, b, c); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define GoldenRetrieverUpdate test_GoldenRetrieverUpdate
#endif
TEST_EXPORT corto_int16 _test_GoldenRetrieverUpdate(test_GoldenRetriever _this, bool a, bool b, bool c);
#define test_GoldenRetrieverUpdate(_this, a, b, c) _test_GoldenRetrieverUpdate(test_GoldenRetriever(_this), a, b, c)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define GoldenRetrieverDeclare test_GoldenRetrieverDeclare
#endif
TEST_EXPORT test_GoldenRetriever _test_GoldenRetrieverDeclare(void);
#define test_GoldenRetrieverDeclare() _test_GoldenRetrieverDeclare()
#define test_GoldenRetrieverDeclare_auto(_id) test_GoldenRetriever _id = test_GoldenRetrieverDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define GoldenRetrieverDeclareChild test_GoldenRetrieverDeclareChild
#endif
TEST_EXPORT test_GoldenRetriever _test_GoldenRetrieverDeclareChild(corto_object _parent, corto_string _id);
#define test_GoldenRetrieverDeclareChild(_parent, _id) _test_GoldenRetrieverDeclareChild(_parent, _id)
#define test_GoldenRetrieverDeclareChild_auto(_parent, _id) test_GoldenRetriever _id = test_GoldenRetrieverDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define GoldenRetrieverDefine test_GoldenRetrieverDefine
#endif
TEST_EXPORT corto_int16 _test_GoldenRetrieverDefine(test_GoldenRetriever _this, bool a, bool b, bool c);
#define test_GoldenRetrieverDefine(_this, a, b, c) _test_GoldenRetrieverDefine(test_GoldenRetriever(_this), a, b, c)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define GoldenRetrieverAssign test_GoldenRetrieverAssign
#endif
TEST_EXPORT test_GoldenRetriever _test_GoldenRetrieverAssign(test_GoldenRetriever _this, bool a, bool b, bool c);
#define test_GoldenRetriever__optional_NotSet NULL
#define test_GoldenRetriever__optional_Set(a, b, c) test_GoldenRetrieverAssign((test_GoldenRetriever*)corto_ptr_new(test_GoldenRetriever_o)), a, b, c)
#define test_GoldenRetriever__optional_SetCond(cond, a, b, c) cond ? test_GoldenRetrieverAssign((test_GoldenRetriever*)corto_ptr_new(test_GoldenRetriever_o), a, b, c) : NULL
#define test_GoldenRetrieverUnset(_this) _this ? corto_ptr_free(_this, test_GoldenRetriever_o), 0 : 0; _this = NULL;
#define test_GoldenRetrieverAssign(_this, a, b, c) _test_GoldenRetrieverAssign(_this, a, b, c)
#define test_GoldenRetrieverSet(_this, a, b, c) _this = _this ? _this : (test_GoldenRetriever*)corto_ptr_new(test_GoldenRetriever_o); _test_GoldenRetrieverAssign(_this, a, b, c)

/* /test/Hooks */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define HooksCreate test_HooksCreate
#endif
TEST_EXPORT test_Hooks* _test_HooksCreate(test_Hooks value);
#define test_HooksCreate(value) _test_HooksCreate(value)
#define test_HooksCreate_auto(_id, value) test_Hooks* _id = test_HooksCreate(value); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define HooksCreateChild test_HooksCreateChild
#endif
TEST_EXPORT test_Hooks* _test_HooksCreateChild(corto_object _parent, corto_string _id, test_Hooks value);
#define test_HooksCreateChild(_parent, _id, value) _test_HooksCreateChild(_parent, _id, value)
#define test_HooksCreateChild_auto(_parent, _id, value) test_Hooks* _id = test_HooksCreateChild(_parent, #_id, value); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define HooksUpdate test_HooksUpdate
#endif
TEST_EXPORT corto_int16 _test_HooksUpdate(test_Hooks* _this, test_Hooks value);
#define test_HooksUpdate(_this, value) _test_HooksUpdate(test_Hooks(_this), value)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define HooksDeclare test_HooksDeclare
#endif
TEST_EXPORT test_Hooks* _test_HooksDeclare(void);
#define test_HooksDeclare() _test_HooksDeclare()
#define test_HooksDeclare_auto(_id) test_Hooks* _id = test_HooksDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define HooksDeclareChild test_HooksDeclareChild
#endif
TEST_EXPORT test_Hooks* _test_HooksDeclareChild(corto_object _parent, corto_string _id);
#define test_HooksDeclareChild(_parent, _id) _test_HooksDeclareChild(_parent, _id)
#define test_HooksDeclareChild_auto(_parent, _id) test_Hooks* _id = test_HooksDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define HooksDefine test_HooksDefine
#endif
TEST_EXPORT corto_int16 _test_HooksDefine(test_Hooks* _this, test_Hooks value);
#define test_HooksDefine(_this, value) _test_HooksDefine(test_Hooks(_this), value)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define HooksAssign test_HooksAssign
#endif
TEST_EXPORT test_Hooks* _test_HooksAssign(test_Hooks* _this, test_Hooks value);
#define test_Hooks__optional_NotSet NULL
#define test_Hooks__optional_Set(value) test_HooksAssign((test_Hooks*)corto_ptr_new(test_Hooks_o)), value)
#define test_Hooks__optional_SetCond(cond, value) cond ? test_HooksAssign((test_Hooks*)corto_ptr_new(test_Hooks_o), value) : NULL
#define test_HooksUnset(_this) _this ? corto_ptr_free(_this, test_Hooks_o), 0 : 0; _this = NULL;
#define test_HooksAssign(_this, value) _test_HooksAssign(_this, value)
#define test_HooksSet(_this, value) _this = _this ? _this : (test_Hooks*)corto_ptr_new(test_Hooks_o); _test_HooksAssign(_this, value)

/* /test/IntArray */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define IntArrayCreate test_IntArrayCreate
#endif
TEST_EXPORT corto_int32* _test_IntArrayCreate(corto_uint32 length, int32_t* elements);
#define test_IntArrayCreate(length, elements) _test_IntArrayCreate(length, elements)
#define test_IntArrayCreate_auto(_id, length, elements) corto_int32* _id = test_IntArrayCreate(length, elements); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define IntArrayCreateChild test_IntArrayCreateChild
#endif
TEST_EXPORT corto_int32* _test_IntArrayCreateChild(corto_object _parent, corto_string _id, corto_uint32 length, int32_t* elements);
#define test_IntArrayCreateChild(_parent, _id, length, elements) _test_IntArrayCreateChild(_parent, _id, length, elements)
#define test_IntArrayCreateChild_auto(_parent, _id, length, elements) corto_int32* _id = test_IntArrayCreateChild(_parent, #_id, length, elements); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define IntArrayUpdate test_IntArrayUpdate
#endif
TEST_EXPORT corto_int16 _test_IntArrayUpdate(test_IntArray _this, corto_uint32 length, int32_t* elements);
#define test_IntArrayUpdate(_this, length, elements) _test_IntArrayUpdate(test_IntArray(_this), length, elements)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define IntArrayDeclare test_IntArrayDeclare
#endif
TEST_EXPORT corto_int32* _test_IntArrayDeclare(void);
#define test_IntArrayDeclare() _test_IntArrayDeclare()
#define test_IntArrayDeclare_auto(_id) corto_int32* _id = test_IntArrayDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define IntArrayDeclareChild test_IntArrayDeclareChild
#endif
TEST_EXPORT corto_int32* _test_IntArrayDeclareChild(corto_object _parent, corto_string _id);
#define test_IntArrayDeclareChild(_parent, _id) _test_IntArrayDeclareChild(_parent, _id)
#define test_IntArrayDeclareChild_auto(_parent, _id) corto_int32* _id = test_IntArrayDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define IntArrayDefine test_IntArrayDefine
#endif
TEST_EXPORT corto_int16 _test_IntArrayDefine(test_IntArray _this, corto_uint32 length, int32_t* elements);
#define test_IntArrayDefine(_this, length, elements) _test_IntArrayDefine(test_IntArray(_this), length, elements)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define IntArrayAssign test_IntArrayAssign
#endif
TEST_EXPORT corto_int32* _test_IntArrayAssign(test_IntArray _this, corto_uint32 length, int32_t* elements);
#define test_IntArray__optional_NotSet NULL
#define test_IntArray__optional_Set(length, elements) test_IntArrayAssign((test_IntArray*)corto_ptr_new(test_IntArray_o)), length, elements)
#define test_IntArray__optional_SetCond(cond, length, elements) cond ? test_IntArrayAssign((test_IntArray*)corto_ptr_new(test_IntArray_o), length, elements) : NULL
#define test_IntArrayUnset(_this) _this ? corto_ptr_free(_this, test_IntArray_o), 0 : 0; _this = NULL;
#define test_IntArrayAssign(_this, length, elements) _test_IntArrayAssign((corto_int32*)_this, length, elements)
#define test_IntArraySet(_this, length, elements) _this = _this ? _this : (test_IntArray*)corto_ptr_new(test_IntArray_o); _test_IntArrayAssign((corto_int32*)_this, length, elements)

/* /test/IntList */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define IntListCreate test_IntListCreate
#endif
TEST_EXPORT test_IntList* _test_IntListCreate(corto_uint32 length, int32_t* elements);
#define test_IntListCreate(length, elements) _test_IntListCreate(length, elements)
#define test_IntListCreate_auto(_id, length, elements) test_IntList* _id = test_IntListCreate(length, elements); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define IntListCreateChild test_IntListCreateChild
#endif
TEST_EXPORT test_IntList* _test_IntListCreateChild(corto_object _parent, corto_string _id, corto_uint32 length, int32_t* elements);
#define test_IntListCreateChild(_parent, _id, length, elements) _test_IntListCreateChild(_parent, _id, length, elements)
#define test_IntListCreateChild_auto(_parent, _id, length, elements) test_IntList* _id = test_IntListCreateChild(_parent, #_id, length, elements); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define IntListUpdate test_IntListUpdate
#endif
TEST_EXPORT corto_int16 _test_IntListUpdate(test_IntList* _this, corto_uint32 length, int32_t* elements);
#define test_IntListUpdate(_this, length, elements) _test_IntListUpdate(test_IntList(_this), length, elements)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define IntListDeclare test_IntListDeclare
#endif
TEST_EXPORT test_IntList* _test_IntListDeclare(void);
#define test_IntListDeclare() _test_IntListDeclare()
#define test_IntListDeclare_auto(_id) test_IntList* _id = test_IntListDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define IntListDeclareChild test_IntListDeclareChild
#endif
TEST_EXPORT test_IntList* _test_IntListDeclareChild(corto_object _parent, corto_string _id);
#define test_IntListDeclareChild(_parent, _id) _test_IntListDeclareChild(_parent, _id)
#define test_IntListDeclareChild_auto(_parent, _id) test_IntList* _id = test_IntListDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define IntListDefine test_IntListDefine
#endif
TEST_EXPORT corto_int16 _test_IntListDefine(test_IntList* _this, corto_uint32 length, int32_t* elements);
#define test_IntListDefine(_this, length, elements) _test_IntListDefine(test_IntList(_this), length, elements)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define IntListAssign test_IntListAssign
#endif
TEST_EXPORT test_IntList* _test_IntListAssign(test_IntList* _this, corto_uint32 length, int32_t* elements);
#define test_IntList__optional_NotSet NULL
#define test_IntList__optional_Set(length, elements) test_IntListAssign((test_IntList*)corto_ptr_new(test_IntList_o)), length, elements)
#define test_IntList__optional_SetCond(cond, length, elements) cond ? test_IntListAssign((test_IntList*)corto_ptr_new(test_IntList_o), length, elements) : NULL
#define test_IntListUnset(_this) _this ? corto_ptr_free(_this, test_IntList_o), 0 : 0; _this = NULL;
#define test_IntListAssign(_this, length, elements) _test_IntListAssign(_this, length, elements)
#define test_IntListSet(_this, length, elements) _this = _this ? _this : (test_IntList*)corto_ptr_new(test_IntList_o); _test_IntListAssign(_this, length, elements)

/* /test/IntSequence */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define IntSequenceCreate test_IntSequenceCreate
#endif
TEST_EXPORT test_IntSequence* _test_IntSequenceCreate(corto_uint32 length, int32_t* elements);
#define test_IntSequenceCreate(length, elements) _test_IntSequenceCreate(length, elements)
#define test_IntSequenceCreate_auto(_id, length, elements) test_IntSequence* _id = test_IntSequenceCreate(length, elements); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define IntSequenceCreateChild test_IntSequenceCreateChild
#endif
TEST_EXPORT test_IntSequence* _test_IntSequenceCreateChild(corto_object _parent, corto_string _id, corto_uint32 length, int32_t* elements);
#define test_IntSequenceCreateChild(_parent, _id, length, elements) _test_IntSequenceCreateChild(_parent, _id, length, elements)
#define test_IntSequenceCreateChild_auto(_parent, _id, length, elements) test_IntSequence* _id = test_IntSequenceCreateChild(_parent, #_id, length, elements); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define IntSequenceUpdate test_IntSequenceUpdate
#endif
TEST_EXPORT corto_int16 _test_IntSequenceUpdate(test_IntSequence* _this, corto_uint32 length, int32_t* elements);
#define test_IntSequenceUpdate(_this, length, elements) _test_IntSequenceUpdate(test_IntSequence(_this), length, elements)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define IntSequenceDeclare test_IntSequenceDeclare
#endif
TEST_EXPORT test_IntSequence* _test_IntSequenceDeclare(void);
#define test_IntSequenceDeclare() _test_IntSequenceDeclare()
#define test_IntSequenceDeclare_auto(_id) test_IntSequence* _id = test_IntSequenceDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define IntSequenceDeclareChild test_IntSequenceDeclareChild
#endif
TEST_EXPORT test_IntSequence* _test_IntSequenceDeclareChild(corto_object _parent, corto_string _id);
#define test_IntSequenceDeclareChild(_parent, _id) _test_IntSequenceDeclareChild(_parent, _id)
#define test_IntSequenceDeclareChild_auto(_parent, _id) test_IntSequence* _id = test_IntSequenceDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define IntSequenceDefine test_IntSequenceDefine
#endif
TEST_EXPORT corto_int16 _test_IntSequenceDefine(test_IntSequence* _this, corto_uint32 length, int32_t* elements);
#define test_IntSequenceDefine(_this, length, elements) _test_IntSequenceDefine(test_IntSequence(_this), length, elements)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define IntSequenceAssign test_IntSequenceAssign
#endif
TEST_EXPORT test_IntSequence* _test_IntSequenceAssign(test_IntSequence* _this, corto_uint32 length, int32_t* elements);
#define test_IntSequence__optional_NotSet NULL
#define test_IntSequence__optional_Set(length, elements) test_IntSequenceAssign((test_IntSequence*)corto_ptr_new(test_IntSequence_o)), length, elements)
#define test_IntSequence__optional_SetCond(cond, length, elements) cond ? test_IntSequenceAssign((test_IntSequence*)corto_ptr_new(test_IntSequence_o), length, elements) : NULL
#define test_IntSequenceUnset(_this) _this ? corto_ptr_free(_this, test_IntSequence_o), 0 : 0; _this = NULL;
#define test_IntSequenceAssign(_this, length, elements) _test_IntSequenceAssign(_this, length, elements)
#define test_IntSequenceSet(_this, length, elements) _this = _this ? _this : (test_IntSequence*)corto_ptr_new(test_IntSequence_o); _test_IntSequenceAssign(_this, length, elements)

/* /test/intw */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define intwCreate test_intwCreate
#endif
TEST_EXPORT intptr_t* _test_intwCreate(intptr_t value);
#define test_intwCreate(value) _test_intwCreate(value)
#define test_intwCreate_auto(_id, value) intptr_t* _id = test_intwCreate(value); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define intwCreateChild test_intwCreateChild
#endif
TEST_EXPORT intptr_t* _test_intwCreateChild(corto_object _parent, corto_string _id, intptr_t value);
#define test_intwCreateChild(_parent, _id, value) _test_intwCreateChild(_parent, _id, value)
#define test_intwCreateChild_auto(_parent, _id, value) intptr_t* _id = test_intwCreateChild(_parent, #_id, value); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define intwUpdate test_intwUpdate
#endif
TEST_EXPORT corto_int16 _test_intwUpdate(intptr_t* _this, intptr_t value);
#define test_intwUpdate(_this, value) _test_intwUpdate(test_intw(_this), value)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define intwDeclare test_intwDeclare
#endif
TEST_EXPORT intptr_t* _test_intwDeclare(void);
#define test_intwDeclare() _test_intwDeclare()
#define test_intwDeclare_auto(_id) intptr_t* _id = test_intwDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define intwDeclareChild test_intwDeclareChild
#endif
TEST_EXPORT intptr_t* _test_intwDeclareChild(corto_object _parent, corto_string _id);
#define test_intwDeclareChild(_parent, _id) _test_intwDeclareChild(_parent, _id)
#define test_intwDeclareChild_auto(_parent, _id) intptr_t* _id = test_intwDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define intwDefine test_intwDefine
#endif
TEST_EXPORT corto_int16 _test_intwDefine(intptr_t* _this, intptr_t value);
#define test_intwDefine(_this, value) _test_intwDefine(test_intw(_this), value)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define intwAssign test_intwAssign
#endif
TEST_EXPORT intptr_t* _test_intwAssign(intptr_t* _this, intptr_t value);
#define test_intw__optional_NotSet NULL
#define test_intw__optional_Set(value) test_intwAssign((test_intw*)corto_ptr_new(test_intw_o)), value)
#define test_intw__optional_SetCond(cond, value) cond ? test_intwAssign((test_intw*)corto_ptr_new(test_intw_o), value) : NULL
#define test_intwUnset(_this) _this ? corto_ptr_free(_this, test_intw_o), 0 : 0; _this = NULL;
#define test_intwAssign(_this, value) _test_intwAssign(_this, value)
#define test_intwSet(_this, value) _this = _this ? _this : (test_intw*)corto_ptr_new(test_intw_o); _test_intwAssign(_this, value)

/* /test/LeafRoot */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define LeafRootCreate test_LeafRootCreate
#endif
TEST_EXPORT test_LeafRoot _test_LeafRootCreate(int32_t id, corto_string value);
#define test_LeafRootCreate(id, value) _test_LeafRootCreate(id, value)
#define test_LeafRootCreate_auto(_id, id, value) test_LeafRoot _id = test_LeafRootCreate(id, value); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define LeafRootCreateChild test_LeafRootCreateChild
#endif
TEST_EXPORT test_LeafRoot _test_LeafRootCreateChild(corto_object _parent, corto_string _id, int32_t id, corto_string value);
#define test_LeafRootCreateChild(_parent, _id, id, value) _test_LeafRootCreateChild(_parent, _id, id, value)
#define test_LeafRootCreateChild_auto(_parent, _id, id, value) test_LeafRoot _id = test_LeafRootCreateChild(_parent, #_id, id, value); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define LeafRootUpdate test_LeafRootUpdate
#endif
TEST_EXPORT corto_int16 _test_LeafRootUpdate(test_LeafRoot _this, int32_t id, corto_string value);
#define test_LeafRootUpdate(_this, id, value) _test_LeafRootUpdate(test_LeafRoot(_this), id, value)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define LeafRootDeclare test_LeafRootDeclare
#endif
TEST_EXPORT test_LeafRoot _test_LeafRootDeclare(void);
#define test_LeafRootDeclare() _test_LeafRootDeclare()
#define test_LeafRootDeclare_auto(_id) test_LeafRoot _id = test_LeafRootDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define LeafRootDeclareChild test_LeafRootDeclareChild
#endif
TEST_EXPORT test_LeafRoot _test_LeafRootDeclareChild(corto_object _parent, corto_string _id);
#define test_LeafRootDeclareChild(_parent, _id) _test_LeafRootDeclareChild(_parent, _id)
#define test_LeafRootDeclareChild_auto(_parent, _id) test_LeafRoot _id = test_LeafRootDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define LeafRootDefine test_LeafRootDefine
#endif
TEST_EXPORT corto_int16 _test_LeafRootDefine(test_LeafRoot _this, int32_t id, corto_string value);
#define test_LeafRootDefine(_this, id, value) _test_LeafRootDefine(test_LeafRoot(_this), id, value)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define LeafRootAssign test_LeafRootAssign
#endif
TEST_EXPORT test_LeafRoot _test_LeafRootAssign(test_LeafRoot _this, int32_t id, corto_string value);
#define test_LeafRoot__optional_NotSet NULL
#define test_LeafRoot__optional_Set(id, value) test_LeafRootAssign((test_LeafRoot*)corto_ptr_new(test_LeafRoot_o)), id, value)
#define test_LeafRoot__optional_SetCond(cond, id, value) cond ? test_LeafRootAssign((test_LeafRoot*)corto_ptr_new(test_LeafRoot_o), id, value) : NULL
#define test_LeafRootUnset(_this) _this ? corto_ptr_free(_this, test_LeafRoot_o), 0 : 0; _this = NULL;
#define test_LeafRootAssign(_this, id, value) _test_LeafRootAssign(_this, id, value)
#define test_LeafRootSet(_this, id, value) _this = _this ? _this : (test_LeafRoot*)corto_ptr_new(test_LeafRoot_o); _test_LeafRootAssign(_this, id, value)

/* /test/LifecycleAdmin */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define LifecycleAdminCreate test_LifecycleAdminCreate
#endif
TEST_EXPORT test_LifecycleAdmin _test_LifecycleAdminCreate(test_Hooks hooksCalled);
#define test_LifecycleAdminCreate(hooksCalled) _test_LifecycleAdminCreate(hooksCalled)
#define test_LifecycleAdminCreate_auto(_id, hooksCalled) test_LifecycleAdmin _id = test_LifecycleAdminCreate(hooksCalled); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define LifecycleAdminCreateChild test_LifecycleAdminCreateChild
#endif
TEST_EXPORT test_LifecycleAdmin _test_LifecycleAdminCreateChild(corto_object _parent, corto_string _id, test_Hooks hooksCalled);
#define test_LifecycleAdminCreateChild(_parent, _id, hooksCalled) _test_LifecycleAdminCreateChild(_parent, _id, hooksCalled)
#define test_LifecycleAdminCreateChild_auto(_parent, _id, hooksCalled) test_LifecycleAdmin _id = test_LifecycleAdminCreateChild(_parent, #_id, hooksCalled); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define LifecycleAdminUpdate test_LifecycleAdminUpdate
#endif
TEST_EXPORT corto_int16 _test_LifecycleAdminUpdate(test_LifecycleAdmin _this, test_Hooks hooksCalled);
#define test_LifecycleAdminUpdate(_this, hooksCalled) _test_LifecycleAdminUpdate(test_LifecycleAdmin(_this), hooksCalled)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define LifecycleAdminDeclare test_LifecycleAdminDeclare
#endif
TEST_EXPORT test_LifecycleAdmin _test_LifecycleAdminDeclare(void);
#define test_LifecycleAdminDeclare() _test_LifecycleAdminDeclare()
#define test_LifecycleAdminDeclare_auto(_id) test_LifecycleAdmin _id = test_LifecycleAdminDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define LifecycleAdminDeclareChild test_LifecycleAdminDeclareChild
#endif
TEST_EXPORT test_LifecycleAdmin _test_LifecycleAdminDeclareChild(corto_object _parent, corto_string _id);
#define test_LifecycleAdminDeclareChild(_parent, _id) _test_LifecycleAdminDeclareChild(_parent, _id)
#define test_LifecycleAdminDeclareChild_auto(_parent, _id) test_LifecycleAdmin _id = test_LifecycleAdminDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define LifecycleAdminDefine test_LifecycleAdminDefine
#endif
TEST_EXPORT corto_int16 _test_LifecycleAdminDefine(test_LifecycleAdmin _this, test_Hooks hooksCalled);
#define test_LifecycleAdminDefine(_this, hooksCalled) _test_LifecycleAdminDefine(test_LifecycleAdmin(_this), hooksCalled)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define LifecycleAdminAssign test_LifecycleAdminAssign
#endif
TEST_EXPORT test_LifecycleAdmin _test_LifecycleAdminAssign(test_LifecycleAdmin _this, test_Hooks hooksCalled);
#define test_LifecycleAdmin__optional_NotSet NULL
#define test_LifecycleAdmin__optional_Set(hooksCalled) test_LifecycleAdminAssign((test_LifecycleAdmin*)corto_ptr_new(test_LifecycleAdmin_o)), hooksCalled)
#define test_LifecycleAdmin__optional_SetCond(cond, hooksCalled) cond ? test_LifecycleAdminAssign((test_LifecycleAdmin*)corto_ptr_new(test_LifecycleAdmin_o), hooksCalled) : NULL
#define test_LifecycleAdminUnset(_this) _this ? corto_ptr_free(_this, test_LifecycleAdmin_o), 0 : 0; _this = NULL;
#define test_LifecycleAdminAssign(_this, hooksCalled) _test_LifecycleAdminAssign(_this, hooksCalled)
#define test_LifecycleAdminSet(_this, hooksCalled) _this = _this ? _this : (test_LifecycleAdmin*)corto_ptr_new(test_LifecycleAdmin_o); _test_LifecycleAdminAssign(_this, hooksCalled)

/* /test/LifecycleTest */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define LifecycleTestCreate test_LifecycleTestCreate
#endif
TEST_EXPORT test_LifecycleTest _test_LifecycleTestCreate(test_LifecycleAdmin admin, bool constructFail, bool validateFail);
#define test_LifecycleTestCreate(admin, constructFail, validateFail) _test_LifecycleTestCreate(test_LifecycleAdmin(admin), constructFail, validateFail)
#define test_LifecycleTestCreate_auto(_id, admin, constructFail, validateFail) test_LifecycleTest _id = test_LifecycleTestCreate(admin, constructFail, validateFail); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define LifecycleTestCreateChild test_LifecycleTestCreateChild
#endif
TEST_EXPORT test_LifecycleTest _test_LifecycleTestCreateChild(corto_object _parent, corto_string _id, test_LifecycleAdmin admin, bool constructFail, bool validateFail);
#define test_LifecycleTestCreateChild(_parent, _id, admin, constructFail, validateFail) _test_LifecycleTestCreateChild(_parent, _id, test_LifecycleAdmin(admin), constructFail, validateFail)
#define test_LifecycleTestCreateChild_auto(_parent, _id, admin, constructFail, validateFail) test_LifecycleTest _id = test_LifecycleTestCreateChild(_parent, #_id, admin, constructFail, validateFail); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define LifecycleTestUpdate test_LifecycleTestUpdate
#endif
TEST_EXPORT corto_int16 _test_LifecycleTestUpdate(test_LifecycleTest _this, test_LifecycleAdmin admin, bool constructFail, bool validateFail);
#define test_LifecycleTestUpdate(_this, admin, constructFail, validateFail) _test_LifecycleTestUpdate(test_LifecycleTest(_this), test_LifecycleAdmin(admin), constructFail, validateFail)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define LifecycleTestDeclare test_LifecycleTestDeclare
#endif
TEST_EXPORT test_LifecycleTest _test_LifecycleTestDeclare(void);
#define test_LifecycleTestDeclare() _test_LifecycleTestDeclare()
#define test_LifecycleTestDeclare_auto(_id) test_LifecycleTest _id = test_LifecycleTestDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define LifecycleTestDeclareChild test_LifecycleTestDeclareChild
#endif
TEST_EXPORT test_LifecycleTest _test_LifecycleTestDeclareChild(corto_object _parent, corto_string _id);
#define test_LifecycleTestDeclareChild(_parent, _id) _test_LifecycleTestDeclareChild(_parent, _id)
#define test_LifecycleTestDeclareChild_auto(_parent, _id) test_LifecycleTest _id = test_LifecycleTestDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define LifecycleTestDefine test_LifecycleTestDefine
#endif
TEST_EXPORT corto_int16 _test_LifecycleTestDefine(test_LifecycleTest _this, test_LifecycleAdmin admin, bool constructFail, bool validateFail);
#define test_LifecycleTestDefine(_this, admin, constructFail, validateFail) _test_LifecycleTestDefine(test_LifecycleTest(_this), test_LifecycleAdmin(admin), constructFail, validateFail)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define LifecycleTestAssign test_LifecycleTestAssign
#endif
TEST_EXPORT test_LifecycleTest _test_LifecycleTestAssign(test_LifecycleTest _this, test_LifecycleAdmin admin, bool constructFail, bool validateFail);
#define test_LifecycleTest__optional_NotSet NULL
#define test_LifecycleTest__optional_Set(admin, constructFail, validateFail) test_LifecycleTestAssign((test_LifecycleTest*)corto_ptr_new(test_LifecycleTest_o)), admin, constructFail, validateFail)
#define test_LifecycleTest__optional_SetCond(cond, admin, constructFail, validateFail) cond ? test_LifecycleTestAssign((test_LifecycleTest*)corto_ptr_new(test_LifecycleTest_o), admin, constructFail, validateFail) : NULL
#define test_LifecycleTestUnset(_this) _this ? corto_ptr_free(_this, test_LifecycleTest_o), 0 : 0; _this = NULL;
#define test_LifecycleTestAssign(_this, admin, constructFail, validateFail) _test_LifecycleTestAssign(_this, test_LifecycleAdmin(admin), constructFail, validateFail)
#define test_LifecycleTestSet(_this, admin, constructFail, validateFail) _this = _this ? _this : (test_LifecycleTest*)corto_ptr_new(test_LifecycleTest_o); _test_LifecycleTestAssign(_this, test_LifecycleAdmin(admin), constructFail, validateFail)

/* /test/Line */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define LineCreate test_LineCreate
#endif
TEST_EXPORT test_Line* _test_LineCreate(test_Point* start, test_Point* stop);
#define test_LineCreate(start, stop) _test_LineCreate(start, stop)
#define test_LineCreate_auto(_id, start, stop) test_Line* _id = test_LineCreate(start, stop); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define LineCreateChild test_LineCreateChild
#endif
TEST_EXPORT test_Line* _test_LineCreateChild(corto_object _parent, corto_string _id, test_Point* start, test_Point* stop);
#define test_LineCreateChild(_parent, _id, start, stop) _test_LineCreateChild(_parent, _id, start, stop)
#define test_LineCreateChild_auto(_parent, _id, start, stop) test_Line* _id = test_LineCreateChild(_parent, #_id, start, stop); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define LineUpdate test_LineUpdate
#endif
TEST_EXPORT corto_int16 _test_LineUpdate(test_Line* _this, test_Point* start, test_Point* stop);
#define test_LineUpdate(_this, start, stop) _test_LineUpdate(test_Line(_this), start, stop)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define LineDeclare test_LineDeclare
#endif
TEST_EXPORT test_Line* _test_LineDeclare(void);
#define test_LineDeclare() _test_LineDeclare()
#define test_LineDeclare_auto(_id) test_Line* _id = test_LineDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define LineDeclareChild test_LineDeclareChild
#endif
TEST_EXPORT test_Line* _test_LineDeclareChild(corto_object _parent, corto_string _id);
#define test_LineDeclareChild(_parent, _id) _test_LineDeclareChild(_parent, _id)
#define test_LineDeclareChild_auto(_parent, _id) test_Line* _id = test_LineDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define LineDefine test_LineDefine
#endif
TEST_EXPORT corto_int16 _test_LineDefine(test_Line* _this, test_Point* start, test_Point* stop);
#define test_LineDefine(_this, start, stop) _test_LineDefine(test_Line(_this), start, stop)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define LineAssign test_LineAssign
#endif
TEST_EXPORT test_Line* _test_LineAssign(test_Line* _this, test_Point* start, test_Point* stop);
#define test_Line__optional_NotSet NULL
#define test_Line__optional_Set(start, stop) test_LineAssign((test_Line*)corto_ptr_new(test_Line_o)), start, stop)
#define test_Line__optional_SetCond(cond, start, stop) cond ? test_LineAssign((test_Line*)corto_ptr_new(test_Line_o), start, stop) : NULL
#define test_LineUnset(_this) _this ? corto_ptr_free(_this, test_Line_o), 0 : 0; _this = NULL;
#define test_LineAssign(_this, start, stop) _test_LineAssign(_this, start, stop)
#define test_LineSet(_this, start, stop) _this = _this ? _this : (test_Line*)corto_ptr_new(test_Line_o); _test_LineAssign(_this, start, stop)

/* /test/Loader */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define LoaderCreate test_LoaderCreate
#endif
TEST_EXPORT test_Loader _test_LoaderCreate(uint32_t assertCount);
#define test_LoaderCreate(assertCount) _test_LoaderCreate(assertCount)
#define test_LoaderCreate_auto(_id, assertCount) test_Loader _id = test_LoaderCreate(assertCount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define LoaderCreateChild test_LoaderCreateChild
#endif
TEST_EXPORT test_Loader _test_LoaderCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount);
#define test_LoaderCreateChild(_parent, _id, assertCount) _test_LoaderCreateChild(_parent, _id, assertCount)
#define test_LoaderCreateChild_auto(_parent, _id, assertCount) test_Loader _id = test_LoaderCreateChild(_parent, #_id, assertCount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define LoaderUpdate test_LoaderUpdate
#endif
TEST_EXPORT corto_int16 _test_LoaderUpdate(test_Loader _this, uint32_t assertCount);
#define test_LoaderUpdate(_this, assertCount) _test_LoaderUpdate(test_Loader(_this), assertCount)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define LoaderDeclare test_LoaderDeclare
#endif
TEST_EXPORT test_Loader _test_LoaderDeclare(void);
#define test_LoaderDeclare() _test_LoaderDeclare()
#define test_LoaderDeclare_auto(_id) test_Loader _id = test_LoaderDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define LoaderDeclareChild test_LoaderDeclareChild
#endif
TEST_EXPORT test_Loader _test_LoaderDeclareChild(corto_object _parent, corto_string _id);
#define test_LoaderDeclareChild(_parent, _id) _test_LoaderDeclareChild(_parent, _id)
#define test_LoaderDeclareChild_auto(_parent, _id) test_Loader _id = test_LoaderDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define LoaderDefine test_LoaderDefine
#endif
TEST_EXPORT corto_int16 _test_LoaderDefine(test_Loader _this, uint32_t assertCount);
#define test_LoaderDefine(_this, assertCount) _test_LoaderDefine(test_Loader(_this), assertCount)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define LoaderAssign test_LoaderAssign
#endif
TEST_EXPORT test_Loader _test_LoaderAssign(test_Loader _this, uint32_t assertCount);
#define test_Loader__optional_NotSet NULL
#define test_Loader__optional_Set(assertCount) test_LoaderAssign((test_Loader*)corto_ptr_new(test_Loader_o)), assertCount)
#define test_Loader__optional_SetCond(cond, assertCount) cond ? test_LoaderAssign((test_Loader*)corto_ptr_new(test_Loader_o), assertCount) : NULL
#define test_LoaderUnset(_this) _this ? corto_ptr_free(_this, test_Loader_o), 0 : 0; _this = NULL;
#define test_LoaderAssign(_this, assertCount) _test_LoaderAssign(_this, assertCount)
#define test_LoaderSet(_this, assertCount) _this = _this ? _this : (test_Loader*)corto_ptr_new(test_Loader_o); _test_LoaderAssign(_this, assertCount)

/* /test/LongIntList */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define LongIntListCreate test_LongIntListCreate
#endif
TEST_EXPORT test_LongIntList* _test_LongIntListCreate(corto_uint32 length, int64_t* elements);
#define test_LongIntListCreate(length, elements) _test_LongIntListCreate(length, elements)
#define test_LongIntListCreate_auto(_id, length, elements) test_LongIntList* _id = test_LongIntListCreate(length, elements); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define LongIntListCreateChild test_LongIntListCreateChild
#endif
TEST_EXPORT test_LongIntList* _test_LongIntListCreateChild(corto_object _parent, corto_string _id, corto_uint32 length, int64_t* elements);
#define test_LongIntListCreateChild(_parent, _id, length, elements) _test_LongIntListCreateChild(_parent, _id, length, elements)
#define test_LongIntListCreateChild_auto(_parent, _id, length, elements) test_LongIntList* _id = test_LongIntListCreateChild(_parent, #_id, length, elements); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define LongIntListUpdate test_LongIntListUpdate
#endif
TEST_EXPORT corto_int16 _test_LongIntListUpdate(test_LongIntList* _this, corto_uint32 length, int64_t* elements);
#define test_LongIntListUpdate(_this, length, elements) _test_LongIntListUpdate(test_LongIntList(_this), length, elements)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define LongIntListDeclare test_LongIntListDeclare
#endif
TEST_EXPORT test_LongIntList* _test_LongIntListDeclare(void);
#define test_LongIntListDeclare() _test_LongIntListDeclare()
#define test_LongIntListDeclare_auto(_id) test_LongIntList* _id = test_LongIntListDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define LongIntListDeclareChild test_LongIntListDeclareChild
#endif
TEST_EXPORT test_LongIntList* _test_LongIntListDeclareChild(corto_object _parent, corto_string _id);
#define test_LongIntListDeclareChild(_parent, _id) _test_LongIntListDeclareChild(_parent, _id)
#define test_LongIntListDeclareChild_auto(_parent, _id) test_LongIntList* _id = test_LongIntListDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define LongIntListDefine test_LongIntListDefine
#endif
TEST_EXPORT corto_int16 _test_LongIntListDefine(test_LongIntList* _this, corto_uint32 length, int64_t* elements);
#define test_LongIntListDefine(_this, length, elements) _test_LongIntListDefine(test_LongIntList(_this), length, elements)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define LongIntListAssign test_LongIntListAssign
#endif
TEST_EXPORT test_LongIntList* _test_LongIntListAssign(test_LongIntList* _this, corto_uint32 length, int64_t* elements);
#define test_LongIntList__optional_NotSet NULL
#define test_LongIntList__optional_Set(length, elements) test_LongIntListAssign((test_LongIntList*)corto_ptr_new(test_LongIntList_o)), length, elements)
#define test_LongIntList__optional_SetCond(cond, length, elements) cond ? test_LongIntListAssign((test_LongIntList*)corto_ptr_new(test_LongIntList_o), length, elements) : NULL
#define test_LongIntListUnset(_this) _this ? corto_ptr_free(_this, test_LongIntList_o), 0 : 0; _this = NULL;
#define test_LongIntListAssign(_this, length, elements) _test_LongIntListAssign(_this, length, elements)
#define test_LongIntListSet(_this, length, elements) _this = _this ? _this : (test_LongIntList*)corto_ptr_new(test_LongIntList_o); _test_LongIntListAssign(_this, length, elements)

/* /test/Lookup */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define LookupCreate test_LookupCreate
#endif
TEST_EXPORT test_Lookup _test_LookupCreate(uint32_t assertCount);
#define test_LookupCreate(assertCount) _test_LookupCreate(assertCount)
#define test_LookupCreate_auto(_id, assertCount) test_Lookup _id = test_LookupCreate(assertCount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define LookupCreateChild test_LookupCreateChild
#endif
TEST_EXPORT test_Lookup _test_LookupCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount);
#define test_LookupCreateChild(_parent, _id, assertCount) _test_LookupCreateChild(_parent, _id, assertCount)
#define test_LookupCreateChild_auto(_parent, _id, assertCount) test_Lookup _id = test_LookupCreateChild(_parent, #_id, assertCount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define LookupUpdate test_LookupUpdate
#endif
TEST_EXPORT corto_int16 _test_LookupUpdate(test_Lookup _this, uint32_t assertCount);
#define test_LookupUpdate(_this, assertCount) _test_LookupUpdate(test_Lookup(_this), assertCount)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define LookupDeclare test_LookupDeclare
#endif
TEST_EXPORT test_Lookup _test_LookupDeclare(void);
#define test_LookupDeclare() _test_LookupDeclare()
#define test_LookupDeclare_auto(_id) test_Lookup _id = test_LookupDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define LookupDeclareChild test_LookupDeclareChild
#endif
TEST_EXPORT test_Lookup _test_LookupDeclareChild(corto_object _parent, corto_string _id);
#define test_LookupDeclareChild(_parent, _id) _test_LookupDeclareChild(_parent, _id)
#define test_LookupDeclareChild_auto(_parent, _id) test_Lookup _id = test_LookupDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define LookupDefine test_LookupDefine
#endif
TEST_EXPORT corto_int16 _test_LookupDefine(test_Lookup _this, uint32_t assertCount);
#define test_LookupDefine(_this, assertCount) _test_LookupDefine(test_Lookup(_this), assertCount)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define LookupAssign test_LookupAssign
#endif
TEST_EXPORT test_Lookup _test_LookupAssign(test_Lookup _this, uint32_t assertCount);
#define test_Lookup__optional_NotSet NULL
#define test_Lookup__optional_Set(assertCount) test_LookupAssign((test_Lookup*)corto_ptr_new(test_Lookup_o)), assertCount)
#define test_Lookup__optional_SetCond(cond, assertCount) cond ? test_LookupAssign((test_Lookup*)corto_ptr_new(test_Lookup_o), assertCount) : NULL
#define test_LookupUnset(_this) _this ? corto_ptr_free(_this, test_Lookup_o), 0 : 0; _this = NULL;
#define test_LookupAssign(_this, assertCount) _test_LookupAssign(_this, assertCount)
#define test_LookupSet(_this, assertCount) _this = _this ? _this : (test_Lookup*)corto_ptr_new(test_Lookup_o); _test_LookupAssign(_this, assertCount)

/* /test/Matcher */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MatcherCreate test_MatcherCreate
#endif
TEST_EXPORT test_Matcher _test_MatcherCreate(uint32_t assertCount);
#define test_MatcherCreate(assertCount) _test_MatcherCreate(assertCount)
#define test_MatcherCreate_auto(_id, assertCount) test_Matcher _id = test_MatcherCreate(assertCount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MatcherCreateChild test_MatcherCreateChild
#endif
TEST_EXPORT test_Matcher _test_MatcherCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount);
#define test_MatcherCreateChild(_parent, _id, assertCount) _test_MatcherCreateChild(_parent, _id, assertCount)
#define test_MatcherCreateChild_auto(_parent, _id, assertCount) test_Matcher _id = test_MatcherCreateChild(_parent, #_id, assertCount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MatcherUpdate test_MatcherUpdate
#endif
TEST_EXPORT corto_int16 _test_MatcherUpdate(test_Matcher _this, uint32_t assertCount);
#define test_MatcherUpdate(_this, assertCount) _test_MatcherUpdate(test_Matcher(_this), assertCount)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MatcherDeclare test_MatcherDeclare
#endif
TEST_EXPORT test_Matcher _test_MatcherDeclare(void);
#define test_MatcherDeclare() _test_MatcherDeclare()
#define test_MatcherDeclare_auto(_id) test_Matcher _id = test_MatcherDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MatcherDeclareChild test_MatcherDeclareChild
#endif
TEST_EXPORT test_Matcher _test_MatcherDeclareChild(corto_object _parent, corto_string _id);
#define test_MatcherDeclareChild(_parent, _id) _test_MatcherDeclareChild(_parent, _id)
#define test_MatcherDeclareChild_auto(_parent, _id) test_Matcher _id = test_MatcherDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MatcherDefine test_MatcherDefine
#endif
TEST_EXPORT corto_int16 _test_MatcherDefine(test_Matcher _this, uint32_t assertCount);
#define test_MatcherDefine(_this, assertCount) _test_MatcherDefine(test_Matcher(_this), assertCount)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MatcherAssign test_MatcherAssign
#endif
TEST_EXPORT test_Matcher _test_MatcherAssign(test_Matcher _this, uint32_t assertCount);
#define test_Matcher__optional_NotSet NULL
#define test_Matcher__optional_Set(assertCount) test_MatcherAssign((test_Matcher*)corto_ptr_new(test_Matcher_o)), assertCount)
#define test_Matcher__optional_SetCond(cond, assertCount) cond ? test_MatcherAssign((test_Matcher*)corto_ptr_new(test_Matcher_o), assertCount) : NULL
#define test_MatcherUnset(_this) _this ? corto_ptr_free(_this, test_Matcher_o), 0 : 0; _this = NULL;
#define test_MatcherAssign(_this, assertCount) _test_MatcherAssign(_this, assertCount)
#define test_MatcherSet(_this, assertCount) _this = _this ? _this : (test_Matcher*)corto_ptr_new(test_Matcher_o); _test_MatcherAssign(_this, assertCount)

/* /test/MethodForwardTest */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MethodForwardTestCreate test_MethodForwardTestCreate
#endif
TEST_EXPORT test_MethodForwardTest _test_MethodForwardTestCreate(void);
#define test_MethodForwardTestCreate() _test_MethodForwardTestCreate()
#define test_MethodForwardTestCreate_auto(_id) test_MethodForwardTest _id = test_MethodForwardTestCreate(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MethodForwardTestCreateChild test_MethodForwardTestCreateChild
#endif
TEST_EXPORT test_MethodForwardTest _test_MethodForwardTestCreateChild(corto_object _parent, corto_string _id);
#define test_MethodForwardTestCreateChild(_parent, _id) _test_MethodForwardTestCreateChild(_parent, _id)
#define test_MethodForwardTestCreateChild_auto(_parent, _id) test_MethodForwardTest _id = test_MethodForwardTestCreateChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MethodForwardTestUpdate test_MethodForwardTestUpdate
#endif
TEST_EXPORT corto_int16 _test_MethodForwardTestUpdate(test_MethodForwardTest _this);
#define test_MethodForwardTestUpdate(_this) _test_MethodForwardTestUpdate(test_MethodForwardTest(_this))


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MethodForwardTestDeclare test_MethodForwardTestDeclare
#endif
TEST_EXPORT test_MethodForwardTest _test_MethodForwardTestDeclare(void);
#define test_MethodForwardTestDeclare() _test_MethodForwardTestDeclare()
#define test_MethodForwardTestDeclare_auto(_id) test_MethodForwardTest _id = test_MethodForwardTestDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MethodForwardTestDeclareChild test_MethodForwardTestDeclareChild
#endif
TEST_EXPORT test_MethodForwardTest _test_MethodForwardTestDeclareChild(corto_object _parent, corto_string _id);
#define test_MethodForwardTestDeclareChild(_parent, _id) _test_MethodForwardTestDeclareChild(_parent, _id)
#define test_MethodForwardTestDeclareChild_auto(_parent, _id) test_MethodForwardTest _id = test_MethodForwardTestDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MethodForwardTestDefine test_MethodForwardTestDefine
#endif
TEST_EXPORT corto_int16 _test_MethodForwardTestDefine(test_MethodForwardTest _this);
#define test_MethodForwardTestDefine(_this) _test_MethodForwardTestDefine(test_MethodForwardTest(_this))

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MethodForwardTestAssign test_MethodForwardTestAssign
#endif
TEST_EXPORT test_MethodForwardTest _test_MethodForwardTestAssign(test_MethodForwardTest _this);
#define test_MethodForwardTest__optional_NotSet NULL
#define test_MethodForwardTest__optional_Set() test_MethodForwardTestAssign((test_MethodForwardTest*)corto_ptr_new(test_MethodForwardTest_o)))
#define test_MethodForwardTest__optional_SetCond(cond) cond ? test_MethodForwardTestAssign((test_MethodForwardTest*)corto_ptr_new(test_MethodForwardTest_o)) : NULL
#define test_MethodForwardTestUnset(_this) _this ? corto_ptr_free(_this, test_MethodForwardTest_o), 0 : 0; _this = NULL;
#define test_MethodForwardTestAssign(_this) _test_MethodForwardTestAssign(_this)
#define test_MethodForwardTestSet(_this) _this = _this ? _this : (test_MethodForwardTest*)corto_ptr_new(test_MethodForwardTest_o); _test_MethodForwardTestAssign(_this)

/* /test/MethodInvoking */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MethodInvokingCreate test_MethodInvokingCreate
#endif
TEST_EXPORT test_MethodInvoking _test_MethodInvokingCreate(uint32_t assertCount);
#define test_MethodInvokingCreate(assertCount) _test_MethodInvokingCreate(assertCount)
#define test_MethodInvokingCreate_auto(_id, assertCount) test_MethodInvoking _id = test_MethodInvokingCreate(assertCount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MethodInvokingCreateChild test_MethodInvokingCreateChild
#endif
TEST_EXPORT test_MethodInvoking _test_MethodInvokingCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount);
#define test_MethodInvokingCreateChild(_parent, _id, assertCount) _test_MethodInvokingCreateChild(_parent, _id, assertCount)
#define test_MethodInvokingCreateChild_auto(_parent, _id, assertCount) test_MethodInvoking _id = test_MethodInvokingCreateChild(_parent, #_id, assertCount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MethodInvokingUpdate test_MethodInvokingUpdate
#endif
TEST_EXPORT corto_int16 _test_MethodInvokingUpdate(test_MethodInvoking _this, uint32_t assertCount);
#define test_MethodInvokingUpdate(_this, assertCount) _test_MethodInvokingUpdate(test_MethodInvoking(_this), assertCount)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MethodInvokingDeclare test_MethodInvokingDeclare
#endif
TEST_EXPORT test_MethodInvoking _test_MethodInvokingDeclare(void);
#define test_MethodInvokingDeclare() _test_MethodInvokingDeclare()
#define test_MethodInvokingDeclare_auto(_id) test_MethodInvoking _id = test_MethodInvokingDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MethodInvokingDeclareChild test_MethodInvokingDeclareChild
#endif
TEST_EXPORT test_MethodInvoking _test_MethodInvokingDeclareChild(corto_object _parent, corto_string _id);
#define test_MethodInvokingDeclareChild(_parent, _id) _test_MethodInvokingDeclareChild(_parent, _id)
#define test_MethodInvokingDeclareChild_auto(_parent, _id) test_MethodInvoking _id = test_MethodInvokingDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MethodInvokingDefine test_MethodInvokingDefine
#endif
TEST_EXPORT corto_int16 _test_MethodInvokingDefine(test_MethodInvoking _this, uint32_t assertCount);
#define test_MethodInvokingDefine(_this, assertCount) _test_MethodInvokingDefine(test_MethodInvoking(_this), assertCount)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MethodInvokingAssign test_MethodInvokingAssign
#endif
TEST_EXPORT test_MethodInvoking _test_MethodInvokingAssign(test_MethodInvoking _this, uint32_t assertCount);
#define test_MethodInvoking__optional_NotSet NULL
#define test_MethodInvoking__optional_Set(assertCount) test_MethodInvokingAssign((test_MethodInvoking*)corto_ptr_new(test_MethodInvoking_o)), assertCount)
#define test_MethodInvoking__optional_SetCond(cond, assertCount) cond ? test_MethodInvokingAssign((test_MethodInvoking*)corto_ptr_new(test_MethodInvoking_o), assertCount) : NULL
#define test_MethodInvokingUnset(_this) _this ? corto_ptr_free(_this, test_MethodInvoking_o), 0 : 0; _this = NULL;
#define test_MethodInvokingAssign(_this, assertCount) _test_MethodInvokingAssign(_this, assertCount)
#define test_MethodInvokingSet(_this, assertCount) _this = _this ? _this : (test_MethodInvoking*)corto_ptr_new(test_MethodInvoking_o); _test_MethodInvokingAssign(_this, assertCount)

/* /test/MethodResolver */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MethodResolverCreate test_MethodResolverCreate
#endif
TEST_EXPORT test_MethodResolver _test_MethodResolverCreate(uint32_t assertCount);
#define test_MethodResolverCreate(assertCount) _test_MethodResolverCreate(assertCount)
#define test_MethodResolverCreate_auto(_id, assertCount) test_MethodResolver _id = test_MethodResolverCreate(assertCount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MethodResolverCreateChild test_MethodResolverCreateChild
#endif
TEST_EXPORT test_MethodResolver _test_MethodResolverCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount);
#define test_MethodResolverCreateChild(_parent, _id, assertCount) _test_MethodResolverCreateChild(_parent, _id, assertCount)
#define test_MethodResolverCreateChild_auto(_parent, _id, assertCount) test_MethodResolver _id = test_MethodResolverCreateChild(_parent, #_id, assertCount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MethodResolverUpdate test_MethodResolverUpdate
#endif
TEST_EXPORT corto_int16 _test_MethodResolverUpdate(test_MethodResolver _this, uint32_t assertCount);
#define test_MethodResolverUpdate(_this, assertCount) _test_MethodResolverUpdate(test_MethodResolver(_this), assertCount)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MethodResolverDeclare test_MethodResolverDeclare
#endif
TEST_EXPORT test_MethodResolver _test_MethodResolverDeclare(void);
#define test_MethodResolverDeclare() _test_MethodResolverDeclare()
#define test_MethodResolverDeclare_auto(_id) test_MethodResolver _id = test_MethodResolverDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MethodResolverDeclareChild test_MethodResolverDeclareChild
#endif
TEST_EXPORT test_MethodResolver _test_MethodResolverDeclareChild(corto_object _parent, corto_string _id);
#define test_MethodResolverDeclareChild(_parent, _id) _test_MethodResolverDeclareChild(_parent, _id)
#define test_MethodResolverDeclareChild_auto(_parent, _id) test_MethodResolver _id = test_MethodResolverDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MethodResolverDefine test_MethodResolverDefine
#endif
TEST_EXPORT corto_int16 _test_MethodResolverDefine(test_MethodResolver _this, uint32_t assertCount);
#define test_MethodResolverDefine(_this, assertCount) _test_MethodResolverDefine(test_MethodResolver(_this), assertCount)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MethodResolverAssign test_MethodResolverAssign
#endif
TEST_EXPORT test_MethodResolver _test_MethodResolverAssign(test_MethodResolver _this, uint32_t assertCount);
#define test_MethodResolver__optional_NotSet NULL
#define test_MethodResolver__optional_Set(assertCount) test_MethodResolverAssign((test_MethodResolver*)corto_ptr_new(test_MethodResolver_o)), assertCount)
#define test_MethodResolver__optional_SetCond(cond, assertCount) cond ? test_MethodResolverAssign((test_MethodResolver*)corto_ptr_new(test_MethodResolver_o), assertCount) : NULL
#define test_MethodResolverUnset(_this) _this ? corto_ptr_free(_this, test_MethodResolver_o), 0 : 0; _this = NULL;
#define test_MethodResolverAssign(_this, assertCount) _test_MethodResolverAssign(_this, assertCount)
#define test_MethodResolverSet(_this, assertCount) _this = _this ? _this : (test_MethodResolver*)corto_ptr_new(test_MethodResolver_o); _test_MethodResolverAssign(_this, assertCount)

/* /test/MethodTester */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MethodTesterCreate test_MethodTesterCreate
#endif
TEST_EXPORT test_MethodTester _test_MethodTesterCreate(void);
#define test_MethodTesterCreate() _test_MethodTesterCreate()
#define test_MethodTesterCreate_auto(_id) test_MethodTester _id = test_MethodTesterCreate(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MethodTesterCreateChild test_MethodTesterCreateChild
#endif
TEST_EXPORT test_MethodTester _test_MethodTesterCreateChild(corto_object _parent, corto_string _id);
#define test_MethodTesterCreateChild(_parent, _id) _test_MethodTesterCreateChild(_parent, _id)
#define test_MethodTesterCreateChild_auto(_parent, _id) test_MethodTester _id = test_MethodTesterCreateChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MethodTesterUpdate test_MethodTesterUpdate
#endif
TEST_EXPORT corto_int16 _test_MethodTesterUpdate(test_MethodTester _this);
#define test_MethodTesterUpdate(_this) _test_MethodTesterUpdate(test_MethodTester(_this))


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MethodTesterDeclare test_MethodTesterDeclare
#endif
TEST_EXPORT test_MethodTester _test_MethodTesterDeclare(void);
#define test_MethodTesterDeclare() _test_MethodTesterDeclare()
#define test_MethodTesterDeclare_auto(_id) test_MethodTester _id = test_MethodTesterDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MethodTesterDeclareChild test_MethodTesterDeclareChild
#endif
TEST_EXPORT test_MethodTester _test_MethodTesterDeclareChild(corto_object _parent, corto_string _id);
#define test_MethodTesterDeclareChild(_parent, _id) _test_MethodTesterDeclareChild(_parent, _id)
#define test_MethodTesterDeclareChild_auto(_parent, _id) test_MethodTester _id = test_MethodTesterDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MethodTesterDefine test_MethodTesterDefine
#endif
TEST_EXPORT corto_int16 _test_MethodTesterDefine(test_MethodTester _this);
#define test_MethodTesterDefine(_this) _test_MethodTesterDefine(test_MethodTester(_this))

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MethodTesterAssign test_MethodTesterAssign
#endif
TEST_EXPORT test_MethodTester _test_MethodTesterAssign(test_MethodTester _this);
#define test_MethodTester__optional_NotSet NULL
#define test_MethodTester__optional_Set() test_MethodTesterAssign((test_MethodTester*)corto_ptr_new(test_MethodTester_o)))
#define test_MethodTester__optional_SetCond(cond) cond ? test_MethodTesterAssign((test_MethodTester*)corto_ptr_new(test_MethodTester_o)) : NULL
#define test_MethodTesterUnset(_this) _this ? corto_ptr_free(_this, test_MethodTester_o), 0 : 0; _this = NULL;
#define test_MethodTesterAssign(_this) _test_MethodTesterAssign(_this)
#define test_MethodTesterSet(_this) _this = _this ? _this : (test_MethodTester*)corto_ptr_new(test_MethodTester_o); _test_MethodTesterAssign(_this)

/* /test/MethodTesterInherit */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MethodTesterInheritCreate test_MethodTesterInheritCreate
#endif
TEST_EXPORT test_MethodTesterInherit _test_MethodTesterInheritCreate(void);
#define test_MethodTesterInheritCreate() _test_MethodTesterInheritCreate()
#define test_MethodTesterInheritCreate_auto(_id) test_MethodTesterInherit _id = test_MethodTesterInheritCreate(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MethodTesterInheritCreateChild test_MethodTesterInheritCreateChild
#endif
TEST_EXPORT test_MethodTesterInherit _test_MethodTesterInheritCreateChild(corto_object _parent, corto_string _id);
#define test_MethodTesterInheritCreateChild(_parent, _id) _test_MethodTesterInheritCreateChild(_parent, _id)
#define test_MethodTesterInheritCreateChild_auto(_parent, _id) test_MethodTesterInherit _id = test_MethodTesterInheritCreateChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MethodTesterInheritUpdate test_MethodTesterInheritUpdate
#endif
TEST_EXPORT corto_int16 _test_MethodTesterInheritUpdate(test_MethodTesterInherit _this);
#define test_MethodTesterInheritUpdate(_this) _test_MethodTesterInheritUpdate(test_MethodTesterInherit(_this))


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MethodTesterInheritDeclare test_MethodTesterInheritDeclare
#endif
TEST_EXPORT test_MethodTesterInherit _test_MethodTesterInheritDeclare(void);
#define test_MethodTesterInheritDeclare() _test_MethodTesterInheritDeclare()
#define test_MethodTesterInheritDeclare_auto(_id) test_MethodTesterInherit _id = test_MethodTesterInheritDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MethodTesterInheritDeclareChild test_MethodTesterInheritDeclareChild
#endif
TEST_EXPORT test_MethodTesterInherit _test_MethodTesterInheritDeclareChild(corto_object _parent, corto_string _id);
#define test_MethodTesterInheritDeclareChild(_parent, _id) _test_MethodTesterInheritDeclareChild(_parent, _id)
#define test_MethodTesterInheritDeclareChild_auto(_parent, _id) test_MethodTesterInherit _id = test_MethodTesterInheritDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MethodTesterInheritDefine test_MethodTesterInheritDefine
#endif
TEST_EXPORT corto_int16 _test_MethodTesterInheritDefine(test_MethodTesterInherit _this);
#define test_MethodTesterInheritDefine(_this) _test_MethodTesterInheritDefine(test_MethodTesterInherit(_this))

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MethodTesterInheritAssign test_MethodTesterInheritAssign
#endif
TEST_EXPORT test_MethodTesterInherit _test_MethodTesterInheritAssign(test_MethodTesterInherit _this);
#define test_MethodTesterInherit__optional_NotSet NULL
#define test_MethodTesterInherit__optional_Set() test_MethodTesterInheritAssign((test_MethodTesterInherit*)corto_ptr_new(test_MethodTesterInherit_o)))
#define test_MethodTesterInherit__optional_SetCond(cond) cond ? test_MethodTesterInheritAssign((test_MethodTesterInherit*)corto_ptr_new(test_MethodTesterInherit_o)) : NULL
#define test_MethodTesterInheritUnset(_this) _this ? corto_ptr_free(_this, test_MethodTesterInherit_o), 0 : 0; _this = NULL;
#define test_MethodTesterInheritAssign(_this) _test_MethodTesterInheritAssign(_this)
#define test_MethodTesterInheritSet(_this) _this = _this ? _this : (test_MethodTesterInherit*)corto_ptr_new(test_MethodTesterInherit_o); _test_MethodTesterInheritAssign(_this)

/* /test/NestedConstructFail */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define NestedConstructFailCreate test_NestedConstructFailCreate
#endif
TEST_EXPORT test_NestedConstructFail _test_NestedConstructFailCreate(void);
#define test_NestedConstructFailCreate() _test_NestedConstructFailCreate()
#define test_NestedConstructFailCreate_auto(_id) test_NestedConstructFail _id = test_NestedConstructFailCreate(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define NestedConstructFailCreateChild test_NestedConstructFailCreateChild
#endif
TEST_EXPORT test_NestedConstructFail _test_NestedConstructFailCreateChild(corto_object _parent, corto_string _id);
#define test_NestedConstructFailCreateChild(_parent, _id) _test_NestedConstructFailCreateChild(_parent, _id)
#define test_NestedConstructFailCreateChild_auto(_parent, _id) test_NestedConstructFail _id = test_NestedConstructFailCreateChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define NestedConstructFailUpdate test_NestedConstructFailUpdate
#endif
TEST_EXPORT corto_int16 _test_NestedConstructFailUpdate(test_NestedConstructFail _this);
#define test_NestedConstructFailUpdate(_this) _test_NestedConstructFailUpdate(test_NestedConstructFail(_this))


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define NestedConstructFailDeclare test_NestedConstructFailDeclare
#endif
TEST_EXPORT test_NestedConstructFail _test_NestedConstructFailDeclare(void);
#define test_NestedConstructFailDeclare() _test_NestedConstructFailDeclare()
#define test_NestedConstructFailDeclare_auto(_id) test_NestedConstructFail _id = test_NestedConstructFailDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define NestedConstructFailDeclareChild test_NestedConstructFailDeclareChild
#endif
TEST_EXPORT test_NestedConstructFail _test_NestedConstructFailDeclareChild(corto_object _parent, corto_string _id);
#define test_NestedConstructFailDeclareChild(_parent, _id) _test_NestedConstructFailDeclareChild(_parent, _id)
#define test_NestedConstructFailDeclareChild_auto(_parent, _id) test_NestedConstructFail _id = test_NestedConstructFailDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define NestedConstructFailDefine test_NestedConstructFailDefine
#endif
TEST_EXPORT corto_int16 _test_NestedConstructFailDefine(test_NestedConstructFail _this);
#define test_NestedConstructFailDefine(_this) _test_NestedConstructFailDefine(test_NestedConstructFail(_this))

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define NestedConstructFailAssign test_NestedConstructFailAssign
#endif
TEST_EXPORT test_NestedConstructFail _test_NestedConstructFailAssign(test_NestedConstructFail _this);
#define test_NestedConstructFail__optional_NotSet NULL
#define test_NestedConstructFail__optional_Set() test_NestedConstructFailAssign((test_NestedConstructFail*)corto_ptr_new(test_NestedConstructFail_o)))
#define test_NestedConstructFail__optional_SetCond(cond) cond ? test_NestedConstructFailAssign((test_NestedConstructFail*)corto_ptr_new(test_NestedConstructFail_o)) : NULL
#define test_NestedConstructFailUnset(_this) _this ? corto_ptr_free(_this, test_NestedConstructFail_o), 0 : 0; _this = NULL;
#define test_NestedConstructFailAssign(_this) _test_NestedConstructFailAssign(_this)
#define test_NestedConstructFailSet(_this) _this = _this ? _this : (test_NestedConstructFail*)corto_ptr_new(test_NestedConstructFail_o); _test_NestedConstructFailAssign(_this)

/* /test/NestedInitFail */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define NestedInitFailCreate test_NestedInitFailCreate
#endif
TEST_EXPORT test_NestedInitFail _test_NestedInitFailCreate(void);
#define test_NestedInitFailCreate() _test_NestedInitFailCreate()
#define test_NestedInitFailCreate_auto(_id) test_NestedInitFail _id = test_NestedInitFailCreate(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define NestedInitFailCreateChild test_NestedInitFailCreateChild
#endif
TEST_EXPORT test_NestedInitFail _test_NestedInitFailCreateChild(corto_object _parent, corto_string _id);
#define test_NestedInitFailCreateChild(_parent, _id) _test_NestedInitFailCreateChild(_parent, _id)
#define test_NestedInitFailCreateChild_auto(_parent, _id) test_NestedInitFail _id = test_NestedInitFailCreateChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define NestedInitFailUpdate test_NestedInitFailUpdate
#endif
TEST_EXPORT corto_int16 _test_NestedInitFailUpdate(test_NestedInitFail _this);
#define test_NestedInitFailUpdate(_this) _test_NestedInitFailUpdate(test_NestedInitFail(_this))


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define NestedInitFailDeclare test_NestedInitFailDeclare
#endif
TEST_EXPORT test_NestedInitFail _test_NestedInitFailDeclare(void);
#define test_NestedInitFailDeclare() _test_NestedInitFailDeclare()
#define test_NestedInitFailDeclare_auto(_id) test_NestedInitFail _id = test_NestedInitFailDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define NestedInitFailDeclareChild test_NestedInitFailDeclareChild
#endif
TEST_EXPORT test_NestedInitFail _test_NestedInitFailDeclareChild(corto_object _parent, corto_string _id);
#define test_NestedInitFailDeclareChild(_parent, _id) _test_NestedInitFailDeclareChild(_parent, _id)
#define test_NestedInitFailDeclareChild_auto(_parent, _id) test_NestedInitFail _id = test_NestedInitFailDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define NestedInitFailDefine test_NestedInitFailDefine
#endif
TEST_EXPORT corto_int16 _test_NestedInitFailDefine(test_NestedInitFail _this);
#define test_NestedInitFailDefine(_this) _test_NestedInitFailDefine(test_NestedInitFail(_this))

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define NestedInitFailAssign test_NestedInitFailAssign
#endif
TEST_EXPORT test_NestedInitFail _test_NestedInitFailAssign(test_NestedInitFail _this);
#define test_NestedInitFail__optional_NotSet NULL
#define test_NestedInitFail__optional_Set() test_NestedInitFailAssign((test_NestedInitFail*)corto_ptr_new(test_NestedInitFail_o)))
#define test_NestedInitFail__optional_SetCond(cond) cond ? test_NestedInitFailAssign((test_NestedInitFail*)corto_ptr_new(test_NestedInitFail_o)) : NULL
#define test_NestedInitFailUnset(_this) _this ? corto_ptr_free(_this, test_NestedInitFail_o), 0 : 0; _this = NULL;
#define test_NestedInitFailAssign(_this) _test_NestedInitFailAssign(_this)
#define test_NestedInitFailSet(_this) _this = _this ? _this : (test_NestedInitFail*)corto_ptr_new(test_NestedInitFail_o); _test_NestedInitFailAssign(_this)

/* /test/ObjectArray */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ObjectArrayCreate test_ObjectArrayCreate
#endif
TEST_EXPORT corto_object* _test_ObjectArrayCreate(corto_uint32 length, corto_object* elements);
#define test_ObjectArrayCreate(length, elements) _test_ObjectArrayCreate(length, elements)
#define test_ObjectArrayCreate_auto(_id, length, elements) corto_object* _id = test_ObjectArrayCreate(length, elements); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ObjectArrayCreateChild test_ObjectArrayCreateChild
#endif
TEST_EXPORT corto_object* _test_ObjectArrayCreateChild(corto_object _parent, corto_string _id, corto_uint32 length, corto_object* elements);
#define test_ObjectArrayCreateChild(_parent, _id, length, elements) _test_ObjectArrayCreateChild(_parent, _id, length, elements)
#define test_ObjectArrayCreateChild_auto(_parent, _id, length, elements) corto_object* _id = test_ObjectArrayCreateChild(_parent, #_id, length, elements); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ObjectArrayUpdate test_ObjectArrayUpdate
#endif
TEST_EXPORT corto_int16 _test_ObjectArrayUpdate(test_ObjectArray _this, corto_uint32 length, corto_object* elements);
#define test_ObjectArrayUpdate(_this, length, elements) _test_ObjectArrayUpdate(test_ObjectArray(_this), length, elements)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ObjectArrayDeclare test_ObjectArrayDeclare
#endif
TEST_EXPORT corto_object* _test_ObjectArrayDeclare(void);
#define test_ObjectArrayDeclare() _test_ObjectArrayDeclare()
#define test_ObjectArrayDeclare_auto(_id) corto_object* _id = test_ObjectArrayDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ObjectArrayDeclareChild test_ObjectArrayDeclareChild
#endif
TEST_EXPORT corto_object* _test_ObjectArrayDeclareChild(corto_object _parent, corto_string _id);
#define test_ObjectArrayDeclareChild(_parent, _id) _test_ObjectArrayDeclareChild(_parent, _id)
#define test_ObjectArrayDeclareChild_auto(_parent, _id) corto_object* _id = test_ObjectArrayDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ObjectArrayDefine test_ObjectArrayDefine
#endif
TEST_EXPORT corto_int16 _test_ObjectArrayDefine(test_ObjectArray _this, corto_uint32 length, corto_object* elements);
#define test_ObjectArrayDefine(_this, length, elements) _test_ObjectArrayDefine(test_ObjectArray(_this), length, elements)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ObjectArrayAssign test_ObjectArrayAssign
#endif
TEST_EXPORT corto_object* _test_ObjectArrayAssign(test_ObjectArray _this, corto_uint32 length, corto_object* elements);
#define test_ObjectArray__optional_NotSet NULL
#define test_ObjectArray__optional_Set(length, elements) test_ObjectArrayAssign((test_ObjectArray*)corto_ptr_new(test_ObjectArray_o)), length, elements)
#define test_ObjectArray__optional_SetCond(cond, length, elements) cond ? test_ObjectArrayAssign((test_ObjectArray*)corto_ptr_new(test_ObjectArray_o), length, elements) : NULL
#define test_ObjectArrayUnset(_this) _this ? corto_ptr_free(_this, test_ObjectArray_o), 0 : 0; _this = NULL;
#define test_ObjectArrayAssign(_this, length, elements) _test_ObjectArrayAssign((corto_object*)_this, length, elements)
#define test_ObjectArraySet(_this, length, elements) _this = _this ? _this : (test_ObjectArray*)corto_ptr_new(test_ObjectArray_o); _test_ObjectArrayAssign((corto_object*)_this, length, elements)

/* /test/ObjectList */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ObjectListCreate test_ObjectListCreate
#endif
TEST_EXPORT test_ObjectList* _test_ObjectListCreate(corto_uint32 length, corto_object* elements);
#define test_ObjectListCreate(length, elements) _test_ObjectListCreate(length, elements)
#define test_ObjectListCreate_auto(_id, length, elements) test_ObjectList* _id = test_ObjectListCreate(length, elements); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ObjectListCreateChild test_ObjectListCreateChild
#endif
TEST_EXPORT test_ObjectList* _test_ObjectListCreateChild(corto_object _parent, corto_string _id, corto_uint32 length, corto_object* elements);
#define test_ObjectListCreateChild(_parent, _id, length, elements) _test_ObjectListCreateChild(_parent, _id, length, elements)
#define test_ObjectListCreateChild_auto(_parent, _id, length, elements) test_ObjectList* _id = test_ObjectListCreateChild(_parent, #_id, length, elements); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ObjectListUpdate test_ObjectListUpdate
#endif
TEST_EXPORT corto_int16 _test_ObjectListUpdate(test_ObjectList* _this, corto_uint32 length, corto_object* elements);
#define test_ObjectListUpdate(_this, length, elements) _test_ObjectListUpdate(test_ObjectList(_this), length, elements)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ObjectListDeclare test_ObjectListDeclare
#endif
TEST_EXPORT test_ObjectList* _test_ObjectListDeclare(void);
#define test_ObjectListDeclare() _test_ObjectListDeclare()
#define test_ObjectListDeclare_auto(_id) test_ObjectList* _id = test_ObjectListDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ObjectListDeclareChild test_ObjectListDeclareChild
#endif
TEST_EXPORT test_ObjectList* _test_ObjectListDeclareChild(corto_object _parent, corto_string _id);
#define test_ObjectListDeclareChild(_parent, _id) _test_ObjectListDeclareChild(_parent, _id)
#define test_ObjectListDeclareChild_auto(_parent, _id) test_ObjectList* _id = test_ObjectListDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ObjectListDefine test_ObjectListDefine
#endif
TEST_EXPORT corto_int16 _test_ObjectListDefine(test_ObjectList* _this, corto_uint32 length, corto_object* elements);
#define test_ObjectListDefine(_this, length, elements) _test_ObjectListDefine(test_ObjectList(_this), length, elements)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ObjectListAssign test_ObjectListAssign
#endif
TEST_EXPORT test_ObjectList* _test_ObjectListAssign(test_ObjectList* _this, corto_uint32 length, corto_object* elements);
#define test_ObjectList__optional_NotSet NULL
#define test_ObjectList__optional_Set(length, elements) test_ObjectListAssign((test_ObjectList*)corto_ptr_new(test_ObjectList_o)), length, elements)
#define test_ObjectList__optional_SetCond(cond, length, elements) cond ? test_ObjectListAssign((test_ObjectList*)corto_ptr_new(test_ObjectList_o), length, elements) : NULL
#define test_ObjectListUnset(_this) _this ? corto_ptr_free(_this, test_ObjectList_o), 0 : 0; _this = NULL;
#define test_ObjectListAssign(_this, length, elements) _test_ObjectListAssign(_this, length, elements)
#define test_ObjectListSet(_this, length, elements) _this = _this ? _this : (test_ObjectList*)corto_ptr_new(test_ObjectList_o); _test_ObjectListAssign(_this, length, elements)

/* /test/ObjectMgmt */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ObjectMgmtCreate test_ObjectMgmtCreate
#endif
TEST_EXPORT test_ObjectMgmt _test_ObjectMgmtCreate(uint32_t assertCount);
#define test_ObjectMgmtCreate(assertCount) _test_ObjectMgmtCreate(assertCount)
#define test_ObjectMgmtCreate_auto(_id, assertCount) test_ObjectMgmt _id = test_ObjectMgmtCreate(assertCount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ObjectMgmtCreateChild test_ObjectMgmtCreateChild
#endif
TEST_EXPORT test_ObjectMgmt _test_ObjectMgmtCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount);
#define test_ObjectMgmtCreateChild(_parent, _id, assertCount) _test_ObjectMgmtCreateChild(_parent, _id, assertCount)
#define test_ObjectMgmtCreateChild_auto(_parent, _id, assertCount) test_ObjectMgmt _id = test_ObjectMgmtCreateChild(_parent, #_id, assertCount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ObjectMgmtUpdate test_ObjectMgmtUpdate
#endif
TEST_EXPORT corto_int16 _test_ObjectMgmtUpdate(test_ObjectMgmt _this, uint32_t assertCount);
#define test_ObjectMgmtUpdate(_this, assertCount) _test_ObjectMgmtUpdate(test_ObjectMgmt(_this), assertCount)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ObjectMgmtDeclare test_ObjectMgmtDeclare
#endif
TEST_EXPORT test_ObjectMgmt _test_ObjectMgmtDeclare(void);
#define test_ObjectMgmtDeclare() _test_ObjectMgmtDeclare()
#define test_ObjectMgmtDeclare_auto(_id) test_ObjectMgmt _id = test_ObjectMgmtDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ObjectMgmtDeclareChild test_ObjectMgmtDeclareChild
#endif
TEST_EXPORT test_ObjectMgmt _test_ObjectMgmtDeclareChild(corto_object _parent, corto_string _id);
#define test_ObjectMgmtDeclareChild(_parent, _id) _test_ObjectMgmtDeclareChild(_parent, _id)
#define test_ObjectMgmtDeclareChild_auto(_parent, _id) test_ObjectMgmt _id = test_ObjectMgmtDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ObjectMgmtDefine test_ObjectMgmtDefine
#endif
TEST_EXPORT corto_int16 _test_ObjectMgmtDefine(test_ObjectMgmt _this, uint32_t assertCount);
#define test_ObjectMgmtDefine(_this, assertCount) _test_ObjectMgmtDefine(test_ObjectMgmt(_this), assertCount)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ObjectMgmtAssign test_ObjectMgmtAssign
#endif
TEST_EXPORT test_ObjectMgmt _test_ObjectMgmtAssign(test_ObjectMgmt _this, uint32_t assertCount);
#define test_ObjectMgmt__optional_NotSet NULL
#define test_ObjectMgmt__optional_Set(assertCount) test_ObjectMgmtAssign((test_ObjectMgmt*)corto_ptr_new(test_ObjectMgmt_o)), assertCount)
#define test_ObjectMgmt__optional_SetCond(cond, assertCount) cond ? test_ObjectMgmtAssign((test_ObjectMgmt*)corto_ptr_new(test_ObjectMgmt_o), assertCount) : NULL
#define test_ObjectMgmtUnset(_this) _this ? corto_ptr_free(_this, test_ObjectMgmt_o), 0 : 0; _this = NULL;
#define test_ObjectMgmtAssign(_this, assertCount) _test_ObjectMgmtAssign(_this, assertCount)
#define test_ObjectMgmtSet(_this, assertCount) _this = _this ? _this : (test_ObjectMgmt*)corto_ptr_new(test_ObjectMgmt_o); _test_ObjectMgmtAssign(_this, assertCount)

/* /test/ObjectSequence */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ObjectSequenceCreate test_ObjectSequenceCreate
#endif
TEST_EXPORT test_ObjectSequence* _test_ObjectSequenceCreate(corto_uint32 length, corto_object* elements);
#define test_ObjectSequenceCreate(length, elements) _test_ObjectSequenceCreate(length, elements)
#define test_ObjectSequenceCreate_auto(_id, length, elements) test_ObjectSequence* _id = test_ObjectSequenceCreate(length, elements); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ObjectSequenceCreateChild test_ObjectSequenceCreateChild
#endif
TEST_EXPORT test_ObjectSequence* _test_ObjectSequenceCreateChild(corto_object _parent, corto_string _id, corto_uint32 length, corto_object* elements);
#define test_ObjectSequenceCreateChild(_parent, _id, length, elements) _test_ObjectSequenceCreateChild(_parent, _id, length, elements)
#define test_ObjectSequenceCreateChild_auto(_parent, _id, length, elements) test_ObjectSequence* _id = test_ObjectSequenceCreateChild(_parent, #_id, length, elements); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ObjectSequenceUpdate test_ObjectSequenceUpdate
#endif
TEST_EXPORT corto_int16 _test_ObjectSequenceUpdate(test_ObjectSequence* _this, corto_uint32 length, corto_object* elements);
#define test_ObjectSequenceUpdate(_this, length, elements) _test_ObjectSequenceUpdate(test_ObjectSequence(_this), length, elements)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ObjectSequenceDeclare test_ObjectSequenceDeclare
#endif
TEST_EXPORT test_ObjectSequence* _test_ObjectSequenceDeclare(void);
#define test_ObjectSequenceDeclare() _test_ObjectSequenceDeclare()
#define test_ObjectSequenceDeclare_auto(_id) test_ObjectSequence* _id = test_ObjectSequenceDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ObjectSequenceDeclareChild test_ObjectSequenceDeclareChild
#endif
TEST_EXPORT test_ObjectSequence* _test_ObjectSequenceDeclareChild(corto_object _parent, corto_string _id);
#define test_ObjectSequenceDeclareChild(_parent, _id) _test_ObjectSequenceDeclareChild(_parent, _id)
#define test_ObjectSequenceDeclareChild_auto(_parent, _id) test_ObjectSequence* _id = test_ObjectSequenceDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ObjectSequenceDefine test_ObjectSequenceDefine
#endif
TEST_EXPORT corto_int16 _test_ObjectSequenceDefine(test_ObjectSequence* _this, corto_uint32 length, corto_object* elements);
#define test_ObjectSequenceDefine(_this, length, elements) _test_ObjectSequenceDefine(test_ObjectSequence(_this), length, elements)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ObjectSequenceAssign test_ObjectSequenceAssign
#endif
TEST_EXPORT test_ObjectSequence* _test_ObjectSequenceAssign(test_ObjectSequence* _this, corto_uint32 length, corto_object* elements);
#define test_ObjectSequence__optional_NotSet NULL
#define test_ObjectSequence__optional_Set(length, elements) test_ObjectSequenceAssign((test_ObjectSequence*)corto_ptr_new(test_ObjectSequence_o)), length, elements)
#define test_ObjectSequence__optional_SetCond(cond, length, elements) cond ? test_ObjectSequenceAssign((test_ObjectSequence*)corto_ptr_new(test_ObjectSequence_o), length, elements) : NULL
#define test_ObjectSequenceUnset(_this) _this ? corto_ptr_free(_this, test_ObjectSequence_o), 0 : 0; _this = NULL;
#define test_ObjectSequenceAssign(_this, length, elements) _test_ObjectSequenceAssign(_this, length, elements)
#define test_ObjectSequenceSet(_this, length, elements) _this = _this ? _this : (test_ObjectSequence*)corto_ptr_new(test_ObjectSequence_o); _test_ObjectSequenceAssign(_this, length, elements)

/* /test/ObserverDispatcher */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ObserverDispatcherCreate test_ObserverDispatcherCreate
#endif
TEST_EXPORT test_ObserverDispatcher _test_ObserverDispatcherCreate(bool called);
#define test_ObserverDispatcherCreate(called) _test_ObserverDispatcherCreate(called)
#define test_ObserverDispatcherCreate_auto(_id, called) test_ObserverDispatcher _id = test_ObserverDispatcherCreate(called); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ObserverDispatcherCreateChild test_ObserverDispatcherCreateChild
#endif
TEST_EXPORT test_ObserverDispatcher _test_ObserverDispatcherCreateChild(corto_object _parent, corto_string _id, bool called);
#define test_ObserverDispatcherCreateChild(_parent, _id, called) _test_ObserverDispatcherCreateChild(_parent, _id, called)
#define test_ObserverDispatcherCreateChild_auto(_parent, _id, called) test_ObserverDispatcher _id = test_ObserverDispatcherCreateChild(_parent, #_id, called); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ObserverDispatcherUpdate test_ObserverDispatcherUpdate
#endif
TEST_EXPORT corto_int16 _test_ObserverDispatcherUpdate(test_ObserverDispatcher _this, bool called);
#define test_ObserverDispatcherUpdate(_this, called) _test_ObserverDispatcherUpdate(test_ObserverDispatcher(_this), called)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ObserverDispatcherDeclare test_ObserverDispatcherDeclare
#endif
TEST_EXPORT test_ObserverDispatcher _test_ObserverDispatcherDeclare(void);
#define test_ObserverDispatcherDeclare() _test_ObserverDispatcherDeclare()
#define test_ObserverDispatcherDeclare_auto(_id) test_ObserverDispatcher _id = test_ObserverDispatcherDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ObserverDispatcherDeclareChild test_ObserverDispatcherDeclareChild
#endif
TEST_EXPORT test_ObserverDispatcher _test_ObserverDispatcherDeclareChild(corto_object _parent, corto_string _id);
#define test_ObserverDispatcherDeclareChild(_parent, _id) _test_ObserverDispatcherDeclareChild(_parent, _id)
#define test_ObserverDispatcherDeclareChild_auto(_parent, _id) test_ObserverDispatcher _id = test_ObserverDispatcherDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ObserverDispatcherDefine test_ObserverDispatcherDefine
#endif
TEST_EXPORT corto_int16 _test_ObserverDispatcherDefine(test_ObserverDispatcher _this, bool called);
#define test_ObserverDispatcherDefine(_this, called) _test_ObserverDispatcherDefine(test_ObserverDispatcher(_this), called)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ObserverDispatcherAssign test_ObserverDispatcherAssign
#endif
TEST_EXPORT test_ObserverDispatcher _test_ObserverDispatcherAssign(test_ObserverDispatcher _this, bool called);
#define test_ObserverDispatcher__optional_NotSet NULL
#define test_ObserverDispatcher__optional_Set(called) test_ObserverDispatcherAssign((test_ObserverDispatcher*)corto_ptr_new(test_ObserverDispatcher_o)), called)
#define test_ObserverDispatcher__optional_SetCond(cond, called) cond ? test_ObserverDispatcherAssign((test_ObserverDispatcher*)corto_ptr_new(test_ObserverDispatcher_o), called) : NULL
#define test_ObserverDispatcherUnset(_this) _this ? corto_ptr_free(_this, test_ObserverDispatcher_o), 0 : 0; _this = NULL;
#define test_ObserverDispatcherAssign(_this, called) _test_ObserverDispatcherAssign(_this, called)
#define test_ObserverDispatcherSet(_this, called) _this = _this ? _this : (test_ObserverDispatcher*)corto_ptr_new(test_ObserverDispatcher_o); _test_ObserverDispatcherAssign(_this, called)

/* /test/Observers */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ObserversCreate test_ObserversCreate
#endif
TEST_EXPORT test_Observers _test_ObserversCreate(uint32_t assertCount, int32_t count);
#define test_ObserversCreate(assertCount, count) _test_ObserversCreate(assertCount, count)
#define test_ObserversCreate_auto(_id, assertCount, count) test_Observers _id = test_ObserversCreate(assertCount, count); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ObserversCreateChild test_ObserversCreateChild
#endif
TEST_EXPORT test_Observers _test_ObserversCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount, int32_t count);
#define test_ObserversCreateChild(_parent, _id, assertCount, count) _test_ObserversCreateChild(_parent, _id, assertCount, count)
#define test_ObserversCreateChild_auto(_parent, _id, assertCount, count) test_Observers _id = test_ObserversCreateChild(_parent, #_id, assertCount, count); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ObserversUpdate test_ObserversUpdate
#endif
TEST_EXPORT corto_int16 _test_ObserversUpdate(test_Observers _this, uint32_t assertCount, int32_t count);
#define test_ObserversUpdate(_this, assertCount, count) _test_ObserversUpdate(test_Observers(_this), assertCount, count)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ObserversDeclare test_ObserversDeclare
#endif
TEST_EXPORT test_Observers _test_ObserversDeclare(void);
#define test_ObserversDeclare() _test_ObserversDeclare()
#define test_ObserversDeclare_auto(_id) test_Observers _id = test_ObserversDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ObserversDeclareChild test_ObserversDeclareChild
#endif
TEST_EXPORT test_Observers _test_ObserversDeclareChild(corto_object _parent, corto_string _id);
#define test_ObserversDeclareChild(_parent, _id) _test_ObserversDeclareChild(_parent, _id)
#define test_ObserversDeclareChild_auto(_parent, _id) test_Observers _id = test_ObserversDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ObserversDefine test_ObserversDefine
#endif
TEST_EXPORT corto_int16 _test_ObserversDefine(test_Observers _this, uint32_t assertCount, int32_t count);
#define test_ObserversDefine(_this, assertCount, count) _test_ObserversDefine(test_Observers(_this), assertCount, count)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ObserversAssign test_ObserversAssign
#endif
TEST_EXPORT test_Observers _test_ObserversAssign(test_Observers _this, uint32_t assertCount, int32_t count);
#define test_Observers__optional_NotSet NULL
#define test_Observers__optional_Set(assertCount, count) test_ObserversAssign((test_Observers*)corto_ptr_new(test_Observers_o)), assertCount, count)
#define test_Observers__optional_SetCond(cond, assertCount, count) cond ? test_ObserversAssign((test_Observers*)corto_ptr_new(test_Observers_o), assertCount, count) : NULL
#define test_ObserversUnset(_this) _this ? corto_ptr_free(_this, test_Observers_o), 0 : 0; _this = NULL;
#define test_ObserversAssign(_this, assertCount, count) _test_ObserversAssign(_this, assertCount, count)
#define test_ObserversSet(_this, assertCount, count) _this = _this ? _this : (test_Observers*)corto_ptr_new(test_Observers_o); _test_ObserversAssign(_this, assertCount, count)

/* /test/Overload */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define OverloadCreate test_OverloadCreate
#endif
TEST_EXPORT test_Overload _test_OverloadCreate(uint32_t assertCount);
#define test_OverloadCreate(assertCount) _test_OverloadCreate(assertCount)
#define test_OverloadCreate_auto(_id, assertCount) test_Overload _id = test_OverloadCreate(assertCount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define OverloadCreateChild test_OverloadCreateChild
#endif
TEST_EXPORT test_Overload _test_OverloadCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount);
#define test_OverloadCreateChild(_parent, _id, assertCount) _test_OverloadCreateChild(_parent, _id, assertCount)
#define test_OverloadCreateChild_auto(_parent, _id, assertCount) test_Overload _id = test_OverloadCreateChild(_parent, #_id, assertCount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define OverloadUpdate test_OverloadUpdate
#endif
TEST_EXPORT corto_int16 _test_OverloadUpdate(test_Overload _this, uint32_t assertCount);
#define test_OverloadUpdate(_this, assertCount) _test_OverloadUpdate(test_Overload(_this), assertCount)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define OverloadDeclare test_OverloadDeclare
#endif
TEST_EXPORT test_Overload _test_OverloadDeclare(void);
#define test_OverloadDeclare() _test_OverloadDeclare()
#define test_OverloadDeclare_auto(_id) test_Overload _id = test_OverloadDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define OverloadDeclareChild test_OverloadDeclareChild
#endif
TEST_EXPORT test_Overload _test_OverloadDeclareChild(corto_object _parent, corto_string _id);
#define test_OverloadDeclareChild(_parent, _id) _test_OverloadDeclareChild(_parent, _id)
#define test_OverloadDeclareChild_auto(_parent, _id) test_Overload _id = test_OverloadDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define OverloadDefine test_OverloadDefine
#endif
TEST_EXPORT corto_int16 _test_OverloadDefine(test_Overload _this, uint32_t assertCount);
#define test_OverloadDefine(_this, assertCount) _test_OverloadDefine(test_Overload(_this), assertCount)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define OverloadAssign test_OverloadAssign
#endif
TEST_EXPORT test_Overload _test_OverloadAssign(test_Overload _this, uint32_t assertCount);
#define test_Overload__optional_NotSet NULL
#define test_Overload__optional_Set(assertCount) test_OverloadAssign((test_Overload*)corto_ptr_new(test_Overload_o)), assertCount)
#define test_Overload__optional_SetCond(cond, assertCount) cond ? test_OverloadAssign((test_Overload*)corto_ptr_new(test_Overload_o), assertCount) : NULL
#define test_OverloadUnset(_this) _this ? corto_ptr_free(_this, test_Overload_o), 0 : 0; _this = NULL;
#define test_OverloadAssign(_this, assertCount) _test_OverloadAssign(_this, assertCount)
#define test_OverloadSet(_this, assertCount) _this = _this ? _this : (test_Overload*)corto_ptr_new(test_Overload_o); _test_OverloadAssign(_this, assertCount)

/* /test/Ownership */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define OwnershipCreate test_OwnershipCreate
#endif
TEST_EXPORT test_Ownership _test_OwnershipCreate(uint32_t assertCount, uintptr_t observable);
#define test_OwnershipCreate(assertCount, observable) _test_OwnershipCreate(assertCount, observable)
#define test_OwnershipCreate_auto(_id, assertCount, observable) test_Ownership _id = test_OwnershipCreate(assertCount, observable); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define OwnershipCreateChild test_OwnershipCreateChild
#endif
TEST_EXPORT test_Ownership _test_OwnershipCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount, uintptr_t observable);
#define test_OwnershipCreateChild(_parent, _id, assertCount, observable) _test_OwnershipCreateChild(_parent, _id, assertCount, observable)
#define test_OwnershipCreateChild_auto(_parent, _id, assertCount, observable) test_Ownership _id = test_OwnershipCreateChild(_parent, #_id, assertCount, observable); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define OwnershipUpdate test_OwnershipUpdate
#endif
TEST_EXPORT corto_int16 _test_OwnershipUpdate(test_Ownership _this, uint32_t assertCount, uintptr_t observable);
#define test_OwnershipUpdate(_this, assertCount, observable) _test_OwnershipUpdate(test_Ownership(_this), assertCount, observable)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define OwnershipDeclare test_OwnershipDeclare
#endif
TEST_EXPORT test_Ownership _test_OwnershipDeclare(void);
#define test_OwnershipDeclare() _test_OwnershipDeclare()
#define test_OwnershipDeclare_auto(_id) test_Ownership _id = test_OwnershipDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define OwnershipDeclareChild test_OwnershipDeclareChild
#endif
TEST_EXPORT test_Ownership _test_OwnershipDeclareChild(corto_object _parent, corto_string _id);
#define test_OwnershipDeclareChild(_parent, _id) _test_OwnershipDeclareChild(_parent, _id)
#define test_OwnershipDeclareChild_auto(_parent, _id) test_Ownership _id = test_OwnershipDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define OwnershipDefine test_OwnershipDefine
#endif
TEST_EXPORT corto_int16 _test_OwnershipDefine(test_Ownership _this, uint32_t assertCount, uintptr_t observable);
#define test_OwnershipDefine(_this, assertCount, observable) _test_OwnershipDefine(test_Ownership(_this), assertCount, observable)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define OwnershipAssign test_OwnershipAssign
#endif
TEST_EXPORT test_Ownership _test_OwnershipAssign(test_Ownership _this, uint32_t assertCount, uintptr_t observable);
#define test_Ownership__optional_NotSet NULL
#define test_Ownership__optional_Set(assertCount, observable) test_OwnershipAssign((test_Ownership*)corto_ptr_new(test_Ownership_o)), assertCount, observable)
#define test_Ownership__optional_SetCond(cond, assertCount, observable) cond ? test_OwnershipAssign((test_Ownership*)corto_ptr_new(test_Ownership_o), assertCount, observable) : NULL
#define test_OwnershipUnset(_this) _this ? corto_ptr_free(_this, test_Ownership_o), 0 : 0; _this = NULL;
#define test_OwnershipAssign(_this, assertCount, observable) _test_OwnershipAssign(_this, assertCount, observable)
#define test_OwnershipSet(_this, assertCount, observable) _this = _this ? _this : (test_Ownership*)corto_ptr_new(test_Ownership_o); _test_OwnershipAssign(_this, assertCount, observable)

/* /test/Plane */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define PlaneCreate test_PlaneCreate
#endif
TEST_EXPORT test_Plane _test_PlaneCreate(double cur_x, double cur_y);
#define test_PlaneCreate(cur_x, cur_y) _test_PlaneCreate(cur_x, cur_y)
#define test_PlaneCreate_auto(_id, cur_x, cur_y) test_Plane _id = test_PlaneCreate(cur_x, cur_y); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define PlaneCreateChild test_PlaneCreateChild
#endif
TEST_EXPORT test_Plane _test_PlaneCreateChild(corto_object _parent, corto_string _id, double cur_x, double cur_y);
#define test_PlaneCreateChild(_parent, _id, cur_x, cur_y) _test_PlaneCreateChild(_parent, _id, cur_x, cur_y)
#define test_PlaneCreateChild_auto(_parent, _id, cur_x, cur_y) test_Plane _id = test_PlaneCreateChild(_parent, #_id, cur_x, cur_y); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define PlaneUpdate test_PlaneUpdate
#endif
TEST_EXPORT corto_int16 _test_PlaneUpdate(test_Plane _this, double cur_x, double cur_y);
#define test_PlaneUpdate(_this, cur_x, cur_y) _test_PlaneUpdate(test_Plane(_this), cur_x, cur_y)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define PlaneDeclare test_PlaneDeclare
#endif
TEST_EXPORT test_Plane _test_PlaneDeclare(void);
#define test_PlaneDeclare() _test_PlaneDeclare()
#define test_PlaneDeclare_auto(_id) test_Plane _id = test_PlaneDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define PlaneDeclareChild test_PlaneDeclareChild
#endif
TEST_EXPORT test_Plane _test_PlaneDeclareChild(corto_object _parent, corto_string _id);
#define test_PlaneDeclareChild(_parent, _id) _test_PlaneDeclareChild(_parent, _id)
#define test_PlaneDeclareChild_auto(_parent, _id) test_Plane _id = test_PlaneDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define PlaneDefine test_PlaneDefine
#endif
TEST_EXPORT corto_int16 _test_PlaneDefine(test_Plane _this, double cur_x, double cur_y);
#define test_PlaneDefine(_this, cur_x, cur_y) _test_PlaneDefine(test_Plane(_this), cur_x, cur_y)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define PlaneAssign test_PlaneAssign
#endif
TEST_EXPORT test_Plane _test_PlaneAssign(test_Plane _this, double cur_x, double cur_y);
#define test_Plane__optional_NotSet NULL
#define test_Plane__optional_Set(cur_x, cur_y) test_PlaneAssign((test_Plane*)corto_ptr_new(test_Plane_o)), cur_x, cur_y)
#define test_Plane__optional_SetCond(cond, cur_x, cur_y) cond ? test_PlaneAssign((test_Plane*)corto_ptr_new(test_Plane_o), cur_x, cur_y) : NULL
#define test_PlaneUnset(_this) _this ? corto_ptr_free(_this, test_Plane_o), 0 : 0; _this = NULL;
#define test_PlaneAssign(_this, cur_x, cur_y) _test_PlaneAssign(_this, cur_x, cur_y)
#define test_PlaneSet(_this, cur_x, cur_y) _this = _this ? _this : (test_Plane*)corto_ptr_new(test_Plane_o); _test_PlaneAssign(_this, cur_x, cur_y)

/* /test/Point */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define PointCreate test_PointCreate
#endif
TEST_EXPORT test_Point* _test_PointCreate(int32_t x, int32_t y);
#define test_PointCreate(x, y) _test_PointCreate(x, y)
#define test_PointCreate_auto(_id, x, y) test_Point* _id = test_PointCreate(x, y); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define PointCreateChild test_PointCreateChild
#endif
TEST_EXPORT test_Point* _test_PointCreateChild(corto_object _parent, corto_string _id, int32_t x, int32_t y);
#define test_PointCreateChild(_parent, _id, x, y) _test_PointCreateChild(_parent, _id, x, y)
#define test_PointCreateChild_auto(_parent, _id, x, y) test_Point* _id = test_PointCreateChild(_parent, #_id, x, y); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define PointUpdate test_PointUpdate
#endif
TEST_EXPORT corto_int16 _test_PointUpdate(test_Point* _this, int32_t x, int32_t y);
#define test_PointUpdate(_this, x, y) _test_PointUpdate(test_Point(_this), x, y)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define PointDeclare test_PointDeclare
#endif
TEST_EXPORT test_Point* _test_PointDeclare(void);
#define test_PointDeclare() _test_PointDeclare()
#define test_PointDeclare_auto(_id) test_Point* _id = test_PointDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define PointDeclareChild test_PointDeclareChild
#endif
TEST_EXPORT test_Point* _test_PointDeclareChild(corto_object _parent, corto_string _id);
#define test_PointDeclareChild(_parent, _id) _test_PointDeclareChild(_parent, _id)
#define test_PointDeclareChild_auto(_parent, _id) test_Point* _id = test_PointDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define PointDefine test_PointDefine
#endif
TEST_EXPORT corto_int16 _test_PointDefine(test_Point* _this, int32_t x, int32_t y);
#define test_PointDefine(_this, x, y) _test_PointDefine(test_Point(_this), x, y)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define PointAssign test_PointAssign
#endif
TEST_EXPORT test_Point* _test_PointAssign(test_Point* _this, int32_t x, int32_t y);
#define test_Point__optional_NotSet NULL
#define test_Point__optional_Set(x, y) test_PointAssign((test_Point*)corto_ptr_new(test_Point_o)), x, y)
#define test_Point__optional_SetCond(cond, x, y) cond ? test_PointAssign((test_Point*)corto_ptr_new(test_Point_o), x, y) : NULL
#define test_PointUnset(_this) _this ? corto_ptr_free(_this, test_Point_o), 0 : 0; _this = NULL;
#define test_PointAssign(_this, x, y) _test_PointAssign(_this, x, y)
#define test_PointSet(_this, x, y) _this = _this ? _this : (test_Point*)corto_ptr_new(test_Point_o); _test_PointAssign(_this, x, y)

/* /test/Point3D */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define Point3DCreate test_Point3DCreate
#endif
TEST_EXPORT test_Point3D* _test_Point3DCreate(int32_t x, int32_t y, int32_t z);
#define test_Point3DCreate(x, y, z) _test_Point3DCreate(x, y, z)
#define test_Point3DCreate_auto(_id, x, y, z) test_Point3D* _id = test_Point3DCreate(x, y, z); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define Point3DCreateChild test_Point3DCreateChild
#endif
TEST_EXPORT test_Point3D* _test_Point3DCreateChild(corto_object _parent, corto_string _id, int32_t x, int32_t y, int32_t z);
#define test_Point3DCreateChild(_parent, _id, x, y, z) _test_Point3DCreateChild(_parent, _id, x, y, z)
#define test_Point3DCreateChild_auto(_parent, _id, x, y, z) test_Point3D* _id = test_Point3DCreateChild(_parent, #_id, x, y, z); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define Point3DUpdate test_Point3DUpdate
#endif
TEST_EXPORT corto_int16 _test_Point3DUpdate(test_Point3D* _this, int32_t x, int32_t y, int32_t z);
#define test_Point3DUpdate(_this, x, y, z) _test_Point3DUpdate(test_Point3D(_this), x, y, z)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define Point3DDeclare test_Point3DDeclare
#endif
TEST_EXPORT test_Point3D* _test_Point3DDeclare(void);
#define test_Point3DDeclare() _test_Point3DDeclare()
#define test_Point3DDeclare_auto(_id) test_Point3D* _id = test_Point3DDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define Point3DDeclareChild test_Point3DDeclareChild
#endif
TEST_EXPORT test_Point3D* _test_Point3DDeclareChild(corto_object _parent, corto_string _id);
#define test_Point3DDeclareChild(_parent, _id) _test_Point3DDeclareChild(_parent, _id)
#define test_Point3DDeclareChild_auto(_parent, _id) test_Point3D* _id = test_Point3DDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define Point3DDefine test_Point3DDefine
#endif
TEST_EXPORT corto_int16 _test_Point3DDefine(test_Point3D* _this, int32_t x, int32_t y, int32_t z);
#define test_Point3DDefine(_this, x, y, z) _test_Point3DDefine(test_Point3D(_this), x, y, z)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define Point3DAssign test_Point3DAssign
#endif
TEST_EXPORT test_Point3D* _test_Point3DAssign(test_Point3D* _this, int32_t x, int32_t y, int32_t z);
#define test_Point3D__optional_NotSet NULL
#define test_Point3D__optional_Set(x, y, z) test_Point3DAssign((test_Point3D*)corto_ptr_new(test_Point3D_o)), x, y, z)
#define test_Point3D__optional_SetCond(cond, x, y, z) cond ? test_Point3DAssign((test_Point3D*)corto_ptr_new(test_Point3D_o), x, y, z) : NULL
#define test_Point3DUnset(_this) _this ? corto_ptr_free(_this, test_Point3D_o), 0 : 0; _this = NULL;
#define test_Point3DAssign(_this, x, y, z) _test_Point3DAssign(_this, x, y, z)
#define test_Point3DSet(_this, x, y, z) _this = _this ? _this : (test_Point3D*)corto_ptr_new(test_Point3D_o); _test_Point3DAssign(_this, x, y, z)

/* /test/ReferenceArray */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ReferenceArrayCreate test_ReferenceArrayCreate
#endif
TEST_EXPORT corto_object* _test_ReferenceArrayCreate(corto_uint32 length, corto_object* elements);
#define test_ReferenceArrayCreate(length, elements) _test_ReferenceArrayCreate(length, elements)
#define test_ReferenceArrayCreate_auto(_id, length, elements) corto_object* _id = test_ReferenceArrayCreate(length, elements); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ReferenceArrayCreateChild test_ReferenceArrayCreateChild
#endif
TEST_EXPORT corto_object* _test_ReferenceArrayCreateChild(corto_object _parent, corto_string _id, corto_uint32 length, corto_object* elements);
#define test_ReferenceArrayCreateChild(_parent, _id, length, elements) _test_ReferenceArrayCreateChild(_parent, _id, length, elements)
#define test_ReferenceArrayCreateChild_auto(_parent, _id, length, elements) corto_object* _id = test_ReferenceArrayCreateChild(_parent, #_id, length, elements); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ReferenceArrayUpdate test_ReferenceArrayUpdate
#endif
TEST_EXPORT corto_int16 _test_ReferenceArrayUpdate(test_ReferenceArray _this, corto_uint32 length, corto_object* elements);
#define test_ReferenceArrayUpdate(_this, length, elements) _test_ReferenceArrayUpdate(test_ReferenceArray(_this), length, elements)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ReferenceArrayDeclare test_ReferenceArrayDeclare
#endif
TEST_EXPORT corto_object* _test_ReferenceArrayDeclare(void);
#define test_ReferenceArrayDeclare() _test_ReferenceArrayDeclare()
#define test_ReferenceArrayDeclare_auto(_id) corto_object* _id = test_ReferenceArrayDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ReferenceArrayDeclareChild test_ReferenceArrayDeclareChild
#endif
TEST_EXPORT corto_object* _test_ReferenceArrayDeclareChild(corto_object _parent, corto_string _id);
#define test_ReferenceArrayDeclareChild(_parent, _id) _test_ReferenceArrayDeclareChild(_parent, _id)
#define test_ReferenceArrayDeclareChild_auto(_parent, _id) corto_object* _id = test_ReferenceArrayDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ReferenceArrayDefine test_ReferenceArrayDefine
#endif
TEST_EXPORT corto_int16 _test_ReferenceArrayDefine(test_ReferenceArray _this, corto_uint32 length, corto_object* elements);
#define test_ReferenceArrayDefine(_this, length, elements) _test_ReferenceArrayDefine(test_ReferenceArray(_this), length, elements)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ReferenceArrayAssign test_ReferenceArrayAssign
#endif
TEST_EXPORT corto_object* _test_ReferenceArrayAssign(test_ReferenceArray _this, corto_uint32 length, corto_object* elements);
#define test_ReferenceArray__optional_NotSet NULL
#define test_ReferenceArray__optional_Set(length, elements) test_ReferenceArrayAssign((test_ReferenceArray*)corto_ptr_new(test_ReferenceArray_o)), length, elements)
#define test_ReferenceArray__optional_SetCond(cond, length, elements) cond ? test_ReferenceArrayAssign((test_ReferenceArray*)corto_ptr_new(test_ReferenceArray_o), length, elements) : NULL
#define test_ReferenceArrayUnset(_this) _this ? corto_ptr_free(_this, test_ReferenceArray_o), 0 : 0; _this = NULL;
#define test_ReferenceArrayAssign(_this, length, elements) _test_ReferenceArrayAssign((corto_object*)_this, length, elements)
#define test_ReferenceArraySet(_this, length, elements) _this = _this ? _this : (test_ReferenceArray*)corto_ptr_new(test_ReferenceArray_o); _test_ReferenceArrayAssign((corto_object*)_this, length, elements)

/* /test/ReferenceList */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ReferenceListCreate test_ReferenceListCreate
#endif
TEST_EXPORT test_ReferenceList* _test_ReferenceListCreate(corto_uint32 length, corto_object* elements);
#define test_ReferenceListCreate(length, elements) _test_ReferenceListCreate(length, elements)
#define test_ReferenceListCreate_auto(_id, length, elements) test_ReferenceList* _id = test_ReferenceListCreate(length, elements); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ReferenceListCreateChild test_ReferenceListCreateChild
#endif
TEST_EXPORT test_ReferenceList* _test_ReferenceListCreateChild(corto_object _parent, corto_string _id, corto_uint32 length, corto_object* elements);
#define test_ReferenceListCreateChild(_parent, _id, length, elements) _test_ReferenceListCreateChild(_parent, _id, length, elements)
#define test_ReferenceListCreateChild_auto(_parent, _id, length, elements) test_ReferenceList* _id = test_ReferenceListCreateChild(_parent, #_id, length, elements); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ReferenceListUpdate test_ReferenceListUpdate
#endif
TEST_EXPORT corto_int16 _test_ReferenceListUpdate(test_ReferenceList* _this, corto_uint32 length, corto_object* elements);
#define test_ReferenceListUpdate(_this, length, elements) _test_ReferenceListUpdate(test_ReferenceList(_this), length, elements)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ReferenceListDeclare test_ReferenceListDeclare
#endif
TEST_EXPORT test_ReferenceList* _test_ReferenceListDeclare(void);
#define test_ReferenceListDeclare() _test_ReferenceListDeclare()
#define test_ReferenceListDeclare_auto(_id) test_ReferenceList* _id = test_ReferenceListDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ReferenceListDeclareChild test_ReferenceListDeclareChild
#endif
TEST_EXPORT test_ReferenceList* _test_ReferenceListDeclareChild(corto_object _parent, corto_string _id);
#define test_ReferenceListDeclareChild(_parent, _id) _test_ReferenceListDeclareChild(_parent, _id)
#define test_ReferenceListDeclareChild_auto(_parent, _id) test_ReferenceList* _id = test_ReferenceListDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ReferenceListDefine test_ReferenceListDefine
#endif
TEST_EXPORT corto_int16 _test_ReferenceListDefine(test_ReferenceList* _this, corto_uint32 length, corto_object* elements);
#define test_ReferenceListDefine(_this, length, elements) _test_ReferenceListDefine(test_ReferenceList(_this), length, elements)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ReferenceListAssign test_ReferenceListAssign
#endif
TEST_EXPORT test_ReferenceList* _test_ReferenceListAssign(test_ReferenceList* _this, corto_uint32 length, corto_object* elements);
#define test_ReferenceList__optional_NotSet NULL
#define test_ReferenceList__optional_Set(length, elements) test_ReferenceListAssign((test_ReferenceList*)corto_ptr_new(test_ReferenceList_o)), length, elements)
#define test_ReferenceList__optional_SetCond(cond, length, elements) cond ? test_ReferenceListAssign((test_ReferenceList*)corto_ptr_new(test_ReferenceList_o), length, elements) : NULL
#define test_ReferenceListUnset(_this) _this ? corto_ptr_free(_this, test_ReferenceList_o), 0 : 0; _this = NULL;
#define test_ReferenceListAssign(_this, length, elements) _test_ReferenceListAssign(_this, length, elements)
#define test_ReferenceListSet(_this, length, elements) _this = _this ? _this : (test_ReferenceList*)corto_ptr_new(test_ReferenceList_o); _test_ReferenceListAssign(_this, length, elements)

/* /test/ReferenceMember */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ReferenceMemberCreate test_ReferenceMemberCreate
#endif
TEST_EXPORT test_ReferenceMember* _test_ReferenceMemberCreate(corto_object m, int32_t n);
#define test_ReferenceMemberCreate(m, n) _test_ReferenceMemberCreate(m, n)
#define test_ReferenceMemberCreate_auto(_id, m, n) test_ReferenceMember* _id = test_ReferenceMemberCreate(m, n); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ReferenceMemberCreateChild test_ReferenceMemberCreateChild
#endif
TEST_EXPORT test_ReferenceMember* _test_ReferenceMemberCreateChild(corto_object _parent, corto_string _id, corto_object m, int32_t n);
#define test_ReferenceMemberCreateChild(_parent, _id, m, n) _test_ReferenceMemberCreateChild(_parent, _id, m, n)
#define test_ReferenceMemberCreateChild_auto(_parent, _id, m, n) test_ReferenceMember* _id = test_ReferenceMemberCreateChild(_parent, #_id, m, n); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ReferenceMemberUpdate test_ReferenceMemberUpdate
#endif
TEST_EXPORT corto_int16 _test_ReferenceMemberUpdate(test_ReferenceMember* _this, corto_object m, int32_t n);
#define test_ReferenceMemberUpdate(_this, m, n) _test_ReferenceMemberUpdate(test_ReferenceMember(_this), m, n)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ReferenceMemberDeclare test_ReferenceMemberDeclare
#endif
TEST_EXPORT test_ReferenceMember* _test_ReferenceMemberDeclare(void);
#define test_ReferenceMemberDeclare() _test_ReferenceMemberDeclare()
#define test_ReferenceMemberDeclare_auto(_id) test_ReferenceMember* _id = test_ReferenceMemberDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ReferenceMemberDeclareChild test_ReferenceMemberDeclareChild
#endif
TEST_EXPORT test_ReferenceMember* _test_ReferenceMemberDeclareChild(corto_object _parent, corto_string _id);
#define test_ReferenceMemberDeclareChild(_parent, _id) _test_ReferenceMemberDeclareChild(_parent, _id)
#define test_ReferenceMemberDeclareChild_auto(_parent, _id) test_ReferenceMember* _id = test_ReferenceMemberDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ReferenceMemberDefine test_ReferenceMemberDefine
#endif
TEST_EXPORT corto_int16 _test_ReferenceMemberDefine(test_ReferenceMember* _this, corto_object m, int32_t n);
#define test_ReferenceMemberDefine(_this, m, n) _test_ReferenceMemberDefine(test_ReferenceMember(_this), m, n)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ReferenceMemberAssign test_ReferenceMemberAssign
#endif
TEST_EXPORT test_ReferenceMember* _test_ReferenceMemberAssign(test_ReferenceMember* _this, corto_object m, int32_t n);
#define test_ReferenceMember__optional_NotSet NULL
#define test_ReferenceMember__optional_Set(m, n) test_ReferenceMemberAssign((test_ReferenceMember*)corto_ptr_new(test_ReferenceMember_o)), m, n)
#define test_ReferenceMember__optional_SetCond(cond, m, n) cond ? test_ReferenceMemberAssign((test_ReferenceMember*)corto_ptr_new(test_ReferenceMember_o), m, n) : NULL
#define test_ReferenceMemberUnset(_this) _this ? corto_ptr_free(_this, test_ReferenceMember_o), 0 : 0; _this = NULL;
#define test_ReferenceMemberAssign(_this, m, n) _test_ReferenceMemberAssign(_this, m, n)
#define test_ReferenceMemberSet(_this, m, n) _this = _this ? _this : (test_ReferenceMember*)corto_ptr_new(test_ReferenceMember_o); _test_ReferenceMemberAssign(_this, m, n)

/* /test/ReferenceSequence */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ReferenceSequenceCreate test_ReferenceSequenceCreate
#endif
TEST_EXPORT test_ReferenceSequence* _test_ReferenceSequenceCreate(corto_uint32 length, corto_object* elements);
#define test_ReferenceSequenceCreate(length, elements) _test_ReferenceSequenceCreate(length, elements)
#define test_ReferenceSequenceCreate_auto(_id, length, elements) test_ReferenceSequence* _id = test_ReferenceSequenceCreate(length, elements); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ReferenceSequenceCreateChild test_ReferenceSequenceCreateChild
#endif
TEST_EXPORT test_ReferenceSequence* _test_ReferenceSequenceCreateChild(corto_object _parent, corto_string _id, corto_uint32 length, corto_object* elements);
#define test_ReferenceSequenceCreateChild(_parent, _id, length, elements) _test_ReferenceSequenceCreateChild(_parent, _id, length, elements)
#define test_ReferenceSequenceCreateChild_auto(_parent, _id, length, elements) test_ReferenceSequence* _id = test_ReferenceSequenceCreateChild(_parent, #_id, length, elements); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ReferenceSequenceUpdate test_ReferenceSequenceUpdate
#endif
TEST_EXPORT corto_int16 _test_ReferenceSequenceUpdate(test_ReferenceSequence* _this, corto_uint32 length, corto_object* elements);
#define test_ReferenceSequenceUpdate(_this, length, elements) _test_ReferenceSequenceUpdate(test_ReferenceSequence(_this), length, elements)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ReferenceSequenceDeclare test_ReferenceSequenceDeclare
#endif
TEST_EXPORT test_ReferenceSequence* _test_ReferenceSequenceDeclare(void);
#define test_ReferenceSequenceDeclare() _test_ReferenceSequenceDeclare()
#define test_ReferenceSequenceDeclare_auto(_id) test_ReferenceSequence* _id = test_ReferenceSequenceDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ReferenceSequenceDeclareChild test_ReferenceSequenceDeclareChild
#endif
TEST_EXPORT test_ReferenceSequence* _test_ReferenceSequenceDeclareChild(corto_object _parent, corto_string _id);
#define test_ReferenceSequenceDeclareChild(_parent, _id) _test_ReferenceSequenceDeclareChild(_parent, _id)
#define test_ReferenceSequenceDeclareChild_auto(_parent, _id) test_ReferenceSequence* _id = test_ReferenceSequenceDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ReferenceSequenceDefine test_ReferenceSequenceDefine
#endif
TEST_EXPORT corto_int16 _test_ReferenceSequenceDefine(test_ReferenceSequence* _this, corto_uint32 length, corto_object* elements);
#define test_ReferenceSequenceDefine(_this, length, elements) _test_ReferenceSequenceDefine(test_ReferenceSequence(_this), length, elements)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ReferenceSequenceAssign test_ReferenceSequenceAssign
#endif
TEST_EXPORT test_ReferenceSequence* _test_ReferenceSequenceAssign(test_ReferenceSequence* _this, corto_uint32 length, corto_object* elements);
#define test_ReferenceSequence__optional_NotSet NULL
#define test_ReferenceSequence__optional_Set(length, elements) test_ReferenceSequenceAssign((test_ReferenceSequence*)corto_ptr_new(test_ReferenceSequence_o)), length, elements)
#define test_ReferenceSequence__optional_SetCond(cond, length, elements) cond ? test_ReferenceSequenceAssign((test_ReferenceSequence*)corto_ptr_new(test_ReferenceSequence_o), length, elements) : NULL
#define test_ReferenceSequenceUnset(_this) _this ? corto_ptr_free(_this, test_ReferenceSequence_o), 0 : 0; _this = NULL;
#define test_ReferenceSequenceAssign(_this, length, elements) _test_ReferenceSequenceAssign(_this, length, elements)
#define test_ReferenceSequenceSet(_this, length, elements) _this = _this ? _this : (test_ReferenceSequence*)corto_ptr_new(test_ReferenceSequence_o); _test_ReferenceSequenceAssign(_this, length, elements)

/* /test/ReferenceTargetMember */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ReferenceTargetMemberCreate test_ReferenceTargetMemberCreate
#endif
TEST_EXPORT test_ReferenceTargetMember* _test_ReferenceTargetMemberCreate(corto_object m, int32_t n);
#define test_ReferenceTargetMemberCreate(m, n) _test_ReferenceTargetMemberCreate(m, n)
#define test_ReferenceTargetMemberCreate_auto(_id, m, n) test_ReferenceTargetMember* _id = test_ReferenceTargetMemberCreate(m, n); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ReferenceTargetMemberCreateChild test_ReferenceTargetMemberCreateChild
#endif
TEST_EXPORT test_ReferenceTargetMember* _test_ReferenceTargetMemberCreateChild(corto_object _parent, corto_string _id, corto_object m, int32_t n);
#define test_ReferenceTargetMemberCreateChild(_parent, _id, m, n) _test_ReferenceTargetMemberCreateChild(_parent, _id, m, n)
#define test_ReferenceTargetMemberCreateChild_auto(_parent, _id, m, n) test_ReferenceTargetMember* _id = test_ReferenceTargetMemberCreateChild(_parent, #_id, m, n); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ReferenceTargetMemberUpdate test_ReferenceTargetMemberUpdate
#endif
TEST_EXPORT corto_int16 _test_ReferenceTargetMemberUpdate(test_ReferenceTargetMember* _this, corto_object m, int32_t n);
#define test_ReferenceTargetMemberUpdate(_this, m, n) _test_ReferenceTargetMemberUpdate(test_ReferenceTargetMember(_this), m, n)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ReferenceTargetMemberDeclare test_ReferenceTargetMemberDeclare
#endif
TEST_EXPORT test_ReferenceTargetMember* _test_ReferenceTargetMemberDeclare(void);
#define test_ReferenceTargetMemberDeclare() _test_ReferenceTargetMemberDeclare()
#define test_ReferenceTargetMemberDeclare_auto(_id) test_ReferenceTargetMember* _id = test_ReferenceTargetMemberDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ReferenceTargetMemberDeclareChild test_ReferenceTargetMemberDeclareChild
#endif
TEST_EXPORT test_ReferenceTargetMember* _test_ReferenceTargetMemberDeclareChild(corto_object _parent, corto_string _id);
#define test_ReferenceTargetMemberDeclareChild(_parent, _id) _test_ReferenceTargetMemberDeclareChild(_parent, _id)
#define test_ReferenceTargetMemberDeclareChild_auto(_parent, _id) test_ReferenceTargetMember* _id = test_ReferenceTargetMemberDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ReferenceTargetMemberDefine test_ReferenceTargetMemberDefine
#endif
TEST_EXPORT corto_int16 _test_ReferenceTargetMemberDefine(test_ReferenceTargetMember* _this, corto_object m, int32_t n);
#define test_ReferenceTargetMemberDefine(_this, m, n) _test_ReferenceTargetMemberDefine(test_ReferenceTargetMember(_this), m, n)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ReferenceTargetMemberAssign test_ReferenceTargetMemberAssign
#endif
TEST_EXPORT test_ReferenceTargetMember* _test_ReferenceTargetMemberAssign(test_ReferenceTargetMember* _this, corto_object m, int32_t n);
#define test_ReferenceTargetMember__optional_NotSet NULL
#define test_ReferenceTargetMember__optional_Set(m, n) test_ReferenceTargetMemberAssign((test_ReferenceTargetMember*)corto_ptr_new(test_ReferenceTargetMember_o)), m, n)
#define test_ReferenceTargetMember__optional_SetCond(cond, m, n) cond ? test_ReferenceTargetMemberAssign((test_ReferenceTargetMember*)corto_ptr_new(test_ReferenceTargetMember_o), m, n) : NULL
#define test_ReferenceTargetMemberUnset(_this) _this ? corto_ptr_free(_this, test_ReferenceTargetMember_o), 0 : 0; _this = NULL;
#define test_ReferenceTargetMemberAssign(_this, m, n) _test_ReferenceTargetMemberAssign(_this, m, n)
#define test_ReferenceTargetMemberSet(_this, m, n) _this = _this ? _this : (test_ReferenceTargetMember*)corto_ptr_new(test_ReferenceTargetMember_o); _test_ReferenceTargetMemberAssign(_this, m, n)

/* /test/RelativeName */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define RelativeNameCreate test_RelativeNameCreate
#endif
TEST_EXPORT test_RelativeName _test_RelativeNameCreate(uint32_t assertCount, corto_object tier1, corto_object tier2, corto_object tier3, corto_object obj, corto_object disjunct, corto_object child);
#define test_RelativeNameCreate(assertCount, tier1, tier2, tier3, obj, disjunct, child) _test_RelativeNameCreate(assertCount, tier1, tier2, tier3, obj, disjunct, child)
#define test_RelativeNameCreate_auto(_id, assertCount, tier1, tier2, tier3, obj, disjunct, child) test_RelativeName _id = test_RelativeNameCreate(assertCount, tier1, tier2, tier3, obj, disjunct, child); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define RelativeNameCreateChild test_RelativeNameCreateChild
#endif
TEST_EXPORT test_RelativeName _test_RelativeNameCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount, corto_object tier1, corto_object tier2, corto_object tier3, corto_object obj, corto_object disjunct, corto_object child);
#define test_RelativeNameCreateChild(_parent, _id, assertCount, tier1, tier2, tier3, obj, disjunct, child) _test_RelativeNameCreateChild(_parent, _id, assertCount, tier1, tier2, tier3, obj, disjunct, child)
#define test_RelativeNameCreateChild_auto(_parent, _id, assertCount, tier1, tier2, tier3, obj, disjunct, child) test_RelativeName _id = test_RelativeNameCreateChild(_parent, #_id, assertCount, tier1, tier2, tier3, obj, disjunct, child); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define RelativeNameUpdate test_RelativeNameUpdate
#endif
TEST_EXPORT corto_int16 _test_RelativeNameUpdate(test_RelativeName _this, uint32_t assertCount, corto_object tier1, corto_object tier2, corto_object tier3, corto_object obj, corto_object disjunct, corto_object child);
#define test_RelativeNameUpdate(_this, assertCount, tier1, tier2, tier3, obj, disjunct, child) _test_RelativeNameUpdate(test_RelativeName(_this), assertCount, tier1, tier2, tier3, obj, disjunct, child)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define RelativeNameDeclare test_RelativeNameDeclare
#endif
TEST_EXPORT test_RelativeName _test_RelativeNameDeclare(void);
#define test_RelativeNameDeclare() _test_RelativeNameDeclare()
#define test_RelativeNameDeclare_auto(_id) test_RelativeName _id = test_RelativeNameDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define RelativeNameDeclareChild test_RelativeNameDeclareChild
#endif
TEST_EXPORT test_RelativeName _test_RelativeNameDeclareChild(corto_object _parent, corto_string _id);
#define test_RelativeNameDeclareChild(_parent, _id) _test_RelativeNameDeclareChild(_parent, _id)
#define test_RelativeNameDeclareChild_auto(_parent, _id) test_RelativeName _id = test_RelativeNameDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define RelativeNameDefine test_RelativeNameDefine
#endif
TEST_EXPORT corto_int16 _test_RelativeNameDefine(test_RelativeName _this, uint32_t assertCount, corto_object tier1, corto_object tier2, corto_object tier3, corto_object obj, corto_object disjunct, corto_object child);
#define test_RelativeNameDefine(_this, assertCount, tier1, tier2, tier3, obj, disjunct, child) _test_RelativeNameDefine(test_RelativeName(_this), assertCount, tier1, tier2, tier3, obj, disjunct, child)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define RelativeNameAssign test_RelativeNameAssign
#endif
TEST_EXPORT test_RelativeName _test_RelativeNameAssign(test_RelativeName _this, uint32_t assertCount, corto_object tier1, corto_object tier2, corto_object tier3, corto_object obj, corto_object disjunct, corto_object child);
#define test_RelativeName__optional_NotSet NULL
#define test_RelativeName__optional_Set(assertCount, tier1, tier2, tier3, obj, disjunct, child) test_RelativeNameAssign((test_RelativeName*)corto_ptr_new(test_RelativeName_o)), assertCount, tier1, tier2, tier3, obj, disjunct, child)
#define test_RelativeName__optional_SetCond(cond, assertCount, tier1, tier2, tier3, obj, disjunct, child) cond ? test_RelativeNameAssign((test_RelativeName*)corto_ptr_new(test_RelativeName_o), assertCount, tier1, tier2, tier3, obj, disjunct, child) : NULL
#define test_RelativeNameUnset(_this) _this ? corto_ptr_free(_this, test_RelativeName_o), 0 : 0; _this = NULL;
#define test_RelativeNameAssign(_this, assertCount, tier1, tier2, tier3, obj, disjunct, child) _test_RelativeNameAssign(_this, assertCount, tier1, tier2, tier3, obj, disjunct, child)
#define test_RelativeNameSet(_this, assertCount, tier1, tier2, tier3, obj, disjunct, child) _this = _this ? _this : (test_RelativeName*)corto_ptr_new(test_RelativeName_o); _test_RelativeNameAssign(_this, assertCount, tier1, tier2, tier3, obj, disjunct, child)

/* /test/Resolver */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ResolverCreate test_ResolverCreate
#endif
TEST_EXPORT test_Resolver _test_ResolverCreate(uint32_t assertCount);
#define test_ResolverCreate(assertCount) _test_ResolverCreate(assertCount)
#define test_ResolverCreate_auto(_id, assertCount) test_Resolver _id = test_ResolverCreate(assertCount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ResolverCreateChild test_ResolverCreateChild
#endif
TEST_EXPORT test_Resolver _test_ResolverCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount);
#define test_ResolverCreateChild(_parent, _id, assertCount) _test_ResolverCreateChild(_parent, _id, assertCount)
#define test_ResolverCreateChild_auto(_parent, _id, assertCount) test_Resolver _id = test_ResolverCreateChild(_parent, #_id, assertCount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ResolverUpdate test_ResolverUpdate
#endif
TEST_EXPORT corto_int16 _test_ResolverUpdate(test_Resolver _this, uint32_t assertCount);
#define test_ResolverUpdate(_this, assertCount) _test_ResolverUpdate(test_Resolver(_this), assertCount)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ResolverDeclare test_ResolverDeclare
#endif
TEST_EXPORT test_Resolver _test_ResolverDeclare(void);
#define test_ResolverDeclare() _test_ResolverDeclare()
#define test_ResolverDeclare_auto(_id) test_Resolver _id = test_ResolverDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ResolverDeclareChild test_ResolverDeclareChild
#endif
TEST_EXPORT test_Resolver _test_ResolverDeclareChild(corto_object _parent, corto_string _id);
#define test_ResolverDeclareChild(_parent, _id) _test_ResolverDeclareChild(_parent, _id)
#define test_ResolverDeclareChild_auto(_parent, _id) test_Resolver _id = test_ResolverDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ResolverDefine test_ResolverDefine
#endif
TEST_EXPORT corto_int16 _test_ResolverDefine(test_Resolver _this, uint32_t assertCount);
#define test_ResolverDefine(_this, assertCount) _test_ResolverDefine(test_Resolver(_this), assertCount)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ResolverAssign test_ResolverAssign
#endif
TEST_EXPORT test_Resolver _test_ResolverAssign(test_Resolver _this, uint32_t assertCount);
#define test_Resolver__optional_NotSet NULL
#define test_Resolver__optional_Set(assertCount) test_ResolverAssign((test_Resolver*)corto_ptr_new(test_Resolver_o)), assertCount)
#define test_Resolver__optional_SetCond(cond, assertCount) cond ? test_ResolverAssign((test_Resolver*)corto_ptr_new(test_Resolver_o), assertCount) : NULL
#define test_ResolverUnset(_this) _this ? corto_ptr_free(_this, test_Resolver_o), 0 : 0; _this = NULL;
#define test_ResolverAssign(_this, assertCount) _test_ResolverAssign(_this, assertCount)
#define test_ResolverSet(_this, assertCount) _this = _this ? _this : (test_Resolver*)corto_ptr_new(test_Resolver_o); _test_ResolverAssign(_this, assertCount)

/* /test/Security */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SecurityCreate test_SecurityCreate
#endif
TEST_EXPORT test_Security _test_SecurityCreate(uint32_t assertCount);
#define test_SecurityCreate(assertCount) _test_SecurityCreate(assertCount)
#define test_SecurityCreate_auto(_id, assertCount) test_Security _id = test_SecurityCreate(assertCount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SecurityCreateChild test_SecurityCreateChild
#endif
TEST_EXPORT test_Security _test_SecurityCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount);
#define test_SecurityCreateChild(_parent, _id, assertCount) _test_SecurityCreateChild(_parent, _id, assertCount)
#define test_SecurityCreateChild_auto(_parent, _id, assertCount) test_Security _id = test_SecurityCreateChild(_parent, #_id, assertCount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SecurityUpdate test_SecurityUpdate
#endif
TEST_EXPORT corto_int16 _test_SecurityUpdate(test_Security _this, uint32_t assertCount);
#define test_SecurityUpdate(_this, assertCount) _test_SecurityUpdate(test_Security(_this), assertCount)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SecurityDeclare test_SecurityDeclare
#endif
TEST_EXPORT test_Security _test_SecurityDeclare(void);
#define test_SecurityDeclare() _test_SecurityDeclare()
#define test_SecurityDeclare_auto(_id) test_Security _id = test_SecurityDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SecurityDeclareChild test_SecurityDeclareChild
#endif
TEST_EXPORT test_Security _test_SecurityDeclareChild(corto_object _parent, corto_string _id);
#define test_SecurityDeclareChild(_parent, _id) _test_SecurityDeclareChild(_parent, _id)
#define test_SecurityDeclareChild_auto(_parent, _id) test_Security _id = test_SecurityDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SecurityDefine test_SecurityDefine
#endif
TEST_EXPORT corto_int16 _test_SecurityDefine(test_Security _this, uint32_t assertCount);
#define test_SecurityDefine(_this, assertCount) _test_SecurityDefine(test_Security(_this), assertCount)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SecurityAssign test_SecurityAssign
#endif
TEST_EXPORT test_Security _test_SecurityAssign(test_Security _this, uint32_t assertCount);
#define test_Security__optional_NotSet NULL
#define test_Security__optional_Set(assertCount) test_SecurityAssign((test_Security*)corto_ptr_new(test_Security_o)), assertCount)
#define test_Security__optional_SetCond(cond, assertCount) cond ? test_SecurityAssign((test_Security*)corto_ptr_new(test_Security_o), assertCount) : NULL
#define test_SecurityUnset(_this) _this ? corto_ptr_free(_this, test_Security_o), 0 : 0; _this = NULL;
#define test_SecurityAssign(_this, assertCount) _test_SecurityAssign(_this, assertCount)
#define test_SecuritySet(_this, assertCount) _this = _this ? _this : (test_Security*)corto_ptr_new(test_Security_o); _test_SecurityAssign(_this, assertCount)

/* /test/Select */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SelectCreate test_SelectCreate
#endif
TEST_EXPORT test_Select _test_SelectCreate(uint32_t assertCount);
#define test_SelectCreate(assertCount) _test_SelectCreate(assertCount)
#define test_SelectCreate_auto(_id, assertCount) test_Select _id = test_SelectCreate(assertCount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SelectCreateChild test_SelectCreateChild
#endif
TEST_EXPORT test_Select _test_SelectCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount);
#define test_SelectCreateChild(_parent, _id, assertCount) _test_SelectCreateChild(_parent, _id, assertCount)
#define test_SelectCreateChild_auto(_parent, _id, assertCount) test_Select _id = test_SelectCreateChild(_parent, #_id, assertCount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SelectUpdate test_SelectUpdate
#endif
TEST_EXPORT corto_int16 _test_SelectUpdate(test_Select _this, uint32_t assertCount);
#define test_SelectUpdate(_this, assertCount) _test_SelectUpdate(test_Select(_this), assertCount)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SelectDeclare test_SelectDeclare
#endif
TEST_EXPORT test_Select _test_SelectDeclare(void);
#define test_SelectDeclare() _test_SelectDeclare()
#define test_SelectDeclare_auto(_id) test_Select _id = test_SelectDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SelectDeclareChild test_SelectDeclareChild
#endif
TEST_EXPORT test_Select _test_SelectDeclareChild(corto_object _parent, corto_string _id);
#define test_SelectDeclareChild(_parent, _id) _test_SelectDeclareChild(_parent, _id)
#define test_SelectDeclareChild_auto(_parent, _id) test_Select _id = test_SelectDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SelectDefine test_SelectDefine
#endif
TEST_EXPORT corto_int16 _test_SelectDefine(test_Select _this, uint32_t assertCount);
#define test_SelectDefine(_this, assertCount) _test_SelectDefine(test_Select(_this), assertCount)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SelectAssign test_SelectAssign
#endif
TEST_EXPORT test_Select _test_SelectAssign(test_Select _this, uint32_t assertCount);
#define test_Select__optional_NotSet NULL
#define test_Select__optional_Set(assertCount) test_SelectAssign((test_Select*)corto_ptr_new(test_Select_o)), assertCount)
#define test_Select__optional_SetCond(cond, assertCount) cond ? test_SelectAssign((test_Select*)corto_ptr_new(test_Select_o), assertCount) : NULL
#define test_SelectUnset(_this) _this ? corto_ptr_free(_this, test_Select_o), 0 : 0; _this = NULL;
#define test_SelectAssign(_this, assertCount) _test_SelectAssign(_this, assertCount)
#define test_SelectSet(_this, assertCount) _this = _this ? _this : (test_Select*)corto_ptr_new(test_Select_o); _test_SelectAssign(_this, assertCount)

/* /test/StringArray */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define StringArrayCreate test_StringArrayCreate
#endif
TEST_EXPORT corto_string* _test_StringArrayCreate(corto_uint32 length, corto_string* elements);
#define test_StringArrayCreate(length, elements) _test_StringArrayCreate(length, elements)
#define test_StringArrayCreate_auto(_id, length, elements) corto_string* _id = test_StringArrayCreate(length, elements); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define StringArrayCreateChild test_StringArrayCreateChild
#endif
TEST_EXPORT corto_string* _test_StringArrayCreateChild(corto_object _parent, corto_string _id, corto_uint32 length, corto_string* elements);
#define test_StringArrayCreateChild(_parent, _id, length, elements) _test_StringArrayCreateChild(_parent, _id, length, elements)
#define test_StringArrayCreateChild_auto(_parent, _id, length, elements) corto_string* _id = test_StringArrayCreateChild(_parent, #_id, length, elements); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define StringArrayUpdate test_StringArrayUpdate
#endif
TEST_EXPORT corto_int16 _test_StringArrayUpdate(test_StringArray _this, corto_uint32 length, corto_string* elements);
#define test_StringArrayUpdate(_this, length, elements) _test_StringArrayUpdate(test_StringArray(_this), length, elements)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define StringArrayDeclare test_StringArrayDeclare
#endif
TEST_EXPORT corto_string* _test_StringArrayDeclare(void);
#define test_StringArrayDeclare() _test_StringArrayDeclare()
#define test_StringArrayDeclare_auto(_id) corto_string* _id = test_StringArrayDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define StringArrayDeclareChild test_StringArrayDeclareChild
#endif
TEST_EXPORT corto_string* _test_StringArrayDeclareChild(corto_object _parent, corto_string _id);
#define test_StringArrayDeclareChild(_parent, _id) _test_StringArrayDeclareChild(_parent, _id)
#define test_StringArrayDeclareChild_auto(_parent, _id) corto_string* _id = test_StringArrayDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define StringArrayDefine test_StringArrayDefine
#endif
TEST_EXPORT corto_int16 _test_StringArrayDefine(test_StringArray _this, corto_uint32 length, corto_string* elements);
#define test_StringArrayDefine(_this, length, elements) _test_StringArrayDefine(test_StringArray(_this), length, elements)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define StringArrayAssign test_StringArrayAssign
#endif
TEST_EXPORT corto_string* _test_StringArrayAssign(test_StringArray _this, corto_uint32 length, corto_string* elements);
#define test_StringArray__optional_NotSet NULL
#define test_StringArray__optional_Set(length, elements) test_StringArrayAssign((test_StringArray*)corto_ptr_new(test_StringArray_o)), length, elements)
#define test_StringArray__optional_SetCond(cond, length, elements) cond ? test_StringArrayAssign((test_StringArray*)corto_ptr_new(test_StringArray_o), length, elements) : NULL
#define test_StringArrayUnset(_this) _this ? corto_ptr_free(_this, test_StringArray_o), 0 : 0; _this = NULL;
#define test_StringArrayAssign(_this, length, elements) _test_StringArrayAssign((corto_string*)_this, length, elements)
#define test_StringArraySet(_this, length, elements) _this = _this ? _this : (test_StringArray*)corto_ptr_new(test_StringArray_o); _test_StringArrayAssign((corto_string*)_this, length, elements)

/* /test/StringDeserializer */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define StringDeserializerCreate test_StringDeserializerCreate
#endif
TEST_EXPORT test_StringDeserializer _test_StringDeserializerCreate(uint32_t assertCount);
#define test_StringDeserializerCreate(assertCount) _test_StringDeserializerCreate(assertCount)
#define test_StringDeserializerCreate_auto(_id, assertCount) test_StringDeserializer _id = test_StringDeserializerCreate(assertCount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define StringDeserializerCreateChild test_StringDeserializerCreateChild
#endif
TEST_EXPORT test_StringDeserializer _test_StringDeserializerCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount);
#define test_StringDeserializerCreateChild(_parent, _id, assertCount) _test_StringDeserializerCreateChild(_parent, _id, assertCount)
#define test_StringDeserializerCreateChild_auto(_parent, _id, assertCount) test_StringDeserializer _id = test_StringDeserializerCreateChild(_parent, #_id, assertCount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define StringDeserializerUpdate test_StringDeserializerUpdate
#endif
TEST_EXPORT corto_int16 _test_StringDeserializerUpdate(test_StringDeserializer _this, uint32_t assertCount);
#define test_StringDeserializerUpdate(_this, assertCount) _test_StringDeserializerUpdate(test_StringDeserializer(_this), assertCount)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define StringDeserializerDeclare test_StringDeserializerDeclare
#endif
TEST_EXPORT test_StringDeserializer _test_StringDeserializerDeclare(void);
#define test_StringDeserializerDeclare() _test_StringDeserializerDeclare()
#define test_StringDeserializerDeclare_auto(_id) test_StringDeserializer _id = test_StringDeserializerDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define StringDeserializerDeclareChild test_StringDeserializerDeclareChild
#endif
TEST_EXPORT test_StringDeserializer _test_StringDeserializerDeclareChild(corto_object _parent, corto_string _id);
#define test_StringDeserializerDeclareChild(_parent, _id) _test_StringDeserializerDeclareChild(_parent, _id)
#define test_StringDeserializerDeclareChild_auto(_parent, _id) test_StringDeserializer _id = test_StringDeserializerDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define StringDeserializerDefine test_StringDeserializerDefine
#endif
TEST_EXPORT corto_int16 _test_StringDeserializerDefine(test_StringDeserializer _this, uint32_t assertCount);
#define test_StringDeserializerDefine(_this, assertCount) _test_StringDeserializerDefine(test_StringDeserializer(_this), assertCount)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define StringDeserializerAssign test_StringDeserializerAssign
#endif
TEST_EXPORT test_StringDeserializer _test_StringDeserializerAssign(test_StringDeserializer _this, uint32_t assertCount);
#define test_StringDeserializer__optional_NotSet NULL
#define test_StringDeserializer__optional_Set(assertCount) test_StringDeserializerAssign((test_StringDeserializer*)corto_ptr_new(test_StringDeserializer_o)), assertCount)
#define test_StringDeserializer__optional_SetCond(cond, assertCount) cond ? test_StringDeserializerAssign((test_StringDeserializer*)corto_ptr_new(test_StringDeserializer_o), assertCount) : NULL
#define test_StringDeserializerUnset(_this) _this ? corto_ptr_free(_this, test_StringDeserializer_o), 0 : 0; _this = NULL;
#define test_StringDeserializerAssign(_this, assertCount) _test_StringDeserializerAssign(_this, assertCount)
#define test_StringDeserializerSet(_this, assertCount) _this = _this ? _this : (test_StringDeserializer*)corto_ptr_new(test_StringDeserializer_o); _test_StringDeserializerAssign(_this, assertCount)

/* /test/StringList */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define StringListCreate test_StringListCreate
#endif
TEST_EXPORT test_StringList* _test_StringListCreate(corto_uint32 length, corto_string* elements);
#define test_StringListCreate(length, elements) _test_StringListCreate(length, elements)
#define test_StringListCreate_auto(_id, length, elements) test_StringList* _id = test_StringListCreate(length, elements); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define StringListCreateChild test_StringListCreateChild
#endif
TEST_EXPORT test_StringList* _test_StringListCreateChild(corto_object _parent, corto_string _id, corto_uint32 length, corto_string* elements);
#define test_StringListCreateChild(_parent, _id, length, elements) _test_StringListCreateChild(_parent, _id, length, elements)
#define test_StringListCreateChild_auto(_parent, _id, length, elements) test_StringList* _id = test_StringListCreateChild(_parent, #_id, length, elements); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define StringListUpdate test_StringListUpdate
#endif
TEST_EXPORT corto_int16 _test_StringListUpdate(test_StringList* _this, corto_uint32 length, corto_string* elements);
#define test_StringListUpdate(_this, length, elements) _test_StringListUpdate(test_StringList(_this), length, elements)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define StringListDeclare test_StringListDeclare
#endif
TEST_EXPORT test_StringList* _test_StringListDeclare(void);
#define test_StringListDeclare() _test_StringListDeclare()
#define test_StringListDeclare_auto(_id) test_StringList* _id = test_StringListDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define StringListDeclareChild test_StringListDeclareChild
#endif
TEST_EXPORT test_StringList* _test_StringListDeclareChild(corto_object _parent, corto_string _id);
#define test_StringListDeclareChild(_parent, _id) _test_StringListDeclareChild(_parent, _id)
#define test_StringListDeclareChild_auto(_parent, _id) test_StringList* _id = test_StringListDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define StringListDefine test_StringListDefine
#endif
TEST_EXPORT corto_int16 _test_StringListDefine(test_StringList* _this, corto_uint32 length, corto_string* elements);
#define test_StringListDefine(_this, length, elements) _test_StringListDefine(test_StringList(_this), length, elements)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define StringListAssign test_StringListAssign
#endif
TEST_EXPORT test_StringList* _test_StringListAssign(test_StringList* _this, corto_uint32 length, corto_string* elements);
#define test_StringList__optional_NotSet NULL
#define test_StringList__optional_Set(length, elements) test_StringListAssign((test_StringList*)corto_ptr_new(test_StringList_o)), length, elements)
#define test_StringList__optional_SetCond(cond, length, elements) cond ? test_StringListAssign((test_StringList*)corto_ptr_new(test_StringList_o), length, elements) : NULL
#define test_StringListUnset(_this) _this ? corto_ptr_free(_this, test_StringList_o), 0 : 0; _this = NULL;
#define test_StringListAssign(_this, length, elements) _test_StringListAssign(_this, length, elements)
#define test_StringListSet(_this, length, elements) _this = _this ? _this : (test_StringList*)corto_ptr_new(test_StringList_o); _test_StringListAssign(_this, length, elements)

/* /test/StringSequence */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define StringSequenceCreate test_StringSequenceCreate
#endif
TEST_EXPORT test_StringSequence* _test_StringSequenceCreate(corto_uint32 length, corto_string* elements);
#define test_StringSequenceCreate(length, elements) _test_StringSequenceCreate(length, elements)
#define test_StringSequenceCreate_auto(_id, length, elements) test_StringSequence* _id = test_StringSequenceCreate(length, elements); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define StringSequenceCreateChild test_StringSequenceCreateChild
#endif
TEST_EXPORT test_StringSequence* _test_StringSequenceCreateChild(corto_object _parent, corto_string _id, corto_uint32 length, corto_string* elements);
#define test_StringSequenceCreateChild(_parent, _id, length, elements) _test_StringSequenceCreateChild(_parent, _id, length, elements)
#define test_StringSequenceCreateChild_auto(_parent, _id, length, elements) test_StringSequence* _id = test_StringSequenceCreateChild(_parent, #_id, length, elements); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define StringSequenceUpdate test_StringSequenceUpdate
#endif
TEST_EXPORT corto_int16 _test_StringSequenceUpdate(test_StringSequence* _this, corto_uint32 length, corto_string* elements);
#define test_StringSequenceUpdate(_this, length, elements) _test_StringSequenceUpdate(test_StringSequence(_this), length, elements)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define StringSequenceDeclare test_StringSequenceDeclare
#endif
TEST_EXPORT test_StringSequence* _test_StringSequenceDeclare(void);
#define test_StringSequenceDeclare() _test_StringSequenceDeclare()
#define test_StringSequenceDeclare_auto(_id) test_StringSequence* _id = test_StringSequenceDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define StringSequenceDeclareChild test_StringSequenceDeclareChild
#endif
TEST_EXPORT test_StringSequence* _test_StringSequenceDeclareChild(corto_object _parent, corto_string _id);
#define test_StringSequenceDeclareChild(_parent, _id) _test_StringSequenceDeclareChild(_parent, _id)
#define test_StringSequenceDeclareChild_auto(_parent, _id) test_StringSequence* _id = test_StringSequenceDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define StringSequenceDefine test_StringSequenceDefine
#endif
TEST_EXPORT corto_int16 _test_StringSequenceDefine(test_StringSequence* _this, corto_uint32 length, corto_string* elements);
#define test_StringSequenceDefine(_this, length, elements) _test_StringSequenceDefine(test_StringSequence(_this), length, elements)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define StringSequenceAssign test_StringSequenceAssign
#endif
TEST_EXPORT test_StringSequence* _test_StringSequenceAssign(test_StringSequence* _this, corto_uint32 length, corto_string* elements);
#define test_StringSequence__optional_NotSet NULL
#define test_StringSequence__optional_Set(length, elements) test_StringSequenceAssign((test_StringSequence*)corto_ptr_new(test_StringSequence_o)), length, elements)
#define test_StringSequence__optional_SetCond(cond, length, elements) cond ? test_StringSequenceAssign((test_StringSequence*)corto_ptr_new(test_StringSequence_o), length, elements) : NULL
#define test_StringSequenceUnset(_this) _this ? corto_ptr_free(_this, test_StringSequence_o), 0 : 0; _this = NULL;
#define test_StringSequenceAssign(_this, length, elements) _test_StringSequenceAssign(_this, length, elements)
#define test_StringSequenceSet(_this, length, elements) _this = _this ? _this : (test_StringSequence*)corto_ptr_new(test_StringSequence_o); _test_StringSequenceAssign(_this, length, elements)

/* /test/StringSerializer */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define StringSerializerCreate test_StringSerializerCreate
#endif
TEST_EXPORT test_StringSerializer _test_StringSerializerCreate(uint32_t assertCount);
#define test_StringSerializerCreate(assertCount) _test_StringSerializerCreate(assertCount)
#define test_StringSerializerCreate_auto(_id, assertCount) test_StringSerializer _id = test_StringSerializerCreate(assertCount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define StringSerializerCreateChild test_StringSerializerCreateChild
#endif
TEST_EXPORT test_StringSerializer _test_StringSerializerCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount);
#define test_StringSerializerCreateChild(_parent, _id, assertCount) _test_StringSerializerCreateChild(_parent, _id, assertCount)
#define test_StringSerializerCreateChild_auto(_parent, _id, assertCount) test_StringSerializer _id = test_StringSerializerCreateChild(_parent, #_id, assertCount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define StringSerializerUpdate test_StringSerializerUpdate
#endif
TEST_EXPORT corto_int16 _test_StringSerializerUpdate(test_StringSerializer _this, uint32_t assertCount);
#define test_StringSerializerUpdate(_this, assertCount) _test_StringSerializerUpdate(test_StringSerializer(_this), assertCount)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define StringSerializerDeclare test_StringSerializerDeclare
#endif
TEST_EXPORT test_StringSerializer _test_StringSerializerDeclare(void);
#define test_StringSerializerDeclare() _test_StringSerializerDeclare()
#define test_StringSerializerDeclare_auto(_id) test_StringSerializer _id = test_StringSerializerDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define StringSerializerDeclareChild test_StringSerializerDeclareChild
#endif
TEST_EXPORT test_StringSerializer _test_StringSerializerDeclareChild(corto_object _parent, corto_string _id);
#define test_StringSerializerDeclareChild(_parent, _id) _test_StringSerializerDeclareChild(_parent, _id)
#define test_StringSerializerDeclareChild_auto(_parent, _id) test_StringSerializer _id = test_StringSerializerDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define StringSerializerDefine test_StringSerializerDefine
#endif
TEST_EXPORT corto_int16 _test_StringSerializerDefine(test_StringSerializer _this, uint32_t assertCount);
#define test_StringSerializerDefine(_this, assertCount) _test_StringSerializerDefine(test_StringSerializer(_this), assertCount)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define StringSerializerAssign test_StringSerializerAssign
#endif
TEST_EXPORT test_StringSerializer _test_StringSerializerAssign(test_StringSerializer _this, uint32_t assertCount);
#define test_StringSerializer__optional_NotSet NULL
#define test_StringSerializer__optional_Set(assertCount) test_StringSerializerAssign((test_StringSerializer*)corto_ptr_new(test_StringSerializer_o)), assertCount)
#define test_StringSerializer__optional_SetCond(cond, assertCount) cond ? test_StringSerializerAssign((test_StringSerializer*)corto_ptr_new(test_StringSerializer_o), assertCount) : NULL
#define test_StringSerializerUnset(_this) _this ? corto_ptr_free(_this, test_StringSerializer_o), 0 : 0; _this = NULL;
#define test_StringSerializerAssign(_this, assertCount) _test_StringSerializerAssign(_this, assertCount)
#define test_StringSerializerSet(_this, assertCount) _this = _this ? _this : (test_StringSerializer*)corto_ptr_new(test_StringSerializer_o); _test_StringSerializerAssign(_this, assertCount)

/* /test/struct_arrayInt */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_arrayIntCreate test_struct_arrayIntCreate
#endif
TEST_EXPORT test_struct_arrayInt* _test_struct_arrayIntCreate(corto_int32Array3 m);
#define test_struct_arrayIntCreate(m) _test_struct_arrayIntCreate(m)
#define test_struct_arrayIntCreate_auto(_id, m) test_struct_arrayInt* _id = test_struct_arrayIntCreate(m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_arrayIntCreateChild test_struct_arrayIntCreateChild
#endif
TEST_EXPORT test_struct_arrayInt* _test_struct_arrayIntCreateChild(corto_object _parent, corto_string _id, corto_int32Array3 m);
#define test_struct_arrayIntCreateChild(_parent, _id, m) _test_struct_arrayIntCreateChild(_parent, _id, m)
#define test_struct_arrayIntCreateChild_auto(_parent, _id, m) test_struct_arrayInt* _id = test_struct_arrayIntCreateChild(_parent, #_id, m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_arrayIntUpdate test_struct_arrayIntUpdate
#endif
TEST_EXPORT corto_int16 _test_struct_arrayIntUpdate(test_struct_arrayInt* _this, corto_int32Array3 m);
#define test_struct_arrayIntUpdate(_this, m) _test_struct_arrayIntUpdate(test_struct_arrayInt(_this), m)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_arrayIntDeclare test_struct_arrayIntDeclare
#endif
TEST_EXPORT test_struct_arrayInt* _test_struct_arrayIntDeclare(void);
#define test_struct_arrayIntDeclare() _test_struct_arrayIntDeclare()
#define test_struct_arrayIntDeclare_auto(_id) test_struct_arrayInt* _id = test_struct_arrayIntDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_arrayIntDeclareChild test_struct_arrayIntDeclareChild
#endif
TEST_EXPORT test_struct_arrayInt* _test_struct_arrayIntDeclareChild(corto_object _parent, corto_string _id);
#define test_struct_arrayIntDeclareChild(_parent, _id) _test_struct_arrayIntDeclareChild(_parent, _id)
#define test_struct_arrayIntDeclareChild_auto(_parent, _id) test_struct_arrayInt* _id = test_struct_arrayIntDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_arrayIntDefine test_struct_arrayIntDefine
#endif
TEST_EXPORT corto_int16 _test_struct_arrayIntDefine(test_struct_arrayInt* _this, corto_int32Array3 m);
#define test_struct_arrayIntDefine(_this, m) _test_struct_arrayIntDefine(test_struct_arrayInt(_this), m)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_arrayIntAssign test_struct_arrayIntAssign
#endif
TEST_EXPORT test_struct_arrayInt* _test_struct_arrayIntAssign(test_struct_arrayInt* _this, corto_int32Array3 m);
#define test_struct_arrayInt__optional_NotSet NULL
#define test_struct_arrayInt__optional_Set(m) test_struct_arrayIntAssign((test_struct_arrayInt*)corto_ptr_new(test_struct_arrayInt_o)), m)
#define test_struct_arrayInt__optional_SetCond(cond, m) cond ? test_struct_arrayIntAssign((test_struct_arrayInt*)corto_ptr_new(test_struct_arrayInt_o), m) : NULL
#define test_struct_arrayIntUnset(_this) _this ? corto_ptr_free(_this, test_struct_arrayInt_o), 0 : 0; _this = NULL;
#define test_struct_arrayIntAssign(_this, m) _test_struct_arrayIntAssign(_this, m)
#define test_struct_arrayIntSet(_this, m) _this = _this ? _this : (test_struct_arrayInt*)corto_ptr_new(test_struct_arrayInt_o); _test_struct_arrayIntAssign(_this, m)

/* /test/struct_arrayReference */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_arrayReferenceCreate test_struct_arrayReferenceCreate
#endif
TEST_EXPORT test_struct_arrayReference* _test_struct_arrayReferenceCreate(corto_objectArray3 m);
#define test_struct_arrayReferenceCreate(m) _test_struct_arrayReferenceCreate(m)
#define test_struct_arrayReferenceCreate_auto(_id, m) test_struct_arrayReference* _id = test_struct_arrayReferenceCreate(m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_arrayReferenceCreateChild test_struct_arrayReferenceCreateChild
#endif
TEST_EXPORT test_struct_arrayReference* _test_struct_arrayReferenceCreateChild(corto_object _parent, corto_string _id, corto_objectArray3 m);
#define test_struct_arrayReferenceCreateChild(_parent, _id, m) _test_struct_arrayReferenceCreateChild(_parent, _id, m)
#define test_struct_arrayReferenceCreateChild_auto(_parent, _id, m) test_struct_arrayReference* _id = test_struct_arrayReferenceCreateChild(_parent, #_id, m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_arrayReferenceUpdate test_struct_arrayReferenceUpdate
#endif
TEST_EXPORT corto_int16 _test_struct_arrayReferenceUpdate(test_struct_arrayReference* _this, corto_objectArray3 m);
#define test_struct_arrayReferenceUpdate(_this, m) _test_struct_arrayReferenceUpdate(test_struct_arrayReference(_this), m)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_arrayReferenceDeclare test_struct_arrayReferenceDeclare
#endif
TEST_EXPORT test_struct_arrayReference* _test_struct_arrayReferenceDeclare(void);
#define test_struct_arrayReferenceDeclare() _test_struct_arrayReferenceDeclare()
#define test_struct_arrayReferenceDeclare_auto(_id) test_struct_arrayReference* _id = test_struct_arrayReferenceDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_arrayReferenceDeclareChild test_struct_arrayReferenceDeclareChild
#endif
TEST_EXPORT test_struct_arrayReference* _test_struct_arrayReferenceDeclareChild(corto_object _parent, corto_string _id);
#define test_struct_arrayReferenceDeclareChild(_parent, _id) _test_struct_arrayReferenceDeclareChild(_parent, _id)
#define test_struct_arrayReferenceDeclareChild_auto(_parent, _id) test_struct_arrayReference* _id = test_struct_arrayReferenceDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_arrayReferenceDefine test_struct_arrayReferenceDefine
#endif
TEST_EXPORT corto_int16 _test_struct_arrayReferenceDefine(test_struct_arrayReference* _this, corto_objectArray3 m);
#define test_struct_arrayReferenceDefine(_this, m) _test_struct_arrayReferenceDefine(test_struct_arrayReference(_this), m)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_arrayReferenceAssign test_struct_arrayReferenceAssign
#endif
TEST_EXPORT test_struct_arrayReference* _test_struct_arrayReferenceAssign(test_struct_arrayReference* _this, corto_objectArray3 m);
#define test_struct_arrayReference__optional_NotSet NULL
#define test_struct_arrayReference__optional_Set(m) test_struct_arrayReferenceAssign((test_struct_arrayReference*)corto_ptr_new(test_struct_arrayReference_o)), m)
#define test_struct_arrayReference__optional_SetCond(cond, m) cond ? test_struct_arrayReferenceAssign((test_struct_arrayReference*)corto_ptr_new(test_struct_arrayReference_o), m) : NULL
#define test_struct_arrayReferenceUnset(_this) _this ? corto_ptr_free(_this, test_struct_arrayReference_o), 0 : 0; _this = NULL;
#define test_struct_arrayReferenceAssign(_this, m) _test_struct_arrayReferenceAssign(_this, m)
#define test_struct_arrayReferenceSet(_this, m) _this = _this ? _this : (test_struct_arrayReference*)corto_ptr_new(test_struct_arrayReference_o); _test_struct_arrayReferenceAssign(_this, m)

/* /test/struct_arrayString */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_arrayStringCreate test_struct_arrayStringCreate
#endif
TEST_EXPORT test_struct_arrayString* _test_struct_arrayStringCreate(corto_stringArray3 m);
#define test_struct_arrayStringCreate(m) _test_struct_arrayStringCreate(m)
#define test_struct_arrayStringCreate_auto(_id, m) test_struct_arrayString* _id = test_struct_arrayStringCreate(m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_arrayStringCreateChild test_struct_arrayStringCreateChild
#endif
TEST_EXPORT test_struct_arrayString* _test_struct_arrayStringCreateChild(corto_object _parent, corto_string _id, corto_stringArray3 m);
#define test_struct_arrayStringCreateChild(_parent, _id, m) _test_struct_arrayStringCreateChild(_parent, _id, m)
#define test_struct_arrayStringCreateChild_auto(_parent, _id, m) test_struct_arrayString* _id = test_struct_arrayStringCreateChild(_parent, #_id, m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_arrayStringUpdate test_struct_arrayStringUpdate
#endif
TEST_EXPORT corto_int16 _test_struct_arrayStringUpdate(test_struct_arrayString* _this, corto_stringArray3 m);
#define test_struct_arrayStringUpdate(_this, m) _test_struct_arrayStringUpdate(test_struct_arrayString(_this), m)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_arrayStringDeclare test_struct_arrayStringDeclare
#endif
TEST_EXPORT test_struct_arrayString* _test_struct_arrayStringDeclare(void);
#define test_struct_arrayStringDeclare() _test_struct_arrayStringDeclare()
#define test_struct_arrayStringDeclare_auto(_id) test_struct_arrayString* _id = test_struct_arrayStringDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_arrayStringDeclareChild test_struct_arrayStringDeclareChild
#endif
TEST_EXPORT test_struct_arrayString* _test_struct_arrayStringDeclareChild(corto_object _parent, corto_string _id);
#define test_struct_arrayStringDeclareChild(_parent, _id) _test_struct_arrayStringDeclareChild(_parent, _id)
#define test_struct_arrayStringDeclareChild_auto(_parent, _id) test_struct_arrayString* _id = test_struct_arrayStringDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_arrayStringDefine test_struct_arrayStringDefine
#endif
TEST_EXPORT corto_int16 _test_struct_arrayStringDefine(test_struct_arrayString* _this, corto_stringArray3 m);
#define test_struct_arrayStringDefine(_this, m) _test_struct_arrayStringDefine(test_struct_arrayString(_this), m)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_arrayStringAssign test_struct_arrayStringAssign
#endif
TEST_EXPORT test_struct_arrayString* _test_struct_arrayStringAssign(test_struct_arrayString* _this, corto_stringArray3 m);
#define test_struct_arrayString__optional_NotSet NULL
#define test_struct_arrayString__optional_Set(m) test_struct_arrayStringAssign((test_struct_arrayString*)corto_ptr_new(test_struct_arrayString_o)), m)
#define test_struct_arrayString__optional_SetCond(cond, m) cond ? test_struct_arrayStringAssign((test_struct_arrayString*)corto_ptr_new(test_struct_arrayString_o), m) : NULL
#define test_struct_arrayStringUnset(_this) _this ? corto_ptr_free(_this, test_struct_arrayString_o), 0 : 0; _this = NULL;
#define test_struct_arrayStringAssign(_this, m) _test_struct_arrayStringAssign(_this, m)
#define test_struct_arrayStringSet(_this, m) _this = _this ? _this : (test_struct_arrayString*)corto_ptr_new(test_struct_arrayString_o); _test_struct_arrayStringAssign(_this, m)

/* /test/struct_arrayStruct */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_arrayStructCreate test_struct_arrayStructCreate
#endif
TEST_EXPORT test_struct_arrayStruct* _test_struct_arrayStructCreate(test_PointArray3 m);
#define test_struct_arrayStructCreate(m) _test_struct_arrayStructCreate(m)
#define test_struct_arrayStructCreate_auto(_id, m) test_struct_arrayStruct* _id = test_struct_arrayStructCreate(m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_arrayStructCreateChild test_struct_arrayStructCreateChild
#endif
TEST_EXPORT test_struct_arrayStruct* _test_struct_arrayStructCreateChild(corto_object _parent, corto_string _id, test_PointArray3 m);
#define test_struct_arrayStructCreateChild(_parent, _id, m) _test_struct_arrayStructCreateChild(_parent, _id, m)
#define test_struct_arrayStructCreateChild_auto(_parent, _id, m) test_struct_arrayStruct* _id = test_struct_arrayStructCreateChild(_parent, #_id, m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_arrayStructUpdate test_struct_arrayStructUpdate
#endif
TEST_EXPORT corto_int16 _test_struct_arrayStructUpdate(test_struct_arrayStruct* _this, test_PointArray3 m);
#define test_struct_arrayStructUpdate(_this, m) _test_struct_arrayStructUpdate(test_struct_arrayStruct(_this), m)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_arrayStructDeclare test_struct_arrayStructDeclare
#endif
TEST_EXPORT test_struct_arrayStruct* _test_struct_arrayStructDeclare(void);
#define test_struct_arrayStructDeclare() _test_struct_arrayStructDeclare()
#define test_struct_arrayStructDeclare_auto(_id) test_struct_arrayStruct* _id = test_struct_arrayStructDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_arrayStructDeclareChild test_struct_arrayStructDeclareChild
#endif
TEST_EXPORT test_struct_arrayStruct* _test_struct_arrayStructDeclareChild(corto_object _parent, corto_string _id);
#define test_struct_arrayStructDeclareChild(_parent, _id) _test_struct_arrayStructDeclareChild(_parent, _id)
#define test_struct_arrayStructDeclareChild_auto(_parent, _id) test_struct_arrayStruct* _id = test_struct_arrayStructDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_arrayStructDefine test_struct_arrayStructDefine
#endif
TEST_EXPORT corto_int16 _test_struct_arrayStructDefine(test_struct_arrayStruct* _this, test_PointArray3 m);
#define test_struct_arrayStructDefine(_this, m) _test_struct_arrayStructDefine(test_struct_arrayStruct(_this), m)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_arrayStructAssign test_struct_arrayStructAssign
#endif
TEST_EXPORT test_struct_arrayStruct* _test_struct_arrayStructAssign(test_struct_arrayStruct* _this, test_PointArray3 m);
#define test_struct_arrayStruct__optional_NotSet NULL
#define test_struct_arrayStruct__optional_Set(m) test_struct_arrayStructAssign((test_struct_arrayStruct*)corto_ptr_new(test_struct_arrayStruct_o)), m)
#define test_struct_arrayStruct__optional_SetCond(cond, m) cond ? test_struct_arrayStructAssign((test_struct_arrayStruct*)corto_ptr_new(test_struct_arrayStruct_o), m) : NULL
#define test_struct_arrayStructUnset(_this) _this ? corto_ptr_free(_this, test_struct_arrayStruct_o), 0 : 0; _this = NULL;
#define test_struct_arrayStructAssign(_this, m) _test_struct_arrayStructAssign(_this, m)
#define test_struct_arrayStructSet(_this, m) _this = _this ? _this : (test_struct_arrayStruct*)corto_ptr_new(test_struct_arrayStruct_o); _test_struct_arrayStructAssign(_this, m)

/* /test/struct_base */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_baseCreate test_struct_baseCreate
#endif
TEST_EXPORT test_struct_base* _test_struct_baseCreate(int32_t x, int32_t y);
#define test_struct_baseCreate(x, y) _test_struct_baseCreate(x, y)
#define test_struct_baseCreate_auto(_id, x, y) test_struct_base* _id = test_struct_baseCreate(x, y); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_baseCreateChild test_struct_baseCreateChild
#endif
TEST_EXPORT test_struct_base* _test_struct_baseCreateChild(corto_object _parent, corto_string _id, int32_t x, int32_t y);
#define test_struct_baseCreateChild(_parent, _id, x, y) _test_struct_baseCreateChild(_parent, _id, x, y)
#define test_struct_baseCreateChild_auto(_parent, _id, x, y) test_struct_base* _id = test_struct_baseCreateChild(_parent, #_id, x, y); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_baseUpdate test_struct_baseUpdate
#endif
TEST_EXPORT corto_int16 _test_struct_baseUpdate(test_struct_base* _this, int32_t x, int32_t y);
#define test_struct_baseUpdate(_this, x, y) _test_struct_baseUpdate(test_struct_base(_this), x, y)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_baseDeclare test_struct_baseDeclare
#endif
TEST_EXPORT test_struct_base* _test_struct_baseDeclare(void);
#define test_struct_baseDeclare() _test_struct_baseDeclare()
#define test_struct_baseDeclare_auto(_id) test_struct_base* _id = test_struct_baseDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_baseDeclareChild test_struct_baseDeclareChild
#endif
TEST_EXPORT test_struct_base* _test_struct_baseDeclareChild(corto_object _parent, corto_string _id);
#define test_struct_baseDeclareChild(_parent, _id) _test_struct_baseDeclareChild(_parent, _id)
#define test_struct_baseDeclareChild_auto(_parent, _id) test_struct_base* _id = test_struct_baseDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_baseDefine test_struct_baseDefine
#endif
TEST_EXPORT corto_int16 _test_struct_baseDefine(test_struct_base* _this, int32_t x, int32_t y);
#define test_struct_baseDefine(_this, x, y) _test_struct_baseDefine(test_struct_base(_this), x, y)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_baseAssign test_struct_baseAssign
#endif
TEST_EXPORT test_struct_base* _test_struct_baseAssign(test_struct_base* _this, int32_t x, int32_t y);
#define test_struct_base__optional_NotSet NULL
#define test_struct_base__optional_Set(x, y) test_struct_baseAssign((test_struct_base*)corto_ptr_new(test_struct_base_o)), x, y)
#define test_struct_base__optional_SetCond(cond, x, y) cond ? test_struct_baseAssign((test_struct_base*)corto_ptr_new(test_struct_base_o), x, y) : NULL
#define test_struct_baseUnset(_this) _this ? corto_ptr_free(_this, test_struct_base_o), 0 : 0; _this = NULL;
#define test_struct_baseAssign(_this, x, y) _test_struct_baseAssign(_this, x, y)
#define test_struct_baseSet(_this, x, y) _this = _this ? _this : (test_struct_base*)corto_ptr_new(test_struct_base_o); _test_struct_baseAssign(_this, x, y)

/* /test/struct_inherit */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_inheritCreate test_struct_inheritCreate
#endif
TEST_EXPORT test_struct_inherit* _test_struct_inheritCreate(int32_t x, int32_t y, int32_t x_1, int32_t z);
#define test_struct_inheritCreate(x, y, x_1, z) _test_struct_inheritCreate(x, y, x_1, z)
#define test_struct_inheritCreate_auto(_id, x, y, x_1, z) test_struct_inherit* _id = test_struct_inheritCreate(x, y, x_1, z); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_inheritCreateChild test_struct_inheritCreateChild
#endif
TEST_EXPORT test_struct_inherit* _test_struct_inheritCreateChild(corto_object _parent, corto_string _id, int32_t x, int32_t y, int32_t x_1, int32_t z);
#define test_struct_inheritCreateChild(_parent, _id, x, y, x_1, z) _test_struct_inheritCreateChild(_parent, _id, x, y, x_1, z)
#define test_struct_inheritCreateChild_auto(_parent, _id, x, y, x_1, z) test_struct_inherit* _id = test_struct_inheritCreateChild(_parent, #_id, x, y, x_1, z); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_inheritUpdate test_struct_inheritUpdate
#endif
TEST_EXPORT corto_int16 _test_struct_inheritUpdate(test_struct_inherit* _this, int32_t x, int32_t y, int32_t x_1, int32_t z);
#define test_struct_inheritUpdate(_this, x, y, x_1, z) _test_struct_inheritUpdate(test_struct_inherit(_this), x, y, x_1, z)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_inheritDeclare test_struct_inheritDeclare
#endif
TEST_EXPORT test_struct_inherit* _test_struct_inheritDeclare(void);
#define test_struct_inheritDeclare() _test_struct_inheritDeclare()
#define test_struct_inheritDeclare_auto(_id) test_struct_inherit* _id = test_struct_inheritDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_inheritDeclareChild test_struct_inheritDeclareChild
#endif
TEST_EXPORT test_struct_inherit* _test_struct_inheritDeclareChild(corto_object _parent, corto_string _id);
#define test_struct_inheritDeclareChild(_parent, _id) _test_struct_inheritDeclareChild(_parent, _id)
#define test_struct_inheritDeclareChild_auto(_parent, _id) test_struct_inherit* _id = test_struct_inheritDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_inheritDefine test_struct_inheritDefine
#endif
TEST_EXPORT corto_int16 _test_struct_inheritDefine(test_struct_inherit* _this, int32_t x, int32_t y, int32_t x_1, int32_t z);
#define test_struct_inheritDefine(_this, x, y, x_1, z) _test_struct_inheritDefine(test_struct_inherit(_this), x, y, x_1, z)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_inheritAssign test_struct_inheritAssign
#endif
TEST_EXPORT test_struct_inherit* _test_struct_inheritAssign(test_struct_inherit* _this, int32_t x, int32_t y, int32_t x_1, int32_t z);
#define test_struct_inherit__optional_NotSet NULL
#define test_struct_inherit__optional_Set(x, y, x_1, z) test_struct_inheritAssign((test_struct_inherit*)corto_ptr_new(test_struct_inherit_o)), x, y, x_1, z)
#define test_struct_inherit__optional_SetCond(cond, x, y, x_1, z) cond ? test_struct_inheritAssign((test_struct_inherit*)corto_ptr_new(test_struct_inherit_o), x, y, x_1, z) : NULL
#define test_struct_inheritUnset(_this) _this ? corto_ptr_free(_this, test_struct_inherit_o), 0 : 0; _this = NULL;
#define test_struct_inheritAssign(_this, x, y, x_1, z) _test_struct_inheritAssign(_this, x, y, x_1, z)
#define test_struct_inheritSet(_this, x, y, x_1, z) _this = _this ? _this : (test_struct_inherit*)corto_ptr_new(test_struct_inherit_o); _test_struct_inheritAssign(_this, x, y, x_1, z)

/* /test/struct_listInt */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_listIntCreate test_struct_listIntCreate
#endif
TEST_EXPORT test_struct_listInt* _test_struct_listIntCreate(corto_int32List m);
#define test_struct_listIntCreate(m) _test_struct_listIntCreate(m)
#define test_struct_listIntCreate_auto(_id, m) test_struct_listInt* _id = test_struct_listIntCreate(m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_listIntCreateChild test_struct_listIntCreateChild
#endif
TEST_EXPORT test_struct_listInt* _test_struct_listIntCreateChild(corto_object _parent, corto_string _id, corto_int32List m);
#define test_struct_listIntCreateChild(_parent, _id, m) _test_struct_listIntCreateChild(_parent, _id, m)
#define test_struct_listIntCreateChild_auto(_parent, _id, m) test_struct_listInt* _id = test_struct_listIntCreateChild(_parent, #_id, m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_listIntUpdate test_struct_listIntUpdate
#endif
TEST_EXPORT corto_int16 _test_struct_listIntUpdate(test_struct_listInt* _this, corto_int32List m);
#define test_struct_listIntUpdate(_this, m) _test_struct_listIntUpdate(test_struct_listInt(_this), m)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_listIntDeclare test_struct_listIntDeclare
#endif
TEST_EXPORT test_struct_listInt* _test_struct_listIntDeclare(void);
#define test_struct_listIntDeclare() _test_struct_listIntDeclare()
#define test_struct_listIntDeclare_auto(_id) test_struct_listInt* _id = test_struct_listIntDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_listIntDeclareChild test_struct_listIntDeclareChild
#endif
TEST_EXPORT test_struct_listInt* _test_struct_listIntDeclareChild(corto_object _parent, corto_string _id);
#define test_struct_listIntDeclareChild(_parent, _id) _test_struct_listIntDeclareChild(_parent, _id)
#define test_struct_listIntDeclareChild_auto(_parent, _id) test_struct_listInt* _id = test_struct_listIntDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_listIntDefine test_struct_listIntDefine
#endif
TEST_EXPORT corto_int16 _test_struct_listIntDefine(test_struct_listInt* _this, corto_int32List m);
#define test_struct_listIntDefine(_this, m) _test_struct_listIntDefine(test_struct_listInt(_this), m)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_listIntAssign test_struct_listIntAssign
#endif
TEST_EXPORT test_struct_listInt* _test_struct_listIntAssign(test_struct_listInt* _this, corto_int32List m);
#define test_struct_listInt__optional_NotSet NULL
#define test_struct_listInt__optional_Set(m) test_struct_listIntAssign((test_struct_listInt*)corto_ptr_new(test_struct_listInt_o)), m)
#define test_struct_listInt__optional_SetCond(cond, m) cond ? test_struct_listIntAssign((test_struct_listInt*)corto_ptr_new(test_struct_listInt_o), m) : NULL
#define test_struct_listIntUnset(_this) _this ? corto_ptr_free(_this, test_struct_listInt_o), 0 : 0; _this = NULL;
#define test_struct_listIntAssign(_this, m) _test_struct_listIntAssign(_this, m)
#define test_struct_listIntSet(_this, m) _this = _this ? _this : (test_struct_listInt*)corto_ptr_new(test_struct_listInt_o); _test_struct_listIntAssign(_this, m)

/* /test/struct_listReference */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_listReferenceCreate test_struct_listReferenceCreate
#endif
TEST_EXPORT test_struct_listReference* _test_struct_listReferenceCreate(corto_objectList m);
#define test_struct_listReferenceCreate(m) _test_struct_listReferenceCreate(m)
#define test_struct_listReferenceCreate_auto(_id, m) test_struct_listReference* _id = test_struct_listReferenceCreate(m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_listReferenceCreateChild test_struct_listReferenceCreateChild
#endif
TEST_EXPORT test_struct_listReference* _test_struct_listReferenceCreateChild(corto_object _parent, corto_string _id, corto_objectList m);
#define test_struct_listReferenceCreateChild(_parent, _id, m) _test_struct_listReferenceCreateChild(_parent, _id, m)
#define test_struct_listReferenceCreateChild_auto(_parent, _id, m) test_struct_listReference* _id = test_struct_listReferenceCreateChild(_parent, #_id, m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_listReferenceUpdate test_struct_listReferenceUpdate
#endif
TEST_EXPORT corto_int16 _test_struct_listReferenceUpdate(test_struct_listReference* _this, corto_objectList m);
#define test_struct_listReferenceUpdate(_this, m) _test_struct_listReferenceUpdate(test_struct_listReference(_this), m)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_listReferenceDeclare test_struct_listReferenceDeclare
#endif
TEST_EXPORT test_struct_listReference* _test_struct_listReferenceDeclare(void);
#define test_struct_listReferenceDeclare() _test_struct_listReferenceDeclare()
#define test_struct_listReferenceDeclare_auto(_id) test_struct_listReference* _id = test_struct_listReferenceDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_listReferenceDeclareChild test_struct_listReferenceDeclareChild
#endif
TEST_EXPORT test_struct_listReference* _test_struct_listReferenceDeclareChild(corto_object _parent, corto_string _id);
#define test_struct_listReferenceDeclareChild(_parent, _id) _test_struct_listReferenceDeclareChild(_parent, _id)
#define test_struct_listReferenceDeclareChild_auto(_parent, _id) test_struct_listReference* _id = test_struct_listReferenceDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_listReferenceDefine test_struct_listReferenceDefine
#endif
TEST_EXPORT corto_int16 _test_struct_listReferenceDefine(test_struct_listReference* _this, corto_objectList m);
#define test_struct_listReferenceDefine(_this, m) _test_struct_listReferenceDefine(test_struct_listReference(_this), m)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_listReferenceAssign test_struct_listReferenceAssign
#endif
TEST_EXPORT test_struct_listReference* _test_struct_listReferenceAssign(test_struct_listReference* _this, corto_objectList m);
#define test_struct_listReference__optional_NotSet NULL
#define test_struct_listReference__optional_Set(m) test_struct_listReferenceAssign((test_struct_listReference*)corto_ptr_new(test_struct_listReference_o)), m)
#define test_struct_listReference__optional_SetCond(cond, m) cond ? test_struct_listReferenceAssign((test_struct_listReference*)corto_ptr_new(test_struct_listReference_o), m) : NULL
#define test_struct_listReferenceUnset(_this) _this ? corto_ptr_free(_this, test_struct_listReference_o), 0 : 0; _this = NULL;
#define test_struct_listReferenceAssign(_this, m) _test_struct_listReferenceAssign(_this, m)
#define test_struct_listReferenceSet(_this, m) _this = _this ? _this : (test_struct_listReference*)corto_ptr_new(test_struct_listReference_o); _test_struct_listReferenceAssign(_this, m)

/* /test/struct_listString */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_listStringCreate test_struct_listStringCreate
#endif
TEST_EXPORT test_struct_listString* _test_struct_listStringCreate(corto_stringList m);
#define test_struct_listStringCreate(m) _test_struct_listStringCreate(m)
#define test_struct_listStringCreate_auto(_id, m) test_struct_listString* _id = test_struct_listStringCreate(m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_listStringCreateChild test_struct_listStringCreateChild
#endif
TEST_EXPORT test_struct_listString* _test_struct_listStringCreateChild(corto_object _parent, corto_string _id, corto_stringList m);
#define test_struct_listStringCreateChild(_parent, _id, m) _test_struct_listStringCreateChild(_parent, _id, m)
#define test_struct_listStringCreateChild_auto(_parent, _id, m) test_struct_listString* _id = test_struct_listStringCreateChild(_parent, #_id, m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_listStringUpdate test_struct_listStringUpdate
#endif
TEST_EXPORT corto_int16 _test_struct_listStringUpdate(test_struct_listString* _this, corto_stringList m);
#define test_struct_listStringUpdate(_this, m) _test_struct_listStringUpdate(test_struct_listString(_this), m)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_listStringDeclare test_struct_listStringDeclare
#endif
TEST_EXPORT test_struct_listString* _test_struct_listStringDeclare(void);
#define test_struct_listStringDeclare() _test_struct_listStringDeclare()
#define test_struct_listStringDeclare_auto(_id) test_struct_listString* _id = test_struct_listStringDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_listStringDeclareChild test_struct_listStringDeclareChild
#endif
TEST_EXPORT test_struct_listString* _test_struct_listStringDeclareChild(corto_object _parent, corto_string _id);
#define test_struct_listStringDeclareChild(_parent, _id) _test_struct_listStringDeclareChild(_parent, _id)
#define test_struct_listStringDeclareChild_auto(_parent, _id) test_struct_listString* _id = test_struct_listStringDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_listStringDefine test_struct_listStringDefine
#endif
TEST_EXPORT corto_int16 _test_struct_listStringDefine(test_struct_listString* _this, corto_stringList m);
#define test_struct_listStringDefine(_this, m) _test_struct_listStringDefine(test_struct_listString(_this), m)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_listStringAssign test_struct_listStringAssign
#endif
TEST_EXPORT test_struct_listString* _test_struct_listStringAssign(test_struct_listString* _this, corto_stringList m);
#define test_struct_listString__optional_NotSet NULL
#define test_struct_listString__optional_Set(m) test_struct_listStringAssign((test_struct_listString*)corto_ptr_new(test_struct_listString_o)), m)
#define test_struct_listString__optional_SetCond(cond, m) cond ? test_struct_listStringAssign((test_struct_listString*)corto_ptr_new(test_struct_listString_o), m) : NULL
#define test_struct_listStringUnset(_this) _this ? corto_ptr_free(_this, test_struct_listString_o), 0 : 0; _this = NULL;
#define test_struct_listStringAssign(_this, m) _test_struct_listStringAssign(_this, m)
#define test_struct_listStringSet(_this, m) _this = _this ? _this : (test_struct_listString*)corto_ptr_new(test_struct_listString_o); _test_struct_listStringAssign(_this, m)

/* /test/struct_listStruct */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_listStructCreate test_struct_listStructCreate
#endif
TEST_EXPORT test_struct_listStruct* _test_struct_listStructCreate(test_PointList m);
#define test_struct_listStructCreate(m) _test_struct_listStructCreate(m)
#define test_struct_listStructCreate_auto(_id, m) test_struct_listStruct* _id = test_struct_listStructCreate(m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_listStructCreateChild test_struct_listStructCreateChild
#endif
TEST_EXPORT test_struct_listStruct* _test_struct_listStructCreateChild(corto_object _parent, corto_string _id, test_PointList m);
#define test_struct_listStructCreateChild(_parent, _id, m) _test_struct_listStructCreateChild(_parent, _id, m)
#define test_struct_listStructCreateChild_auto(_parent, _id, m) test_struct_listStruct* _id = test_struct_listStructCreateChild(_parent, #_id, m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_listStructUpdate test_struct_listStructUpdate
#endif
TEST_EXPORT corto_int16 _test_struct_listStructUpdate(test_struct_listStruct* _this, test_PointList m);
#define test_struct_listStructUpdate(_this, m) _test_struct_listStructUpdate(test_struct_listStruct(_this), m)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_listStructDeclare test_struct_listStructDeclare
#endif
TEST_EXPORT test_struct_listStruct* _test_struct_listStructDeclare(void);
#define test_struct_listStructDeclare() _test_struct_listStructDeclare()
#define test_struct_listStructDeclare_auto(_id) test_struct_listStruct* _id = test_struct_listStructDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_listStructDeclareChild test_struct_listStructDeclareChild
#endif
TEST_EXPORT test_struct_listStruct* _test_struct_listStructDeclareChild(corto_object _parent, corto_string _id);
#define test_struct_listStructDeclareChild(_parent, _id) _test_struct_listStructDeclareChild(_parent, _id)
#define test_struct_listStructDeclareChild_auto(_parent, _id) test_struct_listStruct* _id = test_struct_listStructDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_listStructDefine test_struct_listStructDefine
#endif
TEST_EXPORT corto_int16 _test_struct_listStructDefine(test_struct_listStruct* _this, test_PointList m);
#define test_struct_listStructDefine(_this, m) _test_struct_listStructDefine(test_struct_listStruct(_this), m)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_listStructAssign test_struct_listStructAssign
#endif
TEST_EXPORT test_struct_listStruct* _test_struct_listStructAssign(test_struct_listStruct* _this, test_PointList m);
#define test_struct_listStruct__optional_NotSet NULL
#define test_struct_listStruct__optional_Set(m) test_struct_listStructAssign((test_struct_listStruct*)corto_ptr_new(test_struct_listStruct_o)), m)
#define test_struct_listStruct__optional_SetCond(cond, m) cond ? test_struct_listStructAssign((test_struct_listStruct*)corto_ptr_new(test_struct_listStruct_o), m) : NULL
#define test_struct_listStructUnset(_this) _this ? corto_ptr_free(_this, test_struct_listStruct_o), 0 : 0; _this = NULL;
#define test_struct_listStructAssign(_this, m) _test_struct_listStructAssign(_this, m)
#define test_struct_listStructSet(_this, m) _this = _this ? _this : (test_struct_listStruct*)corto_ptr_new(test_struct_listStruct_o); _test_struct_listStructAssign(_this, m)

/* /test/struct_observableArray */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_observableArrayCreate test_struct_observableArrayCreate
#endif
TEST_EXPORT test_struct_observableArray* _test_struct_observableArrayCreate(test_IntArray m);
#define test_struct_observableArrayCreate(m) _test_struct_observableArrayCreate(m)
#define test_struct_observableArrayCreate_auto(_id, m) test_struct_observableArray* _id = test_struct_observableArrayCreate(m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_observableArrayCreateChild test_struct_observableArrayCreateChild
#endif
TEST_EXPORT test_struct_observableArray* _test_struct_observableArrayCreateChild(corto_object _parent, corto_string _id, test_IntArray m);
#define test_struct_observableArrayCreateChild(_parent, _id, m) _test_struct_observableArrayCreateChild(_parent, _id, m)
#define test_struct_observableArrayCreateChild_auto(_parent, _id, m) test_struct_observableArray* _id = test_struct_observableArrayCreateChild(_parent, #_id, m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_observableArrayUpdate test_struct_observableArrayUpdate
#endif
TEST_EXPORT corto_int16 _test_struct_observableArrayUpdate(test_struct_observableArray* _this, test_IntArray m);
#define test_struct_observableArrayUpdate(_this, m) _test_struct_observableArrayUpdate(test_struct_observableArray(_this), m)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_observableArrayDeclare test_struct_observableArrayDeclare
#endif
TEST_EXPORT test_struct_observableArray* _test_struct_observableArrayDeclare(void);
#define test_struct_observableArrayDeclare() _test_struct_observableArrayDeclare()
#define test_struct_observableArrayDeclare_auto(_id) test_struct_observableArray* _id = test_struct_observableArrayDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_observableArrayDeclareChild test_struct_observableArrayDeclareChild
#endif
TEST_EXPORT test_struct_observableArray* _test_struct_observableArrayDeclareChild(corto_object _parent, corto_string _id);
#define test_struct_observableArrayDeclareChild(_parent, _id) _test_struct_observableArrayDeclareChild(_parent, _id)
#define test_struct_observableArrayDeclareChild_auto(_parent, _id) test_struct_observableArray* _id = test_struct_observableArrayDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_observableArrayDefine test_struct_observableArrayDefine
#endif
TEST_EXPORT corto_int16 _test_struct_observableArrayDefine(test_struct_observableArray* _this, test_IntArray m);
#define test_struct_observableArrayDefine(_this, m) _test_struct_observableArrayDefine(test_struct_observableArray(_this), m)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_observableArrayAssign test_struct_observableArrayAssign
#endif
TEST_EXPORT test_struct_observableArray* _test_struct_observableArrayAssign(test_struct_observableArray* _this, test_IntArray m);
#define test_struct_observableArray__optional_NotSet NULL
#define test_struct_observableArray__optional_Set(m) test_struct_observableArrayAssign((test_struct_observableArray*)corto_ptr_new(test_struct_observableArray_o)), m)
#define test_struct_observableArray__optional_SetCond(cond, m) cond ? test_struct_observableArrayAssign((test_struct_observableArray*)corto_ptr_new(test_struct_observableArray_o), m) : NULL
#define test_struct_observableArrayUnset(_this) _this ? corto_ptr_free(_this, test_struct_observableArray_o), 0 : 0; _this = NULL;
#define test_struct_observableArrayAssign(_this, m) _test_struct_observableArrayAssign(_this, m)
#define test_struct_observableArraySet(_this, m) _this = _this ? _this : (test_struct_observableArray*)corto_ptr_new(test_struct_observableArray_o); _test_struct_observableArrayAssign(_this, m)

/* /test/struct_observableInt */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_observableIntCreate test_struct_observableIntCreate
#endif
TEST_EXPORT test_struct_observableInt* _test_struct_observableIntCreate(int32_t m);
#define test_struct_observableIntCreate(m) _test_struct_observableIntCreate(m)
#define test_struct_observableIntCreate_auto(_id, m) test_struct_observableInt* _id = test_struct_observableIntCreate(m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_observableIntCreateChild test_struct_observableIntCreateChild
#endif
TEST_EXPORT test_struct_observableInt* _test_struct_observableIntCreateChild(corto_object _parent, corto_string _id, int32_t m);
#define test_struct_observableIntCreateChild(_parent, _id, m) _test_struct_observableIntCreateChild(_parent, _id, m)
#define test_struct_observableIntCreateChild_auto(_parent, _id, m) test_struct_observableInt* _id = test_struct_observableIntCreateChild(_parent, #_id, m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_observableIntUpdate test_struct_observableIntUpdate
#endif
TEST_EXPORT corto_int16 _test_struct_observableIntUpdate(test_struct_observableInt* _this, int32_t m);
#define test_struct_observableIntUpdate(_this, m) _test_struct_observableIntUpdate(test_struct_observableInt(_this), m)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_observableIntDeclare test_struct_observableIntDeclare
#endif
TEST_EXPORT test_struct_observableInt* _test_struct_observableIntDeclare(void);
#define test_struct_observableIntDeclare() _test_struct_observableIntDeclare()
#define test_struct_observableIntDeclare_auto(_id) test_struct_observableInt* _id = test_struct_observableIntDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_observableIntDeclareChild test_struct_observableIntDeclareChild
#endif
TEST_EXPORT test_struct_observableInt* _test_struct_observableIntDeclareChild(corto_object _parent, corto_string _id);
#define test_struct_observableIntDeclareChild(_parent, _id) _test_struct_observableIntDeclareChild(_parent, _id)
#define test_struct_observableIntDeclareChild_auto(_parent, _id) test_struct_observableInt* _id = test_struct_observableIntDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_observableIntDefine test_struct_observableIntDefine
#endif
TEST_EXPORT corto_int16 _test_struct_observableIntDefine(test_struct_observableInt* _this, int32_t m);
#define test_struct_observableIntDefine(_this, m) _test_struct_observableIntDefine(test_struct_observableInt(_this), m)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_observableIntAssign test_struct_observableIntAssign
#endif
TEST_EXPORT test_struct_observableInt* _test_struct_observableIntAssign(test_struct_observableInt* _this, int32_t m);
#define test_struct_observableInt__optional_NotSet NULL
#define test_struct_observableInt__optional_Set(m) test_struct_observableIntAssign((test_struct_observableInt*)corto_ptr_new(test_struct_observableInt_o)), m)
#define test_struct_observableInt__optional_SetCond(cond, m) cond ? test_struct_observableIntAssign((test_struct_observableInt*)corto_ptr_new(test_struct_observableInt_o), m) : NULL
#define test_struct_observableIntUnset(_this) _this ? corto_ptr_free(_this, test_struct_observableInt_o), 0 : 0; _this = NULL;
#define test_struct_observableIntAssign(_this, m) _test_struct_observableIntAssign(_this, m)
#define test_struct_observableIntSet(_this, m) _this = _this ? _this : (test_struct_observableInt*)corto_ptr_new(test_struct_observableInt_o); _test_struct_observableIntAssign(_this, m)

/* /test/struct_observableList */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_observableListCreate test_struct_observableListCreate
#endif
TEST_EXPORT test_struct_observableList* _test_struct_observableListCreate(test_IntList m);
#define test_struct_observableListCreate(m) _test_struct_observableListCreate(m)
#define test_struct_observableListCreate_auto(_id, m) test_struct_observableList* _id = test_struct_observableListCreate(m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_observableListCreateChild test_struct_observableListCreateChild
#endif
TEST_EXPORT test_struct_observableList* _test_struct_observableListCreateChild(corto_object _parent, corto_string _id, test_IntList m);
#define test_struct_observableListCreateChild(_parent, _id, m) _test_struct_observableListCreateChild(_parent, _id, m)
#define test_struct_observableListCreateChild_auto(_parent, _id, m) test_struct_observableList* _id = test_struct_observableListCreateChild(_parent, #_id, m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_observableListUpdate test_struct_observableListUpdate
#endif
TEST_EXPORT corto_int16 _test_struct_observableListUpdate(test_struct_observableList* _this, test_IntList m);
#define test_struct_observableListUpdate(_this, m) _test_struct_observableListUpdate(test_struct_observableList(_this), m)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_observableListDeclare test_struct_observableListDeclare
#endif
TEST_EXPORT test_struct_observableList* _test_struct_observableListDeclare(void);
#define test_struct_observableListDeclare() _test_struct_observableListDeclare()
#define test_struct_observableListDeclare_auto(_id) test_struct_observableList* _id = test_struct_observableListDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_observableListDeclareChild test_struct_observableListDeclareChild
#endif
TEST_EXPORT test_struct_observableList* _test_struct_observableListDeclareChild(corto_object _parent, corto_string _id);
#define test_struct_observableListDeclareChild(_parent, _id) _test_struct_observableListDeclareChild(_parent, _id)
#define test_struct_observableListDeclareChild_auto(_parent, _id) test_struct_observableList* _id = test_struct_observableListDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_observableListDefine test_struct_observableListDefine
#endif
TEST_EXPORT corto_int16 _test_struct_observableListDefine(test_struct_observableList* _this, test_IntList m);
#define test_struct_observableListDefine(_this, m) _test_struct_observableListDefine(test_struct_observableList(_this), m)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_observableListAssign test_struct_observableListAssign
#endif
TEST_EXPORT test_struct_observableList* _test_struct_observableListAssign(test_struct_observableList* _this, test_IntList m);
#define test_struct_observableList__optional_NotSet NULL
#define test_struct_observableList__optional_Set(m) test_struct_observableListAssign((test_struct_observableList*)corto_ptr_new(test_struct_observableList_o)), m)
#define test_struct_observableList__optional_SetCond(cond, m) cond ? test_struct_observableListAssign((test_struct_observableList*)corto_ptr_new(test_struct_observableList_o), m) : NULL
#define test_struct_observableListUnset(_this) _this ? corto_ptr_free(_this, test_struct_observableList_o), 0 : 0; _this = NULL;
#define test_struct_observableListAssign(_this, m) _test_struct_observableListAssign(_this, m)
#define test_struct_observableListSet(_this, m) _this = _this ? _this : (test_struct_observableList*)corto_ptr_new(test_struct_observableList_o); _test_struct_observableListAssign(_this, m)

/* /test/struct_observableReference */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_observableReferenceCreate test_struct_observableReferenceCreate
#endif
TEST_EXPORT test_struct_observableReference* _test_struct_observableReferenceCreate(corto_object m);
#define test_struct_observableReferenceCreate(m) _test_struct_observableReferenceCreate(m)
#define test_struct_observableReferenceCreate_auto(_id, m) test_struct_observableReference* _id = test_struct_observableReferenceCreate(m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_observableReferenceCreateChild test_struct_observableReferenceCreateChild
#endif
TEST_EXPORT test_struct_observableReference* _test_struct_observableReferenceCreateChild(corto_object _parent, corto_string _id, corto_object m);
#define test_struct_observableReferenceCreateChild(_parent, _id, m) _test_struct_observableReferenceCreateChild(_parent, _id, m)
#define test_struct_observableReferenceCreateChild_auto(_parent, _id, m) test_struct_observableReference* _id = test_struct_observableReferenceCreateChild(_parent, #_id, m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_observableReferenceUpdate test_struct_observableReferenceUpdate
#endif
TEST_EXPORT corto_int16 _test_struct_observableReferenceUpdate(test_struct_observableReference* _this, corto_object m);
#define test_struct_observableReferenceUpdate(_this, m) _test_struct_observableReferenceUpdate(test_struct_observableReference(_this), m)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_observableReferenceDeclare test_struct_observableReferenceDeclare
#endif
TEST_EXPORT test_struct_observableReference* _test_struct_observableReferenceDeclare(void);
#define test_struct_observableReferenceDeclare() _test_struct_observableReferenceDeclare()
#define test_struct_observableReferenceDeclare_auto(_id) test_struct_observableReference* _id = test_struct_observableReferenceDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_observableReferenceDeclareChild test_struct_observableReferenceDeclareChild
#endif
TEST_EXPORT test_struct_observableReference* _test_struct_observableReferenceDeclareChild(corto_object _parent, corto_string _id);
#define test_struct_observableReferenceDeclareChild(_parent, _id) _test_struct_observableReferenceDeclareChild(_parent, _id)
#define test_struct_observableReferenceDeclareChild_auto(_parent, _id) test_struct_observableReference* _id = test_struct_observableReferenceDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_observableReferenceDefine test_struct_observableReferenceDefine
#endif
TEST_EXPORT corto_int16 _test_struct_observableReferenceDefine(test_struct_observableReference* _this, corto_object m);
#define test_struct_observableReferenceDefine(_this, m) _test_struct_observableReferenceDefine(test_struct_observableReference(_this), m)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_observableReferenceAssign test_struct_observableReferenceAssign
#endif
TEST_EXPORT test_struct_observableReference* _test_struct_observableReferenceAssign(test_struct_observableReference* _this, corto_object m);
#define test_struct_observableReference__optional_NotSet NULL
#define test_struct_observableReference__optional_Set(m) test_struct_observableReferenceAssign((test_struct_observableReference*)corto_ptr_new(test_struct_observableReference_o)), m)
#define test_struct_observableReference__optional_SetCond(cond, m) cond ? test_struct_observableReferenceAssign((test_struct_observableReference*)corto_ptr_new(test_struct_observableReference_o), m) : NULL
#define test_struct_observableReferenceUnset(_this) _this ? corto_ptr_free(_this, test_struct_observableReference_o), 0 : 0; _this = NULL;
#define test_struct_observableReferenceAssign(_this, m) _test_struct_observableReferenceAssign(_this, m)
#define test_struct_observableReferenceSet(_this, m) _this = _this ? _this : (test_struct_observableReference*)corto_ptr_new(test_struct_observableReference_o); _test_struct_observableReferenceAssign(_this, m)

/* /test/struct_observableSequence */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_observableSequenceCreate test_struct_observableSequenceCreate
#endif
TEST_EXPORT test_struct_observableSequence* _test_struct_observableSequenceCreate(test_IntSequence m);
#define test_struct_observableSequenceCreate(m) _test_struct_observableSequenceCreate(m)
#define test_struct_observableSequenceCreate_auto(_id, m) test_struct_observableSequence* _id = test_struct_observableSequenceCreate(m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_observableSequenceCreateChild test_struct_observableSequenceCreateChild
#endif
TEST_EXPORT test_struct_observableSequence* _test_struct_observableSequenceCreateChild(corto_object _parent, corto_string _id, test_IntSequence m);
#define test_struct_observableSequenceCreateChild(_parent, _id, m) _test_struct_observableSequenceCreateChild(_parent, _id, m)
#define test_struct_observableSequenceCreateChild_auto(_parent, _id, m) test_struct_observableSequence* _id = test_struct_observableSequenceCreateChild(_parent, #_id, m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_observableSequenceUpdate test_struct_observableSequenceUpdate
#endif
TEST_EXPORT corto_int16 _test_struct_observableSequenceUpdate(test_struct_observableSequence* _this, test_IntSequence m);
#define test_struct_observableSequenceUpdate(_this, m) _test_struct_observableSequenceUpdate(test_struct_observableSequence(_this), m)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_observableSequenceDeclare test_struct_observableSequenceDeclare
#endif
TEST_EXPORT test_struct_observableSequence* _test_struct_observableSequenceDeclare(void);
#define test_struct_observableSequenceDeclare() _test_struct_observableSequenceDeclare()
#define test_struct_observableSequenceDeclare_auto(_id) test_struct_observableSequence* _id = test_struct_observableSequenceDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_observableSequenceDeclareChild test_struct_observableSequenceDeclareChild
#endif
TEST_EXPORT test_struct_observableSequence* _test_struct_observableSequenceDeclareChild(corto_object _parent, corto_string _id);
#define test_struct_observableSequenceDeclareChild(_parent, _id) _test_struct_observableSequenceDeclareChild(_parent, _id)
#define test_struct_observableSequenceDeclareChild_auto(_parent, _id) test_struct_observableSequence* _id = test_struct_observableSequenceDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_observableSequenceDefine test_struct_observableSequenceDefine
#endif
TEST_EXPORT corto_int16 _test_struct_observableSequenceDefine(test_struct_observableSequence* _this, test_IntSequence m);
#define test_struct_observableSequenceDefine(_this, m) _test_struct_observableSequenceDefine(test_struct_observableSequence(_this), m)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_observableSequenceAssign test_struct_observableSequenceAssign
#endif
TEST_EXPORT test_struct_observableSequence* _test_struct_observableSequenceAssign(test_struct_observableSequence* _this, test_IntSequence m);
#define test_struct_observableSequence__optional_NotSet NULL
#define test_struct_observableSequence__optional_Set(m) test_struct_observableSequenceAssign((test_struct_observableSequence*)corto_ptr_new(test_struct_observableSequence_o)), m)
#define test_struct_observableSequence__optional_SetCond(cond, m) cond ? test_struct_observableSequenceAssign((test_struct_observableSequence*)corto_ptr_new(test_struct_observableSequence_o), m) : NULL
#define test_struct_observableSequenceUnset(_this) _this ? corto_ptr_free(_this, test_struct_observableSequence_o), 0 : 0; _this = NULL;
#define test_struct_observableSequenceAssign(_this, m) _test_struct_observableSequenceAssign(_this, m)
#define test_struct_observableSequenceSet(_this, m) _this = _this ? _this : (test_struct_observableSequence*)corto_ptr_new(test_struct_observableSequence_o); _test_struct_observableSequenceAssign(_this, m)

/* /test/struct_observableString */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_observableStringCreate test_struct_observableStringCreate
#endif
TEST_EXPORT test_struct_observableString* _test_struct_observableStringCreate(corto_string m);
#define test_struct_observableStringCreate(m) _test_struct_observableStringCreate(m)
#define test_struct_observableStringCreate_auto(_id, m) test_struct_observableString* _id = test_struct_observableStringCreate(m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_observableStringCreateChild test_struct_observableStringCreateChild
#endif
TEST_EXPORT test_struct_observableString* _test_struct_observableStringCreateChild(corto_object _parent, corto_string _id, corto_string m);
#define test_struct_observableStringCreateChild(_parent, _id, m) _test_struct_observableStringCreateChild(_parent, _id, m)
#define test_struct_observableStringCreateChild_auto(_parent, _id, m) test_struct_observableString* _id = test_struct_observableStringCreateChild(_parent, #_id, m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_observableStringUpdate test_struct_observableStringUpdate
#endif
TEST_EXPORT corto_int16 _test_struct_observableStringUpdate(test_struct_observableString* _this, corto_string m);
#define test_struct_observableStringUpdate(_this, m) _test_struct_observableStringUpdate(test_struct_observableString(_this), m)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_observableStringDeclare test_struct_observableStringDeclare
#endif
TEST_EXPORT test_struct_observableString* _test_struct_observableStringDeclare(void);
#define test_struct_observableStringDeclare() _test_struct_observableStringDeclare()
#define test_struct_observableStringDeclare_auto(_id) test_struct_observableString* _id = test_struct_observableStringDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_observableStringDeclareChild test_struct_observableStringDeclareChild
#endif
TEST_EXPORT test_struct_observableString* _test_struct_observableStringDeclareChild(corto_object _parent, corto_string _id);
#define test_struct_observableStringDeclareChild(_parent, _id) _test_struct_observableStringDeclareChild(_parent, _id)
#define test_struct_observableStringDeclareChild_auto(_parent, _id) test_struct_observableString* _id = test_struct_observableStringDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_observableStringDefine test_struct_observableStringDefine
#endif
TEST_EXPORT corto_int16 _test_struct_observableStringDefine(test_struct_observableString* _this, corto_string m);
#define test_struct_observableStringDefine(_this, m) _test_struct_observableStringDefine(test_struct_observableString(_this), m)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_observableStringAssign test_struct_observableStringAssign
#endif
TEST_EXPORT test_struct_observableString* _test_struct_observableStringAssign(test_struct_observableString* _this, corto_string m);
#define test_struct_observableString__optional_NotSet NULL
#define test_struct_observableString__optional_Set(m) test_struct_observableStringAssign((test_struct_observableString*)corto_ptr_new(test_struct_observableString_o)), m)
#define test_struct_observableString__optional_SetCond(cond, m) cond ? test_struct_observableStringAssign((test_struct_observableString*)corto_ptr_new(test_struct_observableString_o), m) : NULL
#define test_struct_observableStringUnset(_this) _this ? corto_ptr_free(_this, test_struct_observableString_o), 0 : 0; _this = NULL;
#define test_struct_observableStringAssign(_this, m) _test_struct_observableStringAssign(_this, m)
#define test_struct_observableStringSet(_this, m) _this = _this ? _this : (test_struct_observableString*)corto_ptr_new(test_struct_observableString_o); _test_struct_observableStringAssign(_this, m)

/* /test/struct_observableStruct */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_observableStructCreate test_struct_observableStructCreate
#endif
TEST_EXPORT test_struct_observableStruct* _test_struct_observableStructCreate(test_Point* m);
#define test_struct_observableStructCreate(m) _test_struct_observableStructCreate(m)
#define test_struct_observableStructCreate_auto(_id, m) test_struct_observableStruct* _id = test_struct_observableStructCreate(m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_observableStructCreateChild test_struct_observableStructCreateChild
#endif
TEST_EXPORT test_struct_observableStruct* _test_struct_observableStructCreateChild(corto_object _parent, corto_string _id, test_Point* m);
#define test_struct_observableStructCreateChild(_parent, _id, m) _test_struct_observableStructCreateChild(_parent, _id, m)
#define test_struct_observableStructCreateChild_auto(_parent, _id, m) test_struct_observableStruct* _id = test_struct_observableStructCreateChild(_parent, #_id, m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_observableStructUpdate test_struct_observableStructUpdate
#endif
TEST_EXPORT corto_int16 _test_struct_observableStructUpdate(test_struct_observableStruct* _this, test_Point* m);
#define test_struct_observableStructUpdate(_this, m) _test_struct_observableStructUpdate(test_struct_observableStruct(_this), m)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_observableStructDeclare test_struct_observableStructDeclare
#endif
TEST_EXPORT test_struct_observableStruct* _test_struct_observableStructDeclare(void);
#define test_struct_observableStructDeclare() _test_struct_observableStructDeclare()
#define test_struct_observableStructDeclare_auto(_id) test_struct_observableStruct* _id = test_struct_observableStructDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_observableStructDeclareChild test_struct_observableStructDeclareChild
#endif
TEST_EXPORT test_struct_observableStruct* _test_struct_observableStructDeclareChild(corto_object _parent, corto_string _id);
#define test_struct_observableStructDeclareChild(_parent, _id) _test_struct_observableStructDeclareChild(_parent, _id)
#define test_struct_observableStructDeclareChild_auto(_parent, _id) test_struct_observableStruct* _id = test_struct_observableStructDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_observableStructDefine test_struct_observableStructDefine
#endif
TEST_EXPORT corto_int16 _test_struct_observableStructDefine(test_struct_observableStruct* _this, test_Point* m);
#define test_struct_observableStructDefine(_this, m) _test_struct_observableStructDefine(test_struct_observableStruct(_this), m)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_observableStructAssign test_struct_observableStructAssign
#endif
TEST_EXPORT test_struct_observableStruct* _test_struct_observableStructAssign(test_struct_observableStruct* _this, test_Point* m);
#define test_struct_observableStruct__optional_NotSet NULL
#define test_struct_observableStruct__optional_Set(m) test_struct_observableStructAssign((test_struct_observableStruct*)corto_ptr_new(test_struct_observableStruct_o)), m)
#define test_struct_observableStruct__optional_SetCond(cond, m) cond ? test_struct_observableStructAssign((test_struct_observableStruct*)corto_ptr_new(test_struct_observableStruct_o), m) : NULL
#define test_struct_observableStructUnset(_this) _this ? corto_ptr_free(_this, test_struct_observableStruct_o), 0 : 0; _this = NULL;
#define test_struct_observableStructAssign(_this, m) _test_struct_observableStructAssign(_this, m)
#define test_struct_observableStructSet(_this, m) _this = _this ? _this : (test_struct_observableStruct*)corto_ptr_new(test_struct_observableStruct_o); _test_struct_observableStructAssign(_this, m)

/* /test/struct_optionalArray */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_optionalArrayCreate test_struct_optionalArrayCreate
#endif
TEST_EXPORT test_struct_optionalArray* _test_struct_optionalArrayCreate(test_IntArray* m);
#define test_struct_optionalArrayCreate(m) _test_struct_optionalArrayCreate(test_IntArray__optional_##m)
#define test_struct_optionalArrayCreate_auto(_id, m) test_struct_optionalArray* _id = test_struct_optionalArrayCreate(m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_optionalArrayCreateChild test_struct_optionalArrayCreateChild
#endif
TEST_EXPORT test_struct_optionalArray* _test_struct_optionalArrayCreateChild(corto_object _parent, corto_string _id, test_IntArray* m);
#define test_struct_optionalArrayCreateChild(_parent, _id, m) _test_struct_optionalArrayCreateChild(_parent, _id, test_IntArray__optional_##m)
#define test_struct_optionalArrayCreateChild_auto(_parent, _id, m) test_struct_optionalArray* _id = test_struct_optionalArrayCreateChild(_parent, #_id, m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_optionalArrayUpdate test_struct_optionalArrayUpdate
#endif
TEST_EXPORT corto_int16 _test_struct_optionalArrayUpdate(test_struct_optionalArray* _this, test_IntArray* m);
#define test_struct_optionalArrayUpdate(_this, m) _test_struct_optionalArrayUpdate(test_struct_optionalArray(_this), test_IntArray__optional_##m)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_optionalArrayDeclare test_struct_optionalArrayDeclare
#endif
TEST_EXPORT test_struct_optionalArray* _test_struct_optionalArrayDeclare(void);
#define test_struct_optionalArrayDeclare() _test_struct_optionalArrayDeclare()
#define test_struct_optionalArrayDeclare_auto(_id) test_struct_optionalArray* _id = test_struct_optionalArrayDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_optionalArrayDeclareChild test_struct_optionalArrayDeclareChild
#endif
TEST_EXPORT test_struct_optionalArray* _test_struct_optionalArrayDeclareChild(corto_object _parent, corto_string _id);
#define test_struct_optionalArrayDeclareChild(_parent, _id) _test_struct_optionalArrayDeclareChild(_parent, _id)
#define test_struct_optionalArrayDeclareChild_auto(_parent, _id) test_struct_optionalArray* _id = test_struct_optionalArrayDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_optionalArrayDefine test_struct_optionalArrayDefine
#endif
TEST_EXPORT corto_int16 _test_struct_optionalArrayDefine(test_struct_optionalArray* _this, test_IntArray* m);
#define test_struct_optionalArrayDefine(_this, m) _test_struct_optionalArrayDefine(test_struct_optionalArray(_this), test_IntArray__optional_##m)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_optionalArrayAssign test_struct_optionalArrayAssign
#endif
TEST_EXPORT test_struct_optionalArray* _test_struct_optionalArrayAssign(test_struct_optionalArray* _this, test_IntArray* m);
#define test_struct_optionalArray__optional_NotSet NULL
#define test_struct_optionalArray__optional_Set(m) test_struct_optionalArrayAssign((test_struct_optionalArray*)corto_ptr_new(test_struct_optionalArray_o)), m)
#define test_struct_optionalArray__optional_SetCond(cond, m) cond ? test_struct_optionalArrayAssign((test_struct_optionalArray*)corto_ptr_new(test_struct_optionalArray_o), m) : NULL
#define test_struct_optionalArrayUnset(_this) _this ? corto_ptr_free(_this, test_struct_optionalArray_o), 0 : 0; _this = NULL;
#define test_struct_optionalArrayAssign(_this, m) _test_struct_optionalArrayAssign(_this, test_IntArray__optional_##m)
#define test_struct_optionalArraySet(_this, m) _this = _this ? _this : (test_struct_optionalArray*)corto_ptr_new(test_struct_optionalArray_o); _test_struct_optionalArrayAssign(_this, test_IntArray__optional_##m)

/* /test/struct_optionalInt */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_optionalIntCreate test_struct_optionalIntCreate
#endif
TEST_EXPORT test_struct_optionalInt* _test_struct_optionalIntCreate(int32_t* m);
#define test_struct_optionalIntCreate(m) _test_struct_optionalIntCreate(corto_int32__optional_##m)
#define test_struct_optionalIntCreate_auto(_id, m) test_struct_optionalInt* _id = test_struct_optionalIntCreate(m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_optionalIntCreateChild test_struct_optionalIntCreateChild
#endif
TEST_EXPORT test_struct_optionalInt* _test_struct_optionalIntCreateChild(corto_object _parent, corto_string _id, int32_t* m);
#define test_struct_optionalIntCreateChild(_parent, _id, m) _test_struct_optionalIntCreateChild(_parent, _id, corto_int32__optional_##m)
#define test_struct_optionalIntCreateChild_auto(_parent, _id, m) test_struct_optionalInt* _id = test_struct_optionalIntCreateChild(_parent, #_id, m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_optionalIntUpdate test_struct_optionalIntUpdate
#endif
TEST_EXPORT corto_int16 _test_struct_optionalIntUpdate(test_struct_optionalInt* _this, int32_t* m);
#define test_struct_optionalIntUpdate(_this, m) _test_struct_optionalIntUpdate(test_struct_optionalInt(_this), corto_int32__optional_##m)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_optionalIntDeclare test_struct_optionalIntDeclare
#endif
TEST_EXPORT test_struct_optionalInt* _test_struct_optionalIntDeclare(void);
#define test_struct_optionalIntDeclare() _test_struct_optionalIntDeclare()
#define test_struct_optionalIntDeclare_auto(_id) test_struct_optionalInt* _id = test_struct_optionalIntDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_optionalIntDeclareChild test_struct_optionalIntDeclareChild
#endif
TEST_EXPORT test_struct_optionalInt* _test_struct_optionalIntDeclareChild(corto_object _parent, corto_string _id);
#define test_struct_optionalIntDeclareChild(_parent, _id) _test_struct_optionalIntDeclareChild(_parent, _id)
#define test_struct_optionalIntDeclareChild_auto(_parent, _id) test_struct_optionalInt* _id = test_struct_optionalIntDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_optionalIntDefine test_struct_optionalIntDefine
#endif
TEST_EXPORT corto_int16 _test_struct_optionalIntDefine(test_struct_optionalInt* _this, int32_t* m);
#define test_struct_optionalIntDefine(_this, m) _test_struct_optionalIntDefine(test_struct_optionalInt(_this), corto_int32__optional_##m)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_optionalIntAssign test_struct_optionalIntAssign
#endif
TEST_EXPORT test_struct_optionalInt* _test_struct_optionalIntAssign(test_struct_optionalInt* _this, int32_t* m);
#define test_struct_optionalInt__optional_NotSet NULL
#define test_struct_optionalInt__optional_Set(m) test_struct_optionalIntAssign((test_struct_optionalInt*)corto_ptr_new(test_struct_optionalInt_o)), m)
#define test_struct_optionalInt__optional_SetCond(cond, m) cond ? test_struct_optionalIntAssign((test_struct_optionalInt*)corto_ptr_new(test_struct_optionalInt_o), m) : NULL
#define test_struct_optionalIntUnset(_this) _this ? corto_ptr_free(_this, test_struct_optionalInt_o), 0 : 0; _this = NULL;
#define test_struct_optionalIntAssign(_this, m) _test_struct_optionalIntAssign(_this, corto_int32__optional_##m)
#define test_struct_optionalIntSet(_this, m) _this = _this ? _this : (test_struct_optionalInt*)corto_ptr_new(test_struct_optionalInt_o); _test_struct_optionalIntAssign(_this, corto_int32__optional_##m)

/* /test/struct_optionalList */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_optionalListCreate test_struct_optionalListCreate
#endif
TEST_EXPORT test_struct_optionalList* _test_struct_optionalListCreate(test_IntList* m);
#define test_struct_optionalListCreate(m) _test_struct_optionalListCreate(test_IntList__optional_##m)
#define test_struct_optionalListCreate_auto(_id, m) test_struct_optionalList* _id = test_struct_optionalListCreate(m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_optionalListCreateChild test_struct_optionalListCreateChild
#endif
TEST_EXPORT test_struct_optionalList* _test_struct_optionalListCreateChild(corto_object _parent, corto_string _id, test_IntList* m);
#define test_struct_optionalListCreateChild(_parent, _id, m) _test_struct_optionalListCreateChild(_parent, _id, test_IntList__optional_##m)
#define test_struct_optionalListCreateChild_auto(_parent, _id, m) test_struct_optionalList* _id = test_struct_optionalListCreateChild(_parent, #_id, m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_optionalListUpdate test_struct_optionalListUpdate
#endif
TEST_EXPORT corto_int16 _test_struct_optionalListUpdate(test_struct_optionalList* _this, test_IntList* m);
#define test_struct_optionalListUpdate(_this, m) _test_struct_optionalListUpdate(test_struct_optionalList(_this), test_IntList__optional_##m)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_optionalListDeclare test_struct_optionalListDeclare
#endif
TEST_EXPORT test_struct_optionalList* _test_struct_optionalListDeclare(void);
#define test_struct_optionalListDeclare() _test_struct_optionalListDeclare()
#define test_struct_optionalListDeclare_auto(_id) test_struct_optionalList* _id = test_struct_optionalListDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_optionalListDeclareChild test_struct_optionalListDeclareChild
#endif
TEST_EXPORT test_struct_optionalList* _test_struct_optionalListDeclareChild(corto_object _parent, corto_string _id);
#define test_struct_optionalListDeclareChild(_parent, _id) _test_struct_optionalListDeclareChild(_parent, _id)
#define test_struct_optionalListDeclareChild_auto(_parent, _id) test_struct_optionalList* _id = test_struct_optionalListDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_optionalListDefine test_struct_optionalListDefine
#endif
TEST_EXPORT corto_int16 _test_struct_optionalListDefine(test_struct_optionalList* _this, test_IntList* m);
#define test_struct_optionalListDefine(_this, m) _test_struct_optionalListDefine(test_struct_optionalList(_this), test_IntList__optional_##m)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_optionalListAssign test_struct_optionalListAssign
#endif
TEST_EXPORT test_struct_optionalList* _test_struct_optionalListAssign(test_struct_optionalList* _this, test_IntList* m);
#define test_struct_optionalList__optional_NotSet NULL
#define test_struct_optionalList__optional_Set(m) test_struct_optionalListAssign((test_struct_optionalList*)corto_ptr_new(test_struct_optionalList_o)), m)
#define test_struct_optionalList__optional_SetCond(cond, m) cond ? test_struct_optionalListAssign((test_struct_optionalList*)corto_ptr_new(test_struct_optionalList_o), m) : NULL
#define test_struct_optionalListUnset(_this) _this ? corto_ptr_free(_this, test_struct_optionalList_o), 0 : 0; _this = NULL;
#define test_struct_optionalListAssign(_this, m) _test_struct_optionalListAssign(_this, test_IntList__optional_##m)
#define test_struct_optionalListSet(_this, m) _this = _this ? _this : (test_struct_optionalList*)corto_ptr_new(test_struct_optionalList_o); _test_struct_optionalListAssign(_this, test_IntList__optional_##m)

/* /test/struct_optionalReference */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_optionalReferenceCreate test_struct_optionalReferenceCreate
#endif
TEST_EXPORT test_struct_optionalReference* _test_struct_optionalReferenceCreate(corto_object* m);
#define test_struct_optionalReferenceCreate(m) _test_struct_optionalReferenceCreate(corto_object__optional_##m)
#define test_struct_optionalReferenceCreate_auto(_id, m) test_struct_optionalReference* _id = test_struct_optionalReferenceCreate(m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_optionalReferenceCreateChild test_struct_optionalReferenceCreateChild
#endif
TEST_EXPORT test_struct_optionalReference* _test_struct_optionalReferenceCreateChild(corto_object _parent, corto_string _id, corto_object* m);
#define test_struct_optionalReferenceCreateChild(_parent, _id, m) _test_struct_optionalReferenceCreateChild(_parent, _id, corto_object__optional_##m)
#define test_struct_optionalReferenceCreateChild_auto(_parent, _id, m) test_struct_optionalReference* _id = test_struct_optionalReferenceCreateChild(_parent, #_id, m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_optionalReferenceUpdate test_struct_optionalReferenceUpdate
#endif
TEST_EXPORT corto_int16 _test_struct_optionalReferenceUpdate(test_struct_optionalReference* _this, corto_object* m);
#define test_struct_optionalReferenceUpdate(_this, m) _test_struct_optionalReferenceUpdate(test_struct_optionalReference(_this), corto_object__optional_##m)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_optionalReferenceDeclare test_struct_optionalReferenceDeclare
#endif
TEST_EXPORT test_struct_optionalReference* _test_struct_optionalReferenceDeclare(void);
#define test_struct_optionalReferenceDeclare() _test_struct_optionalReferenceDeclare()
#define test_struct_optionalReferenceDeclare_auto(_id) test_struct_optionalReference* _id = test_struct_optionalReferenceDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_optionalReferenceDeclareChild test_struct_optionalReferenceDeclareChild
#endif
TEST_EXPORT test_struct_optionalReference* _test_struct_optionalReferenceDeclareChild(corto_object _parent, corto_string _id);
#define test_struct_optionalReferenceDeclareChild(_parent, _id) _test_struct_optionalReferenceDeclareChild(_parent, _id)
#define test_struct_optionalReferenceDeclareChild_auto(_parent, _id) test_struct_optionalReference* _id = test_struct_optionalReferenceDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_optionalReferenceDefine test_struct_optionalReferenceDefine
#endif
TEST_EXPORT corto_int16 _test_struct_optionalReferenceDefine(test_struct_optionalReference* _this, corto_object* m);
#define test_struct_optionalReferenceDefine(_this, m) _test_struct_optionalReferenceDefine(test_struct_optionalReference(_this), corto_object__optional_##m)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_optionalReferenceAssign test_struct_optionalReferenceAssign
#endif
TEST_EXPORT test_struct_optionalReference* _test_struct_optionalReferenceAssign(test_struct_optionalReference* _this, corto_object* m);
#define test_struct_optionalReference__optional_NotSet NULL
#define test_struct_optionalReference__optional_Set(m) test_struct_optionalReferenceAssign((test_struct_optionalReference*)corto_ptr_new(test_struct_optionalReference_o)), m)
#define test_struct_optionalReference__optional_SetCond(cond, m) cond ? test_struct_optionalReferenceAssign((test_struct_optionalReference*)corto_ptr_new(test_struct_optionalReference_o), m) : NULL
#define test_struct_optionalReferenceUnset(_this) _this ? corto_ptr_free(_this, test_struct_optionalReference_o), 0 : 0; _this = NULL;
#define test_struct_optionalReferenceAssign(_this, m) _test_struct_optionalReferenceAssign(_this, corto_object__optional_##m)
#define test_struct_optionalReferenceSet(_this, m) _this = _this ? _this : (test_struct_optionalReference*)corto_ptr_new(test_struct_optionalReference_o); _test_struct_optionalReferenceAssign(_this, corto_object__optional_##m)

/* /test/struct_optionalSequence */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_optionalSequenceCreate test_struct_optionalSequenceCreate
#endif
TEST_EXPORT test_struct_optionalSequence* _test_struct_optionalSequenceCreate(test_IntSequence* m);
#define test_struct_optionalSequenceCreate(m) _test_struct_optionalSequenceCreate(test_IntSequence__optional_##m)
#define test_struct_optionalSequenceCreate_auto(_id, m) test_struct_optionalSequence* _id = test_struct_optionalSequenceCreate(m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_optionalSequenceCreateChild test_struct_optionalSequenceCreateChild
#endif
TEST_EXPORT test_struct_optionalSequence* _test_struct_optionalSequenceCreateChild(corto_object _parent, corto_string _id, test_IntSequence* m);
#define test_struct_optionalSequenceCreateChild(_parent, _id, m) _test_struct_optionalSequenceCreateChild(_parent, _id, test_IntSequence__optional_##m)
#define test_struct_optionalSequenceCreateChild_auto(_parent, _id, m) test_struct_optionalSequence* _id = test_struct_optionalSequenceCreateChild(_parent, #_id, m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_optionalSequenceUpdate test_struct_optionalSequenceUpdate
#endif
TEST_EXPORT corto_int16 _test_struct_optionalSequenceUpdate(test_struct_optionalSequence* _this, test_IntSequence* m);
#define test_struct_optionalSequenceUpdate(_this, m) _test_struct_optionalSequenceUpdate(test_struct_optionalSequence(_this), test_IntSequence__optional_##m)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_optionalSequenceDeclare test_struct_optionalSequenceDeclare
#endif
TEST_EXPORT test_struct_optionalSequence* _test_struct_optionalSequenceDeclare(void);
#define test_struct_optionalSequenceDeclare() _test_struct_optionalSequenceDeclare()
#define test_struct_optionalSequenceDeclare_auto(_id) test_struct_optionalSequence* _id = test_struct_optionalSequenceDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_optionalSequenceDeclareChild test_struct_optionalSequenceDeclareChild
#endif
TEST_EXPORT test_struct_optionalSequence* _test_struct_optionalSequenceDeclareChild(corto_object _parent, corto_string _id);
#define test_struct_optionalSequenceDeclareChild(_parent, _id) _test_struct_optionalSequenceDeclareChild(_parent, _id)
#define test_struct_optionalSequenceDeclareChild_auto(_parent, _id) test_struct_optionalSequence* _id = test_struct_optionalSequenceDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_optionalSequenceDefine test_struct_optionalSequenceDefine
#endif
TEST_EXPORT corto_int16 _test_struct_optionalSequenceDefine(test_struct_optionalSequence* _this, test_IntSequence* m);
#define test_struct_optionalSequenceDefine(_this, m) _test_struct_optionalSequenceDefine(test_struct_optionalSequence(_this), test_IntSequence__optional_##m)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_optionalSequenceAssign test_struct_optionalSequenceAssign
#endif
TEST_EXPORT test_struct_optionalSequence* _test_struct_optionalSequenceAssign(test_struct_optionalSequence* _this, test_IntSequence* m);
#define test_struct_optionalSequence__optional_NotSet NULL
#define test_struct_optionalSequence__optional_Set(m) test_struct_optionalSequenceAssign((test_struct_optionalSequence*)corto_ptr_new(test_struct_optionalSequence_o)), m)
#define test_struct_optionalSequence__optional_SetCond(cond, m) cond ? test_struct_optionalSequenceAssign((test_struct_optionalSequence*)corto_ptr_new(test_struct_optionalSequence_o), m) : NULL
#define test_struct_optionalSequenceUnset(_this) _this ? corto_ptr_free(_this, test_struct_optionalSequence_o), 0 : 0; _this = NULL;
#define test_struct_optionalSequenceAssign(_this, m) _test_struct_optionalSequenceAssign(_this, test_IntSequence__optional_##m)
#define test_struct_optionalSequenceSet(_this, m) _this = _this ? _this : (test_struct_optionalSequence*)corto_ptr_new(test_struct_optionalSequence_o); _test_struct_optionalSequenceAssign(_this, test_IntSequence__optional_##m)

/* /test/struct_optionalString */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_optionalStringCreate test_struct_optionalStringCreate
#endif
TEST_EXPORT test_struct_optionalString* _test_struct_optionalStringCreate(corto_string* m);
#define test_struct_optionalStringCreate(m) _test_struct_optionalStringCreate(corto_string__optional_##m)
#define test_struct_optionalStringCreate_auto(_id, m) test_struct_optionalString* _id = test_struct_optionalStringCreate(m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_optionalStringCreateChild test_struct_optionalStringCreateChild
#endif
TEST_EXPORT test_struct_optionalString* _test_struct_optionalStringCreateChild(corto_object _parent, corto_string _id, corto_string* m);
#define test_struct_optionalStringCreateChild(_parent, _id, m) _test_struct_optionalStringCreateChild(_parent, _id, corto_string__optional_##m)
#define test_struct_optionalStringCreateChild_auto(_parent, _id, m) test_struct_optionalString* _id = test_struct_optionalStringCreateChild(_parent, #_id, m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_optionalStringUpdate test_struct_optionalStringUpdate
#endif
TEST_EXPORT corto_int16 _test_struct_optionalStringUpdate(test_struct_optionalString* _this, corto_string* m);
#define test_struct_optionalStringUpdate(_this, m) _test_struct_optionalStringUpdate(test_struct_optionalString(_this), corto_string__optional_##m)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_optionalStringDeclare test_struct_optionalStringDeclare
#endif
TEST_EXPORT test_struct_optionalString* _test_struct_optionalStringDeclare(void);
#define test_struct_optionalStringDeclare() _test_struct_optionalStringDeclare()
#define test_struct_optionalStringDeclare_auto(_id) test_struct_optionalString* _id = test_struct_optionalStringDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_optionalStringDeclareChild test_struct_optionalStringDeclareChild
#endif
TEST_EXPORT test_struct_optionalString* _test_struct_optionalStringDeclareChild(corto_object _parent, corto_string _id);
#define test_struct_optionalStringDeclareChild(_parent, _id) _test_struct_optionalStringDeclareChild(_parent, _id)
#define test_struct_optionalStringDeclareChild_auto(_parent, _id) test_struct_optionalString* _id = test_struct_optionalStringDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_optionalStringDefine test_struct_optionalStringDefine
#endif
TEST_EXPORT corto_int16 _test_struct_optionalStringDefine(test_struct_optionalString* _this, corto_string* m);
#define test_struct_optionalStringDefine(_this, m) _test_struct_optionalStringDefine(test_struct_optionalString(_this), corto_string__optional_##m)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_optionalStringAssign test_struct_optionalStringAssign
#endif
TEST_EXPORT test_struct_optionalString* _test_struct_optionalStringAssign(test_struct_optionalString* _this, corto_string* m);
#define test_struct_optionalString__optional_NotSet NULL
#define test_struct_optionalString__optional_Set(m) test_struct_optionalStringAssign((test_struct_optionalString*)corto_ptr_new(test_struct_optionalString_o)), m)
#define test_struct_optionalString__optional_SetCond(cond, m) cond ? test_struct_optionalStringAssign((test_struct_optionalString*)corto_ptr_new(test_struct_optionalString_o), m) : NULL
#define test_struct_optionalStringUnset(_this) _this ? corto_ptr_free(_this, test_struct_optionalString_o), 0 : 0; _this = NULL;
#define test_struct_optionalStringAssign(_this, m) _test_struct_optionalStringAssign(_this, corto_string__optional_##m)
#define test_struct_optionalStringSet(_this, m) _this = _this ? _this : (test_struct_optionalString*)corto_ptr_new(test_struct_optionalString_o); _test_struct_optionalStringAssign(_this, corto_string__optional_##m)

/* /test/struct_optionalStruct */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_optionalStructCreate test_struct_optionalStructCreate
#endif
TEST_EXPORT test_struct_optionalStruct* _test_struct_optionalStructCreate(test_Point* m);
#define test_struct_optionalStructCreate(m) _test_struct_optionalStructCreate(test_Point__optional_##m)
#define test_struct_optionalStructCreate_auto(_id, m) test_struct_optionalStruct* _id = test_struct_optionalStructCreate(m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_optionalStructCreateChild test_struct_optionalStructCreateChild
#endif
TEST_EXPORT test_struct_optionalStruct* _test_struct_optionalStructCreateChild(corto_object _parent, corto_string _id, test_Point* m);
#define test_struct_optionalStructCreateChild(_parent, _id, m) _test_struct_optionalStructCreateChild(_parent, _id, test_Point__optional_##m)
#define test_struct_optionalStructCreateChild_auto(_parent, _id, m) test_struct_optionalStruct* _id = test_struct_optionalStructCreateChild(_parent, #_id, m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_optionalStructUpdate test_struct_optionalStructUpdate
#endif
TEST_EXPORT corto_int16 _test_struct_optionalStructUpdate(test_struct_optionalStruct* _this, test_Point* m);
#define test_struct_optionalStructUpdate(_this, m) _test_struct_optionalStructUpdate(test_struct_optionalStruct(_this), test_Point__optional_##m)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_optionalStructDeclare test_struct_optionalStructDeclare
#endif
TEST_EXPORT test_struct_optionalStruct* _test_struct_optionalStructDeclare(void);
#define test_struct_optionalStructDeclare() _test_struct_optionalStructDeclare()
#define test_struct_optionalStructDeclare_auto(_id) test_struct_optionalStruct* _id = test_struct_optionalStructDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_optionalStructDeclareChild test_struct_optionalStructDeclareChild
#endif
TEST_EXPORT test_struct_optionalStruct* _test_struct_optionalStructDeclareChild(corto_object _parent, corto_string _id);
#define test_struct_optionalStructDeclareChild(_parent, _id) _test_struct_optionalStructDeclareChild(_parent, _id)
#define test_struct_optionalStructDeclareChild_auto(_parent, _id) test_struct_optionalStruct* _id = test_struct_optionalStructDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_optionalStructDefine test_struct_optionalStructDefine
#endif
TEST_EXPORT corto_int16 _test_struct_optionalStructDefine(test_struct_optionalStruct* _this, test_Point* m);
#define test_struct_optionalStructDefine(_this, m) _test_struct_optionalStructDefine(test_struct_optionalStruct(_this), test_Point__optional_##m)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_optionalStructAssign test_struct_optionalStructAssign
#endif
TEST_EXPORT test_struct_optionalStruct* _test_struct_optionalStructAssign(test_struct_optionalStruct* _this, test_Point* m);
#define test_struct_optionalStruct__optional_NotSet NULL
#define test_struct_optionalStruct__optional_Set(m) test_struct_optionalStructAssign((test_struct_optionalStruct*)corto_ptr_new(test_struct_optionalStruct_o)), m)
#define test_struct_optionalStruct__optional_SetCond(cond, m) cond ? test_struct_optionalStructAssign((test_struct_optionalStruct*)corto_ptr_new(test_struct_optionalStruct_o), m) : NULL
#define test_struct_optionalStructUnset(_this) _this ? corto_ptr_free(_this, test_struct_optionalStruct_o), 0 : 0; _this = NULL;
#define test_struct_optionalStructAssign(_this, m) _test_struct_optionalStructAssign(_this, test_Point__optional_##m)
#define test_struct_optionalStructSet(_this, m) _this = _this ? _this : (test_struct_optionalStruct*)corto_ptr_new(test_struct_optionalStruct_o); _test_struct_optionalStructAssign(_this, test_Point__optional_##m)

/* /test/struct_sequenceInt */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_sequenceIntCreate test_struct_sequenceIntCreate
#endif
TEST_EXPORT test_struct_sequenceInt* _test_struct_sequenceIntCreate(corto_int32Seq m);
#define test_struct_sequenceIntCreate(m) _test_struct_sequenceIntCreate(m)
#define test_struct_sequenceIntCreate_auto(_id, m) test_struct_sequenceInt* _id = test_struct_sequenceIntCreate(m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_sequenceIntCreateChild test_struct_sequenceIntCreateChild
#endif
TEST_EXPORT test_struct_sequenceInt* _test_struct_sequenceIntCreateChild(corto_object _parent, corto_string _id, corto_int32Seq m);
#define test_struct_sequenceIntCreateChild(_parent, _id, m) _test_struct_sequenceIntCreateChild(_parent, _id, m)
#define test_struct_sequenceIntCreateChild_auto(_parent, _id, m) test_struct_sequenceInt* _id = test_struct_sequenceIntCreateChild(_parent, #_id, m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_sequenceIntUpdate test_struct_sequenceIntUpdate
#endif
TEST_EXPORT corto_int16 _test_struct_sequenceIntUpdate(test_struct_sequenceInt* _this, corto_int32Seq m);
#define test_struct_sequenceIntUpdate(_this, m) _test_struct_sequenceIntUpdate(test_struct_sequenceInt(_this), m)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_sequenceIntDeclare test_struct_sequenceIntDeclare
#endif
TEST_EXPORT test_struct_sequenceInt* _test_struct_sequenceIntDeclare(void);
#define test_struct_sequenceIntDeclare() _test_struct_sequenceIntDeclare()
#define test_struct_sequenceIntDeclare_auto(_id) test_struct_sequenceInt* _id = test_struct_sequenceIntDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_sequenceIntDeclareChild test_struct_sequenceIntDeclareChild
#endif
TEST_EXPORT test_struct_sequenceInt* _test_struct_sequenceIntDeclareChild(corto_object _parent, corto_string _id);
#define test_struct_sequenceIntDeclareChild(_parent, _id) _test_struct_sequenceIntDeclareChild(_parent, _id)
#define test_struct_sequenceIntDeclareChild_auto(_parent, _id) test_struct_sequenceInt* _id = test_struct_sequenceIntDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_sequenceIntDefine test_struct_sequenceIntDefine
#endif
TEST_EXPORT corto_int16 _test_struct_sequenceIntDefine(test_struct_sequenceInt* _this, corto_int32Seq m);
#define test_struct_sequenceIntDefine(_this, m) _test_struct_sequenceIntDefine(test_struct_sequenceInt(_this), m)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_sequenceIntAssign test_struct_sequenceIntAssign
#endif
TEST_EXPORT test_struct_sequenceInt* _test_struct_sequenceIntAssign(test_struct_sequenceInt* _this, corto_int32Seq m);
#define test_struct_sequenceInt__optional_NotSet NULL
#define test_struct_sequenceInt__optional_Set(m) test_struct_sequenceIntAssign((test_struct_sequenceInt*)corto_ptr_new(test_struct_sequenceInt_o)), m)
#define test_struct_sequenceInt__optional_SetCond(cond, m) cond ? test_struct_sequenceIntAssign((test_struct_sequenceInt*)corto_ptr_new(test_struct_sequenceInt_o), m) : NULL
#define test_struct_sequenceIntUnset(_this) _this ? corto_ptr_free(_this, test_struct_sequenceInt_o), 0 : 0; _this = NULL;
#define test_struct_sequenceIntAssign(_this, m) _test_struct_sequenceIntAssign(_this, m)
#define test_struct_sequenceIntSet(_this, m) _this = _this ? _this : (test_struct_sequenceInt*)corto_ptr_new(test_struct_sequenceInt_o); _test_struct_sequenceIntAssign(_this, m)

/* /test/struct_sequenceReference */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_sequenceReferenceCreate test_struct_sequenceReferenceCreate
#endif
TEST_EXPORT test_struct_sequenceReference* _test_struct_sequenceReferenceCreate(corto_objectSeq m);
#define test_struct_sequenceReferenceCreate(m) _test_struct_sequenceReferenceCreate(m)
#define test_struct_sequenceReferenceCreate_auto(_id, m) test_struct_sequenceReference* _id = test_struct_sequenceReferenceCreate(m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_sequenceReferenceCreateChild test_struct_sequenceReferenceCreateChild
#endif
TEST_EXPORT test_struct_sequenceReference* _test_struct_sequenceReferenceCreateChild(corto_object _parent, corto_string _id, corto_objectSeq m);
#define test_struct_sequenceReferenceCreateChild(_parent, _id, m) _test_struct_sequenceReferenceCreateChild(_parent, _id, m)
#define test_struct_sequenceReferenceCreateChild_auto(_parent, _id, m) test_struct_sequenceReference* _id = test_struct_sequenceReferenceCreateChild(_parent, #_id, m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_sequenceReferenceUpdate test_struct_sequenceReferenceUpdate
#endif
TEST_EXPORT corto_int16 _test_struct_sequenceReferenceUpdate(test_struct_sequenceReference* _this, corto_objectSeq m);
#define test_struct_sequenceReferenceUpdate(_this, m) _test_struct_sequenceReferenceUpdate(test_struct_sequenceReference(_this), m)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_sequenceReferenceDeclare test_struct_sequenceReferenceDeclare
#endif
TEST_EXPORT test_struct_sequenceReference* _test_struct_sequenceReferenceDeclare(void);
#define test_struct_sequenceReferenceDeclare() _test_struct_sequenceReferenceDeclare()
#define test_struct_sequenceReferenceDeclare_auto(_id) test_struct_sequenceReference* _id = test_struct_sequenceReferenceDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_sequenceReferenceDeclareChild test_struct_sequenceReferenceDeclareChild
#endif
TEST_EXPORT test_struct_sequenceReference* _test_struct_sequenceReferenceDeclareChild(corto_object _parent, corto_string _id);
#define test_struct_sequenceReferenceDeclareChild(_parent, _id) _test_struct_sequenceReferenceDeclareChild(_parent, _id)
#define test_struct_sequenceReferenceDeclareChild_auto(_parent, _id) test_struct_sequenceReference* _id = test_struct_sequenceReferenceDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_sequenceReferenceDefine test_struct_sequenceReferenceDefine
#endif
TEST_EXPORT corto_int16 _test_struct_sequenceReferenceDefine(test_struct_sequenceReference* _this, corto_objectSeq m);
#define test_struct_sequenceReferenceDefine(_this, m) _test_struct_sequenceReferenceDefine(test_struct_sequenceReference(_this), m)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_sequenceReferenceAssign test_struct_sequenceReferenceAssign
#endif
TEST_EXPORT test_struct_sequenceReference* _test_struct_sequenceReferenceAssign(test_struct_sequenceReference* _this, corto_objectSeq m);
#define test_struct_sequenceReference__optional_NotSet NULL
#define test_struct_sequenceReference__optional_Set(m) test_struct_sequenceReferenceAssign((test_struct_sequenceReference*)corto_ptr_new(test_struct_sequenceReference_o)), m)
#define test_struct_sequenceReference__optional_SetCond(cond, m) cond ? test_struct_sequenceReferenceAssign((test_struct_sequenceReference*)corto_ptr_new(test_struct_sequenceReference_o), m) : NULL
#define test_struct_sequenceReferenceUnset(_this) _this ? corto_ptr_free(_this, test_struct_sequenceReference_o), 0 : 0; _this = NULL;
#define test_struct_sequenceReferenceAssign(_this, m) _test_struct_sequenceReferenceAssign(_this, m)
#define test_struct_sequenceReferenceSet(_this, m) _this = _this ? _this : (test_struct_sequenceReference*)corto_ptr_new(test_struct_sequenceReference_o); _test_struct_sequenceReferenceAssign(_this, m)

/* /test/struct_sequenceString */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_sequenceStringCreate test_struct_sequenceStringCreate
#endif
TEST_EXPORT test_struct_sequenceString* _test_struct_sequenceStringCreate(corto_stringSeq m);
#define test_struct_sequenceStringCreate(m) _test_struct_sequenceStringCreate(m)
#define test_struct_sequenceStringCreate_auto(_id, m) test_struct_sequenceString* _id = test_struct_sequenceStringCreate(m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_sequenceStringCreateChild test_struct_sequenceStringCreateChild
#endif
TEST_EXPORT test_struct_sequenceString* _test_struct_sequenceStringCreateChild(corto_object _parent, corto_string _id, corto_stringSeq m);
#define test_struct_sequenceStringCreateChild(_parent, _id, m) _test_struct_sequenceStringCreateChild(_parent, _id, m)
#define test_struct_sequenceStringCreateChild_auto(_parent, _id, m) test_struct_sequenceString* _id = test_struct_sequenceStringCreateChild(_parent, #_id, m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_sequenceStringUpdate test_struct_sequenceStringUpdate
#endif
TEST_EXPORT corto_int16 _test_struct_sequenceStringUpdate(test_struct_sequenceString* _this, corto_stringSeq m);
#define test_struct_sequenceStringUpdate(_this, m) _test_struct_sequenceStringUpdate(test_struct_sequenceString(_this), m)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_sequenceStringDeclare test_struct_sequenceStringDeclare
#endif
TEST_EXPORT test_struct_sequenceString* _test_struct_sequenceStringDeclare(void);
#define test_struct_sequenceStringDeclare() _test_struct_sequenceStringDeclare()
#define test_struct_sequenceStringDeclare_auto(_id) test_struct_sequenceString* _id = test_struct_sequenceStringDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_sequenceStringDeclareChild test_struct_sequenceStringDeclareChild
#endif
TEST_EXPORT test_struct_sequenceString* _test_struct_sequenceStringDeclareChild(corto_object _parent, corto_string _id);
#define test_struct_sequenceStringDeclareChild(_parent, _id) _test_struct_sequenceStringDeclareChild(_parent, _id)
#define test_struct_sequenceStringDeclareChild_auto(_parent, _id) test_struct_sequenceString* _id = test_struct_sequenceStringDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_sequenceStringDefine test_struct_sequenceStringDefine
#endif
TEST_EXPORT corto_int16 _test_struct_sequenceStringDefine(test_struct_sequenceString* _this, corto_stringSeq m);
#define test_struct_sequenceStringDefine(_this, m) _test_struct_sequenceStringDefine(test_struct_sequenceString(_this), m)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_sequenceStringAssign test_struct_sequenceStringAssign
#endif
TEST_EXPORT test_struct_sequenceString* _test_struct_sequenceStringAssign(test_struct_sequenceString* _this, corto_stringSeq m);
#define test_struct_sequenceString__optional_NotSet NULL
#define test_struct_sequenceString__optional_Set(m) test_struct_sequenceStringAssign((test_struct_sequenceString*)corto_ptr_new(test_struct_sequenceString_o)), m)
#define test_struct_sequenceString__optional_SetCond(cond, m) cond ? test_struct_sequenceStringAssign((test_struct_sequenceString*)corto_ptr_new(test_struct_sequenceString_o), m) : NULL
#define test_struct_sequenceStringUnset(_this) _this ? corto_ptr_free(_this, test_struct_sequenceString_o), 0 : 0; _this = NULL;
#define test_struct_sequenceStringAssign(_this, m) _test_struct_sequenceStringAssign(_this, m)
#define test_struct_sequenceStringSet(_this, m) _this = _this ? _this : (test_struct_sequenceString*)corto_ptr_new(test_struct_sequenceString_o); _test_struct_sequenceStringAssign(_this, m)

/* /test/struct_sequenceStruct */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_sequenceStructCreate test_struct_sequenceStructCreate
#endif
TEST_EXPORT test_struct_sequenceStruct* _test_struct_sequenceStructCreate(test_PointSeq m);
#define test_struct_sequenceStructCreate(m) _test_struct_sequenceStructCreate(m)
#define test_struct_sequenceStructCreate_auto(_id, m) test_struct_sequenceStruct* _id = test_struct_sequenceStructCreate(m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_sequenceStructCreateChild test_struct_sequenceStructCreateChild
#endif
TEST_EXPORT test_struct_sequenceStruct* _test_struct_sequenceStructCreateChild(corto_object _parent, corto_string _id, test_PointSeq m);
#define test_struct_sequenceStructCreateChild(_parent, _id, m) _test_struct_sequenceStructCreateChild(_parent, _id, m)
#define test_struct_sequenceStructCreateChild_auto(_parent, _id, m) test_struct_sequenceStruct* _id = test_struct_sequenceStructCreateChild(_parent, #_id, m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_sequenceStructUpdate test_struct_sequenceStructUpdate
#endif
TEST_EXPORT corto_int16 _test_struct_sequenceStructUpdate(test_struct_sequenceStruct* _this, test_PointSeq m);
#define test_struct_sequenceStructUpdate(_this, m) _test_struct_sequenceStructUpdate(test_struct_sequenceStruct(_this), m)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_sequenceStructDeclare test_struct_sequenceStructDeclare
#endif
TEST_EXPORT test_struct_sequenceStruct* _test_struct_sequenceStructDeclare(void);
#define test_struct_sequenceStructDeclare() _test_struct_sequenceStructDeclare()
#define test_struct_sequenceStructDeclare_auto(_id) test_struct_sequenceStruct* _id = test_struct_sequenceStructDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_sequenceStructDeclareChild test_struct_sequenceStructDeclareChild
#endif
TEST_EXPORT test_struct_sequenceStruct* _test_struct_sequenceStructDeclareChild(corto_object _parent, corto_string _id);
#define test_struct_sequenceStructDeclareChild(_parent, _id) _test_struct_sequenceStructDeclareChild(_parent, _id)
#define test_struct_sequenceStructDeclareChild_auto(_parent, _id) test_struct_sequenceStruct* _id = test_struct_sequenceStructDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_sequenceStructDefine test_struct_sequenceStructDefine
#endif
TEST_EXPORT corto_int16 _test_struct_sequenceStructDefine(test_struct_sequenceStruct* _this, test_PointSeq m);
#define test_struct_sequenceStructDefine(_this, m) _test_struct_sequenceStructDefine(test_struct_sequenceStruct(_this), m)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_sequenceStructAssign test_struct_sequenceStructAssign
#endif
TEST_EXPORT test_struct_sequenceStruct* _test_struct_sequenceStructAssign(test_struct_sequenceStruct* _this, test_PointSeq m);
#define test_struct_sequenceStruct__optional_NotSet NULL
#define test_struct_sequenceStruct__optional_Set(m) test_struct_sequenceStructAssign((test_struct_sequenceStruct*)corto_ptr_new(test_struct_sequenceStruct_o)), m)
#define test_struct_sequenceStruct__optional_SetCond(cond, m) cond ? test_struct_sequenceStructAssign((test_struct_sequenceStruct*)corto_ptr_new(test_struct_sequenceStruct_o), m) : NULL
#define test_struct_sequenceStructUnset(_this) _this ? corto_ptr_free(_this, test_struct_sequenceStruct_o), 0 : 0; _this = NULL;
#define test_struct_sequenceStructAssign(_this, m) _test_struct_sequenceStructAssign(_this, m)
#define test_struct_sequenceStructSet(_this, m) _this = _this ? _this : (test_struct_sequenceStruct*)corto_ptr_new(test_struct_sequenceStruct_o); _test_struct_sequenceStructAssign(_this, m)

/* /test/struct_string */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_stringCreate test_struct_stringCreate
#endif
TEST_EXPORT test_struct_string* _test_struct_stringCreate(corto_string m);
#define test_struct_stringCreate(m) _test_struct_stringCreate(m)
#define test_struct_stringCreate_auto(_id, m) test_struct_string* _id = test_struct_stringCreate(m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_stringCreateChild test_struct_stringCreateChild
#endif
TEST_EXPORT test_struct_string* _test_struct_stringCreateChild(corto_object _parent, corto_string _id, corto_string m);
#define test_struct_stringCreateChild(_parent, _id, m) _test_struct_stringCreateChild(_parent, _id, m)
#define test_struct_stringCreateChild_auto(_parent, _id, m) test_struct_string* _id = test_struct_stringCreateChild(_parent, #_id, m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_stringUpdate test_struct_stringUpdate
#endif
TEST_EXPORT corto_int16 _test_struct_stringUpdate(test_struct_string* _this, corto_string m);
#define test_struct_stringUpdate(_this, m) _test_struct_stringUpdate(test_struct_string(_this), m)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_stringDeclare test_struct_stringDeclare
#endif
TEST_EXPORT test_struct_string* _test_struct_stringDeclare(void);
#define test_struct_stringDeclare() _test_struct_stringDeclare()
#define test_struct_stringDeclare_auto(_id) test_struct_string* _id = test_struct_stringDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_stringDeclareChild test_struct_stringDeclareChild
#endif
TEST_EXPORT test_struct_string* _test_struct_stringDeclareChild(corto_object _parent, corto_string _id);
#define test_struct_stringDeclareChild(_parent, _id) _test_struct_stringDeclareChild(_parent, _id)
#define test_struct_stringDeclareChild_auto(_parent, _id) test_struct_string* _id = test_struct_stringDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_stringDefine test_struct_stringDefine
#endif
TEST_EXPORT corto_int16 _test_struct_stringDefine(test_struct_string* _this, corto_string m);
#define test_struct_stringDefine(_this, m) _test_struct_stringDefine(test_struct_string(_this), m)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_stringAssign test_struct_stringAssign
#endif
TEST_EXPORT test_struct_string* _test_struct_stringAssign(test_struct_string* _this, corto_string m);
#define test_struct_string__optional_NotSet NULL
#define test_struct_string__optional_Set(m) test_struct_stringAssign((test_struct_string*)corto_ptr_new(test_struct_string_o)), m)
#define test_struct_string__optional_SetCond(cond, m) cond ? test_struct_stringAssign((test_struct_string*)corto_ptr_new(test_struct_string_o), m) : NULL
#define test_struct_stringUnset(_this) _this ? corto_ptr_free(_this, test_struct_string_o), 0 : 0; _this = NULL;
#define test_struct_stringAssign(_this, m) _test_struct_stringAssign(_this, m)
#define test_struct_stringSet(_this, m) _this = _this ? _this : (test_struct_string*)corto_ptr_new(test_struct_string_o); _test_struct_stringAssign(_this, m)

/* /test/struct_targetArray */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_targetArrayCreate test_struct_targetArrayCreate
#endif
TEST_EXPORT test_struct_targetArray* _test_struct_targetArrayCreate(test_IntArray m);
#define test_struct_targetArrayCreate(m) _test_struct_targetArrayCreate(m)
#define test_struct_targetArrayCreate_auto(_id, m) test_struct_targetArray* _id = test_struct_targetArrayCreate(m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_targetArrayCreateChild test_struct_targetArrayCreateChild
#endif
TEST_EXPORT test_struct_targetArray* _test_struct_targetArrayCreateChild(corto_object _parent, corto_string _id, test_IntArray m);
#define test_struct_targetArrayCreateChild(_parent, _id, m) _test_struct_targetArrayCreateChild(_parent, _id, m)
#define test_struct_targetArrayCreateChild_auto(_parent, _id, m) test_struct_targetArray* _id = test_struct_targetArrayCreateChild(_parent, #_id, m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_targetArrayUpdate test_struct_targetArrayUpdate
#endif
TEST_EXPORT corto_int16 _test_struct_targetArrayUpdate(test_struct_targetArray* _this, test_IntArray m);
#define test_struct_targetArrayUpdate(_this, m) _test_struct_targetArrayUpdate(test_struct_targetArray(_this), m)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_targetArrayDeclare test_struct_targetArrayDeclare
#endif
TEST_EXPORT test_struct_targetArray* _test_struct_targetArrayDeclare(void);
#define test_struct_targetArrayDeclare() _test_struct_targetArrayDeclare()
#define test_struct_targetArrayDeclare_auto(_id) test_struct_targetArray* _id = test_struct_targetArrayDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_targetArrayDeclareChild test_struct_targetArrayDeclareChild
#endif
TEST_EXPORT test_struct_targetArray* _test_struct_targetArrayDeclareChild(corto_object _parent, corto_string _id);
#define test_struct_targetArrayDeclareChild(_parent, _id) _test_struct_targetArrayDeclareChild(_parent, _id)
#define test_struct_targetArrayDeclareChild_auto(_parent, _id) test_struct_targetArray* _id = test_struct_targetArrayDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_targetArrayDefine test_struct_targetArrayDefine
#endif
TEST_EXPORT corto_int16 _test_struct_targetArrayDefine(test_struct_targetArray* _this, test_IntArray m);
#define test_struct_targetArrayDefine(_this, m) _test_struct_targetArrayDefine(test_struct_targetArray(_this), m)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_targetArrayAssign test_struct_targetArrayAssign
#endif
TEST_EXPORT test_struct_targetArray* _test_struct_targetArrayAssign(test_struct_targetArray* _this, test_IntArray m);
#define test_struct_targetArray__optional_NotSet NULL
#define test_struct_targetArray__optional_Set(m) test_struct_targetArrayAssign((test_struct_targetArray*)corto_ptr_new(test_struct_targetArray_o)), m)
#define test_struct_targetArray__optional_SetCond(cond, m) cond ? test_struct_targetArrayAssign((test_struct_targetArray*)corto_ptr_new(test_struct_targetArray_o), m) : NULL
#define test_struct_targetArrayUnset(_this) _this ? corto_ptr_free(_this, test_struct_targetArray_o), 0 : 0; _this = NULL;
#define test_struct_targetArrayAssign(_this, m) _test_struct_targetArrayAssign(_this, m)
#define test_struct_targetArraySet(_this, m) _this = _this ? _this : (test_struct_targetArray*)corto_ptr_new(test_struct_targetArray_o); _test_struct_targetArrayAssign(_this, m)

/* /test/struct_targetInt */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_targetIntCreate test_struct_targetIntCreate
#endif
TEST_EXPORT test_struct_targetInt* _test_struct_targetIntCreate(int32_t m);
#define test_struct_targetIntCreate(m) _test_struct_targetIntCreate(m)
#define test_struct_targetIntCreate_auto(_id, m) test_struct_targetInt* _id = test_struct_targetIntCreate(m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_targetIntCreateChild test_struct_targetIntCreateChild
#endif
TEST_EXPORT test_struct_targetInt* _test_struct_targetIntCreateChild(corto_object _parent, corto_string _id, int32_t m);
#define test_struct_targetIntCreateChild(_parent, _id, m) _test_struct_targetIntCreateChild(_parent, _id, m)
#define test_struct_targetIntCreateChild_auto(_parent, _id, m) test_struct_targetInt* _id = test_struct_targetIntCreateChild(_parent, #_id, m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_targetIntUpdate test_struct_targetIntUpdate
#endif
TEST_EXPORT corto_int16 _test_struct_targetIntUpdate(test_struct_targetInt* _this, int32_t m);
#define test_struct_targetIntUpdate(_this, m) _test_struct_targetIntUpdate(test_struct_targetInt(_this), m)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_targetIntDeclare test_struct_targetIntDeclare
#endif
TEST_EXPORT test_struct_targetInt* _test_struct_targetIntDeclare(void);
#define test_struct_targetIntDeclare() _test_struct_targetIntDeclare()
#define test_struct_targetIntDeclare_auto(_id) test_struct_targetInt* _id = test_struct_targetIntDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_targetIntDeclareChild test_struct_targetIntDeclareChild
#endif
TEST_EXPORT test_struct_targetInt* _test_struct_targetIntDeclareChild(corto_object _parent, corto_string _id);
#define test_struct_targetIntDeclareChild(_parent, _id) _test_struct_targetIntDeclareChild(_parent, _id)
#define test_struct_targetIntDeclareChild_auto(_parent, _id) test_struct_targetInt* _id = test_struct_targetIntDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_targetIntDefine test_struct_targetIntDefine
#endif
TEST_EXPORT corto_int16 _test_struct_targetIntDefine(test_struct_targetInt* _this, int32_t m);
#define test_struct_targetIntDefine(_this, m) _test_struct_targetIntDefine(test_struct_targetInt(_this), m)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_targetIntAssign test_struct_targetIntAssign
#endif
TEST_EXPORT test_struct_targetInt* _test_struct_targetIntAssign(test_struct_targetInt* _this, int32_t m);
#define test_struct_targetInt__optional_NotSet NULL
#define test_struct_targetInt__optional_Set(m) test_struct_targetIntAssign((test_struct_targetInt*)corto_ptr_new(test_struct_targetInt_o)), m)
#define test_struct_targetInt__optional_SetCond(cond, m) cond ? test_struct_targetIntAssign((test_struct_targetInt*)corto_ptr_new(test_struct_targetInt_o), m) : NULL
#define test_struct_targetIntUnset(_this) _this ? corto_ptr_free(_this, test_struct_targetInt_o), 0 : 0; _this = NULL;
#define test_struct_targetIntAssign(_this, m) _test_struct_targetIntAssign(_this, m)
#define test_struct_targetIntSet(_this, m) _this = _this ? _this : (test_struct_targetInt*)corto_ptr_new(test_struct_targetInt_o); _test_struct_targetIntAssign(_this, m)

/* /test/struct_targetList */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_targetListCreate test_struct_targetListCreate
#endif
TEST_EXPORT test_struct_targetList* _test_struct_targetListCreate(test_IntList m);
#define test_struct_targetListCreate(m) _test_struct_targetListCreate(m)
#define test_struct_targetListCreate_auto(_id, m) test_struct_targetList* _id = test_struct_targetListCreate(m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_targetListCreateChild test_struct_targetListCreateChild
#endif
TEST_EXPORT test_struct_targetList* _test_struct_targetListCreateChild(corto_object _parent, corto_string _id, test_IntList m);
#define test_struct_targetListCreateChild(_parent, _id, m) _test_struct_targetListCreateChild(_parent, _id, m)
#define test_struct_targetListCreateChild_auto(_parent, _id, m) test_struct_targetList* _id = test_struct_targetListCreateChild(_parent, #_id, m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_targetListUpdate test_struct_targetListUpdate
#endif
TEST_EXPORT corto_int16 _test_struct_targetListUpdate(test_struct_targetList* _this, test_IntList m);
#define test_struct_targetListUpdate(_this, m) _test_struct_targetListUpdate(test_struct_targetList(_this), m)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_targetListDeclare test_struct_targetListDeclare
#endif
TEST_EXPORT test_struct_targetList* _test_struct_targetListDeclare(void);
#define test_struct_targetListDeclare() _test_struct_targetListDeclare()
#define test_struct_targetListDeclare_auto(_id) test_struct_targetList* _id = test_struct_targetListDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_targetListDeclareChild test_struct_targetListDeclareChild
#endif
TEST_EXPORT test_struct_targetList* _test_struct_targetListDeclareChild(corto_object _parent, corto_string _id);
#define test_struct_targetListDeclareChild(_parent, _id) _test_struct_targetListDeclareChild(_parent, _id)
#define test_struct_targetListDeclareChild_auto(_parent, _id) test_struct_targetList* _id = test_struct_targetListDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_targetListDefine test_struct_targetListDefine
#endif
TEST_EXPORT corto_int16 _test_struct_targetListDefine(test_struct_targetList* _this, test_IntList m);
#define test_struct_targetListDefine(_this, m) _test_struct_targetListDefine(test_struct_targetList(_this), m)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_targetListAssign test_struct_targetListAssign
#endif
TEST_EXPORT test_struct_targetList* _test_struct_targetListAssign(test_struct_targetList* _this, test_IntList m);
#define test_struct_targetList__optional_NotSet NULL
#define test_struct_targetList__optional_Set(m) test_struct_targetListAssign((test_struct_targetList*)corto_ptr_new(test_struct_targetList_o)), m)
#define test_struct_targetList__optional_SetCond(cond, m) cond ? test_struct_targetListAssign((test_struct_targetList*)corto_ptr_new(test_struct_targetList_o), m) : NULL
#define test_struct_targetListUnset(_this) _this ? corto_ptr_free(_this, test_struct_targetList_o), 0 : 0; _this = NULL;
#define test_struct_targetListAssign(_this, m) _test_struct_targetListAssign(_this, m)
#define test_struct_targetListSet(_this, m) _this = _this ? _this : (test_struct_targetList*)corto_ptr_new(test_struct_targetList_o); _test_struct_targetListAssign(_this, m)

/* /test/struct_targetReference */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_targetReferenceCreate test_struct_targetReferenceCreate
#endif
TEST_EXPORT test_struct_targetReference* _test_struct_targetReferenceCreate(corto_object m);
#define test_struct_targetReferenceCreate(m) _test_struct_targetReferenceCreate(m)
#define test_struct_targetReferenceCreate_auto(_id, m) test_struct_targetReference* _id = test_struct_targetReferenceCreate(m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_targetReferenceCreateChild test_struct_targetReferenceCreateChild
#endif
TEST_EXPORT test_struct_targetReference* _test_struct_targetReferenceCreateChild(corto_object _parent, corto_string _id, corto_object m);
#define test_struct_targetReferenceCreateChild(_parent, _id, m) _test_struct_targetReferenceCreateChild(_parent, _id, m)
#define test_struct_targetReferenceCreateChild_auto(_parent, _id, m) test_struct_targetReference* _id = test_struct_targetReferenceCreateChild(_parent, #_id, m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_targetReferenceUpdate test_struct_targetReferenceUpdate
#endif
TEST_EXPORT corto_int16 _test_struct_targetReferenceUpdate(test_struct_targetReference* _this, corto_object m);
#define test_struct_targetReferenceUpdate(_this, m) _test_struct_targetReferenceUpdate(test_struct_targetReference(_this), m)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_targetReferenceDeclare test_struct_targetReferenceDeclare
#endif
TEST_EXPORT test_struct_targetReference* _test_struct_targetReferenceDeclare(void);
#define test_struct_targetReferenceDeclare() _test_struct_targetReferenceDeclare()
#define test_struct_targetReferenceDeclare_auto(_id) test_struct_targetReference* _id = test_struct_targetReferenceDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_targetReferenceDeclareChild test_struct_targetReferenceDeclareChild
#endif
TEST_EXPORT test_struct_targetReference* _test_struct_targetReferenceDeclareChild(corto_object _parent, corto_string _id);
#define test_struct_targetReferenceDeclareChild(_parent, _id) _test_struct_targetReferenceDeclareChild(_parent, _id)
#define test_struct_targetReferenceDeclareChild_auto(_parent, _id) test_struct_targetReference* _id = test_struct_targetReferenceDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_targetReferenceDefine test_struct_targetReferenceDefine
#endif
TEST_EXPORT corto_int16 _test_struct_targetReferenceDefine(test_struct_targetReference* _this, corto_object m);
#define test_struct_targetReferenceDefine(_this, m) _test_struct_targetReferenceDefine(test_struct_targetReference(_this), m)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_targetReferenceAssign test_struct_targetReferenceAssign
#endif
TEST_EXPORT test_struct_targetReference* _test_struct_targetReferenceAssign(test_struct_targetReference* _this, corto_object m);
#define test_struct_targetReference__optional_NotSet NULL
#define test_struct_targetReference__optional_Set(m) test_struct_targetReferenceAssign((test_struct_targetReference*)corto_ptr_new(test_struct_targetReference_o)), m)
#define test_struct_targetReference__optional_SetCond(cond, m) cond ? test_struct_targetReferenceAssign((test_struct_targetReference*)corto_ptr_new(test_struct_targetReference_o), m) : NULL
#define test_struct_targetReferenceUnset(_this) _this ? corto_ptr_free(_this, test_struct_targetReference_o), 0 : 0; _this = NULL;
#define test_struct_targetReferenceAssign(_this, m) _test_struct_targetReferenceAssign(_this, m)
#define test_struct_targetReferenceSet(_this, m) _this = _this ? _this : (test_struct_targetReference*)corto_ptr_new(test_struct_targetReference_o); _test_struct_targetReferenceAssign(_this, m)

/* /test/struct_targetSequence */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_targetSequenceCreate test_struct_targetSequenceCreate
#endif
TEST_EXPORT test_struct_targetSequence* _test_struct_targetSequenceCreate(test_IntSequence m);
#define test_struct_targetSequenceCreate(m) _test_struct_targetSequenceCreate(m)
#define test_struct_targetSequenceCreate_auto(_id, m) test_struct_targetSequence* _id = test_struct_targetSequenceCreate(m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_targetSequenceCreateChild test_struct_targetSequenceCreateChild
#endif
TEST_EXPORT test_struct_targetSequence* _test_struct_targetSequenceCreateChild(corto_object _parent, corto_string _id, test_IntSequence m);
#define test_struct_targetSequenceCreateChild(_parent, _id, m) _test_struct_targetSequenceCreateChild(_parent, _id, m)
#define test_struct_targetSequenceCreateChild_auto(_parent, _id, m) test_struct_targetSequence* _id = test_struct_targetSequenceCreateChild(_parent, #_id, m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_targetSequenceUpdate test_struct_targetSequenceUpdate
#endif
TEST_EXPORT corto_int16 _test_struct_targetSequenceUpdate(test_struct_targetSequence* _this, test_IntSequence m);
#define test_struct_targetSequenceUpdate(_this, m) _test_struct_targetSequenceUpdate(test_struct_targetSequence(_this), m)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_targetSequenceDeclare test_struct_targetSequenceDeclare
#endif
TEST_EXPORT test_struct_targetSequence* _test_struct_targetSequenceDeclare(void);
#define test_struct_targetSequenceDeclare() _test_struct_targetSequenceDeclare()
#define test_struct_targetSequenceDeclare_auto(_id) test_struct_targetSequence* _id = test_struct_targetSequenceDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_targetSequenceDeclareChild test_struct_targetSequenceDeclareChild
#endif
TEST_EXPORT test_struct_targetSequence* _test_struct_targetSequenceDeclareChild(corto_object _parent, corto_string _id);
#define test_struct_targetSequenceDeclareChild(_parent, _id) _test_struct_targetSequenceDeclareChild(_parent, _id)
#define test_struct_targetSequenceDeclareChild_auto(_parent, _id) test_struct_targetSequence* _id = test_struct_targetSequenceDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_targetSequenceDefine test_struct_targetSequenceDefine
#endif
TEST_EXPORT corto_int16 _test_struct_targetSequenceDefine(test_struct_targetSequence* _this, test_IntSequence m);
#define test_struct_targetSequenceDefine(_this, m) _test_struct_targetSequenceDefine(test_struct_targetSequence(_this), m)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_targetSequenceAssign test_struct_targetSequenceAssign
#endif
TEST_EXPORT test_struct_targetSequence* _test_struct_targetSequenceAssign(test_struct_targetSequence* _this, test_IntSequence m);
#define test_struct_targetSequence__optional_NotSet NULL
#define test_struct_targetSequence__optional_Set(m) test_struct_targetSequenceAssign((test_struct_targetSequence*)corto_ptr_new(test_struct_targetSequence_o)), m)
#define test_struct_targetSequence__optional_SetCond(cond, m) cond ? test_struct_targetSequenceAssign((test_struct_targetSequence*)corto_ptr_new(test_struct_targetSequence_o), m) : NULL
#define test_struct_targetSequenceUnset(_this) _this ? corto_ptr_free(_this, test_struct_targetSequence_o), 0 : 0; _this = NULL;
#define test_struct_targetSequenceAssign(_this, m) _test_struct_targetSequenceAssign(_this, m)
#define test_struct_targetSequenceSet(_this, m) _this = _this ? _this : (test_struct_targetSequence*)corto_ptr_new(test_struct_targetSequence_o); _test_struct_targetSequenceAssign(_this, m)

/* /test/struct_targetString */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_targetStringCreate test_struct_targetStringCreate
#endif
TEST_EXPORT test_struct_targetString* _test_struct_targetStringCreate(corto_string m);
#define test_struct_targetStringCreate(m) _test_struct_targetStringCreate(m)
#define test_struct_targetStringCreate_auto(_id, m) test_struct_targetString* _id = test_struct_targetStringCreate(m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_targetStringCreateChild test_struct_targetStringCreateChild
#endif
TEST_EXPORT test_struct_targetString* _test_struct_targetStringCreateChild(corto_object _parent, corto_string _id, corto_string m);
#define test_struct_targetStringCreateChild(_parent, _id, m) _test_struct_targetStringCreateChild(_parent, _id, m)
#define test_struct_targetStringCreateChild_auto(_parent, _id, m) test_struct_targetString* _id = test_struct_targetStringCreateChild(_parent, #_id, m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_targetStringUpdate test_struct_targetStringUpdate
#endif
TEST_EXPORT corto_int16 _test_struct_targetStringUpdate(test_struct_targetString* _this, corto_string m);
#define test_struct_targetStringUpdate(_this, m) _test_struct_targetStringUpdate(test_struct_targetString(_this), m)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_targetStringDeclare test_struct_targetStringDeclare
#endif
TEST_EXPORT test_struct_targetString* _test_struct_targetStringDeclare(void);
#define test_struct_targetStringDeclare() _test_struct_targetStringDeclare()
#define test_struct_targetStringDeclare_auto(_id) test_struct_targetString* _id = test_struct_targetStringDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_targetStringDeclareChild test_struct_targetStringDeclareChild
#endif
TEST_EXPORT test_struct_targetString* _test_struct_targetStringDeclareChild(corto_object _parent, corto_string _id);
#define test_struct_targetStringDeclareChild(_parent, _id) _test_struct_targetStringDeclareChild(_parent, _id)
#define test_struct_targetStringDeclareChild_auto(_parent, _id) test_struct_targetString* _id = test_struct_targetStringDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_targetStringDefine test_struct_targetStringDefine
#endif
TEST_EXPORT corto_int16 _test_struct_targetStringDefine(test_struct_targetString* _this, corto_string m);
#define test_struct_targetStringDefine(_this, m) _test_struct_targetStringDefine(test_struct_targetString(_this), m)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_targetStringAssign test_struct_targetStringAssign
#endif
TEST_EXPORT test_struct_targetString* _test_struct_targetStringAssign(test_struct_targetString* _this, corto_string m);
#define test_struct_targetString__optional_NotSet NULL
#define test_struct_targetString__optional_Set(m) test_struct_targetStringAssign((test_struct_targetString*)corto_ptr_new(test_struct_targetString_o)), m)
#define test_struct_targetString__optional_SetCond(cond, m) cond ? test_struct_targetStringAssign((test_struct_targetString*)corto_ptr_new(test_struct_targetString_o), m) : NULL
#define test_struct_targetStringUnset(_this) _this ? corto_ptr_free(_this, test_struct_targetString_o), 0 : 0; _this = NULL;
#define test_struct_targetStringAssign(_this, m) _test_struct_targetStringAssign(_this, m)
#define test_struct_targetStringSet(_this, m) _this = _this ? _this : (test_struct_targetString*)corto_ptr_new(test_struct_targetString_o); _test_struct_targetStringAssign(_this, m)

/* /test/struct_targetStruct */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_targetStructCreate test_struct_targetStructCreate
#endif
TEST_EXPORT test_struct_targetStruct* _test_struct_targetStructCreate(test_Point* m);
#define test_struct_targetStructCreate(m) _test_struct_targetStructCreate(m)
#define test_struct_targetStructCreate_auto(_id, m) test_struct_targetStruct* _id = test_struct_targetStructCreate(m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_targetStructCreateChild test_struct_targetStructCreateChild
#endif
TEST_EXPORT test_struct_targetStruct* _test_struct_targetStructCreateChild(corto_object _parent, corto_string _id, test_Point* m);
#define test_struct_targetStructCreateChild(_parent, _id, m) _test_struct_targetStructCreateChild(_parent, _id, m)
#define test_struct_targetStructCreateChild_auto(_parent, _id, m) test_struct_targetStruct* _id = test_struct_targetStructCreateChild(_parent, #_id, m); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_targetStructUpdate test_struct_targetStructUpdate
#endif
TEST_EXPORT corto_int16 _test_struct_targetStructUpdate(test_struct_targetStruct* _this, test_Point* m);
#define test_struct_targetStructUpdate(_this, m) _test_struct_targetStructUpdate(test_struct_targetStruct(_this), m)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_targetStructDeclare test_struct_targetStructDeclare
#endif
TEST_EXPORT test_struct_targetStruct* _test_struct_targetStructDeclare(void);
#define test_struct_targetStructDeclare() _test_struct_targetStructDeclare()
#define test_struct_targetStructDeclare_auto(_id) test_struct_targetStruct* _id = test_struct_targetStructDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_targetStructDeclareChild test_struct_targetStructDeclareChild
#endif
TEST_EXPORT test_struct_targetStruct* _test_struct_targetStructDeclareChild(corto_object _parent, corto_string _id);
#define test_struct_targetStructDeclareChild(_parent, _id) _test_struct_targetStructDeclareChild(_parent, _id)
#define test_struct_targetStructDeclareChild_auto(_parent, _id) test_struct_targetStruct* _id = test_struct_targetStructDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_targetStructDefine test_struct_targetStructDefine
#endif
TEST_EXPORT corto_int16 _test_struct_targetStructDefine(test_struct_targetStruct* _this, test_Point* m);
#define test_struct_targetStructDefine(_this, m) _test_struct_targetStructDefine(test_struct_targetStruct(_this), m)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define struct_targetStructAssign test_struct_targetStructAssign
#endif
TEST_EXPORT test_struct_targetStruct* _test_struct_targetStructAssign(test_struct_targetStruct* _this, test_Point* m);
#define test_struct_targetStruct__optional_NotSet NULL
#define test_struct_targetStruct__optional_Set(m) test_struct_targetStructAssign((test_struct_targetStruct*)corto_ptr_new(test_struct_targetStruct_o)), m)
#define test_struct_targetStruct__optional_SetCond(cond, m) cond ? test_struct_targetStructAssign((test_struct_targetStruct*)corto_ptr_new(test_struct_targetStruct_o), m) : NULL
#define test_struct_targetStructUnset(_this) _this ? corto_ptr_free(_this, test_struct_targetStruct_o), 0 : 0; _this = NULL;
#define test_struct_targetStructAssign(_this, m) _test_struct_targetStructAssign(_this, m)
#define test_struct_targetStructSet(_this, m) _this = _this ? _this : (test_struct_targetStruct*)corto_ptr_new(test_struct_targetStruct_o); _test_struct_targetStructAssign(_this, m)

/* /test/Subscribe */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SubscribeCreate test_SubscribeCreate
#endif
TEST_EXPORT test_Subscribe _test_SubscribeCreate(uint32_t assertCount, uint8_t triggered, corto_object owner, corto_result* result_1);
#define test_SubscribeCreate(assertCount, triggered, owner, result_1) _test_SubscribeCreate(assertCount, triggered, owner, result_1)
#define test_SubscribeCreate_auto(_id, assertCount, triggered, owner, result_1) test_Subscribe _id = test_SubscribeCreate(assertCount, triggered, owner, result_1); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SubscribeCreateChild test_SubscribeCreateChild
#endif
TEST_EXPORT test_Subscribe _test_SubscribeCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount, uint8_t triggered, corto_object owner, corto_result* result_1);
#define test_SubscribeCreateChild(_parent, _id, assertCount, triggered, owner, result_1) _test_SubscribeCreateChild(_parent, _id, assertCount, triggered, owner, result_1)
#define test_SubscribeCreateChild_auto(_parent, _id, assertCount, triggered, owner, result_1) test_Subscribe _id = test_SubscribeCreateChild(_parent, #_id, assertCount, triggered, owner, result_1); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SubscribeUpdate test_SubscribeUpdate
#endif
TEST_EXPORT corto_int16 _test_SubscribeUpdate(test_Subscribe _this, uint32_t assertCount, uint8_t triggered, corto_object owner, corto_result* result_1);
#define test_SubscribeUpdate(_this, assertCount, triggered, owner, result_1) _test_SubscribeUpdate(test_Subscribe(_this), assertCount, triggered, owner, result_1)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SubscribeDeclare test_SubscribeDeclare
#endif
TEST_EXPORT test_Subscribe _test_SubscribeDeclare(void);
#define test_SubscribeDeclare() _test_SubscribeDeclare()
#define test_SubscribeDeclare_auto(_id) test_Subscribe _id = test_SubscribeDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SubscribeDeclareChild test_SubscribeDeclareChild
#endif
TEST_EXPORT test_Subscribe _test_SubscribeDeclareChild(corto_object _parent, corto_string _id);
#define test_SubscribeDeclareChild(_parent, _id) _test_SubscribeDeclareChild(_parent, _id)
#define test_SubscribeDeclareChild_auto(_parent, _id) test_Subscribe _id = test_SubscribeDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SubscribeDefine test_SubscribeDefine
#endif
TEST_EXPORT corto_int16 _test_SubscribeDefine(test_Subscribe _this, uint32_t assertCount, uint8_t triggered, corto_object owner, corto_result* result_1);
#define test_SubscribeDefine(_this, assertCount, triggered, owner, result_1) _test_SubscribeDefine(test_Subscribe(_this), assertCount, triggered, owner, result_1)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SubscribeAssign test_SubscribeAssign
#endif
TEST_EXPORT test_Subscribe _test_SubscribeAssign(test_Subscribe _this, uint32_t assertCount, uint8_t triggered, corto_object owner, corto_result* result_1);
#define test_Subscribe__optional_NotSet NULL
#define test_Subscribe__optional_Set(assertCount, triggered, owner, result_1) test_SubscribeAssign((test_Subscribe*)corto_ptr_new(test_Subscribe_o)), assertCount, triggered, owner, result_1)
#define test_Subscribe__optional_SetCond(cond, assertCount, triggered, owner, result_1) cond ? test_SubscribeAssign((test_Subscribe*)corto_ptr_new(test_Subscribe_o), assertCount, triggered, owner, result_1) : NULL
#define test_SubscribeUnset(_this) _this ? corto_ptr_free(_this, test_Subscribe_o), 0 : 0; _this = NULL;
#define test_SubscribeAssign(_this, assertCount, triggered, owner, result_1) _test_SubscribeAssign(_this, assertCount, triggered, owner, result_1)
#define test_SubscribeSet(_this, assertCount, triggered, owner, result_1) _this = _this ? _this : (test_Subscribe*)corto_ptr_new(test_Subscribe_o); _test_SubscribeAssign(_this, assertCount, triggered, owner, result_1)

/* /test/SubscriberEvent */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SubscriberEventCreate test_SubscriberEventCreate
#endif
TEST_EXPORT test_SubscriberEvent _test_SubscriberEventCreate(uint32_t assertCount, corto_attr prevAttr, test_SubscriberTest st);
#define test_SubscriberEventCreate(assertCount, prevAttr, st) _test_SubscriberEventCreate(assertCount, prevAttr, test_SubscriberTest(st))
#define test_SubscriberEventCreate_auto(_id, assertCount, prevAttr, st) test_SubscriberEvent _id = test_SubscriberEventCreate(assertCount, prevAttr, st); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SubscriberEventCreateChild test_SubscriberEventCreateChild
#endif
TEST_EXPORT test_SubscriberEvent _test_SubscriberEventCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount, corto_attr prevAttr, test_SubscriberTest st);
#define test_SubscriberEventCreateChild(_parent, _id, assertCount, prevAttr, st) _test_SubscriberEventCreateChild(_parent, _id, assertCount, prevAttr, test_SubscriberTest(st))
#define test_SubscriberEventCreateChild_auto(_parent, _id, assertCount, prevAttr, st) test_SubscriberEvent _id = test_SubscriberEventCreateChild(_parent, #_id, assertCount, prevAttr, st); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SubscriberEventUpdate test_SubscriberEventUpdate
#endif
TEST_EXPORT corto_int16 _test_SubscriberEventUpdate(test_SubscriberEvent _this, uint32_t assertCount, corto_attr prevAttr, test_SubscriberTest st);
#define test_SubscriberEventUpdate(_this, assertCount, prevAttr, st) _test_SubscriberEventUpdate(test_SubscriberEvent(_this), assertCount, prevAttr, test_SubscriberTest(st))


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SubscriberEventDeclare test_SubscriberEventDeclare
#endif
TEST_EXPORT test_SubscriberEvent _test_SubscriberEventDeclare(void);
#define test_SubscriberEventDeclare() _test_SubscriberEventDeclare()
#define test_SubscriberEventDeclare_auto(_id) test_SubscriberEvent _id = test_SubscriberEventDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SubscriberEventDeclareChild test_SubscriberEventDeclareChild
#endif
TEST_EXPORT test_SubscriberEvent _test_SubscriberEventDeclareChild(corto_object _parent, corto_string _id);
#define test_SubscriberEventDeclareChild(_parent, _id) _test_SubscriberEventDeclareChild(_parent, _id)
#define test_SubscriberEventDeclareChild_auto(_parent, _id) test_SubscriberEvent _id = test_SubscriberEventDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SubscriberEventDefine test_SubscriberEventDefine
#endif
TEST_EXPORT corto_int16 _test_SubscriberEventDefine(test_SubscriberEvent _this, uint32_t assertCount, corto_attr prevAttr, test_SubscriberTest st);
#define test_SubscriberEventDefine(_this, assertCount, prevAttr, st) _test_SubscriberEventDefine(test_SubscriberEvent(_this), assertCount, prevAttr, test_SubscriberTest(st))

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SubscriberEventAssign test_SubscriberEventAssign
#endif
TEST_EXPORT test_SubscriberEvent _test_SubscriberEventAssign(test_SubscriberEvent _this, uint32_t assertCount, corto_attr prevAttr, test_SubscriberTest st);
#define test_SubscriberEvent__optional_NotSet NULL
#define test_SubscriberEvent__optional_Set(assertCount, prevAttr, st) test_SubscriberEventAssign((test_SubscriberEvent*)corto_ptr_new(test_SubscriberEvent_o)), assertCount, prevAttr, st)
#define test_SubscriberEvent__optional_SetCond(cond, assertCount, prevAttr, st) cond ? test_SubscriberEventAssign((test_SubscriberEvent*)corto_ptr_new(test_SubscriberEvent_o), assertCount, prevAttr, st) : NULL
#define test_SubscriberEventUnset(_this) _this ? corto_ptr_free(_this, test_SubscriberEvent_o), 0 : 0; _this = NULL;
#define test_SubscriberEventAssign(_this, assertCount, prevAttr, st) _test_SubscriberEventAssign(_this, assertCount, prevAttr, test_SubscriberTest(st))
#define test_SubscriberEventSet(_this, assertCount, prevAttr, st) _this = _this ? _this : (test_SubscriberEvent*)corto_ptr_new(test_SubscriberEvent_o); _test_SubscriberEventAssign(_this, assertCount, prevAttr, test_SubscriberTest(st))

/* /test/SubscriberTest */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SubscriberTestCreate test_SubscriberTestCreate
#endif
TEST_EXPORT test_SubscriberTest _test_SubscriberTestCreate(void);
#define test_SubscriberTestCreate() _test_SubscriberTestCreate()
#define test_SubscriberTestCreate_auto(_id) test_SubscriberTest _id = test_SubscriberTestCreate(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SubscriberTestCreateChild test_SubscriberTestCreateChild
#endif
TEST_EXPORT test_SubscriberTest _test_SubscriberTestCreateChild(corto_object _parent, corto_string _id);
#define test_SubscriberTestCreateChild(_parent, _id) _test_SubscriberTestCreateChild(_parent, _id)
#define test_SubscriberTestCreateChild_auto(_parent, _id) test_SubscriberTest _id = test_SubscriberTestCreateChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SubscriberTestUpdate test_SubscriberTestUpdate
#endif
TEST_EXPORT corto_int16 _test_SubscriberTestUpdate(test_SubscriberTest _this);
#define test_SubscriberTestUpdate(_this) _test_SubscriberTestUpdate(test_SubscriberTest(_this))


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SubscriberTestDeclare test_SubscriberTestDeclare
#endif
TEST_EXPORT test_SubscriberTest _test_SubscriberTestDeclare(void);
#define test_SubscriberTestDeclare() _test_SubscriberTestDeclare()
#define test_SubscriberTestDeclare_auto(_id) test_SubscriberTest _id = test_SubscriberTestDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SubscriberTestDeclareChild test_SubscriberTestDeclareChild
#endif
TEST_EXPORT test_SubscriberTest _test_SubscriberTestDeclareChild(corto_object _parent, corto_string _id);
#define test_SubscriberTestDeclareChild(_parent, _id) _test_SubscriberTestDeclareChild(_parent, _id)
#define test_SubscriberTestDeclareChild_auto(_parent, _id) test_SubscriberTest _id = test_SubscriberTestDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SubscriberTestDefine test_SubscriberTestDefine
#endif
TEST_EXPORT corto_int16 _test_SubscriberTestDefine(test_SubscriberTest _this);
#define test_SubscriberTestDefine(_this) _test_SubscriberTestDefine(test_SubscriberTest(_this))

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SubscriberTestAssign test_SubscriberTestAssign
#endif
TEST_EXPORT test_SubscriberTest _test_SubscriberTestAssign(test_SubscriberTest _this);
#define test_SubscriberTest__optional_NotSet NULL
#define test_SubscriberTest__optional_Set() test_SubscriberTestAssign((test_SubscriberTest*)corto_ptr_new(test_SubscriberTest_o)))
#define test_SubscriberTest__optional_SetCond(cond) cond ? test_SubscriberTestAssign((test_SubscriberTest*)corto_ptr_new(test_SubscriberTest_o)) : NULL
#define test_SubscriberTestUnset(_this) _this ? corto_ptr_free(_this, test_SubscriberTest_o), 0 : 0; _this = NULL;
#define test_SubscriberTestAssign(_this) _test_SubscriberTestAssign(_this)
#define test_SubscriberTestSet(_this) _this = _this ? _this : (test_SubscriberTest*)corto_ptr_new(test_SubscriberTest_o); _test_SubscriberTestAssign(_this)

/* /test/TableMultiKey */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableMultiKeyCreate test_TableMultiKeyCreate
#endif
TEST_EXPORT test_TableMultiKey _test_TableMultiKeyCreate(corto_string value);
#define test_TableMultiKeyCreate(value) _test_TableMultiKeyCreate(value)
#define test_TableMultiKeyCreate_auto(_id, value) test_TableMultiKey _id = test_TableMultiKeyCreate(value); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableMultiKeyCreateChild test_TableMultiKeyCreateChild
#endif
TEST_EXPORT test_TableMultiKey _test_TableMultiKeyCreateChild(corto_object _parent, corto_string _id, corto_string value);
#define test_TableMultiKeyCreateChild(_parent, _id, value) _test_TableMultiKeyCreateChild(_parent, _id, value)
#define test_TableMultiKeyCreateChild_auto(_parent, _id, value) test_TableMultiKey _id = test_TableMultiKeyCreateChild(_parent, #_id, value); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableMultiKeyUpdate test_TableMultiKeyUpdate
#endif
TEST_EXPORT corto_int16 _test_TableMultiKeyUpdate(test_TableMultiKey _this, corto_string value);
#define test_TableMultiKeyUpdate(_this, value) _test_TableMultiKeyUpdate(test_TableMultiKey(_this), value)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableMultiKeyDeclare test_TableMultiKeyDeclare
#endif
TEST_EXPORT test_TableMultiKey _test_TableMultiKeyDeclare(void);
#define test_TableMultiKeyDeclare() _test_TableMultiKeyDeclare()
#define test_TableMultiKeyDeclare_auto(_id) test_TableMultiKey _id = test_TableMultiKeyDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableMultiKeyDeclareChild test_TableMultiKeyDeclareChild
#endif
TEST_EXPORT test_TableMultiKey _test_TableMultiKeyDeclareChild(corto_object _parent, corto_string _id);
#define test_TableMultiKeyDeclareChild(_parent, _id) _test_TableMultiKeyDeclareChild(_parent, _id)
#define test_TableMultiKeyDeclareChild_auto(_parent, _id) test_TableMultiKey _id = test_TableMultiKeyDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableMultiKeyDefine test_TableMultiKeyDefine
#endif
TEST_EXPORT corto_int16 _test_TableMultiKeyDefine(test_TableMultiKey _this, corto_string value);
#define test_TableMultiKeyDefine(_this, value) _test_TableMultiKeyDefine(test_TableMultiKey(_this), value)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableMultiKeyAssign test_TableMultiKeyAssign
#endif
TEST_EXPORT test_TableMultiKey _test_TableMultiKeyAssign(test_TableMultiKey _this, corto_string value);
#define test_TableMultiKey__optional_NotSet NULL
#define test_TableMultiKey__optional_Set(value) test_TableMultiKeyAssign((test_TableMultiKey*)corto_ptr_new(test_TableMultiKey_o)), value)
#define test_TableMultiKey__optional_SetCond(cond, value) cond ? test_TableMultiKeyAssign((test_TableMultiKey*)corto_ptr_new(test_TableMultiKey_o), value) : NULL
#define test_TableMultiKeyUnset(_this) _this ? corto_ptr_free(_this, test_TableMultiKey_o), 0 : 0; _this = NULL;
#define test_TableMultiKeyAssign(_this, value) _test_TableMultiKeyAssign(_this, value)
#define test_TableMultiKeySet(_this, value) _this = _this ? _this : (test_TableMultiKey*)corto_ptr_new(test_TableMultiKey_o); _test_TableMultiKeyAssign(_this, value)

/* /test/TableMultiMixedKey */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableMultiMixedKeyCreate test_TableMultiMixedKeyCreate
#endif
TEST_EXPORT test_TableMultiMixedKey _test_TableMultiMixedKeyCreate(corto_string value);
#define test_TableMultiMixedKeyCreate(value) _test_TableMultiMixedKeyCreate(value)
#define test_TableMultiMixedKeyCreate_auto(_id, value) test_TableMultiMixedKey _id = test_TableMultiMixedKeyCreate(value); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableMultiMixedKeyCreateChild test_TableMultiMixedKeyCreateChild
#endif
TEST_EXPORT test_TableMultiMixedKey _test_TableMultiMixedKeyCreateChild(corto_object _parent, corto_string _id, corto_string value);
#define test_TableMultiMixedKeyCreateChild(_parent, _id, value) _test_TableMultiMixedKeyCreateChild(_parent, _id, value)
#define test_TableMultiMixedKeyCreateChild_auto(_parent, _id, value) test_TableMultiMixedKey _id = test_TableMultiMixedKeyCreateChild(_parent, #_id, value); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableMultiMixedKeyUpdate test_TableMultiMixedKeyUpdate
#endif
TEST_EXPORT corto_int16 _test_TableMultiMixedKeyUpdate(test_TableMultiMixedKey _this, corto_string value);
#define test_TableMultiMixedKeyUpdate(_this, value) _test_TableMultiMixedKeyUpdate(test_TableMultiMixedKey(_this), value)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableMultiMixedKeyDeclare test_TableMultiMixedKeyDeclare
#endif
TEST_EXPORT test_TableMultiMixedKey _test_TableMultiMixedKeyDeclare(void);
#define test_TableMultiMixedKeyDeclare() _test_TableMultiMixedKeyDeclare()
#define test_TableMultiMixedKeyDeclare_auto(_id) test_TableMultiMixedKey _id = test_TableMultiMixedKeyDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableMultiMixedKeyDeclareChild test_TableMultiMixedKeyDeclareChild
#endif
TEST_EXPORT test_TableMultiMixedKey _test_TableMultiMixedKeyDeclareChild(corto_object _parent, corto_string _id);
#define test_TableMultiMixedKeyDeclareChild(_parent, _id) _test_TableMultiMixedKeyDeclareChild(_parent, _id)
#define test_TableMultiMixedKeyDeclareChild_auto(_parent, _id) test_TableMultiMixedKey _id = test_TableMultiMixedKeyDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableMultiMixedKeyDefine test_TableMultiMixedKeyDefine
#endif
TEST_EXPORT corto_int16 _test_TableMultiMixedKeyDefine(test_TableMultiMixedKey _this, corto_string value);
#define test_TableMultiMixedKeyDefine(_this, value) _test_TableMultiMixedKeyDefine(test_TableMultiMixedKey(_this), value)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableMultiMixedKeyAssign test_TableMultiMixedKeyAssign
#endif
TEST_EXPORT test_TableMultiMixedKey _test_TableMultiMixedKeyAssign(test_TableMultiMixedKey _this, corto_string value);
#define test_TableMultiMixedKey__optional_NotSet NULL
#define test_TableMultiMixedKey__optional_Set(value) test_TableMultiMixedKeyAssign((test_TableMultiMixedKey*)corto_ptr_new(test_TableMultiMixedKey_o)), value)
#define test_TableMultiMixedKey__optional_SetCond(cond, value) cond ? test_TableMultiMixedKeyAssign((test_TableMultiMixedKey*)corto_ptr_new(test_TableMultiMixedKey_o), value) : NULL
#define test_TableMultiMixedKeyUnset(_this) _this ? corto_ptr_free(_this, test_TableMultiMixedKey_o), 0 : 0; _this = NULL;
#define test_TableMultiMixedKeyAssign(_this, value) _test_TableMultiMixedKeyAssign(_this, value)
#define test_TableMultiMixedKeySet(_this, value) _this = _this ? _this : (test_TableMultiMixedKey*)corto_ptr_new(test_TableMultiMixedKey_o); _test_TableMultiMixedKeyAssign(_this, value)

/* /test/TableMultiStringKey */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableMultiStringKeyCreate test_TableMultiStringKeyCreate
#endif
TEST_EXPORT test_TableMultiStringKey _test_TableMultiStringKeyCreate(corto_string value);
#define test_TableMultiStringKeyCreate(value) _test_TableMultiStringKeyCreate(value)
#define test_TableMultiStringKeyCreate_auto(_id, value) test_TableMultiStringKey _id = test_TableMultiStringKeyCreate(value); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableMultiStringKeyCreateChild test_TableMultiStringKeyCreateChild
#endif
TEST_EXPORT test_TableMultiStringKey _test_TableMultiStringKeyCreateChild(corto_object _parent, corto_string _id, corto_string value);
#define test_TableMultiStringKeyCreateChild(_parent, _id, value) _test_TableMultiStringKeyCreateChild(_parent, _id, value)
#define test_TableMultiStringKeyCreateChild_auto(_parent, _id, value) test_TableMultiStringKey _id = test_TableMultiStringKeyCreateChild(_parent, #_id, value); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableMultiStringKeyUpdate test_TableMultiStringKeyUpdate
#endif
TEST_EXPORT corto_int16 _test_TableMultiStringKeyUpdate(test_TableMultiStringKey _this, corto_string value);
#define test_TableMultiStringKeyUpdate(_this, value) _test_TableMultiStringKeyUpdate(test_TableMultiStringKey(_this), value)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableMultiStringKeyDeclare test_TableMultiStringKeyDeclare
#endif
TEST_EXPORT test_TableMultiStringKey _test_TableMultiStringKeyDeclare(void);
#define test_TableMultiStringKeyDeclare() _test_TableMultiStringKeyDeclare()
#define test_TableMultiStringKeyDeclare_auto(_id) test_TableMultiStringKey _id = test_TableMultiStringKeyDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableMultiStringKeyDeclareChild test_TableMultiStringKeyDeclareChild
#endif
TEST_EXPORT test_TableMultiStringKey _test_TableMultiStringKeyDeclareChild(corto_object _parent, corto_string _id);
#define test_TableMultiStringKeyDeclareChild(_parent, _id) _test_TableMultiStringKeyDeclareChild(_parent, _id)
#define test_TableMultiStringKeyDeclareChild_auto(_parent, _id) test_TableMultiStringKey _id = test_TableMultiStringKeyDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableMultiStringKeyDefine test_TableMultiStringKeyDefine
#endif
TEST_EXPORT corto_int16 _test_TableMultiStringKeyDefine(test_TableMultiStringKey _this, corto_string value);
#define test_TableMultiStringKeyDefine(_this, value) _test_TableMultiStringKeyDefine(test_TableMultiStringKey(_this), value)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableMultiStringKeyAssign test_TableMultiStringKeyAssign
#endif
TEST_EXPORT test_TableMultiStringKey _test_TableMultiStringKeyAssign(test_TableMultiStringKey _this, corto_string value);
#define test_TableMultiStringKey__optional_NotSet NULL
#define test_TableMultiStringKey__optional_Set(value) test_TableMultiStringKeyAssign((test_TableMultiStringKey*)corto_ptr_new(test_TableMultiStringKey_o)), value)
#define test_TableMultiStringKey__optional_SetCond(cond, value) cond ? test_TableMultiStringKeyAssign((test_TableMultiStringKey*)corto_ptr_new(test_TableMultiStringKey_o), value) : NULL
#define test_TableMultiStringKeyUnset(_this) _this ? corto_ptr_free(_this, test_TableMultiStringKey_o), 0 : 0; _this = NULL;
#define test_TableMultiStringKeyAssign(_this, value) _test_TableMultiStringKeyAssign(_this, value)
#define test_TableMultiStringKeySet(_this, value) _this = _this ? _this : (test_TableMultiStringKey*)corto_ptr_new(test_TableMultiStringKey_o); _test_TableMultiStringKeyAssign(_this, value)

/* /test/TableNested */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableNestedCreate test_TableNestedCreate
#endif
TEST_EXPORT test_TableNested _test_TableNestedCreate(corto_string value);
#define test_TableNestedCreate(value) _test_TableNestedCreate(value)
#define test_TableNestedCreate_auto(_id, value) test_TableNested _id = test_TableNestedCreate(value); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableNestedCreateChild test_TableNestedCreateChild
#endif
TEST_EXPORT test_TableNested _test_TableNestedCreateChild(corto_object _parent, corto_string _id, corto_string value);
#define test_TableNestedCreateChild(_parent, _id, value) _test_TableNestedCreateChild(_parent, _id, value)
#define test_TableNestedCreateChild_auto(_parent, _id, value) test_TableNested _id = test_TableNestedCreateChild(_parent, #_id, value); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableNestedUpdate test_TableNestedUpdate
#endif
TEST_EXPORT corto_int16 _test_TableNestedUpdate(test_TableNested _this, corto_string value);
#define test_TableNestedUpdate(_this, value) _test_TableNestedUpdate(test_TableNested(_this), value)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableNestedDeclare test_TableNestedDeclare
#endif
TEST_EXPORT test_TableNested _test_TableNestedDeclare(void);
#define test_TableNestedDeclare() _test_TableNestedDeclare()
#define test_TableNestedDeclare_auto(_id) test_TableNested _id = test_TableNestedDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableNestedDeclareChild test_TableNestedDeclareChild
#endif
TEST_EXPORT test_TableNested _test_TableNestedDeclareChild(corto_object _parent, corto_string _id);
#define test_TableNestedDeclareChild(_parent, _id) _test_TableNestedDeclareChild(_parent, _id)
#define test_TableNestedDeclareChild_auto(_parent, _id) test_TableNested _id = test_TableNestedDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableNestedDefine test_TableNestedDefine
#endif
TEST_EXPORT corto_int16 _test_TableNestedDefine(test_TableNested _this, corto_string value);
#define test_TableNestedDefine(_this, value) _test_TableNestedDefine(test_TableNested(_this), value)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableNestedAssign test_TableNestedAssign
#endif
TEST_EXPORT test_TableNested _test_TableNestedAssign(test_TableNested _this, corto_string value);
#define test_TableNested__optional_NotSet NULL
#define test_TableNested__optional_Set(value) test_TableNestedAssign((test_TableNested*)corto_ptr_new(test_TableNested_o)), value)
#define test_TableNested__optional_SetCond(cond, value) cond ? test_TableNestedAssign((test_TableNested*)corto_ptr_new(test_TableNested_o), value) : NULL
#define test_TableNestedUnset(_this) _this ? corto_ptr_free(_this, test_TableNested_o), 0 : 0; _this = NULL;
#define test_TableNestedAssign(_this, value) _test_TableNestedAssign(_this, value)
#define test_TableNestedSet(_this, value) _this = _this ? _this : (test_TableNested*)corto_ptr_new(test_TableNested_o); _test_TableNestedAssign(_this, value)

/* /test/TableNested/ChildTable */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableNested_ChildTableCreate test_TableNested_ChildTableCreate
#endif
TEST_EXPORT test_TableNested_ChildTable _test_TableNested_ChildTableCreate(corto_string value);
#define test_TableNested_ChildTableCreate(value) _test_TableNested_ChildTableCreate(value)
#define test_TableNested_ChildTableCreate_auto(_id, value) test_TableNested_ChildTable _id = test_TableNested_ChildTableCreate(value); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableNested_ChildTableCreateChild test_TableNested_ChildTableCreateChild
#endif
TEST_EXPORT test_TableNested_ChildTable _test_TableNested_ChildTableCreateChild(corto_object _parent, corto_string _id, corto_string value);
#define test_TableNested_ChildTableCreateChild(_parent, _id, value) _test_TableNested_ChildTableCreateChild(_parent, _id, value)
#define test_TableNested_ChildTableCreateChild_auto(_parent, _id, value) test_TableNested_ChildTable _id = test_TableNested_ChildTableCreateChild(_parent, #_id, value); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableNested_ChildTableUpdate test_TableNested_ChildTableUpdate
#endif
TEST_EXPORT corto_int16 _test_TableNested_ChildTableUpdate(test_TableNested_ChildTable _this, corto_string value);
#define test_TableNested_ChildTableUpdate(_this, value) _test_TableNested_ChildTableUpdate(test_TableNested_ChildTable(_this), value)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableNested_ChildTableDeclare test_TableNested_ChildTableDeclare
#endif
TEST_EXPORT test_TableNested_ChildTable _test_TableNested_ChildTableDeclare(void);
#define test_TableNested_ChildTableDeclare() _test_TableNested_ChildTableDeclare()
#define test_TableNested_ChildTableDeclare_auto(_id) test_TableNested_ChildTable _id = test_TableNested_ChildTableDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableNested_ChildTableDeclareChild test_TableNested_ChildTableDeclareChild
#endif
TEST_EXPORT test_TableNested_ChildTable _test_TableNested_ChildTableDeclareChild(corto_object _parent, corto_string _id);
#define test_TableNested_ChildTableDeclareChild(_parent, _id) _test_TableNested_ChildTableDeclareChild(_parent, _id)
#define test_TableNested_ChildTableDeclareChild_auto(_parent, _id) test_TableNested_ChildTable _id = test_TableNested_ChildTableDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableNested_ChildTableDefine test_TableNested_ChildTableDefine
#endif
TEST_EXPORT corto_int16 _test_TableNested_ChildTableDefine(test_TableNested_ChildTable _this, corto_string value);
#define test_TableNested_ChildTableDefine(_this, value) _test_TableNested_ChildTableDefine(test_TableNested_ChildTable(_this), value)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableNested_ChildTableAssign test_TableNested_ChildTableAssign
#endif
TEST_EXPORT test_TableNested_ChildTable _test_TableNested_ChildTableAssign(test_TableNested_ChildTable _this, corto_string value);
#define test_TableNested_ChildTable__optional_NotSet NULL
#define test_TableNested_ChildTable__optional_Set(value) test_TableNested_ChildTableAssign((test_TableNested_ChildTable*)corto_ptr_new(test_TableNested_ChildTable_o)), value)
#define test_TableNested_ChildTable__optional_SetCond(cond, value) cond ? test_TableNested_ChildTableAssign((test_TableNested_ChildTable*)corto_ptr_new(test_TableNested_ChildTable_o), value) : NULL
#define test_TableNested_ChildTableUnset(_this) _this ? corto_ptr_free(_this, test_TableNested_ChildTable_o), 0 : 0; _this = NULL;
#define test_TableNested_ChildTableAssign(_this, value) _test_TableNested_ChildTableAssign(_this, value)
#define test_TableNested_ChildTableSet(_this, value) _this = _this ? _this : (test_TableNested_ChildTable*)corto_ptr_new(test_TableNested_ChildTable_o); _test_TableNested_ChildTableAssign(_this, value)

/* /test/TableNestedContainer */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableNestedContainerCreate test_TableNestedContainerCreate
#endif
TEST_EXPORT test_TableNestedContainer _test_TableNestedContainerCreate(corto_string value);
#define test_TableNestedContainerCreate(value) _test_TableNestedContainerCreate(value)
#define test_TableNestedContainerCreate_auto(_id, value) test_TableNestedContainer _id = test_TableNestedContainerCreate(value); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableNestedContainerCreateChild test_TableNestedContainerCreateChild
#endif
TEST_EXPORT test_TableNestedContainer _test_TableNestedContainerCreateChild(corto_object _parent, corto_string _id, corto_string value);
#define test_TableNestedContainerCreateChild(_parent, _id, value) _test_TableNestedContainerCreateChild(_parent, _id, value)
#define test_TableNestedContainerCreateChild_auto(_parent, _id, value) test_TableNestedContainer _id = test_TableNestedContainerCreateChild(_parent, #_id, value); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableNestedContainerUpdate test_TableNestedContainerUpdate
#endif
TEST_EXPORT corto_int16 _test_TableNestedContainerUpdate(test_TableNestedContainer _this, corto_string value);
#define test_TableNestedContainerUpdate(_this, value) _test_TableNestedContainerUpdate(test_TableNestedContainer(_this), value)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableNestedContainerDeclare test_TableNestedContainerDeclare
#endif
TEST_EXPORT test_TableNestedContainer _test_TableNestedContainerDeclare(void);
#define test_TableNestedContainerDeclare() _test_TableNestedContainerDeclare()
#define test_TableNestedContainerDeclare_auto(_id) test_TableNestedContainer _id = test_TableNestedContainerDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableNestedContainerDeclareChild test_TableNestedContainerDeclareChild
#endif
TEST_EXPORT test_TableNestedContainer _test_TableNestedContainerDeclareChild(corto_object _parent, corto_string _id);
#define test_TableNestedContainerDeclareChild(_parent, _id) _test_TableNestedContainerDeclareChild(_parent, _id)
#define test_TableNestedContainerDeclareChild_auto(_parent, _id) test_TableNestedContainer _id = test_TableNestedContainerDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableNestedContainerDefine test_TableNestedContainerDefine
#endif
TEST_EXPORT corto_int16 _test_TableNestedContainerDefine(test_TableNestedContainer _this, corto_string value);
#define test_TableNestedContainerDefine(_this, value) _test_TableNestedContainerDefine(test_TableNestedContainer(_this), value)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableNestedContainerAssign test_TableNestedContainerAssign
#endif
TEST_EXPORT test_TableNestedContainer _test_TableNestedContainerAssign(test_TableNestedContainer _this, corto_string value);
#define test_TableNestedContainer__optional_NotSet NULL
#define test_TableNestedContainer__optional_Set(value) test_TableNestedContainerAssign((test_TableNestedContainer*)corto_ptr_new(test_TableNestedContainer_o)), value)
#define test_TableNestedContainer__optional_SetCond(cond, value) cond ? test_TableNestedContainerAssign((test_TableNestedContainer*)corto_ptr_new(test_TableNestedContainer_o), value) : NULL
#define test_TableNestedContainerUnset(_this) _this ? corto_ptr_free(_this, test_TableNestedContainer_o), 0 : 0; _this = NULL;
#define test_TableNestedContainerAssign(_this, value) _test_TableNestedContainerAssign(_this, value)
#define test_TableNestedContainerSet(_this, value) _this = _this ? _this : (test_TableNestedContainer*)corto_ptr_new(test_TableNestedContainer_o); _test_TableNestedContainerAssign(_this, value)

/* /test/TableNestedContainer/ChildContainer */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableNestedContainer_ChildContainerCreate test_TableNestedContainer_ChildContainerCreate
#endif
TEST_EXPORT test_TableNestedContainer_ChildContainer _test_TableNestedContainer_ChildContainerCreate(int32_t id, corto_string value);
#define test_TableNestedContainer_ChildContainerCreate(id, value) _test_TableNestedContainer_ChildContainerCreate(id, value)
#define test_TableNestedContainer_ChildContainerCreate_auto(_id, id, value) test_TableNestedContainer_ChildContainer _id = test_TableNestedContainer_ChildContainerCreate(id, value); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableNestedContainer_ChildContainerCreateChild test_TableNestedContainer_ChildContainerCreateChild
#endif
TEST_EXPORT test_TableNestedContainer_ChildContainer _test_TableNestedContainer_ChildContainerCreateChild(corto_object _parent, corto_string _id, int32_t id, corto_string value);
#define test_TableNestedContainer_ChildContainerCreateChild(_parent, _id, id, value) _test_TableNestedContainer_ChildContainerCreateChild(_parent, _id, id, value)
#define test_TableNestedContainer_ChildContainerCreateChild_auto(_parent, _id, id, value) test_TableNestedContainer_ChildContainer _id = test_TableNestedContainer_ChildContainerCreateChild(_parent, #_id, id, value); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableNestedContainer_ChildContainerUpdate test_TableNestedContainer_ChildContainerUpdate
#endif
TEST_EXPORT corto_int16 _test_TableNestedContainer_ChildContainerUpdate(test_TableNestedContainer_ChildContainer _this, int32_t id, corto_string value);
#define test_TableNestedContainer_ChildContainerUpdate(_this, id, value) _test_TableNestedContainer_ChildContainerUpdate(test_TableNestedContainer_ChildContainer(_this), id, value)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableNestedContainer_ChildContainerDeclare test_TableNestedContainer_ChildContainerDeclare
#endif
TEST_EXPORT test_TableNestedContainer_ChildContainer _test_TableNestedContainer_ChildContainerDeclare(void);
#define test_TableNestedContainer_ChildContainerDeclare() _test_TableNestedContainer_ChildContainerDeclare()
#define test_TableNestedContainer_ChildContainerDeclare_auto(_id) test_TableNestedContainer_ChildContainer _id = test_TableNestedContainer_ChildContainerDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableNestedContainer_ChildContainerDeclareChild test_TableNestedContainer_ChildContainerDeclareChild
#endif
TEST_EXPORT test_TableNestedContainer_ChildContainer _test_TableNestedContainer_ChildContainerDeclareChild(corto_object _parent, corto_string _id);
#define test_TableNestedContainer_ChildContainerDeclareChild(_parent, _id) _test_TableNestedContainer_ChildContainerDeclareChild(_parent, _id)
#define test_TableNestedContainer_ChildContainerDeclareChild_auto(_parent, _id) test_TableNestedContainer_ChildContainer _id = test_TableNestedContainer_ChildContainerDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableNestedContainer_ChildContainerDefine test_TableNestedContainer_ChildContainerDefine
#endif
TEST_EXPORT corto_int16 _test_TableNestedContainer_ChildContainerDefine(test_TableNestedContainer_ChildContainer _this, int32_t id, corto_string value);
#define test_TableNestedContainer_ChildContainerDefine(_this, id, value) _test_TableNestedContainer_ChildContainerDefine(test_TableNestedContainer_ChildContainer(_this), id, value)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableNestedContainer_ChildContainerAssign test_TableNestedContainer_ChildContainerAssign
#endif
TEST_EXPORT test_TableNestedContainer_ChildContainer _test_TableNestedContainer_ChildContainerAssign(test_TableNestedContainer_ChildContainer _this, int32_t id, corto_string value);
#define test_TableNestedContainer_ChildContainer__optional_NotSet NULL
#define test_TableNestedContainer_ChildContainer__optional_Set(id, value) test_TableNestedContainer_ChildContainerAssign((test_TableNestedContainer_ChildContainer*)corto_ptr_new(test_TableNestedContainer_ChildContainer_o)), id, value)
#define test_TableNestedContainer_ChildContainer__optional_SetCond(cond, id, value) cond ? test_TableNestedContainer_ChildContainerAssign((test_TableNestedContainer_ChildContainer*)corto_ptr_new(test_TableNestedContainer_ChildContainer_o), id, value) : NULL
#define test_TableNestedContainer_ChildContainerUnset(_this) _this ? corto_ptr_free(_this, test_TableNestedContainer_ChildContainer_o), 0 : 0; _this = NULL;
#define test_TableNestedContainer_ChildContainerAssign(_this, id, value) _test_TableNestedContainer_ChildContainerAssign(_this, id, value)
#define test_TableNestedContainer_ChildContainerSet(_this, id, value) _this = _this ? _this : (test_TableNestedContainer_ChildContainer*)corto_ptr_new(test_TableNestedContainer_ChildContainer_o); _test_TableNestedContainer_ChildContainerAssign(_this, id, value)

/* /test/TableNestedContainer/ChildContainer/ChildLeaf */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableNestedContainer_ChildContainer_ChildLeafCreate test_TableNestedContainer_ChildContainer_ChildLeafCreate
#endif
TEST_EXPORT test_TableNestedContainer_ChildContainer_ChildLeaf _test_TableNestedContainer_ChildContainer_ChildLeafCreate(int32_t id, corto_string value);
#define test_TableNestedContainer_ChildContainer_ChildLeafCreate(id, value) _test_TableNestedContainer_ChildContainer_ChildLeafCreate(id, value)
#define test_TableNestedContainer_ChildContainer_ChildLeafCreate_auto(_id, id, value) test_TableNestedContainer_ChildContainer_ChildLeaf _id = test_TableNestedContainer_ChildContainer_ChildLeafCreate(id, value); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableNestedContainer_ChildContainer_ChildLeafCreateChild test_TableNestedContainer_ChildContainer_ChildLeafCreateChild
#endif
TEST_EXPORT test_TableNestedContainer_ChildContainer_ChildLeaf _test_TableNestedContainer_ChildContainer_ChildLeafCreateChild(corto_object _parent, corto_string _id, int32_t id, corto_string value);
#define test_TableNestedContainer_ChildContainer_ChildLeafCreateChild(_parent, _id, id, value) _test_TableNestedContainer_ChildContainer_ChildLeafCreateChild(_parent, _id, id, value)
#define test_TableNestedContainer_ChildContainer_ChildLeafCreateChild_auto(_parent, _id, id, value) test_TableNestedContainer_ChildContainer_ChildLeaf _id = test_TableNestedContainer_ChildContainer_ChildLeafCreateChild(_parent, #_id, id, value); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableNestedContainer_ChildContainer_ChildLeafUpdate test_TableNestedContainer_ChildContainer_ChildLeafUpdate
#endif
TEST_EXPORT corto_int16 _test_TableNestedContainer_ChildContainer_ChildLeafUpdate(test_TableNestedContainer_ChildContainer_ChildLeaf _this, int32_t id, corto_string value);
#define test_TableNestedContainer_ChildContainer_ChildLeafUpdate(_this, id, value) _test_TableNestedContainer_ChildContainer_ChildLeafUpdate(test_TableNestedContainer_ChildContainer_ChildLeaf(_this), id, value)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableNestedContainer_ChildContainer_ChildLeafDeclare test_TableNestedContainer_ChildContainer_ChildLeafDeclare
#endif
TEST_EXPORT test_TableNestedContainer_ChildContainer_ChildLeaf _test_TableNestedContainer_ChildContainer_ChildLeafDeclare(void);
#define test_TableNestedContainer_ChildContainer_ChildLeafDeclare() _test_TableNestedContainer_ChildContainer_ChildLeafDeclare()
#define test_TableNestedContainer_ChildContainer_ChildLeafDeclare_auto(_id) test_TableNestedContainer_ChildContainer_ChildLeaf _id = test_TableNestedContainer_ChildContainer_ChildLeafDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableNestedContainer_ChildContainer_ChildLeafDeclareChild test_TableNestedContainer_ChildContainer_ChildLeafDeclareChild
#endif
TEST_EXPORT test_TableNestedContainer_ChildContainer_ChildLeaf _test_TableNestedContainer_ChildContainer_ChildLeafDeclareChild(corto_object _parent, corto_string _id);
#define test_TableNestedContainer_ChildContainer_ChildLeafDeclareChild(_parent, _id) _test_TableNestedContainer_ChildContainer_ChildLeafDeclareChild(_parent, _id)
#define test_TableNestedContainer_ChildContainer_ChildLeafDeclareChild_auto(_parent, _id) test_TableNestedContainer_ChildContainer_ChildLeaf _id = test_TableNestedContainer_ChildContainer_ChildLeafDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableNestedContainer_ChildContainer_ChildLeafDefine test_TableNestedContainer_ChildContainer_ChildLeafDefine
#endif
TEST_EXPORT corto_int16 _test_TableNestedContainer_ChildContainer_ChildLeafDefine(test_TableNestedContainer_ChildContainer_ChildLeaf _this, int32_t id, corto_string value);
#define test_TableNestedContainer_ChildContainer_ChildLeafDefine(_this, id, value) _test_TableNestedContainer_ChildContainer_ChildLeafDefine(test_TableNestedContainer_ChildContainer_ChildLeaf(_this), id, value)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableNestedContainer_ChildContainer_ChildLeafAssign test_TableNestedContainer_ChildContainer_ChildLeafAssign
#endif
TEST_EXPORT test_TableNestedContainer_ChildContainer_ChildLeaf _test_TableNestedContainer_ChildContainer_ChildLeafAssign(test_TableNestedContainer_ChildContainer_ChildLeaf _this, int32_t id, corto_string value);
#define test_TableNestedContainer_ChildContainer_ChildLeaf__optional_NotSet NULL
#define test_TableNestedContainer_ChildContainer_ChildLeaf__optional_Set(id, value) test_TableNestedContainer_ChildContainer_ChildLeafAssign((test_TableNestedContainer_ChildContainer_ChildLeaf*)corto_ptr_new(test_TableNestedContainer_ChildContainer_ChildLeaf_o)), id, value)
#define test_TableNestedContainer_ChildContainer_ChildLeaf__optional_SetCond(cond, id, value) cond ? test_TableNestedContainer_ChildContainer_ChildLeafAssign((test_TableNestedContainer_ChildContainer_ChildLeaf*)corto_ptr_new(test_TableNestedContainer_ChildContainer_ChildLeaf_o), id, value) : NULL
#define test_TableNestedContainer_ChildContainer_ChildLeafUnset(_this) _this ? corto_ptr_free(_this, test_TableNestedContainer_ChildContainer_ChildLeaf_o), 0 : 0; _this = NULL;
#define test_TableNestedContainer_ChildContainer_ChildLeafAssign(_this, id, value) _test_TableNestedContainer_ChildContainer_ChildLeafAssign(_this, id, value)
#define test_TableNestedContainer_ChildContainer_ChildLeafSet(_this, id, value) _this = _this ? _this : (test_TableNestedContainer_ChildContainer_ChildLeaf*)corto_ptr_new(test_TableNestedContainer_ChildContainer_ChildLeaf_o); _test_TableNestedContainer_ChildContainer_ChildLeafAssign(_this, id, value)

/* /test/TableNestedLeafs */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableNestedLeafsCreate test_TableNestedLeafsCreate
#endif
TEST_EXPORT test_TableNestedLeafs _test_TableNestedLeafsCreate(corto_string value);
#define test_TableNestedLeafsCreate(value) _test_TableNestedLeafsCreate(value)
#define test_TableNestedLeafsCreate_auto(_id, value) test_TableNestedLeafs _id = test_TableNestedLeafsCreate(value); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableNestedLeafsCreateChild test_TableNestedLeafsCreateChild
#endif
TEST_EXPORT test_TableNestedLeafs _test_TableNestedLeafsCreateChild(corto_object _parent, corto_string _id, corto_string value);
#define test_TableNestedLeafsCreateChild(_parent, _id, value) _test_TableNestedLeafsCreateChild(_parent, _id, value)
#define test_TableNestedLeafsCreateChild_auto(_parent, _id, value) test_TableNestedLeafs _id = test_TableNestedLeafsCreateChild(_parent, #_id, value); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableNestedLeafsUpdate test_TableNestedLeafsUpdate
#endif
TEST_EXPORT corto_int16 _test_TableNestedLeafsUpdate(test_TableNestedLeafs _this, corto_string value);
#define test_TableNestedLeafsUpdate(_this, value) _test_TableNestedLeafsUpdate(test_TableNestedLeafs(_this), value)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableNestedLeafsDeclare test_TableNestedLeafsDeclare
#endif
TEST_EXPORT test_TableNestedLeafs _test_TableNestedLeafsDeclare(void);
#define test_TableNestedLeafsDeclare() _test_TableNestedLeafsDeclare()
#define test_TableNestedLeafsDeclare_auto(_id) test_TableNestedLeafs _id = test_TableNestedLeafsDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableNestedLeafsDeclareChild test_TableNestedLeafsDeclareChild
#endif
TEST_EXPORT test_TableNestedLeafs _test_TableNestedLeafsDeclareChild(corto_object _parent, corto_string _id);
#define test_TableNestedLeafsDeclareChild(_parent, _id) _test_TableNestedLeafsDeclareChild(_parent, _id)
#define test_TableNestedLeafsDeclareChild_auto(_parent, _id) test_TableNestedLeafs _id = test_TableNestedLeafsDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableNestedLeafsDefine test_TableNestedLeafsDefine
#endif
TEST_EXPORT corto_int16 _test_TableNestedLeafsDefine(test_TableNestedLeafs _this, corto_string value);
#define test_TableNestedLeafsDefine(_this, value) _test_TableNestedLeafsDefine(test_TableNestedLeafs(_this), value)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableNestedLeafsAssign test_TableNestedLeafsAssign
#endif
TEST_EXPORT test_TableNestedLeafs _test_TableNestedLeafsAssign(test_TableNestedLeafs _this, corto_string value);
#define test_TableNestedLeafs__optional_NotSet NULL
#define test_TableNestedLeafs__optional_Set(value) test_TableNestedLeafsAssign((test_TableNestedLeafs*)corto_ptr_new(test_TableNestedLeafs_o)), value)
#define test_TableNestedLeafs__optional_SetCond(cond, value) cond ? test_TableNestedLeafsAssign((test_TableNestedLeafs*)corto_ptr_new(test_TableNestedLeafs_o), value) : NULL
#define test_TableNestedLeafsUnset(_this) _this ? corto_ptr_free(_this, test_TableNestedLeafs_o), 0 : 0; _this = NULL;
#define test_TableNestedLeafsAssign(_this, value) _test_TableNestedLeafsAssign(_this, value)
#define test_TableNestedLeafsSet(_this, value) _this = _this ? _this : (test_TableNestedLeafs*)corto_ptr_new(test_TableNestedLeafs_o); _test_TableNestedLeafsAssign(_this, value)

/* /test/TableNestedLeafs/ChildLeaf1 */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableNestedLeafs_ChildLeaf1Create test_TableNestedLeafs_ChildLeaf1Create
#endif
TEST_EXPORT test_TableNestedLeafs_ChildLeaf1 _test_TableNestedLeafs_ChildLeaf1Create(int32_t id, corto_string value);
#define test_TableNestedLeafs_ChildLeaf1Create(id, value) _test_TableNestedLeafs_ChildLeaf1Create(id, value)
#define test_TableNestedLeafs_ChildLeaf1Create_auto(_id, id, value) test_TableNestedLeafs_ChildLeaf1 _id = test_TableNestedLeafs_ChildLeaf1Create(id, value); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableNestedLeafs_ChildLeaf1CreateChild test_TableNestedLeafs_ChildLeaf1CreateChild
#endif
TEST_EXPORT test_TableNestedLeafs_ChildLeaf1 _test_TableNestedLeafs_ChildLeaf1CreateChild(corto_object _parent, corto_string _id, int32_t id, corto_string value);
#define test_TableNestedLeafs_ChildLeaf1CreateChild(_parent, _id, id, value) _test_TableNestedLeafs_ChildLeaf1CreateChild(_parent, _id, id, value)
#define test_TableNestedLeafs_ChildLeaf1CreateChild_auto(_parent, _id, id, value) test_TableNestedLeafs_ChildLeaf1 _id = test_TableNestedLeafs_ChildLeaf1CreateChild(_parent, #_id, id, value); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableNestedLeafs_ChildLeaf1Update test_TableNestedLeafs_ChildLeaf1Update
#endif
TEST_EXPORT corto_int16 _test_TableNestedLeafs_ChildLeaf1Update(test_TableNestedLeafs_ChildLeaf1 _this, int32_t id, corto_string value);
#define test_TableNestedLeafs_ChildLeaf1Update(_this, id, value) _test_TableNestedLeafs_ChildLeaf1Update(test_TableNestedLeafs_ChildLeaf1(_this), id, value)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableNestedLeafs_ChildLeaf1Declare test_TableNestedLeafs_ChildLeaf1Declare
#endif
TEST_EXPORT test_TableNestedLeafs_ChildLeaf1 _test_TableNestedLeafs_ChildLeaf1Declare(void);
#define test_TableNestedLeafs_ChildLeaf1Declare() _test_TableNestedLeafs_ChildLeaf1Declare()
#define test_TableNestedLeafs_ChildLeaf1Declare_auto(_id) test_TableNestedLeafs_ChildLeaf1 _id = test_TableNestedLeafs_ChildLeaf1Declare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableNestedLeafs_ChildLeaf1DeclareChild test_TableNestedLeafs_ChildLeaf1DeclareChild
#endif
TEST_EXPORT test_TableNestedLeafs_ChildLeaf1 _test_TableNestedLeafs_ChildLeaf1DeclareChild(corto_object _parent, corto_string _id);
#define test_TableNestedLeafs_ChildLeaf1DeclareChild(_parent, _id) _test_TableNestedLeafs_ChildLeaf1DeclareChild(_parent, _id)
#define test_TableNestedLeafs_ChildLeaf1DeclareChild_auto(_parent, _id) test_TableNestedLeafs_ChildLeaf1 _id = test_TableNestedLeafs_ChildLeaf1DeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableNestedLeafs_ChildLeaf1Define test_TableNestedLeafs_ChildLeaf1Define
#endif
TEST_EXPORT corto_int16 _test_TableNestedLeafs_ChildLeaf1Define(test_TableNestedLeafs_ChildLeaf1 _this, int32_t id, corto_string value);
#define test_TableNestedLeafs_ChildLeaf1Define(_this, id, value) _test_TableNestedLeafs_ChildLeaf1Define(test_TableNestedLeafs_ChildLeaf1(_this), id, value)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableNestedLeafs_ChildLeaf1Assign test_TableNestedLeafs_ChildLeaf1Assign
#endif
TEST_EXPORT test_TableNestedLeafs_ChildLeaf1 _test_TableNestedLeafs_ChildLeaf1Assign(test_TableNestedLeafs_ChildLeaf1 _this, int32_t id, corto_string value);
#define test_TableNestedLeafs_ChildLeaf1__optional_NotSet NULL
#define test_TableNestedLeafs_ChildLeaf1__optional_Set(id, value) test_TableNestedLeafs_ChildLeaf1Assign((test_TableNestedLeafs_ChildLeaf1*)corto_ptr_new(test_TableNestedLeafs_ChildLeaf1_o)), id, value)
#define test_TableNestedLeafs_ChildLeaf1__optional_SetCond(cond, id, value) cond ? test_TableNestedLeafs_ChildLeaf1Assign((test_TableNestedLeafs_ChildLeaf1*)corto_ptr_new(test_TableNestedLeafs_ChildLeaf1_o), id, value) : NULL
#define test_TableNestedLeafs_ChildLeaf1Unset(_this) _this ? corto_ptr_free(_this, test_TableNestedLeafs_ChildLeaf1_o), 0 : 0; _this = NULL;
#define test_TableNestedLeafs_ChildLeaf1Assign(_this, id, value) _test_TableNestedLeafs_ChildLeaf1Assign(_this, id, value)
#define test_TableNestedLeafs_ChildLeaf1Set(_this, id, value) _this = _this ? _this : (test_TableNestedLeafs_ChildLeaf1*)corto_ptr_new(test_TableNestedLeafs_ChildLeaf1_o); _test_TableNestedLeafs_ChildLeaf1Assign(_this, id, value)

/* /test/TableNestedLeafs/ChildLeaf2 */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableNestedLeafs_ChildLeaf2Create test_TableNestedLeafs_ChildLeaf2Create
#endif
TEST_EXPORT test_TableNestedLeafs_ChildLeaf2 _test_TableNestedLeafs_ChildLeaf2Create(int32_t id, corto_string value);
#define test_TableNestedLeafs_ChildLeaf2Create(id, value) _test_TableNestedLeafs_ChildLeaf2Create(id, value)
#define test_TableNestedLeafs_ChildLeaf2Create_auto(_id, id, value) test_TableNestedLeafs_ChildLeaf2 _id = test_TableNestedLeafs_ChildLeaf2Create(id, value); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableNestedLeafs_ChildLeaf2CreateChild test_TableNestedLeafs_ChildLeaf2CreateChild
#endif
TEST_EXPORT test_TableNestedLeafs_ChildLeaf2 _test_TableNestedLeafs_ChildLeaf2CreateChild(corto_object _parent, corto_string _id, int32_t id, corto_string value);
#define test_TableNestedLeafs_ChildLeaf2CreateChild(_parent, _id, id, value) _test_TableNestedLeafs_ChildLeaf2CreateChild(_parent, _id, id, value)
#define test_TableNestedLeafs_ChildLeaf2CreateChild_auto(_parent, _id, id, value) test_TableNestedLeafs_ChildLeaf2 _id = test_TableNestedLeafs_ChildLeaf2CreateChild(_parent, #_id, id, value); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableNestedLeafs_ChildLeaf2Update test_TableNestedLeafs_ChildLeaf2Update
#endif
TEST_EXPORT corto_int16 _test_TableNestedLeafs_ChildLeaf2Update(test_TableNestedLeafs_ChildLeaf2 _this, int32_t id, corto_string value);
#define test_TableNestedLeafs_ChildLeaf2Update(_this, id, value) _test_TableNestedLeafs_ChildLeaf2Update(test_TableNestedLeafs_ChildLeaf2(_this), id, value)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableNestedLeafs_ChildLeaf2Declare test_TableNestedLeafs_ChildLeaf2Declare
#endif
TEST_EXPORT test_TableNestedLeafs_ChildLeaf2 _test_TableNestedLeafs_ChildLeaf2Declare(void);
#define test_TableNestedLeafs_ChildLeaf2Declare() _test_TableNestedLeafs_ChildLeaf2Declare()
#define test_TableNestedLeafs_ChildLeaf2Declare_auto(_id) test_TableNestedLeafs_ChildLeaf2 _id = test_TableNestedLeafs_ChildLeaf2Declare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableNestedLeafs_ChildLeaf2DeclareChild test_TableNestedLeafs_ChildLeaf2DeclareChild
#endif
TEST_EXPORT test_TableNestedLeafs_ChildLeaf2 _test_TableNestedLeafs_ChildLeaf2DeclareChild(corto_object _parent, corto_string _id);
#define test_TableNestedLeafs_ChildLeaf2DeclareChild(_parent, _id) _test_TableNestedLeafs_ChildLeaf2DeclareChild(_parent, _id)
#define test_TableNestedLeafs_ChildLeaf2DeclareChild_auto(_parent, _id) test_TableNestedLeafs_ChildLeaf2 _id = test_TableNestedLeafs_ChildLeaf2DeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableNestedLeafs_ChildLeaf2Define test_TableNestedLeafs_ChildLeaf2Define
#endif
TEST_EXPORT corto_int16 _test_TableNestedLeafs_ChildLeaf2Define(test_TableNestedLeafs_ChildLeaf2 _this, int32_t id, corto_string value);
#define test_TableNestedLeafs_ChildLeaf2Define(_this, id, value) _test_TableNestedLeafs_ChildLeaf2Define(test_TableNestedLeafs_ChildLeaf2(_this), id, value)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableNestedLeafs_ChildLeaf2Assign test_TableNestedLeafs_ChildLeaf2Assign
#endif
TEST_EXPORT test_TableNestedLeafs_ChildLeaf2 _test_TableNestedLeafs_ChildLeaf2Assign(test_TableNestedLeafs_ChildLeaf2 _this, int32_t id, corto_string value);
#define test_TableNestedLeafs_ChildLeaf2__optional_NotSet NULL
#define test_TableNestedLeafs_ChildLeaf2__optional_Set(id, value) test_TableNestedLeafs_ChildLeaf2Assign((test_TableNestedLeafs_ChildLeaf2*)corto_ptr_new(test_TableNestedLeafs_ChildLeaf2_o)), id, value)
#define test_TableNestedLeafs_ChildLeaf2__optional_SetCond(cond, id, value) cond ? test_TableNestedLeafs_ChildLeaf2Assign((test_TableNestedLeafs_ChildLeaf2*)corto_ptr_new(test_TableNestedLeafs_ChildLeaf2_o), id, value) : NULL
#define test_TableNestedLeafs_ChildLeaf2Unset(_this) _this ? corto_ptr_free(_this, test_TableNestedLeafs_ChildLeaf2_o), 0 : 0; _this = NULL;
#define test_TableNestedLeafs_ChildLeaf2Assign(_this, id, value) _test_TableNestedLeafs_ChildLeaf2Assign(_this, id, value)
#define test_TableNestedLeafs_ChildLeaf2Set(_this, id, value) _this = _this ? _this : (test_TableNestedLeafs_ChildLeaf2*)corto_ptr_new(test_TableNestedLeafs_ChildLeaf2_o); _test_TableNestedLeafs_ChildLeaf2Assign(_this, id, value)

/* /test/TableSingleKey */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableSingleKeyCreate test_TableSingleKeyCreate
#endif
TEST_EXPORT test_TableSingleKey _test_TableSingleKeyCreate(corto_string value);
#define test_TableSingleKeyCreate(value) _test_TableSingleKeyCreate(value)
#define test_TableSingleKeyCreate_auto(_id, value) test_TableSingleKey _id = test_TableSingleKeyCreate(value); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableSingleKeyCreateChild test_TableSingleKeyCreateChild
#endif
TEST_EXPORT test_TableSingleKey _test_TableSingleKeyCreateChild(corto_object _parent, corto_string _id, corto_string value);
#define test_TableSingleKeyCreateChild(_parent, _id, value) _test_TableSingleKeyCreateChild(_parent, _id, value)
#define test_TableSingleKeyCreateChild_auto(_parent, _id, value) test_TableSingleKey _id = test_TableSingleKeyCreateChild(_parent, #_id, value); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableSingleKeyUpdate test_TableSingleKeyUpdate
#endif
TEST_EXPORT corto_int16 _test_TableSingleKeyUpdate(test_TableSingleKey _this, corto_string value);
#define test_TableSingleKeyUpdate(_this, value) _test_TableSingleKeyUpdate(test_TableSingleKey(_this), value)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableSingleKeyDeclare test_TableSingleKeyDeclare
#endif
TEST_EXPORT test_TableSingleKey _test_TableSingleKeyDeclare(void);
#define test_TableSingleKeyDeclare() _test_TableSingleKeyDeclare()
#define test_TableSingleKeyDeclare_auto(_id) test_TableSingleKey _id = test_TableSingleKeyDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableSingleKeyDeclareChild test_TableSingleKeyDeclareChild
#endif
TEST_EXPORT test_TableSingleKey _test_TableSingleKeyDeclareChild(corto_object _parent, corto_string _id);
#define test_TableSingleKeyDeclareChild(_parent, _id) _test_TableSingleKeyDeclareChild(_parent, _id)
#define test_TableSingleKeyDeclareChild_auto(_parent, _id) test_TableSingleKey _id = test_TableSingleKeyDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableSingleKeyDefine test_TableSingleKeyDefine
#endif
TEST_EXPORT corto_int16 _test_TableSingleKeyDefine(test_TableSingleKey _this, corto_string value);
#define test_TableSingleKeyDefine(_this, value) _test_TableSingleKeyDefine(test_TableSingleKey(_this), value)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableSingleKeyAssign test_TableSingleKeyAssign
#endif
TEST_EXPORT test_TableSingleKey _test_TableSingleKeyAssign(test_TableSingleKey _this, corto_string value);
#define test_TableSingleKey__optional_NotSet NULL
#define test_TableSingleKey__optional_Set(value) test_TableSingleKeyAssign((test_TableSingleKey*)corto_ptr_new(test_TableSingleKey_o)), value)
#define test_TableSingleKey__optional_SetCond(cond, value) cond ? test_TableSingleKeyAssign((test_TableSingleKey*)corto_ptr_new(test_TableSingleKey_o), value) : NULL
#define test_TableSingleKeyUnset(_this) _this ? corto_ptr_free(_this, test_TableSingleKey_o), 0 : 0; _this = NULL;
#define test_TableSingleKeyAssign(_this, value) _test_TableSingleKeyAssign(_this, value)
#define test_TableSingleKeySet(_this, value) _this = _this ? _this : (test_TableSingleKey*)corto_ptr_new(test_TableSingleKey_o); _test_TableSingleKeyAssign(_this, value)

/* /test/TableStringKey */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableStringKeyCreate test_TableStringKeyCreate
#endif
TEST_EXPORT test_TableStringKey _test_TableStringKeyCreate(corto_string value);
#define test_TableStringKeyCreate(value) _test_TableStringKeyCreate(value)
#define test_TableStringKeyCreate_auto(_id, value) test_TableStringKey _id = test_TableStringKeyCreate(value); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableStringKeyCreateChild test_TableStringKeyCreateChild
#endif
TEST_EXPORT test_TableStringKey _test_TableStringKeyCreateChild(corto_object _parent, corto_string _id, corto_string value);
#define test_TableStringKeyCreateChild(_parent, _id, value) _test_TableStringKeyCreateChild(_parent, _id, value)
#define test_TableStringKeyCreateChild_auto(_parent, _id, value) test_TableStringKey _id = test_TableStringKeyCreateChild(_parent, #_id, value); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableStringKeyUpdate test_TableStringKeyUpdate
#endif
TEST_EXPORT corto_int16 _test_TableStringKeyUpdate(test_TableStringKey _this, corto_string value);
#define test_TableStringKeyUpdate(_this, value) _test_TableStringKeyUpdate(test_TableStringKey(_this), value)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableStringKeyDeclare test_TableStringKeyDeclare
#endif
TEST_EXPORT test_TableStringKey _test_TableStringKeyDeclare(void);
#define test_TableStringKeyDeclare() _test_TableStringKeyDeclare()
#define test_TableStringKeyDeclare_auto(_id) test_TableStringKey _id = test_TableStringKeyDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableStringKeyDeclareChild test_TableStringKeyDeclareChild
#endif
TEST_EXPORT test_TableStringKey _test_TableStringKeyDeclareChild(corto_object _parent, corto_string _id);
#define test_TableStringKeyDeclareChild(_parent, _id) _test_TableStringKeyDeclareChild(_parent, _id)
#define test_TableStringKeyDeclareChild_auto(_parent, _id) test_TableStringKey _id = test_TableStringKeyDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableStringKeyDefine test_TableStringKeyDefine
#endif
TEST_EXPORT corto_int16 _test_TableStringKeyDefine(test_TableStringKey _this, corto_string value);
#define test_TableStringKeyDefine(_this, value) _test_TableStringKeyDefine(test_TableStringKey(_this), value)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TableStringKeyAssign test_TableStringKeyAssign
#endif
TEST_EXPORT test_TableStringKey _test_TableStringKeyAssign(test_TableStringKey _this, corto_string value);
#define test_TableStringKey__optional_NotSet NULL
#define test_TableStringKey__optional_Set(value) test_TableStringKeyAssign((test_TableStringKey*)corto_ptr_new(test_TableStringKey_o)), value)
#define test_TableStringKey__optional_SetCond(cond, value) cond ? test_TableStringKeyAssign((test_TableStringKey*)corto_ptr_new(test_TableStringKey_o), value) : NULL
#define test_TableStringKeyUnset(_this) _this ? corto_ptr_free(_this, test_TableStringKey_o), 0 : 0; _this = NULL;
#define test_TableStringKeyAssign(_this, value) _test_TableStringKeyAssign(_this, value)
#define test_TableStringKeySet(_this, value) _this = _this ? _this : (test_TableStringKey*)corto_ptr_new(test_TableStringKey_o); _test_TableStringKeyAssign(_this, value)

/* /test/TargetActual */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TargetActualCreate test_TargetActualCreate
#endif
TEST_EXPORT test_TargetActual _test_TargetActualCreate(int32_t actual, int32_t target, int32_t objective);
#define test_TargetActualCreate(actual, target, objective) _test_TargetActualCreate(actual, target, objective)
#define test_TargetActualCreate_auto(_id, actual, target, objective) test_TargetActual _id = test_TargetActualCreate(actual, target, objective); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TargetActualCreateChild test_TargetActualCreateChild
#endif
TEST_EXPORT test_TargetActual _test_TargetActualCreateChild(corto_object _parent, corto_string _id, int32_t actual, int32_t target, int32_t objective);
#define test_TargetActualCreateChild(_parent, _id, actual, target, objective) _test_TargetActualCreateChild(_parent, _id, actual, target, objective)
#define test_TargetActualCreateChild_auto(_parent, _id, actual, target, objective) test_TargetActual _id = test_TargetActualCreateChild(_parent, #_id, actual, target, objective); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TargetActualUpdate test_TargetActualUpdate
#endif
TEST_EXPORT corto_int16 _test_TargetActualUpdate(test_TargetActual _this, int32_t actual, int32_t target, int32_t objective);
#define test_TargetActualUpdate(_this, actual, target, objective) _test_TargetActualUpdate(_this, actual, target, objective)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TargetActualDeclare test_TargetActualDeclare
#endif
TEST_EXPORT test_TargetActual _test_TargetActualDeclare(void);
#define test_TargetActualDeclare() _test_TargetActualDeclare()
#define test_TargetActualDeclare_auto(_id) test_TargetActual _id = test_TargetActualDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TargetActualDeclareChild test_TargetActualDeclareChild
#endif
TEST_EXPORT test_TargetActual _test_TargetActualDeclareChild(corto_object _parent, corto_string _id);
#define test_TargetActualDeclareChild(_parent, _id) _test_TargetActualDeclareChild(_parent, _id)
#define test_TargetActualDeclareChild_auto(_parent, _id) test_TargetActual _id = test_TargetActualDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TargetActualDefine test_TargetActualDefine
#endif
TEST_EXPORT corto_int16 _test_TargetActualDefine(test_TargetActual _this, int32_t actual, int32_t target, int32_t objective);
#define test_TargetActualDefine(_this, actual, target, objective) _test_TargetActualDefine(_this, actual, target, objective)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TargetActualAssign test_TargetActualAssign
#endif
TEST_EXPORT test_TargetActual _test_TargetActualAssign(test_TargetActual _this, int32_t actual, int32_t target, int32_t objective);
#define test_TargetActual__optional_NotSet NULL
#define test_TargetActual__optional_Set(actual, target, objective) test_TargetActualAssign((test_TargetActual*)corto_ptr_new(test_TargetActual_o)), actual, target, objective)
#define test_TargetActual__optional_SetCond(cond, actual, target, objective) cond ? test_TargetActualAssign((test_TargetActual*)corto_ptr_new(test_TargetActual_o), actual, target, objective) : NULL
#define test_TargetActualUnset(_this) _this ? corto_ptr_free(_this, test_TargetActual_o), 0 : 0; _this = NULL;
#define test_TargetActualAssign(_this, actual, target, objective) _test_TargetActualAssign(_this, actual, target, objective)
#define test_TargetActualSet(_this, actual, target, objective) _this = _this ? _this : (test_TargetActual*)corto_ptr_new(test_TargetActual_o); _test_TargetActualAssign(_this, actual, target, objective)

/* /test/TargetActualMember */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TargetActualMemberCreate test_TargetActualMemberCreate
#endif
TEST_EXPORT test_TargetActualMember* _test_TargetActualMemberCreate(int32_t m, int32_t n);
#define test_TargetActualMemberCreate(m, n) _test_TargetActualMemberCreate(m, n)
#define test_TargetActualMemberCreate_auto(_id, m, n) test_TargetActualMember* _id = test_TargetActualMemberCreate(m, n); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TargetActualMemberCreateChild test_TargetActualMemberCreateChild
#endif
TEST_EXPORT test_TargetActualMember* _test_TargetActualMemberCreateChild(corto_object _parent, corto_string _id, int32_t m, int32_t n);
#define test_TargetActualMemberCreateChild(_parent, _id, m, n) _test_TargetActualMemberCreateChild(_parent, _id, m, n)
#define test_TargetActualMemberCreateChild_auto(_parent, _id, m, n) test_TargetActualMember* _id = test_TargetActualMemberCreateChild(_parent, #_id, m, n); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TargetActualMemberUpdate test_TargetActualMemberUpdate
#endif
TEST_EXPORT corto_int16 _test_TargetActualMemberUpdate(test_TargetActualMember* _this, int32_t m, int32_t n);
#define test_TargetActualMemberUpdate(_this, m, n) _test_TargetActualMemberUpdate(test_TargetActualMember(_this), m, n)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TargetActualMemberDeclare test_TargetActualMemberDeclare
#endif
TEST_EXPORT test_TargetActualMember* _test_TargetActualMemberDeclare(void);
#define test_TargetActualMemberDeclare() _test_TargetActualMemberDeclare()
#define test_TargetActualMemberDeclare_auto(_id) test_TargetActualMember* _id = test_TargetActualMemberDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TargetActualMemberDeclareChild test_TargetActualMemberDeclareChild
#endif
TEST_EXPORT test_TargetActualMember* _test_TargetActualMemberDeclareChild(corto_object _parent, corto_string _id);
#define test_TargetActualMemberDeclareChild(_parent, _id) _test_TargetActualMemberDeclareChild(_parent, _id)
#define test_TargetActualMemberDeclareChild_auto(_parent, _id) test_TargetActualMember* _id = test_TargetActualMemberDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TargetActualMemberDefine test_TargetActualMemberDefine
#endif
TEST_EXPORT corto_int16 _test_TargetActualMemberDefine(test_TargetActualMember* _this, int32_t m, int32_t n);
#define test_TargetActualMemberDefine(_this, m, n) _test_TargetActualMemberDefine(test_TargetActualMember(_this), m, n)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TargetActualMemberAssign test_TargetActualMemberAssign
#endif
TEST_EXPORT test_TargetActualMember* _test_TargetActualMemberAssign(test_TargetActualMember* _this, int32_t m, int32_t n);
#define test_TargetActualMember__optional_NotSet NULL
#define test_TargetActualMember__optional_Set(m, n) test_TargetActualMemberAssign((test_TargetActualMember*)corto_ptr_new(test_TargetActualMember_o)), m, n)
#define test_TargetActualMember__optional_SetCond(cond, m, n) cond ? test_TargetActualMemberAssign((test_TargetActualMember*)corto_ptr_new(test_TargetActualMember_o), m, n) : NULL
#define test_TargetActualMemberUnset(_this) _this ? corto_ptr_free(_this, test_TargetActualMember_o), 0 : 0; _this = NULL;
#define test_TargetActualMemberAssign(_this, m, n) _test_TargetActualMemberAssign(_this, m, n)
#define test_TargetActualMemberSet(_this, m, n) _this = _this ? _this : (test_TargetActualMember*)corto_ptr_new(test_TargetActualMember_o); _test_TargetActualMemberAssign(_this, m, n)

/* /test/TestKey */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TestKeyCreate test_TestKeyCreate
#endif
TEST_EXPORT test_TestKey _test_TestKeyCreate(void);
#define test_TestKeyCreate() _test_TestKeyCreate()
#define test_TestKeyCreate_auto(_id) test_TestKey _id = test_TestKeyCreate(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TestKeyCreateChild test_TestKeyCreateChild
#endif
TEST_EXPORT test_TestKey _test_TestKeyCreateChild(corto_object _parent, corto_string _id);
#define test_TestKeyCreateChild(_parent, _id) _test_TestKeyCreateChild(_parent, _id)
#define test_TestKeyCreateChild_auto(_parent, _id) test_TestKey _id = test_TestKeyCreateChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TestKeyUpdate test_TestKeyUpdate
#endif
TEST_EXPORT corto_int16 _test_TestKeyUpdate(test_TestKey _this);
#define test_TestKeyUpdate(_this) _test_TestKeyUpdate(test_TestKey(_this))


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TestKeyDeclare test_TestKeyDeclare
#endif
TEST_EXPORT test_TestKey _test_TestKeyDeclare(void);
#define test_TestKeyDeclare() _test_TestKeyDeclare()
#define test_TestKeyDeclare_auto(_id) test_TestKey _id = test_TestKeyDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TestKeyDeclareChild test_TestKeyDeclareChild
#endif
TEST_EXPORT test_TestKey _test_TestKeyDeclareChild(corto_object _parent, corto_string _id);
#define test_TestKeyDeclareChild(_parent, _id) _test_TestKeyDeclareChild(_parent, _id)
#define test_TestKeyDeclareChild_auto(_parent, _id) test_TestKey _id = test_TestKeyDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TestKeyDefine test_TestKeyDefine
#endif
TEST_EXPORT corto_int16 _test_TestKeyDefine(test_TestKey _this);
#define test_TestKeyDefine(_this) _test_TestKeyDefine(test_TestKey(_this))

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TestKeyAssign test_TestKeyAssign
#endif
TEST_EXPORT test_TestKey _test_TestKeyAssign(test_TestKey _this);
#define test_TestKey__optional_NotSet NULL
#define test_TestKey__optional_Set() test_TestKeyAssign((test_TestKey*)corto_ptr_new(test_TestKey_o)))
#define test_TestKey__optional_SetCond(cond) cond ? test_TestKeyAssign((test_TestKey*)corto_ptr_new(test_TestKey_o)) : NULL
#define test_TestKeyUnset(_this) _this ? corto_ptr_free(_this, test_TestKey_o), 0 : 0; _this = NULL;
#define test_TestKeyAssign(_this) _test_TestKeyAssign(_this)
#define test_TestKeySet(_this) _this = _this ? _this : (test_TestKey*)corto_ptr_new(test_TestKey_o); _test_TestKeyAssign(_this)

/* /test/TestLock */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TestLockCreate test_TestLockCreate
#endif
TEST_EXPORT test_TestLock _test_TestLockCreate(corto_string mount, corto_string expr, int16_t priority, test_AccessRuleList rules);
#define test_TestLockCreate(mount, expr, priority, rules) _test_TestLockCreate(mount, expr, priority, rules)
#define test_TestLockCreate_auto(_id, mount, expr, priority, rules) test_TestLock _id = test_TestLockCreate(mount, expr, priority, rules); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TestLockCreateChild test_TestLockCreateChild
#endif
TEST_EXPORT test_TestLock _test_TestLockCreateChild(corto_object _parent, corto_string _id, corto_string mount, corto_string expr, int16_t priority, test_AccessRuleList rules);
#define test_TestLockCreateChild(_parent, _id, mount, expr, priority, rules) _test_TestLockCreateChild(_parent, _id, mount, expr, priority, rules)
#define test_TestLockCreateChild_auto(_parent, _id, mount, expr, priority, rules) test_TestLock _id = test_TestLockCreateChild(_parent, #_id, mount, expr, priority, rules); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TestLockUpdate test_TestLockUpdate
#endif
TEST_EXPORT corto_int16 _test_TestLockUpdate(test_TestLock _this, corto_string mount, corto_string expr, int16_t priority, test_AccessRuleList rules);
#define test_TestLockUpdate(_this, mount, expr, priority, rules) _test_TestLockUpdate(test_TestLock(_this), mount, expr, priority, rules)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TestLockDeclare test_TestLockDeclare
#endif
TEST_EXPORT test_TestLock _test_TestLockDeclare(void);
#define test_TestLockDeclare() _test_TestLockDeclare()
#define test_TestLockDeclare_auto(_id) test_TestLock _id = test_TestLockDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TestLockDeclareChild test_TestLockDeclareChild
#endif
TEST_EXPORT test_TestLock _test_TestLockDeclareChild(corto_object _parent, corto_string _id);
#define test_TestLockDeclareChild(_parent, _id) _test_TestLockDeclareChild(_parent, _id)
#define test_TestLockDeclareChild_auto(_parent, _id) test_TestLock _id = test_TestLockDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TestLockDefine test_TestLockDefine
#endif
TEST_EXPORT corto_int16 _test_TestLockDefine(test_TestLock _this, corto_string mount, corto_string expr, int16_t priority, test_AccessRuleList rules);
#define test_TestLockDefine(_this, mount, expr, priority, rules) _test_TestLockDefine(test_TestLock(_this), mount, expr, priority, rules)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TestLockAssign test_TestLockAssign
#endif
TEST_EXPORT test_TestLock _test_TestLockAssign(test_TestLock _this, corto_string mount, corto_string expr, int16_t priority, test_AccessRuleList rules);
#define test_TestLock__optional_NotSet NULL
#define test_TestLock__optional_Set(mount, expr, priority, rules) test_TestLockAssign((test_TestLock*)corto_ptr_new(test_TestLock_o)), mount, expr, priority, rules)
#define test_TestLock__optional_SetCond(cond, mount, expr, priority, rules) cond ? test_TestLockAssign((test_TestLock*)corto_ptr_new(test_TestLock_o), mount, expr, priority, rules) : NULL
#define test_TestLockUnset(_this) _this ? corto_ptr_free(_this, test_TestLock_o), 0 : 0; _this = NULL;
#define test_TestLockAssign(_this, mount, expr, priority, rules) _test_TestLockAssign(_this, mount, expr, priority, rules)
#define test_TestLockSet(_this, mount, expr, priority, rules) _this = _this ? _this : (test_TestLock*)corto_ptr_new(test_TestLock_o); _test_TestLockAssign(_this, mount, expr, priority, rules)

/* /test/TypeAttr */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TypeAttrCreate test_TypeAttrCreate
#endif
TEST_EXPORT test_TypeAttr* _test_TypeAttrCreate(int32_t foo);
#define test_TypeAttrCreate(foo) _test_TypeAttrCreate(foo)
#define test_TypeAttrCreate_auto(_id, foo) test_TypeAttr* _id = test_TypeAttrCreate(foo); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TypeAttrCreateChild test_TypeAttrCreateChild
#endif
TEST_EXPORT test_TypeAttr* _test_TypeAttrCreateChild(corto_object _parent, corto_string _id, int32_t foo);
#define test_TypeAttrCreateChild(_parent, _id, foo) _test_TypeAttrCreateChild(_parent, _id, foo)
#define test_TypeAttrCreateChild_auto(_parent, _id, foo) test_TypeAttr* _id = test_TypeAttrCreateChild(_parent, #_id, foo); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TypeAttrUpdate test_TypeAttrUpdate
#endif
TEST_EXPORT corto_int16 _test_TypeAttrUpdate(test_TypeAttr* _this, int32_t foo);
#define test_TypeAttrUpdate(_this, foo) _test_TypeAttrUpdate(test_TypeAttr(_this), foo)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TypeAttrDeclare test_TypeAttrDeclare
#endif
TEST_EXPORT test_TypeAttr* _test_TypeAttrDeclare(void);
#define test_TypeAttrDeclare() _test_TypeAttrDeclare()
#define test_TypeAttrDeclare_auto(_id) test_TypeAttr* _id = test_TypeAttrDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TypeAttrDeclareChild test_TypeAttrDeclareChild
#endif
TEST_EXPORT test_TypeAttr* _test_TypeAttrDeclareChild(corto_object _parent, corto_string _id);
#define test_TypeAttrDeclareChild(_parent, _id) _test_TypeAttrDeclareChild(_parent, _id)
#define test_TypeAttrDeclareChild_auto(_parent, _id) test_TypeAttr* _id = test_TypeAttrDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TypeAttrDefine test_TypeAttrDefine
#endif
TEST_EXPORT corto_int16 _test_TypeAttrDefine(test_TypeAttr* _this, int32_t foo);
#define test_TypeAttrDefine(_this, foo) _test_TypeAttrDefine(test_TypeAttr(_this), foo)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TypeAttrAssign test_TypeAttrAssign
#endif
TEST_EXPORT test_TypeAttr* _test_TypeAttrAssign(test_TypeAttr* _this, int32_t foo);
#define test_TypeAttr__optional_NotSet NULL
#define test_TypeAttr__optional_Set(foo) test_TypeAttrAssign((test_TypeAttr*)corto_ptr_new(test_TypeAttr_o)), foo)
#define test_TypeAttr__optional_SetCond(cond, foo) cond ? test_TypeAttrAssign((test_TypeAttr*)corto_ptr_new(test_TypeAttr_o), foo) : NULL
#define test_TypeAttrUnset(_this) _this ? corto_ptr_free(_this, test_TypeAttr_o), 0 : 0; _this = NULL;
#define test_TypeAttrAssign(_this, foo) _test_TypeAttrAssign(_this, foo)
#define test_TypeAttrSet(_this, foo) _this = _this ? _this : (test_TypeAttr*)corto_ptr_new(test_TypeAttr_o); _test_TypeAttrAssign(_this, foo)

/* /test/TypeKind */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TypeKindCreate test_TypeKindCreate
#endif
TEST_EXPORT test_TypeKind* _test_TypeKindCreate(test_TypeKind value);
#define test_TypeKindCreate(value) _test_TypeKindCreate(value)
#define test_TypeKindCreate_auto(_id, value) test_TypeKind* _id = test_TypeKindCreate(value); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TypeKindCreateChild test_TypeKindCreateChild
#endif
TEST_EXPORT test_TypeKind* _test_TypeKindCreateChild(corto_object _parent, corto_string _id, test_TypeKind value);
#define test_TypeKindCreateChild(_parent, _id, value) _test_TypeKindCreateChild(_parent, _id, value)
#define test_TypeKindCreateChild_auto(_parent, _id, value) test_TypeKind* _id = test_TypeKindCreateChild(_parent, #_id, value); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TypeKindUpdate test_TypeKindUpdate
#endif
TEST_EXPORT corto_int16 _test_TypeKindUpdate(test_TypeKind* _this, test_TypeKind value);
#define test_TypeKindUpdate(_this, value) _test_TypeKindUpdate(test_TypeKind(_this), value)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TypeKindDeclare test_TypeKindDeclare
#endif
TEST_EXPORT test_TypeKind* _test_TypeKindDeclare(void);
#define test_TypeKindDeclare() _test_TypeKindDeclare()
#define test_TypeKindDeclare_auto(_id) test_TypeKind* _id = test_TypeKindDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TypeKindDeclareChild test_TypeKindDeclareChild
#endif
TEST_EXPORT test_TypeKind* _test_TypeKindDeclareChild(corto_object _parent, corto_string _id);
#define test_TypeKindDeclareChild(_parent, _id) _test_TypeKindDeclareChild(_parent, _id)
#define test_TypeKindDeclareChild_auto(_parent, _id) test_TypeKind* _id = test_TypeKindDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TypeKindDefine test_TypeKindDefine
#endif
TEST_EXPORT corto_int16 _test_TypeKindDefine(test_TypeKind* _this, test_TypeKind value);
#define test_TypeKindDefine(_this, value) _test_TypeKindDefine(test_TypeKind(_this), value)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define TypeKindAssign test_TypeKindAssign
#endif
TEST_EXPORT test_TypeKind* _test_TypeKindAssign(test_TypeKind* _this, test_TypeKind value);
#define test_TypeKind__optional_NotSet NULL
#define test_TypeKind__optional_Set(value) test_TypeKindAssign((test_TypeKind*)corto_ptr_new(test_TypeKind_o)), value)
#define test_TypeKind__optional_SetCond(cond, value) cond ? test_TypeKindAssign((test_TypeKind*)corto_ptr_new(test_TypeKind_o), value) : NULL
#define test_TypeKindUnset(_this) _this ? corto_ptr_free(_this, test_TypeKind_o), 0 : 0; _this = NULL;
#define test_TypeKindAssign(_this, value) _test_TypeKindAssign(_this, value)
#define test_TypeKindSet(_this, value) _this = _this ? _this : (test_TypeKind*)corto_ptr_new(test_TypeKind_o); _test_TypeKindAssign(_this, value)

/* /test/uintw */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define uintwCreate test_uintwCreate
#endif
TEST_EXPORT uintptr_t* _test_uintwCreate(uintptr_t value);
#define test_uintwCreate(value) _test_uintwCreate(value)
#define test_uintwCreate_auto(_id, value) uintptr_t* _id = test_uintwCreate(value); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define uintwCreateChild test_uintwCreateChild
#endif
TEST_EXPORT uintptr_t* _test_uintwCreateChild(corto_object _parent, corto_string _id, uintptr_t value);
#define test_uintwCreateChild(_parent, _id, value) _test_uintwCreateChild(_parent, _id, value)
#define test_uintwCreateChild_auto(_parent, _id, value) uintptr_t* _id = test_uintwCreateChild(_parent, #_id, value); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define uintwUpdate test_uintwUpdate
#endif
TEST_EXPORT corto_int16 _test_uintwUpdate(uintptr_t* _this, uintptr_t value);
#define test_uintwUpdate(_this, value) _test_uintwUpdate(test_uintw(_this), value)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define uintwDeclare test_uintwDeclare
#endif
TEST_EXPORT uintptr_t* _test_uintwDeclare(void);
#define test_uintwDeclare() _test_uintwDeclare()
#define test_uintwDeclare_auto(_id) uintptr_t* _id = test_uintwDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define uintwDeclareChild test_uintwDeclareChild
#endif
TEST_EXPORT uintptr_t* _test_uintwDeclareChild(corto_object _parent, corto_string _id);
#define test_uintwDeclareChild(_parent, _id) _test_uintwDeclareChild(_parent, _id)
#define test_uintwDeclareChild_auto(_parent, _id) uintptr_t* _id = test_uintwDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define uintwDefine test_uintwDefine
#endif
TEST_EXPORT corto_int16 _test_uintwDefine(uintptr_t* _this, uintptr_t value);
#define test_uintwDefine(_this, value) _test_uintwDefine(test_uintw(_this), value)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define uintwAssign test_uintwAssign
#endif
TEST_EXPORT uintptr_t* _test_uintwAssign(uintptr_t* _this, uintptr_t value);
#define test_uintw__optional_NotSet NULL
#define test_uintw__optional_Set(value) test_uintwAssign((test_uintw*)corto_ptr_new(test_uintw_o)), value)
#define test_uintw__optional_SetCond(cond, value) cond ? test_uintwAssign((test_uintw*)corto_ptr_new(test_uintw_o), value) : NULL
#define test_uintwUnset(_this) _this ? corto_ptr_free(_this, test_uintw_o), 0 : 0; _this = NULL;
#define test_uintwAssign(_this, value) _test_uintwAssign(_this, value)
#define test_uintwSet(_this, value) _this = _this ? _this : (test_uintw*)corto_ptr_new(test_uintw_o); _test_uintwAssign(_this, value)

/* /test/unionTypes */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesCreate test_unionTypesCreate
#endif
TEST_EXPORT test_unionTypes* _test_unionTypesCreate_m_int(test_TypeKind _d, int32_t m_int);
#define test_unionTypesCreate_m_int(_d, m_int) _test_unionTypesCreate_m_int(_d, m_int)
#define test_unionTypesCreate_m_int_auto(_id, _d, m_int) test_unionTypes* _id = test_unionTypesCreate_m_int(_d, m_int); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesCreate test_unionTypesCreate
#endif
TEST_EXPORT test_unionTypes* _test_unionTypesCreate_m_string(test_TypeKind _d, corto_string m_string);
#define test_unionTypesCreate_m_string(_d, m_string) _test_unionTypesCreate_m_string(_d, m_string)
#define test_unionTypesCreate_m_string_auto(_id, _d, m_string) test_unionTypes* _id = test_unionTypesCreate_m_string(_d, m_string); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesCreate test_unionTypesCreate
#endif
TEST_EXPORT test_unionTypes* _test_unionTypesCreate_m_composite(test_TypeKind _d, test_Point* m_composite);
#define test_unionTypesCreate_m_composite(_d, m_composite) _test_unionTypesCreate_m_composite(_d, m_composite)
#define test_unionTypesCreate_m_composite_auto(_id, _d, m_composite) test_unionTypes* _id = test_unionTypesCreate_m_composite(_d, m_composite); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesCreate test_unionTypesCreate
#endif
TEST_EXPORT test_unionTypes* _test_unionTypesCreate_m_reference(test_TypeKind _d, corto_object m_reference);
#define test_unionTypesCreate_m_reference(_d, m_reference) _test_unionTypesCreate_m_reference(_d, m_reference)
#define test_unionTypesCreate_m_reference_auto(_id, _d, m_reference) test_unionTypes* _id = test_unionTypesCreate_m_reference(_d, m_reference); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesCreate test_unionTypesCreate
#endif
TEST_EXPORT test_unionTypes* _test_unionTypesCreate_m_array(test_TypeKind _d, test_IntArray m_array);
#define test_unionTypesCreate_m_array(_d, m_array) _test_unionTypesCreate_m_array(_d, m_array)
#define test_unionTypesCreate_m_array_auto(_id, _d, m_array) test_unionTypes* _id = test_unionTypesCreate_m_array(_d, m_array); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesCreate test_unionTypesCreate
#endif
TEST_EXPORT test_unionTypes* _test_unionTypesCreate_m_sequence(test_TypeKind _d, test_IntSequence m_sequence);
#define test_unionTypesCreate_m_sequence(_d, m_sequence) _test_unionTypesCreate_m_sequence(_d, m_sequence)
#define test_unionTypesCreate_m_sequence_auto(_id, _d, m_sequence) test_unionTypes* _id = test_unionTypesCreate_m_sequence(_d, m_sequence); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesCreate test_unionTypesCreate
#endif
TEST_EXPORT test_unionTypes* _test_unionTypesCreate_m_list(test_TypeKind _d, test_IntList m_list);
#define test_unionTypesCreate_m_list(_d, m_list) _test_unionTypesCreate_m_list(_d, m_list)
#define test_unionTypesCreate_m_list_auto(_id, _d, m_list) test_unionTypes* _id = test_unionTypesCreate_m_list(_d, m_list); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesCreate test_unionTypesCreate
#endif
TEST_EXPORT test_unionTypes* _test_unionTypesCreate_m_optionalInt(test_TypeKind _d, int32_t* m_optionalInt);
#define test_unionTypesCreate_m_optionalInt(_d, m_optionalInt) _test_unionTypesCreate_m_optionalInt(_d, corto_int32__optional_##m_optionalInt)
#define test_unionTypesCreate_m_optionalInt_auto(_id, _d, m_optionalInt) test_unionTypes* _id = test_unionTypesCreate_m_optionalInt(_d, m_optionalInt); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesCreate test_unionTypesCreate
#endif
TEST_EXPORT test_unionTypes* _test_unionTypesCreate_m_optionalString(test_TypeKind _d, corto_string* m_optionalString);
#define test_unionTypesCreate_m_optionalString(_d, m_optionalString) _test_unionTypesCreate_m_optionalString(_d, corto_string__optional_##m_optionalString)
#define test_unionTypesCreate_m_optionalString_auto(_id, _d, m_optionalString) test_unionTypes* _id = test_unionTypesCreate_m_optionalString(_d, m_optionalString); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesCreate test_unionTypesCreate
#endif
TEST_EXPORT test_unionTypes* _test_unionTypesCreate_m_optionalComposite(test_TypeKind _d, test_Point* m_optionalComposite);
#define test_unionTypesCreate_m_optionalComposite(_d, m_optionalComposite) _test_unionTypesCreate_m_optionalComposite(_d, test_Point__optional_##m_optionalComposite)
#define test_unionTypesCreate_m_optionalComposite_auto(_id, _d, m_optionalComposite) test_unionTypes* _id = test_unionTypesCreate_m_optionalComposite(_d, m_optionalComposite); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesCreate test_unionTypesCreate
#endif
TEST_EXPORT test_unionTypes* _test_unionTypesCreate_m_optionalReference(test_TypeKind _d, corto_object* m_optionalReference);
#define test_unionTypesCreate_m_optionalReference(_d, m_optionalReference) _test_unionTypesCreate_m_optionalReference(_d, corto_object__optional_##m_optionalReference)
#define test_unionTypesCreate_m_optionalReference_auto(_id, _d, m_optionalReference) test_unionTypes* _id = test_unionTypesCreate_m_optionalReference(_d, m_optionalReference); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesCreate test_unionTypesCreate
#endif
TEST_EXPORT test_unionTypes* _test_unionTypesCreate_m_optionalArray(test_TypeKind _d, test_IntArray* m_optionalArray);
#define test_unionTypesCreate_m_optionalArray(_d, m_optionalArray) _test_unionTypesCreate_m_optionalArray(_d, test_IntArray__optional_##m_optionalArray)
#define test_unionTypesCreate_m_optionalArray_auto(_id, _d, m_optionalArray) test_unionTypes* _id = test_unionTypesCreate_m_optionalArray(_d, m_optionalArray); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesCreate test_unionTypesCreate
#endif
TEST_EXPORT test_unionTypes* _test_unionTypesCreate_m_optionalSequence(test_TypeKind _d, test_IntSequence* m_optionalSequence);
#define test_unionTypesCreate_m_optionalSequence(_d, m_optionalSequence) _test_unionTypesCreate_m_optionalSequence(_d, test_IntSequence__optional_##m_optionalSequence)
#define test_unionTypesCreate_m_optionalSequence_auto(_id, _d, m_optionalSequence) test_unionTypes* _id = test_unionTypesCreate_m_optionalSequence(_d, m_optionalSequence); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesCreate test_unionTypesCreate
#endif
TEST_EXPORT test_unionTypes* _test_unionTypesCreate_m_optionalList(test_TypeKind _d, test_IntList* m_optionalList);
#define test_unionTypesCreate_m_optionalList(_d, m_optionalList) _test_unionTypesCreate_m_optionalList(_d, test_IntList__optional_##m_optionalList)
#define test_unionTypesCreate_m_optionalList_auto(_id, _d, m_optionalList) test_unionTypes* _id = test_unionTypesCreate_m_optionalList(_d, m_optionalList); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesCreateChild test_unionTypesCreateChild
#endif
TEST_EXPORT test_unionTypes* _test_unionTypesCreateChild_m_int(corto_object _parent, corto_string _id, test_TypeKind _d, int32_t m_int);
#define test_unionTypesCreateChild_m_int(_parent, _id, _d, m_int) _test_unionTypesCreateChild_m_int(_parent, _id, _d, m_int)
#define test_unionTypesCreateChild_m_int_auto(_parent, _id, _d, m_int) test_unionTypes* _id = test_unionTypesCreateChild_m_int(_parent, #_id, _d, m_int); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesCreateChild test_unionTypesCreateChild
#endif
TEST_EXPORT test_unionTypes* _test_unionTypesCreateChild_m_string(corto_object _parent, corto_string _id, test_TypeKind _d, corto_string m_string);
#define test_unionTypesCreateChild_m_string(_parent, _id, _d, m_string) _test_unionTypesCreateChild_m_string(_parent, _id, _d, m_string)
#define test_unionTypesCreateChild_m_string_auto(_parent, _id, _d, m_string) test_unionTypes* _id = test_unionTypesCreateChild_m_string(_parent, #_id, _d, m_string); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesCreateChild test_unionTypesCreateChild
#endif
TEST_EXPORT test_unionTypes* _test_unionTypesCreateChild_m_composite(corto_object _parent, corto_string _id, test_TypeKind _d, test_Point* m_composite);
#define test_unionTypesCreateChild_m_composite(_parent, _id, _d, m_composite) _test_unionTypesCreateChild_m_composite(_parent, _id, _d, m_composite)
#define test_unionTypesCreateChild_m_composite_auto(_parent, _id, _d, m_composite) test_unionTypes* _id = test_unionTypesCreateChild_m_composite(_parent, #_id, _d, m_composite); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesCreateChild test_unionTypesCreateChild
#endif
TEST_EXPORT test_unionTypes* _test_unionTypesCreateChild_m_reference(corto_object _parent, corto_string _id, test_TypeKind _d, corto_object m_reference);
#define test_unionTypesCreateChild_m_reference(_parent, _id, _d, m_reference) _test_unionTypesCreateChild_m_reference(_parent, _id, _d, m_reference)
#define test_unionTypesCreateChild_m_reference_auto(_parent, _id, _d, m_reference) test_unionTypes* _id = test_unionTypesCreateChild_m_reference(_parent, #_id, _d, m_reference); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesCreateChild test_unionTypesCreateChild
#endif
TEST_EXPORT test_unionTypes* _test_unionTypesCreateChild_m_array(corto_object _parent, corto_string _id, test_TypeKind _d, test_IntArray m_array);
#define test_unionTypesCreateChild_m_array(_parent, _id, _d, m_array) _test_unionTypesCreateChild_m_array(_parent, _id, _d, m_array)
#define test_unionTypesCreateChild_m_array_auto(_parent, _id, _d, m_array) test_unionTypes* _id = test_unionTypesCreateChild_m_array(_parent, #_id, _d, m_array); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesCreateChild test_unionTypesCreateChild
#endif
TEST_EXPORT test_unionTypes* _test_unionTypesCreateChild_m_sequence(corto_object _parent, corto_string _id, test_TypeKind _d, test_IntSequence m_sequence);
#define test_unionTypesCreateChild_m_sequence(_parent, _id, _d, m_sequence) _test_unionTypesCreateChild_m_sequence(_parent, _id, _d, m_sequence)
#define test_unionTypesCreateChild_m_sequence_auto(_parent, _id, _d, m_sequence) test_unionTypes* _id = test_unionTypesCreateChild_m_sequence(_parent, #_id, _d, m_sequence); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesCreateChild test_unionTypesCreateChild
#endif
TEST_EXPORT test_unionTypes* _test_unionTypesCreateChild_m_list(corto_object _parent, corto_string _id, test_TypeKind _d, test_IntList m_list);
#define test_unionTypesCreateChild_m_list(_parent, _id, _d, m_list) _test_unionTypesCreateChild_m_list(_parent, _id, _d, m_list)
#define test_unionTypesCreateChild_m_list_auto(_parent, _id, _d, m_list) test_unionTypes* _id = test_unionTypesCreateChild_m_list(_parent, #_id, _d, m_list); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesCreateChild test_unionTypesCreateChild
#endif
TEST_EXPORT test_unionTypes* _test_unionTypesCreateChild_m_optionalInt(corto_object _parent, corto_string _id, test_TypeKind _d, int32_t* m_optionalInt);
#define test_unionTypesCreateChild_m_optionalInt(_parent, _id, _d, m_optionalInt) _test_unionTypesCreateChild_m_optionalInt(_parent, _id, _d, corto_int32__optional_##m_optionalInt)
#define test_unionTypesCreateChild_m_optionalInt_auto(_parent, _id, _d, m_optionalInt) test_unionTypes* _id = test_unionTypesCreateChild_m_optionalInt(_parent, #_id, _d, m_optionalInt); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesCreateChild test_unionTypesCreateChild
#endif
TEST_EXPORT test_unionTypes* _test_unionTypesCreateChild_m_optionalString(corto_object _parent, corto_string _id, test_TypeKind _d, corto_string* m_optionalString);
#define test_unionTypesCreateChild_m_optionalString(_parent, _id, _d, m_optionalString) _test_unionTypesCreateChild_m_optionalString(_parent, _id, _d, corto_string__optional_##m_optionalString)
#define test_unionTypesCreateChild_m_optionalString_auto(_parent, _id, _d, m_optionalString) test_unionTypes* _id = test_unionTypesCreateChild_m_optionalString(_parent, #_id, _d, m_optionalString); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesCreateChild test_unionTypesCreateChild
#endif
TEST_EXPORT test_unionTypes* _test_unionTypesCreateChild_m_optionalComposite(corto_object _parent, corto_string _id, test_TypeKind _d, test_Point* m_optionalComposite);
#define test_unionTypesCreateChild_m_optionalComposite(_parent, _id, _d, m_optionalComposite) _test_unionTypesCreateChild_m_optionalComposite(_parent, _id, _d, test_Point__optional_##m_optionalComposite)
#define test_unionTypesCreateChild_m_optionalComposite_auto(_parent, _id, _d, m_optionalComposite) test_unionTypes* _id = test_unionTypesCreateChild_m_optionalComposite(_parent, #_id, _d, m_optionalComposite); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesCreateChild test_unionTypesCreateChild
#endif
TEST_EXPORT test_unionTypes* _test_unionTypesCreateChild_m_optionalReference(corto_object _parent, corto_string _id, test_TypeKind _d, corto_object* m_optionalReference);
#define test_unionTypesCreateChild_m_optionalReference(_parent, _id, _d, m_optionalReference) _test_unionTypesCreateChild_m_optionalReference(_parent, _id, _d, corto_object__optional_##m_optionalReference)
#define test_unionTypesCreateChild_m_optionalReference_auto(_parent, _id, _d, m_optionalReference) test_unionTypes* _id = test_unionTypesCreateChild_m_optionalReference(_parent, #_id, _d, m_optionalReference); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesCreateChild test_unionTypesCreateChild
#endif
TEST_EXPORT test_unionTypes* _test_unionTypesCreateChild_m_optionalArray(corto_object _parent, corto_string _id, test_TypeKind _d, test_IntArray* m_optionalArray);
#define test_unionTypesCreateChild_m_optionalArray(_parent, _id, _d, m_optionalArray) _test_unionTypesCreateChild_m_optionalArray(_parent, _id, _d, test_IntArray__optional_##m_optionalArray)
#define test_unionTypesCreateChild_m_optionalArray_auto(_parent, _id, _d, m_optionalArray) test_unionTypes* _id = test_unionTypesCreateChild_m_optionalArray(_parent, #_id, _d, m_optionalArray); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesCreateChild test_unionTypesCreateChild
#endif
TEST_EXPORT test_unionTypes* _test_unionTypesCreateChild_m_optionalSequence(corto_object _parent, corto_string _id, test_TypeKind _d, test_IntSequence* m_optionalSequence);
#define test_unionTypesCreateChild_m_optionalSequence(_parent, _id, _d, m_optionalSequence) _test_unionTypesCreateChild_m_optionalSequence(_parent, _id, _d, test_IntSequence__optional_##m_optionalSequence)
#define test_unionTypesCreateChild_m_optionalSequence_auto(_parent, _id, _d, m_optionalSequence) test_unionTypes* _id = test_unionTypesCreateChild_m_optionalSequence(_parent, #_id, _d, m_optionalSequence); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesCreateChild test_unionTypesCreateChild
#endif
TEST_EXPORT test_unionTypes* _test_unionTypesCreateChild_m_optionalList(corto_object _parent, corto_string _id, test_TypeKind _d, test_IntList* m_optionalList);
#define test_unionTypesCreateChild_m_optionalList(_parent, _id, _d, m_optionalList) _test_unionTypesCreateChild_m_optionalList(_parent, _id, _d, test_IntList__optional_##m_optionalList)
#define test_unionTypesCreateChild_m_optionalList_auto(_parent, _id, _d, m_optionalList) test_unionTypes* _id = test_unionTypesCreateChild_m_optionalList(_parent, #_id, _d, m_optionalList); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesUpdate test_unionTypesUpdate
#endif
TEST_EXPORT corto_int16 _test_unionTypesUpdate_m_int(test_unionTypes* _this, test_TypeKind _d, int32_t m_int);
#define test_unionTypesUpdate_m_int(_this, _d, m_int) _test_unionTypesUpdate_m_int(test_unionTypes(_this), _d, m_int)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesUpdate test_unionTypesUpdate
#endif
TEST_EXPORT corto_int16 _test_unionTypesUpdate_m_string(test_unionTypes* _this, test_TypeKind _d, corto_string m_string);
#define test_unionTypesUpdate_m_string(_this, _d, m_string) _test_unionTypesUpdate_m_string(test_unionTypes(_this), _d, m_string)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesUpdate test_unionTypesUpdate
#endif
TEST_EXPORT corto_int16 _test_unionTypesUpdate_m_composite(test_unionTypes* _this, test_TypeKind _d, test_Point* m_composite);
#define test_unionTypesUpdate_m_composite(_this, _d, m_composite) _test_unionTypesUpdate_m_composite(test_unionTypes(_this), _d, m_composite)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesUpdate test_unionTypesUpdate
#endif
TEST_EXPORT corto_int16 _test_unionTypesUpdate_m_reference(test_unionTypes* _this, test_TypeKind _d, corto_object m_reference);
#define test_unionTypesUpdate_m_reference(_this, _d, m_reference) _test_unionTypesUpdate_m_reference(test_unionTypes(_this), _d, m_reference)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesUpdate test_unionTypesUpdate
#endif
TEST_EXPORT corto_int16 _test_unionTypesUpdate_m_array(test_unionTypes* _this, test_TypeKind _d, test_IntArray m_array);
#define test_unionTypesUpdate_m_array(_this, _d, m_array) _test_unionTypesUpdate_m_array(test_unionTypes(_this), _d, m_array)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesUpdate test_unionTypesUpdate
#endif
TEST_EXPORT corto_int16 _test_unionTypesUpdate_m_sequence(test_unionTypes* _this, test_TypeKind _d, test_IntSequence m_sequence);
#define test_unionTypesUpdate_m_sequence(_this, _d, m_sequence) _test_unionTypesUpdate_m_sequence(test_unionTypes(_this), _d, m_sequence)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesUpdate test_unionTypesUpdate
#endif
TEST_EXPORT corto_int16 _test_unionTypesUpdate_m_list(test_unionTypes* _this, test_TypeKind _d, test_IntList m_list);
#define test_unionTypesUpdate_m_list(_this, _d, m_list) _test_unionTypesUpdate_m_list(test_unionTypes(_this), _d, m_list)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesUpdate test_unionTypesUpdate
#endif
TEST_EXPORT corto_int16 _test_unionTypesUpdate_m_optionalInt(test_unionTypes* _this, test_TypeKind _d, int32_t* m_optionalInt);
#define test_unionTypesUpdate_m_optionalInt(_this, _d, m_optionalInt) _test_unionTypesUpdate_m_optionalInt(test_unionTypes(_this), _d, corto_int32__optional_##m_optionalInt)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesUpdate test_unionTypesUpdate
#endif
TEST_EXPORT corto_int16 _test_unionTypesUpdate_m_optionalString(test_unionTypes* _this, test_TypeKind _d, corto_string* m_optionalString);
#define test_unionTypesUpdate_m_optionalString(_this, _d, m_optionalString) _test_unionTypesUpdate_m_optionalString(test_unionTypes(_this), _d, corto_string__optional_##m_optionalString)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesUpdate test_unionTypesUpdate
#endif
TEST_EXPORT corto_int16 _test_unionTypesUpdate_m_optionalComposite(test_unionTypes* _this, test_TypeKind _d, test_Point* m_optionalComposite);
#define test_unionTypesUpdate_m_optionalComposite(_this, _d, m_optionalComposite) _test_unionTypesUpdate_m_optionalComposite(test_unionTypes(_this), _d, test_Point__optional_##m_optionalComposite)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesUpdate test_unionTypesUpdate
#endif
TEST_EXPORT corto_int16 _test_unionTypesUpdate_m_optionalReference(test_unionTypes* _this, test_TypeKind _d, corto_object* m_optionalReference);
#define test_unionTypesUpdate_m_optionalReference(_this, _d, m_optionalReference) _test_unionTypesUpdate_m_optionalReference(test_unionTypes(_this), _d, corto_object__optional_##m_optionalReference)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesUpdate test_unionTypesUpdate
#endif
TEST_EXPORT corto_int16 _test_unionTypesUpdate_m_optionalArray(test_unionTypes* _this, test_TypeKind _d, test_IntArray* m_optionalArray);
#define test_unionTypesUpdate_m_optionalArray(_this, _d, m_optionalArray) _test_unionTypesUpdate_m_optionalArray(test_unionTypes(_this), _d, test_IntArray__optional_##m_optionalArray)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesUpdate test_unionTypesUpdate
#endif
TEST_EXPORT corto_int16 _test_unionTypesUpdate_m_optionalSequence(test_unionTypes* _this, test_TypeKind _d, test_IntSequence* m_optionalSequence);
#define test_unionTypesUpdate_m_optionalSequence(_this, _d, m_optionalSequence) _test_unionTypesUpdate_m_optionalSequence(test_unionTypes(_this), _d, test_IntSequence__optional_##m_optionalSequence)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesUpdate test_unionTypesUpdate
#endif
TEST_EXPORT corto_int16 _test_unionTypesUpdate_m_optionalList(test_unionTypes* _this, test_TypeKind _d, test_IntList* m_optionalList);
#define test_unionTypesUpdate_m_optionalList(_this, _d, m_optionalList) _test_unionTypesUpdate_m_optionalList(test_unionTypes(_this), _d, test_IntList__optional_##m_optionalList)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesDeclare test_unionTypesDeclare
#endif
TEST_EXPORT test_unionTypes* _test_unionTypesDeclare(void);
#define test_unionTypesDeclare() _test_unionTypesDeclare()
#define test_unionTypesDeclare_auto(_id) test_unionTypes* _id = test_unionTypesDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesDeclareChild test_unionTypesDeclareChild
#endif
TEST_EXPORT test_unionTypes* _test_unionTypesDeclareChild(corto_object _parent, corto_string _id);
#define test_unionTypesDeclareChild(_parent, _id) _test_unionTypesDeclareChild(_parent, _id)
#define test_unionTypesDeclareChild_auto(_parent, _id) test_unionTypes* _id = test_unionTypesDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesDefine test_unionTypesDefine
#endif
TEST_EXPORT corto_int16 _test_unionTypesDefine_m_int(test_unionTypes* _this, test_TypeKind _d, int32_t m_int);
#define test_unionTypesDefine_m_int(_this, _d, m_int) _test_unionTypesDefine_m_int(test_unionTypes(_this), _d, m_int)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesDefine test_unionTypesDefine
#endif
TEST_EXPORT corto_int16 _test_unionTypesDefine_m_string(test_unionTypes* _this, test_TypeKind _d, corto_string m_string);
#define test_unionTypesDefine_m_string(_this, _d, m_string) _test_unionTypesDefine_m_string(test_unionTypes(_this), _d, m_string)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesDefine test_unionTypesDefine
#endif
TEST_EXPORT corto_int16 _test_unionTypesDefine_m_composite(test_unionTypes* _this, test_TypeKind _d, test_Point* m_composite);
#define test_unionTypesDefine_m_composite(_this, _d, m_composite) _test_unionTypesDefine_m_composite(test_unionTypes(_this), _d, m_composite)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesDefine test_unionTypesDefine
#endif
TEST_EXPORT corto_int16 _test_unionTypesDefine_m_reference(test_unionTypes* _this, test_TypeKind _d, corto_object m_reference);
#define test_unionTypesDefine_m_reference(_this, _d, m_reference) _test_unionTypesDefine_m_reference(test_unionTypes(_this), _d, m_reference)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesDefine test_unionTypesDefine
#endif
TEST_EXPORT corto_int16 _test_unionTypesDefine_m_array(test_unionTypes* _this, test_TypeKind _d, test_IntArray m_array);
#define test_unionTypesDefine_m_array(_this, _d, m_array) _test_unionTypesDefine_m_array(test_unionTypes(_this), _d, m_array)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesDefine test_unionTypesDefine
#endif
TEST_EXPORT corto_int16 _test_unionTypesDefine_m_sequence(test_unionTypes* _this, test_TypeKind _d, test_IntSequence m_sequence);
#define test_unionTypesDefine_m_sequence(_this, _d, m_sequence) _test_unionTypesDefine_m_sequence(test_unionTypes(_this), _d, m_sequence)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesDefine test_unionTypesDefine
#endif
TEST_EXPORT corto_int16 _test_unionTypesDefine_m_list(test_unionTypes* _this, test_TypeKind _d, test_IntList m_list);
#define test_unionTypesDefine_m_list(_this, _d, m_list) _test_unionTypesDefine_m_list(test_unionTypes(_this), _d, m_list)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesDefine test_unionTypesDefine
#endif
TEST_EXPORT corto_int16 _test_unionTypesDefine_m_optionalInt(test_unionTypes* _this, test_TypeKind _d, int32_t* m_optionalInt);
#define test_unionTypesDefine_m_optionalInt(_this, _d, m_optionalInt) _test_unionTypesDefine_m_optionalInt(test_unionTypes(_this), _d, corto_int32__optional_##m_optionalInt)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesDefine test_unionTypesDefine
#endif
TEST_EXPORT corto_int16 _test_unionTypesDefine_m_optionalString(test_unionTypes* _this, test_TypeKind _d, corto_string* m_optionalString);
#define test_unionTypesDefine_m_optionalString(_this, _d, m_optionalString) _test_unionTypesDefine_m_optionalString(test_unionTypes(_this), _d, corto_string__optional_##m_optionalString)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesDefine test_unionTypesDefine
#endif
TEST_EXPORT corto_int16 _test_unionTypesDefine_m_optionalComposite(test_unionTypes* _this, test_TypeKind _d, test_Point* m_optionalComposite);
#define test_unionTypesDefine_m_optionalComposite(_this, _d, m_optionalComposite) _test_unionTypesDefine_m_optionalComposite(test_unionTypes(_this), _d, test_Point__optional_##m_optionalComposite)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesDefine test_unionTypesDefine
#endif
TEST_EXPORT corto_int16 _test_unionTypesDefine_m_optionalReference(test_unionTypes* _this, test_TypeKind _d, corto_object* m_optionalReference);
#define test_unionTypesDefine_m_optionalReference(_this, _d, m_optionalReference) _test_unionTypesDefine_m_optionalReference(test_unionTypes(_this), _d, corto_object__optional_##m_optionalReference)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesDefine test_unionTypesDefine
#endif
TEST_EXPORT corto_int16 _test_unionTypesDefine_m_optionalArray(test_unionTypes* _this, test_TypeKind _d, test_IntArray* m_optionalArray);
#define test_unionTypesDefine_m_optionalArray(_this, _d, m_optionalArray) _test_unionTypesDefine_m_optionalArray(test_unionTypes(_this), _d, test_IntArray__optional_##m_optionalArray)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesDefine test_unionTypesDefine
#endif
TEST_EXPORT corto_int16 _test_unionTypesDefine_m_optionalSequence(test_unionTypes* _this, test_TypeKind _d, test_IntSequence* m_optionalSequence);
#define test_unionTypesDefine_m_optionalSequence(_this, _d, m_optionalSequence) _test_unionTypesDefine_m_optionalSequence(test_unionTypes(_this), _d, test_IntSequence__optional_##m_optionalSequence)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesDefine test_unionTypesDefine
#endif
TEST_EXPORT corto_int16 _test_unionTypesDefine_m_optionalList(test_unionTypes* _this, test_TypeKind _d, test_IntList* m_optionalList);
#define test_unionTypesDefine_m_optionalList(_this, _d, m_optionalList) _test_unionTypesDefine_m_optionalList(test_unionTypes(_this), _d, test_IntList__optional_##m_optionalList)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesAssign test_unionTypesAssign
#endif
TEST_EXPORT test_unionTypes* _test_unionTypesAssign_m_int(test_unionTypes* _this, test_TypeKind _d, int32_t m_int);
#define test_unionTypesAssign_m_int(_this, _d, m_int) _test_unionTypesAssign_m_int(_this, _d, m_int)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesAssign test_unionTypesAssign
#endif
TEST_EXPORT test_unionTypes* _test_unionTypesAssign_m_string(test_unionTypes* _this, test_TypeKind _d, corto_string m_string);
#define test_unionTypesAssign_m_string(_this, _d, m_string) _test_unionTypesAssign_m_string(_this, _d, m_string)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesAssign test_unionTypesAssign
#endif
TEST_EXPORT test_unionTypes* _test_unionTypesAssign_m_composite(test_unionTypes* _this, test_TypeKind _d, test_Point* m_composite);
#define test_unionTypesAssign_m_composite(_this, _d, m_composite) _test_unionTypesAssign_m_composite(_this, _d, m_composite)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesAssign test_unionTypesAssign
#endif
TEST_EXPORT test_unionTypes* _test_unionTypesAssign_m_reference(test_unionTypes* _this, test_TypeKind _d, corto_object m_reference);
#define test_unionTypesAssign_m_reference(_this, _d, m_reference) _test_unionTypesAssign_m_reference(_this, _d, m_reference)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesAssign test_unionTypesAssign
#endif
TEST_EXPORT test_unionTypes* _test_unionTypesAssign_m_array(test_unionTypes* _this, test_TypeKind _d, test_IntArray m_array);
#define test_unionTypesAssign_m_array(_this, _d, m_array) _test_unionTypesAssign_m_array(_this, _d, m_array)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesAssign test_unionTypesAssign
#endif
TEST_EXPORT test_unionTypes* _test_unionTypesAssign_m_sequence(test_unionTypes* _this, test_TypeKind _d, test_IntSequence m_sequence);
#define test_unionTypesAssign_m_sequence(_this, _d, m_sequence) _test_unionTypesAssign_m_sequence(_this, _d, m_sequence)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesAssign test_unionTypesAssign
#endif
TEST_EXPORT test_unionTypes* _test_unionTypesAssign_m_list(test_unionTypes* _this, test_TypeKind _d, test_IntList m_list);
#define test_unionTypesAssign_m_list(_this, _d, m_list) _test_unionTypesAssign_m_list(_this, _d, m_list)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesAssign test_unionTypesAssign
#endif
TEST_EXPORT test_unionTypes* _test_unionTypesAssign_m_optionalInt(test_unionTypes* _this, test_TypeKind _d, int32_t* m_optionalInt);
#define test_unionTypesAssign_m_optionalInt(_this, _d, m_optionalInt) _test_unionTypesAssign_m_optionalInt(_this, _d, corto_int32__optional_##m_optionalInt)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesAssign test_unionTypesAssign
#endif
TEST_EXPORT test_unionTypes* _test_unionTypesAssign_m_optionalString(test_unionTypes* _this, test_TypeKind _d, corto_string* m_optionalString);
#define test_unionTypesAssign_m_optionalString(_this, _d, m_optionalString) _test_unionTypesAssign_m_optionalString(_this, _d, corto_string__optional_##m_optionalString)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesAssign test_unionTypesAssign
#endif
TEST_EXPORT test_unionTypes* _test_unionTypesAssign_m_optionalComposite(test_unionTypes* _this, test_TypeKind _d, test_Point* m_optionalComposite);
#define test_unionTypesAssign_m_optionalComposite(_this, _d, m_optionalComposite) _test_unionTypesAssign_m_optionalComposite(_this, _d, test_Point__optional_##m_optionalComposite)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesAssign test_unionTypesAssign
#endif
TEST_EXPORT test_unionTypes* _test_unionTypesAssign_m_optionalReference(test_unionTypes* _this, test_TypeKind _d, corto_object* m_optionalReference);
#define test_unionTypesAssign_m_optionalReference(_this, _d, m_optionalReference) _test_unionTypesAssign_m_optionalReference(_this, _d, corto_object__optional_##m_optionalReference)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesAssign test_unionTypesAssign
#endif
TEST_EXPORT test_unionTypes* _test_unionTypesAssign_m_optionalArray(test_unionTypes* _this, test_TypeKind _d, test_IntArray* m_optionalArray);
#define test_unionTypesAssign_m_optionalArray(_this, _d, m_optionalArray) _test_unionTypesAssign_m_optionalArray(_this, _d, test_IntArray__optional_##m_optionalArray)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesAssign test_unionTypesAssign
#endif
TEST_EXPORT test_unionTypes* _test_unionTypesAssign_m_optionalSequence(test_unionTypes* _this, test_TypeKind _d, test_IntSequence* m_optionalSequence);
#define test_unionTypesAssign_m_optionalSequence(_this, _d, m_optionalSequence) _test_unionTypesAssign_m_optionalSequence(_this, _d, test_IntSequence__optional_##m_optionalSequence)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define unionTypesAssign test_unionTypesAssign
#endif
TEST_EXPORT test_unionTypes* _test_unionTypesAssign_m_optionalList(test_unionTypes* _this, test_TypeKind _d, test_IntList* m_optionalList);
#define test_unionTypesAssign_m_optionalList(_this, _d, m_optionalList) _test_unionTypesAssign_m_optionalList(_this, _d, test_IntList__optional_##m_optionalList)

/* /test/ValueCast */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ValueCastCreate test_ValueCastCreate
#endif
TEST_EXPORT test_ValueCast _test_ValueCastCreate(uint32_t assertCount);
#define test_ValueCastCreate(assertCount) _test_ValueCastCreate(assertCount)
#define test_ValueCastCreate_auto(_id, assertCount) test_ValueCast _id = test_ValueCastCreate(assertCount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ValueCastCreateChild test_ValueCastCreateChild
#endif
TEST_EXPORT test_ValueCast _test_ValueCastCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount);
#define test_ValueCastCreateChild(_parent, _id, assertCount) _test_ValueCastCreateChild(_parent, _id, assertCount)
#define test_ValueCastCreateChild_auto(_parent, _id, assertCount) test_ValueCast _id = test_ValueCastCreateChild(_parent, #_id, assertCount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ValueCastUpdate test_ValueCastUpdate
#endif
TEST_EXPORT corto_int16 _test_ValueCastUpdate(test_ValueCast _this, uint32_t assertCount);
#define test_ValueCastUpdate(_this, assertCount) _test_ValueCastUpdate(test_ValueCast(_this), assertCount)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ValueCastDeclare test_ValueCastDeclare
#endif
TEST_EXPORT test_ValueCast _test_ValueCastDeclare(void);
#define test_ValueCastDeclare() _test_ValueCastDeclare()
#define test_ValueCastDeclare_auto(_id) test_ValueCast _id = test_ValueCastDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ValueCastDeclareChild test_ValueCastDeclareChild
#endif
TEST_EXPORT test_ValueCast _test_ValueCastDeclareChild(corto_object _parent, corto_string _id);
#define test_ValueCastDeclareChild(_parent, _id) _test_ValueCastDeclareChild(_parent, _id)
#define test_ValueCastDeclareChild_auto(_parent, _id) test_ValueCast _id = test_ValueCastDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ValueCastDefine test_ValueCastDefine
#endif
TEST_EXPORT corto_int16 _test_ValueCastDefine(test_ValueCast _this, uint32_t assertCount);
#define test_ValueCastDefine(_this, assertCount) _test_ValueCastDefine(test_ValueCast(_this), assertCount)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ValueCastAssign test_ValueCastAssign
#endif
TEST_EXPORT test_ValueCast _test_ValueCastAssign(test_ValueCast _this, uint32_t assertCount);
#define test_ValueCast__optional_NotSet NULL
#define test_ValueCast__optional_Set(assertCount) test_ValueCastAssign((test_ValueCast*)corto_ptr_new(test_ValueCast_o)), assertCount)
#define test_ValueCast__optional_SetCond(cond, assertCount) cond ? test_ValueCastAssign((test_ValueCast*)corto_ptr_new(test_ValueCast_o), assertCount) : NULL
#define test_ValueCastUnset(_this) _this ? corto_ptr_free(_this, test_ValueCast_o), 0 : 0; _this = NULL;
#define test_ValueCastAssign(_this, assertCount) _test_ValueCastAssign(_this, assertCount)
#define test_ValueCastSet(_this, assertCount) _this = _this ? _this : (test_ValueCast*)corto_ptr_new(test_ValueCast_o); _test_ValueCastAssign(_this, assertCount)

/* /test/ValueExpr */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ValueExprCreate test_ValueExprCreate
#endif
TEST_EXPORT test_ValueExpr _test_ValueExprCreate(uint32_t assertCount);
#define test_ValueExprCreate(assertCount) _test_ValueExprCreate(assertCount)
#define test_ValueExprCreate_auto(_id, assertCount) test_ValueExpr _id = test_ValueExprCreate(assertCount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ValueExprCreateChild test_ValueExprCreateChild
#endif
TEST_EXPORT test_ValueExpr _test_ValueExprCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount);
#define test_ValueExprCreateChild(_parent, _id, assertCount) _test_ValueExprCreateChild(_parent, _id, assertCount)
#define test_ValueExprCreateChild_auto(_parent, _id, assertCount) test_ValueExpr _id = test_ValueExprCreateChild(_parent, #_id, assertCount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ValueExprUpdate test_ValueExprUpdate
#endif
TEST_EXPORT corto_int16 _test_ValueExprUpdate(test_ValueExpr _this, uint32_t assertCount);
#define test_ValueExprUpdate(_this, assertCount) _test_ValueExprUpdate(test_ValueExpr(_this), assertCount)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ValueExprDeclare test_ValueExprDeclare
#endif
TEST_EXPORT test_ValueExpr _test_ValueExprDeclare(void);
#define test_ValueExprDeclare() _test_ValueExprDeclare()
#define test_ValueExprDeclare_auto(_id) test_ValueExpr _id = test_ValueExprDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ValueExprDeclareChild test_ValueExprDeclareChild
#endif
TEST_EXPORT test_ValueExpr _test_ValueExprDeclareChild(corto_object _parent, corto_string _id);
#define test_ValueExprDeclareChild(_parent, _id) _test_ValueExprDeclareChild(_parent, _id)
#define test_ValueExprDeclareChild_auto(_parent, _id) test_ValueExpr _id = test_ValueExprDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ValueExprDefine test_ValueExprDefine
#endif
TEST_EXPORT corto_int16 _test_ValueExprDefine(test_ValueExpr _this, uint32_t assertCount);
#define test_ValueExprDefine(_this, assertCount) _test_ValueExprDefine(test_ValueExpr(_this), assertCount)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ValueExprAssign test_ValueExprAssign
#endif
TEST_EXPORT test_ValueExpr _test_ValueExprAssign(test_ValueExpr _this, uint32_t assertCount);
#define test_ValueExpr__optional_NotSet NULL
#define test_ValueExpr__optional_Set(assertCount) test_ValueExprAssign((test_ValueExpr*)corto_ptr_new(test_ValueExpr_o)), assertCount)
#define test_ValueExpr__optional_SetCond(cond, assertCount) cond ? test_ValueExprAssign((test_ValueExpr*)corto_ptr_new(test_ValueExpr_o), assertCount) : NULL
#define test_ValueExprUnset(_this) _this ? corto_ptr_free(_this, test_ValueExpr_o), 0 : 0; _this = NULL;
#define test_ValueExprAssign(_this, assertCount) _test_ValueExprAssign(_this, assertCount)
#define test_ValueExprSet(_this, assertCount) _this = _this ? _this : (test_ValueExpr*)corto_ptr_new(test_ValueExpr_o); _test_ValueExprAssign(_this, assertCount)

/* /test/Vehicle */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define VehicleCreate test_VehicleCreate
#endif
TEST_EXPORT test_Vehicle _test_VehicleCreate(void);
#define test_VehicleCreate() _test_VehicleCreate()
#define test_VehicleCreate_auto(_id) test_Vehicle _id = test_VehicleCreate(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define VehicleCreateChild test_VehicleCreateChild
#endif
TEST_EXPORT test_Vehicle _test_VehicleCreateChild(corto_object _parent, corto_string _id);
#define test_VehicleCreateChild(_parent, _id) _test_VehicleCreateChild(_parent, _id)
#define test_VehicleCreateChild_auto(_parent, _id) test_Vehicle _id = test_VehicleCreateChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define VehicleUpdate test_VehicleUpdate
#endif
TEST_EXPORT corto_int16 _test_VehicleUpdate(test_Vehicle _this);
#define test_VehicleUpdate(_this) _test_VehicleUpdate(test_Vehicle(_this))


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define VehicleDeclare test_VehicleDeclare
#endif
TEST_EXPORT test_Vehicle _test_VehicleDeclare(void);
#define test_VehicleDeclare() _test_VehicleDeclare()
#define test_VehicleDeclare_auto(_id) test_Vehicle _id = test_VehicleDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define VehicleDeclareChild test_VehicleDeclareChild
#endif
TEST_EXPORT test_Vehicle _test_VehicleDeclareChild(corto_object _parent, corto_string _id);
#define test_VehicleDeclareChild(_parent, _id) _test_VehicleDeclareChild(_parent, _id)
#define test_VehicleDeclareChild_auto(_parent, _id) test_Vehicle _id = test_VehicleDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define VehicleDefine test_VehicleDefine
#endif
TEST_EXPORT corto_int16 _test_VehicleDefine(test_Vehicle _this);
#define test_VehicleDefine(_this) _test_VehicleDefine(test_Vehicle(_this))

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define VehicleAssign test_VehicleAssign
#endif
TEST_EXPORT test_Vehicle _test_VehicleAssign(test_Vehicle _this);
#define test_Vehicle__optional_NotSet NULL
#define test_Vehicle__optional_Set() test_VehicleAssign((test_Vehicle*)corto_ptr_new(test_Vehicle_o)))
#define test_Vehicle__optional_SetCond(cond) cond ? test_VehicleAssign((test_Vehicle*)corto_ptr_new(test_Vehicle_o)) : NULL
#define test_VehicleUnset(_this) _this ? corto_ptr_free(_this, test_Vehicle_o), 0 : 0; _this = NULL;
#define test_VehicleAssign(_this) _test_VehicleAssign(_this)
#define test_VehicleSet(_this) _this = _this ? _this : (test_Vehicle*)corto_ptr_new(test_Vehicle_o); _test_VehicleAssign(_this)

/* /test/VoidParent */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define VoidParentCreate test_VoidParentCreate
#endif
TEST_EXPORT test_VoidParent* _test_VoidParentCreate(int32_t foo);
#define test_VoidParentCreate(foo) _test_VoidParentCreate(foo)
#define test_VoidParentCreate_auto(_id, foo) test_VoidParent* _id = test_VoidParentCreate(foo); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define VoidParentCreateChild test_VoidParentCreateChild
#endif
TEST_EXPORT test_VoidParent* _test_VoidParentCreateChild(corto_object _parent, corto_string _id, int32_t foo);
#define test_VoidParentCreateChild(_parent, _id, foo) _test_VoidParentCreateChild(_parent, _id, foo)
#define test_VoidParentCreateChild_auto(_parent, _id, foo) test_VoidParent* _id = test_VoidParentCreateChild(_parent, #_id, foo); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define VoidParentUpdate test_VoidParentUpdate
#endif
TEST_EXPORT corto_int16 _test_VoidParentUpdate(test_VoidParent* _this, int32_t foo);
#define test_VoidParentUpdate(_this, foo) _test_VoidParentUpdate(test_VoidParent(_this), foo)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define VoidParentDeclare test_VoidParentDeclare
#endif
TEST_EXPORT test_VoidParent* _test_VoidParentDeclare(void);
#define test_VoidParentDeclare() _test_VoidParentDeclare()
#define test_VoidParentDeclare_auto(_id) test_VoidParent* _id = test_VoidParentDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define VoidParentDeclareChild test_VoidParentDeclareChild
#endif
TEST_EXPORT test_VoidParent* _test_VoidParentDeclareChild(corto_object _parent, corto_string _id);
#define test_VoidParentDeclareChild(_parent, _id) _test_VoidParentDeclareChild(_parent, _id)
#define test_VoidParentDeclareChild_auto(_parent, _id) test_VoidParent* _id = test_VoidParentDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define VoidParentDefine test_VoidParentDefine
#endif
TEST_EXPORT corto_int16 _test_VoidParentDefine(test_VoidParent* _this, int32_t foo);
#define test_VoidParentDefine(_this, foo) _test_VoidParentDefine(test_VoidParent(_this), foo)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define VoidParentAssign test_VoidParentAssign
#endif
TEST_EXPORT test_VoidParent* _test_VoidParentAssign(test_VoidParent* _this, int32_t foo);
#define test_VoidParent__optional_NotSet NULL
#define test_VoidParent__optional_Set(foo) test_VoidParentAssign((test_VoidParent*)corto_ptr_new(test_VoidParent_o)), foo)
#define test_VoidParent__optional_SetCond(cond, foo) cond ? test_VoidParentAssign((test_VoidParent*)corto_ptr_new(test_VoidParent_o), foo) : NULL
#define test_VoidParentUnset(_this) _this ? corto_ptr_free(_this, test_VoidParent_o), 0 : 0; _this = NULL;
#define test_VoidParentAssign(_this, foo) _test_VoidParentAssign(_this, foo)
#define test_VoidParentSet(_this, foo) _this = _this ? _this : (test_VoidParent*)corto_ptr_new(test_VoidParent_o); _test_VoidParentAssign(_this, foo)


/* list{/test/AccessRule,0} */
TEST_EXPORT test_AccessRule* test_AccessRuleListInsertAlloc(test_AccessRuleList list);
TEST_EXPORT test_AccessRule* test_AccessRuleListInsert(test_AccessRuleList list, test_AccessRule* element);
TEST_EXPORT test_AccessRule* test_AccessRuleListAppendAlloc(test_AccessRuleList list);
TEST_EXPORT test_AccessRule* test_AccessRuleListAppend(test_AccessRuleList list, test_AccessRule* element);
TEST_EXPORT test_AccessRule* test_AccessRuleListTakeFirst(test_AccessRuleList list);
TEST_EXPORT test_AccessRule* test_AccessRuleListLast(test_AccessRuleList list);
TEST_EXPORT test_AccessRule* test_AccessRuleListGet(test_AccessRuleList list, corto_uint32 index);
TEST_EXPORT corto_uint32 test_AccessRuleListSize(test_AccessRuleList list);
TEST_EXPORT void test_AccessRuleListClear(test_AccessRuleList list);

/* /test/AllocList */
TEST_EXPORT int64_t* test_AllocListInsertAlloc(test_AllocList list);
TEST_EXPORT int64_t* test_AllocListInsert(test_AllocList list, int64_t element);
TEST_EXPORT int64_t* test_AllocListAppendAlloc(test_AllocList list);
TEST_EXPORT int64_t* test_AllocListAppend(test_AllocList list, int64_t element);
TEST_EXPORT int64_t* test_AllocListTakeFirst(test_AllocList list);
TEST_EXPORT int64_t* test_AllocListLast(test_AllocList list);
TEST_EXPORT int64_t test_AllocListGet(test_AllocList list, corto_uint32 index);
TEST_EXPORT corto_uint32 test_AllocListSize(test_AllocList list);
TEST_EXPORT void test_AllocListClear(test_AllocList list);

/* /test/AllocSequence */
TEST_EXPORT int64_t* test_AllocSequenceAppend(test_AllocSequence *seq, int64_t element);
TEST_EXPORT int64_t* test_AllocSequenceAppendAlloc(test_AllocSequence *seq);
TEST_EXPORT void test_AllocSequenceSize(test_AllocSequence *seq, corto_uint32 length);
TEST_EXPORT void test_AllocSequenceClear(test_AllocSequence *seq);

/* /test/CollectionList */
TEST_EXPORT void test_CollectionListInsert(test_CollectionList list, corto_int32List element);
TEST_EXPORT void test_CollectionListAppend(test_CollectionList list, corto_int32List element);
TEST_EXPORT corto_int32List test_CollectionListTakeFirst(test_CollectionList list);
TEST_EXPORT corto_int32List test_CollectionListLast(test_CollectionList list);
TEST_EXPORT corto_int32List test_CollectionListGet(test_CollectionList list, corto_uint32 index);
TEST_EXPORT corto_uint32 test_CollectionListSize(test_CollectionList list);
TEST_EXPORT void test_CollectionListClear(test_CollectionList list);

/* /test/CompositeList */
TEST_EXPORT test_Point* test_CompositeListInsertAlloc(test_CompositeList list);
TEST_EXPORT test_Point* test_CompositeListInsert(test_CompositeList list, test_Point* element);
TEST_EXPORT test_Point* test_CompositeListAppendAlloc(test_CompositeList list);
TEST_EXPORT test_Point* test_CompositeListAppend(test_CompositeList list, test_Point* element);
TEST_EXPORT test_Point* test_CompositeListTakeFirst(test_CompositeList list);
TEST_EXPORT test_Point* test_CompositeListLast(test_CompositeList list);
TEST_EXPORT test_Point* test_CompositeListGet(test_CompositeList list, corto_uint32 index);
TEST_EXPORT corto_uint32 test_CompositeListSize(test_CompositeList list);
TEST_EXPORT void test_CompositeListClear(test_CompositeList list);

/* /test/CompositeSequence */
TEST_EXPORT test_Point* test_CompositeSequenceAppend(test_CompositeSequence *seq, test_Point element);
TEST_EXPORT test_Point* test_CompositeSequenceAppendAlloc(test_CompositeSequence *seq);
TEST_EXPORT void test_CompositeSequenceSize(test_CompositeSequence *seq, corto_uint32 length);
TEST_EXPORT void test_CompositeSequenceClear(test_CompositeSequence *seq);

/* /test/IntList */
TEST_EXPORT void test_IntListInsert(test_IntList list, int32_t element);
TEST_EXPORT void test_IntListAppend(test_IntList list, int32_t element);
TEST_EXPORT int32_t test_IntListTakeFirst(test_IntList list);
TEST_EXPORT int32_t test_IntListLast(test_IntList list);
TEST_EXPORT int32_t test_IntListGet(test_IntList list, corto_uint32 index);
TEST_EXPORT corto_uint32 test_IntListSize(test_IntList list);
TEST_EXPORT void test_IntListClear(test_IntList list);

/* /test/IntSequence */
TEST_EXPORT int32_t* test_IntSequenceAppend(test_IntSequence *seq, int32_t element);
TEST_EXPORT int32_t* test_IntSequenceAppendAlloc(test_IntSequence *seq);
TEST_EXPORT void test_IntSequenceSize(test_IntSequence *seq, corto_uint32 length);
TEST_EXPORT void test_IntSequenceClear(test_IntSequence *seq);

/* /test/LongIntList */
TEST_EXPORT int64_t* test_LongIntListInsertAlloc(test_LongIntList list);
TEST_EXPORT int64_t* test_LongIntListInsert(test_LongIntList list, int64_t element);
TEST_EXPORT int64_t* test_LongIntListAppendAlloc(test_LongIntList list);
TEST_EXPORT int64_t* test_LongIntListAppend(test_LongIntList list, int64_t element);
TEST_EXPORT int64_t* test_LongIntListTakeFirst(test_LongIntList list);
TEST_EXPORT int64_t* test_LongIntListLast(test_LongIntList list);
TEST_EXPORT int64_t test_LongIntListGet(test_LongIntList list, corto_uint32 index);
TEST_EXPORT corto_uint32 test_LongIntListSize(test_LongIntList list);
TEST_EXPORT void test_LongIntListClear(test_LongIntList list);

/* /test/ObjectList */
TEST_EXPORT void test_ObjectListInsert(test_ObjectList list, corto_object element);
TEST_EXPORT void test_ObjectListAppend(test_ObjectList list, corto_object element);
TEST_EXPORT void test_ObjectListRemove(test_ObjectList list, corto_object element);
TEST_EXPORT corto_object test_ObjectListTakeFirst(test_ObjectList list);
TEST_EXPORT corto_object test_ObjectListLast(test_ObjectList list);
TEST_EXPORT corto_object test_ObjectListGet(test_ObjectList list, corto_uint32 index);
TEST_EXPORT corto_uint32 test_ObjectListSize(test_ObjectList list);
TEST_EXPORT void test_ObjectListClear(test_ObjectList list);

/* /test/ObjectSequence */
TEST_EXPORT corto_object* test_ObjectSequenceAppend(test_ObjectSequence *seq, corto_object element);
TEST_EXPORT corto_object* test_ObjectSequenceAppendAlloc(test_ObjectSequence *seq);
TEST_EXPORT void test_ObjectSequenceSize(test_ObjectSequence *seq, corto_uint32 length);
TEST_EXPORT void test_ObjectSequenceClear(test_ObjectSequence *seq);

/* list{/test/Point,0} */
TEST_EXPORT test_Point* test_PointListInsertAlloc(test_PointList list);
TEST_EXPORT test_Point* test_PointListInsert(test_PointList list, test_Point* element);
TEST_EXPORT test_Point* test_PointListAppendAlloc(test_PointList list);
TEST_EXPORT test_Point* test_PointListAppend(test_PointList list, test_Point* element);
TEST_EXPORT test_Point* test_PointListTakeFirst(test_PointList list);
TEST_EXPORT test_Point* test_PointListLast(test_PointList list);
TEST_EXPORT test_Point* test_PointListGet(test_PointList list, corto_uint32 index);
TEST_EXPORT corto_uint32 test_PointListSize(test_PointList list);
TEST_EXPORT void test_PointListClear(test_PointList list);

/* sequence{/test/Point,0} */
TEST_EXPORT test_Point* test_PointSeqAppend(test_PointSeq *seq, test_Point element);
TEST_EXPORT test_Point* test_PointSeqAppendAlloc(test_PointSeq *seq);
TEST_EXPORT void test_PointSeqSize(test_PointSeq *seq, corto_uint32 length);
TEST_EXPORT void test_PointSeqClear(test_PointSeq *seq);

/* /test/ReferenceList */
TEST_EXPORT void test_ReferenceListInsert(test_ReferenceList list, corto_object element);
TEST_EXPORT void test_ReferenceListAppend(test_ReferenceList list, corto_object element);
TEST_EXPORT void test_ReferenceListRemove(test_ReferenceList list, corto_object element);
TEST_EXPORT corto_object test_ReferenceListTakeFirst(test_ReferenceList list);
TEST_EXPORT corto_object test_ReferenceListLast(test_ReferenceList list);
TEST_EXPORT corto_object test_ReferenceListGet(test_ReferenceList list, corto_uint32 index);
TEST_EXPORT corto_uint32 test_ReferenceListSize(test_ReferenceList list);
TEST_EXPORT void test_ReferenceListClear(test_ReferenceList list);

/* /test/ReferenceSequence */
TEST_EXPORT corto_object* test_ReferenceSequenceAppend(test_ReferenceSequence *seq, corto_object element);
TEST_EXPORT corto_object* test_ReferenceSequenceAppendAlloc(test_ReferenceSequence *seq);
TEST_EXPORT void test_ReferenceSequenceSize(test_ReferenceSequence *seq, corto_uint32 length);
TEST_EXPORT void test_ReferenceSequenceClear(test_ReferenceSequence *seq);

/* /test/StringList */
TEST_EXPORT void test_StringListInsert(test_StringList list, corto_string element);
TEST_EXPORT void test_StringListAppend(test_StringList list, corto_string element);
TEST_EXPORT corto_string test_StringListTakeFirst(test_StringList list);
TEST_EXPORT corto_string test_StringListLast(test_StringList list);
TEST_EXPORT corto_string test_StringListGet(test_StringList list, corto_uint32 index);
TEST_EXPORT corto_uint32 test_StringListSize(test_StringList list);
TEST_EXPORT void test_StringListClear(test_StringList list);

/* /test/StringSequence */
TEST_EXPORT corto_string* test_StringSequenceAppend(test_StringSequence *seq, corto_string element);
TEST_EXPORT corto_string* test_StringSequenceAppendAlloc(test_StringSequence *seq);
TEST_EXPORT void test_StringSequenceSize(test_StringSequence *seq, corto_uint32 length);
TEST_EXPORT void test_StringSequenceClear(test_StringSequence *seq);

/* list{object,0} */
TEST_EXPORT void corto_objectListInsert(corto_objectList list, corto_object element);
TEST_EXPORT void corto_objectListAppend(corto_objectList list, corto_object element);
TEST_EXPORT void corto_objectListRemove(corto_objectList list, corto_object element);
TEST_EXPORT corto_object corto_objectListTakeFirst(corto_objectList list);
TEST_EXPORT corto_object corto_objectListLast(corto_objectList list);
TEST_EXPORT corto_object corto_objectListGet(corto_objectList list, corto_uint32 index);
TEST_EXPORT corto_uint32 corto_objectListSize(corto_objectList list);
TEST_EXPORT void corto_objectListClear(corto_objectList list);

/* list{int32,0} */
TEST_EXPORT void corto_int32ListInsert(corto_int32List list, int32_t element);
TEST_EXPORT void corto_int32ListAppend(corto_int32List list, int32_t element);
TEST_EXPORT int32_t corto_int32ListTakeFirst(corto_int32List list);
TEST_EXPORT int32_t corto_int32ListLast(corto_int32List list);
TEST_EXPORT int32_t corto_int32ListGet(corto_int32List list, corto_uint32 index);
TEST_EXPORT corto_uint32 corto_int32ListSize(corto_int32List list);
TEST_EXPORT void corto_int32ListClear(corto_int32List list);

/* list{string,0} */
TEST_EXPORT void corto_stringListInsert(corto_stringList list, corto_string element);
TEST_EXPORT void corto_stringListAppend(corto_stringList list, corto_string element);
TEST_EXPORT corto_string corto_stringListTakeFirst(corto_stringList list);
TEST_EXPORT corto_string corto_stringListLast(corto_stringList list);
TEST_EXPORT corto_string corto_stringListGet(corto_stringList list, corto_uint32 index);
TEST_EXPORT corto_uint32 corto_stringListSize(corto_stringList list);
TEST_EXPORT void corto_stringListClear(corto_stringList list);

/* sequence{int32,0} */
TEST_EXPORT int32_t* corto_int32SeqAppend(corto_int32Seq *seq, int32_t element);
TEST_EXPORT int32_t* corto_int32SeqAppendAlloc(corto_int32Seq *seq);
TEST_EXPORT void corto_int32SeqSize(corto_int32Seq *seq, corto_uint32 length);
TEST_EXPORT void corto_int32SeqClear(corto_int32Seq *seq);

/* sequence{object,0} */
TEST_EXPORT corto_object* corto_objectSeqAppend(corto_objectSeq *seq, corto_object element);
TEST_EXPORT corto_object* corto_objectSeqAppendAlloc(corto_objectSeq *seq);
TEST_EXPORT void corto_objectSeqSize(corto_objectSeq *seq, corto_uint32 length);
TEST_EXPORT void corto_objectSeqClear(corto_objectSeq *seq);

/* sequence{string,0} */
TEST_EXPORT corto_string* corto_stringSeqAppend(corto_stringSeq *seq, corto_string element);
TEST_EXPORT corto_string* corto_stringSeqAppendAlloc(corto_stringSeq *seq);
TEST_EXPORT void corto_stringSeqSize(corto_stringSeq *seq, corto_uint32 length);
TEST_EXPORT void corto_stringSeqClear(corto_stringSeq *seq);

/* list{/corto/vstore/subscriber,0} */
TEST_EXPORT void corto_subscriberListInsert(corto_subscriberList list, corto_subscriber element);
TEST_EXPORT void corto_subscriberListAppend(corto_subscriberList list, corto_subscriber element);
TEST_EXPORT void corto_subscriberListRemove(corto_subscriberList list, corto_subscriber element);
TEST_EXPORT corto_subscriber corto_subscriberListTakeFirst(corto_subscriberList list);
TEST_EXPORT corto_subscriber corto_subscriberListLast(corto_subscriberList list);
TEST_EXPORT corto_subscriber corto_subscriberListGet(corto_subscriberList list, corto_uint32 index);
TEST_EXPORT corto_uint32 corto_subscriberListSize(corto_subscriberList list);
TEST_EXPORT void corto_subscriberListClear(corto_subscriberList list);

#ifdef __cplusplus
}
#endif
#endif

