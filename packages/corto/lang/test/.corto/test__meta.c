/* test__meta.c
 *
 * Loads objects in object store.
 * This file contains generated code. Do not modify!
 */

#include "test.h"

/* Variable definitions */
corto_package test_o;
corto_class test_Animal_o;
corto_member test_Animal_a_o;
corto_class test_AnonymousTest_o;
corto_member test_AnonymousTest_objects_o;
test_Suite test_Args_o;
test_Case test_Args_tc_matchAddNoProject_o;
test_Case test_Args_tc_matchAll_o;
test_Case test_Args_tc_matchCreate_o;
test_Case test_Args_tc_matchCreateApp_o;
test_Case test_Args_tc_matchCreateMultiple_o;
test_Case test_Args_tc_matchCreatePackage_o;
test_Case test_Args_tc_matchCreatePackageAndApp_o;
test_Case test_Args_tc_matchCreatePackageAndAppEscaped_o;
test_Case test_Args_tc_matchCreatePackageOptions_o;
test_Case test_Args_tc_matchDuplicate_o;
test_Case test_Args_tc_matchDuplicateArg_o;
test_Case test_Args_tc_matchErr_o;
test_Case test_Args_tc_matchFixed_o;
test_Case test_Args_tc_matchMultiple_o;
test_Case test_Args_tc_matchMultipleArg_o;
test_Case test_Args_tc_matchNone_o;
test_Case test_Args_tc_matchOptional_o;
test_Case test_Args_tc_matchOptionalOneArg_o;
test_Case test_Args_tc_matchOptionalWithOtherArgs_o;
test_Case test_Args_tc_matchPattern_o;
test_Case test_Args_tc_matchPublish_o;
test_Case test_Args_tc_matchPublishNoProject_o;
test_Case test_Args_tc_matchShell_o;
test_Case test_Args_tc_matchSingle_o;
test_Case test_Args_tc_matchSingleArg_o;
corto_class test_Bar_o;
corto_member test_Bar___dummy_o;
corto_method test_Bar_init_o;
corto_class test_Cat_o;
corto_member test_Cat_b_o;
corto_enum test_Color_o;
corto_constant ___ (*test_Color_Blue_o);
corto_constant ___ (*test_Color_Green_o);
corto_constant ___ (*test_Color_Orange_o);
corto_constant ___ (*test_Color_Red_o);
corto_constant ___ (*test_Color_Yellow_o);
corto_struct test_CompositeCollection_o;
corto_member test_CompositeCollection_points_o;
corto_int8 ___ (*test_constructCalled_o);
corto_struct test_DeclaredParent_o;
corto_member test_DeclaredParent_Foo_o;
corto_struct test_DefinedParent_o;
corto_member test_DefinedParent_Foo_o;
corto_int8 ___ (*test_destructCalled_o);
corto_class test_Dog_o;
corto_member test_Dog_b_o;
test_Suite test_Env_o;
test_Case test_Env_tc_envparseFormatAndReplace_o;
test_Case test_Env_tc_envparseReplaceMultiple_o;
test_Case test_Env_tc_envparseReplaceWithSameVariable_o;
test_Case test_Env_tc_envparseSimpleFormat_o;
test_Case test_Env_tc_envparseSimpleReplace_o;
test_Case test_Env_tc_envparseVariableNotFound_o;
test_Case test_Env_tc_setenvFormatAndReplace_o;
test_Case test_Env_tc_setenvNull_o;
test_Case test_Env_tc_setenvReplaceMultiple_o;
test_Case test_Env_tc_setenvReplaceWithSameVariable_o;
test_Case test_Env_tc_setenvSimple_o;
test_Case test_Env_tc_setenvSimpleFormat_o;
test_Case test_Env_tc_setenvSimpleReplace_o;
test_Case test_Env_tc_setenvVariableNotFound_o;
test_Suite test_Event_o;
corto_member test_Event_et_o;
corto_member test_Event_prevAttr_o;
corto_method test_Event_setup_o;
test_Case test_Event_tc_onDeclare_o;
test_Case test_Event_tc_onDeclareScope_o;
test_Case test_Event_tc_onDeclareSelf_o;
test_Case test_Event_tc_onDeclareTree_o;
test_Case test_Event_tc_onDefine_o;
test_Case test_Event_tc_onDefineScope_o;
test_Case test_Event_tc_onDefineSelf_o;
test_Case test_Event_tc_onDefineTree_o;
test_Case test_Event_tc_onDelete_o;
test_Case test_Event_tc_onDeleteScope_o;
test_Case test_Event_tc_onDeleteSelf_o;
test_Case test_Event_tc_onDeleteTree_o;
test_Case test_Event_tc_onUpdate_o;
test_Case test_Event_tc_onUpdateScope_o;
test_Case test_Event_tc_onUpdateSelf_o;
test_Case test_Event_tc_onUpdateTree_o;
test_Case test_Event_tc_updateUndefined_o;
test_Case test_Event_tc_updateVoidErr_o;
corto_method test_Event_teardown_o;
corto_class test_EventTest_o;
corto_method test_EventTest_construct_o;
corto_member test_EventTest_countDeclare_o;
corto_member test_EventTest_countDeclareScope_o;
corto_member test_EventTest_countDeclareSelf_o;
corto_member test_EventTest_countDeclareTree_o;
corto_member test_EventTest_countDefine_o;
corto_member test_EventTest_countDefineScope_o;
corto_member test_EventTest_countDefineSelf_o;
corto_member test_EventTest_countDefineTree_o;
corto_member test_EventTest_countDelete_o;
corto_member test_EventTest_countDeleteScope_o;
corto_member test_EventTest_countDeleteSelf_o;
corto_member test_EventTest_countDeleteTree_o;
corto_member test_EventTest_countUpdate_o;
corto_member test_EventTest_countUpdateScope_o;
corto_member test_EventTest_countUpdateSelf_o;
corto_member test_EventTest_countUpdateTree_o;
corto_member test_EventTest_lastObservable_o;
corto_member test_EventTest_lastThis_o;
corto_observer test_EventTest_onDeclare_o;
corto_observer test_EventTest_onDeclareScope_o;
corto_observer test_EventTest_onDeclareSelf_o;
corto_observer test_EventTest_onDeclareTree_o;
corto_observer test_EventTest_onDefine_o;
corto_observer test_EventTest_onDefineScope_o;
corto_observer test_EventTest_onDefineSelf_o;
corto_observer test_EventTest_onDefineTree_o;
corto_observer test_EventTest_onDelete_o;
corto_observer test_EventTest_onDeleteScope_o;
corto_observer test_EventTest_onDeleteSelf_o;
corto_observer test_EventTest_onDeleteTree_o;
corto_observer test_EventTest_onUpdate_o;
corto_observer test_EventTest_onUpdateScope_o;
corto_observer test_EventTest_onUpdateSelf_o;
corto_observer test_EventTest_onUpdateTree_o;
corto_member test_EventTest_scope_o;
corto_class test_Foo_o;
corto_method test_Foo_construct_o;
corto_method test_Foo_destruct_o;
corto_member test_Foo_fail_o;
corto_method test_Foo_init_o;
corto_member test_Foo_x_o;
corto_member test_Foo_y_o;
test_Suite test_Fullname_o;
test_Case test_Fullname_tc_null_o;
test_Case test_Fullname_tc_nullBuffer_o;
test_Case test_Fullname_tc_onelevel_o;
test_Case test_Fullname_tc_root_o;
test_Case test_Fullname_tc_twolevels_o;
corto_function test_functionToResolve_o;
corto_class test_GoldenRetriever_o;
corto_member test_GoldenRetriever_c_o;
corto_int8 ___ (*test_initCalled_o);
corto_struct test_Line_o;
corto_member test_Line_start_o;
corto_member test_Line_stop_o;
test_Suite test_MethodResolver_o;
test_Case test_MethodResolver_tc_inheritOverload_o;
test_Case test_MethodResolver_tc_inheritOverloadBaseClass_o;
test_Case test_MethodResolver_tc_inheritOverloadBaseInt_o;
test_Case test_MethodResolver_tc_inheritOverloadBaseString_o;
test_Case test_MethodResolver_tc_inheritOverloadBaseTwoArgs_o;
test_Case test_MethodResolver_tc_inheritOverloadClass_o;
test_Case test_MethodResolver_tc_inheritOverloadNoArgs_o;
test_Case test_MethodResolver_tc_inheritSimple_o;
test_Case test_MethodResolver_tc_inheritSimpleNoArgs_o;
test_Case test_MethodResolver_tc_inheritVirtualOverload_o;
test_Case test_MethodResolver_tc_inheritVirtualOverloadNoArgs_o;
test_Case test_MethodResolver_tc_nonexisting_o;
test_Case test_MethodResolver_tc_onearg_o;
test_Case test_MethodResolver_tc_oneargErr_o;
test_Case test_MethodResolver_tc_oneargErrType_o;
test_Case test_MethodResolver_tc_oneargNoArgs_o;
test_Case test_MethodResolver_tc_overloadAmbiguous_o;
test_Case test_MethodResolver_tc_overloadClass_o;
test_Case test_MethodResolver_tc_overloadInt_o;
test_Case test_MethodResolver_tc_overloadString_o;
test_Case test_MethodResolver_tc_overloadTwoArgs_o;
test_Case test_MethodResolver_tc_redeclare_o;
test_Case test_MethodResolver_tc_simple_o;
test_Case test_MethodResolver_tc_simpleErr_o;
test_Case test_MethodResolver_tc_simpleErrType_o;
test_Case test_MethodResolver_tc_simpleNoArgs_o;
test_Case test_MethodResolver_tc_twoargs_o;
test_Case test_MethodResolver_tc_twoargsNoArgs_o;
test_Case test_MethodResolver_tc_twoargsSpaces_o;
test_Case test_MethodResolver_tc_virtualOverload_o;
test_Case test_MethodResolver_tc_virtualOverloadArg_o;
test_Case test_MethodResolver_tc_virtualOverloadNoArgs_o;
test_Case test_MethodResolver_tc_virtualSimple_o;
test_Case test_MethodResolver_tc_virtualSimpleNoArgs_o;
corto_class test_MethodTester_o;
corto_member test_MethodTester___dummy_o;
corto_method test_MethodTester_onearg_o;
corto_method test_MethodTester_overload__test_MethodTester_o;
corto_method test_MethodTester_overload_int32_o;
corto_method test_MethodTester_overload_int32_int32_o;
corto_method test_MethodTester_overload_string_o;
corto_method test_MethodTester_simple_o;
corto_method test_MethodTester_twoargs_o;
corto_virtual test_MethodTester_virtualOverload__o;
corto_method test_MethodTester_virtualOverload_int32_o;
corto_virtual test_MethodTester_virtualSimple_o;
corto_class test_MethodTesterInherit_o;
corto_method test_MethodTesterInherit_overload__test_MethodTesterInherit_o;
corto_method test_MethodTesterInherit_overload_string_string_o;
corto_method test_MethodTesterInherit_simple_o;
corto_method test_MethodTesterInherit_virtualOverload_o;
test_Suite test_ObjectMgmt_o;
corto_member test_ObjectMgmt_prevAttr_o;
corto_method test_ObjectMgmt_setup_o;
test_Case test_ObjectMgmt_tc_createChildFoo_o;
test_Case test_ObjectMgmt_tc_createChildFooAttr0_o;
test_Case test_ObjectMgmt_tc_createChildInitFail_o;
test_Case test_ObjectMgmt_tc_createChildInt_o;
test_Case test_ObjectMgmt_tc_createChildIntAttr0_o;
test_Case test_ObjectMgmt_tc_createChildInvalidType_o;
test_Case test_ObjectMgmt_tc_createChildNested_o;
test_Case test_ObjectMgmt_tc_createChildNullType_o;
test_Case test_ObjectMgmt_tc_createChildParentStateErr_o;
test_Case test_ObjectMgmt_tc_createChildParentTypeErr_o;
test_Case test_ObjectMgmt_tc_createChildVoid_o;
test_Case test_ObjectMgmt_tc_createChildVoidAttr0_o;
test_Case test_ObjectMgmt_tc_createFoo_o;
test_Case test_ObjectMgmt_tc_createFooAttr0_o;
test_Case test_ObjectMgmt_tc_createInitFail_o;
test_Case test_ObjectMgmt_tc_createInt_o;
test_Case test_ObjectMgmt_tc_createIntAttr0_o;
test_Case test_ObjectMgmt_tc_createInvalidType_o;
test_Case test_ObjectMgmt_tc_createNullType_o;
test_Case test_ObjectMgmt_tc_createVoid_o;
test_Case test_ObjectMgmt_tc_createVoidAttr0_o;
test_Case test_ObjectMgmt_tc_declareChildFoo_o;
test_Case test_ObjectMgmt_tc_declareChildFooAttr0_o;
test_Case test_ObjectMgmt_tc_declareChildInitFail_o;
test_Case test_ObjectMgmt_tc_declareChildInt_o;
test_Case test_ObjectMgmt_tc_declareChildIntAttr0_o;
test_Case test_ObjectMgmt_tc_declareChildInvalidType_o;
test_Case test_ObjectMgmt_tc_declareChildNullType_o;
test_Case test_ObjectMgmt_tc_declareChildParentStateErr_o;
test_Case test_ObjectMgmt_tc_declareChildParentTypeErr_o;
test_Case test_ObjectMgmt_tc_declareChildVoid_o;
test_Case test_ObjectMgmt_tc_declareChildVoidAttr0_o;
test_Case test_ObjectMgmt_tc_declareExistingWithParentState_o;
test_Case test_ObjectMgmt_tc_declareFoo_o;
test_Case test_ObjectMgmt_tc_declareFooAttr0_o;
test_Case test_ObjectMgmt_tc_declareInitFail_o;
test_Case test_ObjectMgmt_tc_declareInt_o;
test_Case test_ObjectMgmt_tc_declareIntAttr0_o;
test_Case test_ObjectMgmt_tc_declareInvalidType_o;
test_Case test_ObjectMgmt_tc_declareNullType_o;
test_Case test_ObjectMgmt_tc_declareVoid_o;
test_Case test_ObjectMgmt_tc_declareVoidAttr0_o;
test_Case test_ObjectMgmt_tc_defineFoo_o;
test_Case test_ObjectMgmt_tc_defineFooAttr0_o;
test_Case test_ObjectMgmt_tc_defineFooFail_o;
test_Case test_ObjectMgmt_tc_defineInt_o;
test_Case test_ObjectMgmt_tc_defineIntAttr0_o;
test_Case test_ObjectMgmt_tc_defineVoid_o;
test_Case test_ObjectMgmt_tc_defineVoidAttr0_o;
test_Case test_ObjectMgmt_tc_drop_o;
test_Case test_ObjectMgmt_tc_invalidate_o;
test_Case test_ObjectMgmt_tc_redeclareWithDifferentType_o;
corto_method test_ObjectMgmt_teardown_o;
corto_function test_ol_any__test_Color_o;
corto_function test_ol_any_bool_o;
corto_function test_ol_any_char_o;
corto_function test_ol_any_float32_o;
corto_function test_ol_any_int32_o;
corto_function test_ol_any_object_o;
corto_function test_ol_any_string_o;
corto_function test_ol_bool_o;
corto_function test_ol_inherit__test_Animal_o;
corto_function test_ol_inherit__test_Dog_o;
corto_function test_ol_int_o;
corto_function test_ol_null_bool_o;
corto_function test_ol_null_object_o;
corto_function test_ol_null_string_o;
corto_function test_ol_num_float64_o;
corto_function test_ol_num_int32_o;
corto_function test_ol_object_o;
corto_function test_ol_string_o;
corto_function test_ol_uint_o;
corto_function test_ol_wildcard_float32_string_o;
corto_function test_ol_wildcard_int32_string_o;
test_Suite test_Overload_o;
test_Case test_Overload_tc_ambiguous_o;
test_Case test_Overload_tc_ambiguousNull_o;
test_Case test_Overload_tc_ambiguousWildcard_o;
test_Case test_Overload_tc_anyChar_o;
test_Case test_Overload_tc_anyColor_o;
test_Case test_Overload_tc_anyFloat32_o;
test_Case test_Overload_tc_anyFloat64_o;
test_Case test_Overload_tc_anyInt16_o;
test_Case test_Overload_tc_anyInt32_o;
test_Case test_Overload_tc_anyInt64_o;
test_Case test_Overload_tc_anyInt8_o;
test_Case test_Overload_tc_anyOctet_o;
test_Case test_Overload_tc_anyString_o;
test_Case test_Overload_tc_anyUint16_o;
test_Case test_Overload_tc_anyUint32_o;
test_Case test_Overload_tc_anyUint64_o;
test_Case test_Overload_tc_anyUint8_o;
test_Case test_Overload_tc_anyWord_o;
test_Case test_Overload_tc_inheritanceBase_o;
test_Case test_Overload_tc_inheritanceMatchSub_o;
test_Case test_Overload_tc_inheritanceSub_o;
test_Case test_Overload_tc_inheritSibling_o;
test_Case test_Overload_tc_nullBool_o;
test_Case test_Overload_tc_nullObject_o;
test_Case test_Overload_tc_nullString_o;
test_Case test_Overload_tc_numChar_o;
test_Case test_Overload_tc_numColor_o;
test_Case test_Overload_tc_numFloat32_o;
test_Case test_Overload_tc_numFloat64_o;
test_Case test_Overload_tc_numInt16_o;
test_Case test_Overload_tc_numInt32_o;
test_Case test_Overload_tc_numInt64_o;
test_Case test_Overload_tc_numInt8_o;
test_Case test_Overload_tc_numOctet_o;
test_Case test_Overload_tc_numString_o;
test_Case test_Overload_tc_numUint16_o;
test_Case test_Overload_tc_numUint32_o;
test_Case test_Overload_tc_numUint64_o;
test_Case test_Overload_tc_numUint8_o;
test_Case test_Overload_tc_numWord_o;
test_Case test_Overload_tc_wildcard_o;
corto_struct test_Point_o;
corto_member test_Point_x_o;
corto_member test_Point_y_o;
corto_struct test_Point3D_o;
corto_member test_Point3D_z_o;
corto_struct test_PrimitiveCollection_o;
corto_member test_PrimitiveCollection_ints_o;
test_Suite test_Project_o;
corto_method test_Project_setup_o;
test_Case test_Project_tc_app_o;
test_Case test_Project_tc_appNoTest_o;
test_Case test_Project_tc_package_o;
test_Case test_Project_tc_packageLocal_o;
test_Case test_Project_tc_publishNotag_o;
corto_method test_Project_teardown_o;
test_Suite test_RelativeName_o;
corto_member test_RelativeName_child_o;
corto_member test_RelativeName_disjunct_o;
corto_member test_RelativeName_obj_o;
corto_method test_RelativeName_setup_o;
test_Case test_RelativeName_tc_fromChild_o;
test_Case test_RelativeName_tc_fromDisjunct_o;
test_Case test_RelativeName_tc_fromGrandchild_o;
test_Case test_RelativeName_tc_fromOneUp_o;
test_Case test_RelativeName_tc_fromParent_o;
test_Case test_RelativeName_tc_fromRoot_o;
test_Case test_RelativeName_tc_fromSelf_o;
test_Case test_RelativeName_tc_fromThreeUp_o;
test_Case test_RelativeName_tc_fromTwoUp_o;
test_Case test_RelativeName_tc_rootFromObj_o;
corto_method test_RelativeName_teardown_o;
corto_member test_RelativeName_tier1_o;
corto_member test_RelativeName_tier2_o;
corto_member test_RelativeName_tier3_o;
test_Suite test_Resolver_o;
corto_method test_Resolver_setup_o;
test_Case test_Resolver_tc_caseInsensitive_o;
test_Case test_Resolver_tc_resolveAll_o;
test_Case test_Resolver_tc_resolveAnonymous_o;
test_Case test_Resolver_tc_resolveCorto_o;
test_Case test_Resolver_tc_resolveEmptyString_o;
test_Case test_Resolver_tc_resolveFunctionArgs_o;
test_Case test_Resolver_tc_resolveFunctionNoArgs_o;
test_Case test_Resolver_tc_resolveIo_o;
test_Case test_Resolver_tc_resolveLang_o;
test_Case test_Resolver_tc_resolveNull_o;
test_Case test_Resolver_tc_resolveParenthesesNoFunction_o;
test_Case test_Resolver_tc_resolveParenthesesNoFunctionArgs_o;
test_Case test_Resolver_tc_resolveParenthesesNoFunctionArgsScoped_o;
test_Case test_Resolver_tc_resolveParenthesesNoFunctionMatchingArgs_o;
test_Case test_Resolver_tc_resolveParenthesesNoFunctionMatchingArgsScoped_o;
test_Case test_Resolver_tc_resolveParenthesesNoFunctionScoped_o;
test_Case test_Resolver_tc_resolveRoot_o;
test_Case test_Resolver_tc_resolveString_o;
test_Case test_Resolver_tc_resolveThis_o;
corto_method test_Resolver_teardown_o;
test_Suite test_Select_o;
corto_function test_Select_collect_o;
corto_function test_Select_hasObject_o;
corto_method test_Select_setup_o;
test_Case test_Select_tc_selectDeleteCurrent_o;
test_Case test_Select_tc_selectDeleteFirst_o;
test_Case test_Select_tc_selectDeleteNext_o;
test_Case test_Select_tc_selectDeleteParent_o;
test_Case test_Select_tc_selectDeletePrevious_o;
test_Case test_Select_tc_selectErrParentAst_o;
test_Case test_Select_tc_selectErrParentId_o;
test_Case test_Select_tc_selectErrParentTree_o;
test_Case test_Select_tc_selectErrParentWc_o;
test_Case test_Select_tc_selectErrScopeScope_o;
test_Case test_Select_tc_selectFilterAsterisk_o;
test_Case test_Select_tc_selectFilterWildcard_o;
test_Case test_Select_tc_selectIdentifier_o;
test_Case test_Select_tc_selectIdentifierCaps_o;
test_Case test_Select_tc_selectNumeric_o;
test_Case test_Select_tc_selectOrder_o;
test_Case test_Select_tc_selectParent_o;
test_Case test_Select_tc_selectScope_o;
test_Case test_Select_tc_selectScopedIdentifier_o;
test_Case test_Select_tc_selectScopedParent_o;
test_Case test_Select_tc_selectScopedThis_o;
test_Case test_Select_tc_selectScopeWithAsterisk_o;
test_Case test_Select_tc_selectScopeWithAsteriskFilter_o;
test_Case test_Select_tc_selectScopeWithWildcard_o;
test_Case test_Select_tc_selectScopeWithWildcardFilter_o;
test_Case test_Select_tc_selectThis_o;
test_Case test_Select_tc_selectTree_o;
test_Case test_Select_tc_selectTreeDeleteCurrent_o;
test_Case test_Select_tc_selectTreeDeleteFirst_o;
test_Case test_Select_tc_selectTreeDeleteGrandparent_o;
test_Case test_Select_tc_selectTreeDeleteNext_o;
test_Case test_Select_tc_selectTreeDeleteParent_o;
test_Case test_Select_tc_selectTreeDeletePrevious_o;
test_Case test_Select_tc_selectTreeWithAsterisk_o;
test_Case test_Select_tc_selectTreeWithAsteriskFilter_o;
test_Case test_Select_tc_selectTreeWithWildcard_o;
test_Case test_Select_tc_selectTreeWithWildcardFilter_o;
test_Case test_Select_tc_selectUnderscore_o;
corto_method test_Select_teardown_o;
corto_struct test_selectItem_o;
corto_member test_selectItem_name_o;
corto_member test_selectItem_parent_o;
corto_member test_selectItem_type_o;
test_Suite test_StringDeserializer_o;
corto_method test_StringDeserializer_setup_o;
test_Case test_StringDeserializer_tc_deserAnonymousMultiple_o;
test_Case test_StringDeserializer_tc_deserAnonymousNested_o;
test_Case test_StringDeserializer_tc_deserAnonymousReuse_o;
test_Case test_StringDeserializer_tc_deserAnonymousReuseNested_o;
test_Case test_StringDeserializer_tc_deserAnonymousSimple_o;
test_Case test_StringDeserializer_tc_deserBoolFalse_o;
test_Case test_StringDeserializer_tc_deserBoolInvalid_o;
test_Case test_StringDeserializer_tc_deserBoolTrue_o;
test_Case test_StringDeserializer_tc_deserChar_o;
test_Case test_StringDeserializer_tc_deserCharEscape_o;
test_Case test_StringDeserializer_tc_deserCharEscapeQuoted_o;
test_Case test_StringDeserializer_tc_deserCharNull_o;
test_Case test_StringDeserializer_tc_deserCharNullQuoted_o;
test_Case test_StringDeserializer_tc_deserCharQuoted_o;
test_Case test_StringDeserializer_tc_deserCollection_o;
test_Case test_StringDeserializer_tc_deserCollectionComplex_o;
test_Case test_StringDeserializer_tc_deserComposite_o;
test_Case test_StringDeserializer_tc_deserCompositeMembers_o;
test_Case test_StringDeserializer_tc_deserCompositeMixed_o;
test_Case test_StringDeserializer_tc_deserCompositeNested_o;
test_Case test_StringDeserializer_tc_deserCompositeNestedMembers_o;
test_Case test_StringDeserializer_tc_deserCompositeNestedMixed_o;
test_Case test_StringDeserializer_tc_deserCompositeNoType_o;
test_Case test_StringDeserializer_tc_deserCompositeWhitespace_o;
test_Case test_StringDeserializer_tc_deserExisting_o;
test_Case test_StringDeserializer_tc_deserExisting_w_scopedType_o;
test_Case test_StringDeserializer_tc_deserExisting_w_type_o;
test_Case test_StringDeserializer_tc_deserInheritance_o;
test_Case test_StringDeserializer_tc_deserInheritanceMembers_o;
test_Case test_StringDeserializer_tc_deserInheritanceMixed_o;
test_Case test_StringDeserializer_tc_deserInt16_o;
test_Case test_StringDeserializer_tc_deserInt16Minus_o;
test_Case test_StringDeserializer_tc_deserInt16Overflow_o;
test_Case test_StringDeserializer_tc_deserInt32_o;
test_Case test_StringDeserializer_tc_deserInt32Minus_o;
test_Case test_StringDeserializer_tc_deserInt32Overflow_o;
test_Case test_StringDeserializer_tc_deserInt64_o;
test_Case test_StringDeserializer_tc_deserInt64Minus_o;
test_Case test_StringDeserializer_tc_deserInt8_o;
test_Case test_StringDeserializer_tc_deserInt8Minus_o;
test_Case test_StringDeserializer_tc_deserInt8Overflow_o;
test_Case test_StringDeserializer_tc_deserString_o;
test_Case test_StringDeserializer_tc_deserStringEscape_o;
test_Case test_StringDeserializer_tc_deserStringQuotes_o;
test_Case test_StringDeserializer_tc_deserStringQuotesWhitespaces_o;
test_Case test_StringDeserializer_tc_deserStringWhitespace_o;
test_Case test_StringDeserializer_tc_deserStringWhitespaceTrailing_o;
test_Case test_StringDeserializer_tc_deserStringWhitespaceTrailingNoType_o;
test_Case test_StringDeserializer_tc_deserUint16_o;
test_Case test_StringDeserializer_tc_deserUint16Overflow_o;
test_Case test_StringDeserializer_tc_deserUint32_o;
test_Case test_StringDeserializer_tc_deserUint32Overflow_o;
test_Case test_StringDeserializer_tc_deserUint64_o;
test_Case test_StringDeserializer_tc_deserUint8_o;
test_Case test_StringDeserializer_tc_deserUint8Overflow_o;
test_Case test_StringDeserializer_tc_errExcessElements_o;
test_Case test_StringDeserializer_tc_errMissingType_o;
test_Case test_StringDeserializer_tc_errNotAType_o;
test_Case test_StringDeserializer_tc_errTypeMismatch_o;
test_Case test_StringDeserializer_tc_errUnresolvedMember_o;
test_Case test_StringDeserializer_tc_errUnresolvedType_o;
corto_method test_StringDeserializer_teardown_o;
corto_struct test_VoidParent_o;
corto_member test_VoidParent_Foo_o;

/* Load objects in object store. */
int test_load(void) {
    corto_object _a_; /* Used for resolving anonymous objects */
    _a_ = NULL;

    /* Declare /test */
    test_o = corto_declareChild(root_o, "test", corto_package_o);
    if (!test_o) {
        corto_error("test_load: failed to declare '/test' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test */
    if (!corto_checkState(test_o, CORTO_DEFINED)) {
        test_o->url = NULL;
        if (corto_define(test_o)) {
            corto_error("test_load: failed to define '/test' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Animal */
    test_Animal_o = corto_declareChild(test_o, "Animal", corto_class_o);
    if (!test_Animal_o) {
        corto_error("test_load: failed to declare '/test/Animal' (%s)", corto_lasterr());
        goto error;
    }

    /* Declare /test/Animal/a */
    test_Animal_a_o = corto_declareChild(test_Animal_o, "a", corto_member_o);
    if (!test_Animal_a_o) {
        corto_error("test_load: failed to declare '/test/Animal/a' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Animal/a */
    if (!corto_checkState(test_Animal_a_o, CORTO_DEFINED)) {
        test_Animal_a_o->type = corto_resolve(NULL, "/corto/lang/bool");
        test_Animal_a_o->modifiers = 0x0;
        test_Animal_a_o->state = 0x6;
        test_Animal_a_o->weak = FALSE;
        test_Animal_a_o->id = 0;
        if (corto_define(test_Animal_a_o)) {
            corto_error("test_load: failed to define '/test/Animal/a' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Define /test/Animal */
    if (!corto_checkState(test_Animal_o, CORTO_DEFINED)) {
        corto_type(test_Animal_o)->parentType = NULL;
        corto_type(test_Animal_o)->parentState = 0x6;
        corto_type(test_Animal_o)->defaultType = NULL;
        corto_type(test_Animal_o)->defaultProcedureType = NULL;
        corto_interface(test_Animal_o)->base = NULL;
        corto_struct(test_Animal_o)->baseAccess = 0x0;
        test_Animal_o->implements.length = 0;
        test_Animal_o->implements.buffer = NULL;
        if (corto_define(test_Animal_o)) {
            corto_error("test_load: failed to define '/test/Animal' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (corto_type(test_Animal_o)->size != sizeof(struct test_Animal_s)) {
        corto_error("test_load: calculated size '%d' of type '/test/Animal' doesn't match C-type size '%d'", corto_type(test_Animal_o)->size, sizeof(struct test_Animal_s));
    }

    /* Declare /test/ol_inherit(/test/Animal a) */
    test_ol_inherit__test_Animal_o = corto_declareChild(test_o, "ol_inherit(/test/Animal a)", corto_function_o);
    if (!test_ol_inherit__test_Animal_o) {
        corto_error("test_load: failed to declare '/test/ol_inherit(/test/Animal a)' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ol_inherit(/test/Animal a) */
    if (!corto_checkState(test_ol_inherit__test_Animal_o, CORTO_DEFINED)) {
        test_ol_inherit__test_Animal_o->returnType = corto_resolve(NULL, "/corto/lang/void");
        test_ol_inherit__test_Animal_o->returnsReference = FALSE;
        
        /* Bind /test/ol_inherit(/test/Animal a) with C-function */
        corto_function(test_ol_inherit__test_Animal_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ol_inherit__test_Animal(void *args, void *result);
        corto_function(test_ol_inherit__test_Animal_o)->impl = (corto_word)__test_ol_inherit__test_Animal;
        if (corto_define(test_ol_inherit__test_Animal_o)) {
            corto_error("test_load: failed to define '/test/ol_inherit(/test/Animal a)' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/AnonymousTest */
    test_AnonymousTest_o = corto_declareChild(test_o, "AnonymousTest", corto_class_o);
    if (!test_AnonymousTest_o) {
        corto_error("test_load: failed to declare '/test/AnonymousTest' (%s)", corto_lasterr());
        goto error;
    }

    /* Declare /test/AnonymousTest/objects */
    test_AnonymousTest_objects_o = corto_declareChild(test_AnonymousTest_o, "objects", corto_member_o);
    if (!test_AnonymousTest_objects_o) {
        corto_error("test_load: failed to declare '/test/AnonymousTest/objects' (%s)", corto_lasterr());
        goto error;
    }

    /* Declare /test/Args */
    test_Args_o = corto_declareChild(test_o, "Args", test_Suite_o);
    if (!test_Args_o) {
        corto_error("test_load: failed to declare '/test/Args' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Args */
    if (!corto_checkState(test_Args_o, CORTO_DEFINED)) {
        corto_type(test_Args_o)->parentType = NULL;
        corto_type(test_Args_o)->parentState = 0x6;
        corto_type(test_Args_o)->defaultType = NULL;
        corto_type(test_Args_o)->defaultProcedureType = NULL;
        corto_interface(test_Args_o)->base = corto_resolve(NULL, "/corto/test/SuiteData");
        corto_struct(test_Args_o)->baseAccess = 0x0;
        corto_class(test_Args_o)->implements.length = 0;
        corto_class(test_Args_o)->implements.buffer = NULL;
        if (corto_define(test_Args_o)) {
            corto_error("test_load: failed to define '/test/Args' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (corto_type(test_Args_o)->size != sizeof(struct test_Args_s)) {
        corto_error("test_load: calculated size '%d' of type '/test/Args' doesn't match C-type size '%d'", corto_type(test_Args_o)->size, sizeof(struct test_Args_s));
    }

    /* Declare /test/Args/tc_matchAddNoProject() */
    test_Args_tc_matchAddNoProject_o = corto_declareChild(test_Args_o, "tc_matchAddNoProject()", test_Case_o);
    if (!test_Args_tc_matchAddNoProject_o) {
        corto_error("test_load: failed to declare '/test/Args/tc_matchAddNoProject()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Args/tc_matchAddNoProject() */
    if (!corto_checkState(test_Args_tc_matchAddNoProject_o, CORTO_DEFINED)) {
        corto_function(test_Args_tc_matchAddNoProject_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Args_tc_matchAddNoProject_o)->returnsReference = FALSE;
        corto_method(test_Args_tc_matchAddNoProject_o)->_virtual = FALSE;
        
        /* Bind /test/Args/tc_matchAddNoProject() with C-function */
        corto_function(test_Args_tc_matchAddNoProject_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Args_tc_matchAddNoProject(void *args, void *result);
        corto_function(test_Args_tc_matchAddNoProject_o)->impl = (corto_word)__test_Args_tc_matchAddNoProject;
        if (corto_define(test_Args_tc_matchAddNoProject_o)) {
            corto_error("test_load: failed to define '/test/Args/tc_matchAddNoProject()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Args/tc_matchAll() */
    test_Args_tc_matchAll_o = corto_declareChild(test_Args_o, "tc_matchAll()", test_Case_o);
    if (!test_Args_tc_matchAll_o) {
        corto_error("test_load: failed to declare '/test/Args/tc_matchAll()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Args/tc_matchAll() */
    if (!corto_checkState(test_Args_tc_matchAll_o, CORTO_DEFINED)) {
        corto_function(test_Args_tc_matchAll_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Args_tc_matchAll_o)->returnsReference = FALSE;
        corto_method(test_Args_tc_matchAll_o)->_virtual = FALSE;
        
        /* Bind /test/Args/tc_matchAll() with C-function */
        corto_function(test_Args_tc_matchAll_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Args_tc_matchAll(void *args, void *result);
        corto_function(test_Args_tc_matchAll_o)->impl = (corto_word)__test_Args_tc_matchAll;
        if (corto_define(test_Args_tc_matchAll_o)) {
            corto_error("test_load: failed to define '/test/Args/tc_matchAll()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Args/tc_matchCreate() */
    test_Args_tc_matchCreate_o = corto_declareChild(test_Args_o, "tc_matchCreate()", test_Case_o);
    if (!test_Args_tc_matchCreate_o) {
        corto_error("test_load: failed to declare '/test/Args/tc_matchCreate()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Args/tc_matchCreate() */
    if (!corto_checkState(test_Args_tc_matchCreate_o, CORTO_DEFINED)) {
        corto_function(test_Args_tc_matchCreate_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Args_tc_matchCreate_o)->returnsReference = FALSE;
        corto_method(test_Args_tc_matchCreate_o)->_virtual = FALSE;
        
        /* Bind /test/Args/tc_matchCreate() with C-function */
        corto_function(test_Args_tc_matchCreate_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Args_tc_matchCreate(void *args, void *result);
        corto_function(test_Args_tc_matchCreate_o)->impl = (corto_word)__test_Args_tc_matchCreate;
        if (corto_define(test_Args_tc_matchCreate_o)) {
            corto_error("test_load: failed to define '/test/Args/tc_matchCreate()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Args/tc_matchCreateApp() */
    test_Args_tc_matchCreateApp_o = corto_declareChild(test_Args_o, "tc_matchCreateApp()", test_Case_o);
    if (!test_Args_tc_matchCreateApp_o) {
        corto_error("test_load: failed to declare '/test/Args/tc_matchCreateApp()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Args/tc_matchCreateApp() */
    if (!corto_checkState(test_Args_tc_matchCreateApp_o, CORTO_DEFINED)) {
        corto_function(test_Args_tc_matchCreateApp_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Args_tc_matchCreateApp_o)->returnsReference = FALSE;
        corto_method(test_Args_tc_matchCreateApp_o)->_virtual = FALSE;
        
        /* Bind /test/Args/tc_matchCreateApp() with C-function */
        corto_function(test_Args_tc_matchCreateApp_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Args_tc_matchCreateApp(void *args, void *result);
        corto_function(test_Args_tc_matchCreateApp_o)->impl = (corto_word)__test_Args_tc_matchCreateApp;
        if (corto_define(test_Args_tc_matchCreateApp_o)) {
            corto_error("test_load: failed to define '/test/Args/tc_matchCreateApp()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Args/tc_matchCreateMultiple() */
    test_Args_tc_matchCreateMultiple_o = corto_declareChild(test_Args_o, "tc_matchCreateMultiple()", test_Case_o);
    if (!test_Args_tc_matchCreateMultiple_o) {
        corto_error("test_load: failed to declare '/test/Args/tc_matchCreateMultiple()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Args/tc_matchCreateMultiple() */
    if (!corto_checkState(test_Args_tc_matchCreateMultiple_o, CORTO_DEFINED)) {
        corto_function(test_Args_tc_matchCreateMultiple_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Args_tc_matchCreateMultiple_o)->returnsReference = FALSE;
        corto_method(test_Args_tc_matchCreateMultiple_o)->_virtual = FALSE;
        
        /* Bind /test/Args/tc_matchCreateMultiple() with C-function */
        corto_function(test_Args_tc_matchCreateMultiple_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Args_tc_matchCreateMultiple(void *args, void *result);
        corto_function(test_Args_tc_matchCreateMultiple_o)->impl = (corto_word)__test_Args_tc_matchCreateMultiple;
        if (corto_define(test_Args_tc_matchCreateMultiple_o)) {
            corto_error("test_load: failed to define '/test/Args/tc_matchCreateMultiple()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Args/tc_matchCreatePackage() */
    test_Args_tc_matchCreatePackage_o = corto_declareChild(test_Args_o, "tc_matchCreatePackage()", test_Case_o);
    if (!test_Args_tc_matchCreatePackage_o) {
        corto_error("test_load: failed to declare '/test/Args/tc_matchCreatePackage()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Args/tc_matchCreatePackage() */
    if (!corto_checkState(test_Args_tc_matchCreatePackage_o, CORTO_DEFINED)) {
        corto_function(test_Args_tc_matchCreatePackage_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Args_tc_matchCreatePackage_o)->returnsReference = FALSE;
        corto_method(test_Args_tc_matchCreatePackage_o)->_virtual = FALSE;
        
        /* Bind /test/Args/tc_matchCreatePackage() with C-function */
        corto_function(test_Args_tc_matchCreatePackage_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Args_tc_matchCreatePackage(void *args, void *result);
        corto_function(test_Args_tc_matchCreatePackage_o)->impl = (corto_word)__test_Args_tc_matchCreatePackage;
        if (corto_define(test_Args_tc_matchCreatePackage_o)) {
            corto_error("test_load: failed to define '/test/Args/tc_matchCreatePackage()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Args/tc_matchCreatePackageAndApp() */
    test_Args_tc_matchCreatePackageAndApp_o = corto_declareChild(test_Args_o, "tc_matchCreatePackageAndApp()", test_Case_o);
    if (!test_Args_tc_matchCreatePackageAndApp_o) {
        corto_error("test_load: failed to declare '/test/Args/tc_matchCreatePackageAndApp()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Args/tc_matchCreatePackageAndApp() */
    if (!corto_checkState(test_Args_tc_matchCreatePackageAndApp_o, CORTO_DEFINED)) {
        corto_function(test_Args_tc_matchCreatePackageAndApp_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Args_tc_matchCreatePackageAndApp_o)->returnsReference = FALSE;
        corto_method(test_Args_tc_matchCreatePackageAndApp_o)->_virtual = FALSE;
        
        /* Bind /test/Args/tc_matchCreatePackageAndApp() with C-function */
        corto_function(test_Args_tc_matchCreatePackageAndApp_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Args_tc_matchCreatePackageAndApp(void *args, void *result);
        corto_function(test_Args_tc_matchCreatePackageAndApp_o)->impl = (corto_word)__test_Args_tc_matchCreatePackageAndApp;
        if (corto_define(test_Args_tc_matchCreatePackageAndApp_o)) {
            corto_error("test_load: failed to define '/test/Args/tc_matchCreatePackageAndApp()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Args/tc_matchCreatePackageAndAppEscaped() */
    test_Args_tc_matchCreatePackageAndAppEscaped_o = corto_declareChild(test_Args_o, "tc_matchCreatePackageAndAppEscaped()", test_Case_o);
    if (!test_Args_tc_matchCreatePackageAndAppEscaped_o) {
        corto_error("test_load: failed to declare '/test/Args/tc_matchCreatePackageAndAppEscaped()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Args/tc_matchCreatePackageAndAppEscaped() */
    if (!corto_checkState(test_Args_tc_matchCreatePackageAndAppEscaped_o, CORTO_DEFINED)) {
        corto_function(test_Args_tc_matchCreatePackageAndAppEscaped_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Args_tc_matchCreatePackageAndAppEscaped_o)->returnsReference = FALSE;
        corto_method(test_Args_tc_matchCreatePackageAndAppEscaped_o)->_virtual = FALSE;
        
        /* Bind /test/Args/tc_matchCreatePackageAndAppEscaped() with C-function */
        corto_function(test_Args_tc_matchCreatePackageAndAppEscaped_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Args_tc_matchCreatePackageAndAppEscaped(void *args, void *result);
        corto_function(test_Args_tc_matchCreatePackageAndAppEscaped_o)->impl = (corto_word)__test_Args_tc_matchCreatePackageAndAppEscaped;
        if (corto_define(test_Args_tc_matchCreatePackageAndAppEscaped_o)) {
            corto_error("test_load: failed to define '/test/Args/tc_matchCreatePackageAndAppEscaped()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Args/tc_matchCreatePackageOptions() */
    test_Args_tc_matchCreatePackageOptions_o = corto_declareChild(test_Args_o, "tc_matchCreatePackageOptions()", test_Case_o);
    if (!test_Args_tc_matchCreatePackageOptions_o) {
        corto_error("test_load: failed to declare '/test/Args/tc_matchCreatePackageOptions()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Args/tc_matchCreatePackageOptions() */
    if (!corto_checkState(test_Args_tc_matchCreatePackageOptions_o, CORTO_DEFINED)) {
        corto_function(test_Args_tc_matchCreatePackageOptions_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Args_tc_matchCreatePackageOptions_o)->returnsReference = FALSE;
        corto_method(test_Args_tc_matchCreatePackageOptions_o)->_virtual = FALSE;
        
        /* Bind /test/Args/tc_matchCreatePackageOptions() with C-function */
        corto_function(test_Args_tc_matchCreatePackageOptions_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Args_tc_matchCreatePackageOptions(void *args, void *result);
        corto_function(test_Args_tc_matchCreatePackageOptions_o)->impl = (corto_word)__test_Args_tc_matchCreatePackageOptions;
        if (corto_define(test_Args_tc_matchCreatePackageOptions_o)) {
            corto_error("test_load: failed to define '/test/Args/tc_matchCreatePackageOptions()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Args/tc_matchDuplicate() */
    test_Args_tc_matchDuplicate_o = corto_declareChild(test_Args_o, "tc_matchDuplicate()", test_Case_o);
    if (!test_Args_tc_matchDuplicate_o) {
        corto_error("test_load: failed to declare '/test/Args/tc_matchDuplicate()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Args/tc_matchDuplicate() */
    if (!corto_checkState(test_Args_tc_matchDuplicate_o, CORTO_DEFINED)) {
        corto_function(test_Args_tc_matchDuplicate_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Args_tc_matchDuplicate_o)->returnsReference = FALSE;
        corto_method(test_Args_tc_matchDuplicate_o)->_virtual = FALSE;
        
        /* Bind /test/Args/tc_matchDuplicate() with C-function */
        corto_function(test_Args_tc_matchDuplicate_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Args_tc_matchDuplicate(void *args, void *result);
        corto_function(test_Args_tc_matchDuplicate_o)->impl = (corto_word)__test_Args_tc_matchDuplicate;
        if (corto_define(test_Args_tc_matchDuplicate_o)) {
            corto_error("test_load: failed to define '/test/Args/tc_matchDuplicate()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Args/tc_matchDuplicateArg() */
    test_Args_tc_matchDuplicateArg_o = corto_declareChild(test_Args_o, "tc_matchDuplicateArg()", test_Case_o);
    if (!test_Args_tc_matchDuplicateArg_o) {
        corto_error("test_load: failed to declare '/test/Args/tc_matchDuplicateArg()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Args/tc_matchDuplicateArg() */
    if (!corto_checkState(test_Args_tc_matchDuplicateArg_o, CORTO_DEFINED)) {
        corto_function(test_Args_tc_matchDuplicateArg_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Args_tc_matchDuplicateArg_o)->returnsReference = FALSE;
        corto_method(test_Args_tc_matchDuplicateArg_o)->_virtual = FALSE;
        
        /* Bind /test/Args/tc_matchDuplicateArg() with C-function */
        corto_function(test_Args_tc_matchDuplicateArg_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Args_tc_matchDuplicateArg(void *args, void *result);
        corto_function(test_Args_tc_matchDuplicateArg_o)->impl = (corto_word)__test_Args_tc_matchDuplicateArg;
        if (corto_define(test_Args_tc_matchDuplicateArg_o)) {
            corto_error("test_load: failed to define '/test/Args/tc_matchDuplicateArg()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Args/tc_matchErr() */
    test_Args_tc_matchErr_o = corto_declareChild(test_Args_o, "tc_matchErr()", test_Case_o);
    if (!test_Args_tc_matchErr_o) {
        corto_error("test_load: failed to declare '/test/Args/tc_matchErr()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Args/tc_matchErr() */
    if (!corto_checkState(test_Args_tc_matchErr_o, CORTO_DEFINED)) {
        corto_function(test_Args_tc_matchErr_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Args_tc_matchErr_o)->returnsReference = FALSE;
        corto_method(test_Args_tc_matchErr_o)->_virtual = FALSE;
        
        /* Bind /test/Args/tc_matchErr() with C-function */
        corto_function(test_Args_tc_matchErr_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Args_tc_matchErr(void *args, void *result);
        corto_function(test_Args_tc_matchErr_o)->impl = (corto_word)__test_Args_tc_matchErr;
        if (corto_define(test_Args_tc_matchErr_o)) {
            corto_error("test_load: failed to define '/test/Args/tc_matchErr()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Args/tc_matchFixed() */
    test_Args_tc_matchFixed_o = corto_declareChild(test_Args_o, "tc_matchFixed()", test_Case_o);
    if (!test_Args_tc_matchFixed_o) {
        corto_error("test_load: failed to declare '/test/Args/tc_matchFixed()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Args/tc_matchFixed() */
    if (!corto_checkState(test_Args_tc_matchFixed_o, CORTO_DEFINED)) {
        corto_function(test_Args_tc_matchFixed_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Args_tc_matchFixed_o)->returnsReference = FALSE;
        corto_method(test_Args_tc_matchFixed_o)->_virtual = FALSE;
        
        /* Bind /test/Args/tc_matchFixed() with C-function */
        corto_function(test_Args_tc_matchFixed_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Args_tc_matchFixed(void *args, void *result);
        corto_function(test_Args_tc_matchFixed_o)->impl = (corto_word)__test_Args_tc_matchFixed;
        if (corto_define(test_Args_tc_matchFixed_o)) {
            corto_error("test_load: failed to define '/test/Args/tc_matchFixed()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Args/tc_matchMultiple() */
    test_Args_tc_matchMultiple_o = corto_declareChild(test_Args_o, "tc_matchMultiple()", test_Case_o);
    if (!test_Args_tc_matchMultiple_o) {
        corto_error("test_load: failed to declare '/test/Args/tc_matchMultiple()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Args/tc_matchMultiple() */
    if (!corto_checkState(test_Args_tc_matchMultiple_o, CORTO_DEFINED)) {
        corto_function(test_Args_tc_matchMultiple_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Args_tc_matchMultiple_o)->returnsReference = FALSE;
        corto_method(test_Args_tc_matchMultiple_o)->_virtual = FALSE;
        
        /* Bind /test/Args/tc_matchMultiple() with C-function */
        corto_function(test_Args_tc_matchMultiple_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Args_tc_matchMultiple(void *args, void *result);
        corto_function(test_Args_tc_matchMultiple_o)->impl = (corto_word)__test_Args_tc_matchMultiple;
        if (corto_define(test_Args_tc_matchMultiple_o)) {
            corto_error("test_load: failed to define '/test/Args/tc_matchMultiple()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Args/tc_matchMultipleArg() */
    test_Args_tc_matchMultipleArg_o = corto_declareChild(test_Args_o, "tc_matchMultipleArg()", test_Case_o);
    if (!test_Args_tc_matchMultipleArg_o) {
        corto_error("test_load: failed to declare '/test/Args/tc_matchMultipleArg()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Args/tc_matchMultipleArg() */
    if (!corto_checkState(test_Args_tc_matchMultipleArg_o, CORTO_DEFINED)) {
        corto_function(test_Args_tc_matchMultipleArg_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Args_tc_matchMultipleArg_o)->returnsReference = FALSE;
        corto_method(test_Args_tc_matchMultipleArg_o)->_virtual = FALSE;
        
        /* Bind /test/Args/tc_matchMultipleArg() with C-function */
        corto_function(test_Args_tc_matchMultipleArg_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Args_tc_matchMultipleArg(void *args, void *result);
        corto_function(test_Args_tc_matchMultipleArg_o)->impl = (corto_word)__test_Args_tc_matchMultipleArg;
        if (corto_define(test_Args_tc_matchMultipleArg_o)) {
            corto_error("test_load: failed to define '/test/Args/tc_matchMultipleArg()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Args/tc_matchNone() */
    test_Args_tc_matchNone_o = corto_declareChild(test_Args_o, "tc_matchNone()", test_Case_o);
    if (!test_Args_tc_matchNone_o) {
        corto_error("test_load: failed to declare '/test/Args/tc_matchNone()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Args/tc_matchNone() */
    if (!corto_checkState(test_Args_tc_matchNone_o, CORTO_DEFINED)) {
        corto_function(test_Args_tc_matchNone_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Args_tc_matchNone_o)->returnsReference = FALSE;
        corto_method(test_Args_tc_matchNone_o)->_virtual = FALSE;
        
        /* Bind /test/Args/tc_matchNone() with C-function */
        corto_function(test_Args_tc_matchNone_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Args_tc_matchNone(void *args, void *result);
        corto_function(test_Args_tc_matchNone_o)->impl = (corto_word)__test_Args_tc_matchNone;
        if (corto_define(test_Args_tc_matchNone_o)) {
            corto_error("test_load: failed to define '/test/Args/tc_matchNone()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Args/tc_matchOptional() */
    test_Args_tc_matchOptional_o = corto_declareChild(test_Args_o, "tc_matchOptional()", test_Case_o);
    if (!test_Args_tc_matchOptional_o) {
        corto_error("test_load: failed to declare '/test/Args/tc_matchOptional()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Args/tc_matchOptional() */
    if (!corto_checkState(test_Args_tc_matchOptional_o, CORTO_DEFINED)) {
        corto_function(test_Args_tc_matchOptional_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Args_tc_matchOptional_o)->returnsReference = FALSE;
        corto_method(test_Args_tc_matchOptional_o)->_virtual = FALSE;
        
        /* Bind /test/Args/tc_matchOptional() with C-function */
        corto_function(test_Args_tc_matchOptional_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Args_tc_matchOptional(void *args, void *result);
        corto_function(test_Args_tc_matchOptional_o)->impl = (corto_word)__test_Args_tc_matchOptional;
        if (corto_define(test_Args_tc_matchOptional_o)) {
            corto_error("test_load: failed to define '/test/Args/tc_matchOptional()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Args/tc_matchOptionalOneArg() */
    test_Args_tc_matchOptionalOneArg_o = corto_declareChild(test_Args_o, "tc_matchOptionalOneArg()", test_Case_o);
    if (!test_Args_tc_matchOptionalOneArg_o) {
        corto_error("test_load: failed to declare '/test/Args/tc_matchOptionalOneArg()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Args/tc_matchOptionalOneArg() */
    if (!corto_checkState(test_Args_tc_matchOptionalOneArg_o, CORTO_DEFINED)) {
        corto_function(test_Args_tc_matchOptionalOneArg_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Args_tc_matchOptionalOneArg_o)->returnsReference = FALSE;
        corto_method(test_Args_tc_matchOptionalOneArg_o)->_virtual = FALSE;
        
        /* Bind /test/Args/tc_matchOptionalOneArg() with C-function */
        corto_function(test_Args_tc_matchOptionalOneArg_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Args_tc_matchOptionalOneArg(void *args, void *result);
        corto_function(test_Args_tc_matchOptionalOneArg_o)->impl = (corto_word)__test_Args_tc_matchOptionalOneArg;
        if (corto_define(test_Args_tc_matchOptionalOneArg_o)) {
            corto_error("test_load: failed to define '/test/Args/tc_matchOptionalOneArg()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Args/tc_matchOptionalWithOtherArgs() */
    test_Args_tc_matchOptionalWithOtherArgs_o = corto_declareChild(test_Args_o, "tc_matchOptionalWithOtherArgs()", test_Case_o);
    if (!test_Args_tc_matchOptionalWithOtherArgs_o) {
        corto_error("test_load: failed to declare '/test/Args/tc_matchOptionalWithOtherArgs()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Args/tc_matchOptionalWithOtherArgs() */
    if (!corto_checkState(test_Args_tc_matchOptionalWithOtherArgs_o, CORTO_DEFINED)) {
        corto_function(test_Args_tc_matchOptionalWithOtherArgs_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Args_tc_matchOptionalWithOtherArgs_o)->returnsReference = FALSE;
        corto_method(test_Args_tc_matchOptionalWithOtherArgs_o)->_virtual = FALSE;
        
        /* Bind /test/Args/tc_matchOptionalWithOtherArgs() with C-function */
        corto_function(test_Args_tc_matchOptionalWithOtherArgs_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Args_tc_matchOptionalWithOtherArgs(void *args, void *result);
        corto_function(test_Args_tc_matchOptionalWithOtherArgs_o)->impl = (corto_word)__test_Args_tc_matchOptionalWithOtherArgs;
        if (corto_define(test_Args_tc_matchOptionalWithOtherArgs_o)) {
            corto_error("test_load: failed to define '/test/Args/tc_matchOptionalWithOtherArgs()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Args/tc_matchPattern() */
    test_Args_tc_matchPattern_o = corto_declareChild(test_Args_o, "tc_matchPattern()", test_Case_o);
    if (!test_Args_tc_matchPattern_o) {
        corto_error("test_load: failed to declare '/test/Args/tc_matchPattern()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Args/tc_matchPattern() */
    if (!corto_checkState(test_Args_tc_matchPattern_o, CORTO_DEFINED)) {
        corto_function(test_Args_tc_matchPattern_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Args_tc_matchPattern_o)->returnsReference = FALSE;
        corto_method(test_Args_tc_matchPattern_o)->_virtual = FALSE;
        
        /* Bind /test/Args/tc_matchPattern() with C-function */
        corto_function(test_Args_tc_matchPattern_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Args_tc_matchPattern(void *args, void *result);
        corto_function(test_Args_tc_matchPattern_o)->impl = (corto_word)__test_Args_tc_matchPattern;
        if (corto_define(test_Args_tc_matchPattern_o)) {
            corto_error("test_load: failed to define '/test/Args/tc_matchPattern()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Args/tc_matchPublish() */
    test_Args_tc_matchPublish_o = corto_declareChild(test_Args_o, "tc_matchPublish()", test_Case_o);
    if (!test_Args_tc_matchPublish_o) {
        corto_error("test_load: failed to declare '/test/Args/tc_matchPublish()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Args/tc_matchPublish() */
    if (!corto_checkState(test_Args_tc_matchPublish_o, CORTO_DEFINED)) {
        corto_function(test_Args_tc_matchPublish_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Args_tc_matchPublish_o)->returnsReference = FALSE;
        corto_method(test_Args_tc_matchPublish_o)->_virtual = FALSE;
        
        /* Bind /test/Args/tc_matchPublish() with C-function */
        corto_function(test_Args_tc_matchPublish_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Args_tc_matchPublish(void *args, void *result);
        corto_function(test_Args_tc_matchPublish_o)->impl = (corto_word)__test_Args_tc_matchPublish;
        if (corto_define(test_Args_tc_matchPublish_o)) {
            corto_error("test_load: failed to define '/test/Args/tc_matchPublish()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Args/tc_matchPublishNoProject() */
    test_Args_tc_matchPublishNoProject_o = corto_declareChild(test_Args_o, "tc_matchPublishNoProject()", test_Case_o);
    if (!test_Args_tc_matchPublishNoProject_o) {
        corto_error("test_load: failed to declare '/test/Args/tc_matchPublishNoProject()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Args/tc_matchPublishNoProject() */
    if (!corto_checkState(test_Args_tc_matchPublishNoProject_o, CORTO_DEFINED)) {
        corto_function(test_Args_tc_matchPublishNoProject_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Args_tc_matchPublishNoProject_o)->returnsReference = FALSE;
        corto_method(test_Args_tc_matchPublishNoProject_o)->_virtual = FALSE;
        
        /* Bind /test/Args/tc_matchPublishNoProject() with C-function */
        corto_function(test_Args_tc_matchPublishNoProject_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Args_tc_matchPublishNoProject(void *args, void *result);
        corto_function(test_Args_tc_matchPublishNoProject_o)->impl = (corto_word)__test_Args_tc_matchPublishNoProject;
        if (corto_define(test_Args_tc_matchPublishNoProject_o)) {
            corto_error("test_load: failed to define '/test/Args/tc_matchPublishNoProject()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Args/tc_matchShell() */
    test_Args_tc_matchShell_o = corto_declareChild(test_Args_o, "tc_matchShell()", test_Case_o);
    if (!test_Args_tc_matchShell_o) {
        corto_error("test_load: failed to declare '/test/Args/tc_matchShell()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Args/tc_matchShell() */
    if (!corto_checkState(test_Args_tc_matchShell_o, CORTO_DEFINED)) {
        corto_function(test_Args_tc_matchShell_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Args_tc_matchShell_o)->returnsReference = FALSE;
        corto_method(test_Args_tc_matchShell_o)->_virtual = FALSE;
        
        /* Bind /test/Args/tc_matchShell() with C-function */
        corto_function(test_Args_tc_matchShell_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Args_tc_matchShell(void *args, void *result);
        corto_function(test_Args_tc_matchShell_o)->impl = (corto_word)__test_Args_tc_matchShell;
        if (corto_define(test_Args_tc_matchShell_o)) {
            corto_error("test_load: failed to define '/test/Args/tc_matchShell()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Args/tc_matchSingle() */
    test_Args_tc_matchSingle_o = corto_declareChild(test_Args_o, "tc_matchSingle()", test_Case_o);
    if (!test_Args_tc_matchSingle_o) {
        corto_error("test_load: failed to declare '/test/Args/tc_matchSingle()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Args/tc_matchSingle() */
    if (!corto_checkState(test_Args_tc_matchSingle_o, CORTO_DEFINED)) {
        corto_function(test_Args_tc_matchSingle_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Args_tc_matchSingle_o)->returnsReference = FALSE;
        corto_method(test_Args_tc_matchSingle_o)->_virtual = FALSE;
        
        /* Bind /test/Args/tc_matchSingle() with C-function */
        corto_function(test_Args_tc_matchSingle_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Args_tc_matchSingle(void *args, void *result);
        corto_function(test_Args_tc_matchSingle_o)->impl = (corto_word)__test_Args_tc_matchSingle;
        if (corto_define(test_Args_tc_matchSingle_o)) {
            corto_error("test_load: failed to define '/test/Args/tc_matchSingle()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Args/tc_matchSingleArg() */
    test_Args_tc_matchSingleArg_o = corto_declareChild(test_Args_o, "tc_matchSingleArg()", test_Case_o);
    if (!test_Args_tc_matchSingleArg_o) {
        corto_error("test_load: failed to declare '/test/Args/tc_matchSingleArg()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Args/tc_matchSingleArg() */
    if (!corto_checkState(test_Args_tc_matchSingleArg_o, CORTO_DEFINED)) {
        corto_function(test_Args_tc_matchSingleArg_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Args_tc_matchSingleArg_o)->returnsReference = FALSE;
        corto_method(test_Args_tc_matchSingleArg_o)->_virtual = FALSE;
        
        /* Bind /test/Args/tc_matchSingleArg() with C-function */
        corto_function(test_Args_tc_matchSingleArg_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Args_tc_matchSingleArg(void *args, void *result);
        corto_function(test_Args_tc_matchSingleArg_o)->impl = (corto_word)__test_Args_tc_matchSingleArg;
        if (corto_define(test_Args_tc_matchSingleArg_o)) {
            corto_error("test_load: failed to define '/test/Args/tc_matchSingleArg()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Bar */
    test_Bar_o = corto_declareChild(test_o, "Bar", corto_class_o);
    if (!test_Bar_o) {
        corto_error("test_load: failed to declare '/test/Bar' (%s)", corto_lasterr());
        goto error;
    }

    /* Declare /test/Bar/__dummy */
    test_Bar___dummy_o = corto_declareChild(test_Bar_o, "__dummy", corto_member_o);
    if (!test_Bar___dummy_o) {
        corto_error("test_load: failed to declare '/test/Bar/__dummy' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Bar/__dummy */
    if (!corto_checkState(test_Bar___dummy_o, CORTO_DEFINED)) {
        test_Bar___dummy_o->type = corto_resolve(NULL, "/corto/lang/int8");
        test_Bar___dummy_o->modifiers = 0x3;
        test_Bar___dummy_o->state = 0x6;
        test_Bar___dummy_o->weak = FALSE;
        test_Bar___dummy_o->id = 0;
        if (corto_define(test_Bar___dummy_o)) {
            corto_error("test_load: failed to define '/test/Bar/__dummy' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Bar/init() */
    test_Bar_init_o = corto_declareChild(test_Bar_o, "init()", corto_method_o);
    if (!test_Bar_init_o) {
        corto_error("test_load: failed to declare '/test/Bar/init()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Bar/init() */
    if (!corto_checkState(test_Bar_init_o, CORTO_DEFINED)) {
        corto_function(test_Bar_init_o)->returnType = corto_resolve(NULL, "/corto/lang/int16");
        corto_function(test_Bar_init_o)->returnsReference = FALSE;
        test_Bar_init_o->_virtual = FALSE;
        
        /* Bind /test/Bar/init() with C-function */
        corto_function(test_Bar_init_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Bar_init(void *args, void *result);
        corto_function(test_Bar_init_o)->impl = (corto_word)__test_Bar_init;
        if (corto_define(test_Bar_init_o)) {
            corto_error("test_load: failed to define '/test/Bar/init()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Define /test/Bar */
    if (!corto_checkState(test_Bar_o, CORTO_DEFINED)) {
        corto_type(test_Bar_o)->parentType = NULL;
        corto_type(test_Bar_o)->parentState = 0x6;
        corto_type(test_Bar_o)->defaultType = NULL;
        corto_type(test_Bar_o)->defaultProcedureType = NULL;
        corto_interface(test_Bar_o)->base = NULL;
        corto_struct(test_Bar_o)->baseAccess = 0x0;
        test_Bar_o->implements.length = 0;
        test_Bar_o->implements.buffer = NULL;
        if (corto_define(test_Bar_o)) {
            corto_error("test_load: failed to define '/test/Bar' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (corto_type(test_Bar_o)->size != sizeof(struct test_Bar_s)) {
        corto_error("test_load: calculated size '%d' of type '/test/Bar' doesn't match C-type size '%d'", corto_type(test_Bar_o)->size, sizeof(struct test_Bar_s));
    }

    /* Declare /test/Cat */
    test_Cat_o = corto_declareChild(test_o, "Cat", corto_class_o);
    if (!test_Cat_o) {
        corto_error("test_load: failed to declare '/test/Cat' (%s)", corto_lasterr());
        goto error;
    }

    /* Declare /test/Cat/b */
    test_Cat_b_o = corto_declareChild(test_Cat_o, "b", corto_member_o);
    if (!test_Cat_b_o) {
        corto_error("test_load: failed to declare '/test/Cat/b' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Cat/b */
    if (!corto_checkState(test_Cat_b_o, CORTO_DEFINED)) {
        test_Cat_b_o->type = corto_resolve(NULL, "/corto/lang/bool");
        test_Cat_b_o->modifiers = 0x0;
        test_Cat_b_o->state = 0x6;
        test_Cat_b_o->weak = FALSE;
        test_Cat_b_o->id = 0;
        if (corto_define(test_Cat_b_o)) {
            corto_error("test_load: failed to define '/test/Cat/b' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Define /test/Cat */
    if (!corto_checkState(test_Cat_o, CORTO_DEFINED)) {
        corto_type(test_Cat_o)->parentType = NULL;
        corto_type(test_Cat_o)->parentState = 0x6;
        corto_type(test_Cat_o)->defaultType = NULL;
        corto_type(test_Cat_o)->defaultProcedureType = NULL;
        corto_interface(test_Cat_o)->base = corto_resolve(NULL, "/test/Animal");
        corto_struct(test_Cat_o)->baseAccess = 0x0;
        test_Cat_o->implements.length = 0;
        test_Cat_o->implements.buffer = NULL;
        if (corto_define(test_Cat_o)) {
            corto_error("test_load: failed to define '/test/Cat' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (corto_type(test_Cat_o)->size != sizeof(struct test_Cat_s)) {
        corto_error("test_load: calculated size '%d' of type '/test/Cat' doesn't match C-type size '%d'", corto_type(test_Cat_o)->size, sizeof(struct test_Cat_s));
    }

    /* Declare /test/Color */
    test_Color_o = corto_declareChild(test_o, "Color", corto_enum_o);
    if (!test_Color_o) {
        corto_error("test_load: failed to declare '/test/Color' (%s)", corto_lasterr());
        goto error;
    }

    /* Declare /test/Color/Blue */
    test_Color_Blue_o = corto_declareChild(test_Color_o, "Blue", corto_constant_o);
    if (!test_Color_Blue_o) {
        corto_error("test_load: failed to declare '/test/Color/Blue' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Color/Blue */
    if (!corto_checkState(test_Color_Blue_o, CORTO_DEFINED)) {
        (*test_Color_Blue_o) = 4;
        if (corto_define(test_Color_Blue_o)) {
            corto_error("test_load: failed to define '/test/Color/Blue' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Color/Green */
    test_Color_Green_o = corto_declareChild(test_Color_o, "Green", corto_constant_o);
    if (!test_Color_Green_o) {
        corto_error("test_load: failed to declare '/test/Color/Green' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Color/Green */
    if (!corto_checkState(test_Color_Green_o, CORTO_DEFINED)) {
        (*test_Color_Green_o) = 3;
        if (corto_define(test_Color_Green_o)) {
            corto_error("test_load: failed to define '/test/Color/Green' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Color/Orange */
    test_Color_Orange_o = corto_declareChild(test_Color_o, "Orange", corto_constant_o);
    if (!test_Color_Orange_o) {
        corto_error("test_load: failed to declare '/test/Color/Orange' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Color/Orange */
    if (!corto_checkState(test_Color_Orange_o, CORTO_DEFINED)) {
        (*test_Color_Orange_o) = 1;
        if (corto_define(test_Color_Orange_o)) {
            corto_error("test_load: failed to define '/test/Color/Orange' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Color/Red */
    test_Color_Red_o = corto_declareChild(test_Color_o, "Red", corto_constant_o);
    if (!test_Color_Red_o) {
        corto_error("test_load: failed to declare '/test/Color/Red' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Color/Red */
    if (!corto_checkState(test_Color_Red_o, CORTO_DEFINED)) {
        (*test_Color_Red_o) = 0;
        if (corto_define(test_Color_Red_o)) {
            corto_error("test_load: failed to define '/test/Color/Red' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Color/Yellow */
    test_Color_Yellow_o = corto_declareChild(test_Color_o, "Yellow", corto_constant_o);
    if (!test_Color_Yellow_o) {
        corto_error("test_load: failed to declare '/test/Color/Yellow' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Color/Yellow */
    if (!corto_checkState(test_Color_Yellow_o, CORTO_DEFINED)) {
        (*test_Color_Yellow_o) = 2;
        if (corto_define(test_Color_Yellow_o)) {
            corto_error("test_load: failed to define '/test/Color/Yellow' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Define /test/Color */
    if (!corto_checkState(test_Color_o, CORTO_DEFINED)) {
        if (corto_define(test_Color_o)) {
            corto_error("test_load: failed to define '/test/Color' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (corto_type(test_Color_o)->size != sizeof(test_Color)) {
        corto_error("test_load: calculated size '%d' of type '/test/Color' doesn't match C-type size '%d'", corto_type(test_Color_o)->size, sizeof(test_Color));
    }

    /* Declare /test/ol_any(/test/Color a) */
    test_ol_any__test_Color_o = corto_declareChild(test_o, "ol_any(/test/Color a)", corto_function_o);
    if (!test_ol_any__test_Color_o) {
        corto_error("test_load: failed to declare '/test/ol_any(/test/Color a)' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ol_any(/test/Color a) */
    if (!corto_checkState(test_ol_any__test_Color_o, CORTO_DEFINED)) {
        test_ol_any__test_Color_o->returnType = corto_resolve(NULL, "/corto/lang/void");
        test_ol_any__test_Color_o->returnsReference = FALSE;
        
        /* Bind /test/ol_any(/test/Color a) with C-function */
        corto_function(test_ol_any__test_Color_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ol_any__test_Color(void *args, void *result);
        corto_function(test_ol_any__test_Color_o)->impl = (corto_word)__test_ol_any__test_Color;
        if (corto_define(test_ol_any__test_Color_o)) {
            corto_error("test_load: failed to define '/test/ol_any(/test/Color a)' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/CompositeCollection */
    test_CompositeCollection_o = corto_declareChild(test_o, "CompositeCollection", corto_struct_o);
    if (!test_CompositeCollection_o) {
        corto_error("test_load: failed to declare '/test/CompositeCollection' (%s)", corto_lasterr());
        goto error;
    }

    /* Declare /test/CompositeCollection/points */
    test_CompositeCollection_points_o = corto_declareChild(test_CompositeCollection_o, "points", corto_member_o);
    if (!test_CompositeCollection_points_o) {
        corto_error("test_load: failed to declare '/test/CompositeCollection/points' (%s)", corto_lasterr());
        goto error;
    }

    /* Declare /test/constructCalled */
    test_constructCalled_o = corto_declareChild(test_o, "constructCalled", corto_int8_o);
    if (!test_constructCalled_o) {
        corto_error("test_load: failed to declare '/test/constructCalled' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/constructCalled */
    if (!corto_checkState(test_constructCalled_o, CORTO_DEFINED)) {
        (*test_constructCalled_o) = 0;
        if (corto_define(test_constructCalled_o)) {
            corto_error("test_load: failed to define '/test/constructCalled' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/DeclaredParent */
    test_DeclaredParent_o = corto_declareChild(test_o, "DeclaredParent", corto_struct_o);
    if (!test_DeclaredParent_o) {
        corto_error("test_load: failed to declare '/test/DeclaredParent' (%s)", corto_lasterr());
        goto error;
    }

    /* Declare /test/DeclaredParent/Foo */
    test_DeclaredParent_Foo_o = corto_declareChild(test_DeclaredParent_o, "Foo", corto_member_o);
    if (!test_DeclaredParent_Foo_o) {
        corto_error("test_load: failed to declare '/test/DeclaredParent/Foo' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/DeclaredParent/Foo */
    if (!corto_checkState(test_DeclaredParent_Foo_o, CORTO_DEFINED)) {
        test_DeclaredParent_Foo_o->type = corto_resolve(NULL, "/corto/lang/int32");
        test_DeclaredParent_Foo_o->modifiers = 0x0;
        test_DeclaredParent_Foo_o->state = 0x6;
        test_DeclaredParent_Foo_o->weak = FALSE;
        test_DeclaredParent_Foo_o->id = 0;
        if (corto_define(test_DeclaredParent_Foo_o)) {
            corto_error("test_load: failed to define '/test/DeclaredParent/Foo' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Define /test/DeclaredParent */
    if (!corto_checkState(test_DeclaredParent_o, CORTO_DEFINED)) {
        corto_type(test_DeclaredParent_o)->parentType = NULL;
        corto_type(test_DeclaredParent_o)->parentState = 0x2;
        corto_type(test_DeclaredParent_o)->defaultType = NULL;
        corto_type(test_DeclaredParent_o)->defaultProcedureType = NULL;
        corto_interface(test_DeclaredParent_o)->base = NULL;
        test_DeclaredParent_o->baseAccess = 0x0;
        if (corto_define(test_DeclaredParent_o)) {
            corto_error("test_load: failed to define '/test/DeclaredParent' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (corto_type(test_DeclaredParent_o)->size != sizeof(test_DeclaredParent)) {
        corto_error("test_load: calculated size '%d' of type '/test/DeclaredParent' doesn't match C-type size '%d'", corto_type(test_DeclaredParent_o)->size, sizeof(test_DeclaredParent));
    }

    /* Declare /test/DefinedParent */
    test_DefinedParent_o = corto_declareChild(test_o, "DefinedParent", corto_struct_o);
    if (!test_DefinedParent_o) {
        corto_error("test_load: failed to declare '/test/DefinedParent' (%s)", corto_lasterr());
        goto error;
    }

    /* Declare /test/DefinedParent/Foo */
    test_DefinedParent_Foo_o = corto_declareChild(test_DefinedParent_o, "Foo", corto_member_o);
    if (!test_DefinedParent_Foo_o) {
        corto_error("test_load: failed to declare '/test/DefinedParent/Foo' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/DefinedParent/Foo */
    if (!corto_checkState(test_DefinedParent_Foo_o, CORTO_DEFINED)) {
        test_DefinedParent_Foo_o->type = corto_resolve(NULL, "/corto/lang/int32");
        test_DefinedParent_Foo_o->modifiers = 0x0;
        test_DefinedParent_Foo_o->state = 0x6;
        test_DefinedParent_Foo_o->weak = FALSE;
        test_DefinedParent_Foo_o->id = 0;
        if (corto_define(test_DefinedParent_Foo_o)) {
            corto_error("test_load: failed to define '/test/DefinedParent/Foo' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Define /test/DefinedParent */
    if (!corto_checkState(test_DefinedParent_o, CORTO_DEFINED)) {
        corto_type(test_DefinedParent_o)->parentType = NULL;
        corto_type(test_DefinedParent_o)->parentState = 0x4;
        corto_type(test_DefinedParent_o)->defaultType = NULL;
        corto_type(test_DefinedParent_o)->defaultProcedureType = NULL;
        corto_interface(test_DefinedParent_o)->base = NULL;
        test_DefinedParent_o->baseAccess = 0x0;
        if (corto_define(test_DefinedParent_o)) {
            corto_error("test_load: failed to define '/test/DefinedParent' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (corto_type(test_DefinedParent_o)->size != sizeof(test_DefinedParent)) {
        corto_error("test_load: calculated size '%d' of type '/test/DefinedParent' doesn't match C-type size '%d'", corto_type(test_DefinedParent_o)->size, sizeof(test_DefinedParent));
    }

    /* Declare /test/destructCalled */
    test_destructCalled_o = corto_declareChild(test_o, "destructCalled", corto_int8_o);
    if (!test_destructCalled_o) {
        corto_error("test_load: failed to declare '/test/destructCalled' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/destructCalled */
    if (!corto_checkState(test_destructCalled_o, CORTO_DEFINED)) {
        (*test_destructCalled_o) = 0;
        if (corto_define(test_destructCalled_o)) {
            corto_error("test_load: failed to define '/test/destructCalled' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Dog */
    test_Dog_o = corto_declareChild(test_o, "Dog", corto_class_o);
    if (!test_Dog_o) {
        corto_error("test_load: failed to declare '/test/Dog' (%s)", corto_lasterr());
        goto error;
    }

    /* Declare /test/Dog/b */
    test_Dog_b_o = corto_declareChild(test_Dog_o, "b", corto_member_o);
    if (!test_Dog_b_o) {
        corto_error("test_load: failed to declare '/test/Dog/b' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Dog/b */
    if (!corto_checkState(test_Dog_b_o, CORTO_DEFINED)) {
        test_Dog_b_o->type = corto_resolve(NULL, "/corto/lang/bool");
        test_Dog_b_o->modifiers = 0x0;
        test_Dog_b_o->state = 0x6;
        test_Dog_b_o->weak = FALSE;
        test_Dog_b_o->id = 0;
        if (corto_define(test_Dog_b_o)) {
            corto_error("test_load: failed to define '/test/Dog/b' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Define /test/Dog */
    if (!corto_checkState(test_Dog_o, CORTO_DEFINED)) {
        corto_type(test_Dog_o)->parentType = NULL;
        corto_type(test_Dog_o)->parentState = 0x6;
        corto_type(test_Dog_o)->defaultType = NULL;
        corto_type(test_Dog_o)->defaultProcedureType = NULL;
        corto_interface(test_Dog_o)->base = corto_resolve(NULL, "/test/Animal");
        corto_struct(test_Dog_o)->baseAccess = 0x0;
        test_Dog_o->implements.length = 0;
        test_Dog_o->implements.buffer = NULL;
        if (corto_define(test_Dog_o)) {
            corto_error("test_load: failed to define '/test/Dog' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (corto_type(test_Dog_o)->size != sizeof(struct test_Dog_s)) {
        corto_error("test_load: calculated size '%d' of type '/test/Dog' doesn't match C-type size '%d'", corto_type(test_Dog_o)->size, sizeof(struct test_Dog_s));
    }

    /* Declare /test/ol_inherit(/test/Dog a) */
    test_ol_inherit__test_Dog_o = corto_declareChild(test_o, "ol_inherit(/test/Dog a)", corto_function_o);
    if (!test_ol_inherit__test_Dog_o) {
        corto_error("test_load: failed to declare '/test/ol_inherit(/test/Dog a)' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ol_inherit(/test/Dog a) */
    if (!corto_checkState(test_ol_inherit__test_Dog_o, CORTO_DEFINED)) {
        test_ol_inherit__test_Dog_o->returnType = corto_resolve(NULL, "/corto/lang/void");
        test_ol_inherit__test_Dog_o->returnsReference = FALSE;
        
        /* Bind /test/ol_inherit(/test/Dog a) with C-function */
        corto_function(test_ol_inherit__test_Dog_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ol_inherit__test_Dog(void *args, void *result);
        corto_function(test_ol_inherit__test_Dog_o)->impl = (corto_word)__test_ol_inherit__test_Dog;
        if (corto_define(test_ol_inherit__test_Dog_o)) {
            corto_error("test_load: failed to define '/test/ol_inherit(/test/Dog a)' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Env */
    test_Env_o = corto_declareChild(test_o, "Env", test_Suite_o);
    if (!test_Env_o) {
        corto_error("test_load: failed to declare '/test/Env' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Env */
    if (!corto_checkState(test_Env_o, CORTO_DEFINED)) {
        corto_type(test_Env_o)->parentType = NULL;
        corto_type(test_Env_o)->parentState = 0x6;
        corto_type(test_Env_o)->defaultType = NULL;
        corto_type(test_Env_o)->defaultProcedureType = NULL;
        corto_interface(test_Env_o)->base = corto_resolve(NULL, "/corto/test/SuiteData");
        corto_struct(test_Env_o)->baseAccess = 0x0;
        corto_class(test_Env_o)->implements.length = 0;
        corto_class(test_Env_o)->implements.buffer = NULL;
        if (corto_define(test_Env_o)) {
            corto_error("test_load: failed to define '/test/Env' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (corto_type(test_Env_o)->size != sizeof(struct test_Env_s)) {
        corto_error("test_load: calculated size '%d' of type '/test/Env' doesn't match C-type size '%d'", corto_type(test_Env_o)->size, sizeof(struct test_Env_s));
    }

    /* Declare /test/Env/tc_envparseFormatAndReplace() */
    test_Env_tc_envparseFormatAndReplace_o = corto_declareChild(test_Env_o, "tc_envparseFormatAndReplace()", test_Case_o);
    if (!test_Env_tc_envparseFormatAndReplace_o) {
        corto_error("test_load: failed to declare '/test/Env/tc_envparseFormatAndReplace()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Env/tc_envparseFormatAndReplace() */
    if (!corto_checkState(test_Env_tc_envparseFormatAndReplace_o, CORTO_DEFINED)) {
        corto_function(test_Env_tc_envparseFormatAndReplace_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Env_tc_envparseFormatAndReplace_o)->returnsReference = FALSE;
        corto_method(test_Env_tc_envparseFormatAndReplace_o)->_virtual = FALSE;
        
        /* Bind /test/Env/tc_envparseFormatAndReplace() with C-function */
        corto_function(test_Env_tc_envparseFormatAndReplace_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Env_tc_envparseFormatAndReplace(void *args, void *result);
        corto_function(test_Env_tc_envparseFormatAndReplace_o)->impl = (corto_word)__test_Env_tc_envparseFormatAndReplace;
        if (corto_define(test_Env_tc_envparseFormatAndReplace_o)) {
            corto_error("test_load: failed to define '/test/Env/tc_envparseFormatAndReplace()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Env/tc_envparseReplaceMultiple() */
    test_Env_tc_envparseReplaceMultiple_o = corto_declareChild(test_Env_o, "tc_envparseReplaceMultiple()", test_Case_o);
    if (!test_Env_tc_envparseReplaceMultiple_o) {
        corto_error("test_load: failed to declare '/test/Env/tc_envparseReplaceMultiple()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Env/tc_envparseReplaceMultiple() */
    if (!corto_checkState(test_Env_tc_envparseReplaceMultiple_o, CORTO_DEFINED)) {
        corto_function(test_Env_tc_envparseReplaceMultiple_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Env_tc_envparseReplaceMultiple_o)->returnsReference = FALSE;
        corto_method(test_Env_tc_envparseReplaceMultiple_o)->_virtual = FALSE;
        
        /* Bind /test/Env/tc_envparseReplaceMultiple() with C-function */
        corto_function(test_Env_tc_envparseReplaceMultiple_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Env_tc_envparseReplaceMultiple(void *args, void *result);
        corto_function(test_Env_tc_envparseReplaceMultiple_o)->impl = (corto_word)__test_Env_tc_envparseReplaceMultiple;
        if (corto_define(test_Env_tc_envparseReplaceMultiple_o)) {
            corto_error("test_load: failed to define '/test/Env/tc_envparseReplaceMultiple()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Env/tc_envparseReplaceWithSameVariable() */
    test_Env_tc_envparseReplaceWithSameVariable_o = corto_declareChild(test_Env_o, "tc_envparseReplaceWithSameVariable()", test_Case_o);
    if (!test_Env_tc_envparseReplaceWithSameVariable_o) {
        corto_error("test_load: failed to declare '/test/Env/tc_envparseReplaceWithSameVariable()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Env/tc_envparseReplaceWithSameVariable() */
    if (!corto_checkState(test_Env_tc_envparseReplaceWithSameVariable_o, CORTO_DEFINED)) {
        corto_function(test_Env_tc_envparseReplaceWithSameVariable_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Env_tc_envparseReplaceWithSameVariable_o)->returnsReference = FALSE;
        corto_method(test_Env_tc_envparseReplaceWithSameVariable_o)->_virtual = FALSE;
        
        /* Bind /test/Env/tc_envparseReplaceWithSameVariable() with C-function */
        corto_function(test_Env_tc_envparseReplaceWithSameVariable_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Env_tc_envparseReplaceWithSameVariable(void *args, void *result);
        corto_function(test_Env_tc_envparseReplaceWithSameVariable_o)->impl = (corto_word)__test_Env_tc_envparseReplaceWithSameVariable;
        if (corto_define(test_Env_tc_envparseReplaceWithSameVariable_o)) {
            corto_error("test_load: failed to define '/test/Env/tc_envparseReplaceWithSameVariable()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Env/tc_envparseSimpleFormat() */
    test_Env_tc_envparseSimpleFormat_o = corto_declareChild(test_Env_o, "tc_envparseSimpleFormat()", test_Case_o);
    if (!test_Env_tc_envparseSimpleFormat_o) {
        corto_error("test_load: failed to declare '/test/Env/tc_envparseSimpleFormat()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Env/tc_envparseSimpleFormat() */
    if (!corto_checkState(test_Env_tc_envparseSimpleFormat_o, CORTO_DEFINED)) {
        corto_function(test_Env_tc_envparseSimpleFormat_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Env_tc_envparseSimpleFormat_o)->returnsReference = FALSE;
        corto_method(test_Env_tc_envparseSimpleFormat_o)->_virtual = FALSE;
        
        /* Bind /test/Env/tc_envparseSimpleFormat() with C-function */
        corto_function(test_Env_tc_envparseSimpleFormat_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Env_tc_envparseSimpleFormat(void *args, void *result);
        corto_function(test_Env_tc_envparseSimpleFormat_o)->impl = (corto_word)__test_Env_tc_envparseSimpleFormat;
        if (corto_define(test_Env_tc_envparseSimpleFormat_o)) {
            corto_error("test_load: failed to define '/test/Env/tc_envparseSimpleFormat()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Env/tc_envparseSimpleReplace() */
    test_Env_tc_envparseSimpleReplace_o = corto_declareChild(test_Env_o, "tc_envparseSimpleReplace()", test_Case_o);
    if (!test_Env_tc_envparseSimpleReplace_o) {
        corto_error("test_load: failed to declare '/test/Env/tc_envparseSimpleReplace()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Env/tc_envparseSimpleReplace() */
    if (!corto_checkState(test_Env_tc_envparseSimpleReplace_o, CORTO_DEFINED)) {
        corto_function(test_Env_tc_envparseSimpleReplace_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Env_tc_envparseSimpleReplace_o)->returnsReference = FALSE;
        corto_method(test_Env_tc_envparseSimpleReplace_o)->_virtual = FALSE;
        
        /* Bind /test/Env/tc_envparseSimpleReplace() with C-function */
        corto_function(test_Env_tc_envparseSimpleReplace_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Env_tc_envparseSimpleReplace(void *args, void *result);
        corto_function(test_Env_tc_envparseSimpleReplace_o)->impl = (corto_word)__test_Env_tc_envparseSimpleReplace;
        if (corto_define(test_Env_tc_envparseSimpleReplace_o)) {
            corto_error("test_load: failed to define '/test/Env/tc_envparseSimpleReplace()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Env/tc_envparseVariableNotFound() */
    test_Env_tc_envparseVariableNotFound_o = corto_declareChild(test_Env_o, "tc_envparseVariableNotFound()", test_Case_o);
    if (!test_Env_tc_envparseVariableNotFound_o) {
        corto_error("test_load: failed to declare '/test/Env/tc_envparseVariableNotFound()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Env/tc_envparseVariableNotFound() */
    if (!corto_checkState(test_Env_tc_envparseVariableNotFound_o, CORTO_DEFINED)) {
        corto_function(test_Env_tc_envparseVariableNotFound_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Env_tc_envparseVariableNotFound_o)->returnsReference = FALSE;
        corto_method(test_Env_tc_envparseVariableNotFound_o)->_virtual = FALSE;
        
        /* Bind /test/Env/tc_envparseVariableNotFound() with C-function */
        corto_function(test_Env_tc_envparseVariableNotFound_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Env_tc_envparseVariableNotFound(void *args, void *result);
        corto_function(test_Env_tc_envparseVariableNotFound_o)->impl = (corto_word)__test_Env_tc_envparseVariableNotFound;
        if (corto_define(test_Env_tc_envparseVariableNotFound_o)) {
            corto_error("test_load: failed to define '/test/Env/tc_envparseVariableNotFound()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Env/tc_setenvFormatAndReplace() */
    test_Env_tc_setenvFormatAndReplace_o = corto_declareChild(test_Env_o, "tc_setenvFormatAndReplace()", test_Case_o);
    if (!test_Env_tc_setenvFormatAndReplace_o) {
        corto_error("test_load: failed to declare '/test/Env/tc_setenvFormatAndReplace()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Env/tc_setenvFormatAndReplace() */
    if (!corto_checkState(test_Env_tc_setenvFormatAndReplace_o, CORTO_DEFINED)) {
        corto_function(test_Env_tc_setenvFormatAndReplace_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Env_tc_setenvFormatAndReplace_o)->returnsReference = FALSE;
        corto_method(test_Env_tc_setenvFormatAndReplace_o)->_virtual = FALSE;
        
        /* Bind /test/Env/tc_setenvFormatAndReplace() with C-function */
        corto_function(test_Env_tc_setenvFormatAndReplace_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Env_tc_setenvFormatAndReplace(void *args, void *result);
        corto_function(test_Env_tc_setenvFormatAndReplace_o)->impl = (corto_word)__test_Env_tc_setenvFormatAndReplace;
        if (corto_define(test_Env_tc_setenvFormatAndReplace_o)) {
            corto_error("test_load: failed to define '/test/Env/tc_setenvFormatAndReplace()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Env/tc_setenvNull() */
    test_Env_tc_setenvNull_o = corto_declareChild(test_Env_o, "tc_setenvNull()", test_Case_o);
    if (!test_Env_tc_setenvNull_o) {
        corto_error("test_load: failed to declare '/test/Env/tc_setenvNull()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Env/tc_setenvNull() */
    if (!corto_checkState(test_Env_tc_setenvNull_o, CORTO_DEFINED)) {
        corto_function(test_Env_tc_setenvNull_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Env_tc_setenvNull_o)->returnsReference = FALSE;
        corto_method(test_Env_tc_setenvNull_o)->_virtual = FALSE;
        
        /* Bind /test/Env/tc_setenvNull() with C-function */
        corto_function(test_Env_tc_setenvNull_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Env_tc_setenvNull(void *args, void *result);
        corto_function(test_Env_tc_setenvNull_o)->impl = (corto_word)__test_Env_tc_setenvNull;
        if (corto_define(test_Env_tc_setenvNull_o)) {
            corto_error("test_load: failed to define '/test/Env/tc_setenvNull()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Env/tc_setenvReplaceMultiple() */
    test_Env_tc_setenvReplaceMultiple_o = corto_declareChild(test_Env_o, "tc_setenvReplaceMultiple()", test_Case_o);
    if (!test_Env_tc_setenvReplaceMultiple_o) {
        corto_error("test_load: failed to declare '/test/Env/tc_setenvReplaceMultiple()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Env/tc_setenvReplaceMultiple() */
    if (!corto_checkState(test_Env_tc_setenvReplaceMultiple_o, CORTO_DEFINED)) {
        corto_function(test_Env_tc_setenvReplaceMultiple_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Env_tc_setenvReplaceMultiple_o)->returnsReference = FALSE;
        corto_method(test_Env_tc_setenvReplaceMultiple_o)->_virtual = FALSE;
        
        /* Bind /test/Env/tc_setenvReplaceMultiple() with C-function */
        corto_function(test_Env_tc_setenvReplaceMultiple_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Env_tc_setenvReplaceMultiple(void *args, void *result);
        corto_function(test_Env_tc_setenvReplaceMultiple_o)->impl = (corto_word)__test_Env_tc_setenvReplaceMultiple;
        if (corto_define(test_Env_tc_setenvReplaceMultiple_o)) {
            corto_error("test_load: failed to define '/test/Env/tc_setenvReplaceMultiple()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Env/tc_setenvReplaceWithSameVariable() */
    test_Env_tc_setenvReplaceWithSameVariable_o = corto_declareChild(test_Env_o, "tc_setenvReplaceWithSameVariable()", test_Case_o);
    if (!test_Env_tc_setenvReplaceWithSameVariable_o) {
        corto_error("test_load: failed to declare '/test/Env/tc_setenvReplaceWithSameVariable()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Env/tc_setenvReplaceWithSameVariable() */
    if (!corto_checkState(test_Env_tc_setenvReplaceWithSameVariable_o, CORTO_DEFINED)) {
        corto_function(test_Env_tc_setenvReplaceWithSameVariable_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Env_tc_setenvReplaceWithSameVariable_o)->returnsReference = FALSE;
        corto_method(test_Env_tc_setenvReplaceWithSameVariable_o)->_virtual = FALSE;
        
        /* Bind /test/Env/tc_setenvReplaceWithSameVariable() with C-function */
        corto_function(test_Env_tc_setenvReplaceWithSameVariable_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Env_tc_setenvReplaceWithSameVariable(void *args, void *result);
        corto_function(test_Env_tc_setenvReplaceWithSameVariable_o)->impl = (corto_word)__test_Env_tc_setenvReplaceWithSameVariable;
        if (corto_define(test_Env_tc_setenvReplaceWithSameVariable_o)) {
            corto_error("test_load: failed to define '/test/Env/tc_setenvReplaceWithSameVariable()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Env/tc_setenvSimple() */
    test_Env_tc_setenvSimple_o = corto_declareChild(test_Env_o, "tc_setenvSimple()", test_Case_o);
    if (!test_Env_tc_setenvSimple_o) {
        corto_error("test_load: failed to declare '/test/Env/tc_setenvSimple()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Env/tc_setenvSimple() */
    if (!corto_checkState(test_Env_tc_setenvSimple_o, CORTO_DEFINED)) {
        corto_function(test_Env_tc_setenvSimple_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Env_tc_setenvSimple_o)->returnsReference = FALSE;
        corto_method(test_Env_tc_setenvSimple_o)->_virtual = FALSE;
        
        /* Bind /test/Env/tc_setenvSimple() with C-function */
        corto_function(test_Env_tc_setenvSimple_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Env_tc_setenvSimple(void *args, void *result);
        corto_function(test_Env_tc_setenvSimple_o)->impl = (corto_word)__test_Env_tc_setenvSimple;
        if (corto_define(test_Env_tc_setenvSimple_o)) {
            corto_error("test_load: failed to define '/test/Env/tc_setenvSimple()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Env/tc_setenvSimpleFormat() */
    test_Env_tc_setenvSimpleFormat_o = corto_declareChild(test_Env_o, "tc_setenvSimpleFormat()", test_Case_o);
    if (!test_Env_tc_setenvSimpleFormat_o) {
        corto_error("test_load: failed to declare '/test/Env/tc_setenvSimpleFormat()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Env/tc_setenvSimpleFormat() */
    if (!corto_checkState(test_Env_tc_setenvSimpleFormat_o, CORTO_DEFINED)) {
        corto_function(test_Env_tc_setenvSimpleFormat_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Env_tc_setenvSimpleFormat_o)->returnsReference = FALSE;
        corto_method(test_Env_tc_setenvSimpleFormat_o)->_virtual = FALSE;
        
        /* Bind /test/Env/tc_setenvSimpleFormat() with C-function */
        corto_function(test_Env_tc_setenvSimpleFormat_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Env_tc_setenvSimpleFormat(void *args, void *result);
        corto_function(test_Env_tc_setenvSimpleFormat_o)->impl = (corto_word)__test_Env_tc_setenvSimpleFormat;
        if (corto_define(test_Env_tc_setenvSimpleFormat_o)) {
            corto_error("test_load: failed to define '/test/Env/tc_setenvSimpleFormat()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Env/tc_setenvSimpleReplace() */
    test_Env_tc_setenvSimpleReplace_o = corto_declareChild(test_Env_o, "tc_setenvSimpleReplace()", test_Case_o);
    if (!test_Env_tc_setenvSimpleReplace_o) {
        corto_error("test_load: failed to declare '/test/Env/tc_setenvSimpleReplace()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Env/tc_setenvSimpleReplace() */
    if (!corto_checkState(test_Env_tc_setenvSimpleReplace_o, CORTO_DEFINED)) {
        corto_function(test_Env_tc_setenvSimpleReplace_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Env_tc_setenvSimpleReplace_o)->returnsReference = FALSE;
        corto_method(test_Env_tc_setenvSimpleReplace_o)->_virtual = FALSE;
        
        /* Bind /test/Env/tc_setenvSimpleReplace() with C-function */
        corto_function(test_Env_tc_setenvSimpleReplace_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Env_tc_setenvSimpleReplace(void *args, void *result);
        corto_function(test_Env_tc_setenvSimpleReplace_o)->impl = (corto_word)__test_Env_tc_setenvSimpleReplace;
        if (corto_define(test_Env_tc_setenvSimpleReplace_o)) {
            corto_error("test_load: failed to define '/test/Env/tc_setenvSimpleReplace()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Env/tc_setenvVariableNotFound() */
    test_Env_tc_setenvVariableNotFound_o = corto_declareChild(test_Env_o, "tc_setenvVariableNotFound()", test_Case_o);
    if (!test_Env_tc_setenvVariableNotFound_o) {
        corto_error("test_load: failed to declare '/test/Env/tc_setenvVariableNotFound()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Env/tc_setenvVariableNotFound() */
    if (!corto_checkState(test_Env_tc_setenvVariableNotFound_o, CORTO_DEFINED)) {
        corto_function(test_Env_tc_setenvVariableNotFound_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Env_tc_setenvVariableNotFound_o)->returnsReference = FALSE;
        corto_method(test_Env_tc_setenvVariableNotFound_o)->_virtual = FALSE;
        
        /* Bind /test/Env/tc_setenvVariableNotFound() with C-function */
        corto_function(test_Env_tc_setenvVariableNotFound_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Env_tc_setenvVariableNotFound(void *args, void *result);
        corto_function(test_Env_tc_setenvVariableNotFound_o)->impl = (corto_word)__test_Env_tc_setenvVariableNotFound;
        if (corto_define(test_Env_tc_setenvVariableNotFound_o)) {
            corto_error("test_load: failed to define '/test/Env/tc_setenvVariableNotFound()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Event */
    test_Event_o = corto_declareChild(test_o, "Event", test_Suite_o);
    if (!test_Event_o) {
        corto_error("test_load: failed to declare '/test/Event' (%s)", corto_lasterr());
        goto error;
    }

    /* Declare /test/Event/et */
    test_Event_et_o = corto_declareChild(test_Event_o, "et", corto_member_o);
    if (!test_Event_et_o) {
        corto_error("test_load: failed to declare '/test/Event/et' (%s)", corto_lasterr());
        goto error;
    }

    /* Declare /test/Event/prevAttr */
    test_Event_prevAttr_o = corto_declareChild(test_Event_o, "prevAttr", corto_member_o);
    if (!test_Event_prevAttr_o) {
        corto_error("test_load: failed to declare '/test/Event/prevAttr' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Event/prevAttr */
    if (!corto_checkState(test_Event_prevAttr_o, CORTO_DEFINED)) {
        test_Event_prevAttr_o->type = corto_resolve(NULL, "/corto/lang/attr");
        test_Event_prevAttr_o->modifiers = 0x0;
        test_Event_prevAttr_o->state = 0x6;
        test_Event_prevAttr_o->weak = FALSE;
        test_Event_prevAttr_o->id = 1;
        if (corto_define(test_Event_prevAttr_o)) {
            corto_error("test_load: failed to define '/test/Event/prevAttr' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Event/setup() */
    test_Event_setup_o = corto_declareChild(test_Event_o, "setup()", corto_method_o);
    if (!test_Event_setup_o) {
        corto_error("test_load: failed to declare '/test/Event/setup()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Event/setup() */
    if (!corto_checkState(test_Event_setup_o, CORTO_DEFINED)) {
        corto_function(test_Event_setup_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Event_setup_o)->returnsReference = FALSE;
        test_Event_setup_o->_virtual = FALSE;
        
        /* Bind /test/Event/setup() with C-function */
        corto_function(test_Event_setup_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Event_setup(void *args, void *result);
        corto_function(test_Event_setup_o)->impl = (corto_word)__test_Event_setup;
        if (corto_define(test_Event_setup_o)) {
            corto_error("test_load: failed to define '/test/Event/setup()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Event/teardown() */
    test_Event_teardown_o = corto_declareChild(test_Event_o, "teardown()", corto_method_o);
    if (!test_Event_teardown_o) {
        corto_error("test_load: failed to declare '/test/Event/teardown()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Event/teardown() */
    if (!corto_checkState(test_Event_teardown_o, CORTO_DEFINED)) {
        corto_function(test_Event_teardown_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Event_teardown_o)->returnsReference = FALSE;
        test_Event_teardown_o->_virtual = FALSE;
        
        /* Bind /test/Event/teardown() with C-function */
        corto_function(test_Event_teardown_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Event_teardown(void *args, void *result);
        corto_function(test_Event_teardown_o)->impl = (corto_word)__test_Event_teardown;
        if (corto_define(test_Event_teardown_o)) {
            corto_error("test_load: failed to define '/test/Event/teardown()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/EventTest */
    test_EventTest_o = corto_declareChild(test_o, "EventTest", corto_class_o);
    if (!test_EventTest_o) {
        corto_error("test_load: failed to declare '/test/EventTest' (%s)", corto_lasterr());
        goto error;
    }

    /* Declare /test/EventTest/construct() */
    test_EventTest_construct_o = corto_declareChild(test_EventTest_o, "construct()", corto_method_o);
    if (!test_EventTest_construct_o) {
        corto_error("test_load: failed to declare '/test/EventTest/construct()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/EventTest/construct() */
    if (!corto_checkState(test_EventTest_construct_o, CORTO_DEFINED)) {
        corto_function(test_EventTest_construct_o)->returnType = corto_resolve(NULL, "/corto/lang/int16");
        corto_function(test_EventTest_construct_o)->returnsReference = FALSE;
        test_EventTest_construct_o->_virtual = FALSE;
        
        /* Bind /test/EventTest/construct() with C-function */
        corto_function(test_EventTest_construct_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_EventTest_construct(void *args, void *result);
        corto_function(test_EventTest_construct_o)->impl = (corto_word)__test_EventTest_construct;
        if (corto_define(test_EventTest_construct_o)) {
            corto_error("test_load: failed to define '/test/EventTest/construct()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/EventTest/countDeclare */
    test_EventTest_countDeclare_o = corto_declareChild(test_EventTest_o, "countDeclare", corto_member_o);
    if (!test_EventTest_countDeclare_o) {
        corto_error("test_load: failed to declare '/test/EventTest/countDeclare' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/EventTest/countDeclare */
    if (!corto_checkState(test_EventTest_countDeclare_o, CORTO_DEFINED)) {
        test_EventTest_countDeclare_o->type = corto_resolve(NULL, "/corto/lang/uint32");
        test_EventTest_countDeclare_o->modifiers = 0x4;
        test_EventTest_countDeclare_o->state = 0x6;
        test_EventTest_countDeclare_o->weak = FALSE;
        test_EventTest_countDeclare_o->id = 3;
        if (corto_define(test_EventTest_countDeclare_o)) {
            corto_error("test_load: failed to define '/test/EventTest/countDeclare' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/EventTest/countDeclareScope */
    test_EventTest_countDeclareScope_o = corto_declareChild(test_EventTest_o, "countDeclareScope", corto_member_o);
    if (!test_EventTest_countDeclareScope_o) {
        corto_error("test_load: failed to declare '/test/EventTest/countDeclareScope' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/EventTest/countDeclareScope */
    if (!corto_checkState(test_EventTest_countDeclareScope_o, CORTO_DEFINED)) {
        test_EventTest_countDeclareScope_o->type = corto_resolve(NULL, "/corto/lang/uint32");
        test_EventTest_countDeclareScope_o->modifiers = 0x4;
        test_EventTest_countDeclareScope_o->state = 0x6;
        test_EventTest_countDeclareScope_o->weak = FALSE;
        test_EventTest_countDeclareScope_o->id = 5;
        if (corto_define(test_EventTest_countDeclareScope_o)) {
            corto_error("test_load: failed to define '/test/EventTest/countDeclareScope' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/EventTest/countDeclareSelf */
    test_EventTest_countDeclareSelf_o = corto_declareChild(test_EventTest_o, "countDeclareSelf", corto_member_o);
    if (!test_EventTest_countDeclareSelf_o) {
        corto_error("test_load: failed to declare '/test/EventTest/countDeclareSelf' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/EventTest/countDeclareSelf */
    if (!corto_checkState(test_EventTest_countDeclareSelf_o, CORTO_DEFINED)) {
        test_EventTest_countDeclareSelf_o->type = corto_resolve(NULL, "/corto/lang/uint32");
        test_EventTest_countDeclareSelf_o->modifiers = 0x4;
        test_EventTest_countDeclareSelf_o->state = 0x6;
        test_EventTest_countDeclareSelf_o->weak = FALSE;
        test_EventTest_countDeclareSelf_o->id = 4;
        if (corto_define(test_EventTest_countDeclareSelf_o)) {
            corto_error("test_load: failed to define '/test/EventTest/countDeclareSelf' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/EventTest/countDeclareTree */
    test_EventTest_countDeclareTree_o = corto_declareChild(test_EventTest_o, "countDeclareTree", corto_member_o);
    if (!test_EventTest_countDeclareTree_o) {
        corto_error("test_load: failed to declare '/test/EventTest/countDeclareTree' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/EventTest/countDeclareTree */
    if (!corto_checkState(test_EventTest_countDeclareTree_o, CORTO_DEFINED)) {
        test_EventTest_countDeclareTree_o->type = corto_resolve(NULL, "/corto/lang/uint32");
        test_EventTest_countDeclareTree_o->modifiers = 0x4;
        test_EventTest_countDeclareTree_o->state = 0x6;
        test_EventTest_countDeclareTree_o->weak = FALSE;
        test_EventTest_countDeclareTree_o->id = 6;
        if (corto_define(test_EventTest_countDeclareTree_o)) {
            corto_error("test_load: failed to define '/test/EventTest/countDeclareTree' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/EventTest/countDefine */
    test_EventTest_countDefine_o = corto_declareChild(test_EventTest_o, "countDefine", corto_member_o);
    if (!test_EventTest_countDefine_o) {
        corto_error("test_load: failed to declare '/test/EventTest/countDefine' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/EventTest/countDefine */
    if (!corto_checkState(test_EventTest_countDefine_o, CORTO_DEFINED)) {
        test_EventTest_countDefine_o->type = corto_resolve(NULL, "/corto/lang/uint32");
        test_EventTest_countDefine_o->modifiers = 0x4;
        test_EventTest_countDefine_o->state = 0x6;
        test_EventTest_countDefine_o->weak = FALSE;
        test_EventTest_countDefine_o->id = 7;
        if (corto_define(test_EventTest_countDefine_o)) {
            corto_error("test_load: failed to define '/test/EventTest/countDefine' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/EventTest/countDefineScope */
    test_EventTest_countDefineScope_o = corto_declareChild(test_EventTest_o, "countDefineScope", corto_member_o);
    if (!test_EventTest_countDefineScope_o) {
        corto_error("test_load: failed to declare '/test/EventTest/countDefineScope' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/EventTest/countDefineScope */
    if (!corto_checkState(test_EventTest_countDefineScope_o, CORTO_DEFINED)) {
        test_EventTest_countDefineScope_o->type = corto_resolve(NULL, "/corto/lang/uint32");
        test_EventTest_countDefineScope_o->modifiers = 0x4;
        test_EventTest_countDefineScope_o->state = 0x6;
        test_EventTest_countDefineScope_o->weak = FALSE;
        test_EventTest_countDefineScope_o->id = 9;
        if (corto_define(test_EventTest_countDefineScope_o)) {
            corto_error("test_load: failed to define '/test/EventTest/countDefineScope' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/EventTest/countDefineSelf */
    test_EventTest_countDefineSelf_o = corto_declareChild(test_EventTest_o, "countDefineSelf", corto_member_o);
    if (!test_EventTest_countDefineSelf_o) {
        corto_error("test_load: failed to declare '/test/EventTest/countDefineSelf' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/EventTest/countDefineSelf */
    if (!corto_checkState(test_EventTest_countDefineSelf_o, CORTO_DEFINED)) {
        test_EventTest_countDefineSelf_o->type = corto_resolve(NULL, "/corto/lang/uint32");
        test_EventTest_countDefineSelf_o->modifiers = 0x4;
        test_EventTest_countDefineSelf_o->state = 0x6;
        test_EventTest_countDefineSelf_o->weak = FALSE;
        test_EventTest_countDefineSelf_o->id = 8;
        if (corto_define(test_EventTest_countDefineSelf_o)) {
            corto_error("test_load: failed to define '/test/EventTest/countDefineSelf' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/EventTest/countDefineTree */
    test_EventTest_countDefineTree_o = corto_declareChild(test_EventTest_o, "countDefineTree", corto_member_o);
    if (!test_EventTest_countDefineTree_o) {
        corto_error("test_load: failed to declare '/test/EventTest/countDefineTree' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/EventTest/countDefineTree */
    if (!corto_checkState(test_EventTest_countDefineTree_o, CORTO_DEFINED)) {
        test_EventTest_countDefineTree_o->type = corto_resolve(NULL, "/corto/lang/uint32");
        test_EventTest_countDefineTree_o->modifiers = 0x4;
        test_EventTest_countDefineTree_o->state = 0x6;
        test_EventTest_countDefineTree_o->weak = FALSE;
        test_EventTest_countDefineTree_o->id = 10;
        if (corto_define(test_EventTest_countDefineTree_o)) {
            corto_error("test_load: failed to define '/test/EventTest/countDefineTree' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/EventTest/countDelete */
    test_EventTest_countDelete_o = corto_declareChild(test_EventTest_o, "countDelete", corto_member_o);
    if (!test_EventTest_countDelete_o) {
        corto_error("test_load: failed to declare '/test/EventTest/countDelete' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/EventTest/countDelete */
    if (!corto_checkState(test_EventTest_countDelete_o, CORTO_DEFINED)) {
        test_EventTest_countDelete_o->type = corto_resolve(NULL, "/corto/lang/uint32");
        test_EventTest_countDelete_o->modifiers = 0x4;
        test_EventTest_countDelete_o->state = 0x6;
        test_EventTest_countDelete_o->weak = FALSE;
        test_EventTest_countDelete_o->id = 15;
        if (corto_define(test_EventTest_countDelete_o)) {
            corto_error("test_load: failed to define '/test/EventTest/countDelete' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/EventTest/countDeleteScope */
    test_EventTest_countDeleteScope_o = corto_declareChild(test_EventTest_o, "countDeleteScope", corto_member_o);
    if (!test_EventTest_countDeleteScope_o) {
        corto_error("test_load: failed to declare '/test/EventTest/countDeleteScope' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/EventTest/countDeleteScope */
    if (!corto_checkState(test_EventTest_countDeleteScope_o, CORTO_DEFINED)) {
        test_EventTest_countDeleteScope_o->type = corto_resolve(NULL, "/corto/lang/uint32");
        test_EventTest_countDeleteScope_o->modifiers = 0x4;
        test_EventTest_countDeleteScope_o->state = 0x6;
        test_EventTest_countDeleteScope_o->weak = FALSE;
        test_EventTest_countDeleteScope_o->id = 17;
        if (corto_define(test_EventTest_countDeleteScope_o)) {
            corto_error("test_load: failed to define '/test/EventTest/countDeleteScope' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/EventTest/countDeleteSelf */
    test_EventTest_countDeleteSelf_o = corto_declareChild(test_EventTest_o, "countDeleteSelf", corto_member_o);
    if (!test_EventTest_countDeleteSelf_o) {
        corto_error("test_load: failed to declare '/test/EventTest/countDeleteSelf' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/EventTest/countDeleteSelf */
    if (!corto_checkState(test_EventTest_countDeleteSelf_o, CORTO_DEFINED)) {
        test_EventTest_countDeleteSelf_o->type = corto_resolve(NULL, "/corto/lang/uint32");
        test_EventTest_countDeleteSelf_o->modifiers = 0x4;
        test_EventTest_countDeleteSelf_o->state = 0x6;
        test_EventTest_countDeleteSelf_o->weak = FALSE;
        test_EventTest_countDeleteSelf_o->id = 16;
        if (corto_define(test_EventTest_countDeleteSelf_o)) {
            corto_error("test_load: failed to define '/test/EventTest/countDeleteSelf' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/EventTest/countDeleteTree */
    test_EventTest_countDeleteTree_o = corto_declareChild(test_EventTest_o, "countDeleteTree", corto_member_o);
    if (!test_EventTest_countDeleteTree_o) {
        corto_error("test_load: failed to declare '/test/EventTest/countDeleteTree' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/EventTest/countDeleteTree */
    if (!corto_checkState(test_EventTest_countDeleteTree_o, CORTO_DEFINED)) {
        test_EventTest_countDeleteTree_o->type = corto_resolve(NULL, "/corto/lang/uint32");
        test_EventTest_countDeleteTree_o->modifiers = 0x4;
        test_EventTest_countDeleteTree_o->state = 0x6;
        test_EventTest_countDeleteTree_o->weak = FALSE;
        test_EventTest_countDeleteTree_o->id = 18;
        if (corto_define(test_EventTest_countDeleteTree_o)) {
            corto_error("test_load: failed to define '/test/EventTest/countDeleteTree' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/EventTest/countUpdate */
    test_EventTest_countUpdate_o = corto_declareChild(test_EventTest_o, "countUpdate", corto_member_o);
    if (!test_EventTest_countUpdate_o) {
        corto_error("test_load: failed to declare '/test/EventTest/countUpdate' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/EventTest/countUpdate */
    if (!corto_checkState(test_EventTest_countUpdate_o, CORTO_DEFINED)) {
        test_EventTest_countUpdate_o->type = corto_resolve(NULL, "/corto/lang/uint32");
        test_EventTest_countUpdate_o->modifiers = 0x4;
        test_EventTest_countUpdate_o->state = 0x6;
        test_EventTest_countUpdate_o->weak = FALSE;
        test_EventTest_countUpdate_o->id = 11;
        if (corto_define(test_EventTest_countUpdate_o)) {
            corto_error("test_load: failed to define '/test/EventTest/countUpdate' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/EventTest/countUpdateScope */
    test_EventTest_countUpdateScope_o = corto_declareChild(test_EventTest_o, "countUpdateScope", corto_member_o);
    if (!test_EventTest_countUpdateScope_o) {
        corto_error("test_load: failed to declare '/test/EventTest/countUpdateScope' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/EventTest/countUpdateScope */
    if (!corto_checkState(test_EventTest_countUpdateScope_o, CORTO_DEFINED)) {
        test_EventTest_countUpdateScope_o->type = corto_resolve(NULL, "/corto/lang/uint32");
        test_EventTest_countUpdateScope_o->modifiers = 0x4;
        test_EventTest_countUpdateScope_o->state = 0x6;
        test_EventTest_countUpdateScope_o->weak = FALSE;
        test_EventTest_countUpdateScope_o->id = 13;
        if (corto_define(test_EventTest_countUpdateScope_o)) {
            corto_error("test_load: failed to define '/test/EventTest/countUpdateScope' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/EventTest/countUpdateSelf */
    test_EventTest_countUpdateSelf_o = corto_declareChild(test_EventTest_o, "countUpdateSelf", corto_member_o);
    if (!test_EventTest_countUpdateSelf_o) {
        corto_error("test_load: failed to declare '/test/EventTest/countUpdateSelf' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/EventTest/countUpdateSelf */
    if (!corto_checkState(test_EventTest_countUpdateSelf_o, CORTO_DEFINED)) {
        test_EventTest_countUpdateSelf_o->type = corto_resolve(NULL, "/corto/lang/uint32");
        test_EventTest_countUpdateSelf_o->modifiers = 0x4;
        test_EventTest_countUpdateSelf_o->state = 0x6;
        test_EventTest_countUpdateSelf_o->weak = FALSE;
        test_EventTest_countUpdateSelf_o->id = 12;
        if (corto_define(test_EventTest_countUpdateSelf_o)) {
            corto_error("test_load: failed to define '/test/EventTest/countUpdateSelf' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/EventTest/countUpdateTree */
    test_EventTest_countUpdateTree_o = corto_declareChild(test_EventTest_o, "countUpdateTree", corto_member_o);
    if (!test_EventTest_countUpdateTree_o) {
        corto_error("test_load: failed to declare '/test/EventTest/countUpdateTree' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/EventTest/countUpdateTree */
    if (!corto_checkState(test_EventTest_countUpdateTree_o, CORTO_DEFINED)) {
        test_EventTest_countUpdateTree_o->type = corto_resolve(NULL, "/corto/lang/uint32");
        test_EventTest_countUpdateTree_o->modifiers = 0x4;
        test_EventTest_countUpdateTree_o->state = 0x6;
        test_EventTest_countUpdateTree_o->weak = FALSE;
        test_EventTest_countUpdateTree_o->id = 14;
        if (corto_define(test_EventTest_countUpdateTree_o)) {
            corto_error("test_load: failed to define '/test/EventTest/countUpdateTree' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/EventTest/lastObservable */
    test_EventTest_lastObservable_o = corto_declareChild(test_EventTest_o, "lastObservable", corto_member_o);
    if (!test_EventTest_lastObservable_o) {
        corto_error("test_load: failed to declare '/test/EventTest/lastObservable' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/EventTest/lastObservable */
    if (!corto_checkState(test_EventTest_lastObservable_o, CORTO_DEFINED)) {
        test_EventTest_lastObservable_o->type = corto_resolve(NULL, "/corto/lang/object");
        test_EventTest_lastObservable_o->modifiers = 0x4;
        test_EventTest_lastObservable_o->state = 0x6;
        test_EventTest_lastObservable_o->weak = FALSE;
        test_EventTest_lastObservable_o->id = 2;
        if (corto_define(test_EventTest_lastObservable_o)) {
            corto_error("test_load: failed to define '/test/EventTest/lastObservable' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/EventTest/lastThis */
    test_EventTest_lastThis_o = corto_declareChild(test_EventTest_o, "lastThis", corto_member_o);
    if (!test_EventTest_lastThis_o) {
        corto_error("test_load: failed to declare '/test/EventTest/lastThis' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/EventTest/lastThis */
    if (!corto_checkState(test_EventTest_lastThis_o, CORTO_DEFINED)) {
        test_EventTest_lastThis_o->type = corto_resolve(NULL, "/corto/lang/object");
        test_EventTest_lastThis_o->modifiers = 0x4;
        test_EventTest_lastThis_o->state = 0x6;
        test_EventTest_lastThis_o->weak = FALSE;
        test_EventTest_lastThis_o->id = 1;
        if (corto_define(test_EventTest_lastThis_o)) {
            corto_error("test_load: failed to define '/test/EventTest/lastThis' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/EventTest/scope */
    test_EventTest_scope_o = corto_declareChild(test_EventTest_o, "scope", corto_member_o);
    if (!test_EventTest_scope_o) {
        corto_error("test_load: failed to declare '/test/EventTest/scope' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/EventTest/scope */
    if (!corto_checkState(test_EventTest_scope_o, CORTO_DEFINED)) {
        test_EventTest_scope_o->type = corto_resolve(NULL, "/corto/lang/object");
        test_EventTest_scope_o->modifiers = 0x0;
        test_EventTest_scope_o->state = 0x6;
        test_EventTest_scope_o->weak = FALSE;
        test_EventTest_scope_o->id = 0;
        if (corto_define(test_EventTest_scope_o)) {
            corto_error("test_load: failed to define '/test/EventTest/scope' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Define /test/EventTest */
    if (!corto_checkState(test_EventTest_o, CORTO_DEFINED)) {
        corto_type(test_EventTest_o)->parentType = NULL;
        corto_type(test_EventTest_o)->parentState = 0x6;
        corto_type(test_EventTest_o)->defaultType = NULL;
        corto_type(test_EventTest_o)->defaultProcedureType = NULL;
        corto_interface(test_EventTest_o)->base = NULL;
        corto_struct(test_EventTest_o)->baseAccess = 0x0;
        test_EventTest_o->implements.length = 0;
        test_EventTest_o->implements.buffer = NULL;
        if (corto_define(test_EventTest_o)) {
            corto_error("test_load: failed to define '/test/EventTest' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (corto_type(test_EventTest_o)->size != sizeof(struct test_EventTest_s)) {
        corto_error("test_load: calculated size '%d' of type '/test/EventTest' doesn't match C-type size '%d'", corto_type(test_EventTest_o)->size, sizeof(struct test_EventTest_s));
    }

    /* Define /test/Event/et */
    if (!corto_checkState(test_Event_et_o, CORTO_DEFINED)) {
        test_Event_et_o->type = corto_resolve(NULL, "/test/EventTest");
        test_Event_et_o->modifiers = 0x0;
        test_Event_et_o->state = 0x6;
        test_Event_et_o->weak = FALSE;
        test_Event_et_o->id = 0;
        if (corto_define(test_Event_et_o)) {
            corto_error("test_load: failed to define '/test/Event/et' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Define /test/Event */
    if (!corto_checkState(test_Event_o, CORTO_DEFINED)) {
        corto_type(test_Event_o)->parentType = NULL;
        corto_type(test_Event_o)->parentState = 0x6;
        corto_type(test_Event_o)->defaultType = NULL;
        corto_type(test_Event_o)->defaultProcedureType = NULL;
        corto_interface(test_Event_o)->base = corto_resolve(NULL, "/corto/test/SuiteData");
        corto_struct(test_Event_o)->baseAccess = 0x0;
        corto_class(test_Event_o)->implements.length = 0;
        corto_class(test_Event_o)->implements.buffer = NULL;
        if (corto_define(test_Event_o)) {
            corto_error("test_load: failed to define '/test/Event' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (corto_type(test_Event_o)->size != sizeof(struct test_Event_s)) {
        corto_error("test_load: calculated size '%d' of type '/test/Event' doesn't match C-type size '%d'", corto_type(test_Event_o)->size, sizeof(struct test_Event_s));
    }

    /* Declare /test/Event/tc_onDeclare() */
    test_Event_tc_onDeclare_o = corto_declareChild(test_Event_o, "tc_onDeclare()", test_Case_o);
    if (!test_Event_tc_onDeclare_o) {
        corto_error("test_load: failed to declare '/test/Event/tc_onDeclare()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Event/tc_onDeclare() */
    if (!corto_checkState(test_Event_tc_onDeclare_o, CORTO_DEFINED)) {
        corto_function(test_Event_tc_onDeclare_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Event_tc_onDeclare_o)->returnsReference = FALSE;
        corto_method(test_Event_tc_onDeclare_o)->_virtual = FALSE;
        
        /* Bind /test/Event/tc_onDeclare() with C-function */
        corto_function(test_Event_tc_onDeclare_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Event_tc_onDeclare(void *args, void *result);
        corto_function(test_Event_tc_onDeclare_o)->impl = (corto_word)__test_Event_tc_onDeclare;
        if (corto_define(test_Event_tc_onDeclare_o)) {
            corto_error("test_load: failed to define '/test/Event/tc_onDeclare()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Event/tc_onDeclareScope() */
    test_Event_tc_onDeclareScope_o = corto_declareChild(test_Event_o, "tc_onDeclareScope()", test_Case_o);
    if (!test_Event_tc_onDeclareScope_o) {
        corto_error("test_load: failed to declare '/test/Event/tc_onDeclareScope()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Event/tc_onDeclareScope() */
    if (!corto_checkState(test_Event_tc_onDeclareScope_o, CORTO_DEFINED)) {
        corto_function(test_Event_tc_onDeclareScope_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Event_tc_onDeclareScope_o)->returnsReference = FALSE;
        corto_method(test_Event_tc_onDeclareScope_o)->_virtual = FALSE;
        
        /* Bind /test/Event/tc_onDeclareScope() with C-function */
        corto_function(test_Event_tc_onDeclareScope_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Event_tc_onDeclareScope(void *args, void *result);
        corto_function(test_Event_tc_onDeclareScope_o)->impl = (corto_word)__test_Event_tc_onDeclareScope;
        if (corto_define(test_Event_tc_onDeclareScope_o)) {
            corto_error("test_load: failed to define '/test/Event/tc_onDeclareScope()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Event/tc_onDeclareSelf() */
    test_Event_tc_onDeclareSelf_o = corto_declareChild(test_Event_o, "tc_onDeclareSelf()", test_Case_o);
    if (!test_Event_tc_onDeclareSelf_o) {
        corto_error("test_load: failed to declare '/test/Event/tc_onDeclareSelf()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Event/tc_onDeclareSelf() */
    if (!corto_checkState(test_Event_tc_onDeclareSelf_o, CORTO_DEFINED)) {
        corto_function(test_Event_tc_onDeclareSelf_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Event_tc_onDeclareSelf_o)->returnsReference = FALSE;
        corto_method(test_Event_tc_onDeclareSelf_o)->_virtual = FALSE;
        
        /* Bind /test/Event/tc_onDeclareSelf() with C-function */
        corto_function(test_Event_tc_onDeclareSelf_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Event_tc_onDeclareSelf(void *args, void *result);
        corto_function(test_Event_tc_onDeclareSelf_o)->impl = (corto_word)__test_Event_tc_onDeclareSelf;
        if (corto_define(test_Event_tc_onDeclareSelf_o)) {
            corto_error("test_load: failed to define '/test/Event/tc_onDeclareSelf()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Event/tc_onDeclareTree() */
    test_Event_tc_onDeclareTree_o = corto_declareChild(test_Event_o, "tc_onDeclareTree()", test_Case_o);
    if (!test_Event_tc_onDeclareTree_o) {
        corto_error("test_load: failed to declare '/test/Event/tc_onDeclareTree()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Event/tc_onDeclareTree() */
    if (!corto_checkState(test_Event_tc_onDeclareTree_o, CORTO_DEFINED)) {
        corto_function(test_Event_tc_onDeclareTree_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Event_tc_onDeclareTree_o)->returnsReference = FALSE;
        corto_method(test_Event_tc_onDeclareTree_o)->_virtual = FALSE;
        
        /* Bind /test/Event/tc_onDeclareTree() with C-function */
        corto_function(test_Event_tc_onDeclareTree_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Event_tc_onDeclareTree(void *args, void *result);
        corto_function(test_Event_tc_onDeclareTree_o)->impl = (corto_word)__test_Event_tc_onDeclareTree;
        if (corto_define(test_Event_tc_onDeclareTree_o)) {
            corto_error("test_load: failed to define '/test/Event/tc_onDeclareTree()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Event/tc_onDefine() */
    test_Event_tc_onDefine_o = corto_declareChild(test_Event_o, "tc_onDefine()", test_Case_o);
    if (!test_Event_tc_onDefine_o) {
        corto_error("test_load: failed to declare '/test/Event/tc_onDefine()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Event/tc_onDefine() */
    if (!corto_checkState(test_Event_tc_onDefine_o, CORTO_DEFINED)) {
        corto_function(test_Event_tc_onDefine_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Event_tc_onDefine_o)->returnsReference = FALSE;
        corto_method(test_Event_tc_onDefine_o)->_virtual = FALSE;
        
        /* Bind /test/Event/tc_onDefine() with C-function */
        corto_function(test_Event_tc_onDefine_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Event_tc_onDefine(void *args, void *result);
        corto_function(test_Event_tc_onDefine_o)->impl = (corto_word)__test_Event_tc_onDefine;
        if (corto_define(test_Event_tc_onDefine_o)) {
            corto_error("test_load: failed to define '/test/Event/tc_onDefine()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Event/tc_onDefineScope() */
    test_Event_tc_onDefineScope_o = corto_declareChild(test_Event_o, "tc_onDefineScope()", test_Case_o);
    if (!test_Event_tc_onDefineScope_o) {
        corto_error("test_load: failed to declare '/test/Event/tc_onDefineScope()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Event/tc_onDefineScope() */
    if (!corto_checkState(test_Event_tc_onDefineScope_o, CORTO_DEFINED)) {
        corto_function(test_Event_tc_onDefineScope_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Event_tc_onDefineScope_o)->returnsReference = FALSE;
        corto_method(test_Event_tc_onDefineScope_o)->_virtual = FALSE;
        
        /* Bind /test/Event/tc_onDefineScope() with C-function */
        corto_function(test_Event_tc_onDefineScope_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Event_tc_onDefineScope(void *args, void *result);
        corto_function(test_Event_tc_onDefineScope_o)->impl = (corto_word)__test_Event_tc_onDefineScope;
        if (corto_define(test_Event_tc_onDefineScope_o)) {
            corto_error("test_load: failed to define '/test/Event/tc_onDefineScope()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Event/tc_onDefineSelf() */
    test_Event_tc_onDefineSelf_o = corto_declareChild(test_Event_o, "tc_onDefineSelf()", test_Case_o);
    if (!test_Event_tc_onDefineSelf_o) {
        corto_error("test_load: failed to declare '/test/Event/tc_onDefineSelf()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Event/tc_onDefineSelf() */
    if (!corto_checkState(test_Event_tc_onDefineSelf_o, CORTO_DEFINED)) {
        corto_function(test_Event_tc_onDefineSelf_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Event_tc_onDefineSelf_o)->returnsReference = FALSE;
        corto_method(test_Event_tc_onDefineSelf_o)->_virtual = FALSE;
        
        /* Bind /test/Event/tc_onDefineSelf() with C-function */
        corto_function(test_Event_tc_onDefineSelf_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Event_tc_onDefineSelf(void *args, void *result);
        corto_function(test_Event_tc_onDefineSelf_o)->impl = (corto_word)__test_Event_tc_onDefineSelf;
        if (corto_define(test_Event_tc_onDefineSelf_o)) {
            corto_error("test_load: failed to define '/test/Event/tc_onDefineSelf()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Event/tc_onDefineTree() */
    test_Event_tc_onDefineTree_o = corto_declareChild(test_Event_o, "tc_onDefineTree()", test_Case_o);
    if (!test_Event_tc_onDefineTree_o) {
        corto_error("test_load: failed to declare '/test/Event/tc_onDefineTree()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Event/tc_onDefineTree() */
    if (!corto_checkState(test_Event_tc_onDefineTree_o, CORTO_DEFINED)) {
        corto_function(test_Event_tc_onDefineTree_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Event_tc_onDefineTree_o)->returnsReference = FALSE;
        corto_method(test_Event_tc_onDefineTree_o)->_virtual = FALSE;
        
        /* Bind /test/Event/tc_onDefineTree() with C-function */
        corto_function(test_Event_tc_onDefineTree_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Event_tc_onDefineTree(void *args, void *result);
        corto_function(test_Event_tc_onDefineTree_o)->impl = (corto_word)__test_Event_tc_onDefineTree;
        if (corto_define(test_Event_tc_onDefineTree_o)) {
            corto_error("test_load: failed to define '/test/Event/tc_onDefineTree()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Event/tc_onDelete() */
    test_Event_tc_onDelete_o = corto_declareChild(test_Event_o, "tc_onDelete()", test_Case_o);
    if (!test_Event_tc_onDelete_o) {
        corto_error("test_load: failed to declare '/test/Event/tc_onDelete()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Event/tc_onDelete() */
    if (!corto_checkState(test_Event_tc_onDelete_o, CORTO_DEFINED)) {
        corto_function(test_Event_tc_onDelete_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Event_tc_onDelete_o)->returnsReference = FALSE;
        corto_method(test_Event_tc_onDelete_o)->_virtual = FALSE;
        
        /* Bind /test/Event/tc_onDelete() with C-function */
        corto_function(test_Event_tc_onDelete_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Event_tc_onDelete(void *args, void *result);
        corto_function(test_Event_tc_onDelete_o)->impl = (corto_word)__test_Event_tc_onDelete;
        if (corto_define(test_Event_tc_onDelete_o)) {
            corto_error("test_load: failed to define '/test/Event/tc_onDelete()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Event/tc_onDeleteScope() */
    test_Event_tc_onDeleteScope_o = corto_declareChild(test_Event_o, "tc_onDeleteScope()", test_Case_o);
    if (!test_Event_tc_onDeleteScope_o) {
        corto_error("test_load: failed to declare '/test/Event/tc_onDeleteScope()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Event/tc_onDeleteScope() */
    if (!corto_checkState(test_Event_tc_onDeleteScope_o, CORTO_DEFINED)) {
        corto_function(test_Event_tc_onDeleteScope_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Event_tc_onDeleteScope_o)->returnsReference = FALSE;
        corto_method(test_Event_tc_onDeleteScope_o)->_virtual = FALSE;
        
        /* Bind /test/Event/tc_onDeleteScope() with C-function */
        corto_function(test_Event_tc_onDeleteScope_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Event_tc_onDeleteScope(void *args, void *result);
        corto_function(test_Event_tc_onDeleteScope_o)->impl = (corto_word)__test_Event_tc_onDeleteScope;
        if (corto_define(test_Event_tc_onDeleteScope_o)) {
            corto_error("test_load: failed to define '/test/Event/tc_onDeleteScope()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Event/tc_onDeleteSelf() */
    test_Event_tc_onDeleteSelf_o = corto_declareChild(test_Event_o, "tc_onDeleteSelf()", test_Case_o);
    if (!test_Event_tc_onDeleteSelf_o) {
        corto_error("test_load: failed to declare '/test/Event/tc_onDeleteSelf()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Event/tc_onDeleteSelf() */
    if (!corto_checkState(test_Event_tc_onDeleteSelf_o, CORTO_DEFINED)) {
        corto_function(test_Event_tc_onDeleteSelf_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Event_tc_onDeleteSelf_o)->returnsReference = FALSE;
        corto_method(test_Event_tc_onDeleteSelf_o)->_virtual = FALSE;
        
        /* Bind /test/Event/tc_onDeleteSelf() with C-function */
        corto_function(test_Event_tc_onDeleteSelf_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Event_tc_onDeleteSelf(void *args, void *result);
        corto_function(test_Event_tc_onDeleteSelf_o)->impl = (corto_word)__test_Event_tc_onDeleteSelf;
        if (corto_define(test_Event_tc_onDeleteSelf_o)) {
            corto_error("test_load: failed to define '/test/Event/tc_onDeleteSelf()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Event/tc_onDeleteTree() */
    test_Event_tc_onDeleteTree_o = corto_declareChild(test_Event_o, "tc_onDeleteTree()", test_Case_o);
    if (!test_Event_tc_onDeleteTree_o) {
        corto_error("test_load: failed to declare '/test/Event/tc_onDeleteTree()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Event/tc_onDeleteTree() */
    if (!corto_checkState(test_Event_tc_onDeleteTree_o, CORTO_DEFINED)) {
        corto_function(test_Event_tc_onDeleteTree_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Event_tc_onDeleteTree_o)->returnsReference = FALSE;
        corto_method(test_Event_tc_onDeleteTree_o)->_virtual = FALSE;
        
        /* Bind /test/Event/tc_onDeleteTree() with C-function */
        corto_function(test_Event_tc_onDeleteTree_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Event_tc_onDeleteTree(void *args, void *result);
        corto_function(test_Event_tc_onDeleteTree_o)->impl = (corto_word)__test_Event_tc_onDeleteTree;
        if (corto_define(test_Event_tc_onDeleteTree_o)) {
            corto_error("test_load: failed to define '/test/Event/tc_onDeleteTree()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Event/tc_onUpdate() */
    test_Event_tc_onUpdate_o = corto_declareChild(test_Event_o, "tc_onUpdate()", test_Case_o);
    if (!test_Event_tc_onUpdate_o) {
        corto_error("test_load: failed to declare '/test/Event/tc_onUpdate()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Event/tc_onUpdate() */
    if (!corto_checkState(test_Event_tc_onUpdate_o, CORTO_DEFINED)) {
        corto_function(test_Event_tc_onUpdate_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Event_tc_onUpdate_o)->returnsReference = FALSE;
        corto_method(test_Event_tc_onUpdate_o)->_virtual = FALSE;
        
        /* Bind /test/Event/tc_onUpdate() with C-function */
        corto_function(test_Event_tc_onUpdate_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Event_tc_onUpdate(void *args, void *result);
        corto_function(test_Event_tc_onUpdate_o)->impl = (corto_word)__test_Event_tc_onUpdate;
        if (corto_define(test_Event_tc_onUpdate_o)) {
            corto_error("test_load: failed to define '/test/Event/tc_onUpdate()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Event/tc_onUpdateScope() */
    test_Event_tc_onUpdateScope_o = corto_declareChild(test_Event_o, "tc_onUpdateScope()", test_Case_o);
    if (!test_Event_tc_onUpdateScope_o) {
        corto_error("test_load: failed to declare '/test/Event/tc_onUpdateScope()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Event/tc_onUpdateScope() */
    if (!corto_checkState(test_Event_tc_onUpdateScope_o, CORTO_DEFINED)) {
        corto_function(test_Event_tc_onUpdateScope_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Event_tc_onUpdateScope_o)->returnsReference = FALSE;
        corto_method(test_Event_tc_onUpdateScope_o)->_virtual = FALSE;
        
        /* Bind /test/Event/tc_onUpdateScope() with C-function */
        corto_function(test_Event_tc_onUpdateScope_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Event_tc_onUpdateScope(void *args, void *result);
        corto_function(test_Event_tc_onUpdateScope_o)->impl = (corto_word)__test_Event_tc_onUpdateScope;
        if (corto_define(test_Event_tc_onUpdateScope_o)) {
            corto_error("test_load: failed to define '/test/Event/tc_onUpdateScope()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Event/tc_onUpdateSelf() */
    test_Event_tc_onUpdateSelf_o = corto_declareChild(test_Event_o, "tc_onUpdateSelf()", test_Case_o);
    if (!test_Event_tc_onUpdateSelf_o) {
        corto_error("test_load: failed to declare '/test/Event/tc_onUpdateSelf()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Event/tc_onUpdateSelf() */
    if (!corto_checkState(test_Event_tc_onUpdateSelf_o, CORTO_DEFINED)) {
        corto_function(test_Event_tc_onUpdateSelf_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Event_tc_onUpdateSelf_o)->returnsReference = FALSE;
        corto_method(test_Event_tc_onUpdateSelf_o)->_virtual = FALSE;
        
        /* Bind /test/Event/tc_onUpdateSelf() with C-function */
        corto_function(test_Event_tc_onUpdateSelf_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Event_tc_onUpdateSelf(void *args, void *result);
        corto_function(test_Event_tc_onUpdateSelf_o)->impl = (corto_word)__test_Event_tc_onUpdateSelf;
        if (corto_define(test_Event_tc_onUpdateSelf_o)) {
            corto_error("test_load: failed to define '/test/Event/tc_onUpdateSelf()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Event/tc_onUpdateTree() */
    test_Event_tc_onUpdateTree_o = corto_declareChild(test_Event_o, "tc_onUpdateTree()", test_Case_o);
    if (!test_Event_tc_onUpdateTree_o) {
        corto_error("test_load: failed to declare '/test/Event/tc_onUpdateTree()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Event/tc_onUpdateTree() */
    if (!corto_checkState(test_Event_tc_onUpdateTree_o, CORTO_DEFINED)) {
        corto_function(test_Event_tc_onUpdateTree_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Event_tc_onUpdateTree_o)->returnsReference = FALSE;
        corto_method(test_Event_tc_onUpdateTree_o)->_virtual = FALSE;
        
        /* Bind /test/Event/tc_onUpdateTree() with C-function */
        corto_function(test_Event_tc_onUpdateTree_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Event_tc_onUpdateTree(void *args, void *result);
        corto_function(test_Event_tc_onUpdateTree_o)->impl = (corto_word)__test_Event_tc_onUpdateTree;
        if (corto_define(test_Event_tc_onUpdateTree_o)) {
            corto_error("test_load: failed to define '/test/Event/tc_onUpdateTree()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Event/tc_updateUndefined() */
    test_Event_tc_updateUndefined_o = corto_declareChild(test_Event_o, "tc_updateUndefined()", test_Case_o);
    if (!test_Event_tc_updateUndefined_o) {
        corto_error("test_load: failed to declare '/test/Event/tc_updateUndefined()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Event/tc_updateUndefined() */
    if (!corto_checkState(test_Event_tc_updateUndefined_o, CORTO_DEFINED)) {
        corto_function(test_Event_tc_updateUndefined_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Event_tc_updateUndefined_o)->returnsReference = FALSE;
        corto_method(test_Event_tc_updateUndefined_o)->_virtual = FALSE;
        
        /* Bind /test/Event/tc_updateUndefined() with C-function */
        corto_function(test_Event_tc_updateUndefined_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Event_tc_updateUndefined(void *args, void *result);
        corto_function(test_Event_tc_updateUndefined_o)->impl = (corto_word)__test_Event_tc_updateUndefined;
        if (corto_define(test_Event_tc_updateUndefined_o)) {
            corto_error("test_load: failed to define '/test/Event/tc_updateUndefined()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Event/tc_updateVoidErr() */
    test_Event_tc_updateVoidErr_o = corto_declareChild(test_Event_o, "tc_updateVoidErr()", test_Case_o);
    if (!test_Event_tc_updateVoidErr_o) {
        corto_error("test_load: failed to declare '/test/Event/tc_updateVoidErr()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Event/tc_updateVoidErr() */
    if (!corto_checkState(test_Event_tc_updateVoidErr_o, CORTO_DEFINED)) {
        corto_function(test_Event_tc_updateVoidErr_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Event_tc_updateVoidErr_o)->returnsReference = FALSE;
        corto_method(test_Event_tc_updateVoidErr_o)->_virtual = FALSE;
        
        /* Bind /test/Event/tc_updateVoidErr() with C-function */
        corto_function(test_Event_tc_updateVoidErr_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Event_tc_updateVoidErr(void *args, void *result);
        corto_function(test_Event_tc_updateVoidErr_o)->impl = (corto_word)__test_Event_tc_updateVoidErr;
        if (corto_define(test_Event_tc_updateVoidErr_o)) {
            corto_error("test_load: failed to define '/test/Event/tc_updateVoidErr()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/EventTest/onDeclare */
    test_EventTest_onDeclare_o = corto_declareChild(test_EventTest_o, "onDeclare", corto_observer_o);
    if (!test_EventTest_onDeclare_o) {
        corto_error("test_load: failed to declare '/test/EventTest/onDeclare' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/EventTest/onDeclare */
    if (!corto_checkState(test_EventTest_onDeclare_o, CORTO_DEFINED)) {
        test_EventTest_onDeclare_o->mask = 0x1a1;
        test_EventTest_onDeclare_o->observable = NULL;
        test_EventTest_onDeclare_o->_template = 1;
        test_EventTest_onDeclare_o->dispatcher = NULL;
        test_EventTest_onDeclare_o->me = NULL;
        
        /* Bind /test/EventTest/onDeclare with C-function */
        corto_function(test_EventTest_onDeclare_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_EventTest_onDeclare(void *args, void *result);
        corto_function(test_EventTest_onDeclare_o)->impl = (corto_word)__test_EventTest_onDeclare;
        if (corto_define(test_EventTest_onDeclare_o)) {
            corto_error("test_load: failed to define '/test/EventTest/onDeclare' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/EventTest/onDeclareScope */
    test_EventTest_onDeclareScope_o = corto_declareChild(test_EventTest_o, "onDeclareScope", corto_observer_o);
    if (!test_EventTest_onDeclareScope_o) {
        corto_error("test_load: failed to declare '/test/EventTest/onDeclareScope' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/EventTest/onDeclareScope */
    if (!corto_checkState(test_EventTest_onDeclareScope_o, CORTO_DEFINED)) {
        test_EventTest_onDeclareScope_o->mask = 0x141;
        test_EventTest_onDeclareScope_o->observable = NULL;
        test_EventTest_onDeclareScope_o->_template = 3;
        test_EventTest_onDeclareScope_o->dispatcher = NULL;
        test_EventTest_onDeclareScope_o->me = NULL;
        
        /* Bind /test/EventTest/onDeclareScope with C-function */
        corto_function(test_EventTest_onDeclareScope_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_EventTest_onDeclareScope(void *args, void *result);
        corto_function(test_EventTest_onDeclareScope_o)->impl = (corto_word)__test_EventTest_onDeclareScope;
        if (corto_define(test_EventTest_onDeclareScope_o)) {
            corto_error("test_load: failed to define '/test/EventTest/onDeclareScope' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/EventTest/onDeclareSelf */
    test_EventTest_onDeclareSelf_o = corto_declareChild(test_EventTest_o, "onDeclareSelf", corto_observer_o);
    if (!test_EventTest_onDeclareSelf_o) {
        corto_error("test_load: failed to declare '/test/EventTest/onDeclareSelf' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/EventTest/onDeclareSelf */
    if (!corto_checkState(test_EventTest_onDeclareSelf_o, CORTO_DEFINED)) {
        test_EventTest_onDeclareSelf_o->mask = 0x121;
        test_EventTest_onDeclareSelf_o->observable = NULL;
        test_EventTest_onDeclareSelf_o->_template = 2;
        test_EventTest_onDeclareSelf_o->dispatcher = NULL;
        test_EventTest_onDeclareSelf_o->me = NULL;
        
        /* Bind /test/EventTest/onDeclareSelf with C-function */
        corto_function(test_EventTest_onDeclareSelf_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_EventTest_onDeclareSelf(void *args, void *result);
        corto_function(test_EventTest_onDeclareSelf_o)->impl = (corto_word)__test_EventTest_onDeclareSelf;
        if (corto_define(test_EventTest_onDeclareSelf_o)) {
            corto_error("test_load: failed to define '/test/EventTest/onDeclareSelf' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/EventTest/onDeclareTree */
    test_EventTest_onDeclareTree_o = corto_declareChild(test_EventTest_o, "onDeclareTree", corto_observer_o);
    if (!test_EventTest_onDeclareTree_o) {
        corto_error("test_load: failed to declare '/test/EventTest/onDeclareTree' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/EventTest/onDeclareTree */
    if (!corto_checkState(test_EventTest_onDeclareTree_o, CORTO_DEFINED)) {
        test_EventTest_onDeclareTree_o->mask = 0x181;
        test_EventTest_onDeclareTree_o->observable = NULL;
        test_EventTest_onDeclareTree_o->_template = 4;
        test_EventTest_onDeclareTree_o->dispatcher = NULL;
        test_EventTest_onDeclareTree_o->me = NULL;
        
        /* Bind /test/EventTest/onDeclareTree with C-function */
        corto_function(test_EventTest_onDeclareTree_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_EventTest_onDeclareTree(void *args, void *result);
        corto_function(test_EventTest_onDeclareTree_o)->impl = (corto_word)__test_EventTest_onDeclareTree;
        if (corto_define(test_EventTest_onDeclareTree_o)) {
            corto_error("test_load: failed to define '/test/EventTest/onDeclareTree' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/EventTest/onDefine */
    test_EventTest_onDefine_o = corto_declareChild(test_EventTest_o, "onDefine", corto_observer_o);
    if (!test_EventTest_onDefine_o) {
        corto_error("test_load: failed to declare '/test/EventTest/onDefine' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/EventTest/onDefine */
    if (!corto_checkState(test_EventTest_onDefine_o, CORTO_DEFINED)) {
        test_EventTest_onDefine_o->mask = 0x1a2;
        test_EventTest_onDefine_o->observable = NULL;
        test_EventTest_onDefine_o->_template = 5;
        test_EventTest_onDefine_o->dispatcher = NULL;
        test_EventTest_onDefine_o->me = NULL;
        
        /* Bind /test/EventTest/onDefine with C-function */
        corto_function(test_EventTest_onDefine_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_EventTest_onDefine(void *args, void *result);
        corto_function(test_EventTest_onDefine_o)->impl = (corto_word)__test_EventTest_onDefine;
        if (corto_define(test_EventTest_onDefine_o)) {
            corto_error("test_load: failed to define '/test/EventTest/onDefine' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/EventTest/onDefineScope */
    test_EventTest_onDefineScope_o = corto_declareChild(test_EventTest_o, "onDefineScope", corto_observer_o);
    if (!test_EventTest_onDefineScope_o) {
        corto_error("test_load: failed to declare '/test/EventTest/onDefineScope' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/EventTest/onDefineScope */
    if (!corto_checkState(test_EventTest_onDefineScope_o, CORTO_DEFINED)) {
        test_EventTest_onDefineScope_o->mask = 0x142;
        test_EventTest_onDefineScope_o->observable = NULL;
        test_EventTest_onDefineScope_o->_template = 7;
        test_EventTest_onDefineScope_o->dispatcher = NULL;
        test_EventTest_onDefineScope_o->me = NULL;
        
        /* Bind /test/EventTest/onDefineScope with C-function */
        corto_function(test_EventTest_onDefineScope_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_EventTest_onDefineScope(void *args, void *result);
        corto_function(test_EventTest_onDefineScope_o)->impl = (corto_word)__test_EventTest_onDefineScope;
        if (corto_define(test_EventTest_onDefineScope_o)) {
            corto_error("test_load: failed to define '/test/EventTest/onDefineScope' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/EventTest/onDefineSelf */
    test_EventTest_onDefineSelf_o = corto_declareChild(test_EventTest_o, "onDefineSelf", corto_observer_o);
    if (!test_EventTest_onDefineSelf_o) {
        corto_error("test_load: failed to declare '/test/EventTest/onDefineSelf' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/EventTest/onDefineSelf */
    if (!corto_checkState(test_EventTest_onDefineSelf_o, CORTO_DEFINED)) {
        test_EventTest_onDefineSelf_o->mask = 0x122;
        test_EventTest_onDefineSelf_o->observable = NULL;
        test_EventTest_onDefineSelf_o->_template = 6;
        test_EventTest_onDefineSelf_o->dispatcher = NULL;
        test_EventTest_onDefineSelf_o->me = NULL;
        
        /* Bind /test/EventTest/onDefineSelf with C-function */
        corto_function(test_EventTest_onDefineSelf_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_EventTest_onDefineSelf(void *args, void *result);
        corto_function(test_EventTest_onDefineSelf_o)->impl = (corto_word)__test_EventTest_onDefineSelf;
        if (corto_define(test_EventTest_onDefineSelf_o)) {
            corto_error("test_load: failed to define '/test/EventTest/onDefineSelf' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/EventTest/onDefineTree */
    test_EventTest_onDefineTree_o = corto_declareChild(test_EventTest_o, "onDefineTree", corto_observer_o);
    if (!test_EventTest_onDefineTree_o) {
        corto_error("test_load: failed to declare '/test/EventTest/onDefineTree' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/EventTest/onDefineTree */
    if (!corto_checkState(test_EventTest_onDefineTree_o, CORTO_DEFINED)) {
        test_EventTest_onDefineTree_o->mask = 0x182;
        test_EventTest_onDefineTree_o->observable = NULL;
        test_EventTest_onDefineTree_o->_template = 8;
        test_EventTest_onDefineTree_o->dispatcher = NULL;
        test_EventTest_onDefineTree_o->me = NULL;
        
        /* Bind /test/EventTest/onDefineTree with C-function */
        corto_function(test_EventTest_onDefineTree_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_EventTest_onDefineTree(void *args, void *result);
        corto_function(test_EventTest_onDefineTree_o)->impl = (corto_word)__test_EventTest_onDefineTree;
        if (corto_define(test_EventTest_onDefineTree_o)) {
            corto_error("test_load: failed to define '/test/EventTest/onDefineTree' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/EventTest/onDelete */
    test_EventTest_onDelete_o = corto_declareChild(test_EventTest_o, "onDelete", corto_observer_o);
    if (!test_EventTest_onDelete_o) {
        corto_error("test_load: failed to declare '/test/EventTest/onDelete' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/EventTest/onDelete */
    if (!corto_checkState(test_EventTest_onDelete_o, CORTO_DEFINED)) {
        test_EventTest_onDelete_o->mask = 0x1a4;
        test_EventTest_onDelete_o->observable = NULL;
        test_EventTest_onDelete_o->_template = 13;
        test_EventTest_onDelete_o->dispatcher = NULL;
        test_EventTest_onDelete_o->me = NULL;
        
        /* Bind /test/EventTest/onDelete with C-function */
        corto_function(test_EventTest_onDelete_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_EventTest_onDelete(void *args, void *result);
        corto_function(test_EventTest_onDelete_o)->impl = (corto_word)__test_EventTest_onDelete;
        if (corto_define(test_EventTest_onDelete_o)) {
            corto_error("test_load: failed to define '/test/EventTest/onDelete' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/EventTest/onDeleteScope */
    test_EventTest_onDeleteScope_o = corto_declareChild(test_EventTest_o, "onDeleteScope", corto_observer_o);
    if (!test_EventTest_onDeleteScope_o) {
        corto_error("test_load: failed to declare '/test/EventTest/onDeleteScope' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/EventTest/onDeleteScope */
    if (!corto_checkState(test_EventTest_onDeleteScope_o, CORTO_DEFINED)) {
        test_EventTest_onDeleteScope_o->mask = 0x144;
        test_EventTest_onDeleteScope_o->observable = NULL;
        test_EventTest_onDeleteScope_o->_template = 15;
        test_EventTest_onDeleteScope_o->dispatcher = NULL;
        test_EventTest_onDeleteScope_o->me = NULL;
        
        /* Bind /test/EventTest/onDeleteScope with C-function */
        corto_function(test_EventTest_onDeleteScope_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_EventTest_onDeleteScope(void *args, void *result);
        corto_function(test_EventTest_onDeleteScope_o)->impl = (corto_word)__test_EventTest_onDeleteScope;
        if (corto_define(test_EventTest_onDeleteScope_o)) {
            corto_error("test_load: failed to define '/test/EventTest/onDeleteScope' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/EventTest/onDeleteSelf */
    test_EventTest_onDeleteSelf_o = corto_declareChild(test_EventTest_o, "onDeleteSelf", corto_observer_o);
    if (!test_EventTest_onDeleteSelf_o) {
        corto_error("test_load: failed to declare '/test/EventTest/onDeleteSelf' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/EventTest/onDeleteSelf */
    if (!corto_checkState(test_EventTest_onDeleteSelf_o, CORTO_DEFINED)) {
        test_EventTest_onDeleteSelf_o->mask = 0x124;
        test_EventTest_onDeleteSelf_o->observable = NULL;
        test_EventTest_onDeleteSelf_o->_template = 14;
        test_EventTest_onDeleteSelf_o->dispatcher = NULL;
        test_EventTest_onDeleteSelf_o->me = NULL;
        
        /* Bind /test/EventTest/onDeleteSelf with C-function */
        corto_function(test_EventTest_onDeleteSelf_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_EventTest_onDeleteSelf(void *args, void *result);
        corto_function(test_EventTest_onDeleteSelf_o)->impl = (corto_word)__test_EventTest_onDeleteSelf;
        if (corto_define(test_EventTest_onDeleteSelf_o)) {
            corto_error("test_load: failed to define '/test/EventTest/onDeleteSelf' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/EventTest/onDeleteTree */
    test_EventTest_onDeleteTree_o = corto_declareChild(test_EventTest_o, "onDeleteTree", corto_observer_o);
    if (!test_EventTest_onDeleteTree_o) {
        corto_error("test_load: failed to declare '/test/EventTest/onDeleteTree' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/EventTest/onDeleteTree */
    if (!corto_checkState(test_EventTest_onDeleteTree_o, CORTO_DEFINED)) {
        test_EventTest_onDeleteTree_o->mask = 0x184;
        test_EventTest_onDeleteTree_o->observable = NULL;
        test_EventTest_onDeleteTree_o->_template = 16;
        test_EventTest_onDeleteTree_o->dispatcher = NULL;
        test_EventTest_onDeleteTree_o->me = NULL;
        
        /* Bind /test/EventTest/onDeleteTree with C-function */
        corto_function(test_EventTest_onDeleteTree_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_EventTest_onDeleteTree(void *args, void *result);
        corto_function(test_EventTest_onDeleteTree_o)->impl = (corto_word)__test_EventTest_onDeleteTree;
        if (corto_define(test_EventTest_onDeleteTree_o)) {
            corto_error("test_load: failed to define '/test/EventTest/onDeleteTree' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/EventTest/onUpdate */
    test_EventTest_onUpdate_o = corto_declareChild(test_EventTest_o, "onUpdate", corto_observer_o);
    if (!test_EventTest_onUpdate_o) {
        corto_error("test_load: failed to declare '/test/EventTest/onUpdate' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/EventTest/onUpdate */
    if (!corto_checkState(test_EventTest_onUpdate_o, CORTO_DEFINED)) {
        test_EventTest_onUpdate_o->mask = 0x1b0;
        test_EventTest_onUpdate_o->observable = NULL;
        test_EventTest_onUpdate_o->_template = 9;
        test_EventTest_onUpdate_o->dispatcher = NULL;
        test_EventTest_onUpdate_o->me = NULL;
        
        /* Bind /test/EventTest/onUpdate with C-function */
        corto_function(test_EventTest_onUpdate_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_EventTest_onUpdate(void *args, void *result);
        corto_function(test_EventTest_onUpdate_o)->impl = (corto_word)__test_EventTest_onUpdate;
        if (corto_define(test_EventTest_onUpdate_o)) {
            corto_error("test_load: failed to define '/test/EventTest/onUpdate' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/EventTest/onUpdateScope */
    test_EventTest_onUpdateScope_o = corto_declareChild(test_EventTest_o, "onUpdateScope", corto_observer_o);
    if (!test_EventTest_onUpdateScope_o) {
        corto_error("test_load: failed to declare '/test/EventTest/onUpdateScope' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/EventTest/onUpdateScope */
    if (!corto_checkState(test_EventTest_onUpdateScope_o, CORTO_DEFINED)) {
        test_EventTest_onUpdateScope_o->mask = 0x150;
        test_EventTest_onUpdateScope_o->observable = NULL;
        test_EventTest_onUpdateScope_o->_template = 11;
        test_EventTest_onUpdateScope_o->dispatcher = NULL;
        test_EventTest_onUpdateScope_o->me = NULL;
        
        /* Bind /test/EventTest/onUpdateScope with C-function */
        corto_function(test_EventTest_onUpdateScope_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_EventTest_onUpdateScope(void *args, void *result);
        corto_function(test_EventTest_onUpdateScope_o)->impl = (corto_word)__test_EventTest_onUpdateScope;
        if (corto_define(test_EventTest_onUpdateScope_o)) {
            corto_error("test_load: failed to define '/test/EventTest/onUpdateScope' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/EventTest/onUpdateSelf */
    test_EventTest_onUpdateSelf_o = corto_declareChild(test_EventTest_o, "onUpdateSelf", corto_observer_o);
    if (!test_EventTest_onUpdateSelf_o) {
        corto_error("test_load: failed to declare '/test/EventTest/onUpdateSelf' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/EventTest/onUpdateSelf */
    if (!corto_checkState(test_EventTest_onUpdateSelf_o, CORTO_DEFINED)) {
        test_EventTest_onUpdateSelf_o->mask = 0x130;
        test_EventTest_onUpdateSelf_o->observable = NULL;
        test_EventTest_onUpdateSelf_o->_template = 10;
        test_EventTest_onUpdateSelf_o->dispatcher = NULL;
        test_EventTest_onUpdateSelf_o->me = NULL;
        
        /* Bind /test/EventTest/onUpdateSelf with C-function */
        corto_function(test_EventTest_onUpdateSelf_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_EventTest_onUpdateSelf(void *args, void *result);
        corto_function(test_EventTest_onUpdateSelf_o)->impl = (corto_word)__test_EventTest_onUpdateSelf;
        if (corto_define(test_EventTest_onUpdateSelf_o)) {
            corto_error("test_load: failed to define '/test/EventTest/onUpdateSelf' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/EventTest/onUpdateTree */
    test_EventTest_onUpdateTree_o = corto_declareChild(test_EventTest_o, "onUpdateTree", corto_observer_o);
    if (!test_EventTest_onUpdateTree_o) {
        corto_error("test_load: failed to declare '/test/EventTest/onUpdateTree' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/EventTest/onUpdateTree */
    if (!corto_checkState(test_EventTest_onUpdateTree_o, CORTO_DEFINED)) {
        test_EventTest_onUpdateTree_o->mask = 0x190;
        test_EventTest_onUpdateTree_o->observable = NULL;
        test_EventTest_onUpdateTree_o->_template = 12;
        test_EventTest_onUpdateTree_o->dispatcher = NULL;
        test_EventTest_onUpdateTree_o->me = NULL;
        
        /* Bind /test/EventTest/onUpdateTree with C-function */
        corto_function(test_EventTest_onUpdateTree_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_EventTest_onUpdateTree(void *args, void *result);
        corto_function(test_EventTest_onUpdateTree_o)->impl = (corto_word)__test_EventTest_onUpdateTree;
        if (corto_define(test_EventTest_onUpdateTree_o)) {
            corto_error("test_load: failed to define '/test/EventTest/onUpdateTree' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Foo */
    test_Foo_o = corto_declareChild(test_o, "Foo", corto_class_o);
    if (!test_Foo_o) {
        corto_error("test_load: failed to declare '/test/Foo' (%s)", corto_lasterr());
        goto error;
    }

    /* Declare /test/Foo/construct() */
    test_Foo_construct_o = corto_declareChild(test_Foo_o, "construct()", corto_method_o);
    if (!test_Foo_construct_o) {
        corto_error("test_load: failed to declare '/test/Foo/construct()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Foo/construct() */
    if (!corto_checkState(test_Foo_construct_o, CORTO_DEFINED)) {
        corto_function(test_Foo_construct_o)->returnType = corto_resolve(NULL, "/corto/lang/int16");
        corto_function(test_Foo_construct_o)->returnsReference = FALSE;
        test_Foo_construct_o->_virtual = FALSE;
        
        /* Bind /test/Foo/construct() with C-function */
        corto_function(test_Foo_construct_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Foo_construct(void *args, void *result);
        corto_function(test_Foo_construct_o)->impl = (corto_word)__test_Foo_construct;
        if (corto_define(test_Foo_construct_o)) {
            corto_error("test_load: failed to define '/test/Foo/construct()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Foo/destruct() */
    test_Foo_destruct_o = corto_declareChild(test_Foo_o, "destruct()", corto_method_o);
    if (!test_Foo_destruct_o) {
        corto_error("test_load: failed to declare '/test/Foo/destruct()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Foo/destruct() */
    if (!corto_checkState(test_Foo_destruct_o, CORTO_DEFINED)) {
        corto_function(test_Foo_destruct_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Foo_destruct_o)->returnsReference = FALSE;
        test_Foo_destruct_o->_virtual = FALSE;
        
        /* Bind /test/Foo/destruct() with C-function */
        corto_function(test_Foo_destruct_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Foo_destruct(void *args, void *result);
        corto_function(test_Foo_destruct_o)->impl = (corto_word)__test_Foo_destruct;
        if (corto_define(test_Foo_destruct_o)) {
            corto_error("test_load: failed to define '/test/Foo/destruct()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Foo/fail */
    test_Foo_fail_o = corto_declareChild(test_Foo_o, "fail", corto_member_o);
    if (!test_Foo_fail_o) {
        corto_error("test_load: failed to declare '/test/Foo/fail' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Foo/fail */
    if (!corto_checkState(test_Foo_fail_o, CORTO_DEFINED)) {
        test_Foo_fail_o->type = corto_resolve(NULL, "/corto/lang/bool");
        test_Foo_fail_o->modifiers = 0x1;
        test_Foo_fail_o->state = 0x6;
        test_Foo_fail_o->weak = FALSE;
        test_Foo_fail_o->id = 0;
        if (corto_define(test_Foo_fail_o)) {
            corto_error("test_load: failed to define '/test/Foo/fail' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Foo/init() */
    test_Foo_init_o = corto_declareChild(test_Foo_o, "init()", corto_method_o);
    if (!test_Foo_init_o) {
        corto_error("test_load: failed to declare '/test/Foo/init()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Foo/init() */
    if (!corto_checkState(test_Foo_init_o, CORTO_DEFINED)) {
        corto_function(test_Foo_init_o)->returnType = corto_resolve(NULL, "/corto/lang/int16");
        corto_function(test_Foo_init_o)->returnsReference = FALSE;
        test_Foo_init_o->_virtual = FALSE;
        
        /* Bind /test/Foo/init() with C-function */
        corto_function(test_Foo_init_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Foo_init(void *args, void *result);
        corto_function(test_Foo_init_o)->impl = (corto_word)__test_Foo_init;
        if (corto_define(test_Foo_init_o)) {
            corto_error("test_load: failed to define '/test/Foo/init()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Foo/x */
    test_Foo_x_o = corto_declareChild(test_Foo_o, "x", corto_member_o);
    if (!test_Foo_x_o) {
        corto_error("test_load: failed to declare '/test/Foo/x' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Foo/x */
    if (!corto_checkState(test_Foo_x_o, CORTO_DEFINED)) {
        test_Foo_x_o->type = corto_resolve(NULL, "/corto/lang/int32");
        test_Foo_x_o->modifiers = 0x0;
        test_Foo_x_o->state = 0x6;
        test_Foo_x_o->weak = FALSE;
        test_Foo_x_o->id = 1;
        if (corto_define(test_Foo_x_o)) {
            corto_error("test_load: failed to define '/test/Foo/x' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Foo/y */
    test_Foo_y_o = corto_declareChild(test_Foo_o, "y", corto_member_o);
    if (!test_Foo_y_o) {
        corto_error("test_load: failed to declare '/test/Foo/y' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Foo/y */
    if (!corto_checkState(test_Foo_y_o, CORTO_DEFINED)) {
        test_Foo_y_o->type = corto_resolve(NULL, "/corto/lang/int32");
        test_Foo_y_o->modifiers = 0x0;
        test_Foo_y_o->state = 0x6;
        test_Foo_y_o->weak = FALSE;
        test_Foo_y_o->id = 2;
        if (corto_define(test_Foo_y_o)) {
            corto_error("test_load: failed to define '/test/Foo/y' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Define /test/Foo */
    if (!corto_checkState(test_Foo_o, CORTO_DEFINED)) {
        corto_type(test_Foo_o)->parentType = NULL;
        corto_type(test_Foo_o)->parentState = 0x6;
        corto_type(test_Foo_o)->defaultType = NULL;
        corto_type(test_Foo_o)->defaultProcedureType = NULL;
        corto_interface(test_Foo_o)->base = NULL;
        corto_struct(test_Foo_o)->baseAccess = 0x0;
        test_Foo_o->implements.length = 0;
        test_Foo_o->implements.buffer = NULL;
        if (corto_define(test_Foo_o)) {
            corto_error("test_load: failed to define '/test/Foo' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (corto_type(test_Foo_o)->size != sizeof(struct test_Foo_s)) {
        corto_error("test_load: calculated size '%d' of type '/test/Foo' doesn't match C-type size '%d'", corto_type(test_Foo_o)->size, sizeof(struct test_Foo_s));
    }

    /* Declare /test/Fullname */
    test_Fullname_o = corto_declareChild(test_o, "Fullname", test_Suite_o);
    if (!test_Fullname_o) {
        corto_error("test_load: failed to declare '/test/Fullname' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Fullname */
    if (!corto_checkState(test_Fullname_o, CORTO_DEFINED)) {
        corto_type(test_Fullname_o)->parentType = NULL;
        corto_type(test_Fullname_o)->parentState = 0x6;
        corto_type(test_Fullname_o)->defaultType = NULL;
        corto_type(test_Fullname_o)->defaultProcedureType = NULL;
        corto_interface(test_Fullname_o)->base = corto_resolve(NULL, "/corto/test/SuiteData");
        corto_struct(test_Fullname_o)->baseAccess = 0x0;
        corto_class(test_Fullname_o)->implements.length = 0;
        corto_class(test_Fullname_o)->implements.buffer = NULL;
        if (corto_define(test_Fullname_o)) {
            corto_error("test_load: failed to define '/test/Fullname' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (corto_type(test_Fullname_o)->size != sizeof(struct test_Fullname_s)) {
        corto_error("test_load: calculated size '%d' of type '/test/Fullname' doesn't match C-type size '%d'", corto_type(test_Fullname_o)->size, sizeof(struct test_Fullname_s));
    }

    /* Declare /test/Fullname/tc_null() */
    test_Fullname_tc_null_o = corto_declareChild(test_Fullname_o, "tc_null()", test_Case_o);
    if (!test_Fullname_tc_null_o) {
        corto_error("test_load: failed to declare '/test/Fullname/tc_null()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Fullname/tc_null() */
    if (!corto_checkState(test_Fullname_tc_null_o, CORTO_DEFINED)) {
        corto_function(test_Fullname_tc_null_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Fullname_tc_null_o)->returnsReference = FALSE;
        corto_method(test_Fullname_tc_null_o)->_virtual = FALSE;
        
        /* Bind /test/Fullname/tc_null() with C-function */
        corto_function(test_Fullname_tc_null_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Fullname_tc_null(void *args, void *result);
        corto_function(test_Fullname_tc_null_o)->impl = (corto_word)__test_Fullname_tc_null;
        if (corto_define(test_Fullname_tc_null_o)) {
            corto_error("test_load: failed to define '/test/Fullname/tc_null()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Fullname/tc_nullBuffer() */
    test_Fullname_tc_nullBuffer_o = corto_declareChild(test_Fullname_o, "tc_nullBuffer()", test_Case_o);
    if (!test_Fullname_tc_nullBuffer_o) {
        corto_error("test_load: failed to declare '/test/Fullname/tc_nullBuffer()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Fullname/tc_nullBuffer() */
    if (!corto_checkState(test_Fullname_tc_nullBuffer_o, CORTO_DEFINED)) {
        corto_function(test_Fullname_tc_nullBuffer_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Fullname_tc_nullBuffer_o)->returnsReference = FALSE;
        corto_method(test_Fullname_tc_nullBuffer_o)->_virtual = FALSE;
        
        /* Bind /test/Fullname/tc_nullBuffer() with C-function */
        corto_function(test_Fullname_tc_nullBuffer_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Fullname_tc_nullBuffer(void *args, void *result);
        corto_function(test_Fullname_tc_nullBuffer_o)->impl = (corto_word)__test_Fullname_tc_nullBuffer;
        if (corto_define(test_Fullname_tc_nullBuffer_o)) {
            corto_error("test_load: failed to define '/test/Fullname/tc_nullBuffer()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Fullname/tc_onelevel() */
    test_Fullname_tc_onelevel_o = corto_declareChild(test_Fullname_o, "tc_onelevel()", test_Case_o);
    if (!test_Fullname_tc_onelevel_o) {
        corto_error("test_load: failed to declare '/test/Fullname/tc_onelevel()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Fullname/tc_onelevel() */
    if (!corto_checkState(test_Fullname_tc_onelevel_o, CORTO_DEFINED)) {
        corto_function(test_Fullname_tc_onelevel_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Fullname_tc_onelevel_o)->returnsReference = FALSE;
        corto_method(test_Fullname_tc_onelevel_o)->_virtual = FALSE;
        
        /* Bind /test/Fullname/tc_onelevel() with C-function */
        corto_function(test_Fullname_tc_onelevel_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Fullname_tc_onelevel(void *args, void *result);
        corto_function(test_Fullname_tc_onelevel_o)->impl = (corto_word)__test_Fullname_tc_onelevel;
        if (corto_define(test_Fullname_tc_onelevel_o)) {
            corto_error("test_load: failed to define '/test/Fullname/tc_onelevel()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Fullname/tc_root() */
    test_Fullname_tc_root_o = corto_declareChild(test_Fullname_o, "tc_root()", test_Case_o);
    if (!test_Fullname_tc_root_o) {
        corto_error("test_load: failed to declare '/test/Fullname/tc_root()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Fullname/tc_root() */
    if (!corto_checkState(test_Fullname_tc_root_o, CORTO_DEFINED)) {
        corto_function(test_Fullname_tc_root_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Fullname_tc_root_o)->returnsReference = FALSE;
        corto_method(test_Fullname_tc_root_o)->_virtual = FALSE;
        
        /* Bind /test/Fullname/tc_root() with C-function */
        corto_function(test_Fullname_tc_root_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Fullname_tc_root(void *args, void *result);
        corto_function(test_Fullname_tc_root_o)->impl = (corto_word)__test_Fullname_tc_root;
        if (corto_define(test_Fullname_tc_root_o)) {
            corto_error("test_load: failed to define '/test/Fullname/tc_root()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Fullname/tc_twolevels() */
    test_Fullname_tc_twolevels_o = corto_declareChild(test_Fullname_o, "tc_twolevels()", test_Case_o);
    if (!test_Fullname_tc_twolevels_o) {
        corto_error("test_load: failed to declare '/test/Fullname/tc_twolevels()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Fullname/tc_twolevels() */
    if (!corto_checkState(test_Fullname_tc_twolevels_o, CORTO_DEFINED)) {
        corto_function(test_Fullname_tc_twolevels_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Fullname_tc_twolevels_o)->returnsReference = FALSE;
        corto_method(test_Fullname_tc_twolevels_o)->_virtual = FALSE;
        
        /* Bind /test/Fullname/tc_twolevels() with C-function */
        corto_function(test_Fullname_tc_twolevels_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Fullname_tc_twolevels(void *args, void *result);
        corto_function(test_Fullname_tc_twolevels_o)->impl = (corto_word)__test_Fullname_tc_twolevels;
        if (corto_define(test_Fullname_tc_twolevels_o)) {
            corto_error("test_load: failed to define '/test/Fullname/tc_twolevels()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/functionToResolve(int32 a,int32 b) */
    test_functionToResolve_o = corto_declareChild(test_o, "functionToResolve(int32 a,int32 b)", corto_function_o);
    if (!test_functionToResolve_o) {
        corto_error("test_load: failed to declare '/test/functionToResolve(int32 a,int32 b)' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/functionToResolve(int32 a,int32 b) */
    if (!corto_checkState(test_functionToResolve_o, CORTO_DEFINED)) {
        test_functionToResolve_o->returnType = corto_resolve(NULL, "/corto/lang/void");
        test_functionToResolve_o->returnsReference = FALSE;
        
        /* Bind /test/functionToResolve(int32 a,int32 b) with C-function */
        corto_function(test_functionToResolve_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_functionToResolve(void *args, void *result);
        corto_function(test_functionToResolve_o)->impl = (corto_word)__test_functionToResolve;
        if (corto_define(test_functionToResolve_o)) {
            corto_error("test_load: failed to define '/test/functionToResolve(int32 a,int32 b)' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/GoldenRetriever */
    test_GoldenRetriever_o = corto_declareChild(test_o, "GoldenRetriever", corto_class_o);
    if (!test_GoldenRetriever_o) {
        corto_error("test_load: failed to declare '/test/GoldenRetriever' (%s)", corto_lasterr());
        goto error;
    }

    /* Declare /test/GoldenRetriever/c */
    test_GoldenRetriever_c_o = corto_declareChild(test_GoldenRetriever_o, "c", corto_member_o);
    if (!test_GoldenRetriever_c_o) {
        corto_error("test_load: failed to declare '/test/GoldenRetriever/c' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/GoldenRetriever/c */
    if (!corto_checkState(test_GoldenRetriever_c_o, CORTO_DEFINED)) {
        test_GoldenRetriever_c_o->type = corto_resolve(NULL, "/corto/lang/bool");
        test_GoldenRetriever_c_o->modifiers = 0x0;
        test_GoldenRetriever_c_o->state = 0x6;
        test_GoldenRetriever_c_o->weak = FALSE;
        test_GoldenRetriever_c_o->id = 0;
        if (corto_define(test_GoldenRetriever_c_o)) {
            corto_error("test_load: failed to define '/test/GoldenRetriever/c' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Define /test/GoldenRetriever */
    if (!corto_checkState(test_GoldenRetriever_o, CORTO_DEFINED)) {
        corto_type(test_GoldenRetriever_o)->parentType = NULL;
        corto_type(test_GoldenRetriever_o)->parentState = 0x6;
        corto_type(test_GoldenRetriever_o)->defaultType = NULL;
        corto_type(test_GoldenRetriever_o)->defaultProcedureType = NULL;
        corto_interface(test_GoldenRetriever_o)->base = corto_resolve(NULL, "/test/Dog");
        corto_struct(test_GoldenRetriever_o)->baseAccess = 0x0;
        test_GoldenRetriever_o->implements.length = 0;
        test_GoldenRetriever_o->implements.buffer = NULL;
        if (corto_define(test_GoldenRetriever_o)) {
            corto_error("test_load: failed to define '/test/GoldenRetriever' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (corto_type(test_GoldenRetriever_o)->size != sizeof(struct test_GoldenRetriever_s)) {
        corto_error("test_load: calculated size '%d' of type '/test/GoldenRetriever' doesn't match C-type size '%d'", corto_type(test_GoldenRetriever_o)->size, sizeof(struct test_GoldenRetriever_s));
    }

    /* Declare /test/initCalled */
    test_initCalled_o = corto_declareChild(test_o, "initCalled", corto_int8_o);
    if (!test_initCalled_o) {
        corto_error("test_load: failed to declare '/test/initCalled' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/initCalled */
    if (!corto_checkState(test_initCalled_o, CORTO_DEFINED)) {
        (*test_initCalled_o) = 0;
        if (corto_define(test_initCalled_o)) {
            corto_error("test_load: failed to define '/test/initCalled' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Line */
    test_Line_o = corto_declareChild(test_o, "Line", corto_struct_o);
    if (!test_Line_o) {
        corto_error("test_load: failed to declare '/test/Line' (%s)", corto_lasterr());
        goto error;
    }

    /* Declare /test/Line/start */
    test_Line_start_o = corto_declareChild(test_Line_o, "start", corto_member_o);
    if (!test_Line_start_o) {
        corto_error("test_load: failed to declare '/test/Line/start' (%s)", corto_lasterr());
        goto error;
    }

    /* Declare /test/Line/stop */
    test_Line_stop_o = corto_declareChild(test_Line_o, "stop", corto_member_o);
    if (!test_Line_stop_o) {
        corto_error("test_load: failed to declare '/test/Line/stop' (%s)", corto_lasterr());
        goto error;
    }

    /* Declare /test/MethodResolver */
    test_MethodResolver_o = corto_declareChild(test_o, "MethodResolver", test_Suite_o);
    if (!test_MethodResolver_o) {
        corto_error("test_load: failed to declare '/test/MethodResolver' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/MethodResolver */
    if (!corto_checkState(test_MethodResolver_o, CORTO_DEFINED)) {
        corto_type(test_MethodResolver_o)->parentType = NULL;
        corto_type(test_MethodResolver_o)->parentState = 0x6;
        corto_type(test_MethodResolver_o)->defaultType = NULL;
        corto_type(test_MethodResolver_o)->defaultProcedureType = NULL;
        corto_interface(test_MethodResolver_o)->base = corto_resolve(NULL, "/corto/test/SuiteData");
        corto_struct(test_MethodResolver_o)->baseAccess = 0x0;
        corto_class(test_MethodResolver_o)->implements.length = 0;
        corto_class(test_MethodResolver_o)->implements.buffer = NULL;
        if (corto_define(test_MethodResolver_o)) {
            corto_error("test_load: failed to define '/test/MethodResolver' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (corto_type(test_MethodResolver_o)->size != sizeof(struct test_MethodResolver_s)) {
        corto_error("test_load: calculated size '%d' of type '/test/MethodResolver' doesn't match C-type size '%d'", corto_type(test_MethodResolver_o)->size, sizeof(struct test_MethodResolver_s));
    }

    /* Declare /test/MethodResolver/tc_inheritOverload() */
    test_MethodResolver_tc_inheritOverload_o = corto_declareChild(test_MethodResolver_o, "tc_inheritOverload()", test_Case_o);
    if (!test_MethodResolver_tc_inheritOverload_o) {
        corto_error("test_load: failed to declare '/test/MethodResolver/tc_inheritOverload()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/MethodResolver/tc_inheritOverload() */
    if (!corto_checkState(test_MethodResolver_tc_inheritOverload_o, CORTO_DEFINED)) {
        corto_function(test_MethodResolver_tc_inheritOverload_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_MethodResolver_tc_inheritOverload_o)->returnsReference = FALSE;
        corto_method(test_MethodResolver_tc_inheritOverload_o)->_virtual = FALSE;
        
        /* Bind /test/MethodResolver/tc_inheritOverload() with C-function */
        corto_function(test_MethodResolver_tc_inheritOverload_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_MethodResolver_tc_inheritOverload(void *args, void *result);
        corto_function(test_MethodResolver_tc_inheritOverload_o)->impl = (corto_word)__test_MethodResolver_tc_inheritOverload;
        if (corto_define(test_MethodResolver_tc_inheritOverload_o)) {
            corto_error("test_load: failed to define '/test/MethodResolver/tc_inheritOverload()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/MethodResolver/tc_inheritOverloadBaseClass() */
    test_MethodResolver_tc_inheritOverloadBaseClass_o = corto_declareChild(test_MethodResolver_o, "tc_inheritOverloadBaseClass()", test_Case_o);
    if (!test_MethodResolver_tc_inheritOverloadBaseClass_o) {
        corto_error("test_load: failed to declare '/test/MethodResolver/tc_inheritOverloadBaseClass()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/MethodResolver/tc_inheritOverloadBaseClass() */
    if (!corto_checkState(test_MethodResolver_tc_inheritOverloadBaseClass_o, CORTO_DEFINED)) {
        corto_function(test_MethodResolver_tc_inheritOverloadBaseClass_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_MethodResolver_tc_inheritOverloadBaseClass_o)->returnsReference = FALSE;
        corto_method(test_MethodResolver_tc_inheritOverloadBaseClass_o)->_virtual = FALSE;
        
        /* Bind /test/MethodResolver/tc_inheritOverloadBaseClass() with C-function */
        corto_function(test_MethodResolver_tc_inheritOverloadBaseClass_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_MethodResolver_tc_inheritOverloadBaseClass(void *args, void *result);
        corto_function(test_MethodResolver_tc_inheritOverloadBaseClass_o)->impl = (corto_word)__test_MethodResolver_tc_inheritOverloadBaseClass;
        if (corto_define(test_MethodResolver_tc_inheritOverloadBaseClass_o)) {
            corto_error("test_load: failed to define '/test/MethodResolver/tc_inheritOverloadBaseClass()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/MethodResolver/tc_inheritOverloadBaseInt() */
    test_MethodResolver_tc_inheritOverloadBaseInt_o = corto_declareChild(test_MethodResolver_o, "tc_inheritOverloadBaseInt()", test_Case_o);
    if (!test_MethodResolver_tc_inheritOverloadBaseInt_o) {
        corto_error("test_load: failed to declare '/test/MethodResolver/tc_inheritOverloadBaseInt()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/MethodResolver/tc_inheritOverloadBaseInt() */
    if (!corto_checkState(test_MethodResolver_tc_inheritOverloadBaseInt_o, CORTO_DEFINED)) {
        corto_function(test_MethodResolver_tc_inheritOverloadBaseInt_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_MethodResolver_tc_inheritOverloadBaseInt_o)->returnsReference = FALSE;
        corto_method(test_MethodResolver_tc_inheritOverloadBaseInt_o)->_virtual = FALSE;
        
        /* Bind /test/MethodResolver/tc_inheritOverloadBaseInt() with C-function */
        corto_function(test_MethodResolver_tc_inheritOverloadBaseInt_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_MethodResolver_tc_inheritOverloadBaseInt(void *args, void *result);
        corto_function(test_MethodResolver_tc_inheritOverloadBaseInt_o)->impl = (corto_word)__test_MethodResolver_tc_inheritOverloadBaseInt;
        if (corto_define(test_MethodResolver_tc_inheritOverloadBaseInt_o)) {
            corto_error("test_load: failed to define '/test/MethodResolver/tc_inheritOverloadBaseInt()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/MethodResolver/tc_inheritOverloadBaseString() */
    test_MethodResolver_tc_inheritOverloadBaseString_o = corto_declareChild(test_MethodResolver_o, "tc_inheritOverloadBaseString()", test_Case_o);
    if (!test_MethodResolver_tc_inheritOverloadBaseString_o) {
        corto_error("test_load: failed to declare '/test/MethodResolver/tc_inheritOverloadBaseString()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/MethodResolver/tc_inheritOverloadBaseString() */
    if (!corto_checkState(test_MethodResolver_tc_inheritOverloadBaseString_o, CORTO_DEFINED)) {
        corto_function(test_MethodResolver_tc_inheritOverloadBaseString_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_MethodResolver_tc_inheritOverloadBaseString_o)->returnsReference = FALSE;
        corto_method(test_MethodResolver_tc_inheritOverloadBaseString_o)->_virtual = FALSE;
        
        /* Bind /test/MethodResolver/tc_inheritOverloadBaseString() with C-function */
        corto_function(test_MethodResolver_tc_inheritOverloadBaseString_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_MethodResolver_tc_inheritOverloadBaseString(void *args, void *result);
        corto_function(test_MethodResolver_tc_inheritOverloadBaseString_o)->impl = (corto_word)__test_MethodResolver_tc_inheritOverloadBaseString;
        if (corto_define(test_MethodResolver_tc_inheritOverloadBaseString_o)) {
            corto_error("test_load: failed to define '/test/MethodResolver/tc_inheritOverloadBaseString()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/MethodResolver/tc_inheritOverloadBaseTwoArgs() */
    test_MethodResolver_tc_inheritOverloadBaseTwoArgs_o = corto_declareChild(test_MethodResolver_o, "tc_inheritOverloadBaseTwoArgs()", test_Case_o);
    if (!test_MethodResolver_tc_inheritOverloadBaseTwoArgs_o) {
        corto_error("test_load: failed to declare '/test/MethodResolver/tc_inheritOverloadBaseTwoArgs()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/MethodResolver/tc_inheritOverloadBaseTwoArgs() */
    if (!corto_checkState(test_MethodResolver_tc_inheritOverloadBaseTwoArgs_o, CORTO_DEFINED)) {
        corto_function(test_MethodResolver_tc_inheritOverloadBaseTwoArgs_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_MethodResolver_tc_inheritOverloadBaseTwoArgs_o)->returnsReference = FALSE;
        corto_method(test_MethodResolver_tc_inheritOverloadBaseTwoArgs_o)->_virtual = FALSE;
        
        /* Bind /test/MethodResolver/tc_inheritOverloadBaseTwoArgs() with C-function */
        corto_function(test_MethodResolver_tc_inheritOverloadBaseTwoArgs_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_MethodResolver_tc_inheritOverloadBaseTwoArgs(void *args, void *result);
        corto_function(test_MethodResolver_tc_inheritOverloadBaseTwoArgs_o)->impl = (corto_word)__test_MethodResolver_tc_inheritOverloadBaseTwoArgs;
        if (corto_define(test_MethodResolver_tc_inheritOverloadBaseTwoArgs_o)) {
            corto_error("test_load: failed to define '/test/MethodResolver/tc_inheritOverloadBaseTwoArgs()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/MethodResolver/tc_inheritOverloadClass() */
    test_MethodResolver_tc_inheritOverloadClass_o = corto_declareChild(test_MethodResolver_o, "tc_inheritOverloadClass()", test_Case_o);
    if (!test_MethodResolver_tc_inheritOverloadClass_o) {
        corto_error("test_load: failed to declare '/test/MethodResolver/tc_inheritOverloadClass()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/MethodResolver/tc_inheritOverloadClass() */
    if (!corto_checkState(test_MethodResolver_tc_inheritOverloadClass_o, CORTO_DEFINED)) {
        corto_function(test_MethodResolver_tc_inheritOverloadClass_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_MethodResolver_tc_inheritOverloadClass_o)->returnsReference = FALSE;
        corto_method(test_MethodResolver_tc_inheritOverloadClass_o)->_virtual = FALSE;
        
        /* Bind /test/MethodResolver/tc_inheritOverloadClass() with C-function */
        corto_function(test_MethodResolver_tc_inheritOverloadClass_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_MethodResolver_tc_inheritOverloadClass(void *args, void *result);
        corto_function(test_MethodResolver_tc_inheritOverloadClass_o)->impl = (corto_word)__test_MethodResolver_tc_inheritOverloadClass;
        if (corto_define(test_MethodResolver_tc_inheritOverloadClass_o)) {
            corto_error("test_load: failed to define '/test/MethodResolver/tc_inheritOverloadClass()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/MethodResolver/tc_inheritOverloadNoArgs() */
    test_MethodResolver_tc_inheritOverloadNoArgs_o = corto_declareChild(test_MethodResolver_o, "tc_inheritOverloadNoArgs()", test_Case_o);
    if (!test_MethodResolver_tc_inheritOverloadNoArgs_o) {
        corto_error("test_load: failed to declare '/test/MethodResolver/tc_inheritOverloadNoArgs()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/MethodResolver/tc_inheritOverloadNoArgs() */
    if (!corto_checkState(test_MethodResolver_tc_inheritOverloadNoArgs_o, CORTO_DEFINED)) {
        corto_function(test_MethodResolver_tc_inheritOverloadNoArgs_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_MethodResolver_tc_inheritOverloadNoArgs_o)->returnsReference = FALSE;
        corto_method(test_MethodResolver_tc_inheritOverloadNoArgs_o)->_virtual = FALSE;
        
        /* Bind /test/MethodResolver/tc_inheritOverloadNoArgs() with C-function */
        corto_function(test_MethodResolver_tc_inheritOverloadNoArgs_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_MethodResolver_tc_inheritOverloadNoArgs(void *args, void *result);
        corto_function(test_MethodResolver_tc_inheritOverloadNoArgs_o)->impl = (corto_word)__test_MethodResolver_tc_inheritOverloadNoArgs;
        if (corto_define(test_MethodResolver_tc_inheritOverloadNoArgs_o)) {
            corto_error("test_load: failed to define '/test/MethodResolver/tc_inheritOverloadNoArgs()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/MethodResolver/tc_inheritSimple() */
    test_MethodResolver_tc_inheritSimple_o = corto_declareChild(test_MethodResolver_o, "tc_inheritSimple()", test_Case_o);
    if (!test_MethodResolver_tc_inheritSimple_o) {
        corto_error("test_load: failed to declare '/test/MethodResolver/tc_inheritSimple()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/MethodResolver/tc_inheritSimple() */
    if (!corto_checkState(test_MethodResolver_tc_inheritSimple_o, CORTO_DEFINED)) {
        corto_function(test_MethodResolver_tc_inheritSimple_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_MethodResolver_tc_inheritSimple_o)->returnsReference = FALSE;
        corto_method(test_MethodResolver_tc_inheritSimple_o)->_virtual = FALSE;
        
        /* Bind /test/MethodResolver/tc_inheritSimple() with C-function */
        corto_function(test_MethodResolver_tc_inheritSimple_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_MethodResolver_tc_inheritSimple(void *args, void *result);
        corto_function(test_MethodResolver_tc_inheritSimple_o)->impl = (corto_word)__test_MethodResolver_tc_inheritSimple;
        if (corto_define(test_MethodResolver_tc_inheritSimple_o)) {
            corto_error("test_load: failed to define '/test/MethodResolver/tc_inheritSimple()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/MethodResolver/tc_inheritSimpleNoArgs() */
    test_MethodResolver_tc_inheritSimpleNoArgs_o = corto_declareChild(test_MethodResolver_o, "tc_inheritSimpleNoArgs()", test_Case_o);
    if (!test_MethodResolver_tc_inheritSimpleNoArgs_o) {
        corto_error("test_load: failed to declare '/test/MethodResolver/tc_inheritSimpleNoArgs()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/MethodResolver/tc_inheritSimpleNoArgs() */
    if (!corto_checkState(test_MethodResolver_tc_inheritSimpleNoArgs_o, CORTO_DEFINED)) {
        corto_function(test_MethodResolver_tc_inheritSimpleNoArgs_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_MethodResolver_tc_inheritSimpleNoArgs_o)->returnsReference = FALSE;
        corto_method(test_MethodResolver_tc_inheritSimpleNoArgs_o)->_virtual = FALSE;
        
        /* Bind /test/MethodResolver/tc_inheritSimpleNoArgs() with C-function */
        corto_function(test_MethodResolver_tc_inheritSimpleNoArgs_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_MethodResolver_tc_inheritSimpleNoArgs(void *args, void *result);
        corto_function(test_MethodResolver_tc_inheritSimpleNoArgs_o)->impl = (corto_word)__test_MethodResolver_tc_inheritSimpleNoArgs;
        if (corto_define(test_MethodResolver_tc_inheritSimpleNoArgs_o)) {
            corto_error("test_load: failed to define '/test/MethodResolver/tc_inheritSimpleNoArgs()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/MethodResolver/tc_inheritVirtualOverload() */
    test_MethodResolver_tc_inheritVirtualOverload_o = corto_declareChild(test_MethodResolver_o, "tc_inheritVirtualOverload()", test_Case_o);
    if (!test_MethodResolver_tc_inheritVirtualOverload_o) {
        corto_error("test_load: failed to declare '/test/MethodResolver/tc_inheritVirtualOverload()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/MethodResolver/tc_inheritVirtualOverload() */
    if (!corto_checkState(test_MethodResolver_tc_inheritVirtualOverload_o, CORTO_DEFINED)) {
        corto_function(test_MethodResolver_tc_inheritVirtualOverload_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_MethodResolver_tc_inheritVirtualOverload_o)->returnsReference = FALSE;
        corto_method(test_MethodResolver_tc_inheritVirtualOverload_o)->_virtual = FALSE;
        
        /* Bind /test/MethodResolver/tc_inheritVirtualOverload() with C-function */
        corto_function(test_MethodResolver_tc_inheritVirtualOverload_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_MethodResolver_tc_inheritVirtualOverload(void *args, void *result);
        corto_function(test_MethodResolver_tc_inheritVirtualOverload_o)->impl = (corto_word)__test_MethodResolver_tc_inheritVirtualOverload;
        if (corto_define(test_MethodResolver_tc_inheritVirtualOverload_o)) {
            corto_error("test_load: failed to define '/test/MethodResolver/tc_inheritVirtualOverload()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/MethodResolver/tc_inheritVirtualOverloadNoArgs() */
    test_MethodResolver_tc_inheritVirtualOverloadNoArgs_o = corto_declareChild(test_MethodResolver_o, "tc_inheritVirtualOverloadNoArgs()", test_Case_o);
    if (!test_MethodResolver_tc_inheritVirtualOverloadNoArgs_o) {
        corto_error("test_load: failed to declare '/test/MethodResolver/tc_inheritVirtualOverloadNoArgs()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/MethodResolver/tc_inheritVirtualOverloadNoArgs() */
    if (!corto_checkState(test_MethodResolver_tc_inheritVirtualOverloadNoArgs_o, CORTO_DEFINED)) {
        corto_function(test_MethodResolver_tc_inheritVirtualOverloadNoArgs_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_MethodResolver_tc_inheritVirtualOverloadNoArgs_o)->returnsReference = FALSE;
        corto_method(test_MethodResolver_tc_inheritVirtualOverloadNoArgs_o)->_virtual = FALSE;
        
        /* Bind /test/MethodResolver/tc_inheritVirtualOverloadNoArgs() with C-function */
        corto_function(test_MethodResolver_tc_inheritVirtualOverloadNoArgs_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_MethodResolver_tc_inheritVirtualOverloadNoArgs(void *args, void *result);
        corto_function(test_MethodResolver_tc_inheritVirtualOverloadNoArgs_o)->impl = (corto_word)__test_MethodResolver_tc_inheritVirtualOverloadNoArgs;
        if (corto_define(test_MethodResolver_tc_inheritVirtualOverloadNoArgs_o)) {
            corto_error("test_load: failed to define '/test/MethodResolver/tc_inheritVirtualOverloadNoArgs()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/MethodResolver/tc_nonexisting() */
    test_MethodResolver_tc_nonexisting_o = corto_declareChild(test_MethodResolver_o, "tc_nonexisting()", test_Case_o);
    if (!test_MethodResolver_tc_nonexisting_o) {
        corto_error("test_load: failed to declare '/test/MethodResolver/tc_nonexisting()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/MethodResolver/tc_nonexisting() */
    if (!corto_checkState(test_MethodResolver_tc_nonexisting_o, CORTO_DEFINED)) {
        corto_function(test_MethodResolver_tc_nonexisting_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_MethodResolver_tc_nonexisting_o)->returnsReference = FALSE;
        corto_method(test_MethodResolver_tc_nonexisting_o)->_virtual = FALSE;
        
        /* Bind /test/MethodResolver/tc_nonexisting() with C-function */
        corto_function(test_MethodResolver_tc_nonexisting_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_MethodResolver_tc_nonexisting(void *args, void *result);
        corto_function(test_MethodResolver_tc_nonexisting_o)->impl = (corto_word)__test_MethodResolver_tc_nonexisting;
        if (corto_define(test_MethodResolver_tc_nonexisting_o)) {
            corto_error("test_load: failed to define '/test/MethodResolver/tc_nonexisting()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/MethodResolver/tc_onearg() */
    test_MethodResolver_tc_onearg_o = corto_declareChild(test_MethodResolver_o, "tc_onearg()", test_Case_o);
    if (!test_MethodResolver_tc_onearg_o) {
        corto_error("test_load: failed to declare '/test/MethodResolver/tc_onearg()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/MethodResolver/tc_onearg() */
    if (!corto_checkState(test_MethodResolver_tc_onearg_o, CORTO_DEFINED)) {
        corto_function(test_MethodResolver_tc_onearg_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_MethodResolver_tc_onearg_o)->returnsReference = FALSE;
        corto_method(test_MethodResolver_tc_onearg_o)->_virtual = FALSE;
        
        /* Bind /test/MethodResolver/tc_onearg() with C-function */
        corto_function(test_MethodResolver_tc_onearg_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_MethodResolver_tc_onearg(void *args, void *result);
        corto_function(test_MethodResolver_tc_onearg_o)->impl = (corto_word)__test_MethodResolver_tc_onearg;
        if (corto_define(test_MethodResolver_tc_onearg_o)) {
            corto_error("test_load: failed to define '/test/MethodResolver/tc_onearg()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/MethodResolver/tc_oneargErr() */
    test_MethodResolver_tc_oneargErr_o = corto_declareChild(test_MethodResolver_o, "tc_oneargErr()", test_Case_o);
    if (!test_MethodResolver_tc_oneargErr_o) {
        corto_error("test_load: failed to declare '/test/MethodResolver/tc_oneargErr()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/MethodResolver/tc_oneargErr() */
    if (!corto_checkState(test_MethodResolver_tc_oneargErr_o, CORTO_DEFINED)) {
        corto_function(test_MethodResolver_tc_oneargErr_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_MethodResolver_tc_oneargErr_o)->returnsReference = FALSE;
        corto_method(test_MethodResolver_tc_oneargErr_o)->_virtual = FALSE;
        
        /* Bind /test/MethodResolver/tc_oneargErr() with C-function */
        corto_function(test_MethodResolver_tc_oneargErr_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_MethodResolver_tc_oneargErr(void *args, void *result);
        corto_function(test_MethodResolver_tc_oneargErr_o)->impl = (corto_word)__test_MethodResolver_tc_oneargErr;
        if (corto_define(test_MethodResolver_tc_oneargErr_o)) {
            corto_error("test_load: failed to define '/test/MethodResolver/tc_oneargErr()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/MethodResolver/tc_oneargErrType() */
    test_MethodResolver_tc_oneargErrType_o = corto_declareChild(test_MethodResolver_o, "tc_oneargErrType()", test_Case_o);
    if (!test_MethodResolver_tc_oneargErrType_o) {
        corto_error("test_load: failed to declare '/test/MethodResolver/tc_oneargErrType()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/MethodResolver/tc_oneargErrType() */
    if (!corto_checkState(test_MethodResolver_tc_oneargErrType_o, CORTO_DEFINED)) {
        corto_function(test_MethodResolver_tc_oneargErrType_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_MethodResolver_tc_oneargErrType_o)->returnsReference = FALSE;
        corto_method(test_MethodResolver_tc_oneargErrType_o)->_virtual = FALSE;
        
        /* Bind /test/MethodResolver/tc_oneargErrType() with C-function */
        corto_function(test_MethodResolver_tc_oneargErrType_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_MethodResolver_tc_oneargErrType(void *args, void *result);
        corto_function(test_MethodResolver_tc_oneargErrType_o)->impl = (corto_word)__test_MethodResolver_tc_oneargErrType;
        if (corto_define(test_MethodResolver_tc_oneargErrType_o)) {
            corto_error("test_load: failed to define '/test/MethodResolver/tc_oneargErrType()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/MethodResolver/tc_oneargNoArgs() */
    test_MethodResolver_tc_oneargNoArgs_o = corto_declareChild(test_MethodResolver_o, "tc_oneargNoArgs()", test_Case_o);
    if (!test_MethodResolver_tc_oneargNoArgs_o) {
        corto_error("test_load: failed to declare '/test/MethodResolver/tc_oneargNoArgs()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/MethodResolver/tc_oneargNoArgs() */
    if (!corto_checkState(test_MethodResolver_tc_oneargNoArgs_o, CORTO_DEFINED)) {
        corto_function(test_MethodResolver_tc_oneargNoArgs_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_MethodResolver_tc_oneargNoArgs_o)->returnsReference = FALSE;
        corto_method(test_MethodResolver_tc_oneargNoArgs_o)->_virtual = FALSE;
        
        /* Bind /test/MethodResolver/tc_oneargNoArgs() with C-function */
        corto_function(test_MethodResolver_tc_oneargNoArgs_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_MethodResolver_tc_oneargNoArgs(void *args, void *result);
        corto_function(test_MethodResolver_tc_oneargNoArgs_o)->impl = (corto_word)__test_MethodResolver_tc_oneargNoArgs;
        if (corto_define(test_MethodResolver_tc_oneargNoArgs_o)) {
            corto_error("test_load: failed to define '/test/MethodResolver/tc_oneargNoArgs()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/MethodResolver/tc_overloadAmbiguous() */
    test_MethodResolver_tc_overloadAmbiguous_o = corto_declareChild(test_MethodResolver_o, "tc_overloadAmbiguous()", test_Case_o);
    if (!test_MethodResolver_tc_overloadAmbiguous_o) {
        corto_error("test_load: failed to declare '/test/MethodResolver/tc_overloadAmbiguous()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/MethodResolver/tc_overloadAmbiguous() */
    if (!corto_checkState(test_MethodResolver_tc_overloadAmbiguous_o, CORTO_DEFINED)) {
        corto_function(test_MethodResolver_tc_overloadAmbiguous_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_MethodResolver_tc_overloadAmbiguous_o)->returnsReference = FALSE;
        corto_method(test_MethodResolver_tc_overloadAmbiguous_o)->_virtual = FALSE;
        
        /* Bind /test/MethodResolver/tc_overloadAmbiguous() with C-function */
        corto_function(test_MethodResolver_tc_overloadAmbiguous_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_MethodResolver_tc_overloadAmbiguous(void *args, void *result);
        corto_function(test_MethodResolver_tc_overloadAmbiguous_o)->impl = (corto_word)__test_MethodResolver_tc_overloadAmbiguous;
        if (corto_define(test_MethodResolver_tc_overloadAmbiguous_o)) {
            corto_error("test_load: failed to define '/test/MethodResolver/tc_overloadAmbiguous()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/MethodResolver/tc_overloadClass() */
    test_MethodResolver_tc_overloadClass_o = corto_declareChild(test_MethodResolver_o, "tc_overloadClass()", test_Case_o);
    if (!test_MethodResolver_tc_overloadClass_o) {
        corto_error("test_load: failed to declare '/test/MethodResolver/tc_overloadClass()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/MethodResolver/tc_overloadClass() */
    if (!corto_checkState(test_MethodResolver_tc_overloadClass_o, CORTO_DEFINED)) {
        corto_function(test_MethodResolver_tc_overloadClass_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_MethodResolver_tc_overloadClass_o)->returnsReference = FALSE;
        corto_method(test_MethodResolver_tc_overloadClass_o)->_virtual = FALSE;
        
        /* Bind /test/MethodResolver/tc_overloadClass() with C-function */
        corto_function(test_MethodResolver_tc_overloadClass_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_MethodResolver_tc_overloadClass(void *args, void *result);
        corto_function(test_MethodResolver_tc_overloadClass_o)->impl = (corto_word)__test_MethodResolver_tc_overloadClass;
        if (corto_define(test_MethodResolver_tc_overloadClass_o)) {
            corto_error("test_load: failed to define '/test/MethodResolver/tc_overloadClass()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/MethodResolver/tc_overloadInt() */
    test_MethodResolver_tc_overloadInt_o = corto_declareChild(test_MethodResolver_o, "tc_overloadInt()", test_Case_o);
    if (!test_MethodResolver_tc_overloadInt_o) {
        corto_error("test_load: failed to declare '/test/MethodResolver/tc_overloadInt()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/MethodResolver/tc_overloadInt() */
    if (!corto_checkState(test_MethodResolver_tc_overloadInt_o, CORTO_DEFINED)) {
        corto_function(test_MethodResolver_tc_overloadInt_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_MethodResolver_tc_overloadInt_o)->returnsReference = FALSE;
        corto_method(test_MethodResolver_tc_overloadInt_o)->_virtual = FALSE;
        
        /* Bind /test/MethodResolver/tc_overloadInt() with C-function */
        corto_function(test_MethodResolver_tc_overloadInt_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_MethodResolver_tc_overloadInt(void *args, void *result);
        corto_function(test_MethodResolver_tc_overloadInt_o)->impl = (corto_word)__test_MethodResolver_tc_overloadInt;
        if (corto_define(test_MethodResolver_tc_overloadInt_o)) {
            corto_error("test_load: failed to define '/test/MethodResolver/tc_overloadInt()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/MethodResolver/tc_overloadString() */
    test_MethodResolver_tc_overloadString_o = corto_declareChild(test_MethodResolver_o, "tc_overloadString()", test_Case_o);
    if (!test_MethodResolver_tc_overloadString_o) {
        corto_error("test_load: failed to declare '/test/MethodResolver/tc_overloadString()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/MethodResolver/tc_overloadString() */
    if (!corto_checkState(test_MethodResolver_tc_overloadString_o, CORTO_DEFINED)) {
        corto_function(test_MethodResolver_tc_overloadString_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_MethodResolver_tc_overloadString_o)->returnsReference = FALSE;
        corto_method(test_MethodResolver_tc_overloadString_o)->_virtual = FALSE;
        
        /* Bind /test/MethodResolver/tc_overloadString() with C-function */
        corto_function(test_MethodResolver_tc_overloadString_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_MethodResolver_tc_overloadString(void *args, void *result);
        corto_function(test_MethodResolver_tc_overloadString_o)->impl = (corto_word)__test_MethodResolver_tc_overloadString;
        if (corto_define(test_MethodResolver_tc_overloadString_o)) {
            corto_error("test_load: failed to define '/test/MethodResolver/tc_overloadString()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/MethodResolver/tc_overloadTwoArgs() */
    test_MethodResolver_tc_overloadTwoArgs_o = corto_declareChild(test_MethodResolver_o, "tc_overloadTwoArgs()", test_Case_o);
    if (!test_MethodResolver_tc_overloadTwoArgs_o) {
        corto_error("test_load: failed to declare '/test/MethodResolver/tc_overloadTwoArgs()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/MethodResolver/tc_overloadTwoArgs() */
    if (!corto_checkState(test_MethodResolver_tc_overloadTwoArgs_o, CORTO_DEFINED)) {
        corto_function(test_MethodResolver_tc_overloadTwoArgs_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_MethodResolver_tc_overloadTwoArgs_o)->returnsReference = FALSE;
        corto_method(test_MethodResolver_tc_overloadTwoArgs_o)->_virtual = FALSE;
        
        /* Bind /test/MethodResolver/tc_overloadTwoArgs() with C-function */
        corto_function(test_MethodResolver_tc_overloadTwoArgs_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_MethodResolver_tc_overloadTwoArgs(void *args, void *result);
        corto_function(test_MethodResolver_tc_overloadTwoArgs_o)->impl = (corto_word)__test_MethodResolver_tc_overloadTwoArgs;
        if (corto_define(test_MethodResolver_tc_overloadTwoArgs_o)) {
            corto_error("test_load: failed to define '/test/MethodResolver/tc_overloadTwoArgs()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/MethodResolver/tc_redeclare() */
    test_MethodResolver_tc_redeclare_o = corto_declareChild(test_MethodResolver_o, "tc_redeclare()", test_Case_o);
    if (!test_MethodResolver_tc_redeclare_o) {
        corto_error("test_load: failed to declare '/test/MethodResolver/tc_redeclare()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/MethodResolver/tc_redeclare() */
    if (!corto_checkState(test_MethodResolver_tc_redeclare_o, CORTO_DEFINED)) {
        corto_function(test_MethodResolver_tc_redeclare_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_MethodResolver_tc_redeclare_o)->returnsReference = FALSE;
        corto_method(test_MethodResolver_tc_redeclare_o)->_virtual = FALSE;
        
        /* Bind /test/MethodResolver/tc_redeclare() with C-function */
        corto_function(test_MethodResolver_tc_redeclare_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_MethodResolver_tc_redeclare(void *args, void *result);
        corto_function(test_MethodResolver_tc_redeclare_o)->impl = (corto_word)__test_MethodResolver_tc_redeclare;
        if (corto_define(test_MethodResolver_tc_redeclare_o)) {
            corto_error("test_load: failed to define '/test/MethodResolver/tc_redeclare()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/MethodResolver/tc_simple() */
    test_MethodResolver_tc_simple_o = corto_declareChild(test_MethodResolver_o, "tc_simple()", test_Case_o);
    if (!test_MethodResolver_tc_simple_o) {
        corto_error("test_load: failed to declare '/test/MethodResolver/tc_simple()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/MethodResolver/tc_simple() */
    if (!corto_checkState(test_MethodResolver_tc_simple_o, CORTO_DEFINED)) {
        corto_function(test_MethodResolver_tc_simple_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_MethodResolver_tc_simple_o)->returnsReference = FALSE;
        corto_method(test_MethodResolver_tc_simple_o)->_virtual = FALSE;
        
        /* Bind /test/MethodResolver/tc_simple() with C-function */
        corto_function(test_MethodResolver_tc_simple_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_MethodResolver_tc_simple(void *args, void *result);
        corto_function(test_MethodResolver_tc_simple_o)->impl = (corto_word)__test_MethodResolver_tc_simple;
        if (corto_define(test_MethodResolver_tc_simple_o)) {
            corto_error("test_load: failed to define '/test/MethodResolver/tc_simple()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/MethodResolver/tc_simpleErr() */
    test_MethodResolver_tc_simpleErr_o = corto_declareChild(test_MethodResolver_o, "tc_simpleErr()", test_Case_o);
    if (!test_MethodResolver_tc_simpleErr_o) {
        corto_error("test_load: failed to declare '/test/MethodResolver/tc_simpleErr()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/MethodResolver/tc_simpleErr() */
    if (!corto_checkState(test_MethodResolver_tc_simpleErr_o, CORTO_DEFINED)) {
        corto_function(test_MethodResolver_tc_simpleErr_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_MethodResolver_tc_simpleErr_o)->returnsReference = FALSE;
        corto_method(test_MethodResolver_tc_simpleErr_o)->_virtual = FALSE;
        
        /* Bind /test/MethodResolver/tc_simpleErr() with C-function */
        corto_function(test_MethodResolver_tc_simpleErr_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_MethodResolver_tc_simpleErr(void *args, void *result);
        corto_function(test_MethodResolver_tc_simpleErr_o)->impl = (corto_word)__test_MethodResolver_tc_simpleErr;
        if (corto_define(test_MethodResolver_tc_simpleErr_o)) {
            corto_error("test_load: failed to define '/test/MethodResolver/tc_simpleErr()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/MethodResolver/tc_simpleErrType() */
    test_MethodResolver_tc_simpleErrType_o = corto_declareChild(test_MethodResolver_o, "tc_simpleErrType()", test_Case_o);
    if (!test_MethodResolver_tc_simpleErrType_o) {
        corto_error("test_load: failed to declare '/test/MethodResolver/tc_simpleErrType()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/MethodResolver/tc_simpleErrType() */
    if (!corto_checkState(test_MethodResolver_tc_simpleErrType_o, CORTO_DEFINED)) {
        corto_function(test_MethodResolver_tc_simpleErrType_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_MethodResolver_tc_simpleErrType_o)->returnsReference = FALSE;
        corto_method(test_MethodResolver_tc_simpleErrType_o)->_virtual = FALSE;
        
        /* Bind /test/MethodResolver/tc_simpleErrType() with C-function */
        corto_function(test_MethodResolver_tc_simpleErrType_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_MethodResolver_tc_simpleErrType(void *args, void *result);
        corto_function(test_MethodResolver_tc_simpleErrType_o)->impl = (corto_word)__test_MethodResolver_tc_simpleErrType;
        if (corto_define(test_MethodResolver_tc_simpleErrType_o)) {
            corto_error("test_load: failed to define '/test/MethodResolver/tc_simpleErrType()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/MethodResolver/tc_simpleNoArgs() */
    test_MethodResolver_tc_simpleNoArgs_o = corto_declareChild(test_MethodResolver_o, "tc_simpleNoArgs()", test_Case_o);
    if (!test_MethodResolver_tc_simpleNoArgs_o) {
        corto_error("test_load: failed to declare '/test/MethodResolver/tc_simpleNoArgs()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/MethodResolver/tc_simpleNoArgs() */
    if (!corto_checkState(test_MethodResolver_tc_simpleNoArgs_o, CORTO_DEFINED)) {
        corto_function(test_MethodResolver_tc_simpleNoArgs_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_MethodResolver_tc_simpleNoArgs_o)->returnsReference = FALSE;
        corto_method(test_MethodResolver_tc_simpleNoArgs_o)->_virtual = FALSE;
        
        /* Bind /test/MethodResolver/tc_simpleNoArgs() with C-function */
        corto_function(test_MethodResolver_tc_simpleNoArgs_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_MethodResolver_tc_simpleNoArgs(void *args, void *result);
        corto_function(test_MethodResolver_tc_simpleNoArgs_o)->impl = (corto_word)__test_MethodResolver_tc_simpleNoArgs;
        if (corto_define(test_MethodResolver_tc_simpleNoArgs_o)) {
            corto_error("test_load: failed to define '/test/MethodResolver/tc_simpleNoArgs()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/MethodResolver/tc_twoargs() */
    test_MethodResolver_tc_twoargs_o = corto_declareChild(test_MethodResolver_o, "tc_twoargs()", test_Case_o);
    if (!test_MethodResolver_tc_twoargs_o) {
        corto_error("test_load: failed to declare '/test/MethodResolver/tc_twoargs()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/MethodResolver/tc_twoargs() */
    if (!corto_checkState(test_MethodResolver_tc_twoargs_o, CORTO_DEFINED)) {
        corto_function(test_MethodResolver_tc_twoargs_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_MethodResolver_tc_twoargs_o)->returnsReference = FALSE;
        corto_method(test_MethodResolver_tc_twoargs_o)->_virtual = FALSE;
        
        /* Bind /test/MethodResolver/tc_twoargs() with C-function */
        corto_function(test_MethodResolver_tc_twoargs_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_MethodResolver_tc_twoargs(void *args, void *result);
        corto_function(test_MethodResolver_tc_twoargs_o)->impl = (corto_word)__test_MethodResolver_tc_twoargs;
        if (corto_define(test_MethodResolver_tc_twoargs_o)) {
            corto_error("test_load: failed to define '/test/MethodResolver/tc_twoargs()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/MethodResolver/tc_twoargsNoArgs() */
    test_MethodResolver_tc_twoargsNoArgs_o = corto_declareChild(test_MethodResolver_o, "tc_twoargsNoArgs()", test_Case_o);
    if (!test_MethodResolver_tc_twoargsNoArgs_o) {
        corto_error("test_load: failed to declare '/test/MethodResolver/tc_twoargsNoArgs()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/MethodResolver/tc_twoargsNoArgs() */
    if (!corto_checkState(test_MethodResolver_tc_twoargsNoArgs_o, CORTO_DEFINED)) {
        corto_function(test_MethodResolver_tc_twoargsNoArgs_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_MethodResolver_tc_twoargsNoArgs_o)->returnsReference = FALSE;
        corto_method(test_MethodResolver_tc_twoargsNoArgs_o)->_virtual = FALSE;
        
        /* Bind /test/MethodResolver/tc_twoargsNoArgs() with C-function */
        corto_function(test_MethodResolver_tc_twoargsNoArgs_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_MethodResolver_tc_twoargsNoArgs(void *args, void *result);
        corto_function(test_MethodResolver_tc_twoargsNoArgs_o)->impl = (corto_word)__test_MethodResolver_tc_twoargsNoArgs;
        if (corto_define(test_MethodResolver_tc_twoargsNoArgs_o)) {
            corto_error("test_load: failed to define '/test/MethodResolver/tc_twoargsNoArgs()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/MethodResolver/tc_twoargsSpaces() */
    test_MethodResolver_tc_twoargsSpaces_o = corto_declareChild(test_MethodResolver_o, "tc_twoargsSpaces()", test_Case_o);
    if (!test_MethodResolver_tc_twoargsSpaces_o) {
        corto_error("test_load: failed to declare '/test/MethodResolver/tc_twoargsSpaces()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/MethodResolver/tc_twoargsSpaces() */
    if (!corto_checkState(test_MethodResolver_tc_twoargsSpaces_o, CORTO_DEFINED)) {
        corto_function(test_MethodResolver_tc_twoargsSpaces_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_MethodResolver_tc_twoargsSpaces_o)->returnsReference = FALSE;
        corto_method(test_MethodResolver_tc_twoargsSpaces_o)->_virtual = FALSE;
        
        /* Bind /test/MethodResolver/tc_twoargsSpaces() with C-function */
        corto_function(test_MethodResolver_tc_twoargsSpaces_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_MethodResolver_tc_twoargsSpaces(void *args, void *result);
        corto_function(test_MethodResolver_tc_twoargsSpaces_o)->impl = (corto_word)__test_MethodResolver_tc_twoargsSpaces;
        if (corto_define(test_MethodResolver_tc_twoargsSpaces_o)) {
            corto_error("test_load: failed to define '/test/MethodResolver/tc_twoargsSpaces()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/MethodResolver/tc_virtualOverload() */
    test_MethodResolver_tc_virtualOverload_o = corto_declareChild(test_MethodResolver_o, "tc_virtualOverload()", test_Case_o);
    if (!test_MethodResolver_tc_virtualOverload_o) {
        corto_error("test_load: failed to declare '/test/MethodResolver/tc_virtualOverload()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/MethodResolver/tc_virtualOverload() */
    if (!corto_checkState(test_MethodResolver_tc_virtualOverload_o, CORTO_DEFINED)) {
        corto_function(test_MethodResolver_tc_virtualOverload_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_MethodResolver_tc_virtualOverload_o)->returnsReference = FALSE;
        corto_method(test_MethodResolver_tc_virtualOverload_o)->_virtual = FALSE;
        
        /* Bind /test/MethodResolver/tc_virtualOverload() with C-function */
        corto_function(test_MethodResolver_tc_virtualOverload_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_MethodResolver_tc_virtualOverload(void *args, void *result);
        corto_function(test_MethodResolver_tc_virtualOverload_o)->impl = (corto_word)__test_MethodResolver_tc_virtualOverload;
        if (corto_define(test_MethodResolver_tc_virtualOverload_o)) {
            corto_error("test_load: failed to define '/test/MethodResolver/tc_virtualOverload()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/MethodResolver/tc_virtualOverloadArg() */
    test_MethodResolver_tc_virtualOverloadArg_o = corto_declareChild(test_MethodResolver_o, "tc_virtualOverloadArg()", test_Case_o);
    if (!test_MethodResolver_tc_virtualOverloadArg_o) {
        corto_error("test_load: failed to declare '/test/MethodResolver/tc_virtualOverloadArg()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/MethodResolver/tc_virtualOverloadArg() */
    if (!corto_checkState(test_MethodResolver_tc_virtualOverloadArg_o, CORTO_DEFINED)) {
        corto_function(test_MethodResolver_tc_virtualOverloadArg_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_MethodResolver_tc_virtualOverloadArg_o)->returnsReference = FALSE;
        corto_method(test_MethodResolver_tc_virtualOverloadArg_o)->_virtual = FALSE;
        
        /* Bind /test/MethodResolver/tc_virtualOverloadArg() with C-function */
        corto_function(test_MethodResolver_tc_virtualOverloadArg_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_MethodResolver_tc_virtualOverloadArg(void *args, void *result);
        corto_function(test_MethodResolver_tc_virtualOverloadArg_o)->impl = (corto_word)__test_MethodResolver_tc_virtualOverloadArg;
        if (corto_define(test_MethodResolver_tc_virtualOverloadArg_o)) {
            corto_error("test_load: failed to define '/test/MethodResolver/tc_virtualOverloadArg()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/MethodResolver/tc_virtualOverloadNoArgs() */
    test_MethodResolver_tc_virtualOverloadNoArgs_o = corto_declareChild(test_MethodResolver_o, "tc_virtualOverloadNoArgs()", test_Case_o);
    if (!test_MethodResolver_tc_virtualOverloadNoArgs_o) {
        corto_error("test_load: failed to declare '/test/MethodResolver/tc_virtualOverloadNoArgs()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/MethodResolver/tc_virtualOverloadNoArgs() */
    if (!corto_checkState(test_MethodResolver_tc_virtualOverloadNoArgs_o, CORTO_DEFINED)) {
        corto_function(test_MethodResolver_tc_virtualOverloadNoArgs_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_MethodResolver_tc_virtualOverloadNoArgs_o)->returnsReference = FALSE;
        corto_method(test_MethodResolver_tc_virtualOverloadNoArgs_o)->_virtual = FALSE;
        
        /* Bind /test/MethodResolver/tc_virtualOverloadNoArgs() with C-function */
        corto_function(test_MethodResolver_tc_virtualOverloadNoArgs_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_MethodResolver_tc_virtualOverloadNoArgs(void *args, void *result);
        corto_function(test_MethodResolver_tc_virtualOverloadNoArgs_o)->impl = (corto_word)__test_MethodResolver_tc_virtualOverloadNoArgs;
        if (corto_define(test_MethodResolver_tc_virtualOverloadNoArgs_o)) {
            corto_error("test_load: failed to define '/test/MethodResolver/tc_virtualOverloadNoArgs()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/MethodResolver/tc_virtualSimple() */
    test_MethodResolver_tc_virtualSimple_o = corto_declareChild(test_MethodResolver_o, "tc_virtualSimple()", test_Case_o);
    if (!test_MethodResolver_tc_virtualSimple_o) {
        corto_error("test_load: failed to declare '/test/MethodResolver/tc_virtualSimple()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/MethodResolver/tc_virtualSimple() */
    if (!corto_checkState(test_MethodResolver_tc_virtualSimple_o, CORTO_DEFINED)) {
        corto_function(test_MethodResolver_tc_virtualSimple_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_MethodResolver_tc_virtualSimple_o)->returnsReference = FALSE;
        corto_method(test_MethodResolver_tc_virtualSimple_o)->_virtual = FALSE;
        
        /* Bind /test/MethodResolver/tc_virtualSimple() with C-function */
        corto_function(test_MethodResolver_tc_virtualSimple_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_MethodResolver_tc_virtualSimple(void *args, void *result);
        corto_function(test_MethodResolver_tc_virtualSimple_o)->impl = (corto_word)__test_MethodResolver_tc_virtualSimple;
        if (corto_define(test_MethodResolver_tc_virtualSimple_o)) {
            corto_error("test_load: failed to define '/test/MethodResolver/tc_virtualSimple()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/MethodResolver/tc_virtualSimpleNoArgs() */
    test_MethodResolver_tc_virtualSimpleNoArgs_o = corto_declareChild(test_MethodResolver_o, "tc_virtualSimpleNoArgs()", test_Case_o);
    if (!test_MethodResolver_tc_virtualSimpleNoArgs_o) {
        corto_error("test_load: failed to declare '/test/MethodResolver/tc_virtualSimpleNoArgs()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/MethodResolver/tc_virtualSimpleNoArgs() */
    if (!corto_checkState(test_MethodResolver_tc_virtualSimpleNoArgs_o, CORTO_DEFINED)) {
        corto_function(test_MethodResolver_tc_virtualSimpleNoArgs_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_MethodResolver_tc_virtualSimpleNoArgs_o)->returnsReference = FALSE;
        corto_method(test_MethodResolver_tc_virtualSimpleNoArgs_o)->_virtual = FALSE;
        
        /* Bind /test/MethodResolver/tc_virtualSimpleNoArgs() with C-function */
        corto_function(test_MethodResolver_tc_virtualSimpleNoArgs_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_MethodResolver_tc_virtualSimpleNoArgs(void *args, void *result);
        corto_function(test_MethodResolver_tc_virtualSimpleNoArgs_o)->impl = (corto_word)__test_MethodResolver_tc_virtualSimpleNoArgs;
        if (corto_define(test_MethodResolver_tc_virtualSimpleNoArgs_o)) {
            corto_error("test_load: failed to define '/test/MethodResolver/tc_virtualSimpleNoArgs()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/MethodTester */
    test_MethodTester_o = corto_declareChild(test_o, "MethodTester", corto_class_o);
    if (!test_MethodTester_o) {
        corto_error("test_load: failed to declare '/test/MethodTester' (%s)", corto_lasterr());
        goto error;
    }

    /* Declare /test/MethodTester/__dummy */
    test_MethodTester___dummy_o = corto_declareChild(test_MethodTester_o, "__dummy", corto_member_o);
    if (!test_MethodTester___dummy_o) {
        corto_error("test_load: failed to declare '/test/MethodTester/__dummy' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/MethodTester/__dummy */
    if (!corto_checkState(test_MethodTester___dummy_o, CORTO_DEFINED)) {
        test_MethodTester___dummy_o->type = corto_resolve(NULL, "/corto/lang/int8");
        test_MethodTester___dummy_o->modifiers = 0x3;
        test_MethodTester___dummy_o->state = 0x6;
        test_MethodTester___dummy_o->weak = FALSE;
        test_MethodTester___dummy_o->id = 0;
        if (corto_define(test_MethodTester___dummy_o)) {
            corto_error("test_load: failed to define '/test/MethodTester/__dummy' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/MethodTester/onearg(int32 a) */
    test_MethodTester_onearg_o = corto_declareChild(test_MethodTester_o, "onearg(int32 a)", corto_method_o);
    if (!test_MethodTester_onearg_o) {
        corto_error("test_load: failed to declare '/test/MethodTester/onearg(int32 a)' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/MethodTester/onearg(int32 a) */
    if (!corto_checkState(test_MethodTester_onearg_o, CORTO_DEFINED)) {
        corto_function(test_MethodTester_onearg_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_MethodTester_onearg_o)->returnsReference = FALSE;
        test_MethodTester_onearg_o->_virtual = FALSE;
        
        /* Bind /test/MethodTester/onearg(int32 a) with C-function */
        corto_function(test_MethodTester_onearg_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_MethodTester_onearg(void *args, void *result);
        corto_function(test_MethodTester_onearg_o)->impl = (corto_word)__test_MethodTester_onearg;
        if (corto_define(test_MethodTester_onearg_o)) {
            corto_error("test_load: failed to define '/test/MethodTester/onearg(int32 a)' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/MethodTester/overload(int32 a) */
    test_MethodTester_overload_int32_o = corto_declareChild(test_MethodTester_o, "overload(int32 a)", corto_method_o);
    if (!test_MethodTester_overload_int32_o) {
        corto_error("test_load: failed to declare '/test/MethodTester/overload(int32 a)' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/MethodTester/overload(int32 a) */
    if (!corto_checkState(test_MethodTester_overload_int32_o, CORTO_DEFINED)) {
        corto_function(test_MethodTester_overload_int32_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_MethodTester_overload_int32_o)->returnsReference = FALSE;
        test_MethodTester_overload_int32_o->_virtual = FALSE;
        
        /* Bind /test/MethodTester/overload(int32 a) with C-function */
        corto_function(test_MethodTester_overload_int32_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_MethodTester_overload_int32(void *args, void *result);
        corto_function(test_MethodTester_overload_int32_o)->impl = (corto_word)__test_MethodTester_overload_int32;
        if (corto_define(test_MethodTester_overload_int32_o)) {
            corto_error("test_load: failed to define '/test/MethodTester/overload(int32 a)' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/MethodTester/overload(int32 a,int32 b) */
    test_MethodTester_overload_int32_int32_o = corto_declareChild(test_MethodTester_o, "overload(int32 a,int32 b)", corto_method_o);
    if (!test_MethodTester_overload_int32_int32_o) {
        corto_error("test_load: failed to declare '/test/MethodTester/overload(int32 a,int32 b)' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/MethodTester/overload(int32 a,int32 b) */
    if (!corto_checkState(test_MethodTester_overload_int32_int32_o, CORTO_DEFINED)) {
        corto_function(test_MethodTester_overload_int32_int32_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_MethodTester_overload_int32_int32_o)->returnsReference = FALSE;
        test_MethodTester_overload_int32_int32_o->_virtual = FALSE;
        
        /* Bind /test/MethodTester/overload(int32 a,int32 b) with C-function */
        corto_function(test_MethodTester_overload_int32_int32_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_MethodTester_overload_int32_int32(void *args, void *result);
        corto_function(test_MethodTester_overload_int32_int32_o)->impl = (corto_word)__test_MethodTester_overload_int32_int32;
        if (corto_define(test_MethodTester_overload_int32_int32_o)) {
            corto_error("test_load: failed to define '/test/MethodTester/overload(int32 a,int32 b)' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/MethodTester/overload(string a) */
    test_MethodTester_overload_string_o = corto_declareChild(test_MethodTester_o, "overload(string a)", corto_method_o);
    if (!test_MethodTester_overload_string_o) {
        corto_error("test_load: failed to declare '/test/MethodTester/overload(string a)' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/MethodTester/overload(string a) */
    if (!corto_checkState(test_MethodTester_overload_string_o, CORTO_DEFINED)) {
        corto_function(test_MethodTester_overload_string_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_MethodTester_overload_string_o)->returnsReference = FALSE;
        test_MethodTester_overload_string_o->_virtual = FALSE;
        
        /* Bind /test/MethodTester/overload(string a) with C-function */
        corto_function(test_MethodTester_overload_string_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_MethodTester_overload_string(void *args, void *result);
        corto_function(test_MethodTester_overload_string_o)->impl = (corto_word)__test_MethodTester_overload_string;
        if (corto_define(test_MethodTester_overload_string_o)) {
            corto_error("test_load: failed to define '/test/MethodTester/overload(string a)' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/MethodTester/simple() */
    test_MethodTester_simple_o = corto_declareChild(test_MethodTester_o, "simple()", corto_method_o);
    if (!test_MethodTester_simple_o) {
        corto_error("test_load: failed to declare '/test/MethodTester/simple()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/MethodTester/simple() */
    if (!corto_checkState(test_MethodTester_simple_o, CORTO_DEFINED)) {
        corto_function(test_MethodTester_simple_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_MethodTester_simple_o)->returnsReference = FALSE;
        test_MethodTester_simple_o->_virtual = FALSE;
        
        /* Bind /test/MethodTester/simple() with C-function */
        corto_function(test_MethodTester_simple_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_MethodTester_simple(void *args, void *result);
        corto_function(test_MethodTester_simple_o)->impl = (corto_word)__test_MethodTester_simple;
        if (corto_define(test_MethodTester_simple_o)) {
            corto_error("test_load: failed to define '/test/MethodTester/simple()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/MethodTester/twoargs(int32 a,int32 b) */
    test_MethodTester_twoargs_o = corto_declareChild(test_MethodTester_o, "twoargs(int32 a,int32 b)", corto_method_o);
    if (!test_MethodTester_twoargs_o) {
        corto_error("test_load: failed to declare '/test/MethodTester/twoargs(int32 a,int32 b)' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/MethodTester/twoargs(int32 a,int32 b) */
    if (!corto_checkState(test_MethodTester_twoargs_o, CORTO_DEFINED)) {
        corto_function(test_MethodTester_twoargs_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_MethodTester_twoargs_o)->returnsReference = FALSE;
        test_MethodTester_twoargs_o->_virtual = FALSE;
        
        /* Bind /test/MethodTester/twoargs(int32 a,int32 b) with C-function */
        corto_function(test_MethodTester_twoargs_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_MethodTester_twoargs(void *args, void *result);
        corto_function(test_MethodTester_twoargs_o)->impl = (corto_word)__test_MethodTester_twoargs;
        if (corto_define(test_MethodTester_twoargs_o)) {
            corto_error("test_load: failed to define '/test/MethodTester/twoargs(int32 a,int32 b)' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/MethodTester/virtualOverload() */
    test_MethodTester_virtualOverload__o = corto_declareChild(test_MethodTester_o, "virtualOverload()", corto_virtual_o);
    if (!test_MethodTester_virtualOverload__o) {
        corto_error("test_load: failed to declare '/test/MethodTester/virtualOverload()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/MethodTester/virtualOverload() */
    if (!corto_checkState(test_MethodTester_virtualOverload__o, CORTO_DEFINED)) {
        corto_function(test_MethodTester_virtualOverload__o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_MethodTester_virtualOverload__o)->returnsReference = FALSE;
        corto_method(test_MethodTester_virtualOverload__o)->_virtual = TRUE;
        
        /* Bind /test/MethodTester/virtualOverload() with C-function */
        corto_function(test_MethodTester_virtualOverload__o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_MethodTester_virtualOverload__v(void *args, void *result);
        corto_function(test_MethodTester_virtualOverload__o)->impl = (corto_word)__test_MethodTester_virtualOverload__v;
        if (corto_define(test_MethodTester_virtualOverload__o)) {
            corto_error("test_load: failed to define '/test/MethodTester/virtualOverload()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/MethodTester/virtualOverload(int32 a) */
    test_MethodTester_virtualOverload_int32_o = corto_declareChild(test_MethodTester_o, "virtualOverload(int32 a)", corto_method_o);
    if (!test_MethodTester_virtualOverload_int32_o) {
        corto_error("test_load: failed to declare '/test/MethodTester/virtualOverload(int32 a)' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/MethodTester/virtualOverload(int32 a) */
    if (!corto_checkState(test_MethodTester_virtualOverload_int32_o, CORTO_DEFINED)) {
        corto_function(test_MethodTester_virtualOverload_int32_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_MethodTester_virtualOverload_int32_o)->returnsReference = FALSE;
        test_MethodTester_virtualOverload_int32_o->_virtual = FALSE;
        
        /* Bind /test/MethodTester/virtualOverload(int32 a) with C-function */
        corto_function(test_MethodTester_virtualOverload_int32_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_MethodTester_virtualOverload_int32(void *args, void *result);
        corto_function(test_MethodTester_virtualOverload_int32_o)->impl = (corto_word)__test_MethodTester_virtualOverload_int32;
        if (corto_define(test_MethodTester_virtualOverload_int32_o)) {
            corto_error("test_load: failed to define '/test/MethodTester/virtualOverload(int32 a)' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/MethodTester/virtualSimple() */
    test_MethodTester_virtualSimple_o = corto_declareChild(test_MethodTester_o, "virtualSimple()", corto_virtual_o);
    if (!test_MethodTester_virtualSimple_o) {
        corto_error("test_load: failed to declare '/test/MethodTester/virtualSimple()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/MethodTester/virtualSimple() */
    if (!corto_checkState(test_MethodTester_virtualSimple_o, CORTO_DEFINED)) {
        corto_function(test_MethodTester_virtualSimple_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_MethodTester_virtualSimple_o)->returnsReference = FALSE;
        corto_method(test_MethodTester_virtualSimple_o)->_virtual = TRUE;
        
        /* Bind /test/MethodTester/virtualSimple() with C-function */
        corto_function(test_MethodTester_virtualSimple_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_MethodTester_virtualSimple_v(void *args, void *result);
        corto_function(test_MethodTester_virtualSimple_o)->impl = (corto_word)__test_MethodTester_virtualSimple_v;
        if (corto_define(test_MethodTester_virtualSimple_o)) {
            corto_error("test_load: failed to define '/test/MethodTester/virtualSimple()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/MethodTesterInherit */
    test_MethodTesterInherit_o = corto_declareChild(test_o, "MethodTesterInherit", corto_class_o);
    if (!test_MethodTesterInherit_o) {
        corto_error("test_load: failed to declare '/test/MethodTesterInherit' (%s)", corto_lasterr());
        goto error;
    }

    /* Declare /test/ObjectMgmt */
    test_ObjectMgmt_o = corto_declareChild(test_o, "ObjectMgmt", test_Suite_o);
    if (!test_ObjectMgmt_o) {
        corto_error("test_load: failed to declare '/test/ObjectMgmt' (%s)", corto_lasterr());
        goto error;
    }

    /* Declare /test/ObjectMgmt/prevAttr */
    test_ObjectMgmt_prevAttr_o = corto_declareChild(test_ObjectMgmt_o, "prevAttr", corto_member_o);
    if (!test_ObjectMgmt_prevAttr_o) {
        corto_error("test_load: failed to declare '/test/ObjectMgmt/prevAttr' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ObjectMgmt/prevAttr */
    if (!corto_checkState(test_ObjectMgmt_prevAttr_o, CORTO_DEFINED)) {
        test_ObjectMgmt_prevAttr_o->type = corto_resolve(NULL, "/corto/lang/attr");
        test_ObjectMgmt_prevAttr_o->modifiers = 0x3;
        test_ObjectMgmt_prevAttr_o->state = 0x6;
        test_ObjectMgmt_prevAttr_o->weak = FALSE;
        test_ObjectMgmt_prevAttr_o->id = 0;
        if (corto_define(test_ObjectMgmt_prevAttr_o)) {
            corto_error("test_load: failed to define '/test/ObjectMgmt/prevAttr' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ObjectMgmt/setup() */
    test_ObjectMgmt_setup_o = corto_declareChild(test_ObjectMgmt_o, "setup()", corto_method_o);
    if (!test_ObjectMgmt_setup_o) {
        corto_error("test_load: failed to declare '/test/ObjectMgmt/setup()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ObjectMgmt/setup() */
    if (!corto_checkState(test_ObjectMgmt_setup_o, CORTO_DEFINED)) {
        corto_function(test_ObjectMgmt_setup_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_ObjectMgmt_setup_o)->returnsReference = FALSE;
        test_ObjectMgmt_setup_o->_virtual = FALSE;
        
        /* Bind /test/ObjectMgmt/setup() with C-function */
        corto_function(test_ObjectMgmt_setup_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ObjectMgmt_setup(void *args, void *result);
        corto_function(test_ObjectMgmt_setup_o)->impl = (corto_word)__test_ObjectMgmt_setup;
        if (corto_define(test_ObjectMgmt_setup_o)) {
            corto_error("test_load: failed to define '/test/ObjectMgmt/setup()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ObjectMgmt/teardown() */
    test_ObjectMgmt_teardown_o = corto_declareChild(test_ObjectMgmt_o, "teardown()", corto_method_o);
    if (!test_ObjectMgmt_teardown_o) {
        corto_error("test_load: failed to declare '/test/ObjectMgmt/teardown()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ObjectMgmt/teardown() */
    if (!corto_checkState(test_ObjectMgmt_teardown_o, CORTO_DEFINED)) {
        corto_function(test_ObjectMgmt_teardown_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_ObjectMgmt_teardown_o)->returnsReference = FALSE;
        test_ObjectMgmt_teardown_o->_virtual = FALSE;
        
        /* Bind /test/ObjectMgmt/teardown() with C-function */
        corto_function(test_ObjectMgmt_teardown_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ObjectMgmt_teardown(void *args, void *result);
        corto_function(test_ObjectMgmt_teardown_o)->impl = (corto_word)__test_ObjectMgmt_teardown;
        if (corto_define(test_ObjectMgmt_teardown_o)) {
            corto_error("test_load: failed to define '/test/ObjectMgmt/teardown()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Define /test/ObjectMgmt */
    if (!corto_checkState(test_ObjectMgmt_o, CORTO_DEFINED)) {
        corto_type(test_ObjectMgmt_o)->parentType = NULL;
        corto_type(test_ObjectMgmt_o)->parentState = 0x6;
        corto_type(test_ObjectMgmt_o)->defaultType = NULL;
        corto_type(test_ObjectMgmt_o)->defaultProcedureType = NULL;
        corto_interface(test_ObjectMgmt_o)->base = corto_resolve(NULL, "/corto/test/SuiteData");
        corto_struct(test_ObjectMgmt_o)->baseAccess = 0x0;
        corto_class(test_ObjectMgmt_o)->implements.length = 0;
        corto_class(test_ObjectMgmt_o)->implements.buffer = NULL;
        if (corto_define(test_ObjectMgmt_o)) {
            corto_error("test_load: failed to define '/test/ObjectMgmt' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (corto_type(test_ObjectMgmt_o)->size != sizeof(struct test_ObjectMgmt_s)) {
        corto_error("test_load: calculated size '%d' of type '/test/ObjectMgmt' doesn't match C-type size '%d'", corto_type(test_ObjectMgmt_o)->size, sizeof(struct test_ObjectMgmt_s));
    }

    /* Declare /test/ObjectMgmt/tc_createChildFoo() */
    test_ObjectMgmt_tc_createChildFoo_o = corto_declareChild(test_ObjectMgmt_o, "tc_createChildFoo()", test_Case_o);
    if (!test_ObjectMgmt_tc_createChildFoo_o) {
        corto_error("test_load: failed to declare '/test/ObjectMgmt/tc_createChildFoo()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ObjectMgmt/tc_createChildFoo() */
    if (!corto_checkState(test_ObjectMgmt_tc_createChildFoo_o, CORTO_DEFINED)) {
        corto_function(test_ObjectMgmt_tc_createChildFoo_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_ObjectMgmt_tc_createChildFoo_o)->returnsReference = FALSE;
        corto_method(test_ObjectMgmt_tc_createChildFoo_o)->_virtual = FALSE;
        
        /* Bind /test/ObjectMgmt/tc_createChildFoo() with C-function */
        corto_function(test_ObjectMgmt_tc_createChildFoo_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ObjectMgmt_tc_createChildFoo(void *args, void *result);
        corto_function(test_ObjectMgmt_tc_createChildFoo_o)->impl = (corto_word)__test_ObjectMgmt_tc_createChildFoo;
        if (corto_define(test_ObjectMgmt_tc_createChildFoo_o)) {
            corto_error("test_load: failed to define '/test/ObjectMgmt/tc_createChildFoo()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ObjectMgmt/tc_createChildFooAttr0() */
    test_ObjectMgmt_tc_createChildFooAttr0_o = corto_declareChild(test_ObjectMgmt_o, "tc_createChildFooAttr0()", test_Case_o);
    if (!test_ObjectMgmt_tc_createChildFooAttr0_o) {
        corto_error("test_load: failed to declare '/test/ObjectMgmt/tc_createChildFooAttr0()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ObjectMgmt/tc_createChildFooAttr0() */
    if (!corto_checkState(test_ObjectMgmt_tc_createChildFooAttr0_o, CORTO_DEFINED)) {
        corto_function(test_ObjectMgmt_tc_createChildFooAttr0_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_ObjectMgmt_tc_createChildFooAttr0_o)->returnsReference = FALSE;
        corto_method(test_ObjectMgmt_tc_createChildFooAttr0_o)->_virtual = FALSE;
        
        /* Bind /test/ObjectMgmt/tc_createChildFooAttr0() with C-function */
        corto_function(test_ObjectMgmt_tc_createChildFooAttr0_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ObjectMgmt_tc_createChildFooAttr0(void *args, void *result);
        corto_function(test_ObjectMgmt_tc_createChildFooAttr0_o)->impl = (corto_word)__test_ObjectMgmt_tc_createChildFooAttr0;
        if (corto_define(test_ObjectMgmt_tc_createChildFooAttr0_o)) {
            corto_error("test_load: failed to define '/test/ObjectMgmt/tc_createChildFooAttr0()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ObjectMgmt/tc_createChildInitFail() */
    test_ObjectMgmt_tc_createChildInitFail_o = corto_declareChild(test_ObjectMgmt_o, "tc_createChildInitFail()", test_Case_o);
    if (!test_ObjectMgmt_tc_createChildInitFail_o) {
        corto_error("test_load: failed to declare '/test/ObjectMgmt/tc_createChildInitFail()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ObjectMgmt/tc_createChildInitFail() */
    if (!corto_checkState(test_ObjectMgmt_tc_createChildInitFail_o, CORTO_DEFINED)) {
        corto_function(test_ObjectMgmt_tc_createChildInitFail_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_ObjectMgmt_tc_createChildInitFail_o)->returnsReference = FALSE;
        corto_method(test_ObjectMgmt_tc_createChildInitFail_o)->_virtual = FALSE;
        
        /* Bind /test/ObjectMgmt/tc_createChildInitFail() with C-function */
        corto_function(test_ObjectMgmt_tc_createChildInitFail_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ObjectMgmt_tc_createChildInitFail(void *args, void *result);
        corto_function(test_ObjectMgmt_tc_createChildInitFail_o)->impl = (corto_word)__test_ObjectMgmt_tc_createChildInitFail;
        if (corto_define(test_ObjectMgmt_tc_createChildInitFail_o)) {
            corto_error("test_load: failed to define '/test/ObjectMgmt/tc_createChildInitFail()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ObjectMgmt/tc_createChildInt() */
    test_ObjectMgmt_tc_createChildInt_o = corto_declareChild(test_ObjectMgmt_o, "tc_createChildInt()", test_Case_o);
    if (!test_ObjectMgmt_tc_createChildInt_o) {
        corto_error("test_load: failed to declare '/test/ObjectMgmt/tc_createChildInt()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ObjectMgmt/tc_createChildInt() */
    if (!corto_checkState(test_ObjectMgmt_tc_createChildInt_o, CORTO_DEFINED)) {
        corto_function(test_ObjectMgmt_tc_createChildInt_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_ObjectMgmt_tc_createChildInt_o)->returnsReference = FALSE;
        corto_method(test_ObjectMgmt_tc_createChildInt_o)->_virtual = FALSE;
        
        /* Bind /test/ObjectMgmt/tc_createChildInt() with C-function */
        corto_function(test_ObjectMgmt_tc_createChildInt_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ObjectMgmt_tc_createChildInt(void *args, void *result);
        corto_function(test_ObjectMgmt_tc_createChildInt_o)->impl = (corto_word)__test_ObjectMgmt_tc_createChildInt;
        if (corto_define(test_ObjectMgmt_tc_createChildInt_o)) {
            corto_error("test_load: failed to define '/test/ObjectMgmt/tc_createChildInt()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ObjectMgmt/tc_createChildIntAttr0() */
    test_ObjectMgmt_tc_createChildIntAttr0_o = corto_declareChild(test_ObjectMgmt_o, "tc_createChildIntAttr0()", test_Case_o);
    if (!test_ObjectMgmt_tc_createChildIntAttr0_o) {
        corto_error("test_load: failed to declare '/test/ObjectMgmt/tc_createChildIntAttr0()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ObjectMgmt/tc_createChildIntAttr0() */
    if (!corto_checkState(test_ObjectMgmt_tc_createChildIntAttr0_o, CORTO_DEFINED)) {
        corto_function(test_ObjectMgmt_tc_createChildIntAttr0_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_ObjectMgmt_tc_createChildIntAttr0_o)->returnsReference = FALSE;
        corto_method(test_ObjectMgmt_tc_createChildIntAttr0_o)->_virtual = FALSE;
        
        /* Bind /test/ObjectMgmt/tc_createChildIntAttr0() with C-function */
        corto_function(test_ObjectMgmt_tc_createChildIntAttr0_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ObjectMgmt_tc_createChildIntAttr0(void *args, void *result);
        corto_function(test_ObjectMgmt_tc_createChildIntAttr0_o)->impl = (corto_word)__test_ObjectMgmt_tc_createChildIntAttr0;
        if (corto_define(test_ObjectMgmt_tc_createChildIntAttr0_o)) {
            corto_error("test_load: failed to define '/test/ObjectMgmt/tc_createChildIntAttr0()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ObjectMgmt/tc_createChildInvalidType() */
    test_ObjectMgmt_tc_createChildInvalidType_o = corto_declareChild(test_ObjectMgmt_o, "tc_createChildInvalidType()", test_Case_o);
    if (!test_ObjectMgmt_tc_createChildInvalidType_o) {
        corto_error("test_load: failed to declare '/test/ObjectMgmt/tc_createChildInvalidType()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ObjectMgmt/tc_createChildInvalidType() */
    if (!corto_checkState(test_ObjectMgmt_tc_createChildInvalidType_o, CORTO_DEFINED)) {
        corto_function(test_ObjectMgmt_tc_createChildInvalidType_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_ObjectMgmt_tc_createChildInvalidType_o)->returnsReference = FALSE;
        corto_method(test_ObjectMgmt_tc_createChildInvalidType_o)->_virtual = FALSE;
        
        /* Bind /test/ObjectMgmt/tc_createChildInvalidType() with C-function */
        corto_function(test_ObjectMgmt_tc_createChildInvalidType_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ObjectMgmt_tc_createChildInvalidType(void *args, void *result);
        corto_function(test_ObjectMgmt_tc_createChildInvalidType_o)->impl = (corto_word)__test_ObjectMgmt_tc_createChildInvalidType;
        if (corto_define(test_ObjectMgmt_tc_createChildInvalidType_o)) {
            corto_error("test_load: failed to define '/test/ObjectMgmt/tc_createChildInvalidType()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ObjectMgmt/tc_createChildNested() */
    test_ObjectMgmt_tc_createChildNested_o = corto_declareChild(test_ObjectMgmt_o, "tc_createChildNested()", test_Case_o);
    if (!test_ObjectMgmt_tc_createChildNested_o) {
        corto_error("test_load: failed to declare '/test/ObjectMgmt/tc_createChildNested()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ObjectMgmt/tc_createChildNested() */
    if (!corto_checkState(test_ObjectMgmt_tc_createChildNested_o, CORTO_DEFINED)) {
        corto_function(test_ObjectMgmt_tc_createChildNested_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_ObjectMgmt_tc_createChildNested_o)->returnsReference = FALSE;
        corto_method(test_ObjectMgmt_tc_createChildNested_o)->_virtual = FALSE;
        
        /* Bind /test/ObjectMgmt/tc_createChildNested() with C-function */
        corto_function(test_ObjectMgmt_tc_createChildNested_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ObjectMgmt_tc_createChildNested(void *args, void *result);
        corto_function(test_ObjectMgmt_tc_createChildNested_o)->impl = (corto_word)__test_ObjectMgmt_tc_createChildNested;
        if (corto_define(test_ObjectMgmt_tc_createChildNested_o)) {
            corto_error("test_load: failed to define '/test/ObjectMgmt/tc_createChildNested()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ObjectMgmt/tc_createChildNullType() */
    test_ObjectMgmt_tc_createChildNullType_o = corto_declareChild(test_ObjectMgmt_o, "tc_createChildNullType()", test_Case_o);
    if (!test_ObjectMgmt_tc_createChildNullType_o) {
        corto_error("test_load: failed to declare '/test/ObjectMgmt/tc_createChildNullType()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ObjectMgmt/tc_createChildNullType() */
    if (!corto_checkState(test_ObjectMgmt_tc_createChildNullType_o, CORTO_DEFINED)) {
        corto_function(test_ObjectMgmt_tc_createChildNullType_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_ObjectMgmt_tc_createChildNullType_o)->returnsReference = FALSE;
        corto_method(test_ObjectMgmt_tc_createChildNullType_o)->_virtual = FALSE;
        
        /* Bind /test/ObjectMgmt/tc_createChildNullType() with C-function */
        corto_function(test_ObjectMgmt_tc_createChildNullType_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ObjectMgmt_tc_createChildNullType(void *args, void *result);
        corto_function(test_ObjectMgmt_tc_createChildNullType_o)->impl = (corto_word)__test_ObjectMgmt_tc_createChildNullType;
        if (corto_define(test_ObjectMgmt_tc_createChildNullType_o)) {
            corto_error("test_load: failed to define '/test/ObjectMgmt/tc_createChildNullType()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ObjectMgmt/tc_createChildParentStateErr() */
    test_ObjectMgmt_tc_createChildParentStateErr_o = corto_declareChild(test_ObjectMgmt_o, "tc_createChildParentStateErr()", test_Case_o);
    if (!test_ObjectMgmt_tc_createChildParentStateErr_o) {
        corto_error("test_load: failed to declare '/test/ObjectMgmt/tc_createChildParentStateErr()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ObjectMgmt/tc_createChildParentStateErr() */
    if (!corto_checkState(test_ObjectMgmt_tc_createChildParentStateErr_o, CORTO_DEFINED)) {
        corto_function(test_ObjectMgmt_tc_createChildParentStateErr_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_ObjectMgmt_tc_createChildParentStateErr_o)->returnsReference = FALSE;
        corto_method(test_ObjectMgmt_tc_createChildParentStateErr_o)->_virtual = FALSE;
        
        /* Bind /test/ObjectMgmt/tc_createChildParentStateErr() with C-function */
        corto_function(test_ObjectMgmt_tc_createChildParentStateErr_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ObjectMgmt_tc_createChildParentStateErr(void *args, void *result);
        corto_function(test_ObjectMgmt_tc_createChildParentStateErr_o)->impl = (corto_word)__test_ObjectMgmt_tc_createChildParentStateErr;
        if (corto_define(test_ObjectMgmt_tc_createChildParentStateErr_o)) {
            corto_error("test_load: failed to define '/test/ObjectMgmt/tc_createChildParentStateErr()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ObjectMgmt/tc_createChildParentTypeErr() */
    test_ObjectMgmt_tc_createChildParentTypeErr_o = corto_declareChild(test_ObjectMgmt_o, "tc_createChildParentTypeErr()", test_Case_o);
    if (!test_ObjectMgmt_tc_createChildParentTypeErr_o) {
        corto_error("test_load: failed to declare '/test/ObjectMgmt/tc_createChildParentTypeErr()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ObjectMgmt/tc_createChildParentTypeErr() */
    if (!corto_checkState(test_ObjectMgmt_tc_createChildParentTypeErr_o, CORTO_DEFINED)) {
        corto_function(test_ObjectMgmt_tc_createChildParentTypeErr_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_ObjectMgmt_tc_createChildParentTypeErr_o)->returnsReference = FALSE;
        corto_method(test_ObjectMgmt_tc_createChildParentTypeErr_o)->_virtual = FALSE;
        
        /* Bind /test/ObjectMgmt/tc_createChildParentTypeErr() with C-function */
        corto_function(test_ObjectMgmt_tc_createChildParentTypeErr_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ObjectMgmt_tc_createChildParentTypeErr(void *args, void *result);
        corto_function(test_ObjectMgmt_tc_createChildParentTypeErr_o)->impl = (corto_word)__test_ObjectMgmt_tc_createChildParentTypeErr;
        if (corto_define(test_ObjectMgmt_tc_createChildParentTypeErr_o)) {
            corto_error("test_load: failed to define '/test/ObjectMgmt/tc_createChildParentTypeErr()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ObjectMgmt/tc_createChildVoid() */
    test_ObjectMgmt_tc_createChildVoid_o = corto_declareChild(test_ObjectMgmt_o, "tc_createChildVoid()", test_Case_o);
    if (!test_ObjectMgmt_tc_createChildVoid_o) {
        corto_error("test_load: failed to declare '/test/ObjectMgmt/tc_createChildVoid()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ObjectMgmt/tc_createChildVoid() */
    if (!corto_checkState(test_ObjectMgmt_tc_createChildVoid_o, CORTO_DEFINED)) {
        corto_function(test_ObjectMgmt_tc_createChildVoid_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_ObjectMgmt_tc_createChildVoid_o)->returnsReference = FALSE;
        corto_method(test_ObjectMgmt_tc_createChildVoid_o)->_virtual = FALSE;
        
        /* Bind /test/ObjectMgmt/tc_createChildVoid() with C-function */
        corto_function(test_ObjectMgmt_tc_createChildVoid_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ObjectMgmt_tc_createChildVoid(void *args, void *result);
        corto_function(test_ObjectMgmt_tc_createChildVoid_o)->impl = (corto_word)__test_ObjectMgmt_tc_createChildVoid;
        if (corto_define(test_ObjectMgmt_tc_createChildVoid_o)) {
            corto_error("test_load: failed to define '/test/ObjectMgmt/tc_createChildVoid()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ObjectMgmt/tc_createChildVoidAttr0() */
    test_ObjectMgmt_tc_createChildVoidAttr0_o = corto_declareChild(test_ObjectMgmt_o, "tc_createChildVoidAttr0()", test_Case_o);
    if (!test_ObjectMgmt_tc_createChildVoidAttr0_o) {
        corto_error("test_load: failed to declare '/test/ObjectMgmt/tc_createChildVoidAttr0()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ObjectMgmt/tc_createChildVoidAttr0() */
    if (!corto_checkState(test_ObjectMgmt_tc_createChildVoidAttr0_o, CORTO_DEFINED)) {
        corto_function(test_ObjectMgmt_tc_createChildVoidAttr0_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_ObjectMgmt_tc_createChildVoidAttr0_o)->returnsReference = FALSE;
        corto_method(test_ObjectMgmt_tc_createChildVoidAttr0_o)->_virtual = FALSE;
        
        /* Bind /test/ObjectMgmt/tc_createChildVoidAttr0() with C-function */
        corto_function(test_ObjectMgmt_tc_createChildVoidAttr0_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ObjectMgmt_tc_createChildVoidAttr0(void *args, void *result);
        corto_function(test_ObjectMgmt_tc_createChildVoidAttr0_o)->impl = (corto_word)__test_ObjectMgmt_tc_createChildVoidAttr0;
        if (corto_define(test_ObjectMgmt_tc_createChildVoidAttr0_o)) {
            corto_error("test_load: failed to define '/test/ObjectMgmt/tc_createChildVoidAttr0()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ObjectMgmt/tc_createFoo() */
    test_ObjectMgmt_tc_createFoo_o = corto_declareChild(test_ObjectMgmt_o, "tc_createFoo()", test_Case_o);
    if (!test_ObjectMgmt_tc_createFoo_o) {
        corto_error("test_load: failed to declare '/test/ObjectMgmt/tc_createFoo()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ObjectMgmt/tc_createFoo() */
    if (!corto_checkState(test_ObjectMgmt_tc_createFoo_o, CORTO_DEFINED)) {
        corto_function(test_ObjectMgmt_tc_createFoo_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_ObjectMgmt_tc_createFoo_o)->returnsReference = FALSE;
        corto_method(test_ObjectMgmt_tc_createFoo_o)->_virtual = FALSE;
        
        /* Bind /test/ObjectMgmt/tc_createFoo() with C-function */
        corto_function(test_ObjectMgmt_tc_createFoo_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ObjectMgmt_tc_createFoo(void *args, void *result);
        corto_function(test_ObjectMgmt_tc_createFoo_o)->impl = (corto_word)__test_ObjectMgmt_tc_createFoo;
        if (corto_define(test_ObjectMgmt_tc_createFoo_o)) {
            corto_error("test_load: failed to define '/test/ObjectMgmt/tc_createFoo()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ObjectMgmt/tc_createFooAttr0() */
    test_ObjectMgmt_tc_createFooAttr0_o = corto_declareChild(test_ObjectMgmt_o, "tc_createFooAttr0()", test_Case_o);
    if (!test_ObjectMgmt_tc_createFooAttr0_o) {
        corto_error("test_load: failed to declare '/test/ObjectMgmt/tc_createFooAttr0()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ObjectMgmt/tc_createFooAttr0() */
    if (!corto_checkState(test_ObjectMgmt_tc_createFooAttr0_o, CORTO_DEFINED)) {
        corto_function(test_ObjectMgmt_tc_createFooAttr0_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_ObjectMgmt_tc_createFooAttr0_o)->returnsReference = FALSE;
        corto_method(test_ObjectMgmt_tc_createFooAttr0_o)->_virtual = FALSE;
        
        /* Bind /test/ObjectMgmt/tc_createFooAttr0() with C-function */
        corto_function(test_ObjectMgmt_tc_createFooAttr0_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ObjectMgmt_tc_createFooAttr0(void *args, void *result);
        corto_function(test_ObjectMgmt_tc_createFooAttr0_o)->impl = (corto_word)__test_ObjectMgmt_tc_createFooAttr0;
        if (corto_define(test_ObjectMgmt_tc_createFooAttr0_o)) {
            corto_error("test_load: failed to define '/test/ObjectMgmt/tc_createFooAttr0()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ObjectMgmt/tc_createInitFail() */
    test_ObjectMgmt_tc_createInitFail_o = corto_declareChild(test_ObjectMgmt_o, "tc_createInitFail()", test_Case_o);
    if (!test_ObjectMgmt_tc_createInitFail_o) {
        corto_error("test_load: failed to declare '/test/ObjectMgmt/tc_createInitFail()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ObjectMgmt/tc_createInitFail() */
    if (!corto_checkState(test_ObjectMgmt_tc_createInitFail_o, CORTO_DEFINED)) {
        corto_function(test_ObjectMgmt_tc_createInitFail_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_ObjectMgmt_tc_createInitFail_o)->returnsReference = FALSE;
        corto_method(test_ObjectMgmt_tc_createInitFail_o)->_virtual = FALSE;
        
        /* Bind /test/ObjectMgmt/tc_createInitFail() with C-function */
        corto_function(test_ObjectMgmt_tc_createInitFail_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ObjectMgmt_tc_createInitFail(void *args, void *result);
        corto_function(test_ObjectMgmt_tc_createInitFail_o)->impl = (corto_word)__test_ObjectMgmt_tc_createInitFail;
        if (corto_define(test_ObjectMgmt_tc_createInitFail_o)) {
            corto_error("test_load: failed to define '/test/ObjectMgmt/tc_createInitFail()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ObjectMgmt/tc_createInt() */
    test_ObjectMgmt_tc_createInt_o = corto_declareChild(test_ObjectMgmt_o, "tc_createInt()", test_Case_o);
    if (!test_ObjectMgmt_tc_createInt_o) {
        corto_error("test_load: failed to declare '/test/ObjectMgmt/tc_createInt()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ObjectMgmt/tc_createInt() */
    if (!corto_checkState(test_ObjectMgmt_tc_createInt_o, CORTO_DEFINED)) {
        corto_function(test_ObjectMgmt_tc_createInt_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_ObjectMgmt_tc_createInt_o)->returnsReference = FALSE;
        corto_method(test_ObjectMgmt_tc_createInt_o)->_virtual = FALSE;
        
        /* Bind /test/ObjectMgmt/tc_createInt() with C-function */
        corto_function(test_ObjectMgmt_tc_createInt_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ObjectMgmt_tc_createInt(void *args, void *result);
        corto_function(test_ObjectMgmt_tc_createInt_o)->impl = (corto_word)__test_ObjectMgmt_tc_createInt;
        if (corto_define(test_ObjectMgmt_tc_createInt_o)) {
            corto_error("test_load: failed to define '/test/ObjectMgmt/tc_createInt()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ObjectMgmt/tc_createIntAttr0() */
    test_ObjectMgmt_tc_createIntAttr0_o = corto_declareChild(test_ObjectMgmt_o, "tc_createIntAttr0()", test_Case_o);
    if (!test_ObjectMgmt_tc_createIntAttr0_o) {
        corto_error("test_load: failed to declare '/test/ObjectMgmt/tc_createIntAttr0()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ObjectMgmt/tc_createIntAttr0() */
    if (!corto_checkState(test_ObjectMgmt_tc_createIntAttr0_o, CORTO_DEFINED)) {
        corto_function(test_ObjectMgmt_tc_createIntAttr0_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_ObjectMgmt_tc_createIntAttr0_o)->returnsReference = FALSE;
        corto_method(test_ObjectMgmt_tc_createIntAttr0_o)->_virtual = FALSE;
        
        /* Bind /test/ObjectMgmt/tc_createIntAttr0() with C-function */
        corto_function(test_ObjectMgmt_tc_createIntAttr0_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ObjectMgmt_tc_createIntAttr0(void *args, void *result);
        corto_function(test_ObjectMgmt_tc_createIntAttr0_o)->impl = (corto_word)__test_ObjectMgmt_tc_createIntAttr0;
        if (corto_define(test_ObjectMgmt_tc_createIntAttr0_o)) {
            corto_error("test_load: failed to define '/test/ObjectMgmt/tc_createIntAttr0()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ObjectMgmt/tc_createInvalidType() */
    test_ObjectMgmt_tc_createInvalidType_o = corto_declareChild(test_ObjectMgmt_o, "tc_createInvalidType()", test_Case_o);
    if (!test_ObjectMgmt_tc_createInvalidType_o) {
        corto_error("test_load: failed to declare '/test/ObjectMgmt/tc_createInvalidType()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ObjectMgmt/tc_createInvalidType() */
    if (!corto_checkState(test_ObjectMgmt_tc_createInvalidType_o, CORTO_DEFINED)) {
        corto_function(test_ObjectMgmt_tc_createInvalidType_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_ObjectMgmt_tc_createInvalidType_o)->returnsReference = FALSE;
        corto_method(test_ObjectMgmt_tc_createInvalidType_o)->_virtual = FALSE;
        
        /* Bind /test/ObjectMgmt/tc_createInvalidType() with C-function */
        corto_function(test_ObjectMgmt_tc_createInvalidType_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ObjectMgmt_tc_createInvalidType(void *args, void *result);
        corto_function(test_ObjectMgmt_tc_createInvalidType_o)->impl = (corto_word)__test_ObjectMgmt_tc_createInvalidType;
        if (corto_define(test_ObjectMgmt_tc_createInvalidType_o)) {
            corto_error("test_load: failed to define '/test/ObjectMgmt/tc_createInvalidType()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ObjectMgmt/tc_createNullType() */
    test_ObjectMgmt_tc_createNullType_o = corto_declareChild(test_ObjectMgmt_o, "tc_createNullType()", test_Case_o);
    if (!test_ObjectMgmt_tc_createNullType_o) {
        corto_error("test_load: failed to declare '/test/ObjectMgmt/tc_createNullType()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ObjectMgmt/tc_createNullType() */
    if (!corto_checkState(test_ObjectMgmt_tc_createNullType_o, CORTO_DEFINED)) {
        corto_function(test_ObjectMgmt_tc_createNullType_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_ObjectMgmt_tc_createNullType_o)->returnsReference = FALSE;
        corto_method(test_ObjectMgmt_tc_createNullType_o)->_virtual = FALSE;
        
        /* Bind /test/ObjectMgmt/tc_createNullType() with C-function */
        corto_function(test_ObjectMgmt_tc_createNullType_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ObjectMgmt_tc_createNullType(void *args, void *result);
        corto_function(test_ObjectMgmt_tc_createNullType_o)->impl = (corto_word)__test_ObjectMgmt_tc_createNullType;
        if (corto_define(test_ObjectMgmt_tc_createNullType_o)) {
            corto_error("test_load: failed to define '/test/ObjectMgmt/tc_createNullType()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ObjectMgmt/tc_createVoid() */
    test_ObjectMgmt_tc_createVoid_o = corto_declareChild(test_ObjectMgmt_o, "tc_createVoid()", test_Case_o);
    if (!test_ObjectMgmt_tc_createVoid_o) {
        corto_error("test_load: failed to declare '/test/ObjectMgmt/tc_createVoid()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ObjectMgmt/tc_createVoid() */
    if (!corto_checkState(test_ObjectMgmt_tc_createVoid_o, CORTO_DEFINED)) {
        corto_function(test_ObjectMgmt_tc_createVoid_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_ObjectMgmt_tc_createVoid_o)->returnsReference = FALSE;
        corto_method(test_ObjectMgmt_tc_createVoid_o)->_virtual = FALSE;
        
        /* Bind /test/ObjectMgmt/tc_createVoid() with C-function */
        corto_function(test_ObjectMgmt_tc_createVoid_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ObjectMgmt_tc_createVoid(void *args, void *result);
        corto_function(test_ObjectMgmt_tc_createVoid_o)->impl = (corto_word)__test_ObjectMgmt_tc_createVoid;
        if (corto_define(test_ObjectMgmt_tc_createVoid_o)) {
            corto_error("test_load: failed to define '/test/ObjectMgmt/tc_createVoid()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ObjectMgmt/tc_createVoidAttr0() */
    test_ObjectMgmt_tc_createVoidAttr0_o = corto_declareChild(test_ObjectMgmt_o, "tc_createVoidAttr0()", test_Case_o);
    if (!test_ObjectMgmt_tc_createVoidAttr0_o) {
        corto_error("test_load: failed to declare '/test/ObjectMgmt/tc_createVoidAttr0()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ObjectMgmt/tc_createVoidAttr0() */
    if (!corto_checkState(test_ObjectMgmt_tc_createVoidAttr0_o, CORTO_DEFINED)) {
        corto_function(test_ObjectMgmt_tc_createVoidAttr0_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_ObjectMgmt_tc_createVoidAttr0_o)->returnsReference = FALSE;
        corto_method(test_ObjectMgmt_tc_createVoidAttr0_o)->_virtual = FALSE;
        
        /* Bind /test/ObjectMgmt/tc_createVoidAttr0() with C-function */
        corto_function(test_ObjectMgmt_tc_createVoidAttr0_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ObjectMgmt_tc_createVoidAttr0(void *args, void *result);
        corto_function(test_ObjectMgmt_tc_createVoidAttr0_o)->impl = (corto_word)__test_ObjectMgmt_tc_createVoidAttr0;
        if (corto_define(test_ObjectMgmt_tc_createVoidAttr0_o)) {
            corto_error("test_load: failed to define '/test/ObjectMgmt/tc_createVoidAttr0()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ObjectMgmt/tc_declareChildFoo() */
    test_ObjectMgmt_tc_declareChildFoo_o = corto_declareChild(test_ObjectMgmt_o, "tc_declareChildFoo()", test_Case_o);
    if (!test_ObjectMgmt_tc_declareChildFoo_o) {
        corto_error("test_load: failed to declare '/test/ObjectMgmt/tc_declareChildFoo()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ObjectMgmt/tc_declareChildFoo() */
    if (!corto_checkState(test_ObjectMgmt_tc_declareChildFoo_o, CORTO_DEFINED)) {
        corto_function(test_ObjectMgmt_tc_declareChildFoo_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_ObjectMgmt_tc_declareChildFoo_o)->returnsReference = FALSE;
        corto_method(test_ObjectMgmt_tc_declareChildFoo_o)->_virtual = FALSE;
        
        /* Bind /test/ObjectMgmt/tc_declareChildFoo() with C-function */
        corto_function(test_ObjectMgmt_tc_declareChildFoo_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ObjectMgmt_tc_declareChildFoo(void *args, void *result);
        corto_function(test_ObjectMgmt_tc_declareChildFoo_o)->impl = (corto_word)__test_ObjectMgmt_tc_declareChildFoo;
        if (corto_define(test_ObjectMgmt_tc_declareChildFoo_o)) {
            corto_error("test_load: failed to define '/test/ObjectMgmt/tc_declareChildFoo()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ObjectMgmt/tc_declareChildFooAttr0() */
    test_ObjectMgmt_tc_declareChildFooAttr0_o = corto_declareChild(test_ObjectMgmt_o, "tc_declareChildFooAttr0()", test_Case_o);
    if (!test_ObjectMgmt_tc_declareChildFooAttr0_o) {
        corto_error("test_load: failed to declare '/test/ObjectMgmt/tc_declareChildFooAttr0()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ObjectMgmt/tc_declareChildFooAttr0() */
    if (!corto_checkState(test_ObjectMgmt_tc_declareChildFooAttr0_o, CORTO_DEFINED)) {
        corto_function(test_ObjectMgmt_tc_declareChildFooAttr0_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_ObjectMgmt_tc_declareChildFooAttr0_o)->returnsReference = FALSE;
        corto_method(test_ObjectMgmt_tc_declareChildFooAttr0_o)->_virtual = FALSE;
        
        /* Bind /test/ObjectMgmt/tc_declareChildFooAttr0() with C-function */
        corto_function(test_ObjectMgmt_tc_declareChildFooAttr0_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ObjectMgmt_tc_declareChildFooAttr0(void *args, void *result);
        corto_function(test_ObjectMgmt_tc_declareChildFooAttr0_o)->impl = (corto_word)__test_ObjectMgmt_tc_declareChildFooAttr0;
        if (corto_define(test_ObjectMgmt_tc_declareChildFooAttr0_o)) {
            corto_error("test_load: failed to define '/test/ObjectMgmt/tc_declareChildFooAttr0()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ObjectMgmt/tc_declareChildInitFail() */
    test_ObjectMgmt_tc_declareChildInitFail_o = corto_declareChild(test_ObjectMgmt_o, "tc_declareChildInitFail()", test_Case_o);
    if (!test_ObjectMgmt_tc_declareChildInitFail_o) {
        corto_error("test_load: failed to declare '/test/ObjectMgmt/tc_declareChildInitFail()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ObjectMgmt/tc_declareChildInitFail() */
    if (!corto_checkState(test_ObjectMgmt_tc_declareChildInitFail_o, CORTO_DEFINED)) {
        corto_function(test_ObjectMgmt_tc_declareChildInitFail_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_ObjectMgmt_tc_declareChildInitFail_o)->returnsReference = FALSE;
        corto_method(test_ObjectMgmt_tc_declareChildInitFail_o)->_virtual = FALSE;
        
        /* Bind /test/ObjectMgmt/tc_declareChildInitFail() with C-function */
        corto_function(test_ObjectMgmt_tc_declareChildInitFail_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ObjectMgmt_tc_declareChildInitFail(void *args, void *result);
        corto_function(test_ObjectMgmt_tc_declareChildInitFail_o)->impl = (corto_word)__test_ObjectMgmt_tc_declareChildInitFail;
        if (corto_define(test_ObjectMgmt_tc_declareChildInitFail_o)) {
            corto_error("test_load: failed to define '/test/ObjectMgmt/tc_declareChildInitFail()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ObjectMgmt/tc_declareChildInt() */
    test_ObjectMgmt_tc_declareChildInt_o = corto_declareChild(test_ObjectMgmt_o, "tc_declareChildInt()", test_Case_o);
    if (!test_ObjectMgmt_tc_declareChildInt_o) {
        corto_error("test_load: failed to declare '/test/ObjectMgmt/tc_declareChildInt()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ObjectMgmt/tc_declareChildInt() */
    if (!corto_checkState(test_ObjectMgmt_tc_declareChildInt_o, CORTO_DEFINED)) {
        corto_function(test_ObjectMgmt_tc_declareChildInt_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_ObjectMgmt_tc_declareChildInt_o)->returnsReference = FALSE;
        corto_method(test_ObjectMgmt_tc_declareChildInt_o)->_virtual = FALSE;
        
        /* Bind /test/ObjectMgmt/tc_declareChildInt() with C-function */
        corto_function(test_ObjectMgmt_tc_declareChildInt_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ObjectMgmt_tc_declareChildInt(void *args, void *result);
        corto_function(test_ObjectMgmt_tc_declareChildInt_o)->impl = (corto_word)__test_ObjectMgmt_tc_declareChildInt;
        if (corto_define(test_ObjectMgmt_tc_declareChildInt_o)) {
            corto_error("test_load: failed to define '/test/ObjectMgmt/tc_declareChildInt()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ObjectMgmt/tc_declareChildIntAttr0() */
    test_ObjectMgmt_tc_declareChildIntAttr0_o = corto_declareChild(test_ObjectMgmt_o, "tc_declareChildIntAttr0()", test_Case_o);
    if (!test_ObjectMgmt_tc_declareChildIntAttr0_o) {
        corto_error("test_load: failed to declare '/test/ObjectMgmt/tc_declareChildIntAttr0()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ObjectMgmt/tc_declareChildIntAttr0() */
    if (!corto_checkState(test_ObjectMgmt_tc_declareChildIntAttr0_o, CORTO_DEFINED)) {
        corto_function(test_ObjectMgmt_tc_declareChildIntAttr0_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_ObjectMgmt_tc_declareChildIntAttr0_o)->returnsReference = FALSE;
        corto_method(test_ObjectMgmt_tc_declareChildIntAttr0_o)->_virtual = FALSE;
        
        /* Bind /test/ObjectMgmt/tc_declareChildIntAttr0() with C-function */
        corto_function(test_ObjectMgmt_tc_declareChildIntAttr0_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ObjectMgmt_tc_declareChildIntAttr0(void *args, void *result);
        corto_function(test_ObjectMgmt_tc_declareChildIntAttr0_o)->impl = (corto_word)__test_ObjectMgmt_tc_declareChildIntAttr0;
        if (corto_define(test_ObjectMgmt_tc_declareChildIntAttr0_o)) {
            corto_error("test_load: failed to define '/test/ObjectMgmt/tc_declareChildIntAttr0()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ObjectMgmt/tc_declareChildInvalidType() */
    test_ObjectMgmt_tc_declareChildInvalidType_o = corto_declareChild(test_ObjectMgmt_o, "tc_declareChildInvalidType()", test_Case_o);
    if (!test_ObjectMgmt_tc_declareChildInvalidType_o) {
        corto_error("test_load: failed to declare '/test/ObjectMgmt/tc_declareChildInvalidType()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ObjectMgmt/tc_declareChildInvalidType() */
    if (!corto_checkState(test_ObjectMgmt_tc_declareChildInvalidType_o, CORTO_DEFINED)) {
        corto_function(test_ObjectMgmt_tc_declareChildInvalidType_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_ObjectMgmt_tc_declareChildInvalidType_o)->returnsReference = FALSE;
        corto_method(test_ObjectMgmt_tc_declareChildInvalidType_o)->_virtual = FALSE;
        
        /* Bind /test/ObjectMgmt/tc_declareChildInvalidType() with C-function */
        corto_function(test_ObjectMgmt_tc_declareChildInvalidType_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ObjectMgmt_tc_declareChildInvalidType(void *args, void *result);
        corto_function(test_ObjectMgmt_tc_declareChildInvalidType_o)->impl = (corto_word)__test_ObjectMgmt_tc_declareChildInvalidType;
        if (corto_define(test_ObjectMgmt_tc_declareChildInvalidType_o)) {
            corto_error("test_load: failed to define '/test/ObjectMgmt/tc_declareChildInvalidType()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ObjectMgmt/tc_declareChildNullType() */
    test_ObjectMgmt_tc_declareChildNullType_o = corto_declareChild(test_ObjectMgmt_o, "tc_declareChildNullType()", test_Case_o);
    if (!test_ObjectMgmt_tc_declareChildNullType_o) {
        corto_error("test_load: failed to declare '/test/ObjectMgmt/tc_declareChildNullType()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ObjectMgmt/tc_declareChildNullType() */
    if (!corto_checkState(test_ObjectMgmt_tc_declareChildNullType_o, CORTO_DEFINED)) {
        corto_function(test_ObjectMgmt_tc_declareChildNullType_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_ObjectMgmt_tc_declareChildNullType_o)->returnsReference = FALSE;
        corto_method(test_ObjectMgmt_tc_declareChildNullType_o)->_virtual = FALSE;
        
        /* Bind /test/ObjectMgmt/tc_declareChildNullType() with C-function */
        corto_function(test_ObjectMgmt_tc_declareChildNullType_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ObjectMgmt_tc_declareChildNullType(void *args, void *result);
        corto_function(test_ObjectMgmt_tc_declareChildNullType_o)->impl = (corto_word)__test_ObjectMgmt_tc_declareChildNullType;
        if (corto_define(test_ObjectMgmt_tc_declareChildNullType_o)) {
            corto_error("test_load: failed to define '/test/ObjectMgmt/tc_declareChildNullType()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ObjectMgmt/tc_declareChildParentStateErr() */
    test_ObjectMgmt_tc_declareChildParentStateErr_o = corto_declareChild(test_ObjectMgmt_o, "tc_declareChildParentStateErr()", test_Case_o);
    if (!test_ObjectMgmt_tc_declareChildParentStateErr_o) {
        corto_error("test_load: failed to declare '/test/ObjectMgmt/tc_declareChildParentStateErr()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ObjectMgmt/tc_declareChildParentStateErr() */
    if (!corto_checkState(test_ObjectMgmt_tc_declareChildParentStateErr_o, CORTO_DEFINED)) {
        corto_function(test_ObjectMgmt_tc_declareChildParentStateErr_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_ObjectMgmt_tc_declareChildParentStateErr_o)->returnsReference = FALSE;
        corto_method(test_ObjectMgmt_tc_declareChildParentStateErr_o)->_virtual = FALSE;
        
        /* Bind /test/ObjectMgmt/tc_declareChildParentStateErr() with C-function */
        corto_function(test_ObjectMgmt_tc_declareChildParentStateErr_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ObjectMgmt_tc_declareChildParentStateErr(void *args, void *result);
        corto_function(test_ObjectMgmt_tc_declareChildParentStateErr_o)->impl = (corto_word)__test_ObjectMgmt_tc_declareChildParentStateErr;
        if (corto_define(test_ObjectMgmt_tc_declareChildParentStateErr_o)) {
            corto_error("test_load: failed to define '/test/ObjectMgmt/tc_declareChildParentStateErr()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ObjectMgmt/tc_declareChildParentTypeErr() */
    test_ObjectMgmt_tc_declareChildParentTypeErr_o = corto_declareChild(test_ObjectMgmt_o, "tc_declareChildParentTypeErr()", test_Case_o);
    if (!test_ObjectMgmt_tc_declareChildParentTypeErr_o) {
        corto_error("test_load: failed to declare '/test/ObjectMgmt/tc_declareChildParentTypeErr()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ObjectMgmt/tc_declareChildParentTypeErr() */
    if (!corto_checkState(test_ObjectMgmt_tc_declareChildParentTypeErr_o, CORTO_DEFINED)) {
        corto_function(test_ObjectMgmt_tc_declareChildParentTypeErr_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_ObjectMgmt_tc_declareChildParentTypeErr_o)->returnsReference = FALSE;
        corto_method(test_ObjectMgmt_tc_declareChildParentTypeErr_o)->_virtual = FALSE;
        
        /* Bind /test/ObjectMgmt/tc_declareChildParentTypeErr() with C-function */
        corto_function(test_ObjectMgmt_tc_declareChildParentTypeErr_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ObjectMgmt_tc_declareChildParentTypeErr(void *args, void *result);
        corto_function(test_ObjectMgmt_tc_declareChildParentTypeErr_o)->impl = (corto_word)__test_ObjectMgmt_tc_declareChildParentTypeErr;
        if (corto_define(test_ObjectMgmt_tc_declareChildParentTypeErr_o)) {
            corto_error("test_load: failed to define '/test/ObjectMgmt/tc_declareChildParentTypeErr()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ObjectMgmt/tc_declareChildVoid() */
    test_ObjectMgmt_tc_declareChildVoid_o = corto_declareChild(test_ObjectMgmt_o, "tc_declareChildVoid()", test_Case_o);
    if (!test_ObjectMgmt_tc_declareChildVoid_o) {
        corto_error("test_load: failed to declare '/test/ObjectMgmt/tc_declareChildVoid()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ObjectMgmt/tc_declareChildVoid() */
    if (!corto_checkState(test_ObjectMgmt_tc_declareChildVoid_o, CORTO_DEFINED)) {
        corto_function(test_ObjectMgmt_tc_declareChildVoid_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_ObjectMgmt_tc_declareChildVoid_o)->returnsReference = FALSE;
        corto_method(test_ObjectMgmt_tc_declareChildVoid_o)->_virtual = FALSE;
        
        /* Bind /test/ObjectMgmt/tc_declareChildVoid() with C-function */
        corto_function(test_ObjectMgmt_tc_declareChildVoid_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ObjectMgmt_tc_declareChildVoid(void *args, void *result);
        corto_function(test_ObjectMgmt_tc_declareChildVoid_o)->impl = (corto_word)__test_ObjectMgmt_tc_declareChildVoid;
        if (corto_define(test_ObjectMgmt_tc_declareChildVoid_o)) {
            corto_error("test_load: failed to define '/test/ObjectMgmt/tc_declareChildVoid()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ObjectMgmt/tc_declareChildVoidAttr0() */
    test_ObjectMgmt_tc_declareChildVoidAttr0_o = corto_declareChild(test_ObjectMgmt_o, "tc_declareChildVoidAttr0()", test_Case_o);
    if (!test_ObjectMgmt_tc_declareChildVoidAttr0_o) {
        corto_error("test_load: failed to declare '/test/ObjectMgmt/tc_declareChildVoidAttr0()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ObjectMgmt/tc_declareChildVoidAttr0() */
    if (!corto_checkState(test_ObjectMgmt_tc_declareChildVoidAttr0_o, CORTO_DEFINED)) {
        corto_function(test_ObjectMgmt_tc_declareChildVoidAttr0_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_ObjectMgmt_tc_declareChildVoidAttr0_o)->returnsReference = FALSE;
        corto_method(test_ObjectMgmt_tc_declareChildVoidAttr0_o)->_virtual = FALSE;
        
        /* Bind /test/ObjectMgmt/tc_declareChildVoidAttr0() with C-function */
        corto_function(test_ObjectMgmt_tc_declareChildVoidAttr0_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ObjectMgmt_tc_declareChildVoidAttr0(void *args, void *result);
        corto_function(test_ObjectMgmt_tc_declareChildVoidAttr0_o)->impl = (corto_word)__test_ObjectMgmt_tc_declareChildVoidAttr0;
        if (corto_define(test_ObjectMgmt_tc_declareChildVoidAttr0_o)) {
            corto_error("test_load: failed to define '/test/ObjectMgmt/tc_declareChildVoidAttr0()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ObjectMgmt/tc_declareExistingWithParentState() */
    test_ObjectMgmt_tc_declareExistingWithParentState_o = corto_declareChild(test_ObjectMgmt_o, "tc_declareExistingWithParentState()", test_Case_o);
    if (!test_ObjectMgmt_tc_declareExistingWithParentState_o) {
        corto_error("test_load: failed to declare '/test/ObjectMgmt/tc_declareExistingWithParentState()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ObjectMgmt/tc_declareExistingWithParentState() */
    if (!corto_checkState(test_ObjectMgmt_tc_declareExistingWithParentState_o, CORTO_DEFINED)) {
        corto_function(test_ObjectMgmt_tc_declareExistingWithParentState_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_ObjectMgmt_tc_declareExistingWithParentState_o)->returnsReference = FALSE;
        corto_method(test_ObjectMgmt_tc_declareExistingWithParentState_o)->_virtual = FALSE;
        
        /* Bind /test/ObjectMgmt/tc_declareExistingWithParentState() with C-function */
        corto_function(test_ObjectMgmt_tc_declareExistingWithParentState_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ObjectMgmt_tc_declareExistingWithParentState(void *args, void *result);
        corto_function(test_ObjectMgmt_tc_declareExistingWithParentState_o)->impl = (corto_word)__test_ObjectMgmt_tc_declareExistingWithParentState;
        if (corto_define(test_ObjectMgmt_tc_declareExistingWithParentState_o)) {
            corto_error("test_load: failed to define '/test/ObjectMgmt/tc_declareExistingWithParentState()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ObjectMgmt/tc_declareFoo() */
    test_ObjectMgmt_tc_declareFoo_o = corto_declareChild(test_ObjectMgmt_o, "tc_declareFoo()", test_Case_o);
    if (!test_ObjectMgmt_tc_declareFoo_o) {
        corto_error("test_load: failed to declare '/test/ObjectMgmt/tc_declareFoo()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ObjectMgmt/tc_declareFoo() */
    if (!corto_checkState(test_ObjectMgmt_tc_declareFoo_o, CORTO_DEFINED)) {
        corto_function(test_ObjectMgmt_tc_declareFoo_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_ObjectMgmt_tc_declareFoo_o)->returnsReference = FALSE;
        corto_method(test_ObjectMgmt_tc_declareFoo_o)->_virtual = FALSE;
        
        /* Bind /test/ObjectMgmt/tc_declareFoo() with C-function */
        corto_function(test_ObjectMgmt_tc_declareFoo_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ObjectMgmt_tc_declareFoo(void *args, void *result);
        corto_function(test_ObjectMgmt_tc_declareFoo_o)->impl = (corto_word)__test_ObjectMgmt_tc_declareFoo;
        if (corto_define(test_ObjectMgmt_tc_declareFoo_o)) {
            corto_error("test_load: failed to define '/test/ObjectMgmt/tc_declareFoo()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ObjectMgmt/tc_declareFooAttr0() */
    test_ObjectMgmt_tc_declareFooAttr0_o = corto_declareChild(test_ObjectMgmt_o, "tc_declareFooAttr0()", test_Case_o);
    if (!test_ObjectMgmt_tc_declareFooAttr0_o) {
        corto_error("test_load: failed to declare '/test/ObjectMgmt/tc_declareFooAttr0()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ObjectMgmt/tc_declareFooAttr0() */
    if (!corto_checkState(test_ObjectMgmt_tc_declareFooAttr0_o, CORTO_DEFINED)) {
        corto_function(test_ObjectMgmt_tc_declareFooAttr0_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_ObjectMgmt_tc_declareFooAttr0_o)->returnsReference = FALSE;
        corto_method(test_ObjectMgmt_tc_declareFooAttr0_o)->_virtual = FALSE;
        
        /* Bind /test/ObjectMgmt/tc_declareFooAttr0() with C-function */
        corto_function(test_ObjectMgmt_tc_declareFooAttr0_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ObjectMgmt_tc_declareFooAttr0(void *args, void *result);
        corto_function(test_ObjectMgmt_tc_declareFooAttr0_o)->impl = (corto_word)__test_ObjectMgmt_tc_declareFooAttr0;
        if (corto_define(test_ObjectMgmt_tc_declareFooAttr0_o)) {
            corto_error("test_load: failed to define '/test/ObjectMgmt/tc_declareFooAttr0()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ObjectMgmt/tc_declareInitFail() */
    test_ObjectMgmt_tc_declareInitFail_o = corto_declareChild(test_ObjectMgmt_o, "tc_declareInitFail()", test_Case_o);
    if (!test_ObjectMgmt_tc_declareInitFail_o) {
        corto_error("test_load: failed to declare '/test/ObjectMgmt/tc_declareInitFail()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ObjectMgmt/tc_declareInitFail() */
    if (!corto_checkState(test_ObjectMgmt_tc_declareInitFail_o, CORTO_DEFINED)) {
        corto_function(test_ObjectMgmt_tc_declareInitFail_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_ObjectMgmt_tc_declareInitFail_o)->returnsReference = FALSE;
        corto_method(test_ObjectMgmt_tc_declareInitFail_o)->_virtual = FALSE;
        
        /* Bind /test/ObjectMgmt/tc_declareInitFail() with C-function */
        corto_function(test_ObjectMgmt_tc_declareInitFail_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ObjectMgmt_tc_declareInitFail(void *args, void *result);
        corto_function(test_ObjectMgmt_tc_declareInitFail_o)->impl = (corto_word)__test_ObjectMgmt_tc_declareInitFail;
        if (corto_define(test_ObjectMgmt_tc_declareInitFail_o)) {
            corto_error("test_load: failed to define '/test/ObjectMgmt/tc_declareInitFail()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ObjectMgmt/tc_declareInt() */
    test_ObjectMgmt_tc_declareInt_o = corto_declareChild(test_ObjectMgmt_o, "tc_declareInt()", test_Case_o);
    if (!test_ObjectMgmt_tc_declareInt_o) {
        corto_error("test_load: failed to declare '/test/ObjectMgmt/tc_declareInt()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ObjectMgmt/tc_declareInt() */
    if (!corto_checkState(test_ObjectMgmt_tc_declareInt_o, CORTO_DEFINED)) {
        corto_function(test_ObjectMgmt_tc_declareInt_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_ObjectMgmt_tc_declareInt_o)->returnsReference = FALSE;
        corto_method(test_ObjectMgmt_tc_declareInt_o)->_virtual = FALSE;
        
        /* Bind /test/ObjectMgmt/tc_declareInt() with C-function */
        corto_function(test_ObjectMgmt_tc_declareInt_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ObjectMgmt_tc_declareInt(void *args, void *result);
        corto_function(test_ObjectMgmt_tc_declareInt_o)->impl = (corto_word)__test_ObjectMgmt_tc_declareInt;
        if (corto_define(test_ObjectMgmt_tc_declareInt_o)) {
            corto_error("test_load: failed to define '/test/ObjectMgmt/tc_declareInt()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ObjectMgmt/tc_declareIntAttr0() */
    test_ObjectMgmt_tc_declareIntAttr0_o = corto_declareChild(test_ObjectMgmt_o, "tc_declareIntAttr0()", test_Case_o);
    if (!test_ObjectMgmt_tc_declareIntAttr0_o) {
        corto_error("test_load: failed to declare '/test/ObjectMgmt/tc_declareIntAttr0()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ObjectMgmt/tc_declareIntAttr0() */
    if (!corto_checkState(test_ObjectMgmt_tc_declareIntAttr0_o, CORTO_DEFINED)) {
        corto_function(test_ObjectMgmt_tc_declareIntAttr0_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_ObjectMgmt_tc_declareIntAttr0_o)->returnsReference = FALSE;
        corto_method(test_ObjectMgmt_tc_declareIntAttr0_o)->_virtual = FALSE;
        
        /* Bind /test/ObjectMgmt/tc_declareIntAttr0() with C-function */
        corto_function(test_ObjectMgmt_tc_declareIntAttr0_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ObjectMgmt_tc_declareIntAttr0(void *args, void *result);
        corto_function(test_ObjectMgmt_tc_declareIntAttr0_o)->impl = (corto_word)__test_ObjectMgmt_tc_declareIntAttr0;
        if (corto_define(test_ObjectMgmt_tc_declareIntAttr0_o)) {
            corto_error("test_load: failed to define '/test/ObjectMgmt/tc_declareIntAttr0()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ObjectMgmt/tc_declareInvalidType() */
    test_ObjectMgmt_tc_declareInvalidType_o = corto_declareChild(test_ObjectMgmt_o, "tc_declareInvalidType()", test_Case_o);
    if (!test_ObjectMgmt_tc_declareInvalidType_o) {
        corto_error("test_load: failed to declare '/test/ObjectMgmt/tc_declareInvalidType()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ObjectMgmt/tc_declareInvalidType() */
    if (!corto_checkState(test_ObjectMgmt_tc_declareInvalidType_o, CORTO_DEFINED)) {
        corto_function(test_ObjectMgmt_tc_declareInvalidType_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_ObjectMgmt_tc_declareInvalidType_o)->returnsReference = FALSE;
        corto_method(test_ObjectMgmt_tc_declareInvalidType_o)->_virtual = FALSE;
        
        /* Bind /test/ObjectMgmt/tc_declareInvalidType() with C-function */
        corto_function(test_ObjectMgmt_tc_declareInvalidType_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ObjectMgmt_tc_declareInvalidType(void *args, void *result);
        corto_function(test_ObjectMgmt_tc_declareInvalidType_o)->impl = (corto_word)__test_ObjectMgmt_tc_declareInvalidType;
        if (corto_define(test_ObjectMgmt_tc_declareInvalidType_o)) {
            corto_error("test_load: failed to define '/test/ObjectMgmt/tc_declareInvalidType()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ObjectMgmt/tc_declareNullType() */
    test_ObjectMgmt_tc_declareNullType_o = corto_declareChild(test_ObjectMgmt_o, "tc_declareNullType()", test_Case_o);
    if (!test_ObjectMgmt_tc_declareNullType_o) {
        corto_error("test_load: failed to declare '/test/ObjectMgmt/tc_declareNullType()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ObjectMgmt/tc_declareNullType() */
    if (!corto_checkState(test_ObjectMgmt_tc_declareNullType_o, CORTO_DEFINED)) {
        corto_function(test_ObjectMgmt_tc_declareNullType_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_ObjectMgmt_tc_declareNullType_o)->returnsReference = FALSE;
        corto_method(test_ObjectMgmt_tc_declareNullType_o)->_virtual = FALSE;
        
        /* Bind /test/ObjectMgmt/tc_declareNullType() with C-function */
        corto_function(test_ObjectMgmt_tc_declareNullType_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ObjectMgmt_tc_declareNullType(void *args, void *result);
        corto_function(test_ObjectMgmt_tc_declareNullType_o)->impl = (corto_word)__test_ObjectMgmt_tc_declareNullType;
        if (corto_define(test_ObjectMgmt_tc_declareNullType_o)) {
            corto_error("test_load: failed to define '/test/ObjectMgmt/tc_declareNullType()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ObjectMgmt/tc_declareVoid() */
    test_ObjectMgmt_tc_declareVoid_o = corto_declareChild(test_ObjectMgmt_o, "tc_declareVoid()", test_Case_o);
    if (!test_ObjectMgmt_tc_declareVoid_o) {
        corto_error("test_load: failed to declare '/test/ObjectMgmt/tc_declareVoid()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ObjectMgmt/tc_declareVoid() */
    if (!corto_checkState(test_ObjectMgmt_tc_declareVoid_o, CORTO_DEFINED)) {
        corto_function(test_ObjectMgmt_tc_declareVoid_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_ObjectMgmt_tc_declareVoid_o)->returnsReference = FALSE;
        corto_method(test_ObjectMgmt_tc_declareVoid_o)->_virtual = FALSE;
        
        /* Bind /test/ObjectMgmt/tc_declareVoid() with C-function */
        corto_function(test_ObjectMgmt_tc_declareVoid_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ObjectMgmt_tc_declareVoid(void *args, void *result);
        corto_function(test_ObjectMgmt_tc_declareVoid_o)->impl = (corto_word)__test_ObjectMgmt_tc_declareVoid;
        if (corto_define(test_ObjectMgmt_tc_declareVoid_o)) {
            corto_error("test_load: failed to define '/test/ObjectMgmt/tc_declareVoid()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ObjectMgmt/tc_declareVoidAttr0() */
    test_ObjectMgmt_tc_declareVoidAttr0_o = corto_declareChild(test_ObjectMgmt_o, "tc_declareVoidAttr0()", test_Case_o);
    if (!test_ObjectMgmt_tc_declareVoidAttr0_o) {
        corto_error("test_load: failed to declare '/test/ObjectMgmt/tc_declareVoidAttr0()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ObjectMgmt/tc_declareVoidAttr0() */
    if (!corto_checkState(test_ObjectMgmt_tc_declareVoidAttr0_o, CORTO_DEFINED)) {
        corto_function(test_ObjectMgmt_tc_declareVoidAttr0_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_ObjectMgmt_tc_declareVoidAttr0_o)->returnsReference = FALSE;
        corto_method(test_ObjectMgmt_tc_declareVoidAttr0_o)->_virtual = FALSE;
        
        /* Bind /test/ObjectMgmt/tc_declareVoidAttr0() with C-function */
        corto_function(test_ObjectMgmt_tc_declareVoidAttr0_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ObjectMgmt_tc_declareVoidAttr0(void *args, void *result);
        corto_function(test_ObjectMgmt_tc_declareVoidAttr0_o)->impl = (corto_word)__test_ObjectMgmt_tc_declareVoidAttr0;
        if (corto_define(test_ObjectMgmt_tc_declareVoidAttr0_o)) {
            corto_error("test_load: failed to define '/test/ObjectMgmt/tc_declareVoidAttr0()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ObjectMgmt/tc_defineFoo() */
    test_ObjectMgmt_tc_defineFoo_o = corto_declareChild(test_ObjectMgmt_o, "tc_defineFoo()", test_Case_o);
    if (!test_ObjectMgmt_tc_defineFoo_o) {
        corto_error("test_load: failed to declare '/test/ObjectMgmt/tc_defineFoo()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ObjectMgmt/tc_defineFoo() */
    if (!corto_checkState(test_ObjectMgmt_tc_defineFoo_o, CORTO_DEFINED)) {
        corto_function(test_ObjectMgmt_tc_defineFoo_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_ObjectMgmt_tc_defineFoo_o)->returnsReference = FALSE;
        corto_method(test_ObjectMgmt_tc_defineFoo_o)->_virtual = FALSE;
        
        /* Bind /test/ObjectMgmt/tc_defineFoo() with C-function */
        corto_function(test_ObjectMgmt_tc_defineFoo_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ObjectMgmt_tc_defineFoo(void *args, void *result);
        corto_function(test_ObjectMgmt_tc_defineFoo_o)->impl = (corto_word)__test_ObjectMgmt_tc_defineFoo;
        if (corto_define(test_ObjectMgmt_tc_defineFoo_o)) {
            corto_error("test_load: failed to define '/test/ObjectMgmt/tc_defineFoo()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ObjectMgmt/tc_defineFooAttr0() */
    test_ObjectMgmt_tc_defineFooAttr0_o = corto_declareChild(test_ObjectMgmt_o, "tc_defineFooAttr0()", test_Case_o);
    if (!test_ObjectMgmt_tc_defineFooAttr0_o) {
        corto_error("test_load: failed to declare '/test/ObjectMgmt/tc_defineFooAttr0()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ObjectMgmt/tc_defineFooAttr0() */
    if (!corto_checkState(test_ObjectMgmt_tc_defineFooAttr0_o, CORTO_DEFINED)) {
        corto_function(test_ObjectMgmt_tc_defineFooAttr0_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_ObjectMgmt_tc_defineFooAttr0_o)->returnsReference = FALSE;
        corto_method(test_ObjectMgmt_tc_defineFooAttr0_o)->_virtual = FALSE;
        
        /* Bind /test/ObjectMgmt/tc_defineFooAttr0() with C-function */
        corto_function(test_ObjectMgmt_tc_defineFooAttr0_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ObjectMgmt_tc_defineFooAttr0(void *args, void *result);
        corto_function(test_ObjectMgmt_tc_defineFooAttr0_o)->impl = (corto_word)__test_ObjectMgmt_tc_defineFooAttr0;
        if (corto_define(test_ObjectMgmt_tc_defineFooAttr0_o)) {
            corto_error("test_load: failed to define '/test/ObjectMgmt/tc_defineFooAttr0()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ObjectMgmt/tc_defineFooFail() */
    test_ObjectMgmt_tc_defineFooFail_o = corto_declareChild(test_ObjectMgmt_o, "tc_defineFooFail()", test_Case_o);
    if (!test_ObjectMgmt_tc_defineFooFail_o) {
        corto_error("test_load: failed to declare '/test/ObjectMgmt/tc_defineFooFail()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ObjectMgmt/tc_defineFooFail() */
    if (!corto_checkState(test_ObjectMgmt_tc_defineFooFail_o, CORTO_DEFINED)) {
        corto_function(test_ObjectMgmt_tc_defineFooFail_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_ObjectMgmt_tc_defineFooFail_o)->returnsReference = FALSE;
        corto_method(test_ObjectMgmt_tc_defineFooFail_o)->_virtual = FALSE;
        
        /* Bind /test/ObjectMgmt/tc_defineFooFail() with C-function */
        corto_function(test_ObjectMgmt_tc_defineFooFail_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ObjectMgmt_tc_defineFooFail(void *args, void *result);
        corto_function(test_ObjectMgmt_tc_defineFooFail_o)->impl = (corto_word)__test_ObjectMgmt_tc_defineFooFail;
        if (corto_define(test_ObjectMgmt_tc_defineFooFail_o)) {
            corto_error("test_load: failed to define '/test/ObjectMgmt/tc_defineFooFail()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ObjectMgmt/tc_defineInt() */
    test_ObjectMgmt_tc_defineInt_o = corto_declareChild(test_ObjectMgmt_o, "tc_defineInt()", test_Case_o);
    if (!test_ObjectMgmt_tc_defineInt_o) {
        corto_error("test_load: failed to declare '/test/ObjectMgmt/tc_defineInt()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ObjectMgmt/tc_defineInt() */
    if (!corto_checkState(test_ObjectMgmt_tc_defineInt_o, CORTO_DEFINED)) {
        corto_function(test_ObjectMgmt_tc_defineInt_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_ObjectMgmt_tc_defineInt_o)->returnsReference = FALSE;
        corto_method(test_ObjectMgmt_tc_defineInt_o)->_virtual = FALSE;
        
        /* Bind /test/ObjectMgmt/tc_defineInt() with C-function */
        corto_function(test_ObjectMgmt_tc_defineInt_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ObjectMgmt_tc_defineInt(void *args, void *result);
        corto_function(test_ObjectMgmt_tc_defineInt_o)->impl = (corto_word)__test_ObjectMgmt_tc_defineInt;
        if (corto_define(test_ObjectMgmt_tc_defineInt_o)) {
            corto_error("test_load: failed to define '/test/ObjectMgmt/tc_defineInt()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ObjectMgmt/tc_defineIntAttr0() */
    test_ObjectMgmt_tc_defineIntAttr0_o = corto_declareChild(test_ObjectMgmt_o, "tc_defineIntAttr0()", test_Case_o);
    if (!test_ObjectMgmt_tc_defineIntAttr0_o) {
        corto_error("test_load: failed to declare '/test/ObjectMgmt/tc_defineIntAttr0()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ObjectMgmt/tc_defineIntAttr0() */
    if (!corto_checkState(test_ObjectMgmt_tc_defineIntAttr0_o, CORTO_DEFINED)) {
        corto_function(test_ObjectMgmt_tc_defineIntAttr0_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_ObjectMgmt_tc_defineIntAttr0_o)->returnsReference = FALSE;
        corto_method(test_ObjectMgmt_tc_defineIntAttr0_o)->_virtual = FALSE;
        
        /* Bind /test/ObjectMgmt/tc_defineIntAttr0() with C-function */
        corto_function(test_ObjectMgmt_tc_defineIntAttr0_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ObjectMgmt_tc_defineIntAttr0(void *args, void *result);
        corto_function(test_ObjectMgmt_tc_defineIntAttr0_o)->impl = (corto_word)__test_ObjectMgmt_tc_defineIntAttr0;
        if (corto_define(test_ObjectMgmt_tc_defineIntAttr0_o)) {
            corto_error("test_load: failed to define '/test/ObjectMgmt/tc_defineIntAttr0()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ObjectMgmt/tc_defineVoid() */
    test_ObjectMgmt_tc_defineVoid_o = corto_declareChild(test_ObjectMgmt_o, "tc_defineVoid()", test_Case_o);
    if (!test_ObjectMgmt_tc_defineVoid_o) {
        corto_error("test_load: failed to declare '/test/ObjectMgmt/tc_defineVoid()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ObjectMgmt/tc_defineVoid() */
    if (!corto_checkState(test_ObjectMgmt_tc_defineVoid_o, CORTO_DEFINED)) {
        corto_function(test_ObjectMgmt_tc_defineVoid_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_ObjectMgmt_tc_defineVoid_o)->returnsReference = FALSE;
        corto_method(test_ObjectMgmt_tc_defineVoid_o)->_virtual = FALSE;
        
        /* Bind /test/ObjectMgmt/tc_defineVoid() with C-function */
        corto_function(test_ObjectMgmt_tc_defineVoid_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ObjectMgmt_tc_defineVoid(void *args, void *result);
        corto_function(test_ObjectMgmt_tc_defineVoid_o)->impl = (corto_word)__test_ObjectMgmt_tc_defineVoid;
        if (corto_define(test_ObjectMgmt_tc_defineVoid_o)) {
            corto_error("test_load: failed to define '/test/ObjectMgmt/tc_defineVoid()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ObjectMgmt/tc_defineVoidAttr0() */
    test_ObjectMgmt_tc_defineVoidAttr0_o = corto_declareChild(test_ObjectMgmt_o, "tc_defineVoidAttr0()", test_Case_o);
    if (!test_ObjectMgmt_tc_defineVoidAttr0_o) {
        corto_error("test_load: failed to declare '/test/ObjectMgmt/tc_defineVoidAttr0()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ObjectMgmt/tc_defineVoidAttr0() */
    if (!corto_checkState(test_ObjectMgmt_tc_defineVoidAttr0_o, CORTO_DEFINED)) {
        corto_function(test_ObjectMgmt_tc_defineVoidAttr0_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_ObjectMgmt_tc_defineVoidAttr0_o)->returnsReference = FALSE;
        corto_method(test_ObjectMgmt_tc_defineVoidAttr0_o)->_virtual = FALSE;
        
        /* Bind /test/ObjectMgmt/tc_defineVoidAttr0() with C-function */
        corto_function(test_ObjectMgmt_tc_defineVoidAttr0_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ObjectMgmt_tc_defineVoidAttr0(void *args, void *result);
        corto_function(test_ObjectMgmt_tc_defineVoidAttr0_o)->impl = (corto_word)__test_ObjectMgmt_tc_defineVoidAttr0;
        if (corto_define(test_ObjectMgmt_tc_defineVoidAttr0_o)) {
            corto_error("test_load: failed to define '/test/ObjectMgmt/tc_defineVoidAttr0()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ObjectMgmt/tc_drop() */
    test_ObjectMgmt_tc_drop_o = corto_declareChild(test_ObjectMgmt_o, "tc_drop()", test_Case_o);
    if (!test_ObjectMgmt_tc_drop_o) {
        corto_error("test_load: failed to declare '/test/ObjectMgmt/tc_drop()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ObjectMgmt/tc_drop() */
    if (!corto_checkState(test_ObjectMgmt_tc_drop_o, CORTO_DEFINED)) {
        corto_function(test_ObjectMgmt_tc_drop_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_ObjectMgmt_tc_drop_o)->returnsReference = FALSE;
        corto_method(test_ObjectMgmt_tc_drop_o)->_virtual = FALSE;
        
        /* Bind /test/ObjectMgmt/tc_drop() with C-function */
        corto_function(test_ObjectMgmt_tc_drop_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ObjectMgmt_tc_drop(void *args, void *result);
        corto_function(test_ObjectMgmt_tc_drop_o)->impl = (corto_word)__test_ObjectMgmt_tc_drop;
        if (corto_define(test_ObjectMgmt_tc_drop_o)) {
            corto_error("test_load: failed to define '/test/ObjectMgmt/tc_drop()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ObjectMgmt/tc_invalidate() */
    test_ObjectMgmt_tc_invalidate_o = corto_declareChild(test_ObjectMgmt_o, "tc_invalidate()", test_Case_o);
    if (!test_ObjectMgmt_tc_invalidate_o) {
        corto_error("test_load: failed to declare '/test/ObjectMgmt/tc_invalidate()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ObjectMgmt/tc_invalidate() */
    if (!corto_checkState(test_ObjectMgmt_tc_invalidate_o, CORTO_DEFINED)) {
        corto_function(test_ObjectMgmt_tc_invalidate_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_ObjectMgmt_tc_invalidate_o)->returnsReference = FALSE;
        corto_method(test_ObjectMgmt_tc_invalidate_o)->_virtual = FALSE;
        
        /* Bind /test/ObjectMgmt/tc_invalidate() with C-function */
        corto_function(test_ObjectMgmt_tc_invalidate_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ObjectMgmt_tc_invalidate(void *args, void *result);
        corto_function(test_ObjectMgmt_tc_invalidate_o)->impl = (corto_word)__test_ObjectMgmt_tc_invalidate;
        if (corto_define(test_ObjectMgmt_tc_invalidate_o)) {
            corto_error("test_load: failed to define '/test/ObjectMgmt/tc_invalidate()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ObjectMgmt/tc_redeclareWithDifferentType() */
    test_ObjectMgmt_tc_redeclareWithDifferentType_o = corto_declareChild(test_ObjectMgmt_o, "tc_redeclareWithDifferentType()", test_Case_o);
    if (!test_ObjectMgmt_tc_redeclareWithDifferentType_o) {
        corto_error("test_load: failed to declare '/test/ObjectMgmt/tc_redeclareWithDifferentType()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ObjectMgmt/tc_redeclareWithDifferentType() */
    if (!corto_checkState(test_ObjectMgmt_tc_redeclareWithDifferentType_o, CORTO_DEFINED)) {
        corto_function(test_ObjectMgmt_tc_redeclareWithDifferentType_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_ObjectMgmt_tc_redeclareWithDifferentType_o)->returnsReference = FALSE;
        corto_method(test_ObjectMgmt_tc_redeclareWithDifferentType_o)->_virtual = FALSE;
        
        /* Bind /test/ObjectMgmt/tc_redeclareWithDifferentType() with C-function */
        corto_function(test_ObjectMgmt_tc_redeclareWithDifferentType_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ObjectMgmt_tc_redeclareWithDifferentType(void *args, void *result);
        corto_function(test_ObjectMgmt_tc_redeclareWithDifferentType_o)->impl = (corto_word)__test_ObjectMgmt_tc_redeclareWithDifferentType;
        if (corto_define(test_ObjectMgmt_tc_redeclareWithDifferentType_o)) {
            corto_error("test_load: failed to define '/test/ObjectMgmt/tc_redeclareWithDifferentType()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ol_any(bool a) */
    test_ol_any_bool_o = corto_declareChild(test_o, "ol_any(bool a)", corto_function_o);
    if (!test_ol_any_bool_o) {
        corto_error("test_load: failed to declare '/test/ol_any(bool a)' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ol_any(bool a) */
    if (!corto_checkState(test_ol_any_bool_o, CORTO_DEFINED)) {
        test_ol_any_bool_o->returnType = corto_resolve(NULL, "/corto/lang/void");
        test_ol_any_bool_o->returnsReference = FALSE;
        
        /* Bind /test/ol_any(bool a) with C-function */
        corto_function(test_ol_any_bool_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ol_any_bool(void *args, void *result);
        corto_function(test_ol_any_bool_o)->impl = (corto_word)__test_ol_any_bool;
        if (corto_define(test_ol_any_bool_o)) {
            corto_error("test_load: failed to define '/test/ol_any(bool a)' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ol_any(char a) */
    test_ol_any_char_o = corto_declareChild(test_o, "ol_any(char a)", corto_function_o);
    if (!test_ol_any_char_o) {
        corto_error("test_load: failed to declare '/test/ol_any(char a)' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ol_any(char a) */
    if (!corto_checkState(test_ol_any_char_o, CORTO_DEFINED)) {
        test_ol_any_char_o->returnType = corto_resolve(NULL, "/corto/lang/void");
        test_ol_any_char_o->returnsReference = FALSE;
        
        /* Bind /test/ol_any(char a) with C-function */
        corto_function(test_ol_any_char_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ol_any_char(void *args, void *result);
        corto_function(test_ol_any_char_o)->impl = (corto_word)__test_ol_any_char;
        if (corto_define(test_ol_any_char_o)) {
            corto_error("test_load: failed to define '/test/ol_any(char a)' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ol_any(float32 a) */
    test_ol_any_float32_o = corto_declareChild(test_o, "ol_any(float32 a)", corto_function_o);
    if (!test_ol_any_float32_o) {
        corto_error("test_load: failed to declare '/test/ol_any(float32 a)' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ol_any(float32 a) */
    if (!corto_checkState(test_ol_any_float32_o, CORTO_DEFINED)) {
        test_ol_any_float32_o->returnType = corto_resolve(NULL, "/corto/lang/void");
        test_ol_any_float32_o->returnsReference = FALSE;
        
        /* Bind /test/ol_any(float32 a) with C-function */
        corto_function(test_ol_any_float32_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ol_any_float32(void *args, void *result);
        corto_function(test_ol_any_float32_o)->impl = (corto_word)__test_ol_any_float32;
        if (corto_define(test_ol_any_float32_o)) {
            corto_error("test_load: failed to define '/test/ol_any(float32 a)' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ol_any(int32 a) */
    test_ol_any_int32_o = corto_declareChild(test_o, "ol_any(int32 a)", corto_function_o);
    if (!test_ol_any_int32_o) {
        corto_error("test_load: failed to declare '/test/ol_any(int32 a)' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ol_any(int32 a) */
    if (!corto_checkState(test_ol_any_int32_o, CORTO_DEFINED)) {
        test_ol_any_int32_o->returnType = corto_resolve(NULL, "/corto/lang/void");
        test_ol_any_int32_o->returnsReference = FALSE;
        
        /* Bind /test/ol_any(int32 a) with C-function */
        corto_function(test_ol_any_int32_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ol_any_int32(void *args, void *result);
        corto_function(test_ol_any_int32_o)->impl = (corto_word)__test_ol_any_int32;
        if (corto_define(test_ol_any_int32_o)) {
            corto_error("test_load: failed to define '/test/ol_any(int32 a)' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ol_any(object a) */
    test_ol_any_object_o = corto_declareChild(test_o, "ol_any(object a)", corto_function_o);
    if (!test_ol_any_object_o) {
        corto_error("test_load: failed to declare '/test/ol_any(object a)' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ol_any(object a) */
    if (!corto_checkState(test_ol_any_object_o, CORTO_DEFINED)) {
        test_ol_any_object_o->returnType = corto_resolve(NULL, "/corto/lang/void");
        test_ol_any_object_o->returnsReference = FALSE;
        
        /* Bind /test/ol_any(object a) with C-function */
        corto_function(test_ol_any_object_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ol_any_object(void *args, void *result);
        corto_function(test_ol_any_object_o)->impl = (corto_word)__test_ol_any_object;
        if (corto_define(test_ol_any_object_o)) {
            corto_error("test_load: failed to define '/test/ol_any(object a)' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ol_any(string a) */
    test_ol_any_string_o = corto_declareChild(test_o, "ol_any(string a)", corto_function_o);
    if (!test_ol_any_string_o) {
        corto_error("test_load: failed to declare '/test/ol_any(string a)' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ol_any(string a) */
    if (!corto_checkState(test_ol_any_string_o, CORTO_DEFINED)) {
        test_ol_any_string_o->returnType = corto_resolve(NULL, "/corto/lang/void");
        test_ol_any_string_o->returnsReference = FALSE;
        
        /* Bind /test/ol_any(string a) with C-function */
        corto_function(test_ol_any_string_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ol_any_string(void *args, void *result);
        corto_function(test_ol_any_string_o)->impl = (corto_word)__test_ol_any_string;
        if (corto_define(test_ol_any_string_o)) {
            corto_error("test_load: failed to define '/test/ol_any(string a)' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ol_bool(bool a) */
    test_ol_bool_o = corto_declareChild(test_o, "ol_bool(bool a)", corto_function_o);
    if (!test_ol_bool_o) {
        corto_error("test_load: failed to declare '/test/ol_bool(bool a)' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ol_bool(bool a) */
    if (!corto_checkState(test_ol_bool_o, CORTO_DEFINED)) {
        test_ol_bool_o->returnType = corto_resolve(NULL, "/corto/lang/void");
        test_ol_bool_o->returnsReference = FALSE;
        
        /* Bind /test/ol_bool(bool a) with C-function */
        corto_function(test_ol_bool_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ol_bool(void *args, void *result);
        corto_function(test_ol_bool_o)->impl = (corto_word)__test_ol_bool;
        if (corto_define(test_ol_bool_o)) {
            corto_error("test_load: failed to define '/test/ol_bool(bool a)' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ol_int(int32 a) */
    test_ol_int_o = corto_declareChild(test_o, "ol_int(int32 a)", corto_function_o);
    if (!test_ol_int_o) {
        corto_error("test_load: failed to declare '/test/ol_int(int32 a)' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ol_int(int32 a) */
    if (!corto_checkState(test_ol_int_o, CORTO_DEFINED)) {
        test_ol_int_o->returnType = corto_resolve(NULL, "/corto/lang/void");
        test_ol_int_o->returnsReference = FALSE;
        
        /* Bind /test/ol_int(int32 a) with C-function */
        corto_function(test_ol_int_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ol_int(void *args, void *result);
        corto_function(test_ol_int_o)->impl = (corto_word)__test_ol_int;
        if (corto_define(test_ol_int_o)) {
            corto_error("test_load: failed to define '/test/ol_int(int32 a)' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ol_null(bool a) */
    test_ol_null_bool_o = corto_declareChild(test_o, "ol_null(bool a)", corto_function_o);
    if (!test_ol_null_bool_o) {
        corto_error("test_load: failed to declare '/test/ol_null(bool a)' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ol_null(bool a) */
    if (!corto_checkState(test_ol_null_bool_o, CORTO_DEFINED)) {
        test_ol_null_bool_o->returnType = corto_resolve(NULL, "/corto/lang/void");
        test_ol_null_bool_o->returnsReference = FALSE;
        
        /* Bind /test/ol_null(bool a) with C-function */
        corto_function(test_ol_null_bool_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ol_null_bool(void *args, void *result);
        corto_function(test_ol_null_bool_o)->impl = (corto_word)__test_ol_null_bool;
        if (corto_define(test_ol_null_bool_o)) {
            corto_error("test_load: failed to define '/test/ol_null(bool a)' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ol_null(object a) */
    test_ol_null_object_o = corto_declareChild(test_o, "ol_null(object a)", corto_function_o);
    if (!test_ol_null_object_o) {
        corto_error("test_load: failed to declare '/test/ol_null(object a)' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ol_null(object a) */
    if (!corto_checkState(test_ol_null_object_o, CORTO_DEFINED)) {
        test_ol_null_object_o->returnType = corto_resolve(NULL, "/corto/lang/void");
        test_ol_null_object_o->returnsReference = FALSE;
        
        /* Bind /test/ol_null(object a) with C-function */
        corto_function(test_ol_null_object_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ol_null_object(void *args, void *result);
        corto_function(test_ol_null_object_o)->impl = (corto_word)__test_ol_null_object;
        if (corto_define(test_ol_null_object_o)) {
            corto_error("test_load: failed to define '/test/ol_null(object a)' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ol_null(string a) */
    test_ol_null_string_o = corto_declareChild(test_o, "ol_null(string a)", corto_function_o);
    if (!test_ol_null_string_o) {
        corto_error("test_load: failed to declare '/test/ol_null(string a)' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ol_null(string a) */
    if (!corto_checkState(test_ol_null_string_o, CORTO_DEFINED)) {
        test_ol_null_string_o->returnType = corto_resolve(NULL, "/corto/lang/void");
        test_ol_null_string_o->returnsReference = FALSE;
        
        /* Bind /test/ol_null(string a) with C-function */
        corto_function(test_ol_null_string_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ol_null_string(void *args, void *result);
        corto_function(test_ol_null_string_o)->impl = (corto_word)__test_ol_null_string;
        if (corto_define(test_ol_null_string_o)) {
            corto_error("test_load: failed to define '/test/ol_null(string a)' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ol_num(float64 a) */
    test_ol_num_float64_o = corto_declareChild(test_o, "ol_num(float64 a)", corto_function_o);
    if (!test_ol_num_float64_o) {
        corto_error("test_load: failed to declare '/test/ol_num(float64 a)' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ol_num(float64 a) */
    if (!corto_checkState(test_ol_num_float64_o, CORTO_DEFINED)) {
        test_ol_num_float64_o->returnType = corto_resolve(NULL, "/corto/lang/void");
        test_ol_num_float64_o->returnsReference = FALSE;
        
        /* Bind /test/ol_num(float64 a) with C-function */
        corto_function(test_ol_num_float64_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ol_num_float64(void *args, void *result);
        corto_function(test_ol_num_float64_o)->impl = (corto_word)__test_ol_num_float64;
        if (corto_define(test_ol_num_float64_o)) {
            corto_error("test_load: failed to define '/test/ol_num(float64 a)' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ol_num(int32 a) */
    test_ol_num_int32_o = corto_declareChild(test_o, "ol_num(int32 a)", corto_function_o);
    if (!test_ol_num_int32_o) {
        corto_error("test_load: failed to declare '/test/ol_num(int32 a)' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ol_num(int32 a) */
    if (!corto_checkState(test_ol_num_int32_o, CORTO_DEFINED)) {
        test_ol_num_int32_o->returnType = corto_resolve(NULL, "/corto/lang/void");
        test_ol_num_int32_o->returnsReference = FALSE;
        
        /* Bind /test/ol_num(int32 a) with C-function */
        corto_function(test_ol_num_int32_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ol_num_int32(void *args, void *result);
        corto_function(test_ol_num_int32_o)->impl = (corto_word)__test_ol_num_int32;
        if (corto_define(test_ol_num_int32_o)) {
            corto_error("test_load: failed to define '/test/ol_num(int32 a)' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ol_object(object a) */
    test_ol_object_o = corto_declareChild(test_o, "ol_object(object a)", corto_function_o);
    if (!test_ol_object_o) {
        corto_error("test_load: failed to declare '/test/ol_object(object a)' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ol_object(object a) */
    if (!corto_checkState(test_ol_object_o, CORTO_DEFINED)) {
        test_ol_object_o->returnType = corto_resolve(NULL, "/corto/lang/void");
        test_ol_object_o->returnsReference = FALSE;
        
        /* Bind /test/ol_object(object a) with C-function */
        corto_function(test_ol_object_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ol_object(void *args, void *result);
        corto_function(test_ol_object_o)->impl = (corto_word)__test_ol_object;
        if (corto_define(test_ol_object_o)) {
            corto_error("test_load: failed to define '/test/ol_object(object a)' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ol_string(string a) */
    test_ol_string_o = corto_declareChild(test_o, "ol_string(string a)", corto_function_o);
    if (!test_ol_string_o) {
        corto_error("test_load: failed to declare '/test/ol_string(string a)' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ol_string(string a) */
    if (!corto_checkState(test_ol_string_o, CORTO_DEFINED)) {
        test_ol_string_o->returnType = corto_resolve(NULL, "/corto/lang/void");
        test_ol_string_o->returnsReference = FALSE;
        
        /* Bind /test/ol_string(string a) with C-function */
        corto_function(test_ol_string_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ol_string(void *args, void *result);
        corto_function(test_ol_string_o)->impl = (corto_word)__test_ol_string;
        if (corto_define(test_ol_string_o)) {
            corto_error("test_load: failed to define '/test/ol_string(string a)' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ol_uint(int32 a) */
    test_ol_uint_o = corto_declareChild(test_o, "ol_uint(int32 a)", corto_function_o);
    if (!test_ol_uint_o) {
        corto_error("test_load: failed to declare '/test/ol_uint(int32 a)' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ol_uint(int32 a) */
    if (!corto_checkState(test_ol_uint_o, CORTO_DEFINED)) {
        test_ol_uint_o->returnType = corto_resolve(NULL, "/corto/lang/void");
        test_ol_uint_o->returnsReference = FALSE;
        
        /* Bind /test/ol_uint(int32 a) with C-function */
        corto_function(test_ol_uint_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ol_uint(void *args, void *result);
        corto_function(test_ol_uint_o)->impl = (corto_word)__test_ol_uint;
        if (corto_define(test_ol_uint_o)) {
            corto_error("test_load: failed to define '/test/ol_uint(int32 a)' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ol_wildcard(float32 a,string b) */
    test_ol_wildcard_float32_string_o = corto_declareChild(test_o, "ol_wildcard(float32 a,string b)", corto_function_o);
    if (!test_ol_wildcard_float32_string_o) {
        corto_error("test_load: failed to declare '/test/ol_wildcard(float32 a,string b)' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ol_wildcard(float32 a,string b) */
    if (!corto_checkState(test_ol_wildcard_float32_string_o, CORTO_DEFINED)) {
        test_ol_wildcard_float32_string_o->returnType = corto_resolve(NULL, "/corto/lang/void");
        test_ol_wildcard_float32_string_o->returnsReference = FALSE;
        
        /* Bind /test/ol_wildcard(float32 a,string b) with C-function */
        corto_function(test_ol_wildcard_float32_string_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ol_wildcard_float32_string(void *args, void *result);
        corto_function(test_ol_wildcard_float32_string_o)->impl = (corto_word)__test_ol_wildcard_float32_string;
        if (corto_define(test_ol_wildcard_float32_string_o)) {
            corto_error("test_load: failed to define '/test/ol_wildcard(float32 a,string b)' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/ol_wildcard(int32 a,string b) */
    test_ol_wildcard_int32_string_o = corto_declareChild(test_o, "ol_wildcard(int32 a,string b)", corto_function_o);
    if (!test_ol_wildcard_int32_string_o) {
        corto_error("test_load: failed to declare '/test/ol_wildcard(int32 a,string b)' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/ol_wildcard(int32 a,string b) */
    if (!corto_checkState(test_ol_wildcard_int32_string_o, CORTO_DEFINED)) {
        test_ol_wildcard_int32_string_o->returnType = corto_resolve(NULL, "/corto/lang/void");
        test_ol_wildcard_int32_string_o->returnsReference = FALSE;
        
        /* Bind /test/ol_wildcard(int32 a,string b) with C-function */
        corto_function(test_ol_wildcard_int32_string_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_ol_wildcard_int32_string(void *args, void *result);
        corto_function(test_ol_wildcard_int32_string_o)->impl = (corto_word)__test_ol_wildcard_int32_string;
        if (corto_define(test_ol_wildcard_int32_string_o)) {
            corto_error("test_load: failed to define '/test/ol_wildcard(int32 a,string b)' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Overload */
    test_Overload_o = corto_declareChild(test_o, "Overload", test_Suite_o);
    if (!test_Overload_o) {
        corto_error("test_load: failed to declare '/test/Overload' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Overload */
    if (!corto_checkState(test_Overload_o, CORTO_DEFINED)) {
        corto_type(test_Overload_o)->parentType = NULL;
        corto_type(test_Overload_o)->parentState = 0x6;
        corto_type(test_Overload_o)->defaultType = NULL;
        corto_type(test_Overload_o)->defaultProcedureType = NULL;
        corto_interface(test_Overload_o)->base = corto_resolve(NULL, "/corto/test/SuiteData");
        corto_struct(test_Overload_o)->baseAccess = 0x0;
        corto_class(test_Overload_o)->implements.length = 0;
        corto_class(test_Overload_o)->implements.buffer = NULL;
        if (corto_define(test_Overload_o)) {
            corto_error("test_load: failed to define '/test/Overload' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (corto_type(test_Overload_o)->size != sizeof(struct test_Overload_s)) {
        corto_error("test_load: calculated size '%d' of type '/test/Overload' doesn't match C-type size '%d'", corto_type(test_Overload_o)->size, sizeof(struct test_Overload_s));
    }

    /* Declare /test/Overload/tc_ambiguous() */
    test_Overload_tc_ambiguous_o = corto_declareChild(test_Overload_o, "tc_ambiguous()", test_Case_o);
    if (!test_Overload_tc_ambiguous_o) {
        corto_error("test_load: failed to declare '/test/Overload/tc_ambiguous()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Overload/tc_ambiguous() */
    if (!corto_checkState(test_Overload_tc_ambiguous_o, CORTO_DEFINED)) {
        corto_function(test_Overload_tc_ambiguous_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Overload_tc_ambiguous_o)->returnsReference = FALSE;
        corto_method(test_Overload_tc_ambiguous_o)->_virtual = FALSE;
        
        /* Bind /test/Overload/tc_ambiguous() with C-function */
        corto_function(test_Overload_tc_ambiguous_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Overload_tc_ambiguous(void *args, void *result);
        corto_function(test_Overload_tc_ambiguous_o)->impl = (corto_word)__test_Overload_tc_ambiguous;
        if (corto_define(test_Overload_tc_ambiguous_o)) {
            corto_error("test_load: failed to define '/test/Overload/tc_ambiguous()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Overload/tc_ambiguousNull() */
    test_Overload_tc_ambiguousNull_o = corto_declareChild(test_Overload_o, "tc_ambiguousNull()", test_Case_o);
    if (!test_Overload_tc_ambiguousNull_o) {
        corto_error("test_load: failed to declare '/test/Overload/tc_ambiguousNull()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Overload/tc_ambiguousNull() */
    if (!corto_checkState(test_Overload_tc_ambiguousNull_o, CORTO_DEFINED)) {
        corto_function(test_Overload_tc_ambiguousNull_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Overload_tc_ambiguousNull_o)->returnsReference = FALSE;
        corto_method(test_Overload_tc_ambiguousNull_o)->_virtual = FALSE;
        
        /* Bind /test/Overload/tc_ambiguousNull() with C-function */
        corto_function(test_Overload_tc_ambiguousNull_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Overload_tc_ambiguousNull(void *args, void *result);
        corto_function(test_Overload_tc_ambiguousNull_o)->impl = (corto_word)__test_Overload_tc_ambiguousNull;
        if (corto_define(test_Overload_tc_ambiguousNull_o)) {
            corto_error("test_load: failed to define '/test/Overload/tc_ambiguousNull()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Overload/tc_ambiguousWildcard() */
    test_Overload_tc_ambiguousWildcard_o = corto_declareChild(test_Overload_o, "tc_ambiguousWildcard()", test_Case_o);
    if (!test_Overload_tc_ambiguousWildcard_o) {
        corto_error("test_load: failed to declare '/test/Overload/tc_ambiguousWildcard()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Overload/tc_ambiguousWildcard() */
    if (!corto_checkState(test_Overload_tc_ambiguousWildcard_o, CORTO_DEFINED)) {
        corto_function(test_Overload_tc_ambiguousWildcard_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Overload_tc_ambiguousWildcard_o)->returnsReference = FALSE;
        corto_method(test_Overload_tc_ambiguousWildcard_o)->_virtual = FALSE;
        
        /* Bind /test/Overload/tc_ambiguousWildcard() with C-function */
        corto_function(test_Overload_tc_ambiguousWildcard_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Overload_tc_ambiguousWildcard(void *args, void *result);
        corto_function(test_Overload_tc_ambiguousWildcard_o)->impl = (corto_word)__test_Overload_tc_ambiguousWildcard;
        if (corto_define(test_Overload_tc_ambiguousWildcard_o)) {
            corto_error("test_load: failed to define '/test/Overload/tc_ambiguousWildcard()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Overload/tc_anyChar() */
    test_Overload_tc_anyChar_o = corto_declareChild(test_Overload_o, "tc_anyChar()", test_Case_o);
    if (!test_Overload_tc_anyChar_o) {
        corto_error("test_load: failed to declare '/test/Overload/tc_anyChar()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Overload/tc_anyChar() */
    if (!corto_checkState(test_Overload_tc_anyChar_o, CORTO_DEFINED)) {
        corto_function(test_Overload_tc_anyChar_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Overload_tc_anyChar_o)->returnsReference = FALSE;
        corto_method(test_Overload_tc_anyChar_o)->_virtual = FALSE;
        
        /* Bind /test/Overload/tc_anyChar() with C-function */
        corto_function(test_Overload_tc_anyChar_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Overload_tc_anyChar(void *args, void *result);
        corto_function(test_Overload_tc_anyChar_o)->impl = (corto_word)__test_Overload_tc_anyChar;
        if (corto_define(test_Overload_tc_anyChar_o)) {
            corto_error("test_load: failed to define '/test/Overload/tc_anyChar()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Overload/tc_anyColor() */
    test_Overload_tc_anyColor_o = corto_declareChild(test_Overload_o, "tc_anyColor()", test_Case_o);
    if (!test_Overload_tc_anyColor_o) {
        corto_error("test_load: failed to declare '/test/Overload/tc_anyColor()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Overload/tc_anyColor() */
    if (!corto_checkState(test_Overload_tc_anyColor_o, CORTO_DEFINED)) {
        corto_function(test_Overload_tc_anyColor_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Overload_tc_anyColor_o)->returnsReference = FALSE;
        corto_method(test_Overload_tc_anyColor_o)->_virtual = FALSE;
        
        /* Bind /test/Overload/tc_anyColor() with C-function */
        corto_function(test_Overload_tc_anyColor_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Overload_tc_anyColor(void *args, void *result);
        corto_function(test_Overload_tc_anyColor_o)->impl = (corto_word)__test_Overload_tc_anyColor;
        if (corto_define(test_Overload_tc_anyColor_o)) {
            corto_error("test_load: failed to define '/test/Overload/tc_anyColor()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Overload/tc_anyFloat32() */
    test_Overload_tc_anyFloat32_o = corto_declareChild(test_Overload_o, "tc_anyFloat32()", test_Case_o);
    if (!test_Overload_tc_anyFloat32_o) {
        corto_error("test_load: failed to declare '/test/Overload/tc_anyFloat32()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Overload/tc_anyFloat32() */
    if (!corto_checkState(test_Overload_tc_anyFloat32_o, CORTO_DEFINED)) {
        corto_function(test_Overload_tc_anyFloat32_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Overload_tc_anyFloat32_o)->returnsReference = FALSE;
        corto_method(test_Overload_tc_anyFloat32_o)->_virtual = FALSE;
        
        /* Bind /test/Overload/tc_anyFloat32() with C-function */
        corto_function(test_Overload_tc_anyFloat32_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Overload_tc_anyFloat32(void *args, void *result);
        corto_function(test_Overload_tc_anyFloat32_o)->impl = (corto_word)__test_Overload_tc_anyFloat32;
        if (corto_define(test_Overload_tc_anyFloat32_o)) {
            corto_error("test_load: failed to define '/test/Overload/tc_anyFloat32()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Overload/tc_anyFloat64() */
    test_Overload_tc_anyFloat64_o = corto_declareChild(test_Overload_o, "tc_anyFloat64()", test_Case_o);
    if (!test_Overload_tc_anyFloat64_o) {
        corto_error("test_load: failed to declare '/test/Overload/tc_anyFloat64()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Overload/tc_anyFloat64() */
    if (!corto_checkState(test_Overload_tc_anyFloat64_o, CORTO_DEFINED)) {
        corto_function(test_Overload_tc_anyFloat64_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Overload_tc_anyFloat64_o)->returnsReference = FALSE;
        corto_method(test_Overload_tc_anyFloat64_o)->_virtual = FALSE;
        
        /* Bind /test/Overload/tc_anyFloat64() with C-function */
        corto_function(test_Overload_tc_anyFloat64_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Overload_tc_anyFloat64(void *args, void *result);
        corto_function(test_Overload_tc_anyFloat64_o)->impl = (corto_word)__test_Overload_tc_anyFloat64;
        if (corto_define(test_Overload_tc_anyFloat64_o)) {
            corto_error("test_load: failed to define '/test/Overload/tc_anyFloat64()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Overload/tc_anyInt16() */
    test_Overload_tc_anyInt16_o = corto_declareChild(test_Overload_o, "tc_anyInt16()", test_Case_o);
    if (!test_Overload_tc_anyInt16_o) {
        corto_error("test_load: failed to declare '/test/Overload/tc_anyInt16()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Overload/tc_anyInt16() */
    if (!corto_checkState(test_Overload_tc_anyInt16_o, CORTO_DEFINED)) {
        corto_function(test_Overload_tc_anyInt16_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Overload_tc_anyInt16_o)->returnsReference = FALSE;
        corto_method(test_Overload_tc_anyInt16_o)->_virtual = FALSE;
        
        /* Bind /test/Overload/tc_anyInt16() with C-function */
        corto_function(test_Overload_tc_anyInt16_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Overload_tc_anyInt16(void *args, void *result);
        corto_function(test_Overload_tc_anyInt16_o)->impl = (corto_word)__test_Overload_tc_anyInt16;
        if (corto_define(test_Overload_tc_anyInt16_o)) {
            corto_error("test_load: failed to define '/test/Overload/tc_anyInt16()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Overload/tc_anyInt32() */
    test_Overload_tc_anyInt32_o = corto_declareChild(test_Overload_o, "tc_anyInt32()", test_Case_o);
    if (!test_Overload_tc_anyInt32_o) {
        corto_error("test_load: failed to declare '/test/Overload/tc_anyInt32()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Overload/tc_anyInt32() */
    if (!corto_checkState(test_Overload_tc_anyInt32_o, CORTO_DEFINED)) {
        corto_function(test_Overload_tc_anyInt32_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Overload_tc_anyInt32_o)->returnsReference = FALSE;
        corto_method(test_Overload_tc_anyInt32_o)->_virtual = FALSE;
        
        /* Bind /test/Overload/tc_anyInt32() with C-function */
        corto_function(test_Overload_tc_anyInt32_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Overload_tc_anyInt32(void *args, void *result);
        corto_function(test_Overload_tc_anyInt32_o)->impl = (corto_word)__test_Overload_tc_anyInt32;
        if (corto_define(test_Overload_tc_anyInt32_o)) {
            corto_error("test_load: failed to define '/test/Overload/tc_anyInt32()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Overload/tc_anyInt64() */
    test_Overload_tc_anyInt64_o = corto_declareChild(test_Overload_o, "tc_anyInt64()", test_Case_o);
    if (!test_Overload_tc_anyInt64_o) {
        corto_error("test_load: failed to declare '/test/Overload/tc_anyInt64()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Overload/tc_anyInt64() */
    if (!corto_checkState(test_Overload_tc_anyInt64_o, CORTO_DEFINED)) {
        corto_function(test_Overload_tc_anyInt64_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Overload_tc_anyInt64_o)->returnsReference = FALSE;
        corto_method(test_Overload_tc_anyInt64_o)->_virtual = FALSE;
        
        /* Bind /test/Overload/tc_anyInt64() with C-function */
        corto_function(test_Overload_tc_anyInt64_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Overload_tc_anyInt64(void *args, void *result);
        corto_function(test_Overload_tc_anyInt64_o)->impl = (corto_word)__test_Overload_tc_anyInt64;
        if (corto_define(test_Overload_tc_anyInt64_o)) {
            corto_error("test_load: failed to define '/test/Overload/tc_anyInt64()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Overload/tc_anyInt8() */
    test_Overload_tc_anyInt8_o = corto_declareChild(test_Overload_o, "tc_anyInt8()", test_Case_o);
    if (!test_Overload_tc_anyInt8_o) {
        corto_error("test_load: failed to declare '/test/Overload/tc_anyInt8()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Overload/tc_anyInt8() */
    if (!corto_checkState(test_Overload_tc_anyInt8_o, CORTO_DEFINED)) {
        corto_function(test_Overload_tc_anyInt8_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Overload_tc_anyInt8_o)->returnsReference = FALSE;
        corto_method(test_Overload_tc_anyInt8_o)->_virtual = FALSE;
        
        /* Bind /test/Overload/tc_anyInt8() with C-function */
        corto_function(test_Overload_tc_anyInt8_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Overload_tc_anyInt8(void *args, void *result);
        corto_function(test_Overload_tc_anyInt8_o)->impl = (corto_word)__test_Overload_tc_anyInt8;
        if (corto_define(test_Overload_tc_anyInt8_o)) {
            corto_error("test_load: failed to define '/test/Overload/tc_anyInt8()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Overload/tc_anyOctet() */
    test_Overload_tc_anyOctet_o = corto_declareChild(test_Overload_o, "tc_anyOctet()", test_Case_o);
    if (!test_Overload_tc_anyOctet_o) {
        corto_error("test_load: failed to declare '/test/Overload/tc_anyOctet()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Overload/tc_anyOctet() */
    if (!corto_checkState(test_Overload_tc_anyOctet_o, CORTO_DEFINED)) {
        corto_function(test_Overload_tc_anyOctet_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Overload_tc_anyOctet_o)->returnsReference = FALSE;
        corto_method(test_Overload_tc_anyOctet_o)->_virtual = FALSE;
        
        /* Bind /test/Overload/tc_anyOctet() with C-function */
        corto_function(test_Overload_tc_anyOctet_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Overload_tc_anyOctet(void *args, void *result);
        corto_function(test_Overload_tc_anyOctet_o)->impl = (corto_word)__test_Overload_tc_anyOctet;
        if (corto_define(test_Overload_tc_anyOctet_o)) {
            corto_error("test_load: failed to define '/test/Overload/tc_anyOctet()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Overload/tc_anyString() */
    test_Overload_tc_anyString_o = corto_declareChild(test_Overload_o, "tc_anyString()", test_Case_o);
    if (!test_Overload_tc_anyString_o) {
        corto_error("test_load: failed to declare '/test/Overload/tc_anyString()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Overload/tc_anyString() */
    if (!corto_checkState(test_Overload_tc_anyString_o, CORTO_DEFINED)) {
        corto_function(test_Overload_tc_anyString_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Overload_tc_anyString_o)->returnsReference = FALSE;
        corto_method(test_Overload_tc_anyString_o)->_virtual = FALSE;
        
        /* Bind /test/Overload/tc_anyString() with C-function */
        corto_function(test_Overload_tc_anyString_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Overload_tc_anyString(void *args, void *result);
        corto_function(test_Overload_tc_anyString_o)->impl = (corto_word)__test_Overload_tc_anyString;
        if (corto_define(test_Overload_tc_anyString_o)) {
            corto_error("test_load: failed to define '/test/Overload/tc_anyString()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Overload/tc_anyUint16() */
    test_Overload_tc_anyUint16_o = corto_declareChild(test_Overload_o, "tc_anyUint16()", test_Case_o);
    if (!test_Overload_tc_anyUint16_o) {
        corto_error("test_load: failed to declare '/test/Overload/tc_anyUint16()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Overload/tc_anyUint16() */
    if (!corto_checkState(test_Overload_tc_anyUint16_o, CORTO_DEFINED)) {
        corto_function(test_Overload_tc_anyUint16_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Overload_tc_anyUint16_o)->returnsReference = FALSE;
        corto_method(test_Overload_tc_anyUint16_o)->_virtual = FALSE;
        
        /* Bind /test/Overload/tc_anyUint16() with C-function */
        corto_function(test_Overload_tc_anyUint16_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Overload_tc_anyUint16(void *args, void *result);
        corto_function(test_Overload_tc_anyUint16_o)->impl = (corto_word)__test_Overload_tc_anyUint16;
        if (corto_define(test_Overload_tc_anyUint16_o)) {
            corto_error("test_load: failed to define '/test/Overload/tc_anyUint16()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Overload/tc_anyUint32() */
    test_Overload_tc_anyUint32_o = corto_declareChild(test_Overload_o, "tc_anyUint32()", test_Case_o);
    if (!test_Overload_tc_anyUint32_o) {
        corto_error("test_load: failed to declare '/test/Overload/tc_anyUint32()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Overload/tc_anyUint32() */
    if (!corto_checkState(test_Overload_tc_anyUint32_o, CORTO_DEFINED)) {
        corto_function(test_Overload_tc_anyUint32_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Overload_tc_anyUint32_o)->returnsReference = FALSE;
        corto_method(test_Overload_tc_anyUint32_o)->_virtual = FALSE;
        
        /* Bind /test/Overload/tc_anyUint32() with C-function */
        corto_function(test_Overload_tc_anyUint32_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Overload_tc_anyUint32(void *args, void *result);
        corto_function(test_Overload_tc_anyUint32_o)->impl = (corto_word)__test_Overload_tc_anyUint32;
        if (corto_define(test_Overload_tc_anyUint32_o)) {
            corto_error("test_load: failed to define '/test/Overload/tc_anyUint32()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Overload/tc_anyUint64() */
    test_Overload_tc_anyUint64_o = corto_declareChild(test_Overload_o, "tc_anyUint64()", test_Case_o);
    if (!test_Overload_tc_anyUint64_o) {
        corto_error("test_load: failed to declare '/test/Overload/tc_anyUint64()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Overload/tc_anyUint64() */
    if (!corto_checkState(test_Overload_tc_anyUint64_o, CORTO_DEFINED)) {
        corto_function(test_Overload_tc_anyUint64_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Overload_tc_anyUint64_o)->returnsReference = FALSE;
        corto_method(test_Overload_tc_anyUint64_o)->_virtual = FALSE;
        
        /* Bind /test/Overload/tc_anyUint64() with C-function */
        corto_function(test_Overload_tc_anyUint64_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Overload_tc_anyUint64(void *args, void *result);
        corto_function(test_Overload_tc_anyUint64_o)->impl = (corto_word)__test_Overload_tc_anyUint64;
        if (corto_define(test_Overload_tc_anyUint64_o)) {
            corto_error("test_load: failed to define '/test/Overload/tc_anyUint64()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Overload/tc_anyUint8() */
    test_Overload_tc_anyUint8_o = corto_declareChild(test_Overload_o, "tc_anyUint8()", test_Case_o);
    if (!test_Overload_tc_anyUint8_o) {
        corto_error("test_load: failed to declare '/test/Overload/tc_anyUint8()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Overload/tc_anyUint8() */
    if (!corto_checkState(test_Overload_tc_anyUint8_o, CORTO_DEFINED)) {
        corto_function(test_Overload_tc_anyUint8_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Overload_tc_anyUint8_o)->returnsReference = FALSE;
        corto_method(test_Overload_tc_anyUint8_o)->_virtual = FALSE;
        
        /* Bind /test/Overload/tc_anyUint8() with C-function */
        corto_function(test_Overload_tc_anyUint8_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Overload_tc_anyUint8(void *args, void *result);
        corto_function(test_Overload_tc_anyUint8_o)->impl = (corto_word)__test_Overload_tc_anyUint8;
        if (corto_define(test_Overload_tc_anyUint8_o)) {
            corto_error("test_load: failed to define '/test/Overload/tc_anyUint8()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Overload/tc_anyWord() */
    test_Overload_tc_anyWord_o = corto_declareChild(test_Overload_o, "tc_anyWord()", test_Case_o);
    if (!test_Overload_tc_anyWord_o) {
        corto_error("test_load: failed to declare '/test/Overload/tc_anyWord()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Overload/tc_anyWord() */
    if (!corto_checkState(test_Overload_tc_anyWord_o, CORTO_DEFINED)) {
        corto_function(test_Overload_tc_anyWord_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Overload_tc_anyWord_o)->returnsReference = FALSE;
        corto_method(test_Overload_tc_anyWord_o)->_virtual = FALSE;
        
        /* Bind /test/Overload/tc_anyWord() with C-function */
        corto_function(test_Overload_tc_anyWord_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Overload_tc_anyWord(void *args, void *result);
        corto_function(test_Overload_tc_anyWord_o)->impl = (corto_word)__test_Overload_tc_anyWord;
        if (corto_define(test_Overload_tc_anyWord_o)) {
            corto_error("test_load: failed to define '/test/Overload/tc_anyWord()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Overload/tc_inheritanceBase() */
    test_Overload_tc_inheritanceBase_o = corto_declareChild(test_Overload_o, "tc_inheritanceBase()", test_Case_o);
    if (!test_Overload_tc_inheritanceBase_o) {
        corto_error("test_load: failed to declare '/test/Overload/tc_inheritanceBase()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Overload/tc_inheritanceBase() */
    if (!corto_checkState(test_Overload_tc_inheritanceBase_o, CORTO_DEFINED)) {
        corto_function(test_Overload_tc_inheritanceBase_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Overload_tc_inheritanceBase_o)->returnsReference = FALSE;
        corto_method(test_Overload_tc_inheritanceBase_o)->_virtual = FALSE;
        
        /* Bind /test/Overload/tc_inheritanceBase() with C-function */
        corto_function(test_Overload_tc_inheritanceBase_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Overload_tc_inheritanceBase(void *args, void *result);
        corto_function(test_Overload_tc_inheritanceBase_o)->impl = (corto_word)__test_Overload_tc_inheritanceBase;
        if (corto_define(test_Overload_tc_inheritanceBase_o)) {
            corto_error("test_load: failed to define '/test/Overload/tc_inheritanceBase()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Overload/tc_inheritanceMatchSub() */
    test_Overload_tc_inheritanceMatchSub_o = corto_declareChild(test_Overload_o, "tc_inheritanceMatchSub()", test_Case_o);
    if (!test_Overload_tc_inheritanceMatchSub_o) {
        corto_error("test_load: failed to declare '/test/Overload/tc_inheritanceMatchSub()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Overload/tc_inheritanceMatchSub() */
    if (!corto_checkState(test_Overload_tc_inheritanceMatchSub_o, CORTO_DEFINED)) {
        corto_function(test_Overload_tc_inheritanceMatchSub_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Overload_tc_inheritanceMatchSub_o)->returnsReference = FALSE;
        corto_method(test_Overload_tc_inheritanceMatchSub_o)->_virtual = FALSE;
        
        /* Bind /test/Overload/tc_inheritanceMatchSub() with C-function */
        corto_function(test_Overload_tc_inheritanceMatchSub_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Overload_tc_inheritanceMatchSub(void *args, void *result);
        corto_function(test_Overload_tc_inheritanceMatchSub_o)->impl = (corto_word)__test_Overload_tc_inheritanceMatchSub;
        if (corto_define(test_Overload_tc_inheritanceMatchSub_o)) {
            corto_error("test_load: failed to define '/test/Overload/tc_inheritanceMatchSub()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Overload/tc_inheritanceSub() */
    test_Overload_tc_inheritanceSub_o = corto_declareChild(test_Overload_o, "tc_inheritanceSub()", test_Case_o);
    if (!test_Overload_tc_inheritanceSub_o) {
        corto_error("test_load: failed to declare '/test/Overload/tc_inheritanceSub()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Overload/tc_inheritanceSub() */
    if (!corto_checkState(test_Overload_tc_inheritanceSub_o, CORTO_DEFINED)) {
        corto_function(test_Overload_tc_inheritanceSub_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Overload_tc_inheritanceSub_o)->returnsReference = FALSE;
        corto_method(test_Overload_tc_inheritanceSub_o)->_virtual = FALSE;
        
        /* Bind /test/Overload/tc_inheritanceSub() with C-function */
        corto_function(test_Overload_tc_inheritanceSub_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Overload_tc_inheritanceSub(void *args, void *result);
        corto_function(test_Overload_tc_inheritanceSub_o)->impl = (corto_word)__test_Overload_tc_inheritanceSub;
        if (corto_define(test_Overload_tc_inheritanceSub_o)) {
            corto_error("test_load: failed to define '/test/Overload/tc_inheritanceSub()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Overload/tc_inheritSibling() */
    test_Overload_tc_inheritSibling_o = corto_declareChild(test_Overload_o, "tc_inheritSibling()", test_Case_o);
    if (!test_Overload_tc_inheritSibling_o) {
        corto_error("test_load: failed to declare '/test/Overload/tc_inheritSibling()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Overload/tc_inheritSibling() */
    if (!corto_checkState(test_Overload_tc_inheritSibling_o, CORTO_DEFINED)) {
        corto_function(test_Overload_tc_inheritSibling_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Overload_tc_inheritSibling_o)->returnsReference = FALSE;
        corto_method(test_Overload_tc_inheritSibling_o)->_virtual = FALSE;
        
        /* Bind /test/Overload/tc_inheritSibling() with C-function */
        corto_function(test_Overload_tc_inheritSibling_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Overload_tc_inheritSibling(void *args, void *result);
        corto_function(test_Overload_tc_inheritSibling_o)->impl = (corto_word)__test_Overload_tc_inheritSibling;
        if (corto_define(test_Overload_tc_inheritSibling_o)) {
            corto_error("test_load: failed to define '/test/Overload/tc_inheritSibling()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Overload/tc_nullBool() */
    test_Overload_tc_nullBool_o = corto_declareChild(test_Overload_o, "tc_nullBool()", test_Case_o);
    if (!test_Overload_tc_nullBool_o) {
        corto_error("test_load: failed to declare '/test/Overload/tc_nullBool()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Overload/tc_nullBool() */
    if (!corto_checkState(test_Overload_tc_nullBool_o, CORTO_DEFINED)) {
        corto_function(test_Overload_tc_nullBool_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Overload_tc_nullBool_o)->returnsReference = FALSE;
        corto_method(test_Overload_tc_nullBool_o)->_virtual = FALSE;
        
        /* Bind /test/Overload/tc_nullBool() with C-function */
        corto_function(test_Overload_tc_nullBool_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Overload_tc_nullBool(void *args, void *result);
        corto_function(test_Overload_tc_nullBool_o)->impl = (corto_word)__test_Overload_tc_nullBool;
        if (corto_define(test_Overload_tc_nullBool_o)) {
            corto_error("test_load: failed to define '/test/Overload/tc_nullBool()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Overload/tc_nullObject() */
    test_Overload_tc_nullObject_o = corto_declareChild(test_Overload_o, "tc_nullObject()", test_Case_o);
    if (!test_Overload_tc_nullObject_o) {
        corto_error("test_load: failed to declare '/test/Overload/tc_nullObject()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Overload/tc_nullObject() */
    if (!corto_checkState(test_Overload_tc_nullObject_o, CORTO_DEFINED)) {
        corto_function(test_Overload_tc_nullObject_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Overload_tc_nullObject_o)->returnsReference = FALSE;
        corto_method(test_Overload_tc_nullObject_o)->_virtual = FALSE;
        
        /* Bind /test/Overload/tc_nullObject() with C-function */
        corto_function(test_Overload_tc_nullObject_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Overload_tc_nullObject(void *args, void *result);
        corto_function(test_Overload_tc_nullObject_o)->impl = (corto_word)__test_Overload_tc_nullObject;
        if (corto_define(test_Overload_tc_nullObject_o)) {
            corto_error("test_load: failed to define '/test/Overload/tc_nullObject()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Overload/tc_nullString() */
    test_Overload_tc_nullString_o = corto_declareChild(test_Overload_o, "tc_nullString()", test_Case_o);
    if (!test_Overload_tc_nullString_o) {
        corto_error("test_load: failed to declare '/test/Overload/tc_nullString()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Overload/tc_nullString() */
    if (!corto_checkState(test_Overload_tc_nullString_o, CORTO_DEFINED)) {
        corto_function(test_Overload_tc_nullString_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Overload_tc_nullString_o)->returnsReference = FALSE;
        corto_method(test_Overload_tc_nullString_o)->_virtual = FALSE;
        
        /* Bind /test/Overload/tc_nullString() with C-function */
        corto_function(test_Overload_tc_nullString_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Overload_tc_nullString(void *args, void *result);
        corto_function(test_Overload_tc_nullString_o)->impl = (corto_word)__test_Overload_tc_nullString;
        if (corto_define(test_Overload_tc_nullString_o)) {
            corto_error("test_load: failed to define '/test/Overload/tc_nullString()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Overload/tc_numChar() */
    test_Overload_tc_numChar_o = corto_declareChild(test_Overload_o, "tc_numChar()", test_Case_o);
    if (!test_Overload_tc_numChar_o) {
        corto_error("test_load: failed to declare '/test/Overload/tc_numChar()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Overload/tc_numChar() */
    if (!corto_checkState(test_Overload_tc_numChar_o, CORTO_DEFINED)) {
        corto_function(test_Overload_tc_numChar_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Overload_tc_numChar_o)->returnsReference = FALSE;
        corto_method(test_Overload_tc_numChar_o)->_virtual = FALSE;
        
        /* Bind /test/Overload/tc_numChar() with C-function */
        corto_function(test_Overload_tc_numChar_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Overload_tc_numChar(void *args, void *result);
        corto_function(test_Overload_tc_numChar_o)->impl = (corto_word)__test_Overload_tc_numChar;
        if (corto_define(test_Overload_tc_numChar_o)) {
            corto_error("test_load: failed to define '/test/Overload/tc_numChar()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Overload/tc_numColor() */
    test_Overload_tc_numColor_o = corto_declareChild(test_Overload_o, "tc_numColor()", test_Case_o);
    if (!test_Overload_tc_numColor_o) {
        corto_error("test_load: failed to declare '/test/Overload/tc_numColor()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Overload/tc_numColor() */
    if (!corto_checkState(test_Overload_tc_numColor_o, CORTO_DEFINED)) {
        corto_function(test_Overload_tc_numColor_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Overload_tc_numColor_o)->returnsReference = FALSE;
        corto_method(test_Overload_tc_numColor_o)->_virtual = FALSE;
        
        /* Bind /test/Overload/tc_numColor() with C-function */
        corto_function(test_Overload_tc_numColor_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Overload_tc_numColor(void *args, void *result);
        corto_function(test_Overload_tc_numColor_o)->impl = (corto_word)__test_Overload_tc_numColor;
        if (corto_define(test_Overload_tc_numColor_o)) {
            corto_error("test_load: failed to define '/test/Overload/tc_numColor()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Overload/tc_numFloat32() */
    test_Overload_tc_numFloat32_o = corto_declareChild(test_Overload_o, "tc_numFloat32()", test_Case_o);
    if (!test_Overload_tc_numFloat32_o) {
        corto_error("test_load: failed to declare '/test/Overload/tc_numFloat32()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Overload/tc_numFloat32() */
    if (!corto_checkState(test_Overload_tc_numFloat32_o, CORTO_DEFINED)) {
        corto_function(test_Overload_tc_numFloat32_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Overload_tc_numFloat32_o)->returnsReference = FALSE;
        corto_method(test_Overload_tc_numFloat32_o)->_virtual = FALSE;
        
        /* Bind /test/Overload/tc_numFloat32() with C-function */
        corto_function(test_Overload_tc_numFloat32_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Overload_tc_numFloat32(void *args, void *result);
        corto_function(test_Overload_tc_numFloat32_o)->impl = (corto_word)__test_Overload_tc_numFloat32;
        if (corto_define(test_Overload_tc_numFloat32_o)) {
            corto_error("test_load: failed to define '/test/Overload/tc_numFloat32()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Overload/tc_numFloat64() */
    test_Overload_tc_numFloat64_o = corto_declareChild(test_Overload_o, "tc_numFloat64()", test_Case_o);
    if (!test_Overload_tc_numFloat64_o) {
        corto_error("test_load: failed to declare '/test/Overload/tc_numFloat64()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Overload/tc_numFloat64() */
    if (!corto_checkState(test_Overload_tc_numFloat64_o, CORTO_DEFINED)) {
        corto_function(test_Overload_tc_numFloat64_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Overload_tc_numFloat64_o)->returnsReference = FALSE;
        corto_method(test_Overload_tc_numFloat64_o)->_virtual = FALSE;
        
        /* Bind /test/Overload/tc_numFloat64() with C-function */
        corto_function(test_Overload_tc_numFloat64_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Overload_tc_numFloat64(void *args, void *result);
        corto_function(test_Overload_tc_numFloat64_o)->impl = (corto_word)__test_Overload_tc_numFloat64;
        if (corto_define(test_Overload_tc_numFloat64_o)) {
            corto_error("test_load: failed to define '/test/Overload/tc_numFloat64()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Overload/tc_numInt16() */
    test_Overload_tc_numInt16_o = corto_declareChild(test_Overload_o, "tc_numInt16()", test_Case_o);
    if (!test_Overload_tc_numInt16_o) {
        corto_error("test_load: failed to declare '/test/Overload/tc_numInt16()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Overload/tc_numInt16() */
    if (!corto_checkState(test_Overload_tc_numInt16_o, CORTO_DEFINED)) {
        corto_function(test_Overload_tc_numInt16_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Overload_tc_numInt16_o)->returnsReference = FALSE;
        corto_method(test_Overload_tc_numInt16_o)->_virtual = FALSE;
        
        /* Bind /test/Overload/tc_numInt16() with C-function */
        corto_function(test_Overload_tc_numInt16_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Overload_tc_numInt16(void *args, void *result);
        corto_function(test_Overload_tc_numInt16_o)->impl = (corto_word)__test_Overload_tc_numInt16;
        if (corto_define(test_Overload_tc_numInt16_o)) {
            corto_error("test_load: failed to define '/test/Overload/tc_numInt16()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Overload/tc_numInt32() */
    test_Overload_tc_numInt32_o = corto_declareChild(test_Overload_o, "tc_numInt32()", test_Case_o);
    if (!test_Overload_tc_numInt32_o) {
        corto_error("test_load: failed to declare '/test/Overload/tc_numInt32()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Overload/tc_numInt32() */
    if (!corto_checkState(test_Overload_tc_numInt32_o, CORTO_DEFINED)) {
        corto_function(test_Overload_tc_numInt32_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Overload_tc_numInt32_o)->returnsReference = FALSE;
        corto_method(test_Overload_tc_numInt32_o)->_virtual = FALSE;
        
        /* Bind /test/Overload/tc_numInt32() with C-function */
        corto_function(test_Overload_tc_numInt32_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Overload_tc_numInt32(void *args, void *result);
        corto_function(test_Overload_tc_numInt32_o)->impl = (corto_word)__test_Overload_tc_numInt32;
        if (corto_define(test_Overload_tc_numInt32_o)) {
            corto_error("test_load: failed to define '/test/Overload/tc_numInt32()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Overload/tc_numInt64() */
    test_Overload_tc_numInt64_o = corto_declareChild(test_Overload_o, "tc_numInt64()", test_Case_o);
    if (!test_Overload_tc_numInt64_o) {
        corto_error("test_load: failed to declare '/test/Overload/tc_numInt64()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Overload/tc_numInt64() */
    if (!corto_checkState(test_Overload_tc_numInt64_o, CORTO_DEFINED)) {
        corto_function(test_Overload_tc_numInt64_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Overload_tc_numInt64_o)->returnsReference = FALSE;
        corto_method(test_Overload_tc_numInt64_o)->_virtual = FALSE;
        
        /* Bind /test/Overload/tc_numInt64() with C-function */
        corto_function(test_Overload_tc_numInt64_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Overload_tc_numInt64(void *args, void *result);
        corto_function(test_Overload_tc_numInt64_o)->impl = (corto_word)__test_Overload_tc_numInt64;
        if (corto_define(test_Overload_tc_numInt64_o)) {
            corto_error("test_load: failed to define '/test/Overload/tc_numInt64()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Overload/tc_numInt8() */
    test_Overload_tc_numInt8_o = corto_declareChild(test_Overload_o, "tc_numInt8()", test_Case_o);
    if (!test_Overload_tc_numInt8_o) {
        corto_error("test_load: failed to declare '/test/Overload/tc_numInt8()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Overload/tc_numInt8() */
    if (!corto_checkState(test_Overload_tc_numInt8_o, CORTO_DEFINED)) {
        corto_function(test_Overload_tc_numInt8_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Overload_tc_numInt8_o)->returnsReference = FALSE;
        corto_method(test_Overload_tc_numInt8_o)->_virtual = FALSE;
        
        /* Bind /test/Overload/tc_numInt8() with C-function */
        corto_function(test_Overload_tc_numInt8_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Overload_tc_numInt8(void *args, void *result);
        corto_function(test_Overload_tc_numInt8_o)->impl = (corto_word)__test_Overload_tc_numInt8;
        if (corto_define(test_Overload_tc_numInt8_o)) {
            corto_error("test_load: failed to define '/test/Overload/tc_numInt8()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Overload/tc_numOctet() */
    test_Overload_tc_numOctet_o = corto_declareChild(test_Overload_o, "tc_numOctet()", test_Case_o);
    if (!test_Overload_tc_numOctet_o) {
        corto_error("test_load: failed to declare '/test/Overload/tc_numOctet()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Overload/tc_numOctet() */
    if (!corto_checkState(test_Overload_tc_numOctet_o, CORTO_DEFINED)) {
        corto_function(test_Overload_tc_numOctet_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Overload_tc_numOctet_o)->returnsReference = FALSE;
        corto_method(test_Overload_tc_numOctet_o)->_virtual = FALSE;
        
        /* Bind /test/Overload/tc_numOctet() with C-function */
        corto_function(test_Overload_tc_numOctet_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Overload_tc_numOctet(void *args, void *result);
        corto_function(test_Overload_tc_numOctet_o)->impl = (corto_word)__test_Overload_tc_numOctet;
        if (corto_define(test_Overload_tc_numOctet_o)) {
            corto_error("test_load: failed to define '/test/Overload/tc_numOctet()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Overload/tc_numString() */
    test_Overload_tc_numString_o = corto_declareChild(test_Overload_o, "tc_numString()", test_Case_o);
    if (!test_Overload_tc_numString_o) {
        corto_error("test_load: failed to declare '/test/Overload/tc_numString()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Overload/tc_numString() */
    if (!corto_checkState(test_Overload_tc_numString_o, CORTO_DEFINED)) {
        corto_function(test_Overload_tc_numString_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Overload_tc_numString_o)->returnsReference = FALSE;
        corto_method(test_Overload_tc_numString_o)->_virtual = FALSE;
        
        /* Bind /test/Overload/tc_numString() with C-function */
        corto_function(test_Overload_tc_numString_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Overload_tc_numString(void *args, void *result);
        corto_function(test_Overload_tc_numString_o)->impl = (corto_word)__test_Overload_tc_numString;
        if (corto_define(test_Overload_tc_numString_o)) {
            corto_error("test_load: failed to define '/test/Overload/tc_numString()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Overload/tc_numUint16() */
    test_Overload_tc_numUint16_o = corto_declareChild(test_Overload_o, "tc_numUint16()", test_Case_o);
    if (!test_Overload_tc_numUint16_o) {
        corto_error("test_load: failed to declare '/test/Overload/tc_numUint16()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Overload/tc_numUint16() */
    if (!corto_checkState(test_Overload_tc_numUint16_o, CORTO_DEFINED)) {
        corto_function(test_Overload_tc_numUint16_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Overload_tc_numUint16_o)->returnsReference = FALSE;
        corto_method(test_Overload_tc_numUint16_o)->_virtual = FALSE;
        
        /* Bind /test/Overload/tc_numUint16() with C-function */
        corto_function(test_Overload_tc_numUint16_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Overload_tc_numUint16(void *args, void *result);
        corto_function(test_Overload_tc_numUint16_o)->impl = (corto_word)__test_Overload_tc_numUint16;
        if (corto_define(test_Overload_tc_numUint16_o)) {
            corto_error("test_load: failed to define '/test/Overload/tc_numUint16()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Overload/tc_numUint32() */
    test_Overload_tc_numUint32_o = corto_declareChild(test_Overload_o, "tc_numUint32()", test_Case_o);
    if (!test_Overload_tc_numUint32_o) {
        corto_error("test_load: failed to declare '/test/Overload/tc_numUint32()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Overload/tc_numUint32() */
    if (!corto_checkState(test_Overload_tc_numUint32_o, CORTO_DEFINED)) {
        corto_function(test_Overload_tc_numUint32_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Overload_tc_numUint32_o)->returnsReference = FALSE;
        corto_method(test_Overload_tc_numUint32_o)->_virtual = FALSE;
        
        /* Bind /test/Overload/tc_numUint32() with C-function */
        corto_function(test_Overload_tc_numUint32_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Overload_tc_numUint32(void *args, void *result);
        corto_function(test_Overload_tc_numUint32_o)->impl = (corto_word)__test_Overload_tc_numUint32;
        if (corto_define(test_Overload_tc_numUint32_o)) {
            corto_error("test_load: failed to define '/test/Overload/tc_numUint32()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Overload/tc_numUint64() */
    test_Overload_tc_numUint64_o = corto_declareChild(test_Overload_o, "tc_numUint64()", test_Case_o);
    if (!test_Overload_tc_numUint64_o) {
        corto_error("test_load: failed to declare '/test/Overload/tc_numUint64()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Overload/tc_numUint64() */
    if (!corto_checkState(test_Overload_tc_numUint64_o, CORTO_DEFINED)) {
        corto_function(test_Overload_tc_numUint64_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Overload_tc_numUint64_o)->returnsReference = FALSE;
        corto_method(test_Overload_tc_numUint64_o)->_virtual = FALSE;
        
        /* Bind /test/Overload/tc_numUint64() with C-function */
        corto_function(test_Overload_tc_numUint64_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Overload_tc_numUint64(void *args, void *result);
        corto_function(test_Overload_tc_numUint64_o)->impl = (corto_word)__test_Overload_tc_numUint64;
        if (corto_define(test_Overload_tc_numUint64_o)) {
            corto_error("test_load: failed to define '/test/Overload/tc_numUint64()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Overload/tc_numUint8() */
    test_Overload_tc_numUint8_o = corto_declareChild(test_Overload_o, "tc_numUint8()", test_Case_o);
    if (!test_Overload_tc_numUint8_o) {
        corto_error("test_load: failed to declare '/test/Overload/tc_numUint8()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Overload/tc_numUint8() */
    if (!corto_checkState(test_Overload_tc_numUint8_o, CORTO_DEFINED)) {
        corto_function(test_Overload_tc_numUint8_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Overload_tc_numUint8_o)->returnsReference = FALSE;
        corto_method(test_Overload_tc_numUint8_o)->_virtual = FALSE;
        
        /* Bind /test/Overload/tc_numUint8() with C-function */
        corto_function(test_Overload_tc_numUint8_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Overload_tc_numUint8(void *args, void *result);
        corto_function(test_Overload_tc_numUint8_o)->impl = (corto_word)__test_Overload_tc_numUint8;
        if (corto_define(test_Overload_tc_numUint8_o)) {
            corto_error("test_load: failed to define '/test/Overload/tc_numUint8()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Overload/tc_numWord() */
    test_Overload_tc_numWord_o = corto_declareChild(test_Overload_o, "tc_numWord()", test_Case_o);
    if (!test_Overload_tc_numWord_o) {
        corto_error("test_load: failed to declare '/test/Overload/tc_numWord()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Overload/tc_numWord() */
    if (!corto_checkState(test_Overload_tc_numWord_o, CORTO_DEFINED)) {
        corto_function(test_Overload_tc_numWord_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Overload_tc_numWord_o)->returnsReference = FALSE;
        corto_method(test_Overload_tc_numWord_o)->_virtual = FALSE;
        
        /* Bind /test/Overload/tc_numWord() with C-function */
        corto_function(test_Overload_tc_numWord_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Overload_tc_numWord(void *args, void *result);
        corto_function(test_Overload_tc_numWord_o)->impl = (corto_word)__test_Overload_tc_numWord;
        if (corto_define(test_Overload_tc_numWord_o)) {
            corto_error("test_load: failed to define '/test/Overload/tc_numWord()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Overload/tc_wildcard() */
    test_Overload_tc_wildcard_o = corto_declareChild(test_Overload_o, "tc_wildcard()", test_Case_o);
    if (!test_Overload_tc_wildcard_o) {
        corto_error("test_load: failed to declare '/test/Overload/tc_wildcard()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Overload/tc_wildcard() */
    if (!corto_checkState(test_Overload_tc_wildcard_o, CORTO_DEFINED)) {
        corto_function(test_Overload_tc_wildcard_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Overload_tc_wildcard_o)->returnsReference = FALSE;
        corto_method(test_Overload_tc_wildcard_o)->_virtual = FALSE;
        
        /* Bind /test/Overload/tc_wildcard() with C-function */
        corto_function(test_Overload_tc_wildcard_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Overload_tc_wildcard(void *args, void *result);
        corto_function(test_Overload_tc_wildcard_o)->impl = (corto_word)__test_Overload_tc_wildcard;
        if (corto_define(test_Overload_tc_wildcard_o)) {
            corto_error("test_load: failed to define '/test/Overload/tc_wildcard()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Point */
    test_Point_o = corto_declareChild(test_o, "Point", corto_struct_o);
    if (!test_Point_o) {
        corto_error("test_load: failed to declare '/test/Point' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/CompositeCollection/points */
    if (!corto_checkState(test_CompositeCollection_points_o, CORTO_DEFINED)) {
        test_CompositeCollection_points_o->type = corto_resolve(NULL, "/corto/lang/list{/test/Point,0}");
        test_CompositeCollection_points_o->modifiers = 0x0;
        test_CompositeCollection_points_o->state = 0x6;
        test_CompositeCollection_points_o->weak = FALSE;
        test_CompositeCollection_points_o->id = 0;
        if (corto_define(test_CompositeCollection_points_o)) {
            corto_error("test_load: failed to define '/test/CompositeCollection/points' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Define /test/CompositeCollection */
    if (!corto_checkState(test_CompositeCollection_o, CORTO_DEFINED)) {
        corto_type(test_CompositeCollection_o)->parentType = NULL;
        corto_type(test_CompositeCollection_o)->parentState = 0x6;
        corto_type(test_CompositeCollection_o)->defaultType = NULL;
        corto_type(test_CompositeCollection_o)->defaultProcedureType = NULL;
        corto_interface(test_CompositeCollection_o)->base = NULL;
        test_CompositeCollection_o->baseAccess = 0x0;
        if (corto_define(test_CompositeCollection_o)) {
            corto_error("test_load: failed to define '/test/CompositeCollection' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (corto_type(test_CompositeCollection_o)->size != sizeof(test_CompositeCollection)) {
        corto_error("test_load: calculated size '%d' of type '/test/CompositeCollection' doesn't match C-type size '%d'", corto_type(test_CompositeCollection_o)->size, sizeof(test_CompositeCollection));
    }

    /* Declare /test/Point/x */
    test_Point_x_o = corto_declareChild(test_Point_o, "x", corto_member_o);
    if (!test_Point_x_o) {
        corto_error("test_load: failed to declare '/test/Point/x' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Point/x */
    if (!corto_checkState(test_Point_x_o, CORTO_DEFINED)) {
        test_Point_x_o->type = corto_resolve(NULL, "/corto/lang/int32");
        test_Point_x_o->modifiers = 0x0;
        test_Point_x_o->state = 0x6;
        test_Point_x_o->weak = FALSE;
        test_Point_x_o->id = 0;
        if (corto_define(test_Point_x_o)) {
            corto_error("test_load: failed to define '/test/Point/x' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Point/y */
    test_Point_y_o = corto_declareChild(test_Point_o, "y", corto_member_o);
    if (!test_Point_y_o) {
        corto_error("test_load: failed to declare '/test/Point/y' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Point/y */
    if (!corto_checkState(test_Point_y_o, CORTO_DEFINED)) {
        test_Point_y_o->type = corto_resolve(NULL, "/corto/lang/int32");
        test_Point_y_o->modifiers = 0x0;
        test_Point_y_o->state = 0x6;
        test_Point_y_o->weak = FALSE;
        test_Point_y_o->id = 1;
        if (corto_define(test_Point_y_o)) {
            corto_error("test_load: failed to define '/test/Point/y' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Define /test/Point */
    if (!corto_checkState(test_Point_o, CORTO_DEFINED)) {
        corto_type(test_Point_o)->parentType = NULL;
        corto_type(test_Point_o)->parentState = 0x6;
        corto_type(test_Point_o)->defaultType = NULL;
        corto_type(test_Point_o)->defaultProcedureType = NULL;
        corto_interface(test_Point_o)->base = NULL;
        test_Point_o->baseAccess = 0x0;
        if (corto_define(test_Point_o)) {
            corto_error("test_load: failed to define '/test/Point' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (corto_type(test_Point_o)->size != sizeof(test_Point)) {
        corto_error("test_load: calculated size '%d' of type '/test/Point' doesn't match C-type size '%d'", corto_type(test_Point_o)->size, sizeof(test_Point));
    }

    /* Define /test/Line/start */
    if (!corto_checkState(test_Line_start_o, CORTO_DEFINED)) {
        test_Line_start_o->type = corto_resolve(NULL, "/test/Point");
        test_Line_start_o->modifiers = 0x0;
        test_Line_start_o->state = 0x6;
        test_Line_start_o->weak = FALSE;
        test_Line_start_o->id = 0;
        if (corto_define(test_Line_start_o)) {
            corto_error("test_load: failed to define '/test/Line/start' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Define /test/Line/stop */
    if (!corto_checkState(test_Line_stop_o, CORTO_DEFINED)) {
        test_Line_stop_o->type = corto_resolve(NULL, "/test/Point");
        test_Line_stop_o->modifiers = 0x0;
        test_Line_stop_o->state = 0x6;
        test_Line_stop_o->weak = FALSE;
        test_Line_stop_o->id = 1;
        if (corto_define(test_Line_stop_o)) {
            corto_error("test_load: failed to define '/test/Line/stop' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Define /test/Line */
    if (!corto_checkState(test_Line_o, CORTO_DEFINED)) {
        corto_type(test_Line_o)->parentType = NULL;
        corto_type(test_Line_o)->parentState = 0x6;
        corto_type(test_Line_o)->defaultType = NULL;
        corto_type(test_Line_o)->defaultProcedureType = NULL;
        corto_interface(test_Line_o)->base = NULL;
        test_Line_o->baseAccess = 0x0;
        if (corto_define(test_Line_o)) {
            corto_error("test_load: failed to define '/test/Line' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (corto_type(test_Line_o)->size != sizeof(test_Line)) {
        corto_error("test_load: calculated size '%d' of type '/test/Line' doesn't match C-type size '%d'", corto_type(test_Line_o)->size, sizeof(test_Line));
    }

    /* Declare /test/Point3D */
    test_Point3D_o = corto_declareChild(test_o, "Point3D", corto_struct_o);
    if (!test_Point3D_o) {
        corto_error("test_load: failed to declare '/test/Point3D' (%s)", corto_lasterr());
        goto error;
    }

    /* Declare /test/Point3D/z */
    test_Point3D_z_o = corto_declareChild(test_Point3D_o, "z", corto_member_o);
    if (!test_Point3D_z_o) {
        corto_error("test_load: failed to declare '/test/Point3D/z' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Point3D/z */
    if (!corto_checkState(test_Point3D_z_o, CORTO_DEFINED)) {
        test_Point3D_z_o->type = corto_resolve(NULL, "/corto/lang/int32");
        test_Point3D_z_o->modifiers = 0x0;
        test_Point3D_z_o->state = 0x6;
        test_Point3D_z_o->weak = FALSE;
        test_Point3D_z_o->id = 0;
        if (corto_define(test_Point3D_z_o)) {
            corto_error("test_load: failed to define '/test/Point3D/z' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Define /test/Point3D */
    if (!corto_checkState(test_Point3D_o, CORTO_DEFINED)) {
        corto_type(test_Point3D_o)->parentType = NULL;
        corto_type(test_Point3D_o)->parentState = 0x6;
        corto_type(test_Point3D_o)->defaultType = NULL;
        corto_type(test_Point3D_o)->defaultProcedureType = NULL;
        corto_interface(test_Point3D_o)->base = corto_resolve(NULL, "/test/Point");
        test_Point3D_o->baseAccess = 0x0;
        if (corto_define(test_Point3D_o)) {
            corto_error("test_load: failed to define '/test/Point3D' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (corto_type(test_Point3D_o)->size != sizeof(test_Point3D)) {
        corto_error("test_load: calculated size '%d' of type '/test/Point3D' doesn't match C-type size '%d'", corto_type(test_Point3D_o)->size, sizeof(test_Point3D));
    }

    /* Declare /test/PrimitiveCollection */
    test_PrimitiveCollection_o = corto_declareChild(test_o, "PrimitiveCollection", corto_struct_o);
    if (!test_PrimitiveCollection_o) {
        corto_error("test_load: failed to declare '/test/PrimitiveCollection' (%s)", corto_lasterr());
        goto error;
    }

    /* Declare /test/PrimitiveCollection/ints */
    test_PrimitiveCollection_ints_o = corto_declareChild(test_PrimitiveCollection_o, "ints", corto_member_o);
    if (!test_PrimitiveCollection_ints_o) {
        corto_error("test_load: failed to declare '/test/PrimitiveCollection/ints' (%s)", corto_lasterr());
        goto error;
    }

    /* Declare /test/Project */
    test_Project_o = corto_declareChild(test_o, "Project", test_Suite_o);
    if (!test_Project_o) {
        corto_error("test_load: failed to declare '/test/Project' (%s)", corto_lasterr());
        goto error;
    }

    /* Declare /test/Project/setup() */
    test_Project_setup_o = corto_declareChild(test_Project_o, "setup()", corto_method_o);
    if (!test_Project_setup_o) {
        corto_error("test_load: failed to declare '/test/Project/setup()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Project/setup() */
    if (!corto_checkState(test_Project_setup_o, CORTO_DEFINED)) {
        corto_function(test_Project_setup_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Project_setup_o)->returnsReference = FALSE;
        test_Project_setup_o->_virtual = FALSE;
        
        /* Bind /test/Project/setup() with C-function */
        corto_function(test_Project_setup_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Project_setup(void *args, void *result);
        corto_function(test_Project_setup_o)->impl = (corto_word)__test_Project_setup;
        if (corto_define(test_Project_setup_o)) {
            corto_error("test_load: failed to define '/test/Project/setup()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Project/teardown() */
    test_Project_teardown_o = corto_declareChild(test_Project_o, "teardown()", corto_method_o);
    if (!test_Project_teardown_o) {
        corto_error("test_load: failed to declare '/test/Project/teardown()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Project/teardown() */
    if (!corto_checkState(test_Project_teardown_o, CORTO_DEFINED)) {
        corto_function(test_Project_teardown_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Project_teardown_o)->returnsReference = FALSE;
        test_Project_teardown_o->_virtual = FALSE;
        
        /* Bind /test/Project/teardown() with C-function */
        corto_function(test_Project_teardown_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Project_teardown(void *args, void *result);
        corto_function(test_Project_teardown_o)->impl = (corto_word)__test_Project_teardown;
        if (corto_define(test_Project_teardown_o)) {
            corto_error("test_load: failed to define '/test/Project/teardown()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Define /test/Project */
    if (!corto_checkState(test_Project_o, CORTO_DEFINED)) {
        corto_type(test_Project_o)->parentType = NULL;
        corto_type(test_Project_o)->parentState = 0x6;
        corto_type(test_Project_o)->defaultType = NULL;
        corto_type(test_Project_o)->defaultProcedureType = NULL;
        corto_interface(test_Project_o)->base = corto_resolve(NULL, "/corto/test/SuiteData");
        corto_struct(test_Project_o)->baseAccess = 0x0;
        corto_class(test_Project_o)->implements.length = 0;
        corto_class(test_Project_o)->implements.buffer = NULL;
        if (corto_define(test_Project_o)) {
            corto_error("test_load: failed to define '/test/Project' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (corto_type(test_Project_o)->size != sizeof(struct test_Project_s)) {
        corto_error("test_load: calculated size '%d' of type '/test/Project' doesn't match C-type size '%d'", corto_type(test_Project_o)->size, sizeof(struct test_Project_s));
    }

    /* Declare /test/Project/tc_app() */
    test_Project_tc_app_o = corto_declareChild(test_Project_o, "tc_app()", test_Case_o);
    if (!test_Project_tc_app_o) {
        corto_error("test_load: failed to declare '/test/Project/tc_app()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Project/tc_app() */
    if (!corto_checkState(test_Project_tc_app_o, CORTO_DEFINED)) {
        corto_function(test_Project_tc_app_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Project_tc_app_o)->returnsReference = FALSE;
        corto_method(test_Project_tc_app_o)->_virtual = FALSE;
        
        /* Bind /test/Project/tc_app() with C-function */
        corto_function(test_Project_tc_app_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Project_tc_app(void *args, void *result);
        corto_function(test_Project_tc_app_o)->impl = (corto_word)__test_Project_tc_app;
        if (corto_define(test_Project_tc_app_o)) {
            corto_error("test_load: failed to define '/test/Project/tc_app()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Project/tc_appNoTest() */
    test_Project_tc_appNoTest_o = corto_declareChild(test_Project_o, "tc_appNoTest()", test_Case_o);
    if (!test_Project_tc_appNoTest_o) {
        corto_error("test_load: failed to declare '/test/Project/tc_appNoTest()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Project/tc_appNoTest() */
    if (!corto_checkState(test_Project_tc_appNoTest_o, CORTO_DEFINED)) {
        corto_function(test_Project_tc_appNoTest_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Project_tc_appNoTest_o)->returnsReference = FALSE;
        corto_method(test_Project_tc_appNoTest_o)->_virtual = FALSE;
        
        /* Bind /test/Project/tc_appNoTest() with C-function */
        corto_function(test_Project_tc_appNoTest_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Project_tc_appNoTest(void *args, void *result);
        corto_function(test_Project_tc_appNoTest_o)->impl = (corto_word)__test_Project_tc_appNoTest;
        if (corto_define(test_Project_tc_appNoTest_o)) {
            corto_error("test_load: failed to define '/test/Project/tc_appNoTest()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Project/tc_package() */
    test_Project_tc_package_o = corto_declareChild(test_Project_o, "tc_package()", test_Case_o);
    if (!test_Project_tc_package_o) {
        corto_error("test_load: failed to declare '/test/Project/tc_package()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Project/tc_package() */
    if (!corto_checkState(test_Project_tc_package_o, CORTO_DEFINED)) {
        corto_function(test_Project_tc_package_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Project_tc_package_o)->returnsReference = FALSE;
        corto_method(test_Project_tc_package_o)->_virtual = FALSE;
        
        /* Bind /test/Project/tc_package() with C-function */
        corto_function(test_Project_tc_package_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Project_tc_package(void *args, void *result);
        corto_function(test_Project_tc_package_o)->impl = (corto_word)__test_Project_tc_package;
        if (corto_define(test_Project_tc_package_o)) {
            corto_error("test_load: failed to define '/test/Project/tc_package()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Project/tc_packageLocal() */
    test_Project_tc_packageLocal_o = corto_declareChild(test_Project_o, "tc_packageLocal()", test_Case_o);
    if (!test_Project_tc_packageLocal_o) {
        corto_error("test_load: failed to declare '/test/Project/tc_packageLocal()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Project/tc_packageLocal() */
    if (!corto_checkState(test_Project_tc_packageLocal_o, CORTO_DEFINED)) {
        corto_function(test_Project_tc_packageLocal_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Project_tc_packageLocal_o)->returnsReference = FALSE;
        corto_method(test_Project_tc_packageLocal_o)->_virtual = FALSE;
        
        /* Bind /test/Project/tc_packageLocal() with C-function */
        corto_function(test_Project_tc_packageLocal_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Project_tc_packageLocal(void *args, void *result);
        corto_function(test_Project_tc_packageLocal_o)->impl = (corto_word)__test_Project_tc_packageLocal;
        if (corto_define(test_Project_tc_packageLocal_o)) {
            corto_error("test_load: failed to define '/test/Project/tc_packageLocal()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Project/tc_publishNotag() */
    test_Project_tc_publishNotag_o = corto_declareChild(test_Project_o, "tc_publishNotag()", test_Case_o);
    if (!test_Project_tc_publishNotag_o) {
        corto_error("test_load: failed to declare '/test/Project/tc_publishNotag()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Project/tc_publishNotag() */
    if (!corto_checkState(test_Project_tc_publishNotag_o, CORTO_DEFINED)) {
        corto_function(test_Project_tc_publishNotag_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Project_tc_publishNotag_o)->returnsReference = FALSE;
        corto_method(test_Project_tc_publishNotag_o)->_virtual = FALSE;
        
        /* Bind /test/Project/tc_publishNotag() with C-function */
        corto_function(test_Project_tc_publishNotag_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Project_tc_publishNotag(void *args, void *result);
        corto_function(test_Project_tc_publishNotag_o)->impl = (corto_word)__test_Project_tc_publishNotag;
        if (corto_define(test_Project_tc_publishNotag_o)) {
            corto_error("test_load: failed to define '/test/Project/tc_publishNotag()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/RelativeName */
    test_RelativeName_o = corto_declareChild(test_o, "RelativeName", test_Suite_o);
    if (!test_RelativeName_o) {
        corto_error("test_load: failed to declare '/test/RelativeName' (%s)", corto_lasterr());
        goto error;
    }

    /* Declare /test/RelativeName/child */
    test_RelativeName_child_o = corto_declareChild(test_RelativeName_o, "child", corto_member_o);
    if (!test_RelativeName_child_o) {
        corto_error("test_load: failed to declare '/test/RelativeName/child' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/RelativeName/child */
    if (!corto_checkState(test_RelativeName_child_o, CORTO_DEFINED)) {
        test_RelativeName_child_o->type = corto_resolve(NULL, "/corto/lang/object");
        test_RelativeName_child_o->modifiers = 0x0;
        test_RelativeName_child_o->state = 0x6;
        test_RelativeName_child_o->weak = FALSE;
        test_RelativeName_child_o->id = 5;
        if (corto_define(test_RelativeName_child_o)) {
            corto_error("test_load: failed to define '/test/RelativeName/child' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/RelativeName/disjunct */
    test_RelativeName_disjunct_o = corto_declareChild(test_RelativeName_o, "disjunct", corto_member_o);
    if (!test_RelativeName_disjunct_o) {
        corto_error("test_load: failed to declare '/test/RelativeName/disjunct' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/RelativeName/disjunct */
    if (!corto_checkState(test_RelativeName_disjunct_o, CORTO_DEFINED)) {
        test_RelativeName_disjunct_o->type = corto_resolve(NULL, "/corto/lang/object");
        test_RelativeName_disjunct_o->modifiers = 0x0;
        test_RelativeName_disjunct_o->state = 0x6;
        test_RelativeName_disjunct_o->weak = FALSE;
        test_RelativeName_disjunct_o->id = 4;
        if (corto_define(test_RelativeName_disjunct_o)) {
            corto_error("test_load: failed to define '/test/RelativeName/disjunct' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/RelativeName/obj */
    test_RelativeName_obj_o = corto_declareChild(test_RelativeName_o, "obj", corto_member_o);
    if (!test_RelativeName_obj_o) {
        corto_error("test_load: failed to declare '/test/RelativeName/obj' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/RelativeName/obj */
    if (!corto_checkState(test_RelativeName_obj_o, CORTO_DEFINED)) {
        test_RelativeName_obj_o->type = corto_resolve(NULL, "/corto/lang/object");
        test_RelativeName_obj_o->modifiers = 0x0;
        test_RelativeName_obj_o->state = 0x6;
        test_RelativeName_obj_o->weak = FALSE;
        test_RelativeName_obj_o->id = 3;
        if (corto_define(test_RelativeName_obj_o)) {
            corto_error("test_load: failed to define '/test/RelativeName/obj' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/RelativeName/setup() */
    test_RelativeName_setup_o = corto_declareChild(test_RelativeName_o, "setup()", corto_method_o);
    if (!test_RelativeName_setup_o) {
        corto_error("test_load: failed to declare '/test/RelativeName/setup()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/RelativeName/setup() */
    if (!corto_checkState(test_RelativeName_setup_o, CORTO_DEFINED)) {
        corto_function(test_RelativeName_setup_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_RelativeName_setup_o)->returnsReference = FALSE;
        test_RelativeName_setup_o->_virtual = FALSE;
        
        /* Bind /test/RelativeName/setup() with C-function */
        corto_function(test_RelativeName_setup_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_RelativeName_setup(void *args, void *result);
        corto_function(test_RelativeName_setup_o)->impl = (corto_word)__test_RelativeName_setup;
        if (corto_define(test_RelativeName_setup_o)) {
            corto_error("test_load: failed to define '/test/RelativeName/setup()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/RelativeName/teardown() */
    test_RelativeName_teardown_o = corto_declareChild(test_RelativeName_o, "teardown()", corto_method_o);
    if (!test_RelativeName_teardown_o) {
        corto_error("test_load: failed to declare '/test/RelativeName/teardown()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/RelativeName/teardown() */
    if (!corto_checkState(test_RelativeName_teardown_o, CORTO_DEFINED)) {
        corto_function(test_RelativeName_teardown_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_RelativeName_teardown_o)->returnsReference = FALSE;
        test_RelativeName_teardown_o->_virtual = FALSE;
        
        /* Bind /test/RelativeName/teardown() with C-function */
        corto_function(test_RelativeName_teardown_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_RelativeName_teardown(void *args, void *result);
        corto_function(test_RelativeName_teardown_o)->impl = (corto_word)__test_RelativeName_teardown;
        if (corto_define(test_RelativeName_teardown_o)) {
            corto_error("test_load: failed to define '/test/RelativeName/teardown()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/RelativeName/tier1 */
    test_RelativeName_tier1_o = corto_declareChild(test_RelativeName_o, "tier1", corto_member_o);
    if (!test_RelativeName_tier1_o) {
        corto_error("test_load: failed to declare '/test/RelativeName/tier1' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/RelativeName/tier1 */
    if (!corto_checkState(test_RelativeName_tier1_o, CORTO_DEFINED)) {
        test_RelativeName_tier1_o->type = corto_resolve(NULL, "/corto/lang/object");
        test_RelativeName_tier1_o->modifiers = 0x0;
        test_RelativeName_tier1_o->state = 0x6;
        test_RelativeName_tier1_o->weak = FALSE;
        test_RelativeName_tier1_o->id = 0;
        if (corto_define(test_RelativeName_tier1_o)) {
            corto_error("test_load: failed to define '/test/RelativeName/tier1' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/RelativeName/tier2 */
    test_RelativeName_tier2_o = corto_declareChild(test_RelativeName_o, "tier2", corto_member_o);
    if (!test_RelativeName_tier2_o) {
        corto_error("test_load: failed to declare '/test/RelativeName/tier2' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/RelativeName/tier2 */
    if (!corto_checkState(test_RelativeName_tier2_o, CORTO_DEFINED)) {
        test_RelativeName_tier2_o->type = corto_resolve(NULL, "/corto/lang/object");
        test_RelativeName_tier2_o->modifiers = 0x0;
        test_RelativeName_tier2_o->state = 0x6;
        test_RelativeName_tier2_o->weak = FALSE;
        test_RelativeName_tier2_o->id = 1;
        if (corto_define(test_RelativeName_tier2_o)) {
            corto_error("test_load: failed to define '/test/RelativeName/tier2' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/RelativeName/tier3 */
    test_RelativeName_tier3_o = corto_declareChild(test_RelativeName_o, "tier3", corto_member_o);
    if (!test_RelativeName_tier3_o) {
        corto_error("test_load: failed to declare '/test/RelativeName/tier3' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/RelativeName/tier3 */
    if (!corto_checkState(test_RelativeName_tier3_o, CORTO_DEFINED)) {
        test_RelativeName_tier3_o->type = corto_resolve(NULL, "/corto/lang/object");
        test_RelativeName_tier3_o->modifiers = 0x0;
        test_RelativeName_tier3_o->state = 0x6;
        test_RelativeName_tier3_o->weak = FALSE;
        test_RelativeName_tier3_o->id = 2;
        if (corto_define(test_RelativeName_tier3_o)) {
            corto_error("test_load: failed to define '/test/RelativeName/tier3' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Define /test/RelativeName */
    if (!corto_checkState(test_RelativeName_o, CORTO_DEFINED)) {
        corto_type(test_RelativeName_o)->parentType = NULL;
        corto_type(test_RelativeName_o)->parentState = 0x6;
        corto_type(test_RelativeName_o)->defaultType = NULL;
        corto_type(test_RelativeName_o)->defaultProcedureType = NULL;
        corto_interface(test_RelativeName_o)->base = corto_resolve(NULL, "/corto/test/SuiteData");
        corto_struct(test_RelativeName_o)->baseAccess = 0x0;
        corto_class(test_RelativeName_o)->implements.length = 0;
        corto_class(test_RelativeName_o)->implements.buffer = NULL;
        if (corto_define(test_RelativeName_o)) {
            corto_error("test_load: failed to define '/test/RelativeName' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (corto_type(test_RelativeName_o)->size != sizeof(struct test_RelativeName_s)) {
        corto_error("test_load: calculated size '%d' of type '/test/RelativeName' doesn't match C-type size '%d'", corto_type(test_RelativeName_o)->size, sizeof(struct test_RelativeName_s));
    }

    /* Declare /test/RelativeName/tc_fromChild() */
    test_RelativeName_tc_fromChild_o = corto_declareChild(test_RelativeName_o, "tc_fromChild()", test_Case_o);
    if (!test_RelativeName_tc_fromChild_o) {
        corto_error("test_load: failed to declare '/test/RelativeName/tc_fromChild()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/RelativeName/tc_fromChild() */
    if (!corto_checkState(test_RelativeName_tc_fromChild_o, CORTO_DEFINED)) {
        corto_function(test_RelativeName_tc_fromChild_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_RelativeName_tc_fromChild_o)->returnsReference = FALSE;
        corto_method(test_RelativeName_tc_fromChild_o)->_virtual = FALSE;
        
        /* Bind /test/RelativeName/tc_fromChild() with C-function */
        corto_function(test_RelativeName_tc_fromChild_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_RelativeName_tc_fromChild(void *args, void *result);
        corto_function(test_RelativeName_tc_fromChild_o)->impl = (corto_word)__test_RelativeName_tc_fromChild;
        if (corto_define(test_RelativeName_tc_fromChild_o)) {
            corto_error("test_load: failed to define '/test/RelativeName/tc_fromChild()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/RelativeName/tc_fromDisjunct() */
    test_RelativeName_tc_fromDisjunct_o = corto_declareChild(test_RelativeName_o, "tc_fromDisjunct()", test_Case_o);
    if (!test_RelativeName_tc_fromDisjunct_o) {
        corto_error("test_load: failed to declare '/test/RelativeName/tc_fromDisjunct()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/RelativeName/tc_fromDisjunct() */
    if (!corto_checkState(test_RelativeName_tc_fromDisjunct_o, CORTO_DEFINED)) {
        corto_function(test_RelativeName_tc_fromDisjunct_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_RelativeName_tc_fromDisjunct_o)->returnsReference = FALSE;
        corto_method(test_RelativeName_tc_fromDisjunct_o)->_virtual = FALSE;
        
        /* Bind /test/RelativeName/tc_fromDisjunct() with C-function */
        corto_function(test_RelativeName_tc_fromDisjunct_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_RelativeName_tc_fromDisjunct(void *args, void *result);
        corto_function(test_RelativeName_tc_fromDisjunct_o)->impl = (corto_word)__test_RelativeName_tc_fromDisjunct;
        if (corto_define(test_RelativeName_tc_fromDisjunct_o)) {
            corto_error("test_load: failed to define '/test/RelativeName/tc_fromDisjunct()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/RelativeName/tc_fromGrandchild() */
    test_RelativeName_tc_fromGrandchild_o = corto_declareChild(test_RelativeName_o, "tc_fromGrandchild()", test_Case_o);
    if (!test_RelativeName_tc_fromGrandchild_o) {
        corto_error("test_load: failed to declare '/test/RelativeName/tc_fromGrandchild()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/RelativeName/tc_fromGrandchild() */
    if (!corto_checkState(test_RelativeName_tc_fromGrandchild_o, CORTO_DEFINED)) {
        corto_function(test_RelativeName_tc_fromGrandchild_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_RelativeName_tc_fromGrandchild_o)->returnsReference = FALSE;
        corto_method(test_RelativeName_tc_fromGrandchild_o)->_virtual = FALSE;
        
        /* Bind /test/RelativeName/tc_fromGrandchild() with C-function */
        corto_function(test_RelativeName_tc_fromGrandchild_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_RelativeName_tc_fromGrandchild(void *args, void *result);
        corto_function(test_RelativeName_tc_fromGrandchild_o)->impl = (corto_word)__test_RelativeName_tc_fromGrandchild;
        if (corto_define(test_RelativeName_tc_fromGrandchild_o)) {
            corto_error("test_load: failed to define '/test/RelativeName/tc_fromGrandchild()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/RelativeName/tc_fromOneUp() */
    test_RelativeName_tc_fromOneUp_o = corto_declareChild(test_RelativeName_o, "tc_fromOneUp()", test_Case_o);
    if (!test_RelativeName_tc_fromOneUp_o) {
        corto_error("test_load: failed to declare '/test/RelativeName/tc_fromOneUp()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/RelativeName/tc_fromOneUp() */
    if (!corto_checkState(test_RelativeName_tc_fromOneUp_o, CORTO_DEFINED)) {
        corto_function(test_RelativeName_tc_fromOneUp_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_RelativeName_tc_fromOneUp_o)->returnsReference = FALSE;
        corto_method(test_RelativeName_tc_fromOneUp_o)->_virtual = FALSE;
        
        /* Bind /test/RelativeName/tc_fromOneUp() with C-function */
        corto_function(test_RelativeName_tc_fromOneUp_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_RelativeName_tc_fromOneUp(void *args, void *result);
        corto_function(test_RelativeName_tc_fromOneUp_o)->impl = (corto_word)__test_RelativeName_tc_fromOneUp;
        if (corto_define(test_RelativeName_tc_fromOneUp_o)) {
            corto_error("test_load: failed to define '/test/RelativeName/tc_fromOneUp()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/RelativeName/tc_fromParent() */
    test_RelativeName_tc_fromParent_o = corto_declareChild(test_RelativeName_o, "tc_fromParent()", test_Case_o);
    if (!test_RelativeName_tc_fromParent_o) {
        corto_error("test_load: failed to declare '/test/RelativeName/tc_fromParent()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/RelativeName/tc_fromParent() */
    if (!corto_checkState(test_RelativeName_tc_fromParent_o, CORTO_DEFINED)) {
        corto_function(test_RelativeName_tc_fromParent_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_RelativeName_tc_fromParent_o)->returnsReference = FALSE;
        corto_method(test_RelativeName_tc_fromParent_o)->_virtual = FALSE;
        
        /* Bind /test/RelativeName/tc_fromParent() with C-function */
        corto_function(test_RelativeName_tc_fromParent_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_RelativeName_tc_fromParent(void *args, void *result);
        corto_function(test_RelativeName_tc_fromParent_o)->impl = (corto_word)__test_RelativeName_tc_fromParent;
        if (corto_define(test_RelativeName_tc_fromParent_o)) {
            corto_error("test_load: failed to define '/test/RelativeName/tc_fromParent()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/RelativeName/tc_fromRoot() */
    test_RelativeName_tc_fromRoot_o = corto_declareChild(test_RelativeName_o, "tc_fromRoot()", test_Case_o);
    if (!test_RelativeName_tc_fromRoot_o) {
        corto_error("test_load: failed to declare '/test/RelativeName/tc_fromRoot()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/RelativeName/tc_fromRoot() */
    if (!corto_checkState(test_RelativeName_tc_fromRoot_o, CORTO_DEFINED)) {
        corto_function(test_RelativeName_tc_fromRoot_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_RelativeName_tc_fromRoot_o)->returnsReference = FALSE;
        corto_method(test_RelativeName_tc_fromRoot_o)->_virtual = FALSE;
        
        /* Bind /test/RelativeName/tc_fromRoot() with C-function */
        corto_function(test_RelativeName_tc_fromRoot_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_RelativeName_tc_fromRoot(void *args, void *result);
        corto_function(test_RelativeName_tc_fromRoot_o)->impl = (corto_word)__test_RelativeName_tc_fromRoot;
        if (corto_define(test_RelativeName_tc_fromRoot_o)) {
            corto_error("test_load: failed to define '/test/RelativeName/tc_fromRoot()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/RelativeName/tc_fromSelf() */
    test_RelativeName_tc_fromSelf_o = corto_declareChild(test_RelativeName_o, "tc_fromSelf()", test_Case_o);
    if (!test_RelativeName_tc_fromSelf_o) {
        corto_error("test_load: failed to declare '/test/RelativeName/tc_fromSelf()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/RelativeName/tc_fromSelf() */
    if (!corto_checkState(test_RelativeName_tc_fromSelf_o, CORTO_DEFINED)) {
        corto_function(test_RelativeName_tc_fromSelf_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_RelativeName_tc_fromSelf_o)->returnsReference = FALSE;
        corto_method(test_RelativeName_tc_fromSelf_o)->_virtual = FALSE;
        
        /* Bind /test/RelativeName/tc_fromSelf() with C-function */
        corto_function(test_RelativeName_tc_fromSelf_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_RelativeName_tc_fromSelf(void *args, void *result);
        corto_function(test_RelativeName_tc_fromSelf_o)->impl = (corto_word)__test_RelativeName_tc_fromSelf;
        if (corto_define(test_RelativeName_tc_fromSelf_o)) {
            corto_error("test_load: failed to define '/test/RelativeName/tc_fromSelf()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/RelativeName/tc_fromThreeUp() */
    test_RelativeName_tc_fromThreeUp_o = corto_declareChild(test_RelativeName_o, "tc_fromThreeUp()", test_Case_o);
    if (!test_RelativeName_tc_fromThreeUp_o) {
        corto_error("test_load: failed to declare '/test/RelativeName/tc_fromThreeUp()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/RelativeName/tc_fromThreeUp() */
    if (!corto_checkState(test_RelativeName_tc_fromThreeUp_o, CORTO_DEFINED)) {
        corto_function(test_RelativeName_tc_fromThreeUp_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_RelativeName_tc_fromThreeUp_o)->returnsReference = FALSE;
        corto_method(test_RelativeName_tc_fromThreeUp_o)->_virtual = FALSE;
        
        /* Bind /test/RelativeName/tc_fromThreeUp() with C-function */
        corto_function(test_RelativeName_tc_fromThreeUp_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_RelativeName_tc_fromThreeUp(void *args, void *result);
        corto_function(test_RelativeName_tc_fromThreeUp_o)->impl = (corto_word)__test_RelativeName_tc_fromThreeUp;
        if (corto_define(test_RelativeName_tc_fromThreeUp_o)) {
            corto_error("test_load: failed to define '/test/RelativeName/tc_fromThreeUp()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/RelativeName/tc_fromTwoUp() */
    test_RelativeName_tc_fromTwoUp_o = corto_declareChild(test_RelativeName_o, "tc_fromTwoUp()", test_Case_o);
    if (!test_RelativeName_tc_fromTwoUp_o) {
        corto_error("test_load: failed to declare '/test/RelativeName/tc_fromTwoUp()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/RelativeName/tc_fromTwoUp() */
    if (!corto_checkState(test_RelativeName_tc_fromTwoUp_o, CORTO_DEFINED)) {
        corto_function(test_RelativeName_tc_fromTwoUp_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_RelativeName_tc_fromTwoUp_o)->returnsReference = FALSE;
        corto_method(test_RelativeName_tc_fromTwoUp_o)->_virtual = FALSE;
        
        /* Bind /test/RelativeName/tc_fromTwoUp() with C-function */
        corto_function(test_RelativeName_tc_fromTwoUp_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_RelativeName_tc_fromTwoUp(void *args, void *result);
        corto_function(test_RelativeName_tc_fromTwoUp_o)->impl = (corto_word)__test_RelativeName_tc_fromTwoUp;
        if (corto_define(test_RelativeName_tc_fromTwoUp_o)) {
            corto_error("test_load: failed to define '/test/RelativeName/tc_fromTwoUp()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/RelativeName/tc_rootFromObj() */
    test_RelativeName_tc_rootFromObj_o = corto_declareChild(test_RelativeName_o, "tc_rootFromObj()", test_Case_o);
    if (!test_RelativeName_tc_rootFromObj_o) {
        corto_error("test_load: failed to declare '/test/RelativeName/tc_rootFromObj()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/RelativeName/tc_rootFromObj() */
    if (!corto_checkState(test_RelativeName_tc_rootFromObj_o, CORTO_DEFINED)) {
        corto_function(test_RelativeName_tc_rootFromObj_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_RelativeName_tc_rootFromObj_o)->returnsReference = FALSE;
        corto_method(test_RelativeName_tc_rootFromObj_o)->_virtual = FALSE;
        
        /* Bind /test/RelativeName/tc_rootFromObj() with C-function */
        corto_function(test_RelativeName_tc_rootFromObj_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_RelativeName_tc_rootFromObj(void *args, void *result);
        corto_function(test_RelativeName_tc_rootFromObj_o)->impl = (corto_word)__test_RelativeName_tc_rootFromObj;
        if (corto_define(test_RelativeName_tc_rootFromObj_o)) {
            corto_error("test_load: failed to define '/test/RelativeName/tc_rootFromObj()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Resolver */
    test_Resolver_o = corto_declareChild(test_o, "Resolver", test_Suite_o);
    if (!test_Resolver_o) {
        corto_error("test_load: failed to declare '/test/Resolver' (%s)", corto_lasterr());
        goto error;
    }

    /* Declare /test/Resolver/setup() */
    test_Resolver_setup_o = corto_declareChild(test_Resolver_o, "setup()", corto_method_o);
    if (!test_Resolver_setup_o) {
        corto_error("test_load: failed to declare '/test/Resolver/setup()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Resolver/setup() */
    if (!corto_checkState(test_Resolver_setup_o, CORTO_DEFINED)) {
        corto_function(test_Resolver_setup_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Resolver_setup_o)->returnsReference = FALSE;
        test_Resolver_setup_o->_virtual = FALSE;
        
        /* Bind /test/Resolver/setup() with C-function */
        corto_function(test_Resolver_setup_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Resolver_setup(void *args, void *result);
        corto_function(test_Resolver_setup_o)->impl = (corto_word)__test_Resolver_setup;
        if (corto_define(test_Resolver_setup_o)) {
            corto_error("test_load: failed to define '/test/Resolver/setup()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Resolver/teardown() */
    test_Resolver_teardown_o = corto_declareChild(test_Resolver_o, "teardown()", corto_method_o);
    if (!test_Resolver_teardown_o) {
        corto_error("test_load: failed to declare '/test/Resolver/teardown()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Resolver/teardown() */
    if (!corto_checkState(test_Resolver_teardown_o, CORTO_DEFINED)) {
        corto_function(test_Resolver_teardown_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Resolver_teardown_o)->returnsReference = FALSE;
        test_Resolver_teardown_o->_virtual = FALSE;
        
        /* Bind /test/Resolver/teardown() with C-function */
        corto_function(test_Resolver_teardown_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Resolver_teardown(void *args, void *result);
        corto_function(test_Resolver_teardown_o)->impl = (corto_word)__test_Resolver_teardown;
        if (corto_define(test_Resolver_teardown_o)) {
            corto_error("test_load: failed to define '/test/Resolver/teardown()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Define /test/Resolver */
    if (!corto_checkState(test_Resolver_o, CORTO_DEFINED)) {
        corto_type(test_Resolver_o)->parentType = NULL;
        corto_type(test_Resolver_o)->parentState = 0x6;
        corto_type(test_Resolver_o)->defaultType = NULL;
        corto_type(test_Resolver_o)->defaultProcedureType = NULL;
        corto_interface(test_Resolver_o)->base = corto_resolve(NULL, "/corto/test/SuiteData");
        corto_struct(test_Resolver_o)->baseAccess = 0x0;
        corto_class(test_Resolver_o)->implements.length = 0;
        corto_class(test_Resolver_o)->implements.buffer = NULL;
        if (corto_define(test_Resolver_o)) {
            corto_error("test_load: failed to define '/test/Resolver' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (corto_type(test_Resolver_o)->size != sizeof(struct test_Resolver_s)) {
        corto_error("test_load: calculated size '%d' of type '/test/Resolver' doesn't match C-type size '%d'", corto_type(test_Resolver_o)->size, sizeof(struct test_Resolver_s));
    }

    /* Declare /test/Resolver/tc_caseInsensitive() */
    test_Resolver_tc_caseInsensitive_o = corto_declareChild(test_Resolver_o, "tc_caseInsensitive()", test_Case_o);
    if (!test_Resolver_tc_caseInsensitive_o) {
        corto_error("test_load: failed to declare '/test/Resolver/tc_caseInsensitive()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Resolver/tc_caseInsensitive() */
    if (!corto_checkState(test_Resolver_tc_caseInsensitive_o, CORTO_DEFINED)) {
        corto_function(test_Resolver_tc_caseInsensitive_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Resolver_tc_caseInsensitive_o)->returnsReference = FALSE;
        corto_method(test_Resolver_tc_caseInsensitive_o)->_virtual = FALSE;
        
        /* Bind /test/Resolver/tc_caseInsensitive() with C-function */
        corto_function(test_Resolver_tc_caseInsensitive_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Resolver_tc_caseInsensitive(void *args, void *result);
        corto_function(test_Resolver_tc_caseInsensitive_o)->impl = (corto_word)__test_Resolver_tc_caseInsensitive;
        if (corto_define(test_Resolver_tc_caseInsensitive_o)) {
            corto_error("test_load: failed to define '/test/Resolver/tc_caseInsensitive()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Resolver/tc_resolveAll() */
    test_Resolver_tc_resolveAll_o = corto_declareChild(test_Resolver_o, "tc_resolveAll()", test_Case_o);
    if (!test_Resolver_tc_resolveAll_o) {
        corto_error("test_load: failed to declare '/test/Resolver/tc_resolveAll()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Resolver/tc_resolveAll() */
    if (!corto_checkState(test_Resolver_tc_resolveAll_o, CORTO_DEFINED)) {
        corto_function(test_Resolver_tc_resolveAll_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Resolver_tc_resolveAll_o)->returnsReference = FALSE;
        corto_method(test_Resolver_tc_resolveAll_o)->_virtual = FALSE;
        
        /* Bind /test/Resolver/tc_resolveAll() with C-function */
        corto_function(test_Resolver_tc_resolveAll_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Resolver_tc_resolveAll(void *args, void *result);
        corto_function(test_Resolver_tc_resolveAll_o)->impl = (corto_word)__test_Resolver_tc_resolveAll;
        if (corto_define(test_Resolver_tc_resolveAll_o)) {
            corto_error("test_load: failed to define '/test/Resolver/tc_resolveAll()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Resolver/tc_resolveAnonymous() */
    test_Resolver_tc_resolveAnonymous_o = corto_declareChild(test_Resolver_o, "tc_resolveAnonymous()", test_Case_o);
    if (!test_Resolver_tc_resolveAnonymous_o) {
        corto_error("test_load: failed to declare '/test/Resolver/tc_resolveAnonymous()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Resolver/tc_resolveAnonymous() */
    if (!corto_checkState(test_Resolver_tc_resolveAnonymous_o, CORTO_DEFINED)) {
        corto_function(test_Resolver_tc_resolveAnonymous_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Resolver_tc_resolveAnonymous_o)->returnsReference = FALSE;
        corto_method(test_Resolver_tc_resolveAnonymous_o)->_virtual = FALSE;
        
        /* Bind /test/Resolver/tc_resolveAnonymous() with C-function */
        corto_function(test_Resolver_tc_resolveAnonymous_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Resolver_tc_resolveAnonymous(void *args, void *result);
        corto_function(test_Resolver_tc_resolveAnonymous_o)->impl = (corto_word)__test_Resolver_tc_resolveAnonymous;
        if (corto_define(test_Resolver_tc_resolveAnonymous_o)) {
            corto_error("test_load: failed to define '/test/Resolver/tc_resolveAnonymous()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Resolver/tc_resolveCorto() */
    test_Resolver_tc_resolveCorto_o = corto_declareChild(test_Resolver_o, "tc_resolveCorto()", test_Case_o);
    if (!test_Resolver_tc_resolveCorto_o) {
        corto_error("test_load: failed to declare '/test/Resolver/tc_resolveCorto()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Resolver/tc_resolveCorto() */
    if (!corto_checkState(test_Resolver_tc_resolveCorto_o, CORTO_DEFINED)) {
        corto_function(test_Resolver_tc_resolveCorto_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Resolver_tc_resolveCorto_o)->returnsReference = FALSE;
        corto_method(test_Resolver_tc_resolveCorto_o)->_virtual = FALSE;
        
        /* Bind /test/Resolver/tc_resolveCorto() with C-function */
        corto_function(test_Resolver_tc_resolveCorto_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Resolver_tc_resolveCorto(void *args, void *result);
        corto_function(test_Resolver_tc_resolveCorto_o)->impl = (corto_word)__test_Resolver_tc_resolveCorto;
        if (corto_define(test_Resolver_tc_resolveCorto_o)) {
            corto_error("test_load: failed to define '/test/Resolver/tc_resolveCorto()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Resolver/tc_resolveEmptyString() */
    test_Resolver_tc_resolveEmptyString_o = corto_declareChild(test_Resolver_o, "tc_resolveEmptyString()", test_Case_o);
    if (!test_Resolver_tc_resolveEmptyString_o) {
        corto_error("test_load: failed to declare '/test/Resolver/tc_resolveEmptyString()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Resolver/tc_resolveEmptyString() */
    if (!corto_checkState(test_Resolver_tc_resolveEmptyString_o, CORTO_DEFINED)) {
        corto_function(test_Resolver_tc_resolveEmptyString_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Resolver_tc_resolveEmptyString_o)->returnsReference = FALSE;
        corto_method(test_Resolver_tc_resolveEmptyString_o)->_virtual = FALSE;
        
        /* Bind /test/Resolver/tc_resolveEmptyString() with C-function */
        corto_function(test_Resolver_tc_resolveEmptyString_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Resolver_tc_resolveEmptyString(void *args, void *result);
        corto_function(test_Resolver_tc_resolveEmptyString_o)->impl = (corto_word)__test_Resolver_tc_resolveEmptyString;
        if (corto_define(test_Resolver_tc_resolveEmptyString_o)) {
            corto_error("test_load: failed to define '/test/Resolver/tc_resolveEmptyString()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Resolver/tc_resolveFunctionArgs() */
    test_Resolver_tc_resolveFunctionArgs_o = corto_declareChild(test_Resolver_o, "tc_resolveFunctionArgs()", test_Case_o);
    if (!test_Resolver_tc_resolveFunctionArgs_o) {
        corto_error("test_load: failed to declare '/test/Resolver/tc_resolveFunctionArgs()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Resolver/tc_resolveFunctionArgs() */
    if (!corto_checkState(test_Resolver_tc_resolveFunctionArgs_o, CORTO_DEFINED)) {
        corto_function(test_Resolver_tc_resolveFunctionArgs_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Resolver_tc_resolveFunctionArgs_o)->returnsReference = FALSE;
        corto_method(test_Resolver_tc_resolveFunctionArgs_o)->_virtual = FALSE;
        
        /* Bind /test/Resolver/tc_resolveFunctionArgs() with C-function */
        corto_function(test_Resolver_tc_resolveFunctionArgs_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Resolver_tc_resolveFunctionArgs(void *args, void *result);
        corto_function(test_Resolver_tc_resolveFunctionArgs_o)->impl = (corto_word)__test_Resolver_tc_resolveFunctionArgs;
        if (corto_define(test_Resolver_tc_resolveFunctionArgs_o)) {
            corto_error("test_load: failed to define '/test/Resolver/tc_resolveFunctionArgs()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Resolver/tc_resolveFunctionNoArgs() */
    test_Resolver_tc_resolveFunctionNoArgs_o = corto_declareChild(test_Resolver_o, "tc_resolveFunctionNoArgs()", test_Case_o);
    if (!test_Resolver_tc_resolveFunctionNoArgs_o) {
        corto_error("test_load: failed to declare '/test/Resolver/tc_resolveFunctionNoArgs()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Resolver/tc_resolveFunctionNoArgs() */
    if (!corto_checkState(test_Resolver_tc_resolveFunctionNoArgs_o, CORTO_DEFINED)) {
        corto_function(test_Resolver_tc_resolveFunctionNoArgs_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Resolver_tc_resolveFunctionNoArgs_o)->returnsReference = FALSE;
        corto_method(test_Resolver_tc_resolveFunctionNoArgs_o)->_virtual = FALSE;
        
        /* Bind /test/Resolver/tc_resolveFunctionNoArgs() with C-function */
        corto_function(test_Resolver_tc_resolveFunctionNoArgs_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Resolver_tc_resolveFunctionNoArgs(void *args, void *result);
        corto_function(test_Resolver_tc_resolveFunctionNoArgs_o)->impl = (corto_word)__test_Resolver_tc_resolveFunctionNoArgs;
        if (corto_define(test_Resolver_tc_resolveFunctionNoArgs_o)) {
            corto_error("test_load: failed to define '/test/Resolver/tc_resolveFunctionNoArgs()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Resolver/tc_resolveIo() */
    test_Resolver_tc_resolveIo_o = corto_declareChild(test_Resolver_o, "tc_resolveIo()", test_Case_o);
    if (!test_Resolver_tc_resolveIo_o) {
        corto_error("test_load: failed to declare '/test/Resolver/tc_resolveIo()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Resolver/tc_resolveIo() */
    if (!corto_checkState(test_Resolver_tc_resolveIo_o, CORTO_DEFINED)) {
        corto_function(test_Resolver_tc_resolveIo_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Resolver_tc_resolveIo_o)->returnsReference = FALSE;
        corto_method(test_Resolver_tc_resolveIo_o)->_virtual = FALSE;
        
        /* Bind /test/Resolver/tc_resolveIo() with C-function */
        corto_function(test_Resolver_tc_resolveIo_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Resolver_tc_resolveIo(void *args, void *result);
        corto_function(test_Resolver_tc_resolveIo_o)->impl = (corto_word)__test_Resolver_tc_resolveIo;
        if (corto_define(test_Resolver_tc_resolveIo_o)) {
            corto_error("test_load: failed to define '/test/Resolver/tc_resolveIo()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Resolver/tc_resolveLang() */
    test_Resolver_tc_resolveLang_o = corto_declareChild(test_Resolver_o, "tc_resolveLang()", test_Case_o);
    if (!test_Resolver_tc_resolveLang_o) {
        corto_error("test_load: failed to declare '/test/Resolver/tc_resolveLang()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Resolver/tc_resolveLang() */
    if (!corto_checkState(test_Resolver_tc_resolveLang_o, CORTO_DEFINED)) {
        corto_function(test_Resolver_tc_resolveLang_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Resolver_tc_resolveLang_o)->returnsReference = FALSE;
        corto_method(test_Resolver_tc_resolveLang_o)->_virtual = FALSE;
        
        /* Bind /test/Resolver/tc_resolveLang() with C-function */
        corto_function(test_Resolver_tc_resolveLang_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Resolver_tc_resolveLang(void *args, void *result);
        corto_function(test_Resolver_tc_resolveLang_o)->impl = (corto_word)__test_Resolver_tc_resolveLang;
        if (corto_define(test_Resolver_tc_resolveLang_o)) {
            corto_error("test_load: failed to define '/test/Resolver/tc_resolveLang()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Resolver/tc_resolveNull() */
    test_Resolver_tc_resolveNull_o = corto_declareChild(test_Resolver_o, "tc_resolveNull()", test_Case_o);
    if (!test_Resolver_tc_resolveNull_o) {
        corto_error("test_load: failed to declare '/test/Resolver/tc_resolveNull()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Resolver/tc_resolveNull() */
    if (!corto_checkState(test_Resolver_tc_resolveNull_o, CORTO_DEFINED)) {
        corto_function(test_Resolver_tc_resolveNull_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Resolver_tc_resolveNull_o)->returnsReference = FALSE;
        corto_method(test_Resolver_tc_resolveNull_o)->_virtual = FALSE;
        
        /* Bind /test/Resolver/tc_resolveNull() with C-function */
        corto_function(test_Resolver_tc_resolveNull_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Resolver_tc_resolveNull(void *args, void *result);
        corto_function(test_Resolver_tc_resolveNull_o)->impl = (corto_word)__test_Resolver_tc_resolveNull;
        if (corto_define(test_Resolver_tc_resolveNull_o)) {
            corto_error("test_load: failed to define '/test/Resolver/tc_resolveNull()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Resolver/tc_resolveParenthesesNoFunction() */
    test_Resolver_tc_resolveParenthesesNoFunction_o = corto_declareChild(test_Resolver_o, "tc_resolveParenthesesNoFunction()", test_Case_o);
    if (!test_Resolver_tc_resolveParenthesesNoFunction_o) {
        corto_error("test_load: failed to declare '/test/Resolver/tc_resolveParenthesesNoFunction()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Resolver/tc_resolveParenthesesNoFunction() */
    if (!corto_checkState(test_Resolver_tc_resolveParenthesesNoFunction_o, CORTO_DEFINED)) {
        corto_function(test_Resolver_tc_resolveParenthesesNoFunction_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Resolver_tc_resolveParenthesesNoFunction_o)->returnsReference = FALSE;
        corto_method(test_Resolver_tc_resolveParenthesesNoFunction_o)->_virtual = FALSE;
        
        /* Bind /test/Resolver/tc_resolveParenthesesNoFunction() with C-function */
        corto_function(test_Resolver_tc_resolveParenthesesNoFunction_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Resolver_tc_resolveParenthesesNoFunction(void *args, void *result);
        corto_function(test_Resolver_tc_resolveParenthesesNoFunction_o)->impl = (corto_word)__test_Resolver_tc_resolveParenthesesNoFunction;
        if (corto_define(test_Resolver_tc_resolveParenthesesNoFunction_o)) {
            corto_error("test_load: failed to define '/test/Resolver/tc_resolveParenthesesNoFunction()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Resolver/tc_resolveParenthesesNoFunctionArgs() */
    test_Resolver_tc_resolveParenthesesNoFunctionArgs_o = corto_declareChild(test_Resolver_o, "tc_resolveParenthesesNoFunctionArgs()", test_Case_o);
    if (!test_Resolver_tc_resolveParenthesesNoFunctionArgs_o) {
        corto_error("test_load: failed to declare '/test/Resolver/tc_resolveParenthesesNoFunctionArgs()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Resolver/tc_resolveParenthesesNoFunctionArgs() */
    if (!corto_checkState(test_Resolver_tc_resolveParenthesesNoFunctionArgs_o, CORTO_DEFINED)) {
        corto_function(test_Resolver_tc_resolveParenthesesNoFunctionArgs_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Resolver_tc_resolveParenthesesNoFunctionArgs_o)->returnsReference = FALSE;
        corto_method(test_Resolver_tc_resolveParenthesesNoFunctionArgs_o)->_virtual = FALSE;
        
        /* Bind /test/Resolver/tc_resolveParenthesesNoFunctionArgs() with C-function */
        corto_function(test_Resolver_tc_resolveParenthesesNoFunctionArgs_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Resolver_tc_resolveParenthesesNoFunctionArgs(void *args, void *result);
        corto_function(test_Resolver_tc_resolveParenthesesNoFunctionArgs_o)->impl = (corto_word)__test_Resolver_tc_resolveParenthesesNoFunctionArgs;
        if (corto_define(test_Resolver_tc_resolveParenthesesNoFunctionArgs_o)) {
            corto_error("test_load: failed to define '/test/Resolver/tc_resolveParenthesesNoFunctionArgs()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Resolver/tc_resolveParenthesesNoFunctionArgsScoped() */
    test_Resolver_tc_resolveParenthesesNoFunctionArgsScoped_o = corto_declareChild(test_Resolver_o, "tc_resolveParenthesesNoFunctionArgsScoped()", test_Case_o);
    if (!test_Resolver_tc_resolveParenthesesNoFunctionArgsScoped_o) {
        corto_error("test_load: failed to declare '/test/Resolver/tc_resolveParenthesesNoFunctionArgsScoped()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Resolver/tc_resolveParenthesesNoFunctionArgsScoped() */
    if (!corto_checkState(test_Resolver_tc_resolveParenthesesNoFunctionArgsScoped_o, CORTO_DEFINED)) {
        corto_function(test_Resolver_tc_resolveParenthesesNoFunctionArgsScoped_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Resolver_tc_resolveParenthesesNoFunctionArgsScoped_o)->returnsReference = FALSE;
        corto_method(test_Resolver_tc_resolveParenthesesNoFunctionArgsScoped_o)->_virtual = FALSE;
        
        /* Bind /test/Resolver/tc_resolveParenthesesNoFunctionArgsScoped() with C-function */
        corto_function(test_Resolver_tc_resolveParenthesesNoFunctionArgsScoped_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Resolver_tc_resolveParenthesesNoFunctionArgsScoped(void *args, void *result);
        corto_function(test_Resolver_tc_resolveParenthesesNoFunctionArgsScoped_o)->impl = (corto_word)__test_Resolver_tc_resolveParenthesesNoFunctionArgsScoped;
        if (corto_define(test_Resolver_tc_resolveParenthesesNoFunctionArgsScoped_o)) {
            corto_error("test_load: failed to define '/test/Resolver/tc_resolveParenthesesNoFunctionArgsScoped()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Resolver/tc_resolveParenthesesNoFunctionMatchingArgs() */
    test_Resolver_tc_resolveParenthesesNoFunctionMatchingArgs_o = corto_declareChild(test_Resolver_o, "tc_resolveParenthesesNoFunctionMatchingArgs()", test_Case_o);
    if (!test_Resolver_tc_resolveParenthesesNoFunctionMatchingArgs_o) {
        corto_error("test_load: failed to declare '/test/Resolver/tc_resolveParenthesesNoFunctionMatchingArgs()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Resolver/tc_resolveParenthesesNoFunctionMatchingArgs() */
    if (!corto_checkState(test_Resolver_tc_resolveParenthesesNoFunctionMatchingArgs_o, CORTO_DEFINED)) {
        corto_function(test_Resolver_tc_resolveParenthesesNoFunctionMatchingArgs_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Resolver_tc_resolveParenthesesNoFunctionMatchingArgs_o)->returnsReference = FALSE;
        corto_method(test_Resolver_tc_resolveParenthesesNoFunctionMatchingArgs_o)->_virtual = FALSE;
        
        /* Bind /test/Resolver/tc_resolveParenthesesNoFunctionMatchingArgs() with C-function */
        corto_function(test_Resolver_tc_resolveParenthesesNoFunctionMatchingArgs_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Resolver_tc_resolveParenthesesNoFunctionMatchingArgs(void *args, void *result);
        corto_function(test_Resolver_tc_resolveParenthesesNoFunctionMatchingArgs_o)->impl = (corto_word)__test_Resolver_tc_resolveParenthesesNoFunctionMatchingArgs;
        if (corto_define(test_Resolver_tc_resolveParenthesesNoFunctionMatchingArgs_o)) {
            corto_error("test_load: failed to define '/test/Resolver/tc_resolveParenthesesNoFunctionMatchingArgs()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Resolver/tc_resolveParenthesesNoFunctionMatchingArgsScoped() */
    test_Resolver_tc_resolveParenthesesNoFunctionMatchingArgsScoped_o = corto_declareChild(test_Resolver_o, "tc_resolveParenthesesNoFunctionMatchingArgsScoped()", test_Case_o);
    if (!test_Resolver_tc_resolveParenthesesNoFunctionMatchingArgsScoped_o) {
        corto_error("test_load: failed to declare '/test/Resolver/tc_resolveParenthesesNoFunctionMatchingArgsScoped()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Resolver/tc_resolveParenthesesNoFunctionMatchingArgsScoped() */
    if (!corto_checkState(test_Resolver_tc_resolveParenthesesNoFunctionMatchingArgsScoped_o, CORTO_DEFINED)) {
        corto_function(test_Resolver_tc_resolveParenthesesNoFunctionMatchingArgsScoped_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Resolver_tc_resolveParenthesesNoFunctionMatchingArgsScoped_o)->returnsReference = FALSE;
        corto_method(test_Resolver_tc_resolveParenthesesNoFunctionMatchingArgsScoped_o)->_virtual = FALSE;
        
        /* Bind /test/Resolver/tc_resolveParenthesesNoFunctionMatchingArgsScoped() with C-function */
        corto_function(test_Resolver_tc_resolveParenthesesNoFunctionMatchingArgsScoped_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Resolver_tc_resolveParenthesesNoFunctionMatchingArgsScoped(void *args, void *result);
        corto_function(test_Resolver_tc_resolveParenthesesNoFunctionMatchingArgsScoped_o)->impl = (corto_word)__test_Resolver_tc_resolveParenthesesNoFunctionMatchingArgsScoped;
        if (corto_define(test_Resolver_tc_resolveParenthesesNoFunctionMatchingArgsScoped_o)) {
            corto_error("test_load: failed to define '/test/Resolver/tc_resolveParenthesesNoFunctionMatchingArgsScoped()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Resolver/tc_resolveParenthesesNoFunctionScoped() */
    test_Resolver_tc_resolveParenthesesNoFunctionScoped_o = corto_declareChild(test_Resolver_o, "tc_resolveParenthesesNoFunctionScoped()", test_Case_o);
    if (!test_Resolver_tc_resolveParenthesesNoFunctionScoped_o) {
        corto_error("test_load: failed to declare '/test/Resolver/tc_resolveParenthesesNoFunctionScoped()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Resolver/tc_resolveParenthesesNoFunctionScoped() */
    if (!corto_checkState(test_Resolver_tc_resolveParenthesesNoFunctionScoped_o, CORTO_DEFINED)) {
        corto_function(test_Resolver_tc_resolveParenthesesNoFunctionScoped_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Resolver_tc_resolveParenthesesNoFunctionScoped_o)->returnsReference = FALSE;
        corto_method(test_Resolver_tc_resolveParenthesesNoFunctionScoped_o)->_virtual = FALSE;
        
        /* Bind /test/Resolver/tc_resolveParenthesesNoFunctionScoped() with C-function */
        corto_function(test_Resolver_tc_resolveParenthesesNoFunctionScoped_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Resolver_tc_resolveParenthesesNoFunctionScoped(void *args, void *result);
        corto_function(test_Resolver_tc_resolveParenthesesNoFunctionScoped_o)->impl = (corto_word)__test_Resolver_tc_resolveParenthesesNoFunctionScoped;
        if (corto_define(test_Resolver_tc_resolveParenthesesNoFunctionScoped_o)) {
            corto_error("test_load: failed to define '/test/Resolver/tc_resolveParenthesesNoFunctionScoped()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Resolver/tc_resolveRoot() */
    test_Resolver_tc_resolveRoot_o = corto_declareChild(test_Resolver_o, "tc_resolveRoot()", test_Case_o);
    if (!test_Resolver_tc_resolveRoot_o) {
        corto_error("test_load: failed to declare '/test/Resolver/tc_resolveRoot()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Resolver/tc_resolveRoot() */
    if (!corto_checkState(test_Resolver_tc_resolveRoot_o, CORTO_DEFINED)) {
        corto_function(test_Resolver_tc_resolveRoot_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Resolver_tc_resolveRoot_o)->returnsReference = FALSE;
        corto_method(test_Resolver_tc_resolveRoot_o)->_virtual = FALSE;
        
        /* Bind /test/Resolver/tc_resolveRoot() with C-function */
        corto_function(test_Resolver_tc_resolveRoot_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Resolver_tc_resolveRoot(void *args, void *result);
        corto_function(test_Resolver_tc_resolveRoot_o)->impl = (corto_word)__test_Resolver_tc_resolveRoot;
        if (corto_define(test_Resolver_tc_resolveRoot_o)) {
            corto_error("test_load: failed to define '/test/Resolver/tc_resolveRoot()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Resolver/tc_resolveString() */
    test_Resolver_tc_resolveString_o = corto_declareChild(test_Resolver_o, "tc_resolveString()", test_Case_o);
    if (!test_Resolver_tc_resolveString_o) {
        corto_error("test_load: failed to declare '/test/Resolver/tc_resolveString()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Resolver/tc_resolveString() */
    if (!corto_checkState(test_Resolver_tc_resolveString_o, CORTO_DEFINED)) {
        corto_function(test_Resolver_tc_resolveString_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Resolver_tc_resolveString_o)->returnsReference = FALSE;
        corto_method(test_Resolver_tc_resolveString_o)->_virtual = FALSE;
        
        /* Bind /test/Resolver/tc_resolveString() with C-function */
        corto_function(test_Resolver_tc_resolveString_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Resolver_tc_resolveString(void *args, void *result);
        corto_function(test_Resolver_tc_resolveString_o)->impl = (corto_word)__test_Resolver_tc_resolveString;
        if (corto_define(test_Resolver_tc_resolveString_o)) {
            corto_error("test_load: failed to define '/test/Resolver/tc_resolveString()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Resolver/tc_resolveThis() */
    test_Resolver_tc_resolveThis_o = corto_declareChild(test_Resolver_o, "tc_resolveThis()", test_Case_o);
    if (!test_Resolver_tc_resolveThis_o) {
        corto_error("test_load: failed to declare '/test/Resolver/tc_resolveThis()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Resolver/tc_resolveThis() */
    if (!corto_checkState(test_Resolver_tc_resolveThis_o, CORTO_DEFINED)) {
        corto_function(test_Resolver_tc_resolveThis_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Resolver_tc_resolveThis_o)->returnsReference = FALSE;
        corto_method(test_Resolver_tc_resolveThis_o)->_virtual = FALSE;
        
        /* Bind /test/Resolver/tc_resolveThis() with C-function */
        corto_function(test_Resolver_tc_resolveThis_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Resolver_tc_resolveThis(void *args, void *result);
        corto_function(test_Resolver_tc_resolveThis_o)->impl = (corto_word)__test_Resolver_tc_resolveThis;
        if (corto_define(test_Resolver_tc_resolveThis_o)) {
            corto_error("test_load: failed to define '/test/Resolver/tc_resolveThis()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Select */
    test_Select_o = corto_declareChild(test_o, "Select", test_Suite_o);
    if (!test_Select_o) {
        corto_error("test_load: failed to declare '/test/Select' (%s)", corto_lasterr());
        goto error;
    }

    /* Declare /test/Select/setup() */
    test_Select_setup_o = corto_declareChild(test_Select_o, "setup()", corto_method_o);
    if (!test_Select_setup_o) {
        corto_error("test_load: failed to declare '/test/Select/setup()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Select/setup() */
    if (!corto_checkState(test_Select_setup_o, CORTO_DEFINED)) {
        corto_function(test_Select_setup_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Select_setup_o)->returnsReference = FALSE;
        test_Select_setup_o->_virtual = FALSE;
        
        /* Bind /test/Select/setup() with C-function */
        corto_function(test_Select_setup_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Select_setup(void *args, void *result);
        corto_function(test_Select_setup_o)->impl = (corto_word)__test_Select_setup;
        if (corto_define(test_Select_setup_o)) {
            corto_error("test_load: failed to define '/test/Select/setup()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Select/teardown() */
    test_Select_teardown_o = corto_declareChild(test_Select_o, "teardown()", corto_method_o);
    if (!test_Select_teardown_o) {
        corto_error("test_load: failed to declare '/test/Select/teardown()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Select/teardown() */
    if (!corto_checkState(test_Select_teardown_o, CORTO_DEFINED)) {
        corto_function(test_Select_teardown_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Select_teardown_o)->returnsReference = FALSE;
        test_Select_teardown_o->_virtual = FALSE;
        
        /* Bind /test/Select/teardown() with C-function */
        corto_function(test_Select_teardown_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Select_teardown(void *args, void *result);
        corto_function(test_Select_teardown_o)->impl = (corto_word)__test_Select_teardown;
        if (corto_define(test_Select_teardown_o)) {
            corto_error("test_load: failed to define '/test/Select/teardown()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Define /test/Select */
    if (!corto_checkState(test_Select_o, CORTO_DEFINED)) {
        corto_type(test_Select_o)->parentType = NULL;
        corto_type(test_Select_o)->parentState = 0x6;
        corto_type(test_Select_o)->defaultType = NULL;
        corto_type(test_Select_o)->defaultProcedureType = NULL;
        corto_interface(test_Select_o)->base = corto_resolve(NULL, "/corto/test/SuiteData");
        corto_struct(test_Select_o)->baseAccess = 0x0;
        corto_class(test_Select_o)->implements.length = 0;
        corto_class(test_Select_o)->implements.buffer = NULL;
        if (corto_define(test_Select_o)) {
            corto_error("test_load: failed to define '/test/Select' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (corto_type(test_Select_o)->size != sizeof(struct test_Select_s)) {
        corto_error("test_load: calculated size '%d' of type '/test/Select' doesn't match C-type size '%d'", corto_type(test_Select_o)->size, sizeof(struct test_Select_s));
    }

    /* Declare /test/Select/collect(object scope,string expr) */
    test_Select_collect_o = corto_declareChild(test_Select_o, "collect(object scope,string expr)", corto_function_o);
    if (!test_Select_collect_o) {
        corto_error("test_load: failed to declare '/test/Select/collect(object scope,string expr)' (%s)", corto_lasterr());
        goto error;
    }

    /* Declare /test/Select/tc_selectDeleteCurrent() */
    test_Select_tc_selectDeleteCurrent_o = corto_declareChild(test_Select_o, "tc_selectDeleteCurrent()", test_Case_o);
    if (!test_Select_tc_selectDeleteCurrent_o) {
        corto_error("test_load: failed to declare '/test/Select/tc_selectDeleteCurrent()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Select/tc_selectDeleteCurrent() */
    if (!corto_checkState(test_Select_tc_selectDeleteCurrent_o, CORTO_DEFINED)) {
        corto_function(test_Select_tc_selectDeleteCurrent_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Select_tc_selectDeleteCurrent_o)->returnsReference = FALSE;
        corto_method(test_Select_tc_selectDeleteCurrent_o)->_virtual = FALSE;
        
        /* Bind /test/Select/tc_selectDeleteCurrent() with C-function */
        corto_function(test_Select_tc_selectDeleteCurrent_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Select_tc_selectDeleteCurrent(void *args, void *result);
        corto_function(test_Select_tc_selectDeleteCurrent_o)->impl = (corto_word)__test_Select_tc_selectDeleteCurrent;
        if (corto_define(test_Select_tc_selectDeleteCurrent_o)) {
            corto_error("test_load: failed to define '/test/Select/tc_selectDeleteCurrent()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Select/tc_selectDeleteFirst() */
    test_Select_tc_selectDeleteFirst_o = corto_declareChild(test_Select_o, "tc_selectDeleteFirst()", test_Case_o);
    if (!test_Select_tc_selectDeleteFirst_o) {
        corto_error("test_load: failed to declare '/test/Select/tc_selectDeleteFirst()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Select/tc_selectDeleteFirst() */
    if (!corto_checkState(test_Select_tc_selectDeleteFirst_o, CORTO_DEFINED)) {
        corto_function(test_Select_tc_selectDeleteFirst_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Select_tc_selectDeleteFirst_o)->returnsReference = FALSE;
        corto_method(test_Select_tc_selectDeleteFirst_o)->_virtual = FALSE;
        
        /* Bind /test/Select/tc_selectDeleteFirst() with C-function */
        corto_function(test_Select_tc_selectDeleteFirst_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Select_tc_selectDeleteFirst(void *args, void *result);
        corto_function(test_Select_tc_selectDeleteFirst_o)->impl = (corto_word)__test_Select_tc_selectDeleteFirst;
        if (corto_define(test_Select_tc_selectDeleteFirst_o)) {
            corto_error("test_load: failed to define '/test/Select/tc_selectDeleteFirst()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Select/tc_selectDeleteNext() */
    test_Select_tc_selectDeleteNext_o = corto_declareChild(test_Select_o, "tc_selectDeleteNext()", test_Case_o);
    if (!test_Select_tc_selectDeleteNext_o) {
        corto_error("test_load: failed to declare '/test/Select/tc_selectDeleteNext()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Select/tc_selectDeleteNext() */
    if (!corto_checkState(test_Select_tc_selectDeleteNext_o, CORTO_DEFINED)) {
        corto_function(test_Select_tc_selectDeleteNext_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Select_tc_selectDeleteNext_o)->returnsReference = FALSE;
        corto_method(test_Select_tc_selectDeleteNext_o)->_virtual = FALSE;
        
        /* Bind /test/Select/tc_selectDeleteNext() with C-function */
        corto_function(test_Select_tc_selectDeleteNext_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Select_tc_selectDeleteNext(void *args, void *result);
        corto_function(test_Select_tc_selectDeleteNext_o)->impl = (corto_word)__test_Select_tc_selectDeleteNext;
        if (corto_define(test_Select_tc_selectDeleteNext_o)) {
            corto_error("test_load: failed to define '/test/Select/tc_selectDeleteNext()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Select/tc_selectDeleteParent() */
    test_Select_tc_selectDeleteParent_o = corto_declareChild(test_Select_o, "tc_selectDeleteParent()", test_Case_o);
    if (!test_Select_tc_selectDeleteParent_o) {
        corto_error("test_load: failed to declare '/test/Select/tc_selectDeleteParent()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Select/tc_selectDeleteParent() */
    if (!corto_checkState(test_Select_tc_selectDeleteParent_o, CORTO_DEFINED)) {
        corto_function(test_Select_tc_selectDeleteParent_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Select_tc_selectDeleteParent_o)->returnsReference = FALSE;
        corto_method(test_Select_tc_selectDeleteParent_o)->_virtual = FALSE;
        
        /* Bind /test/Select/tc_selectDeleteParent() with C-function */
        corto_function(test_Select_tc_selectDeleteParent_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Select_tc_selectDeleteParent(void *args, void *result);
        corto_function(test_Select_tc_selectDeleteParent_o)->impl = (corto_word)__test_Select_tc_selectDeleteParent;
        if (corto_define(test_Select_tc_selectDeleteParent_o)) {
            corto_error("test_load: failed to define '/test/Select/tc_selectDeleteParent()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Select/tc_selectDeletePrevious() */
    test_Select_tc_selectDeletePrevious_o = corto_declareChild(test_Select_o, "tc_selectDeletePrevious()", test_Case_o);
    if (!test_Select_tc_selectDeletePrevious_o) {
        corto_error("test_load: failed to declare '/test/Select/tc_selectDeletePrevious()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Select/tc_selectDeletePrevious() */
    if (!corto_checkState(test_Select_tc_selectDeletePrevious_o, CORTO_DEFINED)) {
        corto_function(test_Select_tc_selectDeletePrevious_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Select_tc_selectDeletePrevious_o)->returnsReference = FALSE;
        corto_method(test_Select_tc_selectDeletePrevious_o)->_virtual = FALSE;
        
        /* Bind /test/Select/tc_selectDeletePrevious() with C-function */
        corto_function(test_Select_tc_selectDeletePrevious_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Select_tc_selectDeletePrevious(void *args, void *result);
        corto_function(test_Select_tc_selectDeletePrevious_o)->impl = (corto_word)__test_Select_tc_selectDeletePrevious;
        if (corto_define(test_Select_tc_selectDeletePrevious_o)) {
            corto_error("test_load: failed to define '/test/Select/tc_selectDeletePrevious()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Select/tc_selectErrParentAst() */
    test_Select_tc_selectErrParentAst_o = corto_declareChild(test_Select_o, "tc_selectErrParentAst()", test_Case_o);
    if (!test_Select_tc_selectErrParentAst_o) {
        corto_error("test_load: failed to declare '/test/Select/tc_selectErrParentAst()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Select/tc_selectErrParentAst() */
    if (!corto_checkState(test_Select_tc_selectErrParentAst_o, CORTO_DEFINED)) {
        corto_function(test_Select_tc_selectErrParentAst_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Select_tc_selectErrParentAst_o)->returnsReference = FALSE;
        corto_method(test_Select_tc_selectErrParentAst_o)->_virtual = FALSE;
        
        /* Bind /test/Select/tc_selectErrParentAst() with C-function */
        corto_function(test_Select_tc_selectErrParentAst_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Select_tc_selectErrParentAst(void *args, void *result);
        corto_function(test_Select_tc_selectErrParentAst_o)->impl = (corto_word)__test_Select_tc_selectErrParentAst;
        if (corto_define(test_Select_tc_selectErrParentAst_o)) {
            corto_error("test_load: failed to define '/test/Select/tc_selectErrParentAst()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Select/tc_selectErrParentId() */
    test_Select_tc_selectErrParentId_o = corto_declareChild(test_Select_o, "tc_selectErrParentId()", test_Case_o);
    if (!test_Select_tc_selectErrParentId_o) {
        corto_error("test_load: failed to declare '/test/Select/tc_selectErrParentId()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Select/tc_selectErrParentId() */
    if (!corto_checkState(test_Select_tc_selectErrParentId_o, CORTO_DEFINED)) {
        corto_function(test_Select_tc_selectErrParentId_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Select_tc_selectErrParentId_o)->returnsReference = FALSE;
        corto_method(test_Select_tc_selectErrParentId_o)->_virtual = FALSE;
        
        /* Bind /test/Select/tc_selectErrParentId() with C-function */
        corto_function(test_Select_tc_selectErrParentId_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Select_tc_selectErrParentId(void *args, void *result);
        corto_function(test_Select_tc_selectErrParentId_o)->impl = (corto_word)__test_Select_tc_selectErrParentId;
        if (corto_define(test_Select_tc_selectErrParentId_o)) {
            corto_error("test_load: failed to define '/test/Select/tc_selectErrParentId()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Select/tc_selectErrParentTree() */
    test_Select_tc_selectErrParentTree_o = corto_declareChild(test_Select_o, "tc_selectErrParentTree()", test_Case_o);
    if (!test_Select_tc_selectErrParentTree_o) {
        corto_error("test_load: failed to declare '/test/Select/tc_selectErrParentTree()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Select/tc_selectErrParentTree() */
    if (!corto_checkState(test_Select_tc_selectErrParentTree_o, CORTO_DEFINED)) {
        corto_function(test_Select_tc_selectErrParentTree_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Select_tc_selectErrParentTree_o)->returnsReference = FALSE;
        corto_method(test_Select_tc_selectErrParentTree_o)->_virtual = FALSE;
        
        /* Bind /test/Select/tc_selectErrParentTree() with C-function */
        corto_function(test_Select_tc_selectErrParentTree_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Select_tc_selectErrParentTree(void *args, void *result);
        corto_function(test_Select_tc_selectErrParentTree_o)->impl = (corto_word)__test_Select_tc_selectErrParentTree;
        if (corto_define(test_Select_tc_selectErrParentTree_o)) {
            corto_error("test_load: failed to define '/test/Select/tc_selectErrParentTree()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Select/tc_selectErrParentWc() */
    test_Select_tc_selectErrParentWc_o = corto_declareChild(test_Select_o, "tc_selectErrParentWc()", test_Case_o);
    if (!test_Select_tc_selectErrParentWc_o) {
        corto_error("test_load: failed to declare '/test/Select/tc_selectErrParentWc()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Select/tc_selectErrParentWc() */
    if (!corto_checkState(test_Select_tc_selectErrParentWc_o, CORTO_DEFINED)) {
        corto_function(test_Select_tc_selectErrParentWc_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Select_tc_selectErrParentWc_o)->returnsReference = FALSE;
        corto_method(test_Select_tc_selectErrParentWc_o)->_virtual = FALSE;
        
        /* Bind /test/Select/tc_selectErrParentWc() with C-function */
        corto_function(test_Select_tc_selectErrParentWc_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Select_tc_selectErrParentWc(void *args, void *result);
        corto_function(test_Select_tc_selectErrParentWc_o)->impl = (corto_word)__test_Select_tc_selectErrParentWc;
        if (corto_define(test_Select_tc_selectErrParentWc_o)) {
            corto_error("test_load: failed to define '/test/Select/tc_selectErrParentWc()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Select/tc_selectErrScopeScope() */
    test_Select_tc_selectErrScopeScope_o = corto_declareChild(test_Select_o, "tc_selectErrScopeScope()", test_Case_o);
    if (!test_Select_tc_selectErrScopeScope_o) {
        corto_error("test_load: failed to declare '/test/Select/tc_selectErrScopeScope()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Select/tc_selectErrScopeScope() */
    if (!corto_checkState(test_Select_tc_selectErrScopeScope_o, CORTO_DEFINED)) {
        corto_function(test_Select_tc_selectErrScopeScope_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Select_tc_selectErrScopeScope_o)->returnsReference = FALSE;
        corto_method(test_Select_tc_selectErrScopeScope_o)->_virtual = FALSE;
        
        /* Bind /test/Select/tc_selectErrScopeScope() with C-function */
        corto_function(test_Select_tc_selectErrScopeScope_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Select_tc_selectErrScopeScope(void *args, void *result);
        corto_function(test_Select_tc_selectErrScopeScope_o)->impl = (corto_word)__test_Select_tc_selectErrScopeScope;
        if (corto_define(test_Select_tc_selectErrScopeScope_o)) {
            corto_error("test_load: failed to define '/test/Select/tc_selectErrScopeScope()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Select/tc_selectFilterAsterisk() */
    test_Select_tc_selectFilterAsterisk_o = corto_declareChild(test_Select_o, "tc_selectFilterAsterisk()", test_Case_o);
    if (!test_Select_tc_selectFilterAsterisk_o) {
        corto_error("test_load: failed to declare '/test/Select/tc_selectFilterAsterisk()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Select/tc_selectFilterAsterisk() */
    if (!corto_checkState(test_Select_tc_selectFilterAsterisk_o, CORTO_DEFINED)) {
        corto_function(test_Select_tc_selectFilterAsterisk_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Select_tc_selectFilterAsterisk_o)->returnsReference = FALSE;
        corto_method(test_Select_tc_selectFilterAsterisk_o)->_virtual = FALSE;
        
        /* Bind /test/Select/tc_selectFilterAsterisk() with C-function */
        corto_function(test_Select_tc_selectFilterAsterisk_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Select_tc_selectFilterAsterisk(void *args, void *result);
        corto_function(test_Select_tc_selectFilterAsterisk_o)->impl = (corto_word)__test_Select_tc_selectFilterAsterisk;
        if (corto_define(test_Select_tc_selectFilterAsterisk_o)) {
            corto_error("test_load: failed to define '/test/Select/tc_selectFilterAsterisk()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Select/tc_selectFilterWildcard() */
    test_Select_tc_selectFilterWildcard_o = corto_declareChild(test_Select_o, "tc_selectFilterWildcard()", test_Case_o);
    if (!test_Select_tc_selectFilterWildcard_o) {
        corto_error("test_load: failed to declare '/test/Select/tc_selectFilterWildcard()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Select/tc_selectFilterWildcard() */
    if (!corto_checkState(test_Select_tc_selectFilterWildcard_o, CORTO_DEFINED)) {
        corto_function(test_Select_tc_selectFilterWildcard_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Select_tc_selectFilterWildcard_o)->returnsReference = FALSE;
        corto_method(test_Select_tc_selectFilterWildcard_o)->_virtual = FALSE;
        
        /* Bind /test/Select/tc_selectFilterWildcard() with C-function */
        corto_function(test_Select_tc_selectFilterWildcard_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Select_tc_selectFilterWildcard(void *args, void *result);
        corto_function(test_Select_tc_selectFilterWildcard_o)->impl = (corto_word)__test_Select_tc_selectFilterWildcard;
        if (corto_define(test_Select_tc_selectFilterWildcard_o)) {
            corto_error("test_load: failed to define '/test/Select/tc_selectFilterWildcard()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Select/tc_selectIdentifier() */
    test_Select_tc_selectIdentifier_o = corto_declareChild(test_Select_o, "tc_selectIdentifier()", test_Case_o);
    if (!test_Select_tc_selectIdentifier_o) {
        corto_error("test_load: failed to declare '/test/Select/tc_selectIdentifier()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Select/tc_selectIdentifier() */
    if (!corto_checkState(test_Select_tc_selectIdentifier_o, CORTO_DEFINED)) {
        corto_function(test_Select_tc_selectIdentifier_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Select_tc_selectIdentifier_o)->returnsReference = FALSE;
        corto_method(test_Select_tc_selectIdentifier_o)->_virtual = FALSE;
        
        /* Bind /test/Select/tc_selectIdentifier() with C-function */
        corto_function(test_Select_tc_selectIdentifier_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Select_tc_selectIdentifier(void *args, void *result);
        corto_function(test_Select_tc_selectIdentifier_o)->impl = (corto_word)__test_Select_tc_selectIdentifier;
        if (corto_define(test_Select_tc_selectIdentifier_o)) {
            corto_error("test_load: failed to define '/test/Select/tc_selectIdentifier()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Select/tc_selectIdentifierCaps() */
    test_Select_tc_selectIdentifierCaps_o = corto_declareChild(test_Select_o, "tc_selectIdentifierCaps()", test_Case_o);
    if (!test_Select_tc_selectIdentifierCaps_o) {
        corto_error("test_load: failed to declare '/test/Select/tc_selectIdentifierCaps()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Select/tc_selectIdentifierCaps() */
    if (!corto_checkState(test_Select_tc_selectIdentifierCaps_o, CORTO_DEFINED)) {
        corto_function(test_Select_tc_selectIdentifierCaps_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Select_tc_selectIdentifierCaps_o)->returnsReference = FALSE;
        corto_method(test_Select_tc_selectIdentifierCaps_o)->_virtual = FALSE;
        
        /* Bind /test/Select/tc_selectIdentifierCaps() with C-function */
        corto_function(test_Select_tc_selectIdentifierCaps_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Select_tc_selectIdentifierCaps(void *args, void *result);
        corto_function(test_Select_tc_selectIdentifierCaps_o)->impl = (corto_word)__test_Select_tc_selectIdentifierCaps;
        if (corto_define(test_Select_tc_selectIdentifierCaps_o)) {
            corto_error("test_load: failed to define '/test/Select/tc_selectIdentifierCaps()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Select/tc_selectNumeric() */
    test_Select_tc_selectNumeric_o = corto_declareChild(test_Select_o, "tc_selectNumeric()", test_Case_o);
    if (!test_Select_tc_selectNumeric_o) {
        corto_error("test_load: failed to declare '/test/Select/tc_selectNumeric()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Select/tc_selectNumeric() */
    if (!corto_checkState(test_Select_tc_selectNumeric_o, CORTO_DEFINED)) {
        corto_function(test_Select_tc_selectNumeric_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Select_tc_selectNumeric_o)->returnsReference = FALSE;
        corto_method(test_Select_tc_selectNumeric_o)->_virtual = FALSE;
        
        /* Bind /test/Select/tc_selectNumeric() with C-function */
        corto_function(test_Select_tc_selectNumeric_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Select_tc_selectNumeric(void *args, void *result);
        corto_function(test_Select_tc_selectNumeric_o)->impl = (corto_word)__test_Select_tc_selectNumeric;
        if (corto_define(test_Select_tc_selectNumeric_o)) {
            corto_error("test_load: failed to define '/test/Select/tc_selectNumeric()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Select/tc_selectOrder() */
    test_Select_tc_selectOrder_o = corto_declareChild(test_Select_o, "tc_selectOrder()", test_Case_o);
    if (!test_Select_tc_selectOrder_o) {
        corto_error("test_load: failed to declare '/test/Select/tc_selectOrder()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Select/tc_selectOrder() */
    if (!corto_checkState(test_Select_tc_selectOrder_o, CORTO_DEFINED)) {
        corto_function(test_Select_tc_selectOrder_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Select_tc_selectOrder_o)->returnsReference = FALSE;
        corto_method(test_Select_tc_selectOrder_o)->_virtual = FALSE;
        
        /* Bind /test/Select/tc_selectOrder() with C-function */
        corto_function(test_Select_tc_selectOrder_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Select_tc_selectOrder(void *args, void *result);
        corto_function(test_Select_tc_selectOrder_o)->impl = (corto_word)__test_Select_tc_selectOrder;
        if (corto_define(test_Select_tc_selectOrder_o)) {
            corto_error("test_load: failed to define '/test/Select/tc_selectOrder()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Select/tc_selectParent() */
    test_Select_tc_selectParent_o = corto_declareChild(test_Select_o, "tc_selectParent()", test_Case_o);
    if (!test_Select_tc_selectParent_o) {
        corto_error("test_load: failed to declare '/test/Select/tc_selectParent()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Select/tc_selectParent() */
    if (!corto_checkState(test_Select_tc_selectParent_o, CORTO_DEFINED)) {
        corto_function(test_Select_tc_selectParent_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Select_tc_selectParent_o)->returnsReference = FALSE;
        corto_method(test_Select_tc_selectParent_o)->_virtual = FALSE;
        
        /* Bind /test/Select/tc_selectParent() with C-function */
        corto_function(test_Select_tc_selectParent_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Select_tc_selectParent(void *args, void *result);
        corto_function(test_Select_tc_selectParent_o)->impl = (corto_word)__test_Select_tc_selectParent;
        if (corto_define(test_Select_tc_selectParent_o)) {
            corto_error("test_load: failed to define '/test/Select/tc_selectParent()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Select/tc_selectScope() */
    test_Select_tc_selectScope_o = corto_declareChild(test_Select_o, "tc_selectScope()", test_Case_o);
    if (!test_Select_tc_selectScope_o) {
        corto_error("test_load: failed to declare '/test/Select/tc_selectScope()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Select/tc_selectScope() */
    if (!corto_checkState(test_Select_tc_selectScope_o, CORTO_DEFINED)) {
        corto_function(test_Select_tc_selectScope_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Select_tc_selectScope_o)->returnsReference = FALSE;
        corto_method(test_Select_tc_selectScope_o)->_virtual = FALSE;
        
        /* Bind /test/Select/tc_selectScope() with C-function */
        corto_function(test_Select_tc_selectScope_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Select_tc_selectScope(void *args, void *result);
        corto_function(test_Select_tc_selectScope_o)->impl = (corto_word)__test_Select_tc_selectScope;
        if (corto_define(test_Select_tc_selectScope_o)) {
            corto_error("test_load: failed to define '/test/Select/tc_selectScope()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Select/tc_selectScopedIdentifier() */
    test_Select_tc_selectScopedIdentifier_o = corto_declareChild(test_Select_o, "tc_selectScopedIdentifier()", test_Case_o);
    if (!test_Select_tc_selectScopedIdentifier_o) {
        corto_error("test_load: failed to declare '/test/Select/tc_selectScopedIdentifier()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Select/tc_selectScopedIdentifier() */
    if (!corto_checkState(test_Select_tc_selectScopedIdentifier_o, CORTO_DEFINED)) {
        corto_function(test_Select_tc_selectScopedIdentifier_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Select_tc_selectScopedIdentifier_o)->returnsReference = FALSE;
        corto_method(test_Select_tc_selectScopedIdentifier_o)->_virtual = FALSE;
        
        /* Bind /test/Select/tc_selectScopedIdentifier() with C-function */
        corto_function(test_Select_tc_selectScopedIdentifier_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Select_tc_selectScopedIdentifier(void *args, void *result);
        corto_function(test_Select_tc_selectScopedIdentifier_o)->impl = (corto_word)__test_Select_tc_selectScopedIdentifier;
        if (corto_define(test_Select_tc_selectScopedIdentifier_o)) {
            corto_error("test_load: failed to define '/test/Select/tc_selectScopedIdentifier()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Select/tc_selectScopedParent() */
    test_Select_tc_selectScopedParent_o = corto_declareChild(test_Select_o, "tc_selectScopedParent()", test_Case_o);
    if (!test_Select_tc_selectScopedParent_o) {
        corto_error("test_load: failed to declare '/test/Select/tc_selectScopedParent()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Select/tc_selectScopedParent() */
    if (!corto_checkState(test_Select_tc_selectScopedParent_o, CORTO_DEFINED)) {
        corto_function(test_Select_tc_selectScopedParent_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Select_tc_selectScopedParent_o)->returnsReference = FALSE;
        corto_method(test_Select_tc_selectScopedParent_o)->_virtual = FALSE;
        
        /* Bind /test/Select/tc_selectScopedParent() with C-function */
        corto_function(test_Select_tc_selectScopedParent_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Select_tc_selectScopedParent(void *args, void *result);
        corto_function(test_Select_tc_selectScopedParent_o)->impl = (corto_word)__test_Select_tc_selectScopedParent;
        if (corto_define(test_Select_tc_selectScopedParent_o)) {
            corto_error("test_load: failed to define '/test/Select/tc_selectScopedParent()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Select/tc_selectScopedThis() */
    test_Select_tc_selectScopedThis_o = corto_declareChild(test_Select_o, "tc_selectScopedThis()", test_Case_o);
    if (!test_Select_tc_selectScopedThis_o) {
        corto_error("test_load: failed to declare '/test/Select/tc_selectScopedThis()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Select/tc_selectScopedThis() */
    if (!corto_checkState(test_Select_tc_selectScopedThis_o, CORTO_DEFINED)) {
        corto_function(test_Select_tc_selectScopedThis_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Select_tc_selectScopedThis_o)->returnsReference = FALSE;
        corto_method(test_Select_tc_selectScopedThis_o)->_virtual = FALSE;
        
        /* Bind /test/Select/tc_selectScopedThis() with C-function */
        corto_function(test_Select_tc_selectScopedThis_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Select_tc_selectScopedThis(void *args, void *result);
        corto_function(test_Select_tc_selectScopedThis_o)->impl = (corto_word)__test_Select_tc_selectScopedThis;
        if (corto_define(test_Select_tc_selectScopedThis_o)) {
            corto_error("test_load: failed to define '/test/Select/tc_selectScopedThis()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Select/tc_selectScopeWithAsterisk() */
    test_Select_tc_selectScopeWithAsterisk_o = corto_declareChild(test_Select_o, "tc_selectScopeWithAsterisk()", test_Case_o);
    if (!test_Select_tc_selectScopeWithAsterisk_o) {
        corto_error("test_load: failed to declare '/test/Select/tc_selectScopeWithAsterisk()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Select/tc_selectScopeWithAsterisk() */
    if (!corto_checkState(test_Select_tc_selectScopeWithAsterisk_o, CORTO_DEFINED)) {
        corto_function(test_Select_tc_selectScopeWithAsterisk_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Select_tc_selectScopeWithAsterisk_o)->returnsReference = FALSE;
        corto_method(test_Select_tc_selectScopeWithAsterisk_o)->_virtual = FALSE;
        
        /* Bind /test/Select/tc_selectScopeWithAsterisk() with C-function */
        corto_function(test_Select_tc_selectScopeWithAsterisk_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Select_tc_selectScopeWithAsterisk(void *args, void *result);
        corto_function(test_Select_tc_selectScopeWithAsterisk_o)->impl = (corto_word)__test_Select_tc_selectScopeWithAsterisk;
        if (corto_define(test_Select_tc_selectScopeWithAsterisk_o)) {
            corto_error("test_load: failed to define '/test/Select/tc_selectScopeWithAsterisk()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Select/tc_selectScopeWithAsteriskFilter() */
    test_Select_tc_selectScopeWithAsteriskFilter_o = corto_declareChild(test_Select_o, "tc_selectScopeWithAsteriskFilter()", test_Case_o);
    if (!test_Select_tc_selectScopeWithAsteriskFilter_o) {
        corto_error("test_load: failed to declare '/test/Select/tc_selectScopeWithAsteriskFilter()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Select/tc_selectScopeWithAsteriskFilter() */
    if (!corto_checkState(test_Select_tc_selectScopeWithAsteriskFilter_o, CORTO_DEFINED)) {
        corto_function(test_Select_tc_selectScopeWithAsteriskFilter_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Select_tc_selectScopeWithAsteriskFilter_o)->returnsReference = FALSE;
        corto_method(test_Select_tc_selectScopeWithAsteriskFilter_o)->_virtual = FALSE;
        
        /* Bind /test/Select/tc_selectScopeWithAsteriskFilter() with C-function */
        corto_function(test_Select_tc_selectScopeWithAsteriskFilter_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Select_tc_selectScopeWithAsteriskFilter(void *args, void *result);
        corto_function(test_Select_tc_selectScopeWithAsteriskFilter_o)->impl = (corto_word)__test_Select_tc_selectScopeWithAsteriskFilter;
        if (corto_define(test_Select_tc_selectScopeWithAsteriskFilter_o)) {
            corto_error("test_load: failed to define '/test/Select/tc_selectScopeWithAsteriskFilter()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Select/tc_selectScopeWithWildcard() */
    test_Select_tc_selectScopeWithWildcard_o = corto_declareChild(test_Select_o, "tc_selectScopeWithWildcard()", test_Case_o);
    if (!test_Select_tc_selectScopeWithWildcard_o) {
        corto_error("test_load: failed to declare '/test/Select/tc_selectScopeWithWildcard()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Select/tc_selectScopeWithWildcard() */
    if (!corto_checkState(test_Select_tc_selectScopeWithWildcard_o, CORTO_DEFINED)) {
        corto_function(test_Select_tc_selectScopeWithWildcard_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Select_tc_selectScopeWithWildcard_o)->returnsReference = FALSE;
        corto_method(test_Select_tc_selectScopeWithWildcard_o)->_virtual = FALSE;
        
        /* Bind /test/Select/tc_selectScopeWithWildcard() with C-function */
        corto_function(test_Select_tc_selectScopeWithWildcard_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Select_tc_selectScopeWithWildcard(void *args, void *result);
        corto_function(test_Select_tc_selectScopeWithWildcard_o)->impl = (corto_word)__test_Select_tc_selectScopeWithWildcard;
        if (corto_define(test_Select_tc_selectScopeWithWildcard_o)) {
            corto_error("test_load: failed to define '/test/Select/tc_selectScopeWithWildcard()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Select/tc_selectScopeWithWildcardFilter() */
    test_Select_tc_selectScopeWithWildcardFilter_o = corto_declareChild(test_Select_o, "tc_selectScopeWithWildcardFilter()", test_Case_o);
    if (!test_Select_tc_selectScopeWithWildcardFilter_o) {
        corto_error("test_load: failed to declare '/test/Select/tc_selectScopeWithWildcardFilter()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Select/tc_selectScopeWithWildcardFilter() */
    if (!corto_checkState(test_Select_tc_selectScopeWithWildcardFilter_o, CORTO_DEFINED)) {
        corto_function(test_Select_tc_selectScopeWithWildcardFilter_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Select_tc_selectScopeWithWildcardFilter_o)->returnsReference = FALSE;
        corto_method(test_Select_tc_selectScopeWithWildcardFilter_o)->_virtual = FALSE;
        
        /* Bind /test/Select/tc_selectScopeWithWildcardFilter() with C-function */
        corto_function(test_Select_tc_selectScopeWithWildcardFilter_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Select_tc_selectScopeWithWildcardFilter(void *args, void *result);
        corto_function(test_Select_tc_selectScopeWithWildcardFilter_o)->impl = (corto_word)__test_Select_tc_selectScopeWithWildcardFilter;
        if (corto_define(test_Select_tc_selectScopeWithWildcardFilter_o)) {
            corto_error("test_load: failed to define '/test/Select/tc_selectScopeWithWildcardFilter()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Select/tc_selectThis() */
    test_Select_tc_selectThis_o = corto_declareChild(test_Select_o, "tc_selectThis()", test_Case_o);
    if (!test_Select_tc_selectThis_o) {
        corto_error("test_load: failed to declare '/test/Select/tc_selectThis()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Select/tc_selectThis() */
    if (!corto_checkState(test_Select_tc_selectThis_o, CORTO_DEFINED)) {
        corto_function(test_Select_tc_selectThis_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Select_tc_selectThis_o)->returnsReference = FALSE;
        corto_method(test_Select_tc_selectThis_o)->_virtual = FALSE;
        
        /* Bind /test/Select/tc_selectThis() with C-function */
        corto_function(test_Select_tc_selectThis_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Select_tc_selectThis(void *args, void *result);
        corto_function(test_Select_tc_selectThis_o)->impl = (corto_word)__test_Select_tc_selectThis;
        if (corto_define(test_Select_tc_selectThis_o)) {
            corto_error("test_load: failed to define '/test/Select/tc_selectThis()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Select/tc_selectTree() */
    test_Select_tc_selectTree_o = corto_declareChild(test_Select_o, "tc_selectTree()", test_Case_o);
    if (!test_Select_tc_selectTree_o) {
        corto_error("test_load: failed to declare '/test/Select/tc_selectTree()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Select/tc_selectTree() */
    if (!corto_checkState(test_Select_tc_selectTree_o, CORTO_DEFINED)) {
        corto_function(test_Select_tc_selectTree_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Select_tc_selectTree_o)->returnsReference = FALSE;
        corto_method(test_Select_tc_selectTree_o)->_virtual = FALSE;
        
        /* Bind /test/Select/tc_selectTree() with C-function */
        corto_function(test_Select_tc_selectTree_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Select_tc_selectTree(void *args, void *result);
        corto_function(test_Select_tc_selectTree_o)->impl = (corto_word)__test_Select_tc_selectTree;
        if (corto_define(test_Select_tc_selectTree_o)) {
            corto_error("test_load: failed to define '/test/Select/tc_selectTree()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Select/tc_selectTreeDeleteCurrent() */
    test_Select_tc_selectTreeDeleteCurrent_o = corto_declareChild(test_Select_o, "tc_selectTreeDeleteCurrent()", test_Case_o);
    if (!test_Select_tc_selectTreeDeleteCurrent_o) {
        corto_error("test_load: failed to declare '/test/Select/tc_selectTreeDeleteCurrent()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Select/tc_selectTreeDeleteCurrent() */
    if (!corto_checkState(test_Select_tc_selectTreeDeleteCurrent_o, CORTO_DEFINED)) {
        corto_function(test_Select_tc_selectTreeDeleteCurrent_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Select_tc_selectTreeDeleteCurrent_o)->returnsReference = FALSE;
        corto_method(test_Select_tc_selectTreeDeleteCurrent_o)->_virtual = FALSE;
        
        /* Bind /test/Select/tc_selectTreeDeleteCurrent() with C-function */
        corto_function(test_Select_tc_selectTreeDeleteCurrent_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Select_tc_selectTreeDeleteCurrent(void *args, void *result);
        corto_function(test_Select_tc_selectTreeDeleteCurrent_o)->impl = (corto_word)__test_Select_tc_selectTreeDeleteCurrent;
        if (corto_define(test_Select_tc_selectTreeDeleteCurrent_o)) {
            corto_error("test_load: failed to define '/test/Select/tc_selectTreeDeleteCurrent()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Select/tc_selectTreeDeleteFirst() */
    test_Select_tc_selectTreeDeleteFirst_o = corto_declareChild(test_Select_o, "tc_selectTreeDeleteFirst()", test_Case_o);
    if (!test_Select_tc_selectTreeDeleteFirst_o) {
        corto_error("test_load: failed to declare '/test/Select/tc_selectTreeDeleteFirst()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Select/tc_selectTreeDeleteFirst() */
    if (!corto_checkState(test_Select_tc_selectTreeDeleteFirst_o, CORTO_DEFINED)) {
        corto_function(test_Select_tc_selectTreeDeleteFirst_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Select_tc_selectTreeDeleteFirst_o)->returnsReference = FALSE;
        corto_method(test_Select_tc_selectTreeDeleteFirst_o)->_virtual = FALSE;
        
        /* Bind /test/Select/tc_selectTreeDeleteFirst() with C-function */
        corto_function(test_Select_tc_selectTreeDeleteFirst_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Select_tc_selectTreeDeleteFirst(void *args, void *result);
        corto_function(test_Select_tc_selectTreeDeleteFirst_o)->impl = (corto_word)__test_Select_tc_selectTreeDeleteFirst;
        if (corto_define(test_Select_tc_selectTreeDeleteFirst_o)) {
            corto_error("test_load: failed to define '/test/Select/tc_selectTreeDeleteFirst()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Select/tc_selectTreeDeleteGrandparent() */
    test_Select_tc_selectTreeDeleteGrandparent_o = corto_declareChild(test_Select_o, "tc_selectTreeDeleteGrandparent()", test_Case_o);
    if (!test_Select_tc_selectTreeDeleteGrandparent_o) {
        corto_error("test_load: failed to declare '/test/Select/tc_selectTreeDeleteGrandparent()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Select/tc_selectTreeDeleteGrandparent() */
    if (!corto_checkState(test_Select_tc_selectTreeDeleteGrandparent_o, CORTO_DEFINED)) {
        corto_function(test_Select_tc_selectTreeDeleteGrandparent_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Select_tc_selectTreeDeleteGrandparent_o)->returnsReference = FALSE;
        corto_method(test_Select_tc_selectTreeDeleteGrandparent_o)->_virtual = FALSE;
        
        /* Bind /test/Select/tc_selectTreeDeleteGrandparent() with C-function */
        corto_function(test_Select_tc_selectTreeDeleteGrandparent_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Select_tc_selectTreeDeleteGrandparent(void *args, void *result);
        corto_function(test_Select_tc_selectTreeDeleteGrandparent_o)->impl = (corto_word)__test_Select_tc_selectTreeDeleteGrandparent;
        if (corto_define(test_Select_tc_selectTreeDeleteGrandparent_o)) {
            corto_error("test_load: failed to define '/test/Select/tc_selectTreeDeleteGrandparent()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Select/tc_selectTreeDeleteNext() */
    test_Select_tc_selectTreeDeleteNext_o = corto_declareChild(test_Select_o, "tc_selectTreeDeleteNext()", test_Case_o);
    if (!test_Select_tc_selectTreeDeleteNext_o) {
        corto_error("test_load: failed to declare '/test/Select/tc_selectTreeDeleteNext()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Select/tc_selectTreeDeleteNext() */
    if (!corto_checkState(test_Select_tc_selectTreeDeleteNext_o, CORTO_DEFINED)) {
        corto_function(test_Select_tc_selectTreeDeleteNext_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Select_tc_selectTreeDeleteNext_o)->returnsReference = FALSE;
        corto_method(test_Select_tc_selectTreeDeleteNext_o)->_virtual = FALSE;
        
        /* Bind /test/Select/tc_selectTreeDeleteNext() with C-function */
        corto_function(test_Select_tc_selectTreeDeleteNext_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Select_tc_selectTreeDeleteNext(void *args, void *result);
        corto_function(test_Select_tc_selectTreeDeleteNext_o)->impl = (corto_word)__test_Select_tc_selectTreeDeleteNext;
        if (corto_define(test_Select_tc_selectTreeDeleteNext_o)) {
            corto_error("test_load: failed to define '/test/Select/tc_selectTreeDeleteNext()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Select/tc_selectTreeDeleteParent() */
    test_Select_tc_selectTreeDeleteParent_o = corto_declareChild(test_Select_o, "tc_selectTreeDeleteParent()", test_Case_o);
    if (!test_Select_tc_selectTreeDeleteParent_o) {
        corto_error("test_load: failed to declare '/test/Select/tc_selectTreeDeleteParent()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Select/tc_selectTreeDeleteParent() */
    if (!corto_checkState(test_Select_tc_selectTreeDeleteParent_o, CORTO_DEFINED)) {
        corto_function(test_Select_tc_selectTreeDeleteParent_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Select_tc_selectTreeDeleteParent_o)->returnsReference = FALSE;
        corto_method(test_Select_tc_selectTreeDeleteParent_o)->_virtual = FALSE;
        
        /* Bind /test/Select/tc_selectTreeDeleteParent() with C-function */
        corto_function(test_Select_tc_selectTreeDeleteParent_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Select_tc_selectTreeDeleteParent(void *args, void *result);
        corto_function(test_Select_tc_selectTreeDeleteParent_o)->impl = (corto_word)__test_Select_tc_selectTreeDeleteParent;
        if (corto_define(test_Select_tc_selectTreeDeleteParent_o)) {
            corto_error("test_load: failed to define '/test/Select/tc_selectTreeDeleteParent()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Select/tc_selectTreeDeletePrevious() */
    test_Select_tc_selectTreeDeletePrevious_o = corto_declareChild(test_Select_o, "tc_selectTreeDeletePrevious()", test_Case_o);
    if (!test_Select_tc_selectTreeDeletePrevious_o) {
        corto_error("test_load: failed to declare '/test/Select/tc_selectTreeDeletePrevious()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Select/tc_selectTreeDeletePrevious() */
    if (!corto_checkState(test_Select_tc_selectTreeDeletePrevious_o, CORTO_DEFINED)) {
        corto_function(test_Select_tc_selectTreeDeletePrevious_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Select_tc_selectTreeDeletePrevious_o)->returnsReference = FALSE;
        corto_method(test_Select_tc_selectTreeDeletePrevious_o)->_virtual = FALSE;
        
        /* Bind /test/Select/tc_selectTreeDeletePrevious() with C-function */
        corto_function(test_Select_tc_selectTreeDeletePrevious_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Select_tc_selectTreeDeletePrevious(void *args, void *result);
        corto_function(test_Select_tc_selectTreeDeletePrevious_o)->impl = (corto_word)__test_Select_tc_selectTreeDeletePrevious;
        if (corto_define(test_Select_tc_selectTreeDeletePrevious_o)) {
            corto_error("test_load: failed to define '/test/Select/tc_selectTreeDeletePrevious()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Select/tc_selectTreeWithAsterisk() */
    test_Select_tc_selectTreeWithAsterisk_o = corto_declareChild(test_Select_o, "tc_selectTreeWithAsterisk()", test_Case_o);
    if (!test_Select_tc_selectTreeWithAsterisk_o) {
        corto_error("test_load: failed to declare '/test/Select/tc_selectTreeWithAsterisk()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Select/tc_selectTreeWithAsterisk() */
    if (!corto_checkState(test_Select_tc_selectTreeWithAsterisk_o, CORTO_DEFINED)) {
        corto_function(test_Select_tc_selectTreeWithAsterisk_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Select_tc_selectTreeWithAsterisk_o)->returnsReference = FALSE;
        corto_method(test_Select_tc_selectTreeWithAsterisk_o)->_virtual = FALSE;
        
        /* Bind /test/Select/tc_selectTreeWithAsterisk() with C-function */
        corto_function(test_Select_tc_selectTreeWithAsterisk_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Select_tc_selectTreeWithAsterisk(void *args, void *result);
        corto_function(test_Select_tc_selectTreeWithAsterisk_o)->impl = (corto_word)__test_Select_tc_selectTreeWithAsterisk;
        if (corto_define(test_Select_tc_selectTreeWithAsterisk_o)) {
            corto_error("test_load: failed to define '/test/Select/tc_selectTreeWithAsterisk()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Select/tc_selectTreeWithAsteriskFilter() */
    test_Select_tc_selectTreeWithAsteriskFilter_o = corto_declareChild(test_Select_o, "tc_selectTreeWithAsteriskFilter()", test_Case_o);
    if (!test_Select_tc_selectTreeWithAsteriskFilter_o) {
        corto_error("test_load: failed to declare '/test/Select/tc_selectTreeWithAsteriskFilter()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Select/tc_selectTreeWithAsteriskFilter() */
    if (!corto_checkState(test_Select_tc_selectTreeWithAsteriskFilter_o, CORTO_DEFINED)) {
        corto_function(test_Select_tc_selectTreeWithAsteriskFilter_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Select_tc_selectTreeWithAsteriskFilter_o)->returnsReference = FALSE;
        corto_method(test_Select_tc_selectTreeWithAsteriskFilter_o)->_virtual = FALSE;
        
        /* Bind /test/Select/tc_selectTreeWithAsteriskFilter() with C-function */
        corto_function(test_Select_tc_selectTreeWithAsteriskFilter_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Select_tc_selectTreeWithAsteriskFilter(void *args, void *result);
        corto_function(test_Select_tc_selectTreeWithAsteriskFilter_o)->impl = (corto_word)__test_Select_tc_selectTreeWithAsteriskFilter;
        if (corto_define(test_Select_tc_selectTreeWithAsteriskFilter_o)) {
            corto_error("test_load: failed to define '/test/Select/tc_selectTreeWithAsteriskFilter()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Select/tc_selectTreeWithWildcard() */
    test_Select_tc_selectTreeWithWildcard_o = corto_declareChild(test_Select_o, "tc_selectTreeWithWildcard()", test_Case_o);
    if (!test_Select_tc_selectTreeWithWildcard_o) {
        corto_error("test_load: failed to declare '/test/Select/tc_selectTreeWithWildcard()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Select/tc_selectTreeWithWildcard() */
    if (!corto_checkState(test_Select_tc_selectTreeWithWildcard_o, CORTO_DEFINED)) {
        corto_function(test_Select_tc_selectTreeWithWildcard_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Select_tc_selectTreeWithWildcard_o)->returnsReference = FALSE;
        corto_method(test_Select_tc_selectTreeWithWildcard_o)->_virtual = FALSE;
        
        /* Bind /test/Select/tc_selectTreeWithWildcard() with C-function */
        corto_function(test_Select_tc_selectTreeWithWildcard_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Select_tc_selectTreeWithWildcard(void *args, void *result);
        corto_function(test_Select_tc_selectTreeWithWildcard_o)->impl = (corto_word)__test_Select_tc_selectTreeWithWildcard;
        if (corto_define(test_Select_tc_selectTreeWithWildcard_o)) {
            corto_error("test_load: failed to define '/test/Select/tc_selectTreeWithWildcard()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Select/tc_selectTreeWithWildcardFilter() */
    test_Select_tc_selectTreeWithWildcardFilter_o = corto_declareChild(test_Select_o, "tc_selectTreeWithWildcardFilter()", test_Case_o);
    if (!test_Select_tc_selectTreeWithWildcardFilter_o) {
        corto_error("test_load: failed to declare '/test/Select/tc_selectTreeWithWildcardFilter()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Select/tc_selectTreeWithWildcardFilter() */
    if (!corto_checkState(test_Select_tc_selectTreeWithWildcardFilter_o, CORTO_DEFINED)) {
        corto_function(test_Select_tc_selectTreeWithWildcardFilter_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Select_tc_selectTreeWithWildcardFilter_o)->returnsReference = FALSE;
        corto_method(test_Select_tc_selectTreeWithWildcardFilter_o)->_virtual = FALSE;
        
        /* Bind /test/Select/tc_selectTreeWithWildcardFilter() with C-function */
        corto_function(test_Select_tc_selectTreeWithWildcardFilter_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Select_tc_selectTreeWithWildcardFilter(void *args, void *result);
        corto_function(test_Select_tc_selectTreeWithWildcardFilter_o)->impl = (corto_word)__test_Select_tc_selectTreeWithWildcardFilter;
        if (corto_define(test_Select_tc_selectTreeWithWildcardFilter_o)) {
            corto_error("test_load: failed to define '/test/Select/tc_selectTreeWithWildcardFilter()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/Select/tc_selectUnderscore() */
    test_Select_tc_selectUnderscore_o = corto_declareChild(test_Select_o, "tc_selectUnderscore()", test_Case_o);
    if (!test_Select_tc_selectUnderscore_o) {
        corto_error("test_load: failed to declare '/test/Select/tc_selectUnderscore()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Select/tc_selectUnderscore() */
    if (!corto_checkState(test_Select_tc_selectUnderscore_o, CORTO_DEFINED)) {
        corto_function(test_Select_tc_selectUnderscore_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_Select_tc_selectUnderscore_o)->returnsReference = FALSE;
        corto_method(test_Select_tc_selectUnderscore_o)->_virtual = FALSE;
        
        /* Bind /test/Select/tc_selectUnderscore() with C-function */
        corto_function(test_Select_tc_selectUnderscore_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Select_tc_selectUnderscore(void *args, void *result);
        corto_function(test_Select_tc_selectUnderscore_o)->impl = (corto_word)__test_Select_tc_selectUnderscore;
        if (corto_define(test_Select_tc_selectUnderscore_o)) {
            corto_error("test_load: failed to define '/test/Select/tc_selectUnderscore()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/selectItem */
    test_selectItem_o = corto_declareChild(test_o, "selectItem", corto_struct_o);
    if (!test_selectItem_o) {
        corto_error("test_load: failed to declare '/test/selectItem' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Select/collect(object scope,string expr) */
    if (!corto_checkState(test_Select_collect_o, CORTO_DEFINED)) {
        test_Select_collect_o->returnType = corto_resolve(NULL, "/corto/lang/list{/test/selectItem,0}");
        test_Select_collect_o->returnsReference = FALSE;
        
        /* Bind /test/Select/collect(object scope,string expr) with C-function */
        corto_function(test_Select_collect_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Select_collect(void *args, void *result);
        corto_function(test_Select_collect_o)->impl = (corto_word)__test_Select_collect;
        if (corto_define(test_Select_collect_o)) {
            corto_error("test_load: failed to define '/test/Select/collect(object scope,string expr)' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/selectItem/name */
    test_selectItem_name_o = corto_declareChild(test_selectItem_o, "name", corto_member_o);
    if (!test_selectItem_name_o) {
        corto_error("test_load: failed to declare '/test/selectItem/name' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/selectItem/name */
    if (!corto_checkState(test_selectItem_name_o, CORTO_DEFINED)) {
        test_selectItem_name_o->type = corto_resolve(NULL, "/corto/lang/string");
        test_selectItem_name_o->modifiers = 0x0;
        test_selectItem_name_o->state = 0x6;
        test_selectItem_name_o->weak = FALSE;
        test_selectItem_name_o->id = 1;
        if (corto_define(test_selectItem_name_o)) {
            corto_error("test_load: failed to define '/test/selectItem/name' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/selectItem/parent */
    test_selectItem_parent_o = corto_declareChild(test_selectItem_o, "parent", corto_member_o);
    if (!test_selectItem_parent_o) {
        corto_error("test_load: failed to declare '/test/selectItem/parent' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/selectItem/parent */
    if (!corto_checkState(test_selectItem_parent_o, CORTO_DEFINED)) {
        test_selectItem_parent_o->type = corto_resolve(NULL, "/corto/lang/string");
        test_selectItem_parent_o->modifiers = 0x0;
        test_selectItem_parent_o->state = 0x6;
        test_selectItem_parent_o->weak = FALSE;
        test_selectItem_parent_o->id = 0;
        if (corto_define(test_selectItem_parent_o)) {
            corto_error("test_load: failed to define '/test/selectItem/parent' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/selectItem/type */
    test_selectItem_type_o = corto_declareChild(test_selectItem_o, "type", corto_member_o);
    if (!test_selectItem_type_o) {
        corto_error("test_load: failed to declare '/test/selectItem/type' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/selectItem/type */
    if (!corto_checkState(test_selectItem_type_o, CORTO_DEFINED)) {
        test_selectItem_type_o->type = corto_resolve(NULL, "/corto/lang/string");
        test_selectItem_type_o->modifiers = 0x0;
        test_selectItem_type_o->state = 0x6;
        test_selectItem_type_o->weak = FALSE;
        test_selectItem_type_o->id = 2;
        if (corto_define(test_selectItem_type_o)) {
            corto_error("test_load: failed to define '/test/selectItem/type' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Define /test/selectItem */
    if (!corto_checkState(test_selectItem_o, CORTO_DEFINED)) {
        corto_type(test_selectItem_o)->parentType = NULL;
        corto_type(test_selectItem_o)->parentState = 0x6;
        corto_type(test_selectItem_o)->defaultType = NULL;
        corto_type(test_selectItem_o)->defaultProcedureType = NULL;
        corto_interface(test_selectItem_o)->base = NULL;
        test_selectItem_o->baseAccess = 0x0;
        if (corto_define(test_selectItem_o)) {
            corto_error("test_load: failed to define '/test/selectItem' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (corto_type(test_selectItem_o)->size != sizeof(test_selectItem)) {
        corto_error("test_load: calculated size '%d' of type '/test/selectItem' doesn't match C-type size '%d'", corto_type(test_selectItem_o)->size, sizeof(test_selectItem));
    }

    /* Declare /test/StringDeserializer */
    test_StringDeserializer_o = corto_declareChild(test_o, "StringDeserializer", test_Suite_o);
    if (!test_StringDeserializer_o) {
        corto_error("test_load: failed to declare '/test/StringDeserializer' (%s)", corto_lasterr());
        goto error;
    }

    /* Declare /test/StringDeserializer/setup() */
    test_StringDeserializer_setup_o = corto_declareChild(test_StringDeserializer_o, "setup()", corto_method_o);
    if (!test_StringDeserializer_setup_o) {
        corto_error("test_load: failed to declare '/test/StringDeserializer/setup()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/StringDeserializer/setup() */
    if (!corto_checkState(test_StringDeserializer_setup_o, CORTO_DEFINED)) {
        corto_function(test_StringDeserializer_setup_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_StringDeserializer_setup_o)->returnsReference = FALSE;
        test_StringDeserializer_setup_o->_virtual = FALSE;
        
        /* Bind /test/StringDeserializer/setup() with C-function */
        corto_function(test_StringDeserializer_setup_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_StringDeserializer_setup(void *args, void *result);
        corto_function(test_StringDeserializer_setup_o)->impl = (corto_word)__test_StringDeserializer_setup;
        if (corto_define(test_StringDeserializer_setup_o)) {
            corto_error("test_load: failed to define '/test/StringDeserializer/setup()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/StringDeserializer/teardown() */
    test_StringDeserializer_teardown_o = corto_declareChild(test_StringDeserializer_o, "teardown()", corto_method_o);
    if (!test_StringDeserializer_teardown_o) {
        corto_error("test_load: failed to declare '/test/StringDeserializer/teardown()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/StringDeserializer/teardown() */
    if (!corto_checkState(test_StringDeserializer_teardown_o, CORTO_DEFINED)) {
        corto_function(test_StringDeserializer_teardown_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_StringDeserializer_teardown_o)->returnsReference = FALSE;
        test_StringDeserializer_teardown_o->_virtual = FALSE;
        
        /* Bind /test/StringDeserializer/teardown() with C-function */
        corto_function(test_StringDeserializer_teardown_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_StringDeserializer_teardown(void *args, void *result);
        corto_function(test_StringDeserializer_teardown_o)->impl = (corto_word)__test_StringDeserializer_teardown;
        if (corto_define(test_StringDeserializer_teardown_o)) {
            corto_error("test_load: failed to define '/test/StringDeserializer/teardown()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Define /test/StringDeserializer */
    if (!corto_checkState(test_StringDeserializer_o, CORTO_DEFINED)) {
        corto_type(test_StringDeserializer_o)->parentType = NULL;
        corto_type(test_StringDeserializer_o)->parentState = 0x6;
        corto_type(test_StringDeserializer_o)->defaultType = NULL;
        corto_type(test_StringDeserializer_o)->defaultProcedureType = NULL;
        corto_interface(test_StringDeserializer_o)->base = corto_resolve(NULL, "/corto/test/SuiteData");
        corto_struct(test_StringDeserializer_o)->baseAccess = 0x0;
        corto_class(test_StringDeserializer_o)->implements.length = 0;
        corto_class(test_StringDeserializer_o)->implements.buffer = NULL;
        if (corto_define(test_StringDeserializer_o)) {
            corto_error("test_load: failed to define '/test/StringDeserializer' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (corto_type(test_StringDeserializer_o)->size != sizeof(struct test_StringDeserializer_s)) {
        corto_error("test_load: calculated size '%d' of type '/test/StringDeserializer' doesn't match C-type size '%d'", corto_type(test_StringDeserializer_o)->size, sizeof(struct test_StringDeserializer_s));
    }

    /* Declare /test/StringDeserializer/tc_deserAnonymousMultiple() */
    test_StringDeserializer_tc_deserAnonymousMultiple_o = corto_declareChild(test_StringDeserializer_o, "tc_deserAnonymousMultiple()", test_Case_o);
    if (!test_StringDeserializer_tc_deserAnonymousMultiple_o) {
        corto_error("test_load: failed to declare '/test/StringDeserializer/tc_deserAnonymousMultiple()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/StringDeserializer/tc_deserAnonymousMultiple() */
    if (!corto_checkState(test_StringDeserializer_tc_deserAnonymousMultiple_o, CORTO_DEFINED)) {
        corto_function(test_StringDeserializer_tc_deserAnonymousMultiple_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_StringDeserializer_tc_deserAnonymousMultiple_o)->returnsReference = FALSE;
        corto_method(test_StringDeserializer_tc_deserAnonymousMultiple_o)->_virtual = FALSE;
        
        /* Bind /test/StringDeserializer/tc_deserAnonymousMultiple() with C-function */
        corto_function(test_StringDeserializer_tc_deserAnonymousMultiple_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_StringDeserializer_tc_deserAnonymousMultiple(void *args, void *result);
        corto_function(test_StringDeserializer_tc_deserAnonymousMultiple_o)->impl = (corto_word)__test_StringDeserializer_tc_deserAnonymousMultiple;
        if (corto_define(test_StringDeserializer_tc_deserAnonymousMultiple_o)) {
            corto_error("test_load: failed to define '/test/StringDeserializer/tc_deserAnonymousMultiple()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/StringDeserializer/tc_deserAnonymousNested() */
    test_StringDeserializer_tc_deserAnonymousNested_o = corto_declareChild(test_StringDeserializer_o, "tc_deserAnonymousNested()", test_Case_o);
    if (!test_StringDeserializer_tc_deserAnonymousNested_o) {
        corto_error("test_load: failed to declare '/test/StringDeserializer/tc_deserAnonymousNested()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/StringDeserializer/tc_deserAnonymousNested() */
    if (!corto_checkState(test_StringDeserializer_tc_deserAnonymousNested_o, CORTO_DEFINED)) {
        corto_function(test_StringDeserializer_tc_deserAnonymousNested_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_StringDeserializer_tc_deserAnonymousNested_o)->returnsReference = FALSE;
        corto_method(test_StringDeserializer_tc_deserAnonymousNested_o)->_virtual = FALSE;
        
        /* Bind /test/StringDeserializer/tc_deserAnonymousNested() with C-function */
        corto_function(test_StringDeserializer_tc_deserAnonymousNested_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_StringDeserializer_tc_deserAnonymousNested(void *args, void *result);
        corto_function(test_StringDeserializer_tc_deserAnonymousNested_o)->impl = (corto_word)__test_StringDeserializer_tc_deserAnonymousNested;
        if (corto_define(test_StringDeserializer_tc_deserAnonymousNested_o)) {
            corto_error("test_load: failed to define '/test/StringDeserializer/tc_deserAnonymousNested()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/StringDeserializer/tc_deserAnonymousReuse() */
    test_StringDeserializer_tc_deserAnonymousReuse_o = corto_declareChild(test_StringDeserializer_o, "tc_deserAnonymousReuse()", test_Case_o);
    if (!test_StringDeserializer_tc_deserAnonymousReuse_o) {
        corto_error("test_load: failed to declare '/test/StringDeserializer/tc_deserAnonymousReuse()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/StringDeserializer/tc_deserAnonymousReuse() */
    if (!corto_checkState(test_StringDeserializer_tc_deserAnonymousReuse_o, CORTO_DEFINED)) {
        corto_function(test_StringDeserializer_tc_deserAnonymousReuse_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_StringDeserializer_tc_deserAnonymousReuse_o)->returnsReference = FALSE;
        corto_method(test_StringDeserializer_tc_deserAnonymousReuse_o)->_virtual = FALSE;
        
        /* Bind /test/StringDeserializer/tc_deserAnonymousReuse() with C-function */
        corto_function(test_StringDeserializer_tc_deserAnonymousReuse_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_StringDeserializer_tc_deserAnonymousReuse(void *args, void *result);
        corto_function(test_StringDeserializer_tc_deserAnonymousReuse_o)->impl = (corto_word)__test_StringDeserializer_tc_deserAnonymousReuse;
        if (corto_define(test_StringDeserializer_tc_deserAnonymousReuse_o)) {
            corto_error("test_load: failed to define '/test/StringDeserializer/tc_deserAnonymousReuse()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/StringDeserializer/tc_deserAnonymousReuseNested() */
    test_StringDeserializer_tc_deserAnonymousReuseNested_o = corto_declareChild(test_StringDeserializer_o, "tc_deserAnonymousReuseNested()", test_Case_o);
    if (!test_StringDeserializer_tc_deserAnonymousReuseNested_o) {
        corto_error("test_load: failed to declare '/test/StringDeserializer/tc_deserAnonymousReuseNested()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/StringDeserializer/tc_deserAnonymousReuseNested() */
    if (!corto_checkState(test_StringDeserializer_tc_deserAnonymousReuseNested_o, CORTO_DEFINED)) {
        corto_function(test_StringDeserializer_tc_deserAnonymousReuseNested_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_StringDeserializer_tc_deserAnonymousReuseNested_o)->returnsReference = FALSE;
        corto_method(test_StringDeserializer_tc_deserAnonymousReuseNested_o)->_virtual = FALSE;
        
        /* Bind /test/StringDeserializer/tc_deserAnonymousReuseNested() with C-function */
        corto_function(test_StringDeserializer_tc_deserAnonymousReuseNested_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_StringDeserializer_tc_deserAnonymousReuseNested(void *args, void *result);
        corto_function(test_StringDeserializer_tc_deserAnonymousReuseNested_o)->impl = (corto_word)__test_StringDeserializer_tc_deserAnonymousReuseNested;
        if (corto_define(test_StringDeserializer_tc_deserAnonymousReuseNested_o)) {
            corto_error("test_load: failed to define '/test/StringDeserializer/tc_deserAnonymousReuseNested()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/StringDeserializer/tc_deserAnonymousSimple() */
    test_StringDeserializer_tc_deserAnonymousSimple_o = corto_declareChild(test_StringDeserializer_o, "tc_deserAnonymousSimple()", test_Case_o);
    if (!test_StringDeserializer_tc_deserAnonymousSimple_o) {
        corto_error("test_load: failed to declare '/test/StringDeserializer/tc_deserAnonymousSimple()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/StringDeserializer/tc_deserAnonymousSimple() */
    if (!corto_checkState(test_StringDeserializer_tc_deserAnonymousSimple_o, CORTO_DEFINED)) {
        corto_function(test_StringDeserializer_tc_deserAnonymousSimple_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_StringDeserializer_tc_deserAnonymousSimple_o)->returnsReference = FALSE;
        corto_method(test_StringDeserializer_tc_deserAnonymousSimple_o)->_virtual = FALSE;
        
        /* Bind /test/StringDeserializer/tc_deserAnonymousSimple() with C-function */
        corto_function(test_StringDeserializer_tc_deserAnonymousSimple_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_StringDeserializer_tc_deserAnonymousSimple(void *args, void *result);
        corto_function(test_StringDeserializer_tc_deserAnonymousSimple_o)->impl = (corto_word)__test_StringDeserializer_tc_deserAnonymousSimple;
        if (corto_define(test_StringDeserializer_tc_deserAnonymousSimple_o)) {
            corto_error("test_load: failed to define '/test/StringDeserializer/tc_deserAnonymousSimple()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/StringDeserializer/tc_deserBoolFalse() */
    test_StringDeserializer_tc_deserBoolFalse_o = corto_declareChild(test_StringDeserializer_o, "tc_deserBoolFalse()", test_Case_o);
    if (!test_StringDeserializer_tc_deserBoolFalse_o) {
        corto_error("test_load: failed to declare '/test/StringDeserializer/tc_deserBoolFalse()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/StringDeserializer/tc_deserBoolFalse() */
    if (!corto_checkState(test_StringDeserializer_tc_deserBoolFalse_o, CORTO_DEFINED)) {
        corto_function(test_StringDeserializer_tc_deserBoolFalse_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_StringDeserializer_tc_deserBoolFalse_o)->returnsReference = FALSE;
        corto_method(test_StringDeserializer_tc_deserBoolFalse_o)->_virtual = FALSE;
        
        /* Bind /test/StringDeserializer/tc_deserBoolFalse() with C-function */
        corto_function(test_StringDeserializer_tc_deserBoolFalse_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_StringDeserializer_tc_deserBoolFalse(void *args, void *result);
        corto_function(test_StringDeserializer_tc_deserBoolFalse_o)->impl = (corto_word)__test_StringDeserializer_tc_deserBoolFalse;
        if (corto_define(test_StringDeserializer_tc_deserBoolFalse_o)) {
            corto_error("test_load: failed to define '/test/StringDeserializer/tc_deserBoolFalse()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/StringDeserializer/tc_deserBoolInvalid() */
    test_StringDeserializer_tc_deserBoolInvalid_o = corto_declareChild(test_StringDeserializer_o, "tc_deserBoolInvalid()", test_Case_o);
    if (!test_StringDeserializer_tc_deserBoolInvalid_o) {
        corto_error("test_load: failed to declare '/test/StringDeserializer/tc_deserBoolInvalid()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/StringDeserializer/tc_deserBoolInvalid() */
    if (!corto_checkState(test_StringDeserializer_tc_deserBoolInvalid_o, CORTO_DEFINED)) {
        corto_function(test_StringDeserializer_tc_deserBoolInvalid_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_StringDeserializer_tc_deserBoolInvalid_o)->returnsReference = FALSE;
        corto_method(test_StringDeserializer_tc_deserBoolInvalid_o)->_virtual = FALSE;
        
        /* Bind /test/StringDeserializer/tc_deserBoolInvalid() with C-function */
        corto_function(test_StringDeserializer_tc_deserBoolInvalid_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_StringDeserializer_tc_deserBoolInvalid(void *args, void *result);
        corto_function(test_StringDeserializer_tc_deserBoolInvalid_o)->impl = (corto_word)__test_StringDeserializer_tc_deserBoolInvalid;
        if (corto_define(test_StringDeserializer_tc_deserBoolInvalid_o)) {
            corto_error("test_load: failed to define '/test/StringDeserializer/tc_deserBoolInvalid()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/StringDeserializer/tc_deserBoolTrue() */
    test_StringDeserializer_tc_deserBoolTrue_o = corto_declareChild(test_StringDeserializer_o, "tc_deserBoolTrue()", test_Case_o);
    if (!test_StringDeserializer_tc_deserBoolTrue_o) {
        corto_error("test_load: failed to declare '/test/StringDeserializer/tc_deserBoolTrue()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/StringDeserializer/tc_deserBoolTrue() */
    if (!corto_checkState(test_StringDeserializer_tc_deserBoolTrue_o, CORTO_DEFINED)) {
        corto_function(test_StringDeserializer_tc_deserBoolTrue_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_StringDeserializer_tc_deserBoolTrue_o)->returnsReference = FALSE;
        corto_method(test_StringDeserializer_tc_deserBoolTrue_o)->_virtual = FALSE;
        
        /* Bind /test/StringDeserializer/tc_deserBoolTrue() with C-function */
        corto_function(test_StringDeserializer_tc_deserBoolTrue_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_StringDeserializer_tc_deserBoolTrue(void *args, void *result);
        corto_function(test_StringDeserializer_tc_deserBoolTrue_o)->impl = (corto_word)__test_StringDeserializer_tc_deserBoolTrue;
        if (corto_define(test_StringDeserializer_tc_deserBoolTrue_o)) {
            corto_error("test_load: failed to define '/test/StringDeserializer/tc_deserBoolTrue()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/StringDeserializer/tc_deserChar() */
    test_StringDeserializer_tc_deserChar_o = corto_declareChild(test_StringDeserializer_o, "tc_deserChar()", test_Case_o);
    if (!test_StringDeserializer_tc_deserChar_o) {
        corto_error("test_load: failed to declare '/test/StringDeserializer/tc_deserChar()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/StringDeserializer/tc_deserChar() */
    if (!corto_checkState(test_StringDeserializer_tc_deserChar_o, CORTO_DEFINED)) {
        corto_function(test_StringDeserializer_tc_deserChar_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_StringDeserializer_tc_deserChar_o)->returnsReference = FALSE;
        corto_method(test_StringDeserializer_tc_deserChar_o)->_virtual = FALSE;
        
        /* Bind /test/StringDeserializer/tc_deserChar() with C-function */
        corto_function(test_StringDeserializer_tc_deserChar_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_StringDeserializer_tc_deserChar(void *args, void *result);
        corto_function(test_StringDeserializer_tc_deserChar_o)->impl = (corto_word)__test_StringDeserializer_tc_deserChar;
        if (corto_define(test_StringDeserializer_tc_deserChar_o)) {
            corto_error("test_load: failed to define '/test/StringDeserializer/tc_deserChar()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/StringDeserializer/tc_deserCharEscape() */
    test_StringDeserializer_tc_deserCharEscape_o = corto_declareChild(test_StringDeserializer_o, "tc_deserCharEscape()", test_Case_o);
    if (!test_StringDeserializer_tc_deserCharEscape_o) {
        corto_error("test_load: failed to declare '/test/StringDeserializer/tc_deserCharEscape()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/StringDeserializer/tc_deserCharEscape() */
    if (!corto_checkState(test_StringDeserializer_tc_deserCharEscape_o, CORTO_DEFINED)) {
        corto_function(test_StringDeserializer_tc_deserCharEscape_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_StringDeserializer_tc_deserCharEscape_o)->returnsReference = FALSE;
        corto_method(test_StringDeserializer_tc_deserCharEscape_o)->_virtual = FALSE;
        
        /* Bind /test/StringDeserializer/tc_deserCharEscape() with C-function */
        corto_function(test_StringDeserializer_tc_deserCharEscape_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_StringDeserializer_tc_deserCharEscape(void *args, void *result);
        corto_function(test_StringDeserializer_tc_deserCharEscape_o)->impl = (corto_word)__test_StringDeserializer_tc_deserCharEscape;
        if (corto_define(test_StringDeserializer_tc_deserCharEscape_o)) {
            corto_error("test_load: failed to define '/test/StringDeserializer/tc_deserCharEscape()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/StringDeserializer/tc_deserCharEscapeQuoted() */
    test_StringDeserializer_tc_deserCharEscapeQuoted_o = corto_declareChild(test_StringDeserializer_o, "tc_deserCharEscapeQuoted()", test_Case_o);
    if (!test_StringDeserializer_tc_deserCharEscapeQuoted_o) {
        corto_error("test_load: failed to declare '/test/StringDeserializer/tc_deserCharEscapeQuoted()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/StringDeserializer/tc_deserCharEscapeQuoted() */
    if (!corto_checkState(test_StringDeserializer_tc_deserCharEscapeQuoted_o, CORTO_DEFINED)) {
        corto_function(test_StringDeserializer_tc_deserCharEscapeQuoted_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_StringDeserializer_tc_deserCharEscapeQuoted_o)->returnsReference = FALSE;
        corto_method(test_StringDeserializer_tc_deserCharEscapeQuoted_o)->_virtual = FALSE;
        
        /* Bind /test/StringDeserializer/tc_deserCharEscapeQuoted() with C-function */
        corto_function(test_StringDeserializer_tc_deserCharEscapeQuoted_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_StringDeserializer_tc_deserCharEscapeQuoted(void *args, void *result);
        corto_function(test_StringDeserializer_tc_deserCharEscapeQuoted_o)->impl = (corto_word)__test_StringDeserializer_tc_deserCharEscapeQuoted;
        if (corto_define(test_StringDeserializer_tc_deserCharEscapeQuoted_o)) {
            corto_error("test_load: failed to define '/test/StringDeserializer/tc_deserCharEscapeQuoted()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/StringDeserializer/tc_deserCharNull() */
    test_StringDeserializer_tc_deserCharNull_o = corto_declareChild(test_StringDeserializer_o, "tc_deserCharNull()", test_Case_o);
    if (!test_StringDeserializer_tc_deserCharNull_o) {
        corto_error("test_load: failed to declare '/test/StringDeserializer/tc_deserCharNull()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/StringDeserializer/tc_deserCharNull() */
    if (!corto_checkState(test_StringDeserializer_tc_deserCharNull_o, CORTO_DEFINED)) {
        corto_function(test_StringDeserializer_tc_deserCharNull_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_StringDeserializer_tc_deserCharNull_o)->returnsReference = FALSE;
        corto_method(test_StringDeserializer_tc_deserCharNull_o)->_virtual = FALSE;
        
        /* Bind /test/StringDeserializer/tc_deserCharNull() with C-function */
        corto_function(test_StringDeserializer_tc_deserCharNull_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_StringDeserializer_tc_deserCharNull(void *args, void *result);
        corto_function(test_StringDeserializer_tc_deserCharNull_o)->impl = (corto_word)__test_StringDeserializer_tc_deserCharNull;
        if (corto_define(test_StringDeserializer_tc_deserCharNull_o)) {
            corto_error("test_load: failed to define '/test/StringDeserializer/tc_deserCharNull()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/StringDeserializer/tc_deserCharNullQuoted() */
    test_StringDeserializer_tc_deserCharNullQuoted_o = corto_declareChild(test_StringDeserializer_o, "tc_deserCharNullQuoted()", test_Case_o);
    if (!test_StringDeserializer_tc_deserCharNullQuoted_o) {
        corto_error("test_load: failed to declare '/test/StringDeserializer/tc_deserCharNullQuoted()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/StringDeserializer/tc_deserCharNullQuoted() */
    if (!corto_checkState(test_StringDeserializer_tc_deserCharNullQuoted_o, CORTO_DEFINED)) {
        corto_function(test_StringDeserializer_tc_deserCharNullQuoted_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_StringDeserializer_tc_deserCharNullQuoted_o)->returnsReference = FALSE;
        corto_method(test_StringDeserializer_tc_deserCharNullQuoted_o)->_virtual = FALSE;
        
        /* Bind /test/StringDeserializer/tc_deserCharNullQuoted() with C-function */
        corto_function(test_StringDeserializer_tc_deserCharNullQuoted_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_StringDeserializer_tc_deserCharNullQuoted(void *args, void *result);
        corto_function(test_StringDeserializer_tc_deserCharNullQuoted_o)->impl = (corto_word)__test_StringDeserializer_tc_deserCharNullQuoted;
        if (corto_define(test_StringDeserializer_tc_deserCharNullQuoted_o)) {
            corto_error("test_load: failed to define '/test/StringDeserializer/tc_deserCharNullQuoted()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/StringDeserializer/tc_deserCharQuoted() */
    test_StringDeserializer_tc_deserCharQuoted_o = corto_declareChild(test_StringDeserializer_o, "tc_deserCharQuoted()", test_Case_o);
    if (!test_StringDeserializer_tc_deserCharQuoted_o) {
        corto_error("test_load: failed to declare '/test/StringDeserializer/tc_deserCharQuoted()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/StringDeserializer/tc_deserCharQuoted() */
    if (!corto_checkState(test_StringDeserializer_tc_deserCharQuoted_o, CORTO_DEFINED)) {
        corto_function(test_StringDeserializer_tc_deserCharQuoted_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_StringDeserializer_tc_deserCharQuoted_o)->returnsReference = FALSE;
        corto_method(test_StringDeserializer_tc_deserCharQuoted_o)->_virtual = FALSE;
        
        /* Bind /test/StringDeserializer/tc_deserCharQuoted() with C-function */
        corto_function(test_StringDeserializer_tc_deserCharQuoted_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_StringDeserializer_tc_deserCharQuoted(void *args, void *result);
        corto_function(test_StringDeserializer_tc_deserCharQuoted_o)->impl = (corto_word)__test_StringDeserializer_tc_deserCharQuoted;
        if (corto_define(test_StringDeserializer_tc_deserCharQuoted_o)) {
            corto_error("test_load: failed to define '/test/StringDeserializer/tc_deserCharQuoted()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/StringDeserializer/tc_deserCollection() */
    test_StringDeserializer_tc_deserCollection_o = corto_declareChild(test_StringDeserializer_o, "tc_deserCollection()", test_Case_o);
    if (!test_StringDeserializer_tc_deserCollection_o) {
        corto_error("test_load: failed to declare '/test/StringDeserializer/tc_deserCollection()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/StringDeserializer/tc_deserCollection() */
    if (!corto_checkState(test_StringDeserializer_tc_deserCollection_o, CORTO_DEFINED)) {
        corto_function(test_StringDeserializer_tc_deserCollection_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_StringDeserializer_tc_deserCollection_o)->returnsReference = FALSE;
        corto_method(test_StringDeserializer_tc_deserCollection_o)->_virtual = FALSE;
        
        /* Bind /test/StringDeserializer/tc_deserCollection() with C-function */
        corto_function(test_StringDeserializer_tc_deserCollection_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_StringDeserializer_tc_deserCollection(void *args, void *result);
        corto_function(test_StringDeserializer_tc_deserCollection_o)->impl = (corto_word)__test_StringDeserializer_tc_deserCollection;
        if (corto_define(test_StringDeserializer_tc_deserCollection_o)) {
            corto_error("test_load: failed to define '/test/StringDeserializer/tc_deserCollection()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/StringDeserializer/tc_deserCollectionComplex() */
    test_StringDeserializer_tc_deserCollectionComplex_o = corto_declareChild(test_StringDeserializer_o, "tc_deserCollectionComplex()", test_Case_o);
    if (!test_StringDeserializer_tc_deserCollectionComplex_o) {
        corto_error("test_load: failed to declare '/test/StringDeserializer/tc_deserCollectionComplex()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/StringDeserializer/tc_deserCollectionComplex() */
    if (!corto_checkState(test_StringDeserializer_tc_deserCollectionComplex_o, CORTO_DEFINED)) {
        corto_function(test_StringDeserializer_tc_deserCollectionComplex_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_StringDeserializer_tc_deserCollectionComplex_o)->returnsReference = FALSE;
        corto_method(test_StringDeserializer_tc_deserCollectionComplex_o)->_virtual = FALSE;
        
        /* Bind /test/StringDeserializer/tc_deserCollectionComplex() with C-function */
        corto_function(test_StringDeserializer_tc_deserCollectionComplex_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_StringDeserializer_tc_deserCollectionComplex(void *args, void *result);
        corto_function(test_StringDeserializer_tc_deserCollectionComplex_o)->impl = (corto_word)__test_StringDeserializer_tc_deserCollectionComplex;
        if (corto_define(test_StringDeserializer_tc_deserCollectionComplex_o)) {
            corto_error("test_load: failed to define '/test/StringDeserializer/tc_deserCollectionComplex()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/StringDeserializer/tc_deserComposite() */
    test_StringDeserializer_tc_deserComposite_o = corto_declareChild(test_StringDeserializer_o, "tc_deserComposite()", test_Case_o);
    if (!test_StringDeserializer_tc_deserComposite_o) {
        corto_error("test_load: failed to declare '/test/StringDeserializer/tc_deserComposite()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/StringDeserializer/tc_deserComposite() */
    if (!corto_checkState(test_StringDeserializer_tc_deserComposite_o, CORTO_DEFINED)) {
        corto_function(test_StringDeserializer_tc_deserComposite_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_StringDeserializer_tc_deserComposite_o)->returnsReference = FALSE;
        corto_method(test_StringDeserializer_tc_deserComposite_o)->_virtual = FALSE;
        
        /* Bind /test/StringDeserializer/tc_deserComposite() with C-function */
        corto_function(test_StringDeserializer_tc_deserComposite_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_StringDeserializer_tc_deserComposite(void *args, void *result);
        corto_function(test_StringDeserializer_tc_deserComposite_o)->impl = (corto_word)__test_StringDeserializer_tc_deserComposite;
        if (corto_define(test_StringDeserializer_tc_deserComposite_o)) {
            corto_error("test_load: failed to define '/test/StringDeserializer/tc_deserComposite()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/StringDeserializer/tc_deserCompositeMembers() */
    test_StringDeserializer_tc_deserCompositeMembers_o = corto_declareChild(test_StringDeserializer_o, "tc_deserCompositeMembers()", test_Case_o);
    if (!test_StringDeserializer_tc_deserCompositeMembers_o) {
        corto_error("test_load: failed to declare '/test/StringDeserializer/tc_deserCompositeMembers()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/StringDeserializer/tc_deserCompositeMembers() */
    if (!corto_checkState(test_StringDeserializer_tc_deserCompositeMembers_o, CORTO_DEFINED)) {
        corto_function(test_StringDeserializer_tc_deserCompositeMembers_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_StringDeserializer_tc_deserCompositeMembers_o)->returnsReference = FALSE;
        corto_method(test_StringDeserializer_tc_deserCompositeMembers_o)->_virtual = FALSE;
        
        /* Bind /test/StringDeserializer/tc_deserCompositeMembers() with C-function */
        corto_function(test_StringDeserializer_tc_deserCompositeMembers_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_StringDeserializer_tc_deserCompositeMembers(void *args, void *result);
        corto_function(test_StringDeserializer_tc_deserCompositeMembers_o)->impl = (corto_word)__test_StringDeserializer_tc_deserCompositeMembers;
        if (corto_define(test_StringDeserializer_tc_deserCompositeMembers_o)) {
            corto_error("test_load: failed to define '/test/StringDeserializer/tc_deserCompositeMembers()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/StringDeserializer/tc_deserCompositeMixed() */
    test_StringDeserializer_tc_deserCompositeMixed_o = corto_declareChild(test_StringDeserializer_o, "tc_deserCompositeMixed()", test_Case_o);
    if (!test_StringDeserializer_tc_deserCompositeMixed_o) {
        corto_error("test_load: failed to declare '/test/StringDeserializer/tc_deserCompositeMixed()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/StringDeserializer/tc_deserCompositeMixed() */
    if (!corto_checkState(test_StringDeserializer_tc_deserCompositeMixed_o, CORTO_DEFINED)) {
        corto_function(test_StringDeserializer_tc_deserCompositeMixed_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_StringDeserializer_tc_deserCompositeMixed_o)->returnsReference = FALSE;
        corto_method(test_StringDeserializer_tc_deserCompositeMixed_o)->_virtual = FALSE;
        
        /* Bind /test/StringDeserializer/tc_deserCompositeMixed() with C-function */
        corto_function(test_StringDeserializer_tc_deserCompositeMixed_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_StringDeserializer_tc_deserCompositeMixed(void *args, void *result);
        corto_function(test_StringDeserializer_tc_deserCompositeMixed_o)->impl = (corto_word)__test_StringDeserializer_tc_deserCompositeMixed;
        if (corto_define(test_StringDeserializer_tc_deserCompositeMixed_o)) {
            corto_error("test_load: failed to define '/test/StringDeserializer/tc_deserCompositeMixed()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/StringDeserializer/tc_deserCompositeNested() */
    test_StringDeserializer_tc_deserCompositeNested_o = corto_declareChild(test_StringDeserializer_o, "tc_deserCompositeNested()", test_Case_o);
    if (!test_StringDeserializer_tc_deserCompositeNested_o) {
        corto_error("test_load: failed to declare '/test/StringDeserializer/tc_deserCompositeNested()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/StringDeserializer/tc_deserCompositeNested() */
    if (!corto_checkState(test_StringDeserializer_tc_deserCompositeNested_o, CORTO_DEFINED)) {
        corto_function(test_StringDeserializer_tc_deserCompositeNested_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_StringDeserializer_tc_deserCompositeNested_o)->returnsReference = FALSE;
        corto_method(test_StringDeserializer_tc_deserCompositeNested_o)->_virtual = FALSE;
        
        /* Bind /test/StringDeserializer/tc_deserCompositeNested() with C-function */
        corto_function(test_StringDeserializer_tc_deserCompositeNested_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_StringDeserializer_tc_deserCompositeNested(void *args, void *result);
        corto_function(test_StringDeserializer_tc_deserCompositeNested_o)->impl = (corto_word)__test_StringDeserializer_tc_deserCompositeNested;
        if (corto_define(test_StringDeserializer_tc_deserCompositeNested_o)) {
            corto_error("test_load: failed to define '/test/StringDeserializer/tc_deserCompositeNested()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/StringDeserializer/tc_deserCompositeNestedMembers() */
    test_StringDeserializer_tc_deserCompositeNestedMembers_o = corto_declareChild(test_StringDeserializer_o, "tc_deserCompositeNestedMembers()", test_Case_o);
    if (!test_StringDeserializer_tc_deserCompositeNestedMembers_o) {
        corto_error("test_load: failed to declare '/test/StringDeserializer/tc_deserCompositeNestedMembers()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/StringDeserializer/tc_deserCompositeNestedMembers() */
    if (!corto_checkState(test_StringDeserializer_tc_deserCompositeNestedMembers_o, CORTO_DEFINED)) {
        corto_function(test_StringDeserializer_tc_deserCompositeNestedMembers_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_StringDeserializer_tc_deserCompositeNestedMembers_o)->returnsReference = FALSE;
        corto_method(test_StringDeserializer_tc_deserCompositeNestedMembers_o)->_virtual = FALSE;
        
        /* Bind /test/StringDeserializer/tc_deserCompositeNestedMembers() with C-function */
        corto_function(test_StringDeserializer_tc_deserCompositeNestedMembers_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_StringDeserializer_tc_deserCompositeNestedMembers(void *args, void *result);
        corto_function(test_StringDeserializer_tc_deserCompositeNestedMembers_o)->impl = (corto_word)__test_StringDeserializer_tc_deserCompositeNestedMembers;
        if (corto_define(test_StringDeserializer_tc_deserCompositeNestedMembers_o)) {
            corto_error("test_load: failed to define '/test/StringDeserializer/tc_deserCompositeNestedMembers()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/StringDeserializer/tc_deserCompositeNestedMixed() */
    test_StringDeserializer_tc_deserCompositeNestedMixed_o = corto_declareChild(test_StringDeserializer_o, "tc_deserCompositeNestedMixed()", test_Case_o);
    if (!test_StringDeserializer_tc_deserCompositeNestedMixed_o) {
        corto_error("test_load: failed to declare '/test/StringDeserializer/tc_deserCompositeNestedMixed()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/StringDeserializer/tc_deserCompositeNestedMixed() */
    if (!corto_checkState(test_StringDeserializer_tc_deserCompositeNestedMixed_o, CORTO_DEFINED)) {
        corto_function(test_StringDeserializer_tc_deserCompositeNestedMixed_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_StringDeserializer_tc_deserCompositeNestedMixed_o)->returnsReference = FALSE;
        corto_method(test_StringDeserializer_tc_deserCompositeNestedMixed_o)->_virtual = FALSE;
        
        /* Bind /test/StringDeserializer/tc_deserCompositeNestedMixed() with C-function */
        corto_function(test_StringDeserializer_tc_deserCompositeNestedMixed_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_StringDeserializer_tc_deserCompositeNestedMixed(void *args, void *result);
        corto_function(test_StringDeserializer_tc_deserCompositeNestedMixed_o)->impl = (corto_word)__test_StringDeserializer_tc_deserCompositeNestedMixed;
        if (corto_define(test_StringDeserializer_tc_deserCompositeNestedMixed_o)) {
            corto_error("test_load: failed to define '/test/StringDeserializer/tc_deserCompositeNestedMixed()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/StringDeserializer/tc_deserCompositeNoType() */
    test_StringDeserializer_tc_deserCompositeNoType_o = corto_declareChild(test_StringDeserializer_o, "tc_deserCompositeNoType()", test_Case_o);
    if (!test_StringDeserializer_tc_deserCompositeNoType_o) {
        corto_error("test_load: failed to declare '/test/StringDeserializer/tc_deserCompositeNoType()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/StringDeserializer/tc_deserCompositeNoType() */
    if (!corto_checkState(test_StringDeserializer_tc_deserCompositeNoType_o, CORTO_DEFINED)) {
        corto_function(test_StringDeserializer_tc_deserCompositeNoType_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_StringDeserializer_tc_deserCompositeNoType_o)->returnsReference = FALSE;
        corto_method(test_StringDeserializer_tc_deserCompositeNoType_o)->_virtual = FALSE;
        
        /* Bind /test/StringDeserializer/tc_deserCompositeNoType() with C-function */
        corto_function(test_StringDeserializer_tc_deserCompositeNoType_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_StringDeserializer_tc_deserCompositeNoType(void *args, void *result);
        corto_function(test_StringDeserializer_tc_deserCompositeNoType_o)->impl = (corto_word)__test_StringDeserializer_tc_deserCompositeNoType;
        if (corto_define(test_StringDeserializer_tc_deserCompositeNoType_o)) {
            corto_error("test_load: failed to define '/test/StringDeserializer/tc_deserCompositeNoType()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/StringDeserializer/tc_deserCompositeWhitespace() */
    test_StringDeserializer_tc_deserCompositeWhitespace_o = corto_declareChild(test_StringDeserializer_o, "tc_deserCompositeWhitespace()", test_Case_o);
    if (!test_StringDeserializer_tc_deserCompositeWhitespace_o) {
        corto_error("test_load: failed to declare '/test/StringDeserializer/tc_deserCompositeWhitespace()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/StringDeserializer/tc_deserCompositeWhitespace() */
    if (!corto_checkState(test_StringDeserializer_tc_deserCompositeWhitespace_o, CORTO_DEFINED)) {
        corto_function(test_StringDeserializer_tc_deserCompositeWhitespace_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_StringDeserializer_tc_deserCompositeWhitespace_o)->returnsReference = FALSE;
        corto_method(test_StringDeserializer_tc_deserCompositeWhitespace_o)->_virtual = FALSE;
        
        /* Bind /test/StringDeserializer/tc_deserCompositeWhitespace() with C-function */
        corto_function(test_StringDeserializer_tc_deserCompositeWhitespace_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_StringDeserializer_tc_deserCompositeWhitespace(void *args, void *result);
        corto_function(test_StringDeserializer_tc_deserCompositeWhitespace_o)->impl = (corto_word)__test_StringDeserializer_tc_deserCompositeWhitespace;
        if (corto_define(test_StringDeserializer_tc_deserCompositeWhitespace_o)) {
            corto_error("test_load: failed to define '/test/StringDeserializer/tc_deserCompositeWhitespace()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/StringDeserializer/tc_deserExisting() */
    test_StringDeserializer_tc_deserExisting_o = corto_declareChild(test_StringDeserializer_o, "tc_deserExisting()", test_Case_o);
    if (!test_StringDeserializer_tc_deserExisting_o) {
        corto_error("test_load: failed to declare '/test/StringDeserializer/tc_deserExisting()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/StringDeserializer/tc_deserExisting() */
    if (!corto_checkState(test_StringDeserializer_tc_deserExisting_o, CORTO_DEFINED)) {
        corto_function(test_StringDeserializer_tc_deserExisting_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_StringDeserializer_tc_deserExisting_o)->returnsReference = FALSE;
        corto_method(test_StringDeserializer_tc_deserExisting_o)->_virtual = FALSE;
        
        /* Bind /test/StringDeserializer/tc_deserExisting() with C-function */
        corto_function(test_StringDeserializer_tc_deserExisting_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_StringDeserializer_tc_deserExisting(void *args, void *result);
        corto_function(test_StringDeserializer_tc_deserExisting_o)->impl = (corto_word)__test_StringDeserializer_tc_deserExisting;
        if (corto_define(test_StringDeserializer_tc_deserExisting_o)) {
            corto_error("test_load: failed to define '/test/StringDeserializer/tc_deserExisting()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/StringDeserializer/tc_deserExisting_w_scopedType() */
    test_StringDeserializer_tc_deserExisting_w_scopedType_o = corto_declareChild(test_StringDeserializer_o, "tc_deserExisting_w_scopedType()", test_Case_o);
    if (!test_StringDeserializer_tc_deserExisting_w_scopedType_o) {
        corto_error("test_load: failed to declare '/test/StringDeserializer/tc_deserExisting_w_scopedType()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/StringDeserializer/tc_deserExisting_w_scopedType() */
    if (!corto_checkState(test_StringDeserializer_tc_deserExisting_w_scopedType_o, CORTO_DEFINED)) {
        corto_function(test_StringDeserializer_tc_deserExisting_w_scopedType_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_StringDeserializer_tc_deserExisting_w_scopedType_o)->returnsReference = FALSE;
        corto_method(test_StringDeserializer_tc_deserExisting_w_scopedType_o)->_virtual = FALSE;
        
        /* Bind /test/StringDeserializer/tc_deserExisting_w_scopedType() with C-function */
        corto_function(test_StringDeserializer_tc_deserExisting_w_scopedType_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_StringDeserializer_tc_deserExisting_w_scopedType(void *args, void *result);
        corto_function(test_StringDeserializer_tc_deserExisting_w_scopedType_o)->impl = (corto_word)__test_StringDeserializer_tc_deserExisting_w_scopedType;
        if (corto_define(test_StringDeserializer_tc_deserExisting_w_scopedType_o)) {
            corto_error("test_load: failed to define '/test/StringDeserializer/tc_deserExisting_w_scopedType()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/StringDeserializer/tc_deserExisting_w_type() */
    test_StringDeserializer_tc_deserExisting_w_type_o = corto_declareChild(test_StringDeserializer_o, "tc_deserExisting_w_type()", test_Case_o);
    if (!test_StringDeserializer_tc_deserExisting_w_type_o) {
        corto_error("test_load: failed to declare '/test/StringDeserializer/tc_deserExisting_w_type()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/StringDeserializer/tc_deserExisting_w_type() */
    if (!corto_checkState(test_StringDeserializer_tc_deserExisting_w_type_o, CORTO_DEFINED)) {
        corto_function(test_StringDeserializer_tc_deserExisting_w_type_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_StringDeserializer_tc_deserExisting_w_type_o)->returnsReference = FALSE;
        corto_method(test_StringDeserializer_tc_deserExisting_w_type_o)->_virtual = FALSE;
        
        /* Bind /test/StringDeserializer/tc_deserExisting_w_type() with C-function */
        corto_function(test_StringDeserializer_tc_deserExisting_w_type_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_StringDeserializer_tc_deserExisting_w_type(void *args, void *result);
        corto_function(test_StringDeserializer_tc_deserExisting_w_type_o)->impl = (corto_word)__test_StringDeserializer_tc_deserExisting_w_type;
        if (corto_define(test_StringDeserializer_tc_deserExisting_w_type_o)) {
            corto_error("test_load: failed to define '/test/StringDeserializer/tc_deserExisting_w_type()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/StringDeserializer/tc_deserInheritance() */
    test_StringDeserializer_tc_deserInheritance_o = corto_declareChild(test_StringDeserializer_o, "tc_deserInheritance()", test_Case_o);
    if (!test_StringDeserializer_tc_deserInheritance_o) {
        corto_error("test_load: failed to declare '/test/StringDeserializer/tc_deserInheritance()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/StringDeserializer/tc_deserInheritance() */
    if (!corto_checkState(test_StringDeserializer_tc_deserInheritance_o, CORTO_DEFINED)) {
        corto_function(test_StringDeserializer_tc_deserInheritance_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_StringDeserializer_tc_deserInheritance_o)->returnsReference = FALSE;
        corto_method(test_StringDeserializer_tc_deserInheritance_o)->_virtual = FALSE;
        
        /* Bind /test/StringDeserializer/tc_deserInheritance() with C-function */
        corto_function(test_StringDeserializer_tc_deserInheritance_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_StringDeserializer_tc_deserInheritance(void *args, void *result);
        corto_function(test_StringDeserializer_tc_deserInheritance_o)->impl = (corto_word)__test_StringDeserializer_tc_deserInheritance;
        if (corto_define(test_StringDeserializer_tc_deserInheritance_o)) {
            corto_error("test_load: failed to define '/test/StringDeserializer/tc_deserInheritance()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/StringDeserializer/tc_deserInheritanceMembers() */
    test_StringDeserializer_tc_deserInheritanceMembers_o = corto_declareChild(test_StringDeserializer_o, "tc_deserInheritanceMembers()", test_Case_o);
    if (!test_StringDeserializer_tc_deserInheritanceMembers_o) {
        corto_error("test_load: failed to declare '/test/StringDeserializer/tc_deserInheritanceMembers()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/StringDeserializer/tc_deserInheritanceMembers() */
    if (!corto_checkState(test_StringDeserializer_tc_deserInheritanceMembers_o, CORTO_DEFINED)) {
        corto_function(test_StringDeserializer_tc_deserInheritanceMembers_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_StringDeserializer_tc_deserInheritanceMembers_o)->returnsReference = FALSE;
        corto_method(test_StringDeserializer_tc_deserInheritanceMembers_o)->_virtual = FALSE;
        
        /* Bind /test/StringDeserializer/tc_deserInheritanceMembers() with C-function */
        corto_function(test_StringDeserializer_tc_deserInheritanceMembers_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_StringDeserializer_tc_deserInheritanceMembers(void *args, void *result);
        corto_function(test_StringDeserializer_tc_deserInheritanceMembers_o)->impl = (corto_word)__test_StringDeserializer_tc_deserInheritanceMembers;
        if (corto_define(test_StringDeserializer_tc_deserInheritanceMembers_o)) {
            corto_error("test_load: failed to define '/test/StringDeserializer/tc_deserInheritanceMembers()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/StringDeserializer/tc_deserInheritanceMixed() */
    test_StringDeserializer_tc_deserInheritanceMixed_o = corto_declareChild(test_StringDeserializer_o, "tc_deserInheritanceMixed()", test_Case_o);
    if (!test_StringDeserializer_tc_deserInheritanceMixed_o) {
        corto_error("test_load: failed to declare '/test/StringDeserializer/tc_deserInheritanceMixed()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/StringDeserializer/tc_deserInheritanceMixed() */
    if (!corto_checkState(test_StringDeserializer_tc_deserInheritanceMixed_o, CORTO_DEFINED)) {
        corto_function(test_StringDeserializer_tc_deserInheritanceMixed_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_StringDeserializer_tc_deserInheritanceMixed_o)->returnsReference = FALSE;
        corto_method(test_StringDeserializer_tc_deserInheritanceMixed_o)->_virtual = FALSE;
        
        /* Bind /test/StringDeserializer/tc_deserInheritanceMixed() with C-function */
        corto_function(test_StringDeserializer_tc_deserInheritanceMixed_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_StringDeserializer_tc_deserInheritanceMixed(void *args, void *result);
        corto_function(test_StringDeserializer_tc_deserInheritanceMixed_o)->impl = (corto_word)__test_StringDeserializer_tc_deserInheritanceMixed;
        if (corto_define(test_StringDeserializer_tc_deserInheritanceMixed_o)) {
            corto_error("test_load: failed to define '/test/StringDeserializer/tc_deserInheritanceMixed()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/StringDeserializer/tc_deserInt16() */
    test_StringDeserializer_tc_deserInt16_o = corto_declareChild(test_StringDeserializer_o, "tc_deserInt16()", test_Case_o);
    if (!test_StringDeserializer_tc_deserInt16_o) {
        corto_error("test_load: failed to declare '/test/StringDeserializer/tc_deserInt16()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/StringDeserializer/tc_deserInt16() */
    if (!corto_checkState(test_StringDeserializer_tc_deserInt16_o, CORTO_DEFINED)) {
        corto_function(test_StringDeserializer_tc_deserInt16_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_StringDeserializer_tc_deserInt16_o)->returnsReference = FALSE;
        corto_method(test_StringDeserializer_tc_deserInt16_o)->_virtual = FALSE;
        
        /* Bind /test/StringDeserializer/tc_deserInt16() with C-function */
        corto_function(test_StringDeserializer_tc_deserInt16_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_StringDeserializer_tc_deserInt16(void *args, void *result);
        corto_function(test_StringDeserializer_tc_deserInt16_o)->impl = (corto_word)__test_StringDeserializer_tc_deserInt16;
        if (corto_define(test_StringDeserializer_tc_deserInt16_o)) {
            corto_error("test_load: failed to define '/test/StringDeserializer/tc_deserInt16()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/StringDeserializer/tc_deserInt16Minus() */
    test_StringDeserializer_tc_deserInt16Minus_o = corto_declareChild(test_StringDeserializer_o, "tc_deserInt16Minus()", test_Case_o);
    if (!test_StringDeserializer_tc_deserInt16Minus_o) {
        corto_error("test_load: failed to declare '/test/StringDeserializer/tc_deserInt16Minus()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/StringDeserializer/tc_deserInt16Minus() */
    if (!corto_checkState(test_StringDeserializer_tc_deserInt16Minus_o, CORTO_DEFINED)) {
        corto_function(test_StringDeserializer_tc_deserInt16Minus_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_StringDeserializer_tc_deserInt16Minus_o)->returnsReference = FALSE;
        corto_method(test_StringDeserializer_tc_deserInt16Minus_o)->_virtual = FALSE;
        
        /* Bind /test/StringDeserializer/tc_deserInt16Minus() with C-function */
        corto_function(test_StringDeserializer_tc_deserInt16Minus_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_StringDeserializer_tc_deserInt16Minus(void *args, void *result);
        corto_function(test_StringDeserializer_tc_deserInt16Minus_o)->impl = (corto_word)__test_StringDeserializer_tc_deserInt16Minus;
        if (corto_define(test_StringDeserializer_tc_deserInt16Minus_o)) {
            corto_error("test_load: failed to define '/test/StringDeserializer/tc_deserInt16Minus()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/StringDeserializer/tc_deserInt16Overflow() */
    test_StringDeserializer_tc_deserInt16Overflow_o = corto_declareChild(test_StringDeserializer_o, "tc_deserInt16Overflow()", test_Case_o);
    if (!test_StringDeserializer_tc_deserInt16Overflow_o) {
        corto_error("test_load: failed to declare '/test/StringDeserializer/tc_deserInt16Overflow()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/StringDeserializer/tc_deserInt16Overflow() */
    if (!corto_checkState(test_StringDeserializer_tc_deserInt16Overflow_o, CORTO_DEFINED)) {
        corto_function(test_StringDeserializer_tc_deserInt16Overflow_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_StringDeserializer_tc_deserInt16Overflow_o)->returnsReference = FALSE;
        corto_method(test_StringDeserializer_tc_deserInt16Overflow_o)->_virtual = FALSE;
        
        /* Bind /test/StringDeserializer/tc_deserInt16Overflow() with C-function */
        corto_function(test_StringDeserializer_tc_deserInt16Overflow_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_StringDeserializer_tc_deserInt16Overflow(void *args, void *result);
        corto_function(test_StringDeserializer_tc_deserInt16Overflow_o)->impl = (corto_word)__test_StringDeserializer_tc_deserInt16Overflow;
        if (corto_define(test_StringDeserializer_tc_deserInt16Overflow_o)) {
            corto_error("test_load: failed to define '/test/StringDeserializer/tc_deserInt16Overflow()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/StringDeserializer/tc_deserInt32() */
    test_StringDeserializer_tc_deserInt32_o = corto_declareChild(test_StringDeserializer_o, "tc_deserInt32()", test_Case_o);
    if (!test_StringDeserializer_tc_deserInt32_o) {
        corto_error("test_load: failed to declare '/test/StringDeserializer/tc_deserInt32()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/StringDeserializer/tc_deserInt32() */
    if (!corto_checkState(test_StringDeserializer_tc_deserInt32_o, CORTO_DEFINED)) {
        corto_function(test_StringDeserializer_tc_deserInt32_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_StringDeserializer_tc_deserInt32_o)->returnsReference = FALSE;
        corto_method(test_StringDeserializer_tc_deserInt32_o)->_virtual = FALSE;
        
        /* Bind /test/StringDeserializer/tc_deserInt32() with C-function */
        corto_function(test_StringDeserializer_tc_deserInt32_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_StringDeserializer_tc_deserInt32(void *args, void *result);
        corto_function(test_StringDeserializer_tc_deserInt32_o)->impl = (corto_word)__test_StringDeserializer_tc_deserInt32;
        if (corto_define(test_StringDeserializer_tc_deserInt32_o)) {
            corto_error("test_load: failed to define '/test/StringDeserializer/tc_deserInt32()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/StringDeserializer/tc_deserInt32Minus() */
    test_StringDeserializer_tc_deserInt32Minus_o = corto_declareChild(test_StringDeserializer_o, "tc_deserInt32Minus()", test_Case_o);
    if (!test_StringDeserializer_tc_deserInt32Minus_o) {
        corto_error("test_load: failed to declare '/test/StringDeserializer/tc_deserInt32Minus()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/StringDeserializer/tc_deserInt32Minus() */
    if (!corto_checkState(test_StringDeserializer_tc_deserInt32Minus_o, CORTO_DEFINED)) {
        corto_function(test_StringDeserializer_tc_deserInt32Minus_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_StringDeserializer_tc_deserInt32Minus_o)->returnsReference = FALSE;
        corto_method(test_StringDeserializer_tc_deserInt32Minus_o)->_virtual = FALSE;
        
        /* Bind /test/StringDeserializer/tc_deserInt32Minus() with C-function */
        corto_function(test_StringDeserializer_tc_deserInt32Minus_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_StringDeserializer_tc_deserInt32Minus(void *args, void *result);
        corto_function(test_StringDeserializer_tc_deserInt32Minus_o)->impl = (corto_word)__test_StringDeserializer_tc_deserInt32Minus;
        if (corto_define(test_StringDeserializer_tc_deserInt32Minus_o)) {
            corto_error("test_load: failed to define '/test/StringDeserializer/tc_deserInt32Minus()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/StringDeserializer/tc_deserInt32Overflow() */
    test_StringDeserializer_tc_deserInt32Overflow_o = corto_declareChild(test_StringDeserializer_o, "tc_deserInt32Overflow()", test_Case_o);
    if (!test_StringDeserializer_tc_deserInt32Overflow_o) {
        corto_error("test_load: failed to declare '/test/StringDeserializer/tc_deserInt32Overflow()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/StringDeserializer/tc_deserInt32Overflow() */
    if (!corto_checkState(test_StringDeserializer_tc_deserInt32Overflow_o, CORTO_DEFINED)) {
        corto_function(test_StringDeserializer_tc_deserInt32Overflow_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_StringDeserializer_tc_deserInt32Overflow_o)->returnsReference = FALSE;
        corto_method(test_StringDeserializer_tc_deserInt32Overflow_o)->_virtual = FALSE;
        
        /* Bind /test/StringDeserializer/tc_deserInt32Overflow() with C-function */
        corto_function(test_StringDeserializer_tc_deserInt32Overflow_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_StringDeserializer_tc_deserInt32Overflow(void *args, void *result);
        corto_function(test_StringDeserializer_tc_deserInt32Overflow_o)->impl = (corto_word)__test_StringDeserializer_tc_deserInt32Overflow;
        if (corto_define(test_StringDeserializer_tc_deserInt32Overflow_o)) {
            corto_error("test_load: failed to define '/test/StringDeserializer/tc_deserInt32Overflow()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/StringDeserializer/tc_deserInt64() */
    test_StringDeserializer_tc_deserInt64_o = corto_declareChild(test_StringDeserializer_o, "tc_deserInt64()", test_Case_o);
    if (!test_StringDeserializer_tc_deserInt64_o) {
        corto_error("test_load: failed to declare '/test/StringDeserializer/tc_deserInt64()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/StringDeserializer/tc_deserInt64() */
    if (!corto_checkState(test_StringDeserializer_tc_deserInt64_o, CORTO_DEFINED)) {
        corto_function(test_StringDeserializer_tc_deserInt64_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_StringDeserializer_tc_deserInt64_o)->returnsReference = FALSE;
        corto_method(test_StringDeserializer_tc_deserInt64_o)->_virtual = FALSE;
        
        /* Bind /test/StringDeserializer/tc_deserInt64() with C-function */
        corto_function(test_StringDeserializer_tc_deserInt64_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_StringDeserializer_tc_deserInt64(void *args, void *result);
        corto_function(test_StringDeserializer_tc_deserInt64_o)->impl = (corto_word)__test_StringDeserializer_tc_deserInt64;
        if (corto_define(test_StringDeserializer_tc_deserInt64_o)) {
            corto_error("test_load: failed to define '/test/StringDeserializer/tc_deserInt64()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/StringDeserializer/tc_deserInt64Minus() */
    test_StringDeserializer_tc_deserInt64Minus_o = corto_declareChild(test_StringDeserializer_o, "tc_deserInt64Minus()", test_Case_o);
    if (!test_StringDeserializer_tc_deserInt64Minus_o) {
        corto_error("test_load: failed to declare '/test/StringDeserializer/tc_deserInt64Minus()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/StringDeserializer/tc_deserInt64Minus() */
    if (!corto_checkState(test_StringDeserializer_tc_deserInt64Minus_o, CORTO_DEFINED)) {
        corto_function(test_StringDeserializer_tc_deserInt64Minus_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_StringDeserializer_tc_deserInt64Minus_o)->returnsReference = FALSE;
        corto_method(test_StringDeserializer_tc_deserInt64Minus_o)->_virtual = FALSE;
        
        /* Bind /test/StringDeserializer/tc_deserInt64Minus() with C-function */
        corto_function(test_StringDeserializer_tc_deserInt64Minus_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_StringDeserializer_tc_deserInt64Minus(void *args, void *result);
        corto_function(test_StringDeserializer_tc_deserInt64Minus_o)->impl = (corto_word)__test_StringDeserializer_tc_deserInt64Minus;
        if (corto_define(test_StringDeserializer_tc_deserInt64Minus_o)) {
            corto_error("test_load: failed to define '/test/StringDeserializer/tc_deserInt64Minus()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/StringDeserializer/tc_deserInt8() */
    test_StringDeserializer_tc_deserInt8_o = corto_declareChild(test_StringDeserializer_o, "tc_deserInt8()", test_Case_o);
    if (!test_StringDeserializer_tc_deserInt8_o) {
        corto_error("test_load: failed to declare '/test/StringDeserializer/tc_deserInt8()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/StringDeserializer/tc_deserInt8() */
    if (!corto_checkState(test_StringDeserializer_tc_deserInt8_o, CORTO_DEFINED)) {
        corto_function(test_StringDeserializer_tc_deserInt8_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_StringDeserializer_tc_deserInt8_o)->returnsReference = FALSE;
        corto_method(test_StringDeserializer_tc_deserInt8_o)->_virtual = FALSE;
        
        /* Bind /test/StringDeserializer/tc_deserInt8() with C-function */
        corto_function(test_StringDeserializer_tc_deserInt8_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_StringDeserializer_tc_deserInt8(void *args, void *result);
        corto_function(test_StringDeserializer_tc_deserInt8_o)->impl = (corto_word)__test_StringDeserializer_tc_deserInt8;
        if (corto_define(test_StringDeserializer_tc_deserInt8_o)) {
            corto_error("test_load: failed to define '/test/StringDeserializer/tc_deserInt8()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/StringDeserializer/tc_deserInt8Minus() */
    test_StringDeserializer_tc_deserInt8Minus_o = corto_declareChild(test_StringDeserializer_o, "tc_deserInt8Minus()", test_Case_o);
    if (!test_StringDeserializer_tc_deserInt8Minus_o) {
        corto_error("test_load: failed to declare '/test/StringDeserializer/tc_deserInt8Minus()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/StringDeserializer/tc_deserInt8Minus() */
    if (!corto_checkState(test_StringDeserializer_tc_deserInt8Minus_o, CORTO_DEFINED)) {
        corto_function(test_StringDeserializer_tc_deserInt8Minus_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_StringDeserializer_tc_deserInt8Minus_o)->returnsReference = FALSE;
        corto_method(test_StringDeserializer_tc_deserInt8Minus_o)->_virtual = FALSE;
        
        /* Bind /test/StringDeserializer/tc_deserInt8Minus() with C-function */
        corto_function(test_StringDeserializer_tc_deserInt8Minus_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_StringDeserializer_tc_deserInt8Minus(void *args, void *result);
        corto_function(test_StringDeserializer_tc_deserInt8Minus_o)->impl = (corto_word)__test_StringDeserializer_tc_deserInt8Minus;
        if (corto_define(test_StringDeserializer_tc_deserInt8Minus_o)) {
            corto_error("test_load: failed to define '/test/StringDeserializer/tc_deserInt8Minus()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/StringDeserializer/tc_deserInt8Overflow() */
    test_StringDeserializer_tc_deserInt8Overflow_o = corto_declareChild(test_StringDeserializer_o, "tc_deserInt8Overflow()", test_Case_o);
    if (!test_StringDeserializer_tc_deserInt8Overflow_o) {
        corto_error("test_load: failed to declare '/test/StringDeserializer/tc_deserInt8Overflow()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/StringDeserializer/tc_deserInt8Overflow() */
    if (!corto_checkState(test_StringDeserializer_tc_deserInt8Overflow_o, CORTO_DEFINED)) {
        corto_function(test_StringDeserializer_tc_deserInt8Overflow_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_StringDeserializer_tc_deserInt8Overflow_o)->returnsReference = FALSE;
        corto_method(test_StringDeserializer_tc_deserInt8Overflow_o)->_virtual = FALSE;
        
        /* Bind /test/StringDeserializer/tc_deserInt8Overflow() with C-function */
        corto_function(test_StringDeserializer_tc_deserInt8Overflow_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_StringDeserializer_tc_deserInt8Overflow(void *args, void *result);
        corto_function(test_StringDeserializer_tc_deserInt8Overflow_o)->impl = (corto_word)__test_StringDeserializer_tc_deserInt8Overflow;
        if (corto_define(test_StringDeserializer_tc_deserInt8Overflow_o)) {
            corto_error("test_load: failed to define '/test/StringDeserializer/tc_deserInt8Overflow()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/StringDeserializer/tc_deserString() */
    test_StringDeserializer_tc_deserString_o = corto_declareChild(test_StringDeserializer_o, "tc_deserString()", test_Case_o);
    if (!test_StringDeserializer_tc_deserString_o) {
        corto_error("test_load: failed to declare '/test/StringDeserializer/tc_deserString()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/StringDeserializer/tc_deserString() */
    if (!corto_checkState(test_StringDeserializer_tc_deserString_o, CORTO_DEFINED)) {
        corto_function(test_StringDeserializer_tc_deserString_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_StringDeserializer_tc_deserString_o)->returnsReference = FALSE;
        corto_method(test_StringDeserializer_tc_deserString_o)->_virtual = FALSE;
        
        /* Bind /test/StringDeserializer/tc_deserString() with C-function */
        corto_function(test_StringDeserializer_tc_deserString_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_StringDeserializer_tc_deserString(void *args, void *result);
        corto_function(test_StringDeserializer_tc_deserString_o)->impl = (corto_word)__test_StringDeserializer_tc_deserString;
        if (corto_define(test_StringDeserializer_tc_deserString_o)) {
            corto_error("test_load: failed to define '/test/StringDeserializer/tc_deserString()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/StringDeserializer/tc_deserStringEscape() */
    test_StringDeserializer_tc_deserStringEscape_o = corto_declareChild(test_StringDeserializer_o, "tc_deserStringEscape()", test_Case_o);
    if (!test_StringDeserializer_tc_deserStringEscape_o) {
        corto_error("test_load: failed to declare '/test/StringDeserializer/tc_deserStringEscape()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/StringDeserializer/tc_deserStringEscape() */
    if (!corto_checkState(test_StringDeserializer_tc_deserStringEscape_o, CORTO_DEFINED)) {
        corto_function(test_StringDeserializer_tc_deserStringEscape_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_StringDeserializer_tc_deserStringEscape_o)->returnsReference = FALSE;
        corto_method(test_StringDeserializer_tc_deserStringEscape_o)->_virtual = FALSE;
        
        /* Bind /test/StringDeserializer/tc_deserStringEscape() with C-function */
        corto_function(test_StringDeserializer_tc_deserStringEscape_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_StringDeserializer_tc_deserStringEscape(void *args, void *result);
        corto_function(test_StringDeserializer_tc_deserStringEscape_o)->impl = (corto_word)__test_StringDeserializer_tc_deserStringEscape;
        if (corto_define(test_StringDeserializer_tc_deserStringEscape_o)) {
            corto_error("test_load: failed to define '/test/StringDeserializer/tc_deserStringEscape()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/StringDeserializer/tc_deserStringQuotes() */
    test_StringDeserializer_tc_deserStringQuotes_o = corto_declareChild(test_StringDeserializer_o, "tc_deserStringQuotes()", test_Case_o);
    if (!test_StringDeserializer_tc_deserStringQuotes_o) {
        corto_error("test_load: failed to declare '/test/StringDeserializer/tc_deserStringQuotes()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/StringDeserializer/tc_deserStringQuotes() */
    if (!corto_checkState(test_StringDeserializer_tc_deserStringQuotes_o, CORTO_DEFINED)) {
        corto_function(test_StringDeserializer_tc_deserStringQuotes_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_StringDeserializer_tc_deserStringQuotes_o)->returnsReference = FALSE;
        corto_method(test_StringDeserializer_tc_deserStringQuotes_o)->_virtual = FALSE;
        
        /* Bind /test/StringDeserializer/tc_deserStringQuotes() with C-function */
        corto_function(test_StringDeserializer_tc_deserStringQuotes_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_StringDeserializer_tc_deserStringQuotes(void *args, void *result);
        corto_function(test_StringDeserializer_tc_deserStringQuotes_o)->impl = (corto_word)__test_StringDeserializer_tc_deserStringQuotes;
        if (corto_define(test_StringDeserializer_tc_deserStringQuotes_o)) {
            corto_error("test_load: failed to define '/test/StringDeserializer/tc_deserStringQuotes()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/StringDeserializer/tc_deserStringQuotesWhitespaces() */
    test_StringDeserializer_tc_deserStringQuotesWhitespaces_o = corto_declareChild(test_StringDeserializer_o, "tc_deserStringQuotesWhitespaces()", test_Case_o);
    if (!test_StringDeserializer_tc_deserStringQuotesWhitespaces_o) {
        corto_error("test_load: failed to declare '/test/StringDeserializer/tc_deserStringQuotesWhitespaces()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/StringDeserializer/tc_deserStringQuotesWhitespaces() */
    if (!corto_checkState(test_StringDeserializer_tc_deserStringQuotesWhitespaces_o, CORTO_DEFINED)) {
        corto_function(test_StringDeserializer_tc_deserStringQuotesWhitespaces_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_StringDeserializer_tc_deserStringQuotesWhitespaces_o)->returnsReference = FALSE;
        corto_method(test_StringDeserializer_tc_deserStringQuotesWhitespaces_o)->_virtual = FALSE;
        
        /* Bind /test/StringDeserializer/tc_deserStringQuotesWhitespaces() with C-function */
        corto_function(test_StringDeserializer_tc_deserStringQuotesWhitespaces_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_StringDeserializer_tc_deserStringQuotesWhitespaces(void *args, void *result);
        corto_function(test_StringDeserializer_tc_deserStringQuotesWhitespaces_o)->impl = (corto_word)__test_StringDeserializer_tc_deserStringQuotesWhitespaces;
        if (corto_define(test_StringDeserializer_tc_deserStringQuotesWhitespaces_o)) {
            corto_error("test_load: failed to define '/test/StringDeserializer/tc_deserStringQuotesWhitespaces()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/StringDeserializer/tc_deserStringWhitespace() */
    test_StringDeserializer_tc_deserStringWhitespace_o = corto_declareChild(test_StringDeserializer_o, "tc_deserStringWhitespace()", test_Case_o);
    if (!test_StringDeserializer_tc_deserStringWhitespace_o) {
        corto_error("test_load: failed to declare '/test/StringDeserializer/tc_deserStringWhitespace()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/StringDeserializer/tc_deserStringWhitespace() */
    if (!corto_checkState(test_StringDeserializer_tc_deserStringWhitespace_o, CORTO_DEFINED)) {
        corto_function(test_StringDeserializer_tc_deserStringWhitespace_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_StringDeserializer_tc_deserStringWhitespace_o)->returnsReference = FALSE;
        corto_method(test_StringDeserializer_tc_deserStringWhitespace_o)->_virtual = FALSE;
        
        /* Bind /test/StringDeserializer/tc_deserStringWhitespace() with C-function */
        corto_function(test_StringDeserializer_tc_deserStringWhitespace_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_StringDeserializer_tc_deserStringWhitespace(void *args, void *result);
        corto_function(test_StringDeserializer_tc_deserStringWhitespace_o)->impl = (corto_word)__test_StringDeserializer_tc_deserStringWhitespace;
        if (corto_define(test_StringDeserializer_tc_deserStringWhitespace_o)) {
            corto_error("test_load: failed to define '/test/StringDeserializer/tc_deserStringWhitespace()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/StringDeserializer/tc_deserStringWhitespaceTrailing() */
    test_StringDeserializer_tc_deserStringWhitespaceTrailing_o = corto_declareChild(test_StringDeserializer_o, "tc_deserStringWhitespaceTrailing()", test_Case_o);
    if (!test_StringDeserializer_tc_deserStringWhitespaceTrailing_o) {
        corto_error("test_load: failed to declare '/test/StringDeserializer/tc_deserStringWhitespaceTrailing()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/StringDeserializer/tc_deserStringWhitespaceTrailing() */
    if (!corto_checkState(test_StringDeserializer_tc_deserStringWhitespaceTrailing_o, CORTO_DEFINED)) {
        corto_function(test_StringDeserializer_tc_deserStringWhitespaceTrailing_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_StringDeserializer_tc_deserStringWhitespaceTrailing_o)->returnsReference = FALSE;
        corto_method(test_StringDeserializer_tc_deserStringWhitespaceTrailing_o)->_virtual = FALSE;
        
        /* Bind /test/StringDeserializer/tc_deserStringWhitespaceTrailing() with C-function */
        corto_function(test_StringDeserializer_tc_deserStringWhitespaceTrailing_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_StringDeserializer_tc_deserStringWhitespaceTrailing(void *args, void *result);
        corto_function(test_StringDeserializer_tc_deserStringWhitespaceTrailing_o)->impl = (corto_word)__test_StringDeserializer_tc_deserStringWhitespaceTrailing;
        if (corto_define(test_StringDeserializer_tc_deserStringWhitespaceTrailing_o)) {
            corto_error("test_load: failed to define '/test/StringDeserializer/tc_deserStringWhitespaceTrailing()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/StringDeserializer/tc_deserStringWhitespaceTrailingNoType() */
    test_StringDeserializer_tc_deserStringWhitespaceTrailingNoType_o = corto_declareChild(test_StringDeserializer_o, "tc_deserStringWhitespaceTrailingNoType()", test_Case_o);
    if (!test_StringDeserializer_tc_deserStringWhitespaceTrailingNoType_o) {
        corto_error("test_load: failed to declare '/test/StringDeserializer/tc_deserStringWhitespaceTrailingNoType()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/StringDeserializer/tc_deserStringWhitespaceTrailingNoType() */
    if (!corto_checkState(test_StringDeserializer_tc_deserStringWhitespaceTrailingNoType_o, CORTO_DEFINED)) {
        corto_function(test_StringDeserializer_tc_deserStringWhitespaceTrailingNoType_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_StringDeserializer_tc_deserStringWhitespaceTrailingNoType_o)->returnsReference = FALSE;
        corto_method(test_StringDeserializer_tc_deserStringWhitespaceTrailingNoType_o)->_virtual = FALSE;
        
        /* Bind /test/StringDeserializer/tc_deserStringWhitespaceTrailingNoType() with C-function */
        corto_function(test_StringDeserializer_tc_deserStringWhitespaceTrailingNoType_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_StringDeserializer_tc_deserStringWhitespaceTrailingNoType(void *args, void *result);
        corto_function(test_StringDeserializer_tc_deserStringWhitespaceTrailingNoType_o)->impl = (corto_word)__test_StringDeserializer_tc_deserStringWhitespaceTrailingNoType;
        if (corto_define(test_StringDeserializer_tc_deserStringWhitespaceTrailingNoType_o)) {
            corto_error("test_load: failed to define '/test/StringDeserializer/tc_deserStringWhitespaceTrailingNoType()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/StringDeserializer/tc_deserUint16() */
    test_StringDeserializer_tc_deserUint16_o = corto_declareChild(test_StringDeserializer_o, "tc_deserUint16()", test_Case_o);
    if (!test_StringDeserializer_tc_deserUint16_o) {
        corto_error("test_load: failed to declare '/test/StringDeserializer/tc_deserUint16()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/StringDeserializer/tc_deserUint16() */
    if (!corto_checkState(test_StringDeserializer_tc_deserUint16_o, CORTO_DEFINED)) {
        corto_function(test_StringDeserializer_tc_deserUint16_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_StringDeserializer_tc_deserUint16_o)->returnsReference = FALSE;
        corto_method(test_StringDeserializer_tc_deserUint16_o)->_virtual = FALSE;
        
        /* Bind /test/StringDeserializer/tc_deserUint16() with C-function */
        corto_function(test_StringDeserializer_tc_deserUint16_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_StringDeserializer_tc_deserUint16(void *args, void *result);
        corto_function(test_StringDeserializer_tc_deserUint16_o)->impl = (corto_word)__test_StringDeserializer_tc_deserUint16;
        if (corto_define(test_StringDeserializer_tc_deserUint16_o)) {
            corto_error("test_load: failed to define '/test/StringDeserializer/tc_deserUint16()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/StringDeserializer/tc_deserUint16Overflow() */
    test_StringDeserializer_tc_deserUint16Overflow_o = corto_declareChild(test_StringDeserializer_o, "tc_deserUint16Overflow()", test_Case_o);
    if (!test_StringDeserializer_tc_deserUint16Overflow_o) {
        corto_error("test_load: failed to declare '/test/StringDeserializer/tc_deserUint16Overflow()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/StringDeserializer/tc_deserUint16Overflow() */
    if (!corto_checkState(test_StringDeserializer_tc_deserUint16Overflow_o, CORTO_DEFINED)) {
        corto_function(test_StringDeserializer_tc_deserUint16Overflow_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_StringDeserializer_tc_deserUint16Overflow_o)->returnsReference = FALSE;
        corto_method(test_StringDeserializer_tc_deserUint16Overflow_o)->_virtual = FALSE;
        
        /* Bind /test/StringDeserializer/tc_deserUint16Overflow() with C-function */
        corto_function(test_StringDeserializer_tc_deserUint16Overflow_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_StringDeserializer_tc_deserUint16Overflow(void *args, void *result);
        corto_function(test_StringDeserializer_tc_deserUint16Overflow_o)->impl = (corto_word)__test_StringDeserializer_tc_deserUint16Overflow;
        if (corto_define(test_StringDeserializer_tc_deserUint16Overflow_o)) {
            corto_error("test_load: failed to define '/test/StringDeserializer/tc_deserUint16Overflow()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/StringDeserializer/tc_deserUint32() */
    test_StringDeserializer_tc_deserUint32_o = corto_declareChild(test_StringDeserializer_o, "tc_deserUint32()", test_Case_o);
    if (!test_StringDeserializer_tc_deserUint32_o) {
        corto_error("test_load: failed to declare '/test/StringDeserializer/tc_deserUint32()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/StringDeserializer/tc_deserUint32() */
    if (!corto_checkState(test_StringDeserializer_tc_deserUint32_o, CORTO_DEFINED)) {
        corto_function(test_StringDeserializer_tc_deserUint32_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_StringDeserializer_tc_deserUint32_o)->returnsReference = FALSE;
        corto_method(test_StringDeserializer_tc_deserUint32_o)->_virtual = FALSE;
        
        /* Bind /test/StringDeserializer/tc_deserUint32() with C-function */
        corto_function(test_StringDeserializer_tc_deserUint32_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_StringDeserializer_tc_deserUint32(void *args, void *result);
        corto_function(test_StringDeserializer_tc_deserUint32_o)->impl = (corto_word)__test_StringDeserializer_tc_deserUint32;
        if (corto_define(test_StringDeserializer_tc_deserUint32_o)) {
            corto_error("test_load: failed to define '/test/StringDeserializer/tc_deserUint32()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/StringDeserializer/tc_deserUint32Overflow() */
    test_StringDeserializer_tc_deserUint32Overflow_o = corto_declareChild(test_StringDeserializer_o, "tc_deserUint32Overflow()", test_Case_o);
    if (!test_StringDeserializer_tc_deserUint32Overflow_o) {
        corto_error("test_load: failed to declare '/test/StringDeserializer/tc_deserUint32Overflow()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/StringDeserializer/tc_deserUint32Overflow() */
    if (!corto_checkState(test_StringDeserializer_tc_deserUint32Overflow_o, CORTO_DEFINED)) {
        corto_function(test_StringDeserializer_tc_deserUint32Overflow_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_StringDeserializer_tc_deserUint32Overflow_o)->returnsReference = FALSE;
        corto_method(test_StringDeserializer_tc_deserUint32Overflow_o)->_virtual = FALSE;
        
        /* Bind /test/StringDeserializer/tc_deserUint32Overflow() with C-function */
        corto_function(test_StringDeserializer_tc_deserUint32Overflow_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_StringDeserializer_tc_deserUint32Overflow(void *args, void *result);
        corto_function(test_StringDeserializer_tc_deserUint32Overflow_o)->impl = (corto_word)__test_StringDeserializer_tc_deserUint32Overflow;
        if (corto_define(test_StringDeserializer_tc_deserUint32Overflow_o)) {
            corto_error("test_load: failed to define '/test/StringDeserializer/tc_deserUint32Overflow()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/StringDeserializer/tc_deserUint64() */
    test_StringDeserializer_tc_deserUint64_o = corto_declareChild(test_StringDeserializer_o, "tc_deserUint64()", test_Case_o);
    if (!test_StringDeserializer_tc_deserUint64_o) {
        corto_error("test_load: failed to declare '/test/StringDeserializer/tc_deserUint64()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/StringDeserializer/tc_deserUint64() */
    if (!corto_checkState(test_StringDeserializer_tc_deserUint64_o, CORTO_DEFINED)) {
        corto_function(test_StringDeserializer_tc_deserUint64_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_StringDeserializer_tc_deserUint64_o)->returnsReference = FALSE;
        corto_method(test_StringDeserializer_tc_deserUint64_o)->_virtual = FALSE;
        
        /* Bind /test/StringDeserializer/tc_deserUint64() with C-function */
        corto_function(test_StringDeserializer_tc_deserUint64_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_StringDeserializer_tc_deserUint64(void *args, void *result);
        corto_function(test_StringDeserializer_tc_deserUint64_o)->impl = (corto_word)__test_StringDeserializer_tc_deserUint64;
        if (corto_define(test_StringDeserializer_tc_deserUint64_o)) {
            corto_error("test_load: failed to define '/test/StringDeserializer/tc_deserUint64()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/StringDeserializer/tc_deserUint8() */
    test_StringDeserializer_tc_deserUint8_o = corto_declareChild(test_StringDeserializer_o, "tc_deserUint8()", test_Case_o);
    if (!test_StringDeserializer_tc_deserUint8_o) {
        corto_error("test_load: failed to declare '/test/StringDeserializer/tc_deserUint8()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/StringDeserializer/tc_deserUint8() */
    if (!corto_checkState(test_StringDeserializer_tc_deserUint8_o, CORTO_DEFINED)) {
        corto_function(test_StringDeserializer_tc_deserUint8_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_StringDeserializer_tc_deserUint8_o)->returnsReference = FALSE;
        corto_method(test_StringDeserializer_tc_deserUint8_o)->_virtual = FALSE;
        
        /* Bind /test/StringDeserializer/tc_deserUint8() with C-function */
        corto_function(test_StringDeserializer_tc_deserUint8_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_StringDeserializer_tc_deserUint8(void *args, void *result);
        corto_function(test_StringDeserializer_tc_deserUint8_o)->impl = (corto_word)__test_StringDeserializer_tc_deserUint8;
        if (corto_define(test_StringDeserializer_tc_deserUint8_o)) {
            corto_error("test_load: failed to define '/test/StringDeserializer/tc_deserUint8()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/StringDeserializer/tc_deserUint8Overflow() */
    test_StringDeserializer_tc_deserUint8Overflow_o = corto_declareChild(test_StringDeserializer_o, "tc_deserUint8Overflow()", test_Case_o);
    if (!test_StringDeserializer_tc_deserUint8Overflow_o) {
        corto_error("test_load: failed to declare '/test/StringDeserializer/tc_deserUint8Overflow()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/StringDeserializer/tc_deserUint8Overflow() */
    if (!corto_checkState(test_StringDeserializer_tc_deserUint8Overflow_o, CORTO_DEFINED)) {
        corto_function(test_StringDeserializer_tc_deserUint8Overflow_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_StringDeserializer_tc_deserUint8Overflow_o)->returnsReference = FALSE;
        corto_method(test_StringDeserializer_tc_deserUint8Overflow_o)->_virtual = FALSE;
        
        /* Bind /test/StringDeserializer/tc_deserUint8Overflow() with C-function */
        corto_function(test_StringDeserializer_tc_deserUint8Overflow_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_StringDeserializer_tc_deserUint8Overflow(void *args, void *result);
        corto_function(test_StringDeserializer_tc_deserUint8Overflow_o)->impl = (corto_word)__test_StringDeserializer_tc_deserUint8Overflow;
        if (corto_define(test_StringDeserializer_tc_deserUint8Overflow_o)) {
            corto_error("test_load: failed to define '/test/StringDeserializer/tc_deserUint8Overflow()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/StringDeserializer/tc_errExcessElements() */
    test_StringDeserializer_tc_errExcessElements_o = corto_declareChild(test_StringDeserializer_o, "tc_errExcessElements()", test_Case_o);
    if (!test_StringDeserializer_tc_errExcessElements_o) {
        corto_error("test_load: failed to declare '/test/StringDeserializer/tc_errExcessElements()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/StringDeserializer/tc_errExcessElements() */
    if (!corto_checkState(test_StringDeserializer_tc_errExcessElements_o, CORTO_DEFINED)) {
        corto_function(test_StringDeserializer_tc_errExcessElements_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_StringDeserializer_tc_errExcessElements_o)->returnsReference = FALSE;
        corto_method(test_StringDeserializer_tc_errExcessElements_o)->_virtual = FALSE;
        
        /* Bind /test/StringDeserializer/tc_errExcessElements() with C-function */
        corto_function(test_StringDeserializer_tc_errExcessElements_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_StringDeserializer_tc_errExcessElements(void *args, void *result);
        corto_function(test_StringDeserializer_tc_errExcessElements_o)->impl = (corto_word)__test_StringDeserializer_tc_errExcessElements;
        if (corto_define(test_StringDeserializer_tc_errExcessElements_o)) {
            corto_error("test_load: failed to define '/test/StringDeserializer/tc_errExcessElements()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/StringDeserializer/tc_errMissingType() */
    test_StringDeserializer_tc_errMissingType_o = corto_declareChild(test_StringDeserializer_o, "tc_errMissingType()", test_Case_o);
    if (!test_StringDeserializer_tc_errMissingType_o) {
        corto_error("test_load: failed to declare '/test/StringDeserializer/tc_errMissingType()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/StringDeserializer/tc_errMissingType() */
    if (!corto_checkState(test_StringDeserializer_tc_errMissingType_o, CORTO_DEFINED)) {
        corto_function(test_StringDeserializer_tc_errMissingType_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_StringDeserializer_tc_errMissingType_o)->returnsReference = FALSE;
        corto_method(test_StringDeserializer_tc_errMissingType_o)->_virtual = FALSE;
        
        /* Bind /test/StringDeserializer/tc_errMissingType() with C-function */
        corto_function(test_StringDeserializer_tc_errMissingType_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_StringDeserializer_tc_errMissingType(void *args, void *result);
        corto_function(test_StringDeserializer_tc_errMissingType_o)->impl = (corto_word)__test_StringDeserializer_tc_errMissingType;
        if (corto_define(test_StringDeserializer_tc_errMissingType_o)) {
            corto_error("test_load: failed to define '/test/StringDeserializer/tc_errMissingType()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/StringDeserializer/tc_errNotAType() */
    test_StringDeserializer_tc_errNotAType_o = corto_declareChild(test_StringDeserializer_o, "tc_errNotAType()", test_Case_o);
    if (!test_StringDeserializer_tc_errNotAType_o) {
        corto_error("test_load: failed to declare '/test/StringDeserializer/tc_errNotAType()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/StringDeserializer/tc_errNotAType() */
    if (!corto_checkState(test_StringDeserializer_tc_errNotAType_o, CORTO_DEFINED)) {
        corto_function(test_StringDeserializer_tc_errNotAType_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_StringDeserializer_tc_errNotAType_o)->returnsReference = FALSE;
        corto_method(test_StringDeserializer_tc_errNotAType_o)->_virtual = FALSE;
        
        /* Bind /test/StringDeserializer/tc_errNotAType() with C-function */
        corto_function(test_StringDeserializer_tc_errNotAType_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_StringDeserializer_tc_errNotAType(void *args, void *result);
        corto_function(test_StringDeserializer_tc_errNotAType_o)->impl = (corto_word)__test_StringDeserializer_tc_errNotAType;
        if (corto_define(test_StringDeserializer_tc_errNotAType_o)) {
            corto_error("test_load: failed to define '/test/StringDeserializer/tc_errNotAType()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/StringDeserializer/tc_errTypeMismatch() */
    test_StringDeserializer_tc_errTypeMismatch_o = corto_declareChild(test_StringDeserializer_o, "tc_errTypeMismatch()", test_Case_o);
    if (!test_StringDeserializer_tc_errTypeMismatch_o) {
        corto_error("test_load: failed to declare '/test/StringDeserializer/tc_errTypeMismatch()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/StringDeserializer/tc_errTypeMismatch() */
    if (!corto_checkState(test_StringDeserializer_tc_errTypeMismatch_o, CORTO_DEFINED)) {
        corto_function(test_StringDeserializer_tc_errTypeMismatch_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_StringDeserializer_tc_errTypeMismatch_o)->returnsReference = FALSE;
        corto_method(test_StringDeserializer_tc_errTypeMismatch_o)->_virtual = FALSE;
        
        /* Bind /test/StringDeserializer/tc_errTypeMismatch() with C-function */
        corto_function(test_StringDeserializer_tc_errTypeMismatch_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_StringDeserializer_tc_errTypeMismatch(void *args, void *result);
        corto_function(test_StringDeserializer_tc_errTypeMismatch_o)->impl = (corto_word)__test_StringDeserializer_tc_errTypeMismatch;
        if (corto_define(test_StringDeserializer_tc_errTypeMismatch_o)) {
            corto_error("test_load: failed to define '/test/StringDeserializer/tc_errTypeMismatch()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/StringDeserializer/tc_errUnresolvedMember() */
    test_StringDeserializer_tc_errUnresolvedMember_o = corto_declareChild(test_StringDeserializer_o, "tc_errUnresolvedMember()", test_Case_o);
    if (!test_StringDeserializer_tc_errUnresolvedMember_o) {
        corto_error("test_load: failed to declare '/test/StringDeserializer/tc_errUnresolvedMember()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/StringDeserializer/tc_errUnresolvedMember() */
    if (!corto_checkState(test_StringDeserializer_tc_errUnresolvedMember_o, CORTO_DEFINED)) {
        corto_function(test_StringDeserializer_tc_errUnresolvedMember_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_StringDeserializer_tc_errUnresolvedMember_o)->returnsReference = FALSE;
        corto_method(test_StringDeserializer_tc_errUnresolvedMember_o)->_virtual = FALSE;
        
        /* Bind /test/StringDeserializer/tc_errUnresolvedMember() with C-function */
        corto_function(test_StringDeserializer_tc_errUnresolvedMember_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_StringDeserializer_tc_errUnresolvedMember(void *args, void *result);
        corto_function(test_StringDeserializer_tc_errUnresolvedMember_o)->impl = (corto_word)__test_StringDeserializer_tc_errUnresolvedMember;
        if (corto_define(test_StringDeserializer_tc_errUnresolvedMember_o)) {
            corto_error("test_load: failed to define '/test/StringDeserializer/tc_errUnresolvedMember()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/StringDeserializer/tc_errUnresolvedType() */
    test_StringDeserializer_tc_errUnresolvedType_o = corto_declareChild(test_StringDeserializer_o, "tc_errUnresolvedType()", test_Case_o);
    if (!test_StringDeserializer_tc_errUnresolvedType_o) {
        corto_error("test_load: failed to declare '/test/StringDeserializer/tc_errUnresolvedType()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/StringDeserializer/tc_errUnresolvedType() */
    if (!corto_checkState(test_StringDeserializer_tc_errUnresolvedType_o, CORTO_DEFINED)) {
        corto_function(test_StringDeserializer_tc_errUnresolvedType_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_StringDeserializer_tc_errUnresolvedType_o)->returnsReference = FALSE;
        corto_method(test_StringDeserializer_tc_errUnresolvedType_o)->_virtual = FALSE;
        
        /* Bind /test/StringDeserializer/tc_errUnresolvedType() with C-function */
        corto_function(test_StringDeserializer_tc_errUnresolvedType_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_StringDeserializer_tc_errUnresolvedType(void *args, void *result);
        corto_function(test_StringDeserializer_tc_errUnresolvedType_o)->impl = (corto_word)__test_StringDeserializer_tc_errUnresolvedType;
        if (corto_define(test_StringDeserializer_tc_errUnresolvedType_o)) {
            corto_error("test_load: failed to define '/test/StringDeserializer/tc_errUnresolvedType()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/VoidParent */
    test_VoidParent_o = corto_declareChild(test_o, "VoidParent", corto_struct_o);
    if (!test_VoidParent_o) {
        corto_error("test_load: failed to declare '/test/VoidParent' (%s)", corto_lasterr());
        goto error;
    }

    /* Declare /test/VoidParent/Foo */
    test_VoidParent_Foo_o = corto_declareChild(test_VoidParent_o, "Foo", corto_member_o);
    if (!test_VoidParent_Foo_o) {
        corto_error("test_load: failed to declare '/test/VoidParent/Foo' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/VoidParent/Foo */
    if (!corto_checkState(test_VoidParent_Foo_o, CORTO_DEFINED)) {
        test_VoidParent_Foo_o->type = corto_resolve(NULL, "/corto/lang/int32");
        test_VoidParent_Foo_o->modifiers = 0x0;
        test_VoidParent_Foo_o->state = 0x6;
        test_VoidParent_Foo_o->weak = FALSE;
        test_VoidParent_Foo_o->id = 0;
        if (corto_define(test_VoidParent_Foo_o)) {
            corto_error("test_load: failed to define '/test/VoidParent/Foo' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Define /test/VoidParent */
    if (!corto_checkState(test_VoidParent_o, CORTO_DEFINED)) {
        corto_type(test_VoidParent_o)->parentType = corto_resolve(NULL, "/corto/lang/void");
        corto_type(test_VoidParent_o)->parentState = 0x6;
        corto_type(test_VoidParent_o)->defaultType = NULL;
        corto_type(test_VoidParent_o)->defaultProcedureType = NULL;
        corto_interface(test_VoidParent_o)->base = NULL;
        test_VoidParent_o->baseAccess = 0x0;
        if (corto_define(test_VoidParent_o)) {
            corto_error("test_load: failed to define '/test/VoidParent' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (corto_type(test_VoidParent_o)->size != sizeof(test_VoidParent)) {
        corto_error("test_load: calculated size '%d' of type '/test/VoidParent' doesn't match C-type size '%d'", corto_type(test_VoidParent_o)->size, sizeof(test_VoidParent));
    }

    /* Define /test/AnonymousTest/objects */
    if (!corto_checkState(test_AnonymousTest_objects_o, CORTO_DEFINED)) {
        test_AnonymousTest_objects_o->type = corto_resolve(NULL, "/corto/lang/list{object,0}");
        test_AnonymousTest_objects_o->modifiers = 0x0;
        test_AnonymousTest_objects_o->state = 0x6;
        test_AnonymousTest_objects_o->weak = FALSE;
        test_AnonymousTest_objects_o->id = 0;
        if (corto_define(test_AnonymousTest_objects_o)) {
            corto_error("test_load: failed to define '/test/AnonymousTest/objects' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Define /test/AnonymousTest */
    if (!corto_checkState(test_AnonymousTest_o, CORTO_DEFINED)) {
        corto_type(test_AnonymousTest_o)->parentType = NULL;
        corto_type(test_AnonymousTest_o)->parentState = 0x6;
        corto_type(test_AnonymousTest_o)->defaultType = NULL;
        corto_type(test_AnonymousTest_o)->defaultProcedureType = NULL;
        corto_interface(test_AnonymousTest_o)->base = NULL;
        corto_struct(test_AnonymousTest_o)->baseAccess = 0x0;
        test_AnonymousTest_o->implements.length = 0;
        test_AnonymousTest_o->implements.buffer = NULL;
        if (corto_define(test_AnonymousTest_o)) {
            corto_error("test_load: failed to define '/test/AnonymousTest' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (corto_type(test_AnonymousTest_o)->size != sizeof(struct test_AnonymousTest_s)) {
        corto_error("test_load: calculated size '%d' of type '/test/AnonymousTest' doesn't match C-type size '%d'", corto_type(test_AnonymousTest_o)->size, sizeof(struct test_AnonymousTest_s));
    }

    /* Define /test/PrimitiveCollection/ints */
    if (!corto_checkState(test_PrimitiveCollection_ints_o, CORTO_DEFINED)) {
        test_PrimitiveCollection_ints_o->type = corto_resolve(NULL, "/corto/lang/list{int32,0}");
        test_PrimitiveCollection_ints_o->modifiers = 0x0;
        test_PrimitiveCollection_ints_o->state = 0x6;
        test_PrimitiveCollection_ints_o->weak = FALSE;
        test_PrimitiveCollection_ints_o->id = 0;
        if (corto_define(test_PrimitiveCollection_ints_o)) {
            corto_error("test_load: failed to define '/test/PrimitiveCollection/ints' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Define /test/PrimitiveCollection */
    if (!corto_checkState(test_PrimitiveCollection_o, CORTO_DEFINED)) {
        corto_type(test_PrimitiveCollection_o)->parentType = NULL;
        corto_type(test_PrimitiveCollection_o)->parentState = 0x6;
        corto_type(test_PrimitiveCollection_o)->defaultType = NULL;
        corto_type(test_PrimitiveCollection_o)->defaultProcedureType = NULL;
        corto_interface(test_PrimitiveCollection_o)->base = NULL;
        test_PrimitiveCollection_o->baseAccess = 0x0;
        if (corto_define(test_PrimitiveCollection_o)) {
            corto_error("test_load: failed to define '/test/PrimitiveCollection' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (corto_type(test_PrimitiveCollection_o)->size != sizeof(test_PrimitiveCollection)) {
        corto_error("test_load: calculated size '%d' of type '/test/PrimitiveCollection' doesn't match C-type size '%d'", corto_type(test_PrimitiveCollection_o)->size, sizeof(test_PrimitiveCollection));
    }

    /* Declare /test/Select/hasObject(list{/test/selectItem,0} items,string parent,string name,string type) */
    test_Select_hasObject_o = corto_declareChild(test_Select_o, "hasObject(list{/test/selectItem,0} items,string parent,string name,string type)", corto_function_o);
    if (!test_Select_hasObject_o) {
        corto_error("test_load: failed to declare '/test/Select/hasObject(list{/test/selectItem,0} items,string parent,string name,string type)' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/Select/hasObject(list{/test/selectItem,0} items,string parent,string name,string type) */
    if (!corto_checkState(test_Select_hasObject_o, CORTO_DEFINED)) {
        test_Select_hasObject_o->returnType = corto_resolve(NULL, "/corto/lang/bool");
        test_Select_hasObject_o->returnsReference = FALSE;
        
        /* Bind /test/Select/hasObject(list{/test/selectItem,0} items,string parent,string name,string type) with C-function */
        corto_function(test_Select_hasObject_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_Select_hasObject(void *args, void *result);
        corto_function(test_Select_hasObject_o)->impl = (corto_word)__test_Select_hasObject;
        if (corto_define(test_Select_hasObject_o)) {
            corto_error("test_load: failed to define '/test/Select/hasObject(list{/test/selectItem,0} items,string parent,string name,string type)' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/MethodTester/overload(/test/MethodTester m) */
    test_MethodTester_overload__test_MethodTester_o = corto_declareChild(test_MethodTester_o, "overload(/test/MethodTester m)", corto_method_o);
    if (!test_MethodTester_overload__test_MethodTester_o) {
        corto_error("test_load: failed to declare '/test/MethodTester/overload(/test/MethodTester m)' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/MethodTester/overload(/test/MethodTester m) */
    if (!corto_checkState(test_MethodTester_overload__test_MethodTester_o, CORTO_DEFINED)) {
        corto_function(test_MethodTester_overload__test_MethodTester_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_MethodTester_overload__test_MethodTester_o)->returnsReference = FALSE;
        test_MethodTester_overload__test_MethodTester_o->_virtual = FALSE;
        
        /* Bind /test/MethodTester/overload(/test/MethodTester m) with C-function */
        corto_function(test_MethodTester_overload__test_MethodTester_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_MethodTester_overload__test_MethodTester(void *args, void *result);
        corto_function(test_MethodTester_overload__test_MethodTester_o)->impl = (corto_word)__test_MethodTester_overload__test_MethodTester;
        if (corto_define(test_MethodTester_overload__test_MethodTester_o)) {
            corto_error("test_load: failed to define '/test/MethodTester/overload(/test/MethodTester m)' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Define /test/MethodTester */
    if (!corto_checkState(test_MethodTester_o, CORTO_DEFINED)) {
        corto_type(test_MethodTester_o)->parentType = NULL;
        corto_type(test_MethodTester_o)->parentState = 0x6;
        corto_type(test_MethodTester_o)->defaultType = NULL;
        corto_type(test_MethodTester_o)->defaultProcedureType = NULL;
        corto_interface(test_MethodTester_o)->base = NULL;
        corto_struct(test_MethodTester_o)->baseAccess = 0x0;
        test_MethodTester_o->implements.length = 0;
        test_MethodTester_o->implements.buffer = NULL;
        if (corto_define(test_MethodTester_o)) {
            corto_error("test_load: failed to define '/test/MethodTester' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (corto_type(test_MethodTester_o)->size != sizeof(struct test_MethodTester_s)) {
        corto_error("test_load: calculated size '%d' of type '/test/MethodTester' doesn't match C-type size '%d'", corto_type(test_MethodTester_o)->size, sizeof(struct test_MethodTester_s));
    }

    /* Declare /test/MethodTesterInherit/overload(/test/MethodTesterInherit m) */
    test_MethodTesterInherit_overload__test_MethodTesterInherit_o = corto_declareChild(test_MethodTesterInherit_o, "overload(/test/MethodTesterInherit m)", corto_method_o);
    if (!test_MethodTesterInherit_overload__test_MethodTesterInherit_o) {
        corto_error("test_load: failed to declare '/test/MethodTesterInherit/overload(/test/MethodTesterInherit m)' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/MethodTesterInherit/overload(/test/MethodTesterInherit m) */
    if (!corto_checkState(test_MethodTesterInherit_overload__test_MethodTesterInherit_o, CORTO_DEFINED)) {
        corto_function(test_MethodTesterInherit_overload__test_MethodTesterInherit_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_MethodTesterInherit_overload__test_MethodTesterInherit_o)->returnsReference = FALSE;
        test_MethodTesterInherit_overload__test_MethodTesterInherit_o->_virtual = FALSE;
        
        /* Bind /test/MethodTesterInherit/overload(/test/MethodTesterInherit m) with C-function */
        corto_function(test_MethodTesterInherit_overload__test_MethodTesterInherit_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_MethodTesterInherit_overload__test_MethodTesterInherit(void *args, void *result);
        corto_function(test_MethodTesterInherit_overload__test_MethodTesterInherit_o)->impl = (corto_word)__test_MethodTesterInherit_overload__test_MethodTesterInherit;
        if (corto_define(test_MethodTesterInherit_overload__test_MethodTesterInherit_o)) {
            corto_error("test_load: failed to define '/test/MethodTesterInherit/overload(/test/MethodTesterInherit m)' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/MethodTesterInherit/overload(string a,string b) */
    test_MethodTesterInherit_overload_string_string_o = corto_declareChild(test_MethodTesterInherit_o, "overload(string a,string b)", corto_method_o);
    if (!test_MethodTesterInherit_overload_string_string_o) {
        corto_error("test_load: failed to declare '/test/MethodTesterInherit/overload(string a,string b)' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/MethodTesterInherit/overload(string a,string b) */
    if (!corto_checkState(test_MethodTesterInherit_overload_string_string_o, CORTO_DEFINED)) {
        corto_function(test_MethodTesterInherit_overload_string_string_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_MethodTesterInherit_overload_string_string_o)->returnsReference = FALSE;
        test_MethodTesterInherit_overload_string_string_o->_virtual = FALSE;
        
        /* Bind /test/MethodTesterInherit/overload(string a,string b) with C-function */
        corto_function(test_MethodTesterInherit_overload_string_string_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_MethodTesterInherit_overload_string_string(void *args, void *result);
        corto_function(test_MethodTesterInherit_overload_string_string_o)->impl = (corto_word)__test_MethodTesterInherit_overload_string_string;
        if (corto_define(test_MethodTesterInherit_overload_string_string_o)) {
            corto_error("test_load: failed to define '/test/MethodTesterInherit/overload(string a,string b)' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/MethodTesterInherit/simple() */
    test_MethodTesterInherit_simple_o = corto_declareChild(test_MethodTesterInherit_o, "simple()", corto_method_o);
    if (!test_MethodTesterInherit_simple_o) {
        corto_error("test_load: failed to declare '/test/MethodTesterInherit/simple()' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/MethodTesterInherit/simple() */
    if (!corto_checkState(test_MethodTesterInherit_simple_o, CORTO_DEFINED)) {
        corto_function(test_MethodTesterInherit_simple_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_MethodTesterInherit_simple_o)->returnsReference = FALSE;
        test_MethodTesterInherit_simple_o->_virtual = FALSE;
        
        /* Bind /test/MethodTesterInherit/simple() with C-function */
        corto_function(test_MethodTesterInherit_simple_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_MethodTesterInherit_simple(void *args, void *result);
        corto_function(test_MethodTesterInherit_simple_o)->impl = (corto_word)__test_MethodTesterInherit_simple;
        if (corto_define(test_MethodTesterInherit_simple_o)) {
            corto_error("test_load: failed to define '/test/MethodTesterInherit/simple()' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Declare /test/MethodTesterInherit/virtualOverload(int32 a) */
    test_MethodTesterInherit_virtualOverload_o = corto_declareChild(test_MethodTesterInherit_o, "virtualOverload(int32 a)", corto_method_o);
    if (!test_MethodTesterInherit_virtualOverload_o) {
        corto_error("test_load: failed to declare '/test/MethodTesterInherit/virtualOverload(int32 a)' (%s)", corto_lasterr());
        goto error;
    }

    /* Define /test/MethodTesterInherit/virtualOverload(int32 a) */
    if (!corto_checkState(test_MethodTesterInherit_virtualOverload_o, CORTO_DEFINED)) {
        corto_function(test_MethodTesterInherit_virtualOverload_o)->returnType = corto_resolve(NULL, "/corto/lang/void");
        corto_function(test_MethodTesterInherit_virtualOverload_o)->returnsReference = FALSE;
        test_MethodTesterInherit_virtualOverload_o->_virtual = FALSE;
        
        /* Bind /test/MethodTesterInherit/virtualOverload(int32 a) with C-function */
        corto_function(test_MethodTesterInherit_virtualOverload_o)->kind = CORTO_PROCEDURE_CDECL;
        void __test_MethodTesterInherit_virtualOverload(void *args, void *result);
        corto_function(test_MethodTesterInherit_virtualOverload_o)->impl = (corto_word)__test_MethodTesterInherit_virtualOverload;
        if (corto_define(test_MethodTesterInherit_virtualOverload_o)) {
            corto_error("test_load: failed to define '/test/MethodTesterInherit/virtualOverload(int32 a)' (%s)", corto_lasterr());
            goto error;
        }
    }

    /* Define /test/MethodTesterInherit */
    if (!corto_checkState(test_MethodTesterInherit_o, CORTO_DEFINED)) {
        corto_type(test_MethodTesterInherit_o)->parentType = NULL;
        corto_type(test_MethodTesterInherit_o)->parentState = 0x6;
        corto_type(test_MethodTesterInherit_o)->defaultType = NULL;
        corto_type(test_MethodTesterInherit_o)->defaultProcedureType = NULL;
        corto_interface(test_MethodTesterInherit_o)->base = corto_resolve(NULL, "/test/MethodTester");
        corto_struct(test_MethodTesterInherit_o)->baseAccess = 0x0;
        test_MethodTesterInherit_o->implements.length = 0;
        test_MethodTesterInherit_o->implements.buffer = NULL;
        if (corto_define(test_MethodTesterInherit_o)) {
            corto_error("test_load: failed to define '/test/MethodTesterInherit' (%s)", corto_lasterr());
            goto error;
        }
    }

    if (corto_type(test_MethodTesterInherit_o)->size != sizeof(struct test_MethodTesterInherit_s)) {
        corto_error("test_load: calculated size '%d' of type '/test/MethodTesterInherit' doesn't match C-type size '%d'", corto_type(test_MethodTesterInherit_o)->size, sizeof(struct test_MethodTesterInherit_s));
    }

    if (_a_) {
        corto_release(_a_);
    }

    return 0;
error:
    if (_a_) {
        corto_release(_a_);
    }

    return -1;
}
