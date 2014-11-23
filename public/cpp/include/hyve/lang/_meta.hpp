/* include/hyve/lang/_meta.hpp
 *
 *  Generated on Oct 28 2014
 *    Loads objects in database.
 *    This file contains generated code. Do not modify!
 */

#ifndef lang_META_H
#define lang_META_H

#include "hyve.hpp"

#include "hyve/lang/_type.hpp"

namespace hyve {
    
    /* ::hyve::lang */
    extern ::hyve::lang::object lang_h;
    namespace lang {
        
        /* ::hyve::lang::alias */
        extern ::hyve::lang::_class alias_h;
        extern ::hyve::lang::Class (*alias_o);
        
        /* ::hyve::lang::alias::init(lang::alias object) */
        extern ::hyve::lang::callback alias_init_h;
        
        /* ::hyve::lang::alias::typeName */
        extern ::hyve::lang::member alias_typeName_h;
        
        /* ::hyve::lang::any */
        extern ::hyve::lang::type any_h;
        
        /* ::hyve::lang::array */
        extern ::hyve::lang::_class array_h;
        extern ::hyve::lang::Class (*array_o);
        
        /* ::hyve::lang::array::construct(lang::array object) */
        extern ::hyve::lang::callback array_construct_h;
        
        /* ::hyve::lang::array::destruct(lang::array object) */
        extern ::hyve::lang::callback array_destruct_h;
        
        /* ::hyve::lang::array::elementType */
        extern ::hyve::lang::member array_elementType_h;
        
        /* ::hyve::lang::array::init(lang::array object) */
        extern ::hyve::lang::callback array_init_h;
        
        /* ::hyve::lang::attr */
        extern ::hyve::lang::bitmask attr_h;
        
        /* ::hyve::lang::attr::ATTR_OBSERVABLE */
        extern ::hyve::lang::constant *attr_ATTR_OBSERVABLE_h;
        
        /* ::hyve::lang::attr::ATTR_SCOPED */
        extern ::hyve::lang::constant *attr_ATTR_SCOPED_h;
        
        /* ::hyve::lang::attr::ATTR_WRITABLE */
        extern ::hyve::lang::constant *attr_ATTR_WRITABLE_h;
        
        /* ::hyve::lang::binary */
        extern ::hyve::lang::_class binary_h;
        extern ::hyve::lang::Class (*binary_o);
        
        /* ::hyve::lang::binary::init(lang::binary object) */
        extern ::hyve::lang::callback binary_init_h;
        
        /* ::hyve::lang::bitmask */
        extern ::hyve::lang::_class bitmask_h;
        extern ::hyve::lang::Class (*bitmask_o);
        
        /* ::hyve::lang::bitmask::init(lang::bitmask object) */
        extern ::hyve::lang::callback bitmask_init_h;
        
        /* ::hyve::lang::bool */
        extern ::hyve::lang::boolean _bool_h;
        
        /* ::hyve::lang::boolean */
        extern ::hyve::lang::_class boolean_h;
        extern ::hyve::lang::Class (*boolean_o);
        
        /* ::hyve::lang::boolean::init(lang::boolean object) */
        extern ::hyve::lang::callback boolean_init_h;
        
        /* ::hyve::lang::callback */
        extern ::hyve::lang::procedure callback_h;
        extern ::hyve::lang::Procedure (*callback_o);
        
        /* ::hyve::lang::callback::bind(lang::callback object) */
        extern ::hyve::lang::callback callback_bind_h;
        
        /* ::hyve::lang::callback::delegate */
        extern ::hyve::lang::member callback_delegate_h;
        
        /* ::hyve::lang::callback::init(lang::callback object) */
        extern ::hyve::lang::callback callback_init_h;
        
        /* ::hyve::lang::char */
        extern ::hyve::lang::character _char_h;
        
        /* ::hyve::lang::character */
        extern ::hyve::lang::_class character_h;
        extern ::hyve::lang::Class (*character_o);
        
        /* ::hyve::lang::character::init(lang::character object) */
        extern ::hyve::lang::callback character_init_h;
        
        /* ::hyve::lang::class */
        extern ::hyve::lang::_class _class_h;
        extern ::hyve::lang::Class (*_class_o);
        
        /* ::hyve::lang::class::_construct(lang::class object) */
        extern ::hyve::lang::callback _class__construct_h;
        
        /* ::hyve::lang::class::_destruct(lang::class object) */
        extern ::hyve::lang::callback _class__destruct_h;
        
        /* ::hyve::lang::class::allocSize() */
        extern ::hyve::lang::method _class_allocSize_h;
        
        /* ::hyve::lang::class::bindMethod(lang::method method) */
        extern ::hyve::lang::method _class_bindMethod_h;
        
        /* ::hyve::lang::class::construct(lang::object object) */
        extern ::hyve::lang::delegate _class_construct_h;
        
        /* ::hyve::lang::class::destruct(lang::object object) */
        extern ::hyve::lang::delegate _class_destruct_h;
        
        /* ::hyve::lang::class::implements */
        extern ::hyve::lang::member _class_implements_h;
        
        /* ::hyve::lang::class::init(lang::class object) */
        extern ::hyve::lang::callback _class_init_h;
        
        /* ::hyve::lang::class::instanceof(lang::object object) */
        extern ::hyve::lang::method _class_instanceof_h;
        
        /* ::hyve::lang::class::interfaceVector */
        extern ::hyve::lang::member _class_interfaceVector_h;
        
        /* ::hyve::lang::class::observers */
        extern ::hyve::lang::member _class_observers_h;
        
        /* ::hyve::lang::class::privateObserver(lang::object object,lang::observer observer) */
        extern ::hyve::lang::method _class_privateObserver_h;
        
        /* ::hyve::lang::collection */
        extern ::hyve::lang::_class collection_h;
        extern ::hyve::lang::Class (*collection_o);
        
