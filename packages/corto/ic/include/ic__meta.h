/* ic__meta.h
 *
 * Loads objects in object store.
 * This file contains generated code. Do not modify!
 */

#ifndef ic_META_H
#define ic_META_H

#include "corto.h"

#include "ic__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::corto */
extern cx_package _o;

/* ::corto::ic */
extern cx_package ic_o;

/* ::corto::ic::accumulator */
extern cx_class ic_accumulator_o;

/* ::corto::ic::accumulator::construct() */
extern cx_method ic_accumulator_construct_o;

/* ::corto::ic::address */
extern cx_class ic_address_o;

/* ::corto::ic::address::construct() */
extern cx_method ic_address_construct_o;

/* ::corto::ic::address::value */
extern cx_member ic_address_value_o;

/* ::corto::ic::derefKind */
extern cx_enum ic_derefKind_o;

/* ::corto::ic::derefKind::DEREF_ADDRESS */
extern cx_constant (*ic_derefKind_DEREF_ADDRESS_o);

/* ::corto::ic::derefKind::DEREF_VALUE */
extern cx_constant (*ic_derefKind_DEREF_VALUE_o);

/* ::corto::ic::element */
extern cx_class ic_element_o;

/* ::corto::ic::element::base */
extern cx_member ic_element_base_o;

/* ::corto::ic::element::construct() */
extern cx_method ic_element_construct_o;

/* ::corto::ic::element::index */
extern cx_member ic_element_index_o;

/* ::corto::ic::element::variableIndex */
extern cx_member ic_element_variableIndex_o;

/* ::corto::ic::function */
extern cx_class ic_function_o;

/* ::corto::ic::function::construct() */
extern cx_method ic_function_construct_o;

/* ::corto::ic::function::function */
extern cx_member ic_function_function_o;

/* ::corto::ic::function::str(string in) */
extern cx_method ic_function_str_o;

/* ::corto::ic::kind */
extern cx_enum ic_kind_o;

/* ::corto::ic::kind::ADDRESS */
extern cx_constant (*ic_kind_ADDRESS_o);

/* ::corto::ic::kind::FUNCTION */
extern cx_constant (*ic_kind_FUNCTION_o);

/* ::corto::ic::kind::LABEL */
extern cx_constant (*ic_kind_LABEL_o);

/* ::corto::ic::kind::LITERAL */
extern cx_constant (*ic_kind_LITERAL_o);

/* ::corto::ic::kind::OP */
extern cx_constant (*ic_kind_OP_o);

/* ::corto::ic::kind::SCOPE */
extern cx_constant (*ic_kind_SCOPE_o);

/* ::corto::ic::kind::STORAGE */
extern cx_constant (*ic_kind_STORAGE_o);

/* ::corto::ic::label */
extern cx_class ic_label_o;

/* ::corto::ic::label::construct() */
extern cx_method ic_label_construct_o;

/* ::corto::ic::label::id */
extern cx_member ic_label_id_o;

/* ::corto::ic::label::str(string in) */
extern cx_method ic_label_str_o;

/* ::corto::ic::literal */
extern cx_class ic_literal_o;

/* ::corto::ic::literal::construct() */
extern cx_method ic_literal_construct_o;

/* ::corto::ic::literal::str(string in) */
extern cx_method ic_literal_str_o;

/* ::corto::ic::literal::value */
extern cx_member ic_literal_value_o;

/* ::corto::ic::member */
extern cx_class ic_member_o;

/* ::corto::ic::member::base */
extern cx_member ic_member_base_o;

/* ::corto::ic::member::construct() */
extern cx_method ic_member_construct_o;

/* ::corto::ic::member::member */
extern cx_member ic_member_member_o;

/* ::corto::ic::node */
extern cx_class ic_node_o;

/* ::corto::ic::node::construct() */
extern cx_method ic_node_construct_o;

/* ::corto::ic::node::kind */
extern cx_member ic_node_kind_o;

/* ::corto::ic::node::str(string in) */
extern cx_virtual ic_node_str_o;

/* ::corto::ic::object */
extern cx_class ic_object_o;

/* ::corto::ic::object::construct() */
extern cx_method ic_object_construct_o;

