/* Fast__meta.h
 *
 * Loads objects in database.
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_META_H
#define Fast_META_H

#include "hyve.h"

#include "Fast__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::hyve */
extern db_object _o;

/* ::hyve::Fast */
extern db_void (*Fast_o);

/* ::hyve::Fast::BinaryExpr */
extern db_class Fast_BinaryExpr_o;

/* ::hyve::Fast::BinaryExpr::construct(Fast::BinaryExpr object) */
extern db_callback Fast_BinaryExpr_construct_o;

/* ::hyve::Fast::BinaryExpr::fold() */
extern db_method Fast_BinaryExpr_fold_o;

/* ::hyve::Fast::BinaryExpr::hasSideEffects() */
extern db_virtual Fast_BinaryExpr_hasSideEffects_o;

/* ::hyve::Fast::BinaryExpr::lvalue */
extern db_member Fast_BinaryExpr_lvalue_o;

/* ::hyve::Fast::BinaryExpr::operator */
extern db_member Fast_BinaryExpr_operator_o;

/* ::hyve::Fast::BinaryExpr::rvalue */
extern db_member Fast_BinaryExpr_rvalue_o;

/* ::hyve::Fast::BinaryExpr::setOperator(lang::operatorKind kind) */
extern db_method Fast_BinaryExpr_setOperator_o;

/* ::hyve::Fast::BinaryExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
extern db_virtual Fast_BinaryExpr_toIc_o;

/* ::hyve::Fast::Binding */
extern db_struct Fast_Binding_o;

/* ::hyve::Fast::Binding::function */
extern db_member Fast_Binding_function_o;

/* ::hyve::Fast::Binding::impl */
extern db_member Fast_Binding_impl_o;

/* ::hyve::Fast::Block */
extern db_class Fast_Block_o;

/* ::hyve::Fast::Block::addStatement(Fast::Node statement) */
extern db_method Fast_Block_addStatement_o;

/* ::hyve::Fast::Block::declare(lang::string id,Fast::Variable type,lang::bool isParameter,bool isReference) */
extern db_method Fast_Block_declare_o;

/* ::hyve::Fast::Block::declareReturnVariable(lang::function function) */
extern db_method Fast_Block_declareReturnVariable_o;

/* ::hyve::Fast::Block::declareTemplate(lang::string id,Fast::Variable type,lang::bool isParameter,bool isReference) */
extern db_method Fast_Block_declareTemplate_o;

/* ::hyve::Fast::Block::function */
extern db_member Fast_Block_function_o;

/* ::hyve::Fast::Block::locals */
extern db_member Fast_Block_locals_o;

/* ::hyve::Fast::Block::lookup(lang::string id) */
extern db_method Fast_Block_lookup_o;

/* ::hyve::Fast::Block::lookupLocal(lang::string id) */
extern db_method Fast_Block_lookupLocal_o;

/* ::hyve::Fast::Block::parent */
extern db_member Fast_Block_parent_o;

/* ::hyve::Fast::Block::resolve(lang::string id) */
extern db_method Fast_Block_resolve_o;

/* ::hyve::Fast::Block::setFunction(lang::function function */
extern db_method Fast_Block_setFunction_o;

/* ::hyve::Fast::Block::statements */
extern db_member Fast_Block_statements_o;

/* ::hyve::Fast::Block::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
extern db_virtual Fast_Block_toIc_o;

/* ::hyve::Fast::Block::toIcBody(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
extern db_virtual Fast_Block_toIcBody_o;

/* ::hyve::Fast::Block::while */
extern db_member Fast_Block_while_o;

/* ::hyve::Fast::Boolean */
extern db_class Fast_Boolean_o;

/* ::hyve::Fast::Boolean::init(Boolean object) */
extern db_callback Fast_Boolean_init_o;

/* ::hyve::Fast::Boolean::serialize(lang::type dstType,lang::word dst) */
extern db_method Fast_Boolean_serialize_o;

/* ::hyve::Fast::Boolean::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
extern db_virtual Fast_Boolean_toIc_o;

/* ::hyve::Fast::Boolean::value */
extern db_member Fast_Boolean_value_o;

/* ::hyve::Fast::Call */
extern db_class Fast_Call_o;

/* ::hyve::Fast::Call::actualFunction */
extern db_member Fast_Call_actualFunction_o;

/* ::hyve::Fast::Call::arguments */
extern db_member Fast_Call_arguments_o;

/* ::hyve::Fast::Call::construct(Fast::Call object) */
extern db_callback Fast_Call_construct_o;

/* ::hyve::Fast::Call::function */
extern db_member Fast_Call_function_o;

/* ::hyve::Fast::Call::hasSideEffects() */
extern db_virtual Fast_Call_hasSideEffects_o;

/* ::hyve::Fast::Call::signature */
extern db_member Fast_Call_signature_o;

/* ::hyve::Fast::Call::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
extern db_virtual Fast_Call_toIc_o;

/* ::hyve::Fast::CastExpr */
extern db_class Fast_CastExpr_o;

/* ::hyve::Fast::CastExpr::construct(Fast::CastExpr object) */
extern db_callback Fast_CastExpr_construct_o;

/* ::hyve::Fast::CastExpr::lvalue */
extern db_member Fast_CastExpr_lvalue_o;

/* ::hyve::Fast::CastExpr::rvalue */
extern db_member Fast_CastExpr_rvalue_o;

/* ::hyve::Fast::CastExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
extern db_virtual Fast_CastExpr_toIc_o;

/* ::hyve::Fast::Character */
extern db_class Fast_Character_o;

/* ::hyve::Fast::Character::init(Character object) */
extern db_callback Fast_Character_init_o;

/* ::hyve::Fast::Character::serialize(lang::type dstType,lang::word dst) */
extern db_method Fast_Character_serialize_o;

/* ::hyve::Fast::Character::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
extern db_virtual Fast_Character_toIc_o;

/* ::hyve::Fast::Character::value */
extern db_member Fast_Character_value_o;

/* ::hyve::Fast::CommaExpr */
extern db_class Fast_CommaExpr_o;

/* ::hyve::Fast::CommaExpr::addExpression(Expression expr) */
extern db_method Fast_CommaExpr_addExpression_o;

/* ::hyve::Fast::CommaExpr::addOrCreate(Expression list,Expression expr) */
extern db_function Fast_CommaExpr_addOrCreate_o;

