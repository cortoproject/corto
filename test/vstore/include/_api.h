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
/* /test/AutoResumeSink */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AutoResumeSinkCreate test_AutoResumeSinkCreate
#endif
TEST_EXPORT test_AutoResumeSink _test_AutoResumeSinkCreate(uint32_t assertCount, int8_t declared, int8_t defined, int8_t updated, int8_t deleted, int8_t resumed, int8_t suspended);
#define test_AutoResumeSinkCreate(assertCount, declared, defined, updated, deleted, resumed, suspended) _test_AutoResumeSinkCreate(assertCount, declared, defined, updated, deleted, resumed, suspended)
#define test_AutoResumeSinkCreate_auto(_id, assertCount, declared, defined, updated, deleted, resumed, suspended) test_AutoResumeSink _id = test_AutoResumeSinkCreate(assertCount, declared, defined, updated, deleted, resumed, suspended); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AutoResumeSinkCreateChild test_AutoResumeSinkCreateChild
#endif
TEST_EXPORT test_AutoResumeSink _test_AutoResumeSinkCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount, int8_t declared, int8_t defined, int8_t updated, int8_t deleted, int8_t resumed, int8_t suspended);
#define test_AutoResumeSinkCreateChild(_parent, _id, assertCount, declared, defined, updated, deleted, resumed, suspended) _test_AutoResumeSinkCreateChild(_parent, _id, assertCount, declared, defined, updated, deleted, resumed, suspended)
#define test_AutoResumeSinkCreateChild_auto(_parent, _id, assertCount, declared, defined, updated, deleted, resumed, suspended) test_AutoResumeSink _id = test_AutoResumeSinkCreateChild(_parent, #_id, assertCount, declared, defined, updated, deleted, resumed, suspended); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AutoResumeSinkUpdate test_AutoResumeSinkUpdate
#endif
TEST_EXPORT corto_int16 _test_AutoResumeSinkUpdate(test_AutoResumeSink _this, uint32_t assertCount, int8_t declared, int8_t defined, int8_t updated, int8_t deleted, int8_t resumed, int8_t suspended);
#define test_AutoResumeSinkUpdate(_this, assertCount, declared, defined, updated, deleted, resumed, suspended) _test_AutoResumeSinkUpdate(test_AutoResumeSink(_this), assertCount, declared, defined, updated, deleted, resumed, suspended)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AutoResumeSinkDeclare test_AutoResumeSinkDeclare
#endif
TEST_EXPORT test_AutoResumeSink _test_AutoResumeSinkDeclare(void);
#define test_AutoResumeSinkDeclare() _test_AutoResumeSinkDeclare()
#define test_AutoResumeSinkDeclare_auto(_id) test_AutoResumeSink _id = test_AutoResumeSinkDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AutoResumeSinkDeclareChild test_AutoResumeSinkDeclareChild
#endif
TEST_EXPORT test_AutoResumeSink _test_AutoResumeSinkDeclareChild(corto_object _parent, corto_string _id);
#define test_AutoResumeSinkDeclareChild(_parent, _id) _test_AutoResumeSinkDeclareChild(_parent, _id)
#define test_AutoResumeSinkDeclareChild_auto(_parent, _id) test_AutoResumeSink _id = test_AutoResumeSinkDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AutoResumeSinkDefine test_AutoResumeSinkDefine
#endif
TEST_EXPORT corto_int16 _test_AutoResumeSinkDefine(test_AutoResumeSink _this, uint32_t assertCount, int8_t declared, int8_t defined, int8_t updated, int8_t deleted, int8_t resumed, int8_t suspended);
#define test_AutoResumeSinkDefine(_this, assertCount, declared, defined, updated, deleted, resumed, suspended) _test_AutoResumeSinkDefine(test_AutoResumeSink(_this), assertCount, declared, defined, updated, deleted, resumed, suspended)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AutoResumeSinkAssign test_AutoResumeSinkAssign
#endif
TEST_EXPORT test_AutoResumeSink _test_AutoResumeSinkAssign(test_AutoResumeSink _this, uint32_t assertCount, int8_t declared, int8_t defined, int8_t updated, int8_t deleted, int8_t resumed, int8_t suspended);
#define test_AutoResumeSink__optional_NotSet NULL
#define test_AutoResumeSink__optional_Set(assertCount, declared, defined, updated, deleted, resumed, suspended) test_AutoResumeSinkAssign((test_AutoResumeSink*)corto_ptr_new(test_AutoResumeSink_o)), assertCount, declared, defined, updated, deleted, resumed, suspended)
#define test_AutoResumeSink__optional_SetCond(cond, assertCount, declared, defined, updated, deleted, resumed, suspended) cond ? test_AutoResumeSinkAssign((test_AutoResumeSink*)corto_ptr_new(test_AutoResumeSink_o), assertCount, declared, defined, updated, deleted, resumed, suspended) : NULL
#define test_AutoResumeSinkUnset(_this) _this ? corto_ptr_free(_this, test_AutoResumeSink_o), 0 : 0; _this = NULL;
#define test_AutoResumeSinkAssign(_this, assertCount, declared, defined, updated, deleted, resumed, suspended) _test_AutoResumeSinkAssign(_this, assertCount, declared, defined, updated, deleted, resumed, suspended)
#define test_AutoResumeSinkSet(_this, assertCount, declared, defined, updated, deleted, resumed, suspended) _this = _this ? _this : (test_AutoResumeSink*)corto_ptr_new(test_AutoResumeSink_o); _test_AutoResumeSinkAssign(_this, assertCount, declared, defined, updated, deleted, resumed, suspended)

/* /test/AutoResumeSinkMount */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AutoResumeSinkMountCreate test_AutoResumeSinkMountCreate
#endif
TEST_EXPORT test_AutoResumeSinkMount _test_AutoResumeSinkMountCreate(corto_object mount, corto_string type_1, corto_string value);
#define test_AutoResumeSinkMountCreate(mount, type_1, value) _test_AutoResumeSinkMountCreate(mount, type_1, value)
#define test_AutoResumeSinkMountCreate_auto(_id, mount, type_1, value) test_AutoResumeSinkMount _id = test_AutoResumeSinkMountCreate(mount, type_1, value); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AutoResumeSinkMountCreateChild test_AutoResumeSinkMountCreateChild
#endif
TEST_EXPORT test_AutoResumeSinkMount _test_AutoResumeSinkMountCreateChild(corto_object _parent, corto_string _id, corto_object mount, corto_string type_1, corto_string value);
#define test_AutoResumeSinkMountCreateChild(_parent, _id, mount, type_1, value) _test_AutoResumeSinkMountCreateChild(_parent, _id, mount, type_1, value)
#define test_AutoResumeSinkMountCreateChild_auto(_parent, _id, mount, type_1, value) test_AutoResumeSinkMount _id = test_AutoResumeSinkMountCreateChild(_parent, #_id, mount, type_1, value); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AutoResumeSinkMountUpdate test_AutoResumeSinkMountUpdate
#endif
TEST_EXPORT corto_int16 _test_AutoResumeSinkMountUpdate(test_AutoResumeSinkMount _this, corto_object mount, corto_string type_1, corto_string value);
#define test_AutoResumeSinkMountUpdate(_this, mount, type_1, value) _test_AutoResumeSinkMountUpdate(test_AutoResumeSinkMount(_this), mount, type_1, value)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AutoResumeSinkMountDeclare test_AutoResumeSinkMountDeclare
#endif
TEST_EXPORT test_AutoResumeSinkMount _test_AutoResumeSinkMountDeclare(void);
#define test_AutoResumeSinkMountDeclare() _test_AutoResumeSinkMountDeclare()
#define test_AutoResumeSinkMountDeclare_auto(_id) test_AutoResumeSinkMount _id = test_AutoResumeSinkMountDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AutoResumeSinkMountDeclareChild test_AutoResumeSinkMountDeclareChild
#endif
TEST_EXPORT test_AutoResumeSinkMount _test_AutoResumeSinkMountDeclareChild(corto_object _parent, corto_string _id);
#define test_AutoResumeSinkMountDeclareChild(_parent, _id) _test_AutoResumeSinkMountDeclareChild(_parent, _id)
#define test_AutoResumeSinkMountDeclareChild_auto(_parent, _id) test_AutoResumeSinkMount _id = test_AutoResumeSinkMountDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AutoResumeSinkMountDefine test_AutoResumeSinkMountDefine
#endif
TEST_EXPORT corto_int16 _test_AutoResumeSinkMountDefine(test_AutoResumeSinkMount _this, corto_object mount, corto_string type_1, corto_string value);
#define test_AutoResumeSinkMountDefine(_this, mount, type_1, value) _test_AutoResumeSinkMountDefine(test_AutoResumeSinkMount(_this), mount, type_1, value)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define AutoResumeSinkMountAssign test_AutoResumeSinkMountAssign
#endif
TEST_EXPORT test_AutoResumeSinkMount _test_AutoResumeSinkMountAssign(test_AutoResumeSinkMount _this, corto_object mount, corto_string type_1, corto_string value);
#define test_AutoResumeSinkMount__optional_NotSet NULL
#define test_AutoResumeSinkMount__optional_Set(mount, type_1, value) test_AutoResumeSinkMountAssign((test_AutoResumeSinkMount*)corto_ptr_new(test_AutoResumeSinkMount_o)), mount, type_1, value)
#define test_AutoResumeSinkMount__optional_SetCond(cond, mount, type_1, value) cond ? test_AutoResumeSinkMountAssign((test_AutoResumeSinkMount*)corto_ptr_new(test_AutoResumeSinkMount_o), mount, type_1, value) : NULL
#define test_AutoResumeSinkMountUnset(_this) _this ? corto_ptr_free(_this, test_AutoResumeSinkMount_o), 0 : 0; _this = NULL;
#define test_AutoResumeSinkMountAssign(_this, mount, type_1, value) _test_AutoResumeSinkMountAssign(_this, mount, type_1, value)
#define test_AutoResumeSinkMountSet(_this, mount, type_1, value) _this = _this ? _this : (test_AutoResumeSinkMount*)corto_ptr_new(test_AutoResumeSinkMount_o); _test_AutoResumeSinkMountAssign(_this, mount, type_1, value)

/* /test/EmptySinkMount */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define EmptySinkMountCreate test_EmptySinkMountCreate
#endif
TEST_EXPORT test_EmptySinkMount _test_EmptySinkMountCreate(corto_object mount);
#define test_EmptySinkMountCreate(mount) _test_EmptySinkMountCreate(mount)
#define test_EmptySinkMountCreate_auto(_id, mount) test_EmptySinkMount _id = test_EmptySinkMountCreate(mount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define EmptySinkMountCreateChild test_EmptySinkMountCreateChild
#endif
TEST_EXPORT test_EmptySinkMount _test_EmptySinkMountCreateChild(corto_object _parent, corto_string _id, corto_object mount);
#define test_EmptySinkMountCreateChild(_parent, _id, mount) _test_EmptySinkMountCreateChild(_parent, _id, mount)
#define test_EmptySinkMountCreateChild_auto(_parent, _id, mount) test_EmptySinkMount _id = test_EmptySinkMountCreateChild(_parent, #_id, mount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define EmptySinkMountUpdate test_EmptySinkMountUpdate
#endif
TEST_EXPORT corto_int16 _test_EmptySinkMountUpdate(test_EmptySinkMount _this, corto_object mount);
#define test_EmptySinkMountUpdate(_this, mount) _test_EmptySinkMountUpdate(test_EmptySinkMount(_this), mount)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define EmptySinkMountDeclare test_EmptySinkMountDeclare
#endif
TEST_EXPORT test_EmptySinkMount _test_EmptySinkMountDeclare(void);
#define test_EmptySinkMountDeclare() _test_EmptySinkMountDeclare()
#define test_EmptySinkMountDeclare_auto(_id) test_EmptySinkMount _id = test_EmptySinkMountDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define EmptySinkMountDeclareChild test_EmptySinkMountDeclareChild
#endif
TEST_EXPORT test_EmptySinkMount _test_EmptySinkMountDeclareChild(corto_object _parent, corto_string _id);
#define test_EmptySinkMountDeclareChild(_parent, _id) _test_EmptySinkMountDeclareChild(_parent, _id)
#define test_EmptySinkMountDeclareChild_auto(_parent, _id) test_EmptySinkMount _id = test_EmptySinkMountDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define EmptySinkMountDefine test_EmptySinkMountDefine
#endif
TEST_EXPORT corto_int16 _test_EmptySinkMountDefine(test_EmptySinkMount _this, corto_object mount);
#define test_EmptySinkMountDefine(_this, mount) _test_EmptySinkMountDefine(test_EmptySinkMount(_this), mount)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define EmptySinkMountAssign test_EmptySinkMountAssign
#endif
TEST_EXPORT test_EmptySinkMount _test_EmptySinkMountAssign(test_EmptySinkMount _this, corto_object mount);
#define test_EmptySinkMount__optional_NotSet NULL
#define test_EmptySinkMount__optional_Set(mount) test_EmptySinkMountAssign((test_EmptySinkMount*)corto_ptr_new(test_EmptySinkMount_o)), mount)
#define test_EmptySinkMount__optional_SetCond(cond, mount) cond ? test_EmptySinkMountAssign((test_EmptySinkMount*)corto_ptr_new(test_EmptySinkMount_o), mount) : NULL
#define test_EmptySinkMountUnset(_this) _this ? corto_ptr_free(_this, test_EmptySinkMount_o), 0 : 0; _this = NULL;
#define test_EmptySinkMountAssign(_this, mount) _test_EmptySinkMountAssign(_this, mount)
#define test_EmptySinkMountSet(_this, mount) _this = _this ? _this : (test_EmptySinkMount*)corto_ptr_new(test_EmptySinkMount_o); _test_EmptySinkMountAssign(_this, mount)

