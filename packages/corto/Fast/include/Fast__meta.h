/* Fast__meta.h
 *
 * Loads objects in object store.
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_META_H
#define Fast_META_H

#include "corto.h"

#include "Fast__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto */
extern cx_package _o;

/* ::corto::Fast */
extern cx_package Fast_o;

/* ::corto::Fast::Binary */
extern cx_class Fast_Binary_o;

/* ::corto::Fast::Binary::construct() */
extern cx_method Fast_Binary_construct_o;

/* ::corto::Fast::Binary::deref */
extern cx_member Fast_Binary_deref_o;

/* ::corto::Fast::Binary::fold() */
extern cx_method Fast_Binary_fold_o;

/* ::corto::Fast::Binary::hasReturnedResource() */
extern cx_virtual Fast_Binary_hasReturnedResource_o;

/* ::corto::Fast::Binary::hasSideEffects() */
extern cx_virtual Fast_Binary_hasSideEffects_o;

/* ::corto::Fast::Binary::isScalar */
extern cx_member Fast_Binary_isScalar_o;

/* ::corto::Fast::Binary::lvalue */
extern cx_member Fast_Binary_lvalue_o;

/* ::corto::Fast::Binary::operator */
extern cx_member Fast_Binary_operator_o;

/* ::corto::Fast::Binary::rvalue */
extern cx_member Fast_Binary_rvalue_o;

/* ::corto::Fast::Binary::setOperator(operatorKind kind) */
extern cx_method Fast_Binary_setOperator_o;

/* ::corto::Fast::Binary::toIc(ic::program program,ic::storage storage,bool stored) */
extern cx_virtual Fast_Binary_toIc_o;

/* ::corto::Fast::Binding */
extern cx_struct Fast_Binding_o;

/* ::corto::Fast::Binding::function */
extern cx_member Fast_Binding_function_o;

/* ::corto::Fast::Binding::impl */
extern cx_member Fast_Binding_impl_o;

/* ::corto::Fast::Block */
extern cx_class Fast_Block_o;

/* ::corto::Fast::Block::addStatement(Fast::Node statement) */
extern cx_method Fast_Block_addStatement_o;

/* ::corto::Fast::Block::declare(string id,type type,bool isParameter,bool isReference) */
extern cx_method Fast_Block_declare_o;

/* ::corto::Fast::Block::declareReturnVariable(function function) */
extern cx_method Fast_Block_declareReturnVariable_o;

/* ::corto::Fast::Block::declareTemplate(string id,type type,bool isParameter,bool isReference) */
extern cx_method Fast_Block_declareTemplate_o;

/* ::corto::Fast::Block::function */
extern cx_member Fast_Block_function_o;

/* ::corto::Fast::Block::isRoot */
extern cx_member Fast_Block_isRoot_o;

/* ::corto::Fast::Block::locals */
extern cx_member Fast_Block_locals_o;

/* ::corto::Fast::Block::lookup(string id) */
extern cx_method Fast_Block_lookup_o;

/* ::corto::Fast::Block::lookupLocal(string id) */
extern cx_method Fast_Block_lookupLocal_o;

/* ::corto::Fast::Block::parent */
extern cx_member Fast_Block_parent_o;

/* ::corto::Fast::Block::resolve(string id) */
extern cx_method Fast_Block_resolve_o;

/* ::corto::Fast::Block::resolveLocal(string id) */
extern cx_method Fast_Block_resolveLocal_o;

/* ::corto::Fast::Block::setFunction(function function */
extern cx_method Fast_Block_setFunction_o;

/* ::corto::Fast::Block::statements */
extern cx_member Fast_Block_statements_o;

/* ::corto::Fast::Block::toIc(ic::program program,ic::storage storage,bool stored) */
extern cx_virtual Fast_Block_toIc_o;

/* ::corto::Fast::Block::toIcBody(ic::program program,ic::storage storage,bool stored) */
extern cx_virtual Fast_Block_toIcBody_o;

/* ::corto::Fast::Block::while */
extern cx_member Fast_Block_while_o;

/* ::corto::Fast::Boolean */
extern cx_class Fast_Boolean_o;

/* ::corto::Fast::Boolean::init() */
extern cx_method Fast_Boolean_init_o;

/* ::corto::Fast::Boolean::serialize(type dstType,word dst) */
extern cx_method Fast_Boolean_serialize_o;

/* ::corto::Fast::Boolean::toIc(ic::program program,ic::storage storage,bool stored) */
extern cx_virtual Fast_Boolean_toIc_o;

/* ::corto::Fast::Boolean::value */
extern cx_member Fast_Boolean_value_o;

/* ::corto::Fast::Call */
extern cx_class Fast_Call_o;

/* ::corto::Fast::Call::arguments */
extern cx_member Fast_Call_arguments_o;

/* ::corto::Fast::Call::construct() */
extern cx_method Fast_Call_construct_o;

/* ::corto::Fast::Call::functionExpr */
extern cx_member Fast_Call_functionExpr_o;

/* ::corto::Fast::Call::hasReturnedResource() */
extern cx_virtual Fast_Call_hasReturnedResource_o;

/* ::corto::Fast::Call::hasSideEffects() */
extern cx_virtual Fast_Call_hasSideEffects_o;

/* ::corto::Fast::Call::instanceExpr */
extern cx_member Fast_Call_instanceExpr_o;

/* ::corto::Fast::Call::instanceIsAny */
extern cx_member Fast_Call_instanceIsAny_o;

/* ::corto::Fast::Call::overloaded */
extern cx_member Fast_Call_overloaded_o;

/* ::corto::Fast::Call::parameters */
extern cx_member Fast_Call_parameters_o;

/* ::corto::Fast::Call::returnsReference */
extern cx_member Fast_Call_returnsReference_o;

/* ::corto::Fast::Call::returnType */
extern cx_member Fast_Call_returnType_o;

/* ::corto::Fast::Call::setParameters(function function) */
extern cx_method Fast_Call_setParameters_o;

/* ::corto::Fast::Call::toIc(ic::program program,ic::storage storage,bool stored) */
extern cx_virtual Fast_Call_toIc_o;

/* ::corto::Fast::CallBuilder */
extern cx_struct Fast_CallBuilder_o;

/* ::corto::Fast::CallBuilder::arguments */
extern cx_member Fast_CallBuilder_arguments_o;

/* ::corto::Fast::CallBuilder::block */
extern cx_member Fast_CallBuilder_block_o;

/* ::corto::Fast::CallBuilder::build() */
extern cx_method Fast_CallBuilder_build_o;

/* ::corto::Fast::CallBuilder::buildSignature() */
extern cx_method Fast_CallBuilder_buildSignature_o;

/* ::corto::Fast::CallBuilder::instance */
extern cx_member Fast_CallBuilder_instance_o;

/* ::corto::Fast::CallBuilder::name */
extern cx_member Fast_CallBuilder_name_o;

/* ::corto::Fast::CallBuilder::overloaded */
extern cx_member Fast_CallBuilder_overloaded_o;

/* ::corto::Fast::CallBuilder::scope */
extern cx_member Fast_CallBuilder_scope_o;

/* ::corto::Fast::CallBuilder::signature */
extern cx_member Fast_CallBuilder_signature_o;

/* ::corto::Fast::Cast */
extern cx_class Fast_Cast_o;