        /* ::hyve::lang::collection::castable(lang::type type) */
        extern ::hyve::lang::method collection_castable_h;
        
        /* ::hyve::lang::collection::elementType */
        extern ::hyve::lang::member collection_elementType_h;
        
        /* ::hyve::lang::collection::init(lang::collection object) */
        extern ::hyve::lang::callback collection_init_h;
        
        /* ::hyve::lang::collection::kind */
        extern ::hyve::lang::member collection_kind_h;
        
        /* ::hyve::lang::collection::max */
        extern ::hyve::lang::member collection_max_h;
        
        /* ::hyve::lang::collection::size() */
        extern ::hyve::lang::metaprocedure collection_size_h;
        
        /* ::hyve::lang::collectionKind */
        extern ::hyve::lang::_enum collectionKind_h;
        
        /* ::hyve::lang::collectionKind::ARRAY */
        extern ::hyve::lang::constant *collectionKind_ARRAY_h;
        
        /* ::hyve::lang::collectionKind::LIST */
        extern ::hyve::lang::constant *collectionKind_LIST_h;
        
        /* ::hyve::lang::collectionKind::MAP */
        extern ::hyve::lang::constant *collectionKind_MAP_h;
        
        /* ::hyve::lang::collectionKind::SEQUENCE */
        extern ::hyve::lang::constant *collectionKind_SEQUENCE_h;
        
        /* ::hyve::lang::compositeKind */
        extern ::hyve::lang::_enum compositeKind_h;
        
        /* ::hyve::lang::compositeKind::CLASS */
        extern ::hyve::lang::constant *compositeKind_CLASS_h;
        
        /* ::hyve::lang::compositeKind::INTERFACE */
        extern ::hyve::lang::constant *compositeKind_INTERFACE_h;
        
        /* ::hyve::lang::compositeKind::PROCEDURE */
        extern ::hyve::lang::constant *compositeKind_PROCEDURE_h;
        
        /* ::hyve::lang::compositeKind::STRUCT */
        extern ::hyve::lang::constant *compositeKind_STRUCT_h;
        
        /* ::hyve::lang::constant */
        extern ::hyve::lang::_int constant_h;
        
        /* ::hyve::lang::constant::init(constant object) */
        extern ::hyve::lang::callback constant_init_h;
        
        /* ::hyve::lang::delegate */
        extern ::hyve::lang::procedure delegate_h;
        extern ::hyve::lang::Procedure (*delegate_o);
        
        /* ::hyve::lang::delegate::id */
        extern ::hyve::lang::member delegate_id_h;
        
        /* ::hyve::lang::delegate::init(lang::delegate object) */
        extern ::hyve::lang::callback delegate_init_h;
        
        /* ::hyve::lang::dispatcher */
        extern ::hyve::lang::interface dispatcher_h;
        extern ::hyve::lang::Interface (*dispatcher_o);
        
        /* ::hyve::lang::dispatcher::getEvent(lang::observer observer,lang::object me,lang::object observable,lang::object src) */
        extern ::hyve::lang::method dispatcher_getEvent_h;
        
        /* ::hyve::lang::dispatcher::post(lang::event event) */
        extern ::hyve::lang::method dispatcher_post_h;
        
        /* ::hyve::lang::enum */
        extern ::hyve::lang::_class _enum_h;
        extern ::hyve::lang::Class (*_enum_o);
        
        /* ::hyve::lang::enum::constant(lang::int32 value) */
        extern ::hyve::lang::method _enum_constant_h;
        
        /* ::hyve::lang::enum::constants */
        extern ::hyve::lang::member _enum_constants_h;
        
        /* ::hyve::lang::enum::construct(lang::enum object) */
        extern ::hyve::lang::callback _enum_construct_h;
        
        /* ::hyve::lang::enum::destruct(lang::enum object) */
        extern ::hyve::lang::callback _enum_destruct_h;
        
        /* ::hyve::lang::enum::init(lang::enum object) */
        extern ::hyve::lang::callback _enum_init_h;
        
        /* ::hyve::lang::equalityKind */
        extern ::hyve::lang::_enum equalityKind_h;
        
        /* ::hyve::lang::equalityKind::EQ */
        extern ::hyve::lang::constant *equalityKind_EQ_h;
        
        /* ::hyve::lang::equalityKind::GT */
        extern ::hyve::lang::constant *equalityKind_GT_h;
        
        /* ::hyve::lang::equalityKind::LT */
        extern ::hyve::lang::constant *equalityKind_LT_h;
        
        /* ::hyve::lang::equalityKind::NEQ */
        extern ::hyve::lang::constant *equalityKind_NEQ_h;
        
        /* ::hyve::lang::event */
        extern ::hyve::lang::_class event_h;
        extern ::hyve::lang::Class (*event_o);
        
        /* ::hyve::lang::event::handled */
        extern ::hyve::lang::member event_handled_h;
        
        /* ::hyve::lang::event::kind */
        extern ::hyve::lang::member event_kind_h;
        
        /* ::hyve::lang::event::processed() */
        extern ::hyve::lang::method event_processed_h;
        
        /* ::hyve::lang::event::uniqueKind() */
        extern ::hyve::lang::function event_uniqueKind_h;
        
        /* ::hyve::lang::eventMask */
        extern ::hyve::lang::bitmask eventMask_h;
        
        /* ::hyve::lang::eventMask::ON_DECLARE */
        extern ::hyve::lang::constant *eventMask_ON_DECLARE_h;
        
        /* ::hyve::lang::eventMask::ON_DEFINE */
        extern ::hyve::lang::constant *eventMask_ON_DEFINE_h;
        
        /* ::hyve::lang::eventMask::ON_DESTRUCT */
        extern ::hyve::lang::constant *eventMask_ON_DESTRUCT_h;
        