/* ::hyve::Fast::CommaExpr::construct(CommaExpr object) */
extern db_callback Fast_CommaExpr_construct_o;

/* ::hyve::Fast::CommaExpr::expressions */
extern db_member Fast_CommaExpr_expressions_o;

/* ::hyve::Fast::CommaExpr::hasSideEffects() */
extern db_virtual Fast_CommaExpr_hasSideEffects_o;

/* ::hyve::Fast::CommaExpr::init(CommaExpr object) */
extern db_callback Fast_CommaExpr_init_o;

/* ::hyve::Fast::CommaExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
extern db_virtual Fast_CommaExpr_toIc_o;

/* ::hyve::Fast::CommaExpr::toList() */
extern db_method Fast_CommaExpr_toList_o;

/* ::hyve::Fast::Define */
extern db_class Fast_Define_o;

/* ::hyve::Fast::Define::construct(Fast::Define object) */
extern db_callback Fast_Define_construct_o;

/* ::hyve::Fast::Define::object */
extern db_member Fast_Define_object_o;

/* ::hyve::Fast::Define::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
extern db_virtual Fast_Define_toIc_o;

/* ::hyve::Fast::DynamicInitializer */
extern db_class Fast_DynamicInitializer_o;

/* ::hyve::Fast::DynamicInitializer::assignValue */
extern db_member Fast_DynamicInitializer_assignValue_o;

/* ::hyve::Fast::DynamicInitializer::construct(DynamicInitializer object) */
extern db_callback Fast_DynamicInitializer_construct_o;

/* ::hyve::Fast::DynamicInitializer::define() */
extern db_method Fast_DynamicInitializer_define_o;

/* ::hyve::Fast::DynamicInitializer::frames */
extern db_member Fast_DynamicInitializer_frames_o;

/* ::hyve::Fast::DynamicInitializer::pop() */
extern db_method Fast_DynamicInitializer_pop_o;

/* ::hyve::Fast::DynamicInitializer::push() */
extern db_method Fast_DynamicInitializer_push_o;

/* ::hyve::Fast::DynamicInitializer::value(Expression v) */
extern db_method Fast_DynamicInitializer_value_o;

/* ::hyve::Fast::DynamicInitializerFrame */
extern db_struct Fast_DynamicInitializerFrame_o;

/* ::hyve::Fast::DynamicInitializerFrame::expr */
extern db_member Fast_DynamicInitializerFrame_expr_o;

/* ::hyve::Fast::DynamicInitializerFrame::keyExpr */
extern db_member Fast_DynamicInitializerFrame_keyExpr_o;

/* ::hyve::Fast::DynamicInitializerFrame::sequenceSize */
extern db_member Fast_DynamicInitializerFrame_sequenceSize_o;

/* ::hyve::Fast::ElementExpr */
extern db_class Fast_ElementExpr_o;

/* ::hyve::Fast::ElementExpr::construct(Fast::MemberExpr object) */
extern db_callback Fast_ElementExpr_construct_o;

/* ::hyve::Fast::ElementExpr::lvalue */
extern db_member Fast_ElementExpr_lvalue_o;

/* ::hyve::Fast::ElementExpr::rvalue */
extern db_member Fast_ElementExpr_rvalue_o;

/* ::hyve::Fast::ElementExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
extern db_virtual Fast_ElementExpr_toIc_o;

/* ::hyve::Fast::Expression */
extern db_class Fast_Expression_o;

/* ::hyve::Fast::Expression::cast(lang::type type) */
extern db_method Fast_Expression_cast_o;

/* ::hyve::Fast::Expression::cleanList(list{Expression} list) */
extern db_function Fast_Expression_cleanList_o;

/* ::hyve::Fast::Expression::fold() */
extern db_virtual Fast_Expression_fold_o;

/* ::hyve::Fast::Expression::forceReference */
extern db_member Fast_Expression_forceReference_o;

/* ::hyve::Fast::Expression::fromList(list{Expression} list) */
extern db_function Fast_Expression_fromList_o;

/* ::hyve::Fast::Expression::getType() */
extern db_method Fast_Expression_getType_o;

/* ::hyve::Fast::Expression::getType_expr(Expression target) */
extern db_method Fast_Expression_getType_expr_o;

/* ::hyve::Fast::Expression::getType_type(lang::type target) */
extern db_method Fast_Expression_getType_type_o;

/* ::hyve::Fast::Expression::getValue() */
extern db_virtual Fast_Expression_getValue_o;

/* ::hyve::Fast::Expression::hasSideEffects() */
extern db_virtual Fast_Expression_hasSideEffects_o;

/* ::hyve::Fast::Expression::init(Expression object) */
extern db_callback Fast_Expression_init_o;

/* ::hyve::Fast::Expression::isReference */
extern db_member Fast_Expression_isReference_o;

/* ::hyve::Fast::Expression::serialize(lang::type dstType,lang::word dst) */
extern db_virtual Fast_Expression_serialize_o;

/* ::hyve::Fast::Expression::toList() */
extern db_virtual Fast_Expression_toList_o;

/* ::hyve::Fast::Expression::type */
extern db_member Fast_Expression_type_o;

/* ::hyve::Fast::FloatingPoint */
extern db_class Fast_FloatingPoint_o;

/* ::hyve::Fast::FloatingPoint::init(FloatingPoint object) */
extern db_callback Fast_FloatingPoint_init_o;

/* ::hyve::Fast::FloatingPoint::serialize(lang::type dstType,lang::word dst) */
extern db_method Fast_FloatingPoint_serialize_o;

/* ::hyve::Fast::FloatingPoint::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
extern db_virtual Fast_FloatingPoint_toIc_o;

/* ::hyve::Fast::FloatingPoint::value */
extern db_member Fast_FloatingPoint_value_o;

/* ::hyve::Fast::If */
extern db_class Fast_If_o;

/* ::hyve::Fast::If::condition */
extern db_member Fast_If_condition_o;

/* ::hyve::Fast::If::construct(If object) */
extern db_callback Fast_If_construct_o;

/* ::hyve::Fast::If::falseBranch */
extern db_member Fast_If_falseBranch_o;

/* ::hyve::Fast::If::noWarnUnreachable() */
extern db_method Fast_If_noWarnUnreachable_o;

/* ::hyve::Fast::If::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
extern db_virtual Fast_If_toIc_o;

/* ::hyve::Fast::If::trueBranch */
extern db_member Fast_If_trueBranch_o;

