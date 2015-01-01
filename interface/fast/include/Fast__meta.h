/* Fast__meta.h
 *
 * Loads objects in database.
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_META_H
#define Fast_META_H

#include "cortex.h"

#include "Fast__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::cortex */
extern cx_object _o;

/* ::cortex::Fast */
extern cx_void (*Fast_o);

/* ::cortex::Fast::BinaryExpr */
extern cx_class Fast_BinaryExpr_o;

/* ::cortex::Fast::BinaryExpr::construct(Fast::BinaryExpr object) */
extern cx_callback Fast_BinaryExpr_construct_o;

/* ::cortex::Fast::BinaryExpr::fold() */
extern cx_method Fast_BinaryExpr_fold_o;

/* ::cortex::Fast::BinaryExpr::hasSideEffects() */
extern cx_virtual Fast_BinaryExpr_hasSideEffects_o;

/* ::cortex::Fast::BinaryExpr::lvalue */
extern cx_member Fast_BinaryExpr_lvalue_o;

/* ::cortex::Fast::BinaryExpr::operator */
extern cx_member Fast_BinaryExpr_operator_o;

/* ::cortex::Fast::BinaryExpr::rvalue */
extern cx_member Fast_BinaryExpr_rvalue_o;

/* ::cortex::Fast::BinaryExpr::setOperator(lang::operatorKind kind) */
extern cx_method Fast_BinaryExpr_setOperator_o;

/* ::cortex::Fast::BinaryExpr::toIc(lang::alias{"cx_icProgram"} program,lang::alias{"cx_icStorage"} storage,lang::bool stored) */
extern cx_virtual Fast_BinaryExpr_toIc_o;

/* ::cortex::Fast::Binding */
extern cx_struct Fast_Binding_o;

/* ::cortex::Fast::Binding::function */
extern cx_member Fast_Binding_function_o;

/* ::cortex::Fast::Binding::impl */
extern cx_member Fast_Binding_impl_o;

/* ::cortex::Fast::Block */
extern cx_class Fast_Block_o;

/* ::cortex::Fast::Block::addStatement(Fast::Node statement) */
extern cx_method Fast_Block_addStatement_o;

/* ::cortex::Fast::Block::declare(lang::string id,Fast::Variable type,lang::bool isParameter,bool isReference) */
extern cx_method Fast_Block_declare_o;

/* ::cortex::Fast::Block::declareReturnVariable(lang::function function) */
extern cx_method Fast_Block_declareReturnVariable_o;

/* ::cortex::Fast::Block::declareTemplate(lang::string id,Fast::Variable type,lang::bool isParameter,bool isReference) */
extern cx_method Fast_Block_declareTemplate_o;

/* ::cortex::Fast::Block::function */
extern cx_member Fast_Block_function_o;

/* ::cortex::Fast::Block::locals */
extern cx_member Fast_Block_locals_o;

/* ::cortex::Fast::Block::lookup(lang::string id) */
extern cx_method Fast_Block_lookup_o;

/* ::cortex::Fast::Block::lookupLocal(lang::string id) */
extern cx_method Fast_Block_lookupLocal_o;

/* ::cortex::Fast::Block::parent */
extern cx_member Fast_Block_parent_o;

/* ::cortex::Fast::Block::resolve(lang::string id) */
extern cx_method Fast_Block_resolve_o;

/* ::cortex::Fast::Block::resolveLocal(lang::string id) */
extern cx_method Fast_Block_resolveLocal_o;

/* ::cortex::Fast::Block::setFunction(lang::function function */
extern cx_method Fast_Block_setFunction_o;

/* ::cortex::Fast::Block::statements */
extern cx_member Fast_Block_statements_o;

/* ::cortex::Fast::Block::toIc(lang::alias{"cx_icProgram"} program,lang::alias{"cx_icStorage"} storage,lang::bool stored) */
extern cx_virtual Fast_Block_toIc_o;

/* ::cortex::Fast::Block::toIcBody(lang::alias{"cx_icProgram"} program,lang::alias{"cx_icStorage"} storage,lang::bool stored) */
extern cx_virtual Fast_Block_toIcBody_o;

/* ::cortex::Fast::Block::while */
extern cx_member Fast_Block_while_o;

/* ::cortex::Fast::Boolean */
extern cx_class Fast_Boolean_o;

/* ::cortex::Fast::Boolean::init(Boolean object) */
extern cx_callback Fast_Boolean_init_o;

/* ::cortex::Fast::Boolean::serialize(lang::type dstType,lang::word dst) */
extern cx_method Fast_Boolean_serialize_o;

/* ::cortex::Fast::Boolean::toIc(lang::alias{"cx_icProgram"} program,lang::alias{"cx_icStorage"} storage,lang::bool stored) */
extern cx_virtual Fast_Boolean_toIc_o;

/* ::cortex::Fast::Boolean::value */
extern cx_member Fast_Boolean_value_o;

/* ::cortex::Fast::Call */
extern cx_class Fast_Call_o;

/* ::cortex::Fast::Call::arguments */
extern cx_member Fast_Call_arguments_o;

/* ::cortex::Fast::Call::construct(Fast::Call object) */
extern cx_callback Fast_Call_construct_o;

/* ::cortex::Fast::Call::functionExpr */
extern cx_member Fast_Call_functionExpr_o;

/* ::cortex::Fast::Call::hasSideEffects() */
extern cx_virtual Fast_Call_hasSideEffects_o;

/* ::cortex::Fast::Call::instanceExpr */
extern cx_member Fast_Call_instanceExpr_o;

/* ::cortex::Fast::Call::instanceIsAny */
extern cx_member Fast_Call_instanceIsAny_o;

/* ::cortex::Fast::Call::overloaded */
extern cx_member Fast_Call_overloaded_o;

/* ::cortex::Fast::Call::parameters */
extern cx_member Fast_Call_parameters_o;

/* ::cortex::Fast::Call::returnsReference */
extern cx_member Fast_Call_returnsReference_o;

/* ::cortex::Fast::Call::returnType */
extern cx_member Fast_Call_returnType_o;

/* ::cortex::Fast::Call::setParameters(lang::function function) */
extern cx_method Fast_Call_setParameters_o;

/* ::cortex::Fast::Call::toIc(lang::alias{"cx_icProgram"} program,lang::alias{"cx_icStorage"} storage,lang::bool stored) */
extern cx_virtual Fast_Call_toIc_o;

/* ::cortex::Fast::CallBuilder */
extern cx_struct Fast_CallBuilder_o;

/* ::cortex::Fast::CallBuilder::arguments */
extern cx_member Fast_CallBuilder_arguments_o;

/* ::cortex::Fast::CallBuilder::block */
extern cx_member Fast_CallBuilder_block_o;

/* ::cortex::Fast::CallBuilder::build() */
extern cx_method Fast_CallBuilder_build_o;

/* ::cortex::Fast::CallBuilder::buildSignature() */
extern cx_method Fast_CallBuilder_buildSignature_o;

/* ::cortex::Fast::CallBuilder::instance */
extern cx_member Fast_CallBuilder_instance_o;

/* ::cortex::Fast::CallBuilder::name */
extern cx_member Fast_CallBuilder_name_o;