/* ::corto::Fast::Cast::construct() */
extern cx_method Fast_Cast_construct_o;

/* ::corto::Fast::Cast::hasReturnedResource() */
extern cx_virtual Fast_Cast_hasReturnedResource_o;

/* ::corto::Fast::Cast::isReference */
extern cx_member Fast_Cast_isReference_o;

/* ::corto::Fast::Cast::lvalue */
extern cx_member Fast_Cast_lvalue_o;

/* ::corto::Fast::Cast::rvalue */
extern cx_member Fast_Cast_rvalue_o;

/* ::corto::Fast::Cast::toIc(ic::program program,ic::storage storage,bool stored) */
extern cx_virtual Fast_Cast_toIc_o;

/* ::corto::Fast::Character */
extern cx_class Fast_Character_o;

/* ::corto::Fast::Character::init() */
extern cx_method Fast_Character_init_o;

/* ::corto::Fast::Character::serialize(type dstType,word dst) */
extern cx_method Fast_Character_serialize_o;

/* ::corto::Fast::Character::toIc(ic::program program,ic::storage storage,bool stored) */
extern cx_virtual Fast_Character_toIc_o;

/* ::corto::Fast::Character::value */
extern cx_member Fast_Character_value_o;

/* ::corto::Fast::Comma */
extern cx_class Fast_Comma_o;

/* ::corto::Fast::Comma::addExpression(Expression expr) */
extern cx_method Fast_Comma_addExpression_o;

/* ::corto::Fast::Comma::addOrCreate(Expression list,Expression expr) */
extern cx_function Fast_Comma_addOrCreate_o;

/* ::corto::Fast::Comma::construct() */
extern cx_method Fast_Comma_construct_o;

/* ::corto::Fast::Comma::expressions */
extern cx_member Fast_Comma_expressions_o;

/* ::corto::Fast::Comma::hasReturnedResource() */
extern cx_virtual Fast_Comma_hasReturnedResource_o;

/* ::corto::Fast::Comma::hasSideEffects() */
extern cx_virtual Fast_Comma_hasSideEffects_o;

/* ::corto::Fast::Comma::init() */
extern cx_method Fast_Comma_init_o;

/* ::corto::Fast::Comma::insertOrCreate(Expression list,Expression expr) */
extern cx_function Fast_Comma_insertOrCreate_o;

/* ::corto::Fast::Comma::toIc(ic::program program,ic::storage storage,bool stored) */
extern cx_virtual Fast_Comma_toIc_o;

/* ::corto::Fast::Comma::toList() */
extern cx_method Fast_Comma_toList_o;

/* ::corto::Fast::Define */
extern cx_class Fast_Define_o;

/* ::corto::Fast::Define::construct() */
extern cx_method Fast_Define_construct_o;

/* ::corto::Fast::Define::object */
extern cx_member Fast_Define_object_o;

/* ::corto::Fast::Define::toIc(ic::program program,ic::storage storage,bool stored) */
extern cx_virtual Fast_Define_toIc_o;

/* ::corto::Fast::Deinit */
extern cx_class Fast_Deinit_o;

/* ::corto::Fast::Deinit::construct() */
extern cx_method Fast_Deinit_construct_o;

/* ::corto::Fast::Deinit::storage */
extern cx_member Fast_Deinit_storage_o;

/* ::corto::Fast::Deinit::toIc(ic::program program,ic::storage storage,bool stored) */
extern cx_virtual Fast_Deinit_toIc_o;

/* ::corto::Fast::DelegateCall */
extern cx_class Fast_DelegateCall_o;

/* ::corto::Fast::DelegateCall::construct() */
extern cx_method Fast_DelegateCall_construct_o;

/* ::corto::Fast::DelegateCall::expr */
extern cx_member Fast_DelegateCall_expr_o;

/* ::corto::Fast::derefKind */
extern cx_enum Fast_derefKind_o;

/* ::corto::Fast::derefKind::ByReference */
extern cx_constant (*Fast_derefKind_ByReference_o);

/* ::corto::Fast::derefKind::ByValue */
extern cx_constant (*Fast_derefKind_ByValue_o);

/* ::corto::Fast::DynamicInitializer */
extern cx_class Fast_DynamicInitializer_o;

/* ::corto::Fast::DynamicInitializer::assignValue */
extern cx_member Fast_DynamicInitializer_assignValue_o;

/* ::corto::Fast::DynamicInitializer::construct() */
extern cx_method Fast_DynamicInitializer_construct_o;

/* ::corto::Fast::DynamicInitializer::define() */
extern cx_method Fast_DynamicInitializer_define_o;

/* ::corto::Fast::DynamicInitializer::frames */
extern cx_member Fast_DynamicInitializer_frames_o;

/* ::corto::Fast::DynamicInitializer::hasReturnedResource() */
extern cx_virtual Fast_DynamicInitializer_hasReturnedResource_o;

/* ::corto::Fast::DynamicInitializer::pop() */
extern cx_method Fast_DynamicInitializer_pop_o;

/* ::corto::Fast::DynamicInitializer::push() */
extern cx_method Fast_DynamicInitializer_push_o;

/* ::corto::Fast::DynamicInitializer::value(Expression v) */
extern cx_method Fast_DynamicInitializer_value_o;

/* ::corto::Fast::DynamicInitializerFrame */
extern cx_struct Fast_DynamicInitializerFrame_o;

/* ::corto::Fast::DynamicInitializerFrame::expr */
extern cx_member Fast_DynamicInitializerFrame_expr_o;

/* ::corto::Fast::DynamicInitializerFrame::keyExpr */
extern cx_member Fast_DynamicInitializerFrame_keyExpr_o;

/* ::corto::Fast::DynamicInitializerFrame::sequenceSize */
extern cx_member Fast_DynamicInitializerFrame_sequenceSize_o;

/* ::corto::Fast::Element */
extern cx_class Fast_Element_o;

/* ::corto::Fast::Element::construct() */
extern cx_method Fast_Element_construct_o;

/* ::corto::Fast::Element::lvalue */
extern cx_member Fast_Element_lvalue_o;

/* ::corto::Fast::Element::rvalue */
extern cx_member Fast_Element_rvalue_o;

/* ::corto::Fast::Element::toIc(ic::program program,ic::storage storage,bool stored) */
extern cx_virtual Fast_Element_toIc_o;

/* ::corto::Fast::Expression */
extern cx_class Fast_Expression_o;

/* ::corto::Fast::Expression::cast(type type,bool isReference) */
extern cx_method Fast_Expression_cast_o;

/* ::corto::Fast::Expression::cleanList(list{Expression} list) */
extern cx_function Fast_Expression_cleanList_o;

/* ::corto::Fast::Expression::deref */
extern cx_member Fast_Expression_deref_o;

/* ::corto::Fast::Expression::fold() */
extern cx_virtual Fast_Expression_fold_o;

/* ::corto::Fast::Expression::fromList(list{Expression} list) */
extern cx_function Fast_Expression_fromList_o;

/* ::corto::Fast::Expression::getType() */
extern cx_method Fast_Expression_getType_o;

/* ::corto::Fast::Expression::getType_expr(Expression target) */
extern cx_method Fast_Expression_getType_expr_o;

/* ::corto::Fast::Expression::getType_type(type target) */
extern cx_method Fast_Expression_getType_type_o;

/* ::corto::Fast::Expression::getValue() */
extern cx_virtual Fast_Expression_getValue_o;