        /* ::hyve::lang::eventMask::ON_INVALIDATE */
        extern ::hyve::lang::constant *eventMask_ON_INVALIDATE_h;
        
        /* ::hyve::lang::eventMask::ON_METAVALUE */
        extern ::hyve::lang::constant *eventMask_ON_METAVALUE_h;
        
        /* ::hyve::lang::eventMask::ON_SCOPE */
        extern ::hyve::lang::constant *eventMask_ON_SCOPE_h;
        
        /* ::hyve::lang::eventMask::ON_SELF */
        extern ::hyve::lang::constant *eventMask_ON_SELF_h;
        
        /* ::hyve::lang::eventMask::ON_UPDATE */
        extern ::hyve::lang::constant *eventMask_ON_UPDATE_h;
        
        /* ::hyve::lang::eventMask::ON_VALUE */
        extern ::hyve::lang::constant *eventMask_ON_VALUE_h;
        
        /* ::hyve::lang::float */
        extern ::hyve::lang::_class _float_h;
        extern ::hyve::lang::Class (*_float_o);
        
        /* ::hyve::lang::float::init(lang::float object) */
        extern ::hyve::lang::callback _float_init_h;
        
        /* ::hyve::lang::float::max */
        extern ::hyve::lang::member _float_max_h;
        
        /* ::hyve::lang::float::min */
        extern ::hyve::lang::member _float_min_h;
        
        /* ::hyve::lang::float32 */
        extern ::hyve::lang::_float float32_h;
        
        /* ::hyve::lang::float64 */
        extern ::hyve::lang::_float float64_h;
        
        /* ::hyve::lang::function */
        extern ::hyve::lang::procedure function_h;
        extern ::hyve::lang::Procedure (*function_o);
        
        /* ::hyve::lang::function::bind(lang::function object) */
        extern ::hyve::lang::callback function_bind_h;
        
        /* ::hyve::lang::function::impl */
        extern ::hyve::lang::member function_impl_h;
        
        /* ::hyve::lang::function::impludata */
        extern ::hyve::lang::member function_impludata_h;
        
        /* ::hyve::lang::function::init(lang::function object) */
        extern ::hyve::lang::callback function_init_h;
        
        /* ::hyve::lang::function::kind */
        extern ::hyve::lang::member function_kind_h;
        
        /* ::hyve::lang::function::nextParameterId */
        extern ::hyve::lang::member function_nextParameterId_h;
        
        /* ::hyve::lang::function::overloaded */
        extern ::hyve::lang::member function_overloaded_h;
        
        /* ::hyve::lang::function::parameters */
        extern ::hyve::lang::member function_parameters_h;
        
        /* ::hyve::lang::function::resource */
        extern ::hyve::lang::member function_resource_h;
        
        /* ::hyve::lang::function::returnType */
        extern ::hyve::lang::member function_returnType_h;
        
        /* ::hyve::lang::function::size */
        extern ::hyve::lang::member function_size_h;
        
        /* ::hyve::lang::function::unbind(lang::function object) */
        extern ::hyve::lang::callback function_unbind_h;
        
        /* ::hyve::lang::int */
        extern ::hyve::lang::_class _int_h;
        extern ::hyve::lang::Class (*_int_o);
        
        /* ::hyve::lang::int::init(lang::int object) */
        extern ::hyve::lang::callback _int_init_h;
        
        /* ::hyve::lang::int::max */
        extern ::hyve::lang::member _int_max_h;
        
        /* ::hyve::lang::int::min */
        extern ::hyve::lang::member _int_min_h;
        
        /* ::hyve::lang::int16 */
        extern ::hyve::lang::_int int16_h;
        
        /* ::hyve::lang::int32 */
        extern ::hyve::lang::_int int32_h;
        
        /* ::hyve::lang::int64 */
        extern ::hyve::lang::_int int64_h;
        
        /* ::hyve::lang::int8 */
        extern ::hyve::lang::_int int8_h;
        
        /* ::hyve::lang::interface */
        extern ::hyve::lang::_class interface_h;
        extern ::hyve::lang::Class (*interface_o);
        
        /* ::hyve::lang::interface::base */
        extern ::hyve::lang::member interface_base_h;
        
        /* ::hyve::lang::interface::bindMethod(lang::method method) */
        extern ::hyve::lang::method interface_bindMethod_h;
        
        /* ::hyve::lang::interface::compatible(lang::type type) */
        extern ::hyve::lang::method interface_compatible_h;
        
        /* ::hyve::lang::interface::construct(lang::interface object) */
        extern ::hyve::lang::callback interface_construct_h;
        
        /* ::hyve::lang::interface::destruct(lang::interface object) */
        extern ::hyve::lang::callback interface_destruct_h;
        
        /* ::hyve::lang::interface::init(lang::interface object) */
        extern ::hyve::lang::callback interface_init_h;
        
        /* ::hyve::lang::interface::kind */
        extern ::hyve::lang::member interface_kind_h;
        
        /* ::hyve::lang::interface::members */
        extern ::hyve::lang::member interface_members_h;
        
        /* ::hyve::lang::interface::methods */
        extern ::hyve::lang::member interface_methods_h;
        
        /* ::hyve::lang::interface::nextMemberId */
        extern ::hyve::lang::member interface_nextMemberId_h;
        
        /* ::hyve::lang::interface::resolveMember(lang::string name) */
        extern ::hyve::lang::method interface_resolveMember_h;
        
        /* ::hyve::lang::interface::resolveMethod(lang::string name) */
        extern ::hyve::lang::method interface_resolveMethod_h;
        
        /* ::hyve::lang::interface::resolveMethodById(lang::uint32 id) */
        extern ::hyve::lang::method interface_resolveMethodById_h;
        