/* ::cortex::Fast::CallBuilder::overloaded */
extern cx_member Fast_CallBuilder_overloaded_o;

/* ::cortex::Fast::CallBuilder::scope */
extern cx_member Fast_CallBuilder_scope_o;

/* ::cortex::Fast::CallBuilder::signature */
extern cx_member Fast_CallBuilder_signature_o;

/* ::cortex::Fast::CastExpr */
extern cx_class Fast_CastExpr_o;

/* ::cortex::Fast::CastExpr::construct(Fast::CastExpr object) */
extern cx_callback Fast_CastExpr_construct_o;

/* ::cortex::Fast::CastExpr::lvalue */
extern cx_member Fast_CastExpr_lvalue_o;

/* ::cortex::Fast::CastExpr::rvalue */
extern cx_member Fast_CastExpr_rvalue_o;

/* ::cortex::Fast::CastExpr::toIc(lang::alias{"cx_icProgram"} program,lang::alias{"cx_icStorage"} storage,lang::bool stored) */
extern cx_virtual Fast_CastExpr_toIc_o;

/* ::cortex::Fast::Character */
extern cx_class Fast_Character_o;

/* ::cortex::Fast::Character::init(Character object) */
extern cx_callback Fast_Character_init_o;

/* ::cortex::Fast::Character::serialize(lang::type dstType,lang::word dst) */
extern cx_method Fast_Character_serialize_o;

/* ::cortex::Fast::Character::toIc(lang::alias{"cx_icProgram"} program,lang::alias{"cx_icStorage"} storage,lang::bool stored) */
extern cx_virtual Fast_Character_toIc_o;

/* ::cortex::Fast::Character::value */
extern cx_member Fast_Character_value_o;

/* ::cortex::Fast::CommaExpr */
extern cx_class Fast_CommaExpr_o;

/* ::cortex::Fast::CommaExpr::addExpression(Expression expr) */
extern cx_method Fast_CommaExpr_addExpression_o;

/* ::cortex::Fast::CommaExpr::addOrCreate(Expression list,Expression expr) */
extern cx_function Fast_CommaExpr_addOrCreate_o;

/* ::cortex::Fast::CommaExpr::construct(CommaExpr object) */
extern cx_callback Fast_CommaExpr_construct_o;

/* ::cortex::Fast::CommaExpr::expressions */
extern cx_member Fast_CommaExpr_expressions_o;

/* ::cortex::Fast::CommaExpr::hasSideEffects() */
extern cx_virtual Fast_CommaExpr_hasSideEffects_o;

/* ::cortex::Fast::CommaExpr::init(CommaExpr object) */
extern cx_callback Fast_CommaExpr_init_o;

/* ::cortex::Fast::CommaExpr::toIc(lang::alias{"cx_icProgram"} program,lang::alias{"cx_icStorage"} storage,lang::bool stored) */
extern cx_virtual Fast_CommaExpr_toIc_o;

/* ::cortex::Fast::CommaExpr::toList() */
extern cx_method Fast_CommaExpr_toList_o;

/* ::cortex::Fast::Define */
extern cx_class Fast_Define_o;

/* ::cortex::Fast::Define::construct(Fast::Define object) */
extern cx_callback Fast_Define_construct_o;

/* ::cortex::Fast::Define::object */
extern cx_member Fast_Define_object_o;

/* ::cortex::Fast::Define::toIc(lang::alias{"cx_icProgram"} program,lang::alias{"cx_icStorage"} storage,lang::bool stored) */
extern cx_virtual Fast_Define_toIc_o;

/* ::cortex::Fast::DelegateCall */
extern cx_class Fast_DelegateCall_o;

/* ::cortex::Fast::DelegateCall::construct(Fast::StaticCall object) */
extern cx_callback Fast_DelegateCall_construct_o;

/* ::cortex::Fast::DelegateCall::expr */
extern cx_member Fast_DelegateCall_expr_o;

/* ::cortex::Fast::DynamicInitializer */
extern cx_class Fast_DynamicInitializer_o;

/* ::cortex::Fast::DynamicInitializer::assignValue */
extern cx_member Fast_DynamicInitializer_assignValue_o;

/* ::cortex::Fast::DynamicInitializer::construct(DynamicInitializer object) */
extern cx_callback Fast_DynamicInitializer_construct_o;

/* ::cortex::Fast::DynamicInitializer::define() */
extern cx_method Fast_DynamicInitializer_define_o;

/* ::cortex::Fast::DynamicInitializer::frames */
extern cx_member Fast_DynamicInitializer_frames_o;

/* ::cortex::Fast::DynamicInitializer::pop() */
extern cx_method Fast_DynamicInitializer_pop_o;

/* ::cortex::Fast::DynamicInitializer::push() */
extern cx_method Fast_DynamicInitializer_push_o;

/* ::cortex::Fast::DynamicInitializer::value(Expression v) */
extern cx_method Fast_DynamicInitializer_value_o;

/* ::cortex::Fast::DynamicInitializerFrame */
extern cx_struct Fast_DynamicInitializerFrame_o;

/* ::cortex::Fast::DynamicInitializerFrame::expr */
extern cx_member Fast_DynamicInitializerFrame_expr_o;

/* ::cortex::Fast::DynamicInitializerFrame::keyExpr */
extern cx_member Fast_DynamicInitializerFrame_keyExpr_o;

/* ::cortex::Fast::DynamicInitializerFrame::sequenceSize */
extern cx_member Fast_DynamicInitializerFrame_sequenceSize_o;

/* ::cortex::Fast::ElementExpr */
extern cx_class Fast_ElementExpr_o;

/* ::cortex::Fast::ElementExpr::construct(Fast::MemberExpr object) */
extern cx_callback Fast_ElementExpr_construct_o;

/* ::cortex::Fast::ElementExpr::lvalue */
extern cx_member Fast_ElementExpr_lvalue_o;

/* ::cortex::Fast::ElementExpr::rvalue */
extern cx_member Fast_ElementExpr_rvalue_o;

/* ::cortex::Fast::ElementExpr::toIc(lang::alias{"cx_icProgram"} program,lang::alias{"cx_icStorage"} storage,lang::bool stored) */
extern cx_virtual Fast_ElementExpr_toIc_o;

/* ::cortex::Fast::Expression */
extern cx_class Fast_Expression_o;

/* ::cortex::Fast::Expression::cast(lang::type type) */
extern cx_method Fast_Expression_cast_o;

/* ::cortex::Fast::Expression::cleanList(list{Expression} list) */
extern cx_function Fast_Expression_cleanList_o;

/* ::cortex::Fast::Expression::fold() */
extern cx_virtual Fast_Expression_fold_o;

/* ::cortex::Fast::Expression::forceReference */
extern cx_member Fast_Expression_forceReference_o;

/* ::cortex::Fast::Expression::fromList(list{Expression} list) */
extern cx_function Fast_Expression_fromList_o;

/* ::cortex::Fast::Expression::getType() */
extern cx_method Fast_Expression_getType_o;

/* ::cortex::Fast::Expression::getType_expr(Expression target) */
extern cx_method Fast_Expression_getType_expr_o;

/* ::cortex::Fast::Expression::getType_type(lang::type target) */
extern cx_method Fast_Expression_getType_type_o;