/* ::corto::Fast::Expression::hasReturnedResource() */
extern cx_virtual Fast_Expression_hasReturnedResource_o;

/* ::corto::Fast::Expression::hasSideEffects() */
extern cx_virtual Fast_Expression_hasSideEffects_o;

/* ::corto::Fast::Expression::isReference */
extern cx_member Fast_Expression_isReference_o;

/* ::corto::Fast::Expression::serialize(type dstType,word dst) */
extern cx_virtual Fast_Expression_serialize_o;

/* ::corto::Fast::Expression::toList() */
extern cx_virtual Fast_Expression_toList_o;

/* ::corto::Fast::Expression::type */
extern cx_member Fast_Expression_type_o;

/* ::corto::Fast::FloatingPoint */
extern cx_class Fast_FloatingPoint_o;

/* ::corto::Fast::FloatingPoint::init() */
extern cx_method Fast_FloatingPoint_init_o;

/* ::corto::Fast::FloatingPoint::serialize(type dstType,word dst) */
extern cx_method Fast_FloatingPoint_serialize_o;

/* ::corto::Fast::FloatingPoint::toIc(ic::program program,ic::storage storage,bool stored) */
extern cx_virtual Fast_FloatingPoint_toIc_o;

/* ::corto::Fast::FloatingPoint::value */
extern cx_member Fast_FloatingPoint_value_o;

/* ::corto::Fast::If */
extern cx_class Fast_If_o;

/* ::corto::Fast::If::condition */
extern cx_member Fast_If_condition_o;

/* ::corto::Fast::If::construct() */
extern cx_method Fast_If_construct_o;

/* ::corto::Fast::If::falseBranch */
extern cx_member Fast_If_falseBranch_o;

/* ::corto::Fast::If::noWarnUnreachable() */
extern cx_method Fast_If_noWarnUnreachable_o;

/* ::corto::Fast::If::toIc(ic::program program,ic::storage storage,bool stored) */
extern cx_virtual Fast_If_toIc_o;

/* ::corto::Fast::If::trueBranch */
extern cx_member Fast_If_trueBranch_o;

/* ::corto::Fast::If::warnUnreachable */
extern cx_member Fast_If_warnUnreachable_o;

/* ::corto::Fast::Init */
extern cx_class Fast_Init_o;

/* ::corto::Fast::Init::construct() */
extern cx_method Fast_Init_construct_o;

/* ::corto::Fast::Init::storage */
extern cx_member Fast_Init_storage_o;

/* ::corto::Fast::Init::toIc(ic::program program,ic::storage storage,bool stored) */
extern cx_virtual Fast_Init_toIc_o;

/* ::corto::Fast::Initializer */
extern cx_class Fast_Initializer_o;

/* ::corto::Fast::Initializer::construct() */
extern cx_method Fast_Initializer_construct_o;

/* ::corto::Fast::Initializer::currentType() */
extern cx_method Fast_Initializer_currentType_o;

/* ::corto::Fast::Initializer::define() */
extern cx_virtual Fast_Initializer_define_o;

/* ::corto::Fast::Initializer::fp */
extern cx_member Fast_Initializer_fp_o;

/* ::corto::Fast::Initializer::frames */
extern cx_member Fast_Initializer_frames_o;

/* ::corto::Fast::Initializer::initFrame() */
extern cx_method Fast_Initializer_initFrame_o;

/* ::corto::Fast::Initializer::member(string name) */
extern cx_virtual Fast_Initializer_member_o;

/* ::corto::Fast::Initializer::next() */
extern cx_virtual Fast_Initializer_next_o;

/* ::corto::Fast::Initializer::pop() */
extern cx_virtual Fast_Initializer_pop_o;

/* ::corto::Fast::Initializer::popKey() */
extern cx_virtual Fast_Initializer_popKey_o;

/* ::corto::Fast::Initializer::push() */
extern cx_virtual Fast_Initializer_push_o;

/* ::corto::Fast::Initializer::pushKey() */
extern cx_virtual Fast_Initializer_pushKey_o;

/* ::corto::Fast::Initializer::type() */
extern cx_method Fast_Initializer_type_o;

/* ::corto::Fast::Initializer::value(Expression v) */
extern cx_virtual Fast_Initializer_value_o;

/* ::corto::Fast::Initializer::valueKey(Expression key) */
extern cx_virtual Fast_Initializer_valueKey_o;

/* ::corto::Fast::Initializer::variableCount */
extern cx_member Fast_Initializer_variableCount_o;

/* ::corto::Fast::Initializer::variables */
extern cx_member Fast_Initializer_variables_o;

/* ::corto::Fast::InitializerExpression */
extern cx_class Fast_InitializerExpression_o;

/* ::corto::Fast::InitializerExpression::assignValue */
extern cx_member Fast_InitializerExpression_assignValue_o;

/* ::corto::Fast::InitializerExpression::construct() */
extern cx_method Fast_InitializerExpression_construct_o;

/* ::corto::Fast::InitializerExpression::define() */
extern cx_method Fast_InitializerExpression_define_o;

/* ::corto::Fast::InitializerExpression::hasReturnedResource() */
extern cx_virtual Fast_InitializerExpression_hasReturnedResource_o;

/* ::corto::Fast::InitializerExpression::insert(Expression variable) */
extern cx_method Fast_InitializerExpression_insert_o;

/* ::corto::Fast::InitializerExpression::member(string name) */
extern cx_method Fast_InitializerExpression_member_o;

/* ::corto::Fast::InitializerExpression::operations */
extern cx_member Fast_InitializerExpression_operations_o;

/* ::corto::Fast::InitializerExpression::pop() */
extern cx_method Fast_InitializerExpression_pop_o;

/* ::corto::Fast::InitializerExpression::push() */
extern cx_method Fast_InitializerExpression_push_o;

/* ::corto::Fast::InitializerExpression::value(Expression v) */
extern cx_method Fast_InitializerExpression_value_o;

/* ::corto::Fast::InitializerFrame */
extern cx_struct Fast_InitializerFrame_o;

/* ::corto::Fast::InitializerFrame::isKey */
extern cx_member Fast_InitializerFrame_isKey_o;

/* ::corto::Fast::InitializerFrame::location */
extern cx_member Fast_InitializerFrame_location_o;

/* ::corto::Fast::InitializerFrame::member */
extern cx_member Fast_InitializerFrame_member_o;

/* ::corto::Fast::InitializerFrame::type */
extern cx_member Fast_InitializerFrame_type_o;

/* ::corto::Fast::InitializerKind */
extern cx_enum Fast_InitializerKind_o;

/* ::corto::Fast::InitializerKind::InitDynamic */
extern cx_constant (*Fast_InitializerKind_InitDynamic_o);

/* ::corto::Fast::InitializerKind::InitExpression */
extern cx_constant (*Fast_InitializerKind_InitExpression_o);

/* ::corto::Fast::InitializerKind::InitStatic */
extern cx_constant (*Fast_InitializerKind_InitStatic_o);

/* ::corto::Fast::InitializerVariable */
extern cx_struct Fast_InitializerVariable_o;

/* ::corto::Fast::InitializerVariable::key */
extern cx_member Fast_InitializerVariable_key_o;

/* ::corto::Fast::InitializerVariable::object */
extern cx_member Fast_InitializerVariable_object_o;