/* /test/EventReplicator */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define EventReplicatorCreate test_EventReplicatorCreate
#endif
TEST_EXPORT test_EventReplicator _test_EventReplicatorCreate(corto_query* query, corto_mountPolicy* policy);
#define test_EventReplicatorCreate(query, policy) _test_EventReplicatorCreate(query, policy)
#define test_EventReplicatorCreate_auto(_id, query, policy) test_EventReplicator _id = test_EventReplicatorCreate(query, policy); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define EventReplicatorCreateChild test_EventReplicatorCreateChild
#endif
TEST_EXPORT test_EventReplicator _test_EventReplicatorCreateChild(corto_object _parent, corto_string _id, corto_query* query, corto_mountPolicy* policy);
#define test_EventReplicatorCreateChild(_parent, _id, query, policy) _test_EventReplicatorCreateChild(_parent, _id, query, policy)
#define test_EventReplicatorCreateChild_auto(_parent, _id, query, policy) test_EventReplicator _id = test_EventReplicatorCreateChild(_parent, #_id, query, policy); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define EventReplicatorUpdate test_EventReplicatorUpdate
#endif
TEST_EXPORT corto_int16 _test_EventReplicatorUpdate(test_EventReplicator _this, corto_query* query, corto_mountPolicy* policy);
#define test_EventReplicatorUpdate(_this, query, policy) _test_EventReplicatorUpdate(test_EventReplicator(_this), query, policy)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define EventReplicatorDeclare test_EventReplicatorDeclare
#endif
TEST_EXPORT test_EventReplicator _test_EventReplicatorDeclare(void);
#define test_EventReplicatorDeclare() _test_EventReplicatorDeclare()
#define test_EventReplicatorDeclare_auto(_id) test_EventReplicator _id = test_EventReplicatorDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define EventReplicatorDeclareChild test_EventReplicatorDeclareChild
#endif
TEST_EXPORT test_EventReplicator _test_EventReplicatorDeclareChild(corto_object _parent, corto_string _id);
#define test_EventReplicatorDeclareChild(_parent, _id) _test_EventReplicatorDeclareChild(_parent, _id)
#define test_EventReplicatorDeclareChild_auto(_parent, _id) test_EventReplicator _id = test_EventReplicatorDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define EventReplicatorDefine test_EventReplicatorDefine
#endif
TEST_EXPORT corto_int16 _test_EventReplicatorDefine(test_EventReplicator _this, corto_query* query, corto_mountPolicy* policy);
#define test_EventReplicatorDefine(_this, query, policy) _test_EventReplicatorDefine(test_EventReplicator(_this), query, policy)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define EventReplicatorAssign test_EventReplicatorAssign
#endif
TEST_EXPORT test_EventReplicator _test_EventReplicatorAssign(test_EventReplicator _this, corto_query* query, corto_mountPolicy* policy);
#define test_EventReplicator__optional_NotSet NULL
#define test_EventReplicator__optional_Set(query, policy) test_EventReplicatorAssign((test_EventReplicator*)corto_ptr_new(test_EventReplicator_o)), query, policy)
#define test_EventReplicator__optional_SetCond(cond, query, policy) cond ? test_EventReplicatorAssign((test_EventReplicator*)corto_ptr_new(test_EventReplicator_o), query, policy) : NULL
#define test_EventReplicatorUnset(_this) _this ? corto_ptr_free(_this, test_EventReplicator_o), 0 : 0; _this = NULL;
#define test_EventReplicatorAssign(_this, query, policy) _test_EventReplicatorAssign(_this, query, policy)
#define test_EventReplicatorSet(_this, query, policy) _this = _this ? _this : (test_EventReplicator*)corto_ptr_new(test_EventReplicator_o); _test_EventReplicatorAssign(_this, query, policy)

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

/* /test/FooDispatcher */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define FooDispatcherCreate test_FooDispatcherCreate
#endif
TEST_EXPORT test_FooDispatcher _test_FooDispatcherCreate(void);
#define test_FooDispatcherCreate() _test_FooDispatcherCreate()
#define test_FooDispatcherCreate_auto(_id) test_FooDispatcher _id = test_FooDispatcherCreate(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define FooDispatcherCreateChild test_FooDispatcherCreateChild
#endif
TEST_EXPORT test_FooDispatcher _test_FooDispatcherCreateChild(corto_object _parent, corto_string _id);
#define test_FooDispatcherCreateChild(_parent, _id) _test_FooDispatcherCreateChild(_parent, _id)
#define test_FooDispatcherCreateChild_auto(_parent, _id) test_FooDispatcher _id = test_FooDispatcherCreateChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define FooDispatcherUpdate test_FooDispatcherUpdate
#endif
TEST_EXPORT corto_int16 _test_FooDispatcherUpdate(test_FooDispatcher _this);
#define test_FooDispatcherUpdate(_this) _test_FooDispatcherUpdate(test_FooDispatcher(_this))


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define FooDispatcherDeclare test_FooDispatcherDeclare
#endif
TEST_EXPORT test_FooDispatcher _test_FooDispatcherDeclare(void);
#define test_FooDispatcherDeclare() _test_FooDispatcherDeclare()
#define test_FooDispatcherDeclare_auto(_id) test_FooDispatcher _id = test_FooDispatcherDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define FooDispatcherDeclareChild test_FooDispatcherDeclareChild
#endif
TEST_EXPORT test_FooDispatcher _test_FooDispatcherDeclareChild(corto_object _parent, corto_string _id);
#define test_FooDispatcherDeclareChild(_parent, _id) _test_FooDispatcherDeclareChild(_parent, _id)
#define test_FooDispatcherDeclareChild_auto(_parent, _id) test_FooDispatcher _id = test_FooDispatcherDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define FooDispatcherDefine test_FooDispatcherDefine
#endif
TEST_EXPORT corto_int16 _test_FooDispatcherDefine(test_FooDispatcher _this);
#define test_FooDispatcherDefine(_this) _test_FooDispatcherDefine(test_FooDispatcher(_this))

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define FooDispatcherAssign test_FooDispatcherAssign
#endif
TEST_EXPORT test_FooDispatcher _test_FooDispatcherAssign(test_FooDispatcher _this);
#define test_FooDispatcher__optional_NotSet NULL
#define test_FooDispatcher__optional_Set() test_FooDispatcherAssign((test_FooDispatcher*)corto_ptr_new(test_FooDispatcher_o)))
#define test_FooDispatcher__optional_SetCond(cond) cond ? test_FooDispatcherAssign((test_FooDispatcher*)corto_ptr_new(test_FooDispatcher_o)) : NULL
#define test_FooDispatcherUnset(_this) _this ? corto_ptr_free(_this, test_FooDispatcher_o), 0 : 0; _this = NULL;
#define test_FooDispatcherAssign(_this) _test_FooDispatcherAssign(_this)
#define test_FooDispatcherSet(_this) _this = _this ? _this : (test_FooDispatcher*)corto_ptr_new(test_FooDispatcher_o); _test_FooDispatcherAssign(_this)

/* /test/HistoryMount */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define HistoryMountCreate test_HistoryMountCreate
#endif
TEST_EXPORT test_HistoryMount _test_HistoryMountCreate(corto_object mount);
#define test_HistoryMountCreate(mount) _test_HistoryMountCreate(mount)
#define test_HistoryMountCreate_auto(_id, mount) test_HistoryMount _id = test_HistoryMountCreate(mount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define HistoryMountCreateChild test_HistoryMountCreateChild
#endif
TEST_EXPORT test_HistoryMount _test_HistoryMountCreateChild(corto_object _parent, corto_string _id, corto_object mount);
#define test_HistoryMountCreateChild(_parent, _id, mount) _test_HistoryMountCreateChild(_parent, _id, mount)
#define test_HistoryMountCreateChild_auto(_parent, _id, mount) test_HistoryMount _id = test_HistoryMountCreateChild(_parent, #_id, mount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define HistoryMountUpdate test_HistoryMountUpdate
#endif
TEST_EXPORT corto_int16 _test_HistoryMountUpdate(test_HistoryMount _this, corto_object mount);
#define test_HistoryMountUpdate(_this, mount) _test_HistoryMountUpdate(test_HistoryMount(_this), mount)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define HistoryMountDeclare test_HistoryMountDeclare
#endif
TEST_EXPORT test_HistoryMount _test_HistoryMountDeclare(void);
#define test_HistoryMountDeclare() _test_HistoryMountDeclare()
#define test_HistoryMountDeclare_auto(_id) test_HistoryMount _id = test_HistoryMountDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define HistoryMountDeclareChild test_HistoryMountDeclareChild
#endif
TEST_EXPORT test_HistoryMount _test_HistoryMountDeclareChild(corto_object _parent, corto_string _id);
#define test_HistoryMountDeclareChild(_parent, _id) _test_HistoryMountDeclareChild(_parent, _id)
#define test_HistoryMountDeclareChild_auto(_parent, _id) test_HistoryMount _id = test_HistoryMountDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define HistoryMountDefine test_HistoryMountDefine
#endif
TEST_EXPORT corto_int16 _test_HistoryMountDefine(test_HistoryMount _this, corto_object mount);
#define test_HistoryMountDefine(_this, mount) _test_HistoryMountDefine(test_HistoryMount(_this), mount)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define HistoryMountAssign test_HistoryMountAssign
#endif
TEST_EXPORT test_HistoryMount _test_HistoryMountAssign(test_HistoryMount _this, corto_object mount);
#define test_HistoryMount__optional_NotSet NULL
#define test_HistoryMount__optional_Set(mount) test_HistoryMountAssign((test_HistoryMount*)corto_ptr_new(test_HistoryMount_o)), mount)
#define test_HistoryMount__optional_SetCond(cond, mount) cond ? test_HistoryMountAssign((test_HistoryMount*)corto_ptr_new(test_HistoryMount_o), mount) : NULL
#define test_HistoryMountUnset(_this) _this ? corto_ptr_free(_this, test_HistoryMount_o), 0 : 0; _this = NULL;
#define test_HistoryMountAssign(_this, mount) _test_HistoryMountAssign(_this, mount)
#define test_HistoryMountSet(_this, mount) _this = _this ? _this : (test_HistoryMount*)corto_ptr_new(test_HistoryMount_o); _test_HistoryMountAssign(_this, mount)

/* /test/HistoryMount/data */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define HistoryMount_dataCreate test_HistoryMount_dataCreate
#endif
TEST_EXPORT test_HistoryMount_data* _test_HistoryMount_dataCreate(corto_result* result, corto_stringList history);
#define test_HistoryMount_dataCreate(result, history) _test_HistoryMount_dataCreate(result, history)
#define test_HistoryMount_dataCreate_auto(_id, result, history) test_HistoryMount_data* _id = test_HistoryMount_dataCreate(result, history); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define HistoryMount_dataCreateChild test_HistoryMount_dataCreateChild
#endif
TEST_EXPORT test_HistoryMount_data* _test_HistoryMount_dataCreateChild(corto_object _parent, corto_string _id, corto_result* result, corto_stringList history);
#define test_HistoryMount_dataCreateChild(_parent, _id, result, history) _test_HistoryMount_dataCreateChild(_parent, _id, result, history)
#define test_HistoryMount_dataCreateChild_auto(_parent, _id, result, history) test_HistoryMount_data* _id = test_HistoryMount_dataCreateChild(_parent, #_id, result, history); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define HistoryMount_dataUpdate test_HistoryMount_dataUpdate
#endif
TEST_EXPORT corto_int16 _test_HistoryMount_dataUpdate(test_HistoryMount_data* _this, corto_result* result, corto_stringList history);
#define test_HistoryMount_dataUpdate(_this, result, history) _test_HistoryMount_dataUpdate(test_HistoryMount_data(_this), result, history)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define HistoryMount_dataDeclare test_HistoryMount_dataDeclare
#endif
TEST_EXPORT test_HistoryMount_data* _test_HistoryMount_dataDeclare(void);
#define test_HistoryMount_dataDeclare() _test_HistoryMount_dataDeclare()
#define test_HistoryMount_dataDeclare_auto(_id) test_HistoryMount_data* _id = test_HistoryMount_dataDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define HistoryMount_dataDeclareChild test_HistoryMount_dataDeclareChild
#endif
TEST_EXPORT test_HistoryMount_data* _test_HistoryMount_dataDeclareChild(corto_object _parent, corto_string _id);
#define test_HistoryMount_dataDeclareChild(_parent, _id) _test_HistoryMount_dataDeclareChild(_parent, _id)
#define test_HistoryMount_dataDeclareChild_auto(_parent, _id) test_HistoryMount_data* _id = test_HistoryMount_dataDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define HistoryMount_dataDefine test_HistoryMount_dataDefine
#endif
TEST_EXPORT corto_int16 _test_HistoryMount_dataDefine(test_HistoryMount_data* _this, corto_result* result, corto_stringList history);
#define test_HistoryMount_dataDefine(_this, result, history) _test_HistoryMount_dataDefine(test_HistoryMount_data(_this), result, history)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define HistoryMount_dataAssign test_HistoryMount_dataAssign
#endif
TEST_EXPORT test_HistoryMount_data* _test_HistoryMount_dataAssign(test_HistoryMount_data* _this, corto_result* result, corto_stringList history);
#define test_HistoryMount_data__optional_NotSet NULL
#define test_HistoryMount_data__optional_Set(result, history) test_HistoryMount_dataAssign((test_HistoryMount_data*)corto_ptr_new(test_HistoryMount_data_o)), result, history)
#define test_HistoryMount_data__optional_SetCond(cond, result, history) cond ? test_HistoryMount_dataAssign((test_HistoryMount_data*)corto_ptr_new(test_HistoryMount_data_o), result, history) : NULL
#define test_HistoryMount_dataUnset(_this) _this ? corto_ptr_free(_this, test_HistoryMount_data_o), 0 : 0; _this = NULL;
#define test_HistoryMount_dataAssign(_this, result, history) _test_HistoryMount_dataAssign(_this, result, history)
#define test_HistoryMount_dataSet(_this, result, history) _this = _this ? _this : (test_HistoryMount_data*)corto_ptr_new(test_HistoryMount_data_o); _test_HistoryMount_dataAssign(_this, result, history)