/* ::cortex::Fast::Expression::getValue() */
extern cx_virtual Fast_Expression_getValue_o;

/* ::cortex::Fast::Expression::hasSideEffects() */
extern cx_virtual Fast_Expression_hasSideEffects_o;

/* ::cortex::Fast::Expression::init(Expression object) */
extern cx_callback Fast_Expression_init_o;

/* ::cortex::Fast::Expression::isReference */
extern cx_member Fast_Expression_isReference_o;

/* ::cortex::Fast::Expression::serialize(lang::type dstType,lang::word dst) */
extern cx_virtual Fast_Expression_serialize_o;

/* ::cortex::Fast::Expression::toList() */
extern cx_virtual Fast_Expression_toList_o;

/* ::cortex::Fast::Expression::type */
extern cx_member Fast_Expression_type_o;

/* ::cortex::Fast::FloatingPoint */
extern cx_class Fast_FloatingPoint_o;

/* ::cortex::Fast::FloatingPoint::init(FloatingPoint object) */
extern cx_callback Fast_FloatingPoint_init_o;

/* ::cortex::Fast::FloatingPoint::serialize(lang::type dstType,lang::word dst) */
extern cx_method Fast_FloatingPoint_serialize_o;

/* ::cortex::Fast::FloatingPoint::toIc(lang::alias{"cx_icProgram"} program,lang::alias{"cx_icStorage"} storage,lang::bool stored) */
extern cx_virtual Fast_FloatingPoint_toIc_o;

/* ::cortex::Fast::FloatingPoint::value */
extern cx_member Fast_FloatingPoint_value_o;

/* ::cortex::Fast::If */
extern cx_class Fast_If_o;

/* ::cortex::Fast::If::condition */
extern cx_member Fast_If_condition_o;

/* ::cortex::Fast::If::construct(If object) */
extern cx_callback Fast_If_construct_o;

/* ::cortex::Fast::If::falseBranch */
extern cx_member Fast_If_falseBranch_o;

/* ::cortex::Fast::If::noWarnUnreachable() */
extern cx_method Fast_If_noWarnUnreachable_o;

/* ::cortex::Fast::If::toIc(lang::alias{"cx_icProgram"} program,lang::alias{"cx_icStorage"} storage,lang::bool stored) */
extern cx_virtual Fast_If_toIc_o;

/* ::cortex::Fast::If::trueBranch */
extern cx_member Fast_If_trueBranch_o;

/* ::cortex::Fast::If::warnUnreachable */
extern cx_member Fast_If_warnUnreachable_o;

/* ::cortex::Fast::Initializer */
extern cx_class Fast_Initializer_o;

/* ::cortex::Fast::Initializer::construct(Initializer object) */
extern cx_callback Fast_Initializer_construct_o;

/* ::cortex::Fast::Initializer::currentType() */
extern cx_method Fast_Initializer_currentType_o;

/* ::cortex::Fast::Initializer::define() */
extern cx_virtual Fast_Initializer_define_o;

/* ::cortex::Fast::Initializer::fp */
extern cx_member Fast_Initializer_fp_o;

/* ::cortex::Fast::Initializer::frames */
extern cx_member Fast_Initializer_frames_o;

/* ::cortex::Fast::Initializer::initFrame() */
extern cx_method Fast_Initializer_initFrame_o;

/* ::cortex::Fast::Initializer::member(lang::string name) */
extern cx_virtual Fast_Initializer_member_o;

/* ::cortex::Fast::Initializer::next() */
extern cx_virtual Fast_Initializer_next_o;

/* ::cortex::Fast::Initializer::pop() */
extern cx_virtual Fast_Initializer_pop_o;

/* ::cortex::Fast::Initializer::popKey() */
extern cx_virtual Fast_Initializer_popKey_o;

/* ::cortex::Fast::Initializer::push() */
extern cx_virtual Fast_Initializer_push_o;

/* ::cortex::Fast::Initializer::pushKey() */
extern cx_virtual Fast_Initializer_pushKey_o;

/* ::cortex::Fast::Initializer::type() */
extern cx_method Fast_Initializer_type_o;

/* ::cortex::Fast::Initializer::value(Expression v) */
extern cx_virtual Fast_Initializer_value_o;

/* ::cortex::Fast::Initializer::valueKey(Expression key) */
extern cx_virtual Fast_Initializer_valueKey_o;

/* ::cortex::Fast::Initializer::variableCount */
extern cx_member Fast_Initializer_variableCount_o;

/* ::cortex::Fast::Initializer::variables */
extern cx_member Fast_Initializer_variables_o;

/* ::cortex::Fast::InitializerExpr */
extern cx_class Fast_InitializerExpr_o;

/* ::cortex::Fast::InitializerExpr::assignValue */
extern cx_member Fast_InitializerExpr_assignValue_o;

/* ::cortex::Fast::InitializerExpr::construct(InitializerExpr object) */
extern cx_callback Fast_InitializerExpr_construct_o;

/* ::cortex::Fast::InitializerExpr::define() */
extern cx_method Fast_InitializerExpr_define_o;

/* ::cortex::Fast::InitializerExpr::insert(Expression variable) */
extern cx_method Fast_InitializerExpr_insert_o;

/* ::cortex::Fast::InitializerExpr::member(lang::string name) */
extern cx_method Fast_InitializerExpr_member_o;

/* ::cortex::Fast::InitializerExpr::operations */
extern cx_member Fast_InitializerExpr_operations_o;

/* ::cortex::Fast::InitializerExpr::pop() */
extern cx_method Fast_InitializerExpr_pop_o;

/* ::cortex::Fast::InitializerExpr::push() */
extern cx_method Fast_InitializerExpr_push_o;

/* ::cortex::Fast::InitializerExpr::value(Expression v) */
extern cx_method Fast_InitializerExpr_value_o;

/* ::cortex::Fast::InitializerFrame */
extern cx_struct Fast_InitializerFrame_o;

/* ::cortex::Fast::InitializerFrame::isKey */
extern cx_member Fast_InitializerFrame_isKey_o;

/* ::cortex::Fast::InitializerFrame::location */
extern cx_member Fast_InitializerFrame_location_o;

/* ::cortex::Fast::InitializerFrame::member */
extern cx_member Fast_InitializerFrame_member_o;

/* ::cortex::Fast::InitializerFrame::type */
extern cx_member Fast_InitializerFrame_type_o;

/* ::cortex::Fast::InitializerKind */
extern cx_enum Fast_InitializerKind_o;

/* ::cortex::Fast::InitializerKind::InitDynamic */
extern cx_constant (*Fast_InitializerKind_InitDynamic_o);

/* ::cortex::Fast::InitializerKind::InitExpression */
extern cx_constant (*Fast_InitializerKind_InitExpression_o);

/* ::cortex::Fast::InitializerKind::InitStatic */
extern cx_constant (*Fast_InitializerKind_InitStatic_o);

/* ::cortex::Fast::InitializerVariable */
extern cx_struct Fast_InitializerVariable_o;

/* ::cortex::Fast::InitializerVariable::key */
extern cx_member Fast_InitializerVariable_key_o;

/* ::cortex::Fast::InitializerVariable::object */
extern cx_member Fast_InitializerVariable_object_o;