/* ::corto::Fast::InitializerVariable::offset */
extern cx_member Fast_InitializerVariable_offset_o;

/* ::corto::Fast::InitOper */
extern cx_struct Fast_InitOper_o;

/* ::corto::Fast::InitOper::expr */
extern cx_member Fast_InitOper_expr_o;

/* ::corto::Fast::InitOper::kind */
extern cx_member Fast_InitOper_kind_o;

/* ::corto::Fast::InitOper::name */
extern cx_member Fast_InitOper_name_o;

/* ::corto::Fast::InitOperKind */
extern cx_enum Fast_InitOperKind_o;

/* ::corto::Fast::InitOperKind::InitDefine */
extern cx_constant (*Fast_InitOperKind_InitDefine_o);

/* ::corto::Fast::InitOperKind::InitMember */
extern cx_constant (*Fast_InitOperKind_InitMember_o);

/* ::corto::Fast::InitOperKind::InitPop */
extern cx_constant (*Fast_InitOperKind_InitPop_o);

/* ::corto::Fast::InitOperKind::InitPush */
extern cx_constant (*Fast_InitOperKind_InitPush_o);

/* ::corto::Fast::InitOperKind::InitValue */
extern cx_constant (*Fast_InitOperKind_InitValue_o);

/* ::corto::Fast::Integer */
extern cx_class Fast_Integer_o;

/* ::corto::Fast::Integer::init() */
extern cx_method Fast_Integer_init_o;

/* ::corto::Fast::Integer::serialize(type dstType,word dst) */
extern cx_method Fast_Integer_serialize_o;

/* ::corto::Fast::Integer::toIc(ic::program program,ic::storage storage,bool stored) */
extern cx_virtual Fast_Integer_toIc_o;

/* ::corto::Fast::Integer::value */
extern cx_member Fast_Integer_value_o;

/* ::corto::Fast::isOperatorAssignment(operatorKind operator) */
extern cx_function Fast_isOperatorAssignment_o;

/* ::corto::Fast::Literal */
extern cx_class Fast_Literal_o;

/* ::corto::Fast::Literal::getValue() */
extern cx_virtual Fast_Literal_getValue_o;

/* ::corto::Fast::Literal::init() */
extern cx_method Fast_Literal_init_o;

/* ::corto::Fast::Literal::kind */
extern cx_member Fast_Literal_kind_o;

/* ::corto::Fast::Local */
extern cx_class Fast_Local_o;

/* ::corto::Fast::Local::construct() */
extern cx_method Fast_Local_construct_o;

/* ::corto::Fast::Local::kind */
extern cx_member Fast_Local_kind_o;

/* ::corto::Fast::Local::name */
extern cx_member Fast_Local_name_o;

/* ::corto::Fast::Local::reference */
extern cx_member Fast_Local_reference_o;

/* ::corto::Fast::Local::toIc(ic::program program,ic::storage storage,bool stored) */
extern cx_virtual Fast_Local_toIc_o;

/* ::corto::Fast::Local::type */
extern cx_member Fast_Local_type_o;

/* ::corto::Fast::LocalKind */
extern cx_enum Fast_LocalKind_o;

/* ::corto::Fast::LocalKind::LocalDefault */
extern cx_constant (*Fast_LocalKind_LocalDefault_o);

/* ::corto::Fast::LocalKind::LocalParameter */
extern cx_constant (*Fast_LocalKind_LocalParameter_o);

/* ::corto::Fast::LocalKind::LocalReturn */
extern cx_constant (*Fast_LocalKind_LocalReturn_o);

/* ::corto::Fast::Lvalue */
extern cx_struct Fast_Lvalue_o;

/* ::corto::Fast::Lvalue::expr */
extern cx_member Fast_Lvalue_expr_o;

/* ::corto::Fast::Lvalue::isAssignment */
extern cx_member Fast_Lvalue_isAssignment_o;

/* ::corto::Fast::Member */
extern cx_class Fast_Member_o;

/* ::corto::Fast::Member::construct() */
extern cx_method Fast_Member_construct_o;

/* ::corto::Fast::Member::hasSideEffects() */
extern cx_virtual Fast_Member_hasSideEffects_o;

/* ::corto::Fast::Member::lvalue */
extern cx_member Fast_Member_lvalue_o;

/* ::corto::Fast::Member::member */
extern cx_member Fast_Member_member_o;

/* ::corto::Fast::Member::rvalue */
extern cx_member Fast_Member_rvalue_o;

/* ::corto::Fast::Member::superMember */
extern cx_member Fast_Member_superMember_o;

/* ::corto::Fast::Member::toIc(ic::program program,ic::storage storage,bool stored) */
extern cx_virtual Fast_Member_toIc_o;

/* ::corto::Fast::New */
extern cx_class Fast_New_o;

/* ::corto::Fast::New::attributes */
extern cx_member Fast_New_attributes_o;

/* ::corto::Fast::New::construct() */
extern cx_method Fast_New_construct_o;

/* ::corto::Fast::New::hasSideEffects() */
extern cx_virtual Fast_New_hasSideEffects_o;

/* ::corto::Fast::New::toIc(ic::program program,ic::storage storage,bool stored) */
extern cx_virtual Fast_New_toIc_o;

/* ::corto::Fast::New::type */
extern cx_member Fast_New_type_o;

/* ::corto::Fast::Node */
extern cx_class Fast_Node_o;

/* ::corto::Fast::Node::column */
extern cx_member Fast_Node_column_o;

/* ::corto::Fast::Node::init() */
extern cx_method Fast_Node_init_o;

/* ::corto::Fast::Node::kind */
extern cx_member Fast_Node_kind_o;

/* ::corto::Fast::Node::line */
extern cx_member Fast_Node_line_o;

/* ::corto::Fast::Node::toIc(ic::program program,ic::storage storage,bool stored) */
extern cx_virtual Fast_Node_toIc_o;

/* ::corto::Fast::nodeKind */
extern cx_enum Fast_nodeKind_o;

/* ::corto::Fast::nodeKind::BinaryExpr */
extern cx_constant (*Fast_nodeKind_BinaryExpr_o);

/* ::corto::Fast::nodeKind::CallExpr */
extern cx_constant (*Fast_nodeKind_CallExpr_o);

/* ::corto::Fast::nodeKind::CastExpr */
extern cx_constant (*Fast_nodeKind_CastExpr_o);

/* ::corto::Fast::nodeKind::CommaExpr */
extern cx_constant (*Fast_nodeKind_CommaExpr_o);

/* ::corto::Fast::nodeKind::DeclarationExpr */
extern cx_constant (*Fast_nodeKind_DeclarationExpr_o);

/* ::corto::Fast::nodeKind::DeclareExpr */
extern cx_constant (*Fast_nodeKind_DeclareExpr_o);

/* ::corto::Fast::nodeKind::DefineExpr */
extern cx_constant (*Fast_nodeKind_DefineExpr_o);

/* ::corto::Fast::nodeKind::DeinitExpr */
extern cx_constant (*Fast_nodeKind_DeinitExpr_o);

/* ::corto::Fast::nodeKind::IfExpr */
extern cx_constant (*Fast_nodeKind_IfExpr_o);

/* ::corto::Fast::nodeKind::InitExpr */
extern cx_constant (*Fast_nodeKind_InitExpr_o);