        /* ::hyve::lang::interface::resolveMethodId(lang::string name) */
        extern ::hyve::lang::method interface_resolveMethodId_h;
        
        /* ::hyve::lang::interfaceSeq */
        extern ::hyve::lang::sequence interfaceSeq_h;
        
        /* ::hyve::lang::interfaceVector */
        extern ::hyve::lang::_struct interfaceVector_h;
        
        /* ::hyve::lang::interfaceVector::interface */
        extern ::hyve::lang::member interfaceVector_interface_h;
        
        /* ::hyve::lang::interfaceVector::vector */
        extern ::hyve::lang::member interfaceVector_vector_h;
        
        /* ::hyve::lang::interfaceVectorSeq */
        extern ::hyve::lang::sequence interfaceVectorSeq_h;
        
        /* ::hyve::lang::list */
        extern ::hyve::lang::_class list_h;
        extern ::hyve::lang::Class (*list_o);
        
        /* ::hyve::lang::list::append() */
        extern ::hyve::lang::metaprocedure list_append__h;
        
        /* ::hyve::lang::list::append(lang::any element) */
        extern ::hyve::lang::metaprocedure list_append_langany_h;
        
        /* ::hyve::lang::list::clear() */
        extern ::hyve::lang::metaprocedure list_clear_h;
        
        /* ::hyve::lang::list::construct(lang::list object) */
        extern ::hyve::lang::callback list_construct_h;
        
        /* ::hyve::lang::list::init(lang::list object) */
        extern ::hyve::lang::callback list_init_h;
        
        /* ::hyve::lang::list::insert() */
        extern ::hyve::lang::metaprocedure list_insert__h;
        
        /* ::hyve::lang::list::insert(lang::any element) */
        extern ::hyve::lang::metaprocedure list_insert_langany_h;
        
        /* ::hyve::lang::list::reverse() */
        extern ::hyve::lang::metaprocedure list_reverse_h;
        
        /* ::hyve::lang::map */
        extern ::hyve::lang::_class map_h;
        extern ::hyve::lang::Class (*map_o);
        
        /* ::hyve::lang::map::construct(lang::map object) */
        extern ::hyve::lang::callback map_construct_h;
        
        /* ::hyve::lang::map::elementType */
        extern ::hyve::lang::member map_elementType_h;
        
        /* ::hyve::lang::map::init(lang::map object) */
        extern ::hyve::lang::callback map_init_h;
        
        /* ::hyve::lang::map::keyType */
        extern ::hyve::lang::member map_keyType_h;
        
        /* ::hyve::lang::map::max */
        extern ::hyve::lang::member map_max_h;
        
        /* ::hyve::lang::member */
        extern ::hyve::lang::_class member_h;
        extern ::hyve::lang::Class (*member_o);
        
        /* ::hyve::lang::member::construct(lang::member object) */
        extern ::hyve::lang::callback member_construct_h;
        
        /* ::hyve::lang::member::id */
        extern ::hyve::lang::member member_id_h;
        
        /* ::hyve::lang::member::init(lang::member object) */
        extern ::hyve::lang::callback member_init_h;
        
        /* ::hyve::lang::member::modifiers */
        extern ::hyve::lang::member member_modifiers_h;
        
        /* ::hyve::lang::member::offset */
        extern ::hyve::lang::member member_offset_h;
        
        /* ::hyve::lang::member::state */
        extern ::hyve::lang::member member_state_h;
        
        /* ::hyve::lang::member::type */
        extern ::hyve::lang::member member_type_h;
        
        /* ::hyve::lang::member::weak */
        extern ::hyve::lang::member member_weak_h;
        
        /* ::hyve::lang::memberSeq */
        extern ::hyve::lang::sequence memberSeq_h;
        
        /* ::hyve::lang::metaprocedure */
        extern ::hyve::lang::procedure metaprocedure_h;
        extern ::hyve::lang::Procedure (*metaprocedure_o);
        
        /* ::hyve::lang::metaprocedure::bind(lang::metaprocedure object) */
        extern ::hyve::lang::callback metaprocedure_bind_h;
        
        /* ::hyve::lang::method */
        extern ::hyve::lang::procedure method_h;
        extern ::hyve::lang::Procedure (*method_o);
        
        /* ::hyve::lang::method::bind(lang::method object) */
        extern ::hyve::lang::callback method_bind_h;
        
        /* ::hyve::lang::method::init(lang::method object) */
        extern ::hyve::lang::callback method_init_h;
        
        /* ::hyve::lang::method::virtual */
        extern ::hyve::lang::member method__virtual_h;
        
        /* ::hyve::lang::modifier */
        extern ::hyve::lang::bitmask modifier_h;
        
        /* ::hyve::lang::modifier::CONST */
        extern ::hyve::lang::constant *modifier_CONST_h;
        
        /* ::hyve::lang::modifier::GLOBAL */
        extern ::hyve::lang::constant *modifier_GLOBAL_h;
        
        /* ::hyve::lang::modifier::LOCAL */
        extern ::hyve::lang::constant *modifier_LOCAL_h;
        
        /* ::hyve::lang::modifier::PRIVATE */
        extern ::hyve::lang::constant *modifier_PRIVATE_h;
        
        /* ::hyve::lang::modifier::READONLY */
        extern ::hyve::lang::constant *modifier_READONLY_h;
        
        /* ::hyve::lang::object */
        extern ::hyve::lang::type object_h;
        
        /* ::hyve::lang::objectSeq */
        extern ::hyve::lang::sequence objectSeq_h;
        
        /* ::hyve::lang::observableEvent */
        extern ::hyve::lang::_class observableEvent_h;
        extern ::hyve::lang::Class (*observableEvent_o);
        
        /* ::hyve::lang::observableEvent::me */
        extern ::hyve::lang::member observableEvent_me_h;
        