/* ::cortex::Fast::InitializerVariable::offset */
extern cx_member Fast_InitializerVariable_offset_o;

/* ::cortex::Fast::InitOper */
extern cx_struct Fast_InitOper_o;

/* ::cortex::Fast::InitOper::expr */
extern cx_member Fast_InitOper_expr_o;

/* ::cortex::Fast::InitOper::kind */
extern cx_member Fast_InitOper_kind_o;

/* ::cortex::Fast::InitOper::name */
extern cx_member Fast_InitOper_name_o;

/* ::cortex::Fast::InitOperKind */
extern cx_enum Fast_InitOperKind_o;

/* ::cortex::Fast::InitOperKind::InitDefine */
extern cx_constant (*Fast_InitOperKind_InitDefine_o);

/* ::cortex::Fast::InitOperKind::InitMember */
extern cx_constant (*Fast_InitOperKind_InitMember_o);

/* ::cortex::Fast::InitOperKind::InitPop */
extern cx_constant (*Fast_InitOperKind_InitPop_o);

/* ::cortex::Fast::InitOperKind::InitPush */
extern cx_constant (*Fast_InitOperKind_InitPush_o);

/* ::cortex::Fast::InitOperKind::InitValue */
extern cx_constant (*Fast_InitOperKind_InitValue_o);

/* ::cortex::Fast::Integer */
extern cx_class Fast_Integer_o;

/* ::cortex::Fast::Integer::init(Integer object) */
extern cx_callback Fast_Integer_init_o;

/* ::cortex::Fast::Integer::serialize(lang::type dstType,lang::word dst) */
extern cx_method Fast_Integer_serialize_o;

/* ::cortex::Fast::Integer::toIc(lang::alias{"cx_icProgram"} program,lang::alias{"cx_icStorage"} storage,lang::bool stored) */
extern cx_virtual Fast_Integer_toIc_o;

/* ::cortex::Fast::Integer::value */
extern cx_member Fast_Integer_value_o;

/* ::cortex::Fast::Literal */
extern cx_class Fast_Literal_o;

/* ::cortex::Fast::Literal::getValue() */
extern cx_virtual Fast_Literal_getValue_o;

/* ::cortex::Fast::Literal::init(Literal object) */
extern cx_callback Fast_Literal_init_o;

/* ::cortex::Fast::Literal::kind */
extern cx_member Fast_Literal_kind_o;

/* ::cortex::Fast::Local */
extern cx_class Fast_Local_o;

/* ::cortex::Fast::Local::construct(Local object) */
extern cx_callback Fast_Local_construct_o;

/* ::cortex::Fast::Local::isReference */
extern cx_member Fast_Local_isReference_o;

/* ::cortex::Fast::Local::kind */
extern cx_member Fast_Local_kind_o;

/* ::cortex::Fast::Local::name */
extern cx_member Fast_Local_name_o;

/* ::cortex::Fast::Local::toIc(lang::alias{"cx_icProgram"} program,lang::alias{"cx_icStorage"} storage,lang::bool stored) */
extern cx_virtual Fast_Local_toIc_o;

/* ::cortex::Fast::Local::type */
extern cx_member Fast_Local_type_o;

/* ::cortex::Fast::LocalKind */
extern cx_enum Fast_LocalKind_o;

/* ::cortex::Fast::LocalKind::LocalDefault */
extern cx_constant (*Fast_LocalKind_LocalDefault_o);

/* ::cortex::Fast::LocalKind::LocalParameter */
extern cx_constant (*Fast_LocalKind_LocalParameter_o);

/* ::cortex::Fast::LocalKind::LocalReturn */
extern cx_constant (*Fast_LocalKind_LocalReturn_o);

/* ::cortex::Fast::Lvalue */
extern cx_struct Fast_Lvalue_o;

/* ::cortex::Fast::Lvalue::expr */
extern cx_member Fast_Lvalue_expr_o;

/* ::cortex::Fast::Lvalue::isAssignment */
extern cx_member Fast_Lvalue_isAssignment_o;

/* ::cortex::Fast::MemberExpr */
extern cx_class Fast_MemberExpr_o;

/* ::cortex::Fast::MemberExpr::construct(Fast::MemberExpr object) */
extern cx_callback Fast_MemberExpr_construct_o;

/* ::cortex::Fast::MemberExpr::hasSideEffects() */
extern cx_virtual Fast_MemberExpr_hasSideEffects_o;

/* ::cortex::Fast::MemberExpr::lvalue */
extern cx_member Fast_MemberExpr_lvalue_o;

/* ::cortex::Fast::MemberExpr::member */
extern cx_member Fast_MemberExpr_member_o;

/* ::cortex::Fast::MemberExpr::rvalue */
extern cx_member Fast_MemberExpr_rvalue_o;

/* ::cortex::Fast::MemberExpr::superMember */
extern cx_member Fast_MemberExpr_superMember_o;

/* ::cortex::Fast::MemberExpr::toIc(lang::alias{"cx_icProgram"} program,lang::alias{"cx_icStorage"} storage,lang::bool stored) */
extern cx_virtual Fast_MemberExpr_toIc_o;

/* ::cortex::Fast::NewExpr */
extern cx_class Fast_NewExpr_o;

/* ::cortex::Fast::NewExpr::attributes */
extern cx_member Fast_NewExpr_attributes_o;

/* ::cortex::Fast::NewExpr::construct(Fast::NewExpr object) */
extern cx_callback Fast_NewExpr_construct_o;

/* ::cortex::Fast::NewExpr::hasSideEffects() */
extern cx_virtual Fast_NewExpr_hasSideEffects_o;

/* ::cortex::Fast::NewExpr::toIc(lang::alias{"cx_icProgram"} program,lang::alias{"cx_icStorage"} storage,lang::bool stored) */
extern cx_virtual Fast_NewExpr_toIc_o;

/* ::cortex::Fast::NewExpr::type */
extern cx_member Fast_NewExpr_type_o;

/* ::cortex::Fast::Node */
extern cx_class Fast_Node_o;

/* ::cortex::Fast::Node::column */
extern cx_member Fast_Node_column_o;

/* ::cortex::Fast::Node::init(Node object) */
extern cx_callback Fast_Node_init_o;

/* ::cortex::Fast::Node::kind */
extern cx_member Fast_Node_kind_o;

/* ::cortex::Fast::Node::line */
extern cx_member Fast_Node_line_o;

/* ::cortex::Fast::Node::toIc(lang::alias{"cx_icProgram"} program,lang::alias{"cx_icStorage"} storage,lang::bool stored) */
extern cx_virtual Fast_Node_toIc_o;

/* ::cortex::Fast::nodeKind */
extern cx_enum Fast_nodeKind_o;

/* ::cortex::Fast::nodeKind::Binary */
extern cx_constant (*Fast_nodeKind_Binary_o);

/* ::cortex::Fast::nodeKind::Call */
extern cx_constant (*Fast_nodeKind_Call_o);

/* ::cortex::Fast::nodeKind::Cast */
extern cx_constant (*Fast_nodeKind_Cast_o);

/* ::cortex::Fast::nodeKind::CommaExpr */
extern cx_constant (*Fast_nodeKind_CommaExpr_o);

/* ::cortex::Fast::nodeKind::Declaration */
extern cx_constant (*Fast_nodeKind_Declaration_o);