/* ::corto::ic::object::ptr */
extern cx_member ic_object_ptr_o;

/* ::corto::ic::op */
extern cx_class ic_op_o;

/* ::corto::ic::op::construct() */
extern cx_method ic_op_construct_o;

/* ::corto::ic::op::kind */
extern cx_member ic_op_kind_o;

/* ::corto::ic::op::line */
extern cx_member ic_op_line_o;

/* ::corto::ic::op::s1 */
extern cx_member ic_op_s1_o;

/* ::corto::ic::op::s1Any */
extern cx_member ic_op_s1Any_o;

/* ::corto::ic::op::s1Deref */
extern cx_member ic_op_s1Deref_o;

/* ::corto::ic::op::s2 */
extern cx_member ic_op_s2_o;

/* ::corto::ic::op::s2Deref */
extern cx_member ic_op_s2Deref_o;

/* ::corto::ic::op::s3 */
extern cx_member ic_op_s3_o;

/* ::corto::ic::op::s3Deref */
extern cx_member ic_op_s3Deref_o;

/* ::corto::ic::op::str(string in) */
extern cx_method ic_op_str_o;

/* ::corto::ic::op::validate() */
extern cx_method ic_op_validate_o;

/* ::corto::ic::opKind */
extern cx_enum ic_opKind_o;

/* ::corto::ic::opKind::add */
extern cx_constant (*ic_opKind_add_o);

/* ::corto::ic::opKind::and */
extern cx_constant (*ic_opKind_and_o);

/* ::corto::ic::opKind::call */
extern cx_constant (*ic_opKind_call_o);

/* ::corto::ic::opKind::cast */
extern cx_constant (*ic_opKind_cast_o);

/* ::corto::ic::opKind::cond_and */
extern cx_constant (*ic_opKind_cond_and_o);

/* ::corto::ic::opKind::cond_eq */
extern cx_constant (*ic_opKind_cond_eq_o);

/* ::corto::ic::opKind::cond_gt */
extern cx_constant (*ic_opKind_cond_gt_o);

/* ::corto::ic::opKind::cond_gteq */
extern cx_constant (*ic_opKind_cond_gteq_o);

/* ::corto::ic::opKind::cond_lt */
extern cx_constant (*ic_opKind_cond_lt_o);

/* ::corto::ic::opKind::cond_lteq */
extern cx_constant (*ic_opKind_cond_lteq_o);

/* ::corto::ic::opKind::cond_neq */
extern cx_constant (*ic_opKind_cond_neq_o);

/* ::corto::ic::opKind::cond_not */
extern cx_constant (*ic_opKind_cond_not_o);

/* ::corto::ic::opKind::cond_or */
extern cx_constant (*ic_opKind_cond_or_o);

/* ::corto::ic::opKind::dec */
extern cx_constant (*ic_opKind_dec_o);

/* ::corto::ic::opKind::define */
extern cx_constant (*ic_opKind_define_o);

/* ::corto::ic::opKind::deinit */
extern cx_constant (*ic_opKind_deinit_o);

/* ::corto::ic::opKind::div */
extern cx_constant (*ic_opKind_div_o);

/* ::corto::ic::opKind::free */
extern cx_constant (*ic_opKind_free_o);

/* ::corto::ic::opKind::inc */
extern cx_constant (*ic_opKind_inc_o);

/* ::corto::ic::opKind::init */
extern cx_constant (*ic_opKind_init_o);

/* ::corto::ic::opKind::jeq */
extern cx_constant (*ic_opKind_jeq_o);

/* ::corto::ic::opKind::jneq */
extern cx_constant (*ic_opKind_jneq_o);

/* ::corto::ic::opKind::jump */
extern cx_constant (*ic_opKind_jump_o);

/* ::corto::ic::opKind::keep */
extern cx_constant (*ic_opKind_keep_o);

/* ::corto::ic::opKind::mod */
extern cx_constant (*ic_opKind_mod_o);

/* ::corto::ic::opKind::mul */
extern cx_constant (*ic_opKind_mul_o);

/* ::corto::ic::opKind::new */
extern cx_constant (*ic_opKind_new_o);