        /* ::hyve::lang::observableEvent::observable */
        extern ::hyve::lang::member observableEvent_observable_h;
        
        /* ::hyve::lang::observableEvent::observer */
        extern ::hyve::lang::member observableEvent_observer_h;
        
        /* ::hyve::lang::observableEvent::source */
        extern ::hyve::lang::member observableEvent_source_h;
        
        /* ::hyve::lang::observer */
        extern ::hyve::lang::procedure observer_h;
        extern ::hyve::lang::Procedure (*observer_o);
        
        /* ::hyve::lang::observer::bind(lang::observer object) */
        extern ::hyve::lang::callback observer_bind_h;
        
        /* ::hyve::lang::observer::delayedBinder */
        extern ::hyve::lang::member observer_delayedBinder_h;
        
        /* ::hyve::lang::observer::dispatcher */
        extern ::hyve::lang::member observer_dispatcher_h;
        
        /* ::hyve::lang::observer::expression */
        extern ::hyve::lang::member observer_expression_h;
        
        /* ::hyve::lang::observer::init(lang::observer object) */
        extern ::hyve::lang::callback observer_init_h;
        
        /* ::hyve::lang::observer::listen(lang::object observable,lang::object me) */
        extern ::hyve::lang::method observer_listen_h;
        
        /* ::hyve::lang::observer::mask */
        extern ::hyve::lang::member observer_mask_h;
        
        /* ::hyve::lang::observer::me */
        extern ::hyve::lang::member observer_me_h;
        
        /* ::hyve::lang::observer::observable */
        extern ::hyve::lang::member observer_observable_h;
        
        /* ::hyve::lang::observer::observing */
        extern ::hyve::lang::member observer_observing_h;
        
        /* ::hyve::lang::observer::setDispatcher(lang::dispatcher dispatcher) */
        extern ::hyve::lang::method observer_setDispatcher_h;
        
        /* ::hyve::lang::observer::silence(lang::object me) */
        extern ::hyve::lang::method observer_silence_h;
        
        /* ::hyve::lang::observer::template */
        extern ::hyve::lang::member observer__template_h;
        
        /* ::hyve::lang::observerSeq */
        extern ::hyve::lang::sequence observerSeq_h;
        
        /* ::hyve::lang::octet */
        extern ::hyve::lang::binary octet_h;
        
        /* ::hyve::lang::operatorKind */
        extern ::hyve::lang::_enum operatorKind_h;
        
        /* ::hyve::lang::operatorKind::ADD */
        extern ::hyve::lang::constant *operatorKind_ADD_h;
        
        /* ::hyve::lang::operatorKind::AND */
        extern ::hyve::lang::constant *operatorKind_AND_h;
        
        /* ::hyve::lang::operatorKind::ASSIGN */
        extern ::hyve::lang::constant *operatorKind_ASSIGN_h;
        
        /* ::hyve::lang::operatorKind::ASSIGN_ADD */
        extern ::hyve::lang::constant *operatorKind_ASSIGN_ADD_h;
        
        /* ::hyve::lang::operatorKind::ASSIGN_AND */
        extern ::hyve::lang::constant *operatorKind_ASSIGN_AND_h;
        
        /* ::hyve::lang::operatorKind::ASSIGN_DIV */
        extern ::hyve::lang::constant *operatorKind_ASSIGN_DIV_h;
        
        /* ::hyve::lang::operatorKind::ASSIGN_MOD */
        extern ::hyve::lang::constant *operatorKind_ASSIGN_MOD_h;
        
        /* ::hyve::lang::operatorKind::ASSIGN_MUL */
        extern ::hyve::lang::constant *operatorKind_ASSIGN_MUL_h;
        
        /* ::hyve::lang::operatorKind::ASSIGN_OR */
        extern ::hyve::lang::constant *operatorKind_ASSIGN_OR_h;
        
        /* ::hyve::lang::operatorKind::ASSIGN_SUB */
        extern ::hyve::lang::constant *operatorKind_ASSIGN_SUB_h;
        
        /* ::hyve::lang::operatorKind::ASSIGN_XOR */
        extern ::hyve::lang::constant *operatorKind_ASSIGN_XOR_h;
        
        /* ::hyve::lang::operatorKind::BRACKET_CLOSE */
        extern ::hyve::lang::constant *operatorKind_BRACKET_CLOSE_h;
        
        /* ::hyve::lang::operatorKind::BRACKET_OPEN */
        extern ::hyve::lang::constant *operatorKind_BRACKET_OPEN_h;
        
        /* ::hyve::lang::operatorKind::COMMA */
        extern ::hyve::lang::constant *operatorKind_COMMA_h;
        
        /* ::hyve::lang::operatorKind::COND_AND */
        extern ::hyve::lang::constant *operatorKind_COND_AND_h;
        
        /* ::hyve::lang::operatorKind::COND_EQ */
        extern ::hyve::lang::constant *operatorKind_COND_EQ_h;
        
        /* ::hyve::lang::operatorKind::COND_GT */
        extern ::hyve::lang::constant *operatorKind_COND_GT_h;
        
        /* ::hyve::lang::operatorKind::COND_GTEQ */
        extern ::hyve::lang::constant *operatorKind_COND_GTEQ_h;
        
        /* ::hyve::lang::operatorKind::COND_LT */
        extern ::hyve::lang::constant *operatorKind_COND_LT_h;
        
        /* ::hyve::lang::operatorKind::COND_LTEQ */
        extern ::hyve::lang::constant *operatorKind_COND_LTEQ_h;
        
        /* ::hyve::lang::operatorKind::COND_NEQ */
        extern ::hyve::lang::constant *operatorKind_COND_NEQ_h;
        
        /* ::hyve::lang::operatorKind::COND_NOT */
        extern ::hyve::lang::constant *operatorKind_COND_NOT_h;
        