/* ::cortex::Fast::nodeKind::Declare */
extern cx_constant (*Fast_nodeKind_Declare_o);

/* ::cortex::Fast::nodeKind::Define */
extern cx_constant (*Fast_nodeKind_Define_o);

/* ::cortex::Fast::nodeKind::Element */
extern cx_constant (*Fast_nodeKind_Element_o);

/* ::cortex::Fast::nodeKind::If */
extern cx_constant (*Fast_nodeKind_If_o);

/* ::cortex::Fast::nodeKind::Initializer */
extern cx_constant (*Fast_nodeKind_Initializer_o);

/* ::cortex::Fast::nodeKind::Literal */
extern cx_constant (*Fast_nodeKind_Literal_o);

/* ::cortex::Fast::nodeKind::Member */
extern cx_constant (*Fast_nodeKind_Member_o);

/* ::cortex::Fast::nodeKind::Method */
extern cx_constant (*Fast_nodeKind_Method_o);

/* ::cortex::Fast::nodeKind::New */
extern cx_constant (*Fast_nodeKind_New_o);

/* ::cortex::Fast::nodeKind::Postfix */
extern cx_constant (*Fast_nodeKind_Postfix_o);

/* ::cortex::Fast::nodeKind::Ternary */
extern cx_constant (*Fast_nodeKind_Ternary_o);

/* ::cortex::Fast::nodeKind::Unary */
extern cx_constant (*Fast_nodeKind_Unary_o);

/* ::cortex::Fast::nodeKind::Update */
extern cx_constant (*Fast_nodeKind_Update_o);

/* ::cortex::Fast::nodeKind::Variable */
extern cx_constant (*Fast_nodeKind_Variable_o);

/* ::cortex::Fast::nodeKind::Wait */
extern cx_constant (*Fast_nodeKind_Wait_o);

/* ::cortex::Fast::nodeKind::While */
extern cx_constant (*Fast_nodeKind_While_o);

/* ::cortex::Fast::Null */
extern cx_class Fast_Null_o;

/* ::cortex::Fast::Null::init(Null object) */
extern cx_callback Fast_Null_init_o;

/* ::cortex::Fast::Null::serialize(lang::type dstType,lang::word dst) */
extern cx_method Fast_Null_serialize_o;

/* ::cortex::Fast::Null::toIc(lang::alias{"cx_icProgram"} program,lang::alias{"cx_icStorage"} storage,lang::bool stored) */
extern cx_virtual Fast_Null_toIc_o;

/* ::cortex::Fast::Object */
extern cx_class Fast_Object_o;

/* ::cortex::Fast::Object::construct(Object object) */
extern cx_callback Fast_Object_construct_o;

/* ::cortex::Fast::Object::getValue() */
extern cx_method Fast_Object_getValue_o;

/* ::cortex::Fast::Object::serialize(lang::type dstType,lang::word dst) */
extern cx_method Fast_Object_serialize_o;

/* ::cortex::Fast::Object::toIc(lang::alias{"cx_icProgram"} program,lang::alias{"cx_icStorage"} storage,lang::bool stored) */
extern cx_virtual Fast_Object_toIc_o;

/* ::cortex::Fast::ObjectBase */
extern cx_class Fast_ObjectBase_o;

/* ::cortex::Fast::ObjectBase::construct(ObjectBase object) */
extern cx_callback Fast_ObjectBase_construct_o;

/* ::cortex::Fast::ObjectBase::value */
extern cx_member Fast_ObjectBase_value_o;

/* ::cortex::Fast::Parser */
extern cx_class Fast_Parser_o;

/* ::cortex::Fast::Parser::abort */
extern cx_member Fast_Parser_abort_o;

/* ::cortex::Fast::Parser::addStatement(Fast::Node statement) */
extern cx_method Fast_Parser_addStatement_o;

/* ::cortex::Fast::Parser::argumentToString(Fast::Variable type,lang::string id,lang::bool reference) */
extern cx_method Fast_Parser_argumentToString_o;

/* ::cortex::Fast::Parser::binaryExpr(Fast::Expression lvalues,Fast::Expression rvalues,lang::operatorKind operator) */
extern cx_method Fast_Parser_binaryExpr_o;

/* ::cortex::Fast::Parser::bind(Fast::Variable function,Fast::Block block) */
extern cx_method Fast_Parser_bind_o;

/* ::cortex::Fast::Parser::bindings */
extern cx_member Fast_Parser_bindings_o;

/* ::cortex::Fast::Parser::bindOneliner(Fast::Variable function,Fast::Block block,Fast::Expression expr) */
extern cx_method Fast_Parser_bindOneliner_o;

/* ::cortex::Fast::Parser::block */
extern cx_member Fast_Parser_block_o;

/* ::cortex::Fast::Parser::blockPop() */
extern cx_method Fast_Parser_blockPop_o;

/* ::cortex::Fast::Parser::blockPreset */
extern cx_member Fast_Parser_blockPreset_o;

/* ::cortex::Fast::Parser::blockPush(lang::bool presetBlock) */
extern cx_method Fast_Parser_blockPush_o;

/* ::cortex::Fast::Parser::callExpr(Fast::Expression function,Fast::Expression arguments) */
extern cx_method Fast_Parser_callExpr_o;

/* ::cortex::Fast::Parser::castExpr(Fast::Expression lvalue,Fast::Expression rvalue) */
extern cx_method Fast_Parser_castExpr_o;

/* ::cortex::Fast::Parser::collect(lang::object o) */
extern cx_method Fast_Parser_collect_o;

/* ::cortex::Fast::Parser::collected */
extern cx_member Fast_Parser_collected_o;

/* ::cortex::Fast::Parser::collectHeap(word addr) */
extern cx_method Fast_Parser_collectHeap_o;

/* ::cortex::Fast::Parser::column */
extern cx_member Fast_Parser_column_o;

/* ::cortex::Fast::Parser::complexType */
extern cx_member Fast_Parser_complexType_o;

/* ::cortex::Fast::Parser::complexTypeSp */
extern cx_member Fast_Parser_complexTypeSp_o;

/* ::cortex::Fast::Parser::construct(Parser object) */
extern cx_callback Fast_Parser_construct_o;

/* ::cortex::Fast::Parser::declaration(Variable type,lang::string id,lang::bool isReference) */
extern cx_method Fast_Parser_declaration_o;

/* ::cortex::Fast::Parser::declareFunction(Variable returnType,lang::string id,lang::type kind,bool returnsReference) */
extern cx_method Fast_Parser_declareFunction_o;

/* ::cortex::Fast::Parser::declareFunctionParams(Variable function) */
extern cx_method Fast_Parser_declareFunctionParams_o;

/* ::cortex::Fast::Parser::define() */
extern cx_method Fast_Parser_define_o;

/* ::cortex::Fast::Parser::defineScope() */
extern cx_method Fast_Parser_defineScope_o;

/* ::cortex::Fast::Parser::defineVariable(Variable object) */
extern cx_method Fast_Parser_defineVariable_o;

/* ::cortex::Fast::Parser::destruct(Parser object) */
extern cx_callback Fast_Parser_destruct_o;