/* ::corto::Fast::nodeKind::InitializerExpr */
extern cx_constant (*Fast_nodeKind_InitializerExpr_o);

/* ::corto::Fast::nodeKind::LiteralExpr */
extern cx_constant (*Fast_nodeKind_LiteralExpr_o);

/* ::corto::Fast::nodeKind::MethodExpr */
extern cx_constant (*Fast_nodeKind_MethodExpr_o);

/* ::corto::Fast::nodeKind::NewExpr */
extern cx_constant (*Fast_nodeKind_NewExpr_o);

/* ::corto::Fast::nodeKind::PostfixExpr */
extern cx_constant (*Fast_nodeKind_PostfixExpr_o);

/* ::corto::Fast::nodeKind::StorageExpr */
extern cx_constant (*Fast_nodeKind_StorageExpr_o);

/* ::corto::Fast::nodeKind::TernaryExpr */
extern cx_constant (*Fast_nodeKind_TernaryExpr_o);

/* ::corto::Fast::nodeKind::UnaryExpr */
extern cx_constant (*Fast_nodeKind_UnaryExpr_o);

/* ::corto::Fast::nodeKind::UpdateExpr */
extern cx_constant (*Fast_nodeKind_UpdateExpr_o);

/* ::corto::Fast::nodeKind::WaitExpr */
extern cx_constant (*Fast_nodeKind_WaitExpr_o);

/* ::corto::Fast::nodeKind::WhileExpr */
extern cx_constant (*Fast_nodeKind_WhileExpr_o);

/* ::corto::Fast::Null */
extern cx_class Fast_Null_o;

/* ::corto::Fast::Null::init() */
extern cx_method Fast_Null_init_o;

/* ::corto::Fast::Null::serialize(type dstType,word dst) */
extern cx_method Fast_Null_serialize_o;

/* ::corto::Fast::Null::toIc(ic::program program,ic::storage storage,bool stored) */
extern cx_virtual Fast_Null_toIc_o;

/* ::corto::Fast::Object */
extern cx_class Fast_Object_o;

/* ::corto::Fast::Object::construct() */
extern cx_method Fast_Object_construct_o;

/* ::corto::Fast::Object::getValue() */
extern cx_method Fast_Object_getValue_o;

/* ::corto::Fast::Object::serialize(type dstType,word dst) */
extern cx_method Fast_Object_serialize_o;

/* ::corto::Fast::Object::toIc(ic::program program,ic::storage storage,bool stored) */
extern cx_virtual Fast_Object_toIc_o;

/* ::corto::Fast::Object::value */
extern cx_member Fast_Object_value_o;

/* ::corto::Fast::Parser */
extern cx_class Fast_Parser_o;

/* ::corto::Fast::Parser::abort */
extern cx_member Fast_Parser_abort_o;

/* ::corto::Fast::Parser::addStatement(Fast::Node statement) */
extern cx_method Fast_Parser_addStatement_o;

/* ::corto::Fast::Parser::argumentToString(type type,string id,bool reference) */
extern cx_method Fast_Parser_argumentToString_o;

/* ::corto::Fast::Parser::binaryExpr(Fast::Expression lvalues,Fast::Expression rvalues,operatorKind operator) */
extern cx_method Fast_Parser_binaryExpr_o;

/* ::corto::Fast::Parser::bind(Fast::Storage function,Fast::Block block) */
extern cx_method Fast_Parser_bind_o;

/* ::corto::Fast::Parser::bindings */
extern cx_member Fast_Parser_bindings_o;

/* ::corto::Fast::Parser::bindOneliner(Fast::Storage function,Fast::Block block,Fast::Expression expr) */
extern cx_method Fast_Parser_bindOneliner_o;

/* ::corto::Fast::Parser::block */
extern cx_member Fast_Parser_block_o;

/* ::corto::Fast::Parser::blockCount */
extern cx_member Fast_Parser_blockCount_o;

/* ::corto::Fast::Parser::blockPop() */
extern cx_method Fast_Parser_blockPop_o;

/* ::corto::Fast::Parser::blockPreset */
extern cx_member Fast_Parser_blockPreset_o;

/* ::corto::Fast::Parser::blockPush(bool presetBlock) */
extern cx_method Fast_Parser_blockPush_o;

/* ::corto::Fast::Parser::callExpr(Fast::Expression function,Fast::Expression arguments) */
extern cx_method Fast_Parser_callExpr_o;

/* ::corto::Fast::Parser::castExpr(type lvalue,Fast::Expression rvalue) */
extern cx_method Fast_Parser_castExpr_o;

/* ::corto::Fast::Parser::collect(object o) */
extern cx_method Fast_Parser_collect_o;

/* ::corto::Fast::Parser::collected */
extern cx_member Fast_Parser_collected_o;

/* ::corto::Fast::Parser::collectHeap(word addr) */
extern cx_method Fast_Parser_collectHeap_o;

/* ::corto::Fast::Parser::column */
extern cx_member Fast_Parser_column_o;

/* ::corto::Fast::Parser::complexType */
extern cx_member Fast_Parser_complexType_o;

/* ::corto::Fast::Parser::complexTypeSp */
extern cx_member Fast_Parser_complexTypeSp_o;

/* ::corto::Fast::Parser::construct() */
extern cx_method Fast_Parser_construct_o;

/* ::corto::Fast::Parser::declaration(type type,string id,bool isReference) */
extern cx_method Fast_Parser_declaration_o;

/* ::corto::Fast::Parser::declareFunction(type returnType,string id,type kind,bool returnsReference) */
extern cx_method Fast_Parser_declareFunction_o;

/* ::corto::Fast::Parser::declareFunctionParams(Storage function) */
extern cx_method Fast_Parser_declareFunctionParams_o;

/* ::corto::Fast::Parser::define() */
extern cx_method Fast_Parser_define_o;

/* ::corto::Fast::Parser::defineScope() */
extern cx_method Fast_Parser_defineScope_o;

/* ::corto::Fast::Parser::defineVariable(Storage object) */
extern cx_method Fast_Parser_defineVariable_o;

/* ::corto::Fast::Parser::destruct() */
extern cx_method Fast_Parser_destruct_o;

/* ::corto::Fast::Parser::elementExpr(Fast::Expression lvalue,Fast::Expression rvalue) */
extern cx_method Fast_Parser_elementExpr_o;

/* ::corto::Fast::Parser::errLine */
extern cx_member Fast_Parser_errLine_o;

/* ::corto::Fast::Parser::errors */
extern cx_member Fast_Parser_errors_o;

/* ::corto::Fast::Parser::errSet */
extern cx_member Fast_Parser_errSet_o;

/* ::corto::Fast::Parser::filename */
extern cx_member Fast_Parser_filename_o;

/* ::corto::Fast::Parser::finalize(ic::program program) */
extern cx_method Fast_Parser_finalize_o;

/* ::corto::Fast::Parser::foreach(string loopId,Fast::Expression collection) */
extern cx_method Fast_Parser_foreach_o;

/* ::corto::Fast::Parser::getComplexType() */
extern cx_method Fast_Parser_getComplexType_o;

/* ::corto::Fast::Parser::getLvalue(bool assignment) */
extern cx_method Fast_Parser_getLvalue_o;

/* ::corto::Fast::Parser::getLvalueType(bool assignment) */
extern cx_method Fast_Parser_getLvalueType_o;

