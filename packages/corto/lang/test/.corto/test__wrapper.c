/* test__wrapper.c
 *
 * This file contains wrapper functions for /test.
 */

#include "test.h"
#include "test__meta.h"

void __test_functionToResolve(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    _test_functionToResolve(
        *(corto_int32*)args,
        *(corto_int32*)((intptr_t)args + sizeof(corto_int32)));
}

void __test_ol_any__test_Color(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    _test_ol_any__test_Color(
        *(test_Color*)args);
}

void __test_ol_any_bool(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    _test_ol_any_bool(
        *(corto_bool*)args);
}

void __test_ol_any_char(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    _test_ol_any_char(
        *(corto_char*)args);
}

void __test_ol_any_float32(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    _test_ol_any_float32(
        *(corto_float32*)args);
}

void __test_ol_any_int32(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    _test_ol_any_int32(
        *(corto_int32*)args);
}

void __test_ol_any_object(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    _test_ol_any_object(
        *(corto_object*)args);
}

void __test_ol_any_string(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    _test_ol_any_string(
        *(corto_string*)args);
}

void __test_ol_bool(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    _test_ol_bool(
        *(corto_bool*)args);
}

void __test_ol_inherit__test_Animal(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    _test_ol_inherit__test_Animal(
        test_Animal(*(test_Animal*)args));
}

void __test_ol_inherit__test_Dog(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    _test_ol_inherit__test_Dog(
        test_Dog(*(test_Dog*)args));
}

void __test_ol_int(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    _test_ol_int(
        *(corto_int32*)args);
}

void __test_ol_null_bool(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    _test_ol_null_bool(
        *(corto_bool*)args);
}

void __test_ol_null_object(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    _test_ol_null_object(
        *(corto_object*)args);
}

void __test_ol_null_string(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    _test_ol_null_string(
        *(corto_string*)args);
}

void __test_ol_num_float64(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    _test_ol_num_float64(
        *(corto_float64*)args);
}

void __test_ol_num_int32(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    _test_ol_num_int32(
        *(corto_int32*)args);
}

void __test_ol_object(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    _test_ol_object(
        *(corto_object*)args);
}

void __test_ol_string(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    _test_ol_string(
        *(corto_string*)args);
}

void __test_ol_uint(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    _test_ol_uint(
        *(corto_int32*)args);
}

void __test_ol_wildcard_float32_string(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    _test_ol_wildcard_float32_string(
        *(corto_float32*)args,
        *(corto_string*)((intptr_t)args + sizeof(corto_float32)));
}

void __test_ol_wildcard_int32_string(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    _test_ol_wildcard_int32_string(
        *(corto_int32*)args,
        *(corto_string*)((intptr_t)args + sizeof(corto_int32)));
}

void __test_Args_tc_matchAddNoProject(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Args_tc_matchAddNoProject(
        test_Args(*(void**)args));
}

void __test_Args_tc_matchAll(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Args_tc_matchAll(
        test_Args(*(void**)args));
}

void __test_Args_tc_matchCreate(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Args_tc_matchCreate(
        test_Args(*(void**)args));
}

void __test_Args_tc_matchCreateApp(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Args_tc_matchCreateApp(
        test_Args(*(void**)args));
}

void __test_Args_tc_matchCreateMultiple(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Args_tc_matchCreateMultiple(
        test_Args(*(void**)args));
}

void __test_Args_tc_matchCreatePackage(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Args_tc_matchCreatePackage(
        test_Args(*(void**)args));
}

void __test_Args_tc_matchCreatePackageAndApp(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Args_tc_matchCreatePackageAndApp(
        test_Args(*(void**)args));
}

void __test_Args_tc_matchCreatePackageAndAppEscaped(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Args_tc_matchCreatePackageAndAppEscaped(
        test_Args(*(void**)args));
}

void __test_Args_tc_matchCreatePackageOptions(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Args_tc_matchCreatePackageOptions(
        test_Args(*(void**)args));
}

void __test_Args_tc_matchDuplicate(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Args_tc_matchDuplicate(
        test_Args(*(void**)args));
}

void __test_Args_tc_matchDuplicateArg(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Args_tc_matchDuplicateArg(
        test_Args(*(void**)args));
}

void __test_Args_tc_matchErr(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Args_tc_matchErr(
        test_Args(*(void**)args));
}

void __test_Args_tc_matchFixed(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Args_tc_matchFixed(
        test_Args(*(void**)args));
}

void __test_Args_tc_matchMultiple(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Args_tc_matchMultiple(
        test_Args(*(void**)args));
}

void __test_Args_tc_matchMultipleArg(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Args_tc_matchMultipleArg(
        test_Args(*(void**)args));
}

void __test_Args_tc_matchNone(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Args_tc_matchNone(
        test_Args(*(void**)args));
}

void __test_Args_tc_matchOptional(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Args_tc_matchOptional(
        test_Args(*(void**)args));
}

void __test_Args_tc_matchOptionalOneArg(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Args_tc_matchOptionalOneArg(
        test_Args(*(void**)args));
}

void __test_Args_tc_matchOptionalWithOtherArgs(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Args_tc_matchOptionalWithOtherArgs(
        test_Args(*(void**)args));
}

void __test_Args_tc_matchPattern(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Args_tc_matchPattern(
        test_Args(*(void**)args));
}

void __test_Args_tc_matchPublish(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Args_tc_matchPublish(
        test_Args(*(void**)args));
}

void __test_Args_tc_matchPublishNoProject(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Args_tc_matchPublishNoProject(
        test_Args(*(void**)args));
}

void __test_Args_tc_matchShell(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Args_tc_matchShell(
        test_Args(*(void**)args));
}

void __test_Args_tc_matchSingle(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Args_tc_matchSingle(
        test_Args(*(void**)args));
}

void __test_Args_tc_matchSingleArg(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Args_tc_matchSingleArg(
        test_Args(*(void**)args));
}

void __test_Bar_init(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_int16*)result = _test_Bar_init(
        test_Bar(*(void**)args));
}

void __test_Env_tc_envparseFormatAndReplace(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Env_tc_envparseFormatAndReplace(
        test_Env(*(void**)args));
}

void __test_Env_tc_envparseReplaceMultiple(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Env_tc_envparseReplaceMultiple(
        test_Env(*(void**)args));
}

void __test_Env_tc_envparseReplaceWithSameVariable(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Env_tc_envparseReplaceWithSameVariable(
        test_Env(*(void**)args));
}

void __test_Env_tc_envparseSimpleFormat(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Env_tc_envparseSimpleFormat(
        test_Env(*(void**)args));
}

void __test_Env_tc_envparseSimpleReplace(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Env_tc_envparseSimpleReplace(
        test_Env(*(void**)args));
}

void __test_Env_tc_envparseVariableNotFound(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Env_tc_envparseVariableNotFound(
        test_Env(*(void**)args));
}

void __test_Env_tc_setenvFormatAndReplace(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Env_tc_setenvFormatAndReplace(
        test_Env(*(void**)args));
}

void __test_Env_tc_setenvNull(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Env_tc_setenvNull(
        test_Env(*(void**)args));
}

void __test_Env_tc_setenvReplaceMultiple(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Env_tc_setenvReplaceMultiple(
        test_Env(*(void**)args));
}

void __test_Env_tc_setenvReplaceWithSameVariable(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Env_tc_setenvReplaceWithSameVariable(
        test_Env(*(void**)args));
}

void __test_Env_tc_setenvSimple(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Env_tc_setenvSimple(
        test_Env(*(void**)args));
}

void __test_Env_tc_setenvSimpleFormat(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Env_tc_setenvSimpleFormat(
        test_Env(*(void**)args));
}