/* ::cortex::Fast::Parser::elementExpr(Fast::Expression lvalue,Fast::Expression rvalue) */
extern cx_method Fast_Parser_elementExpr_o;

/* ::cortex::Fast::Parser::errLine */
extern cx_member Fast_Parser_errLine_o;

/* ::cortex::Fast::Parser::errors */
extern cx_member Fast_Parser_errors_o;

/* ::cortex::Fast::Parser::errSet */
extern cx_member Fast_Parser_errSet_o;

/* ::cortex::Fast::Parser::filename */
extern cx_member Fast_Parser_filename_o;

/* ::cortex::Fast::Parser::foreach(lang::string loopId,Fast::Expression collection) */
extern cx_method Fast_Parser_foreach_o;

/* ::cortex::Fast::Parser::getComplexType() */
extern cx_method Fast_Parser_getComplexType_o;

/* ::cortex::Fast::Parser::getLvalue(lang::bool assignment) */
extern cx_method Fast_Parser_getLvalue_o;

/* ::cortex::Fast::Parser::getLvalueType(lang::bool assignment) */
extern cx_method Fast_Parser_getLvalueType_o;

/* ::cortex::Fast::Parser::heapCollected */
extern cx_member Fast_Parser_heapCollected_o;

/* ::cortex::Fast::Parser::ifStatement(Fast::Expression condition,Fast::Block trueBranch,Fast::If falseBranch) */
extern cx_method Fast_Parser_ifStatement_o;

/* ::cortex::Fast::Parser::initAnonymousId */
extern cx_member Fast_Parser_initAnonymousId_o;

/* ::cortex::Fast::Parser::initDeclareStaged(Fast::Expression expr) */
extern cx_method Fast_Parser_initDeclareStaged_o;

/* ::cortex::Fast::Parser::initDynamic */
extern cx_member Fast_Parser_initDynamic_o;

/* ::cortex::Fast::Parser::initializerCount */
extern cx_member Fast_Parser_initializerCount_o;

/* ::cortex::Fast::Parser::initializers */
extern cx_member Fast_Parser_initializers_o;

/* ::cortex::Fast::Parser::initKeyValuePop() */
extern cx_method Fast_Parser_initKeyValuePop_o;

/* ::cortex::Fast::Parser::initKeyValuePush() */
extern cx_method Fast_Parser_initKeyValuePush_o;

/* ::cortex::Fast::Parser::initKeyValueSet(Fast::Expression expr) */
extern cx_method Fast_Parser_initKeyValueSet_o;

/* ::cortex::Fast::Parser::initMember(lang::string member) */
extern cx_method Fast_Parser_initMember_o;

/* ::cortex::Fast::Parser::initPop() */
extern cx_method Fast_Parser_initPop_o;

/* ::cortex::Fast::Parser::initPush() */
extern cx_method Fast_Parser_initPush_o;

/* ::cortex::Fast::Parser::initPushExpression() */
extern cx_method Fast_Parser_initPushExpression_o;

/* ::cortex::Fast::Parser::initPushIdentifier(Expression type) */
extern cx_method Fast_Parser_initPushIdentifier_o;

/* ::cortex::Fast::Parser::initPushStatic() */
extern cx_method Fast_Parser_initPushStatic_o;

/* ::cortex::Fast::Parser::initStage(lang::string id,bool found) */
extern cx_method Fast_Parser_initStage_o;

/* ::cortex::Fast::Parser::initValue(Expression expr) */
extern cx_method Fast_Parser_initValue_o;

/* ::cortex::Fast::Parser::isAbortSet() */
extern cx_method Fast_Parser_isAbortSet_o;

/* ::cortex::Fast::Parser::isErrSet() */
extern cx_method Fast_Parser_isErrSet_o;

/* ::cortex::Fast::Parser::isLocal */
extern cx_member Fast_Parser_isLocal_o;

/* ::cortex::Fast::Parser::lastFailedResolve */
extern cx_member Fast_Parser_lastFailedResolve_o;

/* ::cortex::Fast::Parser::line */
extern cx_member Fast_Parser_line_o;

/* ::cortex::Fast::Parser::lookup(lang::string id,lang::object source) */
extern cx_method Fast_Parser_lookup_o;

/* ::cortex::Fast::Parser::lvalue */
extern cx_member Fast_Parser_lvalue_o;

/* ::cortex::Fast::Parser::lvalueSp */
extern cx_member Fast_Parser_lvalueSp_o;

/* ::cortex::Fast::Parser::memberExpr(Fast::Expression lvalue,Fast::Expression rvalue) */
extern cx_method Fast_Parser_memberExpr_o;

/* ::cortex::Fast::Parser::observerDeclaration(lang::string id,Fast::Expression object,lang::eventMask mask,Fast::Object dispatcher) */
extern cx_method Fast_Parser_observerDeclaration_o;

/* ::cortex::Fast::Parser::observerPop() */
extern cx_method Fast_Parser_observerPop_o;

/* ::cortex::Fast::Parser::observerPush() */
extern cx_method Fast_Parser_observerPush_o;

/* ::cortex::Fast::Parser::parse() */
extern cx_method Fast_Parser_parse_o;

/* ::cortex::Fast::Parser::parseExpression(lang::string expr,Fast::Block block,Fast::Variable scope,uint32 line,uint32 column) */
extern cx_method Fast_Parser_parseExpression_o;

/* ::cortex::Fast::Parser::parseSingleExpr */
extern cx_member Fast_Parser_parseSingleExpr_o;

/* ::cortex::Fast::Parser::pass */
extern cx_member Fast_Parser_pass_o;

/* ::cortex::Fast::Parser::popComplexType() */
extern cx_method Fast_Parser_popComplexType_o;

/* ::cortex::Fast::Parser::popLvalue() */
extern cx_method Fast_Parser_popLvalue_o;

/* ::cortex::Fast::Parser::popScope(Fast::Variable previous) */
extern cx_method Fast_Parser_popScope_o;

/* ::cortex::Fast::Parser::postfixExpr(Fast::Expression lvalue,lang::operatorKind operator) */
extern cx_method Fast_Parser_postfixExpr_o;

/* ::cortex::Fast::Parser::preprocessed */
extern cx_member Fast_Parser_preprocessed_o;

/* ::cortex::Fast::Parser::pushComplexType(Fast::Expression lvalue) */
extern cx_method Fast_Parser_pushComplexType_o;

/* ::cortex::Fast::Parser::pushLvalue(Fast::Expression lvalue,lang::bool isAssignment) */
extern cx_method Fast_Parser_pushLvalue_o;

/* ::cortex::Fast::Parser::pushReturnAsLvalue(lang::function function) */
extern cx_method Fast_Parser_pushReturnAsLvalue_o;

/* ::cortex::Fast::Parser::pushScope() */
extern cx_method Fast_Parser_pushScope_o;

/* ::cortex::Fast::Parser::reset() */
extern cx_method Fast_Parser_reset_o;

/* ::cortex::Fast::Parser::scope */
extern cx_member Fast_Parser_scope_o;

/* ::cortex::Fast::Parser::singleExpr */
extern cx_member Fast_Parser_singleExpr_o;

/* ::cortex::Fast::Parser::source */
extern cx_member Fast_Parser_source_o;

/* ::cortex::Fast::Parser::staged */
extern cx_member Fast_Parser_staged_o;