/* ::corto::ic::opKind::not */
extern cx_constant (*ic_opKind_not_o);

/* ::corto::ic::opKind::or */
extern cx_constant (*ic_opKind_or_o);

/* ::corto::ic::opKind::push */
extern cx_constant (*ic_opKind_push_o);

/* ::corto::ic::opKind::ret */
extern cx_constant (*ic_opKind_ret_o);

/* ::corto::ic::opKind::set */
extern cx_constant (*ic_opKind_set_o);

/* ::corto::ic::opKind::shift_left */
extern cx_constant (*ic_opKind_shift_left_o);

/* ::corto::ic::opKind::shift_right */
extern cx_constant (*ic_opKind_shift_right_o);

/* ::corto::ic::opKind::stop */
extern cx_constant (*ic_opKind_stop_o);

/* ::corto::ic::opKind::strcat */
extern cx_constant (*ic_opKind_strcat_o);

/* ::corto::ic::opKind::strcpy */
extern cx_constant (*ic_opKind_strcpy_o);

/* ::corto::ic::opKind::sub */
extern cx_constant (*ic_opKind_sub_o);

/* ::corto::ic::opKind::update */
extern cx_constant (*ic_opKind_update_o);

/* ::corto::ic::opKind::updatebegin */
extern cx_constant (*ic_opKind_updatebegin_o);

/* ::corto::ic::opKind::updatecancel */
extern cx_constant (*ic_opKind_updatecancel_o);

/* ::corto::ic::opKind::updateend */
extern cx_constant (*ic_opKind_updateend_o);

/* ::corto::ic::opKind::wait */
extern cx_constant (*ic_opKind_wait_o);

/* ::corto::ic::opKind::waitfor */
extern cx_constant (*ic_opKind_waitfor_o);

/* ::corto::ic::opKind::xor */
extern cx_constant (*ic_opKind_xor_o);

/* ::corto::ic::opKindFromOperator(operatorKind operator) */
extern cx_function ic_opKindFromOperator_o;

/* ::corto::ic::program */
extern cx_class ic_program_o;

/* ::corto::ic::program::accumulatorSp */
extern cx_member ic_program_accumulatorSp_o;

/* ::corto::ic::program::accumulatorStack */
extern cx_member ic_program_accumulatorStack_o;

/* ::corto::ic::program::add(node n) */
extern cx_method ic_program_add_o;

/* ::corto::ic::program::assemble() */
extern cx_method ic_program_assemble_o;

/* ::corto::ic::program::autoAccId */
extern cx_member ic_program_autoAccId_o;

/* ::corto::ic::program::construct() */
extern cx_method ic_program_construct_o;

/* ::corto::ic::program::declareVariable(string name,type type,bool isReference,bool holdsReturn,bool isParameter,bool isReturn) */
extern cx_method ic_program_declareVariable_o;

/* ::corto::ic::program::errors */
extern cx_member ic_program_errors_o;

/* ::corto::ic::program::filename */
extern cx_member ic_program_filename_o;

/* ::corto::ic::program::functions */
extern cx_member ic_program_functions_o;

/* ::corto::ic::program::get() */
extern cx_function ic_program_get_o;

/* ::corto::ic::program::getAccId() */
extern cx_method ic_program_getAccId_o;

/* ::corto::ic::program::getElement(storage base,node index) */
extern cx_method ic_program_getElement_o;

/* ::corto::ic::program::getLabel() */
extern cx_method ic_program_getLabel_o;

/* ::corto::ic::program::getMember(storage base,member m) */
extern cx_method ic_program_getMember_o;

/* ::corto::ic::program::getObject(object o) */
extern cx_method ic_program_getObject_o;

/* ::corto::ic::program::getVariable(string name) */
extern cx_method ic_program_getVariable_o;

/* ::corto::ic::program::labelCount */
extern cx_member ic_program_labelCount_o;

/* ::corto::ic::program::labels */
extern cx_member ic_program_labels_o;

/* ::corto::ic::program::literals */
extern cx_member ic_program_literals_o;

/* ::corto::ic::program::ops */
extern cx_member ic_program_ops_o;

/* ::corto::ic::program::popAccumulator() */
extern cx_method ic_program_popAccumulator_o;