void __test_Env_tc_setenvSimpleReplace(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Env_tc_setenvSimpleReplace(
        test_Env(*(void**)args));
}

void __test_Env_tc_setenvVariableNotFound(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Env_tc_setenvVariableNotFound(
        test_Env(*(void**)args));
}

void __test_Event_setup(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Event_setup(
        test_Event(*(void**)args));
}

void __test_Event_tc_onDeclare(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Event_tc_onDeclare(
        test_Event(*(void**)args));
}

void __test_Event_tc_onDeclareScope(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Event_tc_onDeclareScope(
        test_Event(*(void**)args));
}

void __test_Event_tc_onDeclareSelf(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Event_tc_onDeclareSelf(
        test_Event(*(void**)args));
}

void __test_Event_tc_onDeclareTree(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Event_tc_onDeclareTree(
        test_Event(*(void**)args));
}

void __test_Event_tc_onDefine(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Event_tc_onDefine(
        test_Event(*(void**)args));
}

void __test_Event_tc_onDefineScope(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Event_tc_onDefineScope(
        test_Event(*(void**)args));
}

void __test_Event_tc_onDefineSelf(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Event_tc_onDefineSelf(
        test_Event(*(void**)args));
}

void __test_Event_tc_onDefineTree(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Event_tc_onDefineTree(
        test_Event(*(void**)args));
}

void __test_Event_tc_onDelete(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Event_tc_onDelete(
        test_Event(*(void**)args));
}

void __test_Event_tc_onDeleteScope(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Event_tc_onDeleteScope(
        test_Event(*(void**)args));
}

void __test_Event_tc_onDeleteSelf(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Event_tc_onDeleteSelf(
        test_Event(*(void**)args));
}

void __test_Event_tc_onDeleteTree(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Event_tc_onDeleteTree(
        test_Event(*(void**)args));
}

void __test_Event_tc_onUpdate(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Event_tc_onUpdate(
        test_Event(*(void**)args));
}

void __test_Event_tc_onUpdateScope(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Event_tc_onUpdateScope(
        test_Event(*(void**)args));
}

void __test_Event_tc_onUpdateSelf(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Event_tc_onUpdateSelf(
        test_Event(*(void**)args));
}

void __test_Event_tc_onUpdateTree(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Event_tc_onUpdateTree(
        test_Event(*(void**)args));
}

void __test_Event_tc_updateUndefined(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Event_tc_updateUndefined(
        test_Event(*(void**)args));
}

void __test_Event_tc_updateVoidErr(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Event_tc_updateVoidErr(
        test_Event(*(void**)args));
}

void __test_Event_teardown(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Event_teardown(
        test_Event(*(void**)args));
}

void __test_EventTest_construct(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_int16*)result = _test_EventTest_construct(
        test_EventTest(*(void**)args));
}

void __test_EventTest_onDeclare(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    _test_EventTest_onDeclare(
        test_EventTest(*(void**)args),
        *(void**)((intptr_t)args + sizeof(void*)));
}

void __test_EventTest_onDeclareScope(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    _test_EventTest_onDeclareScope(
        test_EventTest(*(void**)args),
        *(void**)((intptr_t)args + sizeof(void*)));
}

void __test_EventTest_onDeclareSelf(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    _test_EventTest_onDeclareSelf(
        test_EventTest(*(void**)args),
        *(void**)((intptr_t)args + sizeof(void*)));
}

void __test_EventTest_onDeclareTree(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    _test_EventTest_onDeclareTree(
        test_EventTest(*(void**)args),
        *(void**)((intptr_t)args + sizeof(void*)));
}

void __test_EventTest_onDefine(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    _test_EventTest_onDefine(
        test_EventTest(*(void**)args),
        *(void**)((intptr_t)args + sizeof(void*)));
}

void __test_EventTest_onDefineScope(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    _test_EventTest_onDefineScope(
        test_EventTest(*(void**)args),
        *(void**)((intptr_t)args + sizeof(void*)));
}

void __test_EventTest_onDefineSelf(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    _test_EventTest_onDefineSelf(
        test_EventTest(*(void**)args),
        *(void**)((intptr_t)args + sizeof(void*)));
}

void __test_EventTest_onDefineTree(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    _test_EventTest_onDefineTree(
        test_EventTest(*(void**)args),
        *(void**)((intptr_t)args + sizeof(void*)));
}

void __test_EventTest_onDelete(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    _test_EventTest_onDelete(
        test_EventTest(*(void**)args),
        *(void**)((intptr_t)args + sizeof(void*)));
}

void __test_EventTest_onDeleteScope(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    _test_EventTest_onDeleteScope(
        test_EventTest(*(void**)args),
        *(void**)((intptr_t)args + sizeof(void*)));
}

void __test_EventTest_onDeleteSelf(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    _test_EventTest_onDeleteSelf(
        test_EventTest(*(void**)args),
        *(void**)((intptr_t)args + sizeof(void*)));
}

void __test_EventTest_onDeleteTree(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    _test_EventTest_onDeleteTree(
        test_EventTest(*(void**)args),
        *(void**)((intptr_t)args + sizeof(void*)));
}

void __test_EventTest_onUpdate(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    _test_EventTest_onUpdate(
        test_EventTest(*(void**)args),
        *(void**)((intptr_t)args + sizeof(void*)));
}

void __test_EventTest_onUpdateScope(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    _test_EventTest_onUpdateScope(
        test_EventTest(*(void**)args),
        *(void**)((intptr_t)args + sizeof(void*)));
}

void __test_EventTest_onUpdateSelf(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    _test_EventTest_onUpdateSelf(
        test_EventTest(*(void**)args),
        *(void**)((intptr_t)args + sizeof(void*)));
}

void __test_EventTest_onUpdateTree(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    _test_EventTest_onUpdateTree(
        test_EventTest(*(void**)args),
        *(void**)((intptr_t)args + sizeof(void*)));
}

void __test_Foo_construct(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_int16*)result = _test_Foo_construct(
        test_Foo(*(void**)args));
}

void __test_Foo_destruct(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Foo_destruct(
        test_Foo(*(void**)args));
}

void __test_Foo_init(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    *(corto_int16*)result = _test_Foo_init(
        test_Foo(*(void**)args));
}

void __test_Fullname_tc_null(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Fullname_tc_null(
        test_Fullname(*(void**)args));
}

void __test_Fullname_tc_nullBuffer(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Fullname_tc_nullBuffer(
        test_Fullname(*(void**)args));
}

void __test_Fullname_tc_onelevel(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Fullname_tc_onelevel(
        test_Fullname(*(void**)args));
}

void __test_Fullname_tc_root(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Fullname_tc_root(
        test_Fullname(*(void**)args));
}

void __test_Fullname_tc_twolevels(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Fullname_tc_twolevels(
        test_Fullname(*(void**)args));
}

void __test_MethodResolver_tc_inheritOverload(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_MethodResolver_tc_inheritOverload(
        test_MethodResolver(*(void**)args));
}

void __test_MethodResolver_tc_inheritOverloadBaseClass(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_MethodResolver_tc_inheritOverloadBaseClass(
        test_MethodResolver(*(void**)args));
}

void __test_MethodResolver_tc_inheritOverloadBaseInt(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_MethodResolver_tc_inheritOverloadBaseInt(
        test_MethodResolver(*(void**)args));
}

void __test_MethodResolver_tc_inheritOverloadBaseString(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_MethodResolver_tc_inheritOverloadBaseString(
        test_MethodResolver(*(void**)args));
}