/* ::cortex::Fast::Parser::stagedCount */
extern cx_member Fast_Parser_stagedCount_o;

/* ::cortex::Fast::Parser::stagedId */
extern cx_struct Fast_Parser_stagedId_o;

/* ::cortex::Fast::Parser::stagedId::column */
extern cx_member Fast_Parser_stagedId_column_o;

/* ::cortex::Fast::Parser::stagedId::found */
extern cx_member Fast_Parser_stagedId_found_o;

/* ::cortex::Fast::Parser::stagedId::line */
extern cx_member Fast_Parser_stagedId_line_o;

/* ::cortex::Fast::Parser::stagedId::name */
extern cx_member Fast_Parser_stagedId_name_o;

/* ::cortex::Fast::Parser::stagingAllowed */
extern cx_member Fast_Parser_stagingAllowed_o;

/* ::cortex::Fast::Parser::ternaryExpr(Fast::Expression cond,Fast::Expression iftrue,Fast::Expression iffalse) */
extern cx_method Fast_Parser_ternaryExpr_o;

/* ::cortex::Fast::Parser::token */
extern cx_member Fast_Parser_token_o;

/* ::cortex::Fast::Parser::unaryExpr(Fast::Expression lvalue,lang::operatorKind operator) */
extern cx_method Fast_Parser_unaryExpr_o;

/* ::cortex::Fast::Parser::updateStatement(Fast::Expression expr,Fast::Block block) */
extern cx_method Fast_Parser_updateStatement_o;

/* ::cortex::Fast::Parser::variableCount */
extern cx_member Fast_Parser_variableCount_o;

/* ::cortex::Fast::Parser::variablePushed */
extern cx_member Fast_Parser_variablePushed_o;

/* ::cortex::Fast::Parser::variables */
extern cx_member Fast_Parser_variables_o;

/* ::cortex::Fast::Parser::variablesInitialized */
extern cx_member Fast_Parser_variablesInitialized_o;

/* ::cortex::Fast::Parser::waitExpr(list{Fast::Expression} exprList,Fast::Expression timeout) */
extern cx_method Fast_Parser_waitExpr_o;

/* ::cortex::Fast::Parser::warnings */
extern cx_member Fast_Parser_warnings_o;

/* ::cortex::Fast::Parser::whileStatement(Fast::Expression condition,Fast::Block trueBranch,lang::bool isUntil) */
extern cx_method Fast_Parser_whileStatement_o;

/* ::cortex::Fast::ParserDeclaration */
extern cx_struct Fast_ParserDeclaration_o;

/* ::cortex::Fast::ParserDeclaration::name */
extern cx_member Fast_ParserDeclaration_name_o;

/* ::cortex::Fast::ParserDeclaration::variable */
extern cx_member Fast_ParserDeclaration_variable_o;

/* ::cortex::Fast::ParserDeclarationSeq */
extern cx_typedef Fast_ParserDeclarationSeq_o;

/* ::cortex::Fast::ParserNew */
extern cx_struct Fast_ParserNew_o;

/* ::cortex::Fast::ParserNew::attr */
extern cx_member Fast_ParserNew_attr_o;

/* ::cortex::Fast::ParserNew::kind */
extern cx_member Fast_ParserNew_kind_o;

/* ::cortex::Fast::ParserNew::name */
extern cx_member Fast_ParserNew_name_o;

/* ::cortex::Fast::ParserNew::parent */
extern cx_member Fast_ParserNew_parent_o;

/* ::cortex::Fast::PostfixExpr */
extern cx_class Fast_PostfixExpr_o;

/* ::cortex::Fast::PostfixExpr::construct(Fast::PostfixExpr object) */
extern cx_callback Fast_PostfixExpr_construct_o;

/* ::cortex::Fast::PostfixExpr::lvalue */
extern cx_member Fast_PostfixExpr_lvalue_o;

/* ::cortex::Fast::PostfixExpr::operator */
extern cx_member Fast_PostfixExpr_operator_o;

/* ::cortex::Fast::PostfixExpr::toIc(lang::alias{"cx_icProgram"} program,lang::alias{"cx_icStorage"} storage,lang::bool stored) */
extern cx_virtual Fast_PostfixExpr_toIc_o;

/* ::cortex::Fast::SignedInteger */
extern cx_class Fast_SignedInteger_o;

/* ::cortex::Fast::SignedInteger::init(SignedInteger object) */
extern cx_callback Fast_SignedInteger_init_o;

/* ::cortex::Fast::SignedInteger::serialize(lang::type dstType,lang::word dst) */
extern cx_method Fast_SignedInteger_serialize_o;

/* ::cortex::Fast::SignedInteger::toIc(lang::alias{"cx_icProgram"} program,lang::alias{"cx_icStorage"} storage,lang::bool stored) */
extern cx_virtual Fast_SignedInteger_toIc_o;

/* ::cortex::Fast::SignedInteger::value */
extern cx_member Fast_SignedInteger_value_o;

/* ::cortex::Fast::StaticCall */
extern cx_class Fast_StaticCall_o;

/* ::cortex::Fast::StaticCall::construct(Fast::StaticCall object) */
extern cx_callback Fast_StaticCall_construct_o;

/* ::cortex::Fast::StaticCall::function */
extern cx_member Fast_StaticCall_function_o;

/* ::cortex::Fast::StaticInitializer */
extern cx_class Fast_StaticInitializer_o;

/* ::cortex::Fast::StaticInitializer::construct(StaticInitializer object) */
extern cx_callback Fast_StaticInitializer_construct_o;

/* ::cortex::Fast::StaticInitializer::define() */
extern cx_method Fast_StaticInitializer_define_o;

/* ::cortex::Fast::StaticInitializer::frames */
extern cx_member Fast_StaticInitializer_frames_o;

/* ::cortex::Fast::StaticInitializer::push() */
extern cx_method Fast_StaticInitializer_push_o;

/* ::cortex::Fast::StaticInitializer::value(Expression v) */
extern cx_method Fast_StaticInitializer_value_o;

/* ::cortex::Fast::StaticInitializerFrame */
extern cx_struct Fast_StaticInitializerFrame_o;

/* ::cortex::Fast::StaticInitializerFrame::keyPtr */
extern cx_member Fast_StaticInitializerFrame_keyPtr_o;

/* ::cortex::Fast::StaticInitializerFrame::ptr */
extern cx_member Fast_StaticInitializerFrame_ptr_o;

/* ::cortex::Fast::String */
extern cx_class Fast_String_o;

/* ::cortex::Fast::String::block */
extern cx_member Fast_String_block_o;

/* ::cortex::Fast::String::construct(String object) */
extern cx_callback Fast_String_construct_o;

/* ::cortex::Fast::String::elements */
extern cx_member Fast_String_elements_o;

/* ::cortex::Fast::String::getValue() */
extern cx_method Fast_String_getValue_o;

/* ::cortex::Fast::String::init(String object) */
extern cx_callback Fast_String_init_o;

/* ::cortex::Fast::String::scope */
extern cx_member Fast_String_scope_o;

/* ::cortex::Fast::String::serialize(lang::type dstType,lang::word dst) */
extern cx_method Fast_String_serialize_o;