        /* ::hyve::lang::operatorKind::COND_OR */
        extern ::hyve::lang::constant *operatorKind_COND_OR_h;
        
        /* ::hyve::lang::operatorKind::DEC */
        extern ::hyve::lang::constant *operatorKind_DEC_h;
        
        /* ::hyve::lang::operatorKind::DIV */
        extern ::hyve::lang::constant *operatorKind_DIV_h;
        
        /* ::hyve::lang::operatorKind::ELEMENT_CLOSE */
        extern ::hyve::lang::constant *operatorKind_ELEMENT_CLOSE_h;
        
        /* ::hyve::lang::operatorKind::ELEMENT_OPEN */
        extern ::hyve::lang::constant *operatorKind_ELEMENT_OPEN_h;
        
        /* ::hyve::lang::operatorKind::INC */
        extern ::hyve::lang::constant *operatorKind_INC_h;
        
        /* ::hyve::lang::operatorKind::MEMBER_RESOLVE */
        extern ::hyve::lang::constant *operatorKind_MEMBER_RESOLVE_h;
        
        /* ::hyve::lang::operatorKind::MOD */
        extern ::hyve::lang::constant *operatorKind_MOD_h;
        
        /* ::hyve::lang::operatorKind::MUL */
        extern ::hyve::lang::constant *operatorKind_MUL_h;
        
        /* ::hyve::lang::operatorKind::NOT */
        extern ::hyve::lang::constant *operatorKind_NOT_h;
        
        /* ::hyve::lang::operatorKind::OR */
        extern ::hyve::lang::constant *operatorKind_OR_h;
        
        /* ::hyve::lang::operatorKind::REF */
        extern ::hyve::lang::constant *operatorKind_REF_h;
        
        /* ::hyve::lang::operatorKind::SHIFT_LEFT */
        extern ::hyve::lang::constant *operatorKind_SHIFT_LEFT_h;
        
        /* ::hyve::lang::operatorKind::SHIFT_RIGHT */
        extern ::hyve::lang::constant *operatorKind_SHIFT_RIGHT_h;
        
        /* ::hyve::lang::operatorKind::SUB */
        extern ::hyve::lang::constant *operatorKind_SUB_h;
        
        /* ::hyve::lang::operatorKind::XOR */
        extern ::hyve::lang::constant *operatorKind_XOR_h;
        
        /* ::hyve::lang::parameter */
        extern ::hyve::lang::_struct parameter_h;
        
        /* ::hyve::lang::parameter::name */
        extern ::hyve::lang::member parameter_name_h;
        
        /* ::hyve::lang::parameter::passByReference */
        extern ::hyve::lang::member parameter_passByReference_h;
        
        /* ::hyve::lang::parameter::type */
        extern ::hyve::lang::member parameter_type_h;
        
        /* ::hyve::lang::parameterSeq */
        extern ::hyve::lang::sequence parameterSeq_h;
        
        /* ::hyve::lang::primitive */
        extern ::hyve::lang::_class primitive_h;
        extern ::hyve::lang::Class (*primitive_o);
        
        /* ::hyve::lang::primitive::castable(lang::type type) */
        extern ::hyve::lang::method primitive_castable_h;
        
        /* ::hyve::lang::primitive::compatible(lang::type type) */
        extern ::hyve::lang::method primitive_compatible_h;
        
        /* ::hyve::lang::primitive::construct(lang::primitive object) */
        extern ::hyve::lang::callback primitive_construct_h;
        
        /* ::hyve::lang::primitive::convertId */
        extern ::hyve::lang::member primitive_convertId_h;
        
        /* ::hyve::lang::primitive::init(lang::primitive object) */
        extern ::hyve::lang::callback primitive_init_h;
        
        /* ::hyve::lang::primitive::kind */
        extern ::hyve::lang::member primitive_kind_h;
        
        /* ::hyve::lang::primitive::width */
        extern ::hyve::lang::member primitive_width_h;
        
        /* ::hyve::lang::primitiveKind */
        extern ::hyve::lang::_enum primitiveKind_h;
        
        /* ::hyve::lang::primitiveKind::ALIAS */
        extern ::hyve::lang::constant *primitiveKind_ALIAS_h;
        
        /* ::hyve::lang::primitiveKind::BINARY */
        extern ::hyve::lang::constant *primitiveKind_BINARY_h;
        
        /* ::hyve::lang::primitiveKind::BITMASK */
        extern ::hyve::lang::constant *primitiveKind_BITMASK_h;
        
        /* ::hyve::lang::primitiveKind::BOOLEAN */
        extern ::hyve::lang::constant *primitiveKind_BOOLEAN_h;
        
        /* ::hyve::lang::primitiveKind::CHARACTER */
        extern ::hyve::lang::constant *primitiveKind_CHARACTER_h;
        
        /* ::hyve::lang::primitiveKind::ENUM */
        extern ::hyve::lang::constant *primitiveKind_ENUM_h;
        
        /* ::hyve::lang::primitiveKind::FLOAT */
        extern ::hyve::lang::constant *primitiveKind_FLOAT_h;
        
        /* ::hyve::lang::primitiveKind::INTEGER */
        extern ::hyve::lang::constant *primitiveKind_INTEGER_h;
        
        /* ::hyve::lang::primitiveKind::TEXT */
        extern ::hyve::lang::constant *primitiveKind_TEXT_h;
        
        /* ::hyve::lang::primitiveKind::UINTEGER */
        extern ::hyve::lang::constant *primitiveKind_UINTEGER_h;
        
        /* ::hyve::lang::procedure */
        extern ::hyve::lang::_class procedure_h;
        extern ::hyve::lang::Class (*procedure_o);
        
        /* ::hyve::lang::procedure::bind(lang::object object) */
        extern ::hyve::lang::delegate procedure_bind_h;
        