void __test_MethodResolver_tc_inheritOverloadBaseTwoArgs(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_MethodResolver_tc_inheritOverloadBaseTwoArgs(
        test_MethodResolver(*(void**)args));
}

void __test_MethodResolver_tc_inheritOverloadClass(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_MethodResolver_tc_inheritOverloadClass(
        test_MethodResolver(*(void**)args));
}

void __test_MethodResolver_tc_inheritOverloadNoArgs(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_MethodResolver_tc_inheritOverloadNoArgs(
        test_MethodResolver(*(void**)args));
}

void __test_MethodResolver_tc_inheritSimple(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_MethodResolver_tc_inheritSimple(
        test_MethodResolver(*(void**)args));
}

void __test_MethodResolver_tc_inheritSimpleNoArgs(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_MethodResolver_tc_inheritSimpleNoArgs(
        test_MethodResolver(*(void**)args));
}

void __test_MethodResolver_tc_inheritVirtualOverload(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_MethodResolver_tc_inheritVirtualOverload(
        test_MethodResolver(*(void**)args));
}

void __test_MethodResolver_tc_inheritVirtualOverloadNoArgs(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_MethodResolver_tc_inheritVirtualOverloadNoArgs(
        test_MethodResolver(*(void**)args));
}

void __test_MethodResolver_tc_nonexisting(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_MethodResolver_tc_nonexisting(
        test_MethodResolver(*(void**)args));
}

void __test_MethodResolver_tc_onearg(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_MethodResolver_tc_onearg(
        test_MethodResolver(*(void**)args));
}

void __test_MethodResolver_tc_oneargErr(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_MethodResolver_tc_oneargErr(
        test_MethodResolver(*(void**)args));
}

void __test_MethodResolver_tc_oneargErrType(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_MethodResolver_tc_oneargErrType(
        test_MethodResolver(*(void**)args));
}

void __test_MethodResolver_tc_oneargNoArgs(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_MethodResolver_tc_oneargNoArgs(
        test_MethodResolver(*(void**)args));
}

void __test_MethodResolver_tc_overloadAmbiguous(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_MethodResolver_tc_overloadAmbiguous(
        test_MethodResolver(*(void**)args));
}

void __test_MethodResolver_tc_overloadClass(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_MethodResolver_tc_overloadClass(
        test_MethodResolver(*(void**)args));
}

void __test_MethodResolver_tc_overloadInt(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_MethodResolver_tc_overloadInt(
        test_MethodResolver(*(void**)args));
}

void __test_MethodResolver_tc_overloadString(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_MethodResolver_tc_overloadString(
        test_MethodResolver(*(void**)args));
}

void __test_MethodResolver_tc_overloadTwoArgs(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_MethodResolver_tc_overloadTwoArgs(
        test_MethodResolver(*(void**)args));
}

void __test_MethodResolver_tc_redeclare(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_MethodResolver_tc_redeclare(
        test_MethodResolver(*(void**)args));
}

void __test_MethodResolver_tc_simple(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_MethodResolver_tc_simple(
        test_MethodResolver(*(void**)args));
}

void __test_MethodResolver_tc_simpleErr(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_MethodResolver_tc_simpleErr(
        test_MethodResolver(*(void**)args));
}

void __test_MethodResolver_tc_simpleErrType(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_MethodResolver_tc_simpleErrType(
        test_MethodResolver(*(void**)args));
}

void __test_MethodResolver_tc_simpleNoArgs(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_MethodResolver_tc_simpleNoArgs(
        test_MethodResolver(*(void**)args));
}

void __test_MethodResolver_tc_twoargs(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_MethodResolver_tc_twoargs(
        test_MethodResolver(*(void**)args));
}

void __test_MethodResolver_tc_twoargsNoArgs(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_MethodResolver_tc_twoargsNoArgs(
        test_MethodResolver(*(void**)args));
}

void __test_MethodResolver_tc_twoargsSpaces(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_MethodResolver_tc_twoargsSpaces(
        test_MethodResolver(*(void**)args));
}

void __test_MethodResolver_tc_virtualOverload(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_MethodResolver_tc_virtualOverload(
        test_MethodResolver(*(void**)args));
}

void __test_MethodResolver_tc_virtualOverloadArg(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_MethodResolver_tc_virtualOverloadArg(
        test_MethodResolver(*(void**)args));
}

void __test_MethodResolver_tc_virtualOverloadNoArgs(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_MethodResolver_tc_virtualOverloadNoArgs(
        test_MethodResolver(*(void**)args));
}

void __test_MethodResolver_tc_virtualSimple(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_MethodResolver_tc_virtualSimple(
        test_MethodResolver(*(void**)args));
}

void __test_MethodResolver_tc_virtualSimpleNoArgs(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_MethodResolver_tc_virtualSimpleNoArgs(
        test_MethodResolver(*(void**)args));
}

void __test_MethodTester_onearg(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    _test_MethodTester_onearg(
        test_MethodTester(*(void**)args),
        *(corto_int32*)((intptr_t)args + sizeof(void*)));
}

void __test_MethodTester_overload__test_MethodTester(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    _test_MethodTester_overload__test_MethodTester(
        test_MethodTester(*(void**)args),
        test_MethodTester(*(test_MethodTester*)((intptr_t)args + sizeof(void*))));
}

void __test_MethodTester_overload_int32(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    _test_MethodTester_overload_int32(
        test_MethodTester(*(void**)args),
        *(corto_int32*)((intptr_t)args + sizeof(void*)));
}

void __test_MethodTester_overload_int32_int32(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    _test_MethodTester_overload_int32_int32(
        test_MethodTester(*(void**)args),
        *(corto_int32*)((intptr_t)args + sizeof(void*)),
        *(corto_int32*)((intptr_t)args + sizeof(void*) + sizeof(corto_int32)));
}

void __test_MethodTester_overload_string(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    _test_MethodTester_overload_string(
        test_MethodTester(*(void**)args),
        *(corto_string*)((intptr_t)args + sizeof(void*)));
}

void __test_MethodTester_simple(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_MethodTester_simple(
        test_MethodTester(*(void**)args));
}

void __test_MethodTester_twoargs(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    _test_MethodTester_twoargs(
        test_MethodTester(*(void**)args),
        *(corto_int32*)((intptr_t)args + sizeof(void*)),
        *(corto_int32*)((intptr_t)args + sizeof(void*) + sizeof(corto_int32)));
}

/* virtual /test/MethodTester/virtualOverload() */
void _test_MethodTester_virtualOverload_(test_MethodTester this) {
    static corto_uint32 _methodId;
    corto_method _method;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "virtualOverload()");
    }
    corto_assert(_methodId, "virtual method 'virtualOverload()' not found in abstract '%s'", corto_nameof(_abstract));

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::virtualOverload()@%d'", corto_nameof(this), _methodId);

    corto_call(corto_function(_method), NULL, this);
}

void __test_MethodTester_virtualOverload__v(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_MethodTester_virtualOverload__v(
        test_MethodTester(*(void**)args));
}

void __test_MethodTester_virtualOverload_int32(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    _test_MethodTester_virtualOverload_int32(
        test_MethodTester(*(void**)args),
        *(corto_int32*)((intptr_t)args + sizeof(void*)));
}

/* virtual /test/MethodTester/virtualSimple() */
void _test_MethodTester_virtualSimple(test_MethodTester this) {
    static corto_uint32 _methodId;
    corto_method _method;
    corto_interface _abstract;

    _abstract = corto_interface(corto_typeof(this));

    /* Determine methodId once, then cache it for subsequent calls. */
    if (!_methodId) {
        _methodId = corto_interface_resolveMethodId(_abstract, "virtualSimple()");
    }
    corto_assert(_methodId, "virtual method 'virtualSimple()' not found in abstract '%s'", corto_nameof(_abstract));

    /* Lookup method-object. */
    _method = corto_interface_resolveMethodById(_abstract, _methodId);
    corto_assert(_method != NULL, "unresolved method '%s::virtualSimple()@%d'", corto_nameof(this), _methodId);

    corto_call(corto_function(_method), NULL, this);
}