/* /test/IdMount */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define IdMountCreate test_IdMountCreate
#endif
TEST_EXPORT test_IdMount _test_IdMountCreate(corto_object mount, corto_type type);
#define test_IdMountCreate(mount, type) _test_IdMountCreate(mount, corto_type(type))
#define test_IdMountCreate_auto(_id, mount, type) test_IdMount _id = test_IdMountCreate(mount, type); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define IdMountCreateChild test_IdMountCreateChild
#endif
TEST_EXPORT test_IdMount _test_IdMountCreateChild(corto_object _parent, corto_string _id, corto_object mount, corto_type type);
#define test_IdMountCreateChild(_parent, _id, mount, type) _test_IdMountCreateChild(_parent, _id, mount, corto_type(type))
#define test_IdMountCreateChild_auto(_parent, _id, mount, type) test_IdMount _id = test_IdMountCreateChild(_parent, #_id, mount, type); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define IdMountUpdate test_IdMountUpdate
#endif
TEST_EXPORT corto_int16 _test_IdMountUpdate(test_IdMount _this, corto_object mount, corto_type type);
#define test_IdMountUpdate(_this, mount, type) _test_IdMountUpdate(test_IdMount(_this), mount, corto_type(type))


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define IdMountDeclare test_IdMountDeclare
#endif
TEST_EXPORT test_IdMount _test_IdMountDeclare(void);
#define test_IdMountDeclare() _test_IdMountDeclare()
#define test_IdMountDeclare_auto(_id) test_IdMount _id = test_IdMountDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define IdMountDeclareChild test_IdMountDeclareChild
#endif
TEST_EXPORT test_IdMount _test_IdMountDeclareChild(corto_object _parent, corto_string _id);
#define test_IdMountDeclareChild(_parent, _id) _test_IdMountDeclareChild(_parent, _id)
#define test_IdMountDeclareChild_auto(_parent, _id) test_IdMount _id = test_IdMountDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define IdMountDefine test_IdMountDefine
#endif
TEST_EXPORT corto_int16 _test_IdMountDefine(test_IdMount _this, corto_object mount, corto_type type);
#define test_IdMountDefine(_this, mount, type) _test_IdMountDefine(test_IdMount(_this), mount, corto_type(type))

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define IdMountAssign test_IdMountAssign
#endif
TEST_EXPORT test_IdMount _test_IdMountAssign(test_IdMount _this, corto_object mount, corto_type type);
#define test_IdMount__optional_NotSet NULL
#define test_IdMount__optional_Set(mount, type) test_IdMountAssign((test_IdMount*)corto_ptr_new(test_IdMount_o)), mount, type)
#define test_IdMount__optional_SetCond(cond, mount, type) cond ? test_IdMountAssign((test_IdMount*)corto_ptr_new(test_IdMount_o), mount, type) : NULL
#define test_IdMountUnset(_this) _this ? corto_ptr_free(_this, test_IdMount_o), 0 : 0; _this = NULL;
#define test_IdMountAssign(_this, mount, type) _test_IdMountAssign(_this, mount, corto_type(type))
#define test_IdMountSet(_this, mount, type) _this = _this ? _this : (test_IdMount*)corto_ptr_new(test_IdMount_o); _test_IdMountAssign(_this, mount, corto_type(type))

/* /test/JsonReplicator */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define JsonReplicatorCreate test_JsonReplicatorCreate
#endif
TEST_EXPORT test_JsonReplicator _test_JsonReplicatorCreate(corto_object mount);
#define test_JsonReplicatorCreate(mount) _test_JsonReplicatorCreate(mount)
#define test_JsonReplicatorCreate_auto(_id, mount) test_JsonReplicator _id = test_JsonReplicatorCreate(mount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define JsonReplicatorCreateChild test_JsonReplicatorCreateChild
#endif
TEST_EXPORT test_JsonReplicator _test_JsonReplicatorCreateChild(corto_object _parent, corto_string _id, corto_object mount);
#define test_JsonReplicatorCreateChild(_parent, _id, mount) _test_JsonReplicatorCreateChild(_parent, _id, mount)
#define test_JsonReplicatorCreateChild_auto(_parent, _id, mount) test_JsonReplicator _id = test_JsonReplicatorCreateChild(_parent, #_id, mount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define JsonReplicatorUpdate test_JsonReplicatorUpdate
#endif
TEST_EXPORT corto_int16 _test_JsonReplicatorUpdate(test_JsonReplicator _this, corto_object mount);
#define test_JsonReplicatorUpdate(_this, mount) _test_JsonReplicatorUpdate(test_JsonReplicator(_this), mount)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define JsonReplicatorDeclare test_JsonReplicatorDeclare
#endif
TEST_EXPORT test_JsonReplicator _test_JsonReplicatorDeclare(void);
#define test_JsonReplicatorDeclare() _test_JsonReplicatorDeclare()
#define test_JsonReplicatorDeclare_auto(_id) test_JsonReplicator _id = test_JsonReplicatorDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define JsonReplicatorDeclareChild test_JsonReplicatorDeclareChild
#endif
TEST_EXPORT test_JsonReplicator _test_JsonReplicatorDeclareChild(corto_object _parent, corto_string _id);
#define test_JsonReplicatorDeclareChild(_parent, _id) _test_JsonReplicatorDeclareChild(_parent, _id)
#define test_JsonReplicatorDeclareChild_auto(_parent, _id) test_JsonReplicator _id = test_JsonReplicatorDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define JsonReplicatorDefine test_JsonReplicatorDefine
#endif
TEST_EXPORT corto_int16 _test_JsonReplicatorDefine(test_JsonReplicator _this, corto_object mount);
#define test_JsonReplicatorDefine(_this, mount) _test_JsonReplicatorDefine(test_JsonReplicator(_this), mount)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define JsonReplicatorAssign test_JsonReplicatorAssign
#endif
TEST_EXPORT test_JsonReplicator _test_JsonReplicatorAssign(test_JsonReplicator _this, corto_object mount);
#define test_JsonReplicator__optional_NotSet NULL
#define test_JsonReplicator__optional_Set(mount) test_JsonReplicatorAssign((test_JsonReplicator*)corto_ptr_new(test_JsonReplicator_o)), mount)
#define test_JsonReplicator__optional_SetCond(cond, mount) cond ? test_JsonReplicatorAssign((test_JsonReplicator*)corto_ptr_new(test_JsonReplicator_o), mount) : NULL
#define test_JsonReplicatorUnset(_this) _this ? corto_ptr_free(_this, test_JsonReplicator_o), 0 : 0; _this = NULL;
#define test_JsonReplicatorAssign(_this, mount) _test_JsonReplicatorAssign(_this, mount)
#define test_JsonReplicatorSet(_this, mount) _this = _this ? _this : (test_JsonReplicator*)corto_ptr_new(test_JsonReplicator_o); _test_JsonReplicatorAssign(_this, mount)

/* /test/ListMount */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ListMountCreate test_ListMountCreate
#endif
TEST_EXPORT test_ListMount _test_ListMountCreate(corto_object mount, corto_eventMask mask, corto_ownership kind);
#define test_ListMountCreate(mount, mask, kind) _test_ListMountCreate(mount, mask, kind)
#define test_ListMountCreate_auto(_id, mount, mask, kind) test_ListMount _id = test_ListMountCreate(mount, mask, kind); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ListMountCreateChild test_ListMountCreateChild
#endif
TEST_EXPORT test_ListMount _test_ListMountCreateChild(corto_object _parent, corto_string _id, corto_object mount, corto_eventMask mask, corto_ownership kind);
#define test_ListMountCreateChild(_parent, _id, mount, mask, kind) _test_ListMountCreateChild(_parent, _id, mount, mask, kind)
#define test_ListMountCreateChild_auto(_parent, _id, mount, mask, kind) test_ListMount _id = test_ListMountCreateChild(_parent, #_id, mount, mask, kind); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ListMountUpdate test_ListMountUpdate
#endif
TEST_EXPORT corto_int16 _test_ListMountUpdate(test_ListMount _this, corto_object mount, corto_eventMask mask, corto_ownership kind);
#define test_ListMountUpdate(_this, mount, mask, kind) _test_ListMountUpdate(test_ListMount(_this), mount, mask, kind)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ListMountDeclare test_ListMountDeclare
#endif
TEST_EXPORT test_ListMount _test_ListMountDeclare(void);
#define test_ListMountDeclare() _test_ListMountDeclare()
#define test_ListMountDeclare_auto(_id) test_ListMount _id = test_ListMountDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ListMountDeclareChild test_ListMountDeclareChild
#endif
TEST_EXPORT test_ListMount _test_ListMountDeclareChild(corto_object _parent, corto_string _id);
#define test_ListMountDeclareChild(_parent, _id) _test_ListMountDeclareChild(_parent, _id)
#define test_ListMountDeclareChild_auto(_parent, _id) test_ListMount _id = test_ListMountDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ListMountDefine test_ListMountDefine
#endif
TEST_EXPORT corto_int16 _test_ListMountDefine(test_ListMount _this, corto_object mount, corto_eventMask mask, corto_ownership kind);
#define test_ListMountDefine(_this, mount, mask, kind) _test_ListMountDefine(test_ListMount(_this), mount, mask, kind)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ListMountAssign test_ListMountAssign
#endif
TEST_EXPORT test_ListMount _test_ListMountAssign(test_ListMount _this, corto_object mount, corto_eventMask mask, corto_ownership kind);
#define test_ListMount__optional_NotSet NULL
#define test_ListMount__optional_Set(mount, mask, kind) test_ListMountAssign((test_ListMount*)corto_ptr_new(test_ListMount_o)), mount, mask, kind)
#define test_ListMount__optional_SetCond(cond, mount, mask, kind) cond ? test_ListMountAssign((test_ListMount*)corto_ptr_new(test_ListMount_o), mount, mask, kind) : NULL
#define test_ListMountUnset(_this) _this ? corto_ptr_free(_this, test_ListMount_o), 0 : 0; _this = NULL;
#define test_ListMountAssign(_this, mount, mask, kind) _test_ListMountAssign(_this, mount, mask, kind)
#define test_ListMountSet(_this, mount, mask, kind) _this = _this ? _this : (test_ListMount*)corto_ptr_new(test_ListMount_o); _test_ListMountAssign(_this, mount, mask, kind)

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

/* /test/LoaderSimulatorMount */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define LoaderSimulatorMountCreate test_LoaderSimulatorMountCreate
#endif
TEST_EXPORT test_LoaderSimulatorMount _test_LoaderSimulatorMountCreate(void);
#define test_LoaderSimulatorMountCreate() _test_LoaderSimulatorMountCreate()
#define test_LoaderSimulatorMountCreate_auto(_id) test_LoaderSimulatorMount _id = test_LoaderSimulatorMountCreate(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define LoaderSimulatorMountCreateChild test_LoaderSimulatorMountCreateChild
#endif
TEST_EXPORT test_LoaderSimulatorMount _test_LoaderSimulatorMountCreateChild(corto_object _parent, corto_string _id);
#define test_LoaderSimulatorMountCreateChild(_parent, _id) _test_LoaderSimulatorMountCreateChild(_parent, _id)
#define test_LoaderSimulatorMountCreateChild_auto(_parent, _id) test_LoaderSimulatorMount _id = test_LoaderSimulatorMountCreateChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define LoaderSimulatorMountUpdate test_LoaderSimulatorMountUpdate
#endif
TEST_EXPORT corto_int16 _test_LoaderSimulatorMountUpdate(test_LoaderSimulatorMount _this);
#define test_LoaderSimulatorMountUpdate(_this) _test_LoaderSimulatorMountUpdate(test_LoaderSimulatorMount(_this))


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define LoaderSimulatorMountDeclare test_LoaderSimulatorMountDeclare
#endif
TEST_EXPORT test_LoaderSimulatorMount _test_LoaderSimulatorMountDeclare(void);
#define test_LoaderSimulatorMountDeclare() _test_LoaderSimulatorMountDeclare()
#define test_LoaderSimulatorMountDeclare_auto(_id) test_LoaderSimulatorMount _id = test_LoaderSimulatorMountDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define LoaderSimulatorMountDeclareChild test_LoaderSimulatorMountDeclareChild
#endif
TEST_EXPORT test_LoaderSimulatorMount _test_LoaderSimulatorMountDeclareChild(corto_object _parent, corto_string _id);
#define test_LoaderSimulatorMountDeclareChild(_parent, _id) _test_LoaderSimulatorMountDeclareChild(_parent, _id)
#define test_LoaderSimulatorMountDeclareChild_auto(_parent, _id) test_LoaderSimulatorMount _id = test_LoaderSimulatorMountDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define LoaderSimulatorMountDefine test_LoaderSimulatorMountDefine
#endif
TEST_EXPORT corto_int16 _test_LoaderSimulatorMountDefine(test_LoaderSimulatorMount _this);
#define test_LoaderSimulatorMountDefine(_this) _test_LoaderSimulatorMountDefine(test_LoaderSimulatorMount(_this))

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define LoaderSimulatorMountAssign test_LoaderSimulatorMountAssign
#endif
TEST_EXPORT test_LoaderSimulatorMount _test_LoaderSimulatorMountAssign(test_LoaderSimulatorMount _this);
#define test_LoaderSimulatorMount__optional_NotSet NULL
#define test_LoaderSimulatorMount__optional_Set() test_LoaderSimulatorMountAssign((test_LoaderSimulatorMount*)corto_ptr_new(test_LoaderSimulatorMount_o)))
#define test_LoaderSimulatorMount__optional_SetCond(cond) cond ? test_LoaderSimulatorMountAssign((test_LoaderSimulatorMount*)corto_ptr_new(test_LoaderSimulatorMount_o)) : NULL
#define test_LoaderSimulatorMountUnset(_this) _this ? corto_ptr_free(_this, test_LoaderSimulatorMount_o), 0 : 0; _this = NULL;
#define test_LoaderSimulatorMountAssign(_this) _test_LoaderSimulatorMountAssign(_this)
#define test_LoaderSimulatorMountSet(_this) _this = _this ? _this : (test_LoaderSimulatorMount*)corto_ptr_new(test_LoaderSimulatorMount_o); _test_LoaderSimulatorMountAssign(_this)