/* ::hyve::Fast::If::warnUnreachable */
extern db_member Fast_If_warnUnreachable_o;

/* ::hyve::Fast::Initializer */
extern db_class Fast_Initializer_o;

/* ::hyve::Fast::Initializer::construct(Initializer object) */
extern db_callback Fast_Initializer_construct_o;

/* ::hyve::Fast::Initializer::currentType() */
extern db_method Fast_Initializer_currentType_o;

/* ::hyve::Fast::Initializer::define() */
extern db_virtual Fast_Initializer_define_o;

/* ::hyve::Fast::Initializer::fp */
extern db_member Fast_Initializer_fp_o;

/* ::hyve::Fast::Initializer::frames */
extern db_member Fast_Initializer_frames_o;

/* ::hyve::Fast::Initializer::initFrame() */
extern db_method Fast_Initializer_initFrame_o;

/* ::hyve::Fast::Initializer::member(lang::string name) */
extern db_virtual Fast_Initializer_member_o;

/* ::hyve::Fast::Initializer::next() */
extern db_virtual Fast_Initializer_next_o;

/* ::hyve::Fast::Initializer::pop() */
extern db_virtual Fast_Initializer_pop_o;

/* ::hyve::Fast::Initializer::popKey() */
extern db_virtual Fast_Initializer_popKey_o;

/* ::hyve::Fast::Initializer::push() */
extern db_virtual Fast_Initializer_push_o;

/* ::hyve::Fast::Initializer::pushKey() */
extern db_virtual Fast_Initializer_pushKey_o;

/* ::hyve::Fast::Initializer::type() */
extern db_method Fast_Initializer_type_o;

/* ::hyve::Fast::Initializer::value(Expression v) */
extern db_virtual Fast_Initializer_value_o;

/* ::hyve::Fast::Initializer::valueKey(Expression key) */
extern db_virtual Fast_Initializer_valueKey_o;

/* ::hyve::Fast::Initializer::variableCount */
extern db_member Fast_Initializer_variableCount_o;

/* ::hyve::Fast::Initializer::variables */
extern db_member Fast_Initializer_variables_o;

/* ::hyve::Fast::InitializerExpr */
extern db_class Fast_InitializerExpr_o;

/* ::hyve::Fast::InitializerExpr::assignValue */
extern db_member Fast_InitializerExpr_assignValue_o;

/* ::hyve::Fast::InitializerExpr::construct(InitializerExpr object) */
extern db_callback Fast_InitializerExpr_construct_o;

/* ::hyve::Fast::InitializerExpr::define() */
extern db_method Fast_InitializerExpr_define_o;

/* ::hyve::Fast::InitializerExpr::insert(Expression variable) */
extern db_method Fast_InitializerExpr_insert_o;

/* ::hyve::Fast::InitializerExpr::member(lang::string name) */
extern db_method Fast_InitializerExpr_member_o;

/* ::hyve::Fast::InitializerExpr::operations */
extern db_member Fast_InitializerExpr_operations_o;

/* ::hyve::Fast::InitializerExpr::pop() */
extern db_method Fast_InitializerExpr_pop_o;

/* ::hyve::Fast::InitializerExpr::push() */
extern db_method Fast_InitializerExpr_push_o;

/* ::hyve::Fast::InitializerExpr::value(Expression v) */
extern db_method Fast_InitializerExpr_value_o;

/* ::hyve::Fast::InitializerFrame */
extern db_struct Fast_InitializerFrame_o;

/* ::hyve::Fast::InitializerFrame::isKey */
extern db_member Fast_InitializerFrame_isKey_o;

/* ::hyve::Fast::InitializerFrame::location */
extern db_member Fast_InitializerFrame_location_o;

/* ::hyve::Fast::InitializerFrame::member */
extern db_member Fast_InitializerFrame_member_o;

/* ::hyve::Fast::InitializerFrame::type */
extern db_member Fast_InitializerFrame_type_o;

/* ::hyve::Fast::InitializerKind */
extern db_enum Fast_InitializerKind_o;

/* ::hyve::Fast::InitializerKind::InitDynamic */
extern db_constant (*Fast_InitializerKind_InitDynamic_o);

/* ::hyve::Fast::InitializerKind::InitExpression */
extern db_constant (*Fast_InitializerKind_InitExpression_o);

/* ::hyve::Fast::InitializerKind::InitStatic */
extern db_constant (*Fast_InitializerKind_InitStatic_o);

/* ::hyve::Fast::InitializerVariable */
extern db_struct Fast_InitializerVariable_o;

/* ::hyve::Fast::InitializerVariable::key */
extern db_member Fast_InitializerVariable_key_o;

/* ::hyve::Fast::InitializerVariable::object */
extern db_member Fast_InitializerVariable_object_o;

/* ::hyve::Fast::InitializerVariable::offset */
extern db_member Fast_InitializerVariable_offset_o;

/* ::hyve::Fast::InitOper */
extern db_struct Fast_InitOper_o;

/* ::hyve::Fast::InitOper::expr */
extern db_member Fast_InitOper_expr_o;

/* ::hyve::Fast::InitOper::kind */
extern db_member Fast_InitOper_kind_o;

/* ::hyve::Fast::InitOper::name */
extern db_member Fast_InitOper_name_o;

/* ::hyve::Fast::InitOperKind */
extern db_enum Fast_InitOperKind_o;

/* ::hyve::Fast::InitOperKind::InitDefine */
extern db_constant (*Fast_InitOperKind_InitDefine_o);

/* ::hyve::Fast::InitOperKind::InitMember */
extern db_constant (*Fast_InitOperKind_InitMember_o);

/* ::hyve::Fast::InitOperKind::InitPop */
extern db_constant (*Fast_InitOperKind_InitPop_o);

/* ::hyve::Fast::InitOperKind::InitPush */
extern db_constant (*Fast_InitOperKind_InitPush_o);

/* ::hyve::Fast::InitOperKind::InitValue */
extern db_constant (*Fast_InitOperKind_InitValue_o);

/* ::hyve::Fast::Integer */
extern db_class Fast_Integer_o;

/* ::hyve::Fast::Integer::init(Integer object) */
extern db_callback Fast_Integer_init_o;

/* ::hyve::Fast::Integer::serialize(lang::type dstType,lang::word dst) */
extern db_method Fast_Integer_serialize_o;