void __test_MethodTester_virtualSimple_v(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_MethodTester_virtualSimple_v(
        test_MethodTester(*(void**)args));
}

void __test_MethodTesterInherit_overload__test_MethodTesterInherit(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    _test_MethodTesterInherit_overload__test_MethodTesterInherit(
        test_MethodTesterInherit(*(void**)args),
        test_MethodTesterInherit(*(test_MethodTesterInherit*)((intptr_t)args + sizeof(void*))));
}

void __test_MethodTesterInherit_overload_string_string(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    _test_MethodTesterInherit_overload_string_string(
        test_MethodTesterInherit(*(void**)args),
        *(corto_string*)((intptr_t)args + sizeof(void*)),
        *(corto_string*)((intptr_t)args + sizeof(void*) + sizeof(corto_string)));
}

void __test_MethodTesterInherit_simple(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_MethodTesterInherit_simple(
        test_MethodTesterInherit(*(void**)args));
}

void __test_MethodTesterInherit_virtualOverload(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(result);
    _test_MethodTesterInherit_virtualOverload(
        test_MethodTesterInherit(*(void**)args),
        *(corto_int32*)((intptr_t)args + sizeof(void*)));
}

void __test_ObjectMgmt_setup(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_ObjectMgmt_setup(
        test_ObjectMgmt(*(void**)args));
}

void __test_ObjectMgmt_tc_createChildFoo(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_ObjectMgmt_tc_createChildFoo(
        test_ObjectMgmt(*(void**)args));
}

void __test_ObjectMgmt_tc_createChildFooAttr0(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_ObjectMgmt_tc_createChildFooAttr0(
        test_ObjectMgmt(*(void**)args));
}

void __test_ObjectMgmt_tc_createChildInitFail(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_ObjectMgmt_tc_createChildInitFail(
        test_ObjectMgmt(*(void**)args));
}

void __test_ObjectMgmt_tc_createChildInt(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_ObjectMgmt_tc_createChildInt(
        test_ObjectMgmt(*(void**)args));
}

void __test_ObjectMgmt_tc_createChildIntAttr0(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_ObjectMgmt_tc_createChildIntAttr0(
        test_ObjectMgmt(*(void**)args));
}

void __test_ObjectMgmt_tc_createChildInvalidType(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_ObjectMgmt_tc_createChildInvalidType(
        test_ObjectMgmt(*(void**)args));
}

void __test_ObjectMgmt_tc_createChildNested(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_ObjectMgmt_tc_createChildNested(
        test_ObjectMgmt(*(void**)args));
}

void __test_ObjectMgmt_tc_createChildNullType(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_ObjectMgmt_tc_createChildNullType(
        test_ObjectMgmt(*(void**)args));
}

void __test_ObjectMgmt_tc_createChildParentStateErr(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_ObjectMgmt_tc_createChildParentStateErr(
        test_ObjectMgmt(*(void**)args));
}

void __test_ObjectMgmt_tc_createChildParentTypeErr(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_ObjectMgmt_tc_createChildParentTypeErr(
        test_ObjectMgmt(*(void**)args));
}

void __test_ObjectMgmt_tc_createChildVoid(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_ObjectMgmt_tc_createChildVoid(
        test_ObjectMgmt(*(void**)args));
}

void __test_ObjectMgmt_tc_createChildVoidAttr0(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_ObjectMgmt_tc_createChildVoidAttr0(
        test_ObjectMgmt(*(void**)args));
}

void __test_ObjectMgmt_tc_createFoo(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_ObjectMgmt_tc_createFoo(
        test_ObjectMgmt(*(void**)args));
}

void __test_ObjectMgmt_tc_createFooAttr0(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_ObjectMgmt_tc_createFooAttr0(
        test_ObjectMgmt(*(void**)args));
}

void __test_ObjectMgmt_tc_createInitFail(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_ObjectMgmt_tc_createInitFail(
        test_ObjectMgmt(*(void**)args));
}

void __test_ObjectMgmt_tc_createInt(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_ObjectMgmt_tc_createInt(
        test_ObjectMgmt(*(void**)args));
}

void __test_ObjectMgmt_tc_createIntAttr0(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_ObjectMgmt_tc_createIntAttr0(
        test_ObjectMgmt(*(void**)args));
}

void __test_ObjectMgmt_tc_createInvalidType(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_ObjectMgmt_tc_createInvalidType(
        test_ObjectMgmt(*(void**)args));
}

void __test_ObjectMgmt_tc_createNullType(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_ObjectMgmt_tc_createNullType(
        test_ObjectMgmt(*(void**)args));
}

void __test_ObjectMgmt_tc_createVoid(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_ObjectMgmt_tc_createVoid(
        test_ObjectMgmt(*(void**)args));
}

void __test_ObjectMgmt_tc_createVoidAttr0(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_ObjectMgmt_tc_createVoidAttr0(
        test_ObjectMgmt(*(void**)args));
}

void __test_ObjectMgmt_tc_declareChildFoo(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_ObjectMgmt_tc_declareChildFoo(
        test_ObjectMgmt(*(void**)args));
}

void __test_ObjectMgmt_tc_declareChildFooAttr0(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_ObjectMgmt_tc_declareChildFooAttr0(
        test_ObjectMgmt(*(void**)args));
}

void __test_ObjectMgmt_tc_declareChildInitFail(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_ObjectMgmt_tc_declareChildInitFail(
        test_ObjectMgmt(*(void**)args));
}

void __test_ObjectMgmt_tc_declareChildInt(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_ObjectMgmt_tc_declareChildInt(
        test_ObjectMgmt(*(void**)args));
}

void __test_ObjectMgmt_tc_declareChildIntAttr0(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_ObjectMgmt_tc_declareChildIntAttr0(
        test_ObjectMgmt(*(void**)args));
}

void __test_ObjectMgmt_tc_declareChildInvalidType(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_ObjectMgmt_tc_declareChildInvalidType(
        test_ObjectMgmt(*(void**)args));
}

void __test_ObjectMgmt_tc_declareChildNullType(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_ObjectMgmt_tc_declareChildNullType(
        test_ObjectMgmt(*(void**)args));
}

void __test_ObjectMgmt_tc_declareChildParentStateErr(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_ObjectMgmt_tc_declareChildParentStateErr(
        test_ObjectMgmt(*(void**)args));
}

void __test_ObjectMgmt_tc_declareChildParentTypeErr(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_ObjectMgmt_tc_declareChildParentTypeErr(
        test_ObjectMgmt(*(void**)args));
}

void __test_ObjectMgmt_tc_declareChildVoid(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_ObjectMgmt_tc_declareChildVoid(
        test_ObjectMgmt(*(void**)args));
}

void __test_ObjectMgmt_tc_declareChildVoidAttr0(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_ObjectMgmt_tc_declareChildVoidAttr0(
        test_ObjectMgmt(*(void**)args));
}

void __test_ObjectMgmt_tc_declareExistingWithParentState(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_ObjectMgmt_tc_declareExistingWithParentState(
        test_ObjectMgmt(*(void**)args));
}

void __test_ObjectMgmt_tc_declareFoo(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_ObjectMgmt_tc_declareFoo(
        test_ObjectMgmt(*(void**)args));
}