/* /test/MountId */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MountIdCreate test_MountIdCreate
#endif
TEST_EXPORT test_MountId _test_MountIdCreate(uint32_t assertCount);
#define test_MountIdCreate(assertCount) _test_MountIdCreate(assertCount)
#define test_MountIdCreate_auto(_id, assertCount) test_MountId _id = test_MountIdCreate(assertCount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MountIdCreateChild test_MountIdCreateChild
#endif
TEST_EXPORT test_MountId _test_MountIdCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount);
#define test_MountIdCreateChild(_parent, _id, assertCount) _test_MountIdCreateChild(_parent, _id, assertCount)
#define test_MountIdCreateChild_auto(_parent, _id, assertCount) test_MountId _id = test_MountIdCreateChild(_parent, #_id, assertCount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MountIdUpdate test_MountIdUpdate
#endif
TEST_EXPORT corto_int16 _test_MountIdUpdate(test_MountId _this, uint32_t assertCount);
#define test_MountIdUpdate(_this, assertCount) _test_MountIdUpdate(test_MountId(_this), assertCount)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MountIdDeclare test_MountIdDeclare
#endif
TEST_EXPORT test_MountId _test_MountIdDeclare(void);
#define test_MountIdDeclare() _test_MountIdDeclare()
#define test_MountIdDeclare_auto(_id) test_MountId _id = test_MountIdDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MountIdDeclareChild test_MountIdDeclareChild
#endif
TEST_EXPORT test_MountId _test_MountIdDeclareChild(corto_object _parent, corto_string _id);
#define test_MountIdDeclareChild(_parent, _id) _test_MountIdDeclareChild(_parent, _id)
#define test_MountIdDeclareChild_auto(_parent, _id) test_MountId _id = test_MountIdDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MountIdDefine test_MountIdDefine
#endif
TEST_EXPORT corto_int16 _test_MountIdDefine(test_MountId _this, uint32_t assertCount);
#define test_MountIdDefine(_this, assertCount) _test_MountIdDefine(test_MountId(_this), assertCount)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MountIdAssign test_MountIdAssign
#endif
TEST_EXPORT test_MountId _test_MountIdAssign(test_MountId _this, uint32_t assertCount);
#define test_MountId__optional_NotSet NULL
#define test_MountId__optional_Set(assertCount) test_MountIdAssign((test_MountId*)corto_ptr_new(test_MountId_o)), assertCount)
#define test_MountId__optional_SetCond(cond, assertCount) cond ? test_MountIdAssign((test_MountId*)corto_ptr_new(test_MountId_o), assertCount) : NULL
#define test_MountIdUnset(_this) _this ? corto_ptr_free(_this, test_MountId_o), 0 : 0; _this = NULL;
#define test_MountIdAssign(_this, assertCount) _test_MountIdAssign(_this, assertCount)
#define test_MountIdSet(_this, assertCount) _this = _this ? _this : (test_MountId*)corto_ptr_new(test_MountId_o); _test_MountIdAssign(_this, assertCount)

/* /test/MountIterCount */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MountIterCountCreate test_MountIterCountCreate
#endif
TEST_EXPORT test_MountIterCount _test_MountIterCountCreate(corto_object mount);
#define test_MountIterCountCreate(mount) _test_MountIterCountCreate(mount)
#define test_MountIterCountCreate_auto(_id, mount) test_MountIterCount _id = test_MountIterCountCreate(mount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MountIterCountCreateChild test_MountIterCountCreateChild
#endif
TEST_EXPORT test_MountIterCount _test_MountIterCountCreateChild(corto_object _parent, corto_string _id, corto_object mount);
#define test_MountIterCountCreateChild(_parent, _id, mount) _test_MountIterCountCreateChild(_parent, _id, mount)
#define test_MountIterCountCreateChild_auto(_parent, _id, mount) test_MountIterCount _id = test_MountIterCountCreateChild(_parent, #_id, mount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MountIterCountUpdate test_MountIterCountUpdate
#endif
TEST_EXPORT corto_int16 _test_MountIterCountUpdate(test_MountIterCount _this, corto_object mount);
#define test_MountIterCountUpdate(_this, mount) _test_MountIterCountUpdate(test_MountIterCount(_this), mount)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MountIterCountDeclare test_MountIterCountDeclare
#endif
TEST_EXPORT test_MountIterCount _test_MountIterCountDeclare(void);
#define test_MountIterCountDeclare() _test_MountIterCountDeclare()
#define test_MountIterCountDeclare_auto(_id) test_MountIterCount _id = test_MountIterCountDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MountIterCountDeclareChild test_MountIterCountDeclareChild
#endif
TEST_EXPORT test_MountIterCount _test_MountIterCountDeclareChild(corto_object _parent, corto_string _id);
#define test_MountIterCountDeclareChild(_parent, _id) _test_MountIterCountDeclareChild(_parent, _id)
#define test_MountIterCountDeclareChild_auto(_parent, _id) test_MountIterCount _id = test_MountIterCountDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MountIterCountDefine test_MountIterCountDefine
#endif
TEST_EXPORT corto_int16 _test_MountIterCountDefine(test_MountIterCount _this, corto_object mount);
#define test_MountIterCountDefine(_this, mount) _test_MountIterCountDefine(test_MountIterCount(_this), mount)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MountIterCountAssign test_MountIterCountAssign
#endif
TEST_EXPORT test_MountIterCount _test_MountIterCountAssign(test_MountIterCount _this, corto_object mount);
#define test_MountIterCount__optional_NotSet NULL
#define test_MountIterCount__optional_Set(mount) test_MountIterCountAssign((test_MountIterCount*)corto_ptr_new(test_MountIterCount_o)), mount)
#define test_MountIterCount__optional_SetCond(cond, mount) cond ? test_MountIterCountAssign((test_MountIterCount*)corto_ptr_new(test_MountIterCount_o), mount) : NULL
#define test_MountIterCountUnset(_this) _this ? corto_ptr_free(_this, test_MountIterCount_o), 0 : 0; _this = NULL;
#define test_MountIterCountAssign(_this, mount) _test_MountIterCountAssign(_this, mount)
#define test_MountIterCountSet(_this, mount) _this = _this ? _this : (test_MountIterCount*)corto_ptr_new(test_MountIterCount_o); _test_MountIterCountAssign(_this, mount)

/* /test/MountMounts */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MountMountsCreate test_MountMountsCreate
#endif
TEST_EXPORT test_MountMounts _test_MountMountsCreate(uint32_t assertCount);
#define test_MountMountsCreate(assertCount) _test_MountMountsCreate(assertCount)
#define test_MountMountsCreate_auto(_id, assertCount) test_MountMounts _id = test_MountMountsCreate(assertCount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MountMountsCreateChild test_MountMountsCreateChild
#endif
TEST_EXPORT test_MountMounts _test_MountMountsCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount);
#define test_MountMountsCreateChild(_parent, _id, assertCount) _test_MountMountsCreateChild(_parent, _id, assertCount)
#define test_MountMountsCreateChild_auto(_parent, _id, assertCount) test_MountMounts _id = test_MountMountsCreateChild(_parent, #_id, assertCount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MountMountsUpdate test_MountMountsUpdate
#endif
TEST_EXPORT corto_int16 _test_MountMountsUpdate(test_MountMounts _this, uint32_t assertCount);
#define test_MountMountsUpdate(_this, assertCount) _test_MountMountsUpdate(test_MountMounts(_this), assertCount)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MountMountsDeclare test_MountMountsDeclare
#endif
TEST_EXPORT test_MountMounts _test_MountMountsDeclare(void);
#define test_MountMountsDeclare() _test_MountMountsDeclare()
#define test_MountMountsDeclare_auto(_id) test_MountMounts _id = test_MountMountsDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MountMountsDeclareChild test_MountMountsDeclareChild
#endif
TEST_EXPORT test_MountMounts _test_MountMountsDeclareChild(corto_object _parent, corto_string _id);
#define test_MountMountsDeclareChild(_parent, _id) _test_MountMountsDeclareChild(_parent, _id)
#define test_MountMountsDeclareChild_auto(_parent, _id) test_MountMounts _id = test_MountMountsDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MountMountsDefine test_MountMountsDefine
#endif
TEST_EXPORT corto_int16 _test_MountMountsDefine(test_MountMounts _this, uint32_t assertCount);
#define test_MountMountsDefine(_this, assertCount) _test_MountMountsDefine(test_MountMounts(_this), assertCount)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MountMountsAssign test_MountMountsAssign
#endif
TEST_EXPORT test_MountMounts _test_MountMountsAssign(test_MountMounts _this, uint32_t assertCount);
#define test_MountMounts__optional_NotSet NULL
#define test_MountMounts__optional_Set(assertCount) test_MountMountsAssign((test_MountMounts*)corto_ptr_new(test_MountMounts_o)), assertCount)
#define test_MountMounts__optional_SetCond(cond, assertCount) cond ? test_MountMountsAssign((test_MountMounts*)corto_ptr_new(test_MountMounts_o), assertCount) : NULL
#define test_MountMountsUnset(_this) _this ? corto_ptr_free(_this, test_MountMounts_o), 0 : 0; _this = NULL;
#define test_MountMountsAssign(_this, assertCount) _test_MountMountsAssign(_this, assertCount)
#define test_MountMountsSet(_this, assertCount) _this = _this ? _this : (test_MountMounts*)corto_ptr_new(test_MountMounts_o); _test_MountMountsAssign(_this, assertCount)

/* /test/MountSubscription */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MountSubscriptionCreate test_MountSubscriptionCreate
#endif
TEST_EXPORT test_MountSubscription _test_MountSubscriptionCreate(uint32_t assertCount);
#define test_MountSubscriptionCreate(assertCount) _test_MountSubscriptionCreate(assertCount)
#define test_MountSubscriptionCreate_auto(_id, assertCount) test_MountSubscription _id = test_MountSubscriptionCreate(assertCount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MountSubscriptionCreateChild test_MountSubscriptionCreateChild
#endif
TEST_EXPORT test_MountSubscription _test_MountSubscriptionCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount);
#define test_MountSubscriptionCreateChild(_parent, _id, assertCount) _test_MountSubscriptionCreateChild(_parent, _id, assertCount)
#define test_MountSubscriptionCreateChild_auto(_parent, _id, assertCount) test_MountSubscription _id = test_MountSubscriptionCreateChild(_parent, #_id, assertCount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MountSubscriptionUpdate test_MountSubscriptionUpdate
#endif
TEST_EXPORT corto_int16 _test_MountSubscriptionUpdate(test_MountSubscription _this, uint32_t assertCount);
#define test_MountSubscriptionUpdate(_this, assertCount) _test_MountSubscriptionUpdate(test_MountSubscription(_this), assertCount)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MountSubscriptionDeclare test_MountSubscriptionDeclare
#endif
TEST_EXPORT test_MountSubscription _test_MountSubscriptionDeclare(void);
#define test_MountSubscriptionDeclare() _test_MountSubscriptionDeclare()
#define test_MountSubscriptionDeclare_auto(_id) test_MountSubscription _id = test_MountSubscriptionDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MountSubscriptionDeclareChild test_MountSubscriptionDeclareChild
#endif
TEST_EXPORT test_MountSubscription _test_MountSubscriptionDeclareChild(corto_object _parent, corto_string _id);
#define test_MountSubscriptionDeclareChild(_parent, _id) _test_MountSubscriptionDeclareChild(_parent, _id)
#define test_MountSubscriptionDeclareChild_auto(_parent, _id) test_MountSubscription _id = test_MountSubscriptionDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MountSubscriptionDefine test_MountSubscriptionDefine
#endif
TEST_EXPORT corto_int16 _test_MountSubscriptionDefine(test_MountSubscription _this, uint32_t assertCount);
#define test_MountSubscriptionDefine(_this, assertCount) _test_MountSubscriptionDefine(test_MountSubscription(_this), assertCount)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MountSubscriptionAssign test_MountSubscriptionAssign
#endif
TEST_EXPORT test_MountSubscription _test_MountSubscriptionAssign(test_MountSubscription _this, uint32_t assertCount);
#define test_MountSubscription__optional_NotSet NULL
#define test_MountSubscription__optional_Set(assertCount) test_MountSubscriptionAssign((test_MountSubscription*)corto_ptr_new(test_MountSubscription_o)), assertCount)
#define test_MountSubscription__optional_SetCond(cond, assertCount) cond ? test_MountSubscriptionAssign((test_MountSubscription*)corto_ptr_new(test_MountSubscription_o), assertCount) : NULL
#define test_MountSubscriptionUnset(_this) _this ? corto_ptr_free(_this, test_MountSubscription_o), 0 : 0; _this = NULL;
#define test_MountSubscriptionAssign(_this, assertCount) _test_MountSubscriptionAssign(_this, assertCount)
#define test_MountSubscriptionSet(_this, assertCount) _this = _this ? _this : (test_MountSubscription*)corto_ptr_new(test_MountSubscription_o); _test_MountSubscriptionAssign(_this, assertCount)

/* /test/MountWIterData */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MountWIterDataCreate test_MountWIterDataCreate
#endif
TEST_EXPORT test_MountWIterData _test_MountWIterDataCreate(corto_object mount);
#define test_MountWIterDataCreate(mount) _test_MountWIterDataCreate(mount)
#define test_MountWIterDataCreate_auto(_id, mount) test_MountWIterData _id = test_MountWIterDataCreate(mount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MountWIterDataCreateChild test_MountWIterDataCreateChild
#endif
TEST_EXPORT test_MountWIterData _test_MountWIterDataCreateChild(corto_object _parent, corto_string _id, corto_object mount);
#define test_MountWIterDataCreateChild(_parent, _id, mount) _test_MountWIterDataCreateChild(_parent, _id, mount)
#define test_MountWIterDataCreateChild_auto(_parent, _id, mount) test_MountWIterData _id = test_MountWIterDataCreateChild(_parent, #_id, mount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MountWIterDataUpdate test_MountWIterDataUpdate
#endif
TEST_EXPORT corto_int16 _test_MountWIterDataUpdate(test_MountWIterData _this, corto_object mount);
#define test_MountWIterDataUpdate(_this, mount) _test_MountWIterDataUpdate(test_MountWIterData(_this), mount)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MountWIterDataDeclare test_MountWIterDataDeclare
#endif
TEST_EXPORT test_MountWIterData _test_MountWIterDataDeclare(void);
#define test_MountWIterDataDeclare() _test_MountWIterDataDeclare()
#define test_MountWIterDataDeclare_auto(_id) test_MountWIterData _id = test_MountWIterDataDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MountWIterDataDeclareChild test_MountWIterDataDeclareChild
#endif
TEST_EXPORT test_MountWIterData _test_MountWIterDataDeclareChild(corto_object _parent, corto_string _id);
#define test_MountWIterDataDeclareChild(_parent, _id) _test_MountWIterDataDeclareChild(_parent, _id)
#define test_MountWIterDataDeclareChild_auto(_parent, _id) test_MountWIterData _id = test_MountWIterDataDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MountWIterDataDefine test_MountWIterDataDefine
#endif
TEST_EXPORT corto_int16 _test_MountWIterDataDefine(test_MountWIterData _this, corto_object mount);
#define test_MountWIterDataDefine(_this, mount) _test_MountWIterDataDefine(test_MountWIterData(_this), mount)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define MountWIterDataAssign test_MountWIterDataAssign
#endif
TEST_EXPORT test_MountWIterData _test_MountWIterDataAssign(test_MountWIterData _this, corto_object mount);
#define test_MountWIterData__optional_NotSet NULL
#define test_MountWIterData__optional_Set(mount) test_MountWIterDataAssign((test_MountWIterData*)corto_ptr_new(test_MountWIterData_o)), mount)
#define test_MountWIterData__optional_SetCond(cond, mount) cond ? test_MountWIterDataAssign((test_MountWIterData*)corto_ptr_new(test_MountWIterData_o), mount) : NULL
#define test_MountWIterDataUnset(_this) _this ? corto_ptr_free(_this, test_MountWIterData_o), 0 : 0; _this = NULL;
#define test_MountWIterDataAssign(_this, mount) _test_MountWIterDataAssign(_this, mount)
#define test_MountWIterDataSet(_this, mount) _this = _this ? _this : (test_MountWIterData*)corto_ptr_new(test_MountWIterData_o); _test_MountWIterDataAssign(_this, mount)