/* ::corto::Fast::Parser::heapCollected */
extern cx_member Fast_Parser_heapCollected_o;

/* ::corto::Fast::Parser::ifStatement(Fast::Expression condition,Fast::Block trueBranch,Fast::If falseBranch) */
extern cx_method Fast_Parser_ifStatement_o;

/* ::corto::Fast::Parser::initAnonymousId */
extern cx_member Fast_Parser_initAnonymousId_o;

/* ::corto::Fast::Parser::initDeclareStaged(Fast::Expression expr) */
extern cx_method Fast_Parser_initDeclareStaged_o;

/* ::corto::Fast::Parser::initDynamic */
extern cx_member Fast_Parser_initDynamic_o;

/* ::corto::Fast::Parser::initializerCount */
extern cx_member Fast_Parser_initializerCount_o;

/* ::corto::Fast::Parser::initializers */
extern cx_member Fast_Parser_initializers_o;

/* ::corto::Fast::Parser::initKeyValuePop() */
extern cx_method Fast_Parser_initKeyValuePop_o;

/* ::corto::Fast::Parser::initKeyValuePush() */
extern cx_method Fast_Parser_initKeyValuePush_o;

/* ::corto::Fast::Parser::initKeyValueSet(Fast::Expression expr) */
extern cx_method Fast_Parser_initKeyValueSet_o;

/* ::corto::Fast::Parser::initMember(string member) */
extern cx_method Fast_Parser_initMember_o;

/* ::corto::Fast::Parser::initPop() */
extern cx_method Fast_Parser_initPop_o;

/* ::corto::Fast::Parser::initPush() */
extern cx_method Fast_Parser_initPush_o;

/* ::corto::Fast::Parser::initPushExpression() */
extern cx_method Fast_Parser_initPushExpression_o;

/* ::corto::Fast::Parser::initPushIdentifier(Expression type) */
extern cx_method Fast_Parser_initPushIdentifier_o;

/* ::corto::Fast::Parser::initPushStatic() */
extern cx_method Fast_Parser_initPushStatic_o;

/* ::corto::Fast::Parser::initStage(string id,bool found) */
extern cx_method Fast_Parser_initStage_o;

/* ::corto::Fast::Parser::initValue(Expression expr) */
extern cx_method Fast_Parser_initValue_o;

/* ::corto::Fast::Parser::isAbortSet() */
extern cx_method Fast_Parser_isAbortSet_o;

/* ::corto::Fast::Parser::isErrSet() */
extern cx_method Fast_Parser_isErrSet_o;

/* ::corto::Fast::Parser::isLocal */
extern cx_member Fast_Parser_isLocal_o;

/* ::corto::Fast::Parser::lastFailedResolve */
extern cx_member Fast_Parser_lastFailedResolve_o;

/* ::corto::Fast::Parser::line */
extern cx_member Fast_Parser_line_o;

/* ::corto::Fast::Parser::lookup(string id) */
extern cx_method Fast_Parser_lookup_o;

/* ::corto::Fast::Parser::lvalue */
extern cx_member Fast_Parser_lvalue_o;

/* ::corto::Fast::Parser::lvalueSp */
extern cx_member Fast_Parser_lvalueSp_o;

/* ::corto::Fast::Parser::memberExpr(Fast::Expression lvalue,Fast::Expression rvalue) */
extern cx_method Fast_Parser_memberExpr_o;

/* ::corto::Fast::Parser::observerDeclaration(string id,Fast::Expression object,eventMask mask,Fast::Object dispatcher) */
extern cx_method Fast_Parser_observerDeclaration_o;

/* ::corto::Fast::Parser::observerPush() */
extern cx_method Fast_Parser_observerPush_o;

/* ::corto::Fast::Parser::parse() */
extern cx_method Fast_Parser_parse_o;

/* ::corto::Fast::Parser::parseExpression(string expr,Fast::Block block,object scope,uint32 line,uint32 column) */
extern cx_method Fast_Parser_parseExpression_o;

/* ::corto::Fast::Parser::parseLine(string expr,object scope,word value) */
extern cx_function Fast_Parser_parseLine_o;

/* ::corto::Fast::Parser::parseSingleExpr */
extern cx_member Fast_Parser_parseSingleExpr_o;

/* ::corto::Fast::Parser::pass */
extern cx_member Fast_Parser_pass_o;

/* ::corto::Fast::Parser::popComplexType() */
extern cx_method Fast_Parser_popComplexType_o;

/* ::corto::Fast::Parser::popLvalue() */
extern cx_method Fast_Parser_popLvalue_o;

/* ::corto::Fast::Parser::popScope(object previous) */
extern cx_method Fast_Parser_popScope_o;

/* ::corto::Fast::Parser::postfixExpr(Fast::Expression lvalue,operatorKind operator) */
extern cx_method Fast_Parser_postfixExpr_o;

/* ::corto::Fast::Parser::preprocessed */
extern cx_member Fast_Parser_preprocessed_o;

/* ::corto::Fast::Parser::pushComplexType(Fast::Expression lvalue) */
extern cx_method Fast_Parser_pushComplexType_o;

/* ::corto::Fast::Parser::pushLvalue(Fast::Expression lvalue,bool isAssignment) */
extern cx_method Fast_Parser_pushLvalue_o;

/* ::corto::Fast::Parser::pushPackage(string name) */
extern cx_method Fast_Parser_pushPackage_o;

/* ::corto::Fast::Parser::pushReturnAsLvalue(function function) */
extern cx_method Fast_Parser_pushReturnAsLvalue_o;

/* ::corto::Fast::Parser::pushScope() */
extern cx_method Fast_Parser_pushScope_o;

/* ::corto::Fast::Parser::repl */
extern cx_member Fast_Parser_repl_o;

/* ::corto::Fast::Parser::reset() */
extern cx_method Fast_Parser_reset_o;

/* ::corto::Fast::Parser::scope */
extern cx_member Fast_Parser_scope_o;

/* ::corto::Fast::Parser::singleExpr */
extern cx_member Fast_Parser_singleExpr_o;

/* ::corto::Fast::Parser::source */
extern cx_member Fast_Parser_source_o;

/* ::corto::Fast::Parser::staged */
extern cx_member Fast_Parser_staged_o;

/* ::corto::Fast::Parser::stagedCount */
extern cx_member Fast_Parser_stagedCount_o;

/* ::corto::Fast::Parser::stagedId */
extern cx_struct Fast_Parser_stagedId_o;

/* ::corto::Fast::Parser::stagedId::column */
extern cx_member Fast_Parser_stagedId_column_o;

/* ::corto::Fast::Parser::stagedId::found */
extern cx_member Fast_Parser_stagedId_found_o;

/* ::corto::Fast::Parser::stagedId::line */
extern cx_member Fast_Parser_stagedId_line_o;

/* ::corto::Fast::Parser::stagedId::name */
extern cx_member Fast_Parser_stagedId_name_o;

/* ::corto::Fast::Parser::stagingAllowed */
extern cx_member Fast_Parser_stagingAllowed_o;

/* ::corto::Fast::Parser::ternaryExpr(Fast::Expression cond,Fast::Expression iftrue,Fast::Expression iffalse) */
extern cx_method Fast_Parser_ternaryExpr_o;

/* ::corto::Fast::Parser::token */
extern cx_member Fast_Parser_token_o;