void __test_ObjectMgmt_tc_declareFooAttr0(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_ObjectMgmt_tc_declareFooAttr0(
        test_ObjectMgmt(*(void**)args));
}

void __test_ObjectMgmt_tc_declareInitFail(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_ObjectMgmt_tc_declareInitFail(
        test_ObjectMgmt(*(void**)args));
}

void __test_ObjectMgmt_tc_declareInt(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_ObjectMgmt_tc_declareInt(
        test_ObjectMgmt(*(void**)args));
}

void __test_ObjectMgmt_tc_declareIntAttr0(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_ObjectMgmt_tc_declareIntAttr0(
        test_ObjectMgmt(*(void**)args));
}

void __test_ObjectMgmt_tc_declareInvalidType(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_ObjectMgmt_tc_declareInvalidType(
        test_ObjectMgmt(*(void**)args));
}

void __test_ObjectMgmt_tc_declareNullType(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_ObjectMgmt_tc_declareNullType(
        test_ObjectMgmt(*(void**)args));
}

void __test_ObjectMgmt_tc_declareVoid(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_ObjectMgmt_tc_declareVoid(
        test_ObjectMgmt(*(void**)args));
}

void __test_ObjectMgmt_tc_declareVoidAttr0(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_ObjectMgmt_tc_declareVoidAttr0(
        test_ObjectMgmt(*(void**)args));
}

void __test_ObjectMgmt_tc_defineFoo(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_ObjectMgmt_tc_defineFoo(
        test_ObjectMgmt(*(void**)args));
}

void __test_ObjectMgmt_tc_defineFooAttr0(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_ObjectMgmt_tc_defineFooAttr0(
        test_ObjectMgmt(*(void**)args));
}

void __test_ObjectMgmt_tc_defineFooFail(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_ObjectMgmt_tc_defineFooFail(
        test_ObjectMgmt(*(void**)args));
}

void __test_ObjectMgmt_tc_defineInt(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_ObjectMgmt_tc_defineInt(
        test_ObjectMgmt(*(void**)args));
}

void __test_ObjectMgmt_tc_defineIntAttr0(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_ObjectMgmt_tc_defineIntAttr0(
        test_ObjectMgmt(*(void**)args));
}

void __test_ObjectMgmt_tc_defineVoid(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_ObjectMgmt_tc_defineVoid(
        test_ObjectMgmt(*(void**)args));
}

void __test_ObjectMgmt_tc_defineVoidAttr0(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_ObjectMgmt_tc_defineVoidAttr0(
        test_ObjectMgmt(*(void**)args));
}

void __test_ObjectMgmt_tc_drop(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_ObjectMgmt_tc_drop(
        test_ObjectMgmt(*(void**)args));
}

void __test_ObjectMgmt_tc_invalidate(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_ObjectMgmt_tc_invalidate(
        test_ObjectMgmt(*(void**)args));
}

void __test_ObjectMgmt_tc_redeclareWithDifferentType(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_ObjectMgmt_tc_redeclareWithDifferentType(
        test_ObjectMgmt(*(void**)args));
}

void __test_ObjectMgmt_teardown(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_ObjectMgmt_teardown(
        test_ObjectMgmt(*(void**)args));
}

void __test_Overload_tc_ambiguous(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Overload_tc_ambiguous(
        test_Overload(*(void**)args));
}

void __test_Overload_tc_ambiguousNull(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Overload_tc_ambiguousNull(
        test_Overload(*(void**)args));
}

void __test_Overload_tc_ambiguousWildcard(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Overload_tc_ambiguousWildcard(
        test_Overload(*(void**)args));
}

void __test_Overload_tc_anyChar(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Overload_tc_anyChar(
        test_Overload(*(void**)args));
}

void __test_Overload_tc_anyColor(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Overload_tc_anyColor(
        test_Overload(*(void**)args));
}

void __test_Overload_tc_anyFloat32(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Overload_tc_anyFloat32(
        test_Overload(*(void**)args));
}

void __test_Overload_tc_anyFloat64(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Overload_tc_anyFloat64(
        test_Overload(*(void**)args));
}

void __test_Overload_tc_anyInt16(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Overload_tc_anyInt16(
        test_Overload(*(void**)args));
}

void __test_Overload_tc_anyInt32(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Overload_tc_anyInt32(
        test_Overload(*(void**)args));
}

void __test_Overload_tc_anyInt64(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Overload_tc_anyInt64(
        test_Overload(*(void**)args));
}

void __test_Overload_tc_anyInt8(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Overload_tc_anyInt8(
        test_Overload(*(void**)args));
}

void __test_Overload_tc_anyOctet(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Overload_tc_anyOctet(
        test_Overload(*(void**)args));
}

void __test_Overload_tc_anyString(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Overload_tc_anyString(
        test_Overload(*(void**)args));
}

void __test_Overload_tc_anyUint16(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Overload_tc_anyUint16(
        test_Overload(*(void**)args));
}

void __test_Overload_tc_anyUint32(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Overload_tc_anyUint32(
        test_Overload(*(void**)args));
}

void __test_Overload_tc_anyUint64(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Overload_tc_anyUint64(
        test_Overload(*(void**)args));
}

void __test_Overload_tc_anyUint8(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Overload_tc_anyUint8(
        test_Overload(*(void**)args));
}

void __test_Overload_tc_anyWord(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Overload_tc_anyWord(
        test_Overload(*(void**)args));
}

void __test_Overload_tc_inheritanceBase(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Overload_tc_inheritanceBase(
        test_Overload(*(void**)args));
}

void __test_Overload_tc_inheritanceMatchSub(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Overload_tc_inheritanceMatchSub(
        test_Overload(*(void**)args));
}

void __test_Overload_tc_inheritanceSub(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Overload_tc_inheritanceSub(
        test_Overload(*(void**)args));
}

void __test_Overload_tc_inheritSibling(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Overload_tc_inheritSibling(
        test_Overload(*(void**)args));
}

void __test_Overload_tc_nullBool(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Overload_tc_nullBool(
        test_Overload(*(void**)args));
}

void __test_Overload_tc_nullObject(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Overload_tc_nullObject(
        test_Overload(*(void**)args));
}

void __test_Overload_tc_nullString(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Overload_tc_nullString(
        test_Overload(*(void**)args));
}

void __test_Overload_tc_numChar(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Overload_tc_numChar(
        test_Overload(*(void**)args));
}

void __test_Overload_tc_numColor(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Overload_tc_numColor(
        test_Overload(*(void**)args));
}

void __test_Overload_tc_numFloat32(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Overload_tc_numFloat32(
        test_Overload(*(void**)args));
}

void __test_Overload_tc_numFloat64(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Overload_tc_numFloat64(
        test_Overload(*(void**)args));
}

void __test_Overload_tc_numInt16(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Overload_tc_numInt16(
        test_Overload(*(void**)args));
}

void __test_Overload_tc_numInt32(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Overload_tc_numInt32(
        test_Overload(*(void**)args));
}

void __test_Overload_tc_numInt64(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Overload_tc_numInt64(
        test_Overload(*(void**)args));
}

void __test_Overload_tc_numInt8(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Overload_tc_numInt8(
        test_Overload(*(void**)args));
}

void __test_Overload_tc_numOctet(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Overload_tc_numOctet(
        test_Overload(*(void**)args));
}

void __test_Overload_tc_numString(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Overload_tc_numString(
        test_Overload(*(void**)args));
}

void __test_Overload_tc_numUint16(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Overload_tc_numUint16(
        test_Overload(*(void**)args));
}

void __test_Overload_tc_numUint32(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Overload_tc_numUint32(
        test_Overload(*(void**)args));
}