/* ::hyve::Fast::Integer::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
extern db_virtual Fast_Integer_toIc_o;

/* ::hyve::Fast::Integer::value */
extern db_member Fast_Integer_value_o;

/* ::hyve::Fast::Literal */
extern db_class Fast_Literal_o;

/* ::hyve::Fast::Literal::getValue() */
extern db_virtual Fast_Literal_getValue_o;

/* ::hyve::Fast::Literal::init(Literal object) */
extern db_callback Fast_Literal_init_o;

/* ::hyve::Fast::Literal::kind */
extern db_member Fast_Literal_kind_o;

/* ::hyve::Fast::Local */
extern db_class Fast_Local_o;

/* ::hyve::Fast::Local::construct(Local object) */
extern db_callback Fast_Local_construct_o;

/* ::hyve::Fast::Local::isReference */
extern db_member Fast_Local_isReference_o;

/* ::hyve::Fast::Local::kind */
extern db_member Fast_Local_kind_o;

/* ::hyve::Fast::Local::name */
extern db_member Fast_Local_name_o;

/* ::hyve::Fast::Local::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
extern db_virtual Fast_Local_toIc_o;

/* ::hyve::Fast::Local::type */
extern db_member Fast_Local_type_o;

/* ::hyve::Fast::LocalKind */
extern db_enum Fast_LocalKind_o;

/* ::hyve::Fast::LocalKind::LocalDefault */
extern db_constant (*Fast_LocalKind_LocalDefault_o);

/* ::hyve::Fast::LocalKind::LocalParameter */
extern db_constant (*Fast_LocalKind_LocalParameter_o);

/* ::hyve::Fast::LocalKind::LocalReturn */
extern db_constant (*Fast_LocalKind_LocalReturn_o);

/* ::hyve::Fast::Lvalue */
extern db_struct Fast_Lvalue_o;

/* ::hyve::Fast::Lvalue::expr */
extern db_member Fast_Lvalue_expr_o;

/* ::hyve::Fast::Lvalue::isAssignment */
extern db_member Fast_Lvalue_isAssignment_o;

/* ::hyve::Fast::MemberExpr */
extern db_class Fast_MemberExpr_o;

/* ::hyve::Fast::MemberExpr::construct(Fast::MemberExpr object) */
extern db_callback Fast_MemberExpr_construct_o;

/* ::hyve::Fast::MemberExpr::hasSideEffects() */
extern db_virtual Fast_MemberExpr_hasSideEffects_o;

/* ::hyve::Fast::MemberExpr::lvalue */
extern db_member Fast_MemberExpr_lvalue_o;

/* ::hyve::Fast::MemberExpr::member */
extern db_member Fast_MemberExpr_member_o;

/* ::hyve::Fast::MemberExpr::rvalue */
extern db_member Fast_MemberExpr_rvalue_o;

/* ::hyve::Fast::MemberExpr::superMember */
extern db_member Fast_MemberExpr_superMember_o;

/* ::hyve::Fast::MemberExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
extern db_virtual Fast_MemberExpr_toIc_o;

/* ::hyve::Fast::NewExpr */
extern db_class Fast_NewExpr_o;

/* ::hyve::Fast::NewExpr::attributes */
extern db_member Fast_NewExpr_attributes_o;

/* ::hyve::Fast::NewExpr::construct(Fast::NewExpr object) */
extern db_callback Fast_NewExpr_construct_o;

/* ::hyve::Fast::NewExpr::hasSideEffects() */
extern db_virtual Fast_NewExpr_hasSideEffects_o;

/* ::hyve::Fast::NewExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
extern db_virtual Fast_NewExpr_toIc_o;

/* ::hyve::Fast::NewExpr::type */
extern db_member Fast_NewExpr_type_o;

/* ::hyve::Fast::Node */
extern db_class Fast_Node_o;

/* ::hyve::Fast::Node::column */
extern db_member Fast_Node_column_o;

/* ::hyve::Fast::Node::init(Node object) */
extern db_callback Fast_Node_init_o;

/* ::hyve::Fast::Node::kind */
extern db_member Fast_Node_kind_o;

/* ::hyve::Fast::Node::line */
extern db_member Fast_Node_line_o;

/* ::hyve::Fast::Node::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
extern db_virtual Fast_Node_toIc_o;

/* ::hyve::Fast::nodeKind */
extern db_enum Fast_nodeKind_o;

/* ::hyve::Fast::nodeKind::Binary */
extern db_constant (*Fast_nodeKind_Binary_o);

/* ::hyve::Fast::nodeKind::Call */
extern db_constant (*Fast_nodeKind_Call_o);

/* ::hyve::Fast::nodeKind::Cast */
extern db_constant (*Fast_nodeKind_Cast_o);

/* ::hyve::Fast::nodeKind::CommaExpr */
extern db_constant (*Fast_nodeKind_CommaExpr_o);

/* ::hyve::Fast::nodeKind::Declaration */
extern db_constant (*Fast_nodeKind_Declaration_o);

/* ::hyve::Fast::nodeKind::Declare */
extern db_constant (*Fast_nodeKind_Declare_o);

/* ::hyve::Fast::nodeKind::Define */
extern db_constant (*Fast_nodeKind_Define_o);

/* ::hyve::Fast::nodeKind::Element */
extern db_constant (*Fast_nodeKind_Element_o);

/* ::hyve::Fast::nodeKind::If */
extern db_constant (*Fast_nodeKind_If_o);

/* ::hyve::Fast::nodeKind::Initializer */
extern db_constant (*Fast_nodeKind_Initializer_o);

/* ::hyve::Fast::nodeKind::Literal */
extern db_constant (*Fast_nodeKind_Literal_o);

/* ::hyve::Fast::nodeKind::Member */
extern db_constant (*Fast_nodeKind_Member_o);

/* ::hyve::Fast::nodeKind::Method */
extern db_constant (*Fast_nodeKind_Method_o);

/* ::hyve::Fast::nodeKind::New */
extern db_constant (*Fast_nodeKind_New_o);

/* ::hyve::Fast::nodeKind::Postfix */
extern db_constant (*Fast_nodeKind_Postfix_o);

/* ::hyve::Fast::nodeKind::Ternary */
extern db_constant (*Fast_nodeKind_Ternary_o);

/* ::hyve::Fast::nodeKind::Unary */
extern db_constant (*Fast_nodeKind_Unary_o);