/* /test/ObjectMount */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ObjectMountCreate test_ObjectMountCreate
#endif
TEST_EXPORT test_ObjectMount _test_ObjectMountCreate(corto_string select, corto_string from, corto_result* item);
#define test_ObjectMountCreate(select, from, item) _test_ObjectMountCreate(select, from, item)
#define test_ObjectMountCreate_auto(_id, select, from, item) test_ObjectMount _id = test_ObjectMountCreate(select, from, item); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ObjectMountCreateChild test_ObjectMountCreateChild
#endif
TEST_EXPORT test_ObjectMount _test_ObjectMountCreateChild(corto_object _parent, corto_string _id, corto_string select, corto_string from, corto_result* item);
#define test_ObjectMountCreateChild(_parent, _id, select, from, item) _test_ObjectMountCreateChild(_parent, _id, select, from, item)
#define test_ObjectMountCreateChild_auto(_parent, _id, select, from, item) test_ObjectMount _id = test_ObjectMountCreateChild(_parent, #_id, select, from, item); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ObjectMountUpdate test_ObjectMountUpdate
#endif
TEST_EXPORT corto_int16 _test_ObjectMountUpdate(test_ObjectMount _this, corto_string select, corto_string from, corto_result* item);
#define test_ObjectMountUpdate(_this, select, from, item) _test_ObjectMountUpdate(test_ObjectMount(_this), select, from, item)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ObjectMountDeclare test_ObjectMountDeclare
#endif
TEST_EXPORT test_ObjectMount _test_ObjectMountDeclare(void);
#define test_ObjectMountDeclare() _test_ObjectMountDeclare()
#define test_ObjectMountDeclare_auto(_id) test_ObjectMount _id = test_ObjectMountDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ObjectMountDeclareChild test_ObjectMountDeclareChild
#endif
TEST_EXPORT test_ObjectMount _test_ObjectMountDeclareChild(corto_object _parent, corto_string _id);
#define test_ObjectMountDeclareChild(_parent, _id) _test_ObjectMountDeclareChild(_parent, _id)
#define test_ObjectMountDeclareChild_auto(_parent, _id) test_ObjectMount _id = test_ObjectMountDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ObjectMountDefine test_ObjectMountDefine
#endif
TEST_EXPORT corto_int16 _test_ObjectMountDefine(test_ObjectMount _this, corto_string select, corto_string from, corto_result* item);
#define test_ObjectMountDefine(_this, select, from, item) _test_ObjectMountDefine(test_ObjectMount(_this), select, from, item)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ObjectMountAssign test_ObjectMountAssign
#endif
TEST_EXPORT test_ObjectMount _test_ObjectMountAssign(test_ObjectMount _this, corto_string select, corto_string from, corto_result* item);
#define test_ObjectMount__optional_NotSet NULL
#define test_ObjectMount__optional_Set(select, from, item) test_ObjectMountAssign((test_ObjectMount*)corto_ptr_new(test_ObjectMount_o)), select, from, item)
#define test_ObjectMount__optional_SetCond(cond, select, from, item) cond ? test_ObjectMountAssign((test_ObjectMount*)corto_ptr_new(test_ObjectMount_o), select, from, item) : NULL
#define test_ObjectMountUnset(_this) _this ? corto_ptr_free(_this, test_ObjectMount_o), 0 : 0; _this = NULL;
#define test_ObjectMountAssign(_this, select, from, item) _test_ObjectMountAssign(_this, select, from, item)
#define test_ObjectMountSet(_this, select, from, item) _this = _this ? _this : (test_ObjectMount*)corto_ptr_new(test_ObjectMount_o); _test_ObjectMountAssign(_this, select, from, item)

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

/* /test/ReplicatorEvent */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ReplicatorEventCreate test_ReplicatorEventCreate
#endif
TEST_EXPORT test_ReplicatorEvent _test_ReplicatorEventCreate(uint32_t assertCount);
#define test_ReplicatorEventCreate(assertCount) _test_ReplicatorEventCreate(assertCount)
#define test_ReplicatorEventCreate_auto(_id, assertCount) test_ReplicatorEvent _id = test_ReplicatorEventCreate(assertCount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ReplicatorEventCreateChild test_ReplicatorEventCreateChild
#endif
TEST_EXPORT test_ReplicatorEvent _test_ReplicatorEventCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount);
#define test_ReplicatorEventCreateChild(_parent, _id, assertCount) _test_ReplicatorEventCreateChild(_parent, _id, assertCount)
#define test_ReplicatorEventCreateChild_auto(_parent, _id, assertCount) test_ReplicatorEvent _id = test_ReplicatorEventCreateChild(_parent, #_id, assertCount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ReplicatorEventUpdate test_ReplicatorEventUpdate
#endif
TEST_EXPORT corto_int16 _test_ReplicatorEventUpdate(test_ReplicatorEvent _this, uint32_t assertCount);
#define test_ReplicatorEventUpdate(_this, assertCount) _test_ReplicatorEventUpdate(test_ReplicatorEvent(_this), assertCount)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ReplicatorEventDeclare test_ReplicatorEventDeclare
#endif
TEST_EXPORT test_ReplicatorEvent _test_ReplicatorEventDeclare(void);
#define test_ReplicatorEventDeclare() _test_ReplicatorEventDeclare()
#define test_ReplicatorEventDeclare_auto(_id) test_ReplicatorEvent _id = test_ReplicatorEventDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ReplicatorEventDeclareChild test_ReplicatorEventDeclareChild
#endif
TEST_EXPORT test_ReplicatorEvent _test_ReplicatorEventDeclareChild(corto_object _parent, corto_string _id);
#define test_ReplicatorEventDeclareChild(_parent, _id) _test_ReplicatorEventDeclareChild(_parent, _id)
#define test_ReplicatorEventDeclareChild_auto(_parent, _id) test_ReplicatorEvent _id = test_ReplicatorEventDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ReplicatorEventDefine test_ReplicatorEventDefine
#endif
TEST_EXPORT corto_int16 _test_ReplicatorEventDefine(test_ReplicatorEvent _this, uint32_t assertCount);
#define test_ReplicatorEventDefine(_this, assertCount) _test_ReplicatorEventDefine(test_ReplicatorEvent(_this), assertCount)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ReplicatorEventAssign test_ReplicatorEventAssign
#endif
TEST_EXPORT test_ReplicatorEvent _test_ReplicatorEventAssign(test_ReplicatorEvent _this, uint32_t assertCount);
#define test_ReplicatorEvent__optional_NotSet NULL
#define test_ReplicatorEvent__optional_Set(assertCount) test_ReplicatorEventAssign((test_ReplicatorEvent*)corto_ptr_new(test_ReplicatorEvent_o)), assertCount)
#define test_ReplicatorEvent__optional_SetCond(cond, assertCount) cond ? test_ReplicatorEventAssign((test_ReplicatorEvent*)corto_ptr_new(test_ReplicatorEvent_o), assertCount) : NULL
#define test_ReplicatorEventUnset(_this) _this ? corto_ptr_free(_this, test_ReplicatorEvent_o), 0 : 0; _this = NULL;
#define test_ReplicatorEventAssign(_this, assertCount) _test_ReplicatorEventAssign(_this, assertCount)
#define test_ReplicatorEventSet(_this, assertCount) _this = _this ? _this : (test_ReplicatorEvent*)corto_ptr_new(test_ReplicatorEvent_o); _test_ReplicatorEventAssign(_this, assertCount)

/* /test/ResumeSink */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ResumeSinkCreate test_ResumeSinkCreate
#endif
TEST_EXPORT test_ResumeSink _test_ResumeSinkCreate(uint32_t assertCount, int8_t declared, int8_t defined, int8_t updated, int8_t deleted, int8_t resumed, int8_t suspended);
#define test_ResumeSinkCreate(assertCount, declared, defined, updated, deleted, resumed, suspended) _test_ResumeSinkCreate(assertCount, declared, defined, updated, deleted, resumed, suspended)
#define test_ResumeSinkCreate_auto(_id, assertCount, declared, defined, updated, deleted, resumed, suspended) test_ResumeSink _id = test_ResumeSinkCreate(assertCount, declared, defined, updated, deleted, resumed, suspended); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ResumeSinkCreateChild test_ResumeSinkCreateChild
#endif
TEST_EXPORT test_ResumeSink _test_ResumeSinkCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount, int8_t declared, int8_t defined, int8_t updated, int8_t deleted, int8_t resumed, int8_t suspended);
#define test_ResumeSinkCreateChild(_parent, _id, assertCount, declared, defined, updated, deleted, resumed, suspended) _test_ResumeSinkCreateChild(_parent, _id, assertCount, declared, defined, updated, deleted, resumed, suspended)
#define test_ResumeSinkCreateChild_auto(_parent, _id, assertCount, declared, defined, updated, deleted, resumed, suspended) test_ResumeSink _id = test_ResumeSinkCreateChild(_parent, #_id, assertCount, declared, defined, updated, deleted, resumed, suspended); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ResumeSinkUpdate test_ResumeSinkUpdate
#endif
TEST_EXPORT corto_int16 _test_ResumeSinkUpdate(test_ResumeSink _this, uint32_t assertCount, int8_t declared, int8_t defined, int8_t updated, int8_t deleted, int8_t resumed, int8_t suspended);
#define test_ResumeSinkUpdate(_this, assertCount, declared, defined, updated, deleted, resumed, suspended) _test_ResumeSinkUpdate(test_ResumeSink(_this), assertCount, declared, defined, updated, deleted, resumed, suspended)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ResumeSinkDeclare test_ResumeSinkDeclare
#endif
TEST_EXPORT test_ResumeSink _test_ResumeSinkDeclare(void);
#define test_ResumeSinkDeclare() _test_ResumeSinkDeclare()
#define test_ResumeSinkDeclare_auto(_id) test_ResumeSink _id = test_ResumeSinkDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ResumeSinkDeclareChild test_ResumeSinkDeclareChild
#endif
TEST_EXPORT test_ResumeSink _test_ResumeSinkDeclareChild(corto_object _parent, corto_string _id);
#define test_ResumeSinkDeclareChild(_parent, _id) _test_ResumeSinkDeclareChild(_parent, _id)
#define test_ResumeSinkDeclareChild_auto(_parent, _id) test_ResumeSink _id = test_ResumeSinkDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ResumeSinkDefine test_ResumeSinkDefine
#endif
TEST_EXPORT corto_int16 _test_ResumeSinkDefine(test_ResumeSink _this, uint32_t assertCount, int8_t declared, int8_t defined, int8_t updated, int8_t deleted, int8_t resumed, int8_t suspended);
#define test_ResumeSinkDefine(_this, assertCount, declared, defined, updated, deleted, resumed, suspended) _test_ResumeSinkDefine(test_ResumeSink(_this), assertCount, declared, defined, updated, deleted, resumed, suspended)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define ResumeSinkAssign test_ResumeSinkAssign
#endif
TEST_EXPORT test_ResumeSink _test_ResumeSinkAssign(test_ResumeSink _this, uint32_t assertCount, int8_t declared, int8_t defined, int8_t updated, int8_t deleted, int8_t resumed, int8_t suspended);
#define test_ResumeSink__optional_NotSet NULL
#define test_ResumeSink__optional_Set(assertCount, declared, defined, updated, deleted, resumed, suspended) test_ResumeSinkAssign((test_ResumeSink*)corto_ptr_new(test_ResumeSink_o)), assertCount, declared, defined, updated, deleted, resumed, suspended)
#define test_ResumeSink__optional_SetCond(cond, assertCount, declared, defined, updated, deleted, resumed, suspended) cond ? test_ResumeSinkAssign((test_ResumeSink*)corto_ptr_new(test_ResumeSink_o), assertCount, declared, defined, updated, deleted, resumed, suspended) : NULL
#define test_ResumeSinkUnset(_this) _this ? corto_ptr_free(_this, test_ResumeSink_o), 0 : 0; _this = NULL;
#define test_ResumeSinkAssign(_this, assertCount, declared, defined, updated, deleted, resumed, suspended) _test_ResumeSinkAssign(_this, assertCount, declared, defined, updated, deleted, resumed, suspended)
#define test_ResumeSinkSet(_this, assertCount, declared, defined, updated, deleted, resumed, suspended) _this = _this ? _this : (test_ResumeSink*)corto_ptr_new(test_ResumeSink_o); _test_ResumeSinkAssign(_this, assertCount, declared, defined, updated, deleted, resumed, suspended)