void __test_Overload_tc_numUint64(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Overload_tc_numUint64(
        test_Overload(*(void**)args));
}

void __test_Overload_tc_numUint8(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Overload_tc_numUint8(
        test_Overload(*(void**)args));
}

void __test_Overload_tc_numWord(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Overload_tc_numWord(
        test_Overload(*(void**)args));
}

void __test_Overload_tc_wildcard(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Overload_tc_wildcard(
        test_Overload(*(void**)args));
}

void __test_Project_setup(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Project_setup(
        test_Project(*(void**)args));
}

void __test_Project_tc_app(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Project_tc_app(
        test_Project(*(void**)args));
}

void __test_Project_tc_appNoTest(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Project_tc_appNoTest(
        test_Project(*(void**)args));
}

void __test_Project_tc_package(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Project_tc_package(
        test_Project(*(void**)args));
}

void __test_Project_tc_packageLocal(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Project_tc_packageLocal(
        test_Project(*(void**)args));
}

void __test_Project_tc_publishNotag(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Project_tc_publishNotag(
        test_Project(*(void**)args));
}

void __test_Project_teardown(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Project_teardown(
        test_Project(*(void**)args));
}

void __test_RelativeName_setup(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_RelativeName_setup(
        test_RelativeName(*(void**)args));
}

void __test_RelativeName_tc_fromChild(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_RelativeName_tc_fromChild(
        test_RelativeName(*(void**)args));
}

void __test_RelativeName_tc_fromDisjunct(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_RelativeName_tc_fromDisjunct(
        test_RelativeName(*(void**)args));
}

void __test_RelativeName_tc_fromGrandchild(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_RelativeName_tc_fromGrandchild(
        test_RelativeName(*(void**)args));
}

void __test_RelativeName_tc_fromOneUp(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_RelativeName_tc_fromOneUp(
        test_RelativeName(*(void**)args));
}

void __test_RelativeName_tc_fromParent(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_RelativeName_tc_fromParent(
        test_RelativeName(*(void**)args));
}

void __test_RelativeName_tc_fromRoot(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_RelativeName_tc_fromRoot(
        test_RelativeName(*(void**)args));
}

void __test_RelativeName_tc_fromSelf(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_RelativeName_tc_fromSelf(
        test_RelativeName(*(void**)args));
}

void __test_RelativeName_tc_fromThreeUp(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_RelativeName_tc_fromThreeUp(
        test_RelativeName(*(void**)args));
}

void __test_RelativeName_tc_fromTwoUp(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_RelativeName_tc_fromTwoUp(
        test_RelativeName(*(void**)args));
}

void __test_RelativeName_tc_rootFromObj(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_RelativeName_tc_rootFromObj(
        test_RelativeName(*(void**)args));
}

void __test_RelativeName_teardown(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_RelativeName_teardown(
        test_RelativeName(*(void**)args));
}

void __test_Resolver_setup(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Resolver_setup(
        test_Resolver(*(void**)args));
}

void __test_Resolver_tc_caseInsensitive(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Resolver_tc_caseInsensitive(
        test_Resolver(*(void**)args));
}

void __test_Resolver_tc_resolveAll(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Resolver_tc_resolveAll(
        test_Resolver(*(void**)args));
}

void __test_Resolver_tc_resolveAnonymous(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Resolver_tc_resolveAnonymous(
        test_Resolver(*(void**)args));
}

void __test_Resolver_tc_resolveCorto(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Resolver_tc_resolveCorto(
        test_Resolver(*(void**)args));
}

void __test_Resolver_tc_resolveEmptyString(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Resolver_tc_resolveEmptyString(
        test_Resolver(*(void**)args));
}

void __test_Resolver_tc_resolveFunctionArgs(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Resolver_tc_resolveFunctionArgs(
        test_Resolver(*(void**)args));
}

void __test_Resolver_tc_resolveFunctionNoArgs(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Resolver_tc_resolveFunctionNoArgs(
        test_Resolver(*(void**)args));
}

void __test_Resolver_tc_resolveIo(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Resolver_tc_resolveIo(
        test_Resolver(*(void**)args));
}

void __test_Resolver_tc_resolveLang(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Resolver_tc_resolveLang(
        test_Resolver(*(void**)args));
}

void __test_Resolver_tc_resolveNull(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Resolver_tc_resolveNull(
        test_Resolver(*(void**)args));
}

void __test_Resolver_tc_resolveParenthesesNoFunction(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Resolver_tc_resolveParenthesesNoFunction(
        test_Resolver(*(void**)args));
}

void __test_Resolver_tc_resolveParenthesesNoFunctionArgs(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Resolver_tc_resolveParenthesesNoFunctionArgs(
        test_Resolver(*(void**)args));
}

void __test_Resolver_tc_resolveParenthesesNoFunctionArgsScoped(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Resolver_tc_resolveParenthesesNoFunctionArgsScoped(
        test_Resolver(*(void**)args));
}

void __test_Resolver_tc_resolveParenthesesNoFunctionMatchingArgs(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Resolver_tc_resolveParenthesesNoFunctionMatchingArgs(
        test_Resolver(*(void**)args));
}

void __test_Resolver_tc_resolveParenthesesNoFunctionMatchingArgsScoped(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Resolver_tc_resolveParenthesesNoFunctionMatchingArgsScoped(
        test_Resolver(*(void**)args));
}

void __test_Resolver_tc_resolveParenthesesNoFunctionScoped(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Resolver_tc_resolveParenthesesNoFunctionScoped(
        test_Resolver(*(void**)args));
}

void __test_Resolver_tc_resolveRoot(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Resolver_tc_resolveRoot(
        test_Resolver(*(void**)args));
}

void __test_Resolver_tc_resolveString(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Resolver_tc_resolveString(
        test_Resolver(*(void**)args));
}

void __test_Resolver_tc_resolveThis(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Resolver_tc_resolveThis(
        test_Resolver(*(void**)args));
}

void __test_Resolver_teardown(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Resolver_teardown(
        test_Resolver(*(void**)args));
}

void __test_Select_collect(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    *(test_selectItemList*)result = _test_Select_collect(
        *(corto_object*)args,
        *(corto_string*)((intptr_t)args + sizeof(corto_object)));
}

void __test_Select_hasObject(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    *(corto_bool*)result = _test_Select_hasObject(
        *(test_selectItemList*)args,
        *(corto_string*)((intptr_t)args + sizeof(test_selectItemList)),
        *(corto_string*)((intptr_t)args + sizeof(test_selectItemList) + sizeof(corto_string)),
        *(corto_string*)((intptr_t)args + sizeof(test_selectItemList) + sizeof(corto_string) + sizeof(corto_string)));
}

void __test_Select_setup(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Select_setup(
        test_Select(*(void**)args));
}

void __test_Select_tc_selectDeleteCurrent(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Select_tc_selectDeleteCurrent(
        test_Select(*(void**)args));
}

void __test_Select_tc_selectDeleteFirst(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Select_tc_selectDeleteFirst(
        test_Select(*(void**)args));
}

void __test_Select_tc_selectDeleteNext(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Select_tc_selectDeleteNext(
        test_Select(*(void**)args));
}

void __test_Select_tc_selectDeleteParent(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Select_tc_selectDeleteParent(
        test_Select(*(void**)args));
}

void __test_Select_tc_selectDeletePrevious(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Select_tc_selectDeletePrevious(
        test_Select(*(void**)args));
}

void __test_Select_tc_selectErrParentAst(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Select_tc_selectErrParentAst(
        test_Select(*(void**)args));
}