/* ::corto::Fast::Parser::unaryExpr(Fast::Expression lvalue,operatorKind operator) */
extern cx_method Fast_Parser_unaryExpr_o;

/* ::corto::Fast::Parser::updateStatement(Fast::Expression expr,Fast::Block block) */
extern cx_method Fast_Parser_updateStatement_o;

/* ::corto::Fast::Parser::variableCount */
extern cx_member Fast_Parser_variableCount_o;

/* ::corto::Fast::Parser::variablePushed */
extern cx_member Fast_Parser_variablePushed_o;

/* ::corto::Fast::Parser::variables */
extern cx_member Fast_Parser_variables_o;

/* ::corto::Fast::Parser::variablesInitialized */
extern cx_member Fast_Parser_variablesInitialized_o;

/* ::corto::Fast::Parser::waitExpr(Fast::Expression expr,Fast::Expression timeout) */
extern cx_method Fast_Parser_waitExpr_o;

/* ::corto::Fast::Parser::warnings */
extern cx_member Fast_Parser_warnings_o;

/* ::corto::Fast::Parser::whileStatement(Fast::Expression condition,Fast::Block trueBranch,bool isUntil) */
extern cx_method Fast_Parser_whileStatement_o;

/* ::corto::Fast::ParserDeclaration */
extern cx_struct Fast_ParserDeclaration_o;

/* ::corto::Fast::ParserDeclaration::name */
extern cx_member Fast_ParserDeclaration_name_o;

/* ::corto::Fast::ParserDeclaration::storage */
extern cx_member Fast_ParserDeclaration_storage_o;

/* ::corto::Fast::ParserDeclarationSeq */
extern cx_sequence Fast_ParserDeclarationSeq_o;

/* ::corto::Fast::ParserNew */
extern cx_struct Fast_ParserNew_o;

/* ::corto::Fast::ParserNew::attr */
extern cx_member Fast_ParserNew_attr_o;

/* ::corto::Fast::ParserNew::kind */
extern cx_member Fast_ParserNew_kind_o;

/* ::corto::Fast::ParserNew::name */
extern cx_member Fast_ParserNew_name_o;

/* ::corto::Fast::ParserNew::parent */
extern cx_member Fast_ParserNew_parent_o;

/* ::corto::Fast::PostFix */
extern cx_class Fast_PostFix_o;

/* ::corto::Fast::PostFix::construct() */
extern cx_method Fast_PostFix_construct_o;

/* ::corto::Fast::PostFix::hasReturnedResource() */
extern cx_virtual Fast_PostFix_hasReturnedResource_o;

/* ::corto::Fast::PostFix::lvalue */
extern cx_member Fast_PostFix_lvalue_o;

/* ::corto::Fast::PostFix::operator */
extern cx_member Fast_PostFix_operator_o;

/* ::corto::Fast::PostFix::toIc(ic::program program,ic::storage storage,bool stored) */
extern cx_virtual Fast_PostFix_toIc_o;

/* ::corto::Fast::report(string kind,string filename,uint32 line,uint32 column,string error,string token) */
extern cx_function Fast_report_o;

/* ::corto::Fast::reportError(string filename,uint32 line,uint32 column,string error,string token) */
extern cx_function Fast_reportError_o;

/* ::corto::Fast::reportWarning(string filename,uint32 line,uint32 column,string error,string token) */
extern cx_function Fast_reportWarning_o;

/* ::corto::Fast::SignedInteger */
extern cx_class Fast_SignedInteger_o;

/* ::corto::Fast::SignedInteger::init() */
extern cx_method Fast_SignedInteger_init_o;

/* ::corto::Fast::SignedInteger::serialize(type dstType,word dst) */
extern cx_method Fast_SignedInteger_serialize_o;

/* ::corto::Fast::SignedInteger::toIc(ic::program program,ic::storage storage,bool stored) */
extern cx_virtual Fast_SignedInteger_toIc_o;

/* ::corto::Fast::SignedInteger::value */
extern cx_member Fast_SignedInteger_value_o;

/* ::corto::Fast::StaticCall */
extern cx_class Fast_StaticCall_o;

/* ::corto::Fast::StaticCall::construct() */
extern cx_method Fast_StaticCall_construct_o;

/* ::corto::Fast::StaticCall::function */
extern cx_member Fast_StaticCall_function_o;

/* ::corto::Fast::StaticInitializer */
extern cx_class Fast_StaticInitializer_o;

/* ::corto::Fast::StaticInitializer::construct() */
extern cx_method Fast_StaticInitializer_construct_o;

/* ::corto::Fast::StaticInitializer::define() */
extern cx_method Fast_StaticInitializer_define_o;

/* ::corto::Fast::StaticInitializer::frames */
extern cx_member Fast_StaticInitializer_frames_o;

/* ::corto::Fast::StaticInitializer::push() */
extern cx_method Fast_StaticInitializer_push_o;

/* ::corto::Fast::StaticInitializer::value(Expression v) */
extern cx_method Fast_StaticInitializer_value_o;

/* ::corto::Fast::StaticInitializerFrame */
extern cx_struct Fast_StaticInitializerFrame_o;

/* ::corto::Fast::StaticInitializerFrame::keyPtr */
extern cx_member Fast_StaticInitializerFrame_keyPtr_o;

/* ::corto::Fast::StaticInitializerFrame::ptr */
extern cx_member Fast_StaticInitializerFrame_ptr_o;

/* ::corto::Fast::Storage */
extern cx_class Fast_Storage_o;

/* ::corto::Fast::Storage::construct() */
extern cx_method Fast_Storage_construct_o;

/* ::corto::Fast::Storage::kind */
extern cx_member Fast_Storage_kind_o;

/* ::corto::Fast::storageKind */
extern cx_enum Fast_storageKind_o;

/* ::corto::Fast::storageKind::ElementStorage */
extern cx_constant (*Fast_storageKind_ElementStorage_o);

/* ::corto::Fast::storageKind::LocalStorage */
extern cx_constant (*Fast_storageKind_LocalStorage_o);

/* ::corto::Fast::storageKind::MemberStorage */
extern cx_constant (*Fast_storageKind_MemberStorage_o);

/* ::corto::Fast::storageKind::ObjectStorage */
extern cx_constant (*Fast_storageKind_ObjectStorage_o);

/* ::corto::Fast::storageKind::TemplateStorage */
extern cx_constant (*Fast_storageKind_TemplateStorage_o);

/* ::corto::Fast::storageKind::TemporaryStorage */
extern cx_constant (*Fast_storageKind_TemporaryStorage_o);

/* ::corto::Fast::String */
extern cx_class Fast_String_o;

/* ::corto::Fast::String::block */
extern cx_member Fast_String_block_o;

/* ::corto::Fast::String::construct() */
extern cx_method Fast_String_construct_o;

/* ::corto::Fast::String::elements */
extern cx_member Fast_String_elements_o;

/* ::corto::Fast::String::getValue() */
extern cx_method Fast_String_getValue_o;

/* ::corto::Fast::String::init() */
extern cx_method Fast_String_init_o;

/* ::corto::Fast::String::scope */
extern cx_member Fast_String_scope_o;

/* ::corto::Fast::String::serialize(type dstType,word dst) */
extern cx_method Fast_String_serialize_o;

/* ::corto::Fast::String::toIc(ic::program program,ic::storage storage,bool stored) */
extern cx_virtual Fast_String_toIc_o;