/* ::hyve::Fast::nodeKind::Update */
extern db_constant (*Fast_nodeKind_Update_o);

/* ::hyve::Fast::nodeKind::Variable */
extern db_constant (*Fast_nodeKind_Variable_o);

/* ::hyve::Fast::nodeKind::Wait */
extern db_constant (*Fast_nodeKind_Wait_o);

/* ::hyve::Fast::nodeKind::While */
extern db_constant (*Fast_nodeKind_While_o);

/* ::hyve::Fast::Null */
extern db_class Fast_Null_o;

/* ::hyve::Fast::Null::init(Null object) */
extern db_callback Fast_Null_init_o;

/* ::hyve::Fast::Null::serialize(lang::type dstType,lang::word dst) */
extern db_method Fast_Null_serialize_o;

/* ::hyve::Fast::Null::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
extern db_virtual Fast_Null_toIc_o;

/* ::hyve::Fast::Object */
extern db_class Fast_Object_o;

/* ::hyve::Fast::Object::construct(Object object) */
extern db_callback Fast_Object_construct_o;

/* ::hyve::Fast::Object::getValue() */
extern db_method Fast_Object_getValue_o;

/* ::hyve::Fast::Object::serialize(lang::type dstType,lang::word dst) */
extern db_method Fast_Object_serialize_o;

/* ::hyve::Fast::Object::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
extern db_virtual Fast_Object_toIc_o;

/* ::hyve::Fast::ObjectBase */
extern db_class Fast_ObjectBase_o;

/* ::hyve::Fast::ObjectBase::construct(ObjectBase object) */
extern db_callback Fast_ObjectBase_construct_o;

/* ::hyve::Fast::ObjectBase::value */
extern db_member Fast_ObjectBase_value_o;

/* ::hyve::Fast::Parser */
extern db_class Fast_Parser_o;

/* ::hyve::Fast::Parser::abort */
extern db_member Fast_Parser_abort_o;

/* ::hyve::Fast::Parser::addStatement(Fast::Node statement) */
extern db_method Fast_Parser_addStatement_o;

/* ::hyve::Fast::Parser::argumentToString(Fast::Variable type,lang::string id,lang::bool reference) */
extern db_method Fast_Parser_argumentToString_o;

/* ::hyve::Fast::Parser::binaryExpr(Fast::Expression lvalues,Fast::Expression rvalues,lang::operatorKind operator) */
extern db_method Fast_Parser_binaryExpr_o;

/* ::hyve::Fast::Parser::bind(Fast::Variable function,Fast::Block block) */
extern db_method Fast_Parser_bind_o;

/* ::hyve::Fast::Parser::bindings */
extern db_member Fast_Parser_bindings_o;

/* ::hyve::Fast::Parser::bindOneliner(Fast::Variable function,Fast::Block block,Fast::Expression expr) */
extern db_method Fast_Parser_bindOneliner_o;

/* ::hyve::Fast::Parser::block */
extern db_member Fast_Parser_block_o;

/* ::hyve::Fast::Parser::blockPop() */
extern db_method Fast_Parser_blockPop_o;

/* ::hyve::Fast::Parser::blockPreset */
extern db_member Fast_Parser_blockPreset_o;

/* ::hyve::Fast::Parser::blockPush(lang::bool presetBlock) */
extern db_method Fast_Parser_blockPush_o;

/* ::hyve::Fast::Parser::callExpr(Fast::Expression function,Fast::Expression arguments) */
extern db_method Fast_Parser_callExpr_o;

/* ::hyve::Fast::Parser::castExpr(Fast::Expression lvalue,Fast::Expression rvalue) */
extern db_method Fast_Parser_castExpr_o;

/* ::hyve::Fast::Parser::collect(lang::object o) */
extern db_method Fast_Parser_collect_o;

/* ::hyve::Fast::Parser::collected */
extern db_member Fast_Parser_collected_o;

/* ::hyve::Fast::Parser::collectHeap(word addr) */
extern db_method Fast_Parser_collectHeap_o;

/* ::hyve::Fast::Parser::column */
extern db_member Fast_Parser_column_o;

/* ::hyve::Fast::Parser::complexType */
extern db_member Fast_Parser_complexType_o;

/* ::hyve::Fast::Parser::complexTypeSp */
extern db_member Fast_Parser_complexTypeSp_o;

/* ::hyve::Fast::Parser::construct(Parser object) */
extern db_callback Fast_Parser_construct_o;

/* ::hyve::Fast::Parser::declaration(Variable type,lang::string id,lang::bool isReference) */
extern db_method Fast_Parser_declaration_o;

/* ::hyve::Fast::Parser::declareFunction(Variable returnType,lang::string id,lang::type kind,bool returnsReference) */
extern db_method Fast_Parser_declareFunction_o;

/* ::hyve::Fast::Parser::declareFunctionParams(Variable function) */
extern db_method Fast_Parser_declareFunctionParams_o;

/* ::hyve::Fast::Parser::define() */
extern db_method Fast_Parser_define_o;

/* ::hyve::Fast::Parser::defineScope() */
extern db_method Fast_Parser_defineScope_o;

/* ::hyve::Fast::Parser::defineVariable(Variable object) */
extern db_method Fast_Parser_defineVariable_o;

/* ::hyve::Fast::Parser::destruct(Parser object) */
extern db_callback Fast_Parser_destruct_o;

/* ::hyve::Fast::Parser::elementExpr(Fast::Expression lvalue,Fast::Expression rvalue) */
extern db_method Fast_Parser_elementExpr_o;

/* ::hyve::Fast::Parser::errLine */
extern db_member Fast_Parser_errLine_o;

/* ::hyve::Fast::Parser::errors */
extern db_member Fast_Parser_errors_o;

/* ::hyve::Fast::Parser::errSet */
extern db_member Fast_Parser_errSet_o;

/* ::hyve::Fast::Parser::filename */
extern db_member Fast_Parser_filename_o;

/* ::hyve::Fast::Parser::foreach(lang::string loopId,Fast::Expression collection) */
extern db_method Fast_Parser_foreach_o;

/* ::hyve::Fast::Parser::getComplexType() */
extern db_method Fast_Parser_getComplexType_o;

/* ::hyve::Fast::Parser::getLvalue(lang::bool assignment) */
extern db_method Fast_Parser_getLvalue_o;

/* ::hyve::Fast::Parser::getLvalueType(lang::bool assignment) */
extern db_method Fast_Parser_getLvalueType_o;