void __test_Select_tc_selectErrParentId(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Select_tc_selectErrParentId(
        test_Select(*(void**)args));
}

void __test_Select_tc_selectErrParentTree(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Select_tc_selectErrParentTree(
        test_Select(*(void**)args));
}

void __test_Select_tc_selectErrParentWc(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Select_tc_selectErrParentWc(
        test_Select(*(void**)args));
}

void __test_Select_tc_selectErrScopeScope(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Select_tc_selectErrScopeScope(
        test_Select(*(void**)args));
}

void __test_Select_tc_selectFilterAsterisk(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Select_tc_selectFilterAsterisk(
        test_Select(*(void**)args));
}

void __test_Select_tc_selectFilterWildcard(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Select_tc_selectFilterWildcard(
        test_Select(*(void**)args));
}

void __test_Select_tc_selectIdentifier(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Select_tc_selectIdentifier(
        test_Select(*(void**)args));
}

void __test_Select_tc_selectIdentifierCaps(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Select_tc_selectIdentifierCaps(
        test_Select(*(void**)args));
}

void __test_Select_tc_selectNumeric(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Select_tc_selectNumeric(
        test_Select(*(void**)args));
}

void __test_Select_tc_selectOrder(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Select_tc_selectOrder(
        test_Select(*(void**)args));
}

void __test_Select_tc_selectParent(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Select_tc_selectParent(
        test_Select(*(void**)args));
}

void __test_Select_tc_selectScope(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Select_tc_selectScope(
        test_Select(*(void**)args));
}

void __test_Select_tc_selectScopedIdentifier(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Select_tc_selectScopedIdentifier(
        test_Select(*(void**)args));
}

void __test_Select_tc_selectScopedParent(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Select_tc_selectScopedParent(
        test_Select(*(void**)args));
}

void __test_Select_tc_selectScopedThis(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Select_tc_selectScopedThis(
        test_Select(*(void**)args));
}

void __test_Select_tc_selectScopeWithAsterisk(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Select_tc_selectScopeWithAsterisk(
        test_Select(*(void**)args));
}

void __test_Select_tc_selectScopeWithAsteriskFilter(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Select_tc_selectScopeWithAsteriskFilter(
        test_Select(*(void**)args));
}

void __test_Select_tc_selectScopeWithWildcard(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Select_tc_selectScopeWithWildcard(
        test_Select(*(void**)args));
}

void __test_Select_tc_selectScopeWithWildcardFilter(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Select_tc_selectScopeWithWildcardFilter(
        test_Select(*(void**)args));
}

void __test_Select_tc_selectThis(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Select_tc_selectThis(
        test_Select(*(void**)args));
}

void __test_Select_tc_selectTree(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Select_tc_selectTree(
        test_Select(*(void**)args));
}

void __test_Select_tc_selectTreeDeleteCurrent(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Select_tc_selectTreeDeleteCurrent(
        test_Select(*(void**)args));
}

void __test_Select_tc_selectTreeDeleteFirst(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Select_tc_selectTreeDeleteFirst(
        test_Select(*(void**)args));
}

void __test_Select_tc_selectTreeDeleteGrandparent(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Select_tc_selectTreeDeleteGrandparent(
        test_Select(*(void**)args));
}

void __test_Select_tc_selectTreeDeleteNext(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Select_tc_selectTreeDeleteNext(
        test_Select(*(void**)args));
}

void __test_Select_tc_selectTreeDeleteParent(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Select_tc_selectTreeDeleteParent(
        test_Select(*(void**)args));
}

void __test_Select_tc_selectTreeDeletePrevious(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Select_tc_selectTreeDeletePrevious(
        test_Select(*(void**)args));
}

void __test_Select_tc_selectTreeWithAsterisk(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Select_tc_selectTreeWithAsterisk(
        test_Select(*(void**)args));
}

void __test_Select_tc_selectTreeWithAsteriskFilter(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Select_tc_selectTreeWithAsteriskFilter(
        test_Select(*(void**)args));
}

void __test_Select_tc_selectTreeWithWildcard(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Select_tc_selectTreeWithWildcard(
        test_Select(*(void**)args));
}

void __test_Select_tc_selectTreeWithWildcardFilter(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Select_tc_selectTreeWithWildcardFilter(
        test_Select(*(void**)args));
}

void __test_Select_tc_selectUnderscore(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Select_tc_selectUnderscore(
        test_Select(*(void**)args));
}

void __test_Select_teardown(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_Select_teardown(
        test_Select(*(void**)args));
}

void __test_StringDeserializer_setup(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_StringDeserializer_setup(
        test_StringDeserializer(*(void**)args));
}

void __test_StringDeserializer_tc_deserAnonymousMultiple(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_StringDeserializer_tc_deserAnonymousMultiple(
        test_StringDeserializer(*(void**)args));
}

void __test_StringDeserializer_tc_deserAnonymousNested(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_StringDeserializer_tc_deserAnonymousNested(
        test_StringDeserializer(*(void**)args));
}

void __test_StringDeserializer_tc_deserAnonymousReuse(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_StringDeserializer_tc_deserAnonymousReuse(
        test_StringDeserializer(*(void**)args));
}

void __test_StringDeserializer_tc_deserAnonymousReuseNested(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_StringDeserializer_tc_deserAnonymousReuseNested(
        test_StringDeserializer(*(void**)args));
}

void __test_StringDeserializer_tc_deserAnonymousSimple(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_StringDeserializer_tc_deserAnonymousSimple(
        test_StringDeserializer(*(void**)args));
}

void __test_StringDeserializer_tc_deserBoolFalse(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_StringDeserializer_tc_deserBoolFalse(
        test_StringDeserializer(*(void**)args));
}

void __test_StringDeserializer_tc_deserBoolInvalid(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_StringDeserializer_tc_deserBoolInvalid(
        test_StringDeserializer(*(void**)args));
}

void __test_StringDeserializer_tc_deserBoolTrue(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_StringDeserializer_tc_deserBoolTrue(
        test_StringDeserializer(*(void**)args));
}

void __test_StringDeserializer_tc_deserChar(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_StringDeserializer_tc_deserChar(
        test_StringDeserializer(*(void**)args));
}

void __test_StringDeserializer_tc_deserCharEscape(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_StringDeserializer_tc_deserCharEscape(
        test_StringDeserializer(*(void**)args));
}

void __test_StringDeserializer_tc_deserCharEscapeQuoted(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_StringDeserializer_tc_deserCharEscapeQuoted(
        test_StringDeserializer(*(void**)args));
}

void __test_StringDeserializer_tc_deserCharNull(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_StringDeserializer_tc_deserCharNull(
        test_StringDeserializer(*(void**)args));
}

void __test_StringDeserializer_tc_deserCharNullQuoted(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_StringDeserializer_tc_deserCharNullQuoted(
        test_StringDeserializer(*(void**)args));
}

void __test_StringDeserializer_tc_deserCharQuoted(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_StringDeserializer_tc_deserCharQuoted(
        test_StringDeserializer(*(void**)args));
}

void __test_StringDeserializer_tc_deserCollection(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_StringDeserializer_tc_deserCollection(
        test_StringDeserializer(*(void**)args));
}

void __test_StringDeserializer_tc_deserCollectionComplex(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_StringDeserializer_tc_deserCollectionComplex(
        test_StringDeserializer(*(void**)args));
}

void __test_StringDeserializer_tc_deserComposite(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_StringDeserializer_tc_deserComposite(
        test_StringDeserializer(*(void**)args));
}

void __test_StringDeserializer_tc_deserCompositeMembers(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_StringDeserializer_tc_deserCompositeMembers(
        test_StringDeserializer(*(void**)args));
}