/* ::corto::ic::program::popScope() */
extern cx_method ic_program_popScope_o;

/* ::corto::ic::program::pushAccumulator(type type,bool isReference,bool holdsReturn) */
extern cx_method ic_program_pushAccumulator_o;

/* ::corto::ic::program::pushFunction(function function) */
extern cx_method ic_program_pushFunction_o;

/* ::corto::ic::program::pushScope() */
extern cx_method ic_program_pushScope_o;

/* ::corto::ic::program::run(word result) */
extern cx_method ic_program_run_o;

/* ::corto::ic::program::scope */
extern cx_member ic_program_scope_o;

/* ::corto::ic::program::scopes */
extern cx_member ic_program_scopes_o;

/* ::corto::ic::program::storages */
extern cx_member ic_program_storages_o;

/* ::corto::ic::program::str() */
extern cx_method ic_program_str_o;

/* ::corto::ic::program::vmprogram */
extern cx_member ic_program_vmprogram_o;

/* ::corto::ic::scope */
extern cx_class ic_scope_o;

/* ::corto::ic::scope::add(node n) */
extern cx_method ic_scope_add_o;

/* ::corto::ic::scope::addStorage(storage s) */
extern cx_method ic_scope_addStorage_o;

/* ::corto::ic::scope::construct() */
extern cx_method ic_scope_construct_o;

/* ::corto::ic::scope::isFunction */
extern cx_member ic_scope_isFunction_o;

/* ::corto::ic::scope::lookupStorage(string name,bool recursive) */
extern cx_method ic_scope_lookupStorage_o;

/* ::corto::ic::scope::parent */
extern cx_member ic_scope_parent_o;

/* ::corto::ic::scope::program */
extern cx_member ic_scope_program_o;

/* ::corto::ic::scope::storages */
extern cx_member ic_scope_storages_o;

/* ::corto::ic::scope::str(string in) */
extern cx_method ic_scope_str_o;

/* ::corto::ic::storage */
extern cx_class ic_storage_o;

/* ::corto::ic::storage::base */
extern cx_member ic_storage_base_o;

/* ::corto::ic::storage::construct() */
extern cx_method ic_storage_construct_o;

/* ::corto::ic::storage::free() */
extern cx_method ic_storage_free_o;

/* ::corto::ic::storage::holdsReturn */
extern cx_member ic_storage_holdsReturn_o;

/* ::corto::ic::storage::isReference */
extern cx_member ic_storage_isReference_o;

/* ::corto::ic::storage::kind */
extern cx_member ic_storage_kind_o;

/* ::corto::ic::storage::name */
extern cx_member ic_storage_name_o;

/* ::corto::ic::storage::scope */
extern cx_member ic_storage_scope_o;

/* ::corto::ic::storage::str(string in) */
extern cx_method ic_storage_str_o;

/* ::corto::ic::storage::type */
extern cx_member ic_storage_type_o;

/* ::corto::ic::storage::used */
extern cx_member ic_storage_used_o;

/* ::corto::ic::storageKind */
extern cx_enum ic_storageKind_o;

/* ::corto::ic::storageKind::ACCUMULATOR */
extern cx_constant (*ic_storageKind_ACCUMULATOR_o);

/* ::corto::ic::storageKind::ELEMENT */
extern cx_constant (*ic_storageKind_ELEMENT_o);

/* ::corto::ic::storageKind::MEMBER */
extern cx_constant (*ic_storageKind_MEMBER_o);

/* ::corto::ic::storageKind::OBJECT */
extern cx_constant (*ic_storageKind_OBJECT_o);

/* ::corto::ic::storageKind::VARIABLE */
extern cx_constant (*ic_storageKind_VARIABLE_o);

/* ::corto::ic::variable */
extern cx_class ic_variable_o;

/* ::corto::ic::variable::construct() */
extern cx_method ic_variable_construct_o;

/* ::corto::ic::variable::isParameter */
extern cx_member ic_variable_isParameter_o;

/* ::corto::ic::variable::isReturn */
extern cx_member ic_variable_isReturn_o;

int ic_load(void);
#ifdef __cplusplus
}
#endif
#endif