/* /test/SelectContentType */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SelectContentTypeCreate test_SelectContentTypeCreate
#endif
TEST_EXPORT test_SelectContentType _test_SelectContentTypeCreate(uint32_t assertCount);
#define test_SelectContentTypeCreate(assertCount) _test_SelectContentTypeCreate(assertCount)
#define test_SelectContentTypeCreate_auto(_id, assertCount) test_SelectContentType _id = test_SelectContentTypeCreate(assertCount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SelectContentTypeCreateChild test_SelectContentTypeCreateChild
#endif
TEST_EXPORT test_SelectContentType _test_SelectContentTypeCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount);
#define test_SelectContentTypeCreateChild(_parent, _id, assertCount) _test_SelectContentTypeCreateChild(_parent, _id, assertCount)
#define test_SelectContentTypeCreateChild_auto(_parent, _id, assertCount) test_SelectContentType _id = test_SelectContentTypeCreateChild(_parent, #_id, assertCount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SelectContentTypeUpdate test_SelectContentTypeUpdate
#endif
TEST_EXPORT corto_int16 _test_SelectContentTypeUpdate(test_SelectContentType _this, uint32_t assertCount);
#define test_SelectContentTypeUpdate(_this, assertCount) _test_SelectContentTypeUpdate(test_SelectContentType(_this), assertCount)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SelectContentTypeDeclare test_SelectContentTypeDeclare
#endif
TEST_EXPORT test_SelectContentType _test_SelectContentTypeDeclare(void);
#define test_SelectContentTypeDeclare() _test_SelectContentTypeDeclare()
#define test_SelectContentTypeDeclare_auto(_id) test_SelectContentType _id = test_SelectContentTypeDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SelectContentTypeDeclareChild test_SelectContentTypeDeclareChild
#endif
TEST_EXPORT test_SelectContentType _test_SelectContentTypeDeclareChild(corto_object _parent, corto_string _id);
#define test_SelectContentTypeDeclareChild(_parent, _id) _test_SelectContentTypeDeclareChild(_parent, _id)
#define test_SelectContentTypeDeclareChild_auto(_parent, _id) test_SelectContentType _id = test_SelectContentTypeDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SelectContentTypeDefine test_SelectContentTypeDefine
#endif
TEST_EXPORT corto_int16 _test_SelectContentTypeDefine(test_SelectContentType _this, uint32_t assertCount);
#define test_SelectContentTypeDefine(_this, assertCount) _test_SelectContentTypeDefine(test_SelectContentType(_this), assertCount)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SelectContentTypeAssign test_SelectContentTypeAssign
#endif
TEST_EXPORT test_SelectContentType _test_SelectContentTypeAssign(test_SelectContentType _this, uint32_t assertCount);
#define test_SelectContentType__optional_NotSet NULL
#define test_SelectContentType__optional_Set(assertCount) test_SelectContentTypeAssign((test_SelectContentType*)corto_ptr_new(test_SelectContentType_o)), assertCount)
#define test_SelectContentType__optional_SetCond(cond, assertCount) cond ? test_SelectContentTypeAssign((test_SelectContentType*)corto_ptr_new(test_SelectContentType_o), assertCount) : NULL
#define test_SelectContentTypeUnset(_this) _this ? corto_ptr_free(_this, test_SelectContentType_o), 0 : 0; _this = NULL;
#define test_SelectContentTypeAssign(_this, assertCount) _test_SelectContentTypeAssign(_this, assertCount)
#define test_SelectContentTypeSet(_this, assertCount) _this = _this ? _this : (test_SelectContentType*)corto_ptr_new(test_SelectContentType_o); _test_SelectContentTypeAssign(_this, assertCount)

/* /test/SelectHistory */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SelectHistoryCreate test_SelectHistoryCreate
#endif
TEST_EXPORT test_SelectHistory _test_SelectHistoryCreate(uint32_t assertCount);
#define test_SelectHistoryCreate(assertCount) _test_SelectHistoryCreate(assertCount)
#define test_SelectHistoryCreate_auto(_id, assertCount) test_SelectHistory _id = test_SelectHistoryCreate(assertCount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SelectHistoryCreateChild test_SelectHistoryCreateChild
#endif
TEST_EXPORT test_SelectHistory _test_SelectHistoryCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount);
#define test_SelectHistoryCreateChild(_parent, _id, assertCount) _test_SelectHistoryCreateChild(_parent, _id, assertCount)
#define test_SelectHistoryCreateChild_auto(_parent, _id, assertCount) test_SelectHistory _id = test_SelectHistoryCreateChild(_parent, #_id, assertCount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SelectHistoryUpdate test_SelectHistoryUpdate
#endif
TEST_EXPORT corto_int16 _test_SelectHistoryUpdate(test_SelectHistory _this, uint32_t assertCount);
#define test_SelectHistoryUpdate(_this, assertCount) _test_SelectHistoryUpdate(test_SelectHistory(_this), assertCount)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SelectHistoryDeclare test_SelectHistoryDeclare
#endif
TEST_EXPORT test_SelectHistory _test_SelectHistoryDeclare(void);
#define test_SelectHistoryDeclare() _test_SelectHistoryDeclare()
#define test_SelectHistoryDeclare_auto(_id) test_SelectHistory _id = test_SelectHistoryDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SelectHistoryDeclareChild test_SelectHistoryDeclareChild
#endif
TEST_EXPORT test_SelectHistory _test_SelectHistoryDeclareChild(corto_object _parent, corto_string _id);
#define test_SelectHistoryDeclareChild(_parent, _id) _test_SelectHistoryDeclareChild(_parent, _id)
#define test_SelectHistoryDeclareChild_auto(_parent, _id) test_SelectHistory _id = test_SelectHistoryDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SelectHistoryDefine test_SelectHistoryDefine
#endif
TEST_EXPORT corto_int16 _test_SelectHistoryDefine(test_SelectHistory _this, uint32_t assertCount);
#define test_SelectHistoryDefine(_this, assertCount) _test_SelectHistoryDefine(test_SelectHistory(_this), assertCount)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SelectHistoryAssign test_SelectHistoryAssign
#endif
TEST_EXPORT test_SelectHistory _test_SelectHistoryAssign(test_SelectHistory _this, uint32_t assertCount);
#define test_SelectHistory__optional_NotSet NULL
#define test_SelectHistory__optional_Set(assertCount) test_SelectHistoryAssign((test_SelectHistory*)corto_ptr_new(test_SelectHistory_o)), assertCount)
#define test_SelectHistory__optional_SetCond(cond, assertCount) cond ? test_SelectHistoryAssign((test_SelectHistory*)corto_ptr_new(test_SelectHistory_o), assertCount) : NULL
#define test_SelectHistoryUnset(_this) _this ? corto_ptr_free(_this, test_SelectHistory_o), 0 : 0; _this = NULL;
#define test_SelectHistoryAssign(_this, assertCount) _test_SelectHistoryAssign(_this, assertCount)
#define test_SelectHistorySet(_this, assertCount) _this = _this ? _this : (test_SelectHistory*)corto_ptr_new(test_SelectHistory_o); _test_SelectHistoryAssign(_this, assertCount)

/* /test/SelectMount */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SelectMountCreate test_SelectMountCreate
#endif
TEST_EXPORT test_SelectMount _test_SelectMountCreate(uint32_t assertCount, test_ListMount mount);
#define test_SelectMountCreate(assertCount, mount) _test_SelectMountCreate(assertCount, test_ListMount(mount))
#define test_SelectMountCreate_auto(_id, assertCount, mount) test_SelectMount _id = test_SelectMountCreate(assertCount, mount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SelectMountCreateChild test_SelectMountCreateChild
#endif
TEST_EXPORT test_SelectMount _test_SelectMountCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount, test_ListMount mount);
#define test_SelectMountCreateChild(_parent, _id, assertCount, mount) _test_SelectMountCreateChild(_parent, _id, assertCount, test_ListMount(mount))
#define test_SelectMountCreateChild_auto(_parent, _id, assertCount, mount) test_SelectMount _id = test_SelectMountCreateChild(_parent, #_id, assertCount, mount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SelectMountUpdate test_SelectMountUpdate
#endif
TEST_EXPORT corto_int16 _test_SelectMountUpdate(test_SelectMount _this, uint32_t assertCount, test_ListMount mount);
#define test_SelectMountUpdate(_this, assertCount, mount) _test_SelectMountUpdate(test_SelectMount(_this), assertCount, test_ListMount(mount))


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SelectMountDeclare test_SelectMountDeclare
#endif
TEST_EXPORT test_SelectMount _test_SelectMountDeclare(void);
#define test_SelectMountDeclare() _test_SelectMountDeclare()
#define test_SelectMountDeclare_auto(_id) test_SelectMount _id = test_SelectMountDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SelectMountDeclareChild test_SelectMountDeclareChild
#endif
TEST_EXPORT test_SelectMount _test_SelectMountDeclareChild(corto_object _parent, corto_string _id);
#define test_SelectMountDeclareChild(_parent, _id) _test_SelectMountDeclareChild(_parent, _id)
#define test_SelectMountDeclareChild_auto(_parent, _id) test_SelectMount _id = test_SelectMountDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SelectMountDefine test_SelectMountDefine
#endif
TEST_EXPORT corto_int16 _test_SelectMountDefine(test_SelectMount _this, uint32_t assertCount, test_ListMount mount);
#define test_SelectMountDefine(_this, assertCount, mount) _test_SelectMountDefine(test_SelectMount(_this), assertCount, test_ListMount(mount))

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SelectMountAssign test_SelectMountAssign
#endif
TEST_EXPORT test_SelectMount _test_SelectMountAssign(test_SelectMount _this, uint32_t assertCount, test_ListMount mount);
#define test_SelectMount__optional_NotSet NULL
#define test_SelectMount__optional_Set(assertCount, mount) test_SelectMountAssign((test_SelectMount*)corto_ptr_new(test_SelectMount_o)), assertCount, mount)
#define test_SelectMount__optional_SetCond(cond, assertCount, mount) cond ? test_SelectMountAssign((test_SelectMount*)corto_ptr_new(test_SelectMount_o), assertCount, mount) : NULL
#define test_SelectMountUnset(_this) _this ? corto_ptr_free(_this, test_SelectMount_o), 0 : 0; _this = NULL;
#define test_SelectMountAssign(_this, assertCount, mount) _test_SelectMountAssign(_this, assertCount, test_ListMount(mount))
#define test_SelectMountSet(_this, assertCount, mount) _this = _this ? _this : (test_SelectMount*)corto_ptr_new(test_SelectMount_o); _test_SelectMountAssign(_this, assertCount, test_ListMount(mount))

/* /test/SelectSink */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SelectSinkCreate test_SelectSinkCreate
#endif
TEST_EXPORT test_SelectSink _test_SelectSinkCreate(uint32_t assertCount);
#define test_SelectSinkCreate(assertCount) _test_SelectSinkCreate(assertCount)
#define test_SelectSinkCreate_auto(_id, assertCount) test_SelectSink _id = test_SelectSinkCreate(assertCount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SelectSinkCreateChild test_SelectSinkCreateChild
#endif
TEST_EXPORT test_SelectSink _test_SelectSinkCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount);
#define test_SelectSinkCreateChild(_parent, _id, assertCount) _test_SelectSinkCreateChild(_parent, _id, assertCount)
#define test_SelectSinkCreateChild_auto(_parent, _id, assertCount) test_SelectSink _id = test_SelectSinkCreateChild(_parent, #_id, assertCount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SelectSinkUpdate test_SelectSinkUpdate
#endif
TEST_EXPORT corto_int16 _test_SelectSinkUpdate(test_SelectSink _this, uint32_t assertCount);
#define test_SelectSinkUpdate(_this, assertCount) _test_SelectSinkUpdate(test_SelectSink(_this), assertCount)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SelectSinkDeclare test_SelectSinkDeclare
#endif
TEST_EXPORT test_SelectSink _test_SelectSinkDeclare(void);
#define test_SelectSinkDeclare() _test_SelectSinkDeclare()
#define test_SelectSinkDeclare_auto(_id) test_SelectSink _id = test_SelectSinkDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SelectSinkDeclareChild test_SelectSinkDeclareChild
#endif
TEST_EXPORT test_SelectSink _test_SelectSinkDeclareChild(corto_object _parent, corto_string _id);
#define test_SelectSinkDeclareChild(_parent, _id) _test_SelectSinkDeclareChild(_parent, _id)
#define test_SelectSinkDeclareChild_auto(_parent, _id) test_SelectSink _id = test_SelectSinkDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SelectSinkDefine test_SelectSinkDefine
#endif
TEST_EXPORT corto_int16 _test_SelectSinkDefine(test_SelectSink _this, uint32_t assertCount);
#define test_SelectSinkDefine(_this, assertCount) _test_SelectSinkDefine(test_SelectSink(_this), assertCount)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SelectSinkAssign test_SelectSinkAssign
#endif
TEST_EXPORT test_SelectSink _test_SelectSinkAssign(test_SelectSink _this, uint32_t assertCount);
#define test_SelectSink__optional_NotSet NULL
#define test_SelectSink__optional_Set(assertCount) test_SelectSinkAssign((test_SelectSink*)corto_ptr_new(test_SelectSink_o)), assertCount)
#define test_SelectSink__optional_SetCond(cond, assertCount) cond ? test_SelectSinkAssign((test_SelectSink*)corto_ptr_new(test_SelectSink_o), assertCount) : NULL
#define test_SelectSinkUnset(_this) _this ? corto_ptr_free(_this, test_SelectSink_o), 0 : 0; _this = NULL;
#define test_SelectSinkAssign(_this, assertCount) _test_SelectSinkAssign(_this, assertCount)
#define test_SelectSinkSet(_this, assertCount) _this = _this ? _this : (test_SelectSink*)corto_ptr_new(test_SelectSink_o); _test_SelectSinkAssign(_this, assertCount)