        /* ::hyve::lang::procedure::init(lang::procedure object) */
        extern ::hyve::lang::callback procedure_init_h;
        
        /* ::hyve::lang::procedure::kind */
        extern ::hyve::lang::member procedure_kind_h;
        
        /* ::hyve::lang::procedure::unbind(lang::object object) */
        extern ::hyve::lang::delegate procedure_unbind_h;
        
        /* ::hyve::lang::procedureKind */
        extern ::hyve::lang::_enum procedureKind_h;
        
        /* ::hyve::lang::procedureKind::CALLBACK */
        extern ::hyve::lang::constant *procedureKind_CALLBACK_h;
        
        /* ::hyve::lang::procedureKind::DELEGATE */
        extern ::hyve::lang::constant *procedureKind_DELEGATE_h;
        
        /* ::hyve::lang::procedureKind::FUNCTION */
        extern ::hyve::lang::constant *procedureKind_FUNCTION_h;
        
        /* ::hyve::lang::procedureKind::METAPROCEDURE */
        extern ::hyve::lang::constant *procedureKind_METAPROCEDURE_h;
        
        /* ::hyve::lang::procedureKind::METHOD */
        extern ::hyve::lang::constant *procedureKind_METHOD_h;
        
        /* ::hyve::lang::procedureKind::OBSERVER */
        extern ::hyve::lang::constant *procedureKind_OBSERVER_h;
        
        /* ::hyve::lang::sequence */
        extern ::hyve::lang::_class sequence_h;
        extern ::hyve::lang::Class (*sequence_o);
        
        /* ::hyve::lang::sequence::construct(lang::sequence object) */
        extern ::hyve::lang::callback sequence_construct_h;
        
        /* ::hyve::lang::sequence::init(lang::sequence object) */
        extern ::hyve::lang::callback sequence_init_h;
        
        /* ::hyve::lang::sequence::size(lang::uint32 size) */
        extern ::hyve::lang::metaprocedure sequence_size_h;
        
        /* ::hyve::lang::state */
        extern ::hyve::lang::bitmask state_h;
        
        /* ::hyve::lang::state::DECLARED */
        extern ::hyve::lang::constant *state_DECLARED_h;
        
        /* ::hyve::lang::state::DEFINED */
        extern ::hyve::lang::constant *state_DEFINED_h;
        
        /* ::hyve::lang::state::VALID */
        extern ::hyve::lang::constant *state_VALID_h;
        
        /* ::hyve::lang::string */
        extern ::hyve::lang::text string_h;
        
        /* ::hyve::lang::struct */
        extern ::hyve::lang::_class _struct_h;
        extern ::hyve::lang::Class (*_struct_o);
        
        /* ::hyve::lang::struct::baseAccess */
        extern ::hyve::lang::member _struct_baseAccess_h;
        
        /* ::hyve::lang::struct::castable(lang::type type) */
        extern ::hyve::lang::method _struct_castable_h;
        
        /* ::hyve::lang::struct::compatible(lang::type type) */
        extern ::hyve::lang::method _struct_compatible_h;
        
        /* ::hyve::lang::struct::construct(lang::struct object) */
        extern ::hyve::lang::callback _struct_construct_h;
        
        /* ::hyve::lang::struct::delegateCount */
        extern ::hyve::lang::member _struct_delegateCount_h;
        
        /* ::hyve::lang::struct::init(lang::struct object) */
        extern ::hyve::lang::callback _struct_init_h;
        
        /* ::hyve::lang::struct::resolveMember(lang::string name) */
        extern ::hyve::lang::method _struct_resolveMember_h;
        
        /* ::hyve::lang::text */
        extern ::hyve::lang::_class text_h;
        extern ::hyve::lang::Class (*text_o);
        
        /* ::hyve::lang::text::charWidth */
        extern ::hyve::lang::member text_charWidth_h;
        
        /* ::hyve::lang::text::init(lang::text object) */
        extern ::hyve::lang::callback text_init_h;
        
        /* ::hyve::lang::text::length */
        extern ::hyve::lang::member text_length_h;
        
        /* ::hyve::lang::type */
        extern ::hyve::lang::_class type_h;
        extern ::hyve::lang::Class (*type_o);
        
        /* ::hyve::lang::type::_init(lang::type object) */
        extern ::hyve::lang::callback type__init_h;
        
        /* ::hyve::lang::type::alignment */
        extern ::hyve::lang::member type_alignment_h;
        
        /* ::hyve::lang::type::alignmentof() */
        extern ::hyve::lang::method type_alignmentof_h;
        
        /* ::hyve::lang::type::allocSize() */
        extern ::hyve::lang::method type_allocSize_h;
        
        /* ::hyve::lang::type::castable(lang::type type) */
        extern ::hyve::lang::method type_castable_h;
        
        /* ::hyve::lang::type::compare(lang::any value) */
        extern ::hyve::lang::metaprocedure type_compare_h;
        
        /* ::hyve::lang::type::compatible(lang::type type) */
        extern ::hyve::lang::method type_compatible_h;
        
        /* ::hyve::lang::type::construct(lang::type object) */
        extern ::hyve::lang::callback type_construct_h;
        
        /* ::hyve::lang::type::copy(lang::any value) */
        extern ::hyve::lang::metaprocedure type_copy_h;
        
        /* ::hyve::lang::type::defaultType */
        extern ::hyve::lang::member type_defaultType_h;
        
        /* ::hyve::lang::type::destruct(lang::type object) */
        extern ::hyve::lang::callback type_destruct_h;
        
        /* ::hyve::lang::type::fullname() */
        extern ::hyve::lang::metaprocedure type_fullname_h;
        
        /* ::hyve::lang::type::hasResources */
        extern ::hyve::lang::member type_hasResources_h;
        