/* ::hyve::Fast::Parser::heapCollected */
extern db_member Fast_Parser_heapCollected_o;

/* ::hyve::Fast::Parser::ifStatement(Fast::Expression condition,Fast::Block trueBranch,Fast::If falseBranch) */
extern db_method Fast_Parser_ifStatement_o;

/* ::hyve::Fast::Parser::initAnonymousId */
extern db_member Fast_Parser_initAnonymousId_o;

/* ::hyve::Fast::Parser::initDeclareStaged(Fast::Expression expr) */
extern db_method Fast_Parser_initDeclareStaged_o;

/* ::hyve::Fast::Parser::initDynamic */
extern db_member Fast_Parser_initDynamic_o;

/* ::hyve::Fast::Parser::initializerCount */
extern db_member Fast_Parser_initializerCount_o;

/* ::hyve::Fast::Parser::initializers */
extern db_member Fast_Parser_initializers_o;

/* ::hyve::Fast::Parser::initKeyValuePop() */
extern db_method Fast_Parser_initKeyValuePop_o;

/* ::hyve::Fast::Parser::initKeyValuePush() */
extern db_method Fast_Parser_initKeyValuePush_o;

/* ::hyve::Fast::Parser::initKeyValueSet(Fast::Expression expr) */
extern db_method Fast_Parser_initKeyValueSet_o;

/* ::hyve::Fast::Parser::initMember(lang::string member) */
extern db_method Fast_Parser_initMember_o;

/* ::hyve::Fast::Parser::initPop() */
extern db_method Fast_Parser_initPop_o;

/* ::hyve::Fast::Parser::initPush() */
extern db_method Fast_Parser_initPush_o;

/* ::hyve::Fast::Parser::initPushExpression() */
extern db_method Fast_Parser_initPushExpression_o;

/* ::hyve::Fast::Parser::initPushIdentifier(Expression type) */
extern db_method Fast_Parser_initPushIdentifier_o;

/* ::hyve::Fast::Parser::initPushStatic() */
extern db_method Fast_Parser_initPushStatic_o;

/* ::hyve::Fast::Parser::initStage(lang::string id,bool found) */
extern db_method Fast_Parser_initStage_o;

/* ::hyve::Fast::Parser::initValue(Expression expr) */
extern db_method Fast_Parser_initValue_o;

/* ::hyve::Fast::Parser::isAbortSet() */
extern db_method Fast_Parser_isAbortSet_o;

/* ::hyve::Fast::Parser::isErrSet() */
extern db_method Fast_Parser_isErrSet_o;

/* ::hyve::Fast::Parser::isLocal */
extern db_member Fast_Parser_isLocal_o;

/* ::hyve::Fast::Parser::lastFailedResolve */
extern db_member Fast_Parser_lastFailedResolve_o;

/* ::hyve::Fast::Parser::line */
extern db_member Fast_Parser_line_o;

/* ::hyve::Fast::Parser::lookup(lang::string id,lang::object source) */
extern db_method Fast_Parser_lookup_o;

/* ::hyve::Fast::Parser::lvalue */
extern db_member Fast_Parser_lvalue_o;

/* ::hyve::Fast::Parser::lvalueSp */
extern db_member Fast_Parser_lvalueSp_o;

/* ::hyve::Fast::Parser::memberExpr(Fast::Expression lvalue,Fast::Expression rvalue) */
extern db_method Fast_Parser_memberExpr_o;

/* ::hyve::Fast::Parser::observerDeclaration(lang::string id,Fast::Expression object,lang::eventMask mask,Fast::Object dispatcher) */
extern db_method Fast_Parser_observerDeclaration_o;

/* ::hyve::Fast::Parser::observerPop() */
extern db_method Fast_Parser_observerPop_o;

/* ::hyve::Fast::Parser::observerPush() */
extern db_method Fast_Parser_observerPush_o;

/* ::hyve::Fast::Parser::parse() */
extern db_method Fast_Parser_parse_o;

/* ::hyve::Fast::Parser::parseExpression(lang::string expr,Fast::Block block,Fast::Variable scope,uint32 line,uint32 column) */
extern db_method Fast_Parser_parseExpression_o;

/* ::hyve::Fast::Parser::parseSingleExpr */
extern db_member Fast_Parser_parseSingleExpr_o;

/* ::hyve::Fast::Parser::pass */
extern db_member Fast_Parser_pass_o;

/* ::hyve::Fast::Parser::popComplexType() */
extern db_method Fast_Parser_popComplexType_o;

/* ::hyve::Fast::Parser::popLvalue() */
extern db_method Fast_Parser_popLvalue_o;

/* ::hyve::Fast::Parser::popScope(Fast::Variable previous) */
extern db_method Fast_Parser_popScope_o;

/* ::hyve::Fast::Parser::postfixExpr(Fast::Expression lvalue,lang::operatorKind operator) */
extern db_method Fast_Parser_postfixExpr_o;

/* ::hyve::Fast::Parser::preprocessed */
extern db_member Fast_Parser_preprocessed_o;

/* ::hyve::Fast::Parser::pushComplexType(Fast::Expression lvalue) */
extern db_method Fast_Parser_pushComplexType_o;

/* ::hyve::Fast::Parser::pushLvalue(Fast::Expression lvalue,lang::bool isAssignment) */
extern db_method Fast_Parser_pushLvalue_o;

/* ::hyve::Fast::Parser::pushReturnAsLvalue(lang::function function) */
extern db_method Fast_Parser_pushReturnAsLvalue_o;

/* ::hyve::Fast::Parser::pushScope() */
extern db_method Fast_Parser_pushScope_o;

/* ::hyve::Fast::Parser::reset() */
extern db_method Fast_Parser_reset_o;

/* ::hyve::Fast::Parser::scope */
extern db_member Fast_Parser_scope_o;

/* ::hyve::Fast::Parser::singleExpr */
extern db_member Fast_Parser_singleExpr_o;

/* ::hyve::Fast::Parser::source */
extern db_member Fast_Parser_source_o;

/* ::hyve::Fast::Parser::staged */
extern db_member Fast_Parser_staged_o;

/* ::hyve::Fast::Parser::stagedCount */
extern db_member Fast_Parser_stagedCount_o;

/* ::hyve::Fast::Parser::stagedId */
extern db_struct Fast_Parser_stagedId_o;