/* /test/SelectSinkNoOnRequest */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SelectSinkNoOnRequestCreate test_SelectSinkNoOnRequestCreate
#endif
TEST_EXPORT test_SelectSinkNoOnRequest _test_SelectSinkNoOnRequestCreate(uint32_t assertCount);
#define test_SelectSinkNoOnRequestCreate(assertCount) _test_SelectSinkNoOnRequestCreate(assertCount)
#define test_SelectSinkNoOnRequestCreate_auto(_id, assertCount) test_SelectSinkNoOnRequest _id = test_SelectSinkNoOnRequestCreate(assertCount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SelectSinkNoOnRequestCreateChild test_SelectSinkNoOnRequestCreateChild
#endif
TEST_EXPORT test_SelectSinkNoOnRequest _test_SelectSinkNoOnRequestCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount);
#define test_SelectSinkNoOnRequestCreateChild(_parent, _id, assertCount) _test_SelectSinkNoOnRequestCreateChild(_parent, _id, assertCount)
#define test_SelectSinkNoOnRequestCreateChild_auto(_parent, _id, assertCount) test_SelectSinkNoOnRequest _id = test_SelectSinkNoOnRequestCreateChild(_parent, #_id, assertCount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SelectSinkNoOnRequestUpdate test_SelectSinkNoOnRequestUpdate
#endif
TEST_EXPORT corto_int16 _test_SelectSinkNoOnRequestUpdate(test_SelectSinkNoOnRequest _this, uint32_t assertCount);
#define test_SelectSinkNoOnRequestUpdate(_this, assertCount) _test_SelectSinkNoOnRequestUpdate(test_SelectSinkNoOnRequest(_this), assertCount)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SelectSinkNoOnRequestDeclare test_SelectSinkNoOnRequestDeclare
#endif
TEST_EXPORT test_SelectSinkNoOnRequest _test_SelectSinkNoOnRequestDeclare(void);
#define test_SelectSinkNoOnRequestDeclare() _test_SelectSinkNoOnRequestDeclare()
#define test_SelectSinkNoOnRequestDeclare_auto(_id) test_SelectSinkNoOnRequest _id = test_SelectSinkNoOnRequestDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SelectSinkNoOnRequestDeclareChild test_SelectSinkNoOnRequestDeclareChild
#endif
TEST_EXPORT test_SelectSinkNoOnRequest _test_SelectSinkNoOnRequestDeclareChild(corto_object _parent, corto_string _id);
#define test_SelectSinkNoOnRequestDeclareChild(_parent, _id) _test_SelectSinkNoOnRequestDeclareChild(_parent, _id)
#define test_SelectSinkNoOnRequestDeclareChild_auto(_parent, _id) test_SelectSinkNoOnRequest _id = test_SelectSinkNoOnRequestDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SelectSinkNoOnRequestDefine test_SelectSinkNoOnRequestDefine
#endif
TEST_EXPORT corto_int16 _test_SelectSinkNoOnRequestDefine(test_SelectSinkNoOnRequest _this, uint32_t assertCount);
#define test_SelectSinkNoOnRequestDefine(_this, assertCount) _test_SelectSinkNoOnRequestDefine(test_SelectSinkNoOnRequest(_this), assertCount)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SelectSinkNoOnRequestAssign test_SelectSinkNoOnRequestAssign
#endif
TEST_EXPORT test_SelectSinkNoOnRequest _test_SelectSinkNoOnRequestAssign(test_SelectSinkNoOnRequest _this, uint32_t assertCount);
#define test_SelectSinkNoOnRequest__optional_NotSet NULL
#define test_SelectSinkNoOnRequest__optional_Set(assertCount) test_SelectSinkNoOnRequestAssign((test_SelectSinkNoOnRequest*)corto_ptr_new(test_SelectSinkNoOnRequest_o)), assertCount)
#define test_SelectSinkNoOnRequest__optional_SetCond(cond, assertCount) cond ? test_SelectSinkNoOnRequestAssign((test_SelectSinkNoOnRequest*)corto_ptr_new(test_SelectSinkNoOnRequest_o), assertCount) : NULL
#define test_SelectSinkNoOnRequestUnset(_this) _this ? corto_ptr_free(_this, test_SelectSinkNoOnRequest_o), 0 : 0; _this = NULL;
#define test_SelectSinkNoOnRequestAssign(_this, assertCount) _test_SelectSinkNoOnRequestAssign(_this, assertCount)
#define test_SelectSinkNoOnRequestSet(_this, assertCount) _this = _this ? _this : (test_SelectSinkNoOnRequest*)corto_ptr_new(test_SelectSinkNoOnRequest_o); _test_SelectSinkNoOnRequestAssign(_this, assertCount)

/* /test/SelectSinkWithType */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SelectSinkWithTypeCreate test_SelectSinkWithTypeCreate
#endif
TEST_EXPORT test_SelectSinkWithType _test_SelectSinkWithTypeCreate(uint32_t assertCount);
#define test_SelectSinkWithTypeCreate(assertCount) _test_SelectSinkWithTypeCreate(assertCount)
#define test_SelectSinkWithTypeCreate_auto(_id, assertCount) test_SelectSinkWithType _id = test_SelectSinkWithTypeCreate(assertCount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SelectSinkWithTypeCreateChild test_SelectSinkWithTypeCreateChild
#endif
TEST_EXPORT test_SelectSinkWithType _test_SelectSinkWithTypeCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount);
#define test_SelectSinkWithTypeCreateChild(_parent, _id, assertCount) _test_SelectSinkWithTypeCreateChild(_parent, _id, assertCount)
#define test_SelectSinkWithTypeCreateChild_auto(_parent, _id, assertCount) test_SelectSinkWithType _id = test_SelectSinkWithTypeCreateChild(_parent, #_id, assertCount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SelectSinkWithTypeUpdate test_SelectSinkWithTypeUpdate
#endif
TEST_EXPORT corto_int16 _test_SelectSinkWithTypeUpdate(test_SelectSinkWithType _this, uint32_t assertCount);
#define test_SelectSinkWithTypeUpdate(_this, assertCount) _test_SelectSinkWithTypeUpdate(test_SelectSinkWithType(_this), assertCount)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SelectSinkWithTypeDeclare test_SelectSinkWithTypeDeclare
#endif
TEST_EXPORT test_SelectSinkWithType _test_SelectSinkWithTypeDeclare(void);
#define test_SelectSinkWithTypeDeclare() _test_SelectSinkWithTypeDeclare()
#define test_SelectSinkWithTypeDeclare_auto(_id) test_SelectSinkWithType _id = test_SelectSinkWithTypeDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SelectSinkWithTypeDeclareChild test_SelectSinkWithTypeDeclareChild
#endif
TEST_EXPORT test_SelectSinkWithType _test_SelectSinkWithTypeDeclareChild(corto_object _parent, corto_string _id);
#define test_SelectSinkWithTypeDeclareChild(_parent, _id) _test_SelectSinkWithTypeDeclareChild(_parent, _id)
#define test_SelectSinkWithTypeDeclareChild_auto(_parent, _id) test_SelectSinkWithType _id = test_SelectSinkWithTypeDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SelectSinkWithTypeDefine test_SelectSinkWithTypeDefine
#endif
TEST_EXPORT corto_int16 _test_SelectSinkWithTypeDefine(test_SelectSinkWithType _this, uint32_t assertCount);
#define test_SelectSinkWithTypeDefine(_this, assertCount) _test_SelectSinkWithTypeDefine(test_SelectSinkWithType(_this), assertCount)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SelectSinkWithTypeAssign test_SelectSinkWithTypeAssign
#endif
TEST_EXPORT test_SelectSinkWithType _test_SelectSinkWithTypeAssign(test_SelectSinkWithType _this, uint32_t assertCount);
#define test_SelectSinkWithType__optional_NotSet NULL
#define test_SelectSinkWithType__optional_Set(assertCount) test_SelectSinkWithTypeAssign((test_SelectSinkWithType*)corto_ptr_new(test_SelectSinkWithType_o)), assertCount)
#define test_SelectSinkWithType__optional_SetCond(cond, assertCount) cond ? test_SelectSinkWithTypeAssign((test_SelectSinkWithType*)corto_ptr_new(test_SelectSinkWithType_o), assertCount) : NULL
#define test_SelectSinkWithTypeUnset(_this) _this ? corto_ptr_free(_this, test_SelectSinkWithType_o), 0 : 0; _this = NULL;
#define test_SelectSinkWithTypeAssign(_this, assertCount) _test_SelectSinkWithTypeAssign(_this, assertCount)
#define test_SelectSinkWithTypeSet(_this, assertCount) _this = _this ? _this : (test_SelectSinkWithType*)corto_ptr_new(test_SelectSinkWithType_o); _test_SelectSinkWithTypeAssign(_this, assertCount)

/* /test/SinkMount */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SinkMountCreate test_SinkMountCreate
#endif
TEST_EXPORT test_SinkMount _test_SinkMountCreate(corto_object mount, corto_string type_1, corto_string value);
#define test_SinkMountCreate(mount, type_1, value) _test_SinkMountCreate(mount, type_1, value)
#define test_SinkMountCreate_auto(_id, mount, type_1, value) test_SinkMount _id = test_SinkMountCreate(mount, type_1, value); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SinkMountCreateChild test_SinkMountCreateChild
#endif
TEST_EXPORT test_SinkMount _test_SinkMountCreateChild(corto_object _parent, corto_string _id, corto_object mount, corto_string type_1, corto_string value);
#define test_SinkMountCreateChild(_parent, _id, mount, type_1, value) _test_SinkMountCreateChild(_parent, _id, mount, type_1, value)
#define test_SinkMountCreateChild_auto(_parent, _id, mount, type_1, value) test_SinkMount _id = test_SinkMountCreateChild(_parent, #_id, mount, type_1, value); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SinkMountUpdate test_SinkMountUpdate
#endif
TEST_EXPORT corto_int16 _test_SinkMountUpdate(test_SinkMount _this, corto_object mount, corto_string type_1, corto_string value);
#define test_SinkMountUpdate(_this, mount, type_1, value) _test_SinkMountUpdate(test_SinkMount(_this), mount, type_1, value)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SinkMountDeclare test_SinkMountDeclare
#endif
TEST_EXPORT test_SinkMount _test_SinkMountDeclare(void);
#define test_SinkMountDeclare() _test_SinkMountDeclare()
#define test_SinkMountDeclare_auto(_id) test_SinkMount _id = test_SinkMountDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SinkMountDeclareChild test_SinkMountDeclareChild
#endif
TEST_EXPORT test_SinkMount _test_SinkMountDeclareChild(corto_object _parent, corto_string _id);
#define test_SinkMountDeclareChild(_parent, _id) _test_SinkMountDeclareChild(_parent, _id)
#define test_SinkMountDeclareChild_auto(_parent, _id) test_SinkMount _id = test_SinkMountDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SinkMountDefine test_SinkMountDefine
#endif
TEST_EXPORT corto_int16 _test_SinkMountDefine(test_SinkMount _this, corto_object mount, corto_string type_1, corto_string value);
#define test_SinkMountDefine(_this, mount, type_1, value) _test_SinkMountDefine(test_SinkMount(_this), mount, type_1, value)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SinkMountAssign test_SinkMountAssign
#endif
TEST_EXPORT test_SinkMount _test_SinkMountAssign(test_SinkMount _this, corto_object mount, corto_string type_1, corto_string value);
#define test_SinkMount__optional_NotSet NULL
#define test_SinkMount__optional_Set(mount, type_1, value) test_SinkMountAssign((test_SinkMount*)corto_ptr_new(test_SinkMount_o)), mount, type_1, value)
#define test_SinkMount__optional_SetCond(cond, mount, type_1, value) cond ? test_SinkMountAssign((test_SinkMount*)corto_ptr_new(test_SinkMount_o), mount, type_1, value) : NULL
#define test_SinkMountUnset(_this) _this ? corto_ptr_free(_this, test_SinkMount_o), 0 : 0; _this = NULL;
#define test_SinkMountAssign(_this, mount, type_1, value) _test_SinkMountAssign(_this, mount, type_1, value)
#define test_SinkMountSet(_this, mount, type_1, value) _this = _this ? _this : (test_SinkMount*)corto_ptr_new(test_SinkMount_o); _test_SinkMountAssign(_this, mount, type_1, value)

/* /test/StringReplicator */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define StringReplicatorCreate test_StringReplicatorCreate
#endif
TEST_EXPORT test_StringReplicator _test_StringReplicatorCreate(corto_object mount);
#define test_StringReplicatorCreate(mount) _test_StringReplicatorCreate(mount)
#define test_StringReplicatorCreate_auto(_id, mount) test_StringReplicator _id = test_StringReplicatorCreate(mount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define StringReplicatorCreateChild test_StringReplicatorCreateChild
#endif
TEST_EXPORT test_StringReplicator _test_StringReplicatorCreateChild(corto_object _parent, corto_string _id, corto_object mount);
#define test_StringReplicatorCreateChild(_parent, _id, mount) _test_StringReplicatorCreateChild(_parent, _id, mount)
#define test_StringReplicatorCreateChild_auto(_parent, _id, mount) test_StringReplicator _id = test_StringReplicatorCreateChild(_parent, #_id, mount); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define StringReplicatorUpdate test_StringReplicatorUpdate
#endif
TEST_EXPORT corto_int16 _test_StringReplicatorUpdate(test_StringReplicator _this, corto_object mount);
#define test_StringReplicatorUpdate(_this, mount) _test_StringReplicatorUpdate(test_StringReplicator(_this), mount)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define StringReplicatorDeclare test_StringReplicatorDeclare
#endif
TEST_EXPORT test_StringReplicator _test_StringReplicatorDeclare(void);
#define test_StringReplicatorDeclare() _test_StringReplicatorDeclare()
#define test_StringReplicatorDeclare_auto(_id) test_StringReplicator _id = test_StringReplicatorDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define StringReplicatorDeclareChild test_StringReplicatorDeclareChild
#endif
TEST_EXPORT test_StringReplicator _test_StringReplicatorDeclareChild(corto_object _parent, corto_string _id);
#define test_StringReplicatorDeclareChild(_parent, _id) _test_StringReplicatorDeclareChild(_parent, _id)
#define test_StringReplicatorDeclareChild_auto(_parent, _id) test_StringReplicator _id = test_StringReplicatorDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define StringReplicatorDefine test_StringReplicatorDefine
#endif
TEST_EXPORT corto_int16 _test_StringReplicatorDefine(test_StringReplicator _this, corto_object mount);
#define test_StringReplicatorDefine(_this, mount) _test_StringReplicatorDefine(test_StringReplicator(_this), mount)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define StringReplicatorAssign test_StringReplicatorAssign
#endif
TEST_EXPORT test_StringReplicator _test_StringReplicatorAssign(test_StringReplicator _this, corto_object mount);
#define test_StringReplicator__optional_NotSet NULL
#define test_StringReplicator__optional_Set(mount) test_StringReplicatorAssign((test_StringReplicator*)corto_ptr_new(test_StringReplicator_o)), mount)
#define test_StringReplicator__optional_SetCond(cond, mount) cond ? test_StringReplicatorAssign((test_StringReplicator*)corto_ptr_new(test_StringReplicator_o), mount) : NULL
#define test_StringReplicatorUnset(_this) _this ? corto_ptr_free(_this, test_StringReplicator_o), 0 : 0; _this = NULL;
#define test_StringReplicatorAssign(_this, mount) _test_StringReplicatorAssign(_this, mount)
#define test_StringReplicatorSet(_this, mount) _this = _this ? _this : (test_StringReplicator*)corto_ptr_new(test_StringReplicator_o); _test_StringReplicatorAssign(_this, mount)

