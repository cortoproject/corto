/* Fast__meta.c
 *
 * Loads objects in database.
 * This file contains generated code. Do not modify!
 */

#include "Fast__type.h"

/* Variable definitions */
db_object _o;
db_void (*Fast_o);
db_class Fast_BinaryExpr_o;
db_callback Fast_BinaryExpr_construct_o;
db_method Fast_BinaryExpr_fold_o;
db_virtual Fast_BinaryExpr_hasSideEffects_o;
db_member Fast_BinaryExpr_lvalue_o;
db_member Fast_BinaryExpr_operator_o;
db_member Fast_BinaryExpr_rvalue_o;
db_method Fast_BinaryExpr_setOperator_o;
db_virtual Fast_BinaryExpr_toIc_o;
db_struct Fast_Binding_o;
db_member Fast_Binding_function_o;
db_member Fast_Binding_impl_o;
db_class Fast_Block_o;
db_method Fast_Block_addStatement_o;
db_method Fast_Block_declare_o;
db_method Fast_Block_declareReturnVariable_o;
db_method Fast_Block_declareTemplate_o;
db_member Fast_Block_function_o;
db_member Fast_Block_locals_o;
db_method Fast_Block_lookup_o;
db_method Fast_Block_lookupLocal_o;
db_member Fast_Block_parent_o;
db_method Fast_Block_resolve_o;
db_method Fast_Block_setFunction_o;
db_member Fast_Block_statements_o;
db_virtual Fast_Block_toIc_o;
db_virtual Fast_Block_toIcBody_o;
db_member Fast_Block_while_o;
db_class Fast_Boolean_o;
db_callback Fast_Boolean_init_o;
db_method Fast_Boolean_serialize_o;
db_virtual Fast_Boolean_toIc_o;
db_member Fast_Boolean_value_o;
db_class Fast_Call_o;
db_member Fast_Call_actualFunction_o;
db_member Fast_Call_arguments_o;
db_callback Fast_Call_construct_o;
db_member Fast_Call_function_o;
db_virtual Fast_Call_hasSideEffects_o;
db_member Fast_Call_signature_o;
db_virtual Fast_Call_toIc_o;
db_class Fast_CastExpr_o;
db_callback Fast_CastExpr_construct_o;
db_member Fast_CastExpr_lvalue_o;
db_member Fast_CastExpr_rvalue_o;
db_virtual Fast_CastExpr_toIc_o;
db_class Fast_Character_o;
db_callback Fast_Character_init_o;
db_method Fast_Character_serialize_o;
db_virtual Fast_Character_toIc_o;
db_member Fast_Character_value_o;
db_class Fast_CommaExpr_o;
db_method Fast_CommaExpr_addExpression_o;
db_function Fast_CommaExpr_addOrCreate_o;
db_callback Fast_CommaExpr_construct_o;
db_member Fast_CommaExpr_expressions_o;
db_virtual Fast_CommaExpr_hasSideEffects_o;
db_callback Fast_CommaExpr_init_o;
db_virtual Fast_CommaExpr_toIc_o;
db_method Fast_CommaExpr_toList_o;
db_class Fast_Define_o;
db_callback Fast_Define_construct_o;
db_member Fast_Define_object_o;
db_virtual Fast_Define_toIc_o;
db_class Fast_DynamicInitializer_o;
db_member Fast_DynamicInitializer_assignValue_o;
db_callback Fast_DynamicInitializer_construct_o;
db_method Fast_DynamicInitializer_define_o;
db_member Fast_DynamicInitializer_frames_o;
db_method Fast_DynamicInitializer_pop_o;
db_method Fast_DynamicInitializer_push_o;
db_method Fast_DynamicInitializer_value_o;
db_struct Fast_DynamicInitializerFrame_o;
db_member Fast_DynamicInitializerFrame_expr_o;
db_member Fast_DynamicInitializerFrame_keyExpr_o;
db_member Fast_DynamicInitializerFrame_sequenceSize_o;
db_class Fast_ElementExpr_o;
db_callback Fast_ElementExpr_construct_o;
db_member Fast_ElementExpr_lvalue_o;
db_member Fast_ElementExpr_rvalue_o;
db_virtual Fast_ElementExpr_toIc_o;
db_class Fast_Expression_o;
db_method Fast_Expression_cast_o;
db_function Fast_Expression_cleanList_o;
db_virtual Fast_Expression_fold_o;
db_member Fast_Expression_forceReference_o;
db_function Fast_Expression_fromList_o;
db_method Fast_Expression_getType_o;
db_method Fast_Expression_getType_expr_o;
db_method Fast_Expression_getType_type_o;
db_virtual Fast_Expression_getValue_o;
db_virtual Fast_Expression_hasSideEffects_o;
db_callback Fast_Expression_init_o;
db_member Fast_Expression_isReference_o;
db_virtual Fast_Expression_serialize_o;
db_virtual Fast_Expression_toList_o;
db_member Fast_Expression_type_o;
db_class Fast_FloatingPoint_o;
db_callback Fast_FloatingPoint_init_o;
db_method Fast_FloatingPoint_serialize_o;
db_virtual Fast_FloatingPoint_toIc_o;
db_member Fast_FloatingPoint_value_o;
db_class Fast_If_o;
db_member Fast_If_condition_o;
db_callback Fast_If_construct_o;
db_member Fast_If_falseBranch_o;
db_method Fast_If_noWarnUnreachable_o;
db_virtual Fast_If_toIc_o;
db_member Fast_If_trueBranch_o;
db_member Fast_If_warnUnreachable_o;
db_class Fast_Initializer_o;
db_callback Fast_Initializer_construct_o;
db_method Fast_Initializer_currentType_o;
db_virtual Fast_Initializer_define_o;
db_member Fast_Initializer_fp_o;
db_member Fast_Initializer_frames_o;
db_method Fast_Initializer_initFrame_o;
db_virtual Fast_Initializer_member_o;
db_virtual Fast_Initializer_next_o;
db_virtual Fast_Initializer_pop_o;
db_virtual Fast_Initializer_popKey_o;
db_virtual Fast_Initializer_push_o;
db_virtual Fast_Initializer_pushKey_o;
db_method Fast_Initializer_type_o;
db_virtual Fast_Initializer_value_o;
db_virtual Fast_Initializer_valueKey_o;
db_member Fast_Initializer_variableCount_o;
db_member Fast_Initializer_variables_o;
db_class Fast_InitializerExpr_o;
db_member Fast_InitializerExpr_assignValue_o;
db_callback Fast_InitializerExpr_construct_o;
db_method Fast_InitializerExpr_define_o;
db_method Fast_InitializerExpr_insert_o;
db_method Fast_InitializerExpr_member_o;
db_member Fast_InitializerExpr_operations_o;
db_method Fast_InitializerExpr_pop_o;
db_method Fast_InitializerExpr_push_o;
db_method Fast_InitializerExpr_value_o;
db_struct Fast_InitializerFrame_o;
db_member Fast_InitializerFrame_isKey_o;
db_member Fast_InitializerFrame_location_o;
db_member Fast_InitializerFrame_member_o;
db_member Fast_InitializerFrame_type_o;
db_enum Fast_InitializerKind_o;
db_constant (*Fast_InitializerKind_InitDynamic_o);
db_constant (*Fast_InitializerKind_InitExpression_o);
db_constant (*Fast_InitializerKind_InitStatic_o);
db_struct Fast_InitializerVariable_o;
db_member Fast_InitializerVariable_key_o;
db_member Fast_InitializerVariable_object_o;
db_member Fast_InitializerVariable_offset_o;
db_struct Fast_InitOper_o;
db_member Fast_InitOper_expr_o;
db_member Fast_InitOper_kind_o;
db_member Fast_InitOper_name_o;
db_enum Fast_InitOperKind_o;
db_constant (*Fast_InitOperKind_InitDefine_o);
db_constant (*Fast_InitOperKind_InitMember_o);
db_constant (*Fast_InitOperKind_InitPop_o);
db_constant (*Fast_InitOperKind_InitPush_o);
db_constant (*Fast_InitOperKind_InitValue_o);
db_class Fast_Integer_o;
db_callback Fast_Integer_init_o;
db_method Fast_Integer_serialize_o;
db_virtual Fast_Integer_toIc_o;
db_member Fast_Integer_value_o;
db_class Fast_Literal_o;
db_virtual Fast_Literal_getValue_o;
db_callback Fast_Literal_init_o;
db_member Fast_Literal_kind_o;
db_class Fast_Local_o;
db_callback Fast_Local_construct_o;
db_member Fast_Local_isReference_o;
db_member Fast_Local_kind_o;
db_member Fast_Local_name_o;
db_virtual Fast_Local_toIc_o;
db_member Fast_Local_type_o;
db_enum Fast_LocalKind_o;
db_constant (*Fast_LocalKind_LocalDefault_o);
db_constant (*Fast_LocalKind_LocalParameter_o);
db_constant (*Fast_LocalKind_LocalReturn_o);
db_struct Fast_Lvalue_o;
db_member Fast_Lvalue_expr_o;
db_member Fast_Lvalue_isAssignment_o;
db_class Fast_MemberExpr_o;
db_callback Fast_MemberExpr_construct_o;
db_virtual Fast_MemberExpr_hasSideEffects_o;
db_member Fast_MemberExpr_lvalue_o;
db_member Fast_MemberExpr_member_o;
db_member Fast_MemberExpr_rvalue_o;
db_member Fast_MemberExpr_superMember_o;
db_virtual Fast_MemberExpr_toIc_o;
db_class Fast_NewExpr_o;
db_member Fast_NewExpr_attributes_o;
db_callback Fast_NewExpr_construct_o;
db_virtual Fast_NewExpr_hasSideEffects_o;
db_virtual Fast_NewExpr_toIc_o;
db_member Fast_NewExpr_type_o;
db_class Fast_Node_o;
db_member Fast_Node_column_o;
db_callback Fast_Node_init_o;
db_member Fast_Node_kind_o;
db_member Fast_Node_line_o;
db_virtual Fast_Node_toIc_o;
db_enum Fast_nodeKind_o;
db_constant (*Fast_nodeKind_Binary_o);
db_constant (*Fast_nodeKind_Call_o);
db_constant (*Fast_nodeKind_Cast_o);
db_constant (*Fast_nodeKind_CommaExpr_o);
db_constant (*Fast_nodeKind_Declaration_o);
db_constant (*Fast_nodeKind_Declare_o);
db_constant (*Fast_nodeKind_Define_o);
db_constant (*Fast_nodeKind_Element_o);
db_constant (*Fast_nodeKind_If_o);
db_constant (*Fast_nodeKind_Initializer_o);
db_constant (*Fast_nodeKind_Literal_o);
db_constant (*Fast_nodeKind_Member_o);
db_constant (*Fast_nodeKind_Method_o);
db_constant (*Fast_nodeKind_New_o);
db_constant (*Fast_nodeKind_Postfix_o);
db_constant (*Fast_nodeKind_Ternary_o);
db_constant (*Fast_nodeKind_Unary_o);
db_constant (*Fast_nodeKind_Update_o);
db_constant (*Fast_nodeKind_Variable_o);
db_constant (*Fast_nodeKind_Wait_o);
db_constant (*Fast_nodeKind_While_o);
db_class Fast_Null_o;
db_callback Fast_Null_init_o;
db_method Fast_Null_serialize_o;
db_virtual Fast_Null_toIc_o;
db_class Fast_Object_o;
db_callback Fast_Object_construct_o;
db_method Fast_Object_getValue_o;
db_method Fast_Object_serialize_o;
db_virtual Fast_Object_toIc_o;
db_class Fast_ObjectBase_o;
db_callback Fast_ObjectBase_construct_o;
db_member Fast_ObjectBase_value_o;
db_class Fast_Parser_o;
db_member Fast_Parser_abort_o;
db_method Fast_Parser_addStatement_o;
db_method Fast_Parser_argumentToString_o;
db_method Fast_Parser_binaryExpr_o;
db_method Fast_Parser_bind_o;
db_member Fast_Parser_bindings_o;
db_method Fast_Parser_bindOneliner_o;
db_member Fast_Parser_block_o;
db_method Fast_Parser_blockPop_o;
db_member Fast_Parser_blockPreset_o;
db_method Fast_Parser_blockPush_o;
db_method Fast_Parser_callExpr_o;
db_method Fast_Parser_castExpr_o;
db_method Fast_Parser_collect_o;
db_member Fast_Parser_collected_o;
db_method Fast_Parser_collectHeap_o;
db_member Fast_Parser_column_o;
db_member Fast_Parser_complexType_o;
db_member Fast_Parser_complexTypeSp_o;
db_callback Fast_Parser_construct_o;
db_method Fast_Parser_declaration_o;
db_method Fast_Parser_declareFunction_o;
db_method Fast_Parser_declareFunctionParams_o;
db_method Fast_Parser_define_o;
db_method Fast_Parser_defineScope_o;
db_method Fast_Parser_defineVariable_o;
db_callback Fast_Parser_destruct_o;
db_method Fast_Parser_elementExpr_o;
db_member Fast_Parser_errLine_o;
db_member Fast_Parser_errors_o;
db_member Fast_Parser_errSet_o;
db_member Fast_Parser_filename_o;
db_method Fast_Parser_foreach_o;
db_method Fast_Parser_getComplexType_o;
db_method Fast_Parser_getLvalue_o;
db_method Fast_Parser_getLvalueType_o;
db_member Fast_Parser_heapCollected_o;
db_method Fast_Parser_ifStatement_o;
db_member Fast_Parser_initAnonymousId_o;
db_method Fast_Parser_initDeclareStaged_o;
db_member Fast_Parser_initDynamic_o;
db_member Fast_Parser_initializerCount_o;
db_member Fast_Parser_initializers_o;
db_method Fast_Parser_initKeyValuePop_o;
db_method Fast_Parser_initKeyValuePush_o;
db_method Fast_Parser_initKeyValueSet_o;
db_method Fast_Parser_initMember_o;
db_method Fast_Parser_initPop_o;
db_method Fast_Parser_initPush_o;
db_method Fast_Parser_initPushExpression_o;
db_method Fast_Parser_initPushIdentifier_o;
db_method Fast_Parser_initPushStatic_o;
db_method Fast_Parser_initStage_o;
db_method Fast_Parser_initValue_o;
db_method Fast_Parser_isAbortSet_o;
db_method Fast_Parser_isErrSet_o;
db_member Fast_Parser_isLocal_o;
db_member Fast_Parser_lastFailedResolve_o;
db_member Fast_Parser_line_o;
db_method Fast_Parser_lookup_o;
db_member Fast_Parser_lvalue_o;
db_member Fast_Parser_lvalueSp_o;
db_method Fast_Parser_memberExpr_o;
db_method Fast_Parser_observerDeclaration_o;
db_method Fast_Parser_observerPop_o;
db_method Fast_Parser_observerPush_o;
db_method Fast_Parser_parse_o;
db_method Fast_Parser_parseExpression_o;
db_member Fast_Parser_parseSingleExpr_o;
db_member Fast_Parser_pass_o;
db_method Fast_Parser_popComplexType_o;
db_method Fast_Parser_popLvalue_o;
db_method Fast_Parser_popScope_o;
db_method Fast_Parser_postfixExpr_o;
db_member Fast_Parser_preprocessed_o;
db_method Fast_Parser_pushComplexType_o;
db_method Fast_Parser_pushLvalue_o;
db_method Fast_Parser_pushReturnAsLvalue_o;
db_method Fast_Parser_pushScope_o;
db_method Fast_Parser_reset_o;
db_member Fast_Parser_scope_o;
db_member Fast_Parser_singleExpr_o;
db_member Fast_Parser_source_o;
db_member Fast_Parser_staged_o;
db_member Fast_Parser_stagedCount_o;
db_struct Fast_Parser_stagedId_o;
db_member Fast_Parser_stagedId_column_o;
db_member Fast_Parser_stagedId_found_o;
db_member Fast_Parser_stagedId_line_o;
db_member Fast_Parser_stagedId_name_o;
db_member Fast_Parser_stagingAllowed_o;
db_method Fast_Parser_ternaryExpr_o;
db_member Fast_Parser_token_o;
db_method Fast_Parser_unaryExpr_o;
db_method Fast_Parser_updateStatement_o;
db_member Fast_Parser_variableCount_o;
db_member Fast_Parser_variablePushed_o;
db_member Fast_Parser_variables_o;
db_member Fast_Parser_variablesInitialized_o;
db_method Fast_Parser_waitExpr_o;
db_member Fast_Parser_warnings_o;
db_method Fast_Parser_whileStatement_o;
db_struct Fast_ParserDeclaration_o;
db_member Fast_ParserDeclaration_name_o;
db_member Fast_ParserDeclaration_variable_o;
db_typedef Fast_ParserDeclarationSeq_o;
db_struct Fast_ParserNew_o;
db_member Fast_ParserNew_attr_o;
db_member Fast_ParserNew_kind_o;
db_member Fast_ParserNew_name_o;
db_member Fast_ParserNew_parent_o;
db_class Fast_PostfixExpr_o;
db_callback Fast_PostfixExpr_construct_o;
db_member Fast_PostfixExpr_lvalue_o;
db_member Fast_PostfixExpr_operator_o;
db_virtual Fast_PostfixExpr_toIc_o;
db_class Fast_SignedInteger_o;
db_callback Fast_SignedInteger_init_o;
db_method Fast_SignedInteger_serialize_o;
db_virtual Fast_SignedInteger_toIc_o;
db_member Fast_SignedInteger_value_o;
db_class Fast_StaticInitializer_o;
db_callback Fast_StaticInitializer_construct_o;
db_method Fast_StaticInitializer_define_o;
db_member Fast_StaticInitializer_frames_o;
db_method Fast_StaticInitializer_push_o;
db_method Fast_StaticInitializer_value_o;
db_struct Fast_StaticInitializerFrame_o;
db_member Fast_StaticInitializerFrame_keyPtr_o;
db_member Fast_StaticInitializerFrame_ptr_o;
db_class Fast_String_o;
db_member Fast_String_block_o;
db_callback Fast_String_construct_o;
db_member Fast_String_elements_o;
db_method Fast_String_getValue_o;
db_callback Fast_String_init_o;
db_member Fast_String_scope_o;
db_method Fast_String_serialize_o;
db_virtual Fast_String_toIc_o;
db_member Fast_String_value_o;
db_class Fast_Template_o;
db_callback Fast_Template_construct_o;
db_class Fast_TernaryExpr_o;
db_member Fast_TernaryExpr_condition_o;
db_callback Fast_TernaryExpr_construct_o;
db_virtual Fast_TernaryExpr_hasSideEffects_o;
db_member Fast_TernaryExpr_ifFalse_o;
db_member Fast_TernaryExpr_ifFalseExpr_o;
db_member Fast_TernaryExpr_ifstmt_o;
db_member Fast_TernaryExpr_ifTrue_o;
db_member Fast_TernaryExpr_ifTrueExpr_o;
db_member Fast_TernaryExpr_result_o;
db_method Fast_TernaryExpr_setOperator_o;
db_virtual Fast_TernaryExpr_toIc_o;
db_class Fast_UnaryExpr_o;
db_callback Fast_UnaryExpr_construct_o;
db_virtual Fast_UnaryExpr_hasSideEffects_o;
db_member Fast_UnaryExpr_lvalue_o;
db_member Fast_UnaryExpr_operator_o;
db_virtual Fast_UnaryExpr_toIc_o;
db_class Fast_Update_o;
db_member Fast_Update_block_o;
db_callback Fast_Update_construct_o;
db_member Fast_Update_exprList_o;
db_member Fast_Update_from_o;
db_virtual Fast_Update_toIc_o;
db_enum Fast_valueKind_o;
db_constant (*Fast_valueKind_Boolean_o);
db_constant (*Fast_valueKind_Character_o);
db_constant (*Fast_valueKind_Enumerated_o);
db_constant (*Fast_valueKind_FloatingPoint_o);
db_constant (*Fast_valueKind_Integer_o);
db_constant (*Fast_valueKind_Null_o);
db_constant (*Fast_valueKind_Reference_o);
db_constant (*Fast_valueKind_SignedInteger_o);
db_constant (*Fast_valueKind_String_o);
db_function Fast_valueKindFromType_o;
db_class Fast_Variable_o;
db_callback Fast_Variable_construct_o;
db_member Fast_Variable_kind_o;
db_enum Fast_variableKind_o;
db_constant (*Fast_variableKind_Local_o);
db_constant (*Fast_variableKind_Object_o);
db_constant (*Fast_variableKind_Template_o);
db_class Fast_Wait_o;
db_callback Fast_Wait_construct_o;
db_member Fast_Wait_exprList_o;
db_member Fast_Wait_timeout_o;
db_virtual Fast_Wait_toIc_o;
db_class Fast_While_o;
db_member Fast_While_condition_o;
db_callback Fast_While_construct_o;
db_member Fast_While_isUntil_o;
db_virtual Fast_While_toIc_o;
db_member Fast_While_trueBranch_o;

/* Load objects in database */
int Fast_load(void) {
    db_object _a_; /* Used for resolving anonymous objects */
    _a_ = NULL;

    /* Declare ::hyve */
    _o = db_declare(root_o, "hyve", db_typedef(db_object_o));
    if (!_o) {
        db_error("Fast_load: failed to declare object '::hyve'.");
        goto error;
    }

    /* Define ::hyve */
    if (!db_checkState(_o, DB_DEFINED)) {
        if (db_define(_o)) {
            db_error("Fast_load: failed to define object '::hyve'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast */
    Fast_o = db_declare(_o, "Fast", db_typedef(db_void_o));
    if (!Fast_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast'.");
        goto error;
    }

    /* Declare ::hyve::Fast::BinaryExpr */
    Fast_BinaryExpr_o = db_declare(Fast_o, "BinaryExpr", db_typedef(db_class_o));
    if (!Fast_BinaryExpr_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::BinaryExpr'.");
        goto error;
    }

    /* Declare ::hyve::Fast::BinaryExpr::lvalue */
    Fast_BinaryExpr_lvalue_o = db_declare(Fast_BinaryExpr_o, "lvalue", db_typedef(db_member_o));
    if (!Fast_BinaryExpr_lvalue_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::BinaryExpr::lvalue'.");
        goto error;
    }

    /* Declare ::hyve::Fast::BinaryExpr::operator */
    Fast_BinaryExpr_operator_o = db_declare(Fast_BinaryExpr_o, "operator", db_typedef(db_member_o));
    if (!Fast_BinaryExpr_operator_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::BinaryExpr::operator'.");
        goto error;
    }

    /* Define ::hyve::Fast::BinaryExpr::operator */
    if (!db_checkState(Fast_BinaryExpr_operator_o, DB_DEFINED)) {
        Fast_BinaryExpr_operator_o->type = db_resolve_ext(Fast_BinaryExpr_operator_o, NULL, "::hyve::lang::operatorKind", FALSE, "element ::hyve::Fast::BinaryExpr::operator.type");
        Fast_BinaryExpr_operator_o->modifiers = 0x0;
        Fast_BinaryExpr_operator_o->state = 0x6;
        Fast_BinaryExpr_operator_o->weak = FALSE;
        Fast_BinaryExpr_operator_o->id = 2;
        if (db_define(Fast_BinaryExpr_operator_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::BinaryExpr::operator'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::BinaryExpr::rvalue */
    Fast_BinaryExpr_rvalue_o = db_declare(Fast_BinaryExpr_o, "rvalue", db_typedef(db_member_o));
    if (!Fast_BinaryExpr_rvalue_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::BinaryExpr::rvalue'.");
        goto error;
    }

    /* Declare ::hyve::Fast::Binding */
    Fast_Binding_o = db_declare(Fast_o, "Binding", db_typedef(db_struct_o));
    if (!Fast_Binding_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Binding'.");
        goto error;
    }

    /* Declare ::hyve::Fast::Binding::function */
    Fast_Binding_function_o = db_declare(Fast_Binding_o, "function", db_typedef(db_member_o));
    if (!Fast_Binding_function_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Binding::function'.");
        goto error;
    }

    /* Define ::hyve::Fast::Binding::function */
    if (!db_checkState(Fast_Binding_function_o, DB_DEFINED)) {
        Fast_Binding_function_o->type = db_resolve_ext(Fast_Binding_function_o, NULL, "::hyve::lang::function", FALSE, "element ::hyve::Fast::Binding::function.type");
        Fast_Binding_function_o->modifiers = 0x0;
        Fast_Binding_function_o->state = 0x6;
        Fast_Binding_function_o->weak = FALSE;
        Fast_Binding_function_o->id = 0;
        if (db_define(Fast_Binding_function_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Binding::function'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Binding::impl */
    Fast_Binding_impl_o = db_declare(Fast_Binding_o, "impl", db_typedef(db_member_o));
    if (!Fast_Binding_impl_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Binding::impl'.");
        goto error;
    }

    /* Declare ::hyve::Fast::Block */
    Fast_Block_o = db_declare(Fast_o, "Block", db_typedef(db_class_o));
    if (!Fast_Block_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Block'.");
        goto error;
    }

    /* Declare ::hyve::Fast::Block::function */
    Fast_Block_function_o = db_declare(Fast_Block_o, "function", db_typedef(db_member_o));
    if (!Fast_Block_function_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Block::function'.");
        goto error;
    }

    /* Define ::hyve::Fast::Block::function */
    if (!db_checkState(Fast_Block_function_o, DB_DEFINED)) {
        Fast_Block_function_o->type = db_resolve_ext(Fast_Block_function_o, NULL, "::hyve::lang::function", FALSE, "element ::hyve::Fast::Block::function.type");
        Fast_Block_function_o->modifiers = 0x4;
        Fast_Block_function_o->state = 0x6;
        Fast_Block_function_o->weak = FALSE;
        Fast_Block_function_o->id = 3;
        if (db_define(Fast_Block_function_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Block::function'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Block::locals */
    Fast_Block_locals_o = db_declare(Fast_Block_o, "locals", db_typedef(db_member_o));
    if (!Fast_Block_locals_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Block::locals'.");
        goto error;
    }

    /* Declare ::hyve::Fast::Block::parent */
    Fast_Block_parent_o = db_declare(Fast_Block_o, "parent", db_typedef(db_member_o));
    if (!Fast_Block_parent_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Block::parent'.");
        goto error;
    }

    /* Declare ::hyve::Fast::Block::statements */
    Fast_Block_statements_o = db_declare(Fast_Block_o, "statements", db_typedef(db_member_o));
    if (!Fast_Block_statements_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Block::statements'.");
        goto error;
    }

    /* Declare ::hyve::Fast::Block::while */
    Fast_Block_while_o = db_declare(Fast_Block_o, "while", db_typedef(db_member_o));
    if (!Fast_Block_while_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Block::while'.");
        goto error;
    }

    /* Declare ::hyve::Fast::Boolean */
    Fast_Boolean_o = db_declare(Fast_o, "Boolean", db_typedef(db_class_o));
    if (!Fast_Boolean_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Boolean'.");
        goto error;
    }

    /* Declare ::hyve::Fast::Boolean::value */
    Fast_Boolean_value_o = db_declare(Fast_Boolean_o, "value", db_typedef(db_member_o));
    if (!Fast_Boolean_value_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Boolean::value'.");
        goto error;
    }

    /* Define ::hyve::Fast::Boolean::value */
    if (!db_checkState(Fast_Boolean_value_o, DB_DEFINED)) {
        Fast_Boolean_value_o->type = db_resolve_ext(Fast_Boolean_value_o, NULL, "::hyve::lang::bool", FALSE, "element ::hyve::Fast::Boolean::value.type");
        Fast_Boolean_value_o->modifiers = 0x0;
        Fast_Boolean_value_o->state = 0x6;
        Fast_Boolean_value_o->weak = FALSE;
        Fast_Boolean_value_o->id = 0;
        if (db_define(Fast_Boolean_value_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Boolean::value'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Call */
    Fast_Call_o = db_declare(Fast_o, "Call", db_typedef(db_class_o));
    if (!Fast_Call_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Call'.");
        goto error;
    }

    /* Declare ::hyve::Fast::Call::actualFunction */
    Fast_Call_actualFunction_o = db_declare(Fast_Call_o, "actualFunction", db_typedef(db_member_o));
    if (!Fast_Call_actualFunction_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Call::actualFunction'.");
        goto error;
    }

    /* Define ::hyve::Fast::Call::actualFunction */
    if (!db_checkState(Fast_Call_actualFunction_o, DB_DEFINED)) {
        Fast_Call_actualFunction_o->type = db_resolve_ext(Fast_Call_actualFunction_o, NULL, "::hyve::lang::function", FALSE, "element ::hyve::Fast::Call::actualFunction.type");
        Fast_Call_actualFunction_o->modifiers = 0x4;
        Fast_Call_actualFunction_o->state = 0x6;
        Fast_Call_actualFunction_o->weak = FALSE;
        Fast_Call_actualFunction_o->id = 3;
        if (db_define(Fast_Call_actualFunction_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Call::actualFunction'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Call::arguments */
    Fast_Call_arguments_o = db_declare(Fast_Call_o, "arguments", db_typedef(db_member_o));
    if (!Fast_Call_arguments_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Call::arguments'.");
        goto error;
    }

    /* Declare ::hyve::Fast::Call::function */
    Fast_Call_function_o = db_declare(Fast_Call_o, "function", db_typedef(db_member_o));
    if (!Fast_Call_function_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Call::function'.");
        goto error;
    }

    /* Declare ::hyve::Fast::Call::signature */
    Fast_Call_signature_o = db_declare(Fast_Call_o, "signature", db_typedef(db_member_o));
    if (!Fast_Call_signature_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Call::signature'.");
        goto error;
    }

    /* Define ::hyve::Fast::Call::signature */
    if (!db_checkState(Fast_Call_signature_o, DB_DEFINED)) {
        Fast_Call_signature_o->type = db_resolve_ext(Fast_Call_signature_o, NULL, "::hyve::lang::string", FALSE, "element ::hyve::Fast::Call::signature.type");
        Fast_Call_signature_o->modifiers = 0x4;
        Fast_Call_signature_o->state = 0x6;
        Fast_Call_signature_o->weak = FALSE;
        Fast_Call_signature_o->id = 2;
        if (db_define(Fast_Call_signature_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Call::signature'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::CastExpr */
    Fast_CastExpr_o = db_declare(Fast_o, "CastExpr", db_typedef(db_class_o));
    if (!Fast_CastExpr_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::CastExpr'.");
        goto error;
    }

    /* Declare ::hyve::Fast::CastExpr::lvalue */
    Fast_CastExpr_lvalue_o = db_declare(Fast_CastExpr_o, "lvalue", db_typedef(db_member_o));
    if (!Fast_CastExpr_lvalue_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::CastExpr::lvalue'.");
        goto error;
    }

    /* Declare ::hyve::Fast::CastExpr::rvalue */
    Fast_CastExpr_rvalue_o = db_declare(Fast_CastExpr_o, "rvalue", db_typedef(db_member_o));
    if (!Fast_CastExpr_rvalue_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::CastExpr::rvalue'.");
        goto error;
    }

    /* Declare ::hyve::Fast::Character */
    Fast_Character_o = db_declare(Fast_o, "Character", db_typedef(db_class_o));
    if (!Fast_Character_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Character'.");
        goto error;
    }

    /* Declare ::hyve::Fast::Character::value */
    Fast_Character_value_o = db_declare(Fast_Character_o, "value", db_typedef(db_member_o));
    if (!Fast_Character_value_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Character::value'.");
        goto error;
    }

    /* Define ::hyve::Fast::Character::value */
    if (!db_checkState(Fast_Character_value_o, DB_DEFINED)) {
        Fast_Character_value_o->type = db_resolve_ext(Fast_Character_value_o, NULL, "::hyve::lang::char", FALSE, "element ::hyve::Fast::Character::value.type");
        Fast_Character_value_o->modifiers = 0x0;
        Fast_Character_value_o->state = 0x6;
        Fast_Character_value_o->weak = FALSE;
        Fast_Character_value_o->id = 0;
        if (db_define(Fast_Character_value_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Character::value'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::CommaExpr */
    Fast_CommaExpr_o = db_declare(Fast_o, "CommaExpr", db_typedef(db_class_o));
    if (!Fast_CommaExpr_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::CommaExpr'.");
        goto error;
    }

    /* Declare ::hyve::Fast::CommaExpr::expressions */
    Fast_CommaExpr_expressions_o = db_declare(Fast_CommaExpr_o, "expressions", db_typedef(db_member_o));
    if (!Fast_CommaExpr_expressions_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::CommaExpr::expressions'.");
        goto error;
    }

    /* Declare ::hyve::Fast::Define */
    Fast_Define_o = db_declare(Fast_o, "Define", db_typedef(db_class_o));
    if (!Fast_Define_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Define'.");
        goto error;
    }

    /* Declare ::hyve::Fast::Define::object */
    Fast_Define_object_o = db_declare(Fast_Define_o, "object", db_typedef(db_member_o));
    if (!Fast_Define_object_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Define::object'.");
        goto error;
    }

    /* Declare ::hyve::Fast::DynamicInitializer */
    Fast_DynamicInitializer_o = db_declare(Fast_o, "DynamicInitializer", db_typedef(db_class_o));
    if (!Fast_DynamicInitializer_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::DynamicInitializer'.");
        goto error;
    }

    /* Declare ::hyve::Fast::DynamicInitializer::assignValue */
    Fast_DynamicInitializer_assignValue_o = db_declare(Fast_DynamicInitializer_o, "assignValue", db_typedef(db_member_o));
    if (!Fast_DynamicInitializer_assignValue_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::DynamicInitializer::assignValue'.");
        goto error;
    }

    /* Define ::hyve::Fast::DynamicInitializer::assignValue */
    if (!db_checkState(Fast_DynamicInitializer_assignValue_o, DB_DEFINED)) {
        Fast_DynamicInitializer_assignValue_o->type = db_resolve_ext(Fast_DynamicInitializer_assignValue_o, NULL, "::hyve::lang::bool", FALSE, "element ::hyve::Fast::DynamicInitializer::assignValue.type");
        Fast_DynamicInitializer_assignValue_o->modifiers = 0x0;
        Fast_DynamicInitializer_assignValue_o->state = 0x6;
        Fast_DynamicInitializer_assignValue_o->weak = FALSE;
        Fast_DynamicInitializer_assignValue_o->id = 0;
        if (db_define(Fast_DynamicInitializer_assignValue_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::DynamicInitializer::assignValue'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::DynamicInitializer::frames */
    Fast_DynamicInitializer_frames_o = db_declare(Fast_DynamicInitializer_o, "frames", db_typedef(db_member_o));
    if (!Fast_DynamicInitializer_frames_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::DynamicInitializer::frames'.");
        goto error;
    }

    /* Declare ::hyve::Fast::DynamicInitializerFrame */
    Fast_DynamicInitializerFrame_o = db_declare(Fast_o, "DynamicInitializerFrame", db_typedef(db_struct_o));
    if (!Fast_DynamicInitializerFrame_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::DynamicInitializerFrame'.");
        goto error;
    }

    /* Declare ::hyve::Fast::DynamicInitializerFrame::expr */
    Fast_DynamicInitializerFrame_expr_o = db_declare(Fast_DynamicInitializerFrame_o, "expr", db_typedef(db_member_o));
    if (!Fast_DynamicInitializerFrame_expr_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::DynamicInitializerFrame::expr'.");
        goto error;
    }

    /* Declare ::hyve::Fast::DynamicInitializerFrame::keyExpr */
    Fast_DynamicInitializerFrame_keyExpr_o = db_declare(Fast_DynamicInitializerFrame_o, "keyExpr", db_typedef(db_member_o));
    if (!Fast_DynamicInitializerFrame_keyExpr_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::DynamicInitializerFrame::keyExpr'.");
        goto error;
    }

    /* Declare ::hyve::Fast::DynamicInitializerFrame::sequenceSize */
    Fast_DynamicInitializerFrame_sequenceSize_o = db_declare(Fast_DynamicInitializerFrame_o, "sequenceSize", db_typedef(db_member_o));
    if (!Fast_DynamicInitializerFrame_sequenceSize_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::DynamicInitializerFrame::sequenceSize'.");
        goto error;
    }

    /* Declare ::hyve::Fast::ElementExpr */
    Fast_ElementExpr_o = db_declare(Fast_o, "ElementExpr", db_typedef(db_class_o));
    if (!Fast_ElementExpr_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::ElementExpr'.");
        goto error;
    }

    /* Declare ::hyve::Fast::ElementExpr::lvalue */
    Fast_ElementExpr_lvalue_o = db_declare(Fast_ElementExpr_o, "lvalue", db_typedef(db_member_o));
    if (!Fast_ElementExpr_lvalue_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::ElementExpr::lvalue'.");
        goto error;
    }

    /* Declare ::hyve::Fast::ElementExpr::rvalue */
    Fast_ElementExpr_rvalue_o = db_declare(Fast_ElementExpr_o, "rvalue", db_typedef(db_member_o));
    if (!Fast_ElementExpr_rvalue_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::ElementExpr::rvalue'.");
        goto error;
    }

    /* Declare ::hyve::Fast::Expression */
    Fast_Expression_o = db_declare(Fast_o, "Expression", db_typedef(db_class_o));
    if (!Fast_Expression_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Expression'.");
        goto error;
    }

    /* Declare ::hyve::Fast::Expression::forceReference */
    Fast_Expression_forceReference_o = db_declare(Fast_Expression_o, "forceReference", db_typedef(db_member_o));
    if (!Fast_Expression_forceReference_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Expression::forceReference'.");
        goto error;
    }

    /* Define ::hyve::Fast::Expression::forceReference */
    if (!db_checkState(Fast_Expression_forceReference_o, DB_DEFINED)) {
        Fast_Expression_forceReference_o->type = db_resolve_ext(Fast_Expression_forceReference_o, NULL, "::hyve::lang::bool", FALSE, "element ::hyve::Fast::Expression::forceReference.type");
        Fast_Expression_forceReference_o->modifiers = 0x4;
        Fast_Expression_forceReference_o->state = 0x6;
        Fast_Expression_forceReference_o->weak = FALSE;
        Fast_Expression_forceReference_o->id = 2;
        if (db_define(Fast_Expression_forceReference_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Expression::forceReference'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Expression::isReference */
    Fast_Expression_isReference_o = db_declare(Fast_Expression_o, "isReference", db_typedef(db_member_o));
    if (!Fast_Expression_isReference_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Expression::isReference'.");
        goto error;
    }

    /* Define ::hyve::Fast::Expression::isReference */
    if (!db_checkState(Fast_Expression_isReference_o, DB_DEFINED)) {
        Fast_Expression_isReference_o->type = db_resolve_ext(Fast_Expression_isReference_o, NULL, "::hyve::lang::bool", FALSE, "element ::hyve::Fast::Expression::isReference.type");
        Fast_Expression_isReference_o->modifiers = 0x4;
        Fast_Expression_isReference_o->state = 0x6;
        Fast_Expression_isReference_o->weak = FALSE;
        Fast_Expression_isReference_o->id = 1;
        if (db_define(Fast_Expression_isReference_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Expression::isReference'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Expression::type */
    Fast_Expression_type_o = db_declare(Fast_Expression_o, "type", db_typedef(db_member_o));
    if (!Fast_Expression_type_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Expression::type'.");
        goto error;
    }

    /* Define ::hyve::Fast::CommaExpr::expressions */
    if (!db_checkState(Fast_CommaExpr_expressions_o, DB_DEFINED)) {
        Fast_CommaExpr_expressions_o->type = db_resolve_ext(Fast_CommaExpr_expressions_o, NULL, "::hyve::lang::list{::hyve::Fast::Expression,0}", FALSE, "element ::hyve::Fast::CommaExpr::expressions.type");
        Fast_CommaExpr_expressions_o->modifiers = 0x2;
        Fast_CommaExpr_expressions_o->state = 0x6;
        Fast_CommaExpr_expressions_o->weak = FALSE;
        Fast_CommaExpr_expressions_o->id = 0;
        if (db_define(Fast_CommaExpr_expressions_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::CommaExpr::expressions'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Expression::cleanList(list{Expression} list) */
    Fast_Expression_cleanList_o = db_declare(Fast_Expression_o, "cleanList(list{Expression} list)", db_typedef(db_function_o));
    if (!Fast_Expression_cleanList_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Expression::cleanList(list{Expression} list)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Expression::cleanList(list{Expression} list) */
    if (!db_checkState(Fast_Expression_cleanList_o, DB_DEFINED)) {
        Fast_Expression_cleanList_o->returnType = NULL;
        Fast_Expression_cleanList_o->returnsReference = FALSE;
        
        /* Bind Fast_Expression_cleanList_o with C-function */
        db_function(Fast_Expression_cleanList_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Expression_cleanList(void *args, void *result);
        db_function(Fast_Expression_cleanList_o)->impl = (db_word)__Fast_Expression_cleanList;
        if (db_define(Fast_Expression_cleanList_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Expression::cleanList(list{Expression} list)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Expression::fromList(list{Expression} list) */
    Fast_Expression_fromList_o = db_declare(Fast_Expression_o, "fromList(list{Expression} list)", db_typedef(db_function_o));
    if (!Fast_Expression_fromList_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Expression::fromList(list{Expression} list)'.");
        goto error;
    }

    /* Declare ::hyve::Fast::FloatingPoint */
    Fast_FloatingPoint_o = db_declare(Fast_o, "FloatingPoint", db_typedef(db_class_o));
    if (!Fast_FloatingPoint_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::FloatingPoint'.");
        goto error;
    }

    /* Declare ::hyve::Fast::FloatingPoint::value */
    Fast_FloatingPoint_value_o = db_declare(Fast_FloatingPoint_o, "value", db_typedef(db_member_o));
    if (!Fast_FloatingPoint_value_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::FloatingPoint::value'.");
        goto error;
    }

    /* Define ::hyve::Fast::FloatingPoint::value */
    if (!db_checkState(Fast_FloatingPoint_value_o, DB_DEFINED)) {
        Fast_FloatingPoint_value_o->type = db_resolve_ext(Fast_FloatingPoint_value_o, NULL, "::hyve::lang::float64", FALSE, "element ::hyve::Fast::FloatingPoint::value.type");
        Fast_FloatingPoint_value_o->modifiers = 0x0;
        Fast_FloatingPoint_value_o->state = 0x6;
        Fast_FloatingPoint_value_o->weak = FALSE;
        Fast_FloatingPoint_value_o->id = 0;
        if (db_define(Fast_FloatingPoint_value_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::FloatingPoint::value'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::If */
    Fast_If_o = db_declare(Fast_o, "If", db_typedef(db_class_o));
    if (!Fast_If_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::If'.");
        goto error;
    }

    /* Declare ::hyve::Fast::If::condition */
    Fast_If_condition_o = db_declare(Fast_If_o, "condition", db_typedef(db_member_o));
    if (!Fast_If_condition_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::If::condition'.");
        goto error;
    }

    /* Declare ::hyve::Fast::If::falseBranch */
    Fast_If_falseBranch_o = db_declare(Fast_If_o, "falseBranch", db_typedef(db_member_o));
    if (!Fast_If_falseBranch_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::If::falseBranch'.");
        goto error;
    }

    /* Declare ::hyve::Fast::If::trueBranch */
    Fast_If_trueBranch_o = db_declare(Fast_If_o, "trueBranch", db_typedef(db_member_o));
    if (!Fast_If_trueBranch_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::If::trueBranch'.");
        goto error;
    }

    /* Declare ::hyve::Fast::If::warnUnreachable */
    Fast_If_warnUnreachable_o = db_declare(Fast_If_o, "warnUnreachable", db_typedef(db_member_o));
    if (!Fast_If_warnUnreachable_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::If::warnUnreachable'.");
        goto error;
    }

    /* Define ::hyve::Fast::If::warnUnreachable */
    if (!db_checkState(Fast_If_warnUnreachable_o, DB_DEFINED)) {
        Fast_If_warnUnreachable_o->type = db_resolve_ext(Fast_If_warnUnreachable_o, NULL, "::hyve::lang::bool", FALSE, "element ::hyve::Fast::If::warnUnreachable.type");
        Fast_If_warnUnreachable_o->modifiers = 0x3;
        Fast_If_warnUnreachable_o->state = 0x6;
        Fast_If_warnUnreachable_o->weak = FALSE;
        Fast_If_warnUnreachable_o->id = 3;
        if (db_define(Fast_If_warnUnreachable_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::If::warnUnreachable'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Initializer */
    Fast_Initializer_o = db_declare(Fast_o, "Initializer", db_typedef(db_class_o));
    if (!Fast_Initializer_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Initializer'.");
        goto error;
    }

    /* Declare ::hyve::Fast::Initializer::fp */
    Fast_Initializer_fp_o = db_declare(Fast_Initializer_o, "fp", db_typedef(db_member_o));
    if (!Fast_Initializer_fp_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Initializer::fp'.");
        goto error;
    }

    /* Define ::hyve::Fast::Initializer::fp */
    if (!db_checkState(Fast_Initializer_fp_o, DB_DEFINED)) {
        Fast_Initializer_fp_o->type = db_resolve_ext(Fast_Initializer_fp_o, NULL, "::hyve::lang::uint8", FALSE, "element ::hyve::Fast::Initializer::fp.type");
        Fast_Initializer_fp_o->modifiers = 0x3;
        Fast_Initializer_fp_o->state = 0x6;
        Fast_Initializer_fp_o->weak = FALSE;
        Fast_Initializer_fp_o->id = 3;
        if (db_define(Fast_Initializer_fp_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Initializer::fp'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Initializer::frames */
    Fast_Initializer_frames_o = db_declare(Fast_Initializer_o, "frames", db_typedef(db_member_o));
    if (!Fast_Initializer_frames_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Initializer::frames'.");
        goto error;
    }

    /* Declare ::hyve::Fast::Initializer::variableCount */
    Fast_Initializer_variableCount_o = db_declare(Fast_Initializer_o, "variableCount", db_typedef(db_member_o));
    if (!Fast_Initializer_variableCount_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Initializer::variableCount'.");
        goto error;
    }

    /* Define ::hyve::Fast::Initializer::variableCount */
    if (!db_checkState(Fast_Initializer_variableCount_o, DB_DEFINED)) {
        Fast_Initializer_variableCount_o->type = db_resolve_ext(Fast_Initializer_variableCount_o, NULL, "::hyve::lang::uint8", FALSE, "element ::hyve::Fast::Initializer::variableCount.type");
        Fast_Initializer_variableCount_o->modifiers = 0x0;
        Fast_Initializer_variableCount_o->state = 0x6;
        Fast_Initializer_variableCount_o->weak = FALSE;
        Fast_Initializer_variableCount_o->id = 1;
        if (db_define(Fast_Initializer_variableCount_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Initializer::variableCount'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Initializer::variables */
    Fast_Initializer_variables_o = db_declare(Fast_Initializer_o, "variables", db_typedef(db_member_o));
    if (!Fast_Initializer_variables_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Initializer::variables'.");
        goto error;
    }

    /* Declare ::hyve::Fast::InitializerExpr */
    Fast_InitializerExpr_o = db_declare(Fast_o, "InitializerExpr", db_typedef(db_class_o));
    if (!Fast_InitializerExpr_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::InitializerExpr'.");
        goto error;
    }

    /* Declare ::hyve::Fast::InitializerExpr::assignValue */
    Fast_InitializerExpr_assignValue_o = db_declare(Fast_InitializerExpr_o, "assignValue", db_typedef(db_member_o));
    if (!Fast_InitializerExpr_assignValue_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::InitializerExpr::assignValue'.");
        goto error;
    }

    /* Define ::hyve::Fast::InitializerExpr::assignValue */
    if (!db_checkState(Fast_InitializerExpr_assignValue_o, DB_DEFINED)) {
        Fast_InitializerExpr_assignValue_o->type = db_resolve_ext(Fast_InitializerExpr_assignValue_o, NULL, "::hyve::lang::bool", FALSE, "element ::hyve::Fast::InitializerExpr::assignValue.type");
        Fast_InitializerExpr_assignValue_o->modifiers = 0x0;
        Fast_InitializerExpr_assignValue_o->state = 0x6;
        Fast_InitializerExpr_assignValue_o->weak = FALSE;
        Fast_InitializerExpr_assignValue_o->id = 0;
        if (db_define(Fast_InitializerExpr_assignValue_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::InitializerExpr::assignValue'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::InitializerExpr::operations */
    Fast_InitializerExpr_operations_o = db_declare(Fast_InitializerExpr_o, "operations", db_typedef(db_member_o));
    if (!Fast_InitializerExpr_operations_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::InitializerExpr::operations'.");
        goto error;
    }

    /* Declare ::hyve::Fast::InitializerFrame */
    Fast_InitializerFrame_o = db_declare(Fast_o, "InitializerFrame", db_typedef(db_struct_o));
    if (!Fast_InitializerFrame_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::InitializerFrame'.");
        goto error;
    }

    /* Declare ::hyve::Fast::InitializerFrame::isKey */
    Fast_InitializerFrame_isKey_o = db_declare(Fast_InitializerFrame_o, "isKey", db_typedef(db_member_o));
    if (!Fast_InitializerFrame_isKey_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::InitializerFrame::isKey'.");
        goto error;
    }

    /* Define ::hyve::Fast::InitializerFrame::isKey */
    if (!db_checkState(Fast_InitializerFrame_isKey_o, DB_DEFINED)) {
        Fast_InitializerFrame_isKey_o->type = db_resolve_ext(Fast_InitializerFrame_isKey_o, NULL, "::hyve::lang::bool", FALSE, "element ::hyve::Fast::InitializerFrame::isKey.type");
        Fast_InitializerFrame_isKey_o->modifiers = 0x0;
        Fast_InitializerFrame_isKey_o->state = 0x6;
        Fast_InitializerFrame_isKey_o->weak = FALSE;
        Fast_InitializerFrame_isKey_o->id = 2;
        if (db_define(Fast_InitializerFrame_isKey_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::InitializerFrame::isKey'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::InitializerFrame::location */
    Fast_InitializerFrame_location_o = db_declare(Fast_InitializerFrame_o, "location", db_typedef(db_member_o));
    if (!Fast_InitializerFrame_location_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::InitializerFrame::location'.");
        goto error;
    }

    /* Define ::hyve::Fast::InitializerFrame::location */
    if (!db_checkState(Fast_InitializerFrame_location_o, DB_DEFINED)) {
        Fast_InitializerFrame_location_o->type = db_resolve_ext(Fast_InitializerFrame_location_o, NULL, "::hyve::lang::uint32", FALSE, "element ::hyve::Fast::InitializerFrame::location.type");
        Fast_InitializerFrame_location_o->modifiers = 0x0;
        Fast_InitializerFrame_location_o->state = 0x6;
        Fast_InitializerFrame_location_o->weak = FALSE;
        Fast_InitializerFrame_location_o->id = 0;
        if (db_define(Fast_InitializerFrame_location_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::InitializerFrame::location'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::InitializerFrame::member */
    Fast_InitializerFrame_member_o = db_declare(Fast_InitializerFrame_o, "member", db_typedef(db_member_o));
    if (!Fast_InitializerFrame_member_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::InitializerFrame::member'.");
        goto error;
    }

    /* Define ::hyve::Fast::InitializerFrame::member */
    if (!db_checkState(Fast_InitializerFrame_member_o, DB_DEFINED)) {
        Fast_InitializerFrame_member_o->type = db_resolve_ext(Fast_InitializerFrame_member_o, NULL, "::hyve::lang::member", FALSE, "element ::hyve::Fast::InitializerFrame::member.type");
        Fast_InitializerFrame_member_o->modifiers = 0x0;
        Fast_InitializerFrame_member_o->state = 0x6;
        Fast_InitializerFrame_member_o->weak = FALSE;
        Fast_InitializerFrame_member_o->id = 3;
        if (db_define(Fast_InitializerFrame_member_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::InitializerFrame::member'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::InitializerFrame::type */
    Fast_InitializerFrame_type_o = db_declare(Fast_InitializerFrame_o, "type", db_typedef(db_member_o));
    if (!Fast_InitializerFrame_type_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::InitializerFrame::type'.");
        goto error;
    }

    /* Define ::hyve::Fast::InitializerFrame::type */
    if (!db_checkState(Fast_InitializerFrame_type_o, DB_DEFINED)) {
        Fast_InitializerFrame_type_o->type = db_resolve_ext(Fast_InitializerFrame_type_o, NULL, "::hyve::lang::type", FALSE, "element ::hyve::Fast::InitializerFrame::type.type");
        Fast_InitializerFrame_type_o->modifiers = 0x0;
        Fast_InitializerFrame_type_o->state = 0x6;
        Fast_InitializerFrame_type_o->weak = FALSE;
        Fast_InitializerFrame_type_o->id = 1;
        if (db_define(Fast_InitializerFrame_type_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::InitializerFrame::type'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::InitializerFrame */
    if (!db_checkState(Fast_InitializerFrame_o, DB_DEFINED)) {
        db_type(Fast_InitializerFrame_o)->defaultType = db_resolve_ext(Fast_InitializerFrame_o, NULL, "::hyve::lang::member", FALSE, "element ::hyve::Fast::InitializerFrame.defaultType");
        db_type(Fast_InitializerFrame_o)->parentType = NULL;
        db_type(Fast_InitializerFrame_o)->parentState = 0x0;
        db_interface(Fast_InitializerFrame_o)->base = NULL;
        Fast_InitializerFrame_o->baseAccess = 0x0;
        if (db_define(Fast_InitializerFrame_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::InitializerFrame'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::Initializer::frames */
    if (!db_checkState(Fast_Initializer_frames_o, DB_DEFINED)) {
        Fast_Initializer_frames_o->type = db_resolve_ext(Fast_Initializer_frames_o, NULL, "::hyve::lang::array{::hyve::Fast::InitializerFrame,64,::hyve::Fast::InitializerFrame}", FALSE, "element ::hyve::Fast::Initializer::frames.type");
        Fast_Initializer_frames_o->modifiers = 0x3;
        Fast_Initializer_frames_o->state = 0x6;
        Fast_Initializer_frames_o->weak = FALSE;
        Fast_Initializer_frames_o->id = 2;
        if (db_define(Fast_Initializer_frames_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Initializer::frames'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::InitializerKind */
    Fast_InitializerKind_o = db_declare(Fast_o, "InitializerKind", db_typedef(db_enum_o));
    if (!Fast_InitializerKind_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::InitializerKind'.");
        goto error;
    }

    /* Declare ::hyve::Fast::InitializerKind::InitDynamic */
    Fast_InitializerKind_InitDynamic_o = db_declare(Fast_InitializerKind_o, "InitDynamic", db_typedef(db_constant_o));
    if (!Fast_InitializerKind_InitDynamic_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::InitializerKind::InitDynamic'.");
        goto error;
    }

    /* Define ::hyve::Fast::InitializerKind::InitDynamic */
    if (!db_checkState(Fast_InitializerKind_InitDynamic_o, DB_DEFINED)) {
        (*Fast_InitializerKind_InitDynamic_o) = 1;
        if (db_define(Fast_InitializerKind_InitDynamic_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::InitializerKind::InitDynamic'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::InitializerKind::InitExpression */
    Fast_InitializerKind_InitExpression_o = db_declare(Fast_InitializerKind_o, "InitExpression", db_typedef(db_constant_o));
    if (!Fast_InitializerKind_InitExpression_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::InitializerKind::InitExpression'.");
        goto error;
    }

    /* Define ::hyve::Fast::InitializerKind::InitExpression */
    if (!db_checkState(Fast_InitializerKind_InitExpression_o, DB_DEFINED)) {
        (*Fast_InitializerKind_InitExpression_o) = 2;
        if (db_define(Fast_InitializerKind_InitExpression_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::InitializerKind::InitExpression'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::InitializerKind::InitStatic */
    Fast_InitializerKind_InitStatic_o = db_declare(Fast_InitializerKind_o, "InitStatic", db_typedef(db_constant_o));
    if (!Fast_InitializerKind_InitStatic_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::InitializerKind::InitStatic'.");
        goto error;
    }

    /* Define ::hyve::Fast::InitializerKind::InitStatic */
    if (!db_checkState(Fast_InitializerKind_InitStatic_o, DB_DEFINED)) {
        (*Fast_InitializerKind_InitStatic_o) = 0;
        if (db_define(Fast_InitializerKind_InitStatic_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::InitializerKind::InitStatic'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::InitializerKind */
    if (!db_checkState(Fast_InitializerKind_o, DB_DEFINED)) {
        if (db_define(Fast_InitializerKind_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::InitializerKind'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::InitializerVariable */
    Fast_InitializerVariable_o = db_declare(Fast_o, "InitializerVariable", db_typedef(db_struct_o));
    if (!Fast_InitializerVariable_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::InitializerVariable'.");
        goto error;
    }

    /* Declare ::hyve::Fast::InitializerVariable::key */
    Fast_InitializerVariable_key_o = db_declare(Fast_InitializerVariable_o, "key", db_typedef(db_member_o));
    if (!Fast_InitializerVariable_key_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::InitializerVariable::key'.");
        goto error;
    }

    /* Define ::hyve::Fast::InitializerVariable::key */
    if (!db_checkState(Fast_InitializerVariable_key_o, DB_DEFINED)) {
        Fast_InitializerVariable_key_o->type = db_resolve_ext(Fast_InitializerVariable_key_o, NULL, "::hyve::lang::word", FALSE, "element ::hyve::Fast::InitializerVariable::key.type");
        Fast_InitializerVariable_key_o->modifiers = 0x0;
        Fast_InitializerVariable_key_o->state = 0x6;
        Fast_InitializerVariable_key_o->weak = FALSE;
        Fast_InitializerVariable_key_o->id = 2;
        if (db_define(Fast_InitializerVariable_key_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::InitializerVariable::key'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::InitializerVariable::object */
    Fast_InitializerVariable_object_o = db_declare(Fast_InitializerVariable_o, "object", db_typedef(db_member_o));
    if (!Fast_InitializerVariable_object_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::InitializerVariable::object'.");
        goto error;
    }

    /* Declare ::hyve::Fast::InitializerVariable::offset */
    Fast_InitializerVariable_offset_o = db_declare(Fast_InitializerVariable_o, "offset", db_typedef(db_member_o));
    if (!Fast_InitializerVariable_offset_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::InitializerVariable::offset'.");
        goto error;
    }

    /* Define ::hyve::Fast::InitializerVariable::offset */
    if (!db_checkState(Fast_InitializerVariable_offset_o, DB_DEFINED)) {
        Fast_InitializerVariable_offset_o->type = db_resolve_ext(Fast_InitializerVariable_offset_o, NULL, "::hyve::lang::word", FALSE, "element ::hyve::Fast::InitializerVariable::offset.type");
        Fast_InitializerVariable_offset_o->modifiers = 0x0;
        Fast_InitializerVariable_offset_o->state = 0x6;
        Fast_InitializerVariable_offset_o->weak = FALSE;
        Fast_InitializerVariable_offset_o->id = 0;
        if (db_define(Fast_InitializerVariable_offset_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::InitializerVariable::offset'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::InitOper */
    Fast_InitOper_o = db_declare(Fast_o, "InitOper", db_typedef(db_struct_o));
    if (!Fast_InitOper_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::InitOper'.");
        goto error;
    }

    /* Declare ::hyve::Fast::InitOper::expr */
    Fast_InitOper_expr_o = db_declare(Fast_InitOper_o, "expr", db_typedef(db_member_o));
    if (!Fast_InitOper_expr_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::InitOper::expr'.");
        goto error;
    }

    /* Declare ::hyve::Fast::InitOper::kind */
    Fast_InitOper_kind_o = db_declare(Fast_InitOper_o, "kind", db_typedef(db_member_o));
    if (!Fast_InitOper_kind_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::InitOper::kind'.");
        goto error;
    }

    /* Declare ::hyve::Fast::InitOper::name */
    Fast_InitOper_name_o = db_declare(Fast_InitOper_o, "name", db_typedef(db_member_o));
    if (!Fast_InitOper_name_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::InitOper::name'.");
        goto error;
    }

    /* Define ::hyve::Fast::InitOper::name */
    if (!db_checkState(Fast_InitOper_name_o, DB_DEFINED)) {
        Fast_InitOper_name_o->type = db_resolve_ext(Fast_InitOper_name_o, NULL, "::hyve::lang::string", FALSE, "element ::hyve::Fast::InitOper::name.type");
        Fast_InitOper_name_o->modifiers = 0x0;
        Fast_InitOper_name_o->state = 0x6;
        Fast_InitOper_name_o->weak = FALSE;
        Fast_InitOper_name_o->id = 2;
        if (db_define(Fast_InitOper_name_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::InitOper::name'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::InitializerExpr::operations */
    if (!db_checkState(Fast_InitializerExpr_operations_o, DB_DEFINED)) {
        Fast_InitializerExpr_operations_o->type = db_resolve_ext(Fast_InitializerExpr_operations_o, NULL, "::hyve::lang::list{::hyve::Fast::InitOper,0}", FALSE, "element ::hyve::Fast::InitializerExpr::operations.type");
        Fast_InitializerExpr_operations_o->modifiers = 0x3;
        Fast_InitializerExpr_operations_o->state = 0x6;
        Fast_InitializerExpr_operations_o->weak = FALSE;
        Fast_InitializerExpr_operations_o->id = 1;
        if (db_define(Fast_InitializerExpr_operations_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::InitializerExpr::operations'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::InitOperKind */
    Fast_InitOperKind_o = db_declare(Fast_o, "InitOperKind", db_typedef(db_enum_o));
    if (!Fast_InitOperKind_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::InitOperKind'.");
        goto error;
    }

    /* Declare ::hyve::Fast::InitOperKind::InitDefine */
    Fast_InitOperKind_InitDefine_o = db_declare(Fast_InitOperKind_o, "InitDefine", db_typedef(db_constant_o));
    if (!Fast_InitOperKind_InitDefine_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::InitOperKind::InitDefine'.");
        goto error;
    }

    /* Define ::hyve::Fast::InitOperKind::InitDefine */
    if (!db_checkState(Fast_InitOperKind_InitDefine_o, DB_DEFINED)) {
        (*Fast_InitOperKind_InitDefine_o) = 2;
        if (db_define(Fast_InitOperKind_InitDefine_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::InitOperKind::InitDefine'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::InitOperKind::InitMember */
    Fast_InitOperKind_InitMember_o = db_declare(Fast_InitOperKind_o, "InitMember", db_typedef(db_constant_o));
    if (!Fast_InitOperKind_InitMember_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::InitOperKind::InitMember'.");
        goto error;
    }

    /* Define ::hyve::Fast::InitOperKind::InitMember */
    if (!db_checkState(Fast_InitOperKind_InitMember_o, DB_DEFINED)) {
        (*Fast_InitOperKind_InitMember_o) = 4;
        if (db_define(Fast_InitOperKind_InitMember_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::InitOperKind::InitMember'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::InitOperKind::InitPop */
    Fast_InitOperKind_InitPop_o = db_declare(Fast_InitOperKind_o, "InitPop", db_typedef(db_constant_o));
    if (!Fast_InitOperKind_InitPop_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::InitOperKind::InitPop'.");
        goto error;
    }

    /* Define ::hyve::Fast::InitOperKind::InitPop */
    if (!db_checkState(Fast_InitOperKind_InitPop_o, DB_DEFINED)) {
        (*Fast_InitOperKind_InitPop_o) = 1;
        if (db_define(Fast_InitOperKind_InitPop_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::InitOperKind::InitPop'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::InitOperKind::InitPush */
    Fast_InitOperKind_InitPush_o = db_declare(Fast_InitOperKind_o, "InitPush", db_typedef(db_constant_o));
    if (!Fast_InitOperKind_InitPush_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::InitOperKind::InitPush'.");
        goto error;
    }

    /* Define ::hyve::Fast::InitOperKind::InitPush */
    if (!db_checkState(Fast_InitOperKind_InitPush_o, DB_DEFINED)) {
        (*Fast_InitOperKind_InitPush_o) = 0;
        if (db_define(Fast_InitOperKind_InitPush_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::InitOperKind::InitPush'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::InitOperKind::InitValue */
    Fast_InitOperKind_InitValue_o = db_declare(Fast_InitOperKind_o, "InitValue", db_typedef(db_constant_o));
    if (!Fast_InitOperKind_InitValue_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::InitOperKind::InitValue'.");
        goto error;
    }

    /* Define ::hyve::Fast::InitOperKind::InitValue */
    if (!db_checkState(Fast_InitOperKind_InitValue_o, DB_DEFINED)) {
        (*Fast_InitOperKind_InitValue_o) = 3;
        if (db_define(Fast_InitOperKind_InitValue_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::InitOperKind::InitValue'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::InitOperKind */
    if (!db_checkState(Fast_InitOperKind_o, DB_DEFINED)) {
        if (db_define(Fast_InitOperKind_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::InitOperKind'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::InitOper::kind */
    if (!db_checkState(Fast_InitOper_kind_o, DB_DEFINED)) {
        Fast_InitOper_kind_o->type = db_resolve_ext(Fast_InitOper_kind_o, NULL, "::hyve::Fast::InitOperKind", FALSE, "element ::hyve::Fast::InitOper::kind.type");
        Fast_InitOper_kind_o->modifiers = 0x0;
        Fast_InitOper_kind_o->state = 0x6;
        Fast_InitOper_kind_o->weak = FALSE;
        Fast_InitOper_kind_o->id = 0;
        if (db_define(Fast_InitOper_kind_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::InitOper::kind'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Integer */
    Fast_Integer_o = db_declare(Fast_o, "Integer", db_typedef(db_class_o));
    if (!Fast_Integer_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Integer'.");
        goto error;
    }

    /* Declare ::hyve::Fast::Integer::value */
    Fast_Integer_value_o = db_declare(Fast_Integer_o, "value", db_typedef(db_member_o));
    if (!Fast_Integer_value_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Integer::value'.");
        goto error;
    }

    /* Define ::hyve::Fast::Integer::value */
    if (!db_checkState(Fast_Integer_value_o, DB_DEFINED)) {
        Fast_Integer_value_o->type = db_resolve_ext(Fast_Integer_value_o, NULL, "::hyve::lang::uint64", FALSE, "element ::hyve::Fast::Integer::value.type");
        Fast_Integer_value_o->modifiers = 0x0;
        Fast_Integer_value_o->state = 0x6;
        Fast_Integer_value_o->weak = FALSE;
        Fast_Integer_value_o->id = 0;
        if (db_define(Fast_Integer_value_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Integer::value'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Literal */
    Fast_Literal_o = db_declare(Fast_o, "Literal", db_typedef(db_class_o));
    if (!Fast_Literal_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Literal'.");
        goto error;
    }

    /* Declare ::hyve::Fast::Literal::kind */
    Fast_Literal_kind_o = db_declare(Fast_Literal_o, "kind", db_typedef(db_member_o));
    if (!Fast_Literal_kind_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Literal::kind'.");
        goto error;
    }

    /* Declare ::hyve::Fast::Local */
    Fast_Local_o = db_declare(Fast_o, "Local", db_typedef(db_class_o));
    if (!Fast_Local_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Local'.");
        goto error;
    }

    /* Declare ::hyve::Fast::Local::isReference */
    Fast_Local_isReference_o = db_declare(Fast_Local_o, "isReference", db_typedef(db_member_o));
    if (!Fast_Local_isReference_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Local::isReference'.");
        goto error;
    }

    /* Define ::hyve::Fast::Local::isReference */
    if (!db_checkState(Fast_Local_isReference_o, DB_DEFINED)) {
        Fast_Local_isReference_o->type = db_resolve_ext(Fast_Local_isReference_o, NULL, "::hyve::lang::bool", FALSE, "element ::hyve::Fast::Local::isReference.type");
        Fast_Local_isReference_o->modifiers = 0x0;
        Fast_Local_isReference_o->state = 0x6;
        Fast_Local_isReference_o->weak = FALSE;
        Fast_Local_isReference_o->id = 3;
        if (db_define(Fast_Local_isReference_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Local::isReference'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Local::kind */
    Fast_Local_kind_o = db_declare(Fast_Local_o, "kind", db_typedef(db_member_o));
    if (!Fast_Local_kind_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Local::kind'.");
        goto error;
    }

    /* Declare ::hyve::Fast::Local::name */
    Fast_Local_name_o = db_declare(Fast_Local_o, "name", db_typedef(db_member_o));
    if (!Fast_Local_name_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Local::name'.");
        goto error;
    }

    /* Define ::hyve::Fast::Local::name */
    if (!db_checkState(Fast_Local_name_o, DB_DEFINED)) {
        Fast_Local_name_o->type = db_resolve_ext(Fast_Local_name_o, NULL, "::hyve::lang::string", FALSE, "element ::hyve::Fast::Local::name.type");
        Fast_Local_name_o->modifiers = 0x0;
        Fast_Local_name_o->state = 0x6;
        Fast_Local_name_o->weak = FALSE;
        Fast_Local_name_o->id = 0;
        if (db_define(Fast_Local_name_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Local::name'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Local::type */
    Fast_Local_type_o = db_declare(Fast_Local_o, "type", db_typedef(db_member_o));
    if (!Fast_Local_type_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Local::type'.");
        goto error;
    }

    /* Define ::hyve::Fast::Block::locals */
    if (!db_checkState(Fast_Block_locals_o, DB_DEFINED)) {
        Fast_Block_locals_o->type = db_resolve_ext(Fast_Block_locals_o, NULL, "::hyve::lang::list{::hyve::Fast::Local,0}", FALSE, "element ::hyve::Fast::Block::locals.type");
        Fast_Block_locals_o->modifiers = 0x3;
        Fast_Block_locals_o->state = 0x6;
        Fast_Block_locals_o->weak = FALSE;
        Fast_Block_locals_o->id = 2;
        if (db_define(Fast_Block_locals_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Block::locals'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::LocalKind */
    Fast_LocalKind_o = db_declare(Fast_o, "LocalKind", db_typedef(db_enum_o));
    if (!Fast_LocalKind_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::LocalKind'.");
        goto error;
    }

    /* Declare ::hyve::Fast::LocalKind::LocalDefault */
    Fast_LocalKind_LocalDefault_o = db_declare(Fast_LocalKind_o, "LocalDefault", db_typedef(db_constant_o));
    if (!Fast_LocalKind_LocalDefault_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::LocalKind::LocalDefault'.");
        goto error;
    }

    /* Define ::hyve::Fast::LocalKind::LocalDefault */
    if (!db_checkState(Fast_LocalKind_LocalDefault_o, DB_DEFINED)) {
        (*Fast_LocalKind_LocalDefault_o) = 0;
        if (db_define(Fast_LocalKind_LocalDefault_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::LocalKind::LocalDefault'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::LocalKind::LocalParameter */
    Fast_LocalKind_LocalParameter_o = db_declare(Fast_LocalKind_o, "LocalParameter", db_typedef(db_constant_o));
    if (!Fast_LocalKind_LocalParameter_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::LocalKind::LocalParameter'.");
        goto error;
    }

    /* Define ::hyve::Fast::LocalKind::LocalParameter */
    if (!db_checkState(Fast_LocalKind_LocalParameter_o, DB_DEFINED)) {
        (*Fast_LocalKind_LocalParameter_o) = 1;
        if (db_define(Fast_LocalKind_LocalParameter_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::LocalKind::LocalParameter'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::LocalKind::LocalReturn */
    Fast_LocalKind_LocalReturn_o = db_declare(Fast_LocalKind_o, "LocalReturn", db_typedef(db_constant_o));
    if (!Fast_LocalKind_LocalReturn_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::LocalKind::LocalReturn'.");
        goto error;
    }

    /* Define ::hyve::Fast::LocalKind::LocalReturn */
    if (!db_checkState(Fast_LocalKind_LocalReturn_o, DB_DEFINED)) {
        (*Fast_LocalKind_LocalReturn_o) = 2;
        if (db_define(Fast_LocalKind_LocalReturn_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::LocalKind::LocalReturn'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::LocalKind */
    if (!db_checkState(Fast_LocalKind_o, DB_DEFINED)) {
        if (db_define(Fast_LocalKind_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::LocalKind'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::Local::kind */
    if (!db_checkState(Fast_Local_kind_o, DB_DEFINED)) {
        Fast_Local_kind_o->type = db_resolve_ext(Fast_Local_kind_o, NULL, "::hyve::Fast::LocalKind", FALSE, "element ::hyve::Fast::Local::kind.type");
        Fast_Local_kind_o->modifiers = 0x0;
        Fast_Local_kind_o->state = 0x6;
        Fast_Local_kind_o->weak = FALSE;
        Fast_Local_kind_o->id = 2;
        if (db_define(Fast_Local_kind_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Local::kind'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Lvalue */
    Fast_Lvalue_o = db_declare(Fast_o, "Lvalue", db_typedef(db_struct_o));
    if (!Fast_Lvalue_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Lvalue'.");
        goto error;
    }

    /* Declare ::hyve::Fast::Lvalue::expr */
    Fast_Lvalue_expr_o = db_declare(Fast_Lvalue_o, "expr", db_typedef(db_member_o));
    if (!Fast_Lvalue_expr_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Lvalue::expr'.");
        goto error;
    }

    /* Declare ::hyve::Fast::Lvalue::isAssignment */
    Fast_Lvalue_isAssignment_o = db_declare(Fast_Lvalue_o, "isAssignment", db_typedef(db_member_o));
    if (!Fast_Lvalue_isAssignment_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Lvalue::isAssignment'.");
        goto error;
    }

    /* Define ::hyve::Fast::Lvalue::isAssignment */
    if (!db_checkState(Fast_Lvalue_isAssignment_o, DB_DEFINED)) {
        Fast_Lvalue_isAssignment_o->type = db_resolve_ext(Fast_Lvalue_isAssignment_o, NULL, "::hyve::lang::bool", FALSE, "element ::hyve::Fast::Lvalue::isAssignment.type");
        Fast_Lvalue_isAssignment_o->modifiers = 0x0;
        Fast_Lvalue_isAssignment_o->state = 0x6;
        Fast_Lvalue_isAssignment_o->weak = FALSE;
        Fast_Lvalue_isAssignment_o->id = 1;
        if (db_define(Fast_Lvalue_isAssignment_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Lvalue::isAssignment'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::MemberExpr */
    Fast_MemberExpr_o = db_declare(Fast_o, "MemberExpr", db_typedef(db_class_o));
    if (!Fast_MemberExpr_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::MemberExpr'.");
        goto error;
    }

    /* Declare ::hyve::Fast::MemberExpr::lvalue */
    Fast_MemberExpr_lvalue_o = db_declare(Fast_MemberExpr_o, "lvalue", db_typedef(db_member_o));
    if (!Fast_MemberExpr_lvalue_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::MemberExpr::lvalue'.");
        goto error;
    }

    /* Declare ::hyve::Fast::MemberExpr::member */
    Fast_MemberExpr_member_o = db_declare(Fast_MemberExpr_o, "member", db_typedef(db_member_o));
    if (!Fast_MemberExpr_member_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::MemberExpr::member'.");
        goto error;
    }

    /* Define ::hyve::Fast::MemberExpr::member */
    if (!db_checkState(Fast_MemberExpr_member_o, DB_DEFINED)) {
        Fast_MemberExpr_member_o->type = db_resolve_ext(Fast_MemberExpr_member_o, NULL, "::hyve::lang::object", FALSE, "element ::hyve::Fast::MemberExpr::member.type");
        Fast_MemberExpr_member_o->modifiers = 0x2;
        Fast_MemberExpr_member_o->state = 0x6;
        Fast_MemberExpr_member_o->weak = FALSE;
        Fast_MemberExpr_member_o->id = 3;
        if (db_define(Fast_MemberExpr_member_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::MemberExpr::member'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::MemberExpr::rvalue */
    Fast_MemberExpr_rvalue_o = db_declare(Fast_MemberExpr_o, "rvalue", db_typedef(db_member_o));
    if (!Fast_MemberExpr_rvalue_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::MemberExpr::rvalue'.");
        goto error;
    }

    /* Declare ::hyve::Fast::MemberExpr::superMember */
    Fast_MemberExpr_superMember_o = db_declare(Fast_MemberExpr_o, "superMember", db_typedef(db_member_o));
    if (!Fast_MemberExpr_superMember_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::MemberExpr::superMember'.");
        goto error;
    }

    /* Define ::hyve::Fast::MemberExpr::superMember */
    if (!db_checkState(Fast_MemberExpr_superMember_o, DB_DEFINED)) {
        Fast_MemberExpr_superMember_o->type = db_resolve_ext(Fast_MemberExpr_superMember_o, NULL, "::hyve::lang::bool", FALSE, "element ::hyve::Fast::MemberExpr::superMember.type");
        Fast_MemberExpr_superMember_o->modifiers = 0x4;
        Fast_MemberExpr_superMember_o->state = 0x6;
        Fast_MemberExpr_superMember_o->weak = FALSE;
        Fast_MemberExpr_superMember_o->id = 2;
        if (db_define(Fast_MemberExpr_superMember_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::MemberExpr::superMember'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::NewExpr */
    Fast_NewExpr_o = db_declare(Fast_o, "NewExpr", db_typedef(db_class_o));
    if (!Fast_NewExpr_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::NewExpr'.");
        goto error;
    }

    /* Declare ::hyve::Fast::NewExpr::attributes */
    Fast_NewExpr_attributes_o = db_declare(Fast_NewExpr_o, "attributes", db_typedef(db_member_o));
    if (!Fast_NewExpr_attributes_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::NewExpr::attributes'.");
        goto error;
    }

    /* Declare ::hyve::Fast::NewExpr::type */
    Fast_NewExpr_type_o = db_declare(Fast_NewExpr_o, "type", db_typedef(db_member_o));
    if (!Fast_NewExpr_type_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::NewExpr::type'.");
        goto error;
    }

    /* Declare ::hyve::Fast::Node */
    Fast_Node_o = db_declare(Fast_o, "Node", db_typedef(db_class_o));
    if (!Fast_Node_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Node'.");
        goto error;
    }

    /* Declare ::hyve::Fast::Node::column */
    Fast_Node_column_o = db_declare(Fast_Node_o, "column", db_typedef(db_member_o));
    if (!Fast_Node_column_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Node::column'.");
        goto error;
    }

    /* Define ::hyve::Fast::Node::column */
    if (!db_checkState(Fast_Node_column_o, DB_DEFINED)) {
        Fast_Node_column_o->type = db_resolve_ext(Fast_Node_column_o, NULL, "::hyve::lang::uint32", FALSE, "element ::hyve::Fast::Node::column.type");
        Fast_Node_column_o->modifiers = 0x4;
        Fast_Node_column_o->state = 0x6;
        Fast_Node_column_o->weak = FALSE;
        Fast_Node_column_o->id = 2;
        if (db_define(Fast_Node_column_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Node::column'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Node::kind */
    Fast_Node_kind_o = db_declare(Fast_Node_o, "kind", db_typedef(db_member_o));
    if (!Fast_Node_kind_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Node::kind'.");
        goto error;
    }

    /* Declare ::hyve::Fast::Node::line */
    Fast_Node_line_o = db_declare(Fast_Node_o, "line", db_typedef(db_member_o));
    if (!Fast_Node_line_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Node::line'.");
        goto error;
    }

    /* Define ::hyve::Fast::Node::line */
    if (!db_checkState(Fast_Node_line_o, DB_DEFINED)) {
        Fast_Node_line_o->type = db_resolve_ext(Fast_Node_line_o, NULL, "::hyve::lang::uint32", FALSE, "element ::hyve::Fast::Node::line.type");
        Fast_Node_line_o->modifiers = 0x4;
        Fast_Node_line_o->state = 0x6;
        Fast_Node_line_o->weak = FALSE;
        Fast_Node_line_o->id = 1;
        if (db_define(Fast_Node_line_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Node::line'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::Block::statements */
    if (!db_checkState(Fast_Block_statements_o, DB_DEFINED)) {
        Fast_Block_statements_o->type = db_resolve_ext(Fast_Block_statements_o, NULL, "::hyve::lang::list{::hyve::Fast::Node,0}", FALSE, "element ::hyve::Fast::Block::statements.type");
        Fast_Block_statements_o->modifiers = 0x3;
        Fast_Block_statements_o->state = 0x6;
        Fast_Block_statements_o->weak = FALSE;
        Fast_Block_statements_o->id = 1;
        if (db_define(Fast_Block_statements_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Block::statements'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::nodeKind */
    Fast_nodeKind_o = db_declare(Fast_o, "nodeKind", db_typedef(db_enum_o));
    if (!Fast_nodeKind_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::nodeKind'.");
        goto error;
    }

    /* Declare ::hyve::Fast::nodeKind::Binary */
    Fast_nodeKind_Binary_o = db_declare(Fast_nodeKind_o, "Binary", db_typedef(db_constant_o));
    if (!Fast_nodeKind_Binary_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::nodeKind::Binary'.");
        goto error;
    }

    /* Define ::hyve::Fast::nodeKind::Binary */
    if (!db_checkState(Fast_nodeKind_Binary_o, DB_DEFINED)) {
        (*Fast_nodeKind_Binary_o) = 0;
        if (db_define(Fast_nodeKind_Binary_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::nodeKind::Binary'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::nodeKind::Call */
    Fast_nodeKind_Call_o = db_declare(Fast_nodeKind_o, "Call", db_typedef(db_constant_o));
    if (!Fast_nodeKind_Call_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::nodeKind::Call'.");
        goto error;
    }

    /* Define ::hyve::Fast::nodeKind::Call */
    if (!db_checkState(Fast_nodeKind_Call_o, DB_DEFINED)) {
        (*Fast_nodeKind_Call_o) = 1;
        if (db_define(Fast_nodeKind_Call_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::nodeKind::Call'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::nodeKind::Cast */
    Fast_nodeKind_Cast_o = db_declare(Fast_nodeKind_o, "Cast", db_typedef(db_constant_o));
    if (!Fast_nodeKind_Cast_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::nodeKind::Cast'.");
        goto error;
    }

    /* Define ::hyve::Fast::nodeKind::Cast */
    if (!db_checkState(Fast_nodeKind_Cast_o, DB_DEFINED)) {
        (*Fast_nodeKind_Cast_o) = 2;
        if (db_define(Fast_nodeKind_Cast_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::nodeKind::Cast'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::nodeKind::CommaExpr */
    Fast_nodeKind_CommaExpr_o = db_declare(Fast_nodeKind_o, "CommaExpr", db_typedef(db_constant_o));
    if (!Fast_nodeKind_CommaExpr_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::nodeKind::CommaExpr'.");
        goto error;
    }

    /* Define ::hyve::Fast::nodeKind::CommaExpr */
    if (!db_checkState(Fast_nodeKind_CommaExpr_o, DB_DEFINED)) {
        (*Fast_nodeKind_CommaExpr_o) = 3;
        if (db_define(Fast_nodeKind_CommaExpr_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::nodeKind::CommaExpr'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::nodeKind::Declaration */
    Fast_nodeKind_Declaration_o = db_declare(Fast_nodeKind_o, "Declaration", db_typedef(db_constant_o));
    if (!Fast_nodeKind_Declaration_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::nodeKind::Declaration'.");
        goto error;
    }

    /* Define ::hyve::Fast::nodeKind::Declaration */
    if (!db_checkState(Fast_nodeKind_Declaration_o, DB_DEFINED)) {
        (*Fast_nodeKind_Declaration_o) = 4;
        if (db_define(Fast_nodeKind_Declaration_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::nodeKind::Declaration'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::nodeKind::Declare */
    Fast_nodeKind_Declare_o = db_declare(Fast_nodeKind_o, "Declare", db_typedef(db_constant_o));
    if (!Fast_nodeKind_Declare_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::nodeKind::Declare'.");
        goto error;
    }

    /* Define ::hyve::Fast::nodeKind::Declare */
    if (!db_checkState(Fast_nodeKind_Declare_o, DB_DEFINED)) {
        (*Fast_nodeKind_Declare_o) = 5;
        if (db_define(Fast_nodeKind_Declare_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::nodeKind::Declare'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::nodeKind::Define */
    Fast_nodeKind_Define_o = db_declare(Fast_nodeKind_o, "Define", db_typedef(db_constant_o));
    if (!Fast_nodeKind_Define_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::nodeKind::Define'.");
        goto error;
    }

    /* Define ::hyve::Fast::nodeKind::Define */
    if (!db_checkState(Fast_nodeKind_Define_o, DB_DEFINED)) {
        (*Fast_nodeKind_Define_o) = 6;
        if (db_define(Fast_nodeKind_Define_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::nodeKind::Define'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::nodeKind::Element */
    Fast_nodeKind_Element_o = db_declare(Fast_nodeKind_o, "Element", db_typedef(db_constant_o));
    if (!Fast_nodeKind_Element_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::nodeKind::Element'.");
        goto error;
    }

    /* Define ::hyve::Fast::nodeKind::Element */
    if (!db_checkState(Fast_nodeKind_Element_o, DB_DEFINED)) {
        (*Fast_nodeKind_Element_o) = 7;
        if (db_define(Fast_nodeKind_Element_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::nodeKind::Element'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::nodeKind::If */
    Fast_nodeKind_If_o = db_declare(Fast_nodeKind_o, "If", db_typedef(db_constant_o));
    if (!Fast_nodeKind_If_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::nodeKind::If'.");
        goto error;
    }

    /* Define ::hyve::Fast::nodeKind::If */
    if (!db_checkState(Fast_nodeKind_If_o, DB_DEFINED)) {
        (*Fast_nodeKind_If_o) = 8;
        if (db_define(Fast_nodeKind_If_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::nodeKind::If'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::nodeKind::Initializer */
    Fast_nodeKind_Initializer_o = db_declare(Fast_nodeKind_o, "Initializer", db_typedef(db_constant_o));
    if (!Fast_nodeKind_Initializer_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::nodeKind::Initializer'.");
        goto error;
    }

    /* Define ::hyve::Fast::nodeKind::Initializer */
    if (!db_checkState(Fast_nodeKind_Initializer_o, DB_DEFINED)) {
        (*Fast_nodeKind_Initializer_o) = 9;
        if (db_define(Fast_nodeKind_Initializer_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::nodeKind::Initializer'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::nodeKind::Literal */
    Fast_nodeKind_Literal_o = db_declare(Fast_nodeKind_o, "Literal", db_typedef(db_constant_o));
    if (!Fast_nodeKind_Literal_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::nodeKind::Literal'.");
        goto error;
    }

    /* Define ::hyve::Fast::nodeKind::Literal */
    if (!db_checkState(Fast_nodeKind_Literal_o, DB_DEFINED)) {
        (*Fast_nodeKind_Literal_o) = 10;
        if (db_define(Fast_nodeKind_Literal_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::nodeKind::Literal'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::nodeKind::Member */
    Fast_nodeKind_Member_o = db_declare(Fast_nodeKind_o, "Member", db_typedef(db_constant_o));
    if (!Fast_nodeKind_Member_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::nodeKind::Member'.");
        goto error;
    }

    /* Define ::hyve::Fast::nodeKind::Member */
    if (!db_checkState(Fast_nodeKind_Member_o, DB_DEFINED)) {
        (*Fast_nodeKind_Member_o) = 11;
        if (db_define(Fast_nodeKind_Member_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::nodeKind::Member'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::nodeKind::Method */
    Fast_nodeKind_Method_o = db_declare(Fast_nodeKind_o, "Method", db_typedef(db_constant_o));
    if (!Fast_nodeKind_Method_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::nodeKind::Method'.");
        goto error;
    }

    /* Define ::hyve::Fast::nodeKind::Method */
    if (!db_checkState(Fast_nodeKind_Method_o, DB_DEFINED)) {
        (*Fast_nodeKind_Method_o) = 12;
        if (db_define(Fast_nodeKind_Method_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::nodeKind::Method'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::nodeKind::New */
    Fast_nodeKind_New_o = db_declare(Fast_nodeKind_o, "New", db_typedef(db_constant_o));
    if (!Fast_nodeKind_New_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::nodeKind::New'.");
        goto error;
    }

    /* Define ::hyve::Fast::nodeKind::New */
    if (!db_checkState(Fast_nodeKind_New_o, DB_DEFINED)) {
        (*Fast_nodeKind_New_o) = 13;
        if (db_define(Fast_nodeKind_New_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::nodeKind::New'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::nodeKind::Postfix */
    Fast_nodeKind_Postfix_o = db_declare(Fast_nodeKind_o, "Postfix", db_typedef(db_constant_o));
    if (!Fast_nodeKind_Postfix_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::nodeKind::Postfix'.");
        goto error;
    }

    /* Define ::hyve::Fast::nodeKind::Postfix */
    if (!db_checkState(Fast_nodeKind_Postfix_o, DB_DEFINED)) {
        (*Fast_nodeKind_Postfix_o) = 14;
        if (db_define(Fast_nodeKind_Postfix_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::nodeKind::Postfix'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::nodeKind::Ternary */
    Fast_nodeKind_Ternary_o = db_declare(Fast_nodeKind_o, "Ternary", db_typedef(db_constant_o));
    if (!Fast_nodeKind_Ternary_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::nodeKind::Ternary'.");
        goto error;
    }

    /* Define ::hyve::Fast::nodeKind::Ternary */
    if (!db_checkState(Fast_nodeKind_Ternary_o, DB_DEFINED)) {
        (*Fast_nodeKind_Ternary_o) = 15;
        if (db_define(Fast_nodeKind_Ternary_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::nodeKind::Ternary'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::nodeKind::Unary */
    Fast_nodeKind_Unary_o = db_declare(Fast_nodeKind_o, "Unary", db_typedef(db_constant_o));
    if (!Fast_nodeKind_Unary_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::nodeKind::Unary'.");
        goto error;
    }

    /* Define ::hyve::Fast::nodeKind::Unary */
    if (!db_checkState(Fast_nodeKind_Unary_o, DB_DEFINED)) {
        (*Fast_nodeKind_Unary_o) = 16;
        if (db_define(Fast_nodeKind_Unary_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::nodeKind::Unary'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::nodeKind::Update */
    Fast_nodeKind_Update_o = db_declare(Fast_nodeKind_o, "Update", db_typedef(db_constant_o));
    if (!Fast_nodeKind_Update_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::nodeKind::Update'.");
        goto error;
    }

    /* Define ::hyve::Fast::nodeKind::Update */
    if (!db_checkState(Fast_nodeKind_Update_o, DB_DEFINED)) {
        (*Fast_nodeKind_Update_o) = 17;
        if (db_define(Fast_nodeKind_Update_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::nodeKind::Update'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::nodeKind::Variable */
    Fast_nodeKind_Variable_o = db_declare(Fast_nodeKind_o, "Variable", db_typedef(db_constant_o));
    if (!Fast_nodeKind_Variable_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::nodeKind::Variable'.");
        goto error;
    }

    /* Define ::hyve::Fast::nodeKind::Variable */
    if (!db_checkState(Fast_nodeKind_Variable_o, DB_DEFINED)) {
        (*Fast_nodeKind_Variable_o) = 18;
        if (db_define(Fast_nodeKind_Variable_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::nodeKind::Variable'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::nodeKind::Wait */
    Fast_nodeKind_Wait_o = db_declare(Fast_nodeKind_o, "Wait", db_typedef(db_constant_o));
    if (!Fast_nodeKind_Wait_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::nodeKind::Wait'.");
        goto error;
    }

    /* Define ::hyve::Fast::nodeKind::Wait */
    if (!db_checkState(Fast_nodeKind_Wait_o, DB_DEFINED)) {
        (*Fast_nodeKind_Wait_o) = 19;
        if (db_define(Fast_nodeKind_Wait_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::nodeKind::Wait'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::nodeKind::While */
    Fast_nodeKind_While_o = db_declare(Fast_nodeKind_o, "While", db_typedef(db_constant_o));
    if (!Fast_nodeKind_While_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::nodeKind::While'.");
        goto error;
    }

    /* Define ::hyve::Fast::nodeKind::While */
    if (!db_checkState(Fast_nodeKind_While_o, DB_DEFINED)) {
        (*Fast_nodeKind_While_o) = 20;
        if (db_define(Fast_nodeKind_While_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::nodeKind::While'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::nodeKind */
    if (!db_checkState(Fast_nodeKind_o, DB_DEFINED)) {
        if (db_define(Fast_nodeKind_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::nodeKind'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::Node::kind */
    if (!db_checkState(Fast_Node_kind_o, DB_DEFINED)) {
        Fast_Node_kind_o->type = db_resolve_ext(Fast_Node_kind_o, NULL, "::hyve::Fast::nodeKind", FALSE, "element ::hyve::Fast::Node::kind.type");
        Fast_Node_kind_o->modifiers = 0x0;
        Fast_Node_kind_o->state = 0x6;
        Fast_Node_kind_o->weak = FALSE;
        Fast_Node_kind_o->id = 0;
        if (db_define(Fast_Node_kind_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Node::kind'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Null */
    Fast_Null_o = db_declare(Fast_o, "Null", db_typedef(db_class_o));
    if (!Fast_Null_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Null'.");
        goto error;
    }

    /* Declare ::hyve::Fast::Object */
    Fast_Object_o = db_declare(Fast_o, "Object", db_typedef(db_class_o));
    if (!Fast_Object_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Object'.");
        goto error;
    }

    /* Declare ::hyve::Fast::ObjectBase */
    Fast_ObjectBase_o = db_declare(Fast_o, "ObjectBase", db_typedef(db_class_o));
    if (!Fast_ObjectBase_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::ObjectBase'.");
        goto error;
    }

    /* Declare ::hyve::Fast::ObjectBase::value */
    Fast_ObjectBase_value_o = db_declare(Fast_ObjectBase_o, "value", db_typedef(db_member_o));
    if (!Fast_ObjectBase_value_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::ObjectBase::value'.");
        goto error;
    }

    /* Define ::hyve::Fast::ObjectBase::value */
    if (!db_checkState(Fast_ObjectBase_value_o, DB_DEFINED)) {
        Fast_ObjectBase_value_o->type = db_resolve_ext(Fast_ObjectBase_value_o, NULL, "::hyve::lang::object", FALSE, "element ::hyve::Fast::ObjectBase::value.type");
        Fast_ObjectBase_value_o->modifiers = 0x0;
        Fast_ObjectBase_value_o->state = 0x6;
        Fast_ObjectBase_value_o->weak = FALSE;
        Fast_ObjectBase_value_o->id = 0;
        if (db_define(Fast_ObjectBase_value_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::ObjectBase::value'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser */
    Fast_Parser_o = db_declare(Fast_o, "Parser", db_typedef(db_class_o));
    if (!Fast_Parser_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser'.");
        goto error;
    }

    /* Declare ::hyve::Fast::Parser::abort */
    Fast_Parser_abort_o = db_declare(Fast_Parser_o, "abort", db_typedef(db_member_o));
    if (!Fast_Parser_abort_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::abort'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::abort */
    if (!db_checkState(Fast_Parser_abort_o, DB_DEFINED)) {
        Fast_Parser_abort_o->type = db_resolve_ext(Fast_Parser_abort_o, NULL, "::hyve::lang::bool", FALSE, "element ::hyve::Fast::Parser::abort.type");
        Fast_Parser_abort_o->modifiers = 0x4;
        Fast_Parser_abort_o->state = 0x6;
        Fast_Parser_abort_o->weak = FALSE;
        Fast_Parser_abort_o->id = 12;
        if (db_define(Fast_Parser_abort_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::abort'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::bindings */
    Fast_Parser_bindings_o = db_declare(Fast_Parser_o, "bindings", db_typedef(db_member_o));
    if (!Fast_Parser_bindings_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::bindings'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::bindings */
    if (!db_checkState(Fast_Parser_bindings_o, DB_DEFINED)) {
        Fast_Parser_bindings_o->type = db_resolve_ext(Fast_Parser_bindings_o, NULL, "::hyve::lang::list{::hyve::Fast::Binding,0}", FALSE, "element ::hyve::Fast::Parser::bindings.type");
        Fast_Parser_bindings_o->modifiers = 0x4;
        Fast_Parser_bindings_o->state = 0x6;
        Fast_Parser_bindings_o->weak = FALSE;
        Fast_Parser_bindings_o->id = 13;
        if (db_define(Fast_Parser_bindings_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::bindings'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::block */
    Fast_Parser_block_o = db_declare(Fast_Parser_o, "block", db_typedef(db_member_o));
    if (!Fast_Parser_block_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::block'.");
        goto error;
    }

    /* Declare ::hyve::Fast::Parser::blockPop() */
    Fast_Parser_blockPop_o = db_declare(Fast_Parser_o, "blockPop()", db_typedef(db_method_o));
    if (!Fast_Parser_blockPop_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::blockPop()'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::blockPop() */
    if (!db_checkState(Fast_Parser_blockPop_o, DB_DEFINED)) {
        db_function(Fast_Parser_blockPop_o)->returnType = NULL;
        db_function(Fast_Parser_blockPop_o)->returnsReference = FALSE;
        Fast_Parser_blockPop_o->virtual = FALSE;
        
        /* Bind Fast_Parser_blockPop_o with C-function */
        db_function(Fast_Parser_blockPop_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Parser_blockPop(void *args, void *result);
        db_function(Fast_Parser_blockPop_o)->impl = (db_word)__Fast_Parser_blockPop;
        if (db_define(Fast_Parser_blockPop_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::blockPop()'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::blockPreset */
    Fast_Parser_blockPreset_o = db_declare(Fast_Parser_o, "blockPreset", db_typedef(db_member_o));
    if (!Fast_Parser_blockPreset_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::blockPreset'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::blockPreset */
    if (!db_checkState(Fast_Parser_blockPreset_o, DB_DEFINED)) {
        Fast_Parser_blockPreset_o->type = db_resolve_ext(Fast_Parser_blockPreset_o, NULL, "::hyve::lang::bool", FALSE, "element ::hyve::Fast::Parser::blockPreset.type");
        Fast_Parser_blockPreset_o->modifiers = 0x3;
        Fast_Parser_blockPreset_o->state = 0x6;
        Fast_Parser_blockPreset_o->weak = FALSE;
        Fast_Parser_blockPreset_o->id = 17;
        if (db_define(Fast_Parser_blockPreset_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::blockPreset'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::blockPush(lang::bool presetBlock) */
    Fast_Parser_blockPush_o = db_declare(Fast_Parser_o, "blockPush(lang::bool presetBlock)", db_typedef(db_method_o));
    if (!Fast_Parser_blockPush_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::blockPush(lang::bool presetBlock)'.");
        goto error;
    }

    /* Declare ::hyve::Fast::Parser::collect(lang::object o) */
    Fast_Parser_collect_o = db_declare(Fast_Parser_o, "collect(lang::object o)", db_typedef(db_method_o));
    if (!Fast_Parser_collect_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::collect(lang::object o)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::collect(lang::object o) */
    if (!db_checkState(Fast_Parser_collect_o, DB_DEFINED)) {
        db_function(Fast_Parser_collect_o)->returnType = db_resolve_ext(Fast_Parser_collect_o, NULL, "::hyve::lang::void", FALSE, "element ::hyve::Fast::Parser::collect(lang::object o).returnType");
        db_function(Fast_Parser_collect_o)->returnsReference = FALSE;
        Fast_Parser_collect_o->virtual = FALSE;
        
        /* Bind Fast_Parser_collect_o with C-function */
        db_function(Fast_Parser_collect_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Parser_collect(void *args, void *result);
        db_function(Fast_Parser_collect_o)->impl = (db_word)__Fast_Parser_collect;
        if (db_define(Fast_Parser_collect_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::collect(lang::object o)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::collected */
    Fast_Parser_collected_o = db_declare(Fast_Parser_o, "collected", db_typedef(db_member_o));
    if (!Fast_Parser_collected_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::collected'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::collected */
    if (!db_checkState(Fast_Parser_collected_o, DB_DEFINED)) {
        Fast_Parser_collected_o->type = db_resolve_ext(Fast_Parser_collected_o, NULL, "::hyve::lang::list{::hyve::Fast::Object,0}", FALSE, "element ::hyve::Fast::Parser::collected.type");
        Fast_Parser_collected_o->modifiers = 0x3;
        Fast_Parser_collected_o->state = 0x6;
        Fast_Parser_collected_o->weak = FALSE;
        Fast_Parser_collected_o->id = 16;
        if (db_define(Fast_Parser_collected_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::collected'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::collectHeap(word addr) */
    Fast_Parser_collectHeap_o = db_declare(Fast_Parser_o, "collectHeap(word addr)", db_typedef(db_method_o));
    if (!Fast_Parser_collectHeap_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::collectHeap(word addr)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::collectHeap(word addr) */
    if (!db_checkState(Fast_Parser_collectHeap_o, DB_DEFINED)) {
        db_function(Fast_Parser_collectHeap_o)->returnType = db_resolve_ext(Fast_Parser_collectHeap_o, NULL, "::hyve::lang::void", FALSE, "element ::hyve::Fast::Parser::collectHeap(word addr).returnType");
        db_function(Fast_Parser_collectHeap_o)->returnsReference = FALSE;
        Fast_Parser_collectHeap_o->virtual = FALSE;
        
        /* Bind Fast_Parser_collectHeap_o with C-function */
        db_function(Fast_Parser_collectHeap_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Parser_collectHeap(void *args, void *result);
        db_function(Fast_Parser_collectHeap_o)->impl = (db_word)__Fast_Parser_collectHeap;
        if (db_define(Fast_Parser_collectHeap_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::collectHeap(word addr)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::column */
    Fast_Parser_column_o = db_declare(Fast_Parser_o, "column", db_typedef(db_member_o));
    if (!Fast_Parser_column_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::column'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::column */
    if (!db_checkState(Fast_Parser_column_o, DB_DEFINED)) {
        Fast_Parser_column_o->type = db_resolve_ext(Fast_Parser_column_o, NULL, "::hyve::lang::uint32", FALSE, "element ::hyve::Fast::Parser::column.type");
        Fast_Parser_column_o->modifiers = 0x4;
        Fast_Parser_column_o->state = 0x6;
        Fast_Parser_column_o->weak = FALSE;
        Fast_Parser_column_o->id = 4;
        if (db_define(Fast_Parser_column_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::column'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::complexType */
    Fast_Parser_complexType_o = db_declare(Fast_Parser_o, "complexType", db_typedef(db_member_o));
    if (!Fast_Parser_complexType_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::complexType'.");
        goto error;
    }

    /* Declare ::hyve::Fast::Parser::complexTypeSp */
    Fast_Parser_complexTypeSp_o = db_declare(Fast_Parser_o, "complexTypeSp", db_typedef(db_member_o));
    if (!Fast_Parser_complexTypeSp_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::complexTypeSp'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::complexTypeSp */
    if (!db_checkState(Fast_Parser_complexTypeSp_o, DB_DEFINED)) {
        Fast_Parser_complexTypeSp_o->type = db_resolve_ext(Fast_Parser_complexTypeSp_o, NULL, "::hyve::lang::int32", FALSE, "element ::hyve::Fast::Parser::complexTypeSp.type");
        Fast_Parser_complexTypeSp_o->modifiers = 0x3;
        Fast_Parser_complexTypeSp_o->state = 0x6;
        Fast_Parser_complexTypeSp_o->weak = FALSE;
        Fast_Parser_complexTypeSp_o->id = 36;
        if (db_define(Fast_Parser_complexTypeSp_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::complexTypeSp'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::define() */
    Fast_Parser_define_o = db_declare(Fast_Parser_o, "define()", db_typedef(db_method_o));
    if (!Fast_Parser_define_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::define()'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::define() */
    if (!db_checkState(Fast_Parser_define_o, DB_DEFINED)) {
        db_function(Fast_Parser_define_o)->returnType = db_resolve_ext(Fast_Parser_define_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::Parser::define().returnType");
        db_function(Fast_Parser_define_o)->returnsReference = FALSE;
        Fast_Parser_define_o->virtual = FALSE;
        
        /* Bind Fast_Parser_define_o with C-function */
        db_function(Fast_Parser_define_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Parser_define(void *args, void *result);
        db_function(Fast_Parser_define_o)->impl = (db_word)__Fast_Parser_define;
        if (db_define(Fast_Parser_define_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::define()'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::defineScope() */
    Fast_Parser_defineScope_o = db_declare(Fast_Parser_o, "defineScope()", db_typedef(db_method_o));
    if (!Fast_Parser_defineScope_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::defineScope()'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::defineScope() */
    if (!db_checkState(Fast_Parser_defineScope_o, DB_DEFINED)) {
        db_function(Fast_Parser_defineScope_o)->returnType = db_resolve_ext(Fast_Parser_defineScope_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::Parser::defineScope().returnType");
        db_function(Fast_Parser_defineScope_o)->returnsReference = FALSE;
        Fast_Parser_defineScope_o->virtual = FALSE;
        
        /* Bind Fast_Parser_defineScope_o with C-function */
        db_function(Fast_Parser_defineScope_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Parser_defineScope(void *args, void *result);
        db_function(Fast_Parser_defineScope_o)->impl = (db_word)__Fast_Parser_defineScope;
        if (db_define(Fast_Parser_defineScope_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::defineScope()'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::errLine */
    Fast_Parser_errLine_o = db_declare(Fast_Parser_o, "errLine", db_typedef(db_member_o));
    if (!Fast_Parser_errLine_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::errLine'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::errLine */
    if (!db_checkState(Fast_Parser_errLine_o, DB_DEFINED)) {
        Fast_Parser_errLine_o->type = db_resolve_ext(Fast_Parser_errLine_o, NULL, "::hyve::lang::uint32", FALSE, "element ::hyve::Fast::Parser::errLine.type");
        Fast_Parser_errLine_o->modifiers = 0x6;
        Fast_Parser_errLine_o->state = 0x6;
        Fast_Parser_errLine_o->weak = FALSE;
        Fast_Parser_errLine_o->id = 11;
        if (db_define(Fast_Parser_errLine_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::errLine'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::errors */
    Fast_Parser_errors_o = db_declare(Fast_Parser_o, "errors", db_typedef(db_member_o));
    if (!Fast_Parser_errors_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::errors'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::errors */
    if (!db_checkState(Fast_Parser_errors_o, DB_DEFINED)) {
        Fast_Parser_errors_o->type = db_resolve_ext(Fast_Parser_errors_o, NULL, "::hyve::lang::uint32", FALSE, "element ::hyve::Fast::Parser::errors.type");
        Fast_Parser_errors_o->modifiers = 0x4;
        Fast_Parser_errors_o->state = 0x6;
        Fast_Parser_errors_o->weak = FALSE;
        Fast_Parser_errors_o->id = 8;
        if (db_define(Fast_Parser_errors_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::errors'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::errSet */
    Fast_Parser_errSet_o = db_declare(Fast_Parser_o, "errSet", db_typedef(db_member_o));
    if (!Fast_Parser_errSet_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::errSet'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::errSet */
    if (!db_checkState(Fast_Parser_errSet_o, DB_DEFINED)) {
        Fast_Parser_errSet_o->type = db_resolve_ext(Fast_Parser_errSet_o, NULL, "::hyve::lang::bool", FALSE, "element ::hyve::Fast::Parser::errSet.type");
        Fast_Parser_errSet_o->modifiers = 0x6;
        Fast_Parser_errSet_o->state = 0x6;
        Fast_Parser_errSet_o->weak = FALSE;
        Fast_Parser_errSet_o->id = 10;
        if (db_define(Fast_Parser_errSet_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::errSet'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::filename */
    Fast_Parser_filename_o = db_declare(Fast_Parser_o, "filename", db_typedef(db_member_o));
    if (!Fast_Parser_filename_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::filename'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::filename */
    if (!db_checkState(Fast_Parser_filename_o, DB_DEFINED)) {
        Fast_Parser_filename_o->type = db_resolve_ext(Fast_Parser_filename_o, NULL, "::hyve::lang::string", FALSE, "element ::hyve::Fast::Parser::filename.type");
        Fast_Parser_filename_o->modifiers = 0x0;
        Fast_Parser_filename_o->state = 0x6;
        Fast_Parser_filename_o->weak = FALSE;
        Fast_Parser_filename_o->id = 2;
        if (db_define(Fast_Parser_filename_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::filename'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::getComplexType() */
    Fast_Parser_getComplexType_o = db_declare(Fast_Parser_o, "getComplexType()", db_typedef(db_method_o));
    if (!Fast_Parser_getComplexType_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::getComplexType()'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::getComplexType() */
    if (!db_checkState(Fast_Parser_getComplexType_o, DB_DEFINED)) {
        db_function(Fast_Parser_getComplexType_o)->returnType = db_resolve_ext(Fast_Parser_getComplexType_o, NULL, "::hyve::lang::type", FALSE, "element ::hyve::Fast::Parser::getComplexType().returnType");
        db_function(Fast_Parser_getComplexType_o)->returnsReference = FALSE;
        Fast_Parser_getComplexType_o->virtual = FALSE;
        
        /* Bind Fast_Parser_getComplexType_o with C-function */
        db_function(Fast_Parser_getComplexType_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Parser_getComplexType(void *args, void *result);
        db_function(Fast_Parser_getComplexType_o)->impl = (db_word)__Fast_Parser_getComplexType;
        if (db_define(Fast_Parser_getComplexType_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::getComplexType()'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::getLvalue(lang::bool assignment) */
    Fast_Parser_getLvalue_o = db_declare(Fast_Parser_o, "getLvalue(lang::bool assignment)", db_typedef(db_method_o));
    if (!Fast_Parser_getLvalue_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::getLvalue(lang::bool assignment)'.");
        goto error;
    }

    /* Declare ::hyve::Fast::Parser::getLvalueType(lang::bool assignment) */
    Fast_Parser_getLvalueType_o = db_declare(Fast_Parser_o, "getLvalueType(lang::bool assignment)", db_typedef(db_method_o));
    if (!Fast_Parser_getLvalueType_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::getLvalueType(lang::bool assignment)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::getLvalueType(lang::bool assignment) */
    if (!db_checkState(Fast_Parser_getLvalueType_o, DB_DEFINED)) {
        db_function(Fast_Parser_getLvalueType_o)->returnType = db_resolve_ext(Fast_Parser_getLvalueType_o, NULL, "::hyve::lang::type", FALSE, "element ::hyve::Fast::Parser::getLvalueType(lang::bool assignment).returnType");
        db_function(Fast_Parser_getLvalueType_o)->returnsReference = FALSE;
        Fast_Parser_getLvalueType_o->virtual = FALSE;
        
        /* Bind Fast_Parser_getLvalueType_o with C-function */
        db_function(Fast_Parser_getLvalueType_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Parser_getLvalueType(void *args, void *result);
        db_function(Fast_Parser_getLvalueType_o)->impl = (db_word)__Fast_Parser_getLvalueType;
        if (db_define(Fast_Parser_getLvalueType_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::getLvalueType(lang::bool assignment)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::heapCollected */
    Fast_Parser_heapCollected_o = db_declare(Fast_Parser_o, "heapCollected", db_typedef(db_member_o));
    if (!Fast_Parser_heapCollected_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::heapCollected'.");
        goto error;
    }

    /* Declare ::hyve::Fast::Parser::initAnonymousId */
    Fast_Parser_initAnonymousId_o = db_declare(Fast_Parser_o, "initAnonymousId", db_typedef(db_member_o));
    if (!Fast_Parser_initAnonymousId_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::initAnonymousId'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::initAnonymousId */
    if (!db_checkState(Fast_Parser_initAnonymousId_o, DB_DEFINED)) {
        Fast_Parser_initAnonymousId_o->type = db_resolve_ext(Fast_Parser_initAnonymousId_o, NULL, "::hyve::lang::uint32", FALSE, "element ::hyve::Fast::Parser::initAnonymousId.type");
        Fast_Parser_initAnonymousId_o->modifiers = 0x3;
        Fast_Parser_initAnonymousId_o->state = 0x6;
        Fast_Parser_initAnonymousId_o->weak = FALSE;
        Fast_Parser_initAnonymousId_o->id = 28;
        if (db_define(Fast_Parser_initAnonymousId_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::initAnonymousId'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::initDynamic */
    Fast_Parser_initDynamic_o = db_declare(Fast_Parser_o, "initDynamic", db_typedef(db_member_o));
    if (!Fast_Parser_initDynamic_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::initDynamic'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::initDynamic */
    if (!db_checkState(Fast_Parser_initDynamic_o, DB_DEFINED)) {
        Fast_Parser_initDynamic_o->type = db_resolve_ext(Fast_Parser_initDynamic_o, NULL, "::hyve::lang::bool", FALSE, "element ::hyve::Fast::Parser::initDynamic.type");
        Fast_Parser_initDynamic_o->modifiers = 0x3;
        Fast_Parser_initDynamic_o->state = 0x6;
        Fast_Parser_initDynamic_o->weak = FALSE;
        Fast_Parser_initDynamic_o->id = 29;
        if (db_define(Fast_Parser_initDynamic_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::initDynamic'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::initializerCount */
    Fast_Parser_initializerCount_o = db_declare(Fast_Parser_o, "initializerCount", db_typedef(db_member_o));
    if (!Fast_Parser_initializerCount_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::initializerCount'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::initializerCount */
    if (!db_checkState(Fast_Parser_initializerCount_o, DB_DEFINED)) {
        Fast_Parser_initializerCount_o->type = db_resolve_ext(Fast_Parser_initializerCount_o, NULL, "::hyve::lang::int8", FALSE, "element ::hyve::Fast::Parser::initializerCount.type");
        Fast_Parser_initializerCount_o->modifiers = 0x3;
        Fast_Parser_initializerCount_o->state = 0x6;
        Fast_Parser_initializerCount_o->weak = FALSE;
        Fast_Parser_initializerCount_o->id = 27;
        if (db_define(Fast_Parser_initializerCount_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::initializerCount'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::initializers */
    Fast_Parser_initializers_o = db_declare(Fast_Parser_o, "initializers", db_typedef(db_member_o));
    if (!Fast_Parser_initializers_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::initializers'.");
        goto error;
    }

    /* Declare ::hyve::Fast::Parser::initKeyValuePop() */
    Fast_Parser_initKeyValuePop_o = db_declare(Fast_Parser_o, "initKeyValuePop()", db_typedef(db_method_o));
    if (!Fast_Parser_initKeyValuePop_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::initKeyValuePop()'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::initKeyValuePop() */
    if (!db_checkState(Fast_Parser_initKeyValuePop_o, DB_DEFINED)) {
        db_function(Fast_Parser_initKeyValuePop_o)->returnType = db_resolve_ext(Fast_Parser_initKeyValuePop_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::Parser::initKeyValuePop().returnType");
        db_function(Fast_Parser_initKeyValuePop_o)->returnsReference = FALSE;
        Fast_Parser_initKeyValuePop_o->virtual = FALSE;
        
        /* Bind Fast_Parser_initKeyValuePop_o with C-function */
        db_function(Fast_Parser_initKeyValuePop_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Parser_initKeyValuePop(void *args, void *result);
        db_function(Fast_Parser_initKeyValuePop_o)->impl = (db_word)__Fast_Parser_initKeyValuePop;
        if (db_define(Fast_Parser_initKeyValuePop_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::initKeyValuePop()'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::initKeyValuePush() */
    Fast_Parser_initKeyValuePush_o = db_declare(Fast_Parser_o, "initKeyValuePush()", db_typedef(db_method_o));
    if (!Fast_Parser_initKeyValuePush_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::initKeyValuePush()'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::initKeyValuePush() */
    if (!db_checkState(Fast_Parser_initKeyValuePush_o, DB_DEFINED)) {
        db_function(Fast_Parser_initKeyValuePush_o)->returnType = db_resolve_ext(Fast_Parser_initKeyValuePush_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::Parser::initKeyValuePush().returnType");
        db_function(Fast_Parser_initKeyValuePush_o)->returnsReference = FALSE;
        Fast_Parser_initKeyValuePush_o->virtual = FALSE;
        
        /* Bind Fast_Parser_initKeyValuePush_o with C-function */
        db_function(Fast_Parser_initKeyValuePush_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Parser_initKeyValuePush(void *args, void *result);
        db_function(Fast_Parser_initKeyValuePush_o)->impl = (db_word)__Fast_Parser_initKeyValuePush;
        if (db_define(Fast_Parser_initKeyValuePush_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::initKeyValuePush()'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::initMember(lang::string member) */
    Fast_Parser_initMember_o = db_declare(Fast_Parser_o, "initMember(lang::string member)", db_typedef(db_method_o));
    if (!Fast_Parser_initMember_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::initMember(lang::string member)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::initMember(lang::string member) */
    if (!db_checkState(Fast_Parser_initMember_o, DB_DEFINED)) {
        db_function(Fast_Parser_initMember_o)->returnType = db_resolve_ext(Fast_Parser_initMember_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::Parser::initMember(lang::string member).returnType");
        db_function(Fast_Parser_initMember_o)->returnsReference = FALSE;
        Fast_Parser_initMember_o->virtual = FALSE;
        
        /* Bind Fast_Parser_initMember_o with C-function */
        db_function(Fast_Parser_initMember_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Parser_initMember(void *args, void *result);
        db_function(Fast_Parser_initMember_o)->impl = (db_word)__Fast_Parser_initMember;
        if (db_define(Fast_Parser_initMember_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::initMember(lang::string member)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::initPop() */
    Fast_Parser_initPop_o = db_declare(Fast_Parser_o, "initPop()", db_typedef(db_method_o));
    if (!Fast_Parser_initPop_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::initPop()'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::initPop() */
    if (!db_checkState(Fast_Parser_initPop_o, DB_DEFINED)) {
        db_function(Fast_Parser_initPop_o)->returnType = db_resolve_ext(Fast_Parser_initPop_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::Parser::initPop().returnType");
        db_function(Fast_Parser_initPop_o)->returnsReference = FALSE;
        Fast_Parser_initPop_o->virtual = FALSE;
        
        /* Bind Fast_Parser_initPop_o with C-function */
        db_function(Fast_Parser_initPop_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Parser_initPop(void *args, void *result);
        db_function(Fast_Parser_initPop_o)->impl = (db_word)__Fast_Parser_initPop;
        if (db_define(Fast_Parser_initPop_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::initPop()'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::initPush() */
    Fast_Parser_initPush_o = db_declare(Fast_Parser_o, "initPush()", db_typedef(db_method_o));
    if (!Fast_Parser_initPush_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::initPush()'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::initPush() */
    if (!db_checkState(Fast_Parser_initPush_o, DB_DEFINED)) {
        db_function(Fast_Parser_initPush_o)->returnType = db_resolve_ext(Fast_Parser_initPush_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::Parser::initPush().returnType");
        db_function(Fast_Parser_initPush_o)->returnsReference = FALSE;
        Fast_Parser_initPush_o->virtual = FALSE;
        
        /* Bind Fast_Parser_initPush_o with C-function */
        db_function(Fast_Parser_initPush_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Parser_initPush(void *args, void *result);
        db_function(Fast_Parser_initPush_o)->impl = (db_word)__Fast_Parser_initPush;
        if (db_define(Fast_Parser_initPush_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::initPush()'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::initPushExpression() */
    Fast_Parser_initPushExpression_o = db_declare(Fast_Parser_o, "initPushExpression()", db_typedef(db_method_o));
    if (!Fast_Parser_initPushExpression_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::initPushExpression()'.");
        goto error;
    }

    /* Declare ::hyve::Fast::Parser::initPushStatic() */
    Fast_Parser_initPushStatic_o = db_declare(Fast_Parser_o, "initPushStatic()", db_typedef(db_method_o));
    if (!Fast_Parser_initPushStatic_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::initPushStatic()'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::initPushStatic() */
    if (!db_checkState(Fast_Parser_initPushStatic_o, DB_DEFINED)) {
        db_function(Fast_Parser_initPushStatic_o)->returnType = db_resolve_ext(Fast_Parser_initPushStatic_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::Parser::initPushStatic().returnType");
        db_function(Fast_Parser_initPushStatic_o)->returnsReference = FALSE;
        Fast_Parser_initPushStatic_o->virtual = FALSE;
        
        /* Bind Fast_Parser_initPushStatic_o with C-function */
        db_function(Fast_Parser_initPushStatic_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Parser_initPushStatic(void *args, void *result);
        db_function(Fast_Parser_initPushStatic_o)->impl = (db_word)__Fast_Parser_initPushStatic;
        if (db_define(Fast_Parser_initPushStatic_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::initPushStatic()'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::initStage(lang::string id,bool found) */
    Fast_Parser_initStage_o = db_declare(Fast_Parser_o, "initStage(lang::string id,bool found)", db_typedef(db_method_o));
    if (!Fast_Parser_initStage_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::initStage(lang::string id,bool found)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::initStage(lang::string id,bool found) */
    if (!db_checkState(Fast_Parser_initStage_o, DB_DEFINED)) {
        db_function(Fast_Parser_initStage_o)->returnType = NULL;
        db_function(Fast_Parser_initStage_o)->returnsReference = FALSE;
        Fast_Parser_initStage_o->virtual = FALSE;
        
        /* Bind Fast_Parser_initStage_o with C-function */
        db_function(Fast_Parser_initStage_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Parser_initStage(void *args, void *result);
        db_function(Fast_Parser_initStage_o)->impl = (db_word)__Fast_Parser_initStage;
        if (db_define(Fast_Parser_initStage_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::initStage(lang::string id,bool found)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::isAbortSet() */
    Fast_Parser_isAbortSet_o = db_declare(Fast_Parser_o, "isAbortSet()", db_typedef(db_method_o));
    if (!Fast_Parser_isAbortSet_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::isAbortSet()'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::isAbortSet() */
    if (!db_checkState(Fast_Parser_isAbortSet_o, DB_DEFINED)) {
        db_function(Fast_Parser_isAbortSet_o)->returnType = db_resolve_ext(Fast_Parser_isAbortSet_o, NULL, "::hyve::lang::bool", FALSE, "element ::hyve::Fast::Parser::isAbortSet().returnType");
        db_function(Fast_Parser_isAbortSet_o)->returnsReference = FALSE;
        Fast_Parser_isAbortSet_o->virtual = FALSE;
        
        /* Bind Fast_Parser_isAbortSet_o with C-function */
        db_function(Fast_Parser_isAbortSet_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Parser_isAbortSet(void *args, void *result);
        db_function(Fast_Parser_isAbortSet_o)->impl = (db_word)__Fast_Parser_isAbortSet;
        if (db_define(Fast_Parser_isAbortSet_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::isAbortSet()'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::isErrSet() */
    Fast_Parser_isErrSet_o = db_declare(Fast_Parser_o, "isErrSet()", db_typedef(db_method_o));
    if (!Fast_Parser_isErrSet_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::isErrSet()'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::isErrSet() */
    if (!db_checkState(Fast_Parser_isErrSet_o, DB_DEFINED)) {
        db_function(Fast_Parser_isErrSet_o)->returnType = db_resolve_ext(Fast_Parser_isErrSet_o, NULL, "::hyve::lang::bool", FALSE, "element ::hyve::Fast::Parser::isErrSet().returnType");
        db_function(Fast_Parser_isErrSet_o)->returnsReference = FALSE;
        Fast_Parser_isErrSet_o->virtual = FALSE;
        
        /* Bind Fast_Parser_isErrSet_o with C-function */
        db_function(Fast_Parser_isErrSet_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Parser_isErrSet(void *args, void *result);
        db_function(Fast_Parser_isErrSet_o)->impl = (db_word)__Fast_Parser_isErrSet;
        if (db_define(Fast_Parser_isErrSet_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::isErrSet()'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::isLocal */
    Fast_Parser_isLocal_o = db_declare(Fast_Parser_o, "isLocal", db_typedef(db_member_o));
    if (!Fast_Parser_isLocal_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::isLocal'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::isLocal */
    if (!db_checkState(Fast_Parser_isLocal_o, DB_DEFINED)) {
        Fast_Parser_isLocal_o->type = db_resolve_ext(Fast_Parser_isLocal_o, NULL, "::hyve::lang::bool", FALSE, "element ::hyve::Fast::Parser::isLocal.type");
        Fast_Parser_isLocal_o->modifiers = 0x3;
        Fast_Parser_isLocal_o->state = 0x6;
        Fast_Parser_isLocal_o->weak = FALSE;
        Fast_Parser_isLocal_o->id = 18;
        if (db_define(Fast_Parser_isLocal_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::isLocal'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::lastFailedResolve */
    Fast_Parser_lastFailedResolve_o = db_declare(Fast_Parser_o, "lastFailedResolve", db_typedef(db_member_o));
    if (!Fast_Parser_lastFailedResolve_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::lastFailedResolve'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::lastFailedResolve */
    if (!db_checkState(Fast_Parser_lastFailedResolve_o, DB_DEFINED)) {
        Fast_Parser_lastFailedResolve_o->type = db_resolve_ext(Fast_Parser_lastFailedResolve_o, NULL, "::hyve::lang::string", FALSE, "element ::hyve::Fast::Parser::lastFailedResolve.type");
        Fast_Parser_lastFailedResolve_o->modifiers = 0x3;
        Fast_Parser_lastFailedResolve_o->state = 0x6;
        Fast_Parser_lastFailedResolve_o->weak = FALSE;
        Fast_Parser_lastFailedResolve_o->id = 21;
        if (db_define(Fast_Parser_lastFailedResolve_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::lastFailedResolve'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::line */
    Fast_Parser_line_o = db_declare(Fast_Parser_o, "line", db_typedef(db_member_o));
    if (!Fast_Parser_line_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::line'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::line */
    if (!db_checkState(Fast_Parser_line_o, DB_DEFINED)) {
        Fast_Parser_line_o->type = db_resolve_ext(Fast_Parser_line_o, NULL, "::hyve::lang::uint32", FALSE, "element ::hyve::Fast::Parser::line.type");
        Fast_Parser_line_o->modifiers = 0x4;
        Fast_Parser_line_o->state = 0x6;
        Fast_Parser_line_o->weak = FALSE;
        Fast_Parser_line_o->id = 3;
        if (db_define(Fast_Parser_line_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::line'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::lookup(lang::string id,lang::object source) */
    Fast_Parser_lookup_o = db_declare(Fast_Parser_o, "lookup(lang::string id,lang::object source)", db_typedef(db_method_o));
    if (!Fast_Parser_lookup_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::lookup(lang::string id,lang::object source)'.");
        goto error;
    }

    /* Declare ::hyve::Fast::Parser::lvalue */
    Fast_Parser_lvalue_o = db_declare(Fast_Parser_o, "lvalue", db_typedef(db_member_o));
    if (!Fast_Parser_lvalue_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::lvalue'.");
        goto error;
    }

    /* Declare ::hyve::Fast::Parser::lvalueSp */
    Fast_Parser_lvalueSp_o = db_declare(Fast_Parser_o, "lvalueSp", db_typedef(db_member_o));
    if (!Fast_Parser_lvalueSp_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::lvalueSp'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::lvalueSp */
    if (!db_checkState(Fast_Parser_lvalueSp_o, DB_DEFINED)) {
        Fast_Parser_lvalueSp_o->type = db_resolve_ext(Fast_Parser_lvalueSp_o, NULL, "::hyve::lang::int32", FALSE, "element ::hyve::Fast::Parser::lvalueSp.type");
        Fast_Parser_lvalueSp_o->modifiers = 0x3;
        Fast_Parser_lvalueSp_o->state = 0x6;
        Fast_Parser_lvalueSp_o->weak = FALSE;
        Fast_Parser_lvalueSp_o->id = 34;
        if (db_define(Fast_Parser_lvalueSp_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::lvalueSp'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::observerPop() */
    Fast_Parser_observerPop_o = db_declare(Fast_Parser_o, "observerPop()", db_typedef(db_method_o));
    if (!Fast_Parser_observerPop_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::observerPop()'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::observerPop() */
    if (!db_checkState(Fast_Parser_observerPop_o, DB_DEFINED)) {
        db_function(Fast_Parser_observerPop_o)->returnType = NULL;
        db_function(Fast_Parser_observerPop_o)->returnsReference = FALSE;
        Fast_Parser_observerPop_o->virtual = FALSE;
        
        /* Bind Fast_Parser_observerPop_o with C-function */
        db_function(Fast_Parser_observerPop_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Parser_observerPop(void *args, void *result);
        db_function(Fast_Parser_observerPop_o)->impl = (db_word)__Fast_Parser_observerPop;
        if (db_define(Fast_Parser_observerPop_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::observerPop()'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::observerPush() */
    Fast_Parser_observerPush_o = db_declare(Fast_Parser_o, "observerPush()", db_typedef(db_method_o));
    if (!Fast_Parser_observerPush_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::observerPush()'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::observerPush() */
    if (!db_checkState(Fast_Parser_observerPush_o, DB_DEFINED)) {
        db_function(Fast_Parser_observerPush_o)->returnType = NULL;
        db_function(Fast_Parser_observerPush_o)->returnsReference = FALSE;
        Fast_Parser_observerPush_o->virtual = FALSE;
        
        /* Bind Fast_Parser_observerPush_o with C-function */
        db_function(Fast_Parser_observerPush_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Parser_observerPush(void *args, void *result);
        db_function(Fast_Parser_observerPush_o)->impl = (db_word)__Fast_Parser_observerPush;
        if (db_define(Fast_Parser_observerPush_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::observerPush()'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::parse() */
    Fast_Parser_parse_o = db_declare(Fast_Parser_o, "parse()", db_typedef(db_method_o));
    if (!Fast_Parser_parse_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::parse()'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::parse() */
    if (!db_checkState(Fast_Parser_parse_o, DB_DEFINED)) {
        db_function(Fast_Parser_parse_o)->returnType = db_resolve_ext(Fast_Parser_parse_o, NULL, "::hyve::lang::uint32", FALSE, "element ::hyve::Fast::Parser::parse().returnType");
        db_function(Fast_Parser_parse_o)->returnsReference = FALSE;
        Fast_Parser_parse_o->virtual = FALSE;
        
        /* Bind Fast_Parser_parse_o with C-function */
        db_function(Fast_Parser_parse_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Parser_parse(void *args, void *result);
        db_function(Fast_Parser_parse_o)->impl = (db_word)__Fast_Parser_parse;
        if (db_define(Fast_Parser_parse_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::parse()'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::parseSingleExpr */
    Fast_Parser_parseSingleExpr_o = db_declare(Fast_Parser_o, "parseSingleExpr", db_typedef(db_member_o));
    if (!Fast_Parser_parseSingleExpr_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::parseSingleExpr'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::parseSingleExpr */
    if (!db_checkState(Fast_Parser_parseSingleExpr_o, DB_DEFINED)) {
        Fast_Parser_parseSingleExpr_o->type = db_resolve_ext(Fast_Parser_parseSingleExpr_o, NULL, "::hyve::lang::bool", FALSE, "element ::hyve::Fast::Parser::parseSingleExpr.type");
        Fast_Parser_parseSingleExpr_o->modifiers = 0x3;
        Fast_Parser_parseSingleExpr_o->state = 0x6;
        Fast_Parser_parseSingleExpr_o->weak = FALSE;
        Fast_Parser_parseSingleExpr_o->id = 19;
        if (db_define(Fast_Parser_parseSingleExpr_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::parseSingleExpr'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::pass */
    Fast_Parser_pass_o = db_declare(Fast_Parser_o, "pass", db_typedef(db_member_o));
    if (!Fast_Parser_pass_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::pass'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::pass */
    if (!db_checkState(Fast_Parser_pass_o, DB_DEFINED)) {
        Fast_Parser_pass_o->type = db_resolve_ext(Fast_Parser_pass_o, NULL, "::hyve::lang::uint32", FALSE, "element ::hyve::Fast::Parser::pass.type");
        Fast_Parser_pass_o->modifiers = 0x3;
        Fast_Parser_pass_o->state = 0x6;
        Fast_Parser_pass_o->weak = FALSE;
        Fast_Parser_pass_o->id = 14;
        if (db_define(Fast_Parser_pass_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::pass'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::popComplexType() */
    Fast_Parser_popComplexType_o = db_declare(Fast_Parser_o, "popComplexType()", db_typedef(db_method_o));
    if (!Fast_Parser_popComplexType_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::popComplexType()'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::popComplexType() */
    if (!db_checkState(Fast_Parser_popComplexType_o, DB_DEFINED)) {
        db_function(Fast_Parser_popComplexType_o)->returnType = NULL;
        db_function(Fast_Parser_popComplexType_o)->returnsReference = FALSE;
        Fast_Parser_popComplexType_o->virtual = FALSE;
        
        /* Bind Fast_Parser_popComplexType_o with C-function */
        db_function(Fast_Parser_popComplexType_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Parser_popComplexType(void *args, void *result);
        db_function(Fast_Parser_popComplexType_o)->impl = (db_word)__Fast_Parser_popComplexType;
        if (db_define(Fast_Parser_popComplexType_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::popComplexType()'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::popLvalue() */
    Fast_Parser_popLvalue_o = db_declare(Fast_Parser_o, "popLvalue()", db_typedef(db_method_o));
    if (!Fast_Parser_popLvalue_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::popLvalue()'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::popLvalue() */
    if (!db_checkState(Fast_Parser_popLvalue_o, DB_DEFINED)) {
        db_function(Fast_Parser_popLvalue_o)->returnType = NULL;
        db_function(Fast_Parser_popLvalue_o)->returnsReference = FALSE;
        Fast_Parser_popLvalue_o->virtual = FALSE;
        
        /* Bind Fast_Parser_popLvalue_o with C-function */
        db_function(Fast_Parser_popLvalue_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Parser_popLvalue(void *args, void *result);
        db_function(Fast_Parser_popLvalue_o)->impl = (db_word)__Fast_Parser_popLvalue;
        if (db_define(Fast_Parser_popLvalue_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::popLvalue()'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::preprocessed */
    Fast_Parser_preprocessed_o = db_declare(Fast_Parser_o, "preprocessed", db_typedef(db_member_o));
    if (!Fast_Parser_preprocessed_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::preprocessed'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::preprocessed */
    if (!db_checkState(Fast_Parser_preprocessed_o, DB_DEFINED)) {
        Fast_Parser_preprocessed_o->type = db_resolve_ext(Fast_Parser_preprocessed_o, NULL, "::hyve::lang::string", FALSE, "element ::hyve::Fast::Parser::preprocessed.type");
        Fast_Parser_preprocessed_o->modifiers = 0x4;
        Fast_Parser_preprocessed_o->state = 0x6;
        Fast_Parser_preprocessed_o->weak = FALSE;
        Fast_Parser_preprocessed_o->id = 1;
        if (db_define(Fast_Parser_preprocessed_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::preprocessed'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::pushReturnAsLvalue(lang::function function) */
    Fast_Parser_pushReturnAsLvalue_o = db_declare(Fast_Parser_o, "pushReturnAsLvalue(lang::function function)", db_typedef(db_method_o));
    if (!Fast_Parser_pushReturnAsLvalue_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::pushReturnAsLvalue(lang::function function)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::pushReturnAsLvalue(lang::function function) */
    if (!db_checkState(Fast_Parser_pushReturnAsLvalue_o, DB_DEFINED)) {
        db_function(Fast_Parser_pushReturnAsLvalue_o)->returnType = NULL;
        db_function(Fast_Parser_pushReturnAsLvalue_o)->returnsReference = FALSE;
        Fast_Parser_pushReturnAsLvalue_o->virtual = FALSE;
        
        /* Bind Fast_Parser_pushReturnAsLvalue_o with C-function */
        db_function(Fast_Parser_pushReturnAsLvalue_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Parser_pushReturnAsLvalue(void *args, void *result);
        db_function(Fast_Parser_pushReturnAsLvalue_o)->impl = (db_word)__Fast_Parser_pushReturnAsLvalue;
        if (db_define(Fast_Parser_pushReturnAsLvalue_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::pushReturnAsLvalue(lang::function function)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::pushScope() */
    Fast_Parser_pushScope_o = db_declare(Fast_Parser_o, "pushScope()", db_typedef(db_method_o));
    if (!Fast_Parser_pushScope_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::pushScope()'.");
        goto error;
    }

    /* Declare ::hyve::Fast::Parser::reset() */
    Fast_Parser_reset_o = db_declare(Fast_Parser_o, "reset()", db_typedef(db_method_o));
    if (!Fast_Parser_reset_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::reset()'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::reset() */
    if (!db_checkState(Fast_Parser_reset_o, DB_DEFINED)) {
        db_function(Fast_Parser_reset_o)->returnType = NULL;
        db_function(Fast_Parser_reset_o)->returnsReference = FALSE;
        Fast_Parser_reset_o->virtual = FALSE;
        
        /* Bind Fast_Parser_reset_o with C-function */
        db_function(Fast_Parser_reset_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Parser_reset(void *args, void *result);
        db_function(Fast_Parser_reset_o)->impl = (db_word)__Fast_Parser_reset;
        if (db_define(Fast_Parser_reset_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::reset()'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::scope */
    Fast_Parser_scope_o = db_declare(Fast_Parser_o, "scope", db_typedef(db_member_o));
    if (!Fast_Parser_scope_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::scope'.");
        goto error;
    }

    /* Declare ::hyve::Fast::Parser::singleExpr */
    Fast_Parser_singleExpr_o = db_declare(Fast_Parser_o, "singleExpr", db_typedef(db_member_o));
    if (!Fast_Parser_singleExpr_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::singleExpr'.");
        goto error;
    }

    /* Declare ::hyve::Fast::Parser::source */
    Fast_Parser_source_o = db_declare(Fast_Parser_o, "source", db_typedef(db_member_o));
    if (!Fast_Parser_source_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::source'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::source */
    if (!db_checkState(Fast_Parser_source_o, DB_DEFINED)) {
        Fast_Parser_source_o->type = db_resolve_ext(Fast_Parser_source_o, NULL, "::hyve::lang::string", FALSE, "element ::hyve::Fast::Parser::source.type");
        Fast_Parser_source_o->modifiers = 0x0;
        Fast_Parser_source_o->state = 0x6;
        Fast_Parser_source_o->weak = FALSE;
        Fast_Parser_source_o->id = 0;
        if (db_define(Fast_Parser_source_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::source'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::staged */
    Fast_Parser_staged_o = db_declare(Fast_Parser_o, "staged", db_typedef(db_member_o));
    if (!Fast_Parser_staged_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::staged'.");
        goto error;
    }

    /* Declare ::hyve::Fast::Parser::stagedCount */
    Fast_Parser_stagedCount_o = db_declare(Fast_Parser_o, "stagedCount", db_typedef(db_member_o));
    if (!Fast_Parser_stagedCount_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::stagedCount'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::stagedCount */
    if (!db_checkState(Fast_Parser_stagedCount_o, DB_DEFINED)) {
        Fast_Parser_stagedCount_o->type = db_resolve_ext(Fast_Parser_stagedCount_o, NULL, "::hyve::lang::uint32", FALSE, "element ::hyve::Fast::Parser::stagedCount.type");
        Fast_Parser_stagedCount_o->modifiers = 0x3;
        Fast_Parser_stagedCount_o->state = 0x6;
        Fast_Parser_stagedCount_o->weak = FALSE;
        Fast_Parser_stagedCount_o->id = 31;
        if (db_define(Fast_Parser_stagedCount_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::stagedCount'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::stagedId */
    Fast_Parser_stagedId_o = db_declare(Fast_Parser_o, "stagedId", db_typedef(db_struct_o));
    if (!Fast_Parser_stagedId_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::stagedId'.");
        goto error;
    }

    /* Declare ::hyve::Fast::Parser::stagedId::column */
    Fast_Parser_stagedId_column_o = db_declare(Fast_Parser_stagedId_o, "column", db_typedef(db_member_o));
    if (!Fast_Parser_stagedId_column_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::stagedId::column'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::stagedId::column */
    if (!db_checkState(Fast_Parser_stagedId_column_o, DB_DEFINED)) {
        Fast_Parser_stagedId_column_o->type = db_resolve_ext(Fast_Parser_stagedId_column_o, NULL, "::hyve::lang::uint32", FALSE, "element ::hyve::Fast::Parser::stagedId::column.type");
        Fast_Parser_stagedId_column_o->modifiers = 0x0;
        Fast_Parser_stagedId_column_o->state = 0x6;
        Fast_Parser_stagedId_column_o->weak = FALSE;
        Fast_Parser_stagedId_column_o->id = 3;
        if (db_define(Fast_Parser_stagedId_column_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::stagedId::column'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::stagedId::found */
    Fast_Parser_stagedId_found_o = db_declare(Fast_Parser_stagedId_o, "found", db_typedef(db_member_o));
    if (!Fast_Parser_stagedId_found_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::stagedId::found'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::stagedId::found */
    if (!db_checkState(Fast_Parser_stagedId_found_o, DB_DEFINED)) {
        Fast_Parser_stagedId_found_o->type = db_resolve_ext(Fast_Parser_stagedId_found_o, NULL, "::hyve::lang::bool", FALSE, "element ::hyve::Fast::Parser::stagedId::found.type");
        Fast_Parser_stagedId_found_o->modifiers = 0x0;
        Fast_Parser_stagedId_found_o->state = 0x6;
        Fast_Parser_stagedId_found_o->weak = FALSE;
        Fast_Parser_stagedId_found_o->id = 1;
        if (db_define(Fast_Parser_stagedId_found_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::stagedId::found'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::stagedId::line */
    Fast_Parser_stagedId_line_o = db_declare(Fast_Parser_stagedId_o, "line", db_typedef(db_member_o));
    if (!Fast_Parser_stagedId_line_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::stagedId::line'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::stagedId::line */
    if (!db_checkState(Fast_Parser_stagedId_line_o, DB_DEFINED)) {
        Fast_Parser_stagedId_line_o->type = db_resolve_ext(Fast_Parser_stagedId_line_o, NULL, "::hyve::lang::uint32", FALSE, "element ::hyve::Fast::Parser::stagedId::line.type");
        Fast_Parser_stagedId_line_o->modifiers = 0x0;
        Fast_Parser_stagedId_line_o->state = 0x6;
        Fast_Parser_stagedId_line_o->weak = FALSE;
        Fast_Parser_stagedId_line_o->id = 2;
        if (db_define(Fast_Parser_stagedId_line_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::stagedId::line'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::stagedId::name */
    Fast_Parser_stagedId_name_o = db_declare(Fast_Parser_stagedId_o, "name", db_typedef(db_member_o));
    if (!Fast_Parser_stagedId_name_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::stagedId::name'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::stagedId::name */
    if (!db_checkState(Fast_Parser_stagedId_name_o, DB_DEFINED)) {
        Fast_Parser_stagedId_name_o->type = db_resolve_ext(Fast_Parser_stagedId_name_o, NULL, "::hyve::lang::string", FALSE, "element ::hyve::Fast::Parser::stagedId::name.type");
        Fast_Parser_stagedId_name_o->modifiers = 0x0;
        Fast_Parser_stagedId_name_o->state = 0x6;
        Fast_Parser_stagedId_name_o->weak = FALSE;
        Fast_Parser_stagedId_name_o->id = 0;
        if (db_define(Fast_Parser_stagedId_name_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::stagedId::name'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::Parser::stagedId */
    if (!db_checkState(Fast_Parser_stagedId_o, DB_DEFINED)) {
        db_type(Fast_Parser_stagedId_o)->defaultType = db_resolve_ext(Fast_Parser_stagedId_o, NULL, "::hyve::lang::member", FALSE, "element ::hyve::Fast::Parser::stagedId.defaultType");
        db_type(Fast_Parser_stagedId_o)->parentType = NULL;
        db_type(Fast_Parser_stagedId_o)->parentState = 0x0;
        db_interface(Fast_Parser_stagedId_o)->base = NULL;
        Fast_Parser_stagedId_o->baseAccess = 0x0;
        if (db_define(Fast_Parser_stagedId_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::stagedId'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::Parser::staged */
    if (!db_checkState(Fast_Parser_staged_o, DB_DEFINED)) {
        Fast_Parser_staged_o->type = db_resolve_ext(Fast_Parser_staged_o, NULL, "::hyve::lang::array{::hyve::Fast::Parser::stagedId,64,::hyve::Fast::Parser::stagedId}", FALSE, "element ::hyve::Fast::Parser::staged.type");
        Fast_Parser_staged_o->modifiers = 0x3;
        Fast_Parser_staged_o->state = 0x6;
        Fast_Parser_staged_o->weak = FALSE;
        Fast_Parser_staged_o->id = 30;
        if (db_define(Fast_Parser_staged_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::staged'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::stagingAllowed */
    Fast_Parser_stagingAllowed_o = db_declare(Fast_Parser_o, "stagingAllowed", db_typedef(db_member_o));
    if (!Fast_Parser_stagingAllowed_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::stagingAllowed'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::stagingAllowed */
    if (!db_checkState(Fast_Parser_stagingAllowed_o, DB_DEFINED)) {
        Fast_Parser_stagingAllowed_o->type = db_resolve_ext(Fast_Parser_stagingAllowed_o, NULL, "::hyve::lang::bool", FALSE, "element ::hyve::Fast::Parser::stagingAllowed.type");
        Fast_Parser_stagingAllowed_o->modifiers = 0x3;
        Fast_Parser_stagingAllowed_o->state = 0x6;
        Fast_Parser_stagingAllowed_o->weak = FALSE;
        Fast_Parser_stagingAllowed_o->id = 32;
        if (db_define(Fast_Parser_stagingAllowed_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::stagingAllowed'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::token */
    Fast_Parser_token_o = db_declare(Fast_Parser_o, "token", db_typedef(db_member_o));
    if (!Fast_Parser_token_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::token'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::token */
    if (!db_checkState(Fast_Parser_token_o, DB_DEFINED)) {
        Fast_Parser_token_o->type = db_resolve_ext(Fast_Parser_token_o, NULL, "::hyve::lang::string", FALSE, "element ::hyve::Fast::Parser::token.type");
        Fast_Parser_token_o->modifiers = 0x4;
        Fast_Parser_token_o->state = 0x6;
        Fast_Parser_token_o->weak = FALSE;
        Fast_Parser_token_o->id = 5;
        if (db_define(Fast_Parser_token_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::token'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::variableCount */
    Fast_Parser_variableCount_o = db_declare(Fast_Parser_o, "variableCount", db_typedef(db_member_o));
    if (!Fast_Parser_variableCount_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::variableCount'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::variableCount */
    if (!db_checkState(Fast_Parser_variableCount_o, DB_DEFINED)) {
        Fast_Parser_variableCount_o->type = db_resolve_ext(Fast_Parser_variableCount_o, NULL, "::hyve::lang::uint32", FALSE, "element ::hyve::Fast::Parser::variableCount.type");
        Fast_Parser_variableCount_o->modifiers = 0x6;
        Fast_Parser_variableCount_o->state = 0x6;
        Fast_Parser_variableCount_o->weak = FALSE;
        Fast_Parser_variableCount_o->id = 23;
        if (db_define(Fast_Parser_variableCount_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::variableCount'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::variablePushed */
    Fast_Parser_variablePushed_o = db_declare(Fast_Parser_o, "variablePushed", db_typedef(db_member_o));
    if (!Fast_Parser_variablePushed_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::variablePushed'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::variablePushed */
    if (!db_checkState(Fast_Parser_variablePushed_o, DB_DEFINED)) {
        Fast_Parser_variablePushed_o->type = db_resolve_ext(Fast_Parser_variablePushed_o, NULL, "::hyve::lang::bool", FALSE, "element ::hyve::Fast::Parser::variablePushed.type");
        Fast_Parser_variablePushed_o->modifiers = 0x6;
        Fast_Parser_variablePushed_o->state = 0x6;
        Fast_Parser_variablePushed_o->weak = FALSE;
        Fast_Parser_variablePushed_o->id = 25;
        if (db_define(Fast_Parser_variablePushed_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::variablePushed'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::variables */
    Fast_Parser_variables_o = db_declare(Fast_Parser_o, "variables", db_typedef(db_member_o));
    if (!Fast_Parser_variables_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::variables'.");
        goto error;
    }

    /* Declare ::hyve::Fast::Parser::variablesInitialized */
    Fast_Parser_variablesInitialized_o = db_declare(Fast_Parser_o, "variablesInitialized", db_typedef(db_member_o));
    if (!Fast_Parser_variablesInitialized_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::variablesInitialized'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::variablesInitialized */
    if (!db_checkState(Fast_Parser_variablesInitialized_o, DB_DEFINED)) {
        Fast_Parser_variablesInitialized_o->type = db_resolve_ext(Fast_Parser_variablesInitialized_o, NULL, "::hyve::lang::bool", FALSE, "element ::hyve::Fast::Parser::variablesInitialized.type");
        Fast_Parser_variablesInitialized_o->modifiers = 0x6;
        Fast_Parser_variablesInitialized_o->state = 0x6;
        Fast_Parser_variablesInitialized_o->weak = FALSE;
        Fast_Parser_variablesInitialized_o->id = 24;
        if (db_define(Fast_Parser_variablesInitialized_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::variablesInitialized'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::warnings */
    Fast_Parser_warnings_o = db_declare(Fast_Parser_o, "warnings", db_typedef(db_member_o));
    if (!Fast_Parser_warnings_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::warnings'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::warnings */
    if (!db_checkState(Fast_Parser_warnings_o, DB_DEFINED)) {
        Fast_Parser_warnings_o->type = db_resolve_ext(Fast_Parser_warnings_o, NULL, "::hyve::lang::uint32", FALSE, "element ::hyve::Fast::Parser::warnings.type");
        Fast_Parser_warnings_o->modifiers = 0x4;
        Fast_Parser_warnings_o->state = 0x6;
        Fast_Parser_warnings_o->weak = FALSE;
        Fast_Parser_warnings_o->id = 9;
        if (db_define(Fast_Parser_warnings_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::warnings'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::ParserDeclaration */
    Fast_ParserDeclaration_o = db_declare(Fast_o, "ParserDeclaration", db_typedef(db_struct_o));
    if (!Fast_ParserDeclaration_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::ParserDeclaration'.");
        goto error;
    }

    /* Declare ::hyve::Fast::ParserDeclaration::name */
    Fast_ParserDeclaration_name_o = db_declare(Fast_ParserDeclaration_o, "name", db_typedef(db_member_o));
    if (!Fast_ParserDeclaration_name_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::ParserDeclaration::name'.");
        goto error;
    }

    /* Define ::hyve::Fast::ParserDeclaration::name */
    if (!db_checkState(Fast_ParserDeclaration_name_o, DB_DEFINED)) {
        Fast_ParserDeclaration_name_o->type = db_resolve_ext(Fast_ParserDeclaration_name_o, NULL, "::hyve::lang::string", FALSE, "element ::hyve::Fast::ParserDeclaration::name.type");
        Fast_ParserDeclaration_name_o->modifiers = 0x0;
        Fast_ParserDeclaration_name_o->state = 0x6;
        Fast_ParserDeclaration_name_o->weak = FALSE;
        Fast_ParserDeclaration_name_o->id = 0;
        if (db_define(Fast_ParserDeclaration_name_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::ParserDeclaration::name'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::ParserDeclaration::variable */
    Fast_ParserDeclaration_variable_o = db_declare(Fast_ParserDeclaration_o, "variable", db_typedef(db_member_o));
    if (!Fast_ParserDeclaration_variable_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::ParserDeclaration::variable'.");
        goto error;
    }

    /* Declare ::hyve::Fast::ParserDeclarationSeq */
    Fast_ParserDeclarationSeq_o = db_declare(Fast_o, "ParserDeclarationSeq", db_typedef(db_typedef_o));
    if (!Fast_ParserDeclarationSeq_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::ParserDeclarationSeq'.");
        goto error;
    }

    /* Define ::hyve::Fast::ParserDeclarationSeq */
    if (!db_checkState(Fast_ParserDeclarationSeq_o, DB_DEFINED)) {
        Fast_ParserDeclarationSeq_o->type = db_resolve_ext(Fast_ParserDeclarationSeq_o, NULL, "::hyve::lang::sequence{::hyve::Fast::ParserDeclaration,256}", FALSE, "element ::hyve::Fast::ParserDeclarationSeq.type");
        if (db_define(Fast_ParserDeclarationSeq_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::ParserDeclarationSeq'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::ParserNew */
    Fast_ParserNew_o = db_declare(Fast_o, "ParserNew", db_typedef(db_struct_o));
    if (!Fast_ParserNew_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::ParserNew'.");
        goto error;
    }

    /* Declare ::hyve::Fast::ParserNew::attr */
    Fast_ParserNew_attr_o = db_declare(Fast_ParserNew_o, "attr", db_typedef(db_member_o));
    if (!Fast_ParserNew_attr_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::ParserNew::attr'.");
        goto error;
    }

    /* Declare ::hyve::Fast::ParserNew::kind */
    Fast_ParserNew_kind_o = db_declare(Fast_ParserNew_o, "kind", db_typedef(db_member_o));
    if (!Fast_ParserNew_kind_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::ParserNew::kind'.");
        goto error;
    }

    /* Define ::hyve::Fast::ParserNew::kind */
    if (!db_checkState(Fast_ParserNew_kind_o, DB_DEFINED)) {
        Fast_ParserNew_kind_o->type = db_resolve_ext(Fast_ParserNew_kind_o, NULL, "::hyve::Fast::nodeKind", FALSE, "element ::hyve::Fast::ParserNew::kind.type");
        Fast_ParserNew_kind_o->modifiers = 0x0;
        Fast_ParserNew_kind_o->state = 0x6;
        Fast_ParserNew_kind_o->weak = FALSE;
        Fast_ParserNew_kind_o->id = 0;
        if (db_define(Fast_ParserNew_kind_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::ParserNew::kind'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::ParserNew::name */
    Fast_ParserNew_name_o = db_declare(Fast_ParserNew_o, "name", db_typedef(db_member_o));
    if (!Fast_ParserNew_name_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::ParserNew::name'.");
        goto error;
    }

    /* Declare ::hyve::Fast::ParserNew::parent */
    Fast_ParserNew_parent_o = db_declare(Fast_ParserNew_o, "parent", db_typedef(db_member_o));
    if (!Fast_ParserNew_parent_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::ParserNew::parent'.");
        goto error;
    }

    /* Declare ::hyve::Fast::PostfixExpr */
    Fast_PostfixExpr_o = db_declare(Fast_o, "PostfixExpr", db_typedef(db_class_o));
    if (!Fast_PostfixExpr_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::PostfixExpr'.");
        goto error;
    }

    /* Declare ::hyve::Fast::PostfixExpr::lvalue */
    Fast_PostfixExpr_lvalue_o = db_declare(Fast_PostfixExpr_o, "lvalue", db_typedef(db_member_o));
    if (!Fast_PostfixExpr_lvalue_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::PostfixExpr::lvalue'.");
        goto error;
    }

    /* Declare ::hyve::Fast::PostfixExpr::operator */
    Fast_PostfixExpr_operator_o = db_declare(Fast_PostfixExpr_o, "operator", db_typedef(db_member_o));
    if (!Fast_PostfixExpr_operator_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::PostfixExpr::operator'.");
        goto error;
    }

    /* Define ::hyve::Fast::PostfixExpr::operator */
    if (!db_checkState(Fast_PostfixExpr_operator_o, DB_DEFINED)) {
        Fast_PostfixExpr_operator_o->type = db_resolve_ext(Fast_PostfixExpr_operator_o, NULL, "::hyve::lang::operatorKind", FALSE, "element ::hyve::Fast::PostfixExpr::operator.type");
        Fast_PostfixExpr_operator_o->modifiers = 0x0;
        Fast_PostfixExpr_operator_o->state = 0x6;
        Fast_PostfixExpr_operator_o->weak = FALSE;
        Fast_PostfixExpr_operator_o->id = 1;
        if (db_define(Fast_PostfixExpr_operator_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::PostfixExpr::operator'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::SignedInteger */
    Fast_SignedInteger_o = db_declare(Fast_o, "SignedInteger", db_typedef(db_class_o));
    if (!Fast_SignedInteger_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::SignedInteger'.");
        goto error;
    }

    /* Declare ::hyve::Fast::SignedInteger::value */
    Fast_SignedInteger_value_o = db_declare(Fast_SignedInteger_o, "value", db_typedef(db_member_o));
    if (!Fast_SignedInteger_value_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::SignedInteger::value'.");
        goto error;
    }

    /* Define ::hyve::Fast::SignedInteger::value */
    if (!db_checkState(Fast_SignedInteger_value_o, DB_DEFINED)) {
        Fast_SignedInteger_value_o->type = db_resolve_ext(Fast_SignedInteger_value_o, NULL, "::hyve::lang::int64", FALSE, "element ::hyve::Fast::SignedInteger::value.type");
        Fast_SignedInteger_value_o->modifiers = 0x0;
        Fast_SignedInteger_value_o->state = 0x6;
        Fast_SignedInteger_value_o->weak = FALSE;
        Fast_SignedInteger_value_o->id = 0;
        if (db_define(Fast_SignedInteger_value_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::SignedInteger::value'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::StaticInitializer */
    Fast_StaticInitializer_o = db_declare(Fast_o, "StaticInitializer", db_typedef(db_class_o));
    if (!Fast_StaticInitializer_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::StaticInitializer'.");
        goto error;
    }

    /* Declare ::hyve::Fast::StaticInitializer::frames */
    Fast_StaticInitializer_frames_o = db_declare(Fast_StaticInitializer_o, "frames", db_typedef(db_member_o));
    if (!Fast_StaticInitializer_frames_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::StaticInitializer::frames'.");
        goto error;
    }

    /* Declare ::hyve::Fast::StaticInitializerFrame */
    Fast_StaticInitializerFrame_o = db_declare(Fast_o, "StaticInitializerFrame", db_typedef(db_struct_o));
    if (!Fast_StaticInitializerFrame_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::StaticInitializerFrame'.");
        goto error;
    }

    /* Declare ::hyve::Fast::StaticInitializerFrame::keyPtr */
    Fast_StaticInitializerFrame_keyPtr_o = db_declare(Fast_StaticInitializerFrame_o, "keyPtr", db_typedef(db_member_o));
    if (!Fast_StaticInitializerFrame_keyPtr_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::StaticInitializerFrame::keyPtr'.");
        goto error;
    }

    /* Declare ::hyve::Fast::StaticInitializerFrame::ptr */
    Fast_StaticInitializerFrame_ptr_o = db_declare(Fast_StaticInitializerFrame_o, "ptr", db_typedef(db_member_o));
    if (!Fast_StaticInitializerFrame_ptr_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::StaticInitializerFrame::ptr'.");
        goto error;
    }

    /* Declare ::hyve::Fast::String */
    Fast_String_o = db_declare(Fast_o, "String", db_typedef(db_class_o));
    if (!Fast_String_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::String'.");
        goto error;
    }

    /* Declare ::hyve::Fast::String::block */
    Fast_String_block_o = db_declare(Fast_String_o, "block", db_typedef(db_member_o));
    if (!Fast_String_block_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::String::block'.");
        goto error;
    }

    /* Declare ::hyve::Fast::String::elements */
    Fast_String_elements_o = db_declare(Fast_String_o, "elements", db_typedef(db_member_o));
    if (!Fast_String_elements_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::String::elements'.");
        goto error;
    }

    /* Define ::hyve::Fast::String::elements */
    if (!db_checkState(Fast_String_elements_o, DB_DEFINED)) {
        Fast_String_elements_o->type = db_resolve_ext(Fast_String_elements_o, NULL, "::hyve::lang::list{::hyve::Fast::Expression,0}", FALSE, "element ::hyve::Fast::String::elements.type");
        Fast_String_elements_o->modifiers = 0x4;
        Fast_String_elements_o->state = 0x6;
        Fast_String_elements_o->weak = FALSE;
        Fast_String_elements_o->id = 1;
        if (db_define(Fast_String_elements_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::String::elements'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::String::scope */
    Fast_String_scope_o = db_declare(Fast_String_o, "scope", db_typedef(db_member_o));
    if (!Fast_String_scope_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::String::scope'.");
        goto error;
    }

    /* Declare ::hyve::Fast::String::value */
    Fast_String_value_o = db_declare(Fast_String_o, "value", db_typedef(db_member_o));
    if (!Fast_String_value_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::String::value'.");
        goto error;
    }

    /* Define ::hyve::Fast::String::value */
    if (!db_checkState(Fast_String_value_o, DB_DEFINED)) {
        Fast_String_value_o->type = db_resolve_ext(Fast_String_value_o, NULL, "::hyve::lang::string", FALSE, "element ::hyve::Fast::String::value.type");
        Fast_String_value_o->modifiers = 0x0;
        Fast_String_value_o->state = 0x6;
        Fast_String_value_o->weak = FALSE;
        Fast_String_value_o->id = 0;
        if (db_define(Fast_String_value_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::String::value'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Template */
    Fast_Template_o = db_declare(Fast_o, "Template", db_typedef(db_class_o));
    if (!Fast_Template_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Template'.");
        goto error;
    }

    /* Declare ::hyve::Fast::TernaryExpr */
    Fast_TernaryExpr_o = db_declare(Fast_o, "TernaryExpr", db_typedef(db_class_o));
    if (!Fast_TernaryExpr_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::TernaryExpr'.");
        goto error;
    }

    /* Declare ::hyve::Fast::TernaryExpr::condition */
    Fast_TernaryExpr_condition_o = db_declare(Fast_TernaryExpr_o, "condition", db_typedef(db_member_o));
    if (!Fast_TernaryExpr_condition_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::TernaryExpr::condition'.");
        goto error;
    }

    /* Declare ::hyve::Fast::TernaryExpr::ifFalse */
    Fast_TernaryExpr_ifFalse_o = db_declare(Fast_TernaryExpr_o, "ifFalse", db_typedef(db_member_o));
    if (!Fast_TernaryExpr_ifFalse_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::TernaryExpr::ifFalse'.");
        goto error;
    }

    /* Declare ::hyve::Fast::TernaryExpr::ifFalseExpr */
    Fast_TernaryExpr_ifFalseExpr_o = db_declare(Fast_TernaryExpr_o, "ifFalseExpr", db_typedef(db_member_o));
    if (!Fast_TernaryExpr_ifFalseExpr_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::TernaryExpr::ifFalseExpr'.");
        goto error;
    }

    /* Declare ::hyve::Fast::TernaryExpr::ifstmt */
    Fast_TernaryExpr_ifstmt_o = db_declare(Fast_TernaryExpr_o, "ifstmt", db_typedef(db_member_o));
    if (!Fast_TernaryExpr_ifstmt_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::TernaryExpr::ifstmt'.");
        goto error;
    }

    /* Declare ::hyve::Fast::TernaryExpr::ifTrue */
    Fast_TernaryExpr_ifTrue_o = db_declare(Fast_TernaryExpr_o, "ifTrue", db_typedef(db_member_o));
    if (!Fast_TernaryExpr_ifTrue_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::TernaryExpr::ifTrue'.");
        goto error;
    }

    /* Declare ::hyve::Fast::TernaryExpr::ifTrueExpr */
    Fast_TernaryExpr_ifTrueExpr_o = db_declare(Fast_TernaryExpr_o, "ifTrueExpr", db_typedef(db_member_o));
    if (!Fast_TernaryExpr_ifTrueExpr_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::TernaryExpr::ifTrueExpr'.");
        goto error;
    }

    /* Declare ::hyve::Fast::TernaryExpr::result */
    Fast_TernaryExpr_result_o = db_declare(Fast_TernaryExpr_o, "result", db_typedef(db_member_o));
    if (!Fast_TernaryExpr_result_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::TernaryExpr::result'.");
        goto error;
    }

    /* Declare ::hyve::Fast::UnaryExpr */
    Fast_UnaryExpr_o = db_declare(Fast_o, "UnaryExpr", db_typedef(db_class_o));
    if (!Fast_UnaryExpr_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::UnaryExpr'.");
        goto error;
    }

    /* Declare ::hyve::Fast::UnaryExpr::lvalue */
    Fast_UnaryExpr_lvalue_o = db_declare(Fast_UnaryExpr_o, "lvalue", db_typedef(db_member_o));
    if (!Fast_UnaryExpr_lvalue_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::UnaryExpr::lvalue'.");
        goto error;
    }

    /* Declare ::hyve::Fast::UnaryExpr::operator */
    Fast_UnaryExpr_operator_o = db_declare(Fast_UnaryExpr_o, "operator", db_typedef(db_member_o));
    if (!Fast_UnaryExpr_operator_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::UnaryExpr::operator'.");
        goto error;
    }

    /* Define ::hyve::Fast::UnaryExpr::operator */
    if (!db_checkState(Fast_UnaryExpr_operator_o, DB_DEFINED)) {
        Fast_UnaryExpr_operator_o->type = db_resolve_ext(Fast_UnaryExpr_operator_o, NULL, "::hyve::lang::operatorKind", FALSE, "element ::hyve::Fast::UnaryExpr::operator.type");
        Fast_UnaryExpr_operator_o->modifiers = 0x0;
        Fast_UnaryExpr_operator_o->state = 0x6;
        Fast_UnaryExpr_operator_o->weak = FALSE;
        Fast_UnaryExpr_operator_o->id = 1;
        if (db_define(Fast_UnaryExpr_operator_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::UnaryExpr::operator'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Update */
    Fast_Update_o = db_declare(Fast_o, "Update", db_typedef(db_class_o));
    if (!Fast_Update_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Update'.");
        goto error;
    }

    /* Declare ::hyve::Fast::Update::block */
    Fast_Update_block_o = db_declare(Fast_Update_o, "block", db_typedef(db_member_o));
    if (!Fast_Update_block_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Update::block'.");
        goto error;
    }

    /* Declare ::hyve::Fast::Update::exprList */
    Fast_Update_exprList_o = db_declare(Fast_Update_o, "exprList", db_typedef(db_member_o));
    if (!Fast_Update_exprList_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Update::exprList'.");
        goto error;
    }

    /* Define ::hyve::Fast::Update::exprList */
    if (!db_checkState(Fast_Update_exprList_o, DB_DEFINED)) {
        Fast_Update_exprList_o->type = db_resolve_ext(Fast_Update_exprList_o, NULL, "::hyve::lang::list{::hyve::Fast::Expression,0}", FALSE, "element ::hyve::Fast::Update::exprList.type");
        Fast_Update_exprList_o->modifiers = 0x0;
        Fast_Update_exprList_o->state = 0x6;
        Fast_Update_exprList_o->weak = FALSE;
        Fast_Update_exprList_o->id = 0;
        if (db_define(Fast_Update_exprList_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Update::exprList'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Update::from */
    Fast_Update_from_o = db_declare(Fast_Update_o, "from", db_typedef(db_member_o));
    if (!Fast_Update_from_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Update::from'.");
        goto error;
    }

    /* Declare ::hyve::Fast::valueKind */
    Fast_valueKind_o = db_declare(Fast_o, "valueKind", db_typedef(db_enum_o));
    if (!Fast_valueKind_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::valueKind'.");
        goto error;
    }

    /* Declare ::hyve::Fast::valueKind::Boolean */
    Fast_valueKind_Boolean_o = db_declare(Fast_valueKind_o, "Boolean", db_typedef(db_constant_o));
    if (!Fast_valueKind_Boolean_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::valueKind::Boolean'.");
        goto error;
    }

    /* Define ::hyve::Fast::valueKind::Boolean */
    if (!db_checkState(Fast_valueKind_Boolean_o, DB_DEFINED)) {
        (*Fast_valueKind_Boolean_o) = 0;
        if (db_define(Fast_valueKind_Boolean_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::valueKind::Boolean'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::valueKind::Character */
    Fast_valueKind_Character_o = db_declare(Fast_valueKind_o, "Character", db_typedef(db_constant_o));
    if (!Fast_valueKind_Character_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::valueKind::Character'.");
        goto error;
    }

    /* Define ::hyve::Fast::valueKind::Character */
    if (!db_checkState(Fast_valueKind_Character_o, DB_DEFINED)) {
        (*Fast_valueKind_Character_o) = 1;
        if (db_define(Fast_valueKind_Character_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::valueKind::Character'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::valueKind::Enumerated */
    Fast_valueKind_Enumerated_o = db_declare(Fast_valueKind_o, "Enumerated", db_typedef(db_constant_o));
    if (!Fast_valueKind_Enumerated_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::valueKind::Enumerated'.");
        goto error;
    }

    /* Define ::hyve::Fast::valueKind::Enumerated */
    if (!db_checkState(Fast_valueKind_Enumerated_o, DB_DEFINED)) {
        (*Fast_valueKind_Enumerated_o) = 6;
        if (db_define(Fast_valueKind_Enumerated_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::valueKind::Enumerated'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::valueKind::FloatingPoint */
    Fast_valueKind_FloatingPoint_o = db_declare(Fast_valueKind_o, "FloatingPoint", db_typedef(db_constant_o));
    if (!Fast_valueKind_FloatingPoint_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::valueKind::FloatingPoint'.");
        goto error;
    }

    /* Define ::hyve::Fast::valueKind::FloatingPoint */
    if (!db_checkState(Fast_valueKind_FloatingPoint_o, DB_DEFINED)) {
        (*Fast_valueKind_FloatingPoint_o) = 4;
        if (db_define(Fast_valueKind_FloatingPoint_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::valueKind::FloatingPoint'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::valueKind::Integer */
    Fast_valueKind_Integer_o = db_declare(Fast_valueKind_o, "Integer", db_typedef(db_constant_o));
    if (!Fast_valueKind_Integer_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::valueKind::Integer'.");
        goto error;
    }

    /* Define ::hyve::Fast::valueKind::Integer */
    if (!db_checkState(Fast_valueKind_Integer_o, DB_DEFINED)) {
        (*Fast_valueKind_Integer_o) = 2;
        if (db_define(Fast_valueKind_Integer_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::valueKind::Integer'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::valueKind::Null */
    Fast_valueKind_Null_o = db_declare(Fast_valueKind_o, "Null", db_typedef(db_constant_o));
    if (!Fast_valueKind_Null_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::valueKind::Null'.");
        goto error;
    }

    /* Define ::hyve::Fast::valueKind::Null */
    if (!db_checkState(Fast_valueKind_Null_o, DB_DEFINED)) {
        (*Fast_valueKind_Null_o) = 8;
        if (db_define(Fast_valueKind_Null_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::valueKind::Null'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::valueKind::Reference */
    Fast_valueKind_Reference_o = db_declare(Fast_valueKind_o, "Reference", db_typedef(db_constant_o));
    if (!Fast_valueKind_Reference_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::valueKind::Reference'.");
        goto error;
    }

    /* Define ::hyve::Fast::valueKind::Reference */
    if (!db_checkState(Fast_valueKind_Reference_o, DB_DEFINED)) {
        (*Fast_valueKind_Reference_o) = 7;
        if (db_define(Fast_valueKind_Reference_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::valueKind::Reference'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::valueKind::SignedInteger */
    Fast_valueKind_SignedInteger_o = db_declare(Fast_valueKind_o, "SignedInteger", db_typedef(db_constant_o));
    if (!Fast_valueKind_SignedInteger_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::valueKind::SignedInteger'.");
        goto error;
    }

    /* Define ::hyve::Fast::valueKind::SignedInteger */
    if (!db_checkState(Fast_valueKind_SignedInteger_o, DB_DEFINED)) {
        (*Fast_valueKind_SignedInteger_o) = 3;
        if (db_define(Fast_valueKind_SignedInteger_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::valueKind::SignedInteger'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::valueKind::String */
    Fast_valueKind_String_o = db_declare(Fast_valueKind_o, "String", db_typedef(db_constant_o));
    if (!Fast_valueKind_String_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::valueKind::String'.");
        goto error;
    }

    /* Define ::hyve::Fast::valueKind::String */
    if (!db_checkState(Fast_valueKind_String_o, DB_DEFINED)) {
        (*Fast_valueKind_String_o) = 5;
        if (db_define(Fast_valueKind_String_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::valueKind::String'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::valueKind */
    if (!db_checkState(Fast_valueKind_o, DB_DEFINED)) {
        if (db_define(Fast_valueKind_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::valueKind'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::Literal::kind */
    if (!db_checkState(Fast_Literal_kind_o, DB_DEFINED)) {
        Fast_Literal_kind_o->type = db_resolve_ext(Fast_Literal_kind_o, NULL, "::hyve::Fast::valueKind", FALSE, "element ::hyve::Fast::Literal::kind.type");
        Fast_Literal_kind_o->modifiers = 0x0;
        Fast_Literal_kind_o->state = 0x6;
        Fast_Literal_kind_o->weak = FALSE;
        Fast_Literal_kind_o->id = 0;
        if (db_define(Fast_Literal_kind_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Literal::kind'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::valueKindFromType(lang::type type) */
    Fast_valueKindFromType_o = db_declare(Fast_o, "valueKindFromType(lang::type type)", db_typedef(db_function_o));
    if (!Fast_valueKindFromType_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::valueKindFromType(lang::type type)'.");
        goto error;
    }

    /* Define ::hyve::Fast::valueKindFromType(lang::type type) */
    if (!db_checkState(Fast_valueKindFromType_o, DB_DEFINED)) {
        Fast_valueKindFromType_o->returnType = db_resolve_ext(Fast_valueKindFromType_o, NULL, "::hyve::Fast::valueKind", FALSE, "element ::hyve::Fast::valueKindFromType(lang::type type).returnType");
        Fast_valueKindFromType_o->returnsReference = FALSE;
        
        /* Bind Fast_valueKindFromType_o with C-function */
        db_function(Fast_valueKindFromType_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_valueKindFromType(void *args, void *result);
        db_function(Fast_valueKindFromType_o)->impl = (db_word)__Fast_valueKindFromType;
        if (db_define(Fast_valueKindFromType_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::valueKindFromType(lang::type type)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Variable */
    Fast_Variable_o = db_declare(Fast_o, "Variable", db_typedef(db_class_o));
    if (!Fast_Variable_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Variable'.");
        goto error;
    }

    /* Declare ::hyve::Fast::Variable::kind */
    Fast_Variable_kind_o = db_declare(Fast_Variable_o, "kind", db_typedef(db_member_o));
    if (!Fast_Variable_kind_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Variable::kind'.");
        goto error;
    }

    /* Declare ::hyve::Fast::variableKind */
    Fast_variableKind_o = db_declare(Fast_o, "variableKind", db_typedef(db_enum_o));
    if (!Fast_variableKind_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::variableKind'.");
        goto error;
    }

    /* Declare ::hyve::Fast::variableKind::Local */
    Fast_variableKind_Local_o = db_declare(Fast_variableKind_o, "Local", db_typedef(db_constant_o));
    if (!Fast_variableKind_Local_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::variableKind::Local'.");
        goto error;
    }

    /* Define ::hyve::Fast::variableKind::Local */
    if (!db_checkState(Fast_variableKind_Local_o, DB_DEFINED)) {
        (*Fast_variableKind_Local_o) = 0;
        if (db_define(Fast_variableKind_Local_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::variableKind::Local'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::variableKind::Object */
    Fast_variableKind_Object_o = db_declare(Fast_variableKind_o, "Object", db_typedef(db_constant_o));
    if (!Fast_variableKind_Object_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::variableKind::Object'.");
        goto error;
    }

    /* Define ::hyve::Fast::variableKind::Object */
    if (!db_checkState(Fast_variableKind_Object_o, DB_DEFINED)) {
        (*Fast_variableKind_Object_o) = 2;
        if (db_define(Fast_variableKind_Object_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::variableKind::Object'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::variableKind::Template */
    Fast_variableKind_Template_o = db_declare(Fast_variableKind_o, "Template", db_typedef(db_constant_o));
    if (!Fast_variableKind_Template_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::variableKind::Template'.");
        goto error;
    }

    /* Define ::hyve::Fast::variableKind::Template */
    if (!db_checkState(Fast_variableKind_Template_o, DB_DEFINED)) {
        (*Fast_variableKind_Template_o) = 1;
        if (db_define(Fast_variableKind_Template_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::variableKind::Template'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::variableKind */
    if (!db_checkState(Fast_variableKind_o, DB_DEFINED)) {
        if (db_define(Fast_variableKind_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::variableKind'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::Variable::kind */
    if (!db_checkState(Fast_Variable_kind_o, DB_DEFINED)) {
        Fast_Variable_kind_o->type = db_resolve_ext(Fast_Variable_kind_o, NULL, "::hyve::Fast::variableKind", FALSE, "element ::hyve::Fast::Variable::kind.type");
        Fast_Variable_kind_o->modifiers = 0x0;
        Fast_Variable_kind_o->state = 0x6;
        Fast_Variable_kind_o->weak = FALSE;
        Fast_Variable_kind_o->id = 0;
        if (db_define(Fast_Variable_kind_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Variable::kind'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Wait */
    Fast_Wait_o = db_declare(Fast_o, "Wait", db_typedef(db_class_o));
    if (!Fast_Wait_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Wait'.");
        goto error;
    }

    /* Declare ::hyve::Fast::Wait::exprList */
    Fast_Wait_exprList_o = db_declare(Fast_Wait_o, "exprList", db_typedef(db_member_o));
    if (!Fast_Wait_exprList_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Wait::exprList'.");
        goto error;
    }

    /* Define ::hyve::Fast::Wait::exprList */
    if (!db_checkState(Fast_Wait_exprList_o, DB_DEFINED)) {
        Fast_Wait_exprList_o->type = db_resolve_ext(Fast_Wait_exprList_o, NULL, "::hyve::lang::list{::hyve::Fast::Expression,0}", FALSE, "element ::hyve::Fast::Wait::exprList.type");
        Fast_Wait_exprList_o->modifiers = 0x0;
        Fast_Wait_exprList_o->state = 0x6;
        Fast_Wait_exprList_o->weak = FALSE;
        Fast_Wait_exprList_o->id = 0;
        if (db_define(Fast_Wait_exprList_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Wait::exprList'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Wait::timeout */
    Fast_Wait_timeout_o = db_declare(Fast_Wait_o, "timeout", db_typedef(db_member_o));
    if (!Fast_Wait_timeout_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Wait::timeout'.");
        goto error;
    }

    /* Declare ::hyve::Fast::While */
    Fast_While_o = db_declare(Fast_o, "While", db_typedef(db_class_o));
    if (!Fast_While_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::While'.");
        goto error;
    }

    /* Declare ::hyve::Fast::While::condition */
    Fast_While_condition_o = db_declare(Fast_While_o, "condition", db_typedef(db_member_o));
    if (!Fast_While_condition_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::While::condition'.");
        goto error;
    }

    /* Declare ::hyve::Fast::While::isUntil */
    Fast_While_isUntil_o = db_declare(Fast_While_o, "isUntil", db_typedef(db_member_o));
    if (!Fast_While_isUntil_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::While::isUntil'.");
        goto error;
    }

    /* Define ::hyve::Fast::While::isUntil */
    if (!db_checkState(Fast_While_isUntil_o, DB_DEFINED)) {
        Fast_While_isUntil_o->type = db_resolve_ext(Fast_While_isUntil_o, NULL, "::hyve::lang::bool", FALSE, "element ::hyve::Fast::While::isUntil.type");
        Fast_While_isUntil_o->modifiers = 0x0;
        Fast_While_isUntil_o->state = 0x6;
        Fast_While_isUntil_o->weak = FALSE;
        Fast_While_isUntil_o->id = 2;
        if (db_define(Fast_While_isUntil_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::While::isUntil'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::While::trueBranch */
    Fast_While_trueBranch_o = db_declare(Fast_While_o, "trueBranch", db_typedef(db_member_o));
    if (!Fast_While_trueBranch_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::While::trueBranch'.");
        goto error;
    }

    /* Declare ::hyve::Fast::Node::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
    Fast_Node_toIc_o = db_declare(Fast_Node_o, "toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)", db_typedef(db_virtual_o));
    if (!Fast_Node_toIc_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Node::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Node::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
    if (!db_checkState(Fast_Node_toIc_o, DB_DEFINED)) {
        db_function(Fast_Node_toIc_o)->returnType = db_resolve_ext(Fast_Node_toIc_o, NULL, "::hyve::lang::alias{\"db_ic\"}", FALSE, "element ::hyve::Fast::Node::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored).returnType");
        db_function(Fast_Node_toIc_o)->returnsReference = FALSE;
        db_method(Fast_Node_toIc_o)->virtual = TRUE;
        
        /* Bind Fast_Node_toIc_o with C-function */
        db_function(Fast_Node_toIc_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Node_toIc_v(void *args, void *result);
        db_function(Fast_Node_toIc_o)->impl = (db_word)__Fast_Node_toIc_v;
        if (db_define(Fast_Node_toIc_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Node::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::Parser::complexType */
    if (!db_checkState(Fast_Parser_complexType_o, DB_DEFINED)) {
        Fast_Parser_complexType_o->type = db_resolve_ext(Fast_Parser_complexType_o, NULL, "::hyve::lang::array{::hyve::lang::type,64,::hyve::lang::type}", FALSE, "element ::hyve::Fast::Parser::complexType.type");
        Fast_Parser_complexType_o->modifiers = 0x3;
        Fast_Parser_complexType_o->state = 0x6;
        Fast_Parser_complexType_o->weak = FALSE;
        Fast_Parser_complexType_o->id = 35;
        if (db_define(Fast_Parser_complexType_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::complexType'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::Parser::heapCollected */
    if (!db_checkState(Fast_Parser_heapCollected_o, DB_DEFINED)) {
        Fast_Parser_heapCollected_o->type = db_resolve_ext(Fast_Parser_heapCollected_o, NULL, "::hyve::lang::list{::hyve::lang::word,0}", FALSE, "element ::hyve::Fast::Parser::heapCollected.type");
        Fast_Parser_heapCollected_o->modifiers = 0x3;
        Fast_Parser_heapCollected_o->state = 0x6;
        Fast_Parser_heapCollected_o->weak = FALSE;
        Fast_Parser_heapCollected_o->id = 15;
        if (db_define(Fast_Parser_heapCollected_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::heapCollected'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::StaticInitializerFrame::keyPtr */
    if (!db_checkState(Fast_StaticInitializerFrame_keyPtr_o, DB_DEFINED)) {
        Fast_StaticInitializerFrame_keyPtr_o->type = db_resolve_ext(Fast_StaticInitializerFrame_keyPtr_o, NULL, "::hyve::lang::array{::hyve::lang::word,64,::hyve::lang::word}", FALSE, "element ::hyve::Fast::StaticInitializerFrame::keyPtr.type");
        Fast_StaticInitializerFrame_keyPtr_o->modifiers = 0x0;
        Fast_StaticInitializerFrame_keyPtr_o->state = 0x6;
        Fast_StaticInitializerFrame_keyPtr_o->weak = FALSE;
        Fast_StaticInitializerFrame_keyPtr_o->id = 1;
        if (db_define(Fast_StaticInitializerFrame_keyPtr_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::StaticInitializerFrame::keyPtr'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::StaticInitializerFrame::ptr */
    if (!db_checkState(Fast_StaticInitializerFrame_ptr_o, DB_DEFINED)) {
        Fast_StaticInitializerFrame_ptr_o->type = db_resolve_ext(Fast_StaticInitializerFrame_ptr_o, NULL, "::hyve::lang::array{::hyve::lang::word,64,::hyve::lang::word}", FALSE, "element ::hyve::Fast::StaticInitializerFrame::ptr.type");
        Fast_StaticInitializerFrame_ptr_o->modifiers = 0x0;
        Fast_StaticInitializerFrame_ptr_o->state = 0x6;
        Fast_StaticInitializerFrame_ptr_o->weak = FALSE;
        Fast_StaticInitializerFrame_ptr_o->id = 0;
        if (db_define(Fast_StaticInitializerFrame_ptr_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::StaticInitializerFrame::ptr'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::StaticInitializerFrame */
    if (!db_checkState(Fast_StaticInitializerFrame_o, DB_DEFINED)) {
        db_type(Fast_StaticInitializerFrame_o)->defaultType = db_resolve_ext(Fast_StaticInitializerFrame_o, NULL, "::hyve::lang::member", FALSE, "element ::hyve::Fast::StaticInitializerFrame.defaultType");
        db_type(Fast_StaticInitializerFrame_o)->parentType = NULL;
        db_type(Fast_StaticInitializerFrame_o)->parentState = 0x0;
        db_interface(Fast_StaticInitializerFrame_o)->base = NULL;
        Fast_StaticInitializerFrame_o->baseAccess = 0x0;
        if (db_define(Fast_StaticInitializerFrame_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::StaticInitializerFrame'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::StaticInitializer::frames */
    if (!db_checkState(Fast_StaticInitializer_frames_o, DB_DEFINED)) {
        Fast_StaticInitializer_frames_o->type = db_resolve_ext(Fast_StaticInitializer_frames_o, NULL, "::hyve::lang::array{::hyve::Fast::StaticInitializerFrame,64,::hyve::Fast::StaticInitializerFrame}", FALSE, "element ::hyve::Fast::StaticInitializer::frames.type");
        Fast_StaticInitializer_frames_o->modifiers = 0x3;
        Fast_StaticInitializer_frames_o->state = 0x6;
        Fast_StaticInitializer_frames_o->weak = FALSE;
        Fast_StaticInitializer_frames_o->id = 0;
        if (db_define(Fast_StaticInitializer_frames_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::StaticInitializer::frames'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::Block::parent */
    if (!db_checkState(Fast_Block_parent_o, DB_DEFINED)) {
        Fast_Block_parent_o->type = db_resolve_ext(Fast_Block_parent_o, NULL, "::hyve::Fast::Block", FALSE, "element ::hyve::Fast::Block::parent.type");
        Fast_Block_parent_o->modifiers = 0x0;
        Fast_Block_parent_o->state = 0x6;
        Fast_Block_parent_o->weak = FALSE;
        Fast_Block_parent_o->id = 0;
        if (db_define(Fast_Block_parent_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Block::parent'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::Block::while */
    if (!db_checkState(Fast_Block_while_o, DB_DEFINED)) {
        Fast_Block_while_o->type = db_resolve_ext(Fast_Block_while_o, NULL, "::hyve::Fast::While", FALSE, "element ::hyve::Fast::Block::while.type");
        Fast_Block_while_o->modifiers = 0x4;
        Fast_Block_while_o->state = 0x6;
        Fast_Block_while_o->weak = FALSE;
        Fast_Block_while_o->id = 4;
        if (db_define(Fast_Block_while_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Block::while'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::If::falseBranch */
    if (!db_checkState(Fast_If_falseBranch_o, DB_DEFINED)) {
        Fast_If_falseBranch_o->type = db_resolve_ext(Fast_If_falseBranch_o, NULL, "::hyve::Fast::If", FALSE, "element ::hyve::Fast::If::falseBranch.type");
        Fast_If_falseBranch_o->modifiers = 0x0;
        Fast_If_falseBranch_o->state = 0x6;
        Fast_If_falseBranch_o->weak = FALSE;
        Fast_If_falseBranch_o->id = 2;
        if (db_define(Fast_If_falseBranch_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::If::falseBranch'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::construct(Parser object) */
    Fast_Parser_construct_o = db_declare(Fast_Parser_o, "construct(Parser object)", db_typedef(db_callback_o));
    if (!Fast_Parser_construct_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::construct(Parser object)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::construct(Parser object) */
    if (!db_checkState(Fast_Parser_construct_o, DB_DEFINED)) {
        db_function(Fast_Parser_construct_o)->returnType = db_resolve_ext(Fast_Parser_construct_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::Parser::construct(Parser object).returnType");
        db_function(Fast_Parser_construct_o)->returnsReference = FALSE;
        Fast_Parser_construct_o->delegate = db_resolve_ext(Fast_Parser_construct_o, NULL, "::hyve::lang::class::construct(lang::object object)", FALSE, "element ::hyve::Fast::Parser::construct(Parser object).delegate");
        
        /* Bind Fast_Parser_construct_o with C-function */
        db_function(Fast_Parser_construct_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Parser_construct(void *args, void *result);
        db_function(Fast_Parser_construct_o)->impl = (db_word)__Fast_Parser_construct;
        if (db_define(Fast_Parser_construct_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::construct(Parser object)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::destruct(Parser object) */
    Fast_Parser_destruct_o = db_declare(Fast_Parser_o, "destruct(Parser object)", db_typedef(db_callback_o));
    if (!Fast_Parser_destruct_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::destruct(Parser object)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::destruct(Parser object) */
    if (!db_checkState(Fast_Parser_destruct_o, DB_DEFINED)) {
        db_function(Fast_Parser_destruct_o)->returnType = NULL;
        db_function(Fast_Parser_destruct_o)->returnsReference = FALSE;
        Fast_Parser_destruct_o->delegate = db_resolve_ext(Fast_Parser_destruct_o, NULL, "::hyve::lang::class::destruct(lang::object object)", FALSE, "element ::hyve::Fast::Parser::destruct(Parser object).delegate");
        
        /* Bind Fast_Parser_destruct_o with C-function */
        db_function(Fast_Parser_destruct_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Parser_destruct(void *args, void *result);
        db_function(Fast_Parser_destruct_o)->impl = (db_word)__Fast_Parser_destruct;
        if (db_define(Fast_Parser_destruct_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::destruct(Parser object)'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::Expression::type */
    if (!db_checkState(Fast_Expression_type_o, DB_DEFINED)) {
        Fast_Expression_type_o->type = db_resolve_ext(Fast_Expression_type_o, NULL, "::hyve::Fast::Variable", FALSE, "element ::hyve::Fast::Expression::type.type");
        Fast_Expression_type_o->modifiers = 0x4;
        Fast_Expression_type_o->state = 0x6;
        Fast_Expression_type_o->weak = FALSE;
        Fast_Expression_type_o->id = 0;
        if (db_define(Fast_Expression_type_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Expression::type'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Node::init(Node object) */
    Fast_Node_init_o = db_declare(Fast_Node_o, "init(Node object)", db_typedef(db_callback_o));
    if (!Fast_Node_init_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Node::init(Node object)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Node::init(Node object) */
    if (!db_checkState(Fast_Node_init_o, DB_DEFINED)) {
        db_function(Fast_Node_init_o)->returnType = db_resolve_ext(Fast_Node_init_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::Node::init(Node object).returnType");
        db_function(Fast_Node_init_o)->returnsReference = FALSE;
        Fast_Node_init_o->delegate = db_resolve_ext(Fast_Node_init_o, NULL, "::hyve::lang::type::init(lang::object object)", FALSE, "element ::hyve::Fast::Node::init(Node object).delegate");
        
        /* Bind Fast_Node_init_o with C-function */
        db_function(Fast_Node_init_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Node_init(void *args, void *result);
        db_function(Fast_Node_init_o)->impl = (db_word)__Fast_Node_init;
        if (db_define(Fast_Node_init_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Node::init(Node object)'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::Node */
    if (!db_checkState(Fast_Node_o, DB_DEFINED)) {
        db_type(Fast_Node_o)->defaultType = db_resolve_ext(Fast_Node_o, NULL, "::hyve::lang::member", FALSE, "element ::hyve::Fast::Node.defaultType");
        db_type(Fast_Node_o)->parentType = NULL;
        db_type(Fast_Node_o)->parentState = 0x0;
        db_interface(Fast_Node_o)->base = NULL;
        db_struct(Fast_Node_o)->baseAccess = 0x0;
        Fast_Node_o->implements.length = 0;
        Fast_Node_o->implements.buffer = NULL;
        if (db_define(Fast_Node_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Node'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Block::addStatement(Fast::Node statement) */
    Fast_Block_addStatement_o = db_declare(Fast_Block_o, "addStatement(Fast::Node statement)", db_typedef(db_method_o));
    if (!Fast_Block_addStatement_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Block::addStatement(Fast::Node statement)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Block::addStatement(Fast::Node statement) */
    if (!db_checkState(Fast_Block_addStatement_o, DB_DEFINED)) {
        db_function(Fast_Block_addStatement_o)->returnType = NULL;
        db_function(Fast_Block_addStatement_o)->returnsReference = FALSE;
        Fast_Block_addStatement_o->virtual = FALSE;
        
        /* Bind Fast_Block_addStatement_o with C-function */
        db_function(Fast_Block_addStatement_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Block_addStatement(void *args, void *result);
        db_function(Fast_Block_addStatement_o)->impl = (db_word)__Fast_Block_addStatement;
        if (db_define(Fast_Block_addStatement_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Block::addStatement(Fast::Node statement)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Block::declareReturnVariable(lang::function function) */
    Fast_Block_declareReturnVariable_o = db_declare(Fast_Block_o, "declareReturnVariable(lang::function function)", db_typedef(db_method_o));
    if (!Fast_Block_declareReturnVariable_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Block::declareReturnVariable(lang::function function)'.");
        goto error;
    }

    /* Declare ::hyve::Fast::Block::lookup(lang::string id) */
    Fast_Block_lookup_o = db_declare(Fast_Block_o, "lookup(lang::string id)", db_typedef(db_method_o));
    if (!Fast_Block_lookup_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Block::lookup(lang::string id)'.");
        goto error;
    }

    /* Declare ::hyve::Fast::Block::lookupLocal(lang::string id) */
    Fast_Block_lookupLocal_o = db_declare(Fast_Block_o, "lookupLocal(lang::string id)", db_typedef(db_method_o));
    if (!Fast_Block_lookupLocal_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Block::lookupLocal(lang::string id)'.");
        goto error;
    }

    /* Declare ::hyve::Fast::Block::resolve(lang::string id) */
    Fast_Block_resolve_o = db_declare(Fast_Block_o, "resolve(lang::string id)", db_typedef(db_method_o));
    if (!Fast_Block_resolve_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Block::resolve(lang::string id)'.");
        goto error;
    }

    /* Declare ::hyve::Fast::Block::setFunction(lang::function function */
    Fast_Block_setFunction_o = db_declare(Fast_Block_o, "setFunction(lang::function function", db_typedef(db_method_o));
    if (!Fast_Block_setFunction_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Block::setFunction(lang::function function'.");
        goto error;
    }

    /* Define ::hyve::Fast::Block::setFunction(lang::function function */
    if (!db_checkState(Fast_Block_setFunction_o, DB_DEFINED)) {
        db_function(Fast_Block_setFunction_o)->returnType = NULL;
        db_function(Fast_Block_setFunction_o)->returnsReference = FALSE;
        Fast_Block_setFunction_o->virtual = FALSE;
        
        /* Bind Fast_Block_setFunction_o with C-function */
        db_function(Fast_Block_setFunction_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Block_setFunction(void *args, void *result);
        db_function(Fast_Block_setFunction_o)->impl = (db_word)__Fast_Block_setFunction;
        if (db_define(Fast_Block_setFunction_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Block::setFunction(lang::function function'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Block::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
    Fast_Block_toIc_o = db_declare(Fast_Block_o, "toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)", db_typedef(db_virtual_o));
    if (!Fast_Block_toIc_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Block::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Block::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
    if (!db_checkState(Fast_Block_toIc_o, DB_DEFINED)) {
        db_function(Fast_Block_toIc_o)->returnType = db_resolve_ext(Fast_Block_toIc_o, NULL, "::hyve::lang::alias{\"db_ic\"}", FALSE, "element ::hyve::Fast::Block::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored).returnType");
        db_function(Fast_Block_toIc_o)->returnsReference = FALSE;
        db_method(Fast_Block_toIc_o)->virtual = TRUE;
        
        /* Bind Fast_Block_toIc_o with C-function */
        db_function(Fast_Block_toIc_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Block_toIc_v(void *args, void *result);
        db_function(Fast_Block_toIc_o)->impl = (db_word)__Fast_Block_toIc_v;
        if (db_define(Fast_Block_toIc_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Block::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Block::toIcBody(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
    Fast_Block_toIcBody_o = db_declare(Fast_Block_o, "toIcBody(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)", db_typedef(db_virtual_o));
    if (!Fast_Block_toIcBody_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Block::toIcBody(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Block::toIcBody(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
    if (!db_checkState(Fast_Block_toIcBody_o, DB_DEFINED)) {
        db_function(Fast_Block_toIcBody_o)->returnType = db_resolve_ext(Fast_Block_toIcBody_o, NULL, "::hyve::lang::alias{\"db_ic\"}", FALSE, "element ::hyve::Fast::Block::toIcBody(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored).returnType");
        db_function(Fast_Block_toIcBody_o)->returnsReference = FALSE;
        db_method(Fast_Block_toIcBody_o)->virtual = TRUE;
        
        /* Bind Fast_Block_toIcBody_o with C-function */
        db_function(Fast_Block_toIcBody_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Block_toIcBody_v(void *args, void *result);
        db_function(Fast_Block_toIcBody_o)->impl = (db_word)__Fast_Block_toIcBody_v;
        if (db_define(Fast_Block_toIcBody_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Block::toIcBody(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Define::construct(Fast::Define object) */
    Fast_Define_construct_o = db_declare(Fast_Define_o, "construct(Fast::Define object)", db_typedef(db_callback_o));
    if (!Fast_Define_construct_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Define::construct(Fast::Define object)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Define::construct(Fast::Define object) */
    if (!db_checkState(Fast_Define_construct_o, DB_DEFINED)) {
        db_function(Fast_Define_construct_o)->returnType = db_resolve_ext(Fast_Define_construct_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::Define::construct(Fast::Define object).returnType");
        db_function(Fast_Define_construct_o)->returnsReference = FALSE;
        Fast_Define_construct_o->delegate = db_resolve_ext(Fast_Define_construct_o, NULL, "::hyve::lang::class::construct(lang::object object)", FALSE, "element ::hyve::Fast::Define::construct(Fast::Define object).delegate");
        
        /* Bind Fast_Define_construct_o with C-function */
        db_function(Fast_Define_construct_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Define_construct(void *args, void *result);
        db_function(Fast_Define_construct_o)->impl = (db_word)__Fast_Define_construct;
        if (db_define(Fast_Define_construct_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Define::construct(Fast::Define object)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Define::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
    Fast_Define_toIc_o = db_declare(Fast_Define_o, "toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)", db_typedef(db_virtual_o));
    if (!Fast_Define_toIc_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Define::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Define::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
    if (!db_checkState(Fast_Define_toIc_o, DB_DEFINED)) {
        db_function(Fast_Define_toIc_o)->returnType = db_resolve_ext(Fast_Define_toIc_o, NULL, "::hyve::lang::alias{\"db_ic\"}", FALSE, "element ::hyve::Fast::Define::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored).returnType");
        db_function(Fast_Define_toIc_o)->returnsReference = FALSE;
        db_method(Fast_Define_toIc_o)->virtual = TRUE;
        
        /* Bind Fast_Define_toIc_o with C-function */
        db_function(Fast_Define_toIc_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Define_toIc_v(void *args, void *result);
        db_function(Fast_Define_toIc_o)->impl = (db_word)__Fast_Define_toIc_v;
        if (db_define(Fast_Define_toIc_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Define::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Expression::cast(lang::type type) */
    Fast_Expression_cast_o = db_declare(Fast_Expression_o, "cast(lang::type type)", db_typedef(db_method_o));
    if (!Fast_Expression_cast_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Expression::cast(lang::type type)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Expression::cast(lang::type type) */
    if (!db_checkState(Fast_Expression_cast_o, DB_DEFINED)) {
        db_function(Fast_Expression_cast_o)->returnType = db_resolve_ext(Fast_Expression_cast_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::Expression::cast(lang::type type).returnType");
        db_function(Fast_Expression_cast_o)->returnsReference = FALSE;
        Fast_Expression_cast_o->virtual = FALSE;
        
        /* Bind Fast_Expression_cast_o with C-function */
        db_function(Fast_Expression_cast_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Expression_cast(void *args, void *result);
        db_function(Fast_Expression_cast_o)->impl = (db_word)__Fast_Expression_cast;
        if (db_define(Fast_Expression_cast_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Expression::cast(lang::type type)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Expression::fold() */
    Fast_Expression_fold_o = db_declare(Fast_Expression_o, "fold()", db_typedef(db_virtual_o));
    if (!Fast_Expression_fold_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Expression::fold()'.");
        goto error;
    }

    /* Define ::hyve::Fast::Expression::fold() */
    if (!db_checkState(Fast_Expression_fold_o, DB_DEFINED)) {
        db_function(Fast_Expression_fold_o)->returnType = db_resolve_ext(Fast_Expression_fold_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::Expression::fold().returnType");
        db_function(Fast_Expression_fold_o)->returnsReference = FALSE;
        db_method(Fast_Expression_fold_o)->virtual = TRUE;
        
        /* Bind Fast_Expression_fold_o with C-function */
        db_function(Fast_Expression_fold_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Expression_fold_v(void *args, void *result);
        db_function(Fast_Expression_fold_o)->impl = (db_word)__Fast_Expression_fold_v;
        if (db_define(Fast_Expression_fold_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Expression::fold()'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Expression::getType() */
    Fast_Expression_getType_o = db_declare(Fast_Expression_o, "getType()", db_typedef(db_method_o));
    if (!Fast_Expression_getType_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Expression::getType()'.");
        goto error;
    }

    /* Define ::hyve::Fast::Expression::getType() */
    if (!db_checkState(Fast_Expression_getType_o, DB_DEFINED)) {
        db_function(Fast_Expression_getType_o)->returnType = db_resolve_ext(Fast_Expression_getType_o, NULL, "::hyve::lang::type", FALSE, "element ::hyve::Fast::Expression::getType().returnType");
        db_function(Fast_Expression_getType_o)->returnsReference = FALSE;
        Fast_Expression_getType_o->virtual = FALSE;
        
        /* Bind Fast_Expression_getType_o with C-function */
        db_function(Fast_Expression_getType_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Expression_getType(void *args, void *result);
        db_function(Fast_Expression_getType_o)->impl = (db_word)__Fast_Expression_getType;
        if (db_define(Fast_Expression_getType_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Expression::getType()'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Expression::getType_expr(Expression target) */
    Fast_Expression_getType_expr_o = db_declare(Fast_Expression_o, "getType_expr(Expression target)", db_typedef(db_method_o));
    if (!Fast_Expression_getType_expr_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Expression::getType_expr(Expression target)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Expression::getType_expr(Expression target) */
    if (!db_checkState(Fast_Expression_getType_expr_o, DB_DEFINED)) {
        db_function(Fast_Expression_getType_expr_o)->returnType = db_resolve_ext(Fast_Expression_getType_expr_o, NULL, "::hyve::lang::type", FALSE, "element ::hyve::Fast::Expression::getType_expr(Expression target).returnType");
        db_function(Fast_Expression_getType_expr_o)->returnsReference = FALSE;
        Fast_Expression_getType_expr_o->virtual = FALSE;
        
        /* Bind Fast_Expression_getType_expr_o with C-function */
        db_function(Fast_Expression_getType_expr_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Expression_getType_expr(void *args, void *result);
        db_function(Fast_Expression_getType_expr_o)->impl = (db_word)__Fast_Expression_getType_expr;
        if (db_define(Fast_Expression_getType_expr_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Expression::getType_expr(Expression target)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Expression::getType_type(lang::type target) */
    Fast_Expression_getType_type_o = db_declare(Fast_Expression_o, "getType_type(lang::type target)", db_typedef(db_method_o));
    if (!Fast_Expression_getType_type_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Expression::getType_type(lang::type target)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Expression::getType_type(lang::type target) */
    if (!db_checkState(Fast_Expression_getType_type_o, DB_DEFINED)) {
        db_function(Fast_Expression_getType_type_o)->returnType = db_resolve_ext(Fast_Expression_getType_type_o, NULL, "::hyve::lang::type", FALSE, "element ::hyve::Fast::Expression::getType_type(lang::type target).returnType");
        db_function(Fast_Expression_getType_type_o)->returnsReference = FALSE;
        Fast_Expression_getType_type_o->virtual = FALSE;
        
        /* Bind Fast_Expression_getType_type_o with C-function */
        db_function(Fast_Expression_getType_type_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Expression_getType_type(void *args, void *result);
        db_function(Fast_Expression_getType_type_o)->impl = (db_word)__Fast_Expression_getType_type;
        if (db_define(Fast_Expression_getType_type_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Expression::getType_type(lang::type target)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Expression::getValue() */
    Fast_Expression_getValue_o = db_declare(Fast_Expression_o, "getValue()", db_typedef(db_virtual_o));
    if (!Fast_Expression_getValue_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Expression::getValue()'.");
        goto error;
    }

    /* Define ::hyve::Fast::Expression::getValue() */
    if (!db_checkState(Fast_Expression_getValue_o, DB_DEFINED)) {
        db_function(Fast_Expression_getValue_o)->returnType = db_resolve_ext(Fast_Expression_getValue_o, NULL, "::hyve::lang::word", FALSE, "element ::hyve::Fast::Expression::getValue().returnType");
        db_function(Fast_Expression_getValue_o)->returnsReference = FALSE;
        db_method(Fast_Expression_getValue_o)->virtual = TRUE;
        
        /* Bind Fast_Expression_getValue_o with C-function */
        db_function(Fast_Expression_getValue_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Expression_getValue_v(void *args, void *result);
        db_function(Fast_Expression_getValue_o)->impl = (db_word)__Fast_Expression_getValue_v;
        if (db_define(Fast_Expression_getValue_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Expression::getValue()'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Expression::hasSideEffects() */
    Fast_Expression_hasSideEffects_o = db_declare(Fast_Expression_o, "hasSideEffects()", db_typedef(db_virtual_o));
    if (!Fast_Expression_hasSideEffects_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Expression::hasSideEffects()'.");
        goto error;
    }

    /* Define ::hyve::Fast::Expression::hasSideEffects() */
    if (!db_checkState(Fast_Expression_hasSideEffects_o, DB_DEFINED)) {
        db_function(Fast_Expression_hasSideEffects_o)->returnType = db_resolve_ext(Fast_Expression_hasSideEffects_o, NULL, "::hyve::lang::bool", FALSE, "element ::hyve::Fast::Expression::hasSideEffects().returnType");
        db_function(Fast_Expression_hasSideEffects_o)->returnsReference = FALSE;
        db_method(Fast_Expression_hasSideEffects_o)->virtual = TRUE;
        
        /* Bind Fast_Expression_hasSideEffects_o with C-function */
        db_function(Fast_Expression_hasSideEffects_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Expression_hasSideEffects_v(void *args, void *result);
        db_function(Fast_Expression_hasSideEffects_o)->impl = (db_word)__Fast_Expression_hasSideEffects_v;
        if (db_define(Fast_Expression_hasSideEffects_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Expression::hasSideEffects()'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Expression::init(Expression object) */
    Fast_Expression_init_o = db_declare(Fast_Expression_o, "init(Expression object)", db_typedef(db_callback_o));
    if (!Fast_Expression_init_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Expression::init(Expression object)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Expression::init(Expression object) */
    if (!db_checkState(Fast_Expression_init_o, DB_DEFINED)) {
        db_function(Fast_Expression_init_o)->returnType = db_resolve_ext(Fast_Expression_init_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::Expression::init(Expression object).returnType");
        db_function(Fast_Expression_init_o)->returnsReference = FALSE;
        Fast_Expression_init_o->delegate = db_resolve_ext(Fast_Expression_init_o, NULL, "::hyve::lang::type::init(lang::object object)", FALSE, "element ::hyve::Fast::Expression::init(Expression object).delegate");
        
        /* Bind Fast_Expression_init_o with C-function */
        db_function(Fast_Expression_init_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Expression_init(void *args, void *result);
        db_function(Fast_Expression_init_o)->impl = (db_word)__Fast_Expression_init;
        if (db_define(Fast_Expression_init_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Expression::init(Expression object)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Expression::serialize(lang::type dstType,lang::word dst) */
    Fast_Expression_serialize_o = db_declare(Fast_Expression_o, "serialize(lang::type dstType,lang::word dst)", db_typedef(db_virtual_o));
    if (!Fast_Expression_serialize_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Expression::serialize(lang::type dstType,lang::word dst)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Expression::serialize(lang::type dstType,lang::word dst) */
    if (!db_checkState(Fast_Expression_serialize_o, DB_DEFINED)) {
        db_function(Fast_Expression_serialize_o)->returnType = db_resolve_ext(Fast_Expression_serialize_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::Expression::serialize(lang::type dstType,lang::word dst).returnType");
        db_function(Fast_Expression_serialize_o)->returnsReference = FALSE;
        db_method(Fast_Expression_serialize_o)->virtual = TRUE;
        
        /* Bind Fast_Expression_serialize_o with C-function */
        db_function(Fast_Expression_serialize_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Expression_serialize_v(void *args, void *result);
        db_function(Fast_Expression_serialize_o)->impl = (db_word)__Fast_Expression_serialize_v;
        if (db_define(Fast_Expression_serialize_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Expression::serialize(lang::type dstType,lang::word dst)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Expression::toList() */
    Fast_Expression_toList_o = db_declare(Fast_Expression_o, "toList()", db_typedef(db_virtual_o));
    if (!Fast_Expression_toList_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Expression::toList()'.");
        goto error;
    }

    /* Define ::hyve::Fast::Expression::toList() */
    if (!db_checkState(Fast_Expression_toList_o, DB_DEFINED)) {
        db_function(Fast_Expression_toList_o)->returnType = db_resolve_ext(Fast_Expression_toList_o, NULL, "::hyve::lang::list{::hyve::Fast::Expression,0}", FALSE, "element ::hyve::Fast::Expression::toList().returnType");
        db_function(Fast_Expression_toList_o)->returnsReference = FALSE;
        db_method(Fast_Expression_toList_o)->virtual = TRUE;
        
        /* Bind Fast_Expression_toList_o with C-function */
        db_function(Fast_Expression_toList_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Expression_toList_v(void *args, void *result);
        db_function(Fast_Expression_toList_o)->impl = (db_word)__Fast_Expression_toList_v;
        if (db_define(Fast_Expression_toList_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Expression::toList()'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::Expression */
    if (!db_checkState(Fast_Expression_o, DB_DEFINED)) {
        db_type(Fast_Expression_o)->defaultType = db_resolve_ext(Fast_Expression_o, NULL, "::hyve::lang::member", FALSE, "element ::hyve::Fast::Expression.defaultType");
        db_type(Fast_Expression_o)->parentType = NULL;
        db_type(Fast_Expression_o)->parentState = 0x0;
        db_interface(Fast_Expression_o)->base = db_resolve_ext(Fast_Expression_o, NULL, "::hyve::Fast::Node", FALSE, "element ::hyve::Fast::Expression.base");
        db_struct(Fast_Expression_o)->baseAccess = 0x0;
        Fast_Expression_o->implements.length = 0;
        Fast_Expression_o->implements.buffer = NULL;
        if (db_define(Fast_Expression_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Expression'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::BinaryExpr::construct(Fast::BinaryExpr object) */
    Fast_BinaryExpr_construct_o = db_declare(Fast_BinaryExpr_o, "construct(Fast::BinaryExpr object)", db_typedef(db_callback_o));
    if (!Fast_BinaryExpr_construct_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::BinaryExpr::construct(Fast::BinaryExpr object)'.");
        goto error;
    }

    /* Define ::hyve::Fast::BinaryExpr::construct(Fast::BinaryExpr object) */
    if (!db_checkState(Fast_BinaryExpr_construct_o, DB_DEFINED)) {
        db_function(Fast_BinaryExpr_construct_o)->returnType = db_resolve_ext(Fast_BinaryExpr_construct_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::BinaryExpr::construct(Fast::BinaryExpr object).returnType");
        db_function(Fast_BinaryExpr_construct_o)->returnsReference = FALSE;
        Fast_BinaryExpr_construct_o->delegate = db_resolve_ext(Fast_BinaryExpr_construct_o, NULL, "::hyve::lang::class::construct(lang::object object)", FALSE, "element ::hyve::Fast::BinaryExpr::construct(Fast::BinaryExpr object).delegate");
        
        /* Bind Fast_BinaryExpr_construct_o with C-function */
        db_function(Fast_BinaryExpr_construct_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_BinaryExpr_construct(void *args, void *result);
        db_function(Fast_BinaryExpr_construct_o)->impl = (db_word)__Fast_BinaryExpr_construct;
        if (db_define(Fast_BinaryExpr_construct_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::BinaryExpr::construct(Fast::BinaryExpr object)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::BinaryExpr::fold() */
    Fast_BinaryExpr_fold_o = db_declare(Fast_BinaryExpr_o, "fold()", db_typedef(db_method_o));
    if (!Fast_BinaryExpr_fold_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::BinaryExpr::fold()'.");
        goto error;
    }

    /* Define ::hyve::Fast::BinaryExpr::fold() */
    if (!db_checkState(Fast_BinaryExpr_fold_o, DB_DEFINED)) {
        db_function(Fast_BinaryExpr_fold_o)->returnType = db_resolve_ext(Fast_BinaryExpr_fold_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::BinaryExpr::fold().returnType");
        db_function(Fast_BinaryExpr_fold_o)->returnsReference = FALSE;
        Fast_BinaryExpr_fold_o->virtual = FALSE;
        
        /* Bind Fast_BinaryExpr_fold_o with C-function */
        db_function(Fast_BinaryExpr_fold_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_BinaryExpr_fold(void *args, void *result);
        db_function(Fast_BinaryExpr_fold_o)->impl = (db_word)__Fast_BinaryExpr_fold;
        if (db_define(Fast_BinaryExpr_fold_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::BinaryExpr::fold()'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::BinaryExpr::hasSideEffects() */
    Fast_BinaryExpr_hasSideEffects_o = db_declare(Fast_BinaryExpr_o, "hasSideEffects()", db_typedef(db_virtual_o));
    if (!Fast_BinaryExpr_hasSideEffects_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::BinaryExpr::hasSideEffects()'.");
        goto error;
    }

    /* Define ::hyve::Fast::BinaryExpr::hasSideEffects() */
    if (!db_checkState(Fast_BinaryExpr_hasSideEffects_o, DB_DEFINED)) {
        db_function(Fast_BinaryExpr_hasSideEffects_o)->returnType = db_resolve_ext(Fast_BinaryExpr_hasSideEffects_o, NULL, "::hyve::lang::bool", FALSE, "element ::hyve::Fast::BinaryExpr::hasSideEffects().returnType");
        db_function(Fast_BinaryExpr_hasSideEffects_o)->returnsReference = FALSE;
        db_method(Fast_BinaryExpr_hasSideEffects_o)->virtual = TRUE;
        
        /* Bind Fast_BinaryExpr_hasSideEffects_o with C-function */
        db_function(Fast_BinaryExpr_hasSideEffects_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_BinaryExpr_hasSideEffects_v(void *args, void *result);
        db_function(Fast_BinaryExpr_hasSideEffects_o)->impl = (db_word)__Fast_BinaryExpr_hasSideEffects_v;
        if (db_define(Fast_BinaryExpr_hasSideEffects_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::BinaryExpr::hasSideEffects()'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::BinaryExpr::lvalue */
    if (!db_checkState(Fast_BinaryExpr_lvalue_o, DB_DEFINED)) {
        Fast_BinaryExpr_lvalue_o->type = db_resolve_ext(Fast_BinaryExpr_lvalue_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::BinaryExpr::lvalue.type");
        Fast_BinaryExpr_lvalue_o->modifiers = 0x0;
        Fast_BinaryExpr_lvalue_o->state = 0x6;
        Fast_BinaryExpr_lvalue_o->weak = FALSE;
        Fast_BinaryExpr_lvalue_o->id = 0;
        if (db_define(Fast_BinaryExpr_lvalue_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::BinaryExpr::lvalue'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::BinaryExpr::rvalue */
    if (!db_checkState(Fast_BinaryExpr_rvalue_o, DB_DEFINED)) {
        Fast_BinaryExpr_rvalue_o->type = db_resolve_ext(Fast_BinaryExpr_rvalue_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::BinaryExpr::rvalue.type");
        Fast_BinaryExpr_rvalue_o->modifiers = 0x0;
        Fast_BinaryExpr_rvalue_o->state = 0x6;
        Fast_BinaryExpr_rvalue_o->weak = FALSE;
        Fast_BinaryExpr_rvalue_o->id = 1;
        if (db_define(Fast_BinaryExpr_rvalue_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::BinaryExpr::rvalue'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::BinaryExpr::setOperator(lang::operatorKind kind) */
    Fast_BinaryExpr_setOperator_o = db_declare(Fast_BinaryExpr_o, "setOperator(lang::operatorKind kind)", db_typedef(db_method_o));
    if (!Fast_BinaryExpr_setOperator_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::BinaryExpr::setOperator(lang::operatorKind kind)'.");
        goto error;
    }

    /* Define ::hyve::Fast::BinaryExpr::setOperator(lang::operatorKind kind) */
    if (!db_checkState(Fast_BinaryExpr_setOperator_o, DB_DEFINED)) {
        db_function(Fast_BinaryExpr_setOperator_o)->returnType = db_resolve_ext(Fast_BinaryExpr_setOperator_o, NULL, "::hyve::lang::void", FALSE, "element ::hyve::Fast::BinaryExpr::setOperator(lang::operatorKind kind).returnType");
        db_function(Fast_BinaryExpr_setOperator_o)->returnsReference = FALSE;
        Fast_BinaryExpr_setOperator_o->virtual = FALSE;
        
        /* Bind Fast_BinaryExpr_setOperator_o with C-function */
        db_function(Fast_BinaryExpr_setOperator_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_BinaryExpr_setOperator(void *args, void *result);
        db_function(Fast_BinaryExpr_setOperator_o)->impl = (db_word)__Fast_BinaryExpr_setOperator;
        if (db_define(Fast_BinaryExpr_setOperator_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::BinaryExpr::setOperator(lang::operatorKind kind)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::BinaryExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
    Fast_BinaryExpr_toIc_o = db_declare(Fast_BinaryExpr_o, "toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)", db_typedef(db_virtual_o));
    if (!Fast_BinaryExpr_toIc_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::BinaryExpr::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)'.");
        goto error;
    }

    /* Define ::hyve::Fast::BinaryExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
    if (!db_checkState(Fast_BinaryExpr_toIc_o, DB_DEFINED)) {
        db_function(Fast_BinaryExpr_toIc_o)->returnType = db_resolve_ext(Fast_BinaryExpr_toIc_o, NULL, "::hyve::lang::alias{\"db_ic\"}", FALSE, "element ::hyve::Fast::BinaryExpr::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored).returnType");
        db_function(Fast_BinaryExpr_toIc_o)->returnsReference = FALSE;
        db_method(Fast_BinaryExpr_toIc_o)->virtual = TRUE;
        
        /* Bind Fast_BinaryExpr_toIc_o with C-function */
        db_function(Fast_BinaryExpr_toIc_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_BinaryExpr_toIc_v(void *args, void *result);
        db_function(Fast_BinaryExpr_toIc_o)->impl = (db_word)__Fast_BinaryExpr_toIc_v;
        if (db_define(Fast_BinaryExpr_toIc_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::BinaryExpr::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::BinaryExpr */
    if (!db_checkState(Fast_BinaryExpr_o, DB_DEFINED)) {
        db_type(Fast_BinaryExpr_o)->defaultType = db_resolve_ext(Fast_BinaryExpr_o, NULL, "::hyve::lang::member", FALSE, "element ::hyve::Fast::BinaryExpr.defaultType");
        db_type(Fast_BinaryExpr_o)->parentType = NULL;
        db_type(Fast_BinaryExpr_o)->parentState = 0x0;
        db_interface(Fast_BinaryExpr_o)->base = db_resolve_ext(Fast_BinaryExpr_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::BinaryExpr.base");
        db_struct(Fast_BinaryExpr_o)->baseAccess = 0x4;
        Fast_BinaryExpr_o->implements.length = 0;
        Fast_BinaryExpr_o->implements.buffer = NULL;
        if (db_define(Fast_BinaryExpr_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::BinaryExpr'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::Block::lookup(lang::string id) */
    if (!db_checkState(Fast_Block_lookup_o, DB_DEFINED)) {
        db_function(Fast_Block_lookup_o)->returnType = db_resolve_ext(Fast_Block_lookup_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::Block::lookup(lang::string id).returnType");
        db_function(Fast_Block_lookup_o)->returnsReference = FALSE;
        Fast_Block_lookup_o->virtual = FALSE;
        
        /* Bind Fast_Block_lookup_o with C-function */
        db_function(Fast_Block_lookup_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Block_lookup(void *args, void *result);
        db_function(Fast_Block_lookup_o)->impl = (db_word)__Fast_Block_lookup;
        if (db_define(Fast_Block_lookup_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Block::lookup(lang::string id)'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::Block::lookupLocal(lang::string id) */
    if (!db_checkState(Fast_Block_lookupLocal_o, DB_DEFINED)) {
        db_function(Fast_Block_lookupLocal_o)->returnType = db_resolve_ext(Fast_Block_lookupLocal_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::Block::lookupLocal(lang::string id).returnType");
        db_function(Fast_Block_lookupLocal_o)->returnsReference = FALSE;
        Fast_Block_lookupLocal_o->virtual = FALSE;
        
        /* Bind Fast_Block_lookupLocal_o with C-function */
        db_function(Fast_Block_lookupLocal_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Block_lookupLocal(void *args, void *result);
        db_function(Fast_Block_lookupLocal_o)->impl = (db_word)__Fast_Block_lookupLocal;
        if (db_define(Fast_Block_lookupLocal_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Block::lookupLocal(lang::string id)'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::Block::resolve(lang::string id) */
    if (!db_checkState(Fast_Block_resolve_o, DB_DEFINED)) {
        db_function(Fast_Block_resolve_o)->returnType = db_resolve_ext(Fast_Block_resolve_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::Block::resolve(lang::string id).returnType");
        db_function(Fast_Block_resolve_o)->returnsReference = FALSE;
        Fast_Block_resolve_o->virtual = FALSE;
        
        /* Bind Fast_Block_resolve_o with C-function */
        db_function(Fast_Block_resolve_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Block_resolve(void *args, void *result);
        db_function(Fast_Block_resolve_o)->impl = (db_word)__Fast_Block_resolve;
        if (db_define(Fast_Block_resolve_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Block::resolve(lang::string id)'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::Call::arguments */
    if (!db_checkState(Fast_Call_arguments_o, DB_DEFINED)) {
        Fast_Call_arguments_o->type = db_resolve_ext(Fast_Call_arguments_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::Call::arguments.type");
        Fast_Call_arguments_o->modifiers = 0x0;
        Fast_Call_arguments_o->state = 0x6;
        Fast_Call_arguments_o->weak = FALSE;
        Fast_Call_arguments_o->id = 1;
        if (db_define(Fast_Call_arguments_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Call::arguments'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Call::construct(Fast::Call object) */
    Fast_Call_construct_o = db_declare(Fast_Call_o, "construct(Fast::Call object)", db_typedef(db_callback_o));
    if (!Fast_Call_construct_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Call::construct(Fast::Call object)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Call::construct(Fast::Call object) */
    if (!db_checkState(Fast_Call_construct_o, DB_DEFINED)) {
        db_function(Fast_Call_construct_o)->returnType = db_resolve_ext(Fast_Call_construct_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::Call::construct(Fast::Call object).returnType");
        db_function(Fast_Call_construct_o)->returnsReference = FALSE;
        Fast_Call_construct_o->delegate = db_resolve_ext(Fast_Call_construct_o, NULL, "::hyve::lang::class::construct(lang::object object)", FALSE, "element ::hyve::Fast::Call::construct(Fast::Call object).delegate");
        
        /* Bind Fast_Call_construct_o with C-function */
        db_function(Fast_Call_construct_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Call_construct(void *args, void *result);
        db_function(Fast_Call_construct_o)->impl = (db_word)__Fast_Call_construct;
        if (db_define(Fast_Call_construct_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Call::construct(Fast::Call object)'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::Call::function */
    if (!db_checkState(Fast_Call_function_o, DB_DEFINED)) {
        Fast_Call_function_o->type = db_resolve_ext(Fast_Call_function_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::Call::function.type");
        Fast_Call_function_o->modifiers = 0x0;
        Fast_Call_function_o->state = 0x6;
        Fast_Call_function_o->weak = FALSE;
        Fast_Call_function_o->id = 0;
        if (db_define(Fast_Call_function_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Call::function'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Call::hasSideEffects() */
    Fast_Call_hasSideEffects_o = db_declare(Fast_Call_o, "hasSideEffects()", db_typedef(db_virtual_o));
    if (!Fast_Call_hasSideEffects_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Call::hasSideEffects()'.");
        goto error;
    }

    /* Define ::hyve::Fast::Call::hasSideEffects() */
    if (!db_checkState(Fast_Call_hasSideEffects_o, DB_DEFINED)) {
        db_function(Fast_Call_hasSideEffects_o)->returnType = db_resolve_ext(Fast_Call_hasSideEffects_o, NULL, "::hyve::lang::bool", FALSE, "element ::hyve::Fast::Call::hasSideEffects().returnType");
        db_function(Fast_Call_hasSideEffects_o)->returnsReference = FALSE;
        db_method(Fast_Call_hasSideEffects_o)->virtual = TRUE;
        
        /* Bind Fast_Call_hasSideEffects_o with C-function */
        db_function(Fast_Call_hasSideEffects_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Call_hasSideEffects_v(void *args, void *result);
        db_function(Fast_Call_hasSideEffects_o)->impl = (db_word)__Fast_Call_hasSideEffects_v;
        if (db_define(Fast_Call_hasSideEffects_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Call::hasSideEffects()'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Call::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
    Fast_Call_toIc_o = db_declare(Fast_Call_o, "toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)", db_typedef(db_virtual_o));
    if (!Fast_Call_toIc_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Call::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Call::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
    if (!db_checkState(Fast_Call_toIc_o, DB_DEFINED)) {
        db_function(Fast_Call_toIc_o)->returnType = db_resolve_ext(Fast_Call_toIc_o, NULL, "::hyve::lang::alias{\"db_ic\"}", FALSE, "element ::hyve::Fast::Call::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored).returnType");
        db_function(Fast_Call_toIc_o)->returnsReference = FALSE;
        db_method(Fast_Call_toIc_o)->virtual = TRUE;
        
        /* Bind Fast_Call_toIc_o with C-function */
        db_function(Fast_Call_toIc_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Call_toIc_v(void *args, void *result);
        db_function(Fast_Call_toIc_o)->impl = (db_word)__Fast_Call_toIc_v;
        if (db_define(Fast_Call_toIc_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Call::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::Call */
    if (!db_checkState(Fast_Call_o, DB_DEFINED)) {
        db_type(Fast_Call_o)->defaultType = db_resolve_ext(Fast_Call_o, NULL, "::hyve::lang::member", FALSE, "element ::hyve::Fast::Call.defaultType");
        db_type(Fast_Call_o)->parentType = NULL;
        db_type(Fast_Call_o)->parentState = 0x0;
        db_interface(Fast_Call_o)->base = db_resolve_ext(Fast_Call_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::Call.base");
        db_struct(Fast_Call_o)->baseAccess = 0x4;
        Fast_Call_o->implements.length = 0;
        Fast_Call_o->implements.buffer = NULL;
        if (db_define(Fast_Call_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Call'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::CastExpr::construct(Fast::CastExpr object) */
    Fast_CastExpr_construct_o = db_declare(Fast_CastExpr_o, "construct(Fast::CastExpr object)", db_typedef(db_callback_o));
    if (!Fast_CastExpr_construct_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::CastExpr::construct(Fast::CastExpr object)'.");
        goto error;
    }

    /* Define ::hyve::Fast::CastExpr::construct(Fast::CastExpr object) */
    if (!db_checkState(Fast_CastExpr_construct_o, DB_DEFINED)) {
        db_function(Fast_CastExpr_construct_o)->returnType = db_resolve_ext(Fast_CastExpr_construct_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::CastExpr::construct(Fast::CastExpr object).returnType");
        db_function(Fast_CastExpr_construct_o)->returnsReference = FALSE;
        Fast_CastExpr_construct_o->delegate = db_resolve_ext(Fast_CastExpr_construct_o, NULL, "::hyve::lang::class::construct(lang::object object)", FALSE, "element ::hyve::Fast::CastExpr::construct(Fast::CastExpr object).delegate");
        
        /* Bind Fast_CastExpr_construct_o with C-function */
        db_function(Fast_CastExpr_construct_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_CastExpr_construct(void *args, void *result);
        db_function(Fast_CastExpr_construct_o)->impl = (db_word)__Fast_CastExpr_construct;
        if (db_define(Fast_CastExpr_construct_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::CastExpr::construct(Fast::CastExpr object)'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::CastExpr::lvalue */
    if (!db_checkState(Fast_CastExpr_lvalue_o, DB_DEFINED)) {
        Fast_CastExpr_lvalue_o->type = db_resolve_ext(Fast_CastExpr_lvalue_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::CastExpr::lvalue.type");
        Fast_CastExpr_lvalue_o->modifiers = 0x0;
        Fast_CastExpr_lvalue_o->state = 0x6;
        Fast_CastExpr_lvalue_o->weak = FALSE;
        Fast_CastExpr_lvalue_o->id = 0;
        if (db_define(Fast_CastExpr_lvalue_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::CastExpr::lvalue'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::CastExpr::rvalue */
    if (!db_checkState(Fast_CastExpr_rvalue_o, DB_DEFINED)) {
        Fast_CastExpr_rvalue_o->type = db_resolve_ext(Fast_CastExpr_rvalue_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::CastExpr::rvalue.type");
        Fast_CastExpr_rvalue_o->modifiers = 0x0;
        Fast_CastExpr_rvalue_o->state = 0x6;
        Fast_CastExpr_rvalue_o->weak = FALSE;
        Fast_CastExpr_rvalue_o->id = 1;
        if (db_define(Fast_CastExpr_rvalue_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::CastExpr::rvalue'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::CastExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
    Fast_CastExpr_toIc_o = db_declare(Fast_CastExpr_o, "toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)", db_typedef(db_virtual_o));
    if (!Fast_CastExpr_toIc_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::CastExpr::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)'.");
        goto error;
    }

    /* Define ::hyve::Fast::CastExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
    if (!db_checkState(Fast_CastExpr_toIc_o, DB_DEFINED)) {
        db_function(Fast_CastExpr_toIc_o)->returnType = db_resolve_ext(Fast_CastExpr_toIc_o, NULL, "::hyve::lang::alias{\"db_ic\"}", FALSE, "element ::hyve::Fast::CastExpr::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored).returnType");
        db_function(Fast_CastExpr_toIc_o)->returnsReference = FALSE;
        db_method(Fast_CastExpr_toIc_o)->virtual = TRUE;
        
        /* Bind Fast_CastExpr_toIc_o with C-function */
        db_function(Fast_CastExpr_toIc_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_CastExpr_toIc_v(void *args, void *result);
        db_function(Fast_CastExpr_toIc_o)->impl = (db_word)__Fast_CastExpr_toIc_v;
        if (db_define(Fast_CastExpr_toIc_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::CastExpr::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::CastExpr */
    if (!db_checkState(Fast_CastExpr_o, DB_DEFINED)) {
        db_type(Fast_CastExpr_o)->defaultType = db_resolve_ext(Fast_CastExpr_o, NULL, "::hyve::lang::member", FALSE, "element ::hyve::Fast::CastExpr.defaultType");
        db_type(Fast_CastExpr_o)->parentType = NULL;
        db_type(Fast_CastExpr_o)->parentState = 0x0;
        db_interface(Fast_CastExpr_o)->base = db_resolve_ext(Fast_CastExpr_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::CastExpr.base");
        db_struct(Fast_CastExpr_o)->baseAccess = 0x4;
        Fast_CastExpr_o->implements.length = 0;
        Fast_CastExpr_o->implements.buffer = NULL;
        if (db_define(Fast_CastExpr_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::CastExpr'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::CommaExpr::addExpression(Expression expr) */
    Fast_CommaExpr_addExpression_o = db_declare(Fast_CommaExpr_o, "addExpression(Expression expr)", db_typedef(db_method_o));
    if (!Fast_CommaExpr_addExpression_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::CommaExpr::addExpression(Expression expr)'.");
        goto error;
    }

    /* Define ::hyve::Fast::CommaExpr::addExpression(Expression expr) */
    if (!db_checkState(Fast_CommaExpr_addExpression_o, DB_DEFINED)) {
        db_function(Fast_CommaExpr_addExpression_o)->returnType = db_resolve_ext(Fast_CommaExpr_addExpression_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::CommaExpr::addExpression(Expression expr).returnType");
        db_function(Fast_CommaExpr_addExpression_o)->returnsReference = FALSE;
        Fast_CommaExpr_addExpression_o->virtual = FALSE;
        
        /* Bind Fast_CommaExpr_addExpression_o with C-function */
        db_function(Fast_CommaExpr_addExpression_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_CommaExpr_addExpression(void *args, void *result);
        db_function(Fast_CommaExpr_addExpression_o)->impl = (db_word)__Fast_CommaExpr_addExpression;
        if (db_define(Fast_CommaExpr_addExpression_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::CommaExpr::addExpression(Expression expr)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::CommaExpr::addOrCreate(Expression list,Expression expr) */
    Fast_CommaExpr_addOrCreate_o = db_declare(Fast_CommaExpr_o, "addOrCreate(Expression list,Expression expr)", db_typedef(db_function_o));
    if (!Fast_CommaExpr_addOrCreate_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::CommaExpr::addOrCreate(Expression list,Expression expr)'.");
        goto error;
    }

    /* Define ::hyve::Fast::CommaExpr::addOrCreate(Expression list,Expression expr) */
    if (!db_checkState(Fast_CommaExpr_addOrCreate_o, DB_DEFINED)) {
        Fast_CommaExpr_addOrCreate_o->returnType = db_resolve_ext(Fast_CommaExpr_addOrCreate_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::CommaExpr::addOrCreate(Expression list,Expression expr).returnType");
        Fast_CommaExpr_addOrCreate_o->returnsReference = FALSE;
        
        /* Bind Fast_CommaExpr_addOrCreate_o with C-function */
        db_function(Fast_CommaExpr_addOrCreate_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_CommaExpr_addOrCreate(void *args, void *result);
        db_function(Fast_CommaExpr_addOrCreate_o)->impl = (db_word)__Fast_CommaExpr_addOrCreate;
        if (db_define(Fast_CommaExpr_addOrCreate_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::CommaExpr::addOrCreate(Expression list,Expression expr)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::CommaExpr::construct(CommaExpr object) */
    Fast_CommaExpr_construct_o = db_declare(Fast_CommaExpr_o, "construct(CommaExpr object)", db_typedef(db_callback_o));
    if (!Fast_CommaExpr_construct_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::CommaExpr::construct(CommaExpr object)'.");
        goto error;
    }

    /* Define ::hyve::Fast::CommaExpr::construct(CommaExpr object) */
    if (!db_checkState(Fast_CommaExpr_construct_o, DB_DEFINED)) {
        db_function(Fast_CommaExpr_construct_o)->returnType = db_resolve_ext(Fast_CommaExpr_construct_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::CommaExpr::construct(CommaExpr object).returnType");
        db_function(Fast_CommaExpr_construct_o)->returnsReference = FALSE;
        Fast_CommaExpr_construct_o->delegate = db_resolve_ext(Fast_CommaExpr_construct_o, NULL, "::hyve::lang::class::construct(lang::object object)", FALSE, "element ::hyve::Fast::CommaExpr::construct(CommaExpr object).delegate");
        
        /* Bind Fast_CommaExpr_construct_o with C-function */
        db_function(Fast_CommaExpr_construct_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_CommaExpr_construct(void *args, void *result);
        db_function(Fast_CommaExpr_construct_o)->impl = (db_word)__Fast_CommaExpr_construct;
        if (db_define(Fast_CommaExpr_construct_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::CommaExpr::construct(CommaExpr object)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::CommaExpr::hasSideEffects() */
    Fast_CommaExpr_hasSideEffects_o = db_declare(Fast_CommaExpr_o, "hasSideEffects()", db_typedef(db_virtual_o));
    if (!Fast_CommaExpr_hasSideEffects_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::CommaExpr::hasSideEffects()'.");
        goto error;
    }

    /* Define ::hyve::Fast::CommaExpr::hasSideEffects() */
    if (!db_checkState(Fast_CommaExpr_hasSideEffects_o, DB_DEFINED)) {
        db_function(Fast_CommaExpr_hasSideEffects_o)->returnType = db_resolve_ext(Fast_CommaExpr_hasSideEffects_o, NULL, "::hyve::lang::bool", FALSE, "element ::hyve::Fast::CommaExpr::hasSideEffects().returnType");
        db_function(Fast_CommaExpr_hasSideEffects_o)->returnsReference = FALSE;
        db_method(Fast_CommaExpr_hasSideEffects_o)->virtual = TRUE;
        
        /* Bind Fast_CommaExpr_hasSideEffects_o with C-function */
        db_function(Fast_CommaExpr_hasSideEffects_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_CommaExpr_hasSideEffects_v(void *args, void *result);
        db_function(Fast_CommaExpr_hasSideEffects_o)->impl = (db_word)__Fast_CommaExpr_hasSideEffects_v;
        if (db_define(Fast_CommaExpr_hasSideEffects_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::CommaExpr::hasSideEffects()'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::CommaExpr::init(CommaExpr object) */
    Fast_CommaExpr_init_o = db_declare(Fast_CommaExpr_o, "init(CommaExpr object)", db_typedef(db_callback_o));
    if (!Fast_CommaExpr_init_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::CommaExpr::init(CommaExpr object)'.");
        goto error;
    }

    /* Define ::hyve::Fast::CommaExpr::init(CommaExpr object) */
    if (!db_checkState(Fast_CommaExpr_init_o, DB_DEFINED)) {
        db_function(Fast_CommaExpr_init_o)->returnType = db_resolve_ext(Fast_CommaExpr_init_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::CommaExpr::init(CommaExpr object).returnType");
        db_function(Fast_CommaExpr_init_o)->returnsReference = FALSE;
        Fast_CommaExpr_init_o->delegate = db_resolve_ext(Fast_CommaExpr_init_o, NULL, "::hyve::lang::type::init(lang::object object)", FALSE, "element ::hyve::Fast::CommaExpr::init(CommaExpr object).delegate");
        
        /* Bind Fast_CommaExpr_init_o with C-function */
        db_function(Fast_CommaExpr_init_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_CommaExpr_init(void *args, void *result);
        db_function(Fast_CommaExpr_init_o)->impl = (db_word)__Fast_CommaExpr_init;
        if (db_define(Fast_CommaExpr_init_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::CommaExpr::init(CommaExpr object)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::CommaExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
    Fast_CommaExpr_toIc_o = db_declare(Fast_CommaExpr_o, "toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)", db_typedef(db_virtual_o));
    if (!Fast_CommaExpr_toIc_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::CommaExpr::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)'.");
        goto error;
    }

    /* Define ::hyve::Fast::CommaExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
    if (!db_checkState(Fast_CommaExpr_toIc_o, DB_DEFINED)) {
        db_function(Fast_CommaExpr_toIc_o)->returnType = db_resolve_ext(Fast_CommaExpr_toIc_o, NULL, "::hyve::lang::alias{\"db_ic\"}", FALSE, "element ::hyve::Fast::CommaExpr::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored).returnType");
        db_function(Fast_CommaExpr_toIc_o)->returnsReference = FALSE;
        db_method(Fast_CommaExpr_toIc_o)->virtual = TRUE;
        
        /* Bind Fast_CommaExpr_toIc_o with C-function */
        db_function(Fast_CommaExpr_toIc_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_CommaExpr_toIc_v(void *args, void *result);
        db_function(Fast_CommaExpr_toIc_o)->impl = (db_word)__Fast_CommaExpr_toIc_v;
        if (db_define(Fast_CommaExpr_toIc_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::CommaExpr::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::CommaExpr::toList() */
    Fast_CommaExpr_toList_o = db_declare(Fast_CommaExpr_o, "toList()", db_typedef(db_method_o));
    if (!Fast_CommaExpr_toList_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::CommaExpr::toList()'.");
        goto error;
    }

    /* Define ::hyve::Fast::CommaExpr::toList() */
    if (!db_checkState(Fast_CommaExpr_toList_o, DB_DEFINED)) {
        db_function(Fast_CommaExpr_toList_o)->returnType = db_resolve_ext(Fast_CommaExpr_toList_o, NULL, "::hyve::lang::list{::hyve::Fast::Node,0}", FALSE, "element ::hyve::Fast::CommaExpr::toList().returnType");
        db_function(Fast_CommaExpr_toList_o)->returnsReference = FALSE;
        Fast_CommaExpr_toList_o->virtual = FALSE;
        
        /* Bind Fast_CommaExpr_toList_o with C-function */
        db_function(Fast_CommaExpr_toList_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_CommaExpr_toList(void *args, void *result);
        db_function(Fast_CommaExpr_toList_o)->impl = (db_word)__Fast_CommaExpr_toList;
        if (db_define(Fast_CommaExpr_toList_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::CommaExpr::toList()'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::CommaExpr */
    if (!db_checkState(Fast_CommaExpr_o, DB_DEFINED)) {
        db_type(Fast_CommaExpr_o)->defaultType = db_resolve_ext(Fast_CommaExpr_o, NULL, "::hyve::lang::member", FALSE, "element ::hyve::Fast::CommaExpr.defaultType");
        db_type(Fast_CommaExpr_o)->parentType = NULL;
        db_type(Fast_CommaExpr_o)->parentState = 0x0;
        db_interface(Fast_CommaExpr_o)->base = db_resolve_ext(Fast_CommaExpr_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::CommaExpr.base");
        db_struct(Fast_CommaExpr_o)->baseAccess = 0x4;
        Fast_CommaExpr_o->implements.length = 0;
        Fast_CommaExpr_o->implements.buffer = NULL;
        if (db_define(Fast_CommaExpr_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::CommaExpr'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::Define::object */
    if (!db_checkState(Fast_Define_object_o, DB_DEFINED)) {
        Fast_Define_object_o->type = db_resolve_ext(Fast_Define_object_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::Define::object.type");
        Fast_Define_object_o->modifiers = 0x0;
        Fast_Define_object_o->state = 0x6;
        Fast_Define_object_o->weak = FALSE;
        Fast_Define_object_o->id = 0;
        if (db_define(Fast_Define_object_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Define::object'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::Define */
    if (!db_checkState(Fast_Define_o, DB_DEFINED)) {
        db_type(Fast_Define_o)->defaultType = db_resolve_ext(Fast_Define_o, NULL, "::hyve::lang::member", FALSE, "element ::hyve::Fast::Define.defaultType");
        db_type(Fast_Define_o)->parentType = NULL;
        db_type(Fast_Define_o)->parentState = 0x0;
        db_interface(Fast_Define_o)->base = db_resolve_ext(Fast_Define_o, NULL, "::hyve::Fast::Node", FALSE, "element ::hyve::Fast::Define.base");
        db_struct(Fast_Define_o)->baseAccess = 0x4;
        Fast_Define_o->implements.length = 0;
        Fast_Define_o->implements.buffer = NULL;
        if (db_define(Fast_Define_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Define'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::ElementExpr::lvalue */
    if (!db_checkState(Fast_ElementExpr_lvalue_o, DB_DEFINED)) {
        Fast_ElementExpr_lvalue_o->type = db_resolve_ext(Fast_ElementExpr_lvalue_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::ElementExpr::lvalue.type");
        Fast_ElementExpr_lvalue_o->modifiers = 0x0;
        Fast_ElementExpr_lvalue_o->state = 0x6;
        Fast_ElementExpr_lvalue_o->weak = FALSE;
        Fast_ElementExpr_lvalue_o->id = 0;
        if (db_define(Fast_ElementExpr_lvalue_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::ElementExpr::lvalue'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::ElementExpr::rvalue */
    if (!db_checkState(Fast_ElementExpr_rvalue_o, DB_DEFINED)) {
        Fast_ElementExpr_rvalue_o->type = db_resolve_ext(Fast_ElementExpr_rvalue_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::ElementExpr::rvalue.type");
        Fast_ElementExpr_rvalue_o->modifiers = 0x0;
        Fast_ElementExpr_rvalue_o->state = 0x6;
        Fast_ElementExpr_rvalue_o->weak = FALSE;
        Fast_ElementExpr_rvalue_o->id = 1;
        if (db_define(Fast_ElementExpr_rvalue_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::ElementExpr::rvalue'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::ElementExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
    Fast_ElementExpr_toIc_o = db_declare(Fast_ElementExpr_o, "toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)", db_typedef(db_virtual_o));
    if (!Fast_ElementExpr_toIc_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::ElementExpr::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)'.");
        goto error;
    }

    /* Define ::hyve::Fast::ElementExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
    if (!db_checkState(Fast_ElementExpr_toIc_o, DB_DEFINED)) {
        db_function(Fast_ElementExpr_toIc_o)->returnType = db_resolve_ext(Fast_ElementExpr_toIc_o, NULL, "::hyve::lang::alias{\"db_ic\"}", FALSE, "element ::hyve::Fast::ElementExpr::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored).returnType");
        db_function(Fast_ElementExpr_toIc_o)->returnsReference = FALSE;
        db_method(Fast_ElementExpr_toIc_o)->virtual = TRUE;
        
        /* Bind Fast_ElementExpr_toIc_o with C-function */
        db_function(Fast_ElementExpr_toIc_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_ElementExpr_toIc_v(void *args, void *result);
        db_function(Fast_ElementExpr_toIc_o)->impl = (db_word)__Fast_ElementExpr_toIc_v;
        if (db_define(Fast_ElementExpr_toIc_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::ElementExpr::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::Expression::fromList(list{Expression} list) */
    if (!db_checkState(Fast_Expression_fromList_o, DB_DEFINED)) {
        Fast_Expression_fromList_o->returnType = db_resolve_ext(Fast_Expression_fromList_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::Expression::fromList(list{Expression} list).returnType");
        Fast_Expression_fromList_o->returnsReference = FALSE;
        
        /* Bind Fast_Expression_fromList_o with C-function */
        db_function(Fast_Expression_fromList_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Expression_fromList(void *args, void *result);
        db_function(Fast_Expression_fromList_o)->impl = (db_word)__Fast_Expression_fromList;
        if (db_define(Fast_Expression_fromList_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Expression::fromList(list{Expression} list)'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::If::condition */
    if (!db_checkState(Fast_If_condition_o, DB_DEFINED)) {
        Fast_If_condition_o->type = db_resolve_ext(Fast_If_condition_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::If::condition.type");
        Fast_If_condition_o->modifiers = 0x0;
        Fast_If_condition_o->state = 0x6;
        Fast_If_condition_o->weak = FALSE;
        Fast_If_condition_o->id = 0;
        if (db_define(Fast_If_condition_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::If::condition'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Initializer::construct(Initializer object) */
    Fast_Initializer_construct_o = db_declare(Fast_Initializer_o, "construct(Initializer object)", db_typedef(db_callback_o));
    if (!Fast_Initializer_construct_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Initializer::construct(Initializer object)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Initializer::construct(Initializer object) */
    if (!db_checkState(Fast_Initializer_construct_o, DB_DEFINED)) {
        db_function(Fast_Initializer_construct_o)->returnType = db_resolve_ext(Fast_Initializer_construct_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::Initializer::construct(Initializer object).returnType");
        db_function(Fast_Initializer_construct_o)->returnsReference = FALSE;
        Fast_Initializer_construct_o->delegate = db_resolve_ext(Fast_Initializer_construct_o, NULL, "::hyve::lang::class::construct(lang::object object)", FALSE, "element ::hyve::Fast::Initializer::construct(Initializer object).delegate");
        
        /* Bind Fast_Initializer_construct_o with C-function */
        db_function(Fast_Initializer_construct_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Initializer_construct(void *args, void *result);
        db_function(Fast_Initializer_construct_o)->impl = (db_word)__Fast_Initializer_construct;
        if (db_define(Fast_Initializer_construct_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Initializer::construct(Initializer object)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Initializer::currentType() */
    Fast_Initializer_currentType_o = db_declare(Fast_Initializer_o, "currentType()", db_typedef(db_method_o));
    if (!Fast_Initializer_currentType_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Initializer::currentType()'.");
        goto error;
    }

    /* Define ::hyve::Fast::Initializer::currentType() */
    if (!db_checkState(Fast_Initializer_currentType_o, DB_DEFINED)) {
        db_function(Fast_Initializer_currentType_o)->returnType = db_resolve_ext(Fast_Initializer_currentType_o, NULL, "::hyve::lang::type", FALSE, "element ::hyve::Fast::Initializer::currentType().returnType");
        db_function(Fast_Initializer_currentType_o)->returnsReference = FALSE;
        Fast_Initializer_currentType_o->virtual = FALSE;
        
        /* Bind Fast_Initializer_currentType_o with C-function */
        db_function(Fast_Initializer_currentType_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Initializer_currentType(void *args, void *result);
        db_function(Fast_Initializer_currentType_o)->impl = (db_word)__Fast_Initializer_currentType;
        if (db_define(Fast_Initializer_currentType_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Initializer::currentType()'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Initializer::define() */
    Fast_Initializer_define_o = db_declare(Fast_Initializer_o, "define()", db_typedef(db_virtual_o));
    if (!Fast_Initializer_define_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Initializer::define()'.");
        goto error;
    }

    /* Define ::hyve::Fast::Initializer::define() */
    if (!db_checkState(Fast_Initializer_define_o, DB_DEFINED)) {
        db_function(Fast_Initializer_define_o)->returnType = db_resolve_ext(Fast_Initializer_define_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::Initializer::define().returnType");
        db_function(Fast_Initializer_define_o)->returnsReference = FALSE;
        db_method(Fast_Initializer_define_o)->virtual = TRUE;
        
        /* Bind Fast_Initializer_define_o with C-function */
        db_function(Fast_Initializer_define_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Initializer_define_v(void *args, void *result);
        db_function(Fast_Initializer_define_o)->impl = (db_word)__Fast_Initializer_define_v;
        if (db_define(Fast_Initializer_define_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Initializer::define()'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Initializer::initFrame() */
    Fast_Initializer_initFrame_o = db_declare(Fast_Initializer_o, "initFrame()", db_typedef(db_method_o));
    if (!Fast_Initializer_initFrame_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Initializer::initFrame()'.");
        goto error;
    }

    /* Define ::hyve::Fast::Initializer::initFrame() */
    if (!db_checkState(Fast_Initializer_initFrame_o, DB_DEFINED)) {
        db_function(Fast_Initializer_initFrame_o)->returnType = db_resolve_ext(Fast_Initializer_initFrame_o, NULL, "::hyve::lang::uint16", FALSE, "element ::hyve::Fast::Initializer::initFrame().returnType");
        db_function(Fast_Initializer_initFrame_o)->returnsReference = FALSE;
        Fast_Initializer_initFrame_o->virtual = FALSE;
        
        /* Bind Fast_Initializer_initFrame_o with C-function */
        db_function(Fast_Initializer_initFrame_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Initializer_initFrame(void *args, void *result);
        db_function(Fast_Initializer_initFrame_o)->impl = (db_word)__Fast_Initializer_initFrame;
        if (db_define(Fast_Initializer_initFrame_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Initializer::initFrame()'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Initializer::member(lang::string name) */
    Fast_Initializer_member_o = db_declare(Fast_Initializer_o, "member(lang::string name)", db_typedef(db_virtual_o));
    if (!Fast_Initializer_member_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Initializer::member(lang::string name)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Initializer::member(lang::string name) */
    if (!db_checkState(Fast_Initializer_member_o, DB_DEFINED)) {
        db_function(Fast_Initializer_member_o)->returnType = db_resolve_ext(Fast_Initializer_member_o, NULL, "::hyve::lang::int32", FALSE, "element ::hyve::Fast::Initializer::member(lang::string name).returnType");
        db_function(Fast_Initializer_member_o)->returnsReference = FALSE;
        db_method(Fast_Initializer_member_o)->virtual = TRUE;
        
        /* Bind Fast_Initializer_member_o with C-function */
        db_function(Fast_Initializer_member_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Initializer_member_v(void *args, void *result);
        db_function(Fast_Initializer_member_o)->impl = (db_word)__Fast_Initializer_member_v;
        if (db_define(Fast_Initializer_member_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Initializer::member(lang::string name)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Initializer::next() */
    Fast_Initializer_next_o = db_declare(Fast_Initializer_o, "next()", db_typedef(db_virtual_o));
    if (!Fast_Initializer_next_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Initializer::next()'.");
        goto error;
    }

    /* Define ::hyve::Fast::Initializer::next() */
    if (!db_checkState(Fast_Initializer_next_o, DB_DEFINED)) {
        db_function(Fast_Initializer_next_o)->returnType = db_resolve_ext(Fast_Initializer_next_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::Initializer::next().returnType");
        db_function(Fast_Initializer_next_o)->returnsReference = FALSE;
        db_method(Fast_Initializer_next_o)->virtual = TRUE;
        
        /* Bind Fast_Initializer_next_o with C-function */
        db_function(Fast_Initializer_next_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Initializer_next_v(void *args, void *result);
        db_function(Fast_Initializer_next_o)->impl = (db_word)__Fast_Initializer_next_v;
        if (db_define(Fast_Initializer_next_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Initializer::next()'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Initializer::pop() */
    Fast_Initializer_pop_o = db_declare(Fast_Initializer_o, "pop()", db_typedef(db_virtual_o));
    if (!Fast_Initializer_pop_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Initializer::pop()'.");
        goto error;
    }

    /* Define ::hyve::Fast::Initializer::pop() */
    if (!db_checkState(Fast_Initializer_pop_o, DB_DEFINED)) {
        db_function(Fast_Initializer_pop_o)->returnType = db_resolve_ext(Fast_Initializer_pop_o, NULL, "::hyve::lang::int8", FALSE, "element ::hyve::Fast::Initializer::pop().returnType");
        db_function(Fast_Initializer_pop_o)->returnsReference = FALSE;
        db_method(Fast_Initializer_pop_o)->virtual = TRUE;
        
        /* Bind Fast_Initializer_pop_o with C-function */
        db_function(Fast_Initializer_pop_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Initializer_pop_v(void *args, void *result);
        db_function(Fast_Initializer_pop_o)->impl = (db_word)__Fast_Initializer_pop_v;
        if (db_define(Fast_Initializer_pop_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Initializer::pop()'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Initializer::popKey() */
    Fast_Initializer_popKey_o = db_declare(Fast_Initializer_o, "popKey()", db_typedef(db_virtual_o));
    if (!Fast_Initializer_popKey_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Initializer::popKey()'.");
        goto error;
    }

    /* Define ::hyve::Fast::Initializer::popKey() */
    if (!db_checkState(Fast_Initializer_popKey_o, DB_DEFINED)) {
        db_function(Fast_Initializer_popKey_o)->returnType = db_resolve_ext(Fast_Initializer_popKey_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::Initializer::popKey().returnType");
        db_function(Fast_Initializer_popKey_o)->returnsReference = FALSE;
        db_method(Fast_Initializer_popKey_o)->virtual = TRUE;
        
        /* Bind Fast_Initializer_popKey_o with C-function */
        db_function(Fast_Initializer_popKey_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Initializer_popKey_v(void *args, void *result);
        db_function(Fast_Initializer_popKey_o)->impl = (db_word)__Fast_Initializer_popKey_v;
        if (db_define(Fast_Initializer_popKey_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Initializer::popKey()'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Initializer::push() */
    Fast_Initializer_push_o = db_declare(Fast_Initializer_o, "push()", db_typedef(db_virtual_o));
    if (!Fast_Initializer_push_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Initializer::push()'.");
        goto error;
    }

    /* Define ::hyve::Fast::Initializer::push() */
    if (!db_checkState(Fast_Initializer_push_o, DB_DEFINED)) {
        db_function(Fast_Initializer_push_o)->returnType = db_resolve_ext(Fast_Initializer_push_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::Initializer::push().returnType");
        db_function(Fast_Initializer_push_o)->returnsReference = FALSE;
        db_method(Fast_Initializer_push_o)->virtual = TRUE;
        
        /* Bind Fast_Initializer_push_o with C-function */
        db_function(Fast_Initializer_push_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Initializer_push_v(void *args, void *result);
        db_function(Fast_Initializer_push_o)->impl = (db_word)__Fast_Initializer_push_v;
        if (db_define(Fast_Initializer_push_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Initializer::push()'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Initializer::pushKey() */
    Fast_Initializer_pushKey_o = db_declare(Fast_Initializer_o, "pushKey()", db_typedef(db_virtual_o));
    if (!Fast_Initializer_pushKey_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Initializer::pushKey()'.");
        goto error;
    }

    /* Define ::hyve::Fast::Initializer::pushKey() */
    if (!db_checkState(Fast_Initializer_pushKey_o, DB_DEFINED)) {
        db_function(Fast_Initializer_pushKey_o)->returnType = db_resolve_ext(Fast_Initializer_pushKey_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::Initializer::pushKey().returnType");
        db_function(Fast_Initializer_pushKey_o)->returnsReference = FALSE;
        db_method(Fast_Initializer_pushKey_o)->virtual = TRUE;
        
        /* Bind Fast_Initializer_pushKey_o with C-function */
        db_function(Fast_Initializer_pushKey_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Initializer_pushKey_v(void *args, void *result);
        db_function(Fast_Initializer_pushKey_o)->impl = (db_word)__Fast_Initializer_pushKey_v;
        if (db_define(Fast_Initializer_pushKey_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Initializer::pushKey()'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Initializer::type() */
    Fast_Initializer_type_o = db_declare(Fast_Initializer_o, "type()", db_typedef(db_method_o));
    if (!Fast_Initializer_type_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Initializer::type()'.");
        goto error;
    }

    /* Define ::hyve::Fast::Initializer::type() */
    if (!db_checkState(Fast_Initializer_type_o, DB_DEFINED)) {
        db_function(Fast_Initializer_type_o)->returnType = db_resolve_ext(Fast_Initializer_type_o, NULL, "::hyve::lang::type", FALSE, "element ::hyve::Fast::Initializer::type().returnType");
        db_function(Fast_Initializer_type_o)->returnsReference = FALSE;
        Fast_Initializer_type_o->virtual = FALSE;
        
        /* Bind Fast_Initializer_type_o with C-function */
        db_function(Fast_Initializer_type_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Initializer_type(void *args, void *result);
        db_function(Fast_Initializer_type_o)->impl = (db_word)__Fast_Initializer_type;
        if (db_define(Fast_Initializer_type_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Initializer::type()'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Initializer::value(Expression v) */
    Fast_Initializer_value_o = db_declare(Fast_Initializer_o, "value(Expression v)", db_typedef(db_virtual_o));
    if (!Fast_Initializer_value_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Initializer::value(Expression v)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Initializer::value(Expression v) */
    if (!db_checkState(Fast_Initializer_value_o, DB_DEFINED)) {
        db_function(Fast_Initializer_value_o)->returnType = db_resolve_ext(Fast_Initializer_value_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::Initializer::value(Expression v).returnType");
        db_function(Fast_Initializer_value_o)->returnsReference = FALSE;
        db_method(Fast_Initializer_value_o)->virtual = TRUE;
        
        /* Bind Fast_Initializer_value_o with C-function */
        db_function(Fast_Initializer_value_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Initializer_value_v(void *args, void *result);
        db_function(Fast_Initializer_value_o)->impl = (db_word)__Fast_Initializer_value_v;
        if (db_define(Fast_Initializer_value_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Initializer::value(Expression v)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Initializer::valueKey(Expression key) */
    Fast_Initializer_valueKey_o = db_declare(Fast_Initializer_o, "valueKey(Expression key)", db_typedef(db_virtual_o));
    if (!Fast_Initializer_valueKey_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Initializer::valueKey(Expression key)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Initializer::valueKey(Expression key) */
    if (!db_checkState(Fast_Initializer_valueKey_o, DB_DEFINED)) {
        db_function(Fast_Initializer_valueKey_o)->returnType = db_resolve_ext(Fast_Initializer_valueKey_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::Initializer::valueKey(Expression key).returnType");
        db_function(Fast_Initializer_valueKey_o)->returnsReference = FALSE;
        db_method(Fast_Initializer_valueKey_o)->virtual = TRUE;
        
        /* Bind Fast_Initializer_valueKey_o with C-function */
        db_function(Fast_Initializer_valueKey_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Initializer_valueKey_v(void *args, void *result);
        db_function(Fast_Initializer_valueKey_o)->impl = (db_word)__Fast_Initializer_valueKey_v;
        if (db_define(Fast_Initializer_valueKey_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Initializer::valueKey(Expression key)'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::InitializerVariable::object */
    if (!db_checkState(Fast_InitializerVariable_object_o, DB_DEFINED)) {
        Fast_InitializerVariable_object_o->type = db_resolve_ext(Fast_InitializerVariable_object_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::InitializerVariable::object.type");
        Fast_InitializerVariable_object_o->modifiers = 0x0;
        Fast_InitializerVariable_object_o->state = 0x6;
        Fast_InitializerVariable_object_o->weak = FALSE;
        Fast_InitializerVariable_object_o->id = 1;
        if (db_define(Fast_InitializerVariable_object_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::InitializerVariable::object'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::InitializerVariable */
    if (!db_checkState(Fast_InitializerVariable_o, DB_DEFINED)) {
        db_type(Fast_InitializerVariable_o)->defaultType = db_resolve_ext(Fast_InitializerVariable_o, NULL, "::hyve::lang::member", FALSE, "element ::hyve::Fast::InitializerVariable.defaultType");
        db_type(Fast_InitializerVariable_o)->parentType = NULL;
        db_type(Fast_InitializerVariable_o)->parentState = 0x0;
        db_interface(Fast_InitializerVariable_o)->base = NULL;
        Fast_InitializerVariable_o->baseAccess = 0x0;
        if (db_define(Fast_InitializerVariable_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::InitializerVariable'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::Initializer::variables */
    if (!db_checkState(Fast_Initializer_variables_o, DB_DEFINED)) {
        Fast_Initializer_variables_o->type = db_resolve_ext(Fast_Initializer_variables_o, NULL, "::hyve::lang::array{::hyve::Fast::InitializerVariable,64,::hyve::Fast::InitializerVariable}", FALSE, "element ::hyve::Fast::Initializer::variables.type");
        Fast_Initializer_variables_o->modifiers = 0x0;
        Fast_Initializer_variables_o->state = 0x6;
        Fast_Initializer_variables_o->weak = FALSE;
        Fast_Initializer_variables_o->id = 0;
        if (db_define(Fast_Initializer_variables_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Initializer::variables'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::Initializer */
    if (!db_checkState(Fast_Initializer_o, DB_DEFINED)) {
        db_type(Fast_Initializer_o)->defaultType = db_resolve_ext(Fast_Initializer_o, NULL, "::hyve::lang::member", FALSE, "element ::hyve::Fast::Initializer.defaultType");
        db_type(Fast_Initializer_o)->parentType = NULL;
        db_type(Fast_Initializer_o)->parentState = 0x0;
        db_interface(Fast_Initializer_o)->base = db_resolve_ext(Fast_Initializer_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::Initializer.base");
        db_struct(Fast_Initializer_o)->baseAccess = 0x4;
        Fast_Initializer_o->implements.length = 0;
        Fast_Initializer_o->implements.buffer = NULL;
        if (db_define(Fast_Initializer_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Initializer'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::DynamicInitializer::construct(DynamicInitializer object) */
    Fast_DynamicInitializer_construct_o = db_declare(Fast_DynamicInitializer_o, "construct(DynamicInitializer object)", db_typedef(db_callback_o));
    if (!Fast_DynamicInitializer_construct_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::DynamicInitializer::construct(DynamicInitializer object)'.");
        goto error;
    }

    /* Define ::hyve::Fast::DynamicInitializer::construct(DynamicInitializer object) */
    if (!db_checkState(Fast_DynamicInitializer_construct_o, DB_DEFINED)) {
        db_function(Fast_DynamicInitializer_construct_o)->returnType = db_resolve_ext(Fast_DynamicInitializer_construct_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::DynamicInitializer::construct(DynamicInitializer object).returnType");
        db_function(Fast_DynamicInitializer_construct_o)->returnsReference = FALSE;
        Fast_DynamicInitializer_construct_o->delegate = db_resolve_ext(Fast_DynamicInitializer_construct_o, NULL, "::hyve::lang::class::construct(lang::object object)", FALSE, "element ::hyve::Fast::DynamicInitializer::construct(DynamicInitializer object).delegate");
        
        /* Bind Fast_DynamicInitializer_construct_o with C-function */
        db_function(Fast_DynamicInitializer_construct_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_DynamicInitializer_construct(void *args, void *result);
        db_function(Fast_DynamicInitializer_construct_o)->impl = (db_word)__Fast_DynamicInitializer_construct;
        if (db_define(Fast_DynamicInitializer_construct_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::DynamicInitializer::construct(DynamicInitializer object)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::DynamicInitializer::define() */
    Fast_DynamicInitializer_define_o = db_declare(Fast_DynamicInitializer_o, "define()", db_typedef(db_method_o));
    if (!Fast_DynamicInitializer_define_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::DynamicInitializer::define()'.");
        goto error;
    }

    /* Define ::hyve::Fast::DynamicInitializer::define() */
    if (!db_checkState(Fast_DynamicInitializer_define_o, DB_DEFINED)) {
        db_function(Fast_DynamicInitializer_define_o)->returnType = db_resolve_ext(Fast_DynamicInitializer_define_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::DynamicInitializer::define().returnType");
        db_function(Fast_DynamicInitializer_define_o)->returnsReference = FALSE;
        Fast_DynamicInitializer_define_o->virtual = FALSE;
        
        /* Bind Fast_DynamicInitializer_define_o with C-function */
        db_function(Fast_DynamicInitializer_define_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_DynamicInitializer_define(void *args, void *result);
        db_function(Fast_DynamicInitializer_define_o)->impl = (db_word)__Fast_DynamicInitializer_define;
        if (db_define(Fast_DynamicInitializer_define_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::DynamicInitializer::define()'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::DynamicInitializer::pop() */
    Fast_DynamicInitializer_pop_o = db_declare(Fast_DynamicInitializer_o, "pop()", db_typedef(db_method_o));
    if (!Fast_DynamicInitializer_pop_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::DynamicInitializer::pop()'.");
        goto error;
    }

    /* Define ::hyve::Fast::DynamicInitializer::pop() */
    if (!db_checkState(Fast_DynamicInitializer_pop_o, DB_DEFINED)) {
        db_function(Fast_DynamicInitializer_pop_o)->returnType = db_resolve_ext(Fast_DynamicInitializer_pop_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::DynamicInitializer::pop().returnType");
        db_function(Fast_DynamicInitializer_pop_o)->returnsReference = FALSE;
        Fast_DynamicInitializer_pop_o->virtual = FALSE;
        
        /* Bind Fast_DynamicInitializer_pop_o with C-function */
        db_function(Fast_DynamicInitializer_pop_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_DynamicInitializer_pop(void *args, void *result);
        db_function(Fast_DynamicInitializer_pop_o)->impl = (db_word)__Fast_DynamicInitializer_pop;
        if (db_define(Fast_DynamicInitializer_pop_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::DynamicInitializer::pop()'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::DynamicInitializer::push() */
    Fast_DynamicInitializer_push_o = db_declare(Fast_DynamicInitializer_o, "push()", db_typedef(db_method_o));
    if (!Fast_DynamicInitializer_push_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::DynamicInitializer::push()'.");
        goto error;
    }

    /* Define ::hyve::Fast::DynamicInitializer::push() */
    if (!db_checkState(Fast_DynamicInitializer_push_o, DB_DEFINED)) {
        db_function(Fast_DynamicInitializer_push_o)->returnType = db_resolve_ext(Fast_DynamicInitializer_push_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::DynamicInitializer::push().returnType");
        db_function(Fast_DynamicInitializer_push_o)->returnsReference = FALSE;
        Fast_DynamicInitializer_push_o->virtual = FALSE;
        
        /* Bind Fast_DynamicInitializer_push_o with C-function */
        db_function(Fast_DynamicInitializer_push_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_DynamicInitializer_push(void *args, void *result);
        db_function(Fast_DynamicInitializer_push_o)->impl = (db_word)__Fast_DynamicInitializer_push;
        if (db_define(Fast_DynamicInitializer_push_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::DynamicInitializer::push()'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::DynamicInitializer::value(Expression v) */
    Fast_DynamicInitializer_value_o = db_declare(Fast_DynamicInitializer_o, "value(Expression v)", db_typedef(db_method_o));
    if (!Fast_DynamicInitializer_value_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::DynamicInitializer::value(Expression v)'.");
        goto error;
    }

    /* Define ::hyve::Fast::DynamicInitializer::value(Expression v) */
    if (!db_checkState(Fast_DynamicInitializer_value_o, DB_DEFINED)) {
        db_function(Fast_DynamicInitializer_value_o)->returnType = db_resolve_ext(Fast_DynamicInitializer_value_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::DynamicInitializer::value(Expression v).returnType");
        db_function(Fast_DynamicInitializer_value_o)->returnsReference = FALSE;
        Fast_DynamicInitializer_value_o->virtual = FALSE;
        
        /* Bind Fast_DynamicInitializer_value_o with C-function */
        db_function(Fast_DynamicInitializer_value_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_DynamicInitializer_value(void *args, void *result);
        db_function(Fast_DynamicInitializer_value_o)->impl = (db_word)__Fast_DynamicInitializer_value;
        if (db_define(Fast_DynamicInitializer_value_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::DynamicInitializer::value(Expression v)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::InitializerExpr::construct(InitializerExpr object) */
    Fast_InitializerExpr_construct_o = db_declare(Fast_InitializerExpr_o, "construct(InitializerExpr object)", db_typedef(db_callback_o));
    if (!Fast_InitializerExpr_construct_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::InitializerExpr::construct(InitializerExpr object)'.");
        goto error;
    }

    /* Define ::hyve::Fast::InitializerExpr::construct(InitializerExpr object) */
    if (!db_checkState(Fast_InitializerExpr_construct_o, DB_DEFINED)) {
        db_function(Fast_InitializerExpr_construct_o)->returnType = db_resolve_ext(Fast_InitializerExpr_construct_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::InitializerExpr::construct(InitializerExpr object).returnType");
        db_function(Fast_InitializerExpr_construct_o)->returnsReference = FALSE;
        Fast_InitializerExpr_construct_o->delegate = db_resolve_ext(Fast_InitializerExpr_construct_o, NULL, "::hyve::lang::class::construct(lang::object object)", FALSE, "element ::hyve::Fast::InitializerExpr::construct(InitializerExpr object).delegate");
        
        /* Bind Fast_InitializerExpr_construct_o with C-function */
        db_function(Fast_InitializerExpr_construct_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_InitializerExpr_construct(void *args, void *result);
        db_function(Fast_InitializerExpr_construct_o)->impl = (db_word)__Fast_InitializerExpr_construct;
        if (db_define(Fast_InitializerExpr_construct_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::InitializerExpr::construct(InitializerExpr object)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::InitializerExpr::define() */
    Fast_InitializerExpr_define_o = db_declare(Fast_InitializerExpr_o, "define()", db_typedef(db_method_o));
    if (!Fast_InitializerExpr_define_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::InitializerExpr::define()'.");
        goto error;
    }

    /* Define ::hyve::Fast::InitializerExpr::define() */
    if (!db_checkState(Fast_InitializerExpr_define_o, DB_DEFINED)) {
        db_function(Fast_InitializerExpr_define_o)->returnType = db_resolve_ext(Fast_InitializerExpr_define_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::InitializerExpr::define().returnType");
        db_function(Fast_InitializerExpr_define_o)->returnsReference = FALSE;
        Fast_InitializerExpr_define_o->virtual = FALSE;
        
        /* Bind Fast_InitializerExpr_define_o with C-function */
        db_function(Fast_InitializerExpr_define_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_InitializerExpr_define(void *args, void *result);
        db_function(Fast_InitializerExpr_define_o)->impl = (db_word)__Fast_InitializerExpr_define;
        if (db_define(Fast_InitializerExpr_define_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::InitializerExpr::define()'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::InitializerExpr::insert(Expression variable) */
    Fast_InitializerExpr_insert_o = db_declare(Fast_InitializerExpr_o, "insert(Expression variable)", db_typedef(db_method_o));
    if (!Fast_InitializerExpr_insert_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::InitializerExpr::insert(Expression variable)'.");
        goto error;
    }

    /* Define ::hyve::Fast::InitializerExpr::insert(Expression variable) */
    if (!db_checkState(Fast_InitializerExpr_insert_o, DB_DEFINED)) {
        db_function(Fast_InitializerExpr_insert_o)->returnType = db_resolve_ext(Fast_InitializerExpr_insert_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::InitializerExpr::insert(Expression variable).returnType");
        db_function(Fast_InitializerExpr_insert_o)->returnsReference = FALSE;
        Fast_InitializerExpr_insert_o->virtual = FALSE;
        
        /* Bind Fast_InitializerExpr_insert_o with C-function */
        db_function(Fast_InitializerExpr_insert_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_InitializerExpr_insert(void *args, void *result);
        db_function(Fast_InitializerExpr_insert_o)->impl = (db_word)__Fast_InitializerExpr_insert;
        if (db_define(Fast_InitializerExpr_insert_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::InitializerExpr::insert(Expression variable)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::InitializerExpr::member(lang::string name) */
    Fast_InitializerExpr_member_o = db_declare(Fast_InitializerExpr_o, "member(lang::string name)", db_typedef(db_method_o));
    if (!Fast_InitializerExpr_member_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::InitializerExpr::member(lang::string name)'.");
        goto error;
    }

    /* Define ::hyve::Fast::InitializerExpr::member(lang::string name) */
    if (!db_checkState(Fast_InitializerExpr_member_o, DB_DEFINED)) {
        db_function(Fast_InitializerExpr_member_o)->returnType = db_resolve_ext(Fast_InitializerExpr_member_o, NULL, "::hyve::lang::int32", FALSE, "element ::hyve::Fast::InitializerExpr::member(lang::string name).returnType");
        db_function(Fast_InitializerExpr_member_o)->returnsReference = FALSE;
        Fast_InitializerExpr_member_o->virtual = FALSE;
        
        /* Bind Fast_InitializerExpr_member_o with C-function */
        db_function(Fast_InitializerExpr_member_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_InitializerExpr_member(void *args, void *result);
        db_function(Fast_InitializerExpr_member_o)->impl = (db_word)__Fast_InitializerExpr_member;
        if (db_define(Fast_InitializerExpr_member_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::InitializerExpr::member(lang::string name)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::InitializerExpr::pop() */
    Fast_InitializerExpr_pop_o = db_declare(Fast_InitializerExpr_o, "pop()", db_typedef(db_method_o));
    if (!Fast_InitializerExpr_pop_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::InitializerExpr::pop()'.");
        goto error;
    }

    /* Define ::hyve::Fast::InitializerExpr::pop() */
    if (!db_checkState(Fast_InitializerExpr_pop_o, DB_DEFINED)) {
        db_function(Fast_InitializerExpr_pop_o)->returnType = db_resolve_ext(Fast_InitializerExpr_pop_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::InitializerExpr::pop().returnType");
        db_function(Fast_InitializerExpr_pop_o)->returnsReference = FALSE;
        Fast_InitializerExpr_pop_o->virtual = FALSE;
        
        /* Bind Fast_InitializerExpr_pop_o with C-function */
        db_function(Fast_InitializerExpr_pop_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_InitializerExpr_pop(void *args, void *result);
        db_function(Fast_InitializerExpr_pop_o)->impl = (db_word)__Fast_InitializerExpr_pop;
        if (db_define(Fast_InitializerExpr_pop_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::InitializerExpr::pop()'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::InitializerExpr::push() */
    Fast_InitializerExpr_push_o = db_declare(Fast_InitializerExpr_o, "push()", db_typedef(db_method_o));
    if (!Fast_InitializerExpr_push_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::InitializerExpr::push()'.");
        goto error;
    }

    /* Define ::hyve::Fast::InitializerExpr::push() */
    if (!db_checkState(Fast_InitializerExpr_push_o, DB_DEFINED)) {
        db_function(Fast_InitializerExpr_push_o)->returnType = db_resolve_ext(Fast_InitializerExpr_push_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::InitializerExpr::push().returnType");
        db_function(Fast_InitializerExpr_push_o)->returnsReference = FALSE;
        Fast_InitializerExpr_push_o->virtual = FALSE;
        
        /* Bind Fast_InitializerExpr_push_o with C-function */
        db_function(Fast_InitializerExpr_push_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_InitializerExpr_push(void *args, void *result);
        db_function(Fast_InitializerExpr_push_o)->impl = (db_word)__Fast_InitializerExpr_push;
        if (db_define(Fast_InitializerExpr_push_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::InitializerExpr::push()'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::InitializerExpr::value(Expression v) */
    Fast_InitializerExpr_value_o = db_declare(Fast_InitializerExpr_o, "value(Expression v)", db_typedef(db_method_o));
    if (!Fast_InitializerExpr_value_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::InitializerExpr::value(Expression v)'.");
        goto error;
    }

    /* Define ::hyve::Fast::InitializerExpr::value(Expression v) */
    if (!db_checkState(Fast_InitializerExpr_value_o, DB_DEFINED)) {
        db_function(Fast_InitializerExpr_value_o)->returnType = db_resolve_ext(Fast_InitializerExpr_value_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::InitializerExpr::value(Expression v).returnType");
        db_function(Fast_InitializerExpr_value_o)->returnsReference = FALSE;
        Fast_InitializerExpr_value_o->virtual = FALSE;
        
        /* Bind Fast_InitializerExpr_value_o with C-function */
        db_function(Fast_InitializerExpr_value_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_InitializerExpr_value(void *args, void *result);
        db_function(Fast_InitializerExpr_value_o)->impl = (db_word)__Fast_InitializerExpr_value;
        if (db_define(Fast_InitializerExpr_value_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::InitializerExpr::value(Expression v)'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::InitializerExpr */
    if (!db_checkState(Fast_InitializerExpr_o, DB_DEFINED)) {
        db_type(Fast_InitializerExpr_o)->defaultType = db_resolve_ext(Fast_InitializerExpr_o, NULL, "::hyve::lang::member", FALSE, "element ::hyve::Fast::InitializerExpr.defaultType");
        db_type(Fast_InitializerExpr_o)->parentType = NULL;
        db_type(Fast_InitializerExpr_o)->parentState = 0x0;
        db_interface(Fast_InitializerExpr_o)->base = db_resolve_ext(Fast_InitializerExpr_o, NULL, "::hyve::Fast::Initializer", FALSE, "element ::hyve::Fast::InitializerExpr.base");
        db_struct(Fast_InitializerExpr_o)->baseAccess = 0x0;
        Fast_InitializerExpr_o->implements.length = 0;
        Fast_InitializerExpr_o->implements.buffer = NULL;
        if (db_define(Fast_InitializerExpr_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::InitializerExpr'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::StaticInitializer::construct(StaticInitializer object) */
    Fast_StaticInitializer_construct_o = db_declare(Fast_StaticInitializer_o, "construct(StaticInitializer object)", db_typedef(db_callback_o));
    if (!Fast_StaticInitializer_construct_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::StaticInitializer::construct(StaticInitializer object)'.");
        goto error;
    }

    /* Define ::hyve::Fast::StaticInitializer::construct(StaticInitializer object) */
    if (!db_checkState(Fast_StaticInitializer_construct_o, DB_DEFINED)) {
        db_function(Fast_StaticInitializer_construct_o)->returnType = db_resolve_ext(Fast_StaticInitializer_construct_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::StaticInitializer::construct(StaticInitializer object).returnType");
        db_function(Fast_StaticInitializer_construct_o)->returnsReference = FALSE;
        Fast_StaticInitializer_construct_o->delegate = db_resolve_ext(Fast_StaticInitializer_construct_o, NULL, "::hyve::lang::class::construct(lang::object object)", FALSE, "element ::hyve::Fast::StaticInitializer::construct(StaticInitializer object).delegate");
        
        /* Bind Fast_StaticInitializer_construct_o with C-function */
        db_function(Fast_StaticInitializer_construct_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_StaticInitializer_construct(void *args, void *result);
        db_function(Fast_StaticInitializer_construct_o)->impl = (db_word)__Fast_StaticInitializer_construct;
        if (db_define(Fast_StaticInitializer_construct_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::StaticInitializer::construct(StaticInitializer object)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::StaticInitializer::define() */
    Fast_StaticInitializer_define_o = db_declare(Fast_StaticInitializer_o, "define()", db_typedef(db_method_o));
    if (!Fast_StaticInitializer_define_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::StaticInitializer::define()'.");
        goto error;
    }

    /* Define ::hyve::Fast::StaticInitializer::define() */
    if (!db_checkState(Fast_StaticInitializer_define_o, DB_DEFINED)) {
        db_function(Fast_StaticInitializer_define_o)->returnType = db_resolve_ext(Fast_StaticInitializer_define_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::StaticInitializer::define().returnType");
        db_function(Fast_StaticInitializer_define_o)->returnsReference = FALSE;
        Fast_StaticInitializer_define_o->virtual = FALSE;
        
        /* Bind Fast_StaticInitializer_define_o with C-function */
        db_function(Fast_StaticInitializer_define_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_StaticInitializer_define(void *args, void *result);
        db_function(Fast_StaticInitializer_define_o)->impl = (db_word)__Fast_StaticInitializer_define;
        if (db_define(Fast_StaticInitializer_define_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::StaticInitializer::define()'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::StaticInitializer::push() */
    Fast_StaticInitializer_push_o = db_declare(Fast_StaticInitializer_o, "push()", db_typedef(db_method_o));
    if (!Fast_StaticInitializer_push_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::StaticInitializer::push()'.");
        goto error;
    }

    /* Define ::hyve::Fast::StaticInitializer::push() */
    if (!db_checkState(Fast_StaticInitializer_push_o, DB_DEFINED)) {
        db_function(Fast_StaticInitializer_push_o)->returnType = db_resolve_ext(Fast_StaticInitializer_push_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::StaticInitializer::push().returnType");
        db_function(Fast_StaticInitializer_push_o)->returnsReference = FALSE;
        Fast_StaticInitializer_push_o->virtual = FALSE;
        
        /* Bind Fast_StaticInitializer_push_o with C-function */
        db_function(Fast_StaticInitializer_push_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_StaticInitializer_push(void *args, void *result);
        db_function(Fast_StaticInitializer_push_o)->impl = (db_word)__Fast_StaticInitializer_push;
        if (db_define(Fast_StaticInitializer_push_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::StaticInitializer::push()'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::StaticInitializer::value(Expression v) */
    Fast_StaticInitializer_value_o = db_declare(Fast_StaticInitializer_o, "value(Expression v)", db_typedef(db_method_o));
    if (!Fast_StaticInitializer_value_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::StaticInitializer::value(Expression v)'.");
        goto error;
    }

    /* Define ::hyve::Fast::StaticInitializer::value(Expression v) */
    if (!db_checkState(Fast_StaticInitializer_value_o, DB_DEFINED)) {
        db_function(Fast_StaticInitializer_value_o)->returnType = db_resolve_ext(Fast_StaticInitializer_value_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::StaticInitializer::value(Expression v).returnType");
        db_function(Fast_StaticInitializer_value_o)->returnsReference = FALSE;
        Fast_StaticInitializer_value_o->virtual = FALSE;
        
        /* Bind Fast_StaticInitializer_value_o with C-function */
        db_function(Fast_StaticInitializer_value_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_StaticInitializer_value(void *args, void *result);
        db_function(Fast_StaticInitializer_value_o)->impl = (db_word)__Fast_StaticInitializer_value;
        if (db_define(Fast_StaticInitializer_value_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::StaticInitializer::value(Expression v)'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::StaticInitializer */
    if (!db_checkState(Fast_StaticInitializer_o, DB_DEFINED)) {
        db_type(Fast_StaticInitializer_o)->defaultType = db_resolve_ext(Fast_StaticInitializer_o, NULL, "::hyve::lang::member", FALSE, "element ::hyve::Fast::StaticInitializer.defaultType");
        db_type(Fast_StaticInitializer_o)->parentType = NULL;
        db_type(Fast_StaticInitializer_o)->parentState = 0x0;
        db_interface(Fast_StaticInitializer_o)->base = db_resolve_ext(Fast_StaticInitializer_o, NULL, "::hyve::Fast::Initializer", FALSE, "element ::hyve::Fast::StaticInitializer.base");
        db_struct(Fast_StaticInitializer_o)->baseAccess = 0x0;
        Fast_StaticInitializer_o->implements.length = 0;
        Fast_StaticInitializer_o->implements.buffer = NULL;
        if (db_define(Fast_StaticInitializer_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::StaticInitializer'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::Parser::initializers */
    if (!db_checkState(Fast_Parser_initializers_o, DB_DEFINED)) {
        Fast_Parser_initializers_o->type = db_resolve_ext(Fast_Parser_initializers_o, NULL, "::hyve::lang::array{::hyve::Fast::Initializer,64,::hyve::Fast::Initializer}", FALSE, "element ::hyve::Fast::Parser::initializers.type");
        Fast_Parser_initializers_o->modifiers = 0x3;
        Fast_Parser_initializers_o->state = 0x6;
        Fast_Parser_initializers_o->weak = FALSE;
        Fast_Parser_initializers_o->id = 26;
        if (db_define(Fast_Parser_initializers_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::initializers'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::InitOper::expr */
    if (!db_checkState(Fast_InitOper_expr_o, DB_DEFINED)) {
        Fast_InitOper_expr_o->type = db_resolve_ext(Fast_InitOper_expr_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::InitOper::expr.type");
        Fast_InitOper_expr_o->modifiers = 0x0;
        Fast_InitOper_expr_o->state = 0x6;
        Fast_InitOper_expr_o->weak = FALSE;
        Fast_InitOper_expr_o->id = 1;
        if (db_define(Fast_InitOper_expr_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::InitOper::expr'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::InitOper */
    if (!db_checkState(Fast_InitOper_o, DB_DEFINED)) {
        db_type(Fast_InitOper_o)->defaultType = db_resolve_ext(Fast_InitOper_o, NULL, "::hyve::lang::member", FALSE, "element ::hyve::Fast::InitOper.defaultType");
        db_type(Fast_InitOper_o)->parentType = NULL;
        db_type(Fast_InitOper_o)->parentState = 0x0;
        db_interface(Fast_InitOper_o)->base = NULL;
        Fast_InitOper_o->baseAccess = 0x0;
        if (db_define(Fast_InitOper_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::InitOper'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Literal::getValue() */
    Fast_Literal_getValue_o = db_declare(Fast_Literal_o, "getValue()", db_typedef(db_virtual_o));
    if (!Fast_Literal_getValue_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Literal::getValue()'.");
        goto error;
    }

    /* Define ::hyve::Fast::Literal::getValue() */
    if (!db_checkState(Fast_Literal_getValue_o, DB_DEFINED)) {
        db_function(Fast_Literal_getValue_o)->returnType = db_resolve_ext(Fast_Literal_getValue_o, NULL, "::hyve::lang::word", FALSE, "element ::hyve::Fast::Literal::getValue().returnType");
        db_function(Fast_Literal_getValue_o)->returnsReference = FALSE;
        db_method(Fast_Literal_getValue_o)->virtual = TRUE;
        
        /* Bind Fast_Literal_getValue_o with C-function */
        db_function(Fast_Literal_getValue_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Literal_getValue_v(void *args, void *result);
        db_function(Fast_Literal_getValue_o)->impl = (db_word)__Fast_Literal_getValue_v;
        if (db_define(Fast_Literal_getValue_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Literal::getValue()'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Literal::init(Literal object) */
    Fast_Literal_init_o = db_declare(Fast_Literal_o, "init(Literal object)", db_typedef(db_callback_o));
    if (!Fast_Literal_init_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Literal::init(Literal object)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Literal::init(Literal object) */
    if (!db_checkState(Fast_Literal_init_o, DB_DEFINED)) {
        db_function(Fast_Literal_init_o)->returnType = db_resolve_ext(Fast_Literal_init_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::Literal::init(Literal object).returnType");
        db_function(Fast_Literal_init_o)->returnsReference = FALSE;
        Fast_Literal_init_o->delegate = db_resolve_ext(Fast_Literal_init_o, NULL, "::hyve::lang::type::init(lang::object object)", FALSE, "element ::hyve::Fast::Literal::init(Literal object).delegate");
        
        /* Bind Fast_Literal_init_o with C-function */
        db_function(Fast_Literal_init_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Literal_init(void *args, void *result);
        db_function(Fast_Literal_init_o)->impl = (db_word)__Fast_Literal_init;
        if (db_define(Fast_Literal_init_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Literal::init(Literal object)'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::Literal */
    if (!db_checkState(Fast_Literal_o, DB_DEFINED)) {
        db_type(Fast_Literal_o)->defaultType = db_resolve_ext(Fast_Literal_o, NULL, "::hyve::lang::member", FALSE, "element ::hyve::Fast::Literal.defaultType");
        db_type(Fast_Literal_o)->parentType = NULL;
        db_type(Fast_Literal_o)->parentState = 0x0;
        db_interface(Fast_Literal_o)->base = db_resolve_ext(Fast_Literal_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::Literal.base");
        db_struct(Fast_Literal_o)->baseAccess = 0x4;
        Fast_Literal_o->implements.length = 0;
        Fast_Literal_o->implements.buffer = NULL;
        if (db_define(Fast_Literal_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Literal'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Boolean::init(Boolean object) */
    Fast_Boolean_init_o = db_declare(Fast_Boolean_o, "init(Boolean object)", db_typedef(db_callback_o));
    if (!Fast_Boolean_init_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Boolean::init(Boolean object)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Boolean::init(Boolean object) */
    if (!db_checkState(Fast_Boolean_init_o, DB_DEFINED)) {
        db_function(Fast_Boolean_init_o)->returnType = db_resolve_ext(Fast_Boolean_init_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::Boolean::init(Boolean object).returnType");
        db_function(Fast_Boolean_init_o)->returnsReference = FALSE;
        Fast_Boolean_init_o->delegate = db_resolve_ext(Fast_Boolean_init_o, NULL, "::hyve::lang::type::init(lang::object object)", FALSE, "element ::hyve::Fast::Boolean::init(Boolean object).delegate");
        
        /* Bind Fast_Boolean_init_o with C-function */
        db_function(Fast_Boolean_init_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Boolean_init(void *args, void *result);
        db_function(Fast_Boolean_init_o)->impl = (db_word)__Fast_Boolean_init;
        if (db_define(Fast_Boolean_init_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Boolean::init(Boolean object)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Boolean::serialize(lang::type dstType,lang::word dst) */
    Fast_Boolean_serialize_o = db_declare(Fast_Boolean_o, "serialize(lang::type dstType,lang::word dst)", db_typedef(db_method_o));
    if (!Fast_Boolean_serialize_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Boolean::serialize(lang::type dstType,lang::word dst)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Boolean::serialize(lang::type dstType,lang::word dst) */
    if (!db_checkState(Fast_Boolean_serialize_o, DB_DEFINED)) {
        db_function(Fast_Boolean_serialize_o)->returnType = db_resolve_ext(Fast_Boolean_serialize_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::Boolean::serialize(lang::type dstType,lang::word dst).returnType");
        db_function(Fast_Boolean_serialize_o)->returnsReference = FALSE;
        Fast_Boolean_serialize_o->virtual = FALSE;
        
        /* Bind Fast_Boolean_serialize_o with C-function */
        db_function(Fast_Boolean_serialize_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Boolean_serialize(void *args, void *result);
        db_function(Fast_Boolean_serialize_o)->impl = (db_word)__Fast_Boolean_serialize;
        if (db_define(Fast_Boolean_serialize_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Boolean::serialize(lang::type dstType,lang::word dst)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Boolean::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
    Fast_Boolean_toIc_o = db_declare(Fast_Boolean_o, "toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)", db_typedef(db_virtual_o));
    if (!Fast_Boolean_toIc_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Boolean::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Boolean::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
    if (!db_checkState(Fast_Boolean_toIc_o, DB_DEFINED)) {
        db_function(Fast_Boolean_toIc_o)->returnType = db_resolve_ext(Fast_Boolean_toIc_o, NULL, "::hyve::lang::alias{\"db_ic\"}", FALSE, "element ::hyve::Fast::Boolean::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored).returnType");
        db_function(Fast_Boolean_toIc_o)->returnsReference = FALSE;
        db_method(Fast_Boolean_toIc_o)->virtual = TRUE;
        
        /* Bind Fast_Boolean_toIc_o with C-function */
        db_function(Fast_Boolean_toIc_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Boolean_toIc_v(void *args, void *result);
        db_function(Fast_Boolean_toIc_o)->impl = (db_word)__Fast_Boolean_toIc_v;
        if (db_define(Fast_Boolean_toIc_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Boolean::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::Boolean */
    if (!db_checkState(Fast_Boolean_o, DB_DEFINED)) {
        db_type(Fast_Boolean_o)->defaultType = db_resolve_ext(Fast_Boolean_o, NULL, "::hyve::lang::member", FALSE, "element ::hyve::Fast::Boolean.defaultType");
        db_type(Fast_Boolean_o)->parentType = NULL;
        db_type(Fast_Boolean_o)->parentState = 0x0;
        db_interface(Fast_Boolean_o)->base = db_resolve_ext(Fast_Boolean_o, NULL, "::hyve::Fast::Literal", FALSE, "element ::hyve::Fast::Boolean.base");
        db_struct(Fast_Boolean_o)->baseAccess = 0x4;
        Fast_Boolean_o->implements.length = 0;
        Fast_Boolean_o->implements.buffer = NULL;
        if (db_define(Fast_Boolean_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Boolean'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Character::init(Character object) */
    Fast_Character_init_o = db_declare(Fast_Character_o, "init(Character object)", db_typedef(db_callback_o));
    if (!Fast_Character_init_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Character::init(Character object)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Character::init(Character object) */
    if (!db_checkState(Fast_Character_init_o, DB_DEFINED)) {
        db_function(Fast_Character_init_o)->returnType = db_resolve_ext(Fast_Character_init_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::Character::init(Character object).returnType");
        db_function(Fast_Character_init_o)->returnsReference = FALSE;
        Fast_Character_init_o->delegate = db_resolve_ext(Fast_Character_init_o, NULL, "::hyve::lang::type::init(lang::object object)", FALSE, "element ::hyve::Fast::Character::init(Character object).delegate");
        
        /* Bind Fast_Character_init_o with C-function */
        db_function(Fast_Character_init_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Character_init(void *args, void *result);
        db_function(Fast_Character_init_o)->impl = (db_word)__Fast_Character_init;
        if (db_define(Fast_Character_init_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Character::init(Character object)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Character::serialize(lang::type dstType,lang::word dst) */
    Fast_Character_serialize_o = db_declare(Fast_Character_o, "serialize(lang::type dstType,lang::word dst)", db_typedef(db_method_o));
    if (!Fast_Character_serialize_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Character::serialize(lang::type dstType,lang::word dst)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Character::serialize(lang::type dstType,lang::word dst) */
    if (!db_checkState(Fast_Character_serialize_o, DB_DEFINED)) {
        db_function(Fast_Character_serialize_o)->returnType = db_resolve_ext(Fast_Character_serialize_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::Character::serialize(lang::type dstType,lang::word dst).returnType");
        db_function(Fast_Character_serialize_o)->returnsReference = FALSE;
        Fast_Character_serialize_o->virtual = FALSE;
        
        /* Bind Fast_Character_serialize_o with C-function */
        db_function(Fast_Character_serialize_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Character_serialize(void *args, void *result);
        db_function(Fast_Character_serialize_o)->impl = (db_word)__Fast_Character_serialize;
        if (db_define(Fast_Character_serialize_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Character::serialize(lang::type dstType,lang::word dst)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Character::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
    Fast_Character_toIc_o = db_declare(Fast_Character_o, "toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)", db_typedef(db_virtual_o));
    if (!Fast_Character_toIc_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Character::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Character::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
    if (!db_checkState(Fast_Character_toIc_o, DB_DEFINED)) {
        db_function(Fast_Character_toIc_o)->returnType = db_resolve_ext(Fast_Character_toIc_o, NULL, "::hyve::lang::alias{\"db_ic\"}", FALSE, "element ::hyve::Fast::Character::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored).returnType");
        db_function(Fast_Character_toIc_o)->returnsReference = FALSE;
        db_method(Fast_Character_toIc_o)->virtual = TRUE;
        
        /* Bind Fast_Character_toIc_o with C-function */
        db_function(Fast_Character_toIc_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Character_toIc_v(void *args, void *result);
        db_function(Fast_Character_toIc_o)->impl = (db_word)__Fast_Character_toIc_v;
        if (db_define(Fast_Character_toIc_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Character::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::Character */
    if (!db_checkState(Fast_Character_o, DB_DEFINED)) {
        db_type(Fast_Character_o)->defaultType = db_resolve_ext(Fast_Character_o, NULL, "::hyve::lang::member", FALSE, "element ::hyve::Fast::Character.defaultType");
        db_type(Fast_Character_o)->parentType = NULL;
        db_type(Fast_Character_o)->parentState = 0x0;
        db_interface(Fast_Character_o)->base = db_resolve_ext(Fast_Character_o, NULL, "::hyve::Fast::Literal", FALSE, "element ::hyve::Fast::Character.base");
        db_struct(Fast_Character_o)->baseAccess = 0x4;
        Fast_Character_o->implements.length = 0;
        Fast_Character_o->implements.buffer = NULL;
        if (db_define(Fast_Character_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Character'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::FloatingPoint::init(FloatingPoint object) */
    Fast_FloatingPoint_init_o = db_declare(Fast_FloatingPoint_o, "init(FloatingPoint object)", db_typedef(db_callback_o));
    if (!Fast_FloatingPoint_init_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::FloatingPoint::init(FloatingPoint object)'.");
        goto error;
    }

    /* Define ::hyve::Fast::FloatingPoint::init(FloatingPoint object) */
    if (!db_checkState(Fast_FloatingPoint_init_o, DB_DEFINED)) {
        db_function(Fast_FloatingPoint_init_o)->returnType = db_resolve_ext(Fast_FloatingPoint_init_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::FloatingPoint::init(FloatingPoint object).returnType");
        db_function(Fast_FloatingPoint_init_o)->returnsReference = FALSE;
        Fast_FloatingPoint_init_o->delegate = db_resolve_ext(Fast_FloatingPoint_init_o, NULL, "::hyve::lang::type::init(lang::object object)", FALSE, "element ::hyve::Fast::FloatingPoint::init(FloatingPoint object).delegate");
        
        /* Bind Fast_FloatingPoint_init_o with C-function */
        db_function(Fast_FloatingPoint_init_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_FloatingPoint_init(void *args, void *result);
        db_function(Fast_FloatingPoint_init_o)->impl = (db_word)__Fast_FloatingPoint_init;
        if (db_define(Fast_FloatingPoint_init_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::FloatingPoint::init(FloatingPoint object)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::FloatingPoint::serialize(lang::type dstType,lang::word dst) */
    Fast_FloatingPoint_serialize_o = db_declare(Fast_FloatingPoint_o, "serialize(lang::type dstType,lang::word dst)", db_typedef(db_method_o));
    if (!Fast_FloatingPoint_serialize_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::FloatingPoint::serialize(lang::type dstType,lang::word dst)'.");
        goto error;
    }

    /* Define ::hyve::Fast::FloatingPoint::serialize(lang::type dstType,lang::word dst) */
    if (!db_checkState(Fast_FloatingPoint_serialize_o, DB_DEFINED)) {
        db_function(Fast_FloatingPoint_serialize_o)->returnType = db_resolve_ext(Fast_FloatingPoint_serialize_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::FloatingPoint::serialize(lang::type dstType,lang::word dst).returnType");
        db_function(Fast_FloatingPoint_serialize_o)->returnsReference = FALSE;
        Fast_FloatingPoint_serialize_o->virtual = FALSE;
        
        /* Bind Fast_FloatingPoint_serialize_o with C-function */
        db_function(Fast_FloatingPoint_serialize_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_FloatingPoint_serialize(void *args, void *result);
        db_function(Fast_FloatingPoint_serialize_o)->impl = (db_word)__Fast_FloatingPoint_serialize;
        if (db_define(Fast_FloatingPoint_serialize_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::FloatingPoint::serialize(lang::type dstType,lang::word dst)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::FloatingPoint::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
    Fast_FloatingPoint_toIc_o = db_declare(Fast_FloatingPoint_o, "toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)", db_typedef(db_virtual_o));
    if (!Fast_FloatingPoint_toIc_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::FloatingPoint::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)'.");
        goto error;
    }

    /* Define ::hyve::Fast::FloatingPoint::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
    if (!db_checkState(Fast_FloatingPoint_toIc_o, DB_DEFINED)) {
        db_function(Fast_FloatingPoint_toIc_o)->returnType = db_resolve_ext(Fast_FloatingPoint_toIc_o, NULL, "::hyve::lang::alias{\"db_ic\"}", FALSE, "element ::hyve::Fast::FloatingPoint::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored).returnType");
        db_function(Fast_FloatingPoint_toIc_o)->returnsReference = FALSE;
        db_method(Fast_FloatingPoint_toIc_o)->virtual = TRUE;
        
        /* Bind Fast_FloatingPoint_toIc_o with C-function */
        db_function(Fast_FloatingPoint_toIc_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_FloatingPoint_toIc_v(void *args, void *result);
        db_function(Fast_FloatingPoint_toIc_o)->impl = (db_word)__Fast_FloatingPoint_toIc_v;
        if (db_define(Fast_FloatingPoint_toIc_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::FloatingPoint::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::FloatingPoint */
    if (!db_checkState(Fast_FloatingPoint_o, DB_DEFINED)) {
        db_type(Fast_FloatingPoint_o)->defaultType = db_resolve_ext(Fast_FloatingPoint_o, NULL, "::hyve::lang::member", FALSE, "element ::hyve::Fast::FloatingPoint.defaultType");
        db_type(Fast_FloatingPoint_o)->parentType = NULL;
        db_type(Fast_FloatingPoint_o)->parentState = 0x0;
        db_interface(Fast_FloatingPoint_o)->base = db_resolve_ext(Fast_FloatingPoint_o, NULL, "::hyve::Fast::Literal", FALSE, "element ::hyve::Fast::FloatingPoint.base");
        db_struct(Fast_FloatingPoint_o)->baseAccess = 0x4;
        Fast_FloatingPoint_o->implements.length = 0;
        Fast_FloatingPoint_o->implements.buffer = NULL;
        if (db_define(Fast_FloatingPoint_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::FloatingPoint'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Integer::init(Integer object) */
    Fast_Integer_init_o = db_declare(Fast_Integer_o, "init(Integer object)", db_typedef(db_callback_o));
    if (!Fast_Integer_init_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Integer::init(Integer object)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Integer::init(Integer object) */
    if (!db_checkState(Fast_Integer_init_o, DB_DEFINED)) {
        db_function(Fast_Integer_init_o)->returnType = db_resolve_ext(Fast_Integer_init_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::Integer::init(Integer object).returnType");
        db_function(Fast_Integer_init_o)->returnsReference = FALSE;
        Fast_Integer_init_o->delegate = db_resolve_ext(Fast_Integer_init_o, NULL, "::hyve::lang::type::init(lang::object object)", FALSE, "element ::hyve::Fast::Integer::init(Integer object).delegate");
        
        /* Bind Fast_Integer_init_o with C-function */
        db_function(Fast_Integer_init_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Integer_init(void *args, void *result);
        db_function(Fast_Integer_init_o)->impl = (db_word)__Fast_Integer_init;
        if (db_define(Fast_Integer_init_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Integer::init(Integer object)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Integer::serialize(lang::type dstType,lang::word dst) */
    Fast_Integer_serialize_o = db_declare(Fast_Integer_o, "serialize(lang::type dstType,lang::word dst)", db_typedef(db_method_o));
    if (!Fast_Integer_serialize_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Integer::serialize(lang::type dstType,lang::word dst)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Integer::serialize(lang::type dstType,lang::word dst) */
    if (!db_checkState(Fast_Integer_serialize_o, DB_DEFINED)) {
        db_function(Fast_Integer_serialize_o)->returnType = db_resolve_ext(Fast_Integer_serialize_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::Integer::serialize(lang::type dstType,lang::word dst).returnType");
        db_function(Fast_Integer_serialize_o)->returnsReference = FALSE;
        Fast_Integer_serialize_o->virtual = FALSE;
        
        /* Bind Fast_Integer_serialize_o with C-function */
        db_function(Fast_Integer_serialize_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Integer_serialize(void *args, void *result);
        db_function(Fast_Integer_serialize_o)->impl = (db_word)__Fast_Integer_serialize;
        if (db_define(Fast_Integer_serialize_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Integer::serialize(lang::type dstType,lang::word dst)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Integer::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
    Fast_Integer_toIc_o = db_declare(Fast_Integer_o, "toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)", db_typedef(db_virtual_o));
    if (!Fast_Integer_toIc_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Integer::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Integer::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
    if (!db_checkState(Fast_Integer_toIc_o, DB_DEFINED)) {
        db_function(Fast_Integer_toIc_o)->returnType = db_resolve_ext(Fast_Integer_toIc_o, NULL, "::hyve::lang::alias{\"db_ic\"}", FALSE, "element ::hyve::Fast::Integer::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored).returnType");
        db_function(Fast_Integer_toIc_o)->returnsReference = FALSE;
        db_method(Fast_Integer_toIc_o)->virtual = TRUE;
        
        /* Bind Fast_Integer_toIc_o with C-function */
        db_function(Fast_Integer_toIc_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Integer_toIc_v(void *args, void *result);
        db_function(Fast_Integer_toIc_o)->impl = (db_word)__Fast_Integer_toIc_v;
        if (db_define(Fast_Integer_toIc_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Integer::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::Integer */
    if (!db_checkState(Fast_Integer_o, DB_DEFINED)) {
        db_type(Fast_Integer_o)->defaultType = db_resolve_ext(Fast_Integer_o, NULL, "::hyve::lang::member", FALSE, "element ::hyve::Fast::Integer.defaultType");
        db_type(Fast_Integer_o)->parentType = NULL;
        db_type(Fast_Integer_o)->parentState = 0x0;
        db_interface(Fast_Integer_o)->base = db_resolve_ext(Fast_Integer_o, NULL, "::hyve::Fast::Literal", FALSE, "element ::hyve::Fast::Integer.base");
        db_struct(Fast_Integer_o)->baseAccess = 0x4;
        Fast_Integer_o->implements.length = 0;
        Fast_Integer_o->implements.buffer = NULL;
        if (db_define(Fast_Integer_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Integer'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::DynamicInitializerFrame::sequenceSize */
    if (!db_checkState(Fast_DynamicInitializerFrame_sequenceSize_o, DB_DEFINED)) {
        Fast_DynamicInitializerFrame_sequenceSize_o->type = db_resolve_ext(Fast_DynamicInitializerFrame_sequenceSize_o, NULL, "::hyve::Fast::Integer", FALSE, "element ::hyve::Fast::DynamicInitializerFrame::sequenceSize.type");
        Fast_DynamicInitializerFrame_sequenceSize_o->modifiers = 0x0;
        Fast_DynamicInitializerFrame_sequenceSize_o->state = 0x6;
        Fast_DynamicInitializerFrame_sequenceSize_o->weak = FALSE;
        Fast_DynamicInitializerFrame_sequenceSize_o->id = 2;
        if (db_define(Fast_DynamicInitializerFrame_sequenceSize_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::DynamicInitializerFrame::sequenceSize'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Null::init(Null object) */
    Fast_Null_init_o = db_declare(Fast_Null_o, "init(Null object)", db_typedef(db_callback_o));
    if (!Fast_Null_init_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Null::init(Null object)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Null::init(Null object) */
    if (!db_checkState(Fast_Null_init_o, DB_DEFINED)) {
        db_function(Fast_Null_init_o)->returnType = db_resolve_ext(Fast_Null_init_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::Null::init(Null object).returnType");
        db_function(Fast_Null_init_o)->returnsReference = FALSE;
        Fast_Null_init_o->delegate = db_resolve_ext(Fast_Null_init_o, NULL, "::hyve::lang::type::init(lang::object object)", FALSE, "element ::hyve::Fast::Null::init(Null object).delegate");
        
        /* Bind Fast_Null_init_o with C-function */
        db_function(Fast_Null_init_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Null_init(void *args, void *result);
        db_function(Fast_Null_init_o)->impl = (db_word)__Fast_Null_init;
        if (db_define(Fast_Null_init_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Null::init(Null object)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Null::serialize(lang::type dstType,lang::word dst) */
    Fast_Null_serialize_o = db_declare(Fast_Null_o, "serialize(lang::type dstType,lang::word dst)", db_typedef(db_method_o));
    if (!Fast_Null_serialize_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Null::serialize(lang::type dstType,lang::word dst)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Null::serialize(lang::type dstType,lang::word dst) */
    if (!db_checkState(Fast_Null_serialize_o, DB_DEFINED)) {
        db_function(Fast_Null_serialize_o)->returnType = db_resolve_ext(Fast_Null_serialize_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::Null::serialize(lang::type dstType,lang::word dst).returnType");
        db_function(Fast_Null_serialize_o)->returnsReference = FALSE;
        Fast_Null_serialize_o->virtual = FALSE;
        
        /* Bind Fast_Null_serialize_o with C-function */
        db_function(Fast_Null_serialize_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Null_serialize(void *args, void *result);
        db_function(Fast_Null_serialize_o)->impl = (db_word)__Fast_Null_serialize;
        if (db_define(Fast_Null_serialize_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Null::serialize(lang::type dstType,lang::word dst)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Null::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
    Fast_Null_toIc_o = db_declare(Fast_Null_o, "toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)", db_typedef(db_virtual_o));
    if (!Fast_Null_toIc_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Null::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Null::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
    if (!db_checkState(Fast_Null_toIc_o, DB_DEFINED)) {
        db_function(Fast_Null_toIc_o)->returnType = db_resolve_ext(Fast_Null_toIc_o, NULL, "::hyve::lang::alias{\"db_ic\"}", FALSE, "element ::hyve::Fast::Null::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored).returnType");
        db_function(Fast_Null_toIc_o)->returnsReference = FALSE;
        db_method(Fast_Null_toIc_o)->virtual = TRUE;
        
        /* Bind Fast_Null_toIc_o with C-function */
        db_function(Fast_Null_toIc_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Null_toIc_v(void *args, void *result);
        db_function(Fast_Null_toIc_o)->impl = (db_word)__Fast_Null_toIc_v;
        if (db_define(Fast_Null_toIc_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Null::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::Null */
    if (!db_checkState(Fast_Null_o, DB_DEFINED)) {
        db_type(Fast_Null_o)->defaultType = db_resolve_ext(Fast_Null_o, NULL, "::hyve::lang::member", FALSE, "element ::hyve::Fast::Null.defaultType");
        db_type(Fast_Null_o)->parentType = NULL;
        db_type(Fast_Null_o)->parentState = 0x0;
        db_interface(Fast_Null_o)->base = db_resolve_ext(Fast_Null_o, NULL, "::hyve::Fast::Literal", FALSE, "element ::hyve::Fast::Null.base");
        db_struct(Fast_Null_o)->baseAccess = 0x4;
        Fast_Null_o->implements.length = 0;
        Fast_Null_o->implements.buffer = NULL;
        if (db_define(Fast_Null_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Null'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::SignedInteger::init(SignedInteger object) */
    Fast_SignedInteger_init_o = db_declare(Fast_SignedInteger_o, "init(SignedInteger object)", db_typedef(db_callback_o));
    if (!Fast_SignedInteger_init_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::SignedInteger::init(SignedInteger object)'.");
        goto error;
    }

    /* Define ::hyve::Fast::SignedInteger::init(SignedInteger object) */
    if (!db_checkState(Fast_SignedInteger_init_o, DB_DEFINED)) {
        db_function(Fast_SignedInteger_init_o)->returnType = db_resolve_ext(Fast_SignedInteger_init_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::SignedInteger::init(SignedInteger object).returnType");
        db_function(Fast_SignedInteger_init_o)->returnsReference = FALSE;
        Fast_SignedInteger_init_o->delegate = db_resolve_ext(Fast_SignedInteger_init_o, NULL, "::hyve::lang::type::init(lang::object object)", FALSE, "element ::hyve::Fast::SignedInteger::init(SignedInteger object).delegate");
        
        /* Bind Fast_SignedInteger_init_o with C-function */
        db_function(Fast_SignedInteger_init_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_SignedInteger_init(void *args, void *result);
        db_function(Fast_SignedInteger_init_o)->impl = (db_word)__Fast_SignedInteger_init;
        if (db_define(Fast_SignedInteger_init_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::SignedInteger::init(SignedInteger object)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::SignedInteger::serialize(lang::type dstType,lang::word dst) */
    Fast_SignedInteger_serialize_o = db_declare(Fast_SignedInteger_o, "serialize(lang::type dstType,lang::word dst)", db_typedef(db_method_o));
    if (!Fast_SignedInteger_serialize_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::SignedInteger::serialize(lang::type dstType,lang::word dst)'.");
        goto error;
    }

    /* Define ::hyve::Fast::SignedInteger::serialize(lang::type dstType,lang::word dst) */
    if (!db_checkState(Fast_SignedInteger_serialize_o, DB_DEFINED)) {
        db_function(Fast_SignedInteger_serialize_o)->returnType = db_resolve_ext(Fast_SignedInteger_serialize_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::SignedInteger::serialize(lang::type dstType,lang::word dst).returnType");
        db_function(Fast_SignedInteger_serialize_o)->returnsReference = FALSE;
        Fast_SignedInteger_serialize_o->virtual = FALSE;
        
        /* Bind Fast_SignedInteger_serialize_o with C-function */
        db_function(Fast_SignedInteger_serialize_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_SignedInteger_serialize(void *args, void *result);
        db_function(Fast_SignedInteger_serialize_o)->impl = (db_word)__Fast_SignedInteger_serialize;
        if (db_define(Fast_SignedInteger_serialize_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::SignedInteger::serialize(lang::type dstType,lang::word dst)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::SignedInteger::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
    Fast_SignedInteger_toIc_o = db_declare(Fast_SignedInteger_o, "toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)", db_typedef(db_virtual_o));
    if (!Fast_SignedInteger_toIc_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::SignedInteger::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)'.");
        goto error;
    }

    /* Define ::hyve::Fast::SignedInteger::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
    if (!db_checkState(Fast_SignedInteger_toIc_o, DB_DEFINED)) {
        db_function(Fast_SignedInteger_toIc_o)->returnType = db_resolve_ext(Fast_SignedInteger_toIc_o, NULL, "::hyve::lang::alias{\"db_ic\"}", FALSE, "element ::hyve::Fast::SignedInteger::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored).returnType");
        db_function(Fast_SignedInteger_toIc_o)->returnsReference = FALSE;
        db_method(Fast_SignedInteger_toIc_o)->virtual = TRUE;
        
        /* Bind Fast_SignedInteger_toIc_o with C-function */
        db_function(Fast_SignedInteger_toIc_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_SignedInteger_toIc_v(void *args, void *result);
        db_function(Fast_SignedInteger_toIc_o)->impl = (db_word)__Fast_SignedInteger_toIc_v;
        if (db_define(Fast_SignedInteger_toIc_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::SignedInteger::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::SignedInteger */
    if (!db_checkState(Fast_SignedInteger_o, DB_DEFINED)) {
        db_type(Fast_SignedInteger_o)->defaultType = db_resolve_ext(Fast_SignedInteger_o, NULL, "::hyve::lang::member", FALSE, "element ::hyve::Fast::SignedInteger.defaultType");
        db_type(Fast_SignedInteger_o)->parentType = NULL;
        db_type(Fast_SignedInteger_o)->parentState = 0x0;
        db_interface(Fast_SignedInteger_o)->base = db_resolve_ext(Fast_SignedInteger_o, NULL, "::hyve::Fast::Literal", FALSE, "element ::hyve::Fast::SignedInteger.base");
        db_struct(Fast_SignedInteger_o)->baseAccess = 0x4;
        Fast_SignedInteger_o->implements.length = 0;
        Fast_SignedInteger_o->implements.buffer = NULL;
        if (db_define(Fast_SignedInteger_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::SignedInteger'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::String::construct(String object) */
    Fast_String_construct_o = db_declare(Fast_String_o, "construct(String object)", db_typedef(db_callback_o));
    if (!Fast_String_construct_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::String::construct(String object)'.");
        goto error;
    }

    /* Define ::hyve::Fast::String::construct(String object) */
    if (!db_checkState(Fast_String_construct_o, DB_DEFINED)) {
        db_function(Fast_String_construct_o)->returnType = db_resolve_ext(Fast_String_construct_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::String::construct(String object).returnType");
        db_function(Fast_String_construct_o)->returnsReference = FALSE;
        Fast_String_construct_o->delegate = db_resolve_ext(Fast_String_construct_o, NULL, "::hyve::lang::class::construct(lang::object object)", FALSE, "element ::hyve::Fast::String::construct(String object).delegate");
        
        /* Bind Fast_String_construct_o with C-function */
        db_function(Fast_String_construct_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_String_construct(void *args, void *result);
        db_function(Fast_String_construct_o)->impl = (db_word)__Fast_String_construct;
        if (db_define(Fast_String_construct_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::String::construct(String object)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::String::getValue() */
    Fast_String_getValue_o = db_declare(Fast_String_o, "getValue()", db_typedef(db_method_o));
    if (!Fast_String_getValue_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::String::getValue()'.");
        goto error;
    }

    /* Define ::hyve::Fast::String::getValue() */
    if (!db_checkState(Fast_String_getValue_o, DB_DEFINED)) {
        db_function(Fast_String_getValue_o)->returnType = db_resolve_ext(Fast_String_getValue_o, NULL, "::hyve::lang::word", FALSE, "element ::hyve::Fast::String::getValue().returnType");
        db_function(Fast_String_getValue_o)->returnsReference = FALSE;
        Fast_String_getValue_o->virtual = FALSE;
        
        /* Bind Fast_String_getValue_o with C-function */
        db_function(Fast_String_getValue_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_String_getValue(void *args, void *result);
        db_function(Fast_String_getValue_o)->impl = (db_word)__Fast_String_getValue;
        if (db_define(Fast_String_getValue_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::String::getValue()'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::String::init(String object) */
    Fast_String_init_o = db_declare(Fast_String_o, "init(String object)", db_typedef(db_callback_o));
    if (!Fast_String_init_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::String::init(String object)'.");
        goto error;
    }

    /* Define ::hyve::Fast::String::init(String object) */
    if (!db_checkState(Fast_String_init_o, DB_DEFINED)) {
        db_function(Fast_String_init_o)->returnType = db_resolve_ext(Fast_String_init_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::String::init(String object).returnType");
        db_function(Fast_String_init_o)->returnsReference = FALSE;
        Fast_String_init_o->delegate = db_resolve_ext(Fast_String_init_o, NULL, "::hyve::lang::type::init(lang::object object)", FALSE, "element ::hyve::Fast::String::init(String object).delegate");
        
        /* Bind Fast_String_init_o with C-function */
        db_function(Fast_String_init_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_String_init(void *args, void *result);
        db_function(Fast_String_init_o)->impl = (db_word)__Fast_String_init;
        if (db_define(Fast_String_init_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::String::init(String object)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::String::serialize(lang::type dstType,lang::word dst) */
    Fast_String_serialize_o = db_declare(Fast_String_o, "serialize(lang::type dstType,lang::word dst)", db_typedef(db_method_o));
    if (!Fast_String_serialize_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::String::serialize(lang::type dstType,lang::word dst)'.");
        goto error;
    }

    /* Define ::hyve::Fast::String::serialize(lang::type dstType,lang::word dst) */
    if (!db_checkState(Fast_String_serialize_o, DB_DEFINED)) {
        db_function(Fast_String_serialize_o)->returnType = db_resolve_ext(Fast_String_serialize_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::String::serialize(lang::type dstType,lang::word dst).returnType");
        db_function(Fast_String_serialize_o)->returnsReference = FALSE;
        Fast_String_serialize_o->virtual = FALSE;
        
        /* Bind Fast_String_serialize_o with C-function */
        db_function(Fast_String_serialize_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_String_serialize(void *args, void *result);
        db_function(Fast_String_serialize_o)->impl = (db_word)__Fast_String_serialize;
        if (db_define(Fast_String_serialize_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::String::serialize(lang::type dstType,lang::word dst)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::String::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
    Fast_String_toIc_o = db_declare(Fast_String_o, "toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)", db_typedef(db_virtual_o));
    if (!Fast_String_toIc_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::String::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)'.");
        goto error;
    }

    /* Define ::hyve::Fast::String::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
    if (!db_checkState(Fast_String_toIc_o, DB_DEFINED)) {
        db_function(Fast_String_toIc_o)->returnType = db_resolve_ext(Fast_String_toIc_o, NULL, "::hyve::lang::alias{\"db_ic\"}", FALSE, "element ::hyve::Fast::String::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored).returnType");
        db_function(Fast_String_toIc_o)->returnsReference = FALSE;
        db_method(Fast_String_toIc_o)->virtual = TRUE;
        
        /* Bind Fast_String_toIc_o with C-function */
        db_function(Fast_String_toIc_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_String_toIc_v(void *args, void *result);
        db_function(Fast_String_toIc_o)->impl = (db_word)__Fast_String_toIc_v;
        if (db_define(Fast_String_toIc_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::String::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::Lvalue::expr */
    if (!db_checkState(Fast_Lvalue_expr_o, DB_DEFINED)) {
        Fast_Lvalue_expr_o->type = db_resolve_ext(Fast_Lvalue_expr_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::Lvalue::expr.type");
        Fast_Lvalue_expr_o->modifiers = 0x0;
        Fast_Lvalue_expr_o->state = 0x6;
        Fast_Lvalue_expr_o->weak = FALSE;
        Fast_Lvalue_expr_o->id = 0;
        if (db_define(Fast_Lvalue_expr_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Lvalue::expr'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::Lvalue */
    if (!db_checkState(Fast_Lvalue_o, DB_DEFINED)) {
        db_type(Fast_Lvalue_o)->defaultType = db_resolve_ext(Fast_Lvalue_o, NULL, "::hyve::lang::member", FALSE, "element ::hyve::Fast::Lvalue.defaultType");
        db_type(Fast_Lvalue_o)->parentType = NULL;
        db_type(Fast_Lvalue_o)->parentState = 0x0;
        db_interface(Fast_Lvalue_o)->base = NULL;
        Fast_Lvalue_o->baseAccess = 0x0;
        if (db_define(Fast_Lvalue_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Lvalue'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::Parser::lvalue */
    if (!db_checkState(Fast_Parser_lvalue_o, DB_DEFINED)) {
        Fast_Parser_lvalue_o->type = db_resolve_ext(Fast_Parser_lvalue_o, NULL, "::hyve::lang::array{::hyve::Fast::Lvalue,64,::hyve::Fast::Lvalue}", FALSE, "element ::hyve::Fast::Parser::lvalue.type");
        Fast_Parser_lvalue_o->modifiers = 0x3;
        Fast_Parser_lvalue_o->state = 0x6;
        Fast_Parser_lvalue_o->weak = FALSE;
        Fast_Parser_lvalue_o->id = 33;
        if (db_define(Fast_Parser_lvalue_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::lvalue'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::MemberExpr::construct(Fast::MemberExpr object) */
    Fast_MemberExpr_construct_o = db_declare(Fast_MemberExpr_o, "construct(Fast::MemberExpr object)", db_typedef(db_callback_o));
    if (!Fast_MemberExpr_construct_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::MemberExpr::construct(Fast::MemberExpr object)'.");
        goto error;
    }

    /* Define ::hyve::Fast::MemberExpr::construct(Fast::MemberExpr object) */
    if (!db_checkState(Fast_MemberExpr_construct_o, DB_DEFINED)) {
        db_function(Fast_MemberExpr_construct_o)->returnType = db_resolve_ext(Fast_MemberExpr_construct_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::MemberExpr::construct(Fast::MemberExpr object).returnType");
        db_function(Fast_MemberExpr_construct_o)->returnsReference = FALSE;
        Fast_MemberExpr_construct_o->delegate = db_resolve_ext(Fast_MemberExpr_construct_o, NULL, "::hyve::lang::class::construct(lang::object object)", FALSE, "element ::hyve::Fast::MemberExpr::construct(Fast::MemberExpr object).delegate");
        
        /* Bind Fast_MemberExpr_construct_o with C-function */
        db_function(Fast_MemberExpr_construct_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_MemberExpr_construct(void *args, void *result);
        db_function(Fast_MemberExpr_construct_o)->impl = (db_word)__Fast_MemberExpr_construct;
        if (db_define(Fast_MemberExpr_construct_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::MemberExpr::construct(Fast::MemberExpr object)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::MemberExpr::hasSideEffects() */
    Fast_MemberExpr_hasSideEffects_o = db_declare(Fast_MemberExpr_o, "hasSideEffects()", db_typedef(db_virtual_o));
    if (!Fast_MemberExpr_hasSideEffects_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::MemberExpr::hasSideEffects()'.");
        goto error;
    }

    /* Define ::hyve::Fast::MemberExpr::hasSideEffects() */
    if (!db_checkState(Fast_MemberExpr_hasSideEffects_o, DB_DEFINED)) {
        db_function(Fast_MemberExpr_hasSideEffects_o)->returnType = db_resolve_ext(Fast_MemberExpr_hasSideEffects_o, NULL, "::hyve::lang::bool", FALSE, "element ::hyve::Fast::MemberExpr::hasSideEffects().returnType");
        db_function(Fast_MemberExpr_hasSideEffects_o)->returnsReference = FALSE;
        db_method(Fast_MemberExpr_hasSideEffects_o)->virtual = TRUE;
        
        /* Bind Fast_MemberExpr_hasSideEffects_o with C-function */
        db_function(Fast_MemberExpr_hasSideEffects_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_MemberExpr_hasSideEffects_v(void *args, void *result);
        db_function(Fast_MemberExpr_hasSideEffects_o)->impl = (db_word)__Fast_MemberExpr_hasSideEffects_v;
        if (db_define(Fast_MemberExpr_hasSideEffects_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::MemberExpr::hasSideEffects()'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::MemberExpr::lvalue */
    if (!db_checkState(Fast_MemberExpr_lvalue_o, DB_DEFINED)) {
        Fast_MemberExpr_lvalue_o->type = db_resolve_ext(Fast_MemberExpr_lvalue_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::MemberExpr::lvalue.type");
        Fast_MemberExpr_lvalue_o->modifiers = 0x0;
        Fast_MemberExpr_lvalue_o->state = 0x6;
        Fast_MemberExpr_lvalue_o->weak = FALSE;
        Fast_MemberExpr_lvalue_o->id = 0;
        if (db_define(Fast_MemberExpr_lvalue_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::MemberExpr::lvalue'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::MemberExpr::rvalue */
    if (!db_checkState(Fast_MemberExpr_rvalue_o, DB_DEFINED)) {
        Fast_MemberExpr_rvalue_o->type = db_resolve_ext(Fast_MemberExpr_rvalue_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::MemberExpr::rvalue.type");
        Fast_MemberExpr_rvalue_o->modifiers = 0x0;
        Fast_MemberExpr_rvalue_o->state = 0x6;
        Fast_MemberExpr_rvalue_o->weak = FALSE;
        Fast_MemberExpr_rvalue_o->id = 1;
        if (db_define(Fast_MemberExpr_rvalue_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::MemberExpr::rvalue'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::MemberExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
    Fast_MemberExpr_toIc_o = db_declare(Fast_MemberExpr_o, "toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)", db_typedef(db_virtual_o));
    if (!Fast_MemberExpr_toIc_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::MemberExpr::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)'.");
        goto error;
    }

    /* Define ::hyve::Fast::MemberExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
    if (!db_checkState(Fast_MemberExpr_toIc_o, DB_DEFINED)) {
        db_function(Fast_MemberExpr_toIc_o)->returnType = db_resolve_ext(Fast_MemberExpr_toIc_o, NULL, "::hyve::lang::alias{\"db_ic\"}", FALSE, "element ::hyve::Fast::MemberExpr::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored).returnType");
        db_function(Fast_MemberExpr_toIc_o)->returnsReference = FALSE;
        db_method(Fast_MemberExpr_toIc_o)->virtual = TRUE;
        
        /* Bind Fast_MemberExpr_toIc_o with C-function */
        db_function(Fast_MemberExpr_toIc_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_MemberExpr_toIc_v(void *args, void *result);
        db_function(Fast_MemberExpr_toIc_o)->impl = (db_word)__Fast_MemberExpr_toIc_v;
        if (db_define(Fast_MemberExpr_toIc_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::MemberExpr::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::MemberExpr */
    if (!db_checkState(Fast_MemberExpr_o, DB_DEFINED)) {
        db_type(Fast_MemberExpr_o)->defaultType = db_resolve_ext(Fast_MemberExpr_o, NULL, "::hyve::lang::member", FALSE, "element ::hyve::Fast::MemberExpr.defaultType");
        db_type(Fast_MemberExpr_o)->parentType = NULL;
        db_type(Fast_MemberExpr_o)->parentState = 0x0;
        db_interface(Fast_MemberExpr_o)->base = db_resolve_ext(Fast_MemberExpr_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::MemberExpr.base");
        db_struct(Fast_MemberExpr_o)->baseAccess = 0x4;
        Fast_MemberExpr_o->implements.length = 0;
        Fast_MemberExpr_o->implements.buffer = NULL;
        if (db_define(Fast_MemberExpr_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::MemberExpr'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::ElementExpr::construct(Fast::MemberExpr object) */
    Fast_ElementExpr_construct_o = db_declare(Fast_ElementExpr_o, "construct(Fast::MemberExpr object)", db_typedef(db_callback_o));
    if (!Fast_ElementExpr_construct_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::ElementExpr::construct(Fast::MemberExpr object)'.");
        goto error;
    }

    /* Define ::hyve::Fast::ElementExpr::construct(Fast::MemberExpr object) */
    if (!db_checkState(Fast_ElementExpr_construct_o, DB_DEFINED)) {
        db_function(Fast_ElementExpr_construct_o)->returnType = db_resolve_ext(Fast_ElementExpr_construct_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::ElementExpr::construct(Fast::MemberExpr object).returnType");
        db_function(Fast_ElementExpr_construct_o)->returnsReference = FALSE;
        Fast_ElementExpr_construct_o->delegate = db_resolve_ext(Fast_ElementExpr_construct_o, NULL, "::hyve::lang::class::construct(lang::object object)", FALSE, "element ::hyve::Fast::ElementExpr::construct(Fast::MemberExpr object).delegate");
        
        /* Bind Fast_ElementExpr_construct_o with C-function */
        db_function(Fast_ElementExpr_construct_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_ElementExpr_construct(void *args, void *result);
        db_function(Fast_ElementExpr_construct_o)->impl = (db_word)__Fast_ElementExpr_construct;
        if (db_define(Fast_ElementExpr_construct_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::ElementExpr::construct(Fast::MemberExpr object)'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::ElementExpr */
    if (!db_checkState(Fast_ElementExpr_o, DB_DEFINED)) {
        db_type(Fast_ElementExpr_o)->defaultType = db_resolve_ext(Fast_ElementExpr_o, NULL, "::hyve::lang::member", FALSE, "element ::hyve::Fast::ElementExpr.defaultType");
        db_type(Fast_ElementExpr_o)->parentType = NULL;
        db_type(Fast_ElementExpr_o)->parentState = 0x0;
        db_interface(Fast_ElementExpr_o)->base = db_resolve_ext(Fast_ElementExpr_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::ElementExpr.base");
        db_struct(Fast_ElementExpr_o)->baseAccess = 0x4;
        Fast_ElementExpr_o->implements.length = 0;
        Fast_ElementExpr_o->implements.buffer = NULL;
        if (db_define(Fast_ElementExpr_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::ElementExpr'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::NewExpr::attributes */
    if (!db_checkState(Fast_NewExpr_attributes_o, DB_DEFINED)) {
        Fast_NewExpr_attributes_o->type = db_resolve_ext(Fast_NewExpr_attributes_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::NewExpr::attributes.type");
        Fast_NewExpr_attributes_o->modifiers = 0x0;
        Fast_NewExpr_attributes_o->state = 0x6;
        Fast_NewExpr_attributes_o->weak = FALSE;
        Fast_NewExpr_attributes_o->id = 1;
        if (db_define(Fast_NewExpr_attributes_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::NewExpr::attributes'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::NewExpr::construct(Fast::NewExpr object) */
    Fast_NewExpr_construct_o = db_declare(Fast_NewExpr_o, "construct(Fast::NewExpr object)", db_typedef(db_callback_o));
    if (!Fast_NewExpr_construct_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::NewExpr::construct(Fast::NewExpr object)'.");
        goto error;
    }

    /* Define ::hyve::Fast::NewExpr::construct(Fast::NewExpr object) */
    if (!db_checkState(Fast_NewExpr_construct_o, DB_DEFINED)) {
        db_function(Fast_NewExpr_construct_o)->returnType = db_resolve_ext(Fast_NewExpr_construct_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::NewExpr::construct(Fast::NewExpr object).returnType");
        db_function(Fast_NewExpr_construct_o)->returnsReference = FALSE;
        Fast_NewExpr_construct_o->delegate = db_resolve_ext(Fast_NewExpr_construct_o, NULL, "::hyve::lang::class::construct(lang::object object)", FALSE, "element ::hyve::Fast::NewExpr::construct(Fast::NewExpr object).delegate");
        
        /* Bind Fast_NewExpr_construct_o with C-function */
        db_function(Fast_NewExpr_construct_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_NewExpr_construct(void *args, void *result);
        db_function(Fast_NewExpr_construct_o)->impl = (db_word)__Fast_NewExpr_construct;
        if (db_define(Fast_NewExpr_construct_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::NewExpr::construct(Fast::NewExpr object)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::NewExpr::hasSideEffects() */
    Fast_NewExpr_hasSideEffects_o = db_declare(Fast_NewExpr_o, "hasSideEffects()", db_typedef(db_virtual_o));
    if (!Fast_NewExpr_hasSideEffects_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::NewExpr::hasSideEffects()'.");
        goto error;
    }

    /* Define ::hyve::Fast::NewExpr::hasSideEffects() */
    if (!db_checkState(Fast_NewExpr_hasSideEffects_o, DB_DEFINED)) {
        db_function(Fast_NewExpr_hasSideEffects_o)->returnType = db_resolve_ext(Fast_NewExpr_hasSideEffects_o, NULL, "::hyve::lang::bool", FALSE, "element ::hyve::Fast::NewExpr::hasSideEffects().returnType");
        db_function(Fast_NewExpr_hasSideEffects_o)->returnsReference = FALSE;
        db_method(Fast_NewExpr_hasSideEffects_o)->virtual = TRUE;
        
        /* Bind Fast_NewExpr_hasSideEffects_o with C-function */
        db_function(Fast_NewExpr_hasSideEffects_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_NewExpr_hasSideEffects_v(void *args, void *result);
        db_function(Fast_NewExpr_hasSideEffects_o)->impl = (db_word)__Fast_NewExpr_hasSideEffects_v;
        if (db_define(Fast_NewExpr_hasSideEffects_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::NewExpr::hasSideEffects()'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::NewExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
    Fast_NewExpr_toIc_o = db_declare(Fast_NewExpr_o, "toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)", db_typedef(db_virtual_o));
    if (!Fast_NewExpr_toIc_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::NewExpr::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)'.");
        goto error;
    }

    /* Define ::hyve::Fast::NewExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
    if (!db_checkState(Fast_NewExpr_toIc_o, DB_DEFINED)) {
        db_function(Fast_NewExpr_toIc_o)->returnType = db_resolve_ext(Fast_NewExpr_toIc_o, NULL, "::hyve::lang::alias{\"db_ic\"}", FALSE, "element ::hyve::Fast::NewExpr::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored).returnType");
        db_function(Fast_NewExpr_toIc_o)->returnsReference = FALSE;
        db_method(Fast_NewExpr_toIc_o)->virtual = TRUE;
        
        /* Bind Fast_NewExpr_toIc_o with C-function */
        db_function(Fast_NewExpr_toIc_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_NewExpr_toIc_v(void *args, void *result);
        db_function(Fast_NewExpr_toIc_o)->impl = (db_word)__Fast_NewExpr_toIc_v;
        if (db_define(Fast_NewExpr_toIc_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::NewExpr::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::NewExpr::type */
    if (!db_checkState(Fast_NewExpr_type_o, DB_DEFINED)) {
        Fast_NewExpr_type_o->type = db_resolve_ext(Fast_NewExpr_type_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::NewExpr::type.type");
        Fast_NewExpr_type_o->modifiers = 0x0;
        Fast_NewExpr_type_o->state = 0x6;
        Fast_NewExpr_type_o->weak = FALSE;
        Fast_NewExpr_type_o->id = 0;
        if (db_define(Fast_NewExpr_type_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::NewExpr::type'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::NewExpr */
    if (!db_checkState(Fast_NewExpr_o, DB_DEFINED)) {
        db_type(Fast_NewExpr_o)->defaultType = db_resolve_ext(Fast_NewExpr_o, NULL, "::hyve::lang::member", FALSE, "element ::hyve::Fast::NewExpr.defaultType");
        db_type(Fast_NewExpr_o)->parentType = NULL;
        db_type(Fast_NewExpr_o)->parentState = 0x0;
        db_interface(Fast_NewExpr_o)->base = db_resolve_ext(Fast_NewExpr_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::NewExpr.base");
        db_struct(Fast_NewExpr_o)->baseAccess = 0x4;
        Fast_NewExpr_o->implements.length = 0;
        Fast_NewExpr_o->implements.buffer = NULL;
        if (db_define(Fast_NewExpr_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::NewExpr'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::binaryExpr(Fast::Expression lvalues,Fast::Expression rvalues,lang::operatorKind operator) */
    Fast_Parser_binaryExpr_o = db_declare(Fast_Parser_o, "binaryExpr(Fast::Expression lvalues,Fast::Expression rvalues,lang::operatorKind operator)", db_typedef(db_method_o));
    if (!Fast_Parser_binaryExpr_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::binaryExpr(Fast::Expression lvalues,Fast::Expression rvalues,lang::operatorKind operator)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::binaryExpr(Fast::Expression lvalues,Fast::Expression rvalues,lang::operatorKind operator) */
    if (!db_checkState(Fast_Parser_binaryExpr_o, DB_DEFINED)) {
        db_function(Fast_Parser_binaryExpr_o)->returnType = db_resolve_ext(Fast_Parser_binaryExpr_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::Parser::binaryExpr(Fast::Expression lvalues,Fast::Expression rvalues,lang::operatorKind operator).returnType");
        db_function(Fast_Parser_binaryExpr_o)->returnsReference = FALSE;
        Fast_Parser_binaryExpr_o->virtual = FALSE;
        
        /* Bind Fast_Parser_binaryExpr_o with C-function */
        db_function(Fast_Parser_binaryExpr_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Parser_binaryExpr(void *args, void *result);
        db_function(Fast_Parser_binaryExpr_o)->impl = (db_word)__Fast_Parser_binaryExpr;
        if (db_define(Fast_Parser_binaryExpr_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::binaryExpr(Fast::Expression lvalues,Fast::Expression rvalues,lang::operatorKind operator)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::callExpr(Fast::Expression function,Fast::Expression arguments) */
    Fast_Parser_callExpr_o = db_declare(Fast_Parser_o, "callExpr(Fast::Expression function,Fast::Expression arguments)", db_typedef(db_method_o));
    if (!Fast_Parser_callExpr_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::callExpr(Fast::Expression function,Fast::Expression arguments)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::callExpr(Fast::Expression function,Fast::Expression arguments) */
    if (!db_checkState(Fast_Parser_callExpr_o, DB_DEFINED)) {
        db_function(Fast_Parser_callExpr_o)->returnType = db_resolve_ext(Fast_Parser_callExpr_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::Parser::callExpr(Fast::Expression function,Fast::Expression arguments).returnType");
        db_function(Fast_Parser_callExpr_o)->returnsReference = FALSE;
        Fast_Parser_callExpr_o->virtual = FALSE;
        
        /* Bind Fast_Parser_callExpr_o with C-function */
        db_function(Fast_Parser_callExpr_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Parser_callExpr(void *args, void *result);
        db_function(Fast_Parser_callExpr_o)->impl = (db_word)__Fast_Parser_callExpr;
        if (db_define(Fast_Parser_callExpr_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::callExpr(Fast::Expression function,Fast::Expression arguments)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::castExpr(Fast::Expression lvalue,Fast::Expression rvalue) */
    Fast_Parser_castExpr_o = db_declare(Fast_Parser_o, "castExpr(Fast::Expression lvalue,Fast::Expression rvalue)", db_typedef(db_method_o));
    if (!Fast_Parser_castExpr_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::castExpr(Fast::Expression lvalue,Fast::Expression rvalue)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::castExpr(Fast::Expression lvalue,Fast::Expression rvalue) */
    if (!db_checkState(Fast_Parser_castExpr_o, DB_DEFINED)) {
        db_function(Fast_Parser_castExpr_o)->returnType = db_resolve_ext(Fast_Parser_castExpr_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::Parser::castExpr(Fast::Expression lvalue,Fast::Expression rvalue).returnType");
        db_function(Fast_Parser_castExpr_o)->returnsReference = FALSE;
        Fast_Parser_castExpr_o->virtual = FALSE;
        
        /* Bind Fast_Parser_castExpr_o with C-function */
        db_function(Fast_Parser_castExpr_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Parser_castExpr(void *args, void *result);
        db_function(Fast_Parser_castExpr_o)->impl = (db_word)__Fast_Parser_castExpr;
        if (db_define(Fast_Parser_castExpr_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::castExpr(Fast::Expression lvalue,Fast::Expression rvalue)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::elementExpr(Fast::Expression lvalue,Fast::Expression rvalue) */
    Fast_Parser_elementExpr_o = db_declare(Fast_Parser_o, "elementExpr(Fast::Expression lvalue,Fast::Expression rvalue)", db_typedef(db_method_o));
    if (!Fast_Parser_elementExpr_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::elementExpr(Fast::Expression lvalue,Fast::Expression rvalue)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::elementExpr(Fast::Expression lvalue,Fast::Expression rvalue) */
    if (!db_checkState(Fast_Parser_elementExpr_o, DB_DEFINED)) {
        db_function(Fast_Parser_elementExpr_o)->returnType = db_resolve_ext(Fast_Parser_elementExpr_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::Parser::elementExpr(Fast::Expression lvalue,Fast::Expression rvalue).returnType");
        db_function(Fast_Parser_elementExpr_o)->returnsReference = FALSE;
        Fast_Parser_elementExpr_o->virtual = FALSE;
        
        /* Bind Fast_Parser_elementExpr_o with C-function */
        db_function(Fast_Parser_elementExpr_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Parser_elementExpr(void *args, void *result);
        db_function(Fast_Parser_elementExpr_o)->impl = (db_word)__Fast_Parser_elementExpr;
        if (db_define(Fast_Parser_elementExpr_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::elementExpr(Fast::Expression lvalue,Fast::Expression rvalue)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::foreach(lang::string loopId,Fast::Expression collection) */
    Fast_Parser_foreach_o = db_declare(Fast_Parser_o, "foreach(lang::string loopId,Fast::Expression collection)", db_typedef(db_method_o));
    if (!Fast_Parser_foreach_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::foreach(lang::string loopId,Fast::Expression collection)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::foreach(lang::string loopId,Fast::Expression collection) */
    if (!db_checkState(Fast_Parser_foreach_o, DB_DEFINED)) {
        db_function(Fast_Parser_foreach_o)->returnType = db_resolve_ext(Fast_Parser_foreach_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::Parser::foreach(lang::string loopId,Fast::Expression collection).returnType");
        db_function(Fast_Parser_foreach_o)->returnsReference = FALSE;
        Fast_Parser_foreach_o->virtual = FALSE;
        
        /* Bind Fast_Parser_foreach_o with C-function */
        db_function(Fast_Parser_foreach_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Parser_foreach(void *args, void *result);
        db_function(Fast_Parser_foreach_o)->impl = (db_word)__Fast_Parser_foreach;
        if (db_define(Fast_Parser_foreach_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::foreach(lang::string loopId,Fast::Expression collection)'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::Parser::getLvalue(lang::bool assignment) */
    if (!db_checkState(Fast_Parser_getLvalue_o, DB_DEFINED)) {
        db_function(Fast_Parser_getLvalue_o)->returnType = db_resolve_ext(Fast_Parser_getLvalue_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::Parser::getLvalue(lang::bool assignment).returnType");
        db_function(Fast_Parser_getLvalue_o)->returnsReference = FALSE;
        Fast_Parser_getLvalue_o->virtual = FALSE;
        
        /* Bind Fast_Parser_getLvalue_o with C-function */
        db_function(Fast_Parser_getLvalue_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Parser_getLvalue(void *args, void *result);
        db_function(Fast_Parser_getLvalue_o)->impl = (db_word)__Fast_Parser_getLvalue;
        if (db_define(Fast_Parser_getLvalue_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::getLvalue(lang::bool assignment)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::initDeclareStaged(Fast::Expression expr) */
    Fast_Parser_initDeclareStaged_o = db_declare(Fast_Parser_o, "initDeclareStaged(Fast::Expression expr)", db_typedef(db_method_o));
    if (!Fast_Parser_initDeclareStaged_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::initDeclareStaged(Fast::Expression expr)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::initDeclareStaged(Fast::Expression expr) */
    if (!db_checkState(Fast_Parser_initDeclareStaged_o, DB_DEFINED)) {
        db_function(Fast_Parser_initDeclareStaged_o)->returnType = NULL;
        db_function(Fast_Parser_initDeclareStaged_o)->returnsReference = FALSE;
        Fast_Parser_initDeclareStaged_o->virtual = FALSE;
        
        /* Bind Fast_Parser_initDeclareStaged_o with C-function */
        db_function(Fast_Parser_initDeclareStaged_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Parser_initDeclareStaged(void *args, void *result);
        db_function(Fast_Parser_initDeclareStaged_o)->impl = (db_word)__Fast_Parser_initDeclareStaged;
        if (db_define(Fast_Parser_initDeclareStaged_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::initDeclareStaged(Fast::Expression expr)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::initKeyValueSet(Fast::Expression expr) */
    Fast_Parser_initKeyValueSet_o = db_declare(Fast_Parser_o, "initKeyValueSet(Fast::Expression expr)", db_typedef(db_method_o));
    if (!Fast_Parser_initKeyValueSet_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::initKeyValueSet(Fast::Expression expr)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::initKeyValueSet(Fast::Expression expr) */
    if (!db_checkState(Fast_Parser_initKeyValueSet_o, DB_DEFINED)) {
        db_function(Fast_Parser_initKeyValueSet_o)->returnType = db_resolve_ext(Fast_Parser_initKeyValueSet_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::Parser::initKeyValueSet(Fast::Expression expr).returnType");
        db_function(Fast_Parser_initKeyValueSet_o)->returnsReference = FALSE;
        Fast_Parser_initKeyValueSet_o->virtual = FALSE;
        
        /* Bind Fast_Parser_initKeyValueSet_o with C-function */
        db_function(Fast_Parser_initKeyValueSet_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Parser_initKeyValueSet(void *args, void *result);
        db_function(Fast_Parser_initKeyValueSet_o)->impl = (db_word)__Fast_Parser_initKeyValueSet;
        if (db_define(Fast_Parser_initKeyValueSet_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::initKeyValueSet(Fast::Expression expr)'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::Parser::initPushExpression() */
    if (!db_checkState(Fast_Parser_initPushExpression_o, DB_DEFINED)) {
        db_function(Fast_Parser_initPushExpression_o)->returnType = db_resolve_ext(Fast_Parser_initPushExpression_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::Parser::initPushExpression().returnType");
        db_function(Fast_Parser_initPushExpression_o)->returnsReference = FALSE;
        Fast_Parser_initPushExpression_o->virtual = FALSE;
        
        /* Bind Fast_Parser_initPushExpression_o with C-function */
        db_function(Fast_Parser_initPushExpression_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Parser_initPushExpression(void *args, void *result);
        db_function(Fast_Parser_initPushExpression_o)->impl = (db_word)__Fast_Parser_initPushExpression;
        if (db_define(Fast_Parser_initPushExpression_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::initPushExpression()'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::initPushIdentifier(Expression type) */
    Fast_Parser_initPushIdentifier_o = db_declare(Fast_Parser_o, "initPushIdentifier(Expression type)", db_typedef(db_method_o));
    if (!Fast_Parser_initPushIdentifier_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::initPushIdentifier(Expression type)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::initPushIdentifier(Expression type) */
    if (!db_checkState(Fast_Parser_initPushIdentifier_o, DB_DEFINED)) {
        db_function(Fast_Parser_initPushIdentifier_o)->returnType = db_resolve_ext(Fast_Parser_initPushIdentifier_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::Parser::initPushIdentifier(Expression type).returnType");
        db_function(Fast_Parser_initPushIdentifier_o)->returnsReference = FALSE;
        Fast_Parser_initPushIdentifier_o->virtual = FALSE;
        
        /* Bind Fast_Parser_initPushIdentifier_o with C-function */
        db_function(Fast_Parser_initPushIdentifier_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Parser_initPushIdentifier(void *args, void *result);
        db_function(Fast_Parser_initPushIdentifier_o)->impl = (db_word)__Fast_Parser_initPushIdentifier;
        if (db_define(Fast_Parser_initPushIdentifier_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::initPushIdentifier(Expression type)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::initValue(Expression expr) */
    Fast_Parser_initValue_o = db_declare(Fast_Parser_o, "initValue(Expression expr)", db_typedef(db_method_o));
    if (!Fast_Parser_initValue_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::initValue(Expression expr)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::initValue(Expression expr) */
    if (!db_checkState(Fast_Parser_initValue_o, DB_DEFINED)) {
        db_function(Fast_Parser_initValue_o)->returnType = db_resolve_ext(Fast_Parser_initValue_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::Parser::initValue(Expression expr).returnType");
        db_function(Fast_Parser_initValue_o)->returnsReference = FALSE;
        Fast_Parser_initValue_o->virtual = FALSE;
        
        /* Bind Fast_Parser_initValue_o with C-function */
        db_function(Fast_Parser_initValue_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Parser_initValue(void *args, void *result);
        db_function(Fast_Parser_initValue_o)->impl = (db_word)__Fast_Parser_initValue;
        if (db_define(Fast_Parser_initValue_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::initValue(Expression expr)'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::Parser::lookup(lang::string id,lang::object source) */
    if (!db_checkState(Fast_Parser_lookup_o, DB_DEFINED)) {
        db_function(Fast_Parser_lookup_o)->returnType = db_resolve_ext(Fast_Parser_lookup_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::Parser::lookup(lang::string id,lang::object source).returnType");
        db_function(Fast_Parser_lookup_o)->returnsReference = FALSE;
        Fast_Parser_lookup_o->virtual = FALSE;
        
        /* Bind Fast_Parser_lookup_o with C-function */
        db_function(Fast_Parser_lookup_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Parser_lookup(void *args, void *result);
        db_function(Fast_Parser_lookup_o)->impl = (db_word)__Fast_Parser_lookup;
        if (db_define(Fast_Parser_lookup_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::lookup(lang::string id,lang::object source)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::memberExpr(Fast::Expression lvalue,Fast::Expression rvalue) */
    Fast_Parser_memberExpr_o = db_declare(Fast_Parser_o, "memberExpr(Fast::Expression lvalue,Fast::Expression rvalue)", db_typedef(db_method_o));
    if (!Fast_Parser_memberExpr_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::memberExpr(Fast::Expression lvalue,Fast::Expression rvalue)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::memberExpr(Fast::Expression lvalue,Fast::Expression rvalue) */
    if (!db_checkState(Fast_Parser_memberExpr_o, DB_DEFINED)) {
        db_function(Fast_Parser_memberExpr_o)->returnType = db_resolve_ext(Fast_Parser_memberExpr_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::Parser::memberExpr(Fast::Expression lvalue,Fast::Expression rvalue).returnType");
        db_function(Fast_Parser_memberExpr_o)->returnsReference = FALSE;
        Fast_Parser_memberExpr_o->virtual = FALSE;
        
        /* Bind Fast_Parser_memberExpr_o with C-function */
        db_function(Fast_Parser_memberExpr_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Parser_memberExpr(void *args, void *result);
        db_function(Fast_Parser_memberExpr_o)->impl = (db_word)__Fast_Parser_memberExpr;
        if (db_define(Fast_Parser_memberExpr_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::memberExpr(Fast::Expression lvalue,Fast::Expression rvalue)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::postfixExpr(Fast::Expression lvalue,lang::operatorKind operator) */
    Fast_Parser_postfixExpr_o = db_declare(Fast_Parser_o, "postfixExpr(Fast::Expression lvalue,lang::operatorKind operator)", db_typedef(db_method_o));
    if (!Fast_Parser_postfixExpr_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::postfixExpr(Fast::Expression lvalue,lang::operatorKind operator)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::postfixExpr(Fast::Expression lvalue,lang::operatorKind operator) */
    if (!db_checkState(Fast_Parser_postfixExpr_o, DB_DEFINED)) {
        db_function(Fast_Parser_postfixExpr_o)->returnType = db_resolve_ext(Fast_Parser_postfixExpr_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::Parser::postfixExpr(Fast::Expression lvalue,lang::operatorKind operator).returnType");
        db_function(Fast_Parser_postfixExpr_o)->returnsReference = FALSE;
        Fast_Parser_postfixExpr_o->virtual = FALSE;
        
        /* Bind Fast_Parser_postfixExpr_o with C-function */
        db_function(Fast_Parser_postfixExpr_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Parser_postfixExpr(void *args, void *result);
        db_function(Fast_Parser_postfixExpr_o)->impl = (db_word)__Fast_Parser_postfixExpr;
        if (db_define(Fast_Parser_postfixExpr_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::postfixExpr(Fast::Expression lvalue,lang::operatorKind operator)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::pushComplexType(Fast::Expression lvalue) */
    Fast_Parser_pushComplexType_o = db_declare(Fast_Parser_o, "pushComplexType(Fast::Expression lvalue)", db_typedef(db_method_o));
    if (!Fast_Parser_pushComplexType_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::pushComplexType(Fast::Expression lvalue)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::pushComplexType(Fast::Expression lvalue) */
    if (!db_checkState(Fast_Parser_pushComplexType_o, DB_DEFINED)) {
        db_function(Fast_Parser_pushComplexType_o)->returnType = NULL;
        db_function(Fast_Parser_pushComplexType_o)->returnsReference = FALSE;
        Fast_Parser_pushComplexType_o->virtual = FALSE;
        
        /* Bind Fast_Parser_pushComplexType_o with C-function */
        db_function(Fast_Parser_pushComplexType_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Parser_pushComplexType(void *args, void *result);
        db_function(Fast_Parser_pushComplexType_o)->impl = (db_word)__Fast_Parser_pushComplexType;
        if (db_define(Fast_Parser_pushComplexType_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::pushComplexType(Fast::Expression lvalue)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::pushLvalue(Fast::Expression lvalue,lang::bool isAssignment) */
    Fast_Parser_pushLvalue_o = db_declare(Fast_Parser_o, "pushLvalue(Fast::Expression lvalue,lang::bool isAssignment)", db_typedef(db_method_o));
    if (!Fast_Parser_pushLvalue_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::pushLvalue(Fast::Expression lvalue,lang::bool isAssignment)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::pushLvalue(Fast::Expression lvalue,lang::bool isAssignment) */
    if (!db_checkState(Fast_Parser_pushLvalue_o, DB_DEFINED)) {
        db_function(Fast_Parser_pushLvalue_o)->returnType = NULL;
        db_function(Fast_Parser_pushLvalue_o)->returnsReference = FALSE;
        Fast_Parser_pushLvalue_o->virtual = FALSE;
        
        /* Bind Fast_Parser_pushLvalue_o with C-function */
        db_function(Fast_Parser_pushLvalue_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Parser_pushLvalue(void *args, void *result);
        db_function(Fast_Parser_pushLvalue_o)->impl = (db_word)__Fast_Parser_pushLvalue;
        if (db_define(Fast_Parser_pushLvalue_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::pushLvalue(Fast::Expression lvalue,lang::bool isAssignment)'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::Parser::singleExpr */
    if (!db_checkState(Fast_Parser_singleExpr_o, DB_DEFINED)) {
        Fast_Parser_singleExpr_o->type = db_resolve_ext(Fast_Parser_singleExpr_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::Parser::singleExpr.type");
        Fast_Parser_singleExpr_o->modifiers = 0x3;
        Fast_Parser_singleExpr_o->state = 0x6;
        Fast_Parser_singleExpr_o->weak = FALSE;
        Fast_Parser_singleExpr_o->id = 20;
        if (db_define(Fast_Parser_singleExpr_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::singleExpr'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::ternaryExpr(Fast::Expression cond,Fast::Expression iftrue,Fast::Expression iffalse) */
    Fast_Parser_ternaryExpr_o = db_declare(Fast_Parser_o, "ternaryExpr(Fast::Expression cond,Fast::Expression iftrue,Fast::Expression iffalse)", db_typedef(db_method_o));
    if (!Fast_Parser_ternaryExpr_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::ternaryExpr(Fast::Expression cond,Fast::Expression iftrue,Fast::Expression iffalse)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::ternaryExpr(Fast::Expression cond,Fast::Expression iftrue,Fast::Expression iffalse) */
    if (!db_checkState(Fast_Parser_ternaryExpr_o, DB_DEFINED)) {
        db_function(Fast_Parser_ternaryExpr_o)->returnType = db_resolve_ext(Fast_Parser_ternaryExpr_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::Parser::ternaryExpr(Fast::Expression cond,Fast::Expression iftrue,Fast::Expression iffalse).returnType");
        db_function(Fast_Parser_ternaryExpr_o)->returnsReference = FALSE;
        Fast_Parser_ternaryExpr_o->virtual = FALSE;
        
        /* Bind Fast_Parser_ternaryExpr_o with C-function */
        db_function(Fast_Parser_ternaryExpr_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Parser_ternaryExpr(void *args, void *result);
        db_function(Fast_Parser_ternaryExpr_o)->impl = (db_word)__Fast_Parser_ternaryExpr;
        if (db_define(Fast_Parser_ternaryExpr_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::ternaryExpr(Fast::Expression cond,Fast::Expression iftrue,Fast::Expression iffalse)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::unaryExpr(Fast::Expression lvalue,lang::operatorKind operator) */
    Fast_Parser_unaryExpr_o = db_declare(Fast_Parser_o, "unaryExpr(Fast::Expression lvalue,lang::operatorKind operator)", db_typedef(db_method_o));
    if (!Fast_Parser_unaryExpr_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::unaryExpr(Fast::Expression lvalue,lang::operatorKind operator)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::unaryExpr(Fast::Expression lvalue,lang::operatorKind operator) */
    if (!db_checkState(Fast_Parser_unaryExpr_o, DB_DEFINED)) {
        db_function(Fast_Parser_unaryExpr_o)->returnType = db_resolve_ext(Fast_Parser_unaryExpr_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::Parser::unaryExpr(Fast::Expression lvalue,lang::operatorKind operator).returnType");
        db_function(Fast_Parser_unaryExpr_o)->returnsReference = FALSE;
        Fast_Parser_unaryExpr_o->virtual = FALSE;
        
        /* Bind Fast_Parser_unaryExpr_o with C-function */
        db_function(Fast_Parser_unaryExpr_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Parser_unaryExpr(void *args, void *result);
        db_function(Fast_Parser_unaryExpr_o)->impl = (db_word)__Fast_Parser_unaryExpr;
        if (db_define(Fast_Parser_unaryExpr_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::unaryExpr(Fast::Expression lvalue,lang::operatorKind operator)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::waitExpr(list{Fast::Expression} exprList,Fast::Expression timeout) */
    Fast_Parser_waitExpr_o = db_declare(Fast_Parser_o, "waitExpr(list{Fast::Expression} exprList,Fast::Expression timeout)", db_typedef(db_method_o));
    if (!Fast_Parser_waitExpr_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::waitExpr(list{Fast::Expression} exprList,Fast::Expression timeout)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::waitExpr(list{Fast::Expression} exprList,Fast::Expression timeout) */
    if (!db_checkState(Fast_Parser_waitExpr_o, DB_DEFINED)) {
        db_function(Fast_Parser_waitExpr_o)->returnType = db_resolve_ext(Fast_Parser_waitExpr_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::Parser::waitExpr(list{Fast::Expression} exprList,Fast::Expression timeout).returnType");
        db_function(Fast_Parser_waitExpr_o)->returnsReference = FALSE;
        Fast_Parser_waitExpr_o->virtual = FALSE;
        
        /* Bind Fast_Parser_waitExpr_o with C-function */
        db_function(Fast_Parser_waitExpr_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Parser_waitExpr(void *args, void *result);
        db_function(Fast_Parser_waitExpr_o)->impl = (db_word)__Fast_Parser_waitExpr;
        if (db_define(Fast_Parser_waitExpr_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::waitExpr(list{Fast::Expression} exprList,Fast::Expression timeout)'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::ParserNew::attr */
    if (!db_checkState(Fast_ParserNew_attr_o, DB_DEFINED)) {
        Fast_ParserNew_attr_o->type = db_resolve_ext(Fast_ParserNew_attr_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::ParserNew::attr.type");
        Fast_ParserNew_attr_o->modifiers = 0x0;
        Fast_ParserNew_attr_o->state = 0x6;
        Fast_ParserNew_attr_o->weak = FALSE;
        Fast_ParserNew_attr_o->id = 3;
        if (db_define(Fast_ParserNew_attr_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::ParserNew::attr'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::ParserNew::name */
    if (!db_checkState(Fast_ParserNew_name_o, DB_DEFINED)) {
        Fast_ParserNew_name_o->type = db_resolve_ext(Fast_ParserNew_name_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::ParserNew::name.type");
        Fast_ParserNew_name_o->modifiers = 0x0;
        Fast_ParserNew_name_o->state = 0x6;
        Fast_ParserNew_name_o->weak = FALSE;
        Fast_ParserNew_name_o->id = 2;
        if (db_define(Fast_ParserNew_name_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::ParserNew::name'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::ParserNew::parent */
    if (!db_checkState(Fast_ParserNew_parent_o, DB_DEFINED)) {
        Fast_ParserNew_parent_o->type = db_resolve_ext(Fast_ParserNew_parent_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::ParserNew::parent.type");
        Fast_ParserNew_parent_o->modifiers = 0x0;
        Fast_ParserNew_parent_o->state = 0x6;
        Fast_ParserNew_parent_o->weak = FALSE;
        Fast_ParserNew_parent_o->id = 1;
        if (db_define(Fast_ParserNew_parent_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::ParserNew::parent'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::ParserNew */
    if (!db_checkState(Fast_ParserNew_o, DB_DEFINED)) {
        db_type(Fast_ParserNew_o)->defaultType = db_resolve_ext(Fast_ParserNew_o, NULL, "::hyve::lang::member", FALSE, "element ::hyve::Fast::ParserNew.defaultType");
        db_type(Fast_ParserNew_o)->parentType = NULL;
        db_type(Fast_ParserNew_o)->parentState = 0x0;
        db_interface(Fast_ParserNew_o)->base = NULL;
        Fast_ParserNew_o->baseAccess = 0x0;
        if (db_define(Fast_ParserNew_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::ParserNew'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::PostfixExpr::construct(Fast::PostfixExpr object) */
    Fast_PostfixExpr_construct_o = db_declare(Fast_PostfixExpr_o, "construct(Fast::PostfixExpr object)", db_typedef(db_callback_o));
    if (!Fast_PostfixExpr_construct_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::PostfixExpr::construct(Fast::PostfixExpr object)'.");
        goto error;
    }

    /* Define ::hyve::Fast::PostfixExpr::construct(Fast::PostfixExpr object) */
    if (!db_checkState(Fast_PostfixExpr_construct_o, DB_DEFINED)) {
        db_function(Fast_PostfixExpr_construct_o)->returnType = db_resolve_ext(Fast_PostfixExpr_construct_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::PostfixExpr::construct(Fast::PostfixExpr object).returnType");
        db_function(Fast_PostfixExpr_construct_o)->returnsReference = FALSE;
        Fast_PostfixExpr_construct_o->delegate = db_resolve_ext(Fast_PostfixExpr_construct_o, NULL, "::hyve::lang::class::construct(lang::object object)", FALSE, "element ::hyve::Fast::PostfixExpr::construct(Fast::PostfixExpr object).delegate");
        
        /* Bind Fast_PostfixExpr_construct_o with C-function */
        db_function(Fast_PostfixExpr_construct_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_PostfixExpr_construct(void *args, void *result);
        db_function(Fast_PostfixExpr_construct_o)->impl = (db_word)__Fast_PostfixExpr_construct;
        if (db_define(Fast_PostfixExpr_construct_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::PostfixExpr::construct(Fast::PostfixExpr object)'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::PostfixExpr::lvalue */
    if (!db_checkState(Fast_PostfixExpr_lvalue_o, DB_DEFINED)) {
        Fast_PostfixExpr_lvalue_o->type = db_resolve_ext(Fast_PostfixExpr_lvalue_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::PostfixExpr::lvalue.type");
        Fast_PostfixExpr_lvalue_o->modifiers = 0x0;
        Fast_PostfixExpr_lvalue_o->state = 0x6;
        Fast_PostfixExpr_lvalue_o->weak = FALSE;
        Fast_PostfixExpr_lvalue_o->id = 0;
        if (db_define(Fast_PostfixExpr_lvalue_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::PostfixExpr::lvalue'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::PostfixExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
    Fast_PostfixExpr_toIc_o = db_declare(Fast_PostfixExpr_o, "toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)", db_typedef(db_virtual_o));
    if (!Fast_PostfixExpr_toIc_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::PostfixExpr::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)'.");
        goto error;
    }

    /* Define ::hyve::Fast::PostfixExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
    if (!db_checkState(Fast_PostfixExpr_toIc_o, DB_DEFINED)) {
        db_function(Fast_PostfixExpr_toIc_o)->returnType = db_resolve_ext(Fast_PostfixExpr_toIc_o, NULL, "::hyve::lang::alias{\"db_ic\"}", FALSE, "element ::hyve::Fast::PostfixExpr::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored).returnType");
        db_function(Fast_PostfixExpr_toIc_o)->returnsReference = FALSE;
        db_method(Fast_PostfixExpr_toIc_o)->virtual = TRUE;
        
        /* Bind Fast_PostfixExpr_toIc_o with C-function */
        db_function(Fast_PostfixExpr_toIc_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_PostfixExpr_toIc_v(void *args, void *result);
        db_function(Fast_PostfixExpr_toIc_o)->impl = (db_word)__Fast_PostfixExpr_toIc_v;
        if (db_define(Fast_PostfixExpr_toIc_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::PostfixExpr::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::PostfixExpr */
    if (!db_checkState(Fast_PostfixExpr_o, DB_DEFINED)) {
        db_type(Fast_PostfixExpr_o)->defaultType = db_resolve_ext(Fast_PostfixExpr_o, NULL, "::hyve::lang::member", FALSE, "element ::hyve::Fast::PostfixExpr.defaultType");
        db_type(Fast_PostfixExpr_o)->parentType = NULL;
        db_type(Fast_PostfixExpr_o)->parentState = 0x0;
        db_interface(Fast_PostfixExpr_o)->base = db_resolve_ext(Fast_PostfixExpr_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::PostfixExpr.base");
        db_struct(Fast_PostfixExpr_o)->baseAccess = 0x4;
        Fast_PostfixExpr_o->implements.length = 0;
        Fast_PostfixExpr_o->implements.buffer = NULL;
        if (db_define(Fast_PostfixExpr_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::PostfixExpr'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::TernaryExpr::condition */
    if (!db_checkState(Fast_TernaryExpr_condition_o, DB_DEFINED)) {
        Fast_TernaryExpr_condition_o->type = db_resolve_ext(Fast_TernaryExpr_condition_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::TernaryExpr::condition.type");
        Fast_TernaryExpr_condition_o->modifiers = 0x0;
        Fast_TernaryExpr_condition_o->state = 0x6;
        Fast_TernaryExpr_condition_o->weak = FALSE;
        Fast_TernaryExpr_condition_o->id = 0;
        if (db_define(Fast_TernaryExpr_condition_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::TernaryExpr::condition'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::TernaryExpr::construct(Fast::TernaryExpr object) */
    Fast_TernaryExpr_construct_o = db_declare(Fast_TernaryExpr_o, "construct(Fast::TernaryExpr object)", db_typedef(db_callback_o));
    if (!Fast_TernaryExpr_construct_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::TernaryExpr::construct(Fast::TernaryExpr object)'.");
        goto error;
    }

    /* Define ::hyve::Fast::TernaryExpr::construct(Fast::TernaryExpr object) */
    if (!db_checkState(Fast_TernaryExpr_construct_o, DB_DEFINED)) {
        db_function(Fast_TernaryExpr_construct_o)->returnType = db_resolve_ext(Fast_TernaryExpr_construct_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::TernaryExpr::construct(Fast::TernaryExpr object).returnType");
        db_function(Fast_TernaryExpr_construct_o)->returnsReference = FALSE;
        Fast_TernaryExpr_construct_o->delegate = db_resolve_ext(Fast_TernaryExpr_construct_o, NULL, "::hyve::lang::class::construct(lang::object object)", FALSE, "element ::hyve::Fast::TernaryExpr::construct(Fast::TernaryExpr object).delegate");
        
        /* Bind Fast_TernaryExpr_construct_o with C-function */
        db_function(Fast_TernaryExpr_construct_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_TernaryExpr_construct(void *args, void *result);
        db_function(Fast_TernaryExpr_construct_o)->impl = (db_word)__Fast_TernaryExpr_construct;
        if (db_define(Fast_TernaryExpr_construct_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::TernaryExpr::construct(Fast::TernaryExpr object)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::TernaryExpr::hasSideEffects() */
    Fast_TernaryExpr_hasSideEffects_o = db_declare(Fast_TernaryExpr_o, "hasSideEffects()", db_typedef(db_virtual_o));
    if (!Fast_TernaryExpr_hasSideEffects_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::TernaryExpr::hasSideEffects()'.");
        goto error;
    }

    /* Define ::hyve::Fast::TernaryExpr::hasSideEffects() */
    if (!db_checkState(Fast_TernaryExpr_hasSideEffects_o, DB_DEFINED)) {
        db_function(Fast_TernaryExpr_hasSideEffects_o)->returnType = db_resolve_ext(Fast_TernaryExpr_hasSideEffects_o, NULL, "::hyve::lang::bool", FALSE, "element ::hyve::Fast::TernaryExpr::hasSideEffects().returnType");
        db_function(Fast_TernaryExpr_hasSideEffects_o)->returnsReference = FALSE;
        db_method(Fast_TernaryExpr_hasSideEffects_o)->virtual = TRUE;
        
        /* Bind Fast_TernaryExpr_hasSideEffects_o with C-function */
        db_function(Fast_TernaryExpr_hasSideEffects_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_TernaryExpr_hasSideEffects_v(void *args, void *result);
        db_function(Fast_TernaryExpr_hasSideEffects_o)->impl = (db_word)__Fast_TernaryExpr_hasSideEffects_v;
        if (db_define(Fast_TernaryExpr_hasSideEffects_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::TernaryExpr::hasSideEffects()'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::TernaryExpr::ifFalse */
    if (!db_checkState(Fast_TernaryExpr_ifFalse_o, DB_DEFINED)) {
        Fast_TernaryExpr_ifFalse_o->type = db_resolve_ext(Fast_TernaryExpr_ifFalse_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::TernaryExpr::ifFalse.type");
        Fast_TernaryExpr_ifFalse_o->modifiers = 0x0;
        Fast_TernaryExpr_ifFalse_o->state = 0x6;
        Fast_TernaryExpr_ifFalse_o->weak = FALSE;
        Fast_TernaryExpr_ifFalse_o->id = 2;
        if (db_define(Fast_TernaryExpr_ifFalse_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::TernaryExpr::ifFalse'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::TernaryExpr::ifFalseExpr */
    if (!db_checkState(Fast_TernaryExpr_ifFalseExpr_o, DB_DEFINED)) {
        Fast_TernaryExpr_ifFalseExpr_o->type = db_resolve_ext(Fast_TernaryExpr_ifFalseExpr_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::TernaryExpr::ifFalseExpr.type");
        Fast_TernaryExpr_ifFalseExpr_o->modifiers = 0x3;
        Fast_TernaryExpr_ifFalseExpr_o->state = 0x6;
        Fast_TernaryExpr_ifFalseExpr_o->weak = FALSE;
        Fast_TernaryExpr_ifFalseExpr_o->id = 4;
        if (db_define(Fast_TernaryExpr_ifFalseExpr_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::TernaryExpr::ifFalseExpr'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::TernaryExpr::ifTrue */
    if (!db_checkState(Fast_TernaryExpr_ifTrue_o, DB_DEFINED)) {
        Fast_TernaryExpr_ifTrue_o->type = db_resolve_ext(Fast_TernaryExpr_ifTrue_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::TernaryExpr::ifTrue.type");
        Fast_TernaryExpr_ifTrue_o->modifiers = 0x0;
        Fast_TernaryExpr_ifTrue_o->state = 0x6;
        Fast_TernaryExpr_ifTrue_o->weak = FALSE;
        Fast_TernaryExpr_ifTrue_o->id = 1;
        if (db_define(Fast_TernaryExpr_ifTrue_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::TernaryExpr::ifTrue'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::TernaryExpr::ifTrueExpr */
    if (!db_checkState(Fast_TernaryExpr_ifTrueExpr_o, DB_DEFINED)) {
        Fast_TernaryExpr_ifTrueExpr_o->type = db_resolve_ext(Fast_TernaryExpr_ifTrueExpr_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::TernaryExpr::ifTrueExpr.type");
        Fast_TernaryExpr_ifTrueExpr_o->modifiers = 0x3;
        Fast_TernaryExpr_ifTrueExpr_o->state = 0x6;
        Fast_TernaryExpr_ifTrueExpr_o->weak = FALSE;
        Fast_TernaryExpr_ifTrueExpr_o->id = 3;
        if (db_define(Fast_TernaryExpr_ifTrueExpr_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::TernaryExpr::ifTrueExpr'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::TernaryExpr::result */
    if (!db_checkState(Fast_TernaryExpr_result_o, DB_DEFINED)) {
        Fast_TernaryExpr_result_o->type = db_resolve_ext(Fast_TernaryExpr_result_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::TernaryExpr::result.type");
        Fast_TernaryExpr_result_o->modifiers = 0x0;
        Fast_TernaryExpr_result_o->state = 0x6;
        Fast_TernaryExpr_result_o->weak = FALSE;
        Fast_TernaryExpr_result_o->id = 5;
        if (db_define(Fast_TernaryExpr_result_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::TernaryExpr::result'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::TernaryExpr::setOperator(lang::operatorKind kind) */
    Fast_TernaryExpr_setOperator_o = db_declare(Fast_TernaryExpr_o, "setOperator(lang::operatorKind kind)", db_typedef(db_method_o));
    if (!Fast_TernaryExpr_setOperator_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::TernaryExpr::setOperator(lang::operatorKind kind)'.");
        goto error;
    }

    /* Define ::hyve::Fast::TernaryExpr::setOperator(lang::operatorKind kind) */
    if (!db_checkState(Fast_TernaryExpr_setOperator_o, DB_DEFINED)) {
        db_function(Fast_TernaryExpr_setOperator_o)->returnType = db_resolve_ext(Fast_TernaryExpr_setOperator_o, NULL, "::hyve::lang::void", FALSE, "element ::hyve::Fast::TernaryExpr::setOperator(lang::operatorKind kind).returnType");
        db_function(Fast_TernaryExpr_setOperator_o)->returnsReference = FALSE;
        Fast_TernaryExpr_setOperator_o->virtual = FALSE;
        
        /* Bind Fast_TernaryExpr_setOperator_o with C-function */
        db_function(Fast_TernaryExpr_setOperator_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_TernaryExpr_setOperator(void *args, void *result);
        db_function(Fast_TernaryExpr_setOperator_o)->impl = (db_word)__Fast_TernaryExpr_setOperator;
        if (db_define(Fast_TernaryExpr_setOperator_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::TernaryExpr::setOperator(lang::operatorKind kind)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::TernaryExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
    Fast_TernaryExpr_toIc_o = db_declare(Fast_TernaryExpr_o, "toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)", db_typedef(db_virtual_o));
    if (!Fast_TernaryExpr_toIc_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::TernaryExpr::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)'.");
        goto error;
    }

    /* Define ::hyve::Fast::TernaryExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
    if (!db_checkState(Fast_TernaryExpr_toIc_o, DB_DEFINED)) {
        db_function(Fast_TernaryExpr_toIc_o)->returnType = db_resolve_ext(Fast_TernaryExpr_toIc_o, NULL, "::hyve::lang::alias{\"db_ic\"}", FALSE, "element ::hyve::Fast::TernaryExpr::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored).returnType");
        db_function(Fast_TernaryExpr_toIc_o)->returnsReference = FALSE;
        db_method(Fast_TernaryExpr_toIc_o)->virtual = TRUE;
        
        /* Bind Fast_TernaryExpr_toIc_o with C-function */
        db_function(Fast_TernaryExpr_toIc_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_TernaryExpr_toIc_v(void *args, void *result);
        db_function(Fast_TernaryExpr_toIc_o)->impl = (db_word)__Fast_TernaryExpr_toIc_v;
        if (db_define(Fast_TernaryExpr_toIc_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::TernaryExpr::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::UnaryExpr::construct(Fast::UnaryExpr object) */
    Fast_UnaryExpr_construct_o = db_declare(Fast_UnaryExpr_o, "construct(Fast::UnaryExpr object)", db_typedef(db_callback_o));
    if (!Fast_UnaryExpr_construct_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::UnaryExpr::construct(Fast::UnaryExpr object)'.");
        goto error;
    }

    /* Define ::hyve::Fast::UnaryExpr::construct(Fast::UnaryExpr object) */
    if (!db_checkState(Fast_UnaryExpr_construct_o, DB_DEFINED)) {
        db_function(Fast_UnaryExpr_construct_o)->returnType = db_resolve_ext(Fast_UnaryExpr_construct_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::UnaryExpr::construct(Fast::UnaryExpr object).returnType");
        db_function(Fast_UnaryExpr_construct_o)->returnsReference = FALSE;
        Fast_UnaryExpr_construct_o->delegate = db_resolve_ext(Fast_UnaryExpr_construct_o, NULL, "::hyve::lang::class::construct(lang::object object)", FALSE, "element ::hyve::Fast::UnaryExpr::construct(Fast::UnaryExpr object).delegate");
        
        /* Bind Fast_UnaryExpr_construct_o with C-function */
        db_function(Fast_UnaryExpr_construct_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_UnaryExpr_construct(void *args, void *result);
        db_function(Fast_UnaryExpr_construct_o)->impl = (db_word)__Fast_UnaryExpr_construct;
        if (db_define(Fast_UnaryExpr_construct_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::UnaryExpr::construct(Fast::UnaryExpr object)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::UnaryExpr::hasSideEffects() */
    Fast_UnaryExpr_hasSideEffects_o = db_declare(Fast_UnaryExpr_o, "hasSideEffects()", db_typedef(db_virtual_o));
    if (!Fast_UnaryExpr_hasSideEffects_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::UnaryExpr::hasSideEffects()'.");
        goto error;
    }

    /* Define ::hyve::Fast::UnaryExpr::hasSideEffects() */
    if (!db_checkState(Fast_UnaryExpr_hasSideEffects_o, DB_DEFINED)) {
        db_function(Fast_UnaryExpr_hasSideEffects_o)->returnType = db_resolve_ext(Fast_UnaryExpr_hasSideEffects_o, NULL, "::hyve::lang::bool", FALSE, "element ::hyve::Fast::UnaryExpr::hasSideEffects().returnType");
        db_function(Fast_UnaryExpr_hasSideEffects_o)->returnsReference = FALSE;
        db_method(Fast_UnaryExpr_hasSideEffects_o)->virtual = TRUE;
        
        /* Bind Fast_UnaryExpr_hasSideEffects_o with C-function */
        db_function(Fast_UnaryExpr_hasSideEffects_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_UnaryExpr_hasSideEffects_v(void *args, void *result);
        db_function(Fast_UnaryExpr_hasSideEffects_o)->impl = (db_word)__Fast_UnaryExpr_hasSideEffects_v;
        if (db_define(Fast_UnaryExpr_hasSideEffects_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::UnaryExpr::hasSideEffects()'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::UnaryExpr::lvalue */
    if (!db_checkState(Fast_UnaryExpr_lvalue_o, DB_DEFINED)) {
        Fast_UnaryExpr_lvalue_o->type = db_resolve_ext(Fast_UnaryExpr_lvalue_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::UnaryExpr::lvalue.type");
        Fast_UnaryExpr_lvalue_o->modifiers = 0x0;
        Fast_UnaryExpr_lvalue_o->state = 0x6;
        Fast_UnaryExpr_lvalue_o->weak = FALSE;
        Fast_UnaryExpr_lvalue_o->id = 0;
        if (db_define(Fast_UnaryExpr_lvalue_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::UnaryExpr::lvalue'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::UnaryExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
    Fast_UnaryExpr_toIc_o = db_declare(Fast_UnaryExpr_o, "toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)", db_typedef(db_virtual_o));
    if (!Fast_UnaryExpr_toIc_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::UnaryExpr::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)'.");
        goto error;
    }

    /* Define ::hyve::Fast::UnaryExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
    if (!db_checkState(Fast_UnaryExpr_toIc_o, DB_DEFINED)) {
        db_function(Fast_UnaryExpr_toIc_o)->returnType = db_resolve_ext(Fast_UnaryExpr_toIc_o, NULL, "::hyve::lang::alias{\"db_ic\"}", FALSE, "element ::hyve::Fast::UnaryExpr::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored).returnType");
        db_function(Fast_UnaryExpr_toIc_o)->returnsReference = FALSE;
        db_method(Fast_UnaryExpr_toIc_o)->virtual = TRUE;
        
        /* Bind Fast_UnaryExpr_toIc_o with C-function */
        db_function(Fast_UnaryExpr_toIc_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_UnaryExpr_toIc_v(void *args, void *result);
        db_function(Fast_UnaryExpr_toIc_o)->impl = (db_word)__Fast_UnaryExpr_toIc_v;
        if (db_define(Fast_UnaryExpr_toIc_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::UnaryExpr::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::UnaryExpr */
    if (!db_checkState(Fast_UnaryExpr_o, DB_DEFINED)) {
        db_type(Fast_UnaryExpr_o)->defaultType = db_resolve_ext(Fast_UnaryExpr_o, NULL, "::hyve::lang::member", FALSE, "element ::hyve::Fast::UnaryExpr.defaultType");
        db_type(Fast_UnaryExpr_o)->parentType = NULL;
        db_type(Fast_UnaryExpr_o)->parentState = 0x0;
        db_interface(Fast_UnaryExpr_o)->base = db_resolve_ext(Fast_UnaryExpr_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::UnaryExpr.base");
        db_struct(Fast_UnaryExpr_o)->baseAccess = 0x4;
        Fast_UnaryExpr_o->implements.length = 0;
        Fast_UnaryExpr_o->implements.buffer = NULL;
        if (db_define(Fast_UnaryExpr_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::UnaryExpr'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::Update::from */
    if (!db_checkState(Fast_Update_from_o, DB_DEFINED)) {
        Fast_Update_from_o->type = db_resolve_ext(Fast_Update_from_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::Update::from.type");
        Fast_Update_from_o->modifiers = 0x0;
        Fast_Update_from_o->state = 0x6;
        Fast_Update_from_o->weak = FALSE;
        Fast_Update_from_o->id = 2;
        if (db_define(Fast_Update_from_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Update::from'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Variable::construct(Variable object) */
    Fast_Variable_construct_o = db_declare(Fast_Variable_o, "construct(Variable object)", db_typedef(db_callback_o));
    if (!Fast_Variable_construct_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Variable::construct(Variable object)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Variable::construct(Variable object) */
    if (!db_checkState(Fast_Variable_construct_o, DB_DEFINED)) {
        db_function(Fast_Variable_construct_o)->returnType = db_resolve_ext(Fast_Variable_construct_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::Variable::construct(Variable object).returnType");
        db_function(Fast_Variable_construct_o)->returnsReference = FALSE;
        Fast_Variable_construct_o->delegate = db_resolve_ext(Fast_Variable_construct_o, NULL, "::hyve::lang::class::construct(lang::object object)", FALSE, "element ::hyve::Fast::Variable::construct(Variable object).delegate");
        
        /* Bind Fast_Variable_construct_o with C-function */
        db_function(Fast_Variable_construct_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Variable_construct(void *args, void *result);
        db_function(Fast_Variable_construct_o)->impl = (db_word)__Fast_Variable_construct;
        if (db_define(Fast_Variable_construct_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Variable::construct(Variable object)'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::Variable */
    if (!db_checkState(Fast_Variable_o, DB_DEFINED)) {
        db_type(Fast_Variable_o)->defaultType = db_resolve_ext(Fast_Variable_o, NULL, "::hyve::lang::member", FALSE, "element ::hyve::Fast::Variable.defaultType");
        db_type(Fast_Variable_o)->parentType = NULL;
        db_type(Fast_Variable_o)->parentState = 0x0;
        db_interface(Fast_Variable_o)->base = db_resolve_ext(Fast_Variable_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::Variable.base");
        db_struct(Fast_Variable_o)->baseAccess = 0x4;
        Fast_Variable_o->implements.length = 0;
        Fast_Variable_o->implements.buffer = NULL;
        if (db_define(Fast_Variable_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Variable'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Block::declare(lang::string id,Fast::Variable type,lang::bool isParameter,bool isReference) */
    Fast_Block_declare_o = db_declare(Fast_Block_o, "declare(lang::string id,Fast::Variable type,lang::bool isParameter,bool isReference)", db_typedef(db_method_o));
    if (!Fast_Block_declare_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Block::declare(lang::string id,Fast::Variable type,lang::bool isParameter,bool isReference)'.");
        goto error;
    }

    /* Declare ::hyve::Fast::Block::declareTemplate(lang::string id,Fast::Variable type,lang::bool isParameter,bool isReference) */
    Fast_Block_declareTemplate_o = db_declare(Fast_Block_o, "declareTemplate(lang::string id,Fast::Variable type,lang::bool isParameter,bool isReference)", db_typedef(db_method_o));
    if (!Fast_Block_declareTemplate_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Block::declareTemplate(lang::string id,Fast::Variable type,lang::bool isParameter,bool isReference)'.");
        goto error;
    }

    /* Declare ::hyve::Fast::Local::construct(Local object) */
    Fast_Local_construct_o = db_declare(Fast_Local_o, "construct(Local object)", db_typedef(db_callback_o));
    if (!Fast_Local_construct_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Local::construct(Local object)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Local::construct(Local object) */
    if (!db_checkState(Fast_Local_construct_o, DB_DEFINED)) {
        db_function(Fast_Local_construct_o)->returnType = db_resolve_ext(Fast_Local_construct_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::Local::construct(Local object).returnType");
        db_function(Fast_Local_construct_o)->returnsReference = FALSE;
        Fast_Local_construct_o->delegate = db_resolve_ext(Fast_Local_construct_o, NULL, "::hyve::lang::class::construct(lang::object object)", FALSE, "element ::hyve::Fast::Local::construct(Local object).delegate");
        
        /* Bind Fast_Local_construct_o with C-function */
        db_function(Fast_Local_construct_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Local_construct(void *args, void *result);
        db_function(Fast_Local_construct_o)->impl = (db_word)__Fast_Local_construct;
        if (db_define(Fast_Local_construct_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Local::construct(Local object)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Local::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
    Fast_Local_toIc_o = db_declare(Fast_Local_o, "toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)", db_typedef(db_virtual_o));
    if (!Fast_Local_toIc_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Local::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Local::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
    if (!db_checkState(Fast_Local_toIc_o, DB_DEFINED)) {
        db_function(Fast_Local_toIc_o)->returnType = db_resolve_ext(Fast_Local_toIc_o, NULL, "::hyve::lang::alias{\"db_ic\"}", FALSE, "element ::hyve::Fast::Local::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored).returnType");
        db_function(Fast_Local_toIc_o)->returnsReference = FALSE;
        db_method(Fast_Local_toIc_o)->virtual = TRUE;
        
        /* Bind Fast_Local_toIc_o with C-function */
        db_function(Fast_Local_toIc_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Local_toIc_v(void *args, void *result);
        db_function(Fast_Local_toIc_o)->impl = (db_word)__Fast_Local_toIc_v;
        if (db_define(Fast_Local_toIc_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Local::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::Local::type */
    if (!db_checkState(Fast_Local_type_o, DB_DEFINED)) {
        Fast_Local_type_o->type = db_resolve_ext(Fast_Local_type_o, NULL, "::hyve::Fast::Variable", FALSE, "element ::hyve::Fast::Local::type.type");
        Fast_Local_type_o->modifiers = 0x0;
        Fast_Local_type_o->state = 0x6;
        Fast_Local_type_o->weak = FALSE;
        Fast_Local_type_o->id = 1;
        if (db_define(Fast_Local_type_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Local::type'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::Local */
    if (!db_checkState(Fast_Local_o, DB_DEFINED)) {
        db_type(Fast_Local_o)->defaultType = db_resolve_ext(Fast_Local_o, NULL, "::hyve::lang::member", FALSE, "element ::hyve::Fast::Local.defaultType");
        db_type(Fast_Local_o)->parentType = NULL;
        db_type(Fast_Local_o)->parentState = 0x0;
        db_interface(Fast_Local_o)->base = db_resolve_ext(Fast_Local_o, NULL, "::hyve::Fast::Variable", FALSE, "element ::hyve::Fast::Local.base");
        db_struct(Fast_Local_o)->baseAccess = 0x4;
        Fast_Local_o->implements.length = 0;
        Fast_Local_o->implements.buffer = NULL;
        if (db_define(Fast_Local_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Local'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::Block::declare(lang::string id,Fast::Variable type,lang::bool isParameter,bool isReference) */
    if (!db_checkState(Fast_Block_declare_o, DB_DEFINED)) {
        db_function(Fast_Block_declare_o)->returnType = db_resolve_ext(Fast_Block_declare_o, NULL, "::hyve::Fast::Local", FALSE, "element ::hyve::Fast::Block::declare(lang::string id,Fast::Variable type,lang::bool isParameter,bool isReference).returnType");
        db_function(Fast_Block_declare_o)->returnsReference = FALSE;
        Fast_Block_declare_o->virtual = FALSE;
        
        /* Bind Fast_Block_declare_o with C-function */
        db_function(Fast_Block_declare_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Block_declare(void *args, void *result);
        db_function(Fast_Block_declare_o)->impl = (db_word)__Fast_Block_declare;
        if (db_define(Fast_Block_declare_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Block::declare(lang::string id,Fast::Variable type,lang::bool isParameter,bool isReference)'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::Block::declareReturnVariable(lang::function function) */
    if (!db_checkState(Fast_Block_declareReturnVariable_o, DB_DEFINED)) {
        db_function(Fast_Block_declareReturnVariable_o)->returnType = db_resolve_ext(Fast_Block_declareReturnVariable_o, NULL, "::hyve::Fast::Local", FALSE, "element ::hyve::Fast::Block::declareReturnVariable(lang::function function).returnType");
        db_function(Fast_Block_declareReturnVariable_o)->returnsReference = FALSE;
        Fast_Block_declareReturnVariable_o->virtual = FALSE;
        
        /* Bind Fast_Block_declareReturnVariable_o with C-function */
        db_function(Fast_Block_declareReturnVariable_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Block_declareReturnVariable(void *args, void *result);
        db_function(Fast_Block_declareReturnVariable_o)->impl = (db_word)__Fast_Block_declareReturnVariable;
        if (db_define(Fast_Block_declareReturnVariable_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Block::declareReturnVariable(lang::function function)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Template::construct(Template object) */
    Fast_Template_construct_o = db_declare(Fast_Template_o, "construct(Template object)", db_typedef(db_callback_o));
    if (!Fast_Template_construct_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Template::construct(Template object)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Template::construct(Template object) */
    if (!db_checkState(Fast_Template_construct_o, DB_DEFINED)) {
        db_function(Fast_Template_construct_o)->returnType = db_resolve_ext(Fast_Template_construct_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::Template::construct(Template object).returnType");
        db_function(Fast_Template_construct_o)->returnsReference = FALSE;
        Fast_Template_construct_o->delegate = db_resolve_ext(Fast_Template_construct_o, NULL, "::hyve::lang::class::construct(lang::object object)", FALSE, "element ::hyve::Fast::Template::construct(Template object).delegate");
        
        /* Bind Fast_Template_construct_o with C-function */
        db_function(Fast_Template_construct_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Template_construct(void *args, void *result);
        db_function(Fast_Template_construct_o)->impl = (db_word)__Fast_Template_construct;
        if (db_define(Fast_Template_construct_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Template::construct(Template object)'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::Template */
    if (!db_checkState(Fast_Template_o, DB_DEFINED)) {
        db_type(Fast_Template_o)->defaultType = db_resolve_ext(Fast_Template_o, NULL, "::hyve::lang::member", FALSE, "element ::hyve::Fast::Template.defaultType");
        db_type(Fast_Template_o)->parentType = NULL;
        db_type(Fast_Template_o)->parentState = 0x0;
        db_interface(Fast_Template_o)->base = db_resolve_ext(Fast_Template_o, NULL, "::hyve::Fast::Local", FALSE, "element ::hyve::Fast::Template.base");
        db_struct(Fast_Template_o)->baseAccess = 0x0;
        Fast_Template_o->implements.length = 0;
        Fast_Template_o->implements.buffer = NULL;
        if (db_define(Fast_Template_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Template'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::Block::declareTemplate(lang::string id,Fast::Variable type,lang::bool isParameter,bool isReference) */
    if (!db_checkState(Fast_Block_declareTemplate_o, DB_DEFINED)) {
        db_function(Fast_Block_declareTemplate_o)->returnType = db_resolve_ext(Fast_Block_declareTemplate_o, NULL, "::hyve::Fast::Template", FALSE, "element ::hyve::Fast::Block::declareTemplate(lang::string id,Fast::Variable type,lang::bool isParameter,bool isReference).returnType");
        db_function(Fast_Block_declareTemplate_o)->returnsReference = FALSE;
        Fast_Block_declareTemplate_o->virtual = FALSE;
        
        /* Bind Fast_Block_declareTemplate_o with C-function */
        db_function(Fast_Block_declareTemplate_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Block_declareTemplate(void *args, void *result);
        db_function(Fast_Block_declareTemplate_o)->impl = (db_word)__Fast_Block_declareTemplate;
        if (db_define(Fast_Block_declareTemplate_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Block::declareTemplate(lang::string id,Fast::Variable type,lang::bool isParameter,bool isReference)'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::Block */
    if (!db_checkState(Fast_Block_o, DB_DEFINED)) {
        db_type(Fast_Block_o)->defaultType = db_resolve_ext(Fast_Block_o, NULL, "::hyve::lang::member", FALSE, "element ::hyve::Fast::Block.defaultType");
        db_type(Fast_Block_o)->parentType = NULL;
        db_type(Fast_Block_o)->parentState = 0x0;
        db_interface(Fast_Block_o)->base = db_resolve_ext(Fast_Block_o, NULL, "::hyve::Fast::Node", FALSE, "element ::hyve::Fast::Block.base");
        db_struct(Fast_Block_o)->baseAccess = 0x4;
        Fast_Block_o->implements.length = 0;
        Fast_Block_o->implements.buffer = NULL;
        if (db_define(Fast_Block_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Block'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::Binding::impl */
    if (!db_checkState(Fast_Binding_impl_o, DB_DEFINED)) {
        Fast_Binding_impl_o->type = db_resolve_ext(Fast_Binding_impl_o, NULL, "::hyve::Fast::Block", FALSE, "element ::hyve::Fast::Binding::impl.type");
        Fast_Binding_impl_o->modifiers = 0x0;
        Fast_Binding_impl_o->state = 0x6;
        Fast_Binding_impl_o->weak = FALSE;
        Fast_Binding_impl_o->id = 1;
        if (db_define(Fast_Binding_impl_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Binding::impl'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::Binding */
    if (!db_checkState(Fast_Binding_o, DB_DEFINED)) {
        db_type(Fast_Binding_o)->defaultType = db_resolve_ext(Fast_Binding_o, NULL, "::hyve::lang::member", FALSE, "element ::hyve::Fast::Binding.defaultType");
        db_type(Fast_Binding_o)->parentType = NULL;
        db_type(Fast_Binding_o)->parentState = 0x0;
        db_interface(Fast_Binding_o)->base = NULL;
        Fast_Binding_o->baseAccess = 0x0;
        if (db_define(Fast_Binding_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Binding'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::If::trueBranch */
    if (!db_checkState(Fast_If_trueBranch_o, DB_DEFINED)) {
        Fast_If_trueBranch_o->type = db_resolve_ext(Fast_If_trueBranch_o, NULL, "::hyve::Fast::Block", FALSE, "element ::hyve::Fast::If::trueBranch.type");
        Fast_If_trueBranch_o->modifiers = 0x0;
        Fast_If_trueBranch_o->state = 0x6;
        Fast_If_trueBranch_o->weak = FALSE;
        Fast_If_trueBranch_o->id = 1;
        if (db_define(Fast_If_trueBranch_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::If::trueBranch'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::bind(Fast::Variable function,Fast::Block block) */
    Fast_Parser_bind_o = db_declare(Fast_Parser_o, "bind(Fast::Variable function,Fast::Block block)", db_typedef(db_method_o));
    if (!Fast_Parser_bind_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::bind(Fast::Variable function,Fast::Block block)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::bind(Fast::Variable function,Fast::Block block) */
    if (!db_checkState(Fast_Parser_bind_o, DB_DEFINED)) {
        db_function(Fast_Parser_bind_o)->returnType = db_resolve_ext(Fast_Parser_bind_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::Parser::bind(Fast::Variable function,Fast::Block block).returnType");
        db_function(Fast_Parser_bind_o)->returnsReference = FALSE;
        Fast_Parser_bind_o->virtual = FALSE;
        
        /* Bind Fast_Parser_bind_o with C-function */
        db_function(Fast_Parser_bind_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Parser_bind(void *args, void *result);
        db_function(Fast_Parser_bind_o)->impl = (db_word)__Fast_Parser_bind;
        if (db_define(Fast_Parser_bind_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::bind(Fast::Variable function,Fast::Block block)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::bindOneliner(Fast::Variable function,Fast::Block block,Fast::Expression expr) */
    Fast_Parser_bindOneliner_o = db_declare(Fast_Parser_o, "bindOneliner(Fast::Variable function,Fast::Block block,Fast::Expression expr)", db_typedef(db_method_o));
    if (!Fast_Parser_bindOneliner_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::bindOneliner(Fast::Variable function,Fast::Block block,Fast::Expression expr)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::bindOneliner(Fast::Variable function,Fast::Block block,Fast::Expression expr) */
    if (!db_checkState(Fast_Parser_bindOneliner_o, DB_DEFINED)) {
        db_function(Fast_Parser_bindOneliner_o)->returnType = db_resolve_ext(Fast_Parser_bindOneliner_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::Parser::bindOneliner(Fast::Variable function,Fast::Block block,Fast::Expression expr).returnType");
        db_function(Fast_Parser_bindOneliner_o)->returnsReference = FALSE;
        Fast_Parser_bindOneliner_o->virtual = FALSE;
        
        /* Bind Fast_Parser_bindOneliner_o with C-function */
        db_function(Fast_Parser_bindOneliner_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Parser_bindOneliner(void *args, void *result);
        db_function(Fast_Parser_bindOneliner_o)->impl = (db_word)__Fast_Parser_bindOneliner;
        if (db_define(Fast_Parser_bindOneliner_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::bindOneliner(Fast::Variable function,Fast::Block block,Fast::Expression expr)'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::Parser::block */
    if (!db_checkState(Fast_Parser_block_o, DB_DEFINED)) {
        Fast_Parser_block_o->type = db_resolve_ext(Fast_Parser_block_o, NULL, "::hyve::Fast::Block", FALSE, "element ::hyve::Fast::Parser::block.type");
        Fast_Parser_block_o->modifiers = 0x4;
        Fast_Parser_block_o->state = 0x6;
        Fast_Parser_block_o->weak = FALSE;
        Fast_Parser_block_o->id = 6;
        if (db_define(Fast_Parser_block_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::block'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::Parser::blockPush(lang::bool presetBlock) */
    if (!db_checkState(Fast_Parser_blockPush_o, DB_DEFINED)) {
        db_function(Fast_Parser_blockPush_o)->returnType = db_resolve_ext(Fast_Parser_blockPush_o, NULL, "::hyve::Fast::Block", FALSE, "element ::hyve::Fast::Parser::blockPush(lang::bool presetBlock).returnType");
        db_function(Fast_Parser_blockPush_o)->returnsReference = FALSE;
        Fast_Parser_blockPush_o->virtual = FALSE;
        
        /* Bind Fast_Parser_blockPush_o with C-function */
        db_function(Fast_Parser_blockPush_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Parser_blockPush(void *args, void *result);
        db_function(Fast_Parser_blockPush_o)->impl = (db_word)__Fast_Parser_blockPush;
        if (db_define(Fast_Parser_blockPush_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::blockPush(lang::bool presetBlock)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::declareFunctionParams(Variable function) */
    Fast_Parser_declareFunctionParams_o = db_declare(Fast_Parser_o, "declareFunctionParams(Variable function)", db_typedef(db_method_o));
    if (!Fast_Parser_declareFunctionParams_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::declareFunctionParams(Variable function)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::declareFunctionParams(Variable function) */
    if (!db_checkState(Fast_Parser_declareFunctionParams_o, DB_DEFINED)) {
        db_function(Fast_Parser_declareFunctionParams_o)->returnType = db_resolve_ext(Fast_Parser_declareFunctionParams_o, NULL, "::hyve::Fast::Block", FALSE, "element ::hyve::Fast::Parser::declareFunctionParams(Variable function).returnType");
        db_function(Fast_Parser_declareFunctionParams_o)->returnsReference = FALSE;
        Fast_Parser_declareFunctionParams_o->virtual = FALSE;
        
        /* Bind Fast_Parser_declareFunctionParams_o with C-function */
        db_function(Fast_Parser_declareFunctionParams_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Parser_declareFunctionParams(void *args, void *result);
        db_function(Fast_Parser_declareFunctionParams_o)->impl = (db_word)__Fast_Parser_declareFunctionParams;
        if (db_define(Fast_Parser_declareFunctionParams_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::declareFunctionParams(Variable function)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::parseExpression(lang::string expr,Fast::Block block,Fast::Variable scope,uint32 line,uint32 column) */
    Fast_Parser_parseExpression_o = db_declare(Fast_Parser_o, "parseExpression(lang::string expr,Fast::Block block,Fast::Variable scope,uint32 line,uint32 column)", db_typedef(db_method_o));
    if (!Fast_Parser_parseExpression_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::parseExpression(lang::string expr,Fast::Block block,Fast::Variable scope,uint32 line,uint32 column)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::parseExpression(lang::string expr,Fast::Block block,Fast::Variable scope,uint32 line,uint32 column) */
    if (!db_checkState(Fast_Parser_parseExpression_o, DB_DEFINED)) {
        db_function(Fast_Parser_parseExpression_o)->returnType = db_resolve_ext(Fast_Parser_parseExpression_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::Parser::parseExpression(lang::string expr,Fast::Block block,Fast::Variable scope,uint32 line,uint32 column).returnType");
        db_function(Fast_Parser_parseExpression_o)->returnsReference = FALSE;
        Fast_Parser_parseExpression_o->virtual = FALSE;
        
        /* Bind Fast_Parser_parseExpression_o with C-function */
        db_function(Fast_Parser_parseExpression_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Parser_parseExpression(void *args, void *result);
        db_function(Fast_Parser_parseExpression_o)->impl = (db_word)__Fast_Parser_parseExpression;
        if (db_define(Fast_Parser_parseExpression_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::parseExpression(lang::string expr,Fast::Block block,Fast::Variable scope,uint32 line,uint32 column)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::updateStatement(Fast::Expression expr,Fast::Block block) */
    Fast_Parser_updateStatement_o = db_declare(Fast_Parser_o, "updateStatement(Fast::Expression expr,Fast::Block block)", db_typedef(db_method_o));
    if (!Fast_Parser_updateStatement_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::updateStatement(Fast::Expression expr,Fast::Block block)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::updateStatement(Fast::Expression expr,Fast::Block block) */
    if (!db_checkState(Fast_Parser_updateStatement_o, DB_DEFINED)) {
        db_function(Fast_Parser_updateStatement_o)->returnType = db_resolve_ext(Fast_Parser_updateStatement_o, NULL, "::hyve::Fast::Node", FALSE, "element ::hyve::Fast::Parser::updateStatement(Fast::Expression expr,Fast::Block block).returnType");
        db_function(Fast_Parser_updateStatement_o)->returnsReference = FALSE;
        Fast_Parser_updateStatement_o->virtual = FALSE;
        
        /* Bind Fast_Parser_updateStatement_o with C-function */
        db_function(Fast_Parser_updateStatement_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Parser_updateStatement(void *args, void *result);
        db_function(Fast_Parser_updateStatement_o)->impl = (db_word)__Fast_Parser_updateStatement;
        if (db_define(Fast_Parser_updateStatement_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::updateStatement(Fast::Expression expr,Fast::Block block)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::whileStatement(Fast::Expression condition,Fast::Block trueBranch,lang::bool isUntil) */
    Fast_Parser_whileStatement_o = db_declare(Fast_Parser_o, "whileStatement(Fast::Expression condition,Fast::Block trueBranch,lang::bool isUntil)", db_typedef(db_method_o));
    if (!Fast_Parser_whileStatement_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::whileStatement(Fast::Expression condition,Fast::Block trueBranch,lang::bool isUntil)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::whileStatement(Fast::Expression condition,Fast::Block trueBranch,lang::bool isUntil) */
    if (!db_checkState(Fast_Parser_whileStatement_o, DB_DEFINED)) {
        db_function(Fast_Parser_whileStatement_o)->returnType = db_resolve_ext(Fast_Parser_whileStatement_o, NULL, "::hyve::Fast::Node", FALSE, "element ::hyve::Fast::Parser::whileStatement(Fast::Expression condition,Fast::Block trueBranch,lang::bool isUntil).returnType");
        db_function(Fast_Parser_whileStatement_o)->returnsReference = FALSE;
        Fast_Parser_whileStatement_o->virtual = FALSE;
        
        /* Bind Fast_Parser_whileStatement_o with C-function */
        db_function(Fast_Parser_whileStatement_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Parser_whileStatement(void *args, void *result);
        db_function(Fast_Parser_whileStatement_o)->impl = (db_word)__Fast_Parser_whileStatement;
        if (db_define(Fast_Parser_whileStatement_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::whileStatement(Fast::Expression condition,Fast::Block trueBranch,lang::bool isUntil)'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::String::block */
    if (!db_checkState(Fast_String_block_o, DB_DEFINED)) {
        Fast_String_block_o->type = db_resolve_ext(Fast_String_block_o, NULL, "::hyve::Fast::Block", FALSE, "element ::hyve::Fast::String::block.type");
        Fast_String_block_o->modifiers = 0x4;
        Fast_String_block_o->state = 0x6;
        Fast_String_block_o->weak = FALSE;
        Fast_String_block_o->id = 2;
        if (db_define(Fast_String_block_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::String::block'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::Update::block */
    if (!db_checkState(Fast_Update_block_o, DB_DEFINED)) {
        Fast_Update_block_o->type = db_resolve_ext(Fast_Update_block_o, NULL, "::hyve::Fast::Block", FALSE, "element ::hyve::Fast::Update::block.type");
        Fast_Update_block_o->modifiers = 0x0;
        Fast_Update_block_o->state = 0x6;
        Fast_Update_block_o->weak = FALSE;
        Fast_Update_block_o->id = 1;
        if (db_define(Fast_Update_block_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Update::block'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::While::trueBranch */
    if (!db_checkState(Fast_While_trueBranch_o, DB_DEFINED)) {
        Fast_While_trueBranch_o->type = db_resolve_ext(Fast_While_trueBranch_o, NULL, "::hyve::Fast::Block", FALSE, "element ::hyve::Fast::While::trueBranch.type");
        Fast_While_trueBranch_o->modifiers = 0x0;
        Fast_While_trueBranch_o->state = 0x6;
        Fast_While_trueBranch_o->weak = FALSE;
        Fast_While_trueBranch_o->id = 1;
        if (db_define(Fast_While_trueBranch_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::While::trueBranch'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::ObjectBase::construct(ObjectBase object) */
    Fast_ObjectBase_construct_o = db_declare(Fast_ObjectBase_o, "construct(ObjectBase object)", db_typedef(db_callback_o));
    if (!Fast_ObjectBase_construct_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::ObjectBase::construct(ObjectBase object)'.");
        goto error;
    }

    /* Define ::hyve::Fast::ObjectBase::construct(ObjectBase object) */
    if (!db_checkState(Fast_ObjectBase_construct_o, DB_DEFINED)) {
        db_function(Fast_ObjectBase_construct_o)->returnType = db_resolve_ext(Fast_ObjectBase_construct_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::ObjectBase::construct(ObjectBase object).returnType");
        db_function(Fast_ObjectBase_construct_o)->returnsReference = FALSE;
        Fast_ObjectBase_construct_o->delegate = db_resolve_ext(Fast_ObjectBase_construct_o, NULL, "::hyve::lang::class::construct(lang::object object)", FALSE, "element ::hyve::Fast::ObjectBase::construct(ObjectBase object).delegate");
        
        /* Bind Fast_ObjectBase_construct_o with C-function */
        db_function(Fast_ObjectBase_construct_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_ObjectBase_construct(void *args, void *result);
        db_function(Fast_ObjectBase_construct_o)->impl = (db_word)__Fast_ObjectBase_construct;
        if (db_define(Fast_ObjectBase_construct_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::ObjectBase::construct(ObjectBase object)'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::ObjectBase */
    if (!db_checkState(Fast_ObjectBase_o, DB_DEFINED)) {
        db_type(Fast_ObjectBase_o)->defaultType = db_resolve_ext(Fast_ObjectBase_o, NULL, "::hyve::lang::member", FALSE, "element ::hyve::Fast::ObjectBase.defaultType");
        db_type(Fast_ObjectBase_o)->parentType = NULL;
        db_type(Fast_ObjectBase_o)->parentState = 0x0;
        db_interface(Fast_ObjectBase_o)->base = db_resolve_ext(Fast_ObjectBase_o, NULL, "::hyve::Fast::Variable", FALSE, "element ::hyve::Fast::ObjectBase.base");
        db_struct(Fast_ObjectBase_o)->baseAccess = 0x4;
        Fast_ObjectBase_o->implements.length = 0;
        Fast_ObjectBase_o->implements.buffer = NULL;
        if (db_define(Fast_ObjectBase_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::ObjectBase'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Object::construct(Object object) */
    Fast_Object_construct_o = db_declare(Fast_Object_o, "construct(Object object)", db_typedef(db_callback_o));
    if (!Fast_Object_construct_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Object::construct(Object object)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Object::construct(Object object) */
    if (!db_checkState(Fast_Object_construct_o, DB_DEFINED)) {
        db_function(Fast_Object_construct_o)->returnType = db_resolve_ext(Fast_Object_construct_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::Object::construct(Object object).returnType");
        db_function(Fast_Object_construct_o)->returnsReference = FALSE;
        Fast_Object_construct_o->delegate = db_resolve_ext(Fast_Object_construct_o, NULL, "::hyve::lang::class::construct(lang::object object)", FALSE, "element ::hyve::Fast::Object::construct(Object object).delegate");
        
        /* Bind Fast_Object_construct_o with C-function */
        db_function(Fast_Object_construct_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Object_construct(void *args, void *result);
        db_function(Fast_Object_construct_o)->impl = (db_word)__Fast_Object_construct;
        if (db_define(Fast_Object_construct_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Object::construct(Object object)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Object::getValue() */
    Fast_Object_getValue_o = db_declare(Fast_Object_o, "getValue()", db_typedef(db_method_o));
    if (!Fast_Object_getValue_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Object::getValue()'.");
        goto error;
    }

    /* Define ::hyve::Fast::Object::getValue() */
    if (!db_checkState(Fast_Object_getValue_o, DB_DEFINED)) {
        db_function(Fast_Object_getValue_o)->returnType = db_resolve_ext(Fast_Object_getValue_o, NULL, "::hyve::lang::word", FALSE, "element ::hyve::Fast::Object::getValue().returnType");
        db_function(Fast_Object_getValue_o)->returnsReference = FALSE;
        Fast_Object_getValue_o->virtual = FALSE;
        
        /* Bind Fast_Object_getValue_o with C-function */
        db_function(Fast_Object_getValue_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Object_getValue(void *args, void *result);
        db_function(Fast_Object_getValue_o)->impl = (db_word)__Fast_Object_getValue;
        if (db_define(Fast_Object_getValue_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Object::getValue()'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Object::serialize(lang::type dstType,lang::word dst) */
    Fast_Object_serialize_o = db_declare(Fast_Object_o, "serialize(lang::type dstType,lang::word dst)", db_typedef(db_method_o));
    if (!Fast_Object_serialize_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Object::serialize(lang::type dstType,lang::word dst)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Object::serialize(lang::type dstType,lang::word dst) */
    if (!db_checkState(Fast_Object_serialize_o, DB_DEFINED)) {
        db_function(Fast_Object_serialize_o)->returnType = db_resolve_ext(Fast_Object_serialize_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::Object::serialize(lang::type dstType,lang::word dst).returnType");
        db_function(Fast_Object_serialize_o)->returnsReference = FALSE;
        Fast_Object_serialize_o->virtual = FALSE;
        
        /* Bind Fast_Object_serialize_o with C-function */
        db_function(Fast_Object_serialize_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Object_serialize(void *args, void *result);
        db_function(Fast_Object_serialize_o)->impl = (db_word)__Fast_Object_serialize;
        if (db_define(Fast_Object_serialize_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Object::serialize(lang::type dstType,lang::word dst)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Object::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
    Fast_Object_toIc_o = db_declare(Fast_Object_o, "toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)", db_typedef(db_virtual_o));
    if (!Fast_Object_toIc_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Object::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Object::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
    if (!db_checkState(Fast_Object_toIc_o, DB_DEFINED)) {
        db_function(Fast_Object_toIc_o)->returnType = db_resolve_ext(Fast_Object_toIc_o, NULL, "::hyve::lang::alias{\"db_ic\"}", FALSE, "element ::hyve::Fast::Object::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored).returnType");
        db_function(Fast_Object_toIc_o)->returnsReference = FALSE;
        db_method(Fast_Object_toIc_o)->virtual = TRUE;
        
        /* Bind Fast_Object_toIc_o with C-function */
        db_function(Fast_Object_toIc_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Object_toIc_v(void *args, void *result);
        db_function(Fast_Object_toIc_o)->impl = (db_word)__Fast_Object_toIc_v;
        if (db_define(Fast_Object_toIc_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Object::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::Object */
    if (!db_checkState(Fast_Object_o, DB_DEFINED)) {
        db_type(Fast_Object_o)->defaultType = db_resolve_ext(Fast_Object_o, NULL, "::hyve::lang::member", FALSE, "element ::hyve::Fast::Object.defaultType");
        db_type(Fast_Object_o)->parentType = NULL;
        db_type(Fast_Object_o)->parentState = 0x0;
        db_interface(Fast_Object_o)->base = db_resolve_ext(Fast_Object_o, NULL, "::hyve::Fast::ObjectBase", FALSE, "element ::hyve::Fast::Object.base");
        db_struct(Fast_Object_o)->baseAccess = 0x0;
        Fast_Object_o->implements.length = 0;
        Fast_Object_o->implements.buffer = NULL;
        if (db_define(Fast_Object_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Object'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::observerDeclaration(lang::string id,Fast::Expression object,lang::eventMask mask,Fast::Object dispatcher) */
    Fast_Parser_observerDeclaration_o = db_declare(Fast_Parser_o, "observerDeclaration(lang::string id,Fast::Expression object,lang::eventMask mask,Fast::Object dispatcher)", db_typedef(db_method_o));
    if (!Fast_Parser_observerDeclaration_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::observerDeclaration(lang::string id,Fast::Expression object,lang::eventMask mask,Fast::Object dispatcher)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::observerDeclaration(lang::string id,Fast::Expression object,lang::eventMask mask,Fast::Object dispatcher) */
    if (!db_checkState(Fast_Parser_observerDeclaration_o, DB_DEFINED)) {
        db_function(Fast_Parser_observerDeclaration_o)->returnType = db_resolve_ext(Fast_Parser_observerDeclaration_o, NULL, "::hyve::Fast::Variable", FALSE, "element ::hyve::Fast::Parser::observerDeclaration(lang::string id,Fast::Expression object,lang::eventMask mask,Fast::Object dispatcher).returnType");
        db_function(Fast_Parser_observerDeclaration_o)->returnsReference = FALSE;
        Fast_Parser_observerDeclaration_o->virtual = FALSE;
        
        /* Bind Fast_Parser_observerDeclaration_o with C-function */
        db_function(Fast_Parser_observerDeclaration_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Parser_observerDeclaration(void *args, void *result);
        db_function(Fast_Parser_observerDeclaration_o)->impl = (db_word)__Fast_Parser_observerDeclaration;
        if (db_define(Fast_Parser_observerDeclaration_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::observerDeclaration(lang::string id,Fast::Expression object,lang::eventMask mask,Fast::Object dispatcher)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::argumentToString(Fast::Variable type,lang::string id,lang::bool reference) */
    Fast_Parser_argumentToString_o = db_declare(Fast_Parser_o, "argumentToString(Fast::Variable type,lang::string id,lang::bool reference)", db_typedef(db_method_o));
    if (!Fast_Parser_argumentToString_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::argumentToString(Fast::Variable type,lang::string id,lang::bool reference)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::argumentToString(Fast::Variable type,lang::string id,lang::bool reference) */
    if (!db_checkState(Fast_Parser_argumentToString_o, DB_DEFINED)) {
        db_function(Fast_Parser_argumentToString_o)->returnType = db_resolve_ext(Fast_Parser_argumentToString_o, NULL, "::hyve::lang::string", FALSE, "element ::hyve::Fast::Parser::argumentToString(Fast::Variable type,lang::string id,lang::bool reference).returnType");
        db_function(Fast_Parser_argumentToString_o)->returnsReference = FALSE;
        Fast_Parser_argumentToString_o->virtual = FALSE;
        
        /* Bind Fast_Parser_argumentToString_o with C-function */
        db_function(Fast_Parser_argumentToString_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Parser_argumentToString(void *args, void *result);
        db_function(Fast_Parser_argumentToString_o)->impl = (db_word)__Fast_Parser_argumentToString;
        if (db_define(Fast_Parser_argumentToString_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::argumentToString(Fast::Variable type,lang::string id,lang::bool reference)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::declaration(Variable type,lang::string id,lang::bool isReference) */
    Fast_Parser_declaration_o = db_declare(Fast_Parser_o, "declaration(Variable type,lang::string id,lang::bool isReference)", db_typedef(db_method_o));
    if (!Fast_Parser_declaration_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::declaration(Variable type,lang::string id,lang::bool isReference)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::declaration(Variable type,lang::string id,lang::bool isReference) */
    if (!db_checkState(Fast_Parser_declaration_o, DB_DEFINED)) {
        db_function(Fast_Parser_declaration_o)->returnType = db_resolve_ext(Fast_Parser_declaration_o, NULL, "::hyve::Fast::Variable", FALSE, "element ::hyve::Fast::Parser::declaration(Variable type,lang::string id,lang::bool isReference).returnType");
        db_function(Fast_Parser_declaration_o)->returnsReference = FALSE;
        Fast_Parser_declaration_o->virtual = FALSE;
        
        /* Bind Fast_Parser_declaration_o with C-function */
        db_function(Fast_Parser_declaration_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Parser_declaration(void *args, void *result);
        db_function(Fast_Parser_declaration_o)->impl = (db_word)__Fast_Parser_declaration;
        if (db_define(Fast_Parser_declaration_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::declaration(Variable type,lang::string id,lang::bool isReference)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::declareFunction(Variable returnType,lang::string id,lang::procedure kind,bool returnsReference) */
    Fast_Parser_declareFunction_o = db_declare(Fast_Parser_o, "declareFunction(Variable returnType,lang::string id,lang::procedure kind,bool returnsReference)", db_typedef(db_method_o));
    if (!Fast_Parser_declareFunction_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::declareFunction(Variable returnType,lang::string id,lang::procedure kind,bool returnsReference)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::declareFunction(Variable returnType,lang::string id,lang::procedure kind,bool returnsReference) */
    if (!db_checkState(Fast_Parser_declareFunction_o, DB_DEFINED)) {
        db_function(Fast_Parser_declareFunction_o)->returnType = db_resolve_ext(Fast_Parser_declareFunction_o, NULL, "::hyve::Fast::Variable", FALSE, "element ::hyve::Fast::Parser::declareFunction(Variable returnType,lang::string id,lang::procedure kind,bool returnsReference).returnType");
        db_function(Fast_Parser_declareFunction_o)->returnsReference = FALSE;
        Fast_Parser_declareFunction_o->virtual = FALSE;
        
        /* Bind Fast_Parser_declareFunction_o with C-function */
        db_function(Fast_Parser_declareFunction_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Parser_declareFunction(void *args, void *result);
        db_function(Fast_Parser_declareFunction_o)->impl = (db_word)__Fast_Parser_declareFunction;
        if (db_define(Fast_Parser_declareFunction_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::declareFunction(Variable returnType,lang::string id,lang::procedure kind,bool returnsReference)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::defineVariable(Variable object) */
    Fast_Parser_defineVariable_o = db_declare(Fast_Parser_o, "defineVariable(Variable object)", db_typedef(db_method_o));
    if (!Fast_Parser_defineVariable_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::defineVariable(Variable object)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::defineVariable(Variable object) */
    if (!db_checkState(Fast_Parser_defineVariable_o, DB_DEFINED)) {
        db_function(Fast_Parser_defineVariable_o)->returnType = db_resolve_ext(Fast_Parser_defineVariable_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::Parser::defineVariable(Variable object).returnType");
        db_function(Fast_Parser_defineVariable_o)->returnsReference = FALSE;
        Fast_Parser_defineVariable_o->virtual = FALSE;
        
        /* Bind Fast_Parser_defineVariable_o with C-function */
        db_function(Fast_Parser_defineVariable_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Parser_defineVariable(void *args, void *result);
        db_function(Fast_Parser_defineVariable_o)->impl = (db_word)__Fast_Parser_defineVariable;
        if (db_define(Fast_Parser_defineVariable_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::defineVariable(Variable object)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::popScope(Fast::Variable previous) */
    Fast_Parser_popScope_o = db_declare(Fast_Parser_o, "popScope(Fast::Variable previous)", db_typedef(db_method_o));
    if (!Fast_Parser_popScope_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::popScope(Fast::Variable previous)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::popScope(Fast::Variable previous) */
    if (!db_checkState(Fast_Parser_popScope_o, DB_DEFINED)) {
        db_function(Fast_Parser_popScope_o)->returnType = NULL;
        db_function(Fast_Parser_popScope_o)->returnsReference = FALSE;
        Fast_Parser_popScope_o->virtual = FALSE;
        
        /* Bind Fast_Parser_popScope_o with C-function */
        db_function(Fast_Parser_popScope_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Parser_popScope(void *args, void *result);
        db_function(Fast_Parser_popScope_o)->impl = (db_word)__Fast_Parser_popScope;
        if (db_define(Fast_Parser_popScope_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::popScope(Fast::Variable previous)'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::Parser::pushScope() */
    if (!db_checkState(Fast_Parser_pushScope_o, DB_DEFINED)) {
        db_function(Fast_Parser_pushScope_o)->returnType = db_resolve_ext(Fast_Parser_pushScope_o, NULL, "::hyve::Fast::Variable", FALSE, "element ::hyve::Fast::Parser::pushScope().returnType");
        db_function(Fast_Parser_pushScope_o)->returnsReference = FALSE;
        Fast_Parser_pushScope_o->virtual = FALSE;
        
        /* Bind Fast_Parser_pushScope_o with C-function */
        db_function(Fast_Parser_pushScope_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Parser_pushScope(void *args, void *result);
        db_function(Fast_Parser_pushScope_o)->impl = (db_word)__Fast_Parser_pushScope;
        if (db_define(Fast_Parser_pushScope_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::pushScope()'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::Parser::scope */
    if (!db_checkState(Fast_Parser_scope_o, DB_DEFINED)) {
        Fast_Parser_scope_o->type = db_resolve_ext(Fast_Parser_scope_o, NULL, "::hyve::Fast::Variable", FALSE, "element ::hyve::Fast::Parser::scope.type");
        Fast_Parser_scope_o->modifiers = 0x4;
        Fast_Parser_scope_o->state = 0x6;
        Fast_Parser_scope_o->weak = FALSE;
        Fast_Parser_scope_o->id = 7;
        if (db_define(Fast_Parser_scope_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::scope'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::ParserDeclaration::variable */
    if (!db_checkState(Fast_ParserDeclaration_variable_o, DB_DEFINED)) {
        Fast_ParserDeclaration_variable_o->type = db_resolve_ext(Fast_ParserDeclaration_variable_o, NULL, "::hyve::Fast::Variable", FALSE, "element ::hyve::Fast::ParserDeclaration::variable.type");
        Fast_ParserDeclaration_variable_o->modifiers = 0x0;
        Fast_ParserDeclaration_variable_o->state = 0x6;
        Fast_ParserDeclaration_variable_o->weak = FALSE;
        Fast_ParserDeclaration_variable_o->id = 1;
        if (db_define(Fast_ParserDeclaration_variable_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::ParserDeclaration::variable'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::ParserDeclaration */
    if (!db_checkState(Fast_ParserDeclaration_o, DB_DEFINED)) {
        db_type(Fast_ParserDeclaration_o)->defaultType = db_resolve_ext(Fast_ParserDeclaration_o, NULL, "::hyve::lang::member", FALSE, "element ::hyve::Fast::ParserDeclaration.defaultType");
        db_type(Fast_ParserDeclaration_o)->parentType = NULL;
        db_type(Fast_ParserDeclaration_o)->parentState = 0x0;
        db_interface(Fast_ParserDeclaration_o)->base = NULL;
        Fast_ParserDeclaration_o->baseAccess = 0x0;
        if (db_define(Fast_ParserDeclaration_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::ParserDeclaration'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::String::scope */
    if (!db_checkState(Fast_String_scope_o, DB_DEFINED)) {
        Fast_String_scope_o->type = db_resolve_ext(Fast_String_scope_o, NULL, "::hyve::Fast::Variable", FALSE, "element ::hyve::Fast::String::scope.type");
        Fast_String_scope_o->modifiers = 0x4;
        Fast_String_scope_o->state = 0x6;
        Fast_String_scope_o->weak = FALSE;
        Fast_String_scope_o->id = 3;
        if (db_define(Fast_String_scope_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::String::scope'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::String */
    if (!db_checkState(Fast_String_o, DB_DEFINED)) {
        db_type(Fast_String_o)->defaultType = db_resolve_ext(Fast_String_o, NULL, "::hyve::lang::member", FALSE, "element ::hyve::Fast::String.defaultType");
        db_type(Fast_String_o)->parentType = NULL;
        db_type(Fast_String_o)->parentState = 0x0;
        db_interface(Fast_String_o)->base = db_resolve_ext(Fast_String_o, NULL, "::hyve::Fast::Literal", FALSE, "element ::hyve::Fast::String.base");
        db_struct(Fast_String_o)->baseAccess = 0x4;
        Fast_String_o->implements.length = 0;
        Fast_String_o->implements.buffer = NULL;
        if (db_define(Fast_String_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::String'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::Parser::variables */
    if (!db_checkState(Fast_Parser_variables_o, DB_DEFINED)) {
        Fast_Parser_variables_o->type = db_resolve_ext(Fast_Parser_variables_o, NULL, "::hyve::lang::array{::hyve::Fast::Variable,64,::hyve::Fast::Variable}", FALSE, "element ::hyve::Fast::Parser::variables.type");
        Fast_Parser_variables_o->modifiers = 0x6;
        Fast_Parser_variables_o->state = 0x6;
        Fast_Parser_variables_o->weak = FALSE;
        Fast_Parser_variables_o->id = 22;
        if (db_define(Fast_Parser_variables_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::variables'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Wait::construct(Wait object) */
    Fast_Wait_construct_o = db_declare(Fast_Wait_o, "construct(Wait object)", db_typedef(db_callback_o));
    if (!Fast_Wait_construct_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Wait::construct(Wait object)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Wait::construct(Wait object) */
    if (!db_checkState(Fast_Wait_construct_o, DB_DEFINED)) {
        db_function(Fast_Wait_construct_o)->returnType = db_resolve_ext(Fast_Wait_construct_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::Wait::construct(Wait object).returnType");
        db_function(Fast_Wait_construct_o)->returnsReference = FALSE;
        Fast_Wait_construct_o->delegate = db_resolve_ext(Fast_Wait_construct_o, NULL, "::hyve::lang::class::construct(lang::object object)", FALSE, "element ::hyve::Fast::Wait::construct(Wait object).delegate");
        
        /* Bind Fast_Wait_construct_o with C-function */
        db_function(Fast_Wait_construct_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Wait_construct(void *args, void *result);
        db_function(Fast_Wait_construct_o)->impl = (db_word)__Fast_Wait_construct;
        if (db_define(Fast_Wait_construct_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Wait::construct(Wait object)'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::Wait::timeout */
    if (!db_checkState(Fast_Wait_timeout_o, DB_DEFINED)) {
        Fast_Wait_timeout_o->type = db_resolve_ext(Fast_Wait_timeout_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::Wait::timeout.type");
        Fast_Wait_timeout_o->modifiers = 0x0;
        Fast_Wait_timeout_o->state = 0x6;
        Fast_Wait_timeout_o->weak = FALSE;
        Fast_Wait_timeout_o->id = 1;
        if (db_define(Fast_Wait_timeout_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Wait::timeout'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Wait::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
    Fast_Wait_toIc_o = db_declare(Fast_Wait_o, "toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)", db_typedef(db_virtual_o));
    if (!Fast_Wait_toIc_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Wait::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Wait::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
    if (!db_checkState(Fast_Wait_toIc_o, DB_DEFINED)) {
        db_function(Fast_Wait_toIc_o)->returnType = db_resolve_ext(Fast_Wait_toIc_o, NULL, "::hyve::lang::alias{\"db_ic\"}", FALSE, "element ::hyve::Fast::Wait::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored).returnType");
        db_function(Fast_Wait_toIc_o)->returnsReference = FALSE;
        db_method(Fast_Wait_toIc_o)->virtual = TRUE;
        
        /* Bind Fast_Wait_toIc_o with C-function */
        db_function(Fast_Wait_toIc_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Wait_toIc_v(void *args, void *result);
        db_function(Fast_Wait_toIc_o)->impl = (db_word)__Fast_Wait_toIc_v;
        if (db_define(Fast_Wait_toIc_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Wait::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::Wait */
    if (!db_checkState(Fast_Wait_o, DB_DEFINED)) {
        db_type(Fast_Wait_o)->defaultType = db_resolve_ext(Fast_Wait_o, NULL, "::hyve::lang::member", FALSE, "element ::hyve::Fast::Wait.defaultType");
        db_type(Fast_Wait_o)->parentType = NULL;
        db_type(Fast_Wait_o)->parentState = 0x0;
        db_interface(Fast_Wait_o)->base = db_resolve_ext(Fast_Wait_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::Wait.base");
        db_struct(Fast_Wait_o)->baseAccess = 0x4;
        Fast_Wait_o->implements.length = 0;
        Fast_Wait_o->implements.buffer = NULL;
        if (db_define(Fast_Wait_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Wait'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::While::condition */
    if (!db_checkState(Fast_While_condition_o, DB_DEFINED)) {
        Fast_While_condition_o->type = db_resolve_ext(Fast_While_condition_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::While::condition.type");
        Fast_While_condition_o->modifiers = 0x0;
        Fast_While_condition_o->state = 0x6;
        Fast_While_condition_o->weak = FALSE;
        Fast_While_condition_o->id = 0;
        if (db_define(Fast_While_condition_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::While::condition'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::DynamicInitializerFrame::expr */
    if (!db_checkState(Fast_DynamicInitializerFrame_expr_o, DB_DEFINED)) {
        Fast_DynamicInitializerFrame_expr_o->type = db_resolve_ext(Fast_DynamicInitializerFrame_expr_o, NULL, "::hyve::lang::array{::hyve::Fast::Expression,64,::hyve::Fast::Expression}", FALSE, "element ::hyve::Fast::DynamicInitializerFrame::expr.type");
        Fast_DynamicInitializerFrame_expr_o->modifiers = 0x0;
        Fast_DynamicInitializerFrame_expr_o->state = 0x6;
        Fast_DynamicInitializerFrame_expr_o->weak = FALSE;
        Fast_DynamicInitializerFrame_expr_o->id = 0;
        if (db_define(Fast_DynamicInitializerFrame_expr_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::DynamicInitializerFrame::expr'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::DynamicInitializerFrame::keyExpr */
    if (!db_checkState(Fast_DynamicInitializerFrame_keyExpr_o, DB_DEFINED)) {
        Fast_DynamicInitializerFrame_keyExpr_o->type = db_resolve_ext(Fast_DynamicInitializerFrame_keyExpr_o, NULL, "::hyve::lang::array{::hyve::Fast::Expression,64,::hyve::Fast::Expression}", FALSE, "element ::hyve::Fast::DynamicInitializerFrame::keyExpr.type");
        Fast_DynamicInitializerFrame_keyExpr_o->modifiers = 0x0;
        Fast_DynamicInitializerFrame_keyExpr_o->state = 0x6;
        Fast_DynamicInitializerFrame_keyExpr_o->weak = FALSE;
        Fast_DynamicInitializerFrame_keyExpr_o->id = 1;
        if (db_define(Fast_DynamicInitializerFrame_keyExpr_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::DynamicInitializerFrame::keyExpr'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::DynamicInitializerFrame */
    if (!db_checkState(Fast_DynamicInitializerFrame_o, DB_DEFINED)) {
        db_type(Fast_DynamicInitializerFrame_o)->defaultType = db_resolve_ext(Fast_DynamicInitializerFrame_o, NULL, "::hyve::lang::member", FALSE, "element ::hyve::Fast::DynamicInitializerFrame.defaultType");
        db_type(Fast_DynamicInitializerFrame_o)->parentType = NULL;
        db_type(Fast_DynamicInitializerFrame_o)->parentState = 0x0;
        db_interface(Fast_DynamicInitializerFrame_o)->base = NULL;
        Fast_DynamicInitializerFrame_o->baseAccess = 0x0;
        if (db_define(Fast_DynamicInitializerFrame_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::DynamicInitializerFrame'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::DynamicInitializer::frames */
    if (!db_checkState(Fast_DynamicInitializer_frames_o, DB_DEFINED)) {
        Fast_DynamicInitializer_frames_o->type = db_resolve_ext(Fast_DynamicInitializer_frames_o, NULL, "::hyve::lang::array{::hyve::Fast::DynamicInitializerFrame,64,::hyve::Fast::DynamicInitializerFrame}", FALSE, "element ::hyve::Fast::DynamicInitializer::frames.type");
        Fast_DynamicInitializer_frames_o->modifiers = 0x3;
        Fast_DynamicInitializer_frames_o->state = 0x6;
        Fast_DynamicInitializer_frames_o->weak = FALSE;
        Fast_DynamicInitializer_frames_o->id = 1;
        if (db_define(Fast_DynamicInitializer_frames_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::DynamicInitializer::frames'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::DynamicInitializer */
    if (!db_checkState(Fast_DynamicInitializer_o, DB_DEFINED)) {
        db_type(Fast_DynamicInitializer_o)->defaultType = db_resolve_ext(Fast_DynamicInitializer_o, NULL, "::hyve::lang::member", FALSE, "element ::hyve::Fast::DynamicInitializer.defaultType");
        db_type(Fast_DynamicInitializer_o)->parentType = NULL;
        db_type(Fast_DynamicInitializer_o)->parentState = 0x0;
        db_interface(Fast_DynamicInitializer_o)->base = db_resolve_ext(Fast_DynamicInitializer_o, NULL, "::hyve::Fast::Initializer", FALSE, "element ::hyve::Fast::DynamicInitializer.base");
        db_struct(Fast_DynamicInitializer_o)->baseAccess = 0x0;
        Fast_DynamicInitializer_o->implements.length = 0;
        Fast_DynamicInitializer_o->implements.buffer = NULL;
        if (db_define(Fast_DynamicInitializer_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::DynamicInitializer'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::If::construct(If object) */
    Fast_If_construct_o = db_declare(Fast_If_o, "construct(If object)", db_typedef(db_callback_o));
    if (!Fast_If_construct_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::If::construct(If object)'.");
        goto error;
    }

    /* Define ::hyve::Fast::If::construct(If object) */
    if (!db_checkState(Fast_If_construct_o, DB_DEFINED)) {
        db_function(Fast_If_construct_o)->returnType = db_resolve_ext(Fast_If_construct_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::If::construct(If object).returnType");
        db_function(Fast_If_construct_o)->returnsReference = FALSE;
        Fast_If_construct_o->delegate = db_resolve_ext(Fast_If_construct_o, NULL, "::hyve::lang::class::construct(lang::object object)", FALSE, "element ::hyve::Fast::If::construct(If object).delegate");
        
        /* Bind Fast_If_construct_o with C-function */
        db_function(Fast_If_construct_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_If_construct(void *args, void *result);
        db_function(Fast_If_construct_o)->impl = (db_word)__Fast_If_construct;
        if (db_define(Fast_If_construct_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::If::construct(If object)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::If::noWarnUnreachable() */
    Fast_If_noWarnUnreachable_o = db_declare(Fast_If_o, "noWarnUnreachable()", db_typedef(db_method_o));
    if (!Fast_If_noWarnUnreachable_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::If::noWarnUnreachable()'.");
        goto error;
    }

    /* Define ::hyve::Fast::If::noWarnUnreachable() */
    if (!db_checkState(Fast_If_noWarnUnreachable_o, DB_DEFINED)) {
        db_function(Fast_If_noWarnUnreachable_o)->returnType = NULL;
        db_function(Fast_If_noWarnUnreachable_o)->returnsReference = FALSE;
        Fast_If_noWarnUnreachable_o->virtual = FALSE;
        
        /* Bind Fast_If_noWarnUnreachable_o with C-function */
        db_function(Fast_If_noWarnUnreachable_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_If_noWarnUnreachable(void *args, void *result);
        db_function(Fast_If_noWarnUnreachable_o)->impl = (db_word)__Fast_If_noWarnUnreachable;
        if (db_define(Fast_If_noWarnUnreachable_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::If::noWarnUnreachable()'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::If::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
    Fast_If_toIc_o = db_declare(Fast_If_o, "toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)", db_typedef(db_virtual_o));
    if (!Fast_If_toIc_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::If::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)'.");
        goto error;
    }

    /* Define ::hyve::Fast::If::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
    if (!db_checkState(Fast_If_toIc_o, DB_DEFINED)) {
        db_function(Fast_If_toIc_o)->returnType = db_resolve_ext(Fast_If_toIc_o, NULL, "::hyve::lang::alias{\"db_ic\"}", FALSE, "element ::hyve::Fast::If::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored).returnType");
        db_function(Fast_If_toIc_o)->returnsReference = FALSE;
        db_method(Fast_If_toIc_o)->virtual = TRUE;
        
        /* Bind Fast_If_toIc_o with C-function */
        db_function(Fast_If_toIc_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_If_toIc_v(void *args, void *result);
        db_function(Fast_If_toIc_o)->impl = (db_word)__Fast_If_toIc_v;
        if (db_define(Fast_If_toIc_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::If::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::If */
    if (!db_checkState(Fast_If_o, DB_DEFINED)) {
        db_type(Fast_If_o)->defaultType = db_resolve_ext(Fast_If_o, NULL, "::hyve::lang::member", FALSE, "element ::hyve::Fast::If.defaultType");
        db_type(Fast_If_o)->parentType = NULL;
        db_type(Fast_If_o)->parentState = 0x0;
        db_interface(Fast_If_o)->base = db_resolve_ext(Fast_If_o, NULL, "::hyve::Fast::Node", FALSE, "element ::hyve::Fast::If.base");
        db_struct(Fast_If_o)->baseAccess = 0x4;
        Fast_If_o->implements.length = 0;
        Fast_If_o->implements.buffer = NULL;
        if (db_define(Fast_If_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::If'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::ifStatement(Fast::Expression condition,Fast::Block trueBranch,Fast::If falseBranch) */
    Fast_Parser_ifStatement_o = db_declare(Fast_Parser_o, "ifStatement(Fast::Expression condition,Fast::Block trueBranch,Fast::If falseBranch)", db_typedef(db_method_o));
    if (!Fast_Parser_ifStatement_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::ifStatement(Fast::Expression condition,Fast::Block trueBranch,Fast::If falseBranch)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::ifStatement(Fast::Expression condition,Fast::Block trueBranch,Fast::If falseBranch) */
    if (!db_checkState(Fast_Parser_ifStatement_o, DB_DEFINED)) {
        db_function(Fast_Parser_ifStatement_o)->returnType = db_resolve_ext(Fast_Parser_ifStatement_o, NULL, "::hyve::Fast::Node", FALSE, "element ::hyve::Fast::Parser::ifStatement(Fast::Expression condition,Fast::Block trueBranch,Fast::If falseBranch).returnType");
        db_function(Fast_Parser_ifStatement_o)->returnsReference = FALSE;
        Fast_Parser_ifStatement_o->virtual = FALSE;
        
        /* Bind Fast_Parser_ifStatement_o with C-function */
        db_function(Fast_Parser_ifStatement_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Parser_ifStatement(void *args, void *result);
        db_function(Fast_Parser_ifStatement_o)->impl = (db_word)__Fast_Parser_ifStatement;
        if (db_define(Fast_Parser_ifStatement_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::ifStatement(Fast::Expression condition,Fast::Block trueBranch,Fast::If falseBranch)'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::TernaryExpr::ifstmt */
    if (!db_checkState(Fast_TernaryExpr_ifstmt_o, DB_DEFINED)) {
        Fast_TernaryExpr_ifstmt_o->type = db_resolve_ext(Fast_TernaryExpr_ifstmt_o, NULL, "::hyve::Fast::If", FALSE, "element ::hyve::Fast::TernaryExpr::ifstmt.type");
        Fast_TernaryExpr_ifstmt_o->modifiers = 0x3;
        Fast_TernaryExpr_ifstmt_o->state = 0x6;
        Fast_TernaryExpr_ifstmt_o->weak = FALSE;
        Fast_TernaryExpr_ifstmt_o->id = 6;
        if (db_define(Fast_TernaryExpr_ifstmt_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::TernaryExpr::ifstmt'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::TernaryExpr */
    if (!db_checkState(Fast_TernaryExpr_o, DB_DEFINED)) {
        db_type(Fast_TernaryExpr_o)->defaultType = db_resolve_ext(Fast_TernaryExpr_o, NULL, "::hyve::lang::member", FALSE, "element ::hyve::Fast::TernaryExpr.defaultType");
        db_type(Fast_TernaryExpr_o)->parentType = NULL;
        db_type(Fast_TernaryExpr_o)->parentState = 0x0;
        db_interface(Fast_TernaryExpr_o)->base = db_resolve_ext(Fast_TernaryExpr_o, NULL, "::hyve::Fast::Expression", FALSE, "element ::hyve::Fast::TernaryExpr.base");
        db_struct(Fast_TernaryExpr_o)->baseAccess = 0x4;
        Fast_TernaryExpr_o->implements.length = 0;
        Fast_TernaryExpr_o->implements.buffer = NULL;
        if (db_define(Fast_TernaryExpr_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::TernaryExpr'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Parser::addStatement(Fast::Node statement) */
    Fast_Parser_addStatement_o = db_declare(Fast_Parser_o, "addStatement(Fast::Node statement)", db_typedef(db_method_o));
    if (!Fast_Parser_addStatement_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Parser::addStatement(Fast::Node statement)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Parser::addStatement(Fast::Node statement) */
    if (!db_checkState(Fast_Parser_addStatement_o, DB_DEFINED)) {
        db_function(Fast_Parser_addStatement_o)->returnType = NULL;
        db_function(Fast_Parser_addStatement_o)->returnsReference = FALSE;
        Fast_Parser_addStatement_o->virtual = FALSE;
        
        /* Bind Fast_Parser_addStatement_o with C-function */
        db_function(Fast_Parser_addStatement_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Parser_addStatement(void *args, void *result);
        db_function(Fast_Parser_addStatement_o)->impl = (db_word)__Fast_Parser_addStatement;
        if (db_define(Fast_Parser_addStatement_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser::addStatement(Fast::Node statement)'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::Parser */
    if (!db_checkState(Fast_Parser_o, DB_DEFINED)) {
        db_type(Fast_Parser_o)->defaultType = db_resolve_ext(Fast_Parser_o, NULL, "::hyve::lang::member", FALSE, "element ::hyve::Fast::Parser.defaultType");
        db_type(Fast_Parser_o)->parentType = NULL;
        db_type(Fast_Parser_o)->parentState = 0x0;
        db_interface(Fast_Parser_o)->base = NULL;
        db_struct(Fast_Parser_o)->baseAccess = 0x0;
        Fast_Parser_o->implements.length = 0;
        Fast_Parser_o->implements.buffer = NULL;
        if (db_define(Fast_Parser_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Parser'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Update::construct(Update object) */
    Fast_Update_construct_o = db_declare(Fast_Update_o, "construct(Update object)", db_typedef(db_callback_o));
    if (!Fast_Update_construct_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Update::construct(Update object)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Update::construct(Update object) */
    if (!db_checkState(Fast_Update_construct_o, DB_DEFINED)) {
        db_function(Fast_Update_construct_o)->returnType = db_resolve_ext(Fast_Update_construct_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::Update::construct(Update object).returnType");
        db_function(Fast_Update_construct_o)->returnsReference = FALSE;
        Fast_Update_construct_o->delegate = db_resolve_ext(Fast_Update_construct_o, NULL, "::hyve::lang::class::construct(lang::object object)", FALSE, "element ::hyve::Fast::Update::construct(Update object).delegate");
        
        /* Bind Fast_Update_construct_o with C-function */
        db_function(Fast_Update_construct_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Update_construct(void *args, void *result);
        db_function(Fast_Update_construct_o)->impl = (db_word)__Fast_Update_construct;
        if (db_define(Fast_Update_construct_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Update::construct(Update object)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::Update::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
    Fast_Update_toIc_o = db_declare(Fast_Update_o, "toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)", db_typedef(db_virtual_o));
    if (!Fast_Update_toIc_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::Update::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)'.");
        goto error;
    }

    /* Define ::hyve::Fast::Update::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
    if (!db_checkState(Fast_Update_toIc_o, DB_DEFINED)) {
        db_function(Fast_Update_toIc_o)->returnType = db_resolve_ext(Fast_Update_toIc_o, NULL, "::hyve::lang::alias{\"db_ic\"}", FALSE, "element ::hyve::Fast::Update::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored).returnType");
        db_function(Fast_Update_toIc_o)->returnsReference = FALSE;
        db_method(Fast_Update_toIc_o)->virtual = TRUE;
        
        /* Bind Fast_Update_toIc_o with C-function */
        db_function(Fast_Update_toIc_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_Update_toIc_v(void *args, void *result);
        db_function(Fast_Update_toIc_o)->impl = (db_word)__Fast_Update_toIc_v;
        if (db_define(Fast_Update_toIc_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Update::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::Update */
    if (!db_checkState(Fast_Update_o, DB_DEFINED)) {
        db_type(Fast_Update_o)->defaultType = db_resolve_ext(Fast_Update_o, NULL, "::hyve::lang::member", FALSE, "element ::hyve::Fast::Update.defaultType");
        db_type(Fast_Update_o)->parentType = NULL;
        db_type(Fast_Update_o)->parentState = 0x0;
        db_interface(Fast_Update_o)->base = db_resolve_ext(Fast_Update_o, NULL, "::hyve::Fast::Node", FALSE, "element ::hyve::Fast::Update.base");
        db_struct(Fast_Update_o)->baseAccess = 0x4;
        Fast_Update_o->implements.length = 0;
        Fast_Update_o->implements.buffer = NULL;
        if (db_define(Fast_Update_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::Update'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::While::construct(While object) */
    Fast_While_construct_o = db_declare(Fast_While_o, "construct(While object)", db_typedef(db_callback_o));
    if (!Fast_While_construct_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::While::construct(While object)'.");
        goto error;
    }

    /* Define ::hyve::Fast::While::construct(While object) */
    if (!db_checkState(Fast_While_construct_o, DB_DEFINED)) {
        db_function(Fast_While_construct_o)->returnType = db_resolve_ext(Fast_While_construct_o, NULL, "::hyve::lang::int16", FALSE, "element ::hyve::Fast::While::construct(While object).returnType");
        db_function(Fast_While_construct_o)->returnsReference = FALSE;
        Fast_While_construct_o->delegate = db_resolve_ext(Fast_While_construct_o, NULL, "::hyve::lang::class::construct(lang::object object)", FALSE, "element ::hyve::Fast::While::construct(While object).delegate");
        
        /* Bind Fast_While_construct_o with C-function */
        db_function(Fast_While_construct_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_While_construct(void *args, void *result);
        db_function(Fast_While_construct_o)->impl = (db_word)__Fast_While_construct;
        if (db_define(Fast_While_construct_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::While::construct(While object)'.");
            goto error;
        }
    }
    /* Declare ::hyve::Fast::While::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
    Fast_While_toIc_o = db_declare(Fast_While_o, "toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)", db_typedef(db_virtual_o));
    if (!Fast_While_toIc_o) {
        db_error("Fast_load: failed to declare object '::hyve::Fast::While::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)'.");
        goto error;
    }

    /* Define ::hyve::Fast::While::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
    if (!db_checkState(Fast_While_toIc_o, DB_DEFINED)) {
        db_function(Fast_While_toIc_o)->returnType = db_resolve_ext(Fast_While_toIc_o, NULL, "::hyve::lang::alias{\"db_ic\"}", FALSE, "element ::hyve::Fast::While::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored).returnType");
        db_function(Fast_While_toIc_o)->returnsReference = FALSE;
        db_method(Fast_While_toIc_o)->virtual = TRUE;
        
        /* Bind Fast_While_toIc_o with C-function */
        db_function(Fast_While_toIc_o)->kind = DB_PROCEDURE_CDECL;
        void __Fast_While_toIc_v(void *args, void *result);
        db_function(Fast_While_toIc_o)->impl = (db_word)__Fast_While_toIc_v;
        if (db_define(Fast_While_toIc_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::While::toIc(lang::alias{\"db_icProgram\"} program,lang::alias{\"db_icStorage\"} storage,lang::bool stored)'.");
            goto error;
        }
    }
    /* Define ::hyve::Fast::While */
    if (!db_checkState(Fast_While_o, DB_DEFINED)) {
        db_type(Fast_While_o)->defaultType = db_resolve_ext(Fast_While_o, NULL, "::hyve::lang::member", FALSE, "element ::hyve::Fast::While.defaultType");
        db_type(Fast_While_o)->parentType = NULL;
        db_type(Fast_While_o)->parentState = 0x0;
        db_interface(Fast_While_o)->base = db_resolve_ext(Fast_While_o, NULL, "::hyve::Fast::Node", FALSE, "element ::hyve::Fast::While.base");
        db_struct(Fast_While_o)->baseAccess = 0x4;
        Fast_While_o->implements.length = 0;
        Fast_While_o->implements.buffer = NULL;
        if (db_define(Fast_While_o)) {
            db_error("Fast_load: failed to define object '::hyve::Fast::While'.");
            goto error;
        }
    }
    if (_a_) {
        db_free(_a_);
    }

    return 0;
error:
    return -1;
}