/* ::corto::Fast::String::value */
extern cx_member Fast_String_value_o;

/* ::corto::Fast::Template */
extern cx_class Fast_Template_o;

/* ::corto::Fast::Template::construct() */
extern cx_method Fast_Template_construct_o;

/* ::corto::Fast::Temporary */
extern cx_class Fast_Temporary_o;

/* ::corto::Fast::Temporary::construct() */
extern cx_method Fast_Temporary_construct_o;

/* ::corto::Fast::Temporary::ic */
extern cx_member Fast_Temporary_ic_o;

/* ::corto::Fast::Temporary::proxy */
extern cx_member Fast_Temporary_proxy_o;

/* ::corto::Fast::Temporary::reference */
extern cx_member Fast_Temporary_reference_o;

/* ::corto::Fast::Temporary::setProxy(Temporary proxy) */
extern cx_method Fast_Temporary_setProxy_o;

/* ::corto::Fast::Temporary::toIc(ic::program program,ic::storage storage,bool stored) */
extern cx_virtual Fast_Temporary_toIc_o;

/* ::corto::Fast::Temporary::type */
extern cx_member Fast_Temporary_type_o;

/* ::corto::Fast::Ternary */
extern cx_class Fast_Ternary_o;

/* ::corto::Fast::Ternary::condition */
extern cx_member Fast_Ternary_condition_o;

/* ::corto::Fast::Ternary::construct() */
extern cx_method Fast_Ternary_construct_o;

/* ::corto::Fast::Ternary::hasReturnedResource() */
extern cx_virtual Fast_Ternary_hasReturnedResource_o;

/* ::corto::Fast::Ternary::hasSideEffects() */
extern cx_virtual Fast_Ternary_hasSideEffects_o;

/* ::corto::Fast::Ternary::ifFalse */
extern cx_member Fast_Ternary_ifFalse_o;

/* ::corto::Fast::Ternary::ifFalseExpr */
extern cx_member Fast_Ternary_ifFalseExpr_o;

/* ::corto::Fast::Ternary::ifstmt */
extern cx_member Fast_Ternary_ifstmt_o;

/* ::corto::Fast::Ternary::ifTrue */
extern cx_member Fast_Ternary_ifTrue_o;

/* ::corto::Fast::Ternary::ifTrueExpr */
extern cx_member Fast_Ternary_ifTrueExpr_o;

/* ::corto::Fast::Ternary::result */
extern cx_member Fast_Ternary_result_o;

/* ::corto::Fast::Ternary::setOperator(operatorKind kind) */
extern cx_method Fast_Ternary_setOperator_o;

/* ::corto::Fast::Ternary::toIc(ic::program program,ic::storage storage,bool stored) */
extern cx_virtual Fast_Ternary_toIc_o;

/* ::corto::Fast::Unary */
extern cx_class Fast_Unary_o;

/* ::corto::Fast::Unary::construct() */
extern cx_method Fast_Unary_construct_o;

/* ::corto::Fast::Unary::hasReturnedResource() */
extern cx_virtual Fast_Unary_hasReturnedResource_o;

/* ::corto::Fast::Unary::hasSideEffects() */
extern cx_virtual Fast_Unary_hasSideEffects_o;

/* ::corto::Fast::Unary::lvalue */
extern cx_member Fast_Unary_lvalue_o;

/* ::corto::Fast::Unary::operator */
extern cx_member Fast_Unary_operator_o;

/* ::corto::Fast::Unary::toIc(ic::program program,ic::storage storage,bool stored) */
extern cx_virtual Fast_Unary_toIc_o;

/* ::corto::Fast::Update */
extern cx_class Fast_Update_o;

/* ::corto::Fast::Update::block */
extern cx_member Fast_Update_block_o;

/* ::corto::Fast::Update::construct() */
extern cx_method Fast_Update_construct_o;

/* ::corto::Fast::Update::exprList */
extern cx_member Fast_Update_exprList_o;

/* ::corto::Fast::Update::from */
extern cx_member Fast_Update_from_o;

/* ::corto::Fast::Update::kind */
extern cx_member Fast_Update_kind_o;

/* ::corto::Fast::Update::toIc(ic::program program,ic::storage storage,bool stored) */
extern cx_virtual Fast_Update_toIc_o;

/* ::corto::Fast::UpdateKind */
extern cx_enum Fast_UpdateKind_o;

/* ::corto::Fast::UpdateKind::UpdateBegin */
extern cx_constant (*Fast_UpdateKind_UpdateBegin_o);

/* ::corto::Fast::UpdateKind::UpdateDefault */
extern cx_constant (*Fast_UpdateKind_UpdateDefault_o);

/* ::corto::Fast::UpdateKind::UpdateEnd */
extern cx_constant (*Fast_UpdateKind_UpdateEnd_o);

/* ::corto::Fast::valueKind */
extern cx_enum Fast_valueKind_o;

/* ::corto::Fast::valueKind::Bool */
extern cx_constant (*Fast_valueKind_Bool_o);

/* ::corto::Fast::valueKind::Char */
extern cx_constant (*Fast_valueKind_Char_o);

/* ::corto::Fast::valueKind::Enum */
extern cx_constant (*Fast_valueKind_Enum_o);

/* ::corto::Fast::valueKind::Float */
extern cx_constant (*Fast_valueKind_Float_o);

/* ::corto::Fast::valueKind::Int */
extern cx_constant (*Fast_valueKind_Int_o);

/* ::corto::Fast::valueKind::Nothing */
extern cx_constant (*Fast_valueKind_Nothing_o);

/* ::corto::Fast::valueKind::Ref */
extern cx_constant (*Fast_valueKind_Ref_o);

/* ::corto::Fast::valueKind::SignedInt */
extern cx_constant (*Fast_valueKind_SignedInt_o);

/* ::corto::Fast::valueKind::Text */
extern cx_constant (*Fast_valueKind_Text_o);

/* ::corto::Fast::valueKindFromType(type type) */
extern cx_function Fast_valueKindFromType_o;

/* ::corto::Fast::Wait */
extern cx_class Fast_Wait_o;

/* ::corto::Fast::Wait::construct() */
extern cx_method Fast_Wait_construct_o;

/* ::corto::Fast::Wait::exprList */
extern cx_member Fast_Wait_exprList_o;

/* ::corto::Fast::Wait::hasReturnedResource() */
extern cx_virtual Fast_Wait_hasReturnedResource_o;

/* ::corto::Fast::Wait::timeout */
extern cx_member Fast_Wait_timeout_o;

/* ::corto::Fast::Wait::toIc(ic::program program,ic::storage storage,bool stored) */
extern cx_virtual Fast_Wait_toIc_o;

/* ::corto::Fast::While */
extern cx_class Fast_While_o;

/* ::corto::Fast::While::condition */
extern cx_member Fast_While_condition_o;

/* ::corto::Fast::While::construct() */
extern cx_method Fast_While_construct_o;

/* ::corto::Fast::While::isUntil */
extern cx_member Fast_While_isUntil_o;

/* ::corto::Fast::While::toIc(ic::program program,ic::storage storage,bool stored) */
extern cx_virtual Fast_While_toIc_o;

/* ::corto::Fast::While::trueBranch */
extern cx_member Fast_While_trueBranch_o;

int Fast_load(void);
#ifdef __cplusplus
}
#endif
#endif