/* ::cortex::Fast::String::toIc(lang::alias{"cx_icProgram"} program,lang::alias{"cx_icStorage"} storage,lang::bool stored) */
extern cx_virtual Fast_String_toIc_o;

/* ::cortex::Fast::String::value */
extern cx_member Fast_String_value_o;

/* ::cortex::Fast::Template */
extern cx_class Fast_Template_o;

/* ::cortex::Fast::Template::construct(Template object) */
extern cx_callback Fast_Template_construct_o;

/* ::cortex::Fast::TernaryExpr */
extern cx_class Fast_TernaryExpr_o;

/* ::cortex::Fast::TernaryExpr::condition */
extern cx_member Fast_TernaryExpr_condition_o;

/* ::cortex::Fast::TernaryExpr::construct(Fast::TernaryExpr object) */
extern cx_callback Fast_TernaryExpr_construct_o;

/* ::cortex::Fast::TernaryExpr::hasSideEffects() */
extern cx_virtual Fast_TernaryExpr_hasSideEffects_o;

/* ::cortex::Fast::TernaryExpr::ifFalse */
extern cx_member Fast_TernaryExpr_ifFalse_o;

/* ::cortex::Fast::TernaryExpr::ifFalseExpr */
extern cx_member Fast_TernaryExpr_ifFalseExpr_o;

/* ::cortex::Fast::TernaryExpr::ifstmt */
extern cx_member Fast_TernaryExpr_ifstmt_o;

/* ::cortex::Fast::TernaryExpr::ifTrue */
extern cx_member Fast_TernaryExpr_ifTrue_o;

/* ::cortex::Fast::TernaryExpr::ifTrueExpr */
extern cx_member Fast_TernaryExpr_ifTrueExpr_o;

/* ::cortex::Fast::TernaryExpr::result */
extern cx_member Fast_TernaryExpr_result_o;

/* ::cortex::Fast::TernaryExpr::setOperator(lang::operatorKind kind) */
extern cx_method Fast_TernaryExpr_setOperator_o;

/* ::cortex::Fast::TernaryExpr::toIc(lang::alias{"cx_icProgram"} program,lang::alias{"cx_icStorage"} storage,lang::bool stored) */
extern cx_virtual Fast_TernaryExpr_toIc_o;

/* ::cortex::Fast::UnaryExpr */
extern cx_class Fast_UnaryExpr_o;

/* ::cortex::Fast::UnaryExpr::construct(Fast::UnaryExpr object) */
extern cx_callback Fast_UnaryExpr_construct_o;

/* ::cortex::Fast::UnaryExpr::hasSideEffects() */
extern cx_virtual Fast_UnaryExpr_hasSideEffects_o;

/* ::cortex::Fast::UnaryExpr::lvalue */
extern cx_member Fast_UnaryExpr_lvalue_o;

/* ::cortex::Fast::UnaryExpr::operator */
extern cx_member Fast_UnaryExpr_operator_o;

/* ::cortex::Fast::UnaryExpr::toIc(lang::alias{"cx_icProgram"} program,lang::alias{"cx_icStorage"} storage,lang::bool stored) */
extern cx_virtual Fast_UnaryExpr_toIc_o;

/* ::cortex::Fast::Update */
extern cx_class Fast_Update_o;

/* ::cortex::Fast::Update::block */
extern cx_member Fast_Update_block_o;

/* ::cortex::Fast::Update::construct(Update object) */
extern cx_callback Fast_Update_construct_o;

/* ::cortex::Fast::Update::exprList */
extern cx_member Fast_Update_exprList_o;

/* ::cortex::Fast::Update::from */
extern cx_member Fast_Update_from_o;

/* ::cortex::Fast::Update::toIc(lang::alias{"cx_icProgram"} program,lang::alias{"cx_icStorage"} storage,lang::bool stored) */
extern cx_virtual Fast_Update_toIc_o;

/* ::cortex::Fast::valueKind */
extern cx_enum Fast_valueKind_o;

/* ::cortex::Fast::valueKind::Boolean */
extern cx_constant (*Fast_valueKind_Boolean_o);

/* ::cortex::Fast::valueKind::Character */
extern cx_constant (*Fast_valueKind_Character_o);

/* ::cortex::Fast::valueKind::Enumerated */
extern cx_constant (*Fast_valueKind_Enumerated_o);

/* ::cortex::Fast::valueKind::FloatingPoint */
extern cx_constant (*Fast_valueKind_FloatingPoint_o);

/* ::cortex::Fast::valueKind::Integer */
extern cx_constant (*Fast_valueKind_Integer_o);

/* ::cortex::Fast::valueKind::Null */
extern cx_constant (*Fast_valueKind_Null_o);

/* ::cortex::Fast::valueKind::Reference */
extern cx_constant (*Fast_valueKind_Reference_o);

/* ::cortex::Fast::valueKind::SignedInteger */
extern cx_constant (*Fast_valueKind_SignedInteger_o);

/* ::cortex::Fast::valueKind::String */
extern cx_constant (*Fast_valueKind_String_o);

/* ::cortex::Fast::valueKindFromType(lang::type type) */
extern cx_function Fast_valueKindFromType_o;

/* ::cortex::Fast::Variable */
extern cx_class Fast_Variable_o;

/* ::cortex::Fast::Variable::construct(Variable object) */
extern cx_callback Fast_Variable_construct_o;

/* ::cortex::Fast::Variable::kind */
extern cx_member Fast_Variable_kind_o;

/* ::cortex::Fast::variableKind */
extern cx_enum Fast_variableKind_o;

/* ::cortex::Fast::variableKind::Local */
extern cx_constant (*Fast_variableKind_Local_o);

/* ::cortex::Fast::variableKind::Object */
extern cx_constant (*Fast_variableKind_Object_o);

/* ::cortex::Fast::variableKind::Template */
extern cx_constant (*Fast_variableKind_Template_o);

/* ::cortex::Fast::Wait */
extern cx_class Fast_Wait_o;

/* ::cortex::Fast::Wait::construct(Wait object) */
extern cx_callback Fast_Wait_construct_o;

/* ::cortex::Fast::Wait::exprList */
extern cx_member Fast_Wait_exprList_o;

/* ::cortex::Fast::Wait::timeout */
extern cx_member Fast_Wait_timeout_o;

/* ::cortex::Fast::Wait::toIc(lang::alias{"cx_icProgram"} program,lang::alias{"cx_icStorage"} storage,lang::bool stored) */
extern cx_virtual Fast_Wait_toIc_o;

/* ::cortex::Fast::While */
extern cx_class Fast_While_o;

/* ::cortex::Fast::While::condition */
extern cx_member Fast_While_condition_o;

/* ::cortex::Fast::While::construct(While object) */
extern cx_callback Fast_While_construct_o;

/* ::cortex::Fast::While::isUntil */
extern cx_member Fast_While_isUntil_o;

/* ::cortex::Fast::While::toIc(lang::alias{"cx_icProgram"} program,lang::alias{"cx_icStorage"} storage,lang::bool stored) */
extern cx_virtual Fast_While_toIc_o;

/* ::cortex::Fast::While::trueBranch */
extern cx_member Fast_While_trueBranch_o;

int Fast_load(void);
#ifdef __cplusplus
}
#endif
#endif