void __test_StringDeserializer_tc_deserCompositeMixed(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_StringDeserializer_tc_deserCompositeMixed(
        test_StringDeserializer(*(void**)args));
}

void __test_StringDeserializer_tc_deserCompositeNested(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_StringDeserializer_tc_deserCompositeNested(
        test_StringDeserializer(*(void**)args));
}

void __test_StringDeserializer_tc_deserCompositeNestedMembers(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_StringDeserializer_tc_deserCompositeNestedMembers(
        test_StringDeserializer(*(void**)args));
}

void __test_StringDeserializer_tc_deserCompositeNestedMixed(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_StringDeserializer_tc_deserCompositeNestedMixed(
        test_StringDeserializer(*(void**)args));
}

void __test_StringDeserializer_tc_deserCompositeNoType(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_StringDeserializer_tc_deserCompositeNoType(
        test_StringDeserializer(*(void**)args));
}

void __test_StringDeserializer_tc_deserCompositeWhitespace(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_StringDeserializer_tc_deserCompositeWhitespace(
        test_StringDeserializer(*(void**)args));
}

void __test_StringDeserializer_tc_deserExisting(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_StringDeserializer_tc_deserExisting(
        test_StringDeserializer(*(void**)args));
}

void __test_StringDeserializer_tc_deserExisting_w_scopedType(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_StringDeserializer_tc_deserExisting_w_scopedType(
        test_StringDeserializer(*(void**)args));
}

void __test_StringDeserializer_tc_deserExisting_w_type(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_StringDeserializer_tc_deserExisting_w_type(
        test_StringDeserializer(*(void**)args));
}

void __test_StringDeserializer_tc_deserInheritance(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_StringDeserializer_tc_deserInheritance(
        test_StringDeserializer(*(void**)args));
}

void __test_StringDeserializer_tc_deserInheritanceMembers(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_StringDeserializer_tc_deserInheritanceMembers(
        test_StringDeserializer(*(void**)args));
}

void __test_StringDeserializer_tc_deserInheritanceMixed(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_StringDeserializer_tc_deserInheritanceMixed(
        test_StringDeserializer(*(void**)args));
}

void __test_StringDeserializer_tc_deserInt16(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_StringDeserializer_tc_deserInt16(
        test_StringDeserializer(*(void**)args));
}

void __test_StringDeserializer_tc_deserInt16Minus(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_StringDeserializer_tc_deserInt16Minus(
        test_StringDeserializer(*(void**)args));
}

void __test_StringDeserializer_tc_deserInt16Overflow(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_StringDeserializer_tc_deserInt16Overflow(
        test_StringDeserializer(*(void**)args));
}

void __test_StringDeserializer_tc_deserInt32(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_StringDeserializer_tc_deserInt32(
        test_StringDeserializer(*(void**)args));
}

void __test_StringDeserializer_tc_deserInt32Minus(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_StringDeserializer_tc_deserInt32Minus(
        test_StringDeserializer(*(void**)args));
}

void __test_StringDeserializer_tc_deserInt32Overflow(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_StringDeserializer_tc_deserInt32Overflow(
        test_StringDeserializer(*(void**)args));
}

void __test_StringDeserializer_tc_deserInt64(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_StringDeserializer_tc_deserInt64(
        test_StringDeserializer(*(void**)args));
}

void __test_StringDeserializer_tc_deserInt64Minus(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_StringDeserializer_tc_deserInt64Minus(
        test_StringDeserializer(*(void**)args));
}

void __test_StringDeserializer_tc_deserInt8(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_StringDeserializer_tc_deserInt8(
        test_StringDeserializer(*(void**)args));
}

void __test_StringDeserializer_tc_deserInt8Minus(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_StringDeserializer_tc_deserInt8Minus(
        test_StringDeserializer(*(void**)args));
}

void __test_StringDeserializer_tc_deserInt8Overflow(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_StringDeserializer_tc_deserInt8Overflow(
        test_StringDeserializer(*(void**)args));
}

void __test_StringDeserializer_tc_deserString(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_StringDeserializer_tc_deserString(
        test_StringDeserializer(*(void**)args));
}

void __test_StringDeserializer_tc_deserStringEscape(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_StringDeserializer_tc_deserStringEscape(
        test_StringDeserializer(*(void**)args));
}

void __test_StringDeserializer_tc_deserStringQuotes(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_StringDeserializer_tc_deserStringQuotes(
        test_StringDeserializer(*(void**)args));
}

void __test_StringDeserializer_tc_deserStringQuotesWhitespaces(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_StringDeserializer_tc_deserStringQuotesWhitespaces(
        test_StringDeserializer(*(void**)args));
}

void __test_StringDeserializer_tc_deserStringWhitespace(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_StringDeserializer_tc_deserStringWhitespace(
        test_StringDeserializer(*(void**)args));
}

void __test_StringDeserializer_tc_deserStringWhitespaceTrailing(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_StringDeserializer_tc_deserStringWhitespaceTrailing(
        test_StringDeserializer(*(void**)args));
}

void __test_StringDeserializer_tc_deserStringWhitespaceTrailingNoType(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_StringDeserializer_tc_deserStringWhitespaceTrailingNoType(
        test_StringDeserializer(*(void**)args));
}

void __test_StringDeserializer_tc_deserUint16(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_StringDeserializer_tc_deserUint16(
        test_StringDeserializer(*(void**)args));
}

void __test_StringDeserializer_tc_deserUint16Overflow(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_StringDeserializer_tc_deserUint16Overflow(
        test_StringDeserializer(*(void**)args));
}

void __test_StringDeserializer_tc_deserUint32(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_StringDeserializer_tc_deserUint32(
        test_StringDeserializer(*(void**)args));
}

void __test_StringDeserializer_tc_deserUint32Overflow(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_StringDeserializer_tc_deserUint32Overflow(
        test_StringDeserializer(*(void**)args));
}

void __test_StringDeserializer_tc_deserUint64(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_StringDeserializer_tc_deserUint64(
        test_StringDeserializer(*(void**)args));
}

void __test_StringDeserializer_tc_deserUint8(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_StringDeserializer_tc_deserUint8(
        test_StringDeserializer(*(void**)args));
}

void __test_StringDeserializer_tc_deserUint8Overflow(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_StringDeserializer_tc_deserUint8Overflow(
        test_StringDeserializer(*(void**)args));
}

void __test_StringDeserializer_tc_errExcessElements(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_StringDeserializer_tc_errExcessElements(
        test_StringDeserializer(*(void**)args));
}

void __test_StringDeserializer_tc_errMissingType(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_StringDeserializer_tc_errMissingType(
        test_StringDeserializer(*(void**)args));
}

void __test_StringDeserializer_tc_errNotAType(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_StringDeserializer_tc_errNotAType(
        test_StringDeserializer(*(void**)args));
}

void __test_StringDeserializer_tc_errTypeMismatch(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_StringDeserializer_tc_errTypeMismatch(
        test_StringDeserializer(*(void**)args));
}

void __test_StringDeserializer_tc_errUnresolvedMember(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_StringDeserializer_tc_errUnresolvedMember(
        test_StringDeserializer(*(void**)args));
}

void __test_StringDeserializer_tc_errUnresolvedType(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_StringDeserializer_tc_errUnresolvedType(
        test_StringDeserializer(*(void**)args));
}

void __test_StringDeserializer_teardown(corto_function f, void *result, void *args) {
    CORTO_UNUSED(f);
    CORTO_UNUSED(args);
    CORTO_UNUSED(result);
    _test_StringDeserializer_teardown(
        test_StringDeserializer(*(void**)args));
}