/* ::hyve::Fast::Parser::stagedId::column */
extern db_member Fast_Parser_stagedId_column_o;

/* ::hyve::Fast::Parser::stagedId::found */
extern db_member Fast_Parser_stagedId_found_o;

/* ::hyve::Fast::Parser::stagedId::line */
extern db_member Fast_Parser_stagedId_line_o;

/* ::hyve::Fast::Parser::stagedId::name */
extern db_member Fast_Parser_stagedId_name_o;

/* ::hyve::Fast::Parser::stagingAllowed */
extern db_member Fast_Parser_stagingAllowed_o;

/* ::hyve::Fast::Parser::ternaryExpr(Fast::Expression cond,Fast::Expression iftrue,Fast::Expression iffalse) */
extern db_method Fast_Parser_ternaryExpr_o;

/* ::hyve::Fast::Parser::token */
extern db_member Fast_Parser_token_o;

/* ::hyve::Fast::Parser::unaryExpr(Fast::Expression lvalue,lang::operatorKind operator) */
extern db_method Fast_Parser_unaryExpr_o;

/* ::hyve::Fast::Parser::updateStatement(Fast::Expression expr,Fast::Block block) */
extern db_method Fast_Parser_updateStatement_o;

/* ::hyve::Fast::Parser::variableCount */
extern db_member Fast_Parser_variableCount_o;

/* ::hyve::Fast::Parser::variablePushed */
extern db_member Fast_Parser_variablePushed_o;

/* ::hyve::Fast::Parser::variables */
extern db_member Fast_Parser_variables_o;

/* ::hyve::Fast::Parser::variablesInitialized */
extern db_member Fast_Parser_variablesInitialized_o;

/* ::hyve::Fast::Parser::waitExpr(list{Fast::Expression} exprList,Fast::Expression timeout) */
extern db_method Fast_Parser_waitExpr_o;

/* ::hyve::Fast::Parser::warnings */
extern db_member Fast_Parser_warnings_o;

/* ::hyve::Fast::Parser::whileStatement(Fast::Expression condition,Fast::Block trueBranch,lang::bool isUntil) */
extern db_method Fast_Parser_whileStatement_o;

/* ::hyve::Fast::ParserDeclaration */
extern db_struct Fast_ParserDeclaration_o;

/* ::hyve::Fast::ParserDeclaration::name */
extern db_member Fast_ParserDeclaration_name_o;

/* ::hyve::Fast::ParserDeclaration::variable */
extern db_member Fast_ParserDeclaration_variable_o;

/* ::hyve::Fast::ParserDeclarationSeq */
extern db_typedef Fast_ParserDeclarationSeq_o;

/* ::hyve::Fast::ParserNew */
extern db_struct Fast_ParserNew_o;

/* ::hyve::Fast::ParserNew::attr */
extern db_member Fast_ParserNew_attr_o;

/* ::hyve::Fast::ParserNew::kind */
extern db_member Fast_ParserNew_kind_o;

/* ::hyve::Fast::ParserNew::name */
extern db_member Fast_ParserNew_name_o;

/* ::hyve::Fast::ParserNew::parent */
extern db_member Fast_ParserNew_parent_o;

/* ::hyve::Fast::PostfixExpr */
extern db_class Fast_PostfixExpr_o;

/* ::hyve::Fast::PostfixExpr::construct(Fast::PostfixExpr object) */
extern db_callback Fast_PostfixExpr_construct_o;

/* ::hyve::Fast::PostfixExpr::lvalue */
extern db_member Fast_PostfixExpr_lvalue_o;

/* ::hyve::Fast::PostfixExpr::operator */
extern db_member Fast_PostfixExpr_operator_o;

/* ::hyve::Fast::PostfixExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
extern db_virtual Fast_PostfixExpr_toIc_o;

/* ::hyve::Fast::SignedInteger */
extern db_class Fast_SignedInteger_o;

/* ::hyve::Fast::SignedInteger::init(SignedInteger object) */
extern db_callback Fast_SignedInteger_init_o;

/* ::hyve::Fast::SignedInteger::serialize(lang::type dstType,lang::word dst) */
extern db_method Fast_SignedInteger_serialize_o;

/* ::hyve::Fast::SignedInteger::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
extern db_virtual Fast_SignedInteger_toIc_o;

/* ::hyve::Fast::SignedInteger::value */
extern db_member Fast_SignedInteger_value_o;

/* ::hyve::Fast::StaticInitializer */
extern db_class Fast_StaticInitializer_o;

/* ::hyve::Fast::StaticInitializer::construct(StaticInitializer object) */
extern db_callback Fast_StaticInitializer_construct_o;

/* ::hyve::Fast::StaticInitializer::define() */
extern db_method Fast_StaticInitializer_define_o;

/* ::hyve::Fast::StaticInitializer::frames */
extern db_member Fast_StaticInitializer_frames_o;

/* ::hyve::Fast::StaticInitializer::push() */
extern db_method Fast_StaticInitializer_push_o;

/* ::hyve::Fast::StaticInitializer::value(Expression v) */
extern db_method Fast_StaticInitializer_value_o;

/* ::hyve::Fast::StaticInitializerFrame */
extern db_struct Fast_StaticInitializerFrame_o;

/* ::hyve::Fast::StaticInitializerFrame::keyPtr */
extern db_member Fast_StaticInitializerFrame_keyPtr_o;

/* ::hyve::Fast::StaticInitializerFrame::ptr */
extern db_member Fast_StaticInitializerFrame_ptr_o;

/* ::hyve::Fast::String */
extern db_class Fast_String_o;

/* ::hyve::Fast::String::block */
extern db_member Fast_String_block_o;

/* ::hyve::Fast::String::construct(String object) */
extern db_callback Fast_String_construct_o;

/* ::hyve::Fast::String::elements */
extern db_member Fast_String_elements_o;

/* ::hyve::Fast::String::getValue() */
extern db_method Fast_String_getValue_o;

/* ::hyve::Fast::String::init(String object) */
extern db_callback Fast_String_init_o;

/* ::hyve::Fast::String::scope */
extern db_member Fast_String_scope_o;

/* ::hyve::Fast::String::serialize(lang::type dstType,lang::word dst) */
extern db_method Fast_String_serialize_o;

/* ::hyve::Fast::String::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
extern db_virtual Fast_String_toIc_o;

/* ::hyve::Fast::String::value */
extern db_member Fast_String_value_o;