/* /test/SubscribeContentType */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SubscribeContentTypeCreate test_SubscribeContentTypeCreate
#endif
TEST_EXPORT test_SubscribeContentType _test_SubscribeContentTypeCreate(uint32_t assertCount, int32_t eventsReceived);
#define test_SubscribeContentTypeCreate(assertCount, eventsReceived) _test_SubscribeContentTypeCreate(assertCount, eventsReceived)
#define test_SubscribeContentTypeCreate_auto(_id, assertCount, eventsReceived) test_SubscribeContentType _id = test_SubscribeContentTypeCreate(assertCount, eventsReceived); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SubscribeContentTypeCreateChild test_SubscribeContentTypeCreateChild
#endif
TEST_EXPORT test_SubscribeContentType _test_SubscribeContentTypeCreateChild(corto_object _parent, corto_string _id, uint32_t assertCount, int32_t eventsReceived);
#define test_SubscribeContentTypeCreateChild(_parent, _id, assertCount, eventsReceived) _test_SubscribeContentTypeCreateChild(_parent, _id, assertCount, eventsReceived)
#define test_SubscribeContentTypeCreateChild_auto(_parent, _id, assertCount, eventsReceived) test_SubscribeContentType _id = test_SubscribeContentTypeCreateChild(_parent, #_id, assertCount, eventsReceived); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SubscribeContentTypeUpdate test_SubscribeContentTypeUpdate
#endif
TEST_EXPORT corto_int16 _test_SubscribeContentTypeUpdate(test_SubscribeContentType _this, uint32_t assertCount, int32_t eventsReceived);
#define test_SubscribeContentTypeUpdate(_this, assertCount, eventsReceived) _test_SubscribeContentTypeUpdate(test_SubscribeContentType(_this), assertCount, eventsReceived)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SubscribeContentTypeDeclare test_SubscribeContentTypeDeclare
#endif
TEST_EXPORT test_SubscribeContentType _test_SubscribeContentTypeDeclare(void);
#define test_SubscribeContentTypeDeclare() _test_SubscribeContentTypeDeclare()
#define test_SubscribeContentTypeDeclare_auto(_id) test_SubscribeContentType _id = test_SubscribeContentTypeDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SubscribeContentTypeDeclareChild test_SubscribeContentTypeDeclareChild
#endif
TEST_EXPORT test_SubscribeContentType _test_SubscribeContentTypeDeclareChild(corto_object _parent, corto_string _id);
#define test_SubscribeContentTypeDeclareChild(_parent, _id) _test_SubscribeContentTypeDeclareChild(_parent, _id)
#define test_SubscribeContentTypeDeclareChild_auto(_parent, _id) test_SubscribeContentType _id = test_SubscribeContentTypeDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SubscribeContentTypeDefine test_SubscribeContentTypeDefine
#endif
TEST_EXPORT corto_int16 _test_SubscribeContentTypeDefine(test_SubscribeContentType _this, uint32_t assertCount, int32_t eventsReceived);
#define test_SubscribeContentTypeDefine(_this, assertCount, eventsReceived) _test_SubscribeContentTypeDefine(test_SubscribeContentType(_this), assertCount, eventsReceived)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define SubscribeContentTypeAssign test_SubscribeContentTypeAssign
#endif
TEST_EXPORT test_SubscribeContentType _test_SubscribeContentTypeAssign(test_SubscribeContentType _this, uint32_t assertCount, int32_t eventsReceived);
#define test_SubscribeContentType__optional_NotSet NULL
#define test_SubscribeContentType__optional_Set(assertCount, eventsReceived) test_SubscribeContentTypeAssign((test_SubscribeContentType*)corto_ptr_new(test_SubscribeContentType_o)), assertCount, eventsReceived)
#define test_SubscribeContentType__optional_SetCond(cond, assertCount, eventsReceived) cond ? test_SubscribeContentTypeAssign((test_SubscribeContentType*)corto_ptr_new(test_SubscribeContentType_o), assertCount, eventsReceived) : NULL
#define test_SubscribeContentTypeUnset(_this) _this ? corto_ptr_free(_this, test_SubscribeContentType_o), 0 : 0; _this = NULL;
#define test_SubscribeContentTypeAssign(_this, assertCount, eventsReceived) _test_SubscribeContentTypeAssign(_this, assertCount, eventsReceived)
#define test_SubscribeContentTypeSet(_this, assertCount, eventsReceived) _this = _this ? _this : (test_SubscribeContentType*)corto_ptr_new(test_SubscribeContentType_o); _test_SubscribeContentTypeAssign(_this, assertCount, eventsReceived)

/* /test/VirtualMount */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define VirtualMountCreate test_VirtualMountCreate
#endif
TEST_EXPORT test_VirtualMount _test_VirtualMountCreate(corto_string mount_1);
#define test_VirtualMountCreate(mount_1) _test_VirtualMountCreate(mount_1)
#define test_VirtualMountCreate_auto(_id, mount_1) test_VirtualMount _id = test_VirtualMountCreate(mount_1); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define VirtualMountCreateChild test_VirtualMountCreateChild
#endif
TEST_EXPORT test_VirtualMount _test_VirtualMountCreateChild(corto_object _parent, corto_string _id, corto_string mount_1);
#define test_VirtualMountCreateChild(_parent, _id, mount_1) _test_VirtualMountCreateChild(_parent, _id, mount_1)
#define test_VirtualMountCreateChild_auto(_parent, _id, mount_1) test_VirtualMount _id = test_VirtualMountCreateChild(_parent, #_id, mount_1); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define VirtualMountUpdate test_VirtualMountUpdate
#endif
TEST_EXPORT corto_int16 _test_VirtualMountUpdate(test_VirtualMount _this, corto_string mount_1);
#define test_VirtualMountUpdate(_this, mount_1) _test_VirtualMountUpdate(test_VirtualMount(_this), mount_1)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define VirtualMountDeclare test_VirtualMountDeclare
#endif
TEST_EXPORT test_VirtualMount _test_VirtualMountDeclare(void);
#define test_VirtualMountDeclare() _test_VirtualMountDeclare()
#define test_VirtualMountDeclare_auto(_id) test_VirtualMount _id = test_VirtualMountDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define VirtualMountDeclareChild test_VirtualMountDeclareChild
#endif
TEST_EXPORT test_VirtualMount _test_VirtualMountDeclareChild(corto_object _parent, corto_string _id);
#define test_VirtualMountDeclareChild(_parent, _id) _test_VirtualMountDeclareChild(_parent, _id)
#define test_VirtualMountDeclareChild_auto(_parent, _id) test_VirtualMount _id = test_VirtualMountDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define VirtualMountDefine test_VirtualMountDefine
#endif
TEST_EXPORT corto_int16 _test_VirtualMountDefine(test_VirtualMount _this, corto_string mount_1);
#define test_VirtualMountDefine(_this, mount_1) _test_VirtualMountDefine(test_VirtualMount(_this), mount_1)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define VirtualMountAssign test_VirtualMountAssign
#endif
TEST_EXPORT test_VirtualMount _test_VirtualMountAssign(test_VirtualMount _this, corto_string mount_1);
#define test_VirtualMount__optional_NotSet NULL
#define test_VirtualMount__optional_Set(mount_1) test_VirtualMountAssign((test_VirtualMount*)corto_ptr_new(test_VirtualMount_o)), mount_1)
#define test_VirtualMount__optional_SetCond(cond, mount_1) cond ? test_VirtualMountAssign((test_VirtualMount*)corto_ptr_new(test_VirtualMount_o), mount_1) : NULL
#define test_VirtualMountUnset(_this) _this ? corto_ptr_free(_this, test_VirtualMount_o), 0 : 0; _this = NULL;
#define test_VirtualMountAssign(_this, mount_1) _test_VirtualMountAssign(_this, mount_1)
#define test_VirtualMountSet(_this, mount_1) _this = _this ? _this : (test_VirtualMount*)corto_ptr_new(test_VirtualMount_o); _test_VirtualMountAssign(_this, mount_1)

/* /test/VirtualSinkMount */

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define VirtualSinkMountCreate test_VirtualSinkMountCreate
#endif
TEST_EXPORT test_VirtualSinkMount _test_VirtualSinkMountCreate(corto_string from);
#define test_VirtualSinkMountCreate(from) _test_VirtualSinkMountCreate(from)
#define test_VirtualSinkMountCreate_auto(_id, from) test_VirtualSinkMount _id = test_VirtualSinkMountCreate(from); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define VirtualSinkMountCreateChild test_VirtualSinkMountCreateChild
#endif
TEST_EXPORT test_VirtualSinkMount _test_VirtualSinkMountCreateChild(corto_object _parent, corto_string _id, corto_string from);
#define test_VirtualSinkMountCreateChild(_parent, _id, from) _test_VirtualSinkMountCreateChild(_parent, _id, from)
#define test_VirtualSinkMountCreateChild_auto(_parent, _id, from) test_VirtualSinkMount _id = test_VirtualSinkMountCreateChild(_parent, #_id, from); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define VirtualSinkMountUpdate test_VirtualSinkMountUpdate
#endif
TEST_EXPORT corto_int16 _test_VirtualSinkMountUpdate(test_VirtualSinkMount _this, corto_string from);
#define test_VirtualSinkMountUpdate(_this, from) _test_VirtualSinkMountUpdate(test_VirtualSinkMount(_this), from)


#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define VirtualSinkMountDeclare test_VirtualSinkMountDeclare
#endif
TEST_EXPORT test_VirtualSinkMount _test_VirtualSinkMountDeclare(void);
#define test_VirtualSinkMountDeclare() _test_VirtualSinkMountDeclare()
#define test_VirtualSinkMountDeclare_auto(_id) test_VirtualSinkMount _id = test_VirtualSinkMountDeclare(); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define VirtualSinkMountDeclareChild test_VirtualSinkMountDeclareChild
#endif
TEST_EXPORT test_VirtualSinkMount _test_VirtualSinkMountDeclareChild(corto_object _parent, corto_string _id);
#define test_VirtualSinkMountDeclareChild(_parent, _id) _test_VirtualSinkMountDeclareChild(_parent, _id)
#define test_VirtualSinkMountDeclareChild_auto(_parent, _id) test_VirtualSinkMount _id = test_VirtualSinkMountDeclareChild(_parent, #_id); (void)_id

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define VirtualSinkMountDefine test_VirtualSinkMountDefine
#endif
TEST_EXPORT corto_int16 _test_VirtualSinkMountDefine(test_VirtualSinkMount _this, corto_string from);
#define test_VirtualSinkMountDefine(_this, from) _test_VirtualSinkMountDefine(test_VirtualSinkMount(_this), from)

#if defined(BUILDING_TEST) && !defined(__cplusplus)
#define VirtualSinkMountAssign test_VirtualSinkMountAssign
#endif
TEST_EXPORT test_VirtualSinkMount _test_VirtualSinkMountAssign(test_VirtualSinkMount _this, corto_string from);
#define test_VirtualSinkMount__optional_NotSet NULL
#define test_VirtualSinkMount__optional_Set(from) test_VirtualSinkMountAssign((test_VirtualSinkMount*)corto_ptr_new(test_VirtualSinkMount_o)), from)
#define test_VirtualSinkMount__optional_SetCond(cond, from) cond ? test_VirtualSinkMountAssign((test_VirtualSinkMount*)corto_ptr_new(test_VirtualSinkMount_o), from) : NULL
#define test_VirtualSinkMountUnset(_this) _this ? corto_ptr_free(_this, test_VirtualSinkMount_o), 0 : 0; _this = NULL;
#define test_VirtualSinkMountAssign(_this, from) _test_VirtualSinkMountAssign(_this, from)
#define test_VirtualSinkMountSet(_this, from) _this = _this ? _this : (test_VirtualSinkMount*)corto_ptr_new(test_VirtualSinkMount_o); _test_VirtualSinkMountAssign(_this, from)


/* list{/corto/vstore/query,0} */
TEST_EXPORT corto_query* corto_queryListInsertAlloc(corto_queryList list);
TEST_EXPORT corto_query* corto_queryListInsert(corto_queryList list, corto_query* element);
TEST_EXPORT corto_query* corto_queryListAppendAlloc(corto_queryList list);
TEST_EXPORT corto_query* corto_queryListAppend(corto_queryList list, corto_query* element);
TEST_EXPORT corto_query* corto_queryListTakeFirst(corto_queryList list);
TEST_EXPORT corto_query* corto_queryListLast(corto_queryList list);
TEST_EXPORT corto_query* corto_queryListGet(corto_queryList list, corto_uint32 index);
TEST_EXPORT corto_uint32 corto_queryListSize(corto_queryList list);
TEST_EXPORT void corto_queryListClear(corto_queryList list);

/* list{string,0} */
TEST_EXPORT void corto_stringListInsert(corto_stringList list, corto_string element);
TEST_EXPORT void corto_stringListAppend(corto_stringList list, corto_string element);
TEST_EXPORT corto_string corto_stringListTakeFirst(corto_stringList list);
TEST_EXPORT corto_string corto_stringListLast(corto_stringList list);
TEST_EXPORT corto_string corto_stringListGet(corto_stringList list, corto_uint32 index);
TEST_EXPORT corto_uint32 corto_stringListSize(corto_stringList list);
TEST_EXPORT void corto_stringListClear(corto_stringList list);

/* list{/test/HistoryMount/data,0} */
TEST_EXPORT test_HistoryMount_data* test_HistoryMount_dataListInsertAlloc(test_HistoryMount_dataList list);
TEST_EXPORT test_HistoryMount_data* test_HistoryMount_dataListInsert(test_HistoryMount_dataList list, test_HistoryMount_data* element);
TEST_EXPORT test_HistoryMount_data* test_HistoryMount_dataListAppendAlloc(test_HistoryMount_dataList list);
TEST_EXPORT test_HistoryMount_data* test_HistoryMount_dataListAppend(test_HistoryMount_dataList list, test_HistoryMount_data* element);
TEST_EXPORT test_HistoryMount_data* test_HistoryMount_dataListTakeFirst(test_HistoryMount_dataList list);
TEST_EXPORT test_HistoryMount_data* test_HistoryMount_dataListLast(test_HistoryMount_dataList list);
TEST_EXPORT test_HistoryMount_data* test_HistoryMount_dataListGet(test_HistoryMount_dataList list, corto_uint32 index);
TEST_EXPORT corto_uint32 test_HistoryMount_dataListSize(test_HistoryMount_dataList list);
TEST_EXPORT void test_HistoryMount_dataListClear(test_HistoryMount_dataList list);

/* list{/corto/vstore/result,0} */
TEST_EXPORT corto_result* corto_resultListInsertAlloc(corto_resultList list);
TEST_EXPORT corto_result* corto_resultListInsert(corto_resultList list, corto_result* element);
TEST_EXPORT corto_result* corto_resultListAppendAlloc(corto_resultList list);
TEST_EXPORT corto_result* corto_resultListAppend(corto_resultList list, corto_result* element);
TEST_EXPORT corto_result* corto_resultListTakeFirst(corto_resultList list);
TEST_EXPORT corto_result* corto_resultListLast(corto_resultList list);
TEST_EXPORT corto_result* corto_resultListGet(corto_resultList list, corto_uint32 index);
TEST_EXPORT corto_uint32 corto_resultListSize(corto_resultList list);
TEST_EXPORT void corto_resultListClear(corto_resultList list);

#ifdef __cplusplus
}
#endif
#endif

