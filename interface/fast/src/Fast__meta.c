/* Fast__meta.c
 *
 * Loads objects in database.
 * This file contains generated code. Do not modify!
 */

#include "Fast__type.h"

/* Variable definitions */
cx_object _o;
cx_void (*Fast_o);
cx_class Fast_Binary_o;
cx_method Fast_Binary_construct_o;
cx_method Fast_Binary_fold_o;
cx_virtual Fast_Binary_hasSideEffects_o;
cx_member Fast_Binary_lvalue_o;
cx_member Fast_Binary_operator_o;
cx_member Fast_Binary_rvalue_o;
cx_method Fast_Binary_setOperator_o;
cx_virtual Fast_Binary_toIc_o;
cx_struct Fast_Binding_o;
cx_member Fast_Binding_function_o;
cx_member Fast_Binding_impl_o;
cx_class Fast_Block_o;
cx_method Fast_Block_addStatement_o;
cx_method Fast_Block_declare_o;
cx_method Fast_Block_declareReturnVariable_o;
cx_method Fast_Block_declareTemplate_o;
cx_member Fast_Block_function_o;
cx_member Fast_Block_locals_o;
cx_method Fast_Block_lookup_o;
cx_method Fast_Block_lookupLocal_o;
cx_member Fast_Block_parent_o;
cx_method Fast_Block_resolve_o;
cx_method Fast_Block_resolveLocal_o;
cx_method Fast_Block_setFunction_o;
cx_member Fast_Block_statements_o;
cx_virtual Fast_Block_toIc_o;
cx_virtual Fast_Block_toIcBody_o;
cx_member Fast_Block_while_o;
cx_class Fast_Boolean_o;
cx_method Fast_Boolean_init_o;
cx_method Fast_Boolean_serialize_o;
cx_virtual Fast_Boolean_toIc_o;
cx_member Fast_Boolean_value_o;
cx_class Fast_Call_o;
cx_member Fast_Call_arguments_o;
cx_method Fast_Call_construct_o;
cx_member Fast_Call_functionExpr_o;
cx_virtual Fast_Call_hasSideEffects_o;
cx_member Fast_Call_instanceExpr_o;
cx_member Fast_Call_instanceIsAny_o;
cx_member Fast_Call_overloaded_o;
cx_member Fast_Call_parameters_o;
cx_member Fast_Call_returnsReference_o;
cx_member Fast_Call_returnType_o;
cx_method Fast_Call_setParameters_o;
cx_virtual Fast_Call_toIc_o;
cx_struct Fast_CallBuilder_o;
cx_member Fast_CallBuilder_arguments_o;
cx_member Fast_CallBuilder_block_o;
cx_method Fast_CallBuilder_build_o;
cx_method Fast_CallBuilder_buildSignature_o;
cx_member Fast_CallBuilder_instance_o;
cx_member Fast_CallBuilder_name_o;
cx_member Fast_CallBuilder_overloaded_o;
cx_member Fast_CallBuilder_scope_o;
cx_member Fast_CallBuilder_signature_o;
cx_class Fast_Cast_o;
cx_method Fast_Cast_construct_o;
cx_member Fast_Cast_lvalue_o;
cx_member Fast_Cast_rvalue_o;
cx_virtual Fast_Cast_toIc_o;
cx_class Fast_Character_o;
cx_method Fast_Character_init_o;
cx_method Fast_Character_serialize_o;
cx_virtual Fast_Character_toIc_o;
cx_member Fast_Character_value_o;
cx_class Fast_Comma_o;
cx_method Fast_Comma_addExpression_o;
cx_function Fast_Comma_addOrCreate_o;
cx_method Fast_Comma_construct_o;
cx_member Fast_Comma_expressions_o;
cx_virtual Fast_Comma_hasSideEffects_o;
cx_method Fast_Comma_init_o;
cx_virtual Fast_Comma_toIc_o;
cx_method Fast_Comma_toList_o;
cx_class Fast_Define_o;
cx_method Fast_Define_construct_o;
cx_member Fast_Define_object_o;
cx_virtual Fast_Define_toIc_o;
cx_class Fast_DelegateCall_o;
cx_method Fast_DelegateCall_construct_o;
cx_member Fast_DelegateCall_expr_o;
cx_class Fast_DynamicInitializer_o;
cx_member Fast_DynamicInitializer_assignValue_o;
cx_method Fast_DynamicInitializer_construct_o;
cx_method Fast_DynamicInitializer_define_o;
cx_member Fast_DynamicInitializer_frames_o;
cx_method Fast_DynamicInitializer_pop_o;
cx_method Fast_DynamicInitializer_push_o;
cx_method Fast_DynamicInitializer_value_o;
cx_struct Fast_DynamicInitializerFrame_o;
cx_member Fast_DynamicInitializerFrame_expr_o;
cx_member Fast_DynamicInitializerFrame_keyExpr_o;
cx_member Fast_DynamicInitializerFrame_sequenceSize_o;
cx_class Fast_Element_o;
cx_method Fast_Element_construct_o;
cx_member Fast_Element_lvalue_o;
cx_member Fast_Element_rvalue_o;
cx_virtual Fast_Element_toIc_o;
cx_class Fast_Expression_o;
cx_method Fast_Expression_cast_o;
cx_function Fast_Expression_cleanList_o;
cx_virtual Fast_Expression_fold_o;
cx_member Fast_Expression_forceReference_o;
cx_function Fast_Expression_fromList_o;
cx_method Fast_Expression_getType_o;
cx_method Fast_Expression_getType_expr_o;
cx_method Fast_Expression_getType_type_o;
cx_virtual Fast_Expression_getValue_o;
cx_virtual Fast_Expression_hasSideEffects_o;
cx_member Fast_Expression_isReference_o;
cx_virtual Fast_Expression_serialize_o;
cx_virtual Fast_Expression_toList_o;
cx_member Fast_Expression_type_o;
cx_class Fast_FloatingPoint_o;
cx_method Fast_FloatingPoint_init_o;
cx_method Fast_FloatingPoint_serialize_o;
cx_virtual Fast_FloatingPoint_toIc_o;
cx_member Fast_FloatingPoint_value_o;
cx_class Fast_If_o;
cx_member Fast_If_condition_o;
cx_method Fast_If_construct_o;
cx_member Fast_If_falseBranch_o;
cx_method Fast_If_noWarnUnreachable_o;
cx_virtual Fast_If_toIc_o;
cx_member Fast_If_trueBranch_o;
cx_member Fast_If_warnUnreachable_o;
cx_class Fast_Initializer_o;
cx_method Fast_Initializer_construct_o;
cx_method Fast_Initializer_currentType_o;
cx_virtual Fast_Initializer_define_o;
cx_member Fast_Initializer_fp_o;
cx_member Fast_Initializer_frames_o;
cx_method Fast_Initializer_initFrame_o;
cx_virtual Fast_Initializer_member_o;
cx_virtual Fast_Initializer_next_o;
cx_virtual Fast_Initializer_pop_o;
cx_virtual Fast_Initializer_popKey_o;
cx_virtual Fast_Initializer_push_o;
cx_virtual Fast_Initializer_pushKey_o;
cx_method Fast_Initializer_type_o;
cx_virtual Fast_Initializer_value_o;
cx_virtual Fast_Initializer_valueKey_o;
cx_member Fast_Initializer_variableCount_o;
cx_member Fast_Initializer_variables_o;
cx_class Fast_InitializerExpression_o;
cx_member Fast_InitializerExpression_assignValue_o;
cx_method Fast_InitializerExpression_construct_o;
cx_method Fast_InitializerExpression_define_o;
cx_method Fast_InitializerExpression_insert_o;
cx_method Fast_InitializerExpression_member_o;
cx_member Fast_InitializerExpression_operations_o;
cx_method Fast_InitializerExpression_pop_o;
cx_method Fast_InitializerExpression_push_o;
cx_method Fast_InitializerExpression_value_o;
cx_struct Fast_InitializerFrame_o;
cx_member Fast_InitializerFrame_isKey_o;
cx_member Fast_InitializerFrame_location_o;
cx_member Fast_InitializerFrame_member_o;
cx_member Fast_InitializerFrame_type_o;
cx_enum Fast_InitializerKind_o;
cx_constant (*Fast_InitializerKind_InitDynamic_o);
cx_constant (*Fast_InitializerKind_InitExpression_o);
cx_constant (*Fast_InitializerKind_InitStatic_o);
cx_struct Fast_InitializerVariable_o;
cx_member Fast_InitializerVariable_key_o;
cx_member Fast_InitializerVariable_object_o;
cx_member Fast_InitializerVariable_offset_o;
cx_struct Fast_InitOper_o;
cx_member Fast_InitOper_expr_o;
cx_member Fast_InitOper_kind_o;
cx_member Fast_InitOper_name_o;
cx_enum Fast_InitOperKind_o;
cx_constant (*Fast_InitOperKind_InitDefine_o);
cx_constant (*Fast_InitOperKind_InitMember_o);
cx_constant (*Fast_InitOperKind_InitPop_o);
cx_constant (*Fast_InitOperKind_InitPush_o);
cx_constant (*Fast_InitOperKind_InitValue_o);
cx_class Fast_Integer_o;
cx_method Fast_Integer_init_o;
cx_method Fast_Integer_serialize_o;
cx_virtual Fast_Integer_toIc_o;
cx_member Fast_Integer_value_o;
cx_class Fast_Literal_o;
cx_virtual Fast_Literal_getValue_o;
cx_method Fast_Literal_init_o;
cx_member Fast_Literal_kind_o;
cx_class Fast_Local_o;
cx_method Fast_Local_construct_o;
cx_member Fast_Local_kind_o;
cx_member Fast_Local_name_o;
cx_member Fast_Local_reference_o;
cx_virtual Fast_Local_toIc_o;
cx_member Fast_Local_type_o;
cx_enum Fast_LocalKind_o;
cx_constant (*Fast_LocalKind_LocalDefault_o);
cx_constant (*Fast_LocalKind_LocalParameter_o);
cx_constant (*Fast_LocalKind_LocalReturn_o);
cx_struct Fast_Lvalue_o;
cx_member Fast_Lvalue_expr_o;
cx_member Fast_Lvalue_isAssignment_o;
cx_class Fast_Member_o;
cx_method Fast_Member_construct_o;
cx_virtual Fast_Member_hasSideEffects_o;
cx_member Fast_Member_lvalue_o;
cx_member Fast_Member_member_o;
cx_member Fast_Member_rvalue_o;
cx_member Fast_Member_superMember_o;
cx_virtual Fast_Member_toIc_o;
cx_class Fast_New_o;
cx_member Fast_New_attributes_o;
cx_method Fast_New_construct_o;
cx_virtual Fast_New_hasSideEffects_o;
cx_virtual Fast_New_toIc_o;
cx_member Fast_New_type_o;
cx_class Fast_Node_o;
cx_member Fast_Node_column_o;
cx_method Fast_Node_init_o;
cx_member Fast_Node_kind_o;
cx_member Fast_Node_line_o;
cx_virtual Fast_Node_toIc_o;
cx_enum Fast_nodeKind_o;
cx_constant (*Fast_nodeKind_BinaryExpr_o);
cx_constant (*Fast_nodeKind_CallExpr_o);
cx_constant (*Fast_nodeKind_CastExpr_o);
cx_constant (*Fast_nodeKind_CommaExpr_o);
cx_constant (*Fast_nodeKind_DeclarationExpr_o);
cx_constant (*Fast_nodeKind_DeclareExpr_o);
cx_constant (*Fast_nodeKind_DefineExpr_o);
cx_constant (*Fast_nodeKind_ElementExpr_o);
cx_constant (*Fast_nodeKind_IfExpr_o);
cx_constant (*Fast_nodeKind_InitializerExpr_o);
cx_constant (*Fast_nodeKind_LiteralExpr_o);
cx_constant (*Fast_nodeKind_MemberExpr_o);
cx_constant (*Fast_nodeKind_MethodExpr_o);
cx_constant (*Fast_nodeKind_NewExpr_o);
cx_constant (*Fast_nodeKind_PostfixExpr_o);
cx_constant (*Fast_nodeKind_TernaryExpr_o);
cx_constant (*Fast_nodeKind_UnaryExpr_o);
cx_constant (*Fast_nodeKind_UpdateExpr_o);
cx_constant (*Fast_nodeKind_VariableExpr_o);
cx_constant (*Fast_nodeKind_WaitExpr_o);
cx_constant (*Fast_nodeKind_WhileExpr_o);
cx_class Fast_Null_o;
cx_method Fast_Null_init_o;
cx_method Fast_Null_serialize_o;
cx_virtual Fast_Null_toIc_o;
cx_class Fast_Object_o;
cx_method Fast_Object_construct_o;
cx_method Fast_Object_getValue_o;
cx_method Fast_Object_serialize_o;
cx_virtual Fast_Object_toIc_o;
cx_class Fast_ObjectBase_o;
cx_method Fast_ObjectBase_construct_o;
cx_member Fast_ObjectBase_value_o;
cx_class Fast_Parser_o;
cx_member Fast_Parser_abort_o;
cx_method Fast_Parser_addStatement_o;
cx_method Fast_Parser_argumentToString_o;
cx_method Fast_Parser_binaryExpr_o;
cx_method Fast_Parser_bind_o;
cx_member Fast_Parser_bindings_o;
cx_method Fast_Parser_bindOneliner_o;
cx_member Fast_Parser_block_o;
cx_member Fast_Parser_blockCount_o;
cx_method Fast_Parser_blockPop_o;
cx_member Fast_Parser_blockPreset_o;
cx_method Fast_Parser_blockPush_o;
cx_method Fast_Parser_callExpr_o;
cx_method Fast_Parser_castExpr_o;
cx_method Fast_Parser_collect_o;
cx_member Fast_Parser_collected_o;
cx_method Fast_Parser_collectHeap_o;
cx_member Fast_Parser_column_o;
cx_member Fast_Parser_complexType_o;
cx_member Fast_Parser_complexTypeSp_o;
cx_method Fast_Parser_construct_o;
cx_method Fast_Parser_declaration_o;
cx_method Fast_Parser_declareFunction_o;
cx_method Fast_Parser_declareFunctionParams_o;
cx_method Fast_Parser_define_o;
cx_method Fast_Parser_defineScope_o;
cx_method Fast_Parser_defineVariable_o;
cx_method Fast_Parser_destruct_o;
cx_method Fast_Parser_elementExpr_o;
cx_member Fast_Parser_errLine_o;
cx_member Fast_Parser_errors_o;
cx_member Fast_Parser_errSet_o;
cx_member Fast_Parser_filename_o;
cx_method Fast_Parser_finalize_o;
cx_method Fast_Parser_foreach_o;
cx_method Fast_Parser_getComplexType_o;
cx_method Fast_Parser_getLvalue_o;
cx_method Fast_Parser_getLvalueType_o;
cx_member Fast_Parser_heapCollected_o;
cx_method Fast_Parser_ifStatement_o;
cx_member Fast_Parser_initAnonymousId_o;
cx_method Fast_Parser_initDeclareStaged_o;
cx_member Fast_Parser_initDynamic_o;
cx_member Fast_Parser_initializerCount_o;
cx_member Fast_Parser_initializers_o;
cx_method Fast_Parser_initKeyValuePop_o;
cx_method Fast_Parser_initKeyValuePush_o;
cx_method Fast_Parser_initKeyValueSet_o;
cx_method Fast_Parser_initMember_o;
cx_method Fast_Parser_initPop_o;
cx_method Fast_Parser_initPush_o;
cx_method Fast_Parser_initPushExpression_o;
cx_method Fast_Parser_initPushIdentifier_o;
cx_method Fast_Parser_initPushStatic_o;
cx_method Fast_Parser_initStage_o;
cx_method Fast_Parser_initValue_o;
cx_method Fast_Parser_isAbortSet_o;
cx_method Fast_Parser_isErrSet_o;
cx_member Fast_Parser_isLocal_o;
cx_member Fast_Parser_lastFailedResolve_o;
cx_member Fast_Parser_line_o;
cx_method Fast_Parser_lookup_o;
cx_member Fast_Parser_lvalue_o;
cx_member Fast_Parser_lvalueSp_o;
cx_method Fast_Parser_memberExpr_o;
cx_method Fast_Parser_observerDeclaration_o;
cx_method Fast_Parser_observerPush_o;
cx_method Fast_Parser_parse_o;
cx_method Fast_Parser_parseExpression_o;
cx_function Fast_Parser_parseLine_o;
cx_member Fast_Parser_parseSingleExpr_o;
cx_member Fast_Parser_pass_o;
cx_method Fast_Parser_popComplexType_o;
cx_method Fast_Parser_popLvalue_o;
cx_method Fast_Parser_popScope_o;
cx_method Fast_Parser_postfixExpr_o;
cx_member Fast_Parser_preprocessed_o;
cx_method Fast_Parser_pushComplexType_o;
cx_method Fast_Parser_pushLvalue_o;
cx_method Fast_Parser_pushPackage_o;
cx_method Fast_Parser_pushReturnAsLvalue_o;
cx_method Fast_Parser_pushScope_o;
cx_member Fast_Parser_repl_o;
cx_method Fast_Parser_reset_o;
cx_member Fast_Parser_scope_o;
cx_member Fast_Parser_singleExpr_o;
cx_member Fast_Parser_source_o;
cx_member Fast_Parser_staged_o;
cx_member Fast_Parser_stagedCount_o;
cx_struct Fast_Parser_stagedId_o;
cx_member Fast_Parser_stagedId_column_o;
cx_member Fast_Parser_stagedId_found_o;
cx_member Fast_Parser_stagedId_line_o;
cx_member Fast_Parser_stagedId_name_o;
cx_member Fast_Parser_stagingAllowed_o;
cx_method Fast_Parser_ternaryExpr_o;
cx_member Fast_Parser_token_o;
cx_method Fast_Parser_unaryExpr_o;
cx_method Fast_Parser_updateStatement_o;
cx_member Fast_Parser_variableCount_o;
cx_member Fast_Parser_variablePushed_o;
cx_member Fast_Parser_variables_o;
cx_member Fast_Parser_variablesInitialized_o;
cx_method Fast_Parser_waitExpr_o;
cx_member Fast_Parser_warnings_o;
cx_method Fast_Parser_whileStatement_o;
cx_struct Fast_ParserDeclaration_o;
cx_member Fast_ParserDeclaration_name_o;
cx_member Fast_ParserDeclaration_variable_o;
cx_sequence Fast_ParserDeclarationSeq_o;
cx_struct Fast_ParserNew_o;
cx_member Fast_ParserNew_attr_o;
cx_member Fast_ParserNew_kind_o;
cx_member Fast_ParserNew_name_o;
cx_member Fast_ParserNew_parent_o;
cx_class Fast_PostFix_o;
cx_method Fast_PostFix_construct_o;
cx_member Fast_PostFix_lvalue_o;
cx_member Fast_PostFix_operator_o;
cx_virtual Fast_PostFix_toIc_o;
cx_function Fast_report_o;
cx_function Fast_reportError_o;
cx_function Fast_reportWarning_o;
cx_class Fast_SignedInteger_o;
cx_method Fast_SignedInteger_init_o;
cx_method Fast_SignedInteger_serialize_o;
cx_virtual Fast_SignedInteger_toIc_o;
cx_member Fast_SignedInteger_value_o;
cx_class Fast_StaticCall_o;
cx_method Fast_StaticCall_construct_o;
cx_member Fast_StaticCall_function_o;
cx_class Fast_StaticInitializer_o;
cx_method Fast_StaticInitializer_construct_o;
cx_method Fast_StaticInitializer_define_o;
cx_member Fast_StaticInitializer_frames_o;
cx_method Fast_StaticInitializer_push_o;
cx_method Fast_StaticInitializer_value_o;
cx_struct Fast_StaticInitializerFrame_o;
cx_member Fast_StaticInitializerFrame_keyPtr_o;
cx_member Fast_StaticInitializerFrame_ptr_o;
cx_class Fast_String_o;
cx_member Fast_String_block_o;
cx_method Fast_String_construct_o;
cx_member Fast_String_elements_o;
cx_method Fast_String_getValue_o;
cx_method Fast_String_init_o;
cx_member Fast_String_scope_o;
cx_method Fast_String_serialize_o;
cx_virtual Fast_String_toIc_o;
cx_member Fast_String_value_o;
cx_class Fast_Template_o;
cx_method Fast_Template_construct_o;
cx_class Fast_Ternary_o;
cx_member Fast_Ternary_condition_o;
cx_method Fast_Ternary_construct_o;
cx_virtual Fast_Ternary_hasSideEffects_o;
cx_member Fast_Ternary_ifFalse_o;
cx_member Fast_Ternary_ifFalseExpr_o;
cx_member Fast_Ternary_ifstmt_o;
cx_member Fast_Ternary_ifTrue_o;
cx_member Fast_Ternary_ifTrueExpr_o;
cx_member Fast_Ternary_result_o;
cx_method Fast_Ternary_setOperator_o;
cx_virtual Fast_Ternary_toIc_o;
cx_class Fast_Unary_o;
cx_method Fast_Unary_construct_o;
cx_virtual Fast_Unary_hasSideEffects_o;
cx_member Fast_Unary_lvalue_o;
cx_member Fast_Unary_operator_o;
cx_virtual Fast_Unary_toIc_o;
cx_class Fast_Update_o;
cx_member Fast_Update_block_o;
cx_method Fast_Update_construct_o;
cx_member Fast_Update_exprList_o;
cx_member Fast_Update_from_o;
cx_member Fast_Update_kind_o;
cx_virtual Fast_Update_toIc_o;
cx_enum Fast_UpdateKind_o;
cx_constant (*Fast_UpdateKind_UpdateBegin_o);
cx_constant (*Fast_UpdateKind_UpdateDefault_o);
cx_constant (*Fast_UpdateKind_UpdateEnd_o);
cx_enum Fast_valueKind_o;
cx_constant (*Fast_valueKind_Bool_o);
cx_constant (*Fast_valueKind_Char_o);
cx_constant (*Fast_valueKind_Enum_o);
cx_constant (*Fast_valueKind_Float_o);
cx_constant (*Fast_valueKind_Int_o);
cx_constant (*Fast_valueKind_Nothing_o);
cx_constant (*Fast_valueKind_Ref_o);
cx_constant (*Fast_valueKind_SignedInt_o);
cx_constant (*Fast_valueKind_Text_o);
cx_function Fast_valueKindFromType_o;
cx_class Fast_Variable_o;
cx_method Fast_Variable_construct_o;
cx_member Fast_Variable_kind_o;
cx_enum Fast_variableKind_o;
cx_constant (*Fast_variableKind_LocalExpr_o);
cx_constant (*Fast_variableKind_ObjectExpr_o);
cx_constant (*Fast_variableKind_TemplateExpr_o);
cx_class Fast_Wait_o;
cx_method Fast_Wait_construct_o;
cx_member Fast_Wait_exprList_o;
cx_member Fast_Wait_timeout_o;
cx_virtual Fast_Wait_toIc_o;
cx_class Fast_While_o;
cx_member Fast_While_condition_o;
cx_method Fast_While_construct_o;
cx_member Fast_While_isUntil_o;
cx_virtual Fast_While_toIc_o;
cx_member Fast_While_trueBranch_o;

/* Load objects in database */
int Fast_load(void) {
    cx_object _a_; /* Used for resolving anonymous objects */
    _a_ = NULL;

    /* Declare ::cortex */
    _o = cx_declare(root_o, "cortex", cx_type(cx_object_o));
    if (!_o) {
        cx_error("Fast_load: failed to declare object '::cortex'.");
        goto error;
    }

    /* Define ::cortex */
    if (!cx_checkState(_o, CX_DEFINED)) {
        if (cx_define(_o)) {
            cx_error("Fast_load: failed to define object '::cortex'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast */
    Fast_o = cx_declare(_o, "Fast", cx_type(cx_void_o));
    if (!Fast_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Binary */
    Fast_Binary_o = cx_declare(Fast_o, "Binary", cx_type(cx_class_o));
    if (!Fast_Binary_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Binary'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Binary::lvalue */
    Fast_Binary_lvalue_o = cx_declare(Fast_Binary_o, "lvalue", cx_type(cx_member_o));
    if (!Fast_Binary_lvalue_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Binary::lvalue'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Binary::operator */
    Fast_Binary_operator_o = cx_declare(Fast_Binary_o, "operator", cx_type(cx_member_o));
    if (!Fast_Binary_operator_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Binary::operator'.");
        goto error;
    }

    /* Define ::cortex::Fast::Binary::operator */
    if (!cx_checkState(Fast_Binary_operator_o, CX_DEFINED)) {
        Fast_Binary_operator_o->type = cx_resolve_ext(Fast_Binary_operator_o, NULL, "::cortex::lang::operatorKind", FALSE, "element ::cortex::Fast::Binary::operator.type");
        Fast_Binary_operator_o->modifiers = 0x0;
        Fast_Binary_operator_o->state = 0x6;
        Fast_Binary_operator_o->weak = FALSE;
        Fast_Binary_operator_o->id = 2;
        if (cx_define(Fast_Binary_operator_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Binary::operator'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Binary::rvalue */
    Fast_Binary_rvalue_o = cx_declare(Fast_Binary_o, "rvalue", cx_type(cx_member_o));
    if (!Fast_Binary_rvalue_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Binary::rvalue'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Binding */
    Fast_Binding_o = cx_declare(Fast_o, "Binding", cx_type(cx_struct_o));
    if (!Fast_Binding_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Binding'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Binding::function */
    Fast_Binding_function_o = cx_declare(Fast_Binding_o, "function", cx_type(cx_member_o));
    if (!Fast_Binding_function_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Binding::function'.");
        goto error;
    }

    /* Define ::cortex::Fast::Binding::function */
    if (!cx_checkState(Fast_Binding_function_o, CX_DEFINED)) {
        Fast_Binding_function_o->type = cx_resolve_ext(Fast_Binding_function_o, NULL, "::cortex::lang::function", FALSE, "element ::cortex::Fast::Binding::function.type");
        Fast_Binding_function_o->modifiers = 0x0;
        Fast_Binding_function_o->state = 0x6;
        Fast_Binding_function_o->weak = FALSE;
        Fast_Binding_function_o->id = 0;
        if (cx_define(Fast_Binding_function_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Binding::function'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Binding::impl */
    Fast_Binding_impl_o = cx_declare(Fast_Binding_o, "impl", cx_type(cx_member_o));
    if (!Fast_Binding_impl_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Binding::impl'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Block */
    Fast_Block_o = cx_declare(Fast_o, "Block", cx_type(cx_class_o));
    if (!Fast_Block_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Block'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Block::function */
    Fast_Block_function_o = cx_declare(Fast_Block_o, "function", cx_type(cx_member_o));
    if (!Fast_Block_function_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Block::function'.");
        goto error;
    }

    /* Define ::cortex::Fast::Block::function */
    if (!cx_checkState(Fast_Block_function_o, CX_DEFINED)) {
        Fast_Block_function_o->type = cx_resolve_ext(Fast_Block_function_o, NULL, "::cortex::lang::function", FALSE, "element ::cortex::Fast::Block::function.type");
        Fast_Block_function_o->modifiers = 0x4;
        Fast_Block_function_o->state = 0x6;
        Fast_Block_function_o->weak = FALSE;
        Fast_Block_function_o->id = 3;
        if (cx_define(Fast_Block_function_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Block::function'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Block::locals */
    Fast_Block_locals_o = cx_declare(Fast_Block_o, "locals", cx_type(cx_member_o));
    if (!Fast_Block_locals_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Block::locals'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Block::parent */
    Fast_Block_parent_o = cx_declare(Fast_Block_o, "parent", cx_type(cx_member_o));
    if (!Fast_Block_parent_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Block::parent'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Block::statements */
    Fast_Block_statements_o = cx_declare(Fast_Block_o, "statements", cx_type(cx_member_o));
    if (!Fast_Block_statements_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Block::statements'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Block::while */
    Fast_Block_while_o = cx_declare(Fast_Block_o, "while", cx_type(cx_member_o));
    if (!Fast_Block_while_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Block::while'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Boolean */
    Fast_Boolean_o = cx_declare(Fast_o, "Boolean", cx_type(cx_class_o));
    if (!Fast_Boolean_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Boolean'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Boolean::value */
    Fast_Boolean_value_o = cx_declare(Fast_Boolean_o, "value", cx_type(cx_member_o));
    if (!Fast_Boolean_value_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Boolean::value'.");
        goto error;
    }

    /* Define ::cortex::Fast::Boolean::value */
    if (!cx_checkState(Fast_Boolean_value_o, CX_DEFINED)) {
        Fast_Boolean_value_o->type = cx_resolve_ext(Fast_Boolean_value_o, NULL, "::cortex::lang::bool", FALSE, "element ::cortex::Fast::Boolean::value.type");
        Fast_Boolean_value_o->modifiers = 0x0;
        Fast_Boolean_value_o->state = 0x6;
        Fast_Boolean_value_o->weak = FALSE;
        Fast_Boolean_value_o->id = 0;
        if (cx_define(Fast_Boolean_value_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Boolean::value'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Call */
    Fast_Call_o = cx_declare(Fast_o, "Call", cx_type(cx_class_o));
    if (!Fast_Call_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Call'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Call::arguments */
    Fast_Call_arguments_o = cx_declare(Fast_Call_o, "arguments", cx_type(cx_member_o));
    if (!Fast_Call_arguments_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Call::arguments'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Call::functionExpr */
    Fast_Call_functionExpr_o = cx_declare(Fast_Call_o, "functionExpr", cx_type(cx_member_o));
    if (!Fast_Call_functionExpr_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Call::functionExpr'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Call::instanceExpr */
    Fast_Call_instanceExpr_o = cx_declare(Fast_Call_o, "instanceExpr", cx_type(cx_member_o));
    if (!Fast_Call_instanceExpr_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Call::instanceExpr'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Call::instanceIsAny */
    Fast_Call_instanceIsAny_o = cx_declare(Fast_Call_o, "instanceIsAny", cx_type(cx_member_o));
    if (!Fast_Call_instanceIsAny_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Call::instanceIsAny'.");
        goto error;
    }

    /* Define ::cortex::Fast::Call::instanceIsAny */
    if (!cx_checkState(Fast_Call_instanceIsAny_o, CX_DEFINED)) {
        Fast_Call_instanceIsAny_o->type = cx_resolve_ext(Fast_Call_instanceIsAny_o, NULL, "::cortex::lang::bool", FALSE, "element ::cortex::Fast::Call::instanceIsAny.type");
        Fast_Call_instanceIsAny_o->modifiers = 0x4;
        Fast_Call_instanceIsAny_o->state = 0x6;
        Fast_Call_instanceIsAny_o->weak = FALSE;
        Fast_Call_instanceIsAny_o->id = 3;
        if (cx_define(Fast_Call_instanceIsAny_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Call::instanceIsAny'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Call::overloaded */
    Fast_Call_overloaded_o = cx_declare(Fast_Call_o, "overloaded", cx_type(cx_member_o));
    if (!Fast_Call_overloaded_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Call::overloaded'.");
        goto error;
    }

    /* Define ::cortex::Fast::Call::overloaded */
    if (!cx_checkState(Fast_Call_overloaded_o, CX_DEFINED)) {
        Fast_Call_overloaded_o->type = cx_resolve_ext(Fast_Call_overloaded_o, NULL, "::cortex::lang::bool", FALSE, "element ::cortex::Fast::Call::overloaded.type");
        Fast_Call_overloaded_o->modifiers = 0x4;
        Fast_Call_overloaded_o->state = 0x6;
        Fast_Call_overloaded_o->weak = FALSE;
        Fast_Call_overloaded_o->id = 7;
        if (cx_define(Fast_Call_overloaded_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Call::overloaded'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Call::parameters */
    Fast_Call_parameters_o = cx_declare(Fast_Call_o, "parameters", cx_type(cx_member_o));
    if (!Fast_Call_parameters_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Call::parameters'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Call::returnsReference */
    Fast_Call_returnsReference_o = cx_declare(Fast_Call_o, "returnsReference", cx_type(cx_member_o));
    if (!Fast_Call_returnsReference_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Call::returnsReference'.");
        goto error;
    }

    /* Define ::cortex::Fast::Call::returnsReference */
    if (!cx_checkState(Fast_Call_returnsReference_o, CX_DEFINED)) {
        Fast_Call_returnsReference_o->type = cx_resolve_ext(Fast_Call_returnsReference_o, NULL, "::cortex::lang::bool", FALSE, "element ::cortex::Fast::Call::returnsReference.type");
        Fast_Call_returnsReference_o->modifiers = 0x4;
        Fast_Call_returnsReference_o->state = 0x6;
        Fast_Call_returnsReference_o->weak = FALSE;
        Fast_Call_returnsReference_o->id = 5;
        if (cx_define(Fast_Call_returnsReference_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Call::returnsReference'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Call::returnType */
    Fast_Call_returnType_o = cx_declare(Fast_Call_o, "returnType", cx_type(cx_member_o));
    if (!Fast_Call_returnType_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Call::returnType'.");
        goto error;
    }

    /* Define ::cortex::Fast::Call::returnType */
    if (!cx_checkState(Fast_Call_returnType_o, CX_DEFINED)) {
        Fast_Call_returnType_o->type = cx_resolve_ext(Fast_Call_returnType_o, NULL, "::cortex::lang::type", FALSE, "element ::cortex::Fast::Call::returnType.type");
        Fast_Call_returnType_o->modifiers = 0x4;
        Fast_Call_returnType_o->state = 0x6;
        Fast_Call_returnType_o->weak = FALSE;
        Fast_Call_returnType_o->id = 4;
        if (cx_define(Fast_Call_returnType_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Call::returnType'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::CallBuilder */
    Fast_CallBuilder_o = cx_declare(Fast_o, "CallBuilder", cx_type(cx_struct_o));
    if (!Fast_CallBuilder_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::CallBuilder'.");
        goto error;
    }

    /* Declare ::cortex::Fast::CallBuilder::arguments */
    Fast_CallBuilder_arguments_o = cx_declare(Fast_CallBuilder_o, "arguments", cx_type(cx_member_o));
    if (!Fast_CallBuilder_arguments_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::CallBuilder::arguments'.");
        goto error;
    }

    /* Declare ::cortex::Fast::CallBuilder::block */
    Fast_CallBuilder_block_o = cx_declare(Fast_CallBuilder_o, "block", cx_type(cx_member_o));
    if (!Fast_CallBuilder_block_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::CallBuilder::block'.");
        goto error;
    }

    /* Declare ::cortex::Fast::CallBuilder::build() */
    Fast_CallBuilder_build_o = cx_declare(Fast_CallBuilder_o, "build()", cx_type(cx_method_o));
    if (!Fast_CallBuilder_build_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::CallBuilder::build()'.");
        goto error;
    }

    /* Define ::cortex::Fast::CallBuilder::build() */
    if (!cx_checkState(Fast_CallBuilder_build_o, CX_DEFINED)) {
        cx_function(Fast_CallBuilder_build_o)->returnType = cx_resolve_ext(Fast_CallBuilder_build_o, NULL, "::cortex::Fast::Call", FALSE, "element ::cortex::Fast::CallBuilder::build().returnType");
        cx_function(Fast_CallBuilder_build_o)->returnsReference = FALSE;
        Fast_CallBuilder_build_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::CallBuilder::build() with C-function */
        cx_function(Fast_CallBuilder_build_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_CallBuilder_build(void *args, void *result);
        cx_function(Fast_CallBuilder_build_o)->impl = (cx_word)__Fast_CallBuilder_build;
        if (cx_define(Fast_CallBuilder_build_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::CallBuilder::build()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::CallBuilder::buildSignature() */
    Fast_CallBuilder_buildSignature_o = cx_declare(Fast_CallBuilder_o, "buildSignature()", cx_type(cx_method_o));
    if (!Fast_CallBuilder_buildSignature_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::CallBuilder::buildSignature()'.");
        goto error;
    }

    /* Define ::cortex::Fast::CallBuilder::buildSignature() */
    if (!cx_checkState(Fast_CallBuilder_buildSignature_o, CX_DEFINED)) {
        cx_function(Fast_CallBuilder_buildSignature_o)->returnType = cx_resolve_ext(Fast_CallBuilder_buildSignature_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::CallBuilder::buildSignature().returnType");
        cx_function(Fast_CallBuilder_buildSignature_o)->returnsReference = FALSE;
        Fast_CallBuilder_buildSignature_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::CallBuilder::buildSignature() with C-function */
        cx_function(Fast_CallBuilder_buildSignature_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_CallBuilder_buildSignature(void *args, void *result);
        cx_function(Fast_CallBuilder_buildSignature_o)->impl = (cx_word)__Fast_CallBuilder_buildSignature;
        if (cx_define(Fast_CallBuilder_buildSignature_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::CallBuilder::buildSignature()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::CallBuilder::instance */
    Fast_CallBuilder_instance_o = cx_declare(Fast_CallBuilder_o, "instance", cx_type(cx_member_o));
    if (!Fast_CallBuilder_instance_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::CallBuilder::instance'.");
        goto error;
    }

    /* Declare ::cortex::Fast::CallBuilder::name */
    Fast_CallBuilder_name_o = cx_declare(Fast_CallBuilder_o, "name", cx_type(cx_member_o));
    if (!Fast_CallBuilder_name_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::CallBuilder::name'.");
        goto error;
    }

    /* Define ::cortex::Fast::CallBuilder::name */
    if (!cx_checkState(Fast_CallBuilder_name_o, CX_DEFINED)) {
        Fast_CallBuilder_name_o->type = cx_resolve_ext(Fast_CallBuilder_name_o, NULL, "::cortex::lang::string", FALSE, "element ::cortex::Fast::CallBuilder::name.type");
        Fast_CallBuilder_name_o->modifiers = 0x0;
        Fast_CallBuilder_name_o->state = 0x6;
        Fast_CallBuilder_name_o->weak = FALSE;
        Fast_CallBuilder_name_o->id = 0;
        if (cx_define(Fast_CallBuilder_name_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::CallBuilder::name'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::CallBuilder::overloaded */
    Fast_CallBuilder_overloaded_o = cx_declare(Fast_CallBuilder_o, "overloaded", cx_type(cx_member_o));
    if (!Fast_CallBuilder_overloaded_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::CallBuilder::overloaded'.");
        goto error;
    }

    /* Define ::cortex::Fast::CallBuilder::overloaded */
    if (!cx_checkState(Fast_CallBuilder_overloaded_o, CX_DEFINED)) {
        Fast_CallBuilder_overloaded_o->type = cx_resolve_ext(Fast_CallBuilder_overloaded_o, NULL, "::cortex::lang::bool", FALSE, "element ::cortex::Fast::CallBuilder::overloaded.type");
        Fast_CallBuilder_overloaded_o->modifiers = 0x3;
        Fast_CallBuilder_overloaded_o->state = 0x6;
        Fast_CallBuilder_overloaded_o->weak = FALSE;
        Fast_CallBuilder_overloaded_o->id = 5;
        if (cx_define(Fast_CallBuilder_overloaded_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::CallBuilder::overloaded'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::CallBuilder::scope */
    Fast_CallBuilder_scope_o = cx_declare(Fast_CallBuilder_o, "scope", cx_type(cx_member_o));
    if (!Fast_CallBuilder_scope_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::CallBuilder::scope'.");
        goto error;
    }

    /* Define ::cortex::Fast::CallBuilder::scope */
    if (!cx_checkState(Fast_CallBuilder_scope_o, CX_DEFINED)) {
        Fast_CallBuilder_scope_o->type = cx_resolve_ext(Fast_CallBuilder_scope_o, NULL, "::cortex::lang::object", FALSE, "element ::cortex::Fast::CallBuilder::scope.type");
        Fast_CallBuilder_scope_o->modifiers = 0x0;
        Fast_CallBuilder_scope_o->state = 0x6;
        Fast_CallBuilder_scope_o->weak = FALSE;
        Fast_CallBuilder_scope_o->id = 3;
        if (cx_define(Fast_CallBuilder_scope_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::CallBuilder::scope'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::CallBuilder::signature */
    Fast_CallBuilder_signature_o = cx_declare(Fast_CallBuilder_o, "signature", cx_type(cx_member_o));
    if (!Fast_CallBuilder_signature_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::CallBuilder::signature'.");
        goto error;
    }

    /* Define ::cortex::Fast::CallBuilder::signature */
    if (!cx_checkState(Fast_CallBuilder_signature_o, CX_DEFINED)) {
        Fast_CallBuilder_signature_o->type = cx_resolve_ext(Fast_CallBuilder_signature_o, NULL, "::cortex::lang::string", FALSE, "element ::cortex::Fast::CallBuilder::signature.type");
        Fast_CallBuilder_signature_o->modifiers = 0x3;
        Fast_CallBuilder_signature_o->state = 0x6;
        Fast_CallBuilder_signature_o->weak = FALSE;
        Fast_CallBuilder_signature_o->id = 6;
        if (cx_define(Fast_CallBuilder_signature_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::CallBuilder::signature'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Cast */
    Fast_Cast_o = cx_declare(Fast_o, "Cast", cx_type(cx_class_o));
    if (!Fast_Cast_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Cast'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Cast::lvalue */
    Fast_Cast_lvalue_o = cx_declare(Fast_Cast_o, "lvalue", cx_type(cx_member_o));
    if (!Fast_Cast_lvalue_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Cast::lvalue'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Cast::rvalue */
    Fast_Cast_rvalue_o = cx_declare(Fast_Cast_o, "rvalue", cx_type(cx_member_o));
    if (!Fast_Cast_rvalue_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Cast::rvalue'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Character */
    Fast_Character_o = cx_declare(Fast_o, "Character", cx_type(cx_class_o));
    if (!Fast_Character_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Character'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Character::value */
    Fast_Character_value_o = cx_declare(Fast_Character_o, "value", cx_type(cx_member_o));
    if (!Fast_Character_value_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Character::value'.");
        goto error;
    }

    /* Define ::cortex::Fast::Character::value */
    if (!cx_checkState(Fast_Character_value_o, CX_DEFINED)) {
        Fast_Character_value_o->type = cx_resolve_ext(Fast_Character_value_o, NULL, "::cortex::lang::char", FALSE, "element ::cortex::Fast::Character::value.type");
        Fast_Character_value_o->modifiers = 0x0;
        Fast_Character_value_o->state = 0x6;
        Fast_Character_value_o->weak = FALSE;
        Fast_Character_value_o->id = 0;
        if (cx_define(Fast_Character_value_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Character::value'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Comma */
    Fast_Comma_o = cx_declare(Fast_o, "Comma", cx_type(cx_class_o));
    if (!Fast_Comma_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Comma'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Comma::expressions */
    Fast_Comma_expressions_o = cx_declare(Fast_Comma_o, "expressions", cx_type(cx_member_o));
    if (!Fast_Comma_expressions_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Comma::expressions'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Define */
    Fast_Define_o = cx_declare(Fast_o, "Define", cx_type(cx_class_o));
    if (!Fast_Define_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Define'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Define::object */
    Fast_Define_object_o = cx_declare(Fast_Define_o, "object", cx_type(cx_member_o));
    if (!Fast_Define_object_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Define::object'.");
        goto error;
    }

    /* Declare ::cortex::Fast::DelegateCall */
    Fast_DelegateCall_o = cx_declare(Fast_o, "DelegateCall", cx_type(cx_class_o));
    if (!Fast_DelegateCall_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::DelegateCall'.");
        goto error;
    }

    /* Declare ::cortex::Fast::DelegateCall::expr */
    Fast_DelegateCall_expr_o = cx_declare(Fast_DelegateCall_o, "expr", cx_type(cx_member_o));
    if (!Fast_DelegateCall_expr_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::DelegateCall::expr'.");
        goto error;
    }

    /* Declare ::cortex::Fast::DynamicInitializer */
    Fast_DynamicInitializer_o = cx_declare(Fast_o, "DynamicInitializer", cx_type(cx_class_o));
    if (!Fast_DynamicInitializer_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::DynamicInitializer'.");
        goto error;
    }

    /* Declare ::cortex::Fast::DynamicInitializer::assignValue */
    Fast_DynamicInitializer_assignValue_o = cx_declare(Fast_DynamicInitializer_o, "assignValue", cx_type(cx_member_o));
    if (!Fast_DynamicInitializer_assignValue_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::DynamicInitializer::assignValue'.");
        goto error;
    }

    /* Define ::cortex::Fast::DynamicInitializer::assignValue */
    if (!cx_checkState(Fast_DynamicInitializer_assignValue_o, CX_DEFINED)) {
        Fast_DynamicInitializer_assignValue_o->type = cx_resolve_ext(Fast_DynamicInitializer_assignValue_o, NULL, "::cortex::lang::bool", FALSE, "element ::cortex::Fast::DynamicInitializer::assignValue.type");
        Fast_DynamicInitializer_assignValue_o->modifiers = 0x0;
        Fast_DynamicInitializer_assignValue_o->state = 0x6;
        Fast_DynamicInitializer_assignValue_o->weak = FALSE;
        Fast_DynamicInitializer_assignValue_o->id = 0;
        if (cx_define(Fast_DynamicInitializer_assignValue_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::DynamicInitializer::assignValue'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::DynamicInitializer::frames */
    Fast_DynamicInitializer_frames_o = cx_declare(Fast_DynamicInitializer_o, "frames", cx_type(cx_member_o));
    if (!Fast_DynamicInitializer_frames_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::DynamicInitializer::frames'.");
        goto error;
    }

    /* Declare ::cortex::Fast::DynamicInitializerFrame */
    Fast_DynamicInitializerFrame_o = cx_declare(Fast_o, "DynamicInitializerFrame", cx_type(cx_struct_o));
    if (!Fast_DynamicInitializerFrame_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::DynamicInitializerFrame'.");
        goto error;
    }

    /* Declare ::cortex::Fast::DynamicInitializerFrame::expr */
    Fast_DynamicInitializerFrame_expr_o = cx_declare(Fast_DynamicInitializerFrame_o, "expr", cx_type(cx_member_o));
    if (!Fast_DynamicInitializerFrame_expr_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::DynamicInitializerFrame::expr'.");
        goto error;
    }

    /* Declare ::cortex::Fast::DynamicInitializerFrame::keyExpr */
    Fast_DynamicInitializerFrame_keyExpr_o = cx_declare(Fast_DynamicInitializerFrame_o, "keyExpr", cx_type(cx_member_o));
    if (!Fast_DynamicInitializerFrame_keyExpr_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::DynamicInitializerFrame::keyExpr'.");
        goto error;
    }

    /* Declare ::cortex::Fast::DynamicInitializerFrame::sequenceSize */
    Fast_DynamicInitializerFrame_sequenceSize_o = cx_declare(Fast_DynamicInitializerFrame_o, "sequenceSize", cx_type(cx_member_o));
    if (!Fast_DynamicInitializerFrame_sequenceSize_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::DynamicInitializerFrame::sequenceSize'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Element */
    Fast_Element_o = cx_declare(Fast_o, "Element", cx_type(cx_class_o));
    if (!Fast_Element_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Element'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Element::lvalue */
    Fast_Element_lvalue_o = cx_declare(Fast_Element_o, "lvalue", cx_type(cx_member_o));
    if (!Fast_Element_lvalue_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Element::lvalue'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Element::rvalue */
    Fast_Element_rvalue_o = cx_declare(Fast_Element_o, "rvalue", cx_type(cx_member_o));
    if (!Fast_Element_rvalue_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Element::rvalue'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Expression */
    Fast_Expression_o = cx_declare(Fast_o, "Expression", cx_type(cx_class_o));
    if (!Fast_Expression_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Expression'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Expression::forceReference */
    Fast_Expression_forceReference_o = cx_declare(Fast_Expression_o, "forceReference", cx_type(cx_member_o));
    if (!Fast_Expression_forceReference_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Expression::forceReference'.");
        goto error;
    }

    /* Define ::cortex::Fast::Expression::forceReference */
    if (!cx_checkState(Fast_Expression_forceReference_o, CX_DEFINED)) {
        Fast_Expression_forceReference_o->type = cx_resolve_ext(Fast_Expression_forceReference_o, NULL, "::cortex::lang::bool", FALSE, "element ::cortex::Fast::Expression::forceReference.type");
        Fast_Expression_forceReference_o->modifiers = 0x4;
        Fast_Expression_forceReference_o->state = 0x6;
        Fast_Expression_forceReference_o->weak = FALSE;
        Fast_Expression_forceReference_o->id = 2;
        if (cx_define(Fast_Expression_forceReference_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Expression::forceReference'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Expression::isReference */
    Fast_Expression_isReference_o = cx_declare(Fast_Expression_o, "isReference", cx_type(cx_member_o));
    if (!Fast_Expression_isReference_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Expression::isReference'.");
        goto error;
    }

    /* Define ::cortex::Fast::Expression::isReference */
    if (!cx_checkState(Fast_Expression_isReference_o, CX_DEFINED)) {
        Fast_Expression_isReference_o->type = cx_resolve_ext(Fast_Expression_isReference_o, NULL, "::cortex::lang::bool", FALSE, "element ::cortex::Fast::Expression::isReference.type");
        Fast_Expression_isReference_o->modifiers = 0x4;
        Fast_Expression_isReference_o->state = 0x6;
        Fast_Expression_isReference_o->weak = FALSE;
        Fast_Expression_isReference_o->id = 1;
        if (cx_define(Fast_Expression_isReference_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Expression::isReference'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Expression::type */
    Fast_Expression_type_o = cx_declare(Fast_Expression_o, "type", cx_type(cx_member_o));
    if (!Fast_Expression_type_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Expression::type'.");
        goto error;
    }

    /* Define ::cortex::Fast::Comma::expressions */
    if (!cx_checkState(Fast_Comma_expressions_o, CX_DEFINED)) {
        Fast_Comma_expressions_o->type = cx_resolve_ext(Fast_Comma_expressions_o, NULL, "::cortex::lang::list{::cortex::Fast::Expression,0}", FALSE, "element ::cortex::Fast::Comma::expressions.type");
        Fast_Comma_expressions_o->modifiers = 0x2;
        Fast_Comma_expressions_o->state = 0x6;
        Fast_Comma_expressions_o->weak = FALSE;
        Fast_Comma_expressions_o->id = 0;
        if (cx_define(Fast_Comma_expressions_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Comma::expressions'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Expression::cleanList(list{Expression} list) */
    Fast_Expression_cleanList_o = cx_declare(Fast_Expression_o, "cleanList(list{Expression} list)", cx_type(cx_function_o));
    if (!Fast_Expression_cleanList_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Expression::cleanList(list{Expression} list)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Expression::cleanList(list{Expression} list) */
    if (!cx_checkState(Fast_Expression_cleanList_o, CX_DEFINED)) {
        Fast_Expression_cleanList_o->returnType = cx_resolve_ext(Fast_Expression_cleanList_o, NULL, "::cortex::lang::void", FALSE, "element ::cortex::Fast::Expression::cleanList(list{Expression} list).returnType");
        Fast_Expression_cleanList_o->returnsReference = FALSE;
        
        /* Bind ::cortex::Fast::Expression::cleanList(list{Expression} list) with C-function */
        cx_function(Fast_Expression_cleanList_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Expression_cleanList(void *args, void *result);
        cx_function(Fast_Expression_cleanList_o)->impl = (cx_word)__Fast_Expression_cleanList;
        if (cx_define(Fast_Expression_cleanList_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Expression::cleanList(list{Expression} list)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Expression::fromList(list{Expression} list) */
    Fast_Expression_fromList_o = cx_declare(Fast_Expression_o, "fromList(list{Expression} list)", cx_type(cx_function_o));
    if (!Fast_Expression_fromList_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Expression::fromList(list{Expression} list)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Expression::fromList(list{Expression} list) */
    if (!cx_checkState(Fast_Expression_fromList_o, CX_DEFINED)) {
        Fast_Expression_fromList_o->returnType = cx_resolve_ext(Fast_Expression_fromList_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::Expression::fromList(list{Expression} list).returnType");
        Fast_Expression_fromList_o->returnsReference = FALSE;
        
        /* Bind ::cortex::Fast::Expression::fromList(list{Expression} list) with C-function */
        cx_function(Fast_Expression_fromList_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Expression_fromList(void *args, void *result);
        cx_function(Fast_Expression_fromList_o)->impl = (cx_word)__Fast_Expression_fromList;
        if (cx_define(Fast_Expression_fromList_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Expression::fromList(list{Expression} list)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::FloatingPoint */
    Fast_FloatingPoint_o = cx_declare(Fast_o, "FloatingPoint", cx_type(cx_class_o));
    if (!Fast_FloatingPoint_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::FloatingPoint'.");
        goto error;
    }

    /* Declare ::cortex::Fast::FloatingPoint::value */
    Fast_FloatingPoint_value_o = cx_declare(Fast_FloatingPoint_o, "value", cx_type(cx_member_o));
    if (!Fast_FloatingPoint_value_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::FloatingPoint::value'.");
        goto error;
    }

    /* Define ::cortex::Fast::FloatingPoint::value */
    if (!cx_checkState(Fast_FloatingPoint_value_o, CX_DEFINED)) {
        Fast_FloatingPoint_value_o->type = cx_resolve_ext(Fast_FloatingPoint_value_o, NULL, "::cortex::lang::float64", FALSE, "element ::cortex::Fast::FloatingPoint::value.type");
        Fast_FloatingPoint_value_o->modifiers = 0x0;
        Fast_FloatingPoint_value_o->state = 0x6;
        Fast_FloatingPoint_value_o->weak = FALSE;
        Fast_FloatingPoint_value_o->id = 0;
        if (cx_define(Fast_FloatingPoint_value_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::FloatingPoint::value'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::If */
    Fast_If_o = cx_declare(Fast_o, "If", cx_type(cx_class_o));
    if (!Fast_If_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::If'.");
        goto error;
    }

    /* Declare ::cortex::Fast::If::condition */
    Fast_If_condition_o = cx_declare(Fast_If_o, "condition", cx_type(cx_member_o));
    if (!Fast_If_condition_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::If::condition'.");
        goto error;
    }

    /* Declare ::cortex::Fast::If::falseBranch */
    Fast_If_falseBranch_o = cx_declare(Fast_If_o, "falseBranch", cx_type(cx_member_o));
    if (!Fast_If_falseBranch_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::If::falseBranch'.");
        goto error;
    }

    /* Declare ::cortex::Fast::If::trueBranch */
    Fast_If_trueBranch_o = cx_declare(Fast_If_o, "trueBranch", cx_type(cx_member_o));
    if (!Fast_If_trueBranch_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::If::trueBranch'.");
        goto error;
    }

    /* Declare ::cortex::Fast::If::warnUnreachable */
    Fast_If_warnUnreachable_o = cx_declare(Fast_If_o, "warnUnreachable", cx_type(cx_member_o));
    if (!Fast_If_warnUnreachable_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::If::warnUnreachable'.");
        goto error;
    }

    /* Define ::cortex::Fast::If::warnUnreachable */
    if (!cx_checkState(Fast_If_warnUnreachable_o, CX_DEFINED)) {
        Fast_If_warnUnreachable_o->type = cx_resolve_ext(Fast_If_warnUnreachable_o, NULL, "::cortex::lang::bool", FALSE, "element ::cortex::Fast::If::warnUnreachable.type");
        Fast_If_warnUnreachable_o->modifiers = 0x3;
        Fast_If_warnUnreachable_o->state = 0x6;
        Fast_If_warnUnreachable_o->weak = FALSE;
        Fast_If_warnUnreachable_o->id = 3;
        if (cx_define(Fast_If_warnUnreachable_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::If::warnUnreachable'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Initializer */
    Fast_Initializer_o = cx_declare(Fast_o, "Initializer", cx_type(cx_class_o));
    if (!Fast_Initializer_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Initializer'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Initializer::fp */
    Fast_Initializer_fp_o = cx_declare(Fast_Initializer_o, "fp", cx_type(cx_member_o));
    if (!Fast_Initializer_fp_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Initializer::fp'.");
        goto error;
    }

    /* Define ::cortex::Fast::Initializer::fp */
    if (!cx_checkState(Fast_Initializer_fp_o, CX_DEFINED)) {
        Fast_Initializer_fp_o->type = cx_resolve_ext(Fast_Initializer_fp_o, NULL, "::cortex::lang::uint8", FALSE, "element ::cortex::Fast::Initializer::fp.type");
        Fast_Initializer_fp_o->modifiers = 0x3;
        Fast_Initializer_fp_o->state = 0x6;
        Fast_Initializer_fp_o->weak = FALSE;
        Fast_Initializer_fp_o->id = 3;
        if (cx_define(Fast_Initializer_fp_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Initializer::fp'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Initializer::frames */
    Fast_Initializer_frames_o = cx_declare(Fast_Initializer_o, "frames", cx_type(cx_member_o));
    if (!Fast_Initializer_frames_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Initializer::frames'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Initializer::variableCount */
    Fast_Initializer_variableCount_o = cx_declare(Fast_Initializer_o, "variableCount", cx_type(cx_member_o));
    if (!Fast_Initializer_variableCount_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Initializer::variableCount'.");
        goto error;
    }

    /* Define ::cortex::Fast::Initializer::variableCount */
    if (!cx_checkState(Fast_Initializer_variableCount_o, CX_DEFINED)) {
        Fast_Initializer_variableCount_o->type = cx_resolve_ext(Fast_Initializer_variableCount_o, NULL, "::cortex::lang::uint8", FALSE, "element ::cortex::Fast::Initializer::variableCount.type");
        Fast_Initializer_variableCount_o->modifiers = 0x0;
        Fast_Initializer_variableCount_o->state = 0x6;
        Fast_Initializer_variableCount_o->weak = FALSE;
        Fast_Initializer_variableCount_o->id = 1;
        if (cx_define(Fast_Initializer_variableCount_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Initializer::variableCount'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Initializer::variables */
    Fast_Initializer_variables_o = cx_declare(Fast_Initializer_o, "variables", cx_type(cx_member_o));
    if (!Fast_Initializer_variables_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Initializer::variables'.");
        goto error;
    }

    /* Declare ::cortex::Fast::InitializerExpression */
    Fast_InitializerExpression_o = cx_declare(Fast_o, "InitializerExpression", cx_type(cx_class_o));
    if (!Fast_InitializerExpression_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::InitializerExpression'.");
        goto error;
    }

    /* Declare ::cortex::Fast::InitializerExpression::assignValue */
    Fast_InitializerExpression_assignValue_o = cx_declare(Fast_InitializerExpression_o, "assignValue", cx_type(cx_member_o));
    if (!Fast_InitializerExpression_assignValue_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::InitializerExpression::assignValue'.");
        goto error;
    }

    /* Define ::cortex::Fast::InitializerExpression::assignValue */
    if (!cx_checkState(Fast_InitializerExpression_assignValue_o, CX_DEFINED)) {
        Fast_InitializerExpression_assignValue_o->type = cx_resolve_ext(Fast_InitializerExpression_assignValue_o, NULL, "::cortex::lang::bool", FALSE, "element ::cortex::Fast::InitializerExpression::assignValue.type");
        Fast_InitializerExpression_assignValue_o->modifiers = 0x0;
        Fast_InitializerExpression_assignValue_o->state = 0x6;
        Fast_InitializerExpression_assignValue_o->weak = FALSE;
        Fast_InitializerExpression_assignValue_o->id = 0;
        if (cx_define(Fast_InitializerExpression_assignValue_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::InitializerExpression::assignValue'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::InitializerExpression::operations */
    Fast_InitializerExpression_operations_o = cx_declare(Fast_InitializerExpression_o, "operations", cx_type(cx_member_o));
    if (!Fast_InitializerExpression_operations_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::InitializerExpression::operations'.");
        goto error;
    }

    /* Declare ::cortex::Fast::InitializerFrame */
    Fast_InitializerFrame_o = cx_declare(Fast_o, "InitializerFrame", cx_type(cx_struct_o));
    if (!Fast_InitializerFrame_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::InitializerFrame'.");
        goto error;
    }

    /* Declare ::cortex::Fast::InitializerFrame::isKey */
    Fast_InitializerFrame_isKey_o = cx_declare(Fast_InitializerFrame_o, "isKey", cx_type(cx_member_o));
    if (!Fast_InitializerFrame_isKey_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::InitializerFrame::isKey'.");
        goto error;
    }

    /* Define ::cortex::Fast::InitializerFrame::isKey */
    if (!cx_checkState(Fast_InitializerFrame_isKey_o, CX_DEFINED)) {
        Fast_InitializerFrame_isKey_o->type = cx_resolve_ext(Fast_InitializerFrame_isKey_o, NULL, "::cortex::lang::bool", FALSE, "element ::cortex::Fast::InitializerFrame::isKey.type");
        Fast_InitializerFrame_isKey_o->modifiers = 0x0;
        Fast_InitializerFrame_isKey_o->state = 0x6;
        Fast_InitializerFrame_isKey_o->weak = FALSE;
        Fast_InitializerFrame_isKey_o->id = 2;
        if (cx_define(Fast_InitializerFrame_isKey_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::InitializerFrame::isKey'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::InitializerFrame::location */
    Fast_InitializerFrame_location_o = cx_declare(Fast_InitializerFrame_o, "location", cx_type(cx_member_o));
    if (!Fast_InitializerFrame_location_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::InitializerFrame::location'.");
        goto error;
    }

    /* Define ::cortex::Fast::InitializerFrame::location */
    if (!cx_checkState(Fast_InitializerFrame_location_o, CX_DEFINED)) {
        Fast_InitializerFrame_location_o->type = cx_resolve_ext(Fast_InitializerFrame_location_o, NULL, "::cortex::lang::uint32", FALSE, "element ::cortex::Fast::InitializerFrame::location.type");
        Fast_InitializerFrame_location_o->modifiers = 0x0;
        Fast_InitializerFrame_location_o->state = 0x6;
        Fast_InitializerFrame_location_o->weak = FALSE;
        Fast_InitializerFrame_location_o->id = 0;
        if (cx_define(Fast_InitializerFrame_location_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::InitializerFrame::location'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::InitializerFrame::member */
    Fast_InitializerFrame_member_o = cx_declare(Fast_InitializerFrame_o, "member", cx_type(cx_member_o));
    if (!Fast_InitializerFrame_member_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::InitializerFrame::member'.");
        goto error;
    }

    /* Define ::cortex::Fast::InitializerFrame::member */
    if (!cx_checkState(Fast_InitializerFrame_member_o, CX_DEFINED)) {
        Fast_InitializerFrame_member_o->type = cx_resolve_ext(Fast_InitializerFrame_member_o, NULL, "::cortex::lang::member", FALSE, "element ::cortex::Fast::InitializerFrame::member.type");
        Fast_InitializerFrame_member_o->modifiers = 0x0;
        Fast_InitializerFrame_member_o->state = 0x6;
        Fast_InitializerFrame_member_o->weak = FALSE;
        Fast_InitializerFrame_member_o->id = 3;
        if (cx_define(Fast_InitializerFrame_member_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::InitializerFrame::member'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::InitializerFrame::type */
    Fast_InitializerFrame_type_o = cx_declare(Fast_InitializerFrame_o, "type", cx_type(cx_member_o));
    if (!Fast_InitializerFrame_type_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::InitializerFrame::type'.");
        goto error;
    }

    /* Define ::cortex::Fast::InitializerFrame::type */
    if (!cx_checkState(Fast_InitializerFrame_type_o, CX_DEFINED)) {
        Fast_InitializerFrame_type_o->type = cx_resolve_ext(Fast_InitializerFrame_type_o, NULL, "::cortex::lang::type", FALSE, "element ::cortex::Fast::InitializerFrame::type.type");
        Fast_InitializerFrame_type_o->modifiers = 0x0;
        Fast_InitializerFrame_type_o->state = 0x6;
        Fast_InitializerFrame_type_o->weak = FALSE;
        Fast_InitializerFrame_type_o->id = 1;
        if (cx_define(Fast_InitializerFrame_type_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::InitializerFrame::type'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::InitializerFrame */
    if (!cx_checkState(Fast_InitializerFrame_o, CX_DEFINED)) {
        cx_type(Fast_InitializerFrame_o)->defaultType = cx_resolve_ext(Fast_InitializerFrame_o, NULL, "::cortex::lang::member", FALSE, "element ::cortex::Fast::InitializerFrame.defaultType");
        cx_type(Fast_InitializerFrame_o)->parentType = NULL;
        cx_type(Fast_InitializerFrame_o)->parentState = 0x0;
        cx_interface(Fast_InitializerFrame_o)->base = NULL;
        Fast_InitializerFrame_o->baseAccess = 0x0;
        if (cx_define(Fast_InitializerFrame_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::InitializerFrame'.");
            goto error;
        }
    }

    if (cx_type(Fast_InitializerFrame_o)->size != sizeof(Fast_InitializerFrame)) {
        cx_error("Fast_load: calculated size '%d' of type '::cortex::Fast::InitializerFrame' doesn't match C-type size '%d'", cx_type(Fast_InitializerFrame_o)->size, sizeof(Fast_InitializerFrame));
    }

    /* Define ::cortex::Fast::Initializer::frames */
    if (!cx_checkState(Fast_Initializer_frames_o, CX_DEFINED)) {
        Fast_Initializer_frames_o->type = cx_resolve_ext(Fast_Initializer_frames_o, NULL, "::cortex::lang::array{::cortex::Fast::InitializerFrame,64,::cortex::Fast::InitializerFrame}", FALSE, "element ::cortex::Fast::Initializer::frames.type");
        Fast_Initializer_frames_o->modifiers = 0x3;
        Fast_Initializer_frames_o->state = 0x6;
        Fast_Initializer_frames_o->weak = FALSE;
        Fast_Initializer_frames_o->id = 2;
        if (cx_define(Fast_Initializer_frames_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Initializer::frames'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::InitializerKind */
    Fast_InitializerKind_o = cx_declare(Fast_o, "InitializerKind", cx_type(cx_enum_o));
    if (!Fast_InitializerKind_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::InitializerKind'.");
        goto error;
    }

    /* Declare ::cortex::Fast::InitializerKind::InitDynamic */
    Fast_InitializerKind_InitDynamic_o = cx_declare(Fast_InitializerKind_o, "InitDynamic", cx_type(cx_constant_o));
    if (!Fast_InitializerKind_InitDynamic_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::InitializerKind::InitDynamic'.");
        goto error;
    }

    /* Define ::cortex::Fast::InitializerKind::InitDynamic */
    if (!cx_checkState(Fast_InitializerKind_InitDynamic_o, CX_DEFINED)) {
        if (cx_define(Fast_InitializerKind_InitDynamic_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::InitializerKind::InitDynamic'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::InitializerKind::InitExpression */
    Fast_InitializerKind_InitExpression_o = cx_declare(Fast_InitializerKind_o, "InitExpression", cx_type(cx_constant_o));
    if (!Fast_InitializerKind_InitExpression_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::InitializerKind::InitExpression'.");
        goto error;
    }

    /* Define ::cortex::Fast::InitializerKind::InitExpression */
    if (!cx_checkState(Fast_InitializerKind_InitExpression_o, CX_DEFINED)) {
        if (cx_define(Fast_InitializerKind_InitExpression_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::InitializerKind::InitExpression'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::InitializerKind::InitStatic */
    Fast_InitializerKind_InitStatic_o = cx_declare(Fast_InitializerKind_o, "InitStatic", cx_type(cx_constant_o));
    if (!Fast_InitializerKind_InitStatic_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::InitializerKind::InitStatic'.");
        goto error;
    }

    /* Define ::cortex::Fast::InitializerKind::InitStatic */
    if (!cx_checkState(Fast_InitializerKind_InitStatic_o, CX_DEFINED)) {
        if (cx_define(Fast_InitializerKind_InitStatic_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::InitializerKind::InitStatic'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::InitializerKind */
    if (!cx_checkState(Fast_InitializerKind_o, CX_DEFINED)) {
        if (cx_define(Fast_InitializerKind_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::InitializerKind'.");
            goto error;
        }
    }

    if (cx_type(Fast_InitializerKind_o)->size != sizeof(Fast_InitializerKind)) {
        cx_error("Fast_load: calculated size '%d' of type '::cortex::Fast::InitializerKind' doesn't match C-type size '%d'", cx_type(Fast_InitializerKind_o)->size, sizeof(Fast_InitializerKind));
    }

    /* Declare ::cortex::Fast::InitializerVariable */
    Fast_InitializerVariable_o = cx_declare(Fast_o, "InitializerVariable", cx_type(cx_struct_o));
    if (!Fast_InitializerVariable_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::InitializerVariable'.");
        goto error;
    }

    /* Declare ::cortex::Fast::InitializerVariable::key */
    Fast_InitializerVariable_key_o = cx_declare(Fast_InitializerVariable_o, "key", cx_type(cx_member_o));
    if (!Fast_InitializerVariable_key_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::InitializerVariable::key'.");
        goto error;
    }

    /* Define ::cortex::Fast::InitializerVariable::key */
    if (!cx_checkState(Fast_InitializerVariable_key_o, CX_DEFINED)) {
        Fast_InitializerVariable_key_o->type = cx_resolve_ext(Fast_InitializerVariable_key_o, NULL, "::cortex::lang::word", FALSE, "element ::cortex::Fast::InitializerVariable::key.type");
        Fast_InitializerVariable_key_o->modifiers = 0x0;
        Fast_InitializerVariable_key_o->state = 0x6;
        Fast_InitializerVariable_key_o->weak = FALSE;
        Fast_InitializerVariable_key_o->id = 2;
        if (cx_define(Fast_InitializerVariable_key_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::InitializerVariable::key'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::InitializerVariable::object */
    Fast_InitializerVariable_object_o = cx_declare(Fast_InitializerVariable_o, "object", cx_type(cx_member_o));
    if (!Fast_InitializerVariable_object_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::InitializerVariable::object'.");
        goto error;
    }

    /* Declare ::cortex::Fast::InitializerVariable::offset */
    Fast_InitializerVariable_offset_o = cx_declare(Fast_InitializerVariable_o, "offset", cx_type(cx_member_o));
    if (!Fast_InitializerVariable_offset_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::InitializerVariable::offset'.");
        goto error;
    }

    /* Define ::cortex::Fast::InitializerVariable::offset */
    if (!cx_checkState(Fast_InitializerVariable_offset_o, CX_DEFINED)) {
        Fast_InitializerVariable_offset_o->type = cx_resolve_ext(Fast_InitializerVariable_offset_o, NULL, "::cortex::lang::word", FALSE, "element ::cortex::Fast::InitializerVariable::offset.type");
        Fast_InitializerVariable_offset_o->modifiers = 0x0;
        Fast_InitializerVariable_offset_o->state = 0x6;
        Fast_InitializerVariable_offset_o->weak = FALSE;
        Fast_InitializerVariable_offset_o->id = 0;
        if (cx_define(Fast_InitializerVariable_offset_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::InitializerVariable::offset'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::InitOper */
    Fast_InitOper_o = cx_declare(Fast_o, "InitOper", cx_type(cx_struct_o));
    if (!Fast_InitOper_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::InitOper'.");
        goto error;
    }

    /* Declare ::cortex::Fast::InitOper::expr */
    Fast_InitOper_expr_o = cx_declare(Fast_InitOper_o, "expr", cx_type(cx_member_o));
    if (!Fast_InitOper_expr_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::InitOper::expr'.");
        goto error;
    }

    /* Declare ::cortex::Fast::InitOper::kind */
    Fast_InitOper_kind_o = cx_declare(Fast_InitOper_o, "kind", cx_type(cx_member_o));
    if (!Fast_InitOper_kind_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::InitOper::kind'.");
        goto error;
    }

    /* Declare ::cortex::Fast::InitOper::name */
    Fast_InitOper_name_o = cx_declare(Fast_InitOper_o, "name", cx_type(cx_member_o));
    if (!Fast_InitOper_name_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::InitOper::name'.");
        goto error;
    }

    /* Define ::cortex::Fast::InitOper::name */
    if (!cx_checkState(Fast_InitOper_name_o, CX_DEFINED)) {
        Fast_InitOper_name_o->type = cx_resolve_ext(Fast_InitOper_name_o, NULL, "::cortex::lang::string", FALSE, "element ::cortex::Fast::InitOper::name.type");
        Fast_InitOper_name_o->modifiers = 0x0;
        Fast_InitOper_name_o->state = 0x6;
        Fast_InitOper_name_o->weak = FALSE;
        Fast_InitOper_name_o->id = 2;
        if (cx_define(Fast_InitOper_name_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::InitOper::name'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::InitializerExpression::operations */
    if (!cx_checkState(Fast_InitializerExpression_operations_o, CX_DEFINED)) {
        Fast_InitializerExpression_operations_o->type = cx_resolve_ext(Fast_InitializerExpression_operations_o, NULL, "::cortex::lang::list{::cortex::Fast::InitOper,0}", FALSE, "element ::cortex::Fast::InitializerExpression::operations.type");
        Fast_InitializerExpression_operations_o->modifiers = 0x3;
        Fast_InitializerExpression_operations_o->state = 0x6;
        Fast_InitializerExpression_operations_o->weak = FALSE;
        Fast_InitializerExpression_operations_o->id = 1;
        if (cx_define(Fast_InitializerExpression_operations_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::InitializerExpression::operations'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::InitOperKind */
    Fast_InitOperKind_o = cx_declare(Fast_o, "InitOperKind", cx_type(cx_enum_o));
    if (!Fast_InitOperKind_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::InitOperKind'.");
        goto error;
    }

    /* Declare ::cortex::Fast::InitOperKind::InitDefine */
    Fast_InitOperKind_InitDefine_o = cx_declare(Fast_InitOperKind_o, "InitDefine", cx_type(cx_constant_o));
    if (!Fast_InitOperKind_InitDefine_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::InitOperKind::InitDefine'.");
        goto error;
    }

    /* Define ::cortex::Fast::InitOperKind::InitDefine */
    if (!cx_checkState(Fast_InitOperKind_InitDefine_o, CX_DEFINED)) {
        if (cx_define(Fast_InitOperKind_InitDefine_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::InitOperKind::InitDefine'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::InitOperKind::InitMember */
    Fast_InitOperKind_InitMember_o = cx_declare(Fast_InitOperKind_o, "InitMember", cx_type(cx_constant_o));
    if (!Fast_InitOperKind_InitMember_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::InitOperKind::InitMember'.");
        goto error;
    }

    /* Define ::cortex::Fast::InitOperKind::InitMember */
    if (!cx_checkState(Fast_InitOperKind_InitMember_o, CX_DEFINED)) {
        if (cx_define(Fast_InitOperKind_InitMember_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::InitOperKind::InitMember'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::InitOperKind::InitPop */
    Fast_InitOperKind_InitPop_o = cx_declare(Fast_InitOperKind_o, "InitPop", cx_type(cx_constant_o));
    if (!Fast_InitOperKind_InitPop_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::InitOperKind::InitPop'.");
        goto error;
    }

    /* Define ::cortex::Fast::InitOperKind::InitPop */
    if (!cx_checkState(Fast_InitOperKind_InitPop_o, CX_DEFINED)) {
        if (cx_define(Fast_InitOperKind_InitPop_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::InitOperKind::InitPop'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::InitOperKind::InitPush */
    Fast_InitOperKind_InitPush_o = cx_declare(Fast_InitOperKind_o, "InitPush", cx_type(cx_constant_o));
    if (!Fast_InitOperKind_InitPush_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::InitOperKind::InitPush'.");
        goto error;
    }

    /* Define ::cortex::Fast::InitOperKind::InitPush */
    if (!cx_checkState(Fast_InitOperKind_InitPush_o, CX_DEFINED)) {
        if (cx_define(Fast_InitOperKind_InitPush_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::InitOperKind::InitPush'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::InitOperKind::InitValue */
    Fast_InitOperKind_InitValue_o = cx_declare(Fast_InitOperKind_o, "InitValue", cx_type(cx_constant_o));
    if (!Fast_InitOperKind_InitValue_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::InitOperKind::InitValue'.");
        goto error;
    }

    /* Define ::cortex::Fast::InitOperKind::InitValue */
    if (!cx_checkState(Fast_InitOperKind_InitValue_o, CX_DEFINED)) {
        if (cx_define(Fast_InitOperKind_InitValue_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::InitOperKind::InitValue'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::InitOperKind */
    if (!cx_checkState(Fast_InitOperKind_o, CX_DEFINED)) {
        if (cx_define(Fast_InitOperKind_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::InitOperKind'.");
            goto error;
        }
    }

    if (cx_type(Fast_InitOperKind_o)->size != sizeof(Fast_InitOperKind)) {
        cx_error("Fast_load: calculated size '%d' of type '::cortex::Fast::InitOperKind' doesn't match C-type size '%d'", cx_type(Fast_InitOperKind_o)->size, sizeof(Fast_InitOperKind));
    }

    /* Define ::cortex::Fast::InitOper::kind */
    if (!cx_checkState(Fast_InitOper_kind_o, CX_DEFINED)) {
        Fast_InitOper_kind_o->type = cx_resolve_ext(Fast_InitOper_kind_o, NULL, "::cortex::Fast::InitOperKind", FALSE, "element ::cortex::Fast::InitOper::kind.type");
        Fast_InitOper_kind_o->modifiers = 0x0;
        Fast_InitOper_kind_o->state = 0x6;
        Fast_InitOper_kind_o->weak = FALSE;
        Fast_InitOper_kind_o->id = 0;
        if (cx_define(Fast_InitOper_kind_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::InitOper::kind'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Integer */
    Fast_Integer_o = cx_declare(Fast_o, "Integer", cx_type(cx_class_o));
    if (!Fast_Integer_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Integer'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Integer::value */
    Fast_Integer_value_o = cx_declare(Fast_Integer_o, "value", cx_type(cx_member_o));
    if (!Fast_Integer_value_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Integer::value'.");
        goto error;
    }

    /* Define ::cortex::Fast::Integer::value */
    if (!cx_checkState(Fast_Integer_value_o, CX_DEFINED)) {
        Fast_Integer_value_o->type = cx_resolve_ext(Fast_Integer_value_o, NULL, "::cortex::lang::uint64", FALSE, "element ::cortex::Fast::Integer::value.type");
        Fast_Integer_value_o->modifiers = 0x0;
        Fast_Integer_value_o->state = 0x6;
        Fast_Integer_value_o->weak = FALSE;
        Fast_Integer_value_o->id = 0;
        if (cx_define(Fast_Integer_value_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Integer::value'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Literal */
    Fast_Literal_o = cx_declare(Fast_o, "Literal", cx_type(cx_class_o));
    if (!Fast_Literal_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Literal'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Literal::kind */
    Fast_Literal_kind_o = cx_declare(Fast_Literal_o, "kind", cx_type(cx_member_o));
    if (!Fast_Literal_kind_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Literal::kind'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Local */
    Fast_Local_o = cx_declare(Fast_o, "Local", cx_type(cx_class_o));
    if (!Fast_Local_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Local'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Local::kind */
    Fast_Local_kind_o = cx_declare(Fast_Local_o, "kind", cx_type(cx_member_o));
    if (!Fast_Local_kind_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Local::kind'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Local::name */
    Fast_Local_name_o = cx_declare(Fast_Local_o, "name", cx_type(cx_member_o));
    if (!Fast_Local_name_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Local::name'.");
        goto error;
    }

    /* Define ::cortex::Fast::Local::name */
    if (!cx_checkState(Fast_Local_name_o, CX_DEFINED)) {
        Fast_Local_name_o->type = cx_resolve_ext(Fast_Local_name_o, NULL, "::cortex::lang::string", FALSE, "element ::cortex::Fast::Local::name.type");
        Fast_Local_name_o->modifiers = 0x0;
        Fast_Local_name_o->state = 0x6;
        Fast_Local_name_o->weak = FALSE;
        Fast_Local_name_o->id = 0;
        if (cx_define(Fast_Local_name_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Local::name'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Local::reference */
    Fast_Local_reference_o = cx_declare(Fast_Local_o, "reference", cx_type(cx_member_o));
    if (!Fast_Local_reference_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Local::reference'.");
        goto error;
    }

    /* Define ::cortex::Fast::Local::reference */
    if (!cx_checkState(Fast_Local_reference_o, CX_DEFINED)) {
        Fast_Local_reference_o->type = cx_resolve_ext(Fast_Local_reference_o, NULL, "::cortex::lang::bool", FALSE, "element ::cortex::Fast::Local::reference.type");
        Fast_Local_reference_o->modifiers = 0x0;
        Fast_Local_reference_o->state = 0x6;
        Fast_Local_reference_o->weak = FALSE;
        Fast_Local_reference_o->id = 3;
        if (cx_define(Fast_Local_reference_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Local::reference'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Local::type */
    Fast_Local_type_o = cx_declare(Fast_Local_o, "type", cx_type(cx_member_o));
    if (!Fast_Local_type_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Local::type'.");
        goto error;
    }

    /* Define ::cortex::Fast::Block::locals */
    if (!cx_checkState(Fast_Block_locals_o, CX_DEFINED)) {
        Fast_Block_locals_o->type = cx_resolve_ext(Fast_Block_locals_o, NULL, "::cortex::lang::list{::cortex::Fast::Local,0}", FALSE, "element ::cortex::Fast::Block::locals.type");
        Fast_Block_locals_o->modifiers = 0x3;
        Fast_Block_locals_o->state = 0x6;
        Fast_Block_locals_o->weak = FALSE;
        Fast_Block_locals_o->id = 2;
        if (cx_define(Fast_Block_locals_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Block::locals'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::LocalKind */
    Fast_LocalKind_o = cx_declare(Fast_o, "LocalKind", cx_type(cx_enum_o));
    if (!Fast_LocalKind_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::LocalKind'.");
        goto error;
    }

    /* Declare ::cortex::Fast::LocalKind::LocalDefault */
    Fast_LocalKind_LocalDefault_o = cx_declare(Fast_LocalKind_o, "LocalDefault", cx_type(cx_constant_o));
    if (!Fast_LocalKind_LocalDefault_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::LocalKind::LocalDefault'.");
        goto error;
    }

    /* Define ::cortex::Fast::LocalKind::LocalDefault */
    if (!cx_checkState(Fast_LocalKind_LocalDefault_o, CX_DEFINED)) {
        if (cx_define(Fast_LocalKind_LocalDefault_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::LocalKind::LocalDefault'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::LocalKind::LocalParameter */
    Fast_LocalKind_LocalParameter_o = cx_declare(Fast_LocalKind_o, "LocalParameter", cx_type(cx_constant_o));
    if (!Fast_LocalKind_LocalParameter_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::LocalKind::LocalParameter'.");
        goto error;
    }

    /* Define ::cortex::Fast::LocalKind::LocalParameter */
    if (!cx_checkState(Fast_LocalKind_LocalParameter_o, CX_DEFINED)) {
        if (cx_define(Fast_LocalKind_LocalParameter_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::LocalKind::LocalParameter'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::LocalKind::LocalReturn */
    Fast_LocalKind_LocalReturn_o = cx_declare(Fast_LocalKind_o, "LocalReturn", cx_type(cx_constant_o));
    if (!Fast_LocalKind_LocalReturn_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::LocalKind::LocalReturn'.");
        goto error;
    }

    /* Define ::cortex::Fast::LocalKind::LocalReturn */
    if (!cx_checkState(Fast_LocalKind_LocalReturn_o, CX_DEFINED)) {
        if (cx_define(Fast_LocalKind_LocalReturn_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::LocalKind::LocalReturn'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::LocalKind */
    if (!cx_checkState(Fast_LocalKind_o, CX_DEFINED)) {
        if (cx_define(Fast_LocalKind_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::LocalKind'.");
            goto error;
        }
    }

    if (cx_type(Fast_LocalKind_o)->size != sizeof(Fast_LocalKind)) {
        cx_error("Fast_load: calculated size '%d' of type '::cortex::Fast::LocalKind' doesn't match C-type size '%d'", cx_type(Fast_LocalKind_o)->size, sizeof(Fast_LocalKind));
    }

    /* Define ::cortex::Fast::Local::kind */
    if (!cx_checkState(Fast_Local_kind_o, CX_DEFINED)) {
        Fast_Local_kind_o->type = cx_resolve_ext(Fast_Local_kind_o, NULL, "::cortex::Fast::LocalKind", FALSE, "element ::cortex::Fast::Local::kind.type");
        Fast_Local_kind_o->modifiers = 0x0;
        Fast_Local_kind_o->state = 0x6;
        Fast_Local_kind_o->weak = FALSE;
        Fast_Local_kind_o->id = 2;
        if (cx_define(Fast_Local_kind_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Local::kind'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Lvalue */
    Fast_Lvalue_o = cx_declare(Fast_o, "Lvalue", cx_type(cx_struct_o));
    if (!Fast_Lvalue_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Lvalue'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Lvalue::expr */
    Fast_Lvalue_expr_o = cx_declare(Fast_Lvalue_o, "expr", cx_type(cx_member_o));
    if (!Fast_Lvalue_expr_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Lvalue::expr'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Lvalue::isAssignment */
    Fast_Lvalue_isAssignment_o = cx_declare(Fast_Lvalue_o, "isAssignment", cx_type(cx_member_o));
    if (!Fast_Lvalue_isAssignment_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Lvalue::isAssignment'.");
        goto error;
    }

    /* Define ::cortex::Fast::Lvalue::isAssignment */
    if (!cx_checkState(Fast_Lvalue_isAssignment_o, CX_DEFINED)) {
        Fast_Lvalue_isAssignment_o->type = cx_resolve_ext(Fast_Lvalue_isAssignment_o, NULL, "::cortex::lang::bool", FALSE, "element ::cortex::Fast::Lvalue::isAssignment.type");
        Fast_Lvalue_isAssignment_o->modifiers = 0x0;
        Fast_Lvalue_isAssignment_o->state = 0x6;
        Fast_Lvalue_isAssignment_o->weak = FALSE;
        Fast_Lvalue_isAssignment_o->id = 1;
        if (cx_define(Fast_Lvalue_isAssignment_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Lvalue::isAssignment'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Member */
    Fast_Member_o = cx_declare(Fast_o, "Member", cx_type(cx_class_o));
    if (!Fast_Member_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Member'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Member::lvalue */
    Fast_Member_lvalue_o = cx_declare(Fast_Member_o, "lvalue", cx_type(cx_member_o));
    if (!Fast_Member_lvalue_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Member::lvalue'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Member::member */
    Fast_Member_member_o = cx_declare(Fast_Member_o, "member", cx_type(cx_member_o));
    if (!Fast_Member_member_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Member::member'.");
        goto error;
    }

    /* Define ::cortex::Fast::Member::member */
    if (!cx_checkState(Fast_Member_member_o, CX_DEFINED)) {
        Fast_Member_member_o->type = cx_resolve_ext(Fast_Member_member_o, NULL, "::cortex::lang::object", FALSE, "element ::cortex::Fast::Member::member.type");
        Fast_Member_member_o->modifiers = 0x2;
        Fast_Member_member_o->state = 0x6;
        Fast_Member_member_o->weak = FALSE;
        Fast_Member_member_o->id = 3;
        if (cx_define(Fast_Member_member_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Member::member'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Member::rvalue */
    Fast_Member_rvalue_o = cx_declare(Fast_Member_o, "rvalue", cx_type(cx_member_o));
    if (!Fast_Member_rvalue_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Member::rvalue'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Member::superMember */
    Fast_Member_superMember_o = cx_declare(Fast_Member_o, "superMember", cx_type(cx_member_o));
    if (!Fast_Member_superMember_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Member::superMember'.");
        goto error;
    }

    /* Define ::cortex::Fast::Member::superMember */
    if (!cx_checkState(Fast_Member_superMember_o, CX_DEFINED)) {
        Fast_Member_superMember_o->type = cx_resolve_ext(Fast_Member_superMember_o, NULL, "::cortex::lang::bool", FALSE, "element ::cortex::Fast::Member::superMember.type");
        Fast_Member_superMember_o->modifiers = 0x4;
        Fast_Member_superMember_o->state = 0x6;
        Fast_Member_superMember_o->weak = FALSE;
        Fast_Member_superMember_o->id = 2;
        if (cx_define(Fast_Member_superMember_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Member::superMember'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::New */
    Fast_New_o = cx_declare(Fast_o, "New", cx_type(cx_class_o));
    if (!Fast_New_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::New'.");
        goto error;
    }

    /* Declare ::cortex::Fast::New::attributes */
    Fast_New_attributes_o = cx_declare(Fast_New_o, "attributes", cx_type(cx_member_o));
    if (!Fast_New_attributes_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::New::attributes'.");
        goto error;
    }

    /* Declare ::cortex::Fast::New::type */
    Fast_New_type_o = cx_declare(Fast_New_o, "type", cx_type(cx_member_o));
    if (!Fast_New_type_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::New::type'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Node */
    Fast_Node_o = cx_declare(Fast_o, "Node", cx_type(cx_class_o));
    if (!Fast_Node_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Node'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Node::column */
    Fast_Node_column_o = cx_declare(Fast_Node_o, "column", cx_type(cx_member_o));
    if (!Fast_Node_column_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Node::column'.");
        goto error;
    }

    /* Define ::cortex::Fast::Node::column */
    if (!cx_checkState(Fast_Node_column_o, CX_DEFINED)) {
        Fast_Node_column_o->type = cx_resolve_ext(Fast_Node_column_o, NULL, "::cortex::lang::uint32", FALSE, "element ::cortex::Fast::Node::column.type");
        Fast_Node_column_o->modifiers = 0x4;
        Fast_Node_column_o->state = 0x6;
        Fast_Node_column_o->weak = FALSE;
        Fast_Node_column_o->id = 2;
        if (cx_define(Fast_Node_column_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Node::column'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Node::init() */
    Fast_Node_init_o = cx_declare(Fast_Node_o, "init()", cx_type(cx_method_o));
    if (!Fast_Node_init_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Node::init()'.");
        goto error;
    }

    /* Define ::cortex::Fast::Node::init() */
    if (!cx_checkState(Fast_Node_init_o, CX_DEFINED)) {
        cx_function(Fast_Node_init_o)->returnType = cx_resolve_ext(Fast_Node_init_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::Node::init().returnType");
        cx_function(Fast_Node_init_o)->returnsReference = FALSE;
        Fast_Node_init_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Node::init() with C-function */
        cx_function(Fast_Node_init_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Node_init(void *args, void *result);
        cx_function(Fast_Node_init_o)->impl = (cx_word)__Fast_Node_init;
        if (cx_define(Fast_Node_init_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Node::init()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Node::kind */
    Fast_Node_kind_o = cx_declare(Fast_Node_o, "kind", cx_type(cx_member_o));
    if (!Fast_Node_kind_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Node::kind'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Node::line */
    Fast_Node_line_o = cx_declare(Fast_Node_o, "line", cx_type(cx_member_o));
    if (!Fast_Node_line_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Node::line'.");
        goto error;
    }

    /* Define ::cortex::Fast::Node::line */
    if (!cx_checkState(Fast_Node_line_o, CX_DEFINED)) {
        Fast_Node_line_o->type = cx_resolve_ext(Fast_Node_line_o, NULL, "::cortex::lang::uint32", FALSE, "element ::cortex::Fast::Node::line.type");
        Fast_Node_line_o->modifiers = 0x4;
        Fast_Node_line_o->state = 0x6;
        Fast_Node_line_o->weak = FALSE;
        Fast_Node_line_o->id = 1;
        if (cx_define(Fast_Node_line_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Node::line'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::Block::statements */
    if (!cx_checkState(Fast_Block_statements_o, CX_DEFINED)) {
        Fast_Block_statements_o->type = cx_resolve_ext(Fast_Block_statements_o, NULL, "::cortex::lang::list{::cortex::Fast::Node,0}", FALSE, "element ::cortex::Fast::Block::statements.type");
        Fast_Block_statements_o->modifiers = 0x3;
        Fast_Block_statements_o->state = 0x6;
        Fast_Block_statements_o->weak = FALSE;
        Fast_Block_statements_o->id = 1;
        if (cx_define(Fast_Block_statements_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Block::statements'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::nodeKind */
    Fast_nodeKind_o = cx_declare(Fast_o, "nodeKind", cx_type(cx_enum_o));
    if (!Fast_nodeKind_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::nodeKind'.");
        goto error;
    }

    /* Declare ::cortex::Fast::nodeKind::BinaryExpr */
    Fast_nodeKind_BinaryExpr_o = cx_declare(Fast_nodeKind_o, "BinaryExpr", cx_type(cx_constant_o));
    if (!Fast_nodeKind_BinaryExpr_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::nodeKind::BinaryExpr'.");
        goto error;
    }

    /* Define ::cortex::Fast::nodeKind::BinaryExpr */
    if (!cx_checkState(Fast_nodeKind_BinaryExpr_o, CX_DEFINED)) {
        if (cx_define(Fast_nodeKind_BinaryExpr_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::nodeKind::BinaryExpr'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::nodeKind::CallExpr */
    Fast_nodeKind_CallExpr_o = cx_declare(Fast_nodeKind_o, "CallExpr", cx_type(cx_constant_o));
    if (!Fast_nodeKind_CallExpr_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::nodeKind::CallExpr'.");
        goto error;
    }

    /* Define ::cortex::Fast::nodeKind::CallExpr */
    if (!cx_checkState(Fast_nodeKind_CallExpr_o, CX_DEFINED)) {
        if (cx_define(Fast_nodeKind_CallExpr_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::nodeKind::CallExpr'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::nodeKind::CastExpr */
    Fast_nodeKind_CastExpr_o = cx_declare(Fast_nodeKind_o, "CastExpr", cx_type(cx_constant_o));
    if (!Fast_nodeKind_CastExpr_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::nodeKind::CastExpr'.");
        goto error;
    }

    /* Define ::cortex::Fast::nodeKind::CastExpr */
    if (!cx_checkState(Fast_nodeKind_CastExpr_o, CX_DEFINED)) {
        if (cx_define(Fast_nodeKind_CastExpr_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::nodeKind::CastExpr'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::nodeKind::CommaExpr */
    Fast_nodeKind_CommaExpr_o = cx_declare(Fast_nodeKind_o, "CommaExpr", cx_type(cx_constant_o));
    if (!Fast_nodeKind_CommaExpr_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::nodeKind::CommaExpr'.");
        goto error;
    }

    /* Define ::cortex::Fast::nodeKind::CommaExpr */
    if (!cx_checkState(Fast_nodeKind_CommaExpr_o, CX_DEFINED)) {
        if (cx_define(Fast_nodeKind_CommaExpr_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::nodeKind::CommaExpr'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::nodeKind::DeclarationExpr */
    Fast_nodeKind_DeclarationExpr_o = cx_declare(Fast_nodeKind_o, "DeclarationExpr", cx_type(cx_constant_o));
    if (!Fast_nodeKind_DeclarationExpr_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::nodeKind::DeclarationExpr'.");
        goto error;
    }

    /* Define ::cortex::Fast::nodeKind::DeclarationExpr */
    if (!cx_checkState(Fast_nodeKind_DeclarationExpr_o, CX_DEFINED)) {
        if (cx_define(Fast_nodeKind_DeclarationExpr_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::nodeKind::DeclarationExpr'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::nodeKind::DeclareExpr */
    Fast_nodeKind_DeclareExpr_o = cx_declare(Fast_nodeKind_o, "DeclareExpr", cx_type(cx_constant_o));
    if (!Fast_nodeKind_DeclareExpr_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::nodeKind::DeclareExpr'.");
        goto error;
    }

    /* Define ::cortex::Fast::nodeKind::DeclareExpr */
    if (!cx_checkState(Fast_nodeKind_DeclareExpr_o, CX_DEFINED)) {
        if (cx_define(Fast_nodeKind_DeclareExpr_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::nodeKind::DeclareExpr'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::nodeKind::DefineExpr */
    Fast_nodeKind_DefineExpr_o = cx_declare(Fast_nodeKind_o, "DefineExpr", cx_type(cx_constant_o));
    if (!Fast_nodeKind_DefineExpr_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::nodeKind::DefineExpr'.");
        goto error;
    }

    /* Define ::cortex::Fast::nodeKind::DefineExpr */
    if (!cx_checkState(Fast_nodeKind_DefineExpr_o, CX_DEFINED)) {
        if (cx_define(Fast_nodeKind_DefineExpr_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::nodeKind::DefineExpr'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::nodeKind::ElementExpr */
    Fast_nodeKind_ElementExpr_o = cx_declare(Fast_nodeKind_o, "ElementExpr", cx_type(cx_constant_o));
    if (!Fast_nodeKind_ElementExpr_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::nodeKind::ElementExpr'.");
        goto error;
    }

    /* Define ::cortex::Fast::nodeKind::ElementExpr */
    if (!cx_checkState(Fast_nodeKind_ElementExpr_o, CX_DEFINED)) {
        if (cx_define(Fast_nodeKind_ElementExpr_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::nodeKind::ElementExpr'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::nodeKind::IfExpr */
    Fast_nodeKind_IfExpr_o = cx_declare(Fast_nodeKind_o, "IfExpr", cx_type(cx_constant_o));
    if (!Fast_nodeKind_IfExpr_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::nodeKind::IfExpr'.");
        goto error;
    }

    /* Define ::cortex::Fast::nodeKind::IfExpr */
    if (!cx_checkState(Fast_nodeKind_IfExpr_o, CX_DEFINED)) {
        if (cx_define(Fast_nodeKind_IfExpr_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::nodeKind::IfExpr'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::nodeKind::InitializerExpr */
    Fast_nodeKind_InitializerExpr_o = cx_declare(Fast_nodeKind_o, "InitializerExpr", cx_type(cx_constant_o));
    if (!Fast_nodeKind_InitializerExpr_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::nodeKind::InitializerExpr'.");
        goto error;
    }

    /* Define ::cortex::Fast::nodeKind::InitializerExpr */
    if (!cx_checkState(Fast_nodeKind_InitializerExpr_o, CX_DEFINED)) {
        if (cx_define(Fast_nodeKind_InitializerExpr_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::nodeKind::InitializerExpr'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::nodeKind::LiteralExpr */
    Fast_nodeKind_LiteralExpr_o = cx_declare(Fast_nodeKind_o, "LiteralExpr", cx_type(cx_constant_o));
    if (!Fast_nodeKind_LiteralExpr_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::nodeKind::LiteralExpr'.");
        goto error;
    }

    /* Define ::cortex::Fast::nodeKind::LiteralExpr */
    if (!cx_checkState(Fast_nodeKind_LiteralExpr_o, CX_DEFINED)) {
        if (cx_define(Fast_nodeKind_LiteralExpr_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::nodeKind::LiteralExpr'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::nodeKind::MemberExpr */
    Fast_nodeKind_MemberExpr_o = cx_declare(Fast_nodeKind_o, "MemberExpr", cx_type(cx_constant_o));
    if (!Fast_nodeKind_MemberExpr_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::nodeKind::MemberExpr'.");
        goto error;
    }

    /* Define ::cortex::Fast::nodeKind::MemberExpr */
    if (!cx_checkState(Fast_nodeKind_MemberExpr_o, CX_DEFINED)) {
        if (cx_define(Fast_nodeKind_MemberExpr_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::nodeKind::MemberExpr'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::nodeKind::MethodExpr */
    Fast_nodeKind_MethodExpr_o = cx_declare(Fast_nodeKind_o, "MethodExpr", cx_type(cx_constant_o));
    if (!Fast_nodeKind_MethodExpr_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::nodeKind::MethodExpr'.");
        goto error;
    }

    /* Define ::cortex::Fast::nodeKind::MethodExpr */
    if (!cx_checkState(Fast_nodeKind_MethodExpr_o, CX_DEFINED)) {
        if (cx_define(Fast_nodeKind_MethodExpr_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::nodeKind::MethodExpr'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::nodeKind::NewExpr */
    Fast_nodeKind_NewExpr_o = cx_declare(Fast_nodeKind_o, "NewExpr", cx_type(cx_constant_o));
    if (!Fast_nodeKind_NewExpr_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::nodeKind::NewExpr'.");
        goto error;
    }

    /* Define ::cortex::Fast::nodeKind::NewExpr */
    if (!cx_checkState(Fast_nodeKind_NewExpr_o, CX_DEFINED)) {
        if (cx_define(Fast_nodeKind_NewExpr_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::nodeKind::NewExpr'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::nodeKind::PostfixExpr */
    Fast_nodeKind_PostfixExpr_o = cx_declare(Fast_nodeKind_o, "PostfixExpr", cx_type(cx_constant_o));
    if (!Fast_nodeKind_PostfixExpr_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::nodeKind::PostfixExpr'.");
        goto error;
    }

    /* Define ::cortex::Fast::nodeKind::PostfixExpr */
    if (!cx_checkState(Fast_nodeKind_PostfixExpr_o, CX_DEFINED)) {
        if (cx_define(Fast_nodeKind_PostfixExpr_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::nodeKind::PostfixExpr'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::nodeKind::TernaryExpr */
    Fast_nodeKind_TernaryExpr_o = cx_declare(Fast_nodeKind_o, "TernaryExpr", cx_type(cx_constant_o));
    if (!Fast_nodeKind_TernaryExpr_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::nodeKind::TernaryExpr'.");
        goto error;
    }

    /* Define ::cortex::Fast::nodeKind::TernaryExpr */
    if (!cx_checkState(Fast_nodeKind_TernaryExpr_o, CX_DEFINED)) {
        if (cx_define(Fast_nodeKind_TernaryExpr_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::nodeKind::TernaryExpr'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::nodeKind::UnaryExpr */
    Fast_nodeKind_UnaryExpr_o = cx_declare(Fast_nodeKind_o, "UnaryExpr", cx_type(cx_constant_o));
    if (!Fast_nodeKind_UnaryExpr_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::nodeKind::UnaryExpr'.");
        goto error;
    }

    /* Define ::cortex::Fast::nodeKind::UnaryExpr */
    if (!cx_checkState(Fast_nodeKind_UnaryExpr_o, CX_DEFINED)) {
        if (cx_define(Fast_nodeKind_UnaryExpr_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::nodeKind::UnaryExpr'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::nodeKind::UpdateExpr */
    Fast_nodeKind_UpdateExpr_o = cx_declare(Fast_nodeKind_o, "UpdateExpr", cx_type(cx_constant_o));
    if (!Fast_nodeKind_UpdateExpr_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::nodeKind::UpdateExpr'.");
        goto error;
    }

    /* Define ::cortex::Fast::nodeKind::UpdateExpr */
    if (!cx_checkState(Fast_nodeKind_UpdateExpr_o, CX_DEFINED)) {
        if (cx_define(Fast_nodeKind_UpdateExpr_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::nodeKind::UpdateExpr'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::nodeKind::VariableExpr */
    Fast_nodeKind_VariableExpr_o = cx_declare(Fast_nodeKind_o, "VariableExpr", cx_type(cx_constant_o));
    if (!Fast_nodeKind_VariableExpr_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::nodeKind::VariableExpr'.");
        goto error;
    }

    /* Define ::cortex::Fast::nodeKind::VariableExpr */
    if (!cx_checkState(Fast_nodeKind_VariableExpr_o, CX_DEFINED)) {
        if (cx_define(Fast_nodeKind_VariableExpr_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::nodeKind::VariableExpr'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::nodeKind::WaitExpr */
    Fast_nodeKind_WaitExpr_o = cx_declare(Fast_nodeKind_o, "WaitExpr", cx_type(cx_constant_o));
    if (!Fast_nodeKind_WaitExpr_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::nodeKind::WaitExpr'.");
        goto error;
    }

    /* Define ::cortex::Fast::nodeKind::WaitExpr */
    if (!cx_checkState(Fast_nodeKind_WaitExpr_o, CX_DEFINED)) {
        if (cx_define(Fast_nodeKind_WaitExpr_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::nodeKind::WaitExpr'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::nodeKind::WhileExpr */
    Fast_nodeKind_WhileExpr_o = cx_declare(Fast_nodeKind_o, "WhileExpr", cx_type(cx_constant_o));
    if (!Fast_nodeKind_WhileExpr_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::nodeKind::WhileExpr'.");
        goto error;
    }

    /* Define ::cortex::Fast::nodeKind::WhileExpr */
    if (!cx_checkState(Fast_nodeKind_WhileExpr_o, CX_DEFINED)) {
        if (cx_define(Fast_nodeKind_WhileExpr_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::nodeKind::WhileExpr'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::nodeKind */
    if (!cx_checkState(Fast_nodeKind_o, CX_DEFINED)) {
        if (cx_define(Fast_nodeKind_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::nodeKind'.");
            goto error;
        }
    }

    if (cx_type(Fast_nodeKind_o)->size != sizeof(Fast_nodeKind)) {
        cx_error("Fast_load: calculated size '%d' of type '::cortex::Fast::nodeKind' doesn't match C-type size '%d'", cx_type(Fast_nodeKind_o)->size, sizeof(Fast_nodeKind));
    }

    /* Define ::cortex::Fast::Node::kind */
    if (!cx_checkState(Fast_Node_kind_o, CX_DEFINED)) {
        Fast_Node_kind_o->type = cx_resolve_ext(Fast_Node_kind_o, NULL, "::cortex::Fast::nodeKind", FALSE, "element ::cortex::Fast::Node::kind.type");
        Fast_Node_kind_o->modifiers = 0x0;
        Fast_Node_kind_o->state = 0x6;
        Fast_Node_kind_o->weak = FALSE;
        Fast_Node_kind_o->id = 0;
        if (cx_define(Fast_Node_kind_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Node::kind'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Null */
    Fast_Null_o = cx_declare(Fast_o, "Null", cx_type(cx_class_o));
    if (!Fast_Null_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Null'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Object */
    Fast_Object_o = cx_declare(Fast_o, "Object", cx_type(cx_class_o));
    if (!Fast_Object_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Object'.");
        goto error;
    }

    /* Declare ::cortex::Fast::ObjectBase */
    Fast_ObjectBase_o = cx_declare(Fast_o, "ObjectBase", cx_type(cx_class_o));
    if (!Fast_ObjectBase_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::ObjectBase'.");
        goto error;
    }

    /* Declare ::cortex::Fast::ObjectBase::value */
    Fast_ObjectBase_value_o = cx_declare(Fast_ObjectBase_o, "value", cx_type(cx_member_o));
    if (!Fast_ObjectBase_value_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::ObjectBase::value'.");
        goto error;
    }

    /* Define ::cortex::Fast::ObjectBase::value */
    if (!cx_checkState(Fast_ObjectBase_value_o, CX_DEFINED)) {
        Fast_ObjectBase_value_o->type = cx_resolve_ext(Fast_ObjectBase_value_o, NULL, "::cortex::lang::object", FALSE, "element ::cortex::Fast::ObjectBase::value.type");
        Fast_ObjectBase_value_o->modifiers = 0x0;
        Fast_ObjectBase_value_o->state = 0x6;
        Fast_ObjectBase_value_o->weak = FALSE;
        Fast_ObjectBase_value_o->id = 0;
        if (cx_define(Fast_ObjectBase_value_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::ObjectBase::value'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser */
    Fast_Parser_o = cx_declare(Fast_o, "Parser", cx_type(cx_class_o));
    if (!Fast_Parser_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Parser::abort */
    Fast_Parser_abort_o = cx_declare(Fast_Parser_o, "abort", cx_type(cx_member_o));
    if (!Fast_Parser_abort_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::abort'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::abort */
    if (!cx_checkState(Fast_Parser_abort_o, CX_DEFINED)) {
        Fast_Parser_abort_o->type = cx_resolve_ext(Fast_Parser_abort_o, NULL, "::cortex::lang::bool", FALSE, "element ::cortex::Fast::Parser::abort.type");
        Fast_Parser_abort_o->modifiers = 0x4;
        Fast_Parser_abort_o->state = 0x6;
        Fast_Parser_abort_o->weak = FALSE;
        Fast_Parser_abort_o->id = 14;
        if (cx_define(Fast_Parser_abort_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::abort'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::bindings */
    Fast_Parser_bindings_o = cx_declare(Fast_Parser_o, "bindings", cx_type(cx_member_o));
    if (!Fast_Parser_bindings_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::bindings'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::bindings */
    if (!cx_checkState(Fast_Parser_bindings_o, CX_DEFINED)) {
        Fast_Parser_bindings_o->type = cx_resolve_ext(Fast_Parser_bindings_o, NULL, "::cortex::lang::list{::cortex::Fast::Binding,0}", FALSE, "element ::cortex::Fast::Parser::bindings.type");
        Fast_Parser_bindings_o->modifiers = 0x4;
        Fast_Parser_bindings_o->state = 0x6;
        Fast_Parser_bindings_o->weak = FALSE;
        Fast_Parser_bindings_o->id = 15;
        if (cx_define(Fast_Parser_bindings_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::bindings'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::block */
    Fast_Parser_block_o = cx_declare(Fast_Parser_o, "block", cx_type(cx_member_o));
    if (!Fast_Parser_block_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::block'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Parser::blockCount */
    Fast_Parser_blockCount_o = cx_declare(Fast_Parser_o, "blockCount", cx_type(cx_member_o));
    if (!Fast_Parser_blockCount_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::blockCount'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::blockCount */
    if (!cx_checkState(Fast_Parser_blockCount_o, CX_DEFINED)) {
        Fast_Parser_blockCount_o->type = cx_resolve_ext(Fast_Parser_blockCount_o, NULL, "::cortex::lang::uint32", FALSE, "element ::cortex::Fast::Parser::blockCount.type");
        Fast_Parser_blockCount_o->modifiers = 0x4;
        Fast_Parser_blockCount_o->state = 0x6;
        Fast_Parser_blockCount_o->weak = FALSE;
        Fast_Parser_blockCount_o->id = 8;
        if (cx_define(Fast_Parser_blockCount_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::blockCount'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::blockPop() */
    Fast_Parser_blockPop_o = cx_declare(Fast_Parser_o, "blockPop()", cx_type(cx_method_o));
    if (!Fast_Parser_blockPop_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::blockPop()'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::blockPop() */
    if (!cx_checkState(Fast_Parser_blockPop_o, CX_DEFINED)) {
        cx_function(Fast_Parser_blockPop_o)->returnType = cx_resolve_ext(Fast_Parser_blockPop_o, NULL, "::cortex::lang::void", FALSE, "element ::cortex::Fast::Parser::blockPop().returnType");
        cx_function(Fast_Parser_blockPop_o)->returnsReference = FALSE;
        Fast_Parser_blockPop_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Parser::blockPop() with C-function */
        cx_function(Fast_Parser_blockPop_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Parser_blockPop(void *args, void *result);
        cx_function(Fast_Parser_blockPop_o)->impl = (cx_word)__Fast_Parser_blockPop;
        if (cx_define(Fast_Parser_blockPop_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::blockPop()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::blockPreset */
    Fast_Parser_blockPreset_o = cx_declare(Fast_Parser_o, "blockPreset", cx_type(cx_member_o));
    if (!Fast_Parser_blockPreset_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::blockPreset'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::blockPreset */
    if (!cx_checkState(Fast_Parser_blockPreset_o, CX_DEFINED)) {
        Fast_Parser_blockPreset_o->type = cx_resolve_ext(Fast_Parser_blockPreset_o, NULL, "::cortex::lang::bool", FALSE, "element ::cortex::Fast::Parser::blockPreset.type");
        Fast_Parser_blockPreset_o->modifiers = 0x3;
        Fast_Parser_blockPreset_o->state = 0x6;
        Fast_Parser_blockPreset_o->weak = FALSE;
        Fast_Parser_blockPreset_o->id = 19;
        if (cx_define(Fast_Parser_blockPreset_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::blockPreset'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::blockPush(bool presetBlock) */
    Fast_Parser_blockPush_o = cx_declare(Fast_Parser_o, "blockPush(bool presetBlock)", cx_type(cx_method_o));
    if (!Fast_Parser_blockPush_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::blockPush(bool presetBlock)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::blockPush(bool presetBlock) */
    if (!cx_checkState(Fast_Parser_blockPush_o, CX_DEFINED)) {
        cx_function(Fast_Parser_blockPush_o)->returnType = cx_resolve_ext(Fast_Parser_blockPush_o, NULL, "::cortex::Fast::Block", FALSE, "element ::cortex::Fast::Parser::blockPush(bool presetBlock).returnType");
        cx_function(Fast_Parser_blockPush_o)->returnsReference = FALSE;
        Fast_Parser_blockPush_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Parser::blockPush(bool presetBlock) with C-function */
        cx_function(Fast_Parser_blockPush_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Parser_blockPush(void *args, void *result);
        cx_function(Fast_Parser_blockPush_o)->impl = (cx_word)__Fast_Parser_blockPush;
        if (cx_define(Fast_Parser_blockPush_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::blockPush(bool presetBlock)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::collect(object o) */
    Fast_Parser_collect_o = cx_declare(Fast_Parser_o, "collect(object o)", cx_type(cx_method_o));
    if (!Fast_Parser_collect_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::collect(object o)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::collect(object o) */
    if (!cx_checkState(Fast_Parser_collect_o, CX_DEFINED)) {
        cx_function(Fast_Parser_collect_o)->returnType = cx_resolve_ext(Fast_Parser_collect_o, NULL, "::cortex::lang::void", FALSE, "element ::cortex::Fast::Parser::collect(object o).returnType");
        cx_function(Fast_Parser_collect_o)->returnsReference = FALSE;
        Fast_Parser_collect_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Parser::collect(object o) with C-function */
        cx_function(Fast_Parser_collect_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Parser_collect(void *args, void *result);
        cx_function(Fast_Parser_collect_o)->impl = (cx_word)__Fast_Parser_collect;
        if (cx_define(Fast_Parser_collect_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::collect(object o)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::collected */
    Fast_Parser_collected_o = cx_declare(Fast_Parser_o, "collected", cx_type(cx_member_o));
    if (!Fast_Parser_collected_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::collected'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Parser::collectHeap(word addr) */
    Fast_Parser_collectHeap_o = cx_declare(Fast_Parser_o, "collectHeap(word addr)", cx_type(cx_method_o));
    if (!Fast_Parser_collectHeap_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::collectHeap(word addr)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::collectHeap(word addr) */
    if (!cx_checkState(Fast_Parser_collectHeap_o, CX_DEFINED)) {
        cx_function(Fast_Parser_collectHeap_o)->returnType = cx_resolve_ext(Fast_Parser_collectHeap_o, NULL, "::cortex::lang::void", FALSE, "element ::cortex::Fast::Parser::collectHeap(word addr).returnType");
        cx_function(Fast_Parser_collectHeap_o)->returnsReference = FALSE;
        Fast_Parser_collectHeap_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Parser::collectHeap(word addr) with C-function */
        cx_function(Fast_Parser_collectHeap_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Parser_collectHeap(void *args, void *result);
        cx_function(Fast_Parser_collectHeap_o)->impl = (cx_word)__Fast_Parser_collectHeap;
        if (cx_define(Fast_Parser_collectHeap_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::collectHeap(word addr)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::column */
    Fast_Parser_column_o = cx_declare(Fast_Parser_o, "column", cx_type(cx_member_o));
    if (!Fast_Parser_column_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::column'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::column */
    if (!cx_checkState(Fast_Parser_column_o, CX_DEFINED)) {
        Fast_Parser_column_o->type = cx_resolve_ext(Fast_Parser_column_o, NULL, "::cortex::lang::uint32", FALSE, "element ::cortex::Fast::Parser::column.type");
        Fast_Parser_column_o->modifiers = 0x4;
        Fast_Parser_column_o->state = 0x6;
        Fast_Parser_column_o->weak = FALSE;
        Fast_Parser_column_o->id = 5;
        if (cx_define(Fast_Parser_column_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::column'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::complexType */
    Fast_Parser_complexType_o = cx_declare(Fast_Parser_o, "complexType", cx_type(cx_member_o));
    if (!Fast_Parser_complexType_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::complexType'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Parser::complexTypeSp */
    Fast_Parser_complexTypeSp_o = cx_declare(Fast_Parser_o, "complexTypeSp", cx_type(cx_member_o));
    if (!Fast_Parser_complexTypeSp_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::complexTypeSp'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::complexTypeSp */
    if (!cx_checkState(Fast_Parser_complexTypeSp_o, CX_DEFINED)) {
        Fast_Parser_complexTypeSp_o->type = cx_resolve_ext(Fast_Parser_complexTypeSp_o, NULL, "::cortex::lang::int32", FALSE, "element ::cortex::Fast::Parser::complexTypeSp.type");
        Fast_Parser_complexTypeSp_o->modifiers = 0x3;
        Fast_Parser_complexTypeSp_o->state = 0x6;
        Fast_Parser_complexTypeSp_o->weak = FALSE;
        Fast_Parser_complexTypeSp_o->id = 38;
        if (cx_define(Fast_Parser_complexTypeSp_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::complexTypeSp'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::construct() */
    Fast_Parser_construct_o = cx_declare(Fast_Parser_o, "construct()", cx_type(cx_method_o));
    if (!Fast_Parser_construct_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::construct()'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::construct() */
    if (!cx_checkState(Fast_Parser_construct_o, CX_DEFINED)) {
        cx_function(Fast_Parser_construct_o)->returnType = cx_resolve_ext(Fast_Parser_construct_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::Parser::construct().returnType");
        cx_function(Fast_Parser_construct_o)->returnsReference = FALSE;
        Fast_Parser_construct_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Parser::construct() with C-function */
        cx_function(Fast_Parser_construct_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Parser_construct(void *args, void *result);
        cx_function(Fast_Parser_construct_o)->impl = (cx_word)__Fast_Parser_construct;
        if (cx_define(Fast_Parser_construct_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::construct()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::define() */
    Fast_Parser_define_o = cx_declare(Fast_Parser_o, "define()", cx_type(cx_method_o));
    if (!Fast_Parser_define_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::define()'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::define() */
    if (!cx_checkState(Fast_Parser_define_o, CX_DEFINED)) {
        cx_function(Fast_Parser_define_o)->returnType = cx_resolve_ext(Fast_Parser_define_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::Parser::define().returnType");
        cx_function(Fast_Parser_define_o)->returnsReference = FALSE;
        Fast_Parser_define_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Parser::define() with C-function */
        cx_function(Fast_Parser_define_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Parser_define(void *args, void *result);
        cx_function(Fast_Parser_define_o)->impl = (cx_word)__Fast_Parser_define;
        if (cx_define(Fast_Parser_define_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::define()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::defineScope() */
    Fast_Parser_defineScope_o = cx_declare(Fast_Parser_o, "defineScope()", cx_type(cx_method_o));
    if (!Fast_Parser_defineScope_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::defineScope()'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::defineScope() */
    if (!cx_checkState(Fast_Parser_defineScope_o, CX_DEFINED)) {
        cx_function(Fast_Parser_defineScope_o)->returnType = cx_resolve_ext(Fast_Parser_defineScope_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::Parser::defineScope().returnType");
        cx_function(Fast_Parser_defineScope_o)->returnsReference = FALSE;
        Fast_Parser_defineScope_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Parser::defineScope() with C-function */
        cx_function(Fast_Parser_defineScope_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Parser_defineScope(void *args, void *result);
        cx_function(Fast_Parser_defineScope_o)->impl = (cx_word)__Fast_Parser_defineScope;
        if (cx_define(Fast_Parser_defineScope_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::defineScope()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::destruct() */
    Fast_Parser_destruct_o = cx_declare(Fast_Parser_o, "destruct()", cx_type(cx_method_o));
    if (!Fast_Parser_destruct_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::destruct()'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::destruct() */
    if (!cx_checkState(Fast_Parser_destruct_o, CX_DEFINED)) {
        cx_function(Fast_Parser_destruct_o)->returnType = cx_resolve_ext(Fast_Parser_destruct_o, NULL, "::cortex::lang::void", FALSE, "element ::cortex::Fast::Parser::destruct().returnType");
        cx_function(Fast_Parser_destruct_o)->returnsReference = FALSE;
        Fast_Parser_destruct_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Parser::destruct() with C-function */
        cx_function(Fast_Parser_destruct_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Parser_destruct(void *args, void *result);
        cx_function(Fast_Parser_destruct_o)->impl = (cx_word)__Fast_Parser_destruct;
        if (cx_define(Fast_Parser_destruct_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::destruct()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::errLine */
    Fast_Parser_errLine_o = cx_declare(Fast_Parser_o, "errLine", cx_type(cx_member_o));
    if (!Fast_Parser_errLine_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::errLine'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::errLine */
    if (!cx_checkState(Fast_Parser_errLine_o, CX_DEFINED)) {
        Fast_Parser_errLine_o->type = cx_resolve_ext(Fast_Parser_errLine_o, NULL, "::cortex::lang::uint32", FALSE, "element ::cortex::Fast::Parser::errLine.type");
        Fast_Parser_errLine_o->modifiers = 0x6;
        Fast_Parser_errLine_o->state = 0x6;
        Fast_Parser_errLine_o->weak = FALSE;
        Fast_Parser_errLine_o->id = 13;
        if (cx_define(Fast_Parser_errLine_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::errLine'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::errors */
    Fast_Parser_errors_o = cx_declare(Fast_Parser_o, "errors", cx_type(cx_member_o));
    if (!Fast_Parser_errors_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::errors'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::errors */
    if (!cx_checkState(Fast_Parser_errors_o, CX_DEFINED)) {
        Fast_Parser_errors_o->type = cx_resolve_ext(Fast_Parser_errors_o, NULL, "::cortex::lang::uint32", FALSE, "element ::cortex::Fast::Parser::errors.type");
        Fast_Parser_errors_o->modifiers = 0x4;
        Fast_Parser_errors_o->state = 0x6;
        Fast_Parser_errors_o->weak = FALSE;
        Fast_Parser_errors_o->id = 10;
        if (cx_define(Fast_Parser_errors_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::errors'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::errSet */
    Fast_Parser_errSet_o = cx_declare(Fast_Parser_o, "errSet", cx_type(cx_member_o));
    if (!Fast_Parser_errSet_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::errSet'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::errSet */
    if (!cx_checkState(Fast_Parser_errSet_o, CX_DEFINED)) {
        Fast_Parser_errSet_o->type = cx_resolve_ext(Fast_Parser_errSet_o, NULL, "::cortex::lang::bool", FALSE, "element ::cortex::Fast::Parser::errSet.type");
        Fast_Parser_errSet_o->modifiers = 0x6;
        Fast_Parser_errSet_o->state = 0x6;
        Fast_Parser_errSet_o->weak = FALSE;
        Fast_Parser_errSet_o->id = 12;
        if (cx_define(Fast_Parser_errSet_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::errSet'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::filename */
    Fast_Parser_filename_o = cx_declare(Fast_Parser_o, "filename", cx_type(cx_member_o));
    if (!Fast_Parser_filename_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::filename'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::filename */
    if (!cx_checkState(Fast_Parser_filename_o, CX_DEFINED)) {
        Fast_Parser_filename_o->type = cx_resolve_ext(Fast_Parser_filename_o, NULL, "::cortex::lang::string", FALSE, "element ::cortex::Fast::Parser::filename.type");
        Fast_Parser_filename_o->modifiers = 0x0;
        Fast_Parser_filename_o->state = 0x6;
        Fast_Parser_filename_o->weak = FALSE;
        Fast_Parser_filename_o->id = 2;
        if (cx_define(Fast_Parser_filename_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::filename'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::getComplexType() */
    Fast_Parser_getComplexType_o = cx_declare(Fast_Parser_o, "getComplexType()", cx_type(cx_method_o));
    if (!Fast_Parser_getComplexType_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::getComplexType()'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::getComplexType() */
    if (!cx_checkState(Fast_Parser_getComplexType_o, CX_DEFINED)) {
        cx_function(Fast_Parser_getComplexType_o)->returnType = cx_resolve_ext(Fast_Parser_getComplexType_o, NULL, "::cortex::lang::type", FALSE, "element ::cortex::Fast::Parser::getComplexType().returnType");
        cx_function(Fast_Parser_getComplexType_o)->returnsReference = FALSE;
        Fast_Parser_getComplexType_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Parser::getComplexType() with C-function */
        cx_function(Fast_Parser_getComplexType_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Parser_getComplexType(void *args, void *result);
        cx_function(Fast_Parser_getComplexType_o)->impl = (cx_word)__Fast_Parser_getComplexType;
        if (cx_define(Fast_Parser_getComplexType_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::getComplexType()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::getLvalue(bool assignment) */
    Fast_Parser_getLvalue_o = cx_declare(Fast_Parser_o, "getLvalue(bool assignment)", cx_type(cx_method_o));
    if (!Fast_Parser_getLvalue_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::getLvalue(bool assignment)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::getLvalue(bool assignment) */
    if (!cx_checkState(Fast_Parser_getLvalue_o, CX_DEFINED)) {
        cx_function(Fast_Parser_getLvalue_o)->returnType = cx_resolve_ext(Fast_Parser_getLvalue_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::Parser::getLvalue(bool assignment).returnType");
        cx_function(Fast_Parser_getLvalue_o)->returnsReference = FALSE;
        Fast_Parser_getLvalue_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Parser::getLvalue(bool assignment) with C-function */
        cx_function(Fast_Parser_getLvalue_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Parser_getLvalue(void *args, void *result);
        cx_function(Fast_Parser_getLvalue_o)->impl = (cx_word)__Fast_Parser_getLvalue;
        if (cx_define(Fast_Parser_getLvalue_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::getLvalue(bool assignment)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::getLvalueType(bool assignment) */
    Fast_Parser_getLvalueType_o = cx_declare(Fast_Parser_o, "getLvalueType(bool assignment)", cx_type(cx_method_o));
    if (!Fast_Parser_getLvalueType_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::getLvalueType(bool assignment)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::getLvalueType(bool assignment) */
    if (!cx_checkState(Fast_Parser_getLvalueType_o, CX_DEFINED)) {
        cx_function(Fast_Parser_getLvalueType_o)->returnType = cx_resolve_ext(Fast_Parser_getLvalueType_o, NULL, "::cortex::lang::type", FALSE, "element ::cortex::Fast::Parser::getLvalueType(bool assignment).returnType");
        cx_function(Fast_Parser_getLvalueType_o)->returnsReference = FALSE;
        Fast_Parser_getLvalueType_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Parser::getLvalueType(bool assignment) with C-function */
        cx_function(Fast_Parser_getLvalueType_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Parser_getLvalueType(void *args, void *result);
        cx_function(Fast_Parser_getLvalueType_o)->impl = (cx_word)__Fast_Parser_getLvalueType;
        if (cx_define(Fast_Parser_getLvalueType_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::getLvalueType(bool assignment)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::heapCollected */
    Fast_Parser_heapCollected_o = cx_declare(Fast_Parser_o, "heapCollected", cx_type(cx_member_o));
    if (!Fast_Parser_heapCollected_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::heapCollected'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Parser::initAnonymousId */
    Fast_Parser_initAnonymousId_o = cx_declare(Fast_Parser_o, "initAnonymousId", cx_type(cx_member_o));
    if (!Fast_Parser_initAnonymousId_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::initAnonymousId'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::initAnonymousId */
    if (!cx_checkState(Fast_Parser_initAnonymousId_o, CX_DEFINED)) {
        Fast_Parser_initAnonymousId_o->type = cx_resolve_ext(Fast_Parser_initAnonymousId_o, NULL, "::cortex::lang::uint32", FALSE, "element ::cortex::Fast::Parser::initAnonymousId.type");
        Fast_Parser_initAnonymousId_o->modifiers = 0x3;
        Fast_Parser_initAnonymousId_o->state = 0x6;
        Fast_Parser_initAnonymousId_o->weak = FALSE;
        Fast_Parser_initAnonymousId_o->id = 30;
        if (cx_define(Fast_Parser_initAnonymousId_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::initAnonymousId'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::initDynamic */
    Fast_Parser_initDynamic_o = cx_declare(Fast_Parser_o, "initDynamic", cx_type(cx_member_o));
    if (!Fast_Parser_initDynamic_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::initDynamic'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::initDynamic */
    if (!cx_checkState(Fast_Parser_initDynamic_o, CX_DEFINED)) {
        Fast_Parser_initDynamic_o->type = cx_resolve_ext(Fast_Parser_initDynamic_o, NULL, "::cortex::lang::bool", FALSE, "element ::cortex::Fast::Parser::initDynamic.type");
        Fast_Parser_initDynamic_o->modifiers = 0x3;
        Fast_Parser_initDynamic_o->state = 0x6;
        Fast_Parser_initDynamic_o->weak = FALSE;
        Fast_Parser_initDynamic_o->id = 31;
        if (cx_define(Fast_Parser_initDynamic_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::initDynamic'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::initializerCount */
    Fast_Parser_initializerCount_o = cx_declare(Fast_Parser_o, "initializerCount", cx_type(cx_member_o));
    if (!Fast_Parser_initializerCount_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::initializerCount'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::initializerCount */
    if (!cx_checkState(Fast_Parser_initializerCount_o, CX_DEFINED)) {
        Fast_Parser_initializerCount_o->type = cx_resolve_ext(Fast_Parser_initializerCount_o, NULL, "::cortex::lang::int8", FALSE, "element ::cortex::Fast::Parser::initializerCount.type");
        Fast_Parser_initializerCount_o->modifiers = 0x3;
        Fast_Parser_initializerCount_o->state = 0x6;
        Fast_Parser_initializerCount_o->weak = FALSE;
        Fast_Parser_initializerCount_o->id = 29;
        if (cx_define(Fast_Parser_initializerCount_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::initializerCount'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::initializers */
    Fast_Parser_initializers_o = cx_declare(Fast_Parser_o, "initializers", cx_type(cx_member_o));
    if (!Fast_Parser_initializers_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::initializers'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Parser::initKeyValuePop() */
    Fast_Parser_initKeyValuePop_o = cx_declare(Fast_Parser_o, "initKeyValuePop()", cx_type(cx_method_o));
    if (!Fast_Parser_initKeyValuePop_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::initKeyValuePop()'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::initKeyValuePop() */
    if (!cx_checkState(Fast_Parser_initKeyValuePop_o, CX_DEFINED)) {
        cx_function(Fast_Parser_initKeyValuePop_o)->returnType = cx_resolve_ext(Fast_Parser_initKeyValuePop_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::Parser::initKeyValuePop().returnType");
        cx_function(Fast_Parser_initKeyValuePop_o)->returnsReference = FALSE;
        Fast_Parser_initKeyValuePop_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Parser::initKeyValuePop() with C-function */
        cx_function(Fast_Parser_initKeyValuePop_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Parser_initKeyValuePop(void *args, void *result);
        cx_function(Fast_Parser_initKeyValuePop_o)->impl = (cx_word)__Fast_Parser_initKeyValuePop;
        if (cx_define(Fast_Parser_initKeyValuePop_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::initKeyValuePop()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::initKeyValuePush() */
    Fast_Parser_initKeyValuePush_o = cx_declare(Fast_Parser_o, "initKeyValuePush()", cx_type(cx_method_o));
    if (!Fast_Parser_initKeyValuePush_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::initKeyValuePush()'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::initKeyValuePush() */
    if (!cx_checkState(Fast_Parser_initKeyValuePush_o, CX_DEFINED)) {
        cx_function(Fast_Parser_initKeyValuePush_o)->returnType = cx_resolve_ext(Fast_Parser_initKeyValuePush_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::Parser::initKeyValuePush().returnType");
        cx_function(Fast_Parser_initKeyValuePush_o)->returnsReference = FALSE;
        Fast_Parser_initKeyValuePush_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Parser::initKeyValuePush() with C-function */
        cx_function(Fast_Parser_initKeyValuePush_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Parser_initKeyValuePush(void *args, void *result);
        cx_function(Fast_Parser_initKeyValuePush_o)->impl = (cx_word)__Fast_Parser_initKeyValuePush;
        if (cx_define(Fast_Parser_initKeyValuePush_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::initKeyValuePush()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::initMember(string member) */
    Fast_Parser_initMember_o = cx_declare(Fast_Parser_o, "initMember(string member)", cx_type(cx_method_o));
    if (!Fast_Parser_initMember_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::initMember(string member)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::initMember(string member) */
    if (!cx_checkState(Fast_Parser_initMember_o, CX_DEFINED)) {
        cx_function(Fast_Parser_initMember_o)->returnType = cx_resolve_ext(Fast_Parser_initMember_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::Parser::initMember(string member).returnType");
        cx_function(Fast_Parser_initMember_o)->returnsReference = FALSE;
        Fast_Parser_initMember_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Parser::initMember(string member) with C-function */
        cx_function(Fast_Parser_initMember_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Parser_initMember(void *args, void *result);
        cx_function(Fast_Parser_initMember_o)->impl = (cx_word)__Fast_Parser_initMember;
        if (cx_define(Fast_Parser_initMember_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::initMember(string member)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::initPop() */
    Fast_Parser_initPop_o = cx_declare(Fast_Parser_o, "initPop()", cx_type(cx_method_o));
    if (!Fast_Parser_initPop_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::initPop()'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::initPop() */
    if (!cx_checkState(Fast_Parser_initPop_o, CX_DEFINED)) {
        cx_function(Fast_Parser_initPop_o)->returnType = cx_resolve_ext(Fast_Parser_initPop_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::Parser::initPop().returnType");
        cx_function(Fast_Parser_initPop_o)->returnsReference = FALSE;
        Fast_Parser_initPop_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Parser::initPop() with C-function */
        cx_function(Fast_Parser_initPop_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Parser_initPop(void *args, void *result);
        cx_function(Fast_Parser_initPop_o)->impl = (cx_word)__Fast_Parser_initPop;
        if (cx_define(Fast_Parser_initPop_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::initPop()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::initPush() */
    Fast_Parser_initPush_o = cx_declare(Fast_Parser_o, "initPush()", cx_type(cx_method_o));
    if (!Fast_Parser_initPush_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::initPush()'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::initPush() */
    if (!cx_checkState(Fast_Parser_initPush_o, CX_DEFINED)) {
        cx_function(Fast_Parser_initPush_o)->returnType = cx_resolve_ext(Fast_Parser_initPush_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::Parser::initPush().returnType");
        cx_function(Fast_Parser_initPush_o)->returnsReference = FALSE;
        Fast_Parser_initPush_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Parser::initPush() with C-function */
        cx_function(Fast_Parser_initPush_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Parser_initPush(void *args, void *result);
        cx_function(Fast_Parser_initPush_o)->impl = (cx_word)__Fast_Parser_initPush;
        if (cx_define(Fast_Parser_initPush_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::initPush()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::initPushExpression() */
    Fast_Parser_initPushExpression_o = cx_declare(Fast_Parser_o, "initPushExpression()", cx_type(cx_method_o));
    if (!Fast_Parser_initPushExpression_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::initPushExpression()'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::initPushExpression() */
    if (!cx_checkState(Fast_Parser_initPushExpression_o, CX_DEFINED)) {
        cx_function(Fast_Parser_initPushExpression_o)->returnType = cx_resolve_ext(Fast_Parser_initPushExpression_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::Parser::initPushExpression().returnType");
        cx_function(Fast_Parser_initPushExpression_o)->returnsReference = FALSE;
        Fast_Parser_initPushExpression_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Parser::initPushExpression() with C-function */
        cx_function(Fast_Parser_initPushExpression_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Parser_initPushExpression(void *args, void *result);
        cx_function(Fast_Parser_initPushExpression_o)->impl = (cx_word)__Fast_Parser_initPushExpression;
        if (cx_define(Fast_Parser_initPushExpression_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::initPushExpression()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::initPushStatic() */
    Fast_Parser_initPushStatic_o = cx_declare(Fast_Parser_o, "initPushStatic()", cx_type(cx_method_o));
    if (!Fast_Parser_initPushStatic_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::initPushStatic()'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::initPushStatic() */
    if (!cx_checkState(Fast_Parser_initPushStatic_o, CX_DEFINED)) {
        cx_function(Fast_Parser_initPushStatic_o)->returnType = cx_resolve_ext(Fast_Parser_initPushStatic_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::Parser::initPushStatic().returnType");
        cx_function(Fast_Parser_initPushStatic_o)->returnsReference = FALSE;
        Fast_Parser_initPushStatic_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Parser::initPushStatic() with C-function */
        cx_function(Fast_Parser_initPushStatic_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Parser_initPushStatic(void *args, void *result);
        cx_function(Fast_Parser_initPushStatic_o)->impl = (cx_word)__Fast_Parser_initPushStatic;
        if (cx_define(Fast_Parser_initPushStatic_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::initPushStatic()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::initStage(string id,bool found) */
    Fast_Parser_initStage_o = cx_declare(Fast_Parser_o, "initStage(string id,bool found)", cx_type(cx_method_o));
    if (!Fast_Parser_initStage_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::initStage(string id,bool found)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::initStage(string id,bool found) */
    if (!cx_checkState(Fast_Parser_initStage_o, CX_DEFINED)) {
        cx_function(Fast_Parser_initStage_o)->returnType = cx_resolve_ext(Fast_Parser_initStage_o, NULL, "::cortex::lang::void", FALSE, "element ::cortex::Fast::Parser::initStage(string id,bool found).returnType");
        cx_function(Fast_Parser_initStage_o)->returnsReference = FALSE;
        Fast_Parser_initStage_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Parser::initStage(string id,bool found) with C-function */
        cx_function(Fast_Parser_initStage_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Parser_initStage(void *args, void *result);
        cx_function(Fast_Parser_initStage_o)->impl = (cx_word)__Fast_Parser_initStage;
        if (cx_define(Fast_Parser_initStage_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::initStage(string id,bool found)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::isAbortSet() */
    Fast_Parser_isAbortSet_o = cx_declare(Fast_Parser_o, "isAbortSet()", cx_type(cx_method_o));
    if (!Fast_Parser_isAbortSet_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::isAbortSet()'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::isAbortSet() */
    if (!cx_checkState(Fast_Parser_isAbortSet_o, CX_DEFINED)) {
        cx_function(Fast_Parser_isAbortSet_o)->returnType = cx_resolve_ext(Fast_Parser_isAbortSet_o, NULL, "::cortex::lang::bool", FALSE, "element ::cortex::Fast::Parser::isAbortSet().returnType");
        cx_function(Fast_Parser_isAbortSet_o)->returnsReference = FALSE;
        Fast_Parser_isAbortSet_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Parser::isAbortSet() with C-function */
        cx_function(Fast_Parser_isAbortSet_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Parser_isAbortSet(void *args, void *result);
        cx_function(Fast_Parser_isAbortSet_o)->impl = (cx_word)__Fast_Parser_isAbortSet;
        if (cx_define(Fast_Parser_isAbortSet_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::isAbortSet()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::isErrSet() */
    Fast_Parser_isErrSet_o = cx_declare(Fast_Parser_o, "isErrSet()", cx_type(cx_method_o));
    if (!Fast_Parser_isErrSet_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::isErrSet()'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::isErrSet() */
    if (!cx_checkState(Fast_Parser_isErrSet_o, CX_DEFINED)) {
        cx_function(Fast_Parser_isErrSet_o)->returnType = cx_resolve_ext(Fast_Parser_isErrSet_o, NULL, "::cortex::lang::bool", FALSE, "element ::cortex::Fast::Parser::isErrSet().returnType");
        cx_function(Fast_Parser_isErrSet_o)->returnsReference = FALSE;
        Fast_Parser_isErrSet_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Parser::isErrSet() with C-function */
        cx_function(Fast_Parser_isErrSet_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Parser_isErrSet(void *args, void *result);
        cx_function(Fast_Parser_isErrSet_o)->impl = (cx_word)__Fast_Parser_isErrSet;
        if (cx_define(Fast_Parser_isErrSet_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::isErrSet()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::isLocal */
    Fast_Parser_isLocal_o = cx_declare(Fast_Parser_o, "isLocal", cx_type(cx_member_o));
    if (!Fast_Parser_isLocal_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::isLocal'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::isLocal */
    if (!cx_checkState(Fast_Parser_isLocal_o, CX_DEFINED)) {
        Fast_Parser_isLocal_o->type = cx_resolve_ext(Fast_Parser_isLocal_o, NULL, "::cortex::lang::bool", FALSE, "element ::cortex::Fast::Parser::isLocal.type");
        Fast_Parser_isLocal_o->modifiers = 0x3;
        Fast_Parser_isLocal_o->state = 0x6;
        Fast_Parser_isLocal_o->weak = FALSE;
        Fast_Parser_isLocal_o->id = 20;
        if (cx_define(Fast_Parser_isLocal_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::isLocal'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::lastFailedResolve */
    Fast_Parser_lastFailedResolve_o = cx_declare(Fast_Parser_o, "lastFailedResolve", cx_type(cx_member_o));
    if (!Fast_Parser_lastFailedResolve_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::lastFailedResolve'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::lastFailedResolve */
    if (!cx_checkState(Fast_Parser_lastFailedResolve_o, CX_DEFINED)) {
        Fast_Parser_lastFailedResolve_o->type = cx_resolve_ext(Fast_Parser_lastFailedResolve_o, NULL, "::cortex::lang::string", FALSE, "element ::cortex::Fast::Parser::lastFailedResolve.type");
        Fast_Parser_lastFailedResolve_o->modifiers = 0x3;
        Fast_Parser_lastFailedResolve_o->state = 0x6;
        Fast_Parser_lastFailedResolve_o->weak = FALSE;
        Fast_Parser_lastFailedResolve_o->id = 23;
        if (cx_define(Fast_Parser_lastFailedResolve_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::lastFailedResolve'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::line */
    Fast_Parser_line_o = cx_declare(Fast_Parser_o, "line", cx_type(cx_member_o));
    if (!Fast_Parser_line_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::line'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::line */
    if (!cx_checkState(Fast_Parser_line_o, CX_DEFINED)) {
        Fast_Parser_line_o->type = cx_resolve_ext(Fast_Parser_line_o, NULL, "::cortex::lang::uint32", FALSE, "element ::cortex::Fast::Parser::line.type");
        Fast_Parser_line_o->modifiers = 0x4;
        Fast_Parser_line_o->state = 0x6;
        Fast_Parser_line_o->weak = FALSE;
        Fast_Parser_line_o->id = 4;
        if (cx_define(Fast_Parser_line_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::line'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::lookup(string id,object source) */
    Fast_Parser_lookup_o = cx_declare(Fast_Parser_o, "lookup(string id,object source)", cx_type(cx_method_o));
    if (!Fast_Parser_lookup_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::lookup(string id,object source)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::lookup(string id,object source) */
    if (!cx_checkState(Fast_Parser_lookup_o, CX_DEFINED)) {
        cx_function(Fast_Parser_lookup_o)->returnType = cx_resolve_ext(Fast_Parser_lookup_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::Parser::lookup(string id,object source).returnType");
        cx_function(Fast_Parser_lookup_o)->returnsReference = FALSE;
        Fast_Parser_lookup_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Parser::lookup(string id,object source) with C-function */
        cx_function(Fast_Parser_lookup_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Parser_lookup(void *args, void *result);
        cx_function(Fast_Parser_lookup_o)->impl = (cx_word)__Fast_Parser_lookup;
        if (cx_define(Fast_Parser_lookup_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::lookup(string id,object source)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::lvalue */
    Fast_Parser_lvalue_o = cx_declare(Fast_Parser_o, "lvalue", cx_type(cx_member_o));
    if (!Fast_Parser_lvalue_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::lvalue'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Parser::lvalueSp */
    Fast_Parser_lvalueSp_o = cx_declare(Fast_Parser_o, "lvalueSp", cx_type(cx_member_o));
    if (!Fast_Parser_lvalueSp_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::lvalueSp'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::lvalueSp */
    if (!cx_checkState(Fast_Parser_lvalueSp_o, CX_DEFINED)) {
        Fast_Parser_lvalueSp_o->type = cx_resolve_ext(Fast_Parser_lvalueSp_o, NULL, "::cortex::lang::int32", FALSE, "element ::cortex::Fast::Parser::lvalueSp.type");
        Fast_Parser_lvalueSp_o->modifiers = 0x3;
        Fast_Parser_lvalueSp_o->state = 0x6;
        Fast_Parser_lvalueSp_o->weak = FALSE;
        Fast_Parser_lvalueSp_o->id = 36;
        if (cx_define(Fast_Parser_lvalueSp_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::lvalueSp'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::observerPush() */
    Fast_Parser_observerPush_o = cx_declare(Fast_Parser_o, "observerPush()", cx_type(cx_method_o));
    if (!Fast_Parser_observerPush_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::observerPush()'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::observerPush() */
    if (!cx_checkState(Fast_Parser_observerPush_o, CX_DEFINED)) {
        cx_function(Fast_Parser_observerPush_o)->returnType = cx_resolve_ext(Fast_Parser_observerPush_o, NULL, "::cortex::lang::void", FALSE, "element ::cortex::Fast::Parser::observerPush().returnType");
        cx_function(Fast_Parser_observerPush_o)->returnsReference = FALSE;
        Fast_Parser_observerPush_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Parser::observerPush() with C-function */
        cx_function(Fast_Parser_observerPush_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Parser_observerPush(void *args, void *result);
        cx_function(Fast_Parser_observerPush_o)->impl = (cx_word)__Fast_Parser_observerPush;
        if (cx_define(Fast_Parser_observerPush_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::observerPush()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::parse() */
    Fast_Parser_parse_o = cx_declare(Fast_Parser_o, "parse()", cx_type(cx_method_o));
    if (!Fast_Parser_parse_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::parse()'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::parse() */
    if (!cx_checkState(Fast_Parser_parse_o, CX_DEFINED)) {
        cx_function(Fast_Parser_parse_o)->returnType = cx_resolve_ext(Fast_Parser_parse_o, NULL, "::cortex::lang::uint32", FALSE, "element ::cortex::Fast::Parser::parse().returnType");
        cx_function(Fast_Parser_parse_o)->returnsReference = FALSE;
        Fast_Parser_parse_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Parser::parse() with C-function */
        cx_function(Fast_Parser_parse_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Parser_parse(void *args, void *result);
        cx_function(Fast_Parser_parse_o)->impl = (cx_word)__Fast_Parser_parse;
        if (cx_define(Fast_Parser_parse_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::parse()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::parseSingleExpr */
    Fast_Parser_parseSingleExpr_o = cx_declare(Fast_Parser_o, "parseSingleExpr", cx_type(cx_member_o));
    if (!Fast_Parser_parseSingleExpr_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::parseSingleExpr'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::parseSingleExpr */
    if (!cx_checkState(Fast_Parser_parseSingleExpr_o, CX_DEFINED)) {
        Fast_Parser_parseSingleExpr_o->type = cx_resolve_ext(Fast_Parser_parseSingleExpr_o, NULL, "::cortex::lang::bool", FALSE, "element ::cortex::Fast::Parser::parseSingleExpr.type");
        Fast_Parser_parseSingleExpr_o->modifiers = 0x3;
        Fast_Parser_parseSingleExpr_o->state = 0x6;
        Fast_Parser_parseSingleExpr_o->weak = FALSE;
        Fast_Parser_parseSingleExpr_o->id = 21;
        if (cx_define(Fast_Parser_parseSingleExpr_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::parseSingleExpr'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::pass */
    Fast_Parser_pass_o = cx_declare(Fast_Parser_o, "pass", cx_type(cx_member_o));
    if (!Fast_Parser_pass_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::pass'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::pass */
    if (!cx_checkState(Fast_Parser_pass_o, CX_DEFINED)) {
        Fast_Parser_pass_o->type = cx_resolve_ext(Fast_Parser_pass_o, NULL, "::cortex::lang::uint32", FALSE, "element ::cortex::Fast::Parser::pass.type");
        Fast_Parser_pass_o->modifiers = 0x3;
        Fast_Parser_pass_o->state = 0x6;
        Fast_Parser_pass_o->weak = FALSE;
        Fast_Parser_pass_o->id = 16;
        if (cx_define(Fast_Parser_pass_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::pass'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::popComplexType() */
    Fast_Parser_popComplexType_o = cx_declare(Fast_Parser_o, "popComplexType()", cx_type(cx_method_o));
    if (!Fast_Parser_popComplexType_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::popComplexType()'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::popComplexType() */
    if (!cx_checkState(Fast_Parser_popComplexType_o, CX_DEFINED)) {
        cx_function(Fast_Parser_popComplexType_o)->returnType = cx_resolve_ext(Fast_Parser_popComplexType_o, NULL, "::cortex::lang::void", FALSE, "element ::cortex::Fast::Parser::popComplexType().returnType");
        cx_function(Fast_Parser_popComplexType_o)->returnsReference = FALSE;
        Fast_Parser_popComplexType_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Parser::popComplexType() with C-function */
        cx_function(Fast_Parser_popComplexType_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Parser_popComplexType(void *args, void *result);
        cx_function(Fast_Parser_popComplexType_o)->impl = (cx_word)__Fast_Parser_popComplexType;
        if (cx_define(Fast_Parser_popComplexType_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::popComplexType()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::popLvalue() */
    Fast_Parser_popLvalue_o = cx_declare(Fast_Parser_o, "popLvalue()", cx_type(cx_method_o));
    if (!Fast_Parser_popLvalue_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::popLvalue()'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::popLvalue() */
    if (!cx_checkState(Fast_Parser_popLvalue_o, CX_DEFINED)) {
        cx_function(Fast_Parser_popLvalue_o)->returnType = cx_resolve_ext(Fast_Parser_popLvalue_o, NULL, "::cortex::lang::void", FALSE, "element ::cortex::Fast::Parser::popLvalue().returnType");
        cx_function(Fast_Parser_popLvalue_o)->returnsReference = FALSE;
        Fast_Parser_popLvalue_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Parser::popLvalue() with C-function */
        cx_function(Fast_Parser_popLvalue_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Parser_popLvalue(void *args, void *result);
        cx_function(Fast_Parser_popLvalue_o)->impl = (cx_word)__Fast_Parser_popLvalue;
        if (cx_define(Fast_Parser_popLvalue_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::popLvalue()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::preprocessed */
    Fast_Parser_preprocessed_o = cx_declare(Fast_Parser_o, "preprocessed", cx_type(cx_member_o));
    if (!Fast_Parser_preprocessed_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::preprocessed'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::preprocessed */
    if (!cx_checkState(Fast_Parser_preprocessed_o, CX_DEFINED)) {
        Fast_Parser_preprocessed_o->type = cx_resolve_ext(Fast_Parser_preprocessed_o, NULL, "::cortex::lang::string", FALSE, "element ::cortex::Fast::Parser::preprocessed.type");
        Fast_Parser_preprocessed_o->modifiers = 0x4;
        Fast_Parser_preprocessed_o->state = 0x6;
        Fast_Parser_preprocessed_o->weak = FALSE;
        Fast_Parser_preprocessed_o->id = 1;
        if (cx_define(Fast_Parser_preprocessed_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::preprocessed'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::pushPackage(string name) */
    Fast_Parser_pushPackage_o = cx_declare(Fast_Parser_o, "pushPackage(string name)", cx_type(cx_method_o));
    if (!Fast_Parser_pushPackage_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::pushPackage(string name)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::pushPackage(string name) */
    if (!cx_checkState(Fast_Parser_pushPackage_o, CX_DEFINED)) {
        cx_function(Fast_Parser_pushPackage_o)->returnType = cx_resolve_ext(Fast_Parser_pushPackage_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::Parser::pushPackage(string name).returnType");
        cx_function(Fast_Parser_pushPackage_o)->returnsReference = FALSE;
        Fast_Parser_pushPackage_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Parser::pushPackage(string name) with C-function */
        cx_function(Fast_Parser_pushPackage_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Parser_pushPackage(void *args, void *result);
        cx_function(Fast_Parser_pushPackage_o)->impl = (cx_word)__Fast_Parser_pushPackage;
        if (cx_define(Fast_Parser_pushPackage_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::pushPackage(string name)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::pushReturnAsLvalue(function function) */
    Fast_Parser_pushReturnAsLvalue_o = cx_declare(Fast_Parser_o, "pushReturnAsLvalue(function function)", cx_type(cx_method_o));
    if (!Fast_Parser_pushReturnAsLvalue_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::pushReturnAsLvalue(function function)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::pushReturnAsLvalue(function function) */
    if (!cx_checkState(Fast_Parser_pushReturnAsLvalue_o, CX_DEFINED)) {
        cx_function(Fast_Parser_pushReturnAsLvalue_o)->returnType = cx_resolve_ext(Fast_Parser_pushReturnAsLvalue_o, NULL, "::cortex::lang::void", FALSE, "element ::cortex::Fast::Parser::pushReturnAsLvalue(function function).returnType");
        cx_function(Fast_Parser_pushReturnAsLvalue_o)->returnsReference = FALSE;
        Fast_Parser_pushReturnAsLvalue_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Parser::pushReturnAsLvalue(function function) with C-function */
        cx_function(Fast_Parser_pushReturnAsLvalue_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Parser_pushReturnAsLvalue(void *args, void *result);
        cx_function(Fast_Parser_pushReturnAsLvalue_o)->impl = (cx_word)__Fast_Parser_pushReturnAsLvalue;
        if (cx_define(Fast_Parser_pushReturnAsLvalue_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::pushReturnAsLvalue(function function)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::pushScope() */
    Fast_Parser_pushScope_o = cx_declare(Fast_Parser_o, "pushScope()", cx_type(cx_method_o));
    if (!Fast_Parser_pushScope_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::pushScope()'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Parser::repl */
    Fast_Parser_repl_o = cx_declare(Fast_Parser_o, "repl", cx_type(cx_member_o));
    if (!Fast_Parser_repl_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::repl'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::repl */
    if (!cx_checkState(Fast_Parser_repl_o, CX_DEFINED)) {
        Fast_Parser_repl_o->type = cx_resolve_ext(Fast_Parser_repl_o, NULL, "::cortex::lang::uint32", FALSE, "element ::cortex::Fast::Parser::repl.type");
        Fast_Parser_repl_o->modifiers = 0x4;
        Fast_Parser_repl_o->state = 0x6;
        Fast_Parser_repl_o->weak = FALSE;
        Fast_Parser_repl_o->id = 3;
        if (cx_define(Fast_Parser_repl_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::repl'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::reset() */
    Fast_Parser_reset_o = cx_declare(Fast_Parser_o, "reset()", cx_type(cx_method_o));
    if (!Fast_Parser_reset_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::reset()'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::reset() */
    if (!cx_checkState(Fast_Parser_reset_o, CX_DEFINED)) {
        cx_function(Fast_Parser_reset_o)->returnType = cx_resolve_ext(Fast_Parser_reset_o, NULL, "::cortex::lang::void", FALSE, "element ::cortex::Fast::Parser::reset().returnType");
        cx_function(Fast_Parser_reset_o)->returnsReference = FALSE;
        Fast_Parser_reset_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Parser::reset() with C-function */
        cx_function(Fast_Parser_reset_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Parser_reset(void *args, void *result);
        cx_function(Fast_Parser_reset_o)->impl = (cx_word)__Fast_Parser_reset;
        if (cx_define(Fast_Parser_reset_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::reset()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::scope */
    Fast_Parser_scope_o = cx_declare(Fast_Parser_o, "scope", cx_type(cx_member_o));
    if (!Fast_Parser_scope_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::scope'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Parser::singleExpr */
    Fast_Parser_singleExpr_o = cx_declare(Fast_Parser_o, "singleExpr", cx_type(cx_member_o));
    if (!Fast_Parser_singleExpr_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::singleExpr'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Parser::source */
    Fast_Parser_source_o = cx_declare(Fast_Parser_o, "source", cx_type(cx_member_o));
    if (!Fast_Parser_source_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::source'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::source */
    if (!cx_checkState(Fast_Parser_source_o, CX_DEFINED)) {
        Fast_Parser_source_o->type = cx_resolve_ext(Fast_Parser_source_o, NULL, "::cortex::lang::string", FALSE, "element ::cortex::Fast::Parser::source.type");
        Fast_Parser_source_o->modifiers = 0x0;
        Fast_Parser_source_o->state = 0x6;
        Fast_Parser_source_o->weak = FALSE;
        Fast_Parser_source_o->id = 0;
        if (cx_define(Fast_Parser_source_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::source'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::staged */
    Fast_Parser_staged_o = cx_declare(Fast_Parser_o, "staged", cx_type(cx_member_o));
    if (!Fast_Parser_staged_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::staged'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Parser::stagedCount */
    Fast_Parser_stagedCount_o = cx_declare(Fast_Parser_o, "stagedCount", cx_type(cx_member_o));
    if (!Fast_Parser_stagedCount_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::stagedCount'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::stagedCount */
    if (!cx_checkState(Fast_Parser_stagedCount_o, CX_DEFINED)) {
        Fast_Parser_stagedCount_o->type = cx_resolve_ext(Fast_Parser_stagedCount_o, NULL, "::cortex::lang::uint32", FALSE, "element ::cortex::Fast::Parser::stagedCount.type");
        Fast_Parser_stagedCount_o->modifiers = 0x3;
        Fast_Parser_stagedCount_o->state = 0x6;
        Fast_Parser_stagedCount_o->weak = FALSE;
        Fast_Parser_stagedCount_o->id = 33;
        if (cx_define(Fast_Parser_stagedCount_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::stagedCount'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::stagedId */
    Fast_Parser_stagedId_o = cx_declare(Fast_Parser_o, "stagedId", cx_type(cx_struct_o));
    if (!Fast_Parser_stagedId_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::stagedId'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Parser::stagedId::column */
    Fast_Parser_stagedId_column_o = cx_declare(Fast_Parser_stagedId_o, "column", cx_type(cx_member_o));
    if (!Fast_Parser_stagedId_column_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::stagedId::column'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::stagedId::column */
    if (!cx_checkState(Fast_Parser_stagedId_column_o, CX_DEFINED)) {
        Fast_Parser_stagedId_column_o->type = cx_resolve_ext(Fast_Parser_stagedId_column_o, NULL, "::cortex::lang::uint32", FALSE, "element ::cortex::Fast::Parser::stagedId::column.type");
        Fast_Parser_stagedId_column_o->modifiers = 0x0;
        Fast_Parser_stagedId_column_o->state = 0x6;
        Fast_Parser_stagedId_column_o->weak = FALSE;
        Fast_Parser_stagedId_column_o->id = 3;
        if (cx_define(Fast_Parser_stagedId_column_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::stagedId::column'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::stagedId::found */
    Fast_Parser_stagedId_found_o = cx_declare(Fast_Parser_stagedId_o, "found", cx_type(cx_member_o));
    if (!Fast_Parser_stagedId_found_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::stagedId::found'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::stagedId::found */
    if (!cx_checkState(Fast_Parser_stagedId_found_o, CX_DEFINED)) {
        Fast_Parser_stagedId_found_o->type = cx_resolve_ext(Fast_Parser_stagedId_found_o, NULL, "::cortex::lang::bool", FALSE, "element ::cortex::Fast::Parser::stagedId::found.type");
        Fast_Parser_stagedId_found_o->modifiers = 0x0;
        Fast_Parser_stagedId_found_o->state = 0x6;
        Fast_Parser_stagedId_found_o->weak = FALSE;
        Fast_Parser_stagedId_found_o->id = 1;
        if (cx_define(Fast_Parser_stagedId_found_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::stagedId::found'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::stagedId::line */
    Fast_Parser_stagedId_line_o = cx_declare(Fast_Parser_stagedId_o, "line", cx_type(cx_member_o));
    if (!Fast_Parser_stagedId_line_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::stagedId::line'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::stagedId::line */
    if (!cx_checkState(Fast_Parser_stagedId_line_o, CX_DEFINED)) {
        Fast_Parser_stagedId_line_o->type = cx_resolve_ext(Fast_Parser_stagedId_line_o, NULL, "::cortex::lang::uint32", FALSE, "element ::cortex::Fast::Parser::stagedId::line.type");
        Fast_Parser_stagedId_line_o->modifiers = 0x0;
        Fast_Parser_stagedId_line_o->state = 0x6;
        Fast_Parser_stagedId_line_o->weak = FALSE;
        Fast_Parser_stagedId_line_o->id = 2;
        if (cx_define(Fast_Parser_stagedId_line_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::stagedId::line'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::stagedId::name */
    Fast_Parser_stagedId_name_o = cx_declare(Fast_Parser_stagedId_o, "name", cx_type(cx_member_o));
    if (!Fast_Parser_stagedId_name_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::stagedId::name'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::stagedId::name */
    if (!cx_checkState(Fast_Parser_stagedId_name_o, CX_DEFINED)) {
        Fast_Parser_stagedId_name_o->type = cx_resolve_ext(Fast_Parser_stagedId_name_o, NULL, "::cortex::lang::string", FALSE, "element ::cortex::Fast::Parser::stagedId::name.type");
        Fast_Parser_stagedId_name_o->modifiers = 0x0;
        Fast_Parser_stagedId_name_o->state = 0x6;
        Fast_Parser_stagedId_name_o->weak = FALSE;
        Fast_Parser_stagedId_name_o->id = 0;
        if (cx_define(Fast_Parser_stagedId_name_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::stagedId::name'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::Parser::stagedId */
    if (!cx_checkState(Fast_Parser_stagedId_o, CX_DEFINED)) {
        cx_type(Fast_Parser_stagedId_o)->defaultType = cx_resolve_ext(Fast_Parser_stagedId_o, NULL, "::cortex::lang::member", FALSE, "element ::cortex::Fast::Parser::stagedId.defaultType");
        cx_type(Fast_Parser_stagedId_o)->parentType = NULL;
        cx_type(Fast_Parser_stagedId_o)->parentState = 0x0;
        cx_interface(Fast_Parser_stagedId_o)->base = NULL;
        Fast_Parser_stagedId_o->baseAccess = 0x0;
        if (cx_define(Fast_Parser_stagedId_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::stagedId'.");
            goto error;
        }
    }

    if (cx_type(Fast_Parser_stagedId_o)->size != sizeof(Fast_Parser_stagedId)) {
        cx_error("Fast_load: calculated size '%d' of type '::cortex::Fast::Parser::stagedId' doesn't match C-type size '%d'", cx_type(Fast_Parser_stagedId_o)->size, sizeof(Fast_Parser_stagedId));
    }

    /* Define ::cortex::Fast::Parser::staged */
    if (!cx_checkState(Fast_Parser_staged_o, CX_DEFINED)) {
        Fast_Parser_staged_o->type = cx_resolve_ext(Fast_Parser_staged_o, NULL, "::cortex::lang::array{::cortex::Fast::Parser::stagedId,64,::cortex::Fast::Parser::stagedId}", FALSE, "element ::cortex::Fast::Parser::staged.type");
        Fast_Parser_staged_o->modifiers = 0x3;
        Fast_Parser_staged_o->state = 0x6;
        Fast_Parser_staged_o->weak = FALSE;
        Fast_Parser_staged_o->id = 32;
        if (cx_define(Fast_Parser_staged_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::staged'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::stagingAllowed */
    Fast_Parser_stagingAllowed_o = cx_declare(Fast_Parser_o, "stagingAllowed", cx_type(cx_member_o));
    if (!Fast_Parser_stagingAllowed_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::stagingAllowed'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::stagingAllowed */
    if (!cx_checkState(Fast_Parser_stagingAllowed_o, CX_DEFINED)) {
        Fast_Parser_stagingAllowed_o->type = cx_resolve_ext(Fast_Parser_stagingAllowed_o, NULL, "::cortex::lang::bool", FALSE, "element ::cortex::Fast::Parser::stagingAllowed.type");
        Fast_Parser_stagingAllowed_o->modifiers = 0x3;
        Fast_Parser_stagingAllowed_o->state = 0x6;
        Fast_Parser_stagingAllowed_o->weak = FALSE;
        Fast_Parser_stagingAllowed_o->id = 34;
        if (cx_define(Fast_Parser_stagingAllowed_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::stagingAllowed'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::token */
    Fast_Parser_token_o = cx_declare(Fast_Parser_o, "token", cx_type(cx_member_o));
    if (!Fast_Parser_token_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::token'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::token */
    if (!cx_checkState(Fast_Parser_token_o, CX_DEFINED)) {
        Fast_Parser_token_o->type = cx_resolve_ext(Fast_Parser_token_o, NULL, "::cortex::lang::string", FALSE, "element ::cortex::Fast::Parser::token.type");
        Fast_Parser_token_o->modifiers = 0x4;
        Fast_Parser_token_o->state = 0x6;
        Fast_Parser_token_o->weak = FALSE;
        Fast_Parser_token_o->id = 6;
        if (cx_define(Fast_Parser_token_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::token'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::variableCount */
    Fast_Parser_variableCount_o = cx_declare(Fast_Parser_o, "variableCount", cx_type(cx_member_o));
    if (!Fast_Parser_variableCount_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::variableCount'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::variableCount */
    if (!cx_checkState(Fast_Parser_variableCount_o, CX_DEFINED)) {
        Fast_Parser_variableCount_o->type = cx_resolve_ext(Fast_Parser_variableCount_o, NULL, "::cortex::lang::uint32", FALSE, "element ::cortex::Fast::Parser::variableCount.type");
        Fast_Parser_variableCount_o->modifiers = 0x6;
        Fast_Parser_variableCount_o->state = 0x6;
        Fast_Parser_variableCount_o->weak = FALSE;
        Fast_Parser_variableCount_o->id = 25;
        if (cx_define(Fast_Parser_variableCount_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::variableCount'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::variablePushed */
    Fast_Parser_variablePushed_o = cx_declare(Fast_Parser_o, "variablePushed", cx_type(cx_member_o));
    if (!Fast_Parser_variablePushed_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::variablePushed'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::variablePushed */
    if (!cx_checkState(Fast_Parser_variablePushed_o, CX_DEFINED)) {
        Fast_Parser_variablePushed_o->type = cx_resolve_ext(Fast_Parser_variablePushed_o, NULL, "::cortex::lang::bool", FALSE, "element ::cortex::Fast::Parser::variablePushed.type");
        Fast_Parser_variablePushed_o->modifiers = 0x6;
        Fast_Parser_variablePushed_o->state = 0x6;
        Fast_Parser_variablePushed_o->weak = FALSE;
        Fast_Parser_variablePushed_o->id = 27;
        if (cx_define(Fast_Parser_variablePushed_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::variablePushed'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::variables */
    Fast_Parser_variables_o = cx_declare(Fast_Parser_o, "variables", cx_type(cx_member_o));
    if (!Fast_Parser_variables_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::variables'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Parser::variablesInitialized */
    Fast_Parser_variablesInitialized_o = cx_declare(Fast_Parser_o, "variablesInitialized", cx_type(cx_member_o));
    if (!Fast_Parser_variablesInitialized_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::variablesInitialized'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::variablesInitialized */
    if (!cx_checkState(Fast_Parser_variablesInitialized_o, CX_DEFINED)) {
        Fast_Parser_variablesInitialized_o->type = cx_resolve_ext(Fast_Parser_variablesInitialized_o, NULL, "::cortex::lang::bool", FALSE, "element ::cortex::Fast::Parser::variablesInitialized.type");
        Fast_Parser_variablesInitialized_o->modifiers = 0x6;
        Fast_Parser_variablesInitialized_o->state = 0x6;
        Fast_Parser_variablesInitialized_o->weak = FALSE;
        Fast_Parser_variablesInitialized_o->id = 26;
        if (cx_define(Fast_Parser_variablesInitialized_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::variablesInitialized'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::warnings */
    Fast_Parser_warnings_o = cx_declare(Fast_Parser_o, "warnings", cx_type(cx_member_o));
    if (!Fast_Parser_warnings_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::warnings'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::warnings */
    if (!cx_checkState(Fast_Parser_warnings_o, CX_DEFINED)) {
        Fast_Parser_warnings_o->type = cx_resolve_ext(Fast_Parser_warnings_o, NULL, "::cortex::lang::uint32", FALSE, "element ::cortex::Fast::Parser::warnings.type");
        Fast_Parser_warnings_o->modifiers = 0x4;
        Fast_Parser_warnings_o->state = 0x6;
        Fast_Parser_warnings_o->weak = FALSE;
        Fast_Parser_warnings_o->id = 11;
        if (cx_define(Fast_Parser_warnings_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::warnings'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::ParserDeclaration */
    Fast_ParserDeclaration_o = cx_declare(Fast_o, "ParserDeclaration", cx_type(cx_struct_o));
    if (!Fast_ParserDeclaration_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::ParserDeclaration'.");
        goto error;
    }

    /* Declare ::cortex::Fast::ParserDeclaration::name */
    Fast_ParserDeclaration_name_o = cx_declare(Fast_ParserDeclaration_o, "name", cx_type(cx_member_o));
    if (!Fast_ParserDeclaration_name_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::ParserDeclaration::name'.");
        goto error;
    }

    /* Define ::cortex::Fast::ParserDeclaration::name */
    if (!cx_checkState(Fast_ParserDeclaration_name_o, CX_DEFINED)) {
        Fast_ParserDeclaration_name_o->type = cx_resolve_ext(Fast_ParserDeclaration_name_o, NULL, "::cortex::lang::string", FALSE, "element ::cortex::Fast::ParserDeclaration::name.type");
        Fast_ParserDeclaration_name_o->modifiers = 0x0;
        Fast_ParserDeclaration_name_o->state = 0x6;
        Fast_ParserDeclaration_name_o->weak = FALSE;
        Fast_ParserDeclaration_name_o->id = 0;
        if (cx_define(Fast_ParserDeclaration_name_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::ParserDeclaration::name'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::ParserDeclaration::variable */
    Fast_ParserDeclaration_variable_o = cx_declare(Fast_ParserDeclaration_o, "variable", cx_type(cx_member_o));
    if (!Fast_ParserDeclaration_variable_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::ParserDeclaration::variable'.");
        goto error;
    }

    /* Declare ::cortex::Fast::ParserDeclarationSeq */
    Fast_ParserDeclarationSeq_o = cx_declare(Fast_o, "ParserDeclarationSeq", cx_type(cx_sequence_o));
    if (!Fast_ParserDeclarationSeq_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::ParserDeclarationSeq'.");
        goto error;
    }

    /* Define ::cortex::Fast::ParserDeclarationSeq */
    if (!cx_checkState(Fast_ParserDeclarationSeq_o, CX_DEFINED)) {
        cx_collection(Fast_ParserDeclarationSeq_o)->elementType = cx_resolve_ext(Fast_ParserDeclarationSeq_o, NULL, "::cortex::Fast::ParserDeclaration", FALSE, "element ::cortex::Fast::ParserDeclarationSeq.elementType");
        cx_collection(Fast_ParserDeclarationSeq_o)->max = 256;
        if (cx_define(Fast_ParserDeclarationSeq_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::ParserDeclarationSeq'.");
            goto error;
        }
    }

    if (cx_type(Fast_ParserDeclarationSeq_o)->size != sizeof(Fast_ParserDeclarationSeq)) {
        cx_error("Fast_load: calculated size '%d' of type '::cortex::Fast::ParserDeclarationSeq' doesn't match C-type size '%d'", cx_type(Fast_ParserDeclarationSeq_o)->size, sizeof(Fast_ParserDeclarationSeq));
    }

    /* Declare ::cortex::Fast::ParserNew */
    Fast_ParserNew_o = cx_declare(Fast_o, "ParserNew", cx_type(cx_struct_o));
    if (!Fast_ParserNew_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::ParserNew'.");
        goto error;
    }

    /* Declare ::cortex::Fast::ParserNew::attr */
    Fast_ParserNew_attr_o = cx_declare(Fast_ParserNew_o, "attr", cx_type(cx_member_o));
    if (!Fast_ParserNew_attr_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::ParserNew::attr'.");
        goto error;
    }

    /* Declare ::cortex::Fast::ParserNew::kind */
    Fast_ParserNew_kind_o = cx_declare(Fast_ParserNew_o, "kind", cx_type(cx_member_o));
    if (!Fast_ParserNew_kind_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::ParserNew::kind'.");
        goto error;
    }

    /* Define ::cortex::Fast::ParserNew::kind */
    if (!cx_checkState(Fast_ParserNew_kind_o, CX_DEFINED)) {
        Fast_ParserNew_kind_o->type = cx_resolve_ext(Fast_ParserNew_kind_o, NULL, "::cortex::Fast::nodeKind", FALSE, "element ::cortex::Fast::ParserNew::kind.type");
        Fast_ParserNew_kind_o->modifiers = 0x0;
        Fast_ParserNew_kind_o->state = 0x6;
        Fast_ParserNew_kind_o->weak = FALSE;
        Fast_ParserNew_kind_o->id = 0;
        if (cx_define(Fast_ParserNew_kind_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::ParserNew::kind'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::ParserNew::name */
    Fast_ParserNew_name_o = cx_declare(Fast_ParserNew_o, "name", cx_type(cx_member_o));
    if (!Fast_ParserNew_name_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::ParserNew::name'.");
        goto error;
    }

    /* Declare ::cortex::Fast::ParserNew::parent */
    Fast_ParserNew_parent_o = cx_declare(Fast_ParserNew_o, "parent", cx_type(cx_member_o));
    if (!Fast_ParserNew_parent_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::ParserNew::parent'.");
        goto error;
    }

    /* Declare ::cortex::Fast::PostFix */
    Fast_PostFix_o = cx_declare(Fast_o, "PostFix", cx_type(cx_class_o));
    if (!Fast_PostFix_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::PostFix'.");
        goto error;
    }

    /* Declare ::cortex::Fast::PostFix::lvalue */
    Fast_PostFix_lvalue_o = cx_declare(Fast_PostFix_o, "lvalue", cx_type(cx_member_o));
    if (!Fast_PostFix_lvalue_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::PostFix::lvalue'.");
        goto error;
    }

    /* Declare ::cortex::Fast::PostFix::operator */
    Fast_PostFix_operator_o = cx_declare(Fast_PostFix_o, "operator", cx_type(cx_member_o));
    if (!Fast_PostFix_operator_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::PostFix::operator'.");
        goto error;
    }

    /* Define ::cortex::Fast::PostFix::operator */
    if (!cx_checkState(Fast_PostFix_operator_o, CX_DEFINED)) {
        Fast_PostFix_operator_o->type = cx_resolve_ext(Fast_PostFix_operator_o, NULL, "::cortex::lang::operatorKind", FALSE, "element ::cortex::Fast::PostFix::operator.type");
        Fast_PostFix_operator_o->modifiers = 0x0;
        Fast_PostFix_operator_o->state = 0x6;
        Fast_PostFix_operator_o->weak = FALSE;
        Fast_PostFix_operator_o->id = 1;
        if (cx_define(Fast_PostFix_operator_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::PostFix::operator'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::report(string kind,string filename,uint32 line,uint32 column,string error,string token) */
    Fast_report_o = cx_declare(Fast_o, "report(string kind,string filename,uint32 line,uint32 column,string error,string token)", cx_type(cx_function_o));
    if (!Fast_report_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::report(string kind,string filename,uint32 line,uint32 column,string error,string token)'.");
        goto error;
    }

    /* Define ::cortex::Fast::report(string kind,string filename,uint32 line,uint32 column,string error,string token) */
    if (!cx_checkState(Fast_report_o, CX_DEFINED)) {
        Fast_report_o->returnType = cx_resolve_ext(Fast_report_o, NULL, "::cortex::lang::void", FALSE, "element ::cortex::Fast::report(string kind,string filename,uint32 line,uint32 column,string error,string token).returnType");
        Fast_report_o->returnsReference = FALSE;
        
        /* Bind ::cortex::Fast::report(string kind,string filename,uint32 line,uint32 column,string error,string token) with C-function */
        cx_function(Fast_report_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_report(void *args, void *result);
        cx_function(Fast_report_o)->impl = (cx_word)__Fast_report;
        if (cx_define(Fast_report_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::report(string kind,string filename,uint32 line,uint32 column,string error,string token)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::reportError(string filename,uint32 line,uint32 column,string error,string token) */
    Fast_reportError_o = cx_declare(Fast_o, "reportError(string filename,uint32 line,uint32 column,string error,string token)", cx_type(cx_function_o));
    if (!Fast_reportError_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::reportError(string filename,uint32 line,uint32 column,string error,string token)'.");
        goto error;
    }

    /* Define ::cortex::Fast::reportError(string filename,uint32 line,uint32 column,string error,string token) */
    if (!cx_checkState(Fast_reportError_o, CX_DEFINED)) {
        Fast_reportError_o->returnType = cx_resolve_ext(Fast_reportError_o, NULL, "::cortex::lang::void", FALSE, "element ::cortex::Fast::reportError(string filename,uint32 line,uint32 column,string error,string token).returnType");
        Fast_reportError_o->returnsReference = FALSE;
        
        /* Bind ::cortex::Fast::reportError(string filename,uint32 line,uint32 column,string error,string token) with C-function */
        cx_function(Fast_reportError_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_reportError(void *args, void *result);
        cx_function(Fast_reportError_o)->impl = (cx_word)__Fast_reportError;
        if (cx_define(Fast_reportError_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::reportError(string filename,uint32 line,uint32 column,string error,string token)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::reportWarning(string filename,uint32 line,uint32 column,string error,string token) */
    Fast_reportWarning_o = cx_declare(Fast_o, "reportWarning(string filename,uint32 line,uint32 column,string error,string token)", cx_type(cx_function_o));
    if (!Fast_reportWarning_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::reportWarning(string filename,uint32 line,uint32 column,string error,string token)'.");
        goto error;
    }

    /* Define ::cortex::Fast::reportWarning(string filename,uint32 line,uint32 column,string error,string token) */
    if (!cx_checkState(Fast_reportWarning_o, CX_DEFINED)) {
        Fast_reportWarning_o->returnType = cx_resolve_ext(Fast_reportWarning_o, NULL, "::cortex::lang::void", FALSE, "element ::cortex::Fast::reportWarning(string filename,uint32 line,uint32 column,string error,string token).returnType");
        Fast_reportWarning_o->returnsReference = FALSE;
        
        /* Bind ::cortex::Fast::reportWarning(string filename,uint32 line,uint32 column,string error,string token) with C-function */
        cx_function(Fast_reportWarning_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_reportWarning(void *args, void *result);
        cx_function(Fast_reportWarning_o)->impl = (cx_word)__Fast_reportWarning;
        if (cx_define(Fast_reportWarning_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::reportWarning(string filename,uint32 line,uint32 column,string error,string token)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::SignedInteger */
    Fast_SignedInteger_o = cx_declare(Fast_o, "SignedInteger", cx_type(cx_class_o));
    if (!Fast_SignedInteger_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::SignedInteger'.");
        goto error;
    }

    /* Declare ::cortex::Fast::SignedInteger::value */
    Fast_SignedInteger_value_o = cx_declare(Fast_SignedInteger_o, "value", cx_type(cx_member_o));
    if (!Fast_SignedInteger_value_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::SignedInteger::value'.");
        goto error;
    }

    /* Define ::cortex::Fast::SignedInteger::value */
    if (!cx_checkState(Fast_SignedInteger_value_o, CX_DEFINED)) {
        Fast_SignedInteger_value_o->type = cx_resolve_ext(Fast_SignedInteger_value_o, NULL, "::cortex::lang::int64", FALSE, "element ::cortex::Fast::SignedInteger::value.type");
        Fast_SignedInteger_value_o->modifiers = 0x0;
        Fast_SignedInteger_value_o->state = 0x6;
        Fast_SignedInteger_value_o->weak = FALSE;
        Fast_SignedInteger_value_o->id = 0;
        if (cx_define(Fast_SignedInteger_value_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::SignedInteger::value'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::StaticCall */
    Fast_StaticCall_o = cx_declare(Fast_o, "StaticCall", cx_type(cx_class_o));
    if (!Fast_StaticCall_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::StaticCall'.");
        goto error;
    }

    /* Declare ::cortex::Fast::StaticCall::function */
    Fast_StaticCall_function_o = cx_declare(Fast_StaticCall_o, "function", cx_type(cx_member_o));
    if (!Fast_StaticCall_function_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::StaticCall::function'.");
        goto error;
    }

    /* Define ::cortex::Fast::StaticCall::function */
    if (!cx_checkState(Fast_StaticCall_function_o, CX_DEFINED)) {
        Fast_StaticCall_function_o->type = cx_resolve_ext(Fast_StaticCall_function_o, NULL, "::cortex::lang::function", FALSE, "element ::cortex::Fast::StaticCall::function.type");
        Fast_StaticCall_function_o->modifiers = 0x0;
        Fast_StaticCall_function_o->state = 0x6;
        Fast_StaticCall_function_o->weak = FALSE;
        Fast_StaticCall_function_o->id = 0;
        if (cx_define(Fast_StaticCall_function_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::StaticCall::function'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::StaticInitializer */
    Fast_StaticInitializer_o = cx_declare(Fast_o, "StaticInitializer", cx_type(cx_class_o));
    if (!Fast_StaticInitializer_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::StaticInitializer'.");
        goto error;
    }

    /* Declare ::cortex::Fast::StaticInitializer::frames */
    Fast_StaticInitializer_frames_o = cx_declare(Fast_StaticInitializer_o, "frames", cx_type(cx_member_o));
    if (!Fast_StaticInitializer_frames_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::StaticInitializer::frames'.");
        goto error;
    }

    /* Declare ::cortex::Fast::StaticInitializerFrame */
    Fast_StaticInitializerFrame_o = cx_declare(Fast_o, "StaticInitializerFrame", cx_type(cx_struct_o));
    if (!Fast_StaticInitializerFrame_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::StaticInitializerFrame'.");
        goto error;
    }

    /* Declare ::cortex::Fast::StaticInitializerFrame::keyPtr */
    Fast_StaticInitializerFrame_keyPtr_o = cx_declare(Fast_StaticInitializerFrame_o, "keyPtr", cx_type(cx_member_o));
    if (!Fast_StaticInitializerFrame_keyPtr_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::StaticInitializerFrame::keyPtr'.");
        goto error;
    }

    /* Declare ::cortex::Fast::StaticInitializerFrame::ptr */
    Fast_StaticInitializerFrame_ptr_o = cx_declare(Fast_StaticInitializerFrame_o, "ptr", cx_type(cx_member_o));
    if (!Fast_StaticInitializerFrame_ptr_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::StaticInitializerFrame::ptr'.");
        goto error;
    }

    /* Declare ::cortex::Fast::String */
    Fast_String_o = cx_declare(Fast_o, "String", cx_type(cx_class_o));
    if (!Fast_String_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::String'.");
        goto error;
    }

    /* Declare ::cortex::Fast::String::block */
    Fast_String_block_o = cx_declare(Fast_String_o, "block", cx_type(cx_member_o));
    if (!Fast_String_block_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::String::block'.");
        goto error;
    }

    /* Declare ::cortex::Fast::String::elements */
    Fast_String_elements_o = cx_declare(Fast_String_o, "elements", cx_type(cx_member_o));
    if (!Fast_String_elements_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::String::elements'.");
        goto error;
    }

    /* Define ::cortex::Fast::String::elements */
    if (!cx_checkState(Fast_String_elements_o, CX_DEFINED)) {
        Fast_String_elements_o->type = cx_resolve_ext(Fast_String_elements_o, NULL, "::cortex::lang::list{::cortex::Fast::Expression,0}", FALSE, "element ::cortex::Fast::String::elements.type");
        Fast_String_elements_o->modifiers = 0x4;
        Fast_String_elements_o->state = 0x6;
        Fast_String_elements_o->weak = FALSE;
        Fast_String_elements_o->id = 1;
        if (cx_define(Fast_String_elements_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::String::elements'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::String::scope */
    Fast_String_scope_o = cx_declare(Fast_String_o, "scope", cx_type(cx_member_o));
    if (!Fast_String_scope_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::String::scope'.");
        goto error;
    }

    /* Declare ::cortex::Fast::String::value */
    Fast_String_value_o = cx_declare(Fast_String_o, "value", cx_type(cx_member_o));
    if (!Fast_String_value_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::String::value'.");
        goto error;
    }

    /* Define ::cortex::Fast::String::value */
    if (!cx_checkState(Fast_String_value_o, CX_DEFINED)) {
        Fast_String_value_o->type = cx_resolve_ext(Fast_String_value_o, NULL, "::cortex::lang::string", FALSE, "element ::cortex::Fast::String::value.type");
        Fast_String_value_o->modifiers = 0x0;
        Fast_String_value_o->state = 0x6;
        Fast_String_value_o->weak = FALSE;
        Fast_String_value_o->id = 0;
        if (cx_define(Fast_String_value_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::String::value'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Template */
    Fast_Template_o = cx_declare(Fast_o, "Template", cx_type(cx_class_o));
    if (!Fast_Template_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Template'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Ternary */
    Fast_Ternary_o = cx_declare(Fast_o, "Ternary", cx_type(cx_class_o));
    if (!Fast_Ternary_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Ternary'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Ternary::condition */
    Fast_Ternary_condition_o = cx_declare(Fast_Ternary_o, "condition", cx_type(cx_member_o));
    if (!Fast_Ternary_condition_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Ternary::condition'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Ternary::ifFalse */
    Fast_Ternary_ifFalse_o = cx_declare(Fast_Ternary_o, "ifFalse", cx_type(cx_member_o));
    if (!Fast_Ternary_ifFalse_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Ternary::ifFalse'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Ternary::ifFalseExpr */
    Fast_Ternary_ifFalseExpr_o = cx_declare(Fast_Ternary_o, "ifFalseExpr", cx_type(cx_member_o));
    if (!Fast_Ternary_ifFalseExpr_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Ternary::ifFalseExpr'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Ternary::ifstmt */
    Fast_Ternary_ifstmt_o = cx_declare(Fast_Ternary_o, "ifstmt", cx_type(cx_member_o));
    if (!Fast_Ternary_ifstmt_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Ternary::ifstmt'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Ternary::ifTrue */
    Fast_Ternary_ifTrue_o = cx_declare(Fast_Ternary_o, "ifTrue", cx_type(cx_member_o));
    if (!Fast_Ternary_ifTrue_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Ternary::ifTrue'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Ternary::ifTrueExpr */
    Fast_Ternary_ifTrueExpr_o = cx_declare(Fast_Ternary_o, "ifTrueExpr", cx_type(cx_member_o));
    if (!Fast_Ternary_ifTrueExpr_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Ternary::ifTrueExpr'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Ternary::result */
    Fast_Ternary_result_o = cx_declare(Fast_Ternary_o, "result", cx_type(cx_member_o));
    if (!Fast_Ternary_result_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Ternary::result'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Unary */
    Fast_Unary_o = cx_declare(Fast_o, "Unary", cx_type(cx_class_o));
    if (!Fast_Unary_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Unary'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Unary::lvalue */
    Fast_Unary_lvalue_o = cx_declare(Fast_Unary_o, "lvalue", cx_type(cx_member_o));
    if (!Fast_Unary_lvalue_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Unary::lvalue'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Unary::operator */
    Fast_Unary_operator_o = cx_declare(Fast_Unary_o, "operator", cx_type(cx_member_o));
    if (!Fast_Unary_operator_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Unary::operator'.");
        goto error;
    }

    /* Define ::cortex::Fast::Unary::operator */
    if (!cx_checkState(Fast_Unary_operator_o, CX_DEFINED)) {
        Fast_Unary_operator_o->type = cx_resolve_ext(Fast_Unary_operator_o, NULL, "::cortex::lang::operatorKind", FALSE, "element ::cortex::Fast::Unary::operator.type");
        Fast_Unary_operator_o->modifiers = 0x0;
        Fast_Unary_operator_o->state = 0x6;
        Fast_Unary_operator_o->weak = FALSE;
        Fast_Unary_operator_o->id = 1;
        if (cx_define(Fast_Unary_operator_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Unary::operator'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Update */
    Fast_Update_o = cx_declare(Fast_o, "Update", cx_type(cx_class_o));
    if (!Fast_Update_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Update'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Update::block */
    Fast_Update_block_o = cx_declare(Fast_Update_o, "block", cx_type(cx_member_o));
    if (!Fast_Update_block_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Update::block'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Update::exprList */
    Fast_Update_exprList_o = cx_declare(Fast_Update_o, "exprList", cx_type(cx_member_o));
    if (!Fast_Update_exprList_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Update::exprList'.");
        goto error;
    }

    /* Define ::cortex::Fast::Update::exprList */
    if (!cx_checkState(Fast_Update_exprList_o, CX_DEFINED)) {
        Fast_Update_exprList_o->type = cx_resolve_ext(Fast_Update_exprList_o, NULL, "::cortex::lang::list{::cortex::Fast::Expression,0}", FALSE, "element ::cortex::Fast::Update::exprList.type");
        Fast_Update_exprList_o->modifiers = 0x0;
        Fast_Update_exprList_o->state = 0x6;
        Fast_Update_exprList_o->weak = FALSE;
        Fast_Update_exprList_o->id = 0;
        if (cx_define(Fast_Update_exprList_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Update::exprList'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Update::from */
    Fast_Update_from_o = cx_declare(Fast_Update_o, "from", cx_type(cx_member_o));
    if (!Fast_Update_from_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Update::from'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Update::kind */
    Fast_Update_kind_o = cx_declare(Fast_Update_o, "kind", cx_type(cx_member_o));
    if (!Fast_Update_kind_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Update::kind'.");
        goto error;
    }

    /* Declare ::cortex::Fast::UpdateKind */
    Fast_UpdateKind_o = cx_declare(Fast_o, "UpdateKind", cx_type(cx_enum_o));
    if (!Fast_UpdateKind_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::UpdateKind'.");
        goto error;
    }

    /* Declare ::cortex::Fast::UpdateKind::UpdateBegin */
    Fast_UpdateKind_UpdateBegin_o = cx_declare(Fast_UpdateKind_o, "UpdateBegin", cx_type(cx_constant_o));
    if (!Fast_UpdateKind_UpdateBegin_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::UpdateKind::UpdateBegin'.");
        goto error;
    }

    /* Define ::cortex::Fast::UpdateKind::UpdateBegin */
    if (!cx_checkState(Fast_UpdateKind_UpdateBegin_o, CX_DEFINED)) {
        if (cx_define(Fast_UpdateKind_UpdateBegin_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::UpdateKind::UpdateBegin'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::UpdateKind::UpdateDefault */
    Fast_UpdateKind_UpdateDefault_o = cx_declare(Fast_UpdateKind_o, "UpdateDefault", cx_type(cx_constant_o));
    if (!Fast_UpdateKind_UpdateDefault_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::UpdateKind::UpdateDefault'.");
        goto error;
    }

    /* Define ::cortex::Fast::UpdateKind::UpdateDefault */
    if (!cx_checkState(Fast_UpdateKind_UpdateDefault_o, CX_DEFINED)) {
        if (cx_define(Fast_UpdateKind_UpdateDefault_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::UpdateKind::UpdateDefault'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::UpdateKind::UpdateEnd */
    Fast_UpdateKind_UpdateEnd_o = cx_declare(Fast_UpdateKind_o, "UpdateEnd", cx_type(cx_constant_o));
    if (!Fast_UpdateKind_UpdateEnd_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::UpdateKind::UpdateEnd'.");
        goto error;
    }

    /* Define ::cortex::Fast::UpdateKind::UpdateEnd */
    if (!cx_checkState(Fast_UpdateKind_UpdateEnd_o, CX_DEFINED)) {
        if (cx_define(Fast_UpdateKind_UpdateEnd_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::UpdateKind::UpdateEnd'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::UpdateKind */
    if (!cx_checkState(Fast_UpdateKind_o, CX_DEFINED)) {
        if (cx_define(Fast_UpdateKind_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::UpdateKind'.");
            goto error;
        }
    }

    if (cx_type(Fast_UpdateKind_o)->size != sizeof(Fast_UpdateKind)) {
        cx_error("Fast_load: calculated size '%d' of type '::cortex::Fast::UpdateKind' doesn't match C-type size '%d'", cx_type(Fast_UpdateKind_o)->size, sizeof(Fast_UpdateKind));
    }

    /* Define ::cortex::Fast::Update::kind */
    if (!cx_checkState(Fast_Update_kind_o, CX_DEFINED)) {
        Fast_Update_kind_o->type = cx_resolve_ext(Fast_Update_kind_o, NULL, "::cortex::Fast::UpdateKind", FALSE, "element ::cortex::Fast::Update::kind.type");
        Fast_Update_kind_o->modifiers = 0x0;
        Fast_Update_kind_o->state = 0x6;
        Fast_Update_kind_o->weak = FALSE;
        Fast_Update_kind_o->id = 3;
        if (cx_define(Fast_Update_kind_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Update::kind'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::valueKind */
    Fast_valueKind_o = cx_declare(Fast_o, "valueKind", cx_type(cx_enum_o));
    if (!Fast_valueKind_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::valueKind'.");
        goto error;
    }

    /* Declare ::cortex::Fast::valueKind::Bool */
    Fast_valueKind_Bool_o = cx_declare(Fast_valueKind_o, "Bool", cx_type(cx_constant_o));
    if (!Fast_valueKind_Bool_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::valueKind::Bool'.");
        goto error;
    }

    /* Define ::cortex::Fast::valueKind::Bool */
    if (!cx_checkState(Fast_valueKind_Bool_o, CX_DEFINED)) {
        if (cx_define(Fast_valueKind_Bool_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::valueKind::Bool'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::valueKind::Char */
    Fast_valueKind_Char_o = cx_declare(Fast_valueKind_o, "Char", cx_type(cx_constant_o));
    if (!Fast_valueKind_Char_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::valueKind::Char'.");
        goto error;
    }

    /* Define ::cortex::Fast::valueKind::Char */
    if (!cx_checkState(Fast_valueKind_Char_o, CX_DEFINED)) {
        if (cx_define(Fast_valueKind_Char_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::valueKind::Char'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::valueKind::Enum */
    Fast_valueKind_Enum_o = cx_declare(Fast_valueKind_o, "Enum", cx_type(cx_constant_o));
    if (!Fast_valueKind_Enum_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::valueKind::Enum'.");
        goto error;
    }

    /* Define ::cortex::Fast::valueKind::Enum */
    if (!cx_checkState(Fast_valueKind_Enum_o, CX_DEFINED)) {
        if (cx_define(Fast_valueKind_Enum_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::valueKind::Enum'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::valueKind::Float */
    Fast_valueKind_Float_o = cx_declare(Fast_valueKind_o, "Float", cx_type(cx_constant_o));
    if (!Fast_valueKind_Float_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::valueKind::Float'.");
        goto error;
    }

    /* Define ::cortex::Fast::valueKind::Float */
    if (!cx_checkState(Fast_valueKind_Float_o, CX_DEFINED)) {
        if (cx_define(Fast_valueKind_Float_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::valueKind::Float'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::valueKind::Int */
    Fast_valueKind_Int_o = cx_declare(Fast_valueKind_o, "Int", cx_type(cx_constant_o));
    if (!Fast_valueKind_Int_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::valueKind::Int'.");
        goto error;
    }

    /* Define ::cortex::Fast::valueKind::Int */
    if (!cx_checkState(Fast_valueKind_Int_o, CX_DEFINED)) {
        if (cx_define(Fast_valueKind_Int_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::valueKind::Int'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::valueKind::Nothing */
    Fast_valueKind_Nothing_o = cx_declare(Fast_valueKind_o, "Nothing", cx_type(cx_constant_o));
    if (!Fast_valueKind_Nothing_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::valueKind::Nothing'.");
        goto error;
    }

    /* Define ::cortex::Fast::valueKind::Nothing */
    if (!cx_checkState(Fast_valueKind_Nothing_o, CX_DEFINED)) {
        if (cx_define(Fast_valueKind_Nothing_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::valueKind::Nothing'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::valueKind::Ref */
    Fast_valueKind_Ref_o = cx_declare(Fast_valueKind_o, "Ref", cx_type(cx_constant_o));
    if (!Fast_valueKind_Ref_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::valueKind::Ref'.");
        goto error;
    }

    /* Define ::cortex::Fast::valueKind::Ref */
    if (!cx_checkState(Fast_valueKind_Ref_o, CX_DEFINED)) {
        if (cx_define(Fast_valueKind_Ref_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::valueKind::Ref'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::valueKind::SignedInt */
    Fast_valueKind_SignedInt_o = cx_declare(Fast_valueKind_o, "SignedInt", cx_type(cx_constant_o));
    if (!Fast_valueKind_SignedInt_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::valueKind::SignedInt'.");
        goto error;
    }

    /* Define ::cortex::Fast::valueKind::SignedInt */
    if (!cx_checkState(Fast_valueKind_SignedInt_o, CX_DEFINED)) {
        if (cx_define(Fast_valueKind_SignedInt_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::valueKind::SignedInt'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::valueKind::Text */
    Fast_valueKind_Text_o = cx_declare(Fast_valueKind_o, "Text", cx_type(cx_constant_o));
    if (!Fast_valueKind_Text_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::valueKind::Text'.");
        goto error;
    }

    /* Define ::cortex::Fast::valueKind::Text */
    if (!cx_checkState(Fast_valueKind_Text_o, CX_DEFINED)) {
        if (cx_define(Fast_valueKind_Text_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::valueKind::Text'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::valueKind */
    if (!cx_checkState(Fast_valueKind_o, CX_DEFINED)) {
        if (cx_define(Fast_valueKind_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::valueKind'.");
            goto error;
        }
    }

    if (cx_type(Fast_valueKind_o)->size != sizeof(Fast_valueKind)) {
        cx_error("Fast_load: calculated size '%d' of type '::cortex::Fast::valueKind' doesn't match C-type size '%d'", cx_type(Fast_valueKind_o)->size, sizeof(Fast_valueKind));
    }

    /* Define ::cortex::Fast::Literal::kind */
    if (!cx_checkState(Fast_Literal_kind_o, CX_DEFINED)) {
        Fast_Literal_kind_o->type = cx_resolve_ext(Fast_Literal_kind_o, NULL, "::cortex::Fast::valueKind", FALSE, "element ::cortex::Fast::Literal::kind.type");
        Fast_Literal_kind_o->modifiers = 0x0;
        Fast_Literal_kind_o->state = 0x6;
        Fast_Literal_kind_o->weak = FALSE;
        Fast_Literal_kind_o->id = 0;
        if (cx_define(Fast_Literal_kind_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Literal::kind'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::valueKindFromType(lang::type type) */
    Fast_valueKindFromType_o = cx_declare(Fast_o, "valueKindFromType(lang::type type)", cx_type(cx_function_o));
    if (!Fast_valueKindFromType_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::valueKindFromType(lang::type type)'.");
        goto error;
    }

    /* Define ::cortex::Fast::valueKindFromType(lang::type type) */
    if (!cx_checkState(Fast_valueKindFromType_o, CX_DEFINED)) {
        Fast_valueKindFromType_o->returnType = cx_resolve_ext(Fast_valueKindFromType_o, NULL, "::cortex::Fast::valueKind", FALSE, "element ::cortex::Fast::valueKindFromType(lang::type type).returnType");
        Fast_valueKindFromType_o->returnsReference = FALSE;
        
        /* Bind ::cortex::Fast::valueKindFromType(lang::type type) with C-function */
        cx_function(Fast_valueKindFromType_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_valueKindFromType(void *args, void *result);
        cx_function(Fast_valueKindFromType_o)->impl = (cx_word)__Fast_valueKindFromType;
        if (cx_define(Fast_valueKindFromType_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::valueKindFromType(lang::type type)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Variable */
    Fast_Variable_o = cx_declare(Fast_o, "Variable", cx_type(cx_class_o));
    if (!Fast_Variable_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Variable'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::pushScope() */
    if (!cx_checkState(Fast_Parser_pushScope_o, CX_DEFINED)) {
        cx_function(Fast_Parser_pushScope_o)->returnType = cx_resolve_ext(Fast_Parser_pushScope_o, NULL, "::cortex::Fast::Variable", FALSE, "element ::cortex::Fast::Parser::pushScope().returnType");
        cx_function(Fast_Parser_pushScope_o)->returnsReference = FALSE;
        Fast_Parser_pushScope_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Parser::pushScope() with C-function */
        cx_function(Fast_Parser_pushScope_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Parser_pushScope(void *args, void *result);
        cx_function(Fast_Parser_pushScope_o)->impl = (cx_word)__Fast_Parser_pushScope;
        if (cx_define(Fast_Parser_pushScope_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::pushScope()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Variable::kind */
    Fast_Variable_kind_o = cx_declare(Fast_Variable_o, "kind", cx_type(cx_member_o));
    if (!Fast_Variable_kind_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Variable::kind'.");
        goto error;
    }

    /* Declare ::cortex::Fast::variableKind */
    Fast_variableKind_o = cx_declare(Fast_o, "variableKind", cx_type(cx_enum_o));
    if (!Fast_variableKind_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::variableKind'.");
        goto error;
    }

    /* Declare ::cortex::Fast::variableKind::LocalExpr */
    Fast_variableKind_LocalExpr_o = cx_declare(Fast_variableKind_o, "LocalExpr", cx_type(cx_constant_o));
    if (!Fast_variableKind_LocalExpr_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::variableKind::LocalExpr'.");
        goto error;
    }

    /* Define ::cortex::Fast::variableKind::LocalExpr */
    if (!cx_checkState(Fast_variableKind_LocalExpr_o, CX_DEFINED)) {
        if (cx_define(Fast_variableKind_LocalExpr_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::variableKind::LocalExpr'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::variableKind::ObjectExpr */
    Fast_variableKind_ObjectExpr_o = cx_declare(Fast_variableKind_o, "ObjectExpr", cx_type(cx_constant_o));
    if (!Fast_variableKind_ObjectExpr_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::variableKind::ObjectExpr'.");
        goto error;
    }

    /* Define ::cortex::Fast::variableKind::ObjectExpr */
    if (!cx_checkState(Fast_variableKind_ObjectExpr_o, CX_DEFINED)) {
        if (cx_define(Fast_variableKind_ObjectExpr_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::variableKind::ObjectExpr'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::variableKind::TemplateExpr */
    Fast_variableKind_TemplateExpr_o = cx_declare(Fast_variableKind_o, "TemplateExpr", cx_type(cx_constant_o));
    if (!Fast_variableKind_TemplateExpr_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::variableKind::TemplateExpr'.");
        goto error;
    }

    /* Define ::cortex::Fast::variableKind::TemplateExpr */
    if (!cx_checkState(Fast_variableKind_TemplateExpr_o, CX_DEFINED)) {
        if (cx_define(Fast_variableKind_TemplateExpr_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::variableKind::TemplateExpr'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::variableKind */
    if (!cx_checkState(Fast_variableKind_o, CX_DEFINED)) {
        if (cx_define(Fast_variableKind_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::variableKind'.");
            goto error;
        }
    }

    if (cx_type(Fast_variableKind_o)->size != sizeof(Fast_variableKind)) {
        cx_error("Fast_load: calculated size '%d' of type '::cortex::Fast::variableKind' doesn't match C-type size '%d'", cx_type(Fast_variableKind_o)->size, sizeof(Fast_variableKind));
    }

    /* Define ::cortex::Fast::Variable::kind */
    if (!cx_checkState(Fast_Variable_kind_o, CX_DEFINED)) {
        Fast_Variable_kind_o->type = cx_resolve_ext(Fast_Variable_kind_o, NULL, "::cortex::Fast::variableKind", FALSE, "element ::cortex::Fast::Variable::kind.type");
        Fast_Variable_kind_o->modifiers = 0x0;
        Fast_Variable_kind_o->state = 0x6;
        Fast_Variable_kind_o->weak = FALSE;
        Fast_Variable_kind_o->id = 0;
        if (cx_define(Fast_Variable_kind_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Variable::kind'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Wait */
    Fast_Wait_o = cx_declare(Fast_o, "Wait", cx_type(cx_class_o));
    if (!Fast_Wait_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Wait'.");
        goto error;
    }

    /* Declare ::cortex::Fast::Wait::exprList */
    Fast_Wait_exprList_o = cx_declare(Fast_Wait_o, "exprList", cx_type(cx_member_o));
    if (!Fast_Wait_exprList_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Wait::exprList'.");
        goto error;
    }

    /* Define ::cortex::Fast::Wait::exprList */
    if (!cx_checkState(Fast_Wait_exprList_o, CX_DEFINED)) {
        Fast_Wait_exprList_o->type = cx_resolve_ext(Fast_Wait_exprList_o, NULL, "::cortex::lang::list{::cortex::Fast::Expression,0}", FALSE, "element ::cortex::Fast::Wait::exprList.type");
        Fast_Wait_exprList_o->modifiers = 0x0;
        Fast_Wait_exprList_o->state = 0x6;
        Fast_Wait_exprList_o->weak = FALSE;
        Fast_Wait_exprList_o->id = 0;
        if (cx_define(Fast_Wait_exprList_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Wait::exprList'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Wait::timeout */
    Fast_Wait_timeout_o = cx_declare(Fast_Wait_o, "timeout", cx_type(cx_member_o));
    if (!Fast_Wait_timeout_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Wait::timeout'.");
        goto error;
    }

    /* Declare ::cortex::Fast::While */
    Fast_While_o = cx_declare(Fast_o, "While", cx_type(cx_class_o));
    if (!Fast_While_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::While'.");
        goto error;
    }

    /* Declare ::cortex::Fast::While::condition */
    Fast_While_condition_o = cx_declare(Fast_While_o, "condition", cx_type(cx_member_o));
    if (!Fast_While_condition_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::While::condition'.");
        goto error;
    }

    /* Declare ::cortex::Fast::While::isUntil */
    Fast_While_isUntil_o = cx_declare(Fast_While_o, "isUntil", cx_type(cx_member_o));
    if (!Fast_While_isUntil_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::While::isUntil'.");
        goto error;
    }

    /* Define ::cortex::Fast::While::isUntil */
    if (!cx_checkState(Fast_While_isUntil_o, CX_DEFINED)) {
        Fast_While_isUntil_o->type = cx_resolve_ext(Fast_While_isUntil_o, NULL, "::cortex::lang::bool", FALSE, "element ::cortex::Fast::While::isUntil.type");
        Fast_While_isUntil_o->modifiers = 0x0;
        Fast_While_isUntil_o->state = 0x6;
        Fast_While_isUntil_o->weak = FALSE;
        Fast_While_isUntil_o->id = 2;
        if (cx_define(Fast_While_isUntil_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::While::isUntil'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::While::trueBranch */
    Fast_While_trueBranch_o = cx_declare(Fast_While_o, "trueBranch", cx_type(cx_member_o));
    if (!Fast_While_trueBranch_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::While::trueBranch'.");
        goto error;
    }

    /* Define ::cortex::Fast::Call::parameters */
    if (!cx_checkState(Fast_Call_parameters_o, CX_DEFINED)) {
        Fast_Call_parameters_o->type = cx_resolve_ext(Fast_Call_parameters_o, NULL, "::cortex::lang::sequence{parameter,0}", FALSE, "element ::cortex::Fast::Call::parameters.type");
        Fast_Call_parameters_o->modifiers = 0x4;
        Fast_Call_parameters_o->state = 0x6;
        Fast_Call_parameters_o->weak = FALSE;
        Fast_Call_parameters_o->id = 6;
        if (cx_define(Fast_Call_parameters_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Call::parameters'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Node::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
    Fast_Node_toIc_o = cx_declare(Fast_Node_o, "toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)", cx_type(cx_virtual_o));
    if (!Fast_Node_toIc_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Node::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Node::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
    if (!cx_checkState(Fast_Node_toIc_o, CX_DEFINED)) {
        cx_function(Fast_Node_toIc_o)->returnType = cx_resolve_ext(Fast_Node_toIc_o, NULL, "::cortex::lang::alias{\"cx_ic\"}", FALSE, "element ::cortex::Fast::Node::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored).returnType");
        cx_function(Fast_Node_toIc_o)->returnsReference = FALSE;
        cx_method(Fast_Node_toIc_o)->virtual = TRUE;
        
        /* Bind ::cortex::Fast::Node::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) with C-function */
        cx_function(Fast_Node_toIc_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Node_toIc_v(void *args, void *result);
        cx_function(Fast_Node_toIc_o)->impl = (cx_word)__Fast_Node_toIc_v;
        if (cx_define(Fast_Node_toIc_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Node::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::Node */
    if (!cx_checkState(Fast_Node_o, CX_DEFINED)) {
        cx_type(Fast_Node_o)->defaultType = cx_resolve_ext(Fast_Node_o, NULL, "::cortex::lang::member", FALSE, "element ::cortex::Fast::Node.defaultType");
        cx_type(Fast_Node_o)->parentType = NULL;
        cx_type(Fast_Node_o)->parentState = 0x0;
        cx_interface(Fast_Node_o)->base = NULL;
        cx_struct(Fast_Node_o)->baseAccess = 0x0;
        Fast_Node_o->implements.length = 0;
        Fast_Node_o->implements.buffer = NULL;
        if (cx_define(Fast_Node_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Node'.");
            goto error;
        }
    }

    if (cx_type(Fast_Node_o)->size != sizeof(struct Fast_Node_s)) {
        cx_error("Fast_load: calculated size '%d' of type '::cortex::Fast::Node' doesn't match C-type size '%d'", cx_type(Fast_Node_o)->size, sizeof(struct Fast_Node_s));
    }

    /* Declare ::cortex::Fast::Block::addStatement(Fast::Node statement) */
    Fast_Block_addStatement_o = cx_declare(Fast_Block_o, "addStatement(Fast::Node statement)", cx_type(cx_method_o));
    if (!Fast_Block_addStatement_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Block::addStatement(Fast::Node statement)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Block::addStatement(Fast::Node statement) */
    if (!cx_checkState(Fast_Block_addStatement_o, CX_DEFINED)) {
        cx_function(Fast_Block_addStatement_o)->returnType = cx_resolve_ext(Fast_Block_addStatement_o, NULL, "::cortex::lang::void", FALSE, "element ::cortex::Fast::Block::addStatement(Fast::Node statement).returnType");
        cx_function(Fast_Block_addStatement_o)->returnsReference = FALSE;
        Fast_Block_addStatement_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Block::addStatement(Fast::Node statement) with C-function */
        cx_function(Fast_Block_addStatement_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Block_addStatement(void *args, void *result);
        cx_function(Fast_Block_addStatement_o)->impl = (cx_word)__Fast_Block_addStatement;
        if (cx_define(Fast_Block_addStatement_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Block::addStatement(Fast::Node statement)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Block::declareReturnVariable(function function) */
    Fast_Block_declareReturnVariable_o = cx_declare(Fast_Block_o, "declareReturnVariable(function function)", cx_type(cx_method_o));
    if (!Fast_Block_declareReturnVariable_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Block::declareReturnVariable(function function)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Block::declareReturnVariable(function function) */
    if (!cx_checkState(Fast_Block_declareReturnVariable_o, CX_DEFINED)) {
        cx_function(Fast_Block_declareReturnVariable_o)->returnType = cx_resolve_ext(Fast_Block_declareReturnVariable_o, NULL, "::cortex::Fast::Local", FALSE, "element ::cortex::Fast::Block::declareReturnVariable(function function).returnType");
        cx_function(Fast_Block_declareReturnVariable_o)->returnsReference = FALSE;
        Fast_Block_declareReturnVariable_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Block::declareReturnVariable(function function) with C-function */
        cx_function(Fast_Block_declareReturnVariable_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Block_declareReturnVariable(void *args, void *result);
        cx_function(Fast_Block_declareReturnVariable_o)->impl = (cx_word)__Fast_Block_declareReturnVariable;
        if (cx_define(Fast_Block_declareReturnVariable_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Block::declareReturnVariable(function function)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Block::lookup(string id) */
    Fast_Block_lookup_o = cx_declare(Fast_Block_o, "lookup(string id)", cx_type(cx_method_o));
    if (!Fast_Block_lookup_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Block::lookup(string id)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Block::lookup(string id) */
    if (!cx_checkState(Fast_Block_lookup_o, CX_DEFINED)) {
        cx_function(Fast_Block_lookup_o)->returnType = cx_resolve_ext(Fast_Block_lookup_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::Block::lookup(string id).returnType");
        cx_function(Fast_Block_lookup_o)->returnsReference = FALSE;
        Fast_Block_lookup_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Block::lookup(string id) with C-function */
        cx_function(Fast_Block_lookup_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Block_lookup(void *args, void *result);
        cx_function(Fast_Block_lookup_o)->impl = (cx_word)__Fast_Block_lookup;
        if (cx_define(Fast_Block_lookup_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Block::lookup(string id)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Block::lookupLocal(string id) */
    Fast_Block_lookupLocal_o = cx_declare(Fast_Block_o, "lookupLocal(string id)", cx_type(cx_method_o));
    if (!Fast_Block_lookupLocal_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Block::lookupLocal(string id)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Block::lookupLocal(string id) */
    if (!cx_checkState(Fast_Block_lookupLocal_o, CX_DEFINED)) {
        cx_function(Fast_Block_lookupLocal_o)->returnType = cx_resolve_ext(Fast_Block_lookupLocal_o, NULL, "::cortex::Fast::Local", FALSE, "element ::cortex::Fast::Block::lookupLocal(string id).returnType");
        cx_function(Fast_Block_lookupLocal_o)->returnsReference = FALSE;
        Fast_Block_lookupLocal_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Block::lookupLocal(string id) with C-function */
        cx_function(Fast_Block_lookupLocal_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Block_lookupLocal(void *args, void *result);
        cx_function(Fast_Block_lookupLocal_o)->impl = (cx_word)__Fast_Block_lookupLocal;
        if (cx_define(Fast_Block_lookupLocal_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Block::lookupLocal(string id)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Block::resolve(string id) */
    Fast_Block_resolve_o = cx_declare(Fast_Block_o, "resolve(string id)", cx_type(cx_method_o));
    if (!Fast_Block_resolve_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Block::resolve(string id)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Block::resolve(string id) */
    if (!cx_checkState(Fast_Block_resolve_o, CX_DEFINED)) {
        cx_function(Fast_Block_resolve_o)->returnType = cx_resolve_ext(Fast_Block_resolve_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::Block::resolve(string id).returnType");
        cx_function(Fast_Block_resolve_o)->returnsReference = FALSE;
        Fast_Block_resolve_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Block::resolve(string id) with C-function */
        cx_function(Fast_Block_resolve_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Block_resolve(void *args, void *result);
        cx_function(Fast_Block_resolve_o)->impl = (cx_word)__Fast_Block_resolve;
        if (cx_define(Fast_Block_resolve_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Block::resolve(string id)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Block::resolveLocal(string id) */
    Fast_Block_resolveLocal_o = cx_declare(Fast_Block_o, "resolveLocal(string id)", cx_type(cx_method_o));
    if (!Fast_Block_resolveLocal_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Block::resolveLocal(string id)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Block::resolveLocal(string id) */
    if (!cx_checkState(Fast_Block_resolveLocal_o, CX_DEFINED)) {
        cx_function(Fast_Block_resolveLocal_o)->returnType = cx_resolve_ext(Fast_Block_resolveLocal_o, NULL, "::cortex::Fast::Local", FALSE, "element ::cortex::Fast::Block::resolveLocal(string id).returnType");
        cx_function(Fast_Block_resolveLocal_o)->returnsReference = FALSE;
        Fast_Block_resolveLocal_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Block::resolveLocal(string id) with C-function */
        cx_function(Fast_Block_resolveLocal_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Block_resolveLocal(void *args, void *result);
        cx_function(Fast_Block_resolveLocal_o)->impl = (cx_word)__Fast_Block_resolveLocal;
        if (cx_define(Fast_Block_resolveLocal_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Block::resolveLocal(string id)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Block::setFunction(function function */
    Fast_Block_setFunction_o = cx_declare(Fast_Block_o, "setFunction(function function", cx_type(cx_method_o));
    if (!Fast_Block_setFunction_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Block::setFunction(function function'.");
        goto error;
    }

    /* Define ::cortex::Fast::Block::setFunction(function function */
    if (!cx_checkState(Fast_Block_setFunction_o, CX_DEFINED)) {
        cx_function(Fast_Block_setFunction_o)->returnType = cx_resolve_ext(Fast_Block_setFunction_o, NULL, "::cortex::lang::void", FALSE, "element ::cortex::Fast::Block::setFunction(function function.returnType");
        cx_function(Fast_Block_setFunction_o)->returnsReference = FALSE;
        Fast_Block_setFunction_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Block::setFunction(function function with C-function */
        cx_function(Fast_Block_setFunction_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Block_setFunction(void *args, void *result);
        cx_function(Fast_Block_setFunction_o)->impl = (cx_word)__Fast_Block_setFunction;
        if (cx_define(Fast_Block_setFunction_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Block::setFunction(function function'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Block::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
    Fast_Block_toIc_o = cx_declare(Fast_Block_o, "toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)", cx_type(cx_virtual_o));
    if (!Fast_Block_toIc_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Block::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Block::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
    if (!cx_checkState(Fast_Block_toIc_o, CX_DEFINED)) {
        cx_function(Fast_Block_toIc_o)->returnType = cx_resolve_ext(Fast_Block_toIc_o, NULL, "::cortex::lang::alias{\"cx_ic\"}", FALSE, "element ::cortex::Fast::Block::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored).returnType");
        cx_function(Fast_Block_toIc_o)->returnsReference = FALSE;
        cx_method(Fast_Block_toIc_o)->virtual = TRUE;
        
        /* Bind ::cortex::Fast::Block::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) with C-function */
        cx_function(Fast_Block_toIc_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Block_toIc_v(void *args, void *result);
        cx_function(Fast_Block_toIc_o)->impl = (cx_word)__Fast_Block_toIc_v;
        if (cx_define(Fast_Block_toIc_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Block::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Block::toIcBody(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
    Fast_Block_toIcBody_o = cx_declare(Fast_Block_o, "toIcBody(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)", cx_type(cx_virtual_o));
    if (!Fast_Block_toIcBody_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Block::toIcBody(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Block::toIcBody(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
    if (!cx_checkState(Fast_Block_toIcBody_o, CX_DEFINED)) {
        cx_function(Fast_Block_toIcBody_o)->returnType = cx_resolve_ext(Fast_Block_toIcBody_o, NULL, "::cortex::lang::alias{\"cx_ic\"}", FALSE, "element ::cortex::Fast::Block::toIcBody(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored).returnType");
        cx_function(Fast_Block_toIcBody_o)->returnsReference = FALSE;
        cx_method(Fast_Block_toIcBody_o)->virtual = TRUE;
        
        /* Bind ::cortex::Fast::Block::toIcBody(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) with C-function */
        cx_function(Fast_Block_toIcBody_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Block_toIcBody_v(void *args, void *result);
        cx_function(Fast_Block_toIcBody_o)->impl = (cx_word)__Fast_Block_toIcBody_v;
        if (cx_define(Fast_Block_toIcBody_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Block::toIcBody(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Define::construct() */
    Fast_Define_construct_o = cx_declare(Fast_Define_o, "construct()", cx_type(cx_method_o));
    if (!Fast_Define_construct_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Define::construct()'.");
        goto error;
    }

    /* Define ::cortex::Fast::Define::construct() */
    if (!cx_checkState(Fast_Define_construct_o, CX_DEFINED)) {
        cx_function(Fast_Define_construct_o)->returnType = cx_resolve_ext(Fast_Define_construct_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::Define::construct().returnType");
        cx_function(Fast_Define_construct_o)->returnsReference = FALSE;
        Fast_Define_construct_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Define::construct() with C-function */
        cx_function(Fast_Define_construct_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Define_construct(void *args, void *result);
        cx_function(Fast_Define_construct_o)->impl = (cx_word)__Fast_Define_construct;
        if (cx_define(Fast_Define_construct_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Define::construct()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Define::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
    Fast_Define_toIc_o = cx_declare(Fast_Define_o, "toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)", cx_type(cx_virtual_o));
    if (!Fast_Define_toIc_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Define::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Define::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
    if (!cx_checkState(Fast_Define_toIc_o, CX_DEFINED)) {
        cx_function(Fast_Define_toIc_o)->returnType = cx_resolve_ext(Fast_Define_toIc_o, NULL, "::cortex::lang::alias{\"cx_ic\"}", FALSE, "element ::cortex::Fast::Define::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored).returnType");
        cx_function(Fast_Define_toIc_o)->returnsReference = FALSE;
        cx_method(Fast_Define_toIc_o)->virtual = TRUE;
        
        /* Bind ::cortex::Fast::Define::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) with C-function */
        cx_function(Fast_Define_toIc_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Define_toIc_v(void *args, void *result);
        cx_function(Fast_Define_toIc_o)->impl = (cx_word)__Fast_Define_toIc_v;
        if (cx_define(Fast_Define_toIc_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Define::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Expression::cast(type type,bool isReference) */
    Fast_Expression_cast_o = cx_declare(Fast_Expression_o, "cast(type type,bool isReference)", cx_type(cx_method_o));
    if (!Fast_Expression_cast_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Expression::cast(type type,bool isReference)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Expression::cast(type type,bool isReference) */
    if (!cx_checkState(Fast_Expression_cast_o, CX_DEFINED)) {
        cx_function(Fast_Expression_cast_o)->returnType = cx_resolve_ext(Fast_Expression_cast_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::Expression::cast(type type,bool isReference).returnType");
        cx_function(Fast_Expression_cast_o)->returnsReference = FALSE;
        Fast_Expression_cast_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Expression::cast(type type,bool isReference) with C-function */
        cx_function(Fast_Expression_cast_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Expression_cast(void *args, void *result);
        cx_function(Fast_Expression_cast_o)->impl = (cx_word)__Fast_Expression_cast;
        if (cx_define(Fast_Expression_cast_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Expression::cast(type type,bool isReference)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Expression::fold() */
    Fast_Expression_fold_o = cx_declare(Fast_Expression_o, "fold()", cx_type(cx_virtual_o));
    if (!Fast_Expression_fold_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Expression::fold()'.");
        goto error;
    }

    /* Define ::cortex::Fast::Expression::fold() */
    if (!cx_checkState(Fast_Expression_fold_o, CX_DEFINED)) {
        cx_function(Fast_Expression_fold_o)->returnType = cx_resolve_ext(Fast_Expression_fold_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::Expression::fold().returnType");
        cx_function(Fast_Expression_fold_o)->returnsReference = FALSE;
        cx_method(Fast_Expression_fold_o)->virtual = TRUE;
        
        /* Bind ::cortex::Fast::Expression::fold() with C-function */
        cx_function(Fast_Expression_fold_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Expression_fold_v(void *args, void *result);
        cx_function(Fast_Expression_fold_o)->impl = (cx_word)__Fast_Expression_fold_v;
        if (cx_define(Fast_Expression_fold_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Expression::fold()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Expression::getType() */
    Fast_Expression_getType_o = cx_declare(Fast_Expression_o, "getType()", cx_type(cx_method_o));
    if (!Fast_Expression_getType_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Expression::getType()'.");
        goto error;
    }

    /* Define ::cortex::Fast::Expression::getType() */
    if (!cx_checkState(Fast_Expression_getType_o, CX_DEFINED)) {
        cx_function(Fast_Expression_getType_o)->returnType = cx_resolve_ext(Fast_Expression_getType_o, NULL, "::cortex::lang::type", FALSE, "element ::cortex::Fast::Expression::getType().returnType");
        cx_function(Fast_Expression_getType_o)->returnsReference = FALSE;
        Fast_Expression_getType_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Expression::getType() with C-function */
        cx_function(Fast_Expression_getType_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Expression_getType(void *args, void *result);
        cx_function(Fast_Expression_getType_o)->impl = (cx_word)__Fast_Expression_getType;
        if (cx_define(Fast_Expression_getType_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Expression::getType()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Expression::getType_type(type target) */
    Fast_Expression_getType_type_o = cx_declare(Fast_Expression_o, "getType_type(type target)", cx_type(cx_method_o));
    if (!Fast_Expression_getType_type_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Expression::getType_type(type target)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Expression::getType_type(type target) */
    if (!cx_checkState(Fast_Expression_getType_type_o, CX_DEFINED)) {
        cx_function(Fast_Expression_getType_type_o)->returnType = cx_resolve_ext(Fast_Expression_getType_type_o, NULL, "::cortex::lang::type", FALSE, "element ::cortex::Fast::Expression::getType_type(type target).returnType");
        cx_function(Fast_Expression_getType_type_o)->returnsReference = FALSE;
        Fast_Expression_getType_type_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Expression::getType_type(type target) with C-function */
        cx_function(Fast_Expression_getType_type_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Expression_getType_type(void *args, void *result);
        cx_function(Fast_Expression_getType_type_o)->impl = (cx_word)__Fast_Expression_getType_type;
        if (cx_define(Fast_Expression_getType_type_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Expression::getType_type(type target)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Expression::getValue() */
    Fast_Expression_getValue_o = cx_declare(Fast_Expression_o, "getValue()", cx_type(cx_virtual_o));
    if (!Fast_Expression_getValue_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Expression::getValue()'.");
        goto error;
    }

    /* Define ::cortex::Fast::Expression::getValue() */
    if (!cx_checkState(Fast_Expression_getValue_o, CX_DEFINED)) {
        cx_function(Fast_Expression_getValue_o)->returnType = cx_resolve_ext(Fast_Expression_getValue_o, NULL, "::cortex::lang::word", FALSE, "element ::cortex::Fast::Expression::getValue().returnType");
        cx_function(Fast_Expression_getValue_o)->returnsReference = FALSE;
        cx_method(Fast_Expression_getValue_o)->virtual = TRUE;
        
        /* Bind ::cortex::Fast::Expression::getValue() with C-function */
        cx_function(Fast_Expression_getValue_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Expression_getValue_v(void *args, void *result);
        cx_function(Fast_Expression_getValue_o)->impl = (cx_word)__Fast_Expression_getValue_v;
        if (cx_define(Fast_Expression_getValue_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Expression::getValue()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Expression::hasSideEffects() */
    Fast_Expression_hasSideEffects_o = cx_declare(Fast_Expression_o, "hasSideEffects()", cx_type(cx_virtual_o));
    if (!Fast_Expression_hasSideEffects_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Expression::hasSideEffects()'.");
        goto error;
    }

    /* Define ::cortex::Fast::Expression::hasSideEffects() */
    if (!cx_checkState(Fast_Expression_hasSideEffects_o, CX_DEFINED)) {
        cx_function(Fast_Expression_hasSideEffects_o)->returnType = cx_resolve_ext(Fast_Expression_hasSideEffects_o, NULL, "::cortex::lang::bool", FALSE, "element ::cortex::Fast::Expression::hasSideEffects().returnType");
        cx_function(Fast_Expression_hasSideEffects_o)->returnsReference = FALSE;
        cx_method(Fast_Expression_hasSideEffects_o)->virtual = TRUE;
        
        /* Bind ::cortex::Fast::Expression::hasSideEffects() with C-function */
        cx_function(Fast_Expression_hasSideEffects_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Expression_hasSideEffects_v(void *args, void *result);
        cx_function(Fast_Expression_hasSideEffects_o)->impl = (cx_word)__Fast_Expression_hasSideEffects_v;
        if (cx_define(Fast_Expression_hasSideEffects_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Expression::hasSideEffects()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Expression::serialize(type dstType,word dst) */
    Fast_Expression_serialize_o = cx_declare(Fast_Expression_o, "serialize(type dstType,word dst)", cx_type(cx_virtual_o));
    if (!Fast_Expression_serialize_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Expression::serialize(type dstType,word dst)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Expression::serialize(type dstType,word dst) */
    if (!cx_checkState(Fast_Expression_serialize_o, CX_DEFINED)) {
        cx_function(Fast_Expression_serialize_o)->returnType = cx_resolve_ext(Fast_Expression_serialize_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::Expression::serialize(type dstType,word dst).returnType");
        cx_function(Fast_Expression_serialize_o)->returnsReference = FALSE;
        cx_method(Fast_Expression_serialize_o)->virtual = TRUE;
        
        /* Bind ::cortex::Fast::Expression::serialize(type dstType,word dst) with C-function */
        cx_function(Fast_Expression_serialize_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Expression_serialize_v(void *args, void *result);
        cx_function(Fast_Expression_serialize_o)->impl = (cx_word)__Fast_Expression_serialize_v;
        if (cx_define(Fast_Expression_serialize_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Expression::serialize(type dstType,word dst)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Expression::toList() */
    Fast_Expression_toList_o = cx_declare(Fast_Expression_o, "toList()", cx_type(cx_virtual_o));
    if (!Fast_Expression_toList_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Expression::toList()'.");
        goto error;
    }

    /* Define ::cortex::Fast::Expression::toList() */
    if (!cx_checkState(Fast_Expression_toList_o, CX_DEFINED)) {
        cx_function(Fast_Expression_toList_o)->returnType = cx_resolve_ext(Fast_Expression_toList_o, NULL, "::cortex::lang::list{::cortex::Fast::Expression,0}", FALSE, "element ::cortex::Fast::Expression::toList().returnType");
        cx_function(Fast_Expression_toList_o)->returnsReference = FALSE;
        cx_method(Fast_Expression_toList_o)->virtual = TRUE;
        
        /* Bind ::cortex::Fast::Expression::toList() with C-function */
        cx_function(Fast_Expression_toList_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Expression_toList_v(void *args, void *result);
        cx_function(Fast_Expression_toList_o)->impl = (cx_word)__Fast_Expression_toList_v;
        if (cx_define(Fast_Expression_toList_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Expression::toList()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::If::construct() */
    Fast_If_construct_o = cx_declare(Fast_If_o, "construct()", cx_type(cx_method_o));
    if (!Fast_If_construct_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::If::construct()'.");
        goto error;
    }

    /* Define ::cortex::Fast::If::construct() */
    if (!cx_checkState(Fast_If_construct_o, CX_DEFINED)) {
        cx_function(Fast_If_construct_o)->returnType = cx_resolve_ext(Fast_If_construct_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::If::construct().returnType");
        cx_function(Fast_If_construct_o)->returnsReference = FALSE;
        Fast_If_construct_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::If::construct() with C-function */
        cx_function(Fast_If_construct_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_If_construct(void *args, void *result);
        cx_function(Fast_If_construct_o)->impl = (cx_word)__Fast_If_construct;
        if (cx_define(Fast_If_construct_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::If::construct()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::If::noWarnUnreachable() */
    Fast_If_noWarnUnreachable_o = cx_declare(Fast_If_o, "noWarnUnreachable()", cx_type(cx_method_o));
    if (!Fast_If_noWarnUnreachable_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::If::noWarnUnreachable()'.");
        goto error;
    }

    /* Define ::cortex::Fast::If::noWarnUnreachable() */
    if (!cx_checkState(Fast_If_noWarnUnreachable_o, CX_DEFINED)) {
        cx_function(Fast_If_noWarnUnreachable_o)->returnType = cx_resolve_ext(Fast_If_noWarnUnreachable_o, NULL, "::cortex::lang::void", FALSE, "element ::cortex::Fast::If::noWarnUnreachable().returnType");
        cx_function(Fast_If_noWarnUnreachable_o)->returnsReference = FALSE;
        Fast_If_noWarnUnreachable_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::If::noWarnUnreachable() with C-function */
        cx_function(Fast_If_noWarnUnreachable_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_If_noWarnUnreachable(void *args, void *result);
        cx_function(Fast_If_noWarnUnreachable_o)->impl = (cx_word)__Fast_If_noWarnUnreachable;
        if (cx_define(Fast_If_noWarnUnreachable_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::If::noWarnUnreachable()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::If::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
    Fast_If_toIc_o = cx_declare(Fast_If_o, "toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)", cx_type(cx_virtual_o));
    if (!Fast_If_toIc_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::If::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)'.");
        goto error;
    }

    /* Define ::cortex::Fast::If::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
    if (!cx_checkState(Fast_If_toIc_o, CX_DEFINED)) {
        cx_function(Fast_If_toIc_o)->returnType = cx_resolve_ext(Fast_If_toIc_o, NULL, "::cortex::lang::alias{\"cx_ic\"}", FALSE, "element ::cortex::Fast::If::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored).returnType");
        cx_function(Fast_If_toIc_o)->returnsReference = FALSE;
        cx_method(Fast_If_toIc_o)->virtual = TRUE;
        
        /* Bind ::cortex::Fast::If::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) with C-function */
        cx_function(Fast_If_toIc_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_If_toIc_v(void *args, void *result);
        cx_function(Fast_If_toIc_o)->impl = (cx_word)__Fast_If_toIc_v;
        if (cx_define(Fast_If_toIc_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::If::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::addStatement(Fast::Node statement) */
    Fast_Parser_addStatement_o = cx_declare(Fast_Parser_o, "addStatement(Fast::Node statement)", cx_type(cx_method_o));
    if (!Fast_Parser_addStatement_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::addStatement(Fast::Node statement)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::addStatement(Fast::Node statement) */
    if (!cx_checkState(Fast_Parser_addStatement_o, CX_DEFINED)) {
        cx_function(Fast_Parser_addStatement_o)->returnType = cx_resolve_ext(Fast_Parser_addStatement_o, NULL, "::cortex::lang::void", FALSE, "element ::cortex::Fast::Parser::addStatement(Fast::Node statement).returnType");
        cx_function(Fast_Parser_addStatement_o)->returnsReference = FALSE;
        Fast_Parser_addStatement_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Parser::addStatement(Fast::Node statement) with C-function */
        cx_function(Fast_Parser_addStatement_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Parser_addStatement(void *args, void *result);
        cx_function(Fast_Parser_addStatement_o)->impl = (cx_word)__Fast_Parser_addStatement;
        if (cx_define(Fast_Parser_addStatement_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::addStatement(Fast::Node statement)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Update::construct() */
    Fast_Update_construct_o = cx_declare(Fast_Update_o, "construct()", cx_type(cx_method_o));
    if (!Fast_Update_construct_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Update::construct()'.");
        goto error;
    }

    /* Define ::cortex::Fast::Update::construct() */
    if (!cx_checkState(Fast_Update_construct_o, CX_DEFINED)) {
        cx_function(Fast_Update_construct_o)->returnType = cx_resolve_ext(Fast_Update_construct_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::Update::construct().returnType");
        cx_function(Fast_Update_construct_o)->returnsReference = FALSE;
        Fast_Update_construct_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Update::construct() with C-function */
        cx_function(Fast_Update_construct_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Update_construct(void *args, void *result);
        cx_function(Fast_Update_construct_o)->impl = (cx_word)__Fast_Update_construct;
        if (cx_define(Fast_Update_construct_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Update::construct()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::While::construct() */
    Fast_While_construct_o = cx_declare(Fast_While_o, "construct()", cx_type(cx_method_o));
    if (!Fast_While_construct_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::While::construct()'.");
        goto error;
    }

    /* Define ::cortex::Fast::While::construct() */
    if (!cx_checkState(Fast_While_construct_o, CX_DEFINED)) {
        cx_function(Fast_While_construct_o)->returnType = cx_resolve_ext(Fast_While_construct_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::While::construct().returnType");
        cx_function(Fast_While_construct_o)->returnsReference = FALSE;
        Fast_While_construct_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::While::construct() with C-function */
        cx_function(Fast_While_construct_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_While_construct(void *args, void *result);
        cx_function(Fast_While_construct_o)->impl = (cx_word)__Fast_While_construct;
        if (cx_define(Fast_While_construct_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::While::construct()'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::Parser::collected */
    if (!cx_checkState(Fast_Parser_collected_o, CX_DEFINED)) {
        Fast_Parser_collected_o->type = cx_resolve_ext(Fast_Parser_collected_o, NULL, "::cortex::lang::list{object,0}", FALSE, "element ::cortex::Fast::Parser::collected.type");
        Fast_Parser_collected_o->modifiers = 0x3;
        Fast_Parser_collected_o->state = 0x6;
        Fast_Parser_collected_o->weak = FALSE;
        Fast_Parser_collected_o->id = 18;
        if (cx_define(Fast_Parser_collected_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::collected'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::Parser::complexType */
    if (!cx_checkState(Fast_Parser_complexType_o, CX_DEFINED)) {
        Fast_Parser_complexType_o->type = cx_resolve_ext(Fast_Parser_complexType_o, NULL, "::cortex::lang::array{type,64,type}", FALSE, "element ::cortex::Fast::Parser::complexType.type");
        Fast_Parser_complexType_o->modifiers = 0x3;
        Fast_Parser_complexType_o->state = 0x6;
        Fast_Parser_complexType_o->weak = FALSE;
        Fast_Parser_complexType_o->id = 37;
        if (cx_define(Fast_Parser_complexType_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::complexType'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::finalize(alias{"cx_icProgram"} program) */
    Fast_Parser_finalize_o = cx_declare(Fast_Parser_o, "finalize(alias{\"cx_icProgram\"} program)", cx_type(cx_method_o));
    if (!Fast_Parser_finalize_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::finalize(alias{\"cx_icProgram\"} program)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::finalize(alias{"cx_icProgram"} program) */
    if (!cx_checkState(Fast_Parser_finalize_o, CX_DEFINED)) {
        cx_function(Fast_Parser_finalize_o)->returnType = cx_resolve_ext(Fast_Parser_finalize_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::Parser::finalize(alias{\"cx_icProgram\"} program).returnType");
        cx_function(Fast_Parser_finalize_o)->returnsReference = FALSE;
        Fast_Parser_finalize_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Parser::finalize(alias{"cx_icProgram"} program) with C-function */
        cx_function(Fast_Parser_finalize_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Parser_finalize(void *args, void *result);
        cx_function(Fast_Parser_finalize_o)->impl = (cx_word)__Fast_Parser_finalize;
        if (cx_define(Fast_Parser_finalize_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::finalize(alias{\"cx_icProgram\"} program)'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::Parser::heapCollected */
    if (!cx_checkState(Fast_Parser_heapCollected_o, CX_DEFINED)) {
        Fast_Parser_heapCollected_o->type = cx_resolve_ext(Fast_Parser_heapCollected_o, NULL, "::cortex::lang::list{word,0}", FALSE, "element ::cortex::Fast::Parser::heapCollected.type");
        Fast_Parser_heapCollected_o->modifiers = 0x3;
        Fast_Parser_heapCollected_o->state = 0x6;
        Fast_Parser_heapCollected_o->weak = FALSE;
        Fast_Parser_heapCollected_o->id = 17;
        if (cx_define(Fast_Parser_heapCollected_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::heapCollected'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::parseLine(string expr,object scope,alias{"cx_value*"} value) */
    Fast_Parser_parseLine_o = cx_declare(Fast_Parser_o, "parseLine(string expr,object scope,alias{\"cx_value*\"} value)", cx_type(cx_function_o));
    if (!Fast_Parser_parseLine_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::parseLine(string expr,object scope,alias{\"cx_value*\"} value)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::parseLine(string expr,object scope,alias{"cx_value*"} value) */
    if (!cx_checkState(Fast_Parser_parseLine_o, CX_DEFINED)) {
        Fast_Parser_parseLine_o->returnType = cx_resolve_ext(Fast_Parser_parseLine_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::Parser::parseLine(string expr,object scope,alias{\"cx_value*\"} value).returnType");
        Fast_Parser_parseLine_o->returnsReference = FALSE;
        
        /* Bind ::cortex::Fast::Parser::parseLine(string expr,object scope,alias{"cx_value*"} value) with C-function */
        cx_function(Fast_Parser_parseLine_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Parser_parseLine(void *args, void *result);
        cx_function(Fast_Parser_parseLine_o)->impl = (cx_word)__Fast_Parser_parseLine;
        if (cx_define(Fast_Parser_parseLine_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::parseLine(string expr,object scope,alias{\"cx_value*\"} value)'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::StaticInitializerFrame::keyPtr */
    if (!cx_checkState(Fast_StaticInitializerFrame_keyPtr_o, CX_DEFINED)) {
        Fast_StaticInitializerFrame_keyPtr_o->type = cx_resolve_ext(Fast_StaticInitializerFrame_keyPtr_o, NULL, "::cortex::lang::array{word,64,word}", FALSE, "element ::cortex::Fast::StaticInitializerFrame::keyPtr.type");
        Fast_StaticInitializerFrame_keyPtr_o->modifiers = 0x0;
        Fast_StaticInitializerFrame_keyPtr_o->state = 0x6;
        Fast_StaticInitializerFrame_keyPtr_o->weak = FALSE;
        Fast_StaticInitializerFrame_keyPtr_o->id = 1;
        if (cx_define(Fast_StaticInitializerFrame_keyPtr_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::StaticInitializerFrame::keyPtr'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::StaticInitializerFrame::ptr */
    if (!cx_checkState(Fast_StaticInitializerFrame_ptr_o, CX_DEFINED)) {
        Fast_StaticInitializerFrame_ptr_o->type = cx_resolve_ext(Fast_StaticInitializerFrame_ptr_o, NULL, "::cortex::lang::array{word,64,word}", FALSE, "element ::cortex::Fast::StaticInitializerFrame::ptr.type");
        Fast_StaticInitializerFrame_ptr_o->modifiers = 0x0;
        Fast_StaticInitializerFrame_ptr_o->state = 0x6;
        Fast_StaticInitializerFrame_ptr_o->weak = FALSE;
        Fast_StaticInitializerFrame_ptr_o->id = 0;
        if (cx_define(Fast_StaticInitializerFrame_ptr_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::StaticInitializerFrame::ptr'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::StaticInitializerFrame */
    if (!cx_checkState(Fast_StaticInitializerFrame_o, CX_DEFINED)) {
        cx_type(Fast_StaticInitializerFrame_o)->defaultType = cx_resolve_ext(Fast_StaticInitializerFrame_o, NULL, "::cortex::lang::member", FALSE, "element ::cortex::Fast::StaticInitializerFrame.defaultType");
        cx_type(Fast_StaticInitializerFrame_o)->parentType = NULL;
        cx_type(Fast_StaticInitializerFrame_o)->parentState = 0x0;
        cx_interface(Fast_StaticInitializerFrame_o)->base = NULL;
        Fast_StaticInitializerFrame_o->baseAccess = 0x0;
        if (cx_define(Fast_StaticInitializerFrame_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::StaticInitializerFrame'.");
            goto error;
        }
    }

    if (cx_type(Fast_StaticInitializerFrame_o)->size != sizeof(Fast_StaticInitializerFrame)) {
        cx_error("Fast_load: calculated size '%d' of type '::cortex::Fast::StaticInitializerFrame' doesn't match C-type size '%d'", cx_type(Fast_StaticInitializerFrame_o)->size, sizeof(Fast_StaticInitializerFrame));
    }

    /* Define ::cortex::Fast::StaticInitializer::frames */
    if (!cx_checkState(Fast_StaticInitializer_frames_o, CX_DEFINED)) {
        Fast_StaticInitializer_frames_o->type = cx_resolve_ext(Fast_StaticInitializer_frames_o, NULL, "::cortex::lang::array{::cortex::Fast::StaticInitializerFrame,64,::cortex::Fast::StaticInitializerFrame}", FALSE, "element ::cortex::Fast::StaticInitializer::frames.type");
        Fast_StaticInitializer_frames_o->modifiers = 0x3;
        Fast_StaticInitializer_frames_o->state = 0x6;
        Fast_StaticInitializer_frames_o->weak = FALSE;
        Fast_StaticInitializer_frames_o->id = 0;
        if (cx_define(Fast_StaticInitializer_frames_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::StaticInitializer::frames'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Update::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
    Fast_Update_toIc_o = cx_declare(Fast_Update_o, "toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)", cx_type(cx_virtual_o));
    if (!Fast_Update_toIc_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Update::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Update::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
    if (!cx_checkState(Fast_Update_toIc_o, CX_DEFINED)) {
        cx_function(Fast_Update_toIc_o)->returnType = cx_resolve_ext(Fast_Update_toIc_o, NULL, "::cortex::lang::alias{\"cx_ic\"}", FALSE, "element ::cortex::Fast::Update::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored).returnType");
        cx_function(Fast_Update_toIc_o)->returnsReference = FALSE;
        cx_method(Fast_Update_toIc_o)->virtual = TRUE;
        
        /* Bind ::cortex::Fast::Update::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) with C-function */
        cx_function(Fast_Update_toIc_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Update_toIc_v(void *args, void *result);
        cx_function(Fast_Update_toIc_o)->impl = (cx_word)__Fast_Update_toIc_v;
        if (cx_define(Fast_Update_toIc_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Update::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::While::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
    Fast_While_toIc_o = cx_declare(Fast_While_o, "toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)", cx_type(cx_virtual_o));
    if (!Fast_While_toIc_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::While::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)'.");
        goto error;
    }

    /* Define ::cortex::Fast::While::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
    if (!cx_checkState(Fast_While_toIc_o, CX_DEFINED)) {
        cx_function(Fast_While_toIc_o)->returnType = cx_resolve_ext(Fast_While_toIc_o, NULL, "::cortex::lang::alias{\"cx_ic\"}", FALSE, "element ::cortex::Fast::While::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored).returnType");
        cx_function(Fast_While_toIc_o)->returnsReference = FALSE;
        cx_method(Fast_While_toIc_o)->virtual = TRUE;
        
        /* Bind ::cortex::Fast::While::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) with C-function */
        cx_function(Fast_While_toIc_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_While_toIc_v(void *args, void *result);
        cx_function(Fast_While_toIc_o)->impl = (cx_word)__Fast_While_toIc_v;
        if (cx_define(Fast_While_toIc_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::While::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::Block::parent */
    if (!cx_checkState(Fast_Block_parent_o, CX_DEFINED)) {
        Fast_Block_parent_o->type = cx_resolve_ext(Fast_Block_parent_o, NULL, "::cortex::Fast::Block", FALSE, "element ::cortex::Fast::Block::parent.type");
        Fast_Block_parent_o->modifiers = 0x0;
        Fast_Block_parent_o->state = 0x6;
        Fast_Block_parent_o->weak = FALSE;
        Fast_Block_parent_o->id = 0;
        if (cx_define(Fast_Block_parent_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Block::parent'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::Block::while */
    if (!cx_checkState(Fast_Block_while_o, CX_DEFINED)) {
        Fast_Block_while_o->type = cx_resolve_ext(Fast_Block_while_o, NULL, "::cortex::Fast::While", FALSE, "element ::cortex::Fast::Block::while.type");
        Fast_Block_while_o->modifiers = 0x4;
        Fast_Block_while_o->state = 0x6;
        Fast_Block_while_o->weak = FALSE;
        Fast_Block_while_o->id = 4;
        if (cx_define(Fast_Block_while_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Block::while'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::If::falseBranch */
    if (!cx_checkState(Fast_If_falseBranch_o, CX_DEFINED)) {
        Fast_If_falseBranch_o->type = cx_resolve_ext(Fast_If_falseBranch_o, NULL, "::cortex::Fast::If", FALSE, "element ::cortex::Fast::If::falseBranch.type");
        Fast_If_falseBranch_o->modifiers = 0x0;
        Fast_If_falseBranch_o->state = 0x6;
        Fast_If_falseBranch_o->weak = FALSE;
        Fast_If_falseBranch_o->id = 2;
        if (cx_define(Fast_If_falseBranch_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::If::falseBranch'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Expression::getType_expr(Expression target) */
    Fast_Expression_getType_expr_o = cx_declare(Fast_Expression_o, "getType_expr(Expression target)", cx_type(cx_method_o));
    if (!Fast_Expression_getType_expr_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Expression::getType_expr(Expression target)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Expression::getType_expr(Expression target) */
    if (!cx_checkState(Fast_Expression_getType_expr_o, CX_DEFINED)) {
        cx_function(Fast_Expression_getType_expr_o)->returnType = cx_resolve_ext(Fast_Expression_getType_expr_o, NULL, "::cortex::lang::type", FALSE, "element ::cortex::Fast::Expression::getType_expr(Expression target).returnType");
        cx_function(Fast_Expression_getType_expr_o)->returnsReference = FALSE;
        Fast_Expression_getType_expr_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Expression::getType_expr(Expression target) with C-function */
        cx_function(Fast_Expression_getType_expr_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Expression_getType_expr(void *args, void *result);
        cx_function(Fast_Expression_getType_expr_o)->impl = (cx_word)__Fast_Expression_getType_expr;
        if (cx_define(Fast_Expression_getType_expr_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Expression::getType_expr(Expression target)'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::Expression::type */
    if (!cx_checkState(Fast_Expression_type_o, CX_DEFINED)) {
        Fast_Expression_type_o->type = cx_resolve_ext(Fast_Expression_type_o, NULL, "::cortex::Fast::Variable", FALSE, "element ::cortex::Fast::Expression::type.type");
        Fast_Expression_type_o->modifiers = 0x4;
        Fast_Expression_type_o->state = 0x6;
        Fast_Expression_type_o->weak = FALSE;
        Fast_Expression_type_o->id = 0;
        if (cx_define(Fast_Expression_type_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Expression::type'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::Expression */
    if (!cx_checkState(Fast_Expression_o, CX_DEFINED)) {
        cx_type(Fast_Expression_o)->defaultType = cx_resolve_ext(Fast_Expression_o, NULL, "::cortex::lang::member", FALSE, "element ::cortex::Fast::Expression.defaultType");
        cx_type(Fast_Expression_o)->parentType = NULL;
        cx_type(Fast_Expression_o)->parentState = 0x0;
        cx_interface(Fast_Expression_o)->base = cx_resolve_ext(Fast_Expression_o, NULL, "::cortex::Fast::Node", FALSE, "element ::cortex::Fast::Expression.base");
        cx_struct(Fast_Expression_o)->baseAccess = 0x0;
        Fast_Expression_o->implements.length = 0;
        Fast_Expression_o->implements.buffer = NULL;
        if (cx_define(Fast_Expression_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Expression'.");
            goto error;
        }
    }

    if (cx_type(Fast_Expression_o)->size != sizeof(struct Fast_Expression_s)) {
        cx_error("Fast_load: calculated size '%d' of type '::cortex::Fast::Expression' doesn't match C-type size '%d'", cx_type(Fast_Expression_o)->size, sizeof(struct Fast_Expression_s));
    }

    /* Declare ::cortex::Fast::Binary::construct() */
    Fast_Binary_construct_o = cx_declare(Fast_Binary_o, "construct()", cx_type(cx_method_o));
    if (!Fast_Binary_construct_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Binary::construct()'.");
        goto error;
    }

    /* Define ::cortex::Fast::Binary::construct() */
    if (!cx_checkState(Fast_Binary_construct_o, CX_DEFINED)) {
        cx_function(Fast_Binary_construct_o)->returnType = cx_resolve_ext(Fast_Binary_construct_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::Binary::construct().returnType");
        cx_function(Fast_Binary_construct_o)->returnsReference = FALSE;
        Fast_Binary_construct_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Binary::construct() with C-function */
        cx_function(Fast_Binary_construct_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Binary_construct(void *args, void *result);
        cx_function(Fast_Binary_construct_o)->impl = (cx_word)__Fast_Binary_construct;
        if (cx_define(Fast_Binary_construct_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Binary::construct()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Binary::fold() */
    Fast_Binary_fold_o = cx_declare(Fast_Binary_o, "fold()", cx_type(cx_method_o));
    if (!Fast_Binary_fold_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Binary::fold()'.");
        goto error;
    }

    /* Define ::cortex::Fast::Binary::fold() */
    if (!cx_checkState(Fast_Binary_fold_o, CX_DEFINED)) {
        cx_function(Fast_Binary_fold_o)->returnType = cx_resolve_ext(Fast_Binary_fold_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::Binary::fold().returnType");
        cx_function(Fast_Binary_fold_o)->returnsReference = FALSE;
        Fast_Binary_fold_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Binary::fold() with C-function */
        cx_function(Fast_Binary_fold_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Binary_fold(void *args, void *result);
        cx_function(Fast_Binary_fold_o)->impl = (cx_word)__Fast_Binary_fold;
        if (cx_define(Fast_Binary_fold_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Binary::fold()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Binary::hasSideEffects() */
    Fast_Binary_hasSideEffects_o = cx_declare(Fast_Binary_o, "hasSideEffects()", cx_type(cx_virtual_o));
    if (!Fast_Binary_hasSideEffects_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Binary::hasSideEffects()'.");
        goto error;
    }

    /* Define ::cortex::Fast::Binary::hasSideEffects() */
    if (!cx_checkState(Fast_Binary_hasSideEffects_o, CX_DEFINED)) {
        cx_function(Fast_Binary_hasSideEffects_o)->returnType = cx_resolve_ext(Fast_Binary_hasSideEffects_o, NULL, "::cortex::lang::bool", FALSE, "element ::cortex::Fast::Binary::hasSideEffects().returnType");
        cx_function(Fast_Binary_hasSideEffects_o)->returnsReference = FALSE;
        cx_method(Fast_Binary_hasSideEffects_o)->virtual = TRUE;
        
        /* Bind ::cortex::Fast::Binary::hasSideEffects() with C-function */
        cx_function(Fast_Binary_hasSideEffects_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Binary_hasSideEffects_v(void *args, void *result);
        cx_function(Fast_Binary_hasSideEffects_o)->impl = (cx_word)__Fast_Binary_hasSideEffects_v;
        if (cx_define(Fast_Binary_hasSideEffects_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Binary::hasSideEffects()'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::Binary::lvalue */
    if (!cx_checkState(Fast_Binary_lvalue_o, CX_DEFINED)) {
        Fast_Binary_lvalue_o->type = cx_resolve_ext(Fast_Binary_lvalue_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::Binary::lvalue.type");
        Fast_Binary_lvalue_o->modifiers = 0x0;
        Fast_Binary_lvalue_o->state = 0x6;
        Fast_Binary_lvalue_o->weak = FALSE;
        Fast_Binary_lvalue_o->id = 0;
        if (cx_define(Fast_Binary_lvalue_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Binary::lvalue'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::Binary::rvalue */
    if (!cx_checkState(Fast_Binary_rvalue_o, CX_DEFINED)) {
        Fast_Binary_rvalue_o->type = cx_resolve_ext(Fast_Binary_rvalue_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::Binary::rvalue.type");
        Fast_Binary_rvalue_o->modifiers = 0x0;
        Fast_Binary_rvalue_o->state = 0x6;
        Fast_Binary_rvalue_o->weak = FALSE;
        Fast_Binary_rvalue_o->id = 1;
        if (cx_define(Fast_Binary_rvalue_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Binary::rvalue'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Binary::setOperator(operatorKind kind) */
    Fast_Binary_setOperator_o = cx_declare(Fast_Binary_o, "setOperator(operatorKind kind)", cx_type(cx_method_o));
    if (!Fast_Binary_setOperator_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Binary::setOperator(operatorKind kind)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Binary::setOperator(operatorKind kind) */
    if (!cx_checkState(Fast_Binary_setOperator_o, CX_DEFINED)) {
        cx_function(Fast_Binary_setOperator_o)->returnType = cx_resolve_ext(Fast_Binary_setOperator_o, NULL, "::cortex::lang::void", FALSE, "element ::cortex::Fast::Binary::setOperator(operatorKind kind).returnType");
        cx_function(Fast_Binary_setOperator_o)->returnsReference = FALSE;
        Fast_Binary_setOperator_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Binary::setOperator(operatorKind kind) with C-function */
        cx_function(Fast_Binary_setOperator_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Binary_setOperator(void *args, void *result);
        cx_function(Fast_Binary_setOperator_o)->impl = (cx_word)__Fast_Binary_setOperator;
        if (cx_define(Fast_Binary_setOperator_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Binary::setOperator(operatorKind kind)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Binary::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
    Fast_Binary_toIc_o = cx_declare(Fast_Binary_o, "toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)", cx_type(cx_virtual_o));
    if (!Fast_Binary_toIc_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Binary::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Binary::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
    if (!cx_checkState(Fast_Binary_toIc_o, CX_DEFINED)) {
        cx_function(Fast_Binary_toIc_o)->returnType = cx_resolve_ext(Fast_Binary_toIc_o, NULL, "::cortex::lang::alias{\"cx_ic\"}", FALSE, "element ::cortex::Fast::Binary::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored).returnType");
        cx_function(Fast_Binary_toIc_o)->returnsReference = FALSE;
        cx_method(Fast_Binary_toIc_o)->virtual = TRUE;
        
        /* Bind ::cortex::Fast::Binary::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) with C-function */
        cx_function(Fast_Binary_toIc_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Binary_toIc_v(void *args, void *result);
        cx_function(Fast_Binary_toIc_o)->impl = (cx_word)__Fast_Binary_toIc_v;
        if (cx_define(Fast_Binary_toIc_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Binary::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::Binary */
    if (!cx_checkState(Fast_Binary_o, CX_DEFINED)) {
        cx_type(Fast_Binary_o)->defaultType = cx_resolve_ext(Fast_Binary_o, NULL, "::cortex::lang::member", FALSE, "element ::cortex::Fast::Binary.defaultType");
        cx_type(Fast_Binary_o)->parentType = NULL;
        cx_type(Fast_Binary_o)->parentState = 0x0;
        cx_interface(Fast_Binary_o)->base = cx_resolve_ext(Fast_Binary_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::Binary.base");
        cx_struct(Fast_Binary_o)->baseAccess = 0x4;
        Fast_Binary_o->implements.length = 0;
        Fast_Binary_o->implements.buffer = NULL;
        if (cx_define(Fast_Binary_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Binary'.");
            goto error;
        }
    }

    if (cx_type(Fast_Binary_o)->size != sizeof(struct Fast_Binary_s)) {
        cx_error("Fast_load: calculated size '%d' of type '::cortex::Fast::Binary' doesn't match C-type size '%d'", cx_type(Fast_Binary_o)->size, sizeof(struct Fast_Binary_s));
    }

    /* Define ::cortex::Fast::Call::arguments */
    if (!cx_checkState(Fast_Call_arguments_o, CX_DEFINED)) {
        Fast_Call_arguments_o->type = cx_resolve_ext(Fast_Call_arguments_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::Call::arguments.type");
        Fast_Call_arguments_o->modifiers = 0x0;
        Fast_Call_arguments_o->state = 0x6;
        Fast_Call_arguments_o->weak = FALSE;
        Fast_Call_arguments_o->id = 1;
        if (cx_define(Fast_Call_arguments_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Call::arguments'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Call::construct() */
    Fast_Call_construct_o = cx_declare(Fast_Call_o, "construct()", cx_type(cx_method_o));
    if (!Fast_Call_construct_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Call::construct()'.");
        goto error;
    }

    /* Define ::cortex::Fast::Call::construct() */
    if (!cx_checkState(Fast_Call_construct_o, CX_DEFINED)) {
        cx_function(Fast_Call_construct_o)->returnType = cx_resolve_ext(Fast_Call_construct_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::Call::construct().returnType");
        cx_function(Fast_Call_construct_o)->returnsReference = FALSE;
        Fast_Call_construct_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Call::construct() with C-function */
        cx_function(Fast_Call_construct_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Call_construct(void *args, void *result);
        cx_function(Fast_Call_construct_o)->impl = (cx_word)__Fast_Call_construct;
        if (cx_define(Fast_Call_construct_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Call::construct()'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::Call::functionExpr */
    if (!cx_checkState(Fast_Call_functionExpr_o, CX_DEFINED)) {
        Fast_Call_functionExpr_o->type = cx_resolve_ext(Fast_Call_functionExpr_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::Call::functionExpr.type");
        Fast_Call_functionExpr_o->modifiers = 0x4;
        Fast_Call_functionExpr_o->state = 0x6;
        Fast_Call_functionExpr_o->weak = FALSE;
        Fast_Call_functionExpr_o->id = 2;
        if (cx_define(Fast_Call_functionExpr_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Call::functionExpr'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Call::hasSideEffects() */
    Fast_Call_hasSideEffects_o = cx_declare(Fast_Call_o, "hasSideEffects()", cx_type(cx_virtual_o));
    if (!Fast_Call_hasSideEffects_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Call::hasSideEffects()'.");
        goto error;
    }

    /* Define ::cortex::Fast::Call::hasSideEffects() */
    if (!cx_checkState(Fast_Call_hasSideEffects_o, CX_DEFINED)) {
        cx_function(Fast_Call_hasSideEffects_o)->returnType = cx_resolve_ext(Fast_Call_hasSideEffects_o, NULL, "::cortex::lang::bool", FALSE, "element ::cortex::Fast::Call::hasSideEffects().returnType");
        cx_function(Fast_Call_hasSideEffects_o)->returnsReference = FALSE;
        cx_method(Fast_Call_hasSideEffects_o)->virtual = TRUE;
        
        /* Bind ::cortex::Fast::Call::hasSideEffects() with C-function */
        cx_function(Fast_Call_hasSideEffects_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Call_hasSideEffects_v(void *args, void *result);
        cx_function(Fast_Call_hasSideEffects_o)->impl = (cx_word)__Fast_Call_hasSideEffects_v;
        if (cx_define(Fast_Call_hasSideEffects_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Call::hasSideEffects()'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::Call::instanceExpr */
    if (!cx_checkState(Fast_Call_instanceExpr_o, CX_DEFINED)) {
        Fast_Call_instanceExpr_o->type = cx_resolve_ext(Fast_Call_instanceExpr_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::Call::instanceExpr.type");
        Fast_Call_instanceExpr_o->modifiers = 0x0;
        Fast_Call_instanceExpr_o->state = 0x6;
        Fast_Call_instanceExpr_o->weak = FALSE;
        Fast_Call_instanceExpr_o->id = 0;
        if (cx_define(Fast_Call_instanceExpr_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Call::instanceExpr'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Call::setParameters(function function) */
    Fast_Call_setParameters_o = cx_declare(Fast_Call_o, "setParameters(function function)", cx_type(cx_method_o));
    if (!Fast_Call_setParameters_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Call::setParameters(function function)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Call::setParameters(function function) */
    if (!cx_checkState(Fast_Call_setParameters_o, CX_DEFINED)) {
        cx_function(Fast_Call_setParameters_o)->returnType = cx_resolve_ext(Fast_Call_setParameters_o, NULL, "::cortex::lang::void", FALSE, "element ::cortex::Fast::Call::setParameters(function function).returnType");
        cx_function(Fast_Call_setParameters_o)->returnsReference = FALSE;
        Fast_Call_setParameters_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Call::setParameters(function function) with C-function */
        cx_function(Fast_Call_setParameters_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Call_setParameters(void *args, void *result);
        cx_function(Fast_Call_setParameters_o)->impl = (cx_word)__Fast_Call_setParameters;
        if (cx_define(Fast_Call_setParameters_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Call::setParameters(function function)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Call::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
    Fast_Call_toIc_o = cx_declare(Fast_Call_o, "toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)", cx_type(cx_virtual_o));
    if (!Fast_Call_toIc_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Call::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Call::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
    if (!cx_checkState(Fast_Call_toIc_o, CX_DEFINED)) {
        cx_function(Fast_Call_toIc_o)->returnType = cx_resolve_ext(Fast_Call_toIc_o, NULL, "::cortex::lang::alias{\"cx_ic\"}", FALSE, "element ::cortex::Fast::Call::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored).returnType");
        cx_function(Fast_Call_toIc_o)->returnsReference = FALSE;
        cx_method(Fast_Call_toIc_o)->virtual = TRUE;
        
        /* Bind ::cortex::Fast::Call::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) with C-function */
        cx_function(Fast_Call_toIc_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Call_toIc_v(void *args, void *result);
        cx_function(Fast_Call_toIc_o)->impl = (cx_word)__Fast_Call_toIc_v;
        if (cx_define(Fast_Call_toIc_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Call::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::Call */
    if (!cx_checkState(Fast_Call_o, CX_DEFINED)) {
        cx_type(Fast_Call_o)->defaultType = cx_resolve_ext(Fast_Call_o, NULL, "::cortex::lang::member", FALSE, "element ::cortex::Fast::Call.defaultType");
        cx_type(Fast_Call_o)->parentType = NULL;
        cx_type(Fast_Call_o)->parentState = 0x0;
        cx_interface(Fast_Call_o)->base = cx_resolve_ext(Fast_Call_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::Call.base");
        cx_struct(Fast_Call_o)->baseAccess = 0x4;
        Fast_Call_o->implements.length = 0;
        Fast_Call_o->implements.buffer = NULL;
        if (cx_define(Fast_Call_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Call'.");
            goto error;
        }
    }

    if (cx_type(Fast_Call_o)->size != sizeof(struct Fast_Call_s)) {
        cx_error("Fast_load: calculated size '%d' of type '::cortex::Fast::Call' doesn't match C-type size '%d'", cx_type(Fast_Call_o)->size, sizeof(struct Fast_Call_s));
    }

    /* Declare ::cortex::Fast::DelegateCall::construct() */
    Fast_DelegateCall_construct_o = cx_declare(Fast_DelegateCall_o, "construct()", cx_type(cx_method_o));
    if (!Fast_DelegateCall_construct_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::DelegateCall::construct()'.");
        goto error;
    }

    /* Define ::cortex::Fast::DelegateCall::construct() */
    if (!cx_checkState(Fast_DelegateCall_construct_o, CX_DEFINED)) {
        cx_function(Fast_DelegateCall_construct_o)->returnType = cx_resolve_ext(Fast_DelegateCall_construct_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::DelegateCall::construct().returnType");
        cx_function(Fast_DelegateCall_construct_o)->returnsReference = FALSE;
        Fast_DelegateCall_construct_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::DelegateCall::construct() with C-function */
        cx_function(Fast_DelegateCall_construct_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_DelegateCall_construct(void *args, void *result);
        cx_function(Fast_DelegateCall_construct_o)->impl = (cx_word)__Fast_DelegateCall_construct;
        if (cx_define(Fast_DelegateCall_construct_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::DelegateCall::construct()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::StaticCall::construct() */
    Fast_StaticCall_construct_o = cx_declare(Fast_StaticCall_o, "construct()", cx_type(cx_method_o));
    if (!Fast_StaticCall_construct_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::StaticCall::construct()'.");
        goto error;
    }

    /* Define ::cortex::Fast::StaticCall::construct() */
    if (!cx_checkState(Fast_StaticCall_construct_o, CX_DEFINED)) {
        cx_function(Fast_StaticCall_construct_o)->returnType = cx_resolve_ext(Fast_StaticCall_construct_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::StaticCall::construct().returnType");
        cx_function(Fast_StaticCall_construct_o)->returnsReference = FALSE;
        Fast_StaticCall_construct_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::StaticCall::construct() with C-function */
        cx_function(Fast_StaticCall_construct_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_StaticCall_construct(void *args, void *result);
        cx_function(Fast_StaticCall_construct_o)->impl = (cx_word)__Fast_StaticCall_construct;
        if (cx_define(Fast_StaticCall_construct_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::StaticCall::construct()'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::StaticCall */
    if (!cx_checkState(Fast_StaticCall_o, CX_DEFINED)) {
        cx_type(Fast_StaticCall_o)->defaultType = cx_resolve_ext(Fast_StaticCall_o, NULL, "::cortex::lang::member", FALSE, "element ::cortex::Fast::StaticCall.defaultType");
        cx_type(Fast_StaticCall_o)->parentType = NULL;
        cx_type(Fast_StaticCall_o)->parentState = 0x0;
        cx_interface(Fast_StaticCall_o)->base = cx_resolve_ext(Fast_StaticCall_o, NULL, "::cortex::Fast::Call", FALSE, "element ::cortex::Fast::StaticCall.base");
        cx_struct(Fast_StaticCall_o)->baseAccess = 0x0;
        Fast_StaticCall_o->implements.length = 0;
        Fast_StaticCall_o->implements.buffer = NULL;
        if (cx_define(Fast_StaticCall_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::StaticCall'.");
            goto error;
        }
    }

    if (cx_type(Fast_StaticCall_o)->size != sizeof(struct Fast_StaticCall_s)) {
        cx_error("Fast_load: calculated size '%d' of type '::cortex::Fast::StaticCall' doesn't match C-type size '%d'", cx_type(Fast_StaticCall_o)->size, sizeof(struct Fast_StaticCall_s));
    }

    /* Define ::cortex::Fast::CallBuilder::arguments */
    if (!cx_checkState(Fast_CallBuilder_arguments_o, CX_DEFINED)) {
        Fast_CallBuilder_arguments_o->type = cx_resolve_ext(Fast_CallBuilder_arguments_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::CallBuilder::arguments.type");
        Fast_CallBuilder_arguments_o->modifiers = 0x0;
        Fast_CallBuilder_arguments_o->state = 0x6;
        Fast_CallBuilder_arguments_o->weak = FALSE;
        Fast_CallBuilder_arguments_o->id = 1;
        if (cx_define(Fast_CallBuilder_arguments_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::CallBuilder::arguments'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::CallBuilder::instance */
    if (!cx_checkState(Fast_CallBuilder_instance_o, CX_DEFINED)) {
        Fast_CallBuilder_instance_o->type = cx_resolve_ext(Fast_CallBuilder_instance_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::CallBuilder::instance.type");
        Fast_CallBuilder_instance_o->modifiers = 0x0;
        Fast_CallBuilder_instance_o->state = 0x6;
        Fast_CallBuilder_instance_o->weak = FALSE;
        Fast_CallBuilder_instance_o->id = 2;
        if (cx_define(Fast_CallBuilder_instance_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::CallBuilder::instance'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Cast::construct() */
    Fast_Cast_construct_o = cx_declare(Fast_Cast_o, "construct()", cx_type(cx_method_o));
    if (!Fast_Cast_construct_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Cast::construct()'.");
        goto error;
    }

    /* Define ::cortex::Fast::Cast::construct() */
    if (!cx_checkState(Fast_Cast_construct_o, CX_DEFINED)) {
        cx_function(Fast_Cast_construct_o)->returnType = cx_resolve_ext(Fast_Cast_construct_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::Cast::construct().returnType");
        cx_function(Fast_Cast_construct_o)->returnsReference = FALSE;
        Fast_Cast_construct_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Cast::construct() with C-function */
        cx_function(Fast_Cast_construct_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Cast_construct(void *args, void *result);
        cx_function(Fast_Cast_construct_o)->impl = (cx_word)__Fast_Cast_construct;
        if (cx_define(Fast_Cast_construct_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Cast::construct()'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::Cast::lvalue */
    if (!cx_checkState(Fast_Cast_lvalue_o, CX_DEFINED)) {
        Fast_Cast_lvalue_o->type = cx_resolve_ext(Fast_Cast_lvalue_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::Cast::lvalue.type");
        Fast_Cast_lvalue_o->modifiers = 0x0;
        Fast_Cast_lvalue_o->state = 0x6;
        Fast_Cast_lvalue_o->weak = FALSE;
        Fast_Cast_lvalue_o->id = 0;
        if (cx_define(Fast_Cast_lvalue_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Cast::lvalue'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::Cast::rvalue */
    if (!cx_checkState(Fast_Cast_rvalue_o, CX_DEFINED)) {
        Fast_Cast_rvalue_o->type = cx_resolve_ext(Fast_Cast_rvalue_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::Cast::rvalue.type");
        Fast_Cast_rvalue_o->modifiers = 0x0;
        Fast_Cast_rvalue_o->state = 0x6;
        Fast_Cast_rvalue_o->weak = FALSE;
        Fast_Cast_rvalue_o->id = 1;
        if (cx_define(Fast_Cast_rvalue_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Cast::rvalue'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Cast::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
    Fast_Cast_toIc_o = cx_declare(Fast_Cast_o, "toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)", cx_type(cx_virtual_o));
    if (!Fast_Cast_toIc_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Cast::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Cast::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
    if (!cx_checkState(Fast_Cast_toIc_o, CX_DEFINED)) {
        cx_function(Fast_Cast_toIc_o)->returnType = cx_resolve_ext(Fast_Cast_toIc_o, NULL, "::cortex::lang::alias{\"cx_ic\"}", FALSE, "element ::cortex::Fast::Cast::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored).returnType");
        cx_function(Fast_Cast_toIc_o)->returnsReference = FALSE;
        cx_method(Fast_Cast_toIc_o)->virtual = TRUE;
        
        /* Bind ::cortex::Fast::Cast::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) with C-function */
        cx_function(Fast_Cast_toIc_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Cast_toIc_v(void *args, void *result);
        cx_function(Fast_Cast_toIc_o)->impl = (cx_word)__Fast_Cast_toIc_v;
        if (cx_define(Fast_Cast_toIc_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Cast::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::Cast */
    if (!cx_checkState(Fast_Cast_o, CX_DEFINED)) {
        cx_type(Fast_Cast_o)->defaultType = cx_resolve_ext(Fast_Cast_o, NULL, "::cortex::lang::member", FALSE, "element ::cortex::Fast::Cast.defaultType");
        cx_type(Fast_Cast_o)->parentType = NULL;
        cx_type(Fast_Cast_o)->parentState = 0x0;
        cx_interface(Fast_Cast_o)->base = cx_resolve_ext(Fast_Cast_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::Cast.base");
        cx_struct(Fast_Cast_o)->baseAccess = 0x4;
        Fast_Cast_o->implements.length = 0;
        Fast_Cast_o->implements.buffer = NULL;
        if (cx_define(Fast_Cast_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Cast'.");
            goto error;
        }
    }

    if (cx_type(Fast_Cast_o)->size != sizeof(struct Fast_Cast_s)) {
        cx_error("Fast_load: calculated size '%d' of type '::cortex::Fast::Cast' doesn't match C-type size '%d'", cx_type(Fast_Cast_o)->size, sizeof(struct Fast_Cast_s));
    }

    /* Declare ::cortex::Fast::Comma::addExpression(Expression expr) */
    Fast_Comma_addExpression_o = cx_declare(Fast_Comma_o, "addExpression(Expression expr)", cx_type(cx_method_o));
    if (!Fast_Comma_addExpression_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Comma::addExpression(Expression expr)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Comma::addExpression(Expression expr) */
    if (!cx_checkState(Fast_Comma_addExpression_o, CX_DEFINED)) {
        cx_function(Fast_Comma_addExpression_o)->returnType = cx_resolve_ext(Fast_Comma_addExpression_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::Comma::addExpression(Expression expr).returnType");
        cx_function(Fast_Comma_addExpression_o)->returnsReference = FALSE;
        Fast_Comma_addExpression_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Comma::addExpression(Expression expr) with C-function */
        cx_function(Fast_Comma_addExpression_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Comma_addExpression(void *args, void *result);
        cx_function(Fast_Comma_addExpression_o)->impl = (cx_word)__Fast_Comma_addExpression;
        if (cx_define(Fast_Comma_addExpression_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Comma::addExpression(Expression expr)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Comma::addOrCreate(Expression list,Expression expr) */
    Fast_Comma_addOrCreate_o = cx_declare(Fast_Comma_o, "addOrCreate(Expression list,Expression expr)", cx_type(cx_function_o));
    if (!Fast_Comma_addOrCreate_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Comma::addOrCreate(Expression list,Expression expr)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Comma::addOrCreate(Expression list,Expression expr) */
    if (!cx_checkState(Fast_Comma_addOrCreate_o, CX_DEFINED)) {
        Fast_Comma_addOrCreate_o->returnType = cx_resolve_ext(Fast_Comma_addOrCreate_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::Comma::addOrCreate(Expression list,Expression expr).returnType");
        Fast_Comma_addOrCreate_o->returnsReference = FALSE;
        
        /* Bind ::cortex::Fast::Comma::addOrCreate(Expression list,Expression expr) with C-function */
        cx_function(Fast_Comma_addOrCreate_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Comma_addOrCreate(void *args, void *result);
        cx_function(Fast_Comma_addOrCreate_o)->impl = (cx_word)__Fast_Comma_addOrCreate;
        if (cx_define(Fast_Comma_addOrCreate_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Comma::addOrCreate(Expression list,Expression expr)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Comma::construct() */
    Fast_Comma_construct_o = cx_declare(Fast_Comma_o, "construct()", cx_type(cx_method_o));
    if (!Fast_Comma_construct_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Comma::construct()'.");
        goto error;
    }

    /* Define ::cortex::Fast::Comma::construct() */
    if (!cx_checkState(Fast_Comma_construct_o, CX_DEFINED)) {
        cx_function(Fast_Comma_construct_o)->returnType = cx_resolve_ext(Fast_Comma_construct_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::Comma::construct().returnType");
        cx_function(Fast_Comma_construct_o)->returnsReference = FALSE;
        Fast_Comma_construct_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Comma::construct() with C-function */
        cx_function(Fast_Comma_construct_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Comma_construct(void *args, void *result);
        cx_function(Fast_Comma_construct_o)->impl = (cx_word)__Fast_Comma_construct;
        if (cx_define(Fast_Comma_construct_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Comma::construct()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Comma::hasSideEffects() */
    Fast_Comma_hasSideEffects_o = cx_declare(Fast_Comma_o, "hasSideEffects()", cx_type(cx_virtual_o));
    if (!Fast_Comma_hasSideEffects_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Comma::hasSideEffects()'.");
        goto error;
    }

    /* Define ::cortex::Fast::Comma::hasSideEffects() */
    if (!cx_checkState(Fast_Comma_hasSideEffects_o, CX_DEFINED)) {
        cx_function(Fast_Comma_hasSideEffects_o)->returnType = cx_resolve_ext(Fast_Comma_hasSideEffects_o, NULL, "::cortex::lang::bool", FALSE, "element ::cortex::Fast::Comma::hasSideEffects().returnType");
        cx_function(Fast_Comma_hasSideEffects_o)->returnsReference = FALSE;
        cx_method(Fast_Comma_hasSideEffects_o)->virtual = TRUE;
        
        /* Bind ::cortex::Fast::Comma::hasSideEffects() with C-function */
        cx_function(Fast_Comma_hasSideEffects_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Comma_hasSideEffects_v(void *args, void *result);
        cx_function(Fast_Comma_hasSideEffects_o)->impl = (cx_word)__Fast_Comma_hasSideEffects_v;
        if (cx_define(Fast_Comma_hasSideEffects_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Comma::hasSideEffects()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Comma::init() */
    Fast_Comma_init_o = cx_declare(Fast_Comma_o, "init()", cx_type(cx_method_o));
    if (!Fast_Comma_init_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Comma::init()'.");
        goto error;
    }

    /* Define ::cortex::Fast::Comma::init() */
    if (!cx_checkState(Fast_Comma_init_o, CX_DEFINED)) {
        cx_function(Fast_Comma_init_o)->returnType = cx_resolve_ext(Fast_Comma_init_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::Comma::init().returnType");
        cx_function(Fast_Comma_init_o)->returnsReference = FALSE;
        Fast_Comma_init_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Comma::init() with C-function */
        cx_function(Fast_Comma_init_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Comma_init(void *args, void *result);
        cx_function(Fast_Comma_init_o)->impl = (cx_word)__Fast_Comma_init;
        if (cx_define(Fast_Comma_init_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Comma::init()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Comma::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
    Fast_Comma_toIc_o = cx_declare(Fast_Comma_o, "toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)", cx_type(cx_virtual_o));
    if (!Fast_Comma_toIc_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Comma::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Comma::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
    if (!cx_checkState(Fast_Comma_toIc_o, CX_DEFINED)) {
        cx_function(Fast_Comma_toIc_o)->returnType = cx_resolve_ext(Fast_Comma_toIc_o, NULL, "::cortex::lang::alias{\"cx_ic\"}", FALSE, "element ::cortex::Fast::Comma::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored).returnType");
        cx_function(Fast_Comma_toIc_o)->returnsReference = FALSE;
        cx_method(Fast_Comma_toIc_o)->virtual = TRUE;
        
        /* Bind ::cortex::Fast::Comma::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) with C-function */
        cx_function(Fast_Comma_toIc_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Comma_toIc_v(void *args, void *result);
        cx_function(Fast_Comma_toIc_o)->impl = (cx_word)__Fast_Comma_toIc_v;
        if (cx_define(Fast_Comma_toIc_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Comma::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Comma::toList() */
    Fast_Comma_toList_o = cx_declare(Fast_Comma_o, "toList()", cx_type(cx_method_o));
    if (!Fast_Comma_toList_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Comma::toList()'.");
        goto error;
    }

    /* Define ::cortex::Fast::Comma::toList() */
    if (!cx_checkState(Fast_Comma_toList_o, CX_DEFINED)) {
        cx_function(Fast_Comma_toList_o)->returnType = cx_resolve_ext(Fast_Comma_toList_o, NULL, "::cortex::lang::list{::cortex::Fast::Node,0}", FALSE, "element ::cortex::Fast::Comma::toList().returnType");
        cx_function(Fast_Comma_toList_o)->returnsReference = FALSE;
        Fast_Comma_toList_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Comma::toList() with C-function */
        cx_function(Fast_Comma_toList_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Comma_toList(void *args, void *result);
        cx_function(Fast_Comma_toList_o)->impl = (cx_word)__Fast_Comma_toList;
        if (cx_define(Fast_Comma_toList_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Comma::toList()'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::Comma */
    if (!cx_checkState(Fast_Comma_o, CX_DEFINED)) {
        cx_type(Fast_Comma_o)->defaultType = cx_resolve_ext(Fast_Comma_o, NULL, "::cortex::lang::member", FALSE, "element ::cortex::Fast::Comma.defaultType");
        cx_type(Fast_Comma_o)->parentType = NULL;
        cx_type(Fast_Comma_o)->parentState = 0x0;
        cx_interface(Fast_Comma_o)->base = cx_resolve_ext(Fast_Comma_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::Comma.base");
        cx_struct(Fast_Comma_o)->baseAccess = 0x4;
        Fast_Comma_o->implements.length = 0;
        Fast_Comma_o->implements.buffer = NULL;
        if (cx_define(Fast_Comma_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Comma'.");
            goto error;
        }
    }

    if (cx_type(Fast_Comma_o)->size != sizeof(struct Fast_Comma_s)) {
        cx_error("Fast_load: calculated size '%d' of type '::cortex::Fast::Comma' doesn't match C-type size '%d'", cx_type(Fast_Comma_o)->size, sizeof(struct Fast_Comma_s));
    }

    /* Define ::cortex::Fast::Define::object */
    if (!cx_checkState(Fast_Define_object_o, CX_DEFINED)) {
        Fast_Define_object_o->type = cx_resolve_ext(Fast_Define_object_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::Define::object.type");
        Fast_Define_object_o->modifiers = 0x0;
        Fast_Define_object_o->state = 0x6;
        Fast_Define_object_o->weak = FALSE;
        Fast_Define_object_o->id = 0;
        if (cx_define(Fast_Define_object_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Define::object'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::Define */
    if (!cx_checkState(Fast_Define_o, CX_DEFINED)) {
        cx_type(Fast_Define_o)->defaultType = cx_resolve_ext(Fast_Define_o, NULL, "::cortex::lang::member", FALSE, "element ::cortex::Fast::Define.defaultType");
        cx_type(Fast_Define_o)->parentType = NULL;
        cx_type(Fast_Define_o)->parentState = 0x0;
        cx_interface(Fast_Define_o)->base = cx_resolve_ext(Fast_Define_o, NULL, "::cortex::Fast::Node", FALSE, "element ::cortex::Fast::Define.base");
        cx_struct(Fast_Define_o)->baseAccess = 0x4;
        Fast_Define_o->implements.length = 0;
        Fast_Define_o->implements.buffer = NULL;
        if (cx_define(Fast_Define_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Define'.");
            goto error;
        }
    }

    if (cx_type(Fast_Define_o)->size != sizeof(struct Fast_Define_s)) {
        cx_error("Fast_load: calculated size '%d' of type '::cortex::Fast::Define' doesn't match C-type size '%d'", cx_type(Fast_Define_o)->size, sizeof(struct Fast_Define_s));
    }

    /* Define ::cortex::Fast::DelegateCall::expr */
    if (!cx_checkState(Fast_DelegateCall_expr_o, CX_DEFINED)) {
        Fast_DelegateCall_expr_o->type = cx_resolve_ext(Fast_DelegateCall_expr_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::DelegateCall::expr.type");
        Fast_DelegateCall_expr_o->modifiers = 0x0;
        Fast_DelegateCall_expr_o->state = 0x6;
        Fast_DelegateCall_expr_o->weak = FALSE;
        Fast_DelegateCall_expr_o->id = 0;
        if (cx_define(Fast_DelegateCall_expr_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::DelegateCall::expr'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::DelegateCall */
    if (!cx_checkState(Fast_DelegateCall_o, CX_DEFINED)) {
        cx_type(Fast_DelegateCall_o)->defaultType = cx_resolve_ext(Fast_DelegateCall_o, NULL, "::cortex::lang::member", FALSE, "element ::cortex::Fast::DelegateCall.defaultType");
        cx_type(Fast_DelegateCall_o)->parentType = NULL;
        cx_type(Fast_DelegateCall_o)->parentState = 0x0;
        cx_interface(Fast_DelegateCall_o)->base = cx_resolve_ext(Fast_DelegateCall_o, NULL, "::cortex::Fast::Call", FALSE, "element ::cortex::Fast::DelegateCall.base");
        cx_struct(Fast_DelegateCall_o)->baseAccess = 0x0;
        Fast_DelegateCall_o->implements.length = 0;
        Fast_DelegateCall_o->implements.buffer = NULL;
        if (cx_define(Fast_DelegateCall_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::DelegateCall'.");
            goto error;
        }
    }

    if (cx_type(Fast_DelegateCall_o)->size != sizeof(struct Fast_DelegateCall_s)) {
        cx_error("Fast_load: calculated size '%d' of type '::cortex::Fast::DelegateCall' doesn't match C-type size '%d'", cx_type(Fast_DelegateCall_o)->size, sizeof(struct Fast_DelegateCall_s));
    }

    /* Declare ::cortex::Fast::Element::construct() */
    Fast_Element_construct_o = cx_declare(Fast_Element_o, "construct()", cx_type(cx_method_o));
    if (!Fast_Element_construct_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Element::construct()'.");
        goto error;
    }

    /* Define ::cortex::Fast::Element::construct() */
    if (!cx_checkState(Fast_Element_construct_o, CX_DEFINED)) {
        cx_function(Fast_Element_construct_o)->returnType = cx_resolve_ext(Fast_Element_construct_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::Element::construct().returnType");
        cx_function(Fast_Element_construct_o)->returnsReference = FALSE;
        Fast_Element_construct_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Element::construct() with C-function */
        cx_function(Fast_Element_construct_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Element_construct(void *args, void *result);
        cx_function(Fast_Element_construct_o)->impl = (cx_word)__Fast_Element_construct;
        if (cx_define(Fast_Element_construct_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Element::construct()'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::Element::lvalue */
    if (!cx_checkState(Fast_Element_lvalue_o, CX_DEFINED)) {
        Fast_Element_lvalue_o->type = cx_resolve_ext(Fast_Element_lvalue_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::Element::lvalue.type");
        Fast_Element_lvalue_o->modifiers = 0x0;
        Fast_Element_lvalue_o->state = 0x6;
        Fast_Element_lvalue_o->weak = FALSE;
        Fast_Element_lvalue_o->id = 0;
        if (cx_define(Fast_Element_lvalue_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Element::lvalue'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::Element::rvalue */
    if (!cx_checkState(Fast_Element_rvalue_o, CX_DEFINED)) {
        Fast_Element_rvalue_o->type = cx_resolve_ext(Fast_Element_rvalue_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::Element::rvalue.type");
        Fast_Element_rvalue_o->modifiers = 0x0;
        Fast_Element_rvalue_o->state = 0x6;
        Fast_Element_rvalue_o->weak = FALSE;
        Fast_Element_rvalue_o->id = 1;
        if (cx_define(Fast_Element_rvalue_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Element::rvalue'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Element::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
    Fast_Element_toIc_o = cx_declare(Fast_Element_o, "toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)", cx_type(cx_virtual_o));
    if (!Fast_Element_toIc_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Element::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Element::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
    if (!cx_checkState(Fast_Element_toIc_o, CX_DEFINED)) {
        cx_function(Fast_Element_toIc_o)->returnType = cx_resolve_ext(Fast_Element_toIc_o, NULL, "::cortex::lang::alias{\"cx_ic\"}", FALSE, "element ::cortex::Fast::Element::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored).returnType");
        cx_function(Fast_Element_toIc_o)->returnsReference = FALSE;
        cx_method(Fast_Element_toIc_o)->virtual = TRUE;
        
        /* Bind ::cortex::Fast::Element::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) with C-function */
        cx_function(Fast_Element_toIc_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Element_toIc_v(void *args, void *result);
        cx_function(Fast_Element_toIc_o)->impl = (cx_word)__Fast_Element_toIc_v;
        if (cx_define(Fast_Element_toIc_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Element::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::Element */
    if (!cx_checkState(Fast_Element_o, CX_DEFINED)) {
        cx_type(Fast_Element_o)->defaultType = cx_resolve_ext(Fast_Element_o, NULL, "::cortex::lang::member", FALSE, "element ::cortex::Fast::Element.defaultType");
        cx_type(Fast_Element_o)->parentType = NULL;
        cx_type(Fast_Element_o)->parentState = 0x0;
        cx_interface(Fast_Element_o)->base = cx_resolve_ext(Fast_Element_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::Element.base");
        cx_struct(Fast_Element_o)->baseAccess = 0x4;
        Fast_Element_o->implements.length = 0;
        Fast_Element_o->implements.buffer = NULL;
        if (cx_define(Fast_Element_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Element'.");
            goto error;
        }
    }

    if (cx_type(Fast_Element_o)->size != sizeof(struct Fast_Element_s)) {
        cx_error("Fast_load: calculated size '%d' of type '::cortex::Fast::Element' doesn't match C-type size '%d'", cx_type(Fast_Element_o)->size, sizeof(struct Fast_Element_s));
    }

    /* Define ::cortex::Fast::If::condition */
    if (!cx_checkState(Fast_If_condition_o, CX_DEFINED)) {
        Fast_If_condition_o->type = cx_resolve_ext(Fast_If_condition_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::If::condition.type");
        Fast_If_condition_o->modifiers = 0x0;
        Fast_If_condition_o->state = 0x6;
        Fast_If_condition_o->weak = FALSE;
        Fast_If_condition_o->id = 0;
        if (cx_define(Fast_If_condition_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::If::condition'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Initializer::construct() */
    Fast_Initializer_construct_o = cx_declare(Fast_Initializer_o, "construct()", cx_type(cx_method_o));
    if (!Fast_Initializer_construct_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Initializer::construct()'.");
        goto error;
    }

    /* Define ::cortex::Fast::Initializer::construct() */
    if (!cx_checkState(Fast_Initializer_construct_o, CX_DEFINED)) {
        cx_function(Fast_Initializer_construct_o)->returnType = cx_resolve_ext(Fast_Initializer_construct_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::Initializer::construct().returnType");
        cx_function(Fast_Initializer_construct_o)->returnsReference = FALSE;
        Fast_Initializer_construct_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Initializer::construct() with C-function */
        cx_function(Fast_Initializer_construct_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Initializer_construct(void *args, void *result);
        cx_function(Fast_Initializer_construct_o)->impl = (cx_word)__Fast_Initializer_construct;
        if (cx_define(Fast_Initializer_construct_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Initializer::construct()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Initializer::currentType() */
    Fast_Initializer_currentType_o = cx_declare(Fast_Initializer_o, "currentType()", cx_type(cx_method_o));
    if (!Fast_Initializer_currentType_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Initializer::currentType()'.");
        goto error;
    }

    /* Define ::cortex::Fast::Initializer::currentType() */
    if (!cx_checkState(Fast_Initializer_currentType_o, CX_DEFINED)) {
        cx_function(Fast_Initializer_currentType_o)->returnType = cx_resolve_ext(Fast_Initializer_currentType_o, NULL, "::cortex::lang::type", FALSE, "element ::cortex::Fast::Initializer::currentType().returnType");
        cx_function(Fast_Initializer_currentType_o)->returnsReference = FALSE;
        Fast_Initializer_currentType_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Initializer::currentType() with C-function */
        cx_function(Fast_Initializer_currentType_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Initializer_currentType(void *args, void *result);
        cx_function(Fast_Initializer_currentType_o)->impl = (cx_word)__Fast_Initializer_currentType;
        if (cx_define(Fast_Initializer_currentType_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Initializer::currentType()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Initializer::define() */
    Fast_Initializer_define_o = cx_declare(Fast_Initializer_o, "define()", cx_type(cx_virtual_o));
    if (!Fast_Initializer_define_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Initializer::define()'.");
        goto error;
    }

    /* Define ::cortex::Fast::Initializer::define() */
    if (!cx_checkState(Fast_Initializer_define_o, CX_DEFINED)) {
        cx_function(Fast_Initializer_define_o)->returnType = cx_resolve_ext(Fast_Initializer_define_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::Initializer::define().returnType");
        cx_function(Fast_Initializer_define_o)->returnsReference = FALSE;
        cx_method(Fast_Initializer_define_o)->virtual = TRUE;
        
        /* Bind ::cortex::Fast::Initializer::define() with C-function */
        cx_function(Fast_Initializer_define_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Initializer_define_v(void *args, void *result);
        cx_function(Fast_Initializer_define_o)->impl = (cx_word)__Fast_Initializer_define_v;
        if (cx_define(Fast_Initializer_define_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Initializer::define()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Initializer::initFrame() */
    Fast_Initializer_initFrame_o = cx_declare(Fast_Initializer_o, "initFrame()", cx_type(cx_method_o));
    if (!Fast_Initializer_initFrame_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Initializer::initFrame()'.");
        goto error;
    }

    /* Define ::cortex::Fast::Initializer::initFrame() */
    if (!cx_checkState(Fast_Initializer_initFrame_o, CX_DEFINED)) {
        cx_function(Fast_Initializer_initFrame_o)->returnType = cx_resolve_ext(Fast_Initializer_initFrame_o, NULL, "::cortex::lang::uint16", FALSE, "element ::cortex::Fast::Initializer::initFrame().returnType");
        cx_function(Fast_Initializer_initFrame_o)->returnsReference = FALSE;
        Fast_Initializer_initFrame_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Initializer::initFrame() with C-function */
        cx_function(Fast_Initializer_initFrame_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Initializer_initFrame(void *args, void *result);
        cx_function(Fast_Initializer_initFrame_o)->impl = (cx_word)__Fast_Initializer_initFrame;
        if (cx_define(Fast_Initializer_initFrame_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Initializer::initFrame()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Initializer::member(string name) */
    Fast_Initializer_member_o = cx_declare(Fast_Initializer_o, "member(string name)", cx_type(cx_virtual_o));
    if (!Fast_Initializer_member_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Initializer::member(string name)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Initializer::member(string name) */
    if (!cx_checkState(Fast_Initializer_member_o, CX_DEFINED)) {
        cx_function(Fast_Initializer_member_o)->returnType = cx_resolve_ext(Fast_Initializer_member_o, NULL, "::cortex::lang::int32", FALSE, "element ::cortex::Fast::Initializer::member(string name).returnType");
        cx_function(Fast_Initializer_member_o)->returnsReference = FALSE;
        cx_method(Fast_Initializer_member_o)->virtual = TRUE;
        
        /* Bind ::cortex::Fast::Initializer::member(string name) with C-function */
        cx_function(Fast_Initializer_member_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Initializer_member_v(void *args, void *result);
        cx_function(Fast_Initializer_member_o)->impl = (cx_word)__Fast_Initializer_member_v;
        if (cx_define(Fast_Initializer_member_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Initializer::member(string name)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Initializer::next() */
    Fast_Initializer_next_o = cx_declare(Fast_Initializer_o, "next()", cx_type(cx_virtual_o));
    if (!Fast_Initializer_next_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Initializer::next()'.");
        goto error;
    }

    /* Define ::cortex::Fast::Initializer::next() */
    if (!cx_checkState(Fast_Initializer_next_o, CX_DEFINED)) {
        cx_function(Fast_Initializer_next_o)->returnType = cx_resolve_ext(Fast_Initializer_next_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::Initializer::next().returnType");
        cx_function(Fast_Initializer_next_o)->returnsReference = FALSE;
        cx_method(Fast_Initializer_next_o)->virtual = TRUE;
        
        /* Bind ::cortex::Fast::Initializer::next() with C-function */
        cx_function(Fast_Initializer_next_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Initializer_next_v(void *args, void *result);
        cx_function(Fast_Initializer_next_o)->impl = (cx_word)__Fast_Initializer_next_v;
        if (cx_define(Fast_Initializer_next_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Initializer::next()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Initializer::pop() */
    Fast_Initializer_pop_o = cx_declare(Fast_Initializer_o, "pop()", cx_type(cx_virtual_o));
    if (!Fast_Initializer_pop_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Initializer::pop()'.");
        goto error;
    }

    /* Define ::cortex::Fast::Initializer::pop() */
    if (!cx_checkState(Fast_Initializer_pop_o, CX_DEFINED)) {
        cx_function(Fast_Initializer_pop_o)->returnType = cx_resolve_ext(Fast_Initializer_pop_o, NULL, "::cortex::lang::int8", FALSE, "element ::cortex::Fast::Initializer::pop().returnType");
        cx_function(Fast_Initializer_pop_o)->returnsReference = FALSE;
        cx_method(Fast_Initializer_pop_o)->virtual = TRUE;
        
        /* Bind ::cortex::Fast::Initializer::pop() with C-function */
        cx_function(Fast_Initializer_pop_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Initializer_pop_v(void *args, void *result);
        cx_function(Fast_Initializer_pop_o)->impl = (cx_word)__Fast_Initializer_pop_v;
        if (cx_define(Fast_Initializer_pop_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Initializer::pop()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Initializer::popKey() */
    Fast_Initializer_popKey_o = cx_declare(Fast_Initializer_o, "popKey()", cx_type(cx_virtual_o));
    if (!Fast_Initializer_popKey_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Initializer::popKey()'.");
        goto error;
    }

    /* Define ::cortex::Fast::Initializer::popKey() */
    if (!cx_checkState(Fast_Initializer_popKey_o, CX_DEFINED)) {
        cx_function(Fast_Initializer_popKey_o)->returnType = cx_resolve_ext(Fast_Initializer_popKey_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::Initializer::popKey().returnType");
        cx_function(Fast_Initializer_popKey_o)->returnsReference = FALSE;
        cx_method(Fast_Initializer_popKey_o)->virtual = TRUE;
        
        /* Bind ::cortex::Fast::Initializer::popKey() with C-function */
        cx_function(Fast_Initializer_popKey_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Initializer_popKey_v(void *args, void *result);
        cx_function(Fast_Initializer_popKey_o)->impl = (cx_word)__Fast_Initializer_popKey_v;
        if (cx_define(Fast_Initializer_popKey_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Initializer::popKey()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Initializer::push() */
    Fast_Initializer_push_o = cx_declare(Fast_Initializer_o, "push()", cx_type(cx_virtual_o));
    if (!Fast_Initializer_push_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Initializer::push()'.");
        goto error;
    }

    /* Define ::cortex::Fast::Initializer::push() */
    if (!cx_checkState(Fast_Initializer_push_o, CX_DEFINED)) {
        cx_function(Fast_Initializer_push_o)->returnType = cx_resolve_ext(Fast_Initializer_push_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::Initializer::push().returnType");
        cx_function(Fast_Initializer_push_o)->returnsReference = FALSE;
        cx_method(Fast_Initializer_push_o)->virtual = TRUE;
        
        /* Bind ::cortex::Fast::Initializer::push() with C-function */
        cx_function(Fast_Initializer_push_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Initializer_push_v(void *args, void *result);
        cx_function(Fast_Initializer_push_o)->impl = (cx_word)__Fast_Initializer_push_v;
        if (cx_define(Fast_Initializer_push_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Initializer::push()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Initializer::pushKey() */
    Fast_Initializer_pushKey_o = cx_declare(Fast_Initializer_o, "pushKey()", cx_type(cx_virtual_o));
    if (!Fast_Initializer_pushKey_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Initializer::pushKey()'.");
        goto error;
    }

    /* Define ::cortex::Fast::Initializer::pushKey() */
    if (!cx_checkState(Fast_Initializer_pushKey_o, CX_DEFINED)) {
        cx_function(Fast_Initializer_pushKey_o)->returnType = cx_resolve_ext(Fast_Initializer_pushKey_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::Initializer::pushKey().returnType");
        cx_function(Fast_Initializer_pushKey_o)->returnsReference = FALSE;
        cx_method(Fast_Initializer_pushKey_o)->virtual = TRUE;
        
        /* Bind ::cortex::Fast::Initializer::pushKey() with C-function */
        cx_function(Fast_Initializer_pushKey_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Initializer_pushKey_v(void *args, void *result);
        cx_function(Fast_Initializer_pushKey_o)->impl = (cx_word)__Fast_Initializer_pushKey_v;
        if (cx_define(Fast_Initializer_pushKey_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Initializer::pushKey()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Initializer::type() */
    Fast_Initializer_type_o = cx_declare(Fast_Initializer_o, "type()", cx_type(cx_method_o));
    if (!Fast_Initializer_type_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Initializer::type()'.");
        goto error;
    }

    /* Define ::cortex::Fast::Initializer::type() */
    if (!cx_checkState(Fast_Initializer_type_o, CX_DEFINED)) {
        cx_function(Fast_Initializer_type_o)->returnType = cx_resolve_ext(Fast_Initializer_type_o, NULL, "::cortex::lang::type", FALSE, "element ::cortex::Fast::Initializer::type().returnType");
        cx_function(Fast_Initializer_type_o)->returnsReference = FALSE;
        Fast_Initializer_type_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Initializer::type() with C-function */
        cx_function(Fast_Initializer_type_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Initializer_type(void *args, void *result);
        cx_function(Fast_Initializer_type_o)->impl = (cx_word)__Fast_Initializer_type;
        if (cx_define(Fast_Initializer_type_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Initializer::type()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Initializer::value(Expression v) */
    Fast_Initializer_value_o = cx_declare(Fast_Initializer_o, "value(Expression v)", cx_type(cx_virtual_o));
    if (!Fast_Initializer_value_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Initializer::value(Expression v)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Initializer::value(Expression v) */
    if (!cx_checkState(Fast_Initializer_value_o, CX_DEFINED)) {
        cx_function(Fast_Initializer_value_o)->returnType = cx_resolve_ext(Fast_Initializer_value_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::Initializer::value(Expression v).returnType");
        cx_function(Fast_Initializer_value_o)->returnsReference = FALSE;
        cx_method(Fast_Initializer_value_o)->virtual = TRUE;
        
        /* Bind ::cortex::Fast::Initializer::value(Expression v) with C-function */
        cx_function(Fast_Initializer_value_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Initializer_value_v(void *args, void *result);
        cx_function(Fast_Initializer_value_o)->impl = (cx_word)__Fast_Initializer_value_v;
        if (cx_define(Fast_Initializer_value_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Initializer::value(Expression v)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Initializer::valueKey(Expression key) */
    Fast_Initializer_valueKey_o = cx_declare(Fast_Initializer_o, "valueKey(Expression key)", cx_type(cx_virtual_o));
    if (!Fast_Initializer_valueKey_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Initializer::valueKey(Expression key)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Initializer::valueKey(Expression key) */
    if (!cx_checkState(Fast_Initializer_valueKey_o, CX_DEFINED)) {
        cx_function(Fast_Initializer_valueKey_o)->returnType = cx_resolve_ext(Fast_Initializer_valueKey_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::Initializer::valueKey(Expression key).returnType");
        cx_function(Fast_Initializer_valueKey_o)->returnsReference = FALSE;
        cx_method(Fast_Initializer_valueKey_o)->virtual = TRUE;
        
        /* Bind ::cortex::Fast::Initializer::valueKey(Expression key) with C-function */
        cx_function(Fast_Initializer_valueKey_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Initializer_valueKey_v(void *args, void *result);
        cx_function(Fast_Initializer_valueKey_o)->impl = (cx_word)__Fast_Initializer_valueKey_v;
        if (cx_define(Fast_Initializer_valueKey_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Initializer::valueKey(Expression key)'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::InitializerVariable::object */
    if (!cx_checkState(Fast_InitializerVariable_object_o, CX_DEFINED)) {
        Fast_InitializerVariable_object_o->type = cx_resolve_ext(Fast_InitializerVariable_object_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::InitializerVariable::object.type");
        Fast_InitializerVariable_object_o->modifiers = 0x0;
        Fast_InitializerVariable_object_o->state = 0x6;
        Fast_InitializerVariable_object_o->weak = FALSE;
        Fast_InitializerVariable_object_o->id = 1;
        if (cx_define(Fast_InitializerVariable_object_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::InitializerVariable::object'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::InitializerVariable */
    if (!cx_checkState(Fast_InitializerVariable_o, CX_DEFINED)) {
        cx_type(Fast_InitializerVariable_o)->defaultType = cx_resolve_ext(Fast_InitializerVariable_o, NULL, "::cortex::lang::member", FALSE, "element ::cortex::Fast::InitializerVariable.defaultType");
        cx_type(Fast_InitializerVariable_o)->parentType = NULL;
        cx_type(Fast_InitializerVariable_o)->parentState = 0x0;
        cx_interface(Fast_InitializerVariable_o)->base = NULL;
        Fast_InitializerVariable_o->baseAccess = 0x0;
        if (cx_define(Fast_InitializerVariable_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::InitializerVariable'.");
            goto error;
        }
    }

    if (cx_type(Fast_InitializerVariable_o)->size != sizeof(Fast_InitializerVariable)) {
        cx_error("Fast_load: calculated size '%d' of type '::cortex::Fast::InitializerVariable' doesn't match C-type size '%d'", cx_type(Fast_InitializerVariable_o)->size, sizeof(Fast_InitializerVariable));
    }

    /* Define ::cortex::Fast::Initializer::variables */
    if (!cx_checkState(Fast_Initializer_variables_o, CX_DEFINED)) {
        Fast_Initializer_variables_o->type = cx_resolve_ext(Fast_Initializer_variables_o, NULL, "::cortex::lang::array{::cortex::Fast::InitializerVariable,64,::cortex::Fast::InitializerVariable}", FALSE, "element ::cortex::Fast::Initializer::variables.type");
        Fast_Initializer_variables_o->modifiers = 0x0;
        Fast_Initializer_variables_o->state = 0x6;
        Fast_Initializer_variables_o->weak = FALSE;
        Fast_Initializer_variables_o->id = 0;
        if (cx_define(Fast_Initializer_variables_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Initializer::variables'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::Initializer */
    if (!cx_checkState(Fast_Initializer_o, CX_DEFINED)) {
        cx_type(Fast_Initializer_o)->defaultType = cx_resolve_ext(Fast_Initializer_o, NULL, "::cortex::lang::member", FALSE, "element ::cortex::Fast::Initializer.defaultType");
        cx_type(Fast_Initializer_o)->parentType = NULL;
        cx_type(Fast_Initializer_o)->parentState = 0x0;
        cx_interface(Fast_Initializer_o)->base = cx_resolve_ext(Fast_Initializer_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::Initializer.base");
        cx_struct(Fast_Initializer_o)->baseAccess = 0x4;
        Fast_Initializer_o->implements.length = 0;
        Fast_Initializer_o->implements.buffer = NULL;
        if (cx_define(Fast_Initializer_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Initializer'.");
            goto error;
        }
    }

    if (cx_type(Fast_Initializer_o)->size != sizeof(struct Fast_Initializer_s)) {
        cx_error("Fast_load: calculated size '%d' of type '::cortex::Fast::Initializer' doesn't match C-type size '%d'", cx_type(Fast_Initializer_o)->size, sizeof(struct Fast_Initializer_s));
    }

    /* Declare ::cortex::Fast::DynamicInitializer::construct() */
    Fast_DynamicInitializer_construct_o = cx_declare(Fast_DynamicInitializer_o, "construct()", cx_type(cx_method_o));
    if (!Fast_DynamicInitializer_construct_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::DynamicInitializer::construct()'.");
        goto error;
    }

    /* Define ::cortex::Fast::DynamicInitializer::construct() */
    if (!cx_checkState(Fast_DynamicInitializer_construct_o, CX_DEFINED)) {
        cx_function(Fast_DynamicInitializer_construct_o)->returnType = cx_resolve_ext(Fast_DynamicInitializer_construct_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::DynamicInitializer::construct().returnType");
        cx_function(Fast_DynamicInitializer_construct_o)->returnsReference = FALSE;
        Fast_DynamicInitializer_construct_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::DynamicInitializer::construct() with C-function */
        cx_function(Fast_DynamicInitializer_construct_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_DynamicInitializer_construct(void *args, void *result);
        cx_function(Fast_DynamicInitializer_construct_o)->impl = (cx_word)__Fast_DynamicInitializer_construct;
        if (cx_define(Fast_DynamicInitializer_construct_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::DynamicInitializer::construct()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::DynamicInitializer::define() */
    Fast_DynamicInitializer_define_o = cx_declare(Fast_DynamicInitializer_o, "define()", cx_type(cx_method_o));
    if (!Fast_DynamicInitializer_define_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::DynamicInitializer::define()'.");
        goto error;
    }

    /* Define ::cortex::Fast::DynamicInitializer::define() */
    if (!cx_checkState(Fast_DynamicInitializer_define_o, CX_DEFINED)) {
        cx_function(Fast_DynamicInitializer_define_o)->returnType = cx_resolve_ext(Fast_DynamicInitializer_define_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::DynamicInitializer::define().returnType");
        cx_function(Fast_DynamicInitializer_define_o)->returnsReference = FALSE;
        Fast_DynamicInitializer_define_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::DynamicInitializer::define() with C-function */
        cx_function(Fast_DynamicInitializer_define_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_DynamicInitializer_define(void *args, void *result);
        cx_function(Fast_DynamicInitializer_define_o)->impl = (cx_word)__Fast_DynamicInitializer_define;
        if (cx_define(Fast_DynamicInitializer_define_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::DynamicInitializer::define()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::DynamicInitializer::pop() */
    Fast_DynamicInitializer_pop_o = cx_declare(Fast_DynamicInitializer_o, "pop()", cx_type(cx_method_o));
    if (!Fast_DynamicInitializer_pop_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::DynamicInitializer::pop()'.");
        goto error;
    }

    /* Define ::cortex::Fast::DynamicInitializer::pop() */
    if (!cx_checkState(Fast_DynamicInitializer_pop_o, CX_DEFINED)) {
        cx_function(Fast_DynamicInitializer_pop_o)->returnType = cx_resolve_ext(Fast_DynamicInitializer_pop_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::DynamicInitializer::pop().returnType");
        cx_function(Fast_DynamicInitializer_pop_o)->returnsReference = FALSE;
        Fast_DynamicInitializer_pop_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::DynamicInitializer::pop() with C-function */
        cx_function(Fast_DynamicInitializer_pop_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_DynamicInitializer_pop(void *args, void *result);
        cx_function(Fast_DynamicInitializer_pop_o)->impl = (cx_word)__Fast_DynamicInitializer_pop;
        if (cx_define(Fast_DynamicInitializer_pop_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::DynamicInitializer::pop()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::DynamicInitializer::push() */
    Fast_DynamicInitializer_push_o = cx_declare(Fast_DynamicInitializer_o, "push()", cx_type(cx_method_o));
    if (!Fast_DynamicInitializer_push_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::DynamicInitializer::push()'.");
        goto error;
    }

    /* Define ::cortex::Fast::DynamicInitializer::push() */
    if (!cx_checkState(Fast_DynamicInitializer_push_o, CX_DEFINED)) {
        cx_function(Fast_DynamicInitializer_push_o)->returnType = cx_resolve_ext(Fast_DynamicInitializer_push_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::DynamicInitializer::push().returnType");
        cx_function(Fast_DynamicInitializer_push_o)->returnsReference = FALSE;
        Fast_DynamicInitializer_push_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::DynamicInitializer::push() with C-function */
        cx_function(Fast_DynamicInitializer_push_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_DynamicInitializer_push(void *args, void *result);
        cx_function(Fast_DynamicInitializer_push_o)->impl = (cx_word)__Fast_DynamicInitializer_push;
        if (cx_define(Fast_DynamicInitializer_push_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::DynamicInitializer::push()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::DynamicInitializer::value(Expression v) */
    Fast_DynamicInitializer_value_o = cx_declare(Fast_DynamicInitializer_o, "value(Expression v)", cx_type(cx_method_o));
    if (!Fast_DynamicInitializer_value_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::DynamicInitializer::value(Expression v)'.");
        goto error;
    }

    /* Define ::cortex::Fast::DynamicInitializer::value(Expression v) */
    if (!cx_checkState(Fast_DynamicInitializer_value_o, CX_DEFINED)) {
        cx_function(Fast_DynamicInitializer_value_o)->returnType = cx_resolve_ext(Fast_DynamicInitializer_value_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::DynamicInitializer::value(Expression v).returnType");
        cx_function(Fast_DynamicInitializer_value_o)->returnsReference = FALSE;
        Fast_DynamicInitializer_value_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::DynamicInitializer::value(Expression v) with C-function */
        cx_function(Fast_DynamicInitializer_value_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_DynamicInitializer_value(void *args, void *result);
        cx_function(Fast_DynamicInitializer_value_o)->impl = (cx_word)__Fast_DynamicInitializer_value;
        if (cx_define(Fast_DynamicInitializer_value_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::DynamicInitializer::value(Expression v)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::InitializerExpression::construct() */
    Fast_InitializerExpression_construct_o = cx_declare(Fast_InitializerExpression_o, "construct()", cx_type(cx_method_o));
    if (!Fast_InitializerExpression_construct_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::InitializerExpression::construct()'.");
        goto error;
    }

    /* Define ::cortex::Fast::InitializerExpression::construct() */
    if (!cx_checkState(Fast_InitializerExpression_construct_o, CX_DEFINED)) {
        cx_function(Fast_InitializerExpression_construct_o)->returnType = cx_resolve_ext(Fast_InitializerExpression_construct_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::InitializerExpression::construct().returnType");
        cx_function(Fast_InitializerExpression_construct_o)->returnsReference = FALSE;
        Fast_InitializerExpression_construct_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::InitializerExpression::construct() with C-function */
        cx_function(Fast_InitializerExpression_construct_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_InitializerExpression_construct(void *args, void *result);
        cx_function(Fast_InitializerExpression_construct_o)->impl = (cx_word)__Fast_InitializerExpression_construct;
        if (cx_define(Fast_InitializerExpression_construct_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::InitializerExpression::construct()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::InitializerExpression::define() */
    Fast_InitializerExpression_define_o = cx_declare(Fast_InitializerExpression_o, "define()", cx_type(cx_method_o));
    if (!Fast_InitializerExpression_define_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::InitializerExpression::define()'.");
        goto error;
    }

    /* Define ::cortex::Fast::InitializerExpression::define() */
    if (!cx_checkState(Fast_InitializerExpression_define_o, CX_DEFINED)) {
        cx_function(Fast_InitializerExpression_define_o)->returnType = cx_resolve_ext(Fast_InitializerExpression_define_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::InitializerExpression::define().returnType");
        cx_function(Fast_InitializerExpression_define_o)->returnsReference = FALSE;
        Fast_InitializerExpression_define_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::InitializerExpression::define() with C-function */
        cx_function(Fast_InitializerExpression_define_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_InitializerExpression_define(void *args, void *result);
        cx_function(Fast_InitializerExpression_define_o)->impl = (cx_word)__Fast_InitializerExpression_define;
        if (cx_define(Fast_InitializerExpression_define_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::InitializerExpression::define()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::InitializerExpression::insert(Expression variable) */
    Fast_InitializerExpression_insert_o = cx_declare(Fast_InitializerExpression_o, "insert(Expression variable)", cx_type(cx_method_o));
    if (!Fast_InitializerExpression_insert_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::InitializerExpression::insert(Expression variable)'.");
        goto error;
    }

    /* Define ::cortex::Fast::InitializerExpression::insert(Expression variable) */
    if (!cx_checkState(Fast_InitializerExpression_insert_o, CX_DEFINED)) {
        cx_function(Fast_InitializerExpression_insert_o)->returnType = cx_resolve_ext(Fast_InitializerExpression_insert_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::InitializerExpression::insert(Expression variable).returnType");
        cx_function(Fast_InitializerExpression_insert_o)->returnsReference = FALSE;
        Fast_InitializerExpression_insert_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::InitializerExpression::insert(Expression variable) with C-function */
        cx_function(Fast_InitializerExpression_insert_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_InitializerExpression_insert(void *args, void *result);
        cx_function(Fast_InitializerExpression_insert_o)->impl = (cx_word)__Fast_InitializerExpression_insert;
        if (cx_define(Fast_InitializerExpression_insert_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::InitializerExpression::insert(Expression variable)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::InitializerExpression::member(string name) */
    Fast_InitializerExpression_member_o = cx_declare(Fast_InitializerExpression_o, "member(string name)", cx_type(cx_method_o));
    if (!Fast_InitializerExpression_member_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::InitializerExpression::member(string name)'.");
        goto error;
    }

    /* Define ::cortex::Fast::InitializerExpression::member(string name) */
    if (!cx_checkState(Fast_InitializerExpression_member_o, CX_DEFINED)) {
        cx_function(Fast_InitializerExpression_member_o)->returnType = cx_resolve_ext(Fast_InitializerExpression_member_o, NULL, "::cortex::lang::int32", FALSE, "element ::cortex::Fast::InitializerExpression::member(string name).returnType");
        cx_function(Fast_InitializerExpression_member_o)->returnsReference = FALSE;
        Fast_InitializerExpression_member_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::InitializerExpression::member(string name) with C-function */
        cx_function(Fast_InitializerExpression_member_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_InitializerExpression_member(void *args, void *result);
        cx_function(Fast_InitializerExpression_member_o)->impl = (cx_word)__Fast_InitializerExpression_member;
        if (cx_define(Fast_InitializerExpression_member_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::InitializerExpression::member(string name)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::InitializerExpression::pop() */
    Fast_InitializerExpression_pop_o = cx_declare(Fast_InitializerExpression_o, "pop()", cx_type(cx_method_o));
    if (!Fast_InitializerExpression_pop_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::InitializerExpression::pop()'.");
        goto error;
    }

    /* Define ::cortex::Fast::InitializerExpression::pop() */
    if (!cx_checkState(Fast_InitializerExpression_pop_o, CX_DEFINED)) {
        cx_function(Fast_InitializerExpression_pop_o)->returnType = cx_resolve_ext(Fast_InitializerExpression_pop_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::InitializerExpression::pop().returnType");
        cx_function(Fast_InitializerExpression_pop_o)->returnsReference = FALSE;
        Fast_InitializerExpression_pop_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::InitializerExpression::pop() with C-function */
        cx_function(Fast_InitializerExpression_pop_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_InitializerExpression_pop(void *args, void *result);
        cx_function(Fast_InitializerExpression_pop_o)->impl = (cx_word)__Fast_InitializerExpression_pop;
        if (cx_define(Fast_InitializerExpression_pop_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::InitializerExpression::pop()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::InitializerExpression::push() */
    Fast_InitializerExpression_push_o = cx_declare(Fast_InitializerExpression_o, "push()", cx_type(cx_method_o));
    if (!Fast_InitializerExpression_push_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::InitializerExpression::push()'.");
        goto error;
    }

    /* Define ::cortex::Fast::InitializerExpression::push() */
    if (!cx_checkState(Fast_InitializerExpression_push_o, CX_DEFINED)) {
        cx_function(Fast_InitializerExpression_push_o)->returnType = cx_resolve_ext(Fast_InitializerExpression_push_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::InitializerExpression::push().returnType");
        cx_function(Fast_InitializerExpression_push_o)->returnsReference = FALSE;
        Fast_InitializerExpression_push_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::InitializerExpression::push() with C-function */
        cx_function(Fast_InitializerExpression_push_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_InitializerExpression_push(void *args, void *result);
        cx_function(Fast_InitializerExpression_push_o)->impl = (cx_word)__Fast_InitializerExpression_push;
        if (cx_define(Fast_InitializerExpression_push_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::InitializerExpression::push()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::InitializerExpression::value(Expression v) */
    Fast_InitializerExpression_value_o = cx_declare(Fast_InitializerExpression_o, "value(Expression v)", cx_type(cx_method_o));
    if (!Fast_InitializerExpression_value_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::InitializerExpression::value(Expression v)'.");
        goto error;
    }

    /* Define ::cortex::Fast::InitializerExpression::value(Expression v) */
    if (!cx_checkState(Fast_InitializerExpression_value_o, CX_DEFINED)) {
        cx_function(Fast_InitializerExpression_value_o)->returnType = cx_resolve_ext(Fast_InitializerExpression_value_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::InitializerExpression::value(Expression v).returnType");
        cx_function(Fast_InitializerExpression_value_o)->returnsReference = FALSE;
        Fast_InitializerExpression_value_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::InitializerExpression::value(Expression v) with C-function */
        cx_function(Fast_InitializerExpression_value_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_InitializerExpression_value(void *args, void *result);
        cx_function(Fast_InitializerExpression_value_o)->impl = (cx_word)__Fast_InitializerExpression_value;
        if (cx_define(Fast_InitializerExpression_value_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::InitializerExpression::value(Expression v)'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::InitializerExpression */
    if (!cx_checkState(Fast_InitializerExpression_o, CX_DEFINED)) {
        cx_type(Fast_InitializerExpression_o)->defaultType = cx_resolve_ext(Fast_InitializerExpression_o, NULL, "::cortex::lang::member", FALSE, "element ::cortex::Fast::InitializerExpression.defaultType");
        cx_type(Fast_InitializerExpression_o)->parentType = NULL;
        cx_type(Fast_InitializerExpression_o)->parentState = 0x0;
        cx_interface(Fast_InitializerExpression_o)->base = cx_resolve_ext(Fast_InitializerExpression_o, NULL, "::cortex::Fast::Initializer", FALSE, "element ::cortex::Fast::InitializerExpression.base");
        cx_struct(Fast_InitializerExpression_o)->baseAccess = 0x0;
        Fast_InitializerExpression_o->implements.length = 0;
        Fast_InitializerExpression_o->implements.buffer = NULL;
        if (cx_define(Fast_InitializerExpression_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::InitializerExpression'.");
            goto error;
        }
    }

    if (cx_type(Fast_InitializerExpression_o)->size != sizeof(struct Fast_InitializerExpression_s)) {
        cx_error("Fast_load: calculated size '%d' of type '::cortex::Fast::InitializerExpression' doesn't match C-type size '%d'", cx_type(Fast_InitializerExpression_o)->size, sizeof(struct Fast_InitializerExpression_s));
    }

    /* Declare ::cortex::Fast::StaticInitializer::construct() */
    Fast_StaticInitializer_construct_o = cx_declare(Fast_StaticInitializer_o, "construct()", cx_type(cx_method_o));
    if (!Fast_StaticInitializer_construct_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::StaticInitializer::construct()'.");
        goto error;
    }

    /* Define ::cortex::Fast::StaticInitializer::construct() */
    if (!cx_checkState(Fast_StaticInitializer_construct_o, CX_DEFINED)) {
        cx_function(Fast_StaticInitializer_construct_o)->returnType = cx_resolve_ext(Fast_StaticInitializer_construct_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::StaticInitializer::construct().returnType");
        cx_function(Fast_StaticInitializer_construct_o)->returnsReference = FALSE;
        Fast_StaticInitializer_construct_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::StaticInitializer::construct() with C-function */
        cx_function(Fast_StaticInitializer_construct_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_StaticInitializer_construct(void *args, void *result);
        cx_function(Fast_StaticInitializer_construct_o)->impl = (cx_word)__Fast_StaticInitializer_construct;
        if (cx_define(Fast_StaticInitializer_construct_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::StaticInitializer::construct()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::StaticInitializer::define() */
    Fast_StaticInitializer_define_o = cx_declare(Fast_StaticInitializer_o, "define()", cx_type(cx_method_o));
    if (!Fast_StaticInitializer_define_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::StaticInitializer::define()'.");
        goto error;
    }

    /* Define ::cortex::Fast::StaticInitializer::define() */
    if (!cx_checkState(Fast_StaticInitializer_define_o, CX_DEFINED)) {
        cx_function(Fast_StaticInitializer_define_o)->returnType = cx_resolve_ext(Fast_StaticInitializer_define_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::StaticInitializer::define().returnType");
        cx_function(Fast_StaticInitializer_define_o)->returnsReference = FALSE;
        Fast_StaticInitializer_define_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::StaticInitializer::define() with C-function */
        cx_function(Fast_StaticInitializer_define_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_StaticInitializer_define(void *args, void *result);
        cx_function(Fast_StaticInitializer_define_o)->impl = (cx_word)__Fast_StaticInitializer_define;
        if (cx_define(Fast_StaticInitializer_define_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::StaticInitializer::define()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::StaticInitializer::push() */
    Fast_StaticInitializer_push_o = cx_declare(Fast_StaticInitializer_o, "push()", cx_type(cx_method_o));
    if (!Fast_StaticInitializer_push_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::StaticInitializer::push()'.");
        goto error;
    }

    /* Define ::cortex::Fast::StaticInitializer::push() */
    if (!cx_checkState(Fast_StaticInitializer_push_o, CX_DEFINED)) {
        cx_function(Fast_StaticInitializer_push_o)->returnType = cx_resolve_ext(Fast_StaticInitializer_push_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::StaticInitializer::push().returnType");
        cx_function(Fast_StaticInitializer_push_o)->returnsReference = FALSE;
        Fast_StaticInitializer_push_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::StaticInitializer::push() with C-function */
        cx_function(Fast_StaticInitializer_push_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_StaticInitializer_push(void *args, void *result);
        cx_function(Fast_StaticInitializer_push_o)->impl = (cx_word)__Fast_StaticInitializer_push;
        if (cx_define(Fast_StaticInitializer_push_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::StaticInitializer::push()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::StaticInitializer::value(Expression v) */
    Fast_StaticInitializer_value_o = cx_declare(Fast_StaticInitializer_o, "value(Expression v)", cx_type(cx_method_o));
    if (!Fast_StaticInitializer_value_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::StaticInitializer::value(Expression v)'.");
        goto error;
    }

    /* Define ::cortex::Fast::StaticInitializer::value(Expression v) */
    if (!cx_checkState(Fast_StaticInitializer_value_o, CX_DEFINED)) {
        cx_function(Fast_StaticInitializer_value_o)->returnType = cx_resolve_ext(Fast_StaticInitializer_value_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::StaticInitializer::value(Expression v).returnType");
        cx_function(Fast_StaticInitializer_value_o)->returnsReference = FALSE;
        Fast_StaticInitializer_value_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::StaticInitializer::value(Expression v) with C-function */
        cx_function(Fast_StaticInitializer_value_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_StaticInitializer_value(void *args, void *result);
        cx_function(Fast_StaticInitializer_value_o)->impl = (cx_word)__Fast_StaticInitializer_value;
        if (cx_define(Fast_StaticInitializer_value_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::StaticInitializer::value(Expression v)'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::StaticInitializer */
    if (!cx_checkState(Fast_StaticInitializer_o, CX_DEFINED)) {
        cx_type(Fast_StaticInitializer_o)->defaultType = cx_resolve_ext(Fast_StaticInitializer_o, NULL, "::cortex::lang::member", FALSE, "element ::cortex::Fast::StaticInitializer.defaultType");
        cx_type(Fast_StaticInitializer_o)->parentType = NULL;
        cx_type(Fast_StaticInitializer_o)->parentState = 0x0;
        cx_interface(Fast_StaticInitializer_o)->base = cx_resolve_ext(Fast_StaticInitializer_o, NULL, "::cortex::Fast::Initializer", FALSE, "element ::cortex::Fast::StaticInitializer.base");
        cx_struct(Fast_StaticInitializer_o)->baseAccess = 0x0;
        Fast_StaticInitializer_o->implements.length = 0;
        Fast_StaticInitializer_o->implements.buffer = NULL;
        if (cx_define(Fast_StaticInitializer_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::StaticInitializer'.");
            goto error;
        }
    }

    if (cx_type(Fast_StaticInitializer_o)->size != sizeof(struct Fast_StaticInitializer_s)) {
        cx_error("Fast_load: calculated size '%d' of type '::cortex::Fast::StaticInitializer' doesn't match C-type size '%d'", cx_type(Fast_StaticInitializer_o)->size, sizeof(struct Fast_StaticInitializer_s));
    }

    /* Define ::cortex::Fast::Parser::initializers */
    if (!cx_checkState(Fast_Parser_initializers_o, CX_DEFINED)) {
        Fast_Parser_initializers_o->type = cx_resolve_ext(Fast_Parser_initializers_o, NULL, "::cortex::lang::array{::cortex::Fast::Initializer,64,::cortex::Fast::Initializer}", FALSE, "element ::cortex::Fast::Parser::initializers.type");
        Fast_Parser_initializers_o->modifiers = 0x3;
        Fast_Parser_initializers_o->state = 0x6;
        Fast_Parser_initializers_o->weak = FALSE;
        Fast_Parser_initializers_o->id = 28;
        if (cx_define(Fast_Parser_initializers_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::initializers'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::InitOper::expr */
    if (!cx_checkState(Fast_InitOper_expr_o, CX_DEFINED)) {
        Fast_InitOper_expr_o->type = cx_resolve_ext(Fast_InitOper_expr_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::InitOper::expr.type");
        Fast_InitOper_expr_o->modifiers = 0x0;
        Fast_InitOper_expr_o->state = 0x6;
        Fast_InitOper_expr_o->weak = FALSE;
        Fast_InitOper_expr_o->id = 1;
        if (cx_define(Fast_InitOper_expr_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::InitOper::expr'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::InitOper */
    if (!cx_checkState(Fast_InitOper_o, CX_DEFINED)) {
        cx_type(Fast_InitOper_o)->defaultType = cx_resolve_ext(Fast_InitOper_o, NULL, "::cortex::lang::member", FALSE, "element ::cortex::Fast::InitOper.defaultType");
        cx_type(Fast_InitOper_o)->parentType = NULL;
        cx_type(Fast_InitOper_o)->parentState = 0x0;
        cx_interface(Fast_InitOper_o)->base = NULL;
        Fast_InitOper_o->baseAccess = 0x0;
        if (cx_define(Fast_InitOper_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::InitOper'.");
            goto error;
        }
    }

    if (cx_type(Fast_InitOper_o)->size != sizeof(Fast_InitOper)) {
        cx_error("Fast_load: calculated size '%d' of type '::cortex::Fast::InitOper' doesn't match C-type size '%d'", cx_type(Fast_InitOper_o)->size, sizeof(Fast_InitOper));
    }

    /* Declare ::cortex::Fast::Literal::getValue() */
    Fast_Literal_getValue_o = cx_declare(Fast_Literal_o, "getValue()", cx_type(cx_virtual_o));
    if (!Fast_Literal_getValue_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Literal::getValue()'.");
        goto error;
    }

    /* Define ::cortex::Fast::Literal::getValue() */
    if (!cx_checkState(Fast_Literal_getValue_o, CX_DEFINED)) {
        cx_function(Fast_Literal_getValue_o)->returnType = cx_resolve_ext(Fast_Literal_getValue_o, NULL, "::cortex::lang::word", FALSE, "element ::cortex::Fast::Literal::getValue().returnType");
        cx_function(Fast_Literal_getValue_o)->returnsReference = FALSE;
        cx_method(Fast_Literal_getValue_o)->virtual = TRUE;
        
        /* Bind ::cortex::Fast::Literal::getValue() with C-function */
        cx_function(Fast_Literal_getValue_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Literal_getValue_v(void *args, void *result);
        cx_function(Fast_Literal_getValue_o)->impl = (cx_word)__Fast_Literal_getValue_v;
        if (cx_define(Fast_Literal_getValue_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Literal::getValue()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Literal::init() */
    Fast_Literal_init_o = cx_declare(Fast_Literal_o, "init()", cx_type(cx_method_o));
    if (!Fast_Literal_init_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Literal::init()'.");
        goto error;
    }

    /* Define ::cortex::Fast::Literal::init() */
    if (!cx_checkState(Fast_Literal_init_o, CX_DEFINED)) {
        cx_function(Fast_Literal_init_o)->returnType = cx_resolve_ext(Fast_Literal_init_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::Literal::init().returnType");
        cx_function(Fast_Literal_init_o)->returnsReference = FALSE;
        Fast_Literal_init_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Literal::init() with C-function */
        cx_function(Fast_Literal_init_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Literal_init(void *args, void *result);
        cx_function(Fast_Literal_init_o)->impl = (cx_word)__Fast_Literal_init;
        if (cx_define(Fast_Literal_init_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Literal::init()'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::Literal */
    if (!cx_checkState(Fast_Literal_o, CX_DEFINED)) {
        cx_type(Fast_Literal_o)->defaultType = cx_resolve_ext(Fast_Literal_o, NULL, "::cortex::lang::member", FALSE, "element ::cortex::Fast::Literal.defaultType");
        cx_type(Fast_Literal_o)->parentType = NULL;
        cx_type(Fast_Literal_o)->parentState = 0x0;
        cx_interface(Fast_Literal_o)->base = cx_resolve_ext(Fast_Literal_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::Literal.base");
        cx_struct(Fast_Literal_o)->baseAccess = 0x4;
        Fast_Literal_o->implements.length = 0;
        Fast_Literal_o->implements.buffer = NULL;
        if (cx_define(Fast_Literal_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Literal'.");
            goto error;
        }
    }

    if (cx_type(Fast_Literal_o)->size != sizeof(struct Fast_Literal_s)) {
        cx_error("Fast_load: calculated size '%d' of type '::cortex::Fast::Literal' doesn't match C-type size '%d'", cx_type(Fast_Literal_o)->size, sizeof(struct Fast_Literal_s));
    }

    /* Declare ::cortex::Fast::Boolean::init() */
    Fast_Boolean_init_o = cx_declare(Fast_Boolean_o, "init()", cx_type(cx_method_o));
    if (!Fast_Boolean_init_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Boolean::init()'.");
        goto error;
    }

    /* Define ::cortex::Fast::Boolean::init() */
    if (!cx_checkState(Fast_Boolean_init_o, CX_DEFINED)) {
        cx_function(Fast_Boolean_init_o)->returnType = cx_resolve_ext(Fast_Boolean_init_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::Boolean::init().returnType");
        cx_function(Fast_Boolean_init_o)->returnsReference = FALSE;
        Fast_Boolean_init_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Boolean::init() with C-function */
        cx_function(Fast_Boolean_init_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Boolean_init(void *args, void *result);
        cx_function(Fast_Boolean_init_o)->impl = (cx_word)__Fast_Boolean_init;
        if (cx_define(Fast_Boolean_init_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Boolean::init()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Boolean::serialize(type dstType,word dst) */
    Fast_Boolean_serialize_o = cx_declare(Fast_Boolean_o, "serialize(type dstType,word dst)", cx_type(cx_method_o));
    if (!Fast_Boolean_serialize_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Boolean::serialize(type dstType,word dst)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Boolean::serialize(type dstType,word dst) */
    if (!cx_checkState(Fast_Boolean_serialize_o, CX_DEFINED)) {
        cx_function(Fast_Boolean_serialize_o)->returnType = cx_resolve_ext(Fast_Boolean_serialize_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::Boolean::serialize(type dstType,word dst).returnType");
        cx_function(Fast_Boolean_serialize_o)->returnsReference = FALSE;
        Fast_Boolean_serialize_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Boolean::serialize(type dstType,word dst) with C-function */
        cx_function(Fast_Boolean_serialize_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Boolean_serialize(void *args, void *result);
        cx_function(Fast_Boolean_serialize_o)->impl = (cx_word)__Fast_Boolean_serialize;
        if (cx_define(Fast_Boolean_serialize_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Boolean::serialize(type dstType,word dst)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Boolean::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
    Fast_Boolean_toIc_o = cx_declare(Fast_Boolean_o, "toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)", cx_type(cx_virtual_o));
    if (!Fast_Boolean_toIc_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Boolean::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Boolean::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
    if (!cx_checkState(Fast_Boolean_toIc_o, CX_DEFINED)) {
        cx_function(Fast_Boolean_toIc_o)->returnType = cx_resolve_ext(Fast_Boolean_toIc_o, NULL, "::cortex::lang::alias{\"cx_ic\"}", FALSE, "element ::cortex::Fast::Boolean::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored).returnType");
        cx_function(Fast_Boolean_toIc_o)->returnsReference = FALSE;
        cx_method(Fast_Boolean_toIc_o)->virtual = TRUE;
        
        /* Bind ::cortex::Fast::Boolean::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) with C-function */
        cx_function(Fast_Boolean_toIc_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Boolean_toIc_v(void *args, void *result);
        cx_function(Fast_Boolean_toIc_o)->impl = (cx_word)__Fast_Boolean_toIc_v;
        if (cx_define(Fast_Boolean_toIc_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Boolean::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::Boolean */
    if (!cx_checkState(Fast_Boolean_o, CX_DEFINED)) {
        cx_type(Fast_Boolean_o)->defaultType = cx_resolve_ext(Fast_Boolean_o, NULL, "::cortex::lang::member", FALSE, "element ::cortex::Fast::Boolean.defaultType");
        cx_type(Fast_Boolean_o)->parentType = NULL;
        cx_type(Fast_Boolean_o)->parentState = 0x0;
        cx_interface(Fast_Boolean_o)->base = cx_resolve_ext(Fast_Boolean_o, NULL, "::cortex::Fast::Literal", FALSE, "element ::cortex::Fast::Boolean.base");
        cx_struct(Fast_Boolean_o)->baseAccess = 0x4;
        Fast_Boolean_o->implements.length = 0;
        Fast_Boolean_o->implements.buffer = NULL;
        if (cx_define(Fast_Boolean_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Boolean'.");
            goto error;
        }
    }

    if (cx_type(Fast_Boolean_o)->size != sizeof(struct Fast_Boolean_s)) {
        cx_error("Fast_load: calculated size '%d' of type '::cortex::Fast::Boolean' doesn't match C-type size '%d'", cx_type(Fast_Boolean_o)->size, sizeof(struct Fast_Boolean_s));
    }

    /* Declare ::cortex::Fast::Character::init() */
    Fast_Character_init_o = cx_declare(Fast_Character_o, "init()", cx_type(cx_method_o));
    if (!Fast_Character_init_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Character::init()'.");
        goto error;
    }

    /* Define ::cortex::Fast::Character::init() */
    if (!cx_checkState(Fast_Character_init_o, CX_DEFINED)) {
        cx_function(Fast_Character_init_o)->returnType = cx_resolve_ext(Fast_Character_init_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::Character::init().returnType");
        cx_function(Fast_Character_init_o)->returnsReference = FALSE;
        Fast_Character_init_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Character::init() with C-function */
        cx_function(Fast_Character_init_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Character_init(void *args, void *result);
        cx_function(Fast_Character_init_o)->impl = (cx_word)__Fast_Character_init;
        if (cx_define(Fast_Character_init_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Character::init()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Character::serialize(type dstType,word dst) */
    Fast_Character_serialize_o = cx_declare(Fast_Character_o, "serialize(type dstType,word dst)", cx_type(cx_method_o));
    if (!Fast_Character_serialize_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Character::serialize(type dstType,word dst)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Character::serialize(type dstType,word dst) */
    if (!cx_checkState(Fast_Character_serialize_o, CX_DEFINED)) {
        cx_function(Fast_Character_serialize_o)->returnType = cx_resolve_ext(Fast_Character_serialize_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::Character::serialize(type dstType,word dst).returnType");
        cx_function(Fast_Character_serialize_o)->returnsReference = FALSE;
        Fast_Character_serialize_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Character::serialize(type dstType,word dst) with C-function */
        cx_function(Fast_Character_serialize_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Character_serialize(void *args, void *result);
        cx_function(Fast_Character_serialize_o)->impl = (cx_word)__Fast_Character_serialize;
        if (cx_define(Fast_Character_serialize_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Character::serialize(type dstType,word dst)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Character::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
    Fast_Character_toIc_o = cx_declare(Fast_Character_o, "toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)", cx_type(cx_virtual_o));
    if (!Fast_Character_toIc_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Character::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Character::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
    if (!cx_checkState(Fast_Character_toIc_o, CX_DEFINED)) {
        cx_function(Fast_Character_toIc_o)->returnType = cx_resolve_ext(Fast_Character_toIc_o, NULL, "::cortex::lang::alias{\"cx_ic\"}", FALSE, "element ::cortex::Fast::Character::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored).returnType");
        cx_function(Fast_Character_toIc_o)->returnsReference = FALSE;
        cx_method(Fast_Character_toIc_o)->virtual = TRUE;
        
        /* Bind ::cortex::Fast::Character::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) with C-function */
        cx_function(Fast_Character_toIc_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Character_toIc_v(void *args, void *result);
        cx_function(Fast_Character_toIc_o)->impl = (cx_word)__Fast_Character_toIc_v;
        if (cx_define(Fast_Character_toIc_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Character::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::Character */
    if (!cx_checkState(Fast_Character_o, CX_DEFINED)) {
        cx_type(Fast_Character_o)->defaultType = cx_resolve_ext(Fast_Character_o, NULL, "::cortex::lang::member", FALSE, "element ::cortex::Fast::Character.defaultType");
        cx_type(Fast_Character_o)->parentType = NULL;
        cx_type(Fast_Character_o)->parentState = 0x0;
        cx_interface(Fast_Character_o)->base = cx_resolve_ext(Fast_Character_o, NULL, "::cortex::Fast::Literal", FALSE, "element ::cortex::Fast::Character.base");
        cx_struct(Fast_Character_o)->baseAccess = 0x4;
        Fast_Character_o->implements.length = 0;
        Fast_Character_o->implements.buffer = NULL;
        if (cx_define(Fast_Character_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Character'.");
            goto error;
        }
    }

    if (cx_type(Fast_Character_o)->size != sizeof(struct Fast_Character_s)) {
        cx_error("Fast_load: calculated size '%d' of type '::cortex::Fast::Character' doesn't match C-type size '%d'", cx_type(Fast_Character_o)->size, sizeof(struct Fast_Character_s));
    }

    /* Declare ::cortex::Fast::FloatingPoint::init() */
    Fast_FloatingPoint_init_o = cx_declare(Fast_FloatingPoint_o, "init()", cx_type(cx_method_o));
    if (!Fast_FloatingPoint_init_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::FloatingPoint::init()'.");
        goto error;
    }

    /* Define ::cortex::Fast::FloatingPoint::init() */
    if (!cx_checkState(Fast_FloatingPoint_init_o, CX_DEFINED)) {
        cx_function(Fast_FloatingPoint_init_o)->returnType = cx_resolve_ext(Fast_FloatingPoint_init_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::FloatingPoint::init().returnType");
        cx_function(Fast_FloatingPoint_init_o)->returnsReference = FALSE;
        Fast_FloatingPoint_init_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::FloatingPoint::init() with C-function */
        cx_function(Fast_FloatingPoint_init_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_FloatingPoint_init(void *args, void *result);
        cx_function(Fast_FloatingPoint_init_o)->impl = (cx_word)__Fast_FloatingPoint_init;
        if (cx_define(Fast_FloatingPoint_init_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::FloatingPoint::init()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::FloatingPoint::serialize(type dstType,word dst) */
    Fast_FloatingPoint_serialize_o = cx_declare(Fast_FloatingPoint_o, "serialize(type dstType,word dst)", cx_type(cx_method_o));
    if (!Fast_FloatingPoint_serialize_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::FloatingPoint::serialize(type dstType,word dst)'.");
        goto error;
    }

    /* Define ::cortex::Fast::FloatingPoint::serialize(type dstType,word dst) */
    if (!cx_checkState(Fast_FloatingPoint_serialize_o, CX_DEFINED)) {
        cx_function(Fast_FloatingPoint_serialize_o)->returnType = cx_resolve_ext(Fast_FloatingPoint_serialize_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::FloatingPoint::serialize(type dstType,word dst).returnType");
        cx_function(Fast_FloatingPoint_serialize_o)->returnsReference = FALSE;
        Fast_FloatingPoint_serialize_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::FloatingPoint::serialize(type dstType,word dst) with C-function */
        cx_function(Fast_FloatingPoint_serialize_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_FloatingPoint_serialize(void *args, void *result);
        cx_function(Fast_FloatingPoint_serialize_o)->impl = (cx_word)__Fast_FloatingPoint_serialize;
        if (cx_define(Fast_FloatingPoint_serialize_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::FloatingPoint::serialize(type dstType,word dst)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::FloatingPoint::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
    Fast_FloatingPoint_toIc_o = cx_declare(Fast_FloatingPoint_o, "toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)", cx_type(cx_virtual_o));
    if (!Fast_FloatingPoint_toIc_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::FloatingPoint::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)'.");
        goto error;
    }

    /* Define ::cortex::Fast::FloatingPoint::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
    if (!cx_checkState(Fast_FloatingPoint_toIc_o, CX_DEFINED)) {
        cx_function(Fast_FloatingPoint_toIc_o)->returnType = cx_resolve_ext(Fast_FloatingPoint_toIc_o, NULL, "::cortex::lang::alias{\"cx_ic\"}", FALSE, "element ::cortex::Fast::FloatingPoint::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored).returnType");
        cx_function(Fast_FloatingPoint_toIc_o)->returnsReference = FALSE;
        cx_method(Fast_FloatingPoint_toIc_o)->virtual = TRUE;
        
        /* Bind ::cortex::Fast::FloatingPoint::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) with C-function */
        cx_function(Fast_FloatingPoint_toIc_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_FloatingPoint_toIc_v(void *args, void *result);
        cx_function(Fast_FloatingPoint_toIc_o)->impl = (cx_word)__Fast_FloatingPoint_toIc_v;
        if (cx_define(Fast_FloatingPoint_toIc_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::FloatingPoint::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::FloatingPoint */
    if (!cx_checkState(Fast_FloatingPoint_o, CX_DEFINED)) {
        cx_type(Fast_FloatingPoint_o)->defaultType = cx_resolve_ext(Fast_FloatingPoint_o, NULL, "::cortex::lang::member", FALSE, "element ::cortex::Fast::FloatingPoint.defaultType");
        cx_type(Fast_FloatingPoint_o)->parentType = NULL;
        cx_type(Fast_FloatingPoint_o)->parentState = 0x0;
        cx_interface(Fast_FloatingPoint_o)->base = cx_resolve_ext(Fast_FloatingPoint_o, NULL, "::cortex::Fast::Literal", FALSE, "element ::cortex::Fast::FloatingPoint.base");
        cx_struct(Fast_FloatingPoint_o)->baseAccess = 0x4;
        Fast_FloatingPoint_o->implements.length = 0;
        Fast_FloatingPoint_o->implements.buffer = NULL;
        if (cx_define(Fast_FloatingPoint_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::FloatingPoint'.");
            goto error;
        }
    }

    if (cx_type(Fast_FloatingPoint_o)->size != sizeof(struct Fast_FloatingPoint_s)) {
        cx_error("Fast_load: calculated size '%d' of type '::cortex::Fast::FloatingPoint' doesn't match C-type size '%d'", cx_type(Fast_FloatingPoint_o)->size, sizeof(struct Fast_FloatingPoint_s));
    }

    /* Declare ::cortex::Fast::Integer::init() */
    Fast_Integer_init_o = cx_declare(Fast_Integer_o, "init()", cx_type(cx_method_o));
    if (!Fast_Integer_init_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Integer::init()'.");
        goto error;
    }

    /* Define ::cortex::Fast::Integer::init() */
    if (!cx_checkState(Fast_Integer_init_o, CX_DEFINED)) {
        cx_function(Fast_Integer_init_o)->returnType = cx_resolve_ext(Fast_Integer_init_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::Integer::init().returnType");
        cx_function(Fast_Integer_init_o)->returnsReference = FALSE;
        Fast_Integer_init_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Integer::init() with C-function */
        cx_function(Fast_Integer_init_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Integer_init(void *args, void *result);
        cx_function(Fast_Integer_init_o)->impl = (cx_word)__Fast_Integer_init;
        if (cx_define(Fast_Integer_init_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Integer::init()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Integer::serialize(type dstType,word dst) */
    Fast_Integer_serialize_o = cx_declare(Fast_Integer_o, "serialize(type dstType,word dst)", cx_type(cx_method_o));
    if (!Fast_Integer_serialize_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Integer::serialize(type dstType,word dst)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Integer::serialize(type dstType,word dst) */
    if (!cx_checkState(Fast_Integer_serialize_o, CX_DEFINED)) {
        cx_function(Fast_Integer_serialize_o)->returnType = cx_resolve_ext(Fast_Integer_serialize_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::Integer::serialize(type dstType,word dst).returnType");
        cx_function(Fast_Integer_serialize_o)->returnsReference = FALSE;
        Fast_Integer_serialize_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Integer::serialize(type dstType,word dst) with C-function */
        cx_function(Fast_Integer_serialize_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Integer_serialize(void *args, void *result);
        cx_function(Fast_Integer_serialize_o)->impl = (cx_word)__Fast_Integer_serialize;
        if (cx_define(Fast_Integer_serialize_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Integer::serialize(type dstType,word dst)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Integer::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
    Fast_Integer_toIc_o = cx_declare(Fast_Integer_o, "toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)", cx_type(cx_virtual_o));
    if (!Fast_Integer_toIc_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Integer::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Integer::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
    if (!cx_checkState(Fast_Integer_toIc_o, CX_DEFINED)) {
        cx_function(Fast_Integer_toIc_o)->returnType = cx_resolve_ext(Fast_Integer_toIc_o, NULL, "::cortex::lang::alias{\"cx_ic\"}", FALSE, "element ::cortex::Fast::Integer::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored).returnType");
        cx_function(Fast_Integer_toIc_o)->returnsReference = FALSE;
        cx_method(Fast_Integer_toIc_o)->virtual = TRUE;
        
        /* Bind ::cortex::Fast::Integer::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) with C-function */
        cx_function(Fast_Integer_toIc_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Integer_toIc_v(void *args, void *result);
        cx_function(Fast_Integer_toIc_o)->impl = (cx_word)__Fast_Integer_toIc_v;
        if (cx_define(Fast_Integer_toIc_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Integer::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::Integer */
    if (!cx_checkState(Fast_Integer_o, CX_DEFINED)) {
        cx_type(Fast_Integer_o)->defaultType = cx_resolve_ext(Fast_Integer_o, NULL, "::cortex::lang::member", FALSE, "element ::cortex::Fast::Integer.defaultType");
        cx_type(Fast_Integer_o)->parentType = NULL;
        cx_type(Fast_Integer_o)->parentState = 0x0;
        cx_interface(Fast_Integer_o)->base = cx_resolve_ext(Fast_Integer_o, NULL, "::cortex::Fast::Literal", FALSE, "element ::cortex::Fast::Integer.base");
        cx_struct(Fast_Integer_o)->baseAccess = 0x4;
        Fast_Integer_o->implements.length = 0;
        Fast_Integer_o->implements.buffer = NULL;
        if (cx_define(Fast_Integer_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Integer'.");
            goto error;
        }
    }

    if (cx_type(Fast_Integer_o)->size != sizeof(struct Fast_Integer_s)) {
        cx_error("Fast_load: calculated size '%d' of type '::cortex::Fast::Integer' doesn't match C-type size '%d'", cx_type(Fast_Integer_o)->size, sizeof(struct Fast_Integer_s));
    }

    /* Define ::cortex::Fast::DynamicInitializerFrame::sequenceSize */
    if (!cx_checkState(Fast_DynamicInitializerFrame_sequenceSize_o, CX_DEFINED)) {
        Fast_DynamicInitializerFrame_sequenceSize_o->type = cx_resolve_ext(Fast_DynamicInitializerFrame_sequenceSize_o, NULL, "::cortex::Fast::Integer", FALSE, "element ::cortex::Fast::DynamicInitializerFrame::sequenceSize.type");
        Fast_DynamicInitializerFrame_sequenceSize_o->modifiers = 0x0;
        Fast_DynamicInitializerFrame_sequenceSize_o->state = 0x6;
        Fast_DynamicInitializerFrame_sequenceSize_o->weak = FALSE;
        Fast_DynamicInitializerFrame_sequenceSize_o->id = 2;
        if (cx_define(Fast_DynamicInitializerFrame_sequenceSize_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::DynamicInitializerFrame::sequenceSize'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Null::init() */
    Fast_Null_init_o = cx_declare(Fast_Null_o, "init()", cx_type(cx_method_o));
    if (!Fast_Null_init_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Null::init()'.");
        goto error;
    }

    /* Define ::cortex::Fast::Null::init() */
    if (!cx_checkState(Fast_Null_init_o, CX_DEFINED)) {
        cx_function(Fast_Null_init_o)->returnType = cx_resolve_ext(Fast_Null_init_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::Null::init().returnType");
        cx_function(Fast_Null_init_o)->returnsReference = FALSE;
        Fast_Null_init_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Null::init() with C-function */
        cx_function(Fast_Null_init_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Null_init(void *args, void *result);
        cx_function(Fast_Null_init_o)->impl = (cx_word)__Fast_Null_init;
        if (cx_define(Fast_Null_init_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Null::init()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Null::serialize(type dstType,word dst) */
    Fast_Null_serialize_o = cx_declare(Fast_Null_o, "serialize(type dstType,word dst)", cx_type(cx_method_o));
    if (!Fast_Null_serialize_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Null::serialize(type dstType,word dst)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Null::serialize(type dstType,word dst) */
    if (!cx_checkState(Fast_Null_serialize_o, CX_DEFINED)) {
        cx_function(Fast_Null_serialize_o)->returnType = cx_resolve_ext(Fast_Null_serialize_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::Null::serialize(type dstType,word dst).returnType");
        cx_function(Fast_Null_serialize_o)->returnsReference = FALSE;
        Fast_Null_serialize_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Null::serialize(type dstType,word dst) with C-function */
        cx_function(Fast_Null_serialize_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Null_serialize(void *args, void *result);
        cx_function(Fast_Null_serialize_o)->impl = (cx_word)__Fast_Null_serialize;
        if (cx_define(Fast_Null_serialize_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Null::serialize(type dstType,word dst)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Null::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
    Fast_Null_toIc_o = cx_declare(Fast_Null_o, "toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)", cx_type(cx_virtual_o));
    if (!Fast_Null_toIc_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Null::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Null::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
    if (!cx_checkState(Fast_Null_toIc_o, CX_DEFINED)) {
        cx_function(Fast_Null_toIc_o)->returnType = cx_resolve_ext(Fast_Null_toIc_o, NULL, "::cortex::lang::alias{\"cx_ic\"}", FALSE, "element ::cortex::Fast::Null::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored).returnType");
        cx_function(Fast_Null_toIc_o)->returnsReference = FALSE;
        cx_method(Fast_Null_toIc_o)->virtual = TRUE;
        
        /* Bind ::cortex::Fast::Null::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) with C-function */
        cx_function(Fast_Null_toIc_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Null_toIc_v(void *args, void *result);
        cx_function(Fast_Null_toIc_o)->impl = (cx_word)__Fast_Null_toIc_v;
        if (cx_define(Fast_Null_toIc_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Null::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::Null */
    if (!cx_checkState(Fast_Null_o, CX_DEFINED)) {
        cx_type(Fast_Null_o)->defaultType = cx_resolve_ext(Fast_Null_o, NULL, "::cortex::lang::member", FALSE, "element ::cortex::Fast::Null.defaultType");
        cx_type(Fast_Null_o)->parentType = NULL;
        cx_type(Fast_Null_o)->parentState = 0x0;
        cx_interface(Fast_Null_o)->base = cx_resolve_ext(Fast_Null_o, NULL, "::cortex::Fast::Literal", FALSE, "element ::cortex::Fast::Null.base");
        cx_struct(Fast_Null_o)->baseAccess = 0x4;
        Fast_Null_o->implements.length = 0;
        Fast_Null_o->implements.buffer = NULL;
        if (cx_define(Fast_Null_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Null'.");
            goto error;
        }
    }

    if (cx_type(Fast_Null_o)->size != sizeof(struct Fast_Null_s)) {
        cx_error("Fast_load: calculated size '%d' of type '::cortex::Fast::Null' doesn't match C-type size '%d'", cx_type(Fast_Null_o)->size, sizeof(struct Fast_Null_s));
    }

    /* Declare ::cortex::Fast::SignedInteger::init() */
    Fast_SignedInteger_init_o = cx_declare(Fast_SignedInteger_o, "init()", cx_type(cx_method_o));
    if (!Fast_SignedInteger_init_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::SignedInteger::init()'.");
        goto error;
    }

    /* Define ::cortex::Fast::SignedInteger::init() */
    if (!cx_checkState(Fast_SignedInteger_init_o, CX_DEFINED)) {
        cx_function(Fast_SignedInteger_init_o)->returnType = cx_resolve_ext(Fast_SignedInteger_init_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::SignedInteger::init().returnType");
        cx_function(Fast_SignedInteger_init_o)->returnsReference = FALSE;
        Fast_SignedInteger_init_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::SignedInteger::init() with C-function */
        cx_function(Fast_SignedInteger_init_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_SignedInteger_init(void *args, void *result);
        cx_function(Fast_SignedInteger_init_o)->impl = (cx_word)__Fast_SignedInteger_init;
        if (cx_define(Fast_SignedInteger_init_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::SignedInteger::init()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::SignedInteger::serialize(type dstType,word dst) */
    Fast_SignedInteger_serialize_o = cx_declare(Fast_SignedInteger_o, "serialize(type dstType,word dst)", cx_type(cx_method_o));
    if (!Fast_SignedInteger_serialize_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::SignedInteger::serialize(type dstType,word dst)'.");
        goto error;
    }

    /* Define ::cortex::Fast::SignedInteger::serialize(type dstType,word dst) */
    if (!cx_checkState(Fast_SignedInteger_serialize_o, CX_DEFINED)) {
        cx_function(Fast_SignedInteger_serialize_o)->returnType = cx_resolve_ext(Fast_SignedInteger_serialize_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::SignedInteger::serialize(type dstType,word dst).returnType");
        cx_function(Fast_SignedInteger_serialize_o)->returnsReference = FALSE;
        Fast_SignedInteger_serialize_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::SignedInteger::serialize(type dstType,word dst) with C-function */
        cx_function(Fast_SignedInteger_serialize_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_SignedInteger_serialize(void *args, void *result);
        cx_function(Fast_SignedInteger_serialize_o)->impl = (cx_word)__Fast_SignedInteger_serialize;
        if (cx_define(Fast_SignedInteger_serialize_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::SignedInteger::serialize(type dstType,word dst)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::SignedInteger::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
    Fast_SignedInteger_toIc_o = cx_declare(Fast_SignedInteger_o, "toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)", cx_type(cx_virtual_o));
    if (!Fast_SignedInteger_toIc_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::SignedInteger::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)'.");
        goto error;
    }

    /* Define ::cortex::Fast::SignedInteger::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
    if (!cx_checkState(Fast_SignedInteger_toIc_o, CX_DEFINED)) {
        cx_function(Fast_SignedInteger_toIc_o)->returnType = cx_resolve_ext(Fast_SignedInteger_toIc_o, NULL, "::cortex::lang::alias{\"cx_ic\"}", FALSE, "element ::cortex::Fast::SignedInteger::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored).returnType");
        cx_function(Fast_SignedInteger_toIc_o)->returnsReference = FALSE;
        cx_method(Fast_SignedInteger_toIc_o)->virtual = TRUE;
        
        /* Bind ::cortex::Fast::SignedInteger::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) with C-function */
        cx_function(Fast_SignedInteger_toIc_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_SignedInteger_toIc_v(void *args, void *result);
        cx_function(Fast_SignedInteger_toIc_o)->impl = (cx_word)__Fast_SignedInteger_toIc_v;
        if (cx_define(Fast_SignedInteger_toIc_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::SignedInteger::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::SignedInteger */
    if (!cx_checkState(Fast_SignedInteger_o, CX_DEFINED)) {
        cx_type(Fast_SignedInteger_o)->defaultType = cx_resolve_ext(Fast_SignedInteger_o, NULL, "::cortex::lang::member", FALSE, "element ::cortex::Fast::SignedInteger.defaultType");
        cx_type(Fast_SignedInteger_o)->parentType = NULL;
        cx_type(Fast_SignedInteger_o)->parentState = 0x0;
        cx_interface(Fast_SignedInteger_o)->base = cx_resolve_ext(Fast_SignedInteger_o, NULL, "::cortex::Fast::Literal", FALSE, "element ::cortex::Fast::SignedInteger.base");
        cx_struct(Fast_SignedInteger_o)->baseAccess = 0x4;
        Fast_SignedInteger_o->implements.length = 0;
        Fast_SignedInteger_o->implements.buffer = NULL;
        if (cx_define(Fast_SignedInteger_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::SignedInteger'.");
            goto error;
        }
    }

    if (cx_type(Fast_SignedInteger_o)->size != sizeof(struct Fast_SignedInteger_s)) {
        cx_error("Fast_load: calculated size '%d' of type '::cortex::Fast::SignedInteger' doesn't match C-type size '%d'", cx_type(Fast_SignedInteger_o)->size, sizeof(struct Fast_SignedInteger_s));
    }

    /* Declare ::cortex::Fast::String::construct() */
    Fast_String_construct_o = cx_declare(Fast_String_o, "construct()", cx_type(cx_method_o));
    if (!Fast_String_construct_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::String::construct()'.");
        goto error;
    }

    /* Define ::cortex::Fast::String::construct() */
    if (!cx_checkState(Fast_String_construct_o, CX_DEFINED)) {
        cx_function(Fast_String_construct_o)->returnType = cx_resolve_ext(Fast_String_construct_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::String::construct().returnType");
        cx_function(Fast_String_construct_o)->returnsReference = FALSE;
        Fast_String_construct_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::String::construct() with C-function */
        cx_function(Fast_String_construct_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_String_construct(void *args, void *result);
        cx_function(Fast_String_construct_o)->impl = (cx_word)__Fast_String_construct;
        if (cx_define(Fast_String_construct_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::String::construct()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::String::getValue() */
    Fast_String_getValue_o = cx_declare(Fast_String_o, "getValue()", cx_type(cx_method_o));
    if (!Fast_String_getValue_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::String::getValue()'.");
        goto error;
    }

    /* Define ::cortex::Fast::String::getValue() */
    if (!cx_checkState(Fast_String_getValue_o, CX_DEFINED)) {
        cx_function(Fast_String_getValue_o)->returnType = cx_resolve_ext(Fast_String_getValue_o, NULL, "::cortex::lang::word", FALSE, "element ::cortex::Fast::String::getValue().returnType");
        cx_function(Fast_String_getValue_o)->returnsReference = FALSE;
        Fast_String_getValue_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::String::getValue() with C-function */
        cx_function(Fast_String_getValue_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_String_getValue(void *args, void *result);
        cx_function(Fast_String_getValue_o)->impl = (cx_word)__Fast_String_getValue;
        if (cx_define(Fast_String_getValue_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::String::getValue()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::String::init() */
    Fast_String_init_o = cx_declare(Fast_String_o, "init()", cx_type(cx_method_o));
    if (!Fast_String_init_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::String::init()'.");
        goto error;
    }

    /* Define ::cortex::Fast::String::init() */
    if (!cx_checkState(Fast_String_init_o, CX_DEFINED)) {
        cx_function(Fast_String_init_o)->returnType = cx_resolve_ext(Fast_String_init_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::String::init().returnType");
        cx_function(Fast_String_init_o)->returnsReference = FALSE;
        Fast_String_init_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::String::init() with C-function */
        cx_function(Fast_String_init_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_String_init(void *args, void *result);
        cx_function(Fast_String_init_o)->impl = (cx_word)__Fast_String_init;
        if (cx_define(Fast_String_init_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::String::init()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::String::serialize(type dstType,word dst) */
    Fast_String_serialize_o = cx_declare(Fast_String_o, "serialize(type dstType,word dst)", cx_type(cx_method_o));
    if (!Fast_String_serialize_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::String::serialize(type dstType,word dst)'.");
        goto error;
    }

    /* Define ::cortex::Fast::String::serialize(type dstType,word dst) */
    if (!cx_checkState(Fast_String_serialize_o, CX_DEFINED)) {
        cx_function(Fast_String_serialize_o)->returnType = cx_resolve_ext(Fast_String_serialize_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::String::serialize(type dstType,word dst).returnType");
        cx_function(Fast_String_serialize_o)->returnsReference = FALSE;
        Fast_String_serialize_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::String::serialize(type dstType,word dst) with C-function */
        cx_function(Fast_String_serialize_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_String_serialize(void *args, void *result);
        cx_function(Fast_String_serialize_o)->impl = (cx_word)__Fast_String_serialize;
        if (cx_define(Fast_String_serialize_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::String::serialize(type dstType,word dst)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::String::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
    Fast_String_toIc_o = cx_declare(Fast_String_o, "toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)", cx_type(cx_virtual_o));
    if (!Fast_String_toIc_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::String::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)'.");
        goto error;
    }

    /* Define ::cortex::Fast::String::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
    if (!cx_checkState(Fast_String_toIc_o, CX_DEFINED)) {
        cx_function(Fast_String_toIc_o)->returnType = cx_resolve_ext(Fast_String_toIc_o, NULL, "::cortex::lang::alias{\"cx_ic\"}", FALSE, "element ::cortex::Fast::String::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored).returnType");
        cx_function(Fast_String_toIc_o)->returnsReference = FALSE;
        cx_method(Fast_String_toIc_o)->virtual = TRUE;
        
        /* Bind ::cortex::Fast::String::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) with C-function */
        cx_function(Fast_String_toIc_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_String_toIc_v(void *args, void *result);
        cx_function(Fast_String_toIc_o)->impl = (cx_word)__Fast_String_toIc_v;
        if (cx_define(Fast_String_toIc_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::String::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::Lvalue::expr */
    if (!cx_checkState(Fast_Lvalue_expr_o, CX_DEFINED)) {
        Fast_Lvalue_expr_o->type = cx_resolve_ext(Fast_Lvalue_expr_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::Lvalue::expr.type");
        Fast_Lvalue_expr_o->modifiers = 0x0;
        Fast_Lvalue_expr_o->state = 0x6;
        Fast_Lvalue_expr_o->weak = FALSE;
        Fast_Lvalue_expr_o->id = 0;
        if (cx_define(Fast_Lvalue_expr_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Lvalue::expr'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::Lvalue */
    if (!cx_checkState(Fast_Lvalue_o, CX_DEFINED)) {
        cx_type(Fast_Lvalue_o)->defaultType = cx_resolve_ext(Fast_Lvalue_o, NULL, "::cortex::lang::member", FALSE, "element ::cortex::Fast::Lvalue.defaultType");
        cx_type(Fast_Lvalue_o)->parentType = NULL;
        cx_type(Fast_Lvalue_o)->parentState = 0x0;
        cx_interface(Fast_Lvalue_o)->base = NULL;
        Fast_Lvalue_o->baseAccess = 0x0;
        if (cx_define(Fast_Lvalue_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Lvalue'.");
            goto error;
        }
    }

    if (cx_type(Fast_Lvalue_o)->size != sizeof(Fast_Lvalue)) {
        cx_error("Fast_load: calculated size '%d' of type '::cortex::Fast::Lvalue' doesn't match C-type size '%d'", cx_type(Fast_Lvalue_o)->size, sizeof(Fast_Lvalue));
    }

    /* Define ::cortex::Fast::Parser::lvalue */
    if (!cx_checkState(Fast_Parser_lvalue_o, CX_DEFINED)) {
        Fast_Parser_lvalue_o->type = cx_resolve_ext(Fast_Parser_lvalue_o, NULL, "::cortex::lang::array{::cortex::Fast::Lvalue,64,::cortex::Fast::Lvalue}", FALSE, "element ::cortex::Fast::Parser::lvalue.type");
        Fast_Parser_lvalue_o->modifiers = 0x3;
        Fast_Parser_lvalue_o->state = 0x6;
        Fast_Parser_lvalue_o->weak = FALSE;
        Fast_Parser_lvalue_o->id = 35;
        if (cx_define(Fast_Parser_lvalue_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::lvalue'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Member::construct() */
    Fast_Member_construct_o = cx_declare(Fast_Member_o, "construct()", cx_type(cx_method_o));
    if (!Fast_Member_construct_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Member::construct()'.");
        goto error;
    }

    /* Define ::cortex::Fast::Member::construct() */
    if (!cx_checkState(Fast_Member_construct_o, CX_DEFINED)) {
        cx_function(Fast_Member_construct_o)->returnType = cx_resolve_ext(Fast_Member_construct_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::Member::construct().returnType");
        cx_function(Fast_Member_construct_o)->returnsReference = FALSE;
        Fast_Member_construct_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Member::construct() with C-function */
        cx_function(Fast_Member_construct_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Member_construct(void *args, void *result);
        cx_function(Fast_Member_construct_o)->impl = (cx_word)__Fast_Member_construct;
        if (cx_define(Fast_Member_construct_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Member::construct()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Member::hasSideEffects() */
    Fast_Member_hasSideEffects_o = cx_declare(Fast_Member_o, "hasSideEffects()", cx_type(cx_virtual_o));
    if (!Fast_Member_hasSideEffects_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Member::hasSideEffects()'.");
        goto error;
    }

    /* Define ::cortex::Fast::Member::hasSideEffects() */
    if (!cx_checkState(Fast_Member_hasSideEffects_o, CX_DEFINED)) {
        cx_function(Fast_Member_hasSideEffects_o)->returnType = cx_resolve_ext(Fast_Member_hasSideEffects_o, NULL, "::cortex::lang::bool", FALSE, "element ::cortex::Fast::Member::hasSideEffects().returnType");
        cx_function(Fast_Member_hasSideEffects_o)->returnsReference = FALSE;
        cx_method(Fast_Member_hasSideEffects_o)->virtual = TRUE;
        
        /* Bind ::cortex::Fast::Member::hasSideEffects() with C-function */
        cx_function(Fast_Member_hasSideEffects_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Member_hasSideEffects_v(void *args, void *result);
        cx_function(Fast_Member_hasSideEffects_o)->impl = (cx_word)__Fast_Member_hasSideEffects_v;
        if (cx_define(Fast_Member_hasSideEffects_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Member::hasSideEffects()'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::Member::lvalue */
    if (!cx_checkState(Fast_Member_lvalue_o, CX_DEFINED)) {
        Fast_Member_lvalue_o->type = cx_resolve_ext(Fast_Member_lvalue_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::Member::lvalue.type");
        Fast_Member_lvalue_o->modifiers = 0x0;
        Fast_Member_lvalue_o->state = 0x6;
        Fast_Member_lvalue_o->weak = FALSE;
        Fast_Member_lvalue_o->id = 0;
        if (cx_define(Fast_Member_lvalue_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Member::lvalue'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::Member::rvalue */
    if (!cx_checkState(Fast_Member_rvalue_o, CX_DEFINED)) {
        Fast_Member_rvalue_o->type = cx_resolve_ext(Fast_Member_rvalue_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::Member::rvalue.type");
        Fast_Member_rvalue_o->modifiers = 0x0;
        Fast_Member_rvalue_o->state = 0x6;
        Fast_Member_rvalue_o->weak = FALSE;
        Fast_Member_rvalue_o->id = 1;
        if (cx_define(Fast_Member_rvalue_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Member::rvalue'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Member::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
    Fast_Member_toIc_o = cx_declare(Fast_Member_o, "toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)", cx_type(cx_virtual_o));
    if (!Fast_Member_toIc_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Member::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Member::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
    if (!cx_checkState(Fast_Member_toIc_o, CX_DEFINED)) {
        cx_function(Fast_Member_toIc_o)->returnType = cx_resolve_ext(Fast_Member_toIc_o, NULL, "::cortex::lang::alias{\"cx_ic\"}", FALSE, "element ::cortex::Fast::Member::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored).returnType");
        cx_function(Fast_Member_toIc_o)->returnsReference = FALSE;
        cx_method(Fast_Member_toIc_o)->virtual = TRUE;
        
        /* Bind ::cortex::Fast::Member::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) with C-function */
        cx_function(Fast_Member_toIc_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Member_toIc_v(void *args, void *result);
        cx_function(Fast_Member_toIc_o)->impl = (cx_word)__Fast_Member_toIc_v;
        if (cx_define(Fast_Member_toIc_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Member::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::Member */
    if (!cx_checkState(Fast_Member_o, CX_DEFINED)) {
        cx_type(Fast_Member_o)->defaultType = cx_resolve_ext(Fast_Member_o, NULL, "::cortex::lang::member", FALSE, "element ::cortex::Fast::Member.defaultType");
        cx_type(Fast_Member_o)->parentType = NULL;
        cx_type(Fast_Member_o)->parentState = 0x0;
        cx_interface(Fast_Member_o)->base = cx_resolve_ext(Fast_Member_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::Member.base");
        cx_struct(Fast_Member_o)->baseAccess = 0x4;
        Fast_Member_o->implements.length = 0;
        Fast_Member_o->implements.buffer = NULL;
        if (cx_define(Fast_Member_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Member'.");
            goto error;
        }
    }

    if (cx_type(Fast_Member_o)->size != sizeof(struct Fast_Member_s)) {
        cx_error("Fast_load: calculated size '%d' of type '::cortex::Fast::Member' doesn't match C-type size '%d'", cx_type(Fast_Member_o)->size, sizeof(struct Fast_Member_s));
    }

    /* Define ::cortex::Fast::New::attributes */
    if (!cx_checkState(Fast_New_attributes_o, CX_DEFINED)) {
        Fast_New_attributes_o->type = cx_resolve_ext(Fast_New_attributes_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::New::attributes.type");
        Fast_New_attributes_o->modifiers = 0x0;
        Fast_New_attributes_o->state = 0x6;
        Fast_New_attributes_o->weak = FALSE;
        Fast_New_attributes_o->id = 1;
        if (cx_define(Fast_New_attributes_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::New::attributes'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::New::construct() */
    Fast_New_construct_o = cx_declare(Fast_New_o, "construct()", cx_type(cx_method_o));
    if (!Fast_New_construct_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::New::construct()'.");
        goto error;
    }

    /* Define ::cortex::Fast::New::construct() */
    if (!cx_checkState(Fast_New_construct_o, CX_DEFINED)) {
        cx_function(Fast_New_construct_o)->returnType = cx_resolve_ext(Fast_New_construct_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::New::construct().returnType");
        cx_function(Fast_New_construct_o)->returnsReference = FALSE;
        Fast_New_construct_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::New::construct() with C-function */
        cx_function(Fast_New_construct_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_New_construct(void *args, void *result);
        cx_function(Fast_New_construct_o)->impl = (cx_word)__Fast_New_construct;
        if (cx_define(Fast_New_construct_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::New::construct()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::New::hasSideEffects() */
    Fast_New_hasSideEffects_o = cx_declare(Fast_New_o, "hasSideEffects()", cx_type(cx_virtual_o));
    if (!Fast_New_hasSideEffects_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::New::hasSideEffects()'.");
        goto error;
    }

    /* Define ::cortex::Fast::New::hasSideEffects() */
    if (!cx_checkState(Fast_New_hasSideEffects_o, CX_DEFINED)) {
        cx_function(Fast_New_hasSideEffects_o)->returnType = cx_resolve_ext(Fast_New_hasSideEffects_o, NULL, "::cortex::lang::bool", FALSE, "element ::cortex::Fast::New::hasSideEffects().returnType");
        cx_function(Fast_New_hasSideEffects_o)->returnsReference = FALSE;
        cx_method(Fast_New_hasSideEffects_o)->virtual = TRUE;
        
        /* Bind ::cortex::Fast::New::hasSideEffects() with C-function */
        cx_function(Fast_New_hasSideEffects_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_New_hasSideEffects_v(void *args, void *result);
        cx_function(Fast_New_hasSideEffects_o)->impl = (cx_word)__Fast_New_hasSideEffects_v;
        if (cx_define(Fast_New_hasSideEffects_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::New::hasSideEffects()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::New::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
    Fast_New_toIc_o = cx_declare(Fast_New_o, "toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)", cx_type(cx_virtual_o));
    if (!Fast_New_toIc_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::New::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)'.");
        goto error;
    }

    /* Define ::cortex::Fast::New::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
    if (!cx_checkState(Fast_New_toIc_o, CX_DEFINED)) {
        cx_function(Fast_New_toIc_o)->returnType = cx_resolve_ext(Fast_New_toIc_o, NULL, "::cortex::lang::alias{\"cx_ic\"}", FALSE, "element ::cortex::Fast::New::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored).returnType");
        cx_function(Fast_New_toIc_o)->returnsReference = FALSE;
        cx_method(Fast_New_toIc_o)->virtual = TRUE;
        
        /* Bind ::cortex::Fast::New::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) with C-function */
        cx_function(Fast_New_toIc_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_New_toIc_v(void *args, void *result);
        cx_function(Fast_New_toIc_o)->impl = (cx_word)__Fast_New_toIc_v;
        if (cx_define(Fast_New_toIc_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::New::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::New::type */
    if (!cx_checkState(Fast_New_type_o, CX_DEFINED)) {
        Fast_New_type_o->type = cx_resolve_ext(Fast_New_type_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::New::type.type");
        Fast_New_type_o->modifiers = 0x0;
        Fast_New_type_o->state = 0x6;
        Fast_New_type_o->weak = FALSE;
        Fast_New_type_o->id = 0;
        if (cx_define(Fast_New_type_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::New::type'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::New */
    if (!cx_checkState(Fast_New_o, CX_DEFINED)) {
        cx_type(Fast_New_o)->defaultType = cx_resolve_ext(Fast_New_o, NULL, "::cortex::lang::member", FALSE, "element ::cortex::Fast::New.defaultType");
        cx_type(Fast_New_o)->parentType = NULL;
        cx_type(Fast_New_o)->parentState = 0x0;
        cx_interface(Fast_New_o)->base = cx_resolve_ext(Fast_New_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::New.base");
        cx_struct(Fast_New_o)->baseAccess = 0x4;
        Fast_New_o->implements.length = 0;
        Fast_New_o->implements.buffer = NULL;
        if (cx_define(Fast_New_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::New'.");
            goto error;
        }
    }

    if (cx_type(Fast_New_o)->size != sizeof(struct Fast_New_s)) {
        cx_error("Fast_load: calculated size '%d' of type '::cortex::Fast::New' doesn't match C-type size '%d'", cx_type(Fast_New_o)->size, sizeof(struct Fast_New_s));
    }

    /* Declare ::cortex::Fast::Parser::binaryExpr(Fast::Expression lvalues,Fast::Expression rvalues,operatorKind operator) */
    Fast_Parser_binaryExpr_o = cx_declare(Fast_Parser_o, "binaryExpr(Fast::Expression lvalues,Fast::Expression rvalues,operatorKind operator)", cx_type(cx_method_o));
    if (!Fast_Parser_binaryExpr_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::binaryExpr(Fast::Expression lvalues,Fast::Expression rvalues,operatorKind operator)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::binaryExpr(Fast::Expression lvalues,Fast::Expression rvalues,operatorKind operator) */
    if (!cx_checkState(Fast_Parser_binaryExpr_o, CX_DEFINED)) {
        cx_function(Fast_Parser_binaryExpr_o)->returnType = cx_resolve_ext(Fast_Parser_binaryExpr_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::Parser::binaryExpr(Fast::Expression lvalues,Fast::Expression rvalues,operatorKind operator).returnType");
        cx_function(Fast_Parser_binaryExpr_o)->returnsReference = FALSE;
        Fast_Parser_binaryExpr_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Parser::binaryExpr(Fast::Expression lvalues,Fast::Expression rvalues,operatorKind operator) with C-function */
        cx_function(Fast_Parser_binaryExpr_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Parser_binaryExpr(void *args, void *result);
        cx_function(Fast_Parser_binaryExpr_o)->impl = (cx_word)__Fast_Parser_binaryExpr;
        if (cx_define(Fast_Parser_binaryExpr_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::binaryExpr(Fast::Expression lvalues,Fast::Expression rvalues,operatorKind operator)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::callExpr(Fast::Expression function,Fast::Expression arguments) */
    Fast_Parser_callExpr_o = cx_declare(Fast_Parser_o, "callExpr(Fast::Expression function,Fast::Expression arguments)", cx_type(cx_method_o));
    if (!Fast_Parser_callExpr_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::callExpr(Fast::Expression function,Fast::Expression arguments)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::callExpr(Fast::Expression function,Fast::Expression arguments) */
    if (!cx_checkState(Fast_Parser_callExpr_o, CX_DEFINED)) {
        cx_function(Fast_Parser_callExpr_o)->returnType = cx_resolve_ext(Fast_Parser_callExpr_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::Parser::callExpr(Fast::Expression function,Fast::Expression arguments).returnType");
        cx_function(Fast_Parser_callExpr_o)->returnsReference = FALSE;
        Fast_Parser_callExpr_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Parser::callExpr(Fast::Expression function,Fast::Expression arguments) with C-function */
        cx_function(Fast_Parser_callExpr_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Parser_callExpr(void *args, void *result);
        cx_function(Fast_Parser_callExpr_o)->impl = (cx_word)__Fast_Parser_callExpr;
        if (cx_define(Fast_Parser_callExpr_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::callExpr(Fast::Expression function,Fast::Expression arguments)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::castExpr(Fast::Expression lvalue,Fast::Expression rvalue) */
    Fast_Parser_castExpr_o = cx_declare(Fast_Parser_o, "castExpr(Fast::Expression lvalue,Fast::Expression rvalue)", cx_type(cx_method_o));
    if (!Fast_Parser_castExpr_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::castExpr(Fast::Expression lvalue,Fast::Expression rvalue)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::castExpr(Fast::Expression lvalue,Fast::Expression rvalue) */
    if (!cx_checkState(Fast_Parser_castExpr_o, CX_DEFINED)) {
        cx_function(Fast_Parser_castExpr_o)->returnType = cx_resolve_ext(Fast_Parser_castExpr_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::Parser::castExpr(Fast::Expression lvalue,Fast::Expression rvalue).returnType");
        cx_function(Fast_Parser_castExpr_o)->returnsReference = FALSE;
        Fast_Parser_castExpr_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Parser::castExpr(Fast::Expression lvalue,Fast::Expression rvalue) with C-function */
        cx_function(Fast_Parser_castExpr_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Parser_castExpr(void *args, void *result);
        cx_function(Fast_Parser_castExpr_o)->impl = (cx_word)__Fast_Parser_castExpr;
        if (cx_define(Fast_Parser_castExpr_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::castExpr(Fast::Expression lvalue,Fast::Expression rvalue)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::elementExpr(Fast::Expression lvalue,Fast::Expression rvalue) */
    Fast_Parser_elementExpr_o = cx_declare(Fast_Parser_o, "elementExpr(Fast::Expression lvalue,Fast::Expression rvalue)", cx_type(cx_method_o));
    if (!Fast_Parser_elementExpr_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::elementExpr(Fast::Expression lvalue,Fast::Expression rvalue)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::elementExpr(Fast::Expression lvalue,Fast::Expression rvalue) */
    if (!cx_checkState(Fast_Parser_elementExpr_o, CX_DEFINED)) {
        cx_function(Fast_Parser_elementExpr_o)->returnType = cx_resolve_ext(Fast_Parser_elementExpr_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::Parser::elementExpr(Fast::Expression lvalue,Fast::Expression rvalue).returnType");
        cx_function(Fast_Parser_elementExpr_o)->returnsReference = FALSE;
        Fast_Parser_elementExpr_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Parser::elementExpr(Fast::Expression lvalue,Fast::Expression rvalue) with C-function */
        cx_function(Fast_Parser_elementExpr_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Parser_elementExpr(void *args, void *result);
        cx_function(Fast_Parser_elementExpr_o)->impl = (cx_word)__Fast_Parser_elementExpr;
        if (cx_define(Fast_Parser_elementExpr_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::elementExpr(Fast::Expression lvalue,Fast::Expression rvalue)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::foreach(string loopId,Fast::Expression collection) */
    Fast_Parser_foreach_o = cx_declare(Fast_Parser_o, "foreach(string loopId,Fast::Expression collection)", cx_type(cx_method_o));
    if (!Fast_Parser_foreach_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::foreach(string loopId,Fast::Expression collection)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::foreach(string loopId,Fast::Expression collection) */
    if (!cx_checkState(Fast_Parser_foreach_o, CX_DEFINED)) {
        cx_function(Fast_Parser_foreach_o)->returnType = cx_resolve_ext(Fast_Parser_foreach_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::Parser::foreach(string loopId,Fast::Expression collection).returnType");
        cx_function(Fast_Parser_foreach_o)->returnsReference = FALSE;
        Fast_Parser_foreach_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Parser::foreach(string loopId,Fast::Expression collection) with C-function */
        cx_function(Fast_Parser_foreach_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Parser_foreach(void *args, void *result);
        cx_function(Fast_Parser_foreach_o)->impl = (cx_word)__Fast_Parser_foreach;
        if (cx_define(Fast_Parser_foreach_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::foreach(string loopId,Fast::Expression collection)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::initDeclareStaged(Fast::Expression expr) */
    Fast_Parser_initDeclareStaged_o = cx_declare(Fast_Parser_o, "initDeclareStaged(Fast::Expression expr)", cx_type(cx_method_o));
    if (!Fast_Parser_initDeclareStaged_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::initDeclareStaged(Fast::Expression expr)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::initDeclareStaged(Fast::Expression expr) */
    if (!cx_checkState(Fast_Parser_initDeclareStaged_o, CX_DEFINED)) {
        cx_function(Fast_Parser_initDeclareStaged_o)->returnType = cx_resolve_ext(Fast_Parser_initDeclareStaged_o, NULL, "::cortex::lang::void", FALSE, "element ::cortex::Fast::Parser::initDeclareStaged(Fast::Expression expr).returnType");
        cx_function(Fast_Parser_initDeclareStaged_o)->returnsReference = FALSE;
        Fast_Parser_initDeclareStaged_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Parser::initDeclareStaged(Fast::Expression expr) with C-function */
        cx_function(Fast_Parser_initDeclareStaged_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Parser_initDeclareStaged(void *args, void *result);
        cx_function(Fast_Parser_initDeclareStaged_o)->impl = (cx_word)__Fast_Parser_initDeclareStaged;
        if (cx_define(Fast_Parser_initDeclareStaged_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::initDeclareStaged(Fast::Expression expr)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::initKeyValueSet(Fast::Expression expr) */
    Fast_Parser_initKeyValueSet_o = cx_declare(Fast_Parser_o, "initKeyValueSet(Fast::Expression expr)", cx_type(cx_method_o));
    if (!Fast_Parser_initKeyValueSet_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::initKeyValueSet(Fast::Expression expr)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::initKeyValueSet(Fast::Expression expr) */
    if (!cx_checkState(Fast_Parser_initKeyValueSet_o, CX_DEFINED)) {
        cx_function(Fast_Parser_initKeyValueSet_o)->returnType = cx_resolve_ext(Fast_Parser_initKeyValueSet_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::Parser::initKeyValueSet(Fast::Expression expr).returnType");
        cx_function(Fast_Parser_initKeyValueSet_o)->returnsReference = FALSE;
        Fast_Parser_initKeyValueSet_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Parser::initKeyValueSet(Fast::Expression expr) with C-function */
        cx_function(Fast_Parser_initKeyValueSet_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Parser_initKeyValueSet(void *args, void *result);
        cx_function(Fast_Parser_initKeyValueSet_o)->impl = (cx_word)__Fast_Parser_initKeyValueSet;
        if (cx_define(Fast_Parser_initKeyValueSet_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::initKeyValueSet(Fast::Expression expr)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::initPushIdentifier(Expression type) */
    Fast_Parser_initPushIdentifier_o = cx_declare(Fast_Parser_o, "initPushIdentifier(Expression type)", cx_type(cx_method_o));
    if (!Fast_Parser_initPushIdentifier_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::initPushIdentifier(Expression type)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::initPushIdentifier(Expression type) */
    if (!cx_checkState(Fast_Parser_initPushIdentifier_o, CX_DEFINED)) {
        cx_function(Fast_Parser_initPushIdentifier_o)->returnType = cx_resolve_ext(Fast_Parser_initPushIdentifier_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::Parser::initPushIdentifier(Expression type).returnType");
        cx_function(Fast_Parser_initPushIdentifier_o)->returnsReference = FALSE;
        Fast_Parser_initPushIdentifier_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Parser::initPushIdentifier(Expression type) with C-function */
        cx_function(Fast_Parser_initPushIdentifier_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Parser_initPushIdentifier(void *args, void *result);
        cx_function(Fast_Parser_initPushIdentifier_o)->impl = (cx_word)__Fast_Parser_initPushIdentifier;
        if (cx_define(Fast_Parser_initPushIdentifier_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::initPushIdentifier(Expression type)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::initValue(Expression expr) */
    Fast_Parser_initValue_o = cx_declare(Fast_Parser_o, "initValue(Expression expr)", cx_type(cx_method_o));
    if (!Fast_Parser_initValue_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::initValue(Expression expr)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::initValue(Expression expr) */
    if (!cx_checkState(Fast_Parser_initValue_o, CX_DEFINED)) {
        cx_function(Fast_Parser_initValue_o)->returnType = cx_resolve_ext(Fast_Parser_initValue_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::Parser::initValue(Expression expr).returnType");
        cx_function(Fast_Parser_initValue_o)->returnsReference = FALSE;
        Fast_Parser_initValue_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Parser::initValue(Expression expr) with C-function */
        cx_function(Fast_Parser_initValue_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Parser_initValue(void *args, void *result);
        cx_function(Fast_Parser_initValue_o)->impl = (cx_word)__Fast_Parser_initValue;
        if (cx_define(Fast_Parser_initValue_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::initValue(Expression expr)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::memberExpr(Fast::Expression lvalue,Fast::Expression rvalue) */
    Fast_Parser_memberExpr_o = cx_declare(Fast_Parser_o, "memberExpr(Fast::Expression lvalue,Fast::Expression rvalue)", cx_type(cx_method_o));
    if (!Fast_Parser_memberExpr_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::memberExpr(Fast::Expression lvalue,Fast::Expression rvalue)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::memberExpr(Fast::Expression lvalue,Fast::Expression rvalue) */
    if (!cx_checkState(Fast_Parser_memberExpr_o, CX_DEFINED)) {
        cx_function(Fast_Parser_memberExpr_o)->returnType = cx_resolve_ext(Fast_Parser_memberExpr_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::Parser::memberExpr(Fast::Expression lvalue,Fast::Expression rvalue).returnType");
        cx_function(Fast_Parser_memberExpr_o)->returnsReference = FALSE;
        Fast_Parser_memberExpr_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Parser::memberExpr(Fast::Expression lvalue,Fast::Expression rvalue) with C-function */
        cx_function(Fast_Parser_memberExpr_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Parser_memberExpr(void *args, void *result);
        cx_function(Fast_Parser_memberExpr_o)->impl = (cx_word)__Fast_Parser_memberExpr;
        if (cx_define(Fast_Parser_memberExpr_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::memberExpr(Fast::Expression lvalue,Fast::Expression rvalue)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::postfixExpr(Fast::Expression lvalue,operatorKind operator) */
    Fast_Parser_postfixExpr_o = cx_declare(Fast_Parser_o, "postfixExpr(Fast::Expression lvalue,operatorKind operator)", cx_type(cx_method_o));
    if (!Fast_Parser_postfixExpr_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::postfixExpr(Fast::Expression lvalue,operatorKind operator)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::postfixExpr(Fast::Expression lvalue,operatorKind operator) */
    if (!cx_checkState(Fast_Parser_postfixExpr_o, CX_DEFINED)) {
        cx_function(Fast_Parser_postfixExpr_o)->returnType = cx_resolve_ext(Fast_Parser_postfixExpr_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::Parser::postfixExpr(Fast::Expression lvalue,operatorKind operator).returnType");
        cx_function(Fast_Parser_postfixExpr_o)->returnsReference = FALSE;
        Fast_Parser_postfixExpr_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Parser::postfixExpr(Fast::Expression lvalue,operatorKind operator) with C-function */
        cx_function(Fast_Parser_postfixExpr_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Parser_postfixExpr(void *args, void *result);
        cx_function(Fast_Parser_postfixExpr_o)->impl = (cx_word)__Fast_Parser_postfixExpr;
        if (cx_define(Fast_Parser_postfixExpr_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::postfixExpr(Fast::Expression lvalue,operatorKind operator)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::pushComplexType(Fast::Expression lvalue) */
    Fast_Parser_pushComplexType_o = cx_declare(Fast_Parser_o, "pushComplexType(Fast::Expression lvalue)", cx_type(cx_method_o));
    if (!Fast_Parser_pushComplexType_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::pushComplexType(Fast::Expression lvalue)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::pushComplexType(Fast::Expression lvalue) */
    if (!cx_checkState(Fast_Parser_pushComplexType_o, CX_DEFINED)) {
        cx_function(Fast_Parser_pushComplexType_o)->returnType = cx_resolve_ext(Fast_Parser_pushComplexType_o, NULL, "::cortex::lang::void", FALSE, "element ::cortex::Fast::Parser::pushComplexType(Fast::Expression lvalue).returnType");
        cx_function(Fast_Parser_pushComplexType_o)->returnsReference = FALSE;
        Fast_Parser_pushComplexType_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Parser::pushComplexType(Fast::Expression lvalue) with C-function */
        cx_function(Fast_Parser_pushComplexType_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Parser_pushComplexType(void *args, void *result);
        cx_function(Fast_Parser_pushComplexType_o)->impl = (cx_word)__Fast_Parser_pushComplexType;
        if (cx_define(Fast_Parser_pushComplexType_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::pushComplexType(Fast::Expression lvalue)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::pushLvalue(Fast::Expression lvalue,bool isAssignment) */
    Fast_Parser_pushLvalue_o = cx_declare(Fast_Parser_o, "pushLvalue(Fast::Expression lvalue,bool isAssignment)", cx_type(cx_method_o));
    if (!Fast_Parser_pushLvalue_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::pushLvalue(Fast::Expression lvalue,bool isAssignment)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::pushLvalue(Fast::Expression lvalue,bool isAssignment) */
    if (!cx_checkState(Fast_Parser_pushLvalue_o, CX_DEFINED)) {
        cx_function(Fast_Parser_pushLvalue_o)->returnType = cx_resolve_ext(Fast_Parser_pushLvalue_o, NULL, "::cortex::lang::void", FALSE, "element ::cortex::Fast::Parser::pushLvalue(Fast::Expression lvalue,bool isAssignment).returnType");
        cx_function(Fast_Parser_pushLvalue_o)->returnsReference = FALSE;
        Fast_Parser_pushLvalue_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Parser::pushLvalue(Fast::Expression lvalue,bool isAssignment) with C-function */
        cx_function(Fast_Parser_pushLvalue_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Parser_pushLvalue(void *args, void *result);
        cx_function(Fast_Parser_pushLvalue_o)->impl = (cx_word)__Fast_Parser_pushLvalue;
        if (cx_define(Fast_Parser_pushLvalue_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::pushLvalue(Fast::Expression lvalue,bool isAssignment)'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::Parser::singleExpr */
    if (!cx_checkState(Fast_Parser_singleExpr_o, CX_DEFINED)) {
        Fast_Parser_singleExpr_o->type = cx_resolve_ext(Fast_Parser_singleExpr_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::Parser::singleExpr.type");
        Fast_Parser_singleExpr_o->modifiers = 0x3;
        Fast_Parser_singleExpr_o->state = 0x6;
        Fast_Parser_singleExpr_o->weak = FALSE;
        Fast_Parser_singleExpr_o->id = 22;
        if (cx_define(Fast_Parser_singleExpr_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::singleExpr'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::ternaryExpr(Fast::Expression cond,Fast::Expression iftrue,Fast::Expression iffalse) */
    Fast_Parser_ternaryExpr_o = cx_declare(Fast_Parser_o, "ternaryExpr(Fast::Expression cond,Fast::Expression iftrue,Fast::Expression iffalse)", cx_type(cx_method_o));
    if (!Fast_Parser_ternaryExpr_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::ternaryExpr(Fast::Expression cond,Fast::Expression iftrue,Fast::Expression iffalse)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::ternaryExpr(Fast::Expression cond,Fast::Expression iftrue,Fast::Expression iffalse) */
    if (!cx_checkState(Fast_Parser_ternaryExpr_o, CX_DEFINED)) {
        cx_function(Fast_Parser_ternaryExpr_o)->returnType = cx_resolve_ext(Fast_Parser_ternaryExpr_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::Parser::ternaryExpr(Fast::Expression cond,Fast::Expression iftrue,Fast::Expression iffalse).returnType");
        cx_function(Fast_Parser_ternaryExpr_o)->returnsReference = FALSE;
        Fast_Parser_ternaryExpr_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Parser::ternaryExpr(Fast::Expression cond,Fast::Expression iftrue,Fast::Expression iffalse) with C-function */
        cx_function(Fast_Parser_ternaryExpr_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Parser_ternaryExpr(void *args, void *result);
        cx_function(Fast_Parser_ternaryExpr_o)->impl = (cx_word)__Fast_Parser_ternaryExpr;
        if (cx_define(Fast_Parser_ternaryExpr_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::ternaryExpr(Fast::Expression cond,Fast::Expression iftrue,Fast::Expression iffalse)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::unaryExpr(Fast::Expression lvalue,operatorKind operator) */
    Fast_Parser_unaryExpr_o = cx_declare(Fast_Parser_o, "unaryExpr(Fast::Expression lvalue,operatorKind operator)", cx_type(cx_method_o));
    if (!Fast_Parser_unaryExpr_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::unaryExpr(Fast::Expression lvalue,operatorKind operator)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::unaryExpr(Fast::Expression lvalue,operatorKind operator) */
    if (!cx_checkState(Fast_Parser_unaryExpr_o, CX_DEFINED)) {
        cx_function(Fast_Parser_unaryExpr_o)->returnType = cx_resolve_ext(Fast_Parser_unaryExpr_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::Parser::unaryExpr(Fast::Expression lvalue,operatorKind operator).returnType");
        cx_function(Fast_Parser_unaryExpr_o)->returnsReference = FALSE;
        Fast_Parser_unaryExpr_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Parser::unaryExpr(Fast::Expression lvalue,operatorKind operator) with C-function */
        cx_function(Fast_Parser_unaryExpr_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Parser_unaryExpr(void *args, void *result);
        cx_function(Fast_Parser_unaryExpr_o)->impl = (cx_word)__Fast_Parser_unaryExpr;
        if (cx_define(Fast_Parser_unaryExpr_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::unaryExpr(Fast::Expression lvalue,operatorKind operator)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::waitExpr(list{Fast::Expression} exprList,Fast::Expression timeout) */
    Fast_Parser_waitExpr_o = cx_declare(Fast_Parser_o, "waitExpr(list{Fast::Expression} exprList,Fast::Expression timeout)", cx_type(cx_method_o));
    if (!Fast_Parser_waitExpr_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::waitExpr(list{Fast::Expression} exprList,Fast::Expression timeout)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::waitExpr(list{Fast::Expression} exprList,Fast::Expression timeout) */
    if (!cx_checkState(Fast_Parser_waitExpr_o, CX_DEFINED)) {
        cx_function(Fast_Parser_waitExpr_o)->returnType = cx_resolve_ext(Fast_Parser_waitExpr_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::Parser::waitExpr(list{Fast::Expression} exprList,Fast::Expression timeout).returnType");
        cx_function(Fast_Parser_waitExpr_o)->returnsReference = FALSE;
        Fast_Parser_waitExpr_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Parser::waitExpr(list{Fast::Expression} exprList,Fast::Expression timeout) with C-function */
        cx_function(Fast_Parser_waitExpr_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Parser_waitExpr(void *args, void *result);
        cx_function(Fast_Parser_waitExpr_o)->impl = (cx_word)__Fast_Parser_waitExpr;
        if (cx_define(Fast_Parser_waitExpr_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::waitExpr(list{Fast::Expression} exprList,Fast::Expression timeout)'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::ParserNew::attr */
    if (!cx_checkState(Fast_ParserNew_attr_o, CX_DEFINED)) {
        Fast_ParserNew_attr_o->type = cx_resolve_ext(Fast_ParserNew_attr_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::ParserNew::attr.type");
        Fast_ParserNew_attr_o->modifiers = 0x0;
        Fast_ParserNew_attr_o->state = 0x6;
        Fast_ParserNew_attr_o->weak = FALSE;
        Fast_ParserNew_attr_o->id = 3;
        if (cx_define(Fast_ParserNew_attr_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::ParserNew::attr'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::ParserNew::name */
    if (!cx_checkState(Fast_ParserNew_name_o, CX_DEFINED)) {
        Fast_ParserNew_name_o->type = cx_resolve_ext(Fast_ParserNew_name_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::ParserNew::name.type");
        Fast_ParserNew_name_o->modifiers = 0x0;
        Fast_ParserNew_name_o->state = 0x6;
        Fast_ParserNew_name_o->weak = FALSE;
        Fast_ParserNew_name_o->id = 2;
        if (cx_define(Fast_ParserNew_name_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::ParserNew::name'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::ParserNew::parent */
    if (!cx_checkState(Fast_ParserNew_parent_o, CX_DEFINED)) {
        Fast_ParserNew_parent_o->type = cx_resolve_ext(Fast_ParserNew_parent_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::ParserNew::parent.type");
        Fast_ParserNew_parent_o->modifiers = 0x0;
        Fast_ParserNew_parent_o->state = 0x6;
        Fast_ParserNew_parent_o->weak = FALSE;
        Fast_ParserNew_parent_o->id = 1;
        if (cx_define(Fast_ParserNew_parent_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::ParserNew::parent'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::ParserNew */
    if (!cx_checkState(Fast_ParserNew_o, CX_DEFINED)) {
        cx_type(Fast_ParserNew_o)->defaultType = cx_resolve_ext(Fast_ParserNew_o, NULL, "::cortex::lang::member", FALSE, "element ::cortex::Fast::ParserNew.defaultType");
        cx_type(Fast_ParserNew_o)->parentType = NULL;
        cx_type(Fast_ParserNew_o)->parentState = 0x0;
        cx_interface(Fast_ParserNew_o)->base = NULL;
        Fast_ParserNew_o->baseAccess = 0x0;
        if (cx_define(Fast_ParserNew_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::ParserNew'.");
            goto error;
        }
    }

    if (cx_type(Fast_ParserNew_o)->size != sizeof(Fast_ParserNew)) {
        cx_error("Fast_load: calculated size '%d' of type '::cortex::Fast::ParserNew' doesn't match C-type size '%d'", cx_type(Fast_ParserNew_o)->size, sizeof(Fast_ParserNew));
    }

    /* Declare ::cortex::Fast::PostFix::construct() */
    Fast_PostFix_construct_o = cx_declare(Fast_PostFix_o, "construct()", cx_type(cx_method_o));
    if (!Fast_PostFix_construct_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::PostFix::construct()'.");
        goto error;
    }

    /* Define ::cortex::Fast::PostFix::construct() */
    if (!cx_checkState(Fast_PostFix_construct_o, CX_DEFINED)) {
        cx_function(Fast_PostFix_construct_o)->returnType = cx_resolve_ext(Fast_PostFix_construct_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::PostFix::construct().returnType");
        cx_function(Fast_PostFix_construct_o)->returnsReference = FALSE;
        Fast_PostFix_construct_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::PostFix::construct() with C-function */
        cx_function(Fast_PostFix_construct_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_PostFix_construct(void *args, void *result);
        cx_function(Fast_PostFix_construct_o)->impl = (cx_word)__Fast_PostFix_construct;
        if (cx_define(Fast_PostFix_construct_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::PostFix::construct()'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::PostFix::lvalue */
    if (!cx_checkState(Fast_PostFix_lvalue_o, CX_DEFINED)) {
        Fast_PostFix_lvalue_o->type = cx_resolve_ext(Fast_PostFix_lvalue_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::PostFix::lvalue.type");
        Fast_PostFix_lvalue_o->modifiers = 0x0;
        Fast_PostFix_lvalue_o->state = 0x6;
        Fast_PostFix_lvalue_o->weak = FALSE;
        Fast_PostFix_lvalue_o->id = 0;
        if (cx_define(Fast_PostFix_lvalue_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::PostFix::lvalue'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::PostFix::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
    Fast_PostFix_toIc_o = cx_declare(Fast_PostFix_o, "toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)", cx_type(cx_virtual_o));
    if (!Fast_PostFix_toIc_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::PostFix::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)'.");
        goto error;
    }

    /* Define ::cortex::Fast::PostFix::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
    if (!cx_checkState(Fast_PostFix_toIc_o, CX_DEFINED)) {
        cx_function(Fast_PostFix_toIc_o)->returnType = cx_resolve_ext(Fast_PostFix_toIc_o, NULL, "::cortex::lang::alias{\"cx_ic\"}", FALSE, "element ::cortex::Fast::PostFix::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored).returnType");
        cx_function(Fast_PostFix_toIc_o)->returnsReference = FALSE;
        cx_method(Fast_PostFix_toIc_o)->virtual = TRUE;
        
        /* Bind ::cortex::Fast::PostFix::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) with C-function */
        cx_function(Fast_PostFix_toIc_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_PostFix_toIc_v(void *args, void *result);
        cx_function(Fast_PostFix_toIc_o)->impl = (cx_word)__Fast_PostFix_toIc_v;
        if (cx_define(Fast_PostFix_toIc_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::PostFix::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::PostFix */
    if (!cx_checkState(Fast_PostFix_o, CX_DEFINED)) {
        cx_type(Fast_PostFix_o)->defaultType = cx_resolve_ext(Fast_PostFix_o, NULL, "::cortex::lang::member", FALSE, "element ::cortex::Fast::PostFix.defaultType");
        cx_type(Fast_PostFix_o)->parentType = NULL;
        cx_type(Fast_PostFix_o)->parentState = 0x0;
        cx_interface(Fast_PostFix_o)->base = cx_resolve_ext(Fast_PostFix_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::PostFix.base");
        cx_struct(Fast_PostFix_o)->baseAccess = 0x4;
        Fast_PostFix_o->implements.length = 0;
        Fast_PostFix_o->implements.buffer = NULL;
        if (cx_define(Fast_PostFix_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::PostFix'.");
            goto error;
        }
    }

    if (cx_type(Fast_PostFix_o)->size != sizeof(struct Fast_PostFix_s)) {
        cx_error("Fast_load: calculated size '%d' of type '::cortex::Fast::PostFix' doesn't match C-type size '%d'", cx_type(Fast_PostFix_o)->size, sizeof(struct Fast_PostFix_s));
    }

    /* Define ::cortex::Fast::Ternary::condition */
    if (!cx_checkState(Fast_Ternary_condition_o, CX_DEFINED)) {
        Fast_Ternary_condition_o->type = cx_resolve_ext(Fast_Ternary_condition_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::Ternary::condition.type");
        Fast_Ternary_condition_o->modifiers = 0x0;
        Fast_Ternary_condition_o->state = 0x6;
        Fast_Ternary_condition_o->weak = FALSE;
        Fast_Ternary_condition_o->id = 0;
        if (cx_define(Fast_Ternary_condition_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Ternary::condition'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Ternary::construct() */
    Fast_Ternary_construct_o = cx_declare(Fast_Ternary_o, "construct()", cx_type(cx_method_o));
    if (!Fast_Ternary_construct_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Ternary::construct()'.");
        goto error;
    }

    /* Define ::cortex::Fast::Ternary::construct() */
    if (!cx_checkState(Fast_Ternary_construct_o, CX_DEFINED)) {
        cx_function(Fast_Ternary_construct_o)->returnType = cx_resolve_ext(Fast_Ternary_construct_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::Ternary::construct().returnType");
        cx_function(Fast_Ternary_construct_o)->returnsReference = FALSE;
        Fast_Ternary_construct_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Ternary::construct() with C-function */
        cx_function(Fast_Ternary_construct_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Ternary_construct(void *args, void *result);
        cx_function(Fast_Ternary_construct_o)->impl = (cx_word)__Fast_Ternary_construct;
        if (cx_define(Fast_Ternary_construct_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Ternary::construct()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Ternary::hasSideEffects() */
    Fast_Ternary_hasSideEffects_o = cx_declare(Fast_Ternary_o, "hasSideEffects()", cx_type(cx_virtual_o));
    if (!Fast_Ternary_hasSideEffects_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Ternary::hasSideEffects()'.");
        goto error;
    }

    /* Define ::cortex::Fast::Ternary::hasSideEffects() */
    if (!cx_checkState(Fast_Ternary_hasSideEffects_o, CX_DEFINED)) {
        cx_function(Fast_Ternary_hasSideEffects_o)->returnType = cx_resolve_ext(Fast_Ternary_hasSideEffects_o, NULL, "::cortex::lang::bool", FALSE, "element ::cortex::Fast::Ternary::hasSideEffects().returnType");
        cx_function(Fast_Ternary_hasSideEffects_o)->returnsReference = FALSE;
        cx_method(Fast_Ternary_hasSideEffects_o)->virtual = TRUE;
        
        /* Bind ::cortex::Fast::Ternary::hasSideEffects() with C-function */
        cx_function(Fast_Ternary_hasSideEffects_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Ternary_hasSideEffects_v(void *args, void *result);
        cx_function(Fast_Ternary_hasSideEffects_o)->impl = (cx_word)__Fast_Ternary_hasSideEffects_v;
        if (cx_define(Fast_Ternary_hasSideEffects_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Ternary::hasSideEffects()'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::Ternary::ifFalse */
    if (!cx_checkState(Fast_Ternary_ifFalse_o, CX_DEFINED)) {
        Fast_Ternary_ifFalse_o->type = cx_resolve_ext(Fast_Ternary_ifFalse_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::Ternary::ifFalse.type");
        Fast_Ternary_ifFalse_o->modifiers = 0x0;
        Fast_Ternary_ifFalse_o->state = 0x6;
        Fast_Ternary_ifFalse_o->weak = FALSE;
        Fast_Ternary_ifFalse_o->id = 2;
        if (cx_define(Fast_Ternary_ifFalse_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Ternary::ifFalse'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::Ternary::ifFalseExpr */
    if (!cx_checkState(Fast_Ternary_ifFalseExpr_o, CX_DEFINED)) {
        Fast_Ternary_ifFalseExpr_o->type = cx_resolve_ext(Fast_Ternary_ifFalseExpr_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::Ternary::ifFalseExpr.type");
        Fast_Ternary_ifFalseExpr_o->modifiers = 0x3;
        Fast_Ternary_ifFalseExpr_o->state = 0x6;
        Fast_Ternary_ifFalseExpr_o->weak = FALSE;
        Fast_Ternary_ifFalseExpr_o->id = 4;
        if (cx_define(Fast_Ternary_ifFalseExpr_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Ternary::ifFalseExpr'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::Ternary::ifTrue */
    if (!cx_checkState(Fast_Ternary_ifTrue_o, CX_DEFINED)) {
        Fast_Ternary_ifTrue_o->type = cx_resolve_ext(Fast_Ternary_ifTrue_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::Ternary::ifTrue.type");
        Fast_Ternary_ifTrue_o->modifiers = 0x0;
        Fast_Ternary_ifTrue_o->state = 0x6;
        Fast_Ternary_ifTrue_o->weak = FALSE;
        Fast_Ternary_ifTrue_o->id = 1;
        if (cx_define(Fast_Ternary_ifTrue_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Ternary::ifTrue'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::Ternary::ifTrueExpr */
    if (!cx_checkState(Fast_Ternary_ifTrueExpr_o, CX_DEFINED)) {
        Fast_Ternary_ifTrueExpr_o->type = cx_resolve_ext(Fast_Ternary_ifTrueExpr_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::Ternary::ifTrueExpr.type");
        Fast_Ternary_ifTrueExpr_o->modifiers = 0x3;
        Fast_Ternary_ifTrueExpr_o->state = 0x6;
        Fast_Ternary_ifTrueExpr_o->weak = FALSE;
        Fast_Ternary_ifTrueExpr_o->id = 3;
        if (cx_define(Fast_Ternary_ifTrueExpr_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Ternary::ifTrueExpr'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::Ternary::result */
    if (!cx_checkState(Fast_Ternary_result_o, CX_DEFINED)) {
        Fast_Ternary_result_o->type = cx_resolve_ext(Fast_Ternary_result_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::Ternary::result.type");
        Fast_Ternary_result_o->modifiers = 0x0;
        Fast_Ternary_result_o->state = 0x6;
        Fast_Ternary_result_o->weak = FALSE;
        Fast_Ternary_result_o->id = 5;
        if (cx_define(Fast_Ternary_result_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Ternary::result'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Ternary::setOperator(operatorKind kind) */
    Fast_Ternary_setOperator_o = cx_declare(Fast_Ternary_o, "setOperator(operatorKind kind)", cx_type(cx_method_o));
    if (!Fast_Ternary_setOperator_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Ternary::setOperator(operatorKind kind)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Ternary::setOperator(operatorKind kind) */
    if (!cx_checkState(Fast_Ternary_setOperator_o, CX_DEFINED)) {
        cx_function(Fast_Ternary_setOperator_o)->returnType = cx_resolve_ext(Fast_Ternary_setOperator_o, NULL, "::cortex::lang::void", FALSE, "element ::cortex::Fast::Ternary::setOperator(operatorKind kind).returnType");
        cx_function(Fast_Ternary_setOperator_o)->returnsReference = FALSE;
        Fast_Ternary_setOperator_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Ternary::setOperator(operatorKind kind) with C-function */
        cx_function(Fast_Ternary_setOperator_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Ternary_setOperator(void *args, void *result);
        cx_function(Fast_Ternary_setOperator_o)->impl = (cx_word)__Fast_Ternary_setOperator;
        if (cx_define(Fast_Ternary_setOperator_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Ternary::setOperator(operatorKind kind)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Ternary::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
    Fast_Ternary_toIc_o = cx_declare(Fast_Ternary_o, "toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)", cx_type(cx_virtual_o));
    if (!Fast_Ternary_toIc_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Ternary::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Ternary::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
    if (!cx_checkState(Fast_Ternary_toIc_o, CX_DEFINED)) {
        cx_function(Fast_Ternary_toIc_o)->returnType = cx_resolve_ext(Fast_Ternary_toIc_o, NULL, "::cortex::lang::alias{\"cx_ic\"}", FALSE, "element ::cortex::Fast::Ternary::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored).returnType");
        cx_function(Fast_Ternary_toIc_o)->returnsReference = FALSE;
        cx_method(Fast_Ternary_toIc_o)->virtual = TRUE;
        
        /* Bind ::cortex::Fast::Ternary::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) with C-function */
        cx_function(Fast_Ternary_toIc_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Ternary_toIc_v(void *args, void *result);
        cx_function(Fast_Ternary_toIc_o)->impl = (cx_word)__Fast_Ternary_toIc_v;
        if (cx_define(Fast_Ternary_toIc_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Ternary::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Unary::construct() */
    Fast_Unary_construct_o = cx_declare(Fast_Unary_o, "construct()", cx_type(cx_method_o));
    if (!Fast_Unary_construct_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Unary::construct()'.");
        goto error;
    }

    /* Define ::cortex::Fast::Unary::construct() */
    if (!cx_checkState(Fast_Unary_construct_o, CX_DEFINED)) {
        cx_function(Fast_Unary_construct_o)->returnType = cx_resolve_ext(Fast_Unary_construct_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::Unary::construct().returnType");
        cx_function(Fast_Unary_construct_o)->returnsReference = FALSE;
        Fast_Unary_construct_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Unary::construct() with C-function */
        cx_function(Fast_Unary_construct_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Unary_construct(void *args, void *result);
        cx_function(Fast_Unary_construct_o)->impl = (cx_word)__Fast_Unary_construct;
        if (cx_define(Fast_Unary_construct_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Unary::construct()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Unary::hasSideEffects() */
    Fast_Unary_hasSideEffects_o = cx_declare(Fast_Unary_o, "hasSideEffects()", cx_type(cx_virtual_o));
    if (!Fast_Unary_hasSideEffects_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Unary::hasSideEffects()'.");
        goto error;
    }

    /* Define ::cortex::Fast::Unary::hasSideEffects() */
    if (!cx_checkState(Fast_Unary_hasSideEffects_o, CX_DEFINED)) {
        cx_function(Fast_Unary_hasSideEffects_o)->returnType = cx_resolve_ext(Fast_Unary_hasSideEffects_o, NULL, "::cortex::lang::bool", FALSE, "element ::cortex::Fast::Unary::hasSideEffects().returnType");
        cx_function(Fast_Unary_hasSideEffects_o)->returnsReference = FALSE;
        cx_method(Fast_Unary_hasSideEffects_o)->virtual = TRUE;
        
        /* Bind ::cortex::Fast::Unary::hasSideEffects() with C-function */
        cx_function(Fast_Unary_hasSideEffects_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Unary_hasSideEffects_v(void *args, void *result);
        cx_function(Fast_Unary_hasSideEffects_o)->impl = (cx_word)__Fast_Unary_hasSideEffects_v;
        if (cx_define(Fast_Unary_hasSideEffects_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Unary::hasSideEffects()'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::Unary::lvalue */
    if (!cx_checkState(Fast_Unary_lvalue_o, CX_DEFINED)) {
        Fast_Unary_lvalue_o->type = cx_resolve_ext(Fast_Unary_lvalue_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::Unary::lvalue.type");
        Fast_Unary_lvalue_o->modifiers = 0x0;
        Fast_Unary_lvalue_o->state = 0x6;
        Fast_Unary_lvalue_o->weak = FALSE;
        Fast_Unary_lvalue_o->id = 0;
        if (cx_define(Fast_Unary_lvalue_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Unary::lvalue'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Unary::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
    Fast_Unary_toIc_o = cx_declare(Fast_Unary_o, "toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)", cx_type(cx_virtual_o));
    if (!Fast_Unary_toIc_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Unary::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Unary::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
    if (!cx_checkState(Fast_Unary_toIc_o, CX_DEFINED)) {
        cx_function(Fast_Unary_toIc_o)->returnType = cx_resolve_ext(Fast_Unary_toIc_o, NULL, "::cortex::lang::alias{\"cx_ic\"}", FALSE, "element ::cortex::Fast::Unary::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored).returnType");
        cx_function(Fast_Unary_toIc_o)->returnsReference = FALSE;
        cx_method(Fast_Unary_toIc_o)->virtual = TRUE;
        
        /* Bind ::cortex::Fast::Unary::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) with C-function */
        cx_function(Fast_Unary_toIc_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Unary_toIc_v(void *args, void *result);
        cx_function(Fast_Unary_toIc_o)->impl = (cx_word)__Fast_Unary_toIc_v;
        if (cx_define(Fast_Unary_toIc_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Unary::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::Unary */
    if (!cx_checkState(Fast_Unary_o, CX_DEFINED)) {
        cx_type(Fast_Unary_o)->defaultType = cx_resolve_ext(Fast_Unary_o, NULL, "::cortex::lang::member", FALSE, "element ::cortex::Fast::Unary.defaultType");
        cx_type(Fast_Unary_o)->parentType = NULL;
        cx_type(Fast_Unary_o)->parentState = 0x0;
        cx_interface(Fast_Unary_o)->base = cx_resolve_ext(Fast_Unary_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::Unary.base");
        cx_struct(Fast_Unary_o)->baseAccess = 0x4;
        Fast_Unary_o->implements.length = 0;
        Fast_Unary_o->implements.buffer = NULL;
        if (cx_define(Fast_Unary_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Unary'.");
            goto error;
        }
    }

    if (cx_type(Fast_Unary_o)->size != sizeof(struct Fast_Unary_s)) {
        cx_error("Fast_load: calculated size '%d' of type '::cortex::Fast::Unary' doesn't match C-type size '%d'", cx_type(Fast_Unary_o)->size, sizeof(struct Fast_Unary_s));
    }

    /* Define ::cortex::Fast::Update::from */
    if (!cx_checkState(Fast_Update_from_o, CX_DEFINED)) {
        Fast_Update_from_o->type = cx_resolve_ext(Fast_Update_from_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::Update::from.type");
        Fast_Update_from_o->modifiers = 0x0;
        Fast_Update_from_o->state = 0x6;
        Fast_Update_from_o->weak = FALSE;
        Fast_Update_from_o->id = 2;
        if (cx_define(Fast_Update_from_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Update::from'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Variable::construct() */
    Fast_Variable_construct_o = cx_declare(Fast_Variable_o, "construct()", cx_type(cx_method_o));
    if (!Fast_Variable_construct_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Variable::construct()'.");
        goto error;
    }

    /* Define ::cortex::Fast::Variable::construct() */
    if (!cx_checkState(Fast_Variable_construct_o, CX_DEFINED)) {
        cx_function(Fast_Variable_construct_o)->returnType = cx_resolve_ext(Fast_Variable_construct_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::Variable::construct().returnType");
        cx_function(Fast_Variable_construct_o)->returnsReference = FALSE;
        Fast_Variable_construct_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Variable::construct() with C-function */
        cx_function(Fast_Variable_construct_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Variable_construct(void *args, void *result);
        cx_function(Fast_Variable_construct_o)->impl = (cx_word)__Fast_Variable_construct;
        if (cx_define(Fast_Variable_construct_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Variable::construct()'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::Variable */
    if (!cx_checkState(Fast_Variable_o, CX_DEFINED)) {
        cx_type(Fast_Variable_o)->defaultType = cx_resolve_ext(Fast_Variable_o, NULL, "::cortex::lang::member", FALSE, "element ::cortex::Fast::Variable.defaultType");
        cx_type(Fast_Variable_o)->parentType = NULL;
        cx_type(Fast_Variable_o)->parentState = 0x0;
        cx_interface(Fast_Variable_o)->base = cx_resolve_ext(Fast_Variable_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::Variable.base");
        cx_struct(Fast_Variable_o)->baseAccess = 0x4;
        Fast_Variable_o->implements.length = 0;
        Fast_Variable_o->implements.buffer = NULL;
        if (cx_define(Fast_Variable_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Variable'.");
            goto error;
        }
    }

    if (cx_type(Fast_Variable_o)->size != sizeof(struct Fast_Variable_s)) {
        cx_error("Fast_load: calculated size '%d' of type '::cortex::Fast::Variable' doesn't match C-type size '%d'", cx_type(Fast_Variable_o)->size, sizeof(struct Fast_Variable_s));
    }

    /* Declare ::cortex::Fast::Block::declare(string id,Fast::Variable type,bool isParameter,bool isReference) */
    Fast_Block_declare_o = cx_declare(Fast_Block_o, "declare(string id,Fast::Variable type,bool isParameter,bool isReference)", cx_type(cx_method_o));
    if (!Fast_Block_declare_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Block::declare(string id,Fast::Variable type,bool isParameter,bool isReference)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Block::declare(string id,Fast::Variable type,bool isParameter,bool isReference) */
    if (!cx_checkState(Fast_Block_declare_o, CX_DEFINED)) {
        cx_function(Fast_Block_declare_o)->returnType = cx_resolve_ext(Fast_Block_declare_o, NULL, "::cortex::Fast::Local", FALSE, "element ::cortex::Fast::Block::declare(string id,Fast::Variable type,bool isParameter,bool isReference).returnType");
        cx_function(Fast_Block_declare_o)->returnsReference = FALSE;
        Fast_Block_declare_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Block::declare(string id,Fast::Variable type,bool isParameter,bool isReference) with C-function */
        cx_function(Fast_Block_declare_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Block_declare(void *args, void *result);
        cx_function(Fast_Block_declare_o)->impl = (cx_word)__Fast_Block_declare;
        if (cx_define(Fast_Block_declare_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Block::declare(string id,Fast::Variable type,bool isParameter,bool isReference)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Block::declareTemplate(string id,Fast::Variable type,bool isParameter,bool isReference) */
    Fast_Block_declareTemplate_o = cx_declare(Fast_Block_o, "declareTemplate(string id,Fast::Variable type,bool isParameter,bool isReference)", cx_type(cx_method_o));
    if (!Fast_Block_declareTemplate_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Block::declareTemplate(string id,Fast::Variable type,bool isParameter,bool isReference)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Block::declareTemplate(string id,Fast::Variable type,bool isParameter,bool isReference) */
    if (!cx_checkState(Fast_Block_declareTemplate_o, CX_DEFINED)) {
        cx_function(Fast_Block_declareTemplate_o)->returnType = cx_resolve_ext(Fast_Block_declareTemplate_o, NULL, "::cortex::Fast::Template", FALSE, "element ::cortex::Fast::Block::declareTemplate(string id,Fast::Variable type,bool isParameter,bool isReference).returnType");
        cx_function(Fast_Block_declareTemplate_o)->returnsReference = FALSE;
        Fast_Block_declareTemplate_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Block::declareTemplate(string id,Fast::Variable type,bool isParameter,bool isReference) with C-function */
        cx_function(Fast_Block_declareTemplate_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Block_declareTemplate(void *args, void *result);
        cx_function(Fast_Block_declareTemplate_o)->impl = (cx_word)__Fast_Block_declareTemplate;
        if (cx_define(Fast_Block_declareTemplate_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Block::declareTemplate(string id,Fast::Variable type,bool isParameter,bool isReference)'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::Block */
    if (!cx_checkState(Fast_Block_o, CX_DEFINED)) {
        cx_type(Fast_Block_o)->defaultType = cx_resolve_ext(Fast_Block_o, NULL, "::cortex::lang::member", FALSE, "element ::cortex::Fast::Block.defaultType");
        cx_type(Fast_Block_o)->parentType = NULL;
        cx_type(Fast_Block_o)->parentState = 0x0;
        cx_interface(Fast_Block_o)->base = cx_resolve_ext(Fast_Block_o, NULL, "::cortex::Fast::Node", FALSE, "element ::cortex::Fast::Block.base");
        cx_struct(Fast_Block_o)->baseAccess = 0x4;
        Fast_Block_o->implements.length = 0;
        Fast_Block_o->implements.buffer = NULL;
        if (cx_define(Fast_Block_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Block'.");
            goto error;
        }
    }

    if (cx_type(Fast_Block_o)->size != sizeof(struct Fast_Block_s)) {
        cx_error("Fast_load: calculated size '%d' of type '::cortex::Fast::Block' doesn't match C-type size '%d'", cx_type(Fast_Block_o)->size, sizeof(struct Fast_Block_s));
    }

    /* Define ::cortex::Fast::Binding::impl */
    if (!cx_checkState(Fast_Binding_impl_o, CX_DEFINED)) {
        Fast_Binding_impl_o->type = cx_resolve_ext(Fast_Binding_impl_o, NULL, "::cortex::Fast::Block", FALSE, "element ::cortex::Fast::Binding::impl.type");
        Fast_Binding_impl_o->modifiers = 0x0;
        Fast_Binding_impl_o->state = 0x6;
        Fast_Binding_impl_o->weak = FALSE;
        Fast_Binding_impl_o->id = 1;
        if (cx_define(Fast_Binding_impl_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Binding::impl'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::Binding */
    if (!cx_checkState(Fast_Binding_o, CX_DEFINED)) {
        cx_type(Fast_Binding_o)->defaultType = cx_resolve_ext(Fast_Binding_o, NULL, "::cortex::lang::member", FALSE, "element ::cortex::Fast::Binding.defaultType");
        cx_type(Fast_Binding_o)->parentType = NULL;
        cx_type(Fast_Binding_o)->parentState = 0x0;
        cx_interface(Fast_Binding_o)->base = NULL;
        Fast_Binding_o->baseAccess = 0x0;
        if (cx_define(Fast_Binding_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Binding'.");
            goto error;
        }
    }

    if (cx_type(Fast_Binding_o)->size != sizeof(Fast_Binding)) {
        cx_error("Fast_load: calculated size '%d' of type '::cortex::Fast::Binding' doesn't match C-type size '%d'", cx_type(Fast_Binding_o)->size, sizeof(Fast_Binding));
    }

    /* Define ::cortex::Fast::CallBuilder::block */
    if (!cx_checkState(Fast_CallBuilder_block_o, CX_DEFINED)) {
        Fast_CallBuilder_block_o->type = cx_resolve_ext(Fast_CallBuilder_block_o, NULL, "::cortex::Fast::Block", FALSE, "element ::cortex::Fast::CallBuilder::block.type");
        Fast_CallBuilder_block_o->modifiers = 0x0;
        Fast_CallBuilder_block_o->state = 0x6;
        Fast_CallBuilder_block_o->weak = FALSE;
        Fast_CallBuilder_block_o->id = 4;
        if (cx_define(Fast_CallBuilder_block_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::CallBuilder::block'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::CallBuilder */
    if (!cx_checkState(Fast_CallBuilder_o, CX_DEFINED)) {
        cx_type(Fast_CallBuilder_o)->defaultType = cx_resolve_ext(Fast_CallBuilder_o, NULL, "::cortex::lang::member", FALSE, "element ::cortex::Fast::CallBuilder.defaultType");
        cx_type(Fast_CallBuilder_o)->parentType = NULL;
        cx_type(Fast_CallBuilder_o)->parentState = 0x0;
        cx_interface(Fast_CallBuilder_o)->base = NULL;
        Fast_CallBuilder_o->baseAccess = 0x0;
        if (cx_define(Fast_CallBuilder_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::CallBuilder'.");
            goto error;
        }
    }

    if (cx_type(Fast_CallBuilder_o)->size != sizeof(Fast_CallBuilder)) {
        cx_error("Fast_load: calculated size '%d' of type '::cortex::Fast::CallBuilder' doesn't match C-type size '%d'", cx_type(Fast_CallBuilder_o)->size, sizeof(Fast_CallBuilder));
    }

    /* Define ::cortex::Fast::If::trueBranch */
    if (!cx_checkState(Fast_If_trueBranch_o, CX_DEFINED)) {
        Fast_If_trueBranch_o->type = cx_resolve_ext(Fast_If_trueBranch_o, NULL, "::cortex::Fast::Block", FALSE, "element ::cortex::Fast::If::trueBranch.type");
        Fast_If_trueBranch_o->modifiers = 0x0;
        Fast_If_trueBranch_o->state = 0x6;
        Fast_If_trueBranch_o->weak = FALSE;
        Fast_If_trueBranch_o->id = 1;
        if (cx_define(Fast_If_trueBranch_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::If::trueBranch'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::If */
    if (!cx_checkState(Fast_If_o, CX_DEFINED)) {
        cx_type(Fast_If_o)->defaultType = cx_resolve_ext(Fast_If_o, NULL, "::cortex::lang::member", FALSE, "element ::cortex::Fast::If.defaultType");
        cx_type(Fast_If_o)->parentType = NULL;
        cx_type(Fast_If_o)->parentState = 0x0;
        cx_interface(Fast_If_o)->base = cx_resolve_ext(Fast_If_o, NULL, "::cortex::Fast::Node", FALSE, "element ::cortex::Fast::If.base");
        cx_struct(Fast_If_o)->baseAccess = 0x4;
        Fast_If_o->implements.length = 0;
        Fast_If_o->implements.buffer = NULL;
        if (cx_define(Fast_If_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::If'.");
            goto error;
        }
    }

    if (cx_type(Fast_If_o)->size != sizeof(struct Fast_If_s)) {
        cx_error("Fast_load: calculated size '%d' of type '::cortex::Fast::If' doesn't match C-type size '%d'", cx_type(Fast_If_o)->size, sizeof(struct Fast_If_s));
    }

    /* Declare ::cortex::Fast::Parser::ifStatement(Fast::Expression condition,Fast::Block trueBranch,Fast::If falseBranch) */
    Fast_Parser_ifStatement_o = cx_declare(Fast_Parser_o, "ifStatement(Fast::Expression condition,Fast::Block trueBranch,Fast::If falseBranch)", cx_type(cx_method_o));
    if (!Fast_Parser_ifStatement_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::ifStatement(Fast::Expression condition,Fast::Block trueBranch,Fast::If falseBranch)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::ifStatement(Fast::Expression condition,Fast::Block trueBranch,Fast::If falseBranch) */
    if (!cx_checkState(Fast_Parser_ifStatement_o, CX_DEFINED)) {
        cx_function(Fast_Parser_ifStatement_o)->returnType = cx_resolve_ext(Fast_Parser_ifStatement_o, NULL, "::cortex::Fast::Node", FALSE, "element ::cortex::Fast::Parser::ifStatement(Fast::Expression condition,Fast::Block trueBranch,Fast::If falseBranch).returnType");
        cx_function(Fast_Parser_ifStatement_o)->returnsReference = FALSE;
        Fast_Parser_ifStatement_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Parser::ifStatement(Fast::Expression condition,Fast::Block trueBranch,Fast::If falseBranch) with C-function */
        cx_function(Fast_Parser_ifStatement_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Parser_ifStatement(void *args, void *result);
        cx_function(Fast_Parser_ifStatement_o)->impl = (cx_word)__Fast_Parser_ifStatement;
        if (cx_define(Fast_Parser_ifStatement_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::ifStatement(Fast::Expression condition,Fast::Block trueBranch,Fast::If falseBranch)'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::Ternary::ifstmt */
    if (!cx_checkState(Fast_Ternary_ifstmt_o, CX_DEFINED)) {
        Fast_Ternary_ifstmt_o->type = cx_resolve_ext(Fast_Ternary_ifstmt_o, NULL, "::cortex::Fast::If", FALSE, "element ::cortex::Fast::Ternary::ifstmt.type");
        Fast_Ternary_ifstmt_o->modifiers = 0x3;
        Fast_Ternary_ifstmt_o->state = 0x6;
        Fast_Ternary_ifstmt_o->weak = FALSE;
        Fast_Ternary_ifstmt_o->id = 6;
        if (cx_define(Fast_Ternary_ifstmt_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Ternary::ifstmt'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::Ternary */
    if (!cx_checkState(Fast_Ternary_o, CX_DEFINED)) {
        cx_type(Fast_Ternary_o)->defaultType = cx_resolve_ext(Fast_Ternary_o, NULL, "::cortex::lang::member", FALSE, "element ::cortex::Fast::Ternary.defaultType");
        cx_type(Fast_Ternary_o)->parentType = NULL;
        cx_type(Fast_Ternary_o)->parentState = 0x0;
        cx_interface(Fast_Ternary_o)->base = cx_resolve_ext(Fast_Ternary_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::Ternary.base");
        cx_struct(Fast_Ternary_o)->baseAccess = 0x4;
        Fast_Ternary_o->implements.length = 0;
        Fast_Ternary_o->implements.buffer = NULL;
        if (cx_define(Fast_Ternary_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Ternary'.");
            goto error;
        }
    }

    if (cx_type(Fast_Ternary_o)->size != sizeof(struct Fast_Ternary_s)) {
        cx_error("Fast_load: calculated size '%d' of type '::cortex::Fast::Ternary' doesn't match C-type size '%d'", cx_type(Fast_Ternary_o)->size, sizeof(struct Fast_Ternary_s));
    }

    /* Declare ::cortex::Fast::Parser::bind(Fast::Variable function,Fast::Block block) */
    Fast_Parser_bind_o = cx_declare(Fast_Parser_o, "bind(Fast::Variable function,Fast::Block block)", cx_type(cx_method_o));
    if (!Fast_Parser_bind_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::bind(Fast::Variable function,Fast::Block block)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::bind(Fast::Variable function,Fast::Block block) */
    if (!cx_checkState(Fast_Parser_bind_o, CX_DEFINED)) {
        cx_function(Fast_Parser_bind_o)->returnType = cx_resolve_ext(Fast_Parser_bind_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::Parser::bind(Fast::Variable function,Fast::Block block).returnType");
        cx_function(Fast_Parser_bind_o)->returnsReference = FALSE;
        Fast_Parser_bind_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Parser::bind(Fast::Variable function,Fast::Block block) with C-function */
        cx_function(Fast_Parser_bind_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Parser_bind(void *args, void *result);
        cx_function(Fast_Parser_bind_o)->impl = (cx_word)__Fast_Parser_bind;
        if (cx_define(Fast_Parser_bind_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::bind(Fast::Variable function,Fast::Block block)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::bindOneliner(Fast::Variable function,Fast::Block block,Fast::Expression expr) */
    Fast_Parser_bindOneliner_o = cx_declare(Fast_Parser_o, "bindOneliner(Fast::Variable function,Fast::Block block,Fast::Expression expr)", cx_type(cx_method_o));
    if (!Fast_Parser_bindOneliner_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::bindOneliner(Fast::Variable function,Fast::Block block,Fast::Expression expr)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::bindOneliner(Fast::Variable function,Fast::Block block,Fast::Expression expr) */
    if (!cx_checkState(Fast_Parser_bindOneliner_o, CX_DEFINED)) {
        cx_function(Fast_Parser_bindOneliner_o)->returnType = cx_resolve_ext(Fast_Parser_bindOneliner_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::Parser::bindOneliner(Fast::Variable function,Fast::Block block,Fast::Expression expr).returnType");
        cx_function(Fast_Parser_bindOneliner_o)->returnsReference = FALSE;
        Fast_Parser_bindOneliner_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Parser::bindOneliner(Fast::Variable function,Fast::Block block,Fast::Expression expr) with C-function */
        cx_function(Fast_Parser_bindOneliner_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Parser_bindOneliner(void *args, void *result);
        cx_function(Fast_Parser_bindOneliner_o)->impl = (cx_word)__Fast_Parser_bindOneliner;
        if (cx_define(Fast_Parser_bindOneliner_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::bindOneliner(Fast::Variable function,Fast::Block block,Fast::Expression expr)'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::Parser::block */
    if (!cx_checkState(Fast_Parser_block_o, CX_DEFINED)) {
        Fast_Parser_block_o->type = cx_resolve_ext(Fast_Parser_block_o, NULL, "::cortex::Fast::Block", FALSE, "element ::cortex::Fast::Parser::block.type");
        Fast_Parser_block_o->modifiers = 0x4;
        Fast_Parser_block_o->state = 0x6;
        Fast_Parser_block_o->weak = FALSE;
        Fast_Parser_block_o->id = 7;
        if (cx_define(Fast_Parser_block_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::block'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::parseExpression(string expr,Fast::Block block,Fast::Variable scope,uint32 line,uint32 column) */
    Fast_Parser_parseExpression_o = cx_declare(Fast_Parser_o, "parseExpression(string expr,Fast::Block block,Fast::Variable scope,uint32 line,uint32 column)", cx_type(cx_method_o));
    if (!Fast_Parser_parseExpression_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::parseExpression(string expr,Fast::Block block,Fast::Variable scope,uint32 line,uint32 column)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::parseExpression(string expr,Fast::Block block,Fast::Variable scope,uint32 line,uint32 column) */
    if (!cx_checkState(Fast_Parser_parseExpression_o, CX_DEFINED)) {
        cx_function(Fast_Parser_parseExpression_o)->returnType = cx_resolve_ext(Fast_Parser_parseExpression_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::Parser::parseExpression(string expr,Fast::Block block,Fast::Variable scope,uint32 line,uint32 column).returnType");
        cx_function(Fast_Parser_parseExpression_o)->returnsReference = FALSE;
        Fast_Parser_parseExpression_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Parser::parseExpression(string expr,Fast::Block block,Fast::Variable scope,uint32 line,uint32 column) with C-function */
        cx_function(Fast_Parser_parseExpression_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Parser_parseExpression(void *args, void *result);
        cx_function(Fast_Parser_parseExpression_o)->impl = (cx_word)__Fast_Parser_parseExpression;
        if (cx_define(Fast_Parser_parseExpression_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::parseExpression(string expr,Fast::Block block,Fast::Variable scope,uint32 line,uint32 column)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::updateStatement(Fast::Expression expr,Fast::Block block) */
    Fast_Parser_updateStatement_o = cx_declare(Fast_Parser_o, "updateStatement(Fast::Expression expr,Fast::Block block)", cx_type(cx_method_o));
    if (!Fast_Parser_updateStatement_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::updateStatement(Fast::Expression expr,Fast::Block block)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::updateStatement(Fast::Expression expr,Fast::Block block) */
    if (!cx_checkState(Fast_Parser_updateStatement_o, CX_DEFINED)) {
        cx_function(Fast_Parser_updateStatement_o)->returnType = cx_resolve_ext(Fast_Parser_updateStatement_o, NULL, "::cortex::Fast::Node", FALSE, "element ::cortex::Fast::Parser::updateStatement(Fast::Expression expr,Fast::Block block).returnType");
        cx_function(Fast_Parser_updateStatement_o)->returnsReference = FALSE;
        Fast_Parser_updateStatement_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Parser::updateStatement(Fast::Expression expr,Fast::Block block) with C-function */
        cx_function(Fast_Parser_updateStatement_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Parser_updateStatement(void *args, void *result);
        cx_function(Fast_Parser_updateStatement_o)->impl = (cx_word)__Fast_Parser_updateStatement;
        if (cx_define(Fast_Parser_updateStatement_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::updateStatement(Fast::Expression expr,Fast::Block block)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::whileStatement(Fast::Expression condition,Fast::Block trueBranch,bool isUntil) */
    Fast_Parser_whileStatement_o = cx_declare(Fast_Parser_o, "whileStatement(Fast::Expression condition,Fast::Block trueBranch,bool isUntil)", cx_type(cx_method_o));
    if (!Fast_Parser_whileStatement_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::whileStatement(Fast::Expression condition,Fast::Block trueBranch,bool isUntil)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::whileStatement(Fast::Expression condition,Fast::Block trueBranch,bool isUntil) */
    if (!cx_checkState(Fast_Parser_whileStatement_o, CX_DEFINED)) {
        cx_function(Fast_Parser_whileStatement_o)->returnType = cx_resolve_ext(Fast_Parser_whileStatement_o, NULL, "::cortex::Fast::Node", FALSE, "element ::cortex::Fast::Parser::whileStatement(Fast::Expression condition,Fast::Block trueBranch,bool isUntil).returnType");
        cx_function(Fast_Parser_whileStatement_o)->returnsReference = FALSE;
        Fast_Parser_whileStatement_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Parser::whileStatement(Fast::Expression condition,Fast::Block trueBranch,bool isUntil) with C-function */
        cx_function(Fast_Parser_whileStatement_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Parser_whileStatement(void *args, void *result);
        cx_function(Fast_Parser_whileStatement_o)->impl = (cx_word)__Fast_Parser_whileStatement;
        if (cx_define(Fast_Parser_whileStatement_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::whileStatement(Fast::Expression condition,Fast::Block trueBranch,bool isUntil)'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::String::block */
    if (!cx_checkState(Fast_String_block_o, CX_DEFINED)) {
        Fast_String_block_o->type = cx_resolve_ext(Fast_String_block_o, NULL, "::cortex::Fast::Block", FALSE, "element ::cortex::Fast::String::block.type");
        Fast_String_block_o->modifiers = 0x4;
        Fast_String_block_o->state = 0x6;
        Fast_String_block_o->weak = FALSE;
        Fast_String_block_o->id = 2;
        if (cx_define(Fast_String_block_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::String::block'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::Update::block */
    if (!cx_checkState(Fast_Update_block_o, CX_DEFINED)) {
        Fast_Update_block_o->type = cx_resolve_ext(Fast_Update_block_o, NULL, "::cortex::Fast::Block", FALSE, "element ::cortex::Fast::Update::block.type");
        Fast_Update_block_o->modifiers = 0x0;
        Fast_Update_block_o->state = 0x6;
        Fast_Update_block_o->weak = FALSE;
        Fast_Update_block_o->id = 1;
        if (cx_define(Fast_Update_block_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Update::block'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::Update */
    if (!cx_checkState(Fast_Update_o, CX_DEFINED)) {
        cx_type(Fast_Update_o)->defaultType = cx_resolve_ext(Fast_Update_o, NULL, "::cortex::lang::member", FALSE, "element ::cortex::Fast::Update.defaultType");
        cx_type(Fast_Update_o)->parentType = NULL;
        cx_type(Fast_Update_o)->parentState = 0x0;
        cx_interface(Fast_Update_o)->base = cx_resolve_ext(Fast_Update_o, NULL, "::cortex::Fast::Node", FALSE, "element ::cortex::Fast::Update.base");
        cx_struct(Fast_Update_o)->baseAccess = 0x4;
        Fast_Update_o->implements.length = 0;
        Fast_Update_o->implements.buffer = NULL;
        if (cx_define(Fast_Update_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Update'.");
            goto error;
        }
    }

    if (cx_type(Fast_Update_o)->size != sizeof(struct Fast_Update_s)) {
        cx_error("Fast_load: calculated size '%d' of type '::cortex::Fast::Update' doesn't match C-type size '%d'", cx_type(Fast_Update_o)->size, sizeof(struct Fast_Update_s));
    }

    /* Define ::cortex::Fast::While::trueBranch */
    if (!cx_checkState(Fast_While_trueBranch_o, CX_DEFINED)) {
        Fast_While_trueBranch_o->type = cx_resolve_ext(Fast_While_trueBranch_o, NULL, "::cortex::Fast::Block", FALSE, "element ::cortex::Fast::While::trueBranch.type");
        Fast_While_trueBranch_o->modifiers = 0x0;
        Fast_While_trueBranch_o->state = 0x6;
        Fast_While_trueBranch_o->weak = FALSE;
        Fast_While_trueBranch_o->id = 1;
        if (cx_define(Fast_While_trueBranch_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::While::trueBranch'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Local::construct() */
    Fast_Local_construct_o = cx_declare(Fast_Local_o, "construct()", cx_type(cx_method_o));
    if (!Fast_Local_construct_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Local::construct()'.");
        goto error;
    }

    /* Define ::cortex::Fast::Local::construct() */
    if (!cx_checkState(Fast_Local_construct_o, CX_DEFINED)) {
        cx_function(Fast_Local_construct_o)->returnType = cx_resolve_ext(Fast_Local_construct_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::Local::construct().returnType");
        cx_function(Fast_Local_construct_o)->returnsReference = FALSE;
        Fast_Local_construct_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Local::construct() with C-function */
        cx_function(Fast_Local_construct_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Local_construct(void *args, void *result);
        cx_function(Fast_Local_construct_o)->impl = (cx_word)__Fast_Local_construct;
        if (cx_define(Fast_Local_construct_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Local::construct()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Local::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
    Fast_Local_toIc_o = cx_declare(Fast_Local_o, "toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)", cx_type(cx_virtual_o));
    if (!Fast_Local_toIc_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Local::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Local::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
    if (!cx_checkState(Fast_Local_toIc_o, CX_DEFINED)) {
        cx_function(Fast_Local_toIc_o)->returnType = cx_resolve_ext(Fast_Local_toIc_o, NULL, "::cortex::lang::alias{\"cx_ic\"}", FALSE, "element ::cortex::Fast::Local::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored).returnType");
        cx_function(Fast_Local_toIc_o)->returnsReference = FALSE;
        cx_method(Fast_Local_toIc_o)->virtual = TRUE;
        
        /* Bind ::cortex::Fast::Local::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) with C-function */
        cx_function(Fast_Local_toIc_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Local_toIc_v(void *args, void *result);
        cx_function(Fast_Local_toIc_o)->impl = (cx_word)__Fast_Local_toIc_v;
        if (cx_define(Fast_Local_toIc_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Local::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::Local::type */
    if (!cx_checkState(Fast_Local_type_o, CX_DEFINED)) {
        Fast_Local_type_o->type = cx_resolve_ext(Fast_Local_type_o, NULL, "::cortex::Fast::Variable", FALSE, "element ::cortex::Fast::Local::type.type");
        Fast_Local_type_o->modifiers = 0x0;
        Fast_Local_type_o->state = 0x6;
        Fast_Local_type_o->weak = FALSE;
        Fast_Local_type_o->id = 1;
        if (cx_define(Fast_Local_type_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Local::type'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::Local */
    if (!cx_checkState(Fast_Local_o, CX_DEFINED)) {
        cx_type(Fast_Local_o)->defaultType = cx_resolve_ext(Fast_Local_o, NULL, "::cortex::lang::member", FALSE, "element ::cortex::Fast::Local.defaultType");
        cx_type(Fast_Local_o)->parentType = NULL;
        cx_type(Fast_Local_o)->parentState = 0x0;
        cx_interface(Fast_Local_o)->base = cx_resolve_ext(Fast_Local_o, NULL, "::cortex::Fast::Variable", FALSE, "element ::cortex::Fast::Local.base");
        cx_struct(Fast_Local_o)->baseAccess = 0x4;
        Fast_Local_o->implements.length = 0;
        Fast_Local_o->implements.buffer = NULL;
        if (cx_define(Fast_Local_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Local'.");
            goto error;
        }
    }

    if (cx_type(Fast_Local_o)->size != sizeof(struct Fast_Local_s)) {
        cx_error("Fast_load: calculated size '%d' of type '::cortex::Fast::Local' doesn't match C-type size '%d'", cx_type(Fast_Local_o)->size, sizeof(struct Fast_Local_s));
    }

    /* Declare ::cortex::Fast::Template::construct() */
    Fast_Template_construct_o = cx_declare(Fast_Template_o, "construct()", cx_type(cx_method_o));
    if (!Fast_Template_construct_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Template::construct()'.");
        goto error;
    }

    /* Define ::cortex::Fast::Template::construct() */
    if (!cx_checkState(Fast_Template_construct_o, CX_DEFINED)) {
        cx_function(Fast_Template_construct_o)->returnType = cx_resolve_ext(Fast_Template_construct_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::Template::construct().returnType");
        cx_function(Fast_Template_construct_o)->returnsReference = FALSE;
        Fast_Template_construct_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Template::construct() with C-function */
        cx_function(Fast_Template_construct_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Template_construct(void *args, void *result);
        cx_function(Fast_Template_construct_o)->impl = (cx_word)__Fast_Template_construct;
        if (cx_define(Fast_Template_construct_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Template::construct()'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::Template */
    if (!cx_checkState(Fast_Template_o, CX_DEFINED)) {
        cx_type(Fast_Template_o)->defaultType = cx_resolve_ext(Fast_Template_o, NULL, "::cortex::lang::member", FALSE, "element ::cortex::Fast::Template.defaultType");
        cx_type(Fast_Template_o)->parentType = NULL;
        cx_type(Fast_Template_o)->parentState = 0x0;
        cx_interface(Fast_Template_o)->base = cx_resolve_ext(Fast_Template_o, NULL, "::cortex::Fast::Local", FALSE, "element ::cortex::Fast::Template.base");
        cx_struct(Fast_Template_o)->baseAccess = 0x0;
        Fast_Template_o->implements.length = 0;
        Fast_Template_o->implements.buffer = NULL;
        if (cx_define(Fast_Template_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Template'.");
            goto error;
        }
    }

    if (cx_type(Fast_Template_o)->size != sizeof(struct Fast_Template_s)) {
        cx_error("Fast_load: calculated size '%d' of type '::cortex::Fast::Template' doesn't match C-type size '%d'", cx_type(Fast_Template_o)->size, sizeof(struct Fast_Template_s));
    }

    /* Declare ::cortex::Fast::ObjectBase::construct() */
    Fast_ObjectBase_construct_o = cx_declare(Fast_ObjectBase_o, "construct()", cx_type(cx_method_o));
    if (!Fast_ObjectBase_construct_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::ObjectBase::construct()'.");
        goto error;
    }

    /* Define ::cortex::Fast::ObjectBase::construct() */
    if (!cx_checkState(Fast_ObjectBase_construct_o, CX_DEFINED)) {
        cx_function(Fast_ObjectBase_construct_o)->returnType = cx_resolve_ext(Fast_ObjectBase_construct_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::ObjectBase::construct().returnType");
        cx_function(Fast_ObjectBase_construct_o)->returnsReference = FALSE;
        Fast_ObjectBase_construct_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::ObjectBase::construct() with C-function */
        cx_function(Fast_ObjectBase_construct_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_ObjectBase_construct(void *args, void *result);
        cx_function(Fast_ObjectBase_construct_o)->impl = (cx_word)__Fast_ObjectBase_construct;
        if (cx_define(Fast_ObjectBase_construct_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::ObjectBase::construct()'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::ObjectBase */
    if (!cx_checkState(Fast_ObjectBase_o, CX_DEFINED)) {
        cx_type(Fast_ObjectBase_o)->defaultType = cx_resolve_ext(Fast_ObjectBase_o, NULL, "::cortex::lang::member", FALSE, "element ::cortex::Fast::ObjectBase.defaultType");
        cx_type(Fast_ObjectBase_o)->parentType = NULL;
        cx_type(Fast_ObjectBase_o)->parentState = 0x0;
        cx_interface(Fast_ObjectBase_o)->base = cx_resolve_ext(Fast_ObjectBase_o, NULL, "::cortex::Fast::Variable", FALSE, "element ::cortex::Fast::ObjectBase.base");
        cx_struct(Fast_ObjectBase_o)->baseAccess = 0x4;
        Fast_ObjectBase_o->implements.length = 0;
        Fast_ObjectBase_o->implements.buffer = NULL;
        if (cx_define(Fast_ObjectBase_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::ObjectBase'.");
            goto error;
        }
    }

    if (cx_type(Fast_ObjectBase_o)->size != sizeof(struct Fast_ObjectBase_s)) {
        cx_error("Fast_load: calculated size '%d' of type '::cortex::Fast::ObjectBase' doesn't match C-type size '%d'", cx_type(Fast_ObjectBase_o)->size, sizeof(struct Fast_ObjectBase_s));
    }

    /* Declare ::cortex::Fast::Object::construct() */
    Fast_Object_construct_o = cx_declare(Fast_Object_o, "construct()", cx_type(cx_method_o));
    if (!Fast_Object_construct_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Object::construct()'.");
        goto error;
    }

    /* Define ::cortex::Fast::Object::construct() */
    if (!cx_checkState(Fast_Object_construct_o, CX_DEFINED)) {
        cx_function(Fast_Object_construct_o)->returnType = cx_resolve_ext(Fast_Object_construct_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::Object::construct().returnType");
        cx_function(Fast_Object_construct_o)->returnsReference = FALSE;
        Fast_Object_construct_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Object::construct() with C-function */
        cx_function(Fast_Object_construct_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Object_construct(void *args, void *result);
        cx_function(Fast_Object_construct_o)->impl = (cx_word)__Fast_Object_construct;
        if (cx_define(Fast_Object_construct_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Object::construct()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Object::getValue() */
    Fast_Object_getValue_o = cx_declare(Fast_Object_o, "getValue()", cx_type(cx_method_o));
    if (!Fast_Object_getValue_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Object::getValue()'.");
        goto error;
    }

    /* Define ::cortex::Fast::Object::getValue() */
    if (!cx_checkState(Fast_Object_getValue_o, CX_DEFINED)) {
        cx_function(Fast_Object_getValue_o)->returnType = cx_resolve_ext(Fast_Object_getValue_o, NULL, "::cortex::lang::word", FALSE, "element ::cortex::Fast::Object::getValue().returnType");
        cx_function(Fast_Object_getValue_o)->returnsReference = FALSE;
        Fast_Object_getValue_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Object::getValue() with C-function */
        cx_function(Fast_Object_getValue_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Object_getValue(void *args, void *result);
        cx_function(Fast_Object_getValue_o)->impl = (cx_word)__Fast_Object_getValue;
        if (cx_define(Fast_Object_getValue_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Object::getValue()'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Object::serialize(type dstType,word dst) */
    Fast_Object_serialize_o = cx_declare(Fast_Object_o, "serialize(type dstType,word dst)", cx_type(cx_method_o));
    if (!Fast_Object_serialize_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Object::serialize(type dstType,word dst)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Object::serialize(type dstType,word dst) */
    if (!cx_checkState(Fast_Object_serialize_o, CX_DEFINED)) {
        cx_function(Fast_Object_serialize_o)->returnType = cx_resolve_ext(Fast_Object_serialize_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::Object::serialize(type dstType,word dst).returnType");
        cx_function(Fast_Object_serialize_o)->returnsReference = FALSE;
        Fast_Object_serialize_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Object::serialize(type dstType,word dst) with C-function */
        cx_function(Fast_Object_serialize_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Object_serialize(void *args, void *result);
        cx_function(Fast_Object_serialize_o)->impl = (cx_word)__Fast_Object_serialize;
        if (cx_define(Fast_Object_serialize_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Object::serialize(type dstType,word dst)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Object::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
    Fast_Object_toIc_o = cx_declare(Fast_Object_o, "toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)", cx_type(cx_virtual_o));
    if (!Fast_Object_toIc_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Object::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Object::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
    if (!cx_checkState(Fast_Object_toIc_o, CX_DEFINED)) {
        cx_function(Fast_Object_toIc_o)->returnType = cx_resolve_ext(Fast_Object_toIc_o, NULL, "::cortex::lang::alias{\"cx_ic\"}", FALSE, "element ::cortex::Fast::Object::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored).returnType");
        cx_function(Fast_Object_toIc_o)->returnsReference = FALSE;
        cx_method(Fast_Object_toIc_o)->virtual = TRUE;
        
        /* Bind ::cortex::Fast::Object::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) with C-function */
        cx_function(Fast_Object_toIc_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Object_toIc_v(void *args, void *result);
        cx_function(Fast_Object_toIc_o)->impl = (cx_word)__Fast_Object_toIc_v;
        if (cx_define(Fast_Object_toIc_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Object::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::Object */
    if (!cx_checkState(Fast_Object_o, CX_DEFINED)) {
        cx_type(Fast_Object_o)->defaultType = cx_resolve_ext(Fast_Object_o, NULL, "::cortex::lang::member", FALSE, "element ::cortex::Fast::Object.defaultType");
        cx_type(Fast_Object_o)->parentType = NULL;
        cx_type(Fast_Object_o)->parentState = 0x0;
        cx_interface(Fast_Object_o)->base = cx_resolve_ext(Fast_Object_o, NULL, "::cortex::Fast::ObjectBase", FALSE, "element ::cortex::Fast::Object.base");
        cx_struct(Fast_Object_o)->baseAccess = 0x0;
        Fast_Object_o->implements.length = 0;
        Fast_Object_o->implements.buffer = NULL;
        if (cx_define(Fast_Object_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Object'.");
            goto error;
        }
    }

    if (cx_type(Fast_Object_o)->size != sizeof(struct Fast_Object_s)) {
        cx_error("Fast_load: calculated size '%d' of type '::cortex::Fast::Object' doesn't match C-type size '%d'", cx_type(Fast_Object_o)->size, sizeof(struct Fast_Object_s));
    }

    /* Declare ::cortex::Fast::Parser::observerDeclaration(string id,Fast::Expression object,eventMask mask,Fast::Object dispatcher) */
    Fast_Parser_observerDeclaration_o = cx_declare(Fast_Parser_o, "observerDeclaration(string id,Fast::Expression object,eventMask mask,Fast::Object dispatcher)", cx_type(cx_method_o));
    if (!Fast_Parser_observerDeclaration_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::observerDeclaration(string id,Fast::Expression object,eventMask mask,Fast::Object dispatcher)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::observerDeclaration(string id,Fast::Expression object,eventMask mask,Fast::Object dispatcher) */
    if (!cx_checkState(Fast_Parser_observerDeclaration_o, CX_DEFINED)) {
        cx_function(Fast_Parser_observerDeclaration_o)->returnType = cx_resolve_ext(Fast_Parser_observerDeclaration_o, NULL, "::cortex::Fast::Variable", FALSE, "element ::cortex::Fast::Parser::observerDeclaration(string id,Fast::Expression object,eventMask mask,Fast::Object dispatcher).returnType");
        cx_function(Fast_Parser_observerDeclaration_o)->returnsReference = FALSE;
        Fast_Parser_observerDeclaration_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Parser::observerDeclaration(string id,Fast::Expression object,eventMask mask,Fast::Object dispatcher) with C-function */
        cx_function(Fast_Parser_observerDeclaration_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Parser_observerDeclaration(void *args, void *result);
        cx_function(Fast_Parser_observerDeclaration_o)->impl = (cx_word)__Fast_Parser_observerDeclaration;
        if (cx_define(Fast_Parser_observerDeclaration_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::observerDeclaration(string id,Fast::Expression object,eventMask mask,Fast::Object dispatcher)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::argumentToString(Fast::Variable type,string id,bool reference) */
    Fast_Parser_argumentToString_o = cx_declare(Fast_Parser_o, "argumentToString(Fast::Variable type,string id,bool reference)", cx_type(cx_method_o));
    if (!Fast_Parser_argumentToString_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::argumentToString(Fast::Variable type,string id,bool reference)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::argumentToString(Fast::Variable type,string id,bool reference) */
    if (!cx_checkState(Fast_Parser_argumentToString_o, CX_DEFINED)) {
        cx_function(Fast_Parser_argumentToString_o)->returnType = cx_resolve_ext(Fast_Parser_argumentToString_o, NULL, "::cortex::lang::string", FALSE, "element ::cortex::Fast::Parser::argumentToString(Fast::Variable type,string id,bool reference).returnType");
        cx_function(Fast_Parser_argumentToString_o)->returnsReference = FALSE;
        Fast_Parser_argumentToString_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Parser::argumentToString(Fast::Variable type,string id,bool reference) with C-function */
        cx_function(Fast_Parser_argumentToString_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Parser_argumentToString(void *args, void *result);
        cx_function(Fast_Parser_argumentToString_o)->impl = (cx_word)__Fast_Parser_argumentToString;
        if (cx_define(Fast_Parser_argumentToString_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::argumentToString(Fast::Variable type,string id,bool reference)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::declaration(Variable type,string id,bool isReference) */
    Fast_Parser_declaration_o = cx_declare(Fast_Parser_o, "declaration(Variable type,string id,bool isReference)", cx_type(cx_method_o));
    if (!Fast_Parser_declaration_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::declaration(Variable type,string id,bool isReference)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::declaration(Variable type,string id,bool isReference) */
    if (!cx_checkState(Fast_Parser_declaration_o, CX_DEFINED)) {
        cx_function(Fast_Parser_declaration_o)->returnType = cx_resolve_ext(Fast_Parser_declaration_o, NULL, "::cortex::Fast::Variable", FALSE, "element ::cortex::Fast::Parser::declaration(Variable type,string id,bool isReference).returnType");
        cx_function(Fast_Parser_declaration_o)->returnsReference = FALSE;
        Fast_Parser_declaration_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Parser::declaration(Variable type,string id,bool isReference) with C-function */
        cx_function(Fast_Parser_declaration_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Parser_declaration(void *args, void *result);
        cx_function(Fast_Parser_declaration_o)->impl = (cx_word)__Fast_Parser_declaration;
        if (cx_define(Fast_Parser_declaration_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::declaration(Variable type,string id,bool isReference)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::declareFunction(Variable returnType,string id,type kind,bool returnsReference) */
    Fast_Parser_declareFunction_o = cx_declare(Fast_Parser_o, "declareFunction(Variable returnType,string id,type kind,bool returnsReference)", cx_type(cx_method_o));
    if (!Fast_Parser_declareFunction_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::declareFunction(Variable returnType,string id,type kind,bool returnsReference)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::declareFunction(Variable returnType,string id,type kind,bool returnsReference) */
    if (!cx_checkState(Fast_Parser_declareFunction_o, CX_DEFINED)) {
        cx_function(Fast_Parser_declareFunction_o)->returnType = cx_resolve_ext(Fast_Parser_declareFunction_o, NULL, "::cortex::Fast::Variable", FALSE, "element ::cortex::Fast::Parser::declareFunction(Variable returnType,string id,type kind,bool returnsReference).returnType");
        cx_function(Fast_Parser_declareFunction_o)->returnsReference = FALSE;
        Fast_Parser_declareFunction_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Parser::declareFunction(Variable returnType,string id,type kind,bool returnsReference) with C-function */
        cx_function(Fast_Parser_declareFunction_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Parser_declareFunction(void *args, void *result);
        cx_function(Fast_Parser_declareFunction_o)->impl = (cx_word)__Fast_Parser_declareFunction;
        if (cx_define(Fast_Parser_declareFunction_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::declareFunction(Variable returnType,string id,type kind,bool returnsReference)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::declareFunctionParams(Variable function) */
    Fast_Parser_declareFunctionParams_o = cx_declare(Fast_Parser_o, "declareFunctionParams(Variable function)", cx_type(cx_method_o));
    if (!Fast_Parser_declareFunctionParams_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::declareFunctionParams(Variable function)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::declareFunctionParams(Variable function) */
    if (!cx_checkState(Fast_Parser_declareFunctionParams_o, CX_DEFINED)) {
        cx_function(Fast_Parser_declareFunctionParams_o)->returnType = cx_resolve_ext(Fast_Parser_declareFunctionParams_o, NULL, "::cortex::Fast::Block", FALSE, "element ::cortex::Fast::Parser::declareFunctionParams(Variable function).returnType");
        cx_function(Fast_Parser_declareFunctionParams_o)->returnsReference = FALSE;
        Fast_Parser_declareFunctionParams_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Parser::declareFunctionParams(Variable function) with C-function */
        cx_function(Fast_Parser_declareFunctionParams_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Parser_declareFunctionParams(void *args, void *result);
        cx_function(Fast_Parser_declareFunctionParams_o)->impl = (cx_word)__Fast_Parser_declareFunctionParams;
        if (cx_define(Fast_Parser_declareFunctionParams_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::declareFunctionParams(Variable function)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::defineVariable(Variable object) */
    Fast_Parser_defineVariable_o = cx_declare(Fast_Parser_o, "defineVariable(Variable object)", cx_type(cx_method_o));
    if (!Fast_Parser_defineVariable_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::defineVariable(Variable object)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::defineVariable(Variable object) */
    if (!cx_checkState(Fast_Parser_defineVariable_o, CX_DEFINED)) {
        cx_function(Fast_Parser_defineVariable_o)->returnType = cx_resolve_ext(Fast_Parser_defineVariable_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::Parser::defineVariable(Variable object).returnType");
        cx_function(Fast_Parser_defineVariable_o)->returnsReference = FALSE;
        Fast_Parser_defineVariable_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Parser::defineVariable(Variable object) with C-function */
        cx_function(Fast_Parser_defineVariable_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Parser_defineVariable(void *args, void *result);
        cx_function(Fast_Parser_defineVariable_o)->impl = (cx_word)__Fast_Parser_defineVariable;
        if (cx_define(Fast_Parser_defineVariable_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::defineVariable(Variable object)'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Parser::popScope(Fast::Variable previous) */
    Fast_Parser_popScope_o = cx_declare(Fast_Parser_o, "popScope(Fast::Variable previous)", cx_type(cx_method_o));
    if (!Fast_Parser_popScope_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Parser::popScope(Fast::Variable previous)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Parser::popScope(Fast::Variable previous) */
    if (!cx_checkState(Fast_Parser_popScope_o, CX_DEFINED)) {
        cx_function(Fast_Parser_popScope_o)->returnType = cx_resolve_ext(Fast_Parser_popScope_o, NULL, "::cortex::lang::void", FALSE, "element ::cortex::Fast::Parser::popScope(Fast::Variable previous).returnType");
        cx_function(Fast_Parser_popScope_o)->returnsReference = FALSE;
        Fast_Parser_popScope_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Parser::popScope(Fast::Variable previous) with C-function */
        cx_function(Fast_Parser_popScope_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Parser_popScope(void *args, void *result);
        cx_function(Fast_Parser_popScope_o)->impl = (cx_word)__Fast_Parser_popScope;
        if (cx_define(Fast_Parser_popScope_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::popScope(Fast::Variable previous)'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::Parser::scope */
    if (!cx_checkState(Fast_Parser_scope_o, CX_DEFINED)) {
        Fast_Parser_scope_o->type = cx_resolve_ext(Fast_Parser_scope_o, NULL, "::cortex::Fast::Variable", FALSE, "element ::cortex::Fast::Parser::scope.type");
        Fast_Parser_scope_o->modifiers = 0x4;
        Fast_Parser_scope_o->state = 0x6;
        Fast_Parser_scope_o->weak = FALSE;
        Fast_Parser_scope_o->id = 9;
        if (cx_define(Fast_Parser_scope_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::scope'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::ParserDeclaration::variable */
    if (!cx_checkState(Fast_ParserDeclaration_variable_o, CX_DEFINED)) {
        Fast_ParserDeclaration_variable_o->type = cx_resolve_ext(Fast_ParserDeclaration_variable_o, NULL, "::cortex::Fast::Variable", FALSE, "element ::cortex::Fast::ParserDeclaration::variable.type");
        Fast_ParserDeclaration_variable_o->modifiers = 0x0;
        Fast_ParserDeclaration_variable_o->state = 0x6;
        Fast_ParserDeclaration_variable_o->weak = FALSE;
        Fast_ParserDeclaration_variable_o->id = 1;
        if (cx_define(Fast_ParserDeclaration_variable_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::ParserDeclaration::variable'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::ParserDeclaration */
    if (!cx_checkState(Fast_ParserDeclaration_o, CX_DEFINED)) {
        cx_type(Fast_ParserDeclaration_o)->defaultType = cx_resolve_ext(Fast_ParserDeclaration_o, NULL, "::cortex::lang::member", FALSE, "element ::cortex::Fast::ParserDeclaration.defaultType");
        cx_type(Fast_ParserDeclaration_o)->parentType = NULL;
        cx_type(Fast_ParserDeclaration_o)->parentState = 0x0;
        cx_interface(Fast_ParserDeclaration_o)->base = NULL;
        Fast_ParserDeclaration_o->baseAccess = 0x0;
        if (cx_define(Fast_ParserDeclaration_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::ParserDeclaration'.");
            goto error;
        }
    }

    if (cx_type(Fast_ParserDeclaration_o)->size != sizeof(Fast_ParserDeclaration)) {
        cx_error("Fast_load: calculated size '%d' of type '::cortex::Fast::ParserDeclaration' doesn't match C-type size '%d'", cx_type(Fast_ParserDeclaration_o)->size, sizeof(Fast_ParserDeclaration));
    }

    /* Define ::cortex::Fast::String::scope */
    if (!cx_checkState(Fast_String_scope_o, CX_DEFINED)) {
        Fast_String_scope_o->type = cx_resolve_ext(Fast_String_scope_o, NULL, "::cortex::Fast::Variable", FALSE, "element ::cortex::Fast::String::scope.type");
        Fast_String_scope_o->modifiers = 0x4;
        Fast_String_scope_o->state = 0x6;
        Fast_String_scope_o->weak = FALSE;
        Fast_String_scope_o->id = 3;
        if (cx_define(Fast_String_scope_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::String::scope'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::String */
    if (!cx_checkState(Fast_String_o, CX_DEFINED)) {
        cx_type(Fast_String_o)->defaultType = cx_resolve_ext(Fast_String_o, NULL, "::cortex::lang::member", FALSE, "element ::cortex::Fast::String.defaultType");
        cx_type(Fast_String_o)->parentType = NULL;
        cx_type(Fast_String_o)->parentState = 0x0;
        cx_interface(Fast_String_o)->base = cx_resolve_ext(Fast_String_o, NULL, "::cortex::Fast::Literal", FALSE, "element ::cortex::Fast::String.base");
        cx_struct(Fast_String_o)->baseAccess = 0x4;
        Fast_String_o->implements.length = 0;
        Fast_String_o->implements.buffer = NULL;
        if (cx_define(Fast_String_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::String'.");
            goto error;
        }
    }

    if (cx_type(Fast_String_o)->size != sizeof(struct Fast_String_s)) {
        cx_error("Fast_load: calculated size '%d' of type '::cortex::Fast::String' doesn't match C-type size '%d'", cx_type(Fast_String_o)->size, sizeof(struct Fast_String_s));
    }

    /* Define ::cortex::Fast::Parser::variables */
    if (!cx_checkState(Fast_Parser_variables_o, CX_DEFINED)) {
        Fast_Parser_variables_o->type = cx_resolve_ext(Fast_Parser_variables_o, NULL, "::cortex::lang::array{::cortex::Fast::Variable,64,::cortex::Fast::Variable}", FALSE, "element ::cortex::Fast::Parser::variables.type");
        Fast_Parser_variables_o->modifiers = 0x6;
        Fast_Parser_variables_o->state = 0x6;
        Fast_Parser_variables_o->weak = FALSE;
        Fast_Parser_variables_o->id = 24;
        if (cx_define(Fast_Parser_variables_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser::variables'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::Parser */
    if (!cx_checkState(Fast_Parser_o, CX_DEFINED)) {
        cx_type(Fast_Parser_o)->defaultType = cx_resolve_ext(Fast_Parser_o, NULL, "::cortex::lang::member", FALSE, "element ::cortex::Fast::Parser.defaultType");
        cx_type(Fast_Parser_o)->parentType = NULL;
        cx_type(Fast_Parser_o)->parentState = 0x0;
        cx_interface(Fast_Parser_o)->base = NULL;
        cx_struct(Fast_Parser_o)->baseAccess = 0x0;
        Fast_Parser_o->implements.length = 0;
        Fast_Parser_o->implements.buffer = NULL;
        if (cx_define(Fast_Parser_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Parser'.");
            goto error;
        }
    }

    if (cx_type(Fast_Parser_o)->size != sizeof(struct Fast_Parser_s)) {
        cx_error("Fast_load: calculated size '%d' of type '::cortex::Fast::Parser' doesn't match C-type size '%d'", cx_type(Fast_Parser_o)->size, sizeof(struct Fast_Parser_s));
    }

    /* Declare ::cortex::Fast::Wait::construct() */
    Fast_Wait_construct_o = cx_declare(Fast_Wait_o, "construct()", cx_type(cx_method_o));
    if (!Fast_Wait_construct_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Wait::construct()'.");
        goto error;
    }

    /* Define ::cortex::Fast::Wait::construct() */
    if (!cx_checkState(Fast_Wait_construct_o, CX_DEFINED)) {
        cx_function(Fast_Wait_construct_o)->returnType = cx_resolve_ext(Fast_Wait_construct_o, NULL, "::cortex::lang::int16", FALSE, "element ::cortex::Fast::Wait::construct().returnType");
        cx_function(Fast_Wait_construct_o)->returnsReference = FALSE;
        Fast_Wait_construct_o->virtual = FALSE;
        
        /* Bind ::cortex::Fast::Wait::construct() with C-function */
        cx_function(Fast_Wait_construct_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Wait_construct(void *args, void *result);
        cx_function(Fast_Wait_construct_o)->impl = (cx_word)__Fast_Wait_construct;
        if (cx_define(Fast_Wait_construct_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Wait::construct()'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::Wait::timeout */
    if (!cx_checkState(Fast_Wait_timeout_o, CX_DEFINED)) {
        Fast_Wait_timeout_o->type = cx_resolve_ext(Fast_Wait_timeout_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::Wait::timeout.type");
        Fast_Wait_timeout_o->modifiers = 0x0;
        Fast_Wait_timeout_o->state = 0x6;
        Fast_Wait_timeout_o->weak = FALSE;
        Fast_Wait_timeout_o->id = 1;
        if (cx_define(Fast_Wait_timeout_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Wait::timeout'.");
            goto error;
        }
    }

    /* Declare ::cortex::Fast::Wait::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
    Fast_Wait_toIc_o = cx_declare(Fast_Wait_o, "toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)", cx_type(cx_virtual_o));
    if (!Fast_Wait_toIc_o) {
        cx_error("Fast_load: failed to declare object '::cortex::Fast::Wait::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)'.");
        goto error;
    }

    /* Define ::cortex::Fast::Wait::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
    if (!cx_checkState(Fast_Wait_toIc_o, CX_DEFINED)) {
        cx_function(Fast_Wait_toIc_o)->returnType = cx_resolve_ext(Fast_Wait_toIc_o, NULL, "::cortex::lang::alias{\"cx_ic\"}", FALSE, "element ::cortex::Fast::Wait::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored).returnType");
        cx_function(Fast_Wait_toIc_o)->returnsReference = FALSE;
        cx_method(Fast_Wait_toIc_o)->virtual = TRUE;
        
        /* Bind ::cortex::Fast::Wait::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) with C-function */
        cx_function(Fast_Wait_toIc_o)->kind = CX_PROCEDURE_CDECL;
        void __Fast_Wait_toIc_v(void *args, void *result);
        cx_function(Fast_Wait_toIc_o)->impl = (cx_word)__Fast_Wait_toIc_v;
        if (cx_define(Fast_Wait_toIc_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Wait::toIc(alias{\"cx_icProgram\"} program,alias{\"cx_icStorage\"} storage,bool stored)'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::Wait */
    if (!cx_checkState(Fast_Wait_o, CX_DEFINED)) {
        cx_type(Fast_Wait_o)->defaultType = cx_resolve_ext(Fast_Wait_o, NULL, "::cortex::lang::member", FALSE, "element ::cortex::Fast::Wait.defaultType");
        cx_type(Fast_Wait_o)->parentType = NULL;
        cx_type(Fast_Wait_o)->parentState = 0x0;
        cx_interface(Fast_Wait_o)->base = cx_resolve_ext(Fast_Wait_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::Wait.base");
        cx_struct(Fast_Wait_o)->baseAccess = 0x4;
        Fast_Wait_o->implements.length = 0;
        Fast_Wait_o->implements.buffer = NULL;
        if (cx_define(Fast_Wait_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::Wait'.");
            goto error;
        }
    }

    if (cx_type(Fast_Wait_o)->size != sizeof(struct Fast_Wait_s)) {
        cx_error("Fast_load: calculated size '%d' of type '::cortex::Fast::Wait' doesn't match C-type size '%d'", cx_type(Fast_Wait_o)->size, sizeof(struct Fast_Wait_s));
    }

    /* Define ::cortex::Fast::While::condition */
    if (!cx_checkState(Fast_While_condition_o, CX_DEFINED)) {
        Fast_While_condition_o->type = cx_resolve_ext(Fast_While_condition_o, NULL, "::cortex::Fast::Expression", FALSE, "element ::cortex::Fast::While::condition.type");
        Fast_While_condition_o->modifiers = 0x0;
        Fast_While_condition_o->state = 0x6;
        Fast_While_condition_o->weak = FALSE;
        Fast_While_condition_o->id = 0;
        if (cx_define(Fast_While_condition_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::While::condition'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::While */
    if (!cx_checkState(Fast_While_o, CX_DEFINED)) {
        cx_type(Fast_While_o)->defaultType = cx_resolve_ext(Fast_While_o, NULL, "::cortex::lang::member", FALSE, "element ::cortex::Fast::While.defaultType");
        cx_type(Fast_While_o)->parentType = NULL;
        cx_type(Fast_While_o)->parentState = 0x0;
        cx_interface(Fast_While_o)->base = cx_resolve_ext(Fast_While_o, NULL, "::cortex::Fast::Node", FALSE, "element ::cortex::Fast::While.base");
        cx_struct(Fast_While_o)->baseAccess = 0x4;
        Fast_While_o->implements.length = 0;
        Fast_While_o->implements.buffer = NULL;
        if (cx_define(Fast_While_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::While'.");
            goto error;
        }
    }

    if (cx_type(Fast_While_o)->size != sizeof(struct Fast_While_s)) {
        cx_error("Fast_load: calculated size '%d' of type '::cortex::Fast::While' doesn't match C-type size '%d'", cx_type(Fast_While_o)->size, sizeof(struct Fast_While_s));
    }

    /* Define ::cortex::Fast::DynamicInitializerFrame::expr */
    if (!cx_checkState(Fast_DynamicInitializerFrame_expr_o, CX_DEFINED)) {
        Fast_DynamicInitializerFrame_expr_o->type = cx_resolve_ext(Fast_DynamicInitializerFrame_expr_o, NULL, "::cortex::lang::array{::cortex::Fast::Expression,64,::cortex::Fast::Expression}", FALSE, "element ::cortex::Fast::DynamicInitializerFrame::expr.type");
        Fast_DynamicInitializerFrame_expr_o->modifiers = 0x0;
        Fast_DynamicInitializerFrame_expr_o->state = 0x6;
        Fast_DynamicInitializerFrame_expr_o->weak = FALSE;
        Fast_DynamicInitializerFrame_expr_o->id = 0;
        if (cx_define(Fast_DynamicInitializerFrame_expr_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::DynamicInitializerFrame::expr'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::DynamicInitializerFrame::keyExpr */
    if (!cx_checkState(Fast_DynamicInitializerFrame_keyExpr_o, CX_DEFINED)) {
        Fast_DynamicInitializerFrame_keyExpr_o->type = cx_resolve_ext(Fast_DynamicInitializerFrame_keyExpr_o, NULL, "::cortex::lang::array{::cortex::Fast::Expression,64,::cortex::Fast::Expression}", FALSE, "element ::cortex::Fast::DynamicInitializerFrame::keyExpr.type");
        Fast_DynamicInitializerFrame_keyExpr_o->modifiers = 0x0;
        Fast_DynamicInitializerFrame_keyExpr_o->state = 0x6;
        Fast_DynamicInitializerFrame_keyExpr_o->weak = FALSE;
        Fast_DynamicInitializerFrame_keyExpr_o->id = 1;
        if (cx_define(Fast_DynamicInitializerFrame_keyExpr_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::DynamicInitializerFrame::keyExpr'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::DynamicInitializerFrame */
    if (!cx_checkState(Fast_DynamicInitializerFrame_o, CX_DEFINED)) {
        cx_type(Fast_DynamicInitializerFrame_o)->defaultType = cx_resolve_ext(Fast_DynamicInitializerFrame_o, NULL, "::cortex::lang::member", FALSE, "element ::cortex::Fast::DynamicInitializerFrame.defaultType");
        cx_type(Fast_DynamicInitializerFrame_o)->parentType = NULL;
        cx_type(Fast_DynamicInitializerFrame_o)->parentState = 0x0;
        cx_interface(Fast_DynamicInitializerFrame_o)->base = NULL;
        Fast_DynamicInitializerFrame_o->baseAccess = 0x0;
        if (cx_define(Fast_DynamicInitializerFrame_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::DynamicInitializerFrame'.");
            goto error;
        }
    }

    if (cx_type(Fast_DynamicInitializerFrame_o)->size != sizeof(Fast_DynamicInitializerFrame)) {
        cx_error("Fast_load: calculated size '%d' of type '::cortex::Fast::DynamicInitializerFrame' doesn't match C-type size '%d'", cx_type(Fast_DynamicInitializerFrame_o)->size, sizeof(Fast_DynamicInitializerFrame));
    }

    /* Define ::cortex::Fast::DynamicInitializer::frames */
    if (!cx_checkState(Fast_DynamicInitializer_frames_o, CX_DEFINED)) {
        Fast_DynamicInitializer_frames_o->type = cx_resolve_ext(Fast_DynamicInitializer_frames_o, NULL, "::cortex::lang::array{::cortex::Fast::DynamicInitializerFrame,64,::cortex::Fast::DynamicInitializerFrame}", FALSE, "element ::cortex::Fast::DynamicInitializer::frames.type");
        Fast_DynamicInitializer_frames_o->modifiers = 0x3;
        Fast_DynamicInitializer_frames_o->state = 0x6;
        Fast_DynamicInitializer_frames_o->weak = FALSE;
        Fast_DynamicInitializer_frames_o->id = 1;
        if (cx_define(Fast_DynamicInitializer_frames_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::DynamicInitializer::frames'.");
            goto error;
        }
    }

    /* Define ::cortex::Fast::DynamicInitializer */
    if (!cx_checkState(Fast_DynamicInitializer_o, CX_DEFINED)) {
        cx_type(Fast_DynamicInitializer_o)->defaultType = cx_resolve_ext(Fast_DynamicInitializer_o, NULL, "::cortex::lang::member", FALSE, "element ::cortex::Fast::DynamicInitializer.defaultType");
        cx_type(Fast_DynamicInitializer_o)->parentType = NULL;
        cx_type(Fast_DynamicInitializer_o)->parentState = 0x0;
        cx_interface(Fast_DynamicInitializer_o)->base = cx_resolve_ext(Fast_DynamicInitializer_o, NULL, "::cortex::Fast::Initializer", FALSE, "element ::cortex::Fast::DynamicInitializer.base");
        cx_struct(Fast_DynamicInitializer_o)->baseAccess = 0x0;
        Fast_DynamicInitializer_o->implements.length = 0;
        Fast_DynamicInitializer_o->implements.buffer = NULL;
        if (cx_define(Fast_DynamicInitializer_o)) {
            cx_error("Fast_load: failed to define object '::cortex::Fast::DynamicInitializer'.");
            goto error;
        }
    }

    if (cx_type(Fast_DynamicInitializer_o)->size != sizeof(struct Fast_DynamicInitializer_s)) {
        cx_error("Fast_load: calculated size '%d' of type '::cortex::Fast::DynamicInitializer' doesn't match C-type size '%d'", cx_type(Fast_DynamicInitializer_o)->size, sizeof(struct Fast_DynamicInitializer_s));
    }

    if (_a_) {
        cx_free(_a_);
    }

    return 0;
error:
    return -1;
}