/* ::hyve::Fast::Template */
extern db_class Fast_Template_o;

/* ::hyve::Fast::Template::construct(Template object) */
extern db_callback Fast_Template_construct_o;

/* ::hyve::Fast::TernaryExpr */
extern db_class Fast_TernaryExpr_o;

/* ::hyve::Fast::TernaryExpr::condition */
extern db_member Fast_TernaryExpr_condition_o;

/* ::hyve::Fast::TernaryExpr::construct(Fast::TernaryExpr object) */
extern db_callback Fast_TernaryExpr_construct_o;

/* ::hyve::Fast::TernaryExpr::hasSideEffects() */
extern db_virtual Fast_TernaryExpr_hasSideEffects_o;

/* ::hyve::Fast::TernaryExpr::ifFalse */
extern db_member Fast_TernaryExpr_ifFalse_o;

/* ::hyve::Fast::TernaryExpr::ifFalseExpr */
extern db_member Fast_TernaryExpr_ifFalseExpr_o;

/* ::hyve::Fast::TernaryExpr::ifstmt */
extern db_member Fast_TernaryExpr_ifstmt_o;

/* ::hyve::Fast::TernaryExpr::ifTrue */
extern db_member Fast_TernaryExpr_ifTrue_o;

/* ::hyve::Fast::TernaryExpr::ifTrueExpr */
extern db_member Fast_TernaryExpr_ifTrueExpr_o;

/* ::hyve::Fast::TernaryExpr::result */
extern db_member Fast_TernaryExpr_result_o;

/* ::hyve::Fast::TernaryExpr::setOperator(lang::operatorKind kind) */
extern db_method Fast_TernaryExpr_setOperator_o;

/* ::hyve::Fast::TernaryExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
extern db_virtual Fast_TernaryExpr_toIc_o;

/* ::hyve::Fast::UnaryExpr */
extern db_class Fast_UnaryExpr_o;

/* ::hyve::Fast::UnaryExpr::construct(Fast::UnaryExpr object) */
extern db_callback Fast_UnaryExpr_construct_o;

/* ::hyve::Fast::UnaryExpr::hasSideEffects() */
extern db_virtual Fast_UnaryExpr_hasSideEffects_o;

/* ::hyve::Fast::UnaryExpr::lvalue */
extern db_member Fast_UnaryExpr_lvalue_o;

/* ::hyve::Fast::UnaryExpr::operator */
extern db_member Fast_UnaryExpr_operator_o;

/* ::hyve::Fast::UnaryExpr::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
extern db_virtual Fast_UnaryExpr_toIc_o;

/* ::hyve::Fast::Update */
extern db_class Fast_Update_o;

/* ::hyve::Fast::Update::block */
extern db_member Fast_Update_block_o;

/* ::hyve::Fast::Update::construct(Update object) */
extern db_callback Fast_Update_construct_o;

/* ::hyve::Fast::Update::exprList */
extern db_member Fast_Update_exprList_o;

/* ::hyve::Fast::Update::from */
extern db_member Fast_Update_from_o;

/* ::hyve::Fast::Update::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
extern db_virtual Fast_Update_toIc_o;

/* ::hyve::Fast::valueKind */
extern db_enum Fast_valueKind_o;

/* ::hyve::Fast::valueKind::Boolean */
extern db_constant (*Fast_valueKind_Boolean_o);

/* ::hyve::Fast::valueKind::Character */
extern db_constant (*Fast_valueKind_Character_o);

/* ::hyve::Fast::valueKind::Enumerated */
extern db_constant (*Fast_valueKind_Enumerated_o);

/* ::hyve::Fast::valueKind::FloatingPoint */
extern db_constant (*Fast_valueKind_FloatingPoint_o);

/* ::hyve::Fast::valueKind::Integer */
extern db_constant (*Fast_valueKind_Integer_o);

/* ::hyve::Fast::valueKind::Null */
extern db_constant (*Fast_valueKind_Null_o);

/* ::hyve::Fast::valueKind::Reference */
extern db_constant (*Fast_valueKind_Reference_o);

/* ::hyve::Fast::valueKind::SignedInteger */
extern db_constant (*Fast_valueKind_SignedInteger_o);

/* ::hyve::Fast::valueKind::String */
extern db_constant (*Fast_valueKind_String_o);

/* ::hyve::Fast::valueKindFromType(lang::type type) */
extern db_function Fast_valueKindFromType_o;

/* ::hyve::Fast::Variable */
extern db_class Fast_Variable_o;

/* ::hyve::Fast::Variable::construct(Variable object) */
extern db_callback Fast_Variable_construct_o;

/* ::hyve::Fast::Variable::kind */
extern db_member Fast_Variable_kind_o;

/* ::hyve::Fast::variableKind */
extern db_enum Fast_variableKind_o;

/* ::hyve::Fast::variableKind::Local */
extern db_constant (*Fast_variableKind_Local_o);

/* ::hyve::Fast::variableKind::Object */
extern db_constant (*Fast_variableKind_Object_o);

/* ::hyve::Fast::variableKind::Template */
extern db_constant (*Fast_variableKind_Template_o);

/* ::hyve::Fast::Wait */
extern db_class Fast_Wait_o;

/* ::hyve::Fast::Wait::construct(Wait object) */
extern db_callback Fast_Wait_construct_o;

/* ::hyve::Fast::Wait::exprList */
extern db_member Fast_Wait_exprList_o;

/* ::hyve::Fast::Wait::timeout */
extern db_member Fast_Wait_timeout_o;

/* ::hyve::Fast::Wait::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
extern db_virtual Fast_Wait_toIc_o;

/* ::hyve::Fast::While */
extern db_class Fast_While_o;

/* ::hyve::Fast::While::condition */
extern db_member Fast_While_condition_o;

/* ::hyve::Fast::While::construct(While object) */
extern db_callback Fast_While_construct_o;

/* ::hyve::Fast::While::isUntil */
extern db_member Fast_While_isUntil_o;

/* ::hyve::Fast::While::toIc(lang::alias{"db_icProgram"} program,lang::alias{"db_icStorage"} storage,lang::bool stored) */
extern db_virtual Fast_While_toIc_o;

/* ::hyve::Fast::While::trueBranch */
extern db_member Fast_While_trueBranch_o;

int Fast_load(void);
#ifdef __cplusplus
}
#endif
#endif