        /* ::hyve::lang::type::init(lang::object object) */
        extern ::hyve::lang::delegate type_init_h;
        
        /* ::hyve::lang::type::kind */
        extern ::hyve::lang::member type_kind_h;
        
        /* ::hyve::lang::type::metaprocedures */
        extern ::hyve::lang::member type_metaprocedures_h;
        
        /* ::hyve::lang::type::nameof() */
        extern ::hyve::lang::metaprocedure type_nameof_h;
        
        /* ::hyve::lang::type::parentof() */
        extern ::hyve::lang::metaprocedure type_parentof_h;
        
        /* ::hyve::lang::type::parentState */
        extern ::hyve::lang::member type_parentState_h;
        
        /* ::hyve::lang::type::parentType */
        extern ::hyve::lang::member type_parentType_h;
        
        /* ::hyve::lang::type::reference */
        extern ::hyve::lang::member type_reference_h;
        
        /* ::hyve::lang::type::relname(lang::object from) */
        extern ::hyve::lang::metaprocedure type_relname_h;
        
        /* ::hyve::lang::type::resolveProcedure(lang::string name) */
        extern ::hyve::lang::method type_resolveProcedure_h;
        
        /* ::hyve::lang::type::size */
        extern ::hyve::lang::member type_size_h;
        
        /* ::hyve::lang::type::sizeof() */
        extern ::hyve::lang::method type__sizeof_h;
        
        /* ::hyve::lang::type::templateId */
        extern ::hyve::lang::member type_templateId_h;
        
        /* ::hyve::lang::type::toString() */
        extern ::hyve::lang::metaprocedure type_toString_h;
        
        /* ::hyve::lang::type::typeof() */
        extern ::hyve::lang::metaprocedure type_typeof_h;
        
        /* ::hyve::lang::typedef */
        extern ::hyve::lang::_class _typedef_h;
        extern ::hyve::lang::Class (*_typedef_o);
        
        /* ::hyve::lang::typedef::construct(lang::typedef object) */
        extern ::hyve::lang::callback _typedef_construct_h;
        
        /* ::hyve::lang::typedef::destruct(lang::typedef object) */
        extern ::hyve::lang::callback _typedef_destruct_h;
        
        /* ::hyve::lang::typedef::init(lang::typedef object) */
        extern ::hyve::lang::callback _typedef_init_h;
        
        /* ::hyve::lang::typedef::real */
        extern ::hyve::lang::member _typedef_real_h;
        
        /* ::hyve::lang::typedef::realType() */
        extern ::hyve::lang::method _typedef_realType_h;
        
        /* ::hyve::lang::typedef::type */
        extern ::hyve::lang::member _typedef_type_h;
        
        /* ::hyve::lang::typeKind */
        extern ::hyve::lang::_enum typeKind_h;
        
        /* ::hyve::lang::typeKind::ANY */
        extern ::hyve::lang::constant *typeKind_ANY_h;
        
        /* ::hyve::lang::typeKind::COLLECTION */
        extern ::hyve::lang::constant *typeKind_COLLECTION_h;
        
        /* ::hyve::lang::typeKind::COMPOSITE */
        extern ::hyve::lang::constant *typeKind_COMPOSITE_h;
        
        /* ::hyve::lang::typeKind::PRIMITIVE */
        extern ::hyve::lang::constant *typeKind_PRIMITIVE_h;
        
        /* ::hyve::lang::typeKind::VOID */
        extern ::hyve::lang::constant *typeKind_VOID_h;
        
        /* ::hyve::lang::uint */
        extern ::hyve::lang::_class uint_h;
        extern ::hyve::lang::Class (*uint_o);
        
        /* ::hyve::lang::uint::init(lang::uint object) */
        extern ::hyve::lang::callback uint_init_h;
        
        /* ::hyve::lang::uint::max */
        extern ::hyve::lang::member uint_max_h;
        
        /* ::hyve::lang::uint::min */
        extern ::hyve::lang::member uint_min_h;
        
        /* ::hyve::lang::uint16 */
        extern ::hyve::lang::uint uint16_h;
        
        /* ::hyve::lang::uint32 */
        extern ::hyve::lang::uint uint32_h;
        
        /* ::hyve::lang::uint64 */
        extern ::hyve::lang::uint uint64_h;
        
        /* ::hyve::lang::uint8 */
        extern ::hyve::lang::uint uint8_h;
        
        /* ::hyve::lang::virtual */
        extern ::hyve::lang::procedure _virtual_h;
        extern ::hyve::lang::Procedure (*_virtual_o);
        
        /* ::hyve::lang::virtual::init(lang::virtual object) */
        extern ::hyve::lang::callback _virtual_init_h;
        
        /* ::hyve::lang::void */
        extern ::hyve::lang::type _void_h;
        
        /* ::hyve::lang::vtable */
        extern ::hyve::lang::sequence vtable_h;
        
        /* ::hyve::lang::width */
        extern ::hyve::lang::_enum width_h;
        
        /* ::hyve::lang::width::WIDTH_16 */
        extern ::hyve::lang::constant *width_WIDTH_16_h;
        
        /* ::hyve::lang::width::WIDTH_32 */
        extern ::hyve::lang::constant *width_WIDTH_32_h;
        
        /* ::hyve::lang::width::WIDTH_64 */
        extern ::hyve::lang::constant *width_WIDTH_64_h;
        
        /* ::hyve::lang::width::WIDTH_8 */
        extern ::hyve::lang::constant *width_WIDTH_8_h;
        
        /* ::hyve::lang::width::WIDTH_WORD */
        extern ::hyve::lang::constant *width_WIDTH_WORD_h;
        
        /* ::hyve::lang::word */
        extern ::hyve::lang::binary word_h;
        
        int load(void);
    }
}
#endif

